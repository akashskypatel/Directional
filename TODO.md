# Directional Surface-Cell TODO

Last updated: 2026-09-13 UTC

## Current turn — M4-CP-COND-CB2

- [x] `M4-CP-COND-DEFN`: freeze single-writer pre-A0 `ConditionedSourceProduct`, exact/certified raw→conditioned correspondence, exact permitted operation set, typed refusal, independent certificate/tamper validation, idempotence and witness preconditions.
- [x] `M4-CP-COND-CB1`: conditioner/certificate/validator seam implemented at semantic source `b576d061e23873b7b4193b158138d2097c75a728`; compile-only run `34740201494` GREEN with GMP/GMPXX and `runtimeExecution=false`.
- [x] CB1 preserved accepted CP3 package `10307919492` / selector408 **408/408** as predecessor; packaged selector408 remains 408 LF rows at SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`, with no A3/A4 or selector mutation.
- [x] `M4-CP-COND-TB1-EXEC`: authoritative run `34757021728` stopped at package preflight before Directional runtime because immutable artifact `10312168742` omits three selector408 owner executables (`authority_kernel`, `completion`, `validation`) covering 146 accepted identities. Result: **PACKAGE PREFLIGHT RED / 0 semantic processes / zero semantic test credit**; immutable post-stop census is exact.
- [x] `M4-CP-COND-TB1-REV`: candidate upheld as **PACKAGE-CLOSURE OWNER-SET OMISSION / PRE-SEMANTIC / NON-STABLE**; selector owner census independently re-derived as 30/262/75/41 and stable accounting held at 49/14/35, debt 5.
- [ ] `M4-CP-COND-CB2`: rebuild/package exact unchanged semantic source `b576d061e23873b7b4193b158138d2097c75a728` with all four selector-owner binaries plus pipeline/API; GMP/GMPXX mandatory; execute no Directional runtime; freeze unchanged semantic gate as TB2-EXEC plan.
- [ ] Keep boundary-truncated separatrix non-gating unless raw precondition/reachability is independently proved; do not author guaranteed-green evidence.
- [ ] Keep `M4-CP3-TB1-R1-REV-OBS-01`, `M4-CP3-CB4-REV-OBS-02`, `G4-B002` debt 3 and `G4-B003` debt 2 with their existing owners.


## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Closed milestone/checkpoint history lives in `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, `M3_CP4ab_Closure_Record.md`, and `M3_Closure_Record.md`, plus current milestone checkpoint closures such as `.agents/Directional/M4_CP1_Closure_Record.md`, `.agents/Directional/M4_CP2_Closure_Record.md`, and `.agents/Directional/M4_CP3_Closure_Record.md`. Exact runtime evidence lives in `CHANGELOG.md`, the current retained turn report, and `Regression_Root_Cause_Tracker.md`. Normative architecture lives in `DESIGN.md`; the checkpoint map to production-ready lives in `ROADMAP.md`; migration ordering lives in `REORIENTATION_PLAN.md`.

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

**Same-agent REVIEW/DEFN — user-authorized 2026-09-10.** REVIEW, REVIEW + PLAN, and DEFN may be performed by the same agent/session as earlier turns. "Independent" means independently re-opened evidence/re-derivation/oracle authority unless a criterion explicitly requires personnel separation; cadence and turn boundaries are unchanged.

## Current focus — `M4-CP-COND-CB2` (package-closure Code + Build only)

`M4-CP-COND-TB1-REV` is **COMPLETE** and upholds `M4-CP-COND-TB1-EXEC-CAND-01` as **PACKAGE-CLOSURE OWNER-SET OMISSION / PRE-SEMANTIC / NON-STABLE**. Review independently re-hashed selector408 at 408 rows / `c689c0cd...484`, first403 `c3f509af...70cb7`, and re-derived owner distribution **30 authority-kernel / 262 producer / 75 completion / 41 validation**. Immutable CB1 artifact `10312168742` packages only the producer owner, leaving 146 accepted rows without their three other executables. TB1 correctly stopped before runtime; no CP-COND semantic gate has an outcome.

Stable accounting remains **49 events / 14 categories / 35 recurrences**, debt **5**; accepted CP3 package `10307919492` / selector408 **408/408** remains runtime authority.

**Exact next: `M4-CP-COND-CB2`.** Follow `Architecture_M4_CP_COND_CB2_Code_Build_Plan.md`: compile/package exact unchanged semantic source `b576d061...` with `directional_core`, `directional_pipeline`, all four selector-owner test executables, and `directional_compiled_api_tests`; GMP/GMPXX mandatory; `runtimeExecution=false`; no semantic/source/test/fixture/selector/CMake/reusable-workflow edits. CB2 freezes an artifact-only `M4-CP-COND-TB2-EXEC` plan preserving TB1's 14 focused + one report-only + 408-selector semantic surface; mandatory runtime adjudication remains `M4-CP-COND-TB2-REV`.

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

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND TB1 REVIEW COMPLETE, CB2 PACKAGE CLOSURE NEXT**. `M4-CP3-TB8-REV` promotes package `10307919492` / selector408 **408/408** and closes the main exact-torus pairing blocker. CP-COND conditioner implementation is compile-green; TB1 had zero semantic credit because its artifact omitted three selector-owner binaries. Review classifies this pre-semantic/non-stable and freezes exact-source package closure CB2; CP-SCALE follows only after CP-COND; CP4 later discharges the 3 `G4-B002` produced-witness debts and closes M4.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. **M4-CP3 is CLOSED / ACCEPTED** on package `10307919492` / selector408 **408/408**; corrected R4 selector403 remains the accepted predecessor. The main exact-torus pairing blocker is recovery-proved, while its three produced-witness debts remain M4-CP4 gating. `M4-CP-COND-TB1-REV` is complete: the zero-runtime TB1 package failure is classified **PACKAGE-CLOSURE OWNER-SET OMISSION / PRE-SEMANTIC / NON-STABLE**. Exact next is compile/package-only **`M4-CP-COND-CB2`** under `Architecture_M4_CP_COND_CB2_Code_Build_Plan.md`, holding semantic source `b576d061...` and selector408 fixed. PR #8 remains open, draft, and unmerged.
