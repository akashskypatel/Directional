# M6-CP3 R3 — P0/P1 endpoint-local attachment and transport: independent producer Design Review decision

**Type:** runtime-free independent producer Design Review resolving the remaining `M6-CP3-CB1-ENTRY-R3` STOP.
**Decision:** **BLOCK RESOLVED — frozen as RA-39.** Endpoint-local **attachment** requires **no new authority**;
the **transport paths** require one new published field whose content is derivable from RA-38's sector cut.
The current `endpoint_certificate` is categorically wrong in shape, and the fix makes it *smaller*, not larger.
No runtime credit; all RA-34.3 and RA-36.4/.5/.6 gates stand.

## 1. What the endpoint pairs actually are

`src/geometry/SurfaceCellTracing.cpp:18271-18285` requires `first.route == second.route.reversed()` for the
reciprocal pair. Therefore `first.from` and `second.to` lie at the **same spatial end** of the rail polyline, and
`first.to`/`second.from` at the other. The two calls
`endpoint_certificate(first.from.face, second.to.face)` and
`endpoint_certificate(first.to.face, second.from.face)` are consequently **cross-rail pairs, one per spatial
end** — each pair holding one face on each side of the rail at that end.

This is the fact the current implementation does not use. At `:18297-18330` it sets `current = firstAttachment`
and then walks **every** route carrier accumulating τ, attempting to travel from one side's face at one end,
across the whole polyline, to the other side's face. That is neither a local crossing nor a well-defined path.
It is the same end-to-end "walk along one side" shape that produced the superseded RA-36.1 defect, now visible at
the endpoint level.

## 2. Endpoint-local attachment is derivable with no new authority

For endpoint pair `j`, the **terminal carrier** is the route's first (`j = 0`) or last (`j = 1`) oriented step —
well defined because `CanonicalRoute::oriented_steps()` is ordered. Attachment is then:

```text
valid(j)  ⟺  { from_j , to_j }  ==  { C_j.firstFace , C_j.secondFace }   (as an unordered pair)
χ_j       =   C_j.firstToSecond, oriented by which of the two faces is from_j
```

where `C_j` is that terminal carrier's already-published `SurfaceHardRailFieldTransition`
(`include/directional/geometry/SurfaceCellTracing.h:1477-1484`). **No path walk, no threading, no new producer
input.** If the pair is not the terminal carrier's incident pair, there is **no local attachment** and the
certificate fails closed — which is precisely RA-37a's prohibition on "treating a path reaching the opposite
spatial endpoint as a local attachment."

Consistency with RA-38 on the reviewed 3×3 fixture: route `[(1,4), (4,7)]` gives terminal carriers `(1,4)` with
faces `{0,3}` and `(4,7)` with faces `{4,7}`. RA-38's sector cut places `0, 4 ∈ A` and `3, 7 ∈ B`, so **each
endpoint pair holds exactly one face per sector** — one per side of the rail, as a cross-rail pair must.

## 3. The transport paths belong to the square, not to the crossing

The within-sector radial chains are **not** needed for an endpoint crossing — that is a single carrier. They are
needed only for RA-37a's along-rail square, which *compares* the two endpoint mappings after explicit transport:

```text
χ_1 ∘ φ_A  =  φ_B ∘ χ_0
```

with `φ_A` transporting the side-A face from carrier `C_0` to carrier `C_1` **within sector A**, and `φ_B`
likewise within sector B, along **non-rail** A3 transitions. On the fixture: `φ_A : 0 → 1 → 4` and
`φ_B : 3 → 6 → 7` — exactly RA-38's two arcs. Path-independence across admissible chains within a sector, and
rejection on nontrivial holonomy, carry over from RA-38 unchanged.

## 4. The schema gap is real, and the correction shrinks the certificate

`SurfaceHardRailRouteEndpointCertificate`
(`include/directional/geometry/SurfaceCellTracing.h:1488-1493`) is
`{ firstAttachment, secondAttachment, orientedSteps, composedTurn }`, where `orientedSteps` is a vector of
**carrier crossings only** and `composedTurn` is a single end-to-end fold. Two things follow:

- **`orientedSteps` and `composedTurn` are the wrong shape.** An endpoint certificate concerns **one** terminal
  carrier, so it needs that carrier and its oriented crossing `χ_j` — not every carrier and not an end-to-end
  composition. The correction *removes* state.
- **There is nowhere to publish the radial witnesses.** The struct has no field for per-junction, per-sector
  ordered **non-rail** A2b source-edge transitions. This is the genuine gap the STOP record identified, and it
  is correctly described there as "not fixed by renaming the existing fields."

## 5. RA-39 (frozen by this Review)

- **RA-39.1 — attachment.** For endpoint pair `j`, the terminal carrier `C_j` is the route's first/last oriented
  step. The certificate is valid only if `{from_j, to_j}` equals `{C_j.firstFace, C_j.secondFace}` as an
  unordered pair, and `χ_j` is `C_j.firstToSecond` oriented by which face is `from_j`. Any other pair → typed
  fail-closed "no local attachment". No path walk is performed at an endpoint.
- **RA-39.2 — sector agreement.** Each endpoint pair must hold exactly **one face per RA-38 sector**. A pair with
  both faces in one sector, or either face outside the junction star when a junction exists, fails closed.
- **RA-39.3 — transport.** A4 publishes, per junction and per sector, the **ordered non-rail A2b source-edge
  witnesses** of the within-sector radial chain joining consecutive carriers' same-side faces. These exist only
  to serve the square; they are never used as an endpoint crossing.
- **RA-39.4 — the square compares.** Validation applies `χ_1 ∘ φ_A = φ_B ∘ χ_0` as a **comparison after explicit
  transport**. Blind composition of χ across carriers remains prohibited, as does any end-to-end `composedTurn`.
- **RA-39.5 — schema.** Replace the endpoint certificate's `orientedSteps`/`composedTurn` with the single
  terminal carrier and its oriented `χ_j`, and add the RA-39.3 radial witnesses. A5 consumes only this published
  immutable certificate — no path search, no sheet/region label inference, no first-step selection.
- **RA-39.6 — singleton degenerates correctly.** For a one-carrier route both endpoint pairs share that carrier,
  there is no junction, `φ_A`/`φ_B` are identity and the square is trivially the reciprocity already required.
  Existing singleton behaviour must not change.

## 6. What this decision does not establish

It settles attachment, transport ownership and the certificate's shape. It does **not** establish that A4
produces a paired HardRail front over a multi-carrier route; a hand-authored input fixture is not a produced
certificate. If the bounded real-producer search finds none, the multi-carrier path stays **unexercised and must
not be cited as validated**. All RA-34.3 R2-P3 stop gates stand — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`, a
sign-inversion negative, reciprocal/face-permutation invariance — and an empty search **stops for Review**.
Diagnostic-first-locus inside `invalid_route()` is still required before any corrective semantic edit.

## 7. Verification limits

Re-read from source: the reciprocal `route == route.reversed()` requirement and both `endpoint_certificate`
call sites; the walk-all-carriers accumulation at `:18297-18330`; the endpoint and carrier struct definitions;
`CanonicalRoute::oriented_steps()` ordering. Carried from RA-38: the mechanically derived star cycle and sector
arcs for the reviewed fixture. Not established: existence of a produced multi-carrier paired front.
