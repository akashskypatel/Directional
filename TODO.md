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

  R-A closeout sequence — **artifact-only Step 3 attempt 1 failed organically; R-A-TB-CB-00 through R-A-TB-CB-04 are now Code + Build complete / compile-valid at `92bf0ae2b10856162f175d02aeac318e126f9d22`. The mandatory next cadence is one immutable Step 3 retry; Step 4 remains unsatisfied until runtime passes organically.**
  - [x] **Step 1 — Code + Build RA-REV-22-F4/F5 and RA-REV-23-F2** at `64fa65a9379ad0a246393371516de3a3a7146243`, independently re-reviewed closed at the Code + Build boundary.
  - [x] **Step 1 — regenerate the complete R-A inventory**: **19 paths, 48 probes, 203 matches, 22 allowed/0 unexpected raw-projection leaves, 2 allowed/0 unexpected face-count leaves, 2 allowed/0 unexpected pipeline `stitchIdentity` assignments, 4/4 stitch-kind self-tests, final static PASS**.
  - [x] **Step 2 — fresh compile package** from exact source `64fa65a9379ad0a246393371516de3a3a7146243`: run/job `31649372167 / 94290107577`, artifacts `9162042615 / 9162042971`, Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.
  - [x] **Independent end-to-end R-A Code + Build review**: the contract set was accepted as structurally complete and the candidate was cleared to proceed to the runtime gate at `64fa65a9379ad0a246393371516de3a3a7146243`; deferred hygiene remains post-R-A backlog.
  - [ ] **Step 3 — artifact-only Test + Benchmark. Attempt 1 FAILED organically** on compile artifact `9162042615`: runtime run/job `31652227682 / 94298883415`, evidence artifacts `9163003523 / 9163003950`. Preflight/static inventory/postflight all PASS; no rebuild/source mutation; independent discovery selected every intended group; **87 unique contracts selected, 61 passed / 26 failed; zero orchestration failures**. See `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`.
  - [x] **Independently review the failed R-A artifact-only gate.** Turn boundary, preflight/postflight, discovery non-vacuity, and the 61/87 organic failure are accepted as authentic. **The Class A root cause is rejected as misidentified and R-A-TB-CB-01 is rewritten** (finding RA-TB-F1); Class C sequencing corrected (finding RA-TB-F2); Classes B and D accepted. Evidence in `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`, section "Independent review addendum — R-A artifact-only Step 3 failure analysis".
  - [x] **R-A-TB-CB-00 — mechanism inspection completed.** Runtime artifact `9163003950` does not serialize or print `surfaceCellTopologyRegionCount`, so the requested value could not be truthfully read. Exact-source inspection nevertheless confirms the independently reviewed mechanism: `phaseFrontProduct` points into local `traceNetwork`, the authoritative owner is copied before the move, and five post-move reads dereference the moved-from object. No count was fabricated.
  - [x] **R-A-TB-CB-01 — post-move source-authority lifetime fixed at Code + Build boundary.** After moving `traceNetwork`, the stale `phaseFrontProduct` pointer is nulled and every later optimizer/final-validation consumer uses `result.surfaceCellContext.sourceTopologyRegions` through a retained pointer. Strict `source_optimization_has_complete_authority` and exact-source fail-closed checks remain unchanged. Added `PostMoveAggregateOptimizerUsesRetainedSourceAuthority`, which requires published authority to `matches_source_faces` the actual source matrices.
  - [x] **R-A-TB-CB-02 — aggregate final-oracle reachability addressed at Code + Build boundary.** Source reasoning after CB-01 found no justification to synthesize boundary/feature authority or weaken seam guards; the existing F1/F3/F4 counterfactual fixtures are retained for the runtime retry, now with the premature empty-owner path removed. Their semantic reachability remains runtime-pending by design.
  - [x] **R-A-TB-CB-03 — completion authority closure remediated at Code + Build boundary.** Completion now distinguishes source-face-only support resolution from source-geometry projection, generated-interior fixtures supply real source geometry, and published chart authority is the owner-valid chart closure over incident support faces within the selected region/sheet rather than one patch-local chart. Collision coverage now constructs real overlapping/non-identical owner-valid chart sets. No aliases, fabricated IDs, raw mirrors, or pre-intersection identities were restored.
  - [x] **R-A-TB-CB-04 — optimizer contracts corrected at Code + Build boundary.** Replaced the raw `SurfacePoint.sheet` negative with `TriangleProjectionFailsClosedWhenTypedSourceAuthorityDoesNotMatchSourceFaces`, which supplies a typed authority bound to a different face ordering and requires `MissingSourceAuthority`; pinned the replacement in the R-A inventory. The rail-builder fixture now supplies exact source vertices/faces alongside `sourceAuthority`.
  - [x] **Step 2 retry — regenerated static inventory and fresh exact-source compile package.** Source `92bf0ae2b10856162f175d02aeac318e126f9d22`; inventory **19 paths / 50 probes / 206 matches**, raw projection **22 allowed / 0 unexpected**, face-count **2 / 0**, pipeline `stitchIdentity` assignments **2 / 0**, stitch-kind self-test **4/4**, final static **PASS**. Compile run/job `31655755100 / 94309741656` completed Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; result `9164349848` SHA-256 `499bb4b4b6bd33408284bb3985bb04f0bda7312834b462b806965f7799e45870`, log `9164350085` SHA-256 `a7fa938991c13d6a79cf4fdab85669d3e37e6eb625dc2541d8c8fdea2388938f`; 26 regular files, self-excluding manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.
  - [ ] **Step 3 retry — single artifact-only R-A gate** against that fresh package with no rebuild or source changes. A zero-selected filter is orchestration failure.
  - [ ] **Step 4 — mark R-A complete** only if the retry passes organically and immutable pre/postflight plus the complete regenerated static inventory are clean. Any organic failure returns to Code + Build.
  - [ ] Complete R-B through R-G and produce one fresh full M1 package.
  Deferred audit/test hygiene — **post-R-A backlog; must not defer the Test + Benchmark gate**:
  - [ ] RA-REV-23-F3: the R-A audit dispatches the stitch-kind structural classifier by probe-*name* string, so `R_A_Closure_Inventory_Report.md` prints a `Pattern:` that never executed and a probe rename silently reverts to a weaker line regex. Dispatch on an explicit `Probe` field, render the executed classifier's identity, and add at least one negative self-test case so the audit proves discrimination rather than only detection.
  - [ ] RA-REV-22-F6: `EXPECT_TRUE(oracle.provenanceValidationUsed)` and `EXPECT_TRUE(oracle.sourceAuthorityUsed)` remain non-falsifiable given publication. Drop them, or set `strictValidationUsed` / `provenanceValidationUsed` / `featureRailAuthorityUsed` where each gate actually executes to close the class permanently.
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
