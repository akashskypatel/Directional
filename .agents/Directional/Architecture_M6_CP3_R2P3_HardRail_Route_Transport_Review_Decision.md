# M6-CP3 R2-P3 — HardRail route transport: independent Review decision

**Type:** runtime-free independent producer-owned architecture Review, resolving the `M6-CP3-CB1-ENTRY-R2` stop.
**Decision:** **Option (b) APPROVED — A4-owned ordered route transport certificate, with singleton as the
degenerate case. Option (a), a singleton-only route contract, is REJECTED as unsound.**
**Frozen as RA-36.** No runtime credit is granted; every RA-34.3 organic stop gate stands.

## 1. The four decisive claims are confirmed from source

The review request's static findings were re-derived rather than accepted:

1. **A5's predicate is structurally singleton-only.** `rail_tau(fromFace, toFace)`
   (`src/pipeline/RemeshPipeline.cpp:4916-4957`) loops over **every** step of `first.route.steps()`, locates the
   `hardRailFieldTransitions()` record for `step.topology()`, and requires
   `record->firstFace == fromFace && record->secondFace == toFace` (or the swap); otherwise it returns
   `std::nullopt`. It is called as
   `rail_tau(from->…->placement.selectedFace, to->…->placement.selectedFace)`.
2. **A4 publishes per-edge records with no path.** `SurfaceHardRailFieldTransition`
   (`include/directional/geometry/SurfaceCellTracing.h:1477-1484`) is
   `{ edge, firstFace, secondFace, firstToSecond }` — one record per hard edge with its two *incident* faces and
   the oriented A3 τ. Nothing links records of distinct route edges, and there is no route-level τ.
3. **A4 has no one-step cap.** `observedSteps.push_back(step.value())`
   (`src/geometry/SurfaceCellTracing.cpp:11712`) appends one step per distinct retained source-edge topology with
   no cardinality bound, so A4 can emit multi-step routes.
4. **A5 selects endpoint faces from the trace, not the carrier.** `RemeshPipeline.cpp:4319-4337` takes each
   occurrence `selectedFace` from `canonicalTrace.face`.

**The consequence is a topological impossibility.** In a proper non-duplicate triangle mesh two distinct
triangles share at most one edge, so no two distinct source edges carry the same unordered incident-face pair.
A route with ≥2 distinct edges therefore cannot satisfy claim 1's predicate for more than one of its steps, and
deterministically yields `HardRailTransportMismatch` — a code asserting a **transport disagreement that was never
evaluated**.

## 2. Why option (a) is rejected

- **The invariant it needs does not exist.** A singleton-only contract must *prove* the producer emits only
  singleton paired cross-region HardRail routes in the supported domain. Claim 3 shows no cap. Option (a) would
  therefore not be documenting an invariant; it would be **adding a producer restriction** that narrows the
  supported domain.
- **The domain it would narrow is legitimate.** Two consecutive hard-feature edges `(1,4)` and `(4,7)` already
  exist as a real bounded producer input (`tests/SurfaceCellTransitionQuotientTests.cpp:694-759`). Polyline hard
  features are ordinary CAD geometry, not a pathology. Declaring them unsupported is a capability regression
  presented as a contract.
- **Decisively, it does not avoid the work.** Even under a singleton-only contract, the miscoded failure in §1
  must be fixed: a multi-edge route must reject with a typed *unsupported-route* code rather than claim a
  transport mismatch it never tested. Once A4/A5 are obliged to distinguish "multi-edge route" from "τ
  disagrees", publishing the route is strictly more informative than refusing to.

## 3. The actual architectural error, and the contract that follows

`rail_tau` conflates two different obligations and applies both to every step:

- **endpoint attachment** — the relation's two selected faces must attach to the route's ends;
- **transport agreement** — τ must be correct along the route.

Applying attachment at *every* step is what makes ≥2 steps impossible, and demanding equal τ at every carrier is
wrong in principle: τ along a path **composes**, it does not repeat. The correct decomposition is **attachment at
the two ends, composition through the interior** — under which a singleton route is simply the degenerate fold of
length 1. That yields one contract, not two.

### RA-36 (frozen by this Review)

**A4 publishes, per paired cross-region HardRail route, an ordered oriented transport certificate:**

1. the ordered sequence of `SourceEdgeTopologyKey` steps in canonical route orientation;
2. for each step, its two typed incident `SourceFaceTopologyKey` values and the exact oriented A3
   `firstToSecond` quarter-turn, copied/validated against `FieldTransportAtlas::transition_value`;
3. **endpoint attachment**: which face of the first step the `a` endpoint attaches to, and which face of the last
   step the `b` endpoint attaches to;
4. **path connectivity**: consecutive steps must share exactly one typed source face.

**A5 consumes only that published certificate.** It composes `τ_ab` as a typed fold along the published path
(`Z4` addition with per-step orientation; reversed steps negate), verifies that the relation's two
`placement.selectedFace` values equal the published endpoint attachment faces, and then applies the already
frozen `(B_b − B_a − R_coord − τ_ab) mod 4 = 0` at **both** endpoint pairs. The reverse relation must invert
coordinate, branch and τ orientations together; orientations may not be mixed.

**Consistency obligations.** For consecutive carriers both side transports come from A3 source-face transition
authority, and the cross-rail square `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i` must hold. Compose as a typed path — **never**
average, never demand equal τ per carrier, never select the first step. A4 rejects, typed and fail-closed, on:
absent or ambiguous path, disconnected face star, nontrivial singular holonomy, nonreciprocal A3 transitions, or
a mismatching hard-feature owner. A5 must **not** infer path, attachment or τ from regional `F` gauges, sheet
labels, geometric proximity, arbitrary graph traversal, first-step selection, fabricated records, or any new
unreviewed configuration switch.

**Singleton is the degenerate case and must not regress.** Path length 1; attachment faces are that edge's two
incident faces; composed τ is its `firstToSecond`. Existing singleton behaviour must be preserved exactly — the
frozen `497 = 30 + 12 + 449 + 6` gate and every currently green identity are the regression guard.

**Honest failure codes.** A route A4 cannot certify must reject with a typed code naming *that* cause. Reusing
`HardRailTransportMismatch` for an uncertifiable or unsupported route is prohibited: it asserts an evaluation
that did not happen.

## 4. What this decision does not establish

It settles which contract governs; it does not assert that any produced multi-edge HardRail route exists. No
such route has been demonstrated — the two-hard-edge fixture declares inputs, it does not prove A4 emits a
spanning reciprocal route. **If the bounded search yields no multi-edge produced positive, the multi-edge path
code is unexercised and must not be cited as validated**; the same discipline that governed the degenerate
nonzero-Z4 witness at `M5-CP3-DEFN-R1` applies here.

All RA-34.3 R2-P3 stop gates remain mandatory and are unaffected by this decision: an independently generated
baseline-green HardRail witness with **odd τ ∈ {1,3}**, `F_b − F_a ≠ τ`, a sign-inversion negative, and
reciprocal/face-permutation invariance. If the bounded real-producer search yields none, **stop for Review**.

## 5. Verification limits

Re-derived from repository bytes: `rail_tau`'s per-step predicate and its call with selected faces; the
`SurfaceHardRailFieldTransition` record shape; the uncapped `observedSteps.push_back`; the trace-derived
`selectedFace`; and the two-hard-edge fixture's existence. The topological argument (two distinct triangles share
at most one edge) is a property of proper non-duplicate triangle meshes, assumed as the supported input domain.
Not established: existence of any produced multi-edge HardRail route, or of a qualifying odd-τ witness.
