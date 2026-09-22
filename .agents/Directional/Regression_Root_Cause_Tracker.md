## 2026-09-22 — `M5-CP3-TB1-R11-R1-EXEC`: complete retry confirms orchestration recovery but remains semantic RED — **444 PASS / 2 RED / NON-STABLE / +0**

**Stable totals remain 50 events / 14 categories / 36 recurrences. Produced-witness debt remains 3. Accepted runtime authority is unchanged.**

Fresh immutable retry run/job `35778555375 / 106917917282` consumes CB12 candidate
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. Result/log artifacts `10717297354 / 10717921412` verify provider/download
SHA-256 `d76dff757919a0c8bb139b6aa4d54840f5344fc9bf0b88f57a5d9629d3807656 /
c09c1c5797640e85ed485d5b6a034970a266c36fb0bbf488441be1674aff0cd0`. Result self-manifest is complete **912/912** at
`16dfe18019afee726ce2d2d1845187619c27c74bfa9ff238904237c7de3ab589`; orchestration failure is false and all prohibited-operation counters are zero.

The fresh semantic ledger is mechanism **9/9 PASS**, focused atlas **1/1 PASS**, produced **4/6 PASS**, selector430 **430/430 PASS**. Produced rows4/5 alone RED with exact `PeriodicActionCorrespondenceMismatch` before relation publication; row4 never reaches materialization/certificate assertions and row5 never reaches its transform tamper.

### `M5-CP3-TB1-R11-R1-CAND-01` — OPEN / semantic correspondence frontier after CB12

**Status:** OPEN / PRODUCT SEMANTIC RED / PERIODIC ACTION CORRESPONDENCE FRONTIER / FAILED RECOVERY / ROOT-CAUSE SUBPREDICATE UNRESOLVED / NON-STABLE / OWNER `M5-CP3-TB1-R11-R1-REV` / +0.

Root-cause analysis is bounded, not guessed. Candidate source now semantically selects the exact Forward interval copy as
`directedFirst` and Reverse copy as `directedSecond` before constructing the generator route/action. The typed runtime failure means
same-region pair validity, distinct occurrences, direction selection and generator-route availability have already succeeded. The
next guard fails because either `periodic_action_for_pair(...)` returns no exact action or the route/action rotations disagree.
That helper can fail source-chart presence, scale reciprocity, branch-rotation reciprocity or either exact lattice endpoint mapping;
current runtime evidence does not publish which operand failed. Mandatory Review must independently reconstruct those operands and
adjudicate whether CB12 is an insufficient correction of `M5-CP3-TB1-R10-REV-CAND-01` or whether a distinct product/test-authority root is now exposed.

No stable count changes: this is not a new accepted-green -> red transition, and root/category identity is not yet independently
adjudicated. Both nonzero-Z4 M5 debts remain open. Selector publication remains prohibited.

### `M5-CP3-TB1-R11-EXEC-CAND-01` — CLOSED / orchestration correction runtime-confirmed

**Status:** CLOSED / ORCHESTRATION RECOVERY CONFIRMED / NON-STABLE / +0.

Invalid R11 run/job `35771152416 / 106892972571` had self-included temporary `SHA256SUMS.new`, producing 913 rows for 912 real
evidence files and therefore no semantic ledger. CB13 corrected only the finalizer. R11-R1 now executes the entire same frozen gate
and its external-temp finalizer produces a fully verified **912/912** result with `driver_exit=0`; the deterministic self-inclusion
defect is therefore recovery-proved. Invalid R11 artifacts `10714199742 / 10715035437` remain historical provenance only.
