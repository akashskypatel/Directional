## 2026-09-23 — `M5-CP3-TB1-R12-EXEC`: CB14 runtime is mechanically complete but regresses the ordinary torus and does not recover nonzero-Z4 — **439 PASS / 7 RED / REVIEW REQUIRED / +0**

**Stable totals remain 50 events / 14 categories / 36 recurrences pending mandatory Review. Produced-witness debt remains 3. Accepted runtime authority remains unchanged.**

R12 run/job `35802519951 / 106995887964` consumes immutable CB14 candidate
`10725395682 / b8dc3e906dd03525861a1985ea574bad1ad5c69a`. All **446/446** fresh exact-filter processes select once with zero
skips; result evidence is complete **912/912** with exact immutable postflight. Vector: mechanism **9/9**, focused atlas **1/1**,
produced **0/6**, selector430 **429/430**. Protected ordinals 191/192/247 PASS; accepted ordinal408 REDs. Result/log artifacts are
`10726868409 / 10726518857` at ZIP SHA-256
`3f5978b7e0753dccd68fa53ddc50e50b3a5d4d3ea61d2bbd6e9da688531877bc /
146fa160681f012c10979eb8018f6b91e1ad41b2ce5ef5c02c70dc0f36a9d265`.

### `M5-CP3-TB1-R12-CAND-01` — OPEN / exact-A3 checked-product representation/gauge mismatch candidate

Produced rows1/2/3/6, all PASS at R11-R1, now fail while creating the ordinary torus fixture with
`InvalidFinalCellState`; selector ordinal408 likewise changes from PASS to a rejected phase front (`NotProductionReady/tracing/None`).
Candidate source localizes this public reason to `SurfacePhaseFrontProduct::make(...)` rejecting the completed phase-front build.

CB14's new exact-A3 checked-product branch validates A3 Forward/Reverse edge endpoint states against the stored relation's action/cut
route. Immediately before publication, `insert_periodic_holonomy(...)` independently canonicalizes relation representation and may replace
it with inverse action plus reversed generator/cut routes, while `PeriodicRelationId` remains orientation-neutral and the edge's A3
occurrence orientation / endpoint-gauge state is not correspondingly rebound. This creates a bounded `RP-01`-class authority hazard:
**semantic A3 direction may be conflated with storage-canonical relation orientation**. Runtime does not expose the final checked-product
subcode or prove that the failing torus pair took the inverse-canonicalization branch, so this remains a non-stable candidate for R12
Review rather than a claimed stable recurrence.

### `M5-CP3-TB1-R11-R1-CAND-01` — FAILED RECOVERY / still `PeriodicActionCorrespondenceMismatch`

Produced rows4/5 remain at the same correspondence failure and still do not reach materialization/tamper assertions. CB14 therefore has
not runtime-proved the endpoint-gauge correction. The refactored action helper now contains multiple unreported predicates; EXEC does not
invent the first false one. Existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` remains open pending mandatory Review.

`M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN** because row4 still does not reach the independent Forward -> Reverse comparator or its
inverted-pair falsifier. `M5-CP2-TB1-REV-OBS-01` remains **OPEN** because selector430 is not independently green. Candidate remains
unpromoted; no debt is discharged and selector publication remains prohibited. Exact successor is `M5-CP3-TB1-R12-REV`.

## 2026-09-23 — `M5-CP3-CB14`: endpoint-gauge correction compile-green — **RUNTIME PROOF PENDING / +0**

**Stable totals remain 50 events / 14 categories / 36 recurrences. Produced-witness debt remains 3. Accepted runtime authority remains unchanged.**

CB14 implements the existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` correction with a typed periodic relation endpoint state derived
independently from each endpoint's own cut-domain coordinate, branch, source chart, scale and exact A3 occurrence/orientation under the
one directed generator rotation. Ordinary cell placement remains unchanged. Producer action construction and checked-product validation
consume/rederive the same authority; the exact A3 path has no partner fitting, endpoint rewrite, inverse retry or transform search.

Final compile/package run/job `35798853372 / 106984376759` on source `b8dc3e906dd03525861a1985ea574bad1ad5c69a` is green; candidate
artifact `10725395682` has eight GMP/GMPXX targets, root manifest **28/28**, clean source receipts and `runtimeExecution=false`. This is
compile evidence only: the existing R11-R1 candidate remains the latest runtime subject and the root-cause event gains no stable credit.
Exact owner of recovery proof is `M5-CP3-TB1-R12-EXEC` -> mandatory Review.

## 2026-09-22 — `M5-CP3-TB1-R11-R1-REV`: endpoint-gauge authority defect proved — **EXISTING `RP-01` CONTINUATION / NON-STABLE / +0**

**Stable totals remain 50 events / 14 categories / 36 recurrences. Produced-witness debt remains 3. Accepted runtime authority remains unchanged.**

Fresh R11-R1 run/job `35778555375 / 106917917282` on CB12 candidate
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` is mechanically valid: complete result self-manifest **912/912**,
mechanism **9/9**, focused atlas **1/1**, produced **4/6**, selector430 **430/430**, benchmark 0 and exact immutable postflight.
Produced rows4/5 alone fail at `PeriodicActionCorrespondenceMismatch` before materialization/tamper assertions.

### `M5-CP3-TB1-R11-R1-CAND-01` — CAUSE PROVED / product endpoint-gauge authority-domain conflation

**Status:** CAUSE PROVED / PRODUCT / EXISTING `RP-01 AUTHORITY_DOMAIN_CONFLATION` CONTINUATION /
CUT-DOMAIN CELL COORDINATE USED AS QUOTIENT-SEAM ENDPOINT AUTHORITY / NON-STABLE / CB14 CORRECTION COMPILE-GREEN / R12 REVIEW PROOF PENDING / +0.

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

### `M5-CP3-TB1-R6-REV-OBS-01` — ORIGINAL R11-R1 DISPOSITION SUPERSEDED / REOPENED BELOW

R11-R1 originally treated reaching the semantically directed Forward -> Reverse construction path as direction-authority proof. The
subsequent Review amendment below supersedes only that observation disposition: CB12's source-ordering correction remains closed, but
the independent runtime direction observation is OPEN until row4 reaches the comparator and proves both agreement and inverted-pair rejection.

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
