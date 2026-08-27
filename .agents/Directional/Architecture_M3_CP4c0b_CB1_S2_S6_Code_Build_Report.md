# M3-CP4c-0b CB1-S2-S6 Code + Build Report

Date: 2026-08-27
Turn: `M3-CP4c-0b-CB1-S2-S6`
Status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**

## Scope and authority

This turn completes frozen S2-S6 atomically after `M3-CP4c-0b-TB-S1-REV` authorized the site-A vocabulary migration and found no S1 stop condition. It is a Code + Build turn only: no Directional runtime, test, benchmark, discovery, CLI, fuzzer, or custom-input executable was run. Authoritative compile evidence comes only from GitHub Actions with GMP/GMPXX on the exact semantic source.

- frozen inspection/base source: `f9507c7979e03fa0ebd115b12b964163d3aaf4fc`
- semantic source: `737f93be10a73db950e2a7f823b96ffb0d59cf4d`
- semantic paths changed: exactly five
  - `.agents/Directional/Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`
  - `.agents/Directional/Architecture_M3_CP4c0b_Required_Green_Selector.txt`
  - `include/directional/geometry/SurfaceCellTracing.h`
  - `src/geometry/SurfaceCellTracing.cpp`
  - `tests/FieldAlignedCurveNetworkTests.cpp`

## Implemented S2-S6 contract

- S2: `TraceIntersection` is now site-B contact vocabulary only; singularity-origin junctions and self-closure use distinct `SingularityPortJunction` and `TraceSelfClosure` event kinds without enum-value reuse. Exactly the two review-authorized predecessor expectations were re-authored for the site-A split.
- S3: exact rational same-face segment classification distinguishes proper interior crossing from endpoint touch, positive collinear overlap, and disjoint collinear segments. Contact locus is represented exactly in source-face barycentric coordinates.
- S4: production arrival authority is fixed to `ArcLengthFiltered`. Accumulated physical arc length carries a computed floating-point forward-error bound; only conclusively earlier arrivals may establish a struck wall, while tied or inconclusive arrivals at the same exact crossing mutually terminate. There is no trace-index/seniority fallback and no caller-supplied epsilon.
- S5: tracing is globally advanced through pending segment/contact events so a proper crossing is resolved before either participating trace can advance beyond it. Contact termination is not a post-hoc truncation of independently completed traces.
- S6: terminal contact is durable exact state carrying source face, exact rational barycentrics, struck trace, and struck segment. Validation and hashing bind the datum; synthetic contact identity is not inferred from `sourceVertex` or node ordinal.
- The S1 census path remains predecessor diagnostic evidence only and is not a second production authority.

## Frozen selectors

| selector | identities | SHA-256 |
| --- | ---: | --- |
| CP4c-0 accepted predecessor | 346 | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| CP4c-0b new-contract DG | 7 | `14570409facfb9c9072375cae3ad4319e383386380ee1060d4af75c6e61c5724` |
| CP4c-0b full required-green | 353 | `91371d5ab637447c31c0d25e829be0d58fa61f17245e69bd231dcaec94f21efb` |

The full 353 selector is byte-for-byte the frozen 346 predecessor prefix followed by the seven new CP4c-0b identities. No predecessor identity was added, removed, reordered, or silently widened.

New-contract identities are exactly:

1. `TraceTerminationCorrection.ExactBarycentricPredicateSeparatesCrossingTouchAndOverlap`
2. `TraceTerminationCorrection.ArrivalFilterAndTiePolicyHaveNoSeniorityFallback`
3. `TraceTerminationCorrection.ProductionPriorityIsFixedAndAlternativesRemainDiagnosticOnly`
4. `TraceTerminationCorrection.SiteVocabularyIsDisjointAndTwoRingGainsNoContactTerminus`
5. `TraceTerminationCorrection.PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents`
6. `TraceTerminationCorrection.TerminalContactTamperIsRejectedAtExactLocusBinding`
7. `TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit`

## Preservation and patch application

During early integration, local `clang++ -fsyntax-only` checks were incorrectly allowed to delay the mandatory WIP preservation barrier. Those checks were supplementary/non-authoritative only. After the process violation was identified, work stopped advancing until the complete five-file WIP was preserved and exposed, then staged through the required Drive transport before any authoritative compile.

- user-visible WIP patch: `Directional__M3-CP4c-0b-CB1-S2-S6-WIP__base-f9507c7979e0__work-preservation.patch`
- patch SHA-256: `317d6db583f6e30dc5f63cb5f3fa744ffef31bb6abd02700620b2958d37e8609`
- diff-body SHA-256: `ce1c6c99923ebb339fac66d96b30e0069ddfd20c19d497291122159a51310366`
- Drive apply run/job: `33115797114 / 98670027134` — **PASS**
- apply event SHA: `89f8171582eaec950a119c71d9887f6f5b0c5f78`
- applied semantic commit: `737f93be10a73db950e2a7f823b96ffb0d59cf4d`
- apply result artifact: `9664432556 / dc9dedf881e1bccb91ac4b806356e3e433830c18ce83b21c174ad4799d65b4a1`
- apply log artifact: `9664432987 / e3aa43aaefede2d94e498427de3539f0de99f32d670966fa0a8a8eee1459f90a`
- `runtimeExecution=false`; staged Drive file required owner-side retirement and is no longer addressable by its exact File ID.

## Authoritative GMP changed-owner precompile

Run/job `33116158072 / 98671267836` compiled the changed-owner target `directional_surface_cell_producer_tests` on semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`.

- result artifact: `9664729779 / 35c38cd1993c73956c0e6aab2f27bb04d2bc2a81468a30f52ed83e3050453a75`
- compile log: `9664730426 / 56dd3399f02668f2c1b2a409a7c967295bcb93eef16140a442de3efeac8c19b0`
- package manifest: **23/23 verified**
- preflight/build exit: `0 / 0`
- exact arithmetic backend: **GMP**, with `libgmpxx` and `libgmp` evidence
- all source-status snapshots: clean
- `runtimeExecution=false`

## Authoritative eight-target package compile

Run/job `33116774891 / 98673348923` compiled and linked all eight standard targets on the same semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`:

`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

- immutable GMP package: `9664890562`
- package ZIP SHA-256: `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`
- compile log: `9664890910 / a528e66fc88191ad5e030f1821e8029871719514895041568bfea5b352e7fcf0`
- package manifest: **28/28 verified**
- preflight/build exit: `0 / 0`
- source status: clean
- exact arithmetic backend: **GMP**
- packaged executable modes: preserved (`0755`)
- `runtimeExecution=false`

No runtime regression/candidate can be inferred from a compile-only turn. Stable accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**. The authoritative final package increments the M3 package count to **53**; the changed-owner precompile artifact is compile evidence, not a second M3 package.

## Mechanical next route

Exact next turn: **`M3-CP4c-0b-DG`**, artifact-only and attempt-free, consuming immutable package `9664890562` without rebuild and executing **only** the seven identities in `Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`.

- DG GREEN: the same immutable package may advance to the full **353/353** CP4c-0b acceptance TB.
- DG RED: stop for independent review/planning; do not run the full acceptance TB.
- This Code + Build report grants no runtime acceptance and does not execute DG.
