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

## Current focus — `M3-CP4c-3-TB25-R1` (fresh immutable artifact-only re-execution)

`M3-CP4c-3-CB29` is **COMPLETE / CONTROL PROOF GREEN / RUNTIME NOT EXECUTED / SEMANTIC AUTHORITY UNCHANGED**.
It corrected only `M3-CP4c3-TB25-ORCH-01`; no product/test/fixture/selector/package byte changed and no Directional
runtime ran.

CB29 proof run/job `33915621191 / 101162027243` succeeded. Result/log artifacts:
`9953038617 / 9953039237` (`f1216938b3d543d4d3fcb498279b1ce432feac008ec240afbf9ae18b1fbe31cf` /
`5c2a3900e7d225e52651ced15edf6be0a0c320caf4c76aa247f06ec04dc17ac9`). The directly verifiable materialized
TB25 harness has SHA-256 `13ec524fa0fe609949b147ab36bf710392244b8202684ece2eea10eb5c83e0e9`; package authority and selector
365→403 / 401→403 exact-prefix checks passed with `runtime_started=false` and `directional_runtime_invocations=0`.

The first TB25 attempt remains invalid provenance at run/job `33910913448 / 101146905061`, result/log
`9951314815 / 9951315281`, **0/403** identities executed. `M3-CP4c3-TB25-ORCH-01` is now **CONTROL FIX PROVED /
AWAITING RE-EXECUTION / NON-STABLE** and is not closed until a fresh TB25 run reaches the unchanged gate from ordinal 1.

TB24 remains semantic runtime authority at **389 PASS / 12 RED**, accepted **365/365**. Stable totals remain
**44 events / 14 categories / 30 recurrences**, debt **5**; semantic M3 package count **90**. Immutable CB28 artifact
`9950303110` and selector 403 remain the runtime candidate; CP4c-3 remains OPEN.

### Exact next turn

Run **`M3-CP4c-3-TB25-R1`** under the unchanged frozen TB25 plan:

- [ ] reuse immutable artifact `9950303110`, source `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`, selector 403;
- [ ] reuse the CB29-proved pre-runtime representation and verify the exact harness SHA above;
- [ ] verify package, GMP, selector 365/401/403 hashes/counts/prefixes before runtime;
- [ ] execute all 403 selector identities exactly once, each in a fresh process, with every mutation flag false;
- [ ] do not rebuild, configure, relink, repackage, repair modes, mutate source/tests/fixtures/selectors, or replace the package;
- [ ] preserve the first invalid attempt separately from the fresh semantic ledger;
- [ ] if semantic RED, route to independent `TB25-R1-REV`; if orchestration fails before semantic measurement, follow the orchestration-failure edge.

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
  CP4c-3 remains open; **TB24 is the latest valid semantic runtime** at 389 PASS / 12 RED, accepted 365/365,
  selector403/package90 prepared by compile-green CB28; CB29 proved the corrected pre-runtime control with zero Directional runtime. Exact next: **`M3-CP4c-3-TB25-R1`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face ownership derivation:** TB24-REV proved the RED is an **ordering defect** — the certifier returns an error instead of a certificate, so the owner map, the consumer's census and D3 are all unreachable, and the relocated derivation reproduces the pre-CB27 answer (component 0, orbits `[0,1,3]`, locus `(0,1,2)`) because relocation added no information. `M3-CP4c3-TB21-CAND-01` stays UNADJUDICATED. CB28 compiled the discriminator; TB25 owns evidence and TB25-REV adjudication.
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

Current totals are **44 events / 14 categories / 30 recurrences**, classified at `M3-CP4c-3-TB24-REV`. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **90**. **TB24 remains the latest semantic runtime authority at 389 PASS / 12 RED, accepted 365/365.** CB28 artifact `9950303110` remains prepared for selector 403. CB29 proved the corrected pre-runtime harness/package authority with zero Directional runtime; exact next is `M3-CP4c-3-TB25-R1`. PR #8 remains open, draft, and unmerged.
