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

## Current focus — `M3-CP4c-2-TB-X2-R8-REV` — review ordinal-359 gating-witness red

R8 is **SEMANTIC RED** on immutable package `9724864897`: inherited ordinals 1-355 are **355/355 PASS**,
356-358 PASS, and ordinal **359** `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` fails before its
invariance comparison because the baseline direct cut-graph witness is not constructible. The hard stop left
360-365 unexecuted. Exact evidence: `Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md`.

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

R8 authoritative run/job `33288495471 / 99195869180` produced result/log artifacts `9725240893 / 9725241013`;
postflight is green and no build, repair, mutation, or benchmark occurred. Ordinal 359 still uses test-local
`rails_from_atlas(...)`, while the passing production torus path consumes pipeline `authoritativeRails`; this is
`M3-CP4c2-TB-X2-R8-CAND-01`, a non-stable continuation of R7-CAND-01. AF0 now prints the sphere origin as
`RotationSystemInconsistent`; AF2 and AG3 diagnostics execute successfully.

Selector **365** is now frozen. Recomputed hashes are: first-355
`e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, first-357
`b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, first-361
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, whole-365
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

Exact next is **`M3-CP4c-2-TB-X2-R8-REV`**, independent Review + Plan only. It must adjudicate the ordinal-359
witness/authority mismatch, determine the bounded correction for the still-unexercised 360-365 tail, preserve the
355 accepted prefix and immutable R8 evidence, and separately review the sphere's now-visible
`RotationSystemInconsistent` origin. No retry, corrective CB, build, or new Directional runtime is authorized first.

R8 review inputs (including frozen entering-R8 predictions):

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
`selected_r2_branch=NONE`; selector 365 was selected/executed red in R8; `gate_execution_authorized=false` at
closeout. CP4c-3 remains blocked.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R8 re-proved the inherited **355/355** and passed 356-358, then stopped red at new gate ordinal 359 before its invariance comparison. CP4c-2 remains unaccepted. Exact next is `M3-CP4c-2-TB-X2-R8-REV`; CP4c-3 remains blocked.
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
