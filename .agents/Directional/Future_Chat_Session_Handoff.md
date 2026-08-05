# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB31 artifact-only R2E3 validation is complete against exact source `571ff9095ec06a8931fc54aafe1a70a38f80b4a1` and artifact `8918054686`.

R2E3 closes `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence`, but planar, interior-hard-rail, and open-cylinder boundary topology remain invalid. The complete suite is **595/623** with 28 failures, matching P5-TB29. The next turn is **P5-R2E4 authoritative boundary-node rotational-system Code + Build**. Do not advance to R2F or R3.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB31_Artifact_Only_R2E3_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E4_Boundary_Node_Rotation_Code_Build_Plan.md`
5. `benchmark-results/p5-tb31-summary.json`
6. `.agents/Directional/Milestone_G_P5_R2E3_Code_Build_Report.md`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB31 authority

- exact tested source: `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`;
- workflow event commit: `2d1d616eaf6e5be025e1a190b995172954d3f102`;
- artifact: `8918054686`, SHA-256 `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`;
- reviewed/applied diff SHA-256: `f7a26c3b3869a59247532e86f4468e0d17bce7caa72cf31a5c315b620fac1ff3`;
- source status empty; checksums **48/48**; files **49**; fixtures **26**; submodules **9**; target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- no configure, build, relink, patch, regeneration, or source modification during validation;
- evidence bundle: `directional-p5-tb31-8918054686-evidence.zip`, SHA-256 `14dcdbaddab36cf4175bcbec85175af3ce5e0f488ac6008e50f7b82a36929a72`.

## Runtime summary

- source-chart R1 **11/11**;
- source validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **11/14**;
- Milestone D **5/7**;
- Phase 14–18 **233/242**;
- Phase 16 **43/45**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite **595/623**, 28 failures, **142.550 s**;
- sampled RSS at least **169,268 KiB**; exact max unavailable because the outer wrapper ended while the child continued to normal completion.

Relative to P5-TB30, exactly one failure closes and no new failure appears.

## Earliest remaining producer

R2E3 forces the exterior successor and swaps the displaced generic target to the generic owner of the forced exterior target. This guarantees cardinality in simple cases but does not construct the canonical cyclic rotational system.

Consequences:

- planar: predecessor bijection passes, then orbit audit fails `RepeatedEdgeCycle`;
- interior hard rail: local target swap fails `BoundaryLocalPermutationConflict`;
- open cylinder: a bounded orbit is rejected as `NonDiskCell`;
- direct seam, close sheets, and cylinder still publish zero arrangement cells.

P5-R2E4 must discard all generic local assignments at affected boundary nodes and rebuild every local incoming-to-outgoing mapping directly from canonical cyclic ray and sector order. Do not patch missing predecessors, weaken orbit/disk validation, or merge cells after extraction.

## First actions for P5-R2E4

1. Confirm branch descends from this documentation handoff and contains one base workflow and no payload directory.
2. Inspect canonical boundary aliases, ordered wedges/rays, the R2E3 target transposition, orbit analysis, and disk audit.
3. Build one canonical rotational-system inventory per boundary node and R1 fan.
4. Identify exactly one exterior sector per authoritative boundary-loop occurrence and all hard-rail-separated interior sectors.
5. Reconstruct the complete local successor map transactionally from that rotational system.
6. Preserve the passing paired boundary-twin identity and orientation hash.
7. Keep bunny fan, FlowRep, simplification, completion, cache, optimizer, fallback, and lineage out of scope.
8. Compile exactly the four approved targets and execute no project binary.
9. Remove the bounded workflow and payloads after artifact upload.

## End-of-turn PR comment requirement

At the end of every Code + Build, Test + Benchmark, and optional Review turn, post a **new final comment on PR #8** after all documentation commits. The comment must identify the exact evidence/source commit, turn result, remaining gates, authoritative next-turn plan, and final branch/documentation head. It must be the final repository write of the turn.

## Mandatory working-branch hygiene

At Code + Build turn start and end, remove superseded workflows, markers, patch fragments, patch READMEs, transfer files, and generated build artifacts. Retain only the base workflow plus one bounded active workflow/payload while remote work runs. Remove the bounded workflow and payloads immediately after artifact upload. Generate checksum manifests outside the package and never include a manifest in its own input set.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
