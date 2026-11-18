# TB138 P13 departure-chord classifier switch — independent review (MATCH)

## Situation

`M6-CP3-TB138-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-FULL-GATE-REV` — 2026-11-18 UTC. **MATCH upheld; H3 closed narrowly.** 958/958 prior rows match, new row 956 PASS. This is independent review of archived evidence, not a second product execution or CP3 acceptance. PR #8 remains draft, open and unmerged. The repository entered this review from the completed EXEC beacon; no successor work was started.

## Background — authority

[TB138 execution](Architecture_M6_CP3_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Execution_Report_20261118.md), [TB137 execution comparator](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb137_p13_departure_chord_crossing_receipt_full_gate_execution_report_20261118md), [TB137 Review / RA-259](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md), [CB161 compile record](Architecture_M6_CP3_CB161_P13_Departure_Chord_Classifier_Switch_Code_Build_Record_20261118.md).

- CB161 source and executor `f14761715004d7ddc27e032698f6540ae1a9b0c4`; package `14424780973`, ZIP SHA-256 `b55fa59e6c93abd4d40adde92547b309998e03803a3dc95db37feb254346c058`; manifest `e6f5d899229039e3bc12e3435ee96ef03157db457590c8a3b72696424612dc06`, source archive `e3f65c11d1eb26cdef0710a67ad062561260fdd27baa58bf168958df8996b547`. The archived runtime boundary and logs bind that package; this review did not re-download or execute its binaries. CB160 comparator source `66fb0c5ec42fa57614a504437724b18d7004cbb1`, package `14414860103`.
- Fresh snapshot `2af995a8d6fb4adcb885dc8b7d50114ccb038dab`, run `44306912837`, job `134810916572`, artifact `14429155829`; ZIP `9941e61bbcee56516d917e492d504b6bad55c6a8e62125082c82670a3c9fee6f`, inner archive `466fb84db5b1f8ddcba9c2e371bce7c3cd3b261674406c16981720d35560c284`; all 5,567 file checksums passed. GitHub comparison from CB161 to snapshot lists only documentation and control-plane paths. The CB160-to-CB161 source delta is +1 implementation and +66 test lines; the exact frozen diff hashes to `133a940200872ad956da25faae135b9f25b956986eba064134dfe493a7983095` and reverse applicability passes against the snapshot. No source drift.
- Frozen inputs: gate `95e61be9132e159a5c3f041a20b875aed4d55ea5cf7bade0c93e07b329a6641a`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Prior gate rows are retained and one focused row is appended.

| Result archive | Artifact | Verified ZIP SHA-256 |
|---|---:|---|
| TB137 gate | 14418131624 | `47465f4365cd9ce39769cecdef386f8402cde9abd97312f6060ecdfa50fcb346` |
| TB137 census | 14416913949 | `edfdc965df3d8e99568f16ad6a4806800a31a89cb028fee6f0a9f7898e416f19` |
| TB138 gate | 14425931505 | `884cadd19104322d764c87690e53827391806ca3d56765433f7bdb7e5cf8859e` |
| TB138 census | 14425229608 | `c7b9001a718b827ad8d910e511a1e44f3618df13de44e3623097edba716e619b` |

These are the raw result and log ZIPs preserved in `Directional_TB138_verified_closeout_20261118.zip` in the user's File Library. The archive manifest passed. The TB138 live mailbox records bind gate run `44299742312` (event `4ad2ef87d2bc153e102c31c69df7046e572feab8`) and census run `44299795875` (event `79db639b60d3a6cc195b0f37089f6a5e50fb8516`) to CB161 source, the result IDs above, and harness/reusable log IDs `14426790075`/`14425427360` and `14427055668`/`14427115482`. All four archived candidate log ZIP digests equal the mailbox digests. The comparator ZIP digests equal the previously reviewed TB137 authority. Execution logs and IDs belong to the owning execution reports.

## Assessment — independent derivation

