# M3-CP4c-0 TB-R2 Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-0-TB-R2`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic source authority: `390e65b373063c667e3c3f5e78b74ed9d859093b`
- Immutable build artifact: `9586196535`
- Immutable package ZIP SHA-256: `9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`
- Frozen selector: **338 unique identities**, SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`
- Accepted first-316 SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- First-328 SHA-256: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`
- Environment: GitHub Actions `ubuntu-24.04`; artifact-only; no configure/build/relink/repair/discovery/performance benchmark
- Status: **COMPLETE / VALID SEMANTIC RED AT IDENTITY 329; Q8 NOT RUN**

## Authoritative execution

The authoritative semantic execution is diagnosed retry 1:

- workflow run: `32914546494`;
- Test + Benchmark job: `98015432540`;
- event/control SHA: `26c55d13b7449953f27a4e8bd36e3c5b474f00d9`;
- result artifact: `9587747391`, SHA-256 `89d72a42b07bb879f2ba35b18b3771359d522e3c0f444e33e79ce0214d8fc5a3`;
- diagnostic-log artifact: `9587747654`, SHA-256 `2b43c3bda84edffe7ea23cd9763fa3c96858285b785624102f202d4e72479dab`;
- in-run workflow schema validation: PASS.

Retry 0, run/job `32914435964 / 98015089869`, is **orchestration-only / non-semantic**. It verified the exact package/source/selector, executed identity 1 successfully, then stopped because the temporary `run_identity` shell helper returned the status of its final false bookkeeping predicate for ordinal 1. Its result/log artifacts are `9587635807 / 9587636288` with SHA-256 `bd8aad251fd3b5f16a55170e5acd36ed940fc6cdbfdcc442bbac22f056098dc3 / fc3525908575f0511c1596eb5524d25f6890110c381a631b847746837456f99e`. The one policy-authorized diagnosed retry added only an explicit successful helper return; package, selector, commands, fixtures, expectations, and semantic source were unchanged.

No semantic retry is authorized after retry 1.

## Integrity / artifact-only boundary

Preflight verified package ZIP SHA-256, the package's 27-entry self-excluding manifest, semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b`, all three frozen selector hashes, 338 uniqueness, and E6 presence (`TraceStateCycleDetected`, `TraceStepBudgetExhausted`, and `FieldAlignedTraceTraversalGuard`). Package source and the checked-out semantic paths matched before runtime.

Postflight package inventory, runtime-input inventory, selector hash, and source status are byte-identical to preflight. All mutation/build flags are false: `packageMutation`, `sourceMutation`, `testMutation`, `fixtureMutation`, `selectorMutation`, `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`, and `performanceBenchmark`.

## Frozen gate result

Execution used one identity per fresh process, in selector order, with exact filters and `--gtest_fail_if_no_test_selected`.

- identities required: **338**;
- identities executed: **329**;
- identities passed: **328**;
- accepted predecessor prefix: **316/316 PASS**;
- prior CP4c-0 prefix through identity 328: **328/328 PASS**;
- first correction identity executed: **1/10**, failed;
- first semantic failure: ordinal **329**, `ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`.

Per the frozen plan, execution stopped at the first deterministic semantic red. Identities 330–338 were not executed and receive no credit.

## First semantic failure

`ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly` fails every token assertion that expects numeric branch publication such as `branch=1` or `relatedBranch=3`. The emitted diagnostics instead contain raw control characters after `branch=` / `relatedBranch=`.

Static evidence in the immutable package makes the immediate cause high-confidence and narrow:

1. `FieldBranch::value()` returns `std::uint8_t`.
2. Test diagnostic helper `append_network_error` streams `error.branch->value()` and `error.relatedBranch->value()` directly into `std::ostringstream`.
3. C++ stream insertion treats `std::uint8_t` as an unsigned character type, so values `1` and `3` become control characters rather than the decimal strings `"1"` and `"3"`.
4. The error object's typed branch authority is still populated; the loss occurs at the test/witness diagnostic serialization boundary.

This is therefore a **test/diagnostic-observability candidate**, not evidence that accepted production branch authority regressed. The frozen E1 requirement nevertheless demands lossless witness diagnostics, so the red identity is valid and blocks CP4c-0 acceptance until independent review adjudicates the correction. No test or diagnostic source was edited in TB.

## Binding Q8

Q8 is **NOT RUN**. E6 is present, but the frozen plan permits Q8 only after a green 338/338 gate. Because identity 329 is red, no sphere/torus/mechanical Q8 observation is semantically authorized from this turn. The previous accepted runtime authority therefore remains CP4ab **316/316**.

## Regression / candidate accounting

- `M3-CP4c0-TB-R2-CAND-01` — **ACTIVE / NON-STABLE / PENDING INDEPENDENT REVIEW**: test/witness diagnostic serializer publishes `FieldBranch::value()` as a character, causing the first E1 correction identity to fail at ordinal 329.
- `M3-CP4c0-TB-R2-CAND-02` — **RESOLVED ORCHESTRATION / NON-STABLE**: retry 0 stopped after identity 1 because the temporary shell helper returned a bookkeeping predicate status; retry 1 corrected only orchestration and reached the deterministic semantic red.
- Prior `M3-CP4c0-TB-CAND-01` remains **fix implemented / runtime re-proof blocked**: identities 1–328 are green, but Q8 cannot run until the new 338 gate is green.

Stable accounting remains **42 events / 14 categories / 28 recurrences**. CP4c-0 has never been accepted, the accepted 316 prefix is still green, produced-witness debt remains **5**, and M3 build-package count remains **41** because TB produced no build package.

## Phase status / next turn

`M3-CP4c-0-TB-R2` is **COMPLETE / VALID SEMANTIC RED**. CP4c-0 remains unaccepted. Do not repair, rerun, weaken an expectation, alter the fixture, or start CP4c-1 inside this TB.

Exact next is independent **`M3-CP4c-0-TB-R2-REVIEW-PLAN`**, review/planning only. It must adjudicate whether the E1 failure is solely the `std::uint8_t` diagnostic-formatting defect or exposes any broader frozen diagnostic-authority issue, then prescribe the smallest corrective Code + Build turn. Q8 remains frozen and unconsumed.
