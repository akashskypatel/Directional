# P13 arrangement sliver cells — review WIP (2026-11-02)

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (Review/Definition). **Unfinished.** No single producer owner or exact corrective patch has been proved; do not start Code + Build.

## Exact evidence verified this turn

- Snapshot event/source SHA `898316210ab810daa10d2072db927f9ebe4b2a98`, run `41392950017`, artifact `13118097735`, ZIP SHA256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062`. Independently verified ZIP, tar archive, **6092/6092** source-file checksums. No local build or test executed.
- Independently downloaded TB70 census run `41388863937`, artifact `13117365194`, ZIP SHA256 `b4d643b08d0de5eb20dbe805f6a607e53572ec969c28028dc6b23e7cdced7266`; 9/9 content hashes verified. `raw/3.log` reports Vase `NotProductionReady:completion/PatchCompletionRejected`, `InvalidCompletionQuadEmbedding`, patch `6095`, generated vertex `-1`, 192482 trace segments, 26827 arrangement cells, **0 output quads**. Cylinder PASS, BunnyRandom P13-e RED. TB70's separate accepted gate is **880/880**, selector membership 961; neither proves Vase direct acceptance.
- RA-197 prior scratch probe (not rerun this turn): P13-h2 needle cells `6095,20533,20968,22350` (2×2,2×2,3×2,2×4), ~10^-5 short separation over ~10^-2 long dimension; each of bilinear/Coons/Tutte fails some. P13-i two-sided lens cells `26735,26764,26781,26802,26812`, each bordered by one field trace and one hard rail, tip polygon interior angles 0.2°–26.9°. These interior angles **are not a measured field-vs-rail tangent angle**.

## Independent source-flow mapping

- `src/pipeline/RemeshPipeline.cpp:11040-11107`: `surface_arrangement_arcs_from_flow_rep` carries retained FlowRep `id/provenance`, `strand`, `family`, `railId/curveId`, `proposalId/proposalSeedId/proposalSide/proposalBoundarySegment`, source-face/chart into arrangement arcs.
- `src/pipeline/RemeshPipeline.cpp:13666-13770`: only then `build_surface_cell_complex` constructs arrangement incidence. The `retainIntermediateGeometry` path exposes both arrangement arcs and the cell complex, but retaining all products could increase memory.
- `include/directional/geometry/SurfaceArrangement.h:253-414`: each cell has ordered halfedge IDs; each halfedge has trace/rail IDs plus complete provenance. These interfaces can establish whether a needle/lens was already delimited by upstream selected arcs or was wrongly connected by arrangement.
- `src/geometry/FlowRepStrands.cpp:590-609`: hard-rail arcs are mandatory and retain stable `HardRailId`. Do not remove mandatory rails to erase a lens.
- `src/geometry/SurfaceArrangement.cpp:6650-6684`: `Sliver` is an absolute-area check (`<= 1e-14`), **not** a proven aspect-ratio/target-width classification. Do not tune it as a purported fix.
- `src/geometry/PureQuadCompletion.cpp:1875-1893`: <3 logical sides is currently rejected; relaxing admissibility would not establish a valid pure-quad patch.

## Next same-turn probe — mandatory before an owner ruling

On exact CB76 source with an authorized *scratch-only* fresh Vase run, fallback Fail and recovery disabled, collect a bounded per-halfedge provenance inventory for each of **all nine** cell IDs. Emit `cell, halfedge, from/to, source face/chart root, sourceArc, complete provenance, strand, family, rail/curve, proposal/seed/side/segment, source/rail parameters, vertex source-face+barycentric identity, side index`. Join sourceArc to the retained FlowRep arc, then trace/proposal and exact source-feature rail. Compute same-sheet intrinsic minimum long-side separation, length/thickness ratio, transported cross-field versus oriented rail tangent angle at each lens tip, and canonical hashes; don't substitute the RA-197 tip polygon angles. A per-cell streaming receipt is preferable to globally retaining intermediate products if the memory budget is threatened.

**Owner discriminator:** If the exact selected source arcs already bound those needles/lenses, scrutinize the phase-front/trace and FlowRep selection; if the arcs do not imply the cells but the arrangement pairs the wrong wedge successors, the directed arrangement builder owns it. If a prescribed needle boundary is valid with an admissible topology-distinct embedding, completion might own P13-h2 only; that does not explain P13-i. Do not force both into one producer without all nine causality records.

Freeze a single correction only after proving its source-authoritative effect and demonstrating unchanged boundary coverage, hard-rail ownership, sheets, singular index, and no new T-junction/duplicate quad. Follow with non-vacuous positive and negative reduced fixtures, permutation/inversion controls, same-sheet guards, and unchanged accepted-green prefix. Separate CB compile-only from later TB artifact-only execution.

## Continuation and status

No product, test, build, selector or ledger code was changed. No runtime probe was performed this turn. The blockers are **unresolved investigation work with an authorized next action**, not proof of a platform outage. Preserve original start `2026-11-02T05:14:30Z`, same turn ID, blank Ended timestamp. A full user-downloadable companion report exists as `directional-p13-sliver-review-continuation-20261102.md` SHA256 `67904ad43b57cd78070906dd2b09fb39ad2910662df4f47c8ae717bc6893c002`. Source snapshot trigger `.agents/connector-triggers/source-snapshot/m6-cp3-defn-p13-arrangement-sliver-cells-20261102-0515.txt` is temporary: delete it before final STATUS. Carry P13-e and O23 unchanged; no CP3 promotion.
