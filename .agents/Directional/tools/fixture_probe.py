#!/usr/bin/env python3
"""fixture_probe.py -- static geometry/topology probe for Directional benchmark fixtures.

REVIEW AID ONLY. This script never touches the repository, never runs Directional, and is
not product, test, or selector authority. It exists so that independent REVIEW turns can
locate a failure in a committed fixture without re-deriving the same helpers every time.

Pure standard library on purpose: numpy has been absent on two different review machines.

Usage
-----
    python3 fixture_probe.py <subcommand> [args...] [--fixture STEM]

    --fixture STEM   fixture stem under benchmarks/fixtures/milestone-g/
                     (default: mechanical_feature)

Subcommands
-----------
    topology                       V/E/F, boundary edges, Euler characteristic
    vertex   V [V ...]             coords, degree, angle defect, incident edges + dihedrals
    edge     A B                   incident mesh rows, dihedral, interior/boundary
    face     A B C [A B C ...]     mesh row(s) whose vertex SET matches each triple
    rows     A,B,C [A,B,C ...]     same as `face`, comma form -- for pasting trace histories
    chain    V [V ...]             consecutive-edge dihedrals + collinearity of a vertex walk
    fan      V                     vertex fan in cyclic order with edge/face slot numbers
    singular                       reconstructed cross-field index per vertex (SEE CAVEAT)

Caveats that have already cost review turns
-------------------------------------------
1. `singular` uses a NAIVE per-edge matching, not the product's `principal_matching`.
   Non-integer indices are artifacts of this script, not of the field. Treat its output as
   CORROBORATION ONLY -- never as authority. Where the product's own runtime evidence says
   a vertex is/isn't singular, the product wins.

2. Dihedral sharpness is NOT a proxy for the product's barrier set. Barrier edges are
   region-restricted: `FieldTransportAtlas.cpp` requires BOTH incident faces to lie inside
   the region being localized. A hard feature edge that BOUNDS a region is not a barrier.
   Proved on this fixture: vertex 47 has three exactly-90 degree incident edges and still
   emits ports, i.e. it is not barrier-incident. (M3-CP4c-3-TB9-REV, TB11-REV.)

3. Face/edge keys in production loci are CANONICAL SORTED sets. A locus `(36,38,39)` is a
   vertex set; do not infer mesh-row corner order from it. `face`/`rows` match on the set.

4. `fan` mirrors `build_vertex_fan_slots` (edges take EVEN slots, faces ODD, alternating
   around the star). It is a reimplementation for review, not the product function.
"""

import argparse
import collections
import math
import os
import sys

DEFAULT_FIXTURE = "mechanical_feature"


def repo_root():
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.abspath(os.path.join(here, os.pardir, os.pardir, os.pardir))


def fixture_paths(stem):
    base = os.path.join(repo_root(), "benchmarks", "fixtures", "milestone-g", stem)
    return base + ".obj", base + ".rawfield"


# ---------------------------------------------------------------- vector helpers
def sub(a, b):
    return [a[i] - b[i] for i in range(3)]


def dot(a, b):
    return sum(a[i] * b[i] for i in range(3))


def cross(a, b):
    return [a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0]]


def unit(a):
    length = math.sqrt(dot(a, a))
    if length == 0.0:
        return None
    return [x / length for x in a]


