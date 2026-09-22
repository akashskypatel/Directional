## 2026-09-22 — `M5-CP3-TB1-R11-R1-REV`: endpoint-gauge authority defect proved — **EXISTING `RP-01` CONTINUATION / NON-STABLE / +0**

**Stable totals remain 50 events / 14 categories / 36 recurrences. Produced-witness debt remains 3. Accepted runtime authority remains unchanged.**

Fresh R11-R1 run/job `35778555375 / 106917917282` on CB12 candidate
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` is mechanically valid: complete result self-manifest **912/912**,
mechanism **9/9**, focused atlas **1/1**, produced **4/6**, selector430 **430/430**, benchmark 0 and exact immutable postflight.
Produced rows4/5 alone fail at `PeriodicActionCorrespondenceMismatch` before materialization/tamper assertions.

### `M5-CP3-TB1-R11-R1-CAND-01` — CAUSE PROVED / product endpoint-gauge authority-domain conflation

**Status:** CAUSE PROVED / PRODUCT / EXISTING `RP-01 AUTHORITY_DOMAIN_CONFLATION` CONTINUATION /
CUT-DOMAIN CELL COORDINATE USED AS QUOTIENT-SEAM ENDPOINT AUTHORITY / NON-STABLE / OWNER `M5-CP3-CB14` / +0.

Review proves CB12's semantic Forward -> Reverse direction is exact and storage-order independent. The collapsed correspondence guard
can fail only because `periodic_action_for_pair(...)` returns no action: a returned action carries the supplied generator rotation by
construction. Source-chart presence and zero scale pass; exact branch correspondence follows the directed transition; the first
endpoint mapping is true by shift construction. The **second endpoint mapping is the first false predicate**.

The accepted four-run bounded-disk rectangle places reciprocal copies on opposite sides, giving raw cell-grid deltas `d2=-d1`.
Frozen §16 requires `rotate(R,d1) == -d2`, hence `rotate(R,d1)==d1`; for nonzero cardinal `d1` no genuine quarter-turn
`R in {1,2,3}` can satisfy this. The product therefore conflates cut-domain cell placement with quotient-seam relation endpoint
authority. CB14 owns the bounded correction: preserve ordinary cell coordinates, derive a separate relation-owned endpoint gauge
independently from each endpoint's own exact A3 occurrence/source-chart/branch and one directed generator transport, and consume it
in producer plus checked validator with no partner fitting/search/rewrite.

### `M5-CP3-TB1-R10-REV-CAND-01` — CLOSED / recovery proved

**Status:** CLOSED / RECOVERY PROVED / NON-STABLE / +0.

CB12 removes pair insertion/storage order from the directed transform. R11-R1 reaches the exact semantic Forward -> Reverse path and
successful generator-route construction before the downstream endpoint-gauge mismatch. The R10 insertion-order defect is therefore
not the remaining cause.

### `M5-CP3-TB1-R6-REV-OBS-01` — CLOSED / direction authority proved

Fresh nonzero-Z4 R11-R1 reaches the semantically directed Forward -> Reverse construction path. The previous zero-Z4 inability to
discriminate forward from inverse is discharged; the surviving RED is downstream endpoint-gauge authority.

### `M5-CP3-TB1-R11-EXEC-CAND-01` — CLOSED / orchestration correction runtime-confirmed

Invalid R11 run/job `35771152416 / 106892972571` self-included temporary `SHA256SUMS.new`, producing 913 rows for 912 real
evidence files and therefore no semantic ledger. CB13 corrected only the finalizer. R11-R1 executes the full same frozen gate and
produces a fully verified **912/912** result with `driver_exit=0`, recovery-proving that orchestration defect. Invalid R11 artifacts
remain zero-credit provenance.

`M5-CP2-TB1-REV-OBS-01` remains **OPEN**. Selector publication stays prohibited until a corrected candidate is independently green.
The two nonzero-Z4 M5 debts remain open; the separate M6 closed-complex debt remains open.

## `M5-CP3-TB1-R11-R1-REV-OBS-01` — direction observation reopened; "reaches the path" is not "the path is correct"

**Status.** OPEN / reopens `[[M5-CP3-TB1-R6-REV-OBS-01]]` / carried to the first Review in which produced row 4
passes item 5 / NON-STABLE.

`M5-CP3-TB1-R11-R1-REV` §2 discharged the direction observation because "the nonzero-Z4 subject now reaches the
exact semantically directed Forward → Reverse construction path."

**That argument is the class the same Review rejects elsewhere.** §3 correctly discounts
`action.rotation == generatorRoute.rotation` as non-probative, because `periodic_action_for_pair` builds the
action *from* the generator rotation; and it discounts item 4's first endpoint mapping because
`shift = second.to - rotate(R, first.from)` makes it true by definition. Both are labelled "by construction" and
excluded, which is precisely why item 5 is a real localization. By that standard, **reaching the directed
construction path proves the ordering code executes, not that the ordering is correct.**

The original observation required two things, neither of which R11-R1 reports:

1. the produced relation's action checked against an expectation derived **independently of the face order that
   produced it** (§14.2/§16 reciprocity being the natural instrument);
2. an **inverted** pair **failing**.

Rows 4/5 stop at item 5, before the Forward → Reverse comparator, so the falsifier has not run. An inverted
ordering producing a mirrored but self-consistent action would be indistinguishable from this evidence — the
exact failure mode the observation exists to exclude, and the one that would convert today's clean fail-closed
state into a plausible wrong answer.

**How to apply:** `M5-CP3-TB1-R6-REV-OBS-01` returns to **OPEN**. The first Review in which produced row 4 passes
item 5 and reaches the comparator must report both the independent-agreement check and the inverted-pair
failure. The ordering-**source** defect `M5-CP3-TB1-R10-REV-CAND-01` stays **CLOSED** on its own evidence —
CB12's `directedFirst`/`directedSecond` selection by exact A3 orientation is verified at
`src/geometry/SurfaceCellTracing.cpp:17229-17241` — and nothing else in R11-R1 depends on the reopened
observation.
