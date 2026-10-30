# RA-180 — O15: exact A3 branch-topology predicates (2026-10-30)

**Turn:** `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` (DEFN, Review track), run locally. **Authority:** [RA-176.3](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md) and [RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md). Probes are diagnostic only (GMP_COMPILE_POLICY). Source is `2a49b873…`, unchanged in `src/`, `include/` and `tests/` at HEAD `c45c7da04`. A read-only subagent produced the inventory; the Review agent verified it against the code.

## RA-180.1 Inventory of float-decided topology in A3 (`src/authority/FieldTransportAtlas.cpp`)

| # | Decision | Tie possible on valid input? | CB55 |
|---|---|---|---|
| T1 | Face gauge: the raw branch with the least angle from p0→p1 (`atan2` + 1e-10 tolerance, `:276–296`). A branch exactly on p0→p1 lands at 0 or about 2π depending on rounding. | **Yes** (edge-aligned branch) | Exact |
| T2 | Branch barycentric derivatives `u` and `v` (`:157–170`), computed in double from the normalized, projected direction and then converted exactly. They decide boundary flow and the half-open sector membership (`:468`, already an exact rule). | **Yes**: an edge-aligned branch has an exact 0 component, but rounds to 0 or ±1e-16 | Exact |
| T3 | Port representative order (`:818–853`): `counter_clockwise_sector_angle` with the 0/2π wrap and a tolerance reject. | **Yes** (branch on the start ray) | Exact |
| G1–G5 | Conditioning guards that reject degenerate input against a tolerance: face normal norm, projected norm, `det ≤ 1e-10`, `|p·s| > 1−1e-8`, non-finite values. | No exact tie; these are thresholds | Unchanged; accepted-defensive |
| R1 | Cycle lift `round(exactLift)` with 1e-6 (`:2504–2534`). | No (an integer within noise); half-integers are rejected | Unchanged |
| R2 | Upstream `principal_matching` argmin (`src/fields/FieldMatching.cpp:63–131`) is a fields-stage decision; a tie means an exact ±π/4 rotation. | Degenerate input only | **Carried as O15b** (fields stage, not A3) |

## RA-180.2 Exact rule (CB55)

- **T2.** Compute `u` and `v` exactly from the stored doubles, using the raw (unnormalized, unprojected) cross-field vector:
  - `u = (s1·c − s2·b)/det` and `v = (s2·a − s1·b)/det`, with GMP `FieldExactRational`;
  - the in-plane projection and positive normalization do not change the signs, and the ray is unchanged.
  - An edge-aligned branch now has an exactly zero component, and the existing half-open rule (`next > 0 ∧ previous ≥ 0`) counts it exactly once.
- **T1.** Order the four raw branches exactly by counter-clockwise angle in [0, 2π) from p0→p1, with angle 0 included.
  - The half-plane test is the sign of `n·(e×d)`; otherwise ties break toward `e·d > 0`. Within a half-plane, order by the sign of `n·(d₁×d₂)`.
  - An exact tie between distinct branches is rejected as `AmbiguousBranchTopology`.
- **T3.** Within a corner, order representatives by the exact ratio previous/next of their barycentric derivatives, compared by cross-multiplication. An exact tie is rejected as `AmbiguousBranchTopology`.
- **Removed** because no longer used: `positive_oriented_angle`, `counter_clockwise_sector_angle`, `kTwoPi` and `<limits>`.

## RA-180.3 Probe evidence

The scratch build used source `2a49b873…` with the CI configure flags, in two variants:
- the default build (FMA);
- `-ffp-contract=off` throughout (Linux-like); verified 0 FMA instructions in the archived atlas object (RA-179 method).

Evidence is in `build/local-evidence/RA180/` (gitignored).

| Check | Before the patch | After the patch |
|---|---|---|
| Full gate, 855 rows, FMA build | 836/19 (TB53) | **854/855**; only 283 (O2) |
| Full gate, FMA-free build | 854/855 (RA-179 variant B) | **854/855**, byte-identical verdicts (`513e6d98…`) |
| Atlas partition records (4,763 lines) | FMA and FMA-free differ in 682 lines | FMA = FMA-free = pre-patch FMA-free (`f1e0202c…`) |
| 83 deferred rows | 82 RED / 1 PASS | identical verdicts and first-failure sites (`0a664a3d…`) |
| New `EdgeParallelBranchPublishesExactTangentFlow` | **FAIL** with FMA and with FMA-free atlas | PASS in both |
| New `MechanicalFeatureSingularPortsFollowExactHalfOpenSectors` | FAIL with FMA; PASS with FMA-free atlas | PASS in both |

