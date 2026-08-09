# Surface-Cell Test-Suite Independent Audit and Redesign Plan

**Status:** authoritative testing-audit decision and staged redesign plan  
**Review type:** documentation-only independent Review  
**Inspected implementation authority:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Planning baseline:** `a3fba7dc83d9d5b77cdbd10794e3c460de526dbc`  
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8  
**Decision:** **redesign required; the current suite is a contributing part of the recurring-regression system, but it is not the sole cause**  
**Last updated:** 2026-08-09 UTC

## 1. Scope and review boundary

This review cross-references:

- the live branch test, fixture, benchmark, and CMake sources;
- the 34-event PR #8 regression inventory and nine repeated coding patterns;
- the turn-separated testing-integrity rules in the turn-based coding-agent workflow;
- the supplied Directional Fields, MIQ, QEx, QuadWild, Instant Meshes, and FlowRep papers;
- primary implementation/testing examples from libQEx, CGAL, Geometry Central, LLVM libFuzzer, RapidCheck, and Thingi10K.

No project executable, test, benchmark, configure, compile, link, or generated binary was run. This Review may change planning and test-policy documentation only. Runtime totals cited below are the entering immutable artifact records, not results produced by this review.

## 2. Executive decision

The suite is not empty, trivial, or wholly mechanics-only. It has substantial local contract coverage, enters the production remesh API for six direct fixtures, prohibits fallback/recovery in that gate, and checks non-empty pure-quad output. Those are useful controls.

It is nevertheless insufficient as proof of the intended product:

1. the direct acceptance oracle stops at pipeline disposition and face degree;
2. it does not independently verify field alignment, feature alignment, source approximation, topology, source lineage/certificates, manifold incidence, element quality, determinism, or work bounds;
3. the richer prescribed field/topology fixtures are absent from the default direct acceptance matrix;
4. quality metrics already computed by the benchmark path are reported but do not gate acceptance and partly reuse production validation machinery;
5. no property-based generator, shrinker, or coverage-guided fuzz target exists;
6. several strong end-to-end suites are compiled only in the default-off historical target, while some of those historical assertions validate recovery, intermediate retention, or exact counts rather than the strict direct product;
7. the permanent regression record identifies `TEST_AUTHORITY_COVERAGE_GAP` as six events with five recurrences—the second-largest recurring category.

Therefore the suite has participated in the regression loop by allowing a focused proxy to turn green while the representative production state shape remained absent or unobserved. The production architecture remains the primary defect source; the test architecture failed to expose or contain it early enough.

## 3. Current-suite inventory

### 3.1 Build and discovery shape

The default CMake configuration builds and discovers four executables:

| Default executable | Entering discovered denominator | Role |
|---|---:|---|
| `directional_compiled_api_tests` | 8 | compiled API |
| `directional_surface_cell_producer_tests` | 166 | producer, direct acceptance, transition quotient, Phase10 |
| `directional_surface_cell_completion_tests` | 164 | strands, descriptors, completion, simplification |
| `directional_surface_cell_validation_tests` | 67 | optimizer and validator |
| **Total** | **405** | default-discovered tests |

The default-off historical executable contains important integration suites, including `MilestoneGP26Tests.cpp`, `MilestoneGP27Tests.cpp`, `SurfaceCellPipelinePhase20Tests.cpp`, `SurfaceCellTracingPhase14Tests.cpp`, and `SurfaceArrangementPhase16Tests.cpp`. They must be triaged by intent and migrated selectively; enabling them wholesale would also reintroduce recovery-oriented and representation-brittle assertions.

### 3.2 Direct production matrix

`SurfaceCellDesignAcceptanceTests.cpp` invokes `remesh_from_raw_cross_field` with the SurfaceCells backend, fail fallback, source-grid recovery disabled, and six fixtures:

- plane;
- multi-face seam;
- close sheets;
- cylinder;
- bunny with generated smooth field;
- vase with generated smooth field.

