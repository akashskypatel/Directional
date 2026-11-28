# M6-CP3-TB-REV-177 — independent TB177 review (2026-11-24 UTC)

## Situation

TB177 remains **REJECTED**. The immutable full gate executed 1,001/1,001 cases: 994 PASS, seven RED, no missing, duplicate, skipped or abnormal cases. The artifact adjudication is complete. Exactly one bounded compile-only successor is frozen below; no successor implementation has started.

## Background — independent evidence

- TB177 run `45283342400`, result `14871900641`: outer SHA-256 `8c5bce907f59b77207833153912805cccca6fa122c70ff9f299a64f68102b068`, 2,010/2,010 internal hashes and 1,001/1,001 raw-log ledger hashes independently verified. Semantic source `6cdd23a10ac6f6fbc6c741fb1e18ccff2038871c`, compile package `14868834752`.
- TB176 run `45263429563`, result `14861444963`: outer SHA-256 `202cb81282d9e8a0bb6b711020af80450e407feb12b71de613b1be8cca110453`, 2,010/2,010 internal hashes and 1,001/1,001 raw-log ledger hashes independently verified. Source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`, package `14859356205`.
- Source snapshot `defabd83aade7e70a2f10214f773f03b21e7eb5d`, run `45290947596`, artifact `14874770155`, outer SHA-256 `60b48091f4dfdea919de66b1aa4cce46fcf6de2b4981b11446af6d415b3914d5`, source tar SHA-256 `5dfe4b5550f8a3eb7be68104895eca1c296d324b60675a2dc2542c1d76034690`. All 5,834 source digests verified. The exact CB-198 test-only diff SHA-256 is `c30811fca14154427a41d5e90f3fb565bbbbfe0b5601eec8bcec36e845e6391b`; +108/−0 lines. The current test source SHA-256 is `75ae997a94d766bcc9cda56f37abbb3bb9e655758d141003cfbf51c6cb638cc6`.
- Both execution-boundary records confirm 1,001 planned and executed, postflight true, no configure, compile, relink or benchmark, exit 90 (required controls failed). Membership files are byte-identical: 1,001 gated + 81 deferred. Unchanged TB176/TB177 manifest SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`; accepted 491-row prefix plus header re-hashed to `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`.

## Assessment — frozen H4 comparison

All 1,001 verdicts and identities match. Both runs have RED rows 445/652/653/656/658/660/786. Candidate CP2 remains 490/491.

| Comparison class | Rows |
|---|---:|
| Byte-identical raw logs | 650 |
| N1/N2 only (elapsed time/line endings) | 343 |
| N3 complete-record reorder, row172 | 1 |
| Authorized receipt insertion, rows652/656 | 2 |
| Unapproved assertion-line movement | 5 |

Row172 contains six identical complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records in a different order. The prefix count, complete-record multiset and non-record remainder match. Frozen H4 explicitly permits N1–N3: row172 therefore conforms to N3, not an additional exception. The previous execution STOP remains correct because five other rows fail H4. No retrospective normalization is authorized. Their ledger `first_failure` and raw assertion locations both move by exactly +108:

| Row | TB176 | TB177 |
|---|---:|---:|
| 445 | 19338 | 19446 |
| 653 | 14349 | 14457 |
| 658 | 19919 | 20027 |
| 660 | 14148 | 14256 |
| 786 | 19978 | 20086 |

The frozen test diff inserts 108 lines before these assertions. These are source-location changes, not newly failing controls. The H4 comparison remains rejected; no change to the historical execution report or rule. All other ledger fields match except per-run log hash. The new receipt is 1,208 bytes in each of rows652 and656, at the authorized insertion point; the two receipts are identical.

## Assessment — H2 non-vacuity and reference-remap risk

Both receipts show available exact paths, four retrace pairs and both arrival equalities. For each pair, five pieces on each trace, no face pieces, reversed ends and five shared source edges. The recorded origins/arrivals are singularity IDs, not source vertex IDs. IDs 1/3/5/7 map to vertices 10/35/47/71 in both raw port inventories.

