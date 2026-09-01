# Directional Surface-Cell TODO

Last updated: 2026-09-01 UTC

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

## Current focus — `M3-CP4c-3-TB8-REV` (independent REVIEW + PLAN only)

`M3-CP4c-3-TB8` is **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366**. Report:
`Architecture_M3_CP4c3_TB8_Artifact_Only_Test_Benchmark_Report.md`.

TB8 consumed immutable package **78** from semantic source
`e2b59295c9920db5685239c2da188858839fa94f` in run/job `33561723204 / 100035596811`. Result artifact
`9821602279` has Actions SHA-256 `e9858ac5194646f888a193937e52cc504aa36a6940d79904b36f70c059026a62`;
log artifact `9821602943` has SHA-256 `1f41626b53642bb30a00bcaafbbc3993d09870c20c2ffc15f2224670ecc65239`.
Immutable preflight/postflight passed and every build/repair/mutation/benchmark flag remained false.

Ordinals **1–365 PASS**. Ordinal **366** moved past TB7's source-vertex-11 seed failure and now first-reds at
`InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2;publishedFaceCount=0`. The mechanical
path does not reach vertex 30, so its row-209/row-208 owner election remains runtime-unvalidated. Report-only 367–374
completed as **1 PASS / 7 RED**; 367/371/372 share the new terminal-ownership block, 368/369/370 preserve their
existing independent debts, 373 passes synthetically, and 374 repeats the already-reviewed invalid-witness
`atlasBuild` stop without creating a new review trigger.

Diagnostic identity **375**
`ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries` PASSed separately with zero gate
credit. Together with green identities 328/329, this runtime-closes the TB7 radial-arrival admissibility defect and the
TB7-REV audit/rendering reachability defect. It does not close the general non-flat exact-fallback/budget class.

### Exact next turn

Run **`M3-CP4c-3-TB8-REV`** under
`Architecture_M3_CP4c3_TB8_Independent_Review_Plan.md`.

- [ ] REVIEW + PLAN only: no Directional runtime, compile, package, benchmark, or product/test/fixture/selector
      mutation.
- [ ] Re-establish immutable TB8 authority and reconstruct the exact terminal-ownership failure at edge `36-38`,
      face `(36,38,39)`, branch 2.
- [ ] Classify the new first red as product defect, invalid witness/precondition, or diagnostic insufficiency before
      prescribing a correction.
- [ ] Keep vertex-30 owner acceptance open; TB8 did not reach it.
- [ ] Preserve the independent sphere, saturation, ordinal-370, ordinal-374 and mechanical zero-unbound debts unless
      shared ownership is proved.
- [ ] Reconcile candidate/accounting status and freeze exactly one bounded successor for the earliest gating owner.
- [ ] Update `ORIENTATION.md` during the review as required by durable policy.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **75**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB8 re-proved the 365-prefix, cleared the CB10 vertex-11 defect, and first-reds at new terminal-ownership locus `36-38 / (36,38,39) / branch 2`. Exact next is independent `M3-CP4c-3-TB8-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — current gate owner under review:** TB8 clears the proved vertex-11 seed-admissibility defect but first-reds at `InvalidNetworkTerminalOwnership`, source edge `36-38`, source face `(36,38,39)`, branch 2, `publishedFaceCount=0`. `TB8-REV` must establish cause/owner before any correction. Vertex 30 remains unreached and its row-209/row-208 owner acceptance remains open. No candidate-order, tolerance, float-transport, `signedLift`-as-ray, or target-representative shortcut.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **75** after CB10/package 78; TB8 created no package. PR #8 remains open, draft, and unmerged.
