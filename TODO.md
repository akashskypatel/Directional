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

## Current focus — `M3-CP4c-3-TB16` (Artifact-only Test + Benchmark)

`M3-CP4c-3-CB18` is **COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE** at semantic source
`a01016ca59314232526c8b1222c96235856ace6d`. It replaces the edge-locus fallback's trace-global
`trace.sourceVertex` lookup with the current segment's exact far-end vertex support in the selected face — entry
support for Reverse, exit support for Forward — and makes the fallback corner rank contact-relative:
`1 + 2·((corner + 2 − contactIndex) mod 3)`. The two-carrier branch and all excluded topology/collision paths remain
unchanged; a genuinely unbindable far end still fails typed as `SourceVertexFallbackUnbound`.

BP5/BP6 compile-time witnesses cover the previously succeeding first-segment singularity case, contact indices
`{0,1,2}`, Reverse vertex-entry recovery, unbindable negative behavior, carrier/fallback ordering, and the ordinary
two-carrier regression. Selector **381 remains byte-frozen** at
`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`; selector **382** appends exactly
`GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`, SHA-256
`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`.

Authoritative eight-target GMP/GMPXX compile `33706268720 / 100495948544` is GREEN. Result/log artifacts are
`9875350611` (`cc2935716ecf7022fda6c120f0ef6313e60df553d34d7354b587e47ee9663d3a`) / `9875350974`
(`ea39d44a9196e47934cb3ff626633c3031a2c607c542ef5e34298cc6665328f5`). Immutable package **86** is GREEN on
`33707299159 / 100499114323`: artifact `9875664940`
(`8c98b134a527db87b83852de175288a320a158405d22867d95ba986cf68cbef8`), log `9875665222`
(`fe86b4f391d731eb629461e1d79cb3b9543f1bab968fa922c1f8a0deb9565d28`), inner tar
`125d2851164d7af62f90a3ff6ad8f360076a651c8575b655acac59fb50b9e9e7`, packaged source archive
`c96446f169959c56f3c536c7fe711df6f7741d679cbd1413cc7c464838a659e8`. Package verification is **57/57**,
27 fixtures, six executable test/benchmark binaries with preserved executable modes, `runtimeExecution=false`,
`packageRepair=false`. The first package attempts were orchestration-only failures; the successful caller restored the
mode-preserving direct artifact-ZIP extraction already proven by package 85. No Directional binary ran.

### Exact next turn

Run **`M3-CP4c-3-TB16`** artifact-only on immutable package **86** / selector **382**. Do not rebuild, relink, repair,
patch, regenerate, mutate package contents, or change selectors/fixtures. Extract with archived executable modes
preserved and run each selector identity in a fresh process. Execute the retained mechanical diagnostic report-only
with zero gate credit.

The six frozen BP9 discriminators are:

- [ ] **TB16-1** — ordinals **1–365 remain 365/365 PASS**; this is the load-bearing accepted-boundary safety proof.
- [ ] **TB16-2** — ordinal **366** no longer reports `EdgeTraceSecondaryRankInvalid` at edge `25-31`.
- [ ] **TB16-3** — any remaining rotation red has a different typed branch, locus, or incidence.
- [ ] **TB16-4** — re-prove the **v47 five-ray conjunction**: selector 380 passes with the full five-ray rotation and
      distinct former-pair secondary ranks.
- [ ] **TB16-5** — close `M3-CP4c3-TB11-CAND-01`, `M3-CP4c3-TB12-REV-CAND-01`, and
      `M3-CP4c3-TB15-CAND-01` only if TB16-1, TB16-2, and TB16-4 all hold.
- [ ] **TB16-6** — certification may now reach the face walk; report non-disc/admissible counters only if actually
      observed. **No vertex-30 discriminator is authorized.**

A semantic red routes to REVIEW + PLAN; an orchestration failure is repaired as orchestration only. CP4c-3 remains
**OPEN** until TB16 is green. Accepted authority remains **365/365** from TB15; stable accounting remains **44 events /
14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count advances to
**83**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB15/package85 is current runtime authority at accepted 365/365 / first red 366 `EdgeTraceSecondaryRankInvalid -> SourceVertexFallbackUnbound` at edge 25-31 / face `(25,30,31)`. CB18/package86 is current runtime-free build/package authority at selector 382. Exact next is artifact-only `M3-CP4c-3-TB16`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — edge-locus source-vertex fallback frontier:** TB15 re-proves accepted 365/365 and keeps first red 366 at edge `25-31` / face `(25,30,31)` / attempt 0 / zero cut edges, typed `SourceVertexFallbackUnbound`. TB15-REV adjudicated the incidence as valid and the fallback datum/rank namespace as wrong. CB18 has implemented and compile-packaged the bounded correction under BP0-BP9; **TB16 now owns the runtime discrimination**. The load-bearing checks are accepted 1-365 staying 365/365, ordinal 366 clearing the edge-25-31 edge-rank stop, and the v47 full five-ray/distinct-rank production proof. Selector 381 PASS and compile-only selector 382 are insufficient without TB16 runtime. Vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (deferred, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor, which throws unless all five downstream products are retained. Amendment 15's barrier-cycle and Euler-cut contracts have been unmeasured from TB2 through TB10 for a reason unrelated to either. Corrective is test-only (an atlas-scoped fixture accessor, assertions byte-unchanged); deferred because clearing ordinal 366 unblocks them automatically. `M3-CP4c3-TB10-REV-CAND-01`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **83**. TB15/package85 remains current runtime authority: **372 PASS / 9 RED**, accepted **365/365**, first red 366 `SourceVertexFallbackUnbound` at edge 25-31 / face `(25,30,31)`. CB18/package86 is current immutable build/package authority at selector **382** and has executed no Directional runtime. Exact next is artifact-only `M3-CP4c-3-TB16` on package 86 / selector 382. PR #8 remains open, draft, and unmerged.
