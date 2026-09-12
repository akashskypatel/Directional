# M4-CP3-CB7 Code + Build Record

**Turn:** `M4-CP3-CB7`
**Status:** COMPLETE / BUILD GREEN / RUNTIME-FREE / CANDIDATE ONLY
**Phase:** M4-CP3 exact A3→A4 shared-boundary cutover
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Starting source authority:** snapshot marker `18ef11691bf4cf15e8aedcf22a57dd2372673f9c`
**Built semantic evidence commit:** `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`
**Authoritative compile run/job:** `34678708800 / 103513182449`
**Candidate package artifact:** `10293750596`
**Candidate package SHA-256:** `f95decac9b059bcc7c7b341ecda1e95e8a5b0028211eaa7f902144a196c60831`
**Compile log artifact:** `10293990184`
**Compile log SHA-256:** `72447200a886c4e07768f8e81a156f0878f400321cddd054341cf68d758863f9`
**Accepted runtime authority retained:** R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Candidate selector408:** `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` / NOT PROMOTED

## 1. Pre-mutation effective-authority guard

The frozen torus witness was re-derived from the exact source snapshot before any semantic mutation.

- source mesh: `V/E/F = 72/216/144`, connected, closed, `χ=0`;
- minor generator: `0-3-25-37-49-61-0`;
- major generator: `0-1-4-6-8-10-12-14-16-18-20-22-0`;
- the two cycles contain **18 distinct source edges**, are simple except for closure, intersect only at vertex `0`, and all listed pairs are actual source edges;
- maximum non-user dihedral is `60.852573735971816°`, so row-local CAD+organic absolute bands `179.0 / 180.0` classify **0 automatic Hard edges** while explicit user Hard tags remain authoritative;
- effective hard authority is therefore exactly the same **18** source edges, with no boundary rails on the closed torus;
- removing those 18 rail edges leaves one source topology region of 144 faces;
- cutting the two-cycle union yields `V/E/F = 91/234/144`, `χ=1`, 36 boundary edges forming one degree-2 boundary loop: the complement is a disc.

The guard therefore satisfied every `Architecture_M4_CP3_CB7_Code_Build_Plan.md` stop condition before mutation.

## 2. Implemented

One semantic file changed: `tests/FieldAlignedCurveNetworkTests.cpp`.

1. `cp4c_torus_hard_rail_remesh_options()` now sets only the four authorized row408-local adaptive-feature thresholds:

```cpp
options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
```

2. Row408 now derives the effective production `HardFeature` source-edge set from authoritative rails and asserts exact set equality with the frozen 18-edge torus cut graph before the existing A3→A4 assertions. This converts the TB4 composition failure into an immediate, identity-bearing test precondition rather than allowing later seam assertions to run against a different hard-rail authority.

No product source/header, rows404-407, selector, CMake ownership rule, fallback policy, tolerance, or production semantics changed. Row408's test identity is unchanged.

## 3. Engineering-guideline review

- **Material assumptions surfaced:** the `179/180` suppression is a property of this committed torus fixture, not a production invariant; row408 therefore carries an exact effective-authority assertion at runtime.
- **Simplest sufficient approach:** constrain only the row408 helper's automatic feature classification and assert the authority it actually feeds downstream.
- **Why no smaller change satisfies the contract:** threshold assignments alone would repeat CB6's failure mode by relying on an unstated fixture property; the explicit edge-identity assertion is the review-mandated falsifier.
- **Surgical scope:** semantic diff is one test source file, `+26/-0`; no unrelated refactor or formatting drift.
- **Every semantic changed line traces to the objective/supporting validation:** yes.

## 4. Preservation and application

The WIP/recovery patch was emitted before remote mutation and tied to exact base `18ef11691bf4cf15e8aedcf22a57dd2372673f9c`:

- patch SHA-256: `e2a6ca286b22d378f70280dd45a96ec995ee54836ee958edda711770f275c7fe`;
- diff-body SHA-256: `ac4fce2f8c2a2ce1ba217be3c938ab24ee05f52696faf93e7e157826cab8ef9c`;
- intended path: `tests/FieldAlignedCurveNetworkTests.cpp`.

