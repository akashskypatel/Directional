# M3-CP4c-3-CB53 Independent Fragment-Count Oracle Code + Build Report

**Status:** COMPLETE / COMPILE-PROVED / PACKAGE112 ACCEPTED / RUNTIME-FREE

- Phase: `M3-CP4c-3-CB53`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build, with explicit pre-package compile proof
- Starting semantic source: `d1f4644cfaab70fb281cf7ce03b35769e295e399`
- Built evidence commit: `c772b53f1c42e117a948f14f77a33ab3dd2619a2`
- Handoff/closeout commit: repository commit containing this report and the frozen TB47 plan
- Remote synchronization verified: yes; exact semantic commit is pushed and both compile workflows checked out that SHA

## Implemented

CB53 made the one frozen test-authority correction in `tests/FieldAlignedCurveNetworkTests.cpp` inside
`independent_fragment_partition()`:

```text
old: fragmentOrbits[face].size() != tracePieces[face] + 1U
new: fragmentOrbits[face].size() >  tracePieces[face] + 1U
```

The adjacent comment now states the governing relation: `fragmentOrbits` is a set of distinct global face-walk
owners, multiple local fragments may share one owner, and only an owner over-count violates the frozen upper bound.
No product source, fixture, selector, benchmark input, frozen definition, carried-RED expectation, or build logic was
changed.

This is the generalized DEFN-R3.4 correction frozen by `M3-CP4c-3-TB46-R1-REV`; it is not a fixture-specific
exception and it does not make the oracle circular.

## Engineering-Guideline Review

- Material assumption surfaced: local-fragment -> global-owner mapping is not injective; `tracePieces + 1` is an
  upper bound on the distinct owner count, not an equality invariant.
- Simplest sufficient approach chosen: one comparison operator plus a two-line explanatory comment.
- Why no smaller approach satisfies the contract: changing only the comment would leave the false rejection live;
  changing any additional test/product surface would exceed the frozen authority.
- Unrelated refactors/style drift avoided: yes.
- Every changed line traces to objective/supporting validation: yes.

## Files Changed

Semantic source:

- `tests/FieldAlignedCurveNetworkTests.cpp` — 3 insertions / 1 deletion in the final independent
  `FragmentCountRule` guard.

Closeout-only durable records:

- this report;
- `Architecture_M3_CP4c3_TB47_Artifact_Only_Test_Benchmark_Plan.md`;
- current handoff/status/TODO/changelog/orientation pointers needed to name package112 and the exact successor.

## Domain Invariants

Static review of the exact pushed semantic commit verified:

1. the helper's final cardinality guard is exactly `>` against `tracePieces[face] + 1U`;
2. no sibling equality/`!=` restatement in that helper reintroduces local-fragment/global-owner injectivity;
3. CB51's final-no-barrier terminal separation still skips only when independently derived forward/reverse orbit IDs
   are equal;
4. retained separating terminal segments still receive the normal independent bookkeeping;
5. the semantic commit contains exactly one changed file, `tests/FieldAlignedCurveNetworkTests.cpp`;
6. `FragmentCountRule` remains the failure clause for a genuine owner over-count.

**Explicit out-of-scope authority:** the second stale equality at ordinal307
`GlobalTopologyPlan.CoversEverySourceFaceExactlyOnce` remains byte-unchanged. It is accepted/protected and currently
PASS. CB53 did not repair or weaken it. If that predicate later fires, the frozen review disposition is **oracle
drift, not a product regression**, and it requires its own authority under DEFN-R3.4.

## Generalization Review

- Why this is not fixture-specific: the predicate is expressed only in terms of independently derived local
  `tracePieces` and global face-walk owner sets for every source face; no fixture ID, face ID, cardinality constant,
  or known failing witness is consulted.
- Valid input classes affected: any independent fragment-partition witness in which multiple local fragments share a
  global face-walk owner.
- Regression risks considered: an owner over-count still fails; empty ownership still fails; terminal-slit separation
  and the remaining independent checks are unchanged; the full selector409 runtime gate is required next.

## Build

### Work-preservation and semantic apply

The exact patch was preserved before remote mutation:

- work-preservation patch SHA-256:
  `c84b5d727d8e8cb0a31a0655fdc6d9ca20a105bbbfbdd223624d22c8fc767658`;
- diff-body SHA-256:
  `c1f96f3c3c59b9781ba63b3f1d4fd442fb08b503f935163ad571c07f8d6951ca`;
- Drive apply run/job: `34390776043 / 102598299537` — success;
- apply result/log artifacts: `10119535220 / 10119535662`;
- applied semantic commit: `c772b53f1c42e117a948f14f77a33ab3dd2619a2`.

The consumed Google Drive staging file was permanently deleted after successful application and evidence capture.

### Required pre-package compile

`tests/FieldAlignedCurveNetworkTests.cpp` is owned by `directional_surface_cell_producer_tests`. CB53 first compiled
that changed owner target on the exact semantic source, before attempting the complete package:

- run/job: `34391251673 / 102599890497` — success;
- target: `directional_surface_cell_producer_tests`;
- result artifact: `10119786323`, provider/download SHA-256
  `9c519a81c5cd22906768816026a0c2de05d9ae973482e557cb12da98e6d44f10`;
- log artifact: `10119787111`, provider/download SHA-256
  `4846ce462605ff9973133ee4f01917fcc418a79c89a9377491d2c20a6f291431`;
