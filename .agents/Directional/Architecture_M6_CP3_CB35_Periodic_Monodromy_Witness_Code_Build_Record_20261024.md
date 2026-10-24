# CB35 periodic monodromy witness — code and build record (2026-10-24)

- Turn: `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS` (test-only Code + Build).
- Authority: RA-152 D3 and the CB35 periodic-monodromy witness plan.
- Implementation commit: `6c94c053e5d20331e06a93d26437aa864171031f`; only `tests/SurfaceCellsPhase10Tests.cpp` changed (+161/-0).
- Introduced mesh-derived cylinder-axis cross rotation helper `turning_periodic_route_field` and three independent witnesses: k=1, k=2 nonzero monodromy negatives plus atlas-route-step transport publication.
- Test and source fields are identical in both negative witnesses; existing frozen tests, production, selector and workflows were not edited.
- Test-only source patch was applied through verified Google Drive dispatcher run 40130147854; exact Git blob verified and Drive staging retired.
- Compiled source: `6c94c053e5d20331e06a93d26437aa864171031f` (not later STATUS/request branch commits).
- Compile: [run 40131078824](https://github.com/akashskypatel/Directional/actions/runs/40131078824), artifact `12575180700`, ZIP SHA-256 `f94a7a3644d976cac44bf519afa383b4d94a99ca0663aa2608d68b681e8003bd`.
- Packaged manifest: 28/28 verified; eight targets built, GMP/GMPXX link verified, `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, clean source/package statuses and `runtimeExecution=false`.
- No tests, benchmarks or binaries executed in this turn; no runtime acceptance or RP-01 promotion is claimed. Three witness tests are predicted RED pre-fix and must be adjudicated by separate TB36.
- Accounting unchanged: stable 66/17/49, debt 1; CP2 accepted 491/491; TB32 candidate 481/500 with 19 RED; TB35 focused 11 PASS/2 RED; selector497 frozen; RP-01 open, RP-02 unreached.
- Next: `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS-REV` (independent static review; author TB36 manifest only upon acceptance).
