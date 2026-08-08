# Gate 4 Source Topology Region / Isolation Sheet Decoupling — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The source-topology-region / local-isolation-sheet decoupling slice is **compile-valid and packaged**. It has **not** been runtime-validated in this turn.

Exact candidate artifact **`9022061741`** (`g4-topology-region-code-build`) is the only artifact authorized for the following Test + Benchmark turn.

The implementation separates exact source-topological producer ownership from geometric close/opposing-sheet isolation labels. Producer topology now derives regions through exact source-face adjacency and stops only at genuine source boundaries, hard features, or embedded relief barriers. A non-hard edge whose incident faces carry different local isolation labels remains internal producer topology when exact source adjacency proves continuity; reciprocal transition authority is still required to transport phase state across that seam. Local isolation labels remain first-class for proximity/capture/projection provenance.

No generated Directional binary, test, benchmark, `ctest`, discovery command, CLI/GUI command, help/list/version command, or custom-input command executed.

## Entering runtime authority

Runtime authority remains exact artifact **`9021175280`** until the new candidate executes artifact-only.

That runtime proves:

- generalized polygonal boundary-phase semantics **5/5**;
- local isolation/source-sheet semantics **3/3** under the preceding representation;
- retained non-torus curved-disk semantics **5/5**;
- sheet coverage **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- direct deterministic hashes: plane `730caeae49ec872c`, seam `5bdf34d7802e9fb0`, close sheets `89b052762f52a5af`, cylinder `32135be51d7a0a26`;
- no passing direct fallback/recovery;
- bounded suites producer **119/121**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **341/353**;
- exact torus deterministic 3/3 as `Rejected / InvalidBoundedDiskBoundaryTurn`, with zero retained bounded-disk phase/run/polygon/chart state.

Detailed entering runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`.

## Exact source and build authority

Workflow event commit:

- **`806a557c39170d12b172ef6930794711e00e63bc`** — bounded compile trigger.

Implementation commit:

- **`3ca89ab55efff461b050fb12033174be70e7464f`** — `feat(surface-cells): decouple topology regions from isolation sheets`.

Payload cleanup commit:

- **`b188dd37f01181ece2173879fc7e0accf23d1bad`** — `chore(agent): remove G4 topology-region payloads`.

Raw patch authority:

- concatenated SHA-256 **`1c3488b672e25c698451df46081fa951d8c4d883136ff30f88cece0dcadd194b`**;
- six independently verified Git blobs:
  `7b448ca4c1a72057744a6ab1f484103a5d4ce4b8`,
  `edc1a76d23e885d22dce0578619b768377def86b`,
  `501245894bd1be62aaf0c428b8c51e860e761e14`,
  `b6bc2a144756818c527e79de5c8e7f6d07990643`,
  `ace1166cdbfc786c33252aebb05f5ca8b2d48d83`,
  `8b2b2fb714416c0e78045ae37231534cd766db42`;
- every part's Git blob and SHA-256 was verified before concatenation;
- `git apply --check` and `git diff --check` passed;
- exactly six intended source/test/diagnostic paths changed.

Final packaged Git blobs:

| File | Git blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `ba33d8396bd26f8190f8d552aafd9c950e9a3842` |
| `include/directional/geometry/SurfaceCellTracing.h` | `e966a9ab9dc33f23de9cecb3fd9b61ddd75fde7f` |
| `src/bench/DirectionalBenchmark.cpp` | `ba3eb47bfe9f3f78ce1dcbab32bfb3a773658cfc` |
| `src/geometry/SurfaceCellTracing.cpp` | `b3f0ea3b82cf64f3a2ba312f9622172c64bc3e83` |
| `src/pipeline/RemeshPipeline.cpp` | `97a20e41338b616d6bb5cafaa5f3d3851c52c583` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `441ba7fe2066355ce2a2239380f45029ea139346` |

Dependency authority:

- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope `59da72df6517cab8379865899bdffdbc96171301`.

## Production contract implemented

### First-class topology regions

`SurfaceTopologyRegion` now records:

- deterministic region ID within canonical source-topology ordering;
- source component;
- exact source faces;
- Euler characteristic;
- genuine producer-boundary loop count;
- exact boundary-edge topology;
- exact internal isolation-seam topology;
- the set of local isolation labels contained by the region;
- a structural region hash.

`build_source_topology_regions` traverses only exact source-face adjacency. It does not use Euclidean proximity, nearest projection, counts, frequency, source IDs as ownership authority, arbitrary subset selection, or fixture recognition. Hard features and embedded relief barriers stop region adjacency. Local isolation-label disagreement does not.

### Internal isolation seams remain exact-source transport

A non-hard exact shared source edge is classified as an internal isolation seam only when:

- both incident faces are in the same topology region and source component;
- their local isolation labels differ;
- the edge is neither hard nor an embedded relief barrier.

Phase/branch transport across such a seam remains dependent on exact source routing and reciprocal transition metadata. Invalid or nonreciprocal seam transport receives typed `InvalidTopologyRegionTransport`; it is not normalized or bypassed.

The former bounded-disk boundary predicate no longer promotes local isolation-label disagreement to physical producer boundary authority. Genuine source boundary, hard-feature, and embedded-relief boundary authority remain intact.

### Producer ownership and coverage

Whole-surface authoritative producer selection now runs by topology region rather than local isolation label:

1. planar producer;
2. periodic annulus producer;
3. curved bounded-disk producer.

Topology, applicability, Euler characteristic, and boundary-loop classification therefore operate on the exact source-topological region. Local isolation labels remain attached to cells/fronts/relations/phases as provenance. Exact-once aggregation requires one authoritative result per topology region and complete isolation-label coverage within that region; partial region output remains fail-closed.

Periodic relation identity now has topology-region scope. Existing legacy single-sheet state remains supported when no region scope is present. Relation shape and incompatibility checks remain source/route/lattice based.

### Hashing and diagnostics

The trace network now owns and hashes topology-region state, internal isolation seams, region-scoped phase/front/cell state, and local isolation provenance.

Runtime diagnostics expose:

- topology-region count;
- internal isolation-seam count;
- region structural hashes;
- per-region Euler characteristics;
- per-region genuine boundary-loop counts;
- per-region isolation-sheet cardinality.

Benchmark JSON serializes these fields. They exist to prove that the architecture is constructed and consumed; they are not allowed as production branching keys.

## Compile-only regression additions and corrections

The Phase 10 test target compiles structural coverage for:

1. `ExactAdjacentCrossSheetEdgeIsInternalTopologyRegionIsolationSeam`;
2. `SameSheetInternalEdgeIsNeitherBoundaryNorIsolationSeam`;
3. `TopologyRegionIsolationSeamIsInvariantToFaceRowEnumeration`;
4. `ClassifierSplitAnnulusRemainsOneSourceTopologyRegion`;
5. `ClassifierSplitAnnulusTopologyRegionIsRowOrderInvariant`;
6. `HardFeatureCannotBeReinterpretedAsInternalIsolationSeam`;
7. `SourceDisconnectedCloseSheetsRemainSeparateTopologyRegions`;
8. `ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`;
9. `NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
10. strengthened exact torus contract `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`.

