# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — same-corner ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8.
- Primary implementation: `4b7e02b0e8248a8093959147e27cc1ee9440d35a`.
- Exact compiled source: `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`.
- Compile-only run: `30776779114` — success.
- Artifact: `8842377256`.
- Digest: `sha256:669bf5d6f3e9b3738298b5985b6bb715668bce0715b0a68d880eb4aa0e80d6bc`.
- Next turn: P5-TB8 artifact-only test and benchmark.

## Work phases

- [x] P0–P4 — reproducibility, diagnosis, singular traces, and regular-disk completion.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB1–P5-CB20 — canonical ownership, intrinsic support, diagnostics, and compaction.
- [x] P5-TB7 — reach assembly and classify the deterministic `8595/8573` same-corner conflict.
- [x] P5-CB21 — correct generated-interior and parity fixtures.
- [x] P5-CB22 — exact same-corner/distinct-boundary classification and attempt evidence.
- [x] P5-CB23 — bounded upstream boundary-sector repair and fail-closed routing.
- [x] P5-CB24 — generalized regression sources.
- [x] P5-CB25 — bounded attempts and compact ownership state.
- [x] P5-CB26 — compile and package artifact `8842377256`.
- [ ] P5-TB8 — validate artifact `8842377256` without rebuilding.
- [ ] P6 — production topology/provenance/alignment/quality validation.
- [ ] P7 — focused and full regression closure.
- [ ] P8 — final bunny benchmark and production disposition.

## Implemented contract

- Exact `SameCornerDistinctBoundaryClaim` classification.
- Deterministic typed variant and structural repair ledger.
- Closed-form patches do not consume unavailable rotations.
- Candidate intervals derive from complete boundary symmetric difference.
- Twin-aware complex edge subdivision is bounded and transactional.
- Parity, coupled side repair, descriptor derivation, and completion rerun after repair.
- Repair commits only when the original exact claim is removed and all validators pass.
- Unproven overlap or exhausted repair fails closed.
- No deduplication, positional merge, fallback, recovery, source-triangle pairing, validator weakening, or patch-ID special cases.

## Compile evidence

- GCC 13.3.0 optimized static Release.
- 131/131 build steps completed.
- `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks` linked.
- Source status empty; 10/10 packaged checksums pass.
- No tests, benchmarks, or custom meshes executed.

## P5-TB8 requirements

1. Verify source commit, status, and checksums.
2. Run corrected fixtures and focused same-corner regressions.
3. Run PatchDescriptor, Phase 16/18, Phase 14–18, and P23/Phase20 suites.
4. Run the random bunny twice with direct SurfaceCells, fallback Fail, and recovery disabled.
5. Determine the disposition of the previous `8595/8573` claim.
6. Record repair attempts, inserted intervals, output counts/origin, hashes, runtime, and memory.
7. Compare with prior baseline and ownership artifacts.

P5 remains open. PR #8 remains draft and unmerged.
