# Directional Surface-Cell TODO

Last updated: 2026-09-15 UTC

## Current turn — M4-CP-SCALE-TB5-REV

- [x] `M4-CP-SCALE-TB4-R1-EXEC`: fresh immutable candidate `10378808176` mechanically GREEN — focused S2 **1/1 PASS**, selector423 **423/423 PASS**, zero process anomalies, exact immutable postflight.
- [x] `M4-CP-SCALE-TB4-REV`: independently re-derived the six-subject exact oracle, Filter/ExactFallback non-vacuity, regular-star winding/effort authority, selector hashes and owner census; promoted package `10378808176` under unchanged selector423; stable totals remain **49 / 14 / 35**, debt **5**.
- [x] First TB4 orchestration candidates: CLOSED / NON-STABLE by fresh retry; invalid 383/40 observation surface receives zero semantic credit.
- [x] `M4-CP-SCALE-CB6`: published selector424 with exact accepted selector423 bytes as rows1-423 and exact S2 identity as row424; selector424 SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.
- [x] Re-derived unique gate ownership as **30 authority-kernel / 278 producer / 75 completion / 41 validation**.
- [x] Preserved product/test/fixture/CMake semantics and accepted selector423 byte-for-byte; only selector424 was added as semantic gate authority.
- [x] Compile/package GREEN through durable GMP/GMPXX reusable workflow with `runtimeExecution=false`; candidate artifact `10407605295`, exact source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`, package manifest 28/28.
- [x] `M4-CP-SCALE-TB5-EXEC`: immutable candidate artifact-only gate mechanically GREEN — selector424 **424/424 PASS**, zero process anomalies, exact immutable postflight, owner census **30/278/75/41**.
- [ ] `M4-CP-SCALE-TB5-REV`: independently adjudicate TB5 evidence; only Review may promote candidate package/selector424 or discharge `M4-CP-SCALE-TB4-REV-OBS-01`.

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

## Current focus — `M4-CP-SCALE-TB5-REV` (independent adjudication of selector424 cumulative proof)

Accepted runtime authority remains package `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` under selector423 **423/423** (`4e67e4dc...d89343`). CB6 has now published candidate selector424 and compile-proved it without running Directional; this does **not** promote runtime authority.

Candidate selector424 is exact selector423 prefix + row424 `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`, SHA-256 `f202a172...466ca`, owner census **30/278/75/41**. TB5-EXEC run `35002009539` is mechanically GREEN at **424/424 PASS** with zero RED/SKIP/timeout/crash/selection mismatch/unexecuted and exact immutable postflight. This does not promote authority: exact next is mandatory `M4-CP-SCALE-TB5-REV`, which alone may accept candidate `10407605295` / selector424 and discharge `M4-CP-SCALE-TB4-REV-OBS-01`. Stable accounting remains **49 / 14 / 35**, debt **5**; CP-SCALE remains OPEN because Review and S3-S5 are still unproved.

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

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND CLOSED + ACCEPTED / CP-SCALE SELECTOR424 424/424 MECHANICALLY GREEN / REVIEW NEXT**. Package `10378808176` / selector423 **423/423** remains accepted current runtime authority pending Review. Candidate artifact `10407605295` / selector424 is mechanically GREEN at **424/424 PASS** with exact immutable postflight but remains unpromoted. Exact next `M4-CP-SCALE-TB5-REV`; S1 remains diagnostic/non-gating, S2 cumulative selector acceptance awaits Review, S3-S5 remain open, and CP4 later discharges the 3 `G4-B002` debts before M4 closes.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. M4-CP3 and M4-CP-COND are CLOSED / ACCEPTED. `M4-CP-SCALE-TB4-REV` promotes package `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` as current M4 runtime authority under unchanged selector423 **423/423**. CP-SCALE remains OPEN: focused S2 is accepted for selector publication but does not yet receive cumulative required-green credit. CB6 published selector424 and TB5-EXEC run `35002009539` mechanically proves cumulative **424/424 PASS** with exact immutable postflight. Exact next is mandatory **`M4-CP-SCALE-TB5-REV`**; only Review may promote candidate `10407605295` / selector424. Stable accounting remains unchanged, and the prior orchestration-invalid TB4 attempt remains no-semantic-ledger provenance only. PR #8 remains open, draft, and unmerged.
