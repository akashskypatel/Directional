# CB17 — factory rail-vertex endpoint, compile-only (2026-10-19)

- **Turn:** `M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` (U4, RA-102.4).
- **Semantic source:** `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e`; four paths changed: tracing header/source, pipeline digest, Phase 10 tests.
- **Patch:** exact source snapshot `287b53252d756607834a722abfad1cbb94faa773`, staged SHA-256 `8d8dc2555330fde77bb758d06f83674442873ad187c384fbb22329969f0bb2a1`; applied in workflow `39306253290`.
- **Build:** [run 39306529387](https://github.com/akashskypatel/Directional/actions/runs/39306529387), immutable result artifact `12214741070`, outer ZIP SHA-256 `9acb50815485cb597d5673d3daab473ad140eb8aaddcd0a2dbe7d4c435b45ca5`.
- **Verification:** 8/8 prescribed build targets, GMP/GMPXX link, packaged exact source/hash checks and `exactArithmeticBackend=GMP` established by immutable package evidence.
- **Execution boundary:** `runtimeExecution=false` — no tests, benchmarks or compiled binaries executed; CB17 is not a semantic test pass.
- **Scope:** typed R field, interval anchor rules, pure eligibility helper, star incidence, factory R validation, closed-rail R exclusion, conditional R digest; existing I/T/C and consumer unchanged. Added only the two RA-102.4 truth tables.
- **Frozen:** selector 497 unchanged; ledger 66/17/49, debt 1, CP2 491/491, rejected R3 403/497, candidate census 425/497. RP-01 open, RP-02 UNREACHED, Gate C suspended.
- **Next separate turn:** `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` (RA-102.5), artifact-only 13-identity TB16A-derived harness. Any falsifier goes to independent Review.
