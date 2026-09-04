# Directional Surface-Cell TODO

Last updated: 2026-09-04 UTC

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

## Current focus — `M3-CP4c-3-DEFN-R3` (DEFN; absorbs REVIEW + PLAN)

`M3-CP4c-3-TB23-R1-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` (**CE0–CE8** discharged, static only).

**The harness correction is confirmed and the ownership question is proved unanswerable.**

- **`M3-CP4c3-TB23-REV-CAND-02` CLOSES / RUNTIME PROVED.** The corrected harness staged the execution view and
  verified it through the consumer's own resolution rule; accepted returned to **365/365**, confirming the invalid
  attempt's 38 accepted-prefix failures were fixture-open failures. First use of the new
  `TB (orchestration-invalid) -> CB (control-plane correction) -> TB (re-execute)` routing, and it worked end to end.
- **Both new REDs are the new witnesses working, not product regressions.** Ordinal **393** (production) REDs on
  `m3Cp4c3CA3;examined=273;differing=0;witnessCount=64;truncated=true` and on `certifiedFaceDiffersFromSeed`, while
  ordinal **396** (unit) PASSES - the "can versus does" split CA6 was written to create. Ordinal **397** REDs on a
  **genuine defect**: CB25 appended `;cutCandidateCount=0` to the rendered locus of an **unrelated** error.
- **CA2 is discharged; CA1 is not.** Both sides are now filled by separate accessor calls (`:1365-1370`), so
  CB24's aliasing is gone. But the edge-side path writes `walk.orbitByDart[dart]` (`:487, :502-503`) - the same
  quantity `edgeOrbitEvidence` records - so every available labeled certified face **equals its seed**.
- **All 191 component certified faces are `unavailable`.** `resolve_certificate_face_projection` assigns an owner
  only when a component's certified-face set has exactly one element
  (`GlobalTopologyCertificateDiagnostics.h:134-138`), and unites across every edge not in
  `embeddedGraphSourceEdges` - **mandatory and cut only**, omitting `traceTouchedEdges`. Its components are
  therefore **strictly coarser** than the seed guard's, so they collect several certified faces and every member
  resolves to `nullopt`. CA4's multiset is empty and **neither branch of `M3-CP4c3-TB21-CAND-01` fired**.
- **THE DATUM DOES NOT EXIST.** `SurfaceCutGraphFaceCertificate` (`SurfaceCutGraph.h:53-63`) publishes `orbit`,
  `boundaryWalkCount`, `boundaryArcCount` and `discTopologyEstablished` - **no source-face membership, no boundary
  arc list**. No Code + Build turn can read what the contract does not publish, which is why three successive
  diagnostic contracts each had to reconstruct the answer from `walk.orbitByDart` and each collapsed the same way.
  **This is a definition gap**, and TB22-REV's "no further diagnostic turn" prohibition is honoured: the successor
  is a **DEFN**.

Carried surfaces 367/368/369/370/374 unchanged; 371/372/391/392 still PASS. **There is still no vertex-30
discriminator.**

### Exact next turn

Run **`M3-CP4c-3-DEFN-R3`** under §8 **CF0–CF9** of
`Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md`. **No runtime, no compile, no package.**

- [ ] **CF0** — accepted 365 untouched; selector 397 byte-frozen; definitions and measures only.
- [ ] **CF1** — decide what a certified face must publish so ownership of an uncut triangle is answerable.
- [ ] **CF2** — decide whether the seed guard's premise is checkable; no weakening without a stated replacement.
- [ ] **CF3** — state the required barrier set for any certified-face projection.
- [ ] **CF4** — adjudicate `M3-CP4c3-TB20-REV-CAND-02` (CB21 vs the Parts IV/V prohibition).
- [ ] **CF5** — carry forward `proves_cellularity()`, accepted 1–365, the cellularity evidence, CB21, and the
      separate ownership of 367/368/369/370/374.
- [ ] **CF6** — record that both branches of `M3-CP4c3-TB21-CAND-01` were never discriminated.
- [ ] **CF7** — disposition ordinals **393** and **397** explicitly; 397 must be **fixed**, 393 never silently
      deleted.
- [ ] **CF8** — freeze the successor CB's measures, including the fail-open `test_data_root()` and the
      unrelated-locus regression.
- [ ] **CF9** — observe the prohibited list.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **88**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **CB25 is compile-green** at semantic source `e12396d...`, selector397/package88. Exact next: immutable **`M3-CP4c-3-TB23-R1`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face seed/ownership projection:** CB25 replaced the vacuous/circular diagnostics with certificate-derived, independently sided, falsifiable measurements without changing product semantics. Valid TB23-R1 evidence is now available but CA4 reports 191/191 unavailable certified faces, so branch adjudication remains with `M3-CP4c-3-TB23-R1-REV`. Exact owner: that review.
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

Current provisionally retained totals are **44 events / 14 categories / 30 recurrences** pending TB23-R1-REV classification. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **88**. **TB23-R1 is the latest semantic runtime authority at 389 PASS / 8 RED, accepted 365/365; package `9921914679` remains immutable.** Exact next is independent `M3-CP4c-3-TB23-R1-REV`. PR #8 remains open, draft, and unmerged.
