# Architecture M6 CP3 CB1 Entry R1 Recovery Code + Build Plan

> **Review-agent block — `M6-CP3-TB1-ENTRY-REV` addendum (RA-31a), 2026-10-06. Binding; governs this plan where they conflict.**
> - **T3 is REPLACED.** The RA-30 §2 HardRail branch certificate is **withdrawn**: it strips each endpoint's region-relative gauge, but the derivation requires the cross-rail field matching τ.
>   - **Production:** remove the `HardRailBranchCertificateMismatch` rejection and its `:branch-certificate` mapping (`RemeshPipeline.cpp` A5 HardRail block). Keep coordinate-rigid transport and the published endpoint face-gauge evidence.
>   - **Identity 2** stays, pre-registered RED in TB1-R1. Its non-vacuity premise (cross-rail endpoint gauge difference of 90° or 270°) and A5 production must pass. On any A5 rejection the test prints the exact code, site and relation. Do not chase the certificate here.
>   - **Identity 6** must pass once A5 produces. Any remaining A5 rejection, printed, is a **stop for Review**.
> - **T2:** add a stop rule. If no produced nonzero-Z4 periodic pair has a 90° or 270° gauge difference, stop for Review.
> - P1, P2, T1 and T4 are unchanged.
> - **TB1-R1 acceptance:** 496 PASS plus identity 2 RED, with failures confined to its certificate assertions.
> - The D2 certificate is redefined in `M6-DEFN-R5-R1` after the R1 Review.

**Turn:** `M6-CP3-CB1-ENTRY-R1`
**Authority:** `M6-CP3-TB1-ENTRY-REV` / RA-31
**Boundary:** Code + Build only; compile/package all required targets, no generated Directional runtime.

## Goal

Recover the three stable entry regressions and the three new-entry witness/oracle defects without changing CP3 semantics, selector authority, or later exit scope. Keep production and test-authority corrections separate and falsifiable.

## P1 — complete A4 face-gauge publication

In `src/geometry/SurfaceCellTracing.cpp`, make every successful regional phase-front producer publish `faceBranchRotation` for each local face it owns. The curved bounded-disk path already demonstrates the required product shape. Apply the same exact authority publication to the planar/uniform and periodic-annulus producers using the gauge they already compute; then let the existing source-wide merge map those values to source rows.

Requirements:
- every produced regional result has `faceBranchRotation.size()==local face count`;
- values remain exact quarter turns `0..3`;
- no default/sentinel gauge, source-row reconstruction fallback, tolerance or post-product repair;
- retain the top-level fail-closed completeness/conflict checks;
- direct checked-factory callers with intentionally empty optional gauge vectors remain legal only where frozen product construction permits them; A5 HardRail must still fail closed without required gauges.

## P2 — scope OrdinaryFront isolation evidence correctly

In A6 `SurfaceQuotientProducer`, preserve the existing first checks for `OrdinaryFront`: identity canonical transport, kind, coordinate/scale equality and phase reject-only threshold. Then branch:

- **ordinary non-cross-sheet seam:** preserve full `sourceChart` and branch equality plus existing same-sheet/collinear/wedge checks; do **not** require reciprocal isolation-side evidence;
- **certified cross-sheet collinear isolation seam:** require reciprocal isolation evidence, exact stored `SurfaceIsolationSeamTransportCertificate`, exact region/seam/faces/sheets, forward/reverse quarter-turn and gauge-stripped branch turn exactly as RA-30a defines.

Do not weaken seam checks to restore green output.

## T1 — focused30 ordinal12 authority migration

Keep the identity name/order frozen. Its semantic HardRail region relabel must rotate every representation that RA-30a made authoritative, including `sourceFaceBranchRotations`, consistently with the cell/edge branch relabel. Baseline A5 must produce; the test must still prove coordinate-rigid HardRail transport is invariant under a pure face-gauge representation change.

Do not delete the test, reduce the relabel, or bypass checked factories.

