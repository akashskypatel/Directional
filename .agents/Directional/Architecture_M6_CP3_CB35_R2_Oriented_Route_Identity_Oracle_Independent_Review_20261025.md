# CB35-R2 oriented published-route oracle — independent review (2026-10-25)

**Turn:** `M6-CP3-CB35-R2-RP01-ORIENTED-ROUTE-IDENTITY-ORACLE-REV`. **Verdict: ACCEPTED for static test-oracle sufficiency only**; no executed tests, runtime evidence, representative production acceptance, or change to CP3 gates. The precise successor is `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE` with a frozen five-case manifest [Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv](Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv). A Test + Benchmark must still execute each case once in a fresh process from the verified immutable source package; do not build, relink, repair tests, or run the production fix in TB36.

## Independently reopened primary evidence

- CB35-R2 compiled semantic source `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`; current working source-snapshot SHA `e3c04795d049b1c87be1bacd8e3d4c6c53689b05` (control/STATUS/snapshot-trigger additions after compilation). GitHub commit diff confirms **only** `tests/SurfaceCellsPhase10Tests.cpp` +26/−0 changes in the semantic commit. No changed `src/`, `include/`, frozen selectors, fixture generator or build system at that semantic commit. The actual source/test bytes were reopened from a verified GitHub Actions source snapshot rather than inferred from a turn report.
- Snapshot run [40149096996](https://github.com/akashskypatel/Directional/actions/runs/40149096996), source archive artifact `12581911945`, outer SHA-256 `ef5488858fa59ffd251636821a54ea88e4c4652e3b93bfeb40f92d387723fba7`: inner archive and **5,862/5,862** listed file hashes checked. The snapshot is a later control-plane SHA, not a substitute for the immutable compiled source. The R2 compiled source archive and original source diff were separately inspected.
- Exact original compile run [40147720351](https://github.com/akashskypatel/Directional/actions/runs/40147720351), artifact `12580989509`, ZIP SHA-256 `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`; verified **28/28** packaged hashes, semantic SHA above, all eight mandated targets, `DIRECTIONAL_ENABLE_GMP=ON`, gmpxx/gmp linkage, preflight/build success and `runtimeExecution=false`. This review did **not** execute any Directional binary, CTest, or benchmark.

## Directed-route proof, independently recomputed

The committed cylinder fixture has 128 source triangles and 176 interior source edges. Reconstructing the ordered face-pair route from the fixture-authored source vertex/face indices, and looking up shared undirected source-edge keys and their compact IDs **from mesh adjacency**, gives exactly 32 directed crossings with 32 distinct source-edge keys, pairwise face adjacency, and closure back to the first face. The independent compact-edge ID sequence is:

```text
0, 1, 8, 77, 73, 72, 68, 67, 63, 62, 58, 57, 53, 52, 48, 47,
43, 42, 38, 37, 33, 32, 28, 27, 23, 22, 18, 17, 13, 12, 3, 2
```

The fixture supplies its own ordered expected source-edge topology rather than deriving it from the observed route. The new assertion reads **`CanonicalRoute::oriented_steps()`** on every index and requires (a) the fixture-authored source topology, (b) `Orientation::Forward` in the authored source traversal, (c) `TransitionStepKind::Interior`, and (d) an interior ID matching the independently resolved source edge's compact ID. A changed non-distinguished edge, changed kind, absent interior identity, wrong edge ID or reversed direction would fail the positive oracle. The negative explicitly requires the same matcher to reject `route.reversed()` even though canonical `route_topology(route)` equals `route_topology(route.reversed())`: this distinguishes directed traversal from canonical storage and discharges CB35-R1-REV **R-2**. `CanonicalRoute::reversed()` is implemented by flipping route orientation; `oriented_steps()` reverses the sequence and each step orientation. The distinct 32-step cycle makes the reversal falsifier nontrivial, independent of the product's canonical storage order.

The prior R1 assertions remain: 32 zero lattice translations, full composed `GridAutomorphism::identity()`, the two distinguished inverse ±1 quarter turns, remaining identity rotations and both nonzero monodromy negative witnesses. The test has no unconditional skip or recovery behavior that would turn a wrong directed route into PASS. These are static test-oracle checks, **not proof that a green result will occur** on the immutable pre-fix package.

## Scope, outcomes and predecessor obligations

- **R-2 discharged (test-authority only):** order, orientation, source-key, step-kind and compact edge identity are now checked against fixture data and reversal is a real negative discriminant.
- **R-1 remains discharged:** the previous whole-route canonical keys and full lattice-translation/automorphism assertions are retained.
- **RA-152 F1 and D1–D4 remain open:** the suspected dead A4 atlas step transport must first be measured by TB36; no production repair authorized in this turn. The older frozen selectors 191/192 remain unmodified and are included as comparison controls.
- **Other obligations carried unchanged:** RA-152.5, RA-146.2/.4, RA-45.4, 19 inherited candidate REDs, G4-B002, DIAG-RETAIN and the RP-01 census/exit. Do not credit their acceptance from this review.
- Stable events/categories/recurrences **66/17/49**, produced witness debt **1**. Accepted M6-CP2 **491/491**; TB32 unpromoted **481/500** (19 inherited RED), TB35 **11 PASS / 2 RED**, frozen selector **497**. No stable regression or new observed runtime outcome.

## Frozen successor TB36 and stop conditions

The five-case manifest above holds exactly three newly compiled witnesses and frozen selectors 191/192 (no modifications to their bodies). Each selected binary runs with a fresh process on the verified unmodified `12580989509` package. All cases have **unmeasured**, predicted-RED pre-fix outcomes; preserve actual log/first failure and stage without coercion. **STOP and route to Review rather than CB36** if any newly authored witness passes before the fix, the A3 factory rejects k=2, a witness fails before reaching the intended periodic A4 producer, manifests/source/selector drift, incorrect artifact identity, or other unexpected prerequisite invalidates the causal inference. Do not run CB36 production repair until independently reviewed TB36 evidence establishes the owner. Runtime remains a distinct boundary.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 original rows, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; no selector file modified. Selector497 frozen. |
| Decisive claims independently re-derived | 32 oriented source edge crossings, closed face adjacency, 32 unique source edges, compact IDs by independent mesh lookup; +26/−0 test-only source commit; 28/28 package hashes; 5,862/5,862 source hashes. |
| Non-vacuity checked | Reversal-negative uses `oriented_steps()`; `route_topology()` alone is reversal-invariant; matcher additionally checks kind, Forward direction and independent compact interior identity for every crossing. No runtime assertion outcome claimed. |
| Prior obligations discharged/carried | R-2 and R-1 discharged for static oracle; RA-152 F1/D1–D4, RA-152.5, RA-146.2/.4, RA-45.4, G4-B002, DIAG-RETAIN and pending REDs carried. |
| Stable accounting | 66/17/49, debt1; CP2 491/491 accepted; TB32 481/500 candidate, 19 RED; TB35 11/13; selector497 frozen; no promotion. |
| New candidates/obligations recorded | No new source or runtime candidate; R-2 resolved in tracker, existing F1 retained pending TB36. |
| ORIENTATION currency line | Updated 2026-10-25 to accepted static CB35-R2-REV and conditional TB36. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for current position/owner; §4 n/a, no witness executed; §8 n/a, prior canonical-versus-oriented failure pattern is discharged, not a new defect. |
| CHANGELOG | New review entry prepended. |
| ROADMAP | n/a: M6-CP3 remains open; no milestone/checkpoint state moved. |
| Selector manifest | n/a: 497 unchanged; separate five-case TB36 scope manifest only. |
| LESSONS | Existing independent, non-vacuous oracle lessons cited; no new reusable category established. |
| Consolidation under CLEAN_UP_POLICY | Inspected current prior R1/R2 family: immutable build/rejection records remain essential named evidence for TB36; no obsolete records safely deleted or folded. No generic deletion. |
| Successor frozen | `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE` — manifest and stop conditions above; subsequent TB36-REV requires TB36 evidence. |
| Turn boundary held | Static Review only, no product/test/fixture/selector/build source changes or runtime execution. |
| review_check.py boundary | Local `review_check.py boundary` executed: product/test/selector surface and all selector hashes PASS; helper exits 1 on its three historical durable-baseline checks plus missing `8b7299b43` ancestor because this verified source snapshot lacks the upstream Git object history. This is an explicit tooling limitation, **not a green boundary result**. |
| `STATUS` lifecycle maintained | Entry beacon set; final direct-write beacon after patch application/cleanup. |
| Pushed to origin, branch in sync | Verified Drive patch apply run `40152327171` succeeded and pushed exactly seven reviewed paths. GitHub compare confirms the committed change; no local remote-tracking Git check was available. |
