# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-07 UTC  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize `.agents/Directional/DESIGN.md` and the earliest incomplete/regressed high-level gate over local repair activity. Diagnostics, counters, taxonomies, caching, scheduling, performance, historical cleanup and downstream repair machinery must not become the principal objective while an earlier constructive gate is red.

Before any Code + Build change, record exactly:

```text
Active design gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class design contract becomes live and consumed, or a general structural ambiguity is removed. New diagnostics, counters, hashes, equivalent failure movement, aggregate gains, performance work, fallback/recovery or fixture-specific behavior are not material progress alone.

### Mandatory no-progress stop rule

If **two consecutive Code + Build turns** fail to materially advance the earliest active gate after artifact-only runtime validation, the following turn must be a design review or bounded producer replacement proof.

G1 previously triggered this rule and used the bounded producer replacement outcome successfully. For current G3, the ring-correspondence Code + Build plus this artifact-only turn is the **first runtime-no-progress Code + Build result since the prior source-strip material-progress turn**. The rule is therefore not yet triggered. If the next endpoint-canonicalization Code + Build also fails its following artifact-only acceptance without material progress, the next turn after that must be the mandated review/replacement proof.

## Strict turn cadence

Use the turn-based coding-agent cadence exactly:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`

Do not combine turn types.

- **Code + Build:** source/tests/build logic may change; configure/compile/link approved targets; execute no generated Directional binary, test, benchmark, ctest discovery, CLI/GUI/help/list/runtime. Use `PRE_TEST` or equivalent.
- **Test + Benchmark:** execute only the exact immutable built artifact; no rebuild, relink, source/test/fixture/manifest/validator/benchmark/build edit.
- **Review:** independent design/implementation review; may alter the next action plan, not silently turn into a Code + Build or Test + Benchmark turn.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active; regression at periodic chart endpoint representation**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory later observations.
8. G7 hardening/default-on — blocked.

Earliest failing fixture: `cylinder__surface_cells` at `tracing/phase-front`, `Rejected/InvalidPeriodicChart`, cell 29.

## Just-completed turn

**G3 Periodic Ring Correspondence — artifact-only Test + Benchmark.**

Authoritative report:

- `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Report.md`

Exact tested authority:

- source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- artifact `9008118764`, `g3-periodic-ring-correspondence-code-build`;
- artifact SHA-256 `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- build run/job `31214404170 / 92984429773`;
- build log artifact `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- recursive checksums **44/44**;
- five executables, two project libraries, 27 fixture/input files;
- Release/Ninja/static/`PRE_TEST`, seven approved targets, build **111/111**;
- packaged pre-test command boundary `runtimeExecution=false`;
- no rebuild/relink/source/test/fixture/manifest/validator/build edit in the Test + Benchmark turn.

Final changed blobs in that artifact:

