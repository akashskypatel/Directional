# M6-DEFN-R5-R4-REV — producer locus for terminal contact, germ and face gauge: Review decision

**Type:** runtime-free Review adjudication discharging `R4-REV-01A`, `R4-REV-01B`, `R4-REV-02A`.
**Disposition:** the three independent-review findings are **ACCEPTED**; the remedy they demand
("name the exact producer symbol and source-line path") is **DISCHARGED HERE** from repository bytes.
**Consequence:** RA-41 freezes, scoped to the singleton terminal contact. Junction/sector clauses stay
unexercised and uncredited. No runtime, no promotion, no Code + Build in this turn.

Read at HEAD `fe372dded`. Every claim below is a direct byte read, re-derived in this turn.

---

## 1. Accepted against my own prior review

**R4-REV-01A accepted.** `include/directional/geometry/SurfaceCellTracing.h:95-116` declares
`SurfaceCellRailSample::sourceFace`/`sourceEdge` as raw `int` and `SurfaceCellRail::sourceVertices`/
`sourceEdges` as `std::vector<int>`. My word "typed" in RA-42.1 was wrong. Sharper than the finding
states: `sourceEdge` is a **local corner index in [0,3)**, proved by its own guard
`sample.sourceEdge >= 3 → -1` (`src/geometry/SurfaceCellTracing.cpp:5824`) and by
`vertexCorner == sample.sourceEdge → -1` (`:5841`), which only type-checks if both are corner indices.

**R4-REV-01B accepted, and it is worse than a stale citation.** `railFanPotentials` **does not exist
anywhere in `src/` or `include/`**, and `git log -S` finds it only in my own architecture documents. It
was never a symbol. RA-38.5 and RA-42.4 cited a function that never existed. Struck, not relocated.

**R4-REV-02A accepted.** `SurfacePhaseFrontProduct::make` (`src/geometry/SurfaceCellTracing.cpp:8015-8020`)
checks `sourceFaceBranchRotations` for cardinality against `face_count()` and for values in `[0,4)`. That
is a range check, not provenance. One defect beyond the finding: the leading `!sourceFaceBranchRotations.empty() &&`
means an **empty** gauge passes unchecked — absent-is-accepted, the exact optionality RA-40.1 just removed
for the atlas.

**"Never use a caller's own gauge as an independent gauge oracle"** is correct and is adopted verbatim.

---

## 2. Rejected in part: a false citation is not a false claim

The re-review rewrote RA-38.5 to "a valid vertex-star producer must be identified and demonstrated" and
annotated RA-42.4 likewise. Accepting the citation defect does not warrant deleting the architectural
claim, and the claim is **true**. The producer exists, is typed, and is named here.

- `resolve_field_vertex_transit` — `src/geometry/SurfaceCellTracing.cpp:1257`.
- Its star loop — `:1452-1476`: iterates `topology.transports()`, **filtered to adjacencies incident to
  `sourceVertex`** (`:1453-1454`); steps face→face across `adjacency.sourceEdge` (`:1456-1462`); appends
  the typed `SourceEdgeTopologyKey` to `transportPath` and accumulates
  `composedSignedLift += directed->signedLift` (`:1473-1476`), i.e. τ mod 4 along the walk.
- Frontier — `pending` seeded at `:1376`, advanced by cursor at `:1382`, extended at `:1516`: a BFS over
  `(face, branch)` states around the vertex.
- Per-face sector — `vertex_star_sector` at `:1053`, returning `VertexStarSector` (`:1042-1051`) with
  `SourceFaceTopologyKey sourceFace` and typed `nextRadialVertex`/`previousRadialVertex`.

So RA-38.5's substance stands exactly as frozen: **only the carrier cut is missing**, and the cut is a
`continue` on carrier membership inside the loop at `:1452` — no new state, no new τ definition, no A5-side
search. The germ is BFS reachability in that loop with the incident carriers cut.

---

