# M3-CP4c-3-TB11 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB11-REV`
**Date:** 2026-09-02 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB11_Independent_Review_Plan.md`, measures **BG0–BG7**.
**Verdict:** TB11 is a **valid semantic red**. The ordinal-366 collision is **not adjudicable from the retained
evidence**, and the reason is proved: the emitter retains neither colliding ray. Under BG6's explicit conditional,
exactly one **diagnostic-only** successor is frozen: **`M3-CP4c-3-CB14`** under **BH0–BH9**.

---

## 1. Executive adjudication

CB13 delivered its discriminator: ordinal 366 now names the producer condition and phase.

```
NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent;
detailCode=CellularityNotEstablished;sourceVertex=47;
rotationSystemReason=RotationRayOrderKeyCollision;
cutCandidateCount=450;nonDiscComponentCount=0;remainingAdmissibleEdgeCount=0;
certificationAttempt=0;certificationCutEdges=0
```

Four results decide this turn.

1. **The guard is a fail-closed injectivity assertion, and it compares less than the key it is checking.**
   `RayOrderKey` has six members — `primary`, `secondary`, `kind`, `trace`, `arc`, `orientation` — and the *sort*
   uses all of them. The **collision predicate compares only `primary` and `secondary`** (plus `kind == Trace` on
   both sides and a vertex locus). So the guard asserts that `(primary, secondary)` alone is injective over trace
   rays at a vertex, while three further discriminators sit unused in the same struct.

2. **At a vertex locus, `secondary` is drawn from a namespace that is not vertex-local.** For a trace ray,
   `primary = 2·faceSlot + 1` and `secondary = port->ordinal`, where `port` is the singularity port the trace
   **originated from** — found by `candidate.id == trace->port`, with **no check that the port's source vertex is
   the locus vertex**. It discriminates reliably only among rays emanating from that same singularity; every other
   ray incident to the vertex borrows an ordinal from a foreign port namespace.

3. **A structurally guaranteed collision exists that requires no defect anywhere else.** `incidences` is built as
   `incidences[arc.firstNode].push_back(Forward)` and `incidences[arc.secondNode].push_back(Reverse)`. A
   **self-loop arc** (`firstNode == secondNode`) therefore contributes **two darts at the same node**, with the
   same `trace` and hence the **same `secondary`**. If `trace_ray_face` resolves both darts into the same fan
   sector, `primary` matches too and the collision fires — on a legitimate network, distinguished only by `arc`
   and `orientation`, the two members the predicate ignores.

4. **The two colliding rays are not retained, and that is provable rather than assumed.**
   `GlobalTopologyPlanError` carries `arc`, `trace`, **`secondTrace`**, `sourceFace` and **`secondSourceFace`** —
   a DTO visibly shaped for a two-sided comparison. The collision emitter sets only
   `rotationSystemInconsistencyReason`, `sourceVertex` and `sourceEdge`. Neither side is named, no face is named,
   and **no field exists anywhere for the colliding `primary`/`secondary` values**.

At least four of BG2's five alternatives remain live and produce the *identical* rendered line. BG6's conditional
therefore governs: freeze diagnostic-only instrumentation, not a semantic correction.

---

## 2. BG0 — immutable authority re-established

Recomputed in this turn from committed bytes; no rebuilt binary or branch-head build product was used as semantic
evidence, and control-plane commits after package 81 are excluded by construction.

| Datum | Declared | Verified |
|---|---|---|
| semantic/package source | `3070173894ee097f631b96c1c6d29f276df89a66` | exists, `ci: retire CB13 Drive-apply validation payload`, 2026-09-01 21:17:40 −0700, ancestor of branch HEAD |
| selector 377 | `7255ac86…6426cbec1` | LF-blob SHA-256 = `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1` |
| selector 377 cardinality | 377 identities | 377 |
| accepted 365 prefix | `6b5b6555…cfc14b8a1` | `head -365` of selector 377 = `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |

One further BG0 result the TB11 report does not itself assert: **the semantic source equals branch HEAD on every
code surface.** `git diff 3070173 HEAD -- src include tests benchmarks CMakeLists.txt cmake` is **empty**. That is
what licenses §3–§5 below as static evidence about the contents of immutable package 81; it is checked, not
assumed.