- `include/directional/geometry/SurfaceCellTracing.h` → `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `src/geometry/SurfaceCellTracing.cpp` → `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`;
- `tests/SurfaceCellsPhase10Tests.cpp` → `c4671ef674228d74b96e80499abbb6846bcdf3e3`.

## Runtime decision

**G3 does not close. Classification: regression / no-progress.**

Focused/retained producer contracts: **9/15**.

Passed:

- `PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`;
- `ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary` as a typed producer-boundary contract;
- all seven retained G1/G2 producer contracts.

Failed because the nominal periodic chart now rejects `InvalidPeriodicChart` before the intended assertion:

1. `PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
2. `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
3. `PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
4. `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`;
5. `PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
6. `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` because its valid precondition chart rejects first.

The typed ambiguity contract remains real authority. The exact-cylinder boundary test intentionally permits typed rejection and therefore does not override the failed nominal G3 contracts/direct acceptance.

## Direct fixture authority

| Fixture | Result | Producer | Traces | Direct quads | Output | Determinism |
|---|---|---:|---:|---:|---|---|
| plane | **pass** | `Produced` | 352 | 64 | 81 V / 64 Q, `730caeae49ec872c` | 3/3 |
| seam | **pass** | `Produced` | 256 | 64 | 81 V / 64 Q, `5bdf34d7802e9fb0` | 3/3 |
| close sheets | **pass** | `Produced` | 1,104 | 200 | 242 V / 200 Q / 2 comps, `89b052762f52a5af` | 3/3 |
| cylinder | **fail/regression** | `Rejected/InvalidPeriodicChart` | 0 | 0 | none, `NotProductionReady:tracing` | 3/3 |
| bunny | later gate | `NotApplicable` | 80,862 | 0 | `NotProductionReady:completion` | 1 bounded |
| vase | later gate | bounded timeout | — | — | 45 s timeout, failure only | 1 bounded |

Cylinder is stable 3/3 at:

- `surfaceCellFirstInvalidProducerStage = tracing/phase-front`;
- `surfaceCellFirstInvalidProducerReason = InvalidPeriodicChart`;
- `surfaceCellFirstInvalidProducerCell = 29`;
- no terminal holonomy, trace, arrangement, completion, provenance or output;
- no fallback or source-grid recovery;
- about 0.0116–0.0120 s/process.

This supersedes the previous artifact `9004509871` as latest executed runtime authority, even though it is a regression. That preceding artifact had reached periodic `Produced`, `r=0`, `t=(32,0)`, route 32, cut 4, 2,237 traces and 320 direct quads before completed quality validation failed.

## Important retained field-authority lesson

Do **not** restore the former lexicographic/diagonal adjacent-ring correspondence simply because it progressed farther.

Immutable fixture reconstruction confirms:

- the intended same-column source correspondence is axial/field-aligned;
- the competing diagonal mapping is shifted 22.5 degrees in angle and is exactly `37.9670987281°` away from the axial field family;
- that value matched the former cylinder field-P95 defect;
- genuinely field-equivalent candidates still fail closed with typed `AmbiguousPeriodicRingCorrespondence`.

The reciprocal field-authoritative correspondence direction remains correct.

## Exact structural root cause now

Independent numerical reconstruction from only the immutable packaged source and cylinder fixture reproduces the runtime's first rejected cell exactly at **29**.

The defect is in producer-emitted periodic chart endpoints:

1. `periodic_chart_segment()` uses approximately `1e-10` tolerance to classify triangle occupancy along a chart segment;
2. interval limits at the tolerance-expanded simplex boundary are emitted directly as barycentric geometry;
3. two adjacent boundary paths that mathematically share an exact source vertex can therefore acquire microscopic tails on the same source face;
4. at cell 29/source face 30 the reproduced tails are approximately `(-9.9999e-11,0)->(0,0)` and `(0,0)->(-1e-10,1e-10)` in barycentric 2D;
5. the unchanged `segments_intersect_beyond_shared_endpoint_2d()` correctly sees those emitted tails as overlap beyond an exact shared endpoint;
6. `validate_closed_boundary_paths()` rejects and the caller records `InvalidPeriodicChart` for cell 29.

Required architectural principle: **coverage tolerance may determine ownership, but emitted geometry must be canonical source-simplex geometry**.

Do not repair this by relaxing validator tolerance or ignoring small intersections.

## Suite evidence

- bounded producer: **91/99**; six periodic regressions + scheduler-sensitive timing + cylinder direct design acceptance fail;
- completion/simplification: **154/164**, same historical ten deferred failures;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded aggregate: **313/331**.

Bunny completed one bounded observation in 41.60769 s, peak working set 247,566,336 bytes, `NotApplicable`. Vase exceeded the 45-second bounded observation; timeout is failure only, never correctness evidence.

## Next authoritative turn

**Code + Build — G3 Periodic Chart Endpoint Canonicalization.**

Execute:

- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Plan.md`

