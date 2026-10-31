# RA-168 — TB48-REV audit: P-G3 is an A5 defect, E2 is a stale oracle; exact CB49 and CB49E patches (2026-10-28)

**Turns:** this record completes both Review-track DEFNs, `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` and `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` (type **DEFN**). It also audits `M6-CP3-TB48-RP01-FULL-GATE-REV`.

**Decision:**
- TB48 evidence is valid (502/2).
- Two of TB48-REV's conclusions are **wrong** and are corrected here:
  - **P-G3** is not in A4. It is in A5 `periodic_endpoint_gauge`, and RA-167's cp3entry:1 oracle copied the same formula.
  - **E2** is not a production reachability gap. A4 already publishes the RA-166 D2 R-split; cp3entry:2 is a stale junction-era oracle.
- Two exact patches are authorized, in sequence: **CB49** (A5 fix + oracle, 21 lines) then **CB49E** (cp3entry:2 rewrite to D2, test-only). **TB49** then runs on the TB48-REV manifest `a0e39fa2…` and is predicted at **504/0**.

**Basis:** scratch probes against a local GMP build of HEAD `de8c9fae0` production. These are diagnostic only, not gate authority. CI evidence was re-verified independently.

## RA-168.1 Audit of TB48-REV

**Confirmed:**
- CB48 test bytes are identical to the RA-167.8 patch applied at `a4296e3f3`.
- Result artifact `12836819707` re-downloaded: ZIP SHA-256 `3aa8b6bc…20131`; 1014/1014 internal checksums; 504 ledger rows, 502 PASS / 2 RED.
  - Row 492 fails first at `TQ:3027`, then at `:3038` (A5 returns null).
  - Row 493 fails at `TQ:3183`.
- TB48 → TB49 manifest diff is exactly rows 492/493 RED → POSITIVE; self-check passes 504.
- Stable accounting: P-G3 is non-stable (no accepted-green loss). Agreed. 66/17/49, debt 1.

**Corrected:**
1. **P-G3 location (an error inherited from RA-167).** TB48-REV and RA-167 placed the defect at `SurfaceCellTracing.cpp:19088–19123` / `:8194–8218` (A4). The probe (RA-168.2) shows A4's published periodic endpoint states are **identical** on the base and odd-relabelled torus, so A4 is gauge-covariant. The defect is A5 `periodic_endpoint_gauge` (`RemeshPipeline.cpp:4793–4820`). A DEFN instructed to write "an exact A4 correction patch" would have modified a correct stage.
2. **Raw-trace reading.** "One branch rotation differs" is wrong. In the 24-byte `GridAutomorphism` dump, bytes 1–7 are struct padding. The rotation is 3 on both sides; only the translation differs: (−30,6) vs (−31,5).
3. **E2 falsifier contradicts RA-166 D2.** TB48-REV asks for "the exact two-carrier certificate with real junction/paired attachments". D2 makes the R-split canonical, forbids a stitched two-carrier route, and leaves junctions unwitnessed (O9). The raw log of row 493 already shows the D2 R-split: `(1,4)` endpoints `IR` and `(4,7)` endpoints `RI`, `j=0`.
4. **TB49 manifest frozen before the patches existed.** Its content is nevertheless correct for the RA-168 patches (probe below), so it is **kept** as the TB49 authority.

## RA-168.2 Probe evidence

**G3, endpoint dump on the witness relation** (S = rotation 3, shift (−36,0) in both):

| Endpoint | Base: face gauge L / branch / coord → relation coord, branch | Odd relabel: L / branch / coord → relation coord, branch |
|---|---|---|
| fwd.from (face 22) | 0 / 3 / (6,36) → (6,36), 3 | 0 / 3 / (6,36) → (6,36), 3 |
| fwd.to (face 22) | 0 / 3 / (5,36) → (5,36), 3 | 0 / 3 / (5,36) → (5,36), 3 |
| rev.from (face 25) | 0 / 3 / (5,0) → (0,−5), 2 | **3 / 2** / (5,0) → (0,−5), 2 |
| rev.to (face 1) | 0 / 3 / (6,0) → (0,−6), 2 | **3 / 2** / (6,0) → (0,−6), 2 |

- Relation rotation Q = 3 in both. A4 relation states are byte-identical, so **A4 is correct**.
- Placement lattice coordinates are regional-chart `(u,v)` (`SCT:17764`) and gauge-free. Only the branch label carries the face gauge (`branch = L_face + chartUBranch`, `SCT:17767`).
- A5 builds a per-endpoint coordinate gauge with rotation `relationBranch − placementBranch`. That rotation includes −L, so A5 rotates gauge-free coordinates about each endpoint. The per-pair transports become `R(L_r − L_f)(x − p_i) + q_i`. These agree only when `L_r = L_f`. That holds on all 84 periodic-cut edges of the base torus and fails on 16/84 of the odd torus.
- The A6 isolation-seam path already strips the local face gauge the same way (`RemeshPipeline.cpp:5906`).

**G3 fix (P1), probed:**
- A5 accepts the odd torus.
- cp3entry:1 passes in full, including two new gauge-free coordinate checks.
- The old formula **fails** the new coordinate oracle: its transport maps the first endpoint pair but not the second (`first=1 second=0`).
- Whole TQ file: 140 tests pass; the only failures are the five O11 tests, identical to HEAD (138 pass at HEAD with CB48).

