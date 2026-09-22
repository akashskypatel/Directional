# Directional Future Chat Session Handoff

## Current authority

`M5-CP3-CB12` is **COMPLETE / PRODUCT-ONLY / RUNTIME-FREE / COMPILE GREEN** once terminal `STATUS` is published.

CB12 changes exactly `src/geometry/SurfaceCellTracing.cpp` (**+30 / -6**). For a same-region reciprocal periodic pair, exact A3 interval authority now selects the `Orientation::Forward` member as directed source and the `Orientation::Reverse` member as directed target before the existing single `generator_route_for_span(...)`, `periodic_action_for_pair(...)`, and checked `SurfacePeriodicHolonomy::make(...)`. The two helper definitions are byte-identical, cross-region HardRail behavior is unchanged, and no inverse/search/fallback, endpoint rewrite, relation recanonicalization, test/fixture/selector/routing/build semantic change, or Directional runtime was introduced.

Semantic source: `8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. Compile run/job: `35767608403 / 106881074883`. Candidate/log: `10713410215 / 10713170611`. Candidate/log ZIP SHA-256: `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce / 6111b5eb2886f9da7a8a53226b299f417ee4116fc524d5263eadc1e35e12eaee`. Root manifest: **28/28**, SHA-256 `352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33`. Packaged source SHA-256: `506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`. Evidence records exact GMP backend, explicit GMPXX+GMP, clean source receipts, and `runtimeExecution=false`.

This is compile evidence only. Runtime recovery is unproved. Accepted runtime remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; selector430 remains **430/430**; stable accounting remains **50 / 14 / 36**; project debt remains **3**; selector publication is prohibited.

Procedure note: initial repository authority reads preceded the explicit `READ_MODE=snapshot` declaration. Piecemeal inspection stopped immediately and the turn switched to one exact verified source snapshot for subsequent static implementation work. This is a process miss only. Exact turn-local tool-call count was lost during context compaction and is reported partial/unknown rather than reconstructed.

## Exact next turn

**`M5-CP3-TB1-R11-EXEC` — immutable artifact-only Test + Benchmark**, using `.agents/Directional/Architecture_M5_CP3_TB1_R11_Artifact_Only_Test_Benchmark_Plan.md` and candidate `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`.

Execute exactly **446** fresh exact-filter processes: 9 mechanism + 1 focused atlas + 6 produced + selector430 430. Every row selects exactly one test, zero skips; benchmark count 0. Rows1/2/3/6 are controls. Rows4/5 must independently select A3 **Forward -> Reverse**, with row4 proving nonzero-Z4 rotation+translation through materialization/certificate consumption and row5 changing only action rotation and rejecting exact `NonReciprocalPeriodicRelation`.

R11 must copy `driver-authority.txt` **before** regenerating the self-excluding `SHA256SUMS`, run `sha256sum -c`, and independently require manifest row count == actual non-manifest file count (expected **912/912** only if shape is otherwise unchanged). Do not repair R10. Any mechanically complete R11 routes to mandatory `M5-CP3-TB1-R11-REV`; EXEC cannot promote, discharge debt, close observations, or publish/precommit a selector.

## Resume-critical evidence

- R11 plan: `.agents/Directional/Architecture_M5_CP3_TB1_R11_Artifact_Only_Test_Benchmark_Plan.md`
- CB12 source/run/job: `8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188 / 35767608403 / 106881074883`
- CB12 candidate/log: `10713410215 / 10713170611`
- candidate/log ZIP hashes: `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce / 6111b5eb2886f9da7a8a53226b299f417ee4116fc524d5263eadc1e35e12eaee`
- candidate root manifest/source archive: `352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33 / 506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`
- routing artifact/hash: `10592987234 / 352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
- routing identity map: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- selector430 / first427: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- prior Review/report: `.agents/Directional/Architecture_M5_CP3_TB1_R10_Review_Record.md`, `.agents/Directional/Architecture_M5_CP3_TB1_R10_Artifact_Only_Test_Benchmark_Report.md`
- frozen definitions/tracker/consolidated record: `.agents/Directional/Architecture_M5_Frozen_Definitions.md`, `.agents/Directional/Regression_Root_Cause_Tracker.md`, `.agents/Directional/M5_Consolidated_Record.md`

## Context Load Plan

```yaml
load_next:
  - references/turns/TB.md
conditional_modules:
  - trigger: GitHub Actions artifact-only runtime
    path: modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M5_CP3_TB1_R11_Artifact_Only_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M5_CP3_TB1_R10_Review_Record.md
  - .agents/Directional/Architecture_M5_CP3_TB1_R10_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M5_Frozen_Definitions.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/M5_Consolidated_Record.md
do_not_preload:
  - source/test/fixture/selector/routing mutation
  - inverse-direction fallback or best-of-two direction search
  - selector publication before independently green R11 Review
  - M6 occurrence work
```
