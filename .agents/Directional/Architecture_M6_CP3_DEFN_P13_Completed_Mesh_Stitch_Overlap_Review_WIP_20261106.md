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

### Latest probe and review-check boundary

The scratch mailbox had not published a result at the final check; no run completion or geometric owner is claimed. Do not retrigger while the job may still be active. `review_check.py boundary` exited 1 on the source snapshot because its excluded `.git` history cannot establish the durable rewrite ancestry; a full PASS is **not** claimed. The response attaches a same-turn continuation and the read-only `analyze_p13l2_witness.py` (SHA-256 `505b2224d82a73717d51e54647b43447e59798af19095c8040ab701896616e7c`), which reports geometric candidates without equating stitch authority by proximity. Preserve scratch evidence and then clean its temporary workflow/trigger.


## Exact post-CB96 strict witness status (2026-11-06 02:32Z)

Read the newer [geometric-predicate and strict-issues review](Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Geometric_Predicate_Review_20261106.md) before assigning a patch. Frozen CB96 immutable source `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, package `13460725846`, scratch GDB run `42150099703` successful, result artifact `13471199160` (ZIP SHA-256 `576576231e92aa1d20cd886f40b7bcb07a74f5261c3cc1e02b8c3c819fa63a5c`, all six internal hashes valid). **Exact** validator issues: `SelfIntersectingFace(-1,55,15372,15372)`; `GeometricVertexOnUnsplitEdge(vertex=35161,edge=4618-35159)`; same `vertex=35160`; `vertex=53049,edge=28576-53051`. Earlier 1e-7 KD scan was too loose and also incorrectly endpoint-excluded the third; source-scaled `6.438212444601785e-8` prefilter reproduces all three and only these three. All three lie within narrow/near-degenerate quads **containing both edge and alleged vertex** (21286 and 41746). The first reported self-intersection 55/15372 is numerically false under dimensionally correct coplanar overlap, with additional fan-spill witnesses from concave quads; actual remaining crossings not yet globally adjudicated.

`SurfacePoint` provenance captured for every vertex, valid source-face labels and component/sheet 0 for the issue rows; no independently inspectable typed chart/stitch certificate or `PureQuadVertexLineage`/`PureQuadFaceLineage` patch mapping was recovered. The output face-to-source-face array contained -1 at examined rows. Thus **exact issue identity is discharged, but producing patch/typed stitch ownership and the global geometric-collision contract remain unresolved**. No code/test/fixture/selector/build mutation and no TB/CP2 promotion. Preserve accepted CP2 491/491 and stable 66/17/49 debt 1. Resume this same Review with a source-owned patch-lineage certificate and adversarial predicate/concavity checks before freezing separate CB corrections.


## Same-turn continuation: canonical completion-lineage probe (2026-11-06 02:53 UTC)

The previous independent strict-issue replay is authoritative only for its *diagnostic* bytes: immutable CB96 source `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, package `13460725846`, exact four issue tuples from artifact `13471199160`. No accepted gate changed. Recomputed from the retained geometry, quad 21286 has area `1.227781017144571e-10` and edge `(35161,4618)` length `2.6460094959514124e-6`; quad 41746 contains near-zero edge `(53049,28576)` length `8.958587186761864e-8`. The independently measured three issue vertices are each nonadjacent to a *closing edge of their own output quad*. This suggests completion geometry quality/embedding rather than proving boundary subdivision disagreement.

Exact source inspection of `src/geometry/PureQuadCompletion.cpp::quad_embedding_failure` confirms finite coordinates, Newell normal threshold `1e-24` squared, own-plane area `1e-14` absolute, bow-tie crossing with fixed orientation epsilon `1e-13`, and source orientation, but **no minimum own-quad nonadjacent-corner/edge clearance**. Because a narrow quad may pass these tests, source-owned clearance/invariant is a *candidate*, not an authorized fix; before changing it, show positive valid thin-quad controls and identify the producing patch/backend. Do not collapse distinct stitch keys by proximity.

To recover missing producer certificates without rebuilding or altering tests, a temporary GDB scratch workflow `.github/workflows/p13l2-lineage-20261106.yml` (created at `05cd1930a94105d24e4126225533e095c391b4d8`) was triggered by marker `.agents/connector-triggers/p13l2-lineage-20261106.txt` at `031939e650ea2d379e7fb702db17a076a9d94ef9`. It checks out the immutable CB96 source and original compiled artifact, searches *live* std::vector headers for 67,750 `PureQuadFaceLineage` rows (40-byte expected layout) and 67,961 `PureQuadVertexLineage` rows (size inferred by explicit count and index sentinels), dumps only implicated lineage records, and publishes mailbox key `p13l2-lineage` on `workflow-mailbox`. Its trigger is **not** a claim of runtime completion. Validate the final artifact and its embedded hashes before interpreting. This source-level record remains IN_PROGRESS until patch owners, typed identities and the geometric-collision contract are independently adjudicated. No product/test/build/fixture/selector changes made.


## Frozen CB96 exact producer lineage recovered (2026-11-06 02:55 UTC)

