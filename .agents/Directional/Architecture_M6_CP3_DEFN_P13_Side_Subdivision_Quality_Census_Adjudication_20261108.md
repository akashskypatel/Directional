# RA-211 — P13-n side-subdivision quality: per-patch census and owner adjudication (2026-11-08)

> **Partly superseded by [RA-212](Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md) (same day, adversarial re-entry).** The §2 census stands. Corrections:
> - Vase's layout is about 20× denser than its metric target, because 1,131 of its 1,416 seeds are relief-critical (O31).
> - Vase is the only census fixture on the legacy fallback; the four passing fixtures are produced by the phase front, so the fixture-digest falsifiers in §4/§7 are vacuous for legacy changes.
> - `turns` has no behavioural consumer, so P13-n2's owner is completion's patch model, not the descriptor sign.
> - Parity repair writes 121 rail breakpoints, which §7.4 forbids.
> - CB100 is replaced (own-plane reference, `8c11fb85…`) and CB101 is added (`normalP95` was 121.56° only because of the first-triangle normal).
> - TB85 is now 908 rows.
> - §7's next Review is withdrawn in favour of `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH`.

**Turn:** `M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY` (Review / DEFN, P13-n), Claude scratch track. **Disposition:** the REVIEW_BLOCKER is resolved. The owners are adjudicated. One exact CB (CB100) and one TB (TB85) are frozen. The dominant producer fix is prototyped and **falsified as a standalone landing**, so it goes to a separate Review (`M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY`) with the evidence below.

## 1. Block and resolution

ChatGPT's [WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_WIP_20261108.md") blocked on "independent per-patch Vase source-edge subdivision and concave-quality scratch census … unavailable; obtain immutable-source lineage evidence". The WIP's static findings S1 and S2 are correct (§3).

Scratch census on the Review track (RA-166.6 F6, RA-188.1, RA-203.1):
- **Source:** HEAD `c9c50f1e9`. Product sources are byte-identical to CB99 `553932b04`; only the env-gated test probe in `SurfaceCellDesignAcceptanceTests.cpp` differs.
- **Run:** retained-geometry Vase run. Its `platform-digest` line is **byte-identical** to the normal run (`completion=e63758b94110a4f7/67750`, macOS; Linux is `946b59dbe8279a65/67750` per TB84).
- **Dumps:** the completion complex (66,715 nodes, 187,060 halfedges, 26,817 cells) and 26,816 patch descriptors (114,913 sides). Also completed-vertex lineage (stitch kind and arrangement node) and quad lineage (backend, `boundaryOnly`), plus pre- and post-optimization meshes.
- **Analysis:** reflex-aware corner angles about the Newell normal, signed corner turns about the source-face normal, node degree, and source-edge, strand and family identity.
- **Reproducibility:** the probe and scripts live in the session scratchpad (`rev211/tools/*.py`). The probe block is reproduced in §7.

## 2. Census (exact counts)

**Pre-repair vs repair.** The simplified complex has 57,636 nodes. Completion's parity repair finds **5,931 odd cells** and inserts **9,079 nodes** (57,636 → 66,715). Side repair finds 11,424 infeasible cells and inserts 0 (it falls back to `GeneralFallbackPreparation`).

**Side-interior vertices** (71,727 incidences on 114,913 sides):

| Class | Incidences |
|---|---|
| degree-2 on a source edge (D2E) | 46,452 (+40 on rails) |
| degree-2 inside a source face (D2F; arc joints and parity insertions) | 25,008 (+81 on rails) |
| degree-2 at a source vertex | 40 (+51 on rails) |
| junction (degree ≥ 3, T-junction) | **55** |

- **Raw counts:** 64,360 sides have count 1. 50,408 sides carry representation vertices.
- **Semantic counts:** skipping degree-2 plain same-side vertices leaves **114,725 / 114,913 sides at count 1**.

**Corners** (114,913 sides):

| Corner type | Count | Turn |
|---|---|---|
| Junction corners | 107,126 | exactly +90° |
| Degree-2 same-strand L-corners | 7,748 | ±90° |

