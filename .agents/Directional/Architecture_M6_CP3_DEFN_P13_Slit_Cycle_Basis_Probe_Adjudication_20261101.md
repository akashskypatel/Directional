# RA-192 — P13-c slit: probe adjudication of RA-191 and exact CB66 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (Review/Definition), reopened and closed on an authentic Git checkout at `57136b395`. RA-192 keeps RA-191's diagnosis and its rejection of a rail exemption and of midpoint insertion. It replaces RA-191's general edge-side incidence product, its consumer-wide scope and its open-ended CB66 with one narrow, probe-verified adapter, delivered as an exact patch (RA-192.8). DESIGN.md Amendment 25 is rewritten and Amendment 15.3 restored to match.

## RA-192.1 Review of RA-191

**Upheld.**
- **The diagnosis**, re-observed at current source (`dbc38661…`). BunnyRandom region 0 (χ 2, no boundary) has 17 hard-feature edges in 7 tree components. Two components are single edges whose endpoints are both interior tips (`68–216`, `169–331`). The face array keeps each glued, so the cut gives χ −3 with 5 loops against the identity's −5 with 7.
- **No transport across a hard barrier** (no rail exemption), **no midpoint insertion or synthetic vertex**, and identity 15.4 unchanged.

**Defects.**

| # | RA-191 text | Finding |
|---|---|---|
| D1 | A1 builds an edge-side incidence complex with canonical dart identities; "all A1 transport walks, local boundary cycles, holonomy/index/`dual_cycles`, singularity attachment and later transport consumers must use its cut incidence" | **Scope overstated.** Transport adjacency is built from source edges and already excludes every hard-feature edge (`FieldTransportAtlas.cpp:2082–2086`, `FieldTransportBarrierKind::HardFeature`), so no walk, transition or later stage can cross a slit. The cut mesh (`LocalRegionMesh`) is file-local and read only by A1's region loop: the Euler/boundary identity, `PCFaceTangentBundle` → `dual_cycles`, boundary-loop association and `componentTopology`. The defect is confined there. |
| D2 | Collapse attributed to "isolated tip–tip" edges, with no argument that nothing else collapses | **Proved, so 15.3 needs exactly one exception.** The two faces of a barrier edge `e = (u, v)` share a copy of `u` exactly when they lie in one component of `star(u) ∖ B`. At an interior vertex with `d_B(u) = 1` they always do; with `d_B(u) ≥ 2`, or with `u` on the region's local boundary, `e` separates them. Two distinct source edges never share an endpoint pair. So the face array glues a barrier edge exactly when both its endpoints are interior tips, and realises every other configuration. |
| D3 | CB66: "implement the smallest shared A1 cut-side occurrence producer and its transport/cycle consumers", tests "as required" | **Monolithic and open-ended**: design and test authoring handed to the implementation agent. Replaced by the exact patch in RA-192.8. |
| D4 | Falsifiers 1–2 on tetrahedral and octahedral spheres | **Not executable through the atlas.** A1 accepts vertex singularities with 3–6 ports, i.e. index ≤ 1 (`FieldTransportAtlas.cpp:574–581`), and a tetrahedron needs total index 8 on four vertices. On an octahedron, zero-transport lifts are 4/3. Replaced by planar grids, where a zero-transport field is valid, and the genus-1 torus fixture. |
| D5 | Falsifier 4 (face-row reorder, winding reversal); falsifier 5 (mutants as typed-error tests) | 4 tests no property this change introduces: slits are ordered by source edge, and the rest is existing face-array behaviour. 5 is a Review activity, done in RA-192.3. |
| D6 | Falsifier 6 and TB65: the 866 manifest and ledger "remain immutable", new tests "separately enumerated", counts "derived from actual compiled binary" | **Would fail membership** (RA-190 R7 again). Three new tests in a gated binary make membership 950, and P8 rejects the 866 manifest. Deriving counts during TB-EXEC also moves pre-registration to the executor. The 869-row manifest is frozen now (RA-192.6). |
| D7 | TB65: BunnyRandom must "reach a genuine later stage or complete" | **Not pre-registered.** Probes give the exact next failure on macOS and in an FMA-off build (RA-192.3). |
| D8 | No probe | Decided from source reading. RA-192.3 supplies the probes. |

## RA-192.2 The adapter (Amendment 25, rewritten)

- **Detection.** After the face-array cut, `make_local_region_mesh` records each inner edge of the cut mesh whose source edge is a barrier and whose endpoints both have barrier degree 1 and lie off the region's uncut boundary. By D2 these are exactly the glued edges. They are ordered by source edge.
- **Accounting.** `χ_cut = V − E + F − s` and `b_cut = loops + s` for `s` slits. The boundary-multiplicity check counts each slit's two sides, so a glued barrier edge that is not a slit still fails closed.
- **Cycle basis** (`cut_cycle_basis`). Start from `dual_cycles` on the face array.
  - For each slit, the two tip rows merge into one boundary-loop row `ring(u) + ring(v)`, placed after the face-array loops. The slit column cancels, because `ring(u)` holds −1 and `ring(v)` +1 there.
  - The slit column is removed.
  - The curvature is `κ(u) + κ(v) − 2π = 2π − Σθ(u) − Σθ(v)`. That is `dual_cycles`' boundary formula for the vertex set `{u, v}` with all of their corners.
  - The loop's vertex list is `[u, v]`.

  This is the row `dual_cycles` would build on a mesh able to represent the slit; no other vertex ring contains the slit column.
