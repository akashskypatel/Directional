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
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. New diagnostics, counters, hashes, equivalent failure movement, aggregate gains, performance work, fallback/recovery, or fixture-specific behavior are not material progress alone.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate when their following artifact-only runtime results are considered, the next turn must be a design review or bounded producer replacement proof.

This rule was previously triggered for Gate 1; the mandatory Review selected **Outcome B — bounded producer replacement proof**, which subsequently passed.

For current G3 accounting:

- the source-strip turn established material progress;
- the subsequent ring-correspondence Code + Build was classified **runtime no-progress** by artifact `9008118764` because cylinder regressed to `InvalidPeriodicChart` cell 29;
- the just-completed endpoint-canonicalization Code + Build is compile-valid but not yet runtime-tested;
- **if artifact `9010838200` also produces no material G3 progress, the turn immediately after that Test + Benchmark must be the mandated design review or bounded producer replacement proof. Do not take another ordinary isolated Code + Build turn.**

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active; field-authoritative correspondence retained, endpoint-canonicalization correction compile-valid, artifact runtime validation pending**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory later observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Chart Endpoint Canonicalization Code + Build** turn is complete.

Authoritative report:

- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Report.md`.

### Design declaration used

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at tracing/phase-front, Rejected/InvalidPeriodicChart, cell 29
Missing design contract: tolerance-aware periodic chart clipping must emit canonical source-simplex endpoints so segments that meet at an exact source vertex or edge remain exactly shared in source geometry; clipping tolerance may decide triangle coverage but may not create geometric tails that the strict self-intersection validator sees as overlap
Smallest general implementation change: canonicalize and renormalize periodic_chart_segment barycentric interval endpoints onto exact simplex boundaries, remove any segment that becomes zero-length after canonicalization, and preserve exact shared breakpoint identity across consecutive chart intervals without weakening validate_closed_boundary_paths or its self-intersection predicate
Observable material-progress condition: the six currently regressed nominal G3 periodic contracts return to Produced/expected behavior, the field-authoritative correspondence contract reaches and passes its axial-family assertion, exact cylinder advances beyond cell 29 without losing field-authoritative correspondence, and G0-G2 remain green
Explicitly deferred work: completed-output normal/field/warpage remediation after phase-front authority is restored, G4 singularities/topology-distinct completion, G5 adaptive transitions/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization
```

## Latest executed runtime authority — unchanged by Code + Build

Artifact `9008118764`, source/test `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`:

- focused/retained producer contracts **9/15**;
- plane `Produced`, 352 traces, 81 V / 64 strict-valid quads, hash `730caeae49ec872c`, deterministic 3/3;
- seam `Produced`, 256 traces, 81 V / 64 strict-valid quads, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets `Produced`, 1,104 traces, 242 V / 200 strict-valid quads / two isolated components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder **`Rejected/InvalidPeriodicChart`**, `tracing/phase-front`, cell 29, zero traces/arrangement/completion/output, no terminal holonomy, deterministic 3/3, no fallback/recovery;
- bunny later-gate `NotApplicable`, 80,862 traces in one bounded run;
- vase later-gate bounded timeout; timeout is failure only.

Six nominal G3 periodic contracts regress because the valid field-aligned chart rejects before their intended assertions. All seven retained G1/G2 contracts and the typed genuinely ambiguous ring-correspondence contract pass.

### Why the field-authoritative correspondence must remain

Do not restore the prior diagonal/lexicographic adjacent-ring mapping merely because it progressed farther. Immutable reconstruction proves:

- the intended same-column correspondence is axial;
- the discarded diagonal mapping is exactly `37.9670987281°` from the axial field;
- that angle matched the prior field-P95 failure.

## Reproduced endpoint defect

Artifact `9008118764` was independently reconstructed from immutable packaged source/fixtures. The first rejection reproduces at **cell 29**.

The old `periodic_chart_segment()` behavior used approximately `1e-10` tolerance both to decide source-triangle coverage and to define emitted interval endpoints. At cell 29, two sides that mathematically share one source vertex therefore acquire microscopic source-face tails near the tolerance boundary. The unchanged strict `segments_intersect_beyond_shared_endpoint_2d()` correctly recognizes overlap beyond a shared endpoint and `validate_closed_boundary_paths()` rejects the cell.

Therefore the repair target is producer endpoint representation, not validator tolerance.

## Compile-valid endpoint-canonicalization implementation

Final source/test commit:

- `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

Patch:

- SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`.

Final blobs:

- `include/directional/geometry/SurfaceCellTracing.h` → unchanged `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `src/geometry/SurfaceCellTracing.cpp` → `63e5ee427f675077f710db51ffb56d91838d3519`;
- `tests/SurfaceCellsPhase10Tests.cpp` → `bef95b04c95c9a213c634e604d004b3d7d22646e`.

### Constructive correction

1. The existing chart tolerance remains triangle-coverage/ownership evidence only.
2. Emitted chart breakpoints come from exact zero-barycentric simplex crossings, not `-tolerance` expanded bounds.
3. Periodic lattice-point and segment-endpoint barycentrics share a canonicalization helper.
4. Finite values materially outside the simplex reject.
5. In-tolerance coordinates snap exactly to `0` / `1`.
6. Source-vertex endpoints become exact one-hot barycentrics.
7. Remaining valid barycentrics are renormalized while preserving exact zero coordinates.
8. Segments collapsing after canonicalization are omitted instead of emitted as tolerance-only tails.
9. Same-face merging preserves canonical endpoints.
10. Strict closed-boundary/self-intersection validator code and thresholds are unchanged.

Preserved: reciprocal field-authoritative ring correspondence, typed `InvalidPeriodicRingCorrespondence` / `AmbiguousPeriodicRingCorrespondence`, annulus applicability, deterministic cut, first-class holonomy, source-strip breakpoints/subdivisions, artificial-cut ownership/exact quotient, provenance, one accepted cell → one quad, G0-G2 and no fallback/recovery.

### New compile-only regression source

- `SurfaceCellsPhase10.PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints` — requires exact simplex endpoints, exact shared source breakpoints, no tolerance-only segments and unchanged strict boundary validation acceptance on the cylinder phase front.
- `SurfaceCellsPhase10.PeriodicChartEndpointCanonicalizationKeepsGenuineOverlapRejected` — allows a true shared endpoint but requires real collinear overlap beyond it to remain rejected.

These tests were **compiled only; not executed**.

## Compile-only authority

- workflow run/job `31221873296 / 93007996817`;
- source commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- artifact `9010838200` (`g3-periodic-chart-endpoint-canonicalization-code-build`);
- artifact SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- detailed log artifact `9010837410`, SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- recursive checksums **44/44**;
- compile/link **111/111**;
- approved targets **7/7**;
- five executables, two project libraries, 27 fixture/input files;
- GNU C++ 13.3.0 / CMake 3.31.6 / Ninja / Release static / `PRE_TEST`;
- packaged command boundary `runtimeExecution=false`;
- generated Directional binary/test/benchmark/CLI/GUI/help/list/discovery execution: **none**.

Cylinder fixture hashes in the artifact:

- `cylinder.obj` `59ed6d736410dbef6bc751136ba0eb1d557a43c9df63fb2a570daf85c79419ae`;
- `cylinder.rawfield` `6e861e06fa5d3dd6ed84c48bf7d459df701acd7f6ab241cc2adbde66d829084d`.

## Next authoritative turn

**Artifact-only Test + Benchmark — G3 Periodic Chart Endpoint Canonicalization.**

Execute:

- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Plan.md`.

Exact artifact authority:

- artifact ID `9010838200`;
- SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- patch SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`;
- log artifact `9010837410`, SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- expected checksums **44/44**.

### Test + Benchmark boundary

1. Do not configure, compile, relink, regenerate discovery, or edit source/tests/fixtures/manifests/validators/benchmark/build logic.
2. A runtime-only symlink may expose immutable packaged fixture paths; record it and do not alter packaged bytes.
3. Verify artifact digest, 44/44 checksums, source/patch/blobs, five executables, two libraries, 27 fixtures, build logs and `runtimeExecution=false` before runtime.
4. If integrity fails, classify infrastructure invalid and stop; do not build a replacement artifact.
5. Run **17 focused/retained contracts first**: the two new endpoint tests, field-authoritative/typed-ambiguity tests, six retained G3 periodic tests, and seven retained G1/G2 tests.
6. Revalidate plane, seam, close sheets, then exact cylinder.
7. Material progress requires all six nominal G3 periodic regressions restored and cylinder advancing beyond cell 29 with field authority and G0-G2 intact.
8. `Rejected` must not fall through to generic substitution; fallback/recovery remain disabled.
9. G3 closes only with direct deterministic strict-valid periodic `CompletedSurfaceCells`, zero validation failures, field/normal P95 <= 15°, warpage P95 <= 30°, exact cut/holonomy/quotient/provenance and no false exterior cut seam.
10. Historical translation/grid/output/provenance counts are not acceptance constants.
11. Run independent-process determinism and default suites after the direct gate decision.
12. Bunny/vase remain later-gate observations only.
13. Timeout is failure only, never correctness evidence.
14. If the artifact is again no-progress, the **next turn must be the mandatory design review or bounded producer replacement proof**.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Report.md`
- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Report.md`
7. `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `benchmark-results/design-aligned-runtime-summary.json`
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. the turn-based coding-agent skill and the relevant turn/testing-integrity/recovery/handoff/connector-workflow/unit-testing references.

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
