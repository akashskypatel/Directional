# Architecture M6 CP2 CB2 Coverage Code + Build Report

**Turn:** `M6-CP2-CB2-COVERAGE`
**Verdict:** COMPLETE / COMPILE-PACKAGE GREEN / RUNTIME-FREE
**Successor:** `M6-CP2-TB2-COVERAGE-EXEC`

## Source and bounded implementation

RA-29d G1-G4 were implemented at exact semantic source
`5ce3132ec01748eff5b15f82be07a1abe2bd1af6`.

The final semantic patch was SHA-256
`959ab4f3d2f502324369f80eda5b8392402fed9fdbdf15edd99e3367d44e605b`,
diff-body SHA-256
`5b2d46f026f63ecc3daa7bc29f9e95990e777cfbf32a1f1619714ca881d5d0b9`,
based on `23a4663f840d05a5143515dd368a5562d70be234`, and changed exactly:

- `include/directional/pipeline/RemeshPipeline.h`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

The Drive apply workflow `37415698207` verified the exact base, patch hash,
diff-body hash and intended path set, then pushed the semantic commit. No
producer A5/A6/A7 semantic surface and no `SurfaceMeshOptimizer` source was
changed. `UncertifiedAuthoritySubstitution` was removed; the previously
predicate-less `BoundaryOrEulerMismatch` now owns independent recomputed
component / boundary-loop / Euler mismatches. A7 now has exact
`a7:vertex-binding` checks for representative membership, representative point,
embedded position and class-common support.

The focused-30, focused-12, selector449 and routing449 bytes remain unchanged:

- focused-30: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- focused-12: `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`

## G4 — frozen §6.2 recompute coverage

This is a Code + Build turn, so the table records the compiled executable
witnesses that TB2 must execute; it does not claim runtime proof here.

| Frozen §6.2 category | Production predicate | Compiled witness / classification |
|---|---|---|
| source face/edge/vertex incidence and A0 component authority | `src/pipeline/RemeshPipeline.cpp:7483-7508` (`a0:source-faces`, `a0:hard-feature-edge`) | identity 2 `VerifierRecomputesA0AndA5ElementaryIncidenceIndependently`, source-face mismatch and invalid hard-feature edge. RA-29c intentionally removed the invalid raw `a0:component-adjacency` reconstruction; component identity remains A0 authority rather than a downstream re-labeling rule. |
| exact incidence of published `SourceSupport` | `src/pipeline/RemeshPipeline.cpp:7568-7639` and `8158-8168` (`a5:support-resolver`, `a5:support-incidence`, wedge predicates, A7 support incidence) | identity 2 support-resolver / wedge-binding / wedge-isolation negatives; identity 4 support-cover and vertex-binding negatives. |
| occurrence ownership counts and directed-side cycle incidence | `src/pipeline/RemeshPipeline.cpp:7525-7558` (`a5:corner-owner`, `a5:directed-side-cycle`, `a5:exact-corner-ownership`) | identity 2 duplicate owner and directed-side-cycle negatives. |
| output quad/edge incidence, components, boundary loops, Euler and manifoldness | `src/pipeline/RemeshPipeline.cpp:8014-8147` plus `8335-8349` | identity 3 classed-topology tamper, exact third-cell `a6:edge-manifoldness`, and independent `a6:components`, `a6:boundary-loops`, `a6:euler` certificate-count negatives; existing pinched `a6:vertex-link` falsifier remains compiled. |
| cell-to-quad and occurrence-to-class membership from published IDs | `src/pipeline/RemeshPipeline.cpp:7764-7809`, `8025-8045`, `8254-8258` | identity 3 `a6:relation-class`/cell-topology membership negatives and identity 4 `a7:topology-copy`. |
| exact inversion/composition of a named relation certificate | `src/pipeline/RemeshPipeline.cpp:7860-8006` (`a6:selected-path-structure`, `a6:selected-path-certificate`, `a6:legacy-projection`, cycle closure) | identity 5 search/replace-route witness at `a6:selected-path-structure`; certificate-chain identity 6 remains the exact transport-binding witness. |
| source-support incidence of an A7 embedded vertex | `src/pipeline/RemeshPipeline.cpp:8158-8246` (`a7:class-binding`, `a7:support-cover`, `a7:vertex-binding`) | identity 4 contains all four G1 `a7:vertex-binding` tamper classes plus support-cover. |
| deterministic equality of immutable certificate payloads under semantic ordering | `src/pipeline/RemeshPipeline.cpp:8280-8363` (`certificate:a5`, `certificate:a6`, `certificate:a7`) and `8335-8349` | identity 4 A5/A6 certificate payload negatives; existing A7 certificate negative; identity 3 component/boundary/Euler certificate-count negatives. |

No §6.2 row is implemented by tolerance or by reusing a producer repair/search
decision.

