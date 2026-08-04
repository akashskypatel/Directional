# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Exact implementation and compiled source:
  `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`.
- Compile-only workflow run: `30867891341` — **success**.
- Compiled artifact: `8876934846`.
- Completed turn: **P5-CB99 through P5-CB107 code + compile-only build**.
- Next turn: **P5-TB18 artifact-only test and benchmark**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB98 — earlier ownership, topology, liveness, rail,
      fixture, output, memory, and packaging turns.
- [x] P5-TB11–P5-TB17 — earlier runtime diagnosis turns.
- [x] P5-CB99 — canonical physical cell-side ownership across adjacent local
      source charts, with exact per-source-face chart records.
- [x] P5-CB100 — canonical ownership propagated through simplification,
      hashing, and transactional merges.
- [x] P5-CB101 — parity/subdivision preflight consumes committed canonical
      ownership and preserves exact rollback evidence.
- [x] P5-CB102 — completion ownership and reuse dependency identities use the
      canonical ownership contract.
- [x] P5-CB103 — malformed-midpoint fixture reaches its intended valid common-
      chart precondition before temporary mutation.
- [ ] P5-CB104 — canonical open-cylinder DCEL runtime closure.
- [ ] P5-CB105 — production-output earliest-invalid-producer runtime closure.
- [ ] P5-CB106 — quantitative peak-RSS reconciliation closure; source accounting
      extension is implemented, but the 75% gate is unverified.
- [x] P5-CB107 — regression sources and exact four-target compile/package gate.
- [ ] P5-TB18 — artifact-only runtime verification of the P5-CB99–P5-CB107
      checkpoint.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-CB107 artifact integrity

- Artifact ID: `8876934846`.
- Name: `surface-cell-p5-cb107-github-source-linux-release`.
- Exact source commit: `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`.
- Archive SHA-256:
  `ba06737ab313f30e23c74f402114649ee2c9f9d7c3a7177c7e0ba3328749df47`.
- Mandatory workflow-log artifact: `8876935182`.
- Log archive SHA-256:
  `465aad3a957b99fdb8e7bf76b2040facc25b1ea1b2c00bfdca1d58990f1498dd`.
- Packaged source status: empty.
- Recursive packaged checksums: **39/39**.
- Packaged fixture files: **26**.
- Compiled targets:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.
- No test, benchmark, custom mesh, help/list command, or compiled project binary
  executed during the code/build turn.

## Implemented ownership correction

The previous source model conflated a per-face `localSheetByFace` chart label
with the identity of a physical cell side. The new source checkpoint stores and
uses three distinct concepts:

1. connected source component;
2. canonical physical cell-side ownership class, derived from intrinsic stitched
   DCEL/source adjacency;
3. exact sorted `(component, source face, local sheet)` records for every cell.

This permits a valid cell to span adjacent per-face local chart IDs only when
intrinsic adjacency proves that they belong to one physical side. Same-face,
disconnected, close, or opposing sheets are not merged merely by position,
frequency, label, count, or insertion order. Rail lineage remains independent of
the incident cell chart.

Canonical ownership is included in arrangement/domain hashes, simplification
transactions, parity/subdivision preflight, completion conflict classification,
completion dependency/reuse identities, rollback proofs, and logical/retained
storage accounting.

## P5-TB18 runtime requirements

Use artifact `8876934846` directly. Do not configure, rebuild, relink, patch, or
regenerate source during the test/benchmark turn.

- [ ] Run all new canonical-ownership and chart-map regressions.
- [ ] Re-run the 22 P5-TB17 failures for their intended contracts.
- [ ] Restore Phase 14–18 to at least 230/230 and Milestone D to 7/7.
- [ ] Confirm both guaranteed completion-reuse scenarios report real
      `reused > 0` and `recomputed > 0`.
- [ ] Confirm the malformed-midpoint fixture reaches
      `InvalidMidpointEmbedding` after temporary mutation and rolls back
      bit-exactly.
- [ ] Validate the cylinder fixture before candidate extraction: incidence,
      embedding, orientation, disk cells, Euler characteristic 0, one connected
      component, and two boundary loops.
- [ ] Run plane, cylinder, multi-face seam, torus, mechanical feature, close
      sheets, prescribed sphere, thin bent tube, and bunny production cases.
- [ ] Require nonempty, source-valid, manifold, pure-quad output without fallback
      or source-grid recovery for supported production cases.
- [ ] Run four independent face-edge and four independent smooth-field random-
      bunny processes and require deterministic structure/results.
- [ ] Reconcile categorized simultaneous ownership against the same peak-RSS
      sample and require at least 75% coverage.
- [ ] Record the first typed invalid stage/entity and define the next focused
      code/build turn for any unmet gate.

## Preserved prohibitions

- no validator weakening;
- no frequency-vote or count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Current authority

- `.agents/Directional/Milestone_G_P5_CB99_CB107_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Post_TB17_Source_Scope_Topology_Reuse_Output_Memory_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_TB17_Parity_Reuse_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb17-summary.json`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
