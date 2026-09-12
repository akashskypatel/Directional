# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB4-R3-REV` COMPLETE / RUNTIME-FREE / `approved_with_amendments`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Code + Build, `M4-CP3-CB4-R4`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority.
- Package120 / historical old selector403 remains mechanically **403/403** but **unpromoted**.
- R3 successor selector403 is static candidate authority only: 403 rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, accepted first394 `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`, owner partition `30/257/75/41`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3->A4 cutover remains unauthorized.

## R3 Review disposition

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R3_Review_Record.md`.

Review independently upholds semantic commit `7fdc3c001de9193f8f94591d3e74d1c94c260195`. The terminal-contact branch correctly remaps canonical contact components by source-vertex identity into raw oriented `SourceFaceRecord::vertices` order before `vertex_locus_secondary_parameter` consumes them. Replacement row400 is independently non-vacuous on existing fan row `[3,0,4]` versus canonical `[0,3,4]`, canonical weights `[1/6,1/3,1/2]`, locus 4: correct exact secondary parameter `1/3`, wrong positional result `2/3`.

Failed compile evidence `34663130547 / job 103469632631 / artifact 10287418994` is upheld: exact semantic source and GMP/GMPXX were verified, then configure stopped before target compilation because `cmake/DirectionalTests.cmake` still mandates retired row400 identity `FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder`, which has zero definitions. Replacement identity `TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking` has exactly one definition in `tests/FieldAlignedCurveNetworkTests.cpp`, remains producer-owned, and preserves selector owner totals.

`M4-CP3-CB4-R3-REV-CAND-01` is **BUILD-CONTRACT / MANDATORY PACKAGED-TEST IDENTITY DRIFT / NON-STABLE / SOURCE-PROVED**. It is another instance of `LESSONS.md` 49. No selector/package is promoted by Review.

## Exact next — `M4-CP3-CB4-R4`

Use `.agents/Directional/Architecture_M4_CP3_CB4_R4_Code_Build_Plan.md`.

R4 may change exactly one semantic build-configuration value: replace the retired mandatory packaged-test identity in `cmake/DirectionalTests.cmake` with `TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking` inside the existing producer ownership guard. Product source, test/fixture source and selector bytes are frozen.

Before mutation, re-derive exact identity counts/ownership and selector hash/prefix. After the one-name change, compile through the mandatory reusable GitHub workflow only:

1. changed-owner preflight `directional_surface_cell_producer_tests`;
2. if green, full selector-owner package (`directional_core`, `directional_pipeline`, authority-kernel/producer/completion/validation/compiled-api tests, `directional_benchmarks`).

Require GMP/GMPXX, exact clean pushed source, package manifest proof and `runtimeExecution=false`. Do not run GTest listing/discovery, `ctest`, tests, benchmarks, produced binaries or any other Directional runtime. If any second CMake/semantic dependency is needed, STOP and return to Review.

If R4 packages green, future artifact-only `M4-CP3-TB2-R2-EXEC` remains **799** fresh processes: row400 twice + selector394 394/394 + successor selector403 403/403, followed by Review before promotion.

## Carried obligations

- `M4-CP3-CB4-R2-REV-CAND-01`: source correction implemented; still compile/runtime-unproved until R4 + later TB.
- `M4-CP3-TB2-REV-CAND-01`: replacement test authority is now source-proved/non-vacuous; runtime acceptance remains outstanding.
- `M4-CP3-CB4-R3-REV-CAND-01`: R4 corrective owner.
- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity weighting still only `[1,1,1]`; keep outside R4.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` consistency tamper remains outside R4.
- No A3->A4 cutover or exact-torus pairing work before corrected package acceptance.

## Review provenance

- review start semantic authority: `7fdc3c001de9193f8f94591d3e74d1c94c260195`
- review snapshot/control head: `1dad640454306e3ed642640a1409168ed26c5920`
- source-snapshot run/artifact: `34664102792 / 10287759503`
- snapshot provider digest: `sha256:2f012f588c3e520de303cb42910fd37b8c639b749f9b3adbf3883d62dc9f37cf`
- inner source archive SHA-256: `1743c8eea0125a6496328fa20aaa15925dd825debe551a1e13c0f75ed60b1ccc`
- reviewed compile log artifact: `10287418994 / sha256:53488144ddedfea1d1e7eb98b57cc403ef93a22bd9260af1ea85747fc9b10fe3`
- no compile, test, benchmark, produced binary or Directional runtime executed in Review

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: one-name CMake packaged-test ownership correction and bounded compile planning
    path: turn-based-coding-agent/modules/engineering-guidelines/MODULE.md
  - trigger: verify replacement identity remains the intended non-vacuous regression; do not redesign it
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector writes, compile workflow, artifacts and cleanup
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB4_R4_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Compile_Guard_Record.md
  - cmake/DirectionalTests.cmake
  - tests/FieldAlignedCurveNetworkTests.cpp
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt
  - .agents/Directional/Required_Green_Selector_Manifest.md
templates_when_producing:
  - turn-based-coding-agent/templates/CODE_BUILD_REPORT.md
  - turn-based-coding-agent/templates/TEST_PLAN.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - M4-CP3-CB4-REV-OBS-02 row399 work
  - runtime execution during Code + Build
```
