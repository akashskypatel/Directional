# Directional Surface-Cell TODO

Last updated: 2026-08-13 UTC

## Purpose

This is the single durable task index. Normative architecture belongs in `.agents/Directional/DESIGN.md`; migration ordering belongs in `REORIENTATION_PLAN.md`; exact runtime evidence belongs in retained reports; completed history belongs in `CHANGELOG.md`.

## Current focus — M1 R-A remains open

Immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

R-A artifact-only retry 3 tested exact source `555109796188b318c788ef5777f622705ee0aa94` and failed organically at **92 unique selected / 86 passed / 6 failed / 0 orchestration failures**. The bounded remediation from that evidence is now Code + Build complete.

### Completed Code + Build remediation

- [x] **R-A-TB3-CB-01 — correct the same-cardinality stale boundary-cache counterfactual.** `DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches` now explicitly sizes each counterfactual boundary cache to `boundaryVertices.size()` before injecting stale valid identities. The final assertions still require valid canonical lineage identities and no stale token, while rebuild count `0` is reserved for this genuine same-cardinality case. The separate missing-cardinality positive retains exact rebuild-count coverage.

- [x] **R-A-TB3-CB-02 — restore authoritative feature-rail projection for materialized phase-front output.** Source analysis showed the hard feature already reaches authoritative phase-front materialization; the downstream defect was rebuilding output feature sequences by geometric proximity even though exact `HardRail` quotient-equivalence provenance already names the materialized output relation. The pipeline now projects hard-feature output sequences from exact materializer lineage plus actual output mesh edges for phase-front products, while retaining geometric rail samples only for positional optimization. Malformed/missing exact rail relations remain fail-closed. Component aggregate rejection now preserves the inner producer stage/reason/validation issue and context; completion validation emits typed `MissingFeatureRail` when that is the failing invariant. Runtime proof of the four previously failing feature contracts remains pending retry 4.

- [x] **R-A-TB3-CB-03 — make the provenance counterfactual guaranteed semantic.** `FinalMergedOracleRejectsPostComponentProvenanceTamper` now preserves the valid barycentric certificate but changes the source-attached `SurfacePoint.position`, asserts that the certificate was actually changed, and requires final-oracle rejection with `SourcePositionMismatch`. Validator tolerances and coverage were not weakened.

- [x] **R-A-TB3-CB-04 — static closure and fresh immutable compile package.** Semantic implementation commit `199b06f429d8004a5b51c89f94ae33748f4ec38c`; exact clean compile source `aa16449577c48bac72257b7b9915e2b70dad3b82`. Regenerated R-A inventory is **19 affected paths / 60 probes / 270 matches / PASS**, with zero unexpected raw-projection, face-count, or pipeline `stitchIdentity` leaves and classifier self-test PASS. Compile run/job `31674780558 / 94366870676` completed the approved Release/static/Ninja/PRE_TEST targets **118/118**, build exit `0`. Result artifact `9171125667` SHA-256 `0190d60057001cc2fdcb56f64e436b7bf4670bb7a571c0ae0f3af8a296594a83`; log artifact `9171126075` SHA-256 `bc54bd79251bc935a171d04cd81994f211096d060904341169ce6e5777442380`. Package contains **26 files**, recursive self-excluding manifest **25/25**, exact source archive, and five empty source-status snapshots. `runtimeExecution=false`; no generated test, benchmark, discovery, `ctest`, CLI, fuzzer, help/version command, or custom input executed in this Code + Build turn.

