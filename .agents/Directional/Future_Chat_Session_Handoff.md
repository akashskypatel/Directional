# Future Chat Session Handoff — Gate 4 Canonical Test Authority Artifact Validation

Status: **ready for the next turn**
Next turn type: **Test + Benchmark only**
Active branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
Pull request: [#8](https://github.com/akashskypatel/Directional/pull/8), open, draft, unmerged
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Start here

1. Read and follow the complete `turn-based-coding-agent` skill.
2. Resolve PR #8 and verify it remains open, draft, and unmerged.
3. Read:
   - `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Code_Build_Report.md`;
   - `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`;
   - `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`;
   - this handoff;
   - `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, and `tests/TESTING_STRATEGY.md`.
4. Treat the new artifact-only plan as the sole execution authority. Do not combine turn types.

## Completed Code + Build authority

| Authority | Value |
|---|---|
| Entering branch head | `2703f2f94e77afa4c7ed397200ddd456413c7125` |
| Test-remediation implementation | `de5261c7185aef71807b0b4140c8f023a44874fd` |
| Build/event commit | `5bf9b0efc665e0a940aa4e74b168171651685f7d` |
| Workflow run/job | `31284957305 / 93172020467` |
| Compile artifact | `9029584083` |
| Outer SHA-256 | `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad` |
| Recursive manifest | **49/49**, `ee65be615bcf59516f5c0e05f98e56b7d9095d48d41cb1675cb5e3938ad7ce26` |
| Log artifact / SHA-256 | `9029584200` / `b2c147a691caaafc6591106ebb59f50f2956c17722f88bff1857c94d33f3da9b` |
| Artifact retention | through `2026-08-23 UTC` |

Release/static/Ninja with GoogleTest `PRE_TEST` compiled all seven approved targets at **113/113**. Five ELF executables, two static libraries, 27 fixtures, exact source closure, two-file patch, compile database, metadata, logs, and checksums are present and independently verified. `runtimeExecution=false`; no generated binary, test, benchmark, discovery, `ctest`, CLI, help/version command, or custom input ran.

Exact changed blobs:

- `tests/SurfaceCellTransitionQuotientTests.cpp`: `42111d1de51baa6cca85171aeab339813cae3b50`;
- `tests/SurfaceCellsPhase10Tests.cpp`: `552a3d98ec8f9280b960fb9bbff9a1c7596a0778`.

Production and CMake blobs remain unchanged.

## Corrected test authority

- A separate unit-square plus 2-by-1-rectangle fixture makes the later region's interior diagonal a natural serialized route crossing while keeping source-wide compact, region-local compact, and full-`EF` values distinct.
- The witness is selected only from actual cell boundary paths and records the exact cell/side/segment/route slot used by both tampers.
- Every route numeric value remains checked against the parallel topology through the source-wide map; genuine boundaries remain topology-only.
- Face-row periodic invariance now compares ordered topology and independently validates compact mappings instead of indexing `mesh.EV` with compact values.
- Malformed holonomy now selects exactly one full-`EF` CrossField transition by canonical topology and reciprocal faces before the unchanged matching tamper.
- No semantic or typed-failure assertion was weakened.

These corrections have compiled but have not run. If the new rectangle does not produce the intended route, classify a test-fixture authority failure and do not change production code.

## Entering runtime baseline

Artifact `9028103772`, implementation `edc14d38f862b94941b249f564050e2e1f8f5287`, remains the latest runtime authority until the next turn completes.

- plane, multi-face seam, close sheets, and cylinder: direct strict-valid **3/3** each;
- seam semantic digest: `99c8be7159d05c2f`;
- direct G0-G3: **4/4**;
- bounded suites: producer **150/164**, completion **154/164**, validation **60/60**, API **8/8**, aggregate **372/396**;
- torus: **0/3** at `completion/output-validation / LocalSheetMismatch` with 74 issues after complete `4/8/4` authority consumption and materialized `1/0/0` topology.

Sphere and the broader manifest remain deferred while torus is not strict-valid.

## Next artifact-only boundary

Consume artifact `9029584083` exactly. Preflight both outer artifacts, all 49 recursive entries, the six source/CMake blobs, the two-path patch, source archive, toolchain/submodules, five executables, two libraries, and 27 fixtures before runtime.

Run the seven focused tests individually:

1. the three canonical-domain tests;
2. face-row-invariant periodic cut/holonomy;
3. malformed-holonomy typed rejection;
4. incidence/Euler facts;
5. retain iff requested.

Then preserve the prior-green focused/bounded suites and repeat three fresh processes per fixture in order: plane, multi-face seam, close sheets, cylinder, torus. Torus precedes and gates sphere. Do not rebuild or edit source, tests, fixtures, validators, manifests, CMake, workflows, or benchmark acceptance.

If all seven focused contracts pass with retained direct behavior, the next production Code + Build slice may target torus `LocalSheetMismatch`. If a test still fails before its intended assertion, repair test authority only.

## Deferred production blockers

- torus local-chart compatibility after complete quotient consumption;
- nonzero periodic `Z4` rotation;
- target-size-dependent shared hard-rail breakpoint scheduling;
- valid positive multi-isolation quotient lineage;
- historical completion/simplification ten and validator timing;
- sphere, bunny, vase, G5/G6, fallback/recovery, and optimization.

The temporary compile workflow and trigger were removed in safe order; retain only `.github/workflows/agent-source-snapshot.yml`. After all branch files and PR-body updates, the final repository write must be one new top-level PR #8 conversation comment.
