# RA-61 — `M6-CP3-TB1-R4-INTERIOR-WITNESS` measurement review decision (2026-10-15)

Reviewer turn `M6-CP3-TB1-R4-INTERIOR-WITNESS-REV`. Adjudicates the interior-witness
artifact-only measurement, repairs a destroyed append-only ledger, and
**falsifies the reviewer's own RA-60.10 prediction and RA-59.9's mechanism
breadth from exact arithmetic on the measured bits**.

Candidate/non-stable throughout. No promotion, no stable event, no recurrence,
no frozen-497 execution, no gate credit. No source, test, selector, binary,
harness, workflow or benchmark change in this Review.

---

## RA-61.1 — The measurement is ACCEPTED as execution evidence

Run [38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279),
result artifact `11967601999` (ZIP SHA-256
`8b52373eebc7bda574f1fed2914dec4577ff70c670396f2ea3b19383d0fd25f1`), semantic
source `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, harness
`.agents/Directional/tools/m6_cp3_r4_interior_witness_harness.sh` SHA-256
`13a7e73ea17bff8c7b6a14bb2e3bc35712e05b8914a1546668108354fdb02e21`.
`execution-boundary.txt`: `planned=45 executed=45 red=45 missing=0
postflight=true exit=0 compile=false relink=false benchmarks=false
selector497=false`. `immutability.txt`: `package=true source=true
execution_view=true selector=true`.

The instrument is compliant with the shape RA-59.2 and RA-57.8 require: the
39-identity inventory is SHA-256-pinned (`de05a7bd…`) and `mapfile`-read, a
duplicate-identity assertion is present (`:51`), non-selection is recorded and
`continue`d rather than silently passed (`:72-74`, `:110-111`), the breadth
assertion is on the counters alone (`:128` `executed == 45 && missing == 0 &&
postflight == true`), and package/source/execution-view immutability is
`cmp`-verified before and after (`:121-124`).

Three disciplines were honored without prompting and are recorded as such:
**RA-60.12 was obeyed** — all 45 identities ran after the first RED, and the
verdict is taken from the counters, not the RED count; **no predicate was
relaxed and no epsilon introduced** to manufacture green; and the turn
**refused to invent the successor identifier**, leaving it to repository
authority rather than fabricating one. The report also correctly keeps ordinal
**405** distinct and correctly declines to call the result a restoration.

---

## RA-61.2 — REVIEW_BLOCKER, now repaired: the append-only ledger was destroyed

Commit `b90c0f84e` reduced `.agents/Directional/Regression_Root_Cause_Tracker.md`
from **12,949 lines to 6**, deleting **12,944 lines** of root-cause history —
the full stable ledger narrative behind 66 events / 17 categories / 49
recurrences. The standing NEXT_TURN prohibited exactly this ("tracker
append-only"). The 5-line section prepended in its place is legitimate content;
the deletion beneath it is not.

**Repaired in this turn.** The ledger is restored from the last good blob
`cef55bdd0`, with the measurement section retained on top and the RA-61 section
prepended above it. Nothing is discarded in either direction.

**High-water floor, recorded as data so it is auditable without the tool:** the
tracker must never fall below **12,949 lines**, **13 durable-marker occurrences**, or
**648 `## ` sections**. Any future state below any of these three is a
destruction, whatever a gate reports.

This is the **third** occurrence of durable-ledger destruction in this project,
not a novel defect: `.agents/Directional/tools/review_check.py:52-53` records
whole-file overwrites at `ce9bf3cb` / `0043dd4c` on 2026-09-22, restored at
`M5-CP3-TB2-REV`. A failure mode that has now recurred three times is a
property of the workflow, not of one agent.

---

## RA-61.3 — The reviewer was running the wrong gate; the adequate gate existed

`review_check.py boundary` reported **ALL CHECKS PASSED** over the 12,944-line
deletion, printing `durable markers preserved in
Regression_Root_Cause_Tracker.md 0 -> 0`.

The mechanism, read from `:184-196`: `live` is the marker count in the working
tree and `was` is the count in **`HEAD:<rel>`**, and the test is `live >= was`.
It is a within-turn ratchet against the reviewer's own uncommitted edits. Once a
truncation is committed, `HEAD` *is* the truncated file, so the check compares
`0` to `0` and passes — permanently. **A check whose comparand is its own
current state is not a check.**

The tool says so itself at `:48`: *"Protects only against the reviewer's own
uncommitted edits; see `ledgers` for committed overwrites."* The `ledgers`
subcommand exists and names the damage exactly:

```
review_check.py ledgers --base cef55bdd0
  [FAIL] no >10% shrink of .agents/Directional/Regression_Root_Cause_Tracker.md b90c0f84 12949->6
```

So this is a **reviewer defect, not a tooling gap**. The instrument was
adequate, documented its own limitation in a comment, and pointed at its
companion; the standing per-turn procedure invoked only `boundary`.

**Standing rule, in force from this turn:** every Review turn runs **both**
`review_check.py boundary` **and** `review_check.py ledgers --base <prior
review commit>`. `boundary` alone may never again be reported as the gate.

**Both of these lessons were already written down, and both recurred anyway.**
`ORIENTATION.md:1719` records `LESSONS.md` **176** — *"An append-only durable
ledger was replaced by a whole-file write, and nothing noticed for ~20 turns"* —
for `ce9bf3cb`, which cut the same file from 9,837 lines to 21.
`ORIENTATION.md:1799` records *"A guard that counts markers does not protect
content"*, naming the `1 -> 1` pass mode exactly. So RA-61.2 and RA-61.3 are not
discoveries; they are **recurrences of documented lessons**, and the prose
remedy has now failed twice.

The conclusion follows directly: **a written lesson is not a control.** The
floor in RA-61.2 is therefore recorded as three countable numbers rather than as
an instruction to be careful, and the mechanical fix below is mandatory rather
than advisory — a monotone high-water floor that cannot decrease, instead of a
self-relative comparison. Until that fix lands, the floor is verified by
counting, by whoever closes a turn.

---

## RA-61.4 — RA-60.10's prediction is FALSIFIED; its decision rule held

Pre-registered: the 38 `endpoint-1` identities **clear** `:19241` and A4
accepts. Observed: **none cleared.** 44 of 45 report
`a2bProbeFailure=no-exact-terminal-corner`; ordinal 405 reports
`missing-terminal-or-closed-rail-provenance`. Outcome is **branch (C)**.
Branch (B) — a new failure strictly downstream — was not observed.

The premise was wrong, and the error is the reviewer's: RA-60.10 asserted the
probes were `0x1.8p-1` and `0x1p-2` (0.75 / 0.25), *"exactly representable …
sum exactly `1.0` in both charts."* The fixture's `lengthRatio = 0.2`
(`tests/SurfaceCellsPhase10Tests.cpp:6312`, inside the fixture builder at `:6298-6323`), and the measured probes are
0.8 / ≈0.2 — **neither binary-exact**.

The distinction that matters: the **prediction** failed, the **decision rule**
worked. Branch (C) was anticipated, was classified correctly by the measuring
turn, and mandated precisely the response taken — diagnostic separation, no
relaxation. A pre-registration earns its keep by being falsifiable; this one was
falsified cleanly and cheaply, which is the intended outcome of registering it
rather than reasoning after the fact.

---

## RA-61.5 — LESSON: pre-register the *provenance* of the expected value, not only the value

Fourth of one family — RA-57.3 (a non-discriminating control), RA-58.8 (an
instrument conditioned on the verdict), RA-59.4 (*a measured value without its
expected value is not a discriminator*), and now: **an expected value whose
provenance is unstated is not a prediction.** The deciding fact — `lengthRatio
= 0.2`, hence weights 0.8 and 0.2, hence no binary-exact closure — sat in a file
RA-59 had already cited by anchor, and needed no run at all.

---

## RA-61.6 — Principal finding: the acceptance path is unsatisfiable, and for `fromPoint` this is assumption-free

The measured paired probes in 23 identities, from the published source-face
barycentrics (`src/geometry/SurfaceCellTracing.cpp:19389-19397`, lossless
hexfloat of the stored doubles):

```
0: 0x0p+0,              0x1.999999999999ap-1, 0x1.9999999999999p-3
3: 0x1.999999999999ap-1, 0x0p+0,              0x1.9999999999998p-3
```

Exact rational arithmetic on those bits:

| quantity | exact result |
|---|---|
| face 0, nonzero pair sum | `1 + 2^-55` — **not** 1 |
| face 3, nonzero pair sum | **exactly 1** |
| cross-chart ≈0.2 weights | differ by `2^-55` (1 ULP and 2 ULP below nearest-0.2) |

`interior_carrier_parameter` (`:64-89`) requires the third weight exactly `0.0`,
`second` strictly in `(0,1)`, and `first + second == one` over
`FieldExactRational::from_double_exact`. For **face 0 this returns `nullopt`
under every possible corner assignment**:

