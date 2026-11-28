# TB-EXEC-170 — corner-visit reader immutable full gate

## Situation

The immutable CB-189 artifact-only full gate recorded **986/993 PASS**. The comparison to TB169 found **21 unauthorized normalized row differences (rows 396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788, 857)** outside row 979. This report records the runtime observation, not independent acceptance or sphere production.

## Background

- Canonical turn `M6-CP3-TB-EXEC-170-P13-CORNER-VISIT-READER-FULL-GATE`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open, draft, unmerged.
- Frozen semantic source `178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7`; eight-target CB-189 compile [run 45113944225](https://github.com/akashskypatel/Directional/actions/runs/45113944225); artifact `14790917101`, ZIP SHA-256 `0432359393d37cf00b9654339c832263f648733237005171ff3a8eb9cfa1ddfd`, `runtimeExecution=false`, GNU Multiple Precision C/C++ linkage present.
- Frozen manifest `.agents/Directional/gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv`, SHA-256 `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`. Deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred).
- Executor SHA `8cd169210fee847bc608e87ee8af4d797983c64a`; harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Dispatcher event commit `21a01989b2d48e530f9891c3b1250a5c2818c21e`, mailbox `m6-cp3-tb170-corner-visit-reader-full-gate` on orphan `workflow-mailbox`.
- Execution [run 45118730914](https://github.com/akashskypatel/Directional/actions/runs/45118730914), immutable result artifact `14793023424`, outer ZIP SHA-256 `930a4a42cd5f15c1479fd0ba098ff21e5860d5fbcf37520e2c1d7bb5ca652d55`. Baseline: TB169 [run 45104059492](https://github.com/akashskypatel/Directional/actions/runs/45104059492), artifact `14787082075`, ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`.

## Assessment — recorded evidence

- Test state: **986/993 PASS**. CP2 accepted prefix **490/491**. Membership **1074 = 993 selected + 81 deferred**. Full internal result hashes: TB169 **1994/1994**, TB170 **1994/1994**, no incorrect hashes.
- Comparator applies exactly N1 Google Test durations, N2 line endings, and N3 whole-record unordered `M3_CP4AB_FRAGMENT_DIAG` equality. Non-979 normalized differences: **21**; N3 complete record counts baseline/candidate **1750/1450**. Raw byte changes before normalization: **225** rows. Any unexpected row details: `[396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788, 857]`.
- Row **652 RED** with a test-body C++ exception: `NotProductionReady/global-topology-plan/SourceFaceCutPartitionFailed`, source face `(1,4,139)`. Row 656 throws the same typed failure. Five more controls fail because the mechanical-feature plan is absent: rows 445, 653, 658, 660 and 786. **Do not treat the row 652 fail as a passing baseline.** Row 979 test/metadata outcome is separately measured, not preapproved. row979 staged result: `SphereStagedPlan outcome=RegionContainsInteriorSingularity sourceFace=- sourceEdge=- trace=- secondTrace=- chi=- V=- E=- F=- fragmentOrbits=- tracePieces=- expectedFragments=-` N3 whole records on row979 equal: `True`. Row979 has no automatic semantic promotion.
- Published execution boundary is exact package/source and `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, **exit 90** (`required controls failed`) with **postflight true**; no test, selector, build, fixture or source edit was made inside the runtime gate. No production census was run.
- Independent comparison overall frozen gate checks: **VIOLATION**. Failed control rows: **445, 652, 653, 656, 658, 660, 786**. Non-979 changed normalized rows: **[396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788, 857]**. N3 record deficit: **300**. Row979 is PASS as a single test but reveals a *new typed stage*, `RegionContainsInteriorSingularity`, at source vertex 8 (region certification); this is not a completed staged plan. Full validator evidence: 1994/1994 hashes; no skipped/missing tests; result exit 90. This is evidence collected by the TB agent and **not** the separate TB-REV-170 independent review.


## Seven failed controls — exact identities

| Row | Test | Observation |
|---|---|---|
| 445 | `RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b` | Missing mechanical topology plan; `NotProductionReady` |
| 652 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | C++ exception, `SourceFaceCutPartitionFailed` on face `(1,4,139)` |
| 653 | `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` | Missing mechanical topology plan; `NotProductionReady` |
| 656 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | C++ exception, `SourceFaceCutPartitionFailed` on face `(1,4,139)` |
| 658 | `GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent` | Missing mechanical topology plan; `NotProductionReady` |
| 660 | `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` | Missing mechanical topology plan; `NotProductionReady` |
| 786 | `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` | Missing mechanical topology plan; `NotProductionReady` |

The 14 other changed rows remain PASS but are **not equivalent** to TB169 under N1–N3. In aggregate 300 complete N3 records disappeared, and row 669 moves a non-N3 line. No root-cause change is approved within this Test + Benchmark turn.

## Regression and acceptance limits

CANDIDATE REGRESSION: seven baseline-PASS controls now RED (rows 445, 652, 653, 656, 658, 660, 786), all in the mechanical-feature topology-plan family. The first reported typed source failure is SourceFaceCutPartitionFailed on face (1,4,139); row 652 and 656 throw an exception, while the five others fail a plan-presence assertion. An additional 14 non-979 rows changed despite a PASS verdict, largely because 300 complete M3_CP4AB_FRAGMENT_DIAG records disappeared; row 669 also changes non-N3 line order. A CB-189 corner-reader interaction is a plausible source, but the exact per-piece cause is not yet proved. Independent TB-REV-170 must determine the stable-event classification; the historical 66/17/49 accounting is not updated on this test evidence alone. Stable **66 events / 17 categories / 49 recurrences**, one witness debt, 81 deferred are preserved as inherited records, not independently reclassified. Production sphere remains unaccepted at last measured `CutSearchExhaustedBeforeCellularity`; no representative sphere production test ran here. The staged row979 outcome is not a production result. CP3/497/D0/H4 and production activation remain held.

## Recommendation

Next only `M6-CP3-TB-REV-170-P13-CORNER-VISIT-READER-FULL-GATE` (separate independent Review turn): re-open both immutable artifacts, check N1–N3, classify the row979 typed result and any off-row change, then determine the authorized later plan. Do not begin that review, an activation/code turn or a production census inside TB170.
