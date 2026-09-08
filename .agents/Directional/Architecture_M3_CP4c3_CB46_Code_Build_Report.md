# M3-CP4c-3-CB46 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 106 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Final semantic source:** `4cdffe5514ab9f747da38e74c57663ee8806efa6`
**Authoritative compile run/job:** `34253044050 / 102152247907` (attempt 2)
**Immutable result artifact:** `10066942690` / `directional-m3-cp4c3-cb46-result-34253044050`
**Result ZIP SHA-256:** `aae9da4b2b237c7ebda82af2d7153c0e766f24455f1a45ab4a2685e9961a3d24`
**Persistent compile-log artifact:** `10066943120` / `directional-m3-cp4c3-cb46-log-34253044050`
**Compile-log ZIP SHA-256:** `58db7093e7a97d13875560d37336ad1fa7274117ed2f89d5e65e3cc2ad30fc63`
**Packaged source archive SHA-256:** `d355ea6bb13ee0d7e174edc214070cfbd81cf278ce44ad7a4f77bacc17bee004`

## 1. Scope and boundary

CB46 implements **EB7.1–EB7.7** from `Architecture_M3_CP4c3_TB40_Independent_Review_Record.md` after TB40-REV
proved that the CB45 production region→orbit→upstream-face binding is correct and that four accepted test oracles
were comparing two representation-dependent orbit enumerations. The binding itself remains unchanged.

No Directional runtime, test, benchmark, generated discovery/list/help/version command, fuzzer, produced binary,
or artifact-only gate was executed during CB46. The authoritative compile package records
`runtimeExecution=false`; therefore **TB39 / package104 / selector409 402 PASS / 7 RED, accepted 365/365** remains
the current valid semantic runtime authority until TB41-REV independently adjudicates new runtime evidence.

## 2. Implementation result

### EB7.1 / EB7.4 — content-derived face identity; foreign orbit equality removed from independent oracles

CB46 chose the preferred EB7.1(b) repair. `SurfaceCutGraphFaceCertificate` now publishes the canonical oriented
boundary anchor of the certified face walk: the lexicographically minimum `(NetworkArcId, Orientation)` incidence.
The producer-local `orbit` remains present and remains the production binding key; the new anchor is independent
content evidence, not a replacement relation.

The certificate/candidate semantic digest now consumes the anchor. Independent proof helpers and ordinals
311/314/356/357 re-derive their face walk, derive the same canonical anchor, and require exactly one upstream face
certificate with that anchor. They no longer compare an independently enumerated face index with the producer's
orbit ordinal. The census publishes both independent and certificate anchors and explicitly requires more than one
distinct anchor when more than one region exists, so the evidence surface can disagree with itself instead of
collapsing to a constant field.

### EB7.2 — frontier evidence decoupled from terminal error code

`regionFrontierComponentCount` collection now consumes every available region-construction locator
(`uncutFaceComponent`, `sourceFace`, and region) independently rather than using an `if/else-if` chain tied to one
terminal code. Retiring or advancing a failure enum therefore cannot by itself silence already-available frontier
evidence. This is the bounded DEFN-R4.4 correction; it does not change region construction or certification.

### EB7.3 — production binding preserved

CB46 does **not** change `region_orbit`, the exact ordered-boundary derivation, the orbit-keyed upstream lookup, or
the derived-not-stored binding rule. Ordinal315 continues to tamper `actualEmbeddedFace.orbit`; 312/409 are
unchanged binding falsifiers. No selector identity was added, removed, renamed, reordered, or byte-edited.

### EB7.6 — missing-fragment frontier measured, not corrected

`RegionSourceFaceOwningFragmentMissing` retains its rejection behavior. The failure now records
`regionOwningFragmentOrbit` alongside the failing `sourceFace`, and the existing diagnostic serialization exposes
that orbit with the source-face fragment-owner census. This is measurement only. CB46 does not repair 366/367 or
change their owner.

## 3. Exact semantic source changes

The mandatory work-preservation patch was based on
`d01333c3812cb01ea6854449cd59bdb2e19ea431`, touched exactly eight paths, and was emitted before remote
application:

