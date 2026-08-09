# Future Chat Session Handoff

## Mandatory next turn

Run **T1 Independent Test-Oracle Foundation — Code + Build only** under:

`.agents/Directional/Test_Architecture_T1_Independent_Oracle_Foundation_Code_Build_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 remains open, draft, and unmerged;
- active gate: **G4 topology-distinct completion and singularities**;
- review policy: `never`;
- production runtime remains known-red on direct torus; T1 must not change
  production behavior.

T1 is test/build-only. It may add the independent oracle support/tests,
augment direct acceptance to invoke that oracle, and make only the packaging/
CMake changes named by the plan. It must compile/package only. Do **not** run
any generated project binary during Code + Build.

If T1 requires a production/API/fixture/validator change, stop. Do not expand
scope.

## Completed artifact-only Test + Benchmark

Runtime report:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Report.md`

Exact artifact authority:

| Evidence | Value |
|---|---|
| Implementation | `6af23d9aeca29e63aa13c4ae49f50d1748939c49` |
| Build/event commit | `32e97ea89cdc4bca629abde38f31eb943f3f11ad` |
| Result artifact | `9031804178` |
| Result SHA-256 | `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` |
| Log artifact | `9031804382` |
| Log SHA-256 | `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905` |
| Recursive manifest | **49/49**, `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2` |
| Compile closure | Release/static/Ninja **113/113**, `PRE_TEST`, `runtimeExecution=false` |

Preflight/postflight verified both immutable ZIPs, every manifest member, all
50 original package files, five ELF executables, two static libraries, 27
fixtures, all seven source/CMake blobs, the five-path patch, source archive,
compile database, toolchain/submodules, and workflow closure. No packaged
regular member changed during runtime.

## Runtime result

Discovery exactly once per executable:

- producer 166;
- completion 164;
- validation 71;
- API 8.

Required focused tests:

- four new multi-rail **4/4** individually;
- seven retained face-chart **7/7** individually;
- seven retained canonical **7/7** individually;
- total **18/18**.

Retained groups:

- transition quotient **29/36**;
- topology/isolation/hard rail **10/10**;
- polygonal/curved/mixed **12/12**;
- periodic/torus/cylinder **6/7**;
- remaining non-overlap Phase10 **38/39**;
- direct G0-G3 **4/4**.

Bounded suites:

- producer literal `-*BunnyRandom*:*Vase*`: **154/163**;
- completion/simplification **154/164**;
- validation **71/71**;
- API **8/8**;
- aggregate **387/406**.

The exact producer filter completed with a full 163-test summary in 30.63 s.
Do not classify earlier container-wrapper return behavior as product
nontermination.

## Direct production authority

Every direct run requested and executed `SurfaceCells`, used fallback policy
`Fail`, disabled source-grid recovery, and used no fallback, legacy execution,
or input-mesh substitution.

| Fixture | Result | Stable authority |
|---|---:|---|
| Plane | **3/3** | 81 V / 64 Q; `1/1/1`; structural `b243fb3f5f3a3bc4`; semantic `922456fe29a63ba1` |
| Multi-face seam | **3/3** | 81 V / 64 Q; `1/1/1`; structural `48661113839528d4`; semantic `99c8be7159d05c2f` |
| Close sheets | **3/3** | 242 V / 200 Q; `2/2/2`; structural `f01bcf687285ee72`; semantic `f40e1aa5f2eb3f92` |
| Cylinder | **3/3** | 320 V / 288 Q; `1/2/0`; structural `81b3763254afc476`; semantic `98da73e60a564998` |
| Torus | **0/3** | 192 completed Q; complete lineage; `4/8/4`; `1/0/0`; **241** `LocalSheetMismatch` issues |

Torus still fails at `completion/output-validation`. Entering artifact
`9030700527` had 165 mismatches; pre-regression artifact `9029584083` had 74.
The multi-rail correction therefore **failed representative acceptance and
worsened the unresolved symptom**. Prescribed sphere was correctly not run.

The historical exact-torus GoogleTest remains independently red upstream at
`InvalidHardRailPairing`; this is still the target-size-dependent scheduling
blocker `G4-B002`.

## Regression status

Permanent tracker:

`.agents/Directional/Regression_Root_Cause_Tracker.md`

- `PR8-R034 / G4-R007` is **active**.
- Do not create `G4-R008` for this artifact. The affected direct gate was never
  restored, so 165 → 241 is persistence/worsening of the open event, not a new
  recurrence.
- Historical PR-wide totals remain **34 events / 14 categories / 20
  recurrences**.
- `RP-09` local graph semantics pass the focused fixtures but do not close the
  representative product failure.
- This artifact supplies direct evidence for `RP-02 / TA-05 / AR-12`: focused
  stage-local tests can pass while representative product intent remains red.

Do not infer a new product root cause only from the increased mismatch count.
The next production migration is M1, but M1 is blocked until T1 immutable
acceptance establishes an independent test oracle.

## Mandatory regression-pattern review before T1

Read:

- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `.agents/Directional/PR_8_Regression_Audit_Inventory.md`;
- `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- `tests/TESTING_STRATEGY.md`.

Every turn must map `RP-01` through `RP-09`. T1 primarily touches `RP-02`, and
also test-side `RP-01`, `RP-05`, and `RP-07`. Fill the exact mandatory pattern
review table from the T1 plan before implementing.

For every new mandatory test family record:

1. intent;
2. proved precondition;
3. public production entry or exact stage boundary;
4. **independent** oracle;
5. rejected minimal counterexample or permitted metamorphic transformation;
6. exact executable/test/fixture/artifact identity.

Production `result.success`, `SourceAuthoritativeMeshValidator`, benchmark
quality decisions, raw IDs/order, counts, hashes, retention lifetime,
compilation, or no-crash are not independent product oracles.

## T1 success boundary

T1 must create a default-built independent product-oracle executable/support
that checks, without calling production decision procedures:

- nonempty pure-quad schema and valid indices;
- duplicate/repeated-corner/zero-area faces;
- independently reconstructed directed/undirected incidence;
- manifoldness and winding;
- components, boundary loops, and Euler characteristic;
- public vertex/face lineage shape and source-domain validity;
- backend/fallback/recovery/output-origin disposition;
- row/order-independent canonical topology/lineage facts.

Every check needs positive and deliberate corruption coverage. Existing direct
acceptance assertions are preserved and augmented, never weakened.

Code + Build acceptance is compile/package only. It must leave production and
fixtures byte-identical and emit one immutable artifact plus log artifact for
the following Test + Benchmark turn.

## Architecture and test-review authority

The independent architecture review and test-suite audit are complete:

- normative architecture: `.agents/Directional/DESIGN.md`;
- architecture report:
  `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`;
- test audit/redesign:
  `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- normative testing policy: `tests/TESTING_STRATEGY.md`.

`AR-01` through `AR-12` and `TA-01` through `TA-12` remain open until their
named evidence passes. Do not add nonzero holonomy, adaptivity, prescribed
singularity handling, or other feature growth to the legacy weak authority
model.

## Deferred blockers

- active representative torus `G4-R007`;
- shared hard-rail breakpoint scheduling `G4-B002`;
- nonzero periodic `Z4` rotation `G4-B003`;
- positive multi-isolation quotient witness `G4-B004`;
- historical seven transition-quotient cases;
- historical ten completion/simplification cases;
- strict-validator timing assertion;
- prescribed sphere, G5/G6, bunny/vase, fallback/recovery, and optimization.

After all branch-record and PR-body updates for a completed turn, the final
repository write must be exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
