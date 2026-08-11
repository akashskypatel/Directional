# Directional Surface-Cell TODO

Last updated: 2026-08-11 UTC

## Purpose

This is the single durable task index for the cross-field-aligned surface-cell paving pipeline. It consolidates the former root `TODO` and `MILESTONE_G_TODO.md` task tracking and includes the pending work defined by `.agents/Directional/REORIENTATION_PLAN.md`.

Keep this file task-oriented. Exact current-turn instructions belong in `.agents/Directional/Future_Chat_Session_Handoff.md`; architecture ordering and invariants belong in `.agents/Directional/REORIENTATION_PLAN.md` and `DESIGN.md`; completed history belongs in `.agents/Directional/CHANGELOG.md`; exact runtime/build evidence belongs in the current retained report and regression trackers.

## Current focus

- [ ] **M1 single-authority cutover: Code + Build only.**
  - Authoritative plan: `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.
  - Replace the complete affected producer-to-consumer authority contracts in one turn: checked ID ingress; one topology-region product; complete isolation-seam certificates; one chart/support/route/periodic transport representation; exhaustive producer outcome; deletion of displaced fields/helpers/tests.
  - Preserve G0–G3 semantic invariants, truthful typed failures, determinism, strict direct disposition, and no fallback. Do not force prior raw numbering, hashes, row order, or known-incomplete product output.
- [x] **M1l — Phase-Front Cell Topology-Region Consumer: immutable accepted.**
  - Implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; Code + Build artifacts `9083262395 / 9083262833`; immutable runtime `31444022339 / 93634344918`, evidence/log artifacts `9083913766 / 9083913939`.
  - Producer **226**, M1l **6/6**, required-green **211/211**, full entering preservation/direct-product authority, unchanged known-red classes, and exact **56/56** postflight.
- [ ] After the final cutover Code + Build artifact is produced, run the separate immutable **Artifact-Only Test + Benchmark** turn. Discover the actual test inventory; require the new semantic contract groups, all entering semantic preservation gates, direct-product oracles, known-red classification, and a clean duplicate-authority source audit.
- [ ] After immutable M1 acceptance, close M1 and return the primary queue to **G4 production work**. Do not select another authority-migration letter slice.

Current baseline: T1 and M1a-M1l are immutable accepted. Product gate G4 remains active and independent of architecture-migration acceptance. Draft PR #8 remains open and unmerged.

## Product roadmap

- [x] **G0 — truthful authority baseline.**
- [x] **G1 — uniform phase-front plane.**
- [x] **G2 — cross-chart / close-sheet isolation.**
- [x] **G3 — periodic closure / holonomy.**
- [ ] **G4 — topology-distinct completion and singularities.**
  - [ ] `G4-B001` / `PR8-R034` / `G4-R007`: resolve direct-torus final `LocalSheetMismatch` and reach strict-valid torus **3/3**.
  - [ ] `G4-B002`: replace historical exact-torus `InvalidHardRailPairing` with one shared source-authoritative hard-rail schedule; architecture ownership is M3.
  - [ ] `G4-B003`: support nonzero periodic Z4 production behavior with the completed M1 transport contract, the required M4 relation certificate, and independent product acceptance.
  - [ ] `G4-B004`: establish a positive multi-isolation quotient witness with focused and representative certificate evidence.
  - [ ] Return to prescribed-sphere singularity completion only when the active G4 prerequisite boundary permits it; prove the direct cause before elevating historical completion/simplification failures.
- [ ] **G5 — adaptivity and hard features.**
- [ ] **G6 — Bunny/Vase production success and representative performance.**
- [ ] **G7 — hardening and default-on production readiness.**

## Architecture migration roadmap

- [x] **M0 — preserve immutable evidence.**
- [ ] **M1 — single-authority contract cutover.**
  - [x] M1a authority kernel.
  - [x] M1b first source/provenance consumer.
  - [x] M1c field-transition consumer.
  - [x] M1d phase-front route identity consumer.
  - [x] M1e segment route transport consumer.
  - [x] M1f vertex continuation route transport consumer.
  - [x] M1g periodic holonomy route transport consumer.
  - [x] M1h phase-front field-chart consumer.
  - [x] M1i phase-front cell source-scope consumer.
  - [x] M1j phase-front edge source-scope consumer.
  - [x] M1k phase-front edge topology-region consumer.
  - [x] M1l phase-front cell topology-region consumer.
  - [ ] Final cutover: replace all remaining affected producer/storage/verifier/materializer contracts together, remove the displaced forms, build/package, then validate separately.
- [ ] **M2 — remaining closed stage products and single-writer scope.** When active product work reaches a producer outside the M1 cutover, replace its complete outcome/snapshot contract in that production turn; do not run another representation-only campaign.
- [ ] **M3 — global conformity before regional production.** Compute one exact hard-rail breakpoint schedule and certificate before local regions commit cells; both sides consume the identical ordered schedule; remove post-hoc local pairing as authority.
- [ ] **M4 — certificate-carrying chart and quotient relations.** Publish explicit directed occurrence/transport/quotient relations with verifiable certificates; validators verify rather than reconstruct them; close remaining global-local relation debt behind periodic/G4 capability.
- [ ] **M5 — occurrence, embedding, and independent verification split.** Use explicit occurrences, exact source support, certificate-driven quotient materialization, and independently recomputed elementary source/output incidence.
- [ ] **M6 — module boundaries and operational hardening.** Split oversized ownership modules and harden diagnostics/resource/CI after their product contracts are correct; do not defer deletion required by an earlier contract replacement.

## Required target-stage corrections

These tasks mirror the target-stage corrections in `REORIENTATION_PLAN.md` and must remain represented here until their owning migration is complete.

| Stage | Task | Owning migration |
|---|---|---|
| A0 source authority | [ ] Establish one immutable source snapshot and tagged exact source support. | M1, M2, M5 |
| A1 field transport | [ ] Complete typed chart, grid-automorphism, transition, and route authority. | M1 |
| A2 topology plan | [ ] Establish one global topology plan with no downstream semantic reconstruction. | M2, M4 |
| A3 conformity plan | [ ] Establish one verified shared hard-rail schedule before regional commits. | M3 |
| A4 local construction | [ ] Make region authority immutable; aggregation may validate/remap representation only. | M2, M3 |
| A5 occurrence complex | [ ] Publish explicit corner occurrences and directed-side relations. | M4, M5 |
| A6 quotient/materialization | [ ] Use a verified relation registry with exact-once quotient consumption. | M4, M5 |
| A7 embedding | [ ] Bind source geometry through one shared exact-support kernel. | M5 |
| A8 verification | [ ] Independently verify certificates/incidence; verification must never repair topology. | M4, M5 |
| A9 diagnostics/export | [ ] Keep diagnostics derived/non-authoritative with explicit retention semantics. | M2, M6 |

## Testing roadmap

- [x] **T0 — independent audit and authority separation.**
- [x] **T1 — independent oracle/package foundation.**
- [ ] **T2 — complete direct corpus and semantic manifest.** Package and gate the complete direct semantic corpus with explicit topology, boundary, feature, field-variation, matching/holonomy, singularity, scale, and expected-outcome metadata.
- [ ] **T3 — property/metamorphic generation and shrinking.** Add deterministic generators, semantic metamorphic properties, seed replay, and shrinking/minimized reproducers.
- [ ] **T4 — sanitizer fuzzing and minimized replay.** Add coverage-guided sanitizer fuzz targets with valid/invalid seed corpora and committed minimized replay cases.
- [ ] **T5 — calibrated representative quality/corpus gates.** Gate independently measured topology, lineage, geometry, field/feature alignment, approximation, quality, determinism, and representative-corpus thresholds.
- [ ] **T6 — CI, resource, and oracle-adequacy hardening.** Enforce immutable discovery/package manifests, resource/work bounds, repeated-process/state-reset behavior, oracle sensitivity, and tiered CI/corpus execution.

## Deferred cross-cutting work

- [ ] Replace or recalibrate the nondeterministic sub-millisecond strict-validator 5% timing gate with a stable performance test; do not use threshold/retry workarounds to manufacture a pass.
- [ ] Resolve historical transition-quotient/completion failures only when they are proven relevant to the active product/architecture gate.
- [ ] Complete prescribed-sphere production acceptance after prerequisite G4 authority is ready.
- [ ] Complete fallback/recovery policy work after prerequisite direct-production gates; do not use recovery as a substitute for direct SurfaceCells correctness.
- [ ] Complete optimization/performance work after correctness, authority, and representative product gates are established.

## Authoritative references

- `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current turn and resume state.
- `.agents/Directional/REORIENTATION_PLAN.md` — architecture migration order, dependencies, invariants, and stop conditions.
- `.agents/Directional/DESIGN.md` — normative product/stage/domain architecture.
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md` — historical G4 remediation record and preserved product-boundary rationale.
- `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` — T0-T6 test redesign authority.
- `.agents/Directional/Regression_Root_Cause_Tracker.md` — stable regressions, recurring patterns, and blocker definitions.
- `tests/TESTING_STRATEGY.md` — normative testing policy.
- `.agents/Directional/CHANGELOG.md` — completed implementation and immutable-acceptance history.