- **Handle generators.** A generator row that is nonzero on a slit column fails closed as `IncompleteCycleBasis` with the new reason `HandleGeneratorCrossesSlit`, located at the slit's source edge (O19). The row is not rewritten, because `dual_cycles`' generator curvature is a side-set formula, not linear in the row. A distinct reason keeps 15.4's guarantee that a barrier never raises `CycleTransportAdjacencyMissing`.
- **No slit, no change.** The row and column maps are the identity, and the triplets and curvatures are unchanged.
- **Untouched:** transport adjacency, transitions, singularity binding, A2a–A9 and rail policy. A singular tip binds to its slit loop through `slitCycleByGlobalVertex`, as any barrier tip does.

## RA-192.3 Probe findings (macOS, scratch build, diagnostic only)

| Probe | Result |
|---|---|
| 869-row candidate gate | **868/869.** Only row 283 (O16) fails. Only the three new rows reach a slit, so the change is inert on every existing gate fixture. |
| 81 deferred rows, slit off vs on | **81/81 RED in both modes.** Only row 360 (BunnyRandom) reaches a slit; it moves from `CutTransportDomainIdentityMismatch` to the P13-e failure below. Vase (row 365) has no slit and is unchanged. |
| BunnyRandom | Identity passes (cutChi −5, 7 loops), and the cycle basis is built. The next failure is `SingularityPortClassCountMismatch` at vertex 49. Its index is −1, so 5 port classes are expected, but only 4 incidences are found, in fan faces 0, 2, 4 and 6 of 8. An FMA-off build gives the same result, so this is not an FMA tie. Recorded as **P13-e**. |
| Torus sweep: each of 216 edges as the only hard edge | 181 succeed with χ −1, b 1, genus 1 and 2 handles. 35 fail closed because a `dual_cycles` generator crosses the slit: **O19**. |
| Mutants | M1 (no slit detection, i.e. HEAD) fails all three new tests. M2 (slit-loop curvature without the −2π) fails rows 867 and 868. M3 (no generator guard) fails row 869. All three pass on the patch. |
| Membership | 950 = 869 gated + 81 deferred, listed from the built binaries, no overlap. P8: `SELF_CHECK_PASS cases=869 deferred=81` |
| Census | Cylinder PASS. BunnyRandom RED `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, with `cutChi=-5,uncutBoundaryLoops=0,cutBoundaryLoops=7` and no `CutTransportDomainIdentityMismatch`. Vase RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence`, unchanged. |

## RA-192.4 Rulings

- **Amendment 25 (rewritten):**
  - The face array realises every barrier except the slit of D2.
  - A1 applies each slit exactly in its cut accounting and its `dual_cycles` basis.
  - A generator that crosses a slit fails closed (`HandleGeneratorCrossesSlit`).
  - RA-191's general incidence product, dart identities and consumer-wide adoption are withdrawn.
- **Amendment 15.3** reads as before, with this one exception.
- **P13-c:** discharged when TB65 matches.
- **P13-e (new):** A1 requires `4 − index` port classes at every non-barrier singularity. BunnyRandom's smooth field on its random triangulation has 4 sector incidences at index −1 vertex 49, on both builds. The open question is whether A1's sector rule or the field owns this.
  - Owner: `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (Review, probes), after TB65 confirms it on Linux.
- **O19 (new):** `HandleGeneratorCrossesSlit`, a genus > 0 region whose `dual_cycles` generator crosses a slit (35 of 216 torus edges).
  - Not CP3-blocking: all six design-acceptance fixtures are genus 0 (Plane, MultiFaceSeam and Vase χ 1; Cylinder χ 0 with 2 loops; CloseSheets and BunnyRandom χ 2).
  - Owner: a later DEFN, raised when a fixture needs it.
- **RA-191 IDs superseded:**
  - CB66 becomes `M6-CP3-CB66-P13-SLIT-CYCLE-BASIS`.
  - TB65 becomes `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC`.
  - `M6-CP3-PLAN-P13-CUT-INCIDENCE-ADAPTER-STOP` is withdrawn.
- **Carried:** P13-d with O18 (Vase), O6, O9, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b.

## RA-192.5 CB66 — exact patch

`M6-CP3-CB66-P13-SLIT-CYCLE-BASIS`: implementation agent, Linux workflow runner, compile only.

| Item | Value |
|---|---|
| Precheck | `git diff --quiet dbc38661efabdfa051f48f8f71ee3c604841842c HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Patch | RA-192.8 block, verbatim plus a trailing newline. SHA-256 `c83fefa2298e8fb5fc1b6ef14a8fe47f46ce5cf92d0acc89f4fd6d7da0c4377c`. Run `git apply --check`, then apply. |
| Numstat | `1 0` `include/directional/authority/FieldTransportAtlas.h`; `173 33` `src/authority/FieldTransportAtlas.cpp`; `182 0` `tests/FieldAlignedCurveNetworkTests.cpp` |
| Result SHA-256 | header `b73e5adc88812d1106bed5936d8cf9a5480c7ef48f3d5defbe502567e345b78f`; atlas `514d49656cf53d16d3472f41392f0e57a33f3facccb5533719fa1e331e249b89`; network tests `e9f13aa4dc0f3acbaa2c8c0f18575d08f0771d7ebcf63feea30f0a2b95b9a560` |
| Build | `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256. No native runs. |
| Outcomes | Exact → TB65. A patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-SLIT-STOP` (Review). Infrastructure failure → `M6-CP3-CB66A-P13-SLIT-ORCH` (one retry). |

## RA-192.6 TB65 — frozen inputs and pre-registered outcomes

