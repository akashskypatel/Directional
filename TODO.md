# Directional Surface-Cell TODO

Last updated: 2026-08-13 UTC

## Purpose

This is the single durable task index. Normative architecture belongs in `.agents/Directional/DESIGN.md`; migration ordering belongs in `REORIENTATION_PLAN.md`; exact runtime evidence belongs in retained reports; completed history belongs in `CHANGELOG.md`.

## Current focus — M1 R-A remains open

Immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

R-A artifact-only retry 3 tested exact compile source `555109796188b318c788ef5777f622705ee0aa94` from package `9167759672 / 9167759825`. Runtime run/job `31667380356 / 94344731465` passed immutable preflight, regenerated static inventory, independent discovery, and postflight, but failed organically: **92 unique contracts selected, 86 passed / 6 failed, orchestration failures 0**. R-A is not closed.

### Next Code + Build turn

- [ ] **R-A-TB3-CB-01 — correct the same-cardinality stale boundary-cache counterfactual.** `DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches` currently claims to preserve cache cardinality while only overwriting entries that already exist. Authoritative component materialization intentionally leaves this derived cache empty, so aggregate rebuild correctly counts the two missing-cardinality component patches. Explicitly size/populate the counterfactual cache to `boundaryVertices.size()` before injecting stale values, retain the valid/canonical anti-stale assertions, and require rebuild count `0` only for that genuinely same-cardinality case. Preserve the separate missing-cardinality positive with exact rebuild count equal to completed-patch count. Do not change the canonical rebuild merely to satisfy the fixture.

- [ ] **R-A-TB3-CB-02 — restore a production-valid feature-bearing completion path before aggregate/final-oracle checks.** Four retry-3 failures share the same earlier blocker: hard-feature component execution stops at `completion`, so feature-rail tamper and final-oracle feature contracts never reach their declared seams. Preserve/remap the exact component completion failure reason in typed diagnostics, establish whether the current internal hard-edge fixture is inside the supported R-A production domain, and then make the minimum justified correction. If supported, repair production completion without fabricating rails or weakening ownership/feature authority. If the exact fixture is provably unsupported, replace it only with a demonstrably production-feasible **non-empty internal hard feature** witness and retain a separate fail-closed unsupported-feature contract. The existing aggregate/final-oracle intents remain mandatory: changed component feature authority rejects at aggregation, missing/changed remapped feature authority rejects at the final oracle, and present non-empty remapped feature authority passes.

- [ ] **R-A-TB3-CB-03 — make the provenance counterfactual guaranteed semantic.** `FinalMergedOracleRejectsPostComponentProvenanceTamper` sets the first barycentric coordinate to `(1,0,0)`, which can be the already-correct source-vertex provenance; retry 3 therefore passed the final oracle. Replace this with a mutation that is proven different from the baseline and must violate the source-authoritative provenance contract, such as an invalid barycentric certificate or a position/provenance mismatch. Add a non-vacuous precondition proving the mutation changes the semantic certificate. Do not weaken the validator.

- [ ] **R-A-TB3-CB-04 — regenerate the complete R-A static inventory and produce one fresh immutable compile package.** Code + Build only. Compile the corrected contracts and affected approved targets without executing generated runtime. The following turn is artifact-only R-A retry 4.

### Next Test + Benchmark gate

- [ ] **R-A retry 4 — immutable artifact-only semantic gate** against the fresh package from `R-A-TB3-CB-04`. Require exact artifact/source authority, package preflight, byte-identical regenerated static inventory, non-vacuous independent discovery, complete R-A semantic selection, the retained per-contract completion/stitch discrimination evidence, and immutable postflight. Zero-selected filters are orchestration failure. No rebuild, source/test/fixture mutation, or package repair.
- [ ] **R-A closure / Step 4** only if retry 4 passes organically with all immutable checks clean. Any semantic failure returns to a bounded Code + Build plan.

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
