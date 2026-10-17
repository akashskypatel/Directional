# Review decision — RA-81: CB10 / TB10 carrier-endpoint subcondition

**Turn:** `M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV` · **Verdict:** CB10 and TB10 ACCEPTED as diagnostic evidence (no promotion) · **Date:** 2026-10-17
**Semantic source:** `d938ecb57e1040c2a73d5d25c4a613414556cb18` · **Package:** `12062565622` · **Result:** `12062873272` (run `38941839640`)

## Re-derived evidence

Re-derived from the raw logs of result `12062873272` (ZIP recomputed `4db22a92…`, 51/51 manifest,
`planned=44 executed=44 red=44 missing=0`), independently of the harness. Over the 21
exact-one-hot vertex records:

| field | 15 cases | 6 cases |
|---|---|---|
| `ContactEndpointMember` / `CarrierEndpointMember` | `0` / `1` | `0` / `1` |
| decoded vertex | `4` | `2` |
| published contact endpoints | `{1,7}` | `{1,6}` |
| certificate = resolved carrier edge | `{1,4}` | `{1,2}` |

The two columns are one phenomenon in two vertex numberings (RA-67.5 compaction). The
certificate and resolved carrier agree in all 21, so **RA-80.7 is confirmed**: carrier-edge
membership holds and published terminal-contact membership is the failing half.

CB10 is a pure 26/0 insertion; the emission is inside the rejection branch
(`SurfaceCellTracing.cpp:19544`, closes `:20039`); no added line writes production state; the
packaged blob `668618d7…` equals HEAD; `include`/`tests` unchanged; snapshot `12061008957`,
compile `12062565622` and result digests match.

## RA-81.1 — the endpoint contract has a coverage gap

The fixture rail is the open polyline `1–4–7` (`tests/SurfaceCellsPhase10Tests.cpp:271-272`),
with published endpoints `{1,7}`. Vertex `4` is an **interior vertex of the rail**, where carrier
edges `(1,4)` and `(4,7)` meet. No RA-79 (R9B) branch admits it:

- **V** requires a published rail terminal — `4 ∉ {1,7}`;
- **I** requires a strictly interior edge point — `interior_carrier_parameter`
  (`SurfaceCellTracing.cpp:64-90`) returns `nullopt` unless `0 < t < 1`;
- **C** applies to closed rails only.

This is the ordinary case for any rail subdivided into more than one front edge. R9B named it
("a front endpoint at a nonterminal vertex cannot enter branch I") without assigning it a branch,
and RA-79 accepted that. **RA-79 is amended: the V/I/C contract is incomplete.** No producer is
implicated; code is not authorized.

## RA-81.2 — gates under the authorized documentation reset

The tracker reset at `4a1ac5aa8` and the handoff/ORIENTATION/ROADMAP rewrite are user-authorized
and authoritative. `review_check.py` measures those documents against their all-history
high-water length, so its `boundary` floors for the handoff, ORIENTATION and tracker (seven
checks) fail by construction, and `ledgers` flags any in-place shortening of the handoff. Per
`DOCUMENT_DRIFT_AUDIT_POLICY.md` §2.4 this conflict is classified for human review and the rule is
not changed without its own authorization. All other checks pass.

## Disposition

`RP-01`: localized to the consumer's endpoint contract, which lacks an open-rail interior-vertex
case. `RP-02` unreached. Stable 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497
unchanged; no promotion.

**Next (frozen):** `M6-CP3-DEFN-R10-RAIL-INTERIOR-VERTEX-ENDPOINT-SPEC`, documents only.
Consolidation: RA-77–RA-80 review records and the CB9/TB9 records folded into
`M6_Consolidated_Record.md`.
