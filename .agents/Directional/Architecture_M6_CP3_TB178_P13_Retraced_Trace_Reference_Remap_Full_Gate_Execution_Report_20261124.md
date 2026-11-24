# TB-EXEC-178 — retraced trace reference remap full gate (2026-11-24 UTC)

## Situation

**Execution complete; product gate rejected; frozen comparison satisfied.** All 1,002 cases ran: 995 PASS and seven existing RED. New guard row 1002 passed. No inherited case changed outside the permitted comparison rules. The seven failures prevent product acceptance. Only `M6-CP3-TB-REV-178` is authorized next, in a separate turn.

## Background — exact execution authority

| Item | Evidence |
|---|---|
| Semantic source and executor | `de65101eb04c73e08ea4b6b31968975f71d9d909` |
| Compile-only GMP/GMPXX package | [CB-199A record](Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Code_Build_Record_20261124.md), artifact `14883418907`, ZIP SHA-256 `8452d0bbfad23c464c7ad29de2c9b92a4acde9bdbb96347a55aeb84917ef8beb`, 28/28 member checks |
| Package root manifest and source archive | SHA-256 `32a46319cff53f42c3ca6b938227cc8fdee0a304adf03d3c008d38d10c52f7e9` and `fab1353b6bdf5c4f5a057dc1aa3996353f5257ace2c738df4c5caee0d164b4bd` |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Frozen manifest | `gates/Architecture_M6_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Case_Manifest.tsv`, SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed`; first 1,001 rows SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642` |
| Deferred ledger | `gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv`, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Dispatch | `m6-cp3-tb178-exec`; event SHA `b82135677aec6819469cc31d2ce2b9fde45e59ca`; request SHA-256 `9ae8aed9a2e3682f4ec24430d88627a8b386cddc846492d56c8553224ee3f9af` |
| Runtime | [run 45314763603](https://github.com/akashskypatel/Directional/actions/runs/45314763603), job `138178987202`; schema validation and parser PASS; runtime failed with exit 90; mailbox publication PASS |
| Result | Artifact `14885616510`, ZIP SHA-256 `57260ad2ee62adb02bad56bc09d2ab7e2c4782b8ad4ef43faa76cb5e539600a6`, 2012/2012 member checks |
| Harness log | Artifact `14885054409`, ZIP SHA-256 `c6f26fb75fca821051c88bfffd377b98de20ca8a1e305d58d37088a8963f21bf` |
| Reusable wrapper log | Artifact `14884839648`, ZIP SHA-256 `b5fe5cf1e9e1b87aa15af746189834a43948add4c8eb1eaa02d6577d8b1e1ac6` |
| TB177 baseline | Artifact `14871900641`, ZIP SHA-256 `8c5bce907f59b77207833153912805cccca6fa122c70ff9f299a64f68102b068`, 2010/2010 member checks; [report](Architecture_M6_CP3_TB177_P13_Mechanical_Retrace_Selection_Receipt_Full_Gate_Execution_Report_20261123.md) |

The final mailbox on the `workflow-mailbox` branch and the provider artifact inventory agree on the event, source, run and artifact identities. Local ZIP digests match. The complete file inventories and each raw transcript hash match their packaged manifests and ledgers. The runtime wrapper records 02:46:31Z to 03:02:16Z. `postflight=true`; configure, compile, relink and benchmark are all false. No rebuild, repair, fixture, selector, manifest or source change occurred in this execution turn.

## Assessment — frozen gate and comparison

| Check | Observed result |
|---|---|
| Execution | 1,002 planned, 1,002 executed, 995 PASS, 7 RED |
| Membership | 1,002 gated + 81 deferred = 1,083; exactly one new gated identity |
| Integrity | Zero missing, duplicate, skipped or abnormal cases; zero unexpected passes, later positive failures or RED-site mismatches; postflight PASS |
| New guard | Row 1002 `RetracedTraceReferences.RemapsExactStruckSegmentAndEndpointPortWithoutPublication`, producer test binary, one executed and one passed, exit 0; raw log SHA-256 `90362e165534bee0fab1a2196cdaa31925021619cc5e80d50c9945370b70a62d` |
| Inherited ledger | All 1,001 rows match except raw-log hashes that reflect permitted differences; zero other field differences |
| Raw comparison | 627 byte-identical; 371 N1/N2-only; 3 N3-only (172/174/176); zero unauthorized differences |
| N3 diagnostic records | 1,450 complete `M3_CP4AB_FRAGMENT_DIAG` records in each inherited inventory; each of rows 172/174/176 has six records in each artifact; the counted per-row multisets match and the remaining bytes/order match after N1/N2 |
| Assertion locations | No shift; all inherited failure sites match |
| Mechanical receipts | Rows 652 and 656 each retain one byte-identical 1,208-byte receipt, SHA-256 `cea589ac94f174b1ee859d777cf580ff342b39354f5c27191eb1e0c58d46aa69` |
| Required controls | Seven failed; harness exit 90 (`ValueError: required controls failed`); this is a semantic rejection, not an orchestration failure |

N1 is Google Test elapsed-time normalization. N2 is line-ending normalization. N3 is the counted multiset of complete diagnostic records only; all other transcript bytes and their order remain significant. These are the rules frozen in [TB-REV-177](Architecture_M6_CP3_TB_REV_177_Adversarial_Review_20261124.md). No assertion-offset normalization was applied. The comparison permits no additional differences. Row 1002 is an isolated helper guard, not evidence of production integration.

### Existing failed controls

| Row | Test | Failure location |
|---:|---|---|
| 445 | `RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b` | `FieldAlignedCurveNetworkTests.cpp:19446` |
| 652 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | exception: `RegionElectedCutComponentEmpty` |
| 653 | `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` | `FieldAlignedCurveNetworkTests.cpp:14457` |
| 656 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | exception: `RegionElectedCutComponentEmpty` |
| 658 | `GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent` | `FieldAlignedCurveNetworkTests.cpp:20027` |
| 660 | `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` | `FieldAlignedCurveNetworkTests.cpp:14256` |
| 786 | `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` | `FieldAlignedCurveNetworkTests.cpp:20086` |

The existing accepted-green TB170 mechanical recurrence persists. The current evidence does not establish a new event, category or recurrence. The earlier reviewed root cause remains the A2a co-traced zero-area lens/arrival-port ownership defect. The helper has no production caller. Row 652 still reports `RegionElectedCutComponentEmpty`; the unchanged receipt preserves the four reverse path pairs and both arrival equalities. Row 979 still reports the staged `RegionContainsInteriorSingularity` at source vertex 8, not production success. CP2 candidate remains 490/491; accepted CP2 491/491 and TB169 993/993 remain unchanged. Stable totals: 67 events, 17 categories, 50 recurrences; witness debt 1; deferred 81. No CP3/497/D0/H4 promotion.

## Recommendation

The separate `M6-CP3-TB-REV-178` must independently reopen both immutable result archives, rederive the comparison and inspect the new guard against the amended reference-remap contract. Confirm the exact receipt and failure sites and the existing recurrence classification. Then review and freeze CB-199B only if the evidence and design support it. Do not start production selection, add the arrival-port field, change the port-set readers, repair any case, or change the acceptance rules in this turn. CB-199B and CB-200 remain held until separately authorized.
