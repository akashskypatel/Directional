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
4. G3 periodic closure / holonomy — **active; implementation is compile-valid, runtime verification pending**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Cylinder / Holonomy Code + Build** turn is complete.

### Design declaration used by the turn

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: authoritative phase/front construction and periodic seam reconciliation on a singularity-free annulus without treating the periodic cut as an exterior boundary or falling back to generic tracing
Smallest general implementation change: extend the uniform authoritative producer with one deterministic intrinsic cut/unwrapped chart for annular source topology, record exact lattice holonomy across that cut, and stitch periodic front counterparts through source-topology/phase equivalence
Observable material-progress condition: exact production cylinder becomes authoritative Produced or reaches a new typed periodic-holonomy Rejected state with zero generic substitution, while plane, seam, and close sheets remain mandatory regressions
Explicitly deferred work: torus/non-annular topology, singularities/topology-distinct completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production/performance, scheduler timing, downstream completion/simplification failures
```

### G3 source authority

- production source commit: `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- patch SHA-256: `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`;
- changed blobs:
  - `include/directional/geometry/SurfaceCellTracing.h` → `931669018a986096cf78d66a2aed9de5aa8e0fe1`;
  - `include/directional/diagnostics/RemeshDiagnostics.h` → `a51215982318e77581efa4fa7887d0406a9d4bf0`;
  - `src/geometry/SurfaceCellTracing.cpp` → `b1a2c6d4051cc17b79e342170285d69552cad16d`;
  - `src/pipeline/RemeshPipeline.cpp` → `7674ed3fe40c5f43c668c931c01b59f6c7829df8`;
  - `src/bench/DirectionalBenchmark.cpp` → `18955ca8ef72812c9c70ed522bb578409e6a176f`;
  - `tests/SurfaceCellsPhase10Tests.cpp` → `bccd6abf3e31b8096c471c515b1949d08dcfde59`.

Implemented bounded G3 contracts:

1. the periodic producer is attempted only after the connected planar producer is structurally `NotApplicable`;
2. annulus applicability derives from source manifold topology, Euler state, two source boundary cycles, source connectivity, and singularity-free state rather than fixture identity;
3. deterministic source boundary/ring ordering defines one cut-open intrinsic `(s,t)` chart without global world-space planarity;
4. chart samples and cell boundaries retain exact source face/barycentric attachment;
5. periodic holonomy is first-class as `(Z4 quarter-turn rotation, Z2 integer lattice translation, ordered source route)` and the deterministic boundary-to-boundary source cut is retained separately;
6. duplicate, missing, or incompatible periodic transport is typed `Rejected` and cannot silently launch the generic producer;
7. artificial-cut front copies pair through intrinsic periodic lattice identity with explicit `PeriodicFrontMerge` events rather than exterior-boundary or Euclidean semantics;
8. only genuine annulus boundary directions may remain exterior in the bounded periodic front;
9. materialization quotients duplicated cut-chart lattice identities exactly; no nearest-point/Euclidean seam welding or post-hoc cell merge was added;
10. holonomy contributes to structural hashing and benchmark diagnostics;
11. five focused G3 periodic regression sources were added and compiled, not executed.

### Compile authority

- workflow run/job: `31196268841` / `92925122791`;
- artifact: `9001168379` (`g3-periodic-cylinder-code-build`);
- artifact SHA-256: `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- detailed log artifact: `9001167184` (`g3-periodic-cylinder-code-build-logs`);
- log SHA-256: `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`;
- recursive build-artifact checksums: **44/44 passed**;
- compile/link actions: **111/111**;
- approved targets: **7/7**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- compiler/toolchain: GNU C++ 13.3.0, CMake 3.31.6, Ninja 1.13.2, Release static, `PRE_TEST`;
- generated project binary/test/benchmark execution: **none**.

The downloaded build and log archives matched the GitHub outer digests. Packaged command-boundary metadata records `runtimeExecution=false`.

This is compile evidence only. **G3 runtime success is not claimed.**

## Passed-gate runtime authority — mandatory regressions

Latest executed authority is the preceding G2 artifact `8994541137`:

| Fixture | Result | Producer | Traces | Arrangement | Quads | Components | Hash |
|---|---:|---|---:|---:|---:|---:|---|
| Plane | **pass** | `Produced` | 352 | 65 | 64 | 1 | `730caeae49ec872c` |
| Seam | **pass** | `Produced` | 256 | 65 | 64 | 1 | `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | 1,104 | 202 | 200 | 2 | `89b052762f52a5af` |

