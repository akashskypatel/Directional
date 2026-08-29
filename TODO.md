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

## Current focus — `M3-CP4c-2-CB7` — implement Amendment 14

`M3-CP4c-2-CB6` stopped correctly at its first measure, **AF1**, before any implementation or compile. The retained
`prescribed-sphere` `m3Cp4c2ActualGraphOracle` row from result artifact `9721564203` reports
`V=18, E=30, F=18, c=1, chi=6, sourceChi=2` with zero excluded boundary orbits. The standing prediction that the
sphere is already cellular pre-cut is therefore **REFUTED**.

That finding activates the explicit `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` §8.3 trigger: the sphere
is trace-bearing and now proved non-cellular, so §8.2's unproved trace-crossed non-disc cut-selection case is live
and **CP4c-2 must return to definition**. CB6 made no product/test/fixture/selector/build change and ran no compile
or runtime. Full closeout: `Architecture_M3_CP4c2_CB6_Code_Build_Report.md`. That stop is now **discharged**.

Exact next: **`M3-CP4c-2-CB7`**, Code + Build. `M3-CP4c-2-DEFN-R2` discharged the stop:

**Amendment 14** — a source edge crossed by a trace at an interior point **is** an admissible cut. DEFN-R1 excluded
it because promoting one would "subdivide an immutable trace", but `build_arcs` already emits one trace arc per
network event, already splits a mandatory source edge at a trace terminal, and the crossing point is already
published exactly as `segments[i].entryPoint`. Arcs are a derived representation; nothing upstream is mutated.

**Completeness is proved outright** — `network ∪ (source 1-skeleton)` is a cellular embedding, so a sufficient cut
set always exists within `|E_source|` promotions. That is exactly the sphere's case. DEFN-R1 §8.2 closes, §10
Option B loses its trigger, and `NoAdmissibleCutForNonDiscComponent` is retired in favour of a search-exhaustion
code plus a published saturation last resort. **AF5** is resolved and **selector 361** is frozen as the gate.

Full authority: `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md`; `DESIGN.md` §7.2.1 carries the amendment
record for 12, 13 and 14.

**AF5 and AF7 are discharged** by DEFN-R2 §7. CB7 carries the measures CB6 deferred — **AF0** (print the
originating `GlobalTopologyPlanErrorCode`, additive only; still the prerequisite for any sphere product fix),
**AF2** (D2 harness repair), **AF3**/**AF4** (production-authority torus witness and the AD3 falsifier) — plus
**AG1–AG6**:

- **AG1** land DEFN-R2 §§4.1–4.5 as one conversion — edge-interior synthetic nodes keyed `(SourceEdgeTopologyKey,
  TraceId, segment position)`, exact ordering along the promoted edge, trace-arc subdivision at crossings, the
  rotation extension, and removal of the proposal filter that excludes trace-crossed edges.
- **AG2** generalize the existing four-sector edge-locus rotation to admit `Cut` rays at degree four
  (`EmbeddedGraphTopology.cpp:833-935`, `mandatory_ray_points_to_second_endpoint` at `:651`). **The one genuine
  code gap:** a `Cut` arc at an edge-locus node is an unhandled shape today.
- **AG3** publish the completeness theorem's two conditions and the edge-orientation convention, with derivations.
- **AG4** retire `NoAdmissibleCutForNonDiscComponent`'s meaning, add `CutSearchExhaustedBeforeCellularity`, and
  make saturation a published last resort that never fires silently. (Verified: no test consumes the old code.)
- **AG5** construct a witness that actually promotes a trace-crossed edge, asserting its precondition at runtime.
  The sphere may become one once AF0/AG1 land, but it is blocked behind a producer fix, so a constructed witness is
  still required.
- **AG6** extend the independent oracle to reconstruct crossing nodes by its own construction.

**AG7** appends the four new identities named in DEFN-R2 §7.4 to selector 361, producing gate **365**, and records
its hash. **AF6** and **AF8** bind the TB after CB7.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **64**.
`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

### CP4c-2 gate authority

**Selector 361** — `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_361.txt`, whole-file SHA-256
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`. `head -355` and `head -357` reproduce the
accepted-355 and candidate-357 hashes exactly. 357 is superseded and 358 withdrawn; both files are **retained**.

### Open CP4c-2 candidates

- [x] **DEFN-R1 §8.2 completeness gap** — **closed at DEFN-R2**: Amendment 14 makes trace-crossed edges admissible
      and `network ∪ source 1-skeleton` is cellular, so a sufficient cut set always exists.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — live producer failure remains re-localized to the shared embedded-graph authority;
      AF0 has not yet printed its originating typed code and no product fix is authorized. Distinct from, and
      additional to, the sphere's measured pre-cut non-cellularity.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-01` — torus digest diagnostic builds a synthetic witness with no production
      counterpart; AF3/AF4.
- [ ] `M3-CP4c2-TB-X2-R7-CAND-03` — D2 harness compares the actual embedded graph against the withdrawn proxy
      using stale line-number labels; AF2.
- [x] `M3-CP4c2-TB-X2-R7-CAND-04` — **resolved at DEFN-R2**: gate membership decided per identity, selector 361
      frozen, 357 superseded, 358 withdrawn, criterion C3 split.
- [ ] **Amendment 14 is defined and entirely unbuilt** — AG1–AG6, owned by CB7. The degree-four edge-locus
      rotation is the one code gap; AG5's constructed witness is the one thing standing between the amendment and
      shipping unexecuted.
- [ ] **Criterion C3** — `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` to be created
      and gated; mechanical half moves to CP4c-3. AG7.
- [ ] Measure **AD3** — `face.orbit` raw index consumed by `candidate_semantic_hash` under an unproved rationale;
      its only falsifier has never run. AF4.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; R7 re-proved the inherited accepted **355/355** on CB5 package `9719216316`, closing `PR8-R043` and `PR8-R044`. CP4c-2 remains unaccepted; CB6 AF1 refuted pre-cut sphere cellularity, and DEFN-R2's Amendment 14 discharged the resulting definition stop by proving cut-set completeness and freezing gate 361. Exact next is `M3-CP4c-2-CB7`; CP4c-3 remains blocked.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **64**. PR #8 remains open, draft, and unmerged.