Accepted as reported, with no independent evidence added by this static turn: the 377 fresh-process count,
369 PASS / 8 RED, first red at ordinal 366, the report-only set {367, 368, 369, 370, 371, 372, 374}, ordinal 377
PASS, the non-gating diagnostic's zero gate credit, the eleven false boundary flags, and the identical pre/post
package-tree census.

---

## 3. BG1 — reconstruction of the collision

### 3.1 The unique emitter and its exact contract

`RotationRayOrderKeyCollision` has exactly one emission site: `src/geometry/EmbeddedGraphTopology.cpp:1214`, inside
`build_rotation_system`. The name is mapped to a string in `GlobalTopologyPlan.cpp:2224-2225` and appears nowhere
else in the product.

The guard runs **after** key construction and **after** the sort, and **before** `counterClockwise` is published:

```cpp
std::sort(keyed.begin(), keyed.end(),
          [](const auto &lhs, const auto &rhs) { return lhs.first < rhs.first; });
for (std::size_t index = 1U; index < keyed.size(); ++index) {
  const RayOrderKey &previous = keyed[index - 1U].first;
  const RayOrderKey &current  = keyed[index].first;
  if (locusIt->second.vertex.has_value() &&
      previous.kind == GlobalTopologyArcKind::Trace &&
      current.kind  == GlobalTopologyArcKind::Trace &&
      previous.primary   == current.primary &&
      previous.secondary == current.secondary) {
    GlobalTopologyPlanError result = rotation_error(RotationRayOrderKeyCollision);
    result.sourceVertex = locusIt->second.vertex;
    result.sourceEdge   = locusIt->second.edge;
    return result;
  }
}
GlobalTopologyNodeRotation rotation{node, {}};   // publication follows
```

This confirms the plan's stated contract exactly: post-sort, adjacent-pair, both sides `Trace`, vertex locus, equal
`primary` **and** `secondary`. The absence of a `sourceEdge` token in the TB11 line is consistent — at a vertex
locus the locus edge is `std::nullopt`.

### 3.2 How the two key components are formed at a vertex locus

In the vertex branch (`:980–1065`), for `arc.kind == Trace`:

```cpp
key.primary   = 2U * slots->faceSlots.at(*face) + 1U;   // odd: trace rays interleave between edge rays
key.secondary = static_cast<std::size_t>(port->ordinal);
```

where `face = trace_ray_face(arc, incidence.orientation, *trace)` and `port` is located by
`candidate.id == trace->port`. Mandatory/Cut arcs instead take `key.primary = 2U * slot->second` (even) and leave
`secondary` at its default `0`, which is why the predicate additionally requires `kind == Trace` on both sides.

Two properties follow directly, and both matter:

- **`primary` identifies a fan *sector*, not a ray.** Any number of trace rays may share one face sector; `primary`
  cannot separate them.
- **`secondary` is the origin port's ordinal, and its vertex is never checked.** `port->ordinal` ranges over
  `0 … expectedValence−1` **per singularity**. For a ray emanating from the locus singularity it is a genuine
  within-vertex discriminator. For a ray that arrives at, terminates at, or passes through the vertex, it is the
  ordinal of a port at a *different* vertex — a deterministic but non-injective number in this context.

### 3.3 A collision mechanism that needs no defect elsewhere

`build_rotation_system` builds the incidence map as:

```cpp
for (const auto &arc : arcs) {
  incidences[arc.firstNode ].push_back({arc.id, Orientation::Forward});
  incidences[arc.secondNode].push_back({arc.id, Orientation::Reverse});
}
```

For a **self-loop arc** — `firstNode == secondNode` — this pushes **two darts onto the same node**. Both darts
carry the same `arc` and the same `arc.trace`, so both resolve the same origin port and therefore the **same
`secondary`, necessarily**. `trace_ray_face` distinguishes them only through orientation: Forward reads
`segments[arc.firstSegment]`, Reverse reads `segments[arc.onePastLastSegment - 1U]`. If a trace departs and returns
through the **same** face of the vertex fan, both darts land in the same sector, `primary` matches as well, and the
collision fires.

