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

## Current focus — `M3-CP4c-3-CB11` (Code + Build, DIAGNOSTIC-ONLY)

`M3-CP4c-3-TB8-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB8_Independent_Review_Record.md` (**BA0–BA7** discharged, static only).

TB8's ordinal-366 first red —
`InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2;publishedFaceCount=0` — is classified
**BA2 category 3, diagnostic insufficiency, over a proved two-element candidate set**. Ten of the twelve emission
sites of that typed code are eliminated by proof; the two survivors (`SurfaceCellTracing.cpp:1900` and `:3920`) have
**different owners** and emit the **identical** rendered locus. Every field that would separate them —
`traceSeedVertex`, `traceSeedSingularity`, `traceHistory`, `traceSteps`, `singularity`, `rail`, `relatedSourceFace`,
`relatedBranch`, `parameter`, `exactValues`, … — exists on `FieldAlignedCurveNetworkError` and has **no field at all**
in `SurfaceCellFailureLocusDiagnostics` and **no reader** in `RemeshPipeline.cpp`.

`M3-CP4c3-TB7-CAND-01` is **CLOSED** (vertex 11 cleared on the production path; diagnostic 375 elects one owner in
both radial orientations). `M3-CP4c3-TB7-REV-CAND-01` is **CLOSED**, verdict confirmed but its evidentiary basis
corrected. New `M3-CP4c3-TB8-REV-CAND-01` is **ACTIVE**. Vertex 30 is still not reached, so
`M3-CP4c3-TB6-CAND-01` stays **ACTIVE**.

### Exact next turn

Run **`M3-CP4c-3-CB11`** under §8 **BB0–BB9** of
`Architecture_M3_CP4c3_TB8_Independent_Review_Record.md`. **Diagnostic-only.**

- [ ] **BB0** — selectors **374** and **375** byte-frozen; accepted 365 untouched; **GMP/GMPXX linkage mandatory**.
- [ ] **BB1** — project the trace-scoped fields into `SurfaceCellFailureLocusDiagnostics` / `network_failure_locus`
      and render them in `append_cp4c_failure_locus`, with a **bounded** `traceHistory` and an explicit truncation
      marker. Exact reduced strings only; no float in the locus.
- [ ] **BB2** — add a typed **per-site discriminator field** set distinctly at all twelve emission sites. The
      `InvalidNetworkTerminalOwnership` enum value **must not be split or renamed** — accepted ordinal 328 asserts it.
- [ ] **BB3** — make `publishedFaces` honest: populate it or remove it (currently declared and never assigned).
- [ ] **BB4** — find consumers **by search against a predicate**, name one the measure did not name, and re-aim
      ordinal 329's losslessness guarantee at the production renderer. Closes `M3-CP4c3-TB8-REV-CAND-01`.
- [ ] **BB5** — demonstrate reachability of both surviving sites through the **production** renderer.
- [ ] **BB6** — append **selector 376** only on demonstrated falsification; republish 374/375 with unchanged SHA-256.
- [ ] **BB7** — prohibitions: **diagnose the `terminalContact` fall-through, do not repair it**; no change to any
      tracing/election/ownership/termination decision; no fixture mutation; no sphere/370/saturation/folded-cone
      correction; no acceptance claim.
- [ ] **BB8** — audit by assumption; prove no accepted-green identity's observable output changes.
- [ ] **BB9** — publish the five expected `M3-CP4c-3-TB9` discriminators before the TB runs.

**No product correction is authorized until TB9 names the site.** Successor after CB11 is artifact-only
`M3-CP4c-3-TB9` on selector 376 from ordinal 1, then independent `M3-CP4c-3-TB9-REV`.

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
