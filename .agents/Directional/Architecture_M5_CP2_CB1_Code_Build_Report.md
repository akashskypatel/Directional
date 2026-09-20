# M5-CP2-CB1 Code + Build Report

**Turn:** `M5-CP2-CB1`
**Disposition:** **COMPLETE / STATIC GATE SATISFIED / GMP COMPILE-PACKAGE GREEN / RUNTIME NOT EXECUTED**
**Implementation source:** `0798547dedd8be05f9cd7a096b07e6bd94755316`
**Compile run/job:** `35500960779 / 106052541163`
**Candidate package:** artifact `10601978228`
**Exact successor:** `M5-CP2-TB1-EXEC`

## 1. Outcome

The frozen five-class periodic-relation failure matrix is implemented at the checked `SurfacePhaseFrontProduct::make(...)` boundary and the exact implementation source compiled successfully with GMP/GMPXX. No generated Directional binary, test, benchmark, discovery command, CLI, GUI, `ctest`, fuzzer, or custom runtime input executed. The package records `runtimeExecution=false` and remains **unexecuted / unpromoted** until artifact-only Test + Benchmark and Review.

The accepted runtime authority is unchanged: package `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7` / selector430 **430/430**. Stable regression accounting is unchanged at **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**.

## 2. Implemented matrix

`SurfacePhaseFrontProductErrorCode` now carries the five frozen CP2 relation classes without repurposing prior enum values:

| Class | Typed outcome | Checked condition |
|---|---|---|
| missing | `MissingPeriodicRelationOwner` | periodic edge has no relation reference, or referenced canonical ID is absent from the relation table |
| duplicate | `DuplicatePeriodicRelationId` | same canonical relation ID is published more than once with an identical immutable relation value |
| conflicting | `ConflictingPeriodicRelation` | same canonical relation ID is published with a different immutable value/action |
| nonreciprocal | `NonReciprocalPeriodicRelation` | paired periodic edges do not bind the same relation with exact reverse route / compatible forward-or-inverse lattice action |
| representation-renumbered | `RepresentationRenumberedPeriodicRelation` | declared relation identity or edge carrier does not match the canonical carrier identity represented by the relation |

The implementation does not add index-backed relation IDs, `periodicRelationOffset`, first/last-wins replacement, relation dropping, sorting-based reassignment, alternate-path search, or front-edge substitution.

## 3. Independent negative-oracle construction

The new test helpers independently derive carrier identity from `CanonicalRoute::oriented_steps()` into `PeriodicCarrierStepIdentity` values, canonicalize generator/cut carrier reversal with a direct lexicographic comparison, and construct the expected typed ID from `PeriodicRelationId::from_carriers(...)`. They do **not** call production `authority::periodic_relation_id(...)` to obtain the expected answer.

The nonreciprocal witness independently composes route transport and changes exactly one route-step transport while preserving the route's carrier identity. The conflicting witness preserves canonical carrier ID while changing only the relation action. The representation-renumbered witness introduces a second valid relation identity and changes only the edge reference to that different semantic carrier. Duplicate and conflict are therefore distinguished by immutable value equality under one canonical ID rather than by storage order.

## 4. Accepted selector assertion audit — correction and exact mapping

The in-flight observation `M5-CP2-CB1-OBS-01` contained one incorrect premise. Reopening the exact **accepted CP1 source** `8a86710dd33d7b6cb9a077aef738577e4075b5f7` proves selector430 row **221**, `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`, was already a positive-only 14-assertion invariance test before CP2. The compiled source `0798547d...` contains the same body. It therefore did **not** lose `EXPECT_EQ("InvalidPeriodicRelation", materialized.failure)` in CP2. That assertion belonged to other, ungated swap/produced-torus tests.

The accepted selector rows actually touched by CP2 are:

| Selector row | Accepted identity | Accepted-source assertion | CP2 assertion / disposition |
|---:|---|---|---|
| 226 | `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` | downstream `materialize(...)` failure plus exact string `InvalidPeriodicFrontTransport` | same test identity now rejects earlier at the checked phase-front boundary with exact typed `NonReciprocalPeriodicRelation`; carrier identity preservation `EXPECT_EQ(originalId, value->id())` was already present in accepted source and remains present |
| 296 | `SurfacePhaseFrontProductFactoryAuthority.DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory` | exact `DuplicatePeriodicRelationId` | exact `DuplicatePeriodicRelationId` remains; witness is strengthened with independently derived carrier identity and reversed-container-order repetition |
| 304 | `SurfacePhaseFrontProductFactoryAuthority.UnknownPeriodicRelationOwnerRejectsAtCheckedFactory` | broad `InvalidPeriodicRelationOwner` using production ID factory | frozen CP2 `MissingPeriodicRelationOwner`, with the unknown ID independently derived from carrier content rather than by the production identity factory |

Selector rows **220** (`MissingPeriodicRelationOwnerIsRejected`) and **221** are unchanged by CP2. The new conflict, direct nonreciprocal, and representation-renumbered factory identities are not in selector430. That does **not** make the implementation incorrect, but it leaves `M5-CP1-TB1-R3-REV-OBS-01` unresolved: M5 still has no frozen selector-publication sequence protecting newly authored CP1/CP2 evidence. The following Review must independently verify the row-226 boundary relocation and decide whether any additional gated materializer-path preservation is required before CP2 can be accepted.

This report therefore corrects the **locus** of `M5-CP2-CB1-OBS-01`; it does not self-adjudicate the Review-owned coverage question.

## 5. Compile/package evidence

The mandatory reusable compile workflow completed successfully:

- workflow run: `35500960779`;
- compile job: `106052541163`, conclusion **success**;
- exact compiled source: `0798547dedd8be05f9cd7a096b07e6bd94755316`;
- result artifact: `10601978228`, provider ZIP SHA-256 `ad2e502db60d94c275769616edf5555d12abd87499c6cf3987cdafbd458d2f0b`;
- log artifact: `10601923321`, provider ZIP SHA-256 `efadf1c895bad944abc85630eca88cc824f44cac9e7aae1d229f87e9ed968f1c`;
- packaged `SHA256SUMS`: **28/28 verified**;
- preflight/build exit codes: **0 / 0**;
- preflight target: `directional_core`;
- compiled targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`;
- source-status receipts before configure, after configure, after build, and final: empty/clean;
- command boundary: `turnBoundary=Code+Build-only`, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- GMP evidence: explicit `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` linkage;
- compiler cache: fixed key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`, restore hit, 256 MiB cap.

No runtime result is claimed from compilation.

## 6. Turn boundary and successor

`M5-CP2-CB1` is complete as a Code + Build turn. It grants compile/static mechanism evidence only; it does not promote the candidate, publish a selector, execute a test, discharge a production debt, prove CP3 production, or touch M6 occurrence authority.

The exact successor is artifact-only **`M5-CP2-TB1-EXEC`** under `Architecture_M5_CP2_TB1_Artifact_Only_Test_Benchmark_Plan.md`. It must consume artifact `10601978228` immutably, execute the frozen focused matrix plus selector430 with exact-one/zero-skip discipline, run zero benchmarks, and leave semantic promotion to Review.
