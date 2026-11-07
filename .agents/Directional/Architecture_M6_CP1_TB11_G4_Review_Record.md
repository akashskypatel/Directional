# `M6-CP1-TB11-G4-REV` — Independent Review Record

**Disposition:** **CB11 candidate REJECTED / runtime evidence accepted / two REDs reclassified as test-definition defects / bounded R1 recovery required.**

Candidate `11308472138 / 582da20a925ba920c923bf5aacb9e0e56ef0723d` remains **unpromoted**. The last reviewed runtime remains `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` until a recovery gate and mandatory recovery Review succeed.

Stable accounting remains **60 events / 16 categories / 44 recurrences**, project debt **1**. No stable regression event is added: both REDs are newly authored focused-oracle/definition failures on an unpromoted candidate and selector449 remains **449/449 PASS**.

## 1. Independent evidence re-derivation

Review re-used the immutable TB11 package/result bytes without executing generated Directional runtime. Candidate ZIP SHA-256 is `a4d178678bcbc9c29fc4003ffc9205ef220873bfb0e5247b21a453fffdc8d04d`; its root `SHA256SUMS` is `c6e691329dfe5599caf658b23e70d51d45ac76c090afc7d9cb86f3901df34468` and verifies **28/28**. Embedded source is `582da20a925ba920c923bf5aacb9e0e56ef0723d`, archive SHA-256 `c41200fefded7e8a60f57eb801c5de2476eebafe6822fe5ce5e4a2113971c768`, with clean source-status receipts.

Result ZIP SHA-256 is `7de4a3203720d170691ff0f1b3d1773736b56f857accd5e51ced5f92c5973add`. Its self-manifest SHA-256 is `31a537f5d420b64e828fe75c8c5125e33ef3c1c3588efc9e531b6cca3ee61317` and independently verifies **973/973**. The ledgers contain exactly **28 focused + 449 selector = 477** processes. Focused is **26 PASS / 2 RED**, selector is **449/449 PASS**, aggregate **475/477**; every row selected exactly one test and skipped zero. RED is exactly focused ordinals **25 and 28**. The execution boundary records no configure, compile, relink, generated discovery, benchmark, package/mode repair, source/test/fixture/selector mutation, or retry after runtime start. Immutable package/source/execution-view postflight is green.

Review source authority was refreshed with source-snapshot run/artifact `37233051478 / 11314264059` at branch SHA `48c4fbeb154fb8deeb26b970a13ad2ea652583b1`; archive SHA-256 `986e3bc1ec98c681af537004def24d4bd165da417437f9c83268729c96d02c05`, **5348/5348** manifest rows verified, `runtimeExecution=false`. Relevant product/test files are byte-identical to the embedded candidate source. A process miss occurred before this snapshot: several repository source/document reads were made before the mandatory `READ_MODE=snapshot` gate was fixed. No decisive conclusion below relies on that pre-snapshot inspection; every finding was re-derived from the verified local snapshot. Existing tool-conservation policy already forbids the pattern, so this adds no stable lesson/event.

## 2. Finding F1 — ordinal25 is a false rejection: RA-21b conflates quotient identity with arrangement-node identity

**Classification:** TEST-ORACLE / DEFINITION DEFECT. `M6-CP1-TB11-G4-EXEC-CAND-01` is **not** evidence of an A6 production side-pairing defect.

Ordinal25 fails at three linked assumptions: one A6 class must map to one arrangement node, the two incident sides of one A6 edge must have identical arrangement-chain edge sets, and that common chain's endpoints must equal the globally chosen nodes for the A6 classes. Runtime shows 35 class/node disagreements, 30 paired-chain disagreements and 18 endpoint-set disagreements.

The frozen RA-21b assumption is invalid for the exact produced-torus authority:

