# M6-CP3-CB1-ENTRY-R3 — Checked-factory HardRail topology and frozen-gate coverage audit

**Scope:** same unfinished R3 Code + Build turn. Static analysis only. This is NOT an independent Review verdict, a test result, or authorization to modify the 497-case gate.

## Exact source/build evidence

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8.
- Latest verified semantic source: `2ae6f5d1ba4e7657a5089fb52c09812a495dfe47`. Prior apply run `37861219049` succeeded; apply result `11585528786` and log `11585583689`; staged Google Drive patch `1IGrWWs8Au1DUlNYNyBjDFJt-W8UkiRip` was owner-deleted after apply.
- Compile dispatcher event: `af7a067d2062f998b97faeb93258b93610aab836`. Compile run: `37861343725`; compile job `113597653698` succeeded; Test + Benchmark skipped. Result/package artifact `11586413529`, SHA-256 `871bbc76accefb3ca840f5a23fe77883d71928f4dac8b88b7658a39fe7bb96ed`; log artifact `11586303900`, SHA-256 `8aa5d4631aac22ac0265a50a4626879d0f175d91203117cfdb123e327361ea3f`.
- **Package verification:** 28/28 `SHA256SUMS` matches independently verified; `metadata/source-commit.txt` matches the semantic SHA; both preflight and build exit 0; all eight prescribed targets present. Generated link command includes `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`. All five source-status receipts empty. `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.
- Source archive within the compile package: `source/source-2ae6f5d1ba4e7657a5089fb52c09812a495dfe47.tar.gz`, SHA-256 `78585e403c206008988354cdd230847ce2b8616101725eace53eefec044c3f52`. This exact archive supplied the inspection source. No generated Directional executable, test, or benchmark was run.

## Checked-factory guard and compiled regression

`src/geometry/SurfaceCellTracing.cpp`, `SurfacePhaseFrontProduct::make` (approximately lines 7990–8053) now counts actual source-triangle incidences for every **published** `hardRailFieldTransitions` edge from the complete `SourceTopologyRegions` region-face membership. It rejects any published hard-rail cross-face transition unless its source edge has **exactly two** incident triangles, and checks both distinct named faces against that edge and the source topology rows. This closes the specific two-named-faces-can-hide-a-third-face defect without adding independent nonrail A3 provenance. The separate A4 prepublication guard also rejects overfull hard-feature source edges before publication. No production trust-contract or selector changes were made in this attempt.

The focused unit `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` is compiled into `directional_surface_cell_producer_tests` (`tests/SurfaceCellTransitionQuotientTests.cpp` around line 1740; owner declared in `cmake/DirectionalTests.cmake`):
- 1 incident source face, **no** published cross-face transition: expects `EmptyCells` (deliberate post-authority gate control).
- 2 incident faces, a published cross-face transition: expects `EmptyCells`.
- 3 incident faces, only two named by published transition: expects `InvalidSourceAuthority`.
- Repeats the cases with source-face row order reversed.
- `SourceTopologyRegions::make` validates the row/member bijection and does **not** itself impose a two-manifold source-edge condition. The third-face fixture is therefore a relevant checked-factory preflight negative, rather than a guaranteed invalid setup.
- **This test has been COMPILED ONLY.** Runtime expectations and exact selection have NOT been verified.

## Coverage gate finding — explicit follow-up required

The frozen R3 Test + Benchmark harness `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` selects exactly **497** process identities: focused30 (30), focused12 (12), selector449 (449), and six hardcoded CP3 entries. The new factory test identity occurs **only** in its test source, **not** in any of those four selection authorities. The four selection files still match their prescribed hashes and line counts:

| Gate | Count | Frozen SHA-256 |
|---|---:|---|
| focused30 | 30 | `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6` |
| focused12 | 12 | `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed` |
| selector449 | 449 | `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` |
| routing449 | 449 | `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` |

**Therefore:** even a future 497/497 result does NOT prove the newly compiled factory regression has been executed. Independently authorize a **separate, artifact-only focused regression execution** of the exact test identity and its original/row-permuted cases, or explicitly designate it as compile-only defensive coverage pending a later review-approved test gate. Do **not** silently append a 498th process, rewrite the frozen selectors, present this test as already passing, or execute it during the current CB. Preserve immutable package/modes and source-to-binary identity when future TB is permitted.

**Additional scope decision for Review, not a current bug verdict:** the checked factory currently counts source incidences only for edges with published hard-rail transitions, whereas A4 rejects overfull edges from its entire hard-feature set before it publishes anything. If factory validation of *unpublished* hard-feature edges is independently required, specify that contract before broadening the factory or altering one-face boundary behavior.

## Other unresolved R3 gates

The independent factory nonrail A3 attestation choice and CB/TB witness-evidence sequencing remain pending in `.agents/Directional/Architecture_M6_CP3_R3_A3_Trust_CB_TB_Gate_Review_Request.md`. Genuine D1/D2/D3/D5, A6/A7, and odd-τ produced witnesses; 39 historical R2 first-failure investigations (25 direct A4 + 12 Phase10 + 2 terminal) and recovery of 47 prior accepted-green cases are **not** runtime verified. Frozen 497 and regression-ledger authority remain unchanged. No R3 completion or successor is authorized.