- zero at `other` → `first + second = 1 + 2^-55 ≠ 1`;
- zero at `low` → `first = 0`, so closure requires `second == 1`, but `second`
  is 0.8 or ≈0.2;
- zero at `high` → `second = 0`, failing `second > zero`.

Therefore `same_interior_carrier_point` is false at the **first** chart in all
23 cases, and cross-chart equality is never consulted. Face 3, by contrast, *can*
yield a value. The two charts disagree not about the parameter's value but about
whether the point is **admissible at all**.

The measuring turn named only the cross-chart one-ULP difference and framed it
as a deviation from the reviewer's assumed probe form. The single-chart closure
failure — the decisive one, and the first to fire — went unnamed, though both
facts are in the bytes the report itself quoted.

---

## RA-61.7 — The defect is the reviewer's specification, and RA-60 verified the wrong property

`first + second == one` over a traced barycentric demands a closure property the
producer never promises and double arithmetic cannot deliver: an exact
mathematical edge point `(0, 1-t, t)` has each component independently rounded,
and `fl(1-t) + fl(t) == 1` is a coincidence, not an invariant.
`from_double_exact` is exact about the **double** — precisely the wrong object.
It faithfully preserves a rounding error and then tests it for equality.

RA-60.2 praised the absence of any epsilon as a virtue and verified the
implementation's **faithfulness** to RA-59.9. It never asked whether the
predicate could be **true** for a legitimate traced point. It cannot, except by
luck, and the acceptance branch is therefore **effectively unreachable** — which
makes RA-60's "ACCEPTED as faithful" true but hollow: faithful to a
specification that was itself unsatisfiable. The implementation is not at fault
and is not being re-judged.

**RULE: verify a predicate for satisfiability, not only for faithfulness.** A
specification can be implemented perfectly and still be dead on arrival.
"Fail-closed" is a virtue only when the closed state is reachable by legitimate
input. This was derivable at RA-59 time from four lines of header, with no run.

---

## RA-61.8 — An exact witness already exists, and the agent had already wired it

`SurfaceTracePoint` (`include/directional/geometry/SurfaceCellTracing.h:90-93`)
carries **only** `int face` and `Eigen::RowVector3d barycentric` — three
doubles. There is **no exact parameter to read**, so RA-59.9's "exact shared
intrinsic parameter" cannot be obtained from the trace point by any
implementation. The information is destroyed at tracing time.

But `SurfaceSharedBoundaryInterval` (`:1418-1428`) carries
`authority::FieldExactRational firstOrdinal` and `secondOrdinal` — **exact
rationals, not doubles** — and the repair **already** requires equal `span`,
reciprocal ordinals (`firstOrdinal == other.secondOrdinal` and conversely) and
equal `railId` (`:19231-19238`).

**That is the exact shared-point witness RA-59.9 asked for.** The unrequested
check RA-60.2 merely "adopted as a strengthening" is in fact the load-bearing
one, while the part the reviewer specified is the dead one. The implementing
agent's instinct was better than the specification it was given, and that is
recorded as such rather than absorbed silently.

---

## RA-61.9 — Candidate remedy, explicitly NOT yet authorized (RA-54.7)

Decompose the predicate rather than loosen it:

1. **Keep** strict-interiority *classification* per chart — "this endpoint is
   not a corner." One-hot versus ≈0.2 is not a close call and is robust to ULP
   error, and this is what blocks laundering a forged terminal (RA-60.2).
2. **Drop** the `first + second == one` admission gate — a representation
   artifact, not a soundness property (RA-61.7).
3. **Drop** cross-chart double parameter equality.
4. **Rest point identity** on the already-present exact-rational
   `sharedBoundaryInterval` reciprocity.

This introduces **no epsilon**: RA-60.11's prohibition is honored in letter and
in spirit, and the identity claim *moves onto* exact rationals instead of being
weakened. The resulting predicate is smaller **and** more exact than today's.

Two falsifiers must be measured before any of this is authorized, and neither is
settled here: **(i)** is `sharedBoundaryInterval` even **set** for these
fixtures — it is `std::optional`, and `:1423-1425` states that
physical-boundary producers may leave it unset; **(ii)** do equal span plus
reciprocal ordinals pin the **point** rather than merely the interval, to be
derived from the producer's own code and not inferred from the type. **No repair
is authorized until the diagnostic measurement names the deciding conjunct.**

---

## RA-61.10 — RA-59.9's single-mechanism claim is PARTIALLY FALSIFIED: ≥2 shapes, 23 + 21

