# Gate 4 Transition-Quotient Runtime Regression and Executable Coverage — Mandatory Design Review Plan

Status: **authoritative next turn**
Turn type: **Review only**
Active design gate: **G4 topology-distinct completion and singularities**
Configured optional review policy: `never`
Review authority: **mandatory process-guard override**

## Why Review is mandatory

The review-approved implementation `7f486632b154a303789df6c4dd44f602c8c71281` compiled as immutable artifact `9024549134`, but artifact-only runtime validation did not establish accepted material progress:

- plane, seam, close sheets, and cylinder all regress 3/3 at `tracing/phase-front / InvalidFrontBoundaryAuthority`;
- retained focused topology/polygonal/curved/mixed/periodic groups regress broadly;
- exact torus reaches phase-front `Produced` but rejects at `UnconsumedAuthoritativeIsolationSeam` with 4/8/4 region/seam/relation authority and zero consumption;
- semantic-digest tests were compiled only in a disabled historical target and are absent from the packaged executables;
- several other mandated quotient/retention counterfactuals have no independently discoverable packaged test.

The controlling process guard forbids another ordinary Code + Build when retained authority regresses or the quotient remains unconsumed. This Review must validate or replace the proposed remediation architecture before implementation resumes.

## Review boundary

Allowed:

- inspect repository source, tests, CMake/test target wiring, immutable reports, packaged discovery inventories, and exact runtime evidence read-only;
- trace each failure to a concrete ownership/representation contract;
- compare the review-approved plan, implementation, compile report, and actual executable coverage;
- classify tests as valid, missing, over-coupled, permissive, or packaged incorrectly;
- approve, amend, or replace the proposed next Code + Build plan;
- update documentation and PR metadata after the review decision.

Forbidden:

- production, test, fixture, validator, benchmark, or build-system edits;
- configure, compile, link, rebuild, runtime execution, benchmark execution, or discovery regeneration;
- validator/tolerance weakening;
- count/order/frequency/ID/proximity ownership;
- Euclidean welding, representative-sheet substitution, fallback/recovery, arbitrary subset search, synthetic topology correction, fixture-specific success, or assertion weakening;
- merging or closing PR #8.

## Required inputs

Read in order:

1. `.agents/Directional/Future_Chat_Session_Handoff.md`;
2. `TODO` and `MILESTONE_G_TODO.md`;
3. `.agents/Directional/DESIGN.md`;
4. `.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md`;
5. `.agents/Directional/Gate_4_Topology_Region_Independent_Design_Review_Report.md`;
6. `.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Code_Build_Report.md`;
7. exact implementation source at `7f486632b154a303789df6c4dd44f602c8c71281`;
8. `tests/TESTING_STRATEGY.md`, `cmake/DirectionalTests.cmake`, and packaged `--gtest_list_tests` inventories recorded by the runtime evidence;
9. `.agents/Directional/GitHub_Workflow_Policy.md` and the turn-based-coding-agent Review/testing-integrity/recovery/handoff/GitHub-workflow references.

## Review question 1 — source-boundary topology versus transition index

Determine the smallest general representation that restores genuine source boundaries while preserving strict interior transition provenance.

The review must account for this exact defect:

- `edge_matching_indices()` contains only two-face interior source edges;
- `assign_open_front_boundary_authority()` requires that interior index before classifying a one-face edge as `GenuineSourceBoundary`;
- therefore valid source boundaries are rejected by construction.

Required decision:

- specify whether `sourceRouteTopology` alone is authoritative for genuine boundaries and how `sourceRouteEdges` is represented when no interior matching index exists;
- keep periodic, hard-rail, internal-isolation, and ordinary transition provenance strict;
- prevent a missing interior index from being silently accepted on a path whose semantics require transport;
- require counterfactual tests for genuine boundary, hard rail, embedded relief, ordinary interior, and periodic cut classification.

## Review question 2 — internal-isolation-seam consumption witness

Decide what exact evidence proves that a multi-isolation topology region's internal seam has been consumed by quotient materialization.

Current implementation builds the consumed set only from `SurfaceTraceSegment.transitionSourceEdges` on cell boundary paths, then requires every `SurfaceTopologyRegion.internalIsolationSeamTopology` entry. Torus reports all eight seams unconsumed.

The review must decide whether valid ownership comes from one or more of:

- explicit cell-side transition routes;
- occurrence-equivalence provenance crossing the seam;
- exact source-chart/local-isolation lineage represented in a quotient class;
- region-level coverage plus reciprocal transition witnesses;
- another first-class source-topological relation.

The decision must reject these unsound shortcuts:

- unconditional “all region seams consumed” marking;
- seam selection by count, ID, order, frequency, boundary length, or topology hash;
- position/lattice coincidence without reciprocal connectivity;
- erasing local-isolation identity or selecting one representative sheet;
- permitting a seam requirement that no valid producer/materializer event can ever witness.

Require positive and broken-counterfactual tests that distinguish a truly consumed internal seam from merely retained metadata.

## Review question 3 — quotient and topology counterfactual completeness

Audit the exact implementation against every prior review requirement and state which contracts have executable proof:

1. multi-isolation cells without representative-sheet substitution;
2. equal chart/lattice occurrences without reciprocal connectivity remain distinct;
3. ordinary reciprocal pairs union only oriented endpoints;
4. periodic pairs apply the full owned `R^r p+t` relation and reject an incorrect transform;
5. multiple relations are consumed by explicit ownership rather than order/count;
6. exact hard-rail counterparts stitch while missing/ambiguous counterparts reject and genuine boundaries stay exterior;
7. scalar `SurfacePoint` plus complete sorted topology-region/local-isolation/source-chart/support/equivalence lineage;
8. incidence catches repeated corners, nonmanifold edges/fans, artificial boundaries, and wrong Euler state;
9. failure-path trace retention if and only if requested;
10. semantic digest is row/component-order invariant and sensitive to connectivity, winding, source support, component separation, and lineage.

Classify each as:

- executable and adequate;
- executable but permissive/over-coupled;
- implemented but not independently tested;
- test exists but is not in an approved packaged target;
- missing.

## Review question 4 — test-target and artifact closure

Resolve the discrepancy between the compile report's focused-coverage claim and the actual package.

Required decision:

- choose the minimal default packaged target(s) for every active-gate counterfactual;
- do not rely on `DIRECTIONAL_BUILD_HISTORICAL_TESTS=ON` unless the target is explicitly approved, compiled, packaged, and its added scope is justified;
- ensure `--gtest_list_tests` from the immutable artifact exposes every required case;
- keep deliberately long BunnyRandom/Vase cases independently excludable from bounded suites;
- preserve Release/static/Ninja, `PRE_TEST`, exact target allowlist, and `runtimeExecution=false` Code + Build separation.

## Review question 5 — next implementation scope and acceptance

Approve, amend, or replace the `proposed_pending_review` Code + Build plan in the runtime report.

The authoritative successor plan must:

- be the smallest coherent change that fixes boundary authority, resolves seam-consumption ownership, and supplies executable counterfactual coverage;
- identify exact production/test/build files allowed to change;
- identify exact approved build targets;
- forbid runtime during Code + Build;
- require a following artifact-only Test + Benchmark using only its immutable output;
- preserve all retained G0-G3, topology-region, polygonal, curved, mixed, periodic, validation, API, and historical-failure baselines;
- require plane/seam/close-sheets/cylinder direct success in three processes;
- require semantic-digest invariance/sensitivity tests to execute;
- require exact torus direct strict-valid pure quads with complete lineage, one component, zero boundary loops, Euler zero, and all four regions/eight seams/four relations consumed;
- forbid predicted/golden torus output counts;
- keep sphere deferred until torus closes.

## Required review report

Create a new independent Review report containing:

- decision: `Approved`, `Approved with amendments`, or `Rejected`;
- finding severity and exact source/test/build evidence;
- explicit answer to all five review questions;
- per-test validity/coverage classification;
- exact accepted seam-consumption model and rejected alternatives;
- disposition of the proposed Code + Build plan;
- authoritative successor plan path or explicit block if no safe plan exists;
- confirmation that no source/test/build edit, configure/build, or runtime occurred.

## Completion and repository handoff

After the review decision:

1. update `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, `tests/TESTING_STRATEGY.md`, live handoff, and durable remediation/reorientation records;
2. remove or mark superseded planning authority so exactly one next plan remains;
3. verify `.github/workflows` contains only `agent-source-snapshot.yml` and temporary trigger/payload directories are absent;
4. update PR #8 metadata while keeping it open, draft, and unmerged;
5. make a new top-level PR #8 conversation comment as the **final repository write**, then perform no further GitHub write.
