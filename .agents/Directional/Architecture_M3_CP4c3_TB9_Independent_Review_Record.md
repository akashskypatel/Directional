# M3-CP4c-3-TB9 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB9-REV`
**Date:** 2026-09-02 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB9_Independent_Review_Plan.md`, measures **BC0–BC7**.
**Verdict:** TB9 is a **valid semantic red**. Ordinal 366 is classified **BC2 category 1 — a genuine product
ownership defect on a valid mechanical witness**. Exactly one bounded successor is frozen: **`M3-CP4c-3-CB12`**,
product correction, under **BD0–BD9**.

---

## 1. Executive adjudication

CB11 delivered. TB9's ordinal-366 line names one typed condition and carries full trace provenance, and the two-site
ambiguity `M3-CP4c-3-TB8-REV` proved is resolved to the singularity-termination site.

```
detailCode=InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2;
networkErrorCondition=SingularityTerminationPortOwnershipMismatch;
traceSeedVertex=47;traceSeedSingularity=5;traceHistoryCount=5;traceHistoryTruncated=false;
traceHistory=[{45,46,47},{43,44,45},{41,42,43},{39,40,41},{36,38,39}]  (all branch 2)
```

The review establishes four results.

1. **Of the guard's three subconditions, only one is reachable on the production path.** The
   `SingularityTerminationPortOwnershipMismatch` guard is a three-way disjunction. Both `VertexHit` constructions in
   `resolve_field_branch_continuation` derive the terminal vertex **from** `exitPoint->source_support()`, or build
   the boundary point at the exact parameter that `source_support()` maps back to that vertex. Therefore
   `vertexSupport` is never null and always equals `decision.sourceVertex`, and `terminalSingularity` is looked up
   **by that same vertex**. Disjuncts 1 and 3 are dead by construction. **Only `terminalPort == end()` can fire.**

2. **A missing port means exactly one thing.** `candidate.singularityPorts` is built over **all**
   `fieldTransportAtlas.singularities()`, and the single `continue` in that loop skips `portPolicy ==
   BarrierAbsorbed`; every `Emit` singularity receives `expectedValence ∈ [3,6]` ports. So a missing port is not an
   ordering, scope, or region artifact — **it is the `BarrierAbsorbed` policy, by design.**

3. **The witness is valid and the terminal vertex is v36.** `source_support()` maps parameter 0 → `edge.first()`
   and 1 → `edge.second()`, so the terminal vertex is v36 or v38. **v38's entire vertex star is coplanar** — all six
   incident faces lie in `x = -1.4` and every incident edge has an exactly 0° dihedral — so v38 is incident to no
   hard feature edge under any positive threshold, cannot be in `barrierVertices`, and cannot carry a
   `BarrierAbsorbed` singularity. The terminal vertex is **v36**.

4. **The defect is a category error about who owns an arrival.** A port records where a trace **originates**. The
   guard uses it to identify who owns a trace's **arrival**, and takes the terminal node from `terminalPort->node`.
   For a `BarrierAbsorbed` singularity there is deliberately no port — yet its node exists unconditionally
   (`nodeVertices.insert(singularity.sourceVertex)` runs **before** the policy check, and v36 is additionally a
   mandatory-barrier endpoint). The product therefore rejects a legitimate termination whose owner it has already
   constructed.

---

## 2. BC0 — immutable evidence re-established

Recomputed in this turn from committed bytes; no rebuilt binary or branch-head build product was used.

| Datum | Declared | Verified |
|---|---|---|
| semantic source | `803300698289e0d0f629eaa878add1aebc7193c1` | exists, `M3-CP4c-3-CB11: expose diagnostic finalizer seam`, 2026-09-02 00:06:06 +0000, ancestor of branch HEAD |
| selector 374 | `d496ce96…c503c4f` | LF-blob SHA-256 matches; 374 identities |
| selector 375 | `aa7b22bb…06a8f3a0` | LF-blob SHA-256 matches; 375 identities |
| execution selector 376 | `6ab2d9fa…6234bfa5e8` | LF-blob SHA-256 = `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`; 376 identities |
| ordinal 366 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | line 366 of selector 376 |
| ordinal 375 | `…FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries` | line 375 |
| ordinal 376 | `ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection` | line 376 |

Four results BC0 requires that the TB9 report does not itself assert:

- **376 is a strict one-line extension of 375.** The diff is exactly `375a376 >
  ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection`. CB11 appended and
  reordered nothing, so **374 and 375 remain byte-frozen through CB11** — BB6 honoured.
- **Accepted authority is still an exact prefix.** The first 365 lines of selector 376 are byte-identical to
  `Architecture_M3_CP4c2_Required_Green_Selector_365.txt`.
- **Selector 374's hash is unchanged across six consecutive turns** (CB9, TB7, TB7-REV, CB10, TB8, TB8-REV, CB11,
  TB9), and 375's across three.
- **The semantic source equals branch HEAD on every code surface.** `git diff 8033006 HEAD -- src include tests
  benchmarks CMakeLists.txt cmake` is empty, which is what licenses §3–§5 as evidence about immutable package 79.

Preflight/postflight, the 58-file census, and the eleven false control flags are accepted as reported; this turn
executes no runtime and adds no independent evidence there.

---

## 3. BC1 — reconstruction of the named site

### 3.1 The guard, as CB11 left it

`src/geometry/SurfaceCellTracing.cpp`, `append_field_aligned_singularity_termination`:

```cpp
const auto support = trace.terminalPoint->source_support();
const auto *vertexSupport = support.has_value()
    ? std::get_if<authority::SourceVertexSupport>(&*support) : nullptr;
