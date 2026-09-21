# M5-CP3-CB2 Code + Build Report

- Phase: `M5-CP3-CB2`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Starting implementation authority: reviewed `M5-CP3-CB2` plan on the post-CB1-review branch; source inspection used exact snapshots and the implementation patch was based on `c8009a978fb414e0281799c9e09fb30f8701ac8e` (control-only commits do not change the semantic base)
- Built evidence commit: `fc2aa5fa68cac890051614c2104979aef4a60d21`
- Handoff/closeout commit: documentation-only and recorded by branch history after this report is applied
- Remote synchronization verified: yes; compile package records exact source `fc2aa5fa68cac890051614c2104979aef4a60d21` and clean source-status receipts

## Implemented

- Promoted only already-valid same-region A3 paired cut copies with reciprocal exact `sharedBoundaryInterval` provenance and distinct exact `boundaryOccurrence` values from operative `HardRail` to owned `PeriodicCut` pairs.
- Derived the periodic generator carrier from accepted `GlobalTopologyArc::sourcePath`/source-transition authority, used the produced paired-edge route as cut carrier, derived one exact `GridAutomorphism` valid for both reciprocal endpoint pairs, published canonical `SurfacePeriodicHolonomy` ownership, and emitted `PeriodicFrontMerge`.
- Preserved cross-region HardRail behavior and the materializer's existing same-region HardRail rejection.
- Extended checked phase-front product validation so exact A3 shared-boundary provenance is legal on `HardRail` or `PeriodicCut` without making it mandatory on generic periodic cuts; existing CP2 owner/route/action checks remain in place.
- Strengthened selector430 row408 only at the obsolete final-kind assertion: the exact 18-source-edge torus subject, accepted A0-A3/conformity authority, receipt/digests and `InvalidHardRailPairing` check remain, while the final assertion now requires a complete reciprocal promoted `PeriodicCut` pair with canonical owner and exact A3 occurrence provenance.
- Added the six frozen `M5CP3.Produced...` production identities from the reviewed plan with independent carrier/content and production-precondition checks.
- Repaired one compile-only GoogleTest macro parsing issue by parenthesizing the aggregate `LatticeTranslation{0, 0}` argument; no semantic expectation changed.

## Engineering-Guideline Review

- Material assumptions surfaced: the accepted A2b/A3 source-path and atlas authority had to be sufficient to derive an independent generator carrier and one exact action for both pair endpoints; the implementation fails closed when they are not.
- Simplest sufficient approach chosen: reuse the existing A4 exact-pairing seam, source-transition/atlas authority, canonical periodic factory/insertion path and existing relation validators; no parallel relation representation or fallback path was introduced.
- Why no smaller approach satisfies the contract: changing only final edge kind would lose independent canonical relation ownership/action authority, while retaining same-region HardRail is rejected by the frozen materializer contract.
- Unrelated refactors/style drift avoided: yes.
- Every changed semantic line traces to the reviewed promotion, row408 evolution, six produced witnesses, or the one-line compile repair: yes.

## Files Changed

Semantic source/test changes at evidence commit `fc2aa5fa...` relative to the reviewed pre-CB2 semantic authority are confined to:

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

The final compile repair changes only `tests/SurfaceCellTransitionQuotientTests.cpp` by parenthesizing one aggregate initializer passed to `EXPECT_NE`.

## Domain Invariants

