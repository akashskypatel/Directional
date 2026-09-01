# M3-CP4c-3 CB8-REV — Independent Architecture Review and Definition Route

## 0. Verdict

**Turn:** `M3-CP4c-3-CB8-REV`
**Type:** Independent Review + Plan only
**Verdict:** **COMPLETE / CB8 ARCHITECTURAL STOP UPHELD / DEEPER DEFINITION REQUIRED / NO SUCCESSOR CB AUTHORIZED**

This review independently re-derives CB8's stop from exact current source authority and resolves the review-plan
questions AR1–AR5. It does **not** authorize an implementation retry. The missing piece is not only a numeric
representation: the project has never normatively defined how one incoming ray continues through a general
non-coplanar, non-flat source-vertex star. Choosing a number type before defining that geometry would turn an
architectural ambiguity into code.

No Directional runtime, compile, package, benchmark, test, fixture, selector, or product-code change was performed.
Selector **373** remains byte-frozen and selector 374 still does not exist. Ordinal 370, the prescribed sphere,
saturation, accepted selector 365, and all accepted predecessor authority remain untouched.

Static inspection authority for this review is the verified source snapshot at branch authority
`882dccf2d3984b06c18bcb22de143bfaff3ceb55`. CB8's semantic source remains
`0d943f95b42e49813060399e83a1e4180e8348f6`; intervening CB8 closeout/control commits did not change the product,
test, fixture, or selector semantics described below.

---

## 1. Evidence re-established independently

### 1.1 The executed defect remains one representative per candidate cell

`resolve_field_vertex_transit` carries a `TransitState::incomingDirection`, but after crossing a fan adjacency it
transports only the branch label through the atlas `signedLift`, finds the target face's pairing, and assigns:

```cpp
incomingDirection = nextPairing->direction;
```

The exact half-open sector predicate then tests that target-local value. The arithmetic is exact; the semantic datum
is not single-authority. This is exactly the defect prohibited by `DESIGN.md` Amendment 17.

### 1.2 Current A1 authority cannot transport an arbitrary ray

The exact A1 payloads distinguish two different things:

- `FieldBranchBoundaryPairing::direction` — one exact **face-local branch representative**; and
- `FieldBranchTransportAdjacency` / `FieldDirectedBranchTransport` — branch correspondence by quarter-turn and
  integer signed lift, plus floating diagnostic effort.

None contains an exact or certified tangent-space transform for an arbitrary geometric ray. `signedLift` can map a
branch identity; it cannot rotate a continuous ray. `SourceChartTransitionGraph` is topological and similarly has
no tangent metric transform.

The nearby physical transport helper uses world-space `double` normalization/rotation/projection. CB6 already
proved why that path is inadmissible for a topological decision under Amendment 18: exactifying the final floating
result does not restore an exact derivation chain.

### 1.3 The production diagnostic loss is real but downstream

`FieldAlignedCurveNetworkError::vertexTransitStates` retains detailed exact state/election rows. The production
projection in `RemeshPipeline.cpp::network_failure_locus` / `SurfaceCellFailureLocusDiagnostics` drops them. That is
still a real evidence-surface defect (`M3-CP4c3-TB6-CAND-01`), but publishing more rows for the currently invalid
per-cell datum cannot repair Amendment 17 and must follow the semantic authority definition.

---

## 2. AR1 — freeze the primitive datum

The primitive datum is **one exact incoming geometric ray anchored once at the vertex-arrival event**.

Conceptually:

```cpp
struct VertexStarRaySeed {
    SourceVertexId sourceVertex;
    SourceFaceId arrivalFace;
    FieldBranchId arrivalBranch;
    FieldBranchDirection exactArrivalDirection;
};
```

The names are descriptive, not an implementation mandate. The contract is the important part:

1. A2a's exact branch-continuation event writes the seed **once**, at the instant the trace reaches a source vertex.
2. The direction is the same exact face-local branch direction that drove that arrival; it is not regenerated from
   a candidate face.
3. The seed remains immutable until the vertex-transit decision produces one owner or one typed non-owner outcome.
4. Target-face branch representatives may be recorded as audit data, but they are never substitutes for the seed.

The alternatives named by Amendment 17 — "geometric exit from the star" and "upstream continuation owner" — are
best understood as **derived outputs of this same datum**, not independent primitive authorities. Publishing an
owner earlier in the call graph does not make its derivation exact; it merely moves the missing predicate upstream.

---

## 3. AR2 — the representation question exposes a missing semantic definition

### 3.1 Intrinsic star development is the correct reference model to define

The smallest geometry that can make the Amendment-17 question meaningful is an **arrival-anchored intrinsic
vertex-star development**:

1. order the admissible incident-face fan from source topology and barrier policy;
2. anchor the arrival face and its ray once;
3. isometrically unfold neighboring face sectors about their shared radial edges into one developed chart;
4. continue the one seeded ray in that chart;
5. apply the existing exact half-open sector convention to the developed sectors;
6. return one owner or a typed geometric non-owner state.

This is a *reference semantics*, not yet an implementation authorization. It prevents a hidden seam, candidate
ordering, or target-local field representative from becoming semantic authority.

### 3.2 Plain `FieldExactRational` is not a sufficient general construction type

The source coordinates originate as IEEE doubles and can be treated as exact dyadic rationals, but a general
isometric hinge development needs metric quantities such as lengths, normalizations, and rotations. Even from
rational squared lengths those constructions generally introduce square roots/algebraic quantities. The current GMP
rational type is therefore not closed under the required general operation.

The repository also contains no current exact algebraic-number kernel or adaptive predicate with a proved exact
fallback for this vertex-star decision. The atlas's floating `effort`, the world-space `double` transport helper,
and exactification of a floating result are all inadmissible under Amendment 18.

### 3.3 Three implementation families remain viable, but DEFN must choose one

The next definition turn must compare and freeze one of these *exactly equivalent semantic* implementations:

- **Exact developed chart:** represent the constructible/algebraic geometry required by the unfolded fan and test
  sector ownership exactly.
- **Direct exact predicate:** compute the discrete owner/no-owner/multi-owner result from source geometry and the
  seed without materializing every developed vector, while proving it implements the same reference semantics.
- **Certified filter + exact fallback:** permit floating/interval evaluation only when it proves the answer; every
  inconclusive case must defer to one of the exact paths above. "Inconclusive means fail" is not an exact fallback
  and does not satisfy Amendment 18.

An **owner-only representation** can be the public output, but it does not avoid this derivation. If the owner is
computed from candidate-local representatives, face order, nearest angle, a tolerance, or an approximate ray, the
same defect is merely hidden behind a smaller type.

### 3.4 Non-flat stars require an explicit product state

Unfolding a non-flat cone is not automatically a partition of one Euclidean plane. Depending on the intrinsic angle
sum and the seeded ray, the developed sectors can leave a gap or overlap. A continuation can therefore have no
admissible owner or more than one developed owner under a straight-through interpretation.

The current design does not say what those cases mean. Amendment 21 forbids inventing topology or resolving an
exact ambiguity by arbitrary choice. Consequently DEFN-R2 must decide whether each case is:

- a named `RegularizableDegeneracy` with one exact deterministic policy and disposition effect; or
- a typed fail-closed deficit.

That decision is semantic architecture, not an implementation detail, and is the reason a successor CB is not yet
safe to issue.

---

## 4. AR3 — freeze ownership without duplicating A1

The new geometry belongs to **A2a vertex transit as one derived authority**, not to A1 branch correspondence and
not to every candidate cell.

The minimal ownership split is:

- **A0** continues to own exact source support/topology.
- **A1 `FieldTransportAtlas`** continues to own cross-branch identity and edge transport/lift. It is not silently
  redefined as an arbitrary-ray metric transport.
- **A2a branch continuation** writes the one `VertexStarRaySeed` at a vertex arrival.
- **A2a vertex-star transit authority** consumes A0 geometry + immutable A1 topology + that seed and writes exactly
  one `VertexTransitOwnerCertificate` (or one typed non-owner result). Candidate enumeration is only the set being
  tested; it is not a writer of the datum.

This can be implemented as a small A2a-local derived object/helper rather than a new global pipeline stage. DEFN-R2
must freeze its public contract and exactness certificate before any code turn decides its internal representation.

---

## 5. AR4 — mechanical vertex 30 remains a valid falsifier, but not yet an owner oracle

The committed mechanical fixture reconstructs source vertex **30** as one closed, consistently oriented six-face
fan. In fan order:

1. row 43 `(24,30,32)` — arrival face, excluded by `FaceInterior`;
2. row 40 `(24,25,30)`;
3. row 41 `(25,30,31)` — old candidate A;
4. row 208 `(30,31,119)` — old candidate B;
5. row 209 `(30,119,123)`;
6. row 218 `(30,32,123)`.

The vertex is regular, not barrier-absorbed, and not barrier-incident. Candidate A and B are adjacent and share the
source ray `30→31`. Their raw-field branch-vector families are disjoint under every quarter-turn gauge, so the old
algorithm demonstrably evaluates **two different local rays**.

The proposed authority changes the cardinality question fundamentally: there is one developed seed coordinate and
A/B are disjoint half-open sectors of the same developed fan. One coordinate cannot be owned by both merely because
each face has a locally admissible cross representative. The exact owner — A, B, another sector, or a typed
geometric non-owner — is **not frozen by this review**, because naming it before DEFN-R2 defines the development
would repeat the same authority error in prose.

A non-authoritative static sanity calculation from the committed coordinates gives a six-angle sum of `2π` to the
precision of the source doubles, consistent with the fixture being an extrinsically folded but intrinsically flat
star. That observation makes vertex 30 especially useful, but it is not accepted as an exact proof and does not
replace the required exact regression.

---

## 6. AR5 — no CB yet; selector 374 remains blocked

The current minimal identity
`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` proves that exact state is
published. It does **not** prove that one seed is tested against one common fan, and therefore does not falsify:

```cpp
incomingDirection = nextPairing->direction;
```

Selector 373 remains exactly 373 lines with SHA-256
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`. No selector 374 may be created until a
new/strengthened identity fails under the old target-representative mechanism and passes only under the frozen
single-seed authority.

A good future falsifier is a **non-coplanar but intrinsically simple folded fan** with an exact known sector owner
under the DEFN-R2 semantics and deliberately different target-face branch representatives. The fixture must prove
its own fan/precondition and half-open boundary convention. Exact coordinates and assertions are **not** frozen in
this review; DEFN-R2 must derive them rather than accept an approximate sketch.

---

## 7. Exact successor — `M3-CP4c-3-DEFN-R2`

Under the user-authorized cadence, `DEFN` is itself the combined definition + review/plan turn. The exact successor
is therefore:

**`M3-CP4c-3-DEFN-R2` — DEFINITION + REVIEW/PLAN only.**

It must discharge measures **AX0–AX9**:

**AX0 — frozen preconditions.** Preserve accepted 365, frozen selector 373, TB6/package-75 evidence, CB8's
architectural stop, stable accounting `44 / 14 / 30`, debt `5`, semantic-package count `73`, and all deferred
ordinal-370/sphere/saturation authority. No runtime, compile, package, product, test, fixture, or selector mutation.

**AX1 — datum and lifetime.** Normatively define the one arrival-anchored `VertexStarRaySeed`: orientation/sign,
source-face chart, exact source provenance, writer, lifetime, and what information is diagnostic-only. One seed per
vertex-arrival event; never one per candidate.

**AX2 — vertex-star geometry.** Define the arrival-anchored intrinsic fan/development semantics over source
triangles, including fan order, chart orientation, barrier truncation, source-boundary handling, and the exact
meaning of "straight continuation through the vertex". State the semantic reference independently of any numeric
kernel.

**AX3 — curved/degenerate stars.** Classify exact gap, overlap, boundary-ray, and other non-unique/no-owner cases.
For each, choose typed fail-closed versus `RegularizableDegeneracy`, and if regularizable define the exact
certificate/disposition effect. No arbitrary seam, candidate order, nearest-angle, or invented topology.

**AX4 — exact/certified kernel.** Choose the smallest representation/predicate that implements AX2/AX3. If a
certified filter is allowed, name the exact fallback and prove that the filter cannot change the exact result. Plain
GMP rational hinge rotation, float transport followed by exactification, and "filter inconclusive => reject" are
not sufficient.

**AX5 — owning contract.** Freeze the A2a single-writer API/data contract. A1 remains branch-topology authority;
A2a owns one per-arrival seed and one owner/non-owner certificate. State exactly which existing function(s) may
consume the new authority and which old per-candidate derivations become diagnostic-only or are removed from the
decision path.

**AX6 — mechanical proof.** Reconstruct vertex 30 against the frozen semantics and prove how one seed yields one
certificate. The proof must not use candidate order, target-local cross representatives, tolerance, or a changed
`FaceInterior`/barrier rule. If the exact semantics produce a typed non-owner, that result must be accepted as the
proof rather than overwritten to force the current expected candidate.

**AX7 — regression identity.** Derive an exact non-coplanar folded-fan witness whose expected owner/non-owner is
known from AX2. Prove it fails under `incomingDirection = nextPairing->direction`. Only then authorize strengthening
or replacing the current minimal identity and appending exactly one ordinal 374 while preserving selector 373
byte-for-byte.

**AX8 — audit contract.** Freeze the production diagnostic fields for seed → fan/development/predicate → election:
seed identity/provenance, exact/certified representation identity, fan traversal/development certificate, per-sector
exact outcome, final owner cardinality/result, and typed degeneracy/failure reason. Then the later CB may close
`M3-CP4c3-TB6-CAND-01` at the projection boundary.

**AX9 — successor gate.** DEFN-R2 may issue a bounded Code + Build successor only after AX1–AX8 are internally
complete and one exact implementation route is feasible. Otherwise it must stop again at definition. It may not
compile or execute Directional itself, may not touch ordinal 370/sphere/saturation, and may not weaken Amendments
17/18/21.

If AX0–AX9 close, DEFN-R2 should issue the later CB's implementation measures under a **new** measure prefix rather
than silently recycling CB8's AW measures.

---

## 8. Regression/accounting disposition

- `M3-CP4c3-TB3-R1-CAND-01` remains **ACTIVE**, now classified as a **definition + representation authority gap**:
  the per-cell-representative cause is proven, while the exact semantics of a general vertex-star continuation are
  not yet defined.
- `M3-CP4c3-TB6-CAND-01` remains **ACTIVE / owner proved**, but its correction is blocked behind AX1–AX8 because
  production diagnostics must publish the *correct* datum/certificate, not richer rows for the old one.
- No new stable regression is created. The defect is on an unaccepted CP4c-3 surface and accepted 365 remains green.
- Stable totals stay **44 events / 14 categories / 30 recurrences**; produced-witness debt stays **5**; semantic M3
  packages stay **73**.

## 9. Falsifiable prediction for the next implementation cycle

After DEFN-R2 eventually authorizes an implementation, the first valid semantic package must make the strengthened
folded-fan identity distinguish the old and new mechanisms **before** it is admitted to selector 374. On the
mechanical production witness, every candidate-sector diagnostic must reference the same seed/certificate identity;
there must be no target-cell rewrite of the decision datum. A failure to establish either fact returns to Review,
not to a tie-break or tolerance adjustment.
