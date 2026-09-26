# M6-CP1-CB6-A6 — quotient-product extraction + legacy A5 field retirement — Code + Build plan

**Status:** AUTHORIZED by `M6-DEFN-R3-REV`; RA-1 – RA-4 binding
**Turn:** `M6-CP1-CB6-A6`
**Predecessor:** `M6-DEFN-R3-REV`
**Type:** source/test Code + Build; compile/package only; no generated Directional runtime
**Frozen definition:** `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md` as amended by `Architecture_M6_DEFN_R3_Review_Record.md` and `Architecture_M6_Frozen_Definitions.md`

## 1. Goal

Extract the already-frozen A6 quotient semantics from `build_authoritative_phase_front_mesh(...)` into an immutable `SurfaceQuotientProduct` / `SurfaceQuotientProducer`, while preserving accepted A5 **semantics** and transitional A7/output behavior. RA-3 permits only the evidence-carrier enrichment required to make the existing A5→A6 boundary self-sufficient; it does not permit a relation-identity/equality/ownership change. In the same bounded cutover, retire the three unread A5 representative fields `SurfaceOccurrence::{chart,lattice,isolationSheet}`. Do not extract A7 and do not implement the `G4-B002` stage boundary in this turn.

## 2. Required product surface

Introduce compile-visible A6 types sufficient to represent, without consulting the materializer afterward:

- `SurfaceQuotientClassId` — sorted unique non-empty member `OccurrenceId` set;
- `SurfaceQuotientClass` — semantic ID/member set plus classed cell incidence needed by A7;
- `QuotientRelationCertificate` — one per A5-owned relation, always oriented `relation.id.first -> relation.id.second`, with exact canonical relation transport and evidence;
- `QuotientRelationConsumption` — one per A5-owned relation, `Joining` or `CycleClosing`;
- deterministic selected relation forest/path certificates owned by A6;
- `QuotientCertificate` and `MaterializationCertificate`;
- `SurfaceQuotientProductErrorCode` from R3 §7;
- `SurfaceQuotientProduct` immutable accessors;
- `SurfaceQuotientProducer::produce(...)` plus a focused validation-publication seam for malformed-ledger negative tests only.

Keep `authority::QuotientClassId` out of A6 semantic identity. The transitional adapter assigns it deterministically from A6 member-set order solely for `PureQuadVertexLineage::quotientClass` compatibility.

### 2.1 Binding Review amendment — A5 relation evidence completeness

The A5 relation record may be enriched only enough to make the already-frozen A5→A6 boundary self-sufficient. For every A5-owned relation publish immutable evidence from which A6 can validate the canonical `relation.id.first -> relation.id.second` certificate without dereferencing `firstFrontEdge` / `secondFrontEdge` or any global phase-front representation table. This enrichment does not change A5 relation identity, equality, owner selection, accepted relation set, or cell topology.

- OrdinaryFront canonical quotient transport is identity; isolation seam transitions remain validating evidence only.
- HardRail carries/references its exact accepted owner/route/transport normalized to canonical relation direction.
- Periodic carries/references its exact semantic owner action plus required route/cut evidence normalized to canonical relation direction.
- SingularityPort remains unsupported.

`firstOccurrence` / `secondOccurrence` and `firstFrontEdge` / `secondFrontEdge` are representation provenance and cannot select semantic certificate direction or transport. If satisfying this requirement would change A5 relation semantics rather than enrich evidence, stop and return to Review.

## 3. Exact-once algorithm

1. Consume only A5 `owned_relations()`; canonicalize processing by `SurfaceOccurrenceRelationId`. Every certificate direction is `relation.id.first -> relation.id.second`, never the storage-oriented `relation.firstOccurrence -> relation.secondOccurrence`.
2. Reuse the current accepted OrdinaryFront span/wedge/seam, HardRail and Periodic authority checks behind A6, consuming the evidence-complete A5 relation record. OrdinaryFront relation transport is identity; seam quarter-turn evidence is not reapplied as quotient transport.
3. Emit exactly one `QuotientRelationCertificate` and one `QuotientRelationConsumption` for each owned relation. Normalize HardRail/Periodic transport to the canonical certificate direction, inverting exact evidence when required.
4. Joining relations form the selected forest and union the endpoint classes.
5. Cycle-closing relations are never skipped. Traverse the unique selected-forest path from `a` to `b` with `path=identity`; for each traversal transform `T` (inverse when traversed opposite its certificate direction), set `path=compose(T,path)`. Require exact `directRelationTransport == path`; mismatch -> `HolonomyConflict` / external `QuotientHolonomyConflict`.
6. Build semantic classes from the verified transitive closure and identify them by sorted member sets.
7. Publish classed quads one-to-one with A5 cells and validate partition/materialization certificates before returning Produced.
8. Project A6-selected HardRail/Periodic paths to the existing lineage compatibility surface. Ordinary-only paths remain A6 evidence and do not populate legacy `selectedRelationPaths`.

