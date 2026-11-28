# M6-CP3-DEFN-P13-A4-DISC-CORNERS — corners and corner-delimited sides of trace-bounded discs (2026-11-28 UTC)

## Situation

Defines A4's corner rule for A2b discs bounded by traces and freezes CB-220, a compile-only product slice that publishes each region's corners and corner-delimited sides next to the region boundary schedule. No production caller (as CB-214's schedule). Runtime-free. Scope per [TB-REV-194 adv.](Architecture_M6_CP3_TB_REV_194_Adversarial_Review_20261128.md) FF2–FF4: no D7 re-derivation precondition; slivers 2/4 are ordinary discs (quality item, DESIGN §4.11, Amendment 30).

## CR1 — Corner rule (exact, combinatorial)

At each walk node between the incoming oriented arc `a` and the outgoing arc `b`, the interior gap in field quarter turns is:

1. **2 (flat)** when `a` and `b` are consecutive pieces of one trace;
2. **1** at a T-node (not a port node, exactly three incident arc ends) where `a` and `b` belong to different traces — a terminating trace crosses the struck trace transversally, and DESIGN §7.2 rules out a crossing between parallel same-branch segments, so they differ by one quarter turn;
3. at a singular node, the number of port sectors swept on the region's side between the ports `a` and `b` occupy (departure → trace `port`, arrival → `arrivalPort`; after Amendment 35 every arrival owns a port): gap = (incoming ordinal − outgoing ordinal) mod port count, 0 read as a full turn. Plan face walks turn to the clockwise neighbour of the reversed incoming arc (`EmbeddedGraphTopology.cpp:3370–3389`), port slots are counter-clockwise (`FieldTransportAtlas.cpp:965–1057`); that the two conventions agree is unproved and is falsified by the guard if wrong (every sphere singular corner would read 2);
4. anything else (Mandatory/Cut arcs, contact nodes of other degree, missing port) is a typed failure.

Corners are nodes with gap ≠ 2; a corner-delimited side is the maximal run of schedule sides between consecutive corners, its count the sum of their counts. Every `interiorSingularityFree` region must satisfy Σ(2 − gap) = 4 (discrete Gauss–Bonnet in the field's flat metric, A4D5), else a typed failure — a self-check that catches a wrong classification or orientation. Counts are consumed as the validated A3 product (FF2).

## CR2 — CB-220

- API (declared in `GlobalConformityBaseline.h` next to the schedule types; defined in new `src/geometry/RegionCornerSides.cpp`, added to the core library): `build_region_corner_sides(topology, network, schedules)` → per-region `RegionBoundaryCorner {node, scheduleSide, quarterTurns}` and `RegionCornerSide {firstScheduleSide, scheduleSideCount, count}`, or a typed failure: `topology-plan-mismatch`, `network-mismatch` (binding digest), `unsupported-arc-kind`, `unsupported-contact-node`, `port-not-found`, `turning-not-four-quarter-turns`. Corners listed in walk order from the lowest schedule side.
- Placement: `cmake/DirectionalTests.cmake:202–218` forbids `GlobalTopologyArcKind` in the A3 baseline source, and corners are A4's, so the logic lives in its own file. Declaring an A4 product in the A3 header is a minor coupling (noted, not blocking).
- Approximations recorded: "consecutive pieces" uses arc segment ranges (plan arcs keep no cut parameters).
- Tests (in `tests/SurfaceCellTracingDisplayTests.cpp`, whose sphere fixture uses the row858 length ratio 0.02 that yields the FF4 counts):
  - `RegionCornerSides.PrescribedSphereRegionsTurnAtFourQuarterTurnCorners` asserts the FF4 table exactly (8 regions × 4 corners of gap 1; sides r0 30,35,35,32; r1 31,35,35,31 with nodes 8, 9 flat; r2 1,32,1,32; r3 30,32,35,35; r4 1,32,1,32; r5 32,30,35,35; r6 32,35,35,30; r7 35,31,31,35 with nodes 10, 11 flat; sides cover each schedule exactly).
  - `RegionCornerSides.ReversedPrescribedSphereWalkIsRejectedByItsTurning` reverses region 0's walk (sum 1) and requires `TurningNotFourQuarterTurns`.
- Row858 receipts: `<Label>RegionCornerSides unavailable | built=0 failure=<name> | built=1 regions= corners= sides=`, per sphere region `SphereRegionCornerSide region= corners=n,g;… sides=c,…`; genus summary only.
- Verification (syntax only, not compile evidence): independent apply/reverse and hashes; 0 errors; identical location-stripped warning multisets for GlobalConformityBaseline.cpp (20) and the display tests (24); new file 0 errors, no warning inside it; no plan identifiers in code.

## CR3 — Trajectory

Corners make the sides explicit; FF4 predicts that six of eight sphere regions have unequal opposite sides, so the next definition is A4 unequal-side construction (DD5), which decides whether the sphere meshes. genus_two is expected to report `unsupported-arc-kind` if its regions include non-trace arcs (measured, not a failure of this slice).

## CR4 — Turn sequence

1. `M6-CP3-CB-220-P13-REGION-CORNER-SIDES` (compile only) → 2. `M6-CP3-TB-EXEC-195` → 3. `M6-CP3-TB-REV-195` → 4. `M6-CP3-DEFN-P13-A4-UNEQUAL-SIDE-CONSTRUCTION` (DD5) → CB/TB → Vase row → fill → 65B → 65D (O50, Amendment-19) → O41/switch.
