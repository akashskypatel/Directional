# R4 terminal-conjunct artifact extraction — 2026-10-15

**Canonical turn:** `M6-CP3-TB2-R4-CONJUNCT-EXTRACT`. Artifact-only evidence extraction, now complete. No workflow dispatch, compile, test execution, benchmark, code/test/selector change, source mutation, accepted-GREEN credit, or `RP-02` consumer execution.

## Immutable authority

Original run: https://github.com/akashskypatel/Directional/actions/runs/38725063279. Result artifact ID `11967601999`, SHA-256 `8b52373eebc7bda574f1fed2914dec4577ff70c670396f2ea3b19383d0fd25f1` (both provider digest and independently verified downloaded ZIP). All **50/50** manifest digests match. Original `execution-boundary.txt`: `planned=45 executed=45 red=45 missing=0 postflight=true exit=0 compile=false relink=false benchmarks=false selector497=false`. Original immutability file: `package/source/execution_view/selector=true`. Original compiled semantic source `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`. The exact original `ledger.tsv` was paired by row index with `raw/<index>.log` from the verified ZIP. Duplicated diagnostic messages inside a selected test were not counted as extra cases.

## All 45 identities classified from recorded bytes

| Family | Count | Original artifact indices | Observed first failure |
|---|---:|---|---|
| Interior-shaped paired barycentrics | **23** | 1–11, 26–33, 38–39, 42, 45 | `no-exact-terminal-corner` |
| One-hot paired vertex barycentrics | **21** | 12–25, 34, 36–37, 40–41, 43–44 | `no-exact-terminal-corner` |
| Distinct ordinal 405 | **1** | 35 | `missing-terminal-or-closed-rail-provenance` |

The 23 interior-shaped cases all record from face 0 `0x0p+0,0x1.999999999999ap-1,0x1.9999999999999p-3` and to face 3 `0x1.999999999999ap-1,0x0p+0,0x1.9999999999998p-3`. Their differing exact double values do not establish a valid interior-certificate branch, and RA-60.5's aliased failure remains unresolved.

The 21 one-hot cases record from face 0 `0x0p+0,0x0p+0,0x1p+0` and to face 7 `0x1p+0,0x0p+0,0x0p+0`. Both are one-hot but must satisfy the **same published candidate terminal vertex**. For candidate `v`, the three RA-61.11 conjuncts are:

```cpp
(carrierEdge.first() == v || carrierEdge.second() == v)
&& exact_corner(fromPoint, v)
&& exact_corner(toPoint, v)
```

The original `railEnd[v]` and `corner[v]=<from>,<to>` probes give the exact truth values:

| Subset | Count | Carrier edge | Candidate | Carrier membership | From exact corner | To exact corner |
|---|---:|---|---|---|---|---|
| A | 15 | (1,4) | v=1 | **true** | **false** | **false** |
| A | 15 | (1,4) | v=7 | **false** | **false** | **false** |
| B | 6 | (1,2) | v=1 | **true** | **false** | **false** |
| B | 6 | (1,2) | v=6 | **false** | **false** | **false** |

Thus **all 21 one-hot cases definitively fail both exact-corner checks for each published terminal candidate**, and the second candidate additionally fails carrier-edge membership. They are not failures of A3 or contact *presence*: each records `a2bProbeCarrierPresent=1`, `a2bProbeA3Present=1`, `a2bProbeContactPresent=1`, `a2bProbeClosedChainPresent=0`. Original rows with subset B are indices 15–19 and 25; all other one-hot rows are subset A. The logs do not prove a canonical source vertex shared between charts or justify changing terminal authority; the repair remains unapproved.

Ordinal **405** (row 35) is separate: `endpoint-0`, from `0:0,1,0`, to `2:1,0,0`, `carrierPresent=1`, `A3Present=1`, `ContactPresent=0`, `ClosedChainPresent=0`, without a terminal `corner/railEnd` record. Do not fold it into the 21 one-hot mechanism.

## Boundaries and next action

This extraction does not measure optional `sharedBoundaryInterval` presence or the associated rational ordinals (RA-61.9 falsifier (i)), nor establish that reciprocal interval ordinals fix a **point** rather than just an interval (falsifier (ii)). Neither `RP-02` half executed. **No relaxation, epsilon, acceptance remedy, or 497 rerun is authorized.**

**Separately authorized successor:** `M6-CP3-CB2-R4-PREDICATE-SEPARATION`, diagnostic-only Code + Build. Separate the first-rejection strings without changing any acceptance decision, emit optional shared-boundary interval presence and exact ordinals, then seek separate measurement/review authority. Retain R4-VIN-01; altered semantic source cannot reuse old test evidence as a comparand.

Stable regression ledger **66 events / 17 categories / 49 recurrences**, debt **1**. CP2 **491/491** accepted; R3 **403/497** rejected (94 RED, 88 carried accepted losses). Frozen selector **497** remains unchanged. PR #8 stays draft/unmerged. Complete per-identity and log-derived data are preserved in the downloadable chat TSV/report, including all 45 individual identities; this repository report remains usable after result-artifact expiry.
