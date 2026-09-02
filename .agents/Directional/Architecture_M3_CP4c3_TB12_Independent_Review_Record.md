# M3-CP4c-3-TB12 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB12-REV`
**Date:** 2026-09-02 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB12_Independent_Review_Plan.md`, measures **BI0–BI7**.
**Verdict:** TB12 is a **valid semantic red**, and the root cause is now **proved**: BI2 alternative **2** — two
valid distinct rays collapsed by an under-discriminating collision-equivalence contract, whose specific defect is
that `RayOrderKey::secondary` is not locus-relative at a vertex. One bounded **product** successor is frozen:
**`M3-CP4c-3-CB15`** under **BJ0–BJ9**.

---

## 1. Executive adjudication

CB14 delivered both operands, and they settle the question TB11-REV could not reach.

```
previous: primary=3 secondary=0  arc 20 trace 6 Forward  face (45,46,47) slot 1  originPort 0 @ vertex 47
current : primary=3 secondary=0  arc 23 trace 9 Reverse  face (45,46,47) slot 1  originPort 0 @ vertex 71
```

Four results decide this turn.

1. **The fan is combinatorially correct; only the within-wedge order is missing.**
   `build_vertex_fan_slots` walks the vertex star alternately — edge(slot 0), face(slot 1), edge(slot 2),
   face(slot 3), … — so **edges take even slots and faces odd**, and every face slot lies strictly between its two
   bounding edge slots. With `primary = 2·faceSlot + 1` for trace rays and `2·edgeSlot` for edge rays, the combined
   order interleaves correctly. The rotation at v47 is therefore fully determined **down to which wedge a ray
   occupies**, and undetermined **only** for two rays inside one wedge.

2. **`secondary` is the designated within-wedge rank, filled with the wrong quantity.** At a vertex locus,
   `key.secondary = port->ordinal` (`:1077`) — the ordinal of the port the trace **originated** from. TB12 shows
   the production consequence directly: at locus **47**, the arriving ray's `secondary=0` comes from a port whose
   source vertex is **71**. It is a number from a foreign namespace, not a property of the locus.

3. **The architecture already implements the correct pattern one branch away.** At an **edge** locus,
   `secondary` comes from `edge_locus_secondary_rank` (`:893-934`), which resolves the ray's face, finds the
   **locus** edge's local corner index, and ranks the ray by where it *goes* relative to that locus —
   `2·((otherIndex + 3 − contactIndex) mod 3)` — with the in-source comment "*Keep that exact topological case
   between the two carrier destinations **without using geometry***". Locus-relative, exact, geometry-free. The
   vertex branch is the only one that departs from that convention.

4. **Both rays are independently valid, so this is not an invalid witness.** v47 is an index-`+1` singularity with
   `expectedValence = 3`; the census shows exactly three `Forward` rays with origin vertex 47 and port ordinals
   0, 1, 2, in three distinct wedges — a textbook-correct emanation. The two `Reverse` rays are terminations
   arriving from singularities 71 and 10, which is precisely the behaviour CB12 made correct. Nothing is
   duplicated, stale, or malformed.

The fix is therefore **not** to add `arc`, `trace` or `orientation` to the predicate. Ordering two geometrically
distinct rays by identity would publish a rotation that need not match the actual embedding, and the face walk and
cellularity certificate built on it would then be certifying the wrong combinatorial surface.

---

## 2. BI0 — immutable authority re-established

Recomputed in this turn from committed bytes; control-plane commits after package 82 are excluded by construction.

| Datum | Declared | Verified |
|---|---|---|
| semantic/package source | `71ece3ca184e90858d9222fb014b37c16d292294` | ancestor of branch HEAD |
| selector 378 | `86259d91…396440b8` | LF-blob SHA-256 matches |
| selector 378 cardinality | 378 identities | 378 |
| selector 377 prefix | `7255ac86…6426cbec1` | `head -377` of 378 reproduces it |
| accepted 365 prefix | `6b5b6555…cfc14b8a1` | `head -365` of 378 reproduces it |

**The semantic source equals branch HEAD on every code surface** — `git diff 71ece3ca HEAD -- src include tests
benchmarks CMakeLists.txt cmake` is empty. That is what licenses §3–§5 as static evidence about package 82.

Accepted as reported, with no independent evidence added by this static turn: 378 fresh selector processes,
370 PASS / 8 RED, ordinals 1–365 at 365/365, first red 366, report-only {367, 368, 369, 370, 371, 372, 374},
ordinals 373/375/376/377/**378** PASS, the separate non-gating diagnostic's zero gate credit, the eleven false
boundary flags, and the identical pre/post package-tree census.

**Process-order deviation, recorded not excused.** TB12 fetched one handoff file before declaring
`READ_MODE=snapshot`. The turn then completed the mandatory checklist from the exact snapshot before any semantic
adjudication. It changed no package, selector, runtime, or product evidence, and it does not affect any conclusion
in this record. It stands as a control-plane process note, not a semantic defect.

---

## 3. BI1 — both incidences traced end to end

### 3.1 The complete fan at vertex 47

The census is **5 rays, not truncated** — so this is the whole rotation at that node, not a sample:

| # | (primary, secondary) | arc | trace | orientation | face | slot | origin vertex |
|---|---|---|---|---|---|---|---|
| 1 | (3, 0) | 20 | 6 | Forward | `(45,46,47)` | 1 | **47** |
| 2 | (3, 0) | 23 | 9 | Reverse | `(45,46,47)` | 1 | **71** |
| 3 | (7, 1) | 21 | 7 | Forward | `(46,47,72)` | 3 | 47 |
| 4 | (11, 2) | 16 | 2 | Reverse | `(47,72,73)` | 5 | 10 |
| 5 | (15, 2) | 22 | 8 | Forward | `(45,47,73)` | 7 | 47 |

Three independent consistency checks pass:

- **Slot parity.** Face slots are 1, 3, 5, 7 — all odd, as `build_vertex_fan_slots` requires — and
  `primary = 2·slot + 1` reproduces 3, 7, 11, 15 exactly.
- **Fan closure.** v47 has degree 4. The four faces `(45,46,47)`, `(46,47,72)`, `(47,72,73)`, `(45,47,73)` form a
  closed cycle around v47 through edges 47-45, 47-46, 47-72, 47-73 — a complete, closed star.
- **Emanation count.** Exactly three `Forward` rays carry origin vertex 47, with ordinals 0, 1, 2. For an index-`+1`
  singularity `expectedValence = 4 − 1 = 3`. The port set is complete and each port occupies a **different** wedge.

### 3.2 Ray 1 — arc 20 / trace 6 / Forward

`trace_ray_face` for `Forward` returns `trace.segments[arc.firstSegment].sourceFace`, i.e. the face the trace
**starts** in. Trace 6 originates at v47's port ordinal 0 and its first segment lies in `(45,46,47)`. It is one of
v47's three legitimate emanating rays. **Independently valid at vertex 47.**

### 3.3 Ray 2 — arc 23 / trace 9 / Reverse

For `Reverse`, `trace_ray_face` returns `trace.segments[arc.onePastLastSegment - 1U].sourceFace`, i.e. the face the
trace **ends** in. Trace 9 originates at singularity **71** (port ordinal 0) and terminates at v47 through face
`(45,46,47)`. Its incidence at v47 is a `Reverse` dart on the arc whose `secondNode` is v47's node — exactly the
shape CB12 established for singularity terminations. **Independently valid at vertex 47.**

### 3.4 Why both map to the same wedge, and why that is not an error

Face `(45,46,47)` is one of v47's four wedges. Ray 1 leaves v47 into it; ray 2 arrives at v47 through it. Two
distinct curve arcs of a field-aligned network being incident to the same vertex through the same triangle is an
ordinary configuration — not a duplicate, and not a precondition violation. Nothing in the rotation contract, the
fan construction, or the network contract forbids it, and forbidding it would reject valid networks.

**Validity is established from provenance and construction, not from distinct IDs**, as BI1 requires: ray 1 is
accounted for by v47's own complete port set, and ray 2 by a termination event whose origin singularity is a
different vertex.

---

## 4. BI2 — the rotation collision/equivalence invariant

**May two trace rays legally occupy one wedge? Yes** — §3.4. The rotation system must therefore be able to order
them, and the guard is right to refuse to publish a rotation it cannot order.

**Which key members are semantically order-relevant at a vertex locus?**

- `primary` — **order-relevant.** It encodes the wedge, and the fan walk gives wedges their true cyclic order.
- `secondary` — **order-relevant by design**: the within-wedge rank. This is the slot the contract needs.
- `kind` — a classifier, not an order. Edge rays already separate from trace rays through `primary` parity.
- `arc`, `trace`, `orientation` — **not order-relevant.** They are identities. Two rays in one wedge have a real
  angular order about the vertex, and it is not correlated with their ids. Ordering by them would be deterministic
  and *wrong*: the published rotation could disagree with the embedding, and `walk_graph_faces` plus the
  cellularity certificate would then be adjudicating a different surface than the one being remeshed.

**Adjudication of the four alternatives:**

| # | Alternative | Verdict |
|---|---|---|
| 1 | Invalid duplicate/stale incidence despite distinct IDs | **Falsified.** Different arcs, traces, orientations and origin vertices; both accounted for by construction (§3.2–§3.3); the 5-ray census is complete and internally consistent. |
| 2 | Valid distinct rays collapsed by an under-discriminating collision-equivalence predicate | **PROVED.** The rays differ in a way the key was meant to capture and does not: `secondary` is not locus-relative. |
| 3 | Valid geometrically coincident rays requiring an explicit tie/equivalence rule | **Not this instance.** These two rays are not shown to be collinear from v47 — one departs and one arrives. It remains a **latent** case the correction must keep fail-closed (BJ3). |
| 4 | Invalid witness/precondition that should fail earlier | **Falsified.** §3.1's three consistency checks pass and the configuration is ordinary. |

**The invariant, stated positively:**

> At a vertex locus, `RayOrderKey::secondary` must be an **exact rank of the ray within its wedge, measured about
> the locus vertex**. It must be derived from the ray's own geometry/topology *relative to the locus*, never from
> the ray's origin namespace, and it must be a total order on the rays sharing that wedge. Two rays that are
> exactly coincident from the locus remain a **fail-closed** typed outcome, because ordering them requires
> semantics this review did not establish.

---

## 5. BI3 — origin-port locality resolved

**Complete write/read set for `RayOrderKey::secondary`** (`src/geometry/EmbeddedGraphTopology.cpp`):

- declared `:815`;
- **written at exactly two sites** — `:1077` (vertex locus, `port->ordinal`) and `:1213` (edge locus,
  `edge_locus_secondary_rank`);
- read at `:986` (CB14's census), `:1230` (the collision guard), and the defaulted `operator<=>`.

So the audit BI3 demands is exhaustive: **there is exactly one vertex-locus trace-ray key construction path**, at
`:1077`, and it is the defect. `RayOrderKey` is file-local (anonymous namespace, no header), so no other
translation unit constructs or consumes it.

**Is origin-port ordinal valid as a local secondary rank for an arriving trace? No.** `port->ordinal` ranges over
`0 … expectedValence−1` **per singularity**; nothing ties it to the locus. TB12 exhibits the failure in production:
`originPortOrdinal=0; originPortSourceVertex=71` at locus 47.

**Is it valid for an emanating ray? Only incidentally.** For v47's own three rays it is *consistent* — but the
census shows it is also *doing no work*: each port occupies a different wedge, so `primary` already separates them
and `secondary` is never consulted. The quantity has never been load-bearing where it was correct, and is wrong
everywhere it would be needed.

**Arrival-side authority must be derived from the locus.** `edge_locus_secondary_rank` is the existing precedent
(§1.3): resolve the ray's face, locate the **locus** within that face, and rank by where the ray goes relative to
it. The vertex branch must follow the same convention.

**This provenance does not prove an invalid incidence.** Trace 9's origin port at v71 is correct data about trace
9; it is simply the wrong quantity to ask for when ordering rays at v47.

---

## 6. BI4 — certification and diagnostic honesty

`certificationAttemptIndex` increments only after a completed non-cellular certification
(`SurfaceCutGraph.cpp:344-346`), so **attempt 0 / 0 cut edges** again proves failure on the **first certification of
the uncut embedded graph**, before any cut proposal is evaluated. `cutCandidateCount=450` is measured on that path
(`result.cutCandidates = evidence`).

**BH4 is runtime-validated.** `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are now **absent** from
this failure rather than rendering unmeasured zero defaults — the correct behaviour, since they are assigned only
on the `CutSearchExhaustedBeforeCellularity` returns. The third recurrence of the "default rendered as an
observation" pattern is closed at its locus.

