# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-08 UTC  
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
Earliest failing fixture/contract:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. Diagnostics, counters, hashes, equivalent failure movement, aggregate gains, performance work, fallback/recovery, or fixture-specific behavior are not material progress alone.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate when their following artifact-only runtime results are considered, the next turn must be a design review or bounded producer replacement proof.

This rule previously triggered for G1 and produced the successful bounded producer replacement. It is **not currently triggered**: artifact `9010838200` established material G3 progress and satisfied the production runtime closure contract, resetting the no-progress counter.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **production runtime closure contract satisfied; formal closure pending corrected field-correspondence witness artifact validation**.
5. G4 topology/singularities — blocked until formal G3 closure.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory later observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Field-Correspondence Test Witness Code + Build** turn is complete.

Authoritative report:

- `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Report.md`.

### Exact test-only source authority

Evidence commit:

- `117620ec2da2083ce11b205835e58fa404f163ef` — `test(surface-cells): make field witness subdivision invariant`.

Patch:

- SHA-256 `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`.

Blobs:

- `tests/SurfaceCellsPhase10Tests.cpp` → `80a0b58339102279ab863d9112e243a557cd270d`;
- `src/geometry/SurfaceCellTracing.cpp` → unchanged `63e5ee427f675077f710db51ffb56d91838d3519`;
- `include/directional/geometry/SurfaceCellTracing.h` → unchanged `c1b816a584d67a3f74c2d7389962bd92d52244c9`.

Only the Phase10 test file changed. Production source remains byte-identical to runtime-proven source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

### Corrected field witness

The previous test required a single V front edge whose endpoints were two exact source-ring vertices. That witness is structurally absent when target size 0.25 subdivides the cylinder's 0.5 source inter-ring spacing.

The corrected test instead:

1. iterates authoritative phase-front cell `boundaryPaths`;
2. observes only source-attached `family == 1` segments;
3. requires valid source face and finite normalized barycentric endpoints inside the source simplex;
4. reconstructs source-space segment endpoints from `(face, barycentric)` provenance;
5. ignores only genuine zero-length segments;
6. tangentially compares each reconstructed segment with local `faceAxisY`;
7. requires absolute alignment with the authoritative V field family within `1e-10`;
8. requires a nonempty observed V-segment set.

This preserves semantic field authority while removing dependence on target subdivision. It does not use fixture counts, source IDs, output counts, order/frequency, fallback, or production special cases.

### Compile-only artifact authority

- workflow run/job `31228899303 / 93028533210`;
- artifact `9013161456` (`g3-field-correspondence-test-witness-code-build`);
- artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- detailed log artifact `9013161584`, SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f`;
- recursive checksums **44/44**;
- compile/link **111/111**;
- seven approved targets;
- five executables, two project libraries, 27 fixture/input files;
- Release / Ninja;
- project tests/benchmarks were enabled with `DIRECTIONAL_BUILD_TESTS=ON` and `DIRECTIONAL_BUILD_BENCHMARKS=ON`; no generated test discovery command was run during build;
- packaged `runtimeExecution=false`;
- generated Directional binary/test/benchmark/CLI/GUI/help/list/discovery execution: **none**.

Three earlier temporary remote attempts failed only in workflow/build-evidence setup (invalid workflow expression, wrong project build-option names, insufficient exact-source fetch depth). They produced no authoritative build artifact and executed no generated Directional binary. The successful run above is the only build authority for this turn.

## Current executed runtime authority

Artifact `9010838200`, production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, remains runtime authority until artifact `9013161456` executes.

It already proves the production G3 closure contract:

- plane: direct strict-valid `Produced`, 81 V / 64 quads, hash `730caeae49ec872c`, deterministic 3/3;
- seam: direct strict-valid `Produced`, 81 V / 64 quads, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets: direct strict-valid `Produced`, 242 V / 200 quads / two isolated components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder: direct `Produced / CompletedSurfaceCells`;
- cylinder holonomy `r=0`, `t=(32,0)`, route 32, cut 4;
- 1,728 traces, 290 arrangement/simplified cells, 288 pure completed/output quads, 320 output/provenance vertices;
- validation failures **0**;
- field P95 approximately `8.54e-7°`;
- exactly two genuine 32-edge annulus exterior loops; artificial cut not exterior;
- output hash `32135be51d7a0a26`, deterministic 3/3;
- no fallback or source-grid recovery.

The preceding focused/retained result was **16/17**. Both endpoint-canonicalization tests, typed ambiguity, all six retained G3 periodic contracts, and all seven G1/G2 contracts passed. The only failure was the subdivision-dependent field witness corrected by this Code + Build.

## Next authoritative turn

**Artifact-only Test + Benchmark — G3 corrected field-correspondence witness.**

Execute:

- `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md`.

Exact artifact authority:

- artifact ID `9013161456`;
- SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- evidence source `117620ec2da2083ce11b205835e58fa404f163ef`;
- runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- test-only patch SHA-256 `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`;
- log artifact `9013161584`, SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f`;
- expected recursive checksums **44/44**.

