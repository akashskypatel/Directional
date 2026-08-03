# Milestone G Production Readiness TODO

Last updated: 2026-08-03
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — global ownership-frontier remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8.
- Validated artifact: `8844133680` (`surface-cell-p5-route-complete-linux-release`).
- Exact source: `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`.
- Digest: `sha256:1f32a4d3600d1a7be39e710d35273f80bed0c24850626d744ab15e7a748a34bb`.
- Completed turn: P5-TB10 artifact-only test and benchmark.
- Next turn: code changes + compile-only build.
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
- [x] P5-CB34–P5-CB41 — route-complete coupled-sector repair and artifact `8844133680`.
- [x] P5-TB10 — validate corrected tests and expose first-conflict progress-model failure.
- [ ] P5-CB42 — make packaged test fixtures executable-relative and self-contained.
- [ ] P5-CB43 — complete compact exact ownership-conflict inventory.
- [ ] P5-CB44 — exact latent/introduced conflict classification.
- [ ] P5-CB45 — deterministic global ownership frontier and independent repair batching.
- [ ] P5-CB46 — exact recomputation reuse and wall-time recovery.
- [ ] P5-CB47 — preserve memory margin with compact frontier/product storage.
- [ ] P5-CB48 — frontier, component, progress, reuse, and memory diagnostics/hashes.
- [ ] P5-CB49 — compile global-frontier regression sources.
- [ ] P5-CB50 — compile and package the global-frontier checkpoint.
- [ ] P5-TB11 — validate the global-frontier artifact without rebuilding.
- [ ] P6 — production topology/provenance/alignment/quality validation.
- [ ] P7 — focused and full regression closure.
- [ ] P8 — final bunny benchmark and production disposition.

## P5-TB10 tests

| Scope | Passed | Failed |
|---|---:|---:|
| Corrected route-complete subset | 6 | 0 |
| `PatchDescriptorMilestoneE.*` | 21 | 0 |
| Phase 16 + Phase 18 | 89 | 0 |
| Phase 14–18 aggregate | 229 | 0 |
| Milestone G P23 + Phase 20 | 52 | 0 |

Authoritative non-overlapping total: **302/302 passed**.

The manifest-dispatch test initially depended on the absolute compile-runner source path. Staging the exact packaged source archive at that path made the same binary pass. The next build must package and resolve test data without this workaround.

## P5-TB10 production result

Four independent clean-exit random-bunny processes all failed closed at completion:

- formal: 66.704669 s, 1,094,594,560 B;
- formal: 67.738376 s, 1,094,791,168 B;
- supplementary: 66.756596 s, 1,094,737,920 B;
- supplementary: 66.909710 s, 1,094,815,744 B.

Every process stayed below the memory cap, but the maximum independently measured resident set left only 20,472,320 B of margin. Every process failed the wall-time cap and produced zero output quads.

All completed records have identical structural hashes and route ledgers:

- active claim: `4956/4954`;
- route candidate count / consumed / attempts: `1 / 1 / 1`;
- route identity hash: `8326996045896577381`;
- route intervals: `8`;
- selected halfedges: `22706, 23112, 22707, 22710, 22824, 23924, 23922, 23932`;
- affected patches: `4952, 4954, 4955, 4956, 4957, 4958, 5184`;
- inserted vertices / split edges: `8 / 8`;
- result claim: `14137/14136`;
- route outcome: `introduced-ownership-claim`;
- full passes: `2`;
- peak live candidates: `1`;
- peak structural owned bytes: `210,773,020`;
- fallback/recovery: `false / false`.

The result claim patches do not intersect the candidate's affected-patch set. The current first-conflict assembly scan cannot prove whether the claim is latent or introduced, and the controller incorrectly requires every route candidate to reach zero conflicts in one pass.

## Next code/build authority

Use `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`.

Required implementation:

1. package test fixtures and remove absolute CI-source dependencies;
2. collect every exact completed-face ownership conflict in deterministic order;
3. compare complete pre/post inventories to prove retained, removed, latent, and introduced claims;
4. use strict conflict-set reduction as progress;
5. partition claims by exact dependency overlap;
6. batch pairwise-independent complete-route candidates atomically;
7. avoid one full global completion pass per claim through batching or exact dependency-hash reuse;
8. preserve fail-closed output, global budgets, exact state equality, and all validators;
9. recover wall time while preserving the remaining memory margin;
10. compile only the four required targets and execute no binaries.

## P5-TB11 gates

- all global-frontier and prior tests pass from an arbitrary extraction path;
- no source-path staging workaround is needed;
- at least two formal and two supplementary random-bunny processes exit cleanly;
- conflict inventory reaches zero deterministically;
- direct completion succeeds with nonempty pure-quad output;
- no timeout, fallback, or recovery;
- wall ≤ 39.228299 s in every process;
- peak memory ≤ 1,115,394,560 B in every process.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`
- `benchmark-results/p5-tb10-summary.json`
- `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Report.md`

P5 remains open. PR #8 remains draft and unmerged.
