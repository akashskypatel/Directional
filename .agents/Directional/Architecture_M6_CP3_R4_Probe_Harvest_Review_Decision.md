# Architecture Review Decision — `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` + `M6-CP3-TB3-R4-PROBE-HARVEST`

**Review turn:** `M6-CP3-TB3-R4-PROBE-HARVEST-REV`
**Date:** 2026-10-15
**Amendments frozen:** RA-64.1 … RA-64.12
**Adjudicated commits:** `5932d5937` … `1663e8527` (nineteen commits; `6a0587580..HEAD`)
**Verdict:** **BOTH ACCEPTED.** The content-floor fix is verified by independent simulation and
closes RA-63.7. The harvest is a clean, complete, immutable measurement that **falsified half of
this reviewer's recorded prediction** and reported the contradiction plainly. No open
REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no gate credit.

---

## RA-64.1 — Authority re-derived, not accepted

**Harvest.** Run [38756316813](https://github.com/akashskypatel/Directional/actions/runs/38756316813)
`conclusion: success`, `headSha d31a241af` (the dispatcher commit). Result artifact
**`11982824436`** present, 76,926 bytes, name matching. Harness SHA-256 recomputed on disk:

```
bec126c4b4fc835c92de2ae39c6e36295721227549aa6b4ca84178c88fea040a
```

— **byte-identical to the SHA the report claims**, so the harness that ran is the harness
committed. The measured package is the pre-existing immutable `11976790988` from the already
adjudicated compile `38743048456`, at semantic source `16c3134c0`, which RA-63.1 proved
byte-identical to HEAD's `src` tree. **No new compile, no relink, no selector change, no
benchmark, no 497.**

**Non-mutation.** `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` untouched across both
turns; only `tools/review_check.py`, the new harness, the dispatch descriptor and documents
changed. `TODO.md` and the agent CHANGELOG grew; the handoff grew 4,495 → 4,502 by **prepending**,
with history retained.

## RA-64.2 — The content floor is implemented, and verified by simulation rather than by reading

RA-63.7 proved by simulation that the previous guard returned green on an equal-size overwrite.
The same discipline is applied here to the fix. Four simulations, each in a throwaway
`git worktree add --detach`, **nothing committed**:

| simulated defect | line floor | heading floor | gate |
|---|---|---|---|
| **A** equal-size whole-file overwrite, marker retained, sections 302 → 1 | `4502 >= 4502` PASS | **`1 >= 304` FAIL** | **caught** |
| **B** legitimate prepend | `4507 >= 4502` PASS | `305 >= 304` PASS | passes |
| **C** three headings replaced by body lines, **line count unchanged** | `4502 >= 4502` PASS | **`301 >= 304` FAIL** | **caught** |
| **D** line *and* heading counts preserved, every body line replaced | PASS | PASS | **not caught** |

**Shape A is the defect RA-63.7 recorded as uncaught; it is now caught.** Shape C shows the floor
catches a *partial* deletion that leaves the file the same length, which is stronger than
specified. The implementation also improved on the specification: one blob read per revision
supplies **both** floors, where the naive reading of RA-63.8 would have doubled the subprocess
count. Items 2–4 of the mandate all landed: the tracker's exemption is gone
(`protected_history = path in DURABLE_FILES`, `review_check.py:238`), both floors assert
`> 0` against `history_valid` so a total read failure can no longer pass vacuously
(`:206-211`), and the consumed Drive descriptor was reset to a no-op.

**Shape D is the honest residual and this Review declines to mandate more.** A rewrite that
preserves both counts *and* every heading's text, replacing only body prose, still passes.
Catching it needs per-section content hashing — a different and much heavier design. Every one of
the **six** observed integrity events (RA-63.10) collapsed the file and is now caught by shape A
or C. The turn's own report states this limit in its own words — *"these checks do not prove
arbitrary content integrity, only the explicitly authorized high-water properties"* — which is the
correct epistemic posture and the opposite of over-claiming. **`PROCESS-01`'s tooling residual is
discharged for every observed failure mode.** Escalating the guard further would be scope the
evidence does not support.

One behaviour change worth recording rather than fixing: a durable file with **no** committed
history now **fails** (`history_valid` requires a non-empty revision list) where it previously
reported `(new file)` and passed. For the three long-committed protected files this never fires,
and failing loudly on an unestablished floor is the right default.

## RA-64.3 — This reviewer's recorded prediction was half right and half wrong

RA-63 put a prediction on record with its provenance: *subset A must emit
`a2bProbeFromSourceVertex=4` and `a2bProbeToSourceVertex=4`, and report
`one-hot-carrier-junction`.*

| claim | measured | verdict |
|---|---|---|
| subset A source vertex `4/4` | `4/4`, 15 cases | **CONFIRMED** |
| subset B vertex not to be assumed | **`2/2`, 6 cases — measured, not assumed** | discharged |
| first failed condition `one-hot-carrier-junction` | **`carrier-orientation`, all 21** | **FALSIFIED** |

**The vertex half is confirmed and the condition half is wrong, and the error is this
reviewer's.** `one-hot-carrier-junction` sits at rung 4 of the ladder; all 21 one-hot identities
stop at **rung 3**. The prediction named a *value* without checking that execution would ever
*reach* the rung that produces it — the same structural mistake as RA-61.7, one step along: there
the predicate was faithful but unsatisfiable, here the predicted label is correct but unreachable.

**RA-64.12 (new lesson): a prediction must name the rung at which it will be observed, not only
the value it will take.** Fourth member of the RA-61.5 (provenance) / RA-61.7 (satisfiability)
family: **reachability**.

The 23 interior identities report `not-same-interior-carrier-point`, so rung 3 **passed** for them.
The two subsets are therefore separated by exactly one conjunct — whether carrier orientation holds
— which independently corroborates the 23/21 partition from a direction RA-62 never used.

## RA-64.4 — PRINCIPAL: the first gate to fail is a third expression of the same granularity error, re-derived from the fixture with no run

`oriented_carrier` (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) returns a value only when
`{from, to}` **is** the carrier record's own face pair:

```cpp
if (record.firstFace == from && record.secondFace == to) return record;
if (record.firstFace == to && record.secondFace == from) return <flipped>;
return std::nullopt;
```

Recomputing `make_disconnected_rectangular_feature_pair_mesh`
(`tests/SurfaceCellsPhase10Tests.cpp:223-264`) gives, for one component:

```
face 0 = (0,1,4)   face 1 = (0,4,3)   face 2 = (1,2,5)   face 3 = (1,5,4)
face 4 = (3,4,7)   face 5 = (3,7,6)   face 6 = (4,5,8)   face 7 = (4,8,7)
edge (1,4) -> faces {0,3}        edge (4,7) -> faces {4,7}
```

The measured endpoint faces are **{0, 7}**. The carrier is edge **(1,4)**, whose face pair is
**{0, 3}**. **Face 7 is not incident to the carrier edge at all** — it belongs to the rail's
*other* edge (4,7). So `oriented_carrier` is **structurally unsatisfiable** for subset A, by the
fixture's own face table, with no execution.

**Three expressions of one granularity error now sit in the same rejecting conjunction, and this
is the one that fires first:**

1. **rail-level terminal set ← carrier-edge question** (RA-62.5) — never reached for the 21.
2. **edge-record interval ← endpoint question** (RA-63.5) — reached, and satisfied by everything
   (RA-64.5).
3. **single-carrier-edge face pair ← junction-straddling endpoint faces** (new) — **the actual
   first failure for 21 of 44.**

The practical consequence reorders the repair entirely: **the terminal-contact set is not the
first thing to fix.** The certificate's prior premise — that a front's two endpoint trace points
lie in the two faces of *one* carrier edge — is false for every junction-terminated front, and no
terminal vocabulary rescues a conjunction that has already returned `nullopt`.

## RA-64.5 — The interval witness is satisfied 44/44, which is stronger than the type argument

Measured: **both** shared-boundary intervals present in all 44, **equal spans** (span `3` in 38,
span `2` in 6), and **exactly reciprocal ordinals** throughout — `0/1 → 1/1` against `1/1 → 0/1`
for the 23 interior identities, `3/1 → 4/1` against `4/1 → 3/1` for the 21 one-hot. Lossless
exact rationals, as RA-63.4 required.

So the conjunct RA-61.9 proposed to rest endpoint identity on is **true for every single rejected
identity in the population**. RA-63.5 argued from the record's field list that it *cannot* pin the
point; the measurement shows it *does not* discriminate anything at all.

The precise consequence, stated without inflation: RA-61.9 retained strict interiority, which the
21 one-hot identities fail, so it would not have admitted those. It would have admitted **the 23**
— on a warrant that is equally true of the 21 it still rejects. The work would have been done by
**interiority, a double comparison**, while an **exact rational** was presented as the
justification. That is worse than the dead gate it replaced, which at least failed closed and
visibly. **The withdrawal of RA-61.9 is confirmed by measurement and is final.** The report reaches
the same conclusion in its own words — *"the edge-record interval relationship is not an endpoint
identity certificate"* — and correctly declines to treat its own data as authorization.

## RA-64.6 — NEW: the route under-reports the front's extent, and the measurement does not say why

RA-62.8 established that `observedSteps` accumulates one step per run across the whole front path,
so `routeLength = 2` is representable, and concluded that the observed `routeLength = 1` is "a fact
about the traced front". That conclusion now needs refinement, because the **geometry already
spans the junction**: the route reports **one** step (carrier `(1,4)`) while the endpoint faces
`{0, 7}` require **two** carrier edges, `(1,4)` and `(4,7)`.

Two readings remain open and **this measurement decides between neither**:

- **(i)** the A4 publisher cut a run that should have been a single route of two steps, so the
  route is wrong and the trace points are right; or
- **(ii)** a single-step route may legitimately carry endpoint trace points in faces outside its
  carrier, in which case the certificate's face-pair premise is simply the wrong question.

Under **(i)** the RA-59 two-topology recipe may already be **latently satisfied by the geometry**
while the route disagrees. Under **(ii)** RA-64.4 is the whole defect. Distinguishing them is the
first question the specification rung must answer, and it must be answered **from the publisher's
own bytes**, not inferred from the type — the discipline RA-63.5 earned. **Neither reading is
authorized as a conclusion here.**

## RA-64.7 — Harness compliance verified against the standard applied at RA-61

156 lines. Pinned artifact id and source SHA (`:11`); provider digest and artifact digest checks
(`:19`, `:21`); manifest SHA pinned with a `28`-OK count assertion (`:24-26`);
`source-commit.txt` identity (`:27`); `exactArithmeticBackend=GMP` and `runtimeExecution=false`
assertions (`:28-29`); packaged source hash pinned (`:31`); frozen selector hashes (`:38`);
pre-snapshots `p0`/`s0`/`v0` (`:40-44`); census inventory pinned by SHA with **39 identities and
an explicit duplicate assertion** (`:46-51`); ordinal **405** excluded by an explicit `continue`
with the reason in the comment (`:56`); `NOT_SELECTED` paths increment `missing` and `continue`
(`:74-76`, `:112-113`); `planned == 44` assertion (`:120`); post-snapshots with three `cmp`
immutability checks and a postflight manifest (`:145-151`); and the closing
`[[ "$executed" == 44 && "$missing" == 0 && "$postflight" == true ]] || die` with `exit 0`
(`:155-156`). 39 census − 405 + 6 supplemental = **44**, matching the table's 23 + 21.

The extraction parser deserves specific credit: it regex-matches each field per raw log, writes an
**empty string** when a field is absent, and sets `probe_emitted = int(any(values))`, so a missing
probe is **visible rather than synthesized** — the comment says exactly that. One cosmetic
residual: the final `die` message still reads `'incomplete interior-witness measurement'`, a label
copied from the RA-61 harness. Zero impact; not worth a turn.

## RA-64.8 — Reporting conduct: a contradicted prediction was reported plainly

RA-63's mandate said: *"If it does not, say so plainly — do not reconcile it."* The harvest
reported `carrier-orientation` for all 21, which contradicts the reviewer's recorded prediction,
**without reconciling, hedging or relabelling it**, and without claiming the vertex result
licensed anything it did not. It also kept 405 out of the 44 with its reason stated, called its own
RED set an `R4-VIN-01` **baseline** rather than a regression, and wrote *"independent Review
required before deciding an implementation successor."* **This is the standard of reporting the
family has been asking for since RP-03 was opened, and drawing the consequence of the
contradiction is this Review's job, not the measuring turn's.**

## RA-64.9 — A disclosed transport failure, with its byte-divergence caveat volunteered

The content-floor turn's authorized Google Drive transport failed with
`container_session_unavailable`; the turn fell back to direct repository writes **and said so**,
volunteering that the downloadable patch's documentation bytes may differ from the written records.
Three identical `Record R4 Python heading-floor verification…` commits (`af81e3624`,
`add0f44c7`, `0c4a2b369`) are that retry sequence and are harmless. Disclosing a transport
substitution and its exact consequence, unprompted, is the behaviour this process depends on.

## RA-64.10 — Beacon defect: a self-referential successor

The beacon closed `Status: IN_PROGRESS` with `Ended at:` blank and
`Successor: M6-CP3-TB3-R4-PROBE-HARVEST` — **the turn naming itself as its own successor**. RA-64.1
establishes the measurement actually completed, so `IN_PROGRESS` is stale. A self-referential
successor is **worse than the reasoned `UNKNOWN` accepted at RA-63.13**, because `UNKNOWN` signals
absence while this asserts a successor that cannot be executed. The report's own prose has the
correct content — *"independent Review required before deciding an implementation successor"* —
so this is an encoding failure, not a reasoning failure. Closed here with a named successor.

## RA-64.11 — Next rung: the specification is authorized; the code still is not

Through RA-62 and RA-63 the repair was withheld because no specification existed. Three measured
expressions of one granularity error, a 44/44 population, two exactly-characterised subsets and
one named open question are now enough to write one. **`M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` is
authorized to produce a specification and nothing else** — no C++, no compile, no tests, no
instrument change. Its binding obligation, carried from RA-61.7 and sharpened by RA-64.12: **every
proposed predicate must be accompanied by its satisfiability witness and its reachability witness
against the measured 44**, stating which identities it would admit, which it would still reject,
and at which rung each is decided. A predicate whose admitting set is not exhibited against this
population is not a specification.

---

## Accounting

No source, test, selector, binary, harness, workflow or benchmark change in this **Review**; no
Directional binary executed. Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt
**1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses), frozen
selector **30+12+449+6=497** — all unchanged. The 44 RED are the **`R4-VIN-01` baseline** for
semantic source `16c3134c0`, **never a comparand** against artifact `11967601999` or any earlier
measurement. No accepted-green loss, no ledger credit, no promotion, no stable event, no regression
recurrence, no 497 execution, no gate credit. PR #8 draft/open.

**Open:** `RP-01` located, **three expressions**, not repaired — **specification now authorized,
code still not**; `RP-02` **UNREACHED**; `RP-03` satisfied and exemplified (RA-64.8);
**`PROCESS-01` tooling residual discharged for every observed failure mode** (RA-64.2), with the
shape-D residual recorded and deliberately not escalated.

**Confirmed by measurement:** subset A vertex **4**; subset B vertex **2** (measured, not assumed —
backlog item discharged); RA-63.5's edge-level witness is satisfied **44/44**; **RA-61.9 withdrawn,
final**.

**Falsified:** RA-63's `one-hot-carrier-junction` prediction (RA-64.3). **Refined:** RA-62.8's
`routeLength = 1` conclusion (RA-64.6).

**Successor:** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` — specification only.
