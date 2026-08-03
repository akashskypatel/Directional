# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve remaining direct-completion ownership failures.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8`.
- Primary same-corner implementation: `4b7e02b0e8248a8093959147e27cc1ee9440d35a`.
- Exact compiled source: `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`.
- Compile-only run: `30776779114` — **success**.
- Artifact: `8842377256`.
- Digest: `sha256:669bf5d6f3e9b3738298b5985b6bb715668bce0715b0a68d880eb4aa0e80d6bc`.
- Completed turn: **code changes + compile-only build**.
- Next authoritative turn: **test and benchmark without rebuilding**.
- Review policy: `never`.

## Work phases

- [x] P0 — Establish reproducible source and dependency snapshot.
- [x] P1 — Review plans, diagnostics, and benchmark/test harness.
- [x] P2 — Reproduce and preserve the direct bunny failure.
- [x] P3 — Restore required singular separatrix prefixes.
- [x] P4 — Implement balanced regular-disk quadrangulation.
- [ ] P5 — Resolve remaining direct-completion ownership failures. **In progress**
- [x] P5A — Fail closed without legacy integration or meshing.
- [x] P5-CB1 through P5-CB20 — Canonical ownership, source support, typed diagnostics, compaction, and artifact `8841726806`.
- [x] P5-TB7 — Reach assembly and classify the deterministic `8595/8573` same-corner conflict.
- [x] P5-CB21 — Correct the generated-interior escape and parity fixtures.
- [x] P5-CB22 — Add exact same-corner/distinct-boundary claim and repair-attempt evidence.
- [x] P5-CB23 — Add bounded upstream boundary-sector repair and fail-closed unresolved/overlap routing.
- [x] P5-CB24 — Add generalized same-corner, fixture, and closed-form routing regression sources.
- [x] P5-CB25 — Preserve compact identities and bounded repair limits.
- [x] P5-CB26 — Compile and package exact artifact `8842377256`.
- [ ] P5-TB8 — Execute artifact `8842377256` and validate fixtures, same-corner repair, bunny progress, determinism, and performance.
- [ ] P6 — Validate topology, provenance, projection, alignment, determinism, and quality.
- [ ] P7 — Focused and full regression closure.
- [ ] P8 — Final bunny benchmark and production disposition.

## Implemented P5-CB21 through P5-CB26

- Corrected both invalid fixture scenarios without weakening production behavior.
- Added exact `SameCornerDistinctBoundaryClaim` ownership classification and expanded exact evidence.
- Added deterministic typed completion-variant and boundary-sector attempt records.
- Closed-form patches do not consume unavailable rotational attempts.
- Structural candidates derive from canonical complete boundary symmetric difference.
- Repair uses bounded twin-aware complex edge subdivision and transactionally reruns parity, coupled side repair, descriptor derivation, and completion.
- Repair commits only if the original exact claim disappears and all validators pass.
- Unproven ownership overlap or exhausted repair fails closed before accepted output.

Prohibited mechanisms remain absent: final-face deletion/deduplication, positional merge, source-triangle pairing, source-grid recovery, legacy fallback, validator weakening, and patch-ID special cases.

## Compile-only evidence

- GCC 13.3.0 optimized static Release configure: success.
- Build: **131/131 steps completed**.
- Compiled and linked `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Artifact source commit: `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`.
- Source status: empty.
- Packaged checksums: 10/10 pass.
- No test, benchmark, or custom mesh executable ran.

## Required P5-TB8 validation

Use artifact `8842377256` directly and do not rebuild.

1. Verify exact source, empty status, and checksums.
2. Run corrected generated-interior and parity fixtures.
3. Run same-corner classification, overlap, order-invariance, closed-form routing, and repair-ledger regressions.
4. Run `PatchDescriptorMilestoneE.*`, Phase 16/18, Phase 14–18, and Milestone G P23/Phase 20.
5. Run the random bunny at least twice with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled.
6. Determine whether the prior `8595/8573` claim is removed, reclassified upstream, or remains fail-closed.
7. Record structural/variant attempts, inserted intervals, descriptors, endpoints, output origin, accepted quads, all stage hashes, runtime, and peak memory.
8. Compare against artifacts `8838467442`, `8840174777`, `8840866875`, and `8841726806`.

## Closure rules

P5 remains open until direct completion passes assembly without duplicate ownership, recovery, fallback, final-face deduplication, positional ownership, source-triangle pairing, or patch-ID special cases. Correctness, determinism, and acceptable runtime/memory must be demonstrated by execution.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Plan.md`
- `benchmark-results/p5-cb26-summary.json`

PR #8 remains draft and unmerged.
