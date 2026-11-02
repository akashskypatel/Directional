# P13-h2 Review — boundary-only completion changes topology and has a second variant gate

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (same unfinished Review, 2026-11-02). **Status of this finding:** independently rederived *static* source and topology implications, not an implemented change or a formal behavioral test. No new Code + Build successor is authorized by this record.

## Evidence authority and checks

Immutable source: snapshot event `6c95f68120a20c55ddc09fd155de83f633e49549` from GitHub workflow run `41393896396`, archive SHA-256 `701182750fbd98aa589f1792c4490224ed295ec2821d754bca8e02563550a27a`. This attempt independently recomputed the archive digest and verified **6,092/6,092** SHA-256 source entries. GitHub compare to this attempt's opening branch head found **zero changes** under `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/` or `CMakeLists.txt`. RA-197, source `PureQuadCompletion.cpp` SHA-256 `28a26b80f4b0b13605f691ebf15dd91191e51496be4f11db84b64f2f6adbad9b`, and `PatchDescriptor.cpp` are independently inspected from that immutable snapshot.

`p13_boundary_only_quad_count_audit.py` statically checks producer and caller routing, recomputes the Euler counts below, and rejects **5/5** mutated source *copies* (removed pattern dispatch, replaced pattern DP call, removed grid emission, changed closed-form variant case, changed caller's expected backend). The script was initially written with an erroneous assumption of **8** generated interior vertices; it failed that assertion, which was corrected to **7**, and the complete five-control run then passed. This is a local arithmetic correction, **not** a product fix or a manufactured test pass. The receipt is `P13_Boundary_Only_Completion_Counts_Audit_20261102.json`. `review_check.py boundary` was also rerun on the Git-history-free archive and returned **exit 1** on the same four historic-ancestry checks. Previous authentic GitHub ancestry comparison independently established the baseline's ancestry but does not make this script invocation green.

## Two producer/caller gates, not just one

1. `PureQuadCompletion.cpp:1997–2048`: the current four-sided equal-opposite-sides rectangular completion emits `width × height` quads and `(width − 1)(height − 1)` new interior vertices; its `true` result denotes **construction**, not completed-quad source-orientation/embedding validation.
2. `PureQuadCompletion.cpp:2450–2512`: `complete_pure_quad_patch` chooses that grid before `complete_pattern` and only tries `complete_pattern` when `!completed`; the source-ownership, disk-topology and per-quad embedding predicates run *after* this decision. A grid that constructed but then failed embedding cannot reach the existing boundary-only dynamic-programming option. `complete_pattern` uses only boundary vertices and creates no new interior vertex, and its result uses the `Pattern` backend.
3. **Second, separate gate:** `PatchDescriptor.cpp:2900–2940` computes `expectedBackend=ClosedForm` for every four-sided equal-opposite-count patch and obtains `variantCount` from that expected backend *before* calling the completion producer. `PatchDescriptor.cpp:896–912` defines **one** `ClosedForm` variant versus `2 × boundary vertices` `Pattern` variants. Thus the producer is called **once** for each rectangular descriptor, even if its only candidate fails with `InvalidCompletionQuadEmbedding`. Merely adding a late alternative without considering this variant route can leave nonzero valid pattern variants untried. The later completion-ownership-conflict repair in `PatchDescriptor.cpp:3086–3160` computes variant counts from the **chosen mesh backend**, not the original expected backend; if a future fallback returns `Pattern`, that later path will see a different variant range. This source fact must be reconciled before freezing an implementation patch.
4. `PatchDescriptor.cpp:1679` sets `patch.simple=true` for descriptor construction, and `PureQuadCompletion.cpp:2460` checks `patch.simple` before pattern dispatch. The later ownership, lineage, source chart and disk checks must remain unchanged; a nonzero diagonal search result is not a global surface-injectivity certificate.

## Exactly what an interior-free candidate changes

For a topological quad disk with a single simple boundary of `B` edges, **no interior vertices**, and only ordinary interior edges, `V=B`, `4F=2E_interior+B`, and `V−E+F=1` imply `F=B/2−1`. Rectangular grids instead have `F=w×h` and `(w−1)(h−1)` interior vertices. All four shapes and identities are taken from *RA-197 F6*, not inferred from arbitrary approximate needle measurements:

| Vase cell | Frozen grid dimensions | Boundary edges `B` | Existing grid quads | Existing generated interior vertices | Hypothetical boundary-only quads |
|---|---|---:|---:|---:|---:|
| 6095 | 2×2 | 8 | 4 | 1 | 3 |
| 20533 | 2×2 | 8 | 4 | 1 | 3 |
| 20968 | 3×2 | 10 | 6 | 2 | 4 |
| 22350 | 2×4 | 12 | 8 | 3 | 5 |
| **Total** | | | **22** | **7** | **15** |

A successful boundary-only fallback would preserve the same *boundary edge count and exact boundary identities* while changing both **internal combinatorics** and backend provenance, removing seven generated vertices and seven quads across these four patches. These counts are structural predictions, **not measured product output**, and do not establish field-aligned interior layout or global cross-patch injectivity. RA-197's scratch `Rotation + grid DP (mode 4, data point)` reported zero local completion failures and then five `SideCountUnsupported` lens failures. That report supports a **candidate** for these fixed needle boundaries but is not an independently accepted package/test and does not prove a successful full Vase mesh.

## Correct owner, falsifiers and accepted-authority controls

A bounded candidate for *only the four needles* belongs to **pure-quad completion dispatch and its calling variant-selection contract**, not an unsupported global suppression of near-parallel source traces. It must preserve the original chosen grid exactly when already valid, attempt a boundary-only alternative only for a specifically failed grid embedding (never a failed source/chart/ownership proof), restore the immutable boundary before another candidate, preserve typed failure detail if all candidates fail, and pass all existing source lineage/ownership, disk, quad embedding and global assembly checks unweakened. Do not silently change variant ordering, backend enum or cache dependency identity. Independently demonstrate a valid geometry that requires a later pattern variant when variant zero fails, so that the caller's `ClosedForm` one-variant policy cannot make the proposed retry vacuous. A positive existing-grid witness must continue using `ClosedForm` byte-for-byte; a negative genuinely non-embeddable or wrong-sheet boundary must remain RED. Accepted CP2 **491/491** and TB70 **880/880** (membership **961**, **81** deferred), stable **66/17/49**, debt **1**, cannot be weakened or promoted by this Review.

**Lens correction is a separate producer question.** Five P13-i descriptors have **six prepared boundary edges** (3 field + 3 mandatory rail) after parity and subdivision preparation, but only two logical sides; their observed typed `SideCountUnsupported` rejection is not an odd-parity impossibility. Raw arrangement has five halfedges before the repair. The prior incorrect “fixed five-edge lens parity obstruction” was formally retracted in the previous correction. A source-authorized lens layout must address rail-contact topology and protected selector degrees, not modify the four-grid fallback for unrelated reasons. No source-authoritative demonstration yet establishes a single corrective owner for all nine cells. Preserve this Review as unfinished; do not start a Code + Build turn or claim CP3 acceptance.

## Review closeout — interim, not a completed turn

| Duty | Evidence / carried status |
|---|---|
| Accepted prefix | Independently rehashed earlier this canonical Review: CP2 491 ordered identities; TB69 878 rows unchanged in TB70 880; no selector edit this attempt |
| Static claims / non-vacuity | Both completion variant gates + Euler arithmetic independently derived; 5/5 source-copy negative controls rejected; no Directional runtime |
| Prior obligations / owner | Needle completion variant/identity/quality/injectivity controls sharpened; lens source admission and retained rail topology, trace terminal evidence and parity repair remain carried; BunnyRandom P13-e separate |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt 1; CP2 accepted, TB70 candidate only |
| ORIENTATION / handoff / CHANGELOG / roadmap | No accepted checkpoint or semantic authority changed. Full formal Review closeout still pending |
| Successor | Not frozen: no single proven producer owner or complete lens corrective contract |
| Review boundary | `review_check.py boundary` **exit 1** on Git-history-free snapshot, four ancestry checks; not reported green |
| Turn boundary and sync | Source/test/fixture/selector/build unchanged; record committed via GitHub connector, same canonical turn; final STATUS direct write required |