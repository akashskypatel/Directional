# M6-CP3-R4 — terminal-A3 and terminal-sector first-rejection reachability: REVIEW DECISION

**Adjudicates:** `Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md` (`R4-TA3-01`).

**Disposition: the REVIEW STOP is DISSOLVED. Both of RA-49.7's remaining unadjudicated negatives are now
adjudicated and BOTH are RETIRED, coupled to named guards.** `missing-or-nonreciprocal-terminal-A3` is
unreachable (Review A/B). `overlapping-terminal-sectors` is **also** unreachable, by a different and
independent argument (Review C). Both guards are **kept fail-closed**. No runtime credit. Ledger
**66 / 17 / 49**, M6 debt **1**, unchanged. Selector **497** untouched; CP2 **491/491** accepted; R3
**403/497** rejected with 94 RED and 88 accepted CP2 losses.

**The request is the best-constructed stop of this series.** It states a *conditional* inference, explicitly
refuses to claim universal unreachability, names its own counterexample class, and asks the one question that
decides the matter. That is the correct shape for a feasibility stop. Both of its provisional inferences are
confirmed, and its one framing error is minor and stated in §6.

---

## 1. Review A — the ingress census, and the distinction that decides it

**There are exactly two public A4 ingress variants.** The primary
`build_surface_cell_network(vertices, faces, faceAxisX, faceAxisY, targetSize, options, …)` at
`src/geometry/SurfaceCellTracing.cpp:18743`, and the convenience overload at `:20011`, which computes axes
from the cross field and **delegates to the primary** on both of its branches. The gate therefore dominates
every path to the terminal loop.

**No atlas built for a distinct source can pass the gate.** The chain is a two-sided row-by-row pin:

- **Build side.** `FieldTransportAtlas::make` (`src/authority/FieldTransportAtlas.cpp:1893`) requires
  `sourceAuthority.matches_source_faces(sourceMesh.F, |V|)` at `:1909-1910` before anything else, and then
  fills `rowTopology_[row] = sourceAuthority.topology_for_row(row)` at `:1926`. So `rowTopology_[row]` **is**
  the `SourceFaceTopologyKey` of `sourceMesh.F.row(row)`.
- **Consume side.** `:18756-18764` sets `network.sourceTopologyRegions` to an authority that **always**
  satisfies `matches_source_faces(faces, …)`: a supplied authority that does not match is silently **replaced**
  by one built from `faces`, so no path carries regions inconsistent with `faces`. Then `:18771-18774`
  requires `atlas.matches_source_faces(faces, regions, |V|)`, which requires
  `rowTopology_[row] == regions.topology_for_row(row)` for **every** row
  (`FieldTransportAtlas.cpp:3101-3108`), and `SourceTopologyRegions::matches_source_faces`
  (`include/directional/geometry/SourceTopologyRegions.h:151-188`) requires `regions.topology_for_row(row)` to
  equal the key of `faces.row(row)` for every row.

Composing: **`key(faces.row(r)) == key(sourceMesh.F.row(r))` for every `r`.** A `SourceFaceTopologyKey`
determines the triangle's three vertex IDs, hence its three undirected edges, so `faces` and `sourceMesh.F`
induce the **same undirected edge set with the same per-edge face incidence**. There is no "same regions,
different edges" atlas.

**The distinction the request asked for: non-traversable ≠ missing value.** In `make`'s edge loop, a one-face
edge is recorded `SourceBoundary` and `continue`s **before** any value is published (`:2008-2013`); a two-face
edge with no cross-field transition fails `MissingAdjacency` (`:2016-2018`); wrong face ownership fails
`NonReciprocalAdjacency` (`:2020-2027`); and only then
`transitionValues.push_back(FieldTransportTransitionValue{…})` runs at **`:2039-2042`**, which is **before**
the `HardFeature` (`:2043-2047`) and region/component `NonTraversable` (`:2048-2054`) categorizations. A
barrier classification therefore **never withholds a transition value**. `nontraversableEdges` is a separate
list; `transitionValues` is complete for every two-face edge.

## 2. Review B — `missing-or-nonreciprocal-terminal-A3` is UNREACHABLE

