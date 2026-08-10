# M1i Phase-Front Cell Source-Scope Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Implementation:** `b037157921094604f1b0c17f9c8b7076c7604b3b`  
**Source parent:** `48614f383111c96fce1e69871b66199d94033d11`  
**Accepted predecessor:** M1h remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`  
**Review policy:** `never`  
**Date:** 2026-08-10 UTC

## 1. Result

M1i Code + Build is complete at the bounded seam:

`surface_cell_tracing_detail::phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

The implementation migrates persistent **cell-owned** source-component and isolation-sheet authority from raw integers to checked semantic IDs while preserving the existing source-label behavior and retaining raw `SurfaceFrontEdge` and pipeline-facing representations only as explicit compatibility boundaries.

This turn establishes compile/package authority only. **No M1i semantic or runtime acceptance is claimed.** The mandatory next turn is immutable Artifact-Only Test + Benchmark over the exact package recorded below.

## 2. Exact implementation scope

The implementation commit changes exactly four paths relative to source parent `48614f383111c96fce1e69871b66199d94033d11`:

| Path | Delta |
|---|---:|
| `include/directional/geometry/SurfaceCellTracing.h` | +6 / -3 |
| `src/geometry/SurfaceCellTracing.cpp` | +86 / -32 |
| `src/pipeline/RemeshPipeline.cpp` | +47 / -13 |
| `tests/SurfaceCellsPhase10Tests.cpp` | +277 / -5 |
| **Total** | **+416 / -53** |

No CMake, fixture, validator, benchmark-data, source-field, or public product-policy file changed. `tests/TestFixturePaths.h` remains byte-identical to accepted M1h.

## 3. Production migration

### 3.1 Persistent cell source scope

`SurfacePhaseFrontCell` now owns:

```cpp
std::optional<authority::SourceComponentId> sourceComponent;
std::optional<authority::IsolationSheetId> sourceSheet;
std::vector<authority::IsolationSheetId> sourceIsolationSheets;
```

The previous raw `int sourceComponent`, `int sourceSheet`, and `std::vector<int> sourceIsolationSheets` cell authority are removed.

`sourceTopologyRegion` intentionally remains raw and is outside M1i scope.

### 3.2 Checked source-label construction

`phase_front_cell_source_scope` now:

1. derives explicit component/sheet extents from the currently authoritative source-face label arrays;
2. rejects negative enabled labels fail-closed;
3. converts each observed component through `LegacyAuthorityAdapters::source_component`;
4. converts each observed sheet through `LegacyAuthorityAdapters::isolation_sheet`;
5. requires all participating corner/path faces to agree on the same typed `SourceComponentId`;
6. retains every observed `IsolationSheetId` in sorted, deduplicated semantic order;
7. sets the optional single-sheet value only when exactly one isolation sheet is present.

An empty source-label array retains the existing default-zero behavior with an explicit one-element authority extent. Numeric equality does not convert between component and sheet domains.

### 3.3 Explicit compatibility boundary

M1i does **not** migrate `SurfaceFrontEdge` source scope or the broader pipeline schema. Local named conversion helpers expose raw integers only where a still-unmigrated consumer requires them:

- phase-front edge construction;
- aggregate source-region validation;
- pipeline structural hashing;
- authoritative phase-front materialization/validation;
- legacy edge/cell owner comparisons.

The typed cell state is the source of those compatibility values; no duplicate raw cell-owned mirror is retained.

### 3.4 Producer behavior intentionally unchanged

Periodic-annulus and curved bounded-disk producers no longer preassign raw component/sheet values directly into a cell. Instead they use the same checked `phase_front_cell_source_scope` path as the other constructive-cell paths.

M1i does not alter:

- source topology-region identity;
- local isolation-sheet semantics;
- field-chart authority;
- hard-rail or periodic owner authority;
- quotient relations;
- fallback/recovery;
- G4 completion/singularity behavior;
- validator or benchmark thresholds;
- fixtures or known-red expectations.

## 4. Focused contracts compiled, not executed

Exactly six new contracts compile under:

`SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration`

1. `PlanarCellPublishesCheckedDefaultComponentAndSheet`
2. `ExplicitSourceLabelsRemainDistinctTypedDomains`
3. `MultipleObservedSheetsDoNotInventRepresentativeSheet`
4. `MalformedSourceScopeFailsClosed`
5. `FaceRowPermutationPreservesTypedCellSourceScope`
6. `CellToLegacyEdgeBoundaryPreservesTypedScope`

The suite exercises production construction paths rather than adapter mechanics alone. It includes compile-time domain distinction between `SourceComponentId` and `IsolationSheetId`, explicit source-label production, the existing reciprocal two-face isolation-seam path for multi-sheet retention, malformed-label fail-closed behavior, row-permutation semantic comparison, and typed-cell-to-legacy-edge compatibility.

These tests were **not executed** in this turn.

## 5. Build execution boundary

The successful authoritative retry configured:

- Ubuntu 24.04 runner;
- GCC 13.3.0;
- CMake 3.31.6;
- Ninja 1.13.2;
- Release;
- static Directional libraries;
- GMP enabled;
- PARDISO/cuDSS/SuiteSparse disabled;
- tests and benchmarks compiled;
- CLI/GUI/Python/tutorials disabled;
- GoogleTest discovery mode `PRE_TEST`.