Such a pair is distinguished in the key by `arc` and `orientation` — precisely the two members the predicate
excludes. This does **not** prove the observed collision was a self-loop; it proves that the predicate's
injectivity assumption can fail on a network with no upstream defect at all, which is why the observation alone
cannot be read as evidence that anything upstream is wrong.

### 3.4 The missing datum, proved rather than inferred

`GlobalTopologyPlanError` (`include/directional/geometry/GlobalTopologyPlan.h`) declares `arc`, `networkEdge`,
`trace`, **`secondTrace`**, `sourceEdge`, `sourceFace`, **`secondSourceFace`**, `singularity`, `sourceVertex`, and
the rotation reason. The presence of `secondTrace` and `secondSourceFace` shows the DTO was designed to carry both
sides of exactly this kind of pairwise comparison.

The collision emitter populates **only** `rotationSystemInconsistencyReason`, `sourceVertex` and `sourceEdge`.
Therefore, from the retained TB11 evidence:

- neither colliding arc id is recoverable (`previous.arc`, `current.arc` — dropped);
- neither colliding trace id is recoverable (`previous.trace`, `current.trace` — dropped, with `secondTrace`
  sitting unused);
- neither ray's face is recoverable (`sourceFace` / `secondSourceFace` — both unused);
- the colliding `primary` and `secondary` values are **unrecoverable in principle**: no field of the DTO can hold
  them, and no renderer prints them.

The non-gating diagnostic adds nothing here — TB11 §3 records that it re-derived the same stage and the same
reason, not the operands.

**The identities and key values required by BG1 are not retained. That is the proved missing datum.**

---

## 4. BG2 — classification against the alternatives

The five alternatives are adjudicated separately, as required.

| # | Alternative | Status on retained evidence |
|---|---|---|
| 1 | Two genuinely duplicate outgoing incidences entered the rotation system | **Live.** Duplicate darts are structurally reachable (§3.3, self-loop) and duplicated arcs cannot be excluded without the arc ids. |
| 2 | Two distinct valid rays collapse because the key omits a discriminator | **Live, and independently supported.** `secondary` is not vertex-local (§3.2); `arc` and `orientation` exist in the key and are excluded from the predicate (§3.1). |
| 3 | The rays are genuinely coincident and the architecture owes an explicit tie/equivalence rule | **Live.** Two rays in one fan sector have no defined cyclic order; ordering them by id would be deterministic but not geometrically justified. |
| 4 | Stale or duplicated source/network provenance created an invalid incidence | **Live.** Nothing in the retained line constrains arc or trace provenance. |
| 5 | The mechanical witness violates a precondition that should have been rejected earlier | **Weakest, but not excluded.** The witness is a closed manifold that has cleared every prior stage and accepted ordinals 1–365 still pass; v47 is an ordinary index-`+1` singularity. No precondition of the rotation contract is violated by the *mesh*. It remains formally live because an upstream network defect would surface here identically. |

**Alternatives 1–4 produce a byte-identical rendered line.** The observation `sourceVertex=47` plus the reason name
is compatible with every one of them, and §3.4 proves the separating operands were discarded at the emitter.

**Classification: the semantic root cause is underdetermined, and the cause of the underdetermination is a
diagnostic omission — not a missing analysis.** This is BG6's stated conditional. Choosing between "add a
discriminator", "define a tie rule", and "reject upstream" now would be an ordering guess: they touch different
authorities, and two of them would silently change fan ordering for cases that are currently correct.

One further caution for the successor. The rotation system at a **singularity** node became reachable on the
mechanical witness only after CB12's terminal-ownership correction and CB13's diagnostics let the pipeline advance
this far. So this is a **newly reachable** path, not demonstrably a newly introduced defect. CB12's correction is
closed and **must not be reverted or treated as suspect** on this evidence; whether the additional terminal
incidences it publishes at singularity nodes participate in the collision is precisely one of the things the
instrumentation must answer.

---

## 5. BG3 — certification context, established from control flow only

