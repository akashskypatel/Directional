# Surface-Cell Test-Suite Independent Audit and Redesign Plan

**Status:** authoritative testing-audit decision and staged redesign plan  
**Review type:** documentation-only independent Review  
**Inspected implementation authority:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Planning baseline:** `a3fba7dc83d9d5b77cdbd10794e3c460de526dbc`  
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8  
**Decision:** **redesign required; the current suite is a contributing part of the recurring-regression system, but it is not the sole cause**  
**Last updated:** 2026-08-12 UTC

> **Durable evidence-retention note:** this document is normative audit/redesign authority, not per-turn evidence. Current Test + Benchmark artifacts/results are retained only in the single current turn report plus durable live trackers. The mandatory cleanup policy in `.agents/Directional/Future_Chat_Session_Handoff.md` requires every Test + Benchmark turn to clean superseded checked-in evidence at start and replace it with current evidence at closeout. Historical per-turn report filenames below are provenance tied to cited commits and need not exist at the current branch head.

> **2026-08-11 architecture amendment:** The replacement `DESIGN.md` controls where this audit's earlier strict binary-outcome wording conflicts. Pipeline B is normative; Pipeline A is optional and unscheduled. The product now has verifier-assigned D0-D4 dispositions. Strict representative gates still require D0; D1-D3 require their own positive/tamper/metamorphic evidence and never count as strict success. New M3 owns `FieldAlignedCurveNetwork`; prior global-conformity M3 is revised M4; new M7 owns disposition and the declared degraded producer.

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

1. the direct acceptance oracle stops at pipeline disposition and face degree and cannot independently recompute the new D0-D4 tier;
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
| FlowRep | Parameter and field perturbations, global cycles/strands, systemic misalignment, and uneven sizing need robustness/metamorphic coverage; FlowRep is not a triangle-to-quad producer oracle. |
| Combinatorial tracing and motorcycle decomposition | Port ownership, typed termination, non-crossing, crash order, disc-region completeness, and the combined-algorithm preconditions need direct positive/tamper/metamorphic evidence. |
| QGP / minimum-deviation flow | Shared-rail positivity, feasibility, deterministic tie-breaking, solution validity, and polynomial work bounds need independent graph-level oracles. |
| Integer coordinates / intrinsic support | Exact-support operations require round-trip, degeneracy, row-permutation, and differential-oracle tests without tolerance-derived semantic keys. |
| Tutte and injective disk mappings | Fixed-boundary region embedding needs inversion/manifoldness evidence and later distortion/quality calibration. |
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
| L1 focused semantic | one relation with positive/negative witness | branch transport, hard-rail relation, source support |
| L2 metamorphic/property | representation changes cannot change semantics | row reorder, reversal, cycle rotation, rigid transform |
| L3 direct representative | public production entry and independent oracle | plane, seam, close sheets, cylinder, torus, sphere, feature, bunny, vase |
| L4 quality/corpus | geometry/field/quality/resource thresholds and corpus disposition | alignment, approximation, scaled Jacobian, RSS/work |

No lower layer may be used as a substitute for a required higher layer.

## 8. Fixture and corpus redesign

### 8.1 Versioned semantic manifest

Create `tests/fixtures/surface-cells/manifest.json` or an equivalent machine-readable manifest. Each case records:

- stable case ID and version;
- mesh/field paths and SHA-256;
- triangle-only input proof;
- components, boundary loops, Euler characteristic/genus, nonmanifold/degenerate flags;
- scale and target-size policy;
- field generator/source and field variation statistics;
- expected matching/holonomy/singularity/features at the semantic level;
- intended product contract and oracle thresholds;
- allowed terminal disposition during staged migration;
- tier (`pre-merge`, `nightly`, `fuzz-corpus`).

Tests validate the manifest before using a fixture. An incorrect fixture becomes a clear precondition failure rather than a misleading product regression.

### 8.2 Required committed matrix

The default direct matrix becomes the ten committed cases listed in section 3.3. A case may be an expected typed failure while the staged producer capability is incomplete, but the failure must be explicitly defined by the gate and cannot use fallback/recovery.

Use `bunny_1k_random.obj` as the irregular Bunny authority. Do not reintroduce an already-regularized bunny as the primary arbitrary-triangle proof.

