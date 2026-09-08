# M3-CP4c-3-CB47 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 107 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Starting semantic authority:** TB41 / package106 / source `4cdffe5514ab9f747da38e74c57663ee8806efa6`
**Applied implementation commit:** `27e2e15d78c8a2bcf522db7e584b9f9d6957b00e`
**Built evidence commit:** `5dacce6019ea34316c48743f3033d2bb5c26281a`
**Authoritative compile run:** `34262805758`
**Changed-owner compile job:** `102184784612`
**Full package compile job:** `102186267545`
**Immutable package result artifact:** `10070788592` / `directional-m3-cp4c3-cb47-result-34262805758`
**Package result artifact digest:** `sha256:f3a936866dc0bc0a81ed7d6d06380836e98e5c32806ac5a8680cf4a0ab393114`
**Persistent package log artifact:** `10070789404` / `directional-m3-cp4c3-cb47-log-34262805758`
**Package log artifact digest:** `sha256:2be93a8c3f59ea265b3293ea74abee51bdd84f0b61d558185c6bf47a57f99bbd`
**Packaged source archive SHA-256:** `2b71ddbaa6e670edf37d51c2f755250dd587a3caad75b2d8fa2afc1ab6056f88`

## 1. Scope and assumptions

CB47 implements only EC7.1–EC7.7 from the promoted TB41 review: measure whether the protected region-frontier census has a subject before any further correction. The existing partition, locator precedence, guard, certification oracle, region construction, production binding, `region_orbit`, orbit-key lookup, content anchor, and selector identities remain unchanged.

The material assumption was that the existing frontier object is the sole diagnostic authority that should be observed. The smallest sufficient change was therefore additive typed measurement on that object plus deterministic diagnostic rendering. No new partition, lookup, fallback, ownership rule, or semantic branch was introduced.

A process-order miss occurred at turn start: repository/doc connector reads began before the mandatory `READ_MODE` selection. The turn corrected to `READ_MODE=snapshot` before semantic source work, resolved and froze the exact source, and then used the durable source-snapshot workflow for all source editing. This is recorded as a lesson-152 compliance miss; it did not alter source authority or runtime evidence.

## 2. Implemented measurements

Exactly five semantic paths changed:

- `include/directional/geometry/GlobalTopologyPlan.h`
- `include/directional/diagnostics/RemeshDiagnostics.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

CB47 publishes:

- `unlabeledFaceCount`;
- `frontierPartitionComponentCount`;
- `ownerConsistencyRowCount`;
- the first available locator kind: `uncutFaceComponent`, `sourceFace`, `regionSweep`, or `singleComponentFallback`;
- whether that locator survived the existing owner-consistency guard;
- whether `failure.sourceFace` belongs to `frontier.partition.componentByFace`;
- failing-region source-face count and the count present in `componentByFace`.

`RegionFrontierEvidence` now carries the unlabeled-face population, `region_frontier_components` returns a measurement record around the unchanged locator/guard logic, and `SurfaceCellFailureLocusDiagnostics` projects the typed values to the artifact-visible diagnostic surface. Test-source changes only render those measurements beside the existing protected assertion; the assertion itself remains `ASSERT_GT(locus.regionFrontierComponentCount, 0U)`.

## 3. Frozen invariants and generalization review

The implementation is not fixture-specific: it measures generic `GlobalTopologyPlanError` frontier state for any region-certification failure that reaches the existing annotation path. No ordinal, fixture ID, source-face ID, region ID, or expected value is recognized by production code.

Frozen invariants verified statically before compile:

- selector409 SHA-256 remains `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- no selector byte changed;
- no binding, `region_orbit`, orbit-key lookup, content-anchor, region construction, `fragmentCorners`, cut selection, ownership, or A2a′ cellularity semantics changed;
- no early return was reinstated and no oracle was weakened;
- ordinals 366/367/368/369/370/374/398 were not corrected;
- protected 390/393/406/407 are still expected to remain RED at runtime because CB47 is diagnostic-only.

## 4. Work preservation and remote application

The pre-orchestration preservation patch is `Directional__M3-CP4c-3-CB47__base-7d41266811d3__work-preservation.patch`.

