# RA-212 — Adversarial review of RA-211: Vase runs on the legacy fallback, its layout is relief-seeded and 20× too dense, CB100 is revised and CB101 added (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY`, re-entered to review [RA-211](Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Census_Adjudication_20261108.md) for completeness and accuracy. Claude scratch track, product sources = CB99.

**Disposition:**
- RA-211's census counts stand.
- Its owner model, its falsifiers, its CB100 and its next Review do not.
- **CB100 is superseded** before application by a revised exact patch, and **CB101** is added.
- TB85 grows to 908 rows.
- RA-211's next Review (`M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY`) is **withdrawn**. The next Review is `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH`.

## 1. What stands in RA-211

- **The §2 census**, re-run here with a byte-identical digest:
  - 26,373 quads have a >170° corner;
  - the worst corner sits on a representation vertex for 90.2% of them;
  - all 4,463 valence-2 vertices are representation nodes;
  - parity repair makes 9,079 insertions (5,931 raw-odd cells against 301 semantic);
  - the descriptor turn sign is hard-coded.
- **The latent `side_halfedges` wrap defect.**
- **The fact** that every prototype variant rejects Vase.

## 2. What RA-211 got wrong (mine to own)

1. **It never compared cell size with the target.**
   - Vase's metric target has mean 0.0883 and range 0.0335–0.1006; the base is 0.05 × bbox diagonal 2.012.
   - Output edges have median **0.00434** and P95 0.0172.
   - The final report's size ratio is **P5 0.0035, P95 0.200**, against the gate's P5 ≥ 0.5. The four passing fixtures sit at 0.53–1.31.
   - About 172–225 target-size quads would cover Vase; it has **67,750**. The layout is about 20× too dense, linearly. RA-211 even noted "~28 quads per source triangle" without asking why.
2. **It missed the cause of that density.**
   - Vase's 1,416 tracing seeds are **1,131 `ReliefCritical`**, 284 `Boundary`, 1 `Singularity` and 0 `AdaptiveFarthest`. Each seed emits four traces whatever the spacing.
   - Relief seeding appears **nowhere in DESIGN**, and its tests are in the optional guidance target.
   - **Scratch probe** (env-gated, withholding the three relief seed inputs; the relief barrier edges are kept):

     | | Current | No relief seeds |
     |---|---|---|
     | seeds | 1,416 | 380 (95 adaptive coverage seeds at target spacing) |
     | traces / strands | 5,664 / 30,989 | 1,520 / 5,327 |
     | **arrangement cells** | 26,817 | **1,184** |
     | odd cells / parity splits | 5,931 / 9,079 | 255 / 0 |
     | Vase run | ~4 min | 51 s |

     The run stops earlier, at `BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node; AlternativeRepairBudgetExhausted (447/447)`.
   - O31 (RA-204.6, "relief critical points decided by rounding noise") was recorded as having "no effect on completed topology", but that was measured only on the four gate fixtures, which have no tracing seeds. On Vase it is the dominant upstream driver of P13-n.
3. **It missed that Vase is the only census fixture on the legacy fallback.** `RemeshPipeline.cpp` calls the arrangement → descriptor → completion path "the legacy tracing fallback", allowed only when every A4 phase-front producer returns NotApplicable.
   - **Phase-front disposition (scratch):** Plane, MultiFaceSeam, CloseSheets and Cylinder are **`Produced` by the phase front** (A3-consuming A4). Vase is **`NotApplicable`, with no reason published.** BunnyRandom stops earlier, at the atlas (P13-e).
   - Consequently **RA-211's falsifier "five fixture digests byte-identical" was vacuous** for every legacy-completion change. Those fixtures never call `complete_surface_cell_complex`. RA-211 §4 also overclaimed it ("in all variants"): after the padding fix only Plane and Cylinder were run, under variant B.
4. **It mis-owned P13-n2.**
   - `PureQuadPatch::turns` has **no behavioural consumer**: only `turns_are_valid` (|t| ≤ 1) and the completion cache key read it. Signing the turns changes nothing.
   - All 2,232 reflex-corner bad quads come from boundary-only backends: BoundedCombinatorial 1,279, Pattern 886, TransitionTemplate 67.
   - The real owner is completion's patch model. It counts a reflex corner as an ordinary side change, picks templates by side count, and accepts a simple concave quad at a 270° boundary corner.
5. **It missed a forbidden second writer.** Completion parity repair inserted **121 breakpoints on hard rails** (`railId` + `hardFeature`) and 35 on singularity-support edges. DESIGN §7.4: producers "may not insert, remove, quantize, or reorder shared breakpoints"; rail breakpoints are A3's. RA-211's plan ("semantic counts in all three writers") would have hardened this writer.
6. **CB100 was incomplete and used the wrong reference.**
   - **Incomplete:** `normalP95` in the final report uses `face_normal`, the **first-triangle** normal of corners 0–2. On the 7,690 Vase quads whose corner 1 is reflex it flips. Report: **121.56°**. Whole-quad (Newell) normal: **P95 5.91°** (scratch analysis), **3.74°** as the patched evaluator reports it. Zero quads are more than 90° off. The `normalP95 ≤ 15°` gate was failing **purely as a measurement artifact**, RA-208's exact defect class.
   - **Wrong reference:** CB100 took reflex corners against the **source** normal. The validator (CB98 `quad_fan_corner`) uses the quad's own Newell normal, so there were two definitions in A8 (§9). On a quad listed clockwise (inverted), CB100 reports 341.6° and 126.9° for the angle extrema and 180° warpage on a planar quad. The revised test fails on the frozen CB100 at lines 188/190/191.
