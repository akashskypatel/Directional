# M3-CP4c-3-TB29-EXEC — artifact-only execution report

**Status:** EXEC COMPLETE / MECHANICALLY VALID / SEMANTIC REVIEW DEFERRED.

This record closes only the runtime-execution half of the frozen TB29 plan. It does not adjudicate product
failures, update regression classifications, promote the raw ledger to semantic authority, or authorize a corrective
Code + Build turn. The required successor is `M3-CP4c-3-TB29-REV`, which reviews this immutable evidence without
new runtime work.

## Immutable execution authority

- Run: `34002726062`; execute job: `101404386206`; both completed successfully at the orchestration level.
- Workflow event/source: `9d59e21f812c24417bff3f55f8ffb1188e2f4835`.
- Immutable CB34 package: artifact `9979639398`, source `25ab3d55697598bde436d1ac811d71e6cf911f2e`,
  provider/download SHA-256 `c7e35682b9d38b8e8b7916e6030cc2bd3fd4172d0dfc49be83d09a4b0a45ecf2`.
- Packaged source archive SHA-256:
  `187d75cc76a4664c5fd2486b7e6b1b9bae5d7fe0a0e2a5d9be54c73a0885ff5e`.
- Selector 408: 408 identities, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`; selector 407 is its exact prefix.
- Harness SHA-256: `80b6805864899284ed555258db098ccc8ae3841f5669c4c3a6b74db3421574ca`.
- Result artifact `9980019423`, SHA-256
  `98a1133686638493256abd12fb7a7c114d04a3881eee533d7629a35defd0bd5e`.
- Diagnostic-log artifact `9980019636`, SHA-256
  `23baf1355bc0217edfa8941cf299c2060646cc854caef86fff182f8aa552cf29`.
- Ledger SHA-256: `3199d7117dbed28dd23dd22cefb543ff43f449a5a2aa859075f543a8f6195f51`.
- Static identity-map SHA-256: `06c3a5a69078b4ce0dec23d29a9f96e10e0f6e94c42ea00675541c89a70d262a`.

The workflow caller was schema-validated before execution and then executed from the exact marker-trigger source above.
The immutable CB34 artifact's root `SHA256SUMS` verification passed **28/28**, and its packaged source, GMP/GMPXX
metadata, executable bytes/modes, and selector authority were verified before any Directional process started.

## Mechanical execution checks

The packaged `execution-boundary.txt` records:

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

- package census SHA-256: `a49d3cff2561009780b46acded9ba249eaba9dfb634d80045469f68fbbf46eb5`;
- source census SHA-256: `b6ac056687bd4e2d5d3cc68bf55b4f0638f36d4bff1cd95ace6534c603f5d14e`;
- execution-view census SHA-256: `97b45089e4212be6811e02c04c999ba69b94d49e3cea98b3b8b17a4cbcbfec46`.

The runtime-executable census SHA-256 is
`4b0b9b04e334ee6a430bd6815cd0536cd22933c679597c73a702cfcf54cbf119`; all six packaged runtime executables
retained mode `0755`. The resource-summary SHA-256 is
`07d3dd048d62ef1e604239888d34d7582452c838b00e346e7430f3516a3006b6`.

## Raw ledger output — not yet semantically adjudicated

For review intake only, the harness mechanically emitted **399 PASS / 9 RED** with RED ordinals
`[366,367,368,369,370,374,390,398,404]`; raw accepted-prefix rows 1–365 contain **365 PASS** labels. The frozen
credibility controls are mechanically present and labelled RED:

- 366 — `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- 367 — `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`;
- 398 — `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`.

The required publication rows mechanically record 404 RED and 406/407/408 PASS. In particular, ordinal 408 —
`SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus` — selected exactly one test and
returned process exit 0. EXEC makes no semantic claim from those labels.

**This raw 399/9 ledger is not semantic authority.** `M3-CP4c-3-TB29-REV` must apply the frozen credibility gate,
adjudicate every observed RED including ordinals 390 and 404, assess the required ownership/census evidence, update
`Regression_Root_Cause_Tracker.md`, and determine the authorized next edge. Until REV completes, the latest accepted
semantic runtime authority remains `M3-CP4c-3-TB28-R3`: selector 407, **400 PASS / 7 RED**, accepted **365/365**,
RED `[366,367,368,369,370,374,398]`.

## Boundary and process notes

- No product, test, fixture, benchmark, build, selector, or reusable-workflow permission declaration changed.
- No compile, configure, relink, rebuild, repackage, generated discovery, benchmark executable, semantic retry, or
  repair ran in TB29-EXEC.
- `Regression_Root_Cause_Tracker.md` is intentionally unchanged in EXEC; the frozen plan assigns semantic diagnosis
  and regression classification to `M3-CP4c-3-TB29-REV`.
- Before runtime, static materialization found that two harness replacement anchors had multiple expected
  occurrences. Only the temporary orchestration materializer was corrected and re-schema-validated; no Directional
  runtime had started, and no product/test/fixture/selector/harness-semantic bytes were changed.
- Start-of-turn process-control note: the handoff was fetched before mandatory read-mode selection. Source inspection
  then stopped, `READ_MODE=snapshot` was selected, and the verified source snapshot was used for all substantive
  source/document work. This affected control-plane procedure only, not runtime or semantic evidence.

## Exact successor

**`M3-CP4c-3-TB29-REV` — evidence-only review.** It must consume the immutable result/log artifacts above, perform
no new runtime, apply the 366/367/398 credibility gate, adjudicate the raw ledger and accepted-prefix state, classify
every observed regression in `Regression_Root_Cause_Tracker.md`, assess the required source-face ownership and
uncut-component publication evidence, update `ORIENTATION.md`, perform mandatory review-turn document
consolidation, and choose only an edge authorized by the frozen TB29 plan.
