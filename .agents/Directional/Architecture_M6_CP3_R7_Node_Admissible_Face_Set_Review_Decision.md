# Architecture Review Decision — M6 CP3 R7 node admissible-face set (rungs 12 and 13)

**Review turn:** `M6-CP3-R7-NODE-ADMISSIBLE-FACE-SET-REV`
**Adjudicated:** `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` (rung 12) and
`M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` (rung 13)
**Frozen amendment:** RA-73
**Verdicts:** both **ACCEPTED**. **RA-72.8 is falsified and WITHDRAWN** — correctly, by the
turn. One charge on the census's measurement point, one on the beacon.
**Review window:** 2026-10-16T04:55:02Z — 2026-10-16T05:41:30Z
**Semantic source:** `4d64b7684ac7ec2d0655f96c88ecf05f2906bca7` (new — `R4-VIN-01` re-arms)

---

## RA-73.1 Rung 12 — the probe is neutral, and it was built the right way

Structural neutrality verified by brace accounting, not asserted: the rejection branch opens
at `src/geometry/SurfaceCellTracing.cpp:19360`, the census insertion sits inside it at
`:19504-19576`, and the branch closes at `:19639`. `git show --numstat` reports `73 0` on
one file. No acceptance path can observe it.

**The technique is better than what I specified.** I offered a diagnostic re-implementation
of the containment test. The turn instead **calls `point_on_source` itself**, once per face
with a singleton `{face}` list:

```cpp
for (const auto face : activeFaces) {
  SurfaceTracePoint candidate;
  if (!point_on_source(vertices, faces, frame, {face}, uv, candidate)) continue;
  ...
}
```

The singleton defeats first-match-returns-early while leaving the production predicate
untouched, so the test is **faithful by construction** rather than by careful copying. That
removes an entire class of instrument error, and it is the correct reading of the
instruction's intent over its letter.

Absence is reported as absence throughout — `missing-region`, `invalid-region-face`,
`Frame=not-planar`, `none` — so RA-66.4 is not repeated.

## RA-73.2 Chain and artifacts, re-derived

| check | result |
|---|---|
| probe commit `4d64b7684` cpp blob | `bfcc7f88ee0222752d4309d157becc3e480ad514` = **HEAD** |
| `include` / `tests` at `4d64b7684` and HEAD | **byte-identical** — no header, fixture or test change |
| compile artifact `12024554349` | digest `c824a6aa4361…`, matches report |
| result artifact `12025322701` | ZIP SHA-256 **recomputed** `cd7ebc41eb1e…`, matches provider digest |
| result manifest | **49 OK / 0 BAD** |
| `execution-boundary.txt` | `planned=44 executed=44 red=44 missing=0 postflight=true exit=0`, `compile=false relink=false benchmarks=false selector497=false` |
| run `38852145039` | `conclusion=success`, `head_sha=9eba29a39` |
| disclosed failure `38851813094` | independently **`conclusion=failure`** |
| disclosed failure `38851975506` | independently **`conclusion=failure`** |

Both orchestration failures are real and were disclosed when the successful third attempt
would have concealed them — one an invalid uniqueness assumption on a deliberately repeated
identity, one a ZIP extraction that dropped executable permissions so zero tests were
selected. Neither produced evidence and neither was accepted. **`RP-03` satisfied a ninth
consecutive turn.**

## RA-73.3 The census, re-derived independently

96 side-occurrence rows, `evidence=COMPLETE` on every one, `frame` empty throughout (so
`Frame=not-planar` never fired), multiplicity `[(1,42),(3,2)]` as at RA-70. Exactly four
tuples:

| n | condition | side | active | from_admissible | to_admissible | path |
|---:|---|---|---|---|---|---|
| 27 | `not-same-interior-carrier-point` | First | `0,1,4,5` | `0` | `0` | `0` |
| 27 | `not-same-interior-carrier-point` | Second | `2,3,6,7` | `3` | `2,3` | `3` |
| 21 | `carrier-orientation` | First | `0,1,4,5` | `0` | `0,1,4` | `0` |
| 21 | `carrier-orientation` | Second | `2,3,6,7` | `3,6,7` | `3` | `3` |

## RA-73.4 RA-72.8 is FALSIFIED and WITHDRAWN

I deduced at RA-72.8 that, since both selectors take the minimum admissible row, the node's
`activeFaces` "must exclude every row below 7 that the side's interval set includes." The
measurement contradicts this outright: the junction `Second` side's `from_admissible` is
`{3,6,7}` — **it contains 3**. The two selections are not drawing from sets that exclude the
path's face. **RA-72.8 is withdrawn**, and the turn is credited for falsifying it.

## RA-73.5 But the measurement contradicts RA-72.6 at exactly one corner, and the asymmetry is the finding

`:19365-19366` fixes which points the older fields name:

```cpp
const auto &fromPoint = firstMissing ? first.from : first.to;
const auto &toPoint   = firstMissing ? second.to  : second.from;
```

On a second-certificate failure, RA-70's `FromFace=0` is `first.to` and `ToFace=7` is
`second.from`. Against the census:

| corner | published face | its admissible set | minimum | verdict |
|---|---:|---|---:|---|
| `first.to` | **0** | `{0,1,4}` | 0 | **obeys minimum-row** |
| `second.from` | **7** | `{3,6,7}` | 3 | **violates minimum-row** |

Same rejection, same source vertex, two cells in two regions — one corner takes the smallest
admissible face and the other takes the **largest**. **A single global minimum-row rule
cannot explain both**, so RA-72.6's conclusion does not survive as a universal account of the
published corner.

