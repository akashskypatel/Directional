# M6-CP3-CB1-ENTRY-R4 — Phase14 remaining positive rail source-vertex migration

**Turn:** `M6-CP3-CB1-ENTRY-R4` Code + Build continuation; do not promote to Test + Benchmark.
**Exact source baseline:** `5fbfa5de3f1421dab122ea70ba677efb6dd6f5f1` (8/8 GMP/GMPXX compile GREEN, workflow `38193556754`, artifact `11721982481`, `runtimeExecution=false`).
**Source patch:** `Directional_R4_Phase14_Typed_Rail_Positive_Migration_5fb.patch`, complete SHA-256 `53ea70a3d4a62f8afc42ece510e772c87d0b8d343f1d7ec5df55381e53313937`, diff-body SHA-256 `97b29be269f60cc152e17103a75ae44fe73dfd19e1ee7211dc255114b9eca22f`.
**Scope:** one existing test source file `tests/SurfaceCellTracingPhase14Tests.cpp`; ten one-line source-vertex publications across seven **unchanged** tests; no production code, frozen selectors, assertion/oracle, or workflow files changed.

## Exact source-vertex publications

| Existing test | Rail | Exact typed ordered source vertices |
|---|---|---|
| `CompatibleHardFeatureRailIsFollowed` | 5 | `{0,3}` |
| `OpenHardFeatureRailEndpointIsNotClassifiedAsSourceSheet` | 43 / reversed 44 | `{0,3}` / `{3,0}` |
| `CompatibleHardFeatureRailPreservesIntervalMetadata` | 42 | `{0,3}` |
| `CompatibleHardFeatureRailEntersFromEitherSide` | 91 / reversed 92 | `{0,3}` / `{3,0}` |
| `CompatibleHardFeatureRailVisitsAlternatingStoredSideIntervalsInOrder` | 77 / spur 78 | `{0,4,7}` / `{4,8}` |
| `HardFeatureRailContinuationCrossesAdjacentLocalSheetCharts` | 93 | `{0,4,7}` |
| `ClosedHardFeatureRailWrapsIntervalSequence` | 88 | `{0,1,2}` and implicit wrap to 0 |

All assignments are grounded in `make_grid`, the triangle source-face rows, exact stored barycentric corners, and `rail_interval_refs` exact-edge/vertex correspondence. For a closed rail, `sourceVertices` contains one vertex per interval and the last edge wraps to the first; no duplicate initial vertex. The intentionally legacy-untyped near-corner negative `ProducedRailEndpointsRequireExactSourceVertexIncidence` and malformed interval rejection fixtures are *not* modified.

## Application and compilation evidence

**Patch staging:** Google Drive `My Drive/Directional-CI` file ID `1XOXbsjTyBlqiyMtIX3vj-RmsojFGPIyo`. Durable `drive_apply` request commit `1ced5ec62339b668fd9c89dc9d4fb58c451adeb9`, mailbox `.workflow-mailbox/m6-cp3-r4-phase14-typed-positive/latest.json`.

**Apply outcome:** success, workflow `38194680839`, job `114634700456`, artifact `11722878840` verified outer digest `c1d7c9aaf30cb45dcc742d77c3fdc69999e1ae0b40cad63176db4cfe85f69a84`, source semantic commit `10afde93e4de3202d5bc8d2bbd0304f629a2375e`, exact one-file ten-line diff, Drive stage permanently deleted.
**Compile outcome:** Exact-source mandatory eight-target GMP/GMPXX compile **GREEN**; workflow `38194789102`, job `114635016916`, result artifact `11723220719`, ZIP SHA-256 `3340a26bc7fc8a543843981d0040a84339ec44490ed26c17b5541f1cc53e6039`. Eight targets verified; CMake `DIRECTIONAL_ENABLE_GMP=ON`, actual generated linker command references both `libgmpxx.so` and `libgmp.so`, package 28/28 checksum manifest, preflight/build exit 0/0, source worktree clean and `runtimeExecution=false`. No Directional test or benchmark executed. Compile dispatcher request `603c80eac8a8dcafb1d80c9c71ec8c4c99e5ab0a` at mailbox `.workflow-mailbox/m6-cp3-r4-phase14-typed-positives-compile/latest.json`. No local build or Directional test execution.

## Remaining obligations

Code-only fixture migration does not confer a runtime PASS or discharge RA-43.4 globally, source-overfull A3 independent review, 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 accepted-loss, six CP3 positives, genuine multi-carrier odd-τ witnesses, or RA-41/RA-43 producer contract. Existing frozen 497 selection and accepted CP2 gate unchanged. Canonical R4 stays incomplete, successor UNKNOWN.
