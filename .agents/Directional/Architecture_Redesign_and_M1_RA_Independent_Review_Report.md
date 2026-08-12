# Architecture Redesign and M1 R-A Independent Review

**Turn type:** independent Review; documentation changes only  
**Date:** 2026-08-12 UTC  
**Repository:** akashskypatel/Directional  
**Branch:** agent/surface_cell_quad/p5-recover-bridge-healing  
**Current independent-review branch boundary:** db100d15b166a2ac19bf2bb45c829856b43bb5a9  
**Current reviewed implementation/test source:** 9d88d0e47cfc039e5399ebee334290b1eeae792b  
**Review decision/planning commit:** _recorded at push of this documentation-only commit_  
**Entering immutable runtime authority:** M1l bd140cff4572412e6f4ecd70a6ce0fe85310932c  
**Current verdict:** **REV-21 contract completion and REV-22-through-REV-24 are accepted at the Code + Build boundary; overall R-A remains rejected/open because no semantic contract has executed and one REV-22 negative does not reach the final oracle**

## Current-status addendum — R-A closure review after REV-21 coverage and REV-22 through REV-24

This Review inspected exact implementation/test source `9d88d0e47cfc039e5399ebee334290b1eeae792b` at branch boundary `db100d15b166a2ac19bf2bb45c829856b43bb5a9`. `git log --stat 9d88d0e4..db100d15` shows the 15 later commits touch only `.agents/` documents, `TODO.md`, connector triggers, and removed workflow YAML. **Zero implementation, test, fixture, or build source changed**, so the branch head is a valid review proxy for the compile-valid source. This Review changed durable planning documents only and executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input.

**Decision: the requested REV-22-through-REV-24 checkpoint is accepted at the Code + Build boundary. Overall R-A is not complete. Do not mark the R-A checkpoint accepted.**

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **rejected / open** | no semantic contract has executed; only compile and static evidence exists, and RA-REV-22-F1 leaves the final-oracle boundary/feature gates unproven |
| R-A-REV-21 | **accepted at Code + Build** | both required permutation-pair contracts are present and non-vacuous |
| R-A-REV-22 | **accepted at Code + Build with one required follow-up contract** | the source defect is fully corrected, but two of three required negatives reject at the pre-oracle seam guard |
| R-A-REV-23 | **accepted at Code + Build** | duplicate schema deleted; one canonical completion-owned constructor; kind derived from patch structure |
| R-A-REV-24 | **accepted at Code + Build** | entry-level authority proof precedes `sourceAuthorityUsed`; both required direct negatives present |

### Review boundary and evidence

- Compile run/job `31634075824 / 94239861945`, result/log artifacts `9156381103 / 9156381524`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`, self-excluding manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`. This proves buildability only.
- The complete R-A inventory was **independently reproduced during this Review**: `python3 .agents/Directional/R_A_Closure_Inventory.py --root .` against the current tree produced output **byte-for-byte identical** to the committed `R_A_Closure_Inventory_Report.md` (zero diff lines). Confirmed 17 affected paths, 38 probes, 164 probe matches, 22/22 allowed raw-projection leaves, 2/2 allowed face-count leaves, zero unexpected leaves, final static PASS. This closes the prior review's objection that the source-audit record was conclusion-only.

### Verified closures

- **REV-24.** `SourceAuthoritativeMeshValidator.cpp:1027-1037` requires non-null `sourceAuthority` and `matches_source_faces(*sourceFaces, sourceVertices->rows())` in the same entry guard as vertices/faces/provenance, and sets `sourceAuthorityUsed` only after it returns. The former `requireLocalSheetCompatibility`-gated null check is now an unreachable fallback rather than the sole owner. `SourceAuthoritativeMeshValidatorPhase22Tests.cpp:96` and `:124` supply the direct null and same-extent foreign negatives with all three optional gates disabled; the foreign case pre-asserts `matches_source_faces` is false so it cannot pass vacuously.
- **REV-21.** `SourceTopologyRegions::matches_source_faces` (`SourceTopologyRegions.h:151-188`) reconstructs a `SourceFaceTopologyKey` per row and requires equality with `topology_for_row(row)`; `SourceFaceTopologyKey::make` (`AuthorityKernel.cpp:33-42`) sorts and rejects repeated vertices, so the key is genuinely row-order-independent. `SurfaceCellsPhase10Tests.cpp:5564` permutes only the matrix while retaining the original authority and requires both `matches_source_faces` and `SourceChartTransitionGraph::available()` to fail; `:5588` rebuilds paired authority, requires the pair to match, requires the stale authority to fail, and requires semantic region-snapshot equality.
- **REV-23.** The duplicate pipeline constructor formerly at `RemeshPipeline.cpp:9758-9824` is deleted. `rebuild_aggregate_output_identity_caches` (`RemeshPipeline.cpp:9822-9942`) calls `pure_quad_detail::canonical_lineage_stitch_identity` and `canonical_authoritative_identity`. Verified single-source: the canonical constructor delegates to the same private `typed_lineage_stitch_identity` builder used by `resolved_stitch_identity`, derives kind from `patch.boundaryVertices` membership rather than the cached kind, and keeps chart/support out of the stitch key. Boundary-node caches and both face cycles are regenerated from the rebuilt identities. `SurfaceCellsPhase10Tests.cpp:5263` flips kind and injects a stale token into canonical values and boundary-node identities and requires the rebuild to overwrite all of them; `:5166` requires exact equality with the canonical factory, requires a generated-interior vertex to be exercised, and performs a post-publication `stitch_pure_quad_patches` re-stitch.
- **REV-22 source defect.** `RemeshPipeline.cpp:11494-11523` stages and globally remaps boundary edges/loops, feature rails, hard-feature edges, vertex-chart authority, output-quad source faces, and provenance, and enables all three strict gates. Authority is captured pre-aggregation by `captureFinalValidationAuthority` (`:10050`) and protected against post-capture tamper by `same_surface_cell_rail_authority`, so it is not derived from the merged product under check. Published `validationResult` is overwritten with the oracle's outputs at `:11577-11599` instead of the accumulated component reports. The positive fixture `make_disconnected_square_pair_mesh` is two open unit squares, so it is genuinely boundary-bearing and directly exercises the original false-`ChangedBoundaryLoop` condition.

### RA-REV-22-F1 — the two missing-authority negatives never reach the final oracle

**Evidence**

- `MissingComponentBoundaryAuthorityRejectsBeforeAggregatePublication` (`SurfaceCellsPhase10Tests.cpp:5347`) and `MissingComponentFeatureAuthorityRejectsBeforeAggregatePublication` (`:5391`) erase a rail after capture and both assert `surfaceCellFirstInvalidProducerReason == "ChangedComponentValidationAuthority"`.
- That reason is raised by the `same_surface_cell_rail_authority` seam guard at `RemeshPipeline.cpp:10642-10648`, which runs at component index 1 — roughly 870 lines before the final oracle call at `:11517`. The tests prove capture-versus-mutation consistency, not final-oracle enforcement.
- `MeshValidationFailureCode::MissingBoundaryAuthority` and `MissingFeatureRail` are asserted only at component/optimizer level (`SurfaceCellsPhase10Tests.cpp:679`, `SurfaceMeshOptimizerPhase22Tests.cpp:603`), never on the aggregate path. Only `FinalMergedOracleRejectsPostComponentProvenanceTamper` reaches the oracle, and it tampers provenance rather than boundary or feature authority.

**Corrective measures**

1. Add an aggregate negative that corrupts or drops a remapped entry in `globalValidationBoundaryLoops`/`globalValidationBoundaryEdges` so the seam guard passes and the oracle rejects with `FinalMergedSourceAuthorityValidationFailed` carrying `MissingBoundaryAuthority` or `ChangedBoundaryLoop`.
2. Add the equivalent negative for `globalValidationFeatureRails`/`expectedFeatureRailCount` requiring `MissingFeatureRail`. Assert zero aggregate publication in both.
3. Rename the two existing tests to state what they prove, for example `ComponentValidationAuthorityTamperRejectsAtAggregationSeam`, so the names no longer imply oracle coverage.

### RA-REV-22-F2 — three published validation flags are hardcoded

**Evidence**

- `RemeshPipeline.cpp:11579-11587` assigns `strictValidationUsed`, `provenanceValidationUsed`, and `authoritativeFeatureRailsUsed` literal `true` instead of sourcing them from `finalAuthorityValidation`.
- `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches` asserts `strictValidationUsed` and `authoritativeFeatureRailsUsed`; neither can fail under any input. The remaining assertions in that test are oracle-sourced and do carry evidence.

**Corrective measures**

1. Derive `strictValidationUsed` and `authoritativeFeatureRailsUsed` from oracle observables, or drop the two tautological assertions and rely on the oracle-sourced ones.

### RA-REV-22-F3 — final-oracle evidence is discarded when a component report is missing

**Evidence**

- The publication block at `RemeshPipeline.cpp:11577` is gated on `allCompletedSurfaceCells && allHaveValidationResult && !firstValidationResult`. The oracle call at `:11517` is unconditional and still rejects the merge on failure, so the gate itself is not weakened, but a successful final-oracle result is dropped from the published context with no diagnostic when any component lacks a report.

**Corrective measures**

1. Publish the final-oracle outcome, or a typed record stating that the oracle passed while component reports were incomplete, independently of component-report availability so consumers can distinguish "oracle not run" from "oracle ran and passed".

### RA-REV-23-F1 — the duplicate-schema probe is keyed to one identifier

**Evidence**

- The REV-23 probe "duplicate pipeline stitch-key constructor is deleted" matches the literal symbol `rebuild_aggregate_stitch_identity` with expectation `absent`. A renamed reintroduced duplicate builder would leave the probe green.

**Corrective measures**

1. Replace the name-specific probe with a structural one: require that `PureQuadStitchIdentityKind::` never appears as an assignment target under `src/pipeline/`, and that `stitchIdentity` assignments in `RemeshPipeline.cpp` occur only through `canonical_lineage_stitch_identity`.

### Durable-document trims applied by this Review

- `Architecture_M1l_..._Test_Benchmark_Report.md` section 12 directed the next turn to a nonexistent `Architecture_M1m_..._Code_Build_Plan.md`. It is now marked superseded and points at the authoritative plan.
- `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md` sections 4 through 6 are now marked retained history, because their file-level instructions (for example deleting the already-absent `LegacyAuthorityAdapters.h`) read as active work.
- All other `.agents/` and `TODO.md` cross-references resolve. `Architecture_M1_..._Artifact_Only_Test_Benchmark_Report.md` and `tests/fixtures/surface-cells/manifest.json` remain correctly phrased prospective deliverables of dormant plans; no action taken.

### Review conclusion

The requested REV-22-through-REV-24 checkpoint passes at the Code + Build boundary and is marked accepted there. Overall R-A stays open: the only evidence in existence is compile and static evidence, and compile success is not semantic acceptance.

The authoritative next turn remains the **artifact-only Test + Benchmark cadence turn** against the exact fresh package, approved unchanged with two amendments:

1. Expect `MissingComponentBoundaryAuthorityRejectsBeforeAggregatePublication` and `MissingComponentFeatureAuthorityRejectsBeforeAggregatePublication` to reject at the seam guard rather than the final oracle. Classify that as expected-but-insufficient coverage, not as REV-22 closure evidence.
2. Even if the focused runtime gate passes organically, R-A closes only after RA-REV-22-F1 is implemented and executed. RA-REV-22-F2, RA-REV-22-F3, and RA-REV-23-F1 are next Code + Build items and do not block R-A.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Retained prior-status addendum — R-A closure review after REV-18 through REV-21

The prior Review inspected exact implementation/test source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca` at branch boundary `922c36b43b8d35af2d2ffdeccb8e0c2ef551c760`. The 13 later commits between that source and the review boundary change only four durable planning/status documents. No production, test, build, workflow, or fixture source was changed in that Review.

**Decision at that boundary: overall R-A was not complete.** The REV-22, REV-23, and REV-24 findings recorded below are superseded by the current addendum, which accepts them at the Code + Build boundary. Do not execute a task selection from this retained section.

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **rejected / open** | mandatory semantic contracts never executed, the complete inventory is not reproducibly recorded, and three source-level authority/oracle defects remain |
| R-A-REV-18 | **bounded compile-only progress; not accepted** | a global owner is built, but aggregate identity rebuilding emits a noncanonical stitch schema and trusts stale cached kind |
| R-A-REV-19 | **bounded compile-only progress; not accepted** | publication is staged, but the new final oracle rejects ordinary boundary meshes and omits strict boundary/feature/chart authority |
| R-A-REV-20 | **reopened at validator boundary** | named optimizer compatibility branches remain absent, but the public source-authoritative validator can accept null typed authority when local-sheet checking is disabled |
| R-A-REV-21 | **core binding present; contract incomplete** | exact row-topology matching is implemented, but the required authority-only row-permutation negative and consistently paired permutation positive are absent |
| R-A-REV-22 | **open / new finding** | final aggregate validation is neither usable on boundary inputs nor authority-complete |
| R-A-REV-23 | **open / new finding** | aggregate stitch-identity rebuilding diverges from the canonical completion contract |
| R-A-REV-24 | **open / new finding** | source-authoritative validation retains a null-authority fail-open mode |

### Review boundary and evidence

- Compile run/job `31625763711 / 94211611771` succeeded. Independent artifact inspection verified exact source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca`, result/log artifacts `9153147035 / 9153147459`, outer SHA-256 values `bbc07fad9a767dc77aff290c540659b4140aab414ddf1148dec1b637fc32af38` and `ad5984db04ab98a4bbcd058d58c83e1cdef2383890b8bcfab1c209e487b3889b`, **26** regular files, self-excluding manifest **25/25**, five empty source-status snapshots, and `runtimeExecution=false`.
- Release/static/Ninja/PRE_TEST compiled and linked **118/118** targets. This proves buildability only; none of the new semantic contracts executed.
- The packaged REV-18-through-REV-21 source-audit record is a conclusion-only summary. It records no checked-path inventory, commands, match counts, or allowed-leaf classification, so it cannot establish the required complete R-A inventory.
- A direct review inventory confirmed zero affected `SourceEntityId`, `sourcePositions`, `constraints.sourceComponent`, `featureIntervals`, `legacyIndex`, or named standalone-fixture compatibility matches in `include/` and `src/`; `complete_for_face_count` remains only as the implementation detail used by `matches_source_faces`.
- This Review executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input.

### R-A-REV-22 — final merged-product oracle is unusable and incomplete

**Evidence**

- `RemeshPipeline.cpp:11260-11274` constructs aggregate validator options without authoritative boundary loops/edges, feature rails, hard-feature edges, vertex chart authority, or output-quad face authority. It explicitly disables boundary and feature authority.
- `SourceAuthoritativeMeshValidator.cpp:1076-1105` nevertheless always compares actual boundary cycles with supplied expected cycles. On any source with a boundary, the aggregate caller supplies an empty expected set, so a valid output receives `ChangedBoundaryLoop`. The compiled disconnected-aggregation positive cannot establish its asserted success until it actually runs.
- Even for closed inputs, omitting hard-feature/chart/rail authority makes this call weaker than the component strict validator and therefore not the required post-merge semantic oracle.

**Corrective measures**

1. Stage and globally remap every validator authority input required by the component strict path: ordered boundary cycles/edges, hard-feature edges and rails, vertex chart authority, output-quad source-face authority, and provenance.
2. Invoke the strict source-authoritative validator on the final staged mesh with applicable authority gates enabled. Do not derive expected authority from the output being checked.
3. Add boundary-bearing disconnected positives, missing/tampered boundary and feature negatives, and an assertion that proves the final strict oracle executed and accepted the valid merged product.

