# TB145 — independent full-gate Review (2026-11-19 UTC)

## Situation — decision

**MATCH upheld; no EC3 exact code patch authorized.** All 964 old cases match under the frozen TB144 comparison, and the 491 accepted cases remain green. EC3 needs an additional **symmetric entry-contact binding definition**, not a speculative producer-only patch. Review rejects EC3 implementation authorization until that contract is proved. This is a completed negative review decision, not a successful production gate or an independent product acceptance. M6-CP3 remains active. No product, test, fixture, selector or binary is changed in this Review.

## Background — independently checked immutable evidence

| Immutable result | Artifact | GitHub ZIP SHA-256 | Internal checks |
|---|---:|---|---:|
| TB144 gate | 14501920082 | a2cdbdf635d91b9fde4be5f5fa093d96d088714b24e5f22988518051824b7922 | 1,930/1,930 |
| TB144 census | 14502085765 | e7573335b7f222f6e6e383c2fa714697a14e70b5eaefac83bd89f1abdcf601c4 | 9/9 |
| TB145 gate | 14510581877 | bac8df3f16b8161f92813e30644ac5d96e9538395fcd4c6b00b285f83d6519fe | 1,930/1,930 |
| TB145 census | 14510118951 | 463a9be377eed40e8c327760f299819b41928e70535aa34c00fe3d14a8507a1d | 9/9 |

