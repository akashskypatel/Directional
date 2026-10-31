# Architecture Review Decision — M6 CP3 R5 route/path reconciliation (rungs 8 and 9)

**Review turn:** `M6-CP3-R5-ROUTE-PATH-RECONCILIATION-REV`
**Adjudicated:** `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` (rung 8) and
`M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` (rung 9)
**Frozen amendments:** RA-69 (rung 8), RA-70 (rung 9)
**Verdicts:** both **ACCEPTED**. RA-69 carries one charge; RA-70 carries two.
**Review window:** 2026-10-16T01:00:12Z — 2026-10-16T01:48:30Z
**Semantic source:** `a143af264bc8b33f0e1b2f8def16b2479b53d5fc` (new — `R4-VIN-01` re-arms)

---

## RA-69 — rung 8, the route/path probe

### RA-69.1 Decision neutrality is verified structurally, not asserted

The requirement was that the emission sit inside the rejection branch and change nothing
reachable from acceptance. Verified by brace accounting over
`src/geometry/SurfaceCellTracing.cpp`, not by reading the patch's intent:

| anchor | depth | content |
|---|---|---|
| `:19360` | 1 | `if (!firstEndpoint \|\| !secondEndpoint) {` |
| `:19459` | 2 | last pre-existing probe line |
| `:19501` | 1 | end of the inserted lambda |
| `:19566` | 0 | rejection branch closes |
| `:19567` | 0 | `std::vector<SurfaceHardRailRouteJunctionCertificate> junctions;` |

The 42 inserted lines are strictly inside a branch that closes before the junction
certificate is constructed. `git show --numstat` reports `42 0` on one file. **No
acceptance path can observe the probe**, which is the property that makes the measurement
admissible at all.

### RA-69.2 The only control flow in the insertion is lambda-local

`return item.id == edge.filledCell;` is the `std::find_if` predicate; `return;` exits
`append_traced_faces`. Neither leaves `build_surface_cell_network`. Nothing in the
insertion writes `phaseFrontState`, mutates a certificate, touches a predicate, or
constructs a rejection string.

### RA-69.3 Absence is reported as absence

The turn was told that a field it could not reach must be emitted empty and named, never
synthesised as `0`. It emits three distinct sentinels — `missing-cell` when the owning
cell is not found, `missing-side` when `filledSide` is outside `[0,4)`, and `none` for an
empty traced set — and the harness treats each as non-numeric and therefore incomplete.
**RA-66.4's silent omission is not repeated.**

### RA-69.4 The compile chain is closed by content

Every link re-derived independently, none accepted from the record:

| link | verified value |
|---|---|
| snapshot run `38828612903` | `conclusion=success`, `head_sha=48ba0b6b1` |
| snapshot artifact `12016346107` | digest `174cb54bb46b…`, matches |
| `48ba0b6b1` vs `5be5e123e` | `src`/`include`/`tests` **tree-identical** |
| probe commit `a143af264` | `src` changes, `include`/`tests` byte-identical |
| cpp blob at `a143af264` | `c12910dcc15a01e21d074039cc65d79c2234a5a6` |
| dispatcher commit `ffcaa5933`, run `38829147491` | `conclusion=success` |
| compile artifact `12015849679` | ZIP SHA-256 **recomputed** `92a014a6d0bc…`, matches |
| package manifest | **28 OK / 0 BAD** |
| `metadata/source-commit.txt` | `a143af264bc8b33f0e1b2f8def16b2479b53d5fc` |
| `metadata/command-boundary.txt` | `runtimeExecution=false`, `exactArithmeticBackend=GMP` |
| preflight / build exit codes | `0` / `0` |
| five `source-status-*` snapshots | all **empty** — clean tree at every stage |
| eight targets in `compiled-targets.txt` | present |
| GMP link line | links both `libgmpxx.so` and `libgmp.so` |

