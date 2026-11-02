# RA-197 — P13-h/P13-i closed-form grids and side-count descriptors: probe adjudication; exact CB76, TB70 (2026-11-02)

**Turn:** `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (Review/Definition). ChatGPT started it at 2026-11-02T01:14:57Z and set `STATUS` to BLOCKED: the [review WIP](Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Review_WIP_20261102.md) asks for "missing Vase descriptor evidence" before it can name an owner. Resumed here at 03:14:48Z on the RA-196 scratch build. RA-196.8 step 5 had already placed this DEFN on that build. The trace is a probe to run, not an artifact to find, so the block was procedural.

Source at review: HEAD `8510d1e48`. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB75 `8656c4fed5070a467da491b60ead5c8ab1d99dbd` (TB69 package `13107147891`, 878/878). Only documents landed after CB75. The scratch tree `wt61`/`bld61` equals that source (verified file by file) before the probe was added.

## RA-197.1 Findings

1. **F1 — the owner is corner registration in the descriptor, not the grid's geometry.**
   - `ordered_boundary` (`PatchDescriptor.cpp:179`) starts each cell's boundary at its smallest halfedge id. That start is arbitrary with respect to the sides.
   - `extract_sides` then closes a side that wraps around the start, by moving the tail run to the front of side 0. So side 0 begins `t` vertices *before* boundary index 0.
   - `derive_patch_descriptor` copies the boundary in traversal order, so `PureQuadPatch::boundaryVertices[0]` is often a mid-side vertex. Nothing rotates it.
   - `complete_rectangular_grid` reads corner `c00` at index 0, and sides at the offsets `w`, `w + h` and `2w + h`. With `t ≠ 0` every rung joins the wrong pair of vertices: the ladder is twisted by `2t` positions. `complete_singularity_pole` reads corners by index parity the same way.
2. **F2 — the evidence (RA-197.2).**
   - Of the 224 closed-form failures, 220 are boundary-only strips (`w` or `h` equal to 1), not 2D grids. Every one has a simple, counter-clockwise boundary, its normals lie within 6.8° of their mean, and its failing quads touch only boundary vertices.
   - In 222 of the 224, the geometric corners are the grid's assumed corners shifted by `t` = 1–4.
   - For all 220 strips, the ladder built from the geometric corners embeds under Amendment 28.
   - None of the 6,862 1×1 cells fails, and no rotation can twist them.
   - With the boundary rotated to side 0's first halfedge, all 220 strips complete.
3. **F3 — the defect is mostly silent.** At HEAD, 5,868 of the 23,329 four-sided descriptors in Vase's first pass are misregistered: 1,902 of 6,371 strips and 375 of 823 2D grids.
   - Only 222 of those fail.
   - The other **2,055 closed-form completions are accepted with their corners on the wrong vertices.** A real corner sits mid-side, and a T-node is treated as a corner. That puts irregular vertices on the cell boundary, which the field does not ask for.
   - Amendment 28's predicate cannot see this, because a twisted ladder in a convex cell is still embedded.
   - No accepted output contains such completions. Vase has never produced output, BunnyRandom stops at the atlas, and Cylinder never reaches descriptor completion (its trace has no descriptor).
4. **F4 — the WIP's leads and its candidate fixes do not reach the owner.**
   - Its correction stands: patch 4 is a boundary-only strip, so interior interpolation cannot cause it. Its terminology caution stands too.
   - But both of its candidate mechanisms address symptoms:
     - The corner-only bilinear target: Coons targets make Vase worse, with 20 grid failures at HEAD's registration.
     - The CB74 boundary DP for strips: it completes all 220 strips, but it replaces the field's ladder with an arbitrary quadrangulation, and it leaves the 2,055 silent twists in place.
   - Its smooth-side Coons witness is not Vase evidence.
   - Its stop condition ("no trace") is satisfied by running the probe, which RA-196.8 had assigned to the Review track.
5. **F5 — RA-196's own P13-h statements were wrong.**
   - RA-196.2 called the 224 closed-form failures "none boundary-only". 220 of them are boundary-only strips, carried by the `ClosedForm` backend rather than `Pattern`/`BoundedCombinatorial`.
   - RA-196.3 named "the bilinear target or the projection" as the owner candidates. The owner is upstream of both.
   - The dumps were run but never binned by grid shape, and never compared against the geometric corners.
6. **F6 — after CB76, P13-h leaves 4 needle grids (P13-h2).** Cells 6095, 20533, 20968 and 22350 (2×2, 2×2, 3×2, 2×4) fail at a quad with a generated vertex.
   - Their boundaries are simple and counter-clockwise, within 3.6° of flat. Projection moves the targets by at most 1.1 % of the diameter.
   - Each is a needle: about 10⁻⁵ thick and 10⁻² long, bent by more than its thickness.
   - No interpolant embeds them all:
     - corner-bilinear fails these 4;
     - index-uniform Coons fails 5 others (16291, 5504, 25371, 10732, 17300);
     - Tutte (harmonic) fails 2 (6095, 20533).
   - Swapping the interpolant is therefore not a fix.
7. **F7 — the P13-i descriptors are rail-grazing lenses, not malformed counts.** All five (cells 26735, 26764, 26781, 26802, 26812; descriptors 23933–24559) are disks with six boundary vertices and exactly two sides: one field trace (family 0 or 1, 3 edges) and one hard-feature rail (family −1, one rail, one curve, 3 edges).
   - Their two tips have interior angles of 0.2°–27° (26735: 10.0° and 0.6°; 26764: 1.3° and 0.2°; 26781: 20.6° and 3.3°; 26802: 15.1° and 11.1°; 26812: 26.9° and 1.7°).
   - So a trace meets the rail at a grazing angle and cuts off a needle lens.
   - `check_pure_quad_patch_admissibility` is right to reject them. Relaxing `SideCountUnsupported` would accept needle quads.
   - The owner is upstream, in how a trace that runs along a rail meets it.
8. **F8 — what stands.**
   - Amendment 28's predicate, search and typed failures are unchanged.
   - The terminal detail (CB75) is correct.
   - No interior-placement change, fallback, epsilon or admissibility change is authorized.

## RA-197.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB75 before the probe. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. The probe lives in scratch copies of `PureQuadCompletion.cpp` and `PatchDescriptor.cpp`:
- `PROBE_P13H_DUMP` dumps every failed completion (vertex positions, source face, its unit normal, target before projection, quads, source faces), every inadmissible descriptor (sides, families, positions), and one `H_ROT` line per descriptor with its side-0 start offset.
- `PROBE_P13H_ROTATE` rotates the boundary to side 0's first halfedge, which is CB76's change.
- `PROBE_P13H_MODE` selects the variant:
  - `0`: HEAD grid;
  - `1`: index-uniform Coons targets;
  - `2`: the CB74 DP for strips whose ladder does not embed;
  - `3`: `1` and `2` together;
  - `4`: the DP for any grid that does not embed (data point only);
  - `5`: Tutte targets.

Offline audits (Python, `-I`) re-implement Amendment 28's predicate with the same constants and order.

| Probe | Result |
|---|---|
| HEAD (mode 0), dump | 224 closed-form failures (220 strips: 52 bow-tie and 168 source-orientation; 4 2D grids) and 5 `side-count-unsupported`. 13,832 closed-form completions accepted (6,862 1×1, 6,151 strips, 819 grids). Vase RED at patch 4 in 144 s. The 210 transition-template embedding failures in the log are retried variants, not final failures |
| Strip geometry | 220/220 boundaries simple and counter-clockwise in the chart of the mean source normal. Normal spread at most 6.8°. Every failing quad touches boundary vertices only. Thickness/length runs from 0.0006 to 0.70 (median 0.19). A boundary-only quadrangulation exists for 220/220 |
| Patch 4 | Sides `2,1,2,1`. The real corners are boundary indices 1, 2, 4 and 5 (`t = 1`): a straight strip about 0.039 long and 2·10⁻⁵ thick, with its T-nodes 0 and 3 opposite each other. The grid's rung 1–4 runs corner to corner along the strip, giving a bow-tie and an edge-on quad (88.7° and 86.8°). The true rung 0–3 gives two embedded quads |
| Geometric corners vs. assumed corners, all 224 | Shift `t`: 0 → 2, 1 → 42, 2 → 145, 3 → 26, 4 → 9. The ladder built from the real corners embeds for **220/220** strips |
| Misregistration census, all 26,826 descriptors (`H_ROT`, HEAD order) | Four-sided: 5,868 of 23,329. Rectangular: 1×1 0/6,862; strips 1,902/6,371; 2D grids 375/823. Other side counts are also offset (for example 1,064 of 2,942 six-sided), but their backends rotate through every variant |
| Mode 2 (strip DP) | 4 completion failures (the 2D grids) + 5 P13-i. All 220 strips are completed by the DP, which replaces their ladders |
| Mode 3 (Coons + strip DP) | 20 2D-grid failures |
| **Rotation (CB76's change), mode 0** | **0 strip failures.** 4 2D grids fail (6095, 20533, 20968, 22350), each at a quad with a generated vertex. 14,052 closed-form completions accepted (6,862 + 6,371 + 819). Vase RED `completion=InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch;vertices=60917,19077,19081,-1` in 141 s |
| Rotation + Coons (mode 1) | 5 different 2D grids fail (16291, 5504, 25371, 10732, 17300), all bow-tie. Index-uniform parameters misplace rows when one side's T-nodes cluster at an end (16291: three side-1 nodes within 6·10⁻⁴ of a side 1.2·10⁻² long) |
| Rotation + Tutte (mode 5) | 2 fail (6095, 20533): bent needles whose four side midpoints average outside the cell |
| Residual 2D grids after rotation | Boundary simple and counter-clockwise, within 3.6° of flat; projection displacement at most 1.1 % of the diameter. 20533: thickness about 9·10⁻⁶, length 8.2·10⁻³, T-nodes at 82 % of both long sides, bilinear centre at 50 %. 6095: about 4·10⁻⁵ by 4·10⁻² |
| Rotation + grid DP (mode 4, data point) | 0 completion failures. Vase RED `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, `completion=IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;reasonCode=3;attempted=26821;failed=5;total=26826`, in 142 s. So P13-i is the terminal once P13-h2 is resolved |
| P13-i lenses | See F7. Thinness (4πA/P²) 0.006–0.17. 4 of the 5 are also side-0 offset, which does not change their side count |
| Cylinder, BunnyRandom (probe) | Cylinder PASS in 8.5 s with no descriptor; BunnyRandom P13-e at the atlas. CB76 cannot change either |
| Clean CB76 build (exact patch, no probe code) | `PatchDescriptorMilestoneE.*` and `PureQuadCompletionPhase18.*`: 99 passes, plus exactly the 11 pre-existing off-gate `PatchDescriptorMilestoneE` failures of CB72–CB75 (RA-170 baseline) |
| Gate (TB70 manifest, 880 rows) | **879/880**, only row 283 (O16, macOS LegacyInteger). Against RA-196's CB75 gate (877/878), no shared row changes; rows 879–880 PASS. 1 min 42 s at `-P3` |
| Ledger v5 (81 rows) | 0/81 PASS, as at CB75; no row changes its verdict or first-failure token. Row 365 (Vase) is RED in 144 s |
| Census, clean build | Cylinder PASS (8 s). BunnyRandom P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`). **Vase RED** `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, `completion=InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch;vertices=60917,19077,19081,-1`, in 143 s uncontended. This matches TB70's registered criteria |
| Mutants (each rebuilt; rows 879–880 and the entry-point control run) | M1, no rotation (HEAD): 879 and 880 fail. M2, rotation to the last side's start: 879 and 880 fail. Control `CompletesAuthoritativeComplexThroughMilestoneEEntryPoint` passes under both. Restored: all pass |

