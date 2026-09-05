# Directional Surface-Cell TODO

Last updated: 2026-09-04 UTC

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

## Current focus — `M3-CP4c-3-CB32` (Code + Build, runtime-free) — LAST DIAGNOSTIC TURN ON THIS FRONTIER

`M3-CP4c-3-TB27-R1` is **COMPLETE / VALID SEMANTIC RUNTIME / SEMANTIC RED / ACCEPTED PREFIX SAFE**, and
`M3-CP4c-3-TB27-INDEPENDENT-REVIEW` has adjudicated it. Immutable CB31 package `9961564041` / semantic source
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc` executed selector 406 in run/job `33946094875 / 101252363079`.

- ledger: **399 PASS / 7 RED**, accepted **1–365 = 365/365 PASS**;
- RED ordinals: `366,367,368,369,370,374,398` — **the smallest RED set of the checkpoint**;
- result/log artifacts: `9963419649 / 9963419830`;
- **393 recovered**; 404 and 406 PASS.

**Independent-review verdict.** Both CK measures landed. Ordinal 404 publishes all four interior-arc rows with both
dart orbits — arc **14** `(0,1)` and arc **22** `(0,3)` **separate**, arcs 20 and 24 are `(0,0)` — refuting the
prior review's all-bridges prediction. Ordinal 406 publishes `matchesFailingComponent=false`: the census is the
certifier's 214-face `NotTraceCut` component, the failure is the plan's 191-face `EmptyFragmentOrbits` one.
**The separating arcs may not be promoted into evidence about the failing component.** No stable event added.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3
package count **92**. CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB32`**, Code + Build, runtime-free, GMP/GMPXX linked, under **CL6–CL9** of
`Architecture_M3_CP4c3_TB27_Independent_Review_Record.md`:

- [ ] **CL6** publish each interior arc's **crossed source faces** untruncated, each face's component id in **both**
      partitions, and the **typed reason** the face is not trace-cut; publish the same for the **failing plan
      component's** interior arcs.
- [ ] **CL7** publish the **subset** relation alongside the refuted equality boolean; unify nothing.
- [ ] **CL9** selector **407** with 406 as an exact prefix; one gating publication/completeness identity; ordinal
      404 strengthened in place.

**CL8 — HARD STOP RULE.** CB32 is the **last diagnostic turn authorized on source-face ownership**. The review that
reads TB28 **must freeze a product correction** whichever branch CL6 measures — a separating arc inside the failing
component selects the barrier-set correction, its absence selects the attribution-rule correction — and an ambiguous
census **defaults to the barrier-set branch**: an arc whose two darts lie in different face-walk orbits must induce
a barrier.

**CB32 corrects no product behaviour.** No Directional runtime before `M3-CP4c-3-TB28`.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted.
  CP4c-3 remains open. **TB27-R1 is the latest valid semantic runtime** at 399 PASS / 7 RED, accepted 365/365,
  on source `eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc` / package `9961564041` / selector406.
  Exact next: **`M3-CP4c-3-TB27-INDEPENDENT-REVIEW`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face ownership derivation:** TB27 runtime proves the certifier and failing plan partitions
  are different (`matchesFailingComponent=false`): certifier component 0 is 214 faces / `NotTraceCut`, while the
  failing plan component is the 191-face `EmptyFragmentOrbits` object. Two of the certifier's four interior trace
  arcs are separating, but those rows are **not evidence about the failing component**. Exact owner/correction for
  that 191-face object remains review-owned; no winner, barrier change, or partition unification is authorized.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

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

Current totals are **44 events / 14 categories / 30 recurrences**, classified at `M3-CP4c-3-TB27-INDEPENDENT-REVIEW` with no stable change. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **92**. **TB27-R1 is the latest semantic runtime authority at 399 PASS / 7 RED, accepted 365/365.** Exact next is `M3-CP4c-3-CB32` under CL6–CL9, the last diagnostic turn authorized on this frontier. PR #8 remains open, draft, and unmerged.
remains **5**. Semantic M3 package count is **92**. **TB27-R1 is the latest semantic runtime authority at
399 PASS / 7 RED, accepted 365/365.** Selector406 remains current. Exact next is
`M3-CP4c-3-TB27-INDEPENDENT-REVIEW`. PR #8 remains open and unmerged.
