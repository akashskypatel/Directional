# Milestone G P5 — Source-Support Ownership Remediation Plan

**Authority:** Next code changes + compile-only build turn  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Validated artifact:** `8840866875`  
**Validated compiled source:** `dcef9fbf65930b20db93128deb193f10702dc9c7`  
**Review policy:** `never`

## 1. Objective

Remove the deterministic `CompletionOwnershipSourceSupportEscape` blocker without weakening source ownership, boundary identity, duplicate-face validation, or fail-closed behavior.

The next artifact must allow valid source-edge and source-vertex chart aliases while continuing to reject a generated interior point or completion face that actually leaves its patch domain.

## 2. Verified entry evidence

- New ownership discriminator subset: 3/4 passed.
- `PatchDescriptorMilestoneE.*`: 14/15 passed.
- Phase 14–18 aggregate: 218/222 passed.
- Milestone G P23 + Phase 20: 52/52 passed.
- Random bunny failed identically twice with 21,297 attempted, 21,193 completed, and 104 failed descriptors.
- Failure: `CompletionOwnershipSourceSupportEscape`.
- Required unresolved endpoints: zero.
- All stage structural hashes were deterministic.
- Assembly was not reached, so the previous duplicate pair was not reclassified.

## 3. Non-negotiable rules

1. Do not disable completion-domain ownership validation.
2. Do not accept arbitrary adjacent faces by distance or position.
3. Do not broaden generated patch-interior support beyond the descriptor's authoritative source support.
4. Do not remove or deduplicate a final face.
5. Do not weaken `DuplicateStitchedQuad`, duplicate-domain, overlapping-boundary, or inconsistent-geometry checks.
6. Do not use source-grid recovery, legacy fallback, source-triangle pairing, or input-mesh fallback.
7. Do not special-case patch IDs, face IDs, the bunny fixture, or test names.
8. Preserve deterministic hashes and patch/source-row order invariance.

## 4. Work packages

### P5-CB13 — Intrinsic source-entity support

Create one reusable source-support resolver for `SurfacePoint` ownership:

- classify support by barycentric coordinates using a documented tolerance;
- face interior → `{point.face}`;
- source edge → all incident faces of the canonical source edge;
- source vertex → all incident faces of the canonical source vertex;
- invalid/ambiguous barycentrics → fail closed.

Use source topology, not position. Reuse or centralize the incident-face logic currently implemented by source-authoritative validation so completion, optimization, and final validation do not diverge.

For each completion vertex:

- boundary vertex: require authoritative boundary-node identity and nonempty intersection between intrinsic supported faces and `patch.sourceFaces`;
- generated interior vertex: require `GeneratedPatchInterior` identity and require its stored face to be inside the patch's allowed face set;
- enforce component/sheet compatibility when authoritative arrays are available;
- distinguish `BoundaryChartAliasAccepted` only in diagnostics, not as a relaxed identity.

### P5-CB14 — Typed source-support diagnostics

On rejection, serialize at least:

- source patch and operation-local vertex;
- boundary versus generated interior;
- completion backend and variant;
- stored provenance face and barycentric coordinates;
- canonical source entity kind and vertex/edge identity;
- candidate incident supported faces;
- descriptor source-face support;
- component and sheet;
- exact typed failure.

Do not collapse all failures into `CompletionOwnershipSourceSupportEscape` without provenance.

### P5-CB15 — Canonical unoriented conflict serialization

`same_unoriented_cycle()` classifies reversed cycles correctly, but corner diagnostics still use `stitchForward.sourceIndices` independently for each owner.

- Select a deterministic canonical representative across forward and reversed cycles, or align the second record to the first matched orientation.
- Serialize identity kinds, compact hashes, authoritative hashes, local vertices, and global vertices in that same matched order.
- Preserve an explicit orientation/reversal bit if needed for debugging.
- Ensure reversed equivalent cycles produce identical canonical identity arrays.

### P5-CB16 — Correct parity fixture construction

Repair `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` so it actually creates:

- a topology-valid arrangement before repair;
- exactly two authoritative odd cells;
- one real shared interior interface;
- a parity split that updates both incident cells conformingly;
- a completable repaired complex.

Prefer a directly constructed minimal `SurfaceCellComplex` with explicit valid twin/cell incidence when the arrangement builder cannot naturally produce the intended odd-cell topology. Do not set diagnostics manually or bypass incidence validation.

### P5-CB17 — Regression coverage

Add or strengthen tests for:

1. a boundary source-vertex point stored in an adjacent incident face chart;
2. a boundary source-edge point stored in the opposite incident face chart;
3. a face-interior point outside patch support that still fails closed;
4. a generated interior point outside patch support that still fails closed;
5. component/sheet mismatch at a shared source entity;
6. canonical conflict arrays under cyclic rotation and reversal;
7. valid periodic cylinder stitching, inconsistent shared geometry rejection, and patch-order invariance;
8. the topology-valid two-odd-cell parity fixture.

### P5-CB18 — Pipeline diagnostic propagation

Propagate `completionOwnershipRepairAttempts` and the first typed completion-ownership rejection through:

- `SurfaceCellContextProducts`;
- `RemeshDiagnostics`;
- structural hashing where semantically relevant;
- benchmark JSON.

The following validation turn must be able to report whether assembly repair was never reached, attempted, exhausted, or successful.

### P5-CB19 — Performance preservation

Retain the compact identity representation that reduced peak memory from 1.696 GB to 0.873 GB. Avoid rebuilding incident-face maps per patch or per vertex:

- construct source vertex/edge incidence once per completion invocation or shared context;
- use sorted compact face lists or stable indexed spans;
- avoid repeated variable-length copies in normal success paths;
- keep complete diagnostics lazy and materialize them only on failure.

## 5. Compile-only gate

The implementation turn must:

1. change only source-support ownership, conflict diagnostics, diagnostic propagation, relevant tests/fixtures, trackers, and artifact packaging;
2. configure a clean Release build;
3. compile `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
4. compile all modified regression sources;
5. run no tests, benchmarks, or custom mesh programs;
6. package exact source, binaries, libraries, logs, source commit/status, submodule status, and checksums;
7. keep P5 open and PR #8 draft/unmerged.

## 6. Following test-and-benchmark turn

Use the resulting artifact without rebuilding and run:

- source-support and canonical-diagnostic regressions;
- `PatchDescriptorMilestoneE.*`;
- Phase 14–18 aggregate;
- Milestone G P23 + Phase 20;
- random bunny at least twice with fallback `Fail` and recovery disabled;
- same-machine performance comparison with artifacts `8838467442`, `8840174777`, and `8840866875`.

P5 may close only after direct assembly succeeds without recovery/fallback and the final mesh passes production topology, provenance, source projection, field alignment, determinism, and quality gates.
