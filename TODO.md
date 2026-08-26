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

## Current focus — `M3-CP4c-0-DEFN-2` — EXACT NEXT / Definition only

`M3-CP4c-0-TB-R7` is **COMPLETE / VALID SEMANTIC RED**. Authoritative control/run/job `3d1ef24d6bcccb7e4e821d713a21860bc0598bd0 / 33019554121 / 98346293968` consumed only CB7 package `9625495708`. Result `9626003625 / 61994abc1e67fc55bc1d48d38a521598b6b56e458972d948ebcae112fa27eaaa`; diagnostic log `9626004016 / 9f6307b90b93ba557af7643c5a2d4a021969708b2a77e74fc546ae4f263e441c`. Frozen gate is 338/338, accepted 316/316, first-328 328/328, F3 2/2; postflight immutable.

K1 reproduces the legitimate near-tangency separation; J3 remains legitimate 524/524 as a principal-matching implementation cross-check; independent K3 holonomy covers 176/176 complete fans with zero mismatches. K2 reaches grazing on 0/24 traces and is non-decisive: P3 was not observed and the proxy supplies no trace-level cost discrimination among the four frozen grazing models. Q8 remains **CREDITABLE / RED at criterion 2**.

Read `Architecture_M3_CP4c0_TB_R7_Artifact_Only_Test_Benchmark_Report.md`. `M3-CP4c-0-DEFN-2` must close the `DESIGN.md` §4.5 contract for an edge where the neighbouring face's direction also exits. Compare the four frozen options — tangential continuation, typed grazing terminus, refinement precondition, exact-arithmetic joint-face reformulation — and define the chosen model with reasons. Amend Q8 only if that model makes 24 traces unreachable. **Definition only; no production patch and no CP4c-1/2/3.**

- [x] `M3-CP4c-0-DEFN` — COMPLETE.
- [x] `M3-CP4c-0-CB1` — COMPLETE / BUILD GREEN.
- [x] `M3-CP4c-0-TB` — COMPLETE / VALID RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB2` — COMPLETE / BUILD GREEN. Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — COMPLETE / VALID SEMANTIC RED.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB3` — COMPLETE / BUILD GREEN. Package `9589508430`.
- [x] `M3-CP4c-0-TB-R3` — COMPLETE / VALID SEMANTIC RED. 336/338; F3 2/2.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — COMPLETE. Both reds test-side; Amendment 7; G0–G8.
- [x] `M3-CP4c-0-CB4` — COMPLETE / BUILD GREEN. Package `9591540182`; test-side corrections only.
- [x] `M3-CP4c-0-TB-R4` — COMPLETE / VALID SEMANTIC RED. 338/338; Q8 RED criterion 2.
- [x] `M3-CP4c-0-TB-R4-REVIEW-PLAN` — COMPLETE. H0–H7 frozen.
- [x] `M3-CP4c-0-CB5` — COMPLETE / BUILD GREEN. Package `9601160869`.
- [x] `M3-CP4c-0-TB-R5` — COMPLETE / VALID SEMANTIC RED. 338/338; H1 delivered.
- [x] `M3-CP4c-0-TB-R5-REVIEW-PLAN` — COMPLETE. Amendment 8; J0–J7 frozen.
- [x] `M3-CP4c-0-CB6` — COMPLETE / BUILD GREEN. Package `9619352525`.
- [x] `M3-CP4c-0-TB-R6` — **COMPLETE / VALID SEMANTIC RED.** 338/338; F3 2/2; J3 legitimate 524/524 geometry agreement; Q8 RED criterion 2.
- [x] `M3-CP4c-0-TB-R6-REVIEW-PLAN` — **COMPLETE.** Root cause **identified**: the disagreements are a
  **near-tangency discretization phenomenon**, and **Amendment 4 / measure E5's invariant is too strong**
  for a piecewise-constant field. Reproduced the sphere census from the committed fixture alone —
  **exactly 144 directed**, matching runtime — and measured the tangency ratio: disagreeing median
  **0.0218** vs agreeing **0.9233**, every disagreement ≤ **0.2004**. At the live locus **every published
  term is independently verified correct** (matching 0 right with a 42° margin; `0 + 1 − 3 ≡ 2`
  reproduces the lift; both `dbary` triples match to 10 dp; mesh adjacency sound). **One class, not
  two.** Amendment 9 issued. Record:
  `Architecture_M3_CP4c0_TB_R6_Independent_Review_Record.md`.
- [x] `M3-CP4c-0-CB7` — **COMPLETE / BUILD GREEN.** Semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`; package `9625495708`. K0–K7 diagnostic/contract-control only; no production semantics; all eight standard targets compiled/linked; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R7` — **COMPLETE / VALID SEMANTIC RED.** 338/338; F3 2/2; K1 near-tangency reproduced; K2 0/24 reaches grazing (non-decisive); J3 524/524 legitimate; K3 176/176 / 0 mismatches; Q8 RED criterion 2.
- [ ] `M3-CP4c-0-DEFN-2` — **EXACT NEXT.** Closes the `DESIGN.md` §4.5 gap: what a trace does
  at an edge the neighbouring face's direction also exits. Amends Q8 **only if** the chosen model makes
  24 traces unreachable, and only with reasons recorded. **This is a definition turn, not a patch.**
- [ ] `M3-CP4c-1` — OPEN, blocked on CP4c-0.
- [ ] `M3-CP4c-2-DEFN` — BLOCKED.
- [ ] `M3-CP4c-3-DEFN` — BLOCKED.

Frozen selector authority remains **338** `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; accepted first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. Latest accepted runtime remains CP4ab **316/316**. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **46**.

**TB-R6 disposition after review — corrected.** Three standing readings are **withdrawn**:

1. **The live locus does not indict `build_branch_transports`.** Its lift composes correctly
   (`0 + 1 − 3 ≡ 2`), its matching is geometrically right (nearest target raw index at 23.7°, next at
   66.3°), both gauges are right, and both published `dbary` triples reproduce from the fixture to 10
   decimal places. The decision-table row it satisfied is withdrawn as a diagnosis.
2. **There are not two classes.** The unequal-gauge (86/43) and equal-gauge/lift-0 (254/127) populations
   are the same **near-tangency** phenomenon seen through different bookkeeping.
3. **J3's 524/524 does not exclude H-B.** `independent_edge_measurement` re-implements **principal
   matching** — the algorithm H-B suspects — so it is an implementation cross-check, not an aliasing
   test. (H-B *is* excluded, but by direct measurement at the live locus, not by J3.)

**Root cause:** Amendment 4 / measure E5 asserts a **continuum** property that a piecewise-constant field
does not satisfy near edge tangency. The real gap is that **`DESIGN.md` §4.5 does not define what a trace
does at a grazing edge** — a `-DEFN` question, not a patch. **No production change is authorized; there
is nothing in A1 to fix.** Q8 stays red until the model question is settled.

## CP4c documentation — consolidated 2026-08-26

Twenty-four per-turn CP4c execution documents and superseded review briefs were retired into
**`M3_CP4c_Consolidated_Record.md`** under explicit user authorization, preserving every evidence
identifier. Thirty-three CP4c documents became twelve. Retained live: the CP4c-0 DEFN charter and frozen
definitions, the five independent reviews (they carry Amendments 1–7 and measure series E/F/G/H), and
all selector `.txt` authority files. A citation naming a retired document now points at the consolidated
record — **retired provenance, not lost authority**. CP4c-0 and CP4c-1 remain **OPEN**; the record is
historical and closes nothing.
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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **45**. PR #8 remains open, draft, and unmerged.
