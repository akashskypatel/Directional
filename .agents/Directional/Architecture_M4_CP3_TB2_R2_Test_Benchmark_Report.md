# M4-CP3-TB2-R2 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP3-TB2-R2-EXEC`
**Status:** **COMPLETE / 799/799 MEASURED GREEN / IMMUTABLE POSTFLIGHT GREEN / REVIEW PENDING / CANDIDATE UNPROMOTED**
**Date:** 2026-09-12 UTC
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`

## 1. Frozen authority

This execution consumed the corrected R4 candidate frozen by `M4-CP3-CB4-R4`:

- semantic/build evidence source: `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- package artifact: `10289601000`, `m4-cp3-cb4-r4-package-result-34665925501`;
- package ZIP/provider SHA-256: `ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9`;
- package byte size: `29,764,498`;
- packaged source archive SHA-256: `b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0`;
- package `SHA256SUMS`: 28 entries, manifest SHA-256 `d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b`;
- accepted selector394: 394 rows, SHA-256 `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- successor selector403: 403 rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- successor first394: byte-identical to accepted selector394.

No configure, compile, relink, generated GTest discovery, package repair, source/test/fixture/selector mutation or benchmark was authorized or performed.

## 2. Preflight authority and row400 non-vacuity

Preflight completed successfully before any runtime process. It re-verified:

- provider/download artifact digest and byte size;
- package manifest **28/28** and exact manifest path set;
- source commit `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- clean source-status records and GMP/GMPXX Code + Build boundary;
- all four selector-owner executable SHA-256 values and mode `755`;
- selector row counts/hashes and byte-identical 394-row prefix;
- exactly one static source definition per selector identity and unique executable ownership;
- selector394 owner partition **30 authority-kernel / 248 producer / 75 completion / 41 validation**;
- selector403 owner partition **30 / 257 / 75 / 41**.

Replacement row400 is `EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking`, uniquely owned by `directional_surface_cell_producer_tests`. Packaged-source re-derivation preserved the independent discriminator:

```text
raw oriented source row = [3,0,4]
canonical topology row   = [0,3,4]
canonical weights        = [1/6,1/3,1/2]
locus source vertex      = 4
correct remapped value   = 1/3
wrong positional value   = 2/3
```

The test source still asserts the correct exact result and rejects the wrong positional interpretation.

## 3. Exact execution evidence

- workflow run/job: `34666794115 / 103480225842` — **SUCCESS / SUCCESS**;
- event/control SHA: `1bfecc580c41f7ffa2bcdc4b48f9fe143e46a894`;
- result artifact: `10289088800`, `m4-cp3-tb2-r2-exec-result-34666794115`, SHA-256 `2e3bfb39d10c00008479ab5c4b42b428bcdc1b92808646fae23470c4a5704d4e`;
- diagnostic-log artifact: `10289438082`, `m4-cp3-tb2-r2-exec-log-34666794115`, SHA-256 `ea2c9cc599e381a4ae5d63128e8dfcc33f8d476a9904aa0fcc6ded3df292058b`;
- preflight outcome: `success`; runtime outcome: `success`; postflight outcome: `success`;
- planned processes: `799`; observed processes: `799`;
- preflight exit: `0`; runtime exit: `0`; blocker file: absent.

Every runtime process was a fresh invocation of one frozen owner executable with one exact `--gtest_filter=<identity>`, `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, exactly one matching `[ RUN ]`, exactly one matching `[ OK ]`, zero skip, and exit 0.

## 4. Focused row400 proof

The replacement row400 identity was executed twice in independent fresh processes:

| Phase | Identity | Owner | Result |
|---|---|---|---|
| focused A | row400 replacement | producer | **1/1 PASS** |
| focused B | row400 replacement | producer | **1/1 PASS** |

The focused identity/verdict vectors are byte-identical. Neither process selected another test.

## 5. Accepted predecessor and cumulative gates

The frozen predecessor and successor selectors were then executed in file order, one fresh process per identity:

- selector394: **394/394 PASS**;
  - authority-kernel **30/30**; producer **248/248**; completion **75/75**; validation **41/41**;
- selector403: **403/403 PASS**;
  - authority-kernel **30/30**; producer **257/257**; completion **75/75**; validation **41/41**;
- row400 is PASS in successor selector403;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**.

The complete ledger contains exactly 799 data rows across phases `1 + 1 + 394 + 403`; every row records `PASS`, exit `0`, one intended `[ RUN ]`, one intended `[ OK ]`, zero skip and `timeout=false`. Exactly 799 raw per-process logs were preserved.

## 6. Immutable postflight

After process 799:

- package census before/after: byte-identical;
- extracted-source census before/after: byte-identical;
- execution-view census before/after: byte-identical;
- package `SHA256SUMS`: **28/28 PASS** again;
- `configure=false`;
- `compile=false`;
- `relink=false`;
- `generated_discovery=false`;
- `package_repair=false`.

The immutable artifact/source/execution-view boundary therefore remained intact for the full execution.

## 7. Authority boundary

This Test + Benchmark EXEC measured the frozen candidate only. It does **not** classify regressions, promote package `10289601000`, promote selector403, close CP3, or authorize A3→A4.

No RED, crash, skip, timeout, selection-integrity failure, nondeterminism in the focused A/B verdict vector, package-integrity failure or orchestration blocker was observed. Stable accounting therefore remains pending Review at the previously accepted **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**. Accepted runtime authority remains package119 / selector394 **394/394** until Review adjudicates the corrected candidate.

## 8. Exact successor

Exact next turn: **`M4-CP3-TB2-R2-REV`**.

Review is evidence-only. It must independently reopen the frozen plan, R4 package/source authority, raw result artifact `10289088800` and diagnostic artifact `10289438082`; independently re-derive row400 non-vacuity and unique producer ownership; verify the exact 799-process ledger, focused A/B determinism, selector394 compatibility, selector403 owner totals, and immutable postflight; then decide package/selector disposition and any regression-accounting change.

No compile, rerun, package repair, source/test/fixture/selector mutation, promotion or A3→A4 implementation is authorized before that review disposition.
