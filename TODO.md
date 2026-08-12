# Directional Surface-Cell TODO

Last updated: 2026-08-12 UTC

## Purpose

This is the single durable task index for the cross-field-aligned surface-cell quadrangulation pipeline. Current-turn instructions belong in .agents/Directional/Future_Chat_Session_Handoff.md; normative architecture belongs in DESIGN.md; migration ordering belongs in REORIENTATION_PLAN.md; completed history belongs in CHANGELOG.md; exact evidence belongs in retained reports and trackers.

## Current focus

- [ ] **Complete the M1 single-authority cutover.**
  - [x] Preserve M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` as immutable runtime authority and preserve exact compile-only REV-18-through-REV-21 package evidence in `CHANGELOG.md`.
  - [x] Independently review exact source `9d88d0e47cfc039e5399ebee334290b1eeae792b` at branch boundary `db100d15b166a2ac19bf2bb45c829856b43bb5a9`: **REV-21 coverage and REV-22-through-REV-24 accepted at the Code + Build boundary; overall R-A remains rejected/open**. Static inventory independently reproduced byte-for-byte during review.
  - [x] R-A-REV-21 contract completion: authority-only source-row permutation rejects and consistently permuted matrix-plus-authority accepts at Code + Build source `9d88d0e47cfc039e5399ebee334290b1eeae792b`; runtime execution remains pending.
  - [x] R-A-REV-22 Code + Build: final merged-product validation carries independent globally remapped boundary, feature, chart, output-face, hard-edge, and provenance authority with strict gates; boundary/feature tamper and strict-oracle positive contracts compile at `9d88d0e47cfc039e5399ebee334290b1eeae792b`.
  - [x] R-A-REV-23 Code + Build: aggregate stitch identity is rebuilt through the completion-owned canonical constructor, stale kind is ignored, the duplicate pipeline schema is absent, and generated-interior re-stitch contracts compile at `9d88d0e47cfc039e5399ebee334290b1eeae792b`.
  - [x] R-A-REV-24 Code + Build: direct source-authoritative validation requires non-null exact-matching `SourceTopologyRegions` before reporting authority use; null/foreign-authority negatives compile at `9d88d0e47cfc039e5399ebee334290b1eeae792b`.
  - [x] RA-REV-22-F1 Code + Build remediation at `032d4cbae9e2de2767579934682e78754180338d`: existing component authority-tamper tests are explicitly named as aggregation-seam guards; new post-remap final-oracle boundary and feature counterfactuals require `MissingBoundaryAuthority`/`MissingFeatureRail` and zero publication. Runtime execution remains pending.
  - [x] RA-REV-22-F2 Code + Build remediation at `032d4cbae9e2de2767579934682e78754180338d`: strict/provenance/boundary/feature usage publication is derived from `SourceAuthoritativeMeshValidationResult` observables; the hardcoded aggregate flags are absent.
  - [x] RA-REV-22-F3 Code + Build remediation at `032d4cbae9e2de2767579934682e78754180338d`: the typed final source-authority oracle result is published independently of component-report completeness, with an explicit `componentValidationReportsComplete` discriminator and compile-visible counterexample.
  - [x] RA-REV-23-F1 Code + Build remediation at `032d4cbae9e2de2767579934682e78754180338d`: the R-A inventory structurally forbids pipeline stitch-kind assignment and classifies every `stitchIdentity` assignment; only two completion-canonical leaves are allowed.
  - [x] Reproduce the complete retained R-A inventory through REV-24 after the findings: **19 affected paths, 42 probes, 186 probe matches, 22 allowed/0 unexpected raw-projection leaves, 2 allowed/0 unexpected face-count leaves, 2 allowed/0 unexpected pipeline `stitchIdentity` assignments, final static PASS**.
  - [x] Produce and verify a fresh focused compile-only package from `032d4cbae9e2de2767579934682e78754180338d`: run/job `31644502450 / 94274781412`, artifacts `9160266493 / 9160266848`, Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`. Prior package `9156381103 / 9156381524` is superseded as the runtime candidate.
  - [x] Independently re-review RA-REV-22-F1/F2/F3 and RA-REV-23-F1 at exact source `032d4cbae9e2de2767579934682e78754180338d`: **all four findings CLOSED at the Code + Build boundary**. Inventory reproduced byte-for-byte; exact-source claim verified through the reusable workflow's `source_sha` checkout assertion. Three follow-ups opened. Overall R-A remains rejected/open.

  R-A closeout sequence — **R-A remains one continuous checkpoint. Code + Build steps 1-2 are complete; the only live R-A action is the immutable artifact-only gate.**
  - [x] **Step 1 — Code + Build RA-REV-22-F4** at `64fa65a9379ad0a246393371516de3a3a7146243`: added present-but-wrong remapped boundary and feature authority negatives, a non-vacuous feature-bearing positive witness, full final-oracle issue-list diagnostics, and inventory probes pinning the new contracts.
  - [x] **Step 1 — Code + Build RA-REV-22-F5** at `64fa65a9379ad0a246393371516de3a3a7146243`: removed the residual non-falsifiable usage-option `EXPECT_TRUE` assertions while retaining published-vs-oracle equality checks and input-derived semantic observations.
  - [x] **Step 1 — Code + Build RA-REV-23-F2** at `64fa65a9379ad0a246393371516de3a3a7146243`: hardened the whole-statement stitch-kind classifier across all `src/pipeline` translation units, covers wrapped/fully-qualified/stale-copy/alias forms and member writes, and includes a four-case audit self-test.
  - [x] **Step 1 — regenerate the complete R-A inventory**: **19 paths, 48 probes, 203 matches, 22 allowed/0 unexpected raw-projection leaves, 2 allowed/0 unexpected face-count leaves, 2 allowed/0 unexpected pipeline `stitchIdentity` assignments, 4/4 stitch-kind self-tests, final static PASS**.
  - [x] **Step 2 — fresh compile package** from exact source `64fa65a9379ad0a246393371516de3a3a7146243`: run/job `31649372167 / 94290107577`, artifacts `9162042615 / 9162042971`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`, self-excluding manifest **25/25**, five empty source-status snapshots, `semanticContracts=compiled-not-executed`, `runtimeExecution=false`.
  - [ ] **Step 3 — single artifact-only Test + Benchmark** on exact package `9162042615 / 9162042971`, with no rebuild or source changes. Execute the new F4 boundary/feature content negatives and feature-bearing positive, retained F1-F3 final-oracle/publication contracts, renamed aggregation-seam guards, and retained REV-21-through-REV-24 / rollback / zero-publication contracts. A zero-selected filter is orchestration failure.
  - [ ] **Step 4 — mark R-A complete** only if step 3 passes organically and the packaged/regenerated static inventory remains clean. Any organic failure returns to Code + Build; R-A does not close on a partial pass.
  - [ ] Complete R-B through R-G and produce one fresh full M1 package.
- [ ] **Activate the retained full M1 Artifact-Only Test + Benchmark plan only for that fresh full package.**
- [ ] **After M1 acceptance, resume Pipeline B product work under the revised M2-M8 architecture.** Pipeline A remains unscheduled.

Current immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`. Historical regression totals remain **34 events / 14 categories / 20 recurrences**. Draft PR #8 remains open, draft, and unmerged.

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
