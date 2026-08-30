# M3-CP4c-2 TB-X2-R10-EXEC — Artifact-Only Test + Benchmark Report

Date: 2026-08-30 UTC
Status: **COMPLETE / EXECUTION VALID / SELECTOR 365/365 GREEN / REVIEW PENDING**

## 1. Boundary and authority

This record is the raw-evidence closeout for `M3-CP4c-2-TB-X2-R10-EXEC` only. It does not perform the R10 review, classify candidates, mutate the regression tracker, accept CP4c-2, or authorize CP4c-3.

Immutable authority:

- semantic/test source: `57444781af7bdc460e38cc68930a9a8c8199eeea`
- compile run / package job: `33325344311 / 99294619815`
- package artifact: `9736088354`
- package ZIP SHA-256: `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`
- packaged source archive SHA-256: `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`
- selector 365 SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- selector cardinality / uniqueness: **365 / 365**
- exact arithmetic backend inherited from the immutable package: GMP/GMPXX
- benchmark execution: **false**

## 2. Authoritative execution

GitHub Actions run/job:

- run: `33331453506`
- execute job: `99310594268`
- result artifact: `9737796927` (`m3-cp4c2-r10-result-33331453506`)
- result artifact SHA-256: `b02022367785d6a4790549ad127bff69f831404b6ea525f426b707794f71649b`
- diagnostic log artifact: `9737797177` (`m3-cp4c2-r10-log-33331453506`)
- diagnostic artifact SHA-256: `0a374b6b240877049eacfec2c70be944c39ce3cc4e5a6c461c358a1b206e78c8`

Execution interval recorded by the frozen payload: `2026-08-30T19:38:57.357497+00:00` through `2026-08-30T19:42:14.419658+00:00`.

Preflight was green: package hash, internal manifest **28/28**, packaged source hash, source-status records, GMP/GMPXX metadata, executable modes, selector hashes/cardinality/uniqueness, and exact identity resolution all passed before Directional runtime began.

## 3. Frozen non-gating evidence

Each non-gating identity executed once in its own process and remained excluded from the 365 gate count:

1. `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` — **RED**
2. `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable` — **PASS**
3. `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating` — **PASS**

Raw summary: **3 executed / 2 PASS / 1 RED**. The red is report-only in EXEC; its diagnosis/disposition remains owned by R10-REV.

## 4. Required-green selector

The selector executed from ordinal 1, one identity per fresh process, with no semantic hard stop because every identity passed.

- ordinals **1-355: 355/355 PASS**
- 356 `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` — **PASS**
- 357 `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` — **PASS**
- 358 `SurfaceCutGraph.AlreadyCellularNetworkPublishesEmptyCertifiedCutSet` — **PASS**
- 359 `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` — **PASS**
- 360 `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` — **PASS**
- 361 `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` — **PASS**
- 362 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` — **PASS**
- 363 `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` — **PASS**
- 364 `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour` — **PASS**
- 365 `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted` — **PASS**

Final raw selector result: **365 executed / 365 PASS / first red = none**.

The frozen payload publishes `r9Cand01RuntimeClosureCondition=true`; formal candidate disposition remains R10-REV-owned.

## 5. AI2 runtime publication at ordinal 363

Ordinal 363 ran once with `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1` in that same gate process and passed.

The retained `ai2-fragment-orbit-evidence.txt` contains:

- `gate_process_status=PASS`
- `typed_terminal_result=SUCCESS`
- `diagnostic_row_count=178`
- **50** `record=fragment_reconciliation` rows
- **128** `record=cut_edge_orbit_evidence` rows

The raw rows publish `fragment_orbit_count`, `trace_piece_count`, `expected_fragment_count`, and per-face cut-edge `orbit_count`. Their interpretation and the required explicit comparisons belong to R10-REV.

## 6. AH6 raw publication

Because ordinals 363-365 were all reached, AH6 is applicable. The frozen payload published:

- ordinals 363 / 364 / 365: **PASS / PASS / PASS**
- `ordinary_proposal_selected_trace_crossed_edge=no`
- `saturation_used=yes`
- `saturation_locus_exists=yes`
- `saturation_promoted_edge_count_positive=yes`
- `selected_trace_crossed_edge_exists=yes`
- `subdivided_crossing_exists=yes`
- exact selected edge, exact saturation locus, and exact promoted-edge count: `NOT_OBSERVABLE_FROM_FROZEN_TEST_OUTPUT`
- raw path classification: `saturation-reached state, not ordinary trace-crossed proposal coverage`
- raw coverage disposition: `RAW_SATURATION_ONLY_EVIDENCE_FOR_R10_REV`
- `cp4c2_auto_close_eligible=false`

This section records the EXEC publication only. Candidate creation, coverage disposition, and CP4c-2 acceptance eligibility are R10-REV work.

## 7. Unconditional postflight

Postflight passed. Raw flags:

- `configure=false`
- `compile=false`
- `relink=false`
- `repair=false`
- `generatedDiscovery=false`
- `sourceMutation=false`
- `testMutation=false`
- `fixtureMutation=false`
- `selectorMutation=false`
- `packageMutation=false`
- `benchmarkExecution=false`
- `postflightPass=true`

Package and materialized-source inventories matched preflight, and the internal package manifest re-verified.

## 8. Handoff

`M3-CP4c-2-TB-X2-R10-EXEC` is complete and execution-valid. It does **not** accept CP4c-2 by itself.

Exact next subturn: **`M3-CP4c-2-TB-X2-R10-REV`**.

R10-REV owns every regression/candidate classification, `Regression_Root_Cause_Tracker.md` update, `R9-CAND-01` formal disposition, AI2 interpretation, AH6 coverage disposition, and CP4c-2 acceptance/next-step decision.

Starting review accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, authoritative M3 packages **67**.
