# M3-CP4c-2 TB-X2-R9 — Artifact-Only Test + Benchmark Report

Date: 2026-08-30 UTC
Status: **COMPLETE / VALID SEMANTIC RED AT ORDINAL 363 / REVIEW REQUIRED**

## 1. Boundary and immutable authority

`M3-CP4c-2-TB-X2-R9-EXEC` executed the frozen gate against immutable CB8 package **66** only. No source, test,
fixture, selector, or build logic was changed by the semantic run; no configure, compile, relink, repair, generated
discovery, or benchmark occurred.

- semantic/test source: `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`
- build transport source: `997d215e9ce0502f4a10afc62d08b2cd1fb3b037`
- package artifact: `9726295440`
- package SHA-256: `1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`
- packaged source SHA-256: `ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`
- selector 365 SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- accepted-prefix 355 SHA-256: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`

Immutable preflight passed package/source hashes, manifest **28/28**, GMP/GMPXX evidence, Eigen gitlink, clean build
source-status records, executable modes, selector cardinality/uniqueness, all frozen prefix hashes, and static identity
resolution. Selector ownership reproduced **219 producer / 30 authority-kernel / 75 completion / 41 validation**.

## 2. Authoritative execution

Authoritative run/job: **`33319911575 / 99279955697` — workflow SUCCESS / semantic RED**.

Evidence:
- result artifact `9734625006`, SHA-256 `d4cac956267b275b07f25857570b728b863470973ba7bfee0c47d4b8a9da3081`
- diagnostic log artifact `9734625165`, SHA-256 `9325840a0a68a2c6678e485aa2dc6a19311f9df041ab2b7764b415dea3274e10`
- 366 fresh Directional processes: 3 non-gating diagnostics + selector ordinals 1-363
- zero-selected processes: 0

Gate result:
- accepted predecessor **355/355 GREEN**
- ordinals **356-362 GREEN**
- ordinal **363 RED**: `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs`
- ordinals 364-365 **NOT RUN** under the frozen first-semantic-red hard stop
- selector result at stop: **362 passed / 363 executed**

`M3-CP4c2-TB-X2-R8-CAND-01` mechanically satisfies its frozen runtime closure condition in this valid run because
both corrected ordinals 359 and 361 pass and the run reaches 361. Formal disposition remains review-owned.
Criterion C3's ordinal 362 also passes. AH6 is **not applicable** because ordinals 363-365 were not all reached.

## 3. Non-gating diagnostics

All three frozen non-gating identities selected exactly once:

1. `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` — **RED**. It publishes
   `surfaceCutGraphError=CellularityNotEstablished` with direct
   `originatingTopologyError=RotationSystemInconsistent`; this confirms the existing sphere `CAND-04` provenance
   without gate credit.
2. `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable` — **PASS**.
3. `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating` — **PASS**.

The sphere red remains report-only/non-stable. Stable accounting is unchanged.

## 4. First semantic red and localized mechanism

Ordinal 363 proves the constructed witness actually has at least one exact trace/source-edge crossing, successfully
constructs a cellular `SurfaceCutGraph`, and selects at least one cut candidate classified
`TraceInteriorCrossing`. `GlobalTopologyPlan::make` then fails with typed `InvalidCutGraphBinding` at the test helper's
plan-build assertion (`FieldAlignedCurveNetworkTests.cpp:1710`). The helper's subsequent `built.value()` throws
`std::get: wrong index for variant`; that exception is secondary diagnostics fallout after the typed failure, not the
primary product result.

Immutable-source localization bounds the product contradiction:

- `EmbeddedGraphTopology.cpp:503-545` intentionally inserts every synthetic cut/trace crossing into the selected
  source edge's ordered points and emits one `GlobalTopologyArcKind::Cut` arc for each consecutive point pair. A
  trace-crossed selected source edge therefore owns multiple cut arcs by design.
- `GlobalTopologyPlan.cpp:479-499` gathers all Cut arcs carrying each `cutGraph.cut_edges()` source edge but rejects
  unless `arcIndices.size() == 1`, returning `InvalidCutGraphBinding` for the same source edge.

The first Amendment-14 witness therefore exposes a stale **one-source-cut-edge = one-derived-cut-arc** binding
assumption that contradicts the newly introduced synthetic crossing subdivision. This is recorded as
`M3-CP4c2-TB-X2-R9-CAND-01`, non-stable because CP4c-2 is still unaccepted and inherited 355/355 remains green.
Independent R9 review owns corrective planning; EXEC makes no implementation recommendation or change.

## 5. Immutability postflight

Postflight passed byte-and-mode inventories and the internal manifest. Published flags are all false:
`configure`, `compile`, `relink`, `repair`, `generatedDiscovery`, `sourceMutation`, `testMutation`, `fixtureMutation`,
`selectorMutation`, `packageMutation`, and `benchmarkExecution`. `postflightPass=true`.

## 6. Orchestration history

Three pre-authority attempts are explicitly non-semantic:

- schema run `33314981376` — startup failure from an insufficient reusable-workflow permission ceiling; zero jobs;
- execution run `33315131472` — artifact redirect/authentication failure before any Directional process;
- execution run `33319546759` — package extraction lost executable mode bits and preflight stopped before runtime.

The corrected caller was schema-valid on `33319885323`; only run `33319911575` is semantic R9 authority.

## 7. Accounting and successor

Stable regression accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains
**5**; authoritative M3 package count remains **66**. CP4c-2 remains open.

Exact successor: **`M3-CP4c-2-TB-X2-R9-REV`**, independent review/planning only. No runtime retry, implementation,
test/fixture mutation, compile, or benchmark is authorized before that review.
