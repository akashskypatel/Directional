# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB10` COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-TB8-EXEC`

## Current authority

- M1-M3: CLOSED / ACCEPTED. M4-CP1/CP2 remain historical accepted framed closures.
- Corrected R4 artifact `10289601000` remains accepted M4-CP3 runtime authority at selector403 **403/403**; selector403 SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`.
- CB10 semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a` is **COMPILE GREEN / RUNTIME UNADJUDICATED**. Candidate package artifact `10307919492` is not promoted until TB8 Review.
- CB10 changed only `tests/SurfaceCellTransitionQuotientTests.cpp`: `make_hard_rail_fixture()` now obtains its hard-rail network through the production SurfaceCells A2b/A3 authority path while preserving the same 3×3 mesh, hard edges `(1,4)` / `(4,7)`, and all six downstream identity names/bodies. No product source or selector changed.
- Mandatory eight-target GMP/GMPXX compile run/job `34727247774 / 103643462175` is GREEN; package root manifest verified **28/28**, source status is empty, `runtimeExecution=false`.
- Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. CP3 and `G4-B002` remain OPEN.

## CB10 disposition

All pre-mutation guards G1-G4 passed. The stale fixture had been bypassing `GlobalTopologyPlan` / `GlobalConformityBaselinePlan`, so exact A3 `sharedBoundaryInterval` identity was absent and production correctly failed closed. Frozen M4 product strictness remains unchanged: no floating `support_key`, no no-plan hard-rail fallback, and no weakening of missing-interval rejection was introduced.

The correction is test-authority-only. The shared fixture now invokes `remesh_from_raw_cross_field(..., SurfaceCells)` with fallback `Fail`, source-grid recovery disabled, retained intermediates and user hard edges; it requires production-owned source/topology/conformity/rail/trace products before exposing the fixture. Selector403/408 hashes remain unchanged (`c3f509af...70cb7` / `c689c0cd...b0484`).

Compile result artifact `10307919492` has provider digest `8988a12fa8b2e6476bf3fd91a6a6936eaef8a9ab7c73837b74ea2e980d29b2ec`; compile log artifact `10307949270` has digest `f07c66d168d6baacaf3074f789faa0b5581c2a2eadd72c640577220cfa6e4c8a`. No Directional runtime was executed in CB10.

## Exact next — `M4-CP3-TB8-EXEC`

Follow `.agents/Directional/Architecture_M4_CP3_TB8_Artifact_Only_Test_Benchmark_Plan.md` exactly against immutable candidate package `10307919492` / source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`.

TB8-EXEC is mechanical only. It must run the six corrected shared-fixture identities A/B, ordinal138 A/B, row408 A/B, rows404-407 A/B, then execute accepted selector403 **to completion without semantic fail-fast** and publish the complete RED census, followed by selector408 cumulative execution. Immutable pre/postflight is mandatory. `M4-CP3-TB8-REV` is the mandatory promotion/classification owner; no later CB may start before Review if TB8 is RED.

## Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity-2 end-to-end oracle remains carried/non-blocking.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` divergence tamper detector remains carried/non-blocking.
- TB3 provenance warning remains: row408 is a constructed production torus witness, not evidence that `InvalidHardRailPairing` was historically observed in that exact path.

## Context Load Plan

```yaml
load_next:
  - .agents/Directional/Architecture_M4_CP3_TB8_Artifact_Only_Test_Benchmark_Plan.md
required:
  - .agents/Directional/Architecture_M4_CP3_CB10_Code_Build_Report.md
  - .agents/Directional/Architecture_M4_CP3_TB7_Review_Record.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
do_not_preload:
  - M5/M6 implementation
  - any product fallback for no-plan hard rails
  - any package repair or rebuild inside TB8
```
