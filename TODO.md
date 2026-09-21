# Directional Surface-Cell TODO

Last updated: 2026-09-21 UTC

## Latest Review turn — `M5-CP3-TB1-R6-REV`

`M5-CP3-TB1-R6-REV` remains the latest independent Review: R6 is mechanism **9/9 PASS**, focused atlas **1/1 PASS**,
produced **0/6 PASS**, selector430 **429/430 PASS** with sole RED ordinal408, and all six produced rows stop at
`PeriodicGeneratorRouteUnavailable`. Review proved the A3 occurrence-owned source-face / A4 endpoint-face
authority conflation as continuation of the existing stable `RP-01` event and froze CB8. Its direction-orientation
addendum `M5-CP3-TB1-R6-REV-OBS-01` remains open for R7 Review.

## Latest Test + Benchmark turn — `M5-CP3-TB1-R6-EXEC`

R6 run/job `35606326632 / 106354249393` consumes CB7 candidate `10637998372` and executes all 446 fresh exact-filter
processes. Result/log artifacts `10642347642 / 10642362744`; self-manifest **914/914**. Vector is 9/9 mechanism
PASS, 1/1 focused PASS, 0/6 produced PASS, selector430 429/430 with sole RED ordinal408. All six produced rows are
`PeriodicGeneratorRouteUnavailable`; protected ordinals 191/192/247 remain PASS.

## Latest Code + Build turn — `M5-CP3-CB8`

CB8 is **COMPLETE / STATIC GREEN / GMP COMPILE-PACKAGE GREEN / RUNTIME-FREE**. Semantic patch
`31d437a0864f99cb44d06430e0faa85c57c862be` changes only `src/geometry/SurfaceCellTracing.cpp`: exact accepted A3
boundary occurrences now retain their `AcceptedCutBoundarySegment::sourceFace`, generator-route transition queries
resolve the directed face pair from that authority, and the pair is validated against carrier `sourceEdgeFaces` as
an unordered set without using storage order for direction. No atlas/traversal/action/relation/test/selector
semantics changed.

Compile run/job `35623934990 / 106413580650` builds all eight mandatory GMP/GMPXX targets from exact source
`baae6307d189639fdf7d8a0011f5ba5f30de1631` with `runtimeExecution=false`. Candidate/log artifacts are
`10651055588 / 10651435428`; candidate SHA-256 is
`376f61120b4a71dd9747daae8c248fe766bbf899faac0e2f336fc97e57acda96`, package manifest **28/28**. Candidate is
unpromoted; accepted runtime authority and stable accounting remain unchanged.

## M5 checkpoint sequence

- [x] `M5-CP1` and `M5-CP2`: CLOSED / ACCEPTED for mechanism credit; accepted package `10601978228`.
- [x] `M5-CP3-CB2` through `R5-REV`: bounded recovery falsifiers localize the open stable ordinal408 `RP-01` event while four produced debts remain open.
- [x] `M5-CP3-CB7`: typed diagnostic branch cutover compile/package green, runtime-free.
- [x] `M5-CP3-TB1-R6-EXEC`: all six produced REDs dynamically localize to `PeriodicGeneratorRouteUnavailable`; 191/192/247 remain green.
- [x] `M5-CP3-TB1-R6-REV`: R6 evidence upheld; exact A3 occurrence-owned source-face authority versus A4 endpoint-face substitution proved causal; CB8 frozen.
- [x] `M5-CP3-CB8`: occurrence-owned source-face correction implemented; all eight mandatory GMP targets compile/package green; no runtime.
- [ ] `M5-CP3-TB1-R7-EXEC`: **exact next**; immutable candidate `10651055588`, unchanged 446-process artifact-only gate, benchmark 0. Primary falsifier: no produced row may remain `PeriodicGeneratorRouteUnavailable`.
- [ ] `M5-CP3-TB1-R7-REV`: mandatory independent Review; also adjudicates the open direction-orientation observation before promotion/debt/selector credit.

## Current focus — `M5-CP3-TB1-R7-EXEC`

Execute `Architecture_M5_CP3_TB1_R7_Artifact_Only_Test_Benchmark_Plan.md` exactly. Consume candidate
`10651055588` immutably, preserve package modes/bytes, execute 9 mechanism + 1 focused atlas + 6 produced + all
430 selector rows as fresh exact-filter processes, and run **zero benchmarks**. Do not configure, compile, relink,
repair, repackage, mutate tests/fixtures/selector, or perform same-turn semantic repair. Any RED routes to mandatory
R7 Review; full green also routes to R7 Review before promotion.

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
- [ ] **M5** certificate-carrying chart/quotient relations — **CP1 + CP2 CLOSED / ACCEPTED; CP3 CB8 COMPILE-PACKAGE GREEN / R7 EXEC NEXT**. Accepted runtime package remains `10601978228`. CB8 candidate `10651055588` / source `baae6307d...` is compile/package green, runtime-unadjudicated and unpromoted; all eight mandatory GMP/GMPXX targets built with `runtimeExecution=false`. R6 remains latest runtime evidence at mechanism 9/9 PASS, focused atlas 1/1 PASS, produced 0/6 PASS, selector430 429/430 PASS with sole RED ordinal408. Stable accounting remains **50 / 14 / 36**, debt **5**; four M5 debts remain open and selector publication is prohibited. Exact next `M5-CP3-TB1-R7-EXEC`.
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

Current corrected totals are **50 events / 14 categories / 36 recurrences**, debt **5**. M4, M5-CP1 and M5-CP2 are **CLOSED / ACCEPTED**; current accepted runtime authority remains package `10601978228` / source `0798547d...` under unchanged selector430 **430/430**. CB7 candidate `10637998372` / source `8f77ec403f...` is compile/package green, runtime-unadjudicated and unpromoted; R5 remains the latest semantic evidence at mechanism 9/9 and focused atlas 1/1 green, selector430 429/430 with sole RED 408, produced 0/6. R4 non-stable atlas-oracle drift is recovered; the existing R1 stable `RP-01` recurrence remains open pending R6 typed branch proof. The closed-complex `G4-B002` debt remains M6-owned; two periodic `G4-B002` plus two `G4-B003` debts remain M5-owned. Selector publication remains prohibited. Exact successor is **`M5-CP3-TB1-R6-EXEC`**. PR #8 remains open, draft, and unmerged.