**E2:** `nonconstant_hard_rail`, both face-row orders.
- Vertex 4 has exactly two R endpoints, on `(1,4)` and `(4,7)` of rail 2. Both attach to faces 0/7 through two-step non-hard star contact paths. There are no junctions.
- D2 square: with cross transport 3 it commutes, and a +1 mutation breaks it (RA-166.2).
- The checked factory rejects each of these with `InvalidSourceAuthority`: R carrier +1, a dropped R, and an R contact-step +1.
- The old body also had two latent oracle defects. Neither was ever executed, because the test failed earlier at `:3183`:
  - `collect_attested_terminal_steps` asserted `terminalVertex` on every endpoint, including I and R;
  - the final loop asserted `terminalVertex` on R contact steps.

**Local 504 gate (both patches):** **502/504 locally; rows 492 and 493 pass.** The two failures are macOS platform baselines.
  - Row 283 (`SurfaceCellsPhase10` legacy `NFunctionMesher` arrangement) and row 445 (A3 `InvalidFieldTransportAtlas`, `FieldAlignedCurveNetworkTests.cpp:17125`) fail identically with **unpatched** HEAD production, and both pass on CI (TB48). They sit outside A5 or upstream of it.
  - **Falsifiers against HEAD production:** row 492 fails first at the A5 `ASSERT_NE(a5, nullptr)`, so P1 is necessary. Row 493 passes, so P2 does not depend on P1..

## RA-168.3 Decisions

- **G3-A5:** `periodic_endpoint_gauge` strips `branchAuthority.localFaceBranchRotation` from the placement branch before forming the coordinate gauge, so the coordinate gauge is the relation turn alone. The cp3entry:1 oracle is corrected the same way and gains two gauge-free coordinate checks that do not depend on the gauge formula. A4 is unchanged.
- **E2:** cp3entry:2 is rewritten to RA-166 D2:
  - exactly two R endpoints at vertex 4, on (1,4) and (4,7), of one rail;
  - single-step certificates with no junctions;
  - A3 sector transports from the independent atlas over non-hard spokes;
  - separated sectors, commutation, and a +1 mutation that breaks the square;
  - face-row-reversal invariance of the typed R crossings;
  - a checked-factory negative on the (4,7) R crossing.

  The T/R star steps are A3-attested. The A5 odd-carrier witness and the A4 odd-tau negative are kept. The junction-only sections are removed: the balanced junction mutation, sector-topology/radial phi, and the radial-step tamper. Production is unchanged.
- **Accounting:** unchanged. P-G3 non-stable; stable 66/17/49, debt 1; CP2 491/491 accepted; selector497 frozen.

## RA-168.4 CB49 — `M6-CP3-CB49-RP01-G3-A5-PERIODIC-PLACEMENT-GAUGE` (type CB)

Renamed from `…-G3-PERIODIC-ENDPOINT-STATE`, because the endpoint state (A4) is correct.

- Extract the RA-168.9 `~~~diff` block verbatim, with a trailing newline. SHA-256 must be `5897798df599195ba74bc8811a69a7ce113e253040d5be4e02300a32337c47f6`. Then `git apply` with no hand edits.
- Numstat must be exactly `8 2 src/pipeline/RemeshPipeline.cpp` and `13 2 tests/SurfaceCellTransitionQuotientTests.cpp`.
- **Evidence:** the established eight GMP/GMPXX targets, `runtimeExecution=false`, a record of at most 25 lines.

| Observed | Successor |
|---|---|
| Compile OK, numstat exact | `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` |
| The patch does not apply, or a compile error occurs | `M6-CP3-PLAN-RP01-G3-A5-GAUGE-STOP` (Review) |
| Orchestration failure | `M6-CP3-CB49A-RP01-ORCH`, then retry CB49 |

## RA-168.5 CB49E — `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` (type CB)

- Requires CB49 committed. Extract the RA-168.10 block (SHA-256 `9ebef3cc2427a93c21c7c9d1660b9677998fc379a9acccac947eb9928f96a29f`) and `git apply` it on CB49.
- Numstat must be exactly `215 255 tests/SurfaceCellTransitionQuotientTests.cpp`. Test-only.
- **Evidence:** the same eight targets, runtime-free, a record of at most 25 lines.

| Observed | Successor |
|---|---|
| Compile OK, numstat exact | `M6-CP3-TB49-RP01-FULL-GATE-EXEC` |
| The patch does not apply, or a compile error occurs | `M6-CP3-PLAN-RP01-E2-ADJACENCY-STOP` (Review) |
| Orchestration failure | `M6-CP3-CB49A-RP01-ORCH`, then retry CB49E |

## RA-168.6 TB49 — `M6-CP3-TB49-RP01-FULL-GATE-EXEC` (type TB-EXEC)

- Artifact-only, on the CB49E package. The harness is unchanged (`142321061c57…`).
- **Manifest:** `Architecture_M6_CP3_TB49_Full_Gate_Case_Manifest.tsv`, SHA-256 `a0e39fa25d707bfc8eabb25ac9e8c494cff8ebf032e2040718b90366d0250ef0` (frozen by TB48-REV, kept by RA-168.1).
- **Prediction: 504 PASS / 0 RED**, the first all-green full gate.

| Observed | Successor |
|---|---|
| 504/0 | `M6-CP3-TB49-RP01-FULL-GATE-REV` (Review) |
| Any RED (GUARD, POSITIVE, 492 or 493) | Same REV, with S4 diagnosis |
| Infra, coverage or hash failure | `M6-CP3-CB49A-RP01-ORCH` → `M6-CP3-TB49-RP01-FULL-GATE-EXEC-R2` |

## RA-168.7 Canonical turn sequence (IDs validated with `turn_type_from_turn`)

