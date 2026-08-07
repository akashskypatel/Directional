# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-07 UTC  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize `.agents/Directional/DESIGN.md` over local repair activity and work on the earliest incomplete or regressed high-level gate. Diagnostics, taxonomies, cache/memory work, scheduling, performance, historical cleanup, or downstream repair machinery must not become the principal objective while an earlier constructive gate is red.

Before any code change, write:

```text
Active design gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. New diagnostics, counters, hashes, equivalent failure movement, aggregate gains, performance work, fallback/recovery, or fixture-specific behavior are not material progress alone.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate, the next turn must be a design review or bounded producer replacement proof.

This rule was triggered for Gate 1. The mandatory Review selected **Outcome B — bounded producer replacement proof**. That replacement was implemented, compile-verified, and artifact-tested successfully. A third isolated Gate 1 phase-transition predicate repair remains prohibited.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G2 Close-Sheet Authoritative Producer artifact-only Test + Benchmark** turn is complete.

### Exact tested authority

- source commit: `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- artifact: `8994541137` (`g2-close-sheet-code-build`);
- artifact SHA-256: `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- build run/job: `31179899458` / `92870408341`;
- recursive checksums: **45/45 passed**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- changed blobs verified from packaged source:
  - `SurfaceCellTracing.cpp` `c9570ecb4a9557eebaf0e30b751e2ccca90b2973`;
  - `RemeshPipeline.cpp` `55af3205fd7cdb8f21357ac69516ffa29cf8a6d3`;
  - `SurfaceCellsPhase10Tests.cpp` `7151077d7d4e0a10dad388dd008479f96fc1aae8`;
- Code + Build command metadata confirmed `runtimeExecution=false`.

The Test + Benchmark turn did not configure, compile, relink, regenerate discovery, or edit source/tests/fixtures/manifests/validators/benchmark/build logic. A runtime-only `bin/test-data -> ../test-data` symlink exposed the packaged immutable fixtures at the path expected by the compiled tests.

### Focused producer contracts

All seven required focused contracts passed:

1. `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`;
2. `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`;
3. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`;
4. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
5. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`;
6. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`;
7. `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`.

Result: **7/7 passed**.

The close-sheet contract directly verifies phase-front source keys `{(0,0), (1,1)}` and requires each twinned front edge to have matching component/local-sheet identity on both sides. The reversed face-row case preserves phase-front cell/edge/event cardinalities.

## Gate 2 closure

The exact production close-sheet fixture is now a direct success:

- disposition `Produced`;
- `CompletedSurfaceCells` output;
- 1,104 traces;
- 202 arrangement cells;
- 200 pure quads / zero non-quads;
- 242 provenance/output vertices;
- exactly two connected output components;
- zero strict validation failures;
- no non-manifold edges, T-junctions, duplicate faces, or self-intersections;
- topology/boundary preservation true;
- no fallback/recovery;
- deterministic output hash `89b052762f52a5af` in 3/3 independent processes.

The output components contain 121 vertices each and lie independently at `z=-0.035` and `z=+0.035` while sharing the same XY footprint. Combined with the authoritative front-twin contract, this proves the bounded G2 source-sheet isolation requirement.

Therefore **G2 is closed**.

## Mandatory passed-gate regressions

| Fixture | Result | Producer | Traces | Arrangement | Quads | Components | Hash |
|---|---:|---|---:|---:|---:|---:|---|
| Plane | **pass** | `Produced` | 352 | 65 | 64 | 1 | `730caeae49ec872c` |
| Seam | **pass** | `Produced` | 256 | 65 | 64 | 1 | `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | 1,104 | 202 | 200 | 2 | `89b052762f52a5af` |

All three are strict-valid direct outputs and deterministic 3/3.

The seam's prior Gate 1 hash was `a8972efd7c4900a4`. The current artifact remains geometrically equivalent to that baseline within approximately `2.065e-9` symmetric Hausdorff distance, with unchanged 81 vertices / 64 quads and all strict validity checks passing. `5bdf34d7802e9fb0` is the current tested deterministic authority.

## Latest later-gate observations

### Cylinder — active G3 blocker

- disposition `NotApplicable`;
- 732 generic traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`;
- no fallback/recovery;
- deterministic 3/3 failure signature;
- wall range 0.146–0.148 s.

### Bunny

- disposition `NotApplicable`;
- 80,862 traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`;
- wall 23.408649 s;
- peak working set 247,545,856 B.

### Vase

- disposition `NotApplicable`;
- 116,922 traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`;
- wall 52.096160 s;
- peak working set 141,316,096 B.

Bunny/vase remain later mandatory observations and cannot supersede G3.

## Default-suite evidence

- focused producer contracts: **7/7**;
- remaining producer executable: **82/86**;
  - cylinder/bunny/vase direct design-acceptance failures are later-gate failures;
  - `StrictValidatorOverheadStaysBelowFivePercent` remains scheduler-sensitive closeout evidence;
- completion/simplification: **154/164** — same ten deferred failures;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total including focused contracts: **311/325**.

Direct gate ordering outranks aggregate totals.

## Next authoritative turn

**Code + Build — G3 periodic cylinder / holonomy.**

Execute `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Plan.md`.

