# TB130 — carrier-proxy contact full gate (2026-11-17 UTC)

## Situation

`M6-CP3-TB130-P13-CARRIER-PROXY-CONTACT-FULL-GATE-EXEC` — **MATCH** under [RA-251 §S5](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md#s5--tb130-frozen-m6-cp3-tb130-p13-carrier-proxy-contact-full-gate-exec). The immutable CB153 gate passes 953/953. The three representative results match TB129. All frozen comparison criteria pass. The diagnostic records outgoing carrier proxies in 19 passing gate rows. This is measurement evidence, not a semantic switch, acceptance promotion, or closure of O45. No successor work.

## Immutable authority and preflight

- CB153 semantic source and harness executor `95f082b144f2bbe145d764cbf6b3d10d123a6514`; package `14338920906`, ZIP SHA-256 `6f949205feae70dbe3a549fa35ce8edf023c78a1f891448b8babf4781aaa73d9`, root manifest `9ef6894b1255a23ab28255af0ed2aed1ce9c11da1eb50e07ab249eccf2b1b983`, source archive `5ffd9ed8ad38967beb293998ae525c307ab3224914f38dc5a81bf7f5cd929042`. Preflight: 28/28 checks, six executable modes, GNU Multiple Precision (GMP and GMPXX) link evidence, clean source, `runtimeExecution=false` at compile. [CB153 record](Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Code_Build_Record_20261117.md).
- Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Frozen [gate](gates/Architecture_M6_TB128_P13_Face_Contact_Node_Full_Gate_Case_Manifest.tsv) `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` (953); [census](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv) `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3); [deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81). Both manifest self-checks pass. No repair, configure, rebuild, relink, fixture, harness, test, source, workflow or selector change. No local project binary execution or benchmark.
- [TB129 comparator](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md): source `c45e9abe5085f39c1f5bcb149ec07f95b719177e`, package `14327212608`. All four comparator archives (result and harness log for each scope) match the digests in that report: `14329895372`, `14329620767`, `14328938547`, `14328973484`.
- Exact snapshot `5f9536a0bec729b4aaaa9312bcac58ff73425fbd`, [run 44108077765](https://github.com/akashskypatel/Directional/actions/runs/44108077765), artifact `14339452513`, ZIP `2b1200cb8b4cbaa337592fd537b20483a239b668087b47c2c86d9dfdf41d8e78`, inner archive `ed52234bfff6492c9d678417f9e6819bd66ae69449f37af3062e7b92b71d0c21`, 5,527/5,527 checks. CB153-to-snapshot comparison contains only documentation/control changes; source, include, tests and harness match. Snapshot-to-resume `1a6b8e131cc67aad665358ea9b3efc72ffcb47c4` confirms seven intervening commits affect only the continuation, dispatcher, snapshot marker and STATUS. The intended closeout document preimages are unchanged.

## Execution and evidence

| Work | Request event SHA / request SHA-256 | Run / runtime job | Mailbox key (attempt 1) |
|---|---|---|---|
| Gate | `e6dc02207aafdd39e29bb5f33bcf13dbdecf927c` / `9d473cd4b459cb35b8710eaf26c4fe1841ec30ebd867cbd710d195bd6e609b85` | [44108374042](https://github.com/akashskypatel/Directional/actions/runs/44108374042) / `134127287141` | `m6-cp3-tb130-gate-v1` |
| Census | `45f70531432b421f917b3fae4e50dcabd7852e8d` / `43d70b048e0a089e7d373735e16f6cb4068ef48f779e160179b4e8316cac1c88` | [44108426938](https://github.com/akashskypatel/Directional/actions/runs/44108426938) / `134133679888` | `m6-cp3-tb130-census-v1` |

Both mailbox records on `workflow-mailbox` match event, source and request digests. Both sets of workflow validation, parse, runtime and mailbox jobs succeeded. Compile, Drive apply and noop jobs were skipped. Each harness completed with exit 0. No duplicate dispatch. All six candidate archive digests match:

| Artifact | ID | SHA-256 |
|---|---:|---|
| Gate result | 14338844806 | `d93a644f800e2c4e641fdc31051556d62f4a55541ef74009c2b86aaedf927fcc` |
| Gate log | 14339907203 | `6d52e25bbbd990410b0b6967b4819caedd6bbeac0f6d7bd27e3516b91488ed1e` |
| Gate reusable log | 14339657985 | `29146df2a2fa929f1e51e489b844474c8c6229a58a39c896df36b972b6d5e785` |
| Census result | 14339793522 | `c21ce302c41839542015b03bb6c18618798ed1e8dde74b40925c1693785532ca` |
| Census log | 14339982726 | `958403517ec6d8a7d821a5de9508dc147563ebf5ddbabcac2138bd3e4f53a740` |
| Census reusable log | 14340137669 | `7d4c1df487b9d535b7dbc8e474b3bd36f795601d65447033f26db2ae4aa3b801` |

All 1,923 candidate and 1,923 comparator internal checksums pass (3,846 total). All 956 row/raw-log SHA-256 bindings for each package pass (1,912 total). Gate: 953 planned/executed/PASS, zero RED, missing, skipped, duplicate, abnormal or bad controls. Membership: 1,034 unchanged (953 gated + 81 deferred). Census: 3 planned/executed, 1 PASS, 2 registered RED, zero abnormal/missing/skip/duplicate/bad controls. Both postflights pass. Execution boundary records no compile, relink, configure or benchmark.

## RA-251 §S5 comparison — MATCH

| Frozen criterion | Observed evidence |
|---|---|
| Gate 953/953 PASS | PASS; all 953 substantive ledger records match TB129. |
| Representative dispositions | Cylinder PASS, 288 quads. BunnyRandom and Vase RED at unchanged sites; zero accepted faces. |
| Raw-log equality | Delete only complete `EmbeddedGraphTopology.carrierProxyContacts ` lines. 948 gate logs match after elapsed-time normalization, five match the permitted newline framing, all 3 census logs match under the TB129 normalizations. Zero mismatches. |
| Substantive ledger equality | All 956 records match in every field except raw-log SHA-256. |
| Previous diagnostic records | All 66 gate and 2 BunnyRandom `terminalCutBeforeEnd` lines match exactly per row. |
| Census line validity | All 34 lines satisfy `nodes >= 1` and `terminals = lastIncoming + lastOutgoing + neither + unresolved`. No malformed lines. |
| Incoming positive controls | All 19 prior receipt rows and BunnyRandom contain a line with `lastIncoming >= 1`. |

The offline comparator and its complete JSON output are in `Directional_TB130_verified_evidence.zip`. It removes only complete newline-terminated census records, checks every old receipt and compares each ledger field other than the raw-log checksum. It runs no Directional binary. No acceptance criterion was changed. TB129's earlier frozen MISMATCH remains historical authority; TB130 uses its actual records as the frozen comparator.

## Diagnostic data (not MATCH criteria)

Each of the 33 gate census lines contains the same values:

```text
EmbeddedGraphTopology.carrierProxyContacts nodes=6 terminals=8 exactRecords=8 lastIncoming=2 lastOutgoing=6 neither=0 unresolved=0 exactBinding=ok contactNodes=12
```

BunnyRandom prints one census line:

```text
EmbeddedGraphTopology.carrierProxyContacts nodes=88 terminals=88 exactRecords=88 lastIncoming=49 lastOutgoing=39 neither=0 unresolved=0 exactBinding=ok contactNodes=150
```

| Scope | Rows | Lines | Nodes | Terminals | Incoming | Outgoing | Exact records | Neither | Unresolved |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Gate | 19 | 33 | 198 | 264 | 66 | 198 | 264 | 0 | 0 |
| Cylinder | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| BunnyRandom | 1 | 1 | 88 | 88 | 49 | 39 | 88 | 0 | 0 |
| Vase | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

All 34 printed bindings are `ok`. No observed violation of the static predictions `neither = 0` or `exactRecords + unresolved = terminals`. Cylinder and Vase have no census line. Under RA-251 §S5 this is a real zero for proxy contact nodes in the topology builds consumed by A2a′, not proof about unexecuted paths or all contact nodes. Each repeated build remains a separate printed measurement. Do not infer counts of distinct networks or unique defects from summed records.

### Passing gate rows with outgoing proxies

Counts per row sum the printed records. Each record has eight exact records and the same validity/binding values above. All rows below are PASS; the other 934 gate rows have no census line. Six are selector identities. These observations satisfy the RA-251 §S6 condition for staging the next switch behind an option that is off by default. The next Review owns the actual definition and scope.

| Row | Identity | Lines | Nodes | Terminals | Incoming | Outgoing |
|---:|---|---:|---:|---:|---:|---:|
| 380 | `selector:338` | 2 | 12 | 16 | 4 | 12 |
| 388 | `selector:346` | 2 | 12 | 16 | 4 | 12 |
| 393 | `selector:351` | 2 | 12 | 16 | 4 | 12 |
| 394 | `selector:352` | 2 | 12 | 16 | 4 | 12 |
| 396 | `selector:354` | 2 | 12 | 16 | 4 | 12 |
| 397 | `selector:355` | 2 | 12 | 16 | 4 | 12 |
| 644 | `offgate:180` | 2 | 12 | 16 | 4 | 12 |
| 645 | `offgate:181` | 1 | 6 | 8 | 2 | 6 |
| 648 | `offgate:185` | 1 | 6 | 8 | 2 | 6 |
| 669 | `offgate:210` | 2 | 12 | 16 | 4 | 12 |
| 686 | `offgate:229` | 2 | 12 | 16 | 4 | 12 |
| 691 | `offgate:234` | 2 | 12 | 16 | 4 | 12 |
| 694 | `offgate:240` | 2 | 12 | 16 | 4 | 12 |
| 698 | `offgate:246` | 2 | 12 | 16 | 4 | 12 |
| 699 | `offgate:247` | 2 | 12 | 16 | 4 | 12 |
| 700 | `offgate:248` | 2 | 12 | 16 | 4 | 12 |
| 843 | `apicensus:12` | 1 | 6 | 8 | 2 | 6 |
| 844 | `apicensus:13` | 1 | 6 | 8 | 2 | 6 |
| 858 | `apicensus:19` | 1 | 6 | 8 | 2 | 6 |

### Representative dispositions and existing cause

- **Cylinder:** same production PASS, 288 quads. Zero proxy census lines.
- **BunnyRandom:** same failure `NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`, `ArcTraceTerminalCutPositionMismatch`, source vertex 3. Trace 1, event 117, 15 segments, position 14, incoming edge (42,336), face (42,335,336), struck trace 21/segment 4. The two old receipts match exactly. The dry-run exact binding succeeds. No H2 example is observed.
- **Vase:** same completion RED (`AggregateCompletionValidationFailure`). Zero proxy census lines. No change to its open completion obligations.

## Regression classification and limits

No new loss of an accepted result or new stable regression event. The existing C5/O45/FC-7 candidate remains open. The producer retains the exact contact but publishes a common-carrier edge; the edge-bearing contact bypasses face-contact classification and resolves an incoming position at n−1. The guarded arc constructor rejects this position. The outgoing case can resolve n but uses an edge locus; RA-251 identifies the Amendment 13 obligation. The 19 passing rows establish exposure to outgoing proxies, not that a corrected switch passes or that every such row has accepted final geometry. Neither the node-level switch nor its validators ran in this turn. Preserve H2, O46, FC-1/FC-4 and the middle-piece direction witness as open. Do not change the prior TB129 verdict.

Stable totals 66 events / 17 categories / 49 recurrences; produced-witness debt 1, deferred 81. CP2 accepted 491/491. CP3/selector497/D0 unpromoted. C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. D11=A, D12=A, D10 deferred, D6 pending; `chainRimSchedules=false`.

## Recommendation

Exactly next, separately: `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH` under [RA-251 §S6](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md#s6--turn-sequence). The Review must re-open both primary archives and freeze the node-level FC-7′ switch at the specified loci. The frozen staging condition is met. Preserve barrier and port `FirstContact` edge loci, remove the diagnostic in the proposed switch, and retain every existing guard and independent witness obligation. No implementation, runtime, or Review in TB130. Hold the terminal-cut outcome and FC-6 definition until the switch Test + Benchmark turn.

## Closeout provenance

- [Earlier continuation](Architecture_M6_CP3_TB130_P13_Carrier_Proxy_Contact_Full_Gate_Continuation_20261117.md) records the full gate and pending census before resumption. It is historical execution provenance, not an active instruction after this report and the final COMPLETE beacon.
- [Cleanup run 44109662613](https://github.com/akashskypatel/Directional/actions/runs/44109662613) completed for event `f25a0a893416dccebafac989d2e358f9238d544b`, cleanup commit `99e94a28cdd4687138fbeb4772842487cb03877a`, result `14339807345` ZIP `63e365d50071b6d22eb3ab4a2b14b3894bc6bcc77105f38e27af3dc25507bff6`. The current snapshot marker was removed. No unrelated control files or PR comments were removed.
- The prior response dispatched after immutable package checks but before snapshot inspection. This resume read the exact retained snapshot, verified the published census and executed only the offline comparator. No repeat runtime. The scratch Git baseline initially failed the local ownership check; corrected only the scratch directory ownership. Exact cumulative tool-call count across the prior response is unavailable. These procedural limitations do not alter the verified runtime evidence.
- Documentation audit against the verified snapshot: baseline zero errors and warnings; final projected tree zero errors, three protected-change warnings (handoff, orientation, roadmap). These are limited to current-state/next-turn updates required by the closeout instructions. No durable heading, policy, normative definition, frozen selector or historical evidence was removed. The user authorized repository mutation for this exact turn. The audit output is retained in the evidence bundle; no independent Review is claimed.
