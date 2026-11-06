# Completed mesh stitch and overlap — independent review WIP (2026-11-06)

**Turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2), **IN_PROGRESS, not adjudicated**. This is an evidence review, not a patch or approval to implement. Root `STATUS` owns the turn state.

## Authority and independent verification

- Repository `akashskypatel/Directional`, working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Snapshot triggered at control commit `3a3eb7bf08e69414e3957d23f141c0679050c446`, workflow `42135608658`, artifact `13466290539`, ZIP SHA-256 `120ff8eb85fdb978d1ba349caeec535ef576740c071fc46c3615462b88ac7a9f`. Snapshot metadata agrees with the source commit, its nested source archive hash matches, and 6208/6208 file checksums were verified.
- TB83 result report: immutable CB96 semantic source `11c8172ad467c6dc865f2f3352e75b78f5469a2b`; source package `13460725846`. Executed census artifact `13464736999` (ZIP SHA-256 `7637460db327b7ac19f6356bcbc89f4ee889cf69c93567a6be431bc4b0bc1734`) was downloaded and all 9 internal hashes verified. Vase is expected RED, with `validationIssues=4 GeometricVertexOnUnsplitEdge=3 SelfIntersectingFace=1`; 67,750 quads are intermediate/informational, not a valid output. Cylinder passes; BunnyRandom retains P13-e at source vertex 49.
- Recomputed selector: TB83 manifest SHA-256 `61e9edbedee3731b04d7b6279b79a0fd0e0b651686638e9b832773f7aa0a36aa`; TB82 manifest SHA-256 `9fbf329167cbe84698d5a08eda6e5374200c7729a5f0f1e4292836227902f878`. The entire TB82 manifest is a byte-identical prefix of TB83 (901 cases then two GUARD rows). The independent hash comparison does not rerun any tests.

## Source-established mechanisms

1. `src/geometry/PureQuadCompletion.cpp::stitch_pure_quad_patches` determines global vertex rows with `resolved_stitch_identity` / `vertexRows.find(key)`. Matching keys are subject to typed authority intersection and a position-consistency check; **different keys are not geometrically welded**, even when positions are near. Boundary keys come from arrangement boundary-node identity; generated patch interiors are scoped by `(stable_patch_owner, local_vertex)`. This is a correct separation of source-authoritative identity from proximity; do not weaken it.
2. In the same function, `canonicalQuadFirstOwnerIndices` uses the sorted four **global vertex IDs** to detect duplicate face ownership. This does not detect two geometrically crossing or overlapping quads with distinct global IDs. A global geometric collision therefore can reach `SourceAuthoritativeMeshValidator`; exact duplicate-owner checks passing does not prove intersection-free geometry.
3. `src/geometry/PatchDescriptor.cpp::derive_patch_descriptor` obtains each `patch.sideEdgeCounts` from the arrangement's `PatchSideDescriptor.subdivisionCount`; `PureQuadCompletion.cpp` consumes those boundary vertices and counts. A midpoint geometric T-junction could reflect incompatible subdivisions or disconnected embedded edge ownership; the current census alone does not distinguish those mechanisms.
4. `src/validation/SourceAuthoritativeMeshValidator.cpp` uses a triangle AABB intersection search for non-incident output faces and a point/edge search for `GeometricVertexOnUnsplitEdge`, after compatible-source-chart checking. These are terminal detection surfaces. Do not suppress their failures, perform epsilon merges, or let the validator rewrite completed geometry.

## Prior evidence, not a current localized proof

RA-208.2 (pre-CB96) identified one overlap between output faces 55 / 15,372, described as patch owners 118 / 54 over source face 1263, and three unsplit-edge witnesses:
- vertex 35,161 near the start of output edge (4,618, 35,159), parameter approximately 0.0007;
- vertex 53,049 near the start of output edge (28,576, 53,051), parameter approximately 0.0000;
- vertex 35,160 approximately midway (t=0.5003) on edge (4,618, 35,159), associated with patches 4,955 / 4,957.

**None of those indices is yet demonstrated to identify the same geometry after CB96.** TB83 shows a changed completion digest (`03865abb6ffafcbf` to `5a2aff2aff729ab8`), though it retains four issues. Mapping old indices to the new mesh by numerical proximity would be an unjustified substitution for provenance.

## Required evidence before freezing correction patches

