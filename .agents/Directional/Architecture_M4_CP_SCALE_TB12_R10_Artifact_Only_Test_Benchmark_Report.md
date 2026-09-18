# M4-CP-SCALE-TB12-R10-EXEC — CB23 boundary-authority artifact-only Test + Benchmark report

**Turn:** `M4-CP-SCALE-TB12-R10-EXEC`
**Result:** **ALL GREEN / REVIEW REQUIRED / NOT YET PROMOTED**
**Immutable package:** artifact `10560828304`
**Semantic source:** `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff`
**Benchmark execution:** 0

## 1. Execution authority

The authoritative artifact-only run is GitHub Actions run/job `35382311474 / 105721178393`, event SHA `6a925df57ad89ff9f5224aa568f0ddd4a850674f`.

Frozen harness authority:

- Google Drive file `1BE8aLC5OEhBZGhrJ1Zd88eUhaiigeMdi`
- 18,542 bytes
- SHA-256 `e61ea1ced3936f2e0251d74816deb30a16835c9857fc0f5b50eaa85ef9f21e83`

Result/log artifacts:

- result `10562622856`, SHA-256 `57521f2ede071dc2087c2c265ef265308f215c8688653fb341681fdbdb2b8ab8`
- log `10562292934`, SHA-256 `907e5b8e6152414fa01d638a1f6546754ec7bd62c1f2422bd9b881bb0bf9afd3`
- final ledger SHA-256 `32c57323bc2d458ceb38226dd0d0517798e413b0a1a477dd0d4fc17f6d608559`

## 2. Immutable preflight and postflight

Preflight re-established the CB23 package exactly:

- provider/local artifact SHA-256 `e84692e13d6de3b7bec46d8d5433b6b1c196e451187d5fb3a0a3fd6bb1d47ea1`;
- self-excluding package manifest **28/28**, manifest SHA-256 `39e4dfa89c6203852b544395aad0651348f7d976110020b86a2a75968b2edff3`;
- source archive SHA-256 `7ad520fc87b184d04d2aa94b0a0f51782bbc6a6c7e95df92edfd84012788f83f` and semantic source `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff`;
- clean source-status receipts, executable modes `0755`, compile boundary `runtimeExecution=false`, and authoritative GMPXX + GMP link evidence;
- selector426 **426 rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; first425 SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; selector427 absent;
- retained genus-two OBJ/rawfield/metadata SHA-256 values `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

Postflight completed and package/source/execution-view censuses match byte-for-byte and mode-for-mode. The execution boundary records `orchestration_failure=false`, `semantic_red=false`, `postflight_complete=true`, `benchmarkExecuted=0`, and zero configure/compile/relink/discovery/repair/mutation activity.

## 3. Runtime result

The frozen 434-row ledger completed without RED, skip, selection mismatch, crash, timeout, or orchestration failure:

- Gate C0: **3/3 PASS**
- inherited Gate A: **4/4 PASS**
- production S5: **1/1 PASS**
- selector426: **426/426 PASS**
- total: **434/434 PASS**

The selector owner census remains **30 / 280 / 75 / 41** over authority-kernel / producer / completion / validation binaries.

The production S5 row reports exact genus-two topology `V=120,E=366,F=244,components=1,boundaryLoops=0,chi=-2,genus=2`, independent and production atlas hashes both `6035809732721064170`, and `a3Produced=true` with semantic/structural/debug hash `15065394778054153947`, `regionCount=14`, `arcCount=92`, `rotationCount=76`. The test terminates PASS while the production pipeline's deeper terminal state remains the expected typed `NotProductionReady` at `tracing`; this row's acceptance meaning is owned by Review.

Raw per-row logs retain each exact GoogleTest filter and process-reported runtime. The final ledger retains selected/skipped counts, exit code, output hashes, and raw-log path for every row.

## 4. Evidence-packaging note

The harness's redundant nested `evidence.tar.gz` creation emitted GNU tar's `file changed as we read it` warning, so the optional companion `evidence.tar.gz.sha256` was not produced. The authoritative GitHub result artifact itself has the verified provider/local SHA-256 above, and its root self-excluding `SHA256SUMS` verifies every retained result/raw/census file. The semantic run and immutable postflight completed before this redundant nested-packaging warning.

## 5. EXEC disposition

No new regression is observed by R10 EXEC. EXEC does not independently promote package `10560828304`, close R9 `RP-01`, change stable pricing, grant final S5/A3 checkpoint credit, or alter selector authority. Accepted runtime authority therefore remains TB11 package `10473134357` / selector426 **426/426** pending mandatory independent Review.

Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. `M4-CP-SCALE-TB12-R9-EXEC-CAND-01 / RP-01 AUTHORITY_DOMAIN_CONFLATION` remains open until Review adjudicates the all-green recovery evidence.

Exact successor: **`M4-CP-SCALE-TB12-R10-REV`**.
