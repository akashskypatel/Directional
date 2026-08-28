# M3-CP4c-0b DG T4 Artifact-Only Test + Benchmark Execution Report

## Verdict

`M3-CP4c-0b-DG-T4-EXEC` is **COMPLETE / EXECUTION GREEN 7/7**.

The authoritative artifact-only run executed exactly the seven re-frozen trace-termination identities against immutable GMP package `9668492827` from semantic source `b2629040450c12507367c232f68a4d972b46450f`. Every identity selected exactly once and passed. No escaping C++ exception, repository timeout, configure, compile, relink, repair, generated discovery, or package/source/test/fixture/selector mutation occurred. Immutable package and materialized-source byte-and-mode postflight checks passed.

This execution is a diagnostic gate only. It does **not** establish the 353-identity CP4c-0b acceptance result. T5 remains blocked until the required independent `M3-CP4c-0b-DG-T4-REV` completes.

## Immutable authority

- semantic source: `b2629040450c12507367c232f68a4d972b46450f`
- immutable package artifact: `9668492827`
- package ZIP SHA-256: `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`
- package internal manifest: **28/28 PASS**
- seven-identity selector SHA-256: `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`
- full 353 selector remains frozen at: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- runner GMP runtime: `libgmp-dev=2:6.3.0+dfsg-2ubuntu6.1`

## Authoritative execution evidence

- workflow run: `33128261911`
- execute job: `98711506300`
- result artifact: `9669229181`
- result artifact ZIP SHA-256: `364d5d546bca4c664be67e52b336a48cbc1f49b6bd672371ea6351e396dcc84c`
- diagnostic log artifact: `9669229414`
- diagnostic log ZIP SHA-256: `39c7530a70650702f4345fea9de558ea6139fecd715f8d9b504ef945a94447ef`
- result artifact and diagnostic log were downloaded after completion and independently re-hashed to those exact digests
- result artifact pre/post byte and mode inventories were independently compared after download: package equal, materialized source equal

## Seven-identity ledger

| Identity | Selected | Exit | Result |
|---|---:|---:|---|
| `TraceTerminationCorrection.ExactBarycentricPredicateSeparatesCrossingTouchAndOverlap` | 1 | 0 | PASS |
| `TraceTerminationCorrection.ArrivalFilterAndTiePolicyHaveNoSeniorityFallback` | 1 | 0 | PASS |
| `TraceTerminationCorrection.ProductionPriorityIsFixedAndAlternativesRemainDiagnosticOnly` | 1 | 0 | PASS |
| `TraceTerminationCorrection.SiteVocabularyIsDisjointAndTwoRingGainsNoContactTerminus` | 1 | 0 | PASS |
| `TraceTerminationCorrection.PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents` | 1 | 0 | PASS |
| `TraceTerminationCorrection.TerminalContactTamperIsRejectedAtExactLocusBinding` | 1 | 0 | PASS |
| `TraceTerminationCorrection.TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded` | 1 | 0 | PASS |

Aggregate: **7 required / 7 executed / 7 PASS / 0 RED / 0 zero-selected / 0 escaping C++ exceptions**.

The corrected torus identity passed and therefore confirms the CB2 test-contract correction at the diagnostic-gate boundary: zero trace/contact publication is required; lawful pipeline-authoritative structural rail endpoints are not forbidden.

## Boundary and integrity checks

- artifact-only runtime: **yes**
- repository timeout configured: **no**
- configure: **no**
- compile/relink: **no**
- repair build: **no**
- generated test discovery: **no**
- source/test/fixture/selector mutation: **no**
- package mutation: **no**
- package byte-and-mode postflight: **PASS**
- materialized-source byte-and-mode postflight: **PASS**
- GMP runtime supplied without rebuilding the package: **yes**

No regression or new candidate was observed by T4. Stable historical accounting therefore remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, and M3 package count **54**.

## Stop / successor

The exact next turn is **`M3-CP4c-0b-DG-T4-REV`**, independent evidence review under `TB-REVIEW`. The review must consume this T4 result/log evidence and adjudicate whether the green diagnostic gate is sufficient to unlock T5. **Do not execute the full 353-identity T5 acceptance suite in this turn.**
