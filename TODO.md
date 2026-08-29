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

## Current focus — `M3-CP4c-2-CB5` — semantic/provenance digest split, under measures **AD0–AD9**

**`M3-CP4c-2-TB-X2-R6-REV` is COMPLETE / REVIEW GREEN.** Record:
`Architecture_M3_CP4c2_TB_X2_R6_Independent_Review_Record.md`.

**`PR8-R043` is RESOLVED AT ITS LOCUS.** Accepted ordinal 305 passes on the CB4 package — DEFN-R1's
actual-embedded-graph complex did what it was defined to do, and CB4 delivered
`src/geometry/EmbeddedGraphTopology.{h,cpp}` as the single shared authority AC1 required. **Closure is deferred
to a full 355/355**, because R6 ran 309 of 355 accepted identities; closing on a 309 prefix would be the
partial-evidence promotion this project has corrected twice.

**`PR8-R044` is CONFIRMED, and the fix template already exists in this repository.** Verified at source:
`GlobalTopologyPlan.cpp:1511-1519` consumes `candidate.cutGraphDigest`, and `SurfaceCutGraph.cpp:263-265`
builds that digest from gauge-dependent `atlasDigest`. **A2b states the rule in a comment, obeys it on the line
the comment guards, and is defeated two lines earlier.** The error is a **domain conflation**, not a hashing
bug: `candidate_hash` is a *provenance* hash and is correct as such — `make_from_candidate` needs `atlasDigest`
for tamper rejection. `M3-CP3a-DG-CAND-02` fixed exactly this for `FieldAlignedCurveNetwork`. **AD1 adds a
`semantic_digest()` and leaves `candidate_hash` unchanged; removing `atlasDigest` from it is prohibited.**

**One finding the EXEC did not reach.** `SurfaceCutGraph.cpp:258` keys each certificate face by the **raw orbit
index** — an enumeration artifact — and `candidate_hash` consumes it. Ordinal 310 asserts invariance to
enumeration order **and** relabeling, so removing `atlasDigest` alone leaves a latent instance of the same
pattern. **AD3** requires it settled by proof or by replacement with a content-derived key; "it passes now" is
not an answer.

**`R5-ORCH-01` is RESOLVED** — R6's postflight ran unconditionally after the red and passed. Preserve that path.

**`CAND-04` — the prescribed sphere — remains unlocalized for the seventh turn.** D2 has been scheduled and
correctly skipped five times, always because an upstream gate failed first. §8 of the review raises, without
deciding, whether the sphere diagnostic should be sequenced independently of the accepted-prefix outcome.

Stable accounting **44 / 14 / 30**, produced-witness debt **5**, M3 packages **63**.
`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

**New:** `ORIENTATION.md` is a cold-start context document — architecture, current position, witnesses, open
problems, recurring defect patterns and source pointers, with no procedural content. Read it first in a fresh
session.

## CP4c historical provenance

Superseded CP4c parent/CP4c-0/0b/1/2 turn narratives are consolidated in
`.agents/Directional/M3_CP4c_Consolidated_Record.md`. `CHANGELOG.md` owns exact historical run/package/artifact
identities; closure records own closed checkpoint authority. Do not re-expand that history here.

## CP4c documentation — consolidated through 2026-08-29

The sixth consolidation retires the remaining 35 superseded CP4c per-turn plans, reports, execution
evidence files, and review records after preserving their durable facts in
**`M3_CP4c_Consolidated_Record.md`**. Twenty-one CP4c-family files remain: normative frozen definitions,
selector authority, closure records for CP4c-0b/CP4c-1, current CP4c-2 CB4/R6 authority, and the
consolidated record. CP4c-0, CP4c-0b, and CP4c-1 are **CLOSED / ACCEPTED**; CP4c-2 remains active and
runtime-unaccepted. The complete retention/retirement manifest is in consolidated record §8.
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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; current accepted authority is **355/355**. CP4c-2 corrected diagnostic build is green/runtime-free at `c552a5a4a318063cde2564c40773ec7edaf064f6` with immutable GMP package `9704935112`; no 357/358 gate is selected; exact next is artifact-only `M3-CP4c-2-TB-X2-R3-EXEC`; CP4c-3 remains blocked.
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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **53**. PR #8 remains open, draft, and unmerged.