- exact remote base: `7d41266811d3503a8e6d09b21883fca3508b5e85`;
- full patch SHA-256: `92b877d1ae237e656dbcf662f677e565c360977441e8637b5d6f1f8761e9f03f`;
- embedded diff-body SHA-256: `604df6aa29352acde4acf6f4932b881ba552966678e6733789536c45ea2b26a3`;
- intended path count: 5;
- `git apply --check` and `git diff --check`: PASS.

The exact patch was staged temporarily in `My Drive/Directional-CI`, applied by the durable Google Drive reusable, and pushed as semantic commit `27e2e15d78c8a2bcf522db7e584b9f9d6957b00e`. Apply run `34262519809` succeeded and its result/log artifacts were preserved. The Drive staging file was then permanently retired through the owner-authorized Drive connector.

## 5. Compile and immutable package evidence

No Directional runtime, test, benchmark, produced binary, discovery/list/help/version command, or custom fixture execution occurred in CB47.

The durable compile reusable built exact source `5dacce6019ea34316c48743f3033d2bb5c26281a` in two ordered compile-only jobs:

1. changed-owner target `directional_surface_cell_producer_tests`;
2. after that succeeded, the standard package targets:
   - `directional_core`
   - `directional_pipeline`
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
   - `directional_compiled_api_tests`
   - `directional_benchmarks`

Authoritative package contract:

- run `34262805758`: **success**;
- changed-owner job `102184784612`: **success**;
- full package job `102186267545`: **success**;
- `runtimeExecution=false`;
- `turnBoundary=Code+Build-only`;
- `exactArithmeticBackend=GMP`;
- authoritative link evidence includes both GMPXX and GMP;
- final packaged source status empty;
- package root `SHA256SUMS`: `28/28` PASS;
- packaged approved targets match the eight-item list above.

Changed-owner artifact: `10070737904` / `directional-m3-cp4c3-cb47-owner-result-34262805758`, digest `sha256:ab614ac0fe3384251001e7e116606e72332f28eeb0eda5c0f9648c2e908a44eb`.
Full-package artifact: `10070788592` / `directional-m3-cp4c3-cb47-result-34262805758`, digest `sha256:f3a936866dc0bc0a81ed7d6d06380836e98e5c32806ac5a8680cf4a0ab393114`.
Full-package persistent log: `10070789404` / `directional-m3-cp4c3-cb47-log-34262805758`, digest `sha256:2be93a8c3f59ea265b3293ea74abee51bdd84f0b61d558185c6bf47a57f99bbd`.

## 6. Authority after CB47

CB47 creates one new compile package and **no runtime event, category, recurrence, acceptance result, or regression disposition**.

- current semantic runtime authority remains promoted TB41: selector409 **398 PASS / 11 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`;
- ownership remains **300 / 0 / 0**;
- stable accounting remains **47 events / 14 categories / 33 recurrences**;
- produced-witness debt remains **5**;
- package count advances **106 → 107**;
- immutable build authority becomes package107 on source `5dacce6019ea34316c48743f3033d2bb5c26281a`.

Runtime acceptance is explicitly pending TB42. Compilation cannot decide `M3-CP4c-3-DEFN-R8` and does not promote or close CP4c-3.

## 7. Mandatory Test + Benchmark plan

Successor plan: `Architecture_M3_CP4c3_TB42_Artifact_Only_Test_Benchmark_Plan.md`.

TB42-EXEC must validate the exact package107 artifact without rebuilding. It must preserve accepted 1–365 = 365/365, the recovered content-anchor identities, all binding/content-anchor falsifiers, and existing protected owners while collecting the new EC7 measurements on 390/393/406/407. Those four identities are expected to remain RED; a runtime PASS would itself be a contract violation unless independently explained without weakening the oracle.

TB42-EXEC is execution-only. Its successor is independent `M3-CP4c-3-TB42-REV`, which owns interpretation and `DEFN-R8`; the implementation loop stops at that independent-review boundary.

**CB47 terminates after compile evidence, durable closeout, and temporary-state cleanup. No TB42 runtime is executed in this turn.**
