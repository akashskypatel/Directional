# M4-CP3-CB3 Code + Build Report — test-authority recovery for the §17 parity baseline

**Status:** COMPLETE / TEST-ONLY SOURCE REPAIR / PREFLIGHT + PACKAGE COMPILE GREEN / RUNTIME-FREE
**Turn:** `M4-CP3-CB3`
**Execution mode:** canonical Code + Build
**Normative definition:** `Architecture_M4_DEFN_Frozen_Definitions.md` §17
**Accepted runtime predecessor:** package117 / selector382 **382/382**
**Prior candidate:** package118 / selector394 **387/394**, unpromoted
**Post-build candidate designation:** package119 / selector394, unpromoted
**Exact semantic source under test:** `fd532c2f768d0ff6493260deb670cb34b6757712`
**Exact next:** `M4-CP3-TB1-R1-EXEC`

## 1. Implemented

CB3 executed the frozen test-authority recovery control experiment without changing production source, selectors, fixtures, CMake/build logic, reusable workflows, or §17 semantics. The only semantic test-source change is `tests/GlobalConformityBaselineTests.cpp`.

The repair:

1. replaces `make_triangle_mesh()` with the prescribed DCEL-valid four-vertex / three-face triangular-boundary disk while retaining exactly the three original source-boundary terminals;
2. changes ordinal392's unit-edge target size to `0.25`, independently forcing preferred count `4` and therefore a final count of `4` or `3` under §17.6;
3. makes ordinal390's exhaustive oracle faithful to region-incidence multiplicity, including zero-effect same-region double incidences, and exposes `assignmentsExamined`, `parityFeasibleAssignments`, and the live multiplicity matrix;
4. strengthens ordinal389 to select and assert the live preferred/final `1 -> 2` and `2 -> 1` cases by semantic values rather than incidental vector position;
5. counts all nine ordinal391 tamper-validator executions and requires `tamperRows == 9`;
6. preserves ordinal392's forward/reverse exact-ordinal and denominator checks while adding the frozen preferred-count precondition;
7. emits deterministic `M4_CP3_BASELINE_RECEIPT ordinal=<N> ...` lines from live values after intended assertions for ordinals 386, 388, 389, 390, 391, 392 and 394.

No product algorithm was modified to satisfy the repaired tests.

## 2. Engineering-guideline review

- **Material assumptions surfaced:** the triangular helper must remain a three-terminal disk; ordinal390 must model per-region incidence multiplicity rather than a single global XOR; ordinal392's `count > 1` must follow independently from fixture geometry/target size.
- **Simplest sufficient approach:** one test translation unit only, preserving all production and selector authority.
- **Why no smaller approach satisfies the contract:** changing only the triangle fixture would leave ordinal390's oracle unsound for possible interior self-loop spans; changing only ordinal392's expected output would preserve its invalid precondition. The frozen plan therefore requires both fixture correction and non-vacuity hardening.
- **Unrelated refactors/style drift avoided:** yes.
- **Every changed semantic line traces to the frozen CB3 objective/supporting validation:** yes.

## 3. Files changed

Semantic Code + Build source:

- `tests/GlobalConformityBaselineTests.cpp`

Turn-closeout documentation is recorded separately from the compiled semantic source and does not alter package119 binaries.

## 4. Domain invariants preserved

- §17 family/sign-free shared-subdivision + region-parity semantics are unchanged.
- Strict `TriMesh` / DCEL consistency is unchanged; no test-only product bypass exists.
- Region parity is evaluated from boundary incidences with multiplicity; same-region double incidence has zero parity effect modulo two.
- Exact minimum-cardinality parity optimization and canonical lex-prefix semantics are unchanged.
- Accepted selector382 rows are unchanged and remain the exact prefix of selector394.
- Package117 / selector382 remains accepted runtime authority until TB review explicitly promotes a successor.
- Production A3→A4 cutover remains forbidden in this turn.

## 5. Generalization review

This repair is not fixture-specific product behavior. It makes the tests themselves satisfy production preconditions and independently model the frozen parity definition. The triangular helper is a valid disk for every consumer of that helper, while the oracle derives region/span incidence multiplicity from the live topology instead of assuming a one-terminal-per-span shape. The receipt values are read from live objects after the intended assertions execute; they are not detached pass markers.

Regression risks considered:

- new interior triangle edges becoming spans;
- same-region self-loop multiplicity in the independent oracle;
- schedule ordering changing after the valid fixture is introduced;
- lex refinement choosing either allowed ordinal392 final count;
- vacuous custom receipts that could be emitted without executing intended assertions.

## 6. Source and selector authority

GitHub comparison from package118 semantic source `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc` to CB3 semantic source `fd532c2f768d0ff6493260deb670cb34b6757712` shows no `src/` product-source change attributable to CB3. The only semantic code/test mutation is `tests/GlobalConformityBaselineTests.cpp`; intervening differences are documentation/control-plane history.

