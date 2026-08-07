# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
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

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform phase-front plane — **active restoration verification; build complete, runtime pending**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 verification and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The Gate 1 regression-restoration Code + Build turn is complete.

### Exact source and build authority

- prior tested source: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- documentation parent: `1a72073db04d440758ed1ddb23e3dfbf2fe1e7bb`;
- payload checkpoint: `da707052a28688ee35c81d26d2356e3f8581b032`;
- patch SHA-256: `53c402e8d9740c057f70bfc64912fef3f3e2c4d41b57c38710875f17fc4172d8`;
- final source blob: `850971a60b75dd84a81ddd4d260998f7ec9c326a`;
- source commit: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- payload cleanup: `d0ffebf4ef0239563f46dbb7485144bb581e80f1`;
- source-sync run/job: `31143208487` / `92757246121`;
- source-sync evidence artifact: `8980516098`, SHA-256 `2f8561fc8b5937be6bf05a6e010379bd5241ec13a7ced26c7e20a970a07b4766`;
- local build artifact: `directional-g1-regression-restoration-local-build-artifact.zip`;
- artifact SHA-256: `c516af42f6aa388ef219408ef63e939490176385e976885f1ea9176ec3609e20`;
- internal checksums: 44/44;
- five executables, two project static libraries, 27 fixture/input files;
- approved targets: 7/7; incremental compile/link actions: 7/7;
- build wall time: 16.51 seconds; peak RSS: 1,152,172 KiB.

No generated project binary, test, benchmark, discovery command, CLI, GUI, help command, or list command was executed. This turn makes no plane or seam runtime-success claim.

### Implemented contract

The regression came from treating non-null pointers to empty prescribed-field matching/transition containers as complete authoritative metadata. Every interior lookup then failed before phase-front construction.

The planar phase-front proof now:

- treats empty matching, effort, and transition containers as absent metadata;
- uses exact physical branch transport only when authoritative metadata is absent;
- proves forward/reverse consistency against the per-face physical lattice frame;
- records crossed source edges through canonical source-edge indexing;
- retains strict fail-closed transition lookup and reciprocal quarter-turn validation whenever metadata is present;
- preserves chart/component/sheet/family/sign/route provenance, orientation, directed ownership, and one-cell-to-one-quad materialization;
- contains no fixture-specific condition.

### Last runtime authority

The last executed artifact remains the preceding Gate 2 package:

| Fixture | Result | Traces | Arrangement | Output quads |
|---|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 0 |
| Seam | **pass** | 256 | 65 | 64 |
| Close sheets | fail | 158 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 |

The new artifact must not be described as successful until artifact-only execution proves it.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Regression_Restoration_Artifact_Only_Test_Benchmark_Plan.md`.

Required order: verify the artifact and 44 checksums; run plane first; run seam second; continue close sheets, cylinder, bunny, and vase; run non-overlapping default suites and bounded determinism processes; rebuild nothing and edit nothing.

Gate 1 restoration requires direct validated plane output with no generic completion signature. The implementation is accepted only if the seam also retains direct reciprocal-transition output.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Regression_Restoration_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Regression_Restoration_Artifact_Only_Test_Benchmark_Plan.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. latest Test + Benchmark report
6. next Code + Build plan
7. latest runtime summary
8. `tests/TESTING_STRATEGY.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`
10. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Empty prescribed-field metadata is absence, not incomplete authoritative metadata; exact planar physical transport may prove the route, while present metadata remains strict and fail-closed.
- Plane and seam must share one general physical transport contract: zero-turn inference when metadata is absent, reciprocal quarter-turn transport when it is present.
- Analytic fixtures isolate contracts but real bunny/vase fixtures remain mandatory.
- Fixture hashes/topology prevent synthetic simplification.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are closeout evidence, not functional correctness.
- `PRE_TEST` preserves compile-only boundaries.

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
2. Retain only the live handoff, latest report, next executable plan, current authority, latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
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

Every completed turn ends with a new top-level PR #8 comment after all documentation and PR metadata updates. That comment is the final repository write.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
