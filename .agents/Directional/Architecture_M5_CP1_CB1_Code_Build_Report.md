# M5-CP1-CB1 Code + Build Report — Canonical Periodic Relations and Selected Path Certificates

**Turn:** `M5-CP1-CB1`
**Milestone/checkpoint:** M5 / CP1
**Disposition:** COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Semantic evidence commit:** `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Entering accepted runtime authority:** package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**

## 1. Implemented

The CP1 slice is implemented without broadening into M6 or CP2:

- `PeriodicRelationId` is now a semantic composite of `TopologyRegionId` plus canonical generator/cut carrier identities. Carrier identity retains step kind, source-edge topology and checked interior-transition identity while excluding action/transport, container position and front-edge diagnostics.
- `CanonicalRoute` publishes exact carrier identity and `SurfacePeriodicHolonomy::make(...)` derives its relation ID from authoritative routes. Unchecked `with_id(...)`/ordinal production relabeling is removed.
- component aggregation preserves periodic relation IDs verbatim; the former periodic offset/remap path is removed.
- topology-distinct relations in the same topology region coexist; a canonical-ID/value mismatch fails closed instead of being silently renumbered.
- quotient materialization records the exact producer-selected successful relation chain as `SelectedRelationPathCertificate` steps with typed relation IDs, direction, endpoint component identities and applied exact transport.
- `close_completion_lineage_source_authority(...)` validates the producer-carried certificate and its composed transport. It no longer reconstructs semantic reachability with hard-rail adjacency/BFS and never searches for a substitute path.
- benchmark semantic hashing includes canonical periodic identity and selected certificate content.

## 2. Focused regression definitions authored

Runtime is deferred to TB1. The changed producer test target now includes focused coverage for:

- simultaneous route reversal preserving canonical relation ID;
- topology-distinct same-region relations retaining stable unequal IDs under insertion-order reversal;
- action/transport-only change retaining the same canonical ID so unequal value is observable as a conflict;
- disconnected component aggregation preserving canonical periodic IDs without offset remapping;
- selected relation-path certificate invariance under relation-container permutation;
- unused valid periodic relation invariance;
- altered selected-relation transport rejection without alternate-path search;
- the existing `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` non-vacuity discriminator (`>=2` relation owners / `>=2` owned periodic edges).

Expected carrier identity in the route-level test is derived independently from semantic route steps rather than by calling the production relation-ID factory.

## 3. Surgical-change review

Material assumptions came directly from `Architecture_M5_Frozen_Definitions.md` and `Architecture_M5_CP1_Code_Build_Plan.md`: relation identity excludes action/transport, selected producer path is authority, and M6 occurrence authority is out of scope. The implementation reuses existing route, quotient-union and lineage structures rather than adding a generic path framework. No source-grid recovery, fixture-specific condition, selector mutation, unrelated refactor, formatting sweep or performance/cache change was made.

Static source audit on the exact applied patch found no production references to:

```text
PeriodicRelationId::from_index
periodicRelationOffset
reachableHardRailComponents
hardRailAdjacency
```

The semantic patch changes **11 files / +1091 / -212**. `git apply --check` and `git diff --check` passed before remote application.

## 4. Build evidence

Patch application produced exact semantic commit `b98f461b9a392cc182891a81c0a84b0b01dfbb45`.

Authoritative compile-only workflow:

- run/job: `35478855426 / 105992849133`;
- result artifact: `10595705100` (`directional-m5-cp1-cb1-result-35478855426`), provider/download SHA-256 `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`;
- diagnostic artifact: `10595408200` (`directional-m5-cp1-cb1-log-35478855426`), provider/download SHA-256 `c99373dae8f7e70d4bc8698b42b57ecdb26149de753fa4cb6f4f4bdb859171c8`;
- package root `SHA256SUMS`: **28/28 PASS**, manifest SHA-256 `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d`;
- packaged source archive SHA-256 `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`;
- preflight/build exit codes: `0 / 0`;
- final packaged source status: clean;
- `DIRECTIONAL_ENABLE_GMP=ON`; authoritative link command contains both `libgmpxx.so` and `libgmp.so`;
- package boundary records `exactArithmeticBackend=GMP`, `turnBoundary=Code+Build-only`, `runtimeExecution=false`.

Compiled targets:

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

**No generated Directional executable, test, benchmark, discovery/list/help/version command, or custom runtime input was executed in this turn.**

## 5. Control-plane closeout

Temporary apply/compile callers were retired before marker cleanup. Cleanup run/job `35479409243 / 105994360386` succeeded and produced cleanup commit `3e627fa15f48d33afda1addf9b8950f291bf990a`; result artifact `10595102649` has provider digest `sha256:76ffac3dd4fb138b4c0d475ef319990cc3e061bcebdcecf65b2024a65ba4d4cc`. It removed the apply, compile and source-snapshot markers, reported `runtimeExecution=false`, and left only the seven durable workflows.

The patch-apply workflow reported Drive staging retirement required (`drive_file_trashed=false`). The subsequent owner-authorized Drive deletion attempt returned `404 notFound` for the exact staged File ID. No speculative search or retry was performed; the object is no longer addressable through the available owner control plane.

## 6. Acceptance boundary and successor

This turn proves **compile/package correctness only**. It does not grant CP1 runtime credit, promote the candidate package, close any M5 produced-witness debt, or change accepted selector430 authority. Accepted runtime authority therefore remains M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430** until successor runtime evidence is adjudicated.

Exact successor: **`M5-CP1-TB1-EXEC`**, artifact-only, under `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md`.
