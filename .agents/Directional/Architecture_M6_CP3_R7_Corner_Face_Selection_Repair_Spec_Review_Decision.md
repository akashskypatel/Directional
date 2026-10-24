# Architecture Review Decision — M6 CP3 R7 corner-face selection repair (rung 11)

**Review turn:** `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` (rung 11)
**Frozen amendment:** RA-72
**Verdict:** **ACCEPTED WITH AMENDMENT.** All three mandated questions answered; the repair
*shape* is admissible; its central *premise* is unverified and the evidence runs against it.
**This decision also amends my own RA-71.6**, which the source bytes contradict.
**Review window:** 2026-10-16T03:20:11Z — 2026-10-16T04:06:44Z
**Semantic source:** unchanged at `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`

---

## RA-72.1 Provenance, re-derived

| check | result |
|---|---|
| snapshot run `38843434916` | `conclusion=success`, `head_sha=491914f93` |
| snapshot artifact `12021892076` | digest `005211e882847639d563b74650da4f753a5b0023ed599d92520959a0cbf218bc`, matches |
| `src`/`include`/`tests` at `491914f93`, `a143af264`, `HEAD` | **tree-identical** — `72c8fec8e8…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |

The tree-object identity settles the decisive question outright: the specification read
exactly the bytes compiled at rung 8 and measured at rung 9. The turn volunteered that
"the local snapshot was not a Git clone" — a limitation disclosed rather than papered over.

## RA-72.2 The deliverable is complete

All three mandated questions are answered, in order, with source citations. Verified
individually:

- **Q1, producer test** — answered with a six-row witness/publisher table and an explicit
  verdict.
- **Q2, per-node versus per-directed-side** — answered **per-directed-side**, structural.
- **Q3, relocation versus repair** — answered in §4, explicitly, and it goes further than
  asked by noting a global face-identity check would **over-reject** legitimate
  adjacent-face representations of a canonical source vertex.

Seven falsifiers (F1–F7) are stated for its own proposal.

## RA-72.3 The producer test verdict is substantially right — and this is the first repair family to pass it

Verified from the header and the call order:

- `SurfaceTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:1211-1232`)
  carries `int face`, `startBarycentric`, `endBarycentric`, `family`, `sign`,
  `std::optional<FieldChartId> sourceChart`, a typed `authority::CanonicalRoute entryRoute`
  and `std::optional<HardRailId> railId`.
- `cell.boundaryPaths[side]` is filled by `segment_on_source` at `:13012-13021`, **before**
  `SurfaceFrontEdge` is constructed at `:13030-13035`.

So a face-valued, barycentric-exact, chart- and route-attributed endpoint **per directed
side** is already published before the edges are minted. Every prior repair family failed
RA-65.5 for want of a publisher; **this one does not.** That is a real advance and the
turn is right to say so.

The accompanying caution is also right: possessing the evidence is not the same as
propagating it as authoritative, and the implementation must fail closed where identity,
chart or transport cannot be certified.

## RA-72.4 Per-directed-side is the correct structural answer

`point_on_source` chooses one face per `(u,v)` node at `:12949-12958`, before any boundary
segment exists; `:12986-12987` copies it into the corner; `:13033-13035` copies the corner
into the edge endpoints. Each of the four directed paths is built independently at
`:13012-13021` and may approach a shared node from a different incident triangle. A node
belongs to up to four cells, each contributing an incoming and an outgoing side incidence.
**One `SurfaceTracePoint::face` cannot be the authoritative face of all of them**, and the
turn's conclusion that a per-node fix works only under a *proved* special condition is
sound. Keeping one canonical geometric node while allowing several side-occurrence
representations is the right shape.

## RA-72.5 §4 is correct: relocation is not repair

A literal `corner.face == boundaryPaths[side].front().face` test inside
`validate_closed_boundary_paths` would move the measured 7-vs-3 discrepancy to a
producer-stage closure rejection and make no cell succeed. The turn states this plainly
and refuses to count it as recovery. It also identifies the over-rejection risk
unprompted. **No later rung may count relocation as repair.**

---

## RA-72.6 AMENDMENT — RA-71.6 is amended; both selectors are minimum-face-row, not arbitrary order

RA-71.6 states that the corner's face "is decided purely by `activeFaces` iteration
order". **The source contradicts this, and the clause is amended.** Verified chain:

| step | anchor | content |
|---|---|---|
| the list is sorted | `src/geometry/SurfaceCellTracing.cpp:17823` | `std::sort(work.sourceRows.begin(), work.sourceRows.end());` before it is passed as `activeFaces` at `:17887` |
| the sort key is the row | `include/directional/authority/AuthorityIds.h` | `using SourceFaceId = SemanticId<detail::SourceFaceTag>`; `SemanticId` holds one `std::size_t value_`, exposes `index()` returning it, and declares `auto operator<=>(const SemanticId &) const = default` |
| the row *is* the index | `SurfaceCellTracing.cpp:189-195` | `source_face_row` returns `faceId.index()` |

Therefore `activeFaces` is **ascending by face row**, and `point_on_source`'s first match is
the **minimum admissible face row**. Independently, `segment_on_source` selects by
`(selectedFace < 0 || interval.face < selectedFace)` at `:12124-12130` — also the
**minimum** covering face row.

**Both disambiguation rules are the same rule.** The "arbitrary iteration order"
characterization is **WITHDRAWN**.

What survives untouched is RA-71.6's operative conclusion, and it survives on better
grounds: `face_barycentric_from_uv` (`:11450-11474`) is a plain planar inverse affine map
through `phase_uv`, failing only when `|determinant| <= 1.0e-18`, so for a UV point lying
exactly on a shared source vertex **every incident active face yields a valid barycentric
inside tolerance**. The ambiguity is real, it is not numerical, **no epsilon change can
repair it**, and the selection is still made with no reference to the consuming side. The
defect is a **side-independent deterministic rule**, not an arbitrary one.

## RA-72.7 CHARGE — the specification inherited the reviewer's premise instead of re-deriving it

The turn describes `point_on_source` as returning "the first face in `activeFaces`" in the
sense that made my clause wrong, and separately labels `segment_on_source`'s midpoint
choice "an independently order-sensitive *path-face* tie-break". Both characterizations
are off: `activeFaces` is sorted, and both selectors are minimum-row. The §1 "Limit on
determinism" paragraph therefore warns against an asymmetry that does not exist in the
form described, and spends its caution in the wrong place.

**Rung 10 refused a reviewer-supplied census and was credited for it (RA-71.2, RA-71.3).
Rung 11 accepted a reviewer-supplied mechanism unchecked.** The obligation is the same in
both directions.

## RA-72.8 The repair contract's central premise is unverified, and the measurement runs against it

This is the substantive finding, and it is why the verdict is *with amendment*.

Both selectors take the minimum admissible row over a sorted, non-degenerate set. At a
node sitting exactly on a shared vertex, every incident active face is admissible. **A
minimum-row rule cannot return 7 from a set that contains 3.** Yet RA-70 measured, in all
21 junction cases, `toFace=7` on the corner and `{3}` on that side's traced path.

The only consistent reading is that **the two selections draw from different face sets** —
the node-level `activeFaces` for that region must exclude every row below 7 that the
side's interval set includes.

§3.2 of the contract instructs that "the end is `path.back().face/endBarycentric`". On
current evidence that would bind the corner to a face the **node-level containment test
never saw**. That may well be the correct repair; the specification does not establish
that it is legal, and does not notice the tension. **A repair whose premise is contradicted
by the measurement it cites must not be implemented before the premise is measured.**

Note this does not disturb RA-71.5 (the locus), RA-71.7 (the blind reconciler), RA-72.3
(the producer test) or RA-72.4 (per-directed-side). It disturbs only the step that assumes
the path's face is available to the corner.

## RA-72.9 CHARGE — both mandated gates omitted, and the closeout table dropped

RA-71.9 charged, one rung ago, the omission of the `ledgers` gate from a closeout table
that at least reported `boundary`. This rung reports **neither gate**, and the duty table
that carried the row is gone entirely. That is escalation, not repetition. Both gates have
been run by this Review and both pass.

Also dropped: **`ORIENTATION.md` was not updated**, though both preceding Definition turns
updated it, leaving the orientation document describing RA-71 as current while `STATUS`
recorded rung 11 complete. This Review restores currency.

## RA-72.10 Credits

- **Root `CHANGELOG.md` was written this turn**, correcting the RA-71.11 guidance within one
  rung.
- It **declined to authorize its own code successor**, writing "No code implementation is
  authorized by this record alone" and leaving `Successor: UNKNOWN` with reasoning in the
  owning document — the RA-63.13 shape. **`RP-03` satisfied an eighth consecutive turn.**
- It **rejected sorting `activeFaces` as a general repair** — the right conclusion, reached
  for a reason that turns out to be wrong, since the list is already sorted. The conclusion
  is in fact stronger than argued: changing that order would alter the corner face of
  **every** node in the pipeline, not only the junction ones.
- It disclosed that the local snapshot was not a Git clone, and stated seven falsifiers for
  its own proposal.

## RA-72.11 LESSON — re-derive the premise you were handed, not only the question

A specification inherits the reviewer's premises unless it re-derives them. Rung 10
demonstrated the correct behaviour by refusing a census; rung 11 answered three
well-posed questions on top of a mechanism it never checked, and the mechanism was wrong.
**Check the ground you are asked to build on, not just the thing you are asked to build.**

## RA-72.12 `RP-01` state

Repair **shape** admissible — per-directed-side endpoint binding, with the canonical
geometric node retained. Repair **premise unverified** — the node's admissible face set at
the failing corner has never been observed, and minimum-row selection implies it differs
from the side's covering set. **Code remains NOT authorized.** `RP-02` **UNREACHED**.

---

## Rung 12 — scope

`M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE`, **compile-only, rejection-only**, in the
pattern that already worked at rungs 8–9. For a rejected edge only, extend the existing
post-decision probe block at `:19360` to emit:

1. the **full** admissible face set at each endpoint node — every active face passing the
   `point_on_source` containment test, not merely the first;
2. the region's `activeFaces` content as actually presented to the producer;
3. the side path's covering face set, already available, for direct comparison.

Then dispatch a compile package and stop. Rung 13 harvests; rung 14 implements only if the
premise holds. The question the probe settles is single and decisive: **does the node's
admissible set contain the path's face?** If yes, the §3.2 binding is legal and the repair
proceeds. If no, the defect is upstream in region face membership and the repair shape
changes again.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by this Review. PR #8 draft/open.

`R4-VIN-01` remains armed at `a143af264`; artifacts `11994726341`, `11996317553`,
`12005034654`, `12010485442`, `12019178209` and `12021892076` are **baselines, never
comparands**. The 44 RED remain the baseline for `a143af264` alone, candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-71.6 AMENDED
(this decision) — its "arbitrary iteration order" clause withdrawn, its no-epsilon
conclusion retained on firmer ground. Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for
`RP-01` (RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied an eighth consecutive turn.

**Successor:** `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` (rung 12).
