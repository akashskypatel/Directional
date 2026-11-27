# TB-EXEC-192 — Singularity arrival classification execution (2026-11-27 UTC)

## Situation

The frozen 1010-row gate on CB-216 passed in one execution. All predicted row858 sphere arrivals match. The result awaits independent `M6-CP3-TB-REV-192` adjudication. The classifier does not remove traces, activate the schedule or establish production output.

## Background — exact authority

- [Frozen manifest](gates/Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Exact_Manifest.md) and [CB-216 compile record](Architecture_M6_CP3_CB216_P13_Singularity_Arrival_Classification_Code_Build_Record_20261127.md). Candidate `15192246171`, source and executor `c76e74b35ffa5ba6aa1f3f8662f592e077c63033`, compile run `45986095420`. ZIP SHA-256 `e92edf8686722ac4ec96dc07217e7a13923d8786cf89dc6d513793aac381b004`, root manifest `1e8f16fbf6a38e06c95fc5a1b6268919c9d081e5eb803a0b0ee01bb0939352cf`, source archive `d8cdcf38a1886bb0ed494d958e7f52f04c4aa22ceca25da791135befae5c5ce4`. All 28 checks pass. Six binaries retain executable modes. Five source status files are empty. Compile receipt identifies GMP (GNU Multiple Precision Arithmetic Library) and GMPXX (its C++ interface), with both libraries on the link command. `runtimeExecution=false` for the compile package.
- Unchanged harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Full manifest `c9f6325eee41ebead3d516d3bfcbef3141c9dee8c7051cef1e08ad146f60e9f5`, header plus 1008 rows `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081`, plus 1006 rows `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`, CP2 header plus 491 rows `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. Deferred ledger (81) `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Harness, manifest and ledger bytes match the candidate source archive and snapshot.
- [Run 45992751511](https://github.com/akashskypatel/Directional/actions/runs/45992751511), runtime job `140484678308`, attempt 1. Request event `8f4536c91143779e94204d068acb6ca80a592022`, request hash `0c10505f6f03bac48e45f08bd6c1bd252f0c9e34676269e98e02b9b23ce91403`, key `m6-cp3-tb192-exec` on `workflow-mailbox`. Source, event and request match the mailbox and wrapper. Both schema validators, parse, runtime and mailbox succeeded. Compile, drive_apply and noop skipped. Wrapper 11:43:41–11:59:54 UTC (973 s), exit0.
- Snapshot run `45992439434`, job `140483470308`, artifact `15194516505`, ZIP `cde69631bf3f4109aa7da72606ef31e2521aadc57878db593184674bb59daf29`, source `bd0e845e9c08f09ddfe0416fb7e514da66ad9c02`, archive `f187fdb8f302588f48540d65a4309a9cf1275038776bc062c75ec54a2372d6fe`. Prior attempt verified 5889/5889. This continuation reuses the snapshot. Compare to resume head `b28bac2870089f27a03166eade1d45ce5ddbc565` shows only STATUS, request, removal of the consumed marker, and addition of the continuation record. The four documentation preimages match their snapshot checksums. Marker removal commit `147ec793322d9adf883311d63acf080bc804b9f7`. [Continuation record](Architecture_M6_CP3_TB192_Singularity_Arrival_Execution_Continuation_20261127.md) is now historical. This report supersedes its pending execution instructions.

## Assessment — execution and comparison

| Artifact | ID | ZIP SHA-256 |
|---|---|---|
| Result | 15195820651 | `37bd0d7c8ba3abe1f3f1c74c0140903b9e880bf537e38982111621c472aea0ce` |
| Harness log | 15194799175 | `9a96a2705892e822165dc1bc8cfe58462aa9b1fdfbc1786ac5542709632bc4c4` |
| Wrapper log | 15195358020 | `ec07923655ae8f73a09e436111b7eaa17661cf2dcb90f043a47d6dc4fa8e09eb` |
| TB191 reference | 15179335926 | `bab546af9cc089db9deb405ede41b3dd859b9e4547f81507d669c58c911bb519` |

All five ZIP hashes (including candidate) match. The result has 2028/2028 checks and the reference 2024/2024. Each checksum manifest covers its full file set except itself. Membership is exactly 1091 = 1010 gated + 81 deferred across five binaries. The two new GUARD identities are the only additions to TB191 membership. Membership SHA-256 `7471f3b905e659c4be21d854fbf8094d33d3444058e6275210a572fc18d810cf`, ledger `fb34fbe02df49c37df854a2aeef3521345d1cf23e1496a5b38c418e1a37af472`, boundary `946c55245ee67ee773357c2293d7a8e4ad854dd7d81c7b75a4c9adf19dfd4a46`, result checksum manifest `ebc0a96fad617274ec753deaf3dd89041eb9f7d4c58f3ccc0fa3aecee2d5f572`. All 1010 ordered case identities, raw log hashes, single-test RUN/OK envelopes, resource command identities and exits, and ordered harness receipts match. The gate has 1000 GUARD and 10 POSITIVE cases. CP2 is 491/491. Zero RED, abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red or red_site_bad. Postflight true, exit0. Configure, compile, relink and benchmark false.

All inherited non-hash ledger fields match TB191. Of 1007 inherited rows other than 858, 770 match byte-for-byte and 237 match after N1/N2 (GoogleTest timing fields and CRLF conversion). There are no other differences. N3 (complete fragment record ordering) is unnecessary. The normalizer preserves unrelated diagnostic numbers and test identities. Its elapsed-time, line-ending, changed diagnostic number and changed test identity controls pass. All 13 named controls and rows 1003, 1007 and 1008 match. Rows 1005, 1007 and 1008 match exactly. The remaining named controls and row1003 match under N1/N2. The initial local file-coverage check did not account for `./` prefixes in the candidate manifest. The checker now compares canonical relative paths. All checksum, membership and comparison checks then pass without changes to evidence, tests or expectations.

Row858 exact TB191 prefix: 78276 bytes through `GenusRegionBoundarySchedules …`, SHA-256 `aa702e385156ccec02bd52de7fa936f40342d1d474aaf3bcc3241beaa09a9888`. Added 12 lines SHA-256 `04511fa7e6ab0a532e8b470033acee5122db736f0162d21ac076410fa2a94344`. The remaining suffix matches under N1/N2. TB191 raw `2a0611f283c8ab32c6356fdbb8d7a593f182222125d022e1d2cc5a64e43b5540`, TB192 raw `d4f1e4836a1743d96d605d47ced36c549316d51ec4a9df7daeb694f82fc09914`. Row858 PASS, exit0, GoogleTest 9.196 s. Its previous negative production and fallback evidence remains unchanged.

### Row858 — verbatim added records

```text
SphereSingularityArrivals classified=1 arrivals=10 radialEdge=10 faceInterior=0 matched=10 portTraced=10
SphereSingularityArrival trace=0 node=1 approach=radial-edge edge=6-8 port=4 portTraced=1
SphereSingularityArrival trace=1 node=2 approach=radial-edge edge=16-21 port=6 portTraced=1
SphereSingularityArrival trace=9 node=1 approach=radial-edge edge=8-9 port=3 portTraced=1
SphereSingularityArrival trace=10 node=7 approach=radial-edge edge=49-62 port=23 portTraced=1
SphereSingularityArrival trace=11 node=2 approach=radial-edge edge=20-21 port=7 portTraced=1
SphereSingularityArrival trace=12 node=6 approach=radial-edge edge=40-45 port=19 portTraced=1
SphereSingularityArrival trace=13 node=5 approach=radial-edge edge=32-34 port=15 portTraced=1
SphereSingularityArrival trace=14 node=0 approach=radial-edge edge=0-69 port=2 portTraced=1
SphereSingularityArrival trace=21 node=5 approach=radial-edge edge=33-34 port=16 portTraced=1
SphereSingularityArrival trace=22 node=6 approach=radial-edge edge=45-46 port=18 portTraced=1
GenusSingularityArrivals classified=1 arrivals=0 radialEdge=0 faceInterior=0 matched=0 portTraced=0
```

Every arrival has the predicted trace, node and edge, a port in its predicted range and `portTraced=1`. At each node with two arrivals, the ports differ. The genus_two witness reports zero arrivals. It does not establish a positive genus arrival match. Both new mechanical tests pass:

| Row | Test | Raw log SHA-256 |
|---|---|---|
| 1009 | `FieldTransportAtlas.MechanicalSingularityRaysLieOnRadialEdgesAndNameTheirPortSlot` | `8a035d4d1adbb3b101231f45975271bd0011ab5df2a4aef5883a3a2389d5c8c2` |
| 1010 | `FieldAlignedCurveNetwork.MechanicalRetraceArrivalsRealizeTheRemovedPortsSeparatrix` | `848f023adf22e16b4e389022e25cc8fbc62f2d476102f6af2ead72b6b023960e` |

### Regression disposition

No new accepted-green loss or unexpected raw difference. Stable 67 events / 17 categories / 50 recurrences, debt1/deferred81. O51 stays open and non-stable. The diagnostic measures the ten partial co-traces predicted by the A2a arrival DEFN. The source-level cause is the lack of recognition of the full separatrix class in the earlier arrival contract. CB-215 publishes all rays and CB-216 measures arrival matches, but no stage consumes the classifier and neither change removes the extra traces. The removal rule AP4 requires the later user decision. This gate does not prove removal, a topology correction, or production. The mechanical guard checks D13 exact retrace ownership for four already removed port traces. It is not proof of partial co-trace removal. O50 remains open. B1 held, and B2 unmeasured because V5 did not run. No promotion of CP3/497/D0/H4. Last independently accepted test gate remains TB-REV-191 1008/1008 and CP2 491/491.

## Recommendation — TB-REV-192 only

Independently reopen the immutable CB-216 candidate, TB192 result and TB191 comparator. Recompute membership, all verdicts, the N1–N3 comparison, exact row858 prefix, twelve new records and the frozen row858 predictions. Review the two new tests against their frozen contracts. Check the O51 interpretation without claiming trace removal or production. If accepted, the behaviour DEFN (AP4 user decision) follows, then the corners DEFN under repository authority. No runtime, rebuild, retry, V5, product/test/fixture change, B1/fallback repair, A2b/A3 or dispatch/veto change, CB-207D or checkpoint promotion.

Process limits: the first attempt read documents before verified snapshot acquisition. The continuation reuses the verified snapshot after commit comparison. The initial policy read order and full mandatory preliminary policy and LESSONS review are not established for the whole turn. The external turn-based coding skill was inaccessible in the preceding session. Historical tool-call accounting is partial/unknown. No successor work or local Directional execution occurred. The local comparison is execution verification, not independent review acceptance.

Static documentation audit: zero errors. The unchanged ORIENTATION.md size warning predates this turn. The handoff protected-change warning is expected for the required in-place turn closeout. The durable headings and all policy sections remain intact. No protected policy, design or frozen selector changed. The next Review owns ORIENTATION currency and document consolidation.
