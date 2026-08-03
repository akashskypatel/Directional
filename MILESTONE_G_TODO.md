# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve remaining direct-completion ownership failures.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8`.
- Previous validated artifact: `8840866875`, source `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- Intrinsic source-support implementation: `9f6d266436574c7ba797ca42407684700e603bb2`.
- Exact compiled source: `053fe3816f585320e65526824f1107b8ccb1332d`.
- Compile-only run: `30774730933` — **success**.
- New artifact: `8841726806`, digest `sha256:9b9bf5ad23640dfe049d416a0b81649c2e8a3d0353e1bff475fa6ea58155a681`.
- Completed turn: **code changes + compile-only build**.
- Next authoritative turn: **test and benchmark using artifact `8841726806` without rebuilding**.
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
- [x] P5-TB1 through P5-TB5 — Validate the original ownership checkpoint and expose the deterministic completion conflict.
- [x] P5-CB7 — Canonicalize completed-face cycles and add stronger ownership lineage.
- [x] P5-CB8 — Implement false-merge versus completion-template classification and repair routing.
- [x] P5-CB9 — Add completion-domain ownership proof.
- [x] P5-CB10 — Add discriminator and patch-order regression sources.
- [x] P5-CB11 — Correct ambiguous-singularity and transactional partial-output fixtures.
- [x] P5-CB12 — Compact ownership identities and release superseded capacity.
- [x] P5-CB13 — Build and package artifact `8840866875`.
- [x] P5-TB6 — Execute artifact `8840866875`; identify intrinsic source-support rejection as the next blocker.
- [x] P5-CB14 — Replace literal boundary-face membership with intrinsic source-entity support.
- [x] P5-CB15 — Canonicalize serialized conflict corner order under reversal.
- [x] P5-CB16 — Construct an explicit two-odd-cell parity fixture with a real shared interface.
- [x] P5-CB17 — Add chart-alias and strict source-support escape regressions.
- [x] P5-CB18 — Propagate ownership repair attempts and typed support diagnostics.
- [x] P5-CB19 — Reuse one source-incidence resolver per completion invocation and preserve compact identities.
- [x] P5-CB20 — Compile all required targets and package exact artifact `8841726806`.
- [ ] P5-TB7 — Execute artifact `8841726806` and validate intrinsic support, parity, assembly progress, determinism, and performance.
- [ ] P6 — Validate topology, provenance, projection, alignment, determinism, and quality.
- [ ] P7 — Focused and full regression closure.
- [ ] P8 — Final bunny benchmark and production disposition.

## Implemented source-support contract

- Face-interior point: exact source face support.
- Source-edge point: incident faces of the canonical source edge.
- Source-vertex point: incident faces of the canonical source vertex.
- Boundary point: exact authoritative boundary identity plus nonempty intrinsic-support intersection with patch support.
- Generated interior point: strict patch-local identity and exact stored-face confinement.
- Component and sheet labels remain authoritative when available.
- Invalid or ambiguous barycentric support fails closed with typed diagnostics.
- Position does not create support or ownership.

## Diagnostic and fixture changes

- Typed ownership rejection records include patch, local vertex, completion backend/variant, stored face, barycentric coordinates, source entity, candidate incident faces, patch faces, component, sheet, and failure class.
- Completion repair attempts and first ownership rejection propagate through pipeline products, remesh diagnostics, semantic hashing, and benchmark JSON.
- Conflict corner arrays use one canonical unoriented order across cyclic rotation and reversal.
- The parity fixture now directly constructs two odd bounded cells sharing an interior interface with explicit twin/next/cell incidence.
- Added boundary source-edge/source-vertex chart-alias tests and strict exterior/interior escape tests.

## Compile-only evidence

- Clean Release configure: success with GCC 13.3.0.
- Build: **131/131 steps completed**.
- Compiled targets:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.
- Modified production and regression sources compiled successfully.
- Artifact `source-commit.txt`: `053fe3816f585320e65526824f1107b8ccb1332d`.
- Artifact `source-status.txt`: empty.
- Packaged checksums: all ten pass.
- Artifact contains exact source, binaries, libraries, configure/build logs, and submodule revisions.
- No test, benchmark, or custom mesh executable ran.

A first compile attempt exposed four malformed benchmark JSON key literals; those were corrected without changing the ownership design before the successful final build.

## Required next validation turn

Use artifact `8841726806` directly and do not rebuild.

1. Run intrinsic source-support and canonical diagnostic regressions.
2. Run corrected `PatchDescriptorMilestoneE.*`.
3. Run `SurfaceArrangementPhase16.*` and `PureQuadCompletionPhase18.*`.
4. Run the Phase 14–18 aggregate.
5. Run Milestone G P23 and Phase 20 fail-closed suites.
6. Run the random bunny at least twice with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled.
7. Record typed rejection details, ownership repair attempts, descriptor/endpoint counts, output origin, accepted quads, and all stage hashes.
8. Determine whether the pipeline reaches, repairs, or authoritatively reclassifies the prior patches `378/394` duplicate conflict.
9. Compare same-machine runtime and peak memory with artifacts `8838467442`, `8840174777`, and `8840866875`.

## Closure rules

P5 remains open until direct completion proceeds through assembly without duplicate ownership, recovery, fallback, final-face deduplication, or validator weakening. Correctness, determinism, and acceptable runtime/memory must be demonstrated by execution; compilation alone does not close the phase.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Source_Support_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Source_Support_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Completion_Template_Code_Build_Report.md`

PR #8 remains draft and unmerged.
