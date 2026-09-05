# M3-CP4c-3-TB28-R3-EXEC — artifact-only execution report

**Status:** EXEC COMPLETE / MECHANICALLY VALID / SEMANTIC REVIEW DEFERRED.

This record closes only the runtime-execution half of the frozen TB28-R3 plan. It does not adjudicate product
failures, update regression classifications, discharge candidates, or authorize CB34. The required successor is
`M3-CP4c-3-TB28-R3-REV`, which reviews this immutable evidence without new runtime work.

## Immutable execution authority

- Run: `33995961030`; execute job: `101386467115`; both completed successfully at the orchestration level.
- Workflow event/source: `811eaba5f3216f368923f588efe37a6f8629da41`.
- Immutable CB32 package: artifact `9975737868`, source `098ac7d93ea203222dd0ac50cdb68667744f0fd4`,
  provider/download SHA-256 `16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`.
- Selector 407: 407 identities, LF SHA-256
  `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`.
- Harness SHA-256: `b3191b314afa22f72e6f720519cfa2f8ad090dce3de5617612ad64c195489fbf`.
- Result artifact `9978114313`, SHA-256
  `98163e9e512223136df8feaa6192a29bc9ede8a17f9784ba4fd17946754f9b54`.
- Diagnostic-log artifact `9978114502`, SHA-256
  `bad7431f68be53da770069ad48cabb0033ffeb02a2dde94c6a06ba8b47e9a994`.
- Ledger SHA-256: `fa0626b8a28c0f2758e68e2be712fff024197e445be46e46c9491395cc0609ac`.
- Static identity-map SHA-256: `9e726c011f884da55877e6bbca420be530f05325263eddcd86993c1f0a54d3fd`.

TB28-R1 `33990315861` and TB28-R2 `33990951740` remain explicitly preserved as orchestration-invalid attempts with
no semantic credit.

## Mechanical execution checks

The packaged `execution-boundary.txt` records:

- `script_exit=0`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`;
- `execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`;
- `timeout_count=0`;
- `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`;
- `generated_discovery=false`, `package_repair=false`, `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`.

The ledger contains exactly **407 rows**. Every row records `selected=1`; there are no selection mismatches, no
exit-124 timeout rows, and there are exactly 407 raw per-identity logs plus 407 resource records. Each identity ran
through the static owner map in a fresh process as required by the frozen plan.

Package, packaged-source, and execution-view byte+mode censuses are identical before and after runtime:

- package census SHA-256: `42489ff6c1791fefc0226a4a660694740892daa425efc407f6d9cda6252c2629`;
- source census SHA-256: `1bb47b368700a84cc68aa06a4c2cffbea8f431e2ab0421efdabcd83368d78c21`;
- execution-view census SHA-256: `e41f8d231fea25f026a2e1f41c6d0ba6e4de5fd1522606b5cec42ed203846439`.

The package root `SHA256SUMS` verification passed for all packaged executables, libraries, metadata, and source
archive. No package mode repair or byte mutation occurred.

## Raw ledger output — not yet semantically adjudicated

For review intake only, the harness mechanically emitted **400 PASS / 7 RED** with RED ordinals
`[366,367,368,369,370,374,398]`; the raw accepted-prefix rows 1–365 contain 365 PASS labels. The three frozen
control rows are mechanically present and labelled RED:

- 366 — `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- 367 — `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`;
- 398 — `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`.

Ordinals 404, 406, and 407 are mechanically labelled PASS. **EXEC does not apply the semantic credibility gate or
promote this ledger to runtime authority.** Those decisions, the accepted-prefix statement, all regression/root-cause
classification, candidate disposition, and the 191-face ownership-census assessment belong exclusively to
`M3-CP4c-3-TB28-R3-REV` under section 7 of the frozen plan.

Until REV completes, the latest accepted semantic runtime authority remains TB27-R1 at **399 PASS / 7 RED**,
accepted **365/365** on selector406.

## Boundary and process notes

- No product, test, fixture, benchmark, build, selector, or reusable-workflow permission declaration changed.
- No compile, configure, relink, rebuild, repackage, generated discovery, benchmark executable, or semantic retry ran.
- `Regression_Root_Cause_Tracker.md` is intentionally unchanged in EXEC; the plan assigns complete regression
  classification to R3-REV.
- Start-of-turn conservation miss: after `READ_MODE=snapshot` was selected, one three-line direct handoff read and
  two redundant marker-patch inspections occurred before the source snapshot was materialized. Further piecemeal
  source inspection stopped; the verified snapshot was used for all substantive source/document inspection. This
  did not affect runtime bytes or semantic evidence.

## Exact successor

**`M3-CP4c-3-TB28-R3-REV` — evidence-only review.** It must consume the immutable result/log artifacts above,
perform no runtime execution, apply the 366/367/398 credibility gate, classify all observed regressions, assess the
191-face source-face-ownership publication, and decide only whether the already-frozen CM9 sequence may proceed to
CB34 or whether the harness must be replaced. The frozen separating-arc barrier correction may not be re-opened.
