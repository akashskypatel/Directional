# R-A Closure Inventory through R-A-REV-24

Command: `python3 .agents/Directional/R_A_Closure_Inventory.py --root .`

Scope: source-only Code + Build audit. No generated Directional binary, test, benchmark, discovery, `ctest`, CLI, fuzzer, or custom input is executed.

## Checked affected paths

- `include/directional/diagnostics/RemeshDiagnostics.h` — present
- `include/directional/pipeline/RemeshPipeline.h` — present
- `include/directional/geometry/PureQuadCompletion.h` — present
- `include/directional/geometry/SourceChartTransitions.h` — present
- `include/directional/geometry/SourceTopologyRegions.h` — present
- `include/directional/geometry/SurfaceMeshOptimizer.h` — present
- `include/directional/validation/SourceAuthoritativeMeshValidator.h` — present
- `src/geometry/PureQuadCompletion.cpp` — present
- `src/geometry/SurfaceArrangement.cpp` — present
- `src/geometry/SurfaceCellTracing.cpp` — present
- `src/geometry/SurfaceMeshOptimizer.cpp` — present
- `src/geometry/SurfaceOptimizationRailConstraints.cpp` — present
- `src/pipeline/RemeshPipeline.cpp` — present
- `src/validation/SourceAuthoritativeMeshValidator.cpp` — present
- `tests/PureQuadCompletionPhase18Tests.cpp` — present
- `tests/SurfaceCellsPhase10Tests.cpp` — present
- `tests/SurfaceMeshOptimizerPhase19Tests.cpp` — present
- `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` — present
- `.github/workflows/agent-compile-reusable.yml` — present

## REV-01 through REV-24 probes

### R-A-REV-01

**materializer owns typed isolation-sheet state** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `authority::IsolationSheetId isolationSheet;`
- Expectation: `present`
- Match count: **1**
- Classification: OccurrenceData carries typed sheet authority instead of reading SurfacePoint::sheet as authority.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:2253` — `authority::IsolationSheetId isolationSheet;`

**materializer raw projection is not read for sheet/component decisions** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `occurrence\.point\.(?:component|sheet)|representativeOccurrence\.point\.(?:component|sheet)`
- Expectation: `absent`
- Match count: **0**
- Classification: The quotient/materializer semantic path must consume typed region/sheet/chart/support authority.

### R-A-REV-02

**completion stitch key has no raw provenance component/sheet encoding** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`
- Pattern: `(?:stitchIdentity|canonical|identity).*provenance\.(?:component|sheet)|provenance\.(?:component|sheet).*(?:stitchIdentity|canonical|identity)`
- Expectation: `absent`
- Match count: **0**
- Classification: Raw SurfacePoint labels may not enter semantic stitch/ownership identity.

### R-A-REV-03

