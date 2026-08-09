# M1d Phase-Front Route Identity Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** Test + Benchmark only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Source/build mutation:** prohibited  
**Review policy:** `never`

## 1. Objective

Accept or reject the exact M1d build without configuring, rebuilding, relinking, regenerating, substituting, or editing product/test/fixture content.

M1d changes only semantic route identity consumption at:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

The immutable turn must prove that checked source-vertex/transition domains and canonical source-edge identity preserve existing HardRail/PeriodicCut behavior, fail closed on malformed route authority, and do not disturb M1c/M1b/M1a/T1 or direct product authority.

Focused success alone is insufficient.

## 2. Exact immutable authority

| Evidence | Required value |
|---|---|
| M1d entering base | `29f2e20a376c907581f119801768d393c19b9d1b` |
| M1d implementation | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Build/event commit | `98a21f3d843533dcc44cb296711268e0ebb26fb6` |
| Build run/job | `31342400614 / 93318225812` |
| Result artifact | `9046308272` |
| Result ZIP SHA-256 | `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c` |
| Log artifact | `9046308461` |
| Log ZIP SHA-256 | `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c` |
| Recursive manifest | **59/59**, `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0` |
| Package regular files | **60**, including manifest |
| Compile closure | Release/static/Ninja **120/120** |
| Build-turn runtime | **false** |

Expected executable SHA-256 values:

- producer: `0809eccc8625f588d077ab0598d47c9a75b051c58e8375af866a01ff9f2327b7`;
- validation: `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- authority kernel: `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- oracle: `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`.

## 3. Immutable preflight

Before executing any packaged binary:

1. download exact artifacts `9046308272` and `9046308461` from run `31342400614`;
2. verify both GitHub artifact digests exactly;
3. reject absolute, parent-escaping, or otherwise unsafe ZIP entries;
4. require `SHA256SUMS` SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
5. verify every **59/59** package checksum and exactly 60 regular package files;
6. verify seven ELF executables, two static libraries, and 27 packaged fixture files;
7. require `metadata/build-authority.json` to identify implementation `9446fc82...`, build event `98a21f3d...`, run `31342400614`, `runtimeExecution=false`, M1d/M1c/M1b counts 6/6/6, M1a 14, T1 29, previous producer discovery 172, expected discovery 178, and expected required-green segment 163;
8. verify source blobs and all selected executable content hashes;
9. require M1d source/test delta to remain exactly `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp`;
10. record original outer ZIP hashes for postflight.

If extraction strips executable bits, restore permission only after content-hash verification. Runtime fixture locators may be non-regular filesystem metadata only; packaged regular-file content must not change.

Any package/content mismatch is a hard stop and is infrastructure/evidence failure, not product pass/fail.

## 4. Prohibited operations

Do not:

- configure CMake;
- compile, link, or relink;
- regenerate discovery metadata, tests, fixtures, or source;
- patch, edit, substitute, or repair packaged regular files;
- copy in a different executable, library, or fixture;
- weaken assertions or convert required failures to expected success;
- count zero-test selection as success.

A failure during this turn is diagnosed and handed back to a later Code + Build turn; it is never repaired in-place.

## 5. Runtime sequence

### A. Producer discovery authority

Use only packaged `bin/directional_surface_cell_producer_tests` and execute native GoogleTest discovery once.

Require exactly **178 unique tests**.

The new suite `SurfaceCellPhaseFrontRouteAuthorityMigration` must contain exactly these six members and no extra member:

1. `ValidHardRailRouteUsesTypedIdentity`;
2. `ValidPeriodicCutRouteUsesTypedIdentity`;
3. `InvalidInteriorTransitionIdFailsClosed`;
4. `OutOfDomainPackedSourceVertexFailsClosed`;
5. `RouteTopologyTransitionMismatchFailsClosed`;
6. `DuplicateSemanticRouteTopologyFailsClosed`.

Reject missing, duplicate, extra, or zero-selection M1d authority.

### B. M1d focused semantic contracts

Run each of the six M1d contracts individually in a fresh process and require **6/6**. Record exact filter, selected count, return code, stdout/stderr, and elapsed time.

The contracts must prove observable relations:

- a real authoritative HardRail route remains materializable and its compact route IDs correspond to source-wide interior transition authority;
- a real authoritative PeriodicCut route remains materializable with valid relation ownership;
- negative and exact out-of-domain compact transition IDs fail closed;
- a packed source-edge endpoint at `sourceVertices.rows()` fails closed;
- substituting a different valid transition ID for a valid topology key fails closed;
- duplicate semantic source-edge topology fails closed even when parallel vector cardinality remains valid.

### C. Existing route counterexamples

Run and require green individually:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

These preserve real cross-region HardRail materialization, genuine-boundary rejection semantics, and independent output-incidence facts around the migrated consumer.

### D. M1c preservation

Require exact six-member discovery for `SurfaceCellFieldTransitionAuthorityMigration`, then run all six M1c contracts individually and require **6/6**.

Also run and require green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