Its success oracle checks direct backend disposition, no fallback/recovery, completed-surface-cell origin, non-empty output, four columns, and degree four. It does not independently inspect the semantic or geometric validity of the returned quad mesh.

### 3.3 The input-shape hypothesis

The audit rejects the concern that committed production acceptance inputs are already quad meshes. The ten unique SurfaceCells cases in the milestone-G manifest resolve to triangle-only source meshes. Bunny and vase are explicitly asserted as three-column triangle inputs by the default fixture-integrity test; the remaining committed mesh assets are also triangle-only.

The actual gap is diversity and semantic labeling, not triangle-versus-quad format.

| SurfaceCells fixture | Source V / triangle F | Field source | Parsed field-row diversity | In default direct gate? | Principal missing purpose |
|---|---:|---|---:|---:|---|
| plane | 20 / 24 | prescribed raw | 1 / 24 | yes | useful baseline only |
| multi-face seam | 25 / 32 | prescribed raw | 2 / 32 | yes | branch discontinuity |
| close sheets | 32 / 36 | prescribed raw | 2 / 36 | yes | geometric proximity versus sheet identity |
| cylinder | 80 / 128 | prescribed raw | 16 / 128 | yes | boundary/annulus and periodic direction |
| torus | 72 / 144 | prescribed raw | 144 / 144 | no | genus-one cycles and holonomy |
| thin bent tube | 132 / 240 | prescribed raw | 240 / 240 | no | curvature, thin features, spatially varying tangents |
| prescribed sphere | 98 / 192 | prescribed raw | 192 / 192 | no | singularity/index structure |
| mechanical feature | 152 / 300 | prescribed raw | 62 / 300 | no | hard-feature alignment |
| bunny | 502 / 1,000 | generated smooth | generated | yes | irregular organic triangulation |
| vase | 1,274 / 2,404 | generated smooth | generated | yes | larger open organic surface |

“Parsed field-row diversity” counts unique double rows after parsing and is only a coarse inventory signal. It does not prove distinct matchings, singularity indices, cycle transport, or adequate tangent variation. The redesigned manifest must record those semantic properties explicitly.

### 3.4 Intent-versus-mechanics sample

| Current evidence | What it proves | Audit classification |
|---|---|---|
| `SurfaceCellDesignAcceptanceTests.cpp` invokes the public raw-field remesh API with fail fallback and recovery disabled. | Real direct pipeline entry, backend disposition, non-empty pure-quad arity. | useful partial product intent |
| The Phase10 plane case asserts exactly 64 cells/quads and several cases inspect retained phase-front/network fields. | One current discretization/cardinality and internal lifecycle. | mechanics; not a stable product oracle unless exact count/lifetime is the contract |
| `SurfaceCellPipelinePhase20Tests.cpp` contains historical expectations for `SourceGridRecovery` and `2 * source face count`. | Legacy recovery behavior and a construction-specific count. | incompatible with strict direct acceptance; retain only as historical diagnostic |
| `MilestoneGP27Tests.cpp` runs a broad production matrix but its broad disposition check stops at `result.success`; another test conditionally checks non-empty output only on success. | Public entry coverage and disposition sampling. | insufficient independent output intent |
| `BenchmarkQuality` computes pure-quad rate, incidence defects, topology/boundary preservation, feature/field alignment, size error, surface approximation, valence, hashes, and RSS. | Valuable observational metric instrumentation. | non-gating and partly production-coupled |
| P27 quality tests use a synthetic square and bow-tie. | Metric implementation mechanics for simple cases. | useful unit evidence; not production quality acceptance |

The correction is selective migration: retain useful stage mechanics as L0/L1
evidence, but do not count them as L3/L4 semantic or representative proof.

## 4. Regression cross-reference

`TEST_AUTHORITY_COVERAGE_GAP` accounts for six PR events and five recurrences:

