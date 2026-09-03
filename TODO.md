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

## Current focus — `M3-CP4c-3-TB19-REV` (independent REVIEW + PLAN)

`M3-CP4c-3-TB19-EXEC` is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE**. Current runtime report:
`Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Report.md`.

Immutable semantic/package authority remains CB21 source
**`b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`**, compile run/job
**`33794307778 / 100778238374`**, artifact **`9908695433`**. TB19 authoritative run/job
**`33798040003 / 100790444711`** executed selector **384** completely:

- **376 PASS / 8 RED**;
- accepted ordinals **1–365: 365/365 PASS**;
- reds **366/367/368/369/370/371/372/374**;
- exact ledger SHA-256
  **`e9ab64a8392aa1e16e30e03f440865914df846567e4b4fd12f3dce241841c04b`**;
- result/log artifacts **`9910078670 / 9910079341`**;
- pre/post package byte+mode census **IDENTICAL** at
  **`c238668140634325a75dbb48ed23ce5659376cb5d2d7b79f3f3f46ab275e133d`**;
- ordinal **384 PASS**.

CB21's fragment-owner correction is runtime-proved at its intended surface. Ordinals **366/367/371/372** all move
past `TraceCutFaceFragmentCountMismatch`; their new terminal frontier is
`UncutFaceComponentOrbitSeedNotUnique`, source face **`(0,1,2)`**. The retained error does not distinguish zero
component seeds from multiple component seeds, so new `M3-CP4c3-TB19-CAND-01` is review-owned.

The mechanical witness keeps the intended observational evidence: face `(0,1,102)` has owner/expected/deficit
`1/2/1`, local fragment count 2, one non-crossing shared chord trace 1 / arc 15 / segment 4 / orbits `0/0`.
The full untruncated census has 70 face rows, 26 arc rows, 12 trace rows; arc 15 `sharesOrbit=true`, trace 1
`terminalSlit=false`, total/exterior/non-exterior orbit counts `6/0/6`. Carried 368/369/370/374 terminal semantics
are unchanged from TB18.

### Exact next turn

Run **`M3-CP4c-3-TB19-REV`** under
`Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md`. Review only; no runtime, compile, package, product/test/
fixture/selector mutation, and no successor CB before the review adjudicates the new frontier.

- [ ] Re-verify immutable TB19 authority, accepted 365/365, selector 384, ledger, and package census.
- [ ] Determine whether the `(0,1,2)` component seed set is statically provable as zero, greater than one, or still
      unobservable; do not infer it from the global six-orbit census.
- [ ] Compare the historical torus same-code stop without assuming the same root cause.
- [ ] Adjudicate `M3-CP4c3-TB18-REV-CAND-01`: 70/70 retained mechanical face arrangements are non-crossing, but
      witness-local observation is not automatically a universal invariant.
- [ ] Reassess 371/372 shared-fixture coupling now that the fragment mismatch is cleared.
- [ ] Keep 368/369/370/374 under existing owners unless static evidence proves semantic movement.
- [ ] Update regression accounting, `ORIENTATION.md`, and perform mandatory REVIEW-turn document consolidation.
- [ ] Freeze exactly one smallest justified successor plan only after the review measures are discharged.

CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14 categories / 30 recurrences**;
produced-witness debt **5**; semantic M3 package count **85**.


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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB19/selector384 is current runtime authority** at 376 PASS / 8 RED and accepted 365/365. CB21's fragment-owner correction is runtime-proved; the new frontier is `UncutFaceComponentOrbitSeedNotUnique` at `(0,1,2)`. Exact next: independent **`M3-CP4c-3-TB19-REV`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — region ownership frontier:** TB19 runtime-proves the CB21 one-sided fragment-owner correction: 366/367/371/372 clear `TraceCutFaceFragmentCountMismatch`, accepted 1–365 stays 365/365, and ordinal 384 passes. The next typed frontier is **`UncutFaceComponentOrbitSeedNotUnique` at `(0,1,2)`**; retained evidence does not distinguish zero component seeds from multiple seeds. Exact owner is `M3-CP4c-3-TB19-REV`. Vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (deferred, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor, which throws unless all five downstream products are retained. TB19 confirms both clear the fragment mismatch but still abort at the shared downstream `UncutFaceComponentOrbitSeedNotUnique` frontier, so their own Amendment-15 atlas contracts remain unmeasured. The already-specified test-only atlas-scoped accessor remains **review-owned, not authorized**; TB19-REV decides whether to decouple now or keep it deferred. `M3-CP4c3-TB10-REV-CAND-01`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **85**. **TB19/selector384 is current runtime authority: 376 PASS / 8 RED, accepted 365/365; CB21's fragment-owner correction is runtime-proved and the later component-seed frontier is review-owned.** Exact next is `M3-CP4c-3-TB19-REV`. PR #8 remains open, draft, and unmerged.