Packaged selector authority was re-hashed from the candidate source archive:

```text
selector394 rows              = 394
selector394 SHA-256           = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector394 first382 SHA-256  = 1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f
```

Both match the frozen authorities exactly.

## 7. Work preservation and source application

Before remote application, the complete test-only semantic diff was emitted and verified as:

```text
Directional__M4-CP3-CB3__base-28666c847089__work-preservation.patch
SHA-256 = e2ca8228625bf4f77471a81acf2aa6585b9c92a89ab8718ce9e6669eda195ec1
diff-body SHA-256 = 622f60387d1102ec093a8954a0f5ef4a0c35783fbbef468e53125391e9928a85
```

The Drive apply run/job `34563736366 / 103151647274` applied those exact bytes and produced semantic source `fd532c2f768d0ff6493260deb670cb34b6757712`. Result artifact `10185254954` verified the apply. The consumed Drive patch was permanently deleted after successful source application.

## 8. Build evidence

### 8.1 Required owner preflight

The changed owner target was compiled first, by itself, from the exact semantic source:

| Evidence | Authority |
|---|---|
| workflow run | `34563902380` |
| compile job | `103152000174` |
| semantic source | `fd532c2f768d0ff6493260deb670cb34b6757712` |
| target | `directional_surface_cell_producer_tests` |
| result artifact | `10185317910` |
| result artifact SHA-256 | `64b8279ea3d2c67ef45d39bdca586188f7979740fde000e9f8fb1b7c21568d08` |
| log artifact | `10185318261` |
| log artifact SHA-256 | `12f8790de7acb2bafcea14591649c536f0ef7680b00c39ae527a736734cb788e` |

Result: **PASS**, link exit `0`, mandatory GMP/GMPXX present, clean source, `runtimeExecution=false`.

### 8.2 Full package compile

The same semantic source then compiled the complete approved package surface:

| Evidence | Authority |
|---|---|
| workflow run | `34564069513` |
| compile job | `103152491832` |
| semantic source | `fd532c2f768d0ff6493260deb670cb34b6757712` |
| package artifact | `10185370005` — `m4-cp3-cb3-package-result-34564069513` |
| package ZIP SHA-256 | `9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8` |
| compile-log artifact | `10185370244` |
| compile-log SHA-256 | `5287155c1d96f03ea64b4faff02dcc54f33298f76b81160d581a5b5a8f176cb5` |

All approved targets linked:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Package verification established:

- provider digest equals downloaded ZIP SHA-256;
- recursive self-excluding `SHA256SUMS` verifies **28/28** package entries;
- `metadata/source-commit.txt` is exactly `fd532c2f768d0ff6493260deb670cb34b6757712`;
- all packaged source-status files are empty;
- `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`;
- GMP evidence contains both `gmpxx` and `gmp` in the authoritative link command;
- packaged source retains the exact selector394 and selector382-prefix hashes above.

No generated Directional test binary, benchmark, `ctest`, test discovery/list, CLI, fuzzer, help/version command, or custom Directional input was executed in CB3.

## 9. Known risks and deferred evidence

Compile success does **not** prove the repaired runtime contracts. In particular, CB3 does not yet prove that:

- all seven corrected identities reach their intended success path;
- ordinal390's exhaustive oracle agrees with production on the instantiated live topology;
- ordinal391 actually reaches all nine tamper rows at runtime;
- ordinal392 consumes both interior breakpoint directions with a final count greater than one;
- selector394 is 394/394 runtime green.

Those are explicitly owned by the successor artifact-only TB.

## 10. Mandatory Test + Benchmark plan

Plan: `Architecture_M4_CP3_TB1_R1_Test_Benchmark_Plan.md`.

The successor validates immutable package119 artifact `10185370005` without rebuilding. It must execute:

1. selector rows 383-394 in fresh processes, focused pass A;
2. the same rows again as focused pass B with identical ordered verdict and receipt vectors;
3. accepted predecessor selector382, expected **382/382**;
4. cumulative selector394, expected **394/394**;
5. immutable pre/post package/source/execution-view censuses and full manifest verification.

For corrected ordinals 386/388/389/390/391/392/394, focused runs require exactly one matching success-visible receipt per process, with plan-defined parsed invariants. A green selector without the required receipts is insufficient evidence.

Benchmarks: **not applicable**; this change has no performance acceptance metric.

## 11. Next turn

Type: Test + Benchmark, execution subturn only.

**Exact next:** `M4-CP3-TB1-R1-EXEC`.

TB-EXEC performs runtime execution and raw evidence preservation only. Diagnosis, regression classification, candidate promotion, and successor planning belong to the later `M4-CP3-TB1-R1-REV` boundary.