7. **It gave an imprecise reason for not landing n1.** "Turns a produced, D1-like mesh into no mesh at all" is wrong. Vase is already `NotProductionReady` with no product. The regression is an earlier, structural terminal (an invalid quad embedding) in place of a post-completion quality failure: it loses the CB97–CB99 `validationIssues=0` evidence.
8. **It cited DESIGN loosely.** §6.2 is about semantic *identity*, and §10.1 about row permutation; neither forbids a geometric vertex. The applicable clauses are the §5 A4 row ("cells conform exactly to the supplied plan; no shared decision is recomputed") and §7.4. The fallback as a whole is outside DESIGN.
9. **It attributed only the angle gates.** After CB100 (revised) and CB101, Vase fails these gates:

   | Gate | Vase |
   |---|---|
   | field P95 (≤ 15) | 36.4 |
   | size P5 (≥ 0.5) | 0.0035 |
   | angle P5 / P95 | 6.46 / 180.8 |
   | warpage P95 / max | 81.6 / 166.2 |
   | aspect P95 / P99 | 60.7 / 286.6 |
   | SJ min / P5 | −1 / −0.013 |
   | nonConvex | 16,812 |
   | boundary-valence mismatches | 248 |
   | singularity-valence mismatch | 1 |

   Only `normalP95` (3.74) newly passes. Field, size, aspect, boundary valence and singularity valence were never attributed.

## 3. Realignment

- **DESIGN's production path for Vase is the A4 phase-front producer.** It consumes A3 and already produces four of six census fixtures. The legacy fallback is a transitional contract: DESIGN's branch decision deletes a displaced contract at cutover. Its seeding (relief), its layout density and its local parity T-join (writing on rails) are all outside DESIGN.
- **RA-211's step 56 is withdrawn.** Tuning the fallback's count model on a noise-seeded layout 20× denser than target optimizes a configuration that the seeding fix replaces. The P13-n1/n2/n3 measurements stay on record as properties of that configuration, not as frozen work.
- **Next Review: `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH`** (Claude, scratch), in this order:
  1. **Observability:** why each A4 producer (uniform, periodic annulus, curved bounded disk) returns NotApplicable for each Vase region. Today the run publishes `NotApplicable` with no reason. Freeze a narrow diagnostic CB if the reason is not already retained.
  2. **Decision with evidence:**
     - **(a)** extend A4 phase-front coverage to Vase's regions (DESIGN-conformant; A3 owns every shared breakpoint); or
     - **(b)** keep the fallback for P13. In that case:
       - seeding density comes first: relief seeds outside DESIGN, O31 promoted from a determinism item to the P13-n root;
       - re-census at target density, where parity repair failing (255 odd cells) is the first terminal;
       - then n1/n2/n3 only as they recur there;
       - parity repair may not write rail breakpoints.
  3. **Attribute every failing gate** in §2.9, including the field P95, boundary valence and singularity valence.
- **Falsifiers** for any fallback change must run on Vase's legacy path or on legacy unit fixtures, never only the phase-front fixtures.

## 4. CB100 (revised) — evaluator interior angles and warpage in the quad's own plane (exact)

- **Patch:** [`Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff`](Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff), SHA-256 **`8c11fb8541b5dc799f66a5ac8ea325b1e7045b8b50b93ecc6f8689ec92e947a7`**, 114 lines. Keep its 4 single-space context lines. It **supersedes** `d55589c7…` (RA-211.5), which was never applied.
- **Numstat and post-image SHA-256:**
  - `29 2` `src/geometry/SurfaceMeshOptimizer.cpp` → `a0f816b3bc96050ab2c7a68189001e88d22b2a56335befb4e4893b3d456107c0`
  - `39 0` `tests/SurfaceMeshOptimizerPhase21Tests.cpp` → `6104b59ba09a74045b5b9b4ba3a8c811b8424addc36da338bbab8bb0374537fe`
