# M4-CP-SCALE-CB2 Code + Build Plan — S2 Vertex-Star Certified Filter Equivalence

**Turn:** `M4-CP-SCALE-CB2`
**Boundary:** Code + Build only; `runtimeExecution=false`.
**Entering accepted authority:** package `10360085644`, semantic source `a359b981f9350139304bc5a654041dfba78609b6`, selector423 **423/423**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.
**Frozen source:** `Architecture_M4_CP_SCALE_Frozen_Definitions.md` §3 and `M4-CP-SCALE-TB1-REV`.

## 1. Prediction and scope

The existing vertex-star mechanism already has a certified filter and exact fallback. CB2 tests one falsifiable prediction:

> On the same independently constructed vertex-star subjects, every production answer returned through the certified Filter route equals an independent exact oracle, every Inconclusive/filter-boundary case defers to the exact semantic path, and both `Filter` and `ExactFallback` routes are exercised non-vacuously — **without changing production semantics**.

CB2 is therefore **test-authority first**. The default authorized semantic change is only the new S2 identity and test-local independent-oracle helpers in `tests/FieldAlignedCurveNetworkTests.cpp`. No production/API/CMake/fixture change is presumed necessary because existing tests already expose production route metadata through `VertexStarTransitAudit`.

If satisfying the identity requires a production semantic change, a new public semantic API, an arrival-order fallback, or a selector change, **STOP and return to Review** rather than broadening CB2.

## 2. Frozen identity

Author exactly one new identity:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

It remains **outside selector423 in CB2**. Frozen definitions require source, compile evidence and independently proved preconditions before an S2 row may be appended. CB2 may not pre-credit its own unexecuted identity by modifying the selector.

## 3. Independent-oracle contract

The expected result must be independently derived from exact subject inputs. The oracle may use the project's exact rational primitive (`FieldExactRational`/GMP), but it must **not**:

- call `vertex_star_compare_angle_sums`, the product filter, or the product exact-recursive comparator to obtain the expected answer;
- derive expected owner/order from the production decision being tested;
- exactify a previously approximate semantic decision with `from_double_exact()` and then call it independent;
- use epsilon/proximity/tolerance as semantic authority;
- mirror an implementation branch merely under different helper names.

The test-local derivation must state its source of truth and publish enough exact subject data on PASS for Review to reproduce the expected sign/owner.

## 4. Required subject matrix and falsifiers

The single identity must include all of the following independently constructed cases:

1. **positive / strict interior:** exact oracle and production agree on one side of the comparison and the production audit reports `VertexStarDecisionKernelRoute::Filter`;
2. **negative / opposite order:** exact oracle reverses the comparison/owner and production agrees;
3. **near-boundary but certified:** a nonzero exact subject close enough to the equality surface to challenge interval certification while still yielding an independently determined exact sign;
4. **exact-boundary / fallback:** the filter cannot own the semantic result and production reports `VertexStarDecisionKernelRoute::ExactFallback`, with exact half-open ownership checked independently;
5. **discriminating tamper:** change one exact input that the oracle reads so the expected result changes (or the subject crosses the exact boundary), and prove the same production/oracle comparison catches the change.

At least one subject must exercise `Filter` and at least one must exercise `ExactFallback`. `RationalShortCircuit` does not satisfy either requirement. Merely observing route enum values without independently checking the exact semantic answer is insufficient.

The test must fail if any of these are deleted: independent exact comparison, Filter-route subject, ExactFallback-route subject, boundary case, or tamper discriminator.

## 5. Static/non-runtime preflight

Before editing, enumerate:

- all existing `VertexStarDecisionKernelRoute` production writers;
- all existing tests that assert `Filter`, `ExactFallback`, or `RationalShortCircuit`;
- the exact test binary owning `FieldAlignedCurveNetworkTests.cpp`;
- selector423 owner partition **30 / 277 / 75 / 41** and current selector hash.

The census is evidence for scope only; it must not execute generated Directional binaries or `--gtest_list_tests`.

## 6. Source boundary

Authorized semantic/test-source path:

- `tests/FieldAlignedCurveNetworkTests.cpp` — exact S2 identity and test-local independent oracle only.

Documentation, report/plan, and packaging metadata may change as required for Code + Build closeout. Production `src/` and `include/` are **frozen by prediction**. If a production change is discovered to be necessary, STOP for Review instead of making it.

Forbidden in CB2:

- S1 threshold or 4096-bit guard change;
- arrival/arclength ordering work or an invented exact fallback;
- S3 cycle semantics/witness work;
- S4 topology/cut selection/rejection work;
- S5 fixture construction;
- CP4 produced-witness work;
- row399/row408 unrelated hardening;
- selector423 mutation or selector424 publication;
- fixture weakening, epsilon authority, or float-derived exactification;
- Directional runtime/test/benchmark execution.

## 7. Compile/package gate

After the test source is authored, compile/package using the project GitHub workflow with GMP/GMPXX and `runtimeExecution=false`.

Require:

- exact pre-package source authority recorded;
- the new test identity compiles in `directional_surface_cell_producer_tests`;
- all accepted selector423 owner executables are packaged for its later artifact-only successor;
- the same eight approved CB1 build/package targets are GREEN unless the live reusable workflow proves an equivalent superset;
- package manifest is self-excluding and fully verifies;
- packaged selector423 remains exactly **423 LF rows / `4e67e4dc...d89343`** with first422 `bbd496f3...f7cc`;
- source-status receipts are clean;
- no generated Directional binary/test/benchmark/discovery/CLI/fuzzer/help/version/custom-input command executes.

Compile-green is not runtime acceptance. CB2 must not claim S2 gate credit.

## 8. Expected artifact-only successor contract

If and only if CB2 compiles/packages GREEN, its closeout may freeze an artifact-only TB2 plan that consumes that exact package without rebuild/repair. The expected minimum TB2 surface is:

- focused S2 identity exactly once in a fresh process, requiring its complete subject/route/tamper receipt;
- accepted selector423 as 423 fresh exact-filter processes with static owner mapping;
- exact package/source/execution-view postflight.

TB2 remains unable to append/promote an S2 selector row by itself; mandatory Review adjudicates whether the S2 precondition is actually proved and whether a later selector-publication CB is justified.

## 9. STOP rules

STOP without broadening the turn if any of the following occurs:

- an independent exact oracle cannot be constructed without calling/mirroring the mechanism under test;
- no exact subject can exercise `Filter` and `ExactFallback` non-vacuously;
- the tamper does not change an independently derived semantic expectation;
- product `src/`/`include/` semantics or a new public semantic API appear necessary;
- the work drifts into arrival ordering, S3/S4/S5, S1 threshold calibration, CP4, row399 or row408;
- selector423 would need to change before runtime proof/Review;
- compile/package cannot preserve the complete accepted owner set or GMP authority;
- any attempt would execute generated Directional runtime inside Code + Build.

On STOP, preserve the exact partial source as a recovery patch and return to Review with the blocking premise named. Do not substitute a weaker oracle, tolerance, selector shrink, or implementation change.

## 10. Success criteria

CB2 is complete only when the bounded S2 identity is authored with the complete matrix and independent-oracle structure, exact source compiles/packages GREEN under the frozen no-runtime boundary, selector423 is byte-identical, and the immutable package is ready for a separately authorized artifact-only TB. No runtime result, S2 selector credit, scale threshold, or CP-SCALE closure is claimed by CB2.
