# M3-CP4c-3-TB30-EXEC — artifact-only execution report

**Status:** EXEC COMPLETE / MECHANICALLY VALID / SEMANTIC REVIEW DEFERRED.

This record closes only the runtime-execution half of the frozen TB30 plan. It does not adjudicate product
failures, update regression classifications, promote the raw ledger to semantic authority, or authorize a corrective
Code + Build turn. The required successor is `M3-CP4c-3-TB30-REV`, which reviews this immutable evidence without
new runtime work.

## Immutable execution authority

- Run: `34008104497`; execute job: `101418934144`; both completed successfully at the orchestration level.
- Workflow event/source: `773e5a32daf8ee14e610f2c16cd81318a09f269c`.
- Immutable CB35 package: artifact `9980764888`, source `ab86747bdfdb94c7c383bf5d2893ced4207eb555`,
  provider/download SHA-256 `ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`.
- Packaged source archive SHA-256:
  `64801a38ccbe9de282dbec261cad6c2b6575403ed38e93b514c893c22f03684a`.
- Selector 408: 408 identities, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`; selector 407 is its exact prefix.
- Harness SHA-256: `e3768a3dd1089af27896abe18aa3e784a474bac1af86a63dcf4716b66f8cb822`.
- Result artifact `9981641004`, SHA-256
  `40f58d136073e08392701eafd189a4f6b45e1907a4381393ab3d4673cc6b2913`.
- Diagnostic-log artifact `9981641260`, SHA-256
  `dde276e2b448f9ba58b36dbe554bed7b7f4fa6ab2bff90df5ac15ee5af8cbd6d`.
- Ledger SHA-256: `974fed9db1958ee7eb07df77097544199deeb61d663b1d366a37b54d64feeab0`.
- Static identity-map SHA-256: `06c3a5a69078b4ce0dec23d29a9f96e10e0f6e94c42ea00675541c89a70d262a`.

The workflow caller was schema-validated before execution and then executed from the exact marker-trigger source above.
The immutable CB35 artifact's root `SHA256SUMS` verification passed **28/28**, its expected source identity and source
archive digest were checked before runtime, and its executable modes/bytes plus selector authority were verified
before any Directional process started.

## Mechanical execution checks

The result `execution-boundary.txt` records:

- `script_exit=0`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`;
- `execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`;
- `timeout_count=0`;
- `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`;
- `generated_discovery=false`, `package_repair=false`, `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`.

The ledger contains exactly **408 rows**, ordinals exactly 1–408. Every row records `selected=1`; there are no
selection mismatches and no timeout rows. Each identity ran once through the static owner map in a fresh process and
working directory as required by the frozen plan. The exactly-one owner distribution is 30 authority-kernel, 75
completion, 262 producer, and 41 validation identities.

Package, packaged-source, and execution-view byte+mode censuses are identical before and after runtime:

- package census SHA-256: `e020c1285bb869d8eb1eeb237abf3f49ca7019ce4dd875aca9811d22cdc8a800`;
- source census SHA-256: `69e17b69b512454472000d856548275df1253469dd4fb751b4f032416c30a613`;
- execution-view census SHA-256: `9f588ad6cc8788be93e6035fdee90a81495f22abba8714797ec419a344a56567`.

The runtime-executable census SHA-256 is
`9a3b7c3b1325acb69a771c1c7d9b4a6542527d2f2118920abcdfbb6b6be70813`; all six packaged runtime executables
retained mode `0755`. `directional_benchmarks` was censused but never executed. The resource-summary SHA-256 is
`266aea16be95a0abe1baabf56da3a85a5fb105e1878a0d11932db401614c4c50`.

## Raw ledger output — not yet semantically adjudicated

For review intake only, the harness mechanically emitted **401 PASS / 7 RED** with RED ordinals
`[366,367,368,369,370,374,398]`; raw accepted-prefix rows 1–365 contain **365 PASS** labels. Every row selected
exactly one test. The frozen credibility controls are mechanically present and labelled RED:

- 366 — `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- 367 — `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`;
- 398 — `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`.

The two corrected witness rows mechanically record **390 PASS** and **404 PASS**. Rows 406, 407, and 408 also
mechanically record PASS. Required raw logs were retained for 366,367,368,369,370,374,390,398,404,406,407,408;
390 emits `censusCorrespondence=none` with failing face-set digest `17919102493633069558`, while 406 retains the
distinct `EmptyFragmentOrbits` / `NotTraceCut` partition publication and 408 remains PASS.

**This raw 401/7 ledger is not semantic authority.** `M3-CP4c-3-TB30-REV` must compare the full ordinal vector
against TB29, apply the 366/367/398 credibility gate, adjudicate the 390/404 changes, classify every semantic
RED/change in `Regression_Root_Cause_Tracker.md`, and read the retained census before authorizing any later product
correction. Until REV completes, the latest accepted semantic runtime authority remains `M3-CP4c-3-TB29`: selector
408, **399 PASS / 9 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,390,398,404]`.

## Boundary and process notes

- No product, test, fixture, benchmark, build, selector, or reusable-workflow permission declaration changed.
- No compile, configure, relink, rebuild, repackage, generated discovery, benchmark executable, semantic retry, or
  package/mode repair ran in TB30-EXEC.
- `Regression_Root_Cause_Tracker.md` is intentionally unchanged in EXEC; the frozen TB30 plan assigns semantic
  diagnosis and regression classification to `M3-CP4c-3-TB30-REV`.
- Start-of-turn process-control deviation: repository handoff/policy reads occurred before the mandatory turn-local
  `READ_MODE` declaration. Source inspection then stopped, `READ_MODE=snapshot` was selected, and the verified
  source snapshot was used for substantive source/document work. This affected control-plane procedure only; no
  Directional runtime had started and no immutable package/source semantics were altered.
- A first local source-snapshot extraction used an incorrect `--strip-components=1` layout and therefore could not
  verify the snapshot's path-prefixed `SHA256SUMS`. The archive was re-extracted without stripping and all 5,220
  files verified. This was local evidence handling only and did not touch the runtime package.

## Exact successor

**`M3-CP4c-3-TB30-REV` — evidence-only review.** It must consume immutable result artifact `9981641004` and log
artifact `9981641260`, perform no new runtime, verify all 408 execution/provenance invariants, compare against TB29,
adjudicate 390/404 and the 366/367/398 credibility controls, classify every semantic RED/change in the regression
tracker, update `ORIENTATION.md`, perform mandatory review-turn document consolidation, and choose only an edge
authorized by the frozen TB30 plan.
