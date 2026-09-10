# M4-CP2-TB2-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP2-TB2-R1-EXEC`
**Status:** **COMPLETE / MEASURED GREEN / IMMUTABLE POSTFLIGHT GREEN / REVIEW PENDING / PACKAGE117 UNPROMOTED**
**Date:** 2026-09-10 UTC
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`

## 1. Frozen authority

This execution consumed the unchanged package117 candidate frozen by CB2 and carried through CB3:

- semantic source: `534c0d41ae05b31e66711f21f4b4280b59f6483f`;
- package117 artifact: `10172820820`, `directional-m4-cp2-cb2-package117-result-34529050994`;
- package ZIP/provider SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`;
- selector382 SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- accepted selector373 prefix SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- selector380 prefix SHA-256: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- expected owner partition: **30 authority-kernel / 236 producer / 75 completion / 41 validation**.

No configure, compile, relink, package repair, chmod/mode repair, generated discovery, source/test/fixture/selector mutation, or benchmark was authorized or performed.

## 2. Corrected harness authority

CB3 corrected exactly the invalid attempt's preflight census basename. R1 used:

- corrected preflight SHA-256: `12090d4b5e01f6c3e55de712b595dff3444b509ba58b040201a2c61f87d805c1`;
- byte-identical executor SHA-256: `717a4dd6cda5ba96fb8bd6e16879c422f9b2e1ff561951801dc5658d85480019`;
- frozen caller draft/published bytes: `baf81bf788f6823d79f3b34431424a1e19e7e45b6eacb6fb788604333a08d6ab`.

The preflight wrote `execution-view-census-before.tsv`; postflight read that exact file and produced `execution-view-census-after.tsv`. The prior no-credit run `34532107988 / 103055098832` was not stitched into this retry.

## 3. Exact execution evidence

- workflow run/job: `34539783373 / 103079623871` — **SUCCESS / SUCCESS**;
- exact workflow event SHA: `ee63f438ccd258092fedac0a27f0955a1c066ea4`;
- result artifact: `10176889758`, `directional-m4-cp2-tb2-r1-result-34539783373`, SHA-256 `51d16f992fe7784ac8fcc4db64868823108c147e92fa71acfdf97f73c001e5b0`;
- diagnostic-log artifact: `10176890045`, `directional-m4-cp2-tb2-r1-log-34539783373`, SHA-256 `b4a1e0fa555de319a816fffb6aa84b370a7b18862ad107a08a65b48aa37a56d6`;
- preflight: `preflight_exit=0`, package checksums **28/28**, selector rows **382**, owner partition **30/236/75/41**;
- semantic gate: `gate_exit=0`;
- execution boundary: `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `selection_integrity=true`, `orchestration_failure=false`.

The workflow boundary explicitly records `generated_discovery=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `package_repair=false`, `mode_repair=false`, and `benchmark_execution=false`.

## 4. Focused correction phases

The frozen focused sequence 374, 381, 382 was executed twice, one exact identity per fresh process.

| Phase | 374 | 381 | 382 | Result |
|---|---|---|---|---|
| A | PASS | PASS | PASS | **3/3** |
| B | PASS | PASS | PASS | **3/3** |

The verdict vectors are identical. Each ordinal374 raw log contains exactly one required source-derived receipt:

`M4_CP2_ORACLE_RECEIPT coordinateCount=4; containsBidirectedCoefficientMagnitude2=true; magnitude2LoadBearing=true`

Receipt audit: phase A `count=1 / PASS`; phase B `count=1 / PASS`.

## 5. Full selector382 gate

The entire frozen selector was executed in order, one identity per fresh process:

- selector382: **382/382 PASS**;
- accepted predecessor prefix: **373/373 PASS**;
- CP2 rows 374-380: **7/7 PASS**;
- correction rows 381-382: **2/2 PASS**;
- authority-kernel owner: **30/30 PASS**;
- producer owner: **236/236 PASS**;
- completion owner: **75/75 PASS**;
- validation owner: **41/41 PASS**;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**.

The full ledger contains exactly 382 data rows with one selected intended identity and exit 0 for every row.

## 6. Immutable postflight

Before/after census files compare byte-identically for all three required domains:

- package census SHA-256: `c45c423e7365887ccc5ef5974d1c61c32c775e9b064d41e47709500721d6938d`;
- extracted-source census SHA-256: `67726528d5e31765005b1fee3360acfed9d23958a754a71aaa62d5ff7507cee2`;
- execution-view census SHA-256: `1a5b1de75f2c9ae27c28ea77509e57b5e8c4565a2dd537b789cef03f98505f02`.

This directly closes the CB3 falsifier: the canonical execution-view census pair exists and postflight completed successfully with package/source/execution-view immutability preserved.

## 7. Classification and authority boundary

`M4-CP2-TB2-EXEC-CAND-01` is **CLOSED / RECOVERY PROVED / ORCHESTRATION / NON-STABLE**. The earlier invalid attempt remains no-credit provenance; R1 independently re-executed the full gate from scratch and disproved the harness defect after the one-name correction.

No new RED, crash, skip, timeout, nondeterminism, integrity failure, or orchestration failure was observed. Stable accounting therefore remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted package authority **115**.

This TB-EXEC turn does **not** promote package117 or close M4-CP2. Package117/selector382 is mechanically valid measured-green candidate evidence pending review. Accepted runtime authority remains package115 / selector373 **373/373** until review adjudicates promotion.

## 8. Exact successor

Exact next turn: **`M4-CP2-TB2-R1-REV`**.

That review is runtime-free. It must re-open the immutable package117 authority plus result artifact `10176889758` and log artifact `10176890045`, independently re-derive the decisive selector/process/receipt/immutability facts, audit the corrected source contract against the frozen M4 definitions, and decide package117 promotion and M4-CP2 closure or route to the next corrective turn. No compile, rerun, or package repair precedes that review.