`SurfaceCutGraph.cpp:344-346`:

```cpp
std::size_t certificationAttemptIndex = 0U;
while (true) {
  const auto evidence = classify_cut_candidates(*topology, mandatory, traceCrossed, cuts);
  const auto certificateBuild = certify_actual_embedded_graph(..., {cuts.begin(), cuts.end()}, evidence);
  if (const auto *failure = std::get_if<SurfaceCutGraphError>(&certificateBuild)) {
    auto result = *failure;
    result.cutCandidates            = evidence;
    result.certificationAttemptIndex = certificationAttemptIndex;
    result.certificationCutEdgeCount = cuts.size();
    return result;
  }
  ...
  ++certificationAttemptIndex;
```

Therefore `certificationAttempt=0` with `certificationCutEdges=0` proves: the failure occurs on the **first
certification of the uncut embedded graph**, at the top of the loop, **before any cut proposal is evaluated and
before any cut edge exists**. `certify_actual_embedded_graph` calls `build_rotation_system`, which aborts as
described in §3. No cut-search or cellularity semantics may be inferred.

**`cutCandidateCount=450` is a real measurement** — `result.cutCandidates = evidence` is assigned on this path. It
is an inventory of candidates classified on the *uncut* graph, not a search outcome.

**`nonDiscComponentCount=0` and `remainingAdmissibleEdgeCount=0` are NOT measurements on this path.** Both fields
are assigned **only** on the `CutSearchExhaustedBeforeCellularity` returns (`SurfaceCutGraph.cpp:365` and `:367`).
The certification-failure return at `:345` assigns neither, so both retain their struct defaults of `0U`, and
`RemeshPipeline.cpp:6877-6878` projects them unconditionally. Reading them as "no non-disc components" or "no
admissible edges remain" would be a **misreading of a default as an observation** — the third instance of the
pattern first recorded as `LESSONS.md` §4 80 (`publishedFaces`).

---

## 6. BG4 — shared and carried reds, without double counting

- **367 / 371 / 372** abort at the same ordinal-366 mechanical exception before reaching their own assertions, as
  reported. They yield no independent conclusion and create **no separate event**.
- **`M3-CP4c3-TB10-REV-CAND-01`** (ordinals 371/372 blocked by a shared fixture precondition rather than their own
  contracts) remains **ACTIVE / TEST-COUPLING / DEFERRED**. Nothing in TB11 proves a need to decouple them now, and
  doing so would be opportunistic carried-debt repair, which the prohibitions forbid.
- **368** — prescribed sphere, `TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch /
  SourceEdgeUnavailable`: `M3-CP4c2-TB-X2-CAND-04`, unchanged.
- **369** — `saturationUsed=true`: `M3-CP4c2-TB-X2-R10-CAND-01`, unchanged.
- **370** — `CellularityNotEstablished` where `EmptyNetworkOnClosedSurface` is required, source-face locus absent:
  `M3-CP4c2-TB-X2-R8-CAND-02`, unchanged. **No correction authorized**, and note that ordinal 370's *expected*
  code differs from ordinal 366's *actual* code purely by coincidence of naming — they are unrelated conditions.
- **374** — `atlasBuild=false`, pre-classified invalid folded-cone witness: `M3-CP4c3-TB7-CAND-02`, unchanged; no
  atlas invariant may be weakened for it.
- **Vertex 30**, the `finalize_field_aligned_events` contact fall-through, the mechanical zero-unbound debt and the
  general non-flat exact-fallback/budget class all remain **ACTIVE** and untouched.
- **`M3-CP4c3-TB10-CAND-01`** is **CLOSED / RUNTIME DISCRIMINATED**, as TB11 records: CB13's discriminator named
  the producer condition and phase.

---

## 7. BG5 — accepted-boundary safety audit

- **Selector immutability holds.** Selector 377 recomputes byte-identical and its first 365 identities reproduce
  the accepted hash (§2).
