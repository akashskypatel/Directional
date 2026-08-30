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

## Current focus — artifact-only CP4c-3 phase-1 TB on package 68

`M3-CP4c-3-CB1` is **COMPLETE / BUILD GREEN / RUNTIME-FREE / PHASE-1 INSTRUMENTATION ONLY**.
Its retained report is `Architecture_M3_CP4c3_CB1_Code_Build_Report.md`. Corrected semantic source
`48dd011c4aa689a245b74527ed9df0900ada9bf3` compiled under GMP/GMPXX in run/job
`33338642383 / 99330058374`, producing immutable package **68**, artifact `9739919234`, SHA-256
`127c7b086a8849de7f0c14928f2c5d762c3bf71711821d0a1fabfefda889d11c`; packaged-source archive SHA-256
`f1fce7f720718c8ac974d0d5f77ca1fee4244b10c710d2b505a1af162e4f937f`. Internal manifest **28/28 PASS**;
`runtimeExecution=false`. The first compile attempt exposed only a default-construction error in the new diagnostics row;
the isolated correction aggregate-initializes it with `region.id()` and changes no intended product behavior.

CP4c-3 selector **367** remains frozen and unselected at SHA-256
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; the accepted 355/357/361/365
prefix hashes remain unchanged. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

### CB1 instrumentation now available to runtime

- **AK1:** all eight `IncompleteCycleBasis` producer sites carry an enumerated `IncompleteCycleBasisReason`, and all
  existing error-code diagnostic consumers publish it. No error mapping/value changed.
- **AK2:** every region on an `IncompleteCycleBasis` failure publishes local `V/E/F`, Euler characteristic, boundary
  loops, genus, interior-local-vertex count, expected cycle count, actual cycle rows/curvatures/inner adjacencies,
  plus local-mesh/bundle availability.
- **AK3:** all nine instrumented `RotationSystemInconsistent` source sites carry an enumerated
  `RotationSystemInconsistencyReason`, transported through `SurfaceCutGraphError` and the existing sphere diagnostic.
- **AK8:** the retained CB1 report records the search-produced site/consumer enumerations.

### Exact next turn

Run the **artifact-only CP4c-3 phase-1 Test + Benchmark execution** directly from package 68 (`9739919234`):

1. immutable preflight; no rebuild/repair/source/test/fixture/selector/package mutation;
2. execute frozen selector **367 from ordinal 1**;
3. run the frozen non-gating selector in full, or justify each skipped identity under AF6;
4. publish the mechanical-witness AK1 discriminator plus all AK2 region rows and the prescribed-sphere AK3 reason;
5. preserve first-red and stop semantics; do not design a phase-2 fix inside execution;
6. hand the evidence to the independent TB review, which alone orders phase 2.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **68**.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — measured cause pending artifact-only AK1/AK2 runtime evidence, then AK6.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — prescribed sphere, now gated; measured nine-way producer cause pending AK3, then AK6.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — per-face-chord proposal-heuristic correction, AK4; not authorized before phase-1 review.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — typed empty-network rejection, AK5; not authorized before phase-1 review.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted; R10 closed CP4c-2 at **365/365** on immutable package `9736088354`, with criteria C1/C3/C6 green. CP4c-3 is **unblocked** and inherits three items — the prescribed sphere, Amendment 14's unexercised ordinary proposal path, and the zero-node/zero-arc question. `M3-CP4c-3-DEFN` froze CP4c-3's gate at **367**, put the sphere **in** the gate, and decided `R8-CAND-02`. Exact next is `M3-CP4c-3-CB1` under AK0-AK3, instrumentation only.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 R10 review:** EXEC is valid **365/365 GREEN**; review must interpret AI2 fragment/orbit evidence and AH6 saturation-only coverage, disposition candidates, and decide CP4c-2 acceptance eligibility without altering the executed package.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **67**. PR #8 remains open, draft, and unmerged.
