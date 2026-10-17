# M6-CP1-CB9-A7 — A7 extraction and thin-adapter Code + Build plan

> **`M6-DEFN-R4-REV` amendment (RA-18) — this block overrides the plan below where they conflict. CB9 is AUTHORIZED.**
>
> **Goal 2 is replaced.** The adapter's `1e-9` check becomes the A7 `SourceSupportCertificate`, made of two parts:
> - **(a) Typed exact common support.** Read from A5 `SurfaceOccurrence::support` only; never re-resolve a point.
> - **(b) A reject-only point-coincidence guard in simplex coordinates**, with `τ` = the A5 resolver barycentric tolerance:
>   - edge `{a<b}`: `t = β_b/(β_a+β_b)` from each member's own face barycentrics;
>   - face-interior: per-component barycentrics in the common face.
>
>   A violation is `SourceSupportPointMismatch` (`:support-point`). The guard never accepts, merges or selects.
>
> Remove the old check in this same CB.
>
> **Identity 15** is renamed `M6CP1.A7RejectsSupportKindIdentityAndSameSimplexPointMismatches`. It must include:
> - a kind mismatch;
> - an identity mismatch;
> - same edge support at different `t`;
> - same face support at different barycentrics.
>
> All must reject, and the two same-simplex cases must reject **only** through the RA-18 guard.
>
> **Stop rule.** If TB9 shows `SourceSupportKindMismatch`, `SourceSupportIdentityMismatch` or `SourceSupportPointMismatch` on any previously accepted row, Review classifies it. Never relax to cross-kind coercion or to a looser tolerance.
>
> Everything else stands: identities 13-20 (with 15 renamed), focused-20 file, gate **20+449 = 469**.

**Held until:** `M6-DEFN-R4-REV` accepts the R4 definition.
**Type:** Code + Build only; compile/package, no Directional runtime.
**Successor if compile/package green:** `M6-CP1-TB9-A7-EXEC` -> mandatory `M6-CP1-TB9-A7-REV`.

## Goals

1. Implement immutable `SourceAttachedGeometryProduct` / `SourceAttachedGeometryProducer` exactly as R4 D1.
2. Replace the adapter's semantic `1e-9` quotient-geometry check with exact typed `SourceSupportCertificate` authority. A float comparison may survive only as non-authoritative diagnostics.
3. Move D2 category-(c) materialized-mesh certification into A7 and leave category-(d) as serialization only.
4. Preserve A6 topology, exact class membership, selected relation values and RA-17's no-placement-transport consumer rule.
5. Add focused identities 13-20 in the exact R4 order; identity 20 must execute the real `validate_materialized_completion_domain_ownership` path.

## Implementation constraints

- One A7 vertex per A6 `SurfaceQuotientClassId`; no merge/split/re-number semantic authority.
- Exact common support uses typed vertex/edge/face-interior identity and exact A0 face incidence. Cross-kind coercion is forbidden.
- Representation-only representative key is `(support, cornerWedgeBindings, OccurrenceId)`.
- Lineage fields are class-wide A5/A6 projections; `selectedRelationPaths` retain `canonicalRelationValue`.
- `canonicalTransport` / `relationTransport` remain strict-cycle-only consumers.
- Do not edit selector449, the frozen focused-12 file, fixtures, `PureQuadCompletion.cpp` relation semantics, or R5 gauge obligations.

## Tests authored in this CB

Append exactly:

13. `M6CP1.A7PublishesOneEmbeddedVertexPerA6Class`
14. `M6CP1.A7ExactSourceSupportAcceptsVertexEdgeAndFaceInteriorClasses`
15. `M6CP1.A7RejectsSupportKindAndIdentityMismatchesBeforeFloatingDiagnostics`
16. `M6CP1.A7RepresentativeIsInvariantToOccurrenceAndSourceRowOrder`
17. `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues`
18. `M6CP1.A7NeverConsumesPlacementTransportForGeometryOrLineage`
19. `M6CP1.A7CopiesA6TopologyWithoutClassMutation`
20. `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`

Create the successor focused-20 list with the focused-12 bytes as its exact first 12 lines. Record its SHA-256 in the CB report. Tests are compiled only in CB9; execution belongs to TB9.

## Compile gate

Use only the mandatory reusable compile workflow and GMP/GMPXX policy. Compile/package the standard eight targets, prove `runtimeExecution=false`, clean exact source, link authority and complete recursive manifest. Compile-green authorizes immutable TB9 over **20 focused + selector449 = 469** fresh exact-filter processes.

## Documentation closeout

Record exact source, changed paths, focused-20 digest, compile run/job/artifact IDs, GMP evidence and explicit no-runtime boundary. Update handoff/TODO/CHANGELOG only after compile evidence is verified.
