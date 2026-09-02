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

## Current focus — `M3-CP4c-3-TB10` (Test + Benchmark, ARTIFACT-ONLY / NOT EXECUTED)

`M3-CP4c-3-CB12` is **COMPLETE / BUILD GREEN / PRODUCT CORRECTION**. Exact product/test/selector source:
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`. Compile run/job `33581576670 / 100096794713` passed all eight
required targets through the mandatory GMP/GMPXX reusable compile workflow. Immutable package **80** is artifact
`9828786744` from package run/job `33582280392 / 100098880900`; inner tar SHA-256
`4e8303489adb46528ae0a92c7ecf9dae65f0cbd57527740d845d318c65af02ce`. `runtimeExecution=false` throughout CB12.

CB12 discharged the frozen BD0–BD9 scope without touching the separate finalize/contact fall-through or any deferred
sphere/370/saturation/folded-cone/vertex-30 correction:

- [x] **BD0** — selectors 374/375/376 remain byte-frozen; accepted 365 untouched; GMP/GMPXX linkage proved.
- [x] **BD1** — `BarrierAbsorbed` termination now owns the arrival with the singularity's network node and publishes
      the existing `FirstContact` + `SingularityTermination` pair; `Emit` remains port-owned.
- [x] **BD2** — policy is carried explicitly in construction state; empty ports are not a policy proxy.
- [x] **BD3** — existing `SingularityTerminationPortOwnershipMismatch` is preserved; missing barrier-absorbed node has
      distinct fail-closed `SingularityTerminationBarrierAbsorbedNodeMissing`.
- [x] **BD4/BD5** — compiled regression witness derives mechanical terminal **v36**, `BarrierAbsorbed` policy, network
      node and mandatory-barrier incidence; it covers missing-node rejection and positive node-owned termination.
- [x] **BD6** — selector **377** appended exactly one identity, SHA-256
      `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`; 376 is its unchanged prefix.
- [x] **BD7/BD8** — frozen prohibitions and accepted-output audit preserved. Runtime equivalence is not claimed by CB.
- [x] **BD9** — five TB10 discriminators are frozen in
      `Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Plan.md`; **no vertex-30 discriminator**.

`M3-CP4c3-TB9-REV-CAND-01` remains **ACTIVE** until TB10 proves the accepted prefix, the old condition+seed no longer
repeats, and the mechanical v36 network-node witness passes. Accepted authority remains **365/365**; CP4c-3 remains
**OPEN**. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**;
authoritative semantic M3 package count **77**.

### Exact next turn

Run **`M3-CP4c-3-TB10`**, artifact-only on immutable package **80**, selector **377 from ordinal 1**, exactly under
`Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Plan.md`. No rebuild, relink, source/test/fixture/selector
mutation, package repair, or benchmark. CB12 closeout does not begin TB10.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB9 is current runtime authority at accepted prefix 365 / first red 366. CB12 is build-green on package 80 / selector 377. Exact next is artifact-only `M3-CP4c-3-TB10`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — singularity-terminal ownership:** CB12 compiled the BD0–BD9 correction on source `a3b6f1a41feaa8a115faf11de52f85ce4cc42a15` and froze immutable package 80 / selector 377. Runtime closure is deliberately pending TB10: ordinal 366 must not repeat `SingularityTerminationPortOwnershipMismatch` at seed 47 / singularity 5, and identity 377 must prove `BarrierAbsorbed` termination at v36's network node. The separate finalize/contact fall-through remains open and untouched; vertex 30 remains unreached.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **76** after CB11/package 79; TB9 created no package. PR #8 remains open, draft, and unmerged.
