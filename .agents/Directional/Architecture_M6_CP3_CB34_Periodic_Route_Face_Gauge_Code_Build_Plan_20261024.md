# CB34 plan — restore valid periodic-route face gauge (2026-10-24)

**Turn:** `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR`. **Boundary:** test-fixture-only Code + Build; no Directional binary/test/benchmark execution. This plan is authorized by the independent [TB34-REV decision](Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md), not by the diagnostic RED label alone.

## Exact scope

1. Keep `src/authority/FieldTransportAtlas.cpp`, transport validators, APIs, source atlas generation, and frozen selectors unchanged. Change only the `balanced_periodic_route_field` fixture authoring in `tests/SurfaceCellsPhase10Tests.cpp` and genuinely necessary fixture-level assertions/independent expectations; do not change test names or reduce negative checks.
2. Derive a face-gauge value on the *intermediate face* of the two sequential route steps. Set g=+1 at that face, zero elsewhere. For **every source-interior edge adjacent to that face**, update edge-transition `matching` using `g(secondFace)-g(firstFace)` relative to the stored directed orientation. Do not alter `effort`, underlying geometry, or cross-field physical direction. The 0→1 and 1→30 route steps must remain +1 and −1, with a compensating transition on edge(2,3) (faces1↔32).
3. Resolve face-gauge target by *route topology* under reflected and reordered source-face mappings, not literal face ID1. Handle any legacy compact-field serialization by deriving it from the complete corrected source transitions. Keep original `sourceField` independent of intentionally corrupted tracing transition for negative tests.
4. Add or extend a **meaningfully falsifiable** independent source-cycle audit only as needed, not a production validator bypass: (a) all local-vertex residues equal their independently derived lifts, (b) the two original route edges are nonzero with net zero, (c) removing third compensating edge must make the original invalid construction fail S1, (d) distinct positive/negative cases still reach their intended A4 disposition. Preserve accepted 491 prefix and entire selector497.
5. Make the smallest correct test-only patch. If there is no valid gauge-coboundary preserving the targeted route expectations, return to independent Review and report the contradiction instead of inventing a replacement assertion.

## Compile-only gate

Use exact-source GitHub Actions dispatcher/reusable compile, eight standard GMP/GMPXX targets, clean source and manifest/checksum receipts, `runtimeExecution=false`. Do not locally compile, execute tests/benchmarks, or upgrade an unexecuted fixture to PASS. Verify all intended path changes; archive complete patch and source identity. Update durable handoff, tracker and changelog only on evidence, not prediction. Separate successor is an immutable artifact-only TB with original seven cases, five controls, and independent accepted-prefix assessment, followed by independent TB-REV. Do not merge CB and TB.

## Stops/falsifiers

- Any newly missing component of face-gauge transformation or nonzero closed local-cycle residue.
- Original expected positive route proves only a vacuous zero-step path, or negative case loses its independently correct rejection predicate.
- Any frozen selector mutation, A3 producer/validator weakening, source-grid recovery, direct binary execution in CB, or GMP-disabled build.
- Any discrepancy in source SHA/package/checksum or repository authority; preserve WIP and report rather than force-applying.
