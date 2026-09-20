# M5-CP3-CB1 Independent Architecture Review Record

**Turn:** `M5-CP3-CB1-REV`
**Mode:** independent Review + Plan / runtime-free
**Reviewed stop:** `M5-CP3-CB1` static stop before implementation or compile
**Accepted runtime authority:** package `10601978228` / semantic source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Decision:** **APPROVED WITH AMENDMENTS — CB1 STOP UPHELD; REPLACEMENT `M5-CP3-CB2` AUTHORIZED**
**Authoritative next plan:** `Architecture_M5_CP3_CB2_Direct_Production_Promotion_Plan.md`

## 1. Review question and boundary

CB1 stopped at a real contract collision on the accepted row408-class one-region torus. The same A3 hard-feature cut copies that row408 currently observes as final `HardRail` edges must become same-region quotient identifications to satisfy M5-CP3. Keeping them as `HardRail` makes the downstream materializer reject same-region hard-rail transport; changing them to `PeriodicCut` under the current checked factory makes the exact A3 `sharedBoundaryInterval` illegal. CB1 therefore correctly stopped before changing product/test bytes or compiling.

This Review is runtime-free. It does not change production, test, fixture, selector, benchmark or build logic. It re-derives the representation conflict from source and decides which semantics the replacement Code + Build is authorized to implement.

## 2. Independent source re-derivation

### 2.1 Row408 owns the input cut graph and exact A3 provenance, not a permanent final `HardRail` representation

Accepted selector430 row408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, independently proves that the effective production hard-feature authority equals the exact **18** source edges of the accepted torus cut graph before it inspects the phase-front product. It also binds the phase front to accepted A2b/A3 digests. Its final loop currently filters `SurfaceFrontBoundaryKind::HardRail` and requires `sharedBoundaryInterval` on those edges.

The first two facts are the semantic precondition M5 inherits. The final `HardRail` filter is an implementation representation of the M4 product. `DESIGN.md` §14 explicitly permits a vertical semantic-contract replacement on this experimental branch and says prior incomplete product representation is not a design requirement. M5's own acceptance requires direct torus **quotient** evidence and forbids hard-rail substitution for the inherited periodic debts.

### 2.2 `SurfaceSharedBoundaryInterval` is A3 provenance and is structurally separate from final quotient ownership

`SurfaceSharedBoundaryInterval` carries an A2b `NetworkArcId`, exact ordinal endpoints, orientation, and optional exact cut-boundary occurrence. `SurfaceFrontEdge` stores that object separately from `boundaryKind`, `periodicRelation`, and `railId`. The A4 pairing code already uses the interval and distinct `boundaryOccurrence` values to identify the two exact chart copies of one shared cut before publishing `oppositeEdge`.

The current header comment calls it a shared hard-rail interval because HardRail is the only current consumer. That comment describes current representation, not a reason the A3 fact ceases to exist after a later stage classifies the already-paired same-region cut as a periodic quotient. The exact span/ordinal/occurrence provenance remains true after promotion and should remain available as provenance.

### 2.3 Same-region paired hard-rail copies are the periodic promotion seam

At the A4 merge seam, hard-rail groups are keyed by source component, exact A3 span/ordinal interval and canonical route content. A pair is accepted only when its intervals are reciprocal, routes reverse, families match, advance signs oppose, and—when both copies live in the same `sourceTopologyRegion`—the two exact `boundaryOccurrence` values are present and distinct.

That is the discriminating condition the replacement turn must use. It is stronger than “same region”: it proves the pair is two exact cut-open chart occurrences of one upstream A3 cut. Cross-region hard-rail pairs remain ordinary hard-rail merges.

### 2.4 The checked factory can preserve A3 provenance without weakening CP2 periodic authority

`SurfacePhaseFrontProduct::make(...)` currently validates `sharedBoundaryInterval` before periodic ownership. Its only architectural conflict is the first kind predicate: interval presence currently requires `HardRail`. The remainder of that validation already checks exact unit ordinal span, orientation, reciprocal opposite span, opposite ordinals/orientation, and distinct boundary occurrences.

After that block, a `PeriodicCut` independently must have a canonical relation owner; paired periodic edges must share that owner, carry reverse routes, use the owner's cut-route carrier, and satisfy the owner's full `GridAutomorphism` (lattice coordinate, quarter-turn branch rotation, and scale) or its inverse. Therefore permitting exact A3 interval metadata on a promoted `PeriodicCut` does **not** allow provenance to substitute for periodic ownership or reciprocity. The CP2 checks remain the operative quotient guard.

### 2.5 The materializer boundary confirms `HardRail` and `PeriodicCut` are different operative semantics