**Selector 378 PASS is diagnostic-projection evidence only.** Identity 378 is
`GlobalTopologyPlan.RotationRayOrderCollisionDiagnosticsSurviveProductionFailureProjection`, and selector 377 is an
exact 377-identity prefix of 378 — so CB14 appended exactly one identity and reordered nothing, honouring BH6. It
proves the two-ray operands, key values and fan census survive the production failure projection. It is **not**
semantic acceptance of anything, and it advances no accepted authority.

---

## 7. BI5 — shared and carried reds, without double counting

- **367 / 371 / 372** abort at the same distinct-ray collision with the same 5-ray census before reaching their own
  assertions. **No duplicate stable event.**
- **`M3-CP4c3-TB10-REV-CAND-01`** (371/372 fixture coupling) remains **ACTIVE / DEFERRED**; TB12 provides no
  independent evidence to change its status, and decoupling now would be opportunistic carried-debt repair.
- **368** sphere `TraceEventPositionInvalid` / `NoCarrierMatch` — `M3-CP4c2-TB-X2-CAND-04`, unchanged.
- **369** `saturationUsed=true` — `M3-CP4c2-TB-X2-R10-CAND-01`, unchanged.
- **370** typed code 4 vs expected `EmptyNetworkOnClosedSurface` code 6 — `M3-CP4c2-TB-X2-R8-CAND-02`, unchanged.
  **No correction authorized.**
