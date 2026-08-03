# Milestone G P5 — Global Ownership Frontier Candidate-Budget Code + Build Plan

**Status:** P5-CB51 through P5-CB58 implemented and compiled  
**Completed artifact:** `8852049639` (`surface-cell-p5-cb58-memory-frontier-linux-release`)  
**Exact compiled source:** `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`  
**Next turn:** P5-TB12 artifact-only test and benchmark  
**Review policy:** `never`

The implementation and compile evidence are recorded in `.agents/Directional/Milestone_G_P5_Memory_Bounded_Frontier_Code_Build_Report.md` and `benchmark-results/p5-cb58-summary.json`. The plan below remains the scope authority for evaluating the implementation. Runtime correctness and actual RSS reduction are not claimed by the compile-only turn.

## Objective

Make the exact global ownership frontier executable on production input, restore the regressed contracts, package a genuinely self-contained test artifact, and reduce retained expanded state. P5-TB12 must validate this from the packaged artifact without rebuilding.

## P5-CB51 — Correct frontier budget semantics

Partition the exact frontier before applying work budgets.

- Count one atomic independent batch as one candidate evaluation/transaction.
- Do not charge the candidate budget once per exact conflict in the batch.
- Keep a separate diagnostic count for exact claims and route candidates.
- Apply structural-attempt, inserted-vertex, full-pass, and visited-state budgets to actual committed/evaluated transactions.
- Preserve deterministic component ordering and no arbitrary subset enumeration.
- Add regression sources where 92 independent exact claims fit one permitted batch and a second transaction is rejected by a one-transaction budget.

## P5-CB52 — Global completion-template ownership assignment

- Build the complete completion-template conflict graph before changing variants.
- Solve deterministic variant assignment by connected component.
- Batch independent variant changes and assemble once per assignment transaction.
- Preserve exact owner identities and reject genuinely introduced conflicts.
- Do not increase `maxCompletionOwnershipRepairs` as a workaround.
- Record initial/final inventory counts, component counts, changed patches, and assembly passes.

## P5-CB53 — Make exact reuse observable and correct

- Prove which patches are outside each transaction dependency closure.
- Reuse only products whose exact semantic dependencies are unchanged.
- Do not let incidental cell, row, or index renumbering invalidate otherwise identical dependencies; canonicalize those identities first.
- Emit per-product reuse/mismatch reason diagnostics in debug/test builds.
- Ensure cache extraction cannot erase authoritative rollback state or successful result payloads.
- Require at least one genuinely unaffected cached product in fixtures that assert reuse.

## P5-CB54 — Restore fail-closed result invariants and diagnostics

- `success == true` must imply nonempty descriptors, completed patches, assembled quads, and valid lineage unless an explicit empty-input contract exists.
- Restore bounded conflict diagnostics required by `CompletedFaceOwnershipCanonicalizesRotationAndReversal`, including backend and corner identity kinds.
- Preserve complete compact inventories while retaining one bounded verbose first-conflict record.
- Preserve typed semantic-overlap failures such as `SameCornerDistinctBoundaryOverlap`.

## P5-CB55 — Remediate authoritative regression failures

Reproduce each failing test with its stated precondition and make a surgical correction:

- six `PatchDescriptorMilestoneE` failures;
- one `PureQuadCompletionPhase18` failure;
- two `SurfaceCellPipelinePhase20` failures;
- three Milestone D closure failures.

Do not modify expectations merely to match current behavior. Correct fixture construction only when it does not create the intended scenario, and add an explicit precondition assertion before the tested outcome.

## P5-CB56 — Package the complete runtime fixture closure

- Package `milestone_g_manifest.json`, `repo_regressions.json`, and every transitively referenced mesh and field fixture required by compiled tests.
- Resolve all test data relative to the executable or a deterministic packaged fixture root.
- Remove all runtime dependence on `/home/runner/work/...`.
- Verify that the packaged test binary can resolve required manifests from an arbitrary working directory.

## P5-CB57 — Recover wall time and reduce retained memory

- Eliminate repeated full assembly after each single completion-template variant.
- Execute the same-corner frontier as the smallest number of deterministic atomic transactions.
- Reuse unchanged exact completion products.
- Retain one live mutable candidate and one canonical rollback complex.
- Release consumed production intermediates and move expanded stage payloads.
- Compact ownership storage and defer final output/provenance/lineage allocation until zero conflicts.
- Add stage/pass and owned-byte counters so P5-TB12 can attribute wall time and RSS.

## P5-CB58 — Compile-only gate

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Package exact pushed source, empty source status, complete executable-relative fixtures, binaries, libraries, logs, submodule revisions, and checksums. Execute no binary, test, benchmark, help/list command, discovery command, or custom mesh.

This gate completed successfully in run `30803697079`, job `91654036551`: **131/131** build steps, empty source status, and **36/36** packaged checksums.

## P5-TB12 gates

The artifact-only turn must require:

- focused global-frontier, memory-lifetime, budget, reuse, and fixture-portability tests pass;
- authoritative non-overlapping P5 total passes;
- full packaged binary runs without absolute-path fixture failures;
- four independent random-bunny processes succeed with nonempty pure-quad output;
- exact conflict inventory reaches zero deterministically;
- no fallback or recovery;
- wall `<= 39.228299 s` and memory `<= 1,115,394,560 B` in every process;
- direct comparison with the P5-TB11 peak of `936,484,864 B`, with stage-owned byte diagnostics used to explain process RSS.
