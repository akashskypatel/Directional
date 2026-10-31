# Directional M6-CP3-CB1-ENTRY-R3 — source-only audit of 14 historical organic/downstream R2 failures

**Scope:** Same unfinished Code + Build turn. This is an exact-source *static* test-provenance census, not a Test + Benchmark result, regression root-cause verdict, or A/B/C independent architectural decision.

## Frozen evidence and reproducibility

- Semantic source: `9380c1a5a6ecb8ed50cc3290e9a7ff3808d24f20`, source tar SHA256 `9a3e1494b82a590144077c5116331b770760fbd19782c2cf698dc3e06c7266c9` extracted from immutable package. Latest branch compare after this semantic commit changed only control/handoff/mailbox/TODO, not source/test/CMake.
- Mandatory eight-target GMP/GMPXX compile-only workflow `37986977367`, compile job `114011415442` SUCCESS, package artifact `11643991054`, exact outer SHA256 `e09eb8fb727eb858f82c69f1f7805cb22651112a86a45ca1a18b216b03edfadb`; package SHA256SUMS `28/28`, preflight/build exit `0`, authoritative GMPXX/GMP link, `runtimeExecution=false`; no executable was run.
- Historic evidence: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`, exactly 53 RED out of 497; **39** first-observable A4/Phase10/RE cases already separately audited, leaving **14** in the four classes below. The 53 are historical R2, NOT R3 observations.
- Frozen 497 = 30 focused + 12 focused CP2 + 449 selector + 6 CP3; no filters, ordinals, cases, fixtures, code, or workflow changed.

## Classification and owner

| Historical R2 family | Cases | Shared source witness/stage |
|---|---:|---|
| periodic odd A3 organic witness | 5 | `make_nonzero_z4_torus_witness_fixture` |
| torus downstream A5/A6 unavailable | 6 | `torus_fixture` |
| D3/D7 seam-collinear organic witness | 2 | `m6cp3_produced_seam_fixture` |
| D5 ordinary route organic witness | 1 | `A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds` |

All fourteen identities are source-defined in `tests/SurfaceCellTransitionQuotientTests.cpp` and compile under `directional_surface_cell_producer_tests`. Source location is the `TEST(...)` declaration line in the exact package; **source ownership does not prove execution or reaching a named stage**.

## Every historical identity (no identity dropped)

| Group:ordinal | Identity | Source line | Historical CP2 |
|---|---|---:|---|
| focused30:6 | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | 7682 | PASS |
| focused30:20 | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | 5203 | PASS |
| focused30:25 | `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus` | 5565 | PASS |
| focused30:26 | `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels` | 5844 | PASS |
| focused30:27 | `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage` | 5900 | PASS |
| focused30:28 | `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle` | 5922 | PASS |
| selector:444 | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` | 7273 | PASS |
| selector:446 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | 7570 | PASS |
| selector:447 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | 7733 | PASS |
| selector:448 | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | 7798 | PASS |
| cp3entry:1 | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | 2470 | N/A CP3 |
| cp3entry:3 | `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition` | 3022 | N/A CP3 |
| cp3entry:4 | `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds` | 3174 | N/A CP3 |
| cp3entry:5 | `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition` | 3366 | N/A CP3 |

## Observability and nonvacuity audit

### 1. periodic odd A3 organic witness (5)

- Source entry/producer gate: D1 source/A3 generator → odd selected-face gauge → reciprocal A4 PeriodicCut → stored semantic action; current failure counters at lines 1583–1660.
- Nonvacuity requirement: Do not count generator-only or stored-only candidates as produced PeriodicCut.

### 2. torus downstream A5/A6 unavailable (6)

- Source entry/producer gate: Retained A4 torus → A5 occurrence product → A6 closed-complex/materialization; current torus fixture reports A4 first failure but some A5/A6 assertions report only nullptr or false.
- Nonvacuity requirement: On future permitted TB, distinguish A4 preflight rejection, A5 typed error, A6 typed error and unavailable closed_complex_view.

### 3. D3/D7 seam-collinear organic witness (2)

