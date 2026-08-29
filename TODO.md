# Directional Surface-Cell TODO

Last updated: 2026-08-29 UTC

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

## Current focus — `M3-CP4c-2-DEFN-R2` — trace-crossed non-cellular cut completeness definition

`M3-CP4c-2-CB6` stopped correctly at its first measure, **AF1**, before any implementation or compile. The retained
`prescribed-sphere` `m3Cp4c2ActualGraphOracle` row from result artifact `9721564203` reports
`V=18, E=30, F=18, c=1, chi=6, sourceChi=2` with zero excluded boundary orbits. The standing prediction that the
sphere is already cellular pre-cut is therefore **REFUTED**.

That finding activates the explicit `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` §8.3 trigger: the sphere
is trace-bearing and now proved non-cellular, so §8.2's unproved trace-crossed non-disc cut-selection case is live
and **CP4c-2 must return to definition**. CB6 made no product/test/fixture/selector/build change and ran no compile
or runtime. Full closeout: `Architecture_M3_CP4c2_CB6_Code_Build_Report.md`.

Exact next: **`M3-CP4c-2-DEFN-R2`**, definition/planning only. It must:

- define a complete admissible cut strategy for the now-live trace-crossed non-cellular case, or a sound typed-stop
  contract, without subdividing immutable traces or repairing already-derived regions;
- preserve Amendments 12/13 and the actual-embedded-graph authority;
- discharge **AF5** by deciding per `SurfaceCutGraph.*` identity which are gating and why any exclusion is non-gating;
- re-adjudicate the ordering/scope of **AF0/AF2/AF3/AF4** after the definition correction;
- make no selector, fixture, product/test, compile, package, runtime, 357/358, cumulative-gate, or benchmark change.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **64**.
`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

### Open CP4c-2 candidates

- [ ] **DEFN-R1 §8.2 completeness gap — NOW LIVE:** the prescribed sphere is trace-crossed and independently
      non-cellular pre-cut. `M3-CP4c-2-DEFN-R2` owns the definition before implementation can resume.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — live producer failure remains re-localized to the shared embedded-graph authority;
      AF0 has not yet printed its originating typed code and no product fix is authorized.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-01` — torus digest diagnostic builds a synthetic witness with no production
      counterpart; AF3/AF4 deferred across the definition stop.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-03` — D2 harness compares the actual embedded graph against the withdrawn proxy
      using stale line-number labels; AF2 deferred.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-04` — no `SurfaceCutGraph.*` identity is in any selector; the sphere is in neither
      candidate gate; 358 binds the out-of-scope mechanical witness; AF5/AF7.
- [ ] Measure **AD3** — `face.orbit` raw index consumed by `candidate_semantic_hash` under an unproved rationale;
      its only falsifier has never run. AF4 deferred.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R7 re-proved the inherited accepted **355/355** on CB5 package `9719216316`, closing `PR8-R043` and `PR8-R044`. CP4c-2 remains unaccepted; CB6 AF1 refuted pre-cut sphere cellularity and triggered the frozen return-to-definition rule. Exact next is `M3-CP4c-2-DEFN-R2`; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 trace-crossed non-cellular cut completeness:** AF1 proves the prescribed sphere is non-cellular pre-cut, activating DEFN-R1 §8.3. Definition repair/typed-stop contract is required before any product fix.
- [ ] **Prescribed sphere A2a′ collapsed upstream error:** AF0 still must print the originating code before any error-path product fix; do not fix by inference.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **64**. PR #8 remains open, draft, and unmerged.
