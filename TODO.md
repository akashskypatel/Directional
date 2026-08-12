# Directional Surface-Cell TODO

Last updated: 2026-08-12 UTC

## Purpose

This is the single durable task index for the cross-field-aligned surface-cell quadrangulation pipeline. Current-turn instructions belong in .agents/Directional/Future_Chat_Session_Handoff.md; normative architecture belongs in DESIGN.md; migration ordering belongs in REORIENTATION_PLAN.md; completed history belongs in CHANGELOG.md; exact evidence belongs in retained reports and trackers.

## Current focus

- [ ] **Complete the M1 single-authority cutover.**
  - Review boundary: exact implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` at branch authority `fd96852d19defe70effd0dc6fbbaf07db8378e55`.
  - [x] Preserve the REV-14-through-REV-16 Code + Build checkpoint as partial compile evidence only: run/job `31602025466 / 94131563590`, artifacts `9143819164 / 9143819888`, Release/static/Ninja/PRE_TEST **118/118**, manifest **21/21**, no generated runtime.
  - [ ] R-A-REV-17: require source-owned collision certificates; remove exact-only/partial identity aliases; replace fabricated collision fixtures with owned positive and wrong-owner/unowned/wrong-face/stale-identity zero-publication negatives.
  - [ ] R-A-REV-18: publish one global aggregate source-authority product; validate every globally remapped lineage; rebuild/remove vertex identity caches and regenerate face cycles after remap.
  - [ ] R-A-REV-19: make aggregate semantic publication transactional; clear every context payload/flag on rejection; validate the actual final merged product; expand REV-16 and second-component-failure counterfactuals.
  - [ ] R-A-REV-20: delete or separately type/isolate affected optimizer/completion compatibility paths and raw mirrors; add missing-authority/alternate-validator contracts and a failing audit inventory.
  - [ ] Re-run the complete R-A closure inventory and mark R-A complete only when every gate is statically clean.
  - [ ] Complete R-B row-independent face/support/chart identity.
  - [ ] Complete R-C immutable published products and typed certificate construction.
  - [ ] Complete R-D checked ingress and delete compatibility/numeric read-back bridges.
  - [ ] Complete R-E typed semantic owners and lookups.
  - [ ] Complete R-F intent-complete compiled contracts.
  - [ ] Complete R-G expanded failing source audit.
- [ ] **Produce one fresh full R-A-through-R-G Code + Build package.**
  - Compile/package only; execute no generated binary, discovery, test, benchmark, ctest, CLI, fuzzer, or custom input.
  - Every historical/partial package recorded in `CHANGELOG.md` is ineligible for M1 acceptance.
- [ ] **Activate and run the retained immutable M1 Artifact-Only Test + Benchmark plan only after the full package exists.**
- [ ] **After M1 acceptance, resume Pipeline B product work under the revised M2-M8 architecture.** Pipeline A remains unscheduled.

Current immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`. Draft PR #8 remains open, draft, and unmerged.

## Product and architecture roadmap

- [x] **M0 — preserve evidence.**
- [ ] **M1 — single-authority contract cutover.** Current active gate.
- [ ] **M2 — closed stage products and single writers.**
- [ ] **M3 — field-aligned curve network.**
  - Build FieldAlignedCurveNetwork from the field-transport atlas with typed singularity ports, branch-consistent non-crossing traces, typed termination events, and disc-region proofs.
  - Prove the adapted combinatorial-tracing plus motorcycle-decomposition composition on supported inputs; do not treat the cited ingredients as a proof of the combined algorithm.
  - Construct and independently verify the A1 field-quadrangulability certificate.
- [ ] **M4 — global conformity plan.**
  - Compute one strictly positive shared rail schedule with a deterministic polynomial graph/flow algorithm before regional production.
  - Resolve G4-B002 exact-torus InvalidHardRailPairing without post-hoc local pairing.
  - Infeasible subsets become typed D3 inputs; they do not hard-fail the run.
- [ ] **M5 — certificate-carrying chart and quotient relations.**
  - Retain selected relation paths, explicit owners, and independently verifiable certificates.
  - Resolve nonzero periodic Z4 and positive multi-isolation quotient evidence where required by the product gate.
