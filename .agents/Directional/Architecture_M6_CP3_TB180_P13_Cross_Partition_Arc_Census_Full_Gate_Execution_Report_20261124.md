# TB-EXEC-180 — cross-partition arc census full gate (2026-11-24 UTC)

## Situation

The immutable full gate passed 1,003 of 1,003 tests. All seven mechanical controls pass. Row786 is the only material change from TB179. This is execution evidence, not independent acceptance. Only `M6-CP3-TB-REV-180` follows.

## Background — exact authority

| Item | Evidence |
|---|---|
| Source and executor | `4c2b4cf16732cddb58252d5e758ea0b24449ed2a` |
| Compile | [CB-200 record](Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Code_Build_Record_20261124.md), GMP/GMPXX run `45351329597`, package `14901170173`, ZIP SHA-256 `8f4be71c9121cb0735ca07c1bc1dd83a66be20f4ab489b674a852dd122b6889f`, 28/28 checks |
| Package root manifest / source archive | `2699d635c1ffc298a73aa7468e885e05b535f821c92fe8b98e82d2d0ab6ab168` / `c039e9bfb527ff8ffef0f2b687e0ebb555200593da46fdcc2309ac016c14e88d` |
| Frozen case manifest | `gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`, SHA-256 `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`, 1003 cases |
| Deferred ledger | `gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv`, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 identities |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Request | `m6-cp3-tb180-exec`, event commit `c8740ffb8df810da9a1f440d0c311c925a5fe526`, request SHA-256 `c85a3a0356f07f66064c2b5a8477cf84af769dbf57d69c837299733097478d9f` |
| Runtime | [run 45457449013](https://github.com/akashskypatel/Directional/actions/runs/45457449013), job `138670947143`, wrapper 18:15:34Z–18:29:45Z, exit 0; both schema checks, parse and mailbox success. Compile, Drive apply and noop skipped. |
| Result | [14951803089](https://github.com/akashskypatel/Directional/actions/runs/45457449013/artifacts/14951803089), ZIP SHA-256 `67e784747b1c8d04bf781b69b486f3310876fde101b7935f0207fd2fd36a39f8`; 2014/2014 member hashes, root manifest SHA-256 `00d69a06641b6c0dade139d8e5d44fa87b8da04301d36558e4fd6d0f51fff75c` |
| Harness log | `14951863064`, ZIP SHA-256 `b22170cba95807e4afb66e6217e04f935ac149f39a0283952adc0d4c5d2e5fe3` |
| Wrapper log | `14951509916`, ZIP SHA-256 `2abf61f472e4f9aae32e5f5819f312ca6de0a4d31ec7cc674221eb6a5f2a49c6` |
| Mailbox | `workflow-mailbox:.workflow-mailbox/m6-cp3-tb180-exec/runs/45457449013-attempt-1.json`, success, reported 18:30:07Z |
| Baseline | [TB179 report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md), run `45338168889`, result `14895572803`, ZIP SHA-256 `aeaacb099ea7d51292706802ccf3a9a64702abf70575d01bd8c52847acb0c636`, 2014/2014 member hashes |

The result and log ZIP digests match the mailbox and artifact API. Both result archives have exact member inventories. All 1,003 raw-log hashes in each archive match their ledgers. The harness verifies the unchanged case manifest and deferred membership. Each case ran once. Postflight passed. There was no configure, compile, relink, repair, benchmark or fixture, selector, manifest, product or test mutation. The execution used the packaged binaries with their archived modes.

## Assessment — full comparison

| Check | Result |
|---|---|
| Verdict | 1003 PASS, 0 RED; 0 abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red, red_site_bad |
| Membership | 1003 gated + 81 deferred = 1084, identical to TB179 |
| Raw logs | 639 byte-identical, 363 N1/N2 only, 0 N3-only, one material change (786) |
| Complete `M3_CP4AB_FRAGMENT_DIAG` records | 1554 → 1554 across all rows; zero changed multisets |
| Ledger | Row786 RED → PASS; other rows unchanged except raw hashes |
| Mechanical controls | 445, 652, 653, 656, 658, 660, 786: all PASS |
| CP2 candidate | 491/491; accepted CP2 remains 491/491 |
| Row1003 / row979 | Both unchanged in substance. Row1003 PASS; row979 staged `RegionContainsInteriorSingularity`, vertex8, not production acceptance. |
| Comparison inventory / exact raw diff | SHA-256 `4bc6bdfff9671fdf9c360b7f200681ab163f5e59abff98f1e98ec1393bf437b2` / `1527cbedacdc30b8ddfcc82b2211b9b027efa3f3d6105ee219e9df2032680b68` (reconstruct from immutable raw logs) |

N1 permits GoogleTest elapsed times. N2 permits line endings. N3 permits only reordering complete counted fragment records. No assertion-line normalization is permitted. The old row786 failure at `FieldAlignedCurveNetworkTests.cpp:20101` is removed by the expected RED-to-PASS change. No candidate material record contains an assertion location. No other row changes in substance.

### Row786 — exact receipt

`SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions`, producer binary, exit 0. Raw SHA-256 `5d9b538105b5b84e1d2209cd3a164c8f951b56cdc239bb8ccbcab0226516a0e2`.

```text
m3Cp4c3PlanInteriorArcCensusCorruptions;certifierLabelErased=certifierLabel;certifierLabelWrong=certifierLabel;crossedFaceCount=arcFaceCount;duplicateFace=arcFaceDuplicate;planLabel=planLabel;reasonMissing=reason
m3Cp4c3PlanInteriorArcCensus;component=0;interiorArcs=2;truncated=false;correspondence=Superset
m3Cp4c3PlanInteriorArcFace;component=0;arcRow=0;faceRow=0;arc=19;sourceFace=36,38,39;certifierComponent=0;planComponent=absent;notTraceCutReason=TerminalSlit
m3Cp4c3PlanInteriorArcFace;component=0;arcRow=1;faceRow=0;arc=21;sourceFace=66,67,120;certifierComponent=0;planComponent=absent;notTraceCutReason=TerminalSlit
m3Cp4c3R8Receipt;ordinal=407;branch=UncutCensus;censusPredicateExecuted=yes;terminalSubjectRelation=NotApplicable;sameDomainCorruptionRejected=yes;terminalSubjectBranch=PlanFrontier;planFrontierEvidenceBranchExecuted=yes
```

The other eight printed crossed faces have absent labels in both partitions and `notTraceCutReason=none`. Each arc has five crossed faces. The new test derives each partition's membership independently. All six corruptions fail the expected invariant, not an unrelated condition. The observed terminal faces agree with M1 and M4 of the [adversarial review](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-180-folded-records--2026-11-24-utc). The test-local subject-intersection premise caused the last TB179 RED, not an additional observed production failure.

No new accepted-green loss or stable regression event occurred. Keep historical totals 67 events, 17 categories, 50 recurrences, witness debt1 and deferred81. TB170 recurrence disposition and candidate acceptance require independent Review. Accepted TB169 993/993 and CP2 491/491 remain unchanged until then. J6 is not exercised by the mechanical contact fixture. K6, row979, E5, Branch A and CB-190 remain held. No CP3/497/D0/H4 promotion.

## Recommendation

Only `M6-CP3-TB-REV-180` is next. Re-open both immutable result archives and exact CB-200 source. Independently re-derive all case and ledger comparisons, six corruption rejection checks and seven recovered controls. Decide TB170 recurrence closure and the new accepted baseline only if the evidence satisfies M1–M5. The Review is runtime-free. Do not start CB-201 or downstream work.