**The decisive link, done by bytes rather than by trust:** the packaged
`src/geometry/SurfaceCellTracing.cpp` hashes to
`16615b23581a7ab2e66199f52a8a2c9c1d4245549ff6f719a4c073dc06137b99`, which equals the
`a143af264` blob **and** the current `HEAD` blob. The packaged
`tests/SurfaceCellsPhase10Tests.cpp` hashes to `7c88a51373ca…`, equal to `HEAD`. The
binary rung 9 executed was therefore built from exactly the bytes now in the repository,
against the unmodified fixture.

### RA-69.5 CHARGE — chat-retained evidence is not provenance

The record states that Google Drive patch staging failed twice with
`container_session_unavailable`, that a GitHub Git-objects API fallback pushed the blob by
expected-parent non-force ref update, and that "a downloadable preservation patch is
retained in this chat."

The transport irregularity itself is **settled harmless by content** at RA-69.4: whatever
route the bytes travelled, the bytes that landed are the bytes that compiled and the bytes
in the repository. That is the correct way to close a non-standard transport.

What is charged is the citation. Under RA-61.5 a claim is provenanced when it is
re-derivable from repository bytes or an immutable artifact. **A chat attachment is
neither.** It is not addressable, not hashable by a later reviewer, and not retrievable
from the repository or the artifact store. Offering it as a preservation store invites a
successor to accept a byte sequence that no longer has a referent. The sentence should
have read that the patch bytes were deliberately not committed and that the landed blob is
the preserved object — which is true, and sufficient.

### RA-69.6 Informational, not charged

The probe performs a linear `std::find_if` over `phaseFrontState.cells` per rejected edge,
so its cost is O(rejections x cells). It is diagnostic-only code inside a rejection
branch and is not authorized for optimisation; recorded so a later turn does not inherit
it into a non-diagnostic path.

### RA-69.7 The READ_MODE disclosure is credited, not charged

The record self-discloses that the first repository reads preceded an explicit
`READ_MODE=snapshot` selection, contrary to `TOOL_USE_CONSERVATION_POLICY.md`. This
Review adjudicates code, design and architecture, not procedure. The disclosure is noted
and **credited as disclosure**; no charge, and it establishes no semantic result either
way.

---

## RA-70 — rung 9, the harvest

### RA-70.1 The instrument is genuine and in the right identity domain

The incidence test is not a string comparison. `face()` admits only a three-element
vertex set; each route step becomes a two-element set; and the test is

```python
hit_to = sum(bool(t and e <= t) for e in edges)
```

a **subset test of the route edge's vertex pair against the ToAttachment face's vertex
triple** — which is exactly what "an edge is incident to this triangle" means. The path
faces are parsed separately by `rows()` as row indices and compared only against row
indices (`rt in pt`). Carrier edges are derived as `c & d` with `len(carrier)==2`
asserted. **Each comparison is made inside one index domain**, which is the RA-67.13
discipline applied correctly in the instrument.

### RA-70.2 Fail-closed, and the RA-67.8 charge is genuinely discharged

`complete` requires `n>0`, `len(actual)==n`, contiguous step indices
`indices==list(range(n))`, every edge of size 2, all eight derived values present, and
`len(carrier)==2`; `if missing: raise SystemExit(...)` terminates the harvest. The
RA-67.8 charge — first-match parsing with no occurrence count — is closed on the route
fields by construction: `probe_lines` collects **every** emission, and
`occurrences_consistent` requires each one to agree with the first and the count to match
the step list. `probe_occurrences` is now a column.

**The charge was consequential.** Two identities emit three times, and the first harness
aggregated them into one route. That produced dispatch `38831159326`, independently
confirmed `conclusion=failure`, which the turn refused to accept and disclosed — when the
successful retry would have concealed it entirely. **RP-03 is satisfied a sixth
consecutive turn.**

### RA-70.3 The residue, bounded and then measured

`get()` remains `re.search` — first match only — for the nine non-route fields, with no
cross-occurrence consistency check. `hit_to` therefore compares a first-match `t` against
a consistency-checked `edges`: mixed provenance.

