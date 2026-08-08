# Gate 4 Field-Authoritative Polygonal Disk Boundary Phase — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The first-class field-authoritative polygonal bounded-disk boundary-phase slice is **compile-valid and packaged**. It has **not been runtime-validated in this turn**.

Exact candidate artifact **`9021175280`** (`g4-polygonal-boundary-phase-code-build`) is the only artifact authorized for the following Test + Benchmark turn.

The change replaces the former global “exactly four rectangular runs” gate with a source-attached transported boundary-phase representation. It preserves the existing four-run rectangle as the exact fast path. A non-rectangular valid phase is developed into an intrinsic orthogonal polygon and parameterized; because generalized polygon lattice clipping/front pairing is not yet implemented, a successfully constructed non-rectangular chart fails explicitly at the deeper typed `InvalidBoundedDiskFrontPairing` invariant rather than emitting partial cells, coercing runs, or falling through to generic tracing.

No generated Directional binary, test, benchmark, `ctest`, discovery command, CLI/GUI command, help/list/version command, or custom-input command executed.

## Entering runtime authority

Runtime authority remains artifact **`9019024467`** until artifact `9021175280` executes artifact-only.

That authority proves:

- source-sheet-boundary semantics **3/3**;
- combined source-sheet-boundary + curved-disk semantics **9/9**;
- sheet coverage **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- direct deterministic hashes: plane `730caeae49ec872c`, seam `5bdf34d7802e9fb0`, close sheets `89b052762f52a5af`, cylinder `32135be51d7a0a26`;
- no passing direct fallback/recovery;
- bounded suites producer **115/116**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **337/348**;
- exact torus deterministic 3/3 as `Rejected / InvalidBoundedDiskBoundaryPhase` at `tracing/phase-front`, with no invalid source face attached, periodic authority live, and no fallback/recovery.

Detailed entering runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Report.md`.

## Exact source authority

Implementation commit:

- **`085db9ec23ffaa509b1f5a29e72968229efa103d`** — `feat(surface-cells): model polygonal disk boundary phase`

Payload cleanup commit:

- **`c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`** — `chore(agent): remove G4 polygonal boundary payloads`

Workflow event commit:

- `c24af6c83ab25397df1c2bfc4692b91689502f85`

Raw unified-patch authority:

- SHA-256 **`d0ac2b1b59146a57dae61b7a89b487c07db33389421679608ba329b67a48cea0`**;
- six independently verified raw-text Git blobs:
  `5e699a88e7a859419bfb1ca806cb74d63b9770e5`,
  `ae237c7ec045682761e67d5f68d37dc5c7037af7`,
  `296afc8939f236a73b20b42f214099fd5a8f4053`,
  `31563eacd666cb0b9b5575543d977ba32fc54c03`,
  `72efae253869228691058f64f827c8ada09d256d`,
  `7dba7c3a41a81f8a7d0ccc17bd11a3a770994ab8`;
- concatenated patch digest verified before `git apply --check` and application;
- `git diff --check` passed;
- exactly six intended production/test/diagnostic paths changed.

Final packaged Git blobs independently verified from the packaged source archive:

| File | Git blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `9597c49693a1146e5dac2ac90270348b55a0c91d` |
| `include/directional/geometry/SurfaceCellTracing.h` | `0c1daa94300121df40c923716314ae6b242c7e8c` |
| `src/bench/DirectionalBenchmark.cpp` | `fd74cd39fff73bee7b4db578eb08382bd6ef50cf` |
| `src/geometry/SurfaceCellTracing.cpp` | `c834e8c81db04c39af9ecf1f45044ea107de3291` |
| `src/pipeline/RemeshPipeline.cpp` | `945bbc58bc56cb9838532889c616520cb234aaa3` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `981b0f6e6fc935c1bfe3d1f6871736035d6bdfcb` |

## Production contract implemented

### First-class boundary phase

`SurfaceBoundedDiskBoundaryPhase` now retains ordered source-attached boundary runs. Each run records transported branch/family/sign, canonical corner provenance, signed quarter-turn to the next run, cumulative/intrinsic length, exact source edge/face provenance, and edge authority (`sourceBoundary`, `hardFeature`, or non-hard `sourceSheet`).

The aggregate phase records component/sheet ownership, chart-U branch, cyclic signed quarter-turn sum, total intrinsic length, rectangular/polygon/chart state, a deterministic structural hash, and the ordered runs.

Two precise typed failures were added:

- `InvalidBoundedDiskBoundaryTurn` for an adjacent run transition that is not one reciprocal quarter-turn;
- `InvalidBoundedDiskBoundaryIndex` when the oriented cyclic quarter-turn sum is not the valid disk boundary index.

The existing per-edge field-alignment contract and threshold are unchanged.

### Canonical boundary construction

The ordered source boundary remains derived from source topology. Canonical run rotation uses source geometry rather than raw face/edge IDs, discovery order, counts, frequency, or proximity. Runs are not inserted, removed, split, merged, or length-adjusted to manufacture a desired side count.

Every run preserves exact source-boundary/hard-feature/source-sheet provenance. Existing source-sheet authority therefore remains part of the generalized boundary representation rather than being converted into hard features.

### Rectangular fast path retained

When the first-class phase has exactly four runs and every corner is a positive quarter-turn, the established rectangular path remains in force:

- opposite intrinsic side lengths are averaged exactly as before;
- source boundary vertices map monotonically to the same four rectangle sides;
- the same positive-weight interior solve and chart checks are used;
- downstream rectangular grid/front construction remains unchanged.

### Polygonal chart construction

For a non-rectangular valid phase, the producer develops the exact transported run sequence into an intrinsic orthogonal polygon:

- side direction comes from transported branch identity relative to chart-U;
- side length is exact accumulated source-boundary intrinsic length;
- no synthetic closing side or Euler correction is added;
- polygon closure is checked numerically without correcting geometry;
- oriented area/extents and non-adjacent self-intersection are validated;
- boundary source vertices map monotonically to exact side intervals;
- interior UV is solved with the existing deterministic positive-weight Laplacian;
- every source triangle must remain finite, nondegenerate, and orientation-consistent.

On successful polygonal chart construction, `chartConstructed=true`. The current slice then rejects as **`InvalidBoundedDiskFrontPairing`** before generalized lattice clipping/pairing. This is an explicit next invariant, not a relabeling of the old boundary-phase failure: the constructed boundary phase and chart are stored, hashed, and exported to diagnostics.

### Aggregation, hashing, and diagnostics

Whole-surface aggregation retains boundary-phase records even when the applicable local disk stops at a deeper typed invariant. Partial cells are not promoted to whole-surface authority.

Trace-network structural hashing consumes the first-class phase/run/chart/provenance representation when bounded-disk phases exist. The no-phase G0-G3 path is left untouched so their current direct hashes remain valid runtime baselines for the next turn.

New diagnostics expose:

- bounded-disk boundary-phase count;
- total boundary-run count;
- polygonal bounded-disk phase count;
- constructed bounded-disk chart count;
- deterministic phase hashes.

The benchmark JSON serializes these fields so the next artifact-only turn can prove the representation is constructed and consumed rather than infer progress from a changed failure name.

## Compile-only regression additions

The changed Phase 10 test source compiles behavioral coverage for:

1. `ExistingRectangularCurvedDiskRetainsExactBoundaryPhaseFastPath`;
2. `PolygonalCurvedDiskBuildsFieldAuthoritativeSixRunPhaseAndChart` — natural L-shaped orthogonal disk with a real reflex corner, expected to construct the phase/chart and stop at the deliberately deferred front-pairing invariant;
3. `PolygonalCurvedDiskInvalidCyclicFieldTurnFailsClosed`;
4. `PolygonalCurvedDiskBoundaryPhaseIsInvariantToFaceRowEnumeration`;
5. existing non-hard cross-sheet boundary coverage extended to require retained source-sheet boundary provenance;
6. existing hard-boundary coverage extended to require retained hard-feature provenance;
7. `PolygonalCurvedDiskRetainsPeriodicAuthorityWithoutPartialSheetCells` — planar + periodic annulus + polygonal disk composition keeps periodic authority while aggregate rejection exposes no partial cells;
8. exact committed torus advancement contract now forbids `InvalidBoundedDiskBoundaryPhase`, `InvalidBoundedDiskBoundaryTurn`, and `InvalidBoundedDiskBoundaryIndex`, and requires runtime-visible first-class boundary-phase evidence.

The L-shape's six runs and one reflex corner are independently defined by that synthetic fixture's geometric/field contract; production behavior contains no six-run, torus, face-ID, relation-count, feature-count, or boundary-length special case.

**None of these tests executed in this Code + Build turn.**

## Successful compile-only build

Workflow run/job:

- **`31254896323 / 93096734152`**;
- Ubuntu 24.04, Release/static, Ninja;
- GoogleTest discovery deferred with `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- GMP enabled;
- CLI/GUI/PARDISO/cuDSS/SuiteSparse disabled.

