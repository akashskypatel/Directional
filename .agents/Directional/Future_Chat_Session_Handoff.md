# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB4-R4` COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE UNPROMOTED
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Test + Benchmark EXEC, `M4-CP3-TB2-R2-EXEC`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority.
- Package120 / historical old selector403 remains mechanically **403/403** but **unpromoted**.
- Corrected R4 candidate package artifact `10289601000` is compile/package-green at exact evidence source `58521f6d1c4fb5d625da7cde50e002cf4688beee`, but has no runtime acceptance yet.
- Successor selector403 is unchanged: 403 rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; first394 is accepted selector394 byte-for-byte at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`; owner partition `30/257/75/41`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3→A4 cutover remains unauthorized.

## R4 Code + Build result

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R4_Code_Build_Report.md`.

R4 performed exactly the one build-contract mutation authorized by R3 Review: in `cmake/DirectionalTests.cmake`, the mandatory producer test identity `FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder` was replaced by `TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking`. Product source, test/fixture source, selectors, owner targets and guard behavior remained frozen.

Static guards before/after mutation established OLD source definitions `0`, NEW definitions `1`, unique producer ownership, unchanged selector403 `c3f509...`, unchanged accepted first394 `6c27b3...`, row400 NEW, and owner totals `30/257/75/41`.

Changed-owner preflight:

- run/job `34665764441 / 103477222022`;
- exact source `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- target `directional_surface_cell_producer_tests` only;
- result artifact `10289560941`, SHA-256 `289e48f1c8b637f0b165a59df073ef3187dd0829e1f6309a6cf93f9181347342`;
- log artifact `10289276413`, SHA-256 `df90fdefca367086c2e12a9871677023d8f1a26d0b04ae3ee5150c16a8b412fe`;
- configure/compile/link PASS, GMP/GMPXX, empty source status, `runtimeExecution=false`.

Full package:

- run/job `34665925501 / 103477693366`;
- same exact source `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- all eight frozen targets compiled and linked;
- result artifact `10289601000`, SHA-256 `ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9`, `29,764,498` bytes;
- log artifact `10289551097`, SHA-256 `765424fa9faa277632ff6149b86f84291269d9c443ded7e146a7e40ea70bd58f`;
- packaged source archive SHA-256 `b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0`;
- 28-entry manifest SHA-256 `d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b`, full self-verification PASS;
- GMP/GMPXX verified, source clean, four owner executables mode `755`, `runtimeExecution=false`.

No GTest discovery/listing, `ctest`, test, benchmark, produced binary, CLI, help/version or custom-input runtime executed in R4.

One earlier preflight orchestration attempt `34665672229` was a zero-job startup failure caused by an insufficient temporary-caller permission ceiling for the observer reusable. The caller permission union was corrected only at the control plane; semantic source/reusable workflows were unchanged, and that attempt carries no semantic/build credit.

## Exact next — `M4-CP3-TB2-R2-EXEC`

Use `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md`.

Execution is artifact-only against immutable package artifact `10289601000`; configure/compile/relink/package repair are forbidden. Preflight must verify artifact/provider digest, 28/28 package manifest, evidence source, packaged source archive, selector hashes/prefix, unique owner mapping and row400's independent `1/3` correct versus `2/3` wrong-basis discriminator.

Run exactly **799 fresh GTest processes**:

```text
replacement row400 focused A       1
replacement row400 focused B       1
accepted selector394             394
successor selector403            403
-------------------------------------
total                             799
```

Each process uses one exact `--gtest_filter` and must select exactly one test. Acceptance requires focused `1/1` twice, selector394 `394/394`, selector403 `403/403`, owner partition `30/257/75/41`, zero RED/SKIP/timeout/selection mismatch, and byte-identical package/source/execution-view postflight. No benchmark is authorized.

A green EXEC does **not** promote the candidate. Exact successor is `M4-CP3-TB2-R2-REV` for independent evidence re-derivation and package/selector disposition.

## Carried obligations

- `M4-CP3-CB4-R2-REV-CAND-01`: source correction is now compile-proved; runtime acceptance remains outstanding until TB2-R2 + Review.
- `M4-CP3-TB2-REV-CAND-01`: replacement row400 authority is source-proved/non-vacuous and compile-packaged; runtime acceptance remains outstanding.
- `M4-CP3-CB4-R3-REV-CAND-01`: **closed by R4 compile/package** as non-stable build-contract drift; no product regression was introduced.
- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity weighting still only `[1,1,1]`; remains outside the row400 recovery.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` consistency tamper remains outside the row400 recovery.
- No A3→A4 cutover or exact-torus pairing work before corrected package runtime acceptance and Review.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB.md
conditional_modules:
  - trigger: execute the frozen artifact-only row400/selector gate without changing test semantics
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector harness, artifact retrieval, observer evidence and cleanup
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R4_Code_Build_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt
  - .agents/Directional/Architecture_M4_CP3_Required_Green_Selector_394.txt
  - tests/FieldAlignedCurveNetworkTests.cpp
  - .agents/Directional/Required_Green_Selector_Manifest.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - M4-CP3-CB4-REV-OBS-02 row399 work
  - any compile/relink during artifact-only TB execution
```
