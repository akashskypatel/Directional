# M4-CP2-TB1 Artifact-Only Test + Benchmark Plan

**Status:** ISSUED / EXACT NEXT EXECUTION PLAN
**Execution turn:** `M4-CP2-TB1-EXEC`
**Review turn:** `M4-CP2-TB1-REV`
**Boundary:** immutable artifact-only runtime; no compile/relink/regeneration/mutation

## 1. Immutable authority

Consume exactly the CB1 compile package below; do not rebuild it.

- source/evidence commit: `eb23177e6ee9cbb27cf1ee30a299911abc0e1c60`;
- package artifact ID: `10166351695`;
- artifact name: `directional-m4-cp2-cb1-package116-result-34512397141`;
- provider/download ZIP SHA-256: `c61b9900a2745454594825de81181ce982ec4b7986f40aa3b23c23e12d0e8e61`;
- compile run/job: `34512397141 / 102989549611`;
- compile log artifact: `10166352142`;
- selector: `Architecture_M4_CP2_Required_Green_Selector_380.txt`;
- selector380 LF SHA-256: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- accepted selector373 prefix SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- expected owner partition: **30 authority-kernel / 234 producer / 75 completion / 41 validation**.

The seven appended rows are selector ordinals **374-380** and are all owned by `directional_surface_cell_producer_tests`.

## 2. Preflight — no Directional runtime before all checks pass

The EXEC harness must fail as orchestration failure before semantic runtime if any preflight check fails.

1. Download artifact **10166351695** only and verify its ZIP SHA-256 exactly.
2. Extract to a fresh execution workspace. Do not modify package bytes or executable modes to make preflight pass.
3. Run `sha256sum -c SHA256SUMS`; require **28/28** entries to verify.
4. Require `metadata/source-commit.txt` to equal the exact evidence SHA above.
5. Require `metadata/build-exit-code.txt == 0`, `metadata/preflight-exit-code.txt == 0`, all packaged source-status files empty, and `metadata/command-boundary.txt` to contain `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`.
6. Verify `metadata/gmp-evidence.txt` contains both GMPXX and GMP linkage.
7. Extract the package-owned source archive to a fresh read-only/source view and verify selector380 count/hash plus the first-373-row prefix hash.
8. Derive the selector identity-to-owner map from package-owned source/CMake authority. Require exactly 380 identities, no missing or duplicate owner, and the partition **30 / 234 / 75 / 41**.
9. Require all four owner executables to exist and be executable as packaged. Do not run `--gtest_list_tests` or generated discovery.
10. Record package, extracted-source, and execution-view byte censuses for immutable postflight comparison.

A zero-selected identity, missing owner, hash mismatch, source mismatch, package repair need, mode repair need, or generated-discovery need is **orchestration failure**, not PASS/RED/SKIP.

## 3. Focused CP2 deterministic receipt — phase A and phase B

Run selector ordinals **374-380** twice, in frozen order, one identity per fresh process. Use the exact owner derived in preflight; all seven are expected to map to `directional_surface_cell_producer_tests`.

For each identity execute only:

```text
timeout -k 5s 180s ./bin/<owner-binary> --gtest_filter='<exact identity>' --gtest_color=no
```

Do not add test retries. Require exactly one selected/running identity per process. Preserve raw stdout/stderr, exit status, timeout status, elapsed time, identity, ordinal, and owner. A timeout is orchestration/infrastructure failure for this focused run, never a semantic skip/pass.

Focused acceptance requires:

- phase A: **7 PASS / 0 RED / 0 SKIP / 0 timeout**;
- phase B: **7 PASS / 0 RED / 0 SKIP / 0 timeout**;
- phase A/B verdict vectors identical;
- each process shows the intended exact identity executing rather than merely returning exit 0.

## 4. Complete cumulative selector380 gate

After focused phases complete, execute all **380** selector identities in frozen order, one identity per fresh process, through the exact owner map. Use the same per-process command and timeout contract. Do not partition the gate into independently acceptable partial suites and do not impose an outer timeout whose purpose is to terminate the required full gate.

Report separately:

- accepted predecessor rows 1-373;
- new CP2 rows 374-380;
- total PASS/RED/SKIP/timeout;
- selection mismatches/missing owners/duplicate owners;
- owner totals and per-owner outcomes.

The semantic green target is:

- selector380: **380/380 PASS**;
- predecessor selector373: **373/373 PASS**;
- CP2 rows: **7/7 PASS**;
- **0 RED, 0 SKIP, 0 timeout, 0 selection mismatch**;
- focused A/B both 7/7 with identical verdict vectors.

Do not convert an unexpected result into a new expected value during EXEC.

## 5. Required CP2 semantic receipts

Raw logs and the EXEC ledger must make the following seven frozen identities independently inspectable:

1. `GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle`
2. `GlobalConformityCertificate.CarriesBindingPositivityParityObjectiveAndTerminalWitness`
3. `GlobalConformityCertificate.IndependentVerifierRejectsTerminalWitnessTamper`
4. `GlobalConformityOutcome.FeasibleCP2PathPreservesCP1ScheduleExactly`
5. `GlobalConformityOutcome.InfeasibleComponentReturnsTypedSubsetInsteadOfFatalError`
6. `GlobalConformityOutcome.InfeasibleSubsetIsCanonicalAndVerifierRejectsWitnessTamper`
7. `GlobalConformityOutcome.MixedComponentsCoverEveryIncidenceExactlyOnce`

These are behavioral gates, not existence checks. No fixture, assertion, selector, source, certificate bytes, expected value, tolerance, or package input may be mutated by TB-EXEC.

## 6. Postflight and evidence

After the final process, recompute the package, extracted-source, and execution-view censuses. Require each to be byte-identical to its preflight census. Record that no configure, compile, relink, benchmark, generated discovery, package repair, mode repair, or source/test/fixture/selector mutation occurred.

Upload separately:

- a result artifact containing immutable-input receipt, owner map, focused A/B ledgers, full 380-row ledger, per-process logs, timeout/selection summaries, and pre/post censuses;
- a persistent diagnostic log artifact under `if: always()` containing workflow/run/source/artifact identity, commands, outputs, exit context, and final state.

Evidence-upload failure invalidates the execution even if every test process returned green.

## 7. EXEC stop and handoff rules

`M4-CP2-TB1-EXEC` only executes and preserves evidence. It does not modify implementation/test/build logic, recompile, promote package116, close CP2, alter stable regression totals, or author a corrective patch.

- If preflight/selection/integrity fails, classify **orchestration failure**, preserve evidence, and route according to the project orchestration-correction edge.
- If semantic runtime is RED/SKIP or the focused duplicate run is nondeterministic, preserve all raw evidence and hand off to `M4-CP2-TB1-REV`; do not retry or patch first.
- If full green, still hand the primary evidence to `M4-CP2-TB1-REV` for the configured split EXEC/REV cadence. REV owns independent evidence re-derivation, regression adjudication, package promotion, and CP2 closure/next-plan decision.

No benchmark execution is required by this checkpoint despite the canonical Test + Benchmark turn name.
