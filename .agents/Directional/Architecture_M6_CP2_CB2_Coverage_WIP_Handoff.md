# M6-CP2-CB2-COVERAGE WIP handoff

Turn remains **IN_PROGRESS**. This record exists because the bounded-response timer requires closeout before the Code + Build turn is complete.

## Authority and preserved work

- Turn: `M6-CP2-CB2-COVERAGE`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- PR: #8, open/draft
- Exact inspection snapshot source: `a5f203ab25cbbf7ee1409076c78a184e0e5153b7`
- Snapshot workflow/run: `Agent Source Snapshot / 37413126486`
- Snapshot artifact: `11389394786`, provider digest `sha256:74e6bc3f85de9d61ffa7d1d0170313c728e2e9eae65a1bf315b1eac86482edb8`
- Snapshot metadata: 5,482 files, `runtimeExecution=false`, source/archive verification passed.
- WIP patch full SHA-256: `15276109d6826e50aef052d85f01b97586936855f044f274923b519b4498124b`
- WIP patch diff-body SHA-256: `be5fc594532678bef402d860b39250b4e3104a00955226c528e112c25844b555`
- Patch base SHA: `a5f203ab25cbbf7ee1409076c78a184e0e5153b7`
- Intended paths:
  - `include/directional/pipeline/RemeshPipeline.h`
  - `src/pipeline/RemeshPipeline.cpp`
  - `tests/SurfaceCellTransitionQuotientTests.cpp`
- Google Drive staging file ID: `1moIorJGBUYsXSaQJXi7jA41pyXY4kkCW`
- Drive title: `M6-CP2-CB2-COVERAGE-WIP.patch`

The exact patch was generated from the verified snapshot, passed `git diff --check`, and passed `git apply --check` against a fresh extraction of that exact snapshot. It has **not** been applied to the branch yet.

## Implemented locally in the preserved patch

1. Removed dead `VerificationFailureCode::UncertifiedAuthoritySubstitution` and its name-table entry.
2. Split independent A7 certificate comparisons for recomputed connected-component count, boundary-loop count, and Euler characteristic into `BoundaryOrEulerMismatch` findings at:
   - `a6:components`
   - `a6:boundary-loops`
   - `a6:euler`
3. Added exact A7 vertex-binding verification at `a7:vertex-binding` requiring:
   - representative membership in the A6 quotient class;
   - exact face/barycentric/position equality with the published representative occurrence point;
   - exact embedded-position equality with `sourcePoint.position`;
   - support equality with the class support certificate.
4. Strengthened existing frozen identities without adding test identities:
   - identity 2: hard-feature-edge, corner-owner, directed-side-cycle, wedge-isolation witnesses;
   - identity 3: exact-once-ledger, duplicate-certificate, forest-joining-set, forest-cardinality, components/boundary/euler witnesses;
   - identity 4: all four G1 vertex-binding tamper classes plus support-cover, topology-copy, certificate:a5 and certificate:a6 witnesses.

## Still required before this turn can be COMPLETE

1. Finish G3 identity 5 as the required table-driven ten-row §6.3 coverage map, including exact runtime code/site or compile-time API-shape classification for every forbidden class.
2. Finish any missing identity-3 coverage, especially the `a6:edge-manifoldness` row or explicitly justify/classify non-constructibility from verification records.
3. Recheck all newly added witness assertions against the intended exact code/site; no generated Directional binary has been executed in this turn.
4. Produce G4 Code + Build report mapping every frozen §6.2 recompute category and every §6.3 class to production predicate + witness/API-shape evidence.
5. Perform frozen target hash checks for focused-30, focused-12, selector449 and routing449.
6. Re-materialize the final complete patch from the current branch authority before remote apply if branch control-plane commits changed the patch base. Do not silently reuse the current WIP patch as final authority.
7. Apply the completed non-minor patch through the standard Google Drive patch workflow, then retire the staged Drive file after successful push.
8. Run the mandatory reusable GMP/GMPXX compile/package workflow over the standard eight targets with `runtimeExecution=false`. No runtime execution is authorized in this turn.
9. Write the CB report and durable handoff only after compile evidence is verified. Compile-green successor remains `M6-CP2-TB2-COVERAGE-EXEC`; otherwise resume this same turn.

## Stop-rule notes

- No producer A5/A6/A7 semantics were intentionally changed.
- No `SurfaceMeshOptimizer` change was made.
- No test identity was added or renamed.
- No local build/test/runtime command was executed.