| Event | What the test authority missed |
|---|---|
| `PR8-R004` | passing helper tests never entered the structural-repair production path |
| `PR8-R013` | requested validator contracts were absent from the packaged executable |
| `PR8-R022` | row-order evidence compared raw DCEL IDs rather than canonical topology |
| `PR8-R024` | an impossible subdivision-dependent witness was treated as the oracle |
| `PR8-R027` | torus topology authority depended on intermediate-retention timing |
| `PR8-R030` | required quotient counterfactuals were not executable in the default package |

The current active recurrence, `PR8-R034` / `G4-R007`, reinforces the same pattern even though its primary category is `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`: single-relation face-chart tests passed while the direct torus worsened from 74 to 165 mismatches because chained, unused, and off-face relation shapes were absent.

The other repeated categories imply mandatory test forms:

| Repeated pattern | Required test architecture |
|---|---|
| `RP-01` authority-domain conflation | type non-convertibility, checked-conversion tamper tests, independent semantic keys |
| `RP-03` policy/stage conflation | exhaustive state-machine transition tests and failure injection |
| `RP-04` cumulative nontermination | global-work invariants, adversarial sequences, process isolation, resource bounds |
| `RP-05` representation identity | row/order/orientation/component/thread metamorphic equivalence |
| `RP-06` state-cardinality growth | generated relation graphs and scaling assertions |
| `RP-07` cyclic linearization | generated fans/cycles, wraparound, rotation, and reversal properties |
| `RP-08` disposition collapse | exhaustive closed-outcome dispatch and no-substitution properties |
| `RP-09` local consumption of global authority | multi-relation graphs with selected local witness paths and unused global relations |

## 5. Finding register

These findings are structural test debt, not additional runtime regression events. They do not change the 34-event/20-recurrence totals.

| ID | Severity | Finding | Required close condition |
|---|---|---|---|
| `TA-01` | Critical | Direct product acceptance has an incomplete semantic oracle. | An independent product oracle gates exact topology/lineage invariants and calibrated geometric/quality metrics. |
| `TA-02` | Critical | The richest prescribed topology/field fixtures are absent from the default direct matrix. | All ten committed production cases are packaged, discovered, semantically classified, and reported as direct intent gates. |
| `TA-03` | Critical | Benchmark quality is observational, non-gating, and partly coupled to production validation. | Independent test-only oracle decisions gate invariants; benchmark metrics have approved thresholds/baselines and no producer decision reuse. |
| `TA-04` | High | No property-based generator, shrinker, or coverage-guided fuzz target exists. | Deterministic structured generators, minimized replay cases, and sanitizer fuzz targets run at declared tiers. |
| `TA-05` | High | Focused helper/internal-state evidence can be promoted to product proof. | Every mandatory test records intent, proved precondition, production entry, independent oracle, counterexample, and package identity. |
| `TA-06` | High | Test helpers have mirrored weak production domains or impossible witnesses. | Oracle mutation tests and domain-independent constructions prove that the test fails for the intended corruption. |
| `TA-07` | High | Packaged discovery is not a first-class contract. | Artifact manifests enumerate every required test, fixture, corpus version, and label; preflight fails on absence. |
| `TA-08` | High | Raw IDs, exact row order, exact counts, hashes, or retention lifetime sometimes stand in for semantics. | Such values are diagnostic only unless cardinality/order is itself the documented product contract; canonical/metamorphic oracles replace them. |
| `TA-09` | High | Repeated-sequence, reset, work-growth, and resource behavior is under-tested. | Fresh-process repetition plus in-process sequence tests gate determinism, state reset, monotone work, memory, and time budgets. |
| `TA-10` | High | Fixture metadata does not prove semantic coverage of field/topology states. | A versioned fixture manifest records topology, boundaries, components, feature classes, field variation, matching/holonomy, singularity expectations, scale, and intended failure/success. |
| `TA-11` | High | Oracle sensitivity is not demonstrated. | Deliberate output mutations for topology, lineage, geometry, field direction, features, and quality are rejected by the independent oracle. |
| `TA-12` | Moderate | `tests/TESTING_STRATEGY.md` mixes normative policy with artifact history and next-turn status. | The strategy remains normative-only; dated reports, TODO, milestone, and handoff own status/evidence. |