1. `SurfaceCellTracing.cpp` pairs same-region hard-rail boundaries only when their `sharedBoundaryInterval.boundaryOccurrence` values are **distinct**. It then sets reciprocal `oppositeEdge`, constructs a periodic holonomy, and converts the pair to `PeriodicCut` with one shared `PeriodicRelationId`.
2. A5 consumes that reciprocal phase-front authority and publishes the two endpoint occurrence relations across the paired sides. A6 unions the relation endpoints into quotient classes. This is quotient identification across two distinct cut occurrences; it is not a claim that the two cut sides are the same arrangement arc.
3. `SurfaceArrangement.cpp` builds physical DCEL nodes/halfedges from scoped source-node identity and merges segment provenance only when it lands on the same undirected arrangement edge. It does **not** apply A5/A6 occurrence relations to identify arrangement nodes or halfedges.
4. Therefore a valid PeriodicCut quotient edge may have two distinct arrangement provenance chains and its quotient endpoint class may contain occurrences represented by distinct arrangement nodes. Requiring equality of those chains/nodes is exactly the quotient/arrangement authority conflation that the stage split was intended to avoid.

The correct migration oracle is per-occurrence/per-side, not per-quotient-node physical identity. Each proposal side must still have one valid degree-2 arrangement provenance chain, and each A4 corner occurrence must still be the unique intersection of its adjacent proposal-side chains. But A6 quotient equivalence is then checked through A4 `oppositeEdge` + A5/A6 relation authority; members of one quotient class are not required to share one arrangement node, and the two sides of a quotient edge are not required to share one arrangement edge set.

Focused identities 26 and 27 are independently green, which is consistent with this classification: typed hard-feature/relation labels and quotient member lineage survived. They do not by themselves promote the candidate; they only show the RED is not a label/lineage failure.

## 3. Finding F2 — ordinal28 exposes an unproved non-vacuity premise, not a demonstrated extractor implementation defect

**Classification:** DEFINITION / FIXTURE-WITNESS GAP. `M6-CP1-TB11-G4-EXEC-CAND-02` is separate from F1 and is **not** established as a production regression.

Ordinal28 fails only at its first non-vacuity assertion. The hard-feature tamper is never reached. Static review proves that any candidate currently emitted with `includeProtectedCandidatesForDiagnostics=false` already satisfies the independent predicate used by ordinal28: the extractor groups one `stripOrdinal`, rejects invalid path degree, marks cell presence as side-feasible, and filters every hard-feature, boundary or quotient-valence singularity candidate. The independent oracle then re-checks those same externally visible facts. Therefore the observed failure means the production call emitted **no eligible candidate at all** on this produced view; it is not an independent-oracle disagreement about an emitted candidate.

The prior M4CP4 non-vacuity result cannot establish the R4 D3 premise. That accepted test extracts candidates from the retained arrangement grouped by `(family, strand)`. R4 §4.3 explicitly removed `family/strand` from A6 authority and replaced that grouping with the transitive closure of opposite edges in quotient quads. The old test proves an arrangement candidate exists; it does not prove the new quotient-topology strip partition contains an unprotected, nonsingular path/loop on the same fixture. R4 §4.4 silently assumed that transfer and ordinal28 is the first executable falsifier of the assumption.

Review does **not** authorize changing production strip closure, valence classification, protection semantics, or side-feasibility merely to manufacture non-vacuity. Those implementations match the frozen §4.3 rules on static inspection. The reason the produced torus has zero eligible quotient-strip candidates (protected strip, quotient singularity, or topology of the opposite-edge closures) was not emitted by the immutable TB11 artifact, so Review does not invent a more specific runtime cause.

## 4. Binding amendments — RA-21c and RA-23

### RA-21c — arrangement is a per-side subdivision witness, not quotient identity authority

RA-21b items 2-5 are amended as follows for the CB11 migration oracle:

