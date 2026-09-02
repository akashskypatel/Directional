# Review tools

Read-only helpers for independent REVIEW turns. **None of these is product, test, benchmark,
or selector authority.** They run no Directional code, compile nothing, and write nothing to
the repository. They exist because the same handful of derivations was being rewritten inline
every review turn — `M3-CP4c-3-TB9-REV`, `TB11-REV` and `TB12-REV` each regenerated
substantially the same fixture-probing script from scratch.

Pure standard library, deliberately: `numpy` has been missing on two different review machines.

| Tool | Answers |
|---|---|
| `fixture_probe.py` | Where is this failure in the committed fixture? Mesh topology, vertex stars, dihedrals, face-triple → mesh row, vertex fans/slots, a corroborating singularity reconstruction. |
| `selector_probe.py` | Selector hashes, cardinality, prefix continuity, ordinal ↔ identity, accepted-365 membership, and `tests/…:LINE` → enclosing identity → ordinal. |
| `review_check.py` | The BG0/BI0 authority opener, and the pre-commit review-boundary gate. |

---

## `review_check.py`

```
python3 review_check.py authority <semantic-source-sha>
python3 review_check.py boundary [--expect-selector N=SHA ...]
```

**`authority`** is the first thing a review turn should run. It proves the declared
semantic/package source commit exists, is an ancestor of `HEAD`, and — critically — that
**no code surface drifted between it and `HEAD`**. That last check is what licenses reading
the working tree as evidence about the immutable package. Without it, quoting `HEAD` source
in a review record proves nothing about what was actually tested.

**`boundary`** is the gate before committing a review turn: no product/test/fixture/build
mutation, no selector mutation, every selector still hashing to its committed value, durable
section markers preserved, and a printed list of exactly which documents the turn changed.
Exit code 1 on any failure, so it can gate a commit.

## `selector_probe.py`

```
python3 selector_probe.py list
python3 selector_probe.py hash 378 --prefix 365 377
python3 selector_probe.py ordinal 366
python3 selector_probe.py find RotationRay
python3 selector_probe.py prefix 377 378
python3 selector_probe.py identity tests/FieldAlignedCurveNetworkTests.cpp:9408
python3 selector_probe.py identity --name GlobalTopologyPlan.MechanicalFeatureWitness...
```

**Hashes are computed over LF-normalized bytes.** Published selector hashes are LF; a Windows
checkout may hold CRLF, so a naive `sha256sum` will *not* reproduce them. This bit has cost
time more than once.

`identity <file>:<line>` resolves a source line to its enclosing `TEST`/`TEST_F` and then to
its selector ordinal and accepted-365 status. Use it rather than remembering line numbers —
**line numbers move every CB turn**; the same lookup that returned ordinal 328 during TB9-REV
returns a different identity today.

## `fixture_probe.py`

```
python3 fixture_probe.py topology
python3 fixture_probe.py rows 45,46,47 43,44,45 36,38,39     # paste a trace history
python3 fixture_probe.py chain 47 45 43 41 39 36             # walk a vertex chain
python3 fixture_probe.py vertex 36 38 47
python3 fixture_probe.py edge 36 38
python3 fixture_probe.py fan 47                              # vertex fan + slot numbers
python3 fixture_probe.py singular
python3 fixture_probe.py --fixture torus topology
```

`fan` mirrors `build_vertex_fan_slots`: edges take **even** slots, faces **odd**, alternating
around the star, so each face slot lies strictly between its two bounding edge slots. It
prints both `primary` forms (`2·slot+1` for trace rays, `2·slot` for edge rays), which is what
a rotation-system locus reports.

---

## Caveats that have already cost review turns

1. **`singular` is corroboration, never authority.** It uses a naive per-edge matching, not
   the product's `principal_matching`. Non-integer indices in its output are artifacts of the
   script. Where the product's runtime evidence says a vertex is or is not singular, the
   product wins. (It agreed with TB9's runtime facts on the vertices TB9 constrained, which is
   the most it is good for.)

2. **Dihedral sharpness is not a proxy for the product's barrier set.** Barrier edges are
   region-restricted — `FieldTransportAtlas.cpp` requires *both* incident faces to lie inside
   the region being localized, so a hard feature edge that *bounds* a region is not a barrier.
   Proved on the mechanical fixture: vertex 47 has three exactly-90° incident edges and still
   emits ports, i.e. it is not barrier-incident. (`M3-CP4c-3-TB9-REV` §3.6, `TB11-REV`.)

3. **Locus face and edge keys are canonical sorted sets.** A locus `sourceFace=(36,38,39)` is
   a vertex *set*; do not infer mesh-row corner order from it. `rows`/`face` match on the set
   and print the actual row order.

4. **Geometry locates a failure; only the source predicate adjudicates one.** These tools are
   for finding *where* a trace went and *what* the fixture looks like there. Whether the
   product was correct is decided by reading the product's own predicates. (`LESSONS.md` §4 83.)

---

## Worked example — reproducing `M3-CP4c-3-TB12-REV`

The TB12 ordinal-366 census reported five rays at vertex 47 with face slots 1, 3, 5, 7 and
`primary` 3, 7, 11, 15. Independently:

```
$ python3 fixture_probe.py fan 47
vertex 47  incidentFaces=4  closedFan=True
  slot 0   EDGE 45-47
  slot 1   FACE row 59   (45, 46, 47)      primary(trace)=3   primary(edge-ray)=2
  slot 2   EDGE 46-47
  slot 3   FACE row 100  (46, 47, 72)      primary(trace)=7   primary(edge-ray)=6
  slot 4   EDGE 47-72
  slot 5   FACE row 101  (47, 72, 73)      primary(trace)=11  primary(edge-ray)=10
  slot 6   EDGE 47-73
  slot 7   FACE row 290  (45, 47, 73)      primary(trace)=15  primary(edge-ray)=14
```

Every face, slot and `primary` matches the runtime census, and the fan is closed — which is
what establishes that the rotation is determined down to *which wedge* a ray occupies, leaving
only the within-wedge order undefined.
