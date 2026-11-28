# TB146 — execution RED, accepted-prefix STOP (2026-11-19 UTC)

## Situation

The full gate completed all 962 identities on the immutable CB168G package. Required row 393 changed from PASS to RED. This is a semantic stop, not an execution or control-plane failure. Under the [frozen plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md) and [Turn Cadence](Turn_Cadence.md), stop further runtime execution. The three-row census was not dispatched. The execution turn ends with a RED result after closeout; its independent Review owns adjudication. No production or selector acceptance.

## Background — verified immutable authority

| Item | Exact value |
|---|---|
| Semantic source | `ebbe893bd5415e05ea828d5587a265d08326d1fa` |
| Compile run / package | 44599291384 / 14566343560 |
| Package ZIP SHA-256 | `41fc237f91b24cdc369908f483579ef3e16d55b7c7743ccd97ded4f30b83c717` |
| Root checksum manifest | `4211bd1406fefb8626575b0495ebd87dad2d73b9a468f209f4e3112448e1373a` |
| Source archive | `01afa970a754b979ac4cb8c853069b356afdc4122a2c2244ede5c393784aa503` |
| Executor snapshot source | `5a1a2fc5e137d29438bfbf66953dd96e6d1d886e` |
| Snapshot run / artifact | 44603278856 / 14569910640 |
| Snapshot ZIP SHA-256 | `b3b54c48d2795bcfe6734b652ffd2e0dc612a90cb2108e2faee10c71d664054f` |
| Harness SHA-256 | `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Gate manifest, 962 rows | `aa9911870a7514ea5674f869e74d8681f1ad0fcc8a14f43096b8da4f5210b61f` |
| Deferred ledger, 81 identities | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Census manifest, three rows | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| TB145 gate run / artifact | 44484110110 / 14510581877 |
| TB145 census run / artifact | 44484220632 / 14510118951 |


| Execution evidence | Exact value |
|---|---|
| Gate request / dispatch commit | `m6-cp3-tb146-gate-20261119-a1` / `06ef402f737b644d7d7161c198f2a241a220c9b4` |
| Gate [run 44603830217](https://github.com/akashskypatel/Directional/actions/runs/44603830217) / runtime job | 44603830217 / 135842481416 |
| Result ZIP 14569832286 | `c776ec086e6aa50a11cc8f98db2074c282191a13bf6f58b8bd61de1cf85c6f14` |
| Harness log ZIP 14569222609 | `0d25cecab04c06bed6b2a42c40414cd12da9d054919ac171912dd8be0d36e8dc` |
| Reusable log ZIP 14569242504 | `44a12863801cb59872c242d2ecac788bfdc99fe60384b0b036af0de6a9c02073` |
| TB145 gate ZIP 14510581877 | `bac8df3f16b8161f92813e30644ac5d96e9538395fcd4c6b00b285f83d6519fe` |
| TB145 census ZIP 14510118951 | `463a9be377eed40e8c327760f299819b41928e70535aa34c00fe3d14a8507a1d` |

Verified the package's 28 indexed checksums and six executable modes at entry. Source snapshot recorded 5,613 files. Gate result: all 1,932 indexed checksums and 962 raw-ledger digests match; baseline TB145 gate/census 1,930 + 9 indexed checksums and 964 raw-ledger digests match. Both dispatcher validation jobs, parse and mailbox passed. The immutable harness ran from 19:59:14Z to 20:08:08Z and returned exit 90 (`required controls failed`). No build, relink, configuration, benchmark or source/test/fixture/selector change. The runtime job failed only when propagating the harness result.

## Assessment — stop criteria

| Required condition | Result |
|---|---|
| 962 gate + 81 deferred exact membership | PASS: 1,043; 962 executed, none missing/skipped/abnormal/duplicate; postflight true |
| Row 961 and new row 962 PASS | PASS / PASS |
| Accepted prefix rows 1–491 unchanged PASS | **FAIL: 490/491, row 393** |
| Non-sphere prior gate rows MATCH TB145 (frozen N1–N7) | 941/941 MATCH |
| Sphere entry receipts byte-equal | 20/20; all 240 gate entry receipts unchanged |
| Doubled M3_CP4AB_FRAGMENT_DIAG prefix | 0; 1,738 records in each gate; full record multisets match |
| Cylinder PASS/288 and BunnyRandom first failure trace 82 | Not evaluated; the accepted-prefix STOP prevents census dispatch |

TB145 gate 960/961 PASS → TB146 961/962 PASS. Only verdict changes in prior rows: 393 PASS→RED and 858 RED→PASS. The new row 962 passes. Row 648 remains PASS. All 1,200 gate slide proposals and 1,200 gate committed-slide receipts of each kind match the prior byte streams. The execution comparison retained all other per-row outcomes and typed reasons, with sphere rows enumerated rather than required to match. No full 964-prior-case MATCH is claimed because the census was not run and 19 sphere logs changed. Stable accounting remains 66 events / 17 categories / 49 recurrences, produced-witness debt 1, deferred 81; the new regression candidate is not independently adjudicated.

### Row 393 — exact failure and candidate

`TraceTerminationCorrection.PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents` (`directional_surface_cell_producer_tests`). Four distinct assertion failures report `FieldAlignedCurveNetworkTests.cpp:17144`: `Expected: (contact.struckSegmentIndex) < (struck->segments.size()), actual: 7 vs 7`. Raw log SHA-256 `29230abe7f777f2950a4e4d8c3fba2ee046e0e809e3b23193b3fc59b0c963f8a`. The frozen patch explicitly defines mutual stops at the other trace's end, where the index equals the segment count. The observed result is consistent with a test premise that excludes a newly allowed end index, but the assertions omit trace IDs. It is not proof that each failed assertion is one of the two correct mutual pairs. The Review must check exact published contacts and the unchanged consumer contract. No relaxation of this or any other assertion is authorized here. Treat the outcome as RED regardless of the causal hypothesis.

### Sphere partition and prediction inventory

S is the 20 rows with a prior different-face entry receipt. Across S the exact prior duplicate diagnostic on selected cut edge (0,2) at parameter `574181338608147/4503599627370496` appears 66 times in 19 rows; current count is zero in all 20. Raw receipt pairs 4:7/6:7 on (0,2) and 15:7/19:7 on (25,27) retain `inconclusive/different`. The following table lists observed row changes (pair counts include repeated evaluations, not distinct trace events).

| Row | TB145 → TB146 | (0,2) duplicate count | Pair receipts each | First failure/locus and other measured change |
|---:|---|---:|---:|---|
| 380 | PASS → PASS | 4 → 0 | 9 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 388 | PASS → PASS | 4 → 0 | 9 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 393 | PASS → RED | 4 → 0 | 6 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Four failures at FieldAlignedCurveNetworkTests.cpp:17144: struck index 7 is not less than count 7; 24 traces assertion and other checks did not fail. |
| 394 | PASS → PASS | 4 → 0 | 7 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 396 | PASS → PASS | 4 → 0 | 7 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 397 | PASS → PASS | 4 → 0 | 6 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 644 | PASS → PASS | 4 → 0 | 3 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Source-edge barrier V/E/F 81/112/33 → 81/109/30; incoming/outgoing carriers 102/112 → 100/109; χ=2, non-disc=0 unchanged. |
| 645 | PASS → PASS | 2 → 0 | 3 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Sphere barrier V/E/F 81/112/33 → 81/109/30; incoming/outgoing 102/112 → 100/109; complete component inventory changed; χ=2, all 30 discs. |
| 648 | PASS → PASS | 2 → 0 | 3 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Negative plan premise remains PASS; plan absence assertion holds. |
| 669 | PASS → PASS | 4 → 0 | 13 | InvalidNetworkBinding / InvalidCutGraphBinding (trace 4, edge 0–2) → CutSearchExhaustedBeforeCellularity (no source edge; exact face unprinted). Printed first failure changes to cut-search exhaustion; network events 60→56 and terminal intersection events 12→10. |
| 686 | PASS → PASS | 4 → 0 | 3 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Actual embedded-graph diagnostic V/E/F 20/34/22 → 18/30/18; χ 8→6, source χ=2, producer complex unavailable in both; no acceptance. |
| 691 | PASS → PASS | 4 → 0 | 6 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 693 | PASS → PASS | 0 → 0 | 3 | Not printed. Normalized entire record MATCH; no prior duplicate-crossing diagnostic. |
| 694 | PASS → PASS | 4 → 0 | 9 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 698 | PASS → PASS | 4 → 0 | 9 | InvalidNetworkBinding / InvalidCutGraphBinding (trace 4, edge 0–2) → CutSearchExhaustedBeforeCellularity (no source edge; exact face unprinted). G5 report: credit none, 24 traces unchanged; new cut-search exhaustion, events 60→56, terminal intersection events 12→10; cross-family receipt interleaving changed, each receipt stream remained byte-equal. |
| 699 | PASS → PASS | 4 → 0 | 6 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Report-only test remains PASS; only duplicate-crossing lines removed. |
| 700 | PASS → PASS | 4 → 0 | 9 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 843 | PASS → PASS | 2 → 0 | 3 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 844 | PASS → PASS | 2 → 0 | 3 | Prior duplicate-cut-crossing diagnostic: edge (0,2), trace 4/6 → no duplicate record; exact first-failure stage/code/locus not printed in either row. Only prior duplicate-crossing lines removed; no outcome change. |
| 858 | RED → PASS | 2 → 0 | 3 | InvalidNetworkBinding / InvalidCutGraphBinding → face-locus test PASS; new code/corners not printed in this row. RED→PASS at SurfaceCellTracingDisplayTests.cpp:155; source-face presence and display checks now pass; exact face corners not printed. |

The first failure is still in surface-cut-graph in the reports that print the stage (669, 698). It changes from invalid network binding, originating `InvalidCutGraphBinding`, to `CutSearchExhaustedBeforeCellularity`; no claimed source edge is printed in the latter. Row 858 passes the source-face requirement, but its new exact stage/corners are not logged by that test. Do not infer them from another row. Row 686 oracle χ remains unequal to the source; row 648 still has no global plan. These results do not establish a successful sphere quad mesh.

### Per-trace census — evidence limits

Every S row contains the same two exact **pre-commit** entry pairs with pending segment index 7. In the 19 prior rows with duplicate diagnostics, traces 4 and 6 each have final count 8, `end=contact`, crossing index 7; trace 4 names struck trace 1 index 0 face (0,2,3), trace 6 names struck trace 0 index 0 face (0,1,2); `sharedEvents=none`. The prior diagnostic does not report final contact records for 15/19. Row 693 does not print the duplicate diagnostic. Current rows 669 and 698 print all four trace IDs 4/6/15/19 in `terminalEventTraceIds` with kind 2 (`TraceIntersection`); the observed incidences are Terminal. They do not print event node, exact event edge, other incidence roles or final contact fields. Other current S rows do not print these fields. Row 393 prints four equal-index/count pairs (7/7) without IDs. The raw entry receipt is not a final segment count, contact record, or proof of a mutual event. For all 80 row/trace combinations, current final counts and terminal-contact face/struck/index/locus and event node/sourceEdge are **unobserved by trace ID**. A separate census run cannot be started after the STOP. Preserve the raw logs and the derived 80-row inventory for independent Review; do not manufacture missing trace states.

## Recommendation — authorized successor

`M6-CP3-TB146-P13-TRANSVERSE-ENTRY-MUTUAL-STOP-FULL-GATE-REV` only, after the execution closeout. Re-derive the 941 unaffected comparisons, adjudicate the required row 393 regression against the exact CB168F/CB168G contract, confirm row 648/858 changes and all S observations, and decide what evidence is required for the new sphere cut-search stop and missing trace details. No automatic test edits, selector promotion, retry, product change or CB168 binding/CB169 authorization. Keep O47/C5, O48, O49/H4 and all other held obligations open until Review decides. Preserve 66/17/49, debt 1, deferred 81 and accepted CP2 authority as historical, not as a TB146 pass.
