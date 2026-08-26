# Directional Surface-Cell TODO

Last updated: 2026-08-26 UTC

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

## Current focus — `M3-CP4c-0-CB6` — EXACT NEXT / Code + Build, measures J0–J7 (diagnostic-only)

`M3-CP4c-0-TB-R5` is **COMPLETE / VALID SEMANTIC RED** on the immutable CB5 package. Authoritative hosted run/job `32994846466 / 98261255799` consumed package `9601160869` from semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e`; result artifact `9616160533` has ZIP SHA-256 `1ecfd85f06b40466f0e8193d1603950cd93b120723568024a1b50595e9902ad8`, and diagnostic artifact `9616161522` has ZIP SHA-256 `7cb10caee2f1e861368da3098e320f10bee3b13d51439bc868e1e3c60aa14b0e`. The frozen gate is **338/338 PASS**, accepted prefix **316/316 PASS**, prior CP4c-0 prefix **328/328 PASS**, F3 is **2/2 PASS**, G5 is **PASS / non-gating**, and postflight package/source/fixture/selector/executable inventories are byte-identical.

H1 is **PASS / non-gating** and published the decisive A1-only census: **390 violations / 4224 checked pairs = 9.23295%**, classified `H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED`. By witness: two-ring **4/160 (2.5%)**, four-triangle fan **2/32 (6.25%)**, prescribed sphere **144/2304 (6.25%)**, torus **240/1728 (13.8889%)**. Most sphere/torus violations have `signedLift=0`, and violations also occur at even and odd nonzero lifts. Therefore the frozen **H-A odd-lift-only** hypothesis and **H-C zero-census/A2a-only** hypothesis are excluded; the ~50% uniform-index-error branch is unsupported. H-B matching aliasing remains plausible but is **not proved** by H1 because the census alone does not establish singularity localization. Q8 is creditable and remains **RED at criterion 2** because the prescribed sphere still does not publish its required 24-trace network.

- [x] `M3-CP4c-0-DEFN` — COMPLETE.
- [x] `M3-CP4c-0-CB1` — COMPLETE / BUILD GREEN.
- [x] `M3-CP4c-0-TB` — COMPLETE / VALID RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB2` — COMPLETE / BUILD GREEN. Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — COMPLETE / VALID SEMANTIC RED.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB3` — COMPLETE / BUILD GREEN. Package `9589508430`.
- [x] `M3-CP4c-0-TB-R3` — COMPLETE / VALID SEMANTIC RED. 336/338; F3 2/2.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — COMPLETE. Both reds test-side; Amendment 7; G0–G8.
- [x] `M3-CP4c-0-CB4` — COMPLETE / BUILD GREEN. Package `9591540182`; test-side corrections only.
- [x] `M3-CP4c-0-TB-R4` — COMPLETE / VALID SEMANTIC RED. **338/338 PASS**, F3 **2/2 PASS**, G5 PASS/non-gating; Q8 CREDITABLE / RED because the sphere does not publish a network.
- [x] `M3-CP4c-0-TB-R4-REVIEW-PLAN` — COMPLETE. Symptom proved; mechanism reduced to H-A/H-B/H-C; H0–H7 frozen.
- [x] `M3-CP4c-0-CB5` — **COMPLETE / BUILD GREEN.** H1 A1-only census identity, H2 published `signedLift`, H3 ordered trace-step history, H4 matching-provenance audit; H5 no-production-change boundary preserved. Package `9601160869`.
- [x] `M3-CP4c-0-TB-R5` — **COMPLETE / VALID SEMANTIC RED.** Frozen 338/338, F3 2/2, G5 PASS/non-gating; H1 `390/4224`, `H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED`; Q8 CREDITABLE / RED at criterion 2.
- [x] `M3-CP4c-0-TB-R5-REVIEW-PLAN` — **COMPLETE.** H1's **mechanism is correct** (verified in source: it
  applies the published `signedLift` per Amendment 7). Its **population is not**: the four-triangle fan's
  2 violations are a **fixture artifact**, proved by arithmetic — `make_index_one_singularity_field`
  leaves the field vectors globally constant and *imposes* `matching=±1` on one edge, so for edge `1-4`
  the published `signedLift=0` is **exactly correct** (`+1 + 0 − 1 = 0`) and the disagreement is forced
  by a matching that contradicts the geometry. One edge × two directions = **exactly the 2 observed**.
  H-A and H-C independently re-confirmed excluded; **H-B undecided**, and the brief's fan-based clause
  against it is **withdrawn**. Record:
  `Architecture_M3_CP4c0_TB_R5_Independent_Review_Record.md`.
- [ ] `M3-CP4c-0-CB6` — **EXACT NEXT.** Code + Build only, measures **J0–J7**, **diagnostic-only — no
  production semantics change.** **J1 is the cycle's point:** decompose the published lift into
  `matching`, `rawGauge[source]`, `rawGauge[target]` per violation, plus singular-vertex incidence and
  distinct-pair counts — the review's §7 decision table then names the owner unambiguously. J2 quarantines
  the synthetic-field fan witness; J3 adds an independent matching-versus-geometry check; J4 records
  matching provenance per witness. Compile only — **execute nothing.**
- [ ] `M3-CP4c-1` — OPEN, blocked on CP4c-0.
- [ ] `M3-CP4c-2-DEFN` — BLOCKED.
- [ ] `M3-CP4c-3-DEFN` — BLOCKED.

Frozen selector authority remains **338** `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; accepted first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. H1 remains explicitly outside the 338 selector and has no credit. Latest accepted runtime remains CP4ab **316/316**. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **44**.

