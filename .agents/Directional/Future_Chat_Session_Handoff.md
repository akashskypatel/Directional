# Future Chat Session Handoff — Gate 4 Canonical Transition Test Authority Remediation

Status: **ready for the next turn**  
Next turn type: **Code + Build only**  
Active branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Pull request: [#8](https://github.com/akashskypatel/Directional/pull/8), open, draft, unmerged  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Start here

1. Read and follow the complete `turn-based-coding-agent` skill.
2. Resolve PR #8 and verify it remains open, draft, and unmerged.
3. Read:
   - `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`;
   - `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Code_Build_Plan.md`;
   - this handoff;
   - `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, and `tests/TESTING_STRATEGY.md`.
4. Treat the test-authority remediation plan as the sole next-turn authority. Do not combine turn types.

## Completed artifact-only runtime authority

| Authority | Value |
|---|---|
| Implementation | `edc14d38f862b94941b249f564050e2e1f8f5287` |
| Build/event | `b0f8f039856aa1d0c7ff6be017cd5d3121a8efe0` |
| Workflow run/job | `31279574458 / 93158612245` |
| Compile artifact | `9028103772` |
| Outer SHA-256 | `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a` |
| Recursive manifest | `06123ea4c2507ed673e1a4885c4e463a6c05ed43b7a27146b3dc2722a7631a1f`, **48/48** |
| Runtime log manifest | 120 files; `ecbccb599114e1f40d5bd0efea48cb17270e7170fb134671684648cf640cd137` |

Preflight and post-runtime verification both pass. The only extracted-copy additions were `bin/test-data -> ../test-data` and generated benchmark outputs. The recorded test-CMake blob `e82e3088e11f215f030b58be7fb6531a5dbaa99a` is correctly located at `cmake/DirectionalTests.cmake`; the previous handoff's `tests/CMakeLists.txt` label was a documentation error.

## Material progress

- plane, multi-face seam, close sheets, and cylinder complete directly **3/3** each;
- direct G0-G3 GoogleTests are **4/4**, previously 1/4;
- incidence/Euler and exact retain iff requested pass;
- direct seam retains semantic digest `99c8be7159d05c2f`;
- torus moves past numeric route rejection and consumes all `4/8/4` authority, materializing `1/0/0` topology before failing final validation.

Bounded suites are producer **150/164**, completion **154/164**, validation **60/60**, compiled API **8/8**, aggregate **372/396**.

G4 remains blocked. Direct torus fails **0/3** at `completion/output-validation / LocalSheetMismatch`, output face 0, with 74 issues and no final mesh. Sphere and the broader manifest remain deferred.

## Why the next turn is test-only

Three new canonical-domain tests select a pairwise-distinct edge from a region table but never prove that edge occurs in a produced cell route. The positive case fails at `observedWitness == false`; both tamper helpers fail before materialization.

Two Phase10 tests also use the corrected compact route index as if it were the old full-edge domain:

- face-row invariance indexes `mesh.EV` with compact route/cut values;
- malformed holonomy compares a compact route value with `CrossFieldEdgeTransition.sourceEdge`, which remains a full `EF` row.

These are structurally invalid/incorrect test setups. Their assertions remain authoritative and may not be weakened. Repairing them before a torus production change keeps the canonical normalization gate verifiable.

## Next Code + Build boundary

Edit only:

- `tests/SurfaceCellTransitionQuotientTests.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

Required outcomes:

1. the canonical witness is an actually serialized route position whose source-wide compact, region-local compact, and full-`EF` values are pairwise distinct;
2. valid materialization passes and both alternate numeric substitutions reach `InvalidAuthoritativeTransitionSourceEdge`;
3. face-row tests compare parallel canonical topology and validate numeric/topology pairs through each mesh's source-wide compact map;
4. malformed holonomy selects the CrossField transition by canonical topology and reciprocal faces, then remains exact `Rejected / PeriodicHolonomyMismatch / no proposals`.

Do not edit production source, CMake, fixtures, manifests, validators, benchmarks, or unrelated tests. Commit/push, compile/package the seven approved targets, and execute no generated binary, test, discovery, benchmark, `ctest`, CLI, help, or custom input. Record `runtimeExecution=false`.

## Deferred after test authority

- torus `LocalSheetMismatch` after complete quotient consumption;
- nonzero periodic `Z4` rotation;
- shared hard-rail breakpoint scheduling at the focused target size;
- valid positive multi-isolation quotient lineage;
- historical completion/simplification and timing failures;
- sphere, bunny, vase, G5/G6, fallback/recovery, and optimization.

The temporary canonical compile workflow and trigger are absent; only `.github/workflows/agent-source-snapshot.yml` remains. Keep PR #8 open, draft, and unmerged.

After all branch files and PR-body updates, the final repository write must be one new top-level PR #8 conversation comment. Perform no GitHub write after it.
