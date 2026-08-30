# Directional Surface-Cell TODO

Last updated: 2026-08-30 UTC

## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Closed milestone/checkpoint history lives in `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, and `M3_CP4ab_Closure_Record.md`. Exact runtime evidence lives in `CHANGELOG.md`, the current retained turn report, and `Regression_Root_Cause_Tracker.md`. Normative architecture lives in `DESIGN.md`; the checkpoint map to production-ready lives in `ROADMAP.md`; migration ordering lives in `REORIENTATION_PLAN.md`.

**Do not re-accumulate per-checkpoint, per-retry, or per-partial narrative here.** A closed checkpoint gets one line in `ROADMAP.md` §1 and a closure record; it does not stay in this file.

## Turn workflow — changed 2026-08-25

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

**Non-gating diagnostic identities** TB executes and reports them, the
gate count excludes them, each carries a written rationale and an owning corrective measure.

## Current focus — `M3-CP4c-2-TB-X2-R10-EXEC` — immutable re-proof of CB9 package 67

`M3-CP4c-2-CB9` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**:
`Architecture_M3_CP4c2_CB9_Code_Build_Report.md`.

- semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` converts both stale Amendment-14 A2b consumers identified by R9-REV;
- AI1 independently re-derived every `arc.cutEdge` / `GlobalTopologyArcKind::Cut` / `cut_edges()` product consumer before editing: exactly two were stale, and no representation-level widening was required;
- AI2 now binds every derived Cut sub-arc and publishes fragment-reconciliation plus cut-edge-orbit diagnostics;
- AI3 uses the existing `NodeLocus` authority so only actual sub-arc source-vertex endpoints enter the `boundaryVertices` skip list;
- AI4 records ordinal 359 next to the semantic-digest rationale; AI5 stops helper fall-through after typed build failure;
- AI6/AH6 remains runtime-owned; AI8 exclusions remain untouched.

Compile-only run `33325344311` is green. Changed-owner prepackage job `99294371782` compiled `directional_surface_cell_producer_tests` **105/105**; authoritative package job `99294619815` built all eight standard targets through `agent-compile-reusable.yml`. Immutable package **67** is artifact `9736088354`, SHA-256 `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`, packaged source archive `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`, manifest **28/28 PASS**, GMP/GMPXX, `runtimeExecution=false`.

### R10 execution boundary

Exact next is **`M3-CP4c-2-TB-X2-R10-EXEC`** under
`Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Plan.md`.

- artifact-only; no rebuild, relink, repair, chmod, source/test/fixture/selector/package mutation, generated discovery, or benchmark;
- verify immutable package `9736088354` and frozen selector 365 authority first;
- run the three frozen non-gating identities once each;
- execute selector 365 from ordinal 1, one fresh process per identity, with the first-semantic-red hard stop;
- if ordinal 363 is reached, enable `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1` in that same process and preserve AI2 fragment/orbit rows;
- if 363-365 are all reached, publish AH6 ordinary-path versus saturation evidence;
- unconditional immutable postflight regardless of semantic outcome.

R10 is split: **R10-EXEC** owns runtime/raw evidence only; **R10-REV** owns diagnostics, regression/candidate disposition, tracker/report updates, and next-step planning. Do not perform R10-REV work inside EXEC.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **67**. `selected_r2_branch=NONE`; selector **365** remains frozen; CP4c-2 remains unaccepted and CP4c-3 blocked.

### Open CP4c-2 candidates

- [ ] `M3-CP4c2-TB-X2-R9-CAND-01` — corrective source is compile-green; closes only when ordinals **363, 364 and 365 are all green** in a valid run reaching 365.
- [ ] **Ordinals 364 and 365 have never run** — degree-four two-Cut/two-Trace rotation and saturation last resort.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — prescribed sphere: producer `RotationSystemInconsistent` plus independently non-cellular pre-cut graph; non-gating and unchanged.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — zero-node / zero-arc closed-surface cut-graph behavior; non-gating and unchanged.
- [ ] **AH6** — requires 363-365 all reached.

## Carried forward from M1

**Produced-witness debt — `G4-B002` → revised M4 (3).** A fourth reopens section 14 scheduling.
- [ ] Re-prove `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on a produced closed complex.
- [ ] Re-prove `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` through the torus pipeline.
- [ ] Re-prove `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority.

**Produced-witness debt — `G4-B003` → M5 (2).** A third reopens M5 scheduling.
- [ ] Re-prove `FullPeriodicRotationAndTranslationMaterialize` on produced nonzero-Z4 authority.
- [ ] Re-prove `TamperedFullPeriodicTransformIsRejected` on produced nonzero-Z4 authority.

**Criterion-5 disposition re-proof → M7.**
- [ ] Re-express M1 criterion 5 in disposition terms and re-run F1/F2/F3 under verifier-assigned `Certified`. M7 does not close until green.

## Deferred hygiene

- [ ] **Repair `.github/workflows/agent-turn-cleanup.yml` comment handling and trigger safety.** The workflow still deletes **all** PR conversation and inline review comments before its observer step, and creating `.agents/connector-triggers/turn-cleanup/manifest.txt` auto-triggers it. Run `32591251950 / 97075340976` demonstrated 27 conversation-comment deletions. User commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` explicitly superseded the old prohibition by requiring the manifest/workflow at every turn closeout. Until the workflow is repaired, preserve durable repository evidence before publishing the closeout manifest and treat PR comments as non-durable.

Inherited baseline-red / non-gating fixtures remain frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] `WU2A-TB-CAND-01`: successful-side-subdivision ownership-registry precondition.
- [ ] `WU2B-TB-CAND-01`: hard-rail region-copy valid front-boundary-authority precondition.
- [ ] `WU2B-TB-CAND-02`: side-repair rollback ownership-registry/domain-identity precondition.
- [ ] `WU2B-TB-CAND-03`: authoritative-cell-scope subdivision source-scope reconciliation.
- [ ] `WU2B-TB-CAND-04`: five simplification fixtures need independently proven removable/protected/healing preconditions.
- [ ] `WU2B-TB-CAND-05`: FlowRep mandatory-cycle witness needs `selectionSucceeded=true` before later-cycle evidence is creditable.
- [ ] `RA-REV-23-F3`: dispatch stitch-kind audit through an explicit classifier field rather than probe-name text; add a negative self-test.
- [ ] `RA-REV-22-F6`: remove non-falsifiable validation-used assertions or set them where each gate actually executes.
- [ ] `RA-TB6-H1`: repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Milestone status

Checkpoint decomposition, per-milestone acceptance mapping, and the path to production-ready are in **`ROADMAP.md`**. Summary only:

- [x] **M0** preserve evidence  ·  [x] **M1** single-authority cutover  ·  [x] **M2** closed stage products
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted. R9 re-proved **355/355**, passed 356-362, and exposed the first genuine CP4c-2 product defect at 363. CB9 implements both stale Cut-sub-arc consumer corrections and is BUILD GREEN on immutable package **67** (`9736088354`), but runtime is unadjudicated. Exact next is `M3-CP4c-2-TB-X2-R10-EXEC`; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 R10 re-proof:** CB9 corrects the ordinal-363 one-arc binding and silent `boundaryVertices` over-insertion; immutable runtime must now prove 363-365, AI2 fragment/orbit reconciliation, and AH6 without weakening the frozen gate.
- [ ] **Prescribed sphere A2a′ upstream error:** AF0 now publishes `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28`; review the exact rotation-system locus before any product fix.
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; downstream of A2b and not a CP4c witness collision.
- [ ] `G4-B002`: exact torus `InvalidHardRailPairing`; revised M4.
- [ ] `G4-B003`: nonzero periodic Z4 production; M5.
- [ ] `G4-B004`: positive multi-isolation quotient witness; M5/M6.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates.

## Design and calibration backlog

- [ ] Own the closed-rail cardinality contract once at the rail product boundary rather than re-guarding both closed representations at every consumer.
- [ ] Calibrate `T5` quality/resource thresholds from measured baselines before any milestone asserts a quality gate.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] **Audit every remaining `kBranchTopologyTolerance` comparison for dimensional coherence.**
  `direction_in_incident_vertex_sector` compares a Gram **determinant** — an area-squared quantity — to
  `1e-10`. After E2/E3 the surviving uses are admissibility guards only, but their scale is arbitrary and
  mesh-size dependent. Not a CP4c-0 measure; do not fold it into CB2.
- [ ] **Sweep for other tolerant-selector / exact-consumer seams.** CP4c-0 found the pattern three times
  in one subsystem (flow classification, vertex sector, cross-edge flow). The same audit is owed wherever
  an exact authority was introduced downstream of a `double` decision.

---

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **65**. PR #8 remains open, draft, and unmerged.