**typed stitch resolver rejects stale cached identity** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`
- Pattern: `lineage\.stitchIdentity != typed`
- Expectation: `present`
- Match count: **2**
- Classification: A prebuilt compatibility identity cannot bypass typed fail-closed derivation.
- Matches:
  - `src/geometry/PureQuadCompletion.cpp:1024` — `lineage.stitchIdentity != typedIdentity) ||`
  - `src/geometry/PureQuadCompletion.cpp:2022` — `if (lineage.stitchIdentity.valid() && lineage.stitchIdentity != typed) {`

**missing typed stitch authority is an explicit failure** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`, `tests/PureQuadCompletionPhase18Tests.cpp`
- Pattern: `MissingTypedStitchIdentity`
- Expectation: `present`
- Match count: **6**
- Classification: Exact geometry identity alone is insufficient for stitch publication.
- Matches:
  - `src/geometry/PureQuadCompletion.cpp:1014` — `failure = "MissingTypedStitchIdentity";`
  - `src/geometry/PureQuadCompletion.cpp:2578` — `result.failure = "MissingTypedStitchIdentity";`
  - `src/geometry/PureQuadCompletion.cpp:2878` — `result.failure = "MissingTypedStitchIdentity";`
  - `tests/PureQuadCompletionPhase18Tests.cpp:1770` — `EXPECT_EQ("MissingTypedStitchIdentity", assembly.failure);`
  - `tests/PureQuadCompletionPhase18Tests.cpp:2261` — `MissingTypedStitchIdentityFailsClosedForGeneratedInterior) {`
  - `tests/PureQuadCompletionPhase18Tests.cpp:2274` — `EXPECT_EQ("MissingTypedStitchIdentity", assembly.failure);`

### R-A-REV-04

**validator does not read raw SurfacePoint component/sheet** — PASS

- Checked paths: `src/validation/SourceAuthoritativeMeshValidator.cpp`
- Pattern: `\.(?:component|sheet)\b`
- Expectation: `absent`
- Match count: **0**
- Classification: Source-authoritative validation must use typed source authority, not generic projection labels.

**rail constraints do not read raw SurfacePoint component/sheet** — PASS

- Checked paths: `src/geometry/SurfaceOptimizationRailConstraints.cpp`
- Pattern: `\.(?:component|sheet)\b`
- Expectation: `absent`
- Match count: **0**
- Classification: Rail authority must not be scoped or accepted from generic projection labels.

### R-A-REV-05

**typed-authority contract coverage remains compiled** — PASS

- Checked paths: `tests/PureQuadCompletionPhase18Tests.cpp`, `tests/SurfaceMeshOptimizerPhase19Tests.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `(?:MissingTypedStitchIdentity|MissingSourceAuthority|RawProjection|Stale|Distinct.*Sheet|Wrong.*Authority)`
- Expectation: `present`
- Match count: **18**
- Classification: Retained test sources must contain fail-closed typed-authority and tamper contracts.
- Matches:
  - `tests/PureQuadCompletionPhase18Tests.cpp:1422` — `EXPECT_EQ("MissingSourceAuthority", assembly.failure);`
  - `tests/PureQuadCompletionPhase18Tests.cpp:1674` — `CoincidentPositionsOnDistinctTypedSheetsDoNotMerge) {`
  - `tests/PureQuadCompletionPhase18Tests.cpp:1770` — `EXPECT_EQ("MissingTypedStitchIdentity", assembly.failure);`
  - `tests/PureQuadCompletionPhase18Tests.cpp:1971` — `TEST(PureQuadCompletionPhase18, MissingSourceAuthorityPublishesNothing) {`
  - `tests/PureQuadCompletionPhase18Tests.cpp:1981` — `EXPECT_EQ("MissingSourceAuthority", assembly.failure);`
  - `tests/PureQuadCompletionPhase18Tests.cpp:2190` — `TEST(PureQuadCompletionPhase18, StaleCanonicalAuthorityPublishesNothing) {`
  - `tests/PureQuadCompletionPhase18Tests.cpp:2261` — `MissingTypedStitchIdentityFailsClosedForGeneratedInterior) {`
  - `tests/PureQuadCompletionPhase18Tests.cpp:2274` — `EXPECT_EQ("MissingTypedStitchIdentity", assembly.failure);`
  - `tests/PureQuadCompletionPhase18Tests.cpp:2280` — `RawProjectionTamperDoesNotChangeTypedStitchAssembly) {`
  - `tests/SurfaceMeshOptimizerPhase19Tests.cpp:112` — `TEST(SurfaceMeshOptimizerPhase19, MissingSourceAuthorityFailsClosed) {`
  - `tests/SurfaceMeshOptimizerPhase19Tests.cpp:124` — `MissingSourceAuthority);`
  - `tests/SurfaceMeshOptimizerPhase19Tests.cpp:133` — `MissingSourceAuthority);`
  - `tests/SurfaceMeshOptimizerPhase19Tests.cpp:151` — `MissingSourceAuthority,`
  - `tests/SurfaceCellsPhase10Tests.cpp:4945` — `ProductionAggregationCounterfactualIgnoresPreConsumerRawProjectionTamper) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5278` — `DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5299` — `const auto makeStale = [staleToken](auto &lineage) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5318` — `makeStale(lineage);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5323` — `makeStale(lineage);`

### R-A-REV-06

**compile package manifest excludes and verifies itself** — PASS

- Checked paths: `.github/workflows/agent-compile-reusable.yml`
- Pattern: `find \. -type f ! -name SHA256SUMS.*SHA256SUMS|sha256sum -c SHA256SUMS`
- Expectation: `present`
- Match count: **2**
- Classification: Compile evidence must remain internally self-verifying.
- Matches:
  - `.github/workflows/agent-compile-reusable.yml:227` — `(cd "$OUT" && find . -type f ! -name SHA256SUMS -print0 | sort -z | xargs -0 sha256sum > SHA256SUMS)`
  - `.github/workflows/agent-compile-reusable.yml:228` — `(cd "$OUT" && sha256sum -c SHA256SUMS)`

**compile package records clean source snapshots** — PASS

- Checked paths: `.github/workflows/agent-compile-reusable.yml`
- Pattern: `source-status-(?:preconfigure|before-configure|after-configure|after-build|final)`
- Expectation: `present`
- Match count: **9**
- Classification: Build provenance requires clean source status before/after build/package steps.
- Matches:
  - `.github/workflows/agent-compile-reusable.yml:81` — `git status --porcelain=v1 | tee "$RUNNER_TEMP/source-status-preconfigure.txt"`
  - `.github/workflows/agent-compile-reusable.yml:82` — `test ! -s "$RUNNER_TEMP/source-status-preconfigure.txt"`
  - `.github/workflows/agent-compile-reusable.yml:112` — `git status --porcelain=v1 | tee "$RUNNER_TEMP/source-status-before-configure.txt"`
  - `.github/workflows/agent-compile-reusable.yml:113` — `test ! -s "$RUNNER_TEMP/source-status-before-configure.txt"`
  - `.github/workflows/agent-compile-reusable.yml:132` — `git status --porcelain=v1 | tee "$RUNNER_TEMP/source-status-after-configure.txt"`
  - `.github/workflows/agent-compile-reusable.yml:133` — `test ! -s "$RUNNER_TEMP/source-status-after-configure.txt"`
  - `.github/workflows/agent-compile-reusable.yml:149` — `git status --porcelain=v1 | tee "$RUNNER_TEMP/source-status-after-build.txt"`
  - `.github/workflows/agent-compile-reusable.yml:191` — `git status --porcelain=v1 | tee "$RUNNER_TEMP/source-status-final.txt"`
  - `.github/workflows/agent-compile-reusable.yml:192` — `test ! -s "$RUNNER_TEMP/source-status-final.txt"`

### R-A-REV-07

**assembly validates owner-backed typed certificate** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`
- Pattern: `owner_validated_typed_authority_certificate`
- Expectation: `present`
- Match count: **6**
- Classification: Published/stitch-authoritative vertices require complete owned region/sheet/chart/support authority.
- Matches:
  - `src/geometry/PureQuadCompletion.cpp:1758` — `owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:1823` — `owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:1831` — `return owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:2398` — `const auto certificate = owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:2581` — `const auto typedAuthority = owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:2625` — `owner_validated_typed_authority_certificate(`

### R-A-REV-08

**SurfaceCells optimizer has mandatory source-authority predicate** — PASS

- Checked paths: `src/geometry/SurfaceMeshOptimizer.cpp`
- Pattern: `source_optimization_has_complete_authority`
- Expectation: `present`
- Match count: **9**
- Classification: Strict optimizer/final validator entry points must fail closed without source authority.
- Matches:
  - `src/geometry/SurfaceMeshOptimizer.cpp:130` — `if (!source_optimization_has_complete_authority(constraints) ||`
  - `src/geometry/SurfaceMeshOptimizer.cpp:1456` — `if (!source_optimization_has_complete_authority(constraints)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:1829` — `bool source_optimization_has_complete_authority(`
  - `src/geometry/SurfaceMeshOptimizer.cpp:1879` — `if (!source_optimization_has_complete_authority(constraints)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:2307` — `if (!source_optimization_has_complete_authority(constraints)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:2467` — `if (!source_optimization_has_complete_authority(constraints)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:2498` — `if (!source_optimization_has_complete_authority(constraints)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:2903` — `if (!source_optimization_has_complete_authority(constraints)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:2929` — `if (!source_optimization_has_complete_authority(constraints)) {`

### R-A-REV-09

**component remap domain is typed and owner-derived** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `ComponentTypedAuthorityRemapDomain|make_component_typed_authority_remap_domain`
- Expectation: `present`
- Match count: **6**
- Classification: Multi-component sheet/region/chart/support remapping must derive from typed owner domains.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:8568` — `std::optional<ComponentTypedAuthorityRemapDomain>`
  - `src/pipeline/RemeshPipeline.cpp:8569` — `make_component_typed_authority_remap_domain(`
  - `src/pipeline/RemeshPipeline.cpp:8590` — `ComponentTypedAuthorityRemapDomain domain;`
  - `src/pipeline/RemeshPipeline.cpp:8690` — `? std::optional<ComponentTypedAuthorityRemapDomain>(`
  - `src/pipeline/RemeshPipeline.cpp:8700` — `const ComponentTypedAuthorityRemapDomain &domain) {`
  - `src/pipeline/RemeshPipeline.cpp:10637` — `const auto typedAuthorityDomain = make_component_typed_authority_remap_domain(`

### R-A-REV-10

**bounded legacy audit is superseded by this complete inventory** — PASS

- Checked paths: `.agents/Directional/R_A_Closure_Inventory.py`
- Pattern: `R-A closure inventory through R-A-REV-24`
- Expectation: `present`
- Match count: **2**
- Classification: REV-10's sampled audit is not used as closure evidence; this reproducible inventory replaces it.
- Matches:
  - `.agents/Directional/R_A_Closure_Inventory.py:2` — `"""Reproducible static R-A closure inventory through R-A-REV-24.`
  - `.agents/Directional/R_A_Closure_Inventory.py:94` — `r"R-A closure inventory through R-A-REV-24", "present",`

### R-A-REV-11

**collision certificates are intersected before publication** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`
- Pattern: `intersect_typed_authority_certificate`
- Expectation: `present`
- Match count: **2**
- Classification: Same-key/same-position collision is not sufficient without compatible typed authority.
- Matches:
  - `src/geometry/PureQuadCompletion.cpp:1836` — `intersect_typed_authority_certificates(`
  - `src/geometry/PureQuadCompletion.cpp:2618` — `const auto compatibleAuthority = intersect_typed_authority_certificates(`

### R-A-REV-12

**aggregate remap is checked and final lineage is validated** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `remap_quotient_lineage_authority|validate_aggregate_lineage_authority`
- Expectation: `present`
- Match count: **4**
- Classification: Invalid chart/support/region/sheet remaps must reject before publication.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:10969` — `const auto remap_quotient_lineage_authority =`
  - `src/pipeline/RemeshPipeline.cpp:11105` — `if (!remap_quotient_lineage_authority(lineage)) {`
  - `src/pipeline/RemeshPipeline.cpp:11179` — `if (!remap_quotient_lineage_authority(lineage)) {`
  - `src/pipeline/RemeshPipeline.cpp:11299` — `if (!remap_quotient_lineage_authority(lineage)) {`

### R-A-REV-13

**complete affected surface list is explicitly audited** — PASS

- Checked paths: `.agents/Directional/R_A_Closure_Inventory.py`
- Pattern: `AFFECTED_R_A_PATHS`
- Expectation: `present`
- Match count: **4**
- Classification: Closure evidence names the affected source/test/workflow surfaces instead of sampling a few blocks.
- Matches:
  - `.agents/Directional/R_A_Closure_Inventory.py:107` — `r"AFFECTED_R_A_PATHS", "present",`
  - `.agents/Directional/R_A_Closure_Inventory.py:242` — `AFFECTED_R_A_PATHS: tuple[str, ...] = (`
  - `.agents/Directional/R_A_Closure_Inventory.py:555` — `for path in AFFECTED_R_A_PATHS:`
  - `.agents/Directional/R_A_Closure_Inventory.py:650` — `lines.append(f"- Affected path count: **{len(AFFECTED_R_A_PATHS)}**")`

### R-A-REV-14

**post-intersection canonical authority identity is retained** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`
- Pattern: `canonical_typed_authority_identity`
- Expectation: `present`
- Match count: **4**
- Classification: Collision publication derives one canonical authority identity from the final certificate.
- Matches:
  - `src/geometry/PureQuadCompletion.cpp:1861` — `PureQuadStitchIdentity canonical_typed_authority_identity(`
  - `src/geometry/PureQuadCompletion.cpp:2060` — `canonical_typed_authority_identity(resolved, certificate);`
  - `src/geometry/PureQuadCompletion.cpp:2403` — `return canonical_typed_authority_identity(lineage.stitchIdentity,`
  - `src/geometry/PureQuadCompletion.cpp:2720` — `canonical_typed_authority_identity(pending.stitchIdentity,`

### R-A-REV-15

**region/sheet/chart/support remap domain is not self-bounded** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `ComponentTypedAuthorityRemapDomain`
- Expectation: `present`
- Match count: **4**
- Classification: Remap domains are owned by published source topology/chart authority.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:8568` — `std::optional<ComponentTypedAuthorityRemapDomain>`
  - `src/pipeline/RemeshPipeline.cpp:8590` — `ComponentTypedAuthorityRemapDomain domain;`
  - `src/pipeline/RemeshPipeline.cpp:8690` — `? std::optional<ComponentTypedAuthorityRemapDomain>(`
  - `src/pipeline/RemeshPipeline.cpp:8700` — `const ComponentTypedAuthorityRemapDomain &domain) {`

### R-A-REV-16

**counterfactual mutation seam occurs before aggregation** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `beforeAggregation`
- Expectation: `present`
- Match count: **5**
- Classification: Raw/tamper counterfactuals must reach the real aggregate consumer before publication.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:9988` — `*beforeAggregation,`
  - `src/pipeline/RemeshPipeline.cpp:10235` — `if (beforeAggregation != nullptr) {`
  - `src/pipeline/RemeshPipeline.cpp:10237` — `(*beforeAggregation)(index, runs[index].result);`
  - `src/pipeline/RemeshPipeline.cpp:11686` — `const ComponentAggregationInputMutator &beforeAggregation) {`
  - `src/pipeline/RemeshPipeline.cpp:11688` — `vertices, faces, authoritativeCrossField, options, &beforeAggregation,`

### R-A-REV-17

**certificate claims are checked against source ownership** — PASS

- Checked paths: `src/geometry/PureQuadCompletion.cpp`
- Pattern: `owner_validated_typed_authority_certificate`
- Expectation: `present`
- Match count: **6**
- Classification: Collision certificates must be owned by exact source topology/chart/support authority.
- Matches:
  - `src/geometry/PureQuadCompletion.cpp:1758` — `owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:1823` — `owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:1831` — `return owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:2398` — `const auto certificate = owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:2581` — `const auto typedAuthority = owner_validated_typed_authority_certificate(`
  - `src/geometry/PureQuadCompletion.cpp:2625` — `owner_validated_typed_authority_certificate(`

### R-A-REV-18

**one global aggregate source owner is constructed** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `globalSourceAuthority`
- Expectation: `present`
- Match count: **5**
- Classification: Disconnected aggregation must publish lineage through one checked global SourceTopologyRegions owner.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:11470` — `const auto globalSourceAuthority = geometry::SourceTopologyRegions::make(`
  - `src/pipeline/RemeshPipeline.cpp:11473` — `if (!globalSourceAuthority.has_value() ||`
  - `src/pipeline/RemeshPipeline.cpp:11474` — `!globalSourceAuthority->matches_source_faces(`
  - `src/pipeline/RemeshPipeline.cpp:11491` — `staged, faces, globalSourceAuthority.value(),`
  - `src/pipeline/RemeshPipeline.cpp:11498` — `globalSourceAuthority.value();`

**post-remap derived identity caches are rebuilt** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `rebuild_aggregate_output_identity_caches`
- Expectation: `present`
- Match count: **2**
- Classification: Stitch/authoritative identities and face cycles must be regenerated after global remap.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:9826` — `bool rebuild_aggregate_output_identity_caches(`
  - `src/pipeline/RemeshPipeline.cpp:11490` — `if (!rebuild_aggregate_output_identity_caches(`

### R-A-REV-19

**aggregate publication is staged transactionally** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `RemeshResult staged = merged;`
- Expectation: `present`
- Match count: **1**
- Classification: Semantic context remains uncommitted until all remaps and final validation succeed.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:10330` — `RemeshResult staged = merged;`

**actual final merged mesh reaches source-authoritative validator** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `validate_source_authoritative_surface_mesh`
- Expectation: `present`
- Match count: **1**
- Classification: Cached component reports cannot substitute for the post-merge oracle.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:11528` — `validation::validate_source_authoritative_surface_mesh(`

### R-A-REV-20

**removed raw/legacy SurfaceCells compatibility paths stay absent** — PASS

- Checked paths: `include/directional/geometry/SurfaceMeshOptimizer.h`, `src/geometry/SurfaceMeshOptimizer.cpp`, `src/geometry/SurfaceOptimizationRailConstraints.cpp`, `src/validation/SourceAuthoritativeMeshValidator.cpp`, `src/pipeline/RemeshPipeline.cpp`
- Pattern: `sourcePositions|constraints\.sourceComponent|featureIntervals|legacyIndex|standaloneFixture`
- Expectation: `absent`
- Match count: **0**
- Classification: Named raw optimizer/verifier and legacy point-cloud/feature-interval/standalone compatibility authority must remain removed.

### R-A-REV-21

**exact source-row topology binding is used** — PASS

- Checked paths: `include/directional/geometry/SourceTopologyRegions.h`, `src/geometry/PureQuadCompletion.cpp`, `src/geometry/SurfaceMeshOptimizer.cpp`, `src/validation/SourceAuthoritativeMeshValidator.cpp`, `src/pipeline/RemeshPipeline.cpp`
- Pattern: `matches_source_faces`
- Expectation: `present`
- Match count: **13**
- Classification: Same face count is not source ownership; paired geometry and authority must match exact row topology.
- Matches:
  - `include/directional/geometry/SourceTopologyRegions.h:151` — `[[nodiscard]] bool matches_source_faces(`
  - `src/geometry/PureQuadCompletion.cpp:1764` — `!sourceAuthority.matches_source_faces(sourceFaces) ||`
  - `src/geometry/PureQuadCompletion.cpp:2422` — `!sourceAuthority->matches_source_faces(*sourceFaces)) {`
  - `src/geometry/SurfaceMeshOptimizer.cpp:668` — `!constraints.sourceAuthority->matches_source_faces(`
  - `src/geometry/SurfaceMeshOptimizer.cpp:699` — `constraints.sourceAuthority->matches_source_faces(`
  - `src/geometry/SurfaceMeshOptimizer.cpp:1835` — `!constraints.sourceAuthority->matches_source_faces(`
  - `src/validation/SourceAuthoritativeMeshValidator.cpp:1031` — `!options.sourceAuthority->matches_source_faces(`
  - `src/validation/SourceAuthoritativeMeshValidator.cpp:1196` — `options.sourceAuthority->matches_source_faces(`
  - `src/validation/SourceAuthoritativeMeshValidator.cpp:1210` — `!options.sourceAuthority->matches_source_faces(`
  - `src/pipeline/RemeshPipeline.cpp:4428` — `sourceAuthority->matches_source_faces(sourceFaces)) {`
  - `src/pipeline/RemeshPipeline.cpp:8579` — `!sourceAuthority.matches_source_faces(`
  - `src/pipeline/RemeshPipeline.cpp:10060` — `!run.result.surfaceCellContext.sourceTopologyRegions->matches_source_faces(`
  - `src/pipeline/RemeshPipeline.cpp:11474` — `!globalSourceAuthority->matches_source_faces(`

**authority-only row permutation negative exists** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `AuthorityOnlyFaceRowPermutationRejectsExactTopologyBinding`
- Expectation: `present`
- Match count: **1**
- Classification: The mismatched-pair counterexample must retain old authority while permuting only the source matrix.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5937` — `AuthorityOnlyFaceRowPermutationRejectsExactTopologyBinding) {`

**consistent matrix-plus-authority permutation positive exists** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `ConsistentlyPermutedSourceMatrixAndAuthorityPreserveSemanticTopology`
- Expectation: `present`
- Match count: **1**
- Classification: A row permutation remains valid when source geometry and rebuilt authority are paired consistently.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5961` — `ConsistentlyPermutedSourceMatrixAndAuthorityPreserveSemanticTopology) {`

### R-A-REV-22

**final aggregate carries independent strict validator authority** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `ComponentFinalValidationAuthority|globalValidationBoundaryLoops|globalValidationFeatureRails|globalValidationVertexCharts|globalValidationOutputQuadSourceFaces|globalValidationHardFeatureEdges`
- Expectation: `present`
- Match count: **25**
- Classification: Boundary, feature, chart, output-face, hard-edge, and provenance authority must survive global remap into the final oracle.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:10038` — `struct ComponentFinalValidationAuthority {`
  - `src/pipeline/RemeshPipeline.cpp:10052` — `ComponentFinalValidationAuthority finalValidationAuthority;`
  - `src/pipeline/RemeshPipeline.cpp:10116` — `ComponentFinalValidationAuthority &authority =`
  - `src/pipeline/RemeshPipeline.cpp:10409` — `std::vector<std::vector<int>> globalValidationBoundaryLoops;`
  - `src/pipeline/RemeshPipeline.cpp:10410` — `std::vector<std::vector<int>> globalValidationFeatureRails;`
  - `src/pipeline/RemeshPipeline.cpp:10412` — `globalValidationVertexCharts;`
  - `src/pipeline/RemeshPipeline.cpp:10413` — `std::vector<int> globalValidationOutputQuadSourceFaces;`
  - `src/pipeline/RemeshPipeline.cpp:10414` — `std::set<std::uint64_t> globalValidationHardFeatureEdges;`
  - `src/pipeline/RemeshPipeline.cpp:10646` — `const ComponentFinalValidationAuthority &componentValidationAuthority =`
  - `src/pipeline/RemeshPipeline.cpp:10839` — `globalValidationBoundaryLoops.push_back(std::move(globalLoop));`
  - `src/pipeline/RemeshPipeline.cpp:10853` — `globalValidationFeatureRails.push_back(std::move(globalRail));`
  - `src/pipeline/RemeshPipeline.cpp:10869` — `globalValidationOutputQuadSourceFaces.push_back(-1);`
  - `src/pipeline/RemeshPipeline.cpp:10877` — `globalValidationOutputQuadSourceFaces.push_back(`
  - `src/pipeline/RemeshPipeline.cpp:10892` — `globalValidationHardFeatureEdges.insert(surface_cell_source_edge_key(`
  - `src/pipeline/RemeshPipeline.cpp:11118` — `globalValidationVertexCharts.size() !=`
  - `src/pipeline/RemeshPipeline.cpp:11123` — `globalValidationVertexCharts.insert(`
  - `src/pipeline/RemeshPipeline.cpp:11124` — `globalValidationVertexCharts.end(),`
  - `src/pipeline/RemeshPipeline.cpp:11481` — `if (globalValidationVertexCharts.size() !=`
  - `src/pipeline/RemeshPipeline.cpp:11483` — `globalValidationOutputQuadSourceFaces.size() !=`
  - `src/pipeline/RemeshPipeline.cpp:11492` — `&globalValidationHardFeatureEdges)) {`
  - `src/pipeline/RemeshPipeline.cpp:11507` — `&globalValidationVertexCharts;`
  - `src/pipeline/RemeshPipeline.cpp:11509` — `&globalValidationOutputQuadSourceFaces;`
  - `src/pipeline/RemeshPipeline.cpp:11511` — `globalValidationHardFeatureEdges;`
  - `src/pipeline/RemeshPipeline.cpp:11515` — `globalValidationBoundaryLoops;`
  - `src/pipeline/RemeshPipeline.cpp:11517` — `globalValidationFeatureRails;`

**final aggregate enables strict boundary/feature/local-sheet gates** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `finalAuthorityOptions\.requireBoundaryAuthority = true;|finalAuthorityOptions\.requireFeatureRailAuthority = true;|finalAuthorityOptions\.requireLocalSheetCompatibility = true;`
- Expectation: `present`
- Match count: **3**
- Classification: The final oracle cannot weaken component strict gates to make aggregate output pass.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:11520` — `finalAuthorityOptions.requireBoundaryAuthority = true;`
  - `src/pipeline/RemeshPipeline.cpp:11521` — `finalAuthorityOptions.requireFeatureRailAuthority = true;`
  - `src/pipeline/RemeshPipeline.cpp:11522` — `finalAuthorityOptions.requireLocalSheetCompatibility = true;`

**component authority tamper contracts name the aggregation seam** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `ComponentBoundaryRailTamperRejectsAtAggregationSeam|ComponentFeatureRailTamperRejectsAtAggregationSeam`
- Expectation: `present`
- Match count: **2**
- Classification: Component capture-versus-mutation tests prove the pre-oracle seam guard and do not claim final-oracle coverage.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5362` — `ComponentBoundaryRailTamperRejectsAtAggregationSeam) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5406` — `ComponentFeatureRailTamperRejectsAtAggregationSeam) {`

**final oracle boundary and feature authority negatives exist** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority|FinalMergedOracleRejectsMissingRemappedFeatureAuthority`
- Expectation: `present`
- Match count: **2**
- Classification: Post-remap counterfactuals must pass component seam checks and make the final oracle reject missing boundary/feature authority with zero publication.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5451` — `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5502` — `FinalMergedOracleRejectsMissingRemappedFeatureAuthority) {`

**final oracle boundary content mismatch negative exists** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent`
- Expectation: `present`
- Match count: **1**
- Classification: Present remapped boundary authority must be content-checked and reject with ChangedBoundaryLoop rather than only proving the absence guard.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5553` — `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent) {`

**final oracle feature content mismatch negative exists** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`
- Expectation: `present`
- Match count: **1**
- Classification: Present remapped feature authority with preserved cardinality must reject when a rail is absent from the merged output.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5633` — `FinalMergedOracleRejectsChangedRemappedFeatureRailContent) {`

**feature-bearing final oracle positive is non-vacuous** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority|expectedFeatureRailCount > 0U`
- Expectation: `present`
- Match count: **3**
- Classification: Positive aggregate coverage must observe a non-empty feature-rail authority set before accepting it.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5526` — `validationOptions.expectedFeatureRailCount > 0U &&`
  - `tests/SurfaceCellsPhase10Tests.cpp:5703` — `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5727` — `validationOptions.expectedFeatureRailCount > 0U &&`

**final oracle full issue list is retained in diagnostics** — PASS

- Checked paths: `include/directional/diagnostics/RemeshDiagnostics.h`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `surfaceCellFinalSourceAuthorityValidationIssues`
- Expectation: `present`
- Match count: **5**
- Classification: Content-mismatch negatives must prove the actual final-oracle issue list rather than relying only on preferred-code selection.
- Matches:
  - `include/directional/diagnostics/RemeshDiagnostics.h:251` — `std::vector<std::string> surfaceCellFinalSourceAuthorityValidationIssues;`
  - `src/pipeline/RemeshPipeline.cpp:11533` — `merged.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues.clear();`
  - `src/pipeline/RemeshPipeline.cpp:11536` — `merged.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues`
  - `tests/SurfaceCellsPhase10Tests.cpp:5617` — `rejected.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues;`
  - `tests/SurfaceCellsPhase10Tests.cpp:5687` — `rejected.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues;`

**aggregate validation flags are sourced from final oracle observables** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `finalAuthorityValidation\.(?:strictValidationUsed|provenanceValidationUsed|boundaryAuthorityUsed|featureRailAuthorityUsed)`
- Expectation: `present`
- Match count: **4**
- Classification: Published strict/provenance/boundary/feature usage flags must be oracle evidence, not constants.
- Matches:
  - `src/pipeline/RemeshPipeline.cpp:11629` — `finalAuthorityValidation.strictValidationUsed;`
  - `src/pipeline/RemeshPipeline.cpp:11631` — `finalAuthorityValidation.provenanceValidationUsed;`
  - `src/pipeline/RemeshPipeline.cpp:11637` — `finalAuthorityValidation.boundaryAuthorityUsed;`
  - `src/pipeline/RemeshPipeline.cpp:11639` — `finalAuthorityValidation.featureRailAuthorityUsed;`

**aggregate validation flags are not hardcoded true** — PASS

- Checked paths: `src/pipeline/RemeshPipeline.cpp`
- Pattern: `aggregateValidationResult\.(?:strictValidationUsed|provenanceValidationUsed|authoritativeFeatureRailsUsed)\s*=\s*true`
- Expectation: `absent`
- Match count: **0**
- Classification: A hardcoded publication flag is a tautology and cannot establish validator execution.

**option-echo usage EXPECT_TRUE assertions are absent** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `EXPECT_TRUE\((?:finalValidation\.strictValidationUsed|finalValidation\.authoritativeFeatureRailsUsed|oracle\.strictValidationUsed|oracle\.featureRailAuthorityUsed)\)`
- Expectation: `absent`
- Match count: **0**
- Classification: Usage-option echoes are not semantic evidence; tests retain published-vs-oracle equality and input-derived gate observations instead.

**final oracle outcome is published independently of component reports** — PASS

- Checked paths: `include/directional/pipeline/RemeshPipeline.h`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `hasFinalSourceAuthorityValidationResult|componentValidationReportsComplete|FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`
- Expectation: `present`
- Match count: **14**
- Classification: Consumers must distinguish final oracle success from missing component-level aggregate reports.
- Matches:
  - `include/directional/pipeline/RemeshPipeline.h:510` — `bool hasFinalSourceAuthorityValidationResult = false;`
  - `include/directional/pipeline/RemeshPipeline.h:511` — `bool componentValidationReportsComplete = false;`
  - `src/pipeline/RemeshPipeline.cpp:11571` — `staged.surfaceCellContext.hasFinalSourceAuthorityValidationResult = true;`
  - `src/pipeline/RemeshPipeline.cpp:11572` — `staged.surfaceCellContext.componentValidationReportsComplete =`
  - `tests/SurfaceCellsPhase10Tests.cpp:5221` — `result.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5222` — `EXPECT_TRUE(result.surfaceCellContext.componentValidationReportsComplete);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5498` — `rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5549` — `rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5629` — `rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5699` — `rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5741` — `ASSERT_TRUE(result.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5757` — `FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing) {`
  - `tests/SurfaceCellsPhase10Tests.cpp:5793` — `EXPECT_FALSE(result.surfaceCellContext.componentValidationReportsComplete);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5795` — `result.surfaceCellContext.hasFinalSourceAuthorityValidationResult);`

**valid boundary-bearing aggregate asserts strict final oracle evidence** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `finalSourceAuthorityValidationResult|authoritativeBoundaryUsed|authoritativeFeatureRailsUsed|orderedBoundaryCyclesPassed|sourceAuthoritativeValidationUsed`
- Expectation: `present`
- Match count: **13**
- Classification: Positive coverage must prove the strict final merged-product validator actually ran and published its typed result.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5089` — `EXPECT_EQ(baselineValidation.sourceAuthoritativeValidationUsed,`
  - `tests/SurfaceCellsPhase10Tests.cpp:5090` — `tamperedValidation.sourceAuthoritativeValidationUsed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5225` — `result.surfaceCellContext.finalSourceAuthorityValidationResult;`
  - `tests/SurfaceCellsPhase10Tests.cpp:5232` — `finalValidation.sourceAuthoritativeValidationUsed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5234` — `finalValidation.authoritativeBoundaryUsed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5236` — `finalValidation.authoritativeFeatureRailsUsed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5237` — `EXPECT_TRUE(finalValidation.sourceAuthoritativeValidationUsed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5238` — `EXPECT_TRUE(finalValidation.authoritativeBoundaryUsed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5240` — `EXPECT_TRUE(finalValidation.orderedBoundaryCyclesPassed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5743` — `result.surfaceCellContext.finalSourceAuthorityValidationResult;`
  - `tests/SurfaceCellsPhase10Tests.cpp:5748` — `EXPECT_TRUE(oracle.orderedBoundaryCyclesPassed);`
  - `tests/SurfaceCellsPhase10Tests.cpp:5797` — `result.surfaceCellContext.finalSourceAuthorityValidationResult;`
  - `tests/SurfaceCellsPhase10Tests.cpp:5802` — `EXPECT_TRUE(oracle.orderedBoundaryCyclesPassed);`

### R-A-REV-23

**pipeline stitch-kind assignment is structurally absent** — PASS

- Checked paths: `src/pipeline`
- Pattern: `stitchIdentity\s*(?:\.|->)\s*kind|(?:\w+::)*PureQuadStitchIdentityKind`
- Expectation: `absent`
- Match count: **0**
- Classification: A structural whole-statement matcher rejects wrapped, fully-qualified, alias-based, and stale-copy stitch-kind writes across every pipeline translation unit.

**pipeline stitch-kind classifier self-test is wired** — PASS

- Checked paths: `.agents/Directional/R_A_Closure_Inventory.py`
- Pattern: `self_test_pipeline_stitch_kind_classifier`
- Expectation: `present`
- Match count: **3**
- Classification: The audit proves its own coverage against the four independently reviewed evasion forms.
- Matches:
  - `.agents/Directional/R_A_Closure_Inventory.py:221` — `r"self_test_pipeline_stitch_kind_classifier", "present",`
  - `.agents/Directional/R_A_Closure_Inventory.py:512` — `def self_test_pipeline_stitch_kind_classifier() -> tuple[list[str], list[str]]:`
  - `.agents/Directional/R_A_Closure_Inventory.py:632` — `self_test_pipeline_stitch_kind_classifier()`

**completion-owned canonical stitch constructor is used** — PASS

- Checked paths: `include/directional/geometry/PureQuadCompletion.h`, `src/geometry/PureQuadCompletion.cpp`, `src/pipeline/RemeshPipeline.cpp`
- Pattern: `canonical_lineage_stitch_identity`
- Expectation: `present`
- Match count: **3**
- Classification: Post-remap stitch kind/schema is derived from authoritative patch structure by the completion owner.
- Matches:
  - `include/directional/geometry/PureQuadCompletion.h:563` — `PureQuadStitchIdentity canonical_lineage_stitch_identity(`
  - `src/geometry/PureQuadCompletion.cpp:1969` — `PureQuadStitchIdentity canonical_lineage_stitch_identity(`
  - `src/pipeline/RemeshPipeline.cpp:9862` — `geometry::pure_quad_detail::canonical_lineage_stitch_identity(`

**stale-kind and post-publication re-stitch contracts exist** — PASS

- Checked paths: `tests/SurfaceCellsPhase10Tests.cpp`
- Pattern: `GeneratedPatchInterior|stitch_pure_quad_patches|stitchIdentity\.kind`
- Expectation: `present`
- Match count: **6**
- Classification: Generated interior lineages must remain canonical/resolvable after stale cache tamper and publication.
- Matches:
  - `tests/SurfaceCellsPhase10Tests.cpp:5262` — `lineage.stitchIdentity.kind ==`
  - `tests/SurfaceCellsPhase10Tests.cpp:5263` — `directional::geometry::PureQuadStitchIdentityKind::GeneratedPatchInterior;`
  - `tests/SurfaceCellsPhase10Tests.cpp:5272` — `const auto restitched = directional::geometry::stitch_pure_quad_patches(`
  - `tests/SurfaceCellsPhase10Tests.cpp:5301` — `lineage.stitchIdentity.kind =`
  - `tests/SurfaceCellsPhase10Tests.cpp:5302` — `lineage.stitchIdentity.kind ==`
  - `tests/SurfaceCellsPhase10Tests.cpp:5306` — `GeneratedPatchInterior`

### R-A-REV-24

**direct source-authoritative validator rejects null authority at entry** — PASS

- Checked paths: `src/validation/SourceAuthoritativeMeshValidator.cpp`
- Pattern: `options\.sourceAuthority == nullptr`
- Expectation: `present`
- Match count: **2**
- Classification: Missing typed source authority is invalid independently of optional boundary/feature/local-sheet gates.
- Matches:
  - `src/validation/SourceAuthoritativeMeshValidator.cpp:1029` — `options.sourceAuthority == nullptr || options.vertexProvenance == nullptr ||`
  - `src/validation/SourceAuthoritativeMeshValidator.cpp:1209` — `(options.sourceAuthority == nullptr ||`

**direct null/foreign authority negatives exist** — PASS

- Checked paths: `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp`
- Pattern: `MissingSourceAuthorityRejectsEvenWhenOptionalGatesAreDisabled|SameExtentForeignSourceAuthorityRejectsBeforeOptionalGates`
- Expectation: `present`
- Match count: **2**
- Classification: Direct public validator coverage must prove null and same-extent foreign authority fail closed.
- Matches:
  - `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp:96` — `MissingSourceAuthorityRejectsEvenWhenOptionalGatesAreDisabled) {`
  - `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp:126` — `SameExtentForeignSourceAuthorityRejectsBeforeOptionalGates) {`

## Allowed-leaf classification

### Raw `SurfacePoint::{component,sheet}` projection leaves

- Match count: **22**
- Allowed count: **22**
- Unexpected count: **0**
- ALLOWED `src/pipeline/RemeshPipeline.cpp:1998` — one-way SurfacePoint geometry/export projection write — `point.component = static_cast<int>(`
- ALLOWED `src/pipeline/RemeshPipeline.cpp:2000` — one-way SurfacePoint geometry/export projection write — `point.sheet = static_cast<int>(`
- ALLOWED `src/pipeline/RemeshPipeline.cpp:5180` — one-way SurfacePoint geometry/export projection write — `point.component = static_cast<int>(`
- ALLOWED `src/pipeline/RemeshPipeline.cpp:5182` — one-way SurfacePoint geometry/export projection write — `point.sheet = static_cast<int>(`
- ALLOWED `src/pipeline/RemeshPipeline.cpp:8557` — one-way SurfacePoint geometry/export projection write — `point.component = static_cast<int>(componentIndex);`
- ALLOWED `src/pipeline/RemeshPipeline.cpp:8558` — one-way SurfacePoint geometry/export projection write — `point.sheet = typedGlobalSheet.has_value()`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:237` — one-way SurfacePoint geometry/export projection write — `point.component = 0;`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:238` — one-way SurfacePoint geometry/export projection write — `point.sheet = 0;`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:278` — geometry-only averaging payload propagation; not stitch/owner/validator identity — `component = point.component;`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:279` — geometry-only averaging payload propagation; not stitch/owner/validator identity — `sheet = point.sheet;`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:292` — one-way SurfacePoint geometry/export projection write — `averaged.component = component;`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:293` — one-way SurfacePoint geometry/export projection write — `averaged.sheet = sheet;`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:314` — one-way SurfacePoint geometry/export projection write — `point.component = static_cast<int>(`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:316` — one-way SurfacePoint geometry/export projection write — `point.sheet = static_cast<int>(`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:984` — one-way SurfacePoint geometry/export projection write — `provenance.component = static_cast<int>(`
- ALLOWED `src/geometry/PureQuadCompletion.cpp:986` — one-way SurfacePoint geometry/export projection write — `provenance.sheet = static_cast<int>(`
- ALLOWED `src/geometry/SurfaceMeshOptimizer.cpp:774` — one-way SurfacePoint geometry/export projection write — `projected.component = component;`
- ALLOWED `src/geometry/SurfaceMeshOptimizer.cpp:775` — one-way SurfacePoint geometry/export projection write — `projected.sheet = sheet;`
- ALLOWED `src/geometry/SurfaceMeshOptimizer.cpp:2597` — one-way SurfacePoint geometry/export projection write — `sourcePoint.component = component;`
- ALLOWED `src/geometry/SurfaceMeshOptimizer.cpp:2598` — one-way SurfacePoint geometry/export projection write — `sourcePoint.sheet = sheet;`
- ALLOWED `src/geometry/SurfaceMeshOptimizer.cpp:3053` — one-way SurfacePoint geometry/export projection write — `sourcePoint.component = faceComponent;`
- ALLOWED `src/geometry/SurfaceMeshOptimizer.cpp:3054` — one-way SurfacePoint geometry/export projection write — `sourcePoint.sheet = faceSheet;`

### `complete_for_face_count` leaves

- Match count: **2**
- Allowed count: **2**
- Unexpected count: **0**
- ALLOWED `include/directional/geometry/SourceTopologyRegions.h:139` — SourceTopologyRegions-local structural extent precondition; semantic consumers use matches_source_faces, which immediately performs exact checked row-topology equality — `[[nodiscard]] bool complete_for_face_count(std::size_t faceCount) const noexcept {`
- ALLOWED `include/directional/geometry/SourceTopologyRegions.h:155` — SourceTopologyRegions-local structural extent precondition; semantic consumers use matches_source_faces, which immediately performs exact checked row-topology equality — `!complete_for_face_count(`

### Pipeline `stitchIdentity` assignment leaves

- Match count: **2**
- Allowed count: **2**
- Unexpected count: **0**
- ALLOWED `src/pipeline/RemeshPipeline.cpp:9865` — direct assignment from the completion-owned canonical_lineage_stitch_identity result — `stitchIdentity = stitch;`
- ALLOWED `src/pipeline/RemeshPipeline.cpp:9927` — assignment from a lookup map populated only by the completion-owned canonical stitch result — `stitchIdentity = canonical->second;`

### Pipeline stitch-kind classifier self-test

- Case count: **4**
- Passed count: **4**
- Failed count: **0**
- PASS `fully-qualified-enum`
- PASS `wrapped-enum-assignment`
- PASS `stale-kind-copy`
- PASS `enum-alias`

## Inventory summary

- Probe count: **48**
- Probe match count: **203**
- Affected path count: **19**
- Allowed raw-projection leaves: **22**
- Unexpected raw-projection leaves: **0**
- Allowed face-count leaves: **2**
- Unexpected face-count leaves: **0**
- Allowed pipeline stitchIdentity assignments: **2**
- Unexpected pipeline stitchIdentity assignments: **0**
- Stitch-kind classifier self-test cases: **4**
- Stitch-kind classifier self-test failures: **0**
- Final static inventory: **PASS**

This PASS is a static/compile-contract result only. R-A semantic acceptance requires the separately packaged artifact-only runtime turn on the fresh corrected compile package.
