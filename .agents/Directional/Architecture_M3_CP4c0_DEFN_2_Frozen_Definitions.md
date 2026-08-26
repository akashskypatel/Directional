# Architecture M3 CP4c-0 — DEFN-2: Frozen Definition of Grazing Continuation

**Turn:** `M3-CP4c-0-DEFN-2`
**Type:** Independent definition / review / planning only — no product, test, fixture, selector, build, package, or runtime mutation
**Governs:** the `DESIGN.md` §4.5 gap opened by Amendment 9 — *what a trace does when it reaches an edge that the neighbouring face's direction also exits*
**Status:** **FROZEN.** §4–§11 are normative for `M3-CP4c-0` and may change only by an explicit plan update.
**Incoming evidence:** `M3-CP4c-0-TB-R7`, COMPLETE / VALID SEMANTIC RED, control/run/job `3d1ef24d6bcccb7e4e821d713a21860bc0598bd0 / 33019554121 / 98346293968`, package `9625495708`, result `9626003625`
**Incoming accepted authority:** M3-CP4ab **316/316**, run/job `32758293793 / 97530833220`

---

## 0. Verdict, stated first

**The chosen model is *grazing edge transit*.** A trace that reaches an edge which is an outflow
carrier of the face it is about to enter does not enter that face and does not stop. It **transits
along the edge to one endpoint vertex**, chosen by an exact sign predicate on already-published
authority, and then re-enters the existing vertex machinery — T2 regular re-emission or T3
`SingularityTermination`.

Three facts decided this, and each is independently checkable:

1. **It is the unique continuous extension of an already-frozen rule.** Amendment 3 (T1
   exhaustiveness) already defines what happens when the entry face's direction is *exactly* tangent
   to the entry edge: the trace travels along that edge and exits at a vertex. Grazing is the
   neighbourhood of that case. §5.4 proves the two rules select **the same vertex** in the limit, by
   the same expression. Choosing "terminate" for grazing while "slide to a vertex" for exact tangency
   would make the model discontinuous across a measure-zero configuration — the precise defect
   Amendment 9 was written to stop repeating.
2. **The slide direction is unambiguous on every measured configuration.** Re-derived here from the
   committed `.obj` / `.rawfield` alone: **72/72** grazing configurations on the prescribed sphere and
   **120/120** on the torus have both incident faces agreeing on the sign of the edge-parameter rate.
   **Zero disagreements, zero zero-rates.** §3.
3. **It keeps Q8's 24 traces reachable and adds no new state machine.** The transit is a *single
   deterministic hop* to a vertex, not an edge-following mode with its own traversal state. There is
   no new event kind, no new traversal loop, and no tolerance.

At the live locus this resolves completely and checkably. Sphere edge `6-8`, source face `6-8-9`,
target face `6-8-97`: both faces' edge-parameter rates are positive (`+5.0071`, `+3.8017`), so the
trace transits to **vertex 8** — and **vertex 8 is a singularity** (`sphere_prescribed.fieldmeta.json`,
`singular_vertices = [0, 8, 21, 24, 25, 34, 45, 49]`). The trace terminates by **T3
`SingularityTermination`**, which `DESIGN.md` §7.2 step 5 already lists as a lawful terminator.

**One prediction must be recorded now, because it will look like a failure and is not.** The eight
singularities sit at the eight corners of a cube inscribed in the sphere (§3.4, exact coordinates
`(±1, ±1, ±1)/√3`). The seeded trace at vertex `0 = (+1, −1, −1)` terminates at vertex
`8 = (+1, +1, −1)` — an **adjacent cube corner**. If the field's separatrix network is the cube's edge
graph, the sphere publishes 24 traces forming 12 singularity-to-singularity separatrices with **no
trace/trace contact at all**, and binding **Q8 criterion 3 will not be satisfiable on this witness**.
§9 pre-commits the response: Q8 is **not amended**, criterion 3 routes to review as it already
requires, and §9.3 states what that review must conclude and what witness C4/C5 actually needs.

---

## 1. What TB-R7 delivered, and what it did not

| Measure | Result | Weight in this decision |
|---|---|---|
| Frozen gate | **338/338**, accepted prefix **316/316**, first-328 **328/328**, F3 **2/2** | Binding precondition. Satisfied. |
| K1 near-tangency census | Sphere disagreeing median `0.021788`, max `0.200424`; agreeing centred `0.915773`; torus/two-ring reproduce the separation | **Decisive for the regime.** Independently re-derived in §3. |
| K3 vertex-fan holonomy | **176/176** complete fans, **zero** mismatches, `usesPrincipalMatchingMinimizer=false` | **Decisive as an exclusion.** No period/transport defect exists to chase. |
| J3 matching cross-check | Legitimate **524/524**, correctly relabelled `oracleKind=principal-matching-implementation-cross-check`, `canDetectMatchingAliasing=false` | Confirms the implementation; proves nothing about aliasing, and TB-R7 no longer claims it does. |
| K2 grazing-cost proxy | **0/24** traces reached a grazing observation; every trace `traversedEdges=1` | **Zero weight — and §2 shows why it is a test-side defect, not a limitation of the model options.** |
| Q8 | CREDITABLE / RED at criterion 2 | Expected; CB7 was diagnostic-only. |

TB-R7's decision row is the third one in its own corrected K4 table: *K3 holonomy clean, J3
implementation cross-check clean, K1 reproduces the predicted separation* → **the evidence supports
the tracing-model definition gap.** That row is satisfied exactly, so this definition turn is
authorized to freeze.

**What TB-R7 did not deliver is cost discrimination among the four model options.** K2 was supposed to
supply it and published nothing. This turn therefore decides on *structure* — continuity with an
already-frozen rule, exactness, and single-writer preservation — not on measured continuation cost.
§4 states the reasoning for each rejected option so the choice is auditable without K2.

---

## 2. Why K2 measured nothing — a test-side defect, diagnosed