- **374** `atlasBuild=false` — `M3-CP4c3-TB7-CAND-02`, unchanged; no atlas invariant may be weakened.
- **Vertex 30**, the `finalize_field_aligned_events` contact fall-through, the mechanical zero-unbound debt and the
  non-flat exact-fallback/budget class all remain **ACTIVE** and untouched.
- **`M3-CP4c3-TB11-REV-CAND-01`** is **CLOSED / RUNTIME DISCRIMINATED** — CB14 retained both operands and TB12
  proved the projection works and the unmeasured counters are absent.

**Accounting.** Ordinals 1–365 remain green; TB12 loses no accepted behaviour and this review executes nothing.
**+0 stable events / +0 stable recurrences.** Totals remain **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 packages **79**.

---

## 8. BI6 — accepted-boundary safety, and the single frozen successor

### 8.1 Why redefining `secondary` cannot disturb anything that passes today

`secondary` is the **second** member of a defaulted `operator<=>`, so it is consulted **only when `primary` ties**.
For two trace rays, `primary` ties **iff they share a wedge**. Therefore:

> In any configuration that certifies successfully today, no two trace rays share a wedge, so `secondary` is never
> consulted for trace rays; and every configuration in which it *would* be consulted is currently a hard error.

**Redefining `secondary` at the vertex locus cannot change the published rotation of any currently-succeeding
case.** It can only decide cases that are rejected today. This is the accepted-boundary proof BI6 requires, and it
holds for accepted ordinals 1–365 without needing to enumerate them.