### 8.3 Adversarial synthetic families

Generate bounded, deterministic families for:

- rotated/flipped row/vertex permutations;
- close disconnected sheets with variable gap;
- triangles with aspect ratio and minimum-angle ladders;
- small normal and vertex perturbations;
- branch/matching rotation and cycle start offsets;
- multiple topology regions and relation-chain shapes;
- fans of degree 2–12 with duplicate/wraparound sectors;
- hard-rail breakpoint counts, direction reversal, and multi-rail reachability;
- nonmanifold edge/vertex cases and degenerate triangles;
- disconnected components and orientation variants.

Generators must record seeds and provide deterministic shrinkers that reduce vertices/faces/relations while preserving the failing semantic precondition.

## 9. Independent product oracle

Create a test-only oracle module that consumes only:

```text
source mesh + prescribed/generated cross field + explicit feature constraints
candidate quad mesh + exported production lineage/certificates
```

It does not call producer validation to decide acceptance.

### 9.1 Exact/topological invariants

Gate on:

- non-empty pure quads for a success disposition;
- valid indices and finite vertices;
- manifold incidence where the contract requires it;
- connected components;
- boundary-loop count;
- Euler characteristic / genus;
- no duplicate faces/edges under canonical semantic identity;
- complete output vertex/face lineage;
- exact source-support containment;
- consumed certificate/quotient authority when exported;
- no fallback/recovery in strict direct mode.

### 9.2 Field and feature invariants

Independently recompute:

- output edge tangent alignment to the nearest valid cross-field branch on its source support;
- field transport consistency across source edges/cycles;
- hard-feature/boundary curve adherence;
- singularity/index compatibility where prescribed.

### 9.3 Geometric and quality metrics

Record and, after baseline calibration, gate:

- surface approximation distance normalized by source scale;
- field alignment angular error distributions;
- hard-feature distance/alignment error;
- scaled Jacobian;
- quad angle and aspect distributions;
- target edge-length/area deviation;
- irregular valence distribution;
- output-size expansion;
- time, RSS, and monotone work metrics.

Thresholds are calibrated from the manifest/reference corpus and research-guided quality targets. They are not guessed inside a failing turn.

## 10. Oracle mutation tests

For every independent oracle family, deliberately corrupt a valid candidate and prove rejection:

- rotate or randomize the field while keeping geometry fixed;
- move output vertices off the source surface;
- change one quad index to create duplicate/degenerate/nonmanifold incidence;
- delete or duplicate a face;
- cross-connect close sheets;
- corrupt a source-support tag;
- drop or alter a quotient/transport certificate;
- reverse a hard-rail path without inverse transport;
- perturb a feature vertex off the source feature.

These tests directly counter `TA-06`: an oracle that accepts the corruption is not independent enough to certify production.

## 11. Property-based and metamorphic tests

Introduce a C++ property layer such as RapidCheck or a small project-native deterministic generator/shrinker if dependency policy favors no new library.

Mandatory properties include:

1. face-row permutation preserves canonical product topology/lineage/quality within tolerance;
2. vertex-row permutation preserves semantics after canonical remap;
3. route reversal composes the exact inverse transport;
4. cycle start rotation preserves holonomy;
5. source-edge endpoint reversal preserves the same canonical edge identity;
6. per-component input permutation preserves independent component results;
7. 4-way cross-field branch relabeling preserves the geometric field;
8. orientation-preserving rigid transforms preserve topology and normalized quality;
9. scale plus proportional target-size scaling preserves normalized result metrics;
10. generated fan/cycle/relation graphs satisfy authority consumption exactly once.

Failed properties must emit seed, shrunk fixture/graph, and semantic diff.

## 12. Fuzzing

### 12.1 Targets

Add bounded libFuzzer-style targets for:

- `SurfacePoint` / exact source-support normalization;
- authority ID and legacy conversion boundaries;
- canonical route/grid automorphism operations;
- phase-front boundary/certificate validation;
- quotient relation materialization on small generated occurrence complexes;
- generated triangle-mesh + raw-field preconditions for the direct producer, with strict work budgets.

### 12.2 Sanitizers

Run fuzz/property/nightly targets under:

- ASan;
- UBSan;
- debug assertions;
- optional TSan only for thread-safe deterministic units, not as the first fuzz tier.

### 12.3 Corpus and replay

Commit only minimized, semantically labeled reproducers. CI replays them before random fuzz time. Record fuzzer binary SHA, seed/corpus version, sanitizer configuration, and timeout/work budget.

## 13. Repetition, sequence, work, and resource tests

Because `RP-04` and `RP-06` recurred, add both:

- **fresh-process repetition:** same case N times in isolated processes;
- **in-process sequence:** deterministic case permutations through one process.

Assert:

- semantic output hash equality or stable typed failure;
- no state leaked between cases;
- monotone global work ledger never exceeds the declared budget;
- candidate/state counts remain bounded by declared input-derived formulas;
- RSS and time stay within calibrated baseline bands at the appropriate CI tier.

Do not infer a leak from scheduler-sensitive sub-millisecond timings or from one environment. Resource baselines require repeated distributions and comparable machines.

## 14. Package and discovery authority

Every immutable Code + Build package gains a test-evidence manifest containing:

- implementation/source blob IDs;
- executable names and SHA-256;
- exact discovered test names/counts by tier;
- fixture/corpus manifest SHA and file hashes;
- generator/fuzzer version and seeds/corpus version;
- approved oracle module SHA;
- benchmark thresholds/baseline version;
- command-boundary metadata proving no runtime during Code + Build.

The following Test + Benchmark turn performs native discovery from the packaged executables, fails on zero selection or missing required tests, and records exact selected names.

## 15. Test + Benchmark result schema

A result report is insufficient if it says only “N/N passed.” Record per semantic case:

```text
case ID / fixture hash / field hash or generator seed
intended contract and proved precondition
selected test/oracle names
producer disposition / typed failure
pure-quad rate
components / boundaries / Euler / manifold facts
source-lineage/support/certificate facts
field/feature/geometric/quality metrics
semantic hash / deterministic comparison
elapsed / RSS / work ledger
pass/fail and exact reason
artifact/executable hashes
```

Known-red cases stay in the denominator and are classified explicitly; they are not converted to expected success or silently excluded.

## 16. Staged execution plan

This redesign is incremental and preserves turn separation.

### T0 — policy and manifest foundation

**Status:** complete by this review/documentation turn.

- `tests/TESTING_STRATEGY.md` is normative-only;
- this audit defines the redesign;
- reorientation and handoff gate feature expansion on T1.

### T1 — independent test-oracle foundation

**Status:** accepted; its durable facts are now represented in the live tracker/current report and immutable artifact history rather than retained stale per-turn reports.

Implemented the first independent oracle executable/library, topology/lineage/disposition checks, oracle mutation tests, exact package/discovery authority, and representative direct-path ordering.

### T2 — complete direct semantic matrix

**Status:** pending.

- versioned ten-case fixture manifest;
- prescribed topology/field cases in default direct authority;
- independent oracle on every case;
- direct failures classified by typed stage;
- every strict case declares expected D0; D1-D4 do not count as green;
- separate induced D1-D3 cases prove truthful certificate and omitted/degraded-region behavior.

### T3 — property/metamorphic layer

**Status:** pending.

- row/vertex/order/orientation/scale/field relabeling properties;
- curve-network port/trace/crash/decomposition and rail-flow properties;
- disposition tier/degraded-set/omitted-set invariance;
- seed recording and shrinking;
- replay corpus.

### T4 — fuzz/sanitizer layer

**Status:** pending.

- small authority/canonicalization/quotient fuzz targets;
- ASan/UBSan CI;
- minimized corpus replay.

### T5 — calibrated product-quality gates

**Status:** pending.

- independent field/feature/geometric/quality metrics;
- approved baselines/thresholds;
- calibrated D0/D1 boundary with mutation sensitivity;
- Bunny/Vase and prescribed cases promoted only when prerequisites are ready.

### T6 — hardening and default-on

**Status:** pending.

- CI tiers and resource distributions;
- full corpus/fuzz replay;
- no stale historical target as hidden coverage;
- retirement of representation-brittle tests after replacement evidence exists.

## 17. Acceptance gates

### T1 acceptance

