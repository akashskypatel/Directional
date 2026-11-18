# TB137 P13 departure-chord crossing receipt — independent Review (MATCH)

## Situation

`M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-REV`. **MATCH upheld under RA-258 S4.** 957/957 prior rows MATCH; row 955 PASS; 68 other receipts byte-identical; zero departure-chord crossing lines and 48 edge-port departure lines (BunnyRandom only). The measured matrix does not depend on a phantom departure chord. This authorizes the S5 zero-line branch only. No product or test source was changed or executed in this Review. PR #8 remains draft, open and unmerged as specified by standing authority.

## Background — immutable authorities

- [Execution report](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Execution_Report_20261118.md), [CB160 compile record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md), [RA-258 S2–S6](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc).
- Entry beacon `981165f468f41d81ce6ea4a4d3f7eaaec6089406`; exact Review snapshot `669c3d9f9654c3b3c20585bfb33f2ab7dea66a11`, run `44288542552`, artifact `14419458612`, ZIP `cd5b776600012d40c8ca957e5bff836007d5dbc7152511585e2de9473c975316`; 5,558 checksum checks. Remote compare from CB160 source `66fb0c5ec42fa57614a504437724b18d7004cbb1` to snapshot: no product/test changes. Compare CB159 `18cc4a7d3e8ae43ce854c0edc834ab156156dcbf` to CB160: only product/test paths were the frozen +6/+50/+48 edits. Exact diff SHA-256 `d6b045aff9e489fd7428bd60de76a3e0e30935d5a14628c8059636fdc625823d`.
- Fresh CB160 package `14414860103` ZIP `8b2277e9e5ac2fc71ffe4e61a6012e5ac892f2a92c0f03b24613d695437aaec2`; 28/28 checksums, manifest `2946a306b0f9d6d655188d5fcaf2ad9f7433d2a075e96ee85d818b82639e0b1e`, source archive `30dc5fad7dfb3f9eaf097c62d4eff8a0125faecb958461c52a7eee36e9671911`; 569 source/test/fixture/gate/selector/tool/workflow files compared byte-for-byte (371 src/include/tests), zero differences. Six executable modes 0755, five empty source-status files, eight targets, compile/preflight exits 0, both GMP libraries on link line, runtimeExecution=false. No binary execution.

| Evidence | Artifact / run | ZIP SHA-256 |
|---|---|---|
| TB137 gate | 14418131624 / 44281340197 | `47465f4365cd9ce39769cecdef386f8402cde9abd97312f6060ecdfa50fcb346` |
| TB137 census | 14416913949 / 44281390798 | `edfdc965df3d8e99568f16ad6a4806800a31a89cb028fee6f0a9f7898e416f19` |
| TB136 gate | 14406791564 / 44256775123 | `1a1cccc01f86d1e1555ef896cb449dc42da8c0c30f8c41e6b2685c1e0b7045c8` |
| TB136 census | 14406826878 / 44256959318 | `f855a98e9c5a85d3afa21659f35f3ff8c6339b56a8965057f7b54164efd64ce3` |