Twenty-one of the 44 probe **one-hot**: `0:0,0,1` against `7:1,0,0`. That is a
**mesh vertex**, not an interior point. For these, `interior_carrier_parameter`
returns `nullopt` correctly (strict interiority, as RA-60.2 established), and
the terminal loop also refused — so `terminalVertex` is absent **although the
endpoint is an exact corner**.

The interior model does not apply to these 21 at all. RA-59.9 claimed one
mechanism re-explaining all 39 identities; there are at least two, and the
repair addressed only one of them. The 21 are a **separate, undiagnosed family**
that RA-60 never covered and that no part of the repair could have fixed.

This simultaneously **corroborates** RA-59.11 — which bounded independent loci
at **≤22, not 39**, against the report's 39-corroboration framing — since the
realized 23/21 split straddles that bound, and **refutes** the breadth of
RA-59.9's mechanism claim. The bound was right; the mechanism was over-general.

---

## RA-61.11 — The deciding conjunct for the 21 is already captured and was not reported

The terminal loop (`:19213-19220`) is a **three-way conjunction** requiring the
**same** vertex to satisfy all of:

```cpp
(edge.first() == vertex || edge.second() == vertex)
&& exact_corner(fromPoint, vertex)
&& exact_corner(toPoint, vertex)
```

So a one-hot endpoint still fails if the two charts name **different** vertices,
or if the vertex is **not on the carrier edge**, or if it is **not a published
rail terminal**. These are three distinct defects with three distinct repairs.

The probe block already emits exactly the discriminator, per published terminal
(`:19409-19416`): `corner[v]=<from>,<to>` and `railEnd[v]=<bool>`, alongside
`a2bProbeCarrierPresent`, `a2bProbeA3Present`, `a2bProbeContactPresent` and
`a2bProbeClosedChainPresent`. The report quoted only `a2bProbeFrom/To`.

**No re-measurement is required.** The evidence is already inside immutable
artifact `11967601999`. `RP-03` applies at instrument level: name the deciding
conjunct, never the verdict.

---

## RA-61.12 — Accounting, carried obligations, and the next rungs

Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, CP2
**491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses),
frozen selector **30 + 12 + 449 + 6 = 497** — all unchanged. All 39 census
identities were already RED under the prior semantic source and the six
supplementals have no accepted-GREEN baseline, so **no accepted-green loss and
no ledger credit** arises. PR #8 draft/open. The ledger destruction in RA-61.2
is an **integrity** recurrence and does **not** increment the regression
recurrence counter.

`R4-VIN-01` continues to apply: `570c5173…` is a new semantic source, so every
prior measurement is a baseline, never a comparand.

Carried without probe: `RP-01`; `RP-02` (open, unreached — neither the
network-bound consumer nor its tamper half was executed); `RP-03`; RA-60.5
(**now triggered** by branch (C)); RA-60.6 terminal-coverage with no aggregate
replacement; RA-60.7 encoding collapse needing a positive discriminator;
RA-60.8 comment mismatch; RA-60.9's four untested negatives; the RA-58.7
A5/A6/A7 loci and `R4-OHF-02`; the two RA-57.9 guards and RA-41's
junction/sector clauses (frozen UNEXERCISED, recipe known, not retired); ordinal
**405**'s separate A2b provenance defect; 34 Phase10 / seven DCEL / six CP3
identities; CP2 restorations outside the 37; organic D1/D2/D3/D5 and A6/A7
witnesses; the odd-τ witness; the two `SurfaceCellTracingPhase14` identities
needing a separately packaged historical executable
(`cmake/DirectionalTests.cmake:554-572`), not to be bundled into a measurement
rung.

**Next rung — `M6-CP3-TB2-R4-CONJUNCT-EXTRACT`,** artifact-only extraction from
the **existing** immutable artifact `11967601999`. No dispatch, no compile, no
new run, no code. Partition the 44 into the 23 interior-shape and 21 one-hot
families **from bytes**, and for the 21 name which of the three RA-61.11
terminal conjuncts fails.

**Rung after that — `M6-CP3-CB2-R4-PREDICATE-SEPARATION`,** diagnostic-only,
**now authorized** because branch (C) occurred: give each rejection cause a
distinct string so a repeat is interpretable, strictly decision-neutral, and
emit `sharedBoundaryInterval` presence and ordinals so RA-61.9 falsifier (i)
becomes measurable. Acceptance behaviour must not change by one identity.

The RA-61.9 remedy is **not** authorized in either rung.
