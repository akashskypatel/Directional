# M3-CP4c-3-CB35 — Code + Build Report

- **Phase:** `M3-CP4c-3-CB35`
- **Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
- **Execution mode:** canonical Code + Build
- **Starting semantic authority:** `c12e459117eb9c54d6f279f565df1b02e04769f0`
- **Built evidence commit:** `ab86747bdfdb94c7c383bf5d2893ced4207eb555`
- **Semantic test-authority commit:** `7bcf578984a1c650df58abbccb73ed8e1ed0a395`
- **Disposition:** **COMPLETE / COMPILE GREEN / RUNTIME NOT EXECUTED / TB30 REQUIRED**

## Implemented

CB35 executes CO6–CO8 from `M3-CP4c-3-TB29-REV`: **test authority and evidence transcription only; no product change**.

1. **Ordinal 404** — `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure`
   - Removed only the final loop that required every component face to have ownership status other than `Established`.
   - Retained publication, completeness, truncation, face-set-digest, row-field, and incidence assertions.
   - The identity no longer asserts that the defect under repair must remain present.
2. **Ordinal 390** — `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure`
   - Stopped locating the comparison census by numeric component index.
   - First seeks exact correspondence by failing-component face-set digest.
   - If the published relation says the failing component is a subset of a census component, uses the published census face-set digest.
   - Only compares certifier-side count with census seed-orbit count on exact face-set correspondence.
   - If no census corresponds, asserts the published non-subset relation and retains only plan-side assertions.