## RA-197.3 Rulings

- **DESIGN Amendment 29** (added): a patch boundary starts at the first vertex of side 0.
  - **The contract.** `PureQuadPatch::sideEdgeCounts` partitions `boundaryVertices` in order from index 0: side `k` starts at the sum of the earlier counts. Every per-patch array (provenance, identities, charts, regions, rails, curves) follows the same order.
  - **The producer.** `derive_patch_descriptor` rotates its boundary traversal to side 0's first halfedge after extracting sides. The domain identity is rotation-invariant (`canonical_cycle_rotation` of the directed boundary, sorted undirected), so identities and descriptor order do not change.
  - **The consumers.** Completion templates may read corners and sides by index offset; the closed-form grid and the pole template do.
- **P13-h owner:** `derive_patch_descriptor`'s corner registration. CB76 (exact, RA-197.7) fixes it at the producer. No strip search, no interpolant change, no fallback.
- **P13-h2** (new, blocking): 4 needle 2D grids that fail with correctly registered corners. No interpolant is sound on them (F6). The candidates are robust interior placement in the completion, or not producing needle cells in the arrangement.
- **P13-i** (classified): rail-grazing lenses; the admissibility rejection stands. The owner is upstream (trace–rail incidence).
- **Next Review DEFN:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`, a probe DEFN covering P13-h2 and P13-i. It can start now on the scratch build. For each needle and lens it must find:
  - which strands, proposals or rails bound it;
  - the separation of its two long sides;
  - the field direction against the rail tangent at the lens tips;
  - whether a design rule already governs a trace that runs within a cell width of a parallel trace or rail.

  Then it names one owner and freezes exact patches.
- **O23** (new, quality, non-blocking): needle cells (thickness/length down to 6·10⁻⁴) from near-parallel traces produce needle quads even when they embed. Owned by M7 quality unless the sliver DEFN removes them.
- A TB runs after CB76 alone (TB70). CB76 changes a descriptor contract that every completion backend reads, so its gate, ledger and census evidence should not wait for P13-h2.

## RA-197.4 CB76 — `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 8656c4fed5070a467da491b60ead5c8ab1d99dbd HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-197.7 verbatim plus a trailing newline. Keep its 3 single-space context lines. SHA-256 `5c7918fbd6dea765848ce3bd0272aba336c22952fde398acf5beb4d3ccc6af19`; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PatchDescriptor.cpp` | `10 0` | `108e5481fe85ecafa566d4a14f089afbf00956f8e543fbbc8b0c5f176f31f491` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `61 0` | `e1eda480ad809dfd285bf5760c257f47b8085459b9c9ef2b432af8a892bde8d6` |

- **Content:**
  - After `extract_sides`, `derive_patch_descriptor` rotates `boundary` to `descriptor.sides.front().halfedges.front()`.
  - The test helper `start_boundary_inside_first_side` renumbers a fixture cell's halfedges, with their twin and next links, so that the smallest id lies inside side 0.
- **Tests (gate rows 879–880):**
  - `PatchBoundaryStartsAtTheFirstVertexOfSideZero`: a `3,1,3,1` cell whose smallest halfedge id is side 0's second halfedge. The side counts are unchanged, `boundaryVertices` equals the concatenated side vertices, and it starts at vertex 0.
  - `ClosedFormStripRungsJoinOppositeSideVertices`: the same cell, completed through the Milestone E entry point with source authority. One closed-form patch, with quads `{0,1,6,7}`, `{1,2,5,6}`, `{2,3,4,5}`. Without the rotation the ladder is twisted but still embedded, so only the connectivity assertion catches it.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Exact → TB70.
  - Mismatch → `M6-CP3-PLAN-P13-PATCH-SIDE-START-STOP`.
  - Infrastructure → `M6-CP3-CB76A-P13-PATCH-SIDE-START-ORCH` (one retry).

## RA-197.5 TB70 — `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB76's immutable package.

