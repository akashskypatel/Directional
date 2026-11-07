# CB60 — DIAG-RETAIN CLI materialization sidecar (2026-10-31)

- **Turn:** `M6-CB60-DIAG-RETAIN-CLI-SIDECAR`; Code + Build, compile-only. It was run locally while the implementation agent was unavailable.
- **Authority:** [RA-186](Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md) §.4 and §.7.
- **Patch:** extracted from the committed RA-186.7 block.
  - SHA-256 `d14aaeff98b662c70e49f0a64f3dfad4df355e97320301a6341d4d7ad2e2a784`; `git apply --check` passed.
  - Numstat `12 0` (`src/cli/RemeshCommand.cpp`) and `2 0` (`src/cli/Usage.cpp`).
  - The resulting SHA-256 is `418fbf8b…` and `91817875…` (the full values are in RA-186.4). All exact.
- **Source:** commit `a31f2d39f38b01b855c7c17193d124f9b7af2b14`.
- **Build:** a fresh out-of-tree configure of a clean worktree with the CI flags plus `-DDIRECTIONAL_BUILD_CLI=ON`, at default arithmetic. One target, `directional_cli` (executable `directional`): 119/119 steps, exit 0, from 05:12:48Z to 05:16:24Z.
- **Package:** `build/local-evidence/CB60/pkg.zip` (gitignored).
  - ZIP SHA-256 `c867573b835468c1ef15ec4d4e474d4a60d0da2faed27f3c3d3baeb49c1fa345`; root `SHA256SUMS` `c6de6427e32908069b0f87fe0aca366b08703583d2529b562537b30e2378c64d` (11 entries); source archive `3ffff32c…`; `bin/directional` `380131ab…`.
  - A Haiku subagent staged the package; the Review agent re-verified the ZIP, the checksum list, `command-boundary.txt` and byte equality of `bin/directional` with the build. The `static-gmp` platform label means static Directional libraries with GMP enabled, as in every local package; GMP itself is linked dynamically from Homebrew (`gmp-evidence.txt`).
- **No native runs were executed in CB60.**
- **Next:** `M6-TB59-DIAG-RETAIN-CLI-EXEC`: the three registered CLI runs (RA-186.3 and §.5).
