# M3-CP4c-3-CB50 Code + Build Report

**Status:** COMPLETE / COMPILE + PACKAGE GREEN / RUNTIME-FREE

**Turn:** `M3-CP4c-3-CB50`
**Boundary:** Code + Build only
**Date:** 2026-09-09
**Evidence source:** `46554ef2bc1b36fff100e4de0a274a0fb6d3f26d`

## 1. Implemented bounded corrections

CB50 implements exactly the two corrections frozen by TB44-REV and no broader topology change.

### Product — fragment-corner fan authority

`src/geometry/GlobalTopologyPlan.cpp` now partitions carrierless `RayCut` entries by exact
`(sourceFace, sourceCorner)` before ordinal sorting and orbit-chain validation. Each source-corner fan preserves the
existing duplicate-ordinal and orbit-chain fail-closed guards, and its contributions merge only through the existing
set-valued `FragmentCornerIncidence` map. The previous whole-face assumption that all rays had the same
`sourceCorner` is removed.

### Protected tests — typed terminal subject

`tests/FieldAlignedCurveNetworkTests.cpp` keeps the real producer-owned Part XII `P_U` predicates and deliberate
same-domain corruption negatives for ordinals 390/393/406/407. The shared terminal-evidence helper now:

- always requires `regionFrontierSubjectDomainRelation == "Outside"`;
- uses the existing current-region evidence only when `topologyRegion` is authoritative;
- accepts the source-face subject when no current region exists, while requiring region-only fields to remain absent;
- fails closed when neither subject exists;
- publishes `terminalSubjectBranch` in the deterministic receipt.

No fixture, selector, partition, `build_regions`, `fragmentOrbits`, actual embedded graph, carried RED owner or
ownership policy changed.

## 2. Static review

The pre-compile source review passed all frozen CB50 checks:

1. carrierless `RayCut` construction still records exact `sourceCorner`;
2. cross-corner whole-face rejection is gone rather than hidden by ordering;
3. duplicate ordinal and orbit-chain guards execute inside each source-corner fan;
4. no fallback/foreign owner is introduced;
5. 390/393/406/407 still run their real producer predicate and corrupted-copy negative before terminal evidence;
6. terminal subject selection uses authoritative locus fields, not stage-name matching.

The semantic patch changed exactly two files: **75 insertions / 36 deletions**. Preserved patch SHA-256 is
`13f4ba610b797a826a3507422c0ada960fb52f9451439a740995c838101c9a90`; semantic diff-body SHA-256 is `bc28676c199ece634974b44007b1388c634d0b882d99f20303ea572e85f5aff9`.

## 3. Patch application evidence

Corrected patch-metadata retry run/job `34330694028 / 102398372187` successfully verified the exact Drive bytes,
base, diff-body digest and two-path manifest, applied the patch cleanly, passed `git diff --check`, committed and
pushed exact semantic source `46554ef2bc1b36fff100e4de0a274a0fb6d3f26d`.

- apply result artifact: `10095632633`;
- apply log artifact: `10095633157`;
- `runtimeExecution=false`.

The earlier application attempts were orchestration-only failures: first the service account lacked Drive access;
after access was granted, the original patch header encoded `intended_paths` with commas while the durable reusable
expects semicolon separation. Neither failed attempt pushed semantic source. The corrected v2 patch changed only
transport metadata; its semantic diff-body digest remained `bc28676c199ece634974b44007b1388c634d0b882d99f20303ea572e85f5aff9`.

## 4. Compile/package evidence

The mandatory durable GMP/GMPXX reusable workflow compiled exact source `46554ef2bc1b36fff100e4de0a274a0fb6d3f26d` in run/job
`34330825605 / 102398794843`.

- immutable package110 artifact: `10095738820`,
  `m3-cp4c3-cb50-package110-result-34330825605`;
- provider SHA-256: `7edc47632dbd863508c97d5716dd9df5e469671e0b327a133848ff3c37142000`;
- persistent compile-log artifact: `10095739319`;
- log provider SHA-256: `614d440b76ce16fb9965a08008f6d76880e0f016f79c4ef6084f03c38f2876ed`;
- packaged source archive SHA-256: `8ae8fcd115c5b150642ad090272a001de89520d28ba69c2564cd476473374e80`;
- recursive package manifest: **28/28 verified**;
- build exit: **0**;
- source status after configure/build/final: clean;
- `exactArithmeticBackend=GMP`;
- authoritative link command contains both `libgmpxx.so` and `libgmp.so`;
- `runtimeExecution=false`.

Compiled targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, fuzzer or custom input
was executed.

## 5. Authority and accounting

CB50 is compile evidence only. It does not promote semantic runtime behavior or reprice regressions.

- current semantic runtime authority remains **TB44 / package109 / selector409: 398 PASS / 11 RED / 0 SKIP,
  accepted 365/365**;
- stable accounting remains **47 events / 14 categories / 33 recurrences**;
- produced-witness debt remains **5**;
- certified ownership remains **300 / 0 / 0**;
- immutable package count advances **109 → 110**.

## 6. Exact successor

**`M3-CP4c-3-TB45-EXEC` — Test + Benchmark / artifact-only.**

Execute only the frozen
`.agents/Directional/Architecture_M3_CP4c3_TB45_Artifact_Only_Test_Benchmark_Plan.md` against package110 and the
unchanged selector409. TB45-EXEC must not rebuild, repair or mutate the package/source/tests/fixtures/selector.
