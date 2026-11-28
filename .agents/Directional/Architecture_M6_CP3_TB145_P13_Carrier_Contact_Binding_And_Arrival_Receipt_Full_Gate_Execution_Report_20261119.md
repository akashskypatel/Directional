# TB145 — carrier-contact binding and arrival receipt full-gate execution (2026-11-19 UTC)

## Situation

**EXECUTION COMPLETE; independent Review is next.** The immutable CB168E gate executed 961/961 cases (**960 PASS / known row858 RED**, row961 PASS); the three-row census executed 3/3 (**Cylinder PASS / BunnyRandom and Vase RED**). All **964/964 prior TB144 records MATCH** under frozen N1–N7 with only the prescribed appended entry-receipt suffix removed. No source/selector/test/build mutation, production promotion, or code change was authorized or performed.

## Background — immutable evidence

- Source: `d43d07dd1564be90bc1a89775b17b524d4e83039`; compiled artifact `14508452647` ZIP SHA-256 `5daeba011fc49fde4ad083f5104b5a3847abe8b6742dec841465762b0bd1b609`, 28/28 internal checksums. The fixed full-gate manifest (961 gated + 81 deferred) SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949`. The harness SHA-256 is `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Gate run 44484110110](https://github.com/akashskypatel/Directional/actions/runs/44484110110): artifact `14510581877`, ZIP SHA-256 `bac8df3f16b8161f92813e30644ac5d96e9538395fcd4c6b00b285f83d6519fe`, **1,930/1,930** indexed result files. Workflow conclusion `failure` because the preserved required-control row858 is RED; harness exit 90 (`control_bad=1`). All other counts valid: `planned=executed=961`, `passed=960`, `red=1`, `abnormal=missing=skipped=duplicate=unexpected_pass=later_positive_red=red_site_bad=0`, membership 1,042, postflight true.
- [Census run 44484220632](https://github.com/akashskypatel/Directional/actions/runs/44484220632): artifact `14510118951`, ZIP SHA-256 `463a9be377eed40e8c327760f299819b41928e70535aa34c00fe3d14a8507a1d`, **9/9** indexed result files. `planned=executed=3`, `passed=1`, `red=2`, zero missing/skipped/abnormal/duplicates/control failures, postflight true, workflow success.
- Prior TB144 gate artifact `14501920082` (ZIP SHA-256 `a2cdbdf635d91b9fde4be5f5fa093d96d088714b24e5f22988518051824b7922`) and census artifact `14502085765` (ZIP SHA-256 `e7573335b7f222f6e6e383c2fa714697a14e70b5eaefac83bd89f1abdcf601c4`) were rechecked. All four ZIPs passed their internal SHA256SUMS manifests, 3,878 indexed result files total; per-row raw-log SHA-256 matches each ledger.
- Both TB145 result boundaries declare `compile=false`, `relink=false`, `configure=false`, `benchmark=false`, exact immutable source/package authority. No runtime build, repair, selector/manifest edit or test modification occurred.

## Assessment — frozen comparisons

- **961/961 gate + 3/3 census = 964/964 prior log/ledger MATCH.** All 964 per-case verdicts, test identities, failure sites and other prior ledger fields equal TB144; normalizations were applied only as frozen (N1/N2/N4/N7 and TB131 N3). Each new entry receipt ends with one `firstArrival=` and one `faces=` field. Deleting exactly this appended suffix returns all TB144 entry-coincidence receipts as per-row multisets (240 gate + six census).
- Raw slide proposal and committed-slide diagnostics are byte-identical: gate 1,200 of each, census 66 of each, combined 1,266 of each. All complete M3 records match (gate 1,738 + census eight), with zero double-prefix lines. The non-M3 remainder matches after the frozen normalization.
- **491/491** accepted prefix unchanged; new row961 `FieldAlignedCarrierOccupancy.CarrierContactCutsTheStruckTraceAtItsEntryCrossingOnly` PASS. Known row858 `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported` RED at `SurfaceCellTracingDisplayTests.cpp:155`; no unexpected control change.
- Cylinder remains PASS at **288 quads**. BunnyRandom remains RED at source-authoritative trace82 `TraceEventPositionNodeConflict`; Vase remains RED. Prior failure classifications and no-production-acceptance boundary remain unchanged.
- A separate offline comparator was syntax-checked and exercised on one synthetic positive and four deliberately mutated negative controls before use on the four real archives. These comparator checks are not product tests; the full real comparison completed successfully.

### EC3 raw deduplicated arrival/face census

The table records observed data, not a resolution rule. `Cut crossing` means the same log has a `EmbeddedGraphTopology.duplicateCutCrossing` record at the carrier and parameter.

| Fixture (gate/census row) | First / second | Carrier edge, exact parameter | firstArrival | faces | Cut crossing |
|---|---|---|---|---|---|
| Sphere (gate 858) | 4:7 / 6:7 | (0,2), `574181338608147/4503599627370496` | inconclusive | different | yes |
| Sphere (gate 858) | 15:7 / 19:7 | (25,27), `574181338608147/4503599627370496` | inconclusive | different | no |
| BunnyRandom (census 2) | 15:21 / 43:15 | (72,243), `191903898244039/562949953421312` | later | same | no |
| BunnyRandom (census 2) | 15:22 / 43:16 | (72,273), `1755811011335563/2251799813685248` | later | same | no |

Both transverse sphere pairs have `firstArrival=inconclusive`; the next Review must define a **symmetric transverse contact rule**, not infer which trace arrived later. The same-face BunnyRandom pairs remain O48's co-directional merge scope; they do not authorize EC3 transverse wiring. The edge (0,2) has a cut-created crossing and requires the CB168D merge path once production sets the carrier locus; the edge (25,27) has no matching cut crossing and would use the standalone contact node. Both branches are still production-unwitnessed because `carrierLocus` is not published.

This is a **non-stable, unchanged regression checkpoint**, not a new failure candidate: stable regression accounting remains 66 events / 17 categories / 49 recurrences, one produced-witness debt, 81 deferred identities. There is no CP3, selector497, or D0 promotion.

## Recommendation

**Only independent Review next:** `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-REV`. Re-open all four ZIPs, independently check row858, row961, N1–N7, each EC3 receipt and cut-crossing record, and freeze an exact symmetric transverse producer rule if the evidence supports it. Do not implement EC3 or alter code, selectors, tests, normalizations, production acceptance or the frozen TB145 result in this execution turn.
