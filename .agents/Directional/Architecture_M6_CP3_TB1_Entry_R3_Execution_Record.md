# M6-CP3-TB1-ENTRY-R3-EXEC — artifact-only frozen 497 execution record

**Turn disposition: execution mechanically COMPLETE; candidate REJECTED / UNPROMOTED (403 PASS, 94 RED); independent `M6-CP3-TB1-ENTRY-R3-REV` mandatory before repair or promotion.** Observations are provisional; EXEC does not adjudicate stable-event identity or alter the frozen ledger (64 events / 17 categories / 47 recurrences, produced-witness debt 1).

## Immutable candidate, exact trigger, and evidence

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 remains unmerged. Candidate source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`.
- Validated eight-target GMP/GMPXX compile run `38029281891`; candidate artifact `11661566000`, ZIP SHA-256 `18591009acf98b4c6ea996bc4bb1445959bbd49b1f96cc78327caacfb302ac95`; package `SHA256SUMS` SHA-256 `849796ea9a72c00ee9ab9583ff555638b3b56c2f72884e45337b2ad006752931` (28/28 checks both before and after TB); embedded source tar SHA-256 `0b2535eb0b0096f759139850f7a367319a4edb475d303654a9e5f549c764490d`.
- Exact harness `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh`, SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`; executor SHA `b7fd0dff5676b994eb4e8b04ded15a7a620c24a6`. Exact snapshot workflow `38030076112`, artifact `11661328757`, provider ZIP digest `a115cd1bd6fbecb80bc10c0be45e0a38af1394d8e82f379f9daf6ea8ad5070cc`, verified 5816/5816 source hashes. Compare from candidate semantic source to executor reports no semantic/harness/selector changes.
- Durable dispatcher event `589a48db9627eee8288e0a4e0a3cbbbf3c0be92c`, mailbox `m6-cp3-tb1-r3-frozen497-exec-r1`, workflow run `38030196207`, runtime job `114149383653` SUCCESS; result artifact `11661044443` ZIP SHA-256 `555b973a69810f95a2f170fdea30aac11c0805ba7e25bc9914577bdd1bb26ac5`, companion log artifact `11661319224`. Result self-manifest passes **1019/1019** entry checks; `execution-boundary.txt` confirms `--execute`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, all postflight package/source/execution-view and selector/routing integrity checks true. `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `generated_discovery=false`, `package_repair=false`, `mode_repair=false`, `source_test_fixture_selector_mutation=false`, `retry_after_runtime_start=false`.
- Exactly **497 unique fresh process executions**, exactly one selection and zero skips for every identity: focused30 **15 PASS / 15 RED**, focused12 **10 / 2**, selector449 **378 / 71**, CP3entry6 **0 / 6**. Aggregate **403 PASS / 94 RED**. 449 routing receipt order and binary-owner counts 301 producer / 75 completion / 41 validation / 32 authority match the frozen selector; no benchmarks. Frozen `497=30+12+449+6` unchanged.

## Complete RED identity inventory and comparison to R2

- `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`: every **94** RED once, with group/ordinal/test name/owner/exit/raw SHA-256, raw first-observable failure excerpt, **provisional-only** group, R2 prior-RED flag, CP2 previously-accepted flag, and old R2 candidate label. SHA-256 `890a105e73ab686c47aa463cb8db6807169d439ff5c221c3bfd8d59488c106f8`.
- `Architecture_M6_CP3_TB1_Entry_R3_R2_Identity_Comparison.tsv`: identity-exact comparison for all **53** R2 RED cases, including all **47** formerly CP2-accepted, with R1/R2/R3 results. SHA-256 `e2b445b75fcbe213c42e80fba9b7b0f3859808fa5bcabc24a85b05e211468a44`. **0/53 recovered; 0/47 formerly accepted restored; 41 new RED identities beyond R2**. R3 regresses from R2's rejected **444 PASS / 53 RED** to **403 PASS / 94 RED**. This comparison is identity-based, not ordinal-only.
- All 6 CP3 entry obligations RED, including nonconstant HardRail route, odd A3 τ witness, seam/cross-sheet witness, A5 chart barrier, and global-label independence. No organic produced witness or R2 acceptance restoration is claimed.

## Provisional first-observable groups (not stable root-cause dispositions)

| First observable diagnostic category | RED count |
|---|---:|
| `A4_ROUTE_CERTIFICATE_REJECTION` | 39 |
| `A4_NOT_PRODUCED_UNTYPED` | 22 |
| `A4_INVALID_FINAL_CELL_STATE` | 14 |
| `DCEL_FIXTURE_CONSISTENCY_EXCEPTION` | 7 |
| `ORGANIC_ODD_TAU_WITNESS_ABSENT` | 5 |
| `A5_OCCURRENCE_ISOLATION_REJECTION` | 4 |
| `A5_ISOLATION_SEAM_EQUIVALENCE_REJECTION` | 2 |
| `OTHER_FIRST_PREDICATE` | 1 |


The 39 `A4_ROUTE_CERTIFICATE_REJECTION` records include the concrete `InvalidHardRailRouteCertificate` first predicate `endpoint-0;locus=3;rail=2;...;currentFace=0;expectedFace=2;routeLength=1;edge[0]=1,4:faces=0,3`, not independently proven new defect causation. Odd τ witness search reports `sourceA3Candidates=5`, `sourceFaceGaugePairs=5`, `oddFaceGaugePairs=0`. Seven newly RED identities throw `compute_edge_quantities(): DCEL consistency check failed` before intended authority assertions. Other first observables include `InvalidFinalCellState`, baseline phase-front not produced, A5 occurrence-mismatched isolation, and absent A6 arrangement; see per-row raw evidence. **Do not infer all failures share one root**, reclassify as new stable events, or claim RA-40 source-binding caused these failures without independent tracing.

## Required next turn and stop boundaries

1. `M6-CP3-TB1-ENTRY-R3-REV`: independently verify 497/497 exact-one ledger, 1019 self-manifest hashes, raw evidence and 47 lost CP2 acceptances; adjudicate the 94 provisional first observables and distinguish production, oracle, fixture, and cascaded effects. Track all 41 newly RED identities independently and attribute any stable events only on evidence.
2. Do not modify source/tests/selectors, relaunch 497, or initiate repairs/promotion in this completed TB execution turn. R3 candidate REJECTED / UNPROMOTED; CP3/CB2/optimizer held until independent Review and an explicitly authorized successor repair turn.
3. RA-40(C) four supplemental tests remain **unexecuted** and **outside frozen 497**. They require separate, separately counted diagnostic-only turn, no acceptance credit; do not roll them into the gate.
4. Preserve stable totals 64/17/47 and debt 1 pending Review. No test result supports ledger repricing in EXEC alone.

Report generated 2026-10-10 06:20Z. Snapshot authority/binary inputs are immutable; historical prior-plan sections are retained as history, not newer proof.
