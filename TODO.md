# Directional Surface-Cell TODO

Last updated: 2026-09-01 UTC

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

## Current focus — `M3-CP4c-3-DEFN-R2` (Definition + Review/Plan only)

`M3-CP4c-3-CB8-REV` is **COMPLETE / ARCHITECTURAL STOP UPHELD / DEEPER DEFINITION REQUIRED**. The independent
review answered CB8's authority question but did **not** authorize another CB. Amendment 17's primitive is one exact
arrival-anchored ray; current A1 products publish exact branch correspondence, not an exact/certified arbitrary-ray
metric transport, and the design has never defined straight continuation through a general non-flat vertex star.

### CB8-REV verdict

- Freeze one A2a `VertexStarRaySeed` at each exact vertex-arrival event. Candidate-local
  `FieldBranchBoundaryPairing::direction` values are audit data only, never replacements for that seed.
- Use an arrival-anchored intrinsic vertex-star development as the **reference semantics** to be defined. Plain
  `FieldExactRational` is not a general construction type for non-coplanar isometric unfolding; exact algebraic
  geometry or a direct exact predicate is required, with a certified filter allowed only when it defers to an exact
  fallback.
- An upstream continuation-owner representation does not remove this obligation; it merely moves the same exact
  derivation unless the semantic owner rule is independently defined.
- The authority belongs to A2a vertex transit as one derived single-writer contract consuming A0 source geometry +
  immutable A1 branch topology + the one seed. A1 remains branch-correspondence authority.
- General non-flat stars can produce a developed gap or overlap under a straight-through model. Amendment 21
  requires those cases to become explicitly defined typed states, not candidate ordering, a tolerance, a hidden seam,
  or invented topology.
- Mechanical vertex 30 remains a valid falsifier of the old mechanism: its two candidate faces use geometrically
  distinct local branch representatives. One common developed seed cannot become two candidates merely because each
  face's own cross representative is admissible. The exact owner is intentionally **not** named until DEFN-R2
  freezes the geometry.
- Production transit-row projection (`M3-CP4c3-TB6-CAND-01`) remains a real downstream defect but must publish the
  eventual correct seed/certificate rather than richer evidence for the invalid per-cell datum.
- Selector 373 remains frozen at SHA-256
  `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; selector 374 still does not exist.

### Exact next turn

Execute **`M3-CP4c-3-DEFN-R2` — Definition + Review/Plan only** under measures **AX0–AX9** in
`Architecture_M3_CP4c3_CB8_Independent_Review_Record.md`. DEFN-R2 must freeze the vertex-star transit geometry,
curved/degenerate-star semantics, exact/certified kernel, A2a owning contract, mechanical proof, selector-374
falsifier contract, and production audit contract before it may issue any later Code + Build measures. No runtime,
compile, package, product, test, fixture, or selector mutation is allowed in DEFN-R2.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — **ACTIVE / definition + representation authority gap**: the per-cell
  representative cause is proven, but the exact semantics of general non-coplanar vertex-star continuation are not
  yet defined. Owned by DEFN-R2 AX1–AX6.
- [ ] `M3-CP4c3-TB6-CAND-01` — **ACTIVE / owner proved / blocked on semantic datum**: production projection/DTO
  drops exact transit rows. DEFN-R2 AX8 freezes the correct audit contract; a later CB may then repair the projection.
- [ ] selector governance — keep selector 373 immutable; selector 374 is authorized only after AX7 derives a
  non-coplanar exact witness that actually fails under `incomingDirection = nextPairing->direction`.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — genuine independent empty-network product red; deferred.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere `NoCarrierMatch / SourceEdgeUnavailable`; deferred.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — `saturationUsed=true`; deferred quality/coverage debt.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — partial; mechanical zero-unbound proof still owed.

Stable accounting: **44 events / 14 categories / 30 recurrences**; debt **5**; semantic M3 packages **73**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 TB6 preserves the accepted 365-prefix but remains RED at ordinal 366. CB8 triggered its AW1 architectural stop because current products lack exact/certified one-ray projection across a non-coplanar fan. Exact next is combined `M3-CP4c-3-DEFN-R2`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB6 preserves the accepted 365-prefix and first-reds ordinal 366 at `VertexTransitSectorUnresolved`, source vertex 30, with two published faces. CB8 stopped before semantic editing because current source/atlas authority has no exact/certified arbitrary-ray projection across the non-coplanar fan. Owned next by `DEFN-R2` AX1–AX6; no candidate-order, tolerance, float-transport, `signedLift`-as-ray, target-representative shortcut, or undefined cone continuation.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **73** after CB7/package 75. PR #8 remains open, draft, and unmerged.
