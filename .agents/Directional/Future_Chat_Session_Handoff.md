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

The current G3 artifact **did materially advance** the gate: exact cylinder moved from `NotApplicable` generic tracing to deterministic authoritative periodic `Produced` with 290 direct completed quads. The no-progress rule is therefore not triggered by this turn.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active; periodic authority is proven, completed output validation remains**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Cylinder / Holonomy artifact-only Test + Benchmark** turn is complete.

Authoritative report: `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Report.md`.

### Exact artifact authority

- source commit: `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- artifact: `9001168379` (`g3-periodic-cylinder-code-build`);
- artifact SHA-256: `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- build run/job: `31196268841` / `92925122791`;
- log artifact: `9001167184`, SHA-256 `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`;
- source patch SHA-256: `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`;
- recursive checksums: **44/44 passed**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- command boundary: `runtimeExecution=false` for the build turn;
- Test + Benchmark performed no configure/compile/relink and edited no production/test/fixture/manifest/validator/benchmark/build logic.

A runtime-only fixture symlink exposed immutable packaged paths expected by the binaries; no packaged bytes changed.

### Focused G3/retained contracts

**11/12 passed.**

The sole failure is `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`.

Classification: **incorrect test expectation**, not production nondeterminism. The test compares raw DCEL `sourceEdge` IDs between an original and face-row-reversed mesh. DCEL edge IDs are assigned by first halfedge encounter and legitimately renumber when face rows change. Mapping each route/cut ID through that mesh's EV table to canonical `(min(v0,v1), max(v0,v1))` keys yields:

- identical ordered 32-edge holonomy routes;
- identical ordered four-edge cuts: `(0,2) → (2,32) → (32,48) → (48,64)`;
- already-equal grid dimensions, rotation, and lattice translation.

The next Code + Build must compare the ordered canonical endpoint-key sequences instead of raw DCEL IDs. Do not sort away route order or weaken other holonomy assertions. Production code must not normalize incidental DCEL numbering to satisfy this test.

## Direct runtime authority

| Fixture | Result | Producer | Holonomy | Traces | Completed quads | Validation | Hash |
|---|---:|---|---|---:|---:|---:|---|
| Plane | **pass** | `Produced` | — | 352 | 64 | 0 | `730caeae49ec872c` |
| Seam | **pass** | `Produced` | — | 256 | 64 | 0 | `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | — | 1,104 | 200 | 0 | `89b052762f52a5af` |
| Cylinder | **fail / material progress** | `Produced` | `r=0, t=(29,0), route=32, cut=4` | 2,163 | 290 | 2 failures | — |
| Bunny | later gate | `NotApplicable` | — | 80,862 | 0 | — | — |
| Vase | later gate | `NotApplicable` | — | 116,922 | 0 | — | — |

No passing case uses fallback or source-grid recovery.

### Cylinder — current active G3 blocker

The exact cylinder now consumes first-class periodic authority:

- producer disposition `Produced`;
- periodic holonomy available;
- rotation `0`;
- integer translation `(29,0)`;
- ordered route edge count 32;
- deterministic cut edge count four;
- 2,163 source-attached trace segments;
- zero generic arrangement cells;
- 290 direct completed quads;
- 319 provenance vertices;
- no fallback/recovery.

It then fails before optimization/final output:

- terminal `NotProductionReady:completion`;
- first invalid producer stage `completion/output-validation`;
- reason `AggregateCompletionValidationFailure`;
- exactly two validation failures;
- output origin `None` because the completed checkpoint is correctly rejected.

The benchmark record does **not** serialize the two individual `SurfaceFinalValidationReport` threshold fields. Do not claim a specific threshold is proven and do not relax validation.

### Determinism

Plane, seam, close sheets, and cylinder were each run in three independent processes.

- plane, seam, close sheets: same direct valid outputs/hashes 3/3;
- cylinder: same `Produced` disposition, holonomy tuple/counts, 2,163 traces, 290 quads, 319 provenance vertices, two validation failures, failure identity, and recorded stage hashes 3/3.

Cylinder wall range was approximately 0.92–1.06 s.

Bunny completed one bounded observation in 28.61 s. Vase completed one in 51.93 s. They remain later gates.

## Default-suite evidence

- focused/retained producer contracts: **11/12**;
- remaining producer executable excluding those 12: **82/86**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total: **315/330**.

The known scheduler-sensitive validator timing ratio remains performance/closeout evidence. The ten completion/simplification failures and bunny/vase direct acceptance remain deferred by gate order. Direct gate status outranks aggregate totals.

## Bounded diagnosis that drives the next turn

The current periodic chart uses a global periodic target-size count and the committed cylinder produces `gridU=29` while its canonical source ring has 16 source strips. Direct materialization converts accepted cells to straight quads and does not require every canonical source-ring corner to be a lattice column. On curved annular topology, this permits a direct output side to bridge a source strip corner even while the phase-front side retains source-route provenance.

This is a **general structural risk**, not proof of the exact two failed validator thresholds. The next Code + Build corrects the source-strip structure upstream rather than changing the validator.

## Next authoritative turn

**Code + Build — G3 periodic output validation.**

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md`.

