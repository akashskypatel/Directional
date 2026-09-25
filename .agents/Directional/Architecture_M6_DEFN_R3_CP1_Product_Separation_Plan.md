# M6-DEFN-R3 — CP1 A6/A7 Product Separation — Definition Plan

**Turn:** `M6-DEFN-R3`
**Type:** Definition amendment and CP1 sequencing, runtime-free
**Predecessor:** `M6-CP1-TB5-REV`, review-agent addendum (`Architecture_M6_CP1_TB5_Review_Record.md` §C3-§C4)
**Successor:** mandatory `M6-DEFN-R3-REV`, then the first A6 extraction Code + Build
**Current reviewed runtime:** `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 **449/449** (TB5 456/456)

## 1. Why

Frozen §10 defines M6-CP1 as **product separation**: complete A5, **A6** and **A7** products behind stage-product APIs, with the transitional materializer reduced to a thin adapter. Frozen §8.1 adds the `G4-B002` CP1 mechanism: an A6 stage boundary that candidate extraction can consume without `hasArrangement`.

Only A5 exists today.
- No A6 or A7 product types exist.
- The 1,768-line `build_authoritative_phase_front_mesh` (`RemeshPipeline.cpp:4043-5811`) still makes every quotient and embedding decision.
- §4.4 exact-once consumption is not implemented: `:5179` `if (!unite(...)) continue;`.
- §4.3 member-set `QuotientClassId` is not realized (deferred by RA-10).

The contracts in §4-§5 are frozen. The decisions below have compatibility consequences and must be frozen, each with its reason, before extraction code is written.

## 2. Decisions to freeze

1. **CP1 exit checklist (normative).** Restate from §4/§5/§8.1/§10/§11 as an explicit, checkable list:
   - A5, A6 and A7 products and certificates exist;
   - the adapter is thin, with no semantic decision left in it;
   - exact-once ledger;
   - member-set class identity in the A6 product;
   - no coordinate/position weld;
   - the `G4-B002` A6 stage boundary;
   - the legacy `SurfaceOccurrence` `isolationSheet` / `chart` / `lattice` retired;
   - focused multi-isolation identity green;
   - selector449 449/449 on a fresh gate.
2. **Class identity representation.** *Recommended:*
   - the A6 product's semantic class identity is the sorted member `OccurrenceId` vector (a new pipeline type), per §4.3;
   - `PureQuadVertexLineage::quotientClass` (`authority::QuotientClassId` ordinal) stays an adapter-local output row (RA-10), assigned deterministically from the member-set order;
   - audit every frozen assertion over `quotientClass` or its ordering (lesson 180) before choosing the order.
3. **Exact-once ledger semantics.** Every A5 owned relation gets exactly one `QuotientRelationCertificate` (kind-specific verification: the current OrdinaryFront span/wedge/seam checks, HardRail transport, Periodic action) and exactly one ledger row.
   - Disposition is `joining` or `cycle-closing`.
   - *Recommended:* a cycle-closing relation must verify that its transport equals the composed transport of the existing selected path between its endpoints (trivial holonomy for a vertex class). A mismatch is typed `QuotientHolonomyConflict`.
   - **Prove** on the accepted fixtures (torus, cylinder/annulus, hard-rail rectangles, split square) that no accepted class closes with non-trivial holonomy. If one does, record it and choose the evidence-only alternative with reasons.
   - Unreferenced M5 relations stay decision-neutral (rows 437/448).
4. **Selected relation paths.** *Recommended:* owned by A6 as quotient-equivalence evidence and only projected by A7 lineage. Keep R2 §4.4 relation-local charts and the completion-stage re-anchoring (`PureQuadCompletion.cpp:990-1045`).
5. **A7 product.**
   - `SourceAttachedGeometryProduct`: one embedded vertex per class, from exact support.
   - `SourceSupportCertificate` / `GeometryEmbeddingCertificate` (§5).
   - The representative position rule is representation-only (the current `point` path).
   - Lineage projection: wedge-union sheets (RA-6), binding-chart union, `CornerWedgeIsolation` evidence.
   - No topology change.
6. **`G4-B002` CP1 mechanism.** Define the "A6 stage boundary": the closed-complex view derivable from the A6 product (classed quads, quotient vertices, HardRail/Periodic relation boundaries). Also define what CP1 must demonstrate, which is recommended to be a boundary adapter proved equivalent on an existing closed fixture, versus what stays with CP3 (the direct-production re-proof, §8.1). Candidate extraction currently consumes `SurfaceCellComplex` (`SurfaceComplexSimplification.h:418-426`).
7. **Failure vocabulary.** A6 and A7 typed failures, with legacy-name mapping only where a frozen test pins a string. Otherwise use distinct names or RA-12-style suffixes (lesson 181).
8. **Sequencing into bounded turns,** each with pre-registered focused identities and a gate of 7 + new identities + selector449. *Recommended:*
   - **CB6 — A6 extraction plus legacy-field retirement.** Suggested identities:
     - `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant`;
     - `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord`, including cycle-closing relations;
     - `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption`, a negative via a validation-publish seam;
     - `M6CP1.CycleClosingRelationTransportConflictRejected`, a negative.
   - **CB7 — A7 extraction and adapter thinning.** Identities for the embedding certificate and for "no position weld".
   - **CB8 — the `G4-B002` A6 stage boundary.**
   - A final CP1 closure Review checks the §2.1 checklist against the exact source and a fresh green gate.
9. **Frozen-test audit (lesson 180).** For each planned CB, list every frozen assertion it could affect and show it stays satisfiable:
   - lineage `quotientClass`, `equivalences`, `selectedRelationPaths`, hashes;
   - rows 436/437/438/444/446/448, focused 1-7, row140, and the Phase10 HardRail rows.

## 3. Must not change

A5 semantics (R1/R2/RA-1 – RA-12), `OccurrenceId`, `CellId`, relation-only equality, HardRail/Periodic owner semantics, selector449 `d4a0d1b7...d6414`, routing449 `9c88a5ed...c5707`, and all existing tests and fixtures. No source edits, compile or runtime in this turn.

## 4. Exit criteria (checked by `M6-DEFN-R3-REV`)

- §2.1-§2.9 are decided with reasons, written into `Architecture_M6_Frozen_Definitions.md`, and consistent with §4-§5 and RA-10.
- The §2.3 holonomy analysis covers every accepted periodic/HardRail fixture family.
- The CB6 plan is written with its identities pre-registered and its gate size stated.
- Accounting stays 55 / 16 / 39, debt 1.
