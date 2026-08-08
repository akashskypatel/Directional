# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [production runtime closure satisfied; formal closure pending corrected witness artifact validation]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Production G3 runtime closure already demonstrated

Artifact `9010838200`, source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`:

- exact cylinder `Produced / CompletedSurfaceCells`;
- holonomy `r=0`, `t=(32,0)`, route 32, cut 4;
- 288 pure quads / 320 vertices;
- zero strict/completed validation failures;
- field P95 approximately `8.54e-7°`;
- two genuine annulus boundary loops; artificial cut not exterior;
- deterministic output hash `32135be51d7a0a26` 3/3;
- no fallback/recovery;
- plane/seam/close sheets retain passed direct output.

Focused/retained contracts were **16/17**. The sole failure was an invalid subdivision-dependent test witness, not a production runtime failure.

## G3 field-correspondence witness Code + Build complete

Test-only evidence commit:

- `117620ec2da2083ce11b205835e58fa404f163ef`;
- patch SHA-256 `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`;
- changed test blob `80a0b58339102279ab863d9112e243a557cd270d`.

Production blobs are unchanged from the runtime-proven source:

- tracing source `63e5ee427f675077f710db51ffb56d91838d3519`;
- tracing header `c1b816a584d67a3f74c2d7389962bd92d52244c9`.

The corrected witness observes nonzero source-attached V-family boundary-path segments rather than requiring one whole source inter-ring edge to survive target subdivision. It reconstructs source points from face+barycentric provenance, validates finite normalized simplex coordinates, projects the segment and local V field into the source tangent plane, requires axial V-family alignment, and retains a nonempty witness requirement.

No validator, fixture, production, ambiguity, endpoint, periodic, or passed-gate logic changed.

## Compile authority

- run/job `31228899303 / 93028533210`;
- artifact `9013161456`, SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- log artifact `9013161584`, SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f`;
- recursive checksums **44/44**;
- compile/link **111/111**;
- seven approved targets;
- five executables, two libraries, 27 fixture/input files;
- `runtimeExecution=false`.

Three preceding bounded remote attempts failed only in temporary workflow/build-evidence setup and executed no generated Directional binary. The successful run is the only build artifact authority for this turn.

## Required next turn

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9013161456`.

Required decision:

1. verify exact artifact/source/patch/blob/checksum/command-boundary authority;
2. run the corrected field witness first;
3. run all endpoint/ambiguity/G3 periodic/G1-G2 retained contracts — target **17/17**;
4. revalidate plane, seam, close sheets and exact cylinder;
5. require direct deterministic cylinder `Produced / CompletedSurfaceCells`, zero validation failures, valid periodic authority and existing quality thresholds, with no fallback/recovery;
6. if all hold, formally mark **G3 passed** and activate **G4 topology-distinct completion and singularities**.

Historical output cardinalities are evidence, not fixture constants. Test-only source is nevertheless expected to preserve the prior runtime state exactly or semantically equivalently.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