- Same-region promotion remains conjunctive: reciprocal exact A3 intervals, distinct exact occurrences, reverse routes, matching families and opposing advance signs.
- Cross-region pairs remain `HardRail` and continue to use existing hard-rail semantics.
- `sharedBoundaryInterval` remains provenance; `periodicRelation` remains the sole quotient owner for `PeriodicCut`.
- Relation identity remains content-derived from canonical generator/cut carriers; action/transport is relation value, not identity.
- The full action must satisfy both reciprocal endpoint pairs before publication.
- The materializer same-region HardRail rejection is unchanged.
- Selector430 is byte-identical: 430 LF rows, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`.
- First427 remains byte-identical with SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
- No production-debt credit is claimed in Code + Build.

## Accepted-Row Assertion Audit

Accepted selector430 row408 changed only at its obsolete final-representation assertion.

| Removed/relocated row408 assertion | Current coverage |
|---|---|
| Final-row loop restricted observation to `HardRail` and `ASSERT_TRUE(edge.sharedBoundaryInterval.has_value())` for each observed final hard rail | Row408 now requires every observed exact A3 interval on the one-region torus to be on `PeriodicCut`, with a canonical owner, reciprocal opposite, exact span/ordinal/orientation/occurrence reciprocity and reverse route. Cross-region HardRail interval ownership remains accepted-selector coverage in rows 404-407. |
| `EXPECT_GT(exactSharedIntervals, 0U)` | Strengthened in row408 to `promotedSharedIntervalEdges >= 2` and `promotedSharedIntervalPairs >= 1`, so one complete reciprocal pair is mandatory. |

Accepted selector rows retaining the cross-region/general A3 HardRail semantics are:

- row404 `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt` — production hard-rail pairs retain exact shared-boundary interval provenance;
- row405 `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` — fixed-plan perturbation preserves interval authority;
- row406 `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback` — missing/tampered exact interval identity rejects fail-closed;
- row407 `SurfaceCellAuthorityContractCutover.A3SharedBoundaryCutoverPreservesA4LocalFamilyAndAdvanceSign` — reciprocal interval/family/advance-sign semantics remain protected.

No assertion outside the row408 final-kind locus was removed from an accepted selector430 identity by CB2.

## Six Produced Identities

Exactly these compiled identities exist, with no aliases:

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

They are compile-proved only in this turn. Their production preconditions and semantic outcomes remain uncredited until artifact-only runtime and independent Review.

## Build

- Workflow run/job: `35542532109 / 106162702255`
- Exact compiled source: `fc2aa5fa68cac890051614c2104979aef4a60d21`
- Targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`
- Configure: Release, static, PRE_TEST discovery mode, `DIRECTIONAL_ENABLE_GMP=ON`
- Exact arithmetic evidence: GMP found; authoritative link contains both `libgmpxx.so` and `libgmp.so`
- Preflight target/result: `directional_core`, exit `0`
- Full compile/link result: exit `0`
- Source status: clean before configure, after configure/build and final package capture
- Command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`
- Candidate result artifact: `10615252806`, provider/ZIP SHA-256 `1e32fa2b55f84b9097b0d617bcfc1b5f7ad1ab7e5ffc2bdb8e0cde8ea715bf20`
- Diagnostic log artifact: `10614394740`, provider SHA-256 `91e768f1f0ecd36f00dd75ce3c5378ed012d1b4a3a521d1059528118eeedffde`
- Root package manifest: 28/28 verified; `SHA256SUMS` SHA-256 `322b04df9767a80bc246b4b0a03886cc6abb118b8e13147ed8fa1126de74a7c1`
- Packaged source archive: `source-fc2aa5fa68cac890051614c2104979aef4a60d21.tar.gz`, SHA-256 `6fe16061079b01079bc53006f102575a5452a950b663807b4f278949ff3ef967`
- Packaged owner executables retain mode `0755`.
- Tests or benchmarks executed: none.

### Compile corrective loop

The first compile attempt `35541328083 / 106159452135` reached the approved compile boundary and failed in `SurfaceCellTransitionQuotientTests.cpp` because GoogleTest's two-argument `EXPECT_NE` macro parsed the comma in `LatticeTranslation{0, 0}` as a third macro argument. The repair was one syntactic parenthesis pair around that aggregate expression. The exact fix was independently patch-checked, applied through the standard Google Drive patch transport, and the fresh mandatory compile above passed. No runtime evidence comes from either attempt.

## Static Acceptance Gate

- semantic change confined to the reviewed production seam/header contract and focused test definitions: PASS;
- row408 exact 18-source-edge production subject retained: PASS;
- same-region/distinct-occurrence promotion only; cross-region HardRail retained: PASS by source inspection;
- canonical content-derived relation identity and exact action derivation retained: PASS by source inspection;
- CP2 relation checks preserved except orthogonal A3 interval allowance on `PeriodicCut`: PASS by source inspection;
- materializer same-region HardRail rejection unchanged: PASS;
- six exact produced names exist with independent static checks: PASS;
- selector430/first427 frozen hashes: PASS;
- mandatory GMP compile/package, clean source and self-verifying manifest: PASS;
- Directional runtime executed in CB2: none.

## Generalization Review

- Why this is not fixture-specific: production promotion is gated entirely by existing exact semantic authority (region, reciprocal interval/occurrence, canonical routes, family/sign and source-path/atlas transport), not torus names, edge ordinals or fixture IDs.
- Valid input classes affected: already-valid A4 paired hard-feature cut copies whose exact A3 provenance identifies two distinct same-region boundary occurrences; cross-region hard-feature pairs are unchanged.
- Regression risks considered: accidental HardRail weakening, ordinal-based relation identity, action inconsistency between reciprocal endpoints, loss of A3 provenance, CP2 validator weakening, selector-row assertion loss, and generic PeriodicCut overconstraint.

## Known Risks / Process Notes

- Runtime behavior is intentionally unexecuted and uncredited. In particular `>=2` produced relations/owned edges, genuine nonzero-Z4 rotation+translation, materialization, tamper rejection and unused-relation decision neutrality must be proved by `M5-CP3-TB1-EXEC` and adjudicated by Review.
- An early attempt began repository document/source reads before the mandatory snapshot-mode pre-read gate was fully established. Inspection was switched to exact snapshot mode and subsequent static work used verified snapshots/artifacts. This process miss does not alter source/build evidence and remains recorded rather than normalized away.
- The turn-local tool-call ledger became incomplete across context compaction; per policy it is reported as partial/unknown rather than reconstructed by additional calls or guessed.

## Mandatory Test + Benchmark Plan

- Historical TB1 plan reference: folded after its blocked execution; resolver `M5_Consolidated_Record.md` §5. Corrected sole current runtime plan is `Architecture_M5_CP3_TB1_R1_Artifact_Only_Test_Benchmark_Plan.md`.
- Evidence commit/artifact under test: `fc2aa5fa68cac890051614c2104979aef4a60d21` / `10615252806`
- Focused validation: exact nine frozen reviewed mechanism identities, then exact six produced identities, each as a fresh exact-filter process
- Related regression validation: complete selector430, all 430 rows in exact file order and fresh exact-filter processes
- Integration/full validation: selector430 is the complete pre-publication accepted regression gate for this turn
- Benchmarks: exactly 0
- Acceptance criteria: focused 15/15 + selector430 430/430, exact-one selection, zero skips, immutable package/source/execution-view postflight, no configure/compile/relink/repair/mutation
- Stop/blocker conditions: source/artifact/manifest/mode/selector/routing mismatch or any orchestration action that would require package repair stops before semantic runtime; semantic RED is preserved and routes to Review without in-place repair

## Next Turn

Type: Test + Benchmark, exact state `M5-CP3-TB1-EXEC`.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `fc2aa5fa68cac890051614c2104979aef4a60d21`
- Handoff commit: documentation-only closeout commit after this report
- Test plan linked: yes
- Updated or verified unchanged: TODO, M5 consolidated record, changelog and live handoff updated; frozen definitions/selector remain unchanged
- Agent entry-point links verified: successor load plan names `TB-EXEC` plus the exact plan/report/frozen sections
- New lesson recorded: no new general engineering lesson; compile macro failure is a local syntax issue and the earlier read-mode miss is recorded here
