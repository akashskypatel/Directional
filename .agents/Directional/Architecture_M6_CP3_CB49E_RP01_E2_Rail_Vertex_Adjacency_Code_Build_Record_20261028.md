# CB49E RP-01 — E2 rail vertex adjacency (2026-10-28)

- **Turn:** `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY`; Code + Build, compile only.
- **Authority:** RA-168 §.5 and §.10, after compiled CB49 P1 `9c84ba9cc8e44acf556d17e2357b1e9458337cca`.
- **Exact P2:** SHA-256 `9ebef3cc2427a93c21c7c9d1660b9677998fc379a9acccac947eb9928f96a29f`, applied verbatim with no edits.
- **Semantic source:** `092b52eba881e3bafbff4fa263f84f96cf648838`; Drive apply [run 40770171367](https://github.com/akashskypatel/Directional/actions/runs/40770171367), result artifact `12851293841`.
- **Numstat:** `tests/SurfaceCellTransitionQuotientTests.cpp` +215/−255; no other semantic, selector, manifest, workflow edits.
- **Compile:** [run 40770409537](https://github.com/akashskypatel/Directional/actions/runs/40770409537), workload job `123107239241`; eight established targets passed.
- **Immutable package:** artifact `12852132570`, ZIP SHA-256 `24a0beb14cc0766a7f77ba5c5ccdffc76b5bbfbe798c11170d6db2ba1c94d022`; log artifact `12852626777`.
- **Verified package:** 28/28 internal SHA-256 members match, exact source, `DIRECTIONAL_ENABLE_GMP=ON` configuration, `gmpxx` and `gmp` in link, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; build/preflight exit codes 0 and empty source status.
- **Scope:** no compiled binary tests, benchmarks, CLI or GUI executed. Compile success does not imply TB49 gate acceptance or CP3 promotion.
- **Preserved patch:** 30,134 bytes; full SHA-256 `2c9faf7209d2037de229cc484d051c15aeaeea258ecfc3a9ec2b653b808b3d99`, ChatGPT Library `/Directional/`; temporary Drive staging retired after push.
- **Stable baseline:** CP2 491/491 accepted; TB48 502/2 unpromoted; stable 66/17/49 debt 1; PR #8 draft/unmerged.
- **Authorized next turn after documentation/cleanup closeout:** `M6-CP3-TB49-RP01-FULL-GATE-EXEC`, frozen manifest `a0e39fa25d70…`, expected 504/0 (not yet executed).
