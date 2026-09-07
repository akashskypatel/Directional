# M3-CP4c-3-CB40 Code + Build Report

## Turn identity

- Turn: `M3-CP4c-3-CB40`
- Canonical boundary: **Code + Build only**
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Authoritative implementation source: `23a753a83f0eda0447172ce96bcd3180bf95ae8a`
- TB34 semantic runtime authority remains unchanged pending TB35.
- Runtime/tests/benchmarks executed in CB40: **none** (`runtimeExecution=false`).

## Authorized scope

CB40 executed CV2-CV6 from `Architecture_M3_CP4c3_TB34_Independent_Review_Record.md` and nothing beyond them.

1. Restore the load-bearing `current == start` boundary-walk rejection while retaining the typed `ClosedBeforeEnd` reason.
2. Re-aim frozen ordinal 409 at a reachable multi-walk negative rather than an unconstructible node-disjoint-loop precondition.
3. Record the authority-domain distinction between certified embedded-graph faces and plan regions.
4. Preserve selector identity/order, accepted ordinal 312, carried RED surfaces, retired guards, and all topology/barrier/ownership rules.
5. Compile only through the durable GMP/GMPXX workflow; execute no Directional runtime.

## Implementation

### CV2 — product rejection restored

`src/geometry/GlobalTopologyPlan.cpp` again rejects a boundary walk that closes at `start` before consuming the complete region boundary:

- error: `RegionBoundaryNotSingleWalk`;
- `regionBoundaryWalkReason=ClosedBeforeEnd`;
- failing region and boundary arc are preserved;
- the existing `ArcChainBroken` and final `WalkNotClosed` checks remain unchanged.

The accepted ordinal 312 witness was **not edited**.

### CV3 — ordinal 409 re-aimed in place

`tests/FieldAlignedCurveNetworkTests.cpp` keeps the frozen test identity
`GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected`, but no longer depends on the unconstructible `disjointRegions` search. The fixture now duplicates one reachable region boundary, producing two closed boundary walks that meet at their shared start node, and requires:

- `RegionBoundaryNotSingleWalk`;
- `regionBoundaryWalkReason=ClosedBeforeEnd`;
- the second-loop first arc as the reported locus.

The assertion text explicitly records that node-disjoint closed region loops are not constructible through this production entry path. Selector ordinal, test name, selector count, and first 408 selector lines remain unchanged.

### CV4/CV5 — authority and pre-freeze doctrine

`ORIENTATION.md` and `M3_CP4c_Current_And_Forward.md` now state the settled distinction:

- a certified face is a face of the embedded graph;
- a plan region is a different partition object;
- face-certificate `F`, component-count, or Euler residual evidence licenses no conclusion about a plan region;
- plan-region disc authority remains the region-level `RegionBoundaryNotSingleWalk` / `RegionEulerCharacteristicNotOne` checks.

TB34-REV lesson 144 remains the mandatory pre-freeze grep rule before any future review removes or weakens a rejection.

## Static verification before remote application

The complete source patch was generated from exact snapshot source `48cfd3ba5e832d5bab58455fcc76a3f18b8aa42b` and verified before remote mutation:

- exact changed paths: **4**;
- `git apply --check`: PASS;
- `git diff --check`: PASS;
- ordinal 312 source unchanged;
- selector 409 count/hash unchanged: **409** / `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector 408 prefix SHA-256: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`.

The work-preservation patch was emitted to chat/File Library before remote orchestration and staged through `My Drive/Directional-CI`. Drive application run `34080573508` verified the patch and pushed exact implementation commit `23a753a83f0eda0447172ce96bcd3180bf95ae8a`. The consumed Drive patch was permanently deleted after successful application.

## Compile-only evidence

Durable reusable compile workflow:

- run/job: `34080675952 / 101615243724`;
- exact compiled source: `23a753a83f0eda0447172ce96bcd3180bf95ae8a`;
- immutable result artifact: `10003613409` / `m3-cp4c3-cb40-result-34080675952`;
- provider/download ZIP SHA-256: `bb5ee6afc1601d8d339d4fbdba32596e7b9a72b747f1510e4221b54d0776b94f`;
- compile log artifact: `10003613693` / `m3-cp4c3-cb40-log-34080675952`;
- log ZIP SHA-256: `3a7b50e4e011f8fb425807486abcd9a74db70939433efbe4bdd3156be27ccc56`;
- packaged source archive SHA-256: `56dc4a0ba09797bb08374abc15d4eaf472d19bcd8bcfa5d2ca3db361182257b4`;
- root `SHA256SUMS`: **28/28 PASS**;
- configure/preflight/build exit codes: **0 / 0**;
- source status before configure, after configure, after build, and final: **clean**;
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- `DIRECTIONAL_ENABLE_GMP=ON`; `libgmpxx.so` and `libgmp.so` are present in authoritative link evidence.

All eight required targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Compiler-cache evidence is non-semantic: durable fixed key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`, 114/116 hits, 2 misses. No per-turn cache namespace was introduced.

## Process deviations recorded

Two ChatGPT Web procedural deviations are retained rather than hidden:

1. One direct connector read of `TOOL_USE_CONSERVATION_POLICY.md` occurred before the exact source-snapshot transfer completed. No implementation or semantic source inspection used that read as source authority; all CB40 code/document work was based on the verified exact snapshot `48cfd3ba5e832d5bab58455fcc76a3f18b8aa42b`.
2. The start-of-turn cleanup manifest was not published before workflow work. The durable cleanup workflow currently auto-triggers from that manifest and deletes PR comments, so publishing it before durable evidence was preserved would have destroyed non-durable observer context. This does not waive the required end-of-turn cleanup; durable evidence is committed first, then the mandatory cleanup workflow is run after temporary callers are retired workflow-first.

## Acceptance and accounting

CB40 is **IMPLEMENTED / COMPILE-GREEN / RUNTIME-UNADJUDICATED**.

- No semantic/runtime candidate closes in this turn.
- Stable accounting remains **45 events / 14 categories / 31 recurrences**.
- Produced-witness debt remains **5**.
- M3 package count becomes **100**.
- Current semantic runtime authority remains **TB34**: selector 409, 400 PASS / 9 RED, accepted 364/365, until TB35 executes the immutable CB40 artifact.

## Exact successor

**`M3-CP4c-3-TB35-EXEC`**, artifact-only, on immutable artifact `10003613409`, followed by a complete stop at independent `M3-CP4c-3-TB35-REV`.

The executable contract is `Architecture_M3_CP4c3_TB35_Artifact_Only_Test_Benchmark_Plan.md`. Hard gates include ordinal 312 PASS / accepted prefix 365/365, ordinal 409 reaching and passing its re-aimed `ClosedBeforeEnd` oracle, protected greens 390/393/404/406/407/408 remaining PASS, and no earlier-stage movement for 366/367. CB40 does not claim any of those runtime outcomes.
