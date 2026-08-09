# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. The test-architecture prerequisite T1 is now accepted, so the architecture migration may advance to M1.

## T1 independent oracle/package foundation — accepted

Corrected immutable authority:

| Evidence | Value |
|---|---|
| Implementation | `7c169ddf8167093c16755f2160e224994e50307c` |
| Build/event commit | `92231989472e31a81fe1394ddb3918a957f4bc57` |
| Workflow run/job | `31324710550 / 93273122696` |
| Result artifact | `9041289209` |
| Result SHA-256 | `c40dd0207d842dd4b7f52ccc6a7358f049d8d359bc476b0ef9090dff061e85ad` |
| Log artifact | `9041289317` |
| Log SHA-256 | `899b952308fc378a919794191df5374113fb1f29343bb22759c4408b0a82dd13` |
| Recursive manifest | **51/51**, `0221c7e2dfce157461170e9da2add52a6ccfbdf800d1490926d00206bb9f207d` |
| Compile closure | Release/static/Ninja **117/117**, eight targets, `PRE_TEST`, `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

Runtime acceptance:

- oracle discovery exactly once: **29/29**, exact manifest order;
- oracle positive/mutation/metamorphic contracts: **29/29** individually;
- retained multi-rail/face-chart/canonical contracts: **18/18**;
- bounded producer/completion/validation/API: **154/163**, **154/164**, **71/71**, **8/8**;
- bounded aggregate: **387/406**, unchanged.

Direct T1 cases:

| Case | Product result | Independent oracle |
|---|---|---|
| Plane | pass, 1.025 s | reached; no issue |
| MultiFaceSeam | pass, 1.563 s | reached; no issue |
| CloseSheets | pass, 12.759 s | reached; no issue |
| Cylinder | pass, 6.711 s | reached; no issue |
| BunnyRandom | known-red `NotProductionReady:completion`, 54.580 s | reached **before** fatal product assertion and independently rejected returned invalid product |
| Vase | bounded timeout at 60.00 s | no returned result; no oracle result synthesized |

Bunny now proves the required T1 execution order. The independent oracle reports `EmptyOutput`, `NonQuadOutput`, topology mismatches, output-origin mismatch, and the terminal completion failure before the unchanged fatal `result.success` assertion. Bunny remains red. Vase timeout is safety evidence only.

Authoritative report:
`.agents/Directional/T1_Direct_Oracle_Execution_Order_Artifact_Only_Test_Benchmark_Report.md`.

## Regression disposition

- `RP-02 / TA-05` direct-integration defect: **test-authority resolved**.
- T1 creates/resolves no production runtime regression event.
- PR-wide historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current production authority remains:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then **241** `LocalSheetMismatch` issues;
- historical exact-torus remains `InvalidHardRailPairing`.

## Authoritative next turn

**M1a Authority Kernel Core — Code + Build only** under:

`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Code_Build_Plan.md`

M1a is the first bounded strangler slice of M1. It introduces:

1. strong non-interconvertible semantic IDs;
2. named checked legacy conversions with typed domain errors;
3. tagged `SourceSupport`;
4. one `FieldChartId`;
5. exact `QuarterTurn`, integer lattice translation, and `GridAutomorphism` algebra;
6. `TransitionStep` and `CanonicalRoute` with explicit orientation;
7. one-way checked compatibility adapters;
8. default-built semantic/counterexample tests.

No intended production behavior change is authorized. Existing producer, validator, tracing, arrangement, completion, optimizer, quotient, and pipeline consumers must remain on the legacy behavior path during M1a. Code + Build compiles/packages only and executes no generated project binary.

The following turn must be immutable Test + Benchmark. Only after M1a runtime acceptance may M1b migrate the first real production consumer to the new authority kernel.

## Architecture and test authority

- normative architecture: `.agents/Directional/DESIGN.md`;
- migration roadmap: `.agents/Directional/REORIENTATION_PLAN.md`;
- architecture review: `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`;
- test audit/redesign: `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- normative testing policy: `tests/TESTING_STRATEGY.md`;
- permanent regression tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`.

T1 closes the direct-oracle execution-order boundary. `TA-01` still has later geometry/field/feature/quality work; T2–T6 remain staged. M1a primarily addresses `AR-02`, `AR-03`, `AR-05`, and the domain/transport portions of `AR-04`/`AR-09` without producer behavior migration.

## Deferred blockers

1. active representative torus `G4-R007`;
2. shared hard-rail breakpoint scheduling / exact-torus `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic `Z4` production capability (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. seven historical transition-quotient failures;
6. ten historical completion/simplification failures;
7. strict-validator timing assertion;
8. prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization quality;
9. M1b–M6 and T2–T6.

PR #8 remains open, draft, and unmerged. The final repository write of every completed turn is one new top-level PR #8 conversation comment after all other branch-file and PR-body updates.