3. **No selector mutation.** Selector 408 remains 408 identities, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`; accepted selector 365 and selectors 397/401/403/405/406/407/408 are byte-unchanged. Ordinal 398 is untouched.

No production source, fixture, benchmark, build-system, or reusable-workflow permission changed.

## Engineering-Guideline Review

- **Material assumption surfaced:** component numbers are local to their partition domain and are not cross-partition identity.
- **Simplest sufficient approach:** change only the two invalid witness rules identified by independent review.
- **Why no smaller approach works:** 390 needed a semantic correspondence key; 404 needed deletion of an explicitly out-of-contract defect-presence assertion.
- **Unrelated refactors/style drift avoided:** yes.
- **Every semantic changed line traces to CO6:** yes; there is no product-line change.

## Files Changed

Semantic tree delta:

- `tests/FieldAlignedCurveNetworkTests.cpp` — test authority only, net `+33/-19`.

Turn closeout additionally changes durable report/plan/status documentation only.

## Domain Invariants

- Accepted 1–365 selector bytes are untouched.
- Current selector 408 bytes are untouched.
- 366/367/398 product behavior is untouched.
- 404 predicts no ownership value.
- 390 does not equate partition components by integer index.
- No second product correction is authorized.
- Stable regression accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**.

## Generalization Review

390 now uses published semantic partition evidence rather than a particular component number; 404 removes a universally invalid defect-presence condition. Only these two test witnesses change. Ordinal 398 and accepted 1–365 remain the independent safety guards, and TB30 re-runs the complete 408-identity gate.

## CO7 — post-correction TB29 census transcription

This section transcribes existing immutable TB29 runtime evidence from diagnostic-log artifact `9980019636`. It is **not** a new runtime, diagnostic, or measurement.

### Failing plan component

- component: `0`
- domain: `EmptyFragmentOrbits`
- face count: **191**
- face-set digest: **`17919102493633069558`**
- seed count/state: **3 / `Multiple`**
- fragment-owner evidence: `component=0,faceCount=191,seedCount=3,seedState=Multiple,seedOrbitCount=3,seedOrbitsTruncated=false,seedOrbits=[0,1,3]`

### Published comparison census

- component: `0`
- domain: `NotTraceCut`
- face count: **212**
- face-set digest: **`835099723348023536`**
- `matchesFailingComponent=false`
- `failingComponentSubsetOfCensusComponent=false`
- `boundaryEdges=74`, `interiorArcs=2`, `vertexTransits=50`, `seedAttributions=43`

The matching numeric component index is explicitly **not** semantic correspondence.

### Every post-correction uncut-census interior-arc row

Only arcs 20 and 24 remain interior to the `NotTraceCut` census; both have equal dart orbits `0 / 0`.

| Row | Arc | Orbits | Crossed face | Certifier | Plan | Reason |
|---:|---:|---|---|---|---|---|
| 0 | 20 | `0 / 0` | `36,38,39` | `0` | absent | `TerminalSlit` |
| 0 | 20 | `0 / 0` | `39,40,41` | absent | absent | none |
| 0 | 20 | `0 / 0` | `41,42,43` | absent | absent | none |
| 0 | 20 | `0 / 0` | `43,44,45` | absent | absent | none |
| 0 | 20 | `0 / 0` | `45,46,47` | absent | absent | none |
| 1 | 24 | `0 / 0` | `66,67,120` | `0` | absent | `TerminalSlit` |
| 1 | 24 | `0 / 0` | `67,68,124` | absent | absent | none |
| 1 | 24 | `0 / 0` | `68,69,128` | absent | absent | none |
| 1 | 24 | `0 / 0` | `69,70,132` | absent | absent | none |
| 1 | 24 | `0 / 0` | `70,71,92` | absent | absent | none |

The separately published failing-plan interior-arc census also contains only arcs 20 and 24 (`0 / 0`); its terminal faces `36,38,39` and `66,67,120` remain in plan component 0. Separating arcs 14 and 22 are absent from the post-correction uncut census.

### Certified owner publication over all 300 source faces

```text
m3Cp4c3CertifiedOwnerPublication;sourceFaceCount=300;established=300;unavailable=0;conflicting=0;conflictCensusPublished=true;conflictRowCount=0
```

Publication is therefore **300 established / 0 unavailable / 0 conflicting**. This does not itself make 366/367/398 green; they exercise additional production-path obligations.

### Failing assertion text for every TB29 RED

The immutable log is complete authority. The first failing assertion/exception surface is transcribed without duplicating the full 191-face enumeration embedded in the 366/367 exception.

- **366 — `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`**
  ```text
  unknown file: Failure
  C++ exception with description "mechanical feature pipeline did not retain CP4c topology authority:
  NotProductionReady/global-topology-plan/UncutFaceComponentOrbitSeedNotUnique;
  detailCode=UncutFaceComponentOrbitSeedNotUnique;sourceFace=10,79,151;
  ...;uncutFaceComponent=0;uncutFaceComponentSeedCount=3;
  uncutFaceComponentSeedState=Multiple;uncutFaceComponentFaceCount=191;
  ...;fragmentOwnerComponent[0]={component=0,faceCount=191,seedCount=3,seedState=Multiple,
  seedOrbitCount=3,seedOrbitsTruncated=false,seedOrbits=[0,1,3]};..."
  ```
- **367 — `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`**
  ```text
  unknown file: Failure
  C++ exception with description "mechanical feature pipeline did not retain CP4c topology authority:
  NotProductionReady/global-topology-plan/UncutFaceComponentOrbitSeedNotUnique;
  detailCode=UncutFaceComponentOrbitSeedNotUnique;sourceFace=10,79,151;
  ...;uncutFaceComponent=0;uncutFaceComponentSeedCount=3;
  uncutFaceComponentSeedState=Multiple;uncutFaceComponentFaceCount=191;..."
  ```
- **368 — `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:9207: Failure
  Value of: sphere.cutGraph.has_value()
    Actual: false
  Expected: true
  prescribed sphere: ... surfaceCutGraphError=CellularityNotEstablished;
  originatingTopologyError=RotationSystemInconsistent;
  originatingRotationSystemReason=TraceEventPositionInvalid;trace=2;traceEvent=30;
  traceEventPositionFailure=NoCarrierMatch;traceEventPositionPass=SourceEdgeUnavailable
  ```
- **369 — `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:9241: Failure
  Value of: certificate.saturationUsed
    Actual: true
  Expected: false
  the selected trace-crossed edge must come from the ordinary tree-cotree proposal, not the saturation fallback
  ```
- **370 — `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:9276: Failure
  Expected equality of these values:
    directional::geometry::SurfaceCutGraphErrorCode::EmptyNetworkOnClosedSurface
      Which is: 1-byte object <06>
    cutGraph.error().code
      Which is: 1-byte object <04>

  tests/FieldAlignedCurveNetworkTests.cpp:9279: Failure
  Value of: cutGraph.error().sourceFace.has_value()
    Actual: false
  Expected: true
  the typed empty-network rejection must carry a source-face locus
  ```
- **374 — `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:9963: Failure
  Value of: atlasBuild
    Actual: false
  Expected: true
  ```
- **390 — `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:11575: Failure
  Expected equality of these values:
    *locus.uncutFaceComponentCertifiedFaceDistinctCount
      Which is: 3
    attribution->seedOrbits.size()
      Which is: 1
  ```
- **398 — `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:14146: Failure
  Value of: fixture.cutGraph.has_value()
    Actual: false
  Expected: true
  prescribed sphere:NotProductionReady/CellularityNotEstablished
  ```
- **404 — `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure`**
  ```text
  tests/FieldAlignedCurveNetworkTests.cpp:14350: Failure
  Expected: (SurfaceCutGraphSourceFaceOwnershipStatus::Established) != (owner->status),
  actual: 1-byte object <00> vs 1-byte object <00>
  ```
  This repeated for multiple established owners; CB35 deletes only that loop.

## Static Verification

- `git diff --check` passed on the source/test change.
- The exact work-preservation patch passed `git apply --check` against snapshot source `c12e459117eb9c54d6f279f565df1b02e04769f0`.
- Intended changed-path set was exactly `tests/FieldAlignedCurveNetworkTests.cpp`.
- No Directional binary was executed; selector files were untouched.

## Work Preservation and Application

Preserved patch: `Directional__M3-CP4c-3-CB35__base-c12e459117eb__work-preservation.patch`

- patch SHA-256: `341655cf7ac5f5fc6c1e6c97ece0227216196d0a211422b0a052244b3b83289e`
- diff-body SHA-256: `630885cbae15d24a8306e94e41004796a5d881f39caebbc4aa12315eeced4970`
- Drive staging file ID: `1bBwC-YbXXDWPyNmj_aVphdx2NImJVGX_`
- Drive-apply run: `34005244239`
- semantic commit: `7bcf578984a1c650df58abbccb73ed8e1ed0a395`
- durable Drive application succeeded and retired the consumed staging file.
- temporary source-snapshot and Drive-apply caller/trigger files were retired after evidence capture.

## Build

The semantically equivalent clean tree at **`ab86747bdfdb94c7c383bf5d2893ced4207eb555`** compiled through `.github/workflows/agent-compile-reusable.yml`.

- compile run: **`34005311571`** — **SUCCESS**
- result artifact: **`9980764888`**, `m3-cp4c3-cb35-result-34005311571`
- result/provider ZIP SHA-256: **`ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`**
- persistent log artifact: **`9980765148`**
- log artifact SHA-256: **`b7333c208cf47c6e00cd52e781e62e60ac97932185ea4b4bd02f13483706f297`**
- packaged source archive SHA-256: **`64801a38ccbe9de282dbec261cad6c2b6575403ed38e93b514c893c22f03684a`**
- root `SHA256SUMS`: **28/28 PASS**
- preflight compile exit: **0**; full build exit: **0**
- package source status before/after configure/build/final: **empty**
- boundary: `turnBoundary=Code+Build-only`, `runtimeExecution=false`, `preflightCompile=true`, `exactArithmeticBackend=GMP`
- GMP evidence links both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`
- all eight required targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

