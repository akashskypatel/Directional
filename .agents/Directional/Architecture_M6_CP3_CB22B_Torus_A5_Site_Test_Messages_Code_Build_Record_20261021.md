# M6 CP3 CB22B — A5 isolation-site test-message compile record (2026-10-21)

- Authority: RA-119.4; exact semantic source `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`.
- Base `f082d9aebce0ad72906ccbf70c37a4bf90a9ae6f`, unchanged TQ blob `cff5e9909e5614ec754ea67cfe646447af846726`; only `tests/SurfaceCellTransitionQuotientTests.cpp` changed, **+22/−24**.
- Changed TQ old line ranges: 957–960 (new helper); 970–982 (first-failure substitution); 6005–6011; 6190–6196; 6472–6487; 6544–6559.
- Messages now expose `;site=<isolationSite>` when present; no assertion condition, fixture, selection, control flow, runtime, or production-source change. No added line exceeds 100 columns.
- Verified patch body SHA-256 `e81a82f9c5a7a79a0479e22e305eb17c798f6450c724acde1ae54be6b9924e1c`; GitHub application [39590855567](https://github.com/akashskypatel/Directional/actions/runs/39590855567), result `12342291248` SHA-256 `90bb69d29dc175bdc2ff43ccb1d6206e5961de36c02cc6682fb2b23183594be3`.
- Eight-target GMP/GMPXX compile [39591106454](https://github.com/akashskypatel/Directional/actions/runs/39591106454), package `12341307713`, ZIP SHA-256 `b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5`; expires 2026-10-28T11:21:37Z.
- Package `SHA256SUMS` **28/28** verified; root manifest SHA-256 `7c396be65a3138eca15ad4c7a37db192d6828b80442a656d38f84d1887767f11`; packaged source tar SHA-256 `c3779cc949a97fd8b6ce73e62fc8cc62598c637e362bb57cc5f5ecb52cd0cd75`.
- Packaged TQ matches the edited source byte-for-byte; 8/8 requested targets, preflight and build exit `0`, all five source status files empty, `DIRECTIONAL_ENABLE_GMP=ON`, actual GMPXX/GMP generated link; `exactArithmeticBackend=GMP` and `runtimeExecution=false`.
- **Acceptance boundary:** compile GREEN only. No binaries, tests, benchmarks or TB23 executed. Frozen selector 497, 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB21 449/497 candidate. `RP-01` open; `RP-02` UNREACHED.
- **Next separately authorized turn:** `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV` (independent static Review, then TB23 plan). No automatic TB23 dispatch.
