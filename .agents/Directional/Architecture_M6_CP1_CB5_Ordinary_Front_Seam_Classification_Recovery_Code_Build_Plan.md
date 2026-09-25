# M6-CP1-CB5 OrdinaryFront Seam-Classification Recovery Code + Build Plan

**Turn:** `M6-CP1-CB5`
**Type:** bounded runtime-free Code + Build
**Status:** AUTHORIZED BY `M6-CP1-TB4-REV`, **as amended by the review-agent addendum (RA-12 plus the torus falsifier)**

> **Review-agent amendment (2026-09-25):**
> 1. **RA-12 is in scope and required.** Append the site suffixes defined at the end of `Architecture_M6_Frozen_Definitions.md` to every emission of `MissingIsolationSeamEquivalenceAuthority` / `InvalidIsolationSeamEquivalenceAuthority`:
>    - A5 adapter mapping: `:a5-wedge` / `:a5-side`. Distinguish them either from error context (wedge failures set `occurrence`, side failures do not) or with split A5 codes. Existing A5 enum members and focused row3's expectations stay unchanged.
>    - A6: `:a6-side-evidence`, `:a6-collinear-span`, `:a6-seam-span-transition`, `:a6-seam-faces`.
>
>    Diagnostic only: no predicate or outcome change.
> 2. **Torus falsifier.** The recovery of focused row6 and selectors 444/446/448 is a prediction. The torus is multi-sheet, so the A5 site and the seam-span site cannot be excluded statically. If any of them remains RED in TB5, TB5-REV classifies it by its RA-12 suffix. Neither CB5 nor TB5 may be widened.
> 3. Unchanged: the semantic correction below, the frozen surfaces, the seven focused identities, and TB5 = 7 + 449 = 456.
>
> Rationale: `Architecture_M6_CP1_TB4_Review_Record.md`, review-agent addendum.
**Input candidate:** `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5`
**Accepted runtime authority:** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 449/449
**Runtime successor if compile-green:** `M6-CP1-TB5-EXEC` → mandatory `M6-CP1-TB5-REV`

## Goal

Correct one proved A6 authority-domain error without widening M6 semantics: exact source-edge collinearity is a support classification, not proof that the edge is an isolation seam. Preserve every accepted R2/RA-1–RA-11 authority and change only reciprocal `OrdinaryFront` near-endpoint P2 classification.

## Proved defect

A5 records `SurfaceOccurrenceSideSpan::collinearEdge` for any exact `SourceEdgeSupport` span. Its own `transition_between` accepts a no-certificate span when the two bindings remain on the same sheet. A6 later treats every `collinearEdge` as `seam` and requires `isolationCertificateBySeam[{region,edge}]`, producing `MissingIsolationSeamEquivalenceAuthority` on ordinary source-edge-collinear spans. R2 P2 requires the seam branch only when the span is seam-collinear.

## Authorized implementation

In the A6 reciprocal `OrdinaryFront` endpoint-span check:

1. Preserve the existing reciprocal presence parity for `collinearEdge` and require matching exact source-edge identity when present.
2. Factor/reuse a local exact **non-seam P2** predicate if helpful: both spans' mapped interior sheets are equal, and that sheet belongs to both endpoint occurrence wedge sets.
3. If neither span is source-edge-collinear, use that non-seam predicate exactly as today.
4. If both spans name the same source edge, look up the already checked isolation certificate by exact `(sourceTopologyRegion, edge)`.
5. **No certificate:** classify the span as generic source-edge-collinear but non-seam and use the same non-seam predicate. Do not emit or synthesize isolation evidence.
6. **Certificate present:** keep the current seam branch exactly — the selected interior faces/sheets must match the certificate's two incident face/sheet pairs in either direction, and each endpoint span must carry the exact reciprocal `CornerWedgeIsolationTransition`.
7. Keep the existing ordered whole-side `isolationEvidence` certificate validation and reciprocal-list check unchanged.

