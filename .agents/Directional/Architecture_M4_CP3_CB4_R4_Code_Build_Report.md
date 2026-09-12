# M4-CP3-CB4-R4 Code + Build Report — packaged-test contract repaired and corrected package built

**Status:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE UNPROMOTED
**Phase:** `M4-CP3-CB4-R4`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Execution mode:** canonical Code + Build
**Starting exact turn source:** `4defb0cc7992c669f146f6927e58a393baae8fec` (snapshot/control commit; semantic predecessor remains R3 commit `7fdc3c001de9193f8f94591d3e74d1c94c260195`)
**Built evidence commit:** `58521f6d1c4fb5d625da7cde50e002cf4688beee`
**Handoff/closeout commit:** documentation/control closeout follows the immutable built evidence commit; runtime authority remains keyed to `58521f6d1c4fb5d625da7cde50e002cf4688beee`
**Remote synchronization verified:** yes; compile workflows checked out the exact built evidence commit and reported empty source status before/after configure/build.

## Implemented

R4 made the one and only semantic build-configuration change authorized by the R3 Review:

```text
cmake/DirectionalTests.cmake
OLD FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
NEW TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking
```

The containing producer packaged-test ownership guard, source path, targets, product code, test/fixture code and selector bytes were unchanged.

Pre-mutation re-derivation on the exact source proved:

- OLD test definitions: `0`;
- NEW test definitions: `1`;
- NEW definition owner: `tests/FieldAlignedCurveNetworkTests.cpp` in `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES`;
- selector403: `403` LF rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- accepted first394: byte-identical to selector394, SHA-256 `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- row400: `EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking`, uniquely producer-owned;
- selector403 owner partition: `30 / 257 / 75 / 41`.

Post-mutation static re-derivation proved OLD count `0`, NEW CMake contract count `1`, NEW source-definition count `1`, and both selector hashes unchanged.

## Engineering-Guideline Review

- Material assumptions surfaced: the R3 failure was derivative packaging metadata drift, not a product/test semantic defect; the replacement identity had to be the unique existing producer definition.
- Simplest sufficient approach chosen: one string replacement in the existing mandatory packaged-test contract.
- Why no smaller approach satisfies the contract: leaving the stale name makes configure fail; removing or weakening the guard would violate packaged-test authority.
- Unrelated refactors/style drift avoided: yes.
- Every changed semantic line traces to objective/supporting validation: yes; exactly one build-configuration line changed.

## Files Changed

Semantic/build evidence:

- `cmake/DirectionalTests.cmake` — one mandatory identity replacement (`+1/-1`).

Closeout-only documentation is recorded separately from the immutable build evidence.

## Domain Invariants

- R3 product and test semantics are byte-frozen.
- Selector394 and selector403 name/order/bytes are unchanged.
- Owner partition remains `30 authority-kernel / 257 producer / 75 completion / 41 validation` for selector403.
- Package119 / selector394 `394/394` remains the accepted runtime authority until TB Review promotes a successor.
- CP3 remains open; A3→A4 cutover remains unauthorized.
- Stable accounting remains `47 events / 14 categories / 33 recurrences`; produced-witness debt remains `5`.

## Generalization Review

- Why this is not fixture-specific: the edit repairs the build contract that validates mandatory packaged-test ownership for every package configure; it does not branch on fixture data.
- Valid input classes affected: none at product runtime; this is package/configure metadata only.
- Regression risks considered: wrong target ownership, selector drift, silent guard weakening, a second build dependency, and accidental runtime execution. All were explicitly guarded.

## Build

### Changed-owner preflight

- Workflow run/job: `34665764441 / 103477222022`.
- Evidence source: `58521f6d1c4fb5d625da7cde50e002cf4688beee`.
- Target: `directional_surface_cell_producer_tests` only.
- Result artifact: `10289560941` (`m4-cp3-cb4-r4-preflight-result-34665764441`), provider/ZIP SHA-256 `289e48f1c8b637f0b165a59df073ef3187dd0829e1f6309a6cf93f9181347342`.
- Diagnostic log artifact: `10289276413`, SHA-256 `df90fdefca367086c2e12a9871677023d8f1a26d0b04ae3ee5150c16a8b412fe`.
- Configure/compile/link: PASS; preflight exit `0`, build exit `0`.
- Exact arithmetic: GMP/GMPXX linked from `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`.
- Source cleanliness: empty status preconfigure, before/after configure, after build and final.
- Boundary: `runtimeExecution=false`; no GTest discovery/listing, `ctest`, test, benchmark, produced binary, CLI, help/version or custom-input runtime executed.

A prior orchestration-only attempt, run `34665672229`, failed at workflow startup with zero jobs because the temporary caller did not initially grant the `contents: write` permission ceiling required by the observer reusable's statically declared branch-file job. The caller permission union was corrected without changing semantic source, target or reusable workflow permissions. This attempt carries no build/runtime credit.

### Full selector-owner package

- Workflow run/job: `34665925501 / 103477693366`.
- Evidence source: `58521f6d1c4fb5d625da7cde50e002cf4688beee` (same source as preflight).
- Compiled targets, exactly eight:
  - `directional_core`
  - `directional_pipeline`
  - `directional_surface_cell_authority_kernel_tests`
  - `directional_surface_cell_producer_tests`
  - `directional_surface_cell_completion_tests`
  - `directional_surface_cell_validation_tests`
  - `directional_compiled_api_tests`
  - `directional_benchmarks`
- Result artifact: `10289601000` (`m4-cp3-cb4-r4-package-result-34665925501`), provider/ZIP SHA-256 `ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9`, `29,764,498` bytes.
- Diagnostic log artifact: `10289551097`, SHA-256 `765424fa9faa277632ff6149b86f84291269d9c443ded7e146a7e40ea70bd58f`.
- Package source archive SHA-256: `b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0`.
- Package `SHA256SUMS`: 28 self-excluding entries, manifest SHA-256 `d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b`; `sha256sum -c` PASS for all 28 entries.
- Four selector-owner executable modes: `755`.
- Four selector-owner executable SHA-256 values:
  - authority-kernel `5efacc3ad52085a8ab76bad451bfc70c337e44a73a8f81a165f06ab1cd3041b3`
  - producer `50402382ba9052ee593cad7482bbdbf50da62f52f1f0dac133be27257a9fa056`
  - completion `1701820d85d91fe674cb3dd3496669f0a49ca43e6068a170fb0277227aba094a`
  - validation `303af6ab231bf88b6b618df03315c9999a27595b8b55871922935f5098a4ca5f`
- Configure/compile/link: PASS; preflight exit `0`, build exit `0`.
- GMP/GMPXX: verified.
- Source cleanliness: verified through every recorded source-status checkpoint.
- Boundary: `runtimeExecution=false`; no test or benchmark execution.

**Tests or benchmarks executed in this Code + Build turn: none.**

## Known Risks

- Runtime correctness of replacement row400 and cumulative selector403 is not yet accepted; compilation alone cannot supply that evidence.
- The package is a candidate only. Package119 / selector394 remains accepted until `M4-CP3-TB2-R2-REV` adjudicates the future artifact-only execution.
- Carried `M4-CP3-TB1-R1-REV-OBS-01` and `M4-CP3-CB4-REV-OBS-02` remain intentionally outside this bounded correction.

## Mandatory Test + Benchmark Plan

- Plan reference: `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md`.
- Evidence commit/artifact under test: `58521f6d1c4fb5d625da7cde50e002cf4688beee` / artifact `10289601000`.
- Focused validation: replacement row400 twice, two independent fresh processes (`1 + 1`).
- Related regression validation: accepted selector394, exactly `394` fresh processes.
- Integration/cumulative validation: successor selector403, exactly `403` fresh processes.
- Total: exactly `799` fresh GTest processes; no discovery-generated process and no benchmark.
- Acceptance: focused `1/1` twice; selector394 `394/394`; selector403 `403/403`; zero RED/SKIP/selection mismatch/timeout; owner partition `30/257/75/41`; immutable package/source/execution-view pre/postflight green.
- Stop/blocker conditions: artifact/source/digest mismatch, manifest failure, selector drift, owner ambiguity, any prerequisite RED, package mutation, compile/relink/discovery generation, or runtime outside the frozen 799-process plan.

## Next Turn

**Type:** Test + Benchmark
**Next subturn:** `M4-CP3-TB2-R2-EXEC`

Execution is artifact-only against immutable package artifact `10289601000`. A green EXEC still requires `M4-CP3-TB2-R2-REV` before any package/selector promotion or A3→A4 work.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`.
- Evidence commit: `58521f6d1c4fb5d625da7cde50e002cf4688beee`.
- Test plan linked: `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Plan.md`.
- Updated: `TODO.md` and live handoff.
- Agent entry-point links: preserved.
- New lesson recorded: none; the stale packaged-test identity is an existing `LESSONS.md` 49 instance, and the caller permission-ceiling correction is orchestration-only.
