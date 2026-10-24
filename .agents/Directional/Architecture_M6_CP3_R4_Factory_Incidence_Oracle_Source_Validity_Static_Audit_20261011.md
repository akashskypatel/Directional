# M6-CP3-CB1-ENTRY-R4 — hard-rail incidence oracle and frozen DCEL fixture source-validity audit

**Status:** Static source audit only, **not** a normative definition or runtime Test + Benchmark. Canonical R4 remains `IN_PROGRESS`, successor `UNKNOWN`. No source/test executable run; no accept/reject result is inferred.

## Exact evidence

- Verified snapshot workflow [`38154965590`](https://github.com/akashskypatel/Directional/actions/runs/38154965590), job `114515978657`, event/source `57540deb13da2eb14bea9352f28670160026e780`, artifact `11708521074`, ZIP SHA-256 `ead51d98ff2a436c237067a22d2fa209e82297426ee36fd5e1e200fe236ccea5`.
- Inner `source.tar.gz` SHA-256 `923d97f6a3408a7fb6a13fed5f2f60dbbee060516d25025214370dd077278d70`; complete `SHA256SUMS` **6207/6207** entries pass, snapshot metadata `runtimeExecution=false`.
- Frozen historical first-failure source: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`; current source is after multiple compile-only fixture repairs. No current R4 runtime failure evidence is available.

## Specific uncovered risk: three-face rail-incidence oracle is potentially vacuous

`tests/SurfaceCellTransitionQuotientTests.cpp`, `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`, builds `attempt(count, reverseRows, publishTransition, absentRail)` and asserts a typed `InvalidSourceAuthority` result for `count=3`. All three synthetic triangles share the hard edge `{0,1}`. The fixture constructs `TriMesh` and `FieldTransportAtlas::make` from that three-incidence source. The factory invocation permits `sourceAtlas ? &sourceAtlas.value() : nullptr`, and the test expects `InvalidSourceAuthority` for `count=3` regardless of why that result occurs.

**Independent product code:** `SurfacePhaseFrontProduct::make` (`src/geometry/SurfaceCellTracing.cpp`, starting near line 8045) rejects a null A3 atlas and any A3/source mismatch **before** counting incidences; the actual `railIncidenceCounts` overfull-edge guard is later, around lines 8155–8187. Therefore, if the nonmanifold three-face atlas cannot be constructed, the test's expected enum may still pass at the *wrong first predicate*. If `TriMesh::set_mesh` throws for this nonmanifold source, the body instead fails before the checked factory. Neither outcome has been observed; this is a static oracle soundness risk, **not** a proven runtime failure.

**Non-vacuity requirement:** To count as a regression for the checked-factory >2 rail-incidence guard, the fixture must prove non-null exact source-bound A3 and a positive comparison that reaches the incidence gate. If the accepted two-manifold source/A3 contract makes that witness unrealizable, request an independent Definition/Review ruling and retain a separate producer-side nonmanifold-source negative. Do **not** treat an `InvalidSourceAuthority` enum produced by the earlier null/mismatched-A3 gate as proof that the later overfull-incidence guard was exercised. Do not fabricate a nonmanifold atlas or remove A3 matching to make this test pass.

## Seven frozen R3 DCEL cases — current source inventory, not acceptance

Frozen RED ordinals **40, 220, 221, 296, 302, 304, 439** had `DCEL_FIXTURE_CONSISTENCY_EXCEPTION` in the rejected R3 run, including `compute_edge_quantities(): DCEL consistency check failed`.

- Ordinal **40**, `FlowRepStrandsPhase15.RailTruncatedGenericSupportDoesNotInheritLaterTerminalAnchor` in `tests/FlowRepStrandsPhase15Tests.cpp` around line 1448, now supplies two consistently oriented faces `(0,1,2)` and `(0,2,3)` to `attach_source_authority` (four vertices; face 0 geometry retained).
- Ordinals **220, 221, 296, 302, 304, 439** in `tests/SurfaceCellTransitionQuotientTests.cpp` share `direct_periodic_owner_fixture` (around line 244). This now builds a two-triangle source disk `(0,1,2)` and `(0,2,3)`, `SourceTopologyRegions`, independent `FieldTransportAtlas::make`, and a checked `SurfacePhaseFrontProduct`. The named negative tests subsequently mutate relation-owner/order/identity evidence; their frozen identities and expected error codes remain.

A static topology check finds the shared diagonal `(0,2)` has exactly two opposite-oriented incidences and boundary edges one each in both fixture source disks. This removes the obvious one-face or inconsistent-winding preflight weakness, but **does not prove** DCEL runtime construction, the checked factory's positive preflight for every case, or the intended first negative rejection. Earlier source fixture corrections compiled GREEN; no frozen 497-case execution is authorized in current Code + Build. Leave all **seven** RED obligations open pending a separate source-exact, artifact-only Test + Benchmark turn.

## Targeted corrective work, without premature acceptance

1. Design/review the three-face A3 feasibility condition. If feasible, add an independently constructed exact source A3 and assert non-null/source matching **before** crediting overfull-incidence rejection; if impossible under manifold A3, split the nonmanifold producer negative from A4 checked factory tests without weakening either contract.
2. At the next *authorized* artifact-only runtime checkpoint, record whether the seven frozen DCEL identities still throw or now reach intended typed guards. For any changed first rejection, diagnose exact test fixture and factory independently. Do not mark a pass from these static observations.
3. Preserve historic accepted CP2 `491/491`, rejected R3 `403/497`/`94 RED`/`88 previously accepted losses`, and the untouched R4 39 endpoint / 34 Phase10 / six CP3 / genuine multi-carrier odd-τ / independent terminal two-path review obligations. Do not execute tests, discovery, CLI or benchmarks in this Code + Build turn; do not authorize its successor based on this audit.
