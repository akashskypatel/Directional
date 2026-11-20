# TB147 — mutual carrier-end oracle full gate and three-fixture census (2026-11-20 UTC)

## Situation

**Full gate PASS (962/962), accepted prefix PASS (491/491).** The exact CB168I package was tested in [GitHub run 44651403984](https://github.com/akashskypatel/Directional/actions/runs/44651403984). After the full gate passed, the frozen three-case census ran in [GitHub run 44654270153](https://github.com/akashskypatel/Directional/actions/runs/44654270153). The census had 1 PASS and 2 expected RED among 3 cases. No code, test, fixture, selector, compilation, configuration, or relink operation was performed in either Test + Benchmark workload. This green *test gate* is not CP3, selector 497, or D0 production acceptance.

## Background — immutable source and evidence

| Evidence | Verified authority |
|---|---|
| Semantic source | `0f738b1c6d3971c1e414039623336d1baa7965d1` (CB168H+CB168I) |
| Compile-only package | `14589748220`; ZIP SHA-256 `5c74512cdc1cef967ee2968a7055b3323722298259170cae3cc74b8755864bb0`; 28/28 package checksums and exact GMP/GMPXX build authority |
| Exact executor snapshot | `d47e79fecb63174886cfebad1957c9df53ff7df6`; snapshot artifact `14589668879`; 5,615/5,615 file checksums |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`; SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Frozen gate input | 962 rows, SHA-256 `aa9911870a7514ea5674f869e74d8681f1ad0fcc8a14f43096b8da4f5210b61f`; 81 deferred, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Gate run and result | Run `44651403984`, artifact `14590664543`, outer ZIP SHA-256 `4fe8ddd8ab64669940fad176499cd77a739c798df7a931111fcd6ad5218ed372`; 1,932/1,932 indexed hashes and 962/962 raw-ledger hashes valid |
| Census manifest | Three rows, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Census run and result | Run `44654270153`, artifact `14591964172`, outer ZIP SHA-256 `0c2e484363af24e297cf35b78117ca71befc0d490ae34e97972a049b102498ac`; 9/9 indexed hashes and 3/3 raw-ledger hashes valid |
| Reference | TB146 gate artifact `14569832286`; TB145 census artifact `14510118951`; both independently verified |

## Assessment — full gate

- Test accounting: 962 selected, 962 executed, 962 PASS, 0 RED, 0 skipped, 0 abnormal, 0 missing, 0 duplicate, 1043 selected-plus-deferred membership; `postflight=true`.
- Required oracle rows **393 / 961 / 962 all PASS**. The accepted 491-row prefix is 491/491 PASS. The other 961 rows match the TB146 frozen comparison after removal of *only* the new `FieldAlignedCurveNetwork.slideCoincidence` lines. The comparison preserves typed outcomes and sorts complete M3 records as frozen in N3. The M3 diagnostic prefix was never doubled.
- Row 393 prints exactly four directed `SphereMutualCarrierEnd` receipts: 4→6 and 6→4 on node 9, and 15→19 and 19→15 on node 10. Each record has seven committed segments, end index seven, a shared exact edge parameter `574181338608147/4503599627370496`, and `roles=Terminal,Terminal`. The reciprocal face records are different charts of the same source edge. The test independently asserts the unchanged 24-trace and other original properties; no generic index weakening was made.

```text
SphereMutualCarrierEnd trace=4 segments=7 struck=6 struckIndex=7 face=(0,1,2) carrier=(0,2) parameter=574181338608147/4503599627370496 node=9 roles=Terminal,Terminal
SphereMutualCarrierEnd trace=6 segments=7 struck=4 struckIndex=7 face=(0,2,3) carrier=(0,2) parameter=574181338608147/4503599627370496 node=9 roles=Terminal,Terminal
SphereMutualCarrierEnd trace=15 segments=7 struck=19 struckIndex=7 face=(25,27,28) carrier=(25,27) parameter=574181338608147/4503599627370496 node=10 roles=Terminal,Terminal
SphereMutualCarrierEnd trace=19 segments=7 struck=15 struckIndex=7 face=(25,26,27) carrier=(25,27) parameter=574181338608147/4503599627370496 node=10 roles=Terminal,Terminal
```

### Slide-coincidence census and residual classification

There are **480** additional diagnostic records across the 20 sphere rows, containing exactly four unique carrier/parameter pairs (120 copies per pair). All four report `movingInSlide=0`, `wallInSlide=1`, and `faces=same`. There are **zero** observed different-face slide coincidences. These measurements **do not support** the RA-268 S3 prediction that different-face slide contacts explain the residual of four. The remaining vertex-meeting hypothesis has not been established by this test and must be independently investigated in the review. Do not change the producer or classify the residual as solved.

| Copies | Exact slide record |
|---:|---|
| 120 | `FieldAlignedCurveNetwork.slideCoincidence moving=17:8 wall=0:6 carrier=(6,8) parameter=4038890029339747/4503599627370496 movingInSlide=0 wallInSlide=1 faces=same` |
| 120 | `FieldAlignedCurveNetwork.slideCoincidence moving=20:8 wall=1:6 carrier=(16,21) parameter=4038890029339747/4503599627370496 movingInSlide=0 wallInSlide=1 faces=same` |
| 120 | `FieldAlignedCurveNetwork.slideCoincidence moving=5:8 wall=21:6 carrier=(33,34) parameter=1009722507334937/1125899906842624 movingInSlide=0 wallInSlide=1 faces=same` |
| 120 | `FieldAlignedCurveNetwork.slideCoincidence moving=8:8 wall=22:6 carrier=(45,46) parameter=464709598030749/4503599627370496 movingInSlide=0 wallInSlide=1 faces=same` |

Per-row counts, with no invalid parse or different-face entries:

| Sphere gate row | Raw lines | Different-face | Unique records |
|---:|---:|---:|---:|
| 380 | 36 | 0 | 4 |
| 388 | 36 | 0 | 4 |
| 393 | 24 | 0 | 4 |
| 394 | 28 | 0 | 4 |
| 396 | 28 | 0 | 4 |
| 397 | 24 | 0 | 4 |
| 644 | 12 | 0 | 4 |
| 645 | 12 | 0 | 4 |
| 648 | 12 | 0 | 4 |
| 669 | 52 | 0 | 4 |
| 686 | 12 | 0 | 4 |
| 691 | 24 | 0 | 4 |
| 693 | 12 | 0 | 4 |
| 694 | 36 | 0 | 4 |
| 698 | 36 | 0 | 4 |
| 699 | 24 | 0 | 4 |
| 700 | 36 | 0 | 4 |
| 843 | 12 | 0 | 4 |
| 844 | 12 | 0 | 4 |
| 858 | 12 | 0 | 4 |

### Observed sphere cut-graph issue remains

- Row 686 independent actual-graph oracle: **V=18, E=30, F=18, c=1, chi=6, sourceChi=2**. Its 18 face components are disks. The difference `chi − sourceChi = +4` remains unchanged from TB146. This is not an accepted cellular partition.
- Rows 669/698 still report `CutSearchExhaustedBeforeCellularity`, with 24 network traces, 56 network events and 10 terminal trace intersections. There is no new authoritative source-edge locus for the exhaustion.
- The complete original diagnostic lines from rows 686, 669, and 698 are preserved byte-for-byte in [the separate evidence record](evidence/Architecture_M6_CP3_TB147_P13_Sphere_And_Census_Verbatim_Evidence_20261120.txt), SHA-256 `3c16fd5cf6c5b1f52e39b3fec705c58fb6c1c12dd0a5fdbb14010b9769803559`, plus the immutable gate result ZIP. No lines have been truncated or reclassified.

## Assessment — three-fixture census

| Census row | Identity | Recorded result | First failure |
|---:|---|---|---|
| 1 | offgate:362 | PASS | failure-line-not-observed |
| 2 | offgate:360 | RED | ../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:493: Failure |
| 3 | offgate:365 | RED | ../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:493: Failure |

- Census execution accounting: 3 selected, 3 executed, 1 PASS, 2 expected RED, 0 skipped, `postflight=true`. Expected non-green fixtures remain measurements, not production acceptance.
- Baseline comparison to TB145, with only new slide-coincidence lines removed: **3/3 MATCH**. No census mismatch found.
- Additional census slide records:
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=126:4 wall=148:0 carrier=(411,498) parameter=3997861012088939/4503599627370496 movingInSlide=0 wallInSlide=1 faces=different`
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=151:8 wall=101:0 carrier=(338,339) parameter=3988540168889131/4503599627370496 movingInSlide=0 wallInSlide=1 faces=same`
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=152:2 wall=148:0 carrier=(411,498) parameter=1043088501491663/4503599627370496 movingInSlide=0 wallInSlide=1 faces=different`
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=15:19 wall=43:13 carrier=(94,210) parameter=1185534258113431/4503599627370496 movingInSlide=1 wallInSlide=1 faces=same`
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=26:1 wall=99:0 carrier=(302,349) parameter=348952146602893/2251799813685248 movingInSlide=0 wallInSlide=1 faces=different`
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=33:3 wall=24:1 carrier=(48,271) parameter=1416707846882431/2251799813685248 movingInSlide=0 wallInSlide=1 faces=different`
- Census row 2: 3 × `FieldAlignedCurveNetwork.slideCoincidence moving=87:0 wall=142:2 carrier=(280,411) parameter=952111344332611/4503599627370496 movingInSlide=1 wallInSlide=0 faces=different`
- Exact full per-case logs and stable failure evidence remain in the immutable census artifact; historical Cylinder/trace82 and Vase obligations are carried unless fully observed.

## Recommendation — independent review only

The authorized successor is `M6-CP3-TB147-P13-MUTUAL-CARRIER-END-ORACLE-FULL-GATE-REV`. It must assess the unchanged +4 sphere residual and the same-face-only slide census. A vertex-meeting receipt is an unproven next producer candidate, **not** authorized here. Stable regression 66 events / 17 categories / 49 recurrences, produced-witness debt one, and 81 deferred remain unchanged. Historically accepted CP2 491/491 is unchanged. CP3, selector497 and D0 remain unpromoted. H4/O49, O48, FC-6, H2 and terminal-cut remain held by prior authority.
