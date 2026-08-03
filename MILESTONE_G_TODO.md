# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — bounded same-corner structural repair.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8.
- Validated artifact: `8842377256`.
- Exact source: `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`.
- Digest: `sha256:669bf5d6f3e9b3738298b5985b6bb715668bce0715b0a68d880eb4aa0e80d6bc`.
- Completed turn: P5-TB8 artifact-only test and benchmark.
- Next turn: code changes + compile-only build.
- Review policy: `never`.

## Work phases

- [x] P0–P4 — reproducibility, diagnosis, singular traces, and regular-disk completion.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB1–P5-CB20 — canonical ownership, intrinsic support, diagnostics, and compaction.
- [x] P5-TB7 — reach assembly and classify the deterministic `8595/8573` same-corner conflict.
- [x] P5-CB21–P5-CB26 — same-corner classification, initial structural repair, corrected fixtures, and artifact `8842377256`.
- [x] P5-TB8 — validate regressions and expose deterministic completion-stage resource runaway.
- [ ] P5-CB27 — replace recursive search with one global repair-work ledger.
- [ ] P5-CB28 — canonical repair-state deduplication and single-candidate memory discipline.
- [ ] P5-CB29 — strict monotonic progress and fail-closed overlap routing.
- [ ] P5-CB30 — reuse unaffected products where equivalence is proven.
- [ ] P5-CB31 — whole-complex structural-repair, budget, cycle, and order-invariance tests.
- [ ] P5-CB32 — observable global-budget, visited-state, recomputation, and live-candidate diagnostics.
- [ ] P5-CB33 — compile and package the bounded-repair checkpoint.
- [ ] P5-TB9 — validate the bounded-repair artifact without rebuilding.
- [ ] P6 — production topology/provenance/alignment/quality validation.
- [ ] P7 — focused and full regression closure.
- [ ] P8 — final bunny benchmark and production disposition.

## P5-TB8 tests

| Scope | Passed | Failed |
|---|---:|---:|
| Focused corrected fixtures and ownership tests | 9 | 0 |
| `PatchDescriptorMilestoneE.*` | 15 | 0 |
| Phase 16 + Phase 18 | 89 | 0 |
| Phase 14–18 aggregate | 229 | 0 |
| Milestone G P23 + Phase 20 | 52 | 0 |

Authoritative non-overlapping total: **296/296 passed**.

## Production benchmark failure

Two independent direct runs timed out at 60.05 seconds before benchmark JSON or a terminal conflict record was produced:

- peak RSS 2,740,543,488 B;
- peak RSS 2,740,506,624 B;
- mean 2,740,525,056 B (2.552 GiB).

A run injected after simplification completes in 19.260599 seconds at 343,326,720 B with 21,298 cells. The runaway begins in completion/ownership repair.

Compared with artifact `8841726806`, the bounded lower regression is already +129.62% wall and +207.13% memory. The `8595/8573` claim disposition remains unresolved because completion never returned.

## Root cause and test gap

The current structural-repair implementation recursively evaluates multiple candidates, copies the full complex, and reruns complete descriptor/completion/assembly work at every depth. Budgets are depth-local, there is no shared global work ledger, and canonical repair states are not memoized.

Existing tests cover the stitch-time conflict class only. They do not invoke whole-complex `BoundarySectorSubdivision`, assert global attempt limits, or exercise repeated-state termination. Passing tests therefore do not establish the intended production behavior.

## Next code/build authority

Use `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Code_Build_Plan.md`.

The next implementation must:

1. eliminate recursive candidate-tree expansion;
2. share one deterministic global budget across all candidates;
3. memoize exact canonical repair states;
4. retain only one candidate and rollback snapshot;
5. require strict progress and reject replacement ownership conflicts;
6. fail unrepairable overlap before search;
7. add actual whole-complex structural-repair and boundedness tests;
8. expose global budget, visited states, recomputation, live-candidate, and exhaustion diagnostics;
9. compile only the four required targets;
10. execute no tests, benchmarks, or custom meshes.

## P5-TB9 production gates

- no direct-run timeout;
- no fallback or recovery;
- deterministic repair ledger and hashes;
- peak memory ≤ 1,115,394,560 B;
- wall time ≤ 39.228299 s unless a correctness-driven exception is independently reviewed;
- all structural-repair and prior regression suites pass.

P5 remains open. PR #8 remains draft and unmerged.