### 5.1 Turn-based testing-guidance compliance

The audit applied the repository-specific
[turn-based coding-agent testing guidance](https://github.com/akashskypatel/turn-based-coding-agent-skill),
including its Test + Benchmark and testing-integrity rules.

| Guidance | Current suite/process | Audit result |
|---|---|---|
| Separate Code + Build from Test + Benchmark | Planning and artifact records enforce this strongly. | compliant process control |
| Establish intended behavior independently | Product contract exists, but many tests encode stage mechanics/counts/retention. | partial; redesign required |
| Prove fixture/input preconditions | Bunny/vase integrity and several focused fixtures do; the direct matrix lacks semantic field/topology preconditions. | partial |
| Observe the actual result | Direct acceptance observes public output, while many focused/historical tests stop at helpers/intermediates. | partial |
| Assert the intended input/output relation | Direct acceptance asserts disposition and arity, not complete topology/alignment/approximation/quality. | insufficient for product gate |
| Do not weaken assertions or synthesize success | Current policy prohibits both; regression history shows impossible/proxy oracles rather than approved weakening. | policy compliant, architecture incomplete |
| Focused tests do not establish readiness | Historical closeouts repeatedly let focused green evidence coexist with direct red/regressed fixtures. | noncompliant evidence promotion |
| Preserve exact artifact/discovery authority | Current plans are strong, but six RP-02 events include missing packaged tests. | improved; T1/T6 enforcement still required |
| Preserve deterministic reproducers | Fixed production options exist, but there is no generated seed/shrinker/fuzz replay system. | absent |

## 6. Domain research translated into test requirements

| Source | Test implication |
|---|---|
| Directional Fields survey | Representations, matchings, period jumps, singularity indices, boundary/non-contractible cycles, and holonomy need explicit properties; permutation or representative changes must not alter field topology. |
| MIQ | Quad acceptance includes field/feature alignment, element angle/edge distributions, singularity placement, and robustness to skinny/near-degenerate triangles, normal noise, and offset/smoothed geometry. |
| QEx | Tests must cover imperfect parametrizations, foldovers, numerical cracks, nearly degenerate triangles, manifold/watertight connectivity, exact-predicate boundaries, and complete geometry/connectivity reference results. |
| QuadWild | Representative testing must include noisy/self-intersecting/nonmanifold “in-the-wild” inputs, feature preservation, angle deviation, edge-length deviation, scaled Jacobian, irregular vertices, and large-corpus disposition. |
| Instant Meshes | Field alignment, singularity counts, angle/area distributions, feature snapping, scale, and robustness across heterogeneous models are product evidence—not merely visual diagnostics. |
| FlowRep | Parameter and field perturbations, global cycles/strands, systemic misalignment, and uneven sizing need robustness/metamorphic coverage. |
| Thingi10K | A standard-model-only corpus creates false confidence; stratified triangle soups and real-world defects are required at non-blocking and nightly tiers. |
| LLVM libFuzzer | Fuzz targets must be deterministic and fast, consume valid and invalid seed corpora, run with sanitizers, preserve minimized reproducers, and replay the committed corpus. |
| RapidCheck / Geometry Central | Generated properties need seed replay and shrinking; useful geometry properties include representation round trips and differential agreement between independent implementations. |
| CGAL remeshing tests | Precondition handling, feature constraints, self-intersection behavior, and postcondition validation must be explicit. |

## 7. Normative test architecture

Every mandatory test or parameterized family must declare six facts:

1. **Intent:** the user-visible or stage-boundary contract being proved.
2. **Proved precondition:** evidence that the fixture actually enters the semantic state under test.
3. **Stimulus:** the public production entry point or named target stage.
4. **Independent oracle:** observable input/output relation, not the producer’s own success flag or decision procedure.
5. **Counterexample:** a tamper, mutation, or negative fixture that the oracle must reject.
6. **Evidence identity:** fixture/corpus version, deterministic seed, executable, discovery name, artifact, and resource budget.

Required layers are cumulative:

| Layer | Purpose | Examples |
|---|---|---|
| L0 type/schema | make invalid states unrepresentable | non-convertible IDs, closed outcomes, schema tamper |
| L1 stage contract | isolate stage postconditions | transport composition, rail schedule, quotient exact-once |
| L2 property/metamorphic | remove representation dependence | row permutations, route reversal, rigid transforms, branch relabeling |
| L3 independent semantic verification | test actual output meaning | incidence/topology, source support, certificates, no recovery |
| L4 representative direct corpus | prove the public pipeline | all ten committed tri-mesh cases, strict direct disposition |
| L5 robustness/fuzz | discover unanticipated state shapes | structured generators, sanitizer fuzzing, minimized replay |
| L6 quality/performance | prove usefulness and bounded operation | alignment, approximation, element quality, determinism, work/RSS/time |

A lower layer cannot close a higher-layer gate.

## 8. Product oracle

### 8.1 Exact invariants

Successful direct output must independently satisfy:

- non-empty, degree-four faces only;
- valid indices; no degenerate or duplicate faces;
- orientable manifold incidence; no T-junctions or self-intersections;
- connected-component count, boundary-loop count, and Euler characteristic consistent with the declared source/topology policy;
- one accepted cell to one output quad;
- complete source support, lineage, ownership, and certificate consumption;
- no fallback, source-grid recovery, hidden generic substitution, or predicted-topology repair;
- deterministic canonical semantic digest under permitted representation changes;
- finite global work and resource ledger.

These are hard invariants, not tunable quality thresholds.

### 8.2 Calibrated geometric and field-quality gates

The suite must measure and eventually gate:

- bidirectional surface approximation;
- field-alignment error distribution;
- hard-feature recall and feature-alignment error;
- boundary approximation/preservation;
- angle deviation from 90 degrees;
- edge-length/target-size error;
- aspect ratio, warpage, scaled Jacobian, and inverted/near-zero-area elements;
- valence distribution and irregular-vertex placement;
- normal deviation where relevant;
- runtime, peak RSS, and work-ledger growth.

This review does not invent numeric limits. T1–T5 must establish metric definitions, mutation sensitivity, baselines on accepted fixtures/reference implementations where applicable, and explicit approval of thresholds before they become release gates.

## 9. Corpus and field coverage

The fixture manifest must classify each case by:

- triangle-mesh validity class: clean manifold, boundary, multi-component, near-degenerate, nonmanifold, self-intersecting, duplicated, disconnected, or triangle soup;
- topology: components, genus/Euler characteristic, boundary loops, orientability;
- geometry: scale, curvature range, thinness, close sheets, noise, skinny/vanishing triangles;
- features: none, open/closed hard rails, corners, intersections, mechanical features;
- cross field: source, tangent variation, matching distribution, singularity count/index, boundary/non-contractible holonomy, discontinuities;
- target size: uniform/spatially varying, ratios, feasibility, expected adaptivity;
- expected disposition and exact invariant set;
- tier, timeout/work budget, license, checksum, and provenance.

The committed ten-case corpus is the production smoke matrix. A larger stratified corpus is a nightly/benchmark tier. Invalid inputs must assert a typed fail-closed disposition; they must not be relabeled as expected product successes.

## 10. Generative, metamorphic, and fuzz design

### 10.1 Deterministic structured properties

Start without a mandatory third-party dependency. Build small test-only generators for:

- manifold triangulated disks, annuli, spheres, tori, and multiple components;
- close parallel sheets, thin tubes, hard-rail graphs, fans, closed cyclic orbits, and relation graphs;
- cross fields with controlled quarter-turn matching, cycle holonomy, singularity index, discontinuities, and tangent variation;
- valid and deliberately corrupted certificates;
- target-size fields near feasibility and tolerance boundaries.

Every failure logs a stable seed and serialized input. The shrinker minimizes faces/vertices/relations while preserving the documented precondition. Minimized counterexamples become named replay fixtures before the bug is considered contained. RapidCheck may be adopted only if it improves generation/shrinking without obscuring seed/corpus authority.

### 10.2 Metamorphic families

At minimum:

- source vertex/face row permutation;
- component and producer emission order;
- cyclic start rotation and route reversal with orientation inversion;
- thread/schedule and associative container order;
- rigid transform and uniform scale with correspondingly scaled target/tolerances;
- triangulation diagonal flips that preserve the source surface and field semantics;
- equivalent cross-field branch relabeling by quarter turns;
- target-size and geometry perturbation within a declared equivalence envelope;
- repeated calls, alternating success/failure sequences, and fresh-process replay.

Each relation states which output facts must remain equal, which may vary, and which must change.

### 10.3 Coverage-guided fuzzing

After structured generators are accepted, add Clang/libFuzzer targets for fast, reentrant stage boundaries:

- source/field deserialization and sanitization;
- source-support classification;
- transport composition/cycle verification;
- topology/certificate validation;
- occurrence/quotient relation ingestion;
- independent semantic verifier.

Use ASan/UBSan, valid and invalid seed corpora, per-target size/work limits, corpus minimization, and automatic reproducer preservation. The full production pipeline belongs in a bounded process-isolated corpus harness unless it becomes fast and reentrant enough for in-process fuzzing. Timeout, crash, sanitizer finding, unbounded work, or nondeterministic result is a failure; “did not crash” is never product correctness.

## 11. Gate and packaging policy

Every required test must be compiled and independently discovered in the immutable artifact. Labels distinguish meaning; build options do not hide mandatory authority.

| Label | Meaning |
|---|---|
| `contract-required` | accepted fast invariant; must remain green |
| `intent-smoke` | all ten committed direct cases; unresolved product cases remain explicit red evidence until fixed |
| `metamorphic` | representation/parameter equivalence |
| `oracle-mutation` | independent verifier sensitivity |
| `fuzz-replay` | committed minimized counterexamples |
| `corpus-nightly` | larger valid/invalid representative corpus |
| `quality-benchmark` | calibrated geometry/field/resource evidence |
| `historical-diagnostic` | retained history; never counted as current product proof |

Known-red intent tests are not disabled or reported as green. Their explicit status is separate from the required-green regression preservation gate. Promotion to required-green needs one accepted immutable Test + Benchmark result; demotion needs Review.

Artifact preflight must verify executable, exact discovered name, label, fixture/corpus checksum, seed/reproducer manifest, sanitizer mode when applicable, and metric schema. Aggregate pass counts cannot replace the named gate matrix.

## 12. Staged redesign and architecture integration

The already compiled multi-rail artifact remains the mandatory next Test + Benchmark turn. This review does not invalidate or replace it.

After M0 artifact closeout, testing and architecture migrate in interlocked slices:

| Test milestone | Scope | Exit evidence | Architecture/product dependency |
|---|---|---|---|
| `T0` audit and authority separation | this review; normative strategy separated from runtime history | audit, tracker, design, roadmap, TODO/milestone/handoff agree | complete now |
| `T1` independent oracle foundation | test-only topology/lineage/geometry primitives, mutation cases, labels/package manifest | compile-only Code + Build then immutable Test + Benchmark; mutations rejected | prerequisite to M1 |
| `T2` direct corpus and semantic manifest | all ten direct cases, declared preconditions, strict direct dispositions, explicit known-red reporting | discovery and named matrix evidence | before M2 behavior migration |
| `T3` metamorphic/property framework | generators, seed replay, shrinking, row/cycle/transform/sequence properties | at least one intentional mutation per property family; minimized replay | before M3/M4 acceptance |
| `T4` sanitizer fuzz and robustness | fast stage fuzz targets, ASan/UBSan, corpus minimization; process harness for full pipeline | bounded campaign plus zero unresolved findings and replay | before M5 closure |
| `T5` representative quality/corpus gates | calibrated metrics, hard invariants, stratified external corpus | approved thresholds/baselines and nightly evidence | before G6/G7 readiness |
| `T6` CI and adequacy hardening | default discovery, shard labels, oracle mutation adequacy, resource trends | no hidden mandatory tests; stable failure taxonomy | required for M6/G7 closure |

Each `Tn` implementation follows Code + Build then immutable Test + Benchmark. Code + Build may edit test/benchmark/CMake support and compile/package, but may not run generated binaries. Test + Benchmark may run only the exact artifact and may not edit test authority.

Do not pause all architecture work for a monolithic test rewrite. Accept T1 first, then require the relevant T2–T6 evidence before each dependent architecture/product milestone.

## 13. Immediate next-turn instructions

1. Run the already authorized artifact-only multi-rail Test + Benchmark plan against artifacts `9031804178 / 9031804382` unchanged.
2. Interpret its focused results under `RP-02` and `RP-09`; direct torus remains the representative authority.
3. Preserve or update `G4-R007` from runtime evidence; do not count this documentation review as a regression event.
4. After artifact closeout, the first mutating turn is **T1 independent test-oracle foundation — Code + Build**, not M1 production migration.
   Use `.agents/Directional/Test_Architecture_T1_Independent_Oracle_Foundation_Code_Build_Plan.md`.
5. T1 must be test/build-support only, behavior-preserving, separately packaged, and followed by an immutable Test + Benchmark turn.
6. M1 authority-kernel work may begin only after T1 acceptance and must consume the new test-authority format.

## 14. Review decision

**Changes required.** The suite has meaningful local coverage, but its current direct oracle, fixture gating, packaging split, and lack of generative/fuzz evidence are insufficient for the stated arbitrary-triangle-mesh to cross-field-aligned pure-quad product. `TA-01` through `TA-12` are open. Product or architecture completion cannot be claimed until their milestone-specific close conditions are met.

## 15. Primary references

1. Vaxman et al., [Directional Field Synthesis, Design, and Processing](https://avaxman.github.io/Directional/), 2016.
2. Bommes et al., [Mixed-Integer Quadrangulation](https://www.graphics.rwth-aachen.de/publication/0344/), 2009.
3. Ebke et al., [QEx](https://github.com/hcebke/libQEx), 2013.
4. Pietroni et al., [QuadWild / Reliable Feature-Line Driven Quad Remeshing](https://www.quadmesh.cloud/), 2021.
5. Jakob et al., [Instant Field-Aligned Meshes](https://rgl.epfl.ch/publications/Jakob2015Instant), 2015.
6. [LLVM libFuzzer documentation](https://llvm.org/docs/LibFuzzer.html).
7. [RapidCheck](https://github.com/emil-e/rapidcheck).
8. Zhou and Jacobson, [Thingi10K](https://arxiv.org/abs/1605.04797) and [dataset repository](https://github.com/Thingi10K/Thingi10K).
9. [libQEx reference-mesh tests](https://github.com/hcebke/libQEx/blob/517dcaa0cc87646baa89e52cfc8e23766776f6d5/tests/reference_meshes.cc).
10. [Geometry Central intrinsic-triangulation properties](https://github.com/nmwsharp/geometry-central/blob/019669ddabda05e0f71fa3587cfb3c1dadf19cb8/test/src/intrinsic_triangulation_test.cpp).
11. [CGAL remeshing tests](https://github.com/CGAL/cgal/blob/548fc90ea5d38402df679426283475ec78db0537/PMP_Remeshing/test/PMP_Remeshing/remeshing_test.cpp).
12. [Turn-Based Coding Agent Skill](https://github.com/akashskypatel/turn-based-coding-agent-skill).
