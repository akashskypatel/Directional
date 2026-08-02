# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve remaining direct-completion ownership failures.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8`.
- Previous validated artifact: `8840174777`, source `d4c1bce4338b7f2e91264c349a73b6b260e80f54`.
- Implementation commit: `713eb310ec0afe6e2608cf3b0f3b8f6962b485e5`.
- Exact compiled source: `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- Compile-only run: `30771945124` — **success**.
- New artifact: `8840866875`, digest `sha256:d67a464b2f2c2f6d58bbb9fa15a0e87009176698f14d19a9054facfbcb97cd90`.
- Completed turn: **code changes + compile-only build**.
- Next authoritative turn: **test and benchmark using artifact `8840866875` without rebuilding**.
- Review policy: `never`.

## Work phases

- [x] P0 — Establish reproducible local source and dependency snapshot.
- [x] P1 — Review plans, diagnostics, and benchmark/test harness.
- [x] P2 — Reproduce and preserve the direct bunny failure.
- [x] P3 — Restore required nonempty singular separatrix prefixes.
- [x] P4 — Implement balanced regular-disk quadrangulation.
- [ ] P5 — Resolve remaining direct-completion ownership failures. **In progress**
- [x] P5A — Fail closed without legacy integration or meshing.
- [x] P5-CB1 — Add canonical domain and stitch-vertex identities.
- [x] P5-CB2 — Detect duplicate/overlapping arrangement ownership before completion.
- [x] P5-CB3 — Stitch only equal authoritative identities and keep interiors patch-local.
- [x] P5-CB4 — Preserve duplicate validation and add typed ownership hashes.
- [x] P5-CB5 — Add generalized ownership/ordering regression sources.
- [x] P5-TB1 — Validate artifact `8840174777` without rebuilding.
- [x] P5-TB2 — Run ownership regressions: 8/8 passed.
- [x] P5-TB3 — Run Phase 14–18 aggregate: 219/219 passed.
- [x] P5-TB4 — Run Milestone G P23 and Phase 20: 52/52 passed.
- [x] P5-TB5 — Repeat direct bunny and expose provisional completion-template conflict.
- [x] P5-CB7 — Canonicalize completed-face cycles and serialize corner/backend lineage.
- [x] P5-CB8 — Implement authoritative false-merge versus completion-template discrimination and general repair routing.
- [x] P5-CB9 — Enforce per-face completion-domain ownership proof.
- [x] P5-CB10 — Add discriminator, canonical-order, and patch-order regression sources.
- [x] P5-CB11 — Correct the three structurally invalid Milestone E fixtures.
- [x] P5-CB12 — Compact ownership identities and release superseded vector capacity.
- [x] P5-CB13 — Compile all required library, test, and benchmark targets and package exact artifact `8840866875`.
- [ ] P5-TB6 — Execute artifact `8840866875` and validate classification, repair, corrected fixtures, determinism, and performance.
- [ ] P6 — Validate topology, provenance, projection, alignment, determinism, and quality.
- [ ] P7 — Focused and full regression closure.
- [ ] P8 — Final bunny benchmark and production disposition.

## Implemented code/build checkpoint

- Completed-face ownership is canonical under cyclic rotation and reversed orientation.
- Compact stitch identities and stronger source-authoritative identities are retained independently.
- Conflict diagnostics include identity kinds/hashes, local/global corners, component/sheet scope, completion backend, completion variant, and source/operation ownership.
- Equal compact stitch cycles with different authoritative cycles classify as false stitch equivalence.
- Distinct domains with equal authoritative face ownership classify as completion-template ownership.
- Boundary corners, generated interiors, source support, and operation-local ownership are validated before assembly.
- Eligible completion-template conflicts can use bounded deterministic alternative completion variants.
- The final duplicate validator remains transactional and fail-closed.
- Variable-length ownership identities are compacted into deterministic exact IDs after canonicalization, and superseded capacity is released.
- Structural hashes include the new ownership semantics.
- The three invalid Milestone E fixture constructions were replaced with valid scenarios matching their stated contracts.

## Compile-only evidence

- Clean Release configure: success with GCC 13.3.0.
- Build: **131/131 steps completed**.
- Compiled targets:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.
- Modified production and regression sources compiled successfully.
- Artifact `source-commit.txt`: `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- Artifact `source-status.txt`: empty.
- Packaged checksums: all pass.
- No test, benchmark, or custom mesh executable ran.

## Required next validation turn

Use artifact `8840866875` directly and do not rebuild.

1. Run canonical face-ownership and false-merge/completion-template discriminator regressions.
2. Run corrected `PatchDescriptorMilestoneE.*`.
3. Run `SurfaceArrangementPhase16.*` and `PureQuadCompletionPhase18.*`.
4. Run the Phase 14–18 aggregate.
5. Run Milestone G P23 and Phase 20 fail-closed suites.
6. Run the random bunny at least twice with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled.
7. Record definitive classification, repair attempts, descriptor/endpoint counts, output origin, structural hashes, runtime, and peak memory.
8. Compare same-machine performance with artifacts `8838467442` and `8840174777`.

## Closure rules

P5 remains open until direct completion proceeds beyond assembly without duplicate ownership, recovery, fallback, final-face deduplication, or validator weakening. Runtime and memory improvement must be demonstrated; compilation alone does not close the phase.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Completion_Template_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Completion_Template_Code_Build_Report.md`

PR #8 remains draft and unmerged.
