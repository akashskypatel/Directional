# M3-CP4c-3-CB21 Code + Build Report

**Turn:** `M3-CP4c-3-CB21`
**Type:** Code + Build — product correction
**Status:** **COMPLETE / COMPILE GREEN / RUNTIME-FREE**
**Date:** 2026-09-03
**Authoritative semantic source:** `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`
**Accepted runtime authority remains:** **365 / 365**
**Current runtime evidence remains:** `M3-CP4c-3-TB18`

## 1. Verdict

CB21 implements the `BU0–BU9` correction frozen by
`Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` §11. The sole semantic relaxation is the fragment-owner
validation predicate in `build_regions`: a cut face now fails only when the number of distinct global owners is
**greater than** the local `k+1` expectation. A low-side owner deficit is retained as bounded typed evidence and is
not a failure.

The final eight-target compile-only package is green with GMP/GMPXX linked. No generated Directional binary,
test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command, or custom input was executed in
this turn. Therefore CB21 changes product bytes and compile authority but does **not** advance runtime acceptance.

## 2. BU0–BU9 disposition

| Measure | Disposition |
|---|---|
| **BU0** | **PASS.** Accepted selector 365 is untouched. Selector 383 is byte-frozen at `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`. All eight standard targets compile/link with GMP/GMPXX. `runtimeExecution=false`. |
| **BU1** | **PASS.** The sole semantic relaxation is `found->second.size() != expected` → `found->second.size() > expected` in `GlobalTopologyPlan.cpp`; high-side mismatch remains fatal. |
| **BU2** | **PASS.** Low-side deficit evidence publishes `ownerCount`, `expectedFragmentCount`, `ownerDeficit`, and shared-owner chord incidences without returning a mismatch. |
| **BU3** | **PASS.** The local triangle chord arrangement is evaluated exactly and publishes `localFragmentCount`, `traceChordCount`, `chordsCrossInside`, and `localArrangementEvaluated`; none is fatal in CB21. |
| **BU4** | **PASS.** Bounded owner census publishes per-arc forward/reverse orbit sharing, per-trace terminal-slit classification, total/exterior/non-exterior orbit counts, and explicit truncation state. |
| **BU5** | **PASS at compile-contract level.** `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath` exercises every new field through the production fixture, pins the one-chord/one-owner pass-through, and retains a byte-identical high-side failure-envelope oracle. It compiled but was not executed. |
| **BU6** | **PASS.** Selector 384 is `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`; its first 383 lines hash exactly to selector 383, and its sole append is the BU5 identity. |
| **BU7** | **PASS by diff audit.** No authorized change was made to the frozen counting/filtering/face-walk/rotation/region-draft semantics, no new fatal condition was added, and no carried sphere/saturation/ordinal-370/folded-cone/vertex-30/finalize-contact surface was changed. |
| **BU8** | **PASS.** The edited validation loop remains pure. `size > expected` is a strict subset of `size != expected`; the semantic failing set can only shrink. New local-arrangement and census computations are observational. |
| **BU9** | **PASS as a frozen successor contract.** The six TB19 discriminators are published in `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md`; none was runtime-tested here. |

## 3. Product change and safety boundary

### 3.1 Semantic change

Before CB21, every directly cut face required exact equality between distinct global owner-orbit count and
`tracePieceCount + 1`. TB18 proved that equality is unsound when two sides of a locally separating chord
legitimately share one global face-walk orbit. CB21 changes only the fatal predicate:

- **old:** `ownerCount != expectedFragmentCount` → fail;
- **new:** `ownerCount > expectedFragmentCount` → fail.

Thus a high-side overcount stays fatal with the existing CB20 payload, while a low-side deficit is observational.
Because the loop only returns or falls through and mutates no topology, every input that previously passed this
check follows the same control path and sees the same product state.

### 3.2 New observational evidence

CB21 adds typed evidence to the plan/error projection and production diagnostics:

- per directly cut face: source-face key, exact local fragment count when evaluable, owner count, expected count,
  owner deficit, real-chord count, interior-crossing flag, local-arrangement-evaluated flag, shared-owner chord
  count/incidences, and truncation state;
- per global arc: arc/trace identity, forward and reverse face-walk orbit ids, and whether the darts share an orbit;
- per candidate trace: whether its final segment is a terminal slit;
- global total, exterior, and non-exterior orbit counts.

