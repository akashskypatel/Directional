# M3-CP4c-0-TB — Independent Review and Corrective Plan

Turn: `M3-CP4c-0-TB-REVIEW-PLAN`. Review and planning only.
Reviewer scope: inspect immutable evidence and source; amend frozen definitions; author the next
Code + Build plan. **No product source, test source, fixture, selector, build configuration, or runtime
was modified or executed in this turn.**

Governing brief: `Architecture_M3_CP4c0_TB_Review_Plan.md`.
Frozen contract under review: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`.
Evidence under review: `Architecture_M3_CP4c0_Artifact_Only_Test_Benchmark_Report.md`.

---

## 0. Verdict, stated first

**The failure is not in T6, and it is not in Q8. Both frozen contracts are correct and neither is
weakened.** The defect is upstream of both, and it is **mine** — it is in the frozen definitions this
review agent authored in `M3-CP4c-0-DEFN`.

The root cause, stated once:

> **A1 decides the sign of a barycentric direction coordinate with a `double` tolerance, in three
> separate places, and publishes those tolerant verdicts as topological ownership. A2a's new
> continuation rule decides the sign of the *same* coordinate exactly. Where the two disagree — the
> band `|d_i| ≤ 1e-10`, and the reconstruction error of a barycentric→world→barycentric round trip —
> A1 hands A2a a state that A2a is correct to reject.**

`BranchContinuationDegenerateEntry` at `sourceEdge=6-8` is A2a **correctly** refusing an ill-formed
state that A1 was **incorrectly** allowed to produce. T6 is behaving exactly as frozen: it is a
fail-closed invariant assertion, and the invariant genuinely was violated.

DEFN §4.3 and §4.4 asserted that the surviving tolerance was harmless. **That assertion is false**, and
§8 below proves it false. §9 issues the normative amendment. §10 issues corrective measures **E0–E10**
for one Code + Build turn.

After E2 + E3, T6 becomes **provably unreachable from any well-formed production state** (§7,
Theorems 1–3). That is the correct resolution of the T6/Q8 conflict: T6 keeps its exact wording and
keeps firing on invariant violation; Q8 keeps its 24 traces, its terminal `TraceIntersection`, and its
crossover; the conflict dissolves because the states that triggered it stop being produced.

---

## 1. Independent verification of the evidence — CONFIRMED

Every claim in the TB report that this review depends on was re-verified against the GitHub REST API
during this turn, not taken from the report.

| Claim | Source of truth | Verified |
|---|---|---|
| run `32891161394`, `run_attempt=1`, conclusion `failure` | `actions_get/get_workflow_run` | ✅ |
| head SHA `9779f2233eafc716ae4dd7e0dce0c484fe7b68a9` | same | ✅ |
| result artifact `9579600371` SHA-256 `fe472587aba74c2face26a2f65c0706439232bec2e5cc594d81711a26773b399` | `actions_list/list_workflow_run_artifacts` | ✅ exact match |
| log artifact `9579600958` SHA-256 `7ddfe4c8e48b1b618c7a60ad6cf900a767ff954309a1c3cc52a8896306d98039` | same | ✅ exact match |
| schema-validation job `97943166744` PASS | `actions_list/list_workflow_jobs` | ✅ `success` |
| TB job `97943220460` | same | ✅ present, `failure` |
| retry-0 run `32890863928` at SHA `2ceb90e4…` is pre-semantic | job `97942277296` | ✅ see below |

**Two findings that strengthen the report beyond what it claimed.**

1. **The TB job's own step ledger corroborates "valid red, not infrastructure".** In job
   `97943220460`, step 4 `Execute frozen TB plan` **succeeded** (19:43:29 → 19:47:01, 3 m 32 s), step 5
   `Upload TB result evidence` succeeded, step 7 `Upload TB diagnostic log` succeeded, and the *only*
   failing step is step 8, `Fail closed on red gate or Q8`. The workload ran to completion and the
   deliberate gate tripped. This is independent, structural confirmation.
2. **Retry 0 is confirmed pre-semantic by wall clock, not by assertion.** In job `97942277296`, step 4
   failed after **12 seconds** (19:40:30 → 19:40:42) and step 5 `Upload TB result evidence` also
   failed. Twelve seconds cannot contain a 328-identity one-process-per-identity gate, whose
   successful execution took 212 seconds. Retry 0 carries zero semantic evidence. **Confirmed.**

Artifact-only integrity, the 328/328 gate, the 316-prefix hash `601ce2b6…`, and the selector hash
`cf93622e…` are accepted as reported. **The TB turn's characterization of its own run is accurate in
every particular this review could independently check.** That is worth stating plainly.

**Consequence that must not be lost:** D3's accepted-prefix non-regression obligation is now
*runtime-proved*. The Cartesian `connections` defect diagnosed in `M3-CP4c-1-TB-R2-REVIEW-PLAN` is
genuinely fixed, and all twelve CP4c-0 falsifiers are green. CP4c-0's implementation is not being
reverted; it is being **completed**.

---

## 2. R1 — reconstruction of the exact zero-time state

### 2.1 What the published payload actually means — and one field of it is misleading

Observed: `networkError=BranchContinuationDegenerateEntry`, `sourceVertex=0`, `sourceEdge=6-8`,
`singularity=0`.

Read the emission path in source.

`src/geometry/SurfaceCellTracing.cpp:451-456` — the T6 site:

```cpp
  const auto time = (*entryBarycentric)[firstMinimizer] /
                    (-pairing.direction[firstMinimizer]);
  if (time == zero) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry,
        sourceFace, pairing.branch, entryPoint.edge, std::nullopt,
        entryPoint.parameter, std::vector<authority::FieldExactRational>{time});
  }
