# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-TB33 artifact-only R2E5 validation**.
- Next turn: **P5-R2E6 authoritative boundary fan-sector cover Code + Build**.
- R2 remains open. Do not advance to R2F or R3.

## P5-TB33 authority

- Exact tested source: `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`.
- Artifact: `8934315316`, SHA-256 `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`.
- Package manifest **48/48**; files **49**; fixtures **26**; recursive submodules **9**.
- Cleaned source: one base workflow and zero payloads.
- No configure, build, relink, patch, regeneration, fixture modification, or source modification.
- Evidence: `directional-p5-tb33-8934315316-evidence.zip`, SHA-256 `1a4f1a780e29f09e0d93f75f0c01a818358029d6044839f32ffdff53aa340ec7`.

## Results

- [x] source-chart R1 **11/11**;
- [x] source validator **6/6**;
- [x] recovery **9/9**;
- [x] feature/barrier **8/8**;
- [x] graph-dependent **5/6**, bunny only;
- [ ] R2 focused **12/16**;
- [ ] Milestone D **5/7**;
- [ ] Phase 14–18 **240/244**;
- [ ] Phase 16 **44/47**;
- [x] Phase 17 **26/26**;
- [x] Phase 18 **57/57**;
- [ ] Phase 20 **46/48**;
- [ ] complete suite **602/625**, 23 failures, 84.132 s, max RSS 280,640 KiB;
- [ ] direct production cases **0/4**.

## Accepted closure

- [x] degree-two boundary sectors publish one exterior and one bounded disk;
- [x] exact exterior and complementary interior successor mappings;
- [x] all 21 P5-TB32 regressions restored;
- [x] six pre-existing P5-TB31 Phase 17 failures closed naturally;
- [x] source-row and whole-orientation incidence identity preserved;
- [x] no validator weakening or fallback substitution.

## Required next work: P5-R2E6

Follow `.agents/Directional/Milestone_G_P5_R2E6_Boundary_Fan_Sector_Cover_Code_Build_Plan.md`:

- [ ] retain the passing R2E5 degree-two branch;
- [ ] replace the one-common-wedge requirement for `rayCount >= 3`;
- [ ] construct a complete non-overlapping cover of authoritative R1 fan sectors;
- [ ] add exactly one exterior sector from ordered source-boundary continuation;
- [ ] use hard rails as fan-sector separators, never crossings;
- [ ] require every incoming and outgoing ray exactly once;
- [ ] add typed `BoundaryFanSectorCoverConflict` evidence;
- [ ] close the higher-valence non-disk contract and interior-hard-rail rotational conflict;
- [ ] preserve planar, cylinder, bunny, degree-two, orientation, ownership, bridge, support, nested, nonmanifold, pinched-fan, and close-sheet authority;
- [ ] compile only the four approved targets and execute no project binary.

## Standing requirements

Every completed Code + Build, Test + Benchmark, and optional Review turn must end with a new final PR #8 comment after all documentation commits. Code + Build turns must remove bounded workflows and payloads after artifact upload.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB33_Artifact_Only_R2E5_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E6_Boundary_Fan_Sector_Cover_Code_Build_Plan.md`
- `benchmark-results/p5-tb33-summary.json`
- `.agents/Directional/Milestone_G_P5_R2E5_Code_Build_Report.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `TODO`

P5 remains open.
