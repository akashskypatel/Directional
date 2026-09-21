# M5-CP3-TB1-R5 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R5-EXEC`
**Boundary:** artifact-only Test + Benchmark
**Result:** **COMPLETE / MECHANICALLY COMPLETE / SEMANTIC RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R5-REV`

## 1. Immutable authority and orchestration

Candidate artifact `10633891886` from exact packaged source `20f9bf11dc5a986dafd52c5556671fb9f7d429f4` was consumed without rebuild or repair. Provider/download SHA-256 is `4359271b96f9cf5351782056ee030757a3d02956b8cb901264d4a46b4d1836f7`; root `SHA256SUMS` hashes to `5e36a32b3c07c1c4f533c8f896517e33239475a6175d012b66bdd6da358dbd73` and verifies **28/28**; packaged source archive SHA-256 is `c939872ab9e8648d2009e7ca9781ea62a6938ffeb21f342344924dcaf171b8b7`. Accepted routing artifact `10592987234` remained fixed at ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Authoritative runtime run/job is `35591203189 / 106305794544`; observer event SHA is `bbd190df8b931beea5093f4ea4e828f937a8bbcf`. Workflow schema validation passed. Result artifact `10634649162` has provider/download SHA-256 `b93903eafdd028140759526635312efa7e6896442d5260a871a85402371cc4ab`; diagnostic log artifact `10635142112` has provider/download SHA-256 `eded6a14c358fb4f8a24ae07585142cc9d97042912fd100857ff078430f9509c`. The result self-manifest contains **911** entries, hashes to `680ec03ace5f839e802fc256b7a335b11279cedc9248d641e9156e266d6b4fc9`, and verifies **911/911**.

The rendered runtime driver SHA-256 is `4657a4785d4fbe18b8e147a49eafe81ad34c52374e424038820fe7d042fa6bc1`; its template SHA-256 is `752deb7e8d5d879047f1d4619fdb3c564e93e6d3d2e68b8affb9f19a47b997a3`. The orchestration writer remains `d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`.

## 2. Frozen execution result

All **446** planned fresh exact-filter processes executed with exact-one selection and zero skips. Overall result is **439 PASS / 7 RED**:

- mechanism rows: **9/9 PASS**;
- new focused atlas row: **1/1 PASS** — `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`;
- produced rows: **0/6 PASS**, all six RED with `PeriodicHolonomyMismatch` while establishing the production torus fixture;
- selector430: **429/430 PASS**;
- sole selector RED: ordinal **408**, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`;
- benchmark executions: **0**.

All six previously red independent-atlas selector identities from R4 — ordinals **18, 20, 21, 22, 23, 25** — are green. Together with the new focused 1/1 PASS, this is direct runtime recovery evidence for the bounded CB6 independent-oracle correction without selector edits.

Ordinal408 still fails its pre-existing required `Produced` assertion. Runtime reports `fixture.traceNetwork.phaseFront.disposition()` as `Rejected` rather than `Produced`, with diagnostic `NotProductionReady/tracing/None`. All six produced identities independently fail with the exception `torus pipeline producer failed: PeriodicHolonomyMismatch`.

## 3. Regression classification required by the TB gate

### `M5-CP3-TB1-R5-CAND-01` — carrier-distinctness removal does not recover the production endpoint

CB6 removed only the unfrozen generator-versus-cut carrier-identity inequality. R5 nevertheless reproduces the same six produced `PeriodicHolonomyMismatch` failures and the same accepted ordinal408 `Produced`→`Rejected` endpoint as R1-R4. The carrier-distinctness guard was therefore **not sufficient to explain or repair the surviving production failure**.

R5 EXEC does not infer which remaining collapsed `PeriodicHolonomyMismatch` predicate fires. The runtime evidence establishes continuation of the already-recorded accepted ordinal408 PASS→RED event, not a second accepted-green→RED transition. Pending independent Review, this is **EXISTING `RP-01 / AUTHORITY_DOMAIN_CONFLATION` CONTINUATION / +0 stable events / +0 categories / +0 recurrences**. Durable totals remain **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**.

Root-cause analysis at the EXEC boundary is deliberately bounded: the CB6 equality guard is falsified as the complete cause, while the remaining product-side authority defect stays unresolved behind the generic `PeriodicHolonomyMismatch` collapse. `M5-CP3-TB1-R5-REV` must independently localize the next falsifiable authority mismatch before any further implementation turn.

### R4 atlas-oracle drift — runtime recovery observed

`M5-CP3-TB1-R4-CAND-02` was classified non-stable test-authority oracle drift. R5 observes the exact expected recovery signature: the new independent hard-feature value-without-adjacency row is green and all six formerly red accepted atlas identities return to PASS while selector430 remains byte-frozen. EXEC records **RECOVERY OBSERVED / REVIEW PENDING** and does not convert the non-stable issue into a stable event.

## 4. Immutable postflight and prohibited operations

Postflight is exact:

- package byte+mode census unchanged;
- packaged-source byte+mode census unchanged;
- execution-view byte+mode census unchanged;
- candidate root manifest still **28/28**;
- result self-manifest **911/911**;
- selector430 and first427 hashes unchanged;
- routing identity map unchanged;
- `orchestration_failure=false`;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all **0**;
- benchmark execution **0**.

No source, test, fixture, selector, build logic, package byte, executable mode, or accepted runtime authority was changed by this Test + Benchmark turn.

## 5. Disposition

Candidate `10633891886` remains **unpromoted**. All four M5 produced-witness debts remain open and selector publication remains prohibited. R5 earns no production-debt or selector-publication credit.

Exact successor is independent runtime-free **`M5-CP3-TB1-R5-REV`**. Review must independently re-derive the 446-process evidence, confirm the R4 oracle-drift recovery, adjudicate `R5-CAND-01` against the existing stable RP-01 event, inspect the surviving product authority path without weakening test/selector expectations, and decide the next bounded correction or stop condition. No same-turn repair, candidate promotion, debt discharge, or selector publication is authorized by EXEC.