- **Precheck:** `git diff --quiet 553932b04fb433b560e24c59d23751f70f7f2c3e HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Change:**
  - A local `quad_normal` wraps the validator's `source_authoritative_detail::polygon_normal`, one shared definition (§9).
  - A corner is reflex when its turn is negative about the quad's own normal; its angle is then `360 − unsigned`.
  - A diagonal is inside when both corners off it are convex in that plane; warpage uses only inside diagonals and falls back to both diagonals when neither or both qualify.
  - `convex` and `signedScaledJacobian` stay measured against the source normal.
  - Convex quads, in either orientation, keep identical bits.
- **Test** `ConcaveQuadReportsItsReflexAngleAndInteriorDiagonalWarpage`:
  - the counterexample (233.13° / 18.43° / warpage 0 / SJ −0.8);
  - **the same quad clockwise** (same angles and warpage);
  - a lifted convex control.
  - It fails on the legacy body and on the superseded CB100.

## 5. CB101 — report normal error in the quad's own plane (exact)

- **Patch:** [`Architecture_M6_CP3_CB101_P13_Evaluator_Quad_Normal_Own_Plane.diff`](Architecture_M6_CP3_CB101_P13_Evaluator_Quad_Normal_Own_Plane.diff), SHA-256 **`9b42498d9e3615488c9007499aea590c195d472b66e519c67d5ff124190155f1`**, 56 lines. Keep its 1 single-space context line.
- **Precheck:** the CB100 post-images above.
- **Numstat and post-image SHA-256:**
  - `2 2` `src/geometry/SurfaceMeshOptimizer.cpp` → `ac441cd36be7bec02903f5c35baa85ba0f171022012457b892f99c3707793384`
  - `23 0` `tests/SurfaceMeshOptimizerPhase21Tests.cpp` → `0362e0bd636e89543d403812c39cc96602e0fb05cb642c8c1f7366f333e0dfba`
- **Change:** `validate_final_surface_mesh` normal errors and the diagnostic overlay use `quad_normal` instead of `face_normal`. The optimizer's normal energy (`face_normal`, line 1519) is deliberately unchanged, because changing it would change optimization.
- **Test** `NormalErrorOfAConcaveQuadDoesNotDependOnItsFirstCorner`: a planar concave quad with reflex corner 1 must report `normalP95Degrees ≈ 0` and `nonConvex == 1`. It fails without CB101.
- **Effect:** `normalP95` feeds a gate. A mesh whose only failing gate was this artifact would now pass it; any such mesh still fails `nonConvex == 0`.

## 6. Scratch verification of CB100 (revised) + CB101

- The chain applies in sequence to a clean HEAD worktree and reproduces the tested tree byte for byte.
- **Validation target:** 89 PASS, plus the 9 ledger-v5 off-gate failures (rows 373/375/385/390/399/401/406/407/408), the same set as the baseline.
- **Digests:** all six acceptance fixtures are byte-identical to the baseline, Vase's whole line included (`validation=` hashes counts and flags, not angles, warpage or normal). The four fixtures report normal P95 0 under both normals.
- **Vase report:** normal P95 121.56 → **3.74**; angle P95 180 → 180.77; max angle 180 → 332.46; warpage P95/max 156.3/180 → 81.6/166.2. nonConvex, SJ, aspect and size are unchanged.
- **Local 908-row gate (revised TB85 manifest):** 907/908. The only red is row 283, the known macOS-only O16. Rows 795/796/797/864 and GUARD 907/908 pass. No compiler warnings in the changed units.

## 7. TB85 (revised)

- **Manifest:** [`Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv), **908 rows**, SHA-256 **`ec088eb1121a5846605a4bb3675657b68477c88513c28795350369c03bb9f999`**. It is TB84's 906 rows plus GUARD 907 (CB100 test) and GUARD 908 (CB101 test). `SELF_CHECK_PASS cases=908 deferred=81`; membership **989**. It supersedes the 907-row `6ee84959…`.
- **Pins:** rows 795/796/797/864 and the Cylinder, BunnyRandom and Vase census digest lines byte-identical to TB84 (Vase `completion=946b59dbe8279a65/67750`, `validationIssues=0`, terminal `AggregateCompletionValidationFailure`).
- **Routes:** mismatch → `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-REV` (Review, Claude, scratch build); infrastructure → `M6-CP3-TB85A-P13-CONCAVE-QUALITY-METRICS-ORCH`.

## 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 54 — NEXT | `M6-CP3-CB100-P13-EVALUATOR-CONCAVE-QUAD-METRICS` (revised `8c11fb85…`) | implementation agent, compile only |
| 55 | `M6-CP3-CB101-P13-EVALUATOR-QUAD-NORMAL-OWN-PLANE` (`9b42498d…`) | implementation agent, compile only |
| 56 | `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-EXEC` (908 rows) | implementation agent |
| 57 | `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` (§3) | Claude Review, scratch |
| then | P13-e; O32e → d → b/c; O33; P13 re-census → matrix → CP3-REV | as before. O31 is absorbed into step 57 for Vase; its determinism falsifier stays. |

RA-211's step 56 (`SEMANTIC-PATCH-BOUNDARY`) is withdrawn. CP2 491/491, stable 66/17/49, debt 1 and ledger v5 are unchanged; selector497 and CP3 are unpromoted.

## Closeout

Mine to own: items 1–9 above. The most consequential are not checking density against the metric, and treating the phase-front fixtures as falsifiers for legacy-path changes.
