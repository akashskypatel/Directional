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

## Current focus — `M3-CP4c-3-CB12` (Code + Build, PRODUCT CORRECTION)

`M3-CP4c-3-TB9-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB9_Independent_Review_Record.md` (**BC0–BC7** discharged, static only).

TB9's ordinal-366 first red —
`InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2;networkErrorCondition=SingularityTerminationPortOwnershipMismatch;traceSeedVertex=47;traceSeedSingularity=5`
— is classified **BC2 category 1: a genuine product ownership defect on a valid mechanical witness**.

- **Only one of the guard's three subconditions is reachable.** Both `VertexHit` constructions derive the terminal
  vertex **from** `source_support()` (or invert its parameter mapping), and `field_aligned_singularity_at` matches
  **by that same vertex** — so `vertexSupport` is never null and never disagrees with the port's vertex. Disjuncts
  1 and 3 are dead by construction.
- **A missing port means `BarrierAbsorbed`, and nothing else.** The port loop runs over **all** atlas singularities
  with one `continue` on that policy, and `expectedValence ∈ [3,6]` is pre-enforced. On this closed witness that
  means *singular ∧ barrier-incident*.
- **The defect is a category error.** A **port** says where a trace may *originate*; a **node** says what it may
  *terminate at*. The guard reaches the terminal node through `terminalPort->node` — a table the atlas
  deliberately leaves empty for this policy — while the node is allocated **unconditionally** and the terminal
  vertex is additionally a mandatory-barrier endpoint.
- **The witness is ordinary.** From singular corner **v47** down the sharp box edge `(x = -1.4, z = -0.9)` through
  regular vertices 45, 43, 41, 39 — every chain edge at an exactly **90.000000°** dihedral — terminating at
  **v36**. v38 is excluded because its entire star is coplanar.

`M3-CP4c3-TB8-REV-CAND-01` is **CLOSED / RUNTIME PROVED**. New `M3-CP4c3-TB9-REV-CAND-01` is **ACTIVE**.
`M3-CP4c3-TB6-CAND-01`, `M3-CP4c3-DEFN-R2-CAND-01` and `M3-CP4c3-TB7-CAND-02` remain **ACTIVE**. TB8-REV's
`finalize_field_aligned_events` contact fall-through finding is **untouched and still open** — TB9 proves only that
it is not the *first* mechanical failure, and CB12 must not repair it.

**Two adversarial results worth carrying forward.** Geometric sharpness is **not** a proxy for the barrier set
(v47 has three exactly-90° edges and provably emits ports; barriers are region-restricted at
`FieldTransportAtlas.cpp:962`). And accepted ordinal **328**'s port-ownership witness is synthetic and fires
**disjunct 3**, which production cannot reach — the accepted suite does not cover the production disjunct.

### Exact next turn

Run **`M3-CP4c-3-CB12`** under §8 **BD0–BD9** of
`Architecture_M3_CP4c3_TB9_Independent_Review_Record.md`.

- [ ] **BD0** — selectors 374/375/376 byte-frozen; accepted 365 untouched; **GMP/GMPXX linkage mandatory**.
- [ ] **BD1** — own a `BarrierAbsorbed` termination with the singularity's **network node**; publish the same
      `FirstContact` + `SingularityTermination` pair; leave the `Emit` port path unchanged.
- [ ] **BD2** — carry `portPolicy` to the decision point; **do not** infer it from an empty port table.
- [ ] **BD3** — keep `SingularityTerminationPortOwnershipMismatch` correct and reachable for `Emit` (accepted
      ordinal 328 asserts it); add a fail-closed condition for a missing node.
- [ ] **BD4** — add a **missing-port / `BarrierAbsorbed`** witness and a positive `Emit` witness; ordinal 328's
      synthetic witness fires a disjunct production cannot reach.
- [ ] **BD5** — prove on the mechanical fixture that the terminal vertex is **v36** and its singularity is
      `BarrierAbsorbed`; report v36's node id and mandatory-barrier incidence.
- [ ] **BD6** — append **selector 377** only on demonstrated falsification; republish 374/375/376 unchanged.
- [ ] **BD7** — prohibitions: no barrier-termination conversion, no reordering of the `VertexHit` check, no
      synthesized port, **no repair of the `finalize_field_aligned_events` contact fall-through**, no fixture
      mutation, no tolerance or float-derived topological decision, no sphere/370/saturation/folded-cone correction.
- [ ] **BD8** — audit by assumption; prove no accepted-green observable output changes.
- [ ] **BD9** — publish the five `M3-CP4c-3-TB10` discriminators. **No vertex-30 discriminator.**

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **76**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB9 is current runtime authority at accepted prefix 365, first red 366, now naming `SingularityTerminationPortOwnershipMismatch` at seed vertex 47 / singularity 5. Exact next is independent `M3-CP4c-3-TB9-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — singularity-terminal ownership:** TB9 first-red 366 retains `InvalidNetworkTerminalOwnership` at edge `36-38`, face `(36,38,39)`, branch 2, and now names `networkErrorCondition=SingularityTerminationPortOwnershipMismatch`, seed vertex 47 / singularity 5, with five exact untruncated history rows. TB9-REV must determine which internal support/missing-port/source-vertex guard disjunct fires and who owns the invariant before any correction. The finalize/contact fall-through is excluded as this first-red emitter but is not thereby accepted. Vertex 30 remains unreached and row-209/row-208 acceptance remains open. No candidate-order, tolerance, float-transport, `signedLift`-as-ray, or target-representative shortcut.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **76** after CB11/package 79; TB9 created no package. PR #8 remains open, draft, and unmerged.