Drive-apply run `34678546235`, job `103512716658`, applied the patch as semantic commit `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`. The consumed Drive staging file was permanently deleted owner-side after successful application.

## 5. Selector and ownership invariants

Packaged source re-proof preserves the frozen selector surface:

- selector403: 403 LF rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- selector408: 408 LF rows, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- first 403 rows of selector408 hash exactly to selector403;
- owner partition remains **30 authority-kernel / 262 producer / 75 completion / 41 validation**, zero missing/ambiguous owners;
- row408 remains producer-owned.

No selector bytes were authored in CB7.

## 6. Build

The mandatory reusable compile workflow built exact pushed semantic source `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8` in Release/static `PRE_TEST` mode with GMP/GMPXX.

Authoritative unique target order:

1. `directional_surface_cell_producer_tests` — mandatory changed-owner preflight;
2. `directional_core`;
3. `directional_pipeline`;
4. `directional_surface_cell_authority_kernel_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_compiled_api_tests`;
8. `directional_benchmarks`.

Result:

- preflight exit: `0`;
- build exit: `0`;
- package root `SHA256SUMS`: **28/28 PASS**;
- source archive SHA-256: `ca16770d8ceff1da119687284eb7c01b31af9ce237be01753ed4c962305ff18d`;
- package manifest SHA-256: `43e8e4c35712c8b69d4906288390745f2bdb507160cf52c31ad8f7545faa91ed`, 28 entries;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- GMP link evidence contains both `libgmpxx.so` and `libgmp.so`;
- all source-status snapshots are empty;
- packaged test/benchmark binaries are executable but **were not executed**.

### Compile-control corrections

- run `34678598168` was a zero-job `startup_failure` caused only by a temporary caller permission ceiling; reusable workflow permissions were not changed;
- run `34678622666` subsequently compiled successfully, but its temporary caller repeated the producer target in target metadata, so it was intentionally not used as package authority;
- the caller was corrected to the eight unique frozen targets and run `34678708800` is the sole authoritative CB7 package build.

No runtime test, benchmark, GTest listing/discovery, `ctest`, or produced Directional binary executed in CB7.

## 7. Domain invariants and generalization review

- Explicit user Hard authority remains independent of automatic feature scoring.
- The fix is deliberately fixture-scoped because the failure was a row408 fixture-precondition composition defect; production classification semantics remain unchanged for all other inputs.
- Exact source-edge identity, rather than rail count, protects against future automatic/user composition drift.
- Candidate compilation is not semantic acceptance. Corrected R4 selector403 remains accepted runtime authority until TB5 + Review.

## 8. Known risks

- TB5 may expose a product-semantic failure after row408 finally reaches the intended A3→A4 seam. CB7 makes no claim about that runtime outcome.
- The row-local `179/180` bands are safe for the committed torus because the static guard proved its maximum non-user dihedral is ~`60.85°`; replacing the fixture geometry requires the runtime authority assertion to fail rather than silently broadening the witness.
- `M4-CP3-TB4-REV-CAND-01` remains open/non-stable until later Review adjudicates the recovered witness.

## 9. Mandatory Test + Benchmark successor

Plan: `.agents/Directional/Architecture_M4_CP3_TB5_Artifact_Only_Test_Benchmark_Plan.md`.

TB5 must consume artifact `10293750596` unchanged and execute **821 fresh exact-filter processes** in the frozen order:

- row408 focused A: 1;
- row408 focused B: 1;
- rows404-407 control A+B: 8;
- accepted selector403: 403;
- candidate selector408: 408.

It is fail-fast and must preserve immutable pre/postflight. Mandatory `M4-CP3-TB5-REV` owns diagnosis, promotion, `G4-B002`, CP3 disposition and regression accounting.

## 10. Next turn

**Type:** Test + Benchmark
**Exact subturn:** `M4-CP3-TB5-EXEC`
**Runtime authority under test:** candidate artifact `10293750596` from semantic source `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`.
