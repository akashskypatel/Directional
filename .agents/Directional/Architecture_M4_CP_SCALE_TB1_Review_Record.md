# M4-CP-SCALE-TB1 Review Record

**Turn:** `M4-CP-SCALE-TB1-REV`
**Decision:** `approved_with_amendments` — promote the mechanically green CB1/TB1 candidate as current M4 runtime authority, accept S1 only as decision-neutral diagnostic instrumentation on the measured witness set, freeze **no** numeric scale threshold, and advance only to the bounded S2 vertex-star equivalence Code + Build slice.
**Runtime/build:** none; Review is runtime-free.

## 1. Reviewed authority

Review re-opened the immutable TB1 evidence and an exact current source snapshot rather than relying on the EXEC report alone.

- candidate package: `10360085644` (`m4-cp-scale-cb1-result-34872546633`), provider ZIP SHA-256 `996189b38c26f906bdd86354451571475900d98d0811f50e50a9439f26ff6ec7`;
- candidate semantic source: `a359b981f9350139304bc5a654041dfba78609b6`;
- candidate package manifest: **28/28**, SHA-256 `3ac6c9e388d06ed5572613480a587952736657be88cf8dfba393d356e47028b8`;
- candidate packaged-source archive SHA-256: `b261f468cde2e54974f19931ca5101e2c6d07e273ca555c0526d9e7ce112e3d4`;
- TB1 evidence archive SHA-256: `712bf4983695a58d1d0859e041895209c9935eb7e8f4bdc2835c01737173e3da`;
- published TB1 result artifact `10363765929`, provider SHA-256 `4d1a45227983bf9cef221268ee14657f1d81752b5a5c1923db6954607fdfcfe1`;
- publication run/job: `34883153457 / 104107197329`; publication records `internal_manifest_verified=true` and `runtimeExecution=false`;
- exact Review source snapshot: source commit `92e107f509c6d90094c6f8f95a9c78371098c25b`, run/job `34886538260 / 104118529293`, artifact `10364538830`, provider SHA-256 `86a7e0787e2265882bbc9968949d45c849a5f06ee09198a8191ecaeb8fefe6d5`, inner archive SHA-256 `64fc9c7439e1d6c8ec9fb2645d29353435b3d34d200335da0027a5a6edd402db`.

GitHub comparison `a359b981... -> 92e107f5...` is **32 commits ahead / 0 behind** and contains only documentation/control-plane changes; there is no `src/`, `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt`, or `cmake/` drift. Static review of the current source therefore describes the packaged semantic bytes.

Review also re-downloaded artifact `10363765929`. Its ZIP re-hashes to the published provider digest, the nested evidence archive re-hashes to `712bf498...e3da`, and those nested bytes are byte-identical to the retained TB1 evidence used below. The non-self evidence manifest contains **869** entries and independently verifies **869/869**.

## 2. Selector423 re-derivation and non-vacuity

Review independently re-hashed `Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt` from the exact snapshot:

- selector423: **423 LF rows**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- first422: **422 LF rows**, SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc` — byte-identical to accepted selector422;
- row423 remains `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`.

The TB1 owner map has exactly 423 rows in selector order and independently sums to **30 authority-kernel / 277 producer / 75 completion / 41 validation = 423**. The process ledger also has exactly 423 rows in selector order. Every row reports `PASS`, exit `0`, exactly one selected test, exactly one OK test, zero skip, and a unique raw log. Review parsed all **423 raw logs** and found **0** missing/multiple selections, **0** failures, **0** skips, **0** timeouts, and **0** crashes.

This is not a zero-selected or summarized-green result: every accepted identity ran in a fresh exact-filter process and each raw log proves exactly one selected identity completed green.

## 3. S1 primary evidence re-derived

The focused identity `M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral` ran exactly once and is **1/1 PASS**. Its raw log emits the four required witness reports exactly once:

| witness | samples | numerator max | denominator max | magnitude max | deepest / failed stage |
|---|---:|---:|---:|---:|---|
| two-ring | 9 | 105 | 107 | 107 | `direct-field-aligned-network` |
| torus | 0 | 0 | 0 | 0 | `global-topology-plan` |
| mechanical feature | 60 | 1 | 1 | 1 | `global-topology-plan` |
| prescribed sphere | 186 | 429 | 429 | 429 | `field-aligned-network` / `surface-cut-graph` |

The prescribed-sphere raw receipt retains the known downstream chain `CellularityNotEstablished -> RotationSystemInconsistent -> TraceEventPositionInvalid`, trace `2`, event `30`, `NoCarrierMatch / SourceEdgeUnavailable`. The final parsed table hashes to `3befc557dbcf4fe72a74f401aea7ecbadc2dcf1771d9d8e760d4b17f9d0fbdd2`; the focused raw log hashes to `43069f00ac7d06dd220bd1939e9e8ba78d38d0f5b50476f62bec059f5e9faaad`.

Review inspected the source rather than treating the output as self-proving. Census insertion occurs only after the existing traversal guard reports `Advanced`; the optional census is never consulted by a tracing decision. Exact widths are taken from GMP-backed rational numerator/denominator magnitudes without floating conversion. Success preserves the same semantic candidate digest, failure preserves the same typed `FieldAlignedCurveNetworkError` while carrying partial census evidence, and rows/aggregates are deterministic. The authored test independently recomputes row classes/widths from the actual exact entry parameters, checks repeated-census equality, compares enabled/disabled semantic digests, and includes a discriminating exact `0 -> 1/257` measurement tamper.

The retained-witness branch is also non-vacuous: torus and mechanical feature prove successful baseline equivalence; the prescribed sphere proves typed-error equivalence through its existing downstream failure; the two-ring path proves nontrivial exact widths. Existing production tests separately demonstrate both `VertexStarDecisionKernelRoute::Filter` and `ExactFallback`, which is why the S2 vertex-star surface is eligible for an independent equivalence gate next.

## 4. S1 interpretation — measured, not calibrated

The measurements justify **one bounded conclusion**: the S1 census is deterministic, exact, decision-neutral on the retained witness family, and safe to retain in the accepted package as diagnostic instrumentation. They do **not** justify a numeric production bound.

The largest observed active-trace width is **429 bits**, but that is an observation, not a safety envelope. Torus contributes zero trace samples; the retained fixtures are small and regular; no scale/sliver/adversarial stress family was measured. `LESSONS.md` 74 applies directly: evidence from this witness domain cannot justify a general hardening threshold outside it. Therefore:

- no threshold is inferred from `429`;
- `kFieldExactContinuationMagnitudeBits = 4096U` remains an operational fail-closed guard, **not** S1 calibration;
- S1 remains outside selector423 and contributes zero gate rows;
- `M4-CP-SCALE-TB1-REV-OBS-01` records the still-open calibration precondition: a future threshold, if any, requires a separately frozen representative/stress witness domain and an independently justified bound.

This open calibration obligation does **not** block S2 vertex-star work because S2 is a separate certified-filter semantic seam and its frozen precondition is already source-reachable.

## 5. Evidence-provenance hygiene observation

The archived main TB1 harness version writes a nine-column S1 family table, while the final retained table contains the required `failedStage` column and was finalized later. The decisive values are nevertheless independently reconstructible from the raw focused log and test source, both are covered by the immutable evidence manifest, and Review did reconstruct them. The discrepancy therefore does **not** invalidate the runtime or promotion.

It is a resolved evidence-derivation hygiene instance, not a stable regression: future harnesses that post-process a required acceptance table must either archive the postprocessor or emit the final schema directly from the archived harness. This is an instance of existing source-of-truth/evidence-provenance lessons (`LESSONS.md` 109 and 131), so no new LESSONS number is created.

Review setup also incurred one fail-closed process-order miss: `Mandatory_Start_Checklist.md` was inspected before the tool policies and `READ_MODE` were fully established. No source/runtime claim was made from that early read; the turn immediately stopped piecemeal inspection, fully read the tool policies, selected `READ_MODE=snapshot`, and did no further project/source review until the exact snapshot above existed. This is an existing `LESSONS.md` 152 instance, not semantic evidence and not a new category.

## 6. Promotion decision

**APPROVED WITH AMENDMENTS / PROMOTE.** Package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` becomes the accepted current M4 runtime authority.

Promotion is justified by the unchanged accepted selector bytes and full non-vacuous **423/423** cumulative gate, the focused S1 **1/1** decision-neutrality proof, and exact package/source/execution-view postflight. No accepted PASS became RED and no new stable event/category/recurrence is present. Selector authority does not advance numerically: selector423 remains the accepted selector, now re-proved unchanged on the promoted package.

Stable accounting remains **49 events / 14 categories / 35 recurrences**. Produced-witness debt remains **5**.

The amendment is scope, not a semantic correction: S1 is accepted as diagnostic instrumentation only, no numeric threshold is frozen, and CP-SCALE remains OPEN.

## 7. Prior obligations

| obligation | Review disposition |
|---|---|
| `M4-CP-SCALE-DEFN-OBS-01` — arrival-order exact fallback absent | **CARRY.** Not owned by CB2; a later bounded CP-SCALE definition/CB must freeze the same-seam exact fallback before arrival filter gate credit. |
| `M4-CP-SCALE-DEFN-OBS-02` — S3 exact-repeat witness owed | **CARRY.** Sphere combinatorial recurrence remains non-credit; later S3 owner must construct full exact-state repetition. |
| `M4-CP-SCALE-DEFN-OBS-03` — S4 independent incremental oracle/reachability | **CARRY.** Final actual-embedded certificate remains sole topology authority. |
| `M4-CP-SCALE-DEFN-OBS-04` — S5 genus>=2 fixture absent | **CARRY.** Torus genus1 remains zero credit. |
| `M4-CP3-TB1-R1-REV-OBS-01` — same-region multiplicity-2 oracle | **CARRY** to the first independently falsifiable M4 test-authority turn before cumulative M4-CP4. |
| `M4-CP3-CB4-REV-OBS-02` — row399 path/`sourceFaces` divergence tamper | **CARRY** to the next legitimate row399 touch; CB2 does not touch row399. |
| row408 provenance warning | **CARRY / historical-bound**; no CB2 ownership. |
| `G4-B002` produced-witness debts | **CARRY 3** to M4-CP4. |
| `G4-B003` produced-witness debts | **CARRY 2** to M5. |

No prior obligation is silently discharged by S1.

## 8. Exactly one successor

Freeze **`M4-CP-SCALE-CB2`** under `Architecture_M4_CP_SCALE_CB2_Code_Build_Plan.md`.

The slice is S2 **vertex-star only**. Its falsifiable prediction is that the already-existing certified vertex-star filter/exact-fallback mechanism can be independently test-oracled without changing production semantics. CB2 may author the frozen `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` test authority and compile/package it, but it may not append a selector row or execute runtime. The exact route matrix, tamper, non-vacuity, compile/package criteria and STOP rules are frozen in that plan before the build.

Arrival ordering, S3, S4, S5, S1 threshold calibration, CP4 produced-witness debt, row399 and row408 work are explicitly outside CB2.

## 9. Consolidation

Under `CLEAN_UP_POLICY.md`, this Review folds the superseded CP-SCALE DEFN review record, CB1 plan/report, and consumed TB1 plan only after their durable facts are preserved in the frozen definitions, this Review, the current TB1 runtime-authority report, tracker/changelog, and `M4_Consolidated_Record.md` §2.49. The current TB1 runtime report is retained because it is now the current runtime-authority report. Exact folded filenames and line counts are indexed in §2.49; full prior text remains recoverable from git history.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector423 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; first422 exact accepted selector422 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`. |
| Decisive claims independently re-derived | PASS — publication/evidence hashes, 869-entry manifest, selector/prefix hashes, owner census, 423 process/raw logs, S1 raw reports, source decision-neutrality and immutable postflight independently checked. |
| Non-vacuity checked | PASS — every selector process selected exactly one identity; S1 has exact-width recomputation/tamper and success/error semantic equivalence; existing vertex-star Filter and ExactFallback routes are both source/test-reachable. |
| Prior obligations discharged/carried | All listed in §7; none silently discharged. New S1 calibration obligation `M4-CP-SCALE-TB1-REV-OBS-01` is carried without blocking CB2. |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10360085644`, selector423 **423/423**. |
| New candidates/obligations recorded | `M4-CP-SCALE-TB1-REV-OBS-01` — S1 numeric calibration remains unproven outside the measured witness domain; tracker updated. Evidence-table derivation discrepancy is resolved/non-blocking process hygiene, not a regression candidate. |
| ORIENTATION currency line | Updated to `M4-CP-SCALE-TB1-REV`, 2026-09-14; package `10360085644` / selector423 accepted; exact next CB2. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 authority/status updated; §4 stage table unchanged and CP-SCALE measurement note updated; §7 S1 diagnostic slice discharged and S2 vertex-star prioritized; §8 records the evidence-provenance and start-order instances under existing lessons. |
| CHANGELOG | Root and Directional changelogs updated with promotion, no-threshold adjudication, observation and successor. |
| ROADMAP | Updated to promoted package authority and bounded S2 vertex-star next slice. |
| Selector manifest | Updated: selector423 bytes unchanged; package authority advances to `10360085644` after independent 423/423 Review. |
| LESSONS | No new lesson. Existing 74, 109, 131 and 152 cover the measured-domain, provenance and setup-order findings. |
| Consolidation under CLEAN_UP_POLICY | Folded `Architecture_M4_CP_SCALE_DEFN_Record.md` (116), `Architecture_M4_CP_SCALE_CB1_Code_Build_Plan.md` (62), `Architecture_M4_CP_SCALE_CB1_Code_Build_Report.md` (82), and `Architecture_M4_CP_SCALE_TB1_Artifact_Only_Test_Benchmark_Plan.md` (103); retained current TB1 runtime report, Review, CB2 plan, frozen definitions, consolidated record and selectors. |
| Successor frozen | Exactly `M4-CP-SCALE-CB2`; falsifiers/STOP rules are stated before build in `Architecture_M4_CP_SCALE_CB2_Code_Build_Plan.md`. |
| Turn boundary held | PASS — runtime-free Review; no Directional runtime/build/package and no product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | **PASS** — `review_check.py boundary --expect-selector 423=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343` reports no product/test/fixture/build mutation, no selector mutation, all retained selector hashes valid, durable markers preserved, and `ALL CHECKS PASSED`. |
| Pushed to origin, branch in sync | **PASS AT TURN CLOSEOUT** — the exact-base durable Review patch is applied to the configured working branch, temporary control state is removed workflow-first, remote branch/PR authority is re-read, and no local-only repository-applicable work remains before the mandatory final PR comment. |