- The L-corners split exactly in half: 3,874 at +90° (convex) and 3,874 at −90° (reflex). The descriptor hard-codes `turns = 1` for all of them.
- Patches by signed-turn sum: 4-sided 23,324; 6-sided with sum +4 (L) 2,942; 8-sided with sum +4 (U/Z) 371; others 179.
- **Sliver cells** (min/max corner-to-corner side length): 5,760 below 0.1, 677 below 0.01, 51 below 0.001. Examples: cells 8265 and 5604 have sides of 3.3e-5 and 3.9e-5 between nearly coincident traces (1120/1123, 1064/855).

**Output** (67,750 quads; pre- and post-optimization identical):
- **Valence-2 vertices:** 4,463, all degree-2 arrangement nodes (2,081 source-edge, 2,361 in-face, 21 source-vertex); 4,458 of them are also a >170° corner.
- **Quads with a corner > 170°:** 26,373, of which 11,867 are reflex (> 180°). The unsigned metric sees only 24,808.
- **Attribution of the worst corner of each bad quad:**

| Origin of that vertex | Quads | Share |
|---|---|---|
| source-edge crossing (arrangement representation) | 14,025 | 53.2% |
| parity-repair insertion (caused by representation parity) | 6,732 | 25.5% |
| in-face arc joint (arrangement representation) | 3,029 | 11.5% |
| reflex L-corner declared +1 | 2,232 | 8.5% |
| generated 228, feature 93, junction 18, convex corner 16 | 355 | 1.3% |

- **By backend** (bad/total): BoundedCombinatorial boundary-only 21,928/36,744; Pattern boundary-only 3,730/5,229; ClosedForm 415/4,074; ClosedForm boundary-only 200/21,209; TransitionTemplate 100/494.
- **Convex patches without representation side vertices:** only 1,214 of 11,092 quads are bad, counting the representation-free cells that were split by parity insertions.

## 3. Owner adjudication

| Id | Mechanism | Owner | DESIGN | Status |
|---|---|---|---|---|
| **P13-n1** | Arrangement representation vertices (per-face source-edge crossings, in-face arc joints) become patch breakpoints. Three count writers use one wrong definition: `PatchDescriptor.cpp` `extract_sides` (`++subdivisionCount` per halfedge), completion parity (`cell.halfedges.size() % 2`, two sites), and side repair (`effective_side_counts` over `cell.sideEdgeCounts`). | completion preparation / descriptor (A4 consumer) | §6.2 (semantic vs representation), §7.4 (producers may not insert breakpoints), M4 acceptance ("target-size variation cannot create different side breakpoints"), §10.1 | **Prototype falsified as a standalone landing** (§4); to Review |
| **P13-n2** | Reflex L-corners (a strand turns −90° at a degree-2 node) are declared convex: `patch.turns.push_back(1)` with the comment "the cell orientation determines its sign", but no sign is computed. | descriptor turns; upstream layout strands that turn at degree-2 nodes | §7.4, Amendment 29 (side partition) | to Review, coupled to n1 |
| **P13-n3** | Sliver cells from nearly coincident layout traces (677 below 1% side ratio). | layout strand spacing/selection | §2.2 quality | to Review, coupled to n1 |
| **P13-n4** | Evaluator: unsigned angle extrema (a reflex 233.13° is reported as 126.87°) and warpage over **both** diagonals (a planar concave quad reports 180°). | A8 `evaluate_surface_quad_quality` | §9 independent verification | **exact CB100** (§5) |

**A3 is not the owner.** The arrangement completion path builds the conformity baseline (299 entries) but never consumes it, and the Vase complex contains no A3-typed breakpoint. Only the phase-front path reads the schedule. Binding descriptors to A3 is CP3 promotion work, not P13. Within P13 the correct realignment is to make the existing local count model *semantic*, in line with §7.4.

**Latent defect found.** `side_halfedges(cell)` maps `cell.sideEdgeCounts` to halfedges by offset from `cell.halfedges[0]`. When `canonicalize_logical_sides` merges a side that wraps around index 0, the halfedges are attributed to the wrong sides. Raw counts hide this because their sum always equals `halfedges.size()`; semantic counts expose it (prototype A: counts ≤ 0, `MissingSideSubdivisionEdge`). It belongs to the n1 design.