Compatible with: closed CB12 terminal ownership (upstream, untouched); selector immutability (378 byte-frozen);
`RayOrderKey`'s file-local scope, which bounds every other consumer to this one translation unit.

*Observation, not a finding, for the successor to preserve:* the collision guard requires `kind == Trace` on both
sides, so two Mandatory/Cut rays on one edge slot are not guarded. That is out of scope here and must not be
changed opportunistically.

### 8.2 `M3-CP4c-3-CB15` — BJ0–BJ9

**Type:** Code + Build. **Product correction**, narrowly scoped to the vertex-locus `secondary` rank.
**Owner:** `src/geometry/EmbeddedGraphTopology.cpp::build_rotation_system`, vertex branch, line `:1077`.

- **BJ0** — accepted 365 untouched; **selector 378 byte-frozen** at `86259d91…396440b8`, republished with unchanged
  SHA-256; **eight standard compile targets with mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BJ1** — replace `key.secondary = port->ordinal` with an **exact within-wedge rank about the locus vertex**,
  derived from the ray's own segment relative to the locus, following the `edge_locus_secondary_rank` convention.
  For a wedge `F` at corner `v`, the angular order of two rays from `v` equals the order of their crossings of the
  edge of `F` opposite `v`; equivalently, the sign of the existing exact barycentric orientation determinant on the
  two rays' second points. **Exact rationals only — no tolerance, no floating point, no trigonometry.**
- **BJ2** — handle both orientations from the locus: `Forward` uses `segments[arc.firstSegment]`, `Reverse` uses
  `segments[arc.onePastLastSegment - 1U]`, matching `trace_ray_face`. A ray that terminates inside the wedge must
  rank from its terminal barycentric point, not be excluded.
- **BJ3** — keep the collision guard **fail-closed** for rays that are **exactly coincident** from the locus, under
  a distinct typed condition. That case is BI2 alternative 3 and needs semantics this review did not establish;
  it must not be silently ordered.
- **BJ4** — **do not** add `arc`, `trace` or `orientation` to the collision predicate or the comparator; ordering
  by identity is proved semantically wrong (§4). Leave `primary`, the fan-slot construction,
  `build_vertex_fan_slots`, `trace_ray_face`, the edge-locus branch, and the incidence map unchanged.
- **BJ5** — witnesses. **Positive:** a synthetic vertex fan with two trace rays in one wedge at distinct angles,
  asserting a deterministic rotation whose order matches the geometric order, published through the production
  path. **Negative:** two exactly coincident rays still fail closed under BJ3's typed condition. **Regression:** a
  fan with at most one trace ray per wedge publishes the byte-identical rotation before and after.
