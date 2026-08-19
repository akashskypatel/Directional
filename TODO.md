# Directional Surface-Cell TODO

Last updated: 2026-08-19 UTC

## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Completed milestone history lives in `M1_Closure_Record.md`; exact runtime evidence lives in `CHANGELOG.md` and `Regression_Root_Cause_Tracker.md`; normative architecture lives in `DESIGN.md`; migration ordering lives in `REORIENTATION_PLAN.md`. Do not re-accumulate per-checkpoint, per-retry, or per-partial narrative here.

## Current focus — `M3-CP2-TB` — EXACT NEXT / immutable Test + Benchmark

**CP1 remains the latest accepted runtime authority at 281/281. CP2 Code + Build is complete,
but CP2 is NOT yet accepted.** Candidate `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692` is package 9, produced by
`32279806492 / 96155630834` after green external pre-package `32279124852 / 96153441513`, all
with `runtimeExecution=false`. M3 is **9/12**.

Exact next `M3-CP2-TB` consumes `9375452692` artifact-only at frozen **287/287**. No rebuild,
relink, repair, source/test/fixture mutation, or generated discovery is allowed. Red stops for
Review; package 10 / CP3a is blocked until accepted CP2. Stable totals remain **38 / 14 / 24**;
produced-witness debt remains **5**.

## M3 — field-aligned curve network

- [x] `M3-CP0-CB` — census complete; `M3-CP0-TB` **OMITTED** by user-authorized cadence exception (not a pass, not acceptance).
- [x] `M3-CP1-TB-R1` — package 5 immutable gate **258/281 FAIL**; A1 **3/6**, retained M2 **255/275**, M1 producer **118/138**.
- [x] `M3-CP1-RUNTIME-REPLAN-R2` — independent A1 implementation review complete; F2/F3/F4 confirmed, F5 derivation required before mutation.
- [x] `M3-CP1-A1-DERIVATION` — planning-only derivation complete; A1 retained; `turningLift ≡ signed matching sum (mod 4)` derived under the single cycle-row orientation; persistent A1 bypass rejected at CP1 acceptance.
- [x] `M3-CP1-CB-R4` — user-authorized local cap **5 -> 6**; exact source `95006048225df765b5b9c31e235fed82330a1469`; external pre-package **91/91**, package 6 full closure **123/123**, `runtimeExecution=false`; package `9354456191`.
- [x] `M3-CP1-TB-R2` — immutable package-6 gate **258/281 FAIL**; A1 **3/6**, retained M2 **255/275**, M1 producer **118/138**; package/source postflight immutable.
- [x] `M3-CP1-A1-RESCOPE` — planning-only historical rescope. **SUPERSEDED/CORRECTED:** it omitted `indexMinFromZero` from the actual matching producer and its proposed A1 design removal is not authoritative.
- [x] `M3-CP1-PLAN-AMEND` — review complete. The superseded per-turn plan was retired after CP1 acceptance; its durable result is preserved in `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`, the accepted CP1 TB report, and the current M3/CP2 plan: A1 retained, exact-zero `dual_cycles` curvature contamination identified, C1 bypass rejected, CP1 cap **6 -> 7**.
- [x] `M3-CP1-CB-R5` — exact source `9f7e222bab6c930a12d1369fa2aee869f5c0dcff`; bounded two-file exact-zero support correction + strengthened existing square witness; external pre-package **91/91**; package 7 full closure **123/123**; `runtimeExecution=false`; immutable package `9366752046`.
- [x] `M3-CP1-TB-R3` — **ACCEPTED.** Immutable `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046`; `32263614534 / 96102598799`; A1 **6/6** + retained M2 **275/275** = **281/281**; postflight immutable; no generated discovery or benchmark execution.
- [x] `M3-POST-CP1-ALLOC-REPLAN` — cumulative ceiling **11 -> 12**; current **8/12**; remaining slots fixed one each to CP2, CP3a, CP3b, CP4; no automatic retry/package 13; `M3-FULL` remains omitted.
- [x] `M3-CP2-CB` — exact source `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff`; pre-package `32279124852 / 96153441513` green; package 9 `9375452692` via `32279806492 / 96155630834` compile/package green; `runtimeExecution=false`; M3 **9/12**.
- [ ] `M3-CP2-TB` — **EXACT NEXT.** Immutable package `9375452692`; accepted CP1 281 + CP2 6 = **287/287**; red stops for Review.
- [ ] `M3-CP3a-CB` — branch-consistent combinatorial tracing from typed atlas/ports into candidate segments; no contact/intersection graph. **BLOCKED on accepted CP2.** → `M3-CP3a-TB`
- [ ] `M3-CP3b-CB` — typed first-contact/intersection/termination incidence plus independent trace/event composition proof; no global topology selection. **BLOCKED on accepted CP3a.** → `M3-CP3b-TB`
- [ ] `M3-CP4-CB` — derive/select network topology and publish `GlobalTopologyPlan` regions with mandatory-topology preservation and disc proof; stop before M4 rail scheduling. **BLOCKED on accepted CP3b.** → `M3-CP4-TB`, which is also the cumulative M3 exit gate.
- [ ] M3 exit gate — ten criteria in the M3 plan section 2, subject to the accepted CP1 authority and post-CP1 allocation plan.