- `.agents/Directional/Architecture_M3_CP4c3_TB41_Artifact_Only_Test_Benchmark_Plan.md`
- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `include/directional/geometry/SurfaceCutGraph.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/geometry/SurfaceCutGraph.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

Work-preservation patch SHA-256:
`338b38536c817980f5f8818b1bfd50981e17863bba4b6f2618df9c3c6fc7e725`; embedded diff-body SHA-256:
`afecc0aa8c7c8ad2256e56a54c758a10d375597ef43e475907c188fb75b7a42d`. The applied semantic commit is
`4cdffe5514ab9f747da38e74c57663ee8806efa6` with **303 insertions / 28 deletions** across the eight paths.

The successor `Architecture_M3_CP4c3_TB41_Artifact_Only_Test_Benchmark_Plan.md` is part of that immutable semantic
source and freezes the TB41-EXEC contract before runtime.

## 4. Compile and immutable package evidence

The compile caller consumed exact semantic source `4cdffe5514ab9f747da38e74c57663ee8806efa6` through the mandatory
`agent-compile-reusable.yml` path. Run `34253044050` attempt 1 reached workflow infrastructure but was blocked by an
`upload-artifact` finalization HTTP 403 after schema validation had succeeded; no semantic change followed. The
same run was retried without modifying source or caller semantics.

Authoritative attempt 2 job `102152247907` compiled and linked all approved targets successfully:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Compile/package contract:

- Release static out-of-tree PRE_TEST;
- `turnBoundary=Code+Build-only`;
- `runtimeExecution=false`;
- `exactArithmeticBackend=GMP`;
- both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` appear in the authoritative link command;
- preflight exit `0`, build exit `0`;
- final packaged source status empty;
- fixed reusable compiler-cache namespace;
- ccache **97/116 hits**, **19 misses**.

The package root `SHA256SUMS` verifies **28/28 PASS** and excludes itself.

Frozen execution authority remains byte-preserved:

- selector409: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 prefix and artifact-only harness remain byte-identical to package105;
- no selector execution occurred in CB46.

## 5. Accounting and authority after CB46

CB46 creates **one new semantic package and no runtime event or recurrence**:

- current semantic runtime authority remains **M3-CP4c-3-TB39 / package104**;
- TB39 remains selector409 **402 PASS / 7 RED**, accepted **365/365**, RED
  `[366,367,368,369,370,374,398]`;
- TB40 remains mechanically valid but semantically RED and **not promoted**;
- current immutable build authority is **package106**, source
  `4cdffe5514ab9f747da38e74c57663ee8806efa6`, artifact `10066942690`;
- stable accounting remains **47 events / 14 categories / 33 recurrences**;
- produced-witness debt remains **5**;
- semantic M3 package count advances **105 → 106**.

`M3-CP4c3-TB40-EXEC-CAND-01`, `M3-CP4c3-TB40-EXEC-CAND-02`, and
`M3-CP4c3-TB40-REV-CAND-01` are **IMPLEMENTED / RUNTIME PENDING TB41**. Their runtime disposition is not promoted
by compilation. `M3-CP4c3-TB40-REV-CAND-02` remains **ACTIVE / GATING**; CB46 only adds the EB7.6 measurement
needed for TB41-REV to assign its next owner.

## 6. Exact successor boundary

CB46 freezes immutable **`M3-CP4c-3-TB41-EXEC`** against package106 and the byte-frozen selector409. TB41-EXEC
must execute only the packaged artifact/harness, one identity per fresh process, and must require at minimum:

- accepted ordinals 1–365 = **365/365 PASS**;
- 311/314/356/357 PASS through the non-vacuous content-derived anchor census;
- 312/315/409 PASS, preserving the production binding falsifiers;
- 390/393/406/407 PASS with non-empty later-frontier evidence independent of terminal enum;
- 404/408 PASS and source-face ownership **300/0/0**;
- 366/367 remain measured at `RegionSourceFaceOwningFragmentMissing` with source-face/owning-orbit/owner-census evidence unless pre-existing behavior proves otherwise;
- 368/369/370/374/398 remain under their existing owners;
- retired region-disc proxy codes remain absent and all package/source/selector/harness bytes remain immutable.

The complete successor contract is `Architecture_M3_CP4c3_TB41_Artifact_Only_Test_Benchmark_Plan.md`.
TB41-EXEC does not promote itself; its exact successor is independent `M3-CP4c-3-TB41-REV`.

**CB46 terminates here. No TB41 runtime is executed in this turn.**