**And the discriminator is set cardinality.** In the 23 controls the `Second` side's
`from_admissible` is the **singleton** `{3}` — there is nothing to get wrong, and 3 is
published. In the 21 junction cases it has **three** members and the largest is published.
*The junction population is exactly the population where that corner sits where three faces
are admissible.* That is a complete separator, measured, with no exceptions.

## RA-73.6 CHARGE — the census measures admissibility at the wrong UV, and the headline overstates what follows

The probe computes its sample point as

```cpp
const Eigen::Vector2d uv = phase_uv(frame, point_position(vertices, faces, point));
```

— the **published, post-snap** position of the corner. The producer sampled a **lattice** UV,
`(frame.minU + stepU*u, frame.minV + stepV*v)` at `:12951-12952`. These are not the same
point, and the difference is load-bearing: `point_on_source` snaps any barycentric within
`1.0e-10` to exactly `0` or `1` (`:11495-11501`), so a lattice UV lying *near* vertex 4 can
pass containment in only one face **before** snapping and then be published *at* the vertex,
where all three pass. **The set the census measured is therefore not the set the producer
chose from**, and RA-73.5's apparent violation of minimum-row may be entirely an artefact of
measuring after the snap.

The probe's comment discloses the choice and gives a reason (bounded-disk sides may use
separately prescribed conforming boundary subdivision positions), so this is a reasoned,
visible decision rather than an oversight. What is charged is that the consequence was not
drawn, and that the report's headline — "**Yes, for every measured rejected side**" and "the
previously suspected absence … **is falsified by this probe**" — states more than the
evidence supports for the decision it was built to enable. The report's own later sentence
is the accurate one: "the present census does **not** establish why the producer selected 7
despite the later independently measured admissible alternative 3." **That sentence should
have been the headline.** Fourth turn in the claim-calibration category (RA-67.9, RA-70.7,
RA-71.10, now RA-73.6) — though note this one errs toward *over*-claiming, where the prior
three under-claimed.

## RA-73.7 The producer's lattice UV is not reconstructible from published state

Verified while scoping the next rung, and it constrains it. `UniformPhaseFrame`
(`:11421-11426`) carries `minU`, `maxU`, `minV`, `maxV`, `faceBranchRotation` and
`faceChart` — but **no `stepU`/`stepV` and no node counts**. `cell.lattice[k].latticeCoordinate`
is published at `:13005-13008` and reaches the consumer through
`SurfaceFrontEdge::fromLattice`/`toLattice`, but the lattice **coordinate** without the
**step** does not determine the UV. So a consumer-side probe at `:19360` cannot rebuild the
producer's sample point exactly. Rung 14 must either recover the step from published state —
and say how — or move the emission producer-side.

## RA-73.8 CHARGE — the beacon was left `IN_PROGRESS` with a self-referential `Successor`

`STATUS` reads `Turn: M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST`,
`Status: IN_PROGRESS`, `Successor: M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` — the
turn naming itself as its own successor. **Four consecutive NEXT_TURN blocks have instructed
"leave `Successor` EMPTY while in progress, never self-naming (RA-67.11)."** This is a
machine-read state field, not prose, and a successor reading it is handed a cycle. The
durable closeout was also left incomplete: `Regression_Root_Cause_Tracker.md` and
`ORIENTATION.md` were not updated. This Review closes the beacon and restores both.

**Credited, separately:** the commit subject says "preserve TB6 R7 **incomplete**
durable-closeout beacon" — the turn declared the incompleteness rather than faking a close,
which is the right instinct and the reason this is one charge and not two.

## RA-73.9 `RP-01` state

The repair premise is **sharper, not settled**. The question has moved from "does the node's
admissible set contain the path's face?" — answered **yes**, at the published position — to
"**what set did the producer choose from, and why did it take the largest member of it at
one corner and the smallest at the other?**" Until that is measured at the producer's own
sample point, the R7 §3.2 binding remains unauthorized. **Code remains NOT authorized.**
`RP-02` **UNREACHED**.

## RA-73.10 LESSON — a faithful instrument at the wrong sample point is still the wrong measurement

Rung 12 eliminated instrument error completely by calling the production predicate instead
of copying it, and the result is still not decisive, because the *point* it sampled was not
the point the producer sampled. **Fidelity of the test and fidelity of the input are
separate obligations; satisfying one conspicuously well does not discharge the other.**
When a measurement is built to adjudicate a producer's choice, sample where the producer
sampled, and state explicitly which input you used and why.

---

## Rung 14 — scope

`M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE`, **compile-only**. Emit, for the ambiguous corner
only, the **pre-snap** candidate evidence at the **producer's own lattice UV**: the sample UV
itself, and for each active face the raw unsnapped barycentric from `face_barycentric_from_uv`
together with the pass/fail of the containment test. The single decisive question: **at the
producer's sample point, is the published face the minimum admissible one?** If yes,
RA-72.6 stands and the snap explains RA-73.5; if no, the selection rule is something neither
document has identified and the repair shape changes again.

Rung 15 harvests; rung 16 implements only if the premise survives.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `4d64b7684`.** Every earlier artifact — `11994726341`,
`11996317553`, `12005034654`, `12010485442`, `12019178209`, `12021892076` and now
`12024554349` — is a **baseline, never a comparand**. The 44 RED are the baseline for
`4d64b7684` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-71.6 AMENDED
and now contradicted at one corner (RA-73.5) pending rung 15. RA-72.8 WITHDRAWN (this
decision). Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01` (RA-70.11).**
`PROCESS-01` discharged. `RP-03` satisfied a ninth consecutive turn.

**Successor:** `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` (rung 14).
