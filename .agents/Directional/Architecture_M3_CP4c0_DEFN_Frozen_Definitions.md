# Architecture M3 CP4c-0 — Frozen Definitions for Resolved Branch Continuation

**Turn:** `M3-CP4c-0-DEFN`
**Type:** Independent definition / review / planning only — no product, test, fixture, selector, build, package, or runtime mutation
**Charter:** `Architecture_M3_CP4c0_DEFN_Charter.md` (D0–D5)
**Status:** **FROZEN.** §3–§10 are normative for `M3-CP4c-0` and may change only by an explicit plan update.
**Incoming accepted authority:** M3-CP4ab **316/316**, source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`

> ## AMENDED 2026-08-25 — read this before §4
>
> `M3-CP4c-0-TB` executed this contract. The required **328/328** gate went green, but the prescribed
> sphere was rejected at **T6** (`t* = 0`, `BranchContinuationDegenerateEntry`, `sourceEdge=6-8`).
> `M3-CP4c-0-TB-REVIEW-PLAN` adjudicated that failure and found **five defects in this document**.
>
> **Five amendments are normative and supersede the text they name.** They are stated in full in
> **`Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md` §9**:
>
> 1. **§4.3** — the claim that the surviving `kBranchTopologyTolerance` is harmless is **retracted**. It
>    decides carrier-set membership, which is an ownership key, which `DESIGN.md` §6.3 forbids. Every
>    sign-of-`d` decision moves to exact comparison against zero on `pairing.direction`.
> 2. **§4.4 / T2** — the claim that `alpha > tol && beta >= -tol` is a **partition** of the vertex fan is
>    **retracted**; with `tol > 0` it is neither a partition nor a cover. T2 keeps **one** sector rule,
>    exactified to `d[next] > 0 ∧ d[prev] ≥ 0`, indexed by vertex identity. The `Eigen::Vector3d`
>    overload is deleted, so exactly one rule survives.
> 3. **§4.4 / T1** — T1 applies **only** to a strictly interior exit parameter. An exit parameter of
>    exactly `0` or `1` is a vertex and must dispatch to T2/T3.
> 4. **§9** — cross-edge flow agreement is added as a published A1 invariant, asserted by A2a at the
>    point of use.
> 5. **§10** — locus fields are populated only from the failure site (never back-filled from a trace
>    seed), every required locus must be **observable in the emitted diagnostic**, and
>    `BranchTransportFlowDisagreement` is added.
> 6. **§10 again, added 2026-08-26 after `M3-CP4c-0-TB-R2`** — **"observable" is now defined by
>    mechanism**: formatted through a named `*_locus` helper, printable ASCII only (no NUL), parseable,
>    and site-sourced across *every* emission site. Every diagnostic requirement must be falsified by a
>    **class** identity, not an instance one. See Amendment 6 at the end of §10.
> 7. **§9 + §4.4, added 2026-08-26 after `M3-CP4c-0-TB-R3`** — **`FieldBranch` is a per-face gauged
>    label, not a portable direction identifier.** Cross-face branch comparison is valid only through the
>    published `signedLift`. Production is compliant everywhere; the oracle that assumed otherwise was
>    not. A required falsifier may also not assert the *existence* of a current production failure. See
>    Amendment 7 at the end of §10.
> 8. **§9, added 2026-08-26 after `M3-CP4c-0-TB-R5`** — **the cross-edge flow invariant audits the
>    field's input matching, not only A1's composition.** `signedLift = matching + g_source − g_target`,
>    so the invariant firing means one of {input matching, gauge composition, flow classification} is
>    inconsistent — it does not by itself indict A1 code. A witness whose matching is *imposed* rather
>    than derived from its directions **will** trip it, correctly. See Amendment 8 at the end of §10.
> 9. **§9 + `DESIGN.md` §4.5, added 2026-08-26 after `M3-CP4c-0-TB-R6`** — **Amendment 4's cross-edge
>    flow invariant is a CONTINUUM statement and is unsound for a piecewise-constant field near edge
>    tangency.** Measured: 144 of 1152 directed sphere pairs violate it, every one near-tangent
>    (ratio median 0.0218 vs 0.9233 for satisfying pairs), while every published term at the live locus
>    is independently verified correct. `BranchTransportFlowDisagreement` is a **typed grazing
>    observation**, not an A1 defect, and `DESIGN.md` §4.5 does not define a grazing continuation. See
>    Amendment 9 at the end of §10.
>
> 10. **§4.4 + `DESIGN.md` §4.5, added 2026-08-26 after `M3-CP4c-0-DEFN-2`** — **the gap Amendment 9
>     opened is closed. Grazing is a classified continuation, not a rejection.** A carrier's relation to
>     the face a trace is about to enter is a three-way classification read from that face's published
>     `direction`; `Outflow` on both sides means the trace **transits along the edge** to the endpoint
>     both faces drive the parameter toward, then re-enters the existing T2/T3 vertex dispatch.
>     `BranchTransportFlowDisagreement` is retired from production emission. See Amendment 10 at the end
>     of §10, and `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` for the full contract.
>
> 11. **§11 / Q8, added 2026-08-27 after `M3-CP4c-0b-DEFN`** — **Q8 is split with the checkpoint.**
>     Criteria **1, 4 and 5** remain binding on CP4c-0 and are unchanged. Criteria **2** (the prescribed
>     sphere publishes a 24-trace network) and **3** (at least one terminal `TraceIntersection`) **move
>     together to `M3-CP4c-0b`**, because they are one piece of work: the circulating traces are
>     simultaneously what blocks 2 and what satisfies 3. Neither is weakened, relabelled, or satisfiable
>     by anything other than the outcome it names. CP4c-0 closes on its own 346 identities and criteria
>     1, 4, 5. See `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`.
>
> **T6 and the remaining Q8 criteria are NOT amended.** Both are correct as frozen. After the amendments, T6 is *provably
> unreachable* from any well-formed production state (review §7, Theorems 1–3); Amendment 10 preserves
> that unreachability rather than relying on it.
>
> **Amendment history:** 1–5 after `M3-CP4c-0-TB`; 6 after `TB-R2`; 7 after `TB-R3`; 8 after `TB-R5`;
> 9 after `TB-R6`; 10 after `DEFN-2`; 11 after `CP4c-0b-DEFN`.
> The next turn is **`M3-CP4c-0-TB-R9`** on the 346 selector, which closes CP4c-0 against criteria
> 1, 4 and 5. Trace termination is `M3-CP4c-0b`, measures **P0–P9**, in
> `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` §10.

---

## 0. Summary of what is frozen

| Charter question | Frozen answer |
|---|---|
| **D0** exact position authority | New typed value `FieldBoundaryPoint{edge, parameter}`. **`SourceSupport` is not sufficient** — `SourceEdgeSupport` carries no parameter. Single writer: **A2a**. §3. |
| **D1** continuation rule | Exact minimum-ratio exit on barycentric coordinates. **No tolerance decides any topological outcome** — doubles are dyadic rationals, so the comparison is exact by cross-multiplication. §4. |
| **D2** A1 contract shape | `connections` is **deleted**. A1 publishes the per-`(face, branch)` barycentric **direction** instead. `intervals`, `incomingCarriers`, `outgoingCarriers` stay authoritative. §5. |
| **D3** re-proof surface | Semantic-shape and digest change in A1/A2a. **No accepted witness's traces, events, network, or plan changes** — proven in §6.3. |
| **D4** witness capability | Measured table in §7. Two-ring and fan reach A2b; torus reaches A2a empty; sphere reaches A2a and stops at the ambiguity; mechanical stops at A1. |
| **D5** terminus unification | **One datum, two consumers. Unify.** The barrier terminus becomes a `FieldBoundaryPoint` on the mandatory edge. §8. |

**A bonus that falls out of D1:** `FieldAlignedNetworkEventKind::SingularityTermination` — declared since CP3b and, per CP4-DEFN §3.3, **never produced by anything** — finally acquires its producer (§4.4 case T3).

---

## 1. Evidence consumed, and it confirms the diagnosis

`M3-CP4c-1-TB-R3`, run/job `32872112507 / 97881418987`, immutable package `9570940997`, result artifact `9572545977`. 323 fresh processes, zero orchestration errors, accepted prefix **316/316 PASS**, every mutation flag false, empty package/source postflight diffs.

### 1.1 Z1 — the ambiguity census

| Witness | frames | pairings | `(in × out)` distribution | ambiguous | % |
|---|---:|---:|---|---:|---:|
| two-ring skew disc | 15 | 60 | `1×2:30, 2×1:30` | 30 | **50%** |
| four-triangle fan | 4 | 16 | `1×1:8, 1×2:4, 2×1:4` | 4 | **25%** |
| torus | 144 | 576 | `1×2:288, 2×1:288` | 288 | **50%** |
| prescribed sphere | 192 | 768 | `1×2:384, 2×1:384` | 384 | **50%** |

Exactly 50% on every non-degenerate witness. That is the signature the review predicted from `dbary = {-u - v, u, v}` summing identically to zero: one coordinate takes one sign and two take the other, so a face is either `2×1` (resolvable) or `1×2` (ambiguous), with no third possibility. The fan's `1×1:8` are tangent faces where one derivative falls inside `kBranchTopologyTolerance`.

**The two accepted witnesses have non-zero ambiguity.** The defect is latent in accepted authority and was never witness-specific.

### 1.2 Z2 — the site pin

Prescribed sphere: failure at **`field_aligned_outgoing_carrier`** after **one completed segment**, face `1-2-5`, incoming carrier `1-2`, outgoing carriers `{1-5, 2-5}`, multiplicity **2**, `fieldTransportAdjacencyExists=true`.

Every binding prediction confirmed. Not `field_aligned_next_face`, not `topology.transport`. The charter's stop condition (§"If TB-R3 falsifies…") **did not fire**, so this DEFN is authorized to freeze.

Note the two outgoing carriers `1-5` and `2-5` **share vertex 5**. That is the geometry of the tie case and it is why §4.4's vertex handling is not hypothetical.

---

## 2. The gap is two missing data, not one

The review named one. Reading the published structures closes that:

**(i) The entry position.** `FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:194-213`) carries `sourceFace`, `branch`, `incomingCarrier`, `outgoingCarrier`, `entryTransport` — **no position of any kind**.

**(ii) The direction.** `FieldBranchBoundaryPairing` (`include/directional/authority/FieldTransportAtlas.h:289-297`) carries `branch`, `intervals`, `incomingCarriers`, `outgoingCarriers`, `connections`. `FieldFaceBranchFrame` (`:299-306`) carries `sourceFace`, `topologyRegion`, `sourceComponent`, `branches`. **Neither publishes the barycentric direction.** `dbary` is computed at `src/authority/FieldTransportAtlas.cpp:118`, used to classify the three edges, and then **discarded**.

So even a consumer holding an exact entry position could not resolve the continuation today: the vector it must travel along is not published. **Both data are required, and they have different owners** — the position is a property of the trace (A2a), the direction is a property of the field on a face (A1).

This is why `connections` became a Cartesian product. It is not a shortcut; it is the most A1 could say with what it kept.

---

## 3. D0 — exact position authority, frozen

### 3.1 `SourceSupport` is not sufficient, and this is settled from source

`include/directional/authority/SourceSupport.h:23-26`:

```cpp
struct SourceEdgeSupport {
  SourceEdgeTopologyKey edge;
  auto operator<=>(const SourceEdgeSupport &) const = default;
};
```

It records **which** edge a point lies on and **not where**. `DESIGN.md` §6.3 calls the kernel a *classifier* — "classifies a point as a tagged value" — and §4.5 requires positions "**compatible with** `SourceSupport`", not identical to it. A new value is required, and it must **project onto** the existing kernel rather than duplicate it.

### 3.2 The frozen value

```
FieldBoundaryPoint {
    SourceEdgeTopologyKey edge;      // canonical, first() < second()
    ExactUnitParameter    parameter; // exact rational in [0, 1]
}
```

**Orientation convention, frozen.** `parameter` is the fraction of the way from `edge.first()` to `edge.second()`. `SourceEdgeTopologyKey::make` canonicalises with `if (b < a) std::swap(a, b)` (`src/authority/AuthorityKernel.cpp:19-28`), so `first() < second()` **always**. The parameter is therefore **face-independent and orientation-free**: the same point read from either incident face yields the same value, with no second convention and no per-face flip. This is what answers the charter's *"how the value survives transport across source-face boundaries without introducing a second semantic authority"* — **it survives because the edge key is already canonical, so there is nothing to convert.**

**`SourceSupport` projection, frozen and total:**

| `parameter` | projection |
|---|---|
| exactly `0` | `SourceVertexSupport{edge.first()}` |
| exactly `1` | `SourceVertexSupport{edge.second()}` |
| strictly between | `SourceEdgeSupport{edge}` |

The projection is the **only** sanctioned way to obtain a `SourceSupport` from a `FieldBoundaryPoint`. `FieldBoundaryPoint` does not replace, wrap, or shadow `SourceSupport`, and no consumer may reconstruct one by hand.

### 3.3 Exactness — what "arbitrary precision" means here, precisely

`DESIGN.md` §4.5 requires barycentric positions to "propagate in arbitrary precision rather than by numerical integration". That phrase is about **propagation**, and it is achievable in full. It is *not* a claim that the inputs are exact, and this DEFN does not pretend otherwise:

- **The direction is inherently floating point.** `u` and `v` derive from mesh coordinates and the field, both `double` (`FieldTransportAtlas.cpp:112-118`). No representation choice makes them exact.
- **But every IEEE `double` is exactly a dyadic rational.** So the *arithmetic on them* can be exact, and the comparison that decides topology can be exact.

**Frozen requirement.** `ExactUnitParameter` is an exact rational value. Every step recomputes the exit parameter from the published direction and the incoming parameter; **no value is ever carried forward through an accumulating floating-point update**. All comparisons that decide a topological outcome are performed by **exact integer cross-multiplication**, never by dividing and comparing doubles (§4.3).

**Explicitly prohibited:** storing the parameter as a bare `double`; comparing `t` values by subtraction against an epsilon; any `1e-9`-style test on a parameter; any quantized integer key derived from a float (`DESIGN.md` §6.3 forbids both by name).

**Implementation freedom, bounded.** The exact representation is the implementer's choice — a rational over `__int128`, a small big-rational, or dyadic mantissa/exponent pairs — provided **Q3's exactness proof** (§11) passes. If no available mechanism can make the §4.3 comparison exact for the observed magnitude range, that is a **stop condition**: return to review rather than reintroducing a tolerance.

### 3.4 Single writer

**A2a (`FieldAlignedCurveNetwork`) is the sole writer of `FieldBoundaryPoint` values on traces.** A1 writes no positions; it writes the direction (§5). A2b reads and never computes one. `GlobalTopologyPlan` may not construct a `FieldBoundaryPoint`, and no test may synthesise one outside a tamper candidate.

---

## 4. D1 — the continuation rule, frozen

### 4.1 The model, stated exactly

Within one face, for one branch, the field direction is a **single constant vector** — `build_branch_boundary_pairing` computes one `dbary` per `(face, branch)` and classifies all three edges from it. Therefore **the trace is a straight segment in barycentric coordinates**, and the continuation is elementary.

Let the face have canonical vertices `(v0, v1, v2)`. Let the entry point have barycentric coordinates `p = (p0, p1, p2)` with `Σ p_i = 1` and `p_i ≥ 0`, and let the direction be `d = (d0, d1, d2)` with `Σ d_i = 0`.

The trace travels `p + t·d` for increasing `t ≥ 0`. Coordinate `i` reaches zero at `t_i = p_i / (−d_i)`, defined only where `d_i < 0`.

### 4.2 The rule

1. **Candidate set** `N = { i : d_i < 0 }`.
2. **Exit time** `t* = min{ t_i : i ∈ N }`.
3. **Minimizer set** `M = { i ∈ N : t_i = t* }`, compared **exactly**.
4. **Dispatch on `|M|`** — see §4.4.

For `|M| = 1` with minimizer `i*`, the exit lies on the edge **opposite `v_i*`**, and the exit point's barycentric coordinates are `p + t*·d`. Its `FieldBoundaryPoint` parameter is that exit's coordinate along the canonical edge key, converted once, exactly.

**This subsumes the current behaviour and explains it.** `pairing.outgoingCarriers` is precisely `{ edge opposite v_i : i ∈ N }`. When `|N| = 1` the minimum is trivially that one element, so the old Cartesian lookup and the new rule **agree**. When `|N| = 2` the old lookup has two candidates and no way to choose; the new rule chooses by `t*`, which depends on `p` — the datum that was missing. §6.3 turns this into the migration's central claim.

### 4.3 The exact comparison, frozen

Never compute `t_i` by division. For `i, j ∈ N`, compare

```
t_i < t_j    ⟺    p_i · (−d_j)  <  p_j · (−d_i)
```

with both sides evaluated in **exact integer arithmetic** over the dyadic representations. Because `−d_i > 0` and `−d_j > 0` for `i, j ∈ N`, the cross-multiplication is sign-safe and no case analysis is needed. Equality in this comparison is **exact equality**, so `|M| = 2` is an exact predicate and not a tolerance verdict.

**This is the sentence that keeps the design invariant.** `DESIGN.md` §6.3 permits a tolerance to decide "whether input is sanitizable" and forbids a tolerance-derived value from being an ownership key. Under §4.3 **no tolerance participates in any topological decision** — not in which edge is exited, not in whether a vertex is hit.

~~The one tolerance that remains is the pre-existing `kBranchTopologyTolerance` used to classify an edge as Tangent during A1's flow classification. That decides **admissibility of the frame**, which §6.3 permits, and it is unchanged by this DEFN.~~

> **SUPERSEDED by Amendment 1** (review §9). The claim is false: that tolerance's verdict *is*
> `incomingCarriers` / `outgoingCarriers` membership, and carrier membership gates which edge a trace may
> exit through. It is a tolerance-derived **ownership key**, which `DESIGN.md` §6.3 forbids. Normative
> replacement: every sign-of-`d` decision — flow classification, carrier membership, vertex-sector
> membership, `N`, `M`, exit time — is exact against zero on `pairing.direction`; `Tangent` means
> `d_i == 0` exactly. `kBranchTopologyTolerance` is retained **unchanged** for genuine admissibility
> guards that are not sign-of-`d` decisions (degenerate Gram determinant, non-finite input).

### 4.4 Case dispatch, exhaustive

| Case | Condition | Outcome |
|---|---|---|
| **T1** | `\|M\| = 1`, `t* > 0` | **Edge exit.** Continue into the opposite face across the exit edge, carrying the exit `FieldBoundaryPoint`. The normal case. |
| **T2** | `\|M\| = 2`, `t* > 0`, shared vertex is **regular** | **Vertex transit.** The exit is exactly the shared vertex of the two candidate edges. Re-emit from that vertex using A1's existing sector rule, `direction_in_vertex_sector` (`FieldTransportAtlas.cpp:388-412`). Publish a `FieldBoundaryPoint` with parameter exactly `0` or `1`, whose `SourceSupport` projection is the vertex. |
| **T3** | `\|M\| = 2`, `t* > 0`, shared vertex **is a singularity** | **Terminate**, emitting `FieldAlignedNetworkEventKind::SingularityTermination`. `DESIGN.md` §7.2 step 5 lists a singularity as a lawful terminator; CP4-DEFN §3.3 records that this event kind is declared and produced by nothing. **This case is its producer.** |
| **T4** | `\|M\| = 3` | Impossible — `Σ d_i = 0` forbids three negatives. **Typed rejection**, fail closed; it would prove the direction invariant was violated. |
| **T5** | `N = ∅` | No outflow. A1's build already rejects this with `InvalidBranchBoundaryFlow` (`:156-162`), so it is unreachable from a valid frame. **Typed rejection** in A2a regardless. |
| **T6** | `t* = 0` | Degenerate: the entry point already lies on an exiting edge — the trace enters and leaves at the same point. **Typed rejection**, fail closed. |
| **T7** | `Σ d_i ≠ 0` exactly, or `d = 0` | The published direction violates its own invariant. **Typed rejection** naming the face and branch. |

**T2 is the only case that reuses existing accepted machinery.** It must call `direction_in_vertex_sector` rather than re-deriving a sector test — a second sector rule would be a second writer of vertex-emission semantics. ~~Note that helper's half-open convention (`alpha > tol && beta >= -tol`) is a **partition** of the vertex fan: every direction lands in exactly one sector, so it is a lawful deterministic convention, not a tolerance deciding ownership.~~

> **SUPERSEDED by Amendment 2** (review §9). With `tol > 0` the predicate is neither a partition nor a
> cover: it over-admits on the `beta` side (`d[prev] ∈ [−tol, 0)` is accepted although the direction
> exits the face) and under-admits on the `alpha` side (`d[next] ∈ (0, tol]` is rejected although the
> direction enters it). Only `alpha > 0 ∧ beta ≥ 0` partitions the fan. Since `alpha = d[next]` and
> `beta = d[prev]` exactly (review §4.1), the rule is the **same** predicate at `tol = 0`, evaluated on
> `pairing.direction` and indexed by vertex identity. The `Eigen::Vector3d` overload and
> `field_branch_world_direction`'s lossy barycentric→world→barycentric round trip are **deleted**, so
> exactly one sector rule survives. T2's single-writer requirement is preserved, not relaxed.

**T3's boundary with T2 is combinatorial**, decided by whether the shared vertex carries a `FieldSingularityFact` — never by geometry.

> **AMENDMENT 3 — T1 exhaustiveness** (review §9). The T1 row above is **incomplete**. T1 applies only
> when the exit parameter is **strictly interior**. If some `d_k = 0` exactly and `p_k = 0` at entry,
> coordinate `k` stays zero for all `t` and the `|M| = 1` exit lands exactly on a **vertex**
> (`parameter ∈ {0, 1}`), which the implementation currently publishes as an `EdgeExit`. Normative: an
> exit parameter of exactly `0` or `1` **must** dispatch to T2 or T3 by that vertex's singularity
> status. `VertexHit` and `EdgeExit` must never both be able to represent the same geometric event.
>
> **Reachability of T4 and T5, recorded** (review §8). `is_barycentric()` requires `Σ d = 0` and
> `d ≠ 0`, hence `|N| ∈ {1, 2}` always. **T4 (`|M| = 3`), T5 (`N = ∅`), the `|M| > 2` guard, and A1's
> `InvalidBranchBoundaryFlow` are all unreachable from valid published authority.** Their falsifiers are
> unit-level identities over a tampered direction and must be annotated as such; they prove nothing
> about production coverage. Keep the guards — fail-closed assertions on impossible states are correct.

### 4.5 Falsifying witness per branch — required, not optional

The charter requires "a falsifying witness for every nontrivial branch of the rule". Each must be an identity that **fails if the branch is wrong**, not merely one that exercises it:

| Case | Falsifying witness |
|---|---|
| T1 | A face with `1×2` pairing where the two `t_i` differ; assert the exit edge is the **smaller-`t`** one, and that swapping the entry parameter to the other side of the crossover flips the exit edge. Anything that ignores position fails this. |
| T2 | An entry position constructed to hit a shared vertex exactly; assert the published point's projection is `SourceVertexSupport` and the continuation face is the one the sector rule selects. |
| T3 | The same, with the shared vertex a singularity; assert a `SingularityTermination` event is produced and the trace stops. |
| T4/T5/T7 | Tamper the published direction to violate the invariant; assert the exact typed rejection and locus. |
| T6 | Entry parameter placed exactly on an outflow edge's endpoint; assert the typed rejection. |
| **exactness** | Two `t` values that are equal in exact arithmetic but differ in `double` division, or vice versa; assert the exact predicate wins. **Without this identity the §4.3 freeze is unproven.** |

---

## 5. D2 — the A1 contract, frozen

### 5.1 `connections` is deleted

Not demoted, not retained as diagnostics — **deleted**.

A Cartesian product that no consumer may lawfully use is a trap: retaining it invites a future turn to read it and reintroduce the ambiguity, and `LESSONS.md` §4 already records that a representation with a writer and no enforcing reader is latent ambiguity. `FieldBranchBoundaryConnection` is removed with it.

### 5.2 A1 publishes the direction

`FieldBranchBoundaryPairing` gains the barycentric direction it currently discards:

```
FieldBranchBoundaryPairing {
    FieldBranch                             branch;
    FieldBranchDirection                    direction;   // NEW: exact-comparable (d0, d1, d2), Σ = 0
    std::vector<FieldBranchBoundaryInterval> intervals;
    std::vector<SourceEdgeTopologyKey>       incomingCarriers;
    std::vector<SourceEdgeTopologyKey>       outgoingCarriers;
    // connections: REMOVED
}
```

`intervals`, `incomingCarriers`, and `outgoingCarriers` **remain authoritative and unchanged**. They are the flow classification, they are correct, and A2a still uses `outgoingCarriers` to bound the candidate set — the new rule selects *within* that set and may never select outside it. That containment is itself an assertable invariant and should be one.

**`direction` must be stored in a form §4.3 can compare exactly**, and its `Σ = 0` invariant must be checked at construction with a typed rejection, not assumed.

### 5.3 What does not change

- **`FieldBranchTransportAdjacency` and `FieldBranchTopology::transport` are untouched.** They answer "crossing this edge from face A to face B, what is the Z4 lift" — a question independent of position. Z2 confirmed transport adjacency exists and works.
- **`FieldSingularityPortAttachment` is untouched.** It already resolves the first step explicitly via `firstOutgoingCarrier` and `direction_in_vertex_sector`. **This is why the sphere completed exactly one segment before failing** — step 1 has a resolution rule and steps ≥2 did not. A1 has therefore always resolved emission; only continuation was missing.
- **`FieldTransportAtlas`'s adjacency/cycle/effort authority is untouched.**

### 5.4 Digest binding

`branch_topology_digest` (`FieldTransportAtlas.cpp:1053+`) must consume `direction` and must **stop consuming** `connections`. The A1 semantic digest changes as a result — see §6.

---

## 6. D3 — the accepted-prefix re-proof matrix

### 6.1 What propagates

`branch_topology_digest` → `FieldTransportAtlas` semantic digest → `FieldAlignedCurveNetwork::atlas_digest` → `GlobalTopologyPlan::network_digest`.

### 6.2 Digest assertions are all relative

Every digest assertion in the suite compares a baseline against a rebuilt, reordered, or relabeled product — never against a hard-coded constant. This was established during the CP4ab closure review by scanning all test files and is unchanged. **Relative assertions track automatically.**

`validate_field_aligned_candidate` (`SurfaceCellTracing.cpp:1144-1301`) is **recompute-and-compare**: it rebuilds the canonical candidate and compares element-by-element. It tracks the producer by construction. Note, as `LESSONS.md` §1 records, that this proves reproducibility and **not** correctness — it is not evidence for this migration, merely a non-obstacle.

### 6.3 The central claim: **no accepted witness's traces change**

This is the claim that makes the migration safe, and it is provable from Z1's census rather than hoped for.

The new rule and the old lookup **agree whenever `|N| = 1`** (§4.2): with one negative coordinate the minimum is trivially that one, and the Cartesian lookup also has exactly one candidate. They can only differ on a `1×2` face.

The accepted witnesses' traces **build successfully today**. Under the old rule a `1×2` face returns `nullopt` and fails the build. Therefore **no accepted trace has ever traversed a `1×2` face** — if one had, the accepted 316 would not be green. Every face on every accepted trace path is `2×1` or `1×1`, and on those the two rules agree.

**Therefore: accepted traces, their segments' face/branch/carrier content, their events, the network's nodes and mandatory edges, and the derived plan and regions are all unchanged.** Z1's finding that the two-ring is 50% ambiguous is not a contradiction — it counts *all* pairings, including the many the traces never enter.

### 6.4 Per-checkpoint matrix

| Checkpoint | Affected | Kind of change | Action |
|---|---|---|---|
| **M3-CP1** (A1 ports/cycles) | `FieldBranchBoundaryPairing` shape and `branch_topology_digest` | **semantic shape + digest**; port derivation, cycles, effort, index all unchanged | re-run; relative digest assertions track; expect green |
| **M3-CP2** (rails/barriers) | none — barrier classification untouched | **no-op** | re-run; expect green |
| **M3-CP2b** (Z4 transport) | none — `FieldBranchTransportAdjacency` untouched | **no-op** | re-run; expect green |
| **M3-CP3a** (candidate traces) | `FieldAlignedCandidateTraceSegment` gains an entry `FieldBoundaryPoint` | **shape + digest**; per §6.3 the *content* of accepted traces is unchanged | re-run; expect green |
| **M3-CP3b** (events/composition) | events bind unchanged nodes; `SingularityTermination` becomes producible | **shape + digest**; no accepted event changes | re-run; expect green. **Any accepted CP3b identity that asserts terminal-kind exhaustivity must be re-read** — a newly producible kind can invalidate a closed-world assumption |
| **M3-CP4ab** (regions/disc proof) | `network_digest` only | **digest-only**; regions, arcs, rotations, certificates unchanged | re-run; expect green, including `EXPECT_EQ(8U, network.nodes().size())` |

**No identity is expected to require an expectation edit.** That is the falsifiable form of §6.3 and it is checked by Q6.

### 6.5 If an accepted identity does go red

**Stop and return to review.** Do not edit the expectation. A red here falsifies §6.3, which would mean an accepted trace *does* traverse a `1×2` face — and that would mean the old build was succeeding on a face where it should have returned `nullopt`, which is a different and more serious defect than the one this DEFN addresses.

---

## 7. D4 — witness stage capability, measured

Per the rule added at CP4c-1, this table records the furthest stage each witness is **proven** to reach, with its evidence. No witness is reused on reputation.

| Witness | Topology | Reaches | Evidence | Usable for CP4c-0? |
|---|---|---|---|---|
| two-ring skew disc | disc, χ=1 | **A2b** | accepted 316 green | **Yes** — regression baseline |
| four-triangle fan | disc, χ=1 | **A2b** | accepted 316 green | **Yes** — regression baseline; note `1×1:8` tangent faces |
| prescribed sphere | closed, χ=2 | **A2a**, stops at the ambiguity | Z2 site pin | **Yes — the primary target witness** |
| torus | closed, χ=0, genus 1 | **A2a**, publishes 0 traces / 0 events | TB-R2/R3 | **No** — no trace to continue. Deferred to CP4c-2 |
| mechanical feature | closed, χ=2 | **A1 rejects** `IncompleteCycleBasis` | TB-R3 | **No** — never reaches A2a. Deferred to CP4c-3 |

**The prescribed sphere is the only witness that can prove T1**, and it is proven to reach the exact point where T1 applies. T2 and T3 require constructed entry positions on a witness that reaches A2a (§4.5); the sphere and the two accepted discs are the candidates.

---

## 8. D5 — terminus-datum unification: **unified**

The charter warns against unifying merely because both defects mention position. The test is the charter's own: *state the exact predicate each consumer needs, then decide.*

| Consumer | Predicate needed |
|---|---|
| **A2a continuation** (this DEFN) | given entry point on `e_in`, **which** outgoing edge and **where** on it |
| **A2b mandatory-arc split** (CP4ab amendment 10/11) | **where** on the mandatory edge the trace terminated, so the edge splits into two arcs |

Both are "an exact point on a source edge, identified by the canonical edge key and a parameter". **`FieldBoundaryPoint` satisfies both with one type, one writer, and one convention.** They are one datum.

**But the unification is bounded, and CP4ab is not reopened.** Amendment 11 froze that A2a publishes a fresh **combinatorial 0-cell** (`NetworkNodeId`) for every trace terminus, and that node identity is what A2b splits on. That stays exactly as accepted. CP4c-0 **adds** the terminus's `FieldBoundaryPoint` alongside the existing node; it does not replace the node with a coordinate, and `NetworkNodeId` does not become positional.

**Frozen consequence.** The `k ≥ 2` case — two traces terminating on the same mandatory edge — is currently a fail-closed `MandatoryEdgeTerminalOrderUnresolved` because no order exists (CP4-DEFN amendment 10). Once termini carry exact parameters, that order **is** available. **CP4c-0 does not use it.** Ordering multiple termini along an edge is a separate semantic change with its own re-proof surface and belongs to a later checkpoint. The rejection stays in place, and a comment must record that the datum now exists but is deliberately not consumed.

---

## 9. Ownership table

| Datum | Owner (single writer) | Published on | Consumers |
|---|---|---|---|
| `FieldBranchDirection` (barycentric `d`, Σ=0) | **A1** `FieldTransportAtlas` | `FieldBranchBoundaryPairing.direction` | A2a continuation only |
| flow classification, in/out carriers | **A1** | `FieldBranchBoundaryPairing` | A2a candidate-set bound |
| Z4 transport across an edge | **A1** | `FieldBranchTransportAdjacency` | A2a; unchanged |
| vertex-fan emission sector | **A1** | `direction_in_vertex_sector` + `FieldSingularityPortAttachment` | A2a steps 1 and T2; unchanged |
| `FieldBoundaryPoint` on a trace | **A2a** `FieldAlignedCurveNetwork` | trace segments + terminus | A2b (read-only) |
| network 0-cells (`NetworkNodeId`) | **A2a** | nodes/events | A2b; **unchanged by this DEFN** |
| regions, arcs, certificates | **A2b** `GlobalTopologyPlan` | plan | tests |

**Prohibited, each a stop condition:** A2b computing or mutating a `FieldBoundaryPoint`; A2a deriving a direction rather than reading A1's; a second sector rule; a second continuation rule; any consumer reconstructing `SourceSupport` from a parameter by hand instead of using the §3.2 projection.

> **AMENDMENT 4 — cross-edge flow agreement** (review §9). Added row, normative:
>
> | Datum | Owner (single writer) | Published on | Consumers |
> |---|---|---|---|
> | cross-edge flow agreement | **A1** | `FieldBranchBoundaryPairing` carrier sets + `FieldBranchTransportAdjacency` | A2a asserts it at the point of use |
>
> For an edge `e` shared by faces `X` and `Y` whose branches are related by the Z4 lift,
> `e ∈ outgoingCarriers(X, b)` **requires** `e ∈ incomingCarriers(Y, b′)`. Nothing asserted this before;
> A1 classifies each face's flows from that face's own `dbary` and no invariant tied the two signs.
> Violation is a typed rejection (`BranchTransportFlowDisagreement`), never a silent continuation and
> never a `BranchContinuationDegenerateEntry`.
>
> **Also amended:** the row *"vertex-fan emission sector — `direction_in_vertex_sector` … unchanged"* is
> superseded by Amendment 2. That helper is exactified and its `Eigen::Vector3d` overload deleted; A1
> remains its single writer.

---

## 10. Rejection and diagnostic table

Every rejection names its locus. `LESSONS.md` §2 records what an overloaded code costs: `RegionCutComponentCountDeficit` at 18 sites made the torus failure unlocalizable, and splitting it is what made TB-R3 informative.

| Code | Fires when | Required loci |
|---|---|---|
| `BranchDirectionNotBarycentric` | T7 — `Σ d ≠ 0` exactly, or `d = 0` | `sourceFace`, `branch` |
| `BranchContinuationNoOutflow` | T5 — `N = ∅` | `sourceFace`, `branch`, incoming edge |
| `BranchContinuationDegenerateEntry` | T6 — `t* = 0` | `sourceFace`, `branch`, incoming edge, parameter |
| `BranchContinuationMinimizerImpossible` | T4 — `\|M\| = 3` | `sourceFace`, `branch`, all three `t` values |
| `BranchContinuationOutsideOutflowSet` | selected edge ∉ `outgoingCarriers` | `sourceFace`, `branch`, selected edge, the published set |
| `BoundaryPointParameterOutOfRange` | parameter ∉ `[0,1]` | `edge`, parameter |
| `BoundaryPointEdgeNotIncidentToFace` | point's edge is not an edge of the face | `sourceFace`, `edge` |
| `VertexTransitSectorUnresolved` | T2 — the sector rule selects no face | `sourceVertex`, `branch`, incoming face |

**One condition per code.** Reuse an existing code only where its frozen meaning and locus already match exactly (CP4-DEFN amendment 3).

> **AMENDMENT 5 — loci must be observable, and must come from the failure site** (review §9). Two
> normative rules now apply to **every** code in the table above:
>
> 1. A locus field is populated **only** from the failure site. Back-filling a locus field from a trace
>    seed is prohibited — `SurfaceCellTracing.cpp:818-819` back-fills `sourceVertex` from
>    `port.sourceVertex`, which is why the TB report's `sourceVertex=0` named the seed and not the
>    failure. Seed identity is published in separate, distinctly named fields.
> 2. Every locus this table requires must be **observable in the witness diagnostic string**, not merely
>    present in the error struct. CB1 populated `sourceFace`, `parameter`, and `exactValues` correctly in
>    production; `append_network_error` in `tests/FieldAlignedCurveNetworkTests.cpp` emits only
>    `sourceVertex`, `sourceEdge`, `rail`, `singularity`, so the frozen loci were computed and discarded.
>    **A locus that exists but is not emitted does not satisfy this section.** That omission was this
>    document's, not the implementation's.
>
> **New code, normative:**
>
> | Code | Fires when | Required loci |
> |---|---|---|
> | `BranchTransportFlowDisagreement` | Amendment 4 — carrier is outflow in `X` but not inflow in `Y` | both `sourceFace`s, both branches, published `signedLift` actually used, the shared edge, both exact derivatives |
>
> `VertexTransitSectorUnresolved`'s required loci are extended with **the set of admitted candidate
> faces** (empty or ≥ 2), so "no face" and "many faces" are distinguishable without a rerun.

> **AMENDMENT 7 — `FieldBranch` is per-face gauged; and a falsifier may not assert that a witness fails**
> (`Architecture_M3_CP4c0_TB_R3_Review_Plan_Independent_Review.md` §9). `M3-CP4c-0-TB-R3` failed at
> ordinal 334 because a fan-partition oracle iterated a numeric branch label across four faces. It is
> **not** portable.
>
> `build_face_branch_frame` assigns each face a `gauge` by choosing, among
> `{primary, secondary, −primary, −secondary}`, the raw direction with the smallest positive oriented
> angle from that face's **canonical reference edge** (`v0→v1` of its canonical topology key), measured
> about a normal computed from the **canonical vertex order** — which need not agree with mesh
> orientation. Semantic branch `s` denotes `raw[(gauge + s) mod 4]`.
>
> **Normative consequences:**
>
> 1. The same numeric `FieldBranch` on two faces is **not** the same physical direction in general.
> 2. The only sanctioned cross-face relation is `FieldBranchTransportAdjacency::signedLift`, which
>    `build_branch_transports` (`FieldTransportAtlas.cpp:305-320`) has already corrected by
>    `rawGauge[first] − rawGauge[second]`. **Production is compliant at every site** — the trace loop,
>    `resolve_field_vertex_transit`, and the singularity fan partition all rotate by that lift.
> 3. **Any test, oracle, or diagnostic that compares, aggregates, or iterates a branch label across more
>    than one face without applying that lift is ill-formed**, whether or not it currently passes.
>    Ordinal 334 is the worked example: it observed `0, 1, 0, 3` admitted faces where a genuine partition
>    gives `1, 1, 1, 1`, and its branch-1 pass was coincidence.
> 4. A cross-face oracle built on the published lift must be paired with an **independent** check on the
>    gauge correction, so it is not merely consistent with the mechanism under test. The sanctioned check
>    is local holonomy: composed `signedLift` around a complete vertex fan `≡ 0 (mod 4)` at a regular
>    vertex, `≡ index (mod 4)` at a singularity.
>
> **Added to this section's proof rules:** a required falsifier **may not assert the existence of a
> current production failure**. `ASSERT_FALSE(networkBuild)` on the prescribed sphere encodes current
> output as an expectation and inverts the gate at the moment the defect is fixed. Prove such properties
> on a **constructed** failure the test controls; where a production witness is also exercised, its
> branch must be conditional.

> **AMENDMENT 8 — the cross-edge flow invariant audits A1's INPUT as much as its composition**
> (`Architecture_M3_CP4c0_TB_R5_Review_Plan_Independent_Review.md` §8). The A1-only census added by measure H1
> reported 390 disagreements, and the four-triangle fan's contribution proved to be a **fixture
> artifact**: its census field leaves the direction vectors globally constant and *imposes*
> `matching = ±1` on one edge, so the published lift is correct (`+1 + 0 − 1 = 0`) and the disagreement is
> forced by a matching that contradicts the geometry.
>
> **Normative consequences:**
>
> 1. The published lift is a **sum**: `signedLift = matching + rawGauge[source] − rawGauge[target]`. A
>    lift value therefore carries **no information about matching on its own**, and no histogram over
>    lifts may be used to reason about matching.
> 2. Amendment 4's cross-edge flow agreement firing means **one of three things** is inconsistent — the
>    input `matching`, the gauge composition, or the flow classification. **It is not by itself evidence
>    of an A1 code defect**, and no production correction may be authorized from it until the lift is
>    decomposed into its three terms and the owner identified.
> 3. A witness whose `matching` is **imposed** rather than derived from its own direction vectors will
>    trip this invariant correctly, and **must be excluded from — or explicitly classified within — any
>    population used to reason about production authority.** Every census must record, per witness,
>    whether its matching was imposed by the fixture or computed at load.
> 4. Because this invariant audits an input, it belongs in A1's **admissibility** checks as well as at
>    A2a's point of use: a field whose matching contradicts its geometry should be rejected where it
>    enters, not three stages later.
>
> **Also:** a census that checks each edge in both directions double-counts every disagreement. Such a
> census must publish the **distinct** `(edge, branch)` count alongside the directed count, so that no
> reader has to infer the halving.

> **AMENDMENT 9 — the cross-edge flow invariant does not hold for a piecewise-constant field near edge
> tangency** (`Architecture_M3_CP4c0_TB_R6_Independent_Review_Record.md` §8). Amendment 4 required that an
> edge outflowing in `X` for branch `b` inflow in `Y` for the transported branch. On the prescribed
> sphere **144 of 1152 directed source-outflow pairs violate it**, and an independent reproduction from
> the committed fixture — matching the runtime figure exactly — shows every one is a **near-tangency**
> configuration: tangency ratio `min(|d_opp| / max|d|)` median **0.0218** for disagreeing pairs against
> **0.9233** for satisfying pairs. At the live locus every published term (matching, both raw gauges, the
> lift composition, both barycentric directions) is **independently verified correct**.
>
> **Normative consequences:**
>
> 1. **`BranchTransportFlowDisagreement` is not an invariant violation.** It is a **typed observation
>    that the discrete field grazes the shared edge**. It must not be read as an A1 defect, and no
>    production correction to matching, gauge composition, or flow classification may be authorized from
>    it. Amendment 4 is corrected accordingly.
> 2. **`DESIGN.md` §4.5's tracing model is incomplete.** It does not define the continuation of a trace
>    reaching an edge that the neighbouring face's direction also exits. Closing that gap is a **`-DEFN`
>    obligation**, not a patch, and it must be closed before CP4c-0 can publish a sphere network.
> 3. **No tolerance may be introduced to classify grazing.** The tangency distributions overlap, so any
>    cutoff would be a tolerance deciding topological ownership — forbidden by `DESIGN.md` §6.3 and
>    already removed twice at cost. Grazing must be decided by an **exact predicate** on published
>    authority, or by an admissibility precondition that is itself exactly stated.
> 4. **A cross-stage invariant asserted on a discrete field must state its discretization assumptions.**
>    Amendment 4 did not, and asserted a continuum property. Every future invariant of this shape must
>    record whether it holds for piecewise-constant data and in what regime it degrades.
>
> **K5 discretization annotation.** The current `BranchTransportFlowDisagreement` check is evaluated on
> a **piecewise-constant per-face field**. Its cross-edge source-outflow/target-inflow statement is a
> continuum expectation that is informative away from grazing but is **not a rejection invariant at an
> exact grazing locus**. The result is observational only in that regime; no tolerance or rank cutoff may
> convert it into an ownership decision. No other current CP4c-0 cross-stage check asserts this same
> continuum flow-continuity property. Any future check that does must publish its discretization regime
> and degradation regime beside the diagnostic.
>
> **Amendment 8 stands and is reinforced.** It established that this check audits inputs as well as
> composition; Amendment 9 adds that it also audits the **discretization**, and that this third failure
> mode is the dominant one.

> **AMENDMENT 10 — grazing is a classified continuation, not a rejection; the gap Amendment 9 opened is
> closed** (`Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` §5). Amendment 9 declared
> `DESIGN.md` §4.5 incomplete and made closing it a `-DEFN` obligation. `M3-CP4c-0-DEFN-2` discharges
> that obligation and freezes the rule.
>
> **The carrier's relation to the face a trace is about to enter is a three-way classification**, read
> from the exact sign of that face's published `direction` at the coordinate opposite the carrier —
> never by carrier-set membership, which cannot separate `Tangent` from `Outflow`:
>
> | Relation | Continuation |
> |---|---|
> | `Inflow` (`d_Y[opp] > 0`) | ordinary cross-edge continuation, unchanged |
> | `Tangent` (`d_Y[opp] == 0`) | enter `Y`; **Amendment 3 already governs** — the trace travels along the edge and exits at a vertex |
> | `Outflow` (`d_Y[opp] < 0`) | **grazing edge transit** — do not enter `Y`; transit along the edge to one endpoint vertex |
>
> **The transit target is an exact sign predicate on already-published authority.** With `e` canonical
> (`first() < second()`) and `β` the index of `e.second()` in each face's sorted key vertices, let
> `r_X = d_X[β_X]` and `r_Y = d_Y[β_Y]`. These are exactly the rates at which each face drives the
> published `FieldBoundaryPoint` parameter, because `field_boundary_point_from_barycentric`
> (`SurfaceCellTracing.cpp:283-285`) builds that parameter as the barycentric coordinate of
> `e.second()`. Both positive selects `e.second()` (parameter exactly `1`); both negative selects
> `e.first()` (parameter exactly `0`); anything else is the typed rejection
> `BranchGrazingSlideDirectionAmbiguous`. The endpoint is then dispatched by the **existing** vertex
> rule — T3 `SingularityTermination` if it carries a `FieldSingularityFact`, otherwise T2 re-emission.
>
> **Normative consequences:**
>
> 1. **`BranchTransportFlowDisagreement` is retired from production emission.** Enum value 25 is retained
>    and never reused. Grazing is a continuation, so there is nothing left for it to reject.
> 2. **This is the unique continuous extension of Amendment 3**, proved in DEFN-2 §5.4: at
>    `d_Y[opp] = 0` exactly, Amendment 3 already selects `e.second()` iff `r_Y > 0` — the same expression
>    on the same index. A rule that terminated on grazing would be discontinuous across a measure-zero
>    configuration, which is the defect class Amendment 9 exists to prevent.
> 3. **The transit is one hop, never a traversal mode.** `d_X` and `d_Y` are constant per face, so the
>    grazing predicate and both rates are constant along the whole edge; the slide is monotone and
>    reaches an endpoint in a single step. No edge-following state is added.
> 4. **A1 is not touched.** Every datum the rule reads is already published. `branch_topology_digest`
>    does not move, and the grazing relation is **derived on demand and never stored** — storing it would
>    create a second authority for a fact `direction` already determines.
> 5. **T6 stays frozen and stays unreachable.** Grazing is classified at the outgoing side before any
>    entry point is set on an outflow edge of the entry face, so no well-formed state reaches `t* = 0`.
> 6. **A hard rail still wins.** If the grazing edge is a mandatory edge the trace terminates on first
>    contact at the point it met the edge, and is never slid along it.
> 7. **No new `FieldAlignedNetworkEventKind`.** A transit is not a network 0-cell, so CP3b's terminal-kind
>    exhaustivity assumption is untouched.
>
> **Measured, and reproduced independently from the committed fixtures alone:** the prescribed sphere has
> **72** grazing configurations on **72 distinct** edges (one per edge), the torus **120**; **zero** sign
> disagreements and **zero** zero-rates in all 192. The eight sphere singularities are the corners of an
> inscribed cube, each with exactly **3** grazing edges, and the grazing edges lie along the field's
> separatrix corridors — grazing is what the interesting part of the network looks like on this witness,
> not an exceptional pathology.

> **AMENDMENT 6 — "observable" is defined by mechanism, and proved by class**
> (`Architecture_M3_CP4c0_TB_R2_Review_Plan_Independent_Review.md` §9). Amendment 5 rule 2 required a
> locus to be "observable in the witness diagnostic string" and left *observable* undefined. Under that
> wording `branch=\x01` qualified — the byte is in the string — and `M3-CP4c-0-TB-R2` failed at ordinal
> 329 because `FieldBranch::value()` returns `std::uint8_t`, which stream insertion writes as a
> **character**. The typed authority was correct throughout; only the serialization boundary lost it.
> Amendment 5 constrained the *value* and said nothing about the *mechanism*, so the one locus that
> bypassed the `*_locus` formatter convention was unconstrained. **This replaces Amendment 5 rule 2.**
>
> A locus token is **observable** if and only if all four hold:
>
> 1. **Formatted, not inserted.** It is produced by a named `*_locus` formatter returning `std::string`.
>    Raw stream insertion of a typed authority's accessor is prohibited — that is precisely how a narrow
>    integer type becomes character-valued. The correct idiom already existed at
>    `FieldTransportAtlas.cpp:673`; nothing made it enforceable.
> 2. **Printable.** The complete emitted diagnostic contains only printable ASCII plus field separators.
>    **No control character, and in particular no NUL.** `FieldBranch::from_integer(0)` emits NUL;
>    `branch` is emitted *before* `parameter`; and `parameter` is the datum that discriminates the
>    sphere's failure route — so a NUL there truncates exactly what Amendment 5 exists to publish at any
>    C-string boundary.
> 3. **Parseable.** Each token round-trips: the emitted text uniquely determines the value.
> 4. **Site-sourced.** Amendment 5 rule 1, with its scope corrected: **every** locus field on **every**
>    error emitted anywhere in the tracing path is populated only from the failure site. Where a failure
>    genuinely occurs at the port, the port vertex is a legitimate `sourceVertex`; where the failure has
>    its own downstream site, the seed may not be substituted for it. Seed identity appears only under
>    `traceSeedVertex` / `traceSeedSingularity`.
>
> **And a rule about proof, which is the lesson of that turn:** every diagnostic-contract requirement must
> be falsified by a **class** identity quantifying over all codes and all emission sites, never by an
> instance identity over one hand-constructed error. Both defects found in `M3-CP4c-0-TB-R2` — the
> `std::uint8_t` formatting defect and ~15 surviving trace-seed back-fills that E1c's line-scoped wording
> never reached — were class defects that instance falsifiers passed over.
>
> **E6 bound, normative.** A2a keys cycle detection on the complete exact traversal state
> `(sourceFace, branch, incoming carrier, FieldBoundaryPoint)` and applies the saturating step bound
> `max(64, 8 × (sum of published frame branch counts) × (published transport count + 1))`.
> Repeating the complete state is `TraceStateCycleDetected`; reaching the bound is
> `TraceStepBudgetExhausted`. Both name the current face, branch, incoming carrier, exact entry
> parameter, completed-step count, and bound. Neither rejection may publish a clean terminal point.
>
> | Code | Fires when | Required loci |
> |---|---|---|
> | `TraceStateCycleDetected` | the complete exact traversal state repeats | `sourceFace`, `branch`, incoming edge, exact parameter, completed-step count, bound |
> | `TraceStepBudgetExhausted` | advancing would exceed the stated E6 bound | `sourceFace`, `branch`, incoming edge, exact parameter, completed-step count, bound |
>
> **E7 reachability annotations, normative.** `BranchContinuationNoOutflow`, the `|N| = 3` and
> `|M| > 2` forms of `BranchContinuationMinimizerImpossible`, and A1's
> `InvalidBranchBoundaryFlow` are unreachable from a valid nonzero exact barycentric direction:
> `Σd = 0` forces at least one positive and one negative coordinate, hence `1 ≤ |N| ≤ 2` and
> `|M| ≤ |N|`. Their focused falsifiers are unit-level checks over deliberately tampered directions;
> they are not production-reachability evidence.

---

## 11. The bounded next Code + Build turn — measures **Q**

`M3-CP4c-0-CB1`. Code + Build only; **runtime forbidden**.

### Q0 — binding preconditions

Stop and return to review if any fails.

- **Q0.1** `FieldBranchBoundaryPairing` still has `connections` and **no** direction field; `FieldFaceBranchFrame` publishes no per-face direction. If either is false this DEFN is stale.
- **Q0.2** `FieldAlignedCandidateTraceSegment` carries **no** position field.
- **Q0.3** `dbary` is `{-u - v, u, v}` (`FieldTransportAtlas.cpp:118`) and `SourceEdgeTopologyKey::make` swaps so `first() < second()` (`AuthorityKernel.cpp:19-28`). Both underpin §3.2 and §4.3.
- **Q0.4** `direction_in_vertex_sector` exists at `FieldTransportAtlas.cpp:388-412` and is the **only** sector rule in the codebase.
- **Q0.5** No test asserts an absolute digest constant. Re-verify; §6.2 depends on it.

### Q1 — A1 publishes the direction; delete `connections`

Add `FieldBranchDirection` with its `Σ = 0` construction check and typed rejection. Remove `connections` and `FieldBranchBoundaryConnection`. Update `branch_topology_digest`. **Do not touch** `intervals`, carriers, transport adjacency, port attachments, cycles, or effort.

### Q2 — A2a carries `FieldBoundaryPoint`

Add the type with its §3.2 projection and range check. Add the entry point to `FieldAlignedCandidateTraceSegment` and the terminus point alongside — **not replacing** — the existing terminal node.

### Q3 — the exact comparator, and its proof

Implement §4.3's cross-multiplication in exact arithmetic. **Author the exactness identity from §4.5 in the same turn**: a case where exact and `double`-division comparison disagree, asserting the exact predicate wins. **Without that identity the freeze is unproven and Q3 is incomplete.**

### Q4 — the continuation rule

Implement §4.2/§4.4 in A2a, replacing `field_aligned_outgoing_carrier`'s Cartesian lookup. T2 **must** call `direction_in_vertex_sector`; do not write a second sector test. Assert the containment invariant: the selected edge is always a member of the published `outgoingCarriers`.

### Q5 — identities and gate

Author the §4.5 falsifying witnesses plus the §10 rejection negatives. **Freeze the CP4c-0 identity count and names in the CB report**, then compute the gate as `316 + n`. It is **not** fixed here, by design.

### Q6 — the migration check

Re-run the accepted **316** unchanged. §6.3 predicts **316/316** with **no expectation edited**. Report any red with its identity and first typed rejection and **stop** — §6.5.

### Q7 — prohibited in this turn

No A2b change; no use of terminus parameters for `k ≥ 2` ordering (§8); no torus or mechanical work; no change to C4/C5 or the CP4c-1 318 selector; no new tolerance anywhere.

### Q8 — falsifiable predictions

1. Accepted **316/316** green, zero expectation edits.
2. The prescribed sphere reaches A2a and publishes a network — **24 traces**, from 8 index-1 singularities × 3 ports.
3. At least one sphere trace terminates on a trace/trace contact, producing a terminal `TraceIntersection` — which unblocks CP4c-1's C4/C5.
4. Face `1-2-5` with incoming `1-2` resolves to exactly one of `{1-5, 2-5}`, and the exit edge **flips** when the entry parameter is moved across the crossover.
5. The torus still publishes 0 traces; the mechanical still fails A1. Unchanged — they are not in scope.

Prediction 3 is the one that matters for the checkpoint chain. **If the sphere publishes a network but produces no terminal `TraceIntersection`, do not adjust anything — return to review**, because that would mean crash-on-contact still has no witness.

---

## 12. Standing stop conditions for CP4c-0

- a tolerance decides any topological outcome;
- `FieldBoundaryPoint` is written by anything but A2a;
- a second sector rule, a second continuation rule, or a second position convention appears;
- `NetworkNodeId` acquires positional meaning;
- an accepted identity requires an expectation edit;
- the exact comparator cannot be made exact for the observed magnitude range;
- `k ≥ 2` terminus ordering is implemented.

---

## 13. Accounting and exact successor

- accepted runtime authority: **M3 CP4ab 316/316**
- CP4c-1 required selector: **318**, unchanged by this turn
- stable regression accounting: **42 / 14 / 28**; produced-witness debt **5**
- M3 package count: **39**
- budgets: none — abolished 2026-08-25; this planning turn runs nothing

**Exact next: `M3-CP4c-0-CB1`** — Code + Build only, runtime forbidden. Execute Q0's preconditions and obey every stop condition, then Q1–Q8. Compile and package; execute nothing. Then `M3-CP4c-0-TB` on `316 + n`.

`M3-CP4c-1` remains open and blocked on CP4c-0. `M3-CP4c-2-DEFN` and `M3-CP4c-3-DEFN` remain blocked.