M1d does not own quarter-turn transport; any M1c drift is a blocking regression.

### E. Complete producer accounting

The exact 178-test producer discovery must be fully accounted for without silently omitting red cases.

Expected classes:

| Class | Expected count |
|---|---:|
| required-green producer segment | **163** |
| direct required-green product cases | **4** |
| historical/deferred known-red tests | **9** |
| BunnyRandom | **1** |
| Vase | **1** |
| **Total** | **178** |

The required-green segment is the accepted M1c 157 plus the six new M1d contracts. Run the 163-member segment under an explicit process guard and require **163/163** with nonzero exact selection authority.

Keep the nine already-known/deferred producer tests explicit and individually classified; do not relabel them green or hide them from accounting:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`;
- `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize`;
- `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected`;
- `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner`;
- `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected`;
- `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected`;
- `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority`;
- `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`.

A changed failure mode attributable to M1d is material evidence; simple persistence of an already-open blocker is not a new recurrence.

### F. M1b preservation

Using the unchanged packaged validation executable:

1. discover exactly the six `SurfaceOptimizationRailAuthorityMigration` contracts;
2. run them individually and require **6/6**;
3. require full validation discovery exactly **77**;
4. execute full validation and require **77/77**.

### G. M1a authority preservation

Using `directional_surface_cell_authority_kernel_tests`:

- require discovery exactly **14** and exact static-manifest membership;
- run all authority contracts under the accepted procedure;
- require **14/14**.

### H. T1 independent-oracle preservation

Using `directional_surface_cell_oracle_tests`:

- require discovery exactly **29** and exact static-manifest membership;
- execute the accepted independent oracle suite;
- require **29/29**.

### I. Direct required-green product preservation

Repeat the accepted direct product procedure from the immutable producer executable for:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

Each must select exactly one intended existing test, return success, and remain independent-oracle clean. M1d has no authority to alter product disposition.

### J. Bunny/Vase standing comparison

Bunny and Vase are not green acceptance baselines.

Per standing user authorization, use an ephemeral artifact-only GitHub Actions runtime workflow if local execution limits make these cases impractical. Any such workflow must:

1. download exact artifact `9046308272` from build run `31342400614`;
2. verify the artifact digest, all 59 package checksums, implementation metadata, and producer executable hash before runtime;
3. never configure/build/relink/regenerate/substitute/edit packaged regular content;
4. restore executable mode only after content verification;
5. run the exact existing Bunny/Vase tests with explicit guards;
6. retain selected count, filter, stdout/stderr, return code, elapsed time, and evidence digests;
7. classify GoogleTest behavior from raw logs, not workflow success;
8. remove temporary workflow/trigger/helper files before closeout.

Accepted M1c comparison authority:

- Bunny: independent oracle rejects first, then unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`, rc=1 at ~63 s;
- Vase: exactly one real test reaches `[ RUN ]` and is bounded rc=124 at 60 s; safety-only.

Unexpected success, crash, changed terminal failure, lost independent-oracle ordering, or unbounded behavior is material evidence.

## 6. Postflight immutability

After runtime:

1. rehash both original downloaded ZIPs and require exact equality with GitHub/preflight digests;
2. reverify `SHA256SUMS` and every **59/59** package member;
3. reverify selected executable hashes and exactly 60 regular package files;
4. confirm no packaged regular-file content changed;
5. record permission-only restoration and non-regular runtime locators separately;
6. remove any temporary Actions workflow/trigger/helper files used for Bunny/Vase before closeout.

## 7. Acceptance criteria

M1d becomes immutable accepted only if all are true:

1. package/source/executable authority is exact before and after runtime;
2. producer discovery is exactly **178**;
3. M1d suite membership is exactly six and focused contracts are **6/6**;
4. all three existing route counterexamples remain green;
5. M1c remains exact six **6/6** and its three transition counterexamples remain green;
6. required-green producer segment is exactly **163/163**;
7. all nine historical/deferred red producer cases remain explicit and are individually classified;
8. M1b remains **6/6** and validation **77/77** with discovery 77;
9. M1a remains exact 14 and **14/14**;
10. T1 remains exact 29 and **29/29**;
11. Plane/MultiFaceSeam/CloseSheets/Cylinder remain green and independent-oracle clean;
12. Bunny/Vase remain explicitly evidence-classified without synthetic acceptance;
13. both artifact ZIP hashes and every **59/59** package checksum remain unchanged;
14. no product/test/build/fixture mutation occurred.

Only then may M1d be marked immutable accepted and another bounded M1 consumer be planned.

## 8. Failure policy

If any required-green gate regresses:

- remain at M1d;
- capture the exact relation, fixture, selected test, failure reason, and independent evidence;
- create or increment a stable regression only when previously accepted behavior was genuinely restored and then lost;
- produce a corrective **Code + Build** plan;
- do not advance to another M1 consumer, M2, or G4 remediation.

If package authority fails before runtime, stop without executing packaged binaries and classify the evidence/infrastructure failure separately.
