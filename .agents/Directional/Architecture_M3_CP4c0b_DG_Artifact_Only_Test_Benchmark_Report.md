# M3-CP4c-0b DG Artifact-Only Test + Benchmark Report

Date: 2026-08-27 UTC
Turn: `M3-CP4c-0b-DG`
Status: **COMPLETE / VALID SEMANTIC RED 6/7 / ROUTE TO INDEPENDENT REVIEW**

## Scope and immutable authority

This was the attempt-free, new-contract-only diagnostic gate authorized by `M3-CP4c-0b-CB1-S2-S6`. It consumed the immutable GMP/GMPXX package produced by the build turn and did not rebuild, configure, relink, repair, regenerate, discover replacements, or mutate package/source/test/fixture/selector bytes.

- semantic source: `737f93be10a73db950e2a7f823b96ffb0d59cf4d`
- immutable package artifact: `9664890562`
- package ZIP SHA-256: `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`
- DG selector: `.agents/Directional/Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`
- DG selector cardinality / SHA-256: **7** / `14570409facfb9c9072375cae3ad4319e383386380ee1060d4af75c6e61c5724`
- full required selector remains **353** / `91371d5ab637447c31c0d25e829be0d58fa61f17245e69bd231dcaec94f21efb`
- full 353-identity acceptance TB: **NOT RUN**

## Orchestration-only control failure

The first control run `33120437486`, execute job `98685729035`, stopped before any Directional process executed. Package integrity had passed, but the temporary harness checked the packaged fixture with `tar -tzf ... | grep -Fxq ...` under `set -o pipefail`; `grep` exited after the match and `tar` then reported a closed-pipe write error, which the harness misclassified as a missing fixture. This was an orchestration defect, not semantic evidence.

- result artifact: `9666237104` / `d1b4c27a4bf74ab5bf9133cf66242f6136456f18c175ca61688afbc7682d5aee`
- log artifact: `9666237713` / `e8754b6774c0bdcebc6a10678d207f5bd50089686d9aa99fb05d855148d0779c`
- Directional identities executed: **0**
- disposition: `M3-CP4c0b-DG-CAND-01`, **RESOLVED ORCHESTRATION / NON-STABLE**

Only the temporary harness was corrected: the tar listing is materialized first and the fixture lookup is then performed against that file. No semantic/package/test/fixture/selector byte changed. The corrected payload was repinned before a separate trigger.

## Authoritative corrected DG

| Evidence | Authority |
|---|---|
| workflow run | `33120730355` |
| execute job | `98686699036` |
| event/trigger SHA | `167f995b8f6de43811be4032c9eb7c1848387ac8` |
| result artifact | `9666352028` / `286f738f02315d72dea7cc03bed61bc12ef6b5345ddf15264a898b5bfa45db72` |
| diagnostic log | `9666352544` / `651e9cb9fc78d109d725fdf725fd26b72c450f6bba44fd77e638780c0df2712e` |
| schema report | `9666336581` / `1191d527f97ab8b7b2aa472de0baa1a60f6fe977f2d9e4b12c93eb8718f798b3` |
| schema-validator log | `9666337211` / `d4f8853503b824c03a277c4cc8cab79c13c3e23ca68402f94a00efc38fdd8f11` |
| observer log | `9666337089` / `66307c570f26a7f537b70babe13de231af8c127ac301a645d8c0cc5dd34eb35d` |

Authoritative result: **SEMANTIC_RED**, required/executed/passed/failed **7/7/6/1**. Every identity selected exactly once; `zeroSelected=0`; no escaping C++ exception was seen; no repository timeout was configured; configure/compile/relink/repair/generated-discovery flags are false; package/source/test/fixture/selector mutation is false; immutable byte-and-mode postflight is **PASS**.

## Seven-identity ledger

| Identity | Result |
|---|---|
| `TraceTerminationCorrection.ExactBarycentricPredicateSeparatesCrossingTouchAndOverlap` | PASS |
| `TraceTerminationCorrection.ArrivalFilterAndTiePolicyHaveNoSeniorityFallback` | PASS |
| `TraceTerminationCorrection.ProductionPriorityIsFixedAndAlternativesRemainDiagnosticOnly` | PASS |
| `TraceTerminationCorrection.SiteVocabularyIsDisjointAndTwoRingGainsNoContactTerminus` | PASS |
| `TraceTerminationCorrection.PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents` | PASS |
| `TraceTerminationCorrection.TerminalContactTamperIsRejectedAtExactLocusBinding` | PASS |
| `TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit` | **RED** |

The sole failure is at `tests/FieldAlignedCurveNetworkTests.cpp:6952`:

`torus.network->nodes().empty()` was **false** where the new identity expected **true**. In the same identity, the preceding zero-candidate-trace assertion passed, and no separate failure was reported for the following zero-event assertion.

## Red localization and review boundary

Static source authority shows that `canonical_field_aligned_candidate` constructs `candidate.nodes` from source singularity vertices and mandatory-edge endpoints before candidate tracing. Network-node publication is therefore structurally distinct from candidate-trace/event publication. The frozen CP4c-0b definitions do not state a general torus zero-node invariant; their torus role is zero trace/contact behavior. However, the prior S1 census recorded torus `A/B/C=0/0/0`, zero contacts, `nodeCount=0`, and no events. That delta is real evidence and must not be silently dismissed.

The open candidate is therefore recorded as `M3-CP4c0b-DG-CAND-02`: the new torus identity may have over-specified the contract surface by equating zero trace publication with zero network nodes, **or** the changed node publication may expose a real S2-S6 contract breach. This TB-EXEC closeout does not choose between those interpretations and authorizes no product or test correction.

No accepted-green predecessor regression is established by this DG: only the seven never-accepted new identities ran. Stable historical accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, and M3 package count **53**.

## Routing

The green-DG route to the full frozen 353 acceptance TB is **blocked**. Exact next is independent evidence review/planning turn **`M3-CP4c-0b-DG-REV`**. It must adjudicate `CAND-02` from the preserved DG evidence and frozen definitions before any semantic/test correction or runtime retry. Do not run the full 353 gate before that review authorizes a path.
