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

## Current focus — `M3-CP4c-3-TB14` (Artifact-Only Test + Benchmark)

`M3-CP4c-3-CB16` is **COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE**. Report:
`Architecture_M3_CP4c3_CB16_Code_Build_Report.md`.

CB16 discharged **BL0-BL9** from the TB13 independent review:

- final source **`6808c090f2dd229a48550d758f459bfd156da4b6`**;
- selector **379** remains byte-frozen at `ef51298f…842594b7`; selector **380** appends exactly
  `GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure`, SHA-256
  `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`;
- `vertex_trace_ray_second_point` adds the exact source-vertex corner fallback **last** in the Forward chain;
- the secondary-parameter emitter now uses `VertexTraceSecondaryParameterUnavailable` plus a typed subreason and
  retained arc/trace/orientation/segment bounds; the legacy port emitter alone retains `VertexTracePortOrdinalInvalid`;
- the eight standard targets compile and link GREEN with mandatory GMP/GMPXX on run/job
  `33682499470 / 100422188581`, artifact `9866902345`;
- immutable package **84** was produced GREEN on run/job `33683929335 / 100426817194`, artifact `9867334959`,
  inner tar SHA-256 `8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`;
- no Directional runtime identity or benchmark ran in CB16.

Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **81**.

### Exact next turn

Run **`M3-CP4c-3-TB14`** exactly under
`Architecture_M3_CP4c3_TB14_Artifact_Only_Test_Benchmark_Plan.md` on immutable package 84.

- [ ] Verify immutable package/source/GMP/selector-380/prefix/mode authority before runtime.
- [ ] Execute selector 380 from ordinal 1, one exact identity per fresh process; first semantic red stops gate
      credit but the remainder still runs once report-only.
- [ ] Re-prove accepted ordinals **1-365 = 365/365 PASS**.
- [ ] Prove ordinal 366 no longer fails at vertex 10 through the old ambiguous reason.
- [ ] If a vertex-trace secondary-parameter red remains, require the new typed reason/subreason and retained
      arc/trace/orientation/segment bounds; `VertexTracePortOrdinalInvalid` now identifies the legacy emitter only.
- [ ] Re-prove the **v47 five-ray conjunction**: old collision absent and the former pair has distinct secondary
      ranks. `M3-CP4c3-TB11-CAND-01` / `M3-CP4c3-TB12-REV-CAND-01` do not close without it.
- [ ] Execute `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` once as non-gating diagnostic.
- [ ] Record any legitimate face-walk non-disc/admissible counters if downstream certification is reached.
- [ ] Update every observed regression/candidate, verify byte/mode-identical postflight, then route green to
      checkpoint closure or red to independent REVIEW + PLAN.

**No vertex-30 discriminator is authorized.** Sphere 368, saturation 369, ordinal 370, the 371/372 coupling,
folded-cone 374, vertex 30 and finalize/contact remain separate carried surfaces unless TB14 produces new evidence.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB13 is the latest runtime authority at accepted prefix 365 / first red 366, now moved to vertex 10 `VertexTracePortOrdinalInvalid`. CB16/package84 is current build authority; TB13 remains latest runtime authority. Exact next is artifact-only `M3-CP4c-3-TB14`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — CB16 build correction awaits TB14 runtime:** TB13's accepted prefix remains 365/365 and its first red is the vertex-10 `VertexTracePortOrdinalInvalid` failure. TB13-REV proved the missing vertex-exit case and reason collapse; CB16 implements the exact last-chain vertex-corner fallback and splits the secondary-parameter reason, but no runtime acceptance is claimed. TB14 must confirm vertex 10 clears, re-prove the full five-ray/distinct-rank v47 conjunction, and classify the next frontier. `M3-CP4c3-TB13-CAND-01` and `M3-CP4c3-TB13-REV-CAND-01` remain runtime-open until that evidence exists. Vertex 30 and finalize/contact remain separate and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **81**. CB16 is COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE; exact next is artifact-only `M3-CP4c-3-TB14` on immutable package 84. PR #8 remains open, draft, and unmerged.
