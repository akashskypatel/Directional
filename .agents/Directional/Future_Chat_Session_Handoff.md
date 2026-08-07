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

This rule was triggered for Gate 1. The mandatory Review is now complete and selected **Outcome B — bounded producer replacement proof**. A third isolated phase-transition predicate repair remains prohibited.

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform phase-front plane — **active; authoritative producer-boundary replacement proof authorized**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The mandatory **Gate 1 Producer Architecture Review** is complete. It made no production source, test, fixture, validator, fallback, recovery, or build-system change.

### Exact runtime authority reviewed

- tested source: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- payload cleanup: `591ada601843237a709d2d6e133a438ca403f042`;
- tested artifact: `directional-g1-live-transition-local-build-artifact.zip`;
- artifact SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- internal checksums: 45/45;
- evidence archive: `directional-g1-live-transition-artifact-only-test-evidence.zip`;
- evidence SHA-256: `99a4922767d567830f202b440504f2b48d07fdb02bb117668baf846e7eeb9b64`;
- evidence files: 118;
- explicit source-vertex/topology tests: 4/4;
- direct acceptance: 1/6;
- non-overlapping total: 305/321.

Runtime matrix:

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 12 | 0 |
| Seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, output hash `a8972efd7c4900a4`.

## Architecture review findings

### Proven control-flow divergence

The successful Gate 1 parent `aea10409c73c490b92f78760b73191641ef823c6` used geometry-only phase-front construction. The generic seed/trace/proposal producer already existed but stayed latent because the plane phase front succeeded.

Gate 2 commit `21f081b330418a0f34709f61d857f54a03d2fd48` made the phase-front producer consume finalized matching, effort, and edge-transition metadata. This was necessary for seam transport, but `build_surface_cell_network()` still treats every `phaseFront.succeeded == false` identically and launches the generic producer.

Therefore two distinct semantic states are collapsed:

- authoritative producer is not applicable;
- authoritative producer is applicable but rejects its input.

Later completion/output-validation may overwrite the typed phase-front first-invalid diagnostic. This is why local phase-front repairs can alter internal hashes while the exact plane remains on the same 106/9/12 generic path.

### Production test gap

The passing vertex-fan tests reconstruct a geometrically equivalent plane with different indexing and inject convenient state directly. The exact committed `plane.obj` + `plane.rawfield` production route additionally consumes finalized matching/transitions, adaptive target size, source component/sheet labels, feature/relief state, and pipeline tracing options. Narrow tests remain valid contract tests but are not production acceptance authority.

### Relief-barrier semantic mismatch

The tracing option contract states relief separatrices are guidance until embedded. Generic tracing honors `reliefBarriersEmbedded`. Current phase-front transport rejects `reliefBarrierEdges` unconditionally. This is a proven authority inconsistency; it is not claimed to be the exact first current plane rejection because the final artifact did not preserve that first phase-front reason or serialize exact barrier membership.

## Selected architecture

The next implementation must introduce a first-class authoritative producer disposition equivalent to:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: the representation does not cover this topology; another explicitly selected producer may run.
- `Produced`: authoritative cells/fronts are complete; direct one-cell-to-one-quad materialization.
- `Rejected`: the producer was applicable but an invariant failed; preserve the typed reason and stop this backend request. **Do not launch generic seeds/traces/proposals.**

Gate 1 plane and proven Gate 2 seam are within the current applicable domain. Later nonplanar/periodic/singular cases may remain `NotApplicable` until their representation is extended.

The producer must consume first-class source topology, finalized cross field, target-size vector, source component/sheet labels, hard-feature state, relief state plus `reliefBarriersEmbedded`, authoritative rails/features where applicable, and exact tracing/transport options.

Preserve ordinary shared-edge transport, ordered source-vertex fans, reciprocal quarter-turn transport, complete ordered route provenance, component/sheet ownership, source-normal orientation, and one accepted cell → one quad.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Code_Build_Plan.md`.

Required opening declaration:

```text
Active design gate: Gate 1 — uniform phase-front plane
Earliest failing fixture: plane__surface_cells
Missing design contract: authoritative producer applicability, production, and rejection must be distinct first-class outcomes; an applicable producer rejection may not silently substitute the generic tracing/completion producer
Smallest general implementation change: replace the implicit phaseFront.succeeded/fall-through selection with an explicit authoritative producer disposition and preserve immutable rejection authority
Observable material-progress condition: exact committed plane production coverage proves the authoritative producer outcome before generic stages, and a Rejected plane cannot generate the prior 106/9/12 generic completion path; preferred closure is direct plane success while preserving seam direct success
Explicitly deferred work: close-sheet completion, cylinder holonomy, singularities, adaptive later-gate topology, bunny/vase success, performance, cache/memory tuning, validator timing, historical completion cleanup
```

The next Code + Build turn must:

1. implement explicit `NotApplicable / Produced / Rejected` producer disposition;
2. determine applicability from general topology/field state before execution, never fixture identity;
3. prevent `Rejected` from generating generic seeds/traces/proposals;
4. retain immutable typed rejection as first-invalid authority;
5. align relief transport with `reliefBarriersEmbedded`;
6. add exact committed `plane.obj` + `plane.rawfield` producer-level production-route coverage using production preprocessing;
7. retain all narrow source-vertex tests unchanged in strength;
8. preserve the direct deterministic seam contract;
9. keep bunny/vase mandatory integrity and direct observations;
10. compile the approved seven targets and execute no generated project binary;
11. package an immutable artifact for a following plane-first artifact-only Test + Benchmark turn.

GitHub workflow operations are normal again. An authorized Code + Build turn may use GitHub Actions for configure/compile/link and artifact production under `.agents/Directional/GitHub_Workflow_Policy.md`. Test + Benchmark turns remain artifact-only and do not rebuild.

Minimum architectural progress in the following artifact is disappearance of silent 106/9/12 substitution after an authoritative `Rejected` result. Gate 1 closes only through direct deterministic valid plane output while retaining seam direct success.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Live_Transition_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
- `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`
- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
6. `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Code_Build_Plan.md`
7. latest Test + Benchmark report
8. latest runtime summary
9. `tests/TESTING_STRATEGY.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`
11. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

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
- Real bunny/vase fixtures remain mandatory and may not be simplified or bypassed.
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
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