| Kept trace | Removed trace | Kept origin ID | Removed origin ID | Kept arrival ID | Removed arrival ID | Arrival port to preserve |
|---:|---:|---:|---:|---:|---:|---:|
| 0 | 3 | 1 | 3 | 3 | 1 | 3 |
| 2 | 8 | 1 | 5 | 5 | 1 | 8 |
| 7 | 9 | 5 | 7 | 7 | 5 | 9 |
| 4 | 11 | 3 | 7 | 7 | 3 | 11 |

The existing thrown failure branch computes exact source pieces for all segments, rejects unavailable/empty/disjoint paths, invokes the same ordered predicate as the isolated guard and reports the actual arrivals. Row1001 still passes the negative repeated-stretch case. This evidence discharges the receipt prediction, not the production selection. The four lens orbits remain; row652 is `RegionElectedCutComponentEmpty`. Row979 remains staged `RegionContainsInteriorSingularity` at source vertex8. No acceptance promotion.

**Additional static finding:** `FieldAlignedTerminalContact` stores both `struckTrace` and `struckSegmentIndex`; changing only the trace ID can leave the contact on the wrong segment. `field_aligned_publish_contact` writes the pair; `EmbeddedGraphTopology.cpp` consumes that pair in face and carrier contact position readers. The exact reverse path predicate permits different piece subdivisions; a reversed index alone is not an exact mapping. The graph contact node's `sourceVertex` can be a face-corner provenance placeholder, not the contact point. Do not use that field as the locus.

## Recommendation — exactly one frozen successor

Freeze **`M6-CP3-CB-199A-P13-RETRACED-TRACE-REFERENCE-REMAP`**, Code + Build only, as the [Exact proposed diff](Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Exact.diff), SHA-256 `4f458361453186fdc9c7e0073b039fc3329f084d4b01b0eb6c2e193071d22bf7`, +458/−0 lines in exactly two proposed product/test paths. This `.diff` is a Review document, not an applied source change. Apply against unchanged semantic source `6cdd23a10ac6f6fbc6c741fb1e18ccff2038871c` (or verified identical intended paths on the working branch). Forward `git apply --check` on the verified snapshot, reverse check against the exact proposed postimage, and `git diff --check` all pass; no compilation or runtime performed in this Review. The exact postimages are:

| Proposed path | SHA-256 |
|---|---|
| `src/geometry/RetracedTraceReferences.h` (new) | `baa7712de93a712ae4afcfaba039613179beed2d477ecf9aec12c59ca830a277` |
| `tests/FieldAlignedCurveNetworkTests.cpp` (append only; preimage `75ae997a94d766bcc9cda56f37abbb3bb9e655758d141003cfbf51c6cb638cc6`) | `f86f0a1719ddc431f2102078924e7acb8e17111a6a060670f7992cf0dce81698` |

**Bounded contract.** The pure helper accepts one selected pair of stable trace IDs and an immutable candidate. It checks both singularity arrivals, exact path continuity, positive reverse traversal, unique trace and port identity, and common component/region. It returns a separate candidate copy with the duplicate removed, reference remaps and an explicit `(arrivalTrace, arrivalPort)` binding. It never mutates or publishes the input. The future switch must use the selector's disjoint pairs in canonical port order, apply all pairs transactionally, store the arrival binding with the product, and fail closed before publication if any pair fails; that is not part of CB-199A. No selection call in production, no product publication or digest change, no reader changes, no validation weakening in this CB.

**Exact struck reference.** `struckTrace` and `struckSegmentIndex` change together. For carrier entry and slide contacts the helper uses the existing occupancy and strict interior rules; for same-chart face contacts it uses the exact chord parameter rule. It verifies the old reference and requires a unique reader-admissible retained segment. Reject unrepresentable face/chart changes, mutual terminal sentinels, absent or ambiguous matches, incompatible component/region, repeated contact-node claims or missing event evidence. Never infer contact position from `NetworkNode.sourceVertex`, use a reverse index, convert a face contact to a carrier contact, or weaken the exact predicates. Unrelated records are preserved.

