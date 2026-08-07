# Gate 1 Producer Architecture — Design Review Report

## Decision

**Outcome B — bounded producer replacement proof.**

The no-progress stop rule was correctly triggered. Two bounded Gate 1 Code + Build attempts changed local phase-transport behavior without materially advancing the exact production plane. A third predicate-level repair is not authorized.

The replacement boundary is deliberately narrow: replace the ambiguous producer-selection contract around `build_surface_cell_network()` / `build_uniform_phase_front()` with one first-class authoritative producer outcome. Do not rewrite unrelated arrangement, completion, optimization, validation, fallback, or recovery systems.

## Evidence authority

- last successful Gate 1 source: `aea10409c73c490b92f78760b73191641ef823c6`;
- Gate 2 chart-transport source: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- first rejected restoration: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- second bounded source: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- tested artifact SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- evidence SHA-256: `99a4922767d567830f202b440504f2b48d07fdb02bb117668baf846e7eeb9b64`;
- exact production plane: deterministic 106 traces / 9 arrangement cells / 12 completion candidates / 15 validation failures / no output;
- retained seam: deterministic 81 vertices / 64 pure quads / `CompletedSurfaceCells` / hash `a8972efd7c4900a4`.

## Proven execution model

### Successful Gate 1 parent

The successful parent built the planar phase front from geometry and face axes. If that phase front succeeded, `build_surface_cell_network()` converted its cells directly to accepted proposals and returned. The generic seed/trace/proposal producer existed, but it remained latent because the plane's authoritative phase front succeeded.

### Gate 2 divergence

Gate 2 made phase-front construction consume matching, effort, and edge-transition metadata. This was required for the reciprocal seam transport contract, but it also changed the plane from a geometry-only direct producer into a transition-aware producer. When that producer does not succeed, the current architecture automatically invokes the unrelated generic seed/trace/proposal producer.

Therefore `phaseFront.succeeded == false` is currently overloaded to mean both:

1. the authoritative producer is not applicable; and
2. the authoritative producer was applicable but rejected its input.

Those states are not semantically equivalent.

### Production preprocessing versus isolated tests

The exact `plane.obj` + `plane.rawfield` route passes through production field finalization, principal matching, matching effort, edge-transition creation, feature/relief state, adaptive target-size generation, source component/sheet classification, and pipeline tracing options before entering the producer.

The passing vertex-fan contract tests reconstruct a geometrically equivalent plane with different indexing, inject a constant target size directly, and do not reproduce the entire production preprocessing state. Their success proves the ordered fan algorithm only. It does not prove the exact production authority path.

### Relief-barrier contract mismatch

`SurfaceCellTracingOptions::reliefBarriersEmbedded` documents that relief separatrices are guidance until embedded and only embedded separatrices may stop traces as hard barriers. The generic walker honors that flag.

The current phase-front transition route, however, rejects `options.reliefBarrierEdges` unconditionally during ordinary/vertex-fan transport. This is a proven semantic inconsistency between the authoritative phase-front route and the pipeline option contract. It is not claimed to be the exact first current plane rejection because the typed phase-front reason is not retained in final runtime diagnostics and the exact barrier set was not serialized in the artifact evidence.

### Failure authority is overwritten

When phase-front construction fails, `build_surface_cell_network()` proceeds into generic tracing/proposals. The pipeline may initially record a typed `tracing/phase-front` rejection, but later completion/output-validation replaces the first-invalid producer diagnostic. The final plane therefore reports `completion/output-validation:AggregateCompletionValidationFailure` and the stable 106/9/12 generic signature rather than the authoritative producer rejection.

This explains why local phase-front changes can alter tracing hashes yet leave the same downstream constructive signature: the rejected authoritative result is not a terminal or retained producer outcome.

## Architectural conclusion

For a source domain that has selected the authoritative phase-front producer, rejection must not mean "try a different internal producer." The producer selection must be explicit before execution, and the result must distinguish applicability from rejection.

The replacement proof shall introduce a first-class disposition equivalent to:

```text
NotApplicable
Produced
Rejected
```

Semantics:

- **NotApplicable** — this producer does not yet represent the source topology; a later producer may be selected explicitly.
- **Produced** — authoritative cells/fronts are complete and materialize directly one cell to one quad.
- **Rejected** — the producer was applicable but an invariant failed; preserve the typed reason and stop this backend request at the producer boundary. Do not start generic seeds/traces/proposals.

Gate 1 plane and the proven Gate 2 seam are both within the authoritative phase-front producer's current applicable domain. Nonplanar, periodic, singular, or otherwise later-gate domains may remain `NotApplicable` until the representation is extended to them.

## Replacement boundary

### Inputs

The authoritative producer receives, as first-class inputs:

- source vertices/faces and canonical source topology;
- finalized `CrossFieldResult`, including matching/effort/transitions;
- production target-size vector;
- source component and local-sheet labels;
- hard-feature state;
- relief-barrier state plus `reliefBarriersEmbedded`;
- authoritative rail/feature constraints where applicable;
- exact tracing/transport options.

### Outputs

The producer returns:

- disposition: `NotApplicable`, `Produced`, or `Rejected`;
- ordered phase/front cells, edges, and events for `Produced`;
- typed immutable fail-closed reason with source context for `Rejected`;
- complete ordered source-route provenance;
- deterministic structural hash.

### Transport invariants

- canonical source-edge transition identity;
- strict forward/reverse reciprocal transport;
- ordinary shared-edge crossing and ordered source-vertex fan crossing;
- complete ordered crossed-edge provenance;
- exact source component/sheet ownership;
- hard-feature barriers remain constraints;
- relief edges block only when `reliefBarriersEmbedded == true`;
- no proximity/positional merge, arbitrary subset search, fixture identity, fallback, recovery, or post-hoc topology inference.

## Required next implementation proof

Use `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Code_Build_Plan.md`.

The next Code + Build turn must not perform another isolated phase-transition predicate repair. It must implement the explicit producer disposition and prevent `Rejected` from silently launching the generic producer. It must also add production-route coverage that loads the exact committed plane fixture and raw field through the same preprocessing inputs used by the real pipeline.

Minimum architectural progress in the following artifact-only turn is that the exact plane can no longer fall through to the 106/9/12 generic path after authoritative producer rejection. Gate 1 itself still requires direct valid plane output; an explicit `Rejected` result is architectural progress, not Gate 1 closure.

The seam remains a mandatory regression and must stay direct and deterministic.
