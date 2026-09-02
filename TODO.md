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

## Current focus — `M3-CP4c-3-CB15` (Code + Build, PRODUCT CORRECTION)

`M3-CP4c-3-TB12-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB12_Independent_Review_Record.md` (**BI0–BI7** discharged, static only).

TB12's ordinal-366 red — `RotationRayOrderKeyCollision;sourceVertex=47;certificationAttempt=0;certificationCutEdges=0`
— now has a **proved root cause**: **BI2 alternative 2**, valid distinct rays collapsed by an under-discriminating
collision-equivalence contract.

- **Both rays are valid.** v47 is an index-`+1` singularity with `expectedValence = 3`; the complete, untruncated
  5-ray census shows its three `Forward` rays (ordinals 0, 1, 2) in three **different** wedges, plus two `Reverse`
  terminations arriving from singularities 71 and 10 — the path CB12 made correct. Alternatives 1 and 4 falsified.
- **The fan is correct down to the wedge.** `build_vertex_fan_slots` alternates edge(even)/face(odd) slots, so each
  face slot lies strictly between its bounding edge slots. Only the order of two rays *inside one wedge* is
  undefined. Independently reproduced by `tools/fixture_probe.py fan 47`.
- **`secondary` is the designated within-wedge rank, filled with the wrong quantity** — `port->ordinal` from the
  ray's **origin** namespace. At locus 47 the arriving ray's `secondary=0` comes from a port at vertex **71**. It
  is written at exactly one vertex-locus site, and was never load-bearing where it was correct.
- **The correct convention already exists one branch away**, in `edge_locus_secondary_rank`: locus-relative, exact,
  explicitly geometry-free.
- **Ordering by identity is semantically wrong.** Ray order about a vertex is a property of the embedding;
  arc/trace ids do not track it, so a rotation ordered by them could disagree with the surface being certified.
- **Accepted-boundary safety is structural.** `secondary` is compared only on a `primary` tie; a `primary` tie
  between trace rays means a shared wedge; every shared-wedge case is a hard error today. Redefining it cannot
  change any currently-succeeding rotation.

`M3-CP4c3-TB11-REV-CAND-01` is **CLOSED / RUNTIME DISCRIMINATED**; `M3-CP4c3-TB11-CAND-01` transitions to **root
cause proved**; new `M3-CP4c3-TB12-REV-CAND-01` is **ACTIVE**. The 371/372 coupling stays **DEFERRED**; sphere 368,
saturation 369, ordinal 370, folded-cone 374, vertex 30 and the finalize/contact fall-through are unchanged.

### Exact next turn

Run **`M3-CP4c-3-CB15`** under §8.2 **BJ0–BJ9** of
`Architecture_M3_CP4c3_TB12_Independent_Review_Record.md`.

- [ ] **BJ0** — selector 378 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BJ1** — replace the vertex-locus `secondary` with an **exact within-wedge rank about the locus vertex**,
      following the `edge_locus_secondary_rank` convention. Exact rationals only.
- [ ] **BJ2** — handle both orientations; rank a wedge-terminating ray from its terminal barycentric point.
- [ ] **BJ3** — keep exactly-coincident rays **fail-closed** under a distinct typed condition.
- [ ] **BJ4** — **do not** add `arc`/`trace`/`orientation` to the predicate or comparator.
- [ ] **BJ5** — positive (two rays, one wedge, distinct angles), negative (coincident → fail closed) and
      regression (one ray per wedge → byte-identical rotation) witnesses.
- [ ] **BJ6** — append selector 379 only on demonstrated falsification.
- [ ] **BJ7** — prohibitions: no other ordering/cut/topology change; no CB12/CB14 revert; no finalize/contact
      repair; no 371/372 decoupling; no Mandatory/Cut same-slot change; no sphere/369/370/folded-cone correction.
- [ ] **BJ8** — audit by assumption; prove no accepted-green rotation changes.
- [ ] **BJ9** — publish the five `M3-CP4c-3-TB13` discriminators. **No vertex-30 discriminator.**

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **79**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB12 is current runtime authority at accepted prefix 365 / first red 366, a distinct-ray same-sector `RotationRayOrderKeyCollision` at source vertex 47. Exact next is independent `M3-CP4c-3-TB12-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — ordinal 366 rotation-key collision under discrimination:** TB11 localized the current first red to `build_rotation_system` as `RotationRayOrderKeyCollision` at `sourceVertex=47`, initial certification attempt 0 with zero cut edges. TB11-REV proved the retained evidence could not distinguish duplicate/stale incidence, an insufficient order key, valid coincident rays requiring defined tie semantics, or a witness/precondition alternative. CB14 adds diagnostic-only two-ray and fan-census evidence without changing ordering/cut semantics; package 82 is build-green and unexecuted. `M3-CP4c3-TB11-REV-CAND-01` remains active until TB12 runtime evidence discriminates the alternatives. No semantic correction is authorized before that result. Vertex 30 and the separate finalize/contact fall-through remain open and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **79**. TB12 is complete VALID SEMANTIC RED; exact next is independent `M3-CP4c-3-TB12-REV`. PR #8 remains open, draft, and unmerged.
