# M4-CP-COND-CB3 Code + Build Plan

**Turn:** `M4-CP-COND-CB3`
**Type:** Code + Build / test-authority-only / runtime-free
**Owner candidate:** `M4-CP-COND-TB2-REV-CAND-01`
**Product semantic source entering turn:** `b576d061e23873b7b4193b158138d2097c75a728`
**Selector authority:** M4 selector408, 408 LF rows / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
**Runtime in CB3:** forbidden

## 1. Objective

Repair only `InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved` so its negative-index precondition is proved from the actual raw witness bytes rather than authored constants. Preserve production conditioner semantics and every accepted selector identity.

## 2. Mandatory pre-mutation guards

1. Re-read CP-COND frozen §10/§12 and the TB2 Review.
2. Re-hash selector408 and first403 to the frozen hashes.
3. Confirm the only authorized semantic edit is `tests/InputConditionerTests.cpp`; preserve the existing test identity.
4. Prototype an independent oracle over the committed `raw.faces` + `raw.rawCrossField` bytes and prove:
   - local four-branch nonzero/opposite-pair admissibility;
   - unique exact/discrete cross-face Z4 transport around the central cycle;
   - signed/principal cycle accumulation with numerator `-1`.
5. Pre-prove a raw-data mutation control from the same fixture that either changes the independently derived cycle numerator or makes the raw field/transport inadmissible.

If this cannot be done exactly without production output or a product semantic change, **STOP before mutation and return to Review/DEFN**.

## 3. Authorized test edit

Only `tests/InputConditionerTests.cpp` may change semantically. The file-local oracle may exactly decode binary64 components into exact arithmetic, derive mesh-cycle support, derive local admissibility and unique cross-face branch transport, calculate the source-derived numerator, and run the pre-proved raw mutation discriminator.

The oracle must not call production transport/singularity/finalization helpers, read production matching/singularity output, or recover the answer from authored `72°`, `90°`, sector-count, face ordinal, or a prefilled numerator field.

## 4. Frozen exclusions

No changes to `src/**`, `include/**`, public API, product semantics, other test identities, selectors/manifest, CMake semantics, accepted A3/A4 semantics, reusable workflow permissions/behavior, or the boundary-truncated report-only blocker. No epsilon/tolerance authority. Any such need is a STOP.

## 5. Compile/package gate

Compile only through the approved GitHub workflow, GMP/GMPXX mandatory, `runtimeExecution=false`, no Directional runtime.

Exact target set:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`

Package all four selector-owner binaries, compiled API and required libraries with clean source receipts/checksums/modes.

## 6. Frozen TB3 handoff

Freeze `M4-CP-COND-TB3-EXEC` against the immutable CB3 package:

- all 14 existing focused identities once each in fresh exact-filter processes;
- boundary-truncated separatrix once as expected report-only SKIP/non-selector;
- all 408 accepted selector identities once each;
- immutable package/source/selector/execution-view preflight/postflight;
- no rebuild/configure/relink/package repair/generated discovery/source-test-fixture-selector mutation.

Expected process count remains 423. Mechanical green is 14/14 focused PASS + one report-only SKIP + selector408 408/408 PASS, zero RED/crash/selection mismatch, exact postflight. Mandatory successor is `M4-CP-COND-TB3-REV`; only that Review may close the candidate, promote the package, or close CP-COND.
