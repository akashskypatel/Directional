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

## Current focus — `M3-CP4c-3-CB8-REV` (independent Review + Plan only)

`M3-CP4c-3-CB8` is **COMPLETE / ARCHITECTURAL STOP / BUILD GREEN / RUNTIME-FREE**. Its frozen AW1 stop rule fired
before semantic editing: current source/atlas authority can transport exact branch correspondence but cannot publish
an exact/certified projection of one arbitrary incoming tangent ray through a general non-coplanar fan.

### CB8 verdict

- `resolve_field_vertex_transit` still rebinds successor `incomingDirection` to `nextPairing->direction`; no code
  change was made because replacing that with `signedLift`, target-local data, or CB6-style world-space transport
  would violate Amendments 17/18.
- `FieldBranchTransportAdjacency` / `FieldDirectedBranchTransport` carry only quarter-turn, integer lift and floating
  effort; they do not carry an exact arbitrary-ray transform.
- `SourceChartTransitionGraph` carries topology/orientation/corner permutation only, not a tangent metric transform.
- The existing planar phase-front zero-turn path is floating/tolerance-based and not general non-coplanar authority.
- Production transit rows remain dropped at `network_failure_locus` / `SurfaceCellFailureLocusDiagnostics`; this is
  retained as `M3-CP4c3-TB6-CAND-01`, but CB8 did not publish richer rows for an invalid datum.
- Selector 373 remains frozen at SHA-256
  `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; selector 374 was not created.
- Blocker compile run `33467212874` built all eight standard targets from unchanged semantic source
  `0d943f95b42e49813060399e83a1e4180e8348f6` with GMP/GMPXX and `runtimeExecution=false`.
- No semantic package was created. Latest semantic package remains package 75; semantic package count remains 73.

### Exact next turn

Execute **`M3-CP4c-3-CB8-REV` independent Review + Plan only** under
`Architecture_M3_CP4c3_CB8_Independent_Review_Plan.md`. The review must freeze the smallest single-writer
exact/certified transit representation (or another Amendment-17-compliant continuation owner) before authorizing
another CB. No runtime/build/package/test/fixture/selector/product edit is allowed in that review.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — **ACTIVE / architectural authority gap**: Amendment 17 requires one datum, while
  current products provide branch correspondence and per-face representatives but no exact/certified arbitrary-ray
  projection across non-coplanar fans.
- [ ] `M3-CP4c3-TB6-CAND-01` — **ACTIVE / owner proved**: production projection/DTO drops exact transit rows; repair
  only after the review freezes the correct datum/projection authority those rows must publish.
- [ ] selector governance — keep selector 373 immutable; create selector 374 only after the minimal transit identity
  is strengthened to falsify the old target-representative mechanism.
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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 TB6 preserves the accepted 365-prefix but remains RED at ordinal 366. CB8 triggered its AW1 architectural stop because current products lack exact/certified one-ray projection across a non-coplanar fan. Exact next is independent `M3-CP4c-3-CB8-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB6 preserves the accepted 365-prefix and first-reds ordinal 366 at `VertexTransitSectorUnresolved`, source vertex 30, with two published faces. CB8 stopped before semantic editing because current source/atlas authority has no exact/certified arbitrary-ray projection across the non-coplanar fan. Owned next by independent `CB8-REV`; no candidate-order, tolerance, float-transport, `signedLift`-as-ray, or target-representative shortcut.
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