A new read-only parser, `independent_tb138.py`, reopened all four raw result ZIPs, checked complete checksum and case membership coverage (1,927 baseline + 1,929 candidate = 3,856 checks), verified each raw log hash against its ledger, and compared ledger fields and logs independently of the execution comparator. Normalization is limited to N1 GoogleTest elapsed times, N2 CRLF, N3 complete M3 record multiset/framing, and N4 census opaque parameter-object presentation bytes. It retains full diagnostic records and all receipt bytes. No N5 removal. Six independent comparator controls test changed/lost receipts, an added crossing line, CRLF, elapsed time and other payload. All pass. They are parser controls, not product tests. The 1,738 complete M3 region records match. All 959 data rows of the [published measurement table](evidence/Architecture_M6_CP3_TB138_P13_Departure_Chord_Classifier_Switch_Counts_20261118.tsv) match the independent counts; SHA-256 `4aa9876fb42339b8f70ef25271319a15fe581995d0285fc6b0867359f43acd9a`.

| Evidence | Gate | Census | Total |
|---|---:|---:|---:|
| Prior rows equal | 955/955 | 3/3 | 958/958 |
| New row PASS | 1 | 0 | 1 |
| Unchanged other receipts | 66 | 2 | 68 |
| Departure lines (unchanged) | 0 | 48 | 48 |
| Departure-chord crossing lines | 0 | 0 | 0 |

956 gate cases executed; 955 PASS, one permitted RED (row 858 `apicensus:19`, `SurfaceCellTracingDisplayTests.cpp:155`). Row 648 sphere assertions remain unreached. No missing, duplicate, skipped case, abnormal exit, unexpected pass, later positive RED or wrong RED site. Membership 1,037 = 956 gated + 81 deferred. Gate exit 90, `control_bad=1`; census exit 0 and both postflight valid. The gate failure is the frozen semantic RED, not infrastructure failure. Census: Cylinder PASS/288; BunnyRandom RED (trace 82 contact-cut conflict, nodes 220/222); Vase RED (`AggregateCompletionValidationFailure`). No production outcome changed.

Accepted CP2 prefix 491/491, package `11391685901`; each name in exact order matches its recorded PASS. Selector SHA-256: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; joined newline-terminated sequence `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`.

### Non-vacuity and H3 scope

The exact CB161 change at `src/geometry/SurfaceCellTracing.cpp:3090` returns `edgeTransitEntry` when present instead of recomputing an exit. The same routine supplies both segment arguments to the classifier, except the deliberately supplied second terminal exit override. Ordinary segments retain the existing branch continuation. A departure starts on a vertex under two different edge keys; entry and slide start identify the same barycentric point. Its face piece has zero length. The prior recomputation tests a face chord that does not exist. For mid-edge grazing, the recorded start of the slide retains the nonzero traced face piece. The new test `FieldAlignedCarrierOccupancy.DepartureSlideHasNoInteriorChordContact` at `tests/FieldAlignedCurveNetworkTests.cpp:19050` ran as row 956 and passed. Independently calculated with exact fractions: ordinary chord intersects the wall at barycentric `(1/4,1/2,1/4)`; the departure face piece is one point outside the wall (Disjoint in both orders, no contact barycentrics); grazing retains the crossing `(3/8,1/2,1/8)`. The old code ignores the recorded entry and would return the ordinary crossing for the departure, so the new assertions are not vacuous. This fail-before claim is a static prediction, not a second executed result. RA-259 S2.1 is correct: zero crossing receipts follow by construction after the switch and are not an independent proof. The new focused test plus strict equality is decisive.

**Close H3 only** (phantom *face* chord for carrier departure). Do not close omitted carrier-slide contacts or claim that the classifier now handles the slide locus. The CB160 receipt is now unreachable; delete it only in the separately frozen wiring CB. C5/O47 sphere traces 4/6 cross at P on (0,2); O48 BunnyRandom traces 43/15 overlap [X43,v94] on (94,210), trace 43 arrived first, and trace 15 should end at X43 (parameter 0.26324148596788688). Neither is fixed by CB161. RA-259 S3 owns edge-keyed entry/slide contact and arrival order; S5.3 must still define its contact-event, terminal record and `TraceCutPosition` representation. No coordinate merge, guessed cut or guard relaxation. Carry C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4, middle-piece direction witness. Retain C3/O44/C1 and O45 consumer-proxy narrow closures. FC-6, terminal-cut and row858 held; CB145 parked. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. Stable 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. No new event or candidate. CP3 selector497 remains frozen, not promoted; no D0 claim.

## Recommendation — one bounded successor

