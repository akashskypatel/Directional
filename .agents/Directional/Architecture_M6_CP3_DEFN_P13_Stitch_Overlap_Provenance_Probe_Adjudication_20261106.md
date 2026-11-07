# RA-210 — P13-l2 block resolved: the Vase residue is three contact predicates; exact CB97 → CB98 → CB99 → TB84 (2026-11-06)

**Turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2). This resolves the ChatGPT Review's REVIEW_BLOCKER on the Claude scratch track.

**Source:**
- semantic CB96 `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, unchanged through `89cc1d18e`;
- scratch build `bld55n` (macOS, FMA-off, static), synced to the tree named in each section.

**Owning WIP:** [P13-l2 Review WIP](Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Stitch_Overlap_Review_WIP_20261106.md) and its supplements. Their exact issue tuples, patch owners and side schedules are accepted as recorded.

## RA-210.1 The block

- **Rule:** a Review scratch probe is a Review duty on the Claude track (RA-166.6 F6, RA-188.1, RA-203.1). It is not a new runtime boundary that needs separate authorization.
- **The probe:** the existing `retainIntermediateGeometry` snapshots, read by an env-gated dump in the scratch census test. That dump is in no patch.
- **Observational parity:** the retained run's `platform-digest` line is **byte-identical** to the non-retained run's, every stage hash included.
- **Node ids:**
  - `simplifiedComplex`, completion's input, has 57,636 nodes with `node.id == index` (0 mismatches);
  - the ids 9679 and 36055 index it directly;
  - the compaction concern in the WIP does not arise.

## RA-210.2 Provenance of the patch 23301 and 4955 clusters (measured)

| Node | Role | Incident arcs (all `hard=0 rail=0 sing=0`, layout support; FlowRep `mandatory=0`) |
|---|---|---|
| 9679 | **degree-2** crossing of source edge 773–775 (`sedgeT=0.3736864579`) | strand 966 only, FlowRep 21618/21619 |
| 36055 | crossing of strands 966 (family 0) and 459 (family 1), 2.5e-6 bary inside face 1199 | 21574 (966), 7746 (459) |
| 9687 | **degree-2** crossing of the same edge by strand 459 (`sedgeT=0.3736738849`) | strand 459 only |
| 35319 (patch 4955) | **degree-2** crossing of source edge 426 by strand 1331 | strand 1331 only |
| 57362 (patch 4955) | crossing of strands 1331 and 464, 2.3e-5 bary off that edge | 30463, 7902 |

- **Cell 23301:** cycle `9677 9678 9680 9679 36055 9687`. It has four real corners. Its two longer sides are split only by the degree-2 nodes 9679 and 9687, which is why its sides read `[1,1,2,2]`.
- **The microedge 9679–36055 (9.0e-8):** a trace crossing that lands 9e-8 past the point where one of its two traces crossed a source edge.
- **Not the cause:**
  - neither trace is redundant;
  - no identity is wrong;
  - nothing calls for a weld.
- **What it does:** it makes completion's boundary-only split produce quads whose corner sits on their own diagonal. Patch 4955 is the same pattern at 2.6e-6.

## RA-210.3 Owners of the four strict issues (measured; corrects RA-208/209)

All-pairs census of the strict validator's global contact test on the CB96 Vase mesh:

| Validator variant | Contacts | Strict issues |
|---|---|---|
| legacy | **342** triangle pairs (only the first is reported) | 4 |
| determinants measured in length units | 49 (all concave fan spill, e.g. 4304/4308) | 52 |
| plus a fan from the reflex corner of concave quads | **0** | 3 |

1. **Validator, length units (CB97).**
   - `collinear_segment_overlap2`, `proper_segment_intersection2` and `point_in_triangle2_strict` compared `orient2`, which is twice an area, with a length tolerance.
   - Faces 55/15372 are 5.7e-5 apart with a determinant of 1.6e-8, so they were reported as overlapping.
   - **RA-208/209's "1 global overlap" was a validator false positive.** The ChatGPT Review was right; I own the error.
2. **Validator, concave quads (CB98).** `triangulate_faces` fanned every quad from corner 0. For a concave quad whose reflex corner is 1 or 3, that fan covers the notch.
3. **Completion, pinched quads (CB99).**
   - Quads 21286 (patch 4955) and 41746 (patch 23301) each have a corner within the validator's position tolerance (6.44e-8 for Vase) of a non-incident edge of the same quad. These are the 3 `GeometricVertexOnUnsplitEdge` issues.
   - `quad_embedding_failure` had no contact test.
   - With one, defined by the validator's own tolerance, the boundary search rejects 401 candidates and finds an embedded alternative for every patch. Vase still completes with 67,750 quads.

**After CB97–CB99, Vase has `validationIssues=0`** (no T-junctions, self-intersections, degenerate or inverted faces). Its terminal becomes `NotProductionReady:completion detail=AggregateCompletionValidationFailure`, which is the calibrated quality gates (§2.1 item 10), now reported truthfully.

## RA-210.4 Trajectory finding: side subdivision by source-edge crossings (P13-n, Review next)

- **The completed Vase mesh fails quality by a wide margin:**
  - nonConvex 16,812;
  - angle P5/P95 6.5°/180°;
  - warpage P95 156°;
  - scaled Jacobian min −1;
  - boundary valence mismatches 248.
- **Census of the output:** **26,323 of 67,750 quads (39%) have a corner above 170°**, and there are **4,543 valence-2 vertices**.
- **The proxy reading:** those corners sit where degree-2 arrangement nodes, which are source-edge crossings of a single trace, become patch-side subdivisions. Completion then has to place flat corners on them.
- **Why this conflicts with DESIGN:**
  - DESIGN §4/§5 A3 makes side subdivision counts a property of the **conformity plan** ("edge labels are subdivision counts along those arcs").
  - Here they are a property of how the source triangulation cuts each trace, which is a representation artifact.
- **This is a hypothesis, not a fix.** The degree-2 attribution is by output-valence proxy.
- **The Review must:**
  - count degree-2 nodes and flat corners exactly per patch;
  - check that the quality metrics (warpage, normal, Jacobian) evaluate concave quads faithfully, as CB98 does for contact;
  - name the owner: the A3 plan versus completion's interior-vertex patterns.

  No CB until then.

## RA-210.5 Exact turns (each applies on the previous one's result)

**CB97 — `M6-CP3-CB97-P13-VALIDATOR-CONTACT-LENGTH-UNITS`**
- **Precheck:** `git diff --quiet 11c8172ad467c6dc865f2f3352e75b78f5469a2b HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB97_P13_Validator_Contact_Length_Units.diff`](Architecture_M6_CP3_CB97_P13_Validator_Contact_Length_Units.diff).
  - SHA-256 `84b8414fb58df6dfb90b5e425d15c26aac0ccaa73b4ffbf31dbf9dbc38737071`.
  - 114 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/SourceAuthoritativeMeshValidator.h` | `3 0` | `7f3ae0db…` |
  | `src/validation/SourceAuthoritativeMeshValidator.cpp` | `18 9` | `c71a2054…` |
  | `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` | `30 0` | `627eb086…` |

- **Content:** `line_offset2` is the signed distance from a line, and all three 2D predicates compare it with the tolerance.
- **New test:** `SourceAuthoritativeMeshValidatorPhase22.CoplanarContactIsMeasuredInLengthUnits`. It FAILS on legacy.

**CB98 — `M6-CP3-CB98-P13-VALIDATOR-CONCAVE-QUAD-TRIANGLES`**
- **Precheck:** the CB97 results.
- **Patch:** [`…CB98_P13_Validator_Concave_Quad_Triangles.diff`](Architecture_M6_CP3_CB98_P13_Validator_Concave_Quad_Triangles.diff).
  - SHA-256 `14986e38261eb46796262b262801bcf9c5dd255344c918f10867224510b7ce6a`.
  - 113 lines; **keep its 4 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `SourceAuthoritativeMeshValidator.h` | `3 0` | `3b31cb35…` |
  | `SourceAuthoritativeMeshValidator.cpp` | `35 2` | `55360202…` |
  | `SourceAuthoritativeMeshValidatorPhase22Tests.cpp` | `32 0` | `a02f6a79…` |

- **Content:** `quad_fan_corner` fans a concave quad from its reflex corner, judged against the Newell normal.
- **New test:** `…Phase22.ConcaveQuadContactUsesTrianglesInsideTheQuad`. It FAILS on legacy.

