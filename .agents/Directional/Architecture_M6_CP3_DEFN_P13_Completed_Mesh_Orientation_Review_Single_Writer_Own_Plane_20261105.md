# RA-209 — Review of RA-208: the orientation pass must go, and both embedding predicates must project onto the quad's own plane (2026-11-05)

**Reviewed turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` ([RA-208](Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Probe_Adjudication_20261105.md)), in an adversarial re-entry.

**State:**
- The implementation agent applied RA-208's CB93 at `e96e98806` (result hashes verified) and is compiling it under STATUS `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` IN_PROGRESS.
- RA-209 does not touch that turn. CB93 completes as frozen, and RA-209 replaces everything after it.

**Scratch build:** `bld55n` (FMA-off, static), synced to the trees named below and checked with `diff -rq` or `cmp`. The scratch census test adds the env-gated `PROBE_DUMP_ORIENT` snapshot dump; it is not in any patch.

## RA-209.1 What RA-208 got right

- The block resolution.
- The pre/post census:
  - completion's stitched output has 0 same-direction edges and 0 source-inverted quads;
  - the first-triangle orientation pass reverses 7,630 correct quads;
  - the first-triangle validator projection depends on corner order.
- The residue's location: 1 overlap and 3 T-junctions.
- CB93's whole-quad normal is a correct predicate. Its two-quad test is sound.

## RA-209.2 Defects in RA-208 (my own)

1. **It repaired a component the architecture forbids instead of removing it.**
   - DESIGN §3 says downstream stages "validate or consume authority; they never recreate it".
   - DESIGN item 4 says no stage "may … edit, repair, re-solve, or re-derive an earlier stage's immutable product".
   - M2 says consumers "may validate it; they do not rewrite".
   - `orient_quads_to_source_normals` rewrites completion's orientation after completion. Completion already rejects every quad whose whole-polygon normal is more than 60° from its source normal; this is gated by rows 874 and 875.
   - **Measured:** with CB93's predicate, the pass flips **0** pipeline quads across the full 903-row gate and the five-fixture census, Vase included. The only flip it ever makes is the deliberately inverted quad in CB93's own unit test.
   - It is a dead second writer. It also projects centroids onto the unrestricted source, so on close sheets it could pick the wrong sheet and invert a correct quad. **Remove it.**
2. **CB94 adopted completion's axis projection, which accepts genuinely self-intersecting quads.**
   - RA-208 measured crossings in the quad's own Newell plane and in the source plane, and still chose a predicate that projects along the coordinate axis nearest the normal. That axis can be up to 55° off.
   - Over all 67,750 Vase quads: **17 cross in their own plane** and 31 in the source-normal plane (36 together).
   - **12 of them are bow-ties in both planes:** two reflex corners against each normal, and diagonal dihedrals up to 178.7°.
   - Completion's axis predicate accepts all 17, and so did RA-208's CB94. The order-invariant and faithful definition is **orthogonal projection onto the Newell plane**, in both producer and validator, each with its own implementation (DESIGN §9).
3. **The success claim was inflated.** RA-208 reported "Vase 35,416 → 4 issues". The 4 held only because the validator shared completion's blind spot. Under the faithful definition the validator alone reports 21 (17 twisted quads, 1 overlap, 3 T-junctions). Only with the producer also fixed (CB96) does Vase return to 4, and then honestly.
4. **Minor:** CB94's degenerate rule compares the vector area with `tolerance · longestEdge²`. That makes the geometric tolerance act as a dimensionless ratio, inconsistent with its absolute use in `ZeroAreaFace`. The criterion is scale-invariant (area/L² ≤ 1e-9) and has no false positive on any fixture; it is kept, and the comment states it.

## RA-209.3 Realigned turns (exact; each applies on the previous one's result)

**CB93 (in progress, unchanged):** RA-208.3, applied at `e96e98806`. Finish its compile.

**CB94 — `M6-CP3-CB94-P13-ORIENTATION-SINGLE-WRITER`**
- **Precheck:** `git diff --quiet e96e98806cf5fd055df3dd45c629f124c77c5dd5 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB94_P13_Orientation_Single_Writer.diff`](Architecture_M6_CP3_CB94_P13_Orientation_Single_Writer.diff).
  - SHA-256 `a19dd0cde27d1a95f24f4c40ec89d9264fdb44f5aae59da75af5abb1465e52b7`.
  - 183 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/pipeline/RemeshPipeline.h` | `0 7` | `112a024ca7d01f81a24aa4f9b98b13480052da190452f2c9b531a567c106d980` |
  | `src/pipeline/RemeshPipeline.cpp` | `3 104` | `18043141fe7720915f46d7d400ff86146c8a39a8346222ea80a4986df8040629` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `0 31` | `913b97e7a3731aff9899f108cb81d9499517f55071a87376355ddd8e6da27bac` (the pre-CB93 file) |

