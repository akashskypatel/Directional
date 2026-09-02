# M3-CP4c-3-TB13 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB13-REV`
**Date:** 2026-09-02 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB13_Independent_Review_Plan.md`, measures **BK0–BK8**.
**Verdict:** TB13 is a **valid semantic red**, and the condition TB13 called underdetermined is **determined here
from static authority**: the firing emitter is CB15's new `vertex_locus_secondary_parameter` branch, and the defect
is that `vertex_trace_ray_second_point` has **no case for a segment that exits through a vertex**. One bounded
**product + minimal typed-split** successor is frozen: **`M3-CP4c-3-CB16`** under **BL0–BL9**.

---

## 1. Executive adjudication

CB15's within-wedge ranking works — selector 379's focused witness passes and the v47 collision is gone from
ordinal 366 — but the first red moved earlier, to source vertex **10**, face **`(8,10,11)`**, reason
`VertexTracePortOrdinalInvalid`.

TB13 correctly refused to read that reason as an origin-port defect, because package 83 assigns it to **two**
conditions. This review resolves which one fired, and why, without new runtime.

1. **Exactly two emitters, and they are indistinguishable.** `VertexTracePortOrdinalInvalid` is emitted at
   `EmbeddedGraphTopology.cpp:1204` (legacy: port lookup failed or `ordinal < 0`) and `:1217` (CB15's new:
   `vertex_locus_secondary_parameter(...) == nullopt`). Both populate the **same three fields** — reason,
   `sourceVertex`, `sourceFace` — so the rendered locus cannot separate them.

2. **The legacy emitter is excluded by TB12's own evidence.** CB15 touched four files, none of them
   `SurfaceCellTracing.cpp`, so the network — arcs, traces, ports, node assignment — is **byte-identical** to
   TB12's. Node ids are assigned by iterating `nodeVertices`, a `std::set<SourceVertexId>`, so node id is monotone
   in vertex index; `incidences` is a `std::map` keyed by node id. Therefore **v10 is processed before v47**, and
   TB12 *reached* v47 — so v10 passed the legacy port branch on identical inputs. It cannot be firing now.

3. **Only a `Forward` ray can fail the new branch.** For `Reverse`, the helper returns
   `field_boundary_point_barycentric(face, segment.entryPoint)`, and that entry point lies by construction on an
   edge of that same segment's face. Reverse always resolves. The failing incidence is therefore an **emanating
   ray at v10 in face `(8,10,11)`**.

4. **The defect is a missing vertex-exit case, and the ray it rejects is exactly representable.**
   `segment.edgeTransitExit` is assigned **only** on the edge-transit path (`SurfaceCellTracing.cpp:2399`,
   `:3061`) — never for a `VertexHit`. `M3-CP4c-3-TB7-REV` proved that v10's port trace runs along mesh edge
   `(10,11)` and lands on **vertex 11** by Amendment 3. Its exit is a *corner* of face `(8,10,11)`, so the Forward
   fallback chain finds nothing — while the point itself is barycentric `(0,0,1)`, giving denominator `1` and an
   exact within-wedge parameter of **0**.

CB15's contract is therefore incomplete rather than wrong: a valid ray legitimately lacks the *represented* second
point, though not the *actual* one.

---

## 2. BK0 — immutable authority re-established

Verified this turn with `.agents/Directional/tools/review_check.py` and `selector_probe.py`:

| Datum | Declared | Verified |
|---|---|---|
| semantic/package source | `a2fd98eaa015ff5872890bb1945cf4e9e9493615` | exists, `M3-CP4c-3-CB15: fix GlobalTopologyArc test construction`, ancestor of HEAD |
| code drift source→HEAD | — | **empty** over `src include tests benchmarks CMakeLists.txt cmake` |
| selector 379 | `ef51298f…842594b7` | LF-blob SHA-256 = `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7` |
| selector 379 cardinality | 379 identities | 379 |
| selector 378 prefix | `86259d91…396440b8` | `head -378` reproduces it |
| accepted 365 prefix | `6b5b6555…cfc14b8a1` | `head -365` reproduces it |

So CB15 appended **exactly one** identity —
`GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry` — and reordered nothing, honouring BJ6.
The empty code drift is what licenses §3–§5 as static evidence about immutable package 83.

Accepted as reported: 379 fresh selector processes, 371 PASS / 8 RED, ordinals 1–365 at 365/365, first red 366,
report-only {367, 368, 369, 370, 371, 372, 374}, selector-379 witness PASS, the separate non-gating diagnostic's
zero gate credit, and the identical pre/post package census. **TB13's start-of-turn `READ_MODE` process-order
deviation is recorded as procedural only** — it changed no package, selector, runtime or product evidence.

---

## 3. BK1 — every emitter behind the retained reason

`VertexTracePortOrdinalInvalid` appears at exactly four places in package 83: the enum declaration
(`GlobalTopologyPlan.h:161`), the name mapping (`GlobalTopologyPlan.cpp:2160-2161`), and **two emission sites**,
both inside the vertex-locus branch of `build_rotation_system`:

**Emitter A — legacy port ownership (`:1204`)**

```cpp
const auto port = std::find_if(network.singularity_ports().begin(), ...,
    [&](const auto &candidate) { return candidate.id == trace->port; });