### Test + Benchmark boundary

1. Do not configure, compile, relink, regenerate discovery, or edit source/tests/fixtures/manifests/validators/benchmarks/build logic.
2. A runtime-only symlink may expose immutable packaged fixture paths; record it and do not alter packaged bytes.
3. Verify artifact digest, 44/44 checksums, source/patch/blobs, five executables, two libraries, 27 fixtures, build logs and `runtimeExecution=false` before runtime.
4. If integrity fails, classify infrastructure invalid and stop; do not build a replacement artifact.
5. Run the corrected field witness first.
6. Run the complete retained focused set and require **17/17**.
7. Revalidate plane, seam, close sheets, then exact cylinder.
8. G3 formally closes only if cylinder retains direct deterministic strict-valid periodic `CompletedSurfaceCells`, zero validation failures, valid field/holonomy/cut/quotient/provenance, existing quality thresholds, and no fallback/recovery while G0-G2 remain green.
9. Run independent-process determinism and default suites after the direct decision.
10. Bunny/vase remain later-gate observations only.
11. Timeout is failure only, never correctness evidence.
12. If all G3 closure conditions pass, update design/TODO/handoff to **G3 passed** and activate **G4 topology-distinct completion and singularities** with one next Code + Build plan.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Report.md`
- `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Report.md`
7. `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `benchmark-results/design-aligned-runtime-summary.json`
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. the turn-based coding-agent skill and relevant Test + Benchmark, testing-integrity, recovery, handoff, connector-workflow and unit-testing references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not global lattice phase/connectivity.
- Exact production preprocessing is producer authority; reconstructed fixtures are not automatically execution-equivalent.
- Source-vertex crossings require ordered source-topology fans, never positional jumps or arbitrary subsets.
- `NotApplicable` and `Rejected` remain distinct; authoritative `Rejected` cannot silently invoke another producer.
- Spatial proximity never replaces component/local-sheet authority.
- Periodic topology requires first-class holonomy; an artificial chart cut is not a real exterior boundary.
- Periodic seam identification uses exact source/phase/lattice authority, never Euclidean welding.
- Canonical source-strip breakpoints are upstream authority.
- Multiple topology-compatible annulus-ring bijections are resolved by reciprocal cross-field transport authority, not IDs/order/count/frequency.
- Coverage tolerance may select chart ownership, but emitted geometry must be canonical source geometry.
- Strict validator rejection is not a reason to weaken the validator.
- A regression witness must remain valid under legitimate target subdivision; source-attached face+barycentric paths are the correct subdivision-independent evidence here.
- Compile-valid source is not runtime proof; exact artifact execution decides gate closure.
- Real bunny/vase fixtures remain mandatory later observations and may not be simplified/bypassed.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are performance evidence, not functional correctness.
- Compile-only builds must use the repository's actual `DIRECTIONAL_BUILD_TESTS` / `DIRECTIONAL_BUILD_BENCHMARKS` options and must not execute generated test discovery or project binaries.
- Exact-source packaging that requires the parent commit must fetch enough history for that parent.
- Timeout is failure only.

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
