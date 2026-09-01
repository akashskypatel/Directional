# Directional Surface-Cell TODO

Last updated: 2026-09-01 UTC

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

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the chain it **is**
the review-and-plan turn: one turn freezes definitions, adjudicates inherited candidates, decides gate membership,
and issues the successor's measures. Only the `REVIEW+PLAN → DEFN` edge collapses; a red TB with no `DEFN` ahead of
it still gets its own review turn.

## Current focus — `M3-CP4c-3-CB8` (Code + Build, runtime-free)

`M3-CP4c-3-TB6-REV` is **COMPLETE**. Independent review accepted TB6 as a valid semantic red and established the
current cause/owners. Review authority: `Architecture_M3_CP4c3_TB6_Independent_Review_Record.md`.

### Review verdict

- TB6 authority is package 75 / source `e926ada023bc51220628be550bbe9a87f98d7067`, run/job
  `33458067065 / 99702200466`, result artifact **`9782227361`** (`e39fcab4…72a87`); the older documented
  `5748464145 / f084...` result identity was incorrect and has been corrected.
- Accepted ordinals **1–365 remain green**. First red 366 is still vertex 30 with two candidate faces.
- CB7's exactness repair did not preserve Amendment 17: each fan transition assigns
  `incomingDirection = nextPairing->direction`, so election still consumes one exact local representative per cell.
- Resolver audit rows exist but are dropped by `network_failure_locus` / `SurfaceCellFailureLocusDiagnostics`.
- CB7's minimal transit witness was required to become permanent regression authority; selector 373 stayed frozen.
  CB8 must append it as ordinal **374** in a new selector while leaving 373 unchanged.
- Ordinal 370 is a separate genuine product red owned by `SurfaceCutGraph::canonical_candidate`; do not combine it
  with CB8. Sphere and saturation remain deferred.

### Exact next turn

Execute **`M3-CP4c-3-CB8` Code + Build only** under
`Architecture_M3_CP4c3_CB8_Code_Build_Plan.md`. No Directional runtime is authorized. The bounded work is: one
exact single-writer transit datum and certified per-face views; additive production transit-audit projection;
strengthened minimal witness; append-only selector 374; eight-target GMP/GMPXX compile; immutable package and next
artifact-only TB plan. If exact single-datum transport cannot be represented from existing authority without
float/tolerance or rebinding to a target field representative, stop and report the architectural authority gap.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — **ACTIVE / cause confirmed**: per-cell representative election violates Amendment 17.
- [ ] `M3-CP4c3-TB6-CAND-01` — **ACTIVE / owner proved**: production projection/DTO drops exact transit rows.
- [ ] selector governance — create selector 374 only by appending the minimal transit identity to frozen 373.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — genuine independent empty-network product red; deferred from CB8.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere `NoCarrierMatch / SourceEdgeUnavailable`; deferred.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — `saturationUsed=true`; deferred quality/coverage debt.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — partial; mechanical zero-unbound proof still owed.

Stable accounting: **44 events / 14 categories / 30 recurrences**; debt **5**; semantic M3 packages **73**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 TB6 preserves the accepted 365-prefix but remains RED at ordinal 366. TB6-REV confirms per-cell-representative election still violates Amendment 17. Exact next is runtime-free `M3-CP4c-3-CB8` under the frozen AW0–AW9 plan.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB6 preserves the accepted 365-prefix and first-reds ordinal 366 at `VertexTransitSectorUnresolved`, source vertex 30, with two published faces. TB6-REV proves current source still elects from one target-local representative per cell and localizes the missing audit to the production projection DTO. Owned by runtime-free `CB8`; no candidate-order, tolerance, float-transport, or target-representative shortcut.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **73** after CB7/package 75. PR #8 remains open, draft, and unmerged.