Bounded, then measured rather than argued:

- `probe_multiplicity=[(1, 42), (3, 2)]` — only indices 27 and 41 emit more than once.
- Both are **controls** (`not-same-interior-carrier-point`, `hit_to=1`), so **no junction
  case is exposed to first-match parsing at all**.
- In both logs, `grep -o 'a2bProbe.*' | sort -u | wc -l` returns **1**: all three
  emissions are byte-identical across the **full** payload, not merely the route fields.

The residue is measured harmless. It remains open as a narrowing to close.

### RA-70.4 Artifact integrity, re-derived

| check | result |
|---|---|
| result artifact `12017109271` | **recomputed** ZIP SHA-256 `e394c4deab99…`, matches provider digest; 81,938 bytes |
| internal manifest | **51 OK / 0 BAD** |
| `manifest-before` vs `manifest-after` | **byte-identical** |
| `raw/` log count | **44** |
| log artifact `12017213842` | digest `7218f11252…`, matches |
| `execution-boundary.txt` | `planned=44 executed=44 red=44 missing=0 postflight=true exit=0`, `compile=false relink=false benchmarks=false selector497=false` |
| `immutability.txt` | `package=true source=true execution_view=true selector=true` |
| harness SHA-256 | `64a6bb67a02e…`, equal at working tree and executor commit `c46615bcc` |
| run `38831615391` | `conclusion=success`, `head_sha=fab558a61` |

### RA-70.5 The partition, re-derived from the TSV

Independently recomputed from `route-path-reconciliation.tsv` — exactly three tuples,
44 rows, all `COMPLETE`, `a2bProbeRouteStepCount=1` and
`a2bProbeFailure=no-exact-terminal-corner` universal:

| n | first failing condition | route step | fromFace | toFace | path1 | path2 | hit_to | hit_from |
|---:|---|---|---:|---:|---|---|---:|---:|
| 23 | `not-same-interior-carrier-point` | `1,4` | 0 | **3** | `0` | `3` | **1** | 1 |
| 15 | `carrier-orientation` | `1,4` | 0 | **7** | `0` | `3` | **0** | 1 |
| 6 | `carrier-orientation` | `1,2` | 0 | **7** | `0` | `3` | **0** | 1 |

`hit_to` separates the populations **perfectly and without exception**: 0 in all 21
junction cases, 1 in all 23 controls.

### RA-70.6 RA-68.9 is CONFIRMED — the falsifier was not observed

The prediction was that the route's step edge set would contain no edge incident to the
`to` endpoint face. Measured: in **21 of 21** junction cases it does not, and in **23 of
23** controls it does. The named falsifier did not occur in any case.

### RA-70.7 CHARGE — the result is under-claimed, and the discarded half is the half that localizes it

The report states that the second path traverses row 3 while the paired junction corner
lies in row 7. True, and incomplete. Two measured facts it does not state:

1. **`FirstPathFaces=0` and `SecondPathFaces=3` are identical in all 44 rows**, controls
   and failures alike.
2. **`hit_from=1` universally** — the `from` endpoint is correctly incident in every case.

Together these are the strongest available form of the finding. Because the traced path,
the route, the step count, the carrier edge and the `from` endpoint are **measurably
identical between the populations that pass incidence and the populations that fail it**,
the tracer, the route publisher, the carrier producer and the `from` corner are all
exonerated by the same measurement. The defect is isolated to **one field, on one side**:
the `to` corner's `face`. A report that gives only the difference and not the agreement
discards the half of its own evidence that performs the localization. This is the same
category as RA-67.9 and is therefore a **repeat**.

### RA-70.8 CHARGE — one edge printed in two index domains, one rung after that lesson was frozen

The report's table presents three populations and two "One-step route topology key"
values, `(1,4)` and `(1,2)`, inviting the reading that two distinct route topologies are
in play. Its own instrument disagrees:

```
first_rejection_membership_to_incidence=[(('carrier-orientation','one',0), 21),
                                         (('not-same-interior-carrier-point','both',1), 23)]
```

**Two** tuples, with the 21 undivided. And the RA-67.5 first-appearance compaction
(`4→2, 2→4, 7→6, 6→7`) maps every measured triple of the 6-case onto the 15-case exactly:

| field | 15-case | 6-case | under compaction |
|---|---|---|---|
| `a2bProbeFromAttachment` | `0,1,4` | `0,1,2` | ✔ |
| `a2bProbeToAttachment` | `4,7,8` | `2,6,8` | ✔ |
| `carrier_edge` | `1,4` | `1,2` | ✔ |
| route step | `1,4` | `1,2` | ✔ |

All four map under one bijection; every other column already agreed, and both populations
are the same suite `SurfaceCellAuthorityContractCutover`. **One phenomenon, two vertex
index domains** — RA-67.5 confirmed a second time, now on fields that did not exist when
it was derived, which is independent corroboration rather than restatement. RA-70.8
charges that **RA-67.13, frozen one rung earlier, was not applied at the one place where
it changes a reader's count.** The report does add a careful row-versus-triple paragraph,
so the discipline was understood and then not carried to the table.

### RA-70.9 The mechanism, re-derived from fixture bytes

From `tests/SurfaceCellsPhase10Tests.cpp:223-273`, for component 0 the emitted faces are
`f0=(0,1,4) f1=(0,4,3) f2=(1,2,5) f3=(1,5,4) f4=(3,4,7) f5=(3,7,6) f6=(4,5,8)
f7=(4,8,7)`, and the two user hard edges are `(1,4)` and `(4,7)`, sharing vertex 4.
Therefore edge `{1,4}` is incident to faces `{0,3}` and edge `{4,7}` to faces `{4,7}`.

- The route's single step is `{1,4}`; the traced boundary paths visit exactly `{0}` and
  `{3}` — **precisely the two faces of the crossed edge**. The tracing is correct and
  complete.
- The corner array declares the `to` endpoint in face 7 `= (4,8,7)`, which is incident to
  the **other** hard edge `{4,7}` and shares only the single vertex 4 with the crossed
  edge.
- So `oriented_carrier` is asked for a carrier spanning `((0,1,4),(4,8,7))`, a face pair
  whose intersection is the lone vertex `{4}` — not an edge. No edge-keyed carrier can
  exist for it (RA-67.6), and the first failing condition is `carrier-orientation` in all
  21, exactly as measured.
- In the controls `ToAttachment=1,4,5 = f3`, the genuine second face of edge `{1,4}`; the
  pair shares an edge, a carrier exists, and rejection falls through to the later
  `not-same-interior-carrier-point`, exactly as measured in all 23.

**The corner walked around the junction; the path did not.** The `to` corner is not merely
a different face — it is the far face of the adjacent hard edge across the shared junction
vertex.

### RA-70.10 Both repair shapes are now the wrong family, not merely unbuildable

RA-68 disqualified shape A (publisher-side cut at an authenticated rail junction) and
shape B (consumer-side source-vertex-aware admission) for want of a producer. Rung 9
supersedes that reasoning with a stronger one: **there is nothing wrong at the publisher
or at the consumer.** The publisher published a correct single-step route for the edge its
path actually crossed; the consumer correctly refused a face pair that shares only a
vertex. The defect is upstream of both, in the assignment of the front edge's second
corner at A4.

A repair at either locus would make the pipeline accept an endpoint that is simply wrong.

### RA-70.11 Gate C is now unnecessary for RP-01, as well as suspended

Gate C was suspended at RA-65.5 for want of a producer and re-grounded at RA-68.3 on
ordering. Rung 9 adds a third and more basic ground: a vertex-star sector certificate at
the consumer would authorize admission of a corner that names a face the traced path never
visited. **No consumer-side authority can repair a wrong corner.** Gate C remains
SUSPENDED and is additionally **moot for `RP-01`**. No vertex-star predicate may be
implemented.