if (port == network.singularity_ports().end() || port->ordinal < 0) {
  ... result.sourceVertex = locus.vertex; result.sourceFace = face;
      reason = VertexTracePortOrdinalInvalid; return result;
}
```

**Emitter B — CB15's exact parameter (`:1217`)**

```cpp
const auto secondaryParameter = vertex_locus_secondary_parameter(
    topology, *locusIt->second.vertex, arc, incidence.orientation, *trace);
if (!secondaryParameter.has_value()) {
  ... result.sourceVertex = locus.vertex; result.sourceFace = face;
      reason = VertexTracePortOrdinalInvalid; return result;
}
```

They are textually adjacent, they set the **identical** locus fields, and neither records the arc, trace,
orientation or the failing subcondition. **No other producer or projection can create this rendered reason** — the
string is produced from the enum by a single `switch` arm.

This is the collapsed-reason pattern the project has already recorded three times (`LESSONS.md` §4 79, 82, 84),
reintroduced by CB15 in the same turn that correctly added a *distinct* new reason,
`RotationVertexTraceRaysExactlyCoincident = 62`, for the BJ3 fail-close case. The coincidence condition got its own
name; the parameter-unavailable condition did not.

---

## 4. BK2 — the failing incidence, traced statically

### 4.1 Emitter A is excluded

CB15's complete source delta between the TB12 and TB13 package sources is four files:

```
 include/directional/geometry/GlobalTopologyPlan.h |   1 +
 src/geometry/EmbeddedGraphTopology.cpp            | 178 +++-
 src/geometry/EmbeddedGraphTopology.h              |  17 +
 src/geometry/GlobalTopologyPlan.cpp               |   2 +
```

`src/geometry/SurfaceCellTracing.cpp` is **untouched**, so the field-aligned network — its arcs, traces,
singularity ports and node assignment — is byte-identical between TB12 and TB13.

Node ids are assigned by iterating `nodeVertices`, a `std::set<SourceVertexId>`, in sorted order
(`SurfaceCellTracing.cpp:4239-4244`), so **node id is monotone in vertex index**. `build_rotation_system` iterates
`incidences`, a `std::map<NetworkNodeId, …>`, in node-id order. Hence **vertex 10 is processed strictly before
vertex 47**.

TB12 failed *at v47*, which means it had already completed v10 — with the same network and the same emitter A,
whose inputs (`trace->port`, `network.singularity_ports()`) CB15 did not touch.

> **Emitter A did not fire at v10 in TB12, on identical inputs, so it is not what fires in TB13.**

### 4.2 Only a `Forward` incidence can reach emitter B

`vertex_trace_ray_second_point` splits on orientation:

- **`Reverse`** returns `field_boundary_point_barycentric(face, segment.entryPoint)` where `segment` is
  `trace.segments[arc.onePastLastSegment - 1U]` and `face` is that segment's own `sourceFace` (from
  `trace_ray_face`). A segment's entry point lies on an edge of the face it enters, so the lookup always succeeds.
- **`Forward`** takes the fallback chain audited in §5, which can exhaust.

Combined with §4.1:

> **The ordinal-366 failure is a `Forward` — emanating — trace ray at locus vertex 10 in face `(8,10,11)`,
> failing emitter B.**

### 4.3 Which emanating ray

Face `(8,10,11)` is **mesh row 8**, and at v10 it occupies **fan slot 7**, bounded by edges `10-11` (slot 6) and
`8-10` (slot 0). v10 is a degree-4 closed-fan corner with angle defect exactly `π/2` — one of the four
port-emitting singularities — verified with `tools/fixture_probe.py fan 10`.

`M3-CP4c-3-TB7-REV` already proved, exactly from the committed fixture, that row 8's branch-1 direction is
`(0, −2.77777777777777857, +2.77777777777777857)` over `(v8, v10, v11)` — an **exact IEEE zero at `v8`** — so the
port trace leaving singularity **v10** runs along mesh edge `(10,11)` and lands on **vertex 11** under Amendment 3.

That ray departs v10 into wedge slot 7 and exits at a **corner** of its own face. It is the incidence that reaches
emitter B.

---

## 5. BK3 — the exact second-point / parameter contract

### 5.1 The Forward fallback chain, and what it omits

```cpp
if (segment.edgeTransitExit.has_value())                       // (1) edge-transit exit
  return field_boundary_point_barycentric(face, *segment.edgeTransitExit);