The materializer rejects a paired `HardRail` when the pair has the same `sourceTopologyRegion`; its hard-rail branch represents a feature relation between distinct source regions. Its `PeriodicCut` branch, by contrast, requires one periodic relation owner in the same source region, a cut route and reciprocal full action/inverse lattice mapping, and then publishes periodic-holonomy equivalence.

The replacement must therefore **not** weaken the same-region hard-rail rejection. It must classify the exact same-region A3 cut copies as `PeriodicCut` before checked product construction/materialization. A dual-kind workaround is neither representable nor desirable.

## 3. Architecture adjudication

The CB1 stop is upheld and the architecture is frozen as follows.

1. **A3 provenance survives promotion.** `SurfaceSharedBoundaryInterval` is exact upstream provenance. It may be carried by a final `HardRail` or by a same-region A3 cut that A4 promotes to `PeriodicCut`.
2. **Promotion is narrow.** Only an already-valid paired hard-rail group whose two edges have the same `sourceTopologyRegion` **and** distinct exact A3 `boundaryOccurrence` values is eligible. Cross-region pairs remain `HardRail`.
3. **Periodic authority is independent and mandatory.** A promoted pair must receive a checked `SurfacePeriodicHolonomy` and canonical `PeriodicRelationId`; `sharedBoundaryInterval` never substitutes for `periodicRelation`.
4. **Relation identity is still content-derived.** For each promoted relation, obtain the generator carrier from the A2b/A3 owning `NetworkArcId`/exact source-path authority and the cut carrier from the produced paired-edge canonical route. Do not derive identity from vector position, edge number, group order, `HardRailId`, or insertion order.
5. **Relation value is exact full transport.** Build the action from authoritative route/atlas and exact chart-lattice correspondence. Rotation and translation are both semantic value. One action must map both reciprocal endpoint-state pairs exactly before publication. Do not invent a nonzero turn to satisfy the M5 witness.
6. **Exact duplicates may coalesce; conflicts fail.** Multiple unit intervals of the same canonical relation may point to one identical relation object. Same identity with a different value remains the CP2 `ConflictingPeriodicRelation` case.
7. **Final event semantics follow final edge semantics.** Promoted pairs publish `PeriodicFrontMerge`; unpromoted cross-region pairs publish `HardRailMerge`.
8. **Source rail provenance may remain provenance.** Existing `railId` may remain attached to a promoted edge as upstream hard-feature provenance, but it is not the operative quotient owner and no periodic consumer may use it instead of `periodicRelation`.
9. **The materializer hard-rail rule is unchanged.** Same-region `HardRail` remains invalid. No M5 implementation may weaken that branch to preserve row408's old final-kind assertion.

This adjudication is written normatively into `Architecture_M5_Frozen_Definitions.md` §14.

## 4. Row408 accepted-test authority

A surgical body evolution of row408 is **authorized and required**. This is not permission to retarget the witness or weaken its accepted precondition.

The unchanged parts are:

- test identity and selector430 row position;
- committed `torus` fixture and production helper;
- exact **18-edge** effective hard-feature cut graph equality;
- A0/A1/A2/A3 production path and `Produced` requirement;
- conformity-plan receipt and digest binding;
- fail-closed `InvalidHardRailPairing` protection.

Only the final representation assertion changes. On this one-source-region torus, exact A3 shared-boundary intervals that survive into the final phase front must be observed on **promoted `PeriodicCut` pairs**, not required to remain `HardRail`. The evolved row must require a non-empty reciprocal periodic provenance set (at least one full pair / at least two edges), and every such edge must retain its exact interval, exact distinct opposite occurrence, canonical `periodicRelation` owner and reverse-route pairing. A broad “some interval exists” assertion is insufficient.

Existing HardRail-specific positive/negative tests remain responsible for cross-region hard-rail behavior and malformed shared-interval rejection. Row408 remains a production provenance witness, not one of the six M5 debt rows.

Because row408 is already in selector430, the later CP3 artifact-only gate must execute selector430 completely on the candidate. No body edit is accepted by compilation alone.

## 5. Relation construction constraints for CB2

The replacement implementation must not guess a basis by storage order. For each eligible pair:

1. resolve the interval's `span` through the accepted `GlobalTopologyPlan` and use its exact canonical `sourcePath` as the upstream generator-carrier authority;
2. convert that source-path authority through existing source-transition / `FieldTransportAtlas` facts into one canonical generator route; do not reconstruct a path from floating geometry;
3. use the already paired edge canonical route as the cut route, requiring the opposite to be its reverse;
4. derive the relation action from the authoritative generator-route rotation plus exact paired chart-lattice correspondence, then require the same full automorphism (or its inverse by orientation) to satisfy both endpoint pairs;
5. call the checked `SurfacePeriodicHolonomy::make(...)`, insert through the canonical relation insertion path, bind both edges to the resulting canonical ID, and preserve the exact A3 interval on both copies.

