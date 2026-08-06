# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05
**Repository:** `akashskypatel/Directional`
**Base:** `surface_cell_quad`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Current checkpoint

P5-TB41 artifact-only R2E13 Test + Benchmark is complete.

P5-R2E13 is **not accepted**. Runtime counts and the complete failure set are unchanged from P5-TB40, but the enhanced diagnostics identify two distinct first producers:

- planar: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `3/5/4/9`, canonical pairs **3**, exterior exclusions **1**, fan-sector nodes **1**, cyclic-wrap sectors **0**;
- interior hard rail: `BoundaryFanSectorCoverConflict / ExteriorPairMismatch(2)`, tuple `1/7/6/1`, canonical pairs **0**, exterior exclusions **0**.

Each target was executed three times independently with byte-identical logs. The next turn is **P5-R2E14 two-sided exterior-root authority and chart-seam interval normalization Code + Build**. R2 remains open. Do not advance to R2F or R3.

## P5-TB41 authority

- exact tested source: `39b60e66d72f412c1d648ffef213beca93bd19dc`;
- workflow event commit: `45a4c1031cccd3e814b2cf8e24209662dbfdae87`;
- workflow run/job: `31064914809` / `92500525659`;
- artifact: `8953600942`;
- artifact SHA-256: `9144cde751377199a8df135ac0871e75e65c44b5d8efce07ea42a0732ae6f7d1`;
- manifest **20/20**; package files **21**; recursive submodules **9**; staged fixtures **26**; source status empty;
- evidence archive: `directional-p5-tb41-8953600942-evidence.zip`;
- evidence SHA-256: `20d4f87c21c3789a1ade6eb8da84fca69b5cff6dc83bc2808bee6848bf89d825`;
- evidence entries **140**, size **358,161 bytes**.

Only packaged binaries were executed. No configure, rebuild, relink, patch, regeneration, implementation/test/fixture/validator/workflow/build change, or binary replacement occurred.

## Runtime results

- source chart + validator: **17/17**;
- recovery authority: **9/9**;
- feature/barrier: **8/8**;
- graph-dependent: **5/6**;
- R2 focused: **13/16**;
- Milestone D: **5/7**;
- Phase 16: **45/47**;
- Phase 17: **20/26**;
- Phase 18: **57/57**;
- Phase 14–18: **235/244**;
- Phase 20: **46/48**;
- complete non-overlapping split inventory: **597/625**, 28 failures, exact P5-TB40 failure set.

The split inventory consists of **596/623**, isolated P27 matrix **0/1**, and isolated P27 bunny parameter **1/1**. A cumulative-state process again reached the P27 bunny `BEFORE_PIPELINE` marker after prior suite state and was externally terminated. This is performance/nontermination evidence only; timeout or termination is not correctness evidence.

## Direct production evidence

All direct processes used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

- plane: five measured runs, median **0.012994 s**, deterministic lineage, `9 / 9 / 12`, `success=false` at completion/output validity;
- multi-face seam: five runs, median **0.013283 s**, deterministic lineage, `0 / 0 / 0`, `SideSubdivisionRepair:InvalidInputIncidence`;
- close sheets: five runs, median **0.020511 s**, same disposition;
- cylinder: five runs, median **0.133303 s**, same disposition;
- bunny run 1: **21.659158 s**, **272,052,224 B** peak, `0 / 0 / 0`;
- bunny run 2: **21.925100 s**, **272,048,128 B** peak, identical lineage and disposition.

## Source-supported next producers

These are source-supported inferences from deterministic runtime evidence and the exact packaged source. Do not present them as additional emitted runtime fields.

### Hard-rail exterior root authority

R2E13 projects source and target boundary rays independently, then requires their transition roots to be equal before inserting the excluded exterior pair. At a boundary vertex separated by an authoritative interior hard rail, the incident boundary-side charts may correctly have distinct transition roots. The exterior continuation is source-boundary topology and should retain source-side and target-side projected roots independently.

P5-R2E14 must preserve a common authoritative boundary entity/loop and exact `+1/-1` sides, reconcile each endpoint against its own chart/root, and keep non-exterior pairs on one exact common root. It must not select, merge, rank, or count roots.

### Planar chart-seam interval authority

Planar proves that pair inventory and explicit exterior exclusion now succeed. The remaining non-exterior pair fails `InvalidOrientedInterval` with zero wrap evidence. Generic inventory currently assigns `cyclicWrap` from raw fan-vector index, while chart resolution needs an exact circular chart-seam interval.

