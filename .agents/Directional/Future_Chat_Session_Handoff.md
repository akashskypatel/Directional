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

The just-completed G3 Code + Build makes the previously missing field-authoritative adjacent-ring correspondence contract live in production source and compile-verifies it with explicit ambiguity fail-closed behavior. Runtime material acceptance remains pending the next artifact-only turn. The no-progress rule is not triggered by this turn.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active; periodic topology/cut/quotient/source-strip authority is runtime-proven, field-authoritative adjacent-ring correspondence is compile-valid, runtime revalidation pending**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Ring Correspondence Code + Build** turn is complete.

Authoritative Code + Build report: `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Report.md`.

### Design declaration used by the turn

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at completion/output-validation
Missing design contract: adjacent canonical annulus rings can admit multiple source-topologically valid bijections through a triangulated strip; the authoritative periodic chart must resolve that correspondence from reciprocal cross-field family/transport authority, not lexicographic source-vertex ordering
Smallest general implementation change: replace valid.front() ring-pair selection with a field-family-consistent reciprocal ring correspondence that preserves the existing annulus topology, cut, holonomy and source-strip breakpoints; accept exactly one field-consistent bijection and fail closed on zero or multiple authoritative candidates
Observable material-progress condition: the exact cylinder keeps periodic Produced authority but its inter-ring sides follow the axial field family rather than diagonal strip edges, eliminating the 37.967-degree field-P95 defect and allowing normal/warpage quality to move under their existing thresholds while plane, seam and close sheets remain unchanged regressions
Explicitly deferred work: G4 singularities/topology-distinct completion, torus/general genus, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production remediation, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization hardening
```

## Latest executed runtime authority — unchanged by Code + Build

The latest executed G3 authority remains source `2783ea718ffb15f8fb3868795173472ab8636c1c`, artifact `9004509871`.

| Fixture | Result | Producer | Holonomy | Traces | Quads | Validation | Output |
|---|---:|---|---|---:|---:|---:|---|
| Plane | **pass** | `Produced` | — | 352 | 64 | 0 | `CompletedSurfaceCells`, `730caeae49ec872c` |
| Seam | **pass** | `Produced` | — | 256 | 64 | 0 | `CompletedSurfaceCells`, `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | — | 1,104 | 200 | 0 | `CompletedSurfaceCells`, `89b052762f52a5af` |
| Cylinder | **fail / material progress** | `Produced` | `r=0, t=(32,0), route=32, cut=4` | 2,237 | 320 | 3 | withheld at completed validation |
| Bunny | later gate | `NotApplicable` | — | 80,862 | 0 | 0 | later-gate failure |
| Vase | later gate | bounded timeout | — | — | — | — | timeout failure only |

No passing case uses fallback or source-grid recovery. Plane, seam, close sheets and cylinder semantic state were deterministic 3/3.

Exact cylinder failed fields recovered non-invasively from the unmodified packaged runtime:

- normal P95 `16.627273436620403° > 15°`;
- field P95 `37.96709872810172° > 15°`;
- warpage P95 `30.621379281060747° > 30°`.

All represented discrete strict/source-authoritative topology, boundary, feature, provenance, local-sheet, manifold, inversion, self-intersection, convexity, valence, Euler and component checks pass. Validation remains authoritative and unchanged.

The source-strip correction remains proven and retained: source-to-output P95 improved approximately `0.104464 -> 0.008174` and quad-to-source P95 approximately `0.068328 -> 0.031281` while field P95 stayed exactly `37.9670987281°`.

## Structural root cause entering the completed turn

Each adjacent graph-distance annulus ring pair admits two source-topologically valid one-to-one correspondences because the triangulated strip contains both same-column axial and diagonal inter-ring edges. Previous production collected all topology-compatible candidate source-vertex sequences, sorted them lexicographically, and consumed `valid.front()`.

On the committed cylinder that incidental ordering chose the diagonal/sheared candidate. Its inter-ring source edge is exactly `37.9670987281°` away from the axial cross-field family, matching field P95.

Source vertex IDs and lexicographic enumeration are incidental identities and cannot be producer ownership authority.

## G3 field-authoritative correspondence implementation

Final source/test commit:

- `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`.

Implementation lineage:

- initial implementation commit `18f2c880f1714d8c41c9e11dadd53169756629fe`;
- implementation patch SHA-256 `49cd71bc5aafc33ccdfd5e5104e5a23c7452e72074aac3c7775794f55737d6de`;
- compile-only test correction patch SHA-256 `8c96fa983990ab6c3f3ace5b24b8af59678aa7d6a0b7ed4f57b06f1397d1cd56`.