1. Keep the positional proposal/cell preconditions and provenance-key rule unchanged.
2. Build and validate one degree-2 provenance chain for each `(proposalId, proposalSide)`. Every arrangement halfedge must retain proposal provenance; non-proposal inserted arcs remain a stop.
3. For each A4 corner **occurrence**, independently require the previous/next side-chain node sets to intersect in exactly one arrangement node. Store this as an occurrence-node witness. Do not collapse this map by `SurfaceQuotientClassId`; two occurrences in one quotient class may legitimately have different arrangement nodes.
4. For each A6 two-sided edge, map its `SurfaceQuotientSideId`s back to the exact phase-front edges by `(filledCell, filledSide)` and require reciprocal `oppositeEdge`. Require the A5/A6 endpoint relations to certify the reversed quotient-class pairing and relation owner. This relation authority, not physical chain equality, establishes the quotient edge.
5. For each incident side separately, require its chain endpoints to equal the two occurrence-node witnesses for that side. Do **not** require the two incident sides' chain edge sets or endpoint-node sets to be equal across Ordinary/HardRail/Periodic quotient relations.
6. Keep per-chain `hardFeature` uniformity and equality to `hardFeatureProtected`; keep exact HardRail/Periodic owner checks from phase-front/A5/A6 authority. No position, epsilon or hash may establish identity.
7. Stop for Review on positional failure, missing proposal provenance, non-degree-2 side subdivision, non-unique occurrence corner intersection, non-reciprocal phase-front side pairing, relation/owner disagreement, per-side endpoint disagreement, sliver/extra cell, or any need to infer quotient identity from arrangement geometry.

### RA-23 — split produced-boundary verification from CP1 mechanism non-vacuity

R4 §4.4's inference from the old arrangement candidate test to produced A6 quotient-strip non-vacuity is withdrawn.

1. The produced torus remains mandatory for identities 25-27 and for identity28's **universal** boundary checks: independently reconstruct the opposite-edge strip partition from `view.quads` + side incidence and require every published `stripOrdinal` to match it; independently validate every emitted candidate. An empty produced candidate set is not, by itself, a CP1 failure.
2. Identity28's **mechanism-only non-vacuity/tamper** must use a test-side canonical closed toroidal A6 view with at least a `4 x 4` periodic quad grid: every edge two-sided, every vertex quotient-valence four, no boundary/protection labels, and independently derived opposite-edge strip ordinals. It must produce at least one independently eligible closed-loop candidate. Marking one edge of that exact candidate `hardFeatureProtected=true` must make the exact candidate independently ineligible and absent from extraction.
3. The test-side toroidal view is an extractor mechanism fixture only. It grants **zero** `G4-B002` debt credit. M6-CP3 retains the direct-production requirement: closed source, recovery/fallback disabled, a directly produced independently eligible candidate, and discriminating hard-feature tamper after A5-A8 are complete.
4. Focused identity names/order and focused28 list bytes remain unchanged.

## 5. Candidate and regression disposition

- `M6-CP1-TB11-G4-EXEC-CAND-01`: **CLOSED / FALSE REJECTION / TEST-ORACLE DEFECT / NON-STABLE.** Root is RA-21b's invalid quotient==arrangement identity assumption across relation seams.
- `M6-CP1-TB11-G4-EXEC-CAND-02`: **RECLASSIFIED / DEFINITION-WITNESS GAP / NON-STABLE / RECOVERY REQUIRED.** The produced-torus non-vacuity premise was never proved under quotient opposite-edge strips. No product defect is established.
- The two findings are not merged. F1 concerns the migration comparison authority; F2 concerns a non-vacuity premise for a different strip model.
- Stable accounting stays **60 / 16 / 44**, debt **1**.

## 6. Promotion decision and bounded recovery

The CB11 candidate is **rejected for promotion** because the frozen 477 gate did not pass, even though Review finds no demonstrated production-source defect. Recovery must prove the corrected oracle rather than waive the RED.

Exact successor: **`M6-CP1-CB11-G4-R1`**.