### R-A-REV-23 — aggregate stitch identities use a second incompatible schema

**Evidence**

- Canonical completion construction at `PureQuadCompletion.cpp:1924-1963` derives stitch kind from boundary/interior ownership and encodes only the exact local key plus normalized topology regions and isolation sheets. Chart/support authority is encoded separately by `canonical_typed_authority_identity`.
- `RemeshPipeline.cpp:9758-9824` reimplements that builder, copies `lineage.stitchIdentity.kind` from the pre-remap cache, and appends source charts and support to the stitch key. This is a different schema and preserves stale kind authority.
- `resolved_stitch_identity` at `PureQuadCompletion.cpp:1984-2001` recomputes the canonical completion key for generated interior vertices and rejects a cached key that differs. A published aggregate interior lineage rebuilt by the new helper is therefore not consumable by the canonical stitch path.
- Added aggregate tests assert validity and compute authoritative identity from the already-mutated stitch key. The stale-cache test changes only canonical values, not kind, and no test re-stitches published aggregate patches.

**Corrective measures**

1. Delete the duplicate pipeline stitch-key constructor and expose/use one canonical completion-owned construction API.
2. Derive boundary/interior kind from authoritative patch structure, not the old cache; normalize region/sheet authority once and keep chart/support only in the authoritative certificate identity.
3. Add a stale-kind counterexample, exact equality with the canonical factory, and a post-publication re-stitch/resolve contract covering generated interior vertices.
4. Regenerate boundary-node caches and face cycles only from those canonical rebuilt identities.

### R-A-REV-24 — source-authoritative validator can accept missing typed authority

**Evidence**

- `SourceAuthoritativeMeshValidator.cpp:1028-1041` requires source vertices, faces, and provenance but not `sourceAuthority`; it sets `sourceAuthorityUsed=true` before proving a non-null matching authority.
- Null authority is rejected later only when `requireLocalSheetCompatibility` is true at `1205-1217`. A caller that disables that option can traverse the otherwise valid geometry/provenance path with no typed owner while the result falsely reports that source authority was used.
- Existing missing-authority tests exercise optimizer/final-wrapper predicates, not this direct public validator option combination.

**Corrective measures**

1. Require non-null `sourceAuthority` and exact `matches_source_faces` success at validator entry, independent of optional boundary/feature/local-sheet gates.
2. Set `sourceAuthorityUsed` only after that proof succeeds.
3. Add a direct null-authority negative with optional gates disabled, plus a same-extent foreign-authority direct negative; both must reject with `MissingSourceAuthority`.

### R-A-REV-21 contract completion

The exact `matches_source_faces` implementation and consumer migration are useful progress. Complete the prior test matrix: permute only source rows while retaining the original authority and require pre-publication rejection; then permute the source matrix and rebuild/pair its authority consistently and require the same semantic result. The existing row-permutation test builds two independently valid networks and does not exercise the mismatched-pair counterexample.

### Review conclusion

Return to Code + Build for REV-22 through REV-24 and the missing REV-21 contracts. Rerun the complete retained R-A inventory through REV-24 with reproducible checked paths, commands, counts, and allowed leaves; then build one fresh focused package. Only a later immutable Test + Benchmark turn may execute that package and close R-A. Partial artifacts `9153147035 / 9153147459` remain authentic compile history but are superseded as a runtime task and must not be executed or relabeled as acceptance evidence.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Retained prior-status addendum — R-A closure review after REV-17/REV-20 partial remediation

