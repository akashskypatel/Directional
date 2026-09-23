## 2026-09-23 — `M5-CP3-TB1-R12-EXEC`: CB14 candidate is mechanically valid but semantic RED at 439/446; Review next

Fresh immutable run/job `35802519951 / 106995887964` consumes CB14 candidate/source
`10725395682 / b8dc3e906dd03525861a1985ea574bad1ad5c69a`. Result/log artifacts `10726868409 / 10726518857` hash to
`3f5978b7e0753dccd68fa53ddc50e50b3a5d4d3ea61d2bbd6e9da688531877bc / 146fa160681f012c10979eb8018f6b91e1ad41b2ce5ef5c02c70dc0f36a9d265`;
result evidence is complete at **912/912** and immutable postflight is exact.

All **446/446** planned exact-filter processes select once with zero skips: mechanism **9/9**, focused **1/1**, produced **0/6**,
selector430 **429/430**, benchmark 0. Produced rows1/2/3/6 regress from R11-R1 green to `InvalidFinalCellState`; rows4/5 remain at
`PeriodicActionCorrespondenceMismatch`; protected selector ordinal408 regresses to RED while 191/192/247 remain PASS.

Tracker candidates `M5-CP3-TB1-R12-CAND-01` and `-02` separate failed nonzero-Z4 recovery from the newly exposed zero-rotation/direct
production regression. Stable accounting remains **50 / 14 / 36**, debt **3** pending independent Review; accepted runtime remains
unchanged, candidate unpromoted and selector publication prohibited. Exact successor is runtime-free `M5-CP3-TB1-R12-REV`.

## 2026-09-23 — `M5-CP3-CB14`: periodic relation endpoint-gauge authority correction compiles cleanly; R12 next

