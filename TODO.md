# Directional Surface-Cell TODO

Last updated: 2026-08-30 UTC

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

## Current focus — `M3-CP4c-2-CB9` — convert A2b's two stale cut-arc consumers

`M3-CP4c-2-TB-X2-R9-REV` is complete:
`Architecture_M3_CP4c2_TB_X2_R9_Independent_Review_Record.md`. Measures **AI0–AI9**.

**R9 closed four long-running items.** On immutable CB8 package `9726295440` (run/job
`33319911575 / 99279955697`): accepted prefix **355/355 PASS**, ordinals **356–362 PASS**, ordinal **363 RED**,
364–365 NOT RUN.

- **`R8-CAND-01` CLOSED** — 359 and 361 both green in a run reaching 361. AH2 was the right correction.
- **Measure `AD3` RESOLVED** — ordinal 359 reached its enumeration-invariance comparison for the first time, so the
  raw `face.orbit` index in `candidate_semantic_hash` is proved by test rather than by comment.
- **Criterion `C3` GREEN** at ordinal 362, after seven deferrals. **C1, C3 and C6 all hold on the produced torus.**
- **`PR8-R044`'s single-witness residual discharged** — 360 (bounded two-ring) and 361 (closed torus) both pass.

**Ordinal 363 is the first genuine product defect in this arc.** The witness is fine: it proved an exact
trace/source-edge crossing, built a **cellular** cut graph, and selected a `TraceInteriorCrossing` candidate. A2a′
did its job; A2b rejected the result.

- **Producer correct** (`EmbeddedGraphTopology.cpp:503-545`): exact `ExactUnitParameter` ordering, coincident
  crossings rejected not merged, and every sub-arc emitted in the canonical `cutEdge.first() → cutEdge.second()`
  direction (`ArcDraft` stores endpoints verbatim). That last property is why the fix is small.
- **Consumer stale and loud** (`GlobalTopologyPlan.cpp:479-516`): demands exactly one Cut arc per cut edge, and
  still calls cuts "ordinary embedded source-edge barriers" while the trace block below reasons in chords and
  fragments. Amendment 14 made cut arcs chord-like; A2b treats them as whole-edge barriers.
- **Consumer stale and SILENT** (`GlobalTopologyPlan.cpp:1239-1242`): inserts the whole source edge's endpoints
  into `boundaryVertices` for a sub-arc. `boundaryVertices` is a **skip list**, so this suppresses the
  interior-vertex ownership check with no error and no symptom. **Fixing only the loud site would trade a red gate
  for a quiet weakening.**
- **Cause of the omission — the reviewer's.** DEFN-R2 §4 itemized five producer-side changes under "convert every
  consumer" and did not list A2b's cut-arc binding. CB7/CB8 implemented §§4.1–4.5 correctly and completely.
  `LESSONS.md` **61**.

### CB9 scope — AI0–AI9

- **AI1 first, no build.** Produce the consumer audit **yourself**, by search over `arc.cutEdge`,
  `GlobalTopologyArcKind::Cut` and `cut_edges()`, and publish it with a per-site verdict. Compare against the
  review's §4 table **after**; any difference must be explained. This measure exists because a copied enumeration
  inherits the omission that caused this red.
- **AI2** iterate all sub-arcs at `:479-516`; state the canonical-direction dependency in the comment; keep the
  two-incident-faces guard; keep a typed failure for **zero** arcs; publish `fragmentOrbits[face].size()` against
  `tracePieceCount[face] + 1` and the `edgeOrbitEvidence` cardinalities as evidence.
- **AI3** fix the silent `boundaryVertices` site using `build_node_loci`'s existing `NodeLocus{vertex, edge}`,
  threaded in — no second node→vertex lookup. This **tightens** a loose check, so a new legitimate red there is a
  finding, not a regression.
- **AI4** record the four closures with their evidence, including annotating `SurfaceCutGraph.cpp:293-297` with
  "proved by ordinal 359".
- **AI5** test-helper hygiene: `build_topology_plan` / `build_surface_cut_graph` print the typed code and then
  throw on `built.value()`. `LESSONS.md` 60, second instance.
- **AI7** if the audit finds a site needing a representation change rather than a per-arc loop, **stop and return
  to definition** — Amendment 14 is frozen and must not be worked around.
- **AI8** CB9 must not absorb the sphere fix, any new gate identity, any selector byte, any error-enum change, or
  any change to `EmbeddedGraphTopology.cpp`'s crossing emission.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **66**.
`selected_r2_branch=NONE`; gate **365** is the frozen authority, executed red at ordinal 363;
`gate_execution_authorized=false`. CP4c-3 remains blocked.

### Open CP4c-2 candidates

- [ ] `M3-CP4c2-TB-X2-R9-CAND-01` — A2b's two stale cut-arc consumers; AI1–AI3. Closes when ordinals **363, 364 and
      365 are all green** in a run reaching 365.
- [ ] **Ordinals 364 and 365 have never run** — the degree-four two-Cut/two-Trace rotation and the saturation last
      resort, unexecuted for a third turn.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere: a producer `RotationSystemInconsistent` at source face
      `25-27-28` **and**, independently, a non-cellular pre-cut graph (`V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`).
      Neither is in the gate.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — zero-node / zero-arc closed-surface cut-graph behaviour; non-gating.
- [ ] **`AH6`** — carried forward; needs 363–365 all reached.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R9 re-proved the inherited **355/355** and passed 356-362, closing `R8-CAND-01`, measure `AD3` and criterion C3, then stopped red at ordinal 363. Criteria C1/C3/C6 are green on the produced torus; the remaining red is A2b's stale one-arc-per-cut-edge binding, a genuine product defect. CP4c-2 remains unaccepted. Exact next is `M3-CP4c-2-CB9` under AI0-AI9; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 gate ordinal 363:** A2b binds one derived `Cut` arc per selected cut edge, while Amendment 14 gives a trace-crossed edge `n+1` sub-arcs. A second consumer (`boundaryVertices`) over-inserts silently. R9-CAND-01 / R9-REV, measures AI1-AI3.
- [ ] **Prescribed sphere A2a′ upstream error:** AF0 now publishes `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28`; review the exact rotation-system locus before any product fix.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **65**. PR #8 remains open, draft, and unmerged.