The current review inspected exact implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` at branch authority `356a0bc2733af41e15fad056161e526865c147c5`. Six later commits modify durable documents only. Review decision/planning commit: `49b94da971ff544ac77f9dd2fa394791a1b67435`.

**Decision: overall R-A is not complete. Do not mark the R-A checkpoint accepted.**

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **rejected / open** | REV-18 and REV-19 are unimplemented; the complete inventory also found extent-only source-authority binding |
| R-A-REV-17 | **retained bounded progress; not independently accepted** | owner/certificate/canonical-cache changes are present and compile-valid, but a foreign same-extent authority still passes and runtime contracts did not execute |
| R-A-REV-18 | **open / not implemented** | aggregate publication still has no global owner and does not rebuild post-remap vertex/face identity caches |
| R-A-REV-19 | **open / not implemented** | aggregate publication remains non-transactional and still substitutes cached component reports for final merged validation |
| R-A-REV-20 | **retained bounded progress; not independently accepted** | named compatibility paths are removed/fail-closed for missing authority, but “complete authority” remains face-count-only and runtime contracts did not execute |
| R-A-REV-21 | **open / new finding** | paired source geometry and authority are not proven to describe the same topology |

### Review boundary and build evidence

- The implementation delta from prior review head `7b10c1c3cde9769438991742594676ec75e4200a` to `1352f3...` changes 12 implementation/test files. `RemeshPipeline.cpp` has only two deletions; `SurfaceCellsPhase10Tests.cpp` is unchanged. This directly disproves a REV-18/REV-19 implementation claim.
- Run/job `31616904715 / 94181880684` is successful. GitHub records result artifact `9149834162` with SHA-256 `c5055df51d9b94605c27817e596a04983bddb33956727a2c47c494d42a0b2ee2` and log artifact `9149834634` with SHA-256 `04291253c21af768af9c35b61f12e327c0ec536642a2ddf8895781657b1261a7`.
- The retained package record establishes Release/static/Ninja/PRE_TEST **118/118**, self-excluding manifest **21/21**, clean source snapshots, and `runtimeExecution=false`. It is compile evidence, not semantic acceptance.
- This Review changed durable documents only. It executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input.

### Retained REV-17 progress

- `owner_validated_typed_authority_certificate` at `PureQuadCompletion.cpp:1757-1820` checks every claimed chart against the transition graph, support incidence, owning region, and owning sheet.
- Certificate intersection is explicit at `1836-1859`; a present cached identity must equal the canonical full identity at `2016-2048`.
- Stitching requires non-null source faces/authority at `2386-2408`, validates every input/intersection, and creates duplicate-face conflict diagnostics only from the final global authoritative-identity inventory at `2691-2733`.
- The owned overlap contract and wrong-owner/sparse/wrong-sheet/wrong-face/exact-only/stale negatives are present in `PureQuadCompletionPhase18Tests.cpp:1797-2239`.

These changes address the bounded REV-17 defects. They do not close R-A while REV-18/REV-19/REV-21 remain and no immutable runtime contract has run.

### Retained REV-20 progress

- The affected optimizer surface no longer contains `sourcePositions`, `constraints.sourceComponent`, `featureIntervals`, `legacyIndex`, the named standalone-fixture fallback, or the alternate basic-validator branch.
- `source_optimization_has_complete_authority` now fails absent authority and invalid source shapes/indices at `SurfaceMeshOptimizer.cpp:1827-1846`; optimizer and final-validator entry points fail closed when that predicate is false.
- The missing-authority optimizer/final-validator contract is present in `SurfaceMeshOptimizerPhase19Tests.cpp:109-137`.

These changes address the named REV-20 compatibility paths. They do not establish exact owner binding, and the compiled contracts were not executed.

### R-A-REV-18 — global aggregate owner and derived identity remain open

**Evidence**

- The aggregate span `RemeshPipeline.cpp:10004-10846` contains zero assignment to `merged.surfaceCellContext.sourceTopologyRegions`.
- It remaps lineage authority at `10347-10475` but contains zero assignment to `stitchIdentity`, `authoritativeIdentity`, `canonicalStitchCycleHash`, or `canonicalAuthoritativeCycleHash`.
- The REV-17/REV-20 delta changes only two unrelated lines in this file and no aggregation test.

**Corrective measure**

1. Build and publish one checked global source-authority product for the original source mesh.
2. Validate every final global lineage against it.
3. Recompute or remove vertex identity caches after remap and regenerate both face cycles from final identities.
4. Compile colliding-local-domain, stale-cache, wrong-owner, and zero-publication contracts.

### R-A-REV-19 — transactional publication and final merged oracle remain open

**Evidence**

- Labels are written at `RemeshPipeline.cpp:10272-10289` and rails are appended at `10295-10340` before lineage remap validation.
- `reject_component_merge_authority` at `10227-10252` clears mesh/output lineage/completed patches only; it does not reset already written labels, rails, debug/context state, optimization, or validation.
- The aggregate calls `accumulate_surface_validation_report` at `10759-10767` and publishes that cached result at `10832-10836`; it contains no call to the source-authoritative validator on the final merged product.
- The existing zero-publication test asserts only the subset cleared by the rejection lambda.

**Corrective measure**

1. Stage every semantic/context product and commit only after all components, remaps, identity rebuilds, and final validation succeed.
2. Make rejection expose one documented non-consumable empty semantic context, including failure in a later component after an earlier valid component.
3. Run actual final source-authoritative validation against the global owner; retain component reports as diagnostics only.
4. Expand the counterfactual snapshot to global owner, all remap domains, canonical identities, face cycles, complete rollback, and final validation.

### R-A-REV-21 — source authority is bound by extent, not topology

**Evidence**

- `SourceTopologyRegions::complete_for_face_count` returns only `rowBindings_.size() == faceCount && !regions_.empty()` at `SourceTopologyRegions.h:139-140`.
- Stitching at `PureQuadCompletion.cpp:2397-2405` and owner validation at `1763-1805` use that extent predicate. They validate claims within the supplied authority and incidence within the supplied face matrix, but never compare `sourceAuthority.topology_for_row(row)` with the checked topology key constructed from that matrix row.
- `source_optimization_has_complete_authority` at `SurfaceMeshOptimizer.cpp:1827-1846` checks pointer, dimensions, row count, and vertex index bounds only.
- Therefore an authority constructed for a different mesh with the same face count can be treated as complete: its owner relations validate tautologically while support/projection uses another mesh. Current negatives cover null/unowned fields, not this foreign-owner counterexample.

**Corrective measure**

1. Introduce one shared exact binding predicate for every affected `(sourceFaces, SourceTopologyRegions)` boundary.
2. Construct the checked `SourceFaceTopologyKey` for every source row and require equality with `topology_for_row(row)`; reject repeated/invalid/out-of-extent source vertices.
3. Apply it transitively to completion/stitching, `SourceChartTransitionGraph`, optimizer helpers/wrappers, source-authoritative validation, and pipeline ingress.
4. Compile a same-face-count/wrong-topology negative, an authority-only row-permutation negative, and a consistently permuted matrix-plus-authority positive. Every negative must fail before semantic publication.

### Review conclusion

Return to Code + Build for REV-18, REV-19, and REV-21, then rerun the complete retained R-A inventory. The focused runtime turn for partial artifacts `9149834162 / 9149834634` is superseded because the package is source-incomplete and lacks the REV-21 counterexample. Continue R-B through R-G and create one fresh full package only after R-A closes.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Retained prior-review addendum — 2026-08-12 UTC

This report retains the historical review of source `bebac907...` below. The current independent checkpoint review inspected exact implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` at branch authority `fd96852d19defe70effd0dc6fbbaf07db8378e55`. Later branch commits changed durable documentation and removed temporary workflow/payload files; the reviewed production and test blobs are unchanged from `cb848e4...`.

**Verdict at that prior boundary:** **overall R-A and the requested REV-14-through-REV-16 review checkpoint were rejected.** The useful compile-only remediation remains historical partial evidence, but it does not establish the single-authority invariant.

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

### Prior review conclusion

At that boundary, overall R-A and REV-14-through-REV-16 were not independently accepted, and REV-17 through REV-20 were assigned. The current-status addendum supersedes that task selection.

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