P5-R2E14 must keep pair existence node-level and normalized. For an already-authoritative pair, chart evidence may normalize its oriented interval only when the source and target are the unique adjacent rays across the chart seam, with no third-ray intrusion and a span inside the chart wedge. Chart-local evidence must not create or select a pair.

## Retained authoritative documentation

Only current and durable documents remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md`;
2. `Milestone_G_P5_TB41_Artifact_Only_R2E13_Test_Benchmark_Report.md`;
3. `Milestone_G_P5_R2E14_Two_Sided_Exterior_Root_Chart_Seam_Interval_Code_Build_Plan.md`;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

## Retained benchmark results

- `baseline_synthetic_grid_2.json`;
- `p5-tb41-summary.json`.

## Read first for P5-R2E14

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB41_Artifact_Only_R2E13_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E14_Two_Sided_Exterior_Root_Chart_Seam_Interval_Code_Build_Plan.md`
6. `benchmark-results/p5-tb41-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E14 objective

1. Retain exact source and target projected roots separately for the excluded exterior pair.
2. Permit distinct endpoint roots only when exact boundary-side chart authority proves them; do not select or merge roots.
3. Reconcile generic exterior evidence against the corresponding endpoint chart/root/side.
4. Keep every non-exterior pair on one exact common transition root.
5. Preserve node-level canonical pair inventory as pair-existence authority.
6. Normalize an existing pair's chart-seam interval from exact circular adjacency, not raw fan-vector index.
7. Reject ambiguous seam wraps, third-ray intrusion, and spans outside the chart wedge.
8. Preserve complete incoming/target cover, predecessor, separator, orbit, embedding, Euler, ownership, and topology gates.
9. Add only non-weakening diagnostic context where needed.
10. Compile exactly the four approved targets without executing a project binary.

## Lessons from P5-TB41

- Improved diagnostics can prove that an upstream producer advanced even when the overall failure set is unchanged.
- An excluded exterior continuation may need endpoint-specific chart roots; forcing one interior root can erase valid hard-rail separation.
- Pair ownership and chart geometry are separate authorities: node-level evidence establishes the pair, while chart evidence resolves its oriented interval.
- A wrap flag based on container position is not equivalent to exact circular adjacency on a source chart.
- Fixture staging must be byte-identical and executable-relative before authoritative artifact-only results are recorded.
- A complete split inventory remains correctness authority when cumulative-state execution stalls.
- Direct `success=false` with a clean process exit remains a product failure.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the **start and end of every turn**, inspect `.github/workflows` and all temporary workflow-support locations, including temporary trigger files, transfer files, patch/payload directories, and generated build artifacts.
2. Remove stale bounded or turn-specific workflow files before beginning work so an old workflow cannot run, conflict with the current turn, or generate unrelated errors.
3. During a remote compile turn, retain only the approved durable base workflow files plus at most one bounded workflow and the exact temporary payloads required for the current turn.
4. Immediately after the current artifact and logs are published and verified, remove the bounded workflow, its trigger, and its temporary payload or transfer files.
5. The final branch state for every turn must contain only approved durable base workflows and no stale temporary workflow payloads or generated build artifacts.
6. Do not remove a durable base workflow dependency that is explicitly consumed by an approved retained workflow. Distinguish active base-workflow inputs from stale turn-specific payloads before deleting anything.

### Documentation and test-result cleanup

1. At the **end of every turn**, review `.agents` and `benchmark-results` and remove stale or superseded documents, plans, reports, closure notes, evidence indexes, test results, benchmark results, and machine summaries.
2. Retain only durable project authority and the minimum current turn chain required to resume expertly: the live handoff, the latest completed authoritative report, the next executable plan, current source/package authority, the latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Update every retained document so it references only files that still exist after cleanup.
4. Do not keep duplicate historical snapshots merely for provenance; Git history and the PR conversation are the historical archive.
5. Never delete the latest authoritative evidence or next-turn instructions before their replacement is committed and verified.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly instructs its removal or replacement.**
2. Handoff edits must be additive or narrowly corrective by default. Preserve all existing procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Before committing a handoff update, compare the new document with the previous version and verify that every pre-existing mandatory instruction remains present and materially unchanged.
4. When a new instruction appears to conflict with an existing mandatory instruction, preserve both, identify the conflict explicitly, and request user direction rather than deleting either instruction.
5. Documentation cleanup does not authorize removal of mandatory handoff rules. Mandatory rules remain even when older reports, plans, and results are deleted.

## End-of-turn requirement

Every completed Code + Build, Test + Benchmark, optional Review, or documentation-maintenance turn ends with a **new top-level PR #8 comment** after all documentation and PR metadata updates. That comment must be the final repository write.

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
