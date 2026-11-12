# TB94 chain stop-node immutable full-gate execution report (2026-11-10)

**Turn:** `M6-CP3-TB94-P13-A3-CHAIN-STOP-NODES-FULL-GATE-EXEC` (64B.5). **Disposition: COMPLETE / MATCH** under [RA-219 §6](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Span_Switch_Takeover_Review_20261109.md). Artifact-only Test + Benchmark: no implementation, test, fixture, selector, benchmark, CMake or build logic changes, and neither execution configured, compiled, relinked or benchmarked a project binary.

## Immutable authority and evidence

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft/unmerged. CB111 semantic source `abad9902b29e555bc568072b41189e10cad24138`, build [42784806547](https://github.com/akashskypatel/Directional/actions/runs/42784806547), immutable package artifact `13749155800`, ZIP SHA-256 `acf62e697c08a3514457c94fdafa56e4ef2d8803e8937cde82a2f71eaf55d76d`, 28/28 package checksums. Unwired helper only; product behavior unchanged.
- Exact executor snapshot source `e2c198814d6bc57116dfc1fbb749ab728af621f6`, [run 42790535776](https://github.com/akashskypatel/Directional/actions/runs/42790535776), artifact `13750983203`, ZIP SHA-256 `a982a90ca20a00a99dc12bc96ff5410261eba0f8acd2b49d7890decdaad81a47`, 5,415/5,415 file checksums verified. Its temporary snapshot trigger was retired by [cleanup 42791871063](https://github.com/akashskypatel/Directional/actions/runs/42791871063).
- Frozen [TB94 case manifest](gates/Architecture_M6_TB94_P13_A3_Chain_Stop_Nodes_Full_Gate_Case_Manifest.tsv): 925 rows, SHA-256 `ebaf1972c824b0b6256e77c15c309d6a0595f46b26d365368eec8145333bfce9`. Deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 entries. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Self-check passed for both gate and census.
- Gate dispatcher event `ab829d7c701f89ede5be1a9993fa2683af2566ae`, [run 42791092755](https://github.com/akashskypatel/Directional/actions/runs/42791092755), artifact **13751991097**, ZIP SHA-256 `10e38b8cc9714e8dcbe1855bf3863eb0605cafb6d9af19f47f3e8cacc83b45eb`, **1,858/1,858** internal checksums verified.
- Census dispatcher event `9dbdda061bb3bad474b513dc04eb90753189b813`, [run 42791131187](https://github.com/akashskypatel/Directional/actions/runs/42791131187), artifact **13752667095**, ZIP SHA-256 `b9c0509a7587de74af1246c8ddaf925ed9e6d510ecd75a211be6d948da425b37`, **9/9** internal checksums verified. Both mailbox records name the exact event, original CB111 source and successful dispatch. No rebuild or source repair.

## Independent result comparison against TB93

| Gate | Verified result |
|---|---|
| Full gate | **925 planned / 925 executed / 925 PASS**, membership **1006**, postflight true, exit 0 |
| Negative/control status | Zero RED, abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, red_site_bad or later_positive_red in gate |
| Inherited rows | TB94 rows **1–923** match TB93 exactly on row, kind, identity, test, binary, verdict, exit, run, passed, skipped, first-failure and typed-reason fields; per-run log hashes are intentionally not verdict identities |
| Raw platform-digest lines | **7/7 byte-identical** with TB93, over gate and census |
| Raw A3-coverage lines | **7/7 byte-identical** with TB93, over gate and census |
| GUARD 924–925 | **2/2 PASS**, independently executed once each |
| Census | **3/3 executed**: Cylinder PASS; BunnyRandom RED; Vase RED, identical typed ledger identities/verdicts to TB93, no unexpected change |
| Execution boundary | Both artifacts `compile=false`, `relink=false`, `configure=false`, `benchmark=false`, `exit=0`, `error=""`, postflight true |

The literal raw-line comparison included Plane, MultiFaceSeam, CloseSheets, gate/census Cylinder, BunnyRandom and Vase. It was not reconstructed from normalized field values. A registered RED is not a direct-production success; the census ledger records `reason-not-observed` rather than proving a new root cause. The previous P13-e BunnyRandom source-vertex-49 and Vase completion/producer owners remain unresolved.

## Two new non-vacuous stop-node receipts

```text
D5_STOP_RECEIPT case=sources none= ports=4 hardFeature=2,3 curves=1,5 all=1,2,3,4,5 permuted=same
D5_STOP_RECEIPT case=partition unstopped=0F,1F,2F|3F,4F stage1=0F,1F,2F|3F|4F corner1=0F|1F,2F|3F|4F port2=0F,1F|2F|3F|4F
```

These come from distinct PASS guard rows 924 and 925. Their test assertions—not the diagnostic text alone—establish coverage for port, feature-curve, hard-feature-endpoint and stage-1 partition stop behavior. This does not demonstrate production consumption of A3 chains; CB111's function remains unwired.

## Classification and successor

**MATCH; no new stable regression or accepted-green loss.** Retain accepted CP2 **491/491**, stable events/categories/recurrences **66/17/49**, regression debt **1**, deferred ledger v5 **81** and selector497/CP3 **unpromoted**. The registered BunnyRandom and Vase failures, D5 unwired switch, O34 closed rails, O35 hard-feature-rail limitation and D4/D9c/A2b/A4/D8/D6 obligations remain. Under RA-219 §3/§6, the sole successor is **`M6-CP3-CB112-P13-A3-CHAIN-ARC-BINDINGS`** (64B.6), a separate compile-only turn. No CB112 work occurred here; CB113 remains Review-only and unfrozen.

**Operational process disclosure:** the entry session read repository handoff/TODO/tool-policy before the required snapshot read-mode choice, then corrected the source-inspection path by verifying a complete exact snapshot. The deviation is retained as process evidence, not represented as checklist-perfect execution. The successful immutable binaries and receipts are independent of that ordering error.
