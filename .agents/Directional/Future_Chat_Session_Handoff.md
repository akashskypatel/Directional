# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-07 UTC  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize `.agents/Directional/DESIGN.md` over local repair activity and work on the earliest incomplete or regressed high-level gate. Diagnostics, taxonomies, cache/memory work, scheduling, performance, historical cleanup, or downstream repair machinery must not become the principal objective while an earlier constructive gate is red.

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

If two consecutive Code + Build turns do not materially advance the earliest active gate, the next turn must be a design review or bounded producer replacement proof.

This rule was triggered for Gate 1. The mandatory Review selected **Outcome B — bounded producer replacement proof**. That replacement was implemented, compile-verified, and artifact-tested successfully. A third isolated Gate 1 phase-transition predicate repair remains prohibited.

The current G3 Test + Benchmark turn establishes material progress: the source-strip breakpoint contract and canonical row-order identity are now runtime-consumed, source approximation improved substantially, and the next general structural ambiguity was isolated to field-authoritative adjacent-ring correspondence. The no-progress rule is not triggered.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active; periodic topology, cut/quotient, and source-strip conformity are proven, but adjacent-ring correspondence lacks cross-field authority**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Output Validation artifact-only Test + Benchmark** turn is complete.

Authoritative report: `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Report.md`.

### Exact artifact authority

- source commit: `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- artifact: `9004509871` (`g3-periodic-output-validation-code-build`);
- artifact SHA-256: `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- build run/job: `31204848178` / `92953250176`;
- detailed log artifact: `9004508508`, SHA-256 `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`;
- source patch SHA-256: `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- changed blobs:
  - `src/geometry/SurfaceCellTracing.cpp` → `9df9a9759c761293fef1278f97b82fbb0aee0600`;
  - `tests/SurfaceCellsPhase10Tests.cpp` → `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`;
- recursive checksums: **44/44 passed**;
- five executables, two project libraries, 27 fixture/input files;
- build command boundary recorded `runtimeExecution=false`;
- Test + Benchmark performed no configure/compile/relink and edited no source/test/fixture/manifest/validator/benchmark/build logic.

A runtime-only `bin/test-data -> ../test-data` symlink exposed immutable packaged fixture paths. Packaged bytes did not change.

## Focused and retained contracts

**13/13 passed.**

### G3 focused — 6/6

1. `PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
2. `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
3. `PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
4. `PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
5. `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

The row-order contract now passes by ordered canonical endpoint-key route/cut identity. The source-strip contract proves all genuine source boundary vertices are retained as exact phase-front boundary corners without fixture-count assertions.

### Retained G1/G2 — 7/7

Plane producer boundary, disconnected close-sheet partition, close-sheet row-order invariance, ordered source-vertex fan traversal, source-fan row-order invariance, duplicate transition fail-closed behavior, and relief-guidance embedding behavior all pass.

## Direct runtime authority

