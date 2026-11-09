# RA-208 — P13-l resolved: the block, the measured owners, and exact CB93/CB94 (2026-11-05)

> **Reviewed by [RA-209](Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md).** The census and CB93 stand; CB93 is applied at `e96e98806`. The rest is superseded:
> - the orientation pass must be removed (single writer; 0 flips in production);
> - both embedding predicates must project orthogonally onto the quad's own plane, because the axis projection accepts 17 genuinely twisted Vase quads;
> - "35,416 → 4" relied on that blind spot.
>
> CB94 to CB96 and TB83 are replaced, and the RA-208 CB94 diff and TB83 manifest are removed (never applied).

**Turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`, resumed from the ChatGPT Review's BLOCKED checkpoint. See its [WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_WIP_20261105.md").

**Source:** HEAD at CB92's semantic source `d9921cdd5`. `git diff --quiet d9921cdd5 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes.

**Scratch build:** `bld55n`, FMA-off clang/libc++ static, synced to HEAD and checked with `diff -rq`. Its census test was given a scratch-only dump (`PROBE_DUMP_ORIENT`) that writes the existing rejected-result snapshots: `surfaceCellContext.completedQuads` (pre-orientation), `productSnapshots.optimizationResult.quads` (post-orientation), vertices, quad lineage, vertex provenance and `strictValidationIssues`. The dump is not part of any patch. The census tools are `scratchpad/p13l/tools/*.py` (numpy, exact edge census).

## RA-208.1 The block

The ChatGPT Review stopped with `REVIEW_BLOCKER`: the snapshots need a new Directional runtime, and it held that a Review cannot run one without a diagnostic CB/TB.

- **There is no policy conflict, as RA-203.1 already ruled.** Review scratch probes are a Review duty (RA-166.6 F6, RA-188.1). This turn was assigned to "Review (Claude, scratch build)" (handoff row 43B). A Review that cannot run a scratch probe records BLOCKED; it does not route evidence collection through the implementation agent.
- **A diagnostic CB/TB is the wrong tool.** It would spend two implementation turns and add test-only export code to the gate just to obtain data that one scratch run produces in 98 s.
- **The WIP's static work was right, and it is used here.** In particular:
  - the existing rejected-result return channel holds both matrices;
  - the first-triangle orientation and projection defects, with their integer witnesses;
  - the A–F decision table.
- No policy changes.

## RA-208.2 Measured on CB92 Vase (macOS, one run; 67,961 vertices, 67,750 quads)

| | Pre-orientation (stitched completion) | Post-orientation (`orient_quads_to_source_normals`) |
|---|---|---|
| Undirected edges / boundary / non-manifold | 135,710 / 420 / 0 | identical set |
| **Same-direction interior edges** | **0** | **27,597** (all introduced; 19,086 cross-patch, 8,511 intra-patch) |
| Quads inverted against the source (whole-polygon Newell vs source normals) | **0** | 7,630 |
| Quads whose first-triangle normal disagrees with their whole polygon | 7,904 | — |
| Quads reversed by the helper | — | **7,630, every one already agreeing with the source** |
| Validator first-triangle local crossing | 447 | 248 |
| Completion's predicate (Newell dominant axis, eps 1e-13 or tol 1e-9) | **0** | **0** |
| Validation issues | — | FlippedFace 35,164; SelfIntersectingFace 249 (248 local, 1 global); GeometricVertexOnUnsplitEdge 3 |

**Classification against the WIP's A–F table:**
- **B is confirmed and dominant.** Completion's output is consistently oriented and agrees with the source. The helper's first-triangle test then reverses 7,630 correct quads.
- **E/F are confirmed.**
  - The validator's local crossing projects along the first triangle's normal. That axis depends on which corner starts the cycle and on its direction, so the verdict does too: 447 quads before the helper and 248 after, against 0 under completion's whole-polygon definition.
  - In a projection-free check, few of the 248 cross: 11 in the quad's own Newell plane, 17 in the source-normal plane.
- **D is present and small.**
  - The global intersection is between faces 55 (patch 118) and 15372 (patch 54), which overlap over source face 1263. Neither face was flipped.
  - There are 3 T-junctions:
    - vertices 35161 (t = 0.0007) and 53049 (t = 0.0000) lie on edges (4618, 35159) and (28576, 53051) at about 5e-8 distance: unmerged near-coincident vertices;
    - vertex 35160 lies at t = 0.5003 of edge (4618, 35159), between patches 4955 and 4957: a side-subdivision mismatch.
- **A is excluded** on Vase: there were 0 conflicts before the helper.

**With both fixes (scratch):**
- 0 flips, 0 same-direction edges and 0 FlippedFace;
- 0 local self-intersections;
- the issues fall from 35,416 to **4**: 1 global `SelfIntersectingFace` and 3 `GeometricVertexOnUnsplitEdge`;
- the terminal is still RED `SelfIntersectingFace`, now meaning the genuine overlap.