R1 is test-authority recovery only. It may implement RA-21c in focused ordinal25 and RA-23 in focused ordinal28, with helper-only changes needed to express those oracles. **No semantic production change to A5/A6 closed-complex construction, protection, strip closure, or candidate extraction is authorized.** If R1 discovers that such a production change is necessary, it must stop and return to Review instead of broadening scope.

R1 compile/package remains Code + Build only. If compile green, successor gate is the unchanged focused28 + selector449 = **477** fresh exact-filter processes, then mandatory `M6-CP1-TB11-G4-R1-REV`. `M6-CP1-CLOSE-REV` remains held.

---

## Review-agent addendum (2026-10-04, resumed `M6-CP1-TB11-G4-REV`)

**Disposition:**
- **Rejection: CONFIRMED.**
- **F1 (ordinal 25): CONFIRMED in substance.** RA-21c over-relaxes, and RA-21d sharpens it.
- **F2 (ordinal 28): OVERTURNED.** It is a **production/definition defect**, not a non-vacuity witness gap.
  - R4 D3 §4.3 rule 7 groups strips by quad-opposite edges. That produces *rung sets* (matchings), which the path-degree classifier can never accept.
  - The CB11 extractor therefore emits **zero candidates on every closed quad complex**.
  - RA-23's synthetic 4×4 torus would fail the same way.
- **RA-24** replaces rule 7 with edge-loop (strand) closure.
- **The R1 plan is re-scoped** to one bounded production change plus the oracle fixes.
- Accounting 60 / 16 / 44, debt 1.

### L1. Independent re-derivation (confirmed)

**Artifact.**
- I downloaded result `11312313559` again. Its ZIP SHA-256 is `7de4a320...3add`, and `SHA256SUMS` verifies **973/973**.
- Focused is RED at exactly ordinals 25 and 28. Selector449 is 449/449 PASS.

**Ordinal 28's raw log.** The failure is `found != extracted.candidates.end()`, where both iterators are null. **`extracted.candidates` is empty.**
- No candidate was emitted at all.
- So this is not "emitted candidates failed the independent oracle". TB11-REV §3 reached the right first step, but drew the wrong conclusion from it.

**Ordinal 25's raw log.** It shows the reported class↔node and chain disagreements (83 failure lines).

### L2. F2 overturned — the A6 extractor cannot emit a candidate on a closed quad complex

**Code facts at `582da20a`.**
- The A6 view builder unites edges `(0,2)` and `(1,3)` of every classed quad (`RemeshPipeline.cpp:6289-6291`), as R4 D3 §4.3 rule 7 specified ("transitive closure of the opposite-edge relation in quotient quads").
- In a quad, edges 0/2 and 1/3 are **parallel and disjoint**. The closure across a quad strip is that strip's **rung set**, a matching in which every vertex appears in exactly one rung.
- `extract_surface_quotient_simplification_candidates` (`:6343-6436`) then classifies each strip by vertex degree among its edges:
  - all degree 2 → `ClosedLoop`;
  - exactly two degree-1 vertices → `OpenStrip`;
  - otherwise `continue`.
- A rung set of `k ≥ 2` rungs has every vertex at degree 1, so `degreeOne = 2k`, and the strip is silently skipped.

On any closed manifold quad complex, every strip has at least two rungs, so the extractor returns an empty candidate set **regardless of protection**. Two consequences:
- The produced torus's empty result is a consequence of this, not a property of the fixture.
- RA-23's synthetic `4 x 4` periodic torus has four rungs per strip, `degreeOne = 8`, and **would also emit nothing**. R1 as planned (test-only, production frozen) was guaranteed to fail.

**Where the definition went wrong.** The retired arrangement extractor groups edges by `(family, strand)`, splits each group into **node-connected components**, and only then applies the same degree classification (`SurfaceComplexSimplification.cpp:1687-1740`). A strand is a field-aligned curve, i.e. an **edge chain**.

