# Directional Surface-Cell TODO

Last updated: 2026-09-16 UTC

## Current turn — M4-CP-SCALE-TB7-REV

- [x] `M4-CP-SCALE-TB6-REV`: independently reopened TB6 evidence/source, promoted package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` under unchanged selector424 **424/424**, accepted S3 focused proof for publication, and discharged `M4-CP-SCALE-DEFN-OBS-02`.
- [x] `M4-CP-SCALE-CB8`: published selector425 as exact selector424 prefix + row425 `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`; SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owner census **30/279/75/41**.
- [x] Compile/package run/job `35042417046 / 104624909472` GREEN on exact source `01b1124af094044e32d6887ff0615881333d12ce`; artifact `10425344367`, GMP/GMPXX, clean source, self-verifying manifest, `runtimeExecution=false`.
- [x] `M4-CP-SCALE-TB7-EXEC`: authoritative retry `35045130314 / 104633231692` mechanically GREEN at selector425 **425/425 PASS** in 425 fresh exact-filter processes, fresh row425 PASS, owner census **30/279/75/41**, exact immutable postflight, no rebuild/relink/repair/discovery/mutation/benchmark execution. Initial attempt `35044943849` was pre-runtime orchestration failure and receives zero semantic credit.
- [ ] `M4-CP-SCALE-TB7-REV`: independently reopen CB8 package plus TB7 result/log/nested evidence, re-derive selector425/prefix/ownership/all 425 outcomes and immutability, then alone decide selector425 promotion and `M4-CP-SCALE-TB6-REV-OBS-01` discharge.

## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Closed milestone/checkpoint history lives in `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, `M3_CP4ab_Closure_Record.md`, and `M3_Closure_Record.md`, plus current milestone checkpoint closures such as `.agents/Directional/M4_CP1_Closure_Record.md`, `.agents/Directional/M4_CP2_Closure_Record.md`, and `.agents/Directional/M4_CP3_Closure_Record.md`. Exact runtime evidence lives in `CHANGELOG.md`, the current retained turn report, and `Regression_Root_Cause_Tracker.md`. Normative architecture lives in `DESIGN.md`; the checkpoint map to production-ready lives in `ROADMAP.md`; migration ordering lives in `REORIENTATION_PLAN.md`.

**Do not re-accumulate per-checkpoint, per-retry, or per-partial narrative here.** A closed checkpoint gets one line in `ROADMAP.md` §1 and a closure record; it does not stay in this file.

## Turn workflow — changed 2026-08-25

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ semantic red
        REVIEW + PLAN  →  CB  →  …
                ↓ orchestration failure
        CB (orchestration fix) → TB (fresh retry) → …
```

**Non-gating diagnostic identities** TB executes and reports them, the
gate count excludes them, each carries a written rationale and an owning corrective measure.

**Orchestration failures are not semantic RED.** They produce no semantic ledger and route to a bounded runtime-free control-plane Code + Build correction followed by a fresh immutable TB retry, per `Turn_Cadence.md`.

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the chain it **is**
the review-and-plan turn: one turn freezes definitions, adjudicates inherited candidates, decides gate membership,
and issues the successor's measures. Only the `REVIEW+PLAN → DEFN` edge collapses; a red TB with no `DEFN` ahead of
it still gets its own review turn.

**Same-agent REVIEW/DEFN — user-authorized 2026-09-10.** REVIEW, REVIEW + PLAN, and DEFN may be performed by the same agent/session as earlier turns. "Independent" means independently re-opened evidence/re-derivation/oracle authority unless a criterion explicitly requires personnel separation; cadence and turn boundaries are unchanged.

## Current focus — `M4-CP-SCALE-TB7-REV` (mandatory independent evidence adjudication)

Current **accepted runtime authority remains** package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` under selector424 **424/424** (`f202a172...466ca`). CB8 candidate artifact `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` carries selector425 `e0e0f394...790e0b`, owner census **30/279/75/41**, GMP/GMPXX and `runtimeExecution=false`.