No arbitrary relation-subset search, geometry/lattice coincidence union, positional weld, or fixture-specific branch is permitted.

## 4. A5 field retirement folded into this CB

Remove only unread `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet` and their constructor/call-site arguments. Keep all live semantic fields and authorities: `id`, `point`, `support`, `chartComponent`, `topologyRegion`, `cornerWedgeSheets`, `cornerWedgeBindings`, `placement`, `cornerWedgeIsolation`, cells, directed side authority and owned relations.

If implementation discovers a live semantic consumer of any of the three fields, stop and return to Review; do not recreate it under another name.

## 5. Transitional adapter boundary

After the cutover, the quotient portion of `build_authoritative_phase_front_mesh(...)` must call `SurfaceQuotientProducer` and consume the immutable A6 product. It may still perform A7 geometric representative selection/source attachment and final output assembly until the later A7 CB, but it may not:

- union occurrences;
- validate/select relation ownership/transport;
- choose cycle edges or selected relation paths;
- invent class identity;
- repair/mutate the A6 partition or ledger.

Keep completion-stage selected-path re-anchoring unchanged.

## 6. Pre-registered focused tests

Add exactly these four identities to the producer-test target:

1. `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant`
   - semantic IDs equal their exact sorted source-occurrence member sets;
   - relation/cell/source-face storage permutations preserve the member-set IDs;
   - reciprocal front-edge storage swap and the other storage permutations preserve canonical relation-certificate endpoint direction and transport signature;
   - adapter ordinals may be inspected only as deterministic projection rows.
2. `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord`
   - certificate and ledger IDs are exact bijections with A5-owned relation IDs;
   - includes at least one test-constructed cycle-closing relation so the old `if (!unite(...)) continue;` behavior would fail non-vacuously.
3. `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption`
   - use only the A6 validation-publication seam;
   - independently tamper missing, duplicate and disposition/certificate-conflicting consumption and require the matching typed code;
   - no fabricated passing ledger.
4. `M6CP1.CycleClosingRelationTransportConflictRejected`
   - construct an individually valid certified A5/A6 relation cycle;
   - through the A6 validation-publication seam, alter exactly one otherwise admissible direct cycle-closing certificate transport; do not fabricate an invalid OrdinaryFront transport;
   - require `HolonomyConflict` while the untampered cycle publishes.

No existing test or fixture is weakened or rewritten to obtain green output.

## 7. Frozen-test preservation and TB falsifier

The R3 definition-record §10 audit is binding. In particular preserve:

- entering focused rows 1-7;
- selector row140;
- rows 186/214/239;
- selected-path rows 436/437/438 and torus rows 444/446/448/449;
- cylinder row232;
- Phase10 HardRail/hard-feature sheet authority including row240;
- relation-local chart/component selected-path semantics;
- unchanged selector449/routing449 bytes.

The first artifact-only TB after compile-green executes **11 focused + selector449 = 460** exact-filter processes. Row232 and torus 444/446/448/449 are pre-registered falsifiers for the strict cycle-closing transport rule. If any first-fails as `QuotientHolonomyConflict`, TB does not retry or weaken; mandatory Review adjudicates the rule versus legitimate residual holonomy as frozen in R3 §5.4.

## 8. Build boundary

Code + Build only:

- apply the exact source/test patch;
- mandatory GMP/GMPXX configuration;
- compile/link the standard eight approved targets under PRE_TEST/equivalent compile-only discovery mode;
- package source, binaries, manifest and compile evidence with `runtimeExecution=false`;
- no generated Directional binary/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input runtime.

Compile failure may be corrected only within this exact A6/legacy-field scope. No selector or fixture mutation is authorized.

## 9. Exit

Compile/package green -> immutable `M6-CP1-TB6-A6-EXEC` over the 460-process gate -> mandatory `M6-CP1-TB6-A6-REV`.

CB success is not A6 semantic acceptance, CP1 closure, A7 authorization, `G4-B002` credit, accounting change, or debt discharge.
