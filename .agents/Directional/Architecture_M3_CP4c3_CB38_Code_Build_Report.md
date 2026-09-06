# M3-CP4c-3-CB38 Code + Build Report

## Status

**COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE.**

CB38 implements the TB32 independent-review measures CT3–CT6 and freezes CT7 as a mandatory TB33 evidence/reporting obligation. No Directional test, benchmark, generated discovery command, CLI, or other produced runtime executed in this turn.

## Authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic/evidence source: `0d03edb07388c56b592a74e2e7fc5f3edde8cea4`
- Frozen predecessor runtime authority: `M3-CP4c-3-TB32`, selector 408, **397 PASS / 11 RED**, accepted **365/365**
- Selector 408: 408 identities, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`
- Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**

## Implemented scope

### CT3 — typed frontier stage evidence

`GlobalTopologyPlan` now distinguishes `UncutComponent`, `RegionConstruction`, and `RegionCertification` as first-class frontier failure stages. Later-stage failures carry stage-labelled `RegionFrontierComponentEvidenceDiagnostic` rows containing the plan partition identity/face-set digest and the corresponding certifier census identity/digest/subset relation.

Legacy `uncutFaceComponent*` seed-stage fields are populated only by the `UncutComponent` failure path. Later-stage construction/certification failures do not back-fill those seed-stage fields. The typed evidence is projected through `SurfaceCellFailureLocusDiagnostics` and its renderer.

### CT4 — justified cleared-stage outcome for 390/393/406/407

Ordinals **390, 393, 406, and 407** are retained in place with their names, ordinals, gating role, and selector bytes unchanged. Each now accepts exactly two evidence-bearing cases:

1. the uncut-component stage raised the failure and all legacy evidence the identity owns remains required; or
2. a later region stage raised the failure, proving the uncut stage cleared, and complete stage-labelled frontier/correspondence evidence is required.

Absence of evidence alone is not accepted. The later-stage helper also requires no legacy `uncutFaceComponent*` publication.

### CT5 — failure-detail fingerprint

The new reusable artifact-only harness preserves the historical `ledger.tsv` columns unchanged and publishes a separate `failure-detail-digests.tsv`. Every row receives a deterministic detail file/hash: PASS rows hash canonical `PASS\n`; RED rows retain and hash the complete GoogleTest failure blocks, falling back to a bounded process-failure tail only when no GoogleTest assertion block exists.

### CT6 — parameterized artifact harness

Added `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`. It is parameterized through mandatory environment inputs instead of global turn-label replacement. `baseline-authority.txt` records `TURN_ID`, the **executing `${GITHUB_RUN_ID}`**, immutable artifact ID, source SHA, and selector count. Packaged harness SHA-256 is `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.

The harness performs immutable artifact/source/selector/GMP/mode/census preflight before runtime, creates a byte-identical disposable execution view, executes one selector identity per fresh process only in `--execute` mode, records complete raw/detail/resource evidence, and performs byte+mode postflight. It never configures, compiles, relinks, repairs, runs generated discovery, or executes `directional_benchmarks`.

### CT7 — frozen TB33 obligation

No runtime evidence exists in CB38. `Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md` makes it a hard TB33 closeout requirement to transcribe the exact retained failing assertion/exception text for **every RED ordinal in the focused index**. A TB33 report missing any required transcription is incomplete.

## Change scope

Exactly six semantic paths changed:

- `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`
- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

No selector or fixture file changed. No product topology, barrier, source-face ownership, retired guard, separating-arc rule, or prescribed-sphere contract was changed. Ordinals 368/369/370/374/398 were untouched.

## Work-preservation and application evidence

The exact semantic patch was preserved before remote orchestration:

- base: `665f4f32f4abbd405a6ff8ee0643ecd53c889cf3`
- full patch SHA-256: `ac9584f8420d5a22fdc5d063f80c1e162b71e64fae58aa742bc843904be1e919`
- diff-body SHA-256: `fe1c5b9071b3959309f170c37c1767812aa0cc1aadc07aaa345aae601b9d6066`
- Drive apply run/job: `34052306929 / 101537995936`
- apply result artifact: `9994914154`, provider digest `sha256:be56721f0801aed82cad85addaa31cd400bbf497ae6d9b8eae141e2cf4ee8580`
- apply log artifact: `9994914339`, provider digest `sha256:2268444c156cf177b2036565f0ae552add60891e04f00b1bfb751ee103669f28`
- pushed semantic commit: `0d03edb07388c56b592a74e2e7fc5f3edde8cea4`

The consumed Drive patch was permanently retired by the owner-authorized control plane after the verified push.

## Compile/package evidence

Authoritative compile used only `.github/workflows/agent-compile-reusable.yml` through the temporary caller and built the exact semantic source above.

- run/job: `34052395109 / 101538234734`
- result artifact: `9994997588` / `m3-cp4c3-cb38-result-34052395109`
- result provider/download ZIP SHA-256: `059f40350b0acdc885e77523668ff6b50708fc802d910b257ba278d54444f8d8`
- compile log artifact: `9994997848`, provider digest `sha256:71f550cad64e9e1255984327ae33812317deb356e2ae32e7421b62a3729fa531`
- packaged source archive SHA-256: `092b3a5b81894ce15d1c767d41399fc72e65cd72f2400c0e7ff4c6970300c0e0`
- compile preflight exit: `0`
- build exit: `0`
- root self-excluding `SHA256SUMS`: **28/28 PASS**
- source status before/after configure/build/final: clean
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`
- GMP evidence: `DIRECTIONAL_ENABLE_GMP=ON`, authoritative link line includes both `libgmpxx.so` and `libgmp.so`
- compiler cache restored/refreshed under durable key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`

Compiled targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The benchmark target was compiled only; it was not executed.

## Static verification

Before remote application, the semantic patch passed `git apply --check`, `git diff --check`, exact six-path scope verification, and `bash -n` on the new harness. The authoritative compile package independently contains selector 408 at exactly 408 non-empty lines with unchanged SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`; the packaged harness also passes `bash -n`.

## Exit gate

CB38 is **GREEN for Code + Build**. It makes no runtime acceptance claim. The current semantic runtime authority therefore remains TB32 until artifact-only TB33 executes and TB33-REV adjudicates the evidence.

Exact successor: **`M3-CP4c-3-TB33-EXEC`**, consuming immutable artifact `9994997588` under `Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md`. The orchestrator must stop at the independent `TB33-REV` boundary after EXEC closes.
