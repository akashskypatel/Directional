# Architecture Review Decision — `M6-CP3-CB2-R4-PREDICATE-SEPARATION`

**Review turn:** `M6-CP3-CB2-R4-PREDICATE-SEPARATION-REV`
**Date:** 2026-10-15
**Amendments frozen:** RA-63.1 … RA-63.14
**Adjudicated commits:** `e8313283a` … `78a4b4060` (eleven commits; `700d6418f..HEAD`)
**Verdict:** **ACCEPTED.** Both mandated diagnostic payloads are correct and lossless, and the
source edit is decision-neutral by construction. The RA-62.2 integrity fix is a **real and
substantive improvement that still fails the one test it was mandated to pass**; the exact
remedy and its satisfiability proof are frozen here. No open REVIEW_BLOCKER. No promotion,
no stable event, no regression recurrence, no gate credit.

---

## RA-63.1 — Execution authority re-derived from object hashes, not from the report

The report claims a compile at semantic source `16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b`
while the workflow run's `headSha` is `276fc267cddbc9ad3f4212be8e048e58785cee7a`. That
discrepancy is **benign and now proven so**, by tree identity rather than by narrative:

| object | `16c3134c0` | `276fc267c` (run head) | `HEAD` (`78a4b4060`) |
|---|---|---|---|
| `src` tree | `76a12d4053a5c0798adcb0dce6d5eb8bf4e29623` | *identical* | *identical* |
| `include` tree | `790328c2bcffe29db5366ea1193cf0ab6d8cba58` | — | *identical* |

`git diff --stat 16c3134c0 276fc267c` touches exactly one file,
`.agents/Directional/agent-dispatch-request.json`. **The compile therefore covered byte-for-byte
the source that is live at HEAD.**

