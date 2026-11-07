# TB47 same-turn R53 — torus face-gauge cut-domain preflight (2026-10-28)

**Scope:** independent, source-faithful Review scratch for `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER`. No native Directional binary, C++ test, benchmark, build, fixture modification, selector change, or successor action. The existing R49 G3 obligation is NOT discharged.

## Exact input and independently reconstructed topology

The already measured original TB47 `cp3entry:1`/row 492 reports five source/A3 candidate carriers, five tracer-reciprocal/holonomy-matched carriers and **zero odd face-gauge pairs**. Its `raw/492.log` SHA-256 is `696b459ddc597c479d4df97e59da0663e09f4b2018829d065d62e0c741b9e7ff`. The exact `tests/SurfaceCellTransitionQuotientTests.cpp` SHA-256 is `bec57b16e2475cd21be975fad22411925bdceaabd496f3258801d0f7875ea661`, and committed `torus.obj` SHA-256 is `8a6e0b63382a5eab8b02dc6e07f35e1611c736bf9c5744533fcee573de84c1d8`. These source inputs belong to the previously verified 5,951/5,951 source snapshot at `c08de57f6c76d53e6de856c6ca9228a7ff4db507`, and the immutable 1,014/1,014 TB47 result.

Independently parsed OBJ face incidence and the **exact 18 source-hard edges** from `torus_row408_hard_edges`: 72 vertices, 144 triangular faces, 216 unique edges. Removing just the 18 hard edges from the 144-face dual leaves one connected component, 198 non-hard dual edges, and **55 independent fundamental cycles** (198 − 144 + 1). This is a *source-hard-edge complement graph*, **not proof that its edges equal the A4 accepted cut domain**.

The five logged candidate hard carriers meet distinct source face pairs:

| Candidate | Source edge | Two source-face rows | Original measured gauge delta |
|---|---|---|---|
| c0 | (0,3) | 1, 22 | 0 |
| c1 | (0,61) | 121, 142 | 0 |
| c2 | (3,25) | 25, 46 | 0 |
| c3 | (25,37) | 49, 70 | 0 |
| c4 | (37,49) | 73, 94 | 0 |

All ten incident face rows are distinct. Therefore a **hypothetical source arm cyclic +1 on face 1 alone** targets only c0 among these candidates. The Z4 edge change `d(u,v) = shift(v) − shift(u) mod 4` affects exactly two undirected non-hard incident edges (four directed records). It is an **exact coboundary**: reverse signs cancel, and all 55 fundamental cycles have zero added holonomy. The c0 *incidence-order* delta would be 3 and all other candidate deltas stay zero. **Incidence order is not the native witness's directed from/to order**: the native signed delta could be 1 instead; only the odd/even prediction is warranted by this model.

## Falsifiers and feasibility boundary

- A deliberately copied forward odd value as reverse produces `1+1=2 mod 4`, violating reciprocity and the graph-potential reconstruction. Correct inverse/coboundary records pass.
- Cyclic +1 on **both** c0 incident faces produces **zero** c0 delta; a uniform shift cannot supply the missing odd witness.
- The existing `validate_nonzero_z4_torus_chart_subject` independently requires exact authored raw X/Y axes equal to the frozen geometric seam ramp (`authoredX - expectedX`, `authoredY - expectedY`). A face-only cyclic arm reindex **fails that frozen oracle by construction**. Do not mutate the seven-test torus singleton or weaken its exact axis checks. A distinct raw-source metamorphic fixture and corresponding independent authority checks are required.

**Critical limitation:** these are topological/Z4 *conditional* consequences, not evidence that `finalize_surface_cell_raw_cross_field`, native A3 matching, canonical A4 accepted cuts, branch-gauge root/frame selection, periodic relation retention, or A5/A6 admit the changed raw input. In particular, do not claim that the proposed c0 positive is native valid, that the face-gauge values actually changed, or that the one-face arm relabel proves G3. Root face 133 from previous R25 native analysis is not an independently measured root in this scratch run.

## Bounded future native oracle, subject to independent turn authorization

Create **a separately named torus raw-source metamorphic input** from the committed OBJ and existing frame generator, with only face 1's four raw cross arms cyclically permuted; verify identical unordered 4-RoSy axes and source topology before finalization. Independently regenerate and compare the complete A3 matching/carrier and A4 phase-front products for baseline and relabeled sources; require source-attached c0 A4 reciprocal periodic action, genuinely odd and signed face-gauge pair, A5 owned canonical transport/occurrence maps and A6 selected relation, with restored-positive and first-owner wrong-sign negatives. Reject earliest typed producer failure rather than silently searching other candidates or declaring a proxy PASS. Protect the existing `selector:443/446/447` torus controls, separately masked A5 periodic tail, and E2 `cp3entry:2` ownership. **No exact CB48/TB48 hunks or manifest frozen by this R53.**

