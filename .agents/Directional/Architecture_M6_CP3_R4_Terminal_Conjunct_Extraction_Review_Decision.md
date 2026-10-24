# RA-62 — `M6-CP3-TB2-R4-CONJUNCT-EXTRACT` review decision (2026-10-15)

Reviewer turn `M6-CP3-TB2-R4-CONJUNCT-EXTRACT-REV`. Accepts the extraction,
**names the measured mechanism with full provenance from repository bytes**, and
**locates `RP-01` precisely for the first time**.

Candidate/non-stable throughout. No promotion, no stable event, no regression
recurrence, no 497 execution, no gate credit. No source, test, selector, binary,
harness, workflow or benchmark change in this Review.

---

## RA-62.1 — The extraction is ACCEPTED, and it is the best-executed rung of this family

Artifact-only, from the pre-existing immutable artifact `11967601999` (provider
digest and independently re-verified ZIP SHA-256
`8b52373eebc7bda574f1fed2914dec4577ff70c670396f2ea3b19383d0fd25f1`, 50/50
manifest digests), original run
[38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279),
semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`. No dispatch, no compile, no
test execution, no benchmark, no selector change, no new runtime claim.

The partition matches RA-61's prediction **exactly**:

| Family | Count | Artifact indices | First failure |
|---|---:|---|---|
| Interior-shaped paired barycentrics | **23** | 1–11, 26–33, 38–39, 42, 45 | `no-exact-terminal-corner` |
| One-hot paired vertex barycentrics | **21** | 12–25, 34, 36–37, 40–41, 43–44 | `no-exact-terminal-corner` |
| Ordinal 405 | **1** | 35 | `missing-terminal-or-closed-rail-provenance` |

Four disciplines are worth recording explicitly. The turn **delivered the
three-conjunct truth table per published candidate**, which is precisely what
`RP-03` demands and what the measuring turn had omitted. It **refused to
over-claim**: *"the logs do not prove a canonical source vertex shared between
charts"* is exactly right, and the restraint is correct rather than timid. It
**kept ordinal 405 separate** and reported its distinguishing fact
(`ContactPresent=0`). And it **named a successor in the beacon**, ending the
two-turn run of `Successor: UNKNOWN`.

---

## RA-62.2 — DEFECT, repaired here: the handoff CURRENT section was overwritten in place

The handoff convention is accumulate-and-supersede — a new section is prepended
and says it supersedes the one *below*, which remains as authorizing history.
This turn's section correctly says *"Supersedes the previous CURRENT section
below"*, but the previous section — RA-61's, 23 lines — was **deleted** rather
than left below it. Net `4,419 → 4,411` lines.

**Neither gate catches this.** `Future_Chat_Session_Handoff.md` is not in the
`ledgers` coverage list (which carries the tracker, `.agents/CHANGELOG.md`,
`LESSONS.md` and root `CHANGELOG.md`), and `boundary`'s durable-marker check
reports `1 -> 1` because the durable-section heading
survives further down the file while the content above it is replaced.

**This is `ORIENTATION.md:1799` verbatim** — *"A guard that counts markers does
not protect content"*, recorded for `f6a784cf`, where a heading survived a
consolidation and `review_check.py` passed it as `durable markers preserved:
1 -> 1`. Fourth integrity event in this lineage, second in two turns, and on a
**different file** from the one protected last turn — which is the general
lesson: protecting one file by name does not protect the class.

**And the remedy was already named, in exactly the form adopted at RA-61.3.**
`ORIENTATION.md:1719` states that *"the effective guard is `review_check.py
ledgers --base <previous-review-commit>`, which scans committed history"* and
that the `boundary`-based guard *"was inert against committed overwrites"*. The
same entry records that `ce9bf3cb` also overwrote the agent CHANGELOG
(`0043dd4c`, 13,317 → 14 lines) and that **the first repair missed it**.
`:1799` already supplies the decisive test — ***if deleting the protected
content leaves the check green, the check does not cover that content*** — and
already tracks the residual as **`PROCESS-01`** (`LESSONS.md` 172). This turn's
handoff overwrite is a textbook instance, so the RA-62.2 mandate is filed
against `PROCESS-01` rather than opened as new.

**No RA-61 finding was lost.** The decision document,
`Architecture_M6_Frozen_Definitions.md`, `ORIENTATION.md`,
`Regression_Root_Cause_Tracker.md` and root `CHANGELOG.md` are all byte-unchanged
from `215698e0e` (verified). Only the handoff's resume chain was truncated, and
it is restored in this turn beneath the new section.

**Mandated for the next Code + Build rung, first item:** add
`Future_Chat_Session_Handoff.md` and `ORIENTATION.md` to the `ledgers` coverage
list, and replace `boundary`'s self-relative durable check with a **monotone
high-water floor**. Prose lessons have now failed three times.

---

## RA-62.3 — The one-hot vertex is **4**, derived exactly, with every measured truth value reproduced

The extraction correctly declined to name the vertex. The fixture settles it
with no run.

`make_disconnected_rectangular_feature_pair_mesh`
(`tests/SurfaceCellsPhase10Tests.cpp:223-264`) builds one 3×3 planar grid per
component, vertex index `y*3 + x`, and emits two faces per cell as
`(lowerLeft, lowerRight, upperRight)` then `(lowerLeft, upperRight, upperLeft)`.
Therefore:

```
face 0 = (0, 1, 4)        face 7 = (4, 8, 7)
```

The measured one-hot probes are `from 0:(0,0,1)` and `to 7:(1,0,0)`, so:

```
faces(0, 2) = 4        faces(7, 0) = 4
```

**Both charts designate vertex 4.** The rail is the chain **1 – 4 – 7**
(`:6315-6318`, `userHardEdges {1,4}` and `{4,7}`), its published terminals are
`{1, 7}`, and its **interior junction vertex is 4**.

Recomputing the probe predicate from this face table reproduces all four
measured values for subset A exactly:

| candidate | `railEnd[v]` | `corner[v]` | measured |
|---|---|---|---|
| v = 1 | 1 (on carrier `(1,4)`) | 0,0 (point is at 4, not 1) | matches |
| v = 7 | 0 (not on carrier `(1,4)`) | 0,0 | matches |

`railEnd[7] = 0` is also the first **measured** confirmation of **RA-60.6**: at
`routeLength = 1` the carrier touches terminal 1 but not 7, so terminal 7 cannot
be attached in these fixtures. That was inferred at RA-60; it is now observed.

---

## RA-62.4 — Mechanism named: a **junction-terminated front**, a third shape with no certificate at all

The front occupies exactly one carrier edge `(1,4)` and terminates at vertex 4.
It is **not** a terminal front — no exact corner at 1 or 7 — and **not** an
interior front — strictly one-hot, so not interior to the carrier. Both branches
of `endpoint_certificate` therefore refuse it, each correctly.

RA-60.2 recorded that *"a front ending exactly at the rail's interior junction
vertex 4 is rejected, not absorbed"* and offered it as reassurance that RA-41's
junction clauses stayed outside the repair's scope. The measurement shows that
same configuration is **the actual failure mode of 15 of 44 identities**, and on
the shared evidence shape almost certainly all 21. A clause filed as a dormant
backlog item is the live defect for roughly a third of the measured population.

---

## RA-62.5 — PRINCIPAL: this is `RP-01` in its exact canonical form — rail-level authority answering a carrier-level question

`SurfaceHardRailTerminalContacts` is
`std::map<authority::HardRailId, SurfaceHardRailTerminalContact>` and each
contact carries exactly **two** endpoints **per rail**
(`include/directional/geometry/SurfaceCellTracing.h:1530-1535`). Terminal
authority is therefore **whole-rail**: rail 1–4–7 publishes `{1, 7}` and nothing
else.

`endpoint_certificate` then tests a **carrier-edge-level** endpoint against that
**rail-level** set (`src/geometry/SurfaceCellTracing.cpp:19214-19217`):

```cpp
for (const auto vertex : contact->second.endpoints) {        // rail-level {1,7}
  if ((edge.first() != vertex && edge.second() != vertex)   // carrier-level (1,4)
      || !exact_corner(fromPoint, vertex)
      || !exact_corner(toPoint, vertex)) continue;
```

The conjunction can succeed only when the carrier edge happens to contain a
whole-rail terminal **and** the front endpoint sits exactly on that same
terminal. For a **multi-edge rail**, a front occupying one carrier edge
**structurally cannot** satisfy it at the junction end — no input value can
rescue it, exactly as RA-61.6's closure gate could not be rescued.

There is no per-interval terminal vocabulary, although rail **intervals** exist
and are already consulted by the publisher (`find_rail_interval(railBuild.intervals, …)`
at `:12610`). **Two authority domains are conflated in one predicate.** This is
`RP-01 AUTHORITY_DOMAIN_CONFLATION`, located precisely and with a measured
population for the first time since it was opened.

---

## RA-62.6 — RA-59.9 picked the wrong shape for half the population, and that is the reviewer's error

"Half-terminal front" was directionally right — one end at a terminal, one end
not — but RA-59.9 identified the non-terminal end as **interior to the carrier
edge**, when in 21 of 44 cases it sits **exactly at the carrier edge's other
vertex**. RA-60 then specified and verified a certificate for the 23-case shape,
whose gate is unsatisfiable (RA-61.6), while the 21-case shape received nothing
at all.

Three shapes, three distinct states:

1. **Interior-to-carrier** (23) — a certificate shape exists; its admission gate
   is dead (RA-61.6, RA-61.7).
2. **Junction-vertex** (21) — **no certificate shape exists**; the genuine
   domain gap (RA-62.5).
3. **Ordinal 405** (1) — no terminal contact published at all
   (`ContactPresent=0`); a separate A2b provenance defect, still not to be
   folded into either family.

---

## RA-62.7 — The locus count collapses from ≤22 to **2**

All 23 interior-shaped cases record the **identical** probe pair, and all 21
one-hot cases record the **identical** probe pair. So 44 identities exhibit
**two** geometric configurations — not 44, and not the ≤22 RA-59.11 allowed.
RA-59.11's direction was right and the report's 39-corroboration framing was
wrong, but the bound itself was still an order of magnitude too generous.

Subset **B** (6 cases, carrier `(1,2)`, candidates 1/6, indices 15–19 and 25) is
the same junction mechanism in a different fixture, on the identical evidence
shape — `railEnd[first]=1, corner[first]=0,0`; `railEnd[second]=0,
corner[second]=0,0`. **Its vertex is not derived here and must not be assumed.**

---

## RA-62.8 — A hypothesis formed and discarded before it entered the record

Because the front publisher cuts runs at source-edge topology changes, it was
momentarily plausible that a route could never carry ≥2 steps — which would make
RA-41's junction clauses permanently unexercisable and the RA-59 construction
recipe impossible.

Reading the accumulation refutes it. `observedSteps` is declared **once** before
the segment loop (`:12505`), pushed inside it (`:12546`, `:12566`), checked
non-empty after it (`:12672`), and assembled into a single route at
`:12684-12685`. It therefore collects **one step per run across the whole front
path**, so a front spanning both `(1,4)` and `(4,7)` **would** yield
`routeLength = 2` and **would** exercise the junction loop
(`routeSteps = first.route.oriented_steps()`, `:19096`).

**The RA-59 recipe stands.** The observed `routeLength = 1` is a fact about the
traced front, not a publisher limitation — which relocates the open question
upstream: why does the field-traced front stop at vertex 4 instead of continuing
along `(4,7)`? Recorded as the leading upstream question for A1/A2a. **Not
authorized for probing** (RA-54.7).

---

## RA-62.9 — The predicate-separation rung survives, but its justification has shifted and its scope is re-prioritized

RA-60.5 authorized it because a *repeat* of `no-exact-terminal-corner` would be
uninterpretable. The extraction has now disambiguated the **entire** population
from logs that already existed, using `corner[]`/`railEnd[]`. String separation
therefore is no longer the rung's primary value.

Two fields that are **not** obtainable from existing logs now dominate:

- **(b) the actual one-hot vertex identity.** The probe emits `corner[v]` and
  `railEnd[v]` only for *published terminals*, so it never states which vertex
  the point actually is. That omission forced a hand derivation of the fixture's
  face table in this Review (RA-62.3). Emitting it is diagnostic-only and
  decision-neutral, and it would have made RA-62.3 unnecessary.
- **(a) `sharedBoundaryInterval` presence and exact rational ordinals** —
  RA-61.9 falsifier (i), unanswerable from any existing artifact.

The published name `M6-CP3-CB2-R4-PREDICATE-SEPARATION` is **kept** — renaming
for taste would churn a beacon already committed — but the scope is re-ordered
**(b), (a), then the string split**. Strictly decision-neutral: not one
acceptance or rejection decision may change.

---

## RA-62.10 — Accounting, carried obligations, and the next rung

Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, CP2
**491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses),
frozen selector **30 + 12 + 449 + 6 = 497** — all unchanged. No accepted-green
loss and no ledger credit: all 39 census identities were already RED under the
prior semantic source and the six supplementals have no accepted-GREEN baseline.
PR #8 draft/open. The handoff overwrite in RA-62.2 is an **integrity** defect and
does **not** increment the regression recurrence counter.

`R4-VIN-01` continues to apply: `570c5173…` is a new semantic source, so every
prior measurement is a baseline, never a comparand.

**`RP-01` is now located** (RA-62.5) but **not repaired** and not authorized for
repair. `RP-02` remains **unreached** — neither the network-bound consumer nor
its tamper half has executed. `RP-03` carried; this turn's extraction satisfied
it and the measuring turn before it did not.

Carried without probe: RA-60.5 (triggered, now re-scoped by RA-62.9); RA-60.6
(**confirmed by measurement**, RA-62.3); RA-60.7 encoding collapse needing a
positive discriminator; RA-60.8 comment mismatch; RA-60.9's four untested
negatives; RA-61.9's two falsifiers; the RA-58.7 A5/A6/A7 loci and `R4-OHF-02`;
the two RA-57.9 guards; **RA-41's junction/sector clauses — no longer dormant,
now the measured mechanism of 15–21 identities, recipe intact per RA-62.8**;
ordinal **405**; 34 Phase10 / seven DCEL / six CP3 identities; CP2 restorations
outside the 37; organic D1/D2/D3/D5 and A6/A7 witnesses; the odd-τ witness; the
two `SurfaceCellTracingPhase14` identities needing a separately packaged
historical executable (`cmake/DirectionalTests.cmake:554-572`).

**Next rung — `M6-CP3-CB2-R4-PREDICATE-SEPARATION`**, diagnostic-only Code +
Build, scope ordered by RA-62.9, plus the RA-62.2 gate-coverage fix as its first
item. **No acceptance behaviour may change, and neither the RA-61.9 remedy nor
any repair of `RP-01` is authorized in it.**
