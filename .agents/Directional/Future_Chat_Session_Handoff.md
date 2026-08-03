# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

Milestone G P5-CB42 through P5-CB50 is implemented and compiled. Runtime correctness is not yet verified, so P5 remains open.

- Implementation commit: `413660dba15fe1376adc13aa80aea0e1ba99194e`.
- Exact compiled source: `643cc483e430d2cd161dde94a983aedac4be57dd`.
- Compile-only run / job: `30794828420` / `91625965577` — success.
- Artifact: `8848599037` (`surface-cell-p5-global-frontier-linux-release`).
- Digest: `sha256:597c788ed3f34f09480857c910872ff0e6230120a13e57781ef58f3a8bed395d`.
- Build: **131/131**; source status empty; checksums **11/11**.
- No test, benchmark, help/list command, test discovery, or custom mesh executable ran.
- Next turn: **P5-TB11 artifact-only test and benchmark without rebuilding**.

Full implementation and artifact evidence is in `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Report.md`. Do not duplicate it here.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`
5. `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Test_Benchmark_Report.md`
6. `benchmark-results/p5-cb50-summary.json`
7. `benchmark-results/p5-tb10-summary.json`

Earlier `.agents/Directional` documents are historical context only unless one of the files above references them.

## What changed in P5-CB42–P5-CB50

The global ownership-frontier source now includes complete exact conflict inventories, exact pre/post set progress, deterministic conflict components and topology-complete transactions, exact completion-product reuse, compact memory accounting, propagated diagnostics/hashes, regression sources, and an executable-relative packaged manifest fixture.

The exact contracts and prohibitions are defined in the code/build plan; the completed implementation is summarized in the code/build report. Do not restate those sections here.

## Required P5-TB11 procedure

Use artifact `8848599037` directly. Do not rebuild or edit source.

1. Verify `source-commit.txt` equals `643cc483e430d2cd161dde94a983aedac4be57dd`, source status is empty, all packaged checksums pass, and the manifest fixture exists relative to the test executable.
2. Run the focused global-frontier tests and all prior authoritative suites from an arbitrary extraction path.
3. Run the required formal and supplementary `bunny_1k_random.obj` processes using the packaged benchmark binary.
4. Apply every gate listed in `MILESTONE_G_TODO.md`; record exact commands and raw evidence.
5. Update the test/benchmark report, trackers, result summary, PR body/comment, and this handoff.

Do not infer runtime success from compilation. Do not stage source files at the old CI path.

## Turn boundaries

### Code + build

May edit source, tests, build logic, workflows, and documentation; may configure and compile only. It must not execute any built binary.

### Test + benchmark

May execute only the exact packaged artifact and update evidence documents. It must not rebuild or edit implementation, tests, benchmark source, or build configuration.

The project has no review turn because `review_policy` is `never`.

## Repository and workflow rules

- Workflow files under `.github/workflows` must be created or updated directly through the GitHub connector. Do not use a workflow, patch payload, or GitHub App push to modify workflow files; the App lacks `workflows` permission.
- The temporary `apply-p5-cb50-patch.yml` workflow was removed directly through the connector before artifact `8848599037` was built.
- Keep `.github/workflows/agent-build-recovered-p5.yml` compile-only. It must not run tests, benchmarks, help/list commands, discovery, or custom meshes.
- Use the artifact’s `source-commit.txt` as compiled-source authority. Documentation-only commits may make the branch head newer.
- Keep PR #8 draft and unmerged until P5–P8 closure evidence exists.

## Persistent lessons

- Tests must exercise their stated scenario; fix invalid fixtures rather than weakening production validation or forcing synthetic success.
- The authoritative production fixture is `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`, not the simpler bunny fixture.
- No final-face deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, arbitrary subset search, or production ID special case is acceptable.
- GitHub artifact checksum manifests currently contain an archive-time `artifact/` prefix; normalize that prefix when verifying an extracted artifact and record the normalization.
- Keep this file short. Put detailed evidence in the phase report, machine-readable data in `benchmark-results`, and task state in the trackers.