- **Gate:** [manifest](Architecture_M6_TB70_P13_Patch_Side_Start_Full_Gate_Case_Manifest.tsv), 880 rows, SHA-256 `a9f964c843a5620f281bf2ca2f07e7df9b8d11a7769218a635a5b707aaf2b03b`. That is TB69's 878 rows byte for byte plus GUARD rows 879–880.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=880 deferred=81`.
  - Pre-registered **880/880**, membership **961**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, with `completion=InvalidCompletionQuadEmbedding;…;backend=closed-form;…`, and **at least one negative (generated) id in `vertices=`**.
  - The registered match is the stage, the detail, the code, `closed-form` and a generated vertex. The macOS locus (patch 6095, `localQuad=1`, `source-orientation-mismatch`, `vertices=60917,19077,19081,-1`) is recorded, not registered (RA-176).
  - Mismatches:
    - a Vase RED whose `vertices=` are all non-negative (a boundary-only strip still fails);
    - `bounded-combinatorial` or `pattern`;
    - `IncompleteSurfaceCellComplex` (P13-h2 would then not reproduce);
    - `detail=None`, or a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB70A-P13-PATCH-SIDE-START-ORCH` (one retry).

## RA-197.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START` | Implementation agent, Linux; RA-197.7, compile only |
| 2 | `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC` | Implementation agent, Linux; gate 880/880, membership 961; Vase RED `completion` / `PatchCompletionRejected` / closed-form with a generated vertex, within 600 s |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (P13-h2 needle grids, P13-i rail-grazing lenses) | Probe DEFN on the scratch build: name one owner, then exact patches |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## RA-197.7 Exact CB76 patch