Before editing, write exactly:

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: a Produced periodic phase-front must materialize its cut-quotiented annular cells into a source-authoritative completed quad mesh that passes the existing pre-optimization validation without shortcutting canonical source-strip structure; row-order invariance must be compared in canonical source identity rather than DCEL edge numbering
Smallest general implementation change: preserve canonical annulus source-strip breakpoints in periodic lattice/materialization, choosing deterministic per-strip subdivisions nearest the target size so output sides do not bridge source topological corners, while retaining exact periodic holonomy quotient and one accepted cell -> one quad; separately correct the row-order contract test to compare ordered canonical source-edge endpoint keys instead of raw sourceEdge IDs
Observable material-progress condition: exact cylinder remains Produced with the same valid periodic authority and reaches zero completed-checkpoint validation failures/direct CompletedSurfaceCells output, while plane, seam, and close sheets remain strict-valid deterministic regressions; the row-order test passes by canonical endpoint identity without weakening its holonomy invariants
Explicitly deferred work: torus/general genus, singularity topology and G4 completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, scheduler timing, and unrelated historical completion/simplification failures
```

### Required next implementation constraints

1. Preserve topology-derived annulus applicability, deterministic intrinsic cut, first-class holonomy, explicit periodic ownership, typed rejection, and exact quotient identity.
2. Derive canonical annulus source-ring strips from source topology, never fixture identity/counts.
3. Every source-ring strip boundary is a mandatory intrinsic periodic lattice breakpoint.
4. Derive a positive deterministic subdivision count for each strip from intrinsic strip length and local target size; use canonical topology for tie-breaking.
5. Periodic lattice translation becomes the cumulative integer strip subdivisions; do not hard-code 16, 29, fixture names, or expected totals.
6. Ensure one direct output side cannot bridge a mandatory source-strip corner.
7. Keep one accepted phase-front cell → one quad. No post-hoc split/merge/snap/weld repair.
8. Preserve the artificial-cut quotient exactly; no Euclidean/nearest-point seam pairing.
9. Correct the row-order contract test only by mapping each mesh's raw edge IDs through its own EV table to ordered canonical endpoint keys. Keep grid/rotation/translation/cardinality/order assertions.
10. Do not weaken the exact cylinder direct acceptance test or any validator threshold.
11. Code + Build only: use `PRE_TEST` or equivalent; execute no generated project binary, test, benchmark, CLI, help/list, or discovery command.
12. Compile the approved seven targets and package an immutable artifact with source authority, logs, fixtures, recursive checksums, and `runtimeExecution=false` metadata.
13. Temporary build workflows must upload a separate detailed log artifact and must be removed with trigger/payload after artifact verification.
14. The following turn is artifact-only G3 Test + Benchmark; no runtime correctness claim belongs in Code + Build.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
9. latest runtime summary
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

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
- The exact cylinder now proves periodic `Produced` authority and deterministic holonomy; the active defect is downstream direct materialization/output validation, not periodic applicability.
- Raw DCEL edge integers are incidental identities across independently enumerated meshes; compare canonical source-edge endpoint identity when row-order invariance explicitly permits canonical renumbering.
- Source-route provenance alone does not justify a straight direct output side skipping a mandatory source topological corner; periodic materialization must retain source-strip breakpoints.
- Validation remains authoritative; when benchmark serialization reports only an aggregate validation failure, do not invent the individual failed thresholds.
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