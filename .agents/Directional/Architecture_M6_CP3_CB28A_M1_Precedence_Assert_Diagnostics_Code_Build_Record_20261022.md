# CB28A — three M1/A5 rejection messages, code/build (2026-10-22)

- Canonical turn: `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS`; RA-136.3, Code + Build, test-only.
- Exact semantic source: `4473e41e94a35f1bf189fa046e86bac92c7391fb`; base snapshot `b04b0391f3d2b046d76d729f40ebf3d6448456d4` (5793/5793 hashes).
- Patch: `b533844d82ca111a09bb25f79f6e34f02d457ed4a54de6d0520de9bf6357118c`; GitHub apply [run 39867608521](https://github.com/akashskypatel/Directional/actions/runs/39867608521), result `12465430306` verified.
- Only `tests/SurfaceCellTransitionQuotientTests.cpp` changed (+16/-3); exact three asserts in the three named RA-136.2 tests. A5 streams `a5_rejection_message`; both factory asserts stream guarded `describe_phase_front_product_error`. No decisions, assertions, expected results, fixtures, selectors, workflow, or production code changed.
- Compile: [run 39867988763](https://github.com/akashskypatel/Directional/actions/runs/39867988763), result `12465330920`, outer artifact ZIP SHA-256 `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`; 8/8 targets and 28/28 packaged checksums verified; preflight/build exit 0/0.
- GMP backend: `DIRECTIONAL_ENABLE_GMP=ON`; generated link evidence includes `gmpxx` and `gmp`; `exactArithmeticBackend=GMP`.
- `runtimeExecution=false`; no binaries, tests or benchmarks executed; no CP3 runtime acceptance or selector/count promotion claimed.
- Preliminary unsuccessful orchestration [run 39867859128](https://github.com/akashskypatel/Directional/actions/runs/39867859128): request `targets` was string not array; parsing failed before compilation; corrected request `r2` compiled source unchanged.
- Stable 66/17/49, debt 1, accepted CP2 491/491; R3 403/497 rejected, TB28 462/497 candidate; selector 497 frozen, RP-01 open, RP-02 unreached.
- Exact successor: independent `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS-REV` Review; static scope and immutable package verification before TB29.
