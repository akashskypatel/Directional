# Directional Surface-Cell TODO

Last updated: 2026-08-26 UTC

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

## Current focus — `M3-CP4c-0-CB4` — EXACT NEXT / Code + Build, measures G0–G8 (test-side only)

`M3-CP4c-0-TB-R3` is **COMPLETE / VALID SEMANTIC RED** on immutable package `9589508430` at semantic
source `b135e219ee9269a73eaee32992d80c3921318011`. Authoritative run/job `32921851098 / 98036868098`
executed all **338** frozen identities: **336/338 PASS**, accepted prefix **316/316 PASS**, prior CP4c-0
prefix **328/328 PASS**. Ordinal **333** is the first red; ordinal **334** is a later non-crediting red;
ordinals 335–338 pass non-crediting. Supplemental F3 is **2/2 PASS**. Q8 was not creditable and was not run.
Every immutable-gate mutation/build flag remained false.

- [x] `M3-CP4c-0-DEFN` — **COMPLETE.** Frozen definitions remain normative.
- [x] `M3-CP4c-0-CB1` — **COMPLETE / BUILD GREEN.** No runtime in CB.
- [x] `M3-CP4c-0-TB` — **COMPLETE / VALID RED.** 328/328 gate PASS; binding Q8 RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — **COMPLETE.** Root cause adjudicated; E0–E10 frozen; T6/Q8 unchanged.
- [x] `M3-CP4c-0-CB2` — **COMPLETE / BUILD GREEN.** Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — **COMPLETE / VALID SEMANTIC RED.** 1–328 PASS; ordinal 329 RED; Q8 not run.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — **COMPLETE.** Amendment 6; F0–F8 frozen.
- [x] `M3-CP4c-0-CB3` — **COMPLETE / BUILD GREEN.** Package `9589508430`; frozen selector unchanged.
- [x] `M3-CP4c-0-TB-R3` — **COMPLETE / VALID SEMANTIC RED.** 338 executed, 336 PASS; first red
  `333 / ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`; later non-crediting red
  `334 / ExactVertexSectorPartitionsAcceptedInteriorFans`; identity 338 non-crediting green; F3 supplemental
  **2/2 PASS**; Q8 **NOT RUN**.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — **COMPLETE.** Both reds are **test-side; production is correct at
  both sites and no production measure is authorized.** Ordinal 333 throws
  `compute_edge_quantities(): DCEL consistency check failed` **before the predicate runs** — the fixture
  builds a **single-triangle** mesh and `checkPureBoundary` rejects any face with no interior edge, so
  every candidate is invalid regardless of coordinates (0 ms failure confirms it). Ordinal 334 is an
  **oracle defect originating in this reviewer's E8 spec**: `FieldBranch` is **gauged per face**, so
  iterating one numeric label across four faces compares four different physical directions — the gauge
  model derived from source reproduces the observed `0, 1, 0, 3` exactly. **Amendment 7** issued;
  measures **G0–G8** frozen. Record:
  `Architecture_M3_CP4c0_TB_R3_Review_Plan_Independent_Review.md`.
- [ ] `M3-CP4c-0-CB4` — **EXACT NEXT.** Code + Build only, measures **G0–G8**, **test-side only — no
  production source change is authorized.** G1 gives ordinal 333 a DCEL-valid witness and screens before
  `set_mesh`; G2 rebuilds ordinal 334's oracle on the published `signedLift`; G3 adds an independent
  local-holonomy check so G2 is not circular; **G4 de-encodes the supplemental falsifier that currently
  asserts the sphere fails**; **G5 adds a non-gating identity publishing the sphere's A2a outcome.**
  Compile only — **execute nothing.**
- [ ] `M3-CP4c-1` — **OPEN, blocked on CP4c-0.** C4/C5 stay gating; 318 selector untouched.
- [ ] `M3-CP4c-2-DEFN` — **BLOCKED.** Owns `DESIGN.md` §7.2 index-free closed-surface seam gap.
- [ ] `M3-CP4c-3-DEFN` — **BLOCKED.** Owns mechanical missing-adjacency localization.

Frozen selector authority is unchanged: full 338 `d588cae0…`, first-316 `601ce2b6…`, first-328
`cf93622e…` — all three **recomputed locally during review** and matching. **Identity 338 green is not a
Q8 substitute.** Q8 remains verbatim frozen and unconsumed; latest accepted runtime remains CP4ab
**316/316**. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **42**.

**Two results from TB-R3 that outrank the two red identities.**

1. **F6 worked.** Continue-and-observe executed all 338 despite a red at 333. That is the only reason
   334's red, 335–338's greens, and identity 338's pass are known at all. One cosmetic red no longer
   costs a cycle.
2. **The prescribed sphere still does not publish a network.** The supplemental falsifier
   `TracingPathNeverPublishesSeedIdentityAsFailureLocus` contains `ASSERT_FALSE(networkBuild)` and it
   **passed** — direct runtime proof. So **Q8 is expected to fail next cycle even at 338/338**, and that
   assertion will invert the moment CP4c-0 succeeds (measure G4). Identity 338's pass does confirm
   E2–E5 removed the `BranchContinuationDegenerateEntry` family from the sphere — real progress — but
   the current rejection code is still **unpublished by anything in the gate** (measure G5).

## After M3 exit

`ROADMAP.md` §4 proposes the checkpoint decomposition for **M4–M8** — seventeen checkpoints plus five `-DEFN` planning turns to reach `M8-CP3`, the production-ready exit. That decomposition is a **proposal until each milestone's `-DEFN` turn freezes it**; gate arithmetic beyond 322 is deliberately not fixed.

## Carried forward from M2

- [ ] **3 latent fixture-authority sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options assert success but pass only because their complexes never reach boundary-ownership resolution; none are in the frozen selector.
- [ ] **Remove the `= {}` default** on the authority-consuming `complete_surface_cell_complex` overload (`PatchDescriptor.h:427`) so omission stops compiling.
- [ ] **Establish authority-carrying completion options as the local idiom.** `SurfaceCellComplexCompletionOptions` remains authority-unset by default across the affected tests.

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
- [ ] **M3 — field-aligned curve network.** CP4ab accepted at **316/316**; CP4c split into **CP4c-1 (318)**, **CP4c-2 (321)**, **CP4c-3 (322)**.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **42**. PR #8 remains open, draft, and unmerged.
