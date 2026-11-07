# M6-CP3 P13 sliver-cell review — exact active producer path

**2026-11-02.** Owning canonical turn: `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. Independent, source-driven review only; **no production/test/selector changes, no new build or runtime**. This supplements and corrects prior nine-cell review material; it does **not** settle root-cause ownership or authorize implementation.

## Source authority and independently reproduced data

- Semantic production CB76: `f59f92f889fc6fe22d689fd7559c024cd09c6c72`; reused immutable source snapshot event SHA `898316210ab810daa10d2072db927f9ebe4b2a98`, independently verified all 6092 source-file checksums. Relevant source files were unchanged between these semantic identities. 
- Prior diagnostic run: scratch-only compile `41398086098`, artifact `13119948654`, source `95684f2e18c3c573dcbf11d35deaad696d0316d3` (CB76 plus opt-in logging); one Vase run `261644 ms`, failed closed at `InvalidCompletionQuadEmbedding;patch=6095;classification=source-orientation-mismatch`, no output quads. This work **did not rerun the test**.
- Raw stderr SHA-256 `e0a28c941bdaf4d86a1a5d0cf23216ac890f266b67d591e2a7c528a00e189530` and 9/9 prior provenance receipt. New `p13_fallback_path_audit.py` SHA-256 `42667efe230d601a8d82dd547ed336a927f3618b57e292c765ce867c32518e4a` and JSON SHA-256 `912ee3c52db5ebd150ecaeecd021150197be3697f45ce1eb6d7d9ffc3a4dc3ff` (recomputed from raw log, not copied from earlier summaries). The script verifies all nine, independently joins each halfedge to its `P13_ARC` provenance (arc/seed/strand/proposal) and asserts the relevant frozen-source branch contracts. Successful run: `nine_cells_verified=9`, `needle_proposal_boundary_halfedges=21`, `needle_support_halfedges=10`, `lens_rail_halfedges=10`, `lens_support_halfedges=15`.

## Decisive source-path distinction

1. `SurfaceCellTracing.cpp:20721-20738`: a **produced** phase-front product creates `SurfaceCellProposal`s with `seedId=-1`, then immediately returns. A rejected phase-front also immediately returns (`:20741`). Only the **not-applicable/fallback** branch populates `network.seeds` and creates seed-owned proposals (`:20744+`).
2. `FlowRepStrands.cpp:782-801, 507-540`: `proposalSeedId` is copied from each accepted proposal's `seedId`, and `proposalId` from its stable proposal index. `RemeshPipeline.cpp:11040-11107` preserves these values into arrangement arcs, and `SurfaceArrangement.cpp` stores them in halfedge source provenance.
3. The four defective needles' **21 proposal-derived directed halfedges** have positive, matching `(proposalId,proposalSeedId)` values. Thus the execution **cannot have taken the produced phase-front proposal branch** for those arcs. This is evidence for the non-authoritative seed-owned fallback. The remaining 10 needle halfedges are optional nonproposal support traces, not proof of authoritative phase-front output.
4. `RemeshPipeline.cpp:13362` sets `useAuthoritativePhaseFront` only if a produced phase-front exists; `:13713-13714` forwards it to `arrangementOptions.useAuthoritativeProposalCycles`. Therefore the Vase run selected **`useAuthoritativeProposalCycles=false`**. Its successor path is `SurfaceArrangement.cpp:2828+` directed source-entity wedge construction, **not** `:2694-2827` authoritative proposal-cycle/exterior completion. The test's `UniformPhaseFront` parameterized suite name does not itself establish execution of the produced phase-front branch.
5. `FlowRepStrands.cpp:650-782` adds optional *anchored* support traces, encoded as `strandProvenance=-2-supportTraceId` with `proposal=-1` (the original seed-to-trace relation is `traceId=4*seedIndex+branch`). All five lenses pair **three** directed optional trace arcs with **two** directed mandatory rail-0 arcs. No relaxation of rail authority is permitted. The raw arrangement reports them as **two-sided disk cells**, not admissible four-sided patches.

| Cell | Source origin | Exact proposal/trace IDs |
|---|---|---|
| 6095 | 6 proposal arcs | proposals 300,393,524,526 |
| 20533 | 6 proposal arcs | proposals 640,1221,1222,1229 |
| 20968 | 3 proposal arcs + 6 optional support arcs | proposals 465,1078; support trace 815 (seed 203, branch 3) |
| 22350 | 6 proposal arcs + 4 optional support arcs | proposals 488,784,1061; support trace 487 (seed 121, branch 3) |
| 26735 | 3 optional trace arcs + 2 mandatory rail arcs | trace 1037 (seed 259, branch 1), rail 0 |
| 26764 | 3 optional trace arcs + 2 mandatory rail arcs | trace 878 (seed 219, branch 2), rail 0 |
| 26781 | 3 optional trace arcs + 2 mandatory rail arcs | trace 20 (seed 5, branch 0), rail 0 |
| 26802 | 3 optional trace arcs + 2 mandatory rail arcs | trace 422 (seed 105, branch 2), rail 0 |
| 26812 | 3 optional trace arcs + 2 mandatory rail arcs | trace 612 (seed 153, branch 0), rail 0 |

The previous cyclic-side indexing correction remains binding: **29 wrong side labels, of which 24 also differed in family**. Its geometries are Euclidean observations, not chart-transported intrinsic certificates.

**Independent non-vacuity controls:** The read-only provenance analyzer passed on the unmodified 9-cell stderr. Three separate mutated *copies* of that log were rejected with nonzero exit statuses: (a) replace proposal 300's positive seed with `-1` → missing seed-owned proposal; (b) replace support trace 1037's strand encoding → lens origin groups inconsistent; (c) erase mandatory rail-0 identity → lens origin groups inconsistent. No product code, test source, fixture or accepted evidence was changed. The analyzer does **not** validate wedge ordering or the source tracer's geometrical admission, so these controls cannot establish those stronger claims.

## What this proves — and what it does not

**Proved:** This Vase execution used seed-owned fallback proposals and the directed-wedge successor branch. It retained five individually identifiable anchored support traces adjacent to mandatory rail 0, and two needles mixed those support traces with seed-owned proposals. No downstream quad completer invented the bounding arcs. The previous plan must not try to instrument **authoritative proposal-cycle successor ordering** as the active Vase path.

**Not proved:** that an optional support trace was wrongly admitted, that its contact to rail was topologically invalid, that the wedge resolver paired the wrong outgoing rays, that thin seed-proposal cells violate any current exact invariant, or that a **single** producer owns both needles and lenses. The nine-cell log has only the chosen boundary cycles, not the *complete* outgoing-ray alternatives at each junction; it cannot validate angular predecessor selection. The `Sliver` predicate is only an absolute-area cutoff of `1e-14` (none of nine meets it). No width epsilon, rail suppression, permissive two-sided patch, or global acceptance relaxation is authorized.

## Next bounded review discriminator / stop rules

For the five lenses, the precise outgoing-wedge source nodes are `26735:56813/56385`, `26764:16998/47581`, `26781:9928/56412`, `26802:57415/53651`, `26812:57661/23821`. Record for each tip: full same-source-entity outgoing halfedge set (not just selected lens edges), chart/region/sheet roots, resolved entity, directed ray parameters, twin and incoming IDs, predecessor choice, and protected rail contact; independently recompute the source-supported cyclic predecessor. Distinguish **valid wedge + inadmissible retained network** (trace/FlowRep owner) from **invalid wedge permutation for a valid network** (arrangement owner).

For needles, compare source-authoritative ownership of the distinct seed proposals and support traces (especially trace 815 and 487) and intrinsic same-sheet corridor widths; check accepted-green conditions and prevent any loss of mandatory rails, sheets, singular indices, shared boundary, or topology. If no single correction explains both phenomena, explicitly decline a forced single-owner finding and record separate owners and falsifiers before CB. Keep `Status: IN_PROGRESS` until review duties/closeout are fulfilled; preserve the original start date and same-turn successor. This audit did not run `review_check.py boundary`; its prior archive-only Git-ancestry checks remain unresolved.