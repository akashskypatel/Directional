# M6-CP3-CB1-ENTRY-R4 — source-edge index namespace collision (review stop)

**Classification:** `REVIEW_BLOCKER` on the *current* R4 Code + Build turn. The observed source contradicts a previously accepted Review namespace definition. This document is a **source-exact finding/request**, NOT a new accepted Definition, independent normative Review decision, run of a C++ executable, or authorization for TB497. Do not silently change `SurfaceCellRail::sourceEdges` semantics inside the blocked Code + Build turn.

## Exact provenance and existing authority

- Independently extracted source from exact eight-target GMP/GMPXX compile artifact `11740652527`, run `38236639195`, source `dcf24e2c881b9ed67ec8f992d94d4b4e364fd4e2`. Rechecked ZIP SHA-256 `7af625c8ca0bcbc5f4f59d3793484280157e388db05a412b9d188d4cba1418a2` and packaged `metadata/source-commit.txt`. Earlier compile evidence verified `28/28` package checksums, 8/8 targets, GMPXX/GMP link, build/preflight `0/0`, `runtimeExecution=false`. The source was inspected without running, compiling, linking, or invoking any Directional executable.
- **Accepted RA-43 namespace inventory:** `.agents/Directional/Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`, §4, explicitly defines `SurfaceCellRail::sourceEdges` as a **feature-edge index into `featureMap.edges`**. `SurfaceCellRailSample::sourceEdge` is instead the face-local corner index. This accepted decision is binding until a separately authoritative Review amends it.
- **Current producer, source `src/pipeline/RemeshPipeline.cpp`:** `build_authoritative_surface_cell_rails` indexes `featureMap.edges[entry.edgeIndex]` at :9350 and publishes `rail.sourceEdges.push_back(entry.edgeIndex)` at :9359; its single-edge path publishes `rail.sourceEdges = {edgeIndex}` at :9503. These are **feature-map vector positions**, not `TriMesh::EV` positions. Failure `failedEdgeIndex` currently uses the same feature index (:9259-9262, :9535-9537).
- **Current consumer contradicts producer and Review:** `src/geometry/SurfaceCellTracing.cpp:4233-4245` in `canonical_field_aligned_candidate` indexes `sourceMesh.EV(declaredEdge, *)` using `rail.sourceEdges[interval]`, then requires its topological pair equal the independently published typed vertex pair. That is an *unreviewed change of index namespace*, not merely a strengthened equality check.
- **A second consumer has the same inconsistency:** component aggregation in `RemeshPipeline.cpp:17577-17592` constructs `globalEdgeByLocal` indexed by component `TriMesh::EV` local edge. `RemeshPipeline.cpp:18106-18114` uses each rail's feature-map `sourceEdge` as that EV index for remapping, potentially publishing the wrong global index or `-1`.
- **Regression now encodes the opposite interpretation:** `tests/SurfaceCellREPackageTests.cpp:292-298` demands producer raw `rail.sourceEdges` refer to matching `sourceMesh.EV` rows. That test and later compile-only documents used EV semantics without amending the accepted RA-43 Review namespace.

## Counterexample independently derived from constructors (not a runtime claim)

For a valid single oriented triangle with face vertex row `(0,1,2)`:

| Index | `featureMap.edges` (lexical `std::map` insertion at `AdaptiveFeatureMap.h:181-189, :204-244`) | `TriMesh::EV` (DCEL face/halfedge first encounter `DCEL.h:2993-3059` and `TriMesh.h:154-173`) |
|---|---|---|
| 0 | (0,1) | (0,1) |
| 1 | (0,2) | (1,2) |
| 2 | (1,2) | (0,2) |

The producer therefore emits raw `sourceEdges[interval] = 1` for a genuine rail on `(0,2)`; the current consumer indexes EV row 1 and obtains `(1,2)` and returns `InvalidRailGeometry` although the typed source-vertex chain is exactly `(0,2)`. This is a **structural counterexample to the purported index equivalence**. In a two-face/disconnected/component setting, edge ordering may diverge in still more ways. The counterexample derives solely from current source ordering. The actual default pipeline's first observable runtime error, counts and affected frozen identities remain **unexecuted and unproven**.

## Required source-exact Definition/Review decision before changing semantics

**Proposed finding:** `R4-IDX-01 / AUTHORITY_DOMAIN_CONFLATION`; candidate repeat of existing RP-01 class. It is **not a newly counted stable regression** without accepted runtime evidence.

1. Independently confirm both indexing domains and all consumers, including component remap, failure diagnostics, rail provenance hashing, the source-built field-aligned candidate, and the already-landed Phase20 positive regression. Check the source of any manually constructed rails.
2. Freeze **one** `SurfaceCellRail::sourceEdges` contract. An EV-index contract is a plausible repair because field-aligned validation and component remap already use EV, but it **requires amending RA-43 §4 explicitly** and converting the producer's curve-run and standalone rails through a checked `(vertex pair) -> meshWhole.EV row` map. Retain feature-map indices in `coveredEdges` and `failedEdgeIndex` with an explicit conversion; do not conflate diagnostic index spaces. Alternatively keep the accepted feature-index contract and redesign both EV consumers to take authenticated feature-map lookup evidence, as well as correcting the test. The current mixed interpretation is impermissible.
3. Require source-valid **nonvacuous** regressions where lexical feature-map and DCEL EV orders differ (including a boundary/hard-feature rail, closed rail, component-local to global remap), plus negative foreign raw-index tests under the newly reviewed contract. A test of only an edge where both indices coincide (e.g. `(0,1)`) proves nothing.
4. Retain source-attested A3/A4, RA-43.4 typed vertex constraints, first rejecting predicate, original 497 selector identities, and independent overfull-A3 Review. No weakening `InvalidRailGeometry` / typed mismatch gates or inferring runtime PASS.
5. On Review acceptance, resume **this same canonical R4 Code + Build** under corrected instructions; then commit a bounded source patch, perform the standard eight-target GMP/GMPXX compile and preserve immutable evidence. Do not start `M6-CP3-TB1-ENTRY-R4-EXEC` beforehand.

## Boundary and disposition

**REVIEW STOP — UNRESOLVED.** No production, tests, fixtures, selectors, benchmarks, workflow permissions, or frozen normative definitions changed by this finding. Do not treat earlier green compiles or a valid typed vertex chain as confirmation of raw index-domain consistency. Keep R4 stopped for the required source-exact adjudication; successor remains UNKNOWN while its repository-root beacon is blocked. Latest reviewed runtime baseline unchanged: accepted CP2 491/491, rejected R3 403/497, 94 RED/88 accepted CP2 losses, ledger 66/17/49 debt 1.
