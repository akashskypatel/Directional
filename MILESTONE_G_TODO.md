# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — global ownership-frontier remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Main implementation: `9ed03260df430eb856bd9a3edf1587402ddfc16a`.
- Exact compiled source: `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`.
- Compile-only run / job: `30803697079` / `91654036551` — success.
- Artifact: `8852049639` (`surface-cell-p5-cb58-memory-frontier-linux-release`).
- Digest: `sha256:aeab9fc7d38dc65a29fec04a5635d8d63cbef46d7c872dbc17e46b26f3aaa34e`.
- Build: **131/131**; source status empty; checksums **36/36**.
- Completed turn: P5-CB51 through P5-CB58.
- Next turn: P5-TB12 artifact-only test and benchmark.

See `.agents/Directional/Milestone_G_P5_Memory_Bounded_Frontier_Code_Build_Report.md` and `benchmark-results/p5-cb58-summary.json`. Runtime success and actual RSS reduction are not claimed.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation and artifact.
- [x] P5-TB11 — artifact validation completed; closure gates failed.
- [x] P5-CB51 — correct atomic transaction budget semantics.
- [x] P5-CB52 — deterministic component-batched completion-template assignment.
- [x] P5-CB53 — exact product reuse across allocation-local renumbering.
- [x] P5-CB54 — fail-closed result and bounded diagnostic invariants.
- [x] P5-CB55 — compile-only regression corrections and coverage.
- [x] P5-CB56 — complete tracked executable-relative runtime fixture closure.
- [x] P5-CB57 — wall-time remediation path through batching, reuse, and lifetime reduction.
- [x] P5-CB58 — compile/package corrected checkpoint.
- [ ] P5-TB12 — validate artifact `8852049639` without rebuilding.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## Memory remediation

The 1,000-face random bunny OBJ is approximately 49 KB, but P5-TB11 expanded it to about 80,862 trace segments, 21,298 arrangement cells, 21,297 completion patches, and 2,729 parity splits. The previous `936,484,864 B` peak was therefore dominated by expanded pipeline state and copies, not source bytes.

P5-CB51–P5-CB58 now:

- release trace, FlowRep, arrangement, simplification, and completion intermediates after consumption;
- move expanded complexes and products through stages;
- retain one canonical rollback complex and at most one mutable candidate;
- compact ownership records and defer exact verbose payloads until conflicts exist;
- defer final mesh/provenance/lineage allocation until zero conflicts;
- batch independent completion-template changes in one transaction;
- emit ownership-registry, deferred-output, and workspace-owned byte estimates.

Only P5-TB12 can determine the actual RSS change.

## P5-TB12 gates

- Verify exact source, empty status, all checksums, binaries, libraries, logs, source archive, submodules, and complete packaged fixtures from an arbitrary extraction path.
- Run focused memory/frontier/fixture tests and all prior authoritative suites without rebuilding.
- Run the full packaged binary without source-tree or absolute CI path dependencies.
- Execute at least two formal and two supplementary fresh random-bunny processes with `SurfaceCells`, fallback `Fail`, and recovery disabled.
- Require deterministic zero ownership conflicts and nonempty pure-quad production output.
- Require no timeout, fallback, recovery, partial output, final-face deduplication, positional merge, source-triangle pairing, or ID-specific repair.
- Require wall time `<= 39.228299 s` in every process.
- Require peak memory `<= 1,115,394,560 B` in every process and compare directly with the P5-TB11 maximum of `936,484,864 B`.
- Record stage-owned byte diagnostics and explain any material discrepancy from process RSS.

## Current evidence

- `.agents/Directional/Milestone_G_P5_Memory_Bounded_Frontier_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Candidate_Budget_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_P5_TB11_Test_Benchmark_Report.md`
- `benchmark-results/p5-cb58-summary.json`
- `benchmark-results/p5-tb11-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