## RA-208.3 CB93 — `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` (exact)

- **Precheck:** `git diff --quiet d9921cdd5a174bbb00b68387082cf08df80f97c5 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB93_P13_Orientation_Whole_Quad_Normal.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB93_P13_Orientation_Whole_Quad_Normal.diff").
  - SHA-256 `2510e2ddefa717eb71cf50174c29b461713caa5588e61382aab926ef48deebfe`.
  - 94 lines; **keep its 2 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/pipeline/RemeshPipeline.cpp` | `13 4` | `5bb0277ca708e5a34f3ed5416c5d69039526b06806c8dd73de0f40f1dd7a3a31` |
  | `tests/SurfaceCellDesignAcceptanceTests.cpp` | `15 0` | `48bd985008a3803b6cdcadaa90ecf244f980ad4c5e20d76c56da2e0419935a1e` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `31 0` | `3e8604cd3c0d0229bcb7ceac2331d6888094d987bf1220253a7d8434f5ac0fe8` |

- **Content:**
  1. `orient_quads_to_source_normals` compares the source normal with the **whole-polygon Newell vector area** instead of the first triangle's normal. This is the predicate completion's `quad_embedding_failure` already enforces.
  2. The census digest line gains ` validationIssues=<n>` plus counts per failure name, so a census shows every check a RED output fails.
  3. New test `SurfaceCellsPhase10.SourceOrientationKeepsAWholeQuadThatAgreesWithTheSource` uses the WIP's two-quad witness:
     - Q0 (signed double area +19, first triangle −1) and its neighbour stay unchanged;
     - a clockwise quad is still reversed.

     It **fails on the legacy helper**, which flips Q0.

## RA-208.4 CB94 — `M6-CP3-CB94-P13-QUAD-SELF-INTERSECTION-CORNER-ORDER` (exact, applied on CB93)

