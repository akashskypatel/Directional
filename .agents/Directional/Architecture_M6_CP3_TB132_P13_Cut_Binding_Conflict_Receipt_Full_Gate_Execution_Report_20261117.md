# TB132 — cut-binding conflict receipt full gate (2026-11-17 UTC)

## Situation

Execution verdict: **MATCH** under [RA-253 S7](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Independent_Review_20261117.md#ra-253--adversarial-re-review-of-this-review-2026-11-17-utc). Gate: 952/953 PASS; one permitted premise RED at row 858. Census: one PASS and two RED observations. All 956 substantive ledger records and normalized raw logs match TB131. The new receipts confirm both frozen rejection-site predictions. This is a diagnostic-only execution result, not acceptance of CP3, final geometry, or O45.

## Background and execution authority

- Turn `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-EXEC`. Branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft/unmerged. [CB155 compile record](Architecture_M6_CP3_CB155_P13_Cut_Binding_Conflict_Receipt_Code_Build_Record_20261117.md) governs the immutable inputs.
- Source and executor `cce5be20ea7237f59f3c0acca25a4ba57813644e`, package `14357189158`, ZIP SHA-256 `1fe10a511db165b3f4d3d06b8002b0d8241a237ef81d789e3cb5e1676650da4e`. Root manifest `cc58b4dbdd49c3e2c2ad52093b03980dc078f77ed8ef0d11d3b23c2a83fb109b`; source archive `212b528e50c55a1867b6932757b1d200c97daca3dc11e8156cc24bfad3d94f59`. Prior attempt verified 28 checksums, six executable modes and 371/371 source/include/test file bytes. The exact repository snapshot `33c642310417b11e78ff7e34cdc79cc356b44736` (run `44153482535`, artifact `14359338221`) passed 5,535 checks. The checkout's later changes concern only control state and documentation. No rebuild, relink, repair, fixture, test, manifest, selector, harness or workflow edit. No benchmark execution. No local project binary execution.
- Inputs: gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Census omits deferred ledger. Comparator TB131 gate `14349985217`, census `14349666706`, source `452eb3d789016e744e99d88811add0f7e0949165`, package `14347130681`.

| Work | Dispatcher event SHA / request SHA-256 | Run / runtime job | Mailbox key (attempt 1) |
|---|---|---|---|
| Gate | `c60080ced2fac0edba53b5f61a79f7beb5d7e7b1` / `c519348cedaed84d819876ea75ab124f9c0984aa57ad97079262819c62871f7c` | [44153912407](https://github.com/akashskypatel/Directional/actions/runs/44153912407) / `134289803203` | `m6-cp3-tb132-gate-v1` |
| Census | `0665076037611aec0f21ee23027a6f487eb85edf` / `ec8c06f8bc9623aecb3f16ce4725a5ac3aad8cff6484fece4644dbc808c5aa0e` | [44153980062](https://github.com/akashskypatel/Directional/actions/runs/44153980062) / `134298593330` | `m6-cp3-tb132-census-v1` |

Both mailbox records (on `workflow-mailbox`) match the frozen event, source and request digests. Both schema validation, parse and mailbox jobs succeeded. Compile, drive apply and noop jobs were skipped. Gate runtime job failed after organic exit 90 (`required controls failed`); the one bad control is the permitted row 858. Census exit 0. The reusable log's `final_job_status=success` precedes final exit propagation, so use the job conclusion and `harness_exit`, not that intermediate line. Neither execution was repeated. Six archive SHA-256 values match the mailbox and run artifact inventories:

| Artifact | ID | SHA-256 |
|---|---:|---|
| Gate result | 14359654903 | `b2a9997c5f41ba760a75003d3edc7682cbd20dbd852f7df49bd8a90de6c2611e` |
| Gate log | 14360722874 | `a4bcd205afe36894d86f827f2bc8b1350118170749c9fb0f1f32f09402c686f7` |
| Gate reusable log | 14361935611 | `70ca12adadc2be1d9f5dece8e2a6998b40d022e48a96ede898cef903bbdaeefe` |
| Census result | 14362615302 | `a44f41eb558fd9205d9725d85d9f83b8d754beef1b24a3d886b847f6e1d639a2` |
| Census log | 14361192411 | `8aa2f80eee3582b12256ceb63f723ca0b6f9bc294d647f1d7c25593a74bd6586` |
| Census reusable log | 14360584168 | `d05468fe58206abce58cb2392f84d61744eb899f1753ab27cb36c853f61fb3fb` |

All 1,914 gate and 9 census internal checks on each side pass (3,846 total). All 1,912 raw log digests bind to the declared row, binary and actual selected identity. Exact frozen membership is 1,034 (953 gated + 81 deferred), byte-equal to TB131. Each gate has 953 executed, 952 PASS, 1 RED, `control_bad=1`; zero abnormal, missing, skipped, duplicate, unexpected_pass, later_positive_red and red_site_bad. Census has 3 executed, 1 PASS, 2 RED, zero bad controls or abnormal/missing/skipped/duplicate. Both have valid postflight, `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Gate runtime approximately 12m39s and census 3m55s (reusable activity-log timestamps).

## Assessment — frozen RA-253 S7

| Criterion | Result |
|---|---|
| 1. Substantive ledger equal TB131 | PASS: 956/956; only row 858 RED at `SurfaceCellTracingDisplayTests.cpp:155`. Cylinder PASS/288 quads; BunnyRandom and Vase RED. |
| 2. Raw logs equal under N1–N5 | PASS: 956/956; no changed residual bytes or M3 record multiset. |
| 3. Receipt scope and replay | PASS: 66 duplicate-cut lines across exactly 19 sphere rows and 2 contact-cut lines only on BunnyRandom. Adjacent replay pairs identical; one distinct line per receipt kind across these runs. |
| 4. Frozen site discriminators | PASS: rows 644/698 edge (0,2), first trace 4; BunnyRandom trace 82, claimant contact face (21,72,273). |
| 5. Other differences | None observed under the frozen criteria. MATCH. |

Prospective offline comparator uses N1 timing, N2 newline framing, N3 complete `M3_CP4AB_FRAGMENT_DIAG` record multiset and ordered non-record remainder, N4 census parameter-object bytes, N5 exact new receipt lines. It rejects removed, duplicated and altered M3 records, changed non-record bytes and a changed substantive ledger field (5/5 negative controls); 4/4 positive controls for record reorder, concatenation, pointer rendering and GoogleTest elapsed time pass. The script executes no project binary. No widening or retroactive reclassification of TB131's literal MISMATCH. Row 648 sphere assertions remain unreached. The accepted 491/491 prefix remains green; no accepted-result loss.

### Receipt geometry — data for independent Review

Sphere rows: 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 694, 698, 699, 700, 843, 844, 858. Four lines in 14 rows; two lines in five rows. All 66 lines have the same content:

```text
EmbeddedGraphTopology.duplicateCutCrossing edge=(0,2) t=0.12749386848657163 cutEdges=288 trace=[4 segments=8 crossing=7  struckTrace=1 struckSegment=0 contactFace=(0,2,3) at=0.89373888688647607 0.016127667144259561 0.090133445969264342 ] trace=[6 segments=8 crossing=7  struckTrace=0 struckSegment=0 contactFace=(0,1,2) at=0.89373888688647618 0.090133445969264175 0.016127667144259533 ] sharedEvents=none
```

The duplicate crossing has edge (0,2), parameter `0.12749386848657163`, 288 selected cut edges. Both trace 4 and trace 6 cross on segment 7 of 8. Their terminal contacts identify different struck traces (1 and 0) on segment 0, in faces (0,2,3) and (0,1,2). No shared event is printed. All printed terminal-contact barycentric coordinates are positive. The common crossing and the terminal contacts are different positions; do not equate them. The site evidence confirms S2's rejection prediction; Review owns the explanation and repair choice.

BunnyRandom census row 2 prints two identical lines:

```text
EmbeddedGraphTopology.contactCutConflict trace=82 position=0:0.2305473011248014 existing=[node=220 contact face=(21,72,273) point=0.032006329006921713 0.19854097211787966 0.76945269887519852 terminating=43 struckTrace=82 struckSegment=0 contactFace=(21,72,273) at=0.032006329006921713 0.19854097211787966 0.76945269887519852  interior=82:0:0.2305473011248014  events=FirstContact@none,TraceIntersection@none] claimant=[node=222 contact face=(21,72,273) point=0.032006329006921713 0.19854097211787966 0.76945269887519852 terminating=15 struckTrace=82 struckSegment=0 contactFace=(21,72,273) at=0.032006329006921713 0.19854097211787966 0.76945269887519852  interior=82:0:0.2305473011248014  events=FirstContact@none,TraceIntersection@none]
```

Both nodes (220 and 222) have contact role and claim trace 82, segment 0, parameter `0.2305473011248014`, face (21,72,273). Their barycentric points are byte-identical as printed and strictly positive. Terminating trace 43 belongs to node 220 and trace 15 to node 222. Each reports `FirstContact@none,TraceIntersection@none`; no edge-bearing event appears on these claimants. These are producer-identity observations, not authorization to merge nodes by coordinate equality. Exact source identity, event ownership, and whether these are two contacts at one point or duplicate representations require independent Review (FC-1/FC-4).

All new printed contact points are strictly interior by the printed coordinates; no zero coordinate is observed. O45 stays open pending S4 adjudication by Review. The receipt is not a census of all contacts on all inputs. Cylinder remains PASS (288); BunnyRandom still fails `TraceEventPositionNodeConflict`; Vase remains RED at completion. No new stable event, debit, or witness discharge. C5/O42/O43/O45/O46, H2, FC-1/FC-4 producer proof and middle-piece direction remain open. Stable 66/17/49, debt 1, deferred 81, CP2 491/491, CP3/selector497/D0 unpromoted. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`.

## Recommendation — independent Review only

After root STATUS completes `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-EXEC`, next is `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-REV`. Independently re-open this evidence and RA-253 S7, attribute both sites, decide S4/O45 and freeze at most one repair DEFN per site. Do not repair in execution or Review; FC-6, terminal-cut outcome and row 858 face-witness correction remain held. No promotion. Raw archives, comparison JSON and comparator are retained in `Directional_TB132_verified_evidence.zip` in the Directional File Library. Previous attempt's cleanup run `44155528951`, commit `d976ffefe7c567a3390c9b8b234f69a158a25925`, removed only its snapshot trigger and cleanup manifest. No new temporary repository caller or marker required. The previous attempt's initial direct reads preceded mandatory snapshot selection; current attempt reuses the verified snapshot after comparing exact branch authority. Full policy-reading checklist is not certified; no policy or test change was made.