The retained census is bounded. Evidence is projected through `RemeshPipeline` and appended to the existing CP4c
failure-locus formatter. A successful `GlobalTopologyPlan` retains the same evidence for later production-path
inspection.

### 3.3 BU7 prohibition audit

The final semantic diff from the pre-CB21 snapshot touches exactly six intended paths and totals **1024 insertions /
28 deletions**:

1. `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_384.txt`
2. `include/directional/diagnostics/RemeshDiagnostics.h`
3. `include/directional/geometry/GlobalTopologyPlan.h`
4. `src/geometry/GlobalTopologyPlan.cpp`
5. `src/pipeline/RemeshPipeline.cpp`
6. `tests/FieldAlignedCurveNetworkTests.cpp`

No fixture source, tolerance, source authority, trace-piece counting, `add_fragment_orbit`, exterior filtering,
terminal-slit rule, carrier-less corner binding, fragment-corner incidence, face walk, rotation system, or region
draft construction is altered.

## 4. Selector authority

- accepted selector 365: unchanged, accepted runtime authority **365 / 365**;
- selector 383: **383 identities**, SHA-256
  `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`;
- selector 384: **384 identities**, SHA-256
  `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`;
- `head -383 selector384 | sha256sum` reproduces the selector-383 hash exactly;
- sole appended identity:
  `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath`.

Selector 384 is compile-defined only until TB19 executes it.

## 5. Compile-only evidence

### 5.1 Initial compile defect and correction

The first implementation commit was `b76d878f4ca689f72db9cfcd329965402151c89d`. Compile-only run/job
`33793819402 / 100776654267` failed during `directional_core` preflight before any runtime execution. The failure
was confined to `src/geometry/GlobalTopologyPlan.cpp`:

- three local helper signatures used unqualified `SourceFaceRecord` instead of
  `embedded_graph_topology_detail::SourceFaceRecord`;
- `TraceCutFaceFragmentOwnerEvidenceDiagnostic` was default-constructed even though its
  `SourceFaceTopologyKey` member has no default constructor.

The surgical compile correction qualified those three types and aggregate-initialized the evidence row with
`faceKey` (**7 insertions / 6 deletions** in one file). It produced final semantic source
`b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`. No semantic predicate or evidence contract changed in this compile
repair.

### 5.2 Authoritative green compile

Final compile-only run/job: **`33794307778 / 100778238374`**.

All eight required targets compiled and linked:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Evidence:

- preflight target `directional_core`: exit **0**;
- full target build: exit **0**;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only`;
- `exactArithmeticBackend=GMP`;
- GMP cache/config evidence resolves `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`;
- authoritative test-link command contains `libgmpxx.so` followed by `libgmp.so`;
- source status before configure, after configure, after build, and final: empty/clean;
- compiler cache hit; no source-tree build output;
- package manifest: **28 / 28 entries present and hashed**.

Immutable result artifact:

- artifact id **`9908695433`**;
- GitHub/downloaded ZIP SHA-256
  **`efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5`**;
- packaged source archive
  `source-b00efbd53d3da8caa2bcac0d66594e06e44d2cb2.tar.gz` SHA-256
  **`8b774500559e5cc9cd7afece39a68add2065a9812a0d15a40f39cf7f9aafd8e7`**.

Compile log artifact:

- artifact id **`9908695835`**;
- SHA-256 **`f334db6b4bf254c3e2eb84f0a65cb0f6a21fc56285b3677a037cb20881b8ad3f`**.

## 6. Runtime and accounting boundary

CB21 consumed no runtime attempt and proves no required-green identity. Current immutable runtime authority remains
TB18 at selector 383: **375 PASS / 8 RED**, with accepted ordinals 1–365 **365/365 PASS** and reds
366/367/368/369/370/371/372/374.

Stable regression accounting therefore remains **44 events / 14 categories / 30 recurrences**. Produced-witness
debt remains **5**. The successful CB21 package advances the semantic M3 package count from **84 to 85**.
CP4c-3 remains **OPEN**.

## 7. Exact successor

The exact next turn is **`M3-CP4c-3-TB19-EXEC`**, artifact-only Test + Benchmark, using **only** immutable artifact
`9908695433` from semantic source `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2` and selector 384. The binding
execution contract is `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md`.

No TB19 runtime was executed in CB21.
