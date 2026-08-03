# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — bounded same-corner structural repair.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8.
- Exact implementation and compiled source: `bc95579be68d5de073de956022eec8fb89120ec0`.
- Compile-only run: `30779430182` — success.
- Artifact: `8843206930` (`surface-cell-p5-bounded-repair-linux-release`).
- Digest: `sha256:9b6ef73f2bd04eb49486cd7f0f28a1d2e9121a36791c7dd25fe1ffcc19d64f94`.
- Completed turn: P5-CB27 through P5-CB33 code changes + compile-only build.
- Next turn: P5-TB9 artifact-only test and benchmark.
- Review policy: `never`.

## Work phases

- [x] P0–P4 — reproducibility, diagnosis, singular traces, and regular-disk completion.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB1–P5-CB20 — canonical ownership, intrinsic support, diagnostics, and compaction.
- [x] P5-TB7 — reach assembly and classify the deterministic `8595/8573` same-corner conflict.
- [x] P5-CB21–P5-CB26 — same-corner classification, initial structural repair, corrected fixtures, and artifact `8842377256`.
- [x] P5-TB8 — validate regressions and expose deterministic completion-stage resource runaway.
- [x] P5-CB27 — replace recursive search with one global repair-work ledger.
- [x] P5-CB28 — canonical exact repair-state deduplication and single-candidate memory discipline.
- [x] P5-CB29 — strict success-only progress and fail-closed overlap/replacement-conflict routing.
- [x] P5-CB30 — retain full recomputation where partial equivalence is unproven and bound it globally.
- [x] P5-CB31 — add whole-complex structural-repair, overlap, budget, and order-invariance regression sources.
- [x] P5-CB32 — expose candidate budget, state, recomputation, live-candidate, and exhaustion diagnostics.
- [x] P5-CB33 — compile and package artifact `8843206930`.
- [ ] P5-TB9 — validate artifact `8843206930` without rebuilding.
- [ ] P6 — production topology/provenance/alignment/quality validation.
- [ ] P7 — focused and full regression closure.
- [ ] P8 — final bunny benchmark and production disposition.

## Bounded structural-repair contract

- One non-recursive completion pass and one invocation-owned transaction controller.
- Global deterministic limits for candidate evaluations, structural attempts, inserted vertices, full completion passes, and exact visited states.
- Collision-safe canonical repair-state equality; hashes remain diagnostic only.
- One rollback complex and at most one live mutable candidate complex.
- Rejected descriptor, patch, assembly, and candidate storage is released before continuing.
- No geometrically distinct boundary route fails as typed same-corner overlap before search.
- A structural candidate commits only when assembly succeeds and the ownership-claim count decreases to zero.
- Persistent original claims fail as `NoProgress`.
- Replacement ownership conflicts fail as `IntroducedOwnershipClaim`.
- Repeated states and every global budget exhaustion are typed and fail closed.
- Full recomputation is retained because incremental equivalence is unproven; it is globally bounded and separately reported.
- No deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, or patch-ID special case.

## Compile evidence

- GCC 13.3.0 optimized static Release.
- 131/131 build steps completed.
- `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks` linked.
- Source status empty; 10/10 packaged checksums pass.
- Packaged executables are Linux x86-64 ELF files and packaged libraries are valid static archives.
- No tests, benchmarks, or custom meshes executed.

## P5-TB9 requirements

1. Verify source commit, empty status, and all checksums.
2. Execute all new whole-complex structural-repair tests.
3. Run PatchDescriptor, Phase 16/18, Phase 14–18, and P23/Phase20 suites.
4. Run at least two direct random-bunny processes with `SurfaceCells`, fallback `Fail`, and recovery disabled.
5. Require a terminal result without timeout.
6. Record the complete deterministic global work ledger, output disposition, hashes, wall time, and peak memory.
7. Verify no fallback or recovery.
8. Require peak memory ≤ 1,115,394,560 B.
9. Require wall time ≤ 39.228299 s unless a correctness-driven exception is independently reviewed.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Structural_Repair_Test_Benchmark_Report.md`
- `benchmark-results/p5-cb33-summary.json`
- `benchmark-results/p5-tb8-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
