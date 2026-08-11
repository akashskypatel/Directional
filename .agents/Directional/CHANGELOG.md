# Changelog

All notable completed changes and immutable acceptance checkpoints for the Directional surface-cell implementation are recorded here.

This is a durable historical record, maintained separately from `.agents/Directional/Future_Chat_Session_Handoff.md`. The handoff owns only the current resume state, mandatory next action, live blockers, current immutable authority, and durable operating policy.

The format is inspired by [Keep a Changelog](https://keepachangelog.com/): entries are newest first, completed work is separated from unreleased work, and changes are grouped by purpose rather than by commit dump. This project uses migration milestone identifiers instead of semantic-version releases. Dates are included only when they are directly established by authoritative records.

## Maintenance rules

- Keep entries newest first.
- Record completed, durable changes only; active next-turn instructions remain in the handoff.
- Prefer the categories `Added`, `Changed`, `Fixed`, `Validation`, `Known limitations`, and `Operational notes` as applicable.
- Preserve exact implementation commits, artifact IDs, run/job IDs, hashes, stable regression IDs, and failure classifications when they are part of immutable authority.
- Link to the authoritative report when available instead of duplicating every machine log.
- Do not rewrite or remove historical entries merely to shorten the file. Correct factual errors narrowly and preserve provenance.

## [Unreleased]

No completed changes are currently recorded here. The active M1m Code + Build instructions remain in the handoff.

## [M1l] Phase-Front Cell Topology-Region Consumer — Immutable accepted

### Changed

- Migrated persistent `SurfacePhaseFrontCell::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId` at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.
- Cell/edge topology-region agreement is direct typed equality; raw materializer, occurrence, hashing, map-key, and compatibility schemas receive legacy integers only through named typed-to-legacy boundaries.
- Topology-region discovery/partition/numbering, `SurfaceTopologyRegion::id`, raw face-to-region maps, certificate/periodic/bounded-disk/occurrence/lineage schemas, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior remained outside M1l.
- Final semantic product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`, and compile-driven `tests/SurfaceCellTransitionQuotientTests.cpp`.

### Validation

- Implementation: `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; semantic source base `d5a97953416196a8fc74c8d9790a1ae7b646ca2d`.
- Authoritative Code + Build run/job `31441661026 / 93627457924` completed Release/static/Ninja/PRE_TEST **121/121** in **8:38.45**, peak RSS **1,860,672 KiB**, with every generated-runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag false.
- Code + Build result artifact `9083262395`, ZIP SHA-256 `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c`; build-log artifact `9083262833`, ZIP SHA-256 `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8`.
- Recursive manifest **56/56**, SHA-256 `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454`; package has 57 regular files including `SHA256SUMS`, seven executables, two static libraries, 27 fixtures including 21 milestone-G fixtures, zero symlinks; producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`.
- Authoritative immutable runtime run/job: `31444022339 / 93634344918`. Runtime evidence artifact `9083913766`, ZIP SHA-256 `64ad28a3334dd3e73346a221e619873dbbc523e879cb31dda0843caa0214cccd`; runtime log artifact `9083913939`, ZIP SHA-256 `a4f9188b19fb9d21d6f7af39b54f9409cb7c3109669d3fddb0fb62fc999ea917`.
- Producer discovery **226**; M1l focused **6/6** individually; M1k-M1b focused preservation all green; M1d route counterexamples **3/3**; M1c transition counterexamples **3/3**; required-green producer **211/211**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean; remote elapsed times were **1.35 / 2.03 / 16.36 / 8.82 s** respectively.
- All eight historical/deferred red classifications remained unchanged. Exact immutable postflight preserved all **56/56** package checksums and zero symlinks.

### Known limitations

- Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect because accepted historical samples vary materially.
- Bunny preserved `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; authoritative remote elapsed time was **78.06 s**.
- Vase selected one test, reached `[ RUN ]`, and remained bounded safety-only at **60 seconds** with exit code 124.
- `PR8-R034 / G4-R007` remains active; G4 is unchanged.

### Operational notes

- First compile run/job `31440241452 / 93623230585` found one existing compatibility assertion still comparing integer zero directly with the typed optional cell region. The correction was limited to the named legacy helper; no generated runtime executed and no stable product regression was assigned.
- A corrected **121/121** compile run/job `31440985022 / 93625446238` then failed only during package provenance because the shallow checkout lacked semantic base `d5a979...`; log artifact `9083016010`, SHA-256 `946490f115398519aa2b3e5bcb9955eb12775ea496ca4c426bcf6be06a1c9991`. The final workflow fetched that exact base before producing the semantic diff.
- One local first-process Cylinder stall during corroborating artifact execution did not reproduce in the immediate bounded local retry or the authoritative remote run. It remains an execution-plane/harness transient; no product workaround was added.
- No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**.

Authoritative report: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## [M1k] Phase-Front Edge Topology-Region Consumer — Immutable accepted

### Changed

- Migrated persistent `SurfaceFrontEdge::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId` at the seam `SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`.
- Preserved topology-region discovery, partition, numbering, raw cell/region-by-face identity, periodic/bounded-disk/certificate topology-region schemas, accepted source component/sheet authority, M2-M6, fallback/recovery, optimization, and G4 product behavior.
- Final product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, and `tests/SurfaceCellsPhase10Tests.cpp`; source parent `38d6fc4c4042c5a0d200abf4e5594dcf325b8383`.

### Validation

- Implementation: `b9181364926cea840e9cb50da21fe721f33fd874`.
- Code + Build run/job: `31430898273 / 93593780187`.
- Result artifact: `9079318682`, SHA-256 `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d`.
- Build-log artifact: `9079319269`, SHA-256 `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381`.
- Recursive manifest: **68/68**, SHA-256 `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c`.
- Package: 69 regular files, seven executables, two static libraries, 27 fixtures, zero symlinks.
- Producer SHA-256: `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1`.
- Authoritative immutable runtime run/job: `31433794426 / 93603203081`.
- Runtime evidence/log artifacts: `9080245848 / 9080246452`.
- Producer discovery **220**; M1k focused **6/6**; M1j-M1b focused preservation green; M1d route witnesses **3/3**; M1c transition counterexamples **3/3**; required-green producer **205/205**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean.
- All eight historical/deferred red classifications remained unchanged.
- Exact immutable postflight preserved all **68/68** package checksums.

### Known limitations

- Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect because accepted historical samples vary materially.
- Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remains bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remains active; G4 is unchanged.

### Operational notes

- Pre-authority Code + Build attempts exposed packaging/orchestration lessons without generated runtime execution: generated diffs may require `git apply --recount`; package cleanliness checks must exclude intentionally generated build/log directories; the fixture closure is 21 milestone-G files plus six root fixture files; checksum manifests must be generated after all package writes; and Bunny/Vase metadata must use the existing parameterized test names.
- A local Python `zipfile.extractall` attempt did not preserve packaged executable mode bits. Immutable runtime extraction must use the archive naturally, such as CLI `unzip`; `chmod` or package repair is not evidence-preserving.
- One local Cylinder harness stall did not reproduce in immediate bounded local execution or either controlled remote run; no product workaround was added.
- The first remote semantic run was green but its evidence upload used the wrong temporary-root path. Future workflows must use `${{ runner.temp }}` / `$RUNNER_TEMP` consistently.
- No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**.

The former M1k per-turn report was retired under `CLEAN_UP_POLICY.md` after its durable acceptance facts were consolidated here, in the regression tracker, and in immutable GitHub artifact history.

## [M1j] Phase-Front Edge Source-Scope Consumer — Immutable accepted

### Changed

- Preserved checked edge-owned source-component and isolation-sheet authority through the production path while keeping edge topology-region identity outside M1j.
- Final product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, and `tests/SurfaceCellsPhase10Tests.cpp`; source parent `391271e253557b5c6b267befb3f2f33330c090c9`.

### Validation

- Implementation: `d5f681173600dc32dc7617de6105d9e584e593be`.
- Code + Build run/job: `31422691741 / 93566993166`, **120/120**, Release/static/Ninja/PRE_TEST.
- Result artifact `9076217893`, ZIP SHA-256 `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c`.
- Build-log artifact `9076218338`, ZIP SHA-256 `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`.
- Recursive manifest **67/67**, SHA-256 `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`; 68 regular files, seven executables, two static libraries, 27 fixtures; producer SHA-256 `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`.
- Producer discovery **214**; M1j focused **6/6**; required-green **199/199**; M1i-M1b focused preservation green; M1d route witnesses **3/3**; M1c transition counterexamples **3/3**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean without a fixture symlink.
- Remote validation run/job: `31425748772 / 93576908519`; evidence/log artifacts `9077128237 / 9077129029`.
- Heavy artifact-only run: `31425364955`.
- Bunny evidence/log artifacts: `9076993439 / 9076993713`.
- Vase evidence/log artifacts: `9076989920 / 9076990491`.
- Exact preflight/postflight preserved the immutable package and `fixtureSymlink=false`.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing remained deferred after fresh **0/10** characterization.
- Bunny retained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remained active.

### Operational notes

- Initial implementation `274b7ab88b581aa63e2e99c3abca2bc89eb742e2` exposed one incomplete raw/typed periodic-relation component comparison during compile. The final implementation corrected only that named compatibility boundary; no previously accepted runtime authority was lost.
- Earlier successful compile artifact `9075863759` was superseded because its manifest was generated before a final package log copy. The authoritative package computes and verifies the manifest only after all package writes are complete.
- No stable product regression event or recurrence was created; totals remained **34 / 14 / 20**.
- The superseded M1j Code + Build plan/report and artifact-only plan/report were removed under `CLEAN_UP_POLICY.md` after the durable implementation, validation, failure-class, and failed-attempt facts were consolidated here and in the regression tracker/GitHub artifact history.

## [M1i] Phase-Front Cell Source-Scope Consumer — Immutable accepted

### Changed

- Migrated persistent constructive-cell source component and isolation-sheet scope to checked typed authority while preserving existing source-label semantics and downstream compatibility boundaries.

### Validation

- Implementation: `b037157921094604f1b0c17f9c8b7076c7604b3b`.
- Source parent: `48614f383111c96fce1e69871b66199d94033d11`.
- Code + Build run/job: `31411770135 / 93531293415`.
- Result artifact `9072101943`, ZIP SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25`.
- Build-log artifact `9072102331`, ZIP SHA-256 `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`.
- Recursive manifest **72/72**, SHA-256 `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`; 73 regular files, seven executables, two static libraries, 27 fixtures; producer SHA-256 `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d`.
- Producer discovery **208**; M1i focused **6/6**; required-green **193/193**; M1h-M1b focused preservation green; M1d route witnesses **3/3**; M1c transition counterexamples **3/3**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean without a fixture symlink.
- Heavy artifact-only run: `31416928654`.
- Bunny evidence/log artifacts: `9073803244 / 9073803836`.
- Vase evidence/log artifacts: `9073801150 / 9073801757`.
- Local and remote postflight preserved the exact immutable package and `fixtureSymlink=false`.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing remained deferred after fresh **0/10** characterization.
- Bunny remained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remained active.

### Operational notes

- M1b focused names belong to the validation executable; a zero-selected filter is an orchestration error and never a semantic pass.
- Temporary Actions YAML must not use an unindented shell heredoc inside a block scalar; two pre-job heavy runs failed syntax validation before the corrected run. A committed helper payload or indentation-safe script is preferred.
- Historical regression totals remained **34 events / 14 categories / 20 recurrences**.
- The superseded M1i Code + Build plan and artifact-only report were removed under `CLEAN_UP_POLICY.md` after their durable implementation/test facts were consolidated here and in the regression tracker/GitHub artifact history.

## [M1h] Phase-Front Field-Chart Consumer — Immutable accepted after test-authority remediation

### Changed

- Adopted typed field-chart authority at the constructive-front consumer while preserving existing product behavior.
- Remediation corrected the focused test witness without changing the accepted production implementation.

### Validation

- Remediation implementation: `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`.
- Unchanged production implementation: `de4e2ba7c19d2e49931655dc22d758f50656d054`.
- Build run/job: `31404102605 / 93506073062`.
- Result artifact `9069186973`, ZIP SHA-256 `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8`.
- Build-log artifact `9069187317`, ZIP SHA-256 `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a`.
- Recursive manifest **72/72**, SHA-256 `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8`; 73 regular files, seven executables, two static libraries, 27 fixtures; producer SHA-256 `937adceea641f372ee42eeb9a3b91c3bba2088847755cc234eaf0b3754f208ac`.
- Producer discovery **202**; M1h focused **6/6**; required-green **187/187**; M1g-M1b preservation green; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean without a fixture symlink.
- Heavy artifact-only run: `31407263138`.
- Bunny evidence/log artifacts: `9070146263 / 9070146878`.
- Vase evidence/log artifacts: `9070135665 / 9070135953`.
- Local and remote postflight preserved the exact immutable package with `fixtureSymlink=false`.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing remained deferred after fresh **0/10** characterization.
- Bunny remained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remained active.

### Operational notes

- The preceding immutable runtime from artifact `9066967620` was blocked at M1h **5/6** and required-green **186/187** because the focused witness conflated producer chart-domain coverage `{0,1,2}` with sampled lattice-occurrence coverage `{0,2}`. It was classified as a test-authority defect, not a product regression; the accepted remediation was test-only and preserved the production implementation.
- Historical regression totals remained **34 events / 14 categories / 20 recurrences**.
- The superseded M1h artifact-only report was removed under `CLEAN_UP_POLICY.md` after its durable implementation/test-authority facts were consolidated here and in the regression tracker/GitHub artifact history.

## [M1g] Periodic Holonomy Route Transport Consumer — Immutable accepted

### Changed

- Migrated the seam `periodic canonical face cycle -> ordered source-edge crossings -> whole-cycle holonomy decision` to checked source-step identity and typed route transport.
- Preserved the existing nonzero whole-cycle `PeriodicHolonomyMismatch`; M1g did not implement nonzero periodic Z4 support.

### Validation

- Implementation: `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2`.
- Code + Build run/job: `31362470744 / 93373936472`, **120/120**.
- Result artifact `9053047653`, ZIP SHA-256 `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c`.
- Build-log artifact `9053048092`, ZIP SHA-256 `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9`.
- Recursive manifest **64/64**, SHA-256 `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae`.
- Producer discovery **196**; M1g **6/6**; required-green **181/181**; complete M1f/M1e/M1d/M1c/M1b preservation; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean.
- Bunny stayed known-red and Vase bounded safety-only under remote run `31394985769`; exact local and remote postflight passed.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing characterized **1/10 pass, 9/10 fail**, preserving the existing nondeterministic performance-test defect.
- Nonzero periodic Z4 capability remains unresolved as `G4-B003`.

### Operational notes

- Runtime validation discovered that packaged binaries resolved `benchmarks/fixtures` relative to the executable/current working directory and therefore failed from immutable extraction without a fixture symlink. This was classified as a package-portability defect and assigned to M1h remediation rather than repaired inside the M1g artifact turn.
- No new stable product regression event or recurrence was created; totals remained **34 / 14 / 20**.
- Superseded M1g/M1h per-turn evidence was later consolidated here and in the tracker before removal under `CLEAN_UP_POLICY.md`.

## [M1f] Vertex Continuation Route Transport Consumer — Immutable accepted

### Changed

- Replaced the continuation-route `PathState::matching` unrestricted signed accumulator in `resolve_vertex_continuation` with checked source-vertex/interior-transition authority, canonical source-edge topology keys, typed `TransitionStep`/`CanonicalRoute`, and algebraic `GridAutomorphism` composition.
- Preserved route search/ranking, transition-domain identity, route orientation, public/raw compatibility output, M1e/M1d/M1c/M1b semantics, periodic whole-cycle behavior, product behavior, fallback/recovery, optimization, and G4.

### Validation

- Implementation: `baed0f24831c476f45a1b742c12314e3fb03e10e`.
- First failed compile attempt: `17afbfd9beb44213d65b088c94624691989622ef`; the new forward declaration targeted the wrong namespace for an existing anonymous helper. Final implementation used a narrow continuation-owned provenance helper instead of refactoring unrelated ownership.
- Code + Build run/job `31358314392 / 93362155247`, **120/120**, Release/static/Ninja/PRE_TEST; no generated runtime/discovery/test/benchmark executed.
- Result artifact `9050850344`; ZIP SHA-256 `d71042a80e207fbedabdaf744554740383140a516430104f1a4c20b41ceff607`.
- Build-log artifact `9050850809`; ZIP SHA-256 `44b3c17cc802232652c51588009402601a43493b0aa080da5d497c21dc9f2186`.
- Manifest **63/63**, SHA-256 `8841631907af9208a96a601440f02e4e24b0cfef9c9950260e146c22349fb49a`.
- Package contained seven executable artifacts, two static libraries, 27 fixture files, source archive/patch/compile database, source blobs, and exact test-name metadata.
- Producer discovery **190**; M1f **6/6**; required-green **175/175**; M1e/M1d/M1c/M1b preservation; validation **77/77**; M1a **14/14**; T1 **29/29**; direct Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean.
- All entering historical/deferred reds retained their classifications; Bunny remained known-red and Vase bounded safety-only; exact postflight clean.

### Known limitations

- Strict-validator timing remained the existing nondeterministic microbenchmark defect.
- Bunny/Vase and G4 stayed outside M1f.

### Operational notes

- The first result package was semantically correct but metadata-normalization had changed mode bits on executable payloads. The immutable artifact was regenerated from exact built files rather than repaired after packaging. Package metadata itself is part of artifact authority.
- No stable product regression event or recurrence was created.

## [M1e] Segment Route Transport Consumer — Immutable accepted

### Changed

- Migrated `surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments` from unrestricted signed matching accumulation to checked source-vertex and interior-transition step identity, canonical source-edge topology, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition.
- Preserved observed route order through `CanonicalRoute::oriented_steps()`; canonical storage order does not become traversal behavior.
- Kept signed/raw matching only as a compatibility write after typed composition.
- Left continuation search, periodic whole-cycle logic, field-chart production, public schema retirement, topology/conformity/quotient work, validators, fallback/recovery, optimization, and G4 outside M1e.

### Validation

- Implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`; semantic source parent `840172cc766629529752d7fb75f18ff6a1aa089c`.
- Build event/control-plane commit `34036600128262e909c377006a056a2b9976f986`.
- Code + Build run/job `31351113129 / 93341993183`, **120/120**; result artifact `9049125645`, SHA-256 `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7`; log artifact `9049125905`, SHA-256 `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`; manifest **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`.
- Code + Build executed no generated Directional binary, discovery, test, or benchmark.
- Immutable artifact-only runtime passed M1e **6/6**, required-green producer **169/169**, M1d **6/6** plus route counterexamples **3/3**, M1c **6/6** plus transition counterexamples **3/3**, M1b **6/6**, validation **77/77**, M1a **14/14**, T1 **29/29**, and direct Plane/MultiFaceSeam/CloseSheets/Cylinder.
- All separately classified historical/deferred reds remained explicit; Bunny stayed known-red and Vase bounded safety-only; exact postflight passed.

### Fixed

- The initially proposed malformed-domain test tried to mutate hidden raw route storage after the migration had correctly removed that raw semantic storage. The contract was corrected to inject malformed source provenance at the public producer boundary and verify fail-closed rejection, preserving test intent rather than implementation detail.

### Known limitations

- Strict-validator timing remained deferred as the existing nondeterministic performance-test defect.
- No periodic whole-cycle capability, G4 product repair, or public legacy retirement occurred.

### Operational notes

The accepted boundary obeys these durable rules:

1. checked source IDs are created before semantic use;
2. transition IDs use the one source-wide compact transition extent;
3. canonical edge keys and route storage are distinct from observed traversal orientation;
4. typed composition is the only semantic matching authority inside the selected seam;
5. raw matching is compatibility output only;
6. malformed source provenance fails closed at the producer boundary;
7. no helper/unit-only test substitutes for production-path contracts;
8. no recovery/fallback masks direct SurfaceCells behavior;
9. product cases remain independent authority rather than inferred from focused passes;
10. later consumers may reuse the pattern but must be migrated as separate bounded turns.

No new stable product regression event or recurrence was created.

## [M1d] Authoritative Interior-Route Identity Consumer — Immutable accepted

### Changed

- Migrated the exact `pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid` seam so packed route endpoints cross checked source-vertex boundaries and supplied/authoritative compact route indices cross checked interior-transition boundaries before semantic comparison.
- Semantic transition equality uses `InteriorTransitionId`, with raw integer equality retained only as compatibility representation.
- Preserved malformed-route fail-closed outcomes under existing HardRail/PeriodicCut authority failures; no route transport algebra was added in M1d.

### Validation

- Implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`.
- Code + Build run/job `31342400614 / 93318225812`; result artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`; manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`.
- Producer discovery **178**, required-green **163/163**, M1d **6/6**, route counterexamples **3/3**, M1c **6/6** plus transition counterexamples **3/3**, M1b **6/6**, validation **77/77**, M1a **14/14**, T1 **29/29**.
- Plane/MultiFaceSeam/CloseSheets/Cylinder were green and independent-oracle clean; Bunny known-red and Vase bounded safety-only remained preserved; exact package postflight passed.

### Known limitations

- The selected consumer validates route identity but does not own per-step transport; `TransitionStep` / `CanonicalRoute` adoption was intentionally deferred to M1e.
- Strict-validator timing remained the existing nondeterministic performance-test defect.

### Operational notes

- A redundant M1d runtime workflow run `31343858635` existed during orchestration and is not immutable authority.
- Temporary workflows, triggers, and payloads were removed only after the authoritative evidence/run was recorded.
- No new stable product regression event or recurrence was created.