- **Content:** removes the call, the function, its declaration and CB93's unit test. A 3-line comment states the single-writer rule.
- **No new test.** The guarantee is completion's, already gated by rows 874–875. The removed function has no behaviour left to test. TB83's Vase pin (no `FlippedFace`, against 35,164 under the legacy pass) is the integration falsifier.

**CB95 — `M6-CP3-CB95-P13-QUAD-SELF-INTERSECTION-OWN-PLANE`**
- **Precheck:** the three CB94 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB95_P13_Quad_Self_Intersection_Own_Plane.diff`](Architecture_M6_CP3_CB95_P13_Quad_Self_Intersection_Own_Plane.diff).
  - SHA-256 `8207716b9993a9d1e290ff4fe9eb4794ff505dfb601708bcd965c68cf4d0c014`.
  - 158 lines; **keep its 4 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/MeshValidator.h` | `40 35` | `15b813d3b1d312d2a7f6c742c951c002b7b633f3cee00ae317f1872d83a08f3e` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `49 0` | `4cd349c3b7b6bdfa61032d38042018e013cad722c9f01d17b005907d43ae1e3a` |

- **Content:**
  - `quad_self_intersects` builds the Newell normal and treats a vanishing vector area as self-intersecting;
  - it projects **orthogonally onto the quad's own plane** (`unitOrthogonal` basis);
  - it removes the class's orphaned `dominant_axis` and `project2`.
- **New test:** `SurfaceCellsPhase10.QuadSelfIntersectionDoesNotDependOnCornerOrder`, covering in all 8 corner orders:
  - the skew witness (equal verdicts);
  - **Vase twisted quad 65858** (flagged; margin 0.019·L²);
  - a symmetric bow-tie (flagged).
- **Non-vacuity:** it FAILS on the legacy validator. RA-208's axis variant misses the twisted witness, which was selected for exactly that.

**CB96 — `M6-CP3-CB96-P13-COMPLETION-EMBEDDING-OWN-PLANE`**
- **Precheck:** the two CB95 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB96_P13_Completion_Embedding_Own_Plane.diff`](Architecture_M6_CP3_CB96_P13_Completion_Embedding_Own_Plane.diff).
  - SHA-256 `a7e81da57d5d1bf37847ccf0b5ee3abeca5230c0605d35056e6a12d40b54f469`.
  - 74 lines; 0 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PureQuadCompletion.cpp` | `9 12` | `b756c3f29481112f10d382f479caad17861927e56e97ab4f574b6c6c87c200b8` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `31 0` | `6ca86f6e721589fae1dcf150cd88e88d152ec559b9fb4cf18a91a0874e88355d` |

- **Content:** `quad_embedding_failure` projects orthogonally onto the quad's own plane. This is the same definition as CB95, implemented separately.
- **New test:** `PureQuadCompletionPhase18.QuadEmbeddingFindsTheCrossingOfATwistedQuadInItsOwnPlane` expects the twisted witness to be `BowTieIntersection` in all 8 orders. It **FAILS on legacy**, which returns `None`.

**Build (each CB):** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.

**Routes:**

| CB | Mismatch | Infrastructure |
|---|---|---|
| CB94 | `M6-CP3-PLAN-P13-ORIENTATION-SINGLE-WRITER-STOP` | `M6-CP3-CB94A-P13-ORIENTATION-SINGLE-WRITER-ORCH` |
| CB95 | `M6-CP3-PLAN-P13-QUAD-SELF-INTERSECTION-OWN-PLANE-STOP` | `M6-CP3-CB95A-…-ORCH` |
| CB96 | `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-OWN-PLANE-STOP` | `M6-CP3-CB96A-…-ORCH` |

