# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB3-REV` COMPLETE / CANDIDATE REJECTED / TEST-AUTHORITY FIXTURE-PRECONDITION / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Code + Build, `M4-CP3-CB6`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Corrected R4 artifact `10289601000` at semantic source `58521f6d1c4fb5d625da7cde50e002cf4688beee` remains accepted M4-CP3 runtime authority. Selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` remains accepted **403/403**.
- CB5 semantic source `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`, package `10290933668` and selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` are **REJECTED FOR PROMOTION / retained candidate evidence** after TB3 row408 failed its fixture reachability precondition.
- Rows404-407 passed in fresh focused-A processes. Row408 failed before its A3/A4 assertions because the torus fixture carried no hard-feature rail authority and authoritative phase-front disposition was `NotApplicable`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**. `G4-B002` and CP3 remain OPEN.

## TB3 execution and review authority

```text
CB5 package artifact       = 10290933668
CB5 package SHA-256        = 3c73ce15c626b9811a0122cccaaa9615f76f1a6b5d6e93692a05fef524a36571
TB3 run / execute job      = 34671972132 / 103494923768
TB3 result artifact / SHA  = 10291076362 / 56158d759bf7827e33a51ce04fcd67bba960f68fea7486893fdf14936d96f388
TB3 log artifact / SHA     = 10291146242 / 93d56c5c8fc76f4d9ab1210183ce6aa57ecab25479f01b3e31b5ec78c33de5b1
focused-A rows404-407      = 4/4 PASS
focused-A row408           = RED
observed processes         = 5 / 821 planned
preflight / postflight     = PASS / PASS
```

The frozen fail-fast rule correctly stopped after row408, so focused-B, accepted selector403 and candidate selector408 were not executed. Package/source/execution-view remained immutable and no configure/compile/relink/discovery/package repair occurred.

`M4-CP3-TB3-REV-CAND-01` is **TEST-AUTHORITY / FIXTURE-PRECONDITION + REACHABILITY DRIFT / INCORRECT EXPECTATION / NON-STABLE**. Current `cp4c_remesh_options()` declares no explicit hard edges. Production only returns aggregate phase-front `NotApplicable` after all regional producers decline when `hardFeatureEdges.empty()`. Thus row408 never reached the shared hard-rail seam it claimed to test and cannot support promotion or product-regression pricing.

## Exact next — `M4-CP3-CB6`

Authority: `.agents/Directional/Architecture_M4_CP3_CB6_Code_Build_Plan.md`.

CB6 is a **test-authority-only reachability correction**. Before mutation it must statically re-prove two explicit fundamental cycles in committed `torus.obj`:

```text
C_minor = 0-3-25-37-49-61-0
C_major = 0-1-4-6-8-10-12-14-16-18-20-22-0
```

Every pair must remain a source edge; the cycles must be simple, intersect only at vertex 0, represent independent torus directions, and form a disc-complement cut-graph shape. If that guard passes, row408 alone may use those pairs as explicit `surfaceCells.featureMap.userHardEdges`, preserving the row408 identity, selector408 bytes/hash, rows404-407, accepted selector403 and all production semantics. The repaired row must require retained hard-feature rail authority, produced phase-front, exact conformity receipt, at least one HardRail typed shared interval, and absence of `InvalidHardRailPairing`.

**STOP before mutation** if product source/header changes are required or any second dependency appears. Compile/package only via the reusable GMP/GMPXX workflow with `runtimeExecution=false`; no Directional runtime in CB6.

If CB6 packages green, a later artifact-only TB restarts the full **821-process** gate from the beginning, followed by Review. Do not resume from old row408.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: bounded test-authority correction
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: compile/package through GitHub Actions
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB3_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB6_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB3_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB5_Compile_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB5_Derivation_Guard_Record.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - tests/FieldAlignedCurveNetworkTests.cpp
  - benchmarks/fixtures/milestone-g/torus.obj
do_not_preload:
  - M5/M6 implementation
  - product-source changes; CB6 is test-authority-only unless the guard stops and returns to Review
  - any runtime executor during CB6
```