A small local helper that removes duplication of the non-seam predicate is allowed. On failure, the non-seam predicate emits `QuotientReciprocalSideAuthorityMismatch`, as the non-collinear branch does today. RA-12's string suffixes are the only other authorized change. No public schema change is authorized.

## Frozen surfaces — do not change

- A5 span construction and `collinearEdge` definition.
- `SurfaceSupportResolver` behavior/tolerance and collinear interior-face selection.
- `CornerWedgeFaceBinding`, `CornerPlacementProvenance`, wedge sheet sets and `CornerWedgeIsolation` publication.
- `OccurrenceId`, relation IDs, relation ownership, quotient equality/class identity and representative identity.
- HardRail/Periodic owner, route, Z4 action, translation or selected-path semantics.
- Component remap and A7 lineage projection.
- Any test, fixture, benchmark, selector449, routing449 or accepted manifest.
- R2 + RA-1–RA-11 normative text.

Do not add a new focused identity. Holding the existing seven identities fixed is part of the recovery experiment.

## Static falsifiers before compile

Code + Build must stop rather than widen scope if any is true:

- Existing `isolationCertificateBySeam` / region isolation-seam authority cannot distinguish generic source-edge-collinear from seam-collinear without a new A5 field or a new semantic rule.
- The correction requires changing A5 publication, source-support resolution, product schema, tests/fixtures/selectors, or HardRail/Periodic semantics.
- The correction requires fallback search, guessing a seam, scanning unrelated certificate inventory, or weakening exact reciprocal evidence.
- Static inspection shows the new no-certificate branch can admit different-sheet endpoint spans; non-seam P2 must remain exact same-sheet + both-wedges membership.
- Frozen selector449 or routing449 bytes change.

## Code + Build boundary

- Apply the smallest production-source patch necessary for the A6 P2 classification, plus minimal compile/report integration only.
- Run static checks proving the certificate-present seam branch and whole-side reciprocal evidence validation remain unchanged.
- Re-hash selector449 as `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 as `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
- Mandatory compile/package uses `.github/workflows/agent-compile-reusable.yml`, GMP/GMPXX, and the standard eight targets: `directional_core`, `directional_pipeline`, four surface-cell owner test executables, `directional_compiled_api_tests`, `directional_benchmarks`.
- **No generated Directional binary may execute in CB5.** No test, benchmark, discovery/list/help/version/CLI/fuzzer/ctest/custom input. Package must record `runtimeExecution=false` and clean source receipts.

A compile failure may receive only a bounded compile repair that does not alter the semantic experiment. Any semantic expansion returns to Review.

## Pre-registered TB5 gate

If CB5 is compile/package green, `M6-CP1-TB5-EXEC` consumes that exact package immutably and executes exactly the **same seven focused identities + selector449 = 456 fresh exact-filter processes**. No rebuild, repair or test/selector edit is allowed.

Recovery-green is conjunctive:

- focused **7/7 PASS**;
- selector449 **449/449 PASS**;
- exact-one selection and zero skips for all 456;
- benchmark count zero and immutable package/source/execution-view postflight;
- selector row140 remains PASS;
- `OccurrenceInvalidCornerAuthority` remains absent;
- all 21 TB4 new accepted losses recover;
- carried focused pair-swap + selector444/446/448 recover;
- focused row5 and row7 remain PASS.

The prediction for the five feature-oracle and three earlier-stage casualties is that they recover when the common upstream classification error is corrected. **Falsifier:** if the direct `MissingIsolationSeamEquivalenceAuthority` family recovers but any downstream identity remains RED at a different first failure, TB5 Review must open/split a new candidate. Do not broaden CB5 or repair inside TB5.

Every mechanically valid TB5 outcome advances to mandatory runtime-free `M6-CP1-TB5-REV`; no promotion, debt discharge or CP1/G4 closure occurs before Review.