- Source entry/producer gate: Three exact axis-aligned target sizes 0.25/0.5/1.0; A4 rejection → A5 typed error or no certified OrdinaryFront → wedge sheets → A6 selected forest → A7.
- Nonvacuity requirement: Never insert a hand-authored seam or accept an overlap as a positive.

### 4. D5 ordinary route organic witness (1)

- Source entry/producer gate: 18-source-edge torus hard-feature graph + A5 producer, then square fixture A5-owned reciprocal OrdinaryFront on eligible source chart transition.
- Nonvacuity requirement: Require A5-produced paired route and unrelated live chart edge; no unpaired A4 edge as positive.

### Specific diagnostic completeness findings

1. **Periodic (5):** the `make_nonzero_z4_torus_witness_fixture()` helper has fail-only `sourceA3Candidates`, `sourceFaceGaugePairs`, `oddFaceGaugePairs`, `reciprocalTracerPairs`, `publishedPeriodicHolonomies`, and `nonzeroHardCarriers` counts at the no-witness rejection. The same helper is shared across the five historical periodic tests, so these fields may narrow a future failed attempt. They have **not been run**.
2. **Torus downstream (6):** `torus_fixture()` reports retained first producer stage/reason on missing trace authority and the A4 rejected product predicate. After A4 publication, `build_torus_closed_complex_view()` returns only `nullopt` for A5 error, A6 error, or absent `closed_complex_view`; its two known call sites (`5612`, `5924`) assert availability without an A5/A6 typed reason. Several other tests inline A5/A6 construction and assert non-null without an error-code annotation. Therefore the exact first A5/A6 failure for these six cannot be inferred statically from this compile.
3. **D3/D7 (2):** the three-size `m6cp3_produced_seam_fixture()` search records bounded per-size first A4/A5/A6 stage reasons, absent certified OrdinaryFront, overlapping wedge sheets, and missing selected-forest conditions. It fails rather than manufacturing an eligible seam. No current positive witness has been observed.
4. **D5 (1):** the torus A5 baseline assertion emits the typed A5 error, and the square path separately requires a reciprocal A5-published OrdinaryFront with an eligible live source transition before testing the barrier. Static control flow does not establish either existing on current runtime.

## Actionable next safe actions (not pre-approved execution)

- Before a **separate, authorized** artifact-only Test + Benchmark, an optional **test-only fail-context patch** could thread typed A5/A6 error details into the two `build_torus_closed_complex_view()` failure assertions and the inline torus downstream assertions. This must preserve all original assertions and selectors, avoid duplicate producer runs, be exact-base patched through Drive, and pass a new eight-target GMP/GMPXX compile-only gate. It is an observability improvement, not a claimed root fix. Existing 39 reporter work is a different category.
- The independent A/B/C review remains required: (A) A4-trusted vs factory-independent nonrail A3 attestation; (B) compile-only CB closure vs later real-witness TB; (C) the four source-defined but unselected supplemental tests. Do not silently add four tests to the frozen 497 count.
- A later TB must preserve exact processes/receipts and inspect the 39+14 historical identities individually plus 47 CP2 accepted-green losses. A genuine empty two-carrier/organic search remains a STOP to independent producer Review, not a reason to relax assertion or synthesize evidence.

**Outcome:** fourteen historical R2 identities mapped to compiled source owners, with a bounded source-level observability gap in torus A5/A6 error reporting. No runtime results, semantic code changes, or successor authorization.

## 2026-10-09T21:00Z implementation addendum — compile-only, no runtime verdict

Test-only typed A5/A6 error reporters were applied after this exact-source static census, semantic commit `f135946f1007c35960624a368df5f58318fd98e7`, Drive run `37991764540`, eight-target GMP/GMPXX compile `37991952457` GREEN. Package `11644984310` SHA256 `e73793ed37a8663408d8615e4bd1b258ed598180aa6ea3d5fe05815584ef28e6`, 28/28 checks, `runtimeExecution=false`. The test helper and four historical torus assertions now report stage A5/A6 typed errors without changing original pass/fail conditions; two selector-based materialization tests already preserve result failure strings. **No R2 failures were rerun or resolved** and A/B/C reviews remain pending.
