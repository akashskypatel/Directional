# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB6` COMPLETE / BUILD GREEN / RUNTIME-FREE / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** artifact-only Test + Benchmark execution, `M4-CP3-TB4-EXEC`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Corrected R4 artifact `10289601000` at semantic source `58521f6d1c4fb5d625da7cde50e002cf4688beee` remains accepted M4-CP3 runtime authority. Selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` remains accepted **403/403**.
- CB5 package `10290933668` remains rejected for promotion because TB3 proved row408's torus fixture lacked hard-feature rail authority; rows404-407 were green.
- CB6 corrected only that fixture precondition at semantic source `9d66fcebe4b91ab74a6d0234c46643a2723ab643`. The explicit frozen torus cycles passed the source-edge, independence, one-vertex cut-graph/disc-complement, and production-ingress static guard before mutation.
- CB6 immutable candidate package is artifact `10292005428` from run/job `34673625938 / 103499484128`, outer SHA-256 `7723188540182f9515b95efd83c13dd1dbc6f0813532a98cd8df0778a12a882f`. Compile-log artifact is `10292090424`, SHA-256 `80b3950a876b7b5a765f3b95781111f5c7fcefa7e637f96406be96421a580d76`.
- Package source archive SHA-256 is `3c82e4778ec4ea4631e25d39ed18f7f7ed68a2a24a1ad08e3ebfe298dfe331a9`; package manifest SHA-256 is `26529a4d12434bc737e4952f09f9790dd8f36d4151e1500154fa7a60497101af`, 28/28 verified. GMP/GMPXX is linked, source status is clean, all six packaged executables are mode 755, and `runtimeExecution=false`.
- Selector408 remains byte-frozen at `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; its first403 remains byte-identical to accepted selector403. Owner partition remains **30 / 262 / 75 / 41** with zero missing/ambiguous identities.
- No Directional runtime executed in CB6. Package `10292005428` and selector408 are compile-valid candidates only; neither is promoted. Stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**. `G4-B002` and CP3 remain OPEN.

## Exact next — `M4-CP3-TB4-EXEC`

Authority: `.agents/Directional/Architecture_M4_CP3_TB4_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only immutable package artifact `10292005428`; no configure, compile, relink, discovery generation, package repair, or unpackaged runtime. Verify immutable package/source/selector/owner authority first, then restart the entire frozen gate from zero as exactly **821 fresh exact-filter processes**:

```text
corrected row408 focused A   1
corrected row408 focused B   1
rows404-407 controls A+B     8
accepted selector403       403
candidate selector408      408
                           ---
total                      821
```

Honor fail-fast at the first RED, preserve immutable postflight regardless of semantic result, and publish raw execution evidence only. `TB4-EXEC` does not diagnose, promote, close CP3, or change stable accounting. Mandatory successor is `M4-CP3-TB4-REV`.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB.md
conditional_modules:
  - trigger: immutable artifact-only runtime execution
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: artifact execution through GitHub Actions
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB4_Artifact_Only_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB6_Compile_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB6_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB3_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_TB3_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt
do_not_preload:
  - M5/M6 implementation
  - any compile/relink/configure path during TB4-EXEC
  - product changes or diagnosis; TB4-EXEC is mechanical evidence only
```
