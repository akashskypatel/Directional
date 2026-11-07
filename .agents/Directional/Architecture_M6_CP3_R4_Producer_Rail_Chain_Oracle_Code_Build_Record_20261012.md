# M6-CP3-CB1-ENTRY-R4 — source-exact producer rail chain oracle, compile-only (2026-10-12)

**Boundary:** Same Code + Build turn `M6-CP3-CB1-ENTRY-R4`; IN_PROGRESS, successor UNKNOWN. No Directional binaries, tests, benchmarks, frozen TB497, selector/ABI/workflow/PR changes or acceptance promotion.

## Source exactness and changes

- Snapshot workflow `38200112151`, source `2143440c64e328136332117edcd539f1d5856939`, artifact `11724614946`, ZIP SHA-256 `5a3186b67f8c589f8b8be9985fa2076c3425b9ae43efdab5f2305287e4f9b6fa`; file manifest 6329/6329 verified; `runtimeExecution=false`.
- One test file: `tests/SurfaceCellREPackageTests.cpp` +24/-0. Existing `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` now asserts the producer issues one ordered source vertex per source interval, with the correct closed/open cardinality, two samples per edge, and matching face-local endpoints for every emitted interval. The existing `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` fixture now carries exact source vertices `{0,3}` from `make_grid(1)` face-0 local edge 1. No new test selector or name.
- Patch full SHA-256 `01e7867c927a56a746c443fc36fa6c119025c50ee29b1ca90b6425b9f86580ea`, diff body SHA-256 `ac253e8c6acc291ccb129efee4f0db8e1944fc8242e4e4b8958de1f845783992`, source base `2143440c64e328136332117edcd539f1d5856939`; local forward/reverse apply and whitespace checks passed.
- Patch applied in workflow `38200534499`, job `114652777586`, result artifact `11725560890` ZIP SHA-256 `006080f238a7ee58c5d53ecc5e305b10d89fd278b3ef7e850720670995662a4a`; exact semantic source `e7a39b891a046df46811bc9f792a17e0c33e7da9`. Owner permanently deleted the consumed Drive file `15Aw60-ZW6DvTUUuvw4Z93mGE61V5C-ZR` after successful push.

## Mandatory eight-target GMP/GMPXX compile

- Exact semantic source `e7a39b891a046df46811bc9f792a17e0c33e7da9`; dispatcher event `f220feb07ec2fc66d4fb0d7fff04bf52ba0bdee4`, mailbox `.workflow-mailbox/m6-cp3-r4-rail-chain-oracle-compile/latest.json`.
- **GREEN**: workflow `38200681852`, job `114653260254`, result artifact `11725410765`, ZIP SHA-256 `ee7472bc18b63bff93c24a1c4cd7a848eb8f30ff113e99e87b25da5f6d0ff44c`, package manifest **28/28**, preflight/build exits **0/0**, **8/8** required targets, CMake GMP enabled and GMPXX/GMP linker verified, clean source, `runtimeExecution=false`.
- No runtime or acceptance evidence. These assertions are **compile-visible only**, not executed PASS results.

## Open R4 work

RA-43.4 global legacy-untyped fallback retirement remains incomplete. The independent overfull-A3 feasibility ruling remains requested; do not amend the supplemental A4 oracle without it. The 39 endpoint, 34 Phase10, seven DCEL, 88 accepted CP2 losses, six CP3 positives, and genuine multi-carrier odd-τ remain unverified. Accepted CP2 491/491 and rejected R3 403/497 (94 RED / 88 CP2 losses), ledger 66/17/49 debt1 unchanged. No permission to start frozen TB497.
