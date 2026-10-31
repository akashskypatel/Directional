# `M6-CP1-TB12-CLOSE-R1-REV` — Recovery Review Record

## Verdict

**ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED / +0 STABLE REPRICING.**

Candidate package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` is promoted as the current reviewed M6 runtime authority. The immutable R1 gate is independently upheld at focused30 **30/30** + selector449 **449/449** = **479/479 PASS**, exact-one, zero skips, benchmark 0, with immutable postflight. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

Exact successor: runtime-free **`M6-CP1-CLOSE-REV`**. CP1 is not closed by this turn.

## 1. Independent evidence re-derivation

- Runtime run/job: `37280517630 / 111667316992`.
- Result/log artifacts: `11333591947 / 11333547162`; provider ZIP SHA-256 `ef5dba1131f25025bc536ba160475191629cc8bffed0465a087dd72fc4d1474b / dd78296134b6e71d2080ab2b1b6623841f75725e6a43deffe6ec2ad50dd46e53`.
- Result self-manifest re-verified **497/497**; manifest SHA-256 `9d7f244f4996d06db10db756c3bf25e1495d9628b9bb3e92af8cfeb089a4bd67`.
- Focused ledger SHA-256 `296bc32f9ed1fc017c1ae7c5e48c67056a962a9c8f376333f1ca400bfde61e0a`; selector ledger SHA-256 `d5298b2aaaf55c1a458b1ec6e79954cbddc17dbf33be7baf0998f397d4a2908f`.
- Recomputed ledger order equals frozen focused30 **30/30** and selector449/routing449 **449/449**. Every row has selected=`1`, skipped=`0`, result=`PASS`; the RED ledger has no data rows.
- Frozen authorities re-hash to focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d` as the exact first-28 prefix, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
- Candidate package remains exact: source `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, packaged manifest **28/28**, exact GMP boundary, `runtimeExecution=false` for compile/package. R1 execution records no configure/compile/relink/discovery/benchmark/repair/mutation/retry.

The review source snapshot is run/artifact `37287216977 / 11335041130`, exact source/event `f6ffca2a1b6492e0685d0d93f82db996576cb7cc`, provider digest `e672793ad3519750789f2962dda351d756f37541a44ead5cb65af16714fe0cb1`, embedded archive SHA-256 `e470ad13d6498bff71409a56a3520348153013afdfde152132bdc8665419f572`, 5406 files, `runtimeExecution=false`.

## 2. RA-27a implementation review

The R2 implementation is faithful to the frozen rule.

1. **Exact wedge graph.** A7 now accepts a multi-sheet occurrence only when its own `cornerWedgeIsolation` graph connects every member of `cornerWedgeSheets`. Only transitions in `occurrence.topologyRegion` whose two sheet endpoints are in that occurrence's sheet set are edges; traversal is undirected. Failure is `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`. Produced `cornerWedgeSheets` are sorted/unique before publication, matching the membership helper's binary-search precondition.
2. **Selected-forest edge rule unchanged.** The pre-existing disjoint-endpoint-sheet rule remains a separate check at site `cross-sheet`; R2 did not retarget or weaken it.
3. **C4 diagnostic.** `ClosedComplexStripContinuationMismatch` now maps exactly to `QuotientClosedComplexStripContinuationMismatch`.
4. **Identity29 consistent-chain falsifier.** The test proves baseline A5→A6→A7 acceptance, requires a multi-sheet bridge occurrence with non-empty wedge transitions, changes only that occurrence's transition sheet endpoints to unrelated IDs, republishes A5, re-produces A6 and requires A6 success, then requires A7 `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`. The transition vector remains non-empty, so the old non-empty proxy would accept the tamper while the exact graph rejects it.

Runtime focused ordinal29 PASS therefore establishes non-vacuity: the bridge was found, the tamper was reached, A5 publication and fresh A6 production succeeded, and the expected A7 rejection was observed. Ordinal30 also remains PASS. No accepted row regressed.

## 3. Prior obligations

- `M6-CP1-TB12-CLOSE-EXEC-CAND-01`: **CLOSED / RECOVERY PROVED / NON-STABLE**. The corrected reachable-branch falsifier is green. It never enters stable totals because the original loss was a new unpromoted test-authority row, not accepted-green loss.
- RA-27a §2 / C1 reachable wedge proxy: **DISCHARGED** by the exact graph plus ordinal29 runtime falsifier.
- RA-27a §3 C4 name: **DISCHARGED** by exact source inspection. The earlier fail-closed behavior was already reviewed; this turn verifies the required diagnostic string correction.
- RA-27a §6 edge-rule executed falsifier: **CARRIED** to `M6-DEFN-R5` → `M6-CP3`, awaiting the first produced seam-collinear fixture; no hand-built relation record is authorized.
- `M6-CP1-TB12-REV-OBS-01` A6→A5 certificate binding: **CARRIED** to `M6-CP2` via `M6-DEFN-R5`.
- `M6-CP1-TB12-REV-OBS-02` relation-kind-agnostic selected-edge rule: **CARRIED** to `M6-DEFN-R5`.
- RA-26 §5 reference-selecting representative/permutation obligations: **CARRIED** to `M6-DEFN-R5` / `M6-CP3`; they do not block CP1.

No new regression candidate, category, recurrence, or debt is created.

## 4. Promotion and successor boundary

Package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` becomes current reviewed M6 runtime authority under focused30 + selector449 = **479/479**. CP1 remains ACTIVE until the dedicated close Review re-derives all six frozen CP1 exit items and the carried close obligations against exact current source.

