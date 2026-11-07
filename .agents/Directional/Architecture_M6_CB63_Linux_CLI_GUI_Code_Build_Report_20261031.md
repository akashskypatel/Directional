# CB63 — Linux CLI and GUI ten-target compile evidence (2026-10-31)

**Turn:** `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` (Code + Build, runtime-free). **Outcome: COMPILE/PACKAGE PASS, semantic acceptance withheld.** Executed through the durable `agent-operation-dispatcher.yml` → `agent-compile-reusable.yml` on Ubuntu 24.04. No product/test/fixture/selector behavior was changed; no product executable, GUI, tests or benchmarks ran.

## Source and build history

- Initial reusable-workflow correction `1be60fa771352a04117ec45933cb61f0c9e014e2`: request-selected CLI/GUI options and mandatory binary/link checks; YAML schema validation passed at GitHub run `41202467041`.
- First ten-target attempt [41202554478](https://github.com/akashskypatel/Directional/actions/runs/41202554478) failed during CMake configure: unavailable X11 development include/library for GLFW; no package or runtime evidence. Compile job `124541127249`, diagnostic artifact `13043162853`.
- Environment correction `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`: provision Linux X11/GL development dependencies only when GUI requested. Exact workflow YAML schema preflight passed at run `41202825830`.
- Frozen successful compile source: `f6113c4eb0fbf6a02350eee2d37e7e4dab821429` (source contained only workflow/build-orchestration corrections relative to prior semantic authority). Dispatcher request commit `63251d66e47d19d29b62c1e9e5fa9e1efd723040`, request `m6-cb63-linux-cli-gui-compile-20261031-v2`. [Successful Actions run 41202931582](https://github.com/akashskypatel/Directional/actions/runs/41202931582), compile job `124542235337`; authoritative orphan mailbox `.workflow-mailbox/m6-cb63-linux-cli-gui-compile-20261031-v2/latest.json`, result `success` and matching request/source identity.

## Independently verified immutable package

- Result ZIP artifact **`13043004468`** (`m6-cb63-linux-cli-gui-compile-v2-result-41202931582`), ZIP SHA-256 **`14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`**. Downloaded once, verified SHA-256 against GitHub artifact metadata, extracted and independently checked **30/30** entries against `SHA256SUMS`.
- Diagnostic ZIP artifact **`13043198704`**, SHA-256 **`e58a088f7a86a6be6963d46fc583c4897dda3f2dda7fcceef8c7793854f32c83`**. Its activity log agrees with manifest verification and clean source status.
- `metadata/source-commit.txt` equals frozen SHA; `metadata/preflight-exit-code.txt=0`, `metadata/build-exit-code.txt=0`. Build log includes `[226/228] Linking CXX executable directional` and `[228/228] Linking CXX executable directional-ui`.
- Packaged `CMakeCache.txt`: `CMAKE_BUILD_TYPE=Release`, `BUILD_SHARED_LIBS=OFF`, `DIRECTIONAL_ENABLE_GMP=ON`, `DIRECTIONAL_BUILD_CLI=ON`, `DIRECTIONAL_BUILD_GUI=ON`. `metadata/compiled-targets.txt` enumerates ten requested targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`, `directional_cli`, and `directional_gui`.
- Artifacts include `bin/directional`, `bin/directional-ui`, six additional compiled executables, and two core libraries. `metadata/gmp-evidence.txt` contains authoritative generated link commands for both `directional_cli` and `directional_gui`, each including `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`; CMake found both headers and libraries. `metadata/command-boundary.txt` states `runtimeExecution=false`, `exactArithmeticBackend=GMP` and `turnBoundary=Code+Build-only`.

## Acceptance boundary and handoff

CB63 fulfills the **Linux compile/link and immutable package** obligations only. Do not credit package success as semantic acceptance, full-gate Test + Benchmark execution, 11 CLI checks, or visible GUI rendering. Linux TB61 **863/863** was on the earlier eight-target package; accepted CP2 **491/491**, stable **66/17/49**, debt **1**, frozen selector497 and macOS O16 remain unchanged. PR #8 stays draft.

**Authorized next turn (not executed here):** `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC`. Execute the immutable CB63 package **without rebuild/relink/configure**; full frozen TB58 863-case manifest, 82 DEFERRED (membership 945), separately registered existing Linux CLI verification (including applicable 11 checks), and GUI artifact/link verification. The GUI appearance check remains manual. Reference the frozen TB62 plan and this report.
