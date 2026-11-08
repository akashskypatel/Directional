# A4/A2b Review — Source-attached Vase quad geometry and surrogate-disc ownership probe

**Canonical turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (Review, not complete). **Immutable source** `c54184c3caab9dfd37eab6653ae923e0a5c733e9`, workflow snapshot 42452191280; snapshot archive SHA-256 `b3746075d3ee05776a960023a3fa5c74290dfa6810756452bb42f3c1f88ced6a`. Source `benchmarks/fixtures/milestone-g/vase.off` SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`. This is an independent Python Review scratch, **not** C++ build evidence, a real A2a′/A2b/A3 product, or an A4 acceptance test. Keep [RA-213](Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md), the [production-contract audit](Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md) and the [chain metric falsifier](Architecture_M6_CP3_DEFN_P13_A4_A2b_Chain_Segmentation_Falsifier_20261108.md) as governing work.

## S1 — Constructive source-face-attached all-quad geometry, globally

An independent script constructs three quads per existing planar source triangle using exact *source identities*: unchanged source vertices, one globally shared point at each source-edge midpoint, and one centroid per source face. Every quad lies in its owning source triangle; no position-tolerance welding is used. The script reads only the immutable fixture and writes a result JSON. The independent checks assert each edge has one/two owners, reciprocal direction for two-owner edges, correct boundary vertex link paths and interior cycles, signed local convexity, face-area conservation, connected links, Euler characteristic and a negative face reversal.

| Check/measurement | Observed |
|---|---:|
| Input vertices / triangles / edges / boundary | 1,274 / 2,404 / 3,677 / 142 |
| Output V / E / all-quad F | **7,355 / 14,566 / 7,212** |
| Euler characteristic | **1** |
| Output exterior boundary edges | **284** |
| Validated vertex links | **7,355** |
| Input / output surface area | **1.743718360695658 / 1.7437183606956543** |
| Relative area disagreement | **2.16 × 10⁻¹⁵** |
| Local convex corner / reciprocal edge ownership failures | **0 / 0** |
| Minimum / maximum corner angle | **23.09° / 160.54°** |
| Median / P95 maximum-to-minimum quad edge ratio | **2.113 / 3.022** |
| Full surface mesh interior / boundary valence index | **+152 / −148**, total **+4** |
| Deliberately reversed quad | **rejected** |

**Important valence accounting correction:** The initial local scratch index assertion failed because it erroneously used number of incident *quads* as boundary **edge valence**. At boundary vertices, edge valence is incident-quad count **plus one**; the corrected independent edge-valence index passes, as do all other checks. The failed first run is **not** a verified result; the correction and rerun are in the attached script. This was a scratch-code defect, not a finding against product.

**Quality:** The output has 284 exterior edges versus RA-213's real A3 outer-edge schedule **164** (120 excess); its 7,212 quads are **32.25×** the purely area/mean-target-size estimate `1.74371836 / 0.0883² ≈ 223.64`. Hence source attachment and local convexity alone do not solve A3 conformance or density. Field alignment, source-face intersections, global nonlocal collisions, prescribed valence, and A5–A8 quality acceptance are **not evaluated**. This is a constructive **negative** for adopting face-local barycentric refinement as the production A4 solution.

## S2 — Three *surrogate* source-edge discs on the actual Vase surface

To independently exercise disc membership without inventing an A2a′ certificate, a separate script finds three vertex-disjoint (except the source-vertex 357 center) shortest paths along original source **edges**, to arbitrarily selected rim vertices **0, 849, 567**. These are **not** the three real field separatrices, whose source-face-interior support is unknown to this scratch. Path lengths are 25, 27, 18 original edges. Removing the 70 path edges from triangle-to-triangle adjacency partitions the actual 2,404 source triangles into exactly **three** components; each has `χ=1`, one simple connected boundary loop and no open endpoints. Exact source-face memberships, every path, and the chosen rim endpoints are preserved in attached JSON.

| Surrogate region | Source triangles | Cut-domain boundary source edges | Quad faces after face-local refinement | Quad boundary edges | Incident quads at center |
|---|---:|---:|---:|---:|---:|
| 0 | 915 | 99 | 2,745 | 198 | 2 |
| 1 | 843 | 91 | 2,529 | 182 | 3 |
| 2 | 646 | 92 | 1,938 | 184 | 1 |

Cross-region source topological identity is checked by an **independent** consumer: every original cut edge has its canonical globally shared midpoint and two subedges consumed by the two adjacent regions with reversed directed incidence; every exterior source edge has exactly one owner on each of its two subdivided subedges. The 70 cut edges become exactly **140** shared trace subedges. Negative controls are distinctive: reversed quad → `orientation`, removed exterior quad → `outer coverage`, midpoint alias on one trace side → `trace coverage`. These controls reject intentional corruption; they are synthetic, not production-test additions.

**Port-valence falsifier:** At source vertex **357**, the local barycentric fan gives `2+3+1=6` incident quads globally, not the required valence **3** for the +¼ field singularity. Source-attached three-disc topology alone does not deliver the port-corner condition. Exact A2b discs could have different boundaries from these surrogates. Further, their 140 shared subedges do not equal the actual A3 trace subdivisons `10+4+9=23`. This experiment **cannot** replace the real producer prototype.

## Exact next missing evidence and non-authorization

1. Obtain the actual oriented A2b region boundary occurrences and all 3 Trace arcs, including A2a′ source-face-fragment ownership, trace segments, and source-sheet identities; **not** surrogate source-edge paths.
2. Obtain the actual original A3 schedule with complete support pieces, exact endpoint/breakpoint descriptors, target-size field and incidence ownership, then run an independently verified maximal-Mandatory-chain candidate. The existing one-positive-span-per-arc contract requires an explicit redesign and cannot be bypassed by coalescing counts.
3. Construct one real source-face-fragment A4 disc, carry exact A3 breaks and port-corner placement, and verify region-local and shared-trace topology, geometric injectivity, prescribed field valence, A5–A8 and the size/quality gates. Do not use the present face-fan's `6` as a passing central port.
4. Record whether Vase's expected D1 `QualityRelaxed` tier is approved by the user before changing any quality gate or acceptance authority. No approval is inferred.

No source/test/fixture/selector/benchmark/build/workflow files were mutated; no C++ compile or runtime benchmark executed. CB102 remains withdrawn; no successor Code+Build turn is frozen. This evidence discharges a limited constructive **source-attached geometry** question only; the canonical Review remains **IN_PROGRESS**.

**Reproducible chat artifacts** (SHA-256):
- `Directional_Vase_Source_Attached_Quad_Scratch_20261108.py` — `6b88e59974537e686917918e0133c9b8bf47fe61d5665bc09f17c93c1684b8d7`
- `Directional_Vase_Surrogate_Disc_Cut_Scratch_20261108.py` — `df918f92277edf2676b307e4a728caabaf3fd0f6c5494c108007562a40f7c809`
- `Directional_Vase_Surrogate_Trace_Ownership_Scratch_20261108.py` — `2ab4a22353cbc15c018ddd3d34f60f0bd97b1b5c856d8a8f34b085e25625a5c1`