This matters beyond bookkeeping: TB-R7 recorded K2 as a *"diagnostic limitation / non-stable
observation"* without a mechanism, and an unexplained null result in the evidence base is the kind of
thing that gets re-litigated for three more turns.

`cp4c_sphere_grazing_cost_census` (`tests/FieldAlignedCurveNetworkTests.cpp:4033-4133`) walks each
singularity port itself rather than calling production's continuation. Its per-step carrier resolution
is `tests/FieldAlignedCurveNetworkTests.cpp:4067-4072`:

```cpp
} else {
  const auto outgoing =
      cp4c_distinct_outgoing_carriers(*pairing, *incomingCarrier);
  if (outgoing.size() == 1U) outgoingCarrier = *outgoing.begin();
}
if (!outgoingCarrier.has_value()) break;
```

**That is the retired Cartesian carrier-set lookup** — the exact rule `M3-CP4c-0-DEFN` §5.1 deleted,
reimplemented inside a diagnostic. It carries no `FieldBoundaryPoint`, so on any `1×2` face it sees two
outgoing carriers, resolves nothing, and `break`s.

The prescribed sphere is **50 % `1×2`** (DEFN §1.1, Z1 census). A walk that dies on the first `1×2` face
will report `traversedEdges=1` and `firstGrazingStep=none` for every trace. That is precisely what
TB-R7 observed on **all 24**. It is also why K2 never reached the G5 locus, whose production trace
history is **seven** steps long: production resolves `1×2` faces with the position datum, and K2 cannot.

**Consequences, normative:**

1. **K2's null result carries no information about any model option.** It measured the retired rule, not
   the grazing regime. No model may be preferred or rejected on it, in this turn or a later one.
2. **The corrected K2 is measure L8 (§10).** It must call
   `resolve_field_branch_continuation(currentFace, *pairing, *currentEntryPoint)` and thread the
   returned `exitPoint` forward, exactly as `field_aligned_candidate_traces` does. A diagnostic that
   re-implements a production rule is measuring the diagnostic.
3. **Durable lesson (L-2 in §12).** A non-gating census that reimplements a rule the design has retired
   will silently report the retired rule's behaviour and be read as evidence about the current one.
   Diagnostics must call the production entry point or state in their own output which rule they
   implement.

This is a **candidate / non-stable test-side defect**, not a product regression. Stable accounting
**42 / 14 / 28** is unchanged; §13 records the tracker entry.

---

## 3. Independent re-derivation of the evidence

Performed on the committed fixtures only — `benchmarks/fixtures/milestone-g/sphere_prescribed.obj`,
`.rawfield`, `.fieldmeta.json`, and `torus.obj` / `.rawfield`. No Directional binary, build, or test was
executed. Face keys were sorted to match `SourceFaceTopologyKey::make`
(`src/authority/AuthorityKernel.cpp:32-41`), `dbary` was recomputed by the same
projection as `src/authority/FieldTransportAtlas.cpp:100-118`, and the branch correspondence was taken
as the principal matching of raw index 0 across each shared edge.

### 3.1 The grazing population reproduces exactly

| Witness | `(edge, branch)` pairs | Grazing (distinct) | TB-R7 K1 distinct | Grazing ratio median | Grazing ratio max | Non-grazing median |
|---|---:|---:|---:|---:|---:|---:|
| prescribed sphere | 1152 | **72** | **72** | **0.021788** | **0.200424** | 0.923319 |
| torus | 864 | **120** | **120** | 0.074604 | 0.102869 | 0.918970 |

Both distinct counts and both extreme values match TB-R7's runtime figures **to six decimal places**.
The runtime census and this fixture-only derivation are therefore measuring the same object, and K1 is
confirmed by a route that shares no code with the product.

Directed counts double these (`144` and `240`), matching the report, because grazing is **symmetric**:
the predicate is "the shared edge is an outflow carrier on both sides", which does not distinguish
which face the trace arrives from. That symmetry is load-bearing in §5.3.

### 3.2 The slide direction is never ambiguous on the measured witnesses

For each grazing configuration, the rate of change of the published edge parameter was evaluated in
**both** incident faces (§5.2 defines the quantity):

| Witness | Grazing configs | Both rates same sign | Opposite signs | Either rate exactly zero |
|---|---:|---:|---:|---:|
| prescribed sphere | 72 | **72** | **0** | **0** |
| torus | 120 | **120** | **0** | **0** |

**Zero ambiguity in 192 measured configurations.** §5.5 nevertheless specifies a typed rejection for
the ambiguous case, because the two-ring and four-triangle-fan witnesses are constructed in test
support rather than in a fixture file and could not be measured here — and because the fan's grazing
pair is a *fixture artifact* whose matching is imposed (Amendment 8), with a tangency ratio of exactly
`0.500000` rather than the near-tangent values every legitimate witness shows. The fan is the one place
an ambiguous slide could plausibly appear. **Measure L2 must settle it.**

### 3.3 Grazing edges do not collide

| Property | Sphere |
|---|---|
| Grazing configurations | 72 |
| Distinct edges carrying them | **72** |
| Configurations per grazing edge | **1** for every edge (histogram `{1: 72}`) |
| Edges whose configurations slide to *both* endpoints | **0** |
| Grazing edges incident to a singularity | **24** |
| Grazing edges per singular vertex | **3**, for all eight |

No edge grazes for two different branches, so no edge can host two transits in opposite directions.
This is what makes the transit safe to define per edge rather than per (edge, branch, trace).

### 3.4 The eight singularities are the corners of a cube

From `sphere_prescribed.obj`, exactly:

| Vertex | Position | `×√3` |
|---:|---|---|
| 0 | `(+0.5774, −0.5774, −0.5774)` | `(+1, −1, −1)` |
| 8 | `(+0.5774, +0.5774, −0.5774)` | `(+1, +1, −1)` |
| 21 | `(+0.5774, −0.5774, +0.5774)` | `(+1, −1, +1)` |
| 24 | `(+0.5774, +0.5774, +0.5774)` | `(+1, +1, +1)` |
| 25 | `(−0.5774, −0.5774, −0.5774)` | `(−1, −1, −1)` |
| 34 | `(−0.5774, +0.5774, −0.5774)` | `(−1, +1, −1)` |
| 45 | `(−0.5774, −0.5774, +0.5774)` | `(−1, −1, +1)` |
| 49 | `(−0.5774, +0.5774, +0.5774)` | `(−1, +1, +1)` |

