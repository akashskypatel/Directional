# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** →
G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure /
holonomy **accepted** → **G4 topology-distinct completion and singularities
active** → G5 adaptivity/features → G6 bunny/vase production success → G7
hardening.

The latest multi-rail chart-reachability correction is **not accepted as a G4
product fix**. Its local contracts pass, but representative direct torus
remains invalid and worsened at the same final-validation boundary.

T1 independent test-oracle foundation **Code + Build is accepted for
compile/package only** with no production behavior delta. Its following
immutable Test + Benchmark acceptance remains mandatory before M1.

## T1 immutable compile authority

Implementation `6d1922dd57db76dcc4c19056fdd3573a713dde61`, workflow run/job
`31322039791 / 93266424347`:

- result/log artifacts `9040549377 / 9040549498`;
- result/log SHA-256
  `06530ff55e63204a7685077862d935cfe24588237391765596a790759eea2097` /
  `6b756784b98dc8532d905ef3869067ddf178e18501afd2fc29139c53a82c9a86`;
- recursive manifest **51/51**, digest
  `9d3660f8764e57b59c890f0c8afb07e4dcf740e970328e1359acd1c48f61b260`;
- Release/static/Ninja **117/117**, eight approved targets, GoogleTest
  `PRE_TEST`, exact 29-name oracle manifest, `runtimeExecution=false`;
- verified package inventory: 52 regular files including the manifest, six ELF
  executables, two static libraries, 27 fixtures, exact source/CMake blobs,
  seven-path patch, source archive, compile database, and toolchain/submodules;
- temporary workflow/trigger removed at
  `8d153ab4720b129a512cf755f3d77e5ab7738e13`;
- retention through **2026-08-23 UTC**.

## Current immutable runtime authority

Artifact `9031804178`, implementation
`6af23d9aeca29e63aa13c4ae49f50d1748939c49`:

- compile/log artifacts `9031804178 / 9031804382`;
- result/log SHA-256
  `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` /
  `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905`;
- recursive manifest **49/49**, digest
  `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2`;
- Release/static/Ninja **113/113**, GoogleTest `PRE_TEST`,
  `runtimeExecution=false`;
- preflight/postflight verified both ZIPs, every manifest member, 50 original
  package files, five ELF executables, two static libraries, 27 fixtures, seven
  source/CMake blobs, patch/source-archive/compile-database authority,
  toolchain/submodules, and no packaged regular-file mutation.

Runtime report:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Report.md`

## Multi-rail artifact closeout

Discovery, exactly once per executable:

- producer: **166** tests;
- completion: **164**;
- validation: **71**;
- API: **8**.

Required focused contracts all pass individually:

- four new multi-rail: **4/4**;
- seven retained face-chart: **7/7**;
- seven retained canonical: **7/7**;
- required focused aggregate: **18/18**.

Retained groups:

- transition quotient **29/36**;
- topology/isolation/hard rail **10/10**;
- polygonal/curved/mixed **12/12**;
- periodic/torus/cylinder **6/7**;
- remaining non-overlap Phase10 **38/39**;
- direct G0-G3 GoogleTests **4/4**.

Bounded suites:

- producer with literal `-*BunnyRandom*:*Vase*`: **154/163**;
- completion/simplification: **154/164**;
- validation: **71/71**;
- API: **8/8**;
- aggregate: **387/406**.

The exact producer filter completed all 163 selected tests with a full summary
in 30.63 seconds. An earlier container-wrapper return is not product
nontermination evidence.

## Direct production matrix

All direct runs requested/executed `SurfaceCells`, used fallback policy `Fail`,
disabled source-grid recovery, and used no legacy fallback or input-mesh
substitution.

| Fixture | Three-process result | Stable authority |
|---|---:|---|
| Plane | **3/3** | 81 V / 64 Q; topology `1/1/1`; structural `b243fb3f5f3a3bc4`; semantic `922456fe29a63ba1` |
| Multi-face seam | **3/3** | 81 V / 64 Q; `1/1/1`; structural `48661113839528d4`; semantic `99c8be7159d05c2f` |
| Close sheets | **3/3** | 242 V / 200 Q; `2/2/2`; structural `f01bcf687285ee72`; semantic `f40e1aa5f2eb3f92` |
| Cylinder | **3/3** | 320 V / 288 Q; `1/2/0`; structural `81b3763254afc476`; semantic `98da73e60a564998` |
| Torus | **0/3** | 192 completed quads; complete lineage; complete `4/8/4`; `1/0/0`; **241** `LocalSheetMismatch` issues |

Direct torus still reaches completion and fails at
`completion/output-validation / LocalSheetMismatch`. Entering runtime artifact
`9030700527` had 165 issues; pre-regression artifact `9029584083` had 74.
Reduced mismatch count was not acceptance, and 241 is a failed remediation.
Prescribed sphere was correctly not run because its independent exact-torus
scheduling prerequisite is still red.

## Regression disposition

`PR8-R034 / G4-R007` is **active**.

Artifact `9031804178` does **not** create a new event or recurrence. The direct
torus gate was never restored, so 165 → 241 is persistence/worsening of the
same unresolved regression. PR-wide totals remain:

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**.

Permanent tracker:

`.agents/Directional/Regression_Root_Cause_Tracker.md`

The artifact also gives direct evidence for `RP-02 / TA-05 / AR-12`: all
focused chart/reachability contracts can pass while representative product
intent remains red. The focused tests remain valid stage-local contracts; they
cannot be promoted to complete product proof.

## Independent architecture and test-suite review

The required reviews are complete:

- normative architecture: `.agents/Directional/DESIGN.md`;
- architecture report:
  `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`;
- test audit/redesign:
  `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- normative testing policy: `tests/TESTING_STRATEGY.md`.