TB7 authoritative retry `35045130314 / 104633231692` is mechanically GREEN: selector425 **425/425 PASS** in 425 fresh exact-filter processes, fresh row425 PASS, zero anomalies and exact package/source/execution-view postflight. Initial attempt `35044943849` failed before runtime because the temporary workflow omitted checkout; it has no semantic ledger. `M4-CP-SCALE-TB6-REV-OBS-01` is therefore **publication + cumulative runtime satisfied / Review owed**. `M4-CP-SCALE-TB7-REV` must independently reopen the evidence and is the only turn allowed to promote selector425 or discharge the observation. Stable accounting remains **49 / 14 / 35**, debt **5**.

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
- [x] **M3 — field-aligned curve network.** **CLOSED / ACCEPTED at `M3-CP4c-3-TB48-REV`.** Package113/TB48 is reviewed authority at 405 PASS / 4 RED over the final audit surface, with accepted required-green selector365 at 365/365 and the AU0–AU9 mechanical-witness criterion met. Closure: `M3_Closure_Record.md`.

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND CLOSED + ACCEPTED / CP-SCALE S2 CUMULATIVE ACCEPTED + S3 FOCUSED PUBLICATION AUTHORITY / CHECKPOINT OPEN**. Package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` / selector424 **424/424** is accepted current runtime authority. CB8 selector425 publication/compile is GREEN; exact next `M4-CP-SCALE-TB7-EXEC` runs fresh 425/425, followed by mandatory Review; S1 remains diagnostic/non-gating, S2 arrival remains blocked, S3 cumulative selector425 credit remains owed, S4-S5 remain open, and CP4 later discharges the 3 `G4-B002` debts before M4 closes.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [x] **CP4c-3 protected frontier census evidence:** Part XII was first runtime-proved in TB43: 390/393/406/407 executed the producer-owned census predicates and rejected same-domain corruption. `M3-CP4c3-TB40-EXEC-CAND-02` remains historically CLOSED / RUNTIME-PROVED / NON-STABLE. TB45 historically exposed the stale failure-required precondition; package113/TB48 now re-proves all four receipts non-vacuously through `PlanFrontier`.
- [x] **CP4c-3 protected Part XII success-path observability — CLOSED / RUNTIME-PROVED:** package111 ordinals 390/393/406/407 all PASS on `PlanFrontier`, execute the real census predicates, reject same-domain corruption and emit non-vacuous receipts.
- [x] **CP4c-3 ordinal367 independent oracle — CLOSED / RUNTIME-PROVED / NON-STABLE:** TB47/package112 PASSes ordinal367 under the frozen high-side-only rule; package112 is promoted. Accepted ordinal307 remains a separately recorded latent stale equality and is unchanged.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

- [x] **CP4c-3 ordinal370 empty closed network — CLOSED / RUNTIME-PROVED / NON-STABLE:** package113 ordinal370 PASSes under the frozen identity requiring `EmptyNetworkOnClosedSurface = 6` plus a non-empty `sourceFace` locus. TB48-REV promotes package113 and closes `M3-CP4c2-TB-X2-R8-CAND-02` without changing stable accounting.
- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. TB8 repeated this pre-classified stop; it adds no new product evidence.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; downstream of A2b and not a CP4c witness collision.
- [x] `G4-B002` main exact-torus hard-rail pairing blocker — **CLOSED / RECOVERY PROVED at M4-CP3-TB8-REV** on accepted package `10307919492` / selector408 **408/408**. The **three produced-witness debts remain open and M4-CP4-owned**; this checkbox closes the blocker, not those debt items.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. M4-CP3 and M4-CP-COND are CLOSED / ACCEPTED. `M4-CP-SCALE-TB6-REV` promotes package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` as current M4 runtime authority under unchanged selector424 **424/424**, discharges `M4-CP-SCALE-DEFN-OBS-02`, and accepts S3 focused proof for publication. CP-SCALE remains OPEN: S1 is diagnostic/non-gating; S2 arrival remains blocked; S3 cumulative selector425 credit remains owed under `M4-CP-SCALE-TB6-REV-OBS-01`; S4/S5 remain open. CB8 publication/compile is GREEN; exact next is artifact-only **`M4-CP-SCALE-TB7-EXEC`** for fresh selector425 425/425, then mandatory Review. Stable accounting remains unchanged, and prior orchestration-invalid attempts remain no-semantic-ledger provenance only. PR #8 remains open, draft, and unmerged.
