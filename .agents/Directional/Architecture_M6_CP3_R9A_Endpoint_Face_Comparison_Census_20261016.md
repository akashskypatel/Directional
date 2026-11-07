# M6 CP3 R9A — endpoint face-comparison census (Definition)

**Turn:** `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` (rung 19a). **Authority:** RA-77.3 and the current `TODO.md`. **Static source:** `src/geometry/SurfaceCellTracing.cpp`, snapshot `b34c571768e2227a8ea2fed42e7b287e21e466eb`, run 38888296894, artifact 12040008801, ZIP SHA-256 `501523b30aaa1f53ed13fb57bb7e27b0d23f9398e2bd585d1920c69acfbcd957`, 5,672/5,672 internal hashes. A compare to turn-entry head `cd4a539e8aa0f518d6dfab1b95b940cd9205ff8e` changed only eight documentation/control files, not this source. Underlying semantic source remains `f0d7240455b10237af47de58c035cd4c576d889a`.

**Scope:** Former R9 questions 1 and 2 only. Enumerate endpoint face comparisons and producer guarantees. No replacement contract, soundness proof, repair, code, compile, runtime, selector change or implementation authorization. R9B is independently gated by review of R9A.

## Search coverage and classification

The search was `rg -n 'find_carrier|oriented_carrier|exact_corner|no.exact.terminal.corner|closed.chain|\\.face\\s*==|\\.face\\s*!=|\\.face\\s*\\)|\\.face\\s*,|\\.face\\s*\\]' src/geometry/SurfaceCellTracing.cpp` and `rg -n 'same_interior_carrier_point|matches_exact_source_corner|endpoint_certificate\\(' src/geometry/SurfaceCellTracing.cpp`. The entire endpoint constructor `19265–19495`, its two calls `19501–19507`, the independent checked-product verifier `8621–8736`, and rejected-only instrumentation `19507–19824` were inspected. "Needs face" below denotes genuine triangle incidence/chart/transport/sector data; "available handle" denotes a source-entity question answered by decoding the point's stored face and barycentrics. An operation can require both.

### Endpoint constructor, actual admission

| Location | Comparison or lookup | Classification |
|---|---|---|
| `19244–19252`, `19286–19287` | `find_carrier`: lookup solely by canonical `SourceEdgeTopologyKey`, `item.edge == edge` | **Not face-based**; the carrier's edge, not endpoint face, is the key. |
| `19277–19285` | Validate `fromPoint.face`/`toPoint.face`, map rows to `firstAttachment`/`secondAttachment` topology keys | **Needs a face** to decode a chart; its selection is merely an **available handle** for source-entity identity. Does not directly equate the two faces. |
| `19253–19261`, used at `19332–19334` and `19372–19388` | `oriented_carrier` demands its actual ordered source-face pair equal endpoint-derived attachment keys, or reverse; otherwise rejects | **Needs faces** for real A3 carrier orientation; whether the *point's chosen representative* must be that face is a separate, unproved demand. |
| `19299–19304`, `19341–19346` | Closed-chain or terminal-contact component compared to `component_for_row(*from/*to)` | **Available handle** for **component membership**, not exact face identity; valid face row remains needed for lookup. |
| `19309–19331` | Closed chain simple canonical vertex cycle, edge ownership, hard-feature edge keys | **Not face-based**; source-edge and chain ownership are independent requirements. |
| `19347–19366` | `exact_corner` scans `faces(point.face,i)` for designated `SourceVertexId` and requires exact one-hot barycentrics; vertex must terminate carrier edge | **Available handle** for source-vertex identity; **needs face** to decode barycentrics, **not** an identical incident face at both endpoints. |
| `64–97`, called `19374–19388` | `interior_carrier_parameter` decodes a point on named edge from local face corners and exact barycentrics; `same_interior_carrier_point` compares exact rational parameters | **Available handle** for canonical-edge membership/position, **needs chart** for decoding. Requires exact edge parameter, but does **not** compare raw face indices. |
| `19393–19422` | Builds source-face-keyed non-hard-rail A3 star adjacency using *actual incident faces* of source spokes | **Needs faces** for topological transport. Not an endpoint face-equality check. |
| `19425–19450`, used `19463–19466` | `path_to(firstAttachment, oriented.firstFace)` and symmetric second-side path require exactly one admissible face-keyed path | **Needs faces** for A3 sector routing; the start face is currently borrowed from the endpoint representation. Source-entity equality by itself does not establish that sector. |
| `19455–19494` | Carrier reversal; disjoint face-keyed sectors; rejects absent/ambiguous paths, overlapping sectors, ambiguous orientation | **Needs faces** to prove distinct topological sectors; endpoint-derived face remains the supplied start handle. |
| `19377–19385` | A3 presence, exact shared-boundary span/reciprocal ordinals, rail identity | **Not face-based**; separate admission evidence. |