Runtime-free Code + Build. CB14 records and implements the pre-mutation derivation `q=rotate(G,c)`, with `G=I` for zero generator
rotation and `G=B` (the endpoint's own exact branch rotation) for nonzero transport. Ordinary `LocalLatticeState` cell placement is
unchanged. New typed `SurfacePeriodicRelationEndpointState` carries the relation-owned coordinate plus branch/scale/source-chart/A3
occurrence/orientation/generator rotation; producer action construction and checked-product validation use/rederive that same authority.
No partner fitting, endpoint rewrite, inverse retry, transform search, field/fixture/A3 retuning or selector change was introduced.

The first compile-only attempt exposed one agent mistake in the new focused test: `DomainResult<T>` was used with `*` although its
interface requires `.value()`. The bounded same-turn repair changed only those six test expressions. No generated Directional binary
ran in either attempt.

Final compile/package run/job `35798853372 / 106984376759` on exact source `b8dc3e906dd03525861a1985ea574bad1ad5c69a` is green.
Candidate result/log `10725395682 / 10725570501` hash to
`1995b8cf3de6190bff60f0e8d4ad74de90cc82327b80fd5c29f2fc0eb089d902 / e2393d77f6ab0ac324e13f793975ccede0702156e40d922b14fb528d77940a40`;
package manifest is **28/28**, GMP/GMPXX is linked, all eight required targets compile/link, source-status receipts are empty and
`runtimeExecution=false`. Candidate stays unpromoted; accepted runtime, stable accounting **50 / 14 / 36**, debt **3**, and selector
publication state are unchanged. Exact successor is fresh artifact-only `M5-CP3-TB1-R12-EXEC`, then mandatory Review.

## 2026-09-22 — `M5-CP3-TB1-R11-R1-REV` review: upheld; direction observation reopened

Runtime-free review. **Upheld with one disposition reversed.** Accounting holds at **50 events / 14 categories /
36 recurrences**, debt **3**; selector430 **430/430** with protected ordinals **191/192/247/408** PASS and
produced rows 1/2/3/6 PASS, so the two debts discharged at R7 and the §16 `R = 0` reduction are intact.

**`M5-CP3-TB1-R10-REV-OBS-01` discharged.** The result self-manifest is **912/912** — the driver finalization
ordering is fixed, and the rule was satisfied before the publication gate rather than under pressure at it, which
was the point of recording it early. CB12's directed ordering is also verified in source at
`SurfaceCellTracing.cpp:17229-17241`: `directedFirst`/`directedSecond` are bound by exact A3 `Forward`/`Reverse`
orientation, with the unordered pair used only for membership, so `M5-CP3-TB1-R10-REV-CAND-01` is rightly closed.

**Reopened: `M5-CP3-TB1-R6-REV-OBS-01`.** §2 discharged it because the subject "now reaches the exact
semantically directed Forward → Reverse construction path." But §3 of the same Review correctly discounts
`action.rotation == generatorRoute.rotation` and item 4's endpoint mapping as *true by construction* and
therefore non-probative — which is exactly why item 5 is a real localization. By that same standard, reaching the
directed construction path proves the ordering code executes, not that the ordering is correct. The observation
required the action checked against an expectation derived independently of the face order that produced it, and
an inverted pair failing; rows 4/5 stop at item 5, before the comparator, so neither has been shown. An inverted
ordering yielding a mirrored but self-consistent action would look identical to this evidence. Recorded as
`M5-CP3-TB1-R11-R1-REV-OBS-01`; nothing else in the Review depends on the discharge.

The item-1-to-5 predicate walk is otherwise the right kind of diagnosis — labelling which predicates are
tautological is what makes the second endpoint mapping a genuine localization rather than another guess, and
CB14's cut-domain-coordinate target follows algebraically from it.

Exact successor: `M5-CP3-CB14` — periodic seam lattice gauge authority correction.

## 2026-09-22 — `M5-CP3-TB1-R11-R1-REV`: CB12 direction recovery proved; periodic endpoint-gauge authority defect localized

Runtime-free Review independently upholds R11-R1 run/job `35778555375 / 106917917282`, complete result self-manifest **912/912** and the fresh **444 PASS / 2 RED** vector. CB12's exact A3 Forward -> Reverse selection is storage-order independent, closing `M5-CP3-TB1-R10-REV-CAND-01` recovery-proved and discharging the R6 direction observation.

The remaining `PeriodicActionCorrespondenceMismatch` is split exactly. The action helper's source-chart/scale/branch preconditions and first endpoint mapping pass; the second endpoint mapping is the first false predicate. On the accepted `[0,1,2,3]` rectangle, reciprocal copies have raw cell-grid `d2=-d1`, so frozen nonzero `rotate(R,d1)==-d2` becomes impossible `rotate(R,d1)==d1`. The root is existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: cut-domain cell placement is being used as quotient-seam endpoint authority.

Stable accounting remains **50 / 14 / 36**, debt **3**; accepted runtime unchanged, CB12 candidate unpromoted and selector publication prohibited. Exact successor `M5-CP3-CB14` is runtime-free and must preserve cell placement while deriving independent relation-owned endpoint-gauge authority before fresh R12.

## 2026-09-22 — `M5-CP3-TB1-R11-R1-EXEC`: complete 446-process retry is authoritative semantic RED; Review next

Fresh immutable run/job `35778555375 / 106917917282` consumes CB12 candidate/source
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. Result/log `10717297354 / 10717921412` verify ZIP SHA-256
`d76dff757919a0c8bb139b6aa4d54840f5344fc9bf0b88f57a5d9629d3807656 /
c09c1c5797640e85ed485d5b6a034970a266c36fb0bbf488441be1674aff0cd0`; corrected self-manifest is **912/912** at
`16dfe18019afee726ce2d2d1845187619c27c74bfa9ff238904237c7de3ab589`, proving CB13's orchestration correction on the full evidence shape.

All **446/446** fresh exact-filter processes select once with zero skips: mechanism **9/9**, focused atlas **1/1**, produced
**4/6**, selector430 **430/430**, benchmark 0 and exact immutable postflight. Produced rows4/5 alone stop while constructing the
nonzero-Z4 witness at exact `PeriodicActionCorrespondenceMismatch`; row4 never reaches materialization/certificate checks and row5
never reaches its transform tamper. The observed frontier is after CB12's Forward -> Reverse pair binding and generator-route
availability, but the product reason merges action-construction failure with route/action rotation disagreement, so exact root
adjudication is reserved for mandatory `M5-CP3-TB1-R11-R1-REV`.

`M5-CP3-TB1-R11-R1-CAND-01` is OPEN / PRODUCT SEMANTIC RED / non-stable / +0 pending Review. Stable accounting remains
**50 / 14 / 36**, debt **3**, accepted runtime unchanged, candidate unpromoted and selector publication prohibited. Invalid R11's
self-manifest candidate closes as orchestration recovery-confirmed; its runtime rows remain zero-credit provenance.

## 2026-09-22 — `M5-CP3-CB13`: result-manifest orchestration correction validates runtime-free; R11-R1 next

CB13 is control-plane-only and runtime-free. The retry finalizer moves its temporary manifest outside the result tree, preserves
`driver-authority.txt` copy-before-manifest ordering, verifies the complete manifest fail-closed, and independently requires
manifest-row/non-manifest-file equality. Retry SHA-256 authorities are frozen in the retained R11-R1 plan and materialized through
`write_orchestration_payload.py`; the workflow contains no raw 64-hex digest literals.

Validation run `35775766068` is GREEN: retry/self schema jobs `106908450647 / 106908451034` and static/synthetic job
`106908512994` all pass. Result/log artifacts `10716415780 / 10716260918` hash to
`e8a3d09981e6eb22df70325741bb265cc2f81cc141c507f6f1577e1e8efeb20b /
f1cfbc376c05be90da52f7e6660eb86589ec79578e3f0aba35a44e01b10df88b`. Synthetic baseline is 3/3 and both checksum
corruption and late-file count mismatch are detected. The retry driver is identical to historical R11 except for turn ID and
still freezes 446 fresh processes / benchmark 0. No Directional executable ran. Candidate/runtime/accounting/debt remain
unchanged; exact next is fresh `M5-CP3-TB1-R11-R1-EXEC` with zero semantic carry-forward from invalid R11.

## 2026-09-22 — `M5-CP3-TB1-R11-EXEC`: runtime attempt invalidated by self-including result-manifest finalizer

R11 run/job `35771152416 / 106892972571` consumes unchanged CB12 candidate/source
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. All 446 planned exact-filter processes run and immutable runtime
postflight completes, but the wrapper creates `SHA256SUMS.new` inside the directory before `find` enumerates it. Final
evidence is therefore **913 manifest rows for 912 actual non-manifest files**, with only stale `./SHA256SUMS.new` failing.
Result/log artifacts are `10714199742 / 10715035437` at SHA-256
`26b0d4aa711fa1481f45d6eb4dc8dc0d605126abb08fa744a6843f958df1f23e /
aa80f1859fce582fdba8a0a7e31c6d8a5edae3c0e521b800171a1af8494b3d7f`.

Per orchestration cadence this attempt has no semantic ledger despite preserved diagnostic 444/2 raw rows. Stable accounting
remains **50 / 14 / 36**, debt **3**, accepted runtime unchanged, candidate unpromoted. Exact successor is control-plane-only
`M5-CP3-CB13`, then fresh `M5-CP3-TB1-R11-R1-EXEC` from process 1 if static/schema validation is green.

