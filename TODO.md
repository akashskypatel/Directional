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

## Current focus — `M3-CP4c-3-TB22` (Test + Benchmark, ARTIFACT-ONLY)

`M3-CP4c-3-CB24` is **COMPLETE / COMPILE PASS / RUNTIME-FREE**. Record:
`Architecture_M3_CP4c3_CB24_Code_Build_Report.md`. Built evidence/source commit:
**`d69729a69a40b020968ed6ef1fbc1bc788284518`**. Compile run/job **`33823590494 / 100871347582`**;
immutable result artifact **`9919225745`**, SHA-256
`7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`; log artifact **`9919226113`**.
All eight required targets compiled/linked with **GMP/GMPXX mandatory**, source clean, and `runtimeExecution=false`.
No Directional test, benchmark, discovery/list/help/version command, CLI, fuzzer, or custom input executed.

CB24 discharged **BY0–BY9 at the implementation/build boundary** without changing the protected topology semantics:

- [x] **BY0** — accepted 365 untouched; selector 391 byte-frozen; eight-target GMP compile PASS.
- [x] **BY1** — bounded boundary rows retain distinct seed orbits and `noSeedReason` values before positional fill.
- [x] **BY2** — minority rows publish full edge/face/seed metadata and the seed rule.
- [x] **BY3** — minority-edge sides publish certificate-face attribution.
- [x] **BY4** — typed projection-faithfulness residual plus bounded witness rows is published.
- [x] **BY5** — compiled witnesses cover each new diagnostic field and unrelated-error byte identity.
- [x] **BY6** — selector **393** appended with exactly two identities; selector 391 remains its exact byte prefix; manifest regenerated.
- [x] **BY7** — ordinal 391 re-scoped so the owned sphere dependency cannot red the mechanical/torus halves.
- [x] **BY8** — no product semantic change; guard/barrier/partition/seed/certificate authorities remain untouched.
- [x] **BY9** — TB22 discriminators are encoded in the artifact-only plan.

Selector 393 contains **393 identities**, SHA-256
`ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`; selector 391 remains
`f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0` and is an exact prefix.

### Exact next turn

Run **`M3-CP4c-3-TB22`** exactly from
`Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Plan.md` against immutable artifact **9919225745**.
Execute all 393 identities in ordinal order, one fresh process per identity, without configure/compile/relink/repair,
mutation, generated binary discovery, or benchmark execution. Preserve the exact BY2/BY3 minority rows, BY4 residual and
witnesses, ordinal-391 skip evidence, the full 393-row ledger, and an identical pre/post package byte+mode census.

The expected no-new-regression ledger is **387 PASS / 6 RED**, with carried REDs
`366,367,368,369,370,374`; this is an expectation, not permission to manufacture success. Accepted 1–365 must remain
**365/365 PASS**. The actual projection-faithfulness residual is deliberately **not predetermined**.

After TB22, the mandatory next boundary is independent **`M3-CP4c-3-TB22-REV`**. No correction or DEFN execution is
pre-authorized. Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains
**44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count
**87**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB21 remains current runtime authority** at 384 PASS / 7 RED and accepted 365/365, while CB24 package 87 / selector393 is the exact artifact-only validation authority. Exact next: **`M3-CP4c-3-TB22`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 unvalidated source-face projection:** CB24 now publishes the minority seed rows, certificate-face attribution and projection-faithfulness residual without changing the guard/barrier/certificate semantics. Exact runtime owner is TB22; interpretation/correction owner is independent TB22-REV. `M3-CP4c3-TB21-CAND-01`.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [ ] **CP4c-3 ordinal 391 diagnostic dependency:** CB24 re-scoped the test so mechanical/torus evidence is independent and the unavailable prescribed-sphere half is skipped-with-reason while 368 remains open. TB22 must prove ordinal 391 no longer REDs for this dependency. `M3-CP4c3-TB21-CAND-02`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **87**. **TB21 remains current runtime authority: 384 PASS / 7 RED, accepted 365/365; CB24 artifact 9919225745 and selector393 are the exact next artifact-only validation authority.** Exact next is `M3-CP4c-3-TB22`; the mandatory successor after TB22 is independent `M3-CP4c-3-TB22-REV`. PR #8 remains open, draft, and unmerged.
