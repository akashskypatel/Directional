# Architecture Review Decision — M6 CP3 R6 corner-assignment authority (rung 10)

**Review turn:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (rung 10)
**Frozen amendment:** RA-71
**Verdict:** **ACCEPTED**, with two charges. It falsified a reviewer prediction **and** a
reviewer-supplied census, and both falsifications are correct.
**Review window:** 2026-10-16T02:10:04Z — 2026-10-16T02:52:18Z
**Semantic source:** unchanged at `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`

---

## RA-71.1 Provenance, re-derived

| check | result |
|---|---|
| snapshot run `38837317846` | `conclusion=success`, `head_sha=c85bd3600` |
| snapshot artifact `12019178209` | ZIP SHA-256 **recomputed** `37dab2b2f1292e7f0a530042b90be1d9813ee4e7eb4e76df7cd50226c2e98bdb`, matches provider digest |
| snapshot manifest | **5,656 entries, 5,656 OK / 0 BAD** |
| `src`/`include`/`tests` at `c85bd3600`, `a143af264`, `HEAD` | **tree-identical** — `72c8fec8e8…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |

The tree-object identity is the stronger statement and it is the one that matters: the
specification read **exactly** the bytes that were compiled at rung 8 and measured at rung
9. No new semantic source.

---

## RA-71.2 My prediction was falsified, and the falsification is correct

RA-70.14 predicted that `src/geometry/SurfaceCellTracing.cpp:11269` was the locus, on the
reasoning that it keeps `xy.point`, discards `yx.point`, and reduces the disagreement to a
positional `closureError`. **Named falsifier (a) holds.** Verified from source:

```cpp
:19781    if (network.phaseFront.is_produced()) {
:19790        proposal.corners = cell.corners;
              ...
:19801    if (network.phaseFront.is_rejected()) {
:19802      return network;
:19803    }
:19814    SurfaceCellProposal proposal = make_surface_cell_proposal(...);
```

The measured 44 are **rejections**. Control flow returns at `:19802` and never reaches
`:19814`, so `make_surface_cell_proposal` — and with it `:11269` and `:10479` — is
unreachable on the measured path. `:19790` sits inside the `is_produced()` branch and is
equally unreached.

**RA-70.14 is WITHDRAWN**, not merely unconfirmed. The reasoning about `:11269` discarding
a walk without comparing faces remains true of that fallback and explains nothing about
`RP-01`.

## RA-71.3 My census was wrong, and the way it was wrong is the lesson

I supplied three writers and instructed the turn to "confirm this yourself and say so if
you find a fourth." It did, and the correction is structural, not a miscount.

`include/directional/geometry/SurfaceCellTracing.h` declares an identically-typed
`corners` member on **two different structs**:

| header line | owning struct | member |
|---|---|---|
| `:1719` | `SurfacePhaseFrontCell` | `std::array<SurfaceTracePoint, 4> corners;` |
| `:2160` | `SurfaceCellProposal` | `std::array<SurfaceTracePoint, 4> corners;` |

**All three writers I nominated — `:10479`, `:11269`, `:19790` — write
`proposal.corners`, i.e. `SurfaceCellProposal::corners`.** None of them writes
`SurfacePhaseFrontCell::corners`, which is the field A4 actually judges. My census
conflated two objects that share one identifier name and one type. **That is precisely
the error class I charged at RA-67.13 and again at RA-70.8, committed one rung after
freezing the lesson.**

The method was blind too, in two independent ways:

- my first census grep excluded `cell\.corners\[static_cast` in order to filter *reads*
  such as `edge.from = cell.corners[side]`, and that exclusion removes the real write;
- my second, "unfiltered", grep required `=[^=]`, a character after the equals sign —
  and the real write at `:12986` ends its line with `=`, continuing on `:12987`.

Neither grep could have found the target. The sole writer of
`SurfacePhaseFrontCell::corners` is:

```cpp
:12986      cell.corners[static_cast<std::size_t>(corner)] =
:12987          points[static_cast<std::size_t>(nodeIds[corner])];
```

confirmed by an unfiltered census returning exactly four `corners` assignments in the
file — `:10479`, `:11269`, `:19790` (all `proposal.corners`) and `:12986`.

### RA-71.4 LESSON — an enumeration is only as bounded as the filter that produced it

A census presented as exhaustive ("exactly three producers") inherits every blind spot of
the query that produced it, and a reviewer who hands a successor a bounded list converts
their own filter into the successor's search space. State the query, not just its result,
so a successor can falsify the boundary rather than work inside it. The turn did exactly
that by reading the call graph instead of trusting the list.

---

## RA-71.5 The named locus is correct, and verified line by line

**Named locus:** the planar phase-front lattice point-to-source-face selection in
`point_on_source` (`:11477-11509`), made authoritative for corner faces by
`build_uniform_phase_front_for_faces` at `:12949-12958` and `:12986-12987`, with no
reconciliation against `boundaryPaths`.

| step | anchor | verified content |
|---|---|---|
| producer chosen | `:17884-17890` | planar `build_uniform_phase_front_for_faces` is called first; `build_periodic_annulus_phase_front_for_faces` runs only on `NotApplicable`. The fixture is explicitly planar-and-rectangular. |
| face selected | `:11478-11509` | loops `for (const authority::SourceFaceId faceId : activeFaces)`, `continue`s on failed barycentric containment, and on the **first** success does `point.face = face; point.barycentric = barycentric; return true;` — no reference to side, path, cell or route |
| selected **per node** | `:12949-12958` | `points[node_index(u, v)]` is filled once per lattice node, so one face choice is shared by every side and every cell touching that node, made **before any path exists** |
| copied to the corner | `:12986-12987` | `cell.corners[corner] = points[nodeIds[corner]]` — sole writer |
| paths built separately | `:13012-13021` | `segment_on_source(...)` fills `cell.boundaryPaths[side]` independently |
| endpoints inherit it | `:13033-13035` | `edge.from = cell.corners[side]`, `edge.to = cell.corners[(side+1)%4]` |

This is a better answer than my hypothesis. It explains the RA-70.7 asymmetry directly:
`from` and `to` are **different lattice nodes**, each independently first-matched, and
only the node sitting on the shared junction vertex has more than one admissible face.

---

## RA-71.6 Addition — this is an ordering dependency, not a tolerance defect

`:11483` sets `constexpr double tolerance = 1.0e-10`; containment admits
`[-tolerance, 1 + tolerance]`; and `:11495-11501` snaps `|b| <= tolerance` to exactly `0`
and `|b - 1| <= tolerance` to exactly `1`.

A lattice point lying **exactly on a shared source vertex** therefore satisfies the
containment test in **every incident face**. In the measured fixture vertex 4 is a corner
of `f0, f1, f3, f4, f6, f7`, and the point is at the vertex, so the barycentric test
passes in all six. **The winner is decided purely by `activeFaces` iteration order.**

Two consequences, both load-bearing:

1. **No epsilon change can repair this.** Tightening or loosening `tolerance` moves which
   *near*-vertex points are ambiguous; it cannot make an exact vertex unambiguous, because
   the vertex genuinely belongs to every incident face. Any repair that touches the
   tolerance is misdirected, and the first instinct of a later turn will be to touch it.
2. **The attribution is complete without identifying the winning face.** Since the
   selection is iteration-order-dependent and every incident face is admissible, *any*
   order-dependent corner face is the defect. Which face wins is a detail of
   `activeFaces` ordering, not a precondition for naming the producer.

## RA-71.7 Addition — the reconciler exists, and it is blind; third instance of the pattern

The specification says nothing reconciles the corner against the boundary path. The
sharper truth: **the designated reconciler exists, is called twice, and compares the wrong
thing.**

`orient_and_validate_phase_front_cell` calls `validate_closed_boundary_paths` at `:12718`
and again at `:12736`. Inside it (`:7319-7357`):

```cpp
const auto valid = [&](const SurfaceTracePoint &point) {
  return point.face >= 0 && point.face < faces.rows() && ... };
const auto close = [&](const SurfaceTracePoint &a, const SurfaceTracePoint &b) {
  if (!valid(a) || !valid(b)) return false;
  return (point_position(vertices, faces, a) -
          point_position(vertices, faces, b)).norm() <= tolerance; };
...
if (!close(start, corners[side]) ||
    !close(end,   corners[(side + 1) % 4])) return CellRejectionReason::Closure;
```

`valid()` applies a **bounds** check to `point.face`, never an identity check, and `close()`
is a pure 3D distance test. A corner in `f7` and a path endpoint in `f3` that are the same
physical point at vertex 4 pass at distance **exactly 0**. The comparison that would have
caught `RP-01` is made, twice, and cannot see the defect.

**This is the RA-68.3 pattern for the third time.** At RA-68.3 the junction certificate
existed but was ordered after the admission it would authorize. Here the reconciler exists
but compares position where identity is required. **Record the generalization: when a
missing authority is sought in this pipeline, look first for it existing in a form that
cannot do the job.**

Informational: `valid()` uses `faces.rows()` rather than `face_count()` — the RA-66.6
asymmetry locus, unchanged and still not authorized for repair.

## RA-71.8 Falsifiers (c) and (d) settled, not assumed

- **(c)** "a pre-A4 check already requires the selected corner's source face to belong to
  the oriented owning boundary path" — **does not hold**; RA-71.7 shows the only such check
  is positional.
- **(d)** "a later mutation between `:12987` and A4 changes that source face" — **does not
  hold**. `reverse_phase_front_cell_cycle(cell)` at `:12730` permutes the cycle and
  recomputes positions; it reorders corners without rewriting any corner's `face`. The
  unfiltered census confirms no other writer of `SurfacePhaseFrontCell::corners` exists.

The attribution therefore survives all four of its own named falsifiers.

---

## RA-71.9 CHARGE — a mandated verification was omitted and not disclosed

The turn was instructed verbatim to run **both** gates and report both:

```
python3 -I .agents/Directional/tools/review_check.py boundary
python3 -I .agents/Directional/tools/review_check.py ledgers --base fa6495a7c
```

The closeout table carries a `review_check.py boundary` row and **no `ledgers` row**. The
append-only ledger gate was not reported, and its absence was not declared. This is the
**RA-66.4 category — a mandated item silently dropped — and therefore a repeat.** Both
gates have been run by this Review and both pass; the defect is the silence, not the
state. Minor and not charged separately: `review_check.py` was invoked without `-I`.

## RA-71.10 CHARGE — the turn under-claims its own completed attribution, and this is now a pattern

The specification writes that "the exact per-vertex choice responsible for f7 remains the
**reviewable attribution**, not an executed new measurement", which reads as a confession
of incompleteness. Its own evidence completes the attribution: per RA-71.6 the selection
is iteration-order-dependent across six admissible faces, so the producer is named and the
defect established **without** identifying the winning face. The turn had the argument and
declined to draw it.

This is the **third consecutive turn** in the under-claim category — RA-67.9 (harvested
interval fields never examined), RA-70.7 (the path-identity and `hit_from` facts left
unstated), and now RA-71.10. **Recorded as a pattern rather than an isolated lapse:** the
Implementation Agent's measurements have repeatedly been stronger than its claims about
them. The failure mode is conservative, which is far preferable to the opposite, but it
costs a rung each time a reviewer has to extract the result.

## RA-71.11 Credits

- **It falsified a reviewer prediction and a reviewer-supplied census in the same turn**,
  and did so on the merits with a reachability argument, explicitly declining to name
  `:11269` "merely because it discards one of two corner walks." **`RP-03` satisfied a
  seventh consecutive turn.**
- It stated **four explicit falsifiers** for its own attribution, all four of which this
  Review was able to settle from source — which is what makes the attribution reviewable.
- It refused to claim a push it could not verify from inside a snapshot
  ("Require GitHub remote commit/ref evidence; no local-origin claim from snapshot").
  Correct provenance discipline; the push did land, verified independently.
- Guidance, not a charge: the closeout `CHANGELOG` row names
  `.agents/Directional/CHANGELOG.md` while **root `CHANGELOG.md` is canonical**. This
  matches established practice — the Review writes the root ledger — but the row should
  name which file it means.

## RA-71.12 `RP-01` state

`RP-01 AUTHORITY_DOMAIN_CONFLATION` advances from *producer locus localized* to **producer
locus NAMED AND VERIFIED**:

> the corner's source face is selected per **lattice node** by first-match over
> `activeFaces` in `point_on_source` (`:11477-11509`), made authoritative for
> `SurfacePhaseFrontCell::corners` at `:12949-12958` / `:12986-12987`, while the designated
> reconciler `validate_closed_boundary_paths` (`:12718`, `:12736` → `:7319-7357`) compares
> corner against path by 3D position and is blind to face identity.

**Code is still NOT authorized**, because the RA-65.5 producer test has not been applied to
the repair family. `RP-02` remains **UNREACHED**.

---

## Rung 11 — scope

`M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC`, **documents only**. Three questions,
all answerable statically:

1. **Apply the RA-65.5 producer test to the repair family.** Enumerate every witness a
   repair needs and name its existing publisher. Candidates already published:
   `activeFaces` plus the barycentric containment test yields the *admissible* face set at
   a node; `boundaryPaths[side]` segments carry `segment.face`. This may be the first
   repair family whose witnesses all already exist — state the outcome either way.
2. **Settle per-node versus per-side.** A lattice node is shared by up to four sides and
   four cells, and `:12949-12958` makes **one** choice for all of them. If their traced
   paths lie in different faces, no single per-node face can satisfy every consumer, and
   the repair is structural — a per-side corner face or an explicit reconciliation pass —
   not a selection-order fix. Derive the answer from the source plus the RA-70 measurement.
3. **State what a face-identity check at `:12718` would and would not achieve.** It would
   **relocate** the failure from a late A4 `carrier-orientation` rejection to an honest
   cell-production rejection at the true producer. **It would not repair `RP-01`** — the
   cells would still be rejected. Do not let a later rung mistake relocation for repair.

No code, no compile, no runtime, no repair implementation. Naming the repair shape and its
blast radius is the deliverable.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **30+12+449+6 = 497** — all unchanged. No promotion, no stable event, no
regression recurrence, no gate credit, no ledger recomputation, no 497 execution, no
benchmark, no Directional binary executed. No source, test, selector, binary, harness or
workflow change by this Review. PR #8 draft/open.

`R4-VIN-01` remains armed at `a143af264` — the semantic source is unchanged by rung 10, and
artifacts `11994726341`, `11996317553`, `12005034654`, `12010485442` and `12019178209` are
**baselines, never comparands**. The 44 RED remain the baseline for `a143af264` alone,
candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN (this decision).
Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01` (RA-70.11).** `PROCESS-01`
discharged. `RP-03` satisfied a seventh consecutive turn.

**Successor:** `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` (rung 11).
