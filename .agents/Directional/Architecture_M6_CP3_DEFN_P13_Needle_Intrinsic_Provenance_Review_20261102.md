# P13 needle-cell source-provenance and intrinsic-separation review

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. **Date:** 2026-11-02. This is **interim independent Review evidence**, not a completed checkpoint, approved corrective implementation, or formal Test + Benchmark result. No Directional executable, compile, or test was run in this continuation.

## Exact source authority and data

- Frozen CB76 semantic source `f59f92f889fc6fe22d689fd7559c024cd09c6c72`; previously verified snapshot at event/source SHA `898316210ab810daa10d2072db927f9ebe4b2a98`. The existing materialized source snapshot's **6,092/6,092** SHA-256 file checks were revalidated this continuation. GitHub PR #8 remains open/draft; source path comparison from CB76 to this turn's entry head found **no semantic-code change**.
- Reused original archived *scratch* Vase stderr, SHA-256 `e0a28c941bdaf4d86a1a5d0cf23216ac890f266b67d591e2a7c528a00e189530`, collected in the earlier Review-policy-violating runtime turn. **No new runtime evidence was created here.** The original log's nine-cell structural receipt previously passed 9/9; its older `P13_HALFEDGE side=` labels were **incorrect for seven cells** because the arrangement's cyclic side-zero offset was not applied. This review independently reconstructs the cyclic side partition from `P13_SIDE` family/count and the physical directed halfedge sequence, and cross-checks the corrected historical side audit.
- Exact fixture `benchmarks/fixtures/milestone-g/vase.off`, SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`. Every source node used for a width witness was independently checked against its emitted source-face barycentric coordinates and these actual OFF mesh vertices (absolute tolerance 3e-12). The mesh is 1,274 vertices and 2,404 triangles.
- Independently run read-only algorithm `p13_needle_intrinsic_check.py`, SHA-256 `3a4e8c57a3d1b6e77eb3951e535ed52f54ae8e870f4c399fc3b474e8477eb20e`, with JSON receipt `p13_needle_intrinsic_check.json`. The script computes all pairwise finite line-segment distances using constrained quadratic stationary and four boundary candidates; no reliance on the prior four-iteration approximate segment-distance helper for its width proof. Four corrupted-copy negative controls were independently rejected (mesh/barycentric mismatch, missing support-trace identity, proposal/seed mismatch, invalid cyclic side family). The exact source log and input fixture are preserved with the script in a downloadable evidence ZIP. **These are offline verification controls, not product tests.**

## Complete per-side producer attribution

The proposal authority is `src/geometry/FlowRepStrands.cpp:515-562,782-804`: `build_flow_rep_arcs_from_network` assigns a retained accepted proposal's `proposalId`, `proposalSeedId`, `proposalSide`, and `proposalBoundarySegment` and gives its strand the proposal ID. Anchored support segments instead have `proposalId=-1`, `layoutSupport=true`, `supportTraceId` and `strandProvenance=-2-supportTraceId` (`FlowRepStrands.cpp:610-730`). `RemeshPipeline.cpp:11040-11107` carries this provenance into arrangement arcs. Therefore positive and negative strand IDs have **different source producers**, not interchangeable proposal identities.

| Cell | Side 0 | Side 1 | Side 2 | Side 3 | Observed boundary class |
|---|---|---|---|---|---|
| 6095 | Proposal 393 (short) | Proposal 300 (long) | Proposal 526 (short) | Proposal 524 (long) | Four independent proposal-owned sides |
| 20533 | Proposal 1229 (long) | Proposal 1221 (short) | Proposal 1222 (long) | Proposal 640 (short) | Four independent proposal-owned sides |
| 20968 | **Support trace 815 (long)** | Proposal 1078 (short) | **Same support trace 815 (long)** | Proposal 465 (short) | Two disjoint portions of **one retained support path** form both long boundaries |
| 22350 | Proposal 488 (long) | Proposal 1061 (short) | **Support trace 487 (long)** | Proposal 784 (short) | One proposal versus one support trace |

The earlier generic description of all needles as seed-proposal corridors was imprecise: cells 20968 and 22350 have explicit support-trace boundary segments, and cell 20968 has the *same* support-trace ID on opposite sides. In 20968, the two retained long-side FlowRep arc groups are IDs `[2425,2426,2427]` and `[2436,2437,2438]`, both strand `-817` = trace `815`. This proves a repeated nearby **path segment pair** of one producer; it does **not** alone prove the trace is geometrically invalid or that the source path self-intersects.

## Certified intrinsic minimum separation, not merely Euclidean thickness

For two opposite long-side polylines on the triangulated *source surface*, define their closest ambient Euclidean distance `d_E`. Every source-surface path between them has length at least `d_E`. If the finite-segment minimizer lies on two segments supported by **the same source face**, the straight chord between those closest points lies in that convex triangle, giving a same-sheet intrinsic path of length `d_E`. Thus `d_E ≤ d_intrinsic ≤ d_triangle = d_E`, proving the *minimum source-surface intrinsic distance between those two polylines* to floating-point precision; no across-fold shortcut is used.

All four cells admit such independently verified source-face chords:

| Cell | Opposing long sides | Shared source face witness | Shortest source-surface intrinsic separation | Mean long-side / mean short-side boundary length |
|---|---|---:|---:|---:|
| 6095 | 1 / 3 | 2108 | `0.0000774214542302` | 511.83 |
| 20533 | 0 / 2 | 2005 | `0.00000879190921228` | 941.51 |
| 20968 | 0 / 2 | 2244 | `0.000207652829757` | 164.05 |
| 22350 | 0 / 2 | 174 | `0.000881265487687` | 36.39 |

The global ambient minimum and best valid same-face path length matched to the displayed numerical precision in **4/4** cases (0.0 numerical gap at double precision). The same four source-face witnesses were **independently cross-checked with Shapely in local 2D triangle coordinates**, not the constrained 3D solver: the largest absolute disagreement was **4.77e-17** (`p13_needle_independent_planar_check.py` / `.json`). The result certifies shortest *source-surface set-to-set separation*, **not** a geodesic constrained to the cell interior, source-chart transported field matching, a required target-size clearance, or whether any particular narrow quad is semantically prohibited. The aspect measure is a **boundary-length ratio**, not a ratio to target size or acceptance threshold. In particular, an admissible-but-poorly-conditioned source patch could share these measurements.

## Correct corrective owner boundary and falsifiers

1. Cells **6095 and 20533**: four distinct accepted proposal-side producers meet in narrow, source-face-real corridors. Review the accepted-proposal admission and cross-proposal compatibility/overlap contract and the retained FlowRep selection of their side segments; there is no basis yet for blaming one specific proposal or the directed-wedge resolver. Do not invent a universal minimum-width rejection rule.
2. Cell **20968**: one support trace supplies both parallel opposing long sides, while two accepted proposals close the short ends. The narrowness is intrinsic, so investigate the *same-trace return/near-self-approach* contract and cycle/anchor constraints before proposing to remove any segment. This is a different producer configuration from the two all-proposal cells.
3. Cell **22350**: proposal 488 opposes support trace 487. Investigate support-versus-proposal compatibility and the endpoint/coverage/cycle obligations of that particular support; it is not the same-trace-two-sides configuration of 20968.
4. Five hard-rail lens cells are **separate**: earlier independent analysis proved an original rail-vertex protected-degree deletion veto for five optional support traces, but did not prove removal is safe or uniquely determine the transaction rejection. The needle cells have **no hard rails**, so that protected-rail veto is not a universal nine-cell fix.
5. P13-e BunnyRandom RED, O23 and accepted-green authority remain separate. No downstream completion epsilon, arbitrary trace suppression, global protected-degree relaxation, accepted selector change, or CP3 promotion is authorized by this review.

**Falsifiers for next bounded Review work:** compare actual proposal-admission versus full arrangement ownership for the two all-proposal cells; establish if same-trace return 815 is intended and permissible, and if trace 487 is required by cycle or coverage; derive source-sheet-safe, proposal/trace-aware rules from existing design authority before freezing exactly one CB successor. If such a decision needs new runtime diagnostics, move it to an independently authorized Code + Build / Test + Benchmark turn or an explicit Review-policy exception; the Review turn itself is runtime-free.

## Review closeout (interim, not complete)

| Duty | Answer |
|---|---|
| Accepted selector prefix rehashed | n/a for this incremental evidence: selector untouched, but original accepted-prefix hash not rechecked; formal closeout pending |
| Decisive claims independently rederived | Verified 4/4 source-face barycentric points against OFF mesh, re-derived cyclic side partitions, independently minimized all finite segments and certified same-face paths; four deliberately corrupted copies were rejected |
| Prior obligations discharged/carried | Needle proposal vs support provenance and intrinsic minimum widths **discharged**; admissibility/compatibility, support 815/487 validity, five lens coverage/cycle and singularity obligations **carried**; P13-e and O23 independent |
| Stable accounting | Durable stable 66 events / 17 categories / 49 recurrences, debt 1; no independent recount, no reclassification |
| ORIENTATION §3/§4/§7/§8, currency line | Not yet synchronized; formal review closeout still required |
| CHANGELOG / regression tracker | Not yet synchronized; no stable regression change proposed |
| ROADMAP / manifest / LESSONS | No checkpoint or selector promotion; not changed; formal final review still required |
| Successor frozen | No; the evidence still does not establish one corrective producer or legitimate admission rule |
| Turn boundary held | Yes, **this continuation** is offline Review-only; no builds, runtimes, or product/test edits |
| `review_check.py boundary` | Historical archive-only run failed Git-ancestry checks; **not claimed PASS**; verify from actual repository Git history before completed Review |
| Status / push verification | Review evidence to be committed and branch comparison verified before final direct `STATUS` beacon; same unfinished turn and original start preserved |

**Canonical checkpoint remains `IN_PROGRESS`**, with same-turn continuation, until the upstream contracts and full review/document obligations are adjudicated. The missing causal proof is unfinished review analysis, not a confirmed external platform failure.