Exact next: `M6-CP3-CB162-P13-SLIDE-ARRIVAL-HELPER`, compile only. [RA-259 S4](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md#s4--cb162-and-cb163-frozen-unwired) defines the helper and its controls. Frozen diff `Architecture_M6_CP3_CB162_P13_Slide_Arrival_Helper_Exact.diff` SHA-256 `1a3cbb1a74dd4d071e29006b49f379b3af053a3fcc71f17609d2612c5efcb853`, 139 lines, +12/+32/+65. Verify exact CB160+CB161 product preimage. Add only unwired `field_aligned_arrival_at_slide_parameter` and focused test, preserving producer operation order and reproducing segment end arrival, rejecting outside-slide/no-slide, supporting reversed departure and one segment-count increment. Compile eight RA-245 GMP/GMPXX targets, no Directional runtime. Stop on preimage, hash, unexpected source or assertion/semantic mismatch (`M6-CP3-PLAN-P13-SLIDE-CONTACT-HELPERS-STOP`); infrastructure route `M6-CP3-CB162A-P13-SLIDE-CONTACT-HELPERS-ORCH`. Do not weaken tests. CB163 hash `3a7f96f20eb9f9f6d8af825b7649d7bd603baa5b4007a639ceb60f9a918e67a8` and TB139 manifest `96766f760965c01216cbe94f92f67eefcfc40bf78e17dbcd5379bee7556f2d29` verified unchanged; neither is the current turn. No wiring or runtime was authorized here.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 exact names and PASS outcomes; three file hashes and concatenated hash above. |
| Decisive claims independently re-derived | 3,856 archive checksums; 958 rows and 959 count-table rows, receipt and region bytes, source delta and focused geometry. |
| Non-vacuity checked | Six comparison controls and exact ordinary/departure/grazing rational derivation; static fail-before prediction, actual row 956 PASS. |
| Prior obligations discharged/carried | H3 narrow closure; all remaining obligations and prohibitions above. |
| Stable accounting | 66/17/49; debt 1; deferred 81; accepted CP2 package 11391685901, 491/491. |
| New candidates/obligations recorded | None new; existing H3 closure and O47/O48 ownership recorded in tracker. |
| ORIENTATION currency line | TB138 independent Review, 2026-11-18. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §4 and §7 updated in place; §8 unchanged, no new recurring pattern beyond RA-259. |
| CHANGELOG | Independent review entry added. |
| ROADMAP | Current measured authority updated; milestone unchanged. |
| Selector manifest | n/a: no selector added or accepted. |
| LESSONS | No new lesson; existing exact comparison and RA-259 S2.1 non-vacuity rule apply. |
| Consolidation under CLEAN_UP_POLICY | Historical TB137 execution report (64 lines) preserved verbatim in Volume D3, indexed by name/hash, living links repaired. TB137 Review/RA-259 retains normative helper and contact definitions. Other old records with active evidence or normative links retained. Remote comparison shows no other document removed since CB161. |
| Successor frozen | CB162 only; exact bytes, acceptance and stop routes above and in RA-259 S4. |
| Turn boundary held | Runtime-free; no mutation of product/test/fixture/benchmark/build/selector inputs. |
| review_check.py boundary | Local source-only snapshot has no actual rewrite-base Git history; history-dependent checks fail. Product and selector checks pass; compare protected headings to verified preimage, audit links and use remote commit comparison for authority. |
| `STATUS` lifecycle maintained | Entry 2026-11-18T12:44:18Z, IN_PROGRESS (previous EXEC COMPLETE). No prior review start exists in repository beacon. Final direct beacon contingent on verified publication and cleanup. |
| Pushed to origin, branch in sync | Web connector: verify applied commit, changed paths and branch head via remote readback; `git status -sb` against actual origin is unavailable in source-only snapshot. No self-referential commit claim. |

Procedure qualifications: initial source guidance reads preceded snapshot-mode selection and entry beacon; the first repository mutation was the entry beacon. Shell timer start followed startup by approximately one minute; bounded turn deadline is based on initial request, not timer start. Exact tool-call ledger and full mandatory start-policy review are not confirmed. The source-only snapshot cannot prove the historical rewrite-base checks from local Git; the local index is synthetic. No successor product work was started. These procedure gaps do not change the raw evidence comparison.
