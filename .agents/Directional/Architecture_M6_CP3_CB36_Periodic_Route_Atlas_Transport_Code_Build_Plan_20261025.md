# CB36 plan — periodic observed steps read A3 transport (production, compile-only) (2026-10-25)

**Turn:** `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT`. **Authority:** [RA-152](Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md) D2, as specified by [RA-153.3](Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md) and authorized by [TB36-REV](Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Independent_Review_Decision_20261025.md).

## Edit — `src/geometry/SurfaceCellTracing.cpp:14937–14982` only

1. Replace `int matching = 0;` with a step rotation `authority::QuarterTurn stepRotation{}`, computed as follows:
   - **`transitionLookup.atlas != nullptr` (new, first):** typed source and target faces are `faceCycle[index]` and `faceCycle[(index + 1U) % faceCycle.size()]`; `const auto directed = transitionLookup.atlas->transport(*sharedKey, source, target);`.
     - If `!directed`: `Rejected`, `PeriodicHolonomyMismatch`, locus `(-1, -1, sourceFace, targetFace, -1, sourceEdge)`, return.
     - Otherwise `stepRotation = directed->transport`.
   - **`else if (hasTransitions)`** and **`else if (edgeMatching …)`:** unchanged, ending with `stepRotation = authority::QuarterTurn::from_integer(matching)`.
2. In `TransitionStep::interior(...)`, use `GridAutomorphism{stepRotation, LatticeTranslation{0, 0}}`.

The edit is about 15 lines and adds no new helper.

## Out of scope

- The guard (`:15000`), the action, the cut route and the strip BFS.
- The `build_surface_cell_network` overload; `SurfacePhaseFrontProduct::make`.
- Every test, including the witnesses and the frozen 189–195; selectors; workflows; runtime.

## Evidence and stops

- **Gate:** 8 GMP/GMPXX targets compile, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md` (≤30 lines), including the exact diff hunk.
- **STOP → Review:**
  - the typed faces are not available at the edit site without new plumbing;
  - `transport()` is not callable on `transitionLookup.atlas`;
  - any change outside the edit site is needed.
- **Static falsifiers for CB36-REV:**
  - the atlas branch is not first, or the legacy branches are altered;
  - a missing transport is accepted, or is rejected without the locus;
  - the accessor is not `transport()`;
  - any other line changes.
- **Runtime predictions (TB37):** see RA-153.4.
