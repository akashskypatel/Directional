# T1 Independent Test-Oracle Foundation — Immutable Test + Benchmark Report

**Status:** completed; oracle core accepted, direct integration incomplete  
**Turn type:** Test + Benchmark only  
**Phase:** T1 independent test-oracle foundation  
**Date:** 2026-08-09 UTC  
**Review policy:** `never`

## Outcome

The immutable T1 package is internally valid. The new default-built oracle
executable is discovered exactly once with the exact 29-name manifest, and all
29 hand-authored positive, deliberate-mutation, and metamorphic contracts pass
individually. The retained 18 chart/canonical focused contracts remain 18/18.
The bounded producer/completion/validation/API suites remain at the entering
154/163, 154/164, 71/71, and 8/8 results. Production sources and fixtures are
byte-identical to the entering authority.

The T1 oracle foundation is **not yet accepted as complete integration
territory**. Four required-green direct cases (plane, multi-face seam, close
sheets, cylinder) pass with the independent oracle. The existing BunnyRandom
case returns the known-red production failure
`NotProductionReady:completion` after 57.225 s, before the independent oracle
is reached. The existing Vase case does not return within the bounded 60 s
process guard, so no product result or oracle result is available.

Exact source inspection explains the Bunny short-circuit: in
`tests/SurfaceCellDesignAcceptanceTests.cpp`, `ASSERT_TRUE(result.success)` is
executed before `inspect_surface_cell_product(...)`. A known-red result
therefore terminates the test body before the newly added independent oracle.
This is a T1 test-integration authority defect mapped to `RP-02 / TA-05`; it is
not permission to weaken the product assertion and is not a new PR-wide
regression event because T1 immutable acceptance had never been established.

M1 remains blocked. The next turn is a narrow test-only Code + Build that moves
the independent oracle evaluation before the existing fatal production-success
assertion, preserving every product assertion and all known-red product status.

## Immutable artifact authority