Final blobs:

- `include/directional/geometry/SurfaceCellTracing.h` → `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `src/geometry/SurfaceCellTracing.cpp` → `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`;
- `tests/SurfaceCellsPhase10Tests.cpp` → `c4671ef674228d74b96e80499abbb6846bcdf3e3`.

### Constructive contract

The periodic annulus producer now:

1. retains source-topology-compatible adjacent-ring candidate enumeration;
2. builds source-edge incidence, matching-index and explicit-transition authority before correspondence selection;
3. propagates a candidate's 4-RoSy branch state through the candidate strip face-dual graph using `resolve_branch_transition()`;
4. requires reciprocal forward/reverse transition consistency;
5. evaluates inter-ring source connections against one transported cross-field family and circumferential ring connections against its orthogonal family;
6. consumes only a unique field-authoritative optimum;
7. returns typed `InvalidPeriodicRingCorrespondence` when no field-authoritative candidate exists;
8. returns typed `AmbiguousPeriodicRingCorrespondence` when effectively equal best field candidates remain rather than tie-breaking by source ID/order/count/frequency;
9. preserves topology-derived annulus applicability, true boundaries/cut, first-class holonomy, source-strip breakpoints/subdivisions, artificial-cut ownership, exact quotient, provenance and one accepted cell → one quad.

No validator, materializer repair, generic fallback/recovery, Euclidean seam weld, fixture ID/count, arbitrary subset or post-hoc split/merge path was added.

### New regression source

- `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` requires the exact cylinder's exact-source-vertex V-family phase-front edges to follow the authoritative axial field family instead of a diagonal strip edge.
- `SurfaceCellsPhase10.PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed` creates a synthetic 4-RoSy field where the two topology-compatible rising correspondences are genuinely field-equivalent and requires `Rejected/AmbiguousPeriodicRingCorrespondence` with no generic seeds/traces/proposals.

Existing G3 topology, row-order, source-strip, artificial-cut, malformed-holonomy and exact-cylinder producer-boundary tests remain compiled.

## Compile-only authority

### First bounded attempt

Run/job `31213727511 / 92982293325` pushed production/test implementation commit `18f2c880...`. Production source compiled; compilation then failed in the new test helpers because of Eigen expression-template lambda return types and dynamic row-expression `cross()` calls. Failure log artifact `9007820580`, SHA-256 `ee5d9d3ae3f69c88983652495013a2742fa4c4e1bf8c0a90a65bc392d1a0cbec`. No generated project binary ran.

The correction was limited to explicit `Eigen::RowVector3d` test-helper types and concrete three-component edge temporaries. Production behavior did not change.

### Successful bounded build

- workflow run/job: `31214404170` / `92984429773`;
- final source: `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- artifact: `9008118764` (`g3-periodic-ring-correspondence-code-build`);
- artifact SHA-256: `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- detailed log artifact: `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- recursive checksums: **44/44**;
- compile/link actions: **111/111**;
- approved targets: **7/7**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- GNU C++ 13.3.0 / CMake 3.31.6 / Ninja 1.13.2 / Release static / `PRE_TEST`;
- command boundary: `runtimeExecution=false`;
- generated Directional binary/test/benchmark/CLI/GUI/help/list/discovery execution: **none**.

The downloaded build/log archives match GitHub-reported outer digests. A fresh local extraction passed all 44 recursive checksums. Integrity inspection did not execute any packaged project binary.

## Next authoritative turn

**Artifact-only Test + Benchmark — G3 Periodic Ring Correspondence.**

Execute `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9008118764`.

### Mandatory artifact authority