Seven approved targets compiled/linked successfully, **111/111** build actions:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

The build log terminates at `[111/111] Linking CXX executable directional_benchmarks` and `compile_only_gate=passed`.

## Immutable artifact authority

Main artifact:

- ID **`9021175280`**;
- name `g4-polygonal-boundary-phase-code-build`;
- GitHub/downloaded ZIP SHA-256 **`16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`**;
- internal `SHA256SUMS` SHA-256 **`a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`**;
- recursive checksums **48/48**;
- package **49 files**, **27 fixtures**, five executables, two project static libraries.

Dedicated log artifact:

- ID **`9021175444`**;
- name `g4-polygonal-boundary-phase-code-build-logs`;
- ZIP SHA-256 **`170c8d869af4ec737250a1a5ce7dfb532ca76fbef972a696cea85a53c61b0f67`**.

Artifact metadata records implementation `085db9ec...`, cleanup `c3b5dcbc...`, entering runtime artifact `9019024467`, raw patch digest `d0ac2b1b...`, review policy `never`, and **`runtimeExecution=false`**. `metadata/command-boundary.txt` explicitly records that no generated project runtime executed.

## Repository hygiene

After artifact, source, checksum, and log authority were verified:

- bounded workflow removal commit: `904c08652b167aac6bd34cfba77c771f2d7e0cc4`;
- trigger removal commit: `3d821f2942b9feeacaf169114305df68469686ed`;
- patch payloads were already removed by cleanup commit `c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`.

Final hygiene must be rechecked after documentation cleanup and before the mandatory PR closeout comment.

## Runtime authority remains unchanged until validation

This turn proves source synchronization, structural implementation, compilation, packaging, and artifact integrity only. It does **not** prove that the new polygonal tests pass, that the torus constructs a valid polygonal phase/chart, that it reaches `InvalidBoundedDiskFrontPairing`, that output materializes, or that G4 closes.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact **`9021175280`**.

The next turn must establish runtime evidence for the new first-class representation first, retain all current focused/direct authority, then run exact torus in at least three independent processes. If torus constructs and consumes a valid polygonal phase/chart and reaches the deliberately deeper `InvalidBoundedDiskFrontPairing`, the next Code + Build target is generalized polygonal lattice clipping/front pairing. If it fails earlier, follow the first truthful structural invariant shown by the new diagnostics; do not weaken the boundary contract or infer unreported state.