The prior cross-sheet regression was corrected rather than weakened: a non-hard exact-adjacent cross-sheet edge is now asserted as an **internal isolation seam**, not an exterior bounded-disk rail. The same-sheet arbitrary-cut negative control remains invalid. Existing polygonal-boundary focused tests remain compiled unchanged.

**None of these tests executed in this Code + Build turn.**

## Successful compile-only build

Workflow run/job:

- **`31258107220 / 93104542559`**;
- Ubuntu 24.04;
- CMake 3.31.6;
- GCC 13.3.0;
- Ninja 1.13.2;
- Release/static build;
- GoogleTest discovery `PRE_TEST`;
- GMP enabled; CLI/GUI/PARDISO/cuDSS/SuiteSparse disabled.

Seven approved targets compiled and linked successfully in **111/111** actions:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

The build log ends at `[111/111] Linking CXX executable directional_benchmarks` followed by `compile_only_gate=passed`.

## Immutable artifact authority

Main artifact:

- ID **`9022061741`**;
- name `g4-topology-region-code-build`;
- outer ZIP SHA-256 **`df23a89f26d0769fa3433bf8996d2d090eaa82770ddc52a52018e51286087306`**;
- internal `SHA256SUMS` SHA-256 **`d80559fab82a359f7ce5ccfe109069765d18f5d440824106d84d70c5b8822703`**;
- recursive checksums **48/48**;
- package **49 files / 27 fixtures / five executables / two project static libraries**.

Dedicated log artifact:

- ID **`9022061947`**;
- name `g4-topology-region-code-build-logs`;
- ZIP SHA-256 **`8a7c5271791a1e8182d4ff2b0d5d32ebfe6e47f6e36661ba5b431f00f898256d`**.

Artifact metadata records the event, implementation and cleanup commits, entering runtime artifact `9021175280`, six raw-patch Git blobs, decoded patch digest, review policy `never`, and **`runtimeExecution=false`**. `metadata/command-boundary.txt` explicitly records that no generated Directional runtime executed.

## Repository hygiene

After artifact, source, checksum and log authority were independently verified:

- bounded workflow removal commit **`02677344b413ce8b17f7d5174b94f1e4e3491657`**;
- trigger removal commit **`a763d784ae67a0db39cd0e7b7ec9dc1a552b5ed3`**;
- six raw payload files were already removed by cleanup commit `b188dd37f01181ece2173879fc7e0accf23d1bad`.

Final hygiene must be rechecked after documentation cleanup and before the mandatory PR closeout comment.

## Runtime authority remains unchanged until validation

This turn proves source synchronization, architectural implementation, compilation, packaging, and immutable artifact integrity only. It does **not** prove the new topology-region tests pass, that torus advances, that direct hashes remain unchanged, or that G4 closes.

The no-progress rule remains pending runtime evidence. The preceding artifact-only turn recorded one Code + Build without material runtime progress. If validation of artifact `9022061741` also fails to establish material progress, no further ordinary Code + Build iteration is allowed until the mandatory design-review or bounded producer-replacement requirement is satisfied.

## Next turn

Execute `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact **`9022061741`**.

The next turn must establish the new topology-region/isolation-seam semantics first, retain polygonal/isolation/periodic/G0-G3 authority, rerun direct deterministic baselines, and classify exact torus in at least three independent processes. Material progress requires runtime-visible topology-region authority and proof that torus no longer fails because a non-hard classifier seam is interpreted as a bounded-disk exterior turn. A genuinely deeper invariant is acceptable only if the new architecture is proven constructed and consumed.