class Mesh(object):
    def __init__(self, stem):
        self.stem = stem
        obj_path, self.rawfield_path = fixture_paths(stem)
        if not os.path.exists(obj_path):
            sys.exit("fixture not found: %s" % obj_path)
        self.V = []
        self.F = []
        for line in open(obj_path):
            parts = line.split()
            if not parts:
                continue
            if parts[0] == "v":
                self.V.append([float(x) for x in parts[1:4]])
            elif parts[0] == "f":
                self.F.append([int(t.split("/")[0]) - 1 for t in parts[1:4]])

        self.normals = []
        for f in self.F:
            n = unit(cross(sub(self.V[f[1]], self.V[f[0]]),
                           sub(self.V[f[2]], self.V[f[0]])))
            self.normals.append(n)

        self.edge_faces = collections.defaultdict(list)
        self.star = collections.defaultdict(list)
        for i, f in enumerate(self.F):
            for a, b in ((f[0], f[1]), (f[1], f[2]), (f[2], f[0])):
                self.edge_faces[(min(a, b), max(a, b))].append(i)
            for v in f:
                self.star[v].append(i)

    # -- derived quantities -------------------------------------------------
    def key(self, a, b):
        return (min(a, b), max(a, b))

    def dihedral_deg(self, a, b):
        """Angle between the two incident face normals; None on a boundary edge."""
        faces = self.edge_faces[self.key(a, b)]
        if len(faces) != 2:
            return None
        n0, n1 = self.normals[faces[0]], self.normals[faces[1]]
        if n0 is None or n1 is None:
            return None
        return math.degrees(math.acos(max(-1.0, min(1.0, dot(n0, n1)))))

    def angle_defect(self, v):
        total = 2.0 * math.pi
        for fi in self.star[v]:
            f = self.F[fi]
            i = f.index(v)
            u = sub(self.V[f[(i + 1) % 3]], self.V[v])
            w = sub(self.V[f[(i + 2) % 3]], self.V[v])
            denom = math.sqrt(dot(u, u) * dot(w, w))
            if denom == 0.0:
                continue
            total -= math.acos(max(-1.0, min(1.0, dot(u, w) / denom)))
        return total

    def rows_with_vertex_set(self, triple):
        want = set(triple)
        return [i for i, f in enumerate(self.F) if set(f) == want]

    def boundary_edges(self):
        return [e for e, fs in self.edge_faces.items() if len(fs) == 1]


# ---------------------------------------------------------------- subcommands
def cmd_topology(mesh, _args):
    bnd = mesh.boundary_edges()
    print("fixture            : %s" % mesh.stem)
    print("vertices           : %d" % len(mesh.V))
    print("faces              : %d" % len(mesh.F))
    print("edges              : %d" % len(mesh.edge_faces))
    print("boundary edges     : %d" % len(bnd))
    print("Euler V-E+F        : %d" % (len(mesh.V) - len(mesh.edge_faces) + len(mesh.F)))
    nonmanifold = [e for e, fs in mesh.edge_faces.items() if len(fs) > 2]
    print("non-manifold edges : %d" % len(nonmanifold))


def cmd_vertex(mesh, args):
    for v in args.values:
        if v >= len(mesh.V):
            print("v%-4d OUT OF RANGE" % v)
            continue
        incident = sorted(e for e in mesh.edge_faces if v in e)
        print("v%-4d xyz=%s  degree(faces)=%d  angleDefect=%+.9f"
              % (v, ["%.6f" % c for c in mesh.V[v]], len(mesh.star[v]), mesh.angle_defect(v)))
        for e in incident:
            d = mesh.dihedral_deg(*e)
            print("      edge %2d-%-3d faces=%-12s dihedral=%s"
                  % (e[0], e[1], mesh.edge_faces[e],
                     "boundary" if d is None else "%.6f deg" % d))


def cmd_edge(mesh, args):
    a, b = args.a, args.b
    e = mesh.key(a, b)
    faces = mesh.edge_faces.get(e, [])
    d = mesh.dihedral_deg(a, b)
    print("edge %d-%d" % e)
    print("  incident mesh rows : %s" % faces)
    for fi in faces:
        print("      row %-4d = %s" % (fi, tuple(mesh.F[fi])))
    print("  interior           : %s" % (len(faces) == 2))
    print("  dihedral           : %s" % ("n/a" if d is None else "%.9f deg" % d))


def _report_triples(mesh, triples):
    for t in triples:
        rows = mesh.rows_with_vertex_set(t)
        detail = ", ".join("row %d = %s" % (r, tuple(mesh.F[r])) for r in rows) or "NO MATCH"
        print("  %-16s -> %s" % (str(tuple(sorted(t))), detail))


