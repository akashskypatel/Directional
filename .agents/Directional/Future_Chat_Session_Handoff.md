# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB2-R2-EXEC` COMPLETE / 799/799 MEASURED GREEN / IMMUTABLE POSTFLIGHT GREEN / CANDIDATE UNPROMOTED
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Test + Benchmark Review, `M4-CP3-TB2-R2-REV`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority pending review.
- Corrected R4 candidate package artifact `10289601000` is compile/package-green and now mechanically runtime-green at exact evidence source `58521f6d1c4fb5d625da7cde50e002cf4688beee`, but remains unpromoted.
- Successor selector403 remains 403 rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; first394 remains byte-identical to accepted selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3→A4 cutover remains unauthorized.

## R4 package authority

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R4_Code_Build_Report.md`.

- exact source: `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- full package run/job: `34665925501 / 103477693366`;
- artifact: `10289601000`, provider/ZIP SHA-256 `ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9`, `29,764,498` bytes;
- packaged source archive SHA-256: `b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0`;
- 28-entry manifest SHA-256: `d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b`;
- exact arithmetic: GMP/GMPXX; Code + Build boundary `runtimeExecution=false`.

## TB2-R2 execution result

Authority: `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Report.md`.

Frozen plan `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md` was executed artifact-only against immutable package `10289601000` in run/job:

```text
workflow run = 34666794115
execute job  = 103480225842
event SHA    = 1bfecc580c41f7ffa2bcdc4b48f9fe143e46a894
```

Result evidence:

```text
result artifact     = 10289088800
result digest       = sha256:2e3bfb39d10c00008479ab5c4b42b428bcdc1b92808646fae23470c4a5704d4e
diagnostic artifact = 10289438082
diagnostic digest   = sha256:ea2c9cc599e381a4ae5d63128e8dfcc33f8d476a9904aa0fcc6ded3df292058b
```

Preflight re-established artifact/source/manifest/GMP/binary/selector authority, unique owner mapping and the row400 independent discriminator:

```text
raw source row       = [3,0,4]
canonical key row    = [0,3,4]
canonical weights    = [1/6,1/3,1/2]
locus source vertex  = 4
correct remap        = 1/3
wrong positional     = 2/3
owner                = directional_surface_cell_producer_tests
```

The exact frozen runtime matrix completed **799/799 PASS**:

```text
focused row400 A      1/1
focused row400 B      1/1
selector394         394/394
selector403         403/403
---------------------------
total               799/799
```

There were **0 RED, 0 SKIP, 0 timeout and 0 selection mismatch**. Selector394 owner totals were **30 authority-kernel / 248 producer / 75 completion / 41 validation**; selector403 owner totals were **30 / 257 / 75 / 41**. Focused A/B identity+verdict vectors are byte-identical. Package, extracted source and execution-view censuses compare byte-identically before/after; both manifest passes are **28/28**. No configure, compile, relink, generated discovery, package repair or benchmark ran.

TB-EXEC does not classify or promote. Package119 remains accepted and corrected package `10289601000` remains candidate-only pending Review.

## Exact next — `M4-CP3-TB2-R2-REV`

Review is evidence-only and may be performed by the same agent/session under the repository's same-agent review authorization, but the evidence must be independently reopened/re-derived.

At minimum:

1. reopen frozen plan `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md`;
2. independently verify artifact `10289601000`, source `58521...`, manifest/source archive and selector394/403 provenance;
3. reopen raw result artifact `10289088800` and verify exactly 799 fresh exact-filter processes, one selected test per process, focused A/B determinism, selector394 `394/394`, selector403 `403/403`, and owner totals;
4. independently re-derive row400 non-vacuity, unique producer ownership, and the exact `1/3` versus `2/3` wrong-basis discriminator from packaged source;
5. verify package/source/execution-view immutable postflight;
6. decide candidate package/selector disposition and whether regression accounting changes.

Do **not** compile, rerun, mutate implementation/tests/fixtures/selectors/package bytes, promote the candidate, or begin A3→A4 work before Review disposition.

## Carried obligations

- `M4-CP3-CB4-R2-REV-CAND-01`: source correction is compile-proved and mechanically runtime-green; Review still owns acceptance.
- `M4-CP3-TB2-REV-CAND-01`: replacement row400 is source-proved/non-vacuous and now mechanically runtime-green twice; Review still owns acceptance.
- `M4-CP3-CB4-R3-REV-CAND-01`: **closed by R4 compile/package** as non-stable build-contract drift.
- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity weighting still only `[1,1,1]`; outside row400 recovery.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` consistency tamper remains outside row400 recovery.
- No A3→A4 cutover or exact-torus pairing work before corrected package Review acceptance.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB-REVIEW.md
conditional_modules:
  - trigger: independently review row400 fixture/assertion non-vacuity and exact discriminator
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: retrieve and inspect GitHub Actions runtime evidence/artifacts
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R4_Code_Build_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt
  - .agents/Directional/Architecture_M4_CP3_Required_Green_Selector_394.txt
  - tests/FieldAlignedCurveNetworkTests.cpp
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - M4-CP3-CB4-REV-OBS-02 row399 work
  - any compile/relink/rerun before review disposition
```
