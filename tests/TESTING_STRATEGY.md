# Surface-Cell Testing Strategy

**Status:** normative testing policy  
**Scope:** direct source-authoritative surface-cell production and its stage contracts  
**Status authority:** artifact IDs, run totals, active failures, and next-turn instructions belong in dated reports, `TODO.md`, and the handoff—not this file.

## 1. Intended product

Given a supported source triangle mesh, a degree-four tangent directional field, exact source-feature constraints, and a target-size field, normative Pipeline B returns one verifier-assigned disposition:

- D0 `Certified`: complete deterministic source-attached field-aligned manifold pure-quad output satisfying every structural and calibrated quality contract;
- D1 `QualityRelaxed`: complete structurally valid pure-quad output with every missed calibrated quality gate named and measured;
- D2 `LocallyDegraded`: complete structurally valid pure-quad output with every region built by the one declared degraded producer identified;
- D3 `Partial`: a structurally valid pure-quad subset with every omitted region and typed cause identified;
- D4 `DiagnosticOnly`: no mesh, reserved for the closed catastrophic set in `DESIGN.md`.

Strict direct fixture acceptance requires D0. D1-D3 are usable, truthfully labeled product outcomes and have their own tests, but never close a strict gate or become certified baselines. D4 conditions and non-catastrophic degradation triggers must not be conflated.

Pipeline A is optional future work. It has no test or implementation obligation until Pipeline B is D0 on the full committed matrix with calibrated stable quality gates.

## 2. Testing integrity

Tests establish intended behavior; they do not negotiate it.

For every mandatory test or parameterized family, record:

1. **intent** — the user-visible or stage-boundary contract;
2. **proved precondition** — evidence that the fixture enters the semantic state under test;
3. **stimulus** — the public production entry point or named target stage;
4. **independent oracle** — the observable input/output relation;
5. **counterexample** — a tamper, mutation, or negative fixture the oracle rejects;
6. **evidence identity** — fixture/corpus version, seed, executable, discovery name, artifact, and resource budget.

A pass is invalid evidence when the target path was not entered, the fixture did not establish its precondition, the test was not packaged/discovered, the assertion observes only mechanics, or the oracle reuses the producer's decision procedure.

Never weaken assertions, replace semantic validation with existence/count/hash checks, synthesize expected success from production output, relabel invalid fixtures, disable a failing mandatory test, or treat timeout/no-crash as correctness.

## 3. Evidence layers

Evidence is cumulative. A lower layer cannot close a higher-layer gate.

| Layer | Required evidence |
|---|---|
| L0 type/schema | non-convertible semantic domains, closed outcomes, invalid-state construction failures |
| L1 stage contract | positive, tamper, boundary, and exact postcondition tests |
| L2 property/metamorphic | generated cases, seed replay/shrinking, representation and parameter relations |
| L3 independent semantic oracle | topology, source support, certificates, product disposition, geometry |
| L4 representative direct corpus | public production pipeline over the committed fixture matrix |
| L5 robustness/fuzz | structured valid/invalid generation, sanitizers, minimized reproducers |
| L6 quality/performance | alignment, approximation, element quality, determinism, work, memory, and time |

Focused fixtures isolate contracts. Only L4 can close a representative product gate.

## 4. Mandatory committed direct matrix

Every case enters `remesh_from_raw_cross_field` with:

- requested and executed backend `SurfaceCells`;
- `SurfaceCellFallbackPolicy::Fail`;
- source-grid recovery disabled;
- no hidden fallback attempt or undeclared producer substitution;
- production preprocessing and field extraction/generation as declared by the manifest;
- all debug/intermediate retention settings excluded from semantic acceptance.

The committed smoke matrix is:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder;
5. torus;
6. thin bent tube;
7. prescribed sphere;
8. mechanical feature;
9. bunny with generated smooth field;
10. vase with generated smooth field.

Run all named cases within the tier's bounded budget; an earlier failure does not authorize omission of later fixtures. Known-red product cases remain discovered and reported explicitly. They are not disabled and are not counted as required-green proof until an immutable acceptance turn promotes them.

The fixture manifest records its current expected strict disposition. A case expected to reach D0 fails its gate at D1-D4. Deliberate degradation fixtures are separate from the representative strict matrix.

## 5. Fixture and corpus authority

Every committed or generated fixture must have a versioned manifest entry containing:

- checksum, license, provenance, generator version, and deterministic seed;
- source face arity—production-success cases are triangle inputs, not pre-quad outputs;
- vertices/faces, connected components, orientability, Euler characteristic, genus where defined, and boundary loops;
- valid/invalid class, including degeneracy, nonmanifoldness, self-intersection, duplicate faces, triangle soup, or close-sheet separation;
- geometry scale, curvature/thinness/noise class, and feature graph;
- cross-field source, degree, tangent variation, matching distribution, singularity count/index, and boundary/non-contractible holonomy;
- target-size variation and feasibility class;
- intended success or typed failure and the exact invariant set;
- test tier, timeout/work/RSS budget, and expected artifact labels.

Row uniqueness or face count is inventory information only; neither proves semantic field/topology coverage.

Invalid inputs must fail closed at a documented boundary. They must not be substituted for successful arbitrary-triangle-mesh acceptance.

## 6. Independent product oracle

### 6.1 Hard invariants

For every emitted D0-D3 mesh, an independently written test oracle recomputes or verifies:

- non-empty degree-four faces and valid indices;
- no degenerate/inverted/duplicate faces, T-junctions, nonmanifold edges, or self-intersections;
- orientability, connected components, boundary loops, and Euler characteristic under the declared topology policy;
- one accepted cell to one output quad within the emitted set;
- exact source support for every output vertex;
- complete cell/edge/vertex lineage and certificate ownership;
- exact-once consumption of owned topology regions, rails, isolation seams, singularity ports, and periodic/quotient relations after explicit D3 omission bookkeeping;
- requested/executed direct backend, no hidden substitution, and truthful recomputed disposition;
- every degradation certificate matches an observable fact and every observable degradation has exactly one certificate;
- deterministic canonical semantic identity;
- finite global work and declared resource bounds.

The test oracle may share primitive math and typed data schemas. It may not call the producer's acceptance decision, validator decision procedure, or expected-output construction. `result.is_produced()` and production validation are observations, not the independent oracle.

### 6.2 Geometry, field, and element quality

Measure:

- bidirectional surface approximation;
- boundary approximation and preservation;
- field-alignment error distribution;
- feature recall and feature-alignment error;
- normal deviation where relevant;
- angle deviation from 90 degrees;
- edge-length/target-size error;
- aspect ratio, warpage, scaled Jacobian, inversion, and near-zero area;
- valence distribution and irregular-vertex placement;
- runtime, peak RSS, and work-ledger growth.

Topological/product invariants are exact. Numeric quality thresholds require documented definitions, mutation sensitivity, representative baselines, and approval. A metric may be observational before calibration but must be labeled non-gating; it cannot silently imply readiness.

### 6.3 Oracle mutation adequacy

The independent oracle must reject deliberate corruptions of:

- face arity, index validity, winding, incidence, and topology;
- source support, lineage, ownership, and certificate consumption;
- field direction and feature correspondence;
- geometry attachment, self-intersection, inversion, and element quality;
- backend/undeclared-substitution/disposition;
- deterministic semantic identity.

A production bug is not contained until the smallest relevant mutation/reproducer fails the oracle for the intended reason.

## 7. Producer and topology contracts

Each strict producer exposes exactly `NotApplicable`, `Produced`, or `Rejected`.

Required properties:

- valid applicable regions may produce;
- invalid applicable metadata rejects rather than becoming not applicable;
- rejection is terminal for that producer and cannot be softened internally;
- produced payloads are non-empty and internally valid;
- exhaustive dispatch is invariant to unrelated producer ordering;
- source component, topology region, isolation sheet, and field chart remain distinct domains;
- global topology/rail/relation registries are verified once; local producers consume only certified local paths;
- aggregation validates producer scope and cannot rewrite semantic ownership;
- every recursive or combinatorial producer uses a shared global work ledger and monotone progress measure.

State-machine tests cover every transition and impossible state. Repeated-call and alternating success/failure sequences prove reset and transactional behavior.

Degradation is an orchestration/verifier concern, not a producer state. Only the disposition layer may invoke the separately named degraded producer after observing terminal strict rejection. That substitution is single-shot, bounded, non-recursive, cannot mutate upstream products, and is always recorded.

## 8. Transport, chart, rail, and quotient contracts

### 8.1 Typed routes and transport

A route step contains canonical source-edge topology, optional interior transition identity, quarter-turn rotation, lattice translation, and orientation in their declared domains.

Properties include:

- composition, inverse, identity, associativity, and cycle closure;
- genuine one-face boundaries carry no invented interior index;
- two-face transitions validate topology and reciprocal faces;
- branch relabeling and route reversal preserve canonical semantics;
- malformed, duplicate, nonreciprocal, wrong-domain, and wrong-owner routes fail typed;
- full-EF rows, compact transition indices, face rows, and topology keys are never numerically interchangeable.

### 8.2 Topology region versus isolation sheet

A topology region is connected by exact source adjacency and split only by genuine boundary, hard feature, source component, or declared parent-chart authority. A local isolation sheet is a geometric/barrier label and may subdivide one topology region.

Tests prove both distinctions with positive and negative witnesses. Every-face equality of global relation authority is prohibited.

### 8.3 Global rail scheduling

All incident regions consume one canonical source-rail breakpoint schedule decided before local cells commit.

Properties include:

- identical canonical breakpoints and side counts on both sides;
- endpoint, feature, parity, and declared adaptivity constraints;
- invariance under region order and permitted target-size representation changes;
- typed rejection for independent insertion, deletion, reorder, or wrong owner;
- typed subset-scoped infeasibility for an unschedulable rail subset, followed by truthful D3 omission rather than a run failure;
- strictly positive rail lengths and deterministic canonical tie-breaking;
- bounded solver/work behavior.

### 8.4 Occurrence quotient and materialization

Each cell starts with four distinct corner occurrences. Merges require one verified ordinary, hard-rail, periodic, or singularity-port relation.

Tests require:

- every relation independently valid, reciprocal, owned, and consumed exactly once;
- equal lattice/3D coordinates without a relation remain distinct;
- duplicate/conflicting/unowned relations fail closed;
- chained, unused, off-face, cyclic, and multi-isolation relation graphs;
- deterministic equivalence classes under emission/order permutations;
- one accepted cell maps to exactly one quad with complete lineage.

Intermediate-object retention, raw relation IDs, exact output row order, and predicted counts are diagnostics unless they are the explicit contract under test.

### 8.5 Field-aligned curve network

Pipeline B's `FieldAlignedCurveNetwork` tests require:

- singularity port count/branch derived from field index and every port owned exactly once;
- branch-consistent exact-support traces with typed start, crossing, crash, merge, boundary, feature, and singularity events;
- no silent interior termination, geometric crossing, duplicate segment, or unowned mandatory topology;
- motorcycle termination/decomposition producing complete disc regions on every supported positive fixture;
- explicit counterexamples for limit cycles, near-coincident traces, non-disc regions, incompatible holonomy, and failed quadrangulability;
- tracing-order, start-port, row, orientation, and scheduler metamorphic invariance;
- independent verification of the field-quadrangulability certificate and region proofs.

The combined tracing/decomposition algorithm requires direct evidence; tests may not assume that guarantees from separate cited algorithms compose automatically.

### 8.6 Disposition and degradation

Required properties:

- D0-D4 are each reachable through a fixture or controlled fault injection with proved preconditions;
- the verifier recomputes tier from the product and certificates rather than trusting a producer flag;
- unrecorded degradation and fabricated degradation records both fail;
- tier can only stay the same or decrease;
- the degraded producer exactly conforms to the unmodified boundary plan, emits pure quads, remains manifold, and cannot mutate upstream products;
- D3 omitted-region sets reconcile with rail/relation ownership and quotient consumption;
- tier, degraded set, omitted set, and certificates are invariant under every permitted permutation;
- strict representative gates accept D0 only.

## 9. Determinism and metamorphic properties

At minimum, declare and test:

- source vertex/face row permutation;
- component/producer emission order;
- cyclic start rotation and route reversal with orientation inversion;
- output vertex/face row permutation;
- thread/schedule and associative-container order;
- rigid transform and uniform scaling with correspondingly transformed fields/targets/tolerances;
- equivalent cross-field branch relabeling by quarter turns;
- source triangulation changes that preserve the declared surface/field semantics;
- fresh-process repetition and in-process success/failure sequences;
- disposition tier, degraded-region set, omitted-region set, and degradation certificates.

Each relation states the output facts that must remain equal, may vary, and must change. Raw structural hashes are same-artifact diagnostics; only a validated canonical semantic digest may express invariant identity.

## 10. Generative and fuzz testing

### 10.1 Structured generation and shrinking

Use deterministic generators for small triangulated disks, annuli, spheres, tori, multiple components, close sheets, thin tubes, fans, cyclic orbits, hard-rail graphs, and relation graphs. Generate degree-four fields with controlled tangent variation, matching, holonomy, discontinuity, and singularity index, plus valid and corrupted certificates and target-size boundary cases.

Every failure records seed and serialized input. Shrinking minimizes mesh/field/relation data while preserving the stated precondition. Commit the minimized counterexample as a named `fuzz-replay` regression fixture before closure.

### 10.2 Coverage-guided fuzzing

Fast, deterministic, reentrant targets use Clang/libFuzzer with ASan/UBSan for:

- fixture/field parsing and sanitization;
- exact source support;
- transport/cycle algebra;
- certificate verification;
- occurrence/quotient relation ingestion;
- the independent product oracle.

Use valid and invalid seed corpora, input/work limits, corpus minimization, and saved-reproducer replay. The slower full pipeline uses a bounded process-isolated corpus harness unless it meets in-process fuzz constraints.

Crash, sanitizer finding, nondeterminism, unbounded work, or timeout is failure evidence. No-crash alone is never semantic success.

## 11. Build, discovery, and labels

All portable mandatory authority and minimized replay cases are built and
discovered by default in immutable artifacts. Toolchain-specific fuzz targets
are mandatory in their declared Clang sanitizer artifact. CTest/GoogleTest
labels express role:

- `contract-required`;
- `intent-smoke`;
- `metamorphic`;
- `oracle-mutation`;
- `fuzz-replay`;
- `corpus-nightly`;
- `quality-benchmark`;
- `historical-diagnostic`.

Historical tests are triaged one by one. Migrate a test only after naming its intent and replacing recovery, raw-ID/order, exact-count, retention-lifetime, or other proxy oracles. Do not enable the historical target wholesale as product proof.

Artifact preflight verifies:

- exact executable and discovered test name;
- label and required/known-red status;
- fixture/corpus checksum and generator/seed;
- sanitizer and resource configuration where applicable;
- metric schema and oracle version.

A compiled source file, aggregate count, broad filter, or passing helper is not packaged test authority.

## 12. Required gate reporting

Every Test + Benchmark report separates:

1. artifact/source/fixture/corpus integrity;
2. independent discovery;
3. required-green contract regressions;
4. known-red direct intent progress;
5. metamorphic/property results and seeds;
6. oracle-mutation adequacy;
7. fuzz campaign/replay and sanitizer findings;
8. representative corpus dispositions;
9. geometry/field/element-quality distributions;
10. determinism, global work, runtime, and peak RSS;
11. stable regression/pattern mapping.

Run named tests before aggregates. Preserve exact failing input, seed, log, and minimized artifact. Reduced failure counts, later failure stages, focused passes, or improved metrics do not close a direct gate unless the complete intended oracle passes.

## 13. Turn separation

### Code + Build

May:

- edit production/test/fixture/benchmark/CMake code within the approved slice;
- compile and package;
- inspect static build evidence.

Must not run generated project binaries, test discovery, tests, benchmarks, fuzzers, or project CLI/help.

### Test + Benchmark

May:

- verify and run the exact immutable artifact under the approved plan;
- record runtime, quality, fuzz, and resource evidence.

Must not edit implementation, tests, fixtures, validators, benchmarks, manifests, CMake, or workflows; configure/rebuild/relink; substitute artifacts; weaken expectations; or synthesize success.

### Review

May:

- inspect source and evidence;
- update planning, architecture, testing policy, and review records.

Must not edit runtime/test logic or execute generated project binaries.

## 14. Stop conditions

Stop and revise the plan if:

- a fixture precondition is unproved;
- the independent oracle shares the producer's decision procedure;
- a mandatory test is absent from the package/discovery manifest;
- a lower-layer test is used to close a higher-layer gate;
- a success assertion checks only existence, status, count, row ID/order, hash, or intermediate retention;
- fuzzing lacks deterministic replay, minimization, bounds, or sanitizer configuration;
- numeric quality limits lack definitions and approved baselines;
- a known-red test is hidden, disabled, or counted as green;
- a D1-D3 result is counted as a strict fixture pass or certified baseline;
- a degradation lacks a substantiated certificate, recurses, mutates upstream authority, or is chosen by the producer being degraded;
- Pipeline A is scheduled before Pipeline B eligibility gates;
- an assertion, fixture, validator, lineage, failure, strict-gate, or declared-degradation contract is weakened.

## 15. Authority

The detailed audit, finding register `TA-01` through `TA-12`, scientific grounding, and staged `T0`–`T6` redesign are in:

`../.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`.