def cmd_face(mesh, args):
    vals = args.values
    if len(vals) % 3 != 0:
        sys.exit("`face` needs a multiple of three vertex indices")
    _report_triples(mesh, [vals[i:i + 3] for i in range(0, len(vals), 3)])


def cmd_rows(mesh, args):
    triples = []
    for token in args.triples:
        parts = [p for p in token.replace("(", "").replace(")", "").split(",") if p.strip()]
        if len(parts) != 3:
            sys.exit("expected A,B,C but got %r" % token)
        triples.append([int(p) for p in parts])
    _report_triples(mesh, triples)


def cmd_chain(mesh, args):
    chain = args.values
    print("chain: %s" % " -> ".join(str(v) for v in chain))
    for v in chain:
        print("  v%-4d %s" % (v, ["%.6f" % c for c in mesh.V[v]]))
    print("consecutive edges:")
    for a, b in zip(chain, chain[1:]):
        d = mesh.dihedral_deg(a, b)
        present = mesh.key(a, b) in mesh.edge_faces
        print("  %2d-%-3d present=%-5s faces=%-12s dihedral=%s"
              % (a, b, present, mesh.edge_faces.get(mesh.key(a, b), []),
                 "n/a" if d is None else "%.6f deg" % d))
    # collinearity of the whole walk
    if len(chain) >= 3:
        p0 = mesh.V[chain[0]]
        d0 = unit(sub(mesh.V[chain[1]], p0))
        collinear = True
        for v in chain[2:]:
            dv = unit(sub(mesh.V[v], p0))
            if dv is None or d0 is None:
                collinear = False
                break
            if math.sqrt(dot(cross(d0, dv), cross(d0, dv))) > 1e-12:
                collinear = False
                break
        print("collinear walk     : %s" % collinear)


def cmd_fan(mesh, args):
    """Reimplementation of build_vertex_fan_slots for review purposes.

    Edges take EVEN slots and faces ODD, alternating around the star, so each face slot
    lies strictly between its two bounding edge slots.
    """
    v = args.v
    faces = mesh.star[v]
    if not faces:
        sys.exit("vertex %d has no incident faces" % v)
    by_start = {}
    incoming = collections.Counter()
    all_edges = set()
    for fi in faces:
        f = mesh.F[fi]
        i = f.index(v)
        nxt, prv = f[(i + 1) % 3], f[(i + 2) % 3]
        start, end = mesh.key(v, nxt), mesh.key(prv, v)
        if start in by_start:
            sys.exit("non-manifold fan at v%d" % v)
        by_start[start] = (fi, start, end)
        incoming[end] += 1
        all_edges.add(start)
        all_edges.add(end)

    starts = [e for e in sorted(all_edges) if incoming[e] == 0]
    cycle = not starts
    start_edge = sorted(all_edges)[0] if cycle else starts[0]

    print("vertex %d  incidentFaces=%d  closedFan=%s" % (v, len(faces), cycle))
    slot = 0
    current = start_edge
    seen_edges, seen_faces = set(), set()
    while True:
        if current in seen_edges:
            if cycle and current == start_edge:
                break
            sys.exit("fan walk revisited edge %s" % (current,))
        seen_edges.add(current)
        print("  slot %-3d EDGE %2d-%-3d" % (slot, current[0], current[1]))
        slot += 1
        wedge = by_start.get(current)
        if wedge is None:
            break
        fi = wedge[0]
        if fi in seen_faces:
            sys.exit("fan walk revisited face row %d" % fi)
        seen_faces.add(fi)
        print("  slot %-3d FACE row %-4d %-16s  primary(trace)=%d  primary(edge-ray)=%d"
              % (slot, fi, str(tuple(sorted(mesh.F[fi]))), 2 * slot + 1, 2 * slot))
        slot += 1
        current = wedge[2]
        if cycle and current == start_edge:
            break
    if not cycle and current not in seen_edges:
        print("  slot %-3d EDGE %2d-%-3d" % (slot, current[0], current[1]))


