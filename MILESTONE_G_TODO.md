# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — route-complete same-corner structural repair.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8.
- Implementation commit: `5dcc6da94977c733ada42967ecdafa566cbc5d0b`.
- Exact compiled source: `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`.
- Compile-only run: `30782277625` — success.
- Artifact: `8844133680` (`surface-cell-p5-route-complete-linux-release`).
- Digest: `sha256:1f32a4d3600d1a7be39e710d35273f80bed0c24850626d744ab15e7a748a34bb`.
- Completed turn: P5-CB34 through P5-CB41 code changes + compile-only build.
- Next turn: P5-TB10 artifact-only test and benchmark.
- Review policy: `never`.

## Work phases

- [x] P0–P4 — reproducibility, diagnosis, singular traces, and regular-disk completion.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB1–P5-CB20 — canonical ownership, intrinsic support, diagnostics, and compaction.
- [x] P5-TB7 — reach assembly and classify deterministic same-corner ownership.
- [x] P5-CB21–P5-CB26 — initial same-corner repair and artifact `8842377256`.
- [x] P5-TB8 — expose recursive completion-stage resource runaway.
- [x] P5-CB27–P5-CB33 — globally bounded non-recursive controller and artifact `8843206930`.
- [x] P5-TB9 — verify bounded termination and classify single-interval candidate insufficiency.
- [x] P5-CB34 — replace vacuous structural fixtures with an authoritative same-corner route fixture.
- [x] P5-CB35 — exact route-complete candidate identity and maximal route grouping.
- [x] P5-CB36 — atomic topology-derived coupled-sector subdivision.
- [x] P5-CB37 — typed route progress and exhaustion semantics.
- [x] P5-CB38 — release superseded completion storage and preserve one live candidate.
- [x] P5-CB39 — route identities, interval sets, affected domains, outcomes, and owned-byte diagnostics/hashes.
- [x] P5-CB40 — compile corrected route-complete regression sources.
- [x] P5-CB41 — compile and package artifact `8844133680`.
- [ ] P5-TB10 — validate artifact `8844133680` without rebuilding.
- [ ] P6 — production topology/provenance/alignment/quality validation.
- [ ] P7 — focused and full regression closure.
- [ ] P8 — final bunny benchmark and production disposition.

## Implemented route-complete transaction

- Exact candidate identity contains shared authoritative corners, maximal complete route chains, canonical undirected intervals, geometric support, affected patches/domains, and component/sheet scope.
- Multiple differing sectors from one unresolved relationship produce one topology-derived coupled candidate evaluated before individual complete routes.
- No arbitrary subset or powerset enumeration is used.
- All intervals in a candidate are subdivided atomically through twin-conforming complex subdivision.
- Parity, coupled side repair, descriptor derivation, completion, and assembly rerun once for the complete transaction.
- Commit requires assembly success and zero exact ownership conflicts.
- Persistent, replacement, repeated, incomplete, invalid, or exhausted route transactions remain fail-closed.
- One invocation-owned global ledger and collision-safe exact state equality remain authoritative.
- Superseded descriptors, completed patches, assembly meshes, candidate storage, and repeated failure strings are released.
- Peak mutable candidate-complex count remains one.
- Pipeline diagnostics, semantic hashes, and benchmark JSON include route candidates, interval lists, affected domains, compound insertions/splits, typed outcomes, and structural owned-byte estimates.
- No final-face deduplication, positional merge, source-triangle pairing, source-grid recovery, legacy fallback, ID special case, arbitrary combinatorial search, or validator weakening.

## Compile evidence

- GCC 13.3.0 optimized static Release.
- 131/131 build steps completed.
- `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks` linked.
- Source status empty; 10/10 packaged checksums pass.
- Packaged executables are Linux x86-64 ELF files and libraries are valid static archives.
- Exact source archive, configure/build logs, and recursive submodule revisions are packaged.
- No tests, benchmarks, or custom meshes executed.

The first source compile run `30781889869` succeeded but produced a self-referential checksum manifest. It was superseded by run `30782277625`, which corrected packaging without changing the production implementation.

## P5-TB10 requirements

1. Verify exact compiled source, empty status, and all checksums.
2. Execute all corrected route-complete structural tests and assert the initial same-corner preconditions.
3. Run PatchDescriptor, Phase 16/18, Phase 14–18, and P23/Phase20 suites.
4. Run at least two clean-exit direct random-bunny processes with `SurfaceCells`, fallback `Fail`, and recovery disabled.
5. Require direct completion success with nonempty pure-quad output.
6. Record deterministic route candidate identities, complete interval sets, affected domains, compound insertions, structural hashes, and owned-byte diagnostics.
7. Verify no timeout, fallback, or recovery.
8. Require wall time ≤ 39.228299 s in every formal run.
9. Require peak memory ≤ 1,115,394,560 B in every formal and supplementary run.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Test_Benchmark_Report.md`
- `benchmark-results/p5-cb41-summary.json`
- `benchmark-results/p5-tb9-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
