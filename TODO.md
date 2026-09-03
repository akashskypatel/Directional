# Directional Surface-Cell TODO

Last updated: 2026-09-03 UTC

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

## Current focus — `M3-CP4c-3-TB20-REV` (independent REVIEW + PLAN, planning-only)

`M3-CP4c-3-TB20` is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / NON-STABLE** on immutable CB22
semantic source **`c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`**.

Authoritative TB20 runtime evidence:

- compile run/job: **`33805683152 / 100815534364`**; immutable compile artifact **`9912976409`**;
- runtime run/job: **`33809177155 / 100826787667`**;
- result/log artifacts: **`9914226104 / 9914226799`**;
- selector 385: **388 identities**, SHA-256 **`164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`**;
- complete gate: **380 PASS / 8 RED**, accepted ordinals 1–365 **365/365 PASS**;
- red ordinals unchanged: **366, 367, 368, 369, 370, 371, 372, 374**;
- complete ledger SHA-256: **`0a4d8b17abd4e397bb80ff0fa92b70bc50e971589e368d1cdf2ecef85868203a`**;
- pre/post package byte+mode census identical at **`f0b1beec127dacbec9b356630ce8d9e7364de55a5b014598ee67fcdab653c5b0`**;
- no configure, compile, relink, benchmark, package/mode repair, generated discovery, or source/test/fixture/selector mutation occurred in TB20.

TB20 resolves the component-seed branch: ordinal 366 remains `UncutFaceComponentOrbitSeedNotUnique` at the
iteration-order source-face locus `(0,1,2)`, but the discriminating component is **0** with **seed count 3**,
**`seedState=Multiple`**, and exact seed orbits **`[0,1,3]`**. The historical torus occurrence remains the distinct
zero-seed mechanism and must not be merged with this one.

The retained component evidence is intentionally bounded: 64/191 component-face rows and 64/97 boundary rows are
retained and marked truncated. In the retained boundary window every opposite side is labeled; seed contributions
are 44×orbit 0, 1×orbit 1 and 1×orbit 3, with 18 barrier skips. No `edgeOrbitEvidenceNotUnique` row occurs in that
retained production window, so global absence cannot be inferred. Ordinal 386 independently proves the projection
contract preserves that reason when present.

TB19 and TB20 are now two consecutive TB turns with 371/372 blocked at the same downstream mechanical frontier, so
the factual standing trigger in `M3-CP4c3-TB10-REV-CAND-01` is met and must be adjudicated by TB20-REV.

### Exact next turn

Run **`M3-CP4c-3-TB20-REV`** from
`Architecture_M3_CP4c3_TB20_Independent_Review_Plan.md`.

- [ ] Re-verify TB20 source/artifact/run/selector/ledger/package immutability under CW0.
- [ ] Independently prove the `Multiple`, count-3, component-0 discriminator and orbits `[0,1,3]` under CW1.
- [ ] Trace all three seeds to producer semantics and decide whether the exactly-one-seed requirement or its inputs are wrong under CW2–CW4; do not guess the 33 unretained boundary rows.
- [ ] Keep the historical zero-seed torus mechanism separate and preserve CB21's settled one-sided fragment-owner behavior.
- [ ] Adjudicate the now-triggered test-only atlas-scoped 371/372 decoupling under CW6.
- [ ] Keep 368/369/370/374 under their existing owners and freeze exactly one smallest sufficient successor under CW9.

No implementation, test/fixture/selector mutation, compile, benchmark, or runtime execution is authorized in
TB20-REV. Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events /
14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **85**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB20/selector385 is current runtime authority** at 380 PASS / 8 RED and accepted 365/365. Exact next: planning-only **`M3-CP4c-3-TB20-REV`** under CW0–CW9.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — region ownership frontier:** TB20 runtime-proves the current mechanical branch is **`UncutFaceComponentOrbitSeedNotUnique / component 0 / seedState=Multiple / seedCount=3 / seedOrbits=[0,1,3]`**. The iteration-order source-face locus remains `(0,1,2)` and is non-discriminating. Exact owner is `M3-CP4c-3-TB20-REV` under CW1–CW4; vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (trigger reached, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor. TB19 and TB20 are now two consecutive TB turns with the same downstream `UncutFaceComponentOrbitSeedNotUnique` mechanical frontier, so the standing trigger is met. TB20-REV must adjudicate the already-specified test-only atlas-scoped accessor without changing their assertions or selector membership. `M3-CP4c3-TB10-REV-CAND-01`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **85**. **TB20/selector385 is current runtime authority: 380 PASS / 8 RED, accepted 365/365; the mechanical component seed branch is `Multiple` with count 3 and orbits `[0,1,3]`.** Exact next is planning-only `M3-CP4c-3-TB20-REV`. PR #8 remains open, draft, and unmerged.
