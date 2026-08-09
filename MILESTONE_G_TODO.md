# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. Test-architecture migration remains at T1 until the corrected direct-oracle execution order passes immutable runtime acceptance.

## T1 direct-oracle execution-order Code + Build

**Completed for compile/package authority only. Runtime acceptance is next.**

Exact authority:

| Evidence | Value |
|---|---|
| Entering branch head | `4cee37f202a8781980b57677a110380f1596d527` |
| Implementation | `7c169ddf8167093c16755f2160e224994e50307c` |
| Successful build/event commit | `92231989472e31a81fe1394ddb3918a957f4bc57` |
| Workflow run/job | `31324710550 / 93273122696` |
| Result artifact | `9041289209` |
| Result SHA-256 | `c40dd0207d842dd4b7f52ccc6a7358f049d8d359bc476b0ef9090dff061e85ad` |
| Log artifact | `9041289317` |
| Log SHA-256 | `899b952308fc378a919794191df5374113fb1f29343bb22759c4408b0a82dd13` |
| Recursive manifest | **51/51**, `0221c7e2dfce157461170e9da2add52a6ccfbdf800d1490926d00206bb9f207d` |
| Compile closure | Release/static/Ninja **117/117**, eight targets, `PRE_TEST`, `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

Package verification confirms 52 regular files including the manifest, six ELF executables, two static libraries, all 27 fixtures, exact source/CMake authority, a one-file implementation patch, source archive, compile database, toolchain/submodules, and the unchanged exact 29-name oracle manifest with `contract-required;oracle-mutation` labels.

Implementation change is confined to `tests/SurfaceCellDesignAcceptanceTests.cpp`. The existing independent-oracle block now executes immediately after a returned `RemeshResult` and before the unchanged fatal `ASSERT_TRUE(result.success)`. Every existing product/backend/fallback/recovery/origin/schema/degree assertion is preserved with the same predicate and expected value. Production source/API, fixtures, oracle support/mutation tests, CMake, validators, benchmarks, tracing, arrangement, completion, optimizer, quotient, and pipeline behavior are unchanged.

The first workflow attempt `31324642747` failed only in a static verifier before install/configure/compile because blank-line relocation was interpreted too strictly. The implementation source did not change, no generated Directional binary ran, and the successful authoritative build is run `31324710550` only.

Code + Build report:
`.agents/Directional/Test_Architecture_T1_Direct_Oracle_Execution_Order_Code_Build_Report.md`.

## Entering T1 oracle runtime authority

Previous immutable artifact `9040549377` established:

- oracle discovery **29/29** exact names;
- oracle mutation/metamorphic contracts **29/29** individually;
- retained focused contracts **18/18**;
- bounded producer/completion/validation/API **154/163**, **154/164**, **71/71**, **8/8**;
- Plane, MultiFaceSeam, CloseSheets, Cylinder pass and reach the independent oracle;
- BunnyRandom returns known-red `NotProductionReady:completion` after 57.225 s but the entering fatal success assertion short-circuited before oracle execution;
- Vase did not return inside the bounded 60 s safety guard; no correctness or nontermination claim follows from that guard.

The oracle core is accepted. T1 direct integration is not accepted until the corrected artifact demonstrates that every **returned** direct result is independently inspected before any fatal production-success assertion.

## Authoritative next turn

**T1 Direct-Oracle Execution Order — immutable Test + Benchmark** using exactly:

- result artifact `9041289209`;
- log artifact `9041289317`;
- implementation `7c169ddf8167093c16755f2160e224994e50307c`;
- build/event commit `92231989472e31a81fe1394ddb3918a957f4bc57`.

Required acceptance:

1. verify both ZIP digests, **51/51** recursive manifest entries, exact patch/source/dependency closure, six executables, two libraries, 27 fixtures, unchanged 29-name oracle manifest, and `runtimeExecution=false`;
2. rebuild, relink, edit, substitute, or regenerate nothing;
3. discover `directional_surface_cell_oracle_tests` exactly once and match all 29 expected names;
4. run all 29 oracle contracts individually and require **29/29**;
5. preserve the retained 18 focused contracts and bounded producer/completion/validation/API authority;
6. run the six existing direct acceptance cases in fresh processes;
7. require Plane, MultiFaceSeam, CloseSheets, Cylinder to remain green with no independent-oracle issue;
8. require every returned failed direct product to emit independent-oracle evidence before the unchanged fatal product-success assertion failure;
9. keep Bunny/Vase explicit known-red product cases—never disable, count green, or convert to expected failure;
10. use a bounded process guard for a nonreturning case and treat timeout as runtime-safety evidence only;
11. accept T1 only if there is no oracle false positive/negative, missing package/discovery authority, assertion weakening, or returned direct result that bypasses the oracle.

If T1 passes, M1 authority-kernel Code + Build may begin. T2 remains responsible for the complete ten-case semantic fixture matrix and declared resource budgets.

## Current production runtime authority

Artifact `9031804178`, implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49` remains product authority:

- focused chart/canonical contracts **18/18**;
- bounded producer/completion/validation/API **154/163**, **154/164**, **71/71**, **8/8**;
- Plane, seam, close sheets, cylinder direct strict-valid **3/3**;
- torus **0/3** after 192 completed quads, complete lineage, complete `4/8/4`, `1/0/0`, then **241** `LocalSheetMismatch` issues;
- historical exact-torus remains `InvalidHardRailPairing`.

`PR8-R034 / G4-R007` remains **active**. The T1 statement-order correction is test-only, creates no new product runtime event, and does not alter historical totals of **34 events / 14 categories / 20 recurrences**.

## Architecture and test-suite authority

- normative architecture: `.agents/Directional/DESIGN.md`;
- architecture review: `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`;
- test audit/redesign: `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- normative testing policy: `tests/TESTING_STRATEGY.md`;
- permanent regression tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`.

## Deferred blockers

1. active representative torus `G4-R007`;
2. shared hard-rail breakpoint scheduling / exact-torus `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic `Z4` rotation (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. seven historical transition-quotient failures;
6. ten historical completion/simplification failures;
7. strict-validator timing assertion;
8. prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization quality.

PR #8 remains open, draft, and unmerged. The final repository write of every completed turn is one new top-level PR #8 conversation comment after all other branch-file and PR-body updates.
