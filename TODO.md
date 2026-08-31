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

## Current focus — `M3-CP4c-3-TB4` (Artifact-Only Test + Benchmark)

`M3-CP4c-3-CB5` is **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE**. Evidence:
`Architecture_M3_CP4c3_CB5_Code_Build_Report.md`.

### Immutable CB5 authority

- semantic/evidence source `2d22ef293363058cfdca96d01158a93d2c0200f8`;
- immutable package **73** artifact `9773591345`, inner tar `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`;
- full eight-target compile `33433309655 / 99623694545`; package-only envelope `33433718709 / 99625035344`;
- selector 373 unchanged at `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`;
- **27** package-relative fixtures and six `0755` test/benchmark executables verified;
- GMP/GMPXX linkage, manifests and clean source/package checks pass;
- `runtimeExecution=false`; no Directional runtime executed.

### What CB5 established

- **AP1 implemented:** all four typed stage-error boundaries retain a shared `SurfaceCellFailureLocusDiagnostics`
  payload instead of dropping their locus.
- **AP2 implemented but unmeasured:** ordinal 366 can publish source vertex, face, branch, arrival mode, candidate
  cardinality/faces, `BarrierAbsorbed`, barrier incidence/degree and transport-star component count.
  **M1/M2/M3 remain unadjudicated** until runtime.
- **AP3/AP4 held:** no transit/product correction and no design against M3.
- **AP6 adopted for TB4:** after the normal first red, run frozen ordinals **367–373** once as a **non-gating**
  diagnostic pass, report-only and zero gate credit. Selector bytes and gate semantics are unchanged.
- **AP8:** independent typed-data-loss sites were found at `surfaceCutGraphBuild.error()` and
  `globalTopologyBuild.error()`, proving the audit was predicate-driven.

### Exact next turn

Run **`M3-CP4c-3-TB4`** artifact-only on package **73**:

1. verify immutable package/source/GMP/27-fixture/six-mode/selector authority;
2. execute selector 373 from ordinal 1, one exact identity per fresh process, first-red hard stop;
3. after recording the gate verdict, execute frozen ordinals **367–373** once as AP6's non-gating diagnostic pass
   with **zero gate credit**;
4. if ordinal 366 is red, capture AP2's full typed locus and classify M1/M2/M3 from measured evidence;
5. semantic red → `REVIEW + PLAN`; no rebuild, relink, package repair, generated discovery, or corrective
   implementation is allowed in TB4.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — **ACTIVE / CAUSE NOT ESTABLISHED / GATING**; TB4 owns the AP2 discriminator.
- [x] `M3-CP4c3-TB3-R1-REV-CAND-01` — shared typed-error funnel repaired in CB5; runtime publication remains TB evidence.
- [ ] **C2 / mechanical witness** — A1 is proved clear; current accepted-path red remains A2a pending TB4.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — ordinal 373 still runtime-unproved.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere ACTIVE / ONE LEVEL SHORT; ordinal 368 runtime-unproved. **AL4** still forbids designing its fix.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — ordinal 369 runtime-unproved.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — ordinal 370 runtime-unproved.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, semantic packages **71**.

## Superseded — `M3-CP4c-3-TB2` execution record

`M3-CP4c-3-TB2` is **COMPLETE / RED — VALID SEMANTIC FIRST-RED AT ORDINAL 366** after the user-authorized orchestration/fixture remediation. Fixture-only package **70** (artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`) preserves semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71`, the frozen selector **373**, and byte-identical package-69 binaries while adding the immutable sibling `test-data` fixture payload. R4 run `33355714664` passed package/source/GMP/selector/mapping/fixture preflight, then executed ordinals **1–365** as exactly-selected green fresh processes.

Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected exactly once and exited 1 with `InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`. This is a valid semantic first-red. Ordinals **367–373** were not executed under first-red semantics. `M3-CP4c3-TB2-ORCH-01` is **RESOLVED / NON-STABLE** by package 70 and the R4 preflight; it adds **+0 stable events / +0 recurrences**. Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative semantic packages **69**.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — the cycle-basis half is **fixed and proved**; what remains is the same
  assumption at the singularity-port consumer. Frame settled by Amendment 16; policy blocked on **AN1**, implemented
  under **AN5**.
- [ ] `M3-CP4c3-TB2-CAND-01` — **CAUSE ESTABLISHED**; pre-existing and unmasked, not a regression. Closes on ordinal
  366 green in a run reaching at least 366.
- [ ] `M3-CP4c3-TB2-REV-CAND-01` — package-70 binary identity is self-reported and unverified against package 69's
  per-binary digests; owned by **AN2**.
- [ ] `M3-CP4c3-TB2-ORCH-01` — **reopened and reclassified** as a build/packaging contract defect: the packaged
  artifact cannot locate its own fixtures. Owned by **AN3**.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — correction remains compile-green/gating; ordinal 373 is still unexecuted because first-red stopped at 366.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere remains **ACTIVE / ONE LEVEL SHORT**; ordinal 368 remains unexecuted in R4.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — ordinal 369 remains unexecuted; product correction still unaccepted.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — ordinal 370 remains unexecuted; typed-error behavior still unaccepted.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 CB5 diagnostic instrumentation is compile/package-green on semantic source `2d22ef293363058cfdca96d01158a93d2c0200f8`, immutable package **73**. No semantic runtime has consumed it. Exact next is artifact-only `M3-CP4c-3-TB4` under unchanged selector 373 plus AP6's post-first-red non-gating diagnostic pass.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** Amendments 15 and 16/P2 are both implemented and **proved effective at runtime** — the mechanical witness clears **all of A1** and ordinals 1–365 stay green through both changes. It now first-reds in **A2a** at `VertexTransitSectorUnresolved`. Cause not established; three mechanisms enumerated and discriminated by **AP2**, with **AP4** forbidding design against the leading suspicion.
- [ ] **Prescribed sphere A2a′ upstream error:** resolved to `RotationSystemInconsistent → TraceEventPositionInvalid`. AM7 instrumentation is compile-green, but ordinal 368 has never been reached — first-red has stopped at 366 in three consecutive TB runs. **AP6** proposes a non-gating diagnostic pass so 367–373 stop being invisible. No sphere product disposition may be inferred.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **71** after CB5; package labels 70 and 72 were transport/envelope corrections rather than new semantic sources. PR #8 remains open, draft, and unmerged.
