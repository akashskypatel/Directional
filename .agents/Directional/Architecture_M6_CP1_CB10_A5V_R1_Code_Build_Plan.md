# M6-CP1-CB10-A5V-R1 — RA-19 ordering / pure-projection recovery Code + Build plan

> **Review-agent amendment (`M6-CP1-TB10-A5V-REV` addendum §J3) — binding; it adds to Goals R1 and R2 below.**
>
> **R1 addition.** After the reorder, the moved helper takes the **published** `SurfaceOccurrenceComplex`. The side-count check must use `complex.certificate().directedSideCount` and `complex.cells()` again, as the pre-CB10 adapter did; do not use `phaseFront.cells().size()*4`. Keep the 28 moved predicates otherwise verbatim (verified identical in §J2).
>
> **R2 exact oracle.** Use the field table in the TB10 Review record addendum §J3. Every expected value comes from:
> - A7 `vertices()` / `topology()` / `boundary_loops()` / `certificate()`;
> - A6 `relation_certificates()`;
> - A5 `occurrences()`;
> - A4 `isolationSeamTransportCertificates().size()`;
> - or the fixed compatibility constants listed there.
>
> Every other field is asserted equal to its default. Compare exactly. The canonical quad order and the boundary-loop rotation/sort are re-implemented test-side; do not call adapter code.
>
> **Stop for Review** only if a field outside that table turns out to be adapter-written.

**Owner:** `M6-CP1-CB10-A5V-R1`
**Type:** Code + Build only; runtime forbidden.
**Authority:** `Architecture_M6_CP1_TB10_A5V_Review_Record.md`, RA-19, accepted shared-`tau` and RA-22b portions of CB10.
**Successor if compile-green:** `M6-CP1-TB10-A5V-R1-EXEC` -> mandatory `M6-CP1-TB10-A5V-R1-REV`.

## Frozen inputs

- Keep candidate semantics outside F1/F2 fixed.
- Keep `SurfacePointSourceSupportResolver::default_barycentric_tolerance() == 1.0e-8`; no tolerance change.
- Keep RA-22b's exact `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face` guard and focused20 positive/negative unchanged.
- Do not change quotient identity/topology, A6/A7 relation/transport/support semantics, fixtures, selector449/routing449, or any focused identity name/order. Focused24 text remains byte-identical (`6bcc8a...067bf`).
- Do not begin CB11 / RA-20 / RA-21 work.

## Goal R1 — restore RA-19 validation precedence

`SurfaceOccurrenceComplexProducer::produce` must complete every pre-existing A5 record validation before any moved category-(a) phase-front predicate runs.

Preferred implementation shape:
1. construct cells/occurrences/relations exactly as today;
2. call `publish_records_for_validation(...)` first;
3. if it returns an A5 error, return that exact error unchanged;
4. only after it returns a valid `SurfaceOccurrenceComplex`, call the moved `validate_phase_front_authority_after_a5(...)` helper using the published occurrence records;
5. if the moved helper succeeds, return the already-published A5 product.

Equivalent code is allowed only if the same ordering is obvious and no existing failure name/precedence changes.

**Falsifier:** any moved category-(a) check remains reachable before the pre-existing publish/record validations, or any old A5 failure can be shadowed/renamed.

## Goal R2 — make identity24 a complete behavioral projection oracle

Keep `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` and its three fixtures. Strengthen only its body so the expected result is independently serialized from A5/A6/A7 outputs and fixed compatibility/default rules.

At minimum compare every adapter-written or contract-relevant field:
- result success/failure and summary counters derived from A5/A6/A7;
- `PureQuadMesh`: `sourcePatch`, `domainIdentity`, `vertices`, `vertexPositions`, `vertexProvenance`, `quads`, `boundaryVertices`, `boundaryNodeIdentities`, `boundaryLoops`, `backend`, `usesCenterFan`, `sourceSideEdgeCounts`, `vertexLineage`, `quadLineage`;
- every field of `PureQuadVertexLineage` and `PureQuadFaceLineage`, including IDs, kinds, defaults/caches, sourcePatch/local rows, completion flags and cycle hashes.

Do not reuse `build_authoritative_phase_front_mesh` helpers to build the expected object. The expected serialization must be test-side and stage-product-derived. A field intentionally fixed/default by the compatibility adapter may be asserted against that fixed/default contract. If the expected value of a field is not actually frozen by A5/A6/A7 plus compatibility rules, stop for Review instead of inventing semantics.

**Falsifier:** a one-field mutation of any adapter-written mesh/lineage/summary field could still leave identity24 green.

## Goal R3 — static thin-adapter and preservation checks

Re-run the CB10 static scan over `build_authoritative_phase_front_mesh` and show it contains only A5/A6/A7 invocation, typed compatibility mapping, serialization/normalization and diagnostic counters. No semantic tolerance, support/region/sheet authority selection, relation search, route validity, topology repair or acceptance predicate may return.

Re-hash focused24/focused20/selector449/routing449. Focused24 and all pre-existing lists must be byte-identical to CB10/TB10.

## Compile/package gate

Use the mandatory reusable GMP/GMPXX compile workflow on the standard eight targets only. Record exact source/run/job/result/log/digests, 28/28 manifest and clean source receipts with `runtimeExecution=false`. Do not execute tests, test discovery, benchmarks, CLI, generated binaries or custom inputs in this turn.

Compile-green routes to immutable `M6-CP1-TB10-A5V-R1-EXEC`: exactly focused24 + selector449 = **473** fresh exact-filter processes, exact-one, zero skips, benchmark 0, immutable postflight; then mandatory Review. No promotion occurs in Code + Build or EXEC.
