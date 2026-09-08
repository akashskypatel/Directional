# Directional Surface-Cell TODO

Last updated: 2026-09-08 UTC

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

## Current focus — `M3-CP4c-3-TB42-EXEC` (Test + Benchmark, artifact-only) — MEASURED CENSUS SUBJECT RUNTIME

`M3-CP4c-3-CB47` is **COMPLETE / COMPILE-GREEN / RUNTIME-FREE**.

- Exact built source: `5dacce6019ea34316c48743f3033d2bb5c26281a`.
- Compile run: `34262805758`; changed-owner job `102184784612`; package job `102186267545`.
- Immutable package107 artifact: `10070788592` / `directional-m3-cp4c3-cb47-result-34262805758`.
- `runtimeExecution=false`; GMP/GMPXX authoritative link; package checksum manifest `28/28` PASS.
- Selector409 remains byte-frozen at `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.
- CB47 changed only additive diagnostics. No Directional runtime, test or benchmark executed.

CB47 now publishes the population/domain evidence required by EC7.1–EC7.3: `unlabeledFaceCount`,
`frontierPartitionComponentCount`, `ownerConsistencyRowCount`, locator kind, locator guard survival,
`failure.sourceFace` membership, and failing-region source-face membership in `componentByFace`. The existing
partition, locator behavior, guard, frontier oracle, binding, `region_orbit`, orbit-key lookup and content anchor are
unchanged.

**Current semantic runtime authority remains promoted TB41:** selector **409**, **398 PASS / 11 RED**, accepted
**365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`, ownership **300 / 0 / 0**. Stable accounting
remains **47 events / 14 categories / 33 recurrences**, debt **5**; package count is now **107**.

### Exact next turn

Run **`M3-CP4c-3-TB42-EXEC`** against immutable package107 only. No rebuild or source/selector/fixture mutation.

- [ ] Verify exact source/artifact/package checksums and selector409 identity/hash.
- [ ] Execute all 409 identities once, one fresh process each, using the packaged artifact-only harness.
- [ ] Accepted ordinals 1–365 must remain **365/365 PASS**; 311/314/356/357 and 312/315/409 are hard stop gates.
- [ ] 390/393/406/407 are **expected to remain RED** and must publish every EC7 census population/domain field.
- [ ] 404/408 remain PASS; ownership remains **300 / 0 / 0**; existing owners for 366/367/368/369/370/374/398 remain untouched.
- [ ] Record exact identity-level evidence; aggregate 398/11 equality alone is not sufficient.
- [ ] Do not promote or plan a correction in EXEC. Exact successor is independent **`M3-CP4c-3-TB42-REV`**; stop the implementation loop at that boundary.

`M3-CP4c-3-DEFN-R8` remains pre-named and review-owned. If `frontierPartitionComponentCount == 0`, review decides
whether this census is legitimate at `RegionCertification`; EXEC must not widen the partition or weaken the oracle.

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
  CP4c-3 remains open. **`M3-CP4c-3-TB41` is promoted semantic runtime authority** on package106: **398 PASS / 11 RED**, accepted 365/365. **CB47 package107 is compile-green and runtime-free**; exact next is artifact-only `M3-CP4c-3-TB42-EXEC`, followed by independent `M3-CP4c-3-TB42-REV`.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 protected frontier evidence:** TB41 restored the accepted content-anchor oracles but 390/393/406/407 remain RED with `regionFrontierComponentCount=0`. CB47 is compile-green and adds the EC7 population/domain measurements without changing the oracle. TB42-EXEC owns artifact-only measurement; independent TB42-REV owns interpretation and `DEFN-R8`. 366/367 remain under their separate missing-fragment/orbit owner.
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

Current totals are **47 events / 14 categories / 33 recurrences** — CB47 introduced no runtime event — debt **5**, packages **107**. **`M3-CP4c-3-TB41` remains the promoted semantic runtime authority** at 398/11 with accepted **365/365**; package107 is compile-green and runtime-free. Exact next is artifact-only **`M3-CP4c-3-TB42-EXEC`**, followed by independent **`M3-CP4c-3-TB42-REV`**. PR #8 remains open, draft, and unmerged.
