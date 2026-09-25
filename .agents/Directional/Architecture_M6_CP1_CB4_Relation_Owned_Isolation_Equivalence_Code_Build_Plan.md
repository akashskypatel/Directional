# M6-CP1-CB4 Corner-Wedge Isolation Authority Code + Build Plan

> **HELD — `M6-DEFN-R1-REV` did not accept DEFN-R1 as frozen. Do not execute; `M6-DEFN-R2` must revise this plan.**
> As written it would be RED by construction: focused row5 requires non-empty `equivalences` on the v0/v2 `{0,1}` lineage (B1).
> It also leaves unspecified the binding selection for the transitional class key, `representative_key`, selected-path charts and `sourceCharts` (B2).
> Its Scope B collinear rule names only the lexicographic tie-break; the split-square builder `segment_on_source` ties by face row (B3).
> Its Scope C removes duplicate checks although A5's `UnownedRelation` is many-to-one, contradicting §4.6 (B4).
> See `Architecture_M6_DEFN_R1_Review_Record.md` and `Architecture_M6_DEFN_R2_Amendment_Plan.md`.

**Turn:** `M6-CP1-CB4`
**Type:** Code + Build, runtime-free
**Predecessor:** accepted `M6-DEFN-R1-REV` only
**Accepted runtime authority:** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Recovery candidate basis:** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**If compile-green successor:** `M6-CP1-TB4-EXEC`, then mandatory `M6-CP1-TB4-REV`

## Goal

Implement only the accepted `M6-DEFN-R1` seam-incident authority cutover: complete corner-wedge sheet/certificate authority, exact directed-side seam evidence including seam-collinear sides, per-wedge face/chart/branch provenance, and A6 consumption of those A5-published facts. Remove only the duplicate downstream relation-owner checks explicitly transferred to A5.

No generated Directional runtime is permitted in CB4.

## Scope A — A5 occurrence wedge authority

For every occurrence, derive and publish from accepted A4 canonical cell cycle plus exact source topology:

- sorted non-empty `CornerWedgeSheetSet`;
- ordered/per-face `CornerWedgeFaceBindings` with source-face topology identity, sheet, field chart and branch rotation;
- `CornerWedgeIsolationEvidence` keyed by exact `(TopologyRegionId, SourceEdgeTopologyKey)` for every seam edge crossed by the wedge fan.

Occurrence-wide support/identity/lattice values stay occurrence-wide. Face-dependent chart/branch/sheet values must not be taken from a single representative face.

A missing, duplicate, inconsistent, noncontiguous, or uncertified required wedge authority fails closed with an `Occurrence*` A5 error.

## Scope B — directed-side source/seam authority

For every directed side, publish the exact incident-cell interior-side source authority and ordered isolation evidence.

- Non-collinear segments use their exact source route and checked seam crossings.
- A seam-collinear segment chooses the incident source face lying on the owning cell's interior side by exact chart orientation; the lexicographically smallest triangle may remain a representation leaf but cannot be semantic authority.
- Reciprocal seam-collinear ordinary sides must name the same seam certificate and opposite certificate sheets.

Do not infer side authority from world position, epsilons, row order, or certificate inventory size.

## Scope C — A5 relation validation and compatibility naming

Keep `OrdinaryFront` owner-less and keep `OccurrenceRelationId` unchanged. Preserve HardRail/Periodic owners.

Rename A5's externally reported HardRail structural-owner mismatch to `OccurrenceHardRailOwnerMismatch`. Preserve selector row140's legacy `InvalidHardRailTransport` only through the transitional M5-compatible adapter mapping.

Once A5 validates relation kind/owner structure, remove the duplicate structural branches for:

- `MissingHardRailRelationOwner`;
- owner-presence/equality part of `InvalidPeriodicRelationOwner`;
- boundary-kind compatibility part of `IncompatibleAuthoritativeFrontPair`.

Do not remove route/transport/content validation.

## Scope D — A6 consumes only A5-published wedge/side evidence

For every non-collinear ordinary endpoint pair, verify the incident side sheet belongs to both endpoint wedge sets. For side-interior seam crossings, verify exactly the A5-published ordered seam references. For seam-collinear reciprocal sides, verify the common seam certificate plus the two opposite incident-side sheets.

A6 may not search global certificate inventory, infer from geometric/lattice coincidence, or reconstruct semantic authority from raw boundary-path traversal. Only verified A5 owned relations may union occurrences.

A7 lineage publication must use the union of member wedge sheet sets and the certificate evidence actually verified by A6.

## Required static derivation before editing

Record in the CB4 report:

1. split-square v0/center/v2 wedge derivation and certificate orientation;
2. one source-vertex fan crossing two seam edges with the same sheet pair;
3. one seam-collinear directed side and the exact incident-cell interior-face derivation;
4. exact old A5 → adapter → materializer failure flow for row140;
5. exact duplicate downstream branches removed versus transport/content branches retained.

If any derivation is not unique from typed source authority, stop for Review/Definition.

## Frozen validation surface

Existing tests/fixtures and selector/routing files stay unchanged. Preserve exact selector449 LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

Frozen focused order for TB4:

1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
2. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
3. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
4. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`
7. **new in CB4:** `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`

The new identity must assert at least split-square v0 and v2 `{0,1}` authority plus their exact wedge seam-certificate orientations. Do not weaken existing focused identities to make the new contract pass.

## Falsifier and stop rule

Stop without a speculative patch if implementation would require any of the following: representative-face occurrence authority; global certificate search; geometric/lattice welding; relation-owned isolation owner for OrdinaryFront; change to `OccurrenceId`, `CellId`, `QuotientClassId`, relation-only equality, HardRail/Periodic owner semantics, selector449/routing449, or any existing test/fixture; or weakening row140 transport semantics.

## Compile/package gate

Compile/package exactly the standard eight targets through `agent-compile-reusable.yml` with mandatory GMP/GMPXX: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Require `DIRECTIONAL_ENABLE_GMP=ON`, generated link evidence for `gmpxx` and `gmp`, `exactArithmeticBackend=GMP`, clean source receipts, complete recursive manifest and `runtimeExecution=false`. No Directional test, benchmark, discovery, CLI/help/version, or other generated runtime may execute.

## TB4 pre-registration

Compile-green advances to immutable `M6-CP1-TB4-EXEC`, consuming the exact artifact with **7 focused + selector449 = 456 fresh exact-filter processes**, exact-one selection, zero skips, benchmark 0, then exact immutable postflight.

Recovery-green is **456/456 PASS** and includes: no `OccurrenceInvalidCornerAuthority`; v0/v2 complete wedge authority; selector row140 PASS with legacy `InvalidHardRailTransport` surface; selector ordinals 186/214/239/444/446/448 recovered; focused multi-isolation lineage complete; pair-swap PASS.

Any mechanically valid RED is preserved and routed directly to mandatory `M6-CP1-TB4-REV`; TB4 does not repair or rerun. CB4 grants no promotion, stable-event recovery, CP1 closure, or debt credit.
