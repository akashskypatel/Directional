# M4-CP2-TB2 Test + Benchmark Report

**Turn:** `M4-CP2-TB2-EXEC`
**Status:** **COMPLETE / ORCHESTRATION-INVALID / NO SEMANTIC CREDIT / PACKAGE117 IMMUTABLE**
**Date:** 2026-09-10 UTC

## 1. Frozen authority and execution identity

TB2 consumed only immutable candidate package117 from semantic source `534c0d41ae05b31e66711f21f4b4280b59f6483f`.

- package artifact: `10172820820`
- package artifact name: `directional-m4-cp2-cb2-package117-result-34529050994`
- package ZIP SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`
- selector382 SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`
- accepted selector373 prefix SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`
- selector380 prefix SHA-256: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`
- TB2 run/job: `34532107988 / 103055098832`
- TB2 result artifact: `10174031432`, SHA-256 `7742a385e5f2f0b408a5a946a836915abf1a636057d7b3fe0c6612f6dce88a44`
- TB2 diagnostic-log artifact: `10174032131`, SHA-256 `d15ecf14508eb49a154bb443df184de0daf892e9d99635d369f1d0f9d283278b`
- workflow event/control SHA: `2c37042b380ae8cc877fcb0f2d8c146e6a5efc5e`

No configure, compile, relink, generated discovery, package/mode repair, benchmark, or source/test/fixture/selector mutation was authorized or performed.

## 2. Preflight result — valid

Artifact-only preflight completed successfully before any test process started. It verified the exact package metadata and provider digest, all **28/28** package `SHA256SUMS` entries, semantic-source identity, clean packaged source-status receipts, compile/preflight exit `0`, GMP/GMPXX boundary evidence, packaged source archive, selector382 exact row count/hash and frozen 373/380 prefixes, executable hashes/modes, fixture resolution, and the exact static owner partition:

- authority-kernel: **30**
- producer: **236**
- completion: **75**
- validation: **41**

The package, extracted source, and package-derived execution view were staged without repair.

## 3. Runtime process observations — audit-only, not acceptance evidence

The invalid attempt did execute the frozen process set before the postflight orchestration failure. These observations are preserved only to diagnose the attempt and **receive no semantic gate credit**.

- focused phase A, exact ordinals 374/381/382: **3/3 process PASS**
- focused phase B, exact ordinals 374/381/382: **3/3 process PASS**
- focused verdict vectors: identical
- ordinal374 required success receipt: exactly **1** occurrence in each focused raw log
- cumulative selector382 process loop: **382/382 process PASS**
- accepted predecessor rows 1-373: **373/373 process PASS**
- CP2 rows 374-380: **7/7 process PASS**
- correction rows 381-382: **2/2 process PASS**
- process owner outcomes: **30/30 / 236/236 / 75/75 / 41/41**
- RED: **0**; SKIP: **0**; timeout: **0**; selection mismatch: **0**
- raw process logs: **388** total — 6 focused plus 382 cumulative; each independently audits to one intended `[ RUN ]`, one `[ OK ]`, no `[ SKIPPED ]`, and no `[ FAILED ]`

The generated `semantic-summary.json` records those process observations, but it is not semantic acceptance authority because the required postflight did not complete.

## 4. Deterministic orchestration failure

The attempt failed after the 382nd cumulative process because the two frozen harness halves used different names for the execution-view preflight census:

- preflight wrote `execution-view-before.tsv`;
- postflight required `execution-view-census-before.tsv`.

The postflight therefore raised:

`[Errno 2] No such file or directory: '/home/runner/work/_temp/m4-cp2-tb2-result/execution-view-census-before.tsv'`

The workflow recorded `preflight_exit=0`, `gate_exit=90`, and terminated the execute job as failure. This is a deterministic **orchestration failure**, not semantic RED. Re-running the unchanged harness is prohibited.

