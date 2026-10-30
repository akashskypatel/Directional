# M6-CP3-TB53-RP01-FULL-GATE-EXEC — local five-binary gate on the CB54 package (2026-10-30)

**Scope:** TB-EXEC, run locally at the user's direction because the implementation agent was unavailable and GitHub workflows were not to be used. This report gives counts and first failures only. Classification belongs to `M6-CP3-TB53-RP01-FULL-GATE-REV`.

## Frozen inputs

- **Package:** CB54 (`build/local-evidence/CB54/pkg.zip`, gitignored), ZIP SHA-256 `21b7cf2d0432322bfd02c76ed2c84ced938e06cd7462c693b49c6fc9a089fa7d`, root `SHA256SUMS` `262878fd…`, source `2a49b8738c293fac012cde52c9caee477d205aaa`, source archive `9d0cf0a7…`. macOS 26.6.2 arm64, Apple clang 21.0.0, static, GMP. [CB54 record](Architecture_M6_CP3_CB54_RP01_Terminal_Path_Witnesses_Code_Build_Record_20261030.md).
- **Gate:** [`Architecture_M6_CP3_TB53_RP01_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB53_RP01_Full_Gate_Case_Manifest.tsv), 855 rows, `5239f81a…`. **Ledger v3:** [`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv`](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv), 83 rows, `32b43fc5…`.
- **Runner:** [`tools/m6_cp3_local_gate_driver.py`](tools/m6_cp3_local_gate_driver.py), with harness `78b8002c…` loaded unchanged and three workers, each case in its own process and working directory. Run from 21:05:23Z to 21:14:55Z; the exact command is in the handoff.

## Result

The result is `build/local-evidence/TB53/result.zip` (gitignored), SHA-256 `5722887a22a3711618c4880eb262b9493829d88ece3484f81d18f7c46a534f0d`, with 1,718 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **855 / 855 / 836** |
| RED / ABNORMAL / missing / skipped / duplicate | **19** / 0 / 0 / 0 / 0 |
| control_bad (GUARD rows not PASS) | 19 |
| Membership (five binaries) | **938** = 855 GATED + 83 DEFERRED |
| postflight / harness exit | true / **90** (`required controls failed`) |

- **RP-01 rows:** row 854 (`offgate:223`, `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm`) **PASS**; row 855 (`offgate:225`, `M6CP3.TerminalRailContactPathsUseTypedSourceStarA3`) **PASS**. The retired 261 is absent from the package listing.
- **Non-PASS rows (all GUARD; all 19 passed in TB52 on Linux):**

| Row | Identity | Test | First failure |
|---|---|---|---|
| 283 | selector:241 | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns` | exception `segment_arrangement(): surviving twin has invalid next` |
| 445 | selector:403 | `RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b` | `FieldAlignedCurveNetworkTests.cpp:17125` |
| 637 | offgate:172 | `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` | exception `…SingularityPortClassCountMismatch;sourceVertex=35` |
| 638 | offgate:173 | `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` | exception, same text |
| 649 | offgate:186 | `GlobalTopologyPlan.EmbeddedGraphEulerCensusPublishesThroughMechanicalProductionFailure` | `:13485` |
| 650 | offgate:187 | `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath` | `:13205` |
| 652 | offgate:189 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | `:10834` |
| 653 | offgate:190 | `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` | `:13727` |
| 656 | offgate:195 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | exception `…SingularityPortClassCountMismatch` |
| 658 | offgate:199 | `GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent` | `:17705` |
| 660 | offgate:201 | `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` | `:13526` |
| 662 | offgate:203 | `GlobalTopologyPlan.UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence` | `:13333` |
| 665 | offgate:206 | `GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure` | `:12705` |
| 669 | offgate:210 | `M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral` | `:16125` |
| 687 | offgate:230 | `ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort` | `:11297` |
| 784 | offgate:347 | `SurfaceCutGraph.CertifiedOwnerConflictCensusPublishesOnOwnershipFailure` | `:17389` |
| 786 | offgate:349 | `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` | `:17764` |
| 787 | offgate:351 | `SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus` | `:17838` |
| 788 | offgate:352 | `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure` | `:17455` |

Line numbers without a file name are in `tests/FieldAlignedCurveNetworkTests.cpp`.

- **Factual joins (not a classification):**
  - 14 of the 19 rows are in RA-176's list of 18 gated `mechanical_feature` rows. The other four in that list (86, 396, 397, 471) passed.
  - 18 of the 19 logs reference source vertex 35. Rows 637, 638, 652, 656, 669 and 687 contain the A3 text `SingularityPortClassCountMismatch`.
  - Row 283 is the legacy-arrangement row that RA-176 routed to O2.

- **Independent audit (subagent, read-only), all checks pass:**
  - The result ZIP, manifest and ledger hashes match, and 1,718/1,718 checksum entries verify, with no unlisted files.
  - 855/855 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 836 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 938 = 855 GATED (exactly the manifest pairs) + 83 DEFERRED (exactly the ledger v3 pairs); 261 is absent.

## Outcome

Per RA-178.5: any non-PASS → **`M6-CP3-TB53-RP01-FULL-GATE-REV`** classifies it, with no retry. No selector, CP3 or RP-01 acceptance is made here. Stable 66/17/49 and debt 1 are not changed by an unreviewed run.
