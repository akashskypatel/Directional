# TB136 carrier occupancy helpers — independent Review (2026-11-18 UTC)

## Situation

`M6-CP3-TB136-P13-CARRIER-OCCUPANCY-HELPERS-FULL-GATE-REV`: **MATCH upheld** under RA-257 S4. This validates the unwired helper addition and frozen behavior, not a production correction or CP3 acceptance.

## Background — immutable authority

- CB159 source `18cc4a7d3e8ae43ce854c0edc834ab156156dcbf`; package `14405225071`, ZIP SHA-256 `2e142b042d02b81e6626c40b03f2116628d017adf510a9c2ea7f96f9a8994e8c`. Root manifest `6ba41479543ba299e4afa02c3cd6c211d7c713d32b71c5d66c10d93e909ad97d`; source archive `d97314c08f1b4a49ab47c6962d041cb0be37d1d25ed427dbfbbd031a5bfeb183`. 28/28 checksums; 371/371 src/include/tests files match the review snapshot. Eight targets, six executable modes, both libraries, GMP enabled and linked (gmpxx and gmp), five empty source status files. `runtimeExecution=false`.
- Review snapshot `84d920709ca909bf54acea8f44d397bbcf805d2e`, run [44262896302](https://github.com/akashskypatel/Directional/actions/runs/44262896302), artifact `14408667284`, ZIP `d8a364d2171d74c704c58ee7ffb4cd1c7ad3702b5b47ef07a7006ff25b12474a`, source archive `b9c5cad2e66796f2f3169e3cd8902651acc45965edfca4f491346d99c86c5056`; 5,552/5,552 internal checks. No remote source edits in Review.
- TB135 comparator source `5bdc7c092a8935faeab75cf7a739928fd8ddca46`, package `14397197316`. Complete remote comparison to CB159 shows only the three frozen source/test paths changed in the product surfaces (+31/+51/+80, no deletions). Exact diff hash `756bd652b4f188398fe2b652b078f61aa34123b7748f71f5a7bb0d303cffa266`; reverse check succeeds, three postimage blob hashes match CB159 record. No production callers of the three helpers.

| Evidence | Artifact | ZIP SHA-256 |
|---|---|---|
| TB135 gate | 14398029488 | `4cc06b817c8ecfb20b7316b7017337fd2cfc9ab81c15f0360f2d2ef8f7ccc394` |
| TB135 census | 14398329619 | `8840f1d0bf9b303a7364a1346d2f5be88f31f23eab8e73d8ae391e6308ad5453` |
| TB136 gate (run 44256775123) | 14406791564 | `1a1cccc01f86d1e1555ef896cb449dc42da8c0c30f8c41e6b2685c1e0b7045c8` |
| TB136 census (run 44256959318) | 14406826878 | `f855a98e9c5a85d3afa21659f35f3ff8c6339b56a8965057f7b54164efd64ce3` |

All four raw ZIPs were recovered from the verified EXEC evidence archive and checked against immutable records. Package and source snapshot downloaded separately. No execution or rebuild.

## Assessment — independent verification

| RA-257 S4 | Independent result |
|---|---|
| Frozen manifests | Gate `dac17a50bccea4999a5482620793bffe42de61d585d69d53724ae0d59055ebc2` is exact TB135 prefix `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` + row 954. Census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` unchanged. Membership 1,035 = 954 gated + 81 deferred. |
| Same old ledger fields and logs | 953/953 gate + 3/3 census = 956/956. Independently parsed 1,738 complete M3 diagnostic records; preserved other log order and receipt bytes. Applied only N1 elapsed suffix, N2 newline framing, N3 complete gate M3 record multiset, N4 census parameter-object presentation. No field or receipt stripping. |
| Receipts | 66 sphere lines in 19 rows and 2 BunnyRandom lines: all byte-identical (including slide/path). |
| Row 954 | `FieldAlignedCarrierOccupancy.FirstSharedParameterFollowsTheMovingTraceAlongOneCarrier` PASS. |
| No other substantive change | 1,913 raw log/time bindings; 3,848 internal checks; pre/postflight valid; no missing, skipped, duplicate or abnormal case; elapsed resource measurements are not equality criteria. Gate exit 90, row858 permitted premise RED at `SurfaceCellTracingDisplayTests.cpp:155`; census exit 0, Cylinder PASS/288, BunnyRandom/Vase RED. |

**Non-vacuity:** Independent offline comparator controls 11/11: removed, duplicated, changed and unrecognized-field M3 records; changed retained text; changed slide/path; gate presentation mutation rejected, census presentation allowed; CRLF and elapsed suffix allowed. The helper uses exact closed intervals and returns the larger low endpoint for ascending travel, smaller high endpoint for descending travel, or no result if disjoint or on different carriers. Source test asserts both directions, point and endpoint contact, near misses, different carrier, entry/slide extraction and absent/off-carrier cases. These assertions would reject always-empty, wrong-endpoint or carrier-blind implementations. They do not test production contact publication, cut consumption or arrival seniority. The helpers remain unwired.

**Witnesses:** 66 sphere receipts preserve the transverse edge endpoint at P on (0,2), no slide tokens. O47 remains open. Both BunnyRandom receipts preserve slide entries for 43:11, 43:13 and 15:19; shared interval [X43, v94] on (94,210) with t43=0.26324148596788688, t15=0.93470265131543506. Earlier trace 43 is the prior bounded-arc-length result, not inferred from rounded parameters. Nodes 220/222 still claim trace82 at one exact position; Vase `AggregateCompletionValidationFailure` unchanged. H3 is the separately established latent untraced chord on departure segments, not the measured grazing slide defect. No new stable event.

## Recommendation — freeze the authorized successor only

`M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (Review definition). [RA-257 S5–S6](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md#ra-257--adversarial-re-review-of-this-review-2026-11-18-utc) owns scope. Define carrier-keyed slide-piece contact across both incident faces; apply the exact first shared parameter and existing arrival rule including inconclusive outcome. Falsifiers: different carrier or incompatible occurrence/region, disjoint intervals, opposite direction, isolated endpoint-only touch, absent prior wall, reversed or inconclusive seniority. No guessed cut, coordinate merge, guard relaxation, D12 change or production wiring during definition. Keep parallel sphere definition S5.1/S5.3–S5.4; H3 receipt before classifier switch, face-then-slide ordering and terminal/struck position, exact sphere entry occupancy equality. Each obligation has separate unwired and wiring CB/TB pairs (S5.5). Stop rather than silently change ownership or widen frozen criteria. No successor work in this review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/491 ordered prefix `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`; 30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, 12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, 449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. |
| Decisive claims independently re-derived | All four archive hashes, manifest identities, 956 row equivalences, receipt bytes, new test, package and exact frozen diff. |
| Non-vacuity checked | 11 independent comparator controls and source assertion audit above. |
| Prior obligations discharged/carried | RA-257 S4 discharged only. C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece witness open. H3 latent measurement first; O45 consumer proxy and C3/O44/C1 narrow closure retained. FC-6, terminal-cut, row858 held; CB145 parked. D11=A, D12=A, D10 deferred, D6 pending; chainRimSchedules=false. |
| Stable accounting | 66/17/49, debt 1, deferred 81; CP2 491/491 package 11391685901. CP3/selector497/D0 not promoted. |
| New candidates/obligations recorded | None; tracker current evidence updated. |
| ORIENTATION currency line | `M6-CP3-TB136-P13-CARRIER-OCCUPANCY-HELPERS-FULL-GATE-REV`, 2026-11-18. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §4 and §7 current evidence/priority updated. §8 unchanged: existing RA-257 and prior lessons cover this non-behavioral proof. |
| CHANGELOG | Independent review entry added. |
| ROADMAP | Current candidate updated; no checkpoint advancement. |
| Selector manifest | n/a: no accepted selector added or changed. |
| LESSONS | n/a: no new generalizable defect; RA-257 S7 and existing comparison lessons apply. |
| Consolidation under CLEAN_UP_POLICY | Inventory: TB136 execution and CB159 record current authority; TB135 gate/census and RA-257 current comparator and definition authority. Prior active contact/receipt records preserve live obligations and citations. No safe fold in this bounded Review; combined current tracker entry in place; no deletion or historical index claim. |
| Successor frozen | `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP`; scope, falsifiers and stop rules above. |
| Turn boundary held | Runtime-free; no product, test, fixture, selector, benchmark or build changes. |
| review_check.py boundary | Exit nonzero: historical rewrite base 8b7299b43 absent in source-only snapshot; four history-dependent checks fail. Product, selector and present-document checks pass; local exact preimage comparison retains headings. Historical check not claimed PASS. |
| STATUS lifecycle maintained | Entry IN_PROGRESS at 2026-11-18T07:56:04Z; previous EXEC COMPLETE. Final beacon is a separate last remote action; no successor start. |
| Pushed to origin, branch in sync | Web connector: validate patch application and remote branch postimages, then cleanup and final STATUS; no local clone/upstream to compare. Final verification recorded outside this patch. |

Procedure limitations: initial direct guidance reads preceded snapshot-mode selection; full mandatory policy reading was not confirmed at entry. Local timer used shell rather than Python. Source snapshot has no historical Git objects; boundary history checks cannot be certified from the synthetic local index. Tool ledger incomplete. No acceptance claim rests on these omissions.

## RA-258 — adversarial re-review of this Review (2026-11-18 UTC)

### S0 — verdict

MATCH upheld. Product source at HEAD equals CB159 (`git diff --quiet 18cc4a7d3e8ae43ce854c0edc834ab156156dcbf HEAD -- src include tests`). The archive hashes and row comparisons are taken from this Review and the EXEC report; RA-258 did not re-open the archives (runtime-free). The Review's non-vacuity claim for row 954 holds: each direction branch, the closed-interval endpoint and the carrier test have a case that fails if that part is wrong. Two defects follow.

### S1 — routing skipped the first Review-track item and left the implementation agent idle again

RA-257 S6 ordered the Review track as: EDGE-ENDPOINT-CONTACT (H3 receipt first, S5.1), then TB136-REV, then OPPOSING-TRACE-OVERLAP (S5.2). The Review jumped to S5.2 and restated "H3 measurement first" as prose with no frozen turn (RA-225: a prose-only next turn is either withdrawn or frozen). The H3 receipt needs no ownership decision, so it is implementation work that could run now. RA-258 freezes it (S3).

### S2 — H3 is wider than RA-257 stated, and the switch's whole effect is one predicate

- **Both loops, both sides.** The pending-vs-pending loop (`SurfaceCellTracing.cpp:4346`) calls the classifier with no exit override. The wall loop (:4414) overrides only a wall's terminal contact. So a *moving* departure proposal also contributes a recomputed chord, not only stored walls.
- **What the departure set is.** The segment records no dispatch flag, and `entryPoint` comes from `field_boundary_point_at_vertex` (some edge of the face through the vertex), while `edgeTransitEntry` is `{carrier, 0|1}`. The two are the same point under different edge keys. So the set is defined geometrically: the slide start's barycentric coordinates equal the entry's (a zero-length face piece).
- **Non-departure slides are unaffected by a switch.** For a slide entered mid-edge, the recomputation is the same call with the same face, branch and entry as the traced decision (:3577–3582 vs :3097), so it returns the stored `edgeTransitEntry` exactly.
- **The switch's consumer-visible delta.** Both consumers read only `ProperCrossing` (:4349, :4417). A zero-length first piece makes both `orient(a,a,·)` zero, so `ProperCrossing` is impossible. An `Unevaluated` that becomes `Disjoint` or `EndpointTouch` is discarded either way. Switching the classifier to the stored exit therefore changes exactly the `ProperCrossing`s that involve a departure segment, and nothing else. The receipt counts exactly those (RA-229: gate a switch on the consumer's own predicate).

### S3 — CB160 (frozen)

- **Patch.** `.agents/Directional/Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Exact.diff`, SHA-256 `d6b045aff9e489fd7428bd60de76a3e0e30935d5a14628c8059636fdc625823d`, 155 lines. Numstat: `6 0` `SurfaceCellTracing.h`, `50 0` `SurfaceCellTracing.cpp`, `48 0` `FieldAlignedCurveNetworkTests.cpp`.
- **What it adds.**
  - `surface_cell_tracing_detail::field_aligned_segment_departs_along_carrier(segment)`: true iff `edgeTransitEntry` is set and its barycentric coordinates in `sourceFace` equal the entry's.
  - One `std::clog` receipt, printed in both contact loops right after a `ProperCrossing` is found and only if either segment departs along its carrier: `FieldAlignedCurveNetwork.departureChordCrossing pending=<0|1> first=<trace>:<segment> second=<trace>:<segment> face=(a,b,c) departing=<first|second|both> secondExit=<recomputed|terminalContact>`. A proposal's segment index is `trace.segments.size()`. No control-flow or state change.
- **Unit test.** `FieldAlignedCarrierOccupancy.DepartureAlongCarrierMeansTheSlideStartsAtTheEntryPoint`. True cases: a vertex entered on edge (0,1) and left along carrier (0,2), which is the same point under two keys; the same at the carrier's second endpoint, entered on (1,2); and an equal interior point on the same key. False cases: a grazing slide entered mid-edge, a slide starting at the carrier's far end, an interior point 1/100 away, and no slide.
- **Checks.**
  - Precheck: `git diff --quiet 18cc4a7d3e8ae43ce854c0edc834ab156156dcbf HEAD -- src include tests`.
  - `git apply --check` passes.
  - `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` passes on both files, with warning counts unchanged from HEAD (43 and 42).
  - No test captures `std::clog`.
  - A Haiku read-only audit hand-evaluated every expectation (all PASS) and confirmed the patch is additive and behaviour-neutral. It also confirmed that index printing matches the queue events, that `wallTerminalContact` is in scope, that no test captures `std::clog`, and that a grazing slide cannot satisfy the predicate (an exit equal to the entry is rejected at :649–650). Its two notes are applied in the frozen diff: the header comment now states the coordinate comparison exactly, and there is a positive case at `carrier.second()`. The predicate deliberately does not require `edgeTransitEntry.edge == outgoingCarrier`, because it is geometric. Cost: exact barycentric conversion only on ProperCrossings.

### S4 — TB137 criteria (frozen)

- **Package.** CB160.
- **Gate manifest.** `gates/Architecture_M6_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Case_Manifest.tsv`, SHA-256 `46200a6042923619d6bb5d5216f62ff6ff1ec1944e2651b040bfabfa04dd9141`. It is the TB136 manifest `dac17a50…` byte for byte, plus row 955 (`ra258:departure-along-carrier-predicate`, the test above, `directional_surface_cell_producer_tests`, PASS). `SELF_CHECK_PASS cases=955 deferred=81`; membership 1,036.
- **Unchanged inputs.** Census `3af1dc0d…`, deferred `fd433f54…`, harness `78b8002c…`.
- **MATCH** requires all of the following:
  1. Gate rows 1–954 and the 3 census rows have the same ledger fields as TB136 (gate `14406791564`, census `14406826878`). Logs are equal under N1–N4 plus **N5**: delete lines that begin `FieldAlignedCurveNetwork.departureChordCrossing ` before comparing, and nothing else.
  2. Every other receipt, including ` slide=` and ` path=`, is byte-identical.
  3. Row 955 is PASS.
  4. Nothing else differs.
- **Measurement to report.** Per row and per census fixture:
  - the count of `departureChordCrossing` lines and the set of distinct lines;
  - the count of existing `FieldAlignedCurveNetwork.edgePortDeparture` lines, as the denominator of rows that depart at all.
- **No count is predicted.** The count is the unknown being measured. By construction each line names at least one departing segment.
- **Routes.** Mismatch: `M6-CP3-PLAN-P13-DEPARTURE-CHORD-RECEIPT-STOP`. Infrastructure: `M6-CP3-CB160A-P13-DEPARTURE-CHORD-RECEIPT-ORCH`.

### S5 — what TB137 decides

- **Zero lines gate-wide and in the census.** TB137-REV freezes CB161: `field_aligned_segment_exit_point` returns `edgeTransitEntry` when it is set. That switch is neutral on every measured row by S2. Before freezing it:
  - grep the accepted tests that call `classify_field_aligned_segment_contact` with slide segments (RA-217);
  - add a unit test that fails before the switch and passes after: a departure segment against a wall crossing its old chord.
  - TB138 is then an equality gate.
- **Any lines.** The phantom crossings were doing work on those rows. Do not switch alone: the Review reads the rows, and the switch ships together with the S5.2 slide-piece contact that replaces them, as one staged helpers-then-wiring pair.

### S6 — turn sequence

- **Implementation track:**
  1. `M6-CP3-CB160-P13-DEPARTURE-CHORD-CROSSING-RECEIPT` (compile only).
  2. `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-EXEC`.
  3. CB161 (switch) or the S5.2-coupled pair, per S5.
- **Review track** (parallel):
  1. `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (RA-257 S5.2, as this Review froze it).
  2. `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-REV`.
  3. `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT`, the remainder: S5.3 terminal-in-slide and cut ordering; S5.4 sphere entry-occupancy equality.
- **Held:** FC-6, TERMINAL-CUT-OUTCOME and row 858. **Parked:** CB145. D11=A and D12=A are unchanged.

### S7 — lessons

- When a definition step is "measure first", freeze the measuring turn in the Review that names it. Prose obligations get skipped when the next Review reorders the track.
- Before scoping a recomputation defect, check every call site's override arguments. Here the moving side recomputes too.
- Define an affected set by geometry when the record has no dispatch flag, and compare points by coordinates, not by edge key.
