# RA-224 — Disc corner stops (step 64B.13, obligation O38)

**Turn:** `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (Review). **Disposition: COMPLETE.** The corner product is defined (§3) and two exact patches with their gates are frozen: CB119 → TB100 adds the product, unwired; CB120 → TB101 makes the D5 stop set read it, in a factory that production does not call yet. Runtime-free: syntax checks and a Python model only; no product or test source changed in the repository.

The user decided O38 on 2026-11-10 ([RA-221 addendum](Architecture_M6_CP3_DEFN_P13_A3_Boundary_Chain_Consumption_Adversarial_Review_20261110.md#addendum-2026-11-10-user-decision-on-o38)): disc corners are chain stops, read from a published upstream product. This record defines that product. It narrows one item of the addendum (F2).

## 1. What was read

- **The producer's corners** (`SurfaceCellTracing.cpp:16684–16771`). For each boundary edge of a region the bounded-disk producer picks the field branch, out of four directed branches, with the largest dot product against the edge direction in the edge's face. It rejects the region when the best value is below 0.7 or two branches tie. It subtracts the face's rotation in a region-wide gauge, built by transport from a root face, and starts a new side wherever the result differs from the previous edge's.
- **Transport** (`resolve_branch_transition`, `:6712`): the quarter-turn comes from the transport atlas; the sign is then chosen to continue forward geometrically.
- **The stop set** (`derive_mandatory_chain_stop_nodes`): singularity-port nodes, nodes on a feature-curve corner or junction, and both ends of every hard-feature edge. The feature corner is a geometric line-angle test (RA-223 F4).
- **TB98 `d4-rim` lines.** Under today's stops the rim of Plane and MultiFaceSeam is cut into 4 sides and CloseSheets into 8. The chained count is equal on every side of a fixture (10, 10 and 11), where the per-arc sums are 12 and 9 on Plane. Cylinder has 30 sides for 32 rim arcs: other arcs reach almost every rim node.
- **TB99 `D4_UNIFORM_RECEIPT` lines.** Under a chained plan the bounded-disk producer built both plain squares: 8 cells, 2 disc phases, 8 of 8 spans covered.

**Correction to RA-222 §5.** Its prediction "Plane: `chained` equal to `output` (8 per side)" was false. The chained count is 10 and the uniform lattice has 8 (CloseSheets 11 against 10). The switch will therefore change the cell counts of these three fixtures, not only their recorded intervals.

## 2. Findings

| # | Finding | Action |
|---|---|---|
| F1 | **A corner at a pass-through rim node needs no region.** At a rim node that only its two rim arcs reach, the whole face fan of the vertex lies in one region. The gauge difference between the fan's first and last face equals the transport across the fan, because the producer rejects a region whose transport is not path-independent. So the producer's branch change there equals the field's turn across the vertex's own fan | The product is a list of **source vertices**, derived from the mesh, the field and the atlas alone (§3 C1) |
| F2 | **Addendum item 3 cannot be taken literally.** It said the producer reads its side starts from the product. A region's sides also start at trace, cut and hard-rail nodes, which the product does not cover | Narrowed (§3 C3): the producer keeps deriving its side starts; a test proves the two derivations equal at pass-through rim nodes; a span that crosses a corner stays the typed rejection CB116 already has |
| F3 | **RA-223 F4 (the 135° blind spot) is bypassed, not fixed.** Each edge lies within about 45.6° of its branch, so two consecutive edges that turn by more than about 91° cannot share a branch. Every turn the line-angle test misses is a field corner | No change to the feature map. Witness in CB119: a 153° turn is a field corner and not a feature corner |
| F4 | **The reverse also happens.** A 53° kink is a feature corner and both of its edges follow one branch | Feature corners stay stops: they keep the kink vertex in the output. A side may then hold several spans, which the consumers support since CB116 |
| F5 | **The rule can fail to decide** (a tie at 45°, a best value below 0.7, a failed transport). The producer rejects the region there | The product reports an undecided vertex as a corner, so no chain crosses a vertex the producer cannot classify |
| F6 | **O34 narrows.** A closed rim is now cut wherever the field turns. A rim the field follows all the way round, with no other stop, still stays per arc | O34 stays open for that case only |
| F7 | **The rule is floating point.** The product copies the producer's rule so that the two agree. It is deterministic under face-row order, but a near-tie could be decided differently on another platform and would then change the chains as well as the sides | Registered as **O39**: an exact corner rule, changed in the producer and the product together |
| F8 | **Coverage limits.** Only source-boundary rails are covered. Hard-feature rails will need the same rule on each side of the feature when they chain (O35). A cut arc with interior vertices can turn inside one arc, where no stop can help | Registered: O35 inherits the corner rule; interior turns of a cut arc stay with A4 (65C) |

## 3. Definition

**C1. Product: boundary field corner vertices.** For each source-boundary edge, taken in its face's orientation, let `v` be the vertex it enters. The branch of that edge is carried across the faces around `v`, one transport per interior edge, to the boundary edge that leaves `v`, and compared with that edge's branch. `v` is a corner when the two differ, when either branch is undecided, or when the fan cannot be crossed. The per-edge branch and the transport are the producer's own rules. The result is a sorted list of source vertices. It does not depend on regions, on the network or on face-row order.

**C2. Stop set.** `derive_mandatory_chain_stop_nodes` takes the product as a fourth source: a node on a corner vertex is a stop. The chained factory passes it through. Both parameters default to empty, so existing callers are unchanged; the switch passes the product.

**C3. Producer.** Unchanged in these patches. Its side starts at pass-through rim nodes must equal the product (CB119 asserts it on both producer paths). A corner inside a span without a breakpoint on it remains `InvalidBoundedDiskBoundaryPhase` (CB116); under C1 and C2 that outcome marks a defect. Making the producer call the shared per-edge rule is a production-path change and is left to the switch definition, gated on its own.

**C4. Pipeline (at the switch, not frozen here).** The pipeline computes the product once, after the atlas, records it as a context product, and passes it to the chained factory.

## 4. CB119, frozen — the product, unwired

- [Patch](Architecture_M6_CP3_CB119_P13_A3_Boundary_Field_Corners_Exact.diff): SHA-256 `06d6cadd1640b30107db7d4e4a5299849a8a041f5ed33cef1bdb9e6bcbb90b0f`, 307 lines, 4 single-space context lines. Numstat `15 0` `include/directional/geometry/SurfaceCellTracing.h`; `117 0` `src/geometry/SurfaceCellTracing.cpp`; `142 0` `tests/SurfaceCellsPhase10Tests.cpp`. It only adds lines and applies at HEAD.
- **Adds** `derive_boundary_field_corner_vertices(vertices, faces, faceAxisX, faceAxisY, atlas)`. Nothing calls it outside the tests.
- **Test 937** `BoundaryFieldCornersFollowTheFieldNotTheGeometry`, on a four-vertex triangle with no pipeline: the two 153° base ends are corners and the 53° apex is not; reversing the face rows gives the same answer; a field at 45° to the base reports all four vertices.
- **Test 938** `BoundaryFieldCornersMatchTheCurvedProducersSideStarts`, on the two-square fixture with and without its hard rail, in both face-row orders: the product is exactly the eight square corners, and at pass-through rim nodes it equals the side starts the producer published. With the hard rail the producer runs its accepted-cut path under the pipeline's plan; without it, its plain path under a chained plan.
- **Non-vacuity.** The equality is between two derivations that share no code: the producer's region gauge and the product's fan transport. Each case requires some pass-through rim nodes that are corners and some that are not.
- **Checks:** `-fsyntax-only` returns 0 on both files. A Python model of the rule returns the asserted sets for the triangle and for the fixture.

## 5. TB100, frozen

- [Manifest](gates/Architecture_M6_TB100_P13_A3_Boundary_Field_Corners_Full_Gate_Case_Manifest.tsv): 938 rows, SHA-256 `2df4bd96ee8a52323ffa4f07292e37a3b6e4aedd6424fb9dc68e805da2cbc24c`. TB99's 936 rows byte for byte, plus GUARD 937–938. `SELF_CHECK_PASS cases=938 deferred=81`; membership 1019.

| Outcome | Route |
|---|---|
| 938/938 PASS; the 7 platform-digest and 7 a3-coverage lines byte-identical to TB97; the 4 `d4-rim` lines identical to TB98; census unchanged; both `FIELD_CORNER_RECEIPT` lines recorded verbatim | MATCH → `M6-CP3-CB120-P13-A3-FIELD-CORNER-STOPS` |
| Row 937 or 938 fails, any regression in 1–936, or any digest change | MISMATCH → `M6-CP3-TB100-P13-A3-BOUNDARY-FIELD-CORNERS-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB100A-P13-A3-BOUNDARY-FIELD-CORNERS-ORCH` |

**Registered predictions (not pass conditions).** `case=rail corners=8 passThroughRimNodes=12 sideStarts=12 rimSideStarts=8`; `case=plain corners=8 passThroughRimNodes=16 sideStarts=8 rimSideStarts=8`.

**Registered risk.** Row 938 requires the producer to build the plain squares under a chained plan with reversed face rows. TB99 printed that outcome for forward rows only. A failure of that one assertion is a row-order defect of the producer, not of the product; the Review decides.

## 6. CB120, frozen — the stop set reads the product

- [Patch](Architecture_M6_CP3_CB120_P13_A3_Field_Corner_Stops_Exact.diff): SHA-256 `71a21f6dbdc55eaad1f8d6d25978d4f8508444536b3343a346e7f7da3b00c189`, 248 lines, 8 single-space context lines. Numstat `6 3` `include/directional/geometry/GlobalConformityBaseline.h`; `3 2` `src/geometry/GlobalConformityBaseline.cpp`; `9 5` `src/geometry/GlobalConformityBaselineSupport.cpp`; `5 3` `src/geometry/GlobalConformityBaselineSupport.h`; `27 0` `tests/GlobalConformityBaselineTests.cpp`; `34 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`; `50 0` `tests/SurfaceCellsPhase10Tests.cpp`. It applies on top of CB119.
- **Neutral for production:** the pipeline does not call the chained factory, and both new parameters default to empty.
- **Test 939** `StopNodesReadBoundaryFieldCorners`: a corner vertex stops the chain at its node; a vertex with no node adds nothing; order does not matter.
- **Test 940** `ChainedInputStopsAtBoundaryFieldCorners`, on the hard-rail fixture: the derived corners leave the four chains unchanged (they are already feature corners); a corner declared on a mid-side vertex leaves three chains and one more span, and that input builds and validates.
- **Census.** The existing rim census test prints a second line per fixture: `d4-corner case=<name> inputs=own fieldCorners=… chains=<without>/<with> spans=<without>/<with>`. It builds and validates the schedule with the corner stops, which is the first run of that schedule on benchmark meshes. The `d4-rim` line is computed as before.
- **Checks:** `-fsyntax-only` returns 0 on the three source files, the validator and the three test files.

## 7. TB101, frozen

- [Manifest](gates/Architecture_M6_TB101_P13_A3_Field_Corner_Stops_Full_Gate_Case_Manifest.tsv): 940 rows, SHA-256 `8caccb929155a960bee8c8fe5b0c0ca67a24dabdb8d1ad50c76e426eb96a23db`. TB100's 938 rows byte for byte, plus GUARD 939–940. `SELF_CHECK_PASS cases=940 deferred=81`; membership 1021.

| Outcome | Route |
|---|---|
| 940/940 PASS; the 7 + 7 lines byte-identical to TB97; the 4 `d4-rim` lines identical to TB98; census unchanged; the `FIELD_CORNER_STOP_RECEIPT` line and the 4 `d4-corner` lines recorded verbatim | MATCH → `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION` (64D, **Review agent only**) |
| Row 939 or 940 fails, a census row 932–935 fails, any regression, or any digest change | MISMATCH → `M6-CP3-TB101-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB101A-P13-A3-FIELD-CORNER-STOPS-ORCH` |

**Registered predictions (not pass conditions).** `FIELD_CORNER_STOP_RECEIPT fieldCorners=8 chains=4/4 splitChains=3 splitSpans=17`. Plane and MultiFaceSeam: `fieldCorners=4` with `chains` unchanged at 4. CloseSheets: `fieldCorners=8`, `chains` unchanged at 8. Cylinder: `fieldCorners=0`, `chains=2/2`. A fixture whose `chains` or `spans` differ across the slash is one where the field sees a corner the geometry does not; that is evidence for the switch, not a failure.

## 8. Sequence and obligations

| Step | Turn | Owner |
|---|---|---|
| 64B.13 | `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS`: COMPLETE (this record) | Review |
| 64B.14 | `M6-CP3-CB119-P13-A3-BOUNDARY-FIELD-CORNERS`: exact patch §4, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-BOUNDARY-FIELD-CORNERS-STOP`; infrastructure → `M6-CP3-CB119A-P13-A3-BOUNDARY-FIELD-CORNERS-ORCH` | implementation agent |
| 64B.15 | `M6-CP3-TB100-P13-A3-BOUNDARY-FIELD-CORNERS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64B.16 | `M6-CP3-CB120-P13-A3-FIELD-CORNER-STOPS`: exact patch §6, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-FIELD-CORNER-STOPS-STOP`; infrastructure → `M6-CP3-CB120A-P13-A3-FIELD-CORNER-STOPS-ORCH` | implementation agent |
| 64B.17 | `M6-CP3-TB101-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-EXEC` (§7) | implementation agent |
| 64D | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION`; independent of 64B.14–64B.17 and may run alongside them | **Review agent only** |
| later | D5 switch, then D4 uniform switch (O36): one definition, two CBs | Review, then implementation |

**O36 preconditions after this record.**

| Condition | State |
|---|---|
| Mixed stage produces, or hard-feature rails chain (O35) | Met on the rectangular fixture (TB97) |
| Disc corners are stops (O38) | Defined here; product CB119, stop set CB120; pipeline wiring (C4) with the switch |
| The 135° blind spot (RA-223 F4) | Bypassed by the field rule (F3) |
| Closed rims are cut (O34) | Cut wherever the field turns; a rim with no field corner and no other stop stays per arc |
| Breakpoints located in one pass (O37) | Open |
| The bounded-disk producer builds plain regions | Met on the two-square fixture (TB99); the gate fixtures at the switch TB |
| The producer calls the shared per-edge rule (C3) | Open; with the switch |
| Exact corner rule (O39) | Registered; not a precondition unless a platform split appears |
| Switch TB pre-registers digest changes and amends the named tests | Open; TB98 shows sides going from 8 to 10 (Plane, MultiFaceSeam) and from 10 to 11 (CloseSheets) |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB100's rows 1–936 are TB99's manifest byte for byte, and TB101's rows 1–938 are TB100's. Selector497/CP3 is unpromoted |
| Decisive claims re-derived | §1: the producer's branch rule, gauge and side starts; the transport function; the stop set and the chained factory; the TB98 and TB99 lines. F1 is an argument from the producer's own reciprocal-transport check, and test 938 measures it |
| Non-vacuity | §4 and §6 |
| Obligations carried | 64B.14–64B.17; 64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); O35 (inherits the corner rule); O36; O37; O38 (defined); **O39 (new)**; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB99 936/936, membership 1017; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |
