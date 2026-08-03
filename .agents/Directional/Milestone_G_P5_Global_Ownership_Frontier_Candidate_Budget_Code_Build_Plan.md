# Milestone G P5 — Global Ownership Frontier Candidate-Budget Code + Build Plan

**Next turn:** code changes + compile-only build  
**Input:** P5-TB11 artifact `8848599037`  
**Review policy:** `never`

## Objective

Make the exact global ownership frontier executable on production input, restore the regressed contracts, and package a genuinely self-contained test artifact. Do not run tests or benchmarks in this turn.

## P5-CB51 — Correct frontier budget semantics

Partition the exact frontier before applying work budgets.

- Count one atomic independent batch as one candidate evaluation/transaction.
- Do not charge the candidate budget once per exact conflict in the batch.
- Keep a separate diagnostic count for exact claims and route candidates.
- Apply structural-attempt, inserted-vertex, full-pass, and visited-state budgets to actual committed/evaluated transactions.
- Preserve deterministic component ordering and no arbitrary subset enumeration.
- Add compile-only regression sources where 92 independent exact claims fit one permitted batch and a second transaction is rejected by a one-transaction budget.

## P5-CB52 — Global completion-template ownership assignment

The production pass currently performs 41 sequential completion-variant commits and full assembly scans.

- Build the complete completion-template conflict graph before changing variants.
- Solve deterministic variant assignment by connected component.
- Batch independent variant changes and assemble once per assignment transaction.
- Preserve exact owner identities and reject genuinely introduced conflicts.
- Do not increase `maxCompletionOwnershipRepairs` as a workaround.
- Record initial/final inventory counts, component counts, changed patches, and assembly passes.

## P5-CB53 — Make exact reuse observable and correct

Investigate the zero-reuse failures before changing tests.

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

The artifact must support all packaged tests from any extraction path.

- Package `milestone_g_manifest.json`, `repo_regressions.json`, and every transitively referenced mesh and field fixture required by compiled tests.
- Resolve all test data relative to the executable or a deterministic packaged fixture root.
- Remove all runtime dependence on `/home/runner/work/...`.
- Add a test that scans the packaged test binary's required manifests from an arbitrary working directory.

## P5-CB57 — Recover wall time

The target remains `39.228299 s` in every process.

- Eliminate repeated full assembly after each single completion-template variant.
- Execute the same-corner frontier as the smallest number of deterministic atomic transactions.
- Reuse unchanged exact completion products.
- Retain one live mutable candidate and the existing memory cap.
- Add stage/pass counters so P5-TB12 can prove the number of full and incremental assemblies.

## P5-CB58 — Compile-only gate

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Package exact pushed source, empty source status, complete executable-relative fixtures, binaries, libraries, logs, submodule revisions, and checksums. Execute no binary, test, benchmark, help/list command, discovery command, or custom mesh.

## P5-TB12 gates

The following artifact-only turn must require:

- focused global-frontier tests pass;
- authoritative non-overlapping P5 total passes;
- full packaged binary runs without absolute-path fixture failures;
- four independent random-bunny processes succeed with nonempty pure-quad output;
- exact conflict inventory reaches zero deterministically;
- no fallback or recovery;
- wall `<= 39.228299 s` and memory `<= 1,115,394,560 B` in every process.