- **BJ6** — append **selector 379** only on demonstrated falsification; no reordering of any existing ordinal.
- **BJ7** — prohibitions: no change to any other ordering, cut, or topology decision; do not revert or weaken CB12
  or CB14; do not repair the `finalize_field_aligned_events` fall-through; do not decouple 371/372; do not touch
  the unguarded Mandatory/Cut same-slot case; no sphere, saturation, ordinal-370 or folded-cone correction; no
  fixture mutation.
- **BJ8** — audit by assumption; prove via §8.1 that no accepted-green rotation changes, and demonstrate the
  before/after byte-identical rotation on at least one currently-passing witness.
- **BJ9** — publish five `M3-CP4c-3-TB13` discriminators in advance:
  1. ordinals **1–365 remain 365/365**;
  2. ordinal 366 **no longer reports** `RotationRayOrderKeyCollision` at vertex 47 — a repeat there falsifies BJ1;
  3. rays 1 and 2 receive **distinct** `secondary` values and the rotation at v47 publishes all five rays;
  4. if ordinal 366 still reds, it does so at a **different** stage, reason or locus — the certification then
     proceeds past rotation construction into the face walk, and `nonDiscComponentCount` /
     `remainingAdmissibleEdgeCount` may legitimately appear for the first time;
  5. `M3-CP4c3-TB11-CAND-01` closes only on 1, 2 and 3 together.

**No vertex-30 discriminator is published.** Nothing in this review proves the corrected rotation lets the
mechanical path reach vertex 30; `M3-CP4c3-TB6-CAND-01` stays ACTIVE and row 41 remains prohibited rather than
measured.

---

## 9. Assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review describes package 82. | `git diff 71ece3ca HEAD` over the code surfaces is empty. |
| §3.1 | The census is the complete rotation at v47. | TB12 reports 5 rays, **not truncated**; slot parity, fan closure and the 3-port emanation count all reconcile independently. |
| §3.4 | Two rays may share a wedge. | v47 legitimately emits into three of four wedges and legitimately receives terminations; no contract forbids the overlap, and forbidding it would reject valid networks. |
| §4 | Identity is not order-relevant. | Ray order about a vertex is a property of the embedding; arc/trace ids do not track it, so ordering by them can publish a rotation that disagrees with the surface being certified. |
| §5 | Exactly one vertex-locus write of `secondary`. | Full grep of the symbol: declared `:815`, written `:1077` and `:1213`, read `:986`/`:1230`; type is file-local with no header. |
| §5 | The origin ordinal was never load-bearing where correct. | The census shows v47's three ports occupy three **different** wedges, so `primary` already separates them. |
| **§8.1** | **Redefining `secondary` is accepted-safe.** | It is compared only on a `primary` tie; a `primary` tie between trace rays means a shared wedge; every shared-wedge case is a hard error today. So no passing rotation can change. |
| BJ3 | Coincident rays are a separate question. | The two observed rays are one departure and one arrival, not shown collinear; keeping that case fail-closed defers semantics this review did not establish. |
| BJ9 | Ordinal 366 will move. | BJ1 changes exactly the quantity that produced the tie. If it reds identically, the correction did not land. |

---

## 10. Lessons

- **86 (new).** *When one branch of a shared contract is right, read it before designing the other.* The vertex
  locus and the edge locus fill the same `RayOrderKey::secondary` slot; the edge branch computes a locus-relative,
  exact, geometry-free rank and even documents that intent in a comment, while the vertex branch substitutes the
  ray's origin-port ordinal. The correct design was already implemented forty lines away. Before inventing a rank,
  diff the sibling implementations of the same field.
- **87 (new).** *A quantity that is only incidentally correct will be wrong the first time it matters.*
  `port->ordinal` was consistent for a singularity's own emanating rays — and the census shows `primary` already
  separated those, so it never did any work there. It was load-bearing only for rays arriving from elsewhere,
  which is exactly where it was meaningless. Ask which inputs actually reach a tiebreak before trusting it.
- **85 confirmed (TB11-REV).** The predicted mechanism — "an identifier is only a discriminator inside the scope
  that makes it unique" — is now runtime-proved in the production witness: `originPortOrdinal=0` with
  `originPortSourceVertex=71` at locus 47. TB11-REV's diagnostic-only successor was the correct call: the same
  observation would have supported three different fixes without the retained operands.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB15`** under **BJ0–BJ9**.
