# M6-CP1-CB6-A6 — quotient-product extraction + legacy A5 field retirement — Code + Build plan

**Status:** HELD pending `M6-DEFN-R3-REV` acceptance
**Turn:** `M6-CP1-CB6-A6`
**Predecessor:** `M6-DEFN-R3-REV`
**Type:** source/test Code + Build; compile/package only; no generated Directional runtime
**Frozen definition:** `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md`

## 1. Goal

Extract the already-frozen A6 quotient semantics from `build_authoritative_phase_front_mesh(...)` into an immutable `SurfaceQuotientProduct` / `SurfaceQuotientProducer`, while preserving the accepted A5 product and transitional A7/output behavior. In the same bounded cutover, retire the three unread A5 representative fields `SurfaceOccurrence::{chart,lattice,isolationSheet}`. Do not extract A7 and do not implement the `G4-B002` stage boundary in this turn.

## 2. Required product surface

Introduce compile-visible A6 types sufficient to represent, without consulting the materializer afterward:

- `SurfaceQuotientClassId` — sorted unique non-empty member `OccurrenceId` set;
- `SurfaceQuotientClass` — semantic ID/member set plus classed cell incidence needed by A7;
- `QuotientRelationCertificate` — one per A5-owned relation with exact relation-oriented transport and evidence;
- `QuotientRelationConsumption` — one per A5-owned relation, `Joining` or `CycleClosing`;
- deterministic selected relation forest/path certificates owned by A6;
- `QuotientCertificate` and `MaterializationCertificate`;
- `SurfaceQuotientProductErrorCode` from R3 §7;
- `SurfaceQuotientProduct` immutable accessors;
- `SurfaceQuotientProducer::produce(...)` plus a focused validation-publication seam for malformed-ledger negative tests only.

Keep `authority::QuotientClassId` out of A6 semantic identity. The transitional adapter assigns it deterministically from A6 member-set order solely for `PureQuadVertexLineage::quotientClass` compatibility.

## 3. Exact-once algorithm

1. Consume only A5 `owned_relations()`; canonicalize processing by `SurfaceOccurrenceRelationId`.
2. Reuse the current accepted OrdinaryFront span/wedge/seam, HardRail and Periodic authority checks; move those semantic checks behind A6 instead of duplicating them in the adapter.
3. Emit exactly one `QuotientRelationCertificate` and one `QuotientRelationConsumption` for each owned relation.
4. Joining relations form the selected forest and union the endpoint classes.
5. Cycle-closing relations are never skipped: compose the unique selected-forest path transport and require exact equality with the direct relation transport; mismatch -> `HolonomyConflict` / external `QuotientHolonomyConflict`.
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
   - adapter ordinals may be inspected only as deterministic projection rows.
2. `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord`
   - certificate and ledger IDs are exact bijections with A5-owned relation IDs;
   - includes at least one test-constructed cycle-closing relation so the old `if (!unite(...)) continue;` behavior would fail non-vacuously.
3. `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption`
   - use only the A6 validation-publication seam;
   - independently tamper missing, duplicate and disposition/certificate-conflicting consumption and require the matching typed code;
   - no fabricated passing ledger.
4. `M6CP1.CycleClosingRelationTransportConflictRejected`
   - construct a valid A5/A6 relation cycle, alter exactly one direct cycle-closing transport, and require `HolonomyConflict` while the untampered cycle publishes.

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