- [ ] **M6 — occurrence, embedding, and independent verification.**
  - Separate occurrence, quotient, embedding, and verifier products.
  - Establish a correct-by-construction injective region-interior baseline and calibrated geometry/field/quality evidence.
- [ ] **M7 — disposition and graded degradation.**
  - Implement verifier-assigned D0 Certified, D1 QualityRelaxed, D2 LocallyDegraded, D3 Partial, and D4 DiagnosticOnly.
  - Specify and prove the one declared degraded region producer; it must be bounded, non-recursive, pure-quad, manifold, and conform to the unmodified boundary plan.
  - Strict fixture gates require D0; D1-D3 never close them.
- [ ] **M8 — module boundaries and operational hardening.**
- [ ] **Pipeline A — optional decomposed coordinate integration.**
  - No implementation or scheduling until Pipeline B is Certified on the complete representative matrix with calibrated stable quality gates and evidence that integration would materially improve quality.

## Active product blockers

- [ ] G4-B001 / PR8-R034 / G4-R007: direct torus final LocalSheetMismatch; require strict-valid torus 3/3.
- [ ] G4-B002: exact torus InvalidHardRailPairing; owned by revised M4.
- [ ] G4-B003: nonzero periodic Z4 production capability; owned by M5 after M1.
- [ ] G4-B004: positive multi-isolation quotient witness; owned by M5/M6.
- [ ] Bunny/Vase representative production and resource acceptance remain later product gates.

## Design clarification and evidence backlog

- [ ] Correct DESIGN.md section 6.7 invariant 2: D1 is defined by missed quality gates and therefore requires a quality degradation record; QualityRelaxed cannot simultaneously mean all gates passed.
- [ ] Validate the M3 Ray-Sokolov-style trace plus motorcycle-graph composition rather than assuming its guarantees transfer automatically.
- [ ] Define the A1 quadrangulability certificate construction and independent tamper oracle.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] Calibrate D0/D1 geometry, field alignment, approximation, element-quality, determinism, work, and resource thresholds.

## Required target-stage corrections

| Stage | Open contract | Owning milestone |
|---|---|---|
| A0 SourceAuthoritySnapshot | one immutable exact-support/source-incidence authority | M1-M2 |
| A1 FieldTransportAtlas | typed charts/transport plus quadrangulability certificate | M1, M3 |
| A2a FieldAlignedCurveNetwork | non-crossing typed trace network and region proof | M3 |
| A2b GlobalTopologyPlan | one immutable global topology plan | M2-M3 |
| A3 GlobalConformityPlan | positive shared rail schedule and typed infeasible subset | M4 |
| A4 RegionCellComplex | strict and separately declared degraded producers | M2, M4, M7 |
| A5 OccurrenceComplex | explicit typed occurrences and relations | M5-M6 |
| A6 QuotientComplex/materialization | verified exact-once relation consumption | M5-M6 |
| A7 GeometryEmbedding | exact support, injectivity, and quality | M6, T5 |
| A8 Verification | independent verification and disposition assignment | M6-M7 |
| A9 Diagnostics/export | derived, non-authoritative, retained by policy | M8 |

## Testing roadmap

- [x] **T0 — independent audit and authority separation.**
- [x] **T1 — independent oracle/package foundation.**
- [ ] **T2 — complete direct corpus and semantic manifest.** Every strict representative case declares expected D0 or typed failure; no degraded tier counts as green.
- [ ] **T3 — property/metamorphic generation and shrinking.** Include curve-network topology, rail-flow, relation, disposition, degraded/omitted set, and permutation properties.
- [ ] **T4 — sanitizer fuzzing and minimized replay.**
- [ ] **T5 — calibrated representative quality and disposition gates.**
- [ ] **T6 — CI, resource, work-ledger, discovery, and oracle-adequacy hardening.**

## Authoritative references

- .agents/Directional/DESIGN.md
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md
- .agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md
- .agents/Directional/Future_Chat_Session_Handoff.md
- .agents/Directional/REORIENTATION_PLAN.md
- .agents/Directional/Regression_Root_Cause_Tracker.md
- .agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md
- tests/TESTING_STRATEGY.md
- .agents/Directional/CHANGELOG.md
