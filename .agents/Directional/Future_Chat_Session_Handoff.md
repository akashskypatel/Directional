# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB35 artifact-only R2E7 validation is complete against exact source `31c8d9a212f649df7c70fe9291d1fac8c4db7132` and artifact `8938299309`.

R2E7 preserves the degree-two and genuine four-disk higher-valence contracts. It does not change the P5-TB34 failure set. The hard-rail fixture is now narrowed to `embeddingValid == false`: incidence, directed side pairs, orientation, disk, boundary-loop, Euler, cell-count, ownership, and distinct bounded rail-twin owners all pass. Planar still fails `BoundaryFanSectorCoverConflict` before publication, and Phase 17 remains **20/26** through invalid upstream arrangement inputs.

The next turn is **P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build**. Do not advance to R2F or R3.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB35_Artifact_Only_R2E7_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E8_Canonical_Boundary_Corner_Sector_Code_Build_Plan.md`
5. `benchmark-results/p5-tb35-summary.json`
6. `.agents/Directional/Milestone_G_P5_R2E7_Code_Build_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E7_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB35 package authority

- artifact SHA-256 `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`;
- exact source `31c8d9a212f649df7c70fe9291d1fac8c4db7132`;
- workflow event `7d5450cb6411722818844548de59a09c8f4451d5`;
- reviewed/applied diff `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`;
- source status empty;
- checksums **48/48**; files **49**; fixtures **26**; recursive submodules **9**;
- target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- no configure, build, relink, patch, regeneration, source/test/build-logic modification, or fixture modification;
- evidence `directional-p5-tb35-8938299309-evidence.zip`, SHA-256 `c9e4a77b2b9709921a445fb8295a6eff16e62268325a844c1a886deff08e595b`.

## Runtime summary

- source chart **11/11**;
- source validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 14–18 **235/244**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite **597/625**, 28 failures, XML **206.053 s**.

The complete suite was started exactly once. The outer wrapper detached; the packaged process continued to normal XML and Google Test completion and was not rerun. Exact max RSS and wrapper exit code are unavailable. The failure set is identical to P5-TB34.

## Earliest producer diagnosis

### Planar

R2E7 permits cyclic vector wrap but still begins from `intrinsicCandidateNext` and `intrinsicSuccessorWedge`. It therefore validates one generic preselected relation rather than directly constructing the complete authoritative R1 corner-sector cover. Planar still fails typed `BoundaryFanSectorCoverConflict` before publication.

P5-R2E8 must enumerate all cyclic adjacent pairs directly from each canonical R1 fan, canonicalize exact source-chart corner records, remove exactly the independent exterior pair, and require one authoritative record per local incoming and target. Generic intrinsic successor arrays are consistency evidence only, not complete boundary-sector authority.

### Hard rail

The hard rail now produces one exterior and two bounded disk cells with complete ownership and distinct bounded owners for its twins. Only embedding and aggregate topology fail.

P5-R2E8 must derive the two rail-side sectors from exact incident source-face/chart corners and prove a common ownership/chart root for every predicted bounded rail-side orbit before publication. `leftScore` may only confirm exact face-local authority; it must not select the side.

### Out of scope for P5-R2E8

- cylinder incidence/zero direct arrangement inventory;
- bunny intrinsic singularity-fan embedding;
- Phase 17 implementation;
- completion, optimizer, fallback/recovery, memory, and FlowRep.

## First actions for P5-R2E8

1. Confirm branch hygiene: only the base workflow and zero payloads.
2. Preserve the exact degree-two branch and genuine four-disk partition.
3. Replace boundary-node use of generic intrinsic successors with direct canonical R1 corner-sector inventory.
4. Remove the exact exterior pair once and only once.
5. Fail typed on non-identical duplicate incoming/target corner claims; do not select by count/order/frequency or subset search.
6. Derive hard-rail sides from the two exact incident source faces/charts.
7. Audit common chart/ownership roots for the predicted bounded rail-side orbits.
8. Leave every downstream validator unchanged.
9. Compile exactly the four approved targets and execute no project binary.
10. Remove the bounded workflow and payload after artifact upload.

## End-of-turn PR comment requirement

After all documentation commits, post a **new top-level PR #8 comment** identifying exact source/artifact authority, result, remaining gates, next-turn plan, and final documentation head. It must be the final repository write.

## Preserved prohibitions

- no validator weakening;
- no generic successor choice as complete boundary-sector authority;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
