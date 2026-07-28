#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceComplexSimplification.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
using Clock = std::chrono::steady_clock;
using directional::geometry::SurfaceArrangementArc;
using directional::geometry::SurfaceCellComplex;
using directional::geometry::SurfaceSimplificationCandidate;
using directional::geometry::SurfaceSimplificationCandidateSet;
using directional::geometry::SurfaceSimplificationCandidateType;
using directional::geometry::SurfaceSimplificationResult;

struct FixtureInput {
  std::string name;
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  std::vector<SurfaceArrangementArc> arcs;
};

struct FixtureResult {
  std::string name;
  double arrangementSeconds = 0.0;
  double candidateSeconds = 0.0;
  double queueSeconds = 0.0;
  int denseCells = 0;
  int simplifiedCells = 0;
  int denseHalfedges = 0;
  int simplifiedHalfedges = 0;
  int candidateCount = 0;
  int commits = 0;
  int rejected = 0;
  int invalidated = 0;
  int recomputed = 0;
  int validatorPasses = 0;
  int eulerBefore = 0;
  int eulerAfter = 0;
  int boundaryLoopsBefore = 0;
  int boundaryLoopsAfter = 0;
  bool topologyValidBefore = false;
  bool topologyValidAfter = false;
  std::map<int, int> rejectionHistogram;
};

SurfaceArrangementArc make_arc(const int id, const int face,
                               const Eigen::RowVector3d &a,
                               const Eigen::RowVector3d &b,
                               const int family, const int strand) {
  SurfaceArrangementArc value;
  value.id = id;
  value.sourceFace = face;
  value.startBarycentric = a;
  value.endBarycentric = b;
  value.family = family;
  value.strand = strand;
  value.provenance = id;
  value.sourceComponent = 0;
  value.sourceSheet = 0;
  return value;
}

FixtureInput planar_fixture() {
  FixtureInput fixture;
  fixture.name = "oversampled_planar";
  fixture.vertices.resize(3, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0;
  fixture.faces.resize(1, 3);
  fixture.faces << 0, 1, 2;
  int id = 0;
  for (const double t : {0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80}) {
    fixture.arcs.push_back(make_arc(
        id, 0, {1.0 - t, t, 0.0}, {1.0 - t, 0.0, t}, 0, id));
    ++id;
  }
  return fixture;
}

FixtureInput cylinder_fixture(const int segments = 12,
                              const int axialCells = 3) {
  FixtureInput fixture;
  fixture.name = "open_cylinder";
  constexpr double pi = 3.14159265358979323846;
  fixture.vertices.resize((axialCells + 1) * segments, 3);
  for (int ring = 0; ring <= axialCells; ++ring) {
    const double z = static_cast<double>(ring) / axialCells;
    for (int segment = 0; segment < segments; ++segment) {
      const double angle = 2.0 * pi * segment / segments;
      fixture.vertices.row(ring * segments + segment) =
          Eigen::RowVector3d(std::cos(angle), std::sin(angle), z);
    }
  }
  fixture.faces.resize(2 * axialCells * segments, 3);
  int faceId = 0;
  for (int ring = 0; ring < axialCells; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const int next = (segment + 1) % segments;
      const int v00 = ring * segments + segment;
      const int v10 = ring * segments + next;
      const int v01 = (ring + 1) * segments + segment;
      const int v11 = (ring + 1) * segments + next;
      fixture.faces.row(faceId++) = Eigen::RowVector3i(v00, v10, v01);
      fixture.faces.row(faceId++) = Eigen::RowVector3i(v10, v11, v01);
    }
  }

  struct RequestedEdge { int a; int b; int family; int strand; };
  std::vector<RequestedEdge> requested;
  for (int segment = 0; segment < segments; ++segment) {
    for (int ring = 0; ring < axialCells; ++ring) {
      requested.push_back({ring * segments + segment,
                           (ring + 1) * segments + segment, 1, segment});
    }
  }
  for (int ring = 1; ring < axialCells; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      requested.push_back({ring * segments + segment,
                           ring * segments + (segment + 1) % segments,
                           0, 1000 + ring});
    }
  }
  int arcId = 0;
  for (const RequestedEdge &edge : requested) {
    for (int face = 0; face < fixture.faces.rows(); ++face) {
      int localA = -1;
      int localB = -1;
      for (int corner = 0; corner < 3; ++corner) {
        if (fixture.faces(face, corner) == edge.a) localA = corner;
        if (fixture.faces(face, corner) == edge.b) localB = corner;
      }
      if (localA < 0 || localB < 0) continue;
      Eigen::RowVector3d a = Eigen::RowVector3d::Zero();
      Eigen::RowVector3d b = Eigen::RowVector3d::Zero();
      a[localA] = 1.0;
      b[localB] = 1.0;
      fixture.arcs.push_back(
          make_arc(arcId++, face, a, b, edge.family, edge.strand));
    }
  }
  return fixture;
}

const SurfaceSimplificationCandidate *select_candidate(
    const SurfaceSimplificationCandidateSet &set) {
  const auto found = std::find_if(
      set.candidates.begin(), set.candidates.end(), [](const auto &candidate) {
        return (candidate.type == SurfaceSimplificationCandidateType::OpenStrip ||
                candidate.type ==
                    SurfaceSimplificationCandidateType::RedundantStrand) &&
               !candidate.touchesHardFeature && !candidate.touchesBoundary &&
               !candidate.touchesSingularity &&
               !candidate.touchesLocalSheetBoundary &&
               !candidate.changesTopology && candidate.sideFeasible &&
               candidate.affectedPatchDisk && !candidate.elementIds.empty();
      });
  return found == set.candidates.end() ? nullptr : &*found;
}

