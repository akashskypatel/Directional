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

## Current focus — `M3-CP4c-3-TB21-REV` (Independent REVIEW + PLAN — STATIC ONLY)

`M3-CP4c-3-TB21` is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE**. Record:
`Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md`. Exact review contract:
`Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md`.

TB21 consumed immutable CB23 artifact **`9916511617`** from semantic source
**`fa5646106ccaa23770b84a935c6d1d6007928640`** and executed all **391** selector identities one per fresh
process. Runtime run/job **`33818038269 / 100854435211`** completed at **384 PASS / 7 RED**, accepted
**365/365 PASS**, exact RED set **366/367/368/369/370/374/391**. Result/log artifacts are
**`9917317234 / 9917317654`**; package pre/post byte+mode census is identical at
`e15a8ababed2d6580d36abe9e2421a9d573bd29fb5fe36fb08ab844f80161897`.

### Load-bearing TB21 finding

Ordinal 366 remains `UncutFaceComponentOrbitSeedNotUnique` on component 0 with `seedState=Multiple`, seed count 3,
and untruncated seed orbits `[0,1,3]`. But the complete production census for the same mechanical path reports the
actual embedded graph as **`V=22,E=26,F=6,componentCount=1,sourceChi=2,residual=0`**, and the mechanical
`SurfaceCutGraph` exists only after its actual-complex certificate passes `proves_cellularity()`. This contradicts
TB20-REV's load-bearing inference that the three-seed state proves that certified actual complex non-cellular.

Component 0's complete aggregate boundary attribution is orbit **0→81, 1→1, 3→1**, 3 rows untruncated,
83/97 boundary edges attributed; 14 are barrier/no-seed. Ordinals **371/372 both PASS** their own unchanged atlas
assertions, closing their test-coupling candidate. 389/390 PASS. Ordinal **391 RED** because the prescribed-sphere
half has no `sphere.cutGraph`; this co-reaches the already-owned sphere 368 surface and is not a new stable class.

### Exact next turn — BX0–BX8 only

- [ ] **BX0:** independently re-establish source/package/selector/TB21 ledger and immutable postflight authority.
- [ ] **BX1:** statically reconcile the `SurfaceCutGraph` actual-complex certificate with the `GlobalTopologyPlan`
  source-face component/seed construction; name the exact graph/partition each counts.
- [ ] **BX2:** adjudicate the scope of `M3_CP4c_Frozen_Definitions.md` Part I §3 and Parts IV/V against the
  actual-complex/cut authority introduced by Amendments 13–14; do not weaken either guard or certificate.
- [ ] **BX3:** explain how three seed orbits and the 81/1/1 boundary attribution coexist with residual 0, including
  the 14 barrier/no-seed edges, without inferring from error names.
- [ ] **BX4:** re-evaluate `M3-CP4c3-TB20-REV-CAND-01` and the CB21 governance candidate only after BX1–BX3 settle
  the representation relation. No silent revert or preservation of CB21 is authorized.
- [ ] **BX5:** close `M3-CP4c3-TB10-REV-CAND-01` from TB21's 371/372 runtime proof.
- [ ] **BX6:** keep ordinal 391's prescribed-sphere diagnostic dependency separate from the mechanical contradiction.
- [ ] **BX7:** reconcile every TB21 RED in `Regression_Root_Cause_Tracker.md`; stable totals remain unchanged unless
  the evidence independently proves a new stable category/recurrence.
- [ ] **BX8:** freeze exactly one smallest successor. A DEFN is permitted only if review proves a real normative
  conflict; a diagnostic-only CB only if an indispensable representation relation is still absent. No runtime in review.

The review must update `ORIENTATION.md` and perform the mandatory CP4c REVIEW-turn document consolidation before
closing. **No Code + Build, DEFN execution, test, benchmark, configure, compile, link, package or runtime is
pre-authorized.**

Accepted runtime authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains
**44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package
count **86**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB21/selector391 is current runtime authority** at 384 PASS / 7 RED and accepted 365/365. Exact next: static independent **`M3-CP4c-3-TB21-REV`** under BX0–BX8.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 topology-authority contradiction:** TB21 preserves `UncutFaceComponentOrbitSeedNotUnique / component 0 / Multiple / seeds [0,1,3]` while the actual `SurfaceCutGraph` certificate reports `V=22,E=26,F=6,χ=2,residual=0` and proves cellularity. Exact owner is `M3-CP4c-3-TB21-REV` BX1–BX4; no guard/certificate correction is pre-authorized. `M3-CP4c3-TB21-CAND-01`.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [ ] **CP4c-3 ordinal 391 diagnostic dependency:** the prescribed-sphere half cannot compare Euler census because `sphere.cutGraph` is unavailable at the existing ordinal-368 `CellularityNotEstablished` surface. Keep separate from the mechanical contradiction. `M3-CP4c3-TB21-CAND-02`.

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
