# T1 Independent Test-Oracle Foundation — Code + Build Plan

**Status:** authoritative next turn; multi-rail artifact-only closeout completed  
**Turn type:** Code + Build only  
**Production behavior delta:** none  
**Depends on:** completed M0 artifact-only closeout and the accepted test-suite audit  
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

The prerequisite artifact-only turn is complete against artifacts
`9031804178 / 9031804382` without rebuild or source/test/build edits.

Runtime closeout:

- four new multi-rail, seven retained face-chart, and seven retained canonical
  contracts passed individually: **18/18**;
- bounded producer/completion/validation/API are **154/163**, **154/164**,
  **71/71**, and **8/8**;
- plane, seam, close sheets, and cylinder remain direct strict-valid **3/3**;
- direct torus remains **0/3** after 192 completed quads, complete lineage,
  complete `4/8/4` authority consumption, and `1/0/0` topology;
- torus final validation now reports **241** `LocalSheetMismatch` issues,
  versus 165 under entering artifact `9030700527` and 74 under pre-regression
  artifact `9029584083`;
- `G4-R007` is therefore **active**, not resolved. This is persistence and
  worsening of the unresolved event, not a new recurrence;
- prescribed sphere remains gated by the independent historical exact-torus
  `InvalidHardRailPairing` scheduling blocker.

The runtime report is:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Report.md`

The closeout supplies direct evidence for `RP-02 / TA-05 / AR-12`: focused
stage-local tests can pass while representative production remains red. T1 is
therefore mandatory before M1; it is not permission to weaken the existing
focused contracts.

Before implementation:

1. review `RP-01` through `RP-09` and `TA-01` through `TA-12`;
2. preserve `G4-R007` as the entering known-red product baseline;
3. record the mandatory repeated-pattern table below for the actual diff;
4. record the six-part intent record for every new mandatory test family;
5. verify the branch still contains no user/runtime changes after the artifact
   closeout other than documentation/status records.

## 3. Mandatory repeated-pattern review for T1

T1 is test-only, but it directly changes test authority. The implementation
record must fill exact source/test symbols and final immutable evidence for
every touched row.

| Pattern | Expected T1 touch | Required invariant before code is accepted | Required following evidence |
|---|---|---|---|
| `RP-01` authority-domain conflation | yes, test-side representations | Oracle types must distinguish topology, source indices, lineage, and semantic identity; no bare numeric field may stand for multiple domains. | deliberate domain-corruption mutations rejected independently |
| `RP-02` proxy/incomplete test authority | **primary** | Oracle uses independently written observable input/output decisions and is default-built/discovered; production validator/result success is not its oracle. | every positive/mutation test individually discovered/run in immutable artifact |
| `RP-03` policy/state conflation | possible | Oracle result and production disposition remain separate values; no shared flag changes runtime policy. | backend/fallback/origin mutation cases plus byte-identical production sources |
| `RP-04` cumulative work | no algorithmic growth | Oracle is linear/bounded over provided input/output incidence; no recursive search. | static inspection and bounded test runtime |
| `RP-05` representation-dependent identity | yes | Canonical topology/lineage facts are invariant to vertex/face row order and cyclic/reversed quad representation. | row/cycle/reversal metamorphic tests |
| `RP-06` duplicated shared authority | no production storage | Test oracle does not copy unbounded global membership per consumer. | static inspection; no production change |
| `RP-07` cyclic topology linearization | yes | Boundary loops and quad faces are canonicalized cyclically; wraparound is first-class. | cyclic/reversed face and boundary mutation coverage |
| `RP-08` producer disposition conflation | no production change | Oracle records production disposition as an observed contract without reducing typed states. | fallback/recovery/backend/output-origin mutations |
| `RP-09` global authority consumed locally | no new product resolver | T1 must not reconstruct or bless chart-relation authority as product truth; lineage checks stay at public observable shape/domain level. | no calls to production chart resolver/validator; current torus remains known-red |

If the actual implementation needs production/API changes or cannot satisfy a
touched row without reusing production decision procedures, stop and return to
Review. Do not expand this slice.

## 4. Allowed scope

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

## 5. Test-only oracle boundary

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

## 6. Oracle-mutation tests

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

## 7. Integration with direct acceptance

Refactor the six existing direct acceptance cases to invoke the independent T1
oracle after the public production call. Preserve every current backend,
fallback/recovery, origin, nonempty, and degree-four assertion. Do not weaken,
delete, or convert an assertion to a diagnostic.

The production `result.success` assertion remains, but it is no longer the
sole semantic authority. A failing independent oracle remains a test failure
even when production validation says success.

T2—not T1—adds torus, thin bent tube, prescribed sphere, and mechanical
feature to the direct matrix and adds the semantic fixture manifest. The
current torus failure remains explicit in the runtime tracker; T1 must not
silently add or remove it from acceptance to make the suite green.

## 8. Packaging

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

## 9. Code + Build acceptance

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

## 10. Required following Test + Benchmark

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

## 11. Handoff after T1

If T1 immutable acceptance passes, M1 authority-kernel Code + Build may begin
and must use the accepted intent/precondition/oracle/counterexample/evidence
format. T2 complete direct corpus/semantic manifest remains required before M2
behavior migration.