const auto terminalPort = std::find_if(
    candidate.singularityPorts.begin(), candidate.singularityPorts.end(),
    [&](const FieldAlignedSingularityPort &port) {
      return port.singularity == *trace.terminalSingularity;
    });
if (vertexSupport == nullptr ||                                   // disjunct 1
    terminalPort == candidate.singularityPorts.end() ||           // disjunct 2
    terminalPort->sourceVertex != vertexSupport->vertex) {        // disjunct 3
  ... SingularityTerminationPortOwnershipMismatch ...
}
```

CB11 also split the function's first guard into its own condition,
`SingularityTerminationTraceIncomplete` — which independently confirms TB8-REV's elimination of that site, since TB9
reports the *other* condition.

### 3.2 Disjuncts 1 and 3 are dead on the production path

`FieldBoundaryPoint::source_support()` (`FieldTransportAtlas.h:601-610`) returns `SourceVertexSupport{edge.first()}`
at parameter 0, `SourceVertexSupport{edge.second()}` at parameter 1, and `SourceEdgeSupport` strictly between.

`trace.terminalSingularity` is set at exactly one place — the `VertexHit` branch of
`field_aligned_advance_trace_proposal`:

```cpp
proposal.terminalPoint = decision.exitPoint;
const auto *terminalSingularity = field_aligned_singularity_at(
    fieldTransportAtlas, *decision.sourceVertex, trace.sourceComponent, trace.sourceTopologyRegion);
