# CB34 test-only gauge repair: code and build record (2026-10-24)

- Canonical turn: `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR`.
- Authority: RA-150 §3 and amended CB34 plan. No production/selector/frozen-test modification.
- Test-only implementation: `tests/SurfaceCellsPhase10Tests.cpp` at `d3bbc8e9cc41086be10447e4672e0f1ed7245456`, with gauge face found from route topology, three zero-matching preconditions, additive +1/−1/−1, compact matching synchronization, unchanged effort, and face direction/raw-field relabel.
- New independent oracle `BalancedRouteFieldIsPureFaceGauge` verifies source A3 construction, original-vs-gauged semantic digest/frames/transports, three raw signed transition values, and rejection of the invalid two-edge-only construction.
- Compile correction: `DomainResult<SourceFaceId>` uses `.value()` rather than dereference in oracle; tested against the declared API. Exact committed source: `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`.
- Initial compile `40108044838` failed at the new oracle's two `operator*` operands; failure is retained as independent evidence, not reported as green.
- Verified corrected compile: [run 40111610291](https://github.com/akashskypatel/Directional/actions/runs/40111610291), package `12566907246`, outer ZIP SHA-256 `ca5c490bae2d65f9c043636c285d29edcfe5695b9334c24edcc281fac26c6a17`; `28/28` manifest entries verified, eight required targets, GMP/GMPXX linked, `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, clean source, `runtimeExecution=false`.
- Source correction patch: SHA-256 `1a5e2ab5872edca5dc03d17dd1dd0d32439a46ac1886d6f710d50c6ca1405222`, applied in [workflow 40111484173](https://github.com/akashskypatel/Directional/actions/runs/40111484173); staging retired.
- No tests/benchmarks/runtime executed in CB34. Seven inherited REDs and product acceptance remain for independent TB35; compile-only evidence does not promote acceptance.
- Stable 66/17/49, debt 1; CP2 accepted 491/491, TB32 candidate 481/500 with 19 inherited RED; selector497 frozen; RP-01 open, RP-02 unreached.
- Exact successor: `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR-REV` (independent static review; authorizes TB35 manifest separately).
