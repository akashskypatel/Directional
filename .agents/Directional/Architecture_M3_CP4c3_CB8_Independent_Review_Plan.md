# M3-CP4c-3 CB8 Independent Review + Plan — Exact Transit Authority Gap

**Turn:** `M3-CP4c-3-CB8-REV`
**Type:** Independent Review + Plan only
**Runtime/build boundary:** no Directional runtime, compile, package mutation, test, benchmark, fixture, selector,
or product-code edit.

## 1. Purpose

Adjudicate the architectural stop raised by `M3-CP4c-3-CB8`. CB8 proved that current A1/A2a products carry exact
face-local branch derivatives and exact branch correspondence, but no exact/certified transform that projects one
arbitrary incoming tangent ray through a general non-coplanar vertex fan. The review must decide what authority is
missing and freeze one bounded successor. Do not merely restate Amendment 17.

## 2. Required evidence to review

1. `Architecture_M3_CP4c3_CB8_Code_Build_Report.md`.
2. `Architecture_M3_CP4c3_TB6_Independent_Review_Record.md` §§3–5.
3. `DESIGN.md` Amendments 16–19, especially Amendment 17's allowed single-writer choices.
4. Exact current contracts in `FieldTransportAtlas.h/.cpp`, `SurfaceCellTracing.h/.cpp`, and
   `SourceChartTransitions.h`.
5. CB6's world-space transport attempt and TB5's Amendment-18 rejection.
6. The mechanical vertex-30 witness and the minimal exact fan witness.

## 3. Questions that must be answered

### AR1 — What exactly is the datum?

Choose one semantic authority, not a family of equivalents:

- an incoming geometric ray at the arrival event;
- the ray's exact exit/owner in an intrinsic vertex-star chart; or
- an upstream continuation owner published before candidate election.

State its single writer and its lifetime.

### AR2 — What exact/certified representation is sufficient?

For the chosen datum, determine the smallest representation that can prove a unique half-open fan-sector owner on
non-coplanar meshes. Evaluate at least:

- an intrinsic unfolded vertex-star chart with an exact/certified predicate;
- an exact algebraic or adaptive-predicate representation over source geometry;
- a continuation-owner representation that avoids carrying a geometric ray at all.

Do not assume GMP rationals alone can represent the needed rotations. If a certified filter is proposed, specify the
exact fallback and prove that the filter cannot change the exact answer.

### AR3 — Which stage owns the new authority?

Decide whether the representation belongs in:

- `FieldTransportAtlas` / branch topology;
- a new derived vertex-star transport product;
- the upstream branch-continuation result; or
- another existing single-authority product.

Avoid duplicating authority between A1 and A2a.

### AR4 — What does the mechanical witness actually require?

Reconstruct vertex 30 using the committed fixture and show how the proposed authority would distinguish the two old
candidate faces without candidate ordering, target-local cross representatives, tolerance, or `FaceInterior`
cardinality changes.

### AR5 — What is the bounded implementation and regression plan?

Freeze one successor Code + Build turn with:

- exact changed owner(s);
- minimal API/data-contract additions;
- a regression identity that demonstrably fails under `incomingDirection = nextPairing->direction`;
- production diagnostic fields sufficient to audit datum -> projection -> election;
- selector-374 append conditions;
- static stop rules before compile;
- runtime-free GMP compile/package contract and next artifact-only TB plan only if the implementation exists.

## 4. Prohibited conclusions

Do not authorize any of the following as the semantic correction:

- `nextPairing->direction` as the transported datum;
- `signedLift` as an exact arbitrary-ray rotation;
- world-space `double` transport feeding a topological decision;
- epsilon/tolerance changes to sector ownership;
- candidate ordering, first-candidate choice, nearest-angle, or magnitude tie-break;
- barrier traversal or `FaceInterior` cardinality changes;
- appending the current weak minimal witness to selector 374 before it falsifies the old mechanism.

## 5. Required output

Produce an independent review record that either:

1. freezes a concrete exact/certified authority and one bounded successor CB turn; or
2. proves a deeper design amendment is required and routes to that definition/review boundary.

The review must leave ordinal 370, sphere, saturation, accepted selector 365, and frozen selector 373 untouched.