Exact package-source authority: `d43d07dd1564be90bc1a89775b17b524d4e83039` (CB168E), package `14508452647`; gate run `44484110110`, census `44484220632`. The prior comparison base is TB144. The 961-row manifest retains SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949`. No selector byte change or promotion.

An independent local comparison recomputed ledger hashes from all raw logs, compared 961 gate and 3 census rows, removed only the defined `firstArrival=... faces=...` diagnostic suffix, and applied the frozen N1/N2/N3/N4/N7 normalizations. **964/964 exact previous records MATCH.** Gate: 960 PASS, known row858 RED at `SurfaceCellTracingDisplayTests.cpp:155`; new row961 PASS. Accepted prefix: 491/491 PASS. Census: Cylinder PASS/288 quads; BunnyRandom and Vase RED. All 1,266 raw `slideProposal` and 1,266 raw `committedSlide` records equal TB144 byte for byte; 246 original entry receipts remain byte-equal before the suffix (240 gate, six census). Exactly 240 new gate suffixes and six census suffixes. No duplicated `M3_CP4AB_FRAGMENT_DIAG` prefix. Counts of matched M3 diagnostic records are 1,738 gate plus eight census.

The comparison is not a copy of the execution report: row-level raw bytes, record multisets, signed outcome ledger, and archive hashes were inspected separately. The accepted prefix is unchanged because rows 1–491 match the same immutable predecessor logs; no new selector was accepted. Failure of a hash, a changed M3 record, a changed slide, a changed historical receipt prefix, a second suffix, or a changed outcome would have failed the comparison. Distinct outcome types remain visible and are not normalized.

## Assessment — exact contact census and unresolved producer/consumer contract

| Source | First / second | Source edge | Exact parameter | Arrival | Faces | Selected cut crossing |
|---|---|---|---|---|---|---|
| Sphere (20 gate rows) | 4:7 / 6:7 | (0,2) | 574181338608147/4503599627370496 | inconclusive | different | yes |
| Sphere (20 gate rows) | 15:7 / 19:7 | (25,27) | 574181338608147/4503599627370496 | inconclusive | different | no |
| BunnyRandom census | 15:21 / 43:15 | (72,243) | 191903898244039/562949953421312 | later | same | no |
| BunnyRandom census | 15:22 / 43:16 | (72,273) | 1755811011335563/2251799813685248 | later | same | no |

The two Sphere contacts are *transverse entry/entry coincidences*. `first_field_aligned_carrier_contact` detects them, but the current queue (`SurfaceCellTracing.cpp`, pending/pending and pending/wall loops) enqueues only `ProperCrossing`; those exact entry contacts have no shared graph event. Their arrival comparison is **inconclusive**, not proof that either trace is later. A tie-breaking rule that elects one senior trace without independent ownership evidence is not justified. BunnyRandom is same-face and belongs to O48, not this EC3 switch.

**New contract conflict, called EC3-SYM-1.** At these Sphere contacts both pending segments start at the same edge point. A symmetric termination at the entry must not commit either pending segment beyond that edge: it must stop at each trace's last already-committed endpoint. However, the existing consumer `carrier_contact_struck_position` in `EmbeddedGraphTopology.cpp` only validates a `carrierLocus` when `struckSegmentIndex < struck.segments.size()` and the *struck segment's entry* is on the exact edge and parameter. If both newly entered segments are not committed, their proposed indices are out of range. Substituting the previous index is not equivalent: it names the preceding segment's **exit**, while this helper requires an **entry**. Committing either pending segment merely to make an index exist would violate the stop-at-entry requirement and may create an invalid continuation or zero-length incidence. The current `field_aligned_publish_contact` commits terminating proposals before publication and sets terminal contact without edge locus; simply enabling the entry/entry predicate is not a correct fix. Two possible edge regimes (cut and non-cut) must both retain exactly one canonical contact node and valid incidence. These results identify the missing contract but do **not** yet establish the correct complete mutation for the producer, trace binding, cut graph, and event roles.

**Decision:** reject the unproved exact EC3 implementation freeze. No product/source changes, fabricated arrival ordering, positional node merge, weakened helper, inferred successful Sphere result, or promotion. Preserve stable 66 events / 17 categories / 49 recurrences, one produced-witness debt and 81 deferred identities. O47 remains open. O48 still owns the BunnyRandom same-face pairs. Row858 remains the permitted prior RED; no D0, CP3 or selector497 acceptance.

## Recommendation — one bounded successor, not executed here

`M6-CP3-DEFN-P13-SYMMETRIC-TRANSVERSE-ENTRY-EDGE-BINDING` — a definition-only turn. It must freeze exact *symmetric entry-contact* semantics before Code + Build. Establish whether a shared edge-entry event can use the two **pre-entry** committed endpoints while satisfying unique event incidence and `carrier_contact_struck_position`; if not, specify a new typed binding for a *preceding segment exit*, with exact source edge/parameter, two terminal roles, and no implicit source-chart or position merge. Prove both selected-cut and non-cut edge cases, event/source-edge agreement, trace node cardinality, and valid `build_arcs` cut positions. Specify outcome when one or both predecessor segments do not exist, and rollback/retirement constraints. Preserve RA-259/RA-260/RA-262/RA-266, RA-245 and the 491 accepted prefix. The successor must produce a bounded, falsifiable exact code patch and negative controls for consumer mismatch, but **not** implement or run it during definition. Stop if the consumer requires silently changing CB168D's frozen semantics, a missing predecessor, or an unproved two-terminal role transition; do not start Code + Build before these obligations are resolved.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Manifest SHA-256 `fc1264e9…613e949`, unchanged; prior 491 row raw digests independently compared, 491/491 PASS; no selector accepted |
| Decisive claims independently re-derived | Four ZIP hashes, 3,878 internal file checks, 964 matched row logs, raw slides and entry receipts, exact contact-pair partition |
| Non-vacuity checked | Row858 remains RED, census contains two REDs, row961 PASS; changed archived bytes/records would fail hash and N3/N7 comparison; no success inferred from an inert producer |
| Prior obligations discharged/carried | RA-266 TB145 comparison discharged; O47 and EC3-SYM-1 carried to definition; O48 stays separate; H4/O49 and row858 held |
| Stable accounting | 66 / 17 / 49; debt1; deferred81; accepted CP2 491/491; CP3 selector497 not promoted |
| New candidates/obligations recorded | EC3-SYM-1 (producer/consumer mutual-entry binding), tracker and TODO |
| ORIENTATION currency line | Updated to TB145 review 2026-11-19 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated; §4 no witness result changed; §7 re-prioritized; §8 records the contract pitfall |
| CHANGELOG | Review entry added |
| ROADMAP | n/a; checkpoint status unchanged (M6 CP3 active) |
| Selector manifest | n/a; no selector added/accepted |
| LESSONS | Existing lesson: single-writer authority and non-vacuity; no new durable lesson needed |
| Consolidation under CLEAN_UP_POLICY | No historical review file created for consolidation; source snapshot trigger retired from patch |
| Successor frozen | `M6-CP3-DEFN-P13-SYMMETRIC-TRANSVERSE-ENTRY-EDGE-BINDING` defined above; no successor work executed |
| Turn boundary held | No production, tests, fixtures, benchmarks, workflow or selector mutation; only durable review records |
| review_check.py boundary | Snapshot artifact has no original Git history; tool requires original rewrite-base commit. No historical-baseline PASS claimed; static path/selector diff checked independently |
| `STATUS` lifecycle maintained | Entry at 2026-11-19T08:48:32Z; final beacon written separately after repository documentation |
| Pushed to origin, branch in sync | Record after verified remote Drive patch apply and final branch read; absent verification must be marked unverified |
