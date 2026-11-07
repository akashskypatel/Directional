# M6-CP3-CB1-ENTRY-R4 — terminal rail-contact binding and +U gauge witness: Review decision

**Type:** runtime-free Review adjudication of the R4 source-authority binding STOP.
**Disposition:** **Finding 1 ACCEPTED as a specification gap, resolved by option (C) below — neither (A) nor
(B).** **Finding 2 ACCEPTED as a refutation: RA-43.5's oracle was vacuous and is WITHDRAWN**, replaced by a
two-part witness. Frozen as **RA-44**. The R4 Code + Build turn is released to continue.

Read at HEAD `de0f9d4c1`. Every claim is a direct byte read re-derived in this turn.

---

## 1. RA-43.5 is withdrawn: the oracle I named cannot discriminate

`FieldFaceBranchFrame` (`include/directional/authority/FieldTransportAtlas.h:728-734`) holds
`std::vector<FieldBranchBoundaryPairing> branches` — **all four** branches, each with its own
`FieldBranchDirection`. There is no distinguished +U. So `find_frame(face)` offers four equally valid values
and comparing `sourceFaceBranchRotations[face]` against it decides nothing. That is a vacuous check of
exactly the kind LESSONS 171 names, and I froze it. Withdrawn.

The STOP is also right that the factory cannot re-derive the value: `make`
(`src/geometry/SurfaceCellTracing.cpp:7969-7984`) receives `sourceFaces` and `sourceVertexCount` but **no
vertices and no frame axes**, while the gauge's producer at `:11029-11054` selects `bestBranch` from
`project_tangent(axis_for_family(faceAxisX, faceAxisY, face, family, sign), normal).dot(frame.axisU)` under a
hard gate `bestAlignment >= 1.0 - 1e-8`, then cross-checks branch+1 against `frame.axisV` at `:11050-11054`.
The gauge is therefore a **pure function of (faceAxisX, faceAxisY, axisU, axisV, normal)** — none of which
crosses the factory boundary.

## 2. The non-vacuous witness needs two independent parts, and neither suffices alone

- **Absolute pin (geometric).** Per face, the asserted branch's family/sign axis, projected to the face
  normal, aligns with the certificate's own `axisU` under the identical `1 - 1e-8` gate A4 uses at
  `:11034-11043`, with the `axisV` cross-check at `:11050-11054`. This pins the **value**, because alignment
  is an absolute condition, not a relation. It requires `faceAxisX`/`faceAxisY` and the frame axes, so they
  **travel with the gauge**: the certificate carries its own derivation inputs.
- **Relational pin (A3).** Across each interior edge, the two faces' asserted branches differ by the atlas
  transport: `rotation[to] == rotation[from].rotated(transition_value(edge, from, to)->transport)`, reusing
  the accessor already written at `:7996-8009`.

**Why both.** The relational pin alone is **gauge-invariant** — a balanced `+1 mod 4` on every face satisfies
every edge relation, which is precisely the balanced tamper the STOP demands be covered, and precisely the
RA-40 reasoning that forbade using a commuting square as an authenticator. The absolute pin alone ignores A3
entirely and would accept a frame coherent with geometry but incoherent with the field. Together they are
non-vacuous: the balanced tamper is caught by the absolute pin, and an axis-aligned but field-incoherent
assignment is caught by the relational pin.

**Residual, recorded not blocked.** A4 selects an exact Z4 value with a `double` alignment predicate. The
factory must use the **identical** predicate or it would reject what A4 accepted, so this cannot be tightened
inside R4 without changing accepted CP2 behaviour. Logged as a tracked item; the hard `>= 1 - 1e-8` gate
makes it fail-closed, which is the correct structure even though the predicate is floating-point.

**Scope answers the STOP asked for.** Keyed by `SourceFaceTopologyKey`, so **row permutations** cannot
launder it. **Presence is mandatory whenever A6 seam logic consumes the gauge**; the only legal absence is
**total** absence — no gauge and no consumer — so this does not reopen the RA-40 conditional hole, which was
about the atlas. Periodic and isolation transformations are covered because the relational pin runs on the
atlas's own transitions, which already carry them.

---

## 3. Finding 1: the dataflow already exists. Option (C).

The STOP offers (A) pass the rail chain through the boundary, or (B) author a new A4 terminal-contact
certificate. Both are heavier than the facts require, because **the rails already reach this boundary**:

- `hard_feature_edge_keys_from_rails` (`src/pipeline/RemeshPipeline.cpp:9576-9599`) consumes
  `rail.sourceVertices` directly, converting each consecutive pair to a typed `SourceEdgeTopologyKey` via
  `surface_cell_source_edge_key` (`:3064`). The typed conversion RA-43.3 demanded **already exists and is
  already in use**.
- Its result is what becomes A4's `hardFeatureEdges`. At `:12173-12177` the pipeline takes
  `authoritativeRails = railProduct->rails`, reduces them to `hardFeatureRailEdges`, and at `:12178-12179`
  stores `productSnapshots.authoritativeRails = authoritativeRails` — **the rails are already carried in the
  surface-cell context.** Same shape at `:17031` and `:17715-17723`.

So the terminal contact is not missing authority and not a missing dataflow. It is the one datum the existing
reduction **discards**: `hard_feature_edge_keys_from_rails` keeps consecutive *interior* pairs and throws away
(i) which vertex is terminal and (ii) the `HardRailId -> endpoint vertex` association.

**Option (C), ruled:** publish a sibling reduction beside the existing one —
`hard_rail_terminal_contacts_from_rails(rails, vertexExtent)` — emitting, per `HardRailId`, the typed terminal
`SourceVertexId` pair taken from `rail.sourceVertices.front()` and `.back()`, skipping `closed` rails (which
have no terminal), carrying `rail.component`, and using the same existing typed conversion. Thread it to
`make` at the same three call sites that already thread the edge keys. This is the **seventh** publish/reach
instance and the strongest form yet: producer and consumer are already joined by a live call, so the change
widens a reduction rather than inventing a channel.

The contact is keyed by `HardRailId` and carries `component`, which answers the STOP's "front endpoint,
correct component/sheet" without any raw-int namespace equality and without geometric closeness.

**Fixture consequence, ruled.** The archived rail patch was held because hand-authored fixtures omit exact
chains. Under (C) that resolves itself: a fixture supplying hard features **through rails** gets contacts for
free, and a fixture hand-authoring `hardFeatureEdges` with no rail is asserting hard features with no
producer and must **fail closed**. That is the same ruling RA-40 made for tests manufacturing route
certificates without a source-bound atlas. The archived patch stays unapplied; (C) supersedes it.

`rail_sample_source_vertex` (`src/geometry/SurfaceCellTracing.cpp:5820-5844`) becomes deletable at the
endpoint use, because `front()`/`back()` are exact. RA-43.4 stands.

---

## 4. Code accepted this turn

`publish_phase_front_result` (`src/geometry/SurfaceCellTracing.cpp:12240-12250`) now reports
`PublishedProductRejected` and carries `publishedProductError`, ending the collapse of every factory
rejection into `InvalidFinalCellState`. **Accepted** — it discharges RA-42.3 at this locus.

Two soundness checks, both clean: `enum class SurfacePhaseFrontProductErrorCode : int;`
(`include/directional/geometry/SurfaceCellTracing.h:1689`) is an opaque declaration with a **fixed** underlying
type, so the type is complete and `std::optional` over it is well-formed, matching the definition at `:1809`;
and `std::get<SurfacePhaseFrontProductError>` cannot throw because the variant has exactly two alternatives
(`:1846`) and the `get_if` at `:12240` returns early on the other.

The seven two-face DCEL fixture repairs compiled but **were not executed**, so no restoration is claimed.

---

## 5. Disposition

Release R4 Code + Build to continue with RA-44 as its specification. No runtime ran, selector 497 untouched.
CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2 losses. Stable ledger **66 / 17 / 49**,
debt **1** — unchanged: a vacuous check frozen in a review document is a review defect, not a runtime
regression. RA-41's junction/sector clauses remain frozen **UNEXERCISED** and the multi-carrier STOP stands.
