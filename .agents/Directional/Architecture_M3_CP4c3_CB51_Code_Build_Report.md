# M3-CP4c-3-CB51 Code + Build Report

**Status:** COMPLETE / COMPILE + PACKAGE GREEN / RUNTIME-FREE
**Turn:** `M3-CP4c-3-CB51`
**Frozen authority:** `Architecture_M3_CP4c3_CB51_Code_Build_Plan.md`
**Semantic source:** `4f0663ef3468996abce6f59109f1c67f5be5f604`
**Runtime authority entering/leaving:** TB45/package110/selector409 — **399 PASS / 10 RED / 0 SKIP**, accepted **365/365**

## 1. Bounded implementation

CB51 changed only the three frozen paths:

- `include/directional/geometry/GlobalTopologyPlan.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

The semantic commit is `4f0663ef3468996abce6f59109f1c67f5be5f604`.

The implementation is limited to the TB45-REV corrective surface:

1. `independent_fragment_partition()` now omits a final no-barrier segment only when its independently derived
   forward/reverse face-walk orbits are equal. A terminal segment with distinct sides keeps the ordinary independent
   trace-piece, touched-edge, fragment-orbit and edge-orbit bookkeeping.
2. Successful `GlobalTopologyPlan` publication now carries producer-owned `RegionBuildSuccess.frontier` evidence
   through `RegionFrontierEvidenceDiagnostic`. Failure and success publication share
   `make_region_frontier_evidence_diagnostic(...)`; the evidence is observation-only and is not used to select cuts,
   build regions, validate certificates, elect owners or alter semantic control flow.
3. Protected identities 390/393/406/407 no longer require the mechanical plan to fail. They require a successful plan,
   consume its producer frontier evidence, evaluate the existing Part XII predicate against certifier census data,
   mutate a same-domain census copy, require that corruption to be rejected, and emit
   `terminalSubjectBranch=PlanFrontier` receipts.
4. Failure-only `TraceCutFaceFragmentCountMismatch.fragmentIncidences` now omits a syntactic terminal slit only when
   `forwardOrbit == reverseOrbit`; separating terminal segments remain in the diagnostic. The independent syntactic
   terminal-slit census is intentionally unchanged.

No fixture, selector409, Part VIII/XI/XII normative definition, carried RED owner, topology construction rule or
benchmark input changed.

## 2. Static review

The frozen CB51 checks were satisfied before compile:

- the independent oracle's terminal decision reads only its independently derived forward/reverse orbits;
- retained separating terminal segments execute the same independent bookkeeping as ordinary trace pieces;
- successful-plan frontier diagnostics are built from `RegionBuildSuccess.frontier` and the cut-graph certificate,
  not reconstructed from test expectations;
- publication is diagnostic-only; the candidate receives the diagnostic after certificate construction and before
  canonicalization without using it for semantic validation/control flow;
- 390/393/406/407 each retain a real-data predicate and deliberate same-domain corruption negative;
- the failure-only fragment-incidence path uses the separation conjunct while the syntactic terminal-slit census is
  unchanged;
- the semantic commit changes exactly the three frozen files above.

## 3. Patch application evidence

The preserved implementation patch was based on
`e44236cbfbe9be5c6614b1e89f4845c052aaecb5`, SHA-256
`4dfbca6a34267aede4cd4242f4cab690df26403796682a631fe0a2330c5080a5`, with exact intended paths matching the
three-file scope above. Durable Drive apply run/job `34370822097 / 102531331265` verified patch/base/body checks,
`git apply --check`, `git diff --check`, exact changed paths, committed and pushed semantic source
`4f0663ef3468996abce6f59109f1c67f5be5f604`, and executed no Directional runtime. Result/log artifacts are
`10111842393 / 10111843305`.

The consumed Drive transport file was permanently deleted by the owner-authorized control plane after successful
push.

## 4. Compile/package evidence

The first compile attempt (`34371115409 / 102532335603`) compiled the semantic source successfully but its caller
requested only core, pipeline and producer-tests targets. Its result artifact omitted the other executables required
by selector409. That artifact is retained only as invalid packaging-attempt provenance and is **not package111**.
No runtime executed in that attempt.

The diagnosed retry corrected only the temporary caller target list and rebuilt the same semantic source with the
complete historical selector409 executable set:

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

Accepted compile/package authority:

- workflow run/job: `34372482691 / 102536964376`
- exact source: `4f0663ef3468996abce6f59109f1c67f5be5f604`
- result artifact: `10112532452`, provider ZIP SHA-256
  `62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`
- log artifact: `10112533158`, provider ZIP SHA-256
  `2fc66875001184207e5ab59c8838eb95bca69219143ea53ce56e4b2a0ca315ff`
- packaged source archive SHA-256:
  `813d375e8ca38e65b01ea54a668cd067033def144eefe2f375b98a1a29ae0c37`
- build/preflight exit: `0 / 0`
- GMP authority: `libgmp-dev 2:6.3.0+dfsg-2ubuntu6.1`; link evidence contains `libgmpxx.so` and `libgmp.so`
- package contains all six required executables plus `libdirectional_core.a` and `libdirectional_pipeline.a`
- package root `SHA256SUMS`: **28/28 verified**; the manifest excludes itself
- all packaged source-status controls are empty
- package metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `exactArithmeticBackend=GMP`

The downloaded ZIP was independently re-hashed to the provider digest and its root manifest was reverified without
executing any packaged binary.

## 5. Accounting and authority

CB51 changes no semantic runtime ledger. TB45/package110 remains the latest runtime authority until TB46 executes.
Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, ownership
**300/0/0**. Accepted immutable package count advances **110 → 111**.

Selector409 remains byte-frozen at SHA-256
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

## 6. Exact successor

Exactly one successor plan is frozen:
`.agents/Directional/Architecture_M3_CP4c3_TB46_Artifact_Only_Test_Benchmark_Plan.md`.

**Exact next:** `M3-CP4c-3-TB46-EXEC` — Test + Benchmark / artifact-only. CB51 does not execute TB46.
