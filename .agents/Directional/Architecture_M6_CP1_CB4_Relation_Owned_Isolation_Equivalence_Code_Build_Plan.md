# M6-CP1-CB4 Relation-Owned Isolation Equivalence Code + Build Plan

**Turn:** `M6-CP1-CB4`
**Type:** Code + Build, runtime-free
**Predecessor:** `M6-CP1-TB3-REV`
**Accepted runtime authority:** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Recovery candidate basis:** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**If compile-green successor:** `M6-CP1-TB4-EXEC`, then mandatory `M6-CP1-TB4-REV`

## Goal

Correct exactly one Review-proved implementation gap: A5 must explicitly publish the accepted isolation-seam certificate authority that owns an ordinary occurrence relation when its endpoints span isolation sheets, and the transitional A6/materializer must consume that relation-owned reference. Do not infer semantic relation ownership later from front-edge/boundary-path representation traversal.

This implements the already-frozen `SurfaceOccurrenceComplex.ownedRelations[].typed relation owner / certificate reference` obligation. It does **not** redefine A5/A6/A7 semantics.

## Required static derivation before editing

For each TB3 failing subject, trace at least one cross-sheet `OrdinaryFront` relation from:

1. the two A5 `OccurrenceId` endpoints and their exact `SourceSupport` / `IsolationSheetId` values;
2. the accepted A4/M5 source relation and checked `SurfaceIsolationSeamTransportCertificate` authority available to A5;
3. the unique certificate identity that authorizes equality of those endpoint sheet representations;
4. the A5 relation record that must carry that identity; and
5. the A6/transitional consumer that verifies and consumes it exactly once.

Record the derivation in the CB4 report. The derivation must not use output position, lattice coincidence, output lineage, test names, selector ordinals, global certificate-count inventory, or a search for any certificate that merely makes the consumer pass.

## Scope A — publish relation-owned isolation certificate authority at A5

Add the minimum typed field/value needed for an `OrdinaryFront` A5 owned relation to name the exact checked isolation-seam certificate when its resolved occurrence endpoints cross sheets. Prefer semantic source authority such as the certificate's region + canonical seam identity (or an equivalent already-typed certificate reference); raw source-face rows, phase-front vector indices, and `firstFrontEdge/secondFrontEdge` remain representation leaves and are not certificate identity.

Required invariants:

- the existing `OccurrenceId = (CellId, canonicalCornerRole)` contract is unchanged;
- CB3 outgoing-directed-side occurrence sheet authority is unchanged;
- every occurrence keeps exactly one typed `IsolationSheetId` and exact `SourceSupport`;
- relation endpoints remain the existing explicit A5 endpoint pairs;
- a cross-sheet ordinary relation is publishable only when exactly one already-accepted typed certificate authority proves that equivalence for the relation; zero or ambiguous authority fails closed with a typed A5 error;
- HardRail and Periodic relation owners remain unchanged;
- geometric position, lattice equality, certificate inventory size and downstream output state are forbidden as owner selectors.

Do not broaden A5 by copying the whole certificate table into every relation. Publish only the exact owner/reference needed by that relation.

## Scope B — consume only the A5 relation-owned reference

At the transitional A6/materializer seam, construct ordinary equivalence provenance from the verified A5 relation-owned certificate reference. Verify that the named certificate exists exactly once, belongs to the relation's topology region, has the endpoint sheet pair required by the relation, and satisfies its already-checked reciprocal transport contract before union.

The existing `isolationSeamsByFrontEdge` / `boundaryPaths[*].entryRoute` traversal may remain only as representation validation or diagnostic evidence if useful; it may **not** be the semantic source of relation isolation-equivalence ownership. Do not restore the rejected CB3 approach that augments a relation from all available isolation certificates.

Only verified A5-owned relations may union occurrences. Final `sourceIsolationSheets` must continue to come from actual quotient members, sorted/unique, with no representative-sheet collapse.

## Falsifier and stop rule

**Stop and return to Review/Definition without a speculative semantic patch** if any of these occurs:

- the accepted A4/M5 authority cannot uniquely identify the certificate that owns a cross-sheet A5 relation;
- satisfying the gate would require changing occurrence identity, outgoing-side sheet assignment, exact source support or quotient equality;
- the only available implementation requires A6 to search global certificate inventory or infer an owner from geometry/position;
- a frozen A5/A6 semantic statement must be changed rather than merely implemented.

A new typed failure used to reject zero/ambiguous owner authority is allowed; weakening a current accepted failure or accepting uncertified cross-sheet union is not.

## Frozen validation surface

Do not modify tests, fixtures, selector449, routing449, or focused identities. Preserve:

- selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, exactly 449 LF rows;
- routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- focused order:
  1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
  2. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
  3. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
  4. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
  5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
  6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

Preserve row140's recovered `InvalidHardRailTransport` behavior and the clean by-value iterator-range correction. No benchmark semantic adaptation is authorized.

## Compile/package gate

After the smallest semantic patch, compile/package exactly the standard eight targets through `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX authority:

`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Require `DIRECTIONAL_ENABLE_GMP=ON`, generated link evidence for both `gmpxx` and `gmp`, `exactArithmeticBackend=GMP`, clean source receipts, complete recursive manifest and `runtimeExecution=false`. Code + Build may run static/compile-time checks only; no Directional tests, benchmarks, discovery, CLI/help/version or other generated runtime.

## TB4 pre-registration

If compile/package is green, `M6-CP1-TB4-EXEC` consumes the exact artifact immutably and executes the unchanged **six focused + selector449 = 455** fresh exact-filter processes, in the frozen order, exact-one selection, zero skips and benchmark 0.

Recovery-green is **455/455 PASS** with exact immutable postflight. In particular:

- no `OccurrenceInvalidCornerAuthority` anywhere;
- selector row140 remains PASS under `InvalidHardRailTransport`;
- selector ordinals **186, 214, 239, 444, 446, 448** recover;
- focused multi-isolation reaches and proves at least one legitimate multi-sheet quotient lineage with relation equivalence evidence;
- focused pair-swap PASSes.

A mechanically valid RED is preserved and sent directly to mandatory `M6-CP1-TB4-REV`; do not repair or rerun inside TB4. CB4 alone grants no promotion, stable-event recovery, CP1 closure or debt credit.
