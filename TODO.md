# Directional Surface-Cell TODO

Last updated: 2026-09-02 UTC

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

## Current focus — `M3-CP4c-3-CB18` (Code + Build, PRODUCT CORRECTION)

`M3-CP4c-3-TB15-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB15_Independent_Review_Record.md` (**BO0–BO8** discharged, static only).

TB15's typed branch is **`SourceVertexFallbackUnbound`** at edge `25-31` / face `(25,30,31)` = mesh row 41, with
the full incidence retained: source vertex **35**, arc **19**, trace **5**, **Reverse**, segments `[0,5)`, incoming
carrier **none**, outgoing **`25-31`**, contact index **2**, census **3 rays untruncated**.

- **The segment entered its face through a vertex.** `proposal.nextIncomingCarrier` is assigned at exactly one site
  (`SurfaceCellTracing.cpp:3122`, the **edge-exit** continuation); the `VertexHit` branch returns without setting
  it. The arc is `[0,5)`, so segment 4 is not the trace's first — the only other producer of an absent incoming
  carrier.
- **The incidence is valid.** Vertex-transit entry is Amendment 3's ordinary continuation; rejecting it upstream
  would reject valid networks.
- **The datum is wrong, not the shape.** The fallback searches the face's corners for `trace.sourceVertex` — v35, a
  port-emitting singularity elsewhere on the part — while row 41's corners are `{25,30,31}`. The canonical datum is
  the segment's **far-end support in this face**: entry side for Reverse, exit side for Forward, via
  `FieldBoundaryPoint::source_support()`. The shipped rule is the special case where they coincide.
- **A second, latent defect, proved by derivation.** The carrier branch ranks relative to `contactIndex`; the
  fallback ranks absolutely. The correct corner rank is `1 + 2·((corner + 2 − contactIndex) mod 3)`, equal to the
  shipped `1 + 2·corner` **only when `contactIndex == 2`** — this failure's value, so the run cannot see it.
- **This correction is NOT accepted-safe by construction.** It changes rays that currently *succeed*, in two
  classes, and the torus reaches A2b, so accepted identities plausibly exercise the helper. Safety must be
  **demonstrated**, and ordinals 1–365 re-passing is the load-bearing discriminator.

Package 85's diagnostic-name metadata mismatch is **inert and proved so**: the contract-named identity occurs zero
times in `tests/`, the executed one exists, and **neither is in selector 381** — recorded as
`M3-CP4c3-TB15-PKG-01`, no rerun, no repair. `M3-CP4c3-TB14-CAND-01` **CLOSES**; new
`M3-CP4c3-TB15-CAND-01` is **ACTIVE**. **The v47 obligation stays open** — selector 380 is still RED, so
`M3-CP4c3-TB11-CAND-01` does not close and `M3-CP4c3-TB12-REV-CAND-01` stays partially discriminated. Sphere 368,
saturation 369, ordinal 370, folded-cone 374, the 371/372 coupling, vertex 30 and the finalize/contact fall-through
are unchanged. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB18`** under §9 **BP0–BP9** of
`Architecture_M3_CP4c3_TB15_Independent_Review_Record.md`.

- [ ] **BP0** — selector 381 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
      Selector 381's PASS is **not** evidence for this correction.
- [ ] **BP1** — bind the fallback to the segment's **far-end vertex support in this face** via
      `FieldBoundaryPoint::source_support()`; entry side for Reverse, exit side for Forward.
- [ ] **BP2** — corner rank relative to the contact edge: `1 + 2·((corner + 2 − contactIndex) mod 3)`.
- [ ] **BP3** — keep the helper fail-closed for a genuinely unbindable far end.
- [ ] **BP4** — leave the carrier branch, `trace_ray_face`, `sideRank`, `key.primary`, collision detection,
      `build_node_loci` and the vertex-locus path untouched; no CB12/CB14/CB15/CB16/CB17 revert.
- [ ] **BP5** — **demonstrate** accepted-boundary safety: pin every currently-succeeding fallback rank before and
      after. **Not a formality** — this correction changes rays that currently succeed.
- [ ] **BP6** — positive, negative, ordering and regression witnesses.
- [ ] **BP7** — append selector 382 only on demonstrated falsification; no package-85 repair.
- [ ] **BP8** — audit by assumption; report the complete class of inputs whose rank changes.
- [ ] **BP9** — publish the six `M3-CP4c-3-TB16` discriminators, **including the v47 five-ray re-proof**.
      **No vertex-30 discriminator.**

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **82**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB15 is current valid runtime authority at accepted 365/365 / first red 366 `EdgeTraceSecondaryRankInvalid -> SourceVertexFallbackUnbound` at edge 25-31 / face `(25,30,31)`. Package85/source `1e671ef7...` is current immutable authority. `M3-CP4c-3-TB15-REV` is complete; exact next is product-correction `M3-CP4c-3-CB18` under BP0-BP9.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — edge-locus source-vertex fallback frontier:** TB15 re-proves accepted 365/365 and keeps first red 366 at edge `25-31` / face `(25,30,31)` / attempt 0 / zero cut edges, now typed `SourceVertexFallbackUnbound`. The exact retained ray is source vertex 35, arc 19 / trace 5 / Reverse / `[0,5)`, outgoing carrier `25-31`, contact index 2, no incoming/other carrier, with a complete three-ray census. `M3-CP4c3-TB15-CAND-01` has been adjudicated by TB15-REV: the incidence is valid and the fallback binds the wrong datum/namespace, with a latent contact-relative rank defect. CB18 BP0-BP9 owns the bounded product correction and accepted-prefix safety proof. The v47 full five-ray/distinct-rank production proof remains mandatory; selector 381 PASS and absence of the old collision are insufficient. Vertex 30 and finalize/contact remain separate and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **82**. TB15/package85 is current valid runtime/immutable authority: **372 PASS / 9 RED**, accepted **365/365**, first red 366 `SourceVertexFallbackUnbound` at edge 25-31 / face `(25,30,31)`. TB15-REV BO0-BO8 is complete. Exact next is `M3-CP4c-3-CB18` BP0-BP9 (Code + Build, product correction). PR #8 remains open, draft, and unmerged.
