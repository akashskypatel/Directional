# CB131 — Rim-chain switch staging: Code and Build record (2026-11-12)

## Situation

- Canonical turn: `M6-CP3-CB131-P13-A3-RIM-CHAIN-SWITCH-STAGING` (64E.1). **Code and compile-only build verified.** The required eight targets compiled and the immutable package passed **28/28** internal SHA-256 checks.
- Exact next, **in a separate turn**: `M6-CP3-TB112-P13-A3-RIM-CHAIN-SWITCH-STAGING-FULL-GATE-EXEC` (64E.2), artifact-only test and benchmark gate. No successor work started during CB131.

## Background

- RA-230 frozen nine-file patch `Architecture_M6_CP3_CB131_P13_A3_Rim_Chain_Switch_Staging_Exact.diff`: SHA-256 `571ae1ef904420af6a2919379f8326d0d80b85c2390f02b4317c1c488b10021c`, 423 lines. The applied diff has the exact nine-file change set and numstat from RA-230 §4.
- Exact source snapshot `2e40ae6e4ea73e64b2a963448a746ba3a19a6aa7`: run `43191812080`, artifact `13930562758`; 5,508/5,508 source file hashes verified. Local `git apply --check` and `git diff --check` passed.
- Initial patch application [43192934342](https://github.com/akashskypatel/Directional/actions/runs/43192934342) failed without modifying product source. Its metadata omitted the required semicolon-separated `intended_paths`. The corrected transport v2 retained the identical diff body (SHA-256 `d14de7f2f795305a111be7327dc962602bfe129190da4eda9dc7c939d4614ea3`) with full patch SHA-256 `ff35298a6d9c3e745f25bc0fabe3103e5fcf93e54d1dcb1fe2ba5eb6dd9595f3`.
- [Successful patch apply 43193295001](https://github.com/akashskypatel/Directional/actions/runs/43193295001), result artifact `13931876848`, committed [source `240d2a1948c95521e9b90740244e7dd7de46483a`](https://github.com/akashskypatel/Directional/commit/240d2a1948c95521e9b90740244e7dd7de46483a). GitHub compare confirms exact changes in nine source/test files. Both transient Drive patch objects were permanently deleted; the exact v2 backup remains in ChatGPT Library `/Directional/Work-Preservation/`.
- Process deviation: direct authority-document reads preceded the mandated snapshot-mode selection during initial work. Subsequent code inspection used the verified snapshot. An initial local package-check script incorrectly treated the manifest's `./` filename prefix as a missing member; correcting that path normalization yielded 28/28 verified hashes without modifying the package.

## Assessment — immutable compile evidence

- [Compile run `43193524342`](https://github.com/akashskypatel/Directional/actions/runs/43193524342), compile job `131098730039`: **SUCCESS** on source `240d2a1948c95521e9b90740244e7dd7de46483a`. Package [artifact `13931894182`](https://github.com/akashskypatel/Directional/actions/runs/43193524342/artifacts/13931894182), outer ZIP SHA-256 `cf7b19cb429f0983eb4b90ed5c37c75ccc0bf1402586812f4b1acbc79eeaf1c6`; 28/28 internal hashes match.
- Eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Preflight exit `0`, build exit `0`; final source status clean. `metadata/gmp-evidence.txt` proves linker usage of `libgmpxx.so` and `libgmp.so`; `metadata/command-boundary.txt` records `exactArithmeticBackend=GMP` and `runtimeExecution=false`. GNU Multiple Precision (GMP) and its C++ interface (GMPXX) were both linked. The workflow mailbox result is `success` for exact source SHA and package artifact.
- No Directional runtime/test/benchmark executable ran. No selector, fixture, default option or acceptance semantics changed outside the frozen nine-file patch. The `chainRimSchedules` option remains **false by default**; production still uses per-arc schedules until an independent activation decision.
- Prior scoped runtime: TB110 944/944 MATCH, 1,025 memberships, Cylinder PASS / BunnyRandom and Vase registered RED. Accepted CP2 stays 491/491. Stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81; CP3 and selector497 unpromoted.

## Recommendation — next separate turn

- TB112 must consume **the exact immutable artifact `13931894182`**, without rebuilding. Frozen [manifest](gates/Architecture_M6_TB112_P13_A3_Rim_Chain_Switch_Staging_Full_Gate_Case_Manifest.tsv) has 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, 1,026 memberships.
- RA-230 §5 requires 945/945, all inherited TB110 receipts unchanged, ten `switch-run` receipts, and correct `perArc` coverage. The `chained` receipts are observations, not independent PASS requirements. A matching TB112 advances only to the Review-only `M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION`; mismatch or infrastructure failure follows the frozen paths in RA-230. CB131 establishes compile validity, **not** runtime acceptance.