**Endpoint incidence.** Remove the duplicate origin incidence and duplicate termination/first-contact records, retain all ports and nodes, bind the kept terminal and corresponding first-contact incidence to the removed port, and map a shared port-junction incidence to the kept arrival (Terminal). Remap both contact event records only when their terminal incidence and exact struck contact name the removed trace; reject missing event partners and duplicate incidences. The later switch must preserve this port binding in the canonical producer and its replay/digest contract; downstream port-set readers remain CB-200. No claim that the pure helper or its temporary output is a published valid network.

**Non-vacuity and stop conditions.** The appended `RetracedTraceReferences.RemapsExactStruckSegmentAndEndpointPortWithoutPublication` guard checks explicit expected trace and event records, an unrelated trace sharing the port junction, retained nodes/ports and the input's unchanged state. Its original struck segment 0 must become retained segment 1. It also tests entry-to-slide and same-chart face-piece references. Omitting the struck index remap, using a reverse index, discarding the other port or assigning the wrong endpoint port breaks the explicit positive expectations. Missing arrival, invalid original segment, unsupported contact representation, missing event partner and an ambiguous repeated path must return no result. These are frozen predictions, not observed test outcomes. Compile the exact patch by the established GMP/GMPXX workflow (eight targets) with `runtimeExecution=false`; STOP on nonmatching preimage, any diff outside the two paths, compilation failure, or any production caller. Return to Review for any needed change to the frozen contract; do not widen scope during compile. The separate artifact-only TB must add exactly this one guard to the inherited 1,001-case manifest, predict 995/1,002 PASS with the same seven RED, verify the accepted prefix and compare all prior raw logs under N1–N3 with no new semantic or assertion-location changes (test appended at EOF). The guard must execute and pass; any unexpected difference means STOP. The H4 historical STOP remains recorded; no acceptance promotion. CB-199B and CB-200 remain held until separate TB and Review. E5, F1/F3/F4/F5 and S4/S6/S7, CB-190 and row979 remain carried. No CP3/497/D0/H4 promotion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 rows + header; hash above |
| Decisive claims independently re-derived | Both outer ZIP hashes, 4,020 internal hashes, 2,002 raw-log hashes, 1,001 complete comparisons, receipt and source readers |
| Non-vacuity checked | Four actual reverse pairs, exact path availability, both arrival equalities, isolated negative row1001; production remains unwired |
| Prior obligations discharged/carried | H2 receipt prediction discharged; H4 comparison STOP retained; remap and reader obligations carried above |
| Stable accounting | 67 events / 17 categories / 50 recurrences; debt1, deferred81; accepted TB169 993/993 and CP2 491/491 unchanged |
| New candidates/obligations recorded | Struck-segment and endpoint-incidence obligations; existing TB170 recurrence, no new stable event |
| ORIENTATION currency line | Updated with final adjudication and exact successor |
| ORIENTATION §3 / §4 / §7 / §8 | Current rejection, exact receipt witness, exact freeze and unwired-helper pattern updated |
| CHANGELOG | Review progress entry amended to final adjudication |
| ROADMAP | Near-term routing corrected; no milestone promotion |
| Selector manifest | n/a — unchanged, prefix independently rehashed |
| LESSONS | Existing exact-freeze and single-owner rules apply; no new lesson needed |
| Consolidation under CLEAN_UP_POLICY | n/a — retain this active exact-review record and prior frozen evidence; no historical deletion |
| Successor frozen | `M6-CP3-CB-199A-P13-RETRACED-TRACE-REFERENCE-REMAP`; exact diff and falsifiers in Recommendation |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/build mutations |
| review_check.py boundary | Executed on verified source snapshot; selector checks pass; historical Git rewrite baseline/source checks fail because archive excludes remote `.git`. Local exact changed-path and diff checks passed; remote source authority verified with connector. |
| STATUS lifecycle maintained | Entry/resume published; final completion beacon only after exact freeze document publication and retirement |
| Pushed to origin, branch in sync | Progress patch verified pushed at `f9e2c977418ac978d9ac0d88e16f78ff440f0877` by run 45307046104; all seven changed paths verified. Final exact-freeze publication is verified via immutable drive_apply result and remote branch readback before the final STATUS beacon. No remote ancestry is inferred from the synthetic local Git tree. |
