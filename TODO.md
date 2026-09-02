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

## Current focus — `M3-CP4c-3-TB12` (Test + Benchmark, ARTIFACT-ONLY)

`M3-CP4c-3-CB14` is **COMPLETE / BUILD GREEN / DIAGNOSTIC-ONLY**. Record:
`Architecture_M3_CP4c3_CB14_Code_Build_Report.md`.

Final compile/package source is **`71ece3ca184e90858d9222fb014b37c16d292294`**. Compile run/job
`33653092570 / 100324843819` built all eight standard targets with GMP/GMPXX and `runtimeExecution=false`. Immutable
package **82** is artifact `9855841174`, Actions SHA-256
`4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`; inner `package82.tar.gz` is
`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`; packaged source archive is
`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`.

CB14 discharged BH0-BH9 without a semantic correction:

- both colliding rotation rays now retain typed `primary`/`secondary`, arc/trace/face, orientation, fan slot, and
  origin-port ordinal/source-vertex evidence;
- the failing vertex publishes a bounded keyed-fan census with total/truncation state;
- certification counters are optional and no longer render unmeasured default zeros;
- a production-renderer synthetic diagnostic witness and the mechanical ordinal-366 failure-message assertion were
  compiled but **not executed**;
- selector **377** remains byte-frozen at `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`;
  selector **378** is 377 plus exactly one diagnostic identity, SHA-256
  `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`;
- collision predicate, comparator, `RayOrderKey`, key construction, incidence, rotation publication, cut decisions,
  fixtures, and unrelated deferred owners remain untouched.

`M3-CP4c3-TB11-REV-CAND-01` remains **ACTIVE / UNDERDETERMINED** pending runtime discrimination. The 371/372
fixture-coupling candidate, sphere 368, saturation 369, ordinal 370, folded-cone 374, vertex 30, and the
finalize/contact fall-through keep their prior ownership/disposition.

### Exact next turn

Run **`M3-CP4c-3-TB12`** exactly as frozen in
`Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Plan.md`.

- [ ] Preflight immutable package 82 and selectors 373-378; no repair/rebuild/relink/generated discovery.
- [ ] Execute selector **378 from ordinal 1**, one exact identity per fresh process; first-red gate accounting only.
- [ ] Require ordinals **1-365 = 365/365** and ordinal **366** to remain
      `RotationRayOrderKeyCollision;sourceVertex=47;certificationAttempt=0;certificationCutEdges=0`.
- [ ] Preserve both colliding ray identities and the bounded fan census at vertex 47; classify the evidence among
      duplicate/stale incidence, insufficient order key, valid coincident rays/tie semantics, or witness/precondition.
- [ ] Require the two certification counters to be populated only when measured, otherwise absent.
- [ ] Execute `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` once separately with zero gate credit.
- [ ] Execute remaining selector identities report-only after first red, immutable postflight, and update the regression
      tracker before TB12 closes.

No semantic correction is authorized before TB12 evidence separates the alternatives. Accepted semantic authority
remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14 categories / 30 recurrences**;
produced-witness debt **5**; authoritative semantic M3 package count **79**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB11 remains current runtime authority at accepted prefix 365 / first red 366, `RotationRayOrderKeyCollision` at source vertex 47 during initial certification. CB14 is build-green diagnostic-only on immutable package 82; exact next is artifact-only `M3-CP4c-3-TB12`.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **79** after CB14/package 82; TB12 has not started. PR #8 remains open, draft, and unmerged.
