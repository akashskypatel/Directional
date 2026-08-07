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
2. G1 uniform phase-front plane — **regressed; active restoration gate**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The Gate 2 mandatory-fixture artifact-only Test + Benchmark turn is complete.

### Exact authority

- source commit: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- payload cleanup: `98fe525bb46f348cddcad91b0525353796b9e061`;
- input artifact SHA-256: `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`;
- artifact checksums: 45/45;
- evidence archive SHA-256: `8762750ffc13c339e44ce0a2ffac8639f456d16cacc480b7da44b2fedc0ed251`;
- evidence checksums: 84/84.

No configure, compile, relink, regeneration, source/test/fixture/manifest/validator edit, or discovery regeneration occurred. A runtime-only `bin/test-data -> ../test-data` symlink corrected the artifact's packaged fixture lookup layout without changing packaged bytes.

### Mandatory direct evidence

| Fixture | Result | Traces | Arrangement | Completed/output quads | First invalid producer |
|---|---:|---:|---:|---:|---|
| Plane | fail | 106 | 9 | 12 / 0 | `completion/output-validation:AggregateCompletionValidationFailure`; 15 validation failures |
| Seam | **pass** | 256 | 65 | 64 / 64 | none |
| Close sheets | fail | 158 | 0 | 0 / 0 | completion |
| Cylinder | fail | 732 | 0 | 0 / 0 | completion |
| Bunny | fail | 80,862 | 0 | 0 / 0 | completion |
| Vase | fail | 116,922 | 0 | 0 / 0 | completion |

All requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, no source-grid recovery. Seam output is 81 vertices, 64 pure quads, zero validation failures, `CompletedSurfaceCells`, and hash `a8972efd7c4900a4`.

Plane/seam/close/cylinder were deterministic across three processes. Bunny/vase were deterministic across two. The seam is real G2 progress, but the plane regression immediately reactivates G1.

### Default suites

- direct 1/6;
- remaining producer 78/79;
- completion 154/164;
- validation 60/60;
- compiled API 8/8;
- non-overlapping total 301/317.

The producer failure is the scheduler-sensitive validator timing ratio. The ten completion failures are unchanged historical/downstream tests. Neither displaces the direct plane regression.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Regression_Restoration_Code_Build_Plan.md`.

Required objective: restore the constant prescribed-field plane to the authoritative phase-front path while preserving reciprocal quarter-turn seam transport and its 64-quad deterministic output. Do not special-case fixtures or route plane through generic completion.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Cross_Chart_Mandatory_Fixtures_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Regression_Restoration_Code_Build_Plan.md`
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
- Exact reciprocal chart transport can succeed on the seam while a zero-turn prescribed-field route still regresses; both must share one general physical transport contract.
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