| # | Turn | Type | Track | Gate |
|---|---|---|---|---|
| done | `M6-CP3-TB48-RP01-FULL-GATE-REV`; RA-168 completes `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` and `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` | TB-REV; DEFN | R | P1/P2 probed |
| 1 | `M6-CP3-CB49-RP01-G3-A5-PERIODIC-PLACEMENT-GAUGE` | CB | I | Exact P1; 8 targets |
| 2 | `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` | CB | I | Exact P2; 8 targets |
| 3 | `M6-CP3-TB49-RP01-FULL-GATE-EXEC` | TB-EXEC | I | Predict 504/0 |
| 4 | `M6-CP3-TB49-RP01-FULL-GATE-REV` | TB-REV | R | First green full gate; CP3 admission decision |
| 5 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-CB50-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-TB50-RP01-FULL-GATE-EXEC` → `-REV` | DEFN → CB → TB | R → I → I → R | O4, O5, P1-a/P1-b, RA-162 C1 |
| 6 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN | R | RP-01 Review: O6 scope; O7–O12 owners |
| 7 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN | R | After RP-01 |

Naming and STOP rules: RA-167.6, unchanged.

## RA-168.8 Carried items

- **O9** is now explicitly test-locked: cp3entry:2 asserts that every route has no junctions. RP-01 still decides whether to retire the A4 junction path.
- O1, O2, O6, O7, O8, O10, O11 (five off-gate TQ tests, unchanged by P1/P2), O12, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

## RA-168.9 Exact CB49 patch P1 (authoritative bytes)

Extraction: the lines strictly between the first `~~~diff` line and the next `~~~` line after this heading, each newline-terminated.

~~~diff
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index be5475729..1ec7a0474 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -4801,17 +4801,23 @@ SurfaceOccurrenceComplexProducer::produce(
     if (!relationState.has_value() || relationState.value() != published) {
       return std::nullopt;
     }
+    // Placement lattice coordinates live in the gauge-free regional chart;
+    // only the branch label carries the local source-face gauge. Strip that
+    // gauge so the coordinate gauge is the relation turn alone (G3, RA-168).
     const authority::QuarterTurn placementBranch =
         authority::QuarterTurn::from_integer(placement.branchRotation);
+    const authority::QuarterTurn cutPlacementBranch = compose(
+        published.branchAuthority.localFaceBranchRotation.inverse(),
+        placementBranch);
     const authority::QuarterTurn gaugeRotation =
-        compose(relationState->branchRotation, placementBranch.inverse());
+        compose(relationState->branchRotation, cutPlacementBranch.inverse());
     const authority::GridAutomorphism gauge{
         gaugeRotation,
         relationState->latticeCoordinate -
             authority::rotate(gaugeRotation, placement.latticeCoordinate)};
     if (gauge.apply(placement.latticeCoordinate) !=
             relationState->latticeCoordinate ||
-        compose(gauge.rotation, placementBranch) !=
+        compose(gauge.rotation, cutPlacementBranch) !=
             relationState->branchRotation ||
         placement.scaleLevel != relationState->scaleLevel) {
       return std::nullopt;
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index d51a59ed4..a5fd80c9e 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -2984,9 +2984,12 @@ TEST(M6CP3, PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority) {
     if (!relationState.has_value() || relationState.value() != published) {
       return std::nullopt;
     }
-    const auto placementBranch =
+    // Lattice coordinates are gauge-free; only the branch label carries the
+    // local source-face gauge, which must be stripped (RA-168 G3).
+    const auto placementBranch = compose(
+        published.branchAuthority.localFaceBranchRotation.inverse(),
         directional::authority::QuarterTurn::from_integer(
-            placement.branchRotation);
+            placement.branchRotation));
     const auto rotation =
         compose(relationState->branchRotation, placementBranch.inverse());
     return directional::authority::GridAutomorphism{
@@ -3030,6 +3033,14 @@ TEST(M6CP3, PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority) {
                                 gammaFrom->inverse()));
   EXPECT_NE(expected, wrongDirection)
       << "non-self-inverse gauges must kill the wrong Gamma direction";
+  // Gauge-free oracle: the placement transport must carry both forward
+  // regional-chart lattice coordinates onto their reverse partners.
+  EXPECT_EQ(expected.apply(forward->fromLattice.latticeCoordinate),
+            reverse->toLattice.latticeCoordinate)
+      << "G3 placement transport must map the first endpoint pair";
+  EXPECT_EQ(expected.apply(forward->toLattice.latticeCoordinate),
+            reverse->fromLattice.latticeCoordinate)
+      << "G3 placement transport must map the second endpoint pair";
 
   auto a5Result = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
       fixture.fixture.mesh.V, fixture.fixture.mesh.F, front);
~~~

## RA-168.10 Exact CB49E patch P2 (authoritative bytes; applies on P1)

Extraction: the lines strictly between the first `~~~diff` line and the next `~~~` line after this heading, each newline-terminated.

~~~diff
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index a5fd80c9e..12bcc36c6 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -3156,143 +3156,191 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
   const auto &fixture = nonconstant_hard_rail_fixture();
   const auto &front = fixture.network.phaseFront.product();
   ASSERT_FALSE(front.hardRailRouteCertificates().empty())
-      << "D2 requires at least one A4-produced, paired route certificate";
-  // The 3x3 hard-rail input alone is not evidence of a two-carrier
-  // certificate. Only the immutable A4-produced route qualifies, and the
-  // future TB must fail (not silently skip) when none is produced.
-  const auto carrier_vertices = [](const auto &edge) {
-    const int a = static_cast<int>(edge.first().index());
-    const int b = static_cast<int>(edge.second().index());
-    return std::pair<int, int>{std::min(a, b), std::max(a, b)};
+      << "D2 requires A4-produced paired route certificates";
+  // RA-166 D2 / RA-168 E2: A4 ends each rail side at an interior rail
+  // vertex, so the canonical midline representation at source vertex 4 is
+  // the R-split: two single-carrier certificates of one rail on its two
+  // incident carriers (1,4) and (4,7), each with an R endpoint at 4. A
+  // stitched two-carrier route is forbidden; junctions stay unwitnessed (O9).
+  namespace A = directional::authority;
+  using RouteCertificate = directional::geometry::SurfaceHardRailRouteCertificate;
+  using RouteEndpoint =
+      directional::geometry::SurfaceHardRailRouteEndpointCertificate;
+  using RailTransition = directional::geometry::SurfaceHardRailFieldTransition;
+  struct RailVertexSplit {
+    std::size_t railVertexEndpoints = 0U;
+    std::size_t missingSpokeTransitions = 0U;
+    const RouteCertificate *a = nullptr;
+    const RouteEndpoint *ea = nullptr;
+    const RouteCertificate *b = nullptr;
+    const RouteEndpoint *eb = nullptr;
+    std::optional<RailTransition> bCross;
+    std::optional<A::QuarterTurn> s0;
+    std::optional<A::QuarterTurn> s1;
+    bool sectorsSeparated = false;
   };
-  const auto is_midline_pair = [&](const auto &certificate) {
-    const auto steps = certificate.route.oriented_steps();
-    if (steps.size() != 2U) return false;
-    const std::set<std::pair<int, int>> observed{
-        carrier_vertices(steps[0].topology()),
-        carrier_vertices(steps[1].topology())};
-    return observed ==
-           std::set<std::pair<int, int>>{{1, 4}, {4, 7}};
-  };
-  const auto producedMidline = std::find_if(
-      front.hardRailRouteCertificates().begin(),
-      front.hardRailRouteCertificates().end(), is_midline_pair);
-  std::ostringstream certificateInventory;
-  for (const auto &certificate : front.hardRailRouteCertificates()) {
-    certificateInventory << " [steps=";
-    for (const auto &step : certificate.route.oriented_steps()) {
-      const auto pair = carrier_vertices(step.topology());
-      certificateInventory << "(" << pair.first << "," << pair.second << ")";
-    }
-    certificateInventory << ";endpoints=";
-    for (const auto &endpoint : certificate.endpoints) {
-      certificateInventory << (endpoint.terminalVertex ? "T" :
-                               endpoint.railVertex ? "R" : "I");
-    }
-    certificateInventory << ";j=" << certificate.junctions.size() << "]";
-  }
-  ASSERT_NE(producedMidline, front.hardRailRouteCertificates().end())
-      << "D2/RA-38 requires an ACTUAL A4-produced paired two-carrier "
-         "HardRail (1,4)->(4,7); input-only polyline is not proof"
-      << certificateInventory.str();
-  ASSERT_EQ(producedMidline->junctions.size(), 1U);
-  const auto &midlineJunction = producedMidline->junctions.front();
-  ASSERT_EQ(static_cast<int>(midlineJunction.junction.index()), 4);
-  std::array<std::vector<int>, 2> radialRows;
-  std::array<directional::authority::QuarterTurn, 2> sideTransport{
-      directional::authority::QuarterTurn::from_integer(0),
-      directional::authority::QuarterTurn::from_integer(0)};
-  const auto &sourceFaces = front.sourceTopologyRegions();
-  for (std::size_t side = 0U; side < 2U; ++side) {
-    auto face = side == 0U ? producedMidline->endpoints[0].firstAttachment
-                           : producedMidline->endpoints[0].secondAttachment;
-    const auto start = sourceFaces.row_for_topology(face);
-    ASSERT_TRUE(start.has_value());
-    radialRows[side].push_back(static_cast<int>(start->index()));
-    for (const auto &step : midlineJunction.sectorPaths[side]) {
-      EXPECT_EQ(step.firstFace, face);
-      EXPECT_FALSE(front.hardFeatureEdges().contains(step.edge));
-      EXPECT_TRUE(step.edge.first() == midlineJunction.junction ||
-                  step.edge.second() == midlineJunction.junction);
-      sideTransport[side] = compose(step.firstToSecond, sideTransport[side]);
-      face = step.secondFace;
-      const auto row = sourceFaces.row_for_topology(face);
-      ASSERT_TRUE(row.has_value());
-      radialRows[side].push_back(static_cast<int>(row->index()));
+  // The sector transports s0/s1 come from the independently retained A3
+  // atlas over the non-hard spokes of vertex 4, never from A4 certificates.
+  const auto rail_vertex_split = [](const PhaseFrontFixture &source) {
+    RailVertexSplit split;
+    const auto &front = source.network.phaseFront.product();
+    const auto &regions = front.sourceTopologyRegions();
+    const auto &F = source.mesh.F;
+    const auto vertexCount = static_cast<std::size_t>(source.mesh.V.rows());
+    const auto edge_key = [&](const int first, const int second) {
+      return A::SourceEdgeTopologyKey::make(
+                 A::SourceVertexId::from_index(first, vertexCount).value(),
+                 A::SourceVertexId::from_index(second, vertexCount).value())
+          .value();
+    };
+    const auto face_id = [&](const int row) {
+      return A::SourceFaceId::from_index(row, static_cast<std::size_t>(F.rows()))
+          .value();
+    };
+    constexpr int railVertex = 4;
+    for (const auto &certificate : front.hardRailRouteCertificates()) {
+      for (const auto &endpoint : certificate.endpoints) {
+        if (!endpoint.railVertex.has_value() ||
+            static_cast<int>(endpoint.railVertex->index()) != railVertex) {
+          continue;
+        }
+        ++split.railVertexEndpoints;
+        if (endpoint.terminalCarrier.edge == edge_key(1, 4)) {
+          split.a = &certificate;
+          split.ea = &endpoint;
+        } else if (endpoint.terminalCarrier.edge == edge_key(4, 7)) {
+          split.b = &certificate;
+          split.eb = &endpoint;
+        }
+      }
     }
-    EXPECT_EQ(face, side == 0U
-                        ? producedMidline->endpoints[1].firstAttachment
-                        : producedMidline->endpoints[1].secondAttachment);
-    if (radialRows[side].front() > radialRows[side].back()) {
-      std::reverse(radialRows[side].begin(), radialRows[side].end());
+    if (split.ea == nullptr || split.eb == nullptr ||
+        !source.fieldTransportAtlas.has_value()) {
+      return split;
     }
-  }
-  std::sort(radialRows.begin(), radialRows.end());
-  EXPECT_EQ(radialRows[0], (std::vector<int>{0, 1, 4}));
-  EXPECT_EQ(radialRows[1], (std::vector<int>{3, 6, 7}));
-  EXPECT_EQ(compose(producedMidline->endpoints[1].terminalCarrier.firstToSecond,
-                    sideTransport[0]),
-            compose(sideTransport[1],
-                    producedMidline->endpoints[0].terminalCarrier.firstToSecond))
-      << "A3 sector paths must commute with both LOCAL rail crossings";
+    const auto &atlas = *source.fieldTransportAtlas;
+    std::map<A::SourceFaceTopologyKey,
+             std::vector<std::pair<A::SourceFaceTopologyKey, A::QuarterTurn>>>
+        star;
+    std::vector<int> around;
+    for (int row = 0; row < F.rows(); ++row) {
+      if (F(row, 0) == railVertex || F(row, 1) == railVertex ||
+          F(row, 2) == railVertex) {
+        around.push_back(row);
+      }
+    }
+    for (const int i : around) {
+      for (const int j : around) {
+        if (i == j) continue;
+        std::vector<int> shared;
+        for (int c = 0; c < 3; ++c)
+          for (int d = 0; d < 3; ++d)
+            if (F(i, c) == F(j, d)) shared.push_back(F(i, c));
+        if (shared.size() != 2U) continue;
+        const auto spoke = edge_key(shared[0], shared[1]);
+        if (front.hardFeatureEdges().contains(spoke)) continue;
+        const auto transition =
+            atlas.transition_value(spoke, face_id(i), face_id(j));
+        if (!transition.has_value()) {
+          ++split.missingSpokeTransitions;
+          continue;
+        }
+        star[regions.topology_for_row(face_id(i))].push_back(
+            {regions.topology_for_row(face_id(j)), transition->transport});
+      }
+    }
+    const auto sector = [&](const A::SourceFaceTopologyKey &from,
+                            const A::SourceFaceTopologyKey &to)
+        -> std::optional<A::QuarterTurn> {
+      std::map<A::SourceFaceTopologyKey, A::QuarterTurn> seen{
+          {from, A::QuarterTurn::from_integer(0)}};
+      std::vector<A::SourceFaceTopologyKey> pending{from};
+      while (!pending.empty()) {
+        const auto at = pending.back();
+        pending.pop_back();
+        for (const auto &[next, transport] : star[at]) {
+          if (seen.contains(next)) continue;
+          seen[next] = compose(transport, seen[at]);
+          pending.push_back(next);
+        }
+      }
+      const auto found = seen.find(to);
+      if (found == seen.end()) return std::nullopt;
+      return found->second;
+    };
+    RailTransition bCross = split.eb->terminalCarrier;
+    auto s0 = sector(split.ea->terminalCarrier.firstFace, bCross.firstFace);
+    if (!s0.has_value()) {
+      bCross = RailTransition{bCross.edge, bCross.secondFace, bCross.firstFace,
+                              bCross.firstToSecond.inverse()};
+      s0 = sector(split.ea->terminalCarrier.firstFace, bCross.firstFace);
+    }
+    split.bCross = bCross;
+    split.s0 = s0;
+    split.s1 = sector(split.ea->terminalCarrier.secondFace, bCross.secondFace);
+    split.sectorsSeparated =
+        !sector(split.ea->terminalCarrier.firstFace, bCross.secondFace)
+             .has_value();
+    return split;
+  };
+  const auto require_rail_vertex_split = [](const RailVertexSplit &split) {
+    EXPECT_EQ(2U, split.railVertexEndpoints)
+        << "an interior rail vertex has exactly two R endpoints";
+    ASSERT_NE(split.ea, nullptr)
+        << "A4 must publish an R endpoint at 4 on carrier (1,4)";
+    ASSERT_NE(split.eb, nullptr)
+        << "A4 must publish an R endpoint at 4 on carrier (4,7)";
+    EXPECT_NE(split.a, split.b);
+    EXPECT_EQ(split.a->rail, split.b->rail)
+        << "both R endpoints belong to the same open rail";
+    for (const auto *certificate : {split.a, split.b}) {
+      EXPECT_EQ(1U, certificate->route.steps().size())
+          << "R-split certificates never stitch two carriers";
+      EXPECT_TRUE(certificate->junctions.empty())
+          << "junction certificates remain unwitnessed (O9)";
+    }
+    EXPECT_EQ(0U, split.missingSpokeTransitions)
+        << "every non-hard spoke of 4 needs an independent A3 transition";
+    ASSERT_TRUE(split.s0.has_value());
+    ASSERT_TRUE(split.s1.has_value());
+    EXPECT_TRUE(split.sectorsSeparated)
+        << "the rail must separate the two A3 sectors of vertex 4";
+    const auto aCross = split.ea->terminalCarrier.firstToSecond;
+    EXPECT_EQ(compose(split.bCross->firstToSecond, *split.s0),
+              compose(*split.s1, aCross))
+        << "A3 sector paths must commute with both LOCAL rail crossings";
+    EXPECT_NE(compose(compose(A::QuarterTurn::from_integer(1),
+                              split.bCross->firstToSecond),
+                      *split.s0),
+              compose(*split.s1, aCross))
+        << "a quarter-turn carrier mutation must break the square";
+  };
+  const auto midline = rail_vertex_split(fixture);
+  require_rail_vertex_split(midline);
+  if (HasFatalFailure()) return;
 
   // RA-38: face-row order is not a source-topology identity. Produce a
   // second A4 product from the same 3x3 hard rail with the eight input face
-  // rows reversed. Do not compare numeric row IDs or synthesize a route:
-  // the selected certificate must independently be A4-published.
+  // rows reversed; the R-split must be independently A4-published again.
   const auto permutedFixture = make_nonconstant_hard_rail_fixture(true);
   const auto &permutedFront = permutedFixture.network.phaseFront.product();
-  const auto permutedMidline = std::find_if(
-      permutedFront.hardRailRouteCertificates().begin(),
-      permutedFront.hardRailRouteCertificates().end(), is_midline_pair);
-  ASSERT_NE(permutedMidline,
-            permutedFront.hardRailRouteCertificates().end())
-      << "D2 source-face-row permutation must preserve an A4-produced "
-         "two-carrier HardRail, not merely input hard edges";
-  ASSERT_EQ(permutedMidline->junctions.size(), 1U);
-  EXPECT_EQ(permutedMidline->junctions.front().junction,
-            midlineJunction.junction);
-
-  // An internally commuting square is insufficient proof of A3 provenance:
-  // shifting one step on each side by the same Z4 turn preserves that square.
-  // Compare BOTH produced certificates with the original pipeline-owned A3
-  // atlas snapshots, not a second copy of the mutable certificate fields.
-  const auto require_atlas_attested_junction = [](const PhaseFrontFixture &source,
-                                                 const auto &route) {
-    ASSERT_TRUE(source.fieldTransportAtlas.has_value())
-        << "D2 requires an independently retained production A3 atlas";
-    const auto &front = source.network.phaseFront.product();
-    const auto &sourceFaces = front.sourceTopologyRegions();
-    const auto &atlas = *source.fieldTransportAtlas;
-    ASSERT_TRUE(atlas.matches_source_faces(
-        source.mesh.F, sourceFaces,
-        static_cast<std::size_t>(source.mesh.V.rows())))
-        << "A3 atlas must bind to the same typed source-face topology";
-    for (const auto &junction : route.junctions) {
-      for (const auto &side : junction.sectorPaths) {
-        for (const auto &step : side) {
-          const auto firstRow = sourceFaces.row_for_topology(step.firstFace);
-          const auto secondRow = sourceFaces.row_for_topology(step.secondFace);
-          ASSERT_TRUE(firstRow.has_value());
-          ASSERT_TRUE(secondRow.has_value());
-          const auto forward = atlas.transition_value(
-              step.edge, firstRow.value(), secondRow.value());
-          const auto reverse = atlas.transition_value(
-              step.edge, secondRow.value(), firstRow.value());
-          ASSERT_TRUE(forward.has_value())
-              << "Missing independently attested A3 nonrail step";
-          ASSERT_TRUE(reverse.has_value())
-              << "Missing reverse A3 nonrail step";
-          EXPECT_EQ(forward->transport, step.firstToSecond)
-              << "A4 nonrail certificate differs from independent A3 atlas";
-          EXPECT_EQ(reverse->transport, forward->transport.inverse())
-              << "A3 source-edge transport must be reciprocal";
-        }
-      }
-    }
+  const auto permutedMidline = rail_vertex_split(permutedFixture);
+  require_rail_vertex_split(permutedMidline);
+  if (HasFatalFailure()) return;
+  const auto typed_crossing = [](const RailTransition &transition) {
+    const bool reversed = transition.secondFace < transition.firstFace;
+    return std::make_tuple(
+        transition.edge,
+        reversed ? transition.secondFace : transition.firstFace,
+        reversed ? transition.firstFace : transition.secondFace,
+        reversed ? transition.firstToSecond.inverse()
+                 : transition.firstToSecond);
   };
-  require_atlas_attested_junction(fixture, *producedMidline);
-  require_atlas_attested_junction(permutedFixture, *permutedMidline);
+  EXPECT_EQ(typed_crossing(permutedMidline.ea->terminalCarrier),
+            typed_crossing(midline.ea->terminalCarrier));
+  EXPECT_EQ(typed_crossing(permutedMidline.eb->terminalCarrier),
+            typed_crossing(midline.eb->terminalCarrier))
+      << "source-face-row permutation must preserve the typed R-split";
 
   // Terminal A2b paths are independently A3-authenticated source-star
   // transports, just like the interior radial paths. Canonicalize their
@@ -3315,16 +3363,20 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
         static_cast<std::size_t>(source.mesh.V.rows())));
     for (const auto &route : front.hardRailRouteCertificates()) {
       for (const auto &endpoint : route.endpoints) {
-        ASSERT_TRUE(endpoint.terminalVertex.has_value())
-            << "A2b path must retain its producer-owned source vertex";
+        // I endpoints own no source-star path. T (A2b terminal) and R
+        // (interior rail vertex) star paths are both A3-attested (RA-168 E2).
+        const auto starVertex = endpoint.terminalVertex.has_value()
+                                    ? endpoint.terminalVertex
+                                    : endpoint.railVertex;
+        if (!starVertex.has_value()) continue;
         for (std::size_t side = 0U; side < 2U; ++side) {
           auto face = side == 0U ? endpoint.firstAttachment
                                  : endpoint.secondAttachment;
           for (const auto &step : endpoint.contactPaths[side]) {
             ASSERT_EQ(step.firstFace, face);
             ASSERT_FALSE(front.hardFeatureEdges().contains(step.edge));
-            ASSERT_TRUE(step.edge.first() == *endpoint.terminalVertex ||
-                        step.edge.second() == *endpoint.terminalVertex);
+            ASSERT_TRUE(step.edge.first() == *starVertex ||
+                        step.edge.second() == *starVertex);
             const auto first = sourceFaces.row_for_topology(step.firstFace);
             const auto second = sourceFaces.row_for_topology(step.secondFace);
             ASSERT_TRUE(first.has_value());
@@ -3340,7 +3392,7 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
             EXPECT_EQ(forward->transport, step.firstToSecond);
             EXPECT_EQ(reverse->transport, forward->transport.inverse());
             const bool inverted = step.secondFace < step.firstFace;
-            steps.emplace(*endpoint.terminalVertex, step.edge,
+            steps.emplace(*starVertex, step.edge,
                           inverted ? step.secondFace : step.firstFace,
                           inverted ? step.firstFace : step.secondFace,
                           inverted ? step.firstToSecond.inverse()
@@ -3362,50 +3414,9 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
   EXPECT_EQ(terminalSteps, permutedTerminalSteps)
       << "source-row permutations must preserve typed A2b/A3 terminal steps";
 
-  // Falsify a self-consistency-only oracle without requesting a public
-  // factory trust-contract decision: equal +1 Z4 mutations on the two
-  // nonrail side paths preserve the commuting square, but both must differ
-  // from the independently retained A3 atlas. This copied candidate is
-  // diagnostic-only; it must never be published as A4 owner authority.
-  auto balancedMutation = *producedMidline;
-  ASSERT_EQ(balancedMutation.junctions.size(), 1U);
-  for (auto &side : balancedMutation.junctions.front().sectorPaths) {
-    ASSERT_FALSE(side.empty());
-    side.front().firstToSecond = compose(
-        directional::authority::QuarterTurn::from_integer(1),
-        side.front().firstToSecond);
-  }
-  const auto compose_radial = [](const auto &path) {
-    auto total = directional::authority::QuarterTurn::from_integer(0);
-    for (const auto &step : path)
-      total = compose(step.firstToSecond, total);
-    return total;
-  };
-  const auto &mutantPaths = balancedMutation.junctions.front().sectorPaths;
-  EXPECT_EQ(compose(balancedMutation.endpoints[1].terminalCarrier.firstToSecond,
-                    compose_radial(mutantPaths[0])),
-            compose(compose_radial(mutantPaths[1]),
-                    balancedMutation.endpoints[0].terminalCarrier.firstToSecond))
-      << "Equal changes on both sides must leave the square commuting";
-  ASSERT_TRUE(fixture.fieldTransportAtlas.has_value());
-  const auto &independentAtlas = *fixture.fieldTransportAtlas;
-  for (const auto &side : mutantPaths) {
-    const auto &firstStep = side.front();
-    const auto from = sourceFaces.row_for_topology(firstStep.firstFace);
-    const auto to = sourceFaces.row_for_topology(firstStep.secondFace);
-    ASSERT_TRUE(from.has_value());
-    ASSERT_TRUE(to.has_value());
-    const auto sourceTransition = independentAtlas.transition_value(
-        firstStep.edge, from.value(), to.value());
-    ASSERT_TRUE(sourceTransition.has_value());
-    EXPECT_NE(firstStep.firstToSecond, sourceTransition->transport)
-        << "Balanced certificate tamper must be detected by independent A3";
-  }
-
   // Reconstruct with the complete A4 terminal-contact / closed-chain
   // authority. Omitting these optional arguments would silently exercise the
   // legacy attachment==carrier validation instead of the produced A2b germs.
-  // The balanced mutation commutes, but no longer matches genuine A3.
   ASSERT_FALSE(front.hardRailTerminalContacts().empty());
   const auto checkedFactory = [&](const auto &transitions,
                                   const auto &certificates,
@@ -3425,11 +3436,22 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
   EXPECT_NE(nullptr, std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
                          &accepted))
       << "A4 genuinely produced certificate must survive checked A3 factory";
+  // A quarter-turn on the published (4,7) R crossing is a source-authority
+  // forgery: the checked factory authenticates it against unchanged A3.
   auto tamperedCertificates = front.hardRailRouteCertificates();
-  const auto tamperedMidline = std::find_if(
-      tamperedCertificates.begin(), tamperedCertificates.end(), is_midline_pair);
-  ASSERT_NE(tamperedCertificates.end(), tamperedMidline);
-  *tamperedMidline = balancedMutation;
+  std::size_t tamperedCrossings = 0U;
+  for (auto &certificate : tamperedCertificates) {
+    for (auto &endpoint : certificate.endpoints) {
+      if (!endpoint.railVertex.has_value() ||
+          endpoint.terminalCarrier.edge != midline.eb->terminalCarrier.edge) {
+        continue;
+      }
+      endpoint.terminalCarrier.firstToSecond = compose(
+          A::QuarterTurn::from_integer(1), endpoint.terminalCarrier.firstToSecond);
+      ++tamperedCrossings;
+    }
+  }
+  ASSERT_EQ(1U, tamperedCrossings);
   expect_phase_front_product_error(
       checkedFactory(front.hardRailFieldTransitions(), tamperedCertificates,
                      &sourceAtlas),
@@ -3454,35 +3476,10 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
                      &sourceAtlas),
       directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
 
-  // Compare immutable SOURCE-FACE TOPOLOGY, not the rows used to index it.
-  // The canonical pair may exchange sector orientation; normalize the two
-  // unordered sector face sets before comparing.
-  const auto sector_topology = [](const auto &certificate) {
-    using Face = directional::authority::SourceFaceTopologyKey;
-    std::array<std::set<Face>, 2> sectors;
-    for (std::size_t side = 0; side < 2U; ++side) {
-      sectors[side].insert(side == 0U
-          ? certificate.endpoints[0].firstAttachment
-          : certificate.endpoints[0].secondAttachment);
-      sectors[side].insert(side == 0U
-          ? certificate.endpoints[1].firstAttachment
-          : certificate.endpoints[1].secondAttachment);
-      for (const auto &junction : certificate.junctions) {
-        for (const auto &step : junction.sectorPaths[side]) {
-          sectors[side].insert(step.firstFace);
-          sectors[side].insert(step.secondFace);
-        }
-      }
-    }
-    if (sectors[1] < sectors[0]) std::swap(sectors[0], sectors[1]);
-    return sectors;
-  };
-  EXPECT_EQ(sector_topology(*permutedMidline),
-            sector_topology(*producedMidline));
-  // The same physical source topology must retain exact A3 radial transport
-  // and owner HardRail chi, not merely the two sector face sets. Canonicalize
-  // each directed transition by its typed source-face topology to avoid a
-  // spurious discrepancy when the opposite route orientation is published.
+  // The same physical source topology must retain exact owner HardRail chi.
+  // Canonicalize each directed transition by its typed source-face topology
+  // to avoid a spurious discrepancy when the opposite route orientation is
+  // published.
   const auto typed_transport = [](const auto &transition) {
     const bool reversed = transition.secondFace < transition.firstFace;
     return std::make_tuple(
@@ -3500,41 +3497,9 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
       result.emplace(transition.edge, typed_transport(transition));
     return result;
   };
-  const auto radial_transport = [&](const auto &certificate) {
-    using Edge = directional::authority::SourceEdgeTopologyKey;
-    using Face = directional::authority::SourceFaceTopologyKey;
-    using Turn = directional::authority::QuarterTurn;
-    std::map<Edge, std::tuple<Face, Face, Turn>> result;
-    for (const auto &junction : certificate.junctions) {
-      for (const auto &side : junction.sectorPaths) {
-        for (const auto &transition : side) {
-          result.emplace(transition.edge, typed_transport(transition));
-        }
-      }
-    }
-    return result;
-  };
   EXPECT_EQ(rail_transport(permutedFront), rail_transport(front))
       << "source-face-row permutation must not alter typed owner-rail chi";
-  EXPECT_EQ(radial_transport(*permutedMidline),
-            radial_transport(*producedMidline))
-      << "source-face-row permutation must not alter nonrail A3 phi";
-
-  // A certificate with one tampered nonrail A3 step must fail at the
-  // independent product validator; it must not obtain a fresh A5 gauge.
-  PhaseFrontDraft wrongRadial = phase_front_draft(fixture);
-  const auto wrong = std::find_if(wrongRadial.hardRailRouteCertificates.begin(),
-                                  wrongRadial.hardRailRouteCertificates.end(),
-                                  is_midline_pair);
-  ASSERT_NE(wrong, wrongRadial.hardRailRouteCertificates.end());
-  ASSERT_FALSE(wrong->junctions.front().sectorPaths[0].empty());
-  auto &badStep = wrong->junctions.front().sectorPaths[0].front();
-  badStep.firstToSecond = compose(
-      directional::authority::QuarterTurn::from_integer(1),
-      badStep.firstToSecond);
-  expect_phase_front_product_error(
-      construct_phase_front_product(std::move(wrongRadial)),
-      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
+
   std::size_t attestedTerminalSteps = 0U;
   for (const auto &route : front.hardRailRouteCertificates()) {
     ASSERT_FALSE(route.route.empty());
@@ -3552,29 +3517,24 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
         auto at = side == 0U ? endpoint.firstAttachment
                              : endpoint.secondAttachment;
         for (const auto &step : endpoint.contactPaths[side]) {
-          ++attestedTerminalSteps;
           EXPECT_EQ(at, step.firstFace);
           EXPECT_FALSE(front.hardFeatureEdges().contains(step.edge));
-          ASSERT_TRUE(endpoint.terminalVertex.has_value());
-          EXPECT_TRUE(step.edge.first() == *endpoint.terminalVertex ||
-                      step.edge.second() == *endpoint.terminalVertex);
+          const auto vertex = endpoint.terminalVertex.has_value()
+                                  ? endpoint.terminalVertex
+                                  : endpoint.railVertex;
+          ASSERT_TRUE(vertex.has_value())
+              << "only T and R endpoints own source-star contact steps";
+          if (endpoint.terminalVertex.has_value()) ++attestedTerminalSteps;
+          EXPECT_TRUE(step.edge.first() == *vertex ||
+                      step.edge.second() == *vertex);
           at = step.secondFace;
         }
         EXPECT_EQ(at, side == 0U ? endpoint.terminalCarrier.firstFace
                                 : endpoint.terminalCarrier.secondFace);
       }
     }
-    for (const auto &junction : route.junctions) {
-      // Both sectors carry only non-rail A3 transitions and never
-      // compose distinct HardRail crossings end to end.
-      for (const auto &path : junction.sectorPaths) {
-        for (const auto &step : path) {
-          EXPECT_FALSE(front.hardFeatureEdges().contains(step.edge));
-          EXPECT_TRUE(step.edge.first() == junction.junction ||
-                      step.edge.second() == junction.junction);
-        }
-      }
-    }
+    EXPECT_TRUE(route.junctions.empty())
+        << "junction certificates remain unwitnessed (O9)";
   }
   EXPECT_GT(attestedTerminalSteps, 0U)
       << "D2 must certify a produced non-direct A2b terminal attachment";
~~~
