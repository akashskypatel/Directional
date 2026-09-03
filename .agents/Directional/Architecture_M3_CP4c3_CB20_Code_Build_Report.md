# M3 CP4c-3 CB20 — Code + Build Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-CB20`
Status: **COMPLETE / DIAGNOSTIC-ONLY / COMPILE GREEN / RUNTIME NOT EXECUTED**

## Authority

CB20 implements the diagnostic-only successor frozen by `M3-CP4c-3-TB17-REV` §10 (`BS0–BS9`). It does not alter the fragment-count invariant or any topology semantics.

- semantic source / evidence commit: **`57635e87306a416daabb8321e1f36fa9c788d208`**;
- parent semantic authority: `ae30c183c0b876a093cd1bbbd673f8e6cbd52f67`;
- selector 382 SHA-256: **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`** — byte-identical;
- selector 383 SHA-256: **`a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`** — selector 382 as an exact 382-line prefix plus one appended identity;
- appended identity: `GlobalTopologyPlan.TraceCutFaceFragmentMismatchDiagnosticsSurviveProductionFailureProjection`;
- authoritative compile run/job: **`33780005014 / 100731152066`**;
- compile result artifact: **`9903305256`**, digest **`sha256:06def1b690bf63391520392da9381088c2bf6529138b6e9f44816bf06996563a`**;
- compile activity-log artifact: **`9903306009`**, digest **`sha256:f99eb8978f4eb2f014d4d1ca39ecd03e9c885f16d3621d821e7147044b63b8ec`**;
- runtimeExecution: **false**.

## Implemented diagnostic surface

### Typed fragment mismatch evidence

`TraceCutFaceFragmentCountMismatch` now retains and projects the quantities already computed at the failing face:

- actual fragment-orbit owner count (`fragmentOrbitCount`);
- `tracePieceCount`;
- expected local fragment count (`expectedFragmentCount = tracePieceCount + 1`);
- a bounded list of real-chord incidences, with an explicit total count and truncation flag;
- bounded edge-orbit evidence for the failing face's three edges.

Each retained chord incidence carries trace id, arc id, segment index, orientation, incoming/outgoing carriers, forward/reverse face-walk orbit ids, and whether each orbit is removed by the existing `exteriorOrbits` filter. This is evidence only: it does not change the existing filter or any orbit assignment.

### Failing-path reconciliation record

The existing `M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation` record is emitted for the failing face before the existing early return when diagnostics are enabled. The all-faces post-success diagnostic remains intact.

### Production failure projection

A single diagnostic-only projection helper now maps `GlobalTopologyPlanError` into the production `RemeshDiagnostics` topology locus. The existing failure path uses this helper, so the new fields survive the production failure envelope without changing the error reason, comparison, or control flow.

### Compiled witness

`GlobalTopologyPlan.TraceCutFaceFragmentMismatchDiagnosticsSurviveProductionFailureProjection` constructs a typed mismatch error and pins every newly projected field plus the rendered production tokens. Its regression half verifies that the historical source-face-only projection of an unrelated `InvalidSourceBinding` error is byte-identical.

## BS0–BS9 disposition

| Measure | Disposition |
|---|---|
| **BS0** | PASS by construction/build: accepted 365 untouched; selector 382 exact hash retained; all eight required targets compiled with GMP/GMPXX; no runtime. |
| **BS1** | PASS: actual, expected and `tracePieceCount` retained and projected. |
| **BS2** | PASS: bounded per-chord incidence with trace/arc/segment/orientation, carriers, both orbit ids and exterior-drop flags; explicit total/truncation. |
| **BS3** | PASS: bounded three-edge orbit evidence retained on the failing face. |
| **BS4** | PASS: `fragment_reconciliation` reaches the failing path; all-faces version remains. |
| **BS5** | PASS at compile boundary: typed projection witness covers every new field and a byte-identical unrelated-locus regression. Runtime execution is deferred to TB18. |
| **BS6** | PASS: selector 383 is only selector 382 plus the single compiled witness. |
| **BS7** | PASS by diff audit: no semantic change to the comparison, `tracePieceCount`, orbit insertion/filtering, terminal-slit classification, carrier-less binding, fragment incidence construction, region construction, fixture tolerances, or inherited corrections. |
| **BS8** | PASS by construction: added state is observational; no count, orbit, region, plan or accepted identity semantics are mutated. TB18 must still runtime-confirm 365/365. |
| **BS9** | FROZEN FOR TB18: the six runtime discriminators are published in `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md`. |

## Compile evidence

The exact pushed semantic source `57635e87306a416daabb8321e1f36fa9c788d208` was configured Release/static/PRE_TEST with `DIRECTIONAL_ENABLE_GMP=ON`, `GMP_ROOT=/usr`, and the durable compile workflow's explicit GMP/GMPXX configure/link checks. The following exact target set compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The compile artifact contains the exact source archive, compiled test/benchmark binaries, static libraries, configure/build logs, GMP evidence, target manifest, and SHA-256 manifest. No generated Directional binary, GoogleTest identity, benchmark, discovery command, `ctest`, CLI, help/version command, or custom runtime input was executed.

## Exact successor

**`M3-CP4c-3-TB18` — artifact-only Test + Benchmark.** Execute only the frozen plan in `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md` against the exact CB20 compile artifact. Do not rebuild or repair it. A semantic correction remains prohibited until TB18 publishes the mismatch direction and contributing incidence and the successor review adjudicates them.