template <typename Function>
double measure(Function &&function) {
  const auto start = Clock::now();
  function();
  return std::chrono::duration<double>(Clock::now() - start).count();
}

FixtureResult run_fixture(const FixtureInput &input) {
  FixtureResult output;
  output.name = input.name;
  SurfaceCellComplex dense;
  output.arrangementSeconds = measure([&] {
    dense = directional::geometry::build_surface_cell_complex(
        input.vertices, input.faces, input.arcs);
  });
  if (!dense.diagnostics.topologyValid) {
    throw std::runtime_error(input.name + ": dense arrangement is invalid");
  }
  SurfaceSimplificationCandidateSet candidates;
  output.candidateSeconds = measure([&] {
    candidates =
        directional::geometry::extract_surface_simplification_candidates(
            dense, input.vertices, input.faces);
  });
  const SurfaceSimplificationCandidate *candidate =
      select_candidate(candidates);
  if (candidate == nullptr) {
    throw std::runtime_error(input.name + ": no safe commit candidate");
  }
  SurfaceSimplificationResult simplified;
  output.queueSeconds = measure([&] {
    simplified = directional::geometry::simplify_surface_cell_complex(
        dense, input.vertices, input.faces, {*candidate});
  });
  if (simplified.committed <= 0 || !simplified.complex.diagnostics.topologyValid) {
    throw std::runtime_error(input.name + ": simplification did not commit validly");
  }

  output.denseCells = static_cast<int>(dense.cells.size());
  output.simplifiedCells = static_cast<int>(simplified.complex.cells.size());
  output.denseHalfedges = static_cast<int>(dense.halfedges.size());
  output.simplifiedHalfedges =
      static_cast<int>(simplified.complex.halfedges.size());
  output.candidateCount = static_cast<int>(candidates.candidates.size());
  output.commits = simplified.committed;
  output.rejected = simplified.rejected;
  output.invalidated = simplified.invalidatedCandidates;
  output.recomputed = simplified.recomputedCandidates;
  output.validatorPasses = simplified.validationPasses;
  output.eulerBefore = dense.diagnostics.eulerCharacteristic;
  output.eulerAfter = simplified.complex.diagnostics.eulerCharacteristic;
  output.boundaryLoopsBefore = dense.diagnostics.boundaryLoopCount;
  output.boundaryLoopsAfter =
      simplified.complex.diagnostics.boundaryLoopCount;
  output.topologyValidBefore = dense.diagnostics.topologyValid;
  output.topologyValidAfter = simplified.complex.diagnostics.topologyValid;
  for (const auto &transaction : simplified.transactions) {
    ++output.rejectionHistogram[static_cast<int>(transaction.rejection)];
  }
  return output;
}

void print_result(const FixtureResult &value, const bool last) {
  std::cout << "    {\n"
            << "      \"fixture\": \"" << value.name << "\",\n"
            << "      \"arrangementSeconds\": " << value.arrangementSeconds << ",\n"
            << "      \"candidateGenerationSeconds\": " << value.candidateSeconds << ",\n"
            << "      \"queueSeconds\": " << value.queueSeconds << ",\n"
            << "      \"denseCells\": " << value.denseCells << ",\n"
            << "      \"simplifiedCells\": " << value.simplifiedCells << ",\n"
            << "      \"denseHalfedges\": " << value.denseHalfedges << ",\n"
            << "      \"simplifiedHalfedges\": " << value.simplifiedHalfedges << ",\n"
            << "      \"candidateCount\": " << value.candidateCount << ",\n"
            << "      \"commits\": " << value.commits << ",\n"
            << "      \"rejected\": " << value.rejected << ",\n"
            << "      \"invalidatedCandidates\": " << value.invalidated << ",\n"
            << "      \"recomputedCandidates\": " << value.recomputed << ",\n"
            << "      \"validatorPasses\": " << value.validatorPasses << ",\n"
            << "      \"eulerBefore\": " << value.eulerBefore << ",\n"
            << "      \"eulerAfter\": " << value.eulerAfter << ",\n"
            << "      \"boundaryLoopsBefore\": " << value.boundaryLoopsBefore << ",\n"
            << "      \"boundaryLoopsAfter\": " << value.boundaryLoopsAfter << ",\n"
            << "      \"topologyValidBefore\": "
            << (value.topologyValidBefore ? "true" : "false") << ",\n"
            << "      \"topologyValidAfter\": "
            << (value.topologyValidAfter ? "true" : "false") << ",\n"
            << "      \"rejectionHistogram\": {";
  bool first = true;
  for (const auto &[reason, count] : value.rejectionHistogram) {
    if (!first) std::cout << ", ";
    first = false;
    std::cout << "\"" << reason << "\": " << count;
  }
  std::cout << "}\n    }" << (last ? "\n" : ",\n");
}
} // namespace

int main() {
  try {
    const std::vector<FixtureResult> results = {
        run_fixture(planar_fixture()), run_fixture(cylinder_fixture())};
    std::cout << std::setprecision(17) << "{\n  \"fixtures\": [\n";
    for (std::size_t i = 0; i < results.size(); ++i) {
      print_result(results[i], i + 1U == results.size());
    }
    std::cout << "  ]\n}\n";
    return 0;
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