## 4. Prototype evidence (scratch only, not for application)

The prototype adds `SurfaceArrangementNode::representationOnly`. It is placed beside `hardBarrierCrossing` so that `sizeof` is unchanged; otherwise `memoryRatioEstimate` changes every `arrangement` digest. A single writer, `mark_representation_only_nodes`, runs once before completion. It marks a node that has degree 2, plain edges (no hard/rail/curve/singularity), no hard barrier, and that **both** incident cells cross on the same logical side. Consumers: parity count, descriptor sides, and the patch boundary. The prototype diff (variant C below, 256 lines, SHA-256 `bcc260b4…`) is kept as Review evidence in [`Architecture_M6_CP3_DEFN_P13_Representation_Breakpoint_Prototype_FALSIFIED.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Representation_Breakpoint_Prototype_FALSIFIED.diff"). **Do not apply it.**

| Variant | Odd cells / parity splits | Vase terminal |
|---|---|---|
| baseline (CB99) | 5,931 / 9,079 | `AggregateCompletionValidationFailure`, 67,750 quads |
| A: all consumers, including side repair | 301 / 490 | `PreparationRejected` `SideSubdivisionRepair:MissingSideSubdivisionEdge` (offset defect) |
| B: parity and descriptor only | 301 / 490 | `PatchCompletionRejected`, patch 5604 (L hexagon, reflex node 28849), transition-template bow-tie |
| C: B, with marks only between two convex cells | 5,865 / 8,717 | `PatchCompletionRejected`, patch 8265 (sliver 0.016 × 3.3e-5), closed-form source-orientation mismatch; asymmetric marks inside one cell plus a misaligned parity insert |

In all variants the Plane/MultiFaceSeam/CloseSheets/Cylinder/BunnyRandom digests stay byte-identical once the flag is in padding. Those fixtures have no representation side vertices: each arrangement cell becomes one quad (65→64, 65→64, 202→200, 290→288).

**Conclusion:** n1 cannot land alone. It turns Vase from a produced, D1-like mesh into no mesh at all. It has to land with n2 (reflex corners) and an n3 decision (slivers), and its side-repair consumer needs wrap-correct side attribution.

## 5. CB100 — evaluator concave-quad metrics (exact)

- **Patch:** [`Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff"), SHA-256 `d55589c799776ee8449fb4eff6a037a80b228c0d64df6299edc7ab654f9638cb`, 79 lines. Keep its 2 single-space context lines.
- **Numstat and post-image SHA-256:**
  - `15 2` `src/geometry/SurfaceMeshOptimizer.cpp` → `8798fa013a9636d5892109c44ab9e50280881176230caa30c18cf1ba913490ec`
  - `26 0` `tests/SurfaceMeshOptimizerPhase21Tests.cpp` → `6a6d600473fe7300d74b1b414fdac50ee5117a36bc30b6110c526b9e9ece8589`
- **Precheck:** `git diff --quiet 553932b04fb433b560e24c59d23751f70f7f2c3e HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Change:**
  - The interior angle is `360 − unsigned` where the signed corner is negative.
  - Warpage uses only diagonals that lie inside the quad: 0–2 needs corners 1 and 3 positive, 1–3 needs corners 0 and 2 positive. It falls back to both diagonals when neither or both qualify.
  - Convex quads keep identical bits, and `convex` and `signedScaledJacobian` are unchanged.
  - Every decision consumer (optimizer acceptance at `SurfaceMeshOptimizer.cpp:1816`, the pipeline refined pair at `RemeshPipeline.cpp:11519`) requires `convex` first, so only reported metrics change.
- **Test:** `SurfaceMeshOptimizerPhase21.ConcaveQuadReportsItsReflexAngleAndInteriorDiagonalWarpage`:
  - WIP counterexample `[(0,0),(2,0),(0.5,0.5),(0,2)]`: max angle 180+atan2(4,3)°, min 18.4349°, warpage 0, SJ −0.8;
  - lifted convex control.
  - It fails on the legacy body.
- **Scratch verification (macOS, -j2):**
  - the chain applies to a clean HEAD worktree and reproduces the tested tree byte for byte;
  - validation target: 88 PASS, plus the 9 failures that are ledger v5 off-gate rows 373/375/385/390/399/401/406/407/408, identical to baseline;
  - no new warnings;
  - all six acceptance fixtures have byte-identical digests (Vase: `completion` unchanged);
  - Vase report: angle P95 180 → 180.972, max 180 → 359.925, warpage P95/max 156.27/180 → 80.32/179.07; nonConvex 16,812, SJ min −1, aspect and size unchanged.
  - **Local 907-row gate (TB85 manifest):** 906/907. The only red is row 283, the known macOS-only O16 (same as RA-210). Rows 795/796/797/864 and GUARD 907 pass.

## 6. TB85

- **Manifest:** [`Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv"), 907 rows, SHA-256 `6ee8495981ae5f8fe3475ae6593c9063030c36bd76b6ceed50a5fded6cd0afbd`. It is TB84's 906 rows plus GUARD 907 (`ra211:evaluator-concave-quad-metrics`, validation binary). `SELF_CHECK_PASS cases=907 deferred=81`; membership **988**.
- **Pinned:** gate rows 795/796/797/864 and the Cylinder/BunnyRandom census `platform-digest` lines byte-identical to TB84. The Vase line is byte-identical to TB84 (`completion=946b59dbe8279a65/67750`, `validationIssues=0`), terminal `AggregateCompletionValidationFailure`. The Vase metric values are a macOS Review observation, not a pin.
- **Routes:** mismatch → `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-REV` (Review, Claude, scratch build); infrastructure → `M6-CP3-TB85A-P13-CONCAVE-QUALITY-METRICS-ORCH`.
- **Local scratch gate:** 906/907; only row 283 (O16, macOS) is red.

## 7. Next Review — `M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY` (P13-n1/n2/n3, Claude, scratch)

The Review must deliver one combined prototype in which Vase completes (no `PatchCompletionRejected`) and the §2 census improves. It then freezes the result as narrow exact CBs, each independently testable:

1. **Representation flag and single writer, no consumers.** Zero behaviour change; the digests prove it.
2. **Wrap-correct side attribution in side repair.** A latent fix; zero change on the fixtures.
3. **Reflex turns.** Signed turns in the descriptor, plus reflex-corner completion (or an upstream strand fix if the census shows that L-corners come from layout outlines).
4. **Semantic counts in all three writers.**

Falsifiers:
- Plane/MultiFaceSeam/CloseSheets/Cylinder/BunnyRandom digests are byte-identical.
- A unit test on `unit_square_two_triangles` with traces at 0.2/0.7 shows the middle cell going from raw counts {1,2,2,1} to semantic {1,1,1,1}, with junctions and a hard trace's crossing protected.
- Vase valence-2 and >170° counts fall, and no new strict issue appears.

Probe block (scratch only):
```
PROBE_SIDES=<dir>: retained run → nodes.tsv, halfedges.tsv, sides.tsv (per descriptor side:
cell, admissible, reason, singularities, side, family, count, hard, rails, curves, boundaryVertices, halfedges),
vlin.tsv (outputVertex, sourcePatch, localVertex, stitchKind, kind), qlin.tsv (outputQuad, sourcePatch,
backend, localQuad, variant, boundaryOnly), provenance.tsv, source/pre/post matrices, plus repair diagnostics.
```

## 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 54 — NEXT | `M6-CP3-CB100-P13-EVALUATOR-CONCAVE-QUAD-METRICS` | implementation agent, compile only |
| 55 | `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-EXEC` | implementation agent |
| 56 | `M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY` (P13-n1/n2/n3) | Claude Review, scratch |
| then | P13-e, O31, O32e → d → b/c, O33; P13 re-census → matrix → CP3-REV | as before |

CP2 491/491, stable 66/17/49, debt 1, ledger v5 (81 deferred) unchanged; selector497 and CP3 unpromoted.

## Closeout

**Mine to own:** RA-210.4 asserted that A3 owned side subdivision counts, framing this as "A3 vs completion". The census shows the arrangement path never consumes A3. The P13 owner is the local count model, and A3 binding is CP3 promotion work.