Run [38743048456](https://github.com/akashskypatel/Directional/actions/runs/38743048456) is
`conclusion: success`, `status: completed`. Result artifact **`11976790988`**
(`directional-m6-cp3-r4-predicate-compile-result-38743048456`, 38,939,446 bytes) exists and its
name matches the claim. Eight targets, `DIRECTIONAL_ENABLE_GMP=ON`, `libgmpxx`/`libgmp` in the
generated link command, `runtimeExecution=false`, preflight/build `0/0`.

Non-mutation re-derived against `700d6418f` by tree hash: `tests`, `benchmarks`, `cmake`,
`.github`, `include` **all byte-unchanged**. No selector file and no `CMakeLists.txt` in the
diff. Exactly two non-document files changed: `src/geometry/SurfaceCellTracing.cpp` and
`.agents/Directional/tools/review_check.py`.

**LESSON 160 holds and the turn states it itself** ("Compiler success is not runtime
acceptance"). No Directional binary, test, benchmark or frozen-497 selector executed. Nothing
runtime is claimed and nothing runtime is credited.

## RA-63.2 — Decision-neutrality verified at the source level, by construction

Every added line sits inside the already-entered post-decision block
`if (!firstEndpoint || !secondEndpoint)` (`src/geometry/SurfaceCellTracing.cpp:19360`), after
**both** `endpoint_certificate` calls have returned (`:19354-19359`). Each added statement either
declares a block-local (`exact_source_vertex`, `fromVertex`, `toVertex`, `append_interval`,
`probeCarrier`, `firstInterval`, `secondInterval`, `firstFailedCondition`) or streams into
`endpointEvidence`. There is no `return`, no assignment to `firstEndpointPredicate` or
`secondEndpointPredicate`, no mutation of any captured state, no epsilon, and no relaxation of
`exact_corner`, `no-exact-terminal-corner`, the closed-chain branch or any `Produced`
precondition. The helper lambdas it reuses — `find_carrier`, `oriented_carrier`,
`source_face_id` — are pure reads returning by value (`:19097-19114`).

**Not one acceptance or rejection decision can change.** This is the strongest form the mandate
asked for and it is satisfied.

One null-dereference concern was raised and **discharged**: the ladder calls
`network.sourceTopologyRegions->topology_for_row(...)`, but the real certificate dereferences the
same pointer unconditionally at `:19135-19138` immediately after its `!from || !to` guard, so any
path that reaches the probe with valid source faces has already dereferenced it successfully. The
ladder's `invalid-source-face` rung guards the nullopt case before dereferencing. **No new crash
surface.**

## RA-63.3 — Item (b) correctly implemented; the RA-62.3 hand derivation is retired permanently

`exact_source_vertex` tests the barycentric for exact one-hotness against `1.0`/`0.0` with no
tolerance and returns `faces(point.face, corner)`, or `none` when the point is not one-hot. At
most one corner can satisfy the test, so the first-match loop is unambiguous. The probe now
states **what the point is**, not merely whether it matches a published terminal — which is
precisely the omission that forced a by-hand derivation of the fixture's face table at RA-62.3.

**Prediction, with its provenance stated (RA-61.5).** For subset A the emission will be
`a2bProbeFromSourceVertex=4;a2bProbeToSourceVertex=4`. Provenance: RA-62.3's derivation from
`make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-264`),
giving face 0 = `(0,1,4)` and face 7 = `(4,8,7)`, against the measured probes `0:(0,0,1)` and
`7:(1,0,0)`. This is a prediction from the fixture, not an expectation from the report.

## RA-63.4 — Item (a) correctly implemented and lossless

`exact_numerator()` / `exact_denominator()` exist at
`include/directional/authority/FieldTransportAtlas.h:516-517`, returning `EInt`
(`include/directional/numerics/ExactNumber.h:24`). `EInt::to_string()` exists on **both**
backends — `include/directional/numerics/ENumberGMP.h:61` (`value.get_str()`) and
`include/directional/numerics/BigInteger.h:401` — so the emission is exact and
backend-portable. **No double, no rounded decimal, no reconstruction.**

`append_interval` is called **unconditionally** for both records, outside the ladder, so the
presence flags and ordinals are emitted even though the ladder can never reach its own interval
rungs (RA-61.6: `same_interior_carrier_point` is unsatisfiable for a traced barycentric, so the
ladder stops at or before that rung). That placement is a correct design call and not an
accident.

## RA-63.5 — PRINCIPAL: RA-61.9 falsifier (ii) is answered from bytes, negatively. **RA-61.9 is WITHDRAWN.**

The front-edge record `SurfaceFrontEdge` that supplies `first` and `second`
(`include/directional/geometry/SurfaceCellTracing.h:1545-1579`) carries:

- **two** endpoints — `SurfaceTracePoint from;` and `SurfaceTracePoint to;` (`:1549-1550`)
- **one** `std::optional<SurfaceSharedBoundaryInterval> sharedBoundaryInterval;` (`:1572`)
- **one** `std::optional<authority::HardRailId> railId;` (`:1568`)

`endpoint_certificate` is invoked twice (`:19354-19359`) with `first` and `second` captured by
reference and **identical in both calls**; only `fromPoint`, `toPoint` and `edge` differ.
Therefore the interior branch's interval conjunct —

```cpp
first.sharedBoundaryInterval->span      == second.sharedBoundaryInterval->span      &&
first.sharedBoundaryInterval->firstOrdinal  == second.sharedBoundaryInterval->secondOrdinal &&
first.sharedBoundaryInterval->secondOrdinal == second.sharedBoundaryInterval->firstOrdinal  &&
first.railId == second.railId
```

— **evaluates to the same value at endpoint 1 and endpoint 2.** If it is true it is true for
both; if false, false for both. **It pins the edge pair. It can never pin the point.**

RA-61.9 proposed keeping strict interiority, dropping the dead closure gate and the cross-chart
double equality, and **resting endpoint identity on exactly this witness**. With the closure gate
removed, the interior branch's only remaining endpoint-sensitive conjunct is `oriented_carrier`,
which depends on `fromPoint.face` / `toPoint.face` — **face-level, not point-level**. RA-61.9 as
specified would therefore admit an endpoint certificate carrying **no point-level exact evidence
at all**.

The asymmetry is the whole point: **the dead gate fails closed; RA-61.9 would fail open.** An
unsatisfiable gate rejects 44 valid identities, which is a visible defect. An endpoint-blind gate
would accept them on edge-level evidence, which is an invisible one. **RA-61.9 is withdrawn, not
merely left unauthorized.** No successor may implement it. Falsifier (ii) needed no run; it needed
the record's field list.

This is the fourth self-correction in the RA-57.3 / RA-58.8 / RA-59.4 / RA-61.5 / RA-61.7 family
and the second candidate remedy of mine to die on inspection.

## RA-63.6 — `RP-01` is a pattern, and its second instance is in the same conjunction

Two granularity mismatches now sit inside the single `if (!terminalVertex)` branch:

1. **rail-level → carrier-level** (RA-62.5): `SurfaceHardRailTerminalContacts` publishes two
   endpoints per *rail* (`SurfaceCellTracing.h:1530-1535`), consulted to answer a question about
   one *carrier edge* (`:19213-19220`). Structurally unsatisfiable at a multi-edge rail's
   junction end.
2. **edge-record-level → endpoint-level** (RA-63.5, new): one `sharedBoundaryInterval` per front
   record, consulted to answer a question about one of that record's *two* endpoints.

`RP-01 AUTHORITY_DOMAIN_CONFLATION` is therefore **not one site but a recurring construction
habit**, and both instances are in the predicate this family has been circling for six rungs. The
consequence for any future repair is concrete: **widening an existing published set cannot fix
either instance.** The repair must introduce vocabulary at the granularity the question is asked
at — per-interval terminal contacts (rail intervals already exist and are already consulted by
the publisher at `:12610`) and per-endpoint exact parameters. **No repair is authorized here;**
this amendment constrains the eventual specification, it does not license code.

## RA-63.7 — The PROCESS-01 gate fix is a real improvement **and fails the test it was mandated to pass**

What genuinely improved, and it matters: the floor is now `max` over `rev-list HEAD -- <rel>`
(`review_check.py:196-202`), so `boundary` **now detects a committed overwrite**, which was the
entire RA-62.2 hole — the previous `live >= was` against `HEAD` was inert once the overwrite was
in HEAD. `Future_Chat_Session_Handoff.md` and `ORIENTATION.md` are added to
`APPEND_ONLY_LEDGERS` (`:60-61`). `_line_count` and the live count both use `.count("\n")`, so
the two metrics agree and there is no off-by-one. Both gates pass at HEAD with floors
`4468 >= 4468`, `3108 >= 3108`, `13003 >= 13003` — the tracker floor now exceeds the RA-61
frozen floor of ≥12,949. Measured runtime 3.8 s over 424 `git show` invocations: acceptable.

Both shapes were then tested in an isolated detached worktree, never in the live tree:

| simulated defect | result |
|---|---|
| truncate handoff 4,468 → 21 lines | **`[FAIL] durable high-water … 21 >= 4468`** — caught |
| whole-file overwrite to 4,468 lines of filler, marker retained, `## ` sections 302 → 1 | **`ALL CHECKS PASSED`** — not caught |

The second row is the mandate's own acceptance criterion, quoted from `ORIENTATION.md:1853`:
*"If deleting the protected content leaves the check green, the check does not cover that
content."* Every section of authorizing history was destroyed and the gate reported green.

**The lesson generalized one level and the fix instantiated it one level too low. A guard that
counts lines does not protect content, for exactly the reason a guard that counts markers does
not.** The marker check was also weakened from a count to a presence test (`:203-204`) — correct
in itself, since it removes the prose-pollution false positive that bit this reviewer twice, but
it means *no* committed check now examines content at all. Not a blocker: the turn delivered a
strict improvement, it passes its stated claim, and the residual is specified below with proof.

## RA-63.8 — The remedy, with its satisfiability **proven** before being mandated (RA-61.7)

Add a `## `-heading high-water floor to `boundary`, **exactly symmetric** with the line floor
already written — same `max` over `rev-list HEAD -- <rel>`, same comparison direction. Measured
evidence, all three claims verified:

- **Satisfiable today.** live == high-water for every protected file: handoff **302/302**,
  ORIENTATION **105/105**, tracker **651/651**. The gate goes green on the current tree
  immediately.
- **Catches the uncaught shape.** The equal-size overwrite above drops 302 → 1.
- **Catches every historical destruction.** `f7add683` 611→1, `0e1909d3` 629→1, `b90c0f84`
  648→1.

**Rejected alternative, with its reason recorded so it is not re-proposed.** Heading-*set*
inclusion over all history is **unsatisfiable**: 24 handoff, 3 ORIENTATION and 1 tracker headings
differ across history, because superseded `## CURRENT …` headings are legitimately reworded as
they are demoted. Per-step inclusion against the immediately preceding commit is satisfiable
today (0 missing on all three files) but is **not robust** — the next legitimate rewording turns
it red, which would train a successor to disable the gate. A **count** floor tolerates rewording,
rises on every prepend, and cannot be lowered. That is the correct predicate and this is why.

The tracker's one apparently-lost heading was chased to ground and is **not a loss**:
`## 2026-10-08 — M6-CP3-TB1-ENTRY-R2-REV …` survives at
`Regression_Root_Cause_Tracker.md:1332` with reworded trailing text. **The RA-61 restoration is
intact.**

## RA-63.9 — The tracker's exemption from zero-tolerance is unjustified and inverted

`review_check.py:224` reads:

```python
protected_history = path in DURABLE_FILES and path != ".agents/Directional/Regression_Root_Cause_Tracker.md"
```

So handoff and ORIENTATION get zero-tolerance while the tracker keeps the 10 % rule — leaving
**the one file that has actually been destroyed three times** as the single protected file that
still permits a silent ~1,300-line deletion, which is exactly the scale of the `0043dd4c`-class
partial overwrite. No rationale is given in the code or the report.

**Measured: the tracker has had zero shrinks in the 0–10 % band across its entire history.** All
three of its shrinks are >10 % (`f7add683` 11,683→8, `0e1909d3` 12,147→11, `b90c0f84`
12,949→6). The exemption is therefore **pure slack with no historical justification** and removing
it is satisfiable immediately. Remove it; an append-only ledger tolerates no shrink, and a
genuine consolidation should fail loudly and be justified in the open rather than pass silently.

## RA-63.10 — My RA-62 integrity count was wrong, and the undercount is mine

RA-62 recorded the handoff overwrite as the **fourth** integrity event. The bytes show at least
**six**:

| commit | date | effect | recorded in any durable document? |
|---|---|---|---|
| `ce9bf3cb` | 2026-09-22 | tracker 9,837 → 21 | yes (9 docs) |
| `0043dd4c` | 2026-09-22 | agent CHANGELOG 13,317 → 14 | yes (8 docs) |
| `f7add683` | 2026-10-08 | tracker 11,683 → 8 | **NO — zero documents** |
| `0e1909d3` | 2026-10-12 | tracker 12,147 → 11 | cited for content, not flagged as a destruction |
| `b90c0f84` | 2026-10-15 | tracker 12,949 → 6 | yes (RA-61) |
| RA-62's overwrite | 2026-10-15 | handoff 4,419 → 4,411 | yes (RA-62) |

**`f7add683` is an entirely unrecorded whole-file destruction of the append-only tracker.** It was
repaired by a later commit — the tracker stands at 13,003 — but it was never adjudicated and never
counted.

The mechanism of my error is clean and worth freezing: **I counted the integrity events that had
been written down, not the integrity events in the bytes.** That is LESSON 171 — *"a census is not
a witness"* — turned on my own ledger, by me, while mandating a content guard for everyone else.

**RA-63.10 (new lesson): a count of recorded events is not a count of events.** The remedy is not
prose. The RA-63.8 heading high-water would have surfaced all three tracker destructions
mechanically, the moment each landed. Prose lessons have now failed four times in this lineage;
the instrument has failed twice. Filed against the pre-existing **`PROCESS-01`**; it does **not**
increment the regression recurrence counter.

## RA-63.11 — Ladder faithfulness: one ordering divergence, low severity, and the structural hazard behind it

The real conjunction order is `missing-source-face` (`:19134`) → `missing-carrier` (`:19140`) →
the interior conjunction. The probe ladder checks `carrier-absent` **before**
`invalid-source-face`. The two therefore disagree about which condition is "first" when **both**
fail. Narrow, and mitigated by construction: `a2bProbeFailure` carries the real predicate on the
same line, so the log cross-checks itself and no measurement can be silently misread.

The structural point is larger than the bug. **The ladder is an independent second transcription
of the acceptance conjunction.** If the acceptance predicate is ever edited and the ladder is not,
the instrument reports confidently about a reconstruction rather than about the decision — the
same class as RP-03, aimed at the diagnostic instead of the reviewer. Verified faithful today,
condition by condition, including that `firstAttachment` / `secondAttachment` are exactly
`topology_for_row(*source_face_id(point.face, faces.rows()))` (`:19135-19138`), which the ladder
reproduces exactly. **Deferred deliberately:** reordering is a C++ edit and would cost a fresh
eight-target compile and a new semantic source, invalidating the compile that is already packaged
at `16c3134c0`. Information per turn is higher if the harvest runs first.

## RA-63.12 — `one-hot-carrier-junction` is a good call

The ladder distinguishes `one-hot-carrier-junction` from `not-same-interior-carrier-point` when
`!same_interior_carrier_point` and both endpoints resolve to the **same** source vertex. That
names the RA-62 mechanism — a junction-terminated front — inside the instrument itself, rather
than leaving it to be re-derived by a reviewer. Unrequested, correct, and in the right direction.
Subset A is predicted to report it.

## RA-63.13 — `Successor: UNKNOWN`, this time with a reasoned defence, and the reasoning is accepted

The beacon again closed `UNKNOWN`, against an explicit mandate to close with a named successor.
But this instance is **not** the earlier defect. The two earlier occurrences left the field blank
with no reasoning; this one states a position: *"repository authority currently supplies no
successor identifier, so `Successor: UNKNOWN` is correct and no successor work may begin merely
because this Code + Build completed."*

That reasoning is sound, conservative, and correctly refuses to self-authorize. Naming the next
turn is the Review Agent's prerogative in this cadence, not the Implementation Agent's. **No
defect is recorded.** The successor is named here, and the mandate is amended: when no identifier
has been authorized, state that in the handoff — as this turn did — rather than inventing one.

## RA-63.14 — Dispatch-channel hygiene, one line

A **consumed** `drive_apply` descriptor remains committed at
`.agents/Directional/agent-dispatch-request.json` with `base_sha 2d52eeb04` and a live Drive
`file_id`. A request channel whose descriptor stays live after consumption is not idempotent: a
re-read would attempt to re-apply a spent patch against a base that is no longer HEAD. `97965edd2`
retired the *source-snapshot* trigger and left the *closeout* trigger behind. Clear it in the next
turn. Not an architecture finding and not a blocker.

---

## Accounting

No source, test, selector, binary, harness, workflow, benchmark or ledger-count change in this
**Review**; no Directional binary executed. Stable ledger **66 events / 17 categories / 49
recurrences**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88
carried CP2 losses), frozen selector **30+12+449+6=497** — all unchanged. No accepted-green loss
and no ledger credit. No promotion, no stable event, no regression recurrence, no 497 execution,
no gate credit. PR #8 draft/open. `R4-VIN-01` applies: `16c3134c0` is a **new semantic source**,
so every prior measurement — including artifact `11967601999` — is a **baseline, never a
comparand**.

**Open:** `RP-01` **located, now known to be a pattern with two instances, not repaired, repair
not authorized**; `RP-02` **UNREACHED**; `RP-03` satisfied; **`PROCESS-01` open with a proven
remedy specified (RA-63.8, RA-63.9)**.

**Withdrawn:** **RA-61.9** (both the remedy and falsifier (ii), the latter answered negatively
from bytes).

**Successor:** `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` — instrument-only, Python-only, no C++ and
therefore no compile. Then `M6-CP3-TB3-R4-PROBE-HARVEST` at semantic source `16c3134c0`.