```

The fifth argument — `sourceVertex` — is **`std::nullopt` at this site**. So the `sourceVertex=0` in
the report did **not** come from the failure. It came from the caller,
`src/geometry/SurfaceCellTracing.cpp:816-820`:

```cpp
      if (auto *error =
              std::get_if<FieldAlignedCurveNetworkError>(&continuation)) {
        if (!error->sourceVertex.has_value()) error->sourceVertex = port.sourceVertex;
        if (!error->singularity.has_value()) error->singularity = port.singularity;
        return *error;
      }
```

`port.sourceVertex` and `port.singularity` are the **seed** of the trace, not the site of the failure.

**Therefore: `sourceVertex=0` and `singularity=0` together carry exactly one bit of information — the
failing trace is one of the traces seeded at singularity 0 / vertex 0. They say nothing whatsoever
about where it failed.** This is a defect in its own right (measure **E1c**): back-filling a locus
field with a seed identifier makes a diagnostic actively misleading. It is the reason both the TB turn
and this review initially spent effort on vertex 0.

`sourceEdge=6-8` **is** genuine: it is `entryPoint.edge`.

### 2.2 What the runtime computed and threw away

`continuation_error` (`:217-236`) populates `sourceFace`, `branch`, `parameter`, `exactValues`, and
`publishedEdges`. CB1 **did** implement DEFN §10's required loci for this code — that obligation was
met in production.

They are lost in the **witness diagnostic emitter**, `tests/FieldAlignedCurveNetworkTests.cpp`,
`append_network_error`:

```cpp
  stream << "fieldAlignedCurveNetwork=false"
         << ";networkError=" << ...error_code_name(error.code);
  if (error.sourceVertex.has_value()) { stream << ";sourceVertex=" << ...; }
  if (error.sourceEdge.has_value())   { stream << ";sourceEdge=" << ...; }
  if (error.rail.has_value())         { stream << ";rail=" << ...; }
  if (error.singularity.has_value())  { stream << ";singularity=" << ...; }
```

It prints four fields, and `sourceFace`, `parameter`, `exactValues`, and `publishedEdges` are not
among them. The sibling emitter `append_plan_error` in the same file *does* print `sourceFace` via
`source_face_locus`, so the helper already exists.

**Adjudication.** The evidence gap the TB report correctly flagged is real, is exactly one function
wide, and is in **test/diagnostic source**, not production. It is repaired by measure **E1**. The TB
turn could not have repaired it — TB may not edit test source. It was correct to stop and escalate.

### 2.3 The state, reconstructed as far as evidence permits

Established from source with certainty:

- `entryPoint.parameter ∈ [0,1]` — the out-of-range guard at `:377-382` did not fire.
- `entryPoint.edge = 6-8` and it **is** an edge of the failing face — the
  `BoundaryPointEdgeNotIncidentToFace` guard at `:385-389` did not fire.
- `pairing.direction.is_barycentric()` held — the `:411-420` guards did not fire. So
  `Σ d_i = 0` exactly and `d ≠ 0`.
- Therefore `|N| ∈ {1, 2}`, and `|M| ∈ {1, 2}`. `T4` and `T5` did not fire and **cannot** (§6.3).
- `t* = 0` exactly, so `p_{i*} = 0` exactly for the first minimizer `i*`.
- The failure is **not** the trace's first step. The first entry point is
  `field_boundary_point_at_vertex(startFace, port.sourceVertex)` (`:781-782`), whose edge is incident
  to vertex 0. Edge `6-8` is not incident to vertex 0. **The trace advanced at least one step.**

**Not established, because the runtime did not publish it:** the failing `sourceFace`, the branch, the
exact `entryPoint.parameter`, the exact `d`, and the predecessor transition kind.

**`p_{i*} = 0` admits exactly three routes, and the entry parameter alone separates them.** This is
why §2.2 matters so much: the one datum that discriminates was computed and discarded.

| Route | Predecessor | Entry parameter | Mechanism |
|---|---|---|---|
| **A** | `EdgeExit` across `6-8` | strictly interior | The entered face's `d[opp(6-8)] < 0` — the direction points back out through the edge it just crossed. A **cross-face flow disagreement**. |
| **A′** | `EdgeExit` across `6-8` | strictly interior | Same sign, but `|d[opp(6-8)]| ≤ 1e-10`, so A1 classified `6-8` as `Tangent` in the entered face while the exact sign is negative. A **within-face tolerance disagreement**. |
| **B** | `VertexHit` → `resolve_field_vertex_transit` | exactly `0` or `1` | The entry is at a vertex (`bary = (1,0,0)`); the tolerant sector rule selected a face the direction does not exactly enter. A **sector-selection tolerance disagreement**. |

Route B is topologically admissible for `6-8`: `field_boundary_point_at_vertex` names the vertex by the
sorted-first incident edge, so a transit at vertex 8 in any face `(6,8,x)` with `x > 6`, or at vertex 6
in any face `(6,8,x)` with `x > 8`, yields exactly `entryPoint.edge = 6-8`.

**R1 answer: the route is not decidable from the published evidence.** This review does not guess it —
and, decisively, **it does not need to**, because §3 shows all three routes are instances of one root
cause with one fix.

---

## 3. R2 — adjudication of T6

The brief offered four verdicts. **The verdict is (3): a state that should never have been produced.**

Not (1): the state genuinely is invalid — a continuation with `t* = 0` is a trace that enters and
leaves at the same point, which is not a trace.
Not (2): the state is not a valid continuation in a form T6 mis-rejects. Every route in §2.3 is a
genuine violation of the model in DEFN §4.1.
Not (4): the *route* is undecidable, but the *class* is decided, because all three routes share one
antecedent.

**The shared antecedent.** Write `sgn₀(x)` for the exact sign of a `FieldExactRational` and `sgnτ(x)`
for the tolerant verdict `x > τ ? + : (x < −τ ? − : 0)` with `τ = 1e-10`. Then:

- Route A′ is `sgnτ(d_i) = 0` while `sgn₀(d_i) = −`.
- Route B is `sgnτ(β) ≥ 0` (via `beta >= -tol`) while `sgn₀(d_prev) = −`.
- Route A is the same disagreement carried **across an edge**: face `X` says outflow, face `Y` does not
  say inflow, and nothing asserts the two agree.

In every route, **a coordinate of the exact published direction is negative while a tolerant consumer
of that same direction treated it as non-negative.** T6 then evaluates it exactly and is right to
reject.

**T6 is not amended. Its wording, its code, and its fail-closed disposition all stand.** What changes is
that the states reaching it stop existing.

---

## 4. R3 — the exact-versus-tolerant boundary, proved algebraically

The brief asked whether A1's sector rule and A2a's exact ordering can disagree at a vertex. They can,
and the disagreement is not incidental — **they are the same predicate at two precisions**. Here is the
proof, which requires no runtime and no geometry beyond linear algebra.

### 4.1 The sector rule is a sign test on the barycentric direction

`src/authority/FieldTransportAtlas.cpp:399-423`, `direction_in_incident_vertex_sector`, with origin at
vertex `v`, `a = V[next] − V[v]`, `b = V[prev] − V[v]`, solves the 2×2 Gram system for `(α, β)` with
`direction ≈ α·a + β·b`, and returns

```cpp
  // Half-open at the fan rays: include the next-vertex ray, exclude previous.
  return alpha > kBranchTopologyTolerance &&
         beta >= -kBranchTopologyTolerance;