`AR-01` through `AR-12` and `TA-01` through `TA-12` remain open until their
named migration evidence passes. No nonzero holonomy, adaptivity,
prescribed-singularity behavior, or other feature growth may be added to the
legacy weak authority representation.

## Authoritative next turn

**T1 Independent Test-Oracle Foundation — immutable Test + Benchmark** using:

- result artifact `9040549377` exactly;
- log artifact `9040549498` exactly;
- implementation `6d1922dd57db76dcc4c19056fdd3573a713dde61`;
- the Code + Build report
  `.agents/Directional/Test_Architecture_T1_Independent_Oracle_Foundation_Code_Build_Report.md`.

The following turn must:

- verify both immutable ZIP digests, **51/51** manifest entries, source/package
  authority, and `runtimeExecution=false` before executing anything;
- perform GoogleTest discovery exactly once for
  `directional_surface_cell_oracle_tests` and match the exact 29-name manifest;
- run each of the 29 positive/mutation/metamorphic contracts individually and
  require its named diagnostic or preserved semantic record;
- run the six existing direct acceptance cases with all prior assertions plus
  the independent oracle invocation intact;
- make no rebuild, relink, source/test/fixture/CMake/workflow edit, production
  substitution, or benchmark-acceptance change.

Compilation and packaging are not mutation-adequacy acceptance. If the
immutable tests expose a failure, report it without repairing source in that
turn. M1 production authority-kernel migration begins only after T1 passes this
immutable Test + Benchmark acceptance.

Preserve the completed `RP-01` through `RP-09` and `TA-01` through `TA-12`
mapping. T1 primarily touches `RP-02` and test-side `RP-01`, `RP-05`, and
`RP-07`; every runtime result must retain the recorded intent, proved
precondition, production entry/stage, independent oracle, rejected
counterexample, and exact executable/test/artifact identity.

## Deferred blockers

1. active representative torus `G4-R007`;
2. shared hard-rail breakpoint scheduling / historical exact-torus
   `InvalidHardRailPairing` (`G4-B002`), which still gates sphere;
3. nonzero periodic `Z4` rotation (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. seven historical transition-quotient failures;
6. ten historical completion/simplification failures;
7. strict-validator timing assertion;
8. prescribed sphere, G5/G6, bunny/vase, fallback/recovery, and optimization
   quality.

PR #8 remains open, draft, and unmerged. Every completed turn ends with one new
top-level PR #8 conversation comment as the final repository write after all
branch-file and PR-body updates.
