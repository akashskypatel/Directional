# M6-CP1-CB1 — SurfaceOccurrenceComplex Code + Build Report

**Turn:** `M6-CP1-CB1`
**Type:** Code + Build only
**Result:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY
**Semantic source:** `ee8b8ac20571df5773f5f94bf9b382161f37a893`
**Compile run/job:** `36038472933 / 107764451786`
**Result/log artifacts:** `10826090221 / 10826115205`

## 1. Implemented A5 seam

The turn implements only the first M6-CP1 A5 cutover frozen by `Architecture_M6_CP1_CB1_Occurrence_Product_Code_Build_Plan.md`:

- `OccurrenceId` is a content-semantic `(CellId, canonicalCornerRole)` value. Position, lattice coordinate, storage row, output row, representative sheet and scheduler order do not participate in equality/order.
- `SurfaceOccurrenceComplex`, `SurfaceOccurrence`, `SurfaceOccurrenceCell`, `SurfaceOccurrenceRelation`, `OccurrenceComplexCertificate` and typed A5 failure codes are explicit immutable A5 publication surfaces.
- `SurfaceOccurrenceComplexProducer` owns cell/corner occurrence creation, directed-side cycles and owned-relation endpoint publication/validation.
- `build_authoritative_phase_front_mesh(...)` now consumes the produced A5 complex. Its existing A6/A7 transitional union/materialization remains inline; no later M6 stage was extracted in this turn.
- Semantic hashes were updated only to serialize the new semantic occurrence representation as `(CellId, canonicalCornerRole)`; no hash is identity authority.

No A6 `SurfaceQuotientProduct`, A7 source-attached product, A8 verifier, disposition/degradation, fallback/recovery, selector or M5 relation semantics were changed.

## 2. Focused compile-visible authority

Four new A5 identities compile in `directional_surface_cell_producer_tests`:

1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
2. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
3. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
4. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`

The permutation witness constructs the same square with the two source-face rows reversed, reruns the producer, and compares cell, occurrence and relation IDs. The relation-rejection identity separately covers a missing/foreign endpoint, a duplicated endpoint, malformed relation-ID ownership and a duplicate relation declaration. These are compile-visible only in this turn; they have not executed.

The first M6-CP1 artifact-only prepublication vector is frozen as those four identities plus:

5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

All six are focused-only and absent from accepted selector449. The pair-swap identity is retained unchanged per the binding M6-DEFN review amendment; it receives no M5 credit.

## 3. Dormant CB14 disposition and accepted selector preservation

- `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` is deleted as the one authorized no-credit dormant cleanup.
- `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` remains present unchanged and is in the TB1 focused vector.
- Accepted replacements `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` and `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` remain present.
- `Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt` remains 449 lines with LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.

No accepted selector byte was edited or published.

## 4. Compile correction history

Two compile-only integration defects were exposed and corrected within the plan's bounded A5 seam; neither produced runtime evidence:

- Run `36033818731` on source `5ca1c84f50bcf32cf2c2ad6b18593f079bf56219` failed because `RemeshPipeline.cpp`'s generic vector hash had no `OccurrenceId` overload. The correction hashes the semantic `(cell, canonicalCornerRole)` fields explicitly.
- Run `36036140454` on source `aa30db07c76370219337310ac5b3eb612891cd0c` failed because `BenchmarkQuality.cpp`'s generic semantic-ID serializer assumed `.index()`. The correction serializes semantic occurrence fields explicitly.
- Run `36036751134` on source `fc518374aac806d3e39a6257e5e78782c0fccb99` was compile/package green. A final static scope review then strengthened the focused A5 relation-rejection identity to cover malformed and duplicate endpoints explicitly; because test source changed, that earlier green package is superseded by the final package below.

These are compile-time representation-projection integrations, not semantic runtime regressions. Stable regression accounting remains **51 / 14 / 37** and project produced-witness debt remains **1**, M6-owned.

## 5. Final compile/package evidence

The mandatory reusable compile workflow compiled and linked the standard eight approved targets from exact semantic source `ee8b8ac20571df5773f5f94bf9b382161f37a893` with GMP/GMPXX:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Evidence:

- compile run/job: `36038472933 / 107764451786` — success;
- result artifact `10826090221`, SHA-256 `6e3c3b09d272e200f3c213aa5198ed805bff2f293f35b37a55b948176c870a9c`;
- diagnostic log artifact `10826115205`, SHA-256 `322e0c79116d5ae6fcc5f71663ff1f7b6fb45038966eff4669cc7743441d7bc0`;
- package manifest: **28/28** self-verifies;
- configure/preflight/build exits: **0 / 0 / 0**;
- exact arithmetic backend: **GMP**, with both `gmpxx` and `gmp` on the authoritative link line;
- source status receipts: clean;
- `runtimeExecution=false` and `semanticContracts=compiled-not-executed`.

No generated Directional binary, test, benchmark, discovery/list/help/version command, `ctest`, fuzzer or custom input executed in this Code + Build turn.

## 6. Disposition

`M6-CP1-CB1` is complete as a **candidate A5 package only**. It grants no M6 semantic credit, no CP1 closure and no G4 debt closure. The exact successor is `M6-CP1-TB1-EXEC`, which must consume the final package immutably, execute the six focused prepublication identities plus accepted selector449, and then hand off to mandatory `M6-CP1-TB1-REV`.


## 7. Closeout reconciliation and hygiene

A resumed closeout detected that concurrent turn-local work had already advanced the branch with the final relation-rejection test authority, final compile/package evidence, and durable CB1/TB1 records. A locally prepared redundant closeout-doc patch therefore failed closed in `agent-google-drive-reusable.yml` because intended paths had changed since its base; it applied no bytes and its staged Drive file was permanently deleted. The stale bottom summary in `TODO.md` was corrected to the already-authoritative successor `M6-CP1-TB1-EXEC`.

Final temporary-state cleanup run/job `36041971342 / 107776072302` succeeded. Result/log artifacts are `10825764480 / 10826779202`; cleanup commit `90e14c552827a1e5d99e71948346d4ada3da6396` removed all nine inventoried CB1 connector markers plus the cleanup manifest. The final workflow inventory contains exactly the seven durable agent workflows, with no connector-trigger, workflow-observation, or turn-payload directory remaining. Cleanup records `runtimeExecution=false` and deleted only temporary PR observation comments. No semantic source, candidate package, selector, accepted M5 authority, regression accounting, or M6 credit changed during closeout.
