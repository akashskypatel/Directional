# M4-CP3-CB6 Code + Build Plan — exact-torus hard-rail reachability witness correction

**Status:** FROZEN / AUTHORIZED AFTER `M4-CP3-TB3-REV`
**Turn:** `M4-CP3-CB6`
**Canonical turn:** Code + Build
**Runtime in this turn:** FORBIDDEN
**Accepted entering runtime authority:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Unpromoted cutover package:** CB5 artifact `10290933668` / selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`

## 1. Objective

Repair only the row408 exact-torus **fixture precondition** exposed by TB3 Review. The witness must enter production with explicit hard-feature rail authority so it actually reaches the A3→A4 typed shared-boundary seam it claims to test.

CB6 is **not** authorization to change A2b, A3, A4, pairing semantics, feature classification, rail construction, fallback policy, accepted selector403, or the four green CB5 identities 404-407.

## 2. Entering review facts

TB3 run/job `34671972132 / 103494923768` is valid artifact-only evidence. Rows404-407 pass; row408 fails before its cutover assertions because `phaseFront.disposition()` is `NotApplicable`. Current `cp4c_remesh_options()` supplies no explicit hard-feature edges. In the production aggregate phase-front code, this observed `NotApplicable` path after regional producer decline is the no-hard-feature branch; a hard-feature region would fail closed rather than silently return `NotApplicable`.

The row408 RED is therefore TEST-AUTHORITY / FIXTURE-PRECONDITION + REACHABILITY DRIFT, not evidence of accepted product behavior loss. Stable totals remain `47 / 14 / 33`, debt `5`.

## 3. Mandatory pre-mutation reachability guard

Before changing test/build source, independently re-open `benchmarks/fixtures/milestone-g/torus.obj` and prove all of the following statically:

1. the committed mesh remains exactly V/E/F `72/216/144`, closed genus 1;
2. every consecutive pair in each frozen 0-based source-vertex cycle below is a real source edge:

```text
C_minor = 0-3-25-37-49-61-0
C_major = 0-1-4-6-8-10-12-14-16-18-20-22-0
```

3. each cycle is simple except for closure, the two cycles intersect only at vertex `0`, and they represent the two independent torus directions (constant major-angle versus constant minor-coordinate in the committed geometry);
4. their union has the topology of a one-vertex two-loop cut graph whose complement on the torus is a disc;
5. `AdaptiveFeatureMapOptions::userHardEdges` is a direct authoritative ingress for these exact source-edge pairs, and production `build_authoritative_surface_cell_rails(...) -> hard_feature_edge_keys_from_rails(...) -> tracingOptions.hardFeatureEdges` preserves hard-feature ownership without geometric inference;
6. no product/source semantic change is needed merely to supply this explicit fixture authority.

### Guard stop

If any listed pair is not a committed source edge, the cycles do not form the stated homology basis/cut graph, explicit hard edges cannot be carried by the existing production feature/rail path, or product source would need modification to make the fixture reach A4, **STOP before mutation and return to Review**.

## 4. Authorized test-only correction if the guard passes

Make the smallest sufficient change in `tests/FieldAlignedCurveNetworkTests.cpp`:

1. add a dedicated torus-hard-rail option/helper used only by row408 (or an equally narrow fixture parameter) that starts from `cp4c_remesh_options()` and inserts exactly the frozen `C_minor ∪ C_major` edge pairs into `options.surfaceCells.featureMap.userHardEdges`;
2. keep row408's required identity name unchanged:
   `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`;
3. strengthen row408's preconditions so a green result cannot be vacuous:
   - retained authoritative rails exist;
   - at least one retained rail is `HardFeature`;
   - the retained topology/baseline/trace network exist;
   - phase-front disposition is `Produced`;
   - the phase-front conformity receipt exactly equals retained A2b/A3 semantic digests;
   - at least one `HardRail` edge exists and every such edge has `sharedBoundaryInterval`;
   - terminal detail is not `InvalidHardRailPairing`;
4. do not weaken `family`/`advanceSign`, exact interval, route or factory validation to make the witness green;
5. do not change rows404-407 or accepted-prefix identities.

The witness may report enough success-path census to let the later TB prove it actually carried hard rails. It must not derive expected shared identity from subject output.

## 5. Selector/build-contract rules

- Keep `.agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt` byte-identical if row408's identity name remains unchanged.
- Accepted selector403 must remain byte-identical as rows1-403.
- Owner mapping must remain exactly **30 / 262 / 75 / 41**, with row408 uniquely producer-owned.
- `cmake/DirectionalTests.cmake` must not change unless the unchanged row408 identity unexpectedly reveals a literal packaged-test ownership defect; any such second dependency is a STOP/Review event, not scope to absorb.

## 6. Compile/package verification

No local build and no Directional runtime.

Compile only through `.github/workflows/agent-compile-reusable.yml` with GMP/GMPXX and `runtimeExecution=false`:

1. producer changed-owner preflight;
2. full frozen eight-target package compile;
3. clean source status;
4. package manifest self-check and owner executables present/executable;
5. selector408/selector403 hash and exact-prefix recheck;
6. no GTest discovery/listing, `ctest`, produced test/benchmark execution, CLI/help/version, fuzzer or custom-input runtime.

## 7. Frozen stop conditions

STOP and return to Review if:

- the §3 static guard fails;
- any production source/header needs mutation;
- the accepted A3 schedule or A2b source-path semantics would need modification;
- row408 would need tolerance/rounded geometry or fallback authority to become reachable;
- accepted selector403 or rows404-407 would need change;
- another product/build/test dependency appears;
- compile reveals anything beyond this single fixture-precondition correction.

## 8. Future artifact-only acceptance

If CB6 packages green, the successor TB must consume only that immutable package and execute the **entire frozen gate from the beginning**, not resume after the old row408 stop:

```text
corrected row408 focused A   1
corrected row408 focused B   1
rows404-407 focused control  8  (A+B, proving no collateral loss)
accepted selector403       403
candidate selector408      408
```

Total: **821 fresh exact-filter processes**, preserving the original TB3 cardinality and phase semantics. A later Review, not TB-EXEC, decides promotion and CP3 closure.

## 9. Exit

CB6 closes only with either:

- **GUARD STOP:** no semantic/test mutation and precise evidence that the frozen explicit torus hard-rail precondition is not statically valid; or
- **BUILD GREEN:** test-only row408 fixture correction, unchanged selector identities/ownership, and a new immutable GMP package, still runtime-unproved.

No runtime or CP3 promotion occurs in CB6.
