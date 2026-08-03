# Milestone G P5 — Bounded Structural Repair Code + Build Report

**Turn type:** Code changes + compile-only build  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Review policy:** `never`

## 1. Authoritative input

This turn implemented `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Code_Build_Plan.md` against the P5-TB8 evidence from artifact `8842377256`.

P5-TB8 established that the first same-corner structural-repair implementation passed all 296 authoritative regressions but did not terminate on the production random-bunny fixture within 60 seconds and reached approximately 2.552 GiB peak memory. The failure was isolated to recursive completion/ownership repair after simplification.

## 2. Implemented production changes

### One invocation-owned global ledger

- Split the former recursive implementation into a non-recursive `complete_surface_cell_complex_pass()` and a single public transaction controller.
- The controller owns one deterministic ledger for the entire invocation:
  - candidate evaluations;
  - structural attempts;
  - inserted boundary vertices;
  - full completion passes;
  - visited exact repair states;
  - current and peak live candidate complexes;
  - typed exhaustion reason.
- Every candidate consumes the same global limits. No candidate receives a reset depth-local repair budget.
- Default production limits are two candidate evaluations, two structural attempts, eight inserted vertices, three full completion passes, and three visited states.

### Exact repair-state deduplication

- Added collision-safe canonical repair-state identity over complete arrangement topology, exact source/domain and boundary identities, inserted splits, and the active ownership claim.
- Exact identity equality controls visited-state rejection; hashes remain diagnostic only.
- Canonically repeated states fail closed as `RepeatedState` without another recursive evaluation.

### Single-candidate memory discipline

- The prepared complex is retained as the rollback state and at most one mutable candidate complex exists at a time.
- Rejected descriptor arrays, completed patch meshes, assembly meshes, and candidate complexes are explicitly released before the next candidate.
- The result records current and peak live candidate-complex counts.
- No recursive result tree or candidate subtree is retained.

### Strict progress and ownership routing

- Same-corner candidates are selected in deterministic exact-boundary order.
- A claim with no geometrically distinct authoritative boundary route fails before candidate expansion as `SameCornerDistinctBoundaryOverlap`.
- A candidate is committed only when the recomputed assembly succeeds and the active ownership-claim count decreases from one to zero.
- Persistence of the original pair is typed `NoProgress`.
- A different ownership conflict is typed `IntroducedOwnershipClaim`; replacing one conflict with another is never committed.
- Validation failures, repeated states, and every budget exhaustion are fail-closed and observable.
- Full recomputation remains in use because incremental equivalence has not yet been proven; it is bounded by the global full-pass ledger and reported separately from incremental passes.

No final-face deletion or deduplication, positional vertex merge, source-triangle pairing, source-grid recovery, legacy fallback, patch-ID special case, or validator weakening was introduced.

## 3. Diagnostics and benchmark observability

Completion results, pipeline diagnostics, structural hashes, and benchmark JSON now include:

- structural candidate budget and consumed count;
- structural attempt and inserted-vertex totals;
- exact visited-state count;
- full and incremental recomputation counts;
- current and peak live candidate-complex counts;
- last candidate halfedge and affected patch set;
- typed exhaustion reason;
- per-attempt candidate index, structural attempt, recomputation pass, live-candidate count, inserted vertices before/after, repeated-state/progress/new-claim flags, outcome, and affected patches.

## 4. Regression sources added

The following test sources compile but were intentionally not executed in this turn:

- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
- `SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`;
- `ZeroStructuralBudgetFailsBeforeCandidateExpansion`;
- `OneCandidateBudgetIsExactAndDoesNotRecurse`;
- `StructuralRepairLedgerIsPatchOrderInvariant`.

These tests invoke `complete_surface_cell_complex()` with authoritative DCEL/source inputs rather than only testing stitch-time classification. Runtime validity is deferred to P5-TB9.

## 5. Source checkpoint

- Exact implementation and compiled source: `bc95579be68d5de073de956022eec8fb89120ec0`.
- Commit: `fix(surface-cells): bound structural repair search`.
- Seven production/regression files changed.
- Transient encoded patch payloads were removed before the source commit.
- The standard compile-only workflow was restored after artifact creation in documentation-only commit `a7daaf8bb8ef63f8fee9cb7a1383e18e7e485595`.

## 6. Compile-only evidence

- Workflow run: `30779430182` — **success**.
- Job: `91581037642` — **success**.
- Artifact: `8843206930`, `surface-cell-p5-bounded-repair-linux-release`.
- Artifact digest: `sha256:9b6ef73f2bd04eb49486cd7f0f28a1d2e9121a36791c7dd25fe1ffcc19d64f94`.
- Toolchain: GCC 13.3.0, optimized static Release build.
- Build steps: **131/131 completed**.
- Required targets compiled and linked:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.

Artifact verification:

- `source-commit.txt` is exactly `bc95579be68d5de073de956022eec8fb89120ec0`;
- `source-status.txt` is empty;
- all ten packaged checksums pass;
- test and benchmark outputs are Linux x86-64 ELF executables;
- core and pipeline outputs are valid static archives;
- exact source archive, configure/build logs, and recursive submodule revisions are included.

No test, benchmark, or custom mesh executable ran in this turn.

## 7. Status and handoff

P5 remains open. Compilation establishes source validity only; it does not prove termination, runtime, memory, or correctness of the new structural-repair tests.

The next authoritative turn is **P5-TB9 test and benchmark using artifact `8843206930` without rebuilding**. It must:

1. verify exact source, empty status, and all packaged checksums;
2. execute all new whole-complex structural-repair tests and the prior required suites;
3. run at least two independent direct random-bunny processes with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled;
4. require terminal completion or a typed bounded fail-closed result without timeout;
5. record the complete deterministic global ledger and structural hashes;
6. verify no fallback or recovery;
7. enforce peak memory no greater than 1,115,394,560 B;
8. enforce wall time no greater than 39.228299 s unless a correctness-driven exception is independently reviewed.

PR #8 remains draft and unmerged.
