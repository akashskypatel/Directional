# Gate 3 Periodic Output Validation — Code + Build Report

## Decision

**Code + Build complete; G3 remains active pending artifact runtime validation.**

This turn changed only production/test source, configured and compiled the approved seven-target closure with `PRE_TEST`, and packaged an immutable artifact. No generated Directional binary, test, benchmark, `ctest` discovery, CLI/GUI, help/list, or custom-mesh command was executed.

## Design declaration

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: a Produced periodic phase-front must materialize its cut-quotiented annular cells into a source-authoritative completed quad mesh that passes the existing pre-optimization validation without shortcutting canonical source-strip structure; row-order invariance must be compared in canonical source identity rather than DCEL edge numbering
Smallest general implementation change: preserve canonical annulus source-strip breakpoints in periodic lattice/materialization, choosing deterministic per-strip subdivisions nearest the target size so output sides do not bridge source topological corners, while retaining exact periodic holonomy quotient and one accepted cell -> one quad; separately correct the row-order contract test to compare ordered canonical source-edge endpoint keys instead of raw sourceEdge IDs
Observable material-progress condition: exact cylinder remains Produced with valid periodic authority and reaches zero completed-checkpoint validation failures/direct CompletedSurfaceCells output, while plane, seam, and close sheets remain strict-valid deterministic regressions; the row-order test passes by canonical endpoint identity without weakening its holonomy invariants
Explicitly deferred work: torus/general genus, singularity topology and G4 completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, scheduler timing, and unrelated historical completion/simplification failures
```

## Source authority

Exact production/test source commit:

- `2783ea718ffb15f8fb3868795173472ab8636c1c`

Verified source patch:

- SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`

Changed Git blobs:

- `src/geometry/SurfaceCellTracing.cpp` → `9df9a9759c761293fef1278f97b82fbb0aee0600`
- `tests/SurfaceCellsPhase10Tests.cpp` → `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`

No validator, fixture, benchmark, API, materializer, cross-field, fallback, or recovery source was changed.

## Implementation

### Canonical source-strip-conforming periodic lattice

The periodic annulus producer no longer chooses every periodic lattice column from one global `round(period / target)` spacing.

For each already-authoritative canonical source strip around the annulus it now:

1. keeps the source-ring strip boundary as a mandatory intrinsic `s` breakpoint;
2. derives the strip length from the transported canonical rings already used by the periodic chart;
3. samples the local target-size field from both strip endpoints on every canonical ring, with the validated global target only as the fallback for an unavailable vertex sample;
4. chooses a deterministic positive nearest-integer subdivision count from `stripLength / localTarget`;
5. rejects non-finite/overflowing subdivision state as `InvalidPeriodicChart`;
6. builds the periodic chart's lattice-column coordinates strip by strip, inserting the exact source-strip endpoint as the final coordinate of every strip;
7. sets `gridU` and periodic lattice translation to the sum of those strip-local subdivisions;
8. uses those nonuniform intrinsic periodic coordinates for chart points, authoritative cells, boundary paths, and cell validation.

This preserves the existing periodic quotient identity and one accepted phase-front cell → one output quad. It adds no post-hoc split/merge, Euclidean weld, nearest-point seam matching, source-grid recovery, or fixture/count special case.

The axial construction and genuine annulus boundary treatment were intentionally left unchanged.

### Row-enumeration contract correction

`SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` no longer compares raw DCEL edge integers from independently enumerated meshes. Each route/cut source-edge ID is mapped through that mesh's authoritative `EV` table to the ordered canonical endpoint key `(min(v0,v1), max(v0,v1))`; the ordered sequences are compared without sorting away route order.

Grid dimensions, holonomy rotation, lattice translation, and the existing periodic semantic assertions remain intact.

### Added structural regression source

`SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints` derives the source boundary vertices from authoritative boundary edges and requires all of them to occur as exact phase-front corners on the two genuine periodic-annulus boundaries. It does not encode the committed cylinder's ring count or expected output count.

This test was compiled, not executed.

## Compile-only build authority

Successful bounded GitHub Actions build:

- workflow run: `31204848178`
- job: `92953250176`
- build artifact: `9004509871` (`g3-periodic-output-validation-code-build`)
- build artifact SHA-256: `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`
- detailed log artifact: `9004508508` (`g3-periodic-output-validation-code-build-logs`)
- log artifact SHA-256: `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`
- recursive artifact checksums: **44/44 passed**
- compile/link actions: **111/111**
- approved targets: **7/7**
- packaged closure: five executables, two project libraries, 27 fixture/input files
- toolchain: GNU C++ 13.3.0, CMake 3.31.6, Ninja 1.13.2
- configuration: Release static, `PRE_TEST`
- packaged command boundary: `runtimeExecution=false`

The locally downloaded build and log archives match the GitHub artifact digests exactly.

## Runtime status

**No runtime acceptance is claimed by this turn.**

The latest executed authority is still artifact `9001168379`: cylinder was periodic `Produced` with `r=0`, `t=(29,0)`, 290 direct quads / 319 provenance vertices, deterministic 3/3, but terminated at `completion/output-validation:AggregateCompletionValidationFailure` with two aggregate validation failures. Plane, seam, and close sheets remained passed direct regressions.

The new strip-conforming subdivision deliberately allows periodic translation/grid cardinality to change from `29`; the following artifact test must validate the new value semantically rather than require the prior count.

## Workflow hygiene

After artifact/log/source verification, the bounded workflow, exact trigger marker, and source payload were removed. The branch must end the turn with only the approved durable workflow.

## Next turn

Run `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md` as **artifact-only Test + Benchmark** using exact artifact `9004509871`.

The first runtime question is whether the exact cylinder remains authoritative periodic `Produced` and now passes the existing completed-mesh validation directly. No rebuild or implementation/test/fixture/validator/build edit is permitted in that turn.
