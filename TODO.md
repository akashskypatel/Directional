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

## Current focus — `M3-CP4c-3-CB16` (Code + Build, PRODUCT CORRECTION)

`M3-CP4c-3-TB13-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB13_Independent_Review_Record.md` (**BK0–BK8** discharged, static only).

TB13's first red moved **earlier**, to source vertex **10**, face `(8,10,11)`, reason
`VertexTracePortOrdinalInvalid`. TB13 called the cause underdetermined; `M3-CP4c-3-TB13-REV` **determined it from
static authority**.

- **That reason names two emitters.** `EmbeddedGraphTopology.cpp:1204` (legacy: port lookup failed or
  `ordinal < 0`) and `:1217` (CB15's `vertex_locus_secondary_parameter == nullopt`) both set only reason,
  `sourceVertex` and `sourceFace`.
- **The legacy emitter is excluded.** CB15 touched four files, none `SurfaceCellTracing.cpp`, so the network is
  **byte-identical** to TB12's; node ids are monotone in vertex index and `incidences` is a node-id map, so v10 is
  processed **before** v47 — which TB12 reached. v10 passed that branch on identical inputs.
- **Only a `Forward` ray can fail.** The `Reverse` path resolves the segment's own entry point, which lies on an
  edge of that segment's face by construction. So the failure is an **emanating ray at v10 in face `(8,10,11)`** —
  mesh row 8, fan slot 7, bounded by edge `10-11`.
- **The defect is one missing case.** `segment.edgeTransitExit` is assigned only on the edge-transit path, never
  for a `VertexHit`. TB7-REV proved v10's port trace runs along mesh edge `(10,11)` to **vertex 11**, a corner of
  its own face — so the four-case Forward chain finds nothing, while the point is barycentric `(0,0,1)` giving
  denominator 1 and an exact within-wedge parameter of **0**. Every guard would have passed.
- **Accepted-boundary safety is structural.** Appending the new case **last** means it is reached only where the
  helper errors today, so no currently-succeeding rotation can change.

`M3-CP4c3-TB13-CAND-01` transitions to **root cause proved**; new `M3-CP4c3-TB13-REV-CAND-01` is **ACTIVE**.
**The v47 obligation stays open** — `M3-CP4c3-TB11-CAND-01` does **not** close and
`M3-CP4c3-TB12-REV-CAND-01` is only partially discriminated, because the five-ray v47 rotation with distinct ranks
was never reached. Sphere 368, saturation 369, ordinal 370, folded-cone 374, the 371/372 coupling, vertex 30 and
the finalize/contact fall-through are unchanged. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB16`** under §9 **BL0–BL9** of
`Architecture_M3_CP4c3_TB13_Independent_Review_Record.md`.

- [ ] **BL0** — selector 379 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BL1** — add the **vertex-exit case** to `vertex_trace_ray_second_point`'s Forward chain, recovering the
      vertex from `source_support()` / the `outgoingCarrier` endpoint. Exact rationals only.
- [ ] **BL2** — place it **last** in the chain, so it is reached only where the helper errors today.
- [ ] **BL3** — **split the collapsed reason**; give emitter B its own typed name and retain arc, trace,
      orientation, segment bounds and the failing subcondition.
- [ ] **BL4** — preserve every CB15 invariant; do not revert CB12 or CB14.
- [ ] **BL5** — positive (corner exit ranks at exact parameter 0/1), negative (no representable second point fails
      under the new reason) and regression (edge-transit ray byte-identical) witnesses.
- [ ] **BL6** — append selector 380 only on demonstrated falsification.
- [ ] **BL7** — prohibitions: no identity tie-break, no tolerance/float, no change to the projection formula,
      `vertex_trace_secondary_ranks`, `build_vertex_fan_slots`, `trace_ray_face`, the edge-locus branch or the
      incidence map; no CB12/CB14/CB15 revert; no finalize/contact repair; no 371/372 decoupling.
- [ ] **BL8** — audit by assumption; prove no accepted-green rotation changes.
- [ ] **BL9** — publish the six `M3-CP4c-3-TB14` discriminators, **including the v47 five-ray re-proof**.
      **No vertex-30 discriminator.**

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **80**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB13 is the latest runtime authority at accepted prefix 365 / first red 366, now moved to vertex 10 `VertexTracePortOrdinalInvalid`. CB15/package83 remains current build authority. Exact next is independent `M3-CP4c-3-TB13-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — ordinal 366 now moves to vertex-10 ambiguous vertex-trace rank failure:** TB13 preserves 365/365 and removes the old v47 collision at the frontier, but production stops earlier at source vertex 10 / face `(8,10,11)` under `VertexTracePortOrdinalInvalid`. That reason conflates the legacy port lookup/ordinal failure with failure of the new exact secondary-parameter computation, and retained evidence does not identify arc/trace/orientation or subcondition. `M3-CP4c3-TB13-CAND-01` is the gating owner for independent review. The v47 five-ray/distinct-rank conjunction remains open under `M3-CP4c3-TB11-CAND-01`; vertex 30 and finalize/contact remain separate and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **80**. CB15 is COMPLETE / BUILD GREEN / RUNTIME-FREE; exact next is artifact-only `M3-CP4c-3-TB13`. PR #8 remains open, draft, and unmerged.
