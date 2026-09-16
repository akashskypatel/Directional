# M4-CP-SCALE-CB12 Code + Build Report

- Phase: `M4-CP-SCALE-CB12` — selector426 publication-only
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical
- Starting semantic publication base: `05bc3ae0197d6cce6da5a47c1bd173aeb8854aa9`
- Built evidence commit: `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`
- Remote synchronization verified: yes

## Implemented

- Published `Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt` as exact selector425 bytes followed by exactly one producer identity: `M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`.
- Selector426 is 426 LF-terminated rows / 426 unique identities, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`.
- The first425 bytes remain exactly selector425, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`.
- Static owner census is **30 authority-kernel / 280 producer / 75 completion / 41 validation**; row426 is producer-owned and exists exactly once in the compiled producer test source.
- Updated `Required_Green_Selector_Manifest.md` additively for selector426. No accepted historical selector was regenerated, reordered, normalized, deduplicated or changed.
- No product, test, fixture, CMake or benchmark semantic source changed.

## Engineering-Guideline Review

- Material assumptions surfaced: TB10 Review had already accepted the S4 focused product for publication; CB12 was limited to selector publication and compile/package evidence.
- Simplest sufficient approach chosen: byte-copy selector425, append exactly one reviewed identity, update the additive manifest, compile/package unchanged semantic code.
- Why no smaller approach satisfies the contract: cumulative S4 credit requires a durable selector426 identity before fresh cumulative runtime can measure it.
- Unrelated refactors/style drift avoided: yes.
- Every changed line traces to objective/supporting validation: yes.

## Files Changed

Semantic publication commit `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` changes exactly:

- `.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt`
- `.agents/Directional/Required_Green_Selector_Manifest.md`

Temporary workflow callers/markers are control-plane state and are not semantic publication authority.

## Domain Invariants

- Selector425 remains byte-frozen and is the exact first425 prefix.
- S4 product semantics, A2a' cut ordering/proposal/saturation/repair/backtracking semantics and final certificate authority are unchanged.
- Final certificate authority remains `SurfaceCutGraphCellularityCertificate::proves_embedded_cellularity()` plus per-face disc topology.
- CB12 grants publication/compile authority only. Cumulative S4 selector credit remains withheld until TB11 execution and mandatory Review.

## Generalization Review

- Why this is not fixture-specific: publication changes only the cumulative required-green identity set; it introduces no fixture/product behavior.
- Valid input classes affected: none at runtime in this turn.
- Regression risks considered: selector-prefix corruption, duplicate/missing identity, wrong owner, stale manifest lineage, accidental semantic source mutation, non-GMP compile and unauthorized runtime execution.

## Build

- Exact source: `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`.
- Workflow run/job: `35163156552 / 105018295110`.
- Targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Result: **PASS**, preflight `directional_core` exit `0`, full build exit `0`.
- Exact arithmetic: GMP/GMPXX found and linked (`libgmpxx.so`, `libgmp.so`).
- Runtime boundary: `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery command, CTest, CLI, fuzzer, help/version command or custom input executed.
- Result artifact: `10473134357`, provider SHA-256 `aa503e4be2aa1904172c9a3710f41e7cf0ccd352575b39078ece61b7d5d660b9`.
- Activity-log artifact: `10472809674`, provider SHA-256 `2e06d75866a328045ccd0a27334feeb1e616f7d54830f3d5d5488135ca03a266`.
- Packaged source archive SHA-256: `190233bd050a2d1a6c042217f11294f38fc29fdc62d9c6b124a84fefb914d570`.
- Package `SHA256SUMS`: 28/28 verified; manifest SHA-256 `2dbacc439ed714d9c8dfd5c3be5e2d9942a0fe99737aa1f9a0281632d21cf0c8`.
- All source-status receipts are empty/clean.
- Tests or benchmarks executed: none.

## Work-Preservation / Publication Transport

- Preservation patch: `Directional__M4-CP-SCALE-CB12__base-05bc3ae0197d__work-preservation.patch`.
- Patch SHA-256: `3ea4a502cd3e941dd08140f697565ef44099c339fa1cc9c3fea5cad883ba5bb5`.
- Diff-body SHA-256: `fc8cb8056cceb588fcb97fbdf65838c7131c26a386f28dab37cad854edd5bdc9`.
- Drive-apply run/job: `35162958375 / 105017670497`.
- Applied semantic commit: `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`.
- Drive patch workflow could not trash the owner file; owner-authorized connector cleanup then permanently deleted it after successful application/evidence capture.

## Known Risks

- Selector426 has not executed yet. Publication compile success does not imply cumulative S4 runtime acceptance.
- `M4-CP-SCALE-TB10-REV-OBS-01` remains open through TB11 and mandatory Review.

## Mandatory Test + Benchmark Plan

- Plan reference: `Architecture_M4_CP_SCALE_TB11_Artifact_Only_Test_Benchmark_Plan.md`.
- Evidence commit/artifact under test: `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / artifact `10473134357`.
- Focused/reproduction validation: row426 is included naturally as the final exact selector process; no separate focus process is needed.
- Related regression validation: exact selector426 all rows.
- Integration/full/platform validation: 426 fresh exact-filter processes in exact file order with owner census and immutable postflight.
- Benchmarks: not applicable for this publication-only acceptance surface.
- Acceptance criteria: 426/426 PASS, zero anomalies, exact owner census 30/280/75/41, exact immutable package/source/postflight.
- Stop/blocker conditions: any artifact/source/hash/owner mismatch, selection mismatch, RED/SKIP/crash/timeout/unexecuted row, mutation/rebuild/repair attempt, or postflight change.

## Next Turn

Type: Test + Benchmark
Next subturn: `M4-CP-SCALE-TB11-EXEC`

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`
- Test plan linked: yes
- Updated or verified unchanged: TODO, changelog, frozen definitions, M4 consolidated record, roadmap, selector manifest.
- Agent entry-point links verified: yes.
- New lesson recorded: none; existing publication/compile/runtime boundary rules were sufficient.
