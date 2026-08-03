# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — route-complete same-corner structural repair.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8.
- Validated artifact: `8843206930`.
- Exact source: `bc95579be68d5de073de956022eec8fb89120ec0`.
- Digest: `sha256:9b6ef73f2bd04eb49486cd7f0f28a1d2e9121a36791c7dd25fe1ffcc19d64f94`.
- Completed turn: P5-TB9 artifact-only test and benchmark.
- Next turn: code changes + compile-only build.
- Review policy: `never`.

## Work phases

- [x] P0–P4 — reproducibility, diagnosis, singular traces, and regular-disk completion.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB1–P5-CB20 — canonical ownership, intrinsic support, diagnostics, and compaction.
- [x] P5-TB7 — reach assembly and classify deterministic same-corner ownership.
- [x] P5-CB21–P5-CB26 — same-corner classification, initial structural repair, fixtures, and artifact `8842377256`.
- [x] P5-TB8 — expose recursive completion-stage time and memory runaway.
- [x] P5-CB27–P5-CB33 — global non-recursive ledger, exact state deduplication, bounded memory discipline, diagnostics, and artifact `8843206930`.
- [x] P5-TB9 — verify bounded termination and identify single-interval repair insufficiency.
- [ ] P5-CB34 — replace invalid structural fixtures with authoritative same-corner inputs.
- [ ] P5-CB35 — route-complete candidate identity and deterministic route grouping.
- [ ] P5-CB36 — atomic coupled-sector subdivision.
- [ ] P5-CB37 — typed route progress and exhaustion semantics.
- [ ] P5-CB38 — improve peak-memory safety margin.
- [ ] P5-CB39 — route and owned-byte diagnostics/hashes.
- [ ] P5-CB40 — compile corrected route-complete regression sources.
- [ ] P5-CB41 — compile and package the route-complete checkpoint.
- [ ] P5-TB10 — validate the route-complete artifact without rebuilding.
- [ ] P6 — production topology/provenance/alignment/quality validation.
- [ ] P7 — focused and full regression closure.
- [ ] P8 — final bunny benchmark and production disposition.

## P5-TB9 tests

| Scope | Passed | Failed |
|---|---:|---:|
| New whole-complex structural subset | 2 | 3 |
| `PatchDescriptorMilestoneE.*` | 17 | 3 |
| Phase 16 + Phase 18 | 89 | 0 |
| Phase 14–18 aggregate | 229 | 0 |
| Milestone G P23 + Phase 20 | 52 | 0 |

Authoritative non-overlapping total: **298/301 passed**.

The three failed tests use a fixture that assembles on the initial pass and never creates a same-corner conflict. The zero/one-budget and repair expectations are therefore invalid. The patch-order test also passes vacuously with an empty ledger. Correct the fixture; do not force production repair on successful assembly.

## Bounded production result

Two clean-exit random-bunny runs terminate below the formal limits:

- 32.075226 s and 1,053,339,648 B;
- 33.230250 s and 1,083,228,160 B.

Two supplementary guarded probes produce identical completed JSON but peak near 1.242 GB. Memory compliance is not yet repeatably below the cap.

Every completed record has the same terminal ledger:

- initial exact same-corner claim: patches `4956/4954`;
- candidate halfedges: `22706`, then `23112`;
- candidate outcomes: `IntroducedOwnershipClaim`, `IntroducedOwnershipClaim`;
- candidates/attempts: `2/2`;
- inserted vertices: `2`;
- visited states: `3`;
- full/incremental passes: `3/0`;
- peak live candidate complexes: `1`;
- exhaustion: `candidate-budget`;
- output origin/quads: `None / 0`;
- fallback/recovery: `false / false`.

The recursive runaway is fixed. Single-interval subdivision is insufficient: each candidate creates a replacement same-corner claim, and the controller correctly refuses to commit it.

## Next code/build authority

Use `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Plan.md`.

Required implementation:

1. construct real structural-repair test fixtures and assert the initial same-corner precondition;
2. derive complete boundary routes between shared authoritative corners;
3. represent a candidate as an exact interval set, not one halfedge;
4. apply route-complete/coupled-sector subdivision atomically;
5. preserve strict success-only commit and global budgets;
6. add route identities, interval lists, affected domains, outcomes, and owned-byte diagnostics;
7. reduce full-complex copy peaks and require repeatable memory compliance;
8. compile only the four required targets;
9. execute no tests, benchmarks, or custom meshes.

## P5-TB10 gates

- corrected route-complete and prior suites pass;
- direct completion succeeds with nonempty pure-quad output;
- at least two clean-exit deterministic random-bunny runs;
- no timeout, fallback, or recovery;
- wall ≤ 39.228299 s in every formal run;
- peak memory ≤ 1,115,394,560 B in every formal and supplementary run.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Plan.md`
- `benchmark-results/p5-tb9-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
