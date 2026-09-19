# M4-CP4-CB3 — TB1-R1 harness control correction Code + Build plan

**Turn:** `M4-CP4-CB3`
**Type:** runtime-free control-only correction
**Predecessor:** `M4-CP4-TB1-R1-EXEC`
**Candidate package retained unchanged:** `10575545321`
**Exact compiled source retained unchanged:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`

## 1. Goal

Correct `M4-CP4-TB1-R1-ORCH-01` without changing product, test, fixture, selector, benchmark, CMake or candidate-package semantics. R1 proved package preflight but the frozen harness re-enabled shell `errexit` inside `run_one`, so the first semantic RED terminated the harness before the remaining focused rows and immutable postflight.

## 2. Frozen correction boundary

The only behavioral correction authorized is to the artifact-only harness control flow:

- `run_one` must capture the selected process exit code without changing the caller's `errexit` state;
- a semantic RED/SKIP/crash may return nonzero to the outer loop, but must not terminate the harness while the outer loop is under `set +e`;
- all six focused rows still execute unless orchestration integrity fails;
- selector427 still runs in exact order after focused execution unless orchestration integrity failed, stopping after its first semantic non-green;
- mandatory package/source/execution-view immutable postflight still runs whenever runtime started;
- the 433-row ledger, exactly-one-selected rule, benchmark zero and all no-repair/no-build/no-discovery counters remain unchanged.

A minimal implementation is to remove the inner `set +e` / `set -e` toggle around the generated process and capture the command status through shell conditional control, leaving the outer caller's shell mode untouched. Do not broaden the harness contract.

## 3. Explicit non-scope

Do **not** change `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`, `SurfaceComplexSimplificationPhase17Tests.cpp`, `torus.rawfield`, fixture formatting, product code or selector427 in CB3. R1's row-2 `Invalid rawfield fixture header` is diagnostic-only because the run lacks mandatory postflight and full focused execution. A corrected fresh retry must establish trustworthy evidence before Review assigns any semantic/test owner.

Do not recompile or repackage candidate artifact `10575545321`: R1 independently re-proved its ZIP/source hashes, complete manifest, clean receipts, GMPXX+GMP, owner partition and executable modes before runtime. CB3 changes no compiled source byte. If any semantic or package change becomes necessary, stop and return to Review/Plan rather than widening this turn.

## 4. Control freeze

1. Start from current branch authority and `READ_MODE=snapshot`.
2. Recover the R1 harness exactly and make only the bounded `errexit` correction above.
3. Validate the corrected shell syntax and independently inspect the changed control path so a semantic nonzero reaches the outer loop without aborting before counter update/postflight.
4. Freeze the corrected R2 harness by exact byte count and SHA-256.
5. Freeze an R2 caller using the same permissions, artifact-only boundary and observer/schema jobs, changing only retry names/paths necessary for `M4-CP4-TB1-R2-EXEC`; SchemaStore-validate it before execution authority.
6. Execute **no generated Directional runtime** in CB3. Compile/configure/test/benchmark/discovery/list/help/version commands are forbidden.

## 5. Exit

On successful static/control freeze, exact successor is **`M4-CP4-TB1-R2-EXEC`**, consuming the same immutable artifact `10575545321` from scratch. R2 must execute the full six-focused surface, selector427 according to the frozen stop rule, and mandatory immutable postflight. Any trustworthy semantic outcome then routes to Review.
