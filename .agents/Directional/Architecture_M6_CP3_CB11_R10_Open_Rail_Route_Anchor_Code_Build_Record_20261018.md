# CB11 — shared open-rail route anchor, Code + Build

**Turn:** `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` (RA-84.5 U1). **Disposition:** implementation compiled and packaged; runtime tests intentionally not executed. Next separately authorized turn: `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR`.

## Semantic scope and source

- Exact implementation and compile source: `9432aa05ef4719cbea912ae0feb2c5508c4e497a` (ancestor of snapshot `de46224f1ea1647e0e89444616b7a3fc7b2d4c61`). Compared with the prior TB10 semantic source `d938ecb57e1040c2a73d5d25c4a613414556cb18`, the implementation change is limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, and `tests/SurfaceCellsPhase10Tests.cpp`; the intervening history also includes unrelated authorized documentation/control-plane cleanup, not part of CB11 semantics.
- The pre-existing factory open-rail route-anchor clauses were extracted verbatim into the pure `surface_cell_tracing_detail::open_rail_route_anchor_valid` helper. Both `SurfacePhaseFrontProduct::make` and the route-building consumer call the same helper; the consumer rejects immediately before appending a route certificate with `TerminalCarrier`, `-1`, `-1`, `open-rail-route-anchor`.
- Existing closed-rail validation, R admission, open-chain projection, I/C semantics, exact arithmetic, frozen selector and acceptance policy are untouched. No new `Produced` admission was authorized.
- Source snapshot workflow [39087852853](https://github.com/akashskypatel/Directional/actions/runs/39087852853), artifact `12121577119`, ZIP SHA-256 `74e14c752f110917f53fa682af836bbca2414b7b3100d3f07e0cd8cdf3025a06`; snapshot source `de46224f1ea1647e0e89444616b7a3fc7b2d4c61`; `5648/5648` source hashes verified. The three semantic files match the compiled-source tarball byte-for-byte.

## Compiled tests and evidence

- `OpenRailRouteAnchorTruthTable`: independent literal expectations for opposite-order T–T accept, same-terminal T–T reject, non-touching carriers reject, T–I/I–T accept, non-contact T reject, T off carrier reject and I–I reject.
- `CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor`: on a previously `Produced` T–I fixture, clearing the sole terminal in the candidate certificate is expected to produce `InvalidSourceAuthority`.
- The existing `ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` control remains unchanged and asserts the baseline fixture is `Produced`, with its previous forged-terminal rejection. Consumer I–I is **helper-covered, not end-to-end observed**.
- Compile workflow [39085601323](https://github.com/akashskypatel/Directional/actions/runs/39085601323), package artifact `12121016836`, outer ZIP SHA-256 `e92158729bf4cfc13432678e8a05cffba4d922feca6e902d8154a535ab1f2676`.
- Exact compile source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`; eight required targets; `28/28` manifest checks, five empty source-status receipts, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, generated link includes both GMPXX/GMP, `exactArithmeticBackend=GMP`, and `runtimeExecution=false`.
- **No tests, runtime binaries, benchmarks or new semantic acceptance were executed.** Passing compilation does not establish truth-table or end-to-end runtime results.

## Frozen authority and handoff

The last accepted runtime remains M6 CP2 **491/491** (package `11391685901`); candidate R3 remains **403/497** rejected; stable ledger **66/17/49**, debt **1**, selector **497** frozen. `RP-01` unresolved; `RP-02` UNREACHED and Gate C suspended. TB11 must consume this exact immutable compile package without building or changing source/tests and must run the authorized CB11 regression tests plus retained controls. A red TB routes to independent Review, not another CB patch. U2–U4 remain held pending the reviewed green predecessor.
