# Surface-Cell Architecture

**Status:** normative architecture authority. Mutable status/evidence belongs to TODO, milestone, handoff, current turn report/plan, and regression tracker.

## Product contract

The direct `SurfaceCells` backend converts supported arbitrary triangle meshes plus generated or supplied cross fields into deterministic, source-authoritative, field-aligned pure-quad surface output, or returns one truthful typed failure. Strict direct acceptance is not satisfied by fallback/recovery/substitution.

## Architectural invariants

1. Every semantic fact has one owning stage and one authoritative representation.
2. Source face/vertex/edge/transition/chart/region/rail/occurrence/certificate domains use distinct semantic types with checked adapters at compatibility boundaries.
3. Cross-field transport uses exact cyclic/grid algebra (`QuarterTurn`, lattice translation, grid automorphism, exact inverse/composition), not unrestricted integer arithmetic.
4. Ordered transitions are represented as typed steps/routes. Canonical storage never changes behaviorally observed orientation.
5. Producer outcomes are closed (`NotApplicable`/`Produced`/typed `Rejected`) and debug/partial state is not consumable product authority.
6. Global topology/conformity/relation authority is planned globally before local production; local consumers consume explicit witnesses/certificates rather than reconstruct global semantics.
7. Aggregation may remap representation handles only; it does not overwrite semantic scope.
8. Source support is one sanitized exact simplex identity; tolerances determine sanitization success, not topology identity.
9. Validators independently verify elementary incidence, support, topology and producer certificates; they do not synthesize missing producer semantics.
10. Hashes/counts/row positions/emission order/backend handles are never semantic identity unless explicitly part of the product contract.
11. Recursive/search work has one global monotone work ledger and deterministic exhaustion failure.
12. Diagnostics/export state is derived and non-authoritative.
13. Test authority is independent and representative: compile/helper/focused evidence never substitutes for required product-oracle/corpus evidence.

## Target stages

- **A0 SourceAuthoritySnapshot:** sanitized triangle source, exact support, component/feature identity.
- **A1 FieldTransportAtlas:** typed face/chart/edge transitions, quarter-turn/grid automorphism, canonical routes/cycle transport.
- **A2 GlobalTopologyPlan:** source topology regions, isolation, cycle/cut/feature ownership.
- **A3 GlobalConformityPlan:** shared rail/cut breakpoints, parity/subdivision schedules before local production.
- **A4 RegionConstruction:** consumes immutable region/conformity authority and produces fully scoped local cell/trace products or typed failure.
- **A5 OccurrenceComplex:** explicit corner occurrences and directed-side/relation identity.
- **A6 QuotientMaterialization:** consumes verified relation registry/certificates exactly once into candidate quads.
- **A7 Embedding:** binds materialized topology to source geometry through exact support.
- **A8 IndependentVerification:** topology/support/certificate/quality checks without topology repair.
- **A9 DiagnosticsExport:** derived reporting, retention and public compatibility output.

## M1–M6 migration

M1 incrementally introduces typed authority only at genuine semantic owners. M2 closes producer outcomes and creates single-writer immutable snapshots. M3 establishes global conformity before local regions. M4 publishes certificate-carrying relation/quotient authority. M5 completes explicit occurrence/support/independent verification split. M6 retires legacy parallel representations and decomposes ownership modules.

Migration is bounded and evidence-preserving; no broad one-shot rewrite.

## Current architectural interpretation

M1a–M1d typed authority consumers are immutable accepted. M1e ordered segment-route transport is compile/package complete and awaiting immutable runtime. This status statement is informational only; live exact authority is the handoff/current report/current plan.

G4 product blockers remain separate from architecture migration. Typed migration cannot synthetically reinterpret direct-torus failures or promote known-red representatives.

## Anti-shortcuts

No validator weakening, fixture-specific product branches, synthetic output, generic substitution after authoritative rejection, proximity/positional topology merging, tolerance-derived exact identity, arbitrary subset search, timeout-as-correctness, raw ID/count/hash proxy, or post-hoc topology repair may satisfy strict direct acceptance.