Eight index-`1/4` cones at the eight corners of an inscribed cube; `Σ index = 8 × ¼ = 2 = χ`, and
valence `4 − 1 = 3` gives `8 × 3 = 24` ports. Each singular vertex has exactly **3** grazing edges
(§3.3) — one per port. The 72 grazing edges lie in narrow corridors about the twelve cube-edge great
circles (maximum midpoint distance from the nearest such plane: `0.158`).

**Reading:** the grazing edges are not scattered discretization noise. They are the mesh edges that lie
*along* the field's separatrices. A separatrix running from corner to corner crosses a corridor of mesh
edges nearly parallel to itself; those are exactly the edges both incident faces call outflow. **The
grazing case is not an exceptional pathology — it is what the interesting part of the network looks
like on this witness**, which is why terminating on it would forfeit the checkpoint.

### 3.5 The live locus, resolved

| Term | Value | Source |
|---|---|---|
| edge | `6-8`, canonical `first()=6`, `second()=8` | G5 |
| source face key (sorted) | `(6, 8, 9)`; opposite index `2` = vertex 9 | fixture |
| target face key (sorted) | `(6, 8, 97)`; opposite index `2` = vertex 97 | fixture |
| `d` source | `[−4.0035, +5.0071, −1.0035]` | recomputed; matches TB-R6 |
| `d` target | `[−3.2247, +3.8017, −0.5770]` | recomputed; matches TB-R6 |
| outflow on both sides | `d_src[2] < 0` **and** `d_tgt[2] < 0` | **grazing, exactly** |
| parameter index (`edge.second()` = 8) | `1` in both faces | sorted keys |
| parameter rates | `r_src = +5.0071`, `r_tgt = +3.8017` | **same sign** |
| slide target | parameter `1` → **vertex 8** | §5.2 |
| vertex 8 status | **singularity** (`fieldmeta` list) | fixture |
| outcome | **T3 `SingularityTermination`** | §5.3 |

The seven-step G5 trace seeded at singularity `0` / vertex `0` therefore terminates at singularity
vertex `8` — the adjacent cube corner. That is a complete, lawful separatrix.

---

## 4. The four options, adjudicated

TB-R6 §6 framed four and forbade choosing on the evidence then available. K1 and K3 are now in, K2 is
void (§2), and the continuity argument (§5.4) is decisive independently of cost.

### 4.1 Typed grazing terminus — **REJECTED**

Stop the trace with a new typed network event.

- **Fatal:** it is discontinuous with Amendment 3. At `d_target[opp] = 0` exactly, the frozen rule
  already slides along the edge to a vertex and continues. At `d_target[opp] = −ε` this option stops.
  The model would branch on an exact-zero test whose two sides behave incomparably — a *topological*
  outcome hinging on a knife-edge, which is the same defect class as a tolerance deciding ownership
  even though no tolerance appears.
- **Fatal:** it forfeits the checkpoint. §3.4 shows the grazing edges *are* the separatrix corridors.
  Terminating there truncates every trace before it reaches its terminal singularity, and Q8
  criterion 2's 24-trace network becomes unreachable — not because the sphere is hard, but because the
  model refuses to describe the sphere's actual field.
- **Not fatal but disqualifying:** it adds a `FieldAlignedNetworkEventKind`, which per DEFN §6.4 forces
  every accepted CP3b identity asserting terminal-kind exhaustivity to be re-read.

### 4.2 Refinement precondition — **REJECTED**

Declare near-tangency inadmissible input; require A0/A1 preprocessing.