`execution-boundary.txt` was emitted before the exception handler completed and therefore retained `orchestration_failure=false`; that field is not the attempt-classification authority. The explicit `failure.txt`, workflow-level `gate_exit=90`, and failed job conclusion control the classification.

## 5. Independent immutability audit

The invalid attempt nevertheless preserved enough raw evidence to establish that package117 itself was not mutated and may be reused by a corrected harness. The actual before/after census files are byte-identical:

| surface | before/after SHA-256 |
|---|---|
| package | `c45c423e7365887ccc5ef5974d1c61c32c775e9b064d41e47709500721d6938d` |
| extracted source | `67726528d5e31765005b1fee3360acfed9d23958a754a71aaa62d5ff7507cee2` |
| execution view | `1a5b1de75f2c9ae27c28ea77509e57b5e8c4565a2dd537b789cef03f98505f02` |

For the execution view, the identical files are `execution-view-before.tsv` and `execution-view-census-after.tsv`. This independent audit justifies **reuse of the same immutable package117** after correcting orchestration. It does not rehabilitate this attempt or convert its audit-only process observations into semantic evidence.

## 6. Retained evidence hashes

- `identity-map.tsv`: `0698616f9b357e60616351da8a52ec553ef9c8b52dd230fb6062fe7566de23f7`
- `full-ledger.tsv`: `f0b318dcad0831b3b8ac66179a5fcf70236fe6f40a15aa12965309878a3c6bff`
- `focused-a-ledger.tsv`: `3649dc4a1c5c1cce80c66e1449795e51f156a1bc64cd1cd25a5568e7464944f9`
- `focused-b-ledger.tsv`: `954fec5347f6d3648003af1513f0a2f23a527ba762e5150699bc68e6c15f867c`
- `ordinal374-receipt-audit.tsv`: `095e83b9581aee5ee83eb67399aa743681e411dd7f07541c1c89ef3e161e754f`
- `semantic-summary.json`: `768a1b4cce3ee36f0108b4a5ca28861812fcc2a1888d551b7636abf3eec7d7d9`
- `execution-boundary.txt`: `d4c0f5f65a56f93d7caa562a74fd5df2da50e4afff6fbba2def9bddf6b32b450`
- `workflow-boundary.txt`: `376dede73067cce31631998e135b45d3dd22c031e9e9b5d84f4dc5549db2a2a4`
- `package-sha256-check.txt`: `29cb47e6038122b983d4ed9127d7d373d4498a34485d2d3eeb334bacb1e35928`
- `preflight.txt`: `1e2205dcdea8aa511d5fc6a623e0ce8a6d4523ba663e1201c2e50fb3b32978c8`
- `failure.txt`: `d838bf44e31d268e161331fcbf626eaba3294850443e3b0f081df05e806c1d2a`

## 7. Classification and accounting

**`M4-CP2-TB2-EXEC-CAND-01` — OPEN / ORCHESTRATION / NON-STABLE / HARNESS POSTFLIGHT RECEIPT-NAME MISMATCH / OWNER `M4-CP2-CB3`.**

This candidate does not identify a product, test, fixture, selector, or package semantic regression. It adds **+0 events / +0 categories / +0 recurrences**. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted package authority **115**. Package117 remains immutable candidate evidence and is **not promoted**.

## 8. Disposition

`M4-CP2-TB2-EXEC` is formally complete as an **orchestration-invalid attempt with no semantic credit**. The exact successor is runtime-free, control-plane-only **`M4-CP2-CB3`** under `Architecture_M4_CP2_CB3_Orchestration_Correction_Plan.md`.

CB3 must correct only the evidence-harness filename contract and must not modify product source, test definitions, fixtures, selectors, CMake/build semantics, or package117. It does not compile/repackage and does not execute Directional runtime. After CB3, the frozen TB2 gate is re-executed as `M4-CP2-TB2-R1-EXEC` against the same immutable package117 artifact `10172820820`.
