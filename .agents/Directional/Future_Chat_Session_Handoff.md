# Future Chat Session Handoff

## Mandatory next turn

Run **M1a Authority Kernel Core — immutable Test + Benchmark** under:

`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1a authority kernel core**;
- review policy: `never`;
- production behavior delta from M1a Code + Build: **none**.

M1a compile/package authority is complete. **Do not edit or rebuild in the next turn.** Consume only the immutable artifacts below. M1b remains blocked until M1a semantic runtime acceptance passes.

## Completed M1a Code + Build

Authoritative report:

`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Code_Build_Report.md`

Exact authority:

| Evidence | Value |
|---|---|
| Entering branch head | `9f1d3ebd91403252e990f785c3521588197b4fd4` |
| M1a implementation | `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7` |
| Build/event commit | `a29c1f673ea93e1614751f42a0c1fef94d23e1fe` |
| Workflow run/job | `31327073928 / 93279043100` |
| Result artifact | `9041930767` |
| Result SHA-256 | `1c1325c038ffe26b80e00dbb69fb15de8b0d0a42673d9720f28bcd9de8549ec5` |
| Log artifact | `9041930871` |
| Log SHA-256 | `e99e053ea4503b720dbe9b6c9ed4762a4eedcbf67c15261e8ea4317824c427cb` |
| Recursive manifest | **53/53**, `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6` |
| Package regular files | **54**, including manifest |
| Compile closure | Release/static/Ninja **120/120**, `PRE_TEST` |
| Build wall / peak RSS | **8:14.63 / 1,835,984 KiB** |
| Runtime execution | **false** |
| Retention | through **2026-08-23 UTC** |

The package has seven ELF executables, two static libraries, all 27 fixtures, exact patch/source archive/compile DB/source blobs, a static 14-name authority-kernel manifest, the unchanged 29-name T1 oracle manifest, toolchain/submodule records, and explicit command-boundary metadata.

Temporary GitHub Action/trigger files were removed after artifact capture.

### Exact M1a implementation boundary

From entering head to implementation, exactly eight paths changed:

1. `cmake/DirectionalTests.cmake`;
2. `include/directional/authority/AuthorityIds.h`;
3. `include/directional/authority/CanonicalRoute.h`;
4. `include/directional/authority/GridAutomorphism.h`;
5. `include/directional/authority/LegacyAuthorityAdapters.h`;
6. `include/directional/authority/SourceSupport.h`;
7. `src/authority/AuthorityKernel.cpp`;
8. `tests/SurfaceCellAuthorityKernelTests.cpp`.

No `CMakeLists.txt`, production geometry/pipeline/validation/benchmark source, fixture, T1 direct-acceptance source, or T1 oracle source changed. `AuthorityKernel.cpp` is linked only into the new authority-kernel test target in M1a; no real production consumer is migrated yet.

M1a introduces:

- strong non-interconvertible semantic ID types;
- typed `DomainError` and named checked legacy conversions;
- canonical `SourceEdgeTopologyKey` and explicit `Orientation`;
- tagged `SourceSupport`;
- exact `QuarterTurn` (`Z4`), integer `LatticeTranslation`, and `GridAutomorphism` identity/composition/inverse/application;
- `TransitionStep` with topology + optional interior transition + transport + orientation;
- canonical/reversible `CanonicalRoute`;
- one-way compatibility adapters;
- new default-built `directional_surface_cell_authority_kernel_tests` with labels `contract-required;authority-kernel`.

### Static authority packaged

The authority-kernel manifest has exactly **14** names:

1. `SurfaceCellAuthorityKernel.StrongIdsAreStaticallyNonInterconvertible`
2. `SurfaceCellAuthorityKernel.CheckedLegacyConversionAcceptsAndRejectsDomainErrors`
3. `SurfaceCellAuthorityKernel.NumericCoincidenceDoesNotConflateDomains`
4. `SurfaceCellAuthorityKernel.SourceEdgeCanonicalizationPreservesExplicitOrientation`
5. `SurfaceCellAuthorityKernel.SourceSupportAlternativesRemainTypeDistinct`
6. `SurfaceCellAuthorityKernel.QuarterTurnNormalizesAndCyclesExactly`
7. `SurfaceCellAuthorityKernel.GridAutomorphismIdentityInverseAndAssociativityAreExact`
8. `SurfaceCellAuthorityKernel.NonzeroRotationTranslationRoundTripIsExact`
9. `SurfaceCellAuthorityKernel.BoundaryStepWithoutInteriorTransitionIsValid`
10. `SurfaceCellAuthorityKernel.InteriorStepRequiresNamedInteriorTransition`
11. `SurfaceCellAuthorityKernel.CanonicalRouteReversalRoundTripIsExact`
12. `SurfaceCellAuthorityKernel.RepresentationHandlePerturbationDoesNotChangeCanonicalRoute`
13. `SurfaceCellAuthorityKernel.LegacyAdapterRoundTripPreservesSemanticValue`
14. `SurfaceCellAuthorityKernel.DeliberateCrossDomainAdapterMisuseIsRejected`

Static manifest SHA-256: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`.

The accepted T1 oracle manifest remains exactly **29** names, SHA-256 `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

### No-production-delta compile evidence

All eight pre-existing T1 binaries/libraries are byte-for-byte identical in M1a artifact `9041930767`, including `libdirectional_core.a`, `libdirectional_pipeline.a`, compiled API, producer, oracle, completion, validation, and benchmark executables. Only the authority-kernel test executable is new.

This is compile/package evidence only. Do not claim M1a semantics accepted before runtime.

## Mandatory next-turn runtime procedure

Preflight:

1. verify result/log outer hashes exactly;
2. reject unsafe archive paths;
3. verify **53/53** package members and manifest digest;
4. verify exact source/commit/inventory/dependency authority and `runtimeExecution=false`;
5. compare the eight pre-existing binaries/libraries against accepted T1 artifact `9041289209` and require byte identity;
6. add at most a non-regular runtime locator such as `bin/test-data -> ../test-data`; mutate no packaged regular file.

Authority kernel:

1. discover `directional_surface_cell_authority_kernel_tests` **exactly once**;
2. require exact match to the 14 immutable names;
3. run all 14 individually in fresh processes;
4. require **14/14**, with intended positive/counterexample/metamorphic semantics—not compilation/no-crash as proof.

T1 preservation:

1. discover `directional_surface_cell_oracle_tests` exactly once and match its same 29-name manifest;
2. run all 29 individually and require **29/29**;
3. run Plane, MultiFaceSeam, CloseSheets, Cylinder in fresh processes and require the accepted green/oracle-clean behavior;
4. run BunnyRandom and Vase as explicit known-red comparison cases: Bunny must retain independent-oracle-before-fatal-success behavior if it returns; Vase gets a bounded 60 s guard and timeout is safety evidence only;
5. never disable, expected-failure-convert, or count known-red cases green.

Postflight re-hashes both original ZIPs and all package regular files. If anything fails, report without source repair in that Test + Benchmark turn.

Only after immutable **14/14 + 29/29 + preserved direct comparison authority** may M1b be planned. M1b must migrate exactly one real production consumer through the new authority kernel with an explicit legacy rollback boundary.

## Regression-pattern authority

Read `.agents/Directional/Regression_Root_Cause_Tracker.md` before execution.

M1a touched:

- `RP-01`: strong domains + named checked conversion;
- `RP-05`: semantic identity excludes representation handles; orientation explicit;
- `RP-07`: exact modulo-4/cycle/reversal algebra;
- `RP-02`: preservation boundary only; T1 independent oracle/package authority must remain accepted.

`RP-03`, `RP-04`, `RP-06`, `RP-08`, and `RP-09` are untouched.

M1a is new architecture and is currently **pending immutable acceptance**, not a new production regression. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unaffected.

## Accepted T1 comparison authority

T1 artifact `9041289209`, implementation `7c169ddf...` remains the accepted test/product comparison boundary:

- oracle **29/29**;
- retained focused **18/18**;
- bounded producer/completion/validation/API **154/163**, **154/164**, **71/71**, **8/8**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green/oracle-clean;
- BunnyRandom known-red `NotProductionReady:completion`, independent oracle first;
- Vase bounded 60 s nonreturning/safety-only.

## Production authority remains known-red

Production G4 authority remains artifact `9031804178`, implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49`:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`;
- `PR8-R034 / G4-R007` stays **active**.

Do not infer a new torus root cause from M1a authority-kernel work.

## Core references

- `.agents/Directional/DESIGN.md`, especially sections 6.1–6.4;
- `.agents/Directional/REORIENTATION_PLAN.md`, M1;
- `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`;
- `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`;
- `tests/TESTING_STRATEGY.md`.

## Deferred blockers

- active representative torus `G4-R007`;
- shared hard-rail scheduling `G4-B002`;
- nonzero periodic `Z4` production capability `G4-B003`;
- positive multi-isolation witness `G4-B004`;
- historical transition-quotient/completion failures;
- strict-validator timing;
- prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization;
- M1b–M6 and T2–T6.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
