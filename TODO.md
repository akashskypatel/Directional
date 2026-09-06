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

## Current focus — `M3-CP4c-3-CB38` (Code + Build, runtime-free)

`M3-CP4c-3-TB32-REV` promoted TB32 to **current valid semantic runtime authority**.

- selector **408**, **397 PASS / 11 RED**, accepted **1–365 = 365/365**, RED
  `366,367,368,369,370,374,390,393,398,406,407`;
- immutable CB37 package `9983643195` / source `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`;
- run/job `34024893763 / 101464028080`; result/log `9986786215 / 9986786399`; every row `selected=1`;
- certified ownership **300 / 0 / 0**.

**Both DEFN-R4 falsifiers held.** Zero emissions of `TraceArcDoesNotSeparateItsSides` and zero of
`UncutFaceComponentOrbitSeedNotUnique` across all 408 raw logs; 366/367 **advanced** to
`RegionBoundaryNotSingleWalk`, strictly later, which CS6 permitted. **Two guards cleared in two turns.**

**CS3 is unmet, and DEFN-R4.5 was under-specified.** 390/393/406/407 did not return to PASS: removing their
failure-code assertion left assertions about **a stage the plan no longer fails at**. **Which** assertion fails is
not in the report — the third consecutive turn with that gap — so the review declined to guess between two causes
that imply different corrections.

**Two evidence findings.** Seed-stage `uncutFaceComponent*` fields are **back-filled onto later failures**; and
**TB32's ledger SHA-256 is byte-identical to TB31's** despite entirely different failure reasons, so the ledger
digest is a pass/fail fingerprint only.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3
package count **97**. CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB38`**, Code + Build, runtime-free, under **CT3–CT7** of
`Architecture_M3_CP4c3_TB32_Independent_Review_Record.md`:

- [ ] **CT3** frontier evidence carries a typed **stage label**; `uncutFaceComponent*` publish **only** when the
      uncut-component stage raised the failure. Narrows DEFN-R4.4.
- [ ] **CT4** ordinals **390/393/406/407** replaced **in place** with two admissible outcomes — the stage failed and
      published, **or** the stage was cleared **and** the later failure published its labelled evidence.
      **Absence alone is never a pass.**
- [ ] **CT5** a per-row **failure-detail digest**, or one published beside the ledger; existing columns unchanged.
- [ ] **CT6** the harness is **parameterised by turn identity**, not relabelled; `baseline-authority.txt` records
      the executing run.
- [ ] **CT7** `M3-CP4c-3-TB33`'s report **must** transcribe the failing assertion text for every RED ordinal in the
      focused index. A report that omits it is **incomplete**.

**Falsifiers stated first:** if the four still fail with stage-labelled evidence published, the re-scoping is wrong;
if either retired code reappears, CB38 changed forbidden behaviour; if 366/367 move **earlier**, CB38 regressed the
pipeline.

**Must not:** change product topology, barriers, ownership or the retired guard; weaken or re-scope ordinal 398;
touch 368/369/370/374; relax anything the four witnesses legitimately own; add any ownership diagnostic; change any
accepted identity or selector byte.

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
  CP4c-3 remains open. **TB31 remains semantic runtime authority** at 397 PASS / 11 RED, accepted 365/365.
  CB37 is compile-green on immutable package `9983643195` / source
  `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`; no runtime executed. Exact next:
  **`M3-CP4c-3-TB32-EXEC`**, artifact-only runtime under the frozen TB32 plan.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 region-frontier runtime proof:** source-face ownership is closed at last-runtime **300 / 0 / 0**.
  CB37 implements DEFN-R4 ownership-map semantics and code-independent frontier evidence at source
  `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`. Exact next is TB32-EXEC on artifact `9983643195`; runtime must
  decide whether 366/367 advance and must restore 390/393/406/407 without disturbing carried credibility rows.
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

Current totals are **44 events / 14 categories / 30 recurrences**, classified at `M3-CP4c-3-TB32-REV` with no stable change. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **97**. **`M3-CP4c-3-TB32` is the current valid semantic runtime authority at 397 PASS / 11 RED, accepted 365/365 on selector 408, with ownership total at 300/300 and both retired failure codes absent from all 408 logs.** Exact next is `M3-CP4c-3-CB38` under CT3–CT7. PR #8 remains open, draft, and unmerged.