**Verified in scratch:**
- The chain CB94 → CB95 → CB96 applies cleanly on a clean `e96e98806` worktree and reproduces the scratch tree **byte for byte**.
- Results on the final tree:

  | Check | Result |
  |---|---|
  | 903-row gate | **902/903** (only row 283, O16) |
  | Census digests, Plane / MultiFaceSeam / CloseSheets / Cylinder / BunnyRandom | **identical** to post-CB92, apart from the suffix |
  | Census digest, Vase | changes only `completion` (`7f9763a9…/67750`; count unchanged) |
  | Vase validation | `validationIssues=4 GeometricVertexOnUnsplitEdge=3 SelfIntersectingFace=1`; 0 FlippedFace; 0 local self-intersections; 0 flips |
  | Effect of CB96 | the patches that produced the 17 twisted quads take other variants; completion still succeeds |
  | Validator-only state (CB94+CB95) | 21 issues, all genuine: 17 twisted, 1 overlap, 3 T-junctions |
  | Both new tests on legacy | FAIL |
  | GCC 16 `-Wall -Wextra -fsyntax-only`, all six changed units | clean |

## RA-209.4 TB83 — `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-EXEC` (after CB96)

- **Package:** the immutable CB96 package.
- **Gate:** [`Architecture_M6_TB83_P13_Embedding_Predicate_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB83_P13_Embedding_Predicate_Full_Gate_Case_Manifest.tsv).
  - 903 rows, SHA-256 `61e9edbedee3731b04d7b6279b79a0fd0e0b651686638e9b832773f7aa0a36aa`.
  - TB82's 901 rows byte for byte, plus row 902 (the CB95 test, producer binary) and row 903 (the CB96 test, completion binary).
  - `SELF_CHECK_PASS cases=903 deferred=81`.
  - **903/903**, membership **984**.
- **Census:** Cylinder PASS; BunnyRandom P13-e at vertex 49; Vase RED within 600 s.
- **Pinned digests:**
  - gate rows 795, 796, 797 and 864, and census Cylinder: byte-identical to TB82, followed by ` validationIssues=0`;
  - census BunnyRandom: byte-identical to TB82;
  - census Vase: byte-identical to TB82 through `simplification`, then `completion` (recorded), then a ` validationIssues=` suffix **with no `FlippedFace`**. Its counts are recorded; macOS gives 4.
- **Routes:**
  - mismatch → `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB83A-P13-EMBEDDING-PREDICATE-ORCH`.

**Superseded and removed** (never applied):
- RA-208's CB94 diff (`…CB94_P13_Quad_Self_Intersection_Corner_Order.diff`);
- RA-208's TB83 manifest (`…TB83_P13_Orientation_Predicate_…`), which gates CB93's test that CB94 removes.

## RA-209.5 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 43D — IN PROGRESS | `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` | Implementation agent; finish as frozen (RA-208.3) |
| 43E — NEXT after 43D | `M6-CP3-CB94-P13-ORIENTATION-SINGLE-WRITER` | Implementation agent; RA-209.3 |
| 43H | `M6-CP3-CB95-P13-QUAD-SELF-INTERSECTION-OWN-PLANE` | Implementation agent; RA-209.3 |
| 43I | `M6-CP3-CB96-P13-COMPLETION-EMBEDDING-OWN-PLANE` | Implementation agent; RA-209.3 |
| 43F | `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-EXEC` | Implementation agent; RA-209.4 |
| 43G (Review, after TB83) | `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2) | Claude, scratch build. 1 overlap and 3 T-junctions; re-locate the overlap's faces after CB96 |
| 44 / 44A / 44B / 44C | P13-e; O31; O32e → d → b/c; O33 | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The 903-row manifest's 901-row prefix is TB82's; self-check PASS |
| Decisive claims independently re-derived | Helper flip census over the gate and census. Crossing census in the Newell plane and the source plane, with corner signs and dihedrals. The CB96 effect on Vase. Byte-identity of the patch chain |
| Non-vacuity checked | Both new tests FAIL on legacy. The twisted witness was chosen because the axis predicate misses it |
| Prior obligations discharged/carried | RA-208 CB94/TB83 superseded. P13-l2, P13-e, O30b, O31, O32b–e, O33 carried |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| ORIENTATION / TODO / handoff / CHANGELOG / tracker / LESSONS | Updated |
| Turn boundary held | No product, test, fixture or build source changed in the repository; the patches are committed `.diff`s. Scratch probes only |
| `STATUS` lifecycle maintained | Not written: CB93 is IN_PROGRESS (`b734d1cd3`). RA-209 replaces only its successors |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
