# M1 Single-Authority Cutover — Artifact-Only Test + Benchmark Plan

**Turn type:** retained Test + Benchmark plan; currently dormant  
**Validated source to consume:** the future full R-A-through-R-G cutover source; no historical or partial package recorded in `CHANGELOG.md`
**Entering immutable comparison authority:** M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Code + Build result artifact:** pending full-cutover package  
**Code + Build result artifact digest:** pending  
**Code + Build log artifact:** pending  
**Review policy:** `never`  
**Product gate after M1 acceptance:** resume the Pipeline B product queue under the revised M2-M8 architecture; select the smallest owning milestone required by the active product blocker

## 0. Activation amendment — 2026-08-12

This plan is retained but **not executable now**. Complete R-A review through branch head `344f996...` verified the compile/package provenance of exact implementation/test source `78056ba...` and rejected closure on R-A-REV-14 through R-A-REV-16. Historical findings and partial artifacts remain in `CHANGELOG.md`; none may be reused or relabeled as M1 acceptance evidence.

Activate this plan only after a new Code + Build turn:

1. closes R-A-REV-14 through R-A-REV-16 and passes the complete R-A gate;
2. completes R-B through R-G;
3. produces one fresh exact-source package with compiled contracts, fixtures, a counterfactual expanded audit, logs, clean source provenance, and a self-excluding checksum manifest verified before upload;
4. records the new immutable source/artifact IDs, digests, manifest authority, executable inventory, and command-boundary flags in this plan.

The replacement `DESIGN.md` remains normative. M1 acceptance proves only the single-authority contract; strict product fixtures require D0-equivalent behavior.

## 1. Purpose and turn boundary

Validate the exact immutable package produced by the final M1 Code + Build turn. This turn decides whether the single-authority cutover preserves the required semantic/product invariants strongly enough to close M1.

This is an **artifact-only** turn. Do not configure, compile, relink, regenerate code or discovery, patch packaged source, modify packaged fixtures/manifests, or edit implementation/test/benchmark/validator/build logic. If the package is invalid, report an infrastructure/package failure; do not rebuild it in this turn.

Runtime execution is allowed only from the immutable packaged executables and packaged inputs after preflight authority succeeds.

## 2. Immutable package authority

Expected package facts to copy exactly from the future Code + Build report when this plan is activated:

- implementation commit, immediate source parent, and entering accepted M1l source `bd140cff4572412e6f4ecd70a6ce0fe85310932c`;
- result/log artifact IDs, outer digests, and retention metadata;
- recursive manifest entry count and manifest digest; the manifest does not include itself and its complete verification passed before upload;
- fixture file count, packaged executable/library inventory, source/archive/diff/audit closure, and clean pre-build source status;
- every Code + Build command-boundary flag false.

Treat the package metadata and checksums as the source of truth. Stop before runtime if these facts do not close exactly.

## 3. Preflight — verify before any generated-binary execution

Extract the downloaded artifact into a fresh arbitrary directory using a method that preserves its natural executable mode bits. Do not `chmod`, repair, or mutate the package.

Verify, in order:

1. downloaded artifact identity/digest matches the newly activated artifact authority and recorded outer SHA-256;
2. `SHA256SUMS` exists, excludes itself, has the newly recorded entry count and manifest digest, and `sha256sum -c SHA256SUMS` passes every entry;
3. package contains no symlink or path escape and extraction did not rewrite packaged files;
4. `metadata/build-authority.json` names the newly recorded exact implementation, immediate parent, entering M1l `bd140c...`, Release/Ninja/PRE_TEST, and fixture count;
5. `metadata/command-boundary.txt` and JSON metadata record all of these as false: runtime, gtest-list, tests, benchmarks, ctest, CLI, fuzzer, custom input;
6. `metadata/source-cutover-audit.txt` records `static_cutover_audit=clean`;
7. `metadata/cutover-test-groups.txt` contains exactly the five required semantic contract groups listed below;
8. `metadata/cutover-test-source-locations.txt` contains at least one source location for each required group;
9. the source archive, M1l-to-cutover patch, changed-path manifest, changed-source-blob manifest, fixture manifest, configure/build logs, and toolchain/submodule logs exist;
10. record recursive package hash/state for immutable postflight comparison.

A preflight failure is not a product regression and does not authorize a rebuild.

## 4. Independent test discovery

Only after preflight, discover the actual GoogleTest inventory from the packaged executables. Do not use a predeclared producer or total-test count as acceptance authority.

Record for every executable:

- executable SHA-256;
- exact `--gtest_list_tests` output;
- discovered test count;
- selected test names for each gate below.

A zero-selected filter is an orchestration failure, never a semantic pass.

The required M1 cutover groups are:

```text
SurfaceCellAuthorityKernel
SurfaceCellAuthorityContractCutover
SurfaceCellIsolationSeamCertificateAuthority
SurfaceCellTypedTransportAuthority
SurfaceCellSourceSupportAndChartAuthority
```