Mandatory declaration:

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at tracing/phase-front, Rejected/InvalidPeriodicChart, cell 29
Missing design contract: tolerance-aware periodic chart clipping must emit canonical source-simplex endpoints so segments that meet at an exact source vertex or edge remain exactly shared in source geometry; clipping tolerance may decide triangle coverage but may not create geometric tails that the strict self-intersection validator sees as overlap
Smallest general implementation change: canonicalize and renormalize periodic_chart_segment barycentric interval endpoints onto exact simplex boundaries, remove any segment that becomes zero-length after canonicalization, and preserve exact shared breakpoint identity across consecutive chart intervals without weakening validate_closed_boundary_paths or its self-intersection predicate
Observable material-progress condition: the six currently regressed nominal G3 periodic contracts return to Produced/expected behavior, the field-authoritative correspondence contract reaches and passes its axial-family assertion, exact cylinder advances beyond cell 29 without losing field-authoritative correspondence, and G0-G2 remain green
Explicitly deferred work: completed-output normal/field/warpage remediation after phase-front authority is restored, G4 singularities/topology-distinct completion, G5 adaptive transitions/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization
```

### Code + Build requirements

- start from source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` plus current documentation-only branch head;
- preserve field-authoritative correspondence and typed ambiguity/invalid correspondence rejection;
- canonicalize/renormalize periodic chart endpoint barycentrics near exact simplex boundaries;
- preserve one exact shared breakpoint identity across consecutive intervals;
- remove zero-length/tolerance-only segments;
- retain rejection of real out-of-simplex geometry and real self-intersections;
- do not alter strict boundary/self-intersection validators to make the fixture pass;
- do not weaken the six currently failing G3 tests to accept `InvalidPeriodicChart`;
- compile the same seven approved targets with `PRE_TEST` unless a narrower set proves every modified translation unit;
- execute no generated Directional runtime;
- package exact source/patch/blob authority, binaries/libs/fixtures/logs/compile commands, `runtimeExecution=false`, recursive checksums and outer SHA.

## Workflow and repository hygiene — mandatory

Only `.github/workflows/agent-source-snapshot.yml` is approved as a durable workflow.

Temporary Code + Build workflows, trigger markers and payloads are allowed only for bounded remote execution. After verifying artifact/log/source authority:

1. remove/disable the bounded path-filtered workflow **before** deleting its trigger marker;
2. remove trigger/payload debris;
3. verify only durable `agent-source-snapshot.yml` remains;
4. verify temporary trigger/payload directories are absent.

Every workflow must emit detailed success/failure logs and always upload the log artifact.

## Documentation hygiene — mandatory

At every turn end:

- update this handoff, `TODO`, `MILESTONE_G_TODO.md`, latest runtime summary and any live design/remediation plan materially affected;
- retain the latest useful report and next action plan;
- remove superseded turn plans/reports when no longer needed, rather than accumulating stale contradictory instructions;
- ensure every retained reference exists.

## Mandatory instruction preservation

Do not silently drop process constraints from this handoff. Any future rewrite must preserve:

- strict turn separation;
- design-first/earliest-gate policy;
- material-progress definition;
- two-consecutive-Code+Build no-progress stop rule;
- exact artifact/source authority requirements;
- bounded workflow/log/artifact policy and cleanup ordering;
- docs cleanup/live handoff requirements;
- review policy `never`;
- PR #8 stays open/draft/unmerged;
- final top-level PR comment requirement;
- all prohibitions below.

## End-of-turn PR requirement

Every completed turn must add a **new top-level PR #8 Conversation comment after all other repository writes**. That comment is the final repository write of the turn. Perform no GitHub mutation after it.

## Prohibitions

- no validator weakening;
- no source-ID/count/order/frequency ownership selection;
- no arbitrary subset search;
- no fixture/ID special cases;
- no generic producer substitution after `Rejected`;
- no fallback/recovery substitution;
- no Euclidean/nearest-point periodic seam welding;
- no positional merging across unrelated sheets;
- no synthetic counters/Euler/topology correction;
- no post-hoc cycle decomposition/cell split/merge used as construction authority;
- no timeout-as-correctness.

## Current authoritative documents

Read in this order:

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Plan.md`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
9. `benchmark-results/design-aligned-runtime-summary.json`
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
