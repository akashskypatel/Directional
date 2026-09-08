# M3-CP4c-3-CB45 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 105 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Final semantic source:** `0f09439893182235c382492583b82aa35f25045c`
**Authoritative compile run/job:** `34229976475 / 102073447794`
**Immutable result artifact:** `10057456162` / `m3-cp4c3-cb45-result-34229976475`
**Result ZIP SHA-256:** `c9cd0397d22b7cc0c343838a90fdcfe649137fa37a985453778c04731049b99e`
**Persistent compile-log artifact:** `10057456585` / `m3-cp4c3-cb45-log-34229976475`
**Compile-log ZIP SHA-256:** `69c193b501dddfda1966106ec5c6ff5a3ca6e303e1598a9ea0030ef2660cb64f`
**Packaged source archive SHA-256:** `7d1cb457d1101e6addbadd732d783efdae956f61b9732b492c1b9063828a6472`

## 1. Scope and boundary

CB45 implements EA0–EA9 of the consumed `Architecture_M3_CP4c3_CB45_Code_Build_Plan.md` under
`M3_CP4c_Frozen_Definitions.md` Part XI and the Part XI-A verification amendment. It changes the downstream A2b
region-disc proof from a source-support proxy theorem into an exact binding/consumption certificate for the
matching A2a′ actual-embedded face certificate, while preserving field regularity as a separate obligation.

No Directional runtime, test, benchmark, generated discovery/list/help/version command, fuzzer, produced binary,
or artifact-only gate was executed during CB45. Both compile attempts recorded `runtimeExecution=false`. The
current semantic runtime authority therefore remains **TB39 / package104 / selector409 402 PASS / 7 RED,
accepted 365/365**, pending artifact-only TB40 execution of package105.

## 2. Implementation result

### EA0–EA1 — exact region → orbit → upstream-face binding

`GlobalTopologyRegionDiscCertificate` now carries:

- the region ID;
- the exact `SurfaceCutGraphFaceCertificate actualEmbeddedFace`;
- separate interior-field-regularity evidence and boundary singularity IDs.

`build_region_certificate(...)` re-derives the region's current face-walk orbit from exact ordered boundary
equality, requires exactly one upstream `SurfaceCutGraphFaceCertificate` for that orbit, verifies its boundary-arc
cardinality and `proves_disc_topology()`, then copies that exact certificate into the downstream binding
certificate. `proves_disc_topology()` delegates to the consumed upstream face authority.

The semantic digest consumes the upstream certificate's orbit, walk count, arc count, and cellularity bit rather
than the retired source-support proxy counts.

### EA2 / EA4 — proxy topology theorem retired; field regularity remains separate

The canonical region certificate no longer owns `sourceFacesConnected`, reduced/full V/E/F values, or an
independent Euler-characteristic predicate. `RegionEulerCharacteristicNotOne` and
`RegionInteriorDisconnected` are no longer emitted by canonical region certification. Source-support fragment
connectivity is retained only as an observation.

Field regularity remains independently represented by `interiorSingularityFree` and
`boundarySingularities`; binding to an upstream disc face does not imply field regularity.

### EA3 / EA6 — copied candidates re-derive authority; frozen identities preserved

Checked candidate validation re-derives boundary → current orbit → upstream face after copy/mutation and compares
the carried certificate with the uniquely derived upstream certificate. The existing 312/409 mutation seam
therefore cannot retain stale construction-time authority.

Existing proof/oracle helpers were re-aimed to the exact producer/consumer relation. Ordinal 315 now tampers a
varying binding field (`orbit`) and replaces the carried upstream certificate from a different region rather than
tampering a retired proxy count. No selector file changed.

### EA5 / Part XI-A — support diagnostics are explicitly diagnostic; complex authority is emitted once

The former reduced/full certificate fields were moved into `RegionSupportProjectionDiagnostics` and named by
their source-support domain (`interiorVertexCount`, `interiorAdjacencyCount`, `totalVertexCount`,
`totalEdgeCount`, `fragmentCount`, `reducedEulerCharacteristic`,
`wholeSourceFaceEulerCharacteristic`). They no longer participate in disc-topology acceptance.

The existing proof helper now emits one `M3_CP4C3_FACE_BINDING_CENSUS record=complex` row containing the
Part XI-A complex-level cellularity inputs:

`graphComponents`, `sourceComponentCount`, `exteriorSize`, `boundaryLoops`, `graphEuler`, `sourceEuler`.

It then emits one binding row per region while independently deriving the orbit and requiring unique consumption
of all upstream face certificates. This is compile-time source evidence only; TB40 owns the non-vacuous runtime
census.

