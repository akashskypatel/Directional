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

## Current focus — `M3-CP4c-3-CB21` (Code + Build, PRODUCT CORRECTION)

`M3-CP4c-3-TB18-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` (**BT0–BT9** discharged, static only).

TB18 measured the deciding values through CB20's diagnostic projection. Ordinal 366 is unmoved -
`TraceCutFaceFragmentCountMismatch` at `(0,1,102)` - which is itself the proof that CB20's BS7 boundary held.

- **The mechanism is measured and singular.** actual **1** / `k` **1** / expected **2**, low by exactly one; one
  untruncated incidence `trace=1 arc=15 segment=4`, `incomingCarrier=none`, `outgoingCarrier=0-102`,
  `forwardOrbit=0`, `reverseOrbit=0`, neither exterior-dropped; three edge rows each `[0]`. Exterior filtering and
  both high-side mechanisms are **eliminated**; **shared global orbit ownership** is selected.
- **The incidence is a vertex transit through a regular vertex.** Segment 4 is not segment 0, so not the trace's
  port origin: one of CB19's 48 vertex transits. The carrier-less branch binds the corner opposite the outgoing
  carrier - **vertex 1**, degree 6, angle defect 0, two 90-degree sharp edges. The chord separates the triangle
  **locally**.
- **Shared ownership is legitimate, not a merge defect.** The face walk is the canonical rotation-system face
  permutation, validated total; its orbits are its cycles, so it cannot fuse darts a valid rotation system
  separates. Two darts of one arc share an orbit exactly when the arc is a bridge or non-separating - both
  legitimate. `|owners| = k+1` is therefore **not an invariant of any valid input**; the sound relation is
  `|owners| <= localFragmentCount`.
- **The correction is safe by construction.** The validation loop is pure - it returns a failure or falls through
  and mutates nothing. `size > expected` holds on a strict subset of `size != expected`, so the failing set only
  shrinks and every previously-passing input is byte-identical. 1-365 are 365/365, so the accepted boundary cannot
  move. Downstream, `fragmentOrbits[face]` registers face-to-region membership only, correct under shared ownership.
- **BS9-5 is RETIRED.** The missing `fragment_reconciliation` line sits behind
  `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`, which the artifact-only runner never sets, and it prints exactly the
  three values BS1 already retained (1/1/2). It asked for a text duplicate of typed evidence. Nothing is owed and
  BS4 is closed as correctly implemented.

`M3-CP4c3-TB17-CAND-01` transitions to **owner proved / correction authorized**. New
`M3-CP4c3-TB18-REV-CAND-01`: the local-fragment invariant is `k+1` only if no two chords cross inside a face, which
is unproved. Sphere 368, saturation 369, ordinal 370, folded-cone 374, the 371/372 co-reachers, vertex 30 and the
finalize/contact fall-through are unchanged. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB21`** under §11 **BU0–BU9** of
`Architecture_M3_CP4c3_TB18_Independent_Review_Record.md`. **Product correction — a loosening plus evidence.**

- [ ] **BU0** — selector 383 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BU1** — the only semantic change: `size != expected` becomes `size > expected` at
      `GlobalTopologyPlan.cpp:777-779`.
- [ ] **BU2** — retain the low-side deficit and the shared-owner chords as evidence, never as a failure.
- [ ] **BU3** — compute the local fragment count **locally** and retain it, **non-fatal**; retain chord-crossing
      evidence.
- [ ] **BU4** — publish the bridge / orbit census: per-arc shared-dart flag, per-trace terminal-slit flag, and the
      global total / exterior / non-exterior orbit counts.
- [ ] **BU5** — one witness per new field, a witness that one chord with one shared owner now passes, and a
      byte-identical high-side regression witness.
- [ ] **BU6** — append selector 384 with only the BU5 identities; 383 stays an exact prefix.
- [ ] **BU7** — **prohibited:** `tracePieceCount`, `add_fragment_orbit`, the `exteriorOrbits` filter,
      `is_terminal_slit`, `resolve_carrierless_corner_binding`, `build_fragment_corner_incidence`, the face walk,
      the rotation system and region drafts stay untouched; no new fatal condition; no CB12–CB20 revert. **BS9-5 is
      retired — do not restore it.**
- [ ] **BU8** — audit by assumption; reproduce the safety proof against the actual diff.
- [ ] **BU9** — publish the six `M3-CP4c-3-TB19` discriminators, chiefly that **ordinal 366 no longer reds at
      `TraceCutFaceFragmentCountMismatch`**.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **84**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB18/selector383 is current runtime authority** at 375 PASS / 8 RED and accepted 365/365. CB20 diagnostic source `57635e87` remains the semantic/build source. Exact next is independent `M3-CP4c-3-TB18-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — face-fragment orbit/count frontier:** TB18 preserves accepted 365/365 and first-reds at `TraceCutFaceFragmentCountMismatch` on `(0,1,102)`, measuring actual/trace/expected as `1/1/2`. The one chord's forward/reverse orbit ids are both `0` and both exterior-drop flags are false, so this witness is a shared-global-owner collapse. `M3-CP4c-3-TB18-REV` must adjudicate the replacement representation/invariant; TB18 itself authorizes no correction. Vertex 30 and finalize/contact remain separate and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **84**. **TB18/selector383 is current runtime authority: 375 PASS / 8 RED, accepted 365/365, first red 366 `TraceCutFaceFragmentCountMismatch` at `(0,1,102)` with measured actual/trace/expected `1/1/2`.** Exact next is independent `M3-CP4c-3-TB18-REV`. PR #8 remains open, draft, and unmerged.
