# CB16 exact I endpoint witness checkers — Code + Build

- Turn: `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` (RA-97.4); compile-only.
- Semantic source: `1c45e89ae0ca7a072c5140aea2b95be6387ec078`.
- Changed only `SurfaceCellTracing.cpp`, `.h` and three compiled Phase10 tests.
- Rule: unbound present witness rejects; two bound witnesses compare exactly; mixed/absent witness retains unchanged legacy rule.
- Probe: `exact-witness-unbound`, `exact-witness-mismatch` only within existing failed-interior branch.
- Unchanged: previous producer, `interior_carrier_parameter`, dedup, factory/consumer call sites and all other guards.
- Compile: [run 39176761903](https://github.com/akashskypatel/Directional/actions/runs/39176761903); package artifact `12154623660`; ZIP SHA-256 `821edfc6653af356c902d2debedc065a0ee6b51d287c27bdfd0679ef3a619956`.
- All eight GMP/GMPXX targets compiled; `DIRECTIONAL_ENABLE_GMP=ON`; `exactArithmeticBackend=GMP`.
- `runtimeExecution=false`; no Directional tests or benchmarks executed in this turn.
- Runtime acceptance and 12-case falsifiers are deferred to `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` (RA-97.5).
- Frozen: selector497, 66/17/49, debt 1, `RP-01` open, `RP-02` unreached.
