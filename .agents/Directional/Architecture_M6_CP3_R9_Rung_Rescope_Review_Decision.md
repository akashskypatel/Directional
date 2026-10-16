# Architecture Review Decision — M6 CP3 R9 rung re-scope (rung 19 did not execute)

**Review turn:** `M6-CP3-R9-RUNG-RESCOPE-REV`
**Adjudicated:** `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (rung 19)
**Frozen amendment:** RA-77
**Verdict:** **NO DELIVERABLE — nothing to adjudicate.** No acceptance, no rejection, no
charge. The rung is **re-scoped and re-issued as two**, and the over-scoping was mine.
**Review window:** 2026-10-16T10:45:12Z — 2026-10-16T11:02:36Z
**Semantic source:** unchanged at `f0d7240455b10237af47de58c035cd4c576d889a`

---

## RA-77.1 What rung 19 produced

Four commits, no work product:

| commit | effect |
|---|---|
| `c5121b3bf` | `STATUS` flipped to `IN_PROGRESS` (5 lines changed) |
| `2ee549827` | snapshot trigger added (3 lines) |
| `b34c57176` | same trigger removed (3 lines) — net zero |
| `ecb175b92` | **empty commit**, "checkpoint unfinished R9 contract turn" |

`git diff --stat c3e1e2948..HEAD` reports **`STATUS | 10 +++++-----`, one file**. No
specification document, no durable-document section, no source, test, selector, harness or
workflow change. `ledgers --base c3e1e2948` is clean because nothing was written.

**The turn did start properly.** Source-snapshot run `38888296894` and `38886874381` both
report `conclusion=success` at `b34c57176` and `2ee549827`, so authority was requested and
obtained before work stopped. The beacon was left `IN_PROGRESS` with
**`Successor: UNKNOWN`** — correct under RA-63.13 and **not self-referential**, so the
RA-76.6 charge is absorbed.

There is no document to verify, so there is nothing to accept, reject or charge, and this
decision is deliberately short. Manufacturing an adjudication of absent work would be its
own defect.

## RA-77.2 The scope was mine, and it was wrong

Rung 19 asked for four things, and the third was *"specify the contract the consumer should
require, and prove it is not a weakening — exhibit what it would still reject, concretely."*
That is a soundness argument. Every prior Definition turn in this ladder enumerated
producers (RA-71), applied the producer test (RA-72), named an authority (RA-75) or
classified candidates against an admissibility table (RA-75.6). **None was asked to prove a
predicate sound.** Bundling a mechanical census with a soundness proof in one turn violates
the standing instruction not to assign monolithic turns, and the right correction is to
split it rather than to re-issue it unchanged and expect a different outcome.

## RA-77.3 The split

The substance is unchanged; only the packaging is. Questions 1 and 2 are static reading of
the kind this ladder has delivered reliably — and rung 10 notably **improved** on a
reviewer-supplied census rather than merely completing one (RA-71.3), so the census half
plays to a demonstrated strength. Question 3 is design work that cannot begin until the
census exists, because the contract has to be written against the actual comparison sites.

| rung | turn | content |
|---|---|---|
| **19a** | `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` | former Q1 + Q2: enumerate every face comparison in the admission path with line anchors and classify each as *needs a face* or *a face was the available handle*; state precisely what the producers guarantee, including the RA-76.7 one-ULP caveat |
| **19b** | `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | former Q3 + Q4: specify the contract, prove it is not a weakening by exhibiting what it still rejects, and classify each candidate as repair or relocation under RA-65.5 / RA-72.5 — **scoped by 19a's census, not authorized until 19a is reviewed** |
| 20 | first repair-implementation rung | unchanged; **not authorized** |

## RA-77.4 Nothing else changes

`RP-01` remains exactly where RA-76.8 left it: every producer exonerated, the consumer's
endpoint-equivalence contract the sole remaining candidate, **code NOT authorized**. No
measurement was taken and none was due. `RP-02` **UNREACHED**. The ledger counts, the
frozen selector, the withdrawals and the gate-C suspension are all untouched, and
`R4-VIN-01` stays armed at `f0d724045` with no new semantic source.

## RA-77.5 LESSON — a turn that returns nothing is a scoping result

An empty turn is evidence about the instruction, not only about the executor. When a rung
produces no deliverable after acquiring its authority, the first question is whether it was
askable as posed. Here it was not: a census and a soundness proof are different kinds of
work and belong in different turns. **Recording the empty turn honestly and splitting the
scope is the correct response; re-issuing the same instruction is not.**

Credited: the turn checkpointed an unfinished state plainly rather than producing a
document it could not support, and left the beacon in the RA-63.13 shape.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by rung 19 or by this Review. PR #8
draft/open.

`R4-VIN-01` remains armed at `f0d724045`; every earlier artifact through `12035788036` and
`12036818514` is a **baseline, never a comparand**. The 44 RED remain the baseline for
`f0d724045` alone, candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED and CONFIRMED. Gate C
SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01` (RA-70.11).** `PROCESS-01` discharged.
`RP-03` is **not** advanced this rung — no result was reported, so the streak stands at
twelve and is neither extended nor broken. The historical `ledgers` failure at `b2b6e6541`
remains permanent for any earlier base, is correct, and must not be suppressed.

**Successor:** `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` (rung 19a).
