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

## Current focus — `M3-CP4c-3-CB26` (Code + Build, ORCHESTRATION CORRECTION)

`M3-CP4c-3-TB23-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` (**CC0–CC8** discharged, static only).

**The ORCHESTRATION-INVALID classification is upheld, and the defect is the harness - not CB25 and not the
package.**

- **The package never contains `test-data`.** `.github/workflows/agent-compile-reusable.yml` copies only the eight
  compiled targets to `$OUT/bin` and two libraries to `$OUT/lib`; **no workflow in the repository references
  `test-data`**. Fixtures reach the binaries only because the **execution harness stages them** into the layout
  `tests/TestFixturePaths.h:51-64` resolves. TB18-TB22 did that staging - TB21's report records binaries
  hard-linked into an execution view with fixtures extracted from the packaged source. **TB23's harness omitted
  it**, and verified the extracted source workspace, a path the executable never consults.
- **CB25 is not implicated.** Its diff touches `RemeshDiagnostics.h`, `GlobalTopologyPlan.h`, the new
  `GlobalTopologyCertificateDiagnostics.h`, `GlobalTopologyPlan.cpp`, `RemeshPipeline.cpp` and
  `FieldAlignedCurveNetworkTests.cpp` - **no CMake, no `TestFixturePaths.h`, no packaging**.
- **Why a slip became a pseudo-ledger:** `test_data_root()` **fails open** - when neither candidate path exists it
  returns the sibling path anyway - so a missing fixture tree surfaces as hundreds of file-open failures instead of
  one typed stop. The raw **342 PASS / 55 RED, accepted 327/365** are fixture-open failures, **audit-only, not
  regression authority**.
- **CB25 statically satisfies its contract, so re-execution is worth doing.** `certificate_side_orbit` is **gone**;
  `GlobalTopologyCertificateDiagnostics.h` derives `certifiedFaceBySourceFace` from certificate evidence and
  assigns an owner only when a component's certified-face set has exactly one element (`:135-137`); the CA3 pair
  loop (`:181-200`) quantifies over **uncut** adjacent pairs outside `componentBarriers` with **no**
  `certificateSeparatingSourceEdges` intersection and increments `examinedPairCount` for every qualifying edge -
  CB24's structural zero **cannot recur in this form**. Ordinal 396 is the CA6 variation witness, 395 the CA2
  independence witness.
- **Not credited:** the invalid run's ordinals 394-397 results. **CA2/CA4/CA5/CA6 remain runtime-unconfirmed.**

**Authoritative semantic runtime remains `M3-CP4c-3-TB22`: 387 PASS / 6 RED, accepted 365/365.** Carried surfaces
367/368/369/370/374 unchanged. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB26`** under §7 **CD0–CD8** of
`Architecture_M3_CP4c3_TB23_Independent_Review_Record.md`. **Control-plane only — no source change, no rebuild.**

- [ ] **CD0** — control-plane only; reuse package `9921914679`, source `e12396d4`, selector 397 byte-frozen.
- [ ] **CD1** — stage the execution view so `test-data/benchmarks/fixtures` sits at a path
      `tests/TestFixturePaths.h` resolves.
- [ ] **CD2** — verify a known fixture through the **consumer's own resolution rule**, not the source workspace.
- [ ] **CD3** — **fail closed**: do not start runtime if CD2 fails.
- [ ] **CD4** — document the required staged layout in the frozen plan and the harness.
- [ ] **CD5** — preserve TB23-EXEC's evidence as invalid-attempt provenance; promote none of it.
- [ ] **CD6** — no product change; the fail-open resolver (`TB23-REV-CAND-01`) stays out of scope.
- [ ] **CD7** — audit by assumption; package census unchanged at `9c7b12f4…0359a927`.
- [ ] **CD8** — publish `M3-CP4c-3-TB23-R1`'s obligations, chiefly a **non-zero `examinedPairCount`** and the
      failing component's **certified-face multiset**, which names the live branch.

Then **`M3-CP4c-3-TB23-R1`** re-executes the frozen TB23 plan on the same immutable package.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **88**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **CB25 is compile-green** at semantic source `e12396d...`, selector397/package88. Exact next: immutable **`M3-CP4c-3-TB23-EXEC`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face seed/ownership projection:** CB25 replaced the vacuous/circular diagnostics with certificate-derived, independently sided, falsifiable measurements without changing product semantics. Both branches of `M3-CP4c3-TB21-CAND-01` remain live until immutable TB23 evidence is reviewed. Exact owner: `M3-CP4c-3-TB23-REV`.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **88**. **TB22 remains the latest runtime authority until TB23 executes; CB25 is compile-green at semantic source `e12396d471c0754b112a40272a7992020ff49ced`, immutable package `9921914679`, selector397.** Exact next is `M3-CP4c-3-TB23-EXEC`, followed by evidence-only `M3-CP4c-3-TB23-REV`. PR #8 remains open, draft, and unmerged.
