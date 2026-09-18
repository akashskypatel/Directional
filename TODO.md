# Directional Surface-Cell TODO

Last updated: 2026-09-18 UTC

## Current turn — M4-CP-SCALE-TB12-R3-REV (closeout)

Independent Review upholds TB12-R3 Gate-A mechanics but rejects the fourth control as product evidence. `BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport` supplies an all-zero component/sheet source authority with **empty hard-feature edges** on a connected closed genus-two source, then requires a `BoundaryLoop`; production S5 instead derives hard-feature edges from authoritative rails and uses production source labels. This is `M4-CP-SCALE-TB12-R3-EXEC-CAND-01`, **OPEN / RP-02 TEST-AUTHORITY INVALID PRECONDITION + AUTHORITY-SURFACE DIVERGENCE / NON-STABLE**.

- [x] `M4-CP-SCALE-TB12-R2-REV`: multi-component algebraic support / single-loop atlas owner proved.
- [x] `M4-CP-SCALE-CB16`: all closed support components consumed canonically; independent component decomposition/tamper controls added; eight-target GMP compile/package GREEN; no runtime.
- [x] `M4-CP-SCALE-TB12-R3-EXEC`: artifact-only Gate A **3/4**; invalid synthetic genus-two atlas control RED; Gate B/selector426/benchmark not executed.
- [x] `M4-CP-SCALE-TB12-R3-REV`: Gate-A #4 classified test-authority divergence; CB16 not falsified; production retry still owed.
- [ ] `M4-CP-SCALE-CB17`: **exact next**. Test-only repair: restore/adapt an independently preconditioned synthetic boundary row with at least two closed successor components; compile/package only, no runtime.

## Current focus — `M4-CP-SCALE-CB17`

Accepted runtime authority remains package `10473134357` / selector426 **426/426**, owners **30/280/75/41**, stable accounting **49 / 14 / 35**, debt **5**. Candidate artifact `10523132151` remains unpromoted. `M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains **OPEN / RP-07 / production S5 retry + Review owed / NON-STABLE** because TB12-R3 fail-fast prevented the post-CB16 production path from executing.

CB17 may modify only `tests/FieldTransportAtlasTests.cpp` semantically. Product source, S5, retained genus-two fixture/rawfield/metadata, selector426 and selector427 state are frozen. The replacement integration control must prove its multi-component `BoundaryLoop` support independently **before** atlas construction; the preferred bounded witness is the former `make_two_interior_islands_disk()` / 6-support / 2-component case adapted to the current canonical-component oracle.

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

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND CLOSED + ACCEPTED / CP-SCALE S2 + S3 + S4 CUMULATIVE ACCEPTED / CHECKPOINT OPEN**. Accepted runtime authority remains TB11 Review package `10473134357` / selector426 **426/426**, owners **30/280/75/41**. CB16 candidate `10523132151` remains unpromoted: TB12-R3 proves three direct multi-component ordering/oracle controls but the frozen synthetic genus-two atlas control is RED at `CycleTransportMismatch;topologyRegion=0`, so S5 and selector426 did not run. Exact next is runtime-free `M4-CP-SCALE-TB12-R3-REV`. S1 remains diagnostic/non-gating, S2 arrival remains blocked, S5 remains unaccepted, and CP4 later discharges the 3 `G4-B002` debts before M4 closes.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. M4-CP3 and M4-CP-COND are CLOSED / ACCEPTED. `M4-CP-SCALE-TB11-REV` remains accepted runtime authority at package `10473134357` / selector426 **426/426**. Retained S5 genus-two topology is proved; `M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains OPEN / REVIEW REQUIRED / NON-STABLE. CB16 candidate artifact `10523132151` / source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9` remains unpromoted: TB12-R3 Gate A is **3/4**, with the synthetic genus-two atlas control RED at `CycleTransportMismatch;topologyRegion=0`; Gate B and selector426 were not executed. CP-SCALE remains OPEN: S1 is diagnostic/non-gating pending calibration, S2 arrival remains blocked, and S5 remains uncredited. Exact next is runtime-free Code + Build **`M4-CP-SCALE-CB17`**. PR #8 remains open, draft, and unmerged.
