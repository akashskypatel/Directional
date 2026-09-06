# Directional Surface-Cell TODO

Last updated: 2026-09-06 UTC

## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Closed milestone/checkpoint history lives in `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, and `M3_CP4ab_Closure_Record.md`. Exact runtime evidence lives in `CHANGELOG.md`, the current retained turn report, and `Regression_Root_Cause_Tracker.md`. Normative architecture lives in `DESIGN.md`; the checkpoint map to production-ready lives in `ROADMAP.md`; migration ordering lives in `REORIENTATION_PLAN.md`.

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

## Current focus — `M3-CP4c-3-TB33-EXEC` (artifact-only runtime)

`M3-CP4c-3-CB38` is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE**. Current semantic runtime authority remains
TB32 until TB33-REV adjudicates new evidence.

- TB32 selector **408**, **397 PASS / 11 RED**, accepted **365/365**, RED
  `366,367,368,369,370,374,390,393,398,406,407`; ownership **300 / 0 / 0**.
- CB38 semantic source `0d03edb07388c56b592a74e2e7fc5f3edde8cea4`.
- CB38 compile run/job `34052395109 / 101538234734`; immutable artifact `9994997588` /
  `m3-cp4c3-cb38-result-34052395109`, SHA-256
  `059f40350b0acdc885e77523668ff6b50708fc802d910b257ba278d54444f8d8`; source archive
  `092b3a5b81894ce15d1c767d41399fc72e65cd72f2400c0e7ff4c6970300c0e0`; manifest **28/28 PASS**; GMP/GMPXX;
  `runtimeExecution=false`.
- Selector 408 remains byte-identical at
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`; package count **98**.

CB38 implemented CT3–CT6: typed region-frontier stage evidence, no later-stage back-fill into legacy seed fields,
a justified cleared-stage branch for 390/393/406/407, per-row failure-detail fingerprints beside the unchanged
ledger columns, and a parameterized artifact harness that records the executing run. CT7 is frozen into the TB33 plan.

### Exact next turn

Run **`M3-CP4c-3-TB33-EXEC`** under
`Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md` on immutable artifact `9994997588`.

- [ ] Execute all **408** selector identities exactly once through the packaged parameterized harness; accepted
      **1–365 = 365/365 PASS**, zero selection mismatches/timeouts.
- [ ] Require **390/393/406/407 PASS** under the justified cleared-stage contract.
- [ ] Verify later-stage frontier evidence is labelled `RegionConstruction`/`RegionCertification`, complete, and
      publishes **no** legacy `uncutFaceComponent*` seed fields.
- [ ] Require zero emissions of `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique`.
- [ ] 366/367 must not move earlier than `RegionBoundaryNotSingleWalk`; preserve any later movement exactly.
- [ ] Preserve 368/369/370/374/398 as credibility surfaces; any unexpected colour/locus change is review evidence.
- [ ] Verify `baseline-authority.txt` names the **executing TB33 run** and failure-detail files/digests cover all rows.
- [ ] **CT7:** transcribe the exact retained failing assertion/exception text for every RED ordinal in the focused
      index. Missing transcription makes the EXEC report incomplete.
- [ ] Verify package/source/execution-view byte+mode postflight equality and all configure/compile/relink/repair/
      discovery/benchmark/mutation flags false.
- [ ] Update `Regression_Root_Cause_Tracker.md` for every observed regression/candidate before TB33-EXEC closes.
- [ ] After EXEC closeout, stop the loop at **independent `M3-CP4c-3-TB33-REV`**.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**. CP4c-3 remains
**OPEN**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted.
  CP4c-3 remains open. **TB32 remains semantic runtime authority** at 397 PASS / 11 RED, accepted 365/365.
  CB38 is compile-green on immutable artifact `9994997588` / source
  `0d03edb07388c56b592a74e2e7fc5f3edde8cea4`; no CB38 runtime executed. Exact next:
  **`M3-CP4c-3-TB33-EXEC`**, artifact-only runtime under the frozen TB33 plan.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 region-frontier runtime proof:** source-face ownership is closed at last-runtime **300 / 0 / 0**.
  CB38 implements CT3–CT6 stage/evidence/harness corrections at source
  `0d03edb07388c56b592a74e2e7fc5f3edde8cea4`. Exact next is TB33-EXEC on artifact `9994997588`; runtime must
  prove 390/393/406/407 under the justified cleared-stage contract, preserve retired-code silence and accepted
  365/365, and show 366/367 do not move earlier than `RegionBoundaryNotSingleWalk`.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. TB8 repeated this pre-classified stop; it adds no new product evidence.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; downstream of A2b and not a CP4c witness collision.
- [ ] `G4-B002`: exact torus `InvalidHardRailPairing`; revised M4.
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

Current totals are **44 events / 14 categories / 30 recurrences**, classified at `M3-CP4c-3-TB32-REV` with no stable change. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **98**. **`M3-CP4c-3-TB32` is the current valid semantic runtime authority at 397 PASS / 11 RED, accepted 365/365 on selector 408, with ownership total at 300/300 and both retired failure codes absent from all 408 logs.** Exact next is `M3-CP4c-3-TB33-EXEC` on immutable CB38 artifact `9994997588`; stop at independent TB33-REV. PR #8 remains open, draft, and unmerged.
