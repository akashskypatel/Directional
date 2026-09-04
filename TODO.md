# Directional Surface-Cell TODO

Last updated: 2026-09-04 UTC

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

## Current focus — `M3-CP4c-3-CB30` (Code + Build, runtime-free)

`M3-CP4c-3-TB25-R1` is **COMPLETE / VALID IMMUTABLE SEMANTIC RUNTIME / SEMANTIC RED / ACCEPTED PREFIX SAFE** and
`M3-CP4c-3-TB25-REV` has adjudicated it. Formal run/job `33919389753 / 101173990222` consumed immutable CB28
package `9950303110` and selector 403 in 403 fresh processes.

- ledger: **393 PASS / 10 RED**, accepted **1–365 = 365/365 PASS**, SHA-256
  `bdcfbb9d2ea5e7c45535a0b95e2d1914f5245bab498a62dd99cb7b0348936cc0`;
- RED ordinals: `366,367,368,369,370,374,389,390,393,398`;
- result artifact `9954531868`; log artifact `9954532357`.

**TB25-REV verdict.** CH6/CH7 are runtime-proved — **384 and 385 return to PASS** and the ownership publication is
readable: `300 faces — 74 established, 226 unavailable, 0 conflicting`, conflict census published with **0 rows**;
component 0 has **191 faces, 97 boundary edges, seedCount 0, seedState None**. Ten REDs, **four causes**: 366/367
the open product problem, 398 the honest gate, 389/390/393 collateral assertions their identities do not own,
368/369/370/374 carried surfaces. **The defect:** CB28's seed rule admits one source where the pre-CB27 rule
admitted two — **83 attributed boundary edges → 0** on the identical component. `M3-CP4c3-TB21-CAND-01` **CLOSES
as ill-formed**; CH8's conflict census was **vacuous** (it reads only established owners). **No stable event
added.**

Stable accounting is **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3
package count **90**. CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB30`**, Code + Build, runtime-free, GMP/GMPXX linked, under **CJ6–CJ9** of
`Architecture_M3_CP4c3_TB25_Independent_Review_Record.md`:

- [ ] **CJ6** three censuses per uncut component — boundary edges with barrier class, interior arc-incidence,
      vertex transit — published on the failure path and **never gated on an established owner**; component 0's 97
      boundary edges untruncated.
- [ ] **CJ7** restore the second admissible seed source; publish `Conflicting` with the full multiset for
      multi-seed components; **choose no winner**.
- [ ] **CJ8** one contract per gate — 389/390/393 assert `proves_embedded_cellularity()`, 390's
      `ASSERT_GT(..., 1U)` replaced in place; **398 untouched**.
- [ ] **CJ9** selector **405** with 403 as an exact prefix; gating ordinals 404 and 405.

**No barrier may be added or removed and no attribution rule changed beyond the CJ7 restoration before CJ6
reports.** No Directional runtime before `M3-CP4c-3-TB26`.

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
  CP4c-3 remains open; **TB25-R1 is the latest valid semantic runtime** at 393 PASS / 10 RED, accepted 365/365,
  adjudicated by `M3-CP4c-3-TB25-REV`. Selector403/package90 remain immutable; exact next: **`M3-CP4c-3-CB30`**
  under CJ6–CJ9.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face ownership derivation:** TB25-REV diagnosed the seed rule as **starved** — CB28 admits one seed source where the pre-CB27 rule admitted two, taking component 0 from **83** attributed boundary edges to **0**. `M3-CP4c3-TB21-CAND-01` is **CLOSED as ill-formed** (3 owners under one rule, 0 under another). The successor question is a dichotomy about the object: **either component 0 lies in exactly one certified face, or a separating arc meets its interior**, the only hidden-arc mechanism being a trace transiting a vertex. Exact owner: `M3-CP4c-3-CB30` CJ6–CJ7.
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

Current totals are **44 events / 14 categories / 30 recurrences**, classified at `M3-CP4c-3-TB25-REV`. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **90**. **TB25-R1 is the latest semantic runtime authority at 393 PASS / 10 RED, accepted 365/365.** Immutable CB28 artifact `9950303110` remains unchanged. Exact next is `M3-CP4c-3-CB30` under CJ6–CJ9. PR #8 remains open, draft, and unmerged.
