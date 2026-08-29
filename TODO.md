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

## Current focus — `M3-CP4c-2-DOC-R1` — documentation-only hash correction, under measures **AE0–AE9**

**`M3-CP4c-2-TB-X2-R7-REV` is COMPLETE / REVIEW GREEN.** Record:
`Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`.

**R7-0's stop was correct and deserves credit.** Faced with a preflight mismatch it refused to substitute the
observed values for the plan's constants — which would have silently rewritten executable authority mid-run —
stopped before the first Directional process, left the package untouched, and ran a post-preflight integrity
check anyway. **AE7 preserves all three behaviours.**

**All six hashes were recomputed from bytes in review** and match the immutable package, R6-EXEC and
`ORIENTATION.md` exactly. **The selector bytes never changed; the accepted authority chain is intact.**

**The defect is fabricated constants in documentation, and the proof is arithmetic:** the R7 plan's expected
value for selector 357 is **63 characters**. SHA-256 is 64. A stale or wrong-file digest would still be 64, so
this was assembled by hand. Every failing constant shares the **first eight** characters and the **trailing**
characters with the truth and differs only in the middle — the signature of `PREFIX…SUFFIX` expanded back to
full length by inventing the interior.

**Part of the cause is the reviewer's.** R6-REV's AD0 wrote all six hashes in abbreviated form inside a measures
table that reads like a value table. Full values existed elsewhere so the abbreviation did not force the error,
but it supplied the template. **Rule adopted (lesson 22n): a digest is written in full or replaced by a file
reference plus "recompute" — never abbreviated where a value is expected.** AE4 adds mandatory 64-lowercase-hex
validation at authoring time, which would have caught the 63-character value a turn earlier for almost nothing.

**One narrow sequencing change (AE8).** After the correction, R7 retries unchanged in content except that the
**non-gating** diagnostics R7-2..R7-5 run **before** the accepted-prefix gate and publish regardless of its
outcome. They grant no credit and mutate nothing, so this reorders publication, not authority — and it ends an
eight-turn drought in which `CAND-04` has been scheduled and not run in R2, R3, R4, R5, R6 and R7, every stop
individually correct and every one upstream of the measurement.

**`ORIENTATION.md` is now DURABLE and must be updated at every REVIEW turn** — marked in the document itself,
in the handoff's durable policy as item 12, and in the mandatory end-of-turn checklist as item 7.

`PR8-R043` unchanged (RESOLVED AT LOCUS, closure pending full 355). `PR8-R044`'s CB5 correction is **compiled
but runtime-unproved**. Stable accounting **44 / 14 / 30**, debt **5**, M3 packages **64**.
`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

## Superseded focus — `M3-CP4c-2-TB-X2-R7-EXEC` stop (retained for provenance)

**`M3-CP4c-2-TB-X2-R7-EXEC` is COMPLETE AT R7-0 / HARD ORCHESTRATION STOP / NO DIRECTIONAL RUNTIME.**
Immutable package `9719216316` remains valid: outer digest
`acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`, source
`755485865a7cf9c485d754f22b82a41ee151824b`, source archive
`78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`, internal manifest **28/28 PASS**,
GMP/GMPXX evidence present, six runtime binaries executable.

R7-0 found that the plan's exact expected hashes for 346, 353, 357, and 358 do not match the unchanged immutable
selector bytes. The actual values match `ORIENTATION.md` and R6-EXEC authority. The frozen rule therefore stopped
before ordinal 1; R7-1 through R7-5, 357/358 execution, cumulative gate, and benchmarks are **NOT RUN**. Raw archive:
`Directional__M3-CP4c-2-TB-X2-R7-EXEC__raw-evidence.tar.gz`,
`sha256:b83172acc3519fc6fe3472e5844a48e0bfd938fe9e6a5d68d14e515371454cc7`.

Tracked non-stable orchestration defect: **`M3-CP4c2-TB-X2-R7-ORCH-01`**. Stable accounting remains
**44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **64**. R043 and R044 receive no new
runtime evidence; their full-355 closure conditions remain unchanged. `selected_r2_branch=NONE`,
`selected_gate=NONE`, `gate_execution_authorized=false`.

**That review is complete.** It recomputed all six hashes from bytes, localized the defect as four fabricated
constants, adopted the abbreviation rule, and authorized documentation-only `M3-CP4c-2-DOC-R1` under
**AE0–AE9**, after which R7 retries on the unchanged package `9719216316`.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; accepted runtime authority remains **355/355**. CP4c-2 CB5 is build-green/runtime-free at `755485865a7cf9c485d754f22b82a41ee151824b` with immutable GMP package `9719216316`; no 357/358 gate is selected; exact next is documentation-only `M3-CP4c-2-DOC-R1` under measures AE0–AE9, then the R7 retry; CP4c-3 remains blocked.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **64**. PR #8 remains open, draft, and unmerged.
