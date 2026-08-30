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

## Current focus — `M3-CP4c-2-CB8` — correct two test identities

`M3-CP4c-2-TB-X2-R8-REV` is complete:
`Architecture_M3_CP4c2_TB_X2_R8_Independent_Review_Record.md`. Measures **AH0–AH9**.

**R8 was the most productive runtime in this checkpoint.** On immutable CB7 package `9724864897` (run/job
`33288495471 / 99195869180`) the inherited accepted prefix survived a large A2a′ rewrite — **355/355 PASS** — and
ordinals 356, 357, 358 passed. **The torus is done:** ordinal 356 publishes `networkV=48`, `networkE=48`,
`cutEdgeCount=28`, `torusRegionCount=4`, and the independent oracle publishes `V/E/F = 72/76/4`; `76 − 48 = 28`
matches the producer's cut-edge count exactly, so producer and oracle agree term for term. Criteria **C1** and
**C6** hold on the produced torus. AF0 printed the sphere's real origin (`RotationSystemInconsistent`), confirming
R7-REV's static derivation; AF2's repaired D2 executes; AG3's two completeness-theorem conditions hold on all three
witnesses.

**The red at ordinal 359 is a witness defect, not a product defect, and its scope is exactly two identities.**
`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` fails before its comparison because
`make_source_authority(mesh)` supplies **none** of the four production feature products — no authoritative rails,
no hard-feature edges, all-zero component and sheet labels — and `rails_from_atlas` then returns an **empty** rail
set on a closed witness. R8's own split proves it: ordinal 358 uses the identical construction on a **bounded**
witness and passes; ordinal 359 is the only one executed on a **closed** witness. Ordinal 361 shares the
construction and is predicted to fail identically. Owned by `M3-CP4c2-TB-X2-R8-CAND-01`.

Cause of the incomplete migration: R7-REV's **AF3** named "the production torus authority" and then narrowed it in
a parenthetical to "the same `torus.rawfield`-derived field". CB7 implemented that exactly and correctly. The
measure was under-specified — `LESSONS.md` **59**.

### CB8 scope — AH0–AH9, deliberately narrow

- **AH1 first, no build required.** Read the ordinal-359 stdout out of retained result artifact `9725240893` and
  publish every `ADD_FAILURE` line verbatim. The lambda's non-fatal failures and its default-constructed
  `SurfaceCutGraphError` sentinel funnel three distinct causes into one fatal `ASSERT_TRUE` at line 2381, so the
  reported locus does not identify the cause.
- **AH2** rebuild ordinals 359 and 361 on one production feature authority — `authoritativeRails`,
  `hard_feature_edge_keys_from_rails(...)`, and the permuted `componentByFace` / `localSheetByFace` — following
  `observe_cp4c_witness` (`:4391-4403`). `SourceEdgeTopologyKey` is vertex-keyed, so rails and hard features are
  invariant under face-row reordering; only the per-face label vectors need permuting.
- **AH3** do **not** re-run the whole pipeline per ordering — that would couple A2a′'s gate to upstream
  enumeration invariance and destroy the red's locality. Considered and rejected.
- **AH4** add a closed-witness runtime precondition (`if boundaryLoops.empty() → ASSERT_FALSE(rails.empty())`) to
  ordinals 358–361 and the AG5 fixture, in the CP3a style.
- **AH5** remove the sentinel. A default-constructed `SurfaceCutGraphError` reads as `InvalidSourceBinding` with no
  originating code, so printing `error().code` at line 2381 without removing it would emit a **fabricated locus**.
- **AH6** when 363–365 first run, publish whether the trace-crossed edges were selected by the ordinary tree–cotree
  path or only under saturation; if only under saturation, a second witness is owed.
- **AH7** if AH1 shows the cut graph itself failed on an empty network, record a new candidate — do **not** widen
  CB8.
- **AH8** CB8 must not absorb the sphere fix, a new gate identity, any selector byte, or a whole-pipeline
  invariance identity.

**Still unexecuted after the hard stop:** ordinals 360 (two-ring digest split as a gate), 361 (closed-witness digest
split — `PR8-R044` is runtime-proved on one witness only), 362 (**criterion C3, deferred a seventh time**), 363–365
(Amendment 14's subdivision, the degree-four rotation, and saturation). **Measure `AD3` is unresolved for a third
turn** — ordinal 359 is its only falsifier.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **65**.
`selected_r2_branch=NONE`; gate **365** is the frozen authority, executed red; `gate_execution_authorized=false`.
CP4c-3 remains blocked.

### CP4c-2 gate authority

**Selector 365** — `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt`, whole-file SHA-256
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. Its `head -355`, `head -357` and `head -361`
reproduce `e9d88f11…5afeaa`, `b896d0db…64dc70` and `61918d9f…0288b` exactly. 357, 358 and 361 are retained as
lineage and are not executable gate authority.

### Open CP4c-2 candidates

- [ ] `M3-CP4c2-TB-X2-R8-CAND-01` — ordinals 359/361 built on a vacuous rail set; AH1–AH5. Closes when both pass in
      a run reaching at least ordinal 361. **Supersedes `R7-CAND-01`.**
- [ ] `M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere. Two independent problems: the producer fails at
      `RotationSystemInconsistent` (source face `25-27-28`, `producerCutEdgeCount=0`) before cut selection, **and**
      its pre-cut graph is non-cellular (`V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`). Neither is in the gate.
- [ ] **Amendment 14 is built but unexecuted** — ordinals 363–365 never ran.
- [ ] **Criterion C3** — ordinal 362, deferred seven times.
- [ ] Measure **AD3** — raw `face.orbit` index in a semantic digest; falsifier is ordinal 359.

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
