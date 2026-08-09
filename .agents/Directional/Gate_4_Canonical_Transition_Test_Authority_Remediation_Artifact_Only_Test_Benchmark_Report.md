# Gate 4 Canonical Transition Test Authority Remediation — Artifact-Only Test + Benchmark Report

Status: **completed; G4 blocked with material progress**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Date: **2026-08-09 UTC**  
Review policy: `never`

## Outcome

Canonical transition test authority is accepted. All seven corrected focused contracts pass individually, including both alternate numeric-domain rejections, face-row-invariant periodic authority, malformed-holonomy typed rejection, incidence-derived topology, and retain-if-and-only-if-requested failure context.

The prior direct successes remain strict-valid in three fresh processes each. Exact torus remains deterministic **0/3**, but it now consumes all four topology regions, eight internal isolation seams, and four periodic relations and materializes the required one-component, zero-boundary, Euler-zero quotient before final validation rejects 74 faces as `LocalSheetMismatch`. This is the earliest production blocker. Sphere was correctly not run.

No source, test, fixture, manifest, validator, CMake, workflow, or benchmark acceptance changed. No configure, compile, rebuild, relink, or discovery regeneration occurred.

## Immutable artifact authority

| Authority | Value |
|---|---|
| Implementation | `de5261c7185aef71807b0b4140c8f023a44874fd` |
| Build/event commit | `5bf9b0efc665e0a940aa4e74b168171651685f7d` |
| Workflow run/job | [`31284957305 / 93172020467`](https://github.com/akashskypatel/Directional/actions/runs/31284957305) |
| Runtime artifact | [`9029584083`](https://github.com/akashskypatel/Directional/actions/runs/31284957305/artifacts/9029584083) |
| Artifact outer SHA-256 | `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad` |
| Recursive manifest | **49/49**, digest `ee65be615bcf59516f5c0e05f98e56b7d9095d48d41cb1675cb5e3938ad7ce26` |
| Log artifact / SHA-256 | `9029584200` / `b2c147a691caaafc6591106ebb59f50f2956c17722f88bff1857c94d33f3da9b` |
| Test patch SHA-256 | `96e96f3a2bb4492f208600359aefec59c70a0a138b0ccfcf0dca03e40b5650ef` |
| Source archive SHA-256 | `b3d1848ac9710044104e4be5382f2d1af3adf00314ed7b22a566aead8469d376` |
| Artifact retention | through `2026-08-23 UTC` |

Preflight independently verified both outer archives, safe paths, all 49 recursive members, five ELF executables, two static libraries, all 27 fixtures, the two-test patch, the exact source closure, toolchain, submodules, `113/113` compile completion, seven zero build-step exits, and `runtimeExecution=false`.

The six recorded source/CMake blobs remained exact:

- `tests/SurfaceCellTransitionQuotientTests.cpp`: `42111d1de51baa6cca85171aeab339813cae3b50`;
- `tests/SurfaceCellsPhase10Tests.cpp`: `552a3d98ec8f9280b960fb9bbff9a1c7596a0778`;
- `include/directional/geometry/SurfaceCellTracing.h`: `b87e37676a980162e7ef3ac1fa9d954ce2199ad2`;
- `src/geometry/SurfaceCellTracing.cpp`: `4809e66bb6e797001ffc22b3f2da6d3613cfdef0`;
- `src/pipeline/RemeshPipeline.cpp`: `0a55429fc83d429ae2176ce3bbaac573682c48eb`;
- `cmake/DirectionalTests.cmake`: `e82e3088e11f215f030b58be7fb6531a5dbaa99a`.

## Runtime boundary and command record

Every packaged command ran from the isolated artifact's `bin` directory with `LC_ALL=C` and `TZ=UTC`. GoogleTest discovery used each executable's native `--gtest_list_tests` once. Focused execution used one fresh process per exact test. Retained groups used the exact filters named below. The bounded suites used the plan's literal commands. The direct matrix used, once per fresh process:

```bash
./directional_benchmarks \
  --manifest test-data/benchmarks/fixtures/milestone_g_manifest.json \
  --case <case> --warmup 0 --runs 1 \
  --disable-surface-cell-source-grid-recovery
```

An external evidence wrapper initially attempted to invoke absent `/usr/bin/time`; that discovery record exited 127 before the producer binary was invoked. The wrapper was corrected to Bash `time`, after which the producer discovery command ran exactly once. This is an environment-harness failure only and is not test evidence.

The exact commands, working directory, environment, timestamps, exit status, stdout, stderr, timing, result JSON, and per-record checksums are preserved in a 294-file evidence ledger. The ledger file SHA-256 is `22f9fc15ce0f4fdff147ba9fefe3354de344b4bc138b7272135e9415e3894cc0`, and all 294 entries verify.

## Discovery

| Executable | Suites | Tests | Exit |
|---|---:|---:|---:|
| `directional_surface_cell_producer_tests` | 11 | 166 | 0 |
| `directional_surface_cell_completion_tests` | 4 | 164 | 0 |
| `directional_surface_cell_validation_tests` | 5 | 60 | 0 |
| `directional_compiled_api_tests` | 1 | 8 | 0 |

All seven required focused names were present. `directional_benchmarks` is the repository manifest runner, so no Google Benchmark discovery flag was used.

## Focused acceptance

All **7/7** passed, one process each:

1. `SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
2. `SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
3. `SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
7. `SurfaceCellTransitionQuotient.DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

The new deterministic two-region witness therefore reaches a real serialized route. Source-wide compact, region-local compact, and full-`EF` meanings are pairwise distinct; both substitutions reach `InvalidAuthoritativeTransitionSourceEdge`; periodic cut/holonomy remains row-invariant; malformed holonomy reaches exact `Rejected / PeriodicHolonomyMismatch`; and failure retention remains present iff requested.

## Retained groups

These filters overlap and are reported independently, not added together:

| Group | Result | Remaining failure |
|---|---:|---|
| Transition quotient | **29/36** | seven deferred production contracts |
| Topology / isolation / hard rail | **10/10** | none |
| Polygonal / curved / mixed | **12/12** | none |
| Periodic / torus / cylinder | **6/7** | exact committed torus hard-rail acceptance |
| Remaining non-overlap Phase10 | **38/39** | strict-validator timing |
| Direct G0-G3 GoogleTests | **4/4** | none |

The seven transition-quotient failures remain:

- `MultiIsolationMaterializationRetainsAllLocalSheets`;
- `FullPeriodicRotationAndTranslationMaterialize`;
- `TamperedFullPeriodicTransformIsRejected`;
- `MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner`;
- `SwappedPeriodicRelationOwnersAreRejected`;
- `MissingPeriodicRelationOwnerIsRejected`;
- `QuotientLineageRetainsScalarPointAndCompleteSortedAuthority`.

## Bounded suites

The plan's literal producer filter was:

```bash
./directional_surface_cell_producer_tests --gtest_filter='-*BunnyRandom*:*Vase*'
```

It excludes three of the 166 discovered producer tests, not two: the two long parameterized cases plus `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`. The exact current result is therefore **154/163**, with the seven transition-quotient failures above plus:

- `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`.

| Suite | Result | Exit |
|---|---:|---:|
| Producer, literal plan filter | **154/163** | 1 |
| Completion / simplification | **154/164** | 1 |
| Validation | **60/60** | 0 |
| Compiled API | **8/8** | 0 |
| Literal aggregate | **376/395** | — |

The historical completion/simplification ten are unchanged. Validation and API remain fully green. The prior stated producer **150/164** and aggregate **372/396** used a different exclusion denominator, so they are not an exact denominator-matched comparison.

One additional, non-authoritative diagnostic selected 164 producer tests by excluding only the two long parameterized fixtures. It passed the mandatory fixture-integrity case but exited during `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` without a GoogleTest summary or stderr, despite that test passing individually and within the authoritative 163-test process. No success total is inferred from that incomplete process; it is preserved only as a suite-order/process-isolation diagnostic.

`StrictValidatorOverheadStaysBelowFivePercent` remains a scheduler-sensitive, non-semantic timing failure. This run observed approximately 0.00017 seconds validation time against an approximately 0.000105-second five-percent bound. It does not override semantic authority.

## Ordered direct fixture matrix

Each row represents three fresh processes with fallback policy `Fail`, source-grid recovery disabled, requested/executed producer `SurfaceCells`, and no fallback, legacy, input, or recovery substitution.

| Case | Result | Output / topology | Stable digests | Wall seconds | Peak owned bytes |
|---|---:|---|---|---|---:|
| Plane | **3/3** | 81 V, 64 Q, one component, 32 boundary edges, `1/0/0` consumed/materialized as one component, one loop, Euler 1 | structural `b243fb3f5f3a3bc4`; semantic `922456fe29a63ba1` | 0.494619–0.529711 | 672460 |
| Multi-face seam | **3/3** | 81 V, 64 Q, one component, 32 boundary edges | structural `48661113839528d4`; semantic `99c8be7159d05c2f` | 0.751354–0.762664 | 548900 |
| Close sheets | **3/3** | 242 V, 200 Q, two components, 80 boundary edges; materialized two components, two loops, Euler 2 | structural `f01bcf687285ee72`; semantic `f40e1aa5f2eb3f92` | 4.200096–4.355255 | 2104888 |
| Cylinder | **3/3** | 320 V, 288 Q, one component, 64 boundary edges; one periodic relation consumed; materialized one component, two loops, Euler 0 | structural `81b3763254afc476`; semantic `98da73e60a564998` | 4.045100–4.090602 | 3217244 |
| Torus | **0/3** | 192 quads materialized; one component, zero loops, Euler 0; `4/8/4` authority consumed | deterministic `LocalSheetMismatch`, 74 issues | 0.513415–0.541948 | 2355172 |

All four successful cases are strict-valid pure quads with complete lineage and deterministic hashes. The seam semantic digest remains `99c8be7159d05c2f` for same-artifact evidence.

The torus runner process exits zero because it records a completed benchmark result, but each result JSON has `success=false`. Producer disposition is `Produced`; the pipeline then returns `NotProductionReady / completion` at `completion/output-validation / LocalSheetMismatch`, first face 0, with 74 validation issues. It has already consumed all `4/8/4` region/seam/relation authority and computed the required `1/0/0` output topology. All three observations are identical apart from timing. Sphere was not run because torus did not reach strict-valid final output.

## Earliest failure diagnosis

`build_authoritative_phase_front_mesh` correctly forms quotient classes and retains, for each output vertex, the complete sorted `PureQuadVertexLineage.sourceCharts`, `sourceTopologyRegions`, `sourceIsolationSheets`, and `HardRail` equivalence provenance. It also selects one deterministic exact `SurfacePoint` as the vertex's scalar positional representative.

The validation path loses the multi-chart part of that authority. `SurfaceOptimizationConstraints` and `SourceAuthoritativeMeshValidatorOptions` currently carry only scalar `vertexProvenance` for this output; `outputQuadSourceFaces` is not populated by the authoritative phase-front path. `SourcePointLabelSupport::compatible_chart_faces` therefore evaluates a quad only through the four scalar representatives. Hard-feature edges intentionally split source chart components. At a legitimately stitched hard-rail vertex, the retained lineage contains exact charts on both producer regions, but the scalar representative necessarily names only one side. A quad on the other side is rejected as `LocalSheetMismatch` even though its full quotient lineage authorizes that chart.

This is an authority-projection defect between quotient materialization and final validation. It is not permission to relax local-sheet validation or globally join charts across hard features.

The required invariant is:

- select a unique exact source chart for each output quad from the intersection of its four vertices' retained chart authority;
- when a corner uses a chart other than its scalar representative, require both exact chart membership and exact `HardRail` equivalence provenance connecting that support;
- preserve scalar provenance position, source-component, source-sheet, and barycentric checks;
- fail closed on missing, tampered, ambiguous, or nonreciprocal chart/equivalence authority;
- never infer compatibility from proximity, count, row order, fixture identity, a global hard-feature union, or topology-region membership alone.

## Postflight

After all runtime commands:

- both original outer ZIP digests remained exact;
- all original **49/49** manifest entries reverified;
- all six source/CMake Git blobs remained exact;
- the extracted package added only ten expected benchmark regular files under `bin/benchmark-results`—eight successful `.obj`/`.bmp` outputs, torus's failure `.bmp`, and `baseline.json`—plus the documented external symlink `bin/test-data -> ../test-data`;
- no packaged regular file was altered.

## Decision and next authority

This turn makes material progress: five previously blocked canonical/periodic authority tests now reach and pass their intended contracts, all seven focused tests pass, the prior-green direct matrix is retained, and the earliest torus defect is reduced to one explicit authority projection.

G4 remains active. Review policy is `never`, so no Review turn is inserted. The authoritative next turn is **Code + Build only** under:

`.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Code_Build_Plan.md`

That turn may implement only the exact lineage-to-face-chart validation authority described above and compile approved targets. It may not run any generated project binary. Nonzero periodic `Z4` rotation, target-size-dependent hard-rail scheduling, the positive multi-isolation lineage witness, historical completion/timing failures, sphere, G5/G6, fallback/recovery, and optimization remain deferred.
