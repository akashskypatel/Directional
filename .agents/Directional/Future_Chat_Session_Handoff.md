# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB4-REV` COMPLETE / CANDIDATE REJECTED / TEST-AUTHORITY COMPOSITION DRIFT / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-CB7` test-authority-only Code + Build / runtime-free

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Corrected R4 artifact `10289601000` remains accepted M4-CP3 runtime authority. Accepted selector403 is
  `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, **403/403**.
- CB5's production A3→A4 cutover remains compile-valid but not accepted. Rows404-407 received focused-green evidence
  in TB3; row408 has still never reached the intended torus shared-hard-rail seam under a valid frozen fixture.
- CB6 semantic source `9d66fcebe4b91ab74a6d0234c46643a2723ab643` produced candidate package `10292005428`, SHA-256
  `7723188540182f9515b95efd83c13dd1dbc6f0813532a98cd8df0778a12a882f`; selector408 remains byte-frozen at
  `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` with owner partition **30 / 262 / 75 / 41**.
- TB4 authoritative run/job `34674553424 / 103501973294` passed immutable preflight, executed exactly one process,
  and stopped fail-fast on row408. Result artifact `10292016472` hashes to
  `6d3992f3faa0f9f925a35f4ed0afcffcfc3ec2910fc48f3c1d88cc1183040a0f`; log artifact `10291946526` hashes to
  `072fa3127455e6f886e41e91f7465d57601168b13055f26bae900a2cb54abb51`. Row408 selected exactly one test and failed
  at `fixture.network.has_value()` with top-level terminal code `InvalidFieldTransportAtlas`; immutable postflight passed.
- TB4 Review independently proves the CB6 derivation guard was correct for its **18 explicit user edges**, but
  incomplete for the **effective production authority**. Default `AdaptiveFeatureMap` classification adds **48**
  automatic hard edges, disjoint from the 18 user edges. Production therefore consumes **66** hard edges and splits
  the torus into five source topology regions (`24/24/24/48/24` faces), not the intended one-region two-generator
  witness. The raw TB does not expose the nested atlas error, so no more specific atlas diagnosis is claimed.
- `M4-CP3-TB4-REV-CAND-01` is **TEST-AUTHORITY / FIXTURE-PRECONDITION COMPOSITION + REACHABILITY DRIFT / NON-STABLE**.
  Package `10292005428` and selector408 are **NOT PROMOTED**. Stable accounting remains **47 events / 14 categories /
  33 recurrences**, produced-witness debt **5**. `G4-B002` and CP3 remain OPEN.

## Exact next — `M4-CP3-CB7`

Authority: `.agents/Directional/Architecture_M4_CP3_CB7_Code_Build_Plan.md`.

CB7 is test-authority-only and runtime-free. Its first action is a mandatory **effective-authority** guard, not another
additive-edge proof. With row408-only feature-map absolute dihedral bands set to `179.0 / 180.0` for both CAD and
organic modes, statically re-run production classification and prove:

1. explicit user-hard count = 18;
2. automatic-hard count = 0;
3. effective rail/hard-feature set = exactly those same 18 source edges;
4. the resulting production topology is the intended one-region torus with the already-proved two-generator
   disc-complement cut graph.

Any nineteenth effective hard rail, alternate topology region split, production-code dependency, or need to filter
rails downstream is a STOP before mutation/build.

If the guard passes, the only semantic edit may be four assignments inside
`cp4c_torus_hard_rail_remesh_options()` in `tests/FieldAlignedCurveNetworkTests.cpp`:

```cpp
options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
```

The exact idiom already exists in `AdaptiveFeatureMapPhase11.DensityDoesNotLeakAcrossDisconnectedCloseSheet` and
preserves explicit user Hard tags because those are classified before automatic scoring. Row408 assertions/identity,
rows404-407, production code, selectors, ownership and CMake semantics stay frozen. Then compile/package through the
mandatory reusable workflow with GMP/GMPXX and `runtimeExecution=false`; execute no Directional binary.

A green CB7 packages a new candidate for `M4-CP3-TB5-EXEC`, which must restart the entire **821-process** gate from
process 1. Mandatory Review after TB5 owns promotion, `G4-B002`, CP3 and accounting.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: source-static effective feature-authority derivation
    path: turn-based-coding-agent/modules/code-change/MODULE.md
  - trigger: compile/package through GitHub Actions
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB4_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB7_Code_Build_Plan.md
  - .agents/Directional/M4_Consolidated_Record.md
  - .agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt
do_not_preload:
  - M5/M6 implementation
  - any runtime in CB7
  - product changes or selector changes
```
