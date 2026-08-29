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

## Current focus — `M3-CP4c-2-CB6` — bounded diagnostic and witness-repair Code + Build

`M3-CP4c-2-TB-X2-R7-REV` is complete. R7's full accepted **355/355** re-proof on immutable package `9719216316`
is accepted, and on it **`PR8-R043`, `PR8-R044` and `R7-ORCH-01` are CLOSED**. Full adjudication is in
`Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`.

The review's decisive finding: **the prescribed sphere's `CellularityNotEstablished` is a `default:` bucket, not a
cellularity verdict.** `SurfaceCutGraph::topology_error` collapses 36 distinct `GlobalTopologyPlanErrorCode` values
into it; R7-5's `errorSourceFace=25-27-28` proves the sphere took that path, and every such code reachable there is
`RotationSystemInconsistent` inside `EmbeddedGraphTopology.cpp`. The sphere never reached a cellularity decision;
A2a′ renamed its pre-existing failure rather than changing it.

Exact next: **`M3-CP4c-2-CB6`** under measures **AF0–AF4** with the **AF9** prohibitions.

- **AF1 runs first and needs no build:** extract the prescribed sphere's `m3Cp4c2ActualGraphOracle` row from
  retained result artifact `9721564203` and state whether the standing prediction is confirmed. R7-3 already
  published it; the R7 report quoted only the torus row.
- **AF0** carry and print the originating `GlobalTopologyPlanErrorCode` through `topology_error` — additive only;
  no re-mapping and no new enum value.
- **AF2** repair the D2 localization harness (rename `cp4c_producer_rederivation`, drop the stale `419/437/474`
  line-number labels, and either delete or redefine `localizationConsistent`).
- **AF3** rebuild the torus digest diagnostic on the production `torus.rawfield` authority and print the typed
  atlas error instead of `ASSERT_TRUE`.
- **AF4** run `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` non-gating and settle measure **AD3**.

**AF5** (frozen definitions must state per-identity gate membership for A2a′) is DEFN scope. **AF6** (a frozen
non-gating selector must be run or its skips justified per identity) and **AF7** (358 probed non-gating before it
may ever be selected) bind the TB after CB6. **AF8** binds that TB's closeout.

Stable accounting remains **44 / 14 / 30** — closure is a status change, not a count change — produced-witness debt
**5**, authoritative M3 packages **64**. `selected_r2_branch=NONE`; `selected_gate=NONE`;
`gate_execution_authorized=false`.

### Open CP4c-2 candidates

- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere failure re-localized to the shared embedded-graph authority; cellularity
      framing withdrawn. Needs AF0's printed code before any fix.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-01` — torus digest diagnostic builds a synthetic witness with no production
      counterpart; AF3/AF4.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-03` — D2 harness compares the actual embedded graph against the withdrawn proxy
      using stale line-number labels; AF2.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-04` — no `SurfaceCutGraph.*` identity is in any selector; the sphere is in neither
      candidate gate; 358 binds the out-of-scope mechanical witness; AF5/AF7.
- [ ] Measure **AD3** — `face.orbit` raw index consumed by `candidate_semantic_hash` under an unproved rationale;
      its only falsifier has never run. AF4.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R7 re-proved the inherited accepted **355/355** on CB5 package `9719216316`, closing `PR8-R043` and `PR8-R044`. CP4c-2 remains unaccepted because 357/358 are unselected/unrun and the prescribed sphere's A2a′ failure is now localized but unfixed; exact next is `M3-CP4c-2-CB6`; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **Prescribed sphere A2a′ `RotationSystemInconsistent`** (via the collapsed `CellularityNotEstablished`): the checkpoint's real open product defect. Blocked on AF0's printed code; do not fix by inference.
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
