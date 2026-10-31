# CB35 R1 test-only correction plan — complete published-route oracle (2026-10-24)

**Authorized next:** `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION` (Code + Build). **Owner:** CB35-REV [finding R-1](Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Independent_Review_20261024.md). No TB36 execution or product fixes this turn.

1. Change only `tests/SurfaceCellsPhase10Tests.cpp`, inside `PublishedRouteStepsCarryAtlasTransport` (source semantic base `6c94c053e5d20331e06a93d26437aa864171031f`; rebase only after inspecting changed-path authority).
2. Before the ±1/inverse/identity checks, require exact ordered `route_topology(route)` equal `periodic_route_topology(fixture)`; this catches missing, wrong or repeated route-edge identities. Existing 32-step check remains.
3. Check each expected pure-rotation step has zero `LatticeTranslation`, and compare composed `GridAutomorphism total` to `GridAutomorphism::identity()` (not only `total.rotation`). Preserve the existing two distinguished rotations and all remaining identity rotations.
4. Compile the mandatory eight GMP/GMPXX targets in Actions with `runtimeExecution=false`; no test or benchmark execution, no test-selection, selector497, original 189–192, production or workflow changes.
5. Independent follow-up Review must verify that perturbing an unmarked edge topology or a translation would fail the oracle, inspect exact test-only diff, rehash artifact/selector, and only then issue the frozen five-case TB36 pre-fix manifest (new three + frozen 191/192) under RA-152 stops.

**Stop:** If the route publication contract legitimately includes a nonzero translation or an alternative canonical ordered route, stop for independent definition rather than rewriting the expected oracle to match observations. Do not weaken the assertions.