- [x] **Independent pre-runtime review of R-A-TB3-CB-01 through CB-04** at implementation `199b06f429d8004a5b51c89f94ae33748f4ec38c` (byte-identical on source/test/audit paths to compile-pinned `aa16449577c48bac72257b7b9915e2b70dad3b82` and to head): **all four accepted at the Code + Build boundary; candidate ready for retry 4.** CB-01 verified to build a true same-cardinality stale cache (assign-then-inject); CB-02 verified fail-closed with unprojected rails propagating through `requiredFeatureRailCount` to `MissingFeatureRail` rather than being dropped; CB-03's `SourcePositionMismatch` verified reachable in the strict validator; every contract named for retry 4 exists in `tests/`. Inventory reproduced byte-for-byte at 19 / 60 / 270 / PASS.
- [x] **RA-TB3-F1 — corrected in that review.** Five durable documents cited semantic implementation commit `199b5aa85d02d8ef085161e3cdfe49f043e15ee1`, which does not exist in the repository. Corrected to the actual `199b06f429d8004a5b51c89f94ae33748f4ec38c`. The compile-pinned source was already correct, so no source, package, or artifact change was required.

### Next Test + Benchmark gate

- [ ] **R-A retry 4 — immutable artifact-only semantic gate** against exact compile package `9171125667 / 9171126075` from source `aa16449577c48bac72257b7b9915e2b70dad3b82`. Require exact artifact/source authority, outer digest verification, archive/package preflight, byte-identical regenerated **19 / 60 / 270 / PASS** static inventory, non-vacuous independent discovery, the complete R-A semantic selection, retained per-contract completion/stitch discrimination evidence, the CB-01/02/03 affected contracts, and immutable postflight. Zero-selected filters are orchestration failure. No rebuild, source/test/fixture mutation, permission/content repair, or package repair.
- [ ] **R-A closure / Step 4** only if retry 4 passes organically with every semantic contract and immutable check clean. Any semantic failure returns to another bounded Code + Build plan.

## After R-A

- [ ] Complete R-B through R-G and produce one fresh full M1 package.
- [ ] Run the retained full M1 artifact-only acceptance/characterization gate only against that fresh complete package.
- [ ] Mark M1 complete only after the full package passes its required acceptance matrix.

Deferred post-R-A hygiene:
- [ ] **RA-REV-23-F3:** dispatch the stitch-kind audit through an explicit probe classifier field rather than probe-name text; render the executed classifier identity and add a negative self-test.
- [ ] **RA-REV-22-F6:** remove non-falsifiable validation-used assertions or set validation-used fields where each gate actually executes.

## Product and architecture roadmap

- [x] **M0 — preserve evidence.**
- [ ] **M1 — single-authority contract cutover.** Active.
- [ ] **M2 — closed stage products and single writers.**
- [ ] **M3 — field-aligned curve network.** Build from typed singularity ports and branch-consistent non-crossing traces; independently establish the field-quadrangulability certificate.
- [ ] **M4 — global conformity plan.** Compute one shared positive rail schedule before regional production; infeasible subsets become typed degraded inputs rather than post-hoc local pairing.
- [ ] **M5 — certificate-carrying chart and quotient relations.** Retain selected relation paths, owners, and independently verifiable certificates, including periodic Z4 evidence where required.
- [ ] **M6 — occurrence, embedding, and independent verification.** Separate occurrence, quotient, embedding, and verifier products and establish injective region-interior baselines.
- [ ] **M7 — disposition and graded degradation.** Implement D0-D4 with strict fixtures requiring D0 and a bounded declared degraded producer.
- [ ] **M8 — module boundaries and operational hardening.**
- [ ] **Pipeline A — optional decomposed coordinate integration.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; strict-valid torus must reach 3/3.
- [ ] `G4-B002`: exact torus `InvalidHardRailPairing`; owned by revised M4.
- [ ] `G4-B003`: nonzero periodic Z4 production capability; owned by M5 after M1.
- [ ] `G4-B004`: positive multi-isolation quotient witness; owned by M5/M6.
- [ ] Bunny/Vase representative production and resource acceptance remain later product gates.

## Design/evidence backlog

- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Validate the M3 combinatorial-trace plus motorcycle/decomposition composition rather than assuming ingredient guarantees transfer automatically.
- [ ] Define the A1 field-quadrangulability certificate construction and independent tamper oracle.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**. PR #8 remains open, draft, and unmerged.