- **Failing-first evidence on Linux-like arithmetic.** On the non-dyadic parallelogram, the pre-patch double derivative opposite the 0→1 edge is 1.9e-16 without FMA and 2.2e-16 with FMA (`redfirst-probe.cpp`). After the patch it is exactly 0.
- **The `mechanical_feature` oracle matches RA-176's exact count:** 3 incidences and 3 classes at each of vertices 10, 35, 47 and 71.
- **Published direction values change.** They are now the exact derivatives of the raw branch, not of the normalized rounded one. No gated or deferred test pins them; the digests are recomputed from the product.
- **Observations (no new obligation here):**
  - Deferred row 362 (Cylinder design acceptance) passes locally in 179 s, both before and after the patch. Its CI failure is a 600 s timeout, which matters for the P13 slice.
  - With the display-test options, close_sheets, cylinder, multi_face_seam and plane each run longer than 300 s.

## RA-180.4 Row 935 (CB56) — split out

A per-fixture census of the display test's inputs, with the patched build and a 300 s limit per fixture, found **no committed `milestone-g` fixture that stops with a source-vertex locus**:
- mechanical_feature, genus_two, torus and thin_bent_tube stop in `tracing` with no locus;
- sphere_prescribed stops at the cut graph with a face locus;
- four fixtures exceed 300 s.

The vertex section of row 935 therefore needs a constructed input that a stage legitimately rejects at a vertex: for example, an atlas singularity-metadata rejection from a +½-index singularity. That is its own probe-backed definition: **`M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS`** (DEFN, R), which comes before CB56. Row 935 stays FIXTURE in ledger v3.

## RA-180.5 CB55 — exact patch

**Turn:** `M6-CP3-CB55-A3-EXACT-BRANCH-TOPOLOGY` (CB). Run locally while the implementation agent is unavailable; Code + Build, compile-only.
- **Scope:**
  - `src/authority/FieldTransportAtlas.cpp`: T1, T2, T3.
  - `tests/FieldTransportAtlasTests.cpp`: the edge-parallel failing-first test.
  - `tests/FieldAlignedCurveNetworkTests.cpp`: the `mechanical_feature` exact-port oracle.
  - No header, fixture, CMake, workflow, manifest or ledger change.
- **Checks:**
  - Extract the RA-180.7 block verbatim, adding a trailing newline. Its SHA-256 must be `824e64cc76f9ebf6fdba905a8258c68ddc1a5a30b64a3baa36e8489803bf0f70`.
  - `git apply --check`, then apply. The numstat must be exactly `119 81` (atlas), `14 0` (FieldAlignedCurveNetworkTests) and `51 0` (FieldTransportAtlasTests).
  - The resulting atlas SHA-256 must be `43d156a3273495504fcd73a253e60ac09baeea4102f84b90186f8e6883a49461`.
  - Build the eight targets with the CI flags at **default arithmetic** (O15 is fixed, so the RA-179.4 FMA-free convention no longer applies after CB55). Stage the package as for CB54.

| CB55 result | Successor |
|---|---|
| All exact, package built | `M6-CP3-TB54-O15-FULL-GATE-EXEC` |
| Patch, SHA, numstat or compile mismatch | `M6-CP3-PLAN-O15-EXACT-ATLAS-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CP3-CB55A-O15-ORCH`, then one retry |

## RA-180.6 TB54 frozen inputs

