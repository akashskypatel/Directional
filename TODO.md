# Directional Surface-Cell TODO

Last updated: 2026-09-06 UTC

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

## Current focus — `M3-CP4c-3-TB30-EXEC` (Test + Benchmark) — ARTIFACT-ONLY RUNTIME

`M3-CP4c-3-CB35` is **COMPLETE / COMPILE GREEN / RUNTIME-FREE**. Current semantic runtime authority remains
`M3-CP4c-3-TB29` until TB30 is validly reviewed.

- built evidence source **`ab86747bdfdb94c7c383bf5d2893ced4207eb555`**;
- immutable CB35 package **`9980764888`**, `m3-cp4c3-cb35-result-34005311571`, provider ZIP SHA-256
  `ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`;
- selector **408**, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`,
  unchanged by CB35;
- current semantic runtime authority TB29: **399 PASS / 9 RED**, accepted **1–365 = 365/365**, RED
  `366,367,368,369,370,374,390,398,404`.

**CB35 changed test authority only.** Ordinal **404** no longer asserts that ownership must remain non-established;
ordinal **390** no longer equates the plan and certifier partitions by component index. No product source, fixture,
benchmark, build logic, selector byte, accepted identity 1–365, ordinal 398, 366, or 367 changed.

CO7 transcribed the existing TB29 post-correction evidence without new runtime: the failing plan component is
`0 / EmptyFragmentOrbits / 191 faces / digest 17919102493633069558 / seeds [0,1,3]`; the comparison census is
`0 / NotTraceCut / 212 faces / digest 835099723348023536`, with neither exact match nor subset relation; only
equal-orbit arcs 20 and 24 remain interior; certified owner publication is **300 established / 0 unavailable /
0 conflicting**. Exact RED assertion text is retained in `Architecture_M3_CP4c3_CB35_Code_Build_Report.md`.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3
package count **95**. CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-TB30-EXEC`** exactly from
`Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md` on immutable package `9980764888`:

- [ ] verify package/source/checksums/executable modes and frozen selector 408 before runtime;
- [ ] execute all **408** identities in frozen order, one identity per fresh process and fresh working directory;
- [ ] require `selected == 1` for every row and preserve the complete raw ledger, per-identity logs/resource evidence,
      and pre/post byte+mode censuses;
- [ ] accepted 1–365 must remain **365/365 PASS**;
- [ ] corrected witnesses **390 PASS** and **404 PASS** are required;
- [ ] credibility controls **366 RED, 367 RED, 398 RED** are required because CB35 changed no product behavior;
- [ ] record 368/369/370/374 exactly, with no repair or mutation.

If only the two authorized witness corrections change, the consistent aggregate is **401 PASS / 7 RED** with RED
`366,367,368,369,370,374,398`.

**No configure, compile, relink, rebuild, repackaging, package repair/chmod, generated discovery, benchmark,
source/test/fixture/selector mutation, or semantic retry.** TB30-EXEC records raw evidence only and stops at
**`M3-CP4c-3-TB30-REV`**. No second product correction is authorized before that review reads the census.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted.
  CP4c-3 remains open. CB35 is compile-green on immutable package `9980764888` / source
  `ab86747bdfdb94c7c383bf5d2893ced4207eb555`; no CB35 runtime has executed. `M3-CP4c-3-TB29` remains the latest
  valid semantic runtime at 399 PASS / 9 RED, accepted 365/365. Exact next: **`M3-CP4c-3-TB30-EXEC`**,
  artifact-only, followed by evidence-only `TB30-REV`.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face ownership derivation:** CB34's frozen separating-arc barrier correction is runtime-proved
  by TB29. CB35 then restored ordinals 390/404 to their own test contracts and compiled immutable package
  `9980764888` without product change. TB30-EXEC must re-run selector 408; 390/404 are required PASS while
  366/367/398 remain credibility RED controls. No second product correction is authorized before TB30-REV.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

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

Current totals are **44 events / 14 categories / 30 recurrences**, classified at `M3-CP4c-3-TB29-REV` with no stable change. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **95**. **`M3-CP4c-3-TB29` remains the current valid semantic runtime authority at 399 PASS / 9 RED, accepted 365/365 on selector 408; CB35 is compile-green and runtime-free.** Exact next is `M3-CP4c-3-TB30-EXEC`, artifact-only, followed by evidence-only `TB30-REV`. PR #8 remains open, draft, and unmerged.
