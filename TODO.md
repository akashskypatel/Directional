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

## Current focus — independent CP4c-3 phase-1 TB review

`M3-CP4c-3-TB1` is **COMPLETE / VALID SEMANTIC RED / REVIEW REQUIRED**. Retained execution report:
`Architecture_M3_CP4c3_TB1_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative artifact-only run/job `33340448381 / 99335020672` consumed immutable package **68** artifact
`9739919234` directly. Result artifact `9740416876` has SHA-256
`713d4e6853adde54e17738d6d25e5a310a5f88ff8e4232abf67bb73c7a8cbdc0`; diagnostic artifact `9740417020` has
SHA-256 `8302f6ae50a8d5d29f92952aed0f144eb78bda3f070612f3dec67a63701debc0`. Preflight/postflight and package/source
immutability passed; configure/compile/relink/repair/generated discovery/benchmark/mutation flags were all false.

Frozen selector **367** remains byte-identical at SHA-256
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`. TB1 re-proved the accepted prefix
**365/365 PASS**, then hard-stopped at ordinal **366**:
`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`.
Required result: **366 executed / 365 PASS / 1 RED**; ordinal 367 was correctly not executed after the first red.

### Phase-1 measurements now available to review

- **AK1 mechanical discriminator:** `CycleTransportAdjacencyMissing`.
- **AK2 mechanical locus/shape:** region `0`, source edge `0-3`, `fieldTransportAdjacencyExists=false`;
  `V/E/F=152/450/300`, χ=2, boundary loops=0, genus=0, interior local vertices=152, expected cycles=152,
  cycle rows=152, cycle curvatures=152, inner adjacencies=450, local mesh/bundle both available.
- **AK3 prescribed sphere discriminator:** `RotationSystemInconsistent → TraceEventPositionInvalid`. The sphere still
  reaches source topology, atlas and network (24 traces / 56 events) before the `SurfaceCutGraph` failure.
- Frozen non-gating diagnostics executed in full: **0 PASS / 3 RED**, report-only. Torus reaches a valid
  `GlobalTopologyPlan` and then fails downstream at `tracing`; mechanical and sphere reproduce the AK1–AK3 evidence.
- Three earlier workflow controls failed only in preflight and executed no Directional runtime. They are closed as
  orchestration-only; `33340448381` is the sole semantic TB1 authority.

### Exact next turn

Run the **independent CP4c-3 phase-1 TB review / planning turn**. It must:

1. treat the TB1 red as evidence, not as authorization to retry or patch;
2. interpret the measured mechanical `CycleTransportAdjacencyMissing` locus and sphere
   `TraceEventPositionInvalid` reason against the committed authority;
3. update `ORIENTATION.md` as required for every REVIEW turn;
4. order the bounded AK4–AK7 / phase-2 corrections, including whether any measured causes share a locus;
5. keep selector 367 frozen until the already-defined append point and do not weaken the accepted 365 prefix.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **68**.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — TB1 measured `CycleTransportAdjacencyMissing` at source edge `0-3`; independent
  review now owns AK6 corrective design/order.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — prescribed sphere, gated; AK3 now measures
  `TraceEventPositionInvalid`; independent review owns the corrective order.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — per-face-chord proposal-heuristic correction, AK4; phase-2 review ordering pending.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — typed empty-network rejection, AK5; phase-2 review ordering pending.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 selector **367** is frozen; CB1 phase-1 instrumentation is compile-green in package **68** and TB1 is a valid semantic red after re-proving the accepted **365/365** prefix. Ordinal 366 measures `CycleTransportAdjacencyMissing`; AK3 measures the prescribed sphere at `TraceEventPositionInvalid`. Exact next is the independent CP4c-3 phase-1 TB review / planning turn; no phase-2 fix is authorized before it.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 phase-1 TB review:** valid TB1 red at ordinal 366 measured `CycleTransportAdjacencyMissing` on source edge `0-3`; review must derive the corrective invariant before AK6 implementation.
- [ ] **Prescribed sphere A2a′ upstream error:** AK3 now publishes `originatingTopologyError=RotationSystemInconsistent` with `originatingRotationSystemReason=TraceEventPositionInvalid`; review the exact cause before any product fix.
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
