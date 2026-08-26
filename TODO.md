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

## Current focus — `M3-CP4c-0-TB-R6` — EXACT NEXT / artifact-only Test + Benchmark

`M3-CP4c-0-CB6` is **COMPLETE / BUILD GREEN** at semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`. Authoritative compile-only run/job `33002848081 / 98288918300` produced immutable package artifact `9619352525` with GitHub ZIP SHA-256 `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672` and packaged source archive SHA-256 `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093`; compile-log artifact `9619353059` has ZIP SHA-256 `1b2a0ffc9889305ca6a2efa847a2442c941583df01ad94c4c12226aea47be4c4`. Preflight and build both exited `0`, all eight standard targets compiled/linked, every packaged source-status snapshot is empty, and the package explicitly records `runtimeExecution=false` / `turnBoundary=Code+Build-only`. No Directional test, benchmark, or generated runtime executed.

CB6 implements only the review-authorized diagnostic J-series: J1 decomposes H1 violations into `matching`, source/target raw gauges, published lift, singular incidence, and distinct counts; J2 explicitly classifies the synthetic four-triangle fan as excluded fixture artifact; J3 adds the independent matching-versus-geometry census; J4 publishes matching provenance; J5 pins staged payload bytes against line-ending conversion; J6 restores brief/review naming; J7 freezes the successor TB-R6 plan. **J0's no-production-semantics-change boundary is preserved.** Frozen selector authority remains unchanged.

- [x] `M3-CP4c-0-DEFN` — COMPLETE.
- [x] `M3-CP4c-0-CB1` — COMPLETE / BUILD GREEN.
- [x] `M3-CP4c-0-TB` — COMPLETE / VALID RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB2` — COMPLETE / BUILD GREEN. Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — COMPLETE / VALID SEMANTIC RED.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB3` — COMPLETE / BUILD GREEN. Package `9589508430`.
- [x] `M3-CP4c-0-TB-R3` — COMPLETE / VALID SEMANTIC RED. 336/338; F3 2/2.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — COMPLETE. Both reds test-side; Amendment 7; G0–G8.
- [x] `M3-CP4c-0-CB4` — COMPLETE / BUILD GREEN. Package `9591540182`; test-side corrections only.
- [x] `M3-CP4c-0-TB-R4` — COMPLETE / VALID SEMANTIC RED. **338/338 PASS**, F3 **2/2 PASS**, G5 PASS/non-gating; Q8 CREDITABLE / RED because the sphere does not publish a network.
- [x] `M3-CP4c-0-TB-R4-REVIEW-PLAN` — COMPLETE. Symptom proved; mechanism reduced to H-A/H-B/H-C; H0–H7 frozen.
- [x] `M3-CP4c-0-CB5` — **COMPLETE / BUILD GREEN.** H1 A1-only census identity, H2 published `signedLift`, H3 ordered trace-step history, H4 matching-provenance audit; H5 no-production-change boundary preserved. Package `9601160869`.
- [x] `M3-CP4c-0-TB-R5` — **COMPLETE / VALID SEMANTIC RED.** Frozen 338/338, F3 2/2, G5 PASS/non-gating; H1 `390/4224`, `H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED`; Q8 CREDITABLE / RED at criterion 2.
- [x] `M3-CP4c-0-TB-R5-REVIEW-PLAN` — **COMPLETE.** H1 mechanism valid; fan contribution proved fixture artifact; H-A/H-C excluded; H-B undecided; Amendment 8; J0–J7 frozen. Record: `Architecture_M3_CP4c0_TB_R5_Review_Plan_Independent_Review.md`.
- [x] `M3-CP4c-0-CB6` — **COMPLETE / BUILD GREEN.** Diagnostic-only J0–J7; semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`; package `9619352525` (`b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672`); compile-only run/job `33002848081 / 98288918300`.
- [ ] `M3-CP4c-0-TB-R6` — **EXACT NEXT.** Consume only CB6 package `9619352525`; execute unchanged 338 gate, F3, G5, decomposed H1, and J3; Q8 is conditional and **expected to remain RED at criterion 2**. Fill the frozen J1/J3 owner decision table. No rebuild or repair.
- [ ] `M3-CP4c-1` — OPEN, blocked on CP4c-0.
- [ ] `M3-CP4c-2-DEFN` — BLOCKED.
- [ ] `M3-CP4c-3-DEFN` — BLOCKED.

Frozen selector authority remains **338** `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; accepted first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. H1 and J3 remain explicitly outside the 338 selector and have no credit. Latest accepted runtime remains CP4ab **316/316**. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **45**.

**H1 disposition after review — corrected and still unresolved pending TB-R6.** H-A and H-C remain excluded. The fan's 2 directed / 1 distinct disagreement is an excluded fixture artifact, and the lift histogram alone is uninformative about matching. Corrected legitimate population prediction is **388 directed / 194 distinct** across two-ring + prescribed sphere + torus. **Do not attempt a production fix until TB-R6's J1 decomposition and J3 geometry audit fill the frozen decision table with one evidence-supported owner.**

## CP4c documentation — consolidated 2026-08-26

Twenty-four per-turn CP4c execution documents and superseded review briefs were retired into
**`M3_CP4c_Consolidated_Record.md`** under explicit user authorization, preserving every evidence
identifier. Thirty-three CP4c documents became twelve. Retained live: the CP4c-0 DEFN charter and frozen
definitions, the five independent reviews (they carry Amendments 1–7 and measure series E/F/G/H), and
all selector `.txt` authority files. A citation naming a retired document now points at the consolidated
record — **retired provenance, not lost authority**. CP4c-0 and CP4c-1 remain **OPEN**; the record is
historical and closes nothing.
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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **45**. PR #8 remains open, draft, and unmerged.