The predicate (`src/geometry/SurfaceCellTracing.cpp:19099-19105`) is a three-way disjunction: `!forward`,
`!reverse`, or `reverse->transport != forward->transport.inverse()`. Six links close all three.

- **H1 — build-time pin.** `FieldTransportAtlas.cpp:1909-1910` and `:1926` (above).
- **H2 — consume-time pin.** `SurfaceCellTracing.cpp:18756-18764` and `:18771-18774` (above). On every path to
  `:19105` the atlas is non-null; a null atlas rejects earlier and differently at `:19079`
  (`missing-source-A3`).
- **H3 — the edge table is a function of `F`.** RA-48.3 has **landed** (commit `785dd7398`, 2026-10-12
  16:07Z) and is **stronger than specified**: `TriMesh::set_mesh`
  (`include/directional/core/TriMesh.h:331-351`) now calls `compute_edge_quantities(verbose)`
  **unconditionally**, then, if any of `_EV`/`_FE`/`_EF` was supplied, requires it to be **bit-identical** to
  the derived table or **throws** `"set_mesh(): injected edge topology disagrees with faces"`. R4-OVF-01 is
  closed. **Consequence for RA-48.1: guard G1 is now unconditional, so the overfull obligation does NOT
  revive — it is held strictly more tightly than when RA-48 froze.** The DCEL throw is intact at
  `TriMesh.h:160-163`.
- **H4 — every two-face edge has a value, unconditionally** (`:2039-2042` before categorization, with
  `MissingAdjacency` at `:2016-2018`). H1∧H2∧H3 ⟹ every two-face spoke `edge_faces(faces)` yields is a row of
  `sourceMesh.EV`; H4 ⟹ it has a value. The consumer has already skipped the only two exceptions —
  boundary spokes (`incident[0] < 0 || incident[1] < 0 → continue`) and hard-feature spokes
  (`hardFeatureEdges.contains(spoke) → continue`). **`!forward` and `!reverse` cannot fire.**
- **H5 — `reverse` is computed, never supplied.** `FieldTransportAtlas.cpp:2033-2034`:
  `const QuarterTurn reverse = forward.inverse();`. One immutable record holds both, and
  `directed_transition_value` (`:910-922`) returns `value.forward` for `(first,second)` and `value.reverse`
  for `(second,first)`. The consumer's third disjunct therefore compares `value.reverse` against
  `value.forward.inverse()` — **equal by construction**. Not unobserved: **unrepresentable**.
- **H6 — one seam, no mutators.** `FieldTransportAtlas`
  (`include/directional/authority/FieldTransportAtlas.h:837-900`) exposes `make` as its only producer, no
  public constructor and no mutator, only a defaulted `operator<=>`. There is no copy-and-remove path.

**Verdict: RETIRE the `missing-or-nonreciprocal-terminal-A3` fixture obligation, coupled to H1–H6.** If any of
H1–H6 is weakened the obligation **revives**. The guard at `:19099-19105` is **kept fail-closed** — it is the
only backstop should a future route obtain an atlas other than through `make`.

## 3. Review C — `overlapping-terminal-sectors` is ALSO UNREACHABLE

Adjudicated separately, as the request correctly demanded, and by an unrelated argument.

- **K1 — the paired front edges are in different A2b regions.** `:18892`
  (`if (first.sourceTopologyRegion == second.sourceTopologyRegion) continue;`) dominates the certificate call.
- **K2 — a front edge's trace faces lie in its own region.** All three front-edge constructors take the
  enclosing traced region (`:12946`, `:14686`, `:17257`: `SurfaceFrontEdge edge(region.id(), cell.id)`), and
  the per-region tracers enforce face membership explicitly (`:12380`, `:14920`, `:17538-17539`:
  `region_for_row(row) != region.id()` rejects). K1∧K2 ⟹ **`firstAttachment != secondAttachment`**.
- **K3 — every face has degree ≤ 2 in the local star.** The star is built only from spokes with exactly two
  incident faces: `> 2` rejects at `:19091` (`nonmanifold-terminal-star-spoke`, itself retired by RA-49.6) and
  `< 2` (boundary) `continue`s. Each face at the vertex carries exactly two spokes at that vertex, so its
  degree in `localStar` is at most 2. **A graph of maximum degree 2 is a disjoint union of paths and cycles.**
