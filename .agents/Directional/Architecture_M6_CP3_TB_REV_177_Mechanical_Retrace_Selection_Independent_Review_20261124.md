# M6-CP3-TB-REV-177 — independent TB177 review (2026-11-24 UTC)

## Situation

TB177 remains **REJECTED**. The immutable full gate executed 1,001/1,001 cases: 994 PASS, seven RED, no missing, duplicate, skipped or abnormal cases. The review of the artifacts is complete; freezing the exact reference-remap helper and closing this Review turn remain outstanding. No successor is authorized yet.

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

## Recommendation — pending exact freeze, not authorization

The H2 predicate supports preparing the one bounded CB-199A pure unwired reference-remap helper and unit test required by H4. The exact candidate diff is not yet frozen. Continue **this Review turn** until it is. Do not apply or compile a successor patch in this Review.

The helper must resolve every affected contact to the unique admissible exact source locus on the retained trace, including the recorded struck-segment index. Preserve component/region, exact contact coordinate and carrier semantics. Face interior, carrier entry/slide interior and mutual terminal sentinels have distinct reader contracts; do not collapse them to position matching or a reverse index. Reject absent or ambiguous matches before committing any change. Require both actual terminal-singularity equalities and unique arrival-port ownership. Event incidences must retain their physical endpoint and role; the removed origin maps to the kept arrival, not to the kept origin. Preserve the other incidences and forbid dangling trace/port references. Use the existing exact source-piece and contact occupancy functions before adding abstractions. The exact diff must state which unsupported contact representations fail closed and exercise those stops.

Required falsifiers for the exact freeze: reverse paths with unequal subdivisions and an interior struck contact; correct kept trace ID but wrong struck segment; a broken arrival; missing/ambiguous locus; endpoint incidence roles and unrelated records preserved; no partial publication on failure. Show how the test fails with the corresponding remap omitted. Verify the helper is unwired, keep test selection and manifests unchanged until the separate authorized execution turn, and never count a helper pass as production success. The later CB-199B switch, CB-200 readers, CB-190 and row979 remain held. E5, F1/F3/F4/F5 and S4/S6/S7 remain carried. No CP3/497/D0/H4 promotion.

## Review closeout — work in progress

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 rows + header; hash above |
| Decisive claims independently re-derived | Both outer ZIP hashes, 4,020 internal hashes, 2,002 raw-log hashes, 1,001 complete comparisons, receipt and source readers |
| Non-vacuity checked | Four actual reverse pairs, exact path availability, both arrival equalities, isolated negative row1001; production remains unwired |
| Prior obligations discharged/carried | H2 receipt prediction discharged; H4 comparison STOP retained; remap and reader obligations carried above |
| Stable accounting | 67 events / 17 categories / 50 recurrences; debt1, deferred81; accepted TB169 993/993 and CP2 491/491 unchanged |
| New candidates/obligations recorded | Struck-segment and endpoint-incidence obligations; existing TB170 recurrence, no new stable event |
| ORIENTATION currency line | Updated in this preservation patch; review remains active |
| ORIENTATION §3 / §4 / §7 / §8 | Current rejection, exact receipt witness, pending freeze and unwired-helper pattern updated |
| CHANGELOG | Review progress entry, not completion |
| ROADMAP | Near-term routing corrected; no milestone promotion |
| Selector manifest | n/a — unchanged, prefix independently rehashed |
| LESSONS | Existing exact-freeze and single-owner rules apply; no new lesson needed |
| Consolidation under CLEAN_UP_POLICY | n/a — no completed review to fold yet |
| Successor frozen | PENDING — exact candidate diff and non-vacuous unit test not frozen; retain current Review |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/build mutations |
| review_check.py boundary | Run on verified snapshot; historical Git ancestry unavailable in archive; local patch boundary verified separately |
| STATUS lifecycle maintained | Entry/resume published; final beacon to reflect actual publication and unfinished freeze |
| Pushed to origin, branch in sync | PENDING — verify remote publication before claiming completion |
