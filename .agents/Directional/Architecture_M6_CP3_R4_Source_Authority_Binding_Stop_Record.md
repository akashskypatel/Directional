# M6-CP3-CB1-ENTRY-R4 — source-authority binding stop record (2026-10-10)

**Disposition:** REVIEW_BLOCKER candidate found while resuming the authorized R4 Code + Build turn. The source-exact R4-REV/RA-43 producer *locations* remain useful, but the reviewed claim that the checked factory can authenticate both per-face +U gauges and terminal rail contacts from its current inputs is not demonstrated by the current API. Do not attempt a barycentric/epsilon-derived identity shortcut. Do not advance to TB497. A source-authoritative independent decision is required before implementing those bindings.

## Frozen authority and compile receipts

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft.
- Latest semantic implementation: `522b3b1130e981426351ed6afd04c81efde1d742` (seven two-face fixture repairs plus earlier typed factory error propagation).
- Exact clean compile-only source: `522b3b1130e981426351ed6afd04c81efde1d742`, run `38053331246`, package `11670810927`, SHA-256 `73f5da0ec11af03dd105879e51fa5ac71dc483df124eb1672e27b0410ae8a281`; 28/28 SHA256SUMS verified, eight mandatory targets, GMP/GMPXX in generated link command, empty final source status, exit 0 and `runtimeExecution=false`. No tests/benchmarks executed.
- Current inspection snapshot source SHA `e367beab02d31b4b50aab36672384ac382f33e9d` (run `38053795411`, artifact `11670088024`); outer SHA256 `5b54885e1b74d6bd8c20d9d11bccc0c2e7538a53aa0945f91bb1ba1c095da3df`, 5,871 internal file hashes verified, zero mismatch. Snapshot was taken after the fixture commit and subsequent control-plane/status changes. No later semantic source change was detected during inspection.

## Finding 1: exact terminal contact is not a checked-factory input

- `src/pipeline/RemeshPipeline.cpp:9328-9356` constructs `SurfaceCellRail::sourceVertices` from exact ordered-curve endpoint IDs and validates continuity; `:9491` handles single-edge rails.
- `include/directional/geometry/SurfaceCellTracing.h:1488-1508` defines `SurfaceHardRailRouteEndpointCertificate` with two typed face attachments and a `SurfaceHardRailFieldTransition` terminal carrier, but no exact terminal `SourceVertexId` or source-owned rail contact identity.
- `include/directional/geometry/SurfaceCellTracing.h:1850-1865` and `src/geometry/SurfaceCellTracing.cpp:7969-7984` show `SurfacePhaseFrontProduct::make` accepts source faces, atlas, hard-feature edge keys and route certificates, **not** `SurfaceCellRail::sourceVertices`, `SurfaceCellRail`, or another authenticated mapping from `HardRailId` to its endpoint source vertex.
- `src/geometry/SurfaceCellTracing.cpp:12205-12238` `publish_phase_front_result` likewise does not receive the rails; the network call at `:18737` passes source faces, vertex count, and atlas only. The authoritative rail chain is therefore not available at the checked factory by the currently reviewed route.
- `src/geometry/SurfaceCellTracing.cpp:5820-5844` still reconstructs a source vertex from a floating barycentric near-one predicate. The previously archived rail patch avoids that fallback, but is intentionally unapplied because existing hand-authored fixtures omit exact chains.

**Decision needed:** choose an explicit producer-to-factory source-owned contact binding. Options include (A) pass the validated rail source-vertex chain/canonical contact ID through the checked boundary, or (B) publish and validate an A4 terminal-contact certificate authored from the pipeline's exact curve edges. Specify how the front endpoint, correct component/sheet, oriented incident source-star germ and A3 path bind without relying on raw-int namespace equality or geometric closeness. Keep reciprocal and ambiguous-contact negatives.

## Finding 2: a branch frame is not by itself the local +U gauge oracle

- `include/directional/authority/FieldTransportAtlas.h:728-734`: `FieldFaceBranchFrame` publishes a **vector of four** `FieldBranchBoundaryPairing` entries, not a distinguished phase-front +U branch.
- `src/authority/FieldTransportAtlas.cpp:255-314` produces all four canonical branch directions after calculating a private raw gauge. It does not publish which branch A4's independently selected local +U uses.
- `src/geometry/SurfaceCellTracing.cpp:11019-11056` determines the A4 planar face rotation by alignment with its selected frame axis; other region producers have separate root/transport gauges. The checked factory receives `sourceFaceBranchRotations` but not the original A4 frame axes or an independent +U-to-A3 pairing witness.
- `src/geometry/SurfaceCellTracing.cpp:8015-8023` currently performs an optional length/range check (empty accepted), not independent gauge attestation. `find_frame(face)` alone cannot distinguish four valid values. Do not implement a tautological check that the value belongs to `{0,1,2,3}` or compare it to the caller's own lattice branch.

**Decision needed:** define the independently checkable per-face +U frame witness / source-field branch association to be published into or supplied at the checked factory. Explicitly cover gauge-free products, nonempty untrusted gauges, row permutations, periodic/isolation transformations, source-face coverage and balanced tamper. If existing immutable cell/edge geometry suffices, provide a source-exact derivation and counterexample tests before coding.

## Non-blocked work already preserved

- Typed checked-factory rejection propagation compiled green.
- Two-face synthetic DCEL repairs compiled green; original seven negative tests have **not** been executed, so runtime restoration is unclaimed.
- Unapplied work-preservation patch `Directional_M6_R4_source-owned-rail-WIP.patch` remains in ChatGPT Library `/Directional/Evidence/`, SHA256 `1d9f73707ced3a74e3157f057380f425c66a4a9cd53b109e0556a20b4c1da37e`. It must not be applied without migrating the positive rail fixtures and preserving all negative first-failure oracles.
- The 497 frozen TB cases (and four supplemental RA-40(C) cases) are untouched; CP2 491/491 and R3 403/497 remain the frozen baseline, not newly measured.

## Stop / review handoff

Reopen independent source-authority review for the two missing bindings. Freeze the R4 Code + Build turn in place until the review specifies verifiable dataflow and test obligations. Do not mark R4 COMPLETE, do not start successor runtime/TB, do not mutate selector497, and do not conflate a successful compile with accepted semantic product behavior.
