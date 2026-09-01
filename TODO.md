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

## Current focus — `M3-CP4c-3-TB6-REV` (independent REVIEW + PLAN)

`M3-CP4c-3-TB6` is **COMPLETE / VALID SEMANTIC RED** on immutable package **75**. Authoritative run/job
`33458067065 / 99702200466` passed immutable pre/postflight, re-proved ordinals **1–365**, and first-reds ordinal
**366** at `VertexTransitSectorUnresolved`, source vertex **30**, face `(24,30,32)`, branch 1, `FaceInterior`, with
`publishedFaceCount=2` and faces `(25,30,31)|(30,31,119)`. Report:
`Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Report.md`.

The required 367–373 report-only remainder completed **1 PASS / 6 RED** with zero gate credit. Sphere 368 remains
`NoCarrierMatch / SourceEdgeUnavailable`; 369 still reports `saturationUsed=true`; repaired 370 now clears its prior
atlas precondition but returns `CellularityNotEstablished` without a source-face locus instead of
`EmptyNetworkOnClosedSurface`; 371/372 are upstream-blocked; 373 alone passes synthetically.

### Exact next turn

Run independent **`M3-CP4c-3-TB6-REV` REVIEW + PLAN only** under
`Architecture_M3_CP4c3_TB6_Independent_Review_Plan.md`. No runtime, compile, package, product/test/fixture/selector
mutation, unchanged TB retry, or semantic correction is authorized.

The review must:

1. reconstruct CB7's exact vertex-30 transit/election state and adjudicate Amendment 17 without treating two
   published faces as proof of equal elected directions;
2. trace why the production failure projection emits none of CB7's exact per-state/election rows;
3. adjudicate the compiled-but-unselected `ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState`
   identity, which is not in frozen selector 373;
4. classify ordinal 370's now-genuine A2a′ product red and preserve sphere/saturation scope boundaries;
5. freeze exactly one bounded successor CB, diagnostic-only if cause remains underdetermined.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — **ACTIVE**; TB6 returns to vertex 30 with two published faces, but Amendment 17's
  exact-direction falsifier is not exposed by the production exception.
- [ ] `M3-CP4c3-TB6-CAND-01` — **ACTIVE / diagnostic-projection gap**; compiled exact transit state/election evidence
  is not serialized at the gating production failure surface.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere remains localized to `NoCarrierMatch / SourceEdgeUnavailable`; fix unscheduled.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — repaired witness now measures the intended empty-network contract and is RED:
  `CellularityNotEstablished`, no source-face locus, instead of `EmptyNetworkOnClosedSurface`.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — partial; ordinal 373's synthetic pass does not prove mechanical zero-unbound.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — `saturationUsed=true` reconfirmed at 369; deferred behind the mechanical gate.

`M3-CP4c3-TB5-CAND-01`'s silent vertex-11 seed-drop is runtime-cleared as the first failure surface, and
`M3-CP4c3-TB4-DIAG-CAND-01`'s invalid ordinal-370 atlas precondition is repaired. Amendment 15's 371/372 contracts
remain **UNMEASURED, not falsified**, because both are blocked by the mechanical vertex-30 red.

### Scheduled from the adversarial architecture review — `ROADMAP.md` §3b / §3b-bis, **not CP4c-3 work**

Re-evaluated under a production lens on 2026-09-01
(`Architecture_Adversarial_Review_Reevaluation_Production_Lens.md`): five of six rejections reversed after the
fixtures were measured as near-uniform, sliver-free, low-valence meshes (area ratio ≤ 3.17, max aspect ≤ 2.67, max
valence 6, ≤ 152 V) that cannot exhibit the targeted cases. **Amendments 20 and 21** declared.

- [ ] **`M4-CP-COND`** — **Amendment 20**: the conditioning stage before A0. Admissibility certification, a
  conditioned immutable source product with a certified correspondence to the raw input, typed inadmissibility.
  Sliver repair-or-refusal, near-duplicate merging, bounded-lattice quantization and field-matching repair live
  here and **only** here.
- [ ] **`M4-CP-SCALE`** — S1 expression-swell measurement, S2 certified filters, S3 exact limit-cycle detection
  with a typed `LimitCycleTermination`, S4 incremental Betti early rejection.
- [ ] **`M5-CP-REG`** — **Amendment 21**: degeneracy taxonomy, regularization policy interface, certificate
  recording of every regularization and its mapping onto the D0–D4 ladder, plus the typed index-deficit
  reconciliation contract.
- [ ] **S5** genus ≥ 2 witness (M4). **S6** input-perturbation stability, promoted to the acceptance evidence for
  the conditioning contract (M4-CP-COND).

**Witness-coverage gap — never exercised:** slivers / anisotropy; valence > 6; scale beyond 152 V; **negative-index
singularities** (all are `+1`); boundary-truncated separatrices; inadmissible input fields; genus ≥ 2; exact ties
from symmetric input. Matrix and owners in `ROADMAP.md` §3b-bis.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, semantic packages **73**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 TB6 preserves the accepted 365-prefix but remains RED at ordinal 366 on the vertex-30 transit/election surface. Exact next is independent `M3-CP4c-3-TB6-REV`; no retry or correction precedes review.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB6 preserves the accepted 365-prefix and first-reds ordinal 366 at `VertexTransitSectorUnresolved`, source vertex 30, with two published faces. CB7 cleared TB5's silent seed-drop, but the production exception omits the exact state/election rows required to adjudicate Amendment 17. Owned by `TB6-REV`; no candidate-order shortcut.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **73** after CB7/package 75. PR #8 remains open, draft, and unmerged.
