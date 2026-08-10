# M1i Phase-Front Cell Source-Scope Consumer — Immutable Artifact-Only Test + Benchmark Report

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Implementation under test:** `b037157921094604f1b0c17f9c8b7076c7604b3b`  
**Result:** **immutable accepted**  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Decision

M1i is **immutable accepted** at:

`phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

The exact Code + Build package preserves the intended typed `SourceComponentId` / `IsolationSheetId` cell authority, multi-sheet no-representative semantics, fail-closed malformed-label handling, face-row permutation invariance, and typed-to-legacy compatibility behavior. No new stable product regression or recurrence was observed.

This turn changed no production source, header, test, fixture, validator, benchmark, or build logic and did not configure, compile, relink, regenerate, repair, or substitute package content.

## 2. Immutable input authority

| Evidence | Value |
|---|---|
| implementation | `b037157921094604f1b0c17f9c8b7076c7604b3b` |
| source parent | `48614f383111c96fce1e69871b66199d94033d11` |
| successful build run/job | `31411770135 / 93531293415` |
| result artifact | `9072101943` — `m1i-cell-source-scope-code-build-result` |
| result ZIP SHA-256 | `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25` |
| log artifact | `9072102331` — `m1i-cell-source-scope-code-build-logs-r2` |
| log ZIP SHA-256 | `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44` |
| recursive manifest | **72/72**, SHA-256 `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3` |
| package cardinality | **73** regular files, 7 executables, 2 static libraries, 27 fixtures |
| producer SHA-256 | `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d` |

Packaged source/test authority matched the Code + Build declaration:

- tracing header `4036b16a3dc7e20369a9cd65a4422c61be58afb4`;
- tracing implementation `33a41e70e240f198eaa49184c3a87773986b84cb`;
- pipeline `601d02b7560e489246e30e1fa572f8ac2d6d1250`;
- phase-10 tests `f63396f54e70d3c106cd2acbc4758e9d4fb1dda0`;
- fixture-path helper `4a981f772ee70780d0011696010a0e1b8bef6972`.

`metadata/build-authority.json` identifies the exact implementation/source parent, run `31411770135`, Release/static/Ninja/PRE_TEST, and every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input build-turn flag as false.

Preflight rejected unsafe archive paths, verified the exact ZIP and manifest digests, verified every **72/72** package checksum, cardinalities, source authority, producer hash, and confirmed there was no `bin/test-data` or other runtime fixture symlink.

## 3. Native discovery authority

Native packaged GoogleTest discovery was exact:

| Target | Discovered |
|---|---:|
| producer | **208** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

Producer discovery is accepted M1h discovery 202 plus exactly six M1i contracts.

## 4. M1i focused acceptance

Each M1i contract ran in a fresh process and selected exactly one test:

1. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.PlanarCellPublishesCheckedDefaultComponentAndSheet` — pass.
2. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.ExplicitSourceLabelsRemainDistinctTypedDomains` — pass.
3. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.MultipleObservedSheetsDoNotInventRepresentativeSheet` — pass.
4. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.MalformedSourceScopeFailsClosed` — pass.
5. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.FaceRowPermutationPreservesTypedCellSourceScope` — pass.
6. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.CellToLegacyEdgeBoundaryPreservesTypedScope` — pass.

Result: **6/6**.

The multi-sheet witness remains reachable through the production path and does not invent a representative `sourceSheet`. The face-row permutation witness remains semantic rather than positional.

## 5. Entering M1 preservation

Focused preservation remained fully green:

| Slice | Result |
|---|---:|
| M1h field-chart authority | **6/6** |
| M1g periodic-holonomy route transport | **6/6** |
| M1f vertex-continuation route transport | **6/6** |
| M1e segment-route transport | **6/6** |
| M1d phase-front route identity | **6/6** |
| M1c field-transition authority | **6/6** |
| M1b source/provenance consumer | **6/6** |
| M1d route counterexamples | **3/3** |
| M1c transition counterexamples | **3/3** |

M1b's six focused names are owned by the validation executable, not the producer executable. An initial harness invocation accidentally applied the M1b manifest to the producer and therefore selected **0 tests** six times with rc=0. Native discovery immediately identified the target mismatch; the same immutable package was then executed against the validation executable and passed **6/6**. No semantic contract was retried from a red result and no package content changed.

## 6. Complete required-green producer segment

The exact aggregate filter used one GoogleTest positive/negative separator and excluded exactly 15 separately classified tests: four direct products, eight historical/deferred reds, strict-validator timing, BunnyRandom, and Vase.

Native filtered discovery selected exactly:

`208 - 15 = 193`.

Aggregate result:

- selected **193**;
- passed **193/193**;
- rc=0;
- GoogleTest wall time **16.571 s**;
- wrapper wall time **16.57 s**;
- peak RSS **23,396 KiB**.

This aggregate includes all six M1i contracts and prevents focused-test-only acceptance.

## 7. Independent preservation targets

Exact packaged executables passed:

| Target | Result | Wall | Peak RSS |
|---|---:|---:|---:|
| validation | **77/77** | 0.01 s | 5,328 KiB |
| M1a authority kernel | **14/14** | 0.00 s | 4,100 KiB |
| T1 independent oracle | **29/29** | 0.00 s | 4,508 KiB |

## 8. Direct representative products

Each direct product ran individually from an arbitrary extraction with no runtime fixture symlink:

| Product | Result | Wall | Peak RSS |
|---|---|---:|---:|
| Plane | pass | **1.00 s** | **11,116 KiB** |
| MultiFaceSeam | pass | **1.58 s** | **11,140 KiB** |
| CloseSheets | pass | **12.53 s** | **13,608 KiB** |
| Cylinder | pass | **7.04 s** | **14,764 KiB** |

All four selected exactly one product test, reported product success, and retained independent-oracle authority. `fixtureSymlink=false` throughout.

## 9. Historical/deferred red classification

All eight entering historical/deferred reds ran individually and retained their prior classes:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red.
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`.
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`.
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`.
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`.
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`.
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red.
8. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — unchanged `InvalidHardRailPairing` under `NotProductionReady:tracing`.

