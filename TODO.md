## CURRENT — TB57 860/861 locally (A5–A7 snapshots landed); DIAG-RETAIN CLI/GUI DEFN next (2026-10-31)

- [x] Done (records in `.agents/Directional/`, history in `CHANGELOG.md`): RP-01 closure (RA-174…[RA-179](.agents/Directional/Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) → O15 (RA-180, CB55, TB54, [RA-181](.agents/Directional/Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md)) → row 935 (RA-182, CB56, TB55) → O2 entry gate ([RA-183](.agents/Directional/Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md), CB57, TB56 858/859) → DIAG-RETAIN DEFN ([RA-184](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md)) → **`M6-CB58-DIAG-RETAIN-A5-A7-SNAPSHOTS`** ([record](.agents/Directional/Architecture_M6_CB58_Diag_Retain_A5_A7_Snapshots_Code_Build_Record_20261031.md)): patch `c72e47cc…` exact, source `58ddfef0…`, package `241aeebd…` → **`M6-TB57-DIAG-RETAIN-FULL-GATE-EXEC`** ([report](.agents/Directional/Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md)): **860/861**, only row 283 (O16) red; membership 943; result `d0b9fa38…`.
- [ ] **NEXT `M6-DEFN-DIAG-RETAIN-CLI-GUI`** (DEFN, R, local): define the CLI diagnostics dump and GUI display layers over the CB58 snapshots as read-only observers, rule on DR2, decide how each layer is built and tested under the CI flags (which build neither CLI nor GUI), then freeze one exact CB per layer.
- [ ] **DIAG-RETAIN (user-directed, 2026-10-21), remaining:** the CLI diagnostics dump and the GUI display layers (NEXT, above), which also decides DR2 (the multi-component path does not merge the snapshots). DR1 (no in-helper A6/A7 rejection witness) waits for a stimulus, for example from P13 fixtures. DR3 (pre-existing snapshot fields written even when retention is off) is noted. Constraints: one-way observations, never read back as stage authority; no admission, return-value or ordering change; bounded memory; nothing retained when retention is off.
- [ ] **Then:** P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → retire CB → FIXTURE slices (each DEFN first confirms the production pipeline reaches its stage) → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV.
  - **CP3-exit conditions (RA-174.3):** RP-01 closed (done); zero ledger rows; design-acceptance matrix gated at 6/6 (Cylinder is required); O14 enforced; O7 resolved; O15 discharged (done); CP3-REV decides selector497 promotion.
- [ ] Carried separately (owners per RA-174.3):
  - **O2b** (retire the public no-atlas APIs, the legacy detail branches, their 12 gated unit tests and the historical suite) → a retirement DEFN after P13. **O16** (row 283, LegacyInteger NFunctionMesher macOS failure, not FMA) → a legacy-backend probe DEFN; not CP3-blocking.
  - O6 (bounded disks that are not rectangular are rejected by design) → P13 probe DEFN.
  - O7 (oracle-tests target does not compile) → its own probe DEFN.
  - O8 (`InvalidFrontBoundaryAuthority` on the 3×3 midline at `lengthRatio=0.29`) and O10 (non-hard isolation-barrier producer) → CP3-exit probe DEFNs after P13.
  - O9 ruled (RA-178.3): kept as accepted-defensive. Falsifier (a produced route with more than one step) → P13 probe DEFN.
  - O12 (R61 `review_check.py` selector collision) → Review tooling.
  - O14 → P8.
  - **O15c** (exact-direction continuation width; fail-closed at 4,096 bits) → P13 probe DEFN. **O15b** (fields-stage `principal_matching` argmin tie; degenerate input only) → CP3-REV.
  - A Linux CI confirmation run of rows 854–859.
  - RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4. G4-B002 exit row is gated; the discharge decision belongs to CP3-REV.
- **Rules:**
  - **Local mode** (implementation agent unavailable): CB and TB run locally with `tools/m6_cp3_local_gate_driver.py`; packages are built at default arithmetic (RA-180.5) and row 283 (O16) is pre-registered.
  - One CB per exact patch; implementation agents get only exact patches and frozen manifests. Probe-requiring DEFN and TB-REV turns stay on the Review track. Every gate run needs `MEMBERSHIP_LEDGER`.
  - **Naming (RA-167.6):** types per `turn_type_from_turn`; DEFN/PLAN IDs carry no `-CB<n>`/`-TB<n>` segment and no final R+letters qualifier.
  - RA-170 (a gate pass says nothing about off-gate tests), RA-171 (self-check every manifest; census rows are OBSERVE), RA-172 (a DEFN needs a reachable exit), RA-174 (verify completeness against the package, not against the gate's own scope), RA-176 (a result that differs by platform is a determinism defect; compute the exact answer before classifying), RA-178 (a test that targets an accepted-defensive guard has no repair exit; witness the guard at its checked factory or retire the test), RA-179 (trace fixture use through helper accessors, not literal grep; confirm per-file flag changes in the built object).
- **Frozen:** stable 66/17/49, debt 1; CP2 491/491 last accepted; TB52 853/0 reviewed Linux candidate; TB57 860/861 latest local candidate (TB54 856/857 reviewed local candidate, RA-181); RP-01 closed; selector497 frozen and unpromoted; Gate C suspended; PR #8 draft and unmerged.
- Completed per-turn task history before 2026-10-31 was pruned at the user's direction; it is in `CHANGELOG.md`, the per-turn records and git history (`TODO.md` at `4a5578fad`).

## Recorded observations (carried from pruned history)

- [ ] `M5-CP3-TB1-R16-REV-OBS-02` — **RECORDED / NOT FIRING.** Rows 446/447 pin inverse canonical storage. If it fires, classify it as test-authority drift and keep the pin.
- [ ] Review guard (`M5-CP3-TB2-REV-OBS-03`): every Review runs `review_check.py ledgers --base <previous-review-commit>` to catch overwritten ledgers (the tracker and CHANGELOG were each overwritten once and restored).
- [ ] M8-CP2 observations recorded in `Architecture_M6_Frozen_Definitions.md`: `M6-CP1-CB12-REV-OBS-01` (the source-row-order scope of the test-only `make_surface_optimization_overlay`, RA-26) and `M6-CP1-TB12-R1-REV-OBS-02` (the adapter drops A7's cross-sheet site, RA-27b).

---

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

- [x] **M4** global conformity plan — **CLOSED / ACCEPTED at `M4-CP4-TB3-REV`**. Final runtime authority is package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**. Closure: `M4_Closure_Record.md`; CP4 closure: `M4_CP4_Closure_Record.md`. M4 handed four periodic/relation debts to M5 and one closed-complex debt to M6; R7 Review discharged two M5 debts and R16 Review discharges the remaining two nonzero-Z4 M5 debts. The sole remaining project debt is the M6 closed-complex subject.
- [x] **M5** certificate-carrying chart/quotient relations — **CLOSED / ACCEPTED at `M5-CP4-TB2-REV`.** Final authority is package/source `10814505512 / e284fea7...` under accepted selector449 **449/449**, SHA `d4a0d1b7...d6414`, owners 32/301/75/41. All §13.1 conjuncts 1-8 are accepted; M6 Definition is frozen and M6-CP1 recovery is now active.
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
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch` (last measured 0/3 at artifact `9031804178`, pre-M1). **M6-DEFN disposition:** the original hard-rail→sheet root is absent from current source (production passes an empty isolation-barrier set). Carried as a direct-production evidence debt to **`M6-CP3`** (strict torus 3/3 re-proof). Unmeasured since then; do not weaken `LocalSheetMismatch`.
- [x] `G4-B002` main exact-torus hard-rail pairing blocker — **CLOSED / RECOVERY PROVED at M4-CP3-TB8-REV** on accepted package `10307919492` / selector408 **408/408**. The three produced-witness debts remain open: one closed-complex debt is M6-owned after DEFN-R2 and two periodic debts are M5-owned after DEFN-R1. This checkbox closes the blocker, not those debt items.
- [x] `G4-B003`: nonzero periodic Z4 production — **DISCHARGED at M5 R16 Review**; both direct-production debts are runtime/review proved.
- [ ] `G4-B004`: positive multi-isolation quotient witness. **M5 producer half ACCEPTED / DISCHARGED at `M5-CP4-TB2-REV`; M6 representative-consumption half OPEN.** Selector449 final authority proves the same-region producer join. `M6-DEFN` item 7 now owns representative exact-once materialization/consumption, embedding and independent verifier proof without weakening or reconstructing the producer fact.
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
