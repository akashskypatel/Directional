# M4-CP4-TB2-R2 Review Record

**Turn:** `M4-CP4-TB2-R2-REV`
**Date:** 2026-09-19 UTC
**Boundary:** runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation and no generated Directional runtime
**Disposition:** **EVIDENCE UPHELD / ROW1+ROW3+ROW4 CREDITED / ROW2 ESCALATED TO DEFINITION / CP4 OPEN**

## 1. Evidence independently re-derived

The R2 artifact pair is authoritative and immutable:

- run/job `35449574130 / 105914294127`;
- result artifact `10586074692`, SHA-256 `b1e29556f3d0506c0f2319634d7e94872dbc7267576712fa2180c2d55c92f615`;
- log artifact `10586214778`, SHA-256 `2335b11c76e3d5026f5b237d007b426827976748e8cbf1fda8f33c10a011893e`;
- exact composite semantic source: CB4 full package `10578784752` plus CB5 delta `10582435470` from source `4e9ff5003c8dd165dd614c25dd95f0308403719b` for the two changed tests.

Independent parsing of `process-ledger.tsv` yields exactly **431 rows = 430 PASS / 1 RED**: four focus rows are **3 PASS / 1 RED** and all **427 selector rows PASS**. Every row selected exactly one test, there are zero skips, and the selector owner census is exactly **30 authority / 281 producer / 75 completion / 41 validation**. The sole non-PASS row is focus ordinal 2, `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`, classified `TEST_FAILURE`.

The artifact postflight independently confirms exact package/source/execution-view equality, both package manifests re-verify, and configure/compile/relink/generated-discovery/repair/package-repair/mode-repair/source-mutation/test-mutation/fixture-mutation/selector-mutation/benchmark counters are all zero.