```

Displacing from `v` by `α·a + β·b` changes barycentric coordinates by exactly

```
    Δbary[next] = α ,   Δbary[prev] = β ,   Δbary[v] = −α − β .
```

So **`α` is `d[next]` and `β` is `d[prev]`**, and the sector test is literally

```
    d[next] > τ    ∧    d[prev] ≥ −τ .
```

### 4.2 The exact continuation demands the same predicate with τ = 0

At a vertex entry the barycentric position is `p[v] = 1`, `p[next] = p[prev] = 0`. `t* > 0` requires no
index of `N = {i : d_i < 0}` to have `p_i = 0`, i.e. requires

```
    d[next] ≥ 0    ∧    d[prev] ≥ 0 .
```

### 4.3 The two disagree in two bands, and both are reachable

| Band | Sector rule | Exact rule | Consequence |
|---|---|---|---|
| `d[prev] ∈ [−τ, 0)` | **admits** | rejects | face selected; **`t* = 0` → `BranchContinuationDegenerateEntry`** — the observed failure, route B |
| `d[next] ∈ (0, τ]` | **rejects** | admits | the true face is dropped; if no other face is admitted → `VertexTransitSectorUnresolved`; if one other is → **silently wrong face** |

**This is not a hypothetical band.** DEFN §4.4 claimed the half-open convention "is a **partition** of
the vertex fan: every direction lands in exactly one sector". With `τ > 0` that is arithmetically
false: `α > τ ∧ β ≥ −τ` neither partitions nor covers. It over-admits on the `β` side and
under-admits on the `α` side. A true partition is `α > 0 ∧ β ≥ 0`, which is the τ = 0 case and nothing
else. **The claim in §4.4 is my error and §9 retracts it.**

### 4.4 The disagreement is amplified by a lossy round trip — a second, independent defect

There are **three** independent `double` computations of the same barycentric derivative in the live
path:

| # | Site | Basis | Input direction | Product |
|---|---|---|---|---|
| S1 | `build_boundary_pairing` `FieldTransportAtlas.cpp:102-135` | `(p1−p0, p2−p0)` in canonical topology order | `canonicalDirections[b]` | `dbary`, promoted by `from_double_exact` to **`pairing.direction`** |
| S2 | singularity port attachment `FieldTransportAtlas.cpp:546` | `(V[next]−V[v], V[prev]−V[v])` in **mesh-row corner order** | `canonicalDirections[b]` | `startFace`, `firstOutgoingCarrier` |
| S3 | `resolve_field_vertex_transit` `SurfaceCellTracing.cpp:559-565` | same as S2 | **`field_branch_world_direction(...)`** | `nextFace`, `nextBranch` |

S1 is *exact-preserving*: `FieldExactRational::from_double_exact(u)` is the bit-exact rational value of
the `double`, so `sgn₀(pairing.direction[i]) = sgn(dbary[i])` with no loss. **`pairing.direction` is the
`double` computation, losslessly recorded.** That is the crucial structural fact: A2a is not using a
"more accurate" number than A1 — it is using *A1's own number*, and only the *comparison* differs.

S3 is the pathological one. `field_branch_world_direction` (`SurfaceCellTracing.cpp:336-357`) rebuilds a
world vector as `Σ_i d_i · V_i` where `Σ d_i = 0` — a **cancelling** sum, evaluated after
`to_double(18)`. S3 then re-solves a different 2×2 Gram system in a different basis to recover `α, β`.

**So S3 answers "is `d[prev]` negative?" by converting `d` to `double`, taking a catastrophically
cancelling weighted sum of vertex positions, and least-squares-solving back — then comparing the result
to `1e-10`. The exact answer is sitting in `pairing.direction[prev]` the whole time.** Near zero, S3's
sign is not merely tolerance-limited; it is reconstruction-noise-limited.

**R3 answer: yes, they can disagree, the disagreement is exactly characterized by §4.3's two bands, and
S3 widens the `β` band well past `τ`. This is the strongest single candidate for the observed failure,
and it is repaired without inventing any new rule or tolerance — by evaluating the existing rule
exactly on the direction A1 already publishes.**

---

## 5. R4 — entry-position and branch propagation audit

Three producers of `currentEntryPoint`, audited in source.

**P1 — trace start** (`:781-787`). `field_boundary_point_at_vertex(attachment->startFace,
port.sourceVertex)`. `startFace` was chosen by **S2**, the tolerant sector rule (`:546`). The `β` band
therefore applies at step 0 as well. A mis-selection here surfaces either as `t* = 0` (T6) or, via the
`:825-831` guard, as `InvalidCandidateTraceTransport` when `decision.outgoingCarrier !=
attachment->firstOutgoingCarrier`. **The trace start is exposed to the identical seam and must be fixed
with the same measure.**

**P2 — edge exit** (`:918`). `currentEntryPoint = decision.exitPoint`, carried into `*nextFace` with
`nextBranch = currentBranch.rotated(directed->signedLift)`.

> **Unasserted cross-face invariant.** Nothing in the loop checks that `decision.outgoingCarrier` is an
> **incoming** carrier of the destination pairing. A1 classifies each face's flows from *that face's own*
> `dbary`; no invariant ties `sgn(d_X[opp_X(e)])` to `−sgn(d_Y[opp_Y(e)])` across a shared edge `e`.
> When they disagree, `p[opp(e)] = 0` and `d[opp(e)] < 0` give `t* = 0` — route A, reported as
> `BranchContinuationDegenerateEntry` with no indication that a *transport* invariant broke.
> **Measure E5** converts this into its own typed rejection naming both faces, both branches, and both
> exact derivatives.

**P3 — vertex transit** (`:864-878`). `field_boundary_point_at_vertex(vertexTransit.nextFace,
*decision.sourceVertex)`, with `incomingCarrier.reset()` and `entryTransport.reset()`. `nextFace` came
from **S3**. This is route B, in full.

> **Representation note.** `field_boundary_point_at_vertex` (`:291-309`) encodes "at vertex `v`" by
> picking the **sorted-first** incident edge and setting the parameter to `0` or `1`. The edge is an
> arbitrary naming choice, not a locus. This is precisely why `sourceEdge=6-8` cannot, by itself,
> distinguish route B from routes A/A′. The parameter — `0` or `1` versus interior — is the
> discriminator, and E1 publishes it.

**Two further defects found during this audit, neither caused by CB1, both now load-bearing.**

**D-a — T1's dispatch is not exhaustive over the exact model.** DEFN §4.4 sends every `|M| = 1` case to
`EdgeExit`. But when some `d_k = 0` exactly and `p_k = 0` at entry, coordinate `k` stays zero for all
`t`, and the `|M| = 1` exit lands **exactly on a vertex** — `exitPoint.parameter ∈ {0, 1}`. The code at
`:482-493` publishes that as an `EdgeExit` anyway. The next face then receives a vertex entry with two
zero coordinates through the *edge* path, which is exactly the degenerate configuration T6 catches.
`VertexHit` is currently produced **only** by the `|M| = 2` tie, so this vertex landing is invisible to
T2/T3. Narrow, but it is a genuine exhaustiveness hole in the frozen dispatch. **Measure E4.**

**D-b — the cycle guard is position-blind and is now unsound as a terminus rule.** The `visited` set
(`:789-796`, `:905-911`) keys on `(sourceFace, branch, incomingCarrier)`. Before CP4c-0 that was
complete, because position did not exist. **Under D0 it is not**: the whole point of CP4c-0 is that the
same `(face, branch, incoming edge)` can be re-entered at a *different exact parameter* and continue
legitimately. Today such a re-entry is silently truncated at `:908-911`, which sets `terminalPoint` and
`break`s — publishing a **spurious clean terminus**. This directly threatens Q8's `24 traces` and its
terminal-`TraceIntersection` requirement. **Measure E6.** Termination must not be re-derived from the
position-blind key: it needs an explicit, typed, bounded rule, and a trace stopped by that bound must
not be published as a clean terminus.

---

## 6. R5 — witness and oracle validity

Separated as the brief requires, and kept separate deliberately.

| Layer | Finding |
|---|---|
| **Intended contract** | `DESIGN.md` §4.5/§7.2: a field-aligned trace leaves a singularity, crosses faces along a constant per-face direction, and terminates at a barrier, a singularity, or another trace. |
| **Actual fixture state** | The prescribed sphere reaches `sourceEuler=2`, `sourceGenus=0`, `sourceBoundaryLoopCount=0`, `sourceTopologyRegionCount=1`, `interiorLocalVertices=98`, `fieldTransportAtlas=true`. **The fixture is structurally sound and reaches A2a.** |
| **Required preconditions** | A1 must publish a coherent atlas — it did. A2a must receive well-formed entry states — **it did not**. |
| **Implementation result** | 328/328 gate green; sphere blocked at T6. |
| **Q8 oracle** | 24 traces, ≥1 terminal `TraceIntersection`, face `1-2-5` / incoming `1-2` resolving into `{1-5, 2-5}` with the frozen crossover flip. |

**R5 answer: the fixture is valid, the oracle is valid, and neither is touched.** There is no
structural reason the prescribed sphere cannot exercise the intended behaviour; it is blocked by a
production defect, which is precisely the situation in which a fixture must **not** be edited. Q8 is
not weakened, not narrowed, and not made conditional. No sphere-specific branch, edge, face, or index
special case is authorized, now or later.

**Q8 additionally cannot be credited until E6 lands**, because a position-blind truncation can change
the published trace count and manufacture a terminus. A green Q8 obtained over D-b would not be
trustworthy evidence.

---

## 7. Why the corrective measures are sufficient — three theorems

These are the guarantees the successor turn must reproduce as identities. They are stated so the
implementation agent can check its work against a proof rather than against a hope.

**Theorem 1 (T2/T6 non-interference).** Let the vertex-continuation face `F` at vertex `v` be selected
by the **exact** predicate `d_F[next] > 0 ∧ d_F[prev] ≥ 0`. Then the vertex entry point in `F` has
`N = {v}`, `|M| = 1`, and `t* = 1/(−d_F[v]) > 0`.
*Proof.* `Σ d = 0` and `d[next] > 0`, `d[prev] ≥ 0` give `d[v] = −(d[next] + d[prev]) < 0`. Hence
`N = {i : d_i < 0} = {v}`, so `|M| = 1` and `t* = p_v/(−d_v) = 1/(−d_v) > 0`. ∎
**Corollary: T6 cannot fire on any entry produced by T2 or by the trace start.**

**Theorem 2 (outflow-set closure).** Under the exact flow classification of E2, `d[v] < 0` is
*definitionally* "the edge opposite `v` is an outgoing carrier". Combined with Theorem 1, the exit edge
of a vertex-originated step is in `outgoingCarriers` by construction.
**Corollary: `BranchContinuationOutsideOutflowSet` cannot fire on a T2-produced entry**, and A1's
existing check at `FieldTransportAtlas.cpp:550` becomes a tautology rather than a tolerance-dependent
hazard.

**Theorem 3 (edge-entry non-degeneracy).** If the entry edge `e` has a strictly interior parameter and
is in the entered face's `incomingCarriers` under E2's exact classification, then `d[opp(e)] > 0`, so
`opp(e) ∉ N`; and `opp(e)` is the *only* zero coordinate of an interior edge entry. Hence every
`i ∈ N` has `p_i > 0`, so `t* > 0`.
**Corollary: T6 cannot fire on an interior edge entry through a genuine incoming carrier.** The
remaining hole — `e` not being an incoming carrier of the entered face — is exactly what E5 asserts and
types.

**Together: after E2, E3, E4 and E5, `BranchContinuationDegenerateEntry` is unreachable from any
well-formed production state.** It retains exactly the role DEFN §4.4 assigned it — a fail-closed
assertion that fires only when an invariant has been violated — and the twelve CP4c-0 falsifiers that
reach it through constructed inputs stay green.

---

## 8. Reachability audit of the frozen dispatch — three branches are dead from production

`FieldBranchDirection::is_barycentric()`
(`include/directional/authority/FieldTransportAtlas.h:438-444`) requires `Σ d_i = 0` **and** `d ≠ 0`.
Under that invariant, `|N| ∈ {1, 2}` always. Therefore:

| Frozen case | Code | Production reachability |
|---|---|---|
| **T4** `\|M\| = 3` | `BranchContinuationMinimizerImpossible` | **Unreachable** — needs `\|N\| = 3`, impossible with `Σ d = 0`, `d ≠ 0`. |
| **T5** `N = ∅` | `BranchContinuationNoOutflow` | **Unreachable** — `N = ∅ ∧ d ≠ 0 ∧ Σ d = 0` is contradictory. |
| `\|M\| > 2` (`:436`) | `BranchContinuationMinimizerImpossible` | **Unreachable** — `\|M\| ≤ \|N\| ≤ 2`. |

This is **not a defect** — DEFN §4.4 already predicted T4 and T5 would be unreachable, and fail-closed
assertions on impossible states are correct engineering. It **is** a documentation obligation
(measure **E7**): each must carry a written note that its falsifier is a unit-level identity over a
tampered direction and that it proves nothing about production coverage. Without that note, three of
the twelve green CP4c-0 identities could later be miscredited as production evidence. `LESSONS.md`
already records what miscredited coverage costs.

---

## 9. Normative amendment to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`