Use the independently discovered exact names rather than assuming a fixed count.

## 5. Focused M1 cutover gates

Run every discovered test belonging to each required cutover group by exact name before aggregate execution. Each must pass independently.

Required semantic intent:

### `SurfaceCellAuthorityKernel`

- checked lower/upper valid construction boundaries;
- negative and extent rejection with typed errors;
- compile-time ID-domain separation represented by the compiled test contract;
- canonical source-edge/source-face topology-key behavior and degeneracy rejection.

### `SurfaceCellAuthorityContractCutover`

- one complete typed face-to-topology-region product;
- cell/edge/periodic/bounded-disk consumers reference the published region without conflicting component/sheet mirrors;
- source-face row permutation preserves semantic region/certificate identity;
- missing/unassigned authority fails before publication.

### `SurfaceCellIsolationSeamCertificateAuthority`

- valid reciprocal multi-sheet certificate materializes;
- wrong owner/transition/face/sheet, duplicate key, and nonreciprocal transport fail in the intended typed categories;
- exact-once certificate consumption remains observable.

### `SurfaceCellTypedTransportAuthority`

- segment, hard-rail, source-boundary, and periodic routes preserve typed step variants;
- reversal/inversion preserves canonical route identity;
- swapped topology/transition and invented boundary-transition inputs reject;
- unsupported nonzero Z4 remains truthfully unsupported unless the existing production algorithm already supported it.

### `SurfaceCellSourceSupportAndChartAuthority`

- vertex/edge/face-interior support remain distinct typed variants;
- close sheets and separate orientation charts remain distinct;
- source-row permutation preserves semantic identity;
- ambiguous/malformed support fails typed.

Do not reinterpret representation-only differences as semantic failures when the asserted product invariant is preserved.

## 6. Entering semantic-preservation gates

After the new focused groups pass, execute the adapted entering authority/contract coverage and record exact discovered names/counts rather than importing historical totals.

At minimum include:

- all surviving M1a–M1l semantic authority groups;
- M1d route counterexamples;
- M1c transition counterexamples;
- T1 independent oracle/package foundation tests;
- source-authoritative validation executable;
- completion executable coverage required by the M1 contracts;
- compiled API coverage;
- the required-green producer set, excluding only tests explicitly classified as historical/deferred red or characterization-only by the retained project records.

Compare failures against the accepted M1l semantics, not against raw field layout, numeric ID values, source row numbering, structural hashes, or intermediate counts.

## 7. Direct product oracle gates

Run these direct `SurfaceCells` production fixtures using the packaged independent product oracle and the same direct/no-fallback semantics used by entering accepted authority:

```text
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Plane
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/MultiFaceSeam
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/CloseSheets
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder
```

Required classification:

- source attachment must remain correct;
- topology-region/sheet/chart separation must remain correct;
- transport/certificate ownership and exact-once consumption must remain correct;
- direct disposition and no-fallback behavior must remain truthful;
- determinism must remain intact.

A changed raw numbering, row order, diagnostic digest, or intermediate count is not by itself a regression.

## 8. Historical/deferred red classification

Execute and report the known historical/deferred red cases rather than hiding or excluding them from evidence:

```text
SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets
SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize
SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected
SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner
SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected
SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected
SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority
SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary
```

For each, classify current behavior as one of:

- unchanged historical product limitation;
- intentional representation change with preserved semantics;
- earlier truthful typed rejection required by the new contract;
- genuine product progress;
- required-invariant regression;
- unexplained semantic drift.

Do not force the pre-cutover result if the new source model correctly rejects a previously reconstructible but invalid state.

## 9. Strict-validator characterization

The accepted M1l record identifies the sub-millisecond strict-validator ratio gate as nondeterministic. Characterize it in fresh processes without threshold/retry workarounds.

Record individual samples, denominator/numerator timing, pass/fail distribution, and whether any observed change is plausibly attributable to the authority cutover. Do not use this microbenchmark alone to reject M1 when correctness is otherwise preserved unless a stable reproducible regression is established.

## 10. Bounded Bunny/Vase characterization

Run bounded representative characterization using the packaged fixtures and existing direct-product test configuration:

- BunnyRandom: capture disposition, terminal stage/reason, trace/arrangement/completion counts, elapsed time, peak RSS, and deterministic semantic hashes available from the packaged diagnostics;
- Vase: retain the existing bounded safety timeout policy and record whether it terminates, times out safely, or changes failure class.

These are characterization/product-progress evidence. M1 acceptance does not require G6 success, but any new required-invariant regression or unexplained semantic drift blocks acceptance.

## 11. Static source audit from the packaged source

Without rebuilding, extract the packaged source archive into a separate analysis directory and independently repeat the source-only cutover audit over the packaged source.

Require zero production/test-scope references to:

```text
LegacyAuthorityAdapters
to_legacy_index
legacy_phase_front_
transitionSourceEdge
transitionSourceEdges
transitionSourceTopology
sourceRouteEdges
sourceRouteTopology
sourceTopologyRegionByFace
struct SourceChartId
struct SurfaceCellSourceChart
NegativeLegacyValue
OutOfRangeLegacyValue
legacyValue
```

Also inspect the affected authority structs for a typed ID/value stored beside a numeric mirror of the same semantic fact. A remaining duplicate semantic authority is an M1 failure, not follow-up work.

The activated audit must also fail on any reviewed R-A closure defect:

- any materializer equivalence, representative, ownership, or quotient decision reads `SurfacePoint::component` or `SurfacePoint::sheet`;
- any patch/completion/assembly/lineage/verifier identity, equality, hash, order, or lookup key reads raw provenance component/sheet;
- an occurrence lacks required typed topology-region, isolation-sheet, chart, or support authority after construction;
- a fallback canonical/stitch/ownership identity can be built from raw component/sheet mirrors.
- an exact boundary identity is accepted without separate complete typed topology-region/isolation-sheet/chart/support lineage and consistency validation;
- an existing exact stitch key merges a candidate without validating its typed-authority compatibility against the stored candidate;
- collision publication retains a pre-intersection semantic identity beside the final intersected typed certificate;
- a standalone completion or SurfaceCells optimizer/verifier path publishes, succeeds, or validates without complete typed authority;
- the generic validator reads raw projection component/sheet on a SurfaceCells path;
- component aggregation derives typed sheet extent/offset or any typed owner from raw diagnostic/projection labels, silently loses authority during remap, or publishes without complete post-remap lineage validation;
- component aggregation validates region/sheet/chart IDs against bounds synthesized from those IDs, derives offsets from unvalidated maxima, or omits independent owner/domain checks;
- a raw-label tamper contract mutates only after the consumer or compares typed fields that the mutation never touched;
- the audit omits affected declarations, headers, public modes, completion/assembly branches, top-level component aggregation, exact-key collision compatibility, or end-to-end multi-component contracts.

Derived integers are allowed only in one-way diagnostics/export after typed validation and must never be read back by production logic.

## 12. Immutable postflight

After all runtime execution:

1. recompute every packaged checksum and require the same complete result as preflight;
2. recompute the manifest digest and require the newly activated recorded value;
3. verify no package file was added, removed, rewritten, chmod-repaired, or symlinked;
4. verify executable hashes equal preflight values;
5. preserve raw discovery, focused, aggregate, product-oracle, characterization, resource, source-audit, and postflight logs as immutable evidence.

## 13. Acceptance decision

M1 is accepted only when all of the following hold:

- immutable preflight and postflight close exactly;
- all five new semantic cutover groups pass completely;
- all entering required-green semantic authority, validation, T1, and compiled-API gates pass;
- Plane, MultiFaceSeam, CloseSheets, and Cylinder have no required-invariant regression under the independent product oracle;
- every historical/deferred red case is executed and classified, with no unclassified regression;
- no source attachment, topology-region/sheet/chart distinction, transport composition, certificate ownership/exact-once consumption, determinism, direct disposition, or no-fallback invariant regresses;
- independent packaged-source audit finds no displaced representation or duplicate semantic authority;
- the complete R-A gate is clean, including REV-14 through REV-16, with positive, missing-authority, distinct-sheet, exact-only, post-intersection exact-key-collision, independent remap-domain, alternate-validator-path, pre-consumer raw-tamper, and end-to-end multi-component contracts;
- the verified package rules are repeated by clean source provenance and exact preflight/postflight checksum verification;
- all strict preservation fixtures reach certified/D0-equivalent behavior; no D1-D3 output closes a strict gate;
- Bunny/Vase and strict-validator results are truthfully characterized;
- no package mutation or rebuild occurred.

If accepted, close **M1 single-authority cutover** in `TODO.md` and `CHANGELOG.md`, retain the new immutable Test + Benchmark report, and return the primary queue directly to **G4 topology-distinct completion and singularities**. Do not open another M1 letter slice.

If rejected, produce one bounded Code + Build plan addressing only proven semantic/source-authority defects. Do not restore a deleted adapter/raw mirror merely to reproduce old representation.

## 14. Required end-of-turn records

The Test + Benchmark turn must produce:

- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Report.md` with exact run/job/artifact/log identities and discovered counts;
- an updated `TODO.md`, `CHANGELOG.md`, regression tracker when a stable regression event actually exists, and live handoff;
- exactly one authoritative next Code + Build plan. On acceptance that plan must target the highest-prerequisite active **G4** blocker supported by the runtime evidence;
- repository-side stale per-turn cleanup under `CLEAN_UP_POLICY.md` and workflow/trigger/payload cleanup under `GitHub_Workflow_Policy.md`;
- a final summarized PR #8 conversation comment as the last repository write.

PR #8 remains open, draft, and unmerged throughout this validation turn.
