# CB13 — open-rail chain interval, Code + Build

**Turn:** `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (RA-87.4 U3). **Source:** `70217cc2bf7d257bebd2969e1aa56b5a43326a70`. No runtime, tests or benchmarks were executed (`runtimeExecution=false`). The next authorized turn is `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE`.

## Semantic change

- Replaced terminal-anchor predicate with pure `open_rail_route_interval_valid`: nonempty contiguous interval of the ordered open chain, either direction, without cyclic wrapping, with present terminal endpoints restricted to the appropriate chain end. Deleted old helper.
- The factory and consumer call the same helper with the real chain; missing/invalid chains fail closed (`InvalidSourceAuthority` / `open-rail-chain-interval`). Empty chain-map exemption was removed for nonempty terminal contacts. Corrected I-branch explanation.
- Compiled the new interval truth table and flipped the CB12 empty-chain expectation; assertions were not weakened. No R or I endpoint admission, selectors, harnesses, or reusable workflow semantics changed.

## Direct `SurfacePhaseFrontProduct::make` call-site census

- `src/geometry/SurfaceCellTracing.cpp:12926`: production call forwards tracing options' real open chains.
- `tests/SurfaceCellsPhase10Tests.cpp:2542,6394,7220,7259,7444,7469,9011`: reconstruction/tamper calls forward `product/front.hardRailOpenChains()`; `build_fixed_plan_rectangular_hard_rail_network` produces the chain from the same rails as contacts.
- `tests/SurfaceCellTransitionQuotientTests.cpp:1851,1997,2680,2790,3112,8878,8980,9127`: the `PhaseFrontDraft` transports the real chain, the contact-negative test supplies explicit chain, and rebuilds/tampers forward the source product accessor.
- `tests/SurfaceCellTransitionQuotientTests.cpp:350` and `tests/FlowRepStrandsPhase15Tests.cpp:103`: minimal no-contact constructions intentionally have no open chains.

## Compile evidence

- First dispatch [39108089847](https://github.com/akashskypatel/Directional/actions/runs/39108089847) failed in request parsing (`unknown request fields: retention_days`); no C++ compilation occurred. Corrected request `a451e792ee525a9abdc814b3694f34940ee355b4` removes the unsupported field. The second compile (39108842048) reached the compiler and failed at the test lambda generic argument `{}`; the assertion-preserving one-line fix is semantic source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`.
- Verified corrected compile [run 39109464680](https://github.com/akashskypatel/Directional/actions/runs/39109464680), job `117622316011`, immutable package artifact `12130290543`, outer ZIP SHA-256 `7aea91a1b689f26ae9a4786c48152fe0a3d9c8e17382b6e155db0465e3445fd3`; exact source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`. Eight compile targets; `DIRECTIONAL_ENABLE_GMP=ON`, `gmpxx` and `gmp` verified from link evidence, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, source clean; package internal hashes verified.
- Static patch preservation: base `e0d386aeae573ce08a25adfe586f5aa0452a4aa7` snapshot run `39107318204` (5655/5655 hashes), patch SHA-256 `917d359eabfe5c8f13a7042c1bebddf84532d63ffcb6f3895bb0f08d03c1d170`; source push `b2032288ee5af464eec2bb9ccc88870098ebf5ad`.

## Remaining authority

- CB13 is compile-only, not independent semantic acceptance. TB13 must run the six RA-87.5 identities on this unchanged package and report their actual outcomes; TB13C census is conditional after it. Frozen CP2 `491/491`, R3 `403/497`, selector `497`, stable `66/17/49`, debt `1`; `RP-01` unresolved, `RP-02` UNREACHED, Gate C suspended.
