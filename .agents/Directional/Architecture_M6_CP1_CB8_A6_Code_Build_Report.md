# M6-CP1-CB8-A6 Code + Build Report

**Turn:** `M6-CP1-CB8-A6`
**Authority:** RA-16 amendment in `Architecture_M6_CP1_CB8_A6_HardRail_Placement_Transport_Recovery_Code_Build_Plan.md`
**Final semantic source:** `8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`
**Boundary:** Code + Build only; runtime forbidden and not executed
**Successor:** `M6-CP1-TB8-A6-EXEC` -> mandatory `M6-CP1-TB8-A6-REV`

## 1. Implemented RA-16 scope

The implementation changes only the authorized production/test surfaces:

- `include/directional/pipeline/RemeshPipeline.h`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

`src/geometry/PureQuadCompletion.cpp`, selector/routing files, fixtures, A7, R4 and G4 surfaces are unchanged.

The source now:

1. derives HardRail `canonicalTransport` from the two occurrence-placement coordinate pairs at one common scale, with no `branchRotation` comparison;
2. preserves HardRail carrier semantics in `equivalence.route` / `equivalence.action`;
3. adds `canonicalRelationValue`, canonically inverted independently from `canonicalTransport`;
4. feeds `SelectedRelationStep.appliedTransport` from `canonicalRelationValue`;
5. validates HardRail route authority in A5 through one extracted `exact_interior_route_valid` predicate before owner/region/reversed-pair predicates and preserves legacy `InvalidHardRailAuthority`;
6. strengthens focused 3 and adds focused identity 12, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`.

## 2. RA-16 static lineage proof

RA-16 requires `canonicalRelationValue` to reproduce the pre-CB7 lineage value from source `a532f803bd2f0ef92342652ea3f1a9b64945ba69`.

| Relation kind | Pre-CB7 `a532f803` lineage value | CB8 `8e0818b1` relation value |
| --- | --- | --- |
| OrdinaryFront | `RemeshPipeline.cpp:4117` sets `storageTransport = identity()` | `:4265` sets `storageRelationValue = identity()` |
| HardRail | `:4122-4123` sets `sharedEquivalence.action = first.route.composed_transport()` and stores that action | `:4270-4271` keeps the same action and stores it in `storageRelationValue` |
| exact-A3 Periodic | `:4160-4165` resolves `semanticAction` and stores `firstIsForward ? semanticAction : semanticAction.inverse()` | `:4374-4379` resolves the same `semanticAction` and stores the same orientation-correct value |
| non-A3 Periodic | `:4169-4182` selects exactly one of stored action / inverse by the existing state mapping predicate and stores it | `:4403-4404` keeps the same selected placement/action value and assigns `storageRelationValue = storageTransport` |

CB8 then applies the same canonical direction rule independently to both values: `RemeshPipeline.cpp:4446-4456` inverts `storageTransport` and `storageRelationValue` under the same `storageIsCanonical` predicate. `SelectedRelationStep.appliedTransport` consumes the lineage value at `:4475`, while A6 relation certificates continue to use `canonicalTransport`.

This restores the M5 lineage value without coupling A6 placement transport back to carrier/semantic relation value.

## 3. Static checks

Before remote compilation:

- `git diff --check` passed on the complete source/test patch.
- Exact changed-path set was the three files listed in §1.
- `src/geometry/PureQuadCompletion.cpp` was untouched.
- The existing `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` body was not edited.
- selector449 remained SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.
- selector448 prefix remained SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`.
- routing449 remained SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owner census `32 / 301 / 75 / 41`.
- no A7, R4 or G4 implementation was introduced.

## 4. Patch application and compile-only repair

The RA-16 patch was applied through the authorized Google Drive reusable workflow.

- base `8d800223c981e2e5e9daea0fa99763cc2e70d311`;
- patch SHA-256 `b666f5f230c140e40c0487887a7b1e1b99b1fdbc1859bad19fe0b3859476e01f`;
- apply run/job `37101412649 / 111141538493`;
- semantic commit `2b182f1ca2ea61edd3304030c3cac3def45b69fb`;
- result artifact `11266251548`, digest `sha256:b2b63a19bcfeb1aa19cede73adb6bbaa9bf0658c0d2053ba9e39d02b2cf26b8f`;
- log artifact `11266171700`, digest `sha256:db0735a21e60d0e7ef18adef1a99cf198345cb3a125eb349c41acc4c555e7a0b`;
- `runtimeExecution=false`.

Initial mandatory compile run/job `37101508913 / 111141817614` configured successfully but failed to compile `SurfaceCellTransitionQuotientTests.cpp` because the two new focused-test bodies called `first_edge_of_kind` before its later declaration. This was a declaration-order-only test compile defect; no generated Directional runtime executed.

The bounded repair introduced body-local `firstDraftEdgeOfKind` lambdas only inside those two authorized tests.

- repair patch SHA-256 `f961fe495e6246704e78b027c3bd0e6de83371e8143c72de1e1cf82cbc0666e6`;
- repair apply run/job `37101918608 / 111142995689`;
- repaired source `8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`;
- apply result/log artifacts `11266422503 / 11266347558`;
- digests `sha256:223c73cc285629bd590db0d92bc429f6fb883c8173faf8279036e4831cffcb2f` / `sha256:823376247ce3545902368d0d3ee9bab2acf8e33412fbf1adaec71fbd97f7c5b3`;
- `runtimeExecution=false`.

## 5. Mandatory compile/package result — GREEN

Authoritative compile retry:

- run/job `37101997642 / 111143233041`;
- exact compiled source `8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`;
- all eight standard targets requested and compiled:
  `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`,
  `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`,
  `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`;
- preflight/build/compile status `0 / 0 / 0`;
- GMP discovery found `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, and the authoritative generated test link command contains both;
- package metadata records `exactArithmeticBackend=GMP`;
- all source-status receipts are clean;
- root `SHA256SUMS` is self-excluding and verifies;
- `runtimeExecution=false`; the compile log explicitly states that no generated Directional binary, test, benchmark, discovery, `ctest`, CLI, fuzzer, help/version command or custom input executed.

Candidate/result artifact `11265967968` has digest `sha256:022a35378a58463b892f1bf1d5113f726c2cc7cb8939892b24acd1da62259c4b`. Compile log artifact `11266127622` has digest `sha256:a435590a67884432e848298ab064934b04d39674831340854bfbc2c1bcf474cd`.

## 6. Turn disposition

`M6-CP1-CB8-A6` is compile/package GREEN and runtime-free. The candidate is not promoted by Code + Build. Stable accounting remains **60 / 16 / 44**, debt 1; reviewed runtime authority remains TB5 `10879581622 / 82b86a28...` pending the mandatory recovery gate and Review.

Exact successor is `M6-CP1-TB8-A6-EXEC`: focused identities 1-12 in order, then selector449 in file order with routing449, **461 fresh exact-filter processes**, benchmark 0. Recovery-green is **461/461**, followed by mandatory `M6-CP1-TB8-A6-REV`. R4/A7/G4 remain held.
