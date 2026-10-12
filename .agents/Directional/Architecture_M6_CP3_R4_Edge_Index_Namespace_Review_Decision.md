# M6-CP3-R4 — source-edge index namespace: Review decision (RA-47)

**Turn:** `M6-CP3-R4-EDGE-INDEX-NAMESPACE-ARCH-REV` (independent Review).
**Request adjudicated:** `Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`.
**Verdict:** finding **R4-IDX-01 CONFIRMED**; **both** proposed repairs **REJECTED**; **RA-47 FROZEN** in their place.
**Method:** every decisive claim re-derived from repository bytes at `fdeb06b3f`. No binary built, no test executed, no runtime credit.

---

## 1. R4-IDX-01 is confirmed, and its counterexample is sound

The reported conflation is real and the ordering table is correct.

- **Producer publishes a `featureMap.edges` position.** `src/pipeline/RemeshPipeline.cpp:9349-9359` indexes
  `featureMap.edges[entry.edgeIndex]` and pushes **that same integer** into `rail.sourceEdges` in the same
  iteration. The standalone path at `:9502-9503` does likewise. Decisive: the index-use and the store are the
  same expression, so no reinterpretation is available.
- **`featureMap.edges` is lexically ordered.** `include/directional/geometry/AdaptiveFeatureMap.h:181-207`
  builds `std::map<std::pair<int,int>, std::vector<int>> edgeFaces` keyed on `canonical_edge(a,b)` and emits
  `map.edges` by iterating that map — i.e. ascending `(min,max)` vertex pairs.
- **`TriMesh::EV` is halfedge-traversal ordered.** `include/directional/core/TriMesh.h:160-172`: `EV.row(i)` is
  taken from `dcel.edges[i]`, in DCEL first-encounter order, and is **oriented** `(halfedge.vertex,
  halfedge.next.vertex)` rather than canonical.
- **Counterexample stands.** For one face `(0,1,2)`: `featureMap.edges` = `(0,1), (0,2), (1,2)`; `EV` =
  `(0,1), (1,2), (2,0)`. A genuine rail on `(0,2)` is published as `1` and read back as `(1,2)`.
- **Consumer reads it as an EV row.** `src/geometry/SurfaceCellTracing.cpp:4233-4245` bounds-checks
  `declaredEdge` against `sourceMesh.EV.rows()` and compares `EV(declaredEdge,*)` to the typed key.

The request was right to stop. It was right not to convert silently inside Code + Build. It was also right that
a fixture using only `(0,1)` — where the two orders coincide — proves nothing.

---

## 2. Two findings the request did not make

### R4-IDX-02 — the field carries **three** namespaces, not two; the digest hashes whichever is present

`RemeshPipeline.cpp:17471-17476` builds `globalEdgeByVertices` mapping a typed key to a **global
`sourceMesh.EV` row**. `:17579-17593` builds `globalEdgeByLocal` indexed by **component-local `EV` row** and
valued with that global row. `:18106-18114` then rewrites `rail.sourceEdges` through it.

So the same field means **featureMap position** at the producer, is **read as a component-local EV row**, and is
**written as a global EV row** — and `:2043` and `:10005` feed it to the rail provenance digest
(`hash_vector(seed, rail.sourceEdges)`, immediately after `hash_vector(seed, rail.sourceVertices)`).

**Consequence that decides this review:** the request's own preferred repair — "an EV-index contract is a
plausible repair because field-aligned validation and component remap already use EV" — is **insufficient as
stated**. The component remap does not *use* one EV namespace; it *changes* namespace. Freezing "EV" leaves the
field's meaning dependent on whether component decomposition ran, and leaves the digest hashing a
path-dependent integer. A single frozen contract repairs the instance and preserves the class.

### R4-IDX-03 — the two structural checks on this field are vacuous

`SurfaceCellTracing.cpp:4209-4212` and `:5937-5938` constrain only `sourceEdges.size()` against
`sourceVertices.size()`. The §1 counterexample satisfies both: a wholly foreign index vector of the right
length passes. These validate the **duplicate's length**, never its referent — LESSONS-171, "structural
presence is not behavioural coverage." They are not a defence and must not be cited as one.

---

## 3. The decisive fact: `sourceEdges` has no genuine index consumer

Complete census of `SurfaceCellRail::sourceEdges` (all uses in `src/`, `include/`, `tests/`):