Read-only immutable-compiled-artifact scratch run [42152593724](https://github.com/akashskypatel/Directional/actions/runs/42152593724) succeeded on original CB96 semantic source `11c8172ad467c6dc865f2f3352e75b78f5469a2b` and package `13460725846`; no rebuild or source/test/fixture modification. Result artifact `13473291589`, outer SHA-256 `02036d1c1d394ad27063282c0d57d40fd11896457390120961e033c986de7d5e`, internal **6/6** SHA256SUMS validated; log artifact `13473306688`, outer SHA-256 `a415c05b49013951ef5ca831166dc782deffceadf4bdab0c0b9f3ae60db07faf`. Three independently retained in-process vector owners for `PureQuadFaceLineage` and `PureQuadVertexLineage` were located by verified indexed sentinel fields and sizes (67,750 records × 40 bytes, 67,961 records × 928 bytes). Three face-record tables are byte-identical; decoded semantic vertex fields agree across all three copies (raw vector addresses intentionally differ). These are original CB96 lineage records at validator entry, not geometry-based patch guesses.

| Output quad | Source patch | Backend enum/name | Local quad | Boundary only |
|---|---:|---|---:|---|
| 55 | 118 | 2 Pattern | 1 | true |
| 15372 | 54 | 0 ClosedForm | 1 | true |
| 21286 | 4955 | 3 BoundedCombinatorial | 0 | true |
| 21288 | 4955 | 3 BoundedCombinatorial | 2 | true |
| 21290 | 4957 | 3 BoundedCombinatorial | 1 | true |
| 21291 | 4957 | 3 BoundedCombinatorial | 2 | true |
| 41744–41745 | 23302 | 0 ClosedForm | 0–1 | true |
| 41746–41747 | 23301 | 3 BoundedCombinatorial | 0–1 | true |
| 4304 | 8788 | 0 ClosedForm | 0 | true |
| 4308 | 8789 | 2 Pattern | 2 | true |

The prior historical owner pairs **118/54** and **4955/4957** are therefore **confirmed current CB96 patch owners** by independent stored face lineage; retract the old uncertainty that the face IDs could have been remapped. This does **not** turn 118/54 into a real overlap: the independently rederived `collinear_segment_overlap2` dimensional false positive stands. The second T-junction cluster owners are now **23301/23302**; adjacent edge endpoint 28576 is represented from patch 25721.

Retained vertex record summaries (all `kind=SourceTriangle`; `stitchIdentity.kind=authoritativeIdentity.kind=1` = `ArrangementBoundaryNode`, both identity valid flags true): `35160→(representativePatch=4955,localVertex=63360)`, `35161→(4955,35319)`, `35159→(4955,35314)`, `4618→(4977,57362)`, `53049→(23302,9679)`, `53051→(23301,9678)`, `28576→(25721,36055)`. These are deterministic representative lineage owners, **not exclusive contributing patch memberships**. Crucially, all seven are *arrangement-boundary nodes*, not generated patch interiors; the near-degenerate wedge geometry may originate in arrangement-boundary spacing or completion boundary geometry rather than arbitrary generated interiors.

Still missing: actual decoded **canonical typed vector contents** (the captured 928-byte row holds process-address pointers, and vector byte-lengths alone do not prove equality), patch-local/arrangement halfedge and per-side subdivisions, and a producer-correct, negative-on-legacy repair plan. Do **not** use hash equality as typed equality, proximity-weld, skip validator failures, or accept CP3. The two false-positive geometric-collision mechanisms remain separate from boundary ownership. Formal TB83 903/903, CP2 491/491, stable 66/17/49/debt1 remain unchanged.


### Recoverability and scratch hygiene — same attempt

The same-turn raw lineage evidence was exported as ChatGPT attachment `Directional_P13L2_CB96_Retained_Lineage_20261106.zip` (ZIP SHA-256 `6b55222caddb23ec47397407161d611ae58a0988c80448f3d0dd9fb575e518fe4`), with original workflow output, a recovery README, and internal SHA-256 verification manifest; independent 6/6 workflow checksums passed. Temporary workflow caller was deleted via GitHub at `49d95f9dd2dca444080886848f8582e66424bb7a`; the single-use trigger `.agents/connector-triggers/p13l2-lineage-20261106.txt` was submitted to established `agent-turn-cleanup.yml` by manifest trigger `a7802db9d4be0dc84a78a47e7032eb0b19f37d75`. Confirm mailbox key `agent-turn-cleanup` on branch `workflow-mailbox` references **that trigger SHA**, and inspect its cleanup-result artifact. Do not confuse with prior cleanup run `42150899196`. No Google Drive patch transport was needed because this attempt wrote only complete Review documentation directly to GitHub and produced no local repository source modification.

Retained raw `PureQuadVertexLineage` rows from the three independent vectors are *not byte-identical* because their nested `std::vector` heap pointer values differ; the independently decoded identity kinds, valid bits, vector byte lengths, representative patch IDs and local vertex IDs agree. Neither pointer equality nor raw-record hashes are an authority certificate; exact typed vector contents are still missing.
