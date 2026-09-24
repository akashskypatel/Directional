# M6-CP1-CB1 — SurfaceOccurrenceComplex Code + Build Plan

**Turn:** `M6-CP1-CB1`
**Type:** Code + Build only
**Predecessor:** `M6-DEFN`
**Boundary:** first A5 occurrence-product cutover only; compile/package, no generated Directional runtime

## Goal

Extract occurrence creation from the transitional phase-front materializer into one complete immutable A5 `SurfaceOccurrenceComplex` producer using the exact identity rules frozen by `Architecture_M6_Frozen_Definitions.md` §§3,7. Preserve all accepted M5 behavior while making A5 authority explicit and independently consumable by later A6 work.

## Authorized implementation

1. Replace index-backed occurrence identity at the A5 public boundary with semantic `(CellId, canonicalCornerRole)` identity. Representation ordinals may exist internally only behind named projections and cannot define equality/order.
2. Introduce the immutable `SurfaceOccurrenceComplex` and `OccurrenceComplexCertificate` contracts from M6 frozen §3.
3. Move occurrence creation, cell/corner ownership, directed-side cycle publication, and A5 owned-relation endpoint publication out of inline `build_authoritative_phase_front_mesh(...)` logic into the A5 producer.
4. Change the transitional materializer only enough to consume the produced A5 object. It may continue to own the existing inline A6/A7 behavior during this CB1; do not opportunistically extract later stages.
5. Add focused compile-visible test authority for:
   - exactly four distinct occurrences per accepted cell;
   - equal lattice coordinate and equal 3D position without a relation remain distinct A5 occurrences;
   - source-row / cell-storage permutation does not rename occurrence IDs;
   - malformed/missing/duplicate relation endpoints reject at A5 without quotient repair.
6. Delete only the two dormant never-gated CB14 identities frozen for deletion in M6 §9:
   - `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact`;
   - `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`.
   Before deletion, static review must confirm their four accepted replacement identities named in §9 still exist and selector449 remains byte-identical.
7. Compile/package only through the mandatory reusable compile workflow with GMP/GMPXX. No generated Directional binary may execute.

## Explicitly not authorized

- no A6 `SurfaceQuotientProduct` extraction;
- no A7 embedding extraction;
- no A8 verifier implementation;
- no `OutputDisposition`/degradation work;
- no selector publication/change;
- no fixture/field/benchmark change;
- no M5 relation semantic change;
- no hard-feature/isolation-sheet reclassification;
- no coordinate/position weld;
- no fallback/recovery behavior change;
- no G4 blocker/debt closure claim.

## Verification before compile

Static/compile authority must establish:

1. no A5 semantic equality references world position, lattice coordinate, container row, output row, scheduler order, hash, or representative sheet;
2. `build_authoritative_phase_front_mesh(...)` obtains occurrences/cell-side authority from `SurfaceOccurrenceComplex` rather than allocating semantic A5 IDs itself;
3. A5 does not union occurrences or choose quotient representatives;
4. the two deleted CB14 identities are absent and each named accepted replacement remains present;
5. selector449 LF SHA-256 remains exactly `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.

## Code + Build outputs

Compile/link the standard approved Directional targets using the durable reusable compile workflow, package exact source and evidence, verify clean source receipts and GMP/GMPXX linkage, and require `runtimeExecution=false`.

The produced package is a **candidate only**. It receives no M6 semantic credit until a separate artifact-only TB executes the new A5 focused identities plus the unchanged accepted selector authority and a mandatory Review adjudicates the result.

## Falsifiers / stop rules

Stop and return to Review/definition if any implementation requires:

- occurrence equality by coordinate/position or sequential storage rank;
- changing A4 `CellId` semantics or accepted M5 relation identity to make A5 work;
- union/quotient decisions inside A5;
- rewriting A6/A7/A8 in the same turn;
- validator weakening, source-grid recovery, fallback, or hard-feature sheet splitting;
- editing an accepted selector or replacing either dormant CB14 identity with a weaker new test;
- executing any generated Directional runtime in Code + Build.

A compile failure may be repaired only when the correction is bounded to this authorized A5 seam and remains runtime-free. Otherwise stop.

## Success criterion

CB1 completes only when the A5 product/certificate seam is compile/package green, static identity checks pass, the transitional materializer consumes A5 authority without later-stage refactor, the two dormant CB14 identities are removed under their frozen supersession proof, all package evidence is complete, and no generated Directional runtime has executed.
