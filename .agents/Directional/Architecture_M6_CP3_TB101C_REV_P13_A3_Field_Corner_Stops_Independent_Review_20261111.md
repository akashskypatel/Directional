# TB101C independent field-corner stop review — 2026-11-11 UTC

## Situation

**Scoped MATCH / Review COMPLETE.** Independently checked immutable full-gate and census evidence against previous TB100B. The field-corner helper/factory gate is accepted **only at the tested, unwired boundary**. This Review does not approve production wiring, exact boundary-branch decisions, selector497 promotion, or a direct BunnyRandom/Vase success.

## Background and independent evidence

- Source commit: `e1e5b17e94f189c88c74172e12dfd6ac93cc532b`. Immutable compile artifact `13852160952` from [run 43013777504](https://github.com/akashskypatel/Directional/actions/runs/43013777504). Both runtime evidence boundaries say `configure=false, compile=false, relink=false, benchmark=false`.
- [Full gate 43016290356](https://github.com/akashskypatel/Directional/actions/runs/43016290356), artifact `13853426731`, ZIP SHA-256 `b94d9c201720490e8651655218ebb9ade7f71f62396e25b45d31eef99e7285ee`: independent outer checksum check, 1,888/1,888 internal hashes, 940/940 PASS, 1,021 membership. 930 GUARD and 10 POSITIVE rows; no failed, skipped or duplicate rows.
- [Census 43016362575](https://github.com/akashskypatel/Directional/actions/runs/43016362575), artifact `13853038984`, ZIP SHA-256 `ce0a4d256449e5aea6108044ddfe90b31634eefe394031922bb98c6482d0f05e`: independent outer checksum check, 9/9 internal hashes, Cylinder PASS, BunnyRandom RED, Vase RED; zero abnormal results. Two RED outcomes remain registered, not accepted-green losses.
- Compared against original TB100B artifacts `13828258166` and `13828198354` (verified outer hashes and 1,884/1,884 plus 9/9 inner checksums). All **938 inherited** ledger records agree field-by-field (`row`, `kind`, `identity`, `test`, `binary`, `verdict`, `exit`, `run`, `passed`, `skipped`, `typed_reason`). Rows 939 `GlobalConformityBaseline.StopNodesReadBoundaryFieldCorners` and 940 `SurfaceCellAuthorityContractCutover.ChainedInputStopsAtBoundaryFieldCorners` are new and PASS.
- Raw controls unchanged against the previous accepted gate/census: **7/7** `platform-digest` lines, **7/7** `a3-coverage` lines, **4/4** `d4-rim` lines and **2/2** `FIELD_CORNER_RECEIPT` lines.
- The four new `d4-corner` lines are exact observed counts, **not production proof**:

```text
d4-corner case=Plane inputs=own fieldCorners=4 chains=4/4 spans=4/4
d4-corner case=MultiFaceSeam inputs=own fieldCorners=4 chains=4/4 spans=4/4
d4-corner case=CloseSheets inputs=own fieldCorners=8 chains=8/8 spans=8/8
d4-corner case=Cylinder inputs=own fieldCorners=0 chains=2/2 spans=79/79
```

- **Historical receipt absent:** `FIELD_CORNER_STOP_RECEIPT` is absent from both the former and current evidence. It belonged to a superseded one-shot plan. No current sliced gate required that exact line. Its absence is not a failed test, but it also gives **no positive stop receipt**.

## Assessment and non-vacuity

The new stop test supplies vertices `5,6`, tests duplicates and order changes, and checks that an unknown vertex changes nothing. The factory test passes a manually specified source vertex `3` to force a different chain count and span count; removal of the stop handling would make that test fail. The four fixture-produced `d4-corner` results, however, have identical original/new chain counts. They do **not** demonstrate an actual derived pass-through field corner changes a chain on a live curved disc. This limits the claim.

`GlobalConformityBaselineSupport.cpp` maps every declared `SourceVertexId` to all network nodes with the same source vertex when making stops; it does not limit them to one source-chart fan or local sheet. `SurfaceCellTracing.cpp` derives field-corner decisions with floating-point alignment and a tolerance. Thus **fan/sheet-safe stop identity** and **exact common branch decision** are not established. The next Review must decide fan identity; O39 remains a separate mandatory exact single-writer gate before O36.

Cylinder is an observed direct PASS, but its `a3-coverage` evidence says `scheduled=81, covered=0, unrecorded=81`, so this does not show production A3 consumption. BunnyRandom and Vase remain RED and no new stable regression occurred. The accepted CP2 prefix remains 491/491; current test gate is not CP3 selector497 promotion.

### Prior obligations and disposition

- RA-224/O38 corner-product definition: **scoped helper/factory gate accepted**; direct production switch remains open.
- TB100B adversarial re-review: **carried** source-vertex/fan/sheet stop equivalence, a nontrivial transported straight-rim witness, and a certified exact boundary branch authority. No false hard-feature or pass-through-rim falsifier is restored.
- O39: **carried**; exact/certified single-writer branch decision must be decided and independently checked before O36.
- O34/O35/O36/O37 and D6: **carried**; no production scope expansion.
- New stable defect: **none**. New candidate: the *non-vacuity and fan/sheet identity gap*, assigned to the next Review; no stable counter change.

## Recommendation — exactly one successor, not started here

`M6-CP3-DEFN-P13-A3-BOUNDARY-FAN-STOP-IDENTITY` — Review only. Before any implementation, define the authoritative stop identity per source-chart fan and sheet, including what happens when one source vertex supports multiple separated fan occurrences; give counterexamples for cross-sheet propagation and nontrivial branch transport. Prohibit world-space fallback, duplicate producer branches, selector changes, and O36 wiring. If the evidence does not define a single correct identity rule, leave the future implementation conditional. Next after that, in a separate Review, `M6-CP3-DEFN-P13-A3-EXACT-BOUNDARY-BRANCH-OWNER` for O39.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 938 inherited case-manifest ledger rows matched exactly. Existing CP2 selector SHA-256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; full-case selector SHA-256 `8caccb929155a960bee8c8fe5b0c0ca67a24dabdb8d1ad50c76e426eb96a23db`; no selector mutation. |
| Decisive claims independently re-derived | Both ZIP hashes, 1,888 + 9 checksums, 940 rows, 3 census dispositions, prior 938-row comparison, 7 + 7 raw records, four rim and four corner lines. |
| Non-vacuity checked | Manual corner stop changes chain result and would fail if deleted; derived four-case census did not show a chain-count change. |
| Prior obligations discharged/carried | RA-224 narrowly discharged; fan/sheet, O39, O34/O35/O36/O37, D6 carried. |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt 1; deferred 81; accepted CP2 491/491; CP3 selector497 unpromoted. |
| New candidates/obligations recorded | Fan/sheet and nontrivial positive derived stop witness carried to next Review; no stable loss. |
| ORIENTATION currency line | `M6-CP3-TB101C-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-REV` 2026-11-11. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 refreshed; §4 no fixture state changed; §8 no new recurring pattern. |
| CHANGELOG | Independent Review entry added. |
| ROADMAP | n/a: checkpoint state unchanged. |
| Selector manifest | n/a: no new or accepted selector. |
| LESSONS | Existing review non-vacuity rule applies; no new recurring lesson. |
| Consolidation under CLEAN_UP_POLICY | n/a: new current review record retained; no historical document deleted. |
| Successor frozen | `M6-CP3-DEFN-P13-A3-BOUNDARY-FAN-STOP-IDENTITY`; source/fan/sheet falsifiers and stop rules above. |
| Turn boundary held | Review only: no compiled binary ran and no code, fixture, test, selector, benchmark or build content changed. |
| review_check.py boundary | Ran locally: FAIL because snapshot has no original Git ancestry or complete tracked baseline. Reported failures are baseline/`git status` context, not source/test mutations; full check must run on a real checkout before final closure. |
| `STATUS` lifecycle maintained | Entry was published; final COMPLETE beacon is the last repository action for this turn. |
| Pushed to origin, branch in sync | Pending remote patch-application confirmation; snapshot does not have the source branch Git ancestry. |