| Site | Use of the value |
|---|---|
| `SurfaceCellTracing.cpp:4233-4245` | **only** value consumer: derives the typed key from `sourceVertices`, then asks the raw index to agree |
| `SurfaceCellTracing.cpp:4209-4212`, `:5937-5938` | cardinality only (R4-IDX-03) |
| `RemeshPipeline.cpp:2043`, `:10005` | hashed into the provenance digest |
| `RemeshPipeline.cpp:9907` | compared against itself for determinism |
| `RemeshPipeline.cpp:9365`, `:9534-9536` | **diagnostic** `failedEdgeIndex`, feature-map namespace |
| `RemeshPipeline.cpp:18106-18114` | namespace translation (R4-IDX-02) |

No site consumes it as an index into a table it needs. The one value consumer performs a **round trip**: the
typed key is already in hand at `:4223-4225`, the raw index is dereferenced, and the result is compared back to
that same key. The round trip adds exactly one failure mode and zero information.

Three further bytes make this conclusive:

1. **Every hand-authored fixture derives the field from the typed key.** `tests/GlobalConformityBaselineTests.cpp:170`
   and `tests/GlobalConformityPlanTests.cpp:171` call `source_edge_index(mesh, barrier.sourceEdge)`, which
   linearly scans `mesh.EV` for the row matching the key it already holds. `tests/FieldAlignedCurveNetworkTests.cpp:492-494`
   does the same, having just written `rail.sourceVertices` from the two endpoints of that key.
2. **A namespace-free path already exists and works.** `RemeshPipeline.cpp:9588-9599`
   `hard_feature_edge_keys_from_rails` derives typed `SourceEdgeTopologyKey` values from `rail.sourceVertices`
   and **ignores `sourceEdges` entirely**. A4's `hardFeatureEdges` has always been fed this way.
3. **The digest already covers the authoritative datum.** `:2042` hashes `sourceVertices` on the line before
   `:2043` hashes `sourceEdges`.

**`sourceEdges` is a derived raw-int duplicate of `sourceVertices`, maintained in three namespaces, validated
only by length, and re-converted to the typed form at its single point of use.** That is RP-01
`AUTHORITY_DOMAIN_CONFLATION` in its pure form. RA-43 §4's inventory was an accurate description of a defect,
not a contract worth preserving.

---

## 4. Why both offered options are rejected

- **Option "freeze EV, convert the producer through a `(vertex pair) -> EV row` map":** adds a conversion table
  to manufacture a value that is then converted back at `:4233`. Leaves R4-IDX-02 (the remap still translates
  local to global), leaves R4-IDX-03, and leaves a raw int whose correctness must be independently maintained in
  three places. Rejected.
- **Option "keep the feature contract, give both EV consumers authenticated feature-map lookup evidence":**
  strictly more machinery around the same duplicate, and it would push feature-map identity into A4, which holds
  no feature map. Rejected — and note it repeats the RA-42.1 stage-locus error.

Neither option can be made non-vacuous, because there is no predicate either can run that `sourceVertices`
does not already decide.

---

## 5. RA-47 — FROZEN

**RA-47.1.** `SurfaceCellRail::sourceEdges` (`include/directional/geometry/SurfaceCellTracing.h:113`) becomes
`std::vector<authority::SourceEdgeTopologyKey>`. The raw-int edge namespace is **abolished** for this field.
RA-43 §4's row for `SurfaceCellRail::sourceEdges` is **superseded**: it recorded an observed defect, and the
other three rows of that table stand unchanged.

**RA-47.2.** The producer builds each entry from the endpoints it already validated —
`entry.startVertex`/`entry.endVertex` at `:9356-9360`, `edge.vertices.first`/`.second` at `:9502-9503` — via the
existing `surface_cell_source_edge_key` (`RemeshPipeline.cpp:3064`). No feature-map lookup, no EV scan. The
`sourceVertices` continuity check at `:9346` remains the sole authority for chain validity.

**RA-47.3.** `failedEdgeIndex` and `coveredEdges` **stay** feature-map indices and are sourced from
`entry.edgeIndex` directly. `:9365`'s `fail_edge(rail.sourceEdges.back())` must be rewritten to carry the last
feature index explicitly; it must **not** be reconstructed from a typed key. Diagnostic and topological index
spaces are never merged.

