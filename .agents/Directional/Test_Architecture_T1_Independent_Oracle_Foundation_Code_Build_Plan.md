# T1 Independent Test-Oracle Foundation — Code + Build Plan

**Status:** queued; do not execute before the current multi-rail artifact-only closeout  
**Turn type:** Code + Build only  
**Production behavior delta:** none  
**Depends on:** M0 artifact-only closeout and the accepted test-suite audit  
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8

## 1. Objective

Create the first independent, test-only product-oracle boundary and prove that
the oracle rejects deliberate semantic corruptions. Package and label that
authority by default. Do not redesign production algorithms, alter runtime
behavior, expand the direct fixture matrix, or set uncalibrated quality
thresholds in this slice.

This closes no product gate by compilation. It creates the authority required
to test later M1–M6 and T2–T6 slices without reusing the producer or production
validator as its own oracle.

## 2. Preconditions

Before this plan starts:

1. complete
   `.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md`
   against artifacts `9031804178 / 9031804382` unchanged;
2. update `G4-R007` from that runtime evidence;
3. preserve the resulting immutable runtime baseline;
4. review `RP-01` through `RP-09` and `TA-01` through `TA-12`;
5. record the mandatory repeated-pattern table and the six-part intent record
   for every new test family.

## 3. Allowed scope

Allowed implementation/test/build paths:

- new `tests/support/SurfaceCellProductOracle.h`;
- new `tests/support/SurfaceCellProductOracle.cpp`;
- new `tests/SurfaceCellProductOracleTests.cpp`;
- `tests/SurfaceCellDesignAcceptanceTests.cpp`;
- `cmake/DirectionalTests.cmake`;
- the compile/package manifest or artifact-inventory support strictly required
  to enumerate the new executable/tests.

Planning/status documents may be updated only for truthful Code + Build
closeout.

Prohibited:

- production source or public API changes;
- `SourceAuthoritativeMeshValidator`, completion, optimizer, tracing,
  arrangement, quotient, fixture, benchmark-quality, or production-pipeline
  behavior changes;
- new or changed fixture geometry/fields;
- enabling the historical target wholesale;
- numeric quality thresholds;
- workflow changes except a temporary bounded compile/package workflow already
  permitted by repository process;
- running any generated project binary.

If compilation exposes a required production/API change, stop and return to
Review. Do not expand this slice.

## 4. Test-only oracle boundary

The test oracle consumes immutable source input, public remesh result, and
declared fixture expectations. It may use Eigen and independently written
primitive geometry/topology calculations. It must not call:

- the producer's success/acceptance decision;
- `SourceAuthoritativeMeshValidator`;
- `evaluate_benchmark_quality`;
- producer helper functions that construct expected topology/lineage;
- source hashes, raw output ordering, predicted counts, or retained debug
  objects as semantic authority.

T1 implements these exact checks:

1. output schema: non-empty, valid indices, degree four;
2. face validity: no repeated corner, duplicate face, or zero-area quad under a
   scale-relative diagnostic tolerance;
3. independently reconstructed undirected/directed incidence;
4. manifold edge multiplicity and consistent orientation;
5. connected components, boundary-loop structure, and Euler characteristic;
6. complete per-vertex/per-face lineage shape and valid source index domains;
7. strict direct backend/fallback/recovery/output-origin disposition;
8. canonical, row-order-independent topology/lineage record suitable for later
   semantic digest comparison.

T1 must distinguish hard exact invariants from tolerance-derived geometry
diagnostics. A tolerance result cannot become topology identity.

## 5. Oracle-mutation tests

Every oracle check needs a positive control and at least one deliberate
single-fact corruption. Minimum mutations:

- out-of-range index;
- non-quad degree;
- repeated corner/zero-area face;
- duplicate face under cyclic/reversed representation;
- edge with more than two incident faces;
- inconsistent adjacent winding;
- broken boundary incidence;
- changed component/Euler structure;
- missing or out-of-domain vertex lineage;
- missing/duplicate face lineage;
- fallback/recovery/backend/output-origin corruption;
- input/output row permutation that must preserve canonical semantic facts.

Each test records:

| Field | Required content |
|---|---|
| Intent | exact oracle contract |
| Precondition | proof that the unmutated fixture satisfies the contract |
| Stimulus | one named mutation |
| Independent oracle | exact rejected predicate and diagnostic |
| Counterexample | serialized minimal mutation |
| Evidence identity | executable and exact discovered test name |

The positive output must not be synthesized by first accepting production
output. Use minimal hand-authored source/result records whose intended
topology and lineage are independently obvious.

## 6. Integration with direct acceptance

Refactor the six existing direct acceptance cases to invoke the independent T1
oracle after the public production call. Preserve every current backend,
fallback/recovery, origin, nonempty, and degree-four assertion. Do not weaken,
delete, or convert an assertion to a diagnostic.

The production `result.success` assertion remains, but it is no longer the
sole semantic authority. A failing independent oracle remains a test failure
even when production validation says success.

T2—not T1—adds torus, thin bent tube, prescribed sphere, and mechanical
feature to the direct matrix and adds the semantic fixture manifest.

## 7. Packaging

Prefer one new default-built executable
`directional_surface_cell_oracle_tests` with labels
`contract-required;oracle-mutation`. The artifact manifest must enumerate:

- executable path and checksum;
- exact discovered test names;
- labels;
- source file/blob identities;
- `runtimeExecution=false` for Code + Build;
- compile/link commands and dependency closure.

The producer acceptance tests remain default-built and discovered. No
mandatory oracle test may depend on
`DIRECTIONAL_BUILD_HISTORICAL_TESTS`, optional guidance, or legacy integration
options.

## 8. Code + Build acceptance

The turn succeeds only when:

1. the diff is confined to the allowed scope;
2. production and fixtures are byte-identical;
3. all configured targets compile and link in the approved Release/static/Ninja
   environment;
4. the new oracle executable and exact tests are present in the immutable
   package manifest;
5. static inspection proves no calls to production validator/benchmark
   decision procedures;
6. every mutation family has one positive and one negative test definition;
7. the direct acceptance assertions are preserved and augmented;
8. no project executable, test discovery, test, benchmark, fuzzer, CLI/help, or
   generated binary ran;
9. one immutable artifact and log artifact are handed to the following Test +
   Benchmark turn.

Compilation is not test acceptance.

## 9. Required following Test + Benchmark

The following immutable turn must:

1. verify package/source/dependency closure and `runtimeExecution=false`;
2. discover every executable once and verify exact oracle test names/labels;
3. run every oracle positive/mutation test individually;
4. prove each mutation fails for the intended diagnostic and each permitted row
   permutation passes;
5. run the six current direct acceptance cases with the new independent oracle;
6. preserve the entering required-green focused/bounded suites without hiding
   known failures;
7. record topology/lineage oracle output separately from production
   `result.success`;
8. preserve exact logs and artifacts, with no source/test/build edit or rebuild.

Any oracle false negative, false positive, production-validator coupling,
missing discovery entry, assertion weakening, or artifact substitution rejects
T1 and blocks M1.

## 10. Handoff after T1

If T1 immutable acceptance passes, M1 authority-kernel Code + Build may begin
and must use the accepted intent/precondition/oracle/counterexample/evidence
format. T2 complete direct corpus/semantic manifest remains required before M2
behavior migration.

