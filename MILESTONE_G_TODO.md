# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`.
- Tested artifact: `8876934846`.
- Completed turn: **P5-TB18 artifact-only test and benchmark**.
- Next turn: **P5-CB108 through P5-CB116 code + compile-only build**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB107 — earlier implementation and compile/package turns.
- [x] P5-TB11–P5-TB18 — runtime diagnosis through the canonical-ownership
      resource regression.
- [ ] P5-CB108 — compact exact ownership registry.
- [ ] P5-CB109 — unlabeled intrinsic ownership derivation.
- [ ] P5-CB110 — ownership through simplification.
- [ ] P5-CB111 — prepared-domain/parity producer repair.
- [ ] P5-CB112 — route validation and exact reuse.
- [ ] P5-CB113 — invalid-midpoint precondition.
- [ ] P5-CB114 — canonical cylinder DCEL.
- [ ] P5-CB115 — completion/optimizer/output validity.
- [ ] P5-CB116 — regression and compile/package gate.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-TB18 evidence

- artifact SHA-256: `ba06737ab313f30e23c74f402114649ee2c9f9d7c3a7177c7e0ba3328749df47`;
- source status empty;
- checksums **39/39**;
- fixture files **26**;
- Phase 14–18 **223/232**;
- Milestone D **4/7**;
- Milestone E **23/26**;
- Phase 20 **47/48**;
- complete-minus-blocked **573/593**;
- full 596-test execution blocked by random-bunny resource failure;
- face-edge bunny: 98.613553 s, 2,513,285,120 B RSS,
  `InvalidArrangementDomainIdentity;firstPatch=2`;
- smooth bunny: SIGKILL/137 at 65.60 s and 3,801,161,728 B RSS;
- all eight direct production cases fail;
- reuse/recompute remains `0/0`;
- no fallback/recovery.

## Authoritative root causes

1. Unlabeled arrangement calls create no chart roots and invalidate embedding.
2. Full ownership-class membership is duplicated on every cell, producing
   `O(cells × component faces)` memory and multi-gigabyte copies.
3. Patch early returns can lose typed domain failure evidence.
4. The midpoint fixture removes charts needed by an earlier edge.
5. Route repair/cache reuse and optimizer rollback remain incomplete.

## Next-turn closure requirements

- store class membership once per complex and compact per-cell keys;
- restore Phase 16, Phase 17, and Milestone D without validator weakening;
- provide typed first-invalid prepared-domain evidence and repair its producer;
- reach real positive reuse and the intended midpoint failure;
- validate the cylinder before candidate extraction;
- preserve valid completed output through optimization;
- compile/package the four required targets only, without executing binaries;
- retain mandatory workflow logs under `if: always()`.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB18_Canonical_Ownership_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb18-summary.json`
- `.agents/Directional/Milestone_G_P5_Post_TB18_Ownership_Compaction_Topology_Output_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
