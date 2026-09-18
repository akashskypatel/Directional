# Directional Surface-Cell TODO

Last updated: 2026-09-18 UTC

## Latest completed Test + Benchmark — `M4-CP-SCALE-TB12-R8-EXEC`

R8 is **COMPLETE / VALID SEMANTIC RED / FAIL-FAST AT A0 ROW1 / NON-STABLE**. Immutable CB21 artifact `10542249210` / source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1` passes exact package/source/GMP/mode/selector/fixture preflight. Run/job `35338412117 / 105578569562` executes `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` exactly once and fails at `FieldTransportAtlasTests.cpp:2666` with `SingularityPortClassCountMismatch;sourceVertex=16;topologyRegion=1`; diagnostics show `incidences=4`, `classes=4`, `expectedClasses=5`.

Fail-fast leaves **435/436 UNEXECUTED**: Gate A0 0 PASS / 1 RED / 4 unexecuted, Gate A 0/4, S5 0/1, selector426 0/426, benchmark 0. Exact package/source/execution-view postflight passes; result/log artifacts are `10543544280 / 10544295647`; final ledger SHA-256 `a9aea1a0ba92f6889f2c50268c34b29b71c643e23a3a20ba8ff2844986b573e2`.

- [x] `M4-CP-SCALE-CB21`: bounded owner-eligibility correction + independent mismatch/canonicalization controls, compile/package GREEN.
- [x] `M4-CP-SCALE-TB12-R8-EXEC`: valid row1 semantic RED at the later port-class-count seam; 435 rows unexecuted by fail-fast.
- [ ] `M4-CP-SCALE-TB12-R8-REV`: **exact next**. Independently classify the boundary advance, CB21/RP-01 recovery status, port-class-count semantics, evidence sufficiency and third-distinct-product-root-cause stop before any corrective CB.

## Current focus — `M4-CP-SCALE-TB12-R8-REV`

Review immutable R8 result `35338412117 / 105578569562` against candidate `10542249210` without compile or generated runtime. Re-derive package/harness/result provenance, confirm the direct test's independent mismatch precondition precedes atlas construction, compare R7 `SingularityMismatch;sourceVertex=8` with R8 `SingularityPortClassCountMismatch;sourceVertex=16;topologyRegion=1`, and inspect the class-count product contract before assigning product/test/orchestration classification or stable accounting.

Review alone may decide whether CB21 recovery-proves the prior `RP-01` owner-domain seam, whether the new RED is a distinct product cause or existing recurrence, and whether the frozen third-distinct-product-root-cause definition stop fires. No retry, corrective implementation, package promotion, selector427 publication or S5/A3 credit is authorized before Review.

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

- [ ] **M4** global conformity plan — **CP1/CP2 historical framed closures retained / CP3 CLOSED + ACCEPTED / CP-COND CLOSED + ACCEPTED / CP-SCALE S2 + S3 + S4 CUMULATIVE ACCEPTED / CHECKPOINT OPEN**. Accepted runtime authority remains TB11 package `10473134357` / selector426 **426/426**. CB21 candidate `10542249210` / source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1` is compile/package GREEN under GMP/GMPXX with the R7 RP-01 equality removed and independent mismatch/canonicalization controls compiled. Exact next is artifact-only `M4-CP-SCALE-TB12-R8-EXEC`; S5 remains unaccepted and three `G4-B002` debts remain CP4 gating.
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

Current totals are **49 events / 14 categories / 35 recurrences**, debt **5**. M4-CP3 and M4-CP-COND are CLOSED / ACCEPTED. `M4-CP-SCALE-TB11-REV` remains accepted runtime authority at package `10473134357` / selector426 **426/426**. CB21 candidate `10542249210` / source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1` is compile/package GREEN with the R7 cross-domain owner equality removed; it is not runtime-promoted. R7 remains valid semantic evidence for existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; R6 is CLOSED / orchestration recovery proved / non-stable. CP-SCALE remains OPEN: S1 is diagnostic/non-gating pending calibration, S2 arrival remains blocked, and S5 remains uncredited. Exact next is immutable artifact-only **`M4-CP-SCALE-TB12-R8-EXEC`** under the frozen 436-row fail-fast plan; benchmark 0 and selector427 remains forbidden. PR #8 remains open, draft, and unmerged.