The four retained raw archives match the listed SHA-256 values. Candidate gate and census, including their four log archives, match fresh mailbox authority. Comparator hashes match the prior independent record. Candidate event commits `6eb87284f2aef7cb53e9d9e7440de31152514f94` / `9c15ecec7045b6074c4fe95e45cd8acd13cece15`, runtime jobs `134722865400` / `134728938476`. Reused verified closeout bytes instead of duplicate downloads. Gate, census, deferred and harness SHA-256 values match the compile record: `46200a6042923619d6bb5d5216f62ff6ff1ec1944e2651b040bfabfa04dd9141`, `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Gate is TB136 manifest `dac17a50bccea4999a5482620793bffe42de61d585d69d53724ae0d59055ebc2` plus only row 955.

## Assessment — independent derivation

Fresh read-only Python parser independently verified ZIP contents, coverage and 3,852 internal checksums (TB136 1,916 + 9, TB137 1,918 + 9), raw bindings, exact identities, member states and GoogleTest outcomes. It compares all ledger fields except log hashes (whose raw bindings it separately verifies). It normalizes only N1 GoogleTest elapsed times, N2 CRLF, N3 complete region-record framing/order with all numeric/Boolean fields retained, and N4 census opaque parameter bytes. N5 deletion is unnecessary because there are zero lines with its prefix; the independent comparison retains even that prefix. All 11 offline comparator controls pass, including changed/lost receipts and records, strict crossing-line retention, elapsed time, framing and scope of opaque bytes. The 1,738 complete M3 diagnostic records and all 68 prior receipts are equal. Independent count table equals all 958 published entries. Zero distinct crossing lines.

| Scope | Candidate | Old-row match | Crossing receipts | Departure receipts |
|---|---:|---:|---:|---:|
| Gate | 954 PASS / 1 permitted RED | 954/954 | 0 | 0 |
| Cylinder census | PASS / 288 quads | 1/1 | 0 | 0 |
| BunnyRandom census | RED | 1/1 | 0 | 48 |
| Vase census | RED | 1/1 | 0 | 0 |

Membership 1,036 (955 gated + 81 deferred); old membership 1,035 plus exactly row 955. Gate exit 90 and census exit 0 unchanged; both postflight valid. Row 858 remains the permitted sphere premise RED at `SurfaceCellTracingDisplayTests.cpp:155`; row 648 assertions unreached. Accepted prefix 491/491 and ordered selector bytes: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; joined name prefix `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`. No accepted test directly calls `classify_field_aligned_segment_contact` (`rg` over all tests: zero exact symbol matches). The independent barycentric predicate test is not an assertion on the old representation. RA-217 grep obligation discharged; keep all accepted tests unchanged.

**Non-vacuity and causal limit.** CB160 receipt is in both consumers after `ProperCrossing` plus a valid intersection test and before arrival calculation; departure predicate checks coordinates, not edge keys. Source `SurfaceCellTracing.cpp:3087–3140` recomputes an exit except for the wall terminal override; both loops at :4376–4387 and :4449–4462 discard all non-ProperCrossing results. Row 955 asserts positive and negative cases of the geometric departure predicate, including different edge keys. A wall terminal override may make a counted second-departure line conservative rather than an actual changed chord; zero lines still excludes all measured relevant old ProperCrossings. A mid-edge slide's recorded start equals the producer's exact exit; a departure's first piece has identical start and end and cannot pass the strict orientation predicate. This establishes the predicted consumer delta for valid traced segments, not a universal no-contact proof. In particular, slides still need separate contact classification, and arrival/cut or terminal-override behavior is not broadened.

## Recommendation — frozen successor

**Exactly next: `M6-CP3-CB161-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH` (Code + Build, compile only).** First verify current src/include/tests equal CB160 authority, and freeze inputs. Apply [exact diff](Architecture_M6_CP3_CB161_P13_Departure_Chord_Classifier_Switch_Exact.diff), SHA-256 `133a940200872ad956da25faae135b9f25b956986eba064134dfe493a7983095`, 86 lines, +1 implementation / +66 test, no deletions. The file is a Review specification, not an applied code change. Forward/reverse patch checks and whitespace check passed on exact scratch preimages. No product compile or test execution in Review.

- `field_aligned_segment_exit_point` must return `segment.edgeTransitEntry` if present; otherwise retain the current recomputation. Shared helper serves both pending and wall loops; preserve wall terminal override and receipt. Do not change contact scheduling, occupancy helpers, arrival/cut, identity, digest, validators, test expectations, selectors, fallback, or other code.
- New test `FieldAlignedCarrierOccupancy.DepartureSlideHasNoInteriorChordContact` uses the existing planar square and radial-arrival field, face (0,1,2). Gauge branches 1 and 0 have world directions (-1,1,0) and (1,1,0); in this face their derivatives are (1,-2,1) and (-1,0,1). Ordinary ray (0,1,0)→(1/2,0,1/2) crosses wall (1/2,1/2,0)→(0,1/2,1/2) at (1/4,1/2,1/4). The departure's actual face piece (0,1,0)→(0,1,0) is Disjoint against that wall in both argument orders, with no contact point. For grazing control, (1/4,3/4,0)→(5/8,0,3/8) intersects at (3/8,1/2,1/8). Independent exact rational orientation arithmetic verifies these assertions. Old classifier ignores stored entry, so the departure calls would produce the ordinary crossing and fail the new assertions; new code must pass the departure, ordinary and grazing controls. This fail-before/pass-after prediction is static, not an executed test result. The CB must stop if atlas/branch preconditions or exact patch authority are false; do not weaken assertions. Run compile only using eight RA-245 targets and GMP; no runtime in CB161.
- After CB161 formal completion, `M6-CP3-TB138-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-FULL-GATE-EXEC` is a separate immutable artifact-only equality gate, then independent Review. [Frozen manifest](gates/Architecture_M6_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Case_Manifest.tsv) SHA-256 `95e61be9132e159a5c3f041a20b875aed4d55ea5cf7bade0c93e07b329a6641a`: exact TB137 bytes plus row 956 (PASS), membership 1,037 (81 deferred). Census/deferred/harness unchanged. Before running, verify exact CB161 package and source authority. MATCH requires all 955 existing gate rows and 3 census rows (958/958) to match TB137 gate 14418131624 and census 14416913949 in all ledger fields and logs under N1–N4 only; zero crossing lines, exact per-row departure counts, all 68 other receipts byte-identical, accepted 491/491, unchanged row 858/648 and census outcomes, row 956 PASS. Gate 955/956 with one permitted RED, census 1/3 with two preserved REDs, no membership loss, valid postflight, same exit codes. No N5 removal on this equality gate; an added crossing line is a mismatch. If any deviation, freeze `M6-CP3-PLAN-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-STOP` for Review; infrastructure failure route `M6-CP3-CB161A-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-ORCH`. Do not repair the artifact or alter gate in TB138. H3 closure only after independent verification of TB138 and focused test.

Parallel Review track remains `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (RA-257 S5.2), then edge-endpoint contact remainder S5.3/S5.4. Do not combine these definitions or a second behavior change with CB161. C5/O47 sphere transverse edge endpoint and O48 BunnyRandom [X43,v94] on (94,210) remain open. C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece witness carried; H3 switch now frozen. C3/O44/C1 and O45 consumer proxy narrow closure retained. FC-6, terminal-cut, row858 held; CB145 parked. D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false. Stable 66/17/49, debt 1, deferred 81; CP2 491/491 package 11391685901. No CP3/selector497/D0 promotion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/491; three exact selector byte segments and joined hash above. |
| Decisive claims independently re-derived | 3,852 artifact checksums, exact inputs, package, source comparison, 957 rows, row 955, receipt bytes and 958-row count table. |
| Non-vacuity checked | 11 comparator controls, source predicates and independent exact geometry above. |
| Prior obligations discharged/carried | RA-258 S4 and RA-217 grep discharged; S5 branch frozen; all remaining obligations named above. |
| Stable accounting | 66/17/49, debt 1, deferred 81; CP2 491/491; no promotion. |
| New candidates/obligations recorded | No new regression; existing H3 owner is CB161 then TB138. |
| ORIENTATION currency line | `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-REV`, 2026-11-18. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §4 and §7 updated in place; §8 no new pattern beyond existing RA-217/RA-258. |
| CHANGELOG | Independent review entry added. |
| ROADMAP | Current measured authority updated; no advancement. |
| Selector manifest | n/a: no accepted selector changed. New prospective gate only. |
| LESSONS | No new pattern; RA-217 and existing comparison lessons apply. |
| Consolidation under CLEAN_UP_POLICY | Current CB160/TB137 and TB136 RA-258 records, TB135 onset authority and active definitions retain direct normative/evidence links; none safely superseded by this narrow Review. No deletion. |
| Successor frozen | `M6-CP3-CB161-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH`, exact diff and falsifiers above. |
| Turn boundary held | Runtime-free; no product/test/fixture/build/benchmark or accepted selector mutation. |
| review_check.py boundary | Synthetic snapshot has no history base 8b7299b43; history-dependent checks unavailable. Product, selector and present-document checks and direct preimage preservation checked locally. |
| STATUS lifecycle maintained | Entry IN_PROGRESS 2026-11-18T10:45:41Z; previous EXEC COMPLETE. Final beacon is separate last remote action. |
| Pushed to origin, branch in sync | Web connector: verify patch apply and remote postimages, cleanup and final beacon; no local clone or upstream to compare. |

Procedure qualifications: initial direct guidance reads preceded explicit snapshot-mode selection; timer used shell, and full mandatory start-policy reading and exact tool ledger are not confirmed. Source-only snapshot cannot certify historical base checks; local Git index is synthetic. Drift audit: zero errors, three expected protected landing-document update warnings (handoff, orientation, roadmap), scope authorized by requested Review and mandatory policy. Exact durable headings preserved against snapshot. These limitations do not change the independent archived evidence. No claim of successor implementation or execution.