| Fixture | Result | Producer | Holonomy | Traces | Quads | Validation | Output |
|---|---|---|---|---:|---:|---:|---|
| Plane | **pass** | `Produced` | — | 352 | 64 | 0 | `CompletedSurfaceCells`, `730caeae49ec872c` |
| Seam | **pass** | `Produced` | — | 256 | 64 | 0 | `CompletedSurfaceCells`, `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | — | 1,104 | 200 | 0 | `CompletedSurfaceCells`, `89b052762f52a5af` |
| Cylinder | **fail / material progress** | `Produced` | `r=0, t=(32,0), route=32, cut=4` | 2,237 | 320 | **3** | withheld at completion validation |
| Bunny | later gate | `NotApplicable` | — | 80,862 | 0 | 0 | `NotProductionReady:completion` |
| Vase | later gate | bounded timeout | — | — | — | — | no completed result after 180 s |

No case uses fallback or source-grid recovery. Timeout is failure only, never correctness evidence.

### Cylinder exact validation authority

The exact cylinder remains authoritative periodic `Produced`, with zero generic arrangement cells, 320 direct completed cells/quads and 352 provenance vertices. It terminates at:

- `NotProductionReady:completion`;
- first invalid producer stage `completion/output-validation`;
- reason `AggregateCompletionValidationFailure`;
- output origin `None` because final output is correctly withheld.

Non-invasive inspection of the exact packaged process's in-memory `SurfaceFinalValidationReport` identifies exactly three failed scalar thresholds:

1. `normalP95Degrees = 16.627273436620403` > `15.0`;
2. `fieldP95Degrees = 37.96709872810172` > `15.0`;
3. `warpageP95Degrees = 30.621379281060747` > `30.0`.

The benchmark record itself still reports only aggregate validation failure. The individual fields above come from non-invasive observation of the exact packaged runtime; no source, validator, or packaged bytes were modified.

All represented discrete strict/source-authoritative topology, boundary-cycle, feature-rail, provenance, local-sheet, degeneracy, manifold, inversion, self-intersection, convexity, valence, Euler, component, duplicate and bow-tie checks pass. `strictValidationIssues` is empty.

### Source-strip correction comparison

Compared with artifact `9001168379`:

- translation `29 -> 32`;
- traces `2163 -> 2237`;
- direct quads `290 -> 320`;
- provenance vertices `319 -> 352`;
- validation failures `2 -> 3`;
- quad-to-source P95 `0.068328 -> 0.031281`;
- source-to-output P95 `0.104464 -> 0.008174`;
- field P95 `37.9670987281° -> 37.9670987281°` unchanged;
- normal P95 `15.76596° -> 16.62727°`;
- warpage P95 `29.33562° -> 30.62138°`.

The source-strip correction is therefore retained: it materially improves source coverage and its explicit regression passes. It does not solve cross-field alignment.

## Structural root cause — next G3 contract

The periodic chart derives canonical graph-distance rings. For each adjacent ring pair, the triangulated annulus strip contains both the intended same-column axial source edge and a diagonal source edge. The current topology-compatible candidate enumeration therefore produces two valid one-to-one ring correspondences.

Current production then:

1. collects all topology-compatible candidate source-vertex sequences;
2. sorts them lexicographically;
3. selects `valid.front()`.

On the committed cylinder this selects the diagonal/sheared candidate. Ring 0 starts at angular column `0°`; the selected next ring starts at `22.5°` instead of retaining the same column. The selected diagonal inter-ring source edge is exactly **37.96709872810172°** away from the axial cross-field family, matching the failed `fieldP95Degrees` value.

A non-invasive extraction of the exact completed checkpoint mesh independently confirms that high-error output edges move in both circumferential angle and axial `z`, rather than following the axial family.

This is a general ambiguity in triangulated annulus ring correspondence. Source vertex IDs and lexicographic ordering are incidental identities and cannot be ownership authority.

## Default-suite evidence

- focused/retained producer contracts: **13/13**;
- bounded producer remainder excluding the two long Bunny/Vase design-acceptance cases: **82/84**;
  - `StrictValidatorOverheadStaysBelowFivePercent` — scheduler-sensitive timing evidence;
  - exact cylinder direct design acceptance — active G3 failure;
- a full producer remainder attempt reached the long Bunny case but did not complete the Bunny/Vase pair within the bounded turn budget; do not synthesize an 82/86 result for this artifact;
- completion/simplification: **154/164** with the same ten historical failures;
- validation: **60/60**;
- compiled API: **8/8**.

Direct gate status outranks aggregate totals.

## Next authoritative turn

**Code + Build — G3 Periodic Ring Correspondence.**

Execute `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Plan.md`.

Before editing, write exactly:

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at completion/output-validation
Missing design contract: adjacent canonical annulus rings can admit multiple source-topologically valid bijections through a triangulated strip; the authoritative periodic chart must resolve that correspondence from reciprocal cross-field family/transport authority, not lexicographic source-vertex ordering
Smallest general implementation change: replace valid.front() ring-pair selection with a field-family-consistent reciprocal ring correspondence that preserves the existing annulus topology, cut, holonomy and source-strip breakpoints; accept exactly one field-consistent bijection and fail closed on zero or multiple authoritative candidates
Observable material-progress condition: the exact cylinder keeps periodic Produced authority but its inter-ring sides follow the axial field family rather than diagonal strip edges, eliminating the 37.967-degree field-P95 defect and allowing normal/warpage quality to move under their existing thresholds while plane, seam and close sheets remain unchanged regressions
Explicitly deferred work: G4 singularities/topology-distinct completion, torus/general genus, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production remediation, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization hardening
```

### Required implementation constraints

1. Preserve topology-derived annulus applicability, deterministic true boundaries/cut, first-class holonomy, periodic ownership, exact quotient, source-strip breakpoints, provenance, and one accepted cell → one quad.
2. Retain topology-compatible ring-pair candidate enumeration.
3. Evaluate each candidate through finalized cross-field family/sign plus reciprocal transition/branch authority over the complete ring.
4. Require a consistent inter-ring family and reciprocal orthogonal circumferential family.
5. Accept exactly one field-authoritative candidate.
6. If zero candidates qualify, fail closed with typed periodic authority.
7. If multiple candidates are genuinely field-equivalent, fail closed as ambiguity; do not tie-break using source IDs, lexicographic order, counts, frequency, fixture identity, arbitrary subsets, or proximity.
8. Preserve ordered source-edge provenance and canonical row-order invariance.
9. Do not regress source-strip conformity to a global periodic count.
10. Do not change validator thresholds or synthesize validation success.
11. Code + Build only: configure/compile seven approved targets with `PRE_TEST` or equivalent and execute no generated project binary.
12. Package exact immutable artifact/log/checksum authority for the following artifact-only turn.
13. Remove temporary workflow/trigger/payload after artifact verification.