- artifact ID `9008118764`;
- SHA-256 `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- source `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- expected recursive checksums **44/44**;
- run/job `31214404170 / 92984429773`;
- log artifact `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- final blobs exactly as listed above.

### Test + Benchmark boundary

1. Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic or build logic.
2. Runtime-only fixture symlinks are allowed only to expose immutable packaged fixture paths.
3. Verify outer artifact digest, all 44 recursive checksums, source/patch/blob authority, five executables, two libraries, 27 fixture/input files and `runtimeExecution=false` before executing any project binary.
4. If integrity fails, classify infrastructure invalid and stop; do not repair packaged bytes or build a replacement artifact.
5. Execute the two new correspondence contracts plus six retained G3 periodic contracts first.
6. Execute retained G1/G2 producer contracts.
7. Revalidate plane, seam and close sheets before active cylinder acceptance.
8. Require exact cylinder periodic `Produced`, direct strict-valid `CompletedSurfaceCells`, zero validation failures, field/normal P95 <= 15°, warpage P95 <= 30°, exact cut/holonomy/quotient/provenance and no fallback/recovery.
9. Do not require historical translation/grid/output/provenance counts.
10. Run independent-process determinism and default suites only after direct gate decision.
11. Observe bunny/vase only afterward as later-gate evidence.
12. `Rejected` must not fall through to generic producer substitution. `NotApplicable` remains a separate failure state for active G3 acceptance.
13. Timeout is failure only, never correctness evidence.

### G3 decision hierarchy

**Closure:** exact cylinder consumes field-authoritative correspondence and becomes direct deterministic strict-valid pure-quad `CompletedSurfaceCells` with zero validation failures and G0–G2 green → advance to G4.

**Material progress, G3 still open:** field-authoritative correspondence is consumed and exposes a new later exact structural/quality failure with no fallback/generic substitution and G0–G2 green → preserve that exact failure and address only it next.

**No progress/regression:** periodic authority, cut/quotient/source-strip invariants, correspondence contracts or passed gates regress → keep G3 active and apply the mandatory no-progress rule when applicable.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Report.md`
- `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Report.md`
7. `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. latest runtime summary
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. turn-based coding-agent skill and relevant Test + Benchmark, testing-integrity, recovery, handoff, connector-workflow and unit-testing references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Exact production preprocessing is part of producer authority; geometrically equivalent reconstructed fixtures are not necessarily execution-equivalent.
- Complete zero-turn and reciprocal quarter-turn metadata must share one exact transport contract.
- Source-vertex crossings require ordered source-topology fans, never positional jumps or arbitrary subsets.
- `NotApplicable` and `Rejected` must not be conflated; authoritative rejection cannot be silently substituted by another internal producer.
- Typed rejection is necessary authority but does not replace constructive success.
- Relief barriers become hard only when their embedded-authority flag says so.
- Plane proves bounded authoritative phase/front construction; seam proves reciprocal cross-chart transport; close sheets prove spatial proximity cannot merge unrelated source sheets.
- Periodic topology requires explicit holonomy; an artificial chart cut is not a real exterior boundary.
- Periodic seam identification must use exact source/phase/lattice authority, never Euclidean welding.
- Raw DCEL/source-edge integer IDs are incidental across independent enumeration; compare canonical source identities where renumbering is permitted.
- Periodic construction must retain canonical source-strip breakpoints upstream of materialization.
- Per-strip target subdivisions may change periodic lattice translation; historical cardinalities are evidence, not constants.
- Multiple source-topologically valid ring bijections must be resolved by reciprocal transported cross-field authority, not lexicographic source IDs/count/order/frequency.
- Ambiguous field-authoritative ownership must fail closed rather than use an incidental tie-break.
- Compile-valid source is not runtime proof; exact artifact execution decides gate closure.
- Real bunny/vase fixtures remain mandatory later observations and may not be simplified or bypassed.
- Direct gates outrank aggregate totals. Scheduler timing ratios are closeout evidence, not functional correctness.
- `PRE_TEST` preserves compile-only boundaries. Timeout is failure only, never correctness evidence.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the start and end of every turn, inspect `.github/workflows` and all temporary triggers, transfer files, payload/patch directories and generated artifacts.
2. Remove stale bounded or turn-specific workflows before work begins.
3. During remote compile, retain only approved durable workflows plus at most one bounded workflow and its exact payload.
4. After artifact/log verification, remove bounded workflows, triggers and payloads.
5. Final branch state must contain only approved durable workflows and no stale generated artifact.
6. Do not remove a durable dependency consumed by an approved retained workflow.
7. Retain exact payloads until their source commit, expected blobs and build authority are verified; then remove them.

### Documentation and result cleanup

1. End every turn by removing stale/superseded plans, reports, closure notes, evidence indexes and results from `.agents` and `benchmark-results`.
2. Retain only the live handoff, latest report(s) needed for current authority, next executable plan, current runtime summary, durable baselines and durable design/remediation/workflow-policy documents.
3. Retained documents may reference only existing files.
4. Git history and PR conversation are the historical archive.
5. Never delete latest evidence or next-turn instructions before verified replacements exist.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret or silently replace an existing mandatory instruction in this handoff unless the user explicitly requests it.**
2. Handoff edits are additive or narrowly corrective by default; preserve all procedural, safety, scope, cleanup, validation, repository-write and turn-boundary requirements.
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