## 3. Exact semantic source changes

The initial preserved implementation patch was based on
`512ba0388f83a6c5f111f034a11ad03b456483a5` and touched exactly five files:

- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

Its verified patch SHA-256 is
`09f6c778f45874e555f9c5e60a917471bcfb9d970d515a4850152f6bd69bc78b`; embedded diff-body SHA-256 is
`731c76913dd2c5a0d54b87423fbc03c5587fe70915f5b48ad918d479565d167f`. The applied semantic commit was
`e03c29a42c4528013476292333a84c6af1d6aff4` with **201 insertions / 343 deletions**.

The first compile exposed one bounded stale test formatter that still referenced four certificate fields removed
by EA1. No runtime had started. The repair changed only that diagnostic formatter to serialize
`actualEmbeddedFace` and field-regularity state. The user-visible repair preservation patch SHA-256 was
`69e57732f17235c6feabb68b6d9fcf71b69407486547f243fe94fac0f83ba248`; final semantic commit is
`0f09439893182235c382492583b82aa35f25045c`.

## 4. Compile and immutable package evidence

The first compile run `34229136762 / 102070613610` configured successfully with GMP/GMPXX and compiled the core
preflight target, then stopped while compiling `tests/FieldAlignedCurveNetworkTests.cpp` because its diagnostic
formatter referenced removed members `vertexCount`, `edgeCount`, `faceCount`, and `eulerCharacteristic`.
The failure was compile-only and recorded `runtimeExecution=false`; it produced no semantic package.

After the bounded formatter repair, authoritative retry `34229976475 / 102073447794` compiled and linked all
approved targets successfully against exact source `0f09439893182235c382492583b82aa35f25045c`:

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
- GMP 6.3.0 with both GMPXX and GMP linked;
- preflight exit `0`, build exit `0`;
- final packaged source status empty;
- fixed reusable compiler-cache namespace.

Package105 root `SHA256SUMS` verifies **28/28 PASS** and excludes itself.

Frozen execution authority is byte-preserved:

- selector409: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 prefix: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- artifact-only harness: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- packaged `tests/FieldAlignedCurveNetworkTests.cpp`:
  `7f683267354783068443ffe02f3798723b524633bfb4fc70bca717ce4de80b4d`.

The selector and harness hashes are byte-identical to package104. The test source hash changes exactly because CB45
implements the frozen existing-oracle rebinding and the bounded compile repair; no selector identity changed.

## 5. Accounting and authority after CB45

CB45 creates **one new semantic package and no runtime event or recurrence**:

- current semantic runtime authority remains **M3-CP4c-3-TB39 / package104**;
- TB39 remains selector409 **402 PASS / 7 RED**, accepted **365/365**, RED
  `[366,367,368,369,370,374,398]`;
- current immutable build authority is **package105**, source
  `0f09439893182235c382492583b82aa35f25045c`, artifact `10057456162`;
- stable accounting remains **46 events / 14 categories / 32 recurrences**;
- produced-witness debt remains **5**;
- semantic M3 package count advances **104 → 105**.

`M3-CP4c3-TB37-REV-CAND-01` is **IMPLEMENTED / RUNTIME PENDING TB40 / RP-01**.
`M3-CP4c3-TB39-EXEC-CAND-01` is **IMPLEMENTED / RUNTIME PENDING TB40 / NON-STABLE / RP-01**.
No runtime classification is promoted by this compile.

## 6. Exact successor boundary

CB45 freezes immutable `M3-CP4c-3-TB40-EXEC` against package105 and the byte-frozen selector409. TB40 must execute
only the packaged artifact/harness, one identity per fresh process, and must require:

- accepted 1–365 = **365/365**;
- ordinals **312/409 PASS**;
- ordinals **390/393/404/406/407/408 PASS**;
- ownership **300/0/0** and retired-code silence;
- the separately owned 368/369/370/374/398 surfaces remain under their existing owners;
- a non-empty 1:1 region/upstream-face binding census on every creditable A2b witness;
- one complex-level cellularity row per complex with the Part XI-A inputs;
- 366/367 are not rejected solely by retired `RegionEulerCharacteristicNotOne` /
  `RegionInteriorDisconnected` proxy authority;
- package/source/execution-view byte and mode censuses remain unchanged.

The dedicated successor contract is `Architecture_M3_CP4c3_TB40_Artifact_Only_Test_Benchmark_Plan.md`.

**CB45 terminates here. TB40 runtime is not executed in this turn.**
