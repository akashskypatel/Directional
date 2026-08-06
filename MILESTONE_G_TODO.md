# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-TB41 artifact-only R2E13 Test + Benchmark**.
- Next turn: **P5-R2E14 two-sided exterior-root authority and chart-seam interval normalization Code + Build**.
- R2 remains open. Do not advance to R2F or R3.

## P5-TB41 authority

- Exact tested source: `39b60e66d72f412c1d648ffef213beca93bd19dc`.
- Artifact `8953600942`, SHA-256 `9144cde751377199a8df135ac0871e75e65c44b5d8efce07ea42a0732ae6f7d1`.
- Manifest **20/20**; package files **21**; recursive submodules **9**; staged fixtures **26**; source status empty.
- Evidence archive SHA-256 `20d4f87c21c3789a1ade6eb8da84fca69b5cff6dc83bc2808bee6848bf89d825`, entries **140**, size **358,161 bytes**.
- No configure, rebuild, relink, patch, regeneration, implementation/test/fixture/validator/workflow/build change, or binary replacement occurred.

## P5-R2E13 runtime disposition

- [x] artifact/source authority verified;
- [x] target diagnostics are deterministic and expose derived failures;
- [x] planar inserts **3** canonical pairs and excludes one exterior pair;
- [ ] planar interval valid — fails `InvalidOrientedInterval(8)` at tuple `3/5/4/9` with zero cyclic-wrap sectors;
- [ ] hard-rail exterior record inserted — fails `ExteriorPairMismatch(2)` at tuple `1/7/6/1` with zero pairs/exclusions;
- [ ] planar wrap/Euler-one topology restored;
- [ ] hard-rail separator/root/orbit/embedding topology restored;
- [ ] Phase 17 restored — remains **20/26**;
- [ ] R2E13 accepted — **not accepted**.

## Runtime results

- source chart + validator **17/17**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- complete split inventory **597/625**, 28 failures, exact P5-TB40 failure set.

A cumulative-state process again reached the P27 bunny case after prior suite state and was externally terminated. This is performance/nontermination evidence only; the split inventory is correctness authority.

## Required P5-R2E14 work

- [ ] retain exact source and target projected roots separately for the excluded exterior pair;
- [ ] permit distinct endpoint roots when an authoritative hard rail separates boundary-side chart components;
- [ ] reconcile each exterior endpoint against its own exact chart/root/side and fail closed on contradictory same-chart claims;
- [ ] keep one exact common root for every non-exterior pair;
- [ ] retain node-level canonical pair authority;
- [ ] normalize an already-authoritative pair's chart-seam interval from exact circular adjacency rather than raw fan-vector index;
- [ ] reject ambiguous wraps, third-ray intrusion, and spans outside the chart wedge;
- [ ] preserve all pair-cover, predecessor, hard-rail, orbit, embedding, Euler, ownership, and topology gates;
- [ ] leave Phase 17, P27, bunny, cylinder, FlowRep, completion, fallback/recovery, fixtures, and validators unchanged;
- [ ] compile exactly the four approved targets without executing a project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB41_Artifact_Only_R2E13_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E14_Two_Sided_Exterior_Root_Chart_Seam_Interval_Code_Build_Plan.md`
- `benchmark-results/p5-tb41-summary.json`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- durable design, reorientation, remediation, and workflow-policy documents
- `TODO`

Every completed turn ends with a final top-level PR #8 handoff comment after all documentation and PR metadata writes.

P5 remains open.