## 3. The decisive new finding: the terminal-contact owner is in the wrong stage

`SurfaceCellRail::sourceVertices` is **not** authored in A4 at all. It is authored in the pipeline layer:

- `src/pipeline/RemeshPipeline.cpp:9328-9356` — seeds from `ordered[run.front()].startVertex`, then for each
  `OrderedCurveEdge entry` pushes `entry.endVertex`, **enforcing continuity** with
  `rail.sourceVertices.back() != entry.startVertex → fail_edge(...)` (`:9335`) and closure with
  `front() != back() → fail_edge(...)` (`:9353`).
- `OrderedCurveEdge::startVertex` is a plain exact `int` (`:9306`), assigned at `:9401`.
- Single-edge rails: `rail.sourceVertices = {edge.vertices.first, edge.vertices.second}` (`:9491`).

Two consequences, both load-bearing:

1. **The chain is exact, not epsilon-derived.** The worry that the rail's own vertex chain might be
   reconstructed geometrically is refuted: it comes from the curve network's own edge endpoints and is
   continuity-checked. So an authenticated terminal contact *is* constructible.
2. **RA-42.1 named the owner in the wrong place.** A4's endpoint certificate cannot reach
   `SurfaceCellRail` — the rail is built by the pipeline from `featureMap.edges`, downstream of and lateral
   to `SurfacePhaseFrontProduct`. "Publish, don't invent" therefore resolves here as **bind at the factory
   boundary**, on the finished RA-40 precedent, not as "A4 reads the rail".

This is why the contact was "unproven": the owner was misidentified, so no dataflow could be shown.

---

## 4. Namespace inventory — four, not one

A raw `int` equality across any two of these is not a topological claim:

| Value | Namespace | Evidence |
|---|---|---|
| `SurfaceTracePoint::face` | raw source-face row | header `:90-93` |
| `SurfaceCellRailSample::sourceEdge` | **local corner index [0,3)** | `:5824`, `:5841` |
| `SurfaceCellRail::sourceEdges` | **feature-edge index into `featureMap.edges`** | `RemeshPipeline.cpp:9348` |
| component mesh rows | component-local renumbering | `MeshComponents.cpp:72-116` |

`rail_sample_source_vertex` (`src/geometry/SurfaceCellTracing.cpp:5820-5844`) crosses the first two by
`std::abs(value - 1.0) <= 1.0e-8` on barycentric coordinates and is live at `:5868` and `:5937-5938`. Under
RA-42.2 that is prohibited; it is therefore an existing **defect**, not merely a pattern to avoid.

---

## 5. Gauge authentication is constructible inside the RA-40.1 boundary

The oracle is already bound. `FieldTransportAtlas::branch_topology()`
(`include/directional/authority/FieldTransportAtlas.h:874`) exposes `FieldBranchTopology`, whose
`find_frame(const SourceFaceTopologyKey &)` is public at `:800` and yields the canonical per-face branch
frame — "gauge-invariant Z4 branch value in a canonical source-face frame" (`:52`). So per-face
authentication of `sourceFaceBranchRotations` needs **no new input**: it is the `matchesA3` shape already
written at `:7996-8009`, applied per face instead of per transition. Sixth occurrence of publish/reach.

---

## 6. Disposition

RA-41's review gate asked Review to "either accept a source-exact implementable authority path or return
this candidate as an architectural blocker." A source-exact path now exists for both clauses — RA-41.1 via
§5, RA-41.2 via §3 and §2 — so the gate is discharged and RA-41 freezes **restricted to the singleton
terminal contact**. Its junction/sector clauses have zero produced instances (38 printed rows are one
physical singleton carrier; the 39th is receiptless) and are frozen as **unexercised**: they may not be
cited as validated, and R4's multi-carrier STOP stands undischarged.

No runtime ran. Selector 497 untouched. CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2
losses. Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1** — unchanged, because a
review-evidence defect in my own documents is not a runtime regression.
