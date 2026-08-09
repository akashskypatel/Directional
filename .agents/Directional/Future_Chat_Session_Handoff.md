# Future Chat Session Handoff — Gate 4 Torus Hard-Rail Face-Chart Authority

Status: **ready for the next turn**  
Next turn type: **Code + Build only**  
Active branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Pull request: [#8](https://github.com/akashskypatel/Directional/pull/8), open, draft, unmerged  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Start here

1. Read and follow the complete `turn-based-coding-agent` skill.
2. Resolve PR #8 live and verify it remains open, draft, and unmerged.
3. Read:
   - `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md`;
   - `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Code_Build_Plan.md`;
   - this handoff;
   - `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, and `tests/TESTING_STRATEGY.md`.
4. Treat the hard-rail face-chart plan as the sole implementation authority. Do not combine turn types or run project runtime.

## Completed artifact-only authority

| Authority | Value |
|---|---|
| Implementation | `de5261c7185aef71807b0b4140c8f023a44874fd` |
| Build/event commit | `5bf9b0efc665e0a940aa4e74b168171651685f7d` |
| Workflow run/job | `31284957305 / 93172020467` |
| Runtime artifact | `9029584083` |
| Outer SHA-256 | `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad` |
| Recursive manifest | **49/49**, `ee65be615bcf59516f5c0e05f98e56b7d9095d48d41cb1675cb5e3938ad7ce26` |
| Log artifact / SHA-256 | `9029584200` / `b2c147a691caaafc6591106ebb59f50f2956c17722f88bff1857c94d33f3da9b` |
| Runtime evidence ledger | **294/294**, manifest-file SHA-256 `22f9fc15ce0f4fdff147ba9fefe3354de344b4bc138b7272135e9415e3894cc0` |
| Artifact retention | through `2026-08-23 UTC` |

Preflight and postflight both pass. All original 49 manifest members and all six recorded source/CMake blobs remained exact. Runtime added only the expected benchmark outputs and the documented test-data locator symlink inside the isolated extraction. No source/test/fixture/validator/build/workflow edit, configure, compile, rebuild, relink, or artifact substitution occurred.

## Accepted test authority

All seven focused contracts pass individually:

1. source-wide compact index is independent of region partition;
2. full-`EF` row substitution is rejected;
3. region-local compact substitution is rejected;
4. periodic phase-front cut/holonomy ignores face-row enumeration;
5. malformed holonomy fails exact typed;
6. component/boundary/Euler facts derive from incidence;
7. deterministic failure retains authority iff requested.

The corrected two-region witness is therefore real serialized route authority, not a test setup shortcut.

Retained groups:

- transition quotient **29/36**;
- topology/isolation/hard rail **10/10**;
- polygonal/curved/mixed **12/12**;
- periodic/torus/cylinder **6/7**;
- remaining Phase10 **38/39**;
- direct G0-G3 GoogleTests **4/4**.

The literal plan filter `-*BunnyRandom*:*Vase*` selects 163 of 166 producer tests because it also excludes the mandatory Bunny/Vase fixture-integrity test. Exact bounded totals are producer **154/163**, completion **154/164**, validation **60/60**, API **8/8**, aggregate **376/395**. The prior `372/396` baseline used a different denominator and is not directly comparable. Historical completion ten and strict-validator timing remain deferred.

## Direct fixture authority

- plane: direct strict-valid **3/3**, structural `b243fb3f5f3a3bc4`, semantic `922456fe29a63ba1`;
- multi-face seam: direct strict-valid **3/3**, structural `48661113839528d4`, semantic `99c8be7159d05c2f`;
- close sheets: direct strict-valid **3/3**, structural `f01bcf687285ee72`, semantic `f40e1aa5f2eb3f92`;
- cylinder: direct strict-valid **3/3**, structural `81b3763254afc476`, semantic `98da73e60a564998`, one periodic relation consumed;
- torus: deterministic **0/3**, no fallback/recovery, 192 materialized quads, complete `4/8/4` consumption and `1/0/0` topology, then 74 `LocalSheetMismatch` issues at `completion/output-validation`.

Sphere was not run because torus did not reach strict-valid final output.

## Earliest production diagnosis

The phase-front quotient already retains every output vertex's complete sorted source-chart, topology-region, isolation-sheet, and equivalence lineage. It also selects one deterministic exact scalar `SurfacePoint` for position.

That multi-chart authority is dropped before final validation. Constraints/options carry scalar `vertexProvenance`, and the authoritative phase-front path leaves quad source charts unset. The validator therefore asks four scalar representatives to belong to one transition-graph component. Hard rails correctly split those components. A rail vertex can legitimately belong to exact charts on both producer sides, yet its scalar representative names only one, so a quad on the other side fails.

Required correction:

- project existing per-vertex retained chart and hard-rail equivalence lineage into optimizer/validator authority;
- resolve one unique exact compatible chart side per output quad;
- permit an alternate chart only when exact source support, retained chart membership, and matching reciprocal `HardRail` equivalence all agree;
- preserve scalar barycentric, position, component, sheet, and source-entity checks;
- fail closed on missing, tampered, ambiguous, unsupported, or nonreciprocal authority;
- never globally union hard-feature chart components or select by proximity/count/order/ID.

## Next Code + Build boundary

The authoritative plan allows only:

- `include/directional/geometry/SurfaceMeshOptimizer.h`;
- `include/directional/validation/SourceAuthoritativeMeshValidator.h`;
- `src/geometry/SurfaceMeshOptimizer.cpp`;
- `src/validation/SourceAuthoritativeMeshValidator.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

Add focused positive, missing-equivalence, tampered-authority, ambiguity, disconnected-close-sheet, face-row-invariance, and scalar-provenance-preservation tests. Keep the existing exact torus success contract unchanged.

Compile/package the standard seven targets in Release/static/Ninja with GoogleTest `PRE_TEST`. Do not execute any generated Directional binary, discovery/list command, test, benchmark, `ctest`, CLI/GUI command, help/version command, or custom input. The Code + Build report must prove `runtimeExecution=false` and create an exact artifact-only next plan.

## Deferred blockers

- nonzero periodic `Z4` rotation and full transform counterfactuals;
- shared hard-rail breakpoint scheduling at the Phase10 target size;
- the positive multi-isolation quotient-lineage witness;
- multi-relation owner counterfactuals;
- historical completion/simplification ten and validator timing;
- prescribed sphere, bunny, vase, G5/G6, fallback/recovery, and optimization quality.

Keep only `.github/workflows/agent-source-snapshot.yml` after any bounded build workflow cleanup. PR #8 stays open, draft, and unmerged. After all branch files and PR-body updates, the final repository write must be one new top-level PR #8 conversation comment.