### RA-70.12 `RP-01` advances state without authorizing code

`RP-01 AUTHORITY_DOMAIN_CONFLATION` progresses from *measured, mechanistically derived and
bounded on both repair families* to **producer locus localized**: the defect lies in the
assignment of `SurfacePhaseFrontCell::corners[(side+1)%4].face`. `corners` is
`std::array<SurfaceTracePoint, 4>` (`include/directional/geometry/SurfaceCellTracing.h:1719`),
and `SurfaceTracePoint` carries its own `int face` (`:90-93`) — which is where
`a2bProbeToFace=7` originates, while `boundaryPaths` segments give `{3}`. **Code is still
NOT authorized.**

### RA-70.13 LESSON — the controls' agreement is half the result

A perfectly separating measurement says two things: what differed, and what did not. The
second is what performs the localization, because every column that agrees across the
populations exonerates the producer behind it. **State the null half explicitly; a finding
that reports only the difference has thrown away the evidence that narrows it.**

---

## Rung 10 — scope, and why the deferral was right

RA-68 deferred the producer-definition turn behind rung 9 on the stated ground that the
observation could still change *which* producer is needed. **It did exactly that.** Rung
10 is therefore re-scoped from carrier/vertex-star authority to corner-assignment
authority, and is a **documents-only Definition turn**.

The locus is bounded: `src/geometry/SurfaceCellTracing.cpp` contains exactly three
producers of a cell's corner array —

| anchor | form |
|---|---|
| `:10479` | `proposal.corners = {bottomLeft.point, bottomRight.point, topRight.point, …}` — primary aggregate from four traced points |
| `:11269` | `proposal.corners[corner] = xy.point;` — per-corner override from a two-way closure walk |
| `:19790` | `proposal.corners = cell.corners;` — propagation copy |

### RA-70.14 A prediction for rung 10, with its falsifier and its observation rung named

At `:11258-11271` two independent walks reach the same corner. The code keeps
`xy.point`, discards `yx.point`, and reduces the disagreement to a scalar
`closureError = max(closureError, (xyPosition - yxPosition).norm())` tested against
`options.closureToleranceFactor * min(hx, hy)`.

**Prediction:** a face-index disagreement between the two walks is invisible to that test,
because a position on the shared junction vertex is representable in several faces with
zero positional error — so `closureError ≈ 0` while `xy.point.face` and `yx.point.face`
differ, and the corner silently takes the first walk's face. **Falsifier:** if the
rejected cells do not reach `:11269`, or if a face comparison guards it, the hypothesis is
wrong and `:10479` or `:19790` is the locus. **Observation rung:** rung 10, by static
reading — no new measurement is required, which is why rung 10 is a Definition turn and
not another probe.

This is recorded as a **prediction with provenance stated and its rung named** (RA-61.5,
RA-64.12), not a finding. It does **not** revive RA-64.6, which claimed publisher
truncation; the publisher is exonerated by RA-70.7.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **30+12+449+6 = 497** — all unchanged. No promotion, no stable event, no
regression recurrence, no gate credit, no ledger recomputation, no 497 execution, no
benchmark, no Directional binary executed by this Review. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `a143af264`.** It is the new semantic source. Every earlier
artifact — including compile package `11994726341`, TB4 result `11996317553`, and
snapshots `12005034654`, `12010485442` — is now a **baseline, never a comparand**. The 44
RED are the baseline for `a143af264` alone, **candidate / non-stable**, a diagnostic
vintage and not a new stable recurrence.

`RP-01` **producer locus localized**, code NOT authorized. `RP-02 TEST_AUTHORITY_COVERAGE_GAP`
still **UNREACHED**. `RP-03` satisfied a **sixth** consecutive turn. `PROCESS-01`
discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED
(RA-65.5, RA-68.3) and now additionally moot for `RP-01` (RA-70.11).**

**Successor:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (rung 10).