Approved targets compiled **120/120**:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_oracle_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Build resources:

- wall time: **7:39.61**;
- user CPU: **886.07 s**;
- system CPU: **13.60 s**;
- peak RSS: **1,857,412 KiB**;
- exit status: **0**.

No generated Directional executable was run. Package command-boundary metadata records:

```text
runtimeExecution=false
testExecution=false
benchmarkExecution=false
ctestExecution=false
cliExecution=false
fuzzerExecution=false
customInputExecution=false
```

## 6. Packaging retry provenance

The first workflow attempt, run/job `31410750675 / 93527929843`, successfully:

- established implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`;
- passed the static M1i contract checks;
- configured successfully;
- compiled **120/120** approved targets.

It then failed in packaging because `sha256sum -c` was invoked from the repository working directory while the generated manifest contained paths relative to the package root. That failure was an orchestration/package-verification working-directory defect. It was **not** a compile failure and made no semantic/source correction necessary.

First-attempt diagnostic log artifact:

- ID `9071739970`;
- SHA-256 `d47b021fa6d7647e9569cf9f03f4454f77a07ccb6dd50da4c95668f2f4a27c28`.

The original temporary workflow was retired. The corrected packaging retry made **no source delta**, detached the exact implementation commit, rebuilt the same source, performed manifest generation/verification from the package root, and succeeded.

## 7. Authoritative successful build/package evidence

Successful workflow:

- run `31411770135`;
- job `93531293415`;
- conclusion **success**.

Immutable result artifact:

- ID `9072101943`;
- name `m1i-cell-source-scope-code-build-result`;
- ZIP SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25`.

Dedicated log artifact:

- ID `9072102331`;
- name `m1i-cell-source-scope-code-build-logs-r2`;
- ZIP SHA-256 `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`.

Independent download verification matched both outer ZIP digests.

Recursive result-package authority:

- **72/72** manifest entries verified;
- `SHA256SUMS` digest `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`;
- **73** regular files including `SHA256SUMS`;
- **7** executable files;
- **2** Directional static libraries;
- **27** fixture files.

## 8. Executable and library authority

Executables:

| Binary | SHA-256 |
|---|---|
| `directional_benchmarks` | `0b884b652a4e8f8ed1a3d895ad59cfab67c53f4ab9ae922b5e02119f7dd311a2` |
| `directional_compiled_api_tests` | `2df86d5d394a426c5dfb87113bb723f56702fb691088dec5bba033fe7d1d920c` |
| `directional_surface_cell_producer_tests` | `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d` |
| `directional_surface_cell_oracle_tests` | `5fe8cd237ff91e445c1edb1cb8de226fd1e623f87ae810912d0f087c292caf62` |
| `directional_surface_cell_authority_kernel_tests` | `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71` |
| `directional_surface_cell_validation_tests` | `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6` |
| `directional_surface_cell_completion_tests` | `efe2499a034a80f220090da5a32d8aeee12a784c9dc63781a8e281a5720cc121` |

Libraries:

| Library | SHA-256 |
|---|---|
| `libdirectional_core.a` | `22eac5285707982cce339d4dbbc395e2bae28ac7b3c8c947031dbbf06b6e31dc` |
| `libdirectional_pipeline.a` | `fcf6c92cc3f03031b1da675fe16a98c96477907c1e22d0ee36f5038bb0fb249f` |

## 9. Compiled source authority

| Path | Git blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `4036b16a3dc7e20369a9cd65a4422c61be58afb4` |
| `src/geometry/SurfaceCellTracing.cpp` | `33a41e70e240f198eaa49184c3a87773986b84cb` |
| `src/pipeline/RemeshPipeline.cpp` | `601d02b7560e489246e30e1fa572f8ac2d6d1250` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `f63396f54e70d3c106cd2acbc4758e9d4fb1dda0` |
| `tests/TestFixturePaths.h` | `4a981f772ee70780d0011696010a0e1b8bef6972` |

Packaged exact source patch SHA-256:
`6e722546dc50531d3ec45060ede59b33e28ede344f8e86be1f51227067b8612c`.

Packaged source archive SHA-256:
`2a59a1d213ca11f6b275b8d3a0964cfbea8b1a8f7bcb126497aac383fa2aa664`.

## 10. Declared suite authority packaged for the next turn

Source-level manifest generation records:

- M1i: 6;
- M1h: 6;
- M1g: 6;
- M1f: 6;
- M1e: 6;
- M1d: 6;
- M1c: 6;
- M1b: 6;
- M1a: 14;
- T1: 29.

These are source-declared/packaged names only. Runtime discovery is deliberately deferred to the immutable Test + Benchmark turn.

## 11. Regression disposition

M1i touches the established patterns:

- `RP-01` — authority-domain conflation;
- `RP-05` — representation-dependent identity;
- `RP-02 / TA-05` — test-authority adequacy.

Compile-only evidence creates no stable product regression event or recurrence. Historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

The first packaging failure is not a product regression and did not trigger a source change. It is retained here as workflow/orchestration provenance so the same manifest-working-directory mistake is not repeated.

## 12. Mandatory next turn

Run **M1i Phase-Front Cell Source-Scope Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only artifacts `9072101943 / 9072102331` from implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`.

No source, test, fixture, validator, build, or packaged content may be repaired or substituted in that runtime turn. M1i remains **runtime pending** until those immutable gates pass.