## T2 — D1 produced witness

Keep `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` and its frozen semantics. Use a real `remesh_from_raw_cross_field`/production path on a nonzero-Z4 torus subject that organically yields an exact-A3 reciprocal pair with endpoint face-gauge difference **90° or 270°**. Assert this non-vacuity before the authority/tamper checks.

The wrong-Γ-direction mutant must fail. A 180° witness is insufficient. No hand-built A4/A5 relation record.

## T3 — D2 produced HardRail witness

Keep both HardRail entry identity names/order. The fixture must be production-derived, contain at least two topology regions separated by typed user hard edges, use a non-constant raw field, produce a cross-region HardRail, and exhibit at least one endpoint pair with face-gauge difference **90° or 270°**. Assert that A4 property before producing A5.

Then prove:
- `C_a=F_a^-1∘B_a`; `C_b=F_b^-1∘B_b`;
- `C_b∘C_a^-1` equals the coordinate-rigid HardRail transport;
- wrong-direction gauge stripping is rejected at the branch-certificate site;
- A7 HardRail binding does not compare global sheet labels across regions.

If no bounded real-produced witness can satisfy the non-vacuity premise, **STOP and return to Review**. Do not forge product records or weaken the certificate.

## T4 — D4 typed barrier oracle

Keep `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`. Verify barrier semantics at the authority that owns them:

- every typed source hard-feature carrier is absent from admissible `SourceChartTransitionGraph` face adjacency/union;
- every HardRail carrier is represented in the typed set;
- a PeriodicCut carrier may also be hard and must be blocked as a chart crossing;
- removing/tampering the relevant typed source barrier must change the directly governed transition/barrier predicate or allow the forbidden crossing.

Do not require arbitrary relation endpoint occurrences to have different global `chartComponent` IDs; alternate non-hard paths may reconnect them.

## Frozen surfaces

Must remain byte-identical unless the Review record explicitly authorizes test-body changes above:
- focused30 names/order;
- CP2 focused12 names/order;
- selector449 and routing449 bytes;
- the six CP3-entry identity names/order;
- optimizer and final-validator production source;
- D3/D7 production semantics.

No positional identity, global search/lookup, tolerance topology, source-grid recovery, fixture-specific production branch or permissive fallback.

## Static checks before compile

From one verified exact source snapshot/diff:
1. census all assignments to regional `faceBranchRotation` and prove every successful regional producer populates it;
2. prove reciprocal isolation evidence is queried only on the certified cross-sheet OrdinaryFront seam path;
3. prove focused30 ordinal12 transforms explicit face gauges with the rest of the relabel;
4. prove D1/D2 non-vacuity checks precede the stage whose failure would otherwise obscure witness reachability;
5. prove D4 references typed hard-feature/transition authority rather than global chart-label inequality;
6. `git diff --check` and Review-authorized path census only.

## Compile/package

Apply the complete source/test patch through standard Google Drive patch transport. Compile/package through `.github/workflows/agent-compile-reusable.yml` only, with GMP/GMPXX, all eight standard targets:

`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

No generated Directional binary/test/benchmark/discovery/help/version/ctest may run. Package evidence must record `runtimeExecution=false`, exact source, clean source receipts, manifest, toolchain/GMP and all compile exits.

## Immutable successor

If and only if compile/package is green, exact successor is `M6-CP3-TB1-ENTRY-R1-EXEC`. It consumes only the R1 package and executes exactly **497 fresh exact-filter processes** in frozen order: focused30 30 + CP2-focused12 12 + selector449 449 + CP3-entry 6. Exact-one selection 497/497, zero skips, benchmark 0 and immutable postflight are mandatory.

Recovery is green only if all 497 pass. Any RED is classified without retry/test weakening and routes to mandatory `M6-CP3-TB1-ENTRY-R1-REV`. Green also routes to that Review; no CP3-exit work begins directly from TB.