All three are direct `CompletedSurfaceCells` outputs, strict-valid, deterministic 3/3, and use no fallback/recovery.

The close-sheet output has two isolated 121-vertex components at `z=-0.035` and `z=+0.035` with the same XY footprint. Spatial proximity is therefore proven not to substitute for source component/local-sheet authority.

## Latest later-gate runtime observations — unchanged by Code + Build

### Cylinder — active G3 blocker until artifact execution

- disposition `NotApplicable`;
- 732 generic traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`;
- no fallback/recovery;
- deterministic 3/3 prior signature.

### Bunny

- disposition `NotApplicable`;
- 80,862 traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`.

### Vase

- disposition `NotApplicable`;
- 116,922 traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`.

Bunny/vase remain later mandatory observations and cannot supersede G3.

## Latest executed default-suite evidence

- focused G2 producer contracts: **7/7**;
- remaining producer executable: **82/86**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total including focused contracts: **311/325**.

The G3 Code + Build turn did not execute these suites. Direct gate ordering outranks aggregate totals.

## Next authoritative turn

**Artifact-only Test + Benchmark — G3 Periodic Cylinder / Holonomy.**

Execute exactly `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9001168379`.

### Mandatory artifact authority

- artifact ID: `9001168379`;
- artifact name: `g3-periodic-cylinder-code-build`;
- artifact SHA-256: `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- source commit: `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- source patch SHA-256: `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`;
- expected recursive checksums: **44/44**;
- build run/job: `31196268841` / `92925122791`;
- log artifact: `9001167184`, SHA-256 `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`.

### Test + Benchmark turn boundary

1. Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic.
2. Runtime-only fixture symlinks are allowed only to expose packaged fixture paths without modifying packaged bytes.
3. Verify outer artifact digest, all 44 recursive checksums, exact source authority, patch, changed blobs, five executables, two project libraries, and 27 fixture/input files before executing any project binary.
4. If integrity fails, classify infrastructure invalid and stop; do not repair packaged source or inputs.
5. Execute the five new G3 periodic producer contracts first.
6. Revalidate plane, seam, and close sheets as mandatory passed-gate regressions.
7. Execute exact production cylinder as the active G3 acceptance fixture.
8. Prove first-class holonomy, reciprocal artificial-cut pairing, and absence of a false exterior seam or Euclidean seam welding.
9. Run bounded determinism and non-overlapping default suites only after the active acceptance cases.
10. Observe bunny/vase only after the G3 decision; later cases cannot make G3 pass.
11. For `Rejected`, verify generic producer substitution does not occur. For `NotApplicable`, record it separately and never reinterpret it as success.
12. Timeout is failure only, never correctness evidence.

### Focused G3 contracts

Run first:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
2. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
3. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
5. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

Then run retained plane/source-fan/close-sheet contracts required by the exact G3 plan.

### G3 acceptance hierarchy

**G3 closure:** exact cylinder is direct deterministic strict-valid `Produced` pure-quad `CompletedSurfaceCells` output with correct periodic holonomy/quotient, artificial cut absent from exterior output, and plane/seam/close sheets remain valid. Next implementation gate becomes G4 topology-distinct completion and singularities.

**Material progress, G3 still open:** cylinder becomes applicable to the periodic producer and reaches a new exact typed `Rejected` periodic topology/chart/holonomy/front state with zero generic substitution while G0–G2 remain green. The next Code + Build turn addresses only that exact general rejection.

**No material progress/regression:** cylinder remains on the same generic `NotApplicable` path, periodic cut is treated as exterior output, periodic pairing relies on proximity, `Rejected` substitutes generic work, or any passed G0–G2 fixture regresses.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Report.md`
- `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Report.md`
7. `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md`
8. `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
9. latest runtime summary
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill and relevant Test + Benchmark, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

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
- Spatial proximity must never substitute for source component/local-sheet identity; close sheets prove this at production runtime.
- Periodic topology requires explicit holonomy and cannot be represented by declaring an artificial chart cut to be a real boundary.
- Periodic seam identification must use exact source/phase/lattice authority, never Euclidean welding.
- Compile-valid periodic state is not runtime proof; artifact execution must establish whether the cylinder becomes `Produced`, typed `Rejected`, or remains `NotApplicable`.
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
