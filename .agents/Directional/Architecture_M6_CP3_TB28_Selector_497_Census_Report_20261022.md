# TB28 — selector-497 artifact-only census (2026-10-22)

**Turn:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS`; **type:** Test + Benchmark, artifact-only, unchanged CB26 package. **Disposition:** candidate measured; independent TB28 Review required; no stable acceptance or RP-01 closure.

## Immutable evidence and execution boundary

- [Run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202) — dispatcher success, immutable result artifact **12424484672**, ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; complete result manifest **1019/1019** entries independently verified and covering all ZIP payload files.
- Semantic source **`e3d60337ed34538547d3a6d519bafae5b184330e`**; compiled GMP/GMPXX candidate artifact **12409939859**, ZIP SHA-256 `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`.
- Unchanged existing `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`). Dispatcher event SHA `f190214ba53d92f59efd9d3321d13243a2ed5b7a`; workflow mailbox key `m6-cp3-tb28-selector497` on dedicated `workflow-mailbox` branch.
- `runtime_started=true`, `runtime_completed=true`, `script_exit=0`; exactly **497 selected and executed** (30 focused30, 12 focused12, 449 selector, 6 cp3entry); 497 distinct phase/ordinal keys, matching TB21 identity/owning binary. Every process has exactly one `[ RUN ]`, PASS logs one `[ OK ]`, RED logs failure, no skipped/duplicate case. Candidate package, source, and execution-view before/after censuses match byte-for-byte. `compile_execution=false`, `relink_execution=false`, `configure_execution=false`, `benchmark_execution=false`, `generated_discovery=false`, `package_repair=false`, `mode_repair=false`, `source_test_fixture_selector_mutation=false`, `retry_after_runtime_start=false`.

## Candidate result relative to TB21

| Category | TB21 | TB28 | Delta |
|---|---:|---:|---:|
| PASS | 449 | **462** | **+13** |
| RED | 48 | **35** | **−13** |
| PASS → RED | — | **0** | No regressions |
| RED → PASS | — | **13** | All predicted repairs |

By group: focused30 **26/30 PASS**, focused12 **12/12**, selector449 **421/449**, cp3entry **3/6**. All 12 known seam-family cases and `selector:447` changed RED→PASS. No seam-family RED survives. No `UncertifiedCrossSheetBinding` appears in any TB28 RED raw log; therefore there are **no surviving A7 failure sites to enumerate**, and neither `cross-sheet:seam-direction` nor `cross-sheet:periodic` appears as a RED site. Absent sites are not evidence that the untested CB27 rejection branches are covered.

### Every RED → PASS (13)

| Phase | Ordinals |
|---|---|
| focused30 | `6`, `20`, `24`, `25`, `26`, `27`, `28` |
| selector | `444`, `446`, `447`, `448` |
| cp3entry | `3`, `5` |

**PASS → RED:** none. Every remaining RED is inherited from TB21; first failure, raw SHA-256, exit and inherited TB18/TB21 classification are recorded row-by-row in `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv` (35 rows). **All 497 case identities, verdicts, exits, first failures when RED, raw log hashes, and TB21 verdicts** are in `Architecture_M6_CP3_TB28_Selector_497_Full_Ledger.tsv` (497 rows), directly derived from the immutable result's `combined-ledger.tsv` and individual raw logs. Both files preserve the original selector identities without selection changes.

## Unresolved findings and non-promotion

- All 35 residual REDs are **inherited**. Their first-failure evidence is fully recorded, but causality is not adjudicated in this TB turn; the mandatory Review must classify M1, D2 and fixture-debt obligations. The ongoing RP-01 boundary remains open.
- Tests for `cross-sheet:seam-direction`, `cross-sheet:no-certificate`, `cross-sheet:periodic`, the unrelated-seam B4 precision case, and RA-127.4b are not discharged by this census. RA-132 assigns test-only CB27 after the TB28 Review; that successor is **not** started here.
- No stable ledger mutation: **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, accepted CP2 **491/491**, rejected R3 **403/497**, selector 497 byte-frozen; TB21 **449/497** candidate superseded by TB28 **462/497** candidate, not promoted. `RP-02` UNREACHED, Gate C suspended.

**Authorized next turn:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV` — independently re-derive archived evidence, adjudicate all remaining RED families and the zero-regression result, and issue CB27 if warranted. No corrective source work or additional runtime is authorized in this TB turn.