If the accepted authority does not contain enough exact information to construct both carrier routes or one consistent full action, CB2 must stop. It may not fall back to `HardRail`, a direct helper, edge-order identity, synthetic relation injection, or M6 occurrence authority.

## 6. Frozen produced evidence and gate sequence

The six existing names remain unchanged:

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

CB2 also preserves the nine reviewed CP1/CP2 mechanism identities in frozen §13.2. The first runtime remains: nine mechanism rows, then these six produced rows, then selector430; fresh exact-filter process per identity, exact-one/zero-skip, benchmark **0**, immutable artifact-only execution. Selector430 remains byte-frozen through CB2 and that first runtime.

## 7. Prior obligations

- `M5-DEFN-REV-OBS-01` — **DISCHARGED.** Frozen §13.1 now states one reconciled M5 exit theorem tying `DESIGN.md` §14 to §§8-9, all four produced debts, the `>=2` discriminator, mechanism-only prohibition and publication gate. Final M5 Review still must prove every conjunct; the missing-theorem observation itself is closed.
- `M5-CP1-TB1-PREFLIGHT-REV-OBS-01` — **DISCHARGED AS GOVERNANCE/NAMING GAP.** Frozen §13.4 and the six `M5CP3.Produced...` names make produced identities unambiguously distinct from accepted direct/helper rows 218/220/221/226 before any produced re-proof is published. Production credit still requires the CP3 runtime/Review.
- `M5-CP2-TB1-REV-OBS-01` — **CARRIED UNCHANGED to `M5-CP3-TB1-REV`.** Exact successor-selector bytes/order/hash/owner census cannot be pre-committed until the six produced identities compile and are independently reviewed green on the pre-publication runtime.

No new stable regression is created. CB1 stopped before implementation, compile or runtime; accepted package `10601978228` and selector430 remain green authority. Stable accounting stays **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 8. Decision and successor

**Decision: `approved_with_amendments`.** The CB1 stop was correct. The old plan is superseded by `Architecture_M5_CP3_CB2_Direct_Production_Promotion_Plan.md`, which implements the narrow A3-provenance-preserving `HardRail` → `PeriodicCut` promotion and the existing six produced evidence identities. Exact successor: **`M5-CP3-CB2`**.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 = `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 = `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 rows / byte-identical accepted prefix. |
| Decisive claims independently re-derived | Row408 exact 18-edge precondition and final HardRail assertion; A4 same-region distinct-occurrence pairing; factory shared-interval + CP2 periodic checks; materializer HardRail/PeriodicCut split; DESIGN §14 transition rule. |
| Non-vacuity checked | Promotion is gated by same-region + distinct exact boundary occurrences; row408 must observe a real reciprocal promoted pair; six produced rows retain `>=2` relation/edge and nonzero-Z4 discriminators. |
| Prior obligations discharged/carried | `M5-DEFN-REV-OBS-01` discharged; `M5-CP1-TB1-PREFLIGHT-REV-OBS-01` discharged; `M5-CP2-TB1-REV-OBS-01` carried to `M5-CP3-TB1-REV`. |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10601978228` / source `0798547d...`; selector430 unchanged. |
| New candidates/obligations recorded | `M5-CP3-CB1-REV-OBS-01` records the non-stable representation-contract stop and its normative §14 resolution; tracker updated. |
| ORIENTATION currency line | `M5-CP3-CB1-REV`, 2026-09-20 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated: CP3 stop/review state, torus witness status, CB2 priority, and representation-promotion instance; stale CB1-next text removed. |
| CHANGELOG | Review entry added. |
| ROADMAP | CP3 advanced from CB1 stopped/review to reviewed `M5-CP3-CB2` successor. |
| Selector manifest | n/a — no selector bytes were added, changed or accepted in this Review. |
| LESSONS | Existing lessons 22h (binding stop), 22k (architecture settles representation), 22e (convert every consumer), and §4 single-authority rules cited; no new pattern added. |
| Consolidation under CLEAN_UP_POLICY | Superseded CB1 plan and stop record folded into `M5_Consolidated_Record.md`; current Review and CB2 plan retained. |
| Successor frozen | `M5-CP3-CB2`; falsifiers and stop rules are in `Architecture_M5_CP3_CB2_Direct_Production_Promotion_Plan.md` §§8-9. |
| Turn boundary held | runtime-free; no product/test/fixture/selector/benchmark/build mutation. |
| review_check.py boundary | **ALL CHECKS PASSED** with selector430 exact-hash expectation on the local review patch. |
| `STATUS` lifecycle maintained | `M5-CP3-CB1-REV`; final direct beacon is written after durable docs + cleanup, with exact successor `M5-CP3-CB2` and preserved start/resume times. |
| Pushed to origin, branch in sync | Confirmed during closeout after patch application/cleanup by remote branch authority; no local implementation branch state is used as evidence. |