Audit artifacts: `tb47_r53_g3_face_gauge_cut_domain_audit.py` SHA-256 `44e3e619e2ae5a40e9b5ed8447d63376d1b51f07643662da6801117bf7bb4c1e`; JSON receipt `tb47_r53_g3_face_gauge_cut_domain_receipt.json` SHA-256 `cbba038a3ce5143e62995338a2b7067fee8e913cf4edf0460f22b311425c2235`. Both preserved outside repository as exact downloadable review evidence. The script uses only source text, OBJ and prior immutable log; no native Directional run.

**Disposition:** accepted M6-CP2 **491/491**, TB47 unpromoted **500 PASS / 4 RED** out of 504, selector497 frozen; stable **66/17/49**, debt 1. G1/G2/G3, periodic A5 tail, E2, authentic history remain open. Continue only the current canonical Review turn.

## R56 addendum — measured source-model gauge compensation, not A3/A4 native proof (2026-10-28)

**Independent numeric + frozen C++ source review.** This resolves the missing *canonical A3 branch-transport* preflight in R53–R55. `finalize_surface_cell_raw_cross_field` preserves the authored raw arm ordering, `SourceFaceTopologyKey::make` sorts each face's vertex IDs, and `build_face_branch_frame` selects the minimal positively oriented raw arm relative to that topology-keyed face edge (`FieldTransportAtlas.cpp:233–313`). `build_branch_transports` then computes `canonicalLift = rawForwardLift + rawGauge[first] − rawGauge[second]` (`:348–378`), with hard edges excluded from *actual A3 branch adjacency*. The audit reconstructs the canonical source-face reference and gauges for all 144 committed torus faces, and reuses R54's independently computed directed `principal_matching` model with R55's verified `EF` ordering.

For **face 1 raw-arm advance** (`new raw[j] = old raw[(j+1)%4]`), the independently reconstructed A3 *raw* gauge on face 1 changes **−1 modulo 4**; all other 143 gauges are unchanged. The **three** source `matching` changes are `(0,2): 0→3` (directed face 0→1), c0 `(0,3): 1→2` (1→22), and `(2,3): 0→1` (1→24); the other 213 source-edge `matching` values are unchanged. Under the **C++ canonical-lift formula**, the modeled result is exactly **216/216 invariant canonical transports**, including the 198 source non-hard edges and 18 virtual hard-edge evaluations. The 18 hard virtual evaluations are diagnostic arithmetic only: they are *not* claims that A3 published hard `FieldBranchTransportAdjacency` records. The inverse arm cycle also leaves modeled canonical transports invariant but makes c0 raw matching zero, so c0 is ineligible as an odd carrier in that direction.

The observed *raw matching* change is the coboundary `δχ(u→v)=s(u)−s(v)` for `s(face1)=+1` representing **raw-arm advance**, whereas the **A3 raw-gauge** change is `δg(face1)=−1` and satisfies `δχ(u→v)=δg(v)−δg(u)`. This fixes a possible **sign-convention misreading of R53**: its `d(u,v)=shift(v)−shift(u)` is correct when `shift` means *the raw-gauge change*, but must not be interpreted as +1 for a +1 *raw-arm index advance*. The independently calculated deltas satisfy each of **73** fundamental cycles in the full 216-edge/144-face source dual and each of **55** cycles in the 198-edge source-hard complement. Every subgraph of a coboundary graph inherits vanishing added cycle holonomy; however the actual A4 accepted-cut graph and its root are still **unmeasured**.

**Non-vacuity/falsifiers:** (1) changing only a single non-hard `matching` breaks source-dual potential consistency and canonical transport; (2) omitting the raw-gauge update fails on all three incident edges; (3) using the *opposite* gauge-update sign fails on the same three edges. All three were rejected by the source-model audit. These do **not** prove that any real A3 atlas, topology plan, A4 chart, tracer, A5 or A6 will admit the modified input. A valid G3 still requires a **distinct** real producer-authenticated face1-advanced source fixture with actual nonzero c0 chi, A3 checked atlas, A4 accepted-cut root and signed odd face gauges, an A4-published reciprocal periodic relation, A5/A6 positive and signed first-owner negative/restore. Do not change the shared seven-consumer torus singleton, thaw selector497, promote TB47, or start CB48/TB48.

Exact audit: `tb47_r56_gauge_undercut_audit.py` SHA-256 `72da33b853a81fe81227c23440d01deb571421598d22c9111e29e2e92876f35f`; machine receipt `tb47_r56_gauge_undercut_receipt.json` SHA-256 `0143bdbb88ab125d228a086ed5dc5d729d638c86893f86dd8da7454b3ddbda35`. Both run on verified `c08de57f6c76d53e6de856c6ca9228a7ff4db507` source and existing R54 numerical audit, not new native Directional runtime. G1/G2/G3, masked periodic A5 sites, E2 and authentic history audit remain open; last accepted CP2 491/491, original TB47 candidate 500/4.
