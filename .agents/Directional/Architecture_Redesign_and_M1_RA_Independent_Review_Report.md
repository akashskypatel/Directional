# Architecture Redesign and M1 R-A Independent Review

**Turn type:** independent Review; documentation changes only  
**Date:** 2026-08-12 UTC  
**Repository:** akashskypatel/Directional  
**Branch:** agent/surface_cell_quad/p5-recover-bridge-healing  
**Current independent-review branch boundary:** fd96852d19defe70effd0dc6fbbaf07db8378e55  
**Current reviewed implementation/test source:** cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e  
**Entering immutable runtime authority:** M1l bd140cff4572412e6f4ecd70a6ce0fe85310932c  
**Current verdict:** **overall R-A and REV-14-through-REV-16 are rejected; R-A-REV-17 through R-A-REV-20 are open**

## Current-status addendum — 2026-08-12 UTC

This report retains the historical review of source `bebac907...` below. The current independent checkpoint review inspected exact implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` at branch authority `fd96852d19defe70effd0dc6fbbaf07db8378e55`. Later branch commits changed durable documentation and removed temporary workflow/payload files; the reviewed production and test blobs are unchanged from `cb848e4...`.

**Current verdict:** **overall R-A and the requested REV-14-through-REV-16 review checkpoint are rejected.** The useful compile-only remediation remains historical partial evidence, but it does not establish the single-authority invariant.

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **not complete** | aggregate publication has no global owning source-authority product, derived identity caches become stale after typed remap, and named compatibility paths remain |
| R-A-REV-14 | **not independently accepted** | collision certificates are checked only for nonempty fields and the positive fixture fabricates unowned IDs while omitting source authority |
| R-A-REV-15 | **not independently accepted** | aggregation remaps typed IDs without publishing their owner, rebuilding dependent identities, or providing complete transactional rollback |
| R-A-REV-16 | **not independently accepted** | the pre-consumer seam is real, but its snapshot and validation oracle omit the defects above and the audit therefore produces a false closure result |

### Review boundary

- This was an independent Review turn. No production, test, fixture, benchmark, validator, build, workflow, or generated artifact source was modified.
- No configure, compile, discovery, generated test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input was executed.
- Existing compile-only evidence remains authentic partial evidence: run/job `31602025466 / 94131563590`, Release/static/Ninja/PRE_TEST **118/118**, result/log artifacts `9143819164 / 9143819888`, verified self-excluding manifest **21/21**, and no generated runtime execution.
- M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A-REV-17 — collision certificates are not validated against their owner

**Evidence**

- `typed_lineage_authority_certificate` in `src/geometry/PureQuadCompletion.cpp:1700-1720` only normalizes the region/sheet/chart vectors and requires nonempty values plus support. It does not prove that a region owns a sheet, that a chart owns its face, or that support is incident to the chart/region.
- `CompatibleCollisionPublishesOnlyPostIntersectionAuthority` in `tests/PureQuadCompletionPhase18Tests.cpp:1785-1911` appends region IDs 91/92, sheet IDs 93/94, and chart IDs 95/96 without constructing an authority that owns them. It calls `stitch_pure_quad_patches` without `sourceAuthority`.
- The public stitch API permits `sourceAuthority = nullptr` at `include/directional/geometry/PureQuadCompletion.h:602-607`; within stitching that pointer is used for shared geometric provenance, not certificate ownership validation.
- `resolved_authoritative_identity` at `src/geometry/PureQuadCompletion.cpp:1902-1938` accepts the exact stitch identity and an older partial typed identity as compatibility aliases for the canonical full certificate.

**Corrective measure**

1. Require complete `SourceTopologyRegions` plus chart/support ownership authority for semantic stitch publication.
2. Validate every incoming certificate and the final intersection against region-sheet ownership, chart-face ownership, and support incidence before registry insertion or publication.
3. Accept an absent cached authoritative identity by deriving it, or require exact equality with the canonical full identity; reject exact-only and partial-typed aliases.
4. Replace the fabricated positive with a naturally valid overlapping-but-nonidentical boundary certificate owned by the supplied authority. Add wrong-owner, sparse/unowned-ID, wrong-face, exact-only, and stale-partial-identity negatives; each must fail with zero publication.

### R-A-REV-18 — aggregate typed lineage is orphaned and its derived identities are stale

**Evidence**

- A single-component result retains `phaseFrontProduct->sourceTopologyRegions` at `src/pipeline/RemeshPipeline.cpp:6114-6115`.
- The disconnected-component aggregator spans `RemeshPipeline.cpp:9758-10850`; a complete search of that range finds **zero** assignment to `merged.surfaceCellContext.sourceTopologyRegions`. It publishes globally remapped region/sheet/chart IDs without publishing the immutable domain that owns those IDs.
- `remap_component_typed_lineage_authority` at `RemeshPipeline.cpp:8662-8866` rewrites `sourceTopologyRegions`, `sourceIsolationSheets`, `sourceCharts`, and `sourceSupport`.
- A complete search of `RemeshPipeline.cpp` finds **zero** assignment to `authoritativeIdentity`, `stitchIdentity`, `canonicalAuthoritativeCycleHash`, or `canonicalStitchCycleHash`. Those caches were produced before aggregation in `PureQuadCompletion.cpp:2776-2830`, while `hash_completion` later consumes both the remapped fields and stale caches at `RemeshPipeline.cpp:1641-1683`.

**Corrective measure**

1. Construct and publish one checked global `SourceTopologyRegions`/chart authority for the original source mesh before any aggregate semantic output becomes visible.
2. Remap through that published domain; validate every final lineage against it.
3. Recompute or remove every derived stitch/authoritative identity after final global remap, then regenerate each face's canonical stitch/authoritative cycle from the final vertex identities.
4. Add a two-component fixture with colliding local ID ranges and assert global ownership, canonical identity equality, and face-cycle regeneration for every published item. Inject a stale local cache and require rejection before publication.

### R-A-REV-19 — aggregate rejection and the REV-16 oracle are not transactional

**Evidence**

- Aggregation writes global source labels at `RemeshPipeline.cpp:10278-10291` and appends rails at `10340-10341` before output-lineage remap validation.
- `reject_component_merge_authority` at `10229-10254` clears mesh/output lineage/completed patches only. It does not reset already-published rails, source labels, debug products, cached optimization/validation products, or the rest of `SurfaceCellPipelineContext`.
- `ProductionAggregationRejectsUnownedTypedRemapWithZeroPublication` at `tests/SurfaceCellsPhase10Tests.cpp:5121-5163` asserts only the subset cleared by that lambda, so it cannot detect leaked context state or a valid first component left behind when a later component rejects.
- The aggregator performs no post-remap source-authoritative validation. It only accumulates each component's already-computed report at `RemeshPipeline.cpp:10763-10838`.
- The REV-16 typed snapshot at `SurfaceCellsPhase10Tests.cpp:5018-5058` omits the owning global authority, stitch/authoritative identity, and face-cycle caches. Its completion hash compares two equally stale cache sets, and its “downstream validation” comparison observes cached pre-aggregation reports.

**Corrective measure**

1. Stage every component's labels, rails, lineages, patches, debug products, metrics, and validation state in a transaction; commit only after all remaps and final validation succeed. Alternatively reset the entire semantic context to a documented non-consumable rejected state.
2. Run source-authoritative validation on the final merged/remapped product using the new global authority; do not substitute accumulated component reports.
3. Expand zero-publication negatives to fail the second component after a valid first component and assert every semantic payload/flag is empty or unavailable.
4. Expand the counterfactual oracle to compare the global owner, canonical identities, face cycles, and actual post-merge validation. Add malformed region, sheet, chart, support, and stale-cache variants.

### R-A-REV-20 — the complete R-A inventory still contains compatibility authority paths

**Evidence**

- `SurfaceOptimizationConstraints` retains raw `sourceComponent` beside optional typed authority, and `SurfaceFeatureCurveInterval` retains raw component/sheet fields at `include/directional/geometry/SurfaceMeshOptimizer.h:91-123`.
- `nearest_source_point` uses the raw point-cloud component fallback at `src/geometry/SurfaceMeshOptimizer.cpp:154-184`.
- The optimizer retains explicit `legacyIndex` feature-interval fallbacks at `SurfaceMeshOptimizer.cpp:275-334` and a “legacy standalone optimizer fixtures” fallback at `2611-2627`.
- `validate_final_surface_mesh` has an alternate basic-validator path when `sourceAuthority == nullptr` at `SurfaceMeshOptimizer.cpp:2852-2894`. Strict wrappers exist and the production pipeline calls them, but active R-A items 9-12 require the affected standalone compatibility branches and fixture exceptions to be removed or isolated outside the SurfaceCells authority boundary.

**Corrective measure**

1. Delete these compatibility paths from the affected SurfaceCells implementation or move generic non-SurfaceCells behavior into a separately typed API/module that the strict wrapper cannot enter.
2. Make every SurfaceCells optimizer/verifier helper transitively require complete typed source authority; remove raw component/sheet mirrors from affected semantic records.
3. Add missing-authority and alternate-validator-path contracts plus a static inventory that fails on the named legacy branches, raw mirrors, or bypass calls.

### Verified progress retained

The reviewed source does correctly establish checked/private `SurfaceTopologyRegion` and `SourceTopologyRegions` construction, exact face coverage, builder-only raw classifier ingress, a phase-front materializer API that accepts the owning product rather than parallel raw arrays, independent local remap tables with region/sheet/chart/support relationship checks, and a real pre-aggregation raw-tamper seam. Those improvements remain valid implementation progress; they are insufficient for checkpoint closure.

### Review conclusion

Do not mark overall R-A or REV-14-through-REV-16 independently accepted. Execute R-A-REV-17 through R-A-REV-20 in the next Code + Build turn, rerun the complete R-A inventory, and only then continue R-B through R-G and create a fresh full package.

## 1. Review boundary and evidence

This review inspected the supplied redesign, its supporting review/context, the current durable architecture and test records, the R-A source, the final compile record, and the source delta between the downloaded review snapshot and the reviewed source.

No project executable, generated test, discovery command, benchmark, ctest, CLI, fuzzer, or custom input was executed. No production, test, fixture, benchmark, validator, build, or workflow source was edited.

R-A compile evidence:

- workflow run/job 31550744314 / 93972723960;
- result artifact 9124167871, digest sha256:31841bfda6ad39fc5f5c3f2112e24beb5d3e872008e8a65d13985441509f95b8;
- log artifact 9124168143, digest sha256:caf0000f304444a960b051b8445c76be74dd238631ac5f30f3e36fee706f66d8;
- Release/static/Ninja/PRE_TEST compile/link **118/118**;
- all generated-runtime, test, benchmark, discovery, ctest, CLI, fuzzer, and custom-input execution flags false.

The inspected source snapshot was c4932dff1a4249d24224e1b64fea81bdccaba06f. Comparison to reviewed source bebac907... found no later R-A production change; the only later production file was the benchmark translation unit. The inspected R-A paths therefore represent the reviewed implementation.

## 2. Redesign assessment

The supplied DESIGN.md materially improves the prior architecture in four ways:

1. Pipeline B is now the explicit normative default: combinatorial cross-field tracing, a field-aligned curve network, a global topology plan, and a deterministic polynomial conformity/flow stage replace global coordinate integration.
2. Pipeline A is retained as an optional, evidence-gated future path with one integer-free global solve rather than iterative mixed-integer refactorization. It cannot become scheduled work until Pipeline B is Certified on the full representative matrix.
3. The missing A1-to-A2 derivation is made explicit through FieldAlignedCurveNetwork, singularity ports, branch-consistent tracing, typed termination events, motorcycle-style decomposition, and disc-region proofs.
4. Binary success/failure is replaced by verifier-assigned dispositions D0-D4. Degradation is explicit, bounded, non-recursive, certificate-carrying, and cannot close strict gates.

The architecture is scientifically plausible and better aligned with the project's performance goal. It does not yet prove that the adapted tracing/motorcycle composition works for the target input class, that every fixed-boundary region has a successful degraded producer, or that the proposed quality path reaches production thresholds. Those are milestone evidence obligations, not reasons to reject the architecture.

### 2.1 Design clarifications that remain open

These points must be resolved before their owning milestone is accepted:

- DESIGN.md section 6.7 invariant 2 says degradations are empty for QualityRelaxed with all gates passed, while D1 is defined by one or more missed calibrated quality gates. D1 must have a quality-gate degradation record; the invariant needs a narrow wording correction.
- M3 must prove that the Ray-Sokolov-style trace construction plus motorcycle termination/decomposition gives the claimed non-crossing, complete, disc-region network on supported triangle-mesh/cross-field inputs. The cited ingredients do not by themselves prove the combined algorithm.
- The A1 field-quadrangulability certificate needs an executable construction and independent tamper oracle before failure may be classified as FieldTransportUnestablished.
- M7 must specify and prove the one declared degraded region producer, including completion/manifoldness under the unmodified fixed boundary. It cannot be treated as guaranteed merely because its interface is named.
- T5 must calibrate geometry, alignment, approximation, and element-quality thresholds before D0/D1 can be assigned honestly.

The attached DESIGN.md is preserved byte-for-byte as the normative source. These are tracked clarification/evidence items rather than silent edits to the supplied design.

## 3. M1 R-A review

### 3.1 What the implementation established

The implementation makes substantial progress against R-A:

- SourceRegionFaceAuthority owns row-independent SourceFaceTopologyKey plus typed IsolationSheetId.
- SurfaceTopologyRegion and SourceTopologyRegions use private state and checked factories.
- the source-authority factory verifies unique row topology, contiguous typed region IDs, exact row coverage, one row binding per member, component agreement, sheet agreement, and topology/member agreement before publication.
- raw sourceFaceComponents and sourceFaceSheets are confined to the source-authority builder ingress.
- SourceEntityId is removed in favor of typed SourceSupport, SourceProjectionChart, and SourceVertexFanId.
- build_authoritative_phase_front_mesh accepts the owning SurfacePhaseFrontProduct, not parallel raw component/sheet arrays.
- materializer occurrences carry required typed occurrence, support, chart, and topology-region values.

These changes are compile-valid. Compile validity is not semantic/runtime acceptance.

### 3.2 Blocking finding R-A-REV-01 — materializer still reads raw sheet payload as authority

OccurrenceData stores typed support/chart/region but no required typed sheet. The materializer then:

- compares SurfacePoint::sheet to decide whether an ordinary-front equivalence crosses isolation sheets (src/pipeline/RemeshPipeline.cpp:2602-2606);
- includes SurfacePoint::sheet in the canonical representative ordering key (src/pipeline/RemeshPipeline.cpp:2800-2816).

Those values are derived from SourceTopologyRegions, but they are persisted in the generic geometry payload and then read back for semantic decisions. That is exactly the duplicate-authority path prohibited by the corrected authority model and R-A items 7-8.

**Required correction:** each occurrence must carry the required typed sheet/member authority obtained from SourceTopologyRegions; equivalence and representative logic must compare typed region/sheet/chart/support values. SurfacePoint component/sheet may remain only as a one-way geometry/export projection that affected production paths never read as authority.

### 3.3 Blocking finding R-A-REV-02 — completion/lineage still encodes raw component and sheet into identity

PureQuadPatch, PureQuadMesh, and PureQuadVertexLineage retain SurfacePoint provenance beside typed topology-region, chart, sheet, and support authority. More importantly, resolved_stitch_identity writes provenance.component and provenance.sheet into SurfaceCellCanonicalIdentity (src/geometry/PureQuadCompletion.cpp:1694-1721). That identity participates in equality, hashing, ownership conflict detection, and stitching.

This is not diagnostic export. It is a semantic read-back of the raw mirror and leaves R-A item 7 open.

**Required correction:** build fallback stitch/ownership identity from the typed lineage authority or make the typed identity mandatory before assembly. Remove raw component/sheet reads from patch, completion, assembly, lineage, verifier, and materializer semantic decisions.

### 3.4 Acceptance consequence

R-A items 1-6 and the API-removal portion of item 8 are substantially implemented. Items 7 and the semantic-consumption portion of item 8 are not complete. Therefore:

- R-A is **not accepted as complete**;
- R-A source is **compile-valid partial implementation**;
- artifact 9124167871 is **not** an M1 runtime-acceptance candidate;
- no new stable runtime regression is assigned because runtime was intentionally not executed;
- M1l remains the latest immutable runtime authority.

## 4. Historical next sequence — superseded

The original R-A-REV-01/02 sequence below is historical only. Do not execute a task selection from this report's historical sections. The active Code + Build plan owns current R-A-REV-17 through R-A-REV-20, the complete R-A inventory, R-B through R-G, and the fresh full package.
