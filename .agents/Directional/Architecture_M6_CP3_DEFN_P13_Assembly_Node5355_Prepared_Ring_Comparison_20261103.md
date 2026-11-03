# P13-j — Prepared arrangement is one ring; completed boundary keys diverge (2026-11-03)

**Canonical turn** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`, still **in progress**. This is a scratch-only diagnostic and source audit, **not** a production repair, gate acceptance, selector change, or authorized successor. Supersedes no prior observation; read alongside the same-day three-fan witness and breakpoint report.

## Exact independent evidence

- **Immutable base** CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca`.
- **Isolated diagnostic branch** `agent/p13j-diagnostic-first-vertex-20261103` source `41b87026a479d0a67b5f5fdf10fd159e0d3962cf` (one environment-gated logging block in `PatchDescriptor.cpp` plus the prior logging block in `PureQuadCompletion.cpp`). This branch is required to compile diagnostics without modifying working-branch production semantics or immutable CB78. Do **not** merge diagnostic changes.
- **Mandatory GMP/GMPXX compile** reusable Actions workflow [run 41571602244](https://github.com/akashskypatel/Directional/actions/runs/41571602244), exact dispatcher event `191e54dc550bdbcc4fe5125ee19346bd80dcd7aa`, successful source `41b87026…`; immutable package artifact **13201383249**, outer ZIP SHA-256 `d059116652e496dcd45c44aaef564377e7837da417a32d6cc8cc6b31ccefc167`; log artifact **13201965932**, outer ZIP SHA-256 `f171fd1537b538c1081c94f3f510fd8555333fe57cad130d572c60c2548cf0d5`. Package SHA256SUMS verified. No build or modified project binary created in local container; source edits are on isolated scratch ref, workflow compiled them with GMP.
- **Runtime** exact CB78 Vase fixture `milestone_g_manifest.json` case `vase__surface_cells`, `DIRECTIONAL_P13J_SCRATCH_WITNESS=1`, compiled binary SHA256 unchanged before/after `3bd0210c0e8a8c399716ee60ccc350945cdb28e4bf50ca6fd225791d66a2f4e2`. Elapsed **284.112 s**, benchmark `success=false`, original `NonManifoldStitchedVertex` still present; one complete P13K and one complete P13J marker block. Process exit 0 **is not case success**.
- Source-independent parser re-read the **eight actual incident directed halfedge records**, independently checked all four twin pairs reciprocal and orientation-reversed (zero bad twins), and derived the following exact cell adjacency; no invented edge or inferred twin.

## Prepared graph — node 5355

Node 5355, sourceFace **155**, bary `(0.19728784762040577,0.41676813671918711,0.3859440156604072)`, two occurrences from arcs **142** and **5539**. Eight directed halfedges, four reciprocal undirected twins, **all at source face 155 / topology region 0 / chart 0**, no hard feature and `layoutSupport=1`:

| Twin IDs | Shared local arrangement edge | Adjacent prepared cell IDs |
|---|---|---|
| 13338 / 13339 | 5351–5355 | 3 / 26569 |
| 13352 / 13353 | 5355–5359 | 3 / 0 |
| 13340 / 13341 | 5355–5356 | 0 / 26570 |
| 13350 / 13351 | 5357–5355 | 26569 / 26570 |

All four incident cells have `disk=true`, `closed=true`, one boundary cycle. They form **one connected closed ring** `26569–3–0–26570–26569` in the **post-parity/post-side-preparation arrangement**. This **rules out a missing post-preparation arrangement twin** at the point of failure; it does not prove the untouched pre-parity graph was correct.

Completed patch boundary corners preserve those four adjacency claims around node 5355:

| Completed patch index | Source cell | Boundary neighbors at 5355 | Node canonical hash |
|---|---|---|---|
| 0 | 26569 | 5357 / 5351 | 5886397040142297526 |
| 10942 | 3 | 5351 / 5359 | 5886397040142297526 |
| 22042 | 26570 | 5356 / 5357 | 5886397040142297526 |
| 24674 | 0 | 5359 / 5356 | 5886397040142297526 |

**But the resulting P13J stitched topology has three missing links:** arrangement neighbor **5357** is global rows 2 versus 63568 (cells 26569/26570), neighbor **5356** is global rows 63567 versus 76289 (cells 26570/0), and neighbor **5359** is global rows 29991 versus 76288 (cells 3/0). Neighbor **5351** merges correctly at global row 0 (cells 3/26569). The six incident quads therefore form the earlier three disconnected two-face fans, although the prepared arrangement forms one four-cell ring.

## Responsibility / exact outstanding discriminator

**Established:** after the prepared graph, before or during assembly, three **matching reciprocal boundaries** are not coalesced into the same global boundary vertex identity; the source arrangement ring itself is connected. The vertex mesh mismatch is not caused by a missing quad in any of those four patches. Production remains correctly fail-closed.

**Leading hypothesis: completion-boundary identity sharing.** `PatchDescriptor.cpp::arrangement_node_identity` constructs a scope-qualified `SurfaceCellCanonicalIdentity` from the node and the scope of the **outgoing oriented halfedge**. `derive_patch_descriptor` fills `patch.boundaryNodeIdentities` using that oriented edge; `PureQuadCompletion.cpp::resolved_stitch_identity` then uses each completed patch's boundary identity verbatim as the assembly key. Equal keys would share a global vertex row in `stitch_pure_quad_patches`. The three observed different global rows imply **different resolved keys** (provided the unmodified hash/equality contract holds), not a missing halfedge or an intentionally skipped assembly traversal.

**Not yet proved:** the exact canonical identity and typed certificate for the three adjacent arrangement nodes **5356/5357/5359** from both matching patch corners, the outgoing oriented halfedge scope at each corner, and whether those differences correctly encode a legitimate chart/sheet separation. The eight immediate edge scopes at node 5355 all match; scopes at the *other* endpoints were not logged. Therefore do **not** yet freeze a corrective code diff or a Code+Build successor. A deliberately false merge based solely on numeric node ID is forbidden.

**Next narrow probe (same Review turn):** capture for the 4 twin pairs above the *pair of endpoint canonical identities as constructed on each incident patch* (`boundaryNodeIdentities` full equality/hash and `boundaryTopologyRegions/boundaryCharts`), with outgoing halfedge IDs/scopes for nodes 5351/5356/5357/5359, and the incoming `vertexLineage` stitch identities / certificate support. If adjacent boundary keys differ while source region/chart sector remains validly identical, assign correction at descriptor/completion boundary identity construction, not by weakening the assembly's manifold gate. If scopes legitimately differ, trace the earliest incorrect sector assignment upstream before assigning owner.

Standing unchanged: CB78 accepted **only** as immutable compile artifact; TB72A 883/883 unpromoted gate, CP2 **491/491** accepted, stable **66/17/49**, debt 1, selector497 unpromoted. No production source/test/fixture/selector/benchmark modifications. Authenticated ancestry-backed `review_check.py boundary` and full review-document closeout not performed; this turn remains open. The isolated diagnostic branch is retained for exact next probe.

## Same-Review producer-key ownership finding (2026-11-03)

**Definition, not an accepted fix.** Exact CB78 source (`305573a3fd5508dbc380708798051aa0baea5d90` snapshot verified, 6,124/6,124 hashes) shows that `SurfaceArrangement.cpp::node_id` interns one node per `ScopedNodeKey = (NodeKey, TopologyRegionId, NodeAuthorityScope)`. The authority scope is vertex-fan ID for source vertices, sheet ID for face interiors, or empty for edge interiors. The producer retains `nodeScopes` locally, but **does not publish the complete scoped key** on `SurfaceArrangementNode`. The later `ensureOccurrence` appends admissible chart occurrences without creating a new node. V2 reconstructs a key from this mutable occurrence set, rather than using the original node owner identity.

**Smaller alternative to review:** publish an immutable, exact semantic encoding of the producer's complete scoped node key once, then use it **only for completed-patch boundary-node identities**. Preserve oriented/undirected domain and halfedge identity audits, typed certificates, and fail-closed assembly. Encode source vertex/fan, source edge topology and 1e-10 canonical edge parameter, or source face topology and barycentric weights ordered by typed source vertex ID, plus topology region and authority scope. The existing face-interior `NodeKey.face` is a *row index* and must NOT be copied into a semantic key: that would break face-row permutation invariance. Numeric node id alone and world-position proximity are not substitutes. Require injectivity for distinct original scoped nodes, or fail closed. This proposal would eliminate redundant per-corner `resolve_entity/rebind` in V2, but no performance gain is yet measured.

**Mandatory future falsifiers:** equal keys for the same prepared nodes 5351, 5356, 5357, 5359 viewed from either incident patch; distinct keys for distinct scoped nodes across disconnected coincident geometry, hard rails, vertex fans and sheet boundaries; distinct near-edge points around the 1e-8 classification/1e-10 key threshold; invariance to source-face rows, triangle orientations and patch order; unchanged manifold rejection for real disconnected links; bounded Vase progress and unchanged Cylinder PASS/BunnyRandom expected RED. These require descriptor-through-assembler evidence in a separately authorized Code + Build turn, not only native graph tests. **No successor is authorized; V2 is unaccepted.**

**Boundary-check evidence:** `review_check.py boundary` was actually run on the verified snapshot and exited 1 because the snapshot contains no `.git`. Its selector lines appear falsely as `untracked`, and rewrite-base ancestry cannot be checked there. This is not an accepted boundary PASS. Authenticated GitHub compare separately verified CB78 ancestry and no product/test/build/fixture drift; complete boundary proof remains outstanding. Same Review continues.