Accepted and preserved through current M1 work. It must continue to provide exact package/discovery and independent topology/lineage/disposition authority.

### T2 acceptance

- all ten committed cases discovered in the default direct matrix;
- semantic fixture manifest validates;
- exact independent topology/lineage oracle runs for every case;
- no required case is omitted due to runtime or known-red state.

### T3 acceptance

- required metamorphic properties pass over declared seed set;
- at least one deliberate mutation per property is rejected;
- shrinker emits a smaller reproducer for a seeded failing mutation.

### T4 acceptance

- sanitizer builds clean on committed replay corpus;
- bounded fuzz campaign executes declared target set without uncontrolled work/memory;
- all prior minimized reproducers replay deterministically.

### T5 acceptance

- all required product metrics independently computed;
- thresholds/baselines versioned and approved;
- direct representative cases meet their declared gate rather than merely returning `success`.

### T6 acceptance

- pre-merge and nightly tiers are reproducible;
- repeated sequence/process tests meet deterministic/resource budgets;
- oracle mutation coverage remains effective;
- legacy representation-only coverage has documented replacement authority.

## 18. Stop conditions and anti-shortcuts

Stop and redesign the test rather than weakening it if:

- the fixture does not prove the intended precondition;
- the oracle imports the producer decision it is meant to verify;
- a raw ID, count, hash, or retention flag is serving as semantic identity;
- a quality threshold has no calibrated rationale;
- a generated failure cannot be reproduced from its seed;
- a property cannot be shrunk without losing the failing precondition;
- a required test is not actually discovered from the immutable package;
- the direct product remains red while only a focused helper is green.

Never use source-grid recovery, generic producer substitution, validator weakening, fixture-specific product branches, or synthetic output construction to close a strict direct SurfaceCells gate.

The separately declared M7 degraded producer is not a generic substitution and must be tested as its own bounded product. It may emit D2 only, cannot recurse or mutate upstream authority, and cannot close a strict gate.

## 19. Current ordering relative to architecture migration

Current ordering is:

1. T0 complete;
2. T1 independent oracle/package authority accepted;
3. M1 single-authority cutover closes while preserving T1;
4. revised M3 curve-network and M4 conformity work add their own L0-L4 evidence when selected by the Pipeline B product queue;
5. revised M7 cannot land until M6 verification exists and its D0-D4/degraded-producer evidence is complete;
6. T2–T6 expand representative semantic/corpus/fuzz/quality authority before later feature/default-on closure.

The live exact next turn is owned by `.agents/Directional/Future_Chat_Session_Handoff.md`, not this durable redesign document.

## 20. Research references

Primary/documented sources used for the domain-specific testing redesign:

1. [Directional Fields: A Survey](https://doi.org/10.1111/cgf.14285).
2. [Mixed-Integer Quadrangulation (MIQ)](https://libigl.github.io/tutorial/#global-seamless-integer-grid-parametrization).
3. [QEx: Robust Quad Mesh Extraction](https://www.graphics.rwth-aachen.de/publication/03300/) and [libQEx](https://github.com/hcebke/libQEx).
4. [QuadWild](https://github.com/nicopietroni/quadwild).
5. [Instant Field-Aligned Meshes](https://github.com/wjakob/instant-meshes).
6. [Thingi10K](https://ten-thousand-models.appspot.com/).
7. [LLVM libFuzzer](https://llvm.org/docs/LibFuzzer.html).
8. [RapidCheck](https://github.com/emil-e/rapidcheck).
9. [Geometry Central surface-mesh tests](https://github.com/nmwsharp/geometry-central/blob/master/test/src/surface_mesh_test.cpp).
10. [Geometry Central intrinsic-triangulation properties](https://github.com/nmwsharp/geometry-central/blob/019669ddabda05e0f71fa3587cfb3c1dadf19cb8/test/src/intrinsic_triangulation_test.cpp).
11. [CGAL remeshing tests](https://github.com/CGAL/cgal/blob/548fc90ea5d38402df679426283475ec78db0537/PMP_Remeshing/test/PMP_Remeshing/remeshing_test.cpp).
12. [Turn-Based Coding Agent Skill](https://github.com/akashskypatel/turn-based-coding-agent-skill).