Selector427 independently re-hashes to `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` over 427 LF rows. Its exact first-426 prefix independently re-hashes to `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, matching the accepted selector426 authority.

## 2. Focus adjudication

### R1 — production baseline work receipt: CREDITED

`M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` is freshly selected once and PASSes. Its reviewed result is consistent with the previously frozen work-ledger contract and adds no regression or debt. The CP4 work/bit-width/monotone-progress conjunct receives current R2 re-proof credit.

### R2 — produced closed-complex candidate extraction: DEFINITION STOP

The RED is trustworthy, but the R2 EXEC classification as merely the same test-precondition root is no longer sufficient.

CB5 already performed the only test-authority correction authorized by frozen §3.1: `produced_closed_torus_arrangement()` now uses the accepted row408 two-generator / 18-hard-edge torus precondition, keeps `SurfaceCells`, `fallbackPolicy=Fail`, `allowSourceGridRecovery=false`, and `retainIntermediateGeometry=true`, and then requires `result.surfaceCellContext.hasArrangement`. Runtime still stops at:

```text
Produced torus did not retain arrangement authority: NotProductionReady/tracing
```

The historical row408 authority does not contradict that result. `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity` requires the retained A3→A4 trace product and `traceNetwork.phaseFront.disposition() == Produced`; it does **not** require `surfaceCellContext.hasArrangement`. Thus `phaseFront == Produced` and retained closed-complex arrangement authority are different stage facts.

The independent eligibility oracle and its hard-feature tamper remain non-vacuous in design, but R2 never reaches them. Substituting `closed_toroidal_candidate_complex()`, direct/draft authority, recovery output, or a weaker oracle would violate frozen §3.1. A second test-only precondition correction would also repeat the already-exhausted CB5 action without evidence that current M4 production semantics can publish the required subject.

**Disposition:** `M4-CP4-TB2-R2-CAND-01` and antecedent `M4-CP4-TB1-R3-CAND-01` remain **NON-STABLE**, but ownership escalates from test-authority reachability to **ARCHITECTURE_DEFINITION / PRODUCED-SUBJECT STAGE OWNERSHIP**. No accepted-green behavior regressed. The produced closed-complex `G4-B002` debt remains open and counted pending `M4-CP4-DEFN-R2`.

### R3 — same-region multiplicity-two: CREDITED

`M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` is freshly selected once and PASSes under the immutable composite. Review grants the CP4 same-region multiplicity-two exit conjunct current R2 credit. The previously discharged observation remains discharged; no new candidate is opened.

### R4 — zero-transport exact typed expectation: CREDITED / CAND-03 CLOSED

`M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` is freshly selected once and PASSes. The unchanged witness preserves flat success and independently nonzero apex-defect/non-flat controls, and the corrected expected rejection is exact `NonIntegralCycleLift`.

`M4-CP4-TB1-R3-CAND-03` is therefore **CLOSED / CORRECTION RUNTIME-PROVED / NON-STABLE**. Product validation order was not changed and no stable accounting is added.

## 3. Non-vacuity and authority boundary

The evidence distinguishes success from vacuity:

- all 431 exact-filter processes selected exactly one test;
- focus row2 fails before its oracle, so no candidate-extraction credit is claimed;
- focus row3 actually executes the produced same-region multiplicity-two contract;
- focus row4 exercises both flat success and the independently non-flat negative before matching exact typed rejection;
- selector427 executes all four owner binaries with the frozen **30/281/75/41** partition;
- no direct/synthetic/recovery substitute is counted for the row2 debt.

The current review therefore does **not** promote the CB4+CB5 composite. Accepted runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**.

## 4. Accounting and obligations

Stable accounting is unchanged: **49 events / 14 categories / 35 recurrences**. Produced-witness debt remains **5**.

- produced closed-complex `G4-B002` — **OPEN**, definition ownership under `M4-CP4-DEFN-R2`;
- periodic reorder `G4-B002` — **OPEN / M5**, unchanged;
- missing-owner `G4-B002` — **OPEN / M5**, unchanged;
- two `G4-B003` produced-witness debts — **OPEN / M5**, unchanged;
- `M4-CP4-TB1-R3-CAND-03` — **CLOSED / CORRECTION RUNTIME-PROVED / NON-STABLE**;
- same-region multiplicity-two — **CREDITED / DISCHARGED as an M4-CP4 evidence obligation**;
- row1 work/boundedness — **CREDITED**;
- `M4-CP3-CB4-REV-OBS-02`, `M4-CP-SCALE-TB1-REV-OBS-01`, and `M4-CP-SCALE-DEFN-OBS-01` remain carried by their previously assigned owners.

No periodic M4 credit is granted by this Review.

## 5. Checkpoint and successor decision

M4-CP4 remains **OPEN** because its only remaining M4-owned produced-witness debt has no production-reachable retained subject under the currently demonstrated path. The evidence is insufficient to decide inside a Review whether the debt is correctly M4-owned or belongs to the later stage that actually owns the relevant closed complex.

Exactly one successor is frozen: **`M4-CP4-DEFN-R2`** under `Architecture_M4_CP4_DEFN_R2_Produced_Closed_Complex_Authority_Reconciliation_Plan.md`.

DEFN-R2 is runtime-free. It must reconcile the frozen CP4 debt with `DESIGN.md`'s A4 `RegionCellComplex`, A5 `SurfaceOccurrenceComplex`, and the current `surfaceCellContext.hasArrangement` retention boundary. It may amend definitions/ownership and planning only. It must not weaken the oracle, use synthetic/direct/recovery authority, change product/test/fixture/selector/build source, compile, or execute generated runtime.

## 6. Consolidation

Per `CLEAN_UP_POLICY.md`, durable DEFN-R1 reasoning is already preserved in `M4_Consolidated_Record.md` §0.10, frozen definitions, tracker and changelogs. This Review folds the superseded DEFN-R1 record and the consumed R2 Review plan into the consolidated index. The R2 runtime report remains current runtime evidence; this file becomes the current Review; DEFN-R2 has exactly one retained successor plan.

Tool-call accounting for this resumed Review is **partial/unknown** because the inherited in-progress turn did not carry an exact cumulative tool-call ledger across the resume boundary. Per `TOOL_USE_CONSERVATION_POLICY.md`, no calls were spent reconstructing it.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; exact first426 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` |
| Decisive claims independently re-derived | 431-row ledger = 430/1; focus 3/1; selector 427/427; owners 30/281/75/41; exact-one/zero-skip; artifact hashes; immutable postflight; row2 versus row408 stage predicates |
| Non-vacuity checked | row2 explicitly receives no oracle credit before arrangement; rows1/3/4 execute their discriminators; selector rows all select exactly one test |
| Prior obligations discharged/carried | row1 and multiplicity-two credited; `CAND-03` closed correction-runtime-proved; row2 debt/candidate escalated to DEFN-R2; all M5 debts and unrelated carried observations preserved |
| Stable accounting | 49 events / 14 categories / 35 recurrences; debt 5; accepted package `10565723112` / selector427 427/427 unchanged |
| New candidates/obligations recorded | no new stable candidate; `M4-CP4-TB2-R2-CAND-01` reclassified/escalated to architecture-definition stage ownership and tracker updated |
| ORIENTATION currency line | `M4-CP4-TB2-R2-REV`, 2026-09-19 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated for R2 Review credit, torus arrangement reachability, DEFN-R2 priority, and stage-authority substitution instance; superseded CB7/R2-next text removed |
| CHANGELOG | root and agent changelogs updated |
| ROADMAP | updated: CP4 remains open; reviewed row1/row3/row4 credit; exact next DEFN-R2; stale G4-B002 owner split corrected |
| Selector manifest | n/a — selector427 is unchanged and no selector is added/accepted |
| LESSONS | existing lesson 22d applies; no genuinely new lesson added |
| Consolidation under CLEAN_UP_POLICY | DEFN-R1 record (232 lines) and consumed R2 Review plan (62 lines) folded/indexed; R2 runtime report retained |
| Successor frozen | exactly one: `M4-CP4-DEFN-R2`; falsifiers and stop rules are in `Architecture_M4_CP4_DEFN_R2_Produced_Closed_Complex_Authority_Reconciliation_Plan.md` |
| Turn boundary held | runtime-free; no product/test/fixture/selector/benchmark/build source mutation and no generated Directional runtime |
| review_check.py boundary | **PASS** — `python3 .agents/Directional/tools/review_check.py boundary --expect-selector 427=f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` reports all Review-boundary, selector-hash and durable-marker checks PASS on the final intended patch |
| `STATUS` lifecycle maintained | `Turn=M4-CP4-TB2-R2-REV`; Started `2026-09-19T15:37:58Z`; Resumed `2026-09-19T18:55:40Z`; final COMPLETE with `Successor=M4-CP4-DEFN-R2` is reserved for the final repository mutation |
| Pushed to origin, branch in sync | coherent Review closeout will be pushed to the configured branch, cleanup completed, authority re-read, then final COMPLETE `STATUS` published as the last repository write |