- **`RayOrderKey` has no consumers outside its translation unit.** It is declared inside an anonymous namespace
  within `namespace directional::geometry::embedded_graph_topology_detail` in
  `src/geometry/EmbeddedGraphTopology.cpp`, and every use (`:978`, `:995`, `:1117`, `:1206-1207`) is in the same
  file. It appears in no header. A change to the key or its predicate therefore cannot alter fan ordering,
  topology, cut admissibility, or gauge behaviour anywhere else **by linkage** — though it can, of course, change
  the rotation this file publishes, which is why BH forbids touching it.
- **The CB12 terminal-ownership correction stays closed.** It is upstream of this stage, its own condition and seed
  pair did not recur in TB11, and no evidence here bears on its correctness (§4).
- **Accepted ordinals 1–365 are unaffected by the frozen successor**, which adds fields and rendering only and
  changes no decision (BH7).

---

## 8. BG6 — the single frozen successor: `M3-CP4c-3-CB14`

**Type:** Code + Build. **Diagnostic-only**, under BG6's explicit conditional, because §3.4 proves the colliding
identities and key values are not retained. **Owner:** the collision emitter in
`src/geometry/EmbeddedGraphTopology.cpp::build_rotation_system` and the two DTO/projection surfaces it reports
through.

### BH0 — preconditions
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Accepted 365 untouched. **Selector 377 stays
byte-frozen** at `7255ac86…6426cbec1` and must republish with unchanged SHA-256. **Eight standard compile targets
with mandatory GMP/GMPXX linkage** (`GMP_COMPILE_POLICY.md`). No runtime in CB14; no acceptance claimed.

### BH1 — name both colliding rays
Populate, at the collision emitter, the fields the DTO already has: `arc` and `trace` and `sourceFace` for
`previous`, and `secondTrace` and `secondSourceFace` for `current`. Add a second arc field if the DTO lacks one.
Render every one of them.

### BH2 — publish the operands the DTO cannot currently hold
Add typed fields for the colliding `primary` and `secondary` values, both `orientation`s, both origin port
ordinals **and both origin port source vertices** (the last is what proves whether `secondary` was vertex-local),
and the resolved fan slot for each ray. Render them.

### BH3 — publish the sector occupancy at the failing vertex
Emit a **bounded** census of the keyed fan at that locus — per ray: kind, `primary`, `secondary`, arc, trace,
orientation — with an explicit truncation marker. This is what distinguishes BG2's alternatives 1–4 in one
observation: duplicate darts, a self-loop pair, and two independent traces sharing a sector are immediately
separable once the fan is visible.

