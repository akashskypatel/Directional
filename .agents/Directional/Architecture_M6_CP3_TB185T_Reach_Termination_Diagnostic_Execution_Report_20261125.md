# TB-EXEC-185T — reach termination diagnostic (2026-11-25 UTC)

## Situation

Valid bounded external observation; no semantic gate verdict. The row1006 process remained active in surface quotient construction at the observation cutoff. The dominant sampled cost is `quotient_forest_path`, not the preceding region projection diagnostic. TB184 remains independently accepted (1005/1005). No reader activation.

## Background — exact evidence

- Candidate artifact `14995401750`, source `21087c8285a5dd367cc16f610386accc061bd194`, compile run `45554728034`; package ZIP `7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9`, root manifest `255e344116e2faa2d351b637cdfc6d11805b83352965f794b8bddaf56409f5d3`, source archive `bba6f2ce82c27a1481dad5fb16952b88476fca25411840a3e6d588ad67d2502e` (SHA-256). Frozen gate 1006, deferred81; [authority](Architecture_M6_CP3_CB205T_Debugger_Provisioning_Record_20261125.md), [preparation](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_cb205s_reach_termination_diagnostic_preparation_record_20261125md). No new build.
- Executor `90319deb1dc277a2b0ab8bba70c8aa2cf3f2f6a1`, harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Request `m6-cp3-tb185t-reach-termination`, event `2abd77f2e1f678dac221d0dde146f50a5a984615`, request SHA-256 `25aeadd27c0673f34577c3218a22e72caa7065b4a16c0a509f849f18ad79ec5b`; exact mailbox matches. [Run 45639470951](https://github.com/akashskypatel/Directional/actions/runs/45639470951), runtime job `139294131198`; schema and parse PASS, compile/Drive/noop skipped, runtime failure by exit124 propagation, mailbox success. The wrapper's intermediate `final_job_status=success` does not override the job conclusion or harness exit.
- Inspection snapshot `43885d0421821d9f02441dd548d6494e4610f82f`, run `45639063907`, artifact `15035176113`; ZIP SHA-256 `443afa455db7690263443ce16912ab354e056194b9c552a30724a030db1f916c`, archive SHA-256 `befab2151fb4481e599a04989c1ebe3d4e31be337feff92542978ae85a42c35f`, 5836/5836 checks. Compare candidate to snapshot: no product/test/fixture changes. `src/pipeline/RemeshPipeline.cpp` SHA-256 `57c2251135637beff46a6bf26ada735a2ec3f296b251a32a3445a8bec2fb4a02`; test source `03abb0a6abcd8dbafb40bfe4dfbc56c0a2744a5eca9353749c1bf08b9cf3d72d` matches CB205S record.

| Artifact | Verified ZIP SHA-256 |
|---|---|
| Result `15035995368` | `5f8900589df9acb99ad0e43f3edc314f79055728888e826994bf1d5a4c637bec` |
| Harness log `15035955387` | `779683cb5b9d9a66e6095ab6551fb37662e0c54fb320e6fffa18beb79bd7e62c` |
| Wrapper log `15034889362` | `52eb8e2bd43e0ae92b59d3634fa132ddb1e698d3ed167f10347c935b07ea349a` |

## Assessment — observation

All 15/15 result members match the self-excluding manifest. GNU Debugger (GDB) 15.1 (`15.1-1ubuntu1~24.04.1`) control `/usr/bin/sleep 8` verified Linux process-ID file descriptor, three completed interrupt/stack/continue samples and organic exit zero at 8.281 s. Product selected exactly `TraceTerminationCorrection.SlideEntryActivationReachByReaderRecipe`, once; no other test launch or discovery. 19/19 product samples completed, one observed thread throughout; `bounded-observation-ended` at 575.264 s (600 s maximum, 25 s cleanup reserve), observer exit124, debugger exit0, no organic test exit. Package/view postflight true; no compile/relink/configure/benchmark, all gate counters zero. No semantic PASS/RED or full-gate credit.

Raw log 335720 bytes, SHA-256 `661c9417f4a413d8f7d2d80f89a613e7a0c5daba3974f372003558b104dda550`. Prior TB185R raw `06226ad145730dafed92a6cc8381299ac36e5d72062a69b77c468cedbaf7e8f0`; the 11 full recipe lines are byte-identical; whole logs differ. No final selection, close_sheets/cylinder receipt or terminal assertion. Test loop at `tests/FieldAlignedCurveNetworkTests.cpp:24037–24048` and fixture helper at 8100 place this frontier in close_sheets construction; input 32 vertices, 36 triangles, two disconnected components. Stack frames confirm the fixture helper and full pipeline, not the subsequent measurement lambda. Samples 1–2 occur before the 11-receipt frontier; samples 3–19 have the identical 335720-byte log and hash above. All 17 contain `quotient_forest_path` under `SurfaceQuotientProducer::produce`; process and sole thread wait channel 0, CPU tick counts increase by 2999–3001 per interval. Resident memory rises from 496248 to 608220 kB. This is active computation with changing instruction addresses, not observed sleeping/deadlock; memory growth is not proof of a leak. Repeated stack samples do not prove infinite looping or exact asymptotic cost.

| Sample | Elapsed s | CPU ticks (user + system) | Resident kB | Instruction address |
|---:|---:|---:|---:|---|
| 3 | 90.123 | 8998 | 496248 | `0x560e2bf19e2b` |
| 4 | 120.127 | 11997 | 533096 | `0x560e2beeafcd` |
| 5 | 150.13 | 14997 | 542836 | `0x7f40b2aab738` |
| 6 | 180.133 | 17997 | 546660 | `0x560e2bedac03` |
| 7 | 210.137 | 20997 | 554360 | `0x7f40b2aaabcc` |
| 8 | 240.142 | 23997 | 560736 | `0x7f40b2aab738` |
| 9 | 270.145 | 26997 | 591388 | `0x560e2bedabcb` |
| 10 | 300.149 | 29996 | 592880 | `0x560e2bedac03` |
| 11 | 330.153 | 32996 | 594720 | `0x560e2beeb045` |
| 12 | 360.157 | 35996 | 595144 | `0x7f40b2aab8c0` |
| 13 | 390.161 | 38996 | 595728 | `0x560e2bf19dd2` |
| 14 | 420.164 | 41996 | 599384 | `0x7f40b2ed4147` |
| 15 | 450.168 | 44996 | 600096 | `0x560e2bf16593` |
| 16 | 480.172 | 47995 | 600672 | `0x560e2bf19ddf` |
| 17 | 510.176 | 50996 | 601272 | `0x7f40b2aab738` |
| 18 | 540.18 | 53995 | 607736 | `0x7f40b2aab636` |
| 19 | 570.183 | 56996 | 608220 | `0x560e2bf1aa7a` |

Reliable common stack (leaf to caller): `quotient_forest_path` → `SurfaceQuotientProducer::produce(SurfaceOccurrenceComplex const&)` → its overload with hard-feature edges → `build_authoritative_phase_front_mesh_with_hard_features` → `remesh_from_raw_cross_field_impl_with_stage_products` → `remesh_from_raw_cross_field` → `build_cp4c_pipeline_products_fixture` → row1006 TestBody. Samples include ordered-map insertion/destruction, allocation and traversal; producer caller addresses `0x560e2bf86ad1` (3–8) and `0x560e2bf876cd` (9–19), showing different call locations. The optimized stack has symbols but not source line locations. Exact source owner `src/pipeline/RemeshPipeline.cpp:5618–5673` builds and sorts a new adjacency map from the entire forest each call, then traverses with a parent map. Producer at 5676 calls this helper at 6008 for non-joining relations and 6103 for each non-root member of each class, to derive selected-path evidence. Other consumers at 6346, 6525 and 8555 also call the helper; no claim they were sampled. These source facts and stack observations support repeated whole-forest reconstruction as a concrete cost candidate. Exact invocation counts, forest size, contribution of certificate storage, and sufficient correction are unmeasured; do not equate caller addresses to source lines without symbol/disassembly evidence. No product changes or independent correction proof in this diagnostic.

Stable 67 events / 17 categories / 50 recurrences, witness debt1/deferred81 unchanged; no accepted-green loss established by this non-gating observation. CP2 491/491 accepted, P1 supported, D-U carried, TB170/K6 closed. No activation, J6/E5/CB-190 repair or CP3/497/D0/H4 promotion.

## Recommendation — next turn only after closeout

Route the localized cost candidate to `M6-CP3-TB-REV-185T-REACH-TERMINATION-DIAGNOSTIC` under the applicable Review authority in the CB205T record. Reopen the exact artifact and source independently; derive ownership of repeated forest construction, both producer call sites and all other callers, bound work and certificate storage, preserve exact path order/orientations, transport, failure checks and output semantics. Freeze only a justified correction and independent falsifier, not a speculative patch or an oracle shortcut. No blind rerun, timeout acceptance, shortened fixture sequence, or gate change. A justified correction must precede an uninterrupted full 1006-case immutable gate and TB-REV-185, then conditional CB-206. No successor execution in TB185T.

## Closeout limitations

Initial direct document reads preceded snapshot-mode selection and snapshot mailbox polling was excessive. Corrected by verified source snapshot before source inspection. One transient connector disconnect was retried successfully (mailbox then absent). Local audit worktree initially failed Git directory ownership check; scoped local option corrected it. Baseline drift audit: zero errors, two existing navigation-size warnings. Full start checklist and exact tool-call ledger not independently verified after context compaction. Document application and temporary-state cleanup are separate closeout steps; do not claim them before verified evidence.
