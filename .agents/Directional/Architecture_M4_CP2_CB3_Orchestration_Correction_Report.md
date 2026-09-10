# M4-CP2-CB3 Orchestration Correction Report

**Turn:** `M4-CP2-CB3`
**Status:** **COMPLETE / STATIC-GREEN / RUNTIME-FREE / CONTROL-PLANE-ONLY / PACKAGE117 REUSED UNCHANGED**
**Date:** 2026-09-10 UTC
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`

## 1. Authority and scope

CB3 consumed the invalid-attempt diagnosis from `M4-CP2-TB2-EXEC` and the frozen correction plan `Architecture_M4_CP2_CB3_Orchestration_Correction_Plan.md`. The durable branch head entering CB3 was `e819c58a85c188b35b7aec5d542de35ae2c59348`; exact inspection authority was snapshot run/artifact `34534271685 / 10174762812`, event/snapshot SHA `52ebea42ec92bd7ca89e76ab89ac45178cc0176f`, artifact SHA-256 `b07bea51b00c287a9a4d50c7fd12ac482d7d01e01035253c605f0fe09ec1ac0a`, inner source archive SHA-256 `ae212d9f87047ba8bd3d752adaa587bb28d52800eff57859425e64f7be4097be`.

The turn is an orchestration-correction CB only. It does not change product semantics, tests, fixtures, selectors, CMake/build semantics, or package117, and it does not compile or execute Directional runtime.

## 2. Implemented correction

The invalid TB2 preflight payload had SHA-256 `af458b58c6ba6c339c80ac64d360dfeaf190f621b13e31de50d49461274f4aaa` and wrote:

`execution-view-before.tsv`

The unchanged postflight executor had SHA-256 `717a4dd6cda5ba96fb8bd6e16879c422f9b2e1ff561951801dc5658d85480019` and reads `O/f'{x}-census-before.tsv'` while writing `O/f'{x}-census-after.tsv'`. For `x='execution-view'`, the canonical contract is therefore:

- preflight: `execution-view-census-before.tsv`
- postflight: `execution-view-census-after.tsv`

CB3 changes exactly the preflight writer basename to the canonical `execution-view-census-before.tsv`. No postflight code is changed.

The corrected orchestration payload was materialized through `tools/write_orchestration_payload.py` from `@@SHA256:*@@` placeholders, so all expected SHA-256 literals were validated before the output file was written.

## 3. Static validation receipt

No produced Directional binary was executed. Static/file-only checks established:

- corrected preflight Python AST: **PASS**;
- unchanged executor Python AST: **PASS**;
- retry caller YAML parse: **PASS**;
- retry caller schema shape versus the schema-validated TB2 predecessor: **IDENTICAL**; only scalar turn/marker/workflow/script/artifact labels differ;
- invalid-to-corrected preflight diff: **one literal basename replacement only**;
- executor bytes: **identical** to the invalid attempt;
- preflight writer and postflight reader: **same canonical `execution-view-census-before.tsv` contract**;
- no unresolved SHA-256 placeholder remains.

Frozen retry payload hashes:

- corrected R1 preflight: `12090d4b5e01f6c3e55de712b595dff3444b509ba58b040201a2c61f87d805c1`
- unchanged R1 executor: `717a4dd6cda5ba96fb8bd6e16879c422f9b2e1ff561951801dc5658d85480019`
- R1 caller draft: `baf81bf788f6823d79f3b34431424a1e19e7e45b6eacb6fb788604333a08d6ab`

The predecessor TB2 caller was schema-valid enough to run its `validate` dependency and execute workload; the R1 caller draft preserves the same parsed schema/type tree and only changes valid scalar control values. Active publication in R1 must still preserve the exact validated draft bytes and its own normal schema-validation guard.

## 4. Immutable package authority

CB3 carries package117 forward unchanged:

- semantic source: `534c0d41ae05b31e66711f21f4b4280b59f6483f`
- package117 artifact: `10172820820`
- package ZIP SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`
- selector382 SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`
- accepted selector373 prefix: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`
- selector380 prefix: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`

Accepted runtime authority remains package115 / selector373 **373/373**. Package117 remains unpromoted until a valid artifact-only execution and review.

## 5. Engineering review

- **Assumption surfaced:** the failed postflight was caused solely by a producer/consumer filename mismatch; package/source/execution-view immutability was independently established by the invalid attempt.
- **Smallest sufficient change:** rename one preflight output basename. Changing the reader as well, adding compatibility aliases, or rebuilding the package would add variables without evidence.
- **Scope discipline:** no product/test/fixture/selector/CMake file is touched. The executor remains byte-identical.
- **Regression risk:** the retry repeats the entire frozen selector382 gate and immutable postflight, so a hidden semantic issue cannot be promoted on CB3 static evidence.

## 6. Build/runtime boundary

- Directional compile/link: **NOT RUN — forbidden by the frozen orchestration-correction plan**.
- Repackage/package mutation: **NOT RUN**.
- Directional tests/benchmarks/generated discovery/CLI/help/version/fuzzer/custom runtime: **NOT RUN**.
- Static Python/YAML/file-contract checks only: **RUN / PASS**.
- Reusable workflow permissions: **UNCHANGED**.

The standard compile requirement is inapplicable to this explicitly routed control-plane-only CB; package117 is intentionally held fixed as the experiment variable.

## 7. Invalid-attempt disposition

`M4-CP2-TB2-EXEC-CAND-01` remains **NON-STABLE** and is now **CORRECTION AUTHORED / AWAITING R1 RE-EXECUTION**. CB3 does not retroactively validate the invalid attempt. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted package authority **115**.

## 8. Mandatory Test + Benchmark plan

Exact successor: **`M4-CP2-TB2-R1-EXEC`** under `Architecture_M4_CP2_TB2_R1_Artifact_Only_Test_Benchmark_Plan.md`.

R1 must consume immutable package117 `10172820820`, materialize exactly the corrected payload hashes above, re-run focused ordinals 374/381/382 twice and the entire selector382 one identity per fresh process, and complete the corrected immutable postflight. No rebuild/repair is allowed.
