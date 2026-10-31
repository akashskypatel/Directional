## CURRENT — CB64 Linux compile/package verified; TB63 full gate and P13 census next (2026-10-31)

- [x] Done (records in `.agents/Directional/`, history in `CHANGELOG.md`): RP-01 closure (RA-174…[RA-179](.agents/Directional/Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) → O15 (RA-180, CB55, TB54, [RA-181](.agents/Directional/Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md)) → row 935 (RA-182, CB56, TB55) → O2 entry gate ([RA-183](.agents/Directional/Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md), CB57, TB56) → **DIAG-RETAIN** ([RA-184](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md), [RA-185](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md), [RA-186](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md), [RA-187](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md); CB58–CB61, last source `e1fd0e4b…`). TB57–TB60 ran on macOS arm64 only; the latest, TB60, gave **862/863** on the TB58 manifest (863 rows; only row 283, O16), membership 945. TB59 ran only CLI cases; TB60 is the full-gate TB for both CB60 and CB61 (RA-187.1).
- [x] **Independent Linux TB61 full-gate review of CB58–CB61; owner authorized exact Linux CLI/GUI successor** (user direction, 2026-10-31; handoff step 1):
  - [x] `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE`: no source patch; Linux Release/static GMP/GMPXX eight-target package artifact `13034987618` from `e7c27b0a5f53…` (record: [CB62](.agents/Directional/Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md)).
  - [x] `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC`: verified Linux run `41182654107`, CB62 package `13034987618`, source `e7c27b0a…`, TB58 manifest 863, ledger v4 82, **863/863 PASS**, membership 945, row 283 PASS; [TB61 execution report](.agents/Directional/Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). No new Linux regression; stable accounting unchanged.
  - [x] **`M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` evidence adjudication:** independent artifact/manifest/log/package audit 863/863; Linux CLI/GUI switches both OFF in CB62. [Review report](.agents/Directional/Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md).
  - [x] **Owner authorization 2026-10-31:** exact next `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` selected; [compile plan](.agents/Directional/Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md) governs Linux CLI+GUI GMP/GMPXX compile evidence. Full-history `review_check.py boundary` and `ledgers` passed on unshallow GitHub run 41200958419.
  - [x] **`M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE`:** Linux Release/static ten-target compile/link, CLI/GUI ON, GMP/GMPXX generated links; source `f6113c4e…`, [run 41202931582](https://github.com/akashskypatel/Directional/actions/runs/41202931582), artifact `13043004468` (30/30 verified); [report](.agents/Directional/Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md). No runtime.
  - [x] **`M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC`:** immutable CB63 Linux ten-target package `13043004468` (`f6113c4e…`), [run 41205693716](https://github.com/akashskypatel/Directional/actions/runs/41205693716), result `13046191343`: **863/863 PASS**, 82 DEFERRED, membership945, 1,734/1,734 result hashes, postflight true; 11/11 registered Linux CLI checks and GUI link evidence with no GUI launch, zero rebuild. [TB62 report](.agents/Directional/Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Report_20261031.md). No new Linux regression; macOS O16 separate.
- [x] **`M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`** (Review/Definition): independently re-audited TB62 863/863 and CB63 30/30; ruled runtime probes cannot execute within a DEFN despite 'probe-capable' handoff; froze separate CB→TB observation without modifying 863-case gate, v4 82 ledger or design acceptance. [P13 decision](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Decision_20261031.md).
- [x] **[RA-188](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md) `M6-CP3-DEFN-P13-PROBE-ADJUDICATION`** (DEFN, Review, scratch probes on current source):
  - It upholds the P13 audit, but the decision planned on stale pre-CB55 dispositions and skipped the Review probes (RA-166.6 F6). Its CB64-REGISTRATION (a 300 s harness edit) and TB63-CYLINDER-FIRST are withdrawn.
  - **P13-a, Cylinder:** PASS in 182 s. 96% of that time is O(F) `matches_source_faces` re-validation inside `SourceChartTransitionGraph::available()`. With the fix it runs in 7.8 s with byte-identical output.
  - **P13-b, Vase:** A4 `BranchContinuationExactMagnitudeExceeded`. The exact width grows about 200 bits per step and fails at step 21. This is the O15c trigger, and it is architectural.
  - **P13-c, BunnyRandom:** A3 `CutTransportDomainIdentityMismatch`. Two tip–tip single-edge barrier arcs cannot be slit under DESIGN Amendment 15.3.
  - The patch probe gate gives 862/863 (only O16 row 283).
- [x] **`M6-CP3-CB64-P13-CHART-BINDING-CACHE`** (CB; implementation agent; Linux).
  - The RA-188.8 exact patch: SHA `fad8986c…`, numstat `7 4` and `2 2`. It caches the build-time source binding in `available()` and adds `detail=` to the design-acceptance `failure_context`.
  - Exact two-file patch committed as `d56d990580163f4fd0ceda4137f7ecd16ceb6027`; Linux eight-target compile [run 41221202501](https://github.com/akashskypatel/Directional/actions/runs/41221202501), artifact `13050072901`, 28/28 checksums, GMP/GMPXX, no runtime. [CB64 report](.agents/Directional/Architecture_M6_CB64_Chart_Binding_Code_Build_Continuation_20261031.md).
- [ ] **NEXT `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC`** (TB-EXEC; implementation agent; Linux).
  - The gate: TB58 manifest 863 with ledger v4 82, pre-registered 863/863, membership 945.
  - The census: `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` (`3af1dc0d…`, three OBSERVE rows, no ledger). Pre-registered: Cylinder PASS; BunnyRandom RED `CutTransportDomainIdentityMismatch` `cutChi=-3`; Vase RED `detail=BranchContinuationExactMagnitudeExceeded`.
  - If both match → the P13-b DEFN, with no TB-REV. Anything else → `M6-CP3-TB63-P13-CENSUS-FULL-GATE-REV`.
- [ ] **Review track** (probe DEFNs; may run during CB64/TB63):
  - **`M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH`** (Vase). Choose a bounded continuation policy: a revised bound, a rounded direction, or a canonical dyadic exit parameter with exact predicates on the rounded values (RA-188.3). It also promotes Cylinder to the gate (manifest 864, ledger v5 81) → CB65 → TB64.
  - **`M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT`** (BunnyRandom). Amend DESIGN Amendment 15 for tip–tip arcs, either by changing the representation or by a typed rail policy → CB66 → TB65.
  - Then re-census P13, take O6/O9 where they are reached, and aim for matrix 6/6.
- [x] **DIAG-RETAIN (user-directed, 2026-10-21): closed** by CB58–CB61 (snapshots, display adapter and dump, CLI sidecar, GUI layers). Open: DR1 (no in-helper A6/A7 rejection witness; waits for a stimulus), DR3 (pre-existing snapshot fields written when retention is off). DR2 (multi-component snapshot drop) and DR4 (`--diagnostics-prefix` cut sidecars throw on SurfaceCells products, `src/cli/RemeshOutput.cpp:388–392`) → M8-CP2. The GUI layers' appearance is a manual check.
- [ ] **Then:** retire CB → FIXTURE slices (each DEFN first confirms the production pipeline reaches its stage) → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV.
  - **CP3-exit conditions (RA-174.3):** RP-01 closed (done); zero ledger rows; design-acceptance matrix gated at 6/6 (Cylinder is required); O14 enforced; O7 resolved; O15 discharged (done); CP3-REV decides selector497 promotion.
- [ ] Carried separately (owners per RA-174.3):
  - **O2b** (retire the public no-atlas APIs, the legacy detail branches, their 12 gated unit tests and the historical suite) → a retirement DEFN after P13. **O16** (row 283, LegacyInteger NFunctionMesher macOS failure, not FMA) → a legacy-backend probe DEFN; not CP3-blocking.
  - O6 (bounded disks that are not rectangular are rejected by design). No P13 fixture reaches it at current source (RA-188.2) → P13 re-census.
  - **O17** (production code writes diagnostics to stderr unconditionally: `GlobalTopologyPlan.cpp:2634`, `FieldTransportAtlas.cpp:746`) → M8-CP2.
  - O7 (oracle-tests target does not compile) → its own probe DEFN.
  - O8 (`InvalidFrontBoundaryAuthority` on the 3×3 midline at `lengthRatio=0.29`) and O10 (non-hard isolation-barrier producer) → CP3-exit probe DEFNs after P13.
  - O9 ruled (RA-178.3): kept as accepted-defensive. Falsifier (a produced route with more than one step) → P13 re-census, once Vase or BunnyRandom reaches A4 routes.
  - O12 (R61 `review_check.py` selector collision) → Review tooling.
  - O14 → P8.
  - **O15c** has fired on Vase (RA-188.2) → `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH`. **O15b** (fields-stage `principal_matching` argmin tie; degenerate input only) → CP3-REV.
  - RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4. G4-B002 exit row is gated; the discharge decision belongs to CP3-REV.
- **Rules:**
  - CB and TB run on the Linux workflow runner. A TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187); the current gate is the TB58 manifest (863 rows) with ledger v4 (82).
  - One CB per exact patch; implementation agents get only exact patches and frozen manifests. Probe-requiring DEFN and TB-REV turns stay on the Review track. Every gate run needs `MEMBERSHIP_LEDGER`.
  - **Naming (RA-167.6):** types per `turn_type_from_turn`; DEFN/PLAN IDs carry no `-CB<n>`/`-TB<n>` segment and no final R+letters qualifier.
  - RA-170 (a gate pass says nothing about off-gate tests), RA-171 (self-check every manifest; census rows are OBSERVE), RA-172 (a DEFN needs a reachable exit), RA-174 (verify completeness against the package, not against the gate's own scope), RA-176 (a result that differs by platform is a determinism defect; compute the exact answer before classifying), RA-178 (a test that targets an accepted-defensive guard has no repair exit; witness the guard at its checked factory or retire the test), RA-179 (trace fixture use through helper accessors, not literal grep; confirm per-file flag changes in the built object).
- **Frozen:** stable 66/17/49, debt 1; CP2 491/491 last accepted; TB52 853/0 reviewed Linux candidate; TB60 862/863 latest macOS candidate; TB62 863/863 latest independently reconciled Linux full-gate candidate (ten-target scope); TB61 prior eight-target candidate (TB54 856/857 reviewed macOS, RA-181); RP-01 closed; selector497 frozen and unpromoted; Gate C suspended; PR #8 draft and unmerged.
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
