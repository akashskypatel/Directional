# M4-CP-SCALE-CB17 — Synthetic Multi-Component Atlas Test-Authority Repair Code + Build Plan

**Turn:** `M4-CP-SCALE-CB17`
**Type:** Code + Build
**Authority:** `M4-CP-SCALE-TB12-R3-REV`
**Semantic scope:** **TEST SOURCE ONLY**
**Runtime boundary:** **NO generated Directional runtime**; compile/package only, `runtimeExecution=false`

## 1. Goal

Repair the invalid fourth TB12-R3 Gate-A control without changing the CB16 product correction or the production S5 witness. The replacement must prove the exact subject the gate claims: a positive synthetic `FieldTransportAtlas` integration case whose independently derived **boundary algebraic row contains at least two closed successor components before atlas construction**.

The preferred bounded repair is to restore/adapt the pre-CB16 test-local `make_two_interior_islands_disk()` witness and `OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow` identity to the current independent canonical-component oracle. That historical test independently derived a boundary row with **6 support edges / 2 components** before calling `FieldTransportAtlas::make`; CB17 must preserve or strengthen that non-vacuity property.

## 2. Frozen authority

- Accepted runtime authority remains package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**.
- CB16 candidate artifact `10523132151` / source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9` remains unpromoted.
- The CB16 production correction in `src/authority/FieldTransportAtlas.cpp` is frozen in this turn.
- TB12-R3 valid direct controls remain frozen in meaning:
  1. `IndependentCycleOrderingOracleHandlesMultipleClosedComponents`
  2. `PreservesSingleComponentCanonicalCycleSequence`
  3. `IndependentOracleRejectsCycleOrderingTamper`
- The unchanged production S5 identity `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` is frozen.
- Selector426, first425, retained genus-two OBJ/rawfield/metadata and all accepted selectors are byte-frozen. No selector427.
- Stable accounting remains **49 / 14 / 35**, debt **5**. No runtime credit is possible in Code + Build.

## 3. Authorized source change

Only `tests/FieldTransportAtlasTests.cpp` may change semantically.

Required correction:

1. Remove/replace `BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport` as a Gate-A acceptance control. It is invalid because it uses all-zero component/sheet labels plus empty hard-feature authority on a connected closed genus-two source, then requires a `BoundaryLoop` subject that its own source authority does not establish.
2. Restore/adapt a synthetic integration fixture equivalent to `make_two_interior_islands_disk()`.
3. Before calling `FieldTransportAtlas::make`, derive cycle facts independently from the mesh/field authority and assert:
   - a `FieldCycleKind::BoundaryLoop` row exists;
   - its support is non-empty and exact;
   - `independent_canonical_component_order` succeeds;
   - the support contains exactly **6** directed support steps and exactly **2** closed successor components, unless Review is reopened with independently derived evidence justifying a different synthetic witness.
4. Call `FieldTransportAtlas::make` on that same authority and compare the published boundary steps to the independently derived canonical order. Every support edge must appear exactly once.
5. Run the independent snapshot validator on the resulting atlas. It must remain producer-independent and reject the existing tamper controls.
6. Preserve the single-component sequence control exactly in meaning.

Test-only include/helper cleanup made unnecessary by removing the retained-genus-two test is allowed inside `tests/FieldTransportAtlasTests.cpp`.

## 4. Product and witness surfaces explicitly forbidden

CB17 must not modify:

- any `src/**` or public `include/**` file;
- `tests/FieldAlignedCurveNetworkTests.cpp` or the S5 focus;
- `dual_cycles`, field transport coefficients, turning lifts, raw-field finalization or product semantics;
- `benchmarks/fixtures/milestone-g/genus_two.obj`, `.rawfield`, `.fixturemeta.json` or their generator to make the test pass;
- CMake/benchmark semantics;
- selector426 or any earlier selector;
- any selector427 publication.

If the corrected synthetic integration identity cannot be authored without one of those changes, **STOP and return to Review**.

## 5. Required compile/package gate

Compile only through `.github/workflows/agent-compile-reusable.yml`, Release/static/Ninja/PRE_TEST with mandatory GMP/GMPXX, using the standard eight targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Require zero preflight/configure/build exits, authoritative GMPXX+GMP link evidence, clean source-status snapshots, recursive self-manifest verification, preserved executable modes, exact selector426/first425 and retained genus-two fixture hashes, and `runtimeExecution=false`.

No generated Directional test, benchmark, CTest, discovery/list/help/version command or custom runtime input may execute in CB17. A compile-green package is only a candidate.

## 6. Falsifiers and stop rules

STOP without broadening scope if any of the following occurs:

- the replacement gate still requires a `BoundaryLoop` without independently proving that row exists on the exact authority supplied to the atlas;
- the multi-component count is inferred from the atlas's published steps rather than independently from pre-build sparse-row support;
- the positive integration witness does not independently establish at least two closed successor components;
- the witness becomes green by changing product source, `dual_cycles`, field coefficients, fixture/rawfield bytes, source-region production authority, or the S5 test;
- direct controls 1–3 are removed, weakened, made vacuous or made self-authorizing;
- the single-component canonical sequence changes;
- an open component, duplicate origin/support, invalid directed adjacency, dropped edge or non-canonical component order is accepted by the independent validator;
- selector426 changes or selector427 appears;
- any generated Directional runtime occurs in Code + Build;
- the standard GMP/GMPXX eight-target compile/package gate is not clean.

## 7. Conditional handoff after a valid compile

A valid CB17 closeout may freeze a later artifact-only `M4-CP-SCALE-TB12-R4-EXEC` plan, but CB17 itself grants no runtime authority. That later turn must consume the immutable CB17 artifact unchanged and execute, in fail-fast order:

1. the three already-valid direct component-order controls;
2. the corrected synthetic two-component atlas integration control;
3. only if Gate A is 4/4, the unchanged S5 genus-two focus;
4. only if S5 is green, selector426 in exact frozen order;
5. benchmark execution only if separately frozen by that TB plan.

Any semantic runtime result still requires mandatory independent Review before S5/selector credit, candidate closure or package promotion.
