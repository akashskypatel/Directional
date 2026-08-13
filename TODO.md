  - [x] RA-REV-22-F3 Code + Build remediation at `032d4cbae9e2de2767579934682e78754180338d`: the typed final source-authority oracle result is published independently of component-report completeness, with an explicit `componentValidationReportsComplete` discriminator and compile-visible counterexample.
  - [x] RA-REV-23-F1 Code + Build remediation at `032d4cbae9e2de2767579934682e78754180338d`: the R-A inventory structurally forbids pipeline stitch-kind assignment and classifies every `stitchIdentity` assignment; only two completion-canonical leaves are allowed.
  - [x] Reproduce the complete retained R-A inventory through REV-24 after the findings: **19 affected paths, 42 probes, 186 probe matches, 22 allowed/0 unexpected raw-projection leaves, 2 allowed/0 unexpected face-count leaves, 2 allowed/0 unexpected pipeline `stitchIdentity` assignments, final static PASS**.
  - [x] Produce and verify a fresh focused compile-only package from `032d4cbae9e2de2767579934682e78754180338d`: run/job `31644502450 / 94274781412`, artifacts `9160266493 / 9160266848`, Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`. Prior package `9156381103 / 9156381524` is superseded as the runtime candidate.
  - [x] Independently re-review RA-REV-22-F1/F2/F3 and RA-REV-23-F1 at exact source `032d4cbae9e2de2767579934682e78754180338d`: **all four findings CLOSED at the Code + Build boundary**. Inventory reproduced byte-for-byte; exact-source claim verified through the reusable workflow's `source_sha` checkout assertion. Three follow-ups opened. Overall R-A remains rejected/open.

  R-A closeout sequence — **artifact-only Step 3 attempt 1 executed against exact source `64fa65a9379ad0a246393371516de3a3a7146243` and FAILED organically. R-A remains open and returns to Code + Build; Step 4 is not satisfied.**
  - [x] **Step 1 — Code + Build RA-REV-22-F4/F5 and RA-REV-23-F2** at `64fa65a9379ad0a246393371516de3a3a7146243`, independently re-reviewed closed at the Code + Build boundary.
  - [x] **Step 1 — regenerate the complete R-A inventory**: **19 paths, 48 probes, 203 matches, 22 allowed/0 unexpected raw-projection leaves, 2 allowed/0 unexpected face-count leaves, 2 allowed/0 unexpected pipeline `stitchIdentity` assignments, 4/4 stitch-kind self-tests, final static PASS**.
  - [x] **Step 2 — fresh compile package** from exact source `64fa65a9379ad0a246393371516de3a3a7146243`: run/job `31649372167 / 94290107577`, artifacts `9162042615 / 9162042971`, Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.
  - [x] **Independent end-to-end R-A Code + Build review**: the contract set was accepted as structurally complete and the candidate was cleared to proceed to the runtime gate at `64fa65a9379ad0a246393371516de3a3a7146243`; deferred hygiene remains post-R-A backlog.
  - [ ] **Step 3 — artifact-only Test + Benchmark. Attempt 1 FAILED organically** on compile artifact `9162042615`: runtime run/job `31652227682 / 94298883415`, evidence artifacts `9163003523 / 9163003950`. Preflight/static inventory/postflight all PASS; no rebuild/source mutation; independent discovery selected every intended group; **87 unique contracts selected, 61 passed / 26 failed; zero orchestration failures**. See `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`.
  - [ ] **R-A-TB-CB-01 — aggregate typed source-authority transport.** Supply the exact authoritative `SourceTopologyRegions` owner to every SurfaceCells optimizer/final-validation route independently of `phaseFrontProduct`; preserve the strict exact-source binding and remove no fail-closed check. The runtime symptom is premature `optimization / MissingSourceAuthority` across aggregate contracts.
  - [ ] **R-A-TB-CB-02 — aggregate final-oracle fixture reachability.** After CB-01, make the boundary/feature content negatives, feature-bearing positive, missing-authority negatives, component-report counterfactual, and seam guards naturally reach the intended aggregate/final-oracle seam. If the feature witness still has no rail, repair the geometry/hard-feature fixture rather than synthesizing authority arrays.
  - [ ] **R-A-TB-CB-03 — completion authority runtime closure.** Replace pre-seam invalid completion fixtures with owner-valid source geometry/support/chart/provenance authority and diagnose the real `IncompatibleTypedStitchAuthority` failures in `CompatibleExactBoundaryKeyMergesWithTypedAuthorityCertificate` / `StitchingIsPatchOrderInvariant` without restoring aliases, fabricated IDs, or raw authority.
  - [ ] **R-A-TB-CB-04 — optimizer contract cleanup.** Replace `TriangleProjectionFailsClosedWhenRequiredSheetIsUnavailable` raw `SurfacePoint.sheet` mutation with a typed-authority counterexample; give `RailConstraintBuilderUsesOutputVertexSequencesForBoundaryAndFeatures` exact source vertices/faces alongside `sourceAuthority`.
  - [ ] **Step 2 retry — regenerate static inventory and compile one fresh exact-source package** after CB-01 through CB-04. Code + Build only; execute no generated binary/test/benchmark/discovery/CLI/fuzzer/custom input.
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