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

## Current focus — `M3-CP4c-3-CB10` (Code + Build, runtime-free, GMP/GMPXX linked)

`M3-CP4c-3-TB7-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB7_Independent_Review_Record.md`, measures **AW0–AW7** discharged, static only.

It explained **both** TB7 reds and proved they have **different owners**:

- **Ordinal 366 — CB9-introduced product defect.** `AY1` added a fifth seed guard absent from the source TB6 ran,
  applying the **half-open ownership convention** `direction[next] > 0 ∧ direction[previous] ≥ 0` as an
  *admissibility test on the incoming arrival ray*. Proved exactly from committed fixture bytes: face `(8,10,11)` is
  mesh row 8 and its branch-1 direction is `(0, −2.77777777777777857, +2.77777777777777857)` over `(v8, v10, v11)`
  with an **exact IEEE zero** at `v8`, so the port trace out of singularity vertex 10 runs along mesh edge `(10,11)`
  and lands on vertex 11 (Amendment 3); its arrival ray is exactly the radial ray `v11 → v10`, which neighbouring
  row 109 `(79,11,10)` owns. A second guard at `SurfaceCellTracing.cpp:1531-1540` rejects the mirror orientation, so
  the two together make **every** edge-collinear vertex arrival unresolvable in `FaceInterior` mode. **Not** a TB5
  recurrence: shared locus, different mechanism, no recurrence counted.
- **Ordinal 374 — invalid witness, legitimate product rejection (AW4 category 1).** The folded cone has
  `Θ = 3π/2`, angle defect `K = π/2`, while `make_zero_transport_field` declares `effort ≡ 0` and no singularities;
  discrete Gauss–Bonnet forces `exactLift = 1` against a matching composing to `0` →
  `CycleTransportMismatch` at `FieldTransportAtlas.cpp:2098`, with `SingularityMismatch` behind it. **No atlas
  invariant may be weakened.** Corrective is test-only, specified, and **deferred**.

**Amendments 22 and 23 survive intact.** `DEFN-R2` §AX1 never imposed CB9's guard, and §AX7 §7.2 item 5 *required*
the on-radial-ray seed CB9 made unreachable. Accepted authority remains **365**; CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB10`** under **AZ0–AZ9** in
`Architecture_M3_CP4c3_TB7_Independent_Review_Record.md` §8. **Product-only**; Code + Build is runtime-free and
GMP/GMPXX linkage is mandatory.

- [ ] **AZ0** selector 374 byte-frozen and recomputed at authoring and preflight; accepted 365 untouched;
      `selected_gate=NONE`; `gate_execution_authorized=false`; no runtime, gate, benchmark, or package repair.
- [ ] **AZ1** add a separate exact **closed-wedge** admissibility predicate (`next ≥ 0 ∧ prev ≥ 0`, not both zero);
      leave `direction_in_vertex_sector` unchanged and reserved for developed-sector ownership.
- [ ] **AZ2** support the on-radial-ray arrival in **both** orientations; remove the two `FaceInterior` rejections;
      define `α` exactly on each radial ray and route ray-exact cases to the exact fallback.
- [ ] **AZ3** one typed name per condition — split the three conditions currently sharing
      `SeedDirectionNotBarycentric`, and report the distinct-condition count at each name's setting site.
- [ ] **AZ4** build the `VertexStarTransitAudit` and seed **before** the first returning conditional; demonstrate
      reachability of all four typed states, including `SeedUnavailable`.
- [ ] **AZ5** give the AX8 rows a reader; find consumers **by search against a predicate**, and name at least one
      the measure did not name. Closes `M3-CP4c3-TB6-CAND-01`.
- [ ] **AZ6** derive the on-radial `FaceInterior` witness from the mechanical vertex-11 star, both orientations,
      expected owner derived from Amendment 22 before the code; selector 375 appended **only** on demonstrated
      falsification.
- [ ] **AZ7** prohibited: weakening or reusing `direction_in_vertex_sector` for admissibility; any tolerance or
      float-derived topological decision; `signedLift` as ray transport; candidate ordering/nearest-angle/tie-break;
      deciding from a candidate's own representative; repairing `build_boundary_pairing` as if it caused 366;
      touching the ordinal-374 witness, the sphere, ordinal 370, or atlas invariants.
- [ ] **AZ8** audit by assumption, two predicates, each with a site named outside this record.
- [ ] **AZ9** publish the expected TB8 discriminators.

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **74**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB7 first-red at ordinal 366 is now explained as a CB9-introduced seed-admissibility defect, and ordinal 374's stop is classified as an invalid witness precondition. Exact next is `M3-CP4c-3-CB10` under AZ0–AZ9, product-only.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB7 first-red at ordinal 366 is a CB9 seed-admissibility defect at source vertex 11, proved exactly; vertex 30's frozen answer is **masked** by it and untested since TB6. CB10 must clear vertex 11, after which TB8 must prove the mechanical witness elects row 209 or 208, never row 41, and then carry selector 374 through the full gate. No candidate-order, tolerance, float-transport, `signedLift`-as-ray, or target-representative shortcut.
- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. Ordinal 374 stays red in TB8 by construction; that is pre-classified.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **74** after CB9/package 76. PR #8 remains open, draft, and unmerged.
