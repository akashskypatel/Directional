# M6-CP3-CB1-ENTRY-R3 — frozen 497 versus compiled supplemental tests

**Scope:** Source/static inspection in the same unfinished R3 Code + Build turn. **Not** an independent design verdict, runtime execution, or a successor authorization.

## Exact source and independently verified compile evidence

- Latest semantic source: `32994a92dcc6492230ee768c476e65d31a38f59e`, not the superseded `2ae6f5d1ba4e7657a5089fb52c09812a495dfe47`.
- Latest compile workflow: `37878691159`; package artifact `11593975930`; artifact SHA256 `ee955a771dc9f0c254077e2e9dbd199b2f3591242496c5c7556f4e8fb6f498af`.
- Independent package verification: 28/28 SHA256SUMS entries match, eight requested targets present, source commit matches, preflight/build exits 0, `libgmpxx.so` + `libgmp.so` link evidence, five clean source receipts, `runtimeExecution=false`.
- Historical pending compile `37861343725` on `2ae6f5d1…` also passed 28/28, but was superseded by later source changes; do not trigger a duplicate build based on the older package.

## Confirmed selection gap (static only)

The frozen 497-case artifact-only harness `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` fixes **30 focused + 12 CP2 focused + 449 selector + six CP3 entry** exact-filter processes. Recomputed SHA256 for frozen identity lists:

- focused30: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- focused12: `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`

The following source-defined exact GoogleTest identities in `tests/SurfaceCellTransitionQuotientTests.cpp` **are not selected** by any of those 491 lists or the harness's six hardcoded CP3 entries:

1. `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`
2. `M6CP3.HardRailPublishedTauRequiresIncidentSourceFaces`
3. `M6CP3.A6SeamDirectionRejectsForeignFaceAndWedgeBindings`
4. `M6CP3.A7TypedWedgeSheetMismatchRejectsCachedMembership`

CMake `cmake/DirectionalTests.cmake:69–90` compiles the containing `.cpp` into `directional_surface_cell_producer_tests`. The source defines **nine** `M6CP3` tests; exactly **six** match the frozen CP3-entry identities, leaving three additional CP3 tests outside the 497. The factory test is a separate additional identity. Compilation of these test bodies is **not** an execution result.

## Required independent decision for future execution coverage

The two unresolved decisions remain in `.agents/Directional/Architecture_M6_CP3_R3_A3_Trust_CB_TB_Gate_Review_Request.md`: independent versus A4-trusted nonrail A3 factory attestation, and CB versus TB produced-witness acceptance sequencing.

**Additional coverage question for that review:** Decide whether the four source-defined out-of-scope tests above require a separately authorized **supplemental artifact-only** targeted process set against the exact immutable candidate package. If authorized, the supplemental process(es) must be separately counted and reported, preserve the existing **exactly 497** frozen process gate byte-for-byte, require exact-one selection and zero skips for each supplemental identity, and never silently promote a case on compile evidence. A frozen 497/497 result **cannot by itself prove** that these additional tests executed or passed. The test program must not be launched during this Code + Build turn, even with `--gtest_list_tests` or `--help`.

This is a selection audit, not a claim that any test would pass, fail, or reach a particular production rejection locus; no R3 source or test change was made for this report. D1/D2/D3/D5/A6/A7 real-produced witnesses, R2 39 first-failure cases, and 47 accepted-green recoveries remain runtime-unverified. Retain R3 `IN_PROGRESS`, successor `UNKNOWN` pending reviewed authority.