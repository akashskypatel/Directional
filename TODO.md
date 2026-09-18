# Directional Surface-Cell TODO

Last updated: 2026-09-18 UTC

## Latest completed Review — `M4-CP-SCALE-TB12-R7-REV`

R7 Review is **COMPLETE / CB18 FALSIFIED AT DIRECT OWNER GATE / EXISTING RP-01 REFINED / NON-STABLE**. Valid R7 run/job `35326420329 / 105540445909` executes A0 row1 once and REDs `SingularityMismatch;sourceVertex=8`; 435/436 rows remain unexecuted. Review independently localizes the failure to CB18's unsupported equality between the global source-vertex singularity numerator and a per-region relative `BoundaryLoop.turningLift`. The direct CB18 test repeats the same equality, so it is not independent authority for that relation.

Accepted runtime authority remains package `10473134357` / selector426 **426/426**, owners **30/280/75/41**, stable accounting **49 / 14 / 35**, debt **5**. CB18 candidate `10532133889` remains unpromoted and S5/A3 remain uncredited. R6 orchestration recovery is now proved by R7's full generated-runtime/postflight path.

- [x] `M4-CP-SCALE-CB18`: packaged separating-feature owner candidate `10532133889`.
- [x] `M4-CP-SCALE-TB12-R5-EXEC`: orchestration-only failure.
- [x] `M4-CP-SCALE-CB19`: permission-ceiling correction.
- [x] `M4-CP-SCALE-TB12-R6-EXEC`: orchestration-only nounset failure.
- [x] `M4-CP-SCALE-CB20`: nounset harness correction / R7 caller freeze.
- [x] `M4-CP-SCALE-TB12-R7-EXEC`: valid semantic RED at A0 row1.
- [x] `M4-CP-SCALE-TB12-R7-REV`: root-cause = CB18 cross-domain equality, existing `RP-01`.
- [ ] `M4-CP-SCALE-CB21`: **exact next**. Compile/package-only correction of separating-owner eligibility plus independent mismatch discriminator. No generated Directional runtime.

## Current focus — `M4-CP-SCALE-CB21`

Change only `src/authority/FieldTransportAtlas.cpp` and `tests/FieldTransportAtlasTests.cpp` semantically. Separating-feature ownership must be based on source-topology incidence and actual boundary-loop containment, then canonicalized by stable `(TopologyRegionId, FieldCycleId)`. Remove the boundary-loop-lift/global-singularity-index equality from production and the shared test oracle. Preserve the raw numerator as the singularity's numeric fact, `BarrierAbsorbed`, zero origin ports, exact owner exclusivity, same-region slit semantics and source-boundary semantics.

The direct control must independently establish a valid separating-owner case where the relative boundary-loop lift differs from the global target singularity numerator; restoring the old equality must make the control fail. Preserve source topology, cycle ordering, retained genus-two bytes/S5, selector426 and CMake/benchmark semantics. Compile/package under GMP/GMPXX with `runtimeExecution=false`; if green, freeze only a later fresh R8 artifact-only plan.

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

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND CLOSED + ACCEPTED / CP-SCALE S2 + S3 + S4 CUMULATIVE ACCEPTED / CHECKPOINT OPEN**. Accepted runtime authority remains TB11 package `10473134357` / selector426 **426/426**. R7 Review falsifies CB18 at the direct separating-owner gate and refines the existing RP-01 authority-domain defect; exact next is compile/package-only CB21. S5 remains unaccepted and three `G4-B002` debts remain CP4 gating.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. M4-CP3 and M4-CP-COND are CLOSED / ACCEPTED. `M4-CP-SCALE-TB11-REV` remains accepted runtime authority at package `10473134357` / selector426 **426/426**. CB18 candidate `10532133889` / source `079933f2ec31a9323218e73c7ae0d3ea1d11103c` remains compile/package GREEN and unpromoted. R7 is valid semantic evidence: Gate A0 row1 REDs `SingularityMismatch;sourceVertex=8`; Review classifies the cause as CB18's unsupported global-source-index/per-region-boundary-lift equality, a refinement of existing product `RP-01 / AUTHORITY_DOMAIN_CONFLATION`, not a new stable root cause. R6 is CLOSED / orchestration recovery proved / non-stable. CP-SCALE remains OPEN: S1 is diagnostic/non-gating pending calibration, S2 arrival remains blocked, and S5 remains uncredited. Exact next is compile/package-only **`M4-CP-SCALE-CB21`**, limited to separating-owner eligibility plus an independent mismatch discriminator; no generated Directional runtime or selector427 is authorized. PR #8 remains open, draft, and unmerged.
