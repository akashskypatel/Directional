# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Last tested source: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`.
- Last tested artifact: `8875627676`.
- Completed turn: **P5-TB17 artifact-only test and benchmark**.
- Next turn: **P5-CB99 through P5-CB107 code changes + compile-only build**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB90 — earlier ownership, topology, liveness, rail, fixture,
      output, and memory implementation turns.
- [x] P5-TB11–P5-TB16 — earlier runtime diagnosis turns.
- [x] P5-CB91–P5-CB98 — parity scope, completion reuse, midpoint, cylinder,
      output, memory, regressions, and compile/package changes.
- [x] P5-CB98-SYNC — source synchronization and 14/14 implementation blob
      parity verified.
- [x] P5-CB98-GITHUB-COMPILE — exact pushed source compiled with mandatory
      detailed workflow log artifact.
- [x] P5-TB17 — artifact-only runtime validation; closure gates remain open.
- [ ] P5-CB99 — canonical cell ownership across adjacent local sheet charts.
- [ ] P5-CB100 — canonical ownership through simplification.
- [ ] P5-CB101 — parity preflight based on committed canonical ownership.
- [ ] P5-CB102 — exact reuse and route validation.
- [ ] P5-CB103 — intended invalid-midpoint contract.
- [ ] P5-CB104 — canonical open-cylinder DCEL fixture.
- [ ] P5-CB105 — production output producer correction.
- [ ] P5-CB106 — peak-RSS ownership reconciliation.
- [ ] P5-CB107 — regression and compile/package gate.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB17 artifact integrity

- Artifact ID: `8875627676`.
- Name: `surface-cell-p5-cb98-github-source-linux-release`.
- Source commit: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`.
- Archive SHA-256:
  `b9560c9438289e90e6acca3a0f4b7f1d46a5ad34663693c1243bf4176056c165`.
- Source status empty.
- Checksums: **38/38**.
- Fixture files: **26**.
- Random bunny: **502 vertices / 1,000 faces**.
- No build/configure/relink/regeneration occurred.

## P5-TB17 test results

| Scope | Passed | Failed | Total |
|---|---:|---:|---:|
| Focused prior/new regressions | 4 | 10 | 14 |
| Phase 14–18 | 220 | 10 | 230 |
| Patch descriptor Milestone E | 23 | 3 | 26 |
| Milestone D | 4 | 3 | 7 |
| Milestone G P23 | 6 | 0 | 6 |
| Milestone G P26 | 15 | 4 | 19 |
| Milestone G P27 + parameter cases | 16 | 1 | 17 |
| Phase 20 | 47 | 1 | 48 |
| Complete suite | **572** | **22** | **594** |

The complete suite terminated normally. The three former signal-11 cases also
terminate normally: two pass and the P27 aggregate case fails by assertion.

The ten P5-TB16 failures remain. Twelve additional source-level regressions are
present and reproduce with both independently compiled GCC and Clang packages:

- Phase 16: 4;
- Phase 17: 6;
- Milestone D: 2.

## Source-scope root cause

The P5-CB91 ownership model requires every oriented boundary record to share
one raw `(component, localSheetByFace)` pair. The established trace model allows
a legitimate trace/cell to cross adjacent per-face local chart IDs through
intrinsic source adjacency while remaining in one connected physical sheet and
component.

The next implementation must distinguish:

1. connected source component;
2. canonical cell-side/sheet equivalence class;
3. exact per-source-face local chart for every oriented halfedge and occurrence.

It must accept adjacent local charts proven to belong to one canonical cell-side
class, while still rejecting disconnected or close/opposing physical sheets.
Frequency voting, count/order selection, and validator weakening are forbidden.

## Random-bunny benchmark result

Four face-edge and four smooth-field runs:

- terminate normally;
- are structurally deterministic within each field path;
- satisfy wall and memory limits;
- use no fallback and no source-grid recovery;
- emit no output;
- report reuse/recompute `0/0`;
- fail at `BoundaryParityRepair:MixedCellSourceScope`.

Face-edge typed evidence:

- cell `19`;
- halfedge/twin `21767/21766`;
- components `[0,0]`;
- local charts `[0,1]`;
- selected scope `-1/-1`;
- phase `preflight`.

Smooth typed evidence:

- cell `45`;
- halfedge/twin `46451/46450`;
- components `[0,0]`;
- local charts `[0,1]`;
- selected scope `-1/-1`;
- phase `preflight`.

Deterministic structural digests:

- face-edge:
  `aa0ae261c0bda69864d74db10d829fc5367582b06060958bc35165aded8969e8`;
- smooth:
  `27b0a7e69a9e47bd1f0189a9d6e5a2e8bacaf7676248fd05cb3e069673161e50`.

Memory timelines are populated, but simultaneous ownership explains only
**28.0–33.6%** of peak RSS. The next quantitative gate is at least 75% with the
remainder categorized.

## P5-CB99–P5-CB107 closure requirements

- Restore all Phase 16, Phase 17, and Milestone D source regressions without
  reducing validation coverage.
- Face-edge cell 19 and smooth cell 45 resolve one valid canonical ownership
  class and no longer stop at mixed scope.
- Both guaranteed completion-reuse fixtures report real `reused > 0` and
  `recomputed > 0`.
- Route validation resolves the `same-corner-distinct-boundary` conflict at its
  producer.
- Invalid-midpoint fixture reaches `InvalidMidpointEmbedding` only after a valid
  common-chart precondition and rolls back bit-exactly.
- Cylinder fixture validates incidence, embedding, orientation, disk cells,
  Euler 0, one component, and two boundary loops before candidate extraction.
- Plane, cylinder, seam, torus, mechanical, and other production fixtures emit
  nonempty valid manifold pure-quad output without fallback/recovery.
- Peak-RSS ownership reconciliation reaches at least 75%.
- Compile exactly the four required targets and execute no binary in CB107.
- Any workflow follows `.agents/Directional/GitHub_Workflow_Policy.md` and
  always uploads detailed logs on success or failure.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB17_Parity_Reuse_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb17-summary.json`
- `.agents/Directional/Milestone_G_P5_Post_TB17_Source_Scope_Topology_Reuse_Output_Memory_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
