# Gate 1 Live Transition Path — Artifact-Only Test + Benchmark Report

## Result

Gate 1 did **not** materially advance. The second bounded Code + Build artifact was valid and deterministic, and all new source-vertex contract tests passed, but the production plane remained on the exact prior generic path: **106 traces / 9 arrangement cells / 12 completion candidates / 15 validation failures / no output**.

The mandatory no-progress stop rule is therefore active. The next turn is a producer-architecture design review or bounded producer replacement proof; a third local predicate-repair turn is not authorized.

## Exact authority

- source commit: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- payload cleanup: `591ada601843237a709d2d6e133a438ca403f042`;
- artifact: `directional-g1-live-transition-local-build-artifact.zip`;
- artifact SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- internal checksums: **45/45**;
- five executables, two project static libraries, 27 fixture/input files;
- changed source blobs: **4/4 exact**;
- evidence archive: `directional-g1-live-transition-artifact-only-test-evidence.zip`;
- evidence SHA-256: `99a4922767d567830f202b440504f2b48d07fdb02bb117668baf846e7eeb9b64`;
- evidence files covered by checksums: **118**;
- rebuild/configure/relink performed during this test turn: **no**;
- source/test/fixture/manifest/validator edit during this turn: **no**.

A runtime-only `bin/test-data -> ../test-data` symlink was used because the immutable package stores fixtures beside `bin` while the compiled fixture resolver expects `bin/test-data`. No packaged byte was modified.

## Explicit contract and fixture guards

All four explicit prerequisite tests passed:

1. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
2. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`;
3. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`;
4. `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`.

The isolated vertex-fan algorithm therefore works on its contract fixture, and duplicate transition metadata remains fail-closed. Bunny and vase retain their exact production topology guards.

## Mandatory direct acceptance

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | **fail** | 106 | 9 | 12 | 0 |
| Multi-face seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

Direct acceptance remains **1/6**.

### Plane

The plane remained:

- `NotProductionReady:completion`;
- output origin `None`;
- fallback policy `Fail` with no fallback attempt;
- recovery disabled and unused;
- 106 trace segments;
- 9 arrangement cells;
- 12 completion candidates;
- 15 validation failures;
- final first-invalid producer record `completion/output-validation:AggregateCompletionValidationFailure`.

The tracing structural hash changed to `18291124109639474708`, showing that the new route/provenance state affected tracing identity, but the constructive stage counts and terminal behavior remained exactly unchanged. Under the design gate definition this is **not material progress**.

### Seam retained regression

The seam remains a valid direct success:

- `CompletedSurfaceCells`;
- 81 output vertices;
- 64 pure quads;
- zero non-quads;
- zero validation failures;
- no fallback/recovery;
- output structural hash `a8972efd7c4900a4`.

The seam result and all stage identities were stable across three independent processes.

## Determinism

- plane: 3/3 structurally identical;
- seam: 3/3 structurally identical;
- close sheets: 3/3 structurally identical;
- cylinder: 3/3 structurally identical;
- bunny: 2/2 structurally identical;
- vase: 2/2 structurally identical.

No timeout was treated as correctness.

## Default suites

The explicitly executed contract/direct tests were excluded from the remaining producer suite so the aggregate is non-overlapping.

- explicit contract/topology guards: **4/4**;
- direct acceptance: **1/6**;
- remaining producer: **78/79** — only `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` failed;
- completion: **154/164** — the same ten historical/downstream failures remain;
- validation: **60/60**;
- compiled API: **8/8**.

Non-overlapping total: **305/321**.

The scheduler-sensitive validator timing test remains closeout/performance evidence and is not the active correctness blocker.

## Review findings that change the next action

1. **The production plane did not consume the successful contract into direct output.** Passing the isolated vertex-fan test did not alter the mandatory plane signature.
2. **The new contract fixture is not the exact production fixture path.** `make_vertex_fan_plane_mesh()` reconstructs the same 5x4 rectangular geometry with a different vertex/face ordering and directly supplies a constant target size. It does not prove equivalence to the committed `plane.obj` after the production pipeline computes target size, source labels, finalized cross-field metadata, and tracing options.
3. **Typed phase-front failure state is not preserved in final runtime diagnostics.** `RemeshPipeline.cpp` writes `tracing/phase-front` first-invalid state when the authoritative front fails, but downstream completion failure paths overwrite the same diagnostic fields. The final artifact therefore cannot reveal the original phase-front rejection from benchmark JSON.
4. **The plane still falls through to the generic tracing/arrangement/completion path after authoritative phase-front non-success.** Before another producer predicate is changed, the review must determine whether that internal substitution is architecturally correct or whether supported authoritative domains must fail closed / return their typed producer result instead.
5. **Gate 1 successful parent remains essential comparison authority.** The design review must compare `aea10409c73c490b92f78760b73191641ef823c6` with Gate 2 and current sources to isolate the architectural condition that changed a 64-quad direct plane into the generic 106/9/12 path.

## Direction

Execute `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Plan.md` next.

The review must not authorize another local source predicate repair merely because a new Boolean/typed failure can be found. It must establish the exact production-plane authority path, explain the synthetic-contract/production divergence, and choose either a bounded architectural correction or a bounded producer replacement proof with explicit acceptance criteria.
