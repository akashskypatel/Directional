# CB13A — Open-rail chain interval truth table

- Turn: `M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` (RA-88.4).
- Scope: test-only, `tests/SurfaceCellsPhase10Tests.cpp`; one expectation corrected, three discriminating rows added.
- Snapshot source: `54375fdacae67eeaf6a931cf1ec922eff76b32b6`, run `39116386598`, archive artifact `12131434973`; source checks 5659/5659.
- Applied semantic commit: `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b`, exactly one test file changed.
- Verified patch SHA-256: `c7577413d0060b6f7e6150a7f03d414902a7cf5006cf0ed22f83330704a0fed4`.
- Patch application: run `39117029883`, result artifact `12132488580`, successful; staging file deleted.
- GMP/GMPXX compile: run `39117126811`, result artifact `12132184878`.
- Result ZIP SHA-256: `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072`.
- Verification: 28/28 packaged hashes; eight/eight requested targets; preflight and build exits both zero.
- `DIRECTIONAL_ENABLE_GMP=ON`; generated link includes `libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`.
- Five source-status snapshots empty; `runtimeExecution=false`; no binaries, tests, or benchmarks executed.
- Selector 497, code semantics, and accepted runtime evidence unchanged.
- Closeout completed by Review (RA-89): package independently verified (root manifest `bdb4ad98…`, source archive `25ec06e7…`); successor `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`.
- Procedure note: read-mode selection occurred after initial handoff/TODO reads; corrected by exact snapshot before source analysis.
