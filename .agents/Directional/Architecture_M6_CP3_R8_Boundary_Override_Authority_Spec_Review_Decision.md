# Architecture Review Decision — M6 CP3 R8 boundary-override authority (rung 16)

**Review turn:** `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` (rung 16)
**Frozen amendment:** RA-75
**Verdict:** **ACCEPTED**, with one charge and one note. It answered all four questions,
and it **corrected this reviewer's framing of the override**.
**Review window:** 2026-10-16T08:10:44Z — 2026-10-16T08:51:02Z
**Semantic source:** unchanged at `cdd6dc4a9ba95a42aace6226194b38e712b53e4b`

---

## RA-75.1 Provenance and boundary

| check | result |
|---|---|
| snapshot run `38868534647` | `conclusion=success`, `head_sha=e8db3859b` |
| snapshot artifact `12032341939` | digest `ae817b332a1fb8e862f036578c22211d8a9c194bfaf8d9796a5f94b1d638d0be`, matches |
| `src`/`include`/`tests` at `e8db3859b`, `cdd6dc4a9`, `HEAD` | **tree-identical** — `43a6494a27…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |
| `ledgers --base 298b6779d` over the agent's range | **ALL CHECKS PASSED** — no shrink |

## RA-75.2 Q1 answered, and the answer is decisive: face 7 is not a stray value

Verified at `src/geometry/SurfaceCellTracing.cpp:17117-17118` and `:17139-17140`, in both
the forward and reverse ordinal loops:

```cpp
!append_point(*firstParameter,  run.sourceFaces[edgeIndex]) ||
!append_point(*secondParameter, run.sourceFaces[edgeIndex])
```

**The accepted boundary point's face comes from `run.sourceFaces[edgeIndex]` — the source-edge
run's own face — never from a chart selector.** So the published face 7 carries genuine
accepted-conformity source-edge authority. It is not an error value, and the three rungs
spent suspecting the chooser were, in retrospect, looking at the wrong object entirely.

The flags are as stated: `useAcceptedConformity = hasTopologyPlan && hasBaselinePlan`
(`:14993`), while `useAcceptedCutDomain = useAcceptedConformity && regionHasHardFeature`
(`:14998`) — **not coextensive**, exactly as the specification says.

The authority is structural, not merely point-level: at `:17204-17215` the grid interval
counts themselves are taken from `acceptedBoundary[side].intervals.size()`, with
`bottom != top || right != left` rejected. The accepted boundary therefore sizes the
producer's lattice before any sampling happens.

What the specification correctly declines to claim is equally important: nothing proves the
accepted point's `.face` must equal the chart sample's, be the unique incident face, or be
correct for **both** directed-side carriers. And its warning not to replace `.face` without
transporting barycentrics is right — a face-relative coordinate is meaningless against a
different face.

## RA-75.3 Q2 answered honestly, and it corrects me

The guard is `v == 0 || u == gridU || v == gridV || u == 0` under accepted conformity: it
selects **every** grid-boundary node and knows nothing about the failing or control cohorts.

The specification then makes a point I did not: **an unchanged `FirstTo` face 0 may also
have been replaced** — the measurement cannot distinguish "the override did not fire" from
"the override fired and produced the same face." My RA-74.1 framing implied the
substitution is what distinguishes the 21. **It does not, and that is not established.**
Credited, and RA-74.1 is narrowed accordingly: what is measured is that at `SecondFrom` the
published face differs from the sample, not that the override is junction-specific.

## RA-75.4 CHARGE — the cohort "discrepancy" is one population counted in four domains

The specification writes that TB7 has "**27** `producer=none` control occurrences (54
endpoint records)" while "the older R5 controls numbered **23**", and concludes that
"without cross-vintage identity mapping, neither '21 exactly boundary' nor '23/27 exactly
interior' is established."

There is no cross-vintage discrepancy. Recomputed from `producer-presnap-candidates.tsv`:

| count | domain |
|---:|---|
| **54** | control **endpoint records** (two per occurrence) |
| **27** | control **occurrences** (54 ÷ 2) |
| **23** | control **ledger entries** (21 singles + 2 entries emitting 3× each) |
| **22** | control **distinct identity strings** (one entry is a deliberate duplicate) |

Measured directly: control rows 54, distinct identities **22**, and per-identity record
multiplicity `{2: 21, 12: 1}` — twenty-one identities contributing two records each and one
contributing twelve, which is the duplicated identity emitting three times on two ledger
entries. The duplication is deliberate and documented in the agent's own commit
`c4da30a37` ("preserve intentional **duplicate** TB identity").

So 23 and 27 are **the same population counted in two different index domains**, and no
identity mapping is required. **This is RA-67.13 recurring a third time** — derived at
RA-67.5, charged at RA-70.8, and charged again here: *name the index domain of every
identifier you print.*

The resulting caution — "do not code to these cohort counts" — is prudent and survives,
because the specification's **other** ground for it is sound: the override state at the
control nodes was never measured (RA-74.7). The conclusion stands on one good leg and one
bad one, and a successor reading the bad one would believe two vintages disagree when they
do not.

## RA-75.5 Q3 — it declines to name a single owner, with a reason, and that is admissible

I asked for the owning authority, or an explicit statement that the source does not
determine one. The specification gives the latter, with the missing contract named:

- **accepted conformity** owns the published source-edge point and its face-relative
  location;
- **chart sampling** owns interior samples and the preliminary competing representation at
  a boundary;
- **neither face is a unique directed-side carrier certificate.**

That last clause is the substance, and it is consistent with RA-72.4's per-directed-side
necessity: a single corner face cannot be authoritative for both the incoming and outgoing
side, so the question "which face is the corner's" is malformed as posed. The reframing of
`RP-01` as **missing boundary-point-to-directed-side carrier reconciliation**, explicitly
**not** a proven downstream-only bug, is the right disposition on this evidence. An
inadmissible answer is a result (RA-68.12), and this one is argued rather than dodged.

The side paths it cites do carry the needed material: `cell.boundaryPaths[side]` is built by
`bounded_disk_chart_segment` at `:17383-17390`, and `SurfaceTraceSegment`
(`include/directional/geometry/SurfaceCellTracing.h:1211-1232`) carries `face`, both
barycentrics, `sourceChart` and a typed `entryRoute` — verified at RA-72.3 and unchanged.

## RA-75.6 Q4 — a proper admissibility table

Six candidates, each adjudicated: two **admissible shapes only** (reconcile canonical
source-entity/sheet and side-specific face/chart/route while preserving accepted edge
placement; publish separate directed-side face/chart/route rather than one corner face),
one **relocation only** under RA-72.5 (raw face equality at the override or the consumer —
rejects the same 21 earlier and creates no successful cell), and three forbidden, including
inventing a vertex-star route, which is correctly refused under RA-65.5 with gate C
suspended. Seven falsifiers F1–F7 are stated and none is claimed as executed.

## RA-75.7 Credits

- **Both RA-74 charges absorbed in one rung.** `ledgers --base 298b6779d` passes clean over
  the agent's range — the ledger was prepended, not overwritten — and `ORIENTATION.md` was
  written after two consecutive omissions.
- **Beacon correct**: `COMPLETE` with a named Successor, not self-referential.
- It corrected the reviewer on the override's scope (RA-75.3). **`RP-03` satisfied an
  eleventh consecutive turn.**

## RA-75.8 NOTE — the tracker was not written

`Regression_Root_Cause_Tracker.md` is absent from the rung-16 diff, though rungs 10 and 11
wrote it. Not charged — the Review writes the authoritative tracker section regardless, and
the agent's three prior omissions were in documents where the gate floors could have been
threatened. Recorded so the pattern does not drift further.

## RA-75.9 `RP-01` state

**Reframed, not resolved.** The defect is now *missing reconciliation between the accepted
boundary point and the directed-side carriers*, with two mutually exclusive branches:

- **(a)** the accepted and chart points denote **different source entities or sheets** → the
  override is invalid upstream and must be rejected;
- **(b)** they denote the **same** point and only raw face equality is being demanded → the
  consumer's representation contract is wrong.

**These branches imply opposite repairs.** Nothing yet distinguishes them. **Code remains
NOT authorized.** `RP-02` **UNREACHED**.

## RA-75.10 LESSON — when a specification offers two branches with opposite repairs, the next rung measures the discriminator, not the branches

It is tempting to specify both repairs and pick later. The cheaper and safer move is to
measure the one fact that eliminates one branch. Here that fact is small, already
representable in published state, and obtainable from a probe that is a near-copy of one
that has already worked three times.

---

## Rung 17 — scope

`M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE`, **compile-only, rejection-only**, in the
rung 14 producer-side pattern. For **every** grid-boundary node reached in a rejected case,
emit:

1. **whether the override fired** — the `accepted != nullptr` outcome at `:17278` — which
   settles RA-75.3's open question of whether `FirstTo` is also overridden;
2. the **exact source entity** of the chart sample, barycentric-exact: the source vertex id
   when a coordinate is exactly `1`, otherwise the source edge plus its exact parameter when
   a coordinate is exactly `0`, otherwise interior;
3. the **exact source entity** of the accepted boundary point, by the same classification.

One run then answers the branch discriminator: **do the two points denote the same source
entity?** Same entity → branch (b), the override is legitimate and the consumer contract is
at fault. Different entity or sheet → branch (a), the override is invalid upstream. This is
the specification's own F1 falsifier, measured.

Rung 18 harvests; rung 19 defines or implements the repair for whichever branch survives.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by this Review. PR #8 draft/open.

`R4-VIN-01` remains armed at `cdd6dc4a9` — the semantic source is unchanged by rung 16, and
every earlier artifact through `12028682600`, `12030150301` and `12032341939` is a
**baseline, never a comparand**. The 44 RED remain the baseline for `cdd6dc4a9` alone,
candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED (this decision) — the
override is not shown to be junction-specific. Gate C SUSPENDED (RA-65.5, RA-68.3) and moot
for `RP-01` (RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied an eleventh
consecutive turn. The historical `ledgers` failure at `b2b6e6541` remains permanent for any
base earlier than it, is correct, and must not be suppressed.

**Successor:** `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` (rung 17).
