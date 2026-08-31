# Directional Surface-Cell TODO

Last updated: 2026-08-31 UTC

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

## Current focus — `M3-CP4c-3-TB2` (Artifact-Only Test + Benchmark)

`M3-CP4c-3-CB2` is **COMPLETE / BUILD GREEN / RUNTIME-FREE** under Amendment 15 and AM0–AM9. Authoritative semantic/evidence source is `005512f20ed56edc793f4d6505f3d2b4c2999c71`; compile run/job `33347935915 / 99355596358` produced immutable GMP package **69**, result artifact `9742715856` (`2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`), log artifact `9742715997` (`f0f94864be943658bc4d461bdafc312b1d40333e7eca9d2dd4ae88cacdfb218b`), and packaged source archive `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`. Internal manifest **28/28 PASS**, all eight standard targets compile/link, source status is clean, `runtimeExecution=false`, and both GMPXX/GMP are on the authoritative link command. The earlier compile attempt failed only on default construction of the new diagnostics object and executed no runtime; the minimal explicit-constructor correction is included in the evidence source.

Selector lineage is now frozen through **373**: 370 `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525`, 373 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`, with 355/357/361/365/367 hashes unchanged, cardinality=unique-cardinality, and every predecessor a byte-exact prefix. **No gate identity executed in CB2.**

### What CB2 implemented

- **AM1–AM6 / Amendment 15 option A′:** A1 derives the local transport mesh cut along `B(R)`, publishes the barrier decomposition, checks the Euler cut identity under new typed failure, fails closed on unbound prescribed singularities, and publishes the index/witness-kind correction. Region-product topology is unchanged.
- **AM7:** the sphere now reports `NoCarrierMatch` versus `AmbiguousCarrierMatch` plus precise/widened-pass provenance; AL4 still forbids a sphere fix until runtime reports it.
- **AM8:** ordinals 368–370 append the inherited sphere/R10/R8 identities; 371–373 append Amendment 15's barrier exclusion, cut identity, and singularity-binding identities.
- **AL8 control:** orchestration digest authoring validates exact 64-lowercase-hex values before publication.

CB2 does **not** claim the inherited `R10-CAND-01` proposal heuristic or `R8-CAND-02` empty-network product behavior is corrected. Their identities are now gated at 369/370 and compiled, not executed; runtime owns their disposition. Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **69**.

### Exact next turn

Run **`M3-CP4c-3-TB2` artifact-only** under `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Plan.md`. Consume only artifact `9742715856` / semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71`; no rebuild, repair, relink, generated discovery, package mutation, or benchmark. Preflight package/GMP/source/selector authority, then execute frozen selector **373** from ordinal 1, one identity per fresh process with first-red hard stop. Green **373/373** closes CP4c-3; any valid semantic red routes to `REVIEW + PLAN`.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — Amendment 15 option A′ is compile-green; ordinals 366/371/372/373 provide the runtime proof.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — AM4 correction is compile-green; ordinal 373 must prove zero unbound prescribed singularities before closure.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere remains **ACTIVE / ONE LEVEL SHORT**; ordinal 368 carries AM7 provenance, no fix authorized yet.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — gated at ordinal 369; product correction is not claimed by CB2 and remains runtime/open.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — gated at ordinal 370; typed-error product behavior remains runtime/open.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 CB2 is **BUILD GREEN / RUNTIME-FREE** in GMP package **69** with selector **373** frozen. Amendment 15 option A′ is implemented; inherited sphere/R10/R8 semantics remain runtime-pending. Exact next is artifact-only `M3-CP4c-3-TB2` on package 69.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** Amendment 15 option A′ is implemented and compile-green; TB2 must prove that cutting A1's derived local mesh along `B(R)` removes non-separating barriers from the local cycle basis and satisfies the cut identity without weakening singularity/index controls.
- [ ] **Prescribed sphere A2a′ upstream error:** resolved to `RotationSystemInconsistent → TraceEventPositionInvalid`. AM7 instrumentation that distinguishes `NoCarrierMatch` from `AmbiguousCarrierMatch` and precise/widened pass is compile-green; TB2 must report it before any product fix.
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