- **Gate:** [`Architecture_M6_CP3_TB54_O15_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB54_O15_Full_Gate_Case_Manifest.tsv), 857 rows, SHA-256 `53683907397327faf1147c7e7ced73c1a839701db47241933134c9a20b0bec3c`.
  - The first 856 lines are TB53 (`5239f81a…`).
  - Row 856 is `GUARD ra180:o15-edge-parallel` (authority kernel binary); row 857 is `GUARD ra180:o15-mechanical-ports` (producer binary).
- **Ledger:** v3 is unchanged (83, `32b43fc5…`).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=857 deferred=83`. The real membership check of the patched binaries' listings, using the harness's own `membership`, gives **940**.

| TB54 result (local, default arithmetic) | Successor |
|---|---|
| 856/857 PASS, with row 283 the only RED (pre-classified O2, RA-179 F3), postflight true, membership 940 | `M6-CP3-TB54-O15-FULL-GATE-REV` (R): rules O15 discharged |
| Any other non-PASS | TB54-REV classifies it; no retry |
| Membership error | `M6-CP3-PLAN-O15-MEMBERSHIP-STOP` (PLAN, R) |

## RA-180.7 Exact CB55 patch

~~~diff
diff --git a/src/authority/FieldTransportAtlas.cpp b/src/authority/FieldTransportAtlas.cpp
index 71ac61941..24e04e79c 100644
--- a/src/authority/FieldTransportAtlas.cpp
+++ b/src/authority/FieldTransportAtlas.cpp
@@ -12,7 +12,6 @@
 #include <cmath>
 #include <exception>
 #include <iostream>
-#include <limits>
 #include <map>
 #include <numbers>
 #include <numeric>
@@ -42,7 +41,6 @@ int normalized_quarter_turn(const int value) {
 }
 
 constexpr double kBranchTopologyTolerance = 1.0e-10;
-constexpr double kTwoPi = 2.0 * std::numbers::pi;
 
 std::optional<SourceFaceId> row_for_topology(
     const std::vector<SourceFaceTopologyKey> &rowTopology,
@@ -115,13 +113,33 @@ std::optional<Eigen::Vector3d> normalized_projected(
   return tangent;
 }
 
-double positive_oriented_angle(const Eigen::Vector3d &from,
-                               const Eigen::Vector3d &to,
-                               const Eigen::Vector3d &normal) {
-  double angle = std::atan2(normal.dot(from.cross(to)), from.dot(to));
-  if (angle < 0.0) angle += kTwoPi;
-  if (angle >= kTwoPi) angle -= kTwoPi;
-  return angle;
+// Branch topology is decided exactly on the stored doubles (DESIGN Amendment
+// 18): a branch lying exactly on a source edge is a tie that only an exact
+// predicate resolves the same way on every platform.
+using ExactVector = std::array<FieldExactRational, 3>;
+
+std::optional<ExactVector> exact_vector(const Eigen::Vector3d &value) {
+  ExactVector result;
+  for (std::size_t axis = 0; axis < 3U; ++axis) {
+    const auto coordinate =
+        FieldExactRational::from_double_exact(value[static_cast<int>(axis)]);
+    if (!coordinate.has_value()) return std::nullopt;
+    result[axis] = *coordinate;
+  }
+  return result;
+}
+
+ExactVector exact_difference(const ExactVector &a, const ExactVector &b) {
+  return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
+}
+
+FieldExactRational exact_dot(const ExactVector &a, const ExactVector &b) {
+  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
+}
+
+ExactVector exact_cross(const ExactVector &a, const ExactVector &b) {
+  return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
+          a[0] * b[1] - a[1] * b[0]};
 }
 
 struct BuiltFaceBranchFrame {
@@ -133,7 +151,7 @@ struct BuiltFaceBranchFrame {
 std::optional<FieldBranchBoundaryPairing> build_boundary_pairing(
     const TriMesh &sourceMesh, const SourceFaceId sourceFace,
     const SourceFaceTopologyKey &topology, const TopologyRegionId region,
-    const FieldBranch branch, const Eigen::Vector3d &direction,
+    const FieldBranch branch, const ExactVector &direction,
     FieldAtlasBuildError &error) {
   const auto &vertices = topology.vertices();
   const Eigen::Vector3d p0 = sourceMesh.V.row(
@@ -154,28 +172,35 @@ std::optional<FieldBranchBoundaryPairing> build_boundary_pairing(
         sourceFace, std::nullopt, region};
     return std::nullopt;
   }
-  const double r1 = e1.dot(direction);
-  const double r2 = e2.dot(direction);
-  const double u = (r1 * c - r2 * b) / det;
-  const double v = (r2 * a - r1 * b) / det;
-  const std::array<double, 3> dbary{-u - v, u, v};
-  if (!std::isfinite(dbary[0]) || !std::isfinite(dbary[1]) ||
-      !std::isfinite(dbary[2])) {
+  // Barycentric derivatives of the raw branch's in-plane component, exact on
+  // the stored doubles: a branch along an edge has an exactly zero component.
+  const auto x0 = exact_vector(p0);
+  const auto x1 = exact_vector(p1);
+  const auto x2 = exact_vector(p2);
+  if (!x0.has_value() || !x1.has_value() || !x2.has_value()) {
     error = FieldAtlasBuildError{
         FieldAtlasBuildErrorCode::InvalidBranchBoundaryDerivative,
         std::nullopt, sourceFace, std::nullopt, region};
     return std::nullopt;
   }
-  const auto exactU = FieldExactRational::from_double_exact(u);
-  const auto exactV = FieldExactRational::from_double_exact(v);
-  if (!exactU.has_value() || !exactV.has_value()) {
+  const ExactVector f1 = exact_difference(*x1, *x0);
+  const ExactVector f2 = exact_difference(*x2, *x0);
+  const FieldExactRational ea = exact_dot(f1, f1);
+  const FieldExactRational eb = exact_dot(f1, f2);
+  const FieldExactRational ec = exact_dot(f2, f2);
+  const FieldExactRational exactDet = ea * ec - eb * eb;
+  if (exactDet <= FieldExactRational::from_integer(0)) {
     error = FieldAtlasBuildError{
-        FieldAtlasBuildErrorCode::InvalidBranchBoundaryDerivative,
-        std::nullopt, sourceFace, std::nullopt, region};
+        FieldAtlasBuildErrorCode::InvalidBranchBoundaryBasis, std::nullopt,
+        sourceFace, std::nullopt, region};
     return std::nullopt;
   }
+  const FieldExactRational s1 = exact_dot(f1, direction);
+  const FieldExactRational s2 = exact_dot(f2, direction);
+  const FieldExactRational exactU = (s1 * ec - s2 * eb) / exactDet;
+  const FieldExactRational exactV = (s2 * ea - s1 * eb) / exactDet;
   const FieldBranchDirection exactDirection{
-      std::array<FieldExactRational, 3>{-*exactU - *exactV, *exactU, *exactV}};
+      std::array<FieldExactRational, 3>{-exactU - exactV, exactU, exactV}};
   if (!exactDirection.is_barycentric()) {
     error = FieldAtlasBuildError{
         FieldAtlasBuildErrorCode::BranchDirectionNotBarycentric,
@@ -274,21 +299,54 @@ std::optional<BuiltFaceBranchFrame> build_face_branch_frame(
   }
   const std::array<Eigen::Vector3d, 4> rawDirections{
       *primary, *secondary, -*primary, -*secondary};
-  std::array<double, 4> angles{};
+  const auto x0 = exact_vector(p0);
+  const auto x1 = exact_vector(p1);
+  const auto x2 = exact_vector(p2);
+  const auto exactPrimary = exact_vector(
+      crossField.primaryDirections.row(static_cast<int>(row.index())).transpose());
+  const auto exactSecondary = exact_vector(
+      crossField.secondaryDirections.row(static_cast<int>(row.index())).transpose());
+  if (!x0.has_value() || !x1.has_value() || !x2.has_value() ||
+      !exactPrimary.has_value() || !exactSecondary.has_value()) {
+    error = FieldAtlasBuildError{
+        FieldAtlasBuildErrorCode::InvalidBranchTopology, std::nullopt, row,
+        std::nullopt, region};
+    return std::nullopt;
+  }
+  const auto negated = [](const ExactVector &value) {
+    return ExactVector{-value[0], -value[1], -value[2]};
+  };
+  const std::array<ExactVector, 4> exactRawDirections{
+      *exactPrimary, *exactSecondary, negated(*exactPrimary),
+      negated(*exactSecondary)};
+  // Gauge: the raw branch at the least counter-clockwise angle in [0, 2pi)
+  // from p0->p1, angle zero included. Orientation signs use the unnormalized
+  // face normal; the normal component of a raw branch does not affect them.
+  const ExactVector edge = exact_difference(*x1, *x0);
+  const ExactVector faceNormal =
+      exact_cross(edge, exact_difference(*x2, *x0));
+  const FieldExactRational zero = FieldExactRational::from_integer(0);
+  const auto lower_half = [&](const ExactVector &direction) {
+    const FieldExactRational sine =
+        exact_dot(faceNormal, exact_cross(edge, direction));
+    return sine < zero || (sine == zero && exact_dot(edge, direction) < zero);
+  };
+  const auto precedes = [&](const ExactVector &first, const ExactVector &second) {
+    const bool firstLower = lower_half(first);
+    if (firstLower != lower_half(second)) return !firstLower;
+    return exact_dot(faceNormal, exact_cross(first, second)) > zero;
+  };
   int gauge = 0;
-  double best = std::numeric_limits<double>::infinity();
-  for (int raw = 0; raw < 4; ++raw) {
-    angles[static_cast<std::size_t>(raw)] = positive_oriented_angle(
-        *reference, rawDirections[static_cast<std::size_t>(raw)], normal);
-    if (angles[static_cast<std::size_t>(raw)] < best) {
-      best = angles[static_cast<std::size_t>(raw)];
+  for (int raw = 1; raw < 4; ++raw) {
+    if (precedes(exactRawDirections[static_cast<std::size_t>(raw)],
+                 exactRawDirections[static_cast<std::size_t>(gauge)])) {
       gauge = raw;
     }
   }
   for (int raw = 0; raw < 4; ++raw) {
     if (raw != gauge &&
-        std::abs(angles[static_cast<std::size_t>(raw)] - best) <=
-            kBranchTopologyTolerance) {
+        !precedes(exactRawDirections[static_cast<std::size_t>(gauge)],
+                  exactRawDirections[static_cast<std::size_t>(raw)])) {
       error = FieldAtlasBuildError{
           FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt, row,
           std::nullopt, region};
@@ -305,7 +363,7 @@ std::optional<BuiltFaceBranchFrame> build_face_branch_frame(
         rawDirections[static_cast<std::size_t>(raw)];
     const auto pairing = build_boundary_pairing(
         sourceMesh, row, topology, region, FieldBranch::from_integer(semantic),
-        built.canonicalDirections[static_cast<std::size_t>(semantic)], error);
+        exactRawDirections[static_cast<std::size_t>(raw)], error);
     if (!pairing.has_value()) {
       return std::nullopt;
     }
@@ -488,42 +546,6 @@ bool direction_in_closed_incident_vertex_wedge(
          !(next == zero && previous == zero);
 }
 
-std::optional<double> counter_clockwise_sector_angle(
-    const TriMesh &sourceMesh, const IncidentFanFace &face,
-    const SourceVertexId vertex, const Eigen::Vector3d &direction) {
-  const Eigen::Vector3d origin =
-      sourceMesh.V.row(static_cast<int>(vertex.index())).transpose();
-  Eigen::Vector3d start =
-      sourceMesh.V.row(static_cast<int>(face.nextVertex.index())).transpose() -
-      origin;
-  Eigen::Vector3d end =
-      sourceMesh.V.row(static_cast<int>(face.previousVertex.index())).transpose() -
-      origin;
-  Eigen::Vector3d normal = start.cross(end);
-  const double normalNorm = normal.norm();
-  const double startNorm = start.norm();
-  const double endNorm = end.norm();
-  if (!std::isfinite(normalNorm) || !std::isfinite(startNorm) ||
-      !std::isfinite(endNorm) || normalNorm <= kBranchTopologyTolerance ||
-      startNorm <= kBranchTopologyTolerance ||
-      endNorm <= kBranchTopologyTolerance) {
-    return std::nullopt;
-  }
-  normal /= normalNorm;
-  start /= startNorm;
-  end /= endNorm;
-  const auto tangent = normalized_projected(direction, normal);
-  if (!tangent.has_value()) return std::nullopt;
-  const double sector = positive_oriented_angle(start, end, normal);
-  const double angle = positive_oriented_angle(start, *tangent, normal);
-  if (!std::isfinite(sector) || !std::isfinite(angle) ||
-      sector <= kBranchTopologyTolerance ||
-      angle > sector + kBranchTopologyTolerance) {
-    return std::nullopt;
-  }
-  return angle;
-}
-
 const FieldBranchBoundaryPairing *find_pairing(
     const FieldFaceBranchFrame &frame, const FieldBranch branch) {
   const auto found = std::find_if(
@@ -788,10 +810,19 @@ build_singularity_attachments(
       representatives.push_back(incidences[classIndices.front()]);
     }
 
+    // Within one corner the counter-clockwise angle from the next-vertex ray
+    // grows with the exact ratio towardPrevious / towardNext (towardNext > 0
+    // for a sector member), so slots compare by cross-multiplication.
     struct OrderedRepresentative {
       FieldSingularityPortAttachment attachment;
       std::size_t counterClockwiseFanSlot = 0U;
-      double sectorAngle = 0.0;
+      FieldExactRational towardNext;
+      FieldExactRational towardPrevious;
+    };
+    const auto angle_compare = [](const OrderedRepresentative &first,
+                                  const OrderedRepresentative &second) {
+      return first.towardPrevious * second.towardNext <=>
+             second.towardPrevious * first.towardNext;
     };
     std::vector<OrderedRepresentative> orderedRepresentatives;
     orderedRepresentatives.reserve(representatives.size());
@@ -815,35 +846,42 @@ build_singularity_attachments(
           static_cast<std::size_t>(std::distance(fan->begin(), fanIt));
       const std::size_t counterClockwiseFanSlot =
           clockwiseFanSlot == 0U ? 0U : fan->size() - clockwiseFanSlot;
-      const auto angle = counter_clockwise_sector_angle(
-          sourceMesh, *fanIt, singularity.sourceVertex,
-          builtFramesByRow[fanIt->row.index()]
-              .canonicalDirections[representative.branch.value()]);
-      if (!angle.has_value()) {
+      const FieldBranchBoundaryPairing *pairing = find_pairing(
+          builtFramesByRow[fanIt->row.index()].published, representative.branch);
+      const auto &faceVertices = fanIt->topology.vertices();
+      const auto nextAt = std::find(faceVertices.begin(), faceVertices.end(),
+                                    fanIt->nextVertex);
+      const auto previousAt = std::find(faceVertices.begin(), faceVertices.end(),
+                                        fanIt->previousVertex);
+      if (pairing == nullptr || nextAt == faceVertices.end() ||
+          previousAt == faceVertices.end()) {
         error = FieldAtlasBuildError{
             FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt,
             fanIt->row, singularity.sourceVertex, singularity.topologyRegion};
         return std::nullopt;
       }
       orderedRepresentatives.push_back(OrderedRepresentative{
-          representative, counterClockwiseFanSlot, *angle});
+          representative, counterClockwiseFanSlot,
+          pairing->direction[static_cast<std::size_t>(
+              std::distance(faceVertices.begin(), nextAt))],
+          pairing->direction[static_cast<std::size_t>(
+              std::distance(faceVertices.begin(), previousAt))]});
     }
     std::sort(orderedRepresentatives.begin(), orderedRepresentatives.end(),
-              [](const OrderedRepresentative &first,
-                 const OrderedRepresentative &second) {
+              [&](const OrderedRepresentative &first,
+                  const OrderedRepresentative &second) {
                 if (first.counterClockwiseFanSlot !=
                     second.counterClockwiseFanSlot) {
                   return first.counterClockwiseFanSlot <
                          second.counterClockwiseFanSlot;
                 }
-                return first.sectorAngle < second.sectorAngle;
+                return angle_compare(first, second) < 0;
               });
     for (std::size_t index = 1U; index < orderedRepresentatives.size(); ++index) {
       const auto &previous = orderedRepresentatives[index - 1U];
       const auto &current = orderedRepresentatives[index];
       if (previous.counterClockwiseFanSlot == current.counterClockwiseFanSlot &&
-          std::abs(previous.sectorAngle - current.sectorAngle) <=
-              kBranchTopologyTolerance) {
+          angle_compare(previous, current) == 0) {
         const auto sourceFace =
             row_for_topology(rowTopology, current.attachment.startFace);
         error = FieldAtlasBuildError{
diff --git a/tests/FieldAlignedCurveNetworkTests.cpp b/tests/FieldAlignedCurveNetworkTests.cpp
index f6da18884..2f68eb947 100644
--- a/tests/FieldAlignedCurveNetworkTests.cpp
+++ b/tests/FieldAlignedCurveNetworkTests.cpp
@@ -10989,6 +10989,20 @@ TEST(FieldTransportAtlas, NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis) {
   std::cout << "m3Cp4c3AM1AM6" << report.str() << '\n';
 }
 
+// O15 (RA-176/RA-180): branches of mechanical_feature lie exactly on star
+// edges at its index-one singularities. The exact half-open sector rule gives
+// three port classes at each of vertices 10, 35, 47 and 71 on every platform.
+TEST(FieldTransportAtlas, MechanicalFeatureSingularPortsFollowExactHalfOpenSectors) {
+  const auto &fixture = cp4c_mechanical_atlas_fixture();
+  ASSERT_TRUE(fixture.atlas.has_value());
+  std::map<std::size_t, int> ports;
+  for (const auto &attachment :
+       fixture.atlas->branch_topology().singularity_port_attachments())
+    ++ports[attachment.sourceVertex.index()];
+  for (const std::size_t vertex : {10U, 35U, 47U, 71U})
+    EXPECT_EQ(3, ports[vertex]) << "source vertex " << vertex;
+}
+
 TEST(FieldTransportAtlas, CutTransportDomainSatisfiesTheEulerCutIdentity) {
   const auto &fixture = cp4c_mechanical_atlas_fixture();
   ASSERT_TRUE(fixture.atlas.has_value());
diff --git a/tests/FieldTransportAtlasTests.cpp b/tests/FieldTransportAtlasTests.cpp
index d7e3b5277..40e672585 100644
--- a/tests/FieldTransportAtlasTests.cpp
+++ b/tests/FieldTransportAtlasTests.cpp
@@ -391,6 +391,57 @@ TEST(M4CP4, ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRej
             nonFlatAtlas.error().code);
 }
 
+// O15 (RA-180): a branch exactly parallel to a source edge has an exactly
+// zero barycentric derivative at the opposite vertex, so that edge's flow is
+// Tangent on every platform. The non-dyadic parallelogram makes a
+// double-evaluated derivative nonzero with or without FMA contraction.
+TEST(FieldTransportAtlas, EdgeParallelBranchPublishesExactTangentFlow) {
+  Eigen::MatrixXd vertices(4, 3);
+  vertices << 0.0, 0.0, 0.0,
+              0.3, 0.1, 0.0,
+              0.2, 0.7, 0.0,
+              -0.1, 0.6, 0.0;
+  Eigen::MatrixXi faces(2, 3);
+  faces << 0, 1, 2,
+           0, 2, 3;
+  TriMesh mesh;
+  mesh.set_mesh(vertices, faces);
+  const auto sourceAuthority = make_source_authority(mesh);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  CrossFieldResult field = make_zero_transport_field(mesh);
+  for (int face = 0; face < mesh.F.rows(); ++face) {
+    field.primaryDirections.row(face) << 0.3, 0.1, 0.0;
+    field.secondaryDirections.row(face) << -0.1, 0.3, 0.0;
+  }
+  const auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
+  ASSERT_TRUE(built) << describe_field_atlas_build_error(built.error());
+
+  const auto zero = directional::authority::FieldExactRational::from_integer(0);
+  int edgeParallel = 0;
+  for (const auto &frame : built.value().branch_topology().frames()) {
+    const auto &corners = frame.sourceFace.vertices();
+    const auto opposite = std::find_if(
+        corners.begin(), corners.end(),
+        [](const auto &vertex) { return vertex.index() == 2U; });
+    if (opposite == corners.end() ||
+        std::none_of(corners.begin(), corners.end(),
+                     [](const auto &vertex) { return vertex.index() == 1U; })) {
+      continue;
+    }
+    const auto at = static_cast<std::size_t>(opposite - corners.begin());
+    for (const FieldBranchBoundaryPairing &pairing : frame.branches) {
+      if (pairing.direction[at] != zero) continue;
+      ++edgeParallel;
+      for (const auto &interval : pairing.intervals) {
+        const bool alongEdge = interval.sourceEdge.first().index() == 0U &&
+                               interval.sourceEdge.second().index() == 1U;
+        EXPECT_EQ(alongEdge, interval.flow == FieldBoundaryFlow::Tangent);
+      }
+    }
+  }
+  EXPECT_EQ(2, edgeParallel) << "the primary branch and its opposite lie on edge (0,1)";
+}
+
 CrossFieldEdgeTransition *find_transition(CrossFieldResult &field,
                                           const SourceEdgeTopologyKey &key,
                                           const std::size_t vertexExtent) {
~~~
