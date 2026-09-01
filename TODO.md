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

## Current focus — `M3-CP4c-3-TB7` (artifact-only Test + Benchmark)

`M3-CP4c-3-CB9` is **COMPLETE at the Code + Build boundary**. Report:
`Architecture_M3_CP4c3_CB9_Code_Build_Report.md`. The semantic implementation source is
`e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`.

CB9 implemented the frozen Amendment-22/23 vertex-star authority: one exact arrival ray, intrinsic fan development,
`β = α + Θ/2`, unchanged exact half-open sector ownership, a certified filter plus reachable exact fallback,
published fan-length budget 16 with typed fail-closed states, and the full AX8 projection into `RemeshDiagnostics`.
The exact non-flat folded-cone witness has `Θ=3π/2`, demonstrates **two** owners under the obsolete candidate-local
mechanism versus **one** owner under the frozen authority, and includes exact continuation-boundary/radial-arrival
instances.

Selector **373** remains byte-frozen at
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.
AY5 therefore legitimately authorized the one-line selector **374** append:
`d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`.
Accepted semantic authority remains **365** until TB7 executes.

### Immutable package 76

- final compile run/job: `33535836292 / 99949862868` — success;
- exact semantic source: `e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`;
- raw compile artifact `9811669562`, Actions SHA-256
  `b5049004f2687eb48abfd40398c87606224cda1b7892bc22d7a2901d6dab16d2`;
- package run/job: `33536818075 / 99953090803` — success;
- package artifact `9811964367`, Actions SHA-256
  `5c7d27996aa43ef798aa8110df756fc34bbcb6d490356bdfaea249c3953cc949`;
- inner `package76.tar.gz` SHA-256
  `a940ee61c29a1c4e25040dad6353ad54152a0d6181da3450a8fe771dfc170f8e`;
- packaged source SHA-256
  `71b86aafae465b5dcb1763cc3e0250b4310b188d8f2d6e34ac8d7b8c6c74f6ea`;
- exactly 27 package-relative fixtures, six executable test/benchmark binaries, GMP/GMPXX linked;
- `runtimeExecution=false`, `packageRepair=false`.

No valid CB9 runtime/test/gate/benchmark execution occurred. Package 76 has **zero semantic gate credit** until TB7.

### Exact next turn

Run **`M3-CP4c-3-TB7`** from
`Architecture_M3_CP4c3_TB7_Artifact_Only_Test_Benchmark_Plan.md`.

TB7 must consume immutable package 76 without rebuilding or repairing it and execute selector **374 from ordinal 1**,
one identity per fresh process. Required closure is **374/374 PASS** plus immutable postflight. A valid semantic red
stops gate credit, requires the full zero-credit remainder pass through ordinal 374, then routes to independent
`REVIEW + PLAN`.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — implementation changed under Amendments 22/23; semantic disposition now owned by
  TB7's mechanical production witness.
- [ ] selector governance — selector 374 is compiled/package-frozen but not accepted; TB7 owns 374/374 validation.
- [ ] `M3-CP4c3-CB9-AUDIT-01` — `FieldTransportAtlas.cpp::build_boundary_pairing` computes `u/v` in floating point,
  re-expresses them as `FieldExactRational`, then uses the signs for boundary-flow carrier topology. Static
  consumer-re-expression finding; outside CB9's bounded vertex-star change.
- [ ] `M3-CP4c3-CB9-AUDIT-02` — generic `FieldExactRational::integer_sqrt_floor` has no published reusable bit-width
  input budget. CB9's vertex-star path remains bounded by finite source storage plus fan budget 16; generic exact
  utility hardening remains debt.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — empty-network product red; deferred, untouched by CB9.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere `NoCarrierMatch / SourceEdgeUnavailable`; deferred, AL4 binding.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — `saturationUsed=true`; deferred quality/coverage debt.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — partial; mechanical zero-unbound proof still owed.

`M3-CP4c3-TB6-CAND-01` is closed at the implementation/projection boundary by CB9 AY7; TB7 still must validate the
published contract at runtime. `M3-CP4c3-DEFN-R2-CAND-01` is closed for the vertex-star decision by the published
fan-length budget and typed `VertexStarExactBudgetExceeded`.

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**. Semantic M3
package count advances **73 → 74** with package 76. CP4c-2 remains **CLOSED / ACCEPTED at 365/365**; CP4c-3 remains
**OPEN**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; CB9 implemented and package-froze the Amendment-22/23 vertex-star authority as package 76 with selector 374. Exact next is artifact-only `M3-CP4c-3-TB7`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB6 first-red remains the last semantic evidence at ordinal 366, but CB9 now packages the exact Amendment-22/23 one-ray authority. TB7 must prove the mechanical production witness elects row 209 or 208, never row 41, and then carry selector 374 through the full gate. No candidate-order, tolerance, float-transport, `signedLift`-as-ray, or target-representative shortcut.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **74** after CB9/package 76. PR #8 remains open, draft, and unmerged.
