# P13-l2 source microedge classification — supplemental WIP Review

**Owning turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP`, still IN_PROGRESS. This file is supplemental evidence, **not** a second Review authority or a Code + Build authorization. Consolidate it into the owning completed-mesh-stitch Review before formal closure.

## Frozen evidence / runtime boundary

- CB96 semantic product `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, immutable package `13460725846`; source snapshot `a1e3d84821a03f33ee9a870d101d802b38337573` (run `42164386607`, artifact `13478417321`, archived source SHA-256 `3c51942ee03535a5b669f6d5057fe711535de1ca1e67306b468bc7a7fb5b305e`, 6212/6212 file hashes previously verified).
- Rejected diagnostic CB96 mesh from earlier artifact `13469796788`, with 67,961 vertices and 67,750 quads; no success or new TB evidence.
- Resumed branch comparison from snapshot to `129c5431bf881f60cfdcaefa18e5b6c2f8cb408d`: review documentation, handoff, cleanup marker and STATUS changed; no semantic implementation source changed.
- This attempt did **static analysis only** on frozen input and output bytes. No generated Directional executable, compile, test or benchmark was run.

## Independent source-edge finding

Vase input `benchmarks/fixtures/milestone-g/vase.off`: 1274 vertices, 2404 source triangles. Source edge `(773,775)` belongs to precisely two triangles: source rows `285=(773,519,775)`, `1199=(773,775,1169)`. Its length is `0.03007428152092757`, with unsigned oriented-face normal deviation `3.2898067185157487°`.

The benchmark `make_remesh_options` supplies the default `AdaptiveFeatureMapOptions` (no user hard tags). The classifier computes strength `sqrt(relativeScore * smoothstep(dihedral, absoluteLow, absoluteHigh))`; its default absolute low is 8° on organic and 15° on CAD-like regions. Because 3.2898° lies below **both** thresholds, the feature strength for this edge is zero independently of the adaptive percentile score. It is neither boundary nor nonmanifold; under those configured defaults its input classification is **Smooth**, not HardFeature. The source edge is **not itself an authoritative hard-feature rail**.

That does **not** authorize deleting any traced curve, network edge, periodic/cut relation, or arrangement node. The exact `SurfaceArrangementNodeOccurrence.sourceArc` and adjacent `SurfaceArrangementHalfedge.{curveId,railId,hardFeature}` were not retained in the available diagnostic artifacts. Their upstream ownership remains unresolved.

## Source-local geometry of the three-vertex cluster

Frozen output position projected onto source edge `773→775`:

| Global output vertex | Previously retained typed source support | Edge parameter | Distance to infinite source edge |
|---|---|---:|---:|
| 53049 | source edge (773,775) | 0.3736864579042779 | ~1.7e-18 |
| 28576 | face interior (773,775,1169) | 0.3736857521583742 | 8.703525872478638e-08 |
| 53052 | typed support not independently decoded; geometry only | 0.3736738848683131 | ~4.2e-17 |

Measured distances: `|53049−28576|=8.958587186761864e-08`, only `2.978820019533274e-06` of the source edge length; `|53049−53052|=3.7812502317558406e-07`; `|28576−53052|=3.6735936745952676e-07`. **Previously verified authoritative arrangement-node IDs differ**: do not infer a weld from proximity.

The original patch 23301 six-vertex boundary is simple in its Newell plane, polygon area `3.076601640467252e-05`, minimum projected clearance `8.944653152366212e-08`. Its three boundary-only two-quad decompositions all retain the inherited microedge; the alternative diagonals trade the current near-corner issue for severely thin quads (minimum areas ~1.4e-10 or ~1.85e-09). All alternative quad normals remain within ~3.3° of the two local source face normals, so the existing 60° source-orientation predicate alone does not reject them. **No alternative is yet certified as valid**; a calibrated quality/clearance criterion is still absent. `DESIGN.md` §2.1 item 10 and §2.2 separate structural validity from quality disposition; D1 is not current CP3 acceptance.

Distinct from this cluster, completed quad `21286` on patches 4955/4957 consumes all four consecutive nodes of a *single three-edge logical side* as one face. That is a **completion topology** defect, independent of numerical quality thresholds.

## Remaining Review requirements

1. Recover the actual source-arc, rail, junction/cut, and incident-halfedge ownership of the 23301/23302 microcluster from already-authoritative evidence or through a separately authorized diagnostic boundary. Prove whether each node is an indispensable route or a redundant optional support trace; no position weld or narrowed identity classes.
2. If a redundant trace is proven, correction belongs to its **earliest producer**, with transactional, globally conforming side updates across all incident patches. Otherwise preserve exact nodes and report any impossibility/quality failure by its truthful typed cause.
3. The eventual bounded Code+Build plan must give a negative-on-legacy *one-logical-side-as-quad* witness (4955/4957) and valid thin-feature positive controls; geometry validator must also distinguish 55/15372 disjoint, 4304/4308 concave-fan false hit, true distinct-face convex overlap and noncoplanar contacts without dropping real positives.
4. Continue this **same Review** until source-route authority and one owner-specific successor's falsifiers are frozen; do **not** start that successor here or promote CP3.

Unchanged: accepted CP2 `491/491`, TB83 candidate `903/903` (membership 984), stable `66/17/49`, debt `1`, selector497 and CP3 unpromoted.