R4 §4.3 says it "replaces the old … `family/strand` grouping … with a topology-derived strip grouping". The topology-derived analogue of a strand is the **edge-loop** relation: at a regular vertex, continue through the opposite edge. Rule 7 used the quad-opposite relation instead.

R4-REV, which was mine, accepted rule 7 without checking it against the classifier it feeds, or against the strand semantics it claimed to replace. The error is shared and owned. TB11-REV's statement that "those implementations match the frozen §4.3 rules on static inspection" is true: the rule itself was wrong.

**Why the produced torus should be non-vacuous under edge loops.**
- The 18 user hard edges form one minor and one major cycle, each itself an edge loop. Those two loops are `hardFeatureProtected`.
- Every other edge loop is parallel to one of them. It crosses the other hard cycle only at a vertex, not along an edge, so it is unprotected.
- The torus has no boundary and no valence-≠-4 vertex.

So independently eligible `ClosedLoop` candidates exist, consistent with M4CP4's accepted non-vacuity on the same fixture under strand semantics.

### L3. F1 confirmed in substance; RA-21c over-relaxes (RA-21d)

TB11-REV's mechanism is plausible and consistent with the counts: about 30 chain disagreements and 35 node disagreements on a torus with thousands of quotient edges. The arrangement builds scoped node identity, so it splits nodes and edges along barrier-carried seams; A5/A6 identify those seams by relation.

But RA-21c item 5 drops chain equality for **all** quotient edges, including `Ordinary` ones, where no barrier exists. Across an `Ordinary` front with no isolation transition, adjacent proposals share one front polyline, and the arrangement merges it into one edge chain with two opposite provenance entries. The small number of runtime disagreements shows equality holds there.

Dropping it throws away the oracle's discriminating power on the majority of edges. **RA-21d** restores equality:
- for `Ordinary` edges without isolation transitions;
- for the node witness of occurrence pairs joined by such relations.

The relaxation applies only across HardRail, Periodic and isolation-seam edges.

### L4. Disposition changes

- **`M6-CP1-TB11-G4-EXEC-CAND-02`:** re-classified as a **production/definition defect**. The R4 D3 §4.3 rule-7 strip relation is incompatible with the candidate classifier.
  - Non-stable: the candidate is unpromoted, no accepted-green row was lost, and production does not yet call the A6 extractor.
  - +0 to stable accounting.
- **`...-CAND-01`:** remains a test-oracle defect (RA-21c + RA-21d).
- **R1 is re-scoped** to production + test, bounded:
  - Production: change only the A6 view's strip relation to edge-loop closure (RA-24).
  - Tests: identity 25 per RA-21c/RA-21d; identity 28 back to the produced torus (non-vacuity + tamper), with RA-23 item 1's universal checks against the edge-loop reconstruction.
  - RA-23 item 2's synthetic torus is withdrawn as a requirement; it may be kept as an extra mechanism case.
  - Protection, labels, classification and A5/A6/A7 semantics stay unchanged.

### L5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 973/973 manifest, both ledgers, ordinal 25/28 raw logs re-derived. Ordinal 28 = empty candidate set. |
| F1 | Confirmed; RA-21d restores equality on non-barrier Ordinary edges. |
| F2 | **Overturned.** Rule 7 (quad-opposite → rung sets) is incompatible with path-degree classification, so zero candidates on any closed quad complex and RA-23 item 2 would also fail. RA-24: edge-loop closure. |
| R1 plan | Re-scoped: one production change (strip relation) + test oracles. |
| Accountability | R4 D3 rule 7 accepted by R4-REV (review agent) without a classifier-invariant check. Owned. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 196 — when replacing a grouping relation, check the invariants of every downstream classifier. |
| Successor | `M6-CP1-CB11-G4-R1` (re-scoped) → TB11-R1 477 → mandatory Review. |
