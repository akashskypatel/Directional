# P13 cyclic side indexing — corrective Review audit (2026-11-02)

**Owning turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. This is independent scratch evidence, not a production/test change or CB/TB acceptance record.

## Prior evidence correction

The archived `p13_geometry_observations.json` and `p13_sliver_geometry.py` from scratch Vase evidence `directional-p13-sliver-nine-cell-review-evidence.zip` (SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`) had **incorrect side assignment for seven of nine cells**. The raw nine-cell source-provenance inventory and 9/9 directed-cycle/arc/node receipt remain valid **within their original checker's narrower scope**.

**Cause:** `src/geometry/SurfaceArrangement.cpp:6500–6534` constructs `sideEdgeCounts` by merging a continuous final logical side with the first side, but does not rotate `cell.halfedges` to this merged side's start. The scratch probe inferred `P13_HALFEDGE ... side=` by partitioning `cell.halfedges` directly from zero. The geometric summary then used those incorrectly inferred labels to group segments. This was a **diagnostic analysis bug**, not demonstrated to be a product bug. `PatchDescriptor.cpp:220+` independently reconstructs sides and CB76 explicitly reanchors the patch boundary to its first side.

An independent Python audit matched each recorded cyclic family/count sequence against the physical ordered halfedge family sequence, requiring the first actual halfedge to belong to logical side 0. The match was unique for all nine cells and reduced **29 wrong logical-side labels (including 24 family mismatches) to zero**. Recomputed distances remain **Euclidean lower bounds only**, not intrinsic geodesic distances. Existing local-tip field/rail chord angles do not depend on the side group labels and were not invalidated by this correction.

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

**Absolute-area sanity check:** Independently parsed all nine `P13_CELL area=` receipts. The smallest is cell `20533`, `7.292183487273476e-08`; even that exceeds the current `SurfaceArrangement.cpp` `Sliver` threshold `1e-14` by **7,292,183×**. No cell can be classified as a sliver by that present predicate. Increasing the threshold until these cells reject would be an unjustified global behavior change, not causal recovery.

## Ownership finding and exact remaining discriminator

All nine directed cell boundaries are linked to retained source arcs, not fabricated by pure-quad completion. Needle four-sided cells span distinct layout/proposal strands; rail lenses contain a field-trace side and a mandatory hard rail. Existing source `DESIGN.md` §4.5 defines **exact shared-edge grazing transit**; it does not authorize proximity thresholds that delete near-parallel traces or mandatory hard rails. The observed near-parallelism is not proof of an invalid upstream trace.

The missing causal discriminator is **complete incident outgoing-ray/wedge identity and expected left-cell successor** at the lens tips versus the actual `SurfaceArrangement.cpp` directed successor. For needles, compare source-authoritative candidate layout/proposal ownership and same-sheet intrinsic separation against the emitted cells. A claim of a single producer owner is premature without this comparison. Do not tune a `Sliver` area epsilon, redefine two-sided lenses as quad-ready, weaken the completion embedding check, or promote CP3.

**Exact future tip-node probe set:** five lens transition-node pairs in the raw scratch arrangement are `26735: (56813,56385)`, `26764: (16998,47581)`, `26781: (9928,56412)`, `26802: (57415,53651)`, `26812: (57661,23821)`. These were independently extracted as family-change vertices from the directed halfedge cycles. A future scratch-only diagnostic should record every outgoing halfedge from each of these ten nodes, complete source-entity wedge/ray ordering, chosen next and alternative candidates, plus upstream trace/rail admission evidence. Ten node IDs are **not** by themselves a proof that any successor is wrong.

## Additional completion-stage gate audit (same Review, 2026-11-02 13:10Z)

Independently checked the verified source snapshot at `4f48f09562740bcdff78cacb6a9159b0299238a8` (archive SHA-256 `cdbd72e5294c8659e16cb71bde42cdabb8f84765cd750efc2d3e38b2053266b8`, 6,104/6,104 source hashes); semantic CB76 unchanged. These are conditional source-routing proofs, **not** evidence that changing the gates is valid for Vase.

For the five prepared two-logical-side, six-boundary-vertex (3+3) lenses, source contains **three distinct barriers** to reaching the existing dynamic-programming completion:

1. `PureQuadCompletion.cpp:1887–1890`: `check_pure_quad_patch_admissibility` rejects `sides<3` with `SideCountUnsupported` (the observed P13-i class).
2. `PureQuadCompletion.cpp:44–50,1910–1923`: with only that guard hypothetically deleted, `side_inequalities_hold` still returns false for `n<3`, producing `SideInequality`. A one-line side-count change is not a functional fix.
3. `PureQuadCompletion.cpp:2453–2471,2055–2074`: if both guards were altered under a separately established contract, the rectangular grid rejects two sides, but `complete_six_vertex_transition` unconditionally creates two quads for any six-vertex boundary and returns true. That construction result skips `complete_pattern` behind `!completed`; subsequent source-ownership, topology or orientation rejection does not retry DP. The DP is therefore not automatically reached by simply relaxing admission.

The existing abstract hexagon (two sides of three subdivisions) proves only topological possibility. `PatchDescriptor.cpp:1712–1718` supplies two `+1` family turns, not a source-chart transported `Z4` holonomy or field-index certificate. `DESIGN.md` §§4.1, 4.5 and 7.5 retain those obligations. Even boundary parity and simple geometry alone cannot authorize an actual Vase lens.

**Required discriminator:** recover each original support trace terminal and rail interval, chart/sheet identity, protected endpoint/cycle obligations, transported field family and index; independently establish whether any embedded two-side completion preserves mandatory rails and globally valid quad topology. If yes, separately adjudicate a bounded completion capability with all three dispatch barriers and unchanged validators. If not, identify and correct a specific earlier trace/selection admission defect. Positive required-rail-contact and negative invalid-return cases must separate the hypotheses. Neither path is authorized for implementation by this unfinished Review.

## Reproduction and boundary

- Independently reverified the existing source snapshot ZIP SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062` and **6,092/6,092** file hashes. Frozen semantic CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72` remains unchanged by later work.
- `p13_cyclic_side_audit.py` SHA-256 `1727d68a103d7444c326af6bb258f62c252a286872e71c813ed7a0be5a574edc`; `p13_cyclic_side_audit.json` SHA-256 `143c2f8dc1add1b8a840f9fc35fd324e68239877c5254c9e998feca42142de56`. User-downloadable archive `P13_CYCLIC_SIDE_AUDIT_EVIDENCE.zip` SHA-256 `266742ecef9272d0f9b16a1e1e0af1e6afee00002de6470d32ae9c832d4bc88a` includes both and readable detail.
- No local builds, new runtime probes, source/test/selector edits, workflow permission changes, or acceptance runs during this continuation. An early choice of repo-document connector reads before explicitly freezing `READ_MODE=snapshot` missed the conservation pre-read gate; additional static source analysis used the **existing verified immutable snapshot**, not more piecemeal reads. This process defect does not invalidate independently verified source bytes.
- `review_check.py boundary` on archive-only data cannot establish Git-ancestor-dependent checks; remain **unverified**, never report green. Full Review closeout and successor freeze are pending. Preserve same-turn continuation, accepted CP2 491/491, unpromoted TB70 880/880 and 961 membership, stable 66/17/49 and debt 1.