Before editing, write exactly:

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: authoritative phase/front construction and periodic seam reconciliation on a singularity-free annulus without treating the periodic cut as an exterior boundary or falling back to generic tracing
Smallest general implementation change: extend the uniform authoritative producer with one deterministic intrinsic cut/unwrapped chart for annular source topology, record exact lattice holonomy across that cut, and stitch periodic front counterparts through source-topology/phase equivalence
Observable material-progress condition: exact production cylinder becomes authoritative Produced or reaches a new typed periodic-holonomy Rejected state with zero generic substitution, while plane, seam, and close sheets remain mandatory regressions
Explicitly deferred work: torus/non-annular topology, singularities/topology-distinct completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production/performance, scheduler timing, downstream completion/simplification failures
```

### Required G3 implementation constraints

1. Determine annulus applicability from source topology, never fixture identity, geometry counts, names, or expected output.
2. Limit this bounded producer to connected orientable singularity-free annular sheets with two true source boundary loops.
3. Construct one deterministic intrinsic source-topology cut joining the two boundary loops.
4. Build the cut-open phase chart through reciprocal source-topology/tangent transport; do not require global world-space planarity.
5. Preserve authoritative source provenance on both copies of cut-chart entities.
6. Make periodic holonomy first-class as quarter-turn rotation in `Z4`, integer lattice translation in `Z2`, and ordered canonical source route.
7. Non-integral, nonreciprocal, ambiguous, branch-incompatible, or missing-provenance holonomy must be typed authoritative `Rejected` and stop; no generic substitution.
8. Pair periodic front counterparts through exact source-route/lattice-holonomy equivalence, never Euclidean proximity or nearest projection.
9. The artificial cut is not an exterior output boundary; preserve only the two genuine cylinder boundary cycles.
10. Materialize periodic chart duplicates through exact periodic identity; no post-hoc seam welding or cell merging.
11. Add only minimum contract tests for annulus applicability, row-invariant cut/holonomy, periodic front pairing, typed invalid holonomy, and exact production cylinder boundary. Compile them but execute none during Code + Build.
12. Preserve plane, seam, and close sheets as mandatory compiled regressions.
13. Configure/compile approved targets with `PRE_TEST` or equivalent compile-only-safe discovery; execute no generated project binary, test, benchmark, CLI, help/list, or discovery command.
14. Package an immutable artifact with source authority, changed blobs, binaries/libraries, fixtures, logs, checksums, and command-boundary metadata for the next artifact-only Test + Benchmark turn.
15. Remove bounded workflow/trigger/payload after artifact/log verification.

G3 closes only through direct deterministic strict-valid cylinder output with explicit periodic closure and all earlier gates retained. A new exact typed periodic rejection is material progress but does not close G3.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Plan.md`
- `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
7. `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Plan.md`
8. latest runtime summary
9. `tests/TESTING_STRATEGY.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`
11. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Exact production preprocessing is part of producer authority; geometrically equivalent reconstructed fixtures are not necessarily execution-equivalent.
- Complete zero-turn and reciprocal quarter-turn metadata must share one exact transport contract.
- Source-vertex crossings require ordered source-topology fans, never positional jumps or arbitrary subsets.
- `NotApplicable` and `Rejected` must not be conflated.
- Authoritative rejection cannot be silently substituted by another internal producer.
- Typed first-rejection state is necessary authority but does not replace constructive success.
- Relief barriers become hard only when their embedded-authority flag says so.
- Plane proves the bounded authoritative phase/front on a connected planar domain.
- Seam proves reciprocal cross-chart transport.
- Spatial proximity must never substitute for source component/local-sheet identity; close sheets now prove this at production runtime.
- Periodic topology requires explicit holonomy and cannot be represented by declaring an artificial chart cut to be a real boundary.
- Periodic seam identification must use exact source/phase authority, never Euclidean welding.
- Real bunny/vase fixtures remain mandatory and may not be simplified or bypassed.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are closeout evidence, not functional correctness.
- `PRE_TEST` preserves compile-only boundaries.
- Timeout is failure only, never correctness evidence.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the start and end of every turn, inspect `.github/workflows` and all temporary triggers, transfer files, payload/patch directories, and generated artifacts.
2. Remove stale bounded or turn-specific workflows before work begins.
3. During remote compile, retain only approved durable workflows plus at most one bounded workflow and its exact payload.
4. After artifact/log verification, remove bounded workflows, triggers, and payloads.
5. Final branch state must contain only approved durable workflows and no stale generated artifact.
6. Do not remove a durable dependency consumed by an approved retained workflow.
7. Retain exact payloads until their source commit, expected blobs, and build authority are verified; then remove them.

### Documentation and result cleanup

1. End every turn by removing stale/superseded plans, reports, closure notes, evidence indexes, and results from `.agents` and `benchmark-results`.
2. Retain only the live handoff, latest report(s) needed for current authority, next executable plan, current runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Retained documents may reference only existing files.
4. Git history and PR conversation are the historical archive.
5. Never delete latest evidence or next-turn instructions before verified replacements exist.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly requests it.**
2. Handoff edits are additive or narrowly corrective by default; preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Compare handoff updates with the prior version and verify every pre-existing mandatory instruction remains materially present.
4. If a new instruction conflicts, preserve both and request user direction rather than deleting either.
5. Documentation cleanup never authorizes removal of mandatory handoff rules.

## End-of-turn requirement

Every completed turn ends with a new top-level PR #8 comment after all documentation and PR metadata updates. That comment is the **final repository write**.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