| Authority | Value |
|---|---|
| Implementation | `6d1922dd57db76dcc4c19056fdd3573a713dde61` |
| Workflow run/job | `31322039791 / 93266424347` |
| Result artifact | `9040549377` |
| Result outer SHA-256 | `06530ff55e63204a7685077862d935cfe24588237391765596a790759eea2097` |
| Log artifact | `9040549498` |
| Log outer SHA-256 | `6b756784b98dc8532d905ef3869067ddf178e18501afd2fc29139c53a82c9a86` |
| Recursive manifest | **51/51**, `9d3660f8764e57b59c890f0c8afb07e4dcf740e970328e1359acd1c48f61b260` |
| Patch | `1447331ecf09660e3acf1fd757729913d62c1024b7771bbc0e9268f962d089a8` |
| Source archive | `9f3e4b845d5d44ee08a4b976ced302706129b958e3b3a5d3dcf84741a4386315` |
| Compile database | `1fa77cb933c96829d3c41fee73e072da6460c7eb9301e24e7865d2c902616885` |
| Compile closure | Release/static/Ninja **117/117**, eight targets, `PRE_TEST`, `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

Preflight verified both ZIP digests, safe paths, every **51/51** manifest entry,
52 regular package files including the manifest, six ELF executables, two
static libraries, all 27 fixtures, the exact source/CMake blobs, the seven-path
patch, source archive, compile database, toolchain/submodules, exact 29-name
oracle manifest, and the no-runtime Code + Build boundary.

Static inspection additionally confirms the test oracle does not call
`SourceAuthoritativeMeshValidator` or `evaluate_benchmark_quality`, does not
consult `result.success`, and does not use production structural/semantic
hashes as its decision procedure. The one `result.success` occurrence in the
oracle implementation is a comment explicitly stating it is not consulted.

## Mandatory repeated-pattern review

| Pattern | Touched? | Exact affected boundary | Evidence / invariant | Counterfactual or representative result |
|---|---|---|---|---|
| `RP-01` | yes, test side | typed source/output index domains and lineage-domain checks | distinct oracle domain types remain packaged; no production numeric domain change | out-of-range output/source and lineage-domain mutations pass |
| `RP-02` | **yes, primary** | `directional_surface_cell_oracle_tests`; `SurfaceCellDesignAcceptance` | 29 independent contracts are packaged/discovered/run, but direct integration is post-`ASSERT_TRUE(result.success)` and is skipped on returned failures | 29/29 oracle contracts pass; Bunny proves the direct integration short-circuit |
| `RP-03` | observation only | strict disposition issue codes | backend/fallback/recovery/origin/terminal observations remain separate | all five disposition corruption families pass |
| `RP-04` | no algorithmic change | oracle incidence/canonicalization runtime | no recursion/backtracking; individual oracle contracts complete in milliseconds | bounded suites retain entering behavior |
| `RP-05` | yes | canonical product record | row IDs/order are not semantic authority | row/cycle/reversal metamorphic contract passes |
| `RP-06` | no production storage | test-only temporary incidence | no production object changed or shared authority copied per consumer | production byte identity + bounded runtime |
| `RP-07` | yes | cyclic/reversed quad and boundary handling | cyclic/reversed duplicate identity and wraparound are explicit | duplicate-face, broken-boundary, canonical reversal contracts pass |
| `RP-08` | observation only | public direct disposition | no producer state or fallback policy changed | backend/fallback/recovery/origin/terminal mutations pass |
| `RP-09` | no product resolver | public topology/lineage oracle only | T1 does not reconstruct chart-relation authority | retained chart/canonical focused tests 18/18; torus remains separate known-red production authority |

No new regression event or recurrence is created by this turn. The direct
Bunny/Vase status predates T1 and remains deferred G6 product work. The T1
integration defect occurs inside an unaccepted new test architecture and is
tracked as incomplete `RP-02 / TA-05` work rather than a new historical
regression ID.

## Discovery and oracle mutation adequacy

`directional_surface_cell_oracle_tests --gtest_list_tests` was executed exactly
once. Discovery returned exactly **29/29** names in the same order as
`metadata/oracle-test-names.txt`; there were no missing or extra names.

Every named test was then run in its own fresh process with `LC_ALL=C` and
`TZ=UTC`:

- positive minimal disk: **1/1**;
- schema/domain/finiteness/degree mutations: **7/7**;
- face validity mutations: **3/3**;
- incidence/boundary mutations: **3/3**;
- topology mutation: **1/1**;
- provenance/lineage mutations: **8/8**;
- disposition mutations: **5/5**;
- row/cycle/reversal metamorphism: **1/1**;
- total: **29/29**, all exit zero.

Each mutation test source asserts a specific `OracleIssueCode` through the
independent `ProductOracleReport`; a passing GoogleTest therefore establishes
that the intended corruption was rejected rather than merely producing any
failure.

## Retained focused and bounded suites

The 18 entering focused contracts were rerun individually and remain **18/18**:

- multi-rail **4/4**;
- face-chart **7/7**;
- canonical transition/periodic/retention **7/7**.

Bounded suites remain stable:

| Suite | Result | Notes |
|---|---:|---|
| Producer, literal `-*BunnyRandom*:*Vase*` | **154/163** | 9 historical failures; full 163-test summary in 36.993 s |
| Completion/simplification | **154/164** | same historical ten failures |
| Validation | **71/71** | green |
| Compiled API | **8/8** | green |
| Aggregate | **387/406** | unchanged entering denominator/result |

The producer failures remain the seven historical transition-quotient cases,
strict-validator timing, and exact committed torus `InvalidHardRailPairing`.
No previously green bounded test moved.

## Six existing direct acceptance cases

Each case was launched as its exact parameterized GoogleTest in a fresh process.
The first four return successful products and therefore execute the newly added
independent oracle.

| Case | Result | Runtime evidence | Oracle reachability |
|---|---:|---|---|
| Plane | pass | 1.188 s | reached; test passes |
| MultiFaceSeam | pass | 1.570 s | reached; test passes |
| CloseSheets | pass | 12.547 s | reached; test passes |
| Cylinder | pass | 6.632 s | reached; test passes |
| BunnyRandom | **fail** | 57.225 s; `NotProductionReady:completion`; 170831 trace segments, 0 arrangement cells, 0 completed quads | **not reached** because fatal `result.success` assertion precedes oracle |
| Vase | **bounded timeout** | no result after 60 s guard; test was still inside production call | not reachable because no `RemeshResult` returned |

Bunny and Vase are explicitly known-red/deferred product cases under the
normative testing strategy. They are not counted as required-green T1 proof and
are not reclassified as T1 production regressions. The 60 s Vase guard is only
a bounded execution safety limit for this turn; it is not correctness evidence
and does not establish nontermination or a new product root cause.

## Failure classification

### T1 direct-oracle integration ordering

**Classification:** test-authority implementation defect; T1 incomplete.  
**Pattern:** `RP-02`, contributing to `TA-05`.  
**Exact source:** `tests/SurfaceCellDesignAcceptanceTests.cpp` at implementation
`6d1922dd...` executes `ASSERT_TRUE(result.success)` before
`inspect_surface_cell_product(...)`.

The test family therefore verifies the independent oracle only after the
production success decision has already passed. This is sufficient for the four
currently green cases but not for any returned known-red result. It violates the
T1 evidence requirement to keep production disposition and independent oracle
observations separate.

The correction must not remove, weaken, reorder away, or turn the product
success assertion into an expected failure. It must evaluate and report the
independent oracle for every returned result **before** the existing fatal
success assertion, then preserve all existing assertions unchanged.

### BunnyRandom

**Classification:** pre-existing known-red production failure, not a T1
regression. Production code and fixture bytes are unchanged in T1. The failure
is recorded only as representative direct evidence and remains deferred to G6.

### Vase

**Classification:** bounded runtime did not produce a result; product status is
inconclusive in this turn and remains known-red/deferred. The timeout does not
establish nontermination and is not a T1 regression.

## Postflight

After runtime:

- both original outer ZIP digests remain exact;
- all **51/51** recursive manifest entries still verify;
- all 52 original regular package files remain byte-identical;
- no regular file outside the manifest was created;
- the only package-tree addition is the documented runtime locator symlink
  `bin/test-data -> ../test-data`;
- no configure, compile, rebuild, relink, source/test/fixture/CMake/workflow
  edit, or artifact substitution occurred.

## Decision

The **oracle core is accepted**: package/discovery authority, independent
mutation decisions, typed-domain mutation coverage, canonical metamorphism,
and the four required-green direct integrations all behave as designed.

The **T1 immutable acceptance as a whole remains incomplete** because the
direct acceptance family short-circuits the independent oracle on a returned
production failure. M1 remains blocked until that integration defect is
corrected and revalidated from a new immutable artifact.

The next turn is **Code + Build only** under:

`.agents/Directional/Test_Architecture_T1_Direct_Oracle_Execution_Order_Code_Build_Plan.md`

No production behavior change is authorized.