### BH4 — make the certification counters honest
`nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are struct defaults on the certification-failure path
(§5). Either assign them there or stop rendering them for that path. **Do not leave a default rendering as an
observation** — this is the third recurrence of that pattern. State which was chosen and why.

### BH5 — witnesses
Add a synthetic witness that reproduces a same-sector vertex collision — the self-loop shape of §3.3 is the
cheapest — and assert that both sides, both key operands, and the fan census render through the **production**
locus path, not a test-local renderer. Add a mechanical assertion that ordinal 366's line now carries both ray
identities. Preserve every existing assertion verbatim.

### BH6 — selector treatment
Append **selector 378** = 377 plus the new diagnostic identities, **only** on demonstrated falsification — each new
identity must fail before the change and pass after. Republish 377 with unchanged SHA-256. No reordering of any
existing ordinal.

### BH7 — prohibitions
**Do not change the collision predicate, the sort comparator, `RayOrderKey`'s members, `primary`/`secondary`
construction, `trace_ray_face`, the incidence map, or any ordering or rotation semantics.** Do not add `arc` or
`orientation` to the collision test — that is a semantic decision this review deliberately did not make. Do not
revert or weaken CB12. Do not repair the `finalize_field_aligned_events` contact fall-through. Do not decouple
ordinals 371/372. No sphere, saturation, ordinal-370 or folded-cone correction. No fixture mutation, no tolerance,
no float-derived topological decision, no acceptance claim.

### BH8 — audit by assumption
For each of BH1–BH6 state the assumption and the evidence falsifying the nearest alternative. At minimum prove that
no accepted-green identity's observable output changes, and that no rotation, ordering, or cut decision differs
before and after.

### BH9 — discriminators expected from the next artifact-only TB
`M3-CP4c-3-TB12` runs **selector 378 from ordinal 1**, artifact-only, on a fresh immutable package. Publish these
five in advance:

1. ordinals **1–365 remain 365/365** — CB14 changes no decision;
2. ordinal 366 still reds at `RotationRayOrderKeyCollision`, still at `sourceVertex=47`, still at
   `certificationAttempt=0` / `certificationCutEdges=0` — **any movement falsifies BH7**;
3. the same line now names **both** colliding arcs and traces, both faces, both orientations, and both origin port
   ordinals **with their source vertices**;
4. the bounded fan census at v47 is present and shows how many trace rays occupy the colliding sector;
5. `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` are either populated on this path or absent from it.

**No semantic correction is authorized until TB12 separates BG2's alternatives.** The successor after TB12 is an
independent `M3-CP4c-3-TB12-REV`, which will own the category decision and the product correction.

---

## 9. BG7 assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review of the working tree describes package 81. | `git diff 3070173 HEAD` over the code surfaces is empty; drift is excluded. Control-plane commits after package 81 touch no code surface. |
| §3.1 | The guard compares less than the key. | `RayOrderKey` declares six members and defaults `operator<=>`; the predicate names only `primary`, `secondary` and `kind`. |
| §3.2 | `secondary` is not vertex-local. | `port` is matched by `candidate.id == trace->port` with no comparison of the port's source vertex to the locus vertex. |
| §3.3 | A self-loop yields two darts with equal `secondary`. | The incidence map pushes Forward at `firstNode` and Reverse at `secondNode` unconditionally; both darts share `arc.trace`, hence the same origin port. |
| §3.4 | The colliding identities are unrecoverable. | The emitter assigns three fields; `secondTrace` and `secondSourceFace` exist and are unused; **no** field of the DTO can hold `primary`/`secondary`. |
| §4 | The classification is underdetermined rather than merely unanalyzed. | Four alternatives produce a byte-identical rendered line, and §3.4 proves the separating operands were discarded before rendering. |
| §5 | `certificationAttempt=0` means pre-cut. | The counter increments only after a successful non-cellular certification; the failure return precedes the increment and reports `cuts.size()`. |
| §5 | The two zero counters are defaults. | They are assigned only at `SurfaceCutGraph.cpp:365` and `:367`, on a different error code; the `:345` return assigns neither. |
| §7 | A key repair cannot leak outside the file. | `RayOrderKey` is in an anonymous namespace in one `.cpp` and appears in no header. |
| BH9 | Ordinal 366 will not move. | CB14 changes no decision. If the locus, attempt, or reason moves, BH7 was violated and the turn is invalid. |

---

## 10. Lessons

- **84 (new).** *A fail-closed uniqueness assertion must compare the whole key it is asserting on, or say why not.*
  `RayOrderKey` sorts on six members and is checked for collisions on two. That is defensible only if the other
  four are known-irrelevant to the invariant — and if so, the guard should say so and the key should not carry
  them. As written, the predicate cannot distinguish "the key is under-determined" from "the input is duplicated",
  which is exactly the ambiguity that blocked this review.
- **85 (new).** *An identifier is only a discriminator inside its own namespace.* `port->ordinal` is injective over
  the ports of **one** singularity. Used as a within-sector tiebreak at an arbitrary vertex, it silently ranges
  over ordinals minted at other vertices. When borrowing an id as an ordering key, check that the scope which
  guarantees its uniqueness is the scope you are ordering within.
- **80r (third recurrence).** A field that is declared, defaulted, and rendered unconditionally reads as an
  observation. `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are assigned on one error path and
  printed on all of them — after `publishedFaces` (TB8-REV) and the trace-scoped group (TB9-REV). The durable fix
  is not another one-off: a locus field should be printed only where the path that produced it assigns it.
- **Confirmed (lesson 82).** TB11 again shows that naming a *condition* is not the same as retaining its
  *operands*. CB13 correctly discharged its diagnostic obligation — the reason and phase are now visible — and the
  review still cannot adjudicate, because the guard's two operands were never carried.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB14`** under **BH0–BH9**.
