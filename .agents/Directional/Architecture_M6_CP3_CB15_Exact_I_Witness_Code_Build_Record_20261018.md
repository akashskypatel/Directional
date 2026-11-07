# CB15 exact interior source-edge witness — Code + Build

- Turn: `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (RA-96.4).
- Semantic source: `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`.
- Patch: `09396c760c395c729546ba7b515eb0fecd5c4b1ba4b832f8e693ba4aad6e1aba` (base `4919887514143ede74e80a74b104b430829991fd`).
- Apply: [run 39166277967](https://github.com/akashskypatel/Directional/actions/runs/39166277967), result `12150916652`, exact three authorized source/test paths.
- Change: canonical interior `ExactSourceEdgePoint` in `SurfaceTracePoint`, single rounding helper, bit-exact binding, conflict-clearing dedup, four rejection-only witness probe fields, three compiled P10 tests.
- No authority/checker admission, selector, other producer, fixture baseline or regression ledger changes.
- Build: [run 39166755633](https://github.com/akashskypatel/Directional/actions/runs/39166755633), artifact `12150973440`, outer ZIP SHA-256 `7f56c6a551494ab4e5b9276719946e358ea23bd8b2c5bddec94014796d76c073`.
- Required eight targets: all compiled; GMP/GMPXX link verified, `DIRECTIONAL_ENABLE_GMP=ON`; `exactArithmeticBackend=GMP`.
- Package: 28/28 checksums, five empty source-status checkpoints, preflight/build exits 0/0.
- `runtimeExecution=false`; no Directional runtime, test or benchmark executed.
- Next: `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (RA-96.5, immutable nine-case harvest).
- Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB14A 425/497, selector 497; `RP-01` open, `RP-02` UNREACHED.