**RA-47.4.** `:18106-18114` is **deleted**, not converted. `:18093-18104` already remaps `rail.sourceVertices`
through `component.originalVertices`; the typed keys are rebuilt from the remapped chain immediately after. The
rails' dependence on `globalEdgeByLocal` ends with it. This is what closes R4-IDX-02 — the field acquires no
namespace to be translated between.

**RA-47.5.** `:4233-4245` collapses to a typed equality against the key derived at `:4223-4225`. The
`EV.rows()` bounds check and the `EV` dereference are removed. `InvalidRailGeometry` is retained and must not
be weakened; it now fires on a genuine topological disagreement rather than on a namespace artefact.

**RA-47.6.** The digest terms at `:2043` and `:10005` hash `first().index()` then `second().index()` per key,
matching the existing barriers pattern at `:9576-9580`. **The digest value changes.** No test pins a literal
digest (verified: no `railDigest`/`provenanceDigest` literal in `tests/`), and `:9907`/`:10005` compare
in-run products against each other, so no frozen identity depends on the old bits. Any future comparison
against a stored baseline must be re-derived, never back-fitted.

**RA-47.7 — the obligation that makes this non-vacuous.** A positive fixture on a mesh where the lexical
feature order and the DCEL EV order **differ**, carrying a rail on an edge whose two indices are unequal. The
single face `(0,1,2)` with a rail on `(0,2)` is sufficient and is hereby named as the minimum. A fixture
confined to `(0,1)` is explicitly disallowed as evidence. Required negatives, each verified at its **first
rejecting predicate**: a foreign typed key with correct cardinality (must reach `InvalidRailGeometry`, which
R4-IDX-03 shows the current code cannot do); a key whose endpoints are not an edge of the source mesh; a
closed rail whose final key does not close the chain; and a component-decomposed run whose remapped keys must
equal the single-component run's keys for identical geometry (the direct R4-IDX-02 falsifier).

**RA-47.8.** `tests/SurfaceCellREPackageTests.cpp:292-298` becomes a typed equality and thereby becomes
non-vacuous for the first time. `tests/MilestoneBClosureTests.cpp:142`'s literal `{0,1,2,3}` must be re-derived
from the fixture mesh's own vertex pairs; the test **identity** is preserved, the literal is not evidence. The
`source_edge_index` helper in `GlobalConformityBaselineTests.cpp` / `GlobalConformityPlanTests.cpp` is deleted
as an orphan of this change — the fixtures already hold `barrier.sourceEdge` and pass it directly.

**RA-47.9.** This is the eighth M6 instance of the publish-don't-invent family and its **dual**: the first seven
(RA-34.3, RA-35, RA-38, RA-40, RA-42, RA-44.1, and RA-43 as relocated) say *reach or publish what the producer
already holds*; RA-47 says *do not carry a second encoding of what you already publish*. Both reduce to one
test — can the added datum separate anything the authoritative datum cannot? Here, demonstrably not.

**RA-47.10 — no credit.** Nothing here is a runtime claim. The first observable failure, its count and the
affected frozen identities remain **unmeasured**. R4-IDX-01/02/03 are source-level review candidates, **not**
counted stable regressions: ledger stays **66 events / 17 categories / 49 recurrences**, debt **1**. Baselines
unchanged: CP2 **491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses.

---

## 6. Liveness is an open question, not a defence

Whether `:4233-4245` currently rejects producer-built rails on the default path is **not established** by this
review and was not established by the request. Two readings remain open: the consumer is not reached with
producer-built rails, or it is reached and rejects. Either way RA-47 is correct, so the adjudication does not
wait on it — but the implementing turn must **report which**, because a consumer that has never seen a
producer-built rail is itself an RP-02 `TEST_AUTHORITY_COVERAGE_GAP` and would be a separate finding.

---

## 7. Separate finding: destruction of the durable tracker

`0e1909d31` replaced `.agents/Directional/Regression_Root_Cause_Tracker.md` **in full** — 12,147 lines reduced
to 11 — with a single R4-IDX-01 entry. The tracker is the append-only durable ledger that every frozen RA
decision cites for its evidence base; replacing it severs those citations. The content was recoverable from
`497064965` and has been restored, with the R4-IDX-01 entry preserved and prepended as `0e1909d31` intended.
Recorded here as an architectural finding because the ledger is itself a durable artefact of the design, not
because of how the commit was made.
