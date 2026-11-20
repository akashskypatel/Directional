# TB150 — slide-interior cut position, immutable Test + Benchmark (2026-11-20 UTC)

## Situation

**Full gate PASS: 964/964; accepted prefix 491/491.** The complete independent comparison is **963/963 MATCH TB149** under frozen N1–N3. The separate three-case census is **3/3 MATCH TB149 under N1–N4** (Cylinder PASS; BunnyRandom and Vase expected RED). This closes the frozen TB150 test gate, **not** CP3, selector497, D0, H4 or the sphere cut-graph residual.

## Background — immutable authority

| Item | Verified evidence |
|---|---|
| Exact semantic source | `041bde764365710e6d5148c43751da91205ffd35` (CB168L); no source/test/fixture changes in TB150 |
| Compile-only source package | `14608341511`, ZIP SHA-256 `d189282ce898af54c3cb48d2eaa47107ebaaf36ca2d0afcaec9689dec926084b`; 28/28 packaged hashes, GMP/GMPXX compile-only, no rebuild |
| Frozen full gate | `.agents/Directional/gates/Architecture_M6_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Case_Manifest.tsv`, SHA-256 `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`; 964 required + 81 deferred |
| Frozen census | `.agents/Directional/gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; 3 cases |
| Artifact-only harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Source snapshot | [run 44692186639](https://github.com/akashskypatel/Directional/actions/runs/44692186639), source `19ca58bf84f7e31271b078dd135c6b2bf8609636`, artifact `14608653925`, 5631/5631 hashes |
| Gate request/run | `m6-cp3-tb150-gate-20261120-v1`, commit `ec902c7f33bcb2be2d7b6d87b0d671164ecbe4b6`; [run 44692445950](https://github.com/akashskypatel/Directional/actions/runs/44692445950), artifact `14609657696`, ZIP SHA-256 `9e2117dc4bf4d5e097beeaa90236b1c44ceafdba90bc3fd4751ef2cd2472874f` |
| Census request/run | `m6-cp3-tb150-census-20261120-v1`, commit `cb9a919dbfd1ffaa08e1a59327deea9ebbeb3365`; [run 44692570324](https://github.com/akashskypatel/Directional/actions/runs/44692570324), artifact `14610319026`, ZIP SHA-256 `b5033d6939a14ce8716455f5dd5f6f20d15087b2ae229c8c646c96052c68225c` |
| TB149 gate baseline | Artifact `14604413703`, ZIP SHA-256 `b9d0ff8746070c2d0928f8ac0647aa5bc0f5add542691b51932a6d85c0c1a621` |
| TB149 census baseline | Artifact `14606235652`, ZIP SHA-256 `20534de76bd51ffa22bd5cb478b869adb760959139ef025cbf0e53cc531a5f94` |

## Assessment — gate

- All workflow schema, request, runtime and mailbox jobs succeeded. The immutable ZIP has **1,936/1,936** valid indexed SHA-256 hashes. `planned=executed=passed=964`, `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `membership=1045`, `postflight=true`, `exit=0`. `compile=false`, `relink=false`, `configure=false`, `benchmark=false`.
- Required rows **960 and 964 PASS**. The new row asserts exact slide-interior cut behavior, including reversed slides and negative controls. The preexisting **491 accepted-prefix** cases PASS.
- All older 963 ledger rows match TB149 in identities, binary names, tests, verdicts, failure types and control fields. Independent raw-log comparison yields **963/963 MATCH** under frozen **N1 (Google Test durations), N2 (line endings), N3 (complete M3 `region_support_projection` records as counted multiset, remaining lines ordered)**. No additional mask was introduced. There are **1,738** M3 records. All **504** `slideContactArrival` lines on 21 rows are preserved and equal; no deletion or new normalization was used.
- The gate makes no product geometry change. The production graph still emits slide chords until EPO-3 and the CB169 piece-path cutover. Row686 remains χ6 versus sourceχ2 (+4) and rows669/698 still report `CutSearchExhaustedBeforeCellularity`, unchanged from TB149.

## Assessment — census

- Separate immutable census ZIP has **9/9** valid indexed hashes and `planned=executed=3`, `passed=1`, `red=2`, no abnormal/missing/skipped/duplicate/control error, `postflight=true`, `exit=0`; no compile/relink/configure/benchmark.
- **3/3 MATCH TB149** under frozen **N1–N4**: Cylinder PASS, BunnyRandom RED and Vase RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. N4 masks only the two 16-byte `GetParam()` address records in each of the two parameterized RED cases (four occurrences). These bytes are process-address variation and not test results. No other content was excluded. All verdicts and typed failure fields match.

## Regression/accounting and recommendation

No new stable regression is established. The unchanged BunnyRandom/Vase RED cases remain deferred observations, and O47/C5 remains open pending EPO-3 and the CB169 cutover. Stable totals remain **66 events / 17 categories / 49 recurrences**; one produced-witness debt and **81 deferred**. CP2 acceptance 491/491 remains; do not promote CP3 selector497, D0, row858 or deferred production gates.

**Next authorized turn:** `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-REV` (independent Review). The Review must reopen immutable evidence and freeze only the supported exact EPO-3 binding Code + Build step (`sourcePieceCounts`, exact validator, all-ones inert producer) and its Test + Benchmark. No successor work was performed in TB150.
