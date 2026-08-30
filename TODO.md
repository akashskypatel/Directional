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

## Current focus — `M3-CP4c-2-TB-X2-R9-EXEC` — immutable artifact-only gate 365

CB8 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic/test source
`05f9ef299ee54f8c9d50318fc9a37e5a5503740d`.
`Architecture_M3_CP4c2_CB8_Code_Build_Report.md` is the owning report.

CB8 corrected the two R8-REV witness identities without product changes: ordinals 359/361 now consume one
production feature authority (rails, hard-feature edges, component labels, sheet labels), the closed-witness rail
precondition is self-checking, and the default-constructed error sentinel is replaced by a typed failing-stage
result. AH1's retained R8 evidence proved that the former empty network reached `SurfaceCutGraph::make`; because the
R8 process did not print the real cut-graph code/origin, CB8 records the zero-node/zero-arc behavior as
`R8-CAND-02` rather than inventing a product diagnosis.

Immutable package **66** is artifact `9726295440`, SHA-256
`1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`, packaged source SHA-256
`ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`, build run/job
`33292137782 / 99205507393`. All eight standard targets compiled/linked with GMP/GMPXX; internal manifest 28/28;
`runtimeExecution=false`. Selector 365 and all 355/357/361 prefixes remain byte-frozen.

### R9 required execution

Follow `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Plan.md` exactly:

- immutable preflight; preserve executable modes; **no repair/chmod/configure/compile/relink/generated discovery**;
- frozen prescribed-sphere non-gating publisher plus AF2 D2 and AG3 actual-graph oracle, one process each;
- selector 365 **from ordinal 1**, one fresh process per identity, first-semantic-red hard stop;
- accepted prefix must re-prove 355/355;
- `R8-CAND-01` closes only if 359 and 361 both pass in a run reaching 361;
- ordinal 362 owns criterion C3; 363–365 are Amendment 14's first runtime evidence;
- AH6: if 363–365 run, publish whether trace-crossed selection is ordinary tree–cotree or saturation-only. If
  saturation-only, record a new non-stable coverage candidate and keep CP4c-2 open even if 365/365 is green;
- no benchmark is frozen for R9; `benchmarkExecution=false`;
- unconditional postflight plus regression-tracker update for every observed change.

### CP4c-2 gate authority

**Selector 365** — `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt`, whole-file SHA-256
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. Prefix hashes remain:
355 `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 361 `61918d9f…0288b`. Cardinality/uniqueness 365/365.

### Open CP4c-2 candidates / debts

- [ ] `M3-CP4c2-TB-X2-R8-CAND-01` — former vacuous-authority construction in 359/361. Code/test correction is built;
      closes only when **both** identities pass in a run reaching 361. Supersedes `R7-CAND-01`.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — zero-node/zero-arc closed-surface `SurfaceCutGraph` behavior is unresolved;
      **product question / non-gating / non-stable**. R9's gate does not depend on that input.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — prescribed sphere producer `RotationSystemInconsistent` at source face `25-27-28`
      before cut selection, plus independently non-cellular pre-cut graph `V/E/F=18/30/18`, `chi=6` vs `sourceChi=2`.
- [ ] **AH6 ordinary-path coverage** — adjudicate at 363–365; a saturation-only result owes a second witness.
- [ ] **Criterion C3** — ordinal 362, still unexecuted.
- [ ] Measure **AD3** — raw `face.orbit` index in semantic digest; falsifier is ordinal 359.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **66**.
`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`. CP4c-2 and CP4c-3 remain open;
CP4c-3 is blocked behind R9/review disposition.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R8 re-proved the inherited **355/355** and passed 356-358, then stopped red at new gate ordinal 359 before its invariance comparison. Criteria C1/C6 are green on the produced torus; the red is a two-identity witness defect, not a product defect. CP4c-2 remains unaccepted. Exact next is `M3-CP4c-2-CB8` under AH0-AH9; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 gate ordinal 359:** production raw-field migration is incomplete at the rail-authority surface; the gated direct witness still uses `rails_from_atlas(...)` and fails before enumeration invariance is tested. R8-CAND-01 / R8-REV.
- [ ] **Prescribed sphere A2a′ upstream error:** AF0 now publishes `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28`; review the exact rotation-system locus before any product fix.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **65**. PR #8 remains open, draft, and unmerged.
