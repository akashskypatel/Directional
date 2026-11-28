# TB-EXEC-186T — activated sphere termination census (2026-11-26 UTC)

## Situation

The six frozen OBSERVE cases finished. Five tests passed and row 858 failed organically. No case reached the 600 s limit. This is diagnostic execution only, not full-gate acceptance. Independent `M6-CP3-TB-REV-186T` must adjudicate the row 858 result and the frozen predictions.

## Background — immutable authority

- Candidate/executor source `2d62bf3b15f4571504fddd21bafbdd9019f0eeb9`; [CB-206 record](Architecture_M6_CP3_CB206_P13_Slide_Entry_Activation_Code_Build_Record_20261126.md). [Compile run 45857779921](https://github.com/akashskypatel/Directional/actions/runs/45857779921), artifact `15136691967`, ZIP SHA-256 `5b2ae326640d0b55feedeeeb46faf1c389dc110177307fafedea8e2759a40127`. Root manifest `0a35cc8e36ec86c3a70fe40e709dbd6f4f4440fb7fc8071f66c667db98ca827f`; source archive `3ca963601fe85a5982375c16a6b507c461a2c1ce613ab7532f9469b873dc6f95`; 28/28 package checks, eight GMP/GMPXX targets, compile-only.
- [Frozen census contract](gates/Architecture_M6_CP3_TB186T_CB207D_Activated_Sphere_Termination_Exact_Manifest.md); manifest `80970f595b3fe0d46fca08ae47fae1f53567a6d2b9b500ec34f74de24019eefc`; harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. All six manifest identities, tests and binaries match the result ledger. No membership ledger or single-row diagnostic mode.
- Request `m6-cp3-tb186t-exec`, event `b03b9d2c1d95c65dd4757f9939bf27bb98764e9b`, request SHA-256 `bf3dec6f4e5c37bfb12dcdc11b2ccb997389c1f27c2ee5c980e25eba4d14b4fe`. [Run 45861079666](https://github.com/akashskypatel/Directional/actions/runs/45861079666), [runtime job 140052235045](https://github.com/akashskypatel/Directional/actions/runs/45861079666/job/140052235045); source/event identities match the authoritative mailbox, published 16:46:15 UTC. Both schema validations, parse, runtime and mailbox succeeded. Compile, noop and drive_apply jobs skipped. Job log confirms exact executor, harness hash and preflight, all six cases, harness exit 0. No repeat execution.
- [Result artifact 15138712336](https://github.com/akashskypatel/Directional/actions/runs/45861079666/artifacts/15138712336), ZIP `42de0d943825cd6e5b3932fb98300cf6555bd7a25a8786179d8f5bcfb670b3a3`; root `SHA256SUMS` `0f0e7fab8545d997757bfa497a7d9177d1476fa4dbb9020494d583cf5861aa09`; 16/16 member hashes match. Runtime log artifact `15137908089` ZIP `aeaf4b15df641b906c60d4ac55f87b5c2b092ce1e5e9bb49493b7b9c99e15a12`; reusable log `15138048008` ZIP `2ca1f238b4ef893c94d6624f564b91e379f8a0fc95eb0a5c001a6dc28d37a659`. The job log and result provide the evidence; separate log ZIPs were not downloaded.
- The result records `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `postflight=true`, `membership=0`, `planned=6`, `executed=6`, `passed=5`, `red=1`, `abnormal=0`, `missing=0`, `skipped=0`, `duplicate=0`, `exit=0`. OBSERVE permits organic RED. No gate credit. The harness extracted executable modes without repair, verified the immutable package and ran packaged inputs only. No local build or product execution.
- Accepted preactivation comparator TB187Q: [report](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md), result `15130286146` ZIP `a3fb3a89a3dd72ccc2870412fd0d6e78af4921943d7f491c4735443264de8ecc`, 2020/2020 member checks verified. All six corresponding tests previously passed; the full 1006-case gate is not repeated or compared here.

## Assessment — exact case results

Peak resident set size (RSS) is the maximum memory reported by `/usr/bin/time -v`, in KiB. The raw log hashes below match the ledger and the result archive manifest. Each row selected and executed one test. Resource exit agrees with the ledger. No timeout marker occurs in any raw log.

| Census / gate row | Verdict | Exit | Wall s | RSS KiB | Cutoff | Raw log SHA-256 | First failure |
|---|---|---:|---:|---:|---|---|---|
| 1 / 648 | PASS | 0 | 14.60 | 37488 | No | `36c3c45bf06412f584873d27aae18dedc6e7df7b50d43a4b0b4a93c57ab740f0` | failure-line-not-observed |
| 2 / 843 | PASS | 0 | 13.63 | 31460 | No | `41a75d565a4abadd67c07e2a6e9bb21b831ce626877cd36a120cb194a6171aa5` | failure-line-not-observed |
| 3 / 844 | PASS | 0 | 13.57 | 31360 | No | `d97b12e6546fd7d0db59f41a7cb4eca82bd9fb41cfe262dbbe66aa6edc61d2bc` | failure-line-not-observed |
| 4 / 858 | RED | 1 | 13.97 | 66456 | No | `b562e94394d65a11f4569c7813384ca4e5c98c05d81da6f489a4d535b79fe225` | ../../Directional/Directional/tests/SurfaceCellTracingDisplayTests.cpp:222: Failure |
| 5 / 979 | PASS | 0 | 33.13 | 36084 | No | `a568ccb493c8055616ee8846d28dd4e8eaca05bef2ae1b06488cd00fa0472b67` | failure-line-not-observed |
| 6 / 1006 | PASS | 0 | 128.59 | 37472 | No | `7e7e5bd700f53a46c8ed88c41bd46e66c6e6e01a61ad190e99cf256de36b6c75` | failure-line-not-observed |

Total measured case time 217.49 s. The longest case, row 1006, took 128.59 s. The 0.02 sphere recipes in rows 843, 844, 858 and 1006 all finished. The 0.2 cases 648 and 979 also finished. These are bounded observations, not a general scaling guarantee or a close_sheets termination result. Row 1006 was 51.56 s in TB187Q before activation; the different work prevents attributing the increase to QF1. No speedup claim.

### Row 648 — exact CB-206 prediction

```text
m3Cp4c3BW4;torus={V=72,E=76,F=4,componentCount=1,sourceChi=0,residual=0};sphere={V=18,E=30,F=14,componentCount=1,sourceChi=2,residual=0}
```

The complete line matches the [CB-206 frozen prediction](gates/Architecture_M6_CP3_CB206_P13_Slide_Entry_Activation_Exact_Manifest.md). Both topology census residuals are zero. The sphere cut graph and topology plan assertions pass. This does not prove completion.

### Row 858 — organic RED and candidate root cause

```text
SphereDisplayStop stage=completion code=NotProductionReady sourceFace=- relatedSourceFace=- sourceEdge=- sourceVertex=-
../../Directional/Directional/tests/SurfaceCellTracingDisplayTests.cpp:222: Failure
Value of: display->has_stop_location()
  Actual: false
Expected: true
```

The verified TB187Q raw row 858 (SHA-256 `682fa35697320bb626b683c32c5622daa936f34f83a28aaeded13cc024c5a6a5`) passed with:

```text
SphereDisplayStop stage=surface-cut-graph/CutSearchExhaustedBeforeCellularity code=NotProductionReady sourceFace=0,1,2 relatedSourceFace=- sourceEdge=- sourceVertex=-
```

Activation advanced the sphere from cut-graph rejection to completion rejection. The negative `ASSERT_NE("None", ...)` still holds. The failure is the later unconditional geometric stop-location assertion, not that negative assertion. `tests/SurfaceCellTracingDisplayTests.cpp:194–223` tests the reported locus and then requires a location for all three fixtures. `src/visualization/SurfaceCellTracingDisplay.cpp:181–196` reads the reported locus and prints stage/code notes. `include/directional/visualization/SurfaceCellTracingDisplay.h:53–55` requires at least one face, edge or vertex in `has_stop_location()`. Completion can reject without a locus (`src/pipeline/RemeshPipeline.cpp:14363–14369`; other completion rejection sites exist). The common failure helper at :12362–12385 accepts a default empty locus. The raw line does not identify the exact completion predicate or detail code. Do not infer a specific missing geometric entity or that the completion failure is correct. The immediate cause of the display assertion is established; the contract classification (test premise vs missing required production locus) is unresolved. No source, display, fixture or assertion correction here.

Candidate/non-stable accepted-green loss: row 858 is the sole red result in this diagnostic census. The failure is an observed change in an existing test, not yet a stable product regression category. Preserve 67 events / 17 categories / 50 recurrences, witness debt1/deferred81 until independent classification. QF1 remains non-stable: no cutoff occurred in this scope, but the cost hypothesis and fine-resolution close_sheets case remain unproved.

### Row 979 — preserved explicit unstaged rejection

```text
SphereStagedCutGraph unstagedCut=CutSearchExhaustedBeforeCellularity V=18 E=30 F=14 orbits=14 chi=2 sourceChi=2 components=1 cutEdges=0 candidates=288 selected=0 slideCarriers=10 slideClassified=10 slideSelected=0 slideCutEdges=0 sourceFaceCellularity=1
```

The `unstagedCut=` value matches the exact prediction. The test passes with activated production and its explicit unstaged negative control.

### Row 1006 — all eleven exact receipts

LF-terminated receipt SHA-256 `d8407bea068c219f04c785fc2701e0a82093c9b8220514d3786c84869f4ca00c`, exact match to the CB-206 frozen prediction. No normalization.

```text
SlideEntryActivationReach recipe=observe fixture=sphere_prescribed production={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} staged={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} productionStagedDigestEqual=1 published=12659562395504099178 explicitUnstaged={status=built,digest=9084693800288509401,traces=24,events=56,slideStops=0,polylineEligible=1}
SlideEntryActivationReach recipe=observe fixture=torus production={status=built,digest=13466378781049494490,traces=0,events=0,slideStops=0,polylineEligible=0} staged={status=built,digest=13466378781049494490,traces=0,events=0,slideStops=0,polylineEligible=0} productionStagedDigestEqual=1 published=13466378781049494490
SlideEntryActivationReach recipe=observe fixture=mechanical_feature production={status=built,digest=7059319813685616393,traces=8,events=23,slideStops=0,polylineEligible=1} staged={status=built,digest=7059319813685616393,traces=8,events=23,slideStops=0,polylineEligible=1} productionStagedDigestEqual=1 published=7059319813685616393
SlideEntryActivationReach recipe=pipeline-products fixture=sphere_prescribed production={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} staged={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} productionStagedDigestEqual=1 published=12659562395504099178
SlideEntryActivationReach recipe=pipeline-products fixture=torus production={status=built,digest=13466378781049494490,traces=0,events=0,slideStops=0,polylineEligible=0} staged={status=built,digest=13466378781049494490,traces=0,events=0,slideStops=0,polylineEligible=0} productionStagedDigestEqual=1 published=13466378781049494490
SlideEntryActivationReach recipe=atlas-census fixture=two-ring production={status=built,digest=4155612135388465130,traces=3,events=8,slideStops=0,polylineEligible=1} staged={status=built,digest=4155612135388465130,traces=3,events=8,slideStops=0,polylineEligible=1} productionStagedDigestEqual=1 published=not-applicable
SlideEntryActivationReach recipe=atlas-census fixture=four-triangle-fan production={status=built,digest=4544773262561843459,traces=3,events=8,slideStops=0,polylineEligible=0} staged={status=built,digest=4544773262561843459,traces=3,events=8,slideStops=0,polylineEligible=0} productionStagedDigestEqual=1 published=not-applicable
SlideEntryActivationReach recipe=atlas-census fixture=sphere_prescribed production={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} staged={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} productionStagedDigestEqual=1 published=not-applicable
SlideEntryActivationReach recipe=atlas-census fixture=torus production={status=built,digest=4209930161671820097,traces=0,events=0,slideStops=0,polylineEligible=0} staged={status=built,digest=4209930161671820097,traces=0,events=0,slideStops=0,polylineEligible=0} productionStagedDigestEqual=1 published=not-applicable
SlideEntryActivationReach recipe=polyline-defaults fixture=sphere_prescribed production={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} staged={status=built,digest=12659562395504099178,traces=24,events=56,slideStops=4,polylineEligible=1} productionStagedDigestEqual=1 published=12659562395504099178
SlideEntryActivationReachPolyline productionFirst=sphere_prescribed stagedDiagnosticFirst=sphere_prescribed
```

## Recommendation

Next only `M6-CP3-TB-REV-186T`. Independently verify result and baseline bytes, all six outcomes, receipt predictions, row 858 contract and completion stage/locus. The measured prerequisite for contingent CB-207D (0.02 case cutoff) is absent. Do not apply it on this evidence. The review must either authorize the full gate plus V5 or freeze an exact corrective Code + Build turn under the existing adversarial sequence. Preserve the full gate's STOP-on-RED rule; do not rerun the census or weaken row 858. Retain TB187Q 1006/1006 as accepted preactivation only. No CP3/497/D0/H4 promotion. J6/E5/CB-190 held.
