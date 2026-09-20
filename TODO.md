# Directional Surface-Cell TODO

Last updated: 2026-09-20 UTC

## Latest Review turn — `M5-CP1-TB1-R3-REV`

`M5-CP1-TB1-R3-REV` is **COMPLETE / CP1 CLOSED / CANDIDATE PROMOTED**. Independent Review re-opens R3 run/job `35496133258 / 106039321958`, result/log `10601350461 / 10601380504`, candidate `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7`, selector430 and routing authority. It upholds focused **9/9** + selector430 **430/430**, exact-one/zero-skip across **439**, immutable postflight, and the corrected row6 pure-permutation falsifier. Package `10600353027` is promoted as accepted current runtime authority. Stable accounting remains **49 / 14 / 35**, debt **5**.

- [x] `M5-DEFN`: freeze canonical relation identity, selected certificate, cutover, failure matrix, invariance, production reachability, and CP1/CP2/CP3 debt ownership.
- [x] `M5-CP1-CB1`: implement canonical relation IDs + selected path certificates; mandatory GMP compile/package green, no runtime.
- [x] `M5-CP1-TB1-EXEC`: pre-runtime fail-closed blocker recorded; **0/9 focused, 0/430 selector, zero semantic credit**.
- [x] `M5-CP1-TB1-PREFLIGHT-REV`: independently prove both frozen-plan routing defects; publish corrected retry plan; no runtime.
- [x] `M5-CP1-TB1-R1-EXEC`: terminal executor decode failed before Directional runtime; **0/9 focused, 0/430 selector, zero semantic credit**.
- [x] `M5-CP1-CB2`: canonical R2 harness/template authored and statically proved against unchanged immutable artifacts; **zero Directional runtime**.
- [x] `M5-CP1-TB1-R2-EXEC`: full artifact-only gate completed; focused **8/9 PASS / 1 RED**, selector430 **430/430 PASS**, immutable postflight exact.
- [x] `M5-CP1-TB1-R2-REV`: independently adjudicate row6 as test-authority-only and freeze the pure-permutation falsifier.
- [x] `M5-CP1-CB3`: author the pure-permutation row6 witness only; mandatory GMP compile/package green on `10600353027`; no Directional runtime.
- [x] `M5-CP1-TB1-R3-EXEC`: immutable complete gate executed; focused **9/9**, selector430 **430/430**, benchmark **0**, exact postflight.
- [x] `M5-CP1-TB1-R3-REV`: independently uphold R3, discharge the row6 falsifier observation, promote package `10600353027`, close CP1; no production-debt credit.
- [ ] `M5-CP2-CB1`: **exact next**; implement the frozen five-class typed relation failure matrix + independent negative oracles; mandatory GMP compile/package only, no runtime or selector publication.

## Current focus — `M5-CP2-CB1`

Code + Build only under `Architecture_M5_CP2_CB1_Typed_Relation_Failure_Matrix_Plan.md`. Retain missing/duplicate semantics, add conflicting/nonreciprocal/representation-renumbered typed failure, and independently derive expected semantic carrier identity in negative tests. Do not reintroduce ordinal relation identity, do not use the production identity factory as the test oracle, do not touch CP3 production evidence or M6 occurrence authority, and do not execute Directional runtime.

## Carried forward from M1

**Produced-witness debt — `G4-B002` split by DEFN-R1/R2 (3 total, unchanged).**
- [ ] **M6-CP1 mechanism / M6-CP3 production:** re-prove `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on authoritative A5 occurrence-complex production with the original independent eligibility oracle + hard-feature tamper.
- [ ] **M5-CP1 mechanism / M5-CP3 production:** re-prove `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` with the original `>=2` produced relation/edge discriminator.
- [ ] **M5-CP2 mechanism / M5-CP3 production:** re-prove `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority.

**Produced-witness debt — `G4-B003` → M5 (2).** Together with the two re-homed periodic `G4-B002` debts, M5 owns four produced-witness debts; M6 owns the re-homed closed-complex `G4-B002` debt; total project debt remains 5.
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

- [x] **M4** global conformity plan — **CLOSED / ACCEPTED at `M4-CP4-TB3-REV`**. Final runtime authority is package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**. Closure: `M4_Closure_Record.md`; CP4 closure: `M4_CP4_Closure_Record.md`. Four periodic/relation debts remain M5-owned and one closed-complex debt remains M6-owned.
- [ ] **M5** certificate-carrying chart/quotient relations — **CP1 CLOSED / ACCEPTED** on package `10600353027` / source `8a86710d...` under selector430 **430/430**; exact next `M5-CP2-CB1`; four M5 produced-witness debts remain open.
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
- [x] `G4-B002` main exact-torus hard-rail pairing blocker — **CLOSED / RECOVERY PROVED at M4-CP3-TB8-REV** on accepted package `10307919492` / selector408 **408/408**. The three produced-witness debts remain open: one closed-complex debt is M6-owned after DEFN-R2 and two periodic debts are M5-owned after DEFN-R1. This checkbox closes the blocker, not those debt items.
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

Current totals remain **49 events / 14 categories / 35 recurrences**, debt **5**. M4 and M5-CP1 are **CLOSED / ACCEPTED**; current accepted runtime authority is package `10600353027` / source `8a86710d...` under unchanged selector430 **430/430**. No produced-witness debt is discharged by CP1 closure: the closed-complex `G4-B002` debt remains M6-owned, while two periodic `G4-B002` plus two `G4-B003` debts remain M5-owned. Exact successor is **`M5-CP2-CB1`**. PR #8 remains open, draft, and unmerged.