**CB99 — `M6-CP3-CB99-P13-COMPLETION-CORNER-ON-OPPOSITE-EDGE`**
- **Precheck:** the CB98 results.
- **Patch:** [`…CB99_P13_Completion_Corner_On_Opposite_Edge.diff`](Architecture_M6_CP3_CB99_P13_Completion_Corner_On_Opposite_Edge.diff).
  - SHA-256 `92c67e63bbbeabb7504e349c8f48637c3b26aee39e36423fbeee0a1e2d45dcbe`.
  - 344 lines; **keep its 14 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/PureQuadCompletion.h` | `11 4` | `c9a8d90d…` |
  | `SourceAuthoritativeMeshValidator.h` | `7 0` | `ab0e2f01…` |
  | `src/geometry/PatchDescriptor.cpp` | `4 0` | `30cd7da3…` |
  | `src/geometry/PureQuadCompletion.cpp` | `42 15` | `4da63b68…` |
  | `SourceAuthoritativeMeshValidator.cpp` | `14 10` | `abb10499…` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `41 0` | `f728585d…` |

- **Content:**
  - `source_position_tolerance` is the one shared definition. The validator calls it, and so does completion, once per pass.
  - New kind `CornerOnOppositeEdge`.
  - `PureQuadCompletionOptions::positionTolerance`, which defaults to off for direct callers.
- **New test:** `PureQuadCompletionPhase18.QuadEmbeddingRejectsACornerOnTheOppositeEdgeAtThePositionTolerance`, using the Vase quad 41746 witness in all 8 orders, with a square as the positive control. It cannot compile on legacy; behaviourally, legacy accepted the witness.

**Build (each CB):** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.

**Routes:**

| CB | Mismatch | Infrastructure |
|---|---|---|
| CB97 | `M6-CP3-PLAN-P13-VALIDATOR-CONTACT-LENGTH-UNITS-STOP` | `M6-CP3-CB97A-…-ORCH` |
| CB98 | `…-VALIDATOR-CONCAVE-QUAD-TRIANGLES-STOP` | `CB98A-…-ORCH` |
| CB99 | `…-COMPLETION-CORNER-ON-OPPOSITE-EDGE-STOP` | `CB99A-…-ORCH` |

**Verified in scratch:**
- The chain applies cleanly on a fresh `11c8172ad` worktree and reproduces the tested tree byte for byte.
- The local gate passes **905/906** (only row 283, O16).
- Census digests for Plane, MultiFaceSeam, CloseSheets, Cylinder and BunnyRandom are **identical**.
- Vase is identical through `simplification`; completion is `e63758b9…/67750`, with `validationIssues=0`.
- GCC 16 `-Wall -Wextra`: no new warnings in any changed unit.

## RA-210.6 TB84 — `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-EXEC` (after CB99)

- **Gate:** [`Architecture_M6_TB84_P13_Contact_Predicates_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB84_P13_Contact_Predicates_Full_Gate_Case_Manifest.tsv).
  - 906 rows, SHA-256 `09eff7ed146ef39836706f4d87ae8e9309e35ab16787b6d1e8c3f39314a0b7ff`.
  - TB83's 903 rows byte for byte, plus GUARD rows 904–906 (the three new tests).
  - `SELF_CHECK_PASS cases=906 deferred=81`.
  - **906/906**, membership **987**.
- **Census:** Cylinder PASS; BunnyRandom P13-e at vertex 49; Vase RED.
- **Pinned digests:**
  - gate rows 795/796/797/864, census Cylinder and census BunnyRandom: byte-identical to TB83;
  - Vase: byte-identical through `simplification`.
- **Registered expectations,** observed on macOS and recorded, not pinned:
  - Vase `completion` hash;
  - Vase suffix ` validationIssues=0`;
  - Vase terminal `NotProductionReady:completion detail=AggregateCompletionValidationFailure`.

  A Linux difference in any of these routes to REV.
- **Routes:**
  - mismatch → `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB84A-P13-CONTACT-PREDICATES-ORCH`.

## RA-210.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 49 — NEXT | `M6-CP3-CB97-P13-VALIDATOR-CONTACT-LENGTH-UNITS` | Implementation agent |
| 50 | `M6-CP3-CB98-P13-VALIDATOR-CONCAVE-QUAD-TRIANGLES` | Implementation agent |
| 51 | `M6-CP3-CB99-P13-COMPLETION-CORNER-ON-OPPOSITE-EDGE` | Implementation agent |
| 52 | `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-EXEC` | Implementation agent |
| 53 (Review, after TB84) | `M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY` (P13-n) | Claude, scratch build (RA-210.4) |
| then | P13-e, O31, O32e → d → b/c, O33 | Claude, scratch build |
| then | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | — |

## Review closeout

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Retained-run parity. Node and arc provenance. All-pairs contact census under each variant. Pinch census and Vase outcome. Output flat-corner census |
| Non-vacuity checked | All three new tests fail on legacy; CB99's witness was accepted in production |
| Accepted selector prefix re-hashed | The 906-row manifest's 903-row prefix is TB83's |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| Turn boundary held | No product or test source changed in the repository; patches are committed `.diff`s |
| `STATUS` lifecycle maintained | Started-at preserved; IN_PROGRESS beacon pushed; COMPLETE is the final write, with Successor CB97 |
