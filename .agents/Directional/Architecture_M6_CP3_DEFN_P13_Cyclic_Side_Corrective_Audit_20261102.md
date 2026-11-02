# P13 cyclic side indexing — corrective Review audit (2026-11-02)

**Owning turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. This is independent scratch evidence, not a production/test change or CB/TB acceptance record.

## Prior evidence correction

The archived `p13_geometry_observations.json` and `p13_sliver_geometry.py` from scratch Vase evidence `directional-p13-sliver-nine-cell-review-evidence.zip` (SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`) had **incorrect side assignment for seven of nine cells**. The raw nine-cell source-provenance inventory and 9/9 directed-cycle/arc/node receipt remain valid **within their original checker's narrower scope**.

**Cause:** `src/geometry/SurfaceArrangement.cpp:6500–6534` constructs `sideEdgeCounts` by merging a continuous final logical side with the first side, but does not rotate `cell.halfedges` to this merged side's start. The scratch probe inferred `P13_HALFEDGE ... side=` by partitioning `cell.halfedges` directly from zero. The geometric summary then used those incorrectly inferred labels to group segments. This was a **diagnostic analysis bug**, not demonstrated to be a product bug. `PatchDescriptor.cpp:220+` independently reconstructs sides and CB76 explicitly reanchors the patch boundary to its first side.

An independent Python audit matched each recorded cyclic family/count sequence against the physical ordered halfedge family sequence, requiring the first actual halfedge to belong to logical side 0. The match was unique for all nine cells and reduced **24 misassigned halfedge family labels to zero**. Recomputed distances remain **Euclidean lower bounds only**, not intrinsic geodesic distances. Existing local-tip field/rail chord angles do not depend on the side group labels and were not invalidated by this correction.

| Cell | Side-zero start (physical halfedge offset) | Corrected side lengths in cyclic logical order |
|---|---:|---|
| 6095 | 0 | 0.0000807322, 0.0404730743, 0.0000774215, 0.0404739386 |
| 20533 | 5 | 0.00828979368, 0.00000881780, 0.00828987697, 0.00000879191 |
| 20968 | 7 | 0.0343890130, 0.0002115719, 0.0343866634, 0.0002076528 |
| 22350 | 7 | 0.0323743364, 0.0008902854, 0.0323569349, 0.0008887559 |
| 26735 | 4 | 0.0394434000, 0.0394775838 |
| 26764 | 4 | 0.0483646978, 0.0483625639 |
| 26781 | 0 | 0.0362449274, 0.0366260169 |
| 26802 | 3 | 0.0401296925, 0.0411925739 |
| 26812 | 4 | 0.0308496781, 0.0310742718 |

Corrected rail lens sides are respectively a 3-edge field trace plus a 2-edge protected rail, or its cyclic reverse, at **the raw arrangement stage**. RA-197's later **descriptors** with 6 boundary vertices and 3+3 splits are downstream-stage statements, so this does not, by itself, falsify those descriptor observations. The earlier mixed-side lengths reported for lenses, e.g. 26735 approximately 0.005 versus 0.074, are **retracted**.

## Ownership finding and exact remaining discriminator

All nine directed cell boundaries are linked to retained source arcs, not fabricated by pure-quad completion. Needle four-sided cells span distinct layout/proposal strands; rail lenses contain a field-trace side and a mandatory hard rail. Existing source `DESIGN.md` §4.5 defines **exact shared-edge grazing transit**; it does not authorize proximity thresholds that delete near-parallel traces or mandatory hard rails. The observed near-parallelism is not proof of an invalid upstream trace.

The missing causal discriminator is **complete incident outgoing-ray/wedge identity and expected left-cell successor** at the lens tips versus the actual `SurfaceArrangement.cpp` directed successor. For needles, compare source-authoritative candidate layout/proposal ownership and same-sheet intrinsic separation against the emitted cells. A claim of a single producer owner is premature without this comparison. Do not tune a `Sliver` area epsilon, redefine two-sided lenses as quad-ready, weaken the completion embedding check, or promote CP3.

## Reproduction and boundary

- Independently reverified the existing source snapshot ZIP SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062` and **6,092/6,092** file hashes. Frozen semantic CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72` remains unchanged by later work.
- `p13_cyclic_side_audit.py` SHA-256 `1727d68a103d7444c326af6bb258f62c252a286872e71c813ed7a0be5a574edc`; `p13_cyclic_side_audit.json` SHA-256 `143c2f8dc1add1b8a840f9fc35fd324e68239877c5254c9e998feca42142de56`. User-downloadable archive `P13_CYCLIC_SIDE_AUDIT_EVIDENCE.zip` SHA-256 `83568cce1ea75a2e030a2d07a9aa63b1f2466816674766fc1e99301e63bf1e64` includes both and readable detail.
- No local builds, new runtime probes, source/test/selector edits, workflow permission changes, or acceptance runs during this continuation. An early choice of repo-document connector reads before explicitly freezing `READ_MODE=snapshot` missed the conservation pre-read gate; additional static source analysis used the **existing verified immutable snapshot**, not more piecemeal reads. This process defect does not invalidate independently verified source bytes.
- `review_check.py boundary` on archive-only data cannot establish Git-ancestor-dependent checks; remain **unverified**, never report green. Full Review closeout and successor freeze are pending. Preserve same-turn continuation, accepted CP2 491/491, unpromoted TB70 880/880 and 961 membership, stable 66/17/49 and debt 1.
