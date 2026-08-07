# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-07 UTC  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize `.agents/Directional/DESIGN.md` and the earliest incomplete/regressed high-level gate over local repair, diagnostics, cache/memory work, scheduling, performance, historical cleanup, or downstream machinery.

Before any code change, write:

```text
Active design gate:
Earliest failing fixture or contract:
Missing design/test contract:
Smallest general implementation change:
Observable material-progress/closure condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. New diagnostics, counters, hashes, equivalent failure movement, aggregate gains, performance work, fallback/recovery, or fixture-specific behavior are not material progress alone.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate when their following artifact-only runtime results are considered, the next turn must be a design review or bounded producer replacement proof.

This rule was previously triggered for Gate 1; the mandatory Review selected **Outcome B — bounded producer replacement proof**, which subsequently passed.

For current G3 accounting:

- the ring-correspondence Code + Build was runtime no-progress because artifact `9008118764` regressed to `InvalidPeriodicChart` cell 29;
- the endpoint-canonicalization Code + Build followed;
- artifact `9010838200` establishes decisive material progress: the exact cylinder is now direct deterministic strict-valid periodic `Produced / CompletedSurfaceCells` output with zero validation failures;
- therefore the no-progress counter resets to **0** and the mandatory Review stop rule is **not triggered**.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **production runtime closure contract satisfied; formal closure pending one incorrect unit-test witness correction**.
5. G4 topology/singularities — blocked until formal G3 closure.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory later observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Chart Endpoint Canonicalization artifact-only Test + Benchmark** turn is complete.

Authoritative report:

- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Report.md`.

## Exact tested authority