Capture an exact **post-CB96** four-issue witness from the same frozen immutable semantic source, preserving global face/vertex indices, producing patch/local-quad and generated-vs-boundary lineage, exact stitch IDs, typed topology-region/sheet/chart/source-support authority, arrangement boundary node/halfedge IDs, per-side subdivisions, world-space coordinates, intersection parameters and source triangle support. Use a Review scratch probe, not a test/production-source mutation; maintain the no-local-build restriction in `start.txt`.

For each of the three unsplit-edge witnesses, compare the point and edge endpoint canonical authorities **before proposing a merge**. Classify (a) same exact source-entity authority represented by divergent boundary keys, (b) legitimately distinct generated interior vertices close together, or (c) a missing subdivision/edge ownership on one side. For the global crossing, compare the two patches' disjoint arrangement domains, source-face coverage and actual triangle-triangle crossing; determine whether incorrect domain overlap entered at arrangement, a completion topology/embedding choice crosses a distinct patch, or a stitch-identity mismatch alone causes topological separation. Recompute after CB96; do not assume the old owners.

Only after those proofs, write the smallest producer-owner correction(s) with a negative-on-legacy/nonvacuous witness, exact tests and expected failure class. Keep Code + Build and Test + Benchmark in separate turns. Preserve accepted CP2 491/491, current stable 66 events / 17 categories / 49 recurrences, debt 1; CP3 and selector497 remain unpromoted. This Review cannot close COMPLETE or authorize a specific CB patch from the present evidence.

## Closeout state

- Evidence independently checked: snapshot file hashes, two selector manifest hashes and exact-prefix identity; TB83 census artifact checksum manifest.
- Runtime probe: **not executed** (no build or runtime execution in this ChatGPT Review). No post-CB96 per-issue coordinates or lineage artifact is present in the examined TB83 census.
- Source, test, benchmark and build logic: **unchanged**.
- No stable regression accounting changed and no production acceptance claimed.
- Next action: resume **this same turn**, perform the required exact post-CB96 witness capture in an authorized review scratch environment, then adjudicate and freeze owner-targeted changes. All other carried obligations remain unchanged.

## Continuation: source-backed scratch capture (2026-11-06)

The 6208-file frozen source snapshot was independently re-extracted and checksum-verified in this attempt. The TB83 census artifact's nine internal checksums were also independently verified. TB82's actual manifest filename is `Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv`; its SHA-256 is `9fbf329167cbe84698d5a08eda6e5374200c7729a5f0f1e4292836227902f878`, and its bytes are an exact prefix of TB83 (`61e9edbedee3731b04d7b6279b79a0fd0e0b651686638e9b832773f7aa0a36aa`).

A narrower capture route is source-established: `RemeshPipeline.cpp:14370-14398` retains `completedVertices`, `completedQuads`, `completedVertexLineage`, and `completedQuadLineage` even when optional geometry retention is false. At `:14937-14959`, rejected completion validation retains the validation issues. `SourceAuthoritativeMeshValidator.cpp:1345-1352` encodes a global crossing's two face IDs in `edgeFirst/edgeSecond`, while `:1400-1411` encodes each T-junction's vertex and edge endpoint IDs. The default TB83 census output exposes only aggregated counts, not these witness IDs.

A **temporary scratch-only** remote capture was therefore launched, not a formal acceptance/test gate: workflow `.github/workflows/p13l2-scratch-20261106.yml` (install commit `a29c8790aec940dd78b46404082a40b303a56a59`), trigger `.agents/connector-triggers/p13l2-scratch-20261106.txt` (commit `cf1a339611a36deacb9e36ca15a6ae0e1f3c9140`). It validates its schema, checks out the frozen CB96 source `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, injects a witness dump only in the ephemeral Actions worktree, compiles a scratch producer target with GMP, and runs Vase. No production source, repository tests, benchmark selectors, or accepted artifacts were modified. Retrieve its completed result from orphan-branch mailbox key `p13l2-scratch` and verify the resulting artifact before using it. A request/trigger is **not** execution proof. If it is still running, do not duplicate-trigger; if failed, inspect its dedicated log.

Classification and exact corrective patch remain **unresolved until the post-CB96 issue rows and provenance are inspected**. Preserve CP2 491/491, stable 66/17/49, debt 1, and CP3 unpromoted. The same canonical Review turn remains active.