def cmd_singular(mesh, args):
    if not os.path.exists(mesh.rawfield_path):
        sys.exit("rawfield not found: %s" % mesh.rawfield_path)
    tokens = open(mesh.rawfield_path).read().split()
    n = int(tokens[0])
    face_count = int(tokens[1])
    nums = [float(x) for x in tokens[2:]]
    if face_count != len(mesh.F):
        print("WARNING: rawfield face count %d != mesh face count %d"
              % (face_count, len(mesh.F)))
    vals = [[[nums[f * n * 3 + j * 3 + k] for k in range(3)] for j in range(n)]
            for f in range(face_count)]

    b1, b2 = [], []
    for idx, f in enumerate(mesh.F):
        e1 = sub(mesh.V[f[1]], mesh.V[f[0]])
        u1 = unit(e1)
        b1.append(u1)
        b2.append(cross(mesh.normals[idx], u1) if u1 else None)

    def ang(fi, vec):
        return math.atan2(dot(vec, b2[fi]), dot(vec, b1[fi]))

    def wrap(a):
        return (a + math.pi) % (2 * math.pi) - math.pi

    effort = collections.defaultdict(float)
    for (a, b), fs in mesh.edge_faces.items():
        if len(fs) != 2:
            continue
        f0, f1 = fs
        ev = sub(mesh.V[b], mesh.V[a])
        a0, a1 = ang(f0, ev), ang(f1, ev)
        th0 = [ang(f0, vals[f0][j]) - a0 for j in range(n)]
        th1 = [ang(f1, vals[f1][j]) - a1 for j in range(n)]
        best = min((sum(abs(wrap(th1[(j + k) % n] - th0[j])) for j in range(n)), k)
                   for k in range(n))
        k = best[1]
        e = sum(wrap(th1[(j + k) % n] - th0[j]) for j in range(n))
        effort[a] += e
        effort[b] += e

    print("CAVEAT: naive matching, NOT the product's principal_matching.")
    print("        Non-integer indices are artifacts of this script. Corroboration only.")
    print("singular vertices (|index| > 1e-6):")
    found = 0
    for v in range(len(mesh.V)):
        idx = (effort[v] + n * mesh.angle_defect(v)) / (2 * math.pi)
        if abs(idx) > 1e-6:
            found += 1
            flag = "" if abs(idx - round(idx)) < 1e-6 else "   <-- non-integer (artifact)"
            print("  v%-4d index=%+.6f  N*index=%+.3f  defect=%+.9f%s"
                  % (v, idx, idx * n, mesh.angle_defect(v), flag))
    print("count: %d" % found)


def main():
    parser = argparse.ArgumentParser(
        description="Static probe for Directional benchmark fixtures (review aid only).")
    parser.add_argument("--fixture", default=DEFAULT_FIXTURE,
                        help="fixture stem under benchmarks/fixtures/milestone-g/")
    sub_parsers = parser.add_subparsers(dest="cmd", required=True)

    sub_parsers.add_parser("topology").set_defaults(fn=cmd_topology)

    p = sub_parsers.add_parser("vertex")
    p.add_argument("values", type=int, nargs="+")
    p.set_defaults(fn=cmd_vertex)

    p = sub_parsers.add_parser("edge")
    p.add_argument("a", type=int)
    p.add_argument("b", type=int)
    p.set_defaults(fn=cmd_edge)

    p = sub_parsers.add_parser("face")
    p.add_argument("values", type=int, nargs="+")
    p.set_defaults(fn=cmd_face)

    p = sub_parsers.add_parser("rows")
    p.add_argument("triples", nargs="+")
    p.set_defaults(fn=cmd_rows)

    p = sub_parsers.add_parser("chain")
    p.add_argument("values", type=int, nargs="+")
    p.set_defaults(fn=cmd_chain)

    p = sub_parsers.add_parser("fan")
    p.add_argument("v", type=int)
    p.set_defaults(fn=cmd_fan)

    sub_parsers.add_parser("singular").set_defaults(fn=cmd_singular)

    args = parser.parse_args()
    args.fn(Mesh(args.fixture), args)


if __name__ == "__main__":
    main()
