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


## Resume attempt 2026-10-06T04:43:18Z

This section supersedes the stale operational statements above while preserving the earlier checkpoint history.

- Exact resumed inspection snapshot: source/event `23a4663f840d05a5143515dd368a5562d70be234`, run `37415091265`, artifact `11391011990`, provider digest `sha256:0ae7835e3738491d21696faa92522317c877fbb2d506d1ca269d878234d90aca`.
- G3 was completed locally without adding or renaming identities:
  - identity 3 now contains a constructible `a6:edge-manifoldness` witness;
  - identity 5 is a ten-row table matching the frozen §6.3 forbidden classes to an exact runtime witness or compile-time API-shape proof.
- Static pre-apply verification passed: `git diff --check`, exact-base `git apply --check`, and all four frozen selector/routing hashes remained byte-identical.
- Final patch authority:
  - base `23a4663f840d05a5143515dd368a5562d70be234`
  - full SHA-256 `959ab4f3d2f502324369f80eda5b8392402fed9fdbdf15edd99e3367d44e605b`
  - diff-body SHA-256 `5b2d46f026f63ecc3daa7bc29f9e95990e777cfbf32a1f1619714ca881d5d0b9`
  - intended paths remain the same three production/test files listed above.
- Patch apply workflow `37415698207` passed schema validation and exact Drive/base/path/hash verification, pushed semantic commit `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, and recorded `runtimeExecution=false`.
- Both the final applied Drive patch and the superseded WIP Drive patch were permanently retired through the owner-authorized Drive control plane after the successful push.
- The temporary patch-apply caller/marker and resumed source-snapshot marker were retired in workflow-first order.
- Mandatory compile/package is now active through temporary caller `.github/workflows/m6-cp2-cb2-coverage-compile.yml`, marker `.agents/connector-triggers/m6-cp2-cb2-coverage-compile.txt`, exact semantic source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, and the standard eight GMP/GMPXX targets.
- At this checkpoint the compile mailbox `.workflow-mailbox/m6-cp2-cb2-coverage-compile/latest.json` has not yet published. Do not retrigger. Resume by reading that mailbox first; if terminal, collect jobs/artifacts/log evidence once.

Remaining completion work is therefore bounded to: verify the compile/package evidence; write the G4 Code + Build report with the frozen §6.2/§6.3 predicate/witness table; update durable handoff/TODO/change records as required; clean the temporary compile caller before its marker; then either close to `M6-CP2-TB2-COVERAGE-EXEC` on compile-green evidence or keep this turn `IN_PROGRESS`.