`M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC`: implementation agent, Linux workflow runner, on the verified CB66 package only.

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv`, **869 rows**, SHA-256 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`. It is the TB64 866-row manifest byte-for-byte, plus GUARD rows 867 `ra192:slit-two-sided`, 868 `ra192:slit-with-arc` and 869 `ra192:torus-slit`. `SELF_CHECK_PASS cases=869 deferred=81` |
| Ledger | v5, 81 rows, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, unchanged |
| Census | `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` `3af1dc0d…`, no ledger, one fresh process per row |
| Harness | P8 `78b8002c…`, unchanged |

| Run | Pre-registered outcome |
|---|---|
| Gate | **869/869 PASS**, membership **950**, postflight true |
| Census row 1, Cylinder | PASS |
| Census row 2, BunnyRandom | RED `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, with `cutChi=-5,uncutBoundaryLoops=0,cutBoundaryLoops=7` and no `CutTransportDomainIdentityMismatch` |
| Census row 3, Vase | RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence` (unchanged) |

Mismatch routes:
- Any gate RED, membership other than 950, or a census signature mismatch → `M6-CP3-TB65-P13-SLIT-FULL-GATE-REV` (Review).
- Infrastructure failure → `M6-CP3-TB65A-P13-SLIT-ORCH` (one retry).

No TB65-REV is needed when everything matches.