Issued under the reviewer's authority to correct frozen definitions found inconsistent. **This
supersedes the cited text; the rest of the DEFN stands unchanged.**

### Amendment 1 — §4.3, retraction of the tolerance-harmlessness claim

The frozen paragraph reads: *"The one tolerance that remains is the pre-existing
`kBranchTopologyTolerance` used to classify an edge as Tangent during A1's flow classification. That
decides admissibility of the frame, which §6.3 permits, and it is unchanged by this DEFN."*

**Retracted. It is false.** That tolerance does not only decide admissibility: its verdict *is*
`incomingCarriers` / `outgoingCarriers` membership, and `outgoingCarriers` membership gates which edge
a trace may exit through (`BranchContinuationOutsideOutflowSet`). It is therefore a
**tolerance-derived value used as an ownership key**, which `DESIGN.md` §6.3 forbids.

**Replacement, normative:** every decision on the **sign of a coordinate of `pairing.direction`** — flow
classification, carrier-set membership, vertex-sector membership, candidate-set `N`, minimizer set `M`,
and exit time — is taken **exactly, on `pairing.direction`, against exact zero**. `Tangent` means
`d_i == 0` exactly. `kBranchTopologyTolerance` is **retained unchanged** for genuine admissibility
guards that are not sign-of-`d` decisions (degenerate Gram determinant, non-finite input). It is not
retuned, not removed, and no new tolerance is introduced.

