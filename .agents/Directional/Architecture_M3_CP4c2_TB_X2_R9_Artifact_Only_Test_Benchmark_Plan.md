# M3-CP4c-2 TB-X2-R9 — Artifact-Only Test + Benchmark Plan

Date: 2026-08-30 UTC
Status: **FROZEN EXECUTION PLAN / NOT YET EXECUTED**

## 1. Purpose and boundary

`M3-CP4c-2-TB-X2-R9-EXEC` is the sole immediate successor to CB8. It consumes immutable GMP package **66** and
executes the already-frozen CP4c-2 gate. It is **artifact-only**: no source/test/fixture/selector/build-logic change,
configure, compile, relink, repair, generated test discovery, package mutation, or executable-mode repair is
permitted.

The turn does not implement a fix and does not auto-accept CP4c-2. It records runtime evidence, applies the frozen
first-semantic-red stop rule, updates the regression tracker for every observed red/candidate, performs unconditional
immutability postflight, and hands the result to independent review. No benchmark is frozen for R9;
`benchmarkExecution=false` is required.

## 2. Immutable authority

R9 must bind exactly:

- semantic/test source: `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`
- successful build-transport source: `997d215e9ce0502f4a10afc62d08b2cd1fb3b037`
- package artifact: `9726295440`
- package ZIP SHA-256: `1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`
- packaged source archive SHA-256: `ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`
- compile/package run/job: `33292137782 / 99205507393`
- exact Eigen gitlink: `769c72fd8019e389810d1de1e7c243521a43b594`
- exact arithmetic backend: GMP/GMPXX
- selector 365 path: `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt`
- selector 365 SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- frozen prefixes: 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`;
  357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`;
  361 `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`.

Any mismatch is an **integrity stop**, not a semantic red.

## 3. R9-0 immutable preflight

Before any Directional process:

1. download package artifact `9726295440` once and verify its outer SHA-256;
2. materialize the package without flattening its recorded path layout;
3. verify the packaged source archive SHA-256 and all internal `SHA256SUMS` entries (**28/28 expected**);
4. verify packaged source-status records are clean and exact Eigen gitlink matches;
5. verify compile metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and GMP/GMPXX linkage;
6. preserve executable modes exactly as packaged; **no `chmod`, repair, relink, or generated discovery**;
7. recompute selector 365, 361, 357, and 355 hashes from packaged bytes and require exact matches;
8. require selector cardinality/uniqueness **365 / 365** and resolve each required identity exactly once from the
   packaged source/test authority without running generated discovery;
9. record preflight byte/mode inventories for unconditional postflight comparison.

Only after all preflight checks pass may the execution phase begin.

## 4. R9-1 frozen non-gating evidence

Run each of these **once in its own fresh process**, report the result, and exclude it from the 365 gate count:

1. `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable`
2. `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`
3. `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating`

A semantic red in these identities is report-only and does not consume the gate or authorize repair. An integrity,
selection-cardinality, process-control, or orchestration failure stops execution as invalid evidence. Preserve AF0's
real `originatingTopologyError`, AF2's withdrawn-barrier-proxy labeling, and AG3's independent actual-graph records.

## 5. R9-2 required-green selector 365

Execute selector **365 from ordinal 1**, exactly one identity per fresh process, in file order. Every process must
select exactly one test and publish an unambiguous ordinal/identity/exit record.

### Hard stop

The first semantic red in the required-green selector immediately stops later selector ordinals. Do not retry,
continue past the red, repair the package, or reinterpret an unexecuted identity as green. Unconditional postflight
still runs.

### Accepted predecessor requirement

Ordinals **1-355 must re-prove 355/355 PASS**. Any red in 1-355 is an accepted-predecessor regression and must be
fully categorized in `Regression_Root_Cause_Tracker.md` before R9 closes.

### CP4c-2 tail ownership

If reached, record each tail ordinal explicitly:

- 356 `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`
- 357 `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`
- 358 `SurfaceCutGraph.AlreadyCellularNetworkPublishesEmptyCertifiedCutSet`
- 359 `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` — AD3 falsifier
- 360 `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness`
- 361 `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness`
- 362 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` — criterion C3 owner
- 363 `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs`
- 364 `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour`
- 365 `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted`

`M3-CP4c2-TB-X2-R8-CAND-01` may close only if **both 359 and 361 pass in the same valid run reaching 361**. A pass at
359 alone is insufficient because 361 is the second corrected closed-witness identity.

## 6. AH6 — ordinary-path versus saturation coverage

AH6 is mandatory if ordinals 363-365 are reached. Runtime evidence must determine and publish whether the
trace-crossed source edge used by the Amendment-14 witness was selected by the **ordinary tree-cotree proposal path**
or only by the explicit **saturation last resort**.

Required publication must distinguish at least:

- ordinary proposal selected the trace-crossed edge: yes/no;
- saturation used: yes/no;
- saturation locus / promoted-edge count when used;
- the selected trace-crossed edge and its exact crossing/subdivision evidence;
- whether ordinals 363/364 are proving the ordinary path or only a state reached after saturation.

If the trace-crossed witness is **saturation-only**, record a new **non-stable coverage candidate** and keep CP4c-2
open even if 365/365 is green. The owed corrective measure is a second witness that exercises the ordinary
trace-crossed proposal path. Do not add or implement that witness in R9.

`M3-CP4c2-TB-X2-R8-CAND-02` remains a separate non-gating product question. R9's required gate no longer depends on
the zero-node/zero-arc closed-surface input and must not infer its contract from unrelated gate results.

## 7. R9-3 regression and candidate accounting

For every observed red or materially new behavior:

1. preserve exact ordinal, identity, process output, and failure locus;
2. distinguish accepted-prefix regression, newly gated witness/product red, non-gating diagnostic red, orchestration
   failure, and immutable-package integrity failure;
3. update `Regression_Root_Cause_Tracker.md` before closeout;
4. change stable event/category/recurrence totals only when evidence satisfies the stable-regression policy;
5. otherwise create/update a candidate/non-stable record and state why stable totals remain unchanged.

Starting stable accounting is **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, M3
packages **66**.

## 8. R9-4 unconditional postflight

Run postflight regardless of gate outcome. Require:

- package and materialized-source byte inventories equal preflight;
- executable modes equal preflight;
- internal manifest re-verifies;
- selector and fixture bytes are unchanged;
- `configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`;
- `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `selectorMutation=false`,
  `packageMutation=false`;
- `benchmarkExecution=false`.

A postflight mismatch invalidates the semantic result until independently adjudicated.

## 9. Evidence package

Retain one result artifact and one diagnostic/activity-log artifact containing at minimum:

- immutable authority and all preflight results;
- per-process ordinal/identity/run-count/exit records;
- non-gating diagnostic records;
- first-red stop record or final 365/365 green summary;
- AH6 publication when applicable;
- postflight inventories and mutation/build flags;
- raw stdout/stderr needed to adjudicate every red/candidate.

Do not delete immutable Actions evidence during closeout.

## 10. Stop and successor

R9 performs no implementation and grants no automatic CP4c-2 acceptance. After durable R9 evidence/tracker closeout,
stop at **`M3-CP4c-2-TB-X2-R9-REV`**, independent review/planning. The review owns final interpretation of a red,
R8-CAND-01 closure, AH6 coverage, criterion C3, AD3, and any eligibility to close CP4c-2. CP4c-3 remains blocked.
