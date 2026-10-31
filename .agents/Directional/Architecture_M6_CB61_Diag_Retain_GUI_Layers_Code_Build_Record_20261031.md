# CB61 — DIAG-RETAIN GUI layers (2026-10-31)

- **Turn:** `M6-CB61-DIAG-RETAIN-GUI-LAYERS`; Code + Build, compile-only. It was run locally while the implementation agent was unavailable.
- **Authority:** [RA-187](Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md) §.4 and §.7.
- **Patch:** extracted from the committed RA-187.7 block.
  - SHA-256 `afab7d5dc08ec1976b0ef36b22c34757b295f6b010753edf2b26fa7565983e4e`; `git apply --check` passed.
  - Numstat `5 0` (`src/gui/GuiBackend.h`), `5 0` (`src/gui/GuiRemesh.cpp`) and `52 8` (`src/gui/Main.cpp`).
  - The resulting SHA-256 values match RA-187.4 (`6cc1c79a…`, `8a4ed4a9…`, `c601f6e7…`).
- **Source:** commit `e1fd0e4b7560c4fa5bde96853b978d336c522e8f`.
- **Build:** a fresh out-of-tree configure of a clean worktree with the CI flags plus `-DDIRECTIONAL_BUILD_CLI=ON -DDIRECTIONAL_BUILD_GUI=ON`, at default arithmetic. Ten targets (the eight gate targets, `directional_cli`, `directional_gui`): 311/311 steps, exit 0, from 05:23:49Z to 05:31:09Z.
- **Packages** (gitignored, under `build/local-evidence/CB61/`):
  - `pkg.zip` (standard eight-target layout): ZIP `f39152f78024cff5b0f8a15c62fa078f77e2373d768cbd5592eceb17672caf83`, root `SHA256SUMS` `1c5cccb9a3cee5ef3e99154ffc828a40d30a2bc5f992a6177ddc44bde99b525e` (18 entries), source archive `2caf2ece…`.
  - `tools.zip` (`bin/directional`, `bin/directional-ui`): ZIP `c324950f2fdabb2b81f154d88aea2ee92c153b2c88609113211ec59a6f453196`, `SHA256SUMS` `5cf3fd2d…` (8 entries).
  - A Haiku subagent staged both; the Review agent re-verified both ZIPs and checksum lists, `command-boundary.txt` and byte equality of all ten outputs with the build.
- **No native runs were executed in CB61.**
- **Next:** `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` (RA-187.5).
