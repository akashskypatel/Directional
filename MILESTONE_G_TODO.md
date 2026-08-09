# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** →
G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure /
holonomy **accepted** → **G4 topology-distinct completion and singularities
active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7
hardening.

Production remains known-red on direct torus. The test-architecture migration
is currently at T1.

## T1 independent test-oracle checkpoint

Code + Build implementation `6d1922dd57db76dcc4c19056fdd3573a713dde61`
compiled/package-verified artifact `9040549377` with `runtimeExecution=false`.
The following immutable Test + Benchmark is now complete.

Accepted T1 oracle-core evidence:

- both artifact ZIP digests exact;
- recursive package manifest **51/51**;
- six ELF executables, two static libraries, 27 fixtures, exact source/package
  authority;
- `directional_surface_cell_oracle_tests` discovered exactly once with the
  exact **29/29** immutable names;
- all **29/29** positive/mutation/metamorphic oracle tests pass individually;
- retained multi-rail/face-chart/canonical contracts **18/18**;
- bounded producer/completion/validation/API remain
  **154/163**, **154/164**, **71/71**, **8/8**.

T1 is not closed because direct integration is post-success-only:

```text
result = production_call(...)
ASSERT_TRUE(result.success)
...
independentOracle = inspect(result)
```

Plane, seam, close sheets, and cylinder return successful products and pass the
independent oracle. BunnyRandom returns the known-red
`NotProductionReady:completion` failure after 57.225 s and stops before oracle
execution. Vase does not return within the bounded 60 s safety guard. These
known-red product cases are not converted to expected failure or counted green.

Authoritative report:
`.agents/Directional/T1_Independent_Test_Oracle_Foundation_Artifact_Only_Test_Benchmark_Report.md`.

## Authoritative next turn

**T1 Direct-Oracle Execution Order — Code + Build only** under:

`.agents/Directional/Test_Architecture_T1_Direct_Oracle_Execution_Order_Code_Build_Plan.md`

Allowed implementation change: `tests/SurfaceCellDesignAcceptanceTests.cpp`
only. Evaluate the independent oracle immediately after every returned
`RemeshResult` and before the existing fatal production-success assertion.
Preserve every existing product assertion unchanged. Production, public API,
fixtures, oracle support/mutation logic, CMake, validators, benchmarks,
tracing, arrangement, completion, optimizer, and pipeline behavior must remain
byte-identical.

Compile/package only. No generated project binary may run in Code + Build. M1
remains blocked until the following immutable artifact accepts this correction.

## Current production runtime authority

Artifact `9031804178`, implementation
`6af23d9aeca29e63aa13c4ae49f50d1748939c49` remains product authority:

- focused chart/canonical contracts **18/18**;
- bounded producer/completion/validation/API
  **154/163**, **154/164**, **71/71**, **8/8**;
- plane, seam, close sheets, cylinder direct strict-valid **3/3**;
- torus **0/3** after 192 completed quads, complete lineage, complete `4/8/4`,
  `1/0/0`, then **241** `LocalSheetMismatch` issues;
- historical exact-torus remains `InvalidHardRailPairing`.

`PR8-R034 / G4-R007` remains **active**. T1 is test-only and adds no product
runtime regression. PR-wide totals remain **34 events / 14 categories / 20
recurrences**.

## Architecture and test-suite authority

- normative architecture: `.agents/Directional/DESIGN.md`;
- architecture review:
  `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`;
- test audit/redesign:
  `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- normative testing policy: `tests/TESTING_STRATEGY.md`;
- permanent regression tracker:
  `.agents/Directional/Regression_Root_Cause_Tracker.md`.

T1 runtime now strongly supports the independent-oracle, mutation, packaging,
typed-domain, and canonical-metamorphism design. Full product authority remains
staged across T2–T6 and M1–M6.

## Deferred blockers

1. active representative torus `G4-R007`;
2. shared hard-rail breakpoint scheduling / exact-torus
   `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic `Z4` rotation (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. seven historical transition-quotient failures;
6. ten historical completion/simplification failures;
7. strict-validator timing;
8. prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization.

PR #8 remains open, draft, and unmerged. The final repository write of every
completed turn is one new top-level PR #8 conversation comment after all other
branch and PR-body updates.
