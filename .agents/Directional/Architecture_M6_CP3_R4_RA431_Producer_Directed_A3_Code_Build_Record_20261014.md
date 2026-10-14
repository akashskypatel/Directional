# R4 RA-43.1 — producer-backed hard-carrier directed A3 values

Canonical turn: `M6-CP3-CB1-ENTRY-R4`, Code + Build only. No frozen selector changes, runtime execution, TB497, or successor.

## Source and implementation

Verified source snapshot `39ca3697a49e60a5a552a7f246856c652f6125af`, [workflow 38499078105](https://github.com/akashskypatel/Directional/actions/runs/38499078105), immutable artifact `11865161157`, outer SHA-256 `1f61ffbcd03a6bce9749a12b862a5591e2fa7fffdc8d22454fcfa76b5bfb7108`; inner archive hash valid, **5803/5803** file hashes valid. The source test `ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit` in `tests/SurfaceCellsPhase10Tests.cpp` now asserts that each truly producer-published hard-carrier source edge publishes reciprocal A3 transition values (inverse `QuarterTurn`, negative signed lift and effort), while `transport` and ordinary adjacency remain absent. This is a source-level regression, not executed evidence.

Exact verified patch: `baf45e664e6c904a53e0215ed32d012e5fb094d62a3a16fea72594f9aedc9a66`; diff body `8a987c1b99843ad70095cf157da6ba3657d8127abf4fc76e616ddcbda1798533`. Exact-base forward/reverse apply and whitespace checks passed. Preserved Library backup: `/Directional/Work-Preservation/directional-r4-ra431-producer-directed-value-20261014.patch`.

Applied via [workflow 38499979369](https://github.com/akashskypatel/Directional/actions/runs/38499979369), immutable result artifact `11865038180` outer SHA-256 `ea523c86e2d5edd302d673b3e272d9f5e5ed0ec362449a05d2f99f4742bc8bdc`; result `job_status=success`, `runtimeExecution=false`, correct base, patch SHA, and applied commit `7e633b81bb0d3ea37fdac1961a31cb7b72f1449a`. GitHub commit independently confirms **only** `tests/SurfaceCellsPhase10Tests.cpp` changed; staged Drive patch owner-deleted.

## Compile handoff

Exact-source eight-target GMP/GMPXX compile triggered at dispatcher commit `46d5ef0906cf8066da6e9e59cd338e05fba0535f`, source `7e633b81bb0d3ea37fdac1961a31cb7b72f1449a`, mailbox `.workflow-mailbox/m6-cp3-r4-producer-directed-a3-compile/latest.json`, artifact prefix `directional-m6-cp3-r4-producer-directed-a3-compile`. **Exact-source compile GREEN**: [workflow 38500189196](https://github.com/akashskypatel/Directional/actions/runs/38500189196), immutable result artifact `11865173564`, outer SHA-256 `d6baafb1c8fd48f0471a3045cc5b840bd6237c0b704fe0b91f9d1850b19481e1`. Independently verified **28/28** recursive SHA256SUMS entries (manifest paths start `./`), all eight approved targets, exact source commit `7e633b81bb0d3ea37fdac1961a31cb7b72f1449a`, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, linker with `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`, five empty source-status checkpoints, and `runtimeExecution=false`. Dispatcher validation/compile/mailbox jobs succeeded; test/benchmark job skipped. **Assertions were compiled, not executed.**

R4 remains unfinished: broader RA-43.1/43.4, reachable RA-46.5, RA-47.12 runtime liveness in separate TB, historical 39/34/7/88/six, organic D1/D2/D3/D5/A6/A7, genuine multi-carrier odd-τ. No successor.