- **Precheck:** the three CB93 result SHA-256 values above, and the CB93 source commit.
- **Patch:** [`Architecture_M6_CP3_CB94_P13_Quad_Self_Intersection_Corner_Order.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB94_P13_Quad_Self_Intersection_Corner_Order.diff").
  - SHA-256 `a15632d1ba9149c7fbb47bba6fae71db56c34de999debd2977cc797d51a7ef91`.
  - 88 lines; **keep its 2 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/MeshValidator.h` | `19 1` | `892f00196bc57aa6fb739a9c5e8049693d20d580ff5490c954578c830c4b715f` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `41 0` | `dc7a6f1169413201d0a2047a787ec76e15b74ea80d1af99d700d845c1c8a9116` |

- **Content.** `MeshValidator::quad_self_intersects` projects along the **Newell normal**, which is invariant to the starting corner and the direction. A quad whose vector area is at most `tolerance · longestEdge²` is reported as self-intersecting: a symmetric bow-tie has no embedding, and completion rejects it as `DegenerateNormal`.
  - Without that rule, gate row 734 (`MeshValidatorDetectsDuplicateAndInvalidFaces`) went RED in scratch.
  - The validator keeps its own implementation (DESIGN §9 independence). Only the definition is shared with completion.
- **New test:** `SurfaceCellsPhase10.QuadSelfIntersectionDoesNotDependOnCornerOrder` checks the WIP's non-planar witness and a symmetric planar bow-tie in all 8 corner orders:
  - the non-planar witness gets the same verdict in every order;
  - the bow-tie is flagged in every order.

  It **fails on the legacy validator**: the forward cycle is false and the reversed one true.

**Verified in scratch (both CBs, applied in sequence on a clean `f8a0c1b35` worktree; byte-identical to the scratch tree):**

| Check | Result |
|---|---|
| 903-row local gate | **902/903** (only row 283, O16); rows 734, 902 and 903 PASS |
| Census digest lines, all six fixtures | **identical** to the post-CB92 build apart from the new suffix |
| Suffix, Plane / MultiFaceSeam / CloseSheets / Cylinder | `validationIssues=0` |
| Suffix, Vase | `validationIssues=4 GeometricVertexOnUnsplitEdge=3 SelfIntersectingFace=1` |
| Both new tests on the legacy files | FAIL |
| GCC 16 `-Wall -Wextra -fsyntax-only` on every changed unit | clean |

**Build (each CB):** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.

**Routes:**

| CB | Mismatch | Infrastructure |
|---|---|---|
| CB93 | `M6-CP3-PLAN-P13-ORIENTATION-WHOLE-QUAD-STOP` | `M6-CP3-CB93A-P13-ORIENTATION-WHOLE-QUAD-ORCH` |
| CB94 | `M6-CP3-PLAN-P13-QUAD-SELF-INTERSECTION-STOP` | `M6-CP3-CB94A-P13-QUAD-SELF-INTERSECTION-ORCH` |

## RA-208.5 TB83 — `M6-CP3-TB83-P13-ORIENTATION-PREDICATE-FULL-GATE-EXEC` (after CB94)

- **Package:** the immutable CB94 package, which contains CB93.
- **Gate:** [`Architecture_M6_TB83_P13_Orientation_Predicate_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB83_P13_Orientation_Predicate_Full_Gate_Case_Manifest.tsv").
  - 903 rows, SHA-256 `20dc101d78889dc98adf4a048fb253ec66c4fda640e76247a0d5d9f4a92d57fb`.
  - TB82's 901 rows byte for byte, plus GUARD rows 902–903.
  - `SELF_CHECK_PASS cases=903 deferred=81`.
  - **903/903**, membership **984**.
- **Census:** manifest `3af1dc0d…`.
  - Cylinder PASS.
  - BunnyRandom P13-e at vertex 49.
  - Vase RED within 600 s, `detail=SelfIntersectingFace`.
- **Pinned digests:**
  - gate rows 795, 796, 797 and 864, and census Cylinder: byte-identical to TB82, followed by ` validationIssues=0`, which a PASS entails;
  - census BunnyRandom: byte-identical to TB82, with no suffix;
  - census Vase: byte-identical to TB82 through its last product item, followed by a ` validationIssues=` suffix that **contains no `FlippedFace`**. Its counts are recorded; macOS gives 4.
- **Routes:**
  - match → the Review track (RA-208.6);
  - mismatch → `M6-CP3-TB83-P13-ORIENTATION-PREDICATE-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB83A-P13-ORIENTATION-PREDICATE-ORCH`.

## RA-208.6 Trajectory and turn sequence

P13-l splits into two parts:
- **P13-l1 (orientation and predicate)** is owned by CB93/CB94.
- **P13-l2, the genuine residue:** 1 overlap and 3 T-junctions. It goes to the Review DEFN `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP`, which starts from RA-208.2's witnesses:
  - near-coincident unmerged vertices → stitch identity;
  - midpoint side mismatch → side subdivision across patches 4955 and 4957;
  - the patch 118 / 54 overlap → arrangement or completion.

The pre-optimization quality question the WIP raised is moot for Vase: every remaining issue is a safety class. It is carried to the Vase PASS re-census.

| Step | Turn | Track |
|---|---|---|
| 43A — COMPLETE | `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY` | `d9921cdd5` |
| 43C — COMPLETE (MATCH) | `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC` | 901/901 |
| 43B — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | ChatGPT WIP (BLOCKED), then RA-208 |
| 43D — NEXT | `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` | Implementation agent; RA-208.3 |
| 43E | `M6-CP3-CB94-P13-QUAD-SELF-INTERSECTION-CORNER-ORDER` | Implementation agent; RA-208.4 |
| 43F | `M6-CP3-TB83-P13-ORIENTATION-PREDICATE-FULL-GATE-EXEC` | Implementation agent; RA-208.5 |
| 43G (Review, after TB83) | `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2) | Claude, scratch build |
| 44 / 44A / 44B / 44C | P13-e; O31; O32e → d → b/c; O33 | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The 903-row manifest's 901-row prefix is byte-identical to TB82's (`9fbf3291…`); self-check PASS |
| Decisive claims independently re-derived | The return channel confirmed on a real run. An exact directed-edge census before and after. The predicate comparison over all 67,750 quads. Issue origin split. Both fixes measured end to end |
| Non-vacuity checked | Both new tests fail on the legacy code. Row 734 caught the degenerate bow-tie gap in the first CB94 draft |
| Prior obligations discharged/carried | P13-l → P13-l1 (CB93/CB94, TB83) and P13-l2 (DEFN). P13-e, O30b, O31, O32b–e, O33, O27–O29, DR1/DR3 carried |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | P13-l2 (overlap and T-junction witnesses) |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`, RA-208 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 and §8 updated; §3 and §4 unchanged |
| CHANGELOG | RA-208 entry |
| ROADMAP | n/a |
| Selector manifest | New 903-row TB83 manifest, self-checked |
| LESSONS | A geometric predicate must not depend on corner order; pipeline and validator must share one definition |
| Consolidation under CLEAN_UP_POLICY | The WIP is retained with a resolution line |
| Successor frozen | CB93, CB94, TB83 (exact) |
| Turn boundary held | No product, test, fixture or build source changed in the repository; the patches are committed `.diff`s; the manifest is new. Scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Re-entry beacon pushed in canonical form. The non-canonical `Blocker` lines are dropped. COMPLETE with Successor CB93 is the final write. This Review's work began at 2026-11-05T18:42:39Z. A ChatGPT session resumed the same turn at 19:09:27Z and produced no record |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