if (segmentIndex + 1U < trace.segments.size()) {               // (2) next segment's entry,
  const auto continued = field_boundary_point_barycentric(     //     if expressible in THIS face
      face, trace.segments[segmentIndex + 1U].entryPoint);
  if (continued.has_value()) return continued;
}
if (trace.terminalContact.has_value() &&                       // (3) interior terminal contact
    trace.terminalContact->sourceFace == face.topology)        //     in this face
  return trace.terminalContact->barycentric;
if (trace.terminalPoint.has_value())                           // (4) terminal boundary point,
  return field_boundary_point_barycentric(face, *trace.terminalPoint);
return std::nullopt;
```

**`edgeTransitExit` is assigned on exactly two lines**, `SurfaceCellTracing.cpp:2399` and `:3061`, both from
`edgeTransit.exitPoint` — i.e. **only on the edge-transit path. A `VertexHit` exit never sets it.** So case (1)
cannot serve a vertex exit.

Case (2) requires the *next* segment's entry point to be expressible in *this* face. After a vertex transit the
entry point is built by `field_boundary_point_at_vertex(vertexTransit.nextFace, v)` — on an edge of the **next**
face. It is expressible in the current face only when that edge happens to be shared, which is not guaranteed and
is not a contract.

Cases (3) and (4) require the trace's terminal to be in, or expressible in, this face — false for a trace that
continues on to terminate elsewhere.

> **A segment that exits through a vertex, on a trace that continues past this face, has no case in the chain.**

### 5.2 The rejected ray is exactly representable

For face `(8,10,11)` the corner order is `vertices[0]=8, [1]=10, [2]=11`, so at locus v10: `corner = 1`,
`next = 2` (v11), `previous = 0` (v8). The exit at vertex 11 is barycentric **`(0, 0, 1)`**. Then

```
denominator = secondPoint[next] + secondPoint[previous] = 1 + 0 = 1 > 0
secondPoint[next] = 1 ≥ 0,  secondPoint[previous] = 0 ≥ 0
parameter = secondPoint[previous] / denominator = 0 / 1 = 0      (exact)
```

Every guard in `vertex_locus_secondary_parameter` passes and the parameter is **exactly 0** — the ray lies on the
`next`-side boundary of its wedge, which is precisely edge `(10,11)`, consistent with it running along that edge.

The other two nullopt paths are unreachable here: `corner >= 3` cannot occur because the face was already found in
`slots->faceSlots` (else `VertexTraceFaceMissingFromFan` would have fired first), and
`segment.sourceFace != face.topology` cannot occur because `face` *is* that segment's `sourceFace`, from
`trace_ray_face`.

> **A valid ray, with a valid exact parameter, rejected solely because the helper cannot locate its second point.**

### 5.3 Verdict on the contract

CB15's helper contract does **not** cover every valid production incidence. The gap is exactly one case — the
vertex exit — and it is the Amendment-3 case this project has known about since TB7-REV. Nothing about the ranking
mathematics is wrong; the exact opposite-edge projection remains a correct, tolerance-free within-wedge order key.

---

## 6. BK4 / BK5 — semantic defect, bounded; plus the minimum typed split

**This is a semantic defect, proved from static authority**, so BK4's diagnostic-only fallback does not apply and
BK8 authorizes a product correction. Per BK5 it is bounded to the invalid endpoint assumption in
`vertex_trace_ray_second_point`. **All of CB15's settled invariants are preserved**: locus-relative exact
within-wedge ordering, both orientations, interior-terminal support, exact-coincidence fail-close under
`RotationVertexTraceRaysExactlyCoincident`, no arc/trace/orientation identity tie-break, unchanged edge-locus
ranking, unchanged fan-slot/incidence/cut ownership. CB12 and CB14 are untouched.

One diagnostic measure travels with it, and only one: **emitters A and B must stop sharing a reason.** Without that
split, if the next TB still reds at this locus the review cannot tell an incomplete helper fix from a genuine port
defect — the exact ambiguity that cost this turn. The split is additive, changes no control flow, and is the
minimum needed to make TB14 decisive (BK4's discrimination requirement).

---

## 7. BK6 — accepted-boundary and carried-red ownership

**Accepted-boundary safety.** The correction adds a *last-resort* case to a chain that currently returns
`nullopt`, and `nullopt` is currently a hard error. Therefore:

> Any configuration that certifies today never reaches the new case, so no currently-succeeding rotation can
> change. Where cases (2) and the new vertex case could both apply they agree, because both resolve to the same
> shared vertex.

Selector 379 immutability verified (§2). Ordinals 1–365 unaffected.

**Carried reds, unchanged owners:** 368 sphere `TraceEventPositionInvalid` / `NoCarrierMatch`
(`M3-CP4c2-TB-X2-CAND-04`); 369 saturation (`M3-CP4c2-TB-X2-R10-CAND-01`); 370 empty-network typed error
(`M3-CP4c2-TB-X2-R8-CAND-02`) — **no correction authorized**; 374 folded cone (`M3-CP4c3-TB7-CAND-02`) — no atlas
weakening; the 371/372 test coupling (`M3-CP4c3-TB10-REV-CAND-01`) stays **DEFERRED**; vertex 30
(`M3-CP4c3-TB6-CAND-01`) and the `finalize_field_aligned_events` contact fall-through remain **ACTIVE**.
**367/371/372 share the vertex-10 upstream red and create no duplicate stable event.**

---

## 8. BK7 — the v47 obligation stays open

`M3-CP4c3-TB11-CAND-01` **does not close** from TB13. The required conjunction was 365/365 accepted **and** the old
v47 collision absent **and** a full five-ray v47 rotation with distinct former-pair ranks; the third was never
reached because the new vertex-10 red fires earlier. TB13's selector-379 witness proves the *compiled helper*
executes, not the production path.

`M3-CP4c3-TB12-REV-CAND-01` is **PARTIALLY RUNTIME DISCRIMINATED**: the v47 collision is absent at ordinal 366, but
the five-ray rotation with distinct ranks was not published.

> **Any TB that clears vertex 10 must re-prove the original conjunction** — 365/365 accepted, old v47 collision
> absent, and the full five-ray v47 rotation with distinct former-pair secondary ranks — before either candidate
> closes. **There is still no vertex-30 discriminator.**

---

## 9. BK8 — the single frozen successor: `M3-CP4c-3-CB16`

**Type:** Code + Build. **Product correction plus one typed split.** **Owner:**
`src/geometry/EmbeddedGraphTopology.cpp::vertex_trace_ray_second_point`.

- **BL0** — accepted 365 untouched; **selector 379 byte-frozen** at `ef51298f…842594b7`, republished unchanged;
  **eight standard compile targets with mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BL1** — add a **vertex-exit case** to `vertex_trace_ray_second_point`'s `Forward` chain: when the segment's
  exit resolves to a vertex that is a corner of `face`, return the exact unit barycentric at that corner. Recover
  the vertex identity from the existing exact authority — the next segment's entry point support
  (`FieldBoundaryPoint::source_support()`, parameter 0 → `edge.first()`, 1 → `edge.second()`), or the segment's
  `outgoingCarrier` endpoint that the continuation reaches. **Exact rationals only; no tolerance, no float.**
- **BL2** — place the new case **last in the chain**, after the existing four. This makes the accepted-safety proof
  exact: it is reached only where the helper returns `nullopt` today, which is already a hard error. Where case (2)
  and the new case could both apply they resolve to the same shared vertex, so ordering changes no result.
- **BL3** — **split the collapsed reason.** Introduce a distinct typed reason for
  `vertex_locus_secondary_parameter(...) == nullopt` (e.g. `VertexTraceSecondaryParameterUnavailable`), leaving
  `VertexTracePortOrdinalInvalid` to emitter A alone. Retain, on that error, at least the **arc, trace,
  orientation, segment bounds, and which subcondition** produced the `nullopt` (face/record/corner unavailable,
  second point unavailable, or invalid denominator). Do not broaden beyond that.
- **BL4** — preserve every CB15 invariant named in §6, and do not revert CB12 or CB14.
- **BL5** — witnesses. *Positive:* an emanating ray whose segment exits at a wedge corner ranks with the exact
  boundary parameter (0 or 1) and its rotation publishes. *Negative:* a ray with genuinely no representable second
  point still fails, now under the **new** typed reason. *Regression:* a ray with an edge-transit exit produces a
  byte-identical parameter and rotation before and after.
- **BL6** — append **selector 380** only on demonstrated falsification; no reordering of any existing ordinal.
- **BL7** — prohibitions: no identity-based ray-order tie-break; no tolerance or float-derived topological
  decision; no change to `vertex_locus_secondary_parameter`'s projection formula, `vertex_trace_secondary_ranks`,
  `build_vertex_fan_slots`, `trace_ray_face`, the edge-locus branch, the incidence map, or cut ownership; no
  revert of CB12/CB14/CB15; no repair of the finalize/contact fall-through; no 371/372 decoupling; no sphere,
  saturation, ordinal-370 or folded-cone correction; no fixture mutation.
- **BL8** — audit by assumption; prove via §7 that no accepted-green rotation changes, and demonstrate a
  byte-identical before/after parameter on at least one edge-transit witness.
- **BL9** — publish six `M3-CP4c-3-TB14` discriminators in advance:
  1. ordinals **1–365 remain 365/365**;
  2. ordinal 366 no longer reports a vertex-10 rotation failure — a repeat there falsifies BL1;
  3. if any rotation red remains, it carries the **new** typed reason and its retained arc/trace/orientation, or
     `VertexTracePortOrdinalInvalid` meaning emitter A specifically — the two are now separable;
  4. **the BK7 conjunction is re-proved**: old v47 collision absent **and** the full five-ray v47 rotation
     published with **distinct** former-pair secondary ranks;
  5. `M3-CP4c3-TB11-CAND-01` and `M3-CP4c3-TB12-REV-CAND-01` close only on 1, 2 and 4 together;
  6. certification may for the first time proceed past rotation construction into the face walk, where
     `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` can legitimately appear.

**No vertex-30 discriminator is published.**

---

## 10. Assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review describes package 83. | `review_check.py authority a2fd98ea` reports the commit is an ancestor of HEAD with **empty** code drift. |
| §4.1 | Emitter A is not firing. | CB15's delta touches four files, none `SurfaceCellTracing.cpp`; node ids are monotone in vertex index; `incidences` is a node-id map, so v10 precedes v47; TB12 reached v47 on the identical network. |
| §4.2 | Only `Forward` can fail. | The `Reverse` branch resolves the entry point of the segment's own face, which by construction lies on an edge of that face. |
| §4.3 | The ray is v10's port trace along edge (10,11). | TB7-REV's exact fixture proof (row 8 branch-1 direction with an exact IEEE zero at v8) plus `fixture_probe.py fan 10`, which puts face `(8,10,11)` at slot 7 bounded by edge `10-11`. |
| §5.1 | A vertex exit has no case. | `edgeTransitExit` is assigned on exactly two lines, both on the edge-transit path; the remaining fallbacks require expressibility in *this* face, which a continuation through a shared vertex does not guarantee. |
| §5.2 | The ray is exactly representable. | Corner arithmetic on face `(8,10,11)` gives second point `(0,0,1)`, denominator 1, parameter exactly 0 — every guard passes. |
| §6 | A product correction is authorized. | The condition is determined, not underdetermined; BK4's fallback is conditioned on failure to prove, and §4–§5 prove it. |
| §7 | The correction is accepted-safe. | Placed last in the chain (BL2), it is reached only where the helper returns `nullopt` today, which is already a hard error. |
| BL9.4 | The v47 conjunction is still owed. | TB13 never published the five-ray v47 rotation; the selector-379 witness exercises the compiled helper, not the production path. |

---

## 11. Lessons

- **88 (new).** *A turn that adds a typed reason should audit the reasons it reuses.* CB15 correctly minted
  `RotationVertexTraceRaysExactlyCoincident` for its fail-close case, then routed its other new failure into the
  pre-existing `VertexTracePortOrdinalInvalid` — recreating, in the same commit, the collapsed-reason ambiguity
  that lessons 79, 82 and 84 already record. When a change adds a condition, the question is not only "does this
  need a name" but "does the name I am reusing still mean one thing".
- **89 (new).** *Execution order across turns is evidence.* The legacy emitter was excluded not by reading its
  logic but by proving that the same code, on a byte-identical network, had already passed that very vertex in the
  previous TB — because node ids are monotone in vertex index and the failing vertex sorts earlier. When a
  successor changes one layer and the failure moves, the untouched layers' prior successes are a usable proof
  instrument.
- **90 (new).** *A helper that enumerates ways to find a value owes the enumeration, not the value.* CB15's
  ranking mathematics is correct and its guards are correct; the defect is a four-case lookup chain missing a
  fifth case that the project had already documented (Amendment 3's vertex arrival, TB7-REV). When a function's
  body is a fallback chain, review the chain's **coverage** against the producer's cases, not the arithmetic after
  it.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB16`** under **BL0–BL9**.
