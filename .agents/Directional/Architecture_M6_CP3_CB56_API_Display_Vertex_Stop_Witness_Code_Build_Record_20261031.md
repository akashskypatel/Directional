# CB56 — API display vertex-stop witness (row 935) (2026-10-31)

- **Turn:** `M6-CP3-CB56-API-DISPLAY-VERTEX-STOP-WITNESS`; Code + Build, compile-only. It was run locally while the implementation agent was unavailable.
- **Authority:** [RA-182](Architecture_M6_CP3_DEFN_API_Display_Vertex_Stop_Witness_20261031.md) §.4 and §.7.
- **Patch:** extracted from the committed RA-182.7 block.
  - SHA-256 `ffb723f4f664a6517d18620aa7de42a9ecda081e5941f00f04993fbbe0121224`; `git apply --check` passed.
  - Numstat `46 8` (`tests/SurfaceCellTracingDisplayTests.cpp`). The resulting SHA-256 is `f32540153871bd6d6c2f453f5e3784f9f392ab4fdafcb274f496f3a3ee199974`. All exact.
- **Source:** commit `567d1828301f74a6e3c50bfcdfc4f7e6819d1ad3`.
- **Build:** a fresh out-of-tree configure of a clean worktree, with the CI flags at default arithmetic. Eight targets, 151/151 steps, exit 0, from 00:45:13Z to 00:51:05Z.
- **Package:** `build/local-evidence/CB56/pkg.zip` (gitignored).
  - ZIP SHA-256 `26d88d2097ff87057dc27c42a4bfd41f6c4c43bc840f2dccbb915dd10cb26cb0`; root `SHA256SUMS` `ddf68443ebd7588a2a7c631719c289d320ac43a12b1b9e705d5e33ad998e4f4d` (18 entries); source archive `07c5c167…`.
  - A Haiku subagent staged the package; the Review agent re-verified the ZIP, the checksum list, `command-boundary.txt` and byte equality of all eight outputs with the build.
- **No native tests were executed in CB56.**
- **Next:** `M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC`: gate `eb508378…` (858), ledger v4 `36241caa…` (82), membership 940, with row 283 the only pre-registered red (RA-182.5).
