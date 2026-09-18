# M4-CP-SCALE-CB23 — source-boundary global-cycle authority Code + Build report

**Turn:** `M4-CP-SCALE-CB23`
**Result:** **GREEN / COMPILE+PACKAGE ONLY**
**Semantic source:** `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff`
**Runtime boundary:** no generated Directional binary executed.

## 1. Implemented correction

CB23 implements the DEFN-R1 D1–D5 rule without widening the product seam:

- adds typed `SourceBoundaryCycleId` authority and source-global boundary-cycle facts;
- exposes the boundary numeric fact from the field producer's existing complete-cycle `effort_to_indices` result rather than recomputing it in the atlas;
- exactly reconciles legacy per-vertex boundary aliases before collapse;
- replaces both former `boundaryCycleByGlobalVertex` population paths with regional source-boundary support associations;
- requires those regional support edge sets to be disjoint and to cover the complete source-global boundary loop exactly;
- removes the remaining global `indexNumerator` versus regional `BoundaryLoop.turningLift` equality;
- preserves globally-interior separating and same-region slit owner/port semantics;
- keeps boundary global facts outside `FieldSingularityFact`/singularity-port production.

The semantic source touches exactly the intended nine files:

- `include/directional/authority/AuthorityIds.h`
- `include/directional/authority/FieldTransportAtlas.h`
- `include/directional/core/CartesianField.h`
- `include/directional/fields/CrossField.h`
- `src/authority/FieldTransportAtlas.cpp`
- `src/fields/CrossField.cpp`
- `src/fields/FieldMatching.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldTransportAtlasTests.cpp`

## 2. Static verification

Static inspection on the exact pushed source established:

- zero remaining `boundaryCycleByGlobalVertex` references;
- zero remaining comparisons of the source-global boundary numerator with regional `turningLift`;
- both the single-face-disc and general regional association population paths call the same support-association mechanism;
- focused later-runtime authority exists for the R9 skew-fan multi-region case, source-row/orientation permutation, single-face partial source-boundary support, alias tamper/missing/duplicate rejection, and support-cover rejection;
- selector426 SHA-256 remains `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- first425 SHA-256 remains `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- selector427 is absent;
- retained genus-two hashes remain OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No focused test body was executed in this Code + Build turn.

## 3. Compile/package evidence

Mandatory reusable compile authority completed GREEN:

- workflow run: `35378397152`
- compile job: `105708558821`
- exact semantic source: `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff`
- result artifact: `10560828304`
- result artifact SHA-256: `e84692e13d6de3b7bec46d8d5433b6b1c196e451187d5fb3a0a3fd6bb1d47ea1`
- log artifact: `10561148114`
- log artifact SHA-256: `a055968392dfadc84fb91332175747afd0501e9d01e9e374243028a53a6cc95f`
- root manifest: **28/28 verified**, SHA-256 `39e4dfa89c6203852b544395aad0651348f7d976110020b86a2a75968b2edff3`
- packaged source archive SHA-256: `7ad520fc87b184d04d2aa94b0a0f51782bbc6a6c7e95df92edfd84012788f83f`
- exact arithmetic backend: **GMP**, with both `gmpxx` and `gmp` on the authoritative owner-target link line;
- all packaged generated executables retain mode `0755`;
- all recorded source-status snapshots are clean;
- package records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.

The owner target compiled first, followed by the standard accepted target set:

1. `directional_surface_cell_authority_kernel_tests`
2. `directional_core`
3. `directional_pipeline`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

## 4. Disposition

CB23 is compile/package GREEN and satisfies its static stop/falsifier rules. This does **not** promote the candidate to accepted runtime authority and does not close R9 `RP-01`; those claims require fresh immutable artifact-only runtime evidence.

Accepted runtime authority therefore remains TB11 package `10473134357` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. S5/A3 remain uncredited and no selector427 exists.

Exact successor: **`M4-CP-SCALE-TB12-R10-EXEC`**, artifact-only, consuming immutable artifact `10560828304` and testing the CB23 boundary-authority controls before any production S5 retry.