## G4 — frozen §6.3 forbidden-class coverage

Identity 5 remains the same named identity and now contains exactly ten
table-driven rows. Runtime rows mutate only a copied verification-record view,
assert the tamper changed the record, and assert the exact failure code/site.
The last two rows are compile-time API-shape proofs.

| Frozen §6.3 forbidden class | Production reject surface | Identity-5 row |
|---|---|---|
| create or renumber IDs | `a5:duplicate-occurrence` / ownership checks near `RemeshPipeline.cpp:7517-7558` | `create-or-renumber-ids` → `OccurrenceOwnershipMismatch / a5:duplicate-occurrence` |
| union occurrences or replace representative | `a7:vertex-binding` at `RemeshPipeline.cpp:8230-8246` | `union-or-replace-representative` → `SourceSupportIncidenceMismatch / a7:vertex-binding` |
| search/replace route | selected-path structure checks near `RemeshPipeline.cpp:7860-7891` | `search-or-replace-route` → `NamedTransportMismatch / a6:selected-path-structure` |
| infer missing authority | A6 A5-authority lookup near `RemeshPipeline.cpp:7703-7717` | `infer-missing-authority` → `MissingPublishedAuthority / a6:a5-relation` |
| canonicalize malformed producer state | A6 class identity/order predicate in the class partition | `canonicalize-malformed-state` → `SemanticIdentityMismatch / a6:class-identity`, then asserts the malformed record is unchanged |
| substitute equivalent/reverse unowned relation | A6 exact A5 relation ownership near `RemeshPipeline.cpp:7703-7717` | `substitute-equivalent-or-reverse-relation` → `MissingPublishedAuthority / a6:a5-relation` |
| weld by coordinate/barycentric/position/proximity | A6 manifoldness and A7 exact vertex binding | `weld` → pinched `NonManifoldTopology / a6:vertex-link` plus moved-point `SourceSupportIncidenceMismatch / a7:vertex-binding` |
| repair directed side / quad / support / certificate | immutable record verification, including `a5:directed-side-cycle` | `repair` → `DirectedSideCycleMismatch / a5:directed-side-cycle` |
| mutate A5/A6/A7 or emit corrected product | public verifier signature | `mutate-products` compile-time trait proves no mutable-record verifier signature |
| fallback/recovery / producer-rejection conversion | public verifier overload set | `upstream-failure` compile-time trait proves no overload accepts `SurfaceOccurrenceComplexError` |

The identity body is at
`tests/SurfaceCellTransitionQuotientTests.cpp:7911-8095`. All runtime witness
rows are compiled but deliberately **not executed** in this turn; TB2 owns that
runtime proof.

## Compile/package evidence

Compile workflow run/job:
`37415985763 / 112114628756`.

Exact compiled source:
`5ce3132ec01748eff5b15f82be07a1abe2bd1af6`.

All standard eight targets compiled and linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Compile result artifact `11391685901`, provider SHA-256
`d2a3ef4f2bf40420fba21155bb264a8271c36ce18c41bc31a5e191af93739980`.
Compile log artifact `11390994385`, provider SHA-256
`5755622485216a5aedef88365f524ca0bbe24819d4714555f58d39fdb79b9157`.

The package self-manifest verifies **28/28** entries; `SHA256SUMS` itself hashes
to `0a71304d3a77ff99ad6332403927b9cb3cacc9de6647e3d84d1d9dfd3abaa0ce`.
Preflight/build exits are `0/0`; final source status is clean. The packaged
source archive SHA-256 is
`c7bbbdfac04ae55db6adaeb4f60bc6fcd757a01a01b3999369a52215b727f5c9`.

GMP/GMPXX evidence records
`/usr/lib/x86_64-linux-gnu/libgmpxx.so` and
`/usr/lib/x86_64-linux-gnu/libgmp.so` on the authoritative generated link
command, with `exactArithmeticBackend=GMP`. The command boundary records
`runtimeExecution=false`, `turnBoundary=Code+Build-only`, and an out-of-tree
PRE_TEST build. No generated Directional executable, test, benchmark,
discovery command, `ctest`, CLI, fuzzer, help command, or version command was
executed.

## Disposition

G1-G4 and the static/compile gate are satisfied for Code + Build. This turn
does not grant runtime acceptance or CP2 closure. Stable regression accounting
remains **60 / 16 / 44**, produced-witness debt **1**.

Exact successor is immutable artifact-only
`M6-CP2-TB2-COVERAGE-EXEC`: consume package
`11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6` without rebuild or
repair and execute focused-30 + focused-12 + selector449 = **491 fresh
exact-filter processes** using `TURN_ID`-derived upload paths. Regardless of
semantic outcome, route to mandatory `M6-CP2-CLOSE-REV`, which owns CP2
closure and `M6_CP2_Closure_Record.md`.
