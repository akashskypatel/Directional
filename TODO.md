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

## Current focus — `M3-CP4c-3-CB22` (Code + Build, DIAGNOSTIC-ONLY)

`M3-CP4c-3-TB19-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB19_Independent_Review_Record.md` (**CR0–CR8** discharged, static only).

CB21 is **confirmed against BU0-BU9**: 1-365 stay 365/365, ordinal 366 leaves
`TraceCutFaceFragmentCountMismatch` (the load-bearing discriminator), 367/371/372 move with it, the `(0,1,102)`
deficit is retained as 1 non-fatally, the census is untruncated, and carried surfaces are unchanged.
**`M3-CP4c3-TB17-CAND-01` closes.**

The new frontier is `UncutFaceComponentOrbitSeedNotUnique` at source face `(0,1,2)`, emitted at
`GlobalTopologyPlan.cpp:1151-1163` in the block that labels faces no chord touched.

- **The reported locus is an iteration artifact, and this is proved.** `failure.sourceFace` is the **first
  unlabeled face in `std::map` key order**. `(0,1,2)` is **row 0 of the mechanical fixture and row 0 of the torus
  fixture**, and the historical torus stop of the same name reported the identical face. Two unrelated witnesses,
  same code, same locus.
- **Zero seeds versus two-or-more is NOT derivable from committed bytes.** Neither the component id, its
  membership, nor its seed set is retained. Partial evidence favours two-or-more - face `(0,1,2)` neighbours
  labeled row 259 `(0,1,102)` across edge `0-1`, which the TB18 chord never made a carrier
  (`incomingCarrier=none`) - but the barrier membership of `0-1` is a product decision not recoverable statically.
- **The deciding numbers are discarded, sixth instance.** The component id, its membership and `seedOrbits` are all
  in hand at the failure; only `sourceFace` survives, and it is the one field that cannot discriminate.
- **The torus stop is a different mechanism.** With **0 traces** no face acquires a chord label, so no edge has a
  labeled side and every seed set is empty - provably the **zero** branch. The mechanical witness has 70 labeled
  faces and 6 non-exterior orbits and cannot be that. The candidates are **not merged**.
- **A universal non-crossing invariant is REFUTED, not merely unproved.** The tracer builds `TraceIntersection`
  contact nodes bound to a source face, so crossings are a modelled case in which `k` chords make `k + 1 + c`
  local fragments. The 70/70 non-crossing rows are witness-local sufficiency only, so `localFragmentCount` must
  stay non-fatal.
- **371/372 remain deferred with a standing trigger:** both abort in a fixture constructor that will stop throwing
  once the production plan builds, so a test-only accessor now risks landing a surface the next correction makes
  redundant. Authorize the decoupling at the first review that either closes the mechanical production frontier or
  finds the frontier unmoved across two consecutive TB turns.

368/369/370/374 are unchanged under their existing owners. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB22`** under §10 **BV0–BV9** of
`Architecture_M3_CP4c3_TB19_Independent_Review_Record.md`. **Diagnostic-only.**

- [ ] **BV0** — selector 384 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BV1** — component id, seed count, and an explicit **`seedState in {None, Multiple}`** on the error.
- [ ] **BV2** — the failing component's face count and bounded membership, with a truncation marker.
- [ ] **BV3** — bounded boundary-edge rows: edge key, labeled-side flag, owner count, barrier class, and the seed
      or the exact reason none was contributed — **including the silent `edgeOrbitEvidence` skip at `:1136-1139`**.
- [ ] **BV4** — publish that `sourceFace` is an iteration-order locus; add the component identity as the
      discriminating one.
- [ ] **BV5** — extend the existing `TraceFragmentOwnerEvidenceDiagnostic` census with component rows.
- [ ] **BV6** — one witness per new field plus an unrelated-error regression witness; append selector 385.
- [ ] **BV7** — **no semantic change**: the predicate, barrier set, partition, `seedOrbits`, `edgeOrbitEvidence`,
      the face walk, the rotation system, region drafts and CB21's comparison stay untouched;
      **`localFragmentCount` stays non-fatal**; no 371/372 decoupling.
- [ ] **BV8** — audit by assumption; prove 1–365 unaffected by construction.
- [ ] **BV9** — publish the six `M3-CP4c-3-TB20` discriminators, chiefly that the failure now carries `seedState`.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **85**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB19/selector384 is current runtime authority** at 376 PASS / 8 RED and accepted 365/365. CB21's fragment-owner correction is runtime-proved; the new frontier is `UncutFaceComponentOrbitSeedNotUnique` at `(0,1,2)`. Exact next: independent **`M3-CP4c-3-TB19-REV`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — region ownership frontier:** TB19 runtime-proves the CB21 one-sided fragment-owner correction: 366/367/371/372 clear `TraceCutFaceFragmentCountMismatch`, accepted 1–365 stays 365/365, and ordinal 384 passes. The next typed frontier is **`UncutFaceComponentOrbitSeedNotUnique` at `(0,1,2)`**; retained evidence does not distinguish zero component seeds from multiple seeds. Exact owner is `M3-CP4c-3-TB19-REV`. Vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (deferred, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor, which throws unless all five downstream products are retained. TB19 confirms both clear the fragment mismatch but still abort at the shared downstream `UncutFaceComponentOrbitSeedNotUnique` frontier, so their own Amendment-15 atlas contracts remain unmeasured. The already-specified test-only atlas-scoped accessor remains **review-owned, not authorized**; TB19-REV decides whether to decouple now or keep it deferred. `M3-CP4c3-TB10-REV-CAND-01`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **85**. **TB19/selector384 is current runtime authority: 376 PASS / 8 RED, accepted 365/365; CB21's fragment-owner correction is runtime-proved and the later component-seed frontier is review-owned.** Exact next is `M3-CP4c-3-TB19-REV`. PR #8 remains open, draft, and unmerged.
