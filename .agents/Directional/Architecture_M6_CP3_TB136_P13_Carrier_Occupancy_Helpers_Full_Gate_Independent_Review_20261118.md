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