### Amendment 2 — §4.4, T2's sector rule

The frozen note reads: *"Note that helper's half-open convention (`alpha > tol && beta >= -tol`) is a
**partition** of the vertex fan…"*

**Retracted.** With `τ > 0` the predicate `α > τ ∧ β ≥ −τ` is neither a partition nor a cover of the
fan (§4.3 above). Only `α > 0 ∧ β ≥ 0` is.

**Replacement, normative:** T2 continues to use **one** sector rule and A1 remains its single writer.
That rule is **`direction_in_vertex_sector`, exactified**: for face `F` with mesh-row corner successor
`next` and predecessor `prev` at vertex `v`, `F` is admitted **iff**

```
    d_F[next] > 0    ∧    d_F[prev] ≥ 0     (exact, on pairing.direction)
```

with `d_F[·]` indexed **by vertex identity** — locate each vertex's position within
`sourceFace.vertices()` — never by corner position, because `SourceFaceTopologyKey` is canonically
ordered and need not match the mesh row.

This is the **same** rule with the **same** half-open convention (include the next-vertex ray, exclude
the previous-vertex ray) evaluated at `τ = 0`. It is **not** a second sector rule: the
`Eigen::Vector3d` overload is **deleted**, leaving exactly one. It introduces **no** new tolerance; it
removes one. Both constraints of review question R3 are satisfied.

### Amendment 3 — §4.4, T1 exhaustiveness

**Added, normative:** T1 (`|M| = 1`, `t* > 0`) applies **only** when the exit parameter is strictly
interior. If the exit parameter is exactly `0` or `1`, the exit lies on a vertex and **must** dispatch
to T2 or T3 by that vertex's singularity status, identically to the `|M| = 2` case. `VertexHit` and
`EdgeExit` must never both be able to represent the same geometric event.

### Amendment 4 — §9 ownership table

**Added, normative:** *cross-edge flow agreement* is a published invariant of **A1**, asserted at the
point of use by A2a. For an edge `e` shared by faces `X` and `Y` with branches related by the Z4 lift,
`e ∈ outgoingCarriers(X, b)` **requires** `e ∈ incomingCarriers(Y, b′)`. Violation is a typed rejection
(§10, new code), never a silent continuation and never a `DegenerateEntry`.

### Amendment 5 — §10 diagnostic table

**Added, normative rules for every code in the table:**
1. A locus field is populated **only** from the failure site. Back-filling a locus field from a trace
   seed is prohibited. Seed identity is published in **separate, distinctly named** fields.
2. Every locus the table requires must be **observable in the witness diagnostic string**, not merely
   present in the error struct. A locus that exists but is not emitted does not satisfy §10.

**New code added to the table:**

| Code | Fires when | Required loci |
|---|---|---|
| `BranchTransportFlowDisagreement` | Amendment 4 — the carrier is outflow in `X` but not inflow in `Y` | both `sourceFace`s, both branches, the shared edge, both exact derivatives |

`VertexTransitSectorUnresolved`'s required loci are extended to include **the set of admitted candidate
faces** (empty or ≥ 2), so "no face" and "many faces" are distinguishable without a rerun.

---

## 10. Corrective measures — series **E**, one Code + Build turn (`M3-CP4c-0-CB2`)

Ordered. E1 is first on purpose: it is cheap, it cannot regress anything, and it converts the routes of
§2.3 from a three-way guess into an observation.

**E0 — binding preconditions.**
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Code + Build only: author and compile all
eight standard targets; **execute nothing**. Do not edit any fixture. Do not add any sphere-specific,
edge-specific, face-specific, vertex-specific, or index-specific branch. Do not retune, widen, narrow,
or delete `kBranchTopologyTolerance`. Do not weaken T6 or Q8. Do not touch C4/C5, the torus, the
mechanical locus, CP4c-1/2/3. Re-freeze the selector as `316 + n` and publish both hashes.

**E1 — publish the loci that already exist.** *(diagnostics; no production semantics change)*
- **E1a.** Extend `append_network_error` in `tests/FieldAlignedCurveNetworkTests.cpp` to emit
  `sourceFace` (reuse the existing `source_face_locus`), `branch`, `parameter`, `exactValues`, and
  `publishedEdges` whenever present. Exact rationals must print in a **lossless** form — numerator and
  denominator, or an exact dyadic — never a rounded decimal.
- **E1b.** Do the same for `resolve_field_vertex_transit`'s `VertexTransitSectorUnresolved`, including
  Amendment 5's admitted-candidate-face set.
- **E1c.** Remove the seed back-fill at `SurfaceCellTracing.cpp:818-819`. Publish the seed as
  distinctly named fields (`traceSeedVertex`, `traceSeedSingularity`); leave `sourceVertex` unset when
  the failure site has no vertex.
- **Acceptance:** every code in DEFN §10 has an identity asserting each of its required loci appears in
  the emitted string. This closes the evidence gap that stopped the TB turn.

**E2 — exactify A1's flow classification.** *(root cause; routes A′ and, with E5, A)*
In `build_boundary_pairing` (`FieldTransportAtlas.cpp:162-170`), classify from
`exactDirection[opposite[index]]` against exact zero: `> 0` → `Inflow`; `< 0` → `Outflow`; `== 0` →
`Tangent`. Delete the `double`-and-`τ` comparison at this site.
*Note for the implementer:* this is safe and information-preserving. `from_double_exact` is lossless,
so the exact sign **equals** the `double` sign; the only behaviour change is that `|d| ∈ (0, τ]` now
classifies as a carrier instead of `Tangent`. Under `Σ d = 0, d ≠ 0` both carrier sets become
non-empty by construction, so `InvalidBranchBoundaryFlow` (`:174-179`) becomes unreachable — leave the
guard in place and annotate it per E7.

**E3 — exactify the vertex sector rule and collapse to one rule.** *(root cause; route B)*
- Add the exact overload of `direction_in_vertex_sector` taking the face's `FieldBranchDirection`,
  implementing Amendment 2's predicate. Index by **vertex identity**, not corner position.
- Migrate both callers: `FieldTransportAtlas.cpp:546` (S2) and `SurfaceCellTracing.cpp:559-565` (S3).
- **Delete** the `Eigen::Vector3d` overload (`FieldTransportAtlas.h:514`) and **delete**
  `field_branch_world_direction` (`SurfaceCellTracing.cpp:336-357`) — the lossy round trip. Both have
  exactly two production callers and **no test callers**; this has been verified. Exactly one sector
  rule survives.
- **Digest risk, must be pre-checked before compiling:** E3 changes A1's `FieldSingularityPortAttachment`
  selection, which is consumed by the atlas digest (`FieldTransportAtlas.cpp:1124-1127`). Enumerate
  every accepted identity asserting an atlas digest and confirm each is **relative/self-consistent**,
  not an absolute constant. If any is absolute, report it in the CB record and do not silently rewrite
  it — an absolute-digest identity that must change is a finding for review, not a CB edit.

**E4 — T1 exhaustiveness (Amendment 3).**
In the `minimizers.size() == 1U` branch (`SurfaceCellTracing.cpp:482-493`), after computing
`exitPoint`, test its parameter for exact `0` or `1`; if so, return `VertexHit` with the corresponding
vertex so T2/T3 dispatch normally.

**E5 — cross-edge flow agreement (Amendment 4).**
At the transport step (`SurfaceCellTracing.cpp:895-918`), after resolving `nextFace`/`nextBranch` and
before adopting the entry point, require `decision.outgoingCarrier ∈
nextPairing.incomingCarriers`. On violation emit the new `BranchTransportFlowDisagreement` with both
faces, both branches, the edge, and both exact derivatives. This must be a **general** invariant check,
not a sphere patch.

**E6 — replace the position-blind cycle break (defect D-b).**
Separate termination from cycle detection. Either key `visited` on the exact entry point as well and
add an explicit typed bound (`TraceStepBudgetExhausted` or equivalent, with the bound stated in the
DEFN), or state and justify a different termination rule. **A trace stopped by the bound must not be
published as a clean terminus** — today `:908-911` sets `terminalPoint` and breaks, manufacturing one.
Q8's trace count and terminal-event requirement cannot be credited until this is correct.

**E7 — reachability annotations (§8).**
Annotate `BranchContinuationNoOutflow`, the `|N| = 3` and `|M| > 2` `MinimizerImpossible` sites, and
`InvalidBranchBoundaryFlow` as unreachable-from-valid-authority, each with a one-line proof reference
and a note that its falsifier is unit-level over a tampered direction. Mirror the annotations into the
DEFN §10 table.

**E8 — falsifying identities.** Each must **fail if its measure is wrong**, not merely execute it.

| Measure | Falsifying identity |
|---|---|
| E1 | For every DEFN §10 code, assert each required locus is present in the emitted diagnostic string. Deleting one emit must turn it red. |
| E1c | Assert a failure whose site has no vertex emits **no** `sourceVertex`, and that the seed appears only under `traceSeedVertex`. |
| E2 | A face+branch with `0 < \|d_i\| ≤ 1e-10`: assert the edge opposite `i` is a **carrier**, not `Tangent`, and that both carrier sets are non-empty. |
| E3 | **The band identity.** A vertex fan with a direction whose `d[prev] ∈ [−1e-10, 0)`: assert the exact rule **rejects** that face, that exactly one face is admitted across the fan, and that the resulting entry yields `t* > 0`. Reintroducing `τ` must turn this red. |
| E3 | **The round-trip identity.** A direction where `field_branch_world_direction` followed by the Gram solve returns a `β` of the **opposite sign** to `pairing.direction[prev]`; assert the exact rule follows `pairing.direction`. |
| E3 | **Fan partition.** On every accepted witness, for every `(vertex, branch)` fan, assert the exact predicate admits **exactly one** face. |
| E4 | An `\|M\| = 1` exit whose exact parameter is `0`: assert the decision is `VertexHit` at that vertex, not `EdgeExit`. |
| E5 | A tampered adjacency where an outflow carrier is not inflow in the neighbour: assert `BranchTransportFlowDisagreement` with both derivatives, not `DegenerateEntry`. |
| E6 | A trace re-entering the same `(face, branch, incoming edge)` at a **different** exact parameter: assert it continues and is **not** truncated, and that a bound-terminated trace is not published as a clean terminus. |
| **Theorems 1–3** | An end-to-end identity asserting that on every accepted witness **no** `BranchContinuationDegenerateEntry` and **no** `BranchContinuationOutsideOutflowSet` is produced. This is the direct machine statement of §7. |

**E9 — accepted-prefix and CP4c-0 re-proof.**
The successor TB must re-prove **316/316** and the **12** CP4c-0 identities alongside the new ones.
Publish the 316-prefix hash and confirm it still equals `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`.
E2 and E3 change **A1 published authority**, so this is a real regression surface, not a formality.
Any accepted identity that goes red is a **stop condition and a finding for review** — CP4c-0 must not
be closed by editing an accepted expectation.

**E10 — build verification and the successor TB plan.**
Compile all eight standard targets clean. Record the semantic source SHA, the immutable package id and
SHA-256, the re-frozen selector hash and its 316-prefix hash. Restate Q8 **verbatim** — 24 traces, ≥1
terminal `TraceIntersection`, face `1-2-5` / incoming `1-2` → `{1-5, 2-5}` with the frozen crossover
flip — and state that Q8 is not creditable unless E6 is in the package.

---

## 11. Falsifiable predictions

Recorded now so the successor turn can confirm or refute them rather than reinterpret them.

- **P1.** With **E1 alone**, the sphere's rejection publishes `sourceFace`, the branch, and the exact
  `parameter`. `parameter ∈ {0, 1}` ⟹ **route B**; strictly interior ⟹ **route A or A′**. This
  prediction is decidable from the very next TB report.
- **P2.** With **E2 + E3 + E4 + E5**, `BranchContinuationDegenerateEntry` disappears from the sphere
  **on every route** — B by Theorem 1, A′ by E2 + Theorem 3, A by E5 re-typing it.
- **P3.** If, after E3, the sphere fails with `VertexTransitSectorUnresolved` reporting **zero or ≥ 2**
  admitted faces, the per-face directions do not form a coherent fan. That is an **A1 matching defect**,
  not a continuation defect, and it is a distinct, well-localized checkpoint — not a reason to
  reintroduce a tolerance.
- **P4.** If the failure re-emerges as `BranchTransportFlowDisagreement` at edge `6-8`, route A is
  confirmed and the residual defect is in A1's Z4 lift or matching for that edge — again distinct, and
  again localized by construction.
- **P5.** The accepted **316** stay green. The only plausible regressions are an identity asserting an
  **absolute** atlas digest (E3 changes port attachments) or one asserting `Tangent` where
  `0 < |d| ≤ 1e-10` (E2). Both are **statically enumerable during CB**, before any run. The single
  `Tangent` consumer found in the accepted suite —
  `tests/FieldTransportAtlasTests.cpp:1175-1195` — asserts only *consistency* between `interval.flow`
  and the carrier lists, which E2 preserves exactly.
- **P6.** Q8 remains red until E6 lands, **even if the network publishes**, because a position-blind
  truncation can alter the trace count and manufacture a terminus.

---

## 12. Risk register

| # | Risk | Mitigation |
|---|---|---|
| 1 | E3 changes A1 port attachments ⟹ atlas digests move | E3's mandatory pre-check enumerates absolute-digest identities **before** compiling; any absolute digest is a review finding, not a CB edit |
| 2 | E2 flips a `Tangent` classification an accepted identity depends on | P5's static enumeration; the sole consumer is consistency-only |
| 3 | E6 is the largest change and touches trace termination | E6 is separable; if it destabilizes, land E1–E5 + E7–E9 first and carry E6 as its own measure — but **Q8 stays red** until E6 is in |
| 4 | Exactifying the sector rule admits 0 or ≥ 2 faces on some fan | Already typed as `VertexTransitSectorUnresolved`; E1b makes it self-diagnosing; P3 turns it into a localized successor |
| 5 | Temptation to widen a tolerance to "make the sphere pass" | Explicitly prohibited by E0 and by Amendment 1. Every measure here **removes** tolerance from topological decisions; none adds any |
| 6 | Temptation to weaken Q8 or edit the sphere fixture | Prohibited. §6 establishes the fixture and oracle are both valid |

---

## 13. Review record

- **Adjudicated failure class:** upstream ill-formed state — tolerant sign decisions on
  `pairing.direction` feeding an exact consumer. **Confidence: high.** The algebra of §4.1–4.3 is
  exact and requires no runtime; the identity `α = d[next]`, `β = d[prev]` is derived, not assumed.
- **Specific route among A / A′ / B: undetermined**, and deliberately not guessed. E1 determines it in
  one turn; E2–E5 close all three regardless.
- **T6 status:** correct as frozen. **Not amended, not weakened.** Rendered unreachable from
  well-formed states by Theorems 1–3.
- **Q8 status:** valid, binding, **unchanged**. Additionally gated on E6.
- **Definition defects owned by this reviewer:** DEFN §4.3's tolerance-harmlessness claim
  (Amendment 1); DEFN §4.4's "partition" claim (Amendment 2); DEFN §4.4's non-exhaustive T1
  (Amendment 3); a missing cross-edge invariant (Amendment 4); a §10 table that required loci to exist
  without requiring them to be *observable* (Amendment 5).
- **Implementation defects found, none attributable to CB1's frozen scope:** the S3 lossy round trip;
  the seed back-fill at `:818-819`; the position-blind cycle break; the unasserted cross-face flow
  invariant.
- **CB1's compliance:** CB1 implemented DEFN §10's required loci **correctly in production**. The gap
  is in the witness diagnostic emitter, which the DEFN did not require it to extend. **That omission is
  this reviewer's, in the DEFN, not CB1's.**
- **Unresolved gaps:** the specific route; whether E3's exact fan predicate admits exactly one face per
  fan on every accepted witness (E8 measures it directly).
- **Successor turn:** `M3-CP4c-0-CB2`, measures **E0–E10**. Code + Build only.
- **Mutation statement:** this review executed **no** runtime, **no** build, **no** benchmark, and made
  **no** change to product source, test source, fixtures, the selector, or build configuration. Its
  only writes are to durable documentation under `.agents/Directional/`.
