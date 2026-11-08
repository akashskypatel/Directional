# M6-CP3 A4/A2b — independent topology-only scratch, 2026-11-08

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (Review, still IN_PROGRESS). **Exact frozen source:** `c54184c3caab9dfd37eab6653ae923e0a5c733e9` (snapshot workflow 42452191280, metadata and `source.tar.gz.sha256` verified). Read with the previous [WIP review](Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Review_WIP_20261108.md), [feasibility continuation](Architecture_M6_CP3_DEFN_P13_A4_A2b_Three_Side_Feasibility_Continuation_20261108.md), and RA-213.

## Independent scratch evidence (not production A4 or A3)

Construct an abstract oriented Y-sector disc complex using three radial shared chains from the central port to rim points A/B/C, with exact *combinatorial* chain cardinalities 10, 4, 9 (from RA-213). Three rim chains are AB, BC, CA. Form each disc as outward arm, forward rim, reversed adjacent arm; quadrangulate its simple even-length boundary by alternating left/right four-corner ear removals. The first ear removes the central port, so that port is incident to exactly one quad in each of three discs. Every shared-arm vertex is the *same explicit token* on both regions; there is no tolerance-based welding.

| Abstract input | Rim counts AB/BC/CA | Disc boundary edge counts AB/BC/CA | Disc quads AB/BC/CA | Global V/E/F | Boundary edges | Interior extraordinary valence |
|---|---|---|---|---|---|---|
| A3-measured-count **conditional pairing** | 56/33/75 | 70/46/94 | 34/22/46 | 185/286/102 | 164 | 4 vertices of valence 3 |
| Illustrative target-coarsened counts | 20/21/21 | 34/34/40 | 16/16/19 | 83/133/51 | 62 | 4 vertices of valence 3 |

In both cases every edge has one or two faces, interior edges have opposite directed use, every vertex link is connected and has the correct cycle/path shape, all faces have four distinct tokens, the rim is exactly the prescribed three rim chains, Euler characteristic is one, the center has three incident quads, and `sum_int(4-v)+sum_bd(3-v)=4` with interior sum 4 and boundary sum 0. Three extra interior valence-3 poles supply the net +3 beyond the prescribed central +1. These are **topology-only** claims.

**Non-vacuity:** the same scratch incidence checker rejects a flipped face (orientation), removed face (rim coverage), and duplicated face (edge over-ownership), for both cardinality sets. Scratch code SHA-256: `742119651cf330cc0079d1326965b8fe5c4db0fe973c250e1c0b839fa828d3c0`, 151 lines; preserved as downloadable chat artifact `Directional_A4_A2b_Combinatorial_Scratch_20261108.py`.

The measured-count assignment is only one pairing of RA-213's unordered region counts 70/94/46 with the three arm-pairs; actual oriented A2b walks have **not** been recovered. The illustrative counts 20/21/21 are **not** the result of running the exact A3 scheduler. Neither case uses source-face fragments, barycentric attachment, the supplied cross-field, source-boundary geometric fidelity, injective embedding, A5/A8 certificates, size/warpage/field/quality gates, or a produced A3 output. Mean equal-area size / 0.0883 is approximately 1.48 for 102 quads and 2.09 for 51 quads, demonstrating why a valid topological witness is not a target-size or production witness.

## D5 and producer contract implications

1. `GlobalTopologyArc::mandatoryEdge` is optional *single* `NetworkEdgeId`; `GlobalTopologyRegion::sourceFaces` is face-orbit fragment coverage, not an ordinary set of disjoint source faces. Source: `include/directional/geometry/GlobalTopologyPlan.h:44-90`.
2. `ConformitySpanId` is a single `NetworkArcId`; `canonicalize_impl` enforces one span per A2b arc, plus one incidence per boundary occurrence. `preferred_count` multiplies per-piece sum of squared metric lengths by piece count; `breakpoint_location` uses *piece-index*, not accumulated physical/metric length. Source: `include/directional/geometry/GlobalConformityPlan.h:27-65`, `src/geometry/GlobalConformityPlan.cpp:36-49`.
3. To coarsen boundary counts below the number of source-edge Mandatory arcs, positivity **cannot remain defined on each original full A2b arc**. A virtual chain must explicitly preserve all source segment lineage and oriented incidence while changing the A3 scheduling unit, positive-count contract and breakpoint ownership, or A2b must safely publish larger merged arcs with a many-source-edge certificate. A silent downstream count merge would break DESIGN §7.4.
4. The existing curved-disk A4 path is gated to hard-feature source regions and requires a candidate A2b face-set equal to the whole A1 region. Vase has zero hard features and three certified *fragments* of one A1 region; this producer cannot be re-used unchanged. Source: `src/geometry/SurfaceCellTracing.cpp:15478-15550`.

**Minimal future source experiments, in order:** (a) independently materialize the true oriented A2b disc walks and their exact A3 span/source-support coordinates; (b) determine one D5 chain identity/positivity design, test it with unchanged A2b authority and an exact A3 re-solve; (c) construct one source-face-fragment A4 disc with exactly those A3 breakpoints and port corner, certify reciprocal shared traces; (d) then test topology-distinct fill/embedding and every A5–A8 and size/quality gate. A4→A3 conformance must compare the exact ordered breakpoint **coordinates/IDs** on both sides, not counts alone. These are requirements for completing this same Review, not authorized implementation turns.

## Boundary evidence and disposition

The prior `review_check.py boundary` ran on an extracted snapshot without `.git`: local no-product/selector checks passed, four Git-history-dependent checks failed. GitHub compare separately confirmed `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is an ancestor of `c54184c...`. Independent GitHub baseline fetches established the exact protected heading sets: Handoff 4/4 retained, ORIENTATION 1/1 retained, Regression tracker 0/0. This resolves those historical facts *independently* but does not change the command's nonzero exit or constitute a full original gate PASS.

**Unresolved:** no true A3 chain re-solve; no per-disc source-attached A4 output; no geometric/quality/field validation; no selector/runtime promotion. D1 `QualityRelaxed` is a recommendation requiring explicit user approval before changing any expected tier or gate; all structural validation remains mandatory. Preserve RA-213's CB102 withdrawal and the singularity veto. No product/test/fixture/benchmark/build source changes in this review.
