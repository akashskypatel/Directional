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

## Current focus — `M3-CP4c-3-TB12-REV` (Independent REVIEW + PLAN only)

`M3-CP4c-3-TB12` is **COMPLETE / VALID SEMANTIC RED / NON-STABLE**. Record:
`Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Report.md`. Frozen successor:
`Architecture_M3_CP4c3_TB12_Independent_Review_Plan.md`.

TB12 consumed immutable package **82** / selector **378** only. Run/job `33657062615 / 100338185825` executed
378 fresh selector processes: **370 PASS / 8 RED**. Ordinals **1-365 remain 365/365 PASS**; first red remains
ordinal **366**. Result/log artifacts are `9857275334`
(`085b3de9ebf5a9a29cbcf883e4058c97855e11a1a7b2bc53f961c809dace9145`) and `9857276091`
(`89cac6cb1ea6444b8204d8b5ca9233daed7e0ff88986d8592af576e319cb4120`). Immutable postflight passed; no
configure/compile/relink/repair/generated discovery/mutation/benchmark occurred.

BH9 runtime discrimination is now concrete:

- previous ray: arc 20 / trace 6 / Forward / `(primary,secondary)=(3,0)` / face `(45,46,47)` / slot 1 / origin
  port 0 at vertex **47**;
- current ray: arc 23 / trace 9 / Reverse / `(3,0)` / the same face/slot / origin port 0 at vertex **71**;
- fan census is **5 rays, not truncated**;
- `cutCandidateCount=450`, attempt 0 / 0 cut edges remain measured; unmeasured `nonDiscComponentCount` and
  `remainingAdmissibleEdgeCount` are absent;
- selector ordinal 378 PASSes the production diagnostic projection.

The simplest duplicate-incidence identity explanation is falsified: the two rays have distinct arc/trace IDs,
opposite orientation and different origin vertices. Runtime also proves `secondary` is not vertex-local in this
production failure. The remaining semantic distinction is whether these same-face/same-slot rays are valid and need
a deterministic tie/equivalence rule, represent invalid/stale provenance, or violate a witness/precondition.
`M3-CP4c3-TB11-REV-CAND-01` is **CLOSED / RUNTIME DISCRIMINATED**; `M3-CP4c3-TB11-CAND-01` remains the single
gating candidate, transitioned to **DISTINCT-RAY SAME-SECTOR COLLISION / SEMANTIC POLICY UNADJUDICATED**.

### Exact next turn

Run **`M3-CP4c-3-TB12-REV`** exactly as frozen in
`Architecture_M3_CP4c3_TB12_Independent_Review_Plan.md` — **review/planning only**.

- [ ] Trace arc 20/trace 6 and arc 23/trace 9 end to end and establish whether both incidences are valid at vertex 47.
- [ ] Define the intended vertex rotation collision/equivalence invariant; do not add identity fields to the guard by fiat.
- [ ] Adjudicate why an arriving ray from origin vertex 71 uses origin port ordinal 0 as `secondary` at locus 47.
- [ ] Distinguish valid coincident/tie semantics from invalid/stale provenance or witness/precondition failure.
- [ ] Reconfirm 367/371/372 share the same upstream stop and preserve 368/369/370/374 ownership unchanged.
- [ ] Freeze exactly one bounded successor only after the semantic owner is proved.

No runtime, build, package, product/test/fixture/selector mutation, or unchanged TB12 retry belongs in the review.
Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events /
14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **79**.

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
