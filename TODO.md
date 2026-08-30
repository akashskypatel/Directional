# Directional Surface-Cell TODO

Last updated: 2026-08-29 UTC

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

## Current focus — `M3-CP4c-2-TB-X2-R8-EXEC` — immutable selector-365 execution

`M3-CP4c-2-CB7` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. Semantic product/test source
`4f0f3ca74a88ba260a20c019437bc4995f2056e0` implements Amendment 14, the deferred AF0/AF2/AF3/AF4 work, and
AG1–AG7. A transport-only source `1230621baff6d04fb20df3b1bf48903cd65b5d69` changed only temporary control
state plus Eigen's remote URL to the verified GitHub mirror while retaining exact gitlink
`769c72fd8019e389810d1de1e7c243521a43b594`; no product/test/fixture/selector byte differs.

Authoritative GMP compile/package run/job `33287281975 / 99192562149` built all eight standard targets with
`runtimeExecution=false`, clean source status, and exit `0`. Immutable result artifact **`9724864897`** has
SHA-256 `a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`; compile log artifact
`9724865018` has SHA-256 `462090e66648fc6db583b770a2518aca0a3f63ee2ae167d900070fb4ed5460bd`.
Full build authority: `Architecture_M3_CP4c2_CB7_Code_Build_Report.md`.

Selector **365** is now frozen. Recomputed hashes are: first-355
`e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, first-357
`b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, first-361
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, whole-365
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

Exact next is **`M3-CP4c-2-TB-X2-R8-EXEC`**, artifact-only. It must consume package `9724864897`; verify immutable
package/source/GMP and selector hashes before runtime; run the current 365 gate one identity per fresh process only
after the turn's explicit gate-selection/authorization step; execute every frozen non-gating CP4c-2 diagnostic or
record a per-identity skip rationale under AF6; publish AF0/AF2/AF3/AF4 and AG3–AG6 evidence; categorize every
observed red before closeout; and perform unconditional postflight. No rebuild, repair, source/test/fixture mutation,
or benchmark outside the frozen TB plan is permitted.

Open CP4c-2 facts entering R8:

- the inherited accepted prefix is **355/355 green** from R7; any red at ordinals 1–355 is an immediate hard stop;
- ordinals 362–365 are new CB7 contracts and have never executed;
- the prescribed sphere's independent pre-cut actual graph remains `V=18,E=30,F=18,c=1,chi=6,sourceChi=2`;
- AF0 instrumentation must reveal its originating producer error without changing the surface-cut error mapping;
- the production torus must use committed `torus.rawfield`; enumeration invariance remains the AD3 falsifier;
- the constructed trace-crossed witness must prove its own runtime precondition and exercise the two-Cut/two-Trace
  degree-four rotation;
- saturation is expected **false** on production witnesses and deliberately **true** only in the positive saturation
  identity; any other production saturation is a finding;
- the independent oracle must report attached trace endpoints, no degree-zero graph nodes, sphere component
  structure, and per-promoted-edge crossing-node/cut-arc counts.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **65**.
`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false` until the R8 turn explicitly
authorizes execution. CP4c-3 remains blocked.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R7 re-proved the inherited accepted **355/355** on CB5 package `9719216316`, closing `PR8-R043` and `PR8-R044`. CP4c-2 remains unaccepted; CB7 implemented Amendment 14 and froze gate 365, then produced immutable GMP package `9724864897`. Exact next is `M3-CP4c-2-TB-X2-R8-EXEC`; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 trace-crossed non-cellular cut completeness:** AF1 proves the prescribed sphere is non-cellular pre-cut, activating DEFN-R1 §8.3. Definition repair/typed-stop contract is required before any product fix.
- [ ] **Prescribed sphere A2a′ collapsed upstream error:** AF0 still must print the originating code before any error-path product fix; do not fix by inference.
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