Both endpoints use the same certificate: `19501–19503` on `(first.from, second.to, front edge)` and `19504–19506` on `(first.to, second.from, back edge)`. The decision branches at `19507`. No source-row equality `fromPoint.face == toPoint.face` occurs; the over-specific comparison is indirect through topology-keyed attachments and the carrier pair.

### Independent checked-product verifier (also active, not just diagnostic)

| Location | Comparison or lookup | Classification |
|---|---|---|
| `8621–8644` | `published_carrier` requires canonical edge, precise ordered face pair and A3 transport, and valid endpoint attachment rows | **Needs actual source faces** for independent carrier certification; does not equate point-face fields. |
| `8649–8660`, `8676–8683` | `exact_vertex_attachment` checks one-hot barycentrics for a source vertex decoded from `sourceFaces(point.face,i)` | **Available handle** for vertex identity; **needs chart** to decode. |
| `8662–8674`, `8729–8735` | Contact-free/interior endpoint insists `carrier.firstFace == endpoint.firstAttachment`, likewise second, and invokes exact `same_interior_carrier_point` | **Needs carrier faces** for orientation, but exact equality to the endpoint's representative face is a further admission condition; edge parameter equality is separate. |
| `8685–8699` | Independently recomputes unique terminal star paths from endpoint attachment faces to carrier faces | **Needs face-keyed A3 topology**; start derived from point chart. |
| `8701–8728` | Path continuation `step.firstFace == at`, distinct incident faces, A3 correspondence, final carrier face, nonoverlapping visited sectors | **Needs actual faces** for oriented topology/sector validation, not point-face equality. |

Junction verification from `8737` onward reasons about route-junction face sectors, **not** comparisons against the two endpoint corners. The rejected-only `matches_exact_source_corner` at `19518–19530`, source-vertex reporting at `19547–19560`, replays at `19769–19786`, and carrier/corner evidence at `19803–19817` never admit a failed candidate. The later `find_carrier` at `19830–19833` checks an intermediate route step by edge alone.

## Producer guarantees, measured limits, and missing promises

1. **Vertices:** A one-hot exact barycentric point resolves to a canonical source vertex ID by indexing its containing source triangle (`19347–19358`; `8649–8660`). Two different incident face rows can encode the same source vertex. RA-76.1 established all 48 measured `sampled_face=3` / `accepted_face=7` pairs are `SAME_ENTITY`: 42 × `vertex:4`, 6 × `vertex:2`. **Same vertex, not same source face or same A3 sector** is established.
2. **Edge points:** The canonical source-edge key is shared, but exact parametric identity is not established by the observed override population. RA-76.1's full differing set is **324/324** points on the **same canonical edge**, each edge parameter exactly **one ULP apart**; **zero** vertex-identity differences. `same_interior_carrier_point` (`91–97`) demands exact parameter equality and may reject such representations. This is a measured numerical discrepancy, **not a new acceptance tolerance** or proof that every one-ULP-separated pair is interchangeable. No epsilon is authorized.
3. **Face interiors:** A point strictly interior to its source triangle has a face-and-barycentric representation. The vertex and edge measurements do **not** establish equivalence for arbitrary different-face interior points; transferring barycentrics requires actual chart transport. Diagnostic encoding distinguishes `vertex:<id>`, `edge:<lo,hi>@<hexfloat>`, and `interior:<face>@<barycentrics>` at `17245–17273`; encoding is not itself an admission certificate.
4. **Published boundary:** The producer samples a bounded-disk chart and, at accepted boundaries, substitutes the **whole** accepted `SurfaceTracePoint` including its own face and barycentrics (`17291–17317`); it does not promise that face equals the chart sample's. RA-76.2 saw `override=1` on **all 2,628 measured nodes**, both controls and failures; override occurrence is not a discriminator. A source-entity-preserving representation change is distinct from a source-face-preserving one.
5. **Not promised:** Bit-exact cross-producer edge parameters; face identity for a shared vertex or source edge; equivalence of distinct face-interior points; A3 carrier-orientation/sector authority from source-entity identity alone; or sufficiency of a source-entity test for all the product-verifier's independent component, hard-edge, sector, interval and transport checks.

**Disposition:** R9A census only, no contract or repair. `RP-01` unresolved at the consumer, `RP-02` UNREACHED; gate C suspended. R9B is **not authorized until independent review of this census**. Ledger 66/17/49, M6 debt 1, CP2 491/491, R3 403/497, selector 497, and `R4-VIN-01` at `f0d724045` remain unchanged. No runtime acceptance is claimed.

**Transport note:** an attempted user-visible Library preservation upload returned `container_session_unavailable` even though the local source file existed. The GitHub direct-write exception was therefore used; no Google Drive staging/push is claimed.
