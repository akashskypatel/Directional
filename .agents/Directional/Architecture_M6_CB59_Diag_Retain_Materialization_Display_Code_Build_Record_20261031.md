# CB59 — DIAG-RETAIN materialization display adapter (2026-10-31)

- **Turn:** `M6-CB59-DIAG-RETAIN-MATERIALIZATION-DISPLAY`; Code + Build, compile-only. It was run locally while the implementation agent was unavailable.
- **Authority:** [RA-185](Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md) §.4 and §.7.
- **Patch:** extracted from the committed RA-185.7 block.
  - SHA-256 `78108421ae9e3ccff4cd537e0eb882f75d87d3caf3e6c04259e750dd9485023d`; `git apply --check` passed.
  - Numstat `1 0` (`CMakeLists.txt`), `1 0` (`cmake/DirectionalTests.cmake`), `65 0` (new header), `167 0` (new source) and `188 0` (new tests).
  - The five resulting SHA-256 values match RA-185.4 (`7b3eadf6…`, `50c9f938…`, `430e8650…`, `6c2a6f78…`, `db2a2fa0…`).
- **Source:** commit `39a77d2ef90602a19245ddfc5a73a3d9b753c3ee`.
- **Build:** a fresh out-of-tree configure of a clean worktree, with the CI flags at default arithmetic. Eight targets, 153/153 steps, exit 0, from 04:49:59Z to 04:56:10Z.
- **Package:** `build/local-evidence/CB59/pkg.zip` (gitignored).
  - ZIP SHA-256 `1bd8c0bae40a17d0eb50a07820407bc901c9d65c1c05a8db2e8387202831263b`; root `SHA256SUMS` `fb1ac1eaa4192687c4d6ca2fe9fa8f7db004cbfe99b16b79590f98284bd991af` (18 entries); source archive `0fa1bd04…`.
  - A Haiku subagent staged the package; the Review agent re-verified the ZIP, the checksum list, `command-boundary.txt` and byte equality of all eight outputs with the build.
- **No native tests were executed in CB59.**
- **Next:** `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC`: gate `31c1360a…` (863), ledger v4 (82), membership 945, with row 283 the only pre-registered red (RA-185.5).
