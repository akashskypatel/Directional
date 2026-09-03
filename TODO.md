# Directional Surface-Cell TODO

Last updated: 2026-09-03 UTC

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

## Current focus — `M3-CP4c-3-TB18` (Test + Benchmark, ARTIFACT-ONLY)

`M3-CP4c-3-CB20` is **COMPLETE / DIAGNOSTIC-ONLY / COMPILE GREEN / RUNTIME NOT EXECUTED**. Report:
`Architecture_M3_CP4c3_CB20_Code_Build_Report.md`. Frozen successor:
`Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md`.

CB20 semantic/evidence source is **`57635e87306a416daabb8321e1f36fa9c788d208`**. Selector 382 remains
byte-identical at **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`**. Selector 383 is exactly
that 382-line prefix plus `GlobalTopologyPlan.TraceCutFaceFragmentMismatchDiagnosticsSurviveProductionFailureProjection`,
SHA-256 **`a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`**.

CB20 adds diagnostic-only actual/expected/`tracePieceCount`, bounded per-chord incidence with both face-walk orbit ids
and exterior-drop flags, three-edge orbit evidence, and failing-path `fragment_reconciliation`, all projected through
the production error locus. The comparison, counts, orbit/filter rules, terminal-slit rule, carrier-less binding,
fragment incidence and region construction are unchanged. No Directional runtime, test, benchmark, discovery or
generated binary executed in CB20.

### Exact next turn

Run **`M3-CP4c-3-TB18`** exactly as frozen in
`Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md`.

- [ ] Verify the immutable CB20 compile artifact, exact source commit, SHA-256 manifest, GMP/GMPXX evidence, selector
      383 hash and exact 382 prefix **before runtime**. No repair/rebuild.
- [ ] Execute all 383 selector identities in ordinal order, one identity per fresh process; no generated discovery.
- [ ] Prove accepted ordinals 1–365 remain **365/365 PASS**.
- [ ] Prove ordinal 366 still reds at `TraceCutFaceFragmentCountMismatch`, source face `(0,1,102)`. Any movement
      falsifies CB20's no-semantic-change boundary.
- [ ] Publish exact actual/expected/`tracePieceCount` and classify mismatch direction only; do not prescribe a fix.
- [ ] Publish the bounded per-chord incidence, both orbit ids/exterior-drop flags, three-edge orbit evidence and
      failing-face `fragment_reconciliation` record.
- [ ] Confirm carried surfaces 367/368/369/370/371/372/374 remain under their existing owners.
- [ ] Require pre/post artifact byte+mode census identity; all build/repair/source/test/fixture/selector/benchmark
      mutation flags false.
- [ ] Update the tracker/report/handoff, then route to **`M3-CP4c-3-TB18-REV`**.

**No product correction is authorized in TB18.** Accepted semantic authority remains **365/365**; CP4c-3 remains
**OPEN**. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**;
authoritative semantic M3 package count **84**.
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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB17/package87 remains current runtime authority** at 374 PASS / 8 RED and accepted 365/365. CB20 diagnostic source `57635e87` is compile-green and unexecuted. Exact next is artifact-only `M3-CP4c-3-TB18`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — face-fragment orbit/count frontier:** TB17 proves accepted 365/365 and first-reds at `TraceCutFaceFragmentCountMismatch` on `(0,1,102)`. TB17-REV proved the owner class but not the corrective contract; CB20 now compiles the mandatory diagnostic-only counts/incidences without changing semantics. `M3-CP4c-3-TB18` must measure mismatch direction and retained incidence before TB18-REV adjudicates any correction. Vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (deferred, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor, which throws unless all five downstream products are retained. Amendment 15's barrier-cycle and Euler-cut contracts have been unmeasured from TB2 through TB10 for a reason unrelated to either. Corrective is test-only (an atlas-scoped fixture accessor, assertions byte-unchanged); deferred because clearing ordinal 366 unblocks them automatically. `M3-CP4c3-TB10-REV-CAND-01`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **84**. **TB17/package87 remains current runtime authority: 374 PASS / 8 RED, accepted 365/365, first red 366 `TraceCutFaceFragmentCountMismatch` at `(0,1,102)`. CB20 diagnostic source `57635e87` is compile-green and unexecuted.** Exact next is artifact-only `M3-CP4c-3-TB18`. PR #8 remains open, draft, and unmerged.