if (terminalSingularity != nullptr) { proposal.disposition = TerminalSingularity; ... }
```

and `field_aligned_singularity_at` matches **by vertex**, so
`terminalSingularity->sourceVertex == *decision.sourceVertex`.

Both `VertexHit` constructions guarantee `terminalPoint.source_support()` is that same vertex:

- **`|M| = 1` (`:517-523`)** — it *derives* the vertex from the support: it returns `VertexHit` **only** when
  `exitPoint->source_support()` is a `SourceVertexSupport`, and sets `sourceVertex = vertexSupport->vertex`. The
  guard re-evaluates the identical expression on the identical value.
- **`|M| = 2` (`:546-556`)** — it constructs the point as `endpoint = (representative.first() == sharedVertex) ? 0 :
  1` and sets `sourceVertex = sharedVertex`. `source_support()` inverts that mapping exactly.

Hence `vertexSupport != nullptr` (**disjunct 1 dead**) and `vertexSupport->vertex == terminalSingularity->sourceVertex`.
Every port carries `singularity->sourceVertex`, so whenever a port with that singularity id exists,
`terminalPort->sourceVertex == vertexSupport->vertex` (**disjunct 3 dead**).

### 3.3 A missing port means `BarrierAbsorbed`, and nothing else

The port loop iterates **all** `fieldTransportAtlas.singularities()` — not a region- or component-filtered subset —
and contains exactly one `continue`:

```cpp
for (const authority::FieldSingularityFact *singularity : singularities) {
  if (singularity->portPolicy == BarrierAbsorbed) continue;
  const int expectedValence = 4 - singularity->indexNumerator;   // already proved ∈ [3,6]
  for (int ordinal = 0; ordinal < expectedValence; ++ordinal)
    candidate.singularityPorts.emplace_back(..., node->second, singularity->sourceVertex, ...);
}
```

The preceding filter rejects `expectedValence < 3 || > 6` with `InvalidSingularityBinding`, so every `Emit`
singularity gets at least three ports. **`terminalPort == end()` ⟺ `portPolicy == BarrierAbsorbed`.**

`BarrierAbsorbed` is assigned at `FieldTransportAtlas.cpp:2467-2470` iff the vertex is in
`slitCycleByGlobalVertex`, populated at `:2296-2300` iff

```
sourceMesh.isBoundaryVertex(v) == 0  ∧  local->barrierVertices.count(v) != 0  ∧  v is singular
```

and `:2428-2432` makes local-cycle and slit-cycle ownership an exclusive XOR over all singularities. The mechanical
mesh is **closed** (0 boundary edges), so on this witness **`BarrierAbsorbed` ⟺ singular ∧ barrier-incident**.

### 3.4 What TB9 therefore proves as runtime fact

Chaining §3.2 + §3.3 with the observed condition, without any re-derivation of the field:

- the mechanical trace reached a `VertexHit`;
- a singularity exists at that vertex (else the code would have taken `resolve_field_vertex_transit` instead);
- that singularity has **no ports**, hence `portPolicy == BarrierAbsorbed`, hence it is **barrier-incident**.

A second runtime fact falls out of the same reasoning applied to the four intermediate steps: vertices **45, 43, 41
and 39 are not singularities**, because both `resolve_field_vertex_transit` call sites check
`field_aligned_singularity_at` first and terminate the trace when a fact exists there.

### 3.5 The mechanical geometry

Computed directly from `benchmarks/fixtures/milestone-g/mechanical_feature.obj`:

- The five history faces are mesh rows **59, 57, 55, 53, 51** — all four vertices of each lie in the plane
  `x = -1.4`.
- The traversed vertex chain is **47 → 45 → 43 → 41 → 39 → 36**, exactly collinear along `(x = -1.4, z = -0.9)`
  with `y = 0.720, 0.432, 0.144, −0.144, −0.432, −0.780`. All five chain edges have a dihedral of **exactly
  90.000000°** — this is the sharp box edge where the `x = -1.4` face meets the `z = -0.9` face.
- **v38** `(-1.4, -0.432, -0.54)`: degree 6, **every incident edge has a 0° dihedral**, whole star coplanar.
- **v36** `(-1.4, -0.78, -0.9)`: degree 6, four non-coplanar incident edges — `(36,37)` at 91.302°, `(36,39)` at
  90.000°, `(36,96)` at 92.033°, `(36,97)` at 5.391° — the corner where the box silhouette meets the machined
  pocket. Angle defect 1.7658 (a chamfered corner).

v38 cannot be barrier-incident under any positive sharp-feature threshold, so by §3.4 the terminal vertex is
**v36**. Consistently, TB9's proof that v45/v43/v41/v39 are regular matches an independent reconstruction of the
singular support from the committed `.rawfield`, which flags v36 and v47 and not those four.

### 3.6 An adversarial check that changes the reading — and a caution

**v47 also has three exactly-90° incident edges** — `(45,47)`, `(46,47)`, `(47,73)` — yet TB9 proves v47 is an
`Emit` singularity, because a port trace originated there (`traceSeedVertex=47`, `traceSeedSingularity=5`; ports
exist only under `Emit`). So v47 is singular, non-boundary, and geometrically sharp, and is nonetheless **not** in
`local->barrierVertices`.

**Geometric sharpness is therefore not a valid proxy for the product's barrier set.** The operative restriction is
at `FieldTransportAtlas.cpp:962`: an edge becomes a barrier only when **both** its incident faces lie inside the
region being localized —

```cpp
if (firstFace >= 0 && secondFace >= 0 &&
    regionFaces.count(firstFace) != 0U && regionFaces.count(secondFace) != 0U) {
  barrierEdges.insert(edge); result.barrierVertices.insert(...);
}
```

A hard feature edge that *bounds* a region is not a barrier; a hard feature edge *interior* to a region is — which
is what "slit" names. v47's sharp edges are silhouette edges separating planar patches; v36 carries additional
non-silhouette sharp edges into the machined pocket. This does not disturb §3.4, which never depends on which edges
are barriers — only on the proved chain "no port ⟹ `BarrierAbsorbed` ⟹ barrier-incident". It is recorded because
the natural shortcut ("90° ⟹ barrier") is **false on this witness** and would mislead the successor.

---

## 4. BC2 — classification and ownership

**Classification: category 1 — a genuine product ownership defect on a valid mechanical witness.**

Category 2 is excluded: the witness is a closed manifold (`χ = 2`), the trace runs along an ordinary sharp feature
of the part from one singular corner to another, and every precondition the code states is satisfied — the terminal
point *is* a vertex, a singularity *is* there, and its port set is empty **because the atlas deliberately made it
empty**. Category 3 is excluded: CB11's diagnostics were sufficient, and §3.2–§3.3 identify the firing subcondition
from source structure alone.

**Owning authority and DTO.** `FieldAlignedSingularityPort` is the wrong authority for this decision.
`src/geometry/SurfaceCellTracing.cpp::append_field_aligned_singularity_termination` must resolve a termination's
owner through the singularity's **network node**, `candidate.nodes` / `nodeByVertex`.

**Invariant the current code violates**, stated positively:

> Every singularity has exactly one network node, allocated unconditionally, and that node owns **every** trace
> terminating at its source vertex. A singularity port identifies where a trace **originates** and constrains only
> the trace's own origin; it is never a precondition on an arrival. A singularity with `portPolicy ==
> BarrierAbsorbed` has no ports **by design** and must still be able to receive terminations.

Three facts in the same file establish that the node is the intended owner and is guaranteed to exist:

- `nodeVertices.insert(singularity.sourceVertex)` is executed for **every** singularity, **before** and outside the
  `portPolicy` test;
- v36 is additionally inserted by the mandatory-edge loop
  (`nodeVertices.insert(sourceEdge.first()); nodeVertices.insert(sourceEdge.second());`), so its node is a genuine,
  connected barrier endpoint rather than an orphan;
- `candidate.nodes` is materialized from `nodeVertices` **before** `candidate.singularityPorts` is built.

The guard reads `terminalPort->node` — i.e. it reaches the node it needs *through* a table that the atlas
deliberately left empty, when the node is directly available.

---

## 5. BC3 — CB11's diagnostic closure, without semantic acceptance

**`M3-CP4c3-TB8-REV-CAND-01` — CLOSED / RUNTIME PROVED.** Production ordinal 366 now carries the site
discriminator, `traceSeedVertex`/`traceSeedSingularity`, and five untruncated exact history rows; diagnostic 376
passes. The enum value `InvalidNetworkTerminalOwnership` and its name are preserved and the discriminator was added
as a field, exactly as BB2 required, so accepted ordinal 328 still asserts the code it always asserted. CB11 also
honoured BB7: its own test comments record that the finalize/contact fall-through is *deliberately* left
unrepaired.

**No inference is drawn about the unobserved site.** TB9 proves only that `finalize_field_aligned_events`' contact
fall-through is not the *first* mechanical failure at ordinal 366. The defect TB8-REV documented there —
`terminalContact` is never read in `:3745-3935`, so a contact-terminated trace is adjudicated by a loop-closure
rule belonging to a different terminal kind — is **untouched and still open**, and is not part of this successor.

**`publishedFaceCount` is gone and the absence is honest.** BB3 was discharged by making the renderer sparse; no
`publishedFaces` token at this failure now means an empty collection rather than an unassigned constant.

---

## 6. BC4 — independently owned report-only debt preserved

No evidence in this turn proves shared ownership with the ordinal-366 locus. All of the following are preserved and
are **not** folded into the successor:

- **368** — prescribed-sphere `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2 / event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`, under **AL4**.
- **369** — `certificate.saturationUsed=true`; the quality/coverage candidate remains active.
- **370** — genuine product-contract red: `CellularityNotEstablished` where `EmptyNetworkOnClosedSurface` is
  required, source-face locus still absent. **No correction authorized.**
- **373** — synthetic-only PASS; mechanical zero-unbound evidence still owed.
- **374** — pre-classified invalid folded-cone witness (`M3-CP4c3-TB7-CAND-02`). No atlas invariant may be weakened
  for it, and its repeat triggers no review.
- **`M3-CP4c3-DEFN-R2-CAND-01`** — **ACTIVE**; the general non-flat exact-fallback/budget path is still unreached.
- **`M3-CP4c3-TB6-CAND-01`** — **ACTIVE**; vertex 30 is still unreached, so the frozen row-209/row-208 owner
  election has no runtime acceptance and row 41 remains a prohibited result.
- **367 / 371 / 372** — blocked by the ordinal-366 locus; no independent conclusion, no separate candidate.

---

## 7. BC5 — regression and accounting reconciliation

`M3-CP4c3-TB8-CAND-01` advances from *two-site ambiguity* to **root cause established**: the
singularity-termination site, subcondition **missing port**, owned by the product, on a valid witness. It stays
**ACTIVE / GATING** and is re-owned to `M3-CP4c-3-CB12`.

One new candidate is opened:

- **`M3-CP4c3-TB9-REV-CAND-01`** — *a `BarrierAbsorbed` singularity cannot receive a trace termination, because the
  terminal owner is looked up in the port table the policy deliberately leaves empty.* **ACTIVE / GATING /
  PRODUCT / NON-STABLE.** Owner: **BD1–BD5** of `M3-CP4c-3-CB12`.

Dispositions confirmed: `M3-CP4c3-TB8-REV-CAND-01` **CLOSED**; `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB7-CAND-02` **ACTIVE**; the TB8-REV finalize/contact fall-through finding
remains open and unowned by this successor.

**Accounting.** Ordinals 1–365 remain green; TB9 loses no accepted behaviour and this review executes nothing.
**+0 stable events / +0 stable recurrences.** Totals remain **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 packages **76**.

---

## 8. BC6 — the single frozen successor: `M3-CP4c-3-CB12`

**Type:** Code + Build. **Product correction**, narrowly scoped to termination ownership at a `BarrierAbsorbed`
singularity. **Owner:** `src/geometry/SurfaceCellTracing.cpp::append_field_aligned_singularity_termination`.

### BD0 — preconditions
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Accepted 365 untouched. Selectors **374**
(`d496ce96…c503c4f`), **375** (`aa7b22bb…06a8f3a0`) and **376** (`6ab2d9fa…6234bfa5e8`) stay **byte-frozen** and
must republish with unchanged SHA-256. **GMP/GMPXX linkage is mandatory for every compile**
(`GMP_COMPILE_POLICY.md`). CB12 claims no acceptance.

### BD1 — restore the invariant
When the terminal singularity's `portPolicy` is `BarrierAbsorbed`, own the termination with **the singularity's
network node**, resolved from `candidate.nodes` by the terminal support vertex, and publish the same
`FirstContact` + `SingularityTermination` event pair the `Emit` path publishes. The `Emit` path is unchanged: it
still requires a matching port and still requires `terminalPort->sourceVertex == vertexSupport->vertex`.

### BD2 — carry the policy to the decision point
`append_field_aligned_singularity_termination` currently receives only `candidate` and `trace`, and cannot
distinguish "no port because `BarrierAbsorbed`" (legal) from "no port because the candidate is inconsistent"
(illegal). Make the policy available at the decision point — by threading the atlas or the singularity fact, or by
recording the policy on the candidate alongside the node. **Do not infer the policy from the port table's
emptiness**; that is the same conflation this defect is made of.

### BD3 — keep the existing condition correct and reachable
`SingularityTerminationPortOwnershipMismatch` **must not be deleted, renamed, or renumbered** — accepted ordinal
**328** asserts both it and `SingularityTerminationTraceIncomplete` by direct call
(`tests/FieldAlignedCurveNetworkTests.cpp:9568`, `:9660`). After BD1 it must still fire for an `Emit` singularity
whose port is missing or owns a different vertex. Add a distinct typed condition for a genuinely inconsistent
`BarrierAbsorbed` termination — a missing node for the support vertex — and fail closed there; never silently
accept.

### BD4 — witness the disjunct the production path actually reaches
Ordinal 328's port-ownership witness is **synthetic and exercises disjunct 3** (a port exists but owns
`mismatchedTerminalVertex`), which §3.2 proves the production `VertexHit` path can never reach. Add a witness for
the **missing-port / `BarrierAbsorbed`** disjunct, plus a positive witness that an `Emit` termination still
publishes its port-owned events unchanged. Preserve ordinal 328's existing assertions verbatim.

### BD5 — prove the mechanical precondition rather than assuming it
Demonstrate on the mechanical fixture that the terminal vertex is **v36**, that its singularity is
`BarrierAbsorbed`, and that after BD1 the termination publishes at v36's node. Report v36's node id and its
relationship to the mandatory barrier edges incident to it.

### BD6 — selector treatment
Append **selector 377** = selector 376 plus the new identities, **only** on demonstrated falsification — each new
identity must fail before the change and pass after. No reordering of any existing ordinal.

### BD7 — prohibitions
Do **not** convert the arrival into a barrier termination via `field_aligned_publish_barrier_termination` unless
shared ownership is independently proved — that is a different owner and a different event kind. Do **not** reorder
the `VertexHit` check relative to the `mandatoryByEdge` barrier check in
`field_aligned_advance_trace_proposal`. Do **not** synthesize a port for a `BarrierAbsorbed` singularity, weaken
`expectedValence`, or make the port table policy-blind. Do **not** repair the `finalize_field_aligned_events`
contact fall-through — it remains TB8-REV's open finding and a separate owner. No fixture mutation, no tolerance,
no float-derived topological decision, no sphere / ordinal-370 / saturation / folded-cone correction.

### BD8 — audit by assumption
For each of BD1–BD6 state the assumption and the evidence falsifying the nearest alternative. At minimum prove that
no accepted-green identity's observable output changes, and that the change cannot alter a termination owned by the
`Emit` policy or by a different site.

### BD9 — discriminators expected from the next artifact-only TB
`M3-CP4c-3-TB10` runs **selector 377 from ordinal 1**, artifact-only, on a fresh immutable package. Publish these
five in advance:

1. ordinals **1–365 remain 365/365** — the correction is confined to a path no accepted identity exercises;
2. ordinal 366 **no longer reports** `SingularityTerminationPortOwnershipMismatch` at `traceSeedVertex=47` /
   `traceSeedSingularity=5`; a repeat at that condition **and** that seed falsifies the correction outright;
3. if ordinal 366 still reds, it does so at a **different** condition, locus, or trace seed, and that becomes the
   next review's input;
4. the mechanical network publishes a `SingularityTermination` event at v36's node — observable through the
   existing terminal-event report;
5. `M3-CP4c3-TB9-REV-CAND-01` closes only on 1, 2 and 4 together.

**No vertex-30 discriminator is published.** The corrected path is *not* proved to reach vertex 30: v36's
termination retires one trace, and nothing in this review establishes that the remaining ports reach the
row-209/row-208 election. `M3-CP4c3-TB6-CAND-01` stays ACTIVE and row 41 remains prohibited rather than measured.

---

## 9. BC7 — adversarial assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review of the working tree describes package 79. | `git diff 8033006 HEAD` over `src include tests benchmarks CMakeLists.txt cmake` is empty; drift is directly excluded. |
| §3.2 | Only disjunct 2 is reachable. | Both `VertexHit` constructions derive the vertex from, or invert, `source_support()`; `field_aligned_singularity_at` matches by that same vertex. The alternative — a production path where support and singularity vertex differ — has no constructor. |
| §3.3 | A missing port means `BarrierAbsorbed`. | The port loop is over **all** atlas singularities with one `continue`, and `expectedValence ∈ [3,6]` is pre-enforced. Alternatives (region scoping, ordering, valence 0) are each excluded by a named check. |
| §3.3 | The witness is closed, so the boundary clause of `:2296` is vacuous. | 0 boundary edges, `V − E + F = 2`, recomputed from the fixture. |
| §3.5 | The terminal vertex is v36, not v38. | v38's entire star is coplanar — every incident dihedral is exactly 0° — so it is barrier-incident under no positive threshold and cannot be `BarrierAbsorbed`. |
| **§3.6** | **Adversarial:** does sharpness identify the barrier set? | **No — falsified.** v47 has three exactly-90° incident edges and is proved `Emit` by TB9's own trace seed. The operative restriction is the both-faces-in-region test at `FieldTransportAtlas.cpp:962`. §3.4 is independent of this and survives. |
| **BC7 positive case** | An `Emit` termination must keep working. | Singularity **5 at v47** is `Emit` with ports — TB9 shows a trace originating from one. BD1 leaves that path untouched. |
| **BC7 boundary case** | The accepted witness already covers the guard. | **It does not.** Ordinal 328's port-ownership witness is synthetic and exercises **disjunct 3**, which §3.2 proves the production path cannot reach. Hence BD4. |
| BD1 | v36's node exists before ports are built. | `nodeVertices.insert(singularity.sourceVertex)` is unconditional and precedes the policy test; the mandatory-edge loop inserts both endpoints of every barrier edge; `candidate.nodes` is materialized before `candidate.singularityPorts`. |
| BD9 | Ordinal 366 will move. | The correction changes exactly the branch TB9 fired. If the same condition and seed recur, BD1 did not land. |

---

## 10. Lessons

- **81 (new).** *An origin credential is not an arrival credential.* A singularity **port** says where a trace may
  start; a singularity **node** says what a trace may end at. The product allocated the node unconditionally and
  the port conditionally, then asked the port a question only the node can answer — so a policy that exists
  precisely to suppress ports (`BarrierAbsorbed`) made a legitimate arrival unrepresentable. When two tables model
  the same entity at different cardinalities, check which one the question is actually about.
- **82 (new).** *A reachability witness proves the name, not the branch.* CB11 was asked to demonstrate that each
  emission site is reachable, and it did — but through the one subcondition the production path cannot reach. A
  witness that reaches a typed condition by *any* route satisfies "reachable" while telling you nothing about which
  route production takes. When a condition is a disjunction, the witness obligation is per-disjunct.
- **83 (new).** *Geometry is not authority.* Every edge of the traced chain has an exactly 90° dihedral, and the
  natural inference — sharp implies barrier — is false here: v47 is equally sharp and emits ports. The product's
  barrier set is region-restricted, and only the source predicate decides. Reconstructing a fixture is useful for
  *locating* a failure and worthless for *adjudicating* one.
- **Confirmed (lesson 79).** Adding the discriminator as a **field** rather than splitting the enum was the right
  call: accepted ordinal 328 still asserts `InvalidNetworkTerminalOwnership` unchanged, and TB9 still named the
  site. The pattern is reusable for every multi-site code.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB12`** under **BD0–BD9**.