- source/test commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- base production checkpoint `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- artifact `9010838200` (`g3-periodic-chart-endpoint-canonicalization-code-build`);
- artifact SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- patch SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`;
- build run/job `31221873296 / 93007996817`;
- log artifact `9010837410`, SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- recursive checksums **44/44**;
- five executables, two project libraries, 27 fixture/input files;
- final blobs:
  - `SurfaceCellTracing.h` `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
  - `SurfaceCellTracing.cpp` `63e5ee427f675077f710db51ffb56d91838d3519`;
  - `SurfaceCellsPhase10Tests.cpp` `bef95b04c95c9a213c634e604d004b3d7d22646e`;
- build boundary `Release / Ninja / PRE_TEST / runtimeExecution=false`, build `111/111`;
- Test + Benchmark performed no configure, compile, relink, discovery regeneration, source/test/fixture/manifest/validator/benchmark/build edit, or replacement build.

A runtime-only `bin/test-data -> ../test-data` symlink exposed immutable packaged fixture paths. Packaged bytes were unchanged.

## Focused/retained contracts

Raw result: **16/17 passed**.

### Passed

- both endpoint-canonicalization contracts;
- typed `AmbiguousPeriodicRingCorrespondence` fail-closed contract;
- all six nominal G3 periodic contracts that had regressed in artifact `9008118764`;
- all seven retained G1/G2 contracts.

### Sole failure — incorrect expectation

`SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` reaches `Produced` and fails only:

```text
Expected: exactInterRingEdges > 0
Actual:   0
```

Classification: **incorrect expectation / invalid witness precondition**, not production implementation failure.

The test increments `exactInterRingEdges` only when a V-family phase-front edge has two distinct exact source-vertex endpoints. For its own fixture and target:

- source rings are at z `-1, -0.5, 0, 0.5, 1`;
- source inter-ring spacing is `0.5`;
- target size is `0.25`;
- production uses `gridV=8` and V step `0.25`;
- each source inter-ring edge is therefore represented by two V-family phase-front edges.

No one V edge can satisfy the test's exact-two-source-vertex witness even when the field-authoritative same-column correspondence is correct. The fixture remains structurally valid because it still creates the intended axial-vs-diagonal correspondence ambiguity.

The next test must observe subdivision-invariant source-attached V-family path geometry: reconstruct each nonzero V boundary-path segment in source space from face+barycentric provenance, compare it against the local authoritative V cross-field family, and require a nonempty observation set. The discarded diagonal mapping remains ~`37.9670987281°` off the axial family and must fail this semantic assertion.

Do not weaken the test to an existence-only check and do not change production merely to produce an un-subdivided edge.

## Direct runtime authority

| Fixture | Result | Producer | Traces | Quads | Validation | Output hash |
|---|---|---|---:|---:|---:|---|
| Plane | pass | `Produced` | 352 | 64 | 0 | `730caeae49ec872c` |
| Seam | pass | `Produced` | 256 | 64 | 0 | `5bdf34d7802e9fb0` |
| Close sheets | pass | `Produced` | 1,104 | 200 | 0 | `89b052762f52a5af` |
| Cylinder | **pass** | **`Produced`** | **1,728** | **288** | **0** | **`32135be51d7a0a26`** |
| Bunny | later gate | `NotApplicable` | 80,862 | 0 | — | none |
| Vase | later gate | bounded timeout | — | — | — | none |

Plane, seam, close sheets and cylinder are deterministic **3/3**. No active direct case uses fallback or source-grid recovery.

### Exact cylinder — production G3 closure contract satisfied

- producer `Produced`;
- output origin `CompletedSurfaceCells`;
- periodic holonomy available;
- quarter-turn rotation `0`;
- translation `(32,0)`;
- ordered holonomy route 32 edges;
- cut 4 edges;
- 1,728 traces;
- 290 arrangement / 290 simplified cells;
- 288 completed/output quads;
- 320 provenance/output vertices;
- zero non-quads;
- validation failures **0**;
- field P95 `8.537736463e-07°`;
- surface approximation P95 `2.832791574e-16`;
- zero nonmanifold edges, T-junctions, duplicate faces, self-intersections and degenerate faces;
- topology preserved and boundary preserved;
- output hash `32135be51d7a0a26` stable 3/3;
- no fallback attempt/use and no source-grid recovery.

The benchmark JSON does not serialize raw `normalP95Degrees` or `warpageP95Degrees`. `surfaceCellValidationFailures=0` authoritatively proves those existing scalar gates passed because production failure counting includes normal P95 <=15°, field P95 <=15°, warpage P95 <=30°, and the remaining strict criteria. Independent serialized-geometry cross-checks report warpage P95/max 0° and nearest-source normal P95 approximately `8.54e-7°`; these are supporting checks, not replacement validator authority.

Independent output-topology inspection finds exactly 64 boundary edges in two 32-edge degree-2 loops: one entirely at z=-1 and one at z=+1. The artificial periodic cut is therefore not an exterior seam. Provenance count equals output vertex count (`320 == 320`), and direct completed quad count equals output quad count (`288 == 288`).

This is material progress from artifact `9008118764`, where cylinder was `Rejected/InvalidPeriodicChart` at cell 29 with zero traces/completion/output. It also resolves the earlier source-strip artifact's `37.9670987281°` field-P95 defect to approximately zero.

## Default-suite evidence

- bounded producer excluding only long BunnyRandom/Vase parameter cases: **99/101**;
  - `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` — incorrect witness expectation described above;
  - `StrictValidatorOverheadStaysBelowFivePercent` — scheduler/environment-sensitive performance gate; repeated 5/5 failures in this environment, not functional G3 authority;
- completion/simplification: **154/164**, same historical ten failures;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded aggregate: **321/333**.

Bunny later-gate observation: `NotApplicable`, 80,862 traces, ~22.42 s, ~247.75 MB, no fallback/recovery. Vase produced no completed record in the bounded 45-second observation. Timeout is failure only, never correctness evidence.

Direct gate status outranks aggregate totals.

## Next authoritative turn

**Code + Build — G3 Field-Correspondence Test Witness.**

Execute:

- `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md`.

Before editing, write exactly:

```text
Active design gate: G3 periodic closure / holonomy — production runtime contract satisfied; formal closure pending test correction
Earliest failing contract: SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence
Missing test contract: field-authoritative adjacent-ring correspondence must be observed through source-attached V-family path geometry independent of target subdivision; a test may not require one un-subdivided phase-front edge to span two exact source-ring vertices
Smallest general change: replace the exactInterRingEdges witness with a subdivision-invariant check over nonzero V-family boundary-path segments reconstructed from face+barycentric source provenance, asserting alignment with the local authoritative V cross-field family while retaining a nonempty observation requirement
Observable closure condition: corrected field-correspondence test passes without production changes, the endpoint/ambiguity/periodic/G1/G2 contracts remain compiled unchanged, and the next exact artifact keeps cylinder direct deterministic strict-valid periodic CompletedSurfaceCells output
Explicitly deferred work: G4 topology/singularities, G5 adaptivity/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, and unrelated optimization
```

### Required implementation constraints

1. **Expected production source change: none.**
2. Keep the cylinder ambiguity fixture and `Produced` precondition.
3. Replace only the impossible `exactInterRingEdges` witness with source-attached V-family boundary-path/segment evidence.
4. For each qualifying nonzero V segment, require valid finite normalized source face+barycentric provenance, reconstruct source-space direction, compare to the local authoritative V field family, and use a justified numerical tolerance.
5. Require at least one qualifying V segment so empty evidence cannot pass.
6. Ignore only truly zero-length segments.
7. Preserve `PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed` unchanged.
8. Preserve endpoint canonicalization, annulus, cut/holonomy, source-strip, artificial-cut, malformed-holonomy and all G1/G2 contracts unchanged.
9. Do not assert historical `gridV`, output count, source vertex IDs, DCEL IDs, discovery order, or exact segment count.
10. Do not modify validators, thresholds, ring scoring, endpoint canonicalization, periodic quotient, fallback/recovery, or materialization merely to satisfy the test.
11. Code + Build only: configure/compile the seven approved targets with `PRE_TEST`; execute no generated project binary.
12. Package immutable artifact/log/checksum/source authority for the following artifact-only turn.
13. Remove temporary workflow/trigger/payload after verification; leave only the durable workflow.

### Following acceptance

The following artifact-only turn must first rerun the 17 focused/retained contracts and obtain **17/17**. Then revalidate plane/seam/close sheets/exact cylinder. If cylinder retains the direct deterministic strict-valid periodic output above with zero validation failures and no fallback/recovery, formally mark G3 passed and make G4 the active gate.

Optional Review is skipped; this plan is authoritative.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
9. `benchmark-results/design-aligned-runtime-summary.json`
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill plus relevant Code + Build, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not global lattice phase/connectivity.
- Exact production preprocessing is producer authority; reconstructed fixtures are not automatically execution-equivalent.
- Source-vertex crossings require ordered source-topology fans, never positional jumps or arbitrary subsets.
- `NotApplicable` and `Rejected` must remain distinct; authoritative `Rejected` cannot silently invoke another producer.
- Relief barriers become hard only when explicitly embedded.
- Plane proves bounded authoritative phase/front construction on a connected planar domain.
- Seam proves reciprocal cross-chart transport.
- Spatial proximity must never replace component/local-sheet authority; close sheets prove isolation.
- Periodic topology requires first-class holonomy; an artificial chart cut is not a real exterior boundary.
- Periodic seam identification uses exact source/phase/lattice authority, never Euclidean welding.
- Source-route provenance alone does not justify skipping mandatory source topological corners; canonical source-strip breakpoints are upstream authority.
- Multiple topology-compatible annulus-ring bijections are resolved by reciprocal cross-field transport authority, not IDs/order/count/frequency.
- Coverage tolerance may select chart ownership, but emitted geometry must be canonical source geometry; tolerance-expanded ownership bounds must not become geometric tails.
- Strict validator rejection of producer-emitted overlap is not a reason to weaken the validator.
- A behavioral unit-test witness must survive legitimate target subdivision; an un-subdivided exact-edge witness is invalid when the contract is source-attached field alignment.
- Correct invalid tests by preserving/strengthening their semantic contract, not by encoding current implementation output.
- Raw DCEL edge integers are incidental under face-row re-enumeration; compare canonical endpoint identity where renumbering is allowed.
- Compile-valid source is not runtime proof; exact artifact execution decides gate closure.
- Real bunny/vase fixtures remain mandatory later observations and may not be simplified/bypassed.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are closeout/performance evidence, not functional correctness.
- `PRE_TEST` preserves compile-only build boundaries.
- Timeout is failure only, never correctness evidence.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the start and end of every turn, inspect `.github/workflows` and all temporary triggers, transfer files, payload/patch directories, and generated artifacts.
2. Remove stale bounded/turn-specific workflows before work begins.
3. During remote compile, retain only approved durable workflows plus at most one bounded workflow and its exact payload.
4. After source/build/log/artifact verification, **remove or disable the bounded path-filtered workflow before deleting its trigger marker**, so cleanup cannot retrigger it.
5. Then remove the marker and payload.
6. Final branch state must contain only approved durable workflows and no stale generated artifact.
7. Do not remove a durable dependency consumed by an approved retained workflow.
8. Retain exact payloads until source commit, expected blobs, build authority and artifacts are verified; then remove them.

### Documentation and result cleanup

1. End every turn by removing stale/superseded plans, reports, closure notes, evidence indexes, and results from `.agents` and `benchmark-results`.
2. Retain only the live handoff, latest report(s) required for current runtime/build authority, next executable plan, current runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Retained documents may reference only files that exist.
4. Git history and PR conversation are the historical archive.
5. Never delete latest evidence or next-turn instructions before verified replacements exist.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly requests it.**
2. Handoff edits are additive or narrowly corrective by default; preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Compare handoff updates with the prior version and verify every pre-existing mandatory instruction remains materially present.
4. If a new instruction conflicts, preserve both and request user direction rather than deleting either.
5. Documentation cleanup never authorizes removal of mandatory handoff rules.

## End-of-turn requirement

Every completed turn ends with a new **top-level PR #8 comment** after all documentation and PR metadata updates. That comment is the **final repository write**.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
