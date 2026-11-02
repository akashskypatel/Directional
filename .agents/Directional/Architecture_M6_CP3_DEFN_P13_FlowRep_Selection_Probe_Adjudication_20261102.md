# RA-199 — P13-i FlowRep selection: probe adjudication; unmet support chords; exact CB78, TB72; next failure P13-j (2026-11-02)

**Turn:** `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (Review/Definition, P13-i). ChatGPT started it at 2026-11-02T18:16:23Z. It wrote a [probe preflight](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Preflight_20261102.md) and an earlier [static review](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Invariants_Review_20261102.md), then set `STATUS` to BLOCKED: its session cannot run the scratch probes RA-198.6 requires.

That block is procedural, as in RA-197 and RA-198. RA-198.6 put this probe DEFN on the Review track, on the scratch build. `REVIEW_TURN_POLICY.md` §4.3 keeps a Review free of repository product, test, fixture and selector changes; scratch diagnostic probes change none of those. Resumed here at 20:52:44Z on the RA-198 scratch build.

Source at review: HEAD `16cc9a268`. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB77 `25713a0c0eb0979155c6954f86f8fb13417d5463` (TB71 package `13160673891`, 881/881). The scratch tree `wt61`/`bld61` equals that source (verified file by file) before the probes were added.

The preflight's probe contract is used as a checklist. Its source reading stands, and it is credited where it applies below. Where a probe contradicts one of its assumptions, the finding says so.

## RA-199.1 Findings

1. **F1 — selection cannot see whether a support trace meets the layout.**
   - Seed traces end only on rails, features or singularities. No seed trace ends on another trace, and a crossing inside a source face creates no shared endpoint key.
   - So every retained support trace is exactly one flowline: 115 support transactions for 115 support traces. Its endpoint keys touch only its rail.
   - The selector's two guards both work on this graph. Neither can express "this support connects to nothing":
     - the degree rule sees only rail nodes;
     - coverage sees only distances.
2. **F2 — coverage is not the lens criterion.**
   - Distances are measured from each support's own samples to the nearest other active arc, normalised by target size (Vase target size 0.034–0.10; tolerance 0.02):
     - same face: 13 of 115 within 0.02;
     - across an edge-sharing face: 19 within 0.02 and 59 within 0.1. Vertex-sharing faces give exactly the same counts.
   - Three of the five lenses are not near-duplicates of anything:
     - trace 612 at 0.022;
     - trace 20 at 0.051;
     - trace 422 at 0.058 (and 0.12 from the rail).
   - Cross-face coverage plus a relaxed degree rule removes 13 supports, including lenses 878 and 1037. Vase still has three two-sided cells (probe B).
   - The same-face restriction is a real metric defect: the distance across a shared edge is infinite. Correcting it changes which near-duplicate supports survive, which is a needle-quality matter (O23), not validity → **O25**.
3. **F3 — the exact degree rule makes support selection inert.**
   - `protected_endpoint_degrees` freezes every rail node's degree. Every rail-seeded support adds one incidence to a rail node, so no support can ever be removed: all 115 fail the endpoint check (probe A).
   - This is the RA-198 F5 finding, confirmed. It is not on the P13-i path once unmet chords are not admitted (F6). Recorded with O25.
4. **F4 — the lenses are unmet chords.**
   - Exactly 10 of the 115 support traces are crossed or touched by no other non-rail arc: 20, 422, 612, 878, 1037 (all five lenses) and 5, 28, 439, 604, 629.
   - All 115 leave rail 0 and end on the source boundary. A trace that returns to the rail it left and meets nothing bounds, with that rail, a cell whose only corners are its own two ends.
   - RA-198 F6's three exposed cells are among the other five. Nested chords bound two-sided cells once the five inner lenses are gone.
   - Taking all 10 out clears every two-sided cell. Completion then succeeds on every cell, and Vase fails later, at assembly (probe C and the exact CB78).
5. **F5 — one pass is the fixed point.**
   - Meeting is symmetric, and an unmet chord meets no other trace. Deactivating one therefore cannot change whether another is met.
   - Probe C's second pass removed nothing. RA-198's fixed-point requirement is met by one pass, with no iteration and no order dependence.
6. **F6 — the rule belongs in what selection admits, not in a removal transaction.**
   - Probe C applied the chord rule inside `select_sparse_flow_rep_network`'s removal loop. After the first chord went, its uncovered samples stayed in the global coverage maximum, and every later coverage removal failed (220 of 220).
   - Leaving unmet chords inactive when `build_flow_rep_selection_input` builds the input keeps them out of coverage samples and cycles entirely. The selector's transactions are unchanged.
   - The input builder already does this for one lens: it replaces a singular separatrix's pre-rail micro-loop with a spoke because "one DCEL face becomes a two-sided lens" (`FlowRepStrands.cpp`, singular transition block).
   - This matches the producer's own definition of a support: a trace kept to connect its rail "to surrounding cells". It is also §7.2 step 7 (select and simplify the candidate network) and invariant 8: the rule removes a redundant trace and touches no rail, port or singularity support.
7. **F7 — Vase's next failure is P13-j, at assembly.**
   - With CB78's exact source, Vase fails at `terminal=NotProductionReady:completion detail=AssemblyRejected traceSegments=192482 arrangementCells=26817 completedQuads=0 completion=NonManifoldStitchedVertex` (159 s).
   - This is the failure RA-198 probe E reached by a different route (tangent-skip plus needle fall-through). Two independent networks fail the same way, so it is a stage of its own, not an artefact of either rule.
   - → **P13-j**, Review DEFN `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`.
8. **F8 — the preflight's assumptions, checked.**
   - Its source reading of the coverage index, the degree rule and the call wiring stands.
   - Its proposed coverage contract (cross-face transport with bounded unfolding) would not have closed P13-i (F2).
   - Its incidence contract (protect mandatory incidence, forbid new dangling ends) is right in principle. It is not needed once unmet chords are not admitted, because no admitted support is removed by any rule on these fixtures.
   - Its falsifiers are covered:
     - a support that joins two rails is kept (row 882's connector). A chord on another sheet cannot match: rails and keys carry the sheet;
     - crossing chords are kept (row 883);
     - mandatory rails are untouched (row 882);
     - gate and ledger are unchanged (§2);
     - BunnyRandom is unchanged because it fails at A1, before A2a;
     - Vase's new failure is named (F7).

## RA-199.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB77 before the probes. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. The env switches live in a scratch copy of `FlowRepStrands.cpp`; unset is HEAD behaviour:
- `PROBE_S_DUMP`: per support transaction, the verdicts, own-sample nearest distances (same face, edge-sharing faces, vertex-sharing faces, any boundary rail), crossings by other non-rail arcs and boundary ends (`S_SUP`); per-kind totals (`S_SUM`); removed support traces (`S_RM`).
- `PROBE_S_COV=1|2`: coverage candidates also from vertex- or edge-sharing faces in the same region and sheet.
- `PROBE_S_DEG`: protect rail and singularity incidence; forbid a new dangling end.
- `PROBE_S_FIX=1|2`: repeat removal passes to a fixed point (2: re-extract flowlines each pass).
- `PROBE_S_CHORD`: a support with no crossing and both ends on the boundary passes the evidence check.

| Probe | Result |
|---|---|
| A: dump, HEAD behaviour | 4,057 attempted, 0 accepted. Supports 115: coverage fails 102, endpoint fails 115. Proposals 3,942: cycles fail 3,942. Distances as in F2. Vase RED `side-count-unsupported`, `failed=5` (the TB71 locus) |
| B: vertex-star coverage + relaxed degree + fixed point | 13 supports removed (5, 302, 447, 604, 823, 831, 839, 847, 863, 878, 886, 1037, 1052); the second pass removes none. Vase RED `IncompleteSurfaceCellComplex;descriptor=23887;cell=26658;reason=side-count-unsupported;…;failed=3;total=26701`: lenses 20, 422 and 612 remain |
| A2: dump with crossings | 10 of 115 supports unmet (F4); every support ends on the boundary |
| C: chord rule + relaxed degree + edge coverage + fixed point | Exactly the 10 unmet chords removed; the second pass removes none. Coverage removals blocked after the first chord (F6). Vase RED `AssemblyRejected` / `NonManifoldStitchedVertex`, 26,817 cells, 0 quads |
| CB78 exact (no probe) | Vase as in C: `AssemblyRejected`, 26,817 cells, `NonManifoldStitchedVertex` (159 s). Cylinder PASS (7.9 s). BunnyRandom unchanged: `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` (A1, before selection) |
| CB78 gate (TB72 manifest, 883 rows) | **882/883**: only row 283 (O16, macOS LegacyInteger). No shared row changes its verdict against RA-198's CB77 gate; rows 882–883 PASS; longest row 13.7 s |
| CB78 ledger v5 (81 rows) | 0/81, as at CB77; no row changes its verdict or first-failure token. The new tests are appended at the end of the test file, so no ledger assertion line moves |
| Mutants (completion tests rebuilt each time) | M1, rule never called (HEAD behaviour): row 882 fails (chord active, with coverage samples). M2, same-rail condition dropped: row 882 fails (the cross-rail connector is deactivated). M3, meeting check dropped: row 883 fails (crossing chords deactivated). Clean restored: both pass |

## RA-199.3 Rulings

- **DESIGN Amendment 31** (added): an unmet support chord is not admitted to selection.
  - A layout-support trace that returns to the rail it left, crossed or touched by no other non-rail arc, connects nothing. With that rail it only bounds a cell whose corners are its own ends.
  - `build_flow_rep_selection_input` leaves such a trace inactive: no coverage samples, no cycle, reported among the selection's removed arcs.
  - "Returns to the rail" is decided on canonical node keys. Both ends lie on a source vertex or source edge that the same rail's arcs run along.
  - Rails, singularity supports, spokes, proposals and supports that join two rails are untouched. Meeting is symmetric, so one pass is the fixed point.
- **P13-i owner:** what A2a selection admits (`build_flow_rep_selection_input`). CB78 (exact, RA-199.8) fixes it. No tolerance, no coverage change, no change to the selector's transactions.
- **Coverage across faces:** unchanged → **O25** (quality, M7, with O23). The same-face index treats a sample one edge away from a covering arc as uncovered, and the exact degree rule freezes every rail node. Together they make support selection inert. On these fixtures that affects only which near-duplicate supports survive. A later change must state a cross-face intrinsic metric and its own falsifiers.
- **Incidence:** no change. The exact degree rule over-protects (F3), but after Amendment 31 no fixture needs a support removal. The preflight's incidence contract is the reference if O25 is taken up.
- **Proposals:** each remains one required cycle. No probe gave a reason to change that.
- **Next Review DEFN: `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`** (P13-j, probe DEFN on the scratch build, Review track). It can start now on the CB78 scratch state. It must:
  - name the stitched vertex, its source support, and the cells and patches that meet there;
  - decide whether the owner is assembly, completion boundary sharing, or an arrangement node;
  - then freeze an exact patch.

## RA-199.4 CB78 — `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 25713a0c0eb0979155c6954f86f8fb13417d5463 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-199.8 verbatim plus a trailing newline. **Keep its 3 single-space context lines** (lines 5, 7 and 134 of the block). SHA-256 `1d8b80e7f5a07c41643967a140b8290cbd563068abf000ae44775bed8159150d`, 296 lines; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/FlowRepStrands.cpp` | `119 0` | `0b15f6dabf73338950f458d1a3d1d73f8cef25c87c9585a125d3fa09a6ea3aa4` |
  | `tests/FlowRepStrandsPhase15Tests.cpp` | `153 0` | `c7138a4743525a3dafd6ff0d2f694ba323e20e61d8dbc783e35fe5c13c5eeaba` |

- **Content:** `deactivate_unmet_support_chords` (anonymous namespace before `build_flow_rep_selection_input`), called once after the singular-transition spokes and before coverage samples are drawn.
- **Tests (gate rows 882–883), on a two-triangle disk with boundary rails 1 (bottom) and 2 (upper sides):**
  - `FlowRepStrandsPhase15.UnmetSupportChordIsNotAdmittedToSelection`: a support from vertex 0 back to rail 1 meeting nothing is inactive and has no coverage samples. A support from rail 2 to rail 1 that also meets nothing stays active. All 4 rail arcs stay active.
  - `FlowRepStrandsPhase15.CrossingSupportChordsRemainAdmitted`: two chords of rail 1 that cross in face 0 both stay active.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Precheck, apply, numstat or result-hash mismatch → `M6-CP3-PLAN-P13-SUPPORT-CHORD-STOP`.
  - Infrastructure failure → `M6-CP3-CB78A-P13-SUPPORT-CHORD-ORCH` (one retry).

## RA-199.5 TB72 — `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB78's immutable package.

