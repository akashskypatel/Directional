# Future Chat Session Handoff — Directional Surface Cells

## Resume here

- Repository: `akashskypatel/Directional`
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Draft PR: #8 — keep **open, draft, unmerged**
- Configured optional review policy: `never`
- Mandatory review guard: **not active; latest artifact made material progress**
- Active gate: **G4 topology-distinct completion and singularities**
- Completed turn: **artifact-only Test + Benchmark — boundary and isolation-transport certificate**
- Result: **blocked with material progress**
- Next turn: **Code + Build only**
- Authoritative next plan: `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`
- Latest runtime report: `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`
- Latest compile report: `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Code_Build_Report.md`
- Current review report: `.agents/Directional/Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md`
- Entering artifact-closeout branch head: `1b002f86d61d5760c29439f9133a9da903945aaf`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the authoritative Code + Build plan, the latest runtime/compile/review reports, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the turn-based-coding-agent Code+Build/testing-integrity/recovery/GitHub-workflow references.

The next turn may edit only its exact production/test allowlist, compile/package the approved targets, and create the following artifact-only plan. It must execute no generated Directional binary, test, benchmark, `ctest`, discovery/list/help/version command, CLI/GUI command, or custom input.

## Exact immutable runtime authority

- Build artifact: **`9026181778`** (`g4-boundary-isolation-certificate-code-build`)
- Log artifact: **`9026181889`**
- Workflow run/job: **`31272661747 / 93141125742`**
- Workflow event: `9f0e6de3e4a1f70eb02d2946072305c7b8c9b5ad`
- Implementation: `82151bf51bce9af9859282b2a03e295a0ee5a309`
- Build/cleanup: `846b23a1175f541d86e880c993784715c995ef20`
- Build/log SHA-256: `0682ae9fe6e98eefac8e4ddb2ccc8db8407326d7b872ec6da1d945aa8a59b79d` / `d53a060c2b3b20205ce71b3cf44f0fe9f14a2a207a176ec74faf9a8d57e9c890`
- Internal manifest: `c63931f3cd9c6261710bd9db255a49aa03029a39d062fe21c714529c4b31fdb1`, recursive **48/48**
- Source archive: `08fa7f4403145216c1316240a4494c7fa069d77f2518ddbc6346812bcb91bdba`
- Packaged/decoded patch: `b092219704f360e2f013cdeab83a12c870ac8e804f52f325edcfca2d2a17faac` / `b93f420d7f9c8139663f8ff573613eeb23dd3c30073ff76c8b563c537fd07f10`
- Package: 49 files, 27 fixtures, five executables, two static libraries
- Build: Release/static/Ninja **113/113**, `PRE_TEST`, seven approved targets, `runtimeExecution=false`

All source blobs, dependencies, fixture blobs/copies, logs, archives, ELF/static-library resolution, and recursive checksums match. The only extracted-copy mutation was `artifact/bin/test-data -> ../test-data`. No artifact byte changed.

## Discovery and test results

Producer discovery ran exactly once and found every **33/33** `SurfaceCellTransitionQuotient.*` test.

Focused groups:

- transition quotient **24/33**;
- topology/isolation/hard-rail **10/10**;
- polygonal/curved/mixed **12/12**;
- periodic/torus/cylinder **5/7**;
- remaining non-overlap Phase10 **35/39**;
- direct G0-G3 GoogleTests **1/4**.

Bounded suites:

- producer **143/161**;
- completion/simplification **154/164**, exact same ten historical failures;
- validation **60/60**;
- API **8/8**;
- aggregate bounded **365/393**.

The first focused invocation from the extraction root was retained only as a fixture-helper working-directory diagnostic. Authoritative runs started from `artifact/bin`, where the permitted symlink resolved committed inputs. Do not count or reinterpret the diagnostic invocation as product evidence.

## Direct deterministic evidence

Three independent processes per fixture:

| Fixture | Result | Exact observation |
|---|---:|---|
| plane | **0/3** | `InvalidAuthoritativeTransitionSourceEdge`, cell/edge `63/162`, one region |
| multi-face seam | **3/3** | `CompletedSurfaceCells`, 81 vertices / 64 pure quads, one component / one loop / Euler 1, structural `48661113839528d4`, semantic `99c8be7159d05c2f` |
| close sheets | **0/3** | `InvalidAuthoritativeTransitionSourceEdge`, cell/edge `199/12`, two regions |
| cylinder | **0/3** | `InvalidPeriodicCutAuthority`, cell/edge `287/3`, one region / one relation |
| torus | **0/3** | `InvalidPeriodicCutAuthority`, cell/edge `191/0`, four regions / eight seams / four relations |

Every failure has phase-front `Produced`, output origin `None`, consumed authority `0/0/0`, and no fallback/recovery. Torus retains Euler `[0,0,0,0]`, genuine loops `[2,2,2,2]`, local-isolation cardinalities `[1,1,2,1]`, and periodic `r=0`, `t=(24,0)`, route 24, cut 2. Sphere and the broader benchmark manifest were correctly skipped.

## Source-bounded next correction

`CrossFieldEdgeTransition.sourceEdge` is a full `mesh.EF` row. The materializer reconstructs one source-wide compact table over two-face interior edges. `source_edge_provenance()` returns the full row when transition metadata exists, while local producers can also build compact tables from active-region faces. Those alternate domains are stored in the same segment/front/periodic route fields, while materialization always interprets them in the source-wide compact domain.

The next Code + Build must:

1. validate CrossField transition topology and reciprocal incident faces;
2. construct and thread one source-wide `edge_matching_indices(edge_faces(full source faces))` table, then emit that compact value to every materializer-facing two-face transition/periodic route;
3. retain canonical topology beside the numeric route and strict per-position agreement;
4. keep genuine one-face boundaries topology-only and keep `edge_matching_indices()` interior-only;
5. add positive/tamper counterfactuals where the full `EF` row and a region-local compact value differ from the source-wide compact index.

Retention must also split:

- `retainRequested = options.surfaceCells.retainIntermediateGeometry`;
- temporary operational ownership needed to reach failure injection.

The same committed valid input must reach identical `InjectedStageFailure / tracing` for retain true/false, with trace authority exposed iff requested.

## Exact next allowlist

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`
- `tests/SurfaceCellsPhase10Tests.cpp` only if needed for the normalized integration assertion

CMake, fixtures, manifests, validators, benchmarks, cross-field extraction, completion/simplification, and unrelated tests are outside scope.

## Explicitly deferred blockers

1. Winding cylinder: periodic annulus rejects nonzero accumulated `Z4` matching, then hard-codes relation rotation zero.
2. Exact torus Phase10: independently produced hard-rail sides do not yet share one conforming source-authoritative breakpoint schedule.
3. Split isolation: certificate acceptance does not yet create a proven multi-sheet quotient class/equivalence witness; establish a valid reciprocal cross-sheet precondition before changing product lineage.
4. Sphere, G5/G6, bunny/vase, historical completion repairs, validator/timing thresholds, fallback/recovery, and unrelated optimization.

## Process and repository rules

Artifact `9026181778` made material progress by restoring direct multi-face seam, activating all 33 counterfactuals, and validating boundary/certificate/digest contracts. The mandatory no-progress Review guard is not active.

Never combine turn types. Code + Build makes no runtime claim. The next following turn must consume one exact immutable artifact without rebuilding. PR #8 remains open, draft, and unmerged.

End-of-turn hygiene retains only `.github/workflows/agent-source-snapshot.yml` in workflow/temporary-state paths; bounded workflow, trigger, and payload state must be absent. Every completed turn ends with a new top-level PR #8 conversation comment as the final repository write. Perform no GitHub write after that comment.