**Tests/benchmarks executed: none.** The successful package advances semantic M3 package count **94 → 95**.

## Granular Loop Summary

- CB-DRAFT preservation patch: SHA-256 `341655cf7ac5f5fc6c1e6c97ece0227216196d0a211422b0a052244b3b83289e`
- CB-APPLY: run `34005244239`, semantic commit `7bcf578984a1c650df58abbccb73ed8e1ed0a395`
- CB-COMPILE: run `34005311571`
- Compile failures: none
- Final CB-COMPILE result: **PASS**
- Temporary compile caller and trigger retired after terminal evidence capture.

## Known Risks

- 390 and 404 are not runtime-proved until TB30.
- 366/367/398 must remain RED in TB30 because CB35 changed no product behavior; an unexpected PASS makes execution suspect until reviewed.
- 368/369/370/374 are carried separate-owner surfaces.
- The owner publication is 300/300/0/0, but the production witness still failed its multi-seed guard in TB29.
- No product correction is authorized before TB30-REV.

## Mandatory Test + Benchmark Plan

- **Plan:** `Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md`
- **Evidence source/artifact:** `ab86747bdfdb94c7c383bf5d2893ced4207eb555` / `9980764888`
- **Complete gate:** selector 408, one identity per fresh process.
- **Required corrected witnesses:** **390 PASS, 404 PASS**.
- **Credibility controls:** **366 RED, 367 RED, 398 RED**.
- **Accepted boundary:** **1–365 = 365/365 PASS**.
- **Benchmarks:** none.

## Next Turn

Type: artifact-only Test + Benchmark
Exact next: **`M3-CP4c-3-TB30-EXEC`**
Then: **`M3-CP4c-3-TB30-REV`**, evidence review only.

CB35 stops here and does **not** execute TB30.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `ab86747bdfdb94c7c383bf5d2893ced4207eb555`
- Test plan: `Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md`
- Semantic runtime authority remains TB29 (399 PASS / 9 RED, accepted 365/365) until TB30 is validly reviewed.
- New lesson: none; CB35 applies existing lessons against defect-presence assertions and partition-index matching.
