# CB58 — DIAG-RETAIN A5–A7 snapshots (2026-10-31)

- **Turn:** `M6-CB58-DIAG-RETAIN-A5-A7-SNAPSHOTS`; Code + Build, compile-only. It was run locally while the implementation agent was unavailable.
- **Authority:** [RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md) §.5 and §.7.
- **Patch:** extracted from the committed RA-184.7 block.
  - SHA-256 `c72e47cc54c407af5921bf80aaeec043bd3add928b24046dfc879f56e9041b0e`; `git apply --check` passed.
  - Numstat `27 0` (`include/directional/pipeline/RemeshPipeline.h`), `39 3` (`src/pipeline/RemeshPipeline.cpp`), `47 0` (`tests/SurfaceCellTransitionQuotientTests.cpp`) and `50 0` (`tests/SurfaceCellsPhase10Tests.cpp`).
  - The resulting SHA-256 values are `37f85237…`, `47d77eb7…`, `358dabad…` and `913b97e7…` (the full values are in RA-184.5). All exact.
- **Source:** commit `58ddfef02fc0803092c3fc0967c99fe47a6bc0bf`.
- **Build:** a fresh out-of-tree configure of a clean worktree, with the CI flags at default arithmetic. Eight targets, 151/151 steps, exit 0, from 04:16:38Z to 04:22:45Z.
- **Package:** `build/local-evidence/CB58/pkg.zip` (gitignored).
  - ZIP SHA-256 `241aeebd9c925782868f6546399e581bcd4282639231908c02ede2983477cbbb`; root `SHA256SUMS` `8e154d568109798caa55ed88bfeed01890e4dec759be24338a6159f6d140a972` (18 entries); source archive `d2f9f01a…`.
  - A Haiku subagent staged the package; the Review agent re-verified the ZIP, the checksum list, `command-boundary.txt` and byte equality of all eight outputs with the build.
- **No native tests were executed in CB58.**
- **Next:** `M6-TB57-DIAG-RETAIN-FULL-GATE-EXEC`: gate `f898c9b6…` (861), ledger v4 (82), membership 943, with row 283 the only pre-registered red (RA-184.6).
