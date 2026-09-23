# M5-CP3-CB16 Code + Build Report

**Turn:** `M5-CP3-CB16`
**Boundary:** runtime-free Code + Build
**Disposition:** **COMPLETE / COMPILE GREEN / RUNTIME UNPROVED**
**Exact successor:** `M5-CP3-TB1-R14-EXEC`

## 1. Entering authority

CB16 implements only the bounded correction frozen by `M5-CP3-TB1-R13-REV` and `Architecture_M5_CP3_CB16_Occurrence_Branch_Gauge_Authority_Correction_Plan.md`.

R13 had mechanically complete **445/447 PASS** evidence with selector430 **430/430**. Produced rows4/5 alone stopped at typed `PeriodicActionFirstBranchMismatch`. Review proved the surviving seam was an existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: generator rotation is exact A3 Forward-occurrence -> Reverse-occurrence carrier-face transport, while relation endpoint branch/gauge was still authored from the retained local cell/trace face.

The R13 Review addendum also corrects historical stable accounting: the R12 accepted ordinal408 PASS -> RED transition is a new recovered `RP-01` recurrence. Current totals entering and leaving CB16 are therefore **51 events / 14 categories / 37 recurrences**, produced-witness debt **3**.

## 2. Implemented correction

CB16 adds an explicit `SurfacePeriodicRelationEndpointBranchAuthority` containing:

- local endpoint source face;
- exact local-face +U branch rotation;
- exact accepted A3 occurrence-carrier face;
- exact occurrence-carrier-face +U branch rotation.

`make_periodic_relation_endpoint_state(...)` now preserves the bounded-disk chart offset while changing only the face gauge:

```text
C     = B_local - B_face_local  (mod 4)
B_rel = B_face_occ + C          (mod 4)
```

The published relation endpoint stores `B_rel`. For nonzero generator rotation its relation-owned lattice coordinate is rotated by `B_rel`; for `R == 0` the raw cut-domain cell coordinate is preserved exactly. Ordinary `LocalLatticeState`, canonical relation identity/storage, A3 route authority, source field construction and selector430 are unchanged.

The producer resolves the occurrence face from the accepted A3 boundary occurrence plus exact generator carrier. Checked `SurfacePhaseFrontProduct::make(...)` and authoritative materialization independently validate the carried branch authority and reconstruct the same endpoint state. No partner fitting, inverse retry, translation search or post-failure endpoint rewrite was added.

## 3. Independent focused falsifier

Added:

`M5CP3.PeriodicRelationEndpointBranchUsesAcceptedOccurrenceAuthority`

The identity uses genuine quarter-turn transport while deliberately making the retained local-face branch differ from the accepted occurrence-carrier-face branch. It independently derives the expected relation branch, verifies the corrected endpoint state, proves the raw local branch cannot accidentally satisfy the old correspondence, and retains an `R == 0` control where relation coordinates equal raw cell coordinates exactly.

The test is compiled only in CB16. It is **not executed** in this turn and is not added to selector430.

## 4. Same-turn compile correction

The first semantic patch produced source `11a82a4bd190260648214498da78f93ca106142b`. Initial compile run/job `35820136501 / 107050051110` correctly failed during the `directional_core` preflight because `build_uniform_phase_front_state(...)` attempted to read `faceBranchRotation` outside the bounded-disk regional producer scope:

```text
SurfaceCellTracing.cpp:17558:35: error: ‘faceBranchRotation’ was not declared in this scope
SurfaceCellTracing.cpp:17567:13: error: ‘faceBranchRotation’ was not declared in this scope
```

This was a scope/lifetime defect in the new authority bridge, not a runtime result. The bounded same-turn correction retains each regional producer's exact per-face branch gauge in internal `SurfacePhaseFrontBuildState::faceBranchRotation` and obtains the local/occurrence values from the already selected regional build during periodic reconciliation. It does not add a new semantic owner or broaden the frozen formula.

The corrected semantic source is:

`6bad9eb5626e77a234ffb2c14f621195105e4ba1`

## 5. Patch transport evidence

Primary semantic patch:

- base `c56769e634273ccc872fab4da385bd15f450308c`;
- patch SHA-256 `d0cce7aac3424396c541acbc6baaa815f7783557133d1f17f7dbc0d00e686e7a`;
- diff-body SHA-256 `1fffb84c3d66f0f3726665c5852aec2ec08e456c3fad5d184ede29643cccf8f2`;
- apply run/job `35820015171 / 107049693541`;
- result/log artifacts `10732594313 / 10732584289`;
- applied source `11a82a4bd190260648214498da78f93ca106142b`.

Compile-correction patch:

- base `11a82a4bd190260648214498da78f93ca106142b`;
- patch SHA-256 `9d6dc388b4a4f1ff48876b2eea46cf4abfdba301f964b00ac90e61d370ca9747`;
- diff-body SHA-256 `58488f75c2f0e8575efd8550d57613acbd906938a20aa8744cac0e57118478b5`;
- apply run/job `35820709280 / 107051775237`;
- result/log artifacts `10732784972 / 10733885229`;
- applied source `6bad9eb5626e77a234ffb2c14f621195105e4ba1`.

Both transient Drive patch files required owner cleanup and were permanently deleted after successful push.

## 6. Mandatory GMP compile/package result

Compile retry run/job:

`35820794471 / 107052021973`

Candidate result artifact:

`10733058003` — ZIP SHA-256 `96e313e822bea8ebc6b7478c75c99d4c9245c7d88913b0d14d449a0ec73013f0`

Diagnostic log artifact:

`10732709067` — ZIP SHA-256 `3cfde85027f85bbb21f22c87918bbb911879f17bdc03014618c819a04343eeaa`

Package evidence:

- exact semantic source `6bad9eb5626e77a234ffb2c14f621195105e4ba1`;
- all eight required targets compiled and linked;
- preflight exit `0`, full build exit `0`;
- root manifest **28/28**, `SHA256SUMS` SHA-256 `f77684128606428a82fe236b749b2d8357948e610745db55f98775a6b4217629`;
- packaged source archive SHA-256 `45bb6ccaba68772e998ebd41d75334041b54e5eadb36e4f3c0cd68b46b9b988b`;
- all source-status receipts empty;
- `exactArithmeticBackend=GMP`;
- authoritative link command contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`;
- `runtimeExecution=false`.

Compiled targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional executable, test, benchmark, discovery/list/help/version command, CLI, fuzzer or custom input was executed.

## 7. Disposition

CB16 satisfies its Code + Build gate only. The candidate is **compile-green and runtime-unproved**. No runtime recovery, candidate promotion, debt discharge, observation closure, selector publication or stable-accounting change is claimed from compilation.

Accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. The two nonzero-Z4 M5 debts, `M5-CP3-TB1-R6-REV-OBS-01`, `M5-CP2-TB1-REV-OBS-01`, and `M5-CP3-TB1-R13-REV-OBS-01` remain open entering R14.

Fresh artifact-only `M5-CP3-TB1-R14-EXEC` is now authorized. It must run the new branch-authority identity first and then the unchanged R13 447 identities, for **448 fresh exact-filter processes**, followed by mandatory Review.
