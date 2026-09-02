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

## Current focus — `M3-CP4c-3-CB14` (Code + Build, DIAGNOSTIC-ONLY)

`M3-CP4c-3-TB11-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB11_Independent_Review_Record.md` (**BG0–BG7** discharged, static only).

TB11's ordinal-366 red —
`rotationSystemReason=RotationRayOrderKeyCollision;sourceVertex=47;certificationAttempt=0;certificationCutEdges=0`
— is **not adjudicable from the retained evidence**, and `M3-CP4c-3-TB11-REV` proved why.

- **The unique emitter** is `EmbeddedGraphTopology.cpp:1214` in `build_rotation_system`: post key-construction,
  post-sort, pre-`counterClockwise`, on adjacent sorted pairs that are both `Trace` at a **vertex** locus.
- **The guard compares less than the key.** `RayOrderKey` sorts on six members; the predicate tests only `primary`
  and `secondary`. `arc` and `orientation` are present and excluded.
- **`secondary` is not vertex-local.** It is `port->ordinal` for the port the trace **originated** from, matched by
  id with **no check** that the port's source vertex is the locus vertex.
- **A self-loop arc collides by construction.** The incidence map pushes `Forward` at `firstNode` and `Reverse` at
  `secondNode` unconditionally; both darts share `arc.trace` and hence `secondary`. No upstream defect is required.
- **Neither colliding ray is retained.** The emitter sets only the reason, `sourceVertex` and `sourceEdge`, while
  the DTO already declares `arc`, `trace`, `secondTrace`, `sourceFace` and `secondSourceFace` — and **no field can
  hold `primary`/`secondary` at all**. BG2 alternatives 1–4 render **byte-identically**.
- **Certification phase (BG3).** `certificationAttempt=0` / `certificationCutEdges=0` prove failure on the **first
  certification of the uncut graph**, before any cut proposal. `cutCandidateCount=450` is a real measurement;
  `nonDiscComponentCount=0` and `remainingAdmissibleEdgeCount=0` are **struct defaults on this path**, assigned
  only at `SurfaceCutGraph.cpp:365`/`:367` under a different error code.

`M3-CP4c3-TB10-CAND-01` is **CLOSED / RUNTIME DISCRIMINATED**. `M3-CP4c3-TB11-CAND-01` transitions to
**underdetermined by retained evidence**; new `M3-CP4c3-TB11-REV-CAND-01` is **ACTIVE**.
`M3-CP4c3-TB10-REV-CAND-01` (371/372 test coupling) stays **DEFERRED**; sphere 368, saturation 369, ordinal 370,
folded-cone 374, vertex 30 and the finalize/contact fall-through are unchanged.

**Caution:** the rotation system at a **singularity** node became reachable only after CB12 and CB13 let the
pipeline advance this far. This is a **newly reachable** path, not demonstrably a newly introduced defect; CB12
must not be reverted or treated as suspect on this evidence.

### Exact next turn

Run **`M3-CP4c-3-CB14`** under §8 **BH0–BH9** of
`Architecture_M3_CP4c3_TB11_Independent_Review_Record.md`. **Diagnostic-only.**

- [ ] **BH0** — selector 377 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BH1** — name both colliding rays via `arc`/`trace`/`sourceFace` and `secondTrace`/`secondSourceFace`.
- [ ] **BH2** — add typed fields for both `primary`/`secondary`, both orientations, both origin port ordinals **and
      their source vertices**, and each ray's fan slot.
- [ ] **BH3** — publish a bounded fan census at the failing locus with a truncation marker.
- [ ] **BH4** — make `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` honest on the certification path.
- [ ] **BH5** — synthetic same-sector collision witness through the **production** renderer + mechanical assertion.
- [ ] **BH6** — append selector 378 only on demonstrated falsification; republish 377 unchanged.
- [ ] **BH7** — prohibitions: no change to the predicate, sort, `RayOrderKey`, `primary`/`secondary`,
      `trace_ray_face`, the incidence map, or any ordering semantics; no CB12 revert; no finalize/contact repair;
      no 371/372 decoupling; no sphere/369/370/folded-cone correction.
- [ ] **BH8** — audit by assumption; prove no accepted-green observable output changes.
- [ ] **BH9** — publish the five `M3-CP4c-3-TB12` discriminators.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **78**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB11 is current runtime authority at accepted prefix 365 / first red 366, now `RotationRayOrderKeyCollision` at source vertex 47 during initial certification. Exact next is independent `M3-CP4c-3-TB11-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — moved mechanical first red:** TB10 runtime-proved CB12's barrier-absorbed termination correction and closed `M3-CP4c3-TB9-REV-CAND-01`. The gating frontier is ordinal 366 in `surface-cut-graph`, at `CellularityNotEstablished/origin=RotationSystemInconsistent`. TB10-REV proved the firing site is one of **28** `RotationSystemInconsistent` emission sites that publish neither a reason nor an edge/face locus, so the underlying condition is **unavailable at the current instrumentation and the loss is producer-side** — the projection repair alone would change nothing. `M3-CP4c3-TB10-CAND-01` is owned by diagnostic-only `M3-CP4c-3-CB13` (BF0–BF9). No product semantic correction is authorized or inferable. Vertex 30 and the separate finalize/contact fall-through remain open and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **77** after CB12/package 80; TB10 created no package. PR #8 remains open, draft, and unmerged.
