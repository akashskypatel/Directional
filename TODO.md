# Directional Surface-Cell TODO

Last updated: 2026-08-26 UTC

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

## Current focus — `M3-CP4c-0-TB-R4` — EXACT NEXT / artifact-only Test + Benchmark

`M3-CP4c-0-CB4` is **COMPLETE / BUILD GREEN** at semantic source
`de291a17d5e9bfb6f54918660320ecfa1d521be4`. Authoritative compile run/job
`32926004147 / 98048909565` produced immutable package `9591540182`
(`8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`), internal manifest
**27/27 PASS**, with `runtimeExecution=false`. The independent TB-R3 adjudication was followed exactly:
CB4 changed test/oracle/diagnostic code only; **no production source changed**.

- [x] `M3-CP4c-0-DEFN` — **COMPLETE.** Frozen definitions remain normative.
- [x] `M3-CP4c-0-CB1` — **COMPLETE / BUILD GREEN.** No runtime in CB.
- [x] `M3-CP4c-0-TB` — **COMPLETE / VALID RED.** 328/328 gate PASS; binding Q8 RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — **COMPLETE.** E0–E10 frozen; T6/Q8 unchanged.
- [x] `M3-CP4c-0-CB2` — **COMPLETE / BUILD GREEN.** Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — **COMPLETE / VALID SEMANTIC RED.** First red 329; Q8 not run.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — **COMPLETE.** Amendment 6; F0–F8 frozen.
- [x] `M3-CP4c-0-CB3` — **COMPLETE / BUILD GREEN.** Package `9589508430`.
- [x] `M3-CP4c-0-TB-R3` — **COMPLETE / VALID SEMANTIC RED.** 338 executed, 336 PASS; reds 333/334;
  F3 supplemental **2/2 PASS**; Q8 not run.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — **COMPLETE.** Both reds adjudicated **test-side**; Amendment 7;
  no production measure authorized; G0–G8 frozen.
- [x] `M3-CP4c-0-CB4` — **COMPLETE / BUILD GREEN.** G1 gives ordinal 333 a DCEL-valid witness;
  G2 rebuilds ordinal 334 on published `signedLift`; G3 adds local-holonomy coverage; G4 de-encodes the
  seed-provenance falsifier; G5 adds an always-publishing non-gating sphere A2a diagnostic; G6 records
  the per-face gauge premise; G7 records semantic/control/package/selector authority; G8 freezes TB-R4.
- [ ] `M3-CP4c-0-TB-R4` — **EXACT NEXT.** Consume package `9591540182` only. Execute the unchanged
  **338** selector in exact order/fresh processes with F6 continue-and-observe, then the two F3
  supplementals, then G5 non-gating diagnostic. Q8 is creditable only after exact integrity + 338/338 +
  F3 2/2. **P4 predicts Q8 RED** because TB-R3 proved the sphere still did not publish a network; preserve
  G5's rejection/outcome and route a red Q8 to review rather than repairing inside TB.
- [ ] `M3-CP4c-1` — **OPEN, blocked on CP4c-0.** C4/C5 stay gating; 318 selector untouched.
- [ ] `M3-CP4c-2-DEFN` — **BLOCKED.** Owns `DESIGN.md` §7.2 index-free closed-surface seam gap.
- [ ] `M3-CP4c-3-DEFN` — **BLOCKED.** Owns mechanical missing-adjacency localization.

Frozen selector authority remains **338** `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
accepted first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.
Q8 remains verbatim frozen and unconsumed. Latest accepted runtime remains CP4ab **316/316**. Stable
accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **43**.

## After M3 exit

`ROADMAP.md` §4 proposes the checkpoint decomposition for **M4–M8** — seventeen checkpoints plus five `-DEFN` planning turns to reach `M8-CP3`, the production-ready exit. That decomposition is a **proposal until each milestone's `-DEFN` turn freezes it**; gate arithmetic beyond 322 is deliberately not fixed.

## Carried forward from M2

- [ ] **3 latent fixture-authority sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options assert success but pass only because their complexes never reach boundary-ownership resolution; none are in the frozen selector.
- [ ] **Remove the `= {}` default** on the authority-consuming `complete_surface_cell_complex` overload (`PatchDescriptor.h:427`) so omission stops compiling.
- [ ] **Establish authority-carrying completion options as the local idiom.** `SurfaceCellComplexCompletionOptions` remains authority-unset by default across the affected tests.

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
- [ ] **M3 — field-aligned curve network.** CP4ab accepted at **316/316**; CP4c split into **CP4c-1 (318)**, **CP4c-2 (321)**, **CP4c-3 (322)**.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **42**. PR #8 remains open, draft, and unmerged.
