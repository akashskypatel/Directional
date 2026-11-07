# R4 Eigen mirror dependency blocker remediation (2026-10-11)

**Scope:** infrastructure-only repair of the Eigen checkout failure from workflow 38178491667, during active canonical `M6-CP3-CB1-ENTRY-R4`. No SurfaceCells implementation changes, runtime tests, benchmarks, review/definition amendments, or successor turn.

## Source change

- Changed `.gitmodules` `submodule.external/eigen.url` from `https://gitlab.com/libeigen/eigen` to `https://github.com/eigen-mirror/eigen`.
- Changed `backupUrl` to `https://gitlab.com/libeigen/eigen`, preserving the prior primary as fallback.
- Direct source commit: `37c349948758328ac9bfac303a93d431b5b3e8e7`.
- The gitlink remains pinned to `769c72fd8019e389810d1de1e7c243521a43b594`, independently resolved in the mirror's Git object API before editing.
- The dispatcher request at `e10364955b6af00373f06cd7e6efcf538660ee7d` requested a compile of **that exact source commit**, not the orchestration event commit.

## Authoritative compile evidence

- Dispatcher workflow: https://github.com/akashskypatel/Directional/actions/runs/38183615883
- Compile job: `114601230999`, **success**.
- Checkout log explicitly records `Submodule 'external/eigen' (https://github.com/eigen-mirror/eigen)`, `From https://github.com/eigen-mirror/eigen`, and checkout of `769c72fd8019e389810d1de1e7c243521a43b594`.
- Source evidence: `metadata/source-commit.txt` = `37c349948758328ac9bfac303a93d431b5b3e8e7`.
- Preflight/build exit codes: `0/0`. All eight requested targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `DIRECTIONAL_ENABLE_GMP=ON` verified in the packaged CMake cache. An authoritative link command contains both `libgmpxx.so` and `libgmp.so`.
- Downloaded result ZIP artifact `11719135402`, provider SHA-256 `b258929b712bd7251aab69a3e2a96866d7267f3d7f995d7b3109f054a219c0e7`; verified packaged `SHA256SUMS` **28/28**.
- Diagnostic log artifact `11719225264`, provider SHA-256 `f396c701e7d660217b09d953517162e6dde15709fd488495565c2be4035e9334`.
- Source status after compilation was empty. Package `command-boundary.txt`: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.

**Disposition:** The GitLab-hosted Eigen clone failure is resolved by switching primary checkout to the user-designated GitHub mirror. This is infrastructure verification only, **not** a runtime regression restoration or completion of R4. Continue to honor the user-directed pause on broader implementation; the separate terminal-A3 dual-path independent Definition/Review question and other R4 obligations remain unresolved. No frozen Test + Benchmark work is authorized here.
