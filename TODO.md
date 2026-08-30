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

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the chain it **is**
the review-and-plan turn: one turn freezes definitions, adjudicates inherited candidates, decides gate membership,
and issues the successor's measures. Only the `REVIEW+PLAN → DEFN` edge collapses; a red TB with no `DEFN` ahead of
it still gets its own review turn.

## Current focus — `M3-CP4c-3-DEFN-R1` (combined definition + review)

`M3-CP4c-3-TB1` is **COMPLETE / VALID SEMANTIC RED / REVIEWED**. The independent review is
`Architecture_M3_CP4c3_TB1_Independent_Review_Record.md`, measures **AL0–AL9**; the retained execution report is
`Architecture_M3_CP4c3_TB1_Artifact_Only_Test_Benchmark_Report.md`.

TB1 (run/job `33340448381 / 99335020672`, immutable package **68** artifact `9739919234`, semantic source
`48dd011c4aa689a245b74527ed9df0900ada9bf3`) re-proved the accepted prefix **365/365 PASS** and hard-stopped at
ordinal **366** — `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`. Execution
validity is **ACCEPTED**: immutable package consumed directly, preflight/postflight PASS, every
configure/compile/relink/repair/generated-discovery/benchmark/mutation flag false. Frozen selector **367** remains
byte-identical at SHA-256 `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`, and the working tree
is byte-identical to the packaged semantic source (`git diff --stat 48dd011c… HEAD -- tests/ src/ include/` empty).

### What phase 1 established

- **Mechanical witness — CAUSE ESTABLISHED.** `CycleTransportAdjacencyMissing`, region `0`, source edge `0-3`,
  `fieldTransportAdjacencyExists=false`; sole region `V/E/F=152/450/300`, χ=2, genus 0, `boundaryLoops=0`, 152
  interior vertices / expected cycles / rows / curvatures, 450 inner adjacencies, `globalEF = localEF = 1,158`.
  Edge `0-3` is a `HardFeature` **barrier** by elimination over the four adjacency buckets. Regions skip hard
  features when flood-filling, but that **disconnects nothing unless the edges separate** — and on a χ=2 region they
  provably cannot all be closed curves, so the feature set contains at least one **open arc**. The region
  decomposition and the traversability classification disagree about the same edge.
- **Prescribed sphere — ONE LEVEL SHORT.** `RotationSystemInconsistent → TraceEventPositionInvalid`, reached with
  source topology, atlas and network all available (24 traces / 56 events). `TraceEventPositionInvalid` is itself a
  two-way collapse (`positions.empty()` vs `positions.size() > 1`) whose branches need **opposite** fixes, plus a
  widening second pass that can manufacture the ambiguous case. Not actionable until AL3 reports.
- **The two causes do not share a locus** — A1 `FieldTransportAtlas` vs A2a′ `EmbeddedGraphTopology` — so they may
  be worked independently.
- Frozen non-gating diagnostics executed in full: **0 PASS / 3 RED**, report-only. Three workflow controls failed in
  preflight and executed no Directional runtime; `33340448381` is the sole semantic TB1 authority. One control is
  the **third** `R7-ORCH-01` malformed-digest occurrence, escalated to a mechanism by AL8.

### Exact next turn

Run **`M3-CP4c-3-DEFN-R1`** — a combined definition + review turn under the standing cadence. It must:

1. settle **AL2** normatively: what a topology region *is* when a barrier does not separate — option **A** (cut the
   local mesh along the arc so it becomes boundary, recommended) versus option **D** (fail closed with a precise
   typed error), with option **C** (giving a barrier edge a transport adjacency) **explicitly prohibited**;
2. if A: write down the treatment of an open arc's **endpoints**, where the cut surface touches itself, with its
   derivation — not left to the implementation;
3. show, rather than assert, that `χ`, `boundaryLoops` and `expectedCycleCount` stay consistent for a slit region;
4. record the decision as an amendment in `DESIGN.md` §7.2.1 alongside 12, 13 and 14;
5. keep selector 367 frozen until AL7's already-defined append point, and do not weaken the accepted 365 prefix.

Then **`M3-CP4c-3-CB2`** under **AL3** (resolve `TraceEventPositionInvalid` one level further) and **AL5** (the
mechanical fix). **AL4** forbids designing the sphere's fix before AL3 reports.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **68**.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — cause established; **AL2** owns the normative decision, **AL5** the fix, **AL1**
  the confirming measurement (feature-set arc decomposition: components, closed loops, open arcs, endpoints).
- [ ] `M3-CP4c2-TB-X2-CAND-04` — prescribed sphere, gated, **ACTIVE / ONE LEVEL SHORT**; **AL3** owns the next
  resolution, **AL4** forbids designing across it.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — per-face-chord proposal-heuristic correction, AK4/**AL6**; unchanged by TB1,
  no shared locus, neither blocks nor is blocked.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — typed empty-network rejection, AK5/**AL6**; same.
- [ ] **AL7** — append `PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`,
  `OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`,
  `EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` to selector 367, producing gate **370**, with all five
  earlier prefixes re-verified. Omission requires a written rationale.
- [ ] **AL8** — move the 64-lowercase-hex digest validation into the orchestration payload authoring path itself.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 selector **367** is frozen; CB1 phase-1 instrumentation is compile-green in package **68** and TB1 is a valid semantic red after re-proving the accepted **365/365** prefix. TB1 is now reviewed: the mechanical witness's cause is **established** (a non-separating hard-feature barrier left interior to its region), the prescribed sphere's is **one level short**, and the two do not share a locus. Phase 2 is authorized for the mechanical witness only, and `M3-CP4c-3-DEFN-R1` must settle AL2's normative question first.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** a non-separating `HardFeature` barrier edge stays interior to its topology region, so the cycle basis spans an edge the atlas deliberately gave no adjacency. Cause established at TB1; the corrective is a **normative** choice owned by `M3-CP4c-3-DEFN-R1` (AL2), not by a CB.
- [ ] **Prescribed sphere A2a′ upstream error:** resolved to `RotationSystemInconsistent → TraceEventPositionInvalid`, which is itself a two-way collapse. AL3 must distinguish `NoCarrierMatch` from `AmbiguousCarrierMatch` — and report which pass produced it — before any product fix.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **68**. PR #8 remains open, draft, and unmerged.
