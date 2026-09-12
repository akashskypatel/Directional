# M4-CP3-CB4-R4 Code + Build Plan — repair the mandatory packaged-test identity and re-enter compile/package

**Status:** AUTHORITATIVE SUCCESSOR PLAN from `M4-CP3-CB4-R3-REV`
**Turn:** canonical Code + Build
**Runtime:** forbidden
**Accepted runtime authority entering turn:** package119 / selector394 **394/394**
**Candidate semantic source entering turn:** `7fdc3c001de9193f8f94591d3e74d1c94c260195` plus later documentation/control-only commits

## 1. Objective

Repair exactly one derivative build-contract identity omitted when R3 replaced row400, then compile/package the preserved R3 semantic correction without widening product/test/selector scope.

The current configure failure is deterministic: `cmake/DirectionalTests.cmake` requires retired identity
`FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder`, which has zero source definitions after the approved row400 replacement.

## 2. Frozen change

Change only the mandatory identity string in the existing producer packaged-test contract:

```text
OLD: FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
NEW: TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking
```

The containing `directional_require_default_packaged_test_contract(...)` call, expected source path
`tests/FieldAlignedCurveNetworkTests.cpp`, owner target, helper implementation and failure semantics remain unchanged.

### 2.1 Pre-mutation guards

Before editing, re-derive from exact turn source:

- OLD has zero test definitions;
- NEW has exactly one test definition;
- NEW is defined in `tests/FieldAlignedCurveNetworkTests.cpp`;
- that file is a member of `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES`;
- R3 selector403 has exactly 403 LF rows and SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- its first394 equals accepted selector394 byte-for-byte at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- row400 is NEW and maps uniquely to `directional_surface_cell_producer_tests`;
- owner partition is exactly `30 / 257 / 75 / 41`.

After editing, require the CMake packaged-test contract to name NEW exactly once and OLD zero times.

## 3. Frozen semantic/test/selector authority

R4 must not change:

- `src/geometry/EmbeddedGraphTopology.cpp`;
- `tests/FieldAlignedCurveNetworkTests.cpp` or any other test/fixture source;
- `Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt`;
- accepted selector394 or any historical selector;
- A2a/A2b product contracts, exact-path publication, A3 semantics or A4;
- row399, multiplicity `OBS-01`, prescribed-sphere work, or any unrelated cleanup/refactor.

The CMake identity replacement is packaging ownership metadata only. If any additional semantic/build dependency is needed, STOP and return to Review before mutation beyond this one change.

## 4. Compile/package — no runtime

All compilation occurs through the mandatory reusable GitHub Actions compile workflow with exact pushed source and GMP/GMPXX authority. Do not compile locally.

### 4.1 Changed-owner preflight

Compile only:

```text
directional_surface_cell_producer_tests
```

Configure must now prove the NEW mandatory packaged-test identity exists exactly once in the expected producer source.

### 4.2 Full selector-owner package

Only after preflight is green, compile/package:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

Require:

- configure/compile/link exit 0;
- GMP/GMPXX verification;
- exact clean source provenance;
- all four selector-owner executables present;
- recursive self-excluding package manifest verification;
- executable modes preserved;
- `runtimeExecution=false`.

Forbidden in Code + Build: GTest discovery/listing, `ctest`, tests, benchmarks, produced binaries, help/version commands, custom meshes or any other Directional runtime.

## 5. Test plan to hand off after green packaging

If R4 packages successfully, freeze artifact-only `M4-CP3-TB2-R2-EXEC` against that immutable package with exactly:

```text
replacement row400 focused A       1
replacement row400 focused B       1
accepted selector394             394
cumulative successor selector403 403
-------------------------------------
total                             799
```

Each process is a fresh exact filter. Acceptance requires:

- row400 `1/1 PASS` twice;
- independently checkable `1/3` correct versus `2/3` wrong-basis source fixture remains present in packaged source;
- selector394 `394/394 PASS`;
- successor selector403 `403/403 PASS`;
- zero RED/SKIP/selection mismatch/timeout;
- owner partition `30/257/75/41`;
- immutable package/source/execution-view pre/postflight and complete manifest verification.

Green execution still requires `M4-CP3-TB2-R2-REV` before package/selector promotion.

## 6. Stop rules

STOP and return to Review if any of the following is required or observed:

- a second CMake identity or target-membership change;
- any product/test/fixture/selector semantic edit;
- NEW is not uniquely producer-owned in exact source;
- accepted first394 or R3 selector403 bytes differ unexpectedly;
- configure fails for a new semantic/build dependency after the one-name correction;
- GMP/GMPXX or exact-source authority cannot be established;
- packaging requires runtime execution;
- any proposal to weaken/remove a required identity to obtain green.

A failed compile after the one authorized correction may receive only an ordinary compiler-error fix if it is a direct syntactic consequence of that one CMake-line change. Any broader dependency is a Review boundary.

## 7. Closeout requirements

A successful R4 Code + Build turn must record exact evidence commit, run/job/artifact/digests, package manifest proof, source cleanliness, `runtimeExecution=false`, and the executable 799-process TB plan above. It must update TODO/handoff and preserve all WIP through the project work-preservation workflow.