**H1 disposition after review — corrected.** H-A and H-C remain excluded. But two standing readings are
now **withdrawn**:

1. **The fan's 2 violations are an artifact, not signal.** Its field keeps the direction vectors globally
   constant and imposes `matching=±1` on one edge; the published lift for that edge is *correct*
   (`+1 + 0 − 1 = 0`) and the flow disagreement is forced by a matching that contradicts the geometry.
   The brief's use of the fan as evidence weakening H-B does not hold.
2. **The lift histogram carries no information about matching.** `signedLift = matching + g_src − g_tgt`
   is a sum of three unobserved terms, so lift-0 dominance is consistent with almost any matching
   distribution. The ±1/±2/±3 tail symmetry is imposed by the census's own two-direction loop, not by the
   field — and every count is therefore doubled. **Distinct disagreements: two-ring 2, fan 1 (artifact),
   sphere 72, torus 120. Corrected population 388 directed / 194 distinct over three legitimate
   witnesses.**

**Do not attempt a production fix until J1's decomposition fills in the review's §7 decision table** —
each branch of it names a different owner (field matching, gauge composition, or flow classification).
**Q8 stays red at criterion 2; do not plan the next TB as a Q8 close.**

## CP4c documentation — consolidated 2026-08-26

Twenty-four per-turn CP4c execution documents and superseded review briefs were retired into
**`M3_CP4c_Consolidated_Record.md`** under explicit user authorization, preserving every evidence
identifier. Thirty-three CP4c documents became twelve. Retained live: the CP4c-0 DEFN charter and frozen
definitions, the five independent reviews (they carry Amendments 1–7 and measure series E/F/G/H), and
all selector `.txt` authority files. A citation naming a retired document now points at the consolidated
record — **retired provenance, not lost authority**. CP4c-0 and CP4c-1 remain **OPEN**; the record is
historical and closes nothing.
## After M3 exit

`ROADMAP.md` §4 proposes the checkpoint decomposition for **M4–M8** — seventeen checkpoints plus five `-DEFN` planning turns to reach `M8-CP3`, the production-ready exit. That decomposition is a **proposal until each milestone's `-DEFN` turn freezes it**; gate arithmetic beyond 322 is deliberately not fixed.

## Carried forward from M2

- [ ] **3 latent fixture-authority sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options assert success but pass only because their complexes never reach boundary-ownership resolution; none are in the frozen selector.
- [ ] **Remove the `= {}` default** on the authority-consuming `complete_surface_cell_complex` overload (`PatchDescriptor.h:427`) so omission stops compiling.
- [ ] **Establish authority-carrying completion options as the local idiom.** `SurfaceCellComplexCompletionOptions` remains authority-unset by default across the affected tests.

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
- [ ] **M3 — field-aligned curve network.** CP4ab accepted at **316/316**; CP4c split into **CP4c-1 (318)**, **CP4c-2 (321)**, **CP4c-3 (322)**.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

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

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **44**. PR #8 remains open, draft, and unmerged.
