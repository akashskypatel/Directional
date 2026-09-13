# M4-CP3-CB10 Code + Build Report — hard-rail fixture migrated to production A2b/A3 authority

**Turn:** `M4-CP3-CB10`
**Type:** Code + Build only; runtime-free
**Status:** **COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED**
**Owner:** `M4-CP3-TB7-REV-CAND-01`
**Accepted runtime authority entering/leaving:** corrected R4 package `10289601000`, selector403 **403/403**
**Candidate package:** artifact `10307919492`, semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`

## 1. Guard disposition

All four pre-mutation guards from `Architecture_M4_CP3_CB10_Code_Build_Plan.md` passed.

- **G1 — GREEN.** Accepted R4 selector403 is 403/403 and contains ordinal211. The pre-edit `tests/SurfaceCellTransitionQuotientTests.cpp` bytes were the Review-frozen `4372a939fc1bc356e7753fa4c40e4ce269b04fcd59ba037513665add6a982f25`; selector403/408 identity files remained unchanged at `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` and `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.
- **G2 — GREEN.** The legacy `make_hard_rail_fixture()` manually supplied hard-rail network authority directly to `build_surface_cell_network()` without accepted `GlobalTopologyPlan` / `GlobalConformityBaselinePlan`; therefore the A3-owned `sharedBoundaryInterval` identity was absent and production correctly rejected `InvalidHardRailPairing` before ordinal211's intended tamper.
- **G3 — GREEN.** Frozen M4 authority makes A3 the exact shared-subdivision writer. Restoring floating `support_key`, inventing no-plan pairing, or weakening missing-interval rejection would violate the A3→A4 contract and was not done.
- **G4 — GREEN.** The existing `remesh_from_raw_cross_field(..., SurfaceCells)` retained-intermediate path accepts user hard edges and publishes the required source labels/topology regions, global topology plan, global conformity baseline, authoritative rails, and trace network. It can preserve the same 3×3 source mesh and hard-edge support without a second semantic dependency.

## 2. Implemented change

Only `tests/SurfaceCellTransitionQuotientTests.cpp` changed semantically.

`make_hard_rail_fixture()` now:

1. retains the same 3×3 planar mesh and the same hard edges `(1,4)` and `(4,7)`;
2. constructs `RemeshOptions` for the direct `SurfaceCells` backend with fallback `Fail`, source-grid recovery disabled, intermediates retained, and the same raw cross field;
3. supplies the two hard edges through `surfaceCells.featureMap.userHardEdges`;
4. calls the production `remesh_from_raw_cross_field(...)` path;
5. requires retained source labels, source topology regions, field-aligned network, global topology plan, global conformity baseline, authoritative rails, and trace network before exposing the fixture;
6. copies the production-created component/sheet/network authority and keeps the existing `require_produced` gate.

The old manual hard-rail construction made obsolete by this migration was removed. No production source under `src/` or `include/` changed.

The six downstream identity names and test bodies remain unchanged:

- ordinal211 `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`;
- ordinal217 `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- ordinal219 `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected`;
- ordinal227 `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed`;
- ordinal230 `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed`;
- ordinal231 `SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity`.

Post-edit test-file SHA-256 is `e150c73668e69079b1f5bdf5b51e49aa0dbe18595af079ec616f58bec1a2e2ec`. Selector403/408 bytes and hashes are unchanged.

## 3. Work preservation and source authority

The semantic edit was preserved before remote mutation as one complete Git patch:

- patch SHA-256: `e70a522016c77fda177d821fd64f8da62ac2f393de88d38d806ed05262e575a9`;
- diff-body SHA-256: `05acfca20c1e1b6e00144045e2b09558f89dcd6704d9ca815625e6a46266b9fa`;
- exact patch base: control head `5ede97218103bb3e3cdb70a7b36f6c527d134db0` (semantic parent `ec7c7b2b4d21f5c66aa6c459390cbff4ad8a6986` plus the source-snapshot trigger only).

The Drive apply workflow committed the semantic change as `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`. The staged Drive patch was then permanently retired through the owner-authorized Drive connector.

Start-of-turn source snapshot authority was run `34726887356`, snapshot job `103642475627`, artifact `10307584339`; its provider digest is `e870a7341d306841c50df3bdf3b4640bbf15939edf3860fbf3741908643cdd50`, archive SHA-256 `3d0538a393c130f12a8605b4af0222ed2d5812ccada3ef6badfedbf0cb2f262d`, `runtimeExecution=false`.

## 4. Compile/package evidence

Compile workflow run/job: `34727247774 / 103643462175`.

The mandatory reusable workflow checked out exact semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a` and compiled/linked exactly these eight targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Result: **GREEN**.

Compile result artifact `10307919492` has provider digest `8988a12fa8b2e6476bf3fd91a6a6936eaef8a9ab7c73837b74ea2e980d29b2ec`. Compile log artifact `10307949270` has provider digest `f07c66d168d6baacaf3074f789faa0b5581c2a2eadd72c640577220cfa6e4c8a`.

Independent static artifact verification found:

- package root `SHA256SUMS`: **28/28 PASS**;
- exact source commit recorded correctly;
- preflight and build exit codes: `0`;
- all eight required targets present;
- source status before/after/final empty;
- `runtimeExecution=false`;
- exact arithmetic backend `GMP` with `GMPXX` and `GMP` libraries present on authoritative link evidence;
- packaged binaries/libraries present for the exact owner set;
- selector403/408 hashes unchanged.

No Directional test, benchmark, generated binary, or packaged executable was run in CB10.

## 5. Disposition

CB10 is **COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED**. The new package is a candidate only. Corrected R4 artifact `10289601000` remains the accepted M4-CP3 runtime authority until TB8 Review adjudicates the candidate.

Stable accounting is unchanged by this runtime-free turn at **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. CP3 and `G4-B002` remain OPEN.

**Exact successor:** `M4-CP3-TB8-EXEC`, followed mandatorily by `M4-CP3-TB8-REV`. TB8 must consume the immutable CB10 package under `.agents/Directional/Architecture_M4_CP3_TB8_Artifact_Only_Test_Benchmark_Plan.md`.
