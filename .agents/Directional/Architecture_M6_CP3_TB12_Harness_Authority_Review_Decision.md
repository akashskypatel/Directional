# RA-86 — TB12 harness authority; CB12 reviewed; TB12 selection and CB13 constraints

**Turn:** `M6-CP3-TB12-R10-HARNESS-AUTHORITY-REV` (Review of a blocked TB). **Subjects:** CB12 source `b1b02d5be`, compile run `39097975393`, package `12125223513`; TB12 stopped `BLOCKED` before any dispatch (`e718548a3`). **S** = `src/geometry/SurfaceCellTracing.cpp`, **P** = `src/pipeline/RemeshPipeline.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`.

## RA-86.1 The block is a handoff defect; TB12 authors its own harness

- Every artifact-only TB has authored its own per-turn harness under `.agents/Directional/tools/` inside the TB turn: TB8 `a2bdf08cb`, TB9 `754ef65a8`, TB10 `3a5a726fc`, TB11 `763dee35a`. The executor requires a committed harness path and SHA-256 (`GitHub_Workflow_Policy.md:102`).
- The CB12 closeout copied CB12's own out-of-scope list ("harness") into TB12's. That was right for CB12 and wrong for TB12.
- Nothing was dispatched or measured, so this is neither a semantic RED nor an orchestration failure. Turn_Cadence rule 5 does not apply, no orchestration CB is needed, and the package is reused unchanged.
- **Authorization:** TB12 adds exactly one new file, `.agents/Directional/tools/m6_cp3_r10_open_rail_chain_provenance_harness.sh`, derived from the TB11 harness (`763dee35a`). Allowed deltas: source SHA, artifact, digest, the identity list of RA-86.4, the result tags, and two extra ledger columns: `role`, plus `first_failure` (the first raw-log line containing `predicate=` or `producer failed:`, cut at 600 characters). Existing harnesses, workflows, tests and product source stay untouched.

## RA-86.2 CB12 implemented to specification

- **Package verified independently:** ZIP SHA-256 `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6`; 28/28 manifest hashes; `source-commit` `b1b02d5be`; build exit 0; `runtimeExecution=false`; GMP. The packaged source equals HEAD for all seven semantic files, and all six RA-86.4 identities are present in `directional_surface_cell_producer_tests`.
- **Plumbing:** the types are at H:1559; the projection at P:9761-9769 emits every open rail's `sourceVertices`; the wiring runs P:12489 → consumer copy of options → `publish_phase_front_result` → `make` → accessor H:2000.
- **Validator** (S:8262, called at S:8521) mirrors the closed-chain block that precedes it, clause for clause, including the face-support scan.
- **Validator inputs on real data:** pipeline inputs satisfy it by construction, so it is a consistency check (RA-84.2):
  - `hardFeatureEdges` comes from the same `sourceVertices` (P:9702-9724);
  - production open curves are simple paths, because `extract_curves` breaks at every vertex of compatible degree ≠ 2;
  - the contact component is already matched to the region component at S:8533-8562.
- **Test expectations re-derived by hand:** edge 1–4 is on faces {0,3} and edge 4–7 on faces {4,7}. Every tamper is rejected, and both the 2-vertex chain and the reversed chain are accepted. Predicted PASS.
- **Gaps (non-blocking):**
  - the "rail id absent from contacts" branch is reached only through the size clause;
  - the face-support clause has no isolated tamper;
  - no test exercises the `make` rejection or the accessor, because no open-rail fixture reaches `Produced` (RP-01).

## RA-86.3 Correction: TB11's tests never reach the CB12 validator

TB11's two RED tests stop in the consumer (`open-rail-route-anchor`) before `publish_phase_front_result`, so `make` never runs. "TB11 locus unchanged" therefore says nothing about CB12 on real data.

The only tests that pass a real pipeline chain toward `make` build `nonconstant_hard_rail_fixture` (TQ, full `remesh_from_raw_cross_field`, rail 1–4–7). Two of them are frozen-selector identities `cp3entry:2` and `cp3entry:6`, which are RED (RP-01). TB12 runs them as non-gating diagnostics. Their failure text tells the two cases apart (TQ:426-444):
- `firstPredicate=` means a consumer-level rejection, before `make`;
- `PublishedProductRejected` without a predicate means `make` rejected.

## RA-86.4 TB12 selection, gate and predictions (binary `directional_surface_cell_producer_tests`)

| # | Identity | Role | Prediction |
|---|---|---|---|
| 1 | `SurfaceCellClosedProductContracts.OpenHardRailChainProvenanceIsSourceValidated` | gate | PASS |
| 2 | `SurfaceCellAuthorityContractCutover.OpenRailRouteAnchorTruthTable` | gate | PASS |
| 3 | `SurfaceCellAuthorityContractCutover.CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor` | diagnostic (RP-01; owner U3–U5) | RED; `first_failure` byte-identical to TB11's predicate |
| 4 | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` | diagnostic (RP-01; owner U3–U5) | as #3 |
| 5 | `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` | diagnostic (RP-01 `cp3entry:2`) | RED; fixture not `Produced`; `first_failure` carries `firstPredicate=` |
| 6 | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | diagnostic (RP-01 `cp3entry:6`) | as #5 |

- **TB11 predicate:** `predicate=open-rail-route-anchor;locus=9;rail=2;front=29,147;faceEnds=0,3|0,3;vertex=-1;step=-1;currentFace=0;expectedFace=3;routeLength=1;edge[0]=1,4:faces=0,3:chi=0`.
- **CB12 falsifier:** #5 or #6 reports `PublishedProductRejected` without `firstPredicate=`.
- **Disposition:** whatever the outcome, the successor is the Review `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV`. It adjudicates the predictions and issues the CB13 specification (RA-85.5: each CB follows a reviewed TB). Orchestration failures follow rule 5.

## RA-86.5 Constraints for U3 (CB13), fixed now

1. **The chain is mandatory.** An open-rail route certificate whose rail has a terminal contact is validated only against `hardRailOpenChains()`. A missing chain is rejected; there is no fallback to `open_rail_route_anchor_valid`. The empty-map exemption at S:8269 ends: a non-empty contact set requires an exact chain map.
2. **No vacuous negatives.** Direct-factory tests that set terminal contacts (`SurfaceCellsPhase10Tests.cpp` :2550, :6403-7466, :9006; TQ :1801-3112, :8821-9238) must supply valid chains, so that each negative test is rejected for its stated reason and not for a missing chain.
3. **The clone path carries the chain.** `PhaseFrontDraft` and `phase_front_draft()` (TQ:1775-1832) carry `hardRailOpenChains`. Their own comment names this hazard: dropped inputs become "unrelated early provenance failures".
4. **One rule in both checkers.** The interval rule replaces the anchor helper in both the factory and the consumer. The truth table's I–I row flips, and the helper is removed if it is left unused. The factory's stale I-branch comment ("opposite endpoint must already carry … terminal witness") is corrected.