- **K4 — a cycle component yields ambiguity, not overlap.** `path_to` requires `count == 1`
  (`:19137`); on a cycle there are two simple paths, so it returns `nullopt` with `pathCount > 1` and the loop
  ends at `ambiguous-terminal-A3-path`, never at overlap.
- **K5 — both orientations are tried** (`:19143`).

**Proof.** Work in a path component with the carrier's two faces at its ends, ordered `F1 … F2`. Write
`p = firstAttachment`, `q = secondAttachment`. The un-reversed orientation walks `p → F1` and `q → F2`; these
closed intervals intersect **iff `p` is at or after `q`** in the `F1 → F2` order. The reversed orientation
walks `p → F2` and `q → F1`; these intersect **iff `p` is at or before `q`**. Both overlap **iff `p == q`**,
which K1∧K2 exclude. If `p` and `q` lie in different components, at least one target is unreachable and the
loop ends at `missing-terminal-A3-path`. **No input yields `overlapping-terminal-sectors`.**

**Verdict: RETIRE the `overlapping-terminal-sectors` fixture obligation, coupled to K1–K5.** Guard **kept
fail-closed**. Weakening K1 (the pairing region-distinctness) or K3 (the incidence bound) **revives** it.

Note the structural echo of RA-50.5: the mis-ordered-attachment case is absorbed by the second orientation,
exactly as the global attachment swap is absorbed there. The certificate's side symmetry is the same symmetry
in both results.

## 4. One hypothesis checked, no defect reported

The consumer's `localStar` (`:19081-19110`) excludes only `hardFeatureEdges` and so **admits** steps across
region/component seams the atlas classified `NonTraversable` (`FieldTransportAtlas.cpp:2048-2054`). If the
factory re-derivation used a different rule, a certificate the consumer accepted would be rejected by
`make` — a producer/validator disagreement. **It does not.** `unique_terminal_star_path`
(`SurfaceCellTracing.cpp:8395-8430`) applies the same rule: `incident.size() > 2` invalid,
`hardFeatureEdges.contains(spoke)` skipped, `incident.size() != 2` skipped, then `transition_value` plus
`matchesA3`. Consumer and factory **agree**: the terminal star is cut by **rails only**. This is recorded as a
deliberate design, not a finding, so it is not re-raised as one.

## 5. New finding — `R4-TA3-02 / DEAD_DISJUNCT` (architectural, no runtime credit)

Two reciprocity tests are dead by construction, and naming them is a forward constraint, not a cleanup
request:

- `reverse->transport != forward->transport.inverse()` (`SurfaceCellTracing.cpp:19103-19104`) — dead by H5.
- `compose(forward, reverse) != QuarterTurn{}` (`FieldTransportAtlas.cpp:2035-2038`) — dead for any correct
  `QuarterTurn::inverse`.

Both are harmless as fail-closed guards and **stay**. The constraint is on RA-46.6: **a typed sub-code may not
be minted for a disjunct that cannot fire.** Splitting `missing-or-nonreciprocal-terminal-A3` into a "missing"
and a "nonreciprocal" sub-code would manufacture a fresh unsatisfiable fixture obligation of exactly the kind
this decision just retired twice. Sub-code work must separate **reachable** predicates only.

## 6. The request's one framing error

Step 4 groups RA-48.3 with RA-49.7's unadjudicated list. RA-49.7 left two **feasibility** questions open —
`overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3`. RA-48.3 was never one of them: it
is an **implementation** obligation, and it had already **landed** at the request's own snapshot (ancestor
`785dd7398` of `0240d0f00`). Its landing is not a parallel open item; it is the link (H3) that closes the
forged-edge-table route the request was right to worry about. The distinction matters because an
implementation obligation discharges by code, while a feasibility question discharges only by review.

Its line citations also predate RA-50's prepend: `Architecture_M6_Frozen_Definitions.md:157-163` no longer
points at RA-49.7. Cite frozen clauses by RA number, never by line — RA-50.8 already required this for source.