- build/preflight exit: `0 / 0`;
- source status: clean;
- `runtimeExecution=false`;
- GMP/GMPXX link evidence present.

No generated Directional executable was run.

### Accepted package112 compile

The second compile used the same exact semantic source and all eight required selector409 package targets:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

Evidence:

- compile run/job: `34391561462 / 102600894187` — success;
- immutable package112 artifact: `10119861923`,
  `m3-cp4c3-cb53-package112-result-34391561462`;
- provider/download ZIP SHA-256:
  `3abab0f9d4248c838dc0009d3264fb68ce338a0f20160f7c4b325e28f2c24320`;
- persistent log artifact: `10119862314`, SHA-256
  `9dbe0ddc0ab6b4fda5f2e7edff5dc8721f5e9df44ad28d616b1f8589f455b72f`;
- packaged source archive SHA-256:
  `07955e1be63d35caf335537ca26e83363202a592fcf2542ac7414ec55857e931`;
- packaged `tests/FieldAlignedCurveNetworkTests.cpp` SHA-256:
  `0b0a1ce1bdf7c1778baf6c536659c690df955066aa4881b2ce6bd2c21fe9d3c2`;
- root manifest: **28/28 PASS**, self excluded and self-verification recorded;
- all six required executable binaries present;
- `libdirectional_core.a` and `libdirectional_pipeline.a` present;
- build/preflight exit: `0 / 0`;
- source status final: empty/clean;
- command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- GMP and GMPXX are linked from `/usr/lib/x86_64-linux-gnu/libgmp.so` and `libgmpxx.so`.

**Tests or benchmarks executed: none.** Building the benchmark executable does not constitute benchmark execution.
The retained activity log explicitly states that no generated Directional binary, test, benchmark, discovery,
`ctest`, CLI, fuzzer, help/version command, or custom input executed.

Package count therefore advances **111 -> 112**. Stable accounting remains **47 events / 14 categories / 33
recurrences**, produced-witness debt **5**, ownership **300/0/0**.

## Granular Loop Summary

- CB-DRAFT/work-preservation patch: SHA-256 `c84b5d727d8e8cb0a31a0655fdc6d9ca20a105bbbfbdd223624d22c8fc767658`.
- CB-APPLY: semantic commit `c772b53f1c42e117a948f14f77a33ab3dd2619a2`.
- CB-COMPILE #1: changed-owner pre-package compile `34391251673 / 102599890497` — PASS.
- CB-COMPILE #2: complete package112 compile `34391561462 / 102600894187` — PASS.
- Compile failures/corrective loop: none.
- Final CB-COMPILE result: PASS.
- CB-CLOSEOUT: this report plus frozen TB47 plan and durable current-state pointers.

## Known Risks

- CB53 proves compilation and package integrity only. Ordinal367's post-correction runtime behavior has not yet been
  measured.
- The accepted ordinal307 stale equality remains deliberately untouched and protected; see the explicit out-of-scope
  statement above.
- Carried runtime RED owners 368/369/370/374/398 remain open under their existing independent owners.
- TB46-R1/package111 remains the **promoted semantic runtime authority** until the successor execution is independently
  reviewed. Package112 is the new immutable **build authority**, not yet promoted runtime authority.

## Mandatory Test + Benchmark Plan

- Plan reference: `Architecture_M3_CP4c3_TB47_Artifact_Only_Test_Benchmark_Plan.md`.
- Template/equivalent: `templates/TEST_PLAN.md`.
- Evidence commit/artifact under test: source `c772b53f1c42e117a948f14f77a33ab3dd2619a2`, package112 artifact
  `10119861923`.
- Focused/reproduction validation: run ordinal367 through unchanged selector409 and retain its exact failure detail if
  it remains RED; the retired lower-owner-count equality must not be reintroduced as `FragmentCountRule`.
- Related regression validation: accepted prefix 1-365, protected 390/393/406/407, controls, carried owners, and
  retired-code silence are all observed from the same full gate.
- Integration/full/platform validation: all 409 selector identities, exactly once, one fresh process per identity on
  the artifact-only runner.
- Benchmarks: none; not applicable to this test-authority-only change.
- Acceptance criteria: mechanical integrity and full raw evidence per the frozen plan; no expected aggregate is
  frozen by CB53.
- Stop/blocker conditions: artifact/source/selector/harness mismatch, package integrity failure, selection mismatch,
  timeout, mutation, repair, build/relink/discovery, or orchestration failure.

## Next Turn

Type: Test + Benchmark

**Exact next subturn: `M3-CP4c-3-TB47-EXEC`.** It is runtime execution and evidence capture only. It must stop at
`M3-CP4c-3-TB47-REV` for independent diagnostic review and planning; EXEC does not self-adjudicate a RED gate.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`.
- Evidence commit: `c772b53f1c42e117a948f14f77a33ab3dd2619a2`.
- Test plan linked: `Architecture_M3_CP4c3_TB47_Artifact_Only_Test_Benchmark_Plan.md`.
- Updated/verified unchanged: TODO, current/forward state, changelog, orientation pointer, frozen definitions,
  selector409, carried RED owners.
- Agent entry-point links verified through the durable handoff.
- New lesson recorded: none; this turn follows existing lessons 72/73 by compiling the changed owner target before
  packaging the same fixed semantic source.
