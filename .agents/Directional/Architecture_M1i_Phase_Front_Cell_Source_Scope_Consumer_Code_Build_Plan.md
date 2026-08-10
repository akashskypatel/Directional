# M1i Phase-Front Cell Source-Scope Consumer — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Prerequisite:** M1h immutable accepted  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Entering authority

M1h is immutable accepted from remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` and exact result/log artifacts `9069186973 / 9069187317`.

Accepted M1h runtime authority:

- producer discovery **202**;
- M1h focused **6/6** individually;
- required-green producer **187/187**;
- M1g/M1f/M1e/M1d/M1c/M1b focused preservation green;
- validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean without a fixture symlink;
- all eight historical/deferred red classes unchanged;
- Bunny known-red unchanged; Vase bounded safety-only;
- exact **72/72** package postflight preserved.

M1i must preserve this authority. Compile/package success alone will not make M1i semantically accepted.

## 2. Selected bounded seam

M1i migrates only the persistent constructive-cell source-scope consumer:

`surface_cell_tracing_detail::phase_front_cell_source_scope`

into:

`SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

Fresh accepted-source inspection shows that M1h has typed field-chart state but `SurfacePhaseFrontCell` still persists source-component and isolation-sheet identity as bare integers. The authority kernel already defines distinct `SourceComponentId` and `IsolationSheetId` domains and checked legacy adapters. Normative `DESIGN.md` requires source topology region, isolation sheet, field chart, and quotient class to remain separate semantic domains.

This is the next smallest production owner that can consume the existing strong-ID kernel without entering M2 single-writer/outcome redesign or G4 feature work.

## 3. Required implementation shape

The implementation must keep the current producer topology and source-label semantics unchanged while moving persistent cell-owned source scope to checked types.

Required changes:

1. replace `SurfacePhaseFrontCell::sourceComponent` with an optional/otherwise explicitly nullable `authority::SourceComponentId`;
2. replace `SurfacePhaseFrontCell::sourceSheet` with an optional/otherwise explicitly nullable `authority::IsolationSheetId` for the single-sheet compatibility case;
3. replace `SurfacePhaseFrontCell::sourceIsolationSheets` with a typed collection of `authority::IsolationSheetId`;
4. make `phase_front_cell_source_scope` establish checked component/sheet identity from source-face authority before returning semantic scope;
5. preserve the existing rule that all faces participating in one cell must agree on source component;
6. preserve all distinct isolation sheets observed by the cell, sorted/deduplicated by semantic ID;
7. set the single-sheet value only when the typed isolation-sheet set has cardinality one; a multi-sheet cell must not manufacture a representative sheet;
8. use named `LegacyAuthorityAdapters` conversions only at existing raw compatibility boundaries required by still-unmigrated consumers;
9. fail closed through the existing production failure path when a required component/sheet label cannot establish valid authority;
10. preserve deterministic behavior under source-face row permutation and container order.

If source labels are represented by non-negative legacy values, establish an explicit checked extent from the already-validated label authority; do not use numeric coincidence between component and sheet domains as conversion.

## 4. Compatibility boundary

This turn deliberately migrates **cell-owned source scope only**.

Still-raw neighboring representations may receive explicit compatibility integers derived from the typed cell scope where compilation requires them. Such conversions are representation boundaries, not new authority.

Do not add a second raw mirror of the same cell-owned source scope. The typed state is authoritative once constructed.

## 5. Explicit exclusions

M1i must **not** broaden into:

- `SurfaceFrontEdge::{sourceComponent, sourceTopologyRegion, sourceSheet, sourceIsolationSheets}` semantic migration beyond explicit compatibility conversion from the typed cell;
- `SurfaceTopologyRegion` or `TopologyRegionId` migration;
- `SurfacePeriodicHolonomy`, bounded-disk phase, isolation-seam certificate, or periodic relation owner migration;
- `HardRailId`, `PeriodicRelationId`, `CellId`, `OccurrenceId`, or `QuotientClassId` adoption;
- public route/segment schema retirement;
- source-sheet/topology boundary behavior changes;
- new hard-feature, relief-barrier, periodic, singularity, or G4 completion behavior;
- fallback/recovery changes;
- M2 closed producer outcomes or single-writer snapshots;
- M3 global conformity planning;
- M4 certificate/quotient redesign;
- M5 occurrence/embedding split;
- M6 legacy-representation retirement;
- fixture data, validator thresholds, benchmark thresholds, or known-red expectations.

In particular, do not reinterpret source-sheet labels as physical source boundaries in this authority-migration slice. M1i types existing source-scope semantics; it does not change them.

## 6. Focused production-path contracts

Add exactly six focused contracts under suite:

`SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration`

The contracts must exercise production paths, not only adapter mechanics:

1. `PlanarCellPublishesCheckedDefaultComponentAndSheet`  
   A valid planar constructive cell must publish typed component/sheet zero and a one-element typed isolation-sheet set.

2. `ExplicitSourceLabelsRemainDistinctTypedDomains`  
   A production cell built from explicit source labels must reproduce the hard-authored component and sheet IDs through the correct typed domains; equal legacy numeric values must not make component and sheet interchangeable.

3. `MultipleObservedSheetsDoNotInventRepresentativeSheet`  
   When an existing valid production scenario legitimately records more than one isolation sheet for a cell, the typed collection must retain every sheet while the single-sheet optional remains empty. If fresh source inspection proves that such a cell is unreachable by the current producer contract, replace this with the nearest reachable production predecessor that proves the same no-representative-alias invariant; do not synthesize an impossible fixture.

4. `MalformedSourceScopeFailsClosed`  
   Negative, missing, or otherwise invalid authoritative component/sheet labels must not masquerade as valid typed scope or fall back to geometric/default ownership when label authority is enabled.

5. `FaceRowPermutationPreservesTypedCellSourceScope`  
   An equivalent face-row permutation must preserve the semantic component/sheet set of produced cells under semantic matching rather than positional pairing.

6. `CellToLegacyEdgeBoundaryPreservesTypedScope`  
   Where current `SurfaceFrontEdge` remains a raw compatibility consumer, the emitted legacy component/sheet values must equal explicit conversions from the typed cell authority; no raw cell mirror may drive the edge independently.

Every test must fail for a meaningful violation of the intended authority contract. Do not assert private implementation mechanics that are not semantically required.

## 7. Regression-pattern interlock

Review `Regression_Root_Cause_Tracker.md` before editing.

M1i directly touches:

- `RP-01` authority-domain conflation;
- `RP-05` representation-dependent identity;
- `RP-02 / TA-05` test-authority adequacy.

Required counterexamples/invariants:

- `SourceComponentId` and `IsolationSheetId` are not numerically interchangeable;
- malformed enabled label authority fails closed;
- cell scope derives from source-face authority, not first/last container position;
- multiple isolation sheets remain a set of semantic identities rather than a selected representative;
- face-row order cannot change semantic cell scope;
- raw downstream compatibility values are derived from typed cell scope only.

Do not add a new stable regression ID from compile-only evidence.

## 8. Allowed files

Expected production/test scope is narrow:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

`src/pipeline/RemeshPipeline.cpp` may be touched only if compilation proves that a direct consumer of `SurfacePhaseFrontCell` requires an explicit typed-to-legacy compatibility conversion. Any additional production path requires a documented compile-driven reason before editing.

No CMake, fixture, validator, benchmark-data, or public product-policy changes are expected.

## 9. Code + Build execution boundary

This turn may:

- inspect accepted source;
- implement the bounded source/test migration;
- configure a compile-only Release/static/Ninja build with GoogleTest discovery mode `PRE_TEST`;
- compile/link the approved targets;
- package immutable binaries, libraries, fixtures, source authority, logs, metadata, and recursive checksums.

This turn must **not execute any generated Directional binary**, including:

- GoogleTest discovery/list commands;
- tests;
- benchmarks;
- `ctest`;
- CLI/GUI/help/version commands;
- fuzzers;
- custom-mesh execution.

Record `runtimeExecution=false` and equivalent command-boundary facts in the package.

## 10. Approved compile targets

Compile only the established M1 authority package targets:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_oracle_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

A successful build must package the same fixture closure and independent oracle/authority executables used by M1h.

## 11. Required package metadata

The immutable Code + Build artifact must record:

- exact implementation commit and source parent;
- accepted M1h implementation/package reference;
- source/test blob IDs for every changed path;
- exact source patch/archive;
- toolchain/configuration and shallow-submodule authority;
- command-boundary metadata proving no generated project runtime executed;
- executable and library SHA-256 values;
- exact focused test-name manifests;
- fixture inventory;
- recursive `SHA256SUMS` and its digest.

The following Test + Benchmark turn must consume this exact package without rebuilding or repairing it.

## 12. Code + Build acceptance gate

The Code + Build turn is complete only if:

1. the diff remains within the bounded M1i source-scope seam;
2. cell-owned source scope is typed and no duplicate raw cell authority remains;
3. all compatibility conversions are explicit and local to still-unmigrated consumers;
4. exactly six meaningful M1i focused contracts compile;
5. the approved targets compile/link successfully;
6. immutable package authority and recursive checksums are complete;
7. every runtime flag is false;
8. no source/test/fixture expectation was weakened to obtain compilation;
9. temporary workflows/triggers/payloads are removed before closeout;
10. PR #8 remains open, draft, and unmerged.

Compile success does not accept M1i semantics. The mandatory following turn is immutable Artifact-Only Test + Benchmark over the exact package.