- The admissibility predicate would be exact and stateable ("no edge is an outflow carrier on both
  sides for matched branches"), so it survives `DESIGN.md` §6.3 — this option is not unsound.
- **It is empirically hopeless.** It rejects the prescribed sphere (72 edges), the torus (120 edges),
  *and* the two-ring skew disc (2), i.e. **every non-degenerate witness the project owns, including two
  that are already accepted at 316/316.** An admissibility condition that no witness satisfies is a
  refusal to implement A2a.
- **It is also aimed at the wrong object.** §3.4 shows grazing tracks the *field's separatrices*, not
  mesh quality. Refining the mesh produces more, thinner triangles along the same corridors — the
  grazing corridor persists at every resolution. Mollification (`DESIGN.md` §4.8) addresses degenerate
  triangles and would not touch this.

### 4.3 Tangential continuation as an edge-following mode — **REJECTED IN THAT FORM**

Add an edge-following state to the tracing model: the trace acquires "on an edge" as a first-class
traversal state with its own entry/exit rules.

- The *behaviour* is right; the *shape* is not. TB-R6 called this "the largest model change", and as a
  general edge-following mode it is: a second traversal state machine, a second termination analysis, a
  second interaction with `mandatoryByEdge`, and a second cycle/budget accounting.
- **It is unnecessary, and that is a theorem, not a preference.** §5.4 proves the slide always
  terminates at an endpoint of the *same* edge in one step, because the direction is constant per face,
  so the grazing predicate and the parameter rate are both constant along the whole edge. There is no
  configuration in which a trace slides part-way along an edge and leaves in the middle. An
  edge-following *state* would therefore never be observed in more than one step.

### 4.4 Exact-arithmetic joint-face reformulation — **ADOPTED, in the bounded form of §5**

Decide the grazing case **once, at the edge, from both faces jointly**, instead of asking each face
independently.

- It is where the defect actually is: A1 classifies each face's flow from that face's own `dbary` and
  nothing ever related the two signs (DEFN §9, Amendment 4). Amendment 9 then proved the *continuum*
  relation between them false for piecewise-constant data. The remaining correct move is to define what
  the joint configuration **means**, which is what §5 does.
- Adopted with §4.3's behaviour and none of its machinery: the joint decision yields a **single hop to a
  vertex**, handed straight to the existing T2/T3 vertex path.
- The decision site already exists and already holds both faces' pairings:
  `src/geometry/SurfaceCellTracing.cpp:1052-1056`, where
  `validate_field_branch_transport_flow(currentFace, *pairing, *nextFace, *nextPairing,
  decision.outgoingCarrier, directed->signedLift)` currently rejects. **No new plumbing is required to
  reach the data.**

---

## 5. The frozen rule — **G**, grazing edge transit

Names in this section are normative. `X` is the face the trace is leaving, `Y` the face it would
otherwise enter, `e` the shared carrier, `b` the branch in `X`, `b′ = b.rotated(signedLift)` the branch
in `Y`.

### 5.1 G1 — the carrier relation is a classification, not a rejection

`validate_field_branch_transport_flow` is replaced by a **classifier** over the target-side flow of the
carrier. The classification is by the exact sign of a single published rational, using A1's own
convention (`src/authority/FieldTransportAtlas.cpp:162-172`): for edge `e` opposite local index `opp`,
`d[opp] > 0` is `Inflow`, `d[opp] < 0` is `Outflow`, `d[opp] == 0` is `Tangent`.

```
FieldBranchEdgeFlowRelation ← relation of e to (Y, b′)

  d_Y[opp_Y] >  0   →  Inflow    — ordinary cross-edge continuation, unchanged
  d_Y[opp_Y] == 0   →  Tangent   — enter Y; Amendment 3 already governs (§5.4)
  d_Y[opp_Y] <  0   →  Outflow   —  G R A Z I N G : do not enter Y; transit (§5.2)
```

**Normative:** the relation must be computed from `Y`'s published `direction`, **not** by membership
testing `incomingCarriers`. Membership cannot separate `Tangent` from `Outflow` — the present predicate
`carrier ∉ targetPairing.incomingCarriers` lumps them, and that conflation is why the exactly-tangent
case is currently mis-rejected alongside the grazing case. Carrier-set membership remains authoritative
for what it *is* (§5.7), but the three-way relation is read from the sign.

**Precondition, asserted:** `e ∈ outgoingCarriers(X, b)`. This is already guaranteed by
`BranchContinuationOutsideOutflowSet` (`SurfaceCellTracing.cpp:446-455`); the classifier must assert it
rather than assume it.

### 5.2 G2 — the transit target, an exact sign predicate

Let `e.first() < e.second()` (canonical, `AuthorityKernel.cpp:18-28`). Let

- `β_X` = index of `e.second()` in `X`'s sorted key vertices,
- `β_Y` = index of `e.second()` in `Y`'s sorted key vertices,
- `r_X = d_X[β_X]`, `r_Y = d_Y[β_Y]` — exact rationals, read directly from the published directions.

```
r_X > 0  ∧  r_Y > 0   →  transit to e.second(),  terminal parameter exactly 1
r_X < 0  ∧  r_Y < 0   →  transit to e.first(),   terminal parameter exactly 0
otherwise             →  BranchGrazingSlideDirectionAmbiguous  (§5.5)
```

**Why `r` is the right quantity, from source rather than from analogy.**
`field_boundary_point_from_barycentric` (`SurfaceCellTracing.cpp:271-287`) builds the published
parameter as `barycentric[*secondIndex]` — **the parameter of a `FieldBoundaryPoint` on `e` *is* the
barycentric coordinate of `e.second()`**. Barycentric coordinates are affine, so along `p + t·d` the
rate of change of that coordinate is exactly `d[β]`. Therefore `r_X` and `r_Y` are, literally, *the rate
at which each face drives the published edge parameter*, in the units the parameter is already
published in. No metric, no unfolding, no normalization, and no new convention enters.

**Scale-invariance, required.** The field's per-face magnitude carries no semantics. `r_X` and `r_Y` are
each positively homogeneous of degree 1 in their own face's direction, so the predicate is invariant
under independent positive rescaling of either face's `dbary`. This must be an authored identity (L4):
scaling one face's direction by a positive rational must not change the transit target.

**Orientation-freedom, required.** `e` is canonical, so `β_X` and `β_Y` name the same physical endpoint
from both sides and the predicate is symmetric under swapping `X` and `Y`. Combined with §3.1's
symmetry of the grazing predicate itself, the whole rule is independent of which face the trace arrives
from. This must also be an authored identity (L4).

### 5.3 G3 — dispatch at the transit endpoint

The transit produces a `FieldBoundaryPoint{e, 0}` or `FieldBoundaryPoint{e, 1}`, whose §3.2 projection
is `SourceVertexSupport`. Dispatch is then **exactly the existing vertex dispatch**, in this precedence:

| Order | Condition | Outcome |
|---:|---|---|
| 1 | `e ∈ mandatoryByEdge` | **`MandatoryBarrierTermination` at the point where the trace met `e`** — *not* at the endpoint. A hard rail stops a trace on first contact; it is never slid along. Already correct in source: the barrier test (`SurfaceCellTracing.cpp:1016-1020`) precedes the flow check and must keep that precedence. |
| 2 | `e` has one incident face | Not grazing — there is no `Y`. Existing boundary handling, unchanged. |
| 3 | endpoint vertex carries a `FieldSingularityFact` | **T3 — `SingularityTermination`.** `trace.terminalPoint` is the endpoint. |
| 4 | otherwise | **T2 — vertex re-emission** via `resolve_field_vertex_transit`. |

**One bounded change to T2 is required and is stated explicitly.** `resolve_field_vertex_transit`
excludes `currentFace` from candidacy (`SurfaceCellTracing.cpp:551`), which is correct for a trace
arriving at a vertex *from inside* that face — continuing into it would be going backwards. A trace
arriving **along an edge** came from inside neither `X` nor `Y`, so neither may be excluded.

> **Frozen:** the vertex-transit search takes an explicit arrival mode. `FaceInterior` keeps the
> exclusion set `{currentFace}` — **accepted behaviour is bit-identical**. `EdgeTransit` uses the empty
> exclusion set. The sector rule itself is untouched: `direction_in_vertex_sector` remains the single
> writer of vertex-emission semantics (DEFN §9), and after Amendment 2 it partitions the fan, so exactly
> one candidate is expected in both modes. Zero or two candidates remain the existing fail-closed
> `VertexTransitSectorUnresolved`.

### 5.4 G4 — the continuity theorem

**Claim.** As `d_Y[opp_Y] → 0⁻`, rule G selects the same endpoint that Amendment 3 already selects at
`d_Y[opp_Y] = 0`.

**Proof.** Let `d_Y[opp_Y] = 0` exactly, and let the trace enter `Y` at a point of `e`, so
`p[opp_Y] = 0`. Coordinate `opp_Y` then satisfies `ṗ = 0` and stays zero for all `t`: the trace travels
**along `e`**. Since `Σ d_Y = 0` and `d_Y[opp_Y] = 0`, the remaining two coordinates satisfy
`d_Y[α_Y] + d_Y[β_Y] = 0` with `α_Y` the index of `e.first()`. They are non-zero and opposite in sign
(both zero would make `d_Y = 0`, rejected by T7).

- If `d_Y[β_Y] < 0`, coordinate `β_Y` reaches zero first; `opp_Y` is already zero, so the exit point has
  two zero coordinates and is the vertex `e.first()`. Amendment 3 dispatches it to T2/T3.
- If `d_Y[β_Y] > 0`, then `d_Y[α_Y] < 0` and by the same argument the exit is `e.second()`.

So Amendment 3's endpoint is `e.second()` iff `d_Y[β_Y] > 0`, i.e. **iff `r_Y > 0`** — the same
expression G2 uses, on the same index. And in the limit `d_Y[opp_Y] → 0⁻` the source-side rate `r_X`
must share that sign, since the two directions become parallel to `e` and to each other. G is therefore
the continuous extension of Amendment 3, and no other endpoint choice is. ∎

**Corollary — the transit is one hop, never a mode.** `d_X` and `d_Y` are constant on their faces, so
`d_Y[opp_Y] < 0`, `r_X` and `r_Y` are constant along the whole of `e`. The grazing predicate and the
transit direction do not vary with position on the edge, so the slide is monotone in the parameter and
reaches an endpoint of `e` in a single step. There is no interior stopping point and no configuration
requiring a second edge-following step. This is what retires option §4.3's machinery.

### 5.5 G5 — typed rejection for the ambiguous case

```
BranchGrazingSlideDirectionAmbiguous  (new code, value 28)
```

Fires when `e` is grazing and `¬(r_X > 0 ∧ r_Y > 0) ∧ ¬(r_X < 0 ∧ r_Y < 0)` — i.e. the two incident
faces disagree on the direction of the slide, or either rate is exactly zero.

**Required loci, every one observable in the emitted diagnostic string through a named `*_locus`
helper, printable ASCII only, site-sourced, per Amendment 6:** `sourceFace` (`X`), `branch` (`b`),
`relatedSourceFace` (`Y`), `relatedBranch` (`b′`), `sourceEdge` (`e`), `signedLift`, the entry
parameter, and the four exact rationals `d_X[opp_X]`, `d_Y[opp_Y]`, `r_X`, `r_Y`.

**Measured incidence: zero in 192 configurations** across the sphere and torus (§3.2). The rejection is
fail-closed insurance for the unmeasured constructed witnesses, not an expected path. It **may not** be
softened into a tie-break, and **no tolerance may be introduced to decide it** — Amendment 9 clause 3.

`BranchTransportFlowDisagreement` (value 25) is **retired from production emission**. Its enum value is
retained, never reused, with a comment recording that grazing is now a classified continuation rather
than a rejection. Its diagnostic consumers (the K1/H1 census) move to the §5.1 classifier. Retiring
rather than repurposing is deliberate: `LESSONS.md` §2 records what an overloaded code costs.

### 5.6 G6 — how a transit is recorded on the trace

**One additive field**, and no new struct:

```cpp
struct FieldAlignedCandidateTraceSegment {
  // ... existing members, unchanged ...
  std::optional<authority::FieldBoundaryPoint> edgeTransitExit;  // NEW
};
```

Set **only** on a segment whose continuation was an edge transit; its value is the endpoint of
`outgoingCarrier`, with `parameter` exactly `0` or `1`. Absent means the segment's exit is the point the
continuation rule computes, as today.

**Why this is sufficient and why it is not optional.** The segment already ends at the computed exit
point on `e`, and the *next* record begins at the endpoint of `e`. Both lie on `e`, so a consumer that
joins consecutive points reconstructs the slide correctly **without** the field. The field is required
anyway for two reasons: the transit must be *auditable* rather than inferable, and `LESSONS.md` §4
records that a representation with a writer and no enforcing reader is latent ambiguity. Measure L6
therefore requires an identity asserting that every trace whose continuation transited publishes it, and
that its parameter is exactly `0` or `1` with a `SourceVertexSupport` projection matching the vertex the
trace continued from.

**No `FieldAlignedNetworkEventKind` is added.** An edge transit is not a network 0-cell; it creates no
node and no incidence. CP3b's terminal-kind exhaustivity assumption is therefore untouched by this
DEFN — unlike DEFN-1, which made `SingularityTermination` producible.

### 5.7 G7 — what does not change

- **A1 publishes nothing new.** `direction`, `intervals`, `incomingCarriers`, `outgoingCarriers`,
  `FieldBranchTransportAdjacency`, `FieldBranchTopology::transport`, port attachments, cycles, effort,
  index — all unchanged. Every datum rule G reads is already published. **A1 is not touched by this
  DEFN at all**, and `branch_topology_digest` does not move.
- **`FieldBoundaryPoint`, `ExactUnitParameter`, and the §4.3 comparator are unchanged.**
- **T1–T7 are unchanged.** T6 (`t* = 0`) stays exactly as frozen and stays *unreachable*: grazing is
  now classified at the outgoing side, before `currentEntryPoint` is ever set to a point on an
  outflow edge of the entry face, so no well-formed state reaches T6. The TB-review Theorems 1–3 are
  preserved, not weakened.
- **`direction_in_vertex_sector` remains the single sector rule**, and A2a remains the single writer of
  `FieldBoundaryPoint` values on traces.
- **No tolerance is introduced anywhere.** Every predicate in §5 is an exact sign or exact equality test
  on published rationals.

---

## 6. Ownership delta

| Datum | Owner (single writer) | Published on | Consumers |
|---|---|---|---|
| carrier-to-target flow relation (`Inflow`/`Tangent`/`Outflow`) | **derived, not owned** — a pure function of A1's published `direction` | not stored | A2a continuation; K1 census |
| grazing transit target vertex | **A2a** | `FieldBranchContinuationDecision` (kind `EdgeTransit`) | A2a trace loop only |
| `edgeTransitExit` on a segment | **A2a** | trace segments | A2b (read-only, geometry reconstruction) |

**Prohibited, each a stop condition:** A1 acquiring a grazing field, flag, or classification (the
relation is derived on demand and never stored — storing it would create a second authority for a fact
`direction` already determines); a second slide-direction predicate anywhere; A2b computing or mutating
`edgeTransitExit`; the classifier being reintroduced as a carrier-set membership test; any threshold,
cutoff, or magnitude comparison entering §5.1 or §5.2.

---

## 7. Accepted-prefix re-proof matrix

### 7.1 The central claim: **no accepted trace changes, and this is provable**

`validate_field_branch_transport_flow` is **already live** in the accepted build. TB-R7 re-proved the
accepted prefix at **316/316 PASS** on package `9625495708` with that rejection in place. If any
accepted trace had ever crossed a grazing edge, it would have been rejected and the 316 would be red.

**Therefore no accepted trace crosses a grazing edge, and rule G — which changes behaviour only on
grazing edges — cannot change any accepted trace.** The two-ring's 2 and the fan's 1 distinct grazing
configurations exist but lie off every accepted trace path.

This is the exact analogue of DEFN §6.3's argument, and it is stronger: §6.3 reasoned from a build that
would have failed, this reasons from a gate that was measured green four days later.

### 7.2 Per-checkpoint matrix

| Checkpoint | Affected | Kind of change | Action |
|---|---|---|---|
| **M3-CP1** (A1 ports/cycles) | **nothing** — A1 is untouched; `branch_topology_digest` does not move | **no-op** | re-run; expect green |
| **M3-CP2** (rails/barriers) | barrier precedence restated, behaviour unchanged (§5.3 row 1) | **no-op** | re-run; expect green |
| **M3-CP2b** (Z4 transport) | none | **no-op** | re-run; expect green |
| **M3-CP3a** (candidate traces) | `FieldAlignedCandidateTraceSegment` gains optional `edgeTransitExit` | **shape + digest**; content unchanged per §7.1 | re-run; relative digest assertions track; expect green |
| **M3-CP3b** (events/composition) | **no new event kind**; no accepted event changes | **digest-only** | re-run; expect green |
| **M3-CP4ab** (regions/disc proof) | `network_digest` only | **digest-only** | re-run; expect green, including `EXPECT_EQ(8U, network.nodes().size())` |
| **M3-CP4c-0 prefix (317–338)** | `BranchTransportFlowDisagreement` negatives now assert a **classification**, not a rejection | **expectation change confined to the identities that own the retired code** | re-author those identities in the same turn; §10 L7 |

**Two edits are authorized and no others.** (i) The identities whose subject *is* the retired
`BranchTransportFlowDisagreement` rejection — they are re-authored, not deleted, to assert the new
classification and the transit. (ii) The K1/H1 census's classifier call. **Any other red is a stop**
(§11), and per DEFN §6.5 the expectation is never edited to make it pass.

### 7.3 Witness-stage capability, updated

| Witness | Reaches today | Expected after CB8 | Basis |
|---|---|---|---|
| two-ring skew disc | A2b | **A2b, unchanged** | §7.1 — no accepted trace grazes; 2 distinct grazing configs lie off-path |
| four-triangle fan | A2b | **A2b, unchanged** | §7.1; its 1 grazing config is the imposed-matching artifact (Amendment 8) |
| prescribed sphere | A2a, stops at the grazing edge | **A2a complete — 24 traces** | §3.4, §3.5 |
| torus | A2a, 0 traces | **A2a, 0 traces — unchanged** | no ports; deferred to CP4c-2 |
| mechanical feature | A1 rejects `IncompleteCycleBasis` | **unchanged** | deferred to CP4c-3 |

**The prescribed sphere is the only witness that can prove rule G**, and §3 proves it reaches exactly
the configuration G governs, 72 times.

---

## 8. What `DESIGN.md` §4.5 now says

Amendment 9 recorded that §4.5 "does not define the continuation of a trace that reaches an edge the
neighbouring face's direction also exits". **That gap is closed by §5 of this document.** §4.5's
normative text is extended by exactly one paragraph, and Ray–Sokolov's cited properties are preserved
rather than qualified:

> Where a triangle's inflow/outflow decomposition is read from a piecewise-constant field, a shared edge
> may be an outflow interval of **both** incident triangles. The trace does not cross such an edge and
> does not stop on it: it transits along the edge to the endpoint both incident directions drive the
> edge parameter toward, and re-enters the vertex rule there. The transit is decided by an exact sign
> predicate on the published barycentric directions, is independent of which face the trace arrives
> from, and terminates in one step because the directions are constant per face. It is the continuous
> extension of the exactly-tangent case.

**The cited guarantees are re-examined, not assumed:**

- **Non-crossing** is preserved. A transit lies *on* an edge and creates no interior crossing.
- **Non-merging** requires a measurement and gets one. Two traces entering the same grazing edge would
  overlap along it. §3.3 measures **one grazing configuration per edge** on the sphere, so two traces
  could share an edge only by arriving on the same branch from different parameters. **Measure L5 must
  count traces per grazing edge**; more than one is a typed observation and a return to review, not a
  silent merge.
- **Arbitrary-precision propagation** is preserved: the transit's terminal parameter is the exact
  integer `0` or `1`, which is the most exact value a parameter can take, and nothing is accumulated.

---

## 9. Q8 — **not amended**, with one prediction recorded in advance

TB-R7 authorized amending Q8 "only if the chosen model makes 24 traces unreachable". **Rule G does
not.** Q8's five criteria stand exactly as frozen.

### 9.1 Expected outcome per criterion

| Criterion | Expectation under rule G |
|---|---|
| 1 — accepted prefix and package integrity | **PASS** |
| 2 — prescribed sphere publishes the required **24-trace** network | **PASS expected.** 8 corners × 3 ports; §3.5 resolves the live blocker and §3.3 shows each of the 24 singularity-incident grazing edges is unambiguous |
| 3 — at least one terminal `TraceIntersection` | **Expected NOT satisfied — see §9.2** |
| 4 — torus/mechanical unchanged | **PASS** |
| 5 — carried | unchanged |

### 9.2 Criterion 3 will probably not be satisfiable on this witness, and that is a property of the witness

§3.4 establishes that the eight singularities are the corners of an inscribed cube and that each has
exactly three grazing edges — one per port. The live trace runs corner `(+1,−1,−1)` → corner
`(+1,+1,−1)`. If that pattern holds for all 24 ports, the network is the **cube's edge graph**: 24
traces pairing into 12 singularity-to-singularity separatrices, every one terminating by T3, and **no
trace ever contacts another**. Crash-on-contact would then have **no witness on the prescribed sphere**,
not because it is broken but because this field has nothing to crash.

**This is a prediction with a clean falsifier**, and it must be recorded before CB8 runs so it cannot be
retrofitted: *if the sphere publishes 24 traces and every one terminates with a `terminalSingularity`,
criterion 3's absence is explained; if any trace terminates otherwise, this prediction is wrong and the
explanation must be re-derived.*

### 9.3 The pre-committed response

Q8's own text says: *"If the sphere publishes a network but produces no terminal `TraceIntersection`, do
not adjust anything — return to review."* **That instruction stands and is not weakened here.** What is
frozen is what that review must decide, so the turn is not spent rediscovering §9.2:

1. **Do not weaken criterion 3, and do not relabel a singularity termination as a contact.**
2. **Do not add a witness to CP4c-0.** CP4c-0's question is the continuation rule, and criteria 1, 2 and
   4 answer it.
3. **The conclusion to reach is that criterion 3 is mis-assigned to CP4c-0.** Trace/trace contact is
   `C4`/`C5`, which belong to **CP4c-1**, and they need a witness whose separatrices do *not* pair
   singularities — a field with an odd or irregular port graph, not a cube. Identifying that witness is
   CP4c-1's work under the D4 witness-stage rule, which forbids reusing a witness on reputation.
4. Criterion 3 is then **re-homed to CP4c-1 by an explicit plan update**, with its reason recorded. It
   is not deleted and not silently dropped.

---

## 10. The bounded next Code + Build turn — measures **L**

**`M3-CP4c-0-CB8`.** Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. **Code + Build only;
compile all eight standard targets; execute nothing.** This is the first CP4c-0 turn since CB4 that is
authorized to change production semantics, and the authorization is bounded to §5.

### L0 — binding preconditions

Stop and return to review if any fails.

- **L0.1** `validate_field_branch_transport_flow` still returns an *error* and is still called at
  `SurfaceCellTracing.cpp:1052-1056` with both pairings in scope. If it has moved or changed shape, this
  definition is stale.
- **L0.2** A1's flow classification is still `d[opp] > 0 → Inflow`, `< 0 → Outflow`, `== 0 → Tangent`
  (`FieldTransportAtlas.cpp:162-172`). §5.1 depends on it verbatim.
- **L0.3** `field_boundary_point_from_barycentric` still builds the parameter as
  `barycentric[*secondIndex]` (`SurfaceCellTracing.cpp:283-285`). §5.2's identification of `r` with the
  parameter rate depends on it.
- **L0.4** `SourceFaceTopologyKey::make` still sorts (`AuthorityKernel.cpp:32-41`) and
  `SourceEdgeTopologyKey::make` still swaps so `first() < second()`. §5.2's indices depend on both.
- **L0.5** `resolve_field_vertex_transit` still excludes `currentFace` at `SurfaceCellTracing.cpp:551`
  and `direction_in_vertex_sector` is still the only sector rule.
- **L0.6** The accepted prefix is still 316 and the frozen CP4c-0 selector is still exactly 338
  identities with SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`.

### L1 — the classifier

Replace `validate_field_branch_transport_flow` with the §5.1 three-way classifier read from
`Y`'s published `direction`. Assert the `e ∈ outgoingCarriers(X, b)` precondition. Retire
`BranchTransportFlowDisagreement` from production emission; retain enum value 25 unused with a comment.
**`Tangent` must now enter `Y`** and reach Amendment 3's vertex exit — this fixes a live mis-rejection
and is part of L1, not a separate change.

### L2 — the transit rule

Implement §5.2 and add `FieldBranchContinuationKind::EdgeTransit`. Add
`BranchGrazingSlideDirectionAmbiguous` (value 28) with the complete §5.5 locus set, emitted through a
named `*_locus` helper, printable ASCII, site-sourced, per Amendment 6.

**Required non-gating census, `L2-census`:** for every witness that reaches A1, publish the grazing
population, and for each configuration the exact `d_X[opp_X]`, `d_Y[opp_Y]`, `r_X`, `r_Y`, the sign
agreement verdict, and the selected endpoint. **Falsifiable predictions:** prescribed sphere **72
distinct** grazing configurations on **72 distinct edges**, **zero** sign disagreements, **zero** zero
rates; torus **120 / 120 / 0 / 0**; two-ring **2**; fan **1**, excluded from legitimate totals. A
disagreement on the two-ring or the fan is **material new evidence** and routes to review before any
further work — it does not authorize a tie-break.

### L3 — dispatch and the arrival mode

Implement §5.3, including the `FaceInterior` / `EdgeTransit` arrival mode on
`resolve_field_vertex_transit`. **`FaceInterior` must be provably bit-identical to today's behaviour** —
author an identity that asserts it, not a comment that claims it.

### L4 — the invariance identities

Two identities, both falsifying rather than merely exercising:

1. **Scale invariance.** Multiply one face's published direction by a positive rational; assert the
   transit target is unchanged.
2. **Arrival symmetry.** Present the same grazing edge from both incident faces; assert the same
   endpoint is selected.

Without both, §5.2's freeze is unproven.

### L5 — the non-merging measurement

Non-gating: count, per grazing edge, how many candidate traces reach it. **Prediction: at most one on
every witness.** More than one is a typed observation and a return to review (§8).

### L6 — the transit record

Implement §5.6's `edgeTransitExit`, bind it into the trace digest, and author the identity that asserts
every transited segment publishes it with parameter exactly `0` or `1` and a `SourceVertexSupport`
projection equal to the vertex the trace continued from.

### L7 — accepted-prefix and CP4c-0-prefix migration

Re-run the accepted **316** unchanged; §7.1 predicts **316/316 with zero expectation edits**. Re-author
only the identities whose subject is the retired `BranchTransportFlowDisagreement` rejection (§7.2), and
**name every one of them explicitly in the CB8 report**. Freeze the new CP4c-0 identity count and
compute the gate as `338 + n`, minus any identity retired with its code. Report any other red with its
identity and first typed rejection and **stop**.

### L8 — the corrected K2

Re-author `cp4c_sphere_grazing_cost_census` to call `resolve_field_branch_continuation` and thread the
returned `exitPoint`, exactly as `field_aligned_candidate_traces` does (§2). It must publish, per trace:
traversed edges, transit count, first transit step, terminal kind, and terminal vertex. **Prediction:
every sphere trace now traverses more than one edge**, and the trace seeded at vertex `0` reaches edge
`6-8` at step **7**, matching G5's published history.

### L9 — prohibited in this turn

No A1 change of any kind. No new `FieldAlignedNetworkEventKind`. No A2b change. No `k ≥ 2` terminus
ordering. No torus or mechanical work. No change to the CP4c-1 318 selector. No new tolerance. No
threshold, cutoff, or magnitude test in §5.1 or §5.2. No runtime execution — CB8 compiles and packages
only.

---

## 11. Stop conditions for CP4c-0, extended

The DEFN §12 list stands. Added by this turn:

- a tolerance, threshold, or magnitude comparison enters the grazing classification or the slide
  predicate;
- the grazing relation is **stored** on A1 rather than derived from `direction`;
- `BranchGrazingSlideDirectionAmbiguous` fires on a legitimate witness and is answered by a tie-break
  rather than a review;
- more than one candidate trace reaches the same grazing edge (§8, L5) and is allowed to merge silently;
- an accepted identity outside §7.2's two authorized edits requires an expectation change;
- Q8 criterion 3 is weakened, deleted, or satisfied by relabelling a singularity termination as a
  contact;
- `FaceInterior` vertex-transit behaviour changes in any observable way.

---

## 12. Durable lessons

- **L-1 — a discrete model must be continuous across its own exact cases.** Amendment 3 already defined
  the exactly-tangent case. Any rule for the near-tangent neighbourhood that disagrees with it in the
  limit is wrong on structure alone, before any measurement. This is the argument that decided §4.1
  against a grazing terminus, and it needed no cost data.
- **L-2 — a diagnostic that reimplements a retired rule measures the retired rule.** K2 walked traces
  with the deleted Cartesian carrier lookup, died on the first `1×2` face, and reported `0/24` — which
  was then recorded as a limitation of the *model options*. Every non-gating census must either call the
  production entry point or state in its own published output which rule it implements.
- **L-3 — "the invariant fires 6–14 % of the time" was the shape of the answer, not the size of the
  problem.** The grazing edges turned out to be the mesh edges lying along the field's separatrices
  (§3.4). A high-incidence "violation" that clusters on the structures the stage exists to find is
  evidence the invariant is wrong, not that the input is bad. That reading is what separated §4.4 from
  §4.2.
- **L-4 — the exact quantity a rule needs is often already the published one.** The slide predicate
  looked like it needed a metric, unfolding, and a Filippov convex combination. It needed
  `d[index of edge.second()]`, because the published parameter *is* that barycentric coordinate
  (`SurfaceCellTracing.cpp:283-285`). Read the publication convention before importing geometry.

---

## 13. Accounting and exact successor

- accepted runtime authority: **M3 CP4ab 316/316**, run/job `32758293793 / 97530833220`
- current frozen CP4c-0 gate: **338**, SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; CB8 recomputes it as `338 + n` and freezes the count in its report
- CP4c-1 required selector: **318**, unchanged by this turn
- stable regression accounting: **42 / 14 / 28**, unchanged; produced-witness debt **5**; M3 packages **46**
- `M3-CP4c0-TB-R4-CAND-01` remains active / non-stable — the near-tangency regime is now **explained and
  defined**, so it is closable by CB8's L2 census rather than by further diagnosis
- **new candidate: `M3-CP4c0-DEFN2-CAND-01`** — K2's retired-rule walk (§2). Test-side, non-stable, no
  product impact, owned by measure L8. Stable totals unchanged and the reason is recorded.
- budgets: none; this planning turn executed nothing

**Exact next: `M3-CP4c-0-CB8`** — Code + Build only, runtime forbidden. Execute L0's preconditions,
obey every §11 stop condition, then L1–L9. Compile and package; execute nothing. Then
`M3-CP4c-0-TB-R8` on `338 + n`.

`M3-CP4c-1` remains open and blocked on CP4c-0, and now also owns the re-homed Q8 criterion 3 question
(§9.3). `M3-CP4c-2-DEFN` and `M3-CP4c-3-DEFN` remain blocked.