`M6-CP1-CLOSE-REV` is runtime-free. Its falsifiers are frozen in `Architecture_M6_CP1_Close_Review_Plan.md`: any missing CP1 exit item, any surviving authority-deciding provenance-face consumer, any undisclosed semantic adapter decision, any coordinate/position weld, or any contradiction with the promoted 479/479 evidence prevents CP1 closure and must be routed to the proper Definition/Code + Build owner rather than repaired in Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused28 `9154a986...011d` is the exact first 28 rows of focused30 `1e815443...a1d6`; selector449 `d4a0d1b7...d6414` and routing449 `9c88a5ed...c5707` independently re-hashed. |
| Decisive claims independently re-derived | 497/497 result manifest; 30/30 + 449/449 ledgers in frozen order; exact-one/zero-skip; candidate/package/source identity; RA-27a source/test semantics. |
| Non-vacuity checked | Ordinal29 PASS requires the multi-sheet bridge, non-empty tamper, A5 republish, fresh A6 success, and exact A7 wedge rejection; old non-empty proxy would accept the same non-empty tamper. |
| Prior obligations discharged/carried | CAND-01, C1 wedge proxy and C4 name discharged; RA-27a §6, OBS-01/02 and RA-26 §5 carried with owners in §3. |
| Stable accounting | 60 / 16 / 44, debt 1; promoted package/source `11330703256 / 3f40f04a...`; selector449 remains accepted. |
| New candidates/obligations recorded | None; tracker records recovery closure and carried existing obligations. |
| ORIENTATION currency line | `M6-CP1-TB12-CLOSE-R1-REV`, 2026-10-05 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 promoted 479/479 authority; §4 split-square wedge falsifier updated; §7 R2 item discharged and close Review made exact next; §8 cites existing lesson 199, no new pattern. |
| CHANGELOG | Root and agent changelogs updated with accepted R1 Review and promotion. |
| ROADMAP | n/a: CP1 remains ACTIVE; checkpoint status does not move until `M6-CP1-CLOSE-REV`. |
| Selector manifest | n/a: no selector file was added, modified, or newly accepted. |
| LESSONS | Existing lesson 199 applies; no genuinely new pattern. |
| Consolidation under CLEAN_UP_POLICY | Immediate TB12-close predecessor plan/report/review and consumed R2/R1 plans folded into `M6_Consolidated_Record.md` §48/index; current R1 runtime report retained. |
| Successor frozen | `M6-CP1-CLOSE-REV`; falsifiers in `Architecture_M6_CP1_Close_Review_Plan.md`. |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build source mutation and no generated Directional runtime. |
| review_check.py boundary | PASS — review-turn boundary check reports no product/test/fixture/build or selector mutation; all durable-marker checks pass. |
| `STATUS` lifecycle maintained | Entry beacon published; final COMPLETE beacon is the final repository action. |
| Pushed to origin, branch in sync | Connector-applied documentation patch and cleanup are verified on the configured working branch before final beacon. |

---

## Review-agent addendum (2026-10-05, resumed `M6-CP1-TB12-CLOSE-R1-REV`)

**Disposition:**
- **Acceptance and promotion of `11330703256 / 3f40f04a...` (479/479): CONFIRMED.**
- **Two claims overstate the runtime proof** (Q3).
- **Two defensive branches have no executed falsifier and no owner** (Q4).
- The close plan does not freeze CP1's successor (Q5).
- **RA-27b** records owners and amends the close plan. The successor stays **`M6-CP1-CLOSE-REV`**.
- Accounting **60 / 16 / 44**, debt 1.

### Q1. Independent re-derivation (confirmed)

- Result `11333591947`: ZIP `ef5dba11...`. Log `11333547162`: ZIP `dd782961...`.
- `SHA256SUMS` (`9d7f244f...`) verifies **497/497**: 479 raw logs plus metadata. This harness writes no per-process resource files.
- Focused ledger `296bc32f...` and selector ledger `d5298b2a...` are in exact focused-30 and selector449 order.
- Every row has selected=1, skipped=0, passed=1, PASS. **All 479 raw-log SHA-256 values match their ledger rows.** The RED ledger has a header only (`dc5496d3...`).
- Ordinals 29 and 30 are `[ OK ]`.
- Candidate `3f40f04a` source == HEAD source. Its diff from `02149f15` touches 2 files: `RemeshPipeline.cpp` (+26/−6) and the test file.

### Q2. RA-27a code review (confirmed)

- **Wedge rule** (`RemeshPipeline.cpp:6884-6915`):
  - fixed-point reachability from `cornerWedgeSheets.front()`, over transitions with `region == topologyRegion` and both sheets in the set;
  - accepts only if the reachable set equals the sheet set;
  - single-sheet members pass trivially;
  - site `cross-sheet:wedge`.

  It matches RA-27a §2 exactly. The edge rule is unchanged.
- **Membership.** `wedge_contains_sheet` uses `binary_search`. The A5 *producer* sorts and dedupes (`:4446-4453`); `publish_records_for_validation` does not. Unsorted or duplicated input can only cause **false rejection**, never false acceptance, so this is fail-closed.
- **C4 name.** Now `QuotientClosedComplexStripContinuationMismatch`. This was required, not cosmetic: DEFN-R3 freezes "external A6 diagnostics use the `Quotient` prefix".
- **Identity 29.** It runs on a consistent chain:
  - bridge non-vacuity, then baseline acceptance;
  - every bridge transition rewritten to sheets 99→100, still non-empty;
  - republish A5, re-produce A6 and assert success;
  - A7 fails at `cross-sheet:wedge`.

  The old proxy accepts this tamper, so the test discriminates.

### Q3. Overclaims (Low–Medium)

1. **"RA-27a §2 discharged by the exact graph plus the ordinal-29 runtime falsifier."** The tamper moves **both** endpoints of every transition outside the set, so it falsifies only the "no transition inside the set" case. These conjuncts are verified **statically only**:
   - the **region filter**: a mutant that ignores region passes identity 29;
   - **connectivity versus "touches the set"**: a mutant accepting any transition with one endpoint in the set also passes;
   - **three-sheet partial connectivity**.

   The production code is correct by inspection, but the record should say "static plus one runtime dimension". Owner for the missing tampers: Q6.
2. **"Produced `cornerWedgeSheets` are sorted/unique before publication."** True of the producer, not of the publication seam (Q2). Harmless, but imprecise.

### Q4. Defensive branches with no executed falsifier and no owner (Medium; not CP1-blocking)

| Branch | Why it is unfalsified | Why it is not CP1-blocking | Owner (RA-27b) |
|---|---|---|---|
| C4 `ClosedComplexStripContinuationMismatch` (`:6310-6333`) | A non-unique opposite needs a pinched interior vertex: two 2-quad fans sharing one vertex. Only a weld produces that, and CP1 item 6 rules welds out. | It fails closed; identity 28 proves it does not fire falsely on the produced torus. | `M6-CP2-DEFN`: a weld-constructed malformed-authority witness, together with the verifier's manifoldness recompute (frozen §6.2). |
| C2 empty-front `MissingAuthoritativePhaseFront` | A4 rejects empty edges and cells first (identity 30 says so honestly). | Unreachable through product authority. | Accepted as defensive; no owner needed. |

TB12-R1-REV §3 lists neither branch. CLOSE-REV must classify each explicitly; RA-27b §3 amends the close plan to require this.

### Q5. The close plan leaves CP1's successor open (Medium, routing)

`Architecture_M6_CP1_Close_Review_Plan.md` ends with "freeze exactly one next turn under the roadmap". The carried obligations, however, are split across two owners that the roadmap orders CP2 → CP3:
- **CP2 entry:** the verifier contract (frozen §6, §10). OBS-01, the missing A6 → A5 certificate binding, belongs here, because §6.2 lets the verifier check "deterministic equality of immutable certificate payloads". So does RA-26 §5(iii) (retire or replace the vacuous `project_vertices` sheet check), and the Q4 C4 witness.
- **CP3 entry (`M6-DEFN-R5`):** the gauge obligations, the A5 barrier-set census, RA-26 §5(i)(ii)(iv), RA-27a §6 (edge-rule falsifier) and OBS-02.

Letting CLOSE-REV choose freely invites jumping to DEFN-R5, which would skip CP2 and overload one Definition turn (lesson 188). **RA-27b freezes the post-closure successor as `M6-CP2-DEFN`**: a bounded, runtime-free definition of `SurfaceProductVerifier` with the CP2-entry items. `M6-DEFN-R5` follows CP2.

### Q6. Observations

- **`M6-CP1-TB12-R1-REV-OBS-01`.** Identity 29 lacks region, one-endpoint and three-sheet tampers (Q3.1). Owner: the first `M6-CP2` Code + Build, as **new appended identities**; identity 29 stays unchanged.
- **`M6-CP1-TB12-R1-REV-OBS-02`.** The adapter maps `UncertifiedCrossSheetBinding` without A7's site (`RemeshPipeline.cpp:7462`), so edge and wedge failures share one adapter string. A7 keeps the site, so diagnosability is lost only at the adapter boundary. Owner: M8-CP2 (diagnostics).

### Q7. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived: 497/497, frozen order, 479/479, all raw hashes match. |
| RA-27a code | Confirmed; fail-closed under malformed membership input. |
| Overclaims | Q3 recorded; runtime proof covers one dimension of the wedge rule. |
| Defensive branches | C4 → `M6-CP2-DEFN`; C2 empty-front accepted as defensive. |
| Close plan | RA-27b block: exit items verbatim from frozen §526; defensive-branch classification; `G4-B002` debt stays open; successor `M6-CP2-DEFN`. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 200. |
| Successor | `M6-CP1-CLOSE-REV`, unchanged. |
