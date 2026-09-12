# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB4-R3` HALTED / STOP-GUARD / POST-MUTATION / CONFIGURE RED / NO RUNTIME
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Review, `M4-CP3-CB4-R3-REV`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority.
- Package120 / historical old selector403 remains mechanically **403/403** but **unpromoted**.
- Historical old selector403 SHA-256 remains `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; accepted first394/selector394 remains `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3→A4 cutover remains unauthorized.

## CB4-R3 disposition

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R3_Compile_Guard_Record.md`.

The bounded A2b semantic correction is preserved at `7fdc3c001de9193f8f94591d3e74d1c94c260195`. The terminal-contact branch now remaps canonical contact components by vertex identity into raw oriented `SourceFaceRecord::vertices` order before `vertex_locus_secondary_parameter` consumes them. Replacement row400 uses `make_four_triangle_fan()` row 3 raw `[3,0,4]`, canonical `[0,3,4]`, canonical weights `[1/6,1/3,1/2]`, locus 4, independent correct secondary parameter `1/3`, and explicit wrong-basis result `2/3`.

New candidate selector `.agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt` contains 403 LF rows with SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`. Its first394 remains accepted selector394 byte-for-byte at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`; only row400 differs from historical CB4-R1 selector403, and owner totals remain `30/257/75/41`.

Compile run `34663130547` checked out exact semantic source `7fdc3c0`, proved GMP/GMPXX authority, and failed at CMake configure before target compilation because `cmake/DirectionalTests.cmake` still mandates the retired row400 identity `FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder`. Frozen CB4-R3 scope excludes build configuration. The package job was skipped, no package was produced, and no Directional runtime executed. Do not rerun unchanged and do not patch CMake inside the halted turn.

## Exact next — `M4-CP3-CB4-R3-REV`

Runtime-free Review must independently re-open the semantic diff and compile evidence and decide one bounded authority correction: either freeze a successor Code + Build plan that surgically replaces the mandatory packaged-test-contract identity in `cmake/DirectionalTests.cmake`, or reject/replace CB4-R3 if that would weaken/misstate the packaged required-green contract. Review may update planning/durable review records only; it must not compile, execute runtime validation, mutate product/test/selector/build source, or promote selector403.

Package119/selector394 remains accepted **394/394**. Package120/historical old selector403 remains mechanically **403/403** but unpromoted. The CB4-R3 successor selector403 is static candidate authority only. Stable accounting remains **47 / 14 / 33**, debt **5**, CP3 open, and A3→A4 cutover unauthorized.

## Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity weighting still only `[1,1,1]`; keep outside CB4-R3.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` consistency tamper remains outside CB4-R3.
- No A3→A4 cutover or exact-torus pairing work before corrected package acceptance.

## CB4-R3 provenance and closeout

- source snapshot authority/run/artifact: `463bcb9ab35f7b9941e03199c8ca0818b20db84c / 34662558179 / 10288520129`
- snapshot provider digest: `sha256:c467d2fa754d45fedfbcb89e1b5668b93a41f191784950db2575e7332bfbe709`
- work-preservation patch SHA-256: `5fe9f584c081d461d5c8a93569d97147b9c36480b60ee9c300410a03d3eafb38`
- semantic patch apply run/commit: `34663036232 / 7fdc3c001de9193f8f94591d3e74d1c94c260195`
- compile run / failed preflight job: `34663130547 / 103469632631`
- failed preflight log artifact/digest: `10287418994 / sha256:53488144ddedfea1d1e7eb98b57cc403ef93a22bd9260af1ea85747fc9b10fe3`
- compile failure stage: CMake configure, before any target compilation; package job skipped
- `runtimeExecution=false`; no Directional runtime, test, benchmark, discovery/listing command, or produced binary executed
- temporary apply/compile callers and markers were retired after evidence capture; Drive patch staging was owner-deleted after successful semantic push
- final turn-cleanup run/head is recorded by the closeout metadata after the mandatory cleanup workflow completes

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/REVIEW.md
conditional_modules:
  - trigger: independent semantic/build-contract adjudication and successor planning
    path: turn-based-coding-agent/modules/engineering-guidelines/MODULE.md
  - trigger: replacement row400 test-authority review
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector reads/writes, artifacts and cleanup
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Compile_Guard_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R2_Review_Record.md
  - cmake/DirectionalTests.cmake
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
templates_when_producing:
  - turn-based-coding-agent/templates/REVIEW_REPORT.md
  - turn-based-coding-agent/templates/CODE_BUILD_PLAN.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - M4-CP3-CB4-REV-OBS-02 row399 work
  - runtime execution or compilation during Review
```
