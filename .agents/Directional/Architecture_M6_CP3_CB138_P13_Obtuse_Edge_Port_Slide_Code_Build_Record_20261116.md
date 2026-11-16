# CB138 Code + Build — obtuse-face edge port and exact slide

## Situation
`M6-CP3-CB138-P13-OBTUSE-EDGE-PORT-SLIDE` completed its exact source patch and eight-target compile. The separate TB119 turn owns runtime tests, benchmarks, and production census.

## Background
- RA-238 §4 froze the exact four-file patch `.agents/Directional/Architecture_M6_CP3_CB138_P13_Obtuse_Edge_Port_Slide_Exact.diff`, SHA-256 `53985fef66e2e7262d4624c79f5b037e58e4760f4db18403d37c683a4e0e5d60` (+211/−25). A1 now checks the exact along-edge rate in both incident faces; A2a slides an edge-supported port to the carrier's far vertex. Ordinary grazing remains unchanged. The new `FieldTransportAtlas.PublishesEdgeSupportedPortFromFaceObtuseAtVertex` test is compiled, not executed.
- Exact pre-patch snapshot: `0a7b1d8cd3c0101390b02e2e5b9555d28cd1a092`, [run 43796071420](https://github.com/akashskypatel/Directional/actions/runs/43796071420), source artifact `14194452391`; 5,545/5,545 snapshot file hashes verified.
- Patch transport SHA-256 `14ea418a6054305173e97304c661ac31b083e4181b316e0540ba9b6f85115501`; [apply run 43796582181](https://github.com/akashskypatel/Directional/actions/runs/43796582181), result artifact `14194662123`, successful exact application at source commit `2e551bdd9ac72ccf3cd65326d58aa7911adee36f`. Temporary Drive patch ID `1RmHMyLyMnOAL2Wve12mvaw6DCzqnrc2k` was deleted through the owner-authorized connector.

## Assessment
- [Compile run 43796972574](https://github.com/akashskypatel/Directional/actions/runs/43796972574) **SUCCESS**. Exact source commit `2e551bdd9ac72ccf3cd65326d58aa7911adee36f`; result artifact `14195465639` SHA-256 `5f7cc46b03b491f95ec907bfccc3a81afd4f36d3cb49330494df2de4fed498ac`; compile-log artifact `14195440746` SHA-256 `1bec8be3bb0e5ff06d21ccad0b7b0e5df94d40fa41e86a1d0e04696c09f9d1b0`.
- Package verified against all 28/28 internal SHA-256 entries, including the source archive. Both preflight and build exit codes are `0`; source tree is clean. The eight targets are `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.
- CMake found GMP and GMPXX; linked libraries include `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`. Package boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`. No tests, benchmark binaries, or production census executed.
- One procedural miss in the initial response: repository documents were read before selecting mandatory snapshot read mode. The miss was disclosed; remaining source inspection used the verified snapshot. This does not change the compile evidence.
- Carried unchanged: CP2 491/491, stable 66/17/49, debt 1, deferred 81; `chainRimSchedules=false`; CP3/selector497 not promoted; O42 and O43 open; D11=A, D10 deferred.

## Recommendation
**Next separate turn:** `M6-CP3-TB119-P13-OBTUSE-EDGE-PORT-SLIDE-FULL-GATE-EXEC`, artifact-only, using the immutable CB138 package. RA-238 §5 specifies the 947-row gate manifest `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b` and the independent three-case census. Do not recompile or promote CP3/selector497 based on this Code + Build result.