### Following acceptance

G3 closes only if the next artifact proves exact cylinder is direct deterministic `Produced` `CompletedSurfaceCells` pure-quad output with zero validation failures, field P95 <= 15°, normal P95 <= 15°, warpage P95 <= 30°, correct periodic quotient/provenance, no false cut seam, no fallback/recovery, and G0–G2 green.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Plan.md`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
9. latest runtime summary
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Exact production preprocessing is part of producer authority; geometrically equivalent reconstructed fixtures are not necessarily execution-equivalent.
- Complete zero-turn and reciprocal quarter-turn metadata must share one exact transport contract.
- Source-vertex crossings require ordered source-topology fans, never positional jumps or arbitrary subsets.
- `NotApplicable` and `Rejected` must not be conflated.
- Authoritative rejection cannot be silently substituted by another internal producer.
- Typed first-rejection state is necessary authority but does not replace constructive success.
- Relief barriers become hard only when their embedded-authority flag says so.
- Plane proves the bounded authoritative phase/front on a connected planar domain.
- Seam proves reciprocal cross-chart transport.
- Spatial proximity must never substitute for source component/local-sheet identity; close sheets prove this at production runtime.
- Periodic topology requires explicit holonomy and cannot be represented by declaring an artificial chart cut to be a real boundary.
- Periodic seam identification must use exact source/phase/lattice authority, never Euclidean welding.
- The exact cylinder proves periodic `Produced` authority, source-strip conformity, and deterministic holonomy; the active defect is field-authoritative ring correspondence.
- Raw DCEL edge integers are incidental identities across independently enumerated meshes; compare canonical source-edge endpoint identity when row-order invariance explicitly permits canonical renumbering.
- Source-route provenance alone does not justify a straight direct output side skipping a mandatory source topological corner; periodic construction must retain canonical source-strip breakpoints upstream of materialization.
- Per-strip deterministic target subdivisions may legitimately change periodic lattice translation; historical grid counts are evidence, not required constants.
- Multiple source-topologically valid ring bijections must be resolved by reciprocal cross-field transport authority, not lexicographic vertex ordering or counts.
- Non-invasive exact-runtime inspection may identify which existing validation fields failed, but it does not authorize validator changes.
- Compile-valid source is not runtime proof; exact artifact execution decides gate closure.
- Real bunny/vase fixtures remain mandatory and may not be simplified or bypassed.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are closeout evidence, not functional correctness.
- `PRE_TEST` preserves compile-only boundaries.
- Timeout is failure only, never correctness evidence.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the start and end of every turn, inspect `.github/workflows` and all temporary triggers, transfer files, payload/patch directories, and generated artifacts.
2. Remove stale bounded or turn-specific workflows before work begins.
3. During remote compile, retain only approved durable workflows plus at most one bounded workflow and its exact payload.
4. After artifact/log verification, remove bounded workflows, triggers, and payloads.
5. Final branch state must contain only approved durable workflows and no stale generated artifact.
6. Do not remove a durable dependency consumed by an approved retained workflow.
7. Retain exact payloads until their source commit, expected blobs, and build authority are verified; then remove them.

### Documentation and result cleanup

1. End every turn by removing stale/superseded plans, reports, closure notes, evidence indexes, and results from `.agents` and `benchmark-results`.
2. Retain only the live handoff, latest report(s) needed for current authority, next executable plan, current runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Retained documents may reference only existing files.
4. Git history and PR conversation are the historical archive.
5. Never delete latest evidence or next-turn instructions before verified replacements exist.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly requests it.**
2. Handoff edits are additive or narrowly corrective by default; preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Compare handoff updates with the prior version and verify every pre-existing mandatory instruction remains materially present.
4. If a new instruction conflicts, preserve both and request user direction rather than deleting either.
5. Documentation cleanup never authorizes removal of mandatory handoff rules.

## End-of-turn requirement

Every completed turn ends with a new top-level PR #8 comment after all documentation and PR metadata updates. That comment is the **final repository write**.

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