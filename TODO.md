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

## Current focus — `M3-CP4c-3-TB19-EXEC` (artifact-only Test + Benchmark)

`M3-CP4c-3-CB21` is **COMPLETE / COMPILE GREEN / RUNTIME-FREE**. Record:
`Architecture_M3_CP4c3_CB21_Code_Build_Report.md`.

CB21 final semantic source is **`b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`**. Authoritative compile-only run/job
**`33794307778 / 100778238374`** built all eight standard targets with GMP/GMPXX and `runtimeExecution=false`.
Immutable result artifact **`9908695433`** has ZIP SHA-256
`efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5`; packaged source archive SHA-256
`8b774500559e5cc9cd7afece39a68add2065a9812a0d15a40f39cf7f9aafd8e7`. Compile log artifact `9908695835` hashes
to `f334db6b4bf254c3e2eb84f0a65cb0f6a21fc56285b3677a037cb20881b8ad3f`.

CB21 disposition:

- [x] **BU0** — selector 383 byte-frozen; accepted 365 untouched; eight compile targets green with GMP/GMPXX.
- [x] **BU1** — sole semantic change `ownerCount != expected` → `ownerCount > expected`; high side remains fatal.
- [x] **BU2** — low-side deficit/shared-owner chords retained as evidence, never as a mismatch.
- [x] **BU3** — exact local fragment count and interior chord-crossing evidence retained, non-fatal.
- [x] **BU4** — bounded per-arc shared-orbit, per-trace terminal-slit, and global orbit census published.
- [x] **BU5** — production-path evidence witness and byte-identical high-side regression oracle compiled.
- [x] **BU6** — selector 384 appended exactly one identity; SHA-256
      `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`; first 383 exact prefix.
- [x] **BU7** — prohibited semantics/surfaces unchanged by diff audit.
- [x] **BU8** — safety proof reproduced against the actual diff: pure loop, strictly weaker predicate,
      observational new computations.
- [x] **BU9** — TB19 discriminators frozen in
      `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md`.

### Exact next turn

Run **`M3-CP4c-3-TB19-EXEC`** under
`Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md` using only immutable artifact `9908695433`.

- [ ] Verify the artifact ZIP, all 28 manifest entries, source commit, zero compile exits, GMP/GMPXX evidence, and
      clean packaged source state.
- [ ] Verify selector 384 has 384 identities, correct full hash, selector 383 exact prefix, and accepted 365 prefix.
- [ ] Record package byte+mode census, then execute all **384 identities in order, one fresh process each**.
- [ ] Confirm ordinals **1–365 remain 365/365 PASS**.
- [ ] Measure whether **366** and co-reachers **367/371/372** move past `TraceCutFaceFragmentCountMismatch`.
- [ ] Retain face `(0,1,102)` deficit/shared-chord evidence and the arc/trace/orbit census.
- [ ] Compare carried surfaces **368/369/370/374** against TB18 without forcing outcomes.
- [ ] Execute ordinal **384** exactly once and record its production-path evidence result.
- [ ] Recompute postflight byte+mode census and require exact equality; publish exact ledger/log hashes.
- [ ] Update `Regression_Root_Cause_Tracker.md` for every observed runtime regression/candidate before handoff.

Current immutable runtime authority is still **TB18 / selector 383**, **375 PASS / 8 RED**, accepted **365/365**.
CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness
debt **5**; semantic M3 package count **85**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB18/selector383 remains current runtime authority** at 375 PASS / 8 RED and accepted 365/365. CB21 semantic source `b00efbd5` is compile green in immutable package `9908695433`; selector 384 is frozen but unexecuted. Exact next: artifact-only **`M3-CP4c-3-TB19-EXEC`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — face-fragment orbit/count frontier:** TB18 measured the low-side shared-owner stop at `(0,1,102)` as actual/trace/expected `1/1/2`; TB18-REV proved exact global-owner equality unsound and authorized the one-sided relaxation. CB21 has implemented and compiled that correction at semantic source `b00efbd5` with retained local-fragment/shared-owner/orbit evidence. **TB19-EXEC must now prove the runtime frontier moves past `TraceCutFaceFragmentCountMismatch` without disturbing accepted 1–365.** Vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (deferred, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor, which throws unless all five downstream products are retained. Amendment 15's barrier-cycle and Euler-cut contracts have been unmeasured for a reason unrelated to either. Corrective remains test-only (an atlas-scoped fixture accessor, assertions byte-unchanged), but **TB19 first measures whether CB21 clears their shared fragment-owner stop and records each later frontier independently.** `M3-CP4c3-TB10-REV-CAND-01`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **85**. **TB18/selector383 remains current runtime authority: 375 PASS / 8 RED, accepted 365/365. CB21 source `b00efbd5` / package `9908695433` is compile green and runtime-unexecuted; selector 384 is frozen.** Exact next is artifact-only `M3-CP4c-3-TB19-EXEC`. PR #8 remains open, draft, and unmerged.
