# Directional Surface-Cell TODO

Last updated: 2026-09-16 UTC

## Current turn — M4-CP-SCALE-TB9-EXEC

- [x] `M4-CP-SCALE-TB8-REV`: rejected the CB9 sphere-numbered torus prerequisite authority; accepted TB7 runtime authority remained unchanged.
- [x] `M4-CP-SCALE-CB10`: corrected only the S4 prerequisite test authority at semantic source `bebb14e32a0ac53dd420acf46bfa34410cf759a1`; changed-owner preflight and all-eight-target GMP/GMPXX package compile are GREEN with `runtimeExecution=false`. Candidate artifact `10455353524` / SHA-256 `b891318511ef6db2f6317abac99a4b7e1511fe6d4ebc58bdd048cdc49a757de9`; selector425 remains byte-frozen.
- [ ] `M4-CP-SCALE-TB9-EXEC`: artifact-only focused S4 prerequisite first; fail fast on focused defect, otherwise run selector425 as 425 additional fresh exact-filter processes; immutable postflight mandatory. No rebuild/repair/mutation and no promotion decision.
- [ ] `M4-CP-SCALE-TB9-REV`: mandatory independent review after TB9 execution; decides candidate promotion and `M4-CP-SCALE-DEFN-OBS-03` disposition.

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

## Current focus — `M4-CP-SCALE-CB10` (S4 prerequisite test-authority correction)

Accepted runtime authority remains TB7 package `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` under selector425 **425/425** (`e0e0f394...790e0b`), exact selector424 prefix `f202a172...466ca`, owner census **30/279/75/41**.

TB8 Review re-derived the rejected CB9 focus from exact bytes. `SurfaceCutGraph::canonical_candidate` proves the empty-cut torus state is a real production candidate, but accepted row356 and M3 frozen authority establish its pre-cut network as **V=48 / E=48 / c=4 with four annular complement components**. The CB9 expected tuple **18/30/18 / c=1** is the retained prescribed-sphere pre-cut actual-graph tuple. Correct torus necessary-condition arithmetic is `b1=4`, required faces `3`, observed independent complement components `4`, so the negative still rejects for a sound reason. CB9's additional equality between independent complement components and product face-walk-orbit `faceCount` is invalid off the cellular domain and must be removed.

`M4-CP-SCALE-CB10` owns only that test-authority correction and compile/package proof. Product topology semantics, A2a' cut selection, final certificate, fixtures, CMake semantics and selector425 stay frozen. No runtime and no selector426. `M4-CP-SCALE-DEFN-OBS-03` remains **OPEN / CORRECTION + FRESH TB9 + REVIEW OWED / NON-STABLE**. Stable accounting remains **49 / 14 / 35**, debt **5**.

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

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND CLOSED + ACCEPTED / CP-SCALE S2 + S3 CUMULATIVE ACCEPTED / CHECKPOINT OPEN**. Package `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` / selector425 **425/425** remains accepted current runtime authority after TB7 Review. TB8 Review rejected CB9's S4 prerequisite test authority as a non-stable witness-numeric transplant plus an off-domain face-count representation comparison; accepted TB7 authority remains unchanged. Exact next `M4-CP-SCALE-CB10` is test-only authority correction + compile/package, with no S4 production activation or selector426. S1 remains diagnostic/non-gating, S2 arrival remains blocked, S5 remains open, and CP4 later discharges the 3 `G4-B002` debts before M4 closes.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. M4-CP3 and M4-CP-COND are CLOSED / ACCEPTED. `M4-CP-SCALE-TB7-REV` package `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` remains current M4 runtime authority under selector425 **425/425** with S3 cumulatively accepted. TB8 Review rejects CB9's S4 prerequisite test authority as a non-stable witness-numeric transplant: prescribed-sphere `18/30/18,c=1` was asserted on a torus whose accepted pre-cut authority is `48/48,c=4`, with four annular complement components. Correct independent torus arithmetic is `b1=4`, required faces `3`, observed components `4`. Accepted TB7 authority remains unchanged. CP-SCALE remains OPEN: S1 is diagnostic/non-gating, S2 arrival remains blocked, S4 prerequisite test correction + fresh runtime + mandatory Review, later production activation, and S5 genus>=2 remain open. Exact next is mandatory **`M4-CP-SCALE-CB10`**. PR #8 remains open, draft, and unmerged.