```diff
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -1698,6 +1698,16 @@ PatchDescriptor derive_patch_descriptor(
 
   descriptor.sides =
       patch_descriptor_detail::extract_sides(complex, cell, boundary, V, F);
+  // The traversal starts at the smallest halfedge id, which can lie inside a
+  // side that extract_sides then closes across the wrap. Start the patch
+  // boundary at side 0's first halfedge instead, so the side counts partition
+  // it in order from its first vertex, as the completion templates assume.
+  if (!descriptor.sides.empty()) {
+    std::rotate(boundary.begin(),
+                std::find(boundary.begin(), boundary.end(),
+                          descriptor.sides.front().halfedges.front()),
+                boundary.end());
+  }
   patch.sideEdgeCounts.reserve(descriptor.sides.size());
   patch.turns.reserve(descriptor.sides.size());
   for (const PatchSideDescriptor &side : descriptor.sides) {
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -780,6 +780,27 @@ Fixture make_valid_parallel_route_same_corner_complex() {
   return fixture;
 }
 
+// Renumbers the boundary halfedges of the fixture's first cell so that the
+// smallest id is the `offset`-th halfedge of side 0. Twin and next links
+// follow the renumbering.
+void start_boundary_inside_first_side(Fixture &fixture, const int offset) {
+  auto &halfedges = fixture.complex.halfedges;
+  const int count =
+      static_cast<int>(fixture.complex.cells.front().halfedges.size());
+  const auto moved = [&](const int id) {
+    return id >= 0 && id < count ? (id - offset + count) % count : id;
+  };
+  auto renumbered = halfedges;
+  for (int id = 0; id < static_cast<int>(halfedges.size()); ++id) {
+    auto edge = halfedges[static_cast<std::size_t>(id)];
+    edge.id = moved(edge.id);
+    edge.next = moved(edge.next);
+    edge.twin = moved(edge.twin);
+    renumbered[static_cast<std::size_t>(moved(id))] = edge;
+  }
+  halfedges = std::move(renumbered);
+}
+
 } // namespace
 
 TEST(PatchDescriptorMilestoneE, DerivesOrderedSidesSubdivisionsAndFeatures) {
@@ -1930,3 +1951,43 @@ TEST(PatchDescriptorMilestoneE, CompletionFailureKindsNameTheTerminalDetail) {
                    SurfaceCellComplexCompletionFailureKind::
                        PatchCompletionRejected));
 }
+
+TEST(PatchDescriptorMilestoneE, PatchBoundaryStartsAtTheFirstVertexOfSideZero) {
+  // The smallest halfedge id is the second halfedge of side 0, so the
+  // boundary traversal starts inside side 0 and closes it across the wrap.
+  Fixture fixture = make_patch({3, 1, 3, 1});
+  start_boundary_inside_first_side(fixture, 1);
+  const auto descriptor = directional::geometry::derive_patch_descriptor(
+      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
+
+  ASSERT_TRUE(descriptor.boundaryCycleValid);
+  ASSERT_EQ(descriptor.sides.size(), 4U);
+  EXPECT_EQ(descriptor.patch.sideEdgeCounts, (std::vector<int>{3, 1, 3, 1}));
+  std::vector<int> sideVertices;
+  for (const auto &side : descriptor.sides) {
+    sideVertices.insert(sideVertices.end(), side.boundaryVertices.begin(),
+                        side.boundaryVertices.end());
+  }
+  EXPECT_EQ(descriptor.patch.boundaryVertices, sideVertices);
+  EXPECT_EQ(descriptor.patch.boundaryVertices,
+            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7}));
+  EXPECT_TRUE(descriptor.feasibility.admissible);
+}
+
+TEST(PatchDescriptorMilestoneE, ClosedFormStripRungsJoinOppositeSideVertices) {
+  Fixture fixture = make_authoritative_patch({3, 1, 3, 1});
+  start_boundary_inside_first_side(fixture, 1);
+  const auto completion = complete_fixture_with_source_authority(
+      fixture.complex, fixture.V, fixture.F);
+
+  ASSERT_TRUE(completion.is_produced());
+  ASSERT_EQ(1U, completion.product().completedPatches.size());
+  const auto &mesh = completion.product().completedPatches.front();
+  EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::ClosedForm,
+            mesh.backend);
+  // Side 0 runs 0-1-2-3 and side 2 runs 4-5-6-7 back, so each rung joins a
+  // side 0 vertex to the opposite side 2 vertex and the corners 0, 3, 4 and
+  // 7 each lie in exactly one quad.
+  EXPECT_EQ(mesh.quads, (std::vector<std::vector<int>>{
+                            {0, 1, 6, 7}, {1, 2, 5, 6}, {2, 3, 4, 5}}));
+}
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB70 manifest is TB69's 878 rows byte for byte plus rows 879–880; `SELF_CHECK_PASS cases=880 deferred=81` with harness P8 |
| Decisive claims independently re-derived | Full first-pass failure dump at HEAD; every failure binned by grid shape; geometric corners against assumed corners for all 224; producer start rule read in source; misregistration census of all 26,826 descriptors; rotation, interpolant and fallback probes; clean build of the exact patch (suites, gate, ledger, census); mutants; patch applied to HEAD with both result SHA-256 reproduced; embedded block re-hashed |
| Non-vacuity checked | Rows 879–880 fail under M1 (HEAD behaviour) and M2; row 880 fails on connectivity alone, because the twisted ladder still embeds. The Vase census moves off strips (0 strip failures; every residual failure has a generated vertex) |
| Prior obligations discharged/carried | F1–F8 ruled; RA-196 F-statements on P13-h corrected (F5). P13-h attributed and routed (CB76/TB70). P13-h2 new, P13-i classified; both → `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. O23 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, O21, O22, DR1/DR3, DR2/DR4, O2b, O15b, O7 (the oracle target still does not compile) |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-h2, O23; P13-i classification; the silent misregistration (F3) as a tracker candidate |
| ORIENTATION currency line | Updated to RA-197 / CB76 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: when a rotation-invariant subclass never fails, check index contracts between producer and consumer before geometry |
| Consolidation under CLEAN_UP_POLICY | The review WIP stays as history with a superseded note pointing here |
| Successor frozen | CB76 (RA-197.4, exact RA-197.7) → TB70 (RA-197.5) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 8510d1e48` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB76 |
| Pushed to origin, branch in sync | Yes, fast-forward, no force |