## Carried forward from M2

- [ ] **3 latent fixture-authority sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options asserting success, passing only because their complexes never reach boundary-ownership resolution; **none in the frozen selector**, so no gate protects them.
- [ ] **Remove the `= {}` default** on the authority-consuming `complete_surface_cell_complex` overload (`PatchDescriptor.h:427`) so omission stops compiling — the class-closing fix, still unscheduled.
- [ ] **Establish authority-carrying completion options as the local idiom.** `SurfaceCellComplexCompletionOptions` is 8/8 authority-unset across all tests; only 3 of `PatchDescriptorMilestoneE`'s contracts are gated, none of them completion tests.

## Carried forward from M1

Enforced as exit criteria of the milestones that can discharge them — not as task-list items, which have nothing enforcing them.

**Produced-witness debt — `G4-B002` → revised M4 (3).** A 4th reopens section 14 scheduling.
- [ ] Re-prove `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on a produced closed complex.
- [ ] Re-prove `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` through the torus pipeline.
- [ ] Re-prove `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority.

**Produced-witness debt — `G4-B003` → M5 (2).** A 3rd reopens M5 scheduling.
- [ ] Re-prove `FullPeriodicRotationAndTranslationMaterialize` on produced nonzero-Z4 authority.
- [ ] Re-prove `TamperedFullPeriodicTransformIsRejected` on produced nonzero-Z4 authority.

**Criterion-5 disposition re-proof → M7.**
- [ ] Re-express M1 criterion 5 in disposition terms and re-run F1/F2/F3 under verifier-assigned `Certified`. M7 does not close until green.

## Deferred hygiene

Inherited baseline-red / non-gating fixtures, frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] **WU2A-TB-CAND-01:** `PatchDescriptorMilestoneE.SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity` — prove the ownership-registry precondition first.
- [ ] **WU2B-TB-CAND-01:** hard-rail region-copy fixture — establish a valid front-boundary-authority precondition first.
- [ ] **WU2B-TB-CAND-02:** permitted side-repair rollback fixture — establish its ownership-registry/domain-identity precondition; keep the rollback assertion strict.
- [ ] **WU2B-TB-CAND-03:** authoritative-cell-scope subdivision fixture — reconcile against independently derived source-scope authority.
- [ ] **WU2B-TB-CAND-04:** five simplification fixtures — require independently proven removable/protected/healing preconditions.
- [ ] **WU2B-TB-CAND-05:** FlowRep mandatory-cycle witness — `selectionSucceeded=false` is non-evidence for the later cycle assertion.
- [ ] **RA-REV-23-F3:** dispatch the stitch-kind audit through an explicit probe classifier field rather than probe-name text; add a negative self-test.
- [ ] **RA-REV-22-F6:** remove non-falsifiable validation-used assertions, or set those fields where each gate actually executes.
- [ ] **RA-TB6-H1:** repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Product and architecture roadmap

- [x] **M0 — preserve evidence.**
- [x] **M1 — single-authority contract cutover.** Closed by accepted `M1-FULL-TB` `32055365696 / 95464163035` at 234/234 and K=0.
- [x] **M2 — closed stage products and single writers.** **CLOSED / ACCEPTED** by `M2-CP4-TB-R2` `32183306224 / 95861164621` on `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431` at **275/275 + K=0**.
- [ ] **M3 — field-aligned curve network.** CP1 accepted; CP2 package 9 `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692` is frozen; current M3 **9/12**; exact next immutable `M3-CP2-TB` at **287/287**. CP3a package 10 is blocked until CP2 acceptance.
- [ ] **M4 — global conformity plan.** One shared positive rail schedule before regional production. **Also discharges the 3 `G4-B002` produced-witness debts.**
- [ ] **M5 — certificate-carrying chart and quotient relations.** **Also discharges the 2 `G4-B003` produced-witness debts.**
- [ ] **M6 — occurrence, embedding, and independent verification.**
- [ ] **M7 — disposition and graded degradation.** D0-D4, strict fixtures at D0. **Also discharges the M1 criterion-5 forward obligation:** re-express M1 criterion 5 in disposition terms and re-run the three named structural fixtures under verifier-assigned `Certified`.
- [ ] **M8 — module boundaries and operational hardening.**
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; strict-valid torus must reach 3/3.
- [ ] `G4-B002`: exact torus `InvalidHardRailPairing`; revised M4. Scheduling reviewed and **confirmed deferred**, with the deferral priced (`REORIENTATION_PLAN.md` section 14).
- [ ] `G4-B003`: nonzero periodic Z4 production; M5. Producer leg still open; algebra and materializer legs advanced by unit-2 Batch D.
- [ ] `G4-B004`: positive multi-isolation quotient witness; M5/M6.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates, explicitly **not** M1 exit criteria.

## Design and calibration backlog

- [ ] **Calibrate `T5` quality/resource thresholds** from measured baselines before any milestone asserts a quality gate. Not an M1 blocker; blocks the representative acceptance matrix.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.

---

Historical stable totals are **38 events / 14 categories / 24 recurrences**. Produced-witness debt remains **5**. PR #8 remains open, draft, and unmerged.