- **Gate:** [manifest](Architecture_M6_TB72_P13_Support_Chord_Full_Gate_Case_Manifest.tsv), 883 rows, SHA-256 `e9eabb064fba1aa625b20931f1b85cf3f441c0c877a81cccd49b73bb5ebd3031`. That is TB71's 881 rows byte for byte plus GUARD rows 882–883.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=883 deferred=81`.
  - Pre-registered **883/883**, membership **964**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=AssemblyRejected`, with `completion=NonManifoldStitchedVertex`.
  - The registered match is the stage, the detail and the code. The macOS counts (26,817 cells, 0 quads) are recorded, not registered (RA-176).
  - Mismatches:
    - `PatchCompletionRejected` or `IncompleteSurfaceCellComplex` (a two-sided cell remains);
    - any other assembly or completion code;
    - `detail=None`, or a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH` (one retry).

## RA-199.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION` | Implementation agent, Linux; RA-199.8, compile only |
| 2 | `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC` | Implementation agent, Linux; gate 883/883, membership 964; Vase RED `completion` / `AssemblyRejected` / `NonManifoldStitchedVertex`, within 600 s |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (P13-j) | Probe DEFN on the CB78 scratch state, then an exact patch |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–2 only. Steps 3–4 are probe DEFNs on the Review track (Claude), on the scratch build. A Review turn that cannot run a scratch probe does not start them; that is a scheduling fact, not a block.

## RA-199.7 Probe scripts (scratch, not committed)

`scratchpad/p13s/`:
- `make_probe_s.py`: the env-switched probes.
- `make_cb78.py`: the CB78 state and mutants M1/M2.
- `make_patch78.py`: the patch, apply check and result hashes.
- `run_vase.sh`: one census process.
- `tb72_manifest.tsv`, `ledger_as_manifest.tsv`.

The per-row gate driver is RA-198's `p13i/gate.py`.

## RA-199.8 Exact CB78 patch

```diff
diff --git a/src/geometry/FlowRepStrands.cpp b/src/geometry/FlowRepStrands.cpp
--- a/src/geometry/FlowRepStrands.cpp
+++ b/src/geometry/FlowRepStrands.cpp
@@ -807,6 +807,124 @@ std::vector<FlowRepArc> build_flow_rep_arcs_from_network(
 
 namespace directional::geometry {
 
+namespace {
+
+// A layout-support trace connects the rail its seed lies on to the
+// surrounding layout. One that returns to that rail without meeting any other
+// trace connects nothing: with the rail it only bounds a cell whose two
+// corners are its own ends. Such a chord is not admitted to selection.
+// Meeting is symmetric and an unmet chord meets no other trace, so
+// deactivating one cannot change whether another is met.
+void deactivate_unmet_support_chords(std::vector<FlowRepArc> &arcs,
+                                     const Eigen::MatrixXi &faces) {
+  using surface_arrangement_detail::NodeKey;
+  const auto node_at = [&](const FlowRepArc &arc, const bool start) {
+    return surface_arrangement_detail::make_node_key(
+        faces, arc.sourceFace,
+        surface_arrangement_detail::bary_to_uv(
+            start ? arc.startBarycentric : arc.endBarycentric));
+  };
+  const auto vertex_pair = [](const int a, const int b) {
+    return std::make_pair(std::min(a, b), std::max(a, b));
+  };
+  const auto edge_of = [&](const NodeKey &key) {
+    return vertex_pair(static_cast<int>(key.edge->first().index()),
+                       static_cast<int>(key.edge->second().index()));
+  };
+
+  std::map<int, std::set<int>> railsAtVertex;
+  std::map<std::pair<int, int>, std::set<int>> railsAlongEdge;
+  std::map<int, std::vector<int>> nonRailArcsByFace;
+  std::map<int, std::vector<int>> supportArcsByTrace;
+  for (const FlowRepArc &arc : arcs) {
+    if (!arc.initiallyActive || arc.sourceFace < 0 ||
+        arc.sourceFace >= faces.rows()) {
+      continue;
+    }
+    if (arc.railId.has_value()) {
+      const int rail = static_cast<int>(arc.railId->index());
+      const NodeKey from = node_at(arc, true);
+      const NodeKey to = node_at(arc, false);
+      for (const NodeKey *key : {&from, &to}) {
+        if (key->kind == 0) {
+          railsAtVertex[key->vertex].insert(rail);
+        } else if (key->kind == 1) {
+          railsAlongEdge[edge_of(*key)].insert(rail);
+        }
+      }
+      if (from.kind == 0 && to.kind == 0) {
+        railsAlongEdge[vertex_pair(from.vertex, to.vertex)].insert(rail);
+      }
+      continue;
+    }
+    nonRailArcsByFace[arc.sourceFace].push_back(arc.id);
+    if (arc.layoutSupport && !arc.singularitySupport && !arc.mandatoryRail) {
+      supportArcsByTrace[arc.supportTraceId].push_back(arc.id);
+    }
+  }
+  const auto rails_at = [&](const NodeKey &key) {
+    if (key.kind == 0) {
+      const auto found = railsAtVertex.find(key.vertex);
+      if (found != railsAtVertex.end()) {
+        return found->second;
+      }
+    } else if (key.kind == 1) {
+      const auto found = railsAlongEdge.find(edge_of(key));
+      if (found != railsAlongEdge.end()) {
+        return found->second;
+      }
+    }
+    return std::set<int>{};
+  };
+
+  std::vector<int> unmetChordArcs;
+  for (const auto &[traceId, arcIds] : supportArcsByTrace) {
+    const FlowRepArc &first = arcs[static_cast<std::size_t>(arcIds.front())];
+    const FlowRepArc &last = arcs[static_cast<std::size_t>(arcIds.back())];
+    const std::set<int> endRails = rails_at(node_at(last, false));
+    bool returnsToRail = false;
+    for (const int rail : rails_at(node_at(first, true))) {
+      returnsToRail = returnsToRail || endRails.count(rail) != 0U;
+    }
+    if (!returnsToRail) {
+      continue;
+    }
+    const std::set<std::uint64_t> ends{
+        flow_rep_detail::embedded_endpoint_key(first, true),
+        flow_rep_detail::embedded_endpoint_key(last, false)};
+    bool met = false;
+    for (const int arcId : arcIds) {
+      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
+      for (const int otherId : nonRailArcsByFace[arc.sourceFace]) {
+        const FlowRepArc &other = arcs[static_cast<std::size_t>(otherId)];
+        if (other.layoutSupport && other.supportTraceId == traceId) {
+          continue;
+        }
+        met = met || flow_rep_detail::segments_cross_2d(arc, other);
+        for (const bool start : {true, false}) {
+          met = met ||
+                (ends.count(flow_rep_detail::embedded_endpoint_key(
+                     other, start)) == 0U &&
+                 flow_rep_detail::point_on_segment_2d(
+                     start ? flow_rep_detail::predicate_start(other)
+                           : flow_rep_detail::predicate_end(other),
+                     flow_rep_detail::predicate_start(arc),
+                     flow_rep_detail::predicate_end(arc)));
+        }
+      }
+    }
+    if (!met) {
+      unmetChordArcs.insert(unmetChordArcs.end(), arcIds.begin(),
+                            arcIds.end());
+    }
+  }
+  for (const int arcId : unmetChordArcs) {
+    arcs[static_cast<std::size_t>(arcId)].initiallyActive = false;
+  }
+}
+
+} // namespace
+
 FlowRepSelectionInput build_flow_rep_selection_input(
     const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
     const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
@@ -1196,6 +1314,7 @@ FlowRepSelectionInput build_flow_rep_selection_input(
     flow_rep_detail::assign_intrinsic_endpoint_keys(spoke, faces);
     input.arcs.push_back(std::move(spoke));
   }
+  deactivate_unmet_support_chords(input.arcs, faces);
 
   const auto target_size_at_barycentric = [&](const int face,
                                                const Eigen::RowVector3d &bary) {
diff --git a/tests/FlowRepStrandsPhase15Tests.cpp b/tests/FlowRepStrandsPhase15Tests.cpp
--- a/tests/FlowRepStrandsPhase15Tests.cpp
+++ b/tests/FlowRepStrandsPhase15Tests.cpp
@@ -2975,3 +2975,156 @@ TEST(FlowRepStrandsPhase15, TenRunSparseNetworkHashIsIdentical) {
     EXPECT_EQ(sparse_hash(repeated), hash);
   }
 }
+
+namespace {
+
+// Two triangles over (0,0)-(2,0)-(1,1). Boundary rail 1 runs along the
+// bottom (0-1-2) and rail 2 along the two upper sides (2-3-0).
+struct SupportChordFixture {
+  Eigen::MatrixXd vertices = Eigen::MatrixXd(4, 3);
+  Eigen::MatrixXi faces = Eigen::MatrixXi(2, 3);
+  directional::geometry::SurfaceCellNetwork network;
+  Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(4, 0.5);
+
+  SupportChordFixture() {
+    vertices << 0.0, 0.0, 0.0,
+                1.0, 0.0, 0.0,
+                2.0, 0.0, 0.0,
+                1.0, 1.0, 0.0;
+    faces << 0, 1, 3,
+             1, 2, 3;
+    attach_source_authority(network, vertices, faces, {0, 0}, {0, 0});
+    add_rail(1, {{0, {1.0, 0.0, 0.0}}, {0, {0.0, 1.0, 0.0}},
+                 {1, {1.0, 0.0, 0.0}}, {1, {0.0, 1.0, 0.0}}});
+    add_rail(2, {{1, {0.0, 1.0, 0.0}}, {1, {0.0, 0.0, 1.0}},
+                 {0, {0.0, 0.0, 1.0}}, {0, {1.0, 0.0, 0.0}}});
+  }
+
+  void add_rail(const int id,
+                const std::vector<std::pair<int, Eigen::RowVector3d>> &points) {
+    directional::geometry::SurfaceCellRail rail(
+        directional::tests::test_hard_rail_id(id));
+    rail.kind = directional::geometry::SurfaceCellRailKind::Boundary;
+    rail.curveId = id;
+    for (int index = 0; index < static_cast<int>(points.size()); ++index) {
+      directional::geometry::SurfaceCellRailSample sample;
+      sample.sourceFace = points[static_cast<std::size_t>(index)].first;
+      sample.barycentric = points[static_cast<std::size_t>(index)].second;
+      sample.railParameter = static_cast<double>(index);
+      sample.position = Eigen::RowVector3d::Zero();
+      for (int corner = 0; corner < 3; ++corner) {
+        sample.position += sample.barycentric[corner] *
+                           vertices.row(faces(sample.sourceFace, corner));
+      }
+      rail.samples.push_back(sample);
+    }
+    network.authoritativeRails.push_back(rail);
+  }
+
+  // A boundary seed on `rail` at `point`; branch 0 traces `segments`.
+  void add_support(const int rail,
+                   const directional::geometry::SurfaceTracePoint &point,
+                   const std::vector<std::tuple<int, Eigen::RowVector3d,
+                                                Eigen::RowVector3d>> &segments) {
+    directional::geometry::SurfaceTraceSeed seed;
+    seed.id = static_cast<int>(network.seeds.size());
+    seed.hardRailId = directional::tests::test_hard_rail_id(rail);
+    seed.provenance = directional::geometry::SurfaceSeedProvenance::Boundary;
+    seed.point = point;
+    network.seeds.push_back(seed);
+    network.traces.resize(4U * network.seeds.size());
+    directional::geometry::SurfaceTraceResult &trace =
+        network.traces[4U * static_cast<std::size_t>(seed.id)];
+    trace.termination = directional::geometry::TraceTerminationReason::Boundary;
+    for (const auto &[face, from, to] : segments) {
+      directional::geometry::SurfaceTraceSegment segment;
+      segment.face = face;
+      segment.startBarycentric = from;
+      segment.endBarycentric = to;
+      segment.family = 0;
+      segment.sign = 1;
+      trace.segments.push_back(segment);
+    }
+  }
+
+  // From vertex 0 across edge 1-3 near vertex 1 back to rail 1 at (1.5, 0).
+  void add_bottom_chord() {
+    add_support(1, {0, Eigen::RowVector3d(1.0, 0.0, 0.0)},
+                {{0, Eigen::RowVector3d(1.0, 0.0, 0.0),
+                  Eigen::RowVector3d(0.0, 0.9, 0.1)},
+                 {1, Eigen::RowVector3d(0.9, 0.0, 0.1),
+                  Eigen::RowVector3d(0.5, 0.5, 0.0)}});
+  }
+};
+
+std::vector<const FlowRepArc *> support_arcs(
+    const directional::geometry::FlowRepSelectionInput &input,
+    const int traceId) {
+  std::vector<const FlowRepArc *> result;
+  for (const FlowRepArc &arc : input.arcs) {
+    if (arc.layoutSupport && arc.supportTraceId == traceId) {
+      result.push_back(&arc);
+    }
+  }
+  return result;
+}
+
+} // namespace
+
+TEST(FlowRepStrandsPhase15, UnmetSupportChordIsNotAdmittedToSelection) {
+  SupportChordFixture fixture;
+  fixture.add_bottom_chord();
+  // From vertex 3 on rail 2 down to rail 1 at (1.75, 0): it meets nothing
+  // either, but it joins two rails.
+  fixture.add_support(2, {1, Eigen::RowVector3d(0.0, 0.0, 1.0)},
+                      {{1, Eigen::RowVector3d(0.0, 0.0, 1.0),
+                        Eigen::RowVector3d(0.25, 0.75, 0.0)}});
+
+  const auto input = directional::geometry::build_flow_rep_selection_input(
+      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
+      0.5);
+
+  const auto chord = support_arcs(input, 0);
+  const auto connector = support_arcs(input, 4);
+  ASSERT_EQ(chord.size(), 2U);
+  ASSERT_EQ(connector.size(), 1U);
+  EXPECT_FALSE(chord[0]->initiallyActive);
+  EXPECT_FALSE(chord[1]->initiallyActive);
+  EXPECT_TRUE(connector[0]->initiallyActive);
+  int activeRails = 0;
+  for (const FlowRepArc &arc : input.arcs) {
+    activeRails += arc.boundaryRail && arc.initiallyActive ? 1 : 0;
+  }
+  EXPECT_EQ(activeRails, 4);
+  for (const auto &sample : input.coverageSamples) {
+    EXPECT_NE(sample.sourceArcId, chord[0]->id);
+    EXPECT_NE(sample.sourceArcId, chord[1]->id);
+  }
+}
+
+TEST(FlowRepStrandsPhase15, CrossingSupportChordsRemainAdmitted) {
+  SupportChordFixture fixture;
+  fixture.add_bottom_chord();
+  // From vertex 2 through the midpoint of edge 1-3 back to rail 1 at
+  // (0.5, 0); it crosses the first chord in face 0.
+  fixture.add_support(1, {1, Eigen::RowVector3d(0.0, 1.0, 0.0)},
+                      {{1, Eigen::RowVector3d(0.0, 1.0, 0.0),
+                        Eigen::RowVector3d(0.5, 0.0, 0.5)},
+                       {0, Eigen::RowVector3d(0.0, 0.5, 0.5),
+                        Eigen::RowVector3d(0.5, 0.5, 0.0)}});
+
+  const auto input = directional::geometry::build_flow_rep_selection_input(
+      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
+      0.5);
+
+  const auto first = support_arcs(input, 0);
+  const auto second = support_arcs(input, 4);
+  ASSERT_EQ(first.size(), 2U);
+  ASSERT_EQ(second.size(), 2U);
+  for (const FlowRepArc *arc : first) {
+    EXPECT_TRUE(arc->initiallyActive);
+  }
+  for (const FlowRepArc *arc : second) {
+    EXPECT_TRUE(arc->initiallyActive);
+  }
+}
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB72 manifest is TB71's 881 rows byte for byte plus rows 882–883; `SELF_CHECK_PASS cases=883 deferred=81` with harness P8 |
| Decisive claims independently re-derived | HEAD-behaviour dump reproduces TB71's Vase locus and RA-198's 0-of-4,057 census. Every support transaction dumped with distances and crossings. Cross-face coverage, relaxed degree, fixed point and chord probes. Clean build of the exact patch (gate, ledger, census). Mutants. Patch applied to HEAD with both result SHA-256 reproduced; embedded block re-hashed |
| Non-vacuity checked | Each of the rule's three conditions binds a GUARD row: M1 and M2 fail row 882, M3 fails row 883. The selector census counts every transaction; the crossing census names every unmet chord, and the exact patch reproduces probe C's 26,817 cells |
| Prior obligations discharged/carried | P13-i attributed and routed (CB78/TB72). P13-j new → `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`. O25 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, O21, O22, O23, O24, DR1/DR3, DR2/DR4, O2b, O15b, O7 |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | O25 (inert support selection: same-face coverage and exact rail-node degrees); P13-j |
| ORIENTATION currency line | Updated to RA-199 / CB78 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: check which relation a guard can see before tuning it |
| Consolidation under CLEAN_UP_POLICY | The preflight and the static review stay as history, each with a superseded note pointing here |
| Successor frozen | CB78 (RA-199.4, exact RA-199.8) → TB72 (RA-199.5); Review DEFN `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED; `ledgers --base 16cc9a268` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB78 |
| Pushed to origin, branch in sync | Pushed to `origin/agent/surface_cell_quad/p5-recover-bridge-healing` as a fast-forward, no force; `git status -sb` confirms sync |
