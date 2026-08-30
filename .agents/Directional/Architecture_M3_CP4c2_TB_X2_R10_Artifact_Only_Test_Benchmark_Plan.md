# M3-CP4c-2 TB-X2-R10 — Artifact-Only Test + Benchmark Plan

Date: 2026-08-30 UTC
Status: **FROZEN EXECUTION PLAN / NOT EXECUTED**

## 1. Purpose and split boundary

R10 is the canonical Test + Benchmark successor to CB9 and is split into two bounded subturns:

1. **`M3-CP4c-2-TB-X2-R10-EXEC`** — immutable package verification plus runtime execution only. Preserve raw evidence; do not diagnose beyond process/integrity control needed to execute the frozen plan, do not edit durable product/test/fixture/build logic, and do not create corrective implementation.
2. **`M3-CP4c-2-TB-X2-R10-REV`** — consume the immutable R10-EXEC evidence, perform root-cause/candidate review, update the regression tracker and durable report/handoff, and plan the next bounded turn. Do not rebuild or mutate the executed package.

R10 does not auto-accept CP4c-2. No benchmark is frozen for this gate; `benchmarkExecution=false` is required.

## 2. Immutable authority

R10 must bind exactly:

- semantic/test source: `57444781af7bdc460e38cc68930a9a8c8199eeea`
- compile workflow run: `33325344311`
- authoritative package job: `99294619815`
- package artifact: `9736088354`
- package ZIP SHA-256: `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`
- packaged source archive SHA-256: `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`
- compile-log artifact: `9736088507` / `8670377030da448b90e37500dda9811d081b13676d16034441ed305cc2906b00`
- exact arithmetic backend: GMP/GMPXX
- selector path: `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt`
- selector whole-file SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- frozen prefixes: 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`; 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`; 361 `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
- selector cardinality / uniqueness: **365 / 365**.

Any mismatch is an **integrity/orchestration stop**, not semantic evidence.

## 3. R10-EXEC immutable preflight

Before any Directional process:

1. download artifact `9736088354` once and verify outer SHA-256 `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`;
2. extract while preserving packaged executable mode bits; ordinary `unzip`/`tar` is required — no Python `zipfile.extractall`, no `chmod`, no repair;
3. verify packaged source archive SHA-256 `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e` and every internal `SHA256SUMS` entry (**28/28 expected**);
4. verify all packaged source-status records are empty and compile metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and GMP/GMPXX linkage;
5. recompute selector 365/361/357/355 hashes from packaged bytes and require exact values above;
6. require selector cardinality/uniqueness **365 / 365** and resolve every required identity exactly once from packaged source/test authority without generated discovery;
7. record package/materialized-source byte inventories and executable-mode inventory for unconditional postflight.

Only a completely green preflight permits Directional runtime.

## 4. R10-EXEC frozen non-gating evidence

Run each once in its own fresh process and exclude it from the 365 gate count:

1. `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable`
2. `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`
3. `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating`

A semantic red is report-only. An integrity, cardinality, process-control, or orchestration failure invalidates execution. Preserve the originating-topology-error and independent actual-graph evidence exactly; do not infer a sphere fix from this run.

## 5. R10-EXEC required-green selector 365

Execute selector 365 **from ordinal 1**, in file order, exactly one identity per fresh process. Every process must select exactly one test and publish ordinal, identity, selection count, exit code, and raw stdout/stderr reference.

### First-semantic-red hard stop

The first semantic red immediately stops all later selector ordinals. Do not retry, continue past the red, repair the package, or mark unexecuted identities green. Unconditional postflight still runs.

### Accepted predecessor

Ordinals **1-355 must re-prove 355/355 PASS**. A red in 1-355 is an accepted-predecessor regression and R10-REV must fully classify it before the canonical TB closes.

### Tail ownership

If reached, record each explicitly:

- 356 `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`
- 357 `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`
- 358 `SurfaceCutGraph.AlreadyCellularNetworkPublishesEmptyCertifiedCutSet`
- 359 `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`
- 360 `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness`
- 361 `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness`
- 362 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness`
- 363 `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs`
- 364 `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour`
- 365 `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted`

## 6. AI2 runtime evidence at ordinal 363

If ordinal 363 is reached, execute that identity with `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1` in the **same single gate process**; do not run a second copy merely for diagnostics.

Preserve and publish every relevant:

- `record=fragment_reconciliation` row, requiring the evidence to state `fragment_orbit_count`, `trace_piece_count`, and `expected_fragment_count`;
- `record=cut_edge_orbit_evidence` row for the trace-crossed selected cut edge and its two incident faces;
- typed terminal result from `GlobalTopologyPlan` / `SurfaceCutGraph`.

R10-REV must explicitly compare `fragment_orbit_count` with `trace_piece_count + 1` and explain the per-face cut-edge orbit cardinalities. The R9-REV paper argument is not runtime proof.

## 7. AH6 — ordinary-path versus saturation coverage

AH6 remains mandatory if ordinals 363-365 are all reached. Publish whether the Amendment-14 trace-crossed source edge was selected through the ordinary tree-cotree proposal path or only after saturation:

- ordinary proposal selected trace-crossed edge: yes/no;
- `saturationUsed`: yes/no;
- saturation locus and promoted-edge count when used;
- selected trace-crossed edge and exact crossing/subdivision evidence;
- whether 363/364 exercise the ordinary path or only a saturation-created state.

If the trace-crossed witness is saturation-only, R10-REV must record a non-stable coverage candidate and keep CP4c-2 open even if selector 365 is otherwise green. Do not add the owed second witness during R10-EXEC.

`M3-CP4c2-TB-X2-R8-CAND-02` remains a separate non-gating product question.

## 8. R10-EXEC unconditional postflight

Run postflight regardless of semantic result. Require:

- package and materialized-source byte inventories equal preflight;
- executable modes equal preflight;
- internal manifest re-verifies;
- selector and fixture bytes unchanged;
- `configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`;
- `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `selectorMutation=false`, `packageMutation=false`;
- `benchmarkExecution=false`.

Any mismatch invalidates semantic evidence pending R10-REV.

## 9. R10-EXEC evidence output

Retain one result artifact and one diagnostic/activity-log artifact containing at minimum:

- immutable authority and full preflight;
- three non-gating process records;
- one fresh-process record per executed gate ordinal;
- first-red stop or final 365/365 summary;
- AI2 fragment/orbit diagnostic rows if 363 is reached;
- AH6 publication if 363-365 are reached;
- unconditional postflight and all build/mutation/benchmark flags;
- raw stdout/stderr needed for R10-REV.

R10-EXEC must not update product/test/fixture/build logic and must not generate a corrective plan beyond recording the exact evidence handoff.

## 10. R10-REV ownership

After valid R10-EXEC evidence exists, stop execution and hand it to **`M3-CP4c-2-TB-X2-R10-REV`**. R10-REV owns:

- every regression/candidate classification and required `Regression_Root_Cause_Tracker.md` update;
- `R9-CAND-01` closure only if ordinals **363, 364 and 365 are all green in a run reaching 365**;
- AI2 diagnostic interpretation;
- AH6 coverage disposition;
- CP4c-2 acceptance eligibility or the next bounded corrective/independent-review boundary.

Starting accounting is **44 / 14 / 30**, debt **5**, M3 packages **67**. CP4c-3 remains blocked until CP4c-2 is accepted.
