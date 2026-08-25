# Directional Surface-Cell TODO

Last updated: 2026-08-25 UTC

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

## Current focus — `M3-CP4c-0-CB2` — EXACT NEXT / Code + Build, measures E0–E10

**`M3-CP4c-0-CB1` is COMPLETE / BUILD GREEN** at semantic source
`e784e44ce86e458b250b04689288f5f365ca507b`; the exact-position/exact-continuation implementation
compiled all eight standard targets and froze **328 = accepted 316 + 12**.

**`M3-CP4c-0-TB` is COMPLETE / VALID RED.** Authoritative artifact-only run/job
`32891161394 / 97943220460` consumed immutable package `9577900736`. The semantic gate is **328/328
PASS** — accepted **316/316** and CP4c-0 **12/12** — but binding Q8 is RED: A2a rejects
`BranchContinuationDegenerateEntry` at `sourceEdge=6-8` before publishing a
`FieldAlignedCurveNetwork`. Required 24 traces, terminal `TraceIntersection`, and face `1-2-5` crossover
therefore cannot be observed. Owning report:
`Architecture_M3_CP4c0_Artifact_Only_Test_Benchmark_Report.md`. Every digest, both job ledgers, and the
retry-0 characterization were re-verified against the GitHub API during review and **all matched**.

The report's `sourceVertex=0` / `singularity=0` are the failing trace's **seed**, back-filled at
`SurfaceCellTracing.cpp:818-819`; they do not locate the failure. Only `sourceEdge=6-8` is a genuine
locus, and it alone cannot separate the three candidate routes. `sourceFace`, the branch, the exact entry
parameter, and `t*` **were computed and discarded** by the witness diagnostic emitter — measure E1.

- [x] `M3-CP4c-0-DEFN` — **COMPLETE.** Frozen definitions remain normative.
- [x] `M3-CP4c-0-CB1` — **COMPLETE / BUILD GREEN.** No runtime in CB.
- [x] `M3-CP4c-0-TB` — **COMPLETE / VALID RED.** 328/328 gate PASS; binding Q8 RED. Retry 0 was
  infrastructure-only before any semantic identity; retry 1 is authoritative. No semantic retry.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — **COMPLETE.** Adjudicated: the defect is neither T6 nor Q8, but the
  frozen definitions. A1 decides the **sign of a barycentric direction coordinate** with a `double`
  tolerance in three places and publishes those verdicts as topological ownership, while A2a decides the
  same sign exactly. T6 correctly rejects a state A1 was incorrectly allowed to produce. Five DEFN
  amendments issued; T6 and Q8 unchanged. Owning record:
  `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`.
- [ ] `M3-CP4c-0-CB2` — **EXACT NEXT.** Code + Build only, measures **E0–E10** (review §10). E1 publishes
  loci that already exist and is what determines the failure route; E2/E3 exactify A1's flow
  classification and vertex-sector rule and delete the lossy round trip; E4/E5 close the T1
  exhaustiveness hole and the unasserted cross-edge flow invariant; E6 replaces the position-blind cycle
  break. After E2–E5, T6 is provably unreachable from well-formed states (review §7). Compile only —
  **execute nothing.**
- [ ] `M3-CP4c-1` — **OPEN, blocked on CP4c-0.** C4/C5 stay gating; 318 selector untouched.
- [ ] `M3-CP4c-2-DEFN` — **BLOCKED.** Owns `DESIGN.md` §7.2 index-free closed-surface seam gap.
- [ ] `M3-CP4c-3-DEFN` — **BLOCKED.** Owns mechanical missing-adjacency localization.

**Standing prohibitions for CB2.** Do not retune, widen, narrow, or delete `kBranchTopologyTolerance`
(every measure **removes** tolerance from topological decisions; none adds any). Do not weaken T6 or Q8.
Do not edit the sphere fixture — §6 of the review establishes both fixture and oracle are valid. No
sphere-specific branch/edge/face/vertex/index special case. Q8 is not creditable until E6 lands, because
a position-blind truncation can alter the trace count and manufacture a terminus.

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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **40**. PR #8 remains open, draft, and unmerged.
