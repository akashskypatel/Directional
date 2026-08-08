# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1 and G2 are closed. Exact cylinder production runtime now satisfies the G3 periodic closure contract. Formal G3 closure is blocked only by artifact validation of the corrected subdivision-independent field-correspondence test witness.

Current runtime authority: artifact `9010838200`, source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

- cylinder `Produced / CompletedSurfaceCells`;
- valid field-authoritative ring correspondence and periodic holonomy/cut/quotient;
- 288 pure quads / 320 vertices;
- zero validation failures;
- field P95 approximately `8.54e-7°`;
- two genuine exterior annulus loops only;
- deterministic 3/3;
- no fallback/recovery;
- plane/seam/close sheets remain direct strict-valid passes.

## Proven producer foundation

Retain without redesign:

- first-class `NotApplicable / Produced / Rejected` authority;
- no generic substitution after `Rejected`;
- reciprocal source-edge/source-vertex transport and source-route provenance;
- component/local-sheet isolation;
- topology-derived annulus applicability and intrinsic cut;
- periodic holonomy `(Z4 rotation, Z2 translation, ordered source route)`;
- exact artificial-cut ownership/quotient;
- canonical source-strip breakpoints and per-strip subdivisions;
- reciprocal field-authoritative adjacent-ring correspondence with typed ambiguity rejection;
- canonical source-simplex chart endpoints;
- direct one-cell-to-one-quad materialization;
- strict source-authoritative validation.

## Remaining G3 correction — test witness only

The earlier `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` expectation required one V front edge whose endpoints were two exact source-ring vertices. The fixture target is 0.25 while source inter-ring spacing is 0.5, so a correct phase front subdivides that connection and the precondition is structurally absent.

Evidence commit `117620ec2da2083ce11b205835e58fa404f163ef` corrects the test without changing production source.

The replacement witness:

1. iterates source-attached `family == 1` boundary-path segments;
2. verifies source-face and finite normalized barycentric provenance;
3. reconstructs source-space endpoints from `(face, barycentric)`;
4. skips only genuine zero-length segments;
5. projects the segment and local V field family into the source tangent plane;
6. requires V-family alignment and nonempty observations;
7. is independent of target subdivision and incidental source identifiers/counts/order.

Production blobs remain exactly those of runtime-proven G3 source.

## Compile authority

- evidence source/test `117620ec2da2083ce11b205835e58fa404f163ef`;
- test-only patch SHA-256 `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`;
- artifact `9013161456`, SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- run/job `31228899303 / 93028533210`;
- log artifact `9013161584`, SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f`;
- 44/44 recursive checksums;
- 111/111 compile/link;
- five executables, two libraries, 27 fixtures;
- `runtimeExecution=false`.

## Required verification sequence

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9013161456`.

1. verify artifact/source/patch/blob/checksum/build boundary;
2. run corrected field witness first;
3. run all endpoint/ambiguity/G3 periodic/G1-G2 retained contracts — **17/17 required**;
4. revalidate plane/seam/close sheets;
5. revalidate exact cylinder direct strict-valid periodic closure;
6. if all pass, mark G3 closed and activate G4.

No rebuild or source/test/fixture/validator/build edit is allowed in that Test + Benchmark turn.

## Deferred work

Do not broaden this final G3 closeout into torus/general genus, G4 singularities/topology-distinct completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production/performance, scheduler timing, historical completion/simplification repair, validator changes or unrelated optimization.

## Acceptance discipline

No validator weakening, fixture special cases, count/order/frequency ownership selection, generic-producer substitution, fallback/recovery, positional sheet merging, Euclidean periodic seam welding, arbitrary subset search, synthetic topology correction, post-hoc cycle/cell merging, or timeout-as-correctness is allowed.
