# Endpoint-chart probe — immutable artifact-only Test + Benchmark harvest

**Turn:** `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST`
**Date:** 2026-10-15
**Execution:** [Actions run 38782417387](https://github.com/akashskypatel/Directional/actions/runs/38782417387), mailbox key `m6-cp3-tb4-r4-endpoint-chart-harvest`, result **success**.
**Result archive:** artifact `11996317553`, size 80,281 bytes, ZIP SHA-256 `44df6e2fc1bdba1e15f81e11ddec7bbb6cc90e2d43adcda4f334d875d1dbd9c9`.
**Harness:** `.agents/Directional/tools/m6_cp3_r4_endpoint_chart_harvest_harness.sh` at executor `6129289e1cb1c83ee3a8eb751f173b2e0bced286`, SHA-256 `5b13f121bd678ec975e9c4d00df3685e79893eff8f7f9f42f980402b9b955fab`.
**Dispatch:** event SHA `8e8cf1cfad8ad973cf9cc54766505655ac62be95`.
**Immutable subject:** compile artifact `11994726341`, ZIP SHA-256 `b59dc16f4417693c4aec79025160da2054cfbca3a1589ef051ee3a171d3185bb`, semantic source `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`. This is the NEW package. The earlier artifact `11976790988` is a historical baseline, **not the measured comparand**.

## Verified execution boundary

The downloaded result ZIP matches the mailbox digest byte-for-byte; its `SHA256SUMS` verifies every included file. `execution-boundary.txt` explicitly reports `planned=44`, `executed=44`, `red=44`, `missing=0`, `postflight=true`, `exit=0`, `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`. The harness verifies the immutable subject's 28/28 packaged checksums before and after execution, exact source identity, GMP command boundary, source archive SHA-256, frozen selector checksums, and three distinct package/source/execution-view before-after byte inventories. Each selected identity runs as its own process; ordinal 405 is explicitly excluded because its non-interior mechanism is a separate case. The result archive includes all 44 raw logs, `ledger.tsv`, `endpoint-chart-harvest.tsv`, `chart-summary.txt`, manifest receipts, and immutability receipt.

All 44 selected identities returned RED, all with `a2bProbeFailure=no-exact-terminal-corner`, as under the prior semantic-source baseline. These are **observed failures of the new source**, not new stable regressions or evidence of a loss of accepted green results. The new diagnostic fields are present. No source, test, production predicate, immutable package, benchmark, frozen selector, or accepted-ledger mutation occurred in this Test + Benchmark turn.

## Measured endpoint-chart partition

Every carrier edge below is **computed**, not emitted. The instrument omitted the mandated `a2bProbeCarrierEdge` field (RA-66). For each row the harness parses the two canonical three-vertex `SourceFaceTopologyKey` triples `CarrierFirstFace` and `CarrierSecondFace` and takes their two-element set intersection. Every such intersection has cardinality exactly two; no edge identity was invented from the fixture. The actual A4 endpoint face rows and both source attachment keys were measured independently.

| Partition | Count | FromFace → ToFace | FromAttachment → ToAttachment | CarrierFirstFace / CarrierSecondFace | Computed carrier edge | Source terminal |
|---|---:|---|---|---|---|---|
| Interior-shaped, first failure `not-same-interior-carrier-point` | 23 | 0 → 3 | (0,1,4) → (1,4,5) | (0,1,4) / (1,4,5) | (1,4) | none |
| Junction A, first failure `carrier-orientation` | 15 | 0 → 7 | (0,1,4) → (4,7,8) | (0,1,4) / (1,4,5) | (1,4) | 4/4 |
| Junction B, first failure `carrier-orientation` | 6 | 0 → 7 | (0,1,2) → (2,6,8) | (0,1,2) / (1,2,5) | (1,2) | 2/2 |

**First-order classification:** 23/23 interior-shaped cases have **both** attachment keys in the carrier face pair, in the forward orientation; 21/21 junction cases have **exactly one** in the carrier face pair, always the *from* attachment. Neither/zero, both/swapped, missing keys, and missing endpoint faces are zero for the 21. The actual rows **0/7** are now *measured*, not a prior inferred illustration. For every junction case, the other endpoint attachment shares the indicated terminal source vertex but is not either of the carrier's two face keys.

The observed `carrier-orientation` outcome is therefore explained at the **first rejecting comparison** by nonmembership of the *to* attachment face key in the carrier's face pair. This does **not** establish which upstream rail segment, front sector, or publisher continuation should own the endpoint. No sector is claimed here: a source-based sector reconstruction would have to exhibit all relevant fixture rail edges and vertex incidences line by line. The new measurements do not authorize a route extension, gate change, exact-parameter reconstruction, acceptance promotion, or RP-01 code correction.

## Disposition and evidence boundaries

- **`R4-VIN-01`:** known recurring terminal failure, reproduced as 44/44 RED on new immutable source. Record as a non-stable diagnostic candidate/continuation; no new stable event, category, or recurrence earned by this instrumentation-only change. Accepted CP2 **491/491**, rejected R3 **403/497**, 66/17/49 accounting, debt 1 and the frozen `30+12+449+6=497` selector remain unchanged.
- **`RP-01`:** face-pair mismatch is now measured rather than assumed; root correction remains unapproved. **RA-64.6 stays withdrawn**: no evidence here proves that a route was truncated by its publisher.
- **`RP-02`:** still unreached. **Gate C remains suspended** under RA-65.5 because the required vertex-star authority product has no producer.
- No full TB497, alternate compilation, source-grid recovery, benchmark, independent architecture Review or production acceptance is claimed. This Test + Benchmark observation requires a separately authorized independent Review before a Code + Build remedy.

## Reproduction and evidence access

1. The archived harness is pinned to `11994726341`, package ZIP hash, 28-file manifest hash, exact source archive hash, and source commit. The earlier old-package harness must not be reused.
2. The committed harness has an independently measured SHA-256 matching the executor request.
3. Run mailbox entry is under `workflow-mailbox:.workflow-mailbox/m6-cp3-tb4-r4-endpoint-chart-harvest/latest.json`.
4. Immutable result: [artifact 11996317553](https://github.com/akashskypatel/Directional/actions/runs/38782417387/artifacts/11996317553). The tabular file is the per-identity authority; aggregates in this record are computed from it.

**Next action:** preserve and review these observed face/attachment/carrier fields independently; do not infer the source sector or resume endpoint repair without the separate review decision.
