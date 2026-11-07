# CB35 plan — authoritative periodic monodromy witnesses (test-only, compile-only) (2026-10-24)

**Turn:** `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS`. **Authority:** [RA-152](Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md) D3. **Purpose:** add discriminating witnesses for F1 **before** any production change. They are expected RED on the current producer.

## Edit — `tests/SurfaceCellsPhase10Tests.cpp` only, after `make_legacy_periodic_route_field`

1. Helper `turning_periodic_route_field(const PeriodicHolonomyRouteFixture&, int quarterTurns)`:
   - cylinder axis: the mesh's principal axis through the vertex centroid, computed from the mesh, never hard-coded;
   - per face: φ = azimuth of the centroid about the axis in [0, 2π); `α = quarterTurns·(π/2)·φ/(2π)`; rotate each of the four raw 3-vectors in `fixture.rawField.row(f)` by α about the unit face normal (`v' = cosα·v + sinα·(n×v)`);
   - return `directional::pipeline::finalize_surface_cell_raw_cross_field(fixture.mesh, rotatedRaw)`.
2. A shared lambda or helper for the witness body, for each k ∈ {1, 2}:
   - **Preconditions** (`ASSERT`): the field has no singularities (`singularIndices.size() == 0`); `periodic_route_rotation(fixture, field)` equals `from_integer(k)` or `from_integer(-k)` and is not identity; `FieldTransportAtlas::make` succeeds, printing `describe_field_atlas_build_error` on failure.
   - **Subject:** `build_periodic_route_network_with_source_atlas(fixture, field, field)`. The same field serves as tracing and source, so there is no split input.
   - **Expect:** exactly 192's assertion set — `Rejected`, `PeriodicHolonomyMismatch`, `is_rejected`, `!is_produced`, null product, and failure `cell/side/face/targetFace/sourceVertex/sourceEdge/secondarySourceEdge == -1`.
3. Tests, suite `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration`:
   - `AuthoritativeQuarterTurnMonodromyRejectsAtPeriodicGuard` (k=1);
   - `AuthoritativeHalfTurnMonodromyRejectsAtPeriodicGuard` (k=2);
   - `PublishedRouteStepsCarryAtlasTransport`: the balanced (gauged) field as tracing and source; `ASSERT Produced`; in `holonomy.route().oriented_steps()`, the step at `expectedRoute[0].currentTopology` has rotation r ∈ {1, 3}, the step at `expectedRoute[1].currentTopology` has `r.inverse()`, all other steps are identity, and the composition is identity.

## Out of scope

Production code; the bodies of the seven frozen tests and existing helpers; selectors; workflows; runtime execution.

## Evidence and stops

- **Gate:** 8 GMP/GMPXX targets compile, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Record_20261024.md` (≤30 lines).
- **STOP → Review:**
  - the rotation needs an API that is not public;
  - `finalize_surface_cell_raw_cross_field` is unavailable to the test target;
  - satisfying the plan would require touching production code or a frozen test.
- **Predictions for TB36 (pre-fix):** all three new tests RED. The two monodromy witnesses fail with `Produced`, or with a non-`PeriodicHolonomyMismatch` rejection (gauge-pin backstop). `PublishedRouteStepsCarryAtlasTransport` fails because every step is identity.