## RA-192.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB66-P13-SLIT-CYCLE-BASIS` | Implementation agent, Linux; exact patch, compile only |
| 2 | `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869 + census 3 |
| 3 (Review, parallel with 1–2) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d with O18) → CB → TB | Review (probes) → implementation agent |
| 4 (Review, after 2) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Review (probes) → implementation agent |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | Per slice |

## RA-192.8 Exact CB66 patch

SHA-256 of the block content plus a trailing newline: `c83fefa2298e8fb5fc1b6ef14a8fe47f46ce5cf92d0acc89f4fd6d7da0c4377c`.

Seven lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the patched source is clean under `git diff --check`.

```diff
diff --git a/include/directional/authority/FieldTransportAtlas.h b/include/directional/authority/FieldTransportAtlas.h
index 206c9a1b2..ea8fe47db 100644
--- a/include/directional/authority/FieldTransportAtlas.h
+++ b/include/directional/authority/FieldTransportAtlas.h
@@ -108,6 +108,7 @@ enum class IncompleteCycleBasisReason : std::uint8_t {
   CycleOrderingFailed = 5,
   CycleKindPartitionMismatch = 6,
   BoundaryCycleCountMismatch = 7,
+  HandleGeneratorCrossesSlit = 8,
 };
 
 struct FieldAtlasRegionCycleBasisDiagnostics {
diff --git a/src/authority/FieldTransportAtlas.cpp b/src/authority/FieldTransportAtlas.cpp
index 24e04e79c..6762a9687 100644
--- a/src/authority/FieldTransportAtlas.cpp
+++ b/src/authority/FieldTransportAtlas.cpp
@@ -982,6 +982,10 @@ struct LocalRegionMesh {
   std::vector<int> globalVertexByLocal;
   std::set<int> barrierVertices;
   std::map<int, std::size_t> transportStarComponentCountByGlobalVertex;
+  // Rows of mesh.EV that are slits (Amendment 25): barrier edges whose two
+  // endpoints are interior barrier tips, so the face array keeps both sides
+  // glued. Sorted by source edge.
+  std::vector<int> slitEdges;
   FieldTransportRegionDiagnostics diagnostics;
   bool uncutAuthorityMatches = false;
   bool cutIdentityValid = false;
@@ -1263,10 +1267,36 @@ std::optional<LocalRegionMesh> make_local_region_mesh(
   } catch (const std::exception &) {
     return std::nullopt;
   }
+
+  // Amendment 25: a tip has one vertex copy, so a barrier edge whose two
+  // endpoints are interior tips stays an inner edge of the face array. Each
+  // such slit adds one edge and one two-edge boundary loop to the cut.
+  std::map<SourceEdgeTopologyKey, int> slitEdgeByKey;
+  for (int edge = 0; edge < result.mesh.EV.rows(); ++edge) {
+    if (result.mesh.EF(edge, 1) < 0) continue;
+    const int first = result.globalVertexByLocal[static_cast<std::size_t>(
+        result.mesh.EV(edge, 0))];
+    const int second = result.globalVertexByLocal[static_cast<std::size_t>(
+        result.mesh.EV(edge, 1))];
+    const auto key = SourceEdgeTopologyKey::from_indices(
+        first, second, static_cast<std::size_t>(sourceMesh.V.rows()));
+    if (!key || barrierEdges.count(key.value()) == 0U) continue;
+    if (barrierAdjacency[first].size() == 1U &&
+        barrierAdjacency[second].size() == 1U &&
+        uncutBoundaryGlobalVertices.count(first) == 0U &&
+        uncutBoundaryGlobalVertices.count(second) == 0U) {
+      slitEdgeByKey.emplace(key.value(), edge);
+    }
+  }
+  for (const auto &[key, edge] : slitEdgeByKey) {
+    result.slitEdges.push_back(edge);
+  }
+  const int slitCount = static_cast<int>(result.slitEdges.size());
   result.diagnostics.cutEulerCharacteristic = static_cast<int>(
-      result.mesh.V.rows() - result.mesh.EV.rows() + result.mesh.F.rows());
+      result.mesh.V.rows() - result.mesh.EV.rows() + result.mesh.F.rows()) -
+      slitCount;
   result.diagnostics.cutBoundaryLoopCount =
-      static_cast<int>(result.mesh.boundaryLoops.size());
+      static_cast<int>(result.mesh.boundaryLoops.size()) + slitCount;
   result.diagnostics.newSlitBoundaryLoopCount =
       result.diagnostics.cutBoundaryLoopCount -
       result.diagnostics.uncutBoundaryLoopCount;
@@ -1283,6 +1313,9 @@ std::optional<LocalRegionMesh> make_local_region_mesh(
     if (!key) return std::nullopt;
     ++cutBoundaryMultiplicity[key.value()];
   }
+  for (const auto &[key, edge] : slitEdgeByKey) {
+    cutBoundaryMultiplicity[key] += 2U;
+  }
   bool boundaryRealizationValid = true;
   for (const auto &[edge, count] : cutBoundaryMultiplicity) {
     const std::size_t expected = barrierEdges.count(edge) != 0U
@@ -1315,6 +1348,108 @@ std::optional<LocalRegionMesh> make_local_region_mesh(
   return result;
 }
 
+// Cycle basis of a region's cut transport domain: dual_cycles of the face
+// array with each slit applied exactly (Amendment 25). A slit's two tip rows
+// become one boundary-loop row, in which the slit column cancels, and the slit
+// column is removed. The loop's curvature is 2*pi minus the angle sums at both
+// tips, which is dual_cycles' boundary formula. Rows are interior vertices,
+// face-array boundary loops, slit loops, then handle generators.
+struct LocalCutCycleBasis {
+  Eigen::SparseMatrix<double> cycles;
+  Eigen::VectorXd cycleCurvatures;
+  Eigen::VectorXi innerAdjacencies;
+  std::vector<int> interiorVertices;
+  std::vector<std::vector<int>> boundaryLoops;
+  // A handle generator that crosses a slit would need transport across a
+  // barrier; it is reported, not rewritten.
+  std::optional<int> generatorSlitEdge;
+};
+
+// Throws whatever PCFaceTangentBundle::init throws.
+LocalCutCycleBasis cut_cycle_basis(const LocalRegionMesh &local) {
+  PCFaceTangentBundle bundle;
+  bundle.init(local.mesh);
+  LocalCutCycleBasis basis;
+  basis.boundaryLoops = local.mesh.boundaryLoops;
+  std::map<int, int> slitByTip;
+  std::set<int> slitEdges(local.slitEdges.begin(), local.slitEdges.end());
+  for (std::size_t slit = 0; slit < local.slitEdges.size(); ++slit) {
+    const int edge = local.slitEdges[slit];
+    slitByTip.emplace(local.mesh.EV(edge, 0), static_cast<int>(slit));
+    slitByTip.emplace(local.mesh.EV(edge, 1), static_cast<int>(slit));
+    basis.boundaryLoops.push_back(
+        {local.mesh.EV(edge, 0), local.mesh.EV(edge, 1)});
+  }
+
+  std::vector<int> meshInterior;
+  for (int vertex = 0; vertex < local.mesh.V.rows(); ++vertex) {
+    if (local.mesh.isBoundaryVertex(vertex) == 0) meshInterior.push_back(vertex);
+  }
+  // dual_cycles rows are the face array's interior vertices, its boundary
+  // loops, then handle generators; each slit merges two rows into one.
+  const int interiorRows = static_cast<int>(meshInterior.size());
+  const int generatorRowBegin =
+      interiorRows + static_cast<int>(local.mesh.boundaryLoops.size());
+  const int slitCount = static_cast<int>(local.slitEdges.size());
+  const int slitRowBegin = generatorRowBegin - 2 * slitCount;
+  const int rowCount = static_cast<int>(bundle.cycles.rows()) - slitCount;
+  std::vector<int> rowMap(static_cast<std::size_t>(bundle.cycles.rows()));
+  int nextRow = 0;
+  for (int row = 0; row < bundle.cycles.rows(); ++row) {
+    if (row == generatorRowBegin) nextRow += slitCount;
+    if (row < interiorRows) {
+      const int vertex = meshInterior[static_cast<std::size_t>(row)];
+      const auto slit = slitByTip.find(vertex);
+      if (slit != slitByTip.end()) {
+        rowMap[static_cast<std::size_t>(row)] = slitRowBegin + slit->second;
+        continue;
+      }
+      basis.interiorVertices.push_back(vertex);
+    }
+    rowMap[static_cast<std::size_t>(row)] = nextRow++;
+  }
+
+  std::vector<int> columnMap(
+      static_cast<std::size_t>(bundle.innerAdjacencies.size()), -1);
+  std::vector<int> innerAdjacencies;
+  for (int column = 0; column < bundle.innerAdjacencies.size(); ++column) {
+    if (slitEdges.count(bundle.innerAdjacencies(column)) != 0U) continue;
+    columnMap[static_cast<std::size_t>(column)] =
+        static_cast<int>(innerAdjacencies.size());
+    innerAdjacencies.push_back(bundle.innerAdjacencies(column));
+  }
+
+  std::vector<Eigen::Triplet<double>> triplets;
+  for (int column = 0; column < bundle.cycles.outerSize(); ++column) {
+    for (Eigen::SparseMatrix<double>::InnerIterator it(bundle.cycles, column);
+         it; ++it) {
+      const int mappedColumn = columnMap[static_cast<std::size_t>(it.col())];
+      if (mappedColumn < 0) {
+        if (it.row() >= generatorRowBegin) {
+          basis.generatorSlitEdge = bundle.innerAdjacencies(it.col());
+        }
+        continue;
+      }
+      triplets.emplace_back(rowMap[static_cast<std::size_t>(it.row())],
+                            mappedColumn, it.value());
+    }
+  }
+  basis.cycles.resize(rowCount, static_cast<int>(innerAdjacencies.size()));
+  basis.cycles.setFromTriplets(triplets.begin(), triplets.end());
+  basis.innerAdjacencies = Eigen::Map<const Eigen::VectorXi>(
+      innerAdjacencies.data(), static_cast<int>(innerAdjacencies.size()));
+
+  basis.cycleCurvatures = Eigen::VectorXd::Zero(rowCount);
+  for (int slit = 0; slit < slitCount; ++slit) {
+    basis.cycleCurvatures(slitRowBegin + slit) = -2.0 * std::numbers::pi;
+  }
+  for (int row = 0; row < bundle.cycles.rows(); ++row) {
+    basis.cycleCurvatures(rowMap[static_cast<std::size_t>(row)]) +=
+        bundle.cycleCurvatures(row);
+  }
+  return basis;
+}
+
 std::vector<FieldAtlasRegionCycleBasisDiagnostics>
 collect_cycle_basis_diagnostics(
     const TriMesh &sourceMesh,
@@ -1332,11 +1467,11 @@ collect_cycle_basis_diagnostics(
 
     row.localMeshAvailable = true;
     row.vertexCount = static_cast<std::size_t>(local->mesh.V.rows());
-    row.edgeCount = static_cast<std::size_t>(local->mesh.EV.rows());
+    row.edgeCount = static_cast<std::size_t>(local->mesh.EV.rows()) +
+                    local->slitEdges.size();
     row.faceCount = static_cast<std::size_t>(local->mesh.F.rows());
-    row.eulerCharacteristic = static_cast<int>(
-        local->mesh.V.rows() - local->mesh.EV.rows() + local->mesh.F.rows());
-    row.boundaryLoopCount = static_cast<int>(local->mesh.boundaryLoops.size());
+    row.eulerCharacteristic = local->diagnostics.cutEulerCharacteristic;
+    row.boundaryLoopCount = local->diagnostics.cutBoundaryLoopCount;
     const int genusNumerator =
         2 - row.boundaryLoopCount - row.eulerCharacteristic;
     if (genusNumerator >= 0 && genusNumerator % 2 == 0) {
@@ -1347,20 +1482,20 @@ collect_cycle_basis_diagnostics(
         ++row.interiorLocalVertexCount;
       }
     }
+    row.interiorLocalVertexCount -= 2U * local->slitEdges.size();
     if (row.genus >= 0) {
       row.expectedCycleCount =
           static_cast<int>(row.interiorLocalVertexCount) +
           row.boundaryLoopCount + 2 * row.genus;
     }
 
-    PCFaceTangentBundle bundle;
     try {
-      bundle.init(local->mesh);
+      const LocalCutCycleBasis basis = cut_cycle_basis(*local);
       row.bundleInitialized = true;
-      row.cycleRowCount = static_cast<std::size_t>(bundle.cycles.rows());
-      row.cycleCurvatureCount = bundle.cycleCurvatures.size();
+      row.cycleRowCount = static_cast<std::size_t>(basis.cycles.rows());
+      row.cycleCurvatureCount = basis.cycleCurvatures.size();
       row.innerAdjacencyCount =
-          static_cast<std::size_t>(bundle.innerAdjacencies.size());
+          static_cast<std::size_t>(basis.innerAdjacencies.size());
     } catch (const std::exception &) {
       row.bundleInitialized = false;
     }
@@ -2486,37 +2621,39 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
     }
     const int genus = genusNumerator / 2;
 
-    PCFaceTangentBundle bundle;
+    LocalCutCycleBasis basis;
     try {
-      bundle.init(local->mesh);
+      basis = cut_cycle_basis(*local);
     } catch (const std::exception &) {
       return incomplete_cycle_basis_failure(
           sourceMesh, sourceAuthority,
           IncompleteCycleBasisReason::LocalTangentBundleInitializationFailed,
           std::nullopt, region.id(), hardFeatureEdges);
     }
-    std::vector<int> interiorLocalVertices;
-    for (int vertex = 0; vertex < local->mesh.V.rows(); ++vertex) {
-      if (local->mesh.isBoundaryVertex(vertex) == 0) {
-        interiorLocalVertices.push_back(vertex);
-      }
+    if (basis.generatorSlitEdge.has_value()) {
+      return incomplete_cycle_basis_failure(
+          sourceMesh, sourceAuthority,
+          IncompleteCycleBasisReason::HandleGeneratorCrossesSlit,
+          global_edge_key(*local, *basis.generatorSlitEdge, vertexExtent),
+          region.id(), hardFeatureEdges);
     }
+    const std::vector<int> &interiorLocalVertices = basis.interiorVertices;
     const int expectedHandleCount = 2 * genus;
     const int expectedCycleCount =
         static_cast<int>(interiorLocalVertices.size()) + boundaryLoopCount +
         expectedHandleCount;
-    if (bundle.cycles.rows() != expectedCycleCount ||
-        bundle.cycleCurvatures.size() != expectedCycleCount ||
-        bundle.cycles.cols() != bundle.innerAdjacencies.size()) {
+    if (basis.cycles.rows() != expectedCycleCount ||
+        basis.cycleCurvatures.size() != expectedCycleCount ||
+        basis.cycles.cols() != basis.innerAdjacencies.size()) {
       return incomplete_cycle_basis_failure(
           sourceMesh, sourceAuthority,
           IncompleteCycleBasisReason::CycleDimensionCountMismatch, std::nullopt,
           region.id(), hardFeatureEdges);
     }
 
-    Eigen::VectorXd effort(bundle.innerAdjacencies.size());
-    for (int column = 0; column < bundle.innerAdjacencies.size(); ++column) {
-      const int localEdge = bundle.innerAdjacencies(column);
+    Eigen::VectorXd effort(basis.innerAdjacencies.size());
+    for (int column = 0; column < basis.innerAdjacencies.size(); ++column) {
+      const int localEdge = basis.innerAdjacencies(column);
       const SourceEdgeTopologyKey edge =
           global_edge_key(*local, localEdge, vertexExtent);
       const auto transition = transitionByEdge.find(edge);
@@ -2540,12 +2677,12 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
       }
     }
     const Eigen::VectorXd exactLifts =
-        ((bundle.cycles * effort +
+        ((basis.cycles * effort +
           static_cast<double>(fields::kCrossFieldDegree) *
-              bundle.cycleCurvatures)
+              basis.cycleCurvatures)
              .array() /
          (2.0 * std::numbers::pi));
-    Eigen::SparseMatrix<double, Eigen::RowMajor> rowCycles = bundle.cycles;
+    Eigen::SparseMatrix<double, Eigen::RowMajor> rowCycles = basis.cycles;
 
     const std::size_t componentCycleBegin = cycles.size();
     std::vector<std::size_t> localCycleIndices;
@@ -2569,13 +2706,13 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
         // zeros. They are representation storage, not semantic cycle support.
         if (std::abs(coefficient) < kIntegerTolerance) continue;
         if (std::abs(std::abs(coefficient) - 1.0) >= kIntegerTolerance ||
-            it.col() < 0 || it.col() >= bundle.innerAdjacencies.size()) {
+            it.col() < 0 || it.col() >= basis.innerAdjacencies.size()) {
           return incomplete_cycle_basis_failure(
               sourceMesh, sourceAuthority,
               IncompleteCycleBasisReason::CycleCoefficientInvalid, std::nullopt,
               region.id(), hardFeatureEdges);
         }
-        const int localEdge = bundle.innerAdjacencies(it.col());
+        const int localEdge = basis.innerAdjacencies(it.col());
         const SourceEdgeTopologyKey edge =
             global_edge_key(*local, localEdge, vertexExtent);
         const FieldTransportAdjacency *adjacency =
@@ -2745,18 +2882,18 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
       }
       witness.indexSum = requiredIndexSum;
     }
-    if (boundaryCycleIndices.size() != local->mesh.boundaryLoops.size()) {
+    if (boundaryCycleIndices.size() != basis.boundaryLoops.size()) {
       return incomplete_cycle_basis_failure(
           sourceMesh, sourceAuthority,
           IncompleteCycleBasisReason::BoundaryCycleCountMismatch, std::nullopt,
           region.id(), hardFeatureEdges);
     }
     for (std::size_t loopIndex = 0;
-         loopIndex < local->mesh.boundaryLoops.size(); ++loopIndex) {
+         loopIndex < basis.boundaryLoops.size(); ++loopIndex) {
       const FieldCycleId boundaryCycle =
           cycles[boundaryCycleIndices[loopIndex]].id;
       const std::vector<int> &localBoundaryLoop =
-          local->mesh.boundaryLoops[loopIndex];
+          basis.boundaryLoops[loopIndex];
       std::vector<SourceEdgeTopologyKey> sourceBoundarySupport;
       sourceBoundarySupport.reserve(localBoundaryLoop.size());
       for (std::size_t edgeIndex = 0; edgeIndex < localBoundaryLoop.size();
@@ -2836,7 +2973,8 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
         region.id(), region.component(), eulerCharacteristic,
         boundaryLoopCount, genus,
         static_cast<std::size_t>(local->mesh.V.rows()),
-        static_cast<std::size_t>(local->mesh.EV.rows()),
+        static_cast<std::size_t>(local->mesh.EV.rows()) +
+            local->slitEdges.size(),
         static_cast<std::size_t>(local->mesh.F.rows()),
         localCycleIndices.size(), handleCycleIndices.size()});
     FieldTransportRegionDiagnostics regionDiagnostics = local->diagnostics;
@@ -3252,6 +3390,8 @@ const char *incomplete_cycle_basis_reason_name(
     return "CycleKindPartitionMismatch";
   case IncompleteCycleBasisReason::BoundaryCycleCountMismatch:
     return "BoundaryCycleCountMismatch";
+  case IncompleteCycleBasisReason::HandleGeneratorCrossesSlit:
+    return "HandleGeneratorCrossesSlit";
   }
   return "Unknown";
 }
diff --git a/tests/FieldAlignedCurveNetworkTests.cpp b/tests/FieldAlignedCurveNetworkTests.cpp
index ad5883a38..36b9f1754 100644
--- a/tests/FieldAlignedCurveNetworkTests.cpp
+++ b/tests/FieldAlignedCurveNetworkTests.cpp
@@ -18018,3 +18018,185 @@ TEST(TestFixturePaths, MissingPackageFailsClosedInsteadOfReturningMissingPath) {
   EXPECT_THROW((void)directional::tests::require_test_data_root(missing),
                std::runtime_error);
 }
+
+namespace {
+
+// Planar n-by-n vertex grid; every interior vertex has six incident faces.
+TriMesh make_planar_grid_mesh(const int side) {
+  Eigen::MatrixXd vertices(side * side, 3);
+  for (int row = 0; row < side; ++row) {
+    for (int column = 0; column < side; ++column) {
+      vertices.row(row * side + column) << column, row, 0.0;
+    }
+  }
+  Eigen::MatrixXi faces(2 * (side - 1) * (side - 1), 3);
+  int face = 0;
+  for (int row = 0; row + 1 < side; ++row) {
+    for (int column = 0; column + 1 < side; ++column) {
+      const int corner = row * side + column;
+      faces.row(face++) << corner, corner + 1, corner + side + 1;
+      faces.row(face++) << corner, corner + side + 1, corner + side;
+    }
+  }
+  TriMesh mesh;
+  mesh.set_mesh(vertices, faces);
+  return mesh;
+}
+
+bool cycle_steps_all_touch(const directional::authority::FieldCycleWitness &cycle,
+                        const std::set<std::size_t> &vertices) {
+  return std::all_of(cycle.steps.begin(), cycle.steps.end(),
+                     [&](const auto &step) {
+                       return vertices.count(step.sourceEdge.first().index()) !=
+                                  0U ||
+                              vertices.count(step.sourceEdge.second().index()) !=
+                                  0U;
+                     });
+}
+
+} // namespace
+
+// Amendment 25: an interior hard-feature edge whose endpoints are both
+// interior barrier tips is a slit. The face array keeps its two sides glued,
+// so A1 cuts it in the cycle basis: one more edge, one two-edge boundary loop,
+// no vertex cycle at either tip and no cycle step across the slit.
+TEST(FieldTransportAtlas, IsolatedInteriorBarrierEdgeIsATwoSidedSlit) {
+  const TriMesh mesh = make_planar_grid_mesh(5);
+  const auto slit = topology_edge(6, 7, 25U);
+  const std::set<SourceEdgeTopologyKey> hardEdges{slit};
+  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
+      mesh, *sourceAuthority, hardEdges, make_zero_transport_field(mesh));
+  std::ostringstream report;
+  if (!atlasBuild) append_atlas_error(report, atlasBuild.error());
+  ASSERT_TRUE(atlasBuild) << report.str();
+  const auto &atlas = atlasBuild.value();
+  append_transport_region_diagnostics(report, atlas);
+
+  ASSERT_EQ(1U, atlas.component_topology().size());
+  const auto &topology = atlas.component_topology().front();
+  EXPECT_EQ(0, topology.eulerCharacteristic) << report.str();
+  EXPECT_EQ(2, topology.boundaryLoopCount) << report.str();
+  EXPECT_EQ(0, topology.genus) << report.str();
+  EXPECT_EQ(25U, topology.vertexCount) << report.str();
+  EXPECT_EQ(57U, topology.edgeCount) << report.str();
+  EXPECT_EQ(32U, topology.faceCount) << report.str();
+  EXPECT_EQ(7U, topology.localCycleCount) << report.str();
+  ASSERT_EQ(1U, atlas.region_transport_diagnostics().size());
+  const auto &region = atlas.region_transport_diagnostics().front();
+  EXPECT_EQ(1, region.uncutEulerCharacteristic) << report.str();
+  EXPECT_EQ(0, region.cutEulerCharacteristic) << report.str();
+  EXPECT_EQ(2, region.cutBoundaryLoopCount) << report.str();
+  EXPECT_EQ(1, region.newSlitBoundaryLoopCount) << report.str();
+
+  std::vector<int> boundaryLifts;
+  for (const auto &cycle : atlas.cycles()) {
+    for (const auto &step : cycle.steps) {
+      EXPECT_NE(slit, step.sourceEdge) << report.str();
+    }
+    if (cycle.kind == directional::authority::FieldCycleKind::LocalVertex) {
+      ASSERT_TRUE(cycle.localVertex.has_value());
+      EXPECT_NE(6U, cycle.localVertex->index()) << report.str();
+      EXPECT_NE(7U, cycle.localVertex->index()) << report.str();
+    }
+    if (cycle.kind != directional::authority::FieldCycleKind::BoundaryLoop) {
+      continue;
+    }
+    boundaryLifts.push_back(cycle.turningLift);
+    if (cycle_steps_all_touch(cycle, {6U, 7U})) {
+      // Ten radial edges around the two degree-six tips, minus the slit.
+      EXPECT_EQ(10U, cycle.steps.size()) << report.str();
+      EXPECT_EQ(-4, cycle.turningLift) << report.str();
+    }
+  }
+  EXPECT_EQ((std::vector<int>{4, -4}), boundaryLifts) << report.str();
+}
+
+// Two slits and a two-edge barrier arc in one region: the face array cuts the
+// arc (its middle vertex gets two copies) and the cycle basis cuts the slits.
+TEST(FieldTransportAtlas, SlitsAndABarrierArcShareOneCutTransportDomain) {
+  const TriMesh mesh = make_planar_grid_mesh(6);
+  const std::set<SourceEdgeTopologyKey> hardEdges{
+      topology_edge(7, 8, 36U), topology_edge(27, 28, 36U),
+      topology_edge(14, 15, 36U), topology_edge(15, 16, 36U)};
+  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
+      mesh, *sourceAuthority, hardEdges, make_zero_transport_field(mesh));
+  std::ostringstream report;
+  if (!atlasBuild) append_atlas_error(report, atlasBuild.error());
+  ASSERT_TRUE(atlasBuild) << report.str();
+  const auto &atlas = atlasBuild.value();
+  append_transport_region_diagnostics(report, atlas);
+
+  ASSERT_EQ(1U, atlas.component_topology().size());
+  const auto &topology = atlas.component_topology().front();
+  EXPECT_EQ(-2, topology.eulerCharacteristic) << report.str();
+  EXPECT_EQ(4, topology.boundaryLoopCount) << report.str();
+  EXPECT_EQ(0, topology.genus) << report.str();
+  EXPECT_EQ(37U, topology.vertexCount) << report.str();
+  EXPECT_EQ(89U, topology.edgeCount) << report.str();
+  EXPECT_EQ(9U, topology.localCycleCount) << report.str();
+  std::vector<int> boundaryLifts;
+  for (const auto &cycle : atlas.cycles()) {
+    for (const auto &step : cycle.steps) {
+      EXPECT_EQ(0U, hardEdges.count(step.sourceEdge)) << report.str();
+    }
+    if (cycle.kind == directional::authority::FieldCycleKind::BoundaryLoop) {
+      boundaryLifts.push_back(cycle.turningLift);
+    }
+  }
+  std::sort(boundaryLifts.begin(), boundaryLifts.end());
+  EXPECT_EQ((std::vector<int>{-4, -4, -4, 4}), boundaryLifts) << report.str();
+}
+
+// On the genus-one torus fixture a slit keeps both handle generators when
+// dual_cycles' generators avoid it. A generator that crosses it would need
+// transport across the barrier, so A1 fails closed with the slit as locus
+// (O19).
+TEST(FieldTransportAtlas, TorusSlitKeepsBothHandlesOrFailsClosedAtTheSlit) {
+  TriMesh mesh;
+  ASSERT_TRUE(directional::readOBJ(
+      directional::tests::benchmark_fixture_path("milestone-g/torus.obj")
+          .string(),
+      mesh));
+  const Eigen::MatrixXd raw = read_cp4c_rawfield(
+      directional::tests::benchmark_fixture_path("milestone-g/torus.rawfield"),
+      mesh.F.rows());
+  const CrossFieldResult field =
+      directional::pipeline::finalize_surface_cell_raw_cross_field(mesh, raw);
+  const auto build = [&](const SourceEdgeTopologyKey &slit) {
+    const std::set<SourceEdgeTopologyKey> hardEdges{slit};
+    const auto sourceAuthority = make_source_authority(mesh, hardEdges);
+    EXPECT_TRUE(sourceAuthority.has_value());
+    return directional::authority::FieldTransportAtlas::make(
+        mesh, *sourceAuthority, hardEdges, field);
+  };
+  const std::size_t extent = static_cast<std::size_t>(mesh.V.rows());
+
+  const auto kept = topology_edge(0, 1, extent);
+  const auto keptBuild = build(kept);
+  std::ostringstream report;
+  if (!keptBuild) append_atlas_error(report, keptBuild.error());
+  ASSERT_TRUE(keptBuild) << report.str();
+  ASSERT_EQ(1U, keptBuild.value().component_topology().size());
+  const auto &topology = keptBuild.value().component_topology().front();
+  EXPECT_EQ(-1, topology.eulerCharacteristic);
+  EXPECT_EQ(1, topology.boundaryLoopCount);
+  EXPECT_EQ(1, topology.genus);
+  EXPECT_EQ(2U, topology.handleGeneratorCount);
+  for (const auto &cycle : keptBuild.value().cycles()) {
+    for (const auto &step : cycle.steps) EXPECT_NE(kept, step.sourceEdge);
+  }
+
+  const auto crossed = topology_edge(12, 14, extent);
+  const auto crossedBuild = build(crossed);
+  ASSERT_FALSE(crossedBuild);
+  EXPECT_EQ(directional::authority::FieldAtlasBuildErrorCode::IncompleteCycleBasis,
+            crossedBuild.error().code);
+  EXPECT_EQ(directional::authority::IncompleteCycleBasisReason::
+                HandleGeneratorCrossesSlit,
+            crossedBuild.error().incompleteCycleBasisReason);
+  EXPECT_EQ(crossed, crossedBuild.error().sourceEdge);
+}
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB64 866 `289d887c…` is the byte-identical prefix of the new 869 `baaef9e7…`; ledger v5 `fd433f54…` unchanged; both self-check |
| Decisive claims independently re-derived | Probes, not static reading. Gate run under the change. Deferred rows compared slit-off vs slit-on. BunnyRandom run on macOS and in an FMA-off build. Torus swept over all 216 edges. Membership listed from the built binaries |
| Non-vacuity checked | Mutants M1–M3 each fail at least one new test; the three new rows and deferred row 360 reach a slit |
| Prior obligations discharged/carried | RA-191 D1–D8 ruled. P13-c discharged once TB65 matches. P13-e and O19 new. P13-d, O18, O6, O9, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-e (BunnyRandom vertex-49 port count), O19 (handle generator across a slit) |
| ORIENTATION currency line | Updated to RA-192 / CB66 next |
| ORIENTATION §3 / §4 / §7 / §8 | §7 Immediate and priority 1 updated; §8 RA-191 line corrected. §3/§4: n/a, no executed gate or witness change |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: find what a broken representation actually feeds before replacing it |
| Consolidation under CLEAN_UP_POLICY | n/a: RA-191 stays as history; its diagnosis is upheld here |
| Successor frozen | CB66 (RA-192.5); TB65 falsifiers (RA-192.6) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran only in scratch builds |
| `review_check.py boundary` | ALL CHECKS PASSED on the authentic checkout; `ledgers --base 0a9b0618e` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB66 |
| Pushed to origin, branch in sync | Confirmed after the push |