No failure-class drift attributable to M1i occurred. Nonzero periodic whole-cycle rotation remains unresolved as `PeriodicHolonomyMismatch`; `G4-B003` remains open.

## 10. Strict-validator timing characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` ran in **10 fresh processes** with no retry-based greening.

Result: **0/10 pass, 10/10 fail**.

Observed `validationSeconds / remeshSeconds*0.05` pairs:

1. `0.000143633 / 0.0000997026`;
2. `0.000138205 / 0.0000959490`;
3. `0.000135922 / 0.0001050911`;
4. `0.000137104 / 0.0001045433`;
5. `0.000138476 / 0.0001013891`;
6. `0.000156883 / 0.0000940727`;
7. `0.000148261 / 0.00011671735`;
8. `0.000141590 / 0.0001050420`;
9. `0.000141010 / 0.0000988468`;
10. `0.000140760 / 0.0001059999` seconds.

This remains the existing deferred sub-millisecond ratio/microbenchmark defect. No threshold, retry policy, or product rule changed.

## 11. Bunny/Vase bounded immutable comparison

Because all earlier mandatory gates passed, heavy comparison ran from the exact immutable result artifact in temporary artifact-only GitHub Actions run `31416928654`. Both jobs downloaded artifact `9072101943` directly, verified its exact outer digest, **72/72** package checksums, cardinalities, source/test authority, producer hash, and `fixtureSymlink=false` before runtime and repeated exact postflight afterward. Neither job checked out source for execution, configured, built, relinked, regenerated, patched, repaired, or substituted package content.

### BunnyRandom

Job `93548045953` selected exactly one BunnyRandom test and returned expected rc=1 after **62.90 s**, peak RSS **341,076 KiB**.

The accepted known-red ordering and signature are unchanged:

1. independent oracle rejects first with `EmptyOutput`, `NonQuadOutput`, connected-component mismatch, Euler-characteristic mismatch, output-origin mismatch, and `TerminalFailureObserved:NotProductionReady:completion`;
2. the product-success assertion then reports `terminal=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

Evidence artifacts:

- `9073803244` — `m1i-heavy-bunny-evidence`, SHA-256 `d7da132936b3ea56d814bb5b8286236d133137bcb2f5a4147c390affa1334ab0`;
- `9073803836` — `m1i-heavy-bunny-logs`, SHA-256 `bcc3920f23920b841d16051ce58733a664856df8473c0202a2eab73413e2bf48`.

### Vase

Job `93548045879` selected exactly one Vase test, reached `[ RUN ]`, and was bounded at **60.00 s** with rc=124, peak RSS **71,012 KiB**.

This remains safety-only evidence. It is not correctness evidence and does not prove nontermination.

Evidence artifacts:

- `9073801150` — `m1i-heavy-vase-evidence`, SHA-256 `1eebc77ca8c326ef8a4ac315c31509f24f04c3fd6b00737a05452460f294dd86`;
- `9073801757` — `m1i-heavy-vase-logs`, SHA-256 `84f6977e0e00e4763baf15603a6ab2481f081538c8a0d93e6a26d878c9aba58e`.

The first two temporary heavy-workflow runs (`31416789700` and `31416802555`) failed before any job was created because a shell heredoc was not indented as valid YAML block content. They executed no package runtime and carry no product evidence. The corrected temporary workflow produced run `31416928654`; this is an orchestration-only lesson, not a product regression.

## 12. Exact postflight

Final local postflight independently reverified:

- result ZIP SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25`;
- log ZIP SHA-256 `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`;
- manifest SHA-256 `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`;
- all **72/72** manifest entries;
- exactly **73** regular files, **7** executables, **2** libraries, **27** fixtures;
- producer SHA-256 `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d`;
- zero symlinks and no `bin/test-data` repair.

The immutable runtime evidence is therefore valid.

## 13. Regression disposition

M1i introduces no new stable product regression event and no recurrence. Historical totals remain:

- **34** distinct regression events;
- **14** architectural categories;
- **20** recurrences.

`PR8-R034 / G4-R007` remains active. G4 remains unresolved and separate from M1i architecture acceptance.

## 14. Next bounded M1 consumer selection

Accepted-source inspection after runtime acceptance found the immediate next raw authority seam in `SurfaceFrontEdge`:

- `SurfacePhaseFrontCell` now owns typed component/sheet authority;
- `SurfaceFrontEdge` still stores `sourceComponent`, `sourceSheet`, and `sourceIsolationSheets` as raw integers;
- edge publication immediately downgrades the typed cell authority through `legacy_phase_front_source_*` helpers;
- later region aggregation overwrites/normalizes those raw edge fields;
- pipeline hashing/materialization then consumes the raw edge values.

This is the narrowest adjacent consumer and directly advances the normative strong-ID/single-writer rule without entering `TopologyRegionId`, periodic/bounded-disk owner migration, M2–M6, or G4 behavior repair.

The authoritative next turn is **M1j Phase-Front Edge Source-Scope Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`.
