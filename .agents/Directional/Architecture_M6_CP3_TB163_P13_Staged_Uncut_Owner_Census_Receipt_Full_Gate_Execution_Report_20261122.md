# TB163 — staged uncut-owner census receipt: immutable Test + Benchmark execution

## Situation

The TB163 full gate **PASSED 979/979** against the immutable CB-180 package. Independent local comparison against TB162 found **zero differences** outside the frozen N1–N3 normalization and exactly the five row-979-only new diagnostic families. This is a diagnostic result, not a source-owner repair, validated production output, or CP3 promotion.

## Background

- Exact turn: `M6-CP3-TB-EXEC-163-P13-STAGED-UNCUT-OWNER-CENSUS-RECEIPT-FULL-GATE`. Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 stays draft, unmerged.
- Immutable source: `23d66f60d87329e178d9fc3963489cbef088555e`. CB-180 GMP/GMPXX compiled package: artifact `14749353214` from compile [45010876980](https://github.com/akashskypatel/Directional/actions/runs/45010876980); outer ZIP SHA-256 `fdcba4479936b7e8b1d3ee955bd1ac069715f4fa513ec874bc4e535a8872a668`; prior package check: 28/28 files.
- Unchanged TB161 gate manifest: `.agents/Directional/gates/Architecture_M6_TB161_P13_Staged_Slide_Entry_Stop_Downstream_Receipt_Full_Gate_Case_Manifest.tsv`, SHA-256 `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`; deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Dispatcher request `m6-cp3-tb163-gate-20261122-a`, trigger commit `571f9542d8577e9470949d09d2d36bc193c80994`. [Execution 45012486246](https://github.com/akashskypatel/Directional/actions/runs/45012486246), result artifact `14750681733`, ZIP SHA-256 `ed9112f827ae22cea3f80fb32e32594d6a332da30946e0c6fded00e0ae56461e`; 1966/1966 internal SHA-256 records verified. All validation, parse, runtime, and mailbox jobs succeeded.
- Comparison reference: TB162 result artifact `14746794132`, ZIP SHA-256 `92c4420abe82ed0dae8476de609454f89fcf8a86f2846bb219d53516f78e64e2`; 1966/1966 internal SHA-256 records verified. Frozen comparator authority: [TB-REV-162 adversarial review](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), N1–N3 plus five approved diagnostic prefixes.

## Assessment — measured results

| Gate | Measured evidence |
|---|---|
| Complete gate | **979/979 PASS**, 0 RED / abnormal / missing / skipped / duplicate |
| Accepted CP2 prefix | **491/491 PASS**; same identities and results as TB162 |
| Gate membership | 1060/1060 byte-identical; 81 deferred unchanged |
| Row identities and non-hash ledger fields | 979/979 equal to TB162; all 979 raw logs bind to their own SHA-256 ledger values |
| Rows 1–978 | 978/978 equal after only N1–N3; zero exceptions |
| Row 979 | 60/60 old `SphereStaged*` lines present verbatim in original order |
| Row 979 new diagnostics | **48**: `SphereStagedUncutCensus` 2; `SphereStagedUncutBoundary` 16; `SphereStagedArc` 30; `SphereStagedUncutInteriorArc` 0; `SphereStagedUncutVertexTransit` 0 |
| Raw full-log byte equality | 755/979 rows; other differences normalize only as authorized |
| N3 complete record population | TB162 1750, TB163 1750 |
| Execution boundary | artifact `14749353214`, exact source, postflight true, exit 0, configure/compile/relink/benchmark all false |
| Production census | **Not run**; last TB161 census artifact `14741883606` stays authoritative |

Exact row-979 candidate raw SHA-256: `19480a0c684f16d1cde6e4f3555298ebb59d7bb17a1d767693ea3ff79d335394` (verify against ledger). All new diagnostic lines are retained **verbatim** in [TB163 raw receipt](evidence/Architecture_M6_CP3_TB163_P13_Staged_Uncut_Owner_Census_Receipt_Raw_20261122.txt). Comparison was performed using the independent archive-and-raw-ledger verifier, which checked 1,966 file hashes for each archive, 979 row hashes and identities, the N1–N3 normalized log equivalence and the new-prefix-only row-979 allowance. The comparator found no mismatches.

**Evidence-only observation:** both seedless uncut components (1 and 5) have eight faces, eight boundary edges, zero interior arcs, zero vertex transits, zero seed attributions, and `status=1`. All 16 listed boundary edges say `barrier=0 oppositeTraceCut=1 sideOwner=1`; each opposite face publishes a multi-orbit record, not a proved unique component owner. This is *not* yet a classification into R-a or H5: the decision-map signature for R-a requests `sideOwner=0`, while the H5 alternatives require all barriers or an interior unequal-orbit arc. A separate Review must independently classify the printed evidence and may issue a typed STOP when neither prescribed branch is proved. No owner is invented.

**Regression classification:** no newly observed RED case, PASS-to-RED transition, product mutation or stable regression. The same staged source-face owner obligation H1/H5 remains a **non-stable candidate** for Review; stable totals remain **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. Production sphere still stops at `CutSearchExhaustedBeforeCellularity` and `sourceFaceCellularity=0`; staged row 979 still reports `UncutFaceComponentOrbitSeedNotUnique` at `2-5-12`. CP3/497/D0/H4 are not promoted.

## Recommendation

Next *separate* turn: `M6-CP3-TB-REV-163-P13-STAGED-UNCUT-OWNER-CENSUS-RECEIPT-FULL-GATE`. Verify the complete 48-line raw receipt and apply the frozen [TB-REV-163 decision map](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md#tb-rev-163-decision-map) without assuming either repair. Require independent source-authoritative proof before any CB-181/CB-182 plan. Do not change source, tests, selector, manifest, production switch, or acceptance criteria during TB163.
