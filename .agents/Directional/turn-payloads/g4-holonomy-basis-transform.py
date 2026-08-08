from pathlib import Path
import re


def replace_once(path: str, old: str, new: str) -> None:
    p = Path(path)
    text = p.read_text()
    count = text.count(old)
    if count != 1:
        raise RuntimeError(f"{path}: expected one exact replacement, found {count}: {old[:100]!r}")
    p.write_text(text.replace(old, new, 1))


def regex_once(path: str, pattern: str, replacement: str) -> None:
    p = Path(path)
    text = p.read_text()
    new_text, count = re.subn(pattern, replacement, text, count=1, flags=re.S)
    if count != 1:
        raise RuntimeError(f"{path}: expected one regex replacement, found {count}: {pattern[:100]!r}")
    p.write_text(new_text)


# First-class authority: the result owns a canonical collection rather than one scalar relation.
replace_once(
    "include/directional/geometry/SurfaceCellTracing.h",
    """struct SurfacePeriodicHolonomy {\n  bool enabled = false;\n  int sourceComponent = -1;\n  int sourceSheet = -1;\n  int quarterTurnRotation = 0;\n  Eigen::Vector2i latticeTranslation = Eigen::Vector2i::Zero();\n  /// Ordered interior source-edge route for one complete periodic transport.\n  std::vector<int> sourceRouteEdges;\n  /// Ordered source edges forming the deterministic boundary-to-boundary cut.\n  std::vector<int> cutSourceEdges;\n};\n""",
    """struct SurfacePeriodicHolonomy {\n  int sourceComponent = -1;\n  int sourceSheet = -1;\n  int quarterTurnRotation = 0;\n  Eigen::Vector2i latticeTranslation = Eigen::Vector2i::Zero();\n  /// Ordered interior source-edge route for one complete periodic transport.\n  std::vector<int> sourceRouteEdges;\n  /// Canonical source-edge endpoint keys parallel to sourceRouteEdges.\n  std::vector<std::uint64_t> sourceRouteTopology;\n  /// Ordered source edges forming the deterministic boundary-to-boundary cut.\n  std::vector<int> cutSourceEdges;\n  /// Canonical source-edge endpoint keys parallel to cutSourceEdges.\n  std::vector<std::uint64_t> cutSourceTopology;\n};\n\nenum class SurfacePeriodicHolonomyInsertStatus : int {\n  Inserted = 0,\n  Equivalent = 1,\n  AmbiguousBasis = 2,\n  Incompatible = 3,\n};\n""",
)
replace_once(
    "include/directional/geometry/SurfaceCellTracing.h",
    """  InvalidPeriodicRingCorrespondence = 31,\n  AmbiguousPeriodicRingCorrespondence = 32,\n};\n""",
    """  InvalidPeriodicRingCorrespondence = 31,\n  AmbiguousPeriodicRingCorrespondence = 32,\n  AmbiguousPeriodicRelationBasis = 33,\n  IncompatiblePeriodicRelation = 34,\n};\n""",
)
replace_once(
    "include/directional/geometry/SurfaceCellTracing.h",
    """  int gridU = 0;\n  int gridV = 0;\n  SurfacePeriodicHolonomy periodicHolonomy;\n  SurfacePhaseFrontFailure failure;\n""",
    """  int gridU = 0;\n  int gridV = 0;\n  std::vector<SurfacePeriodicHolonomy> periodicHolonomies;\n  SurfacePhaseFrontFailure failure;\n""",
)
replace_once(
    "include/directional/geometry/SurfaceCellTracing.h",
    """int normalized_branch(const int branch);\n\nEigen::RowVector3d transport_direction_between_faces(\n""",
    """int normalized_branch(const int branch);\n\nSurfacePeriodicHolonomy canonicalize_periodic_holonomy(\n    SurfacePeriodicHolonomy relation);\n\nSurfacePeriodicHolonomyInsertStatus insert_periodic_holonomy(\n    std::vector<SurfacePeriodicHolonomy> &relations,\n    SurfacePeriodicHolonomy relation);\n\nEigen::RowVector3d transport_direction_between_faces(\n""",
)

# Machine-readable diagnostics retain every relation while legacy scalar fields become a derived first-relation view.
replace_once(
    "include/directional/diagnostics/RemeshDiagnostics.h",
    """struct SurfaceCellStageLineage {\n""",
    """struct SurfaceCellPeriodicHolonomyDiagnostics {\n  int sourceComponent = -1;\n  int sourceSheet = -1;\n  int quarterTurnRotation = 0;\n  int translationU = 0;\n  int translationV = 0;\n  std::vector<int> sourceRouteEdges;\n  std::vector<std::uint64_t> sourceRouteTopology;\n  std::vector<int> cutSourceEdges;\n  std::vector<std::uint64_t> cutSourceTopology;\n};\n\nstruct SurfaceCellStageLineage {\n""",
)
replace_once(
    "include/directional/diagnostics/RemeshDiagnostics.h",
    """  std::string surfaceCellAuthoritativeProducerDisposition;\n  bool surfaceCellPeriodicHolonomyAvailable = false;\n""",
    """  std::string surfaceCellAuthoritativeProducerDisposition;\n  std::vector<SurfaceCellPeriodicHolonomyDiagnostics>\n      surfaceCellPeriodicHolonomies;\n  bool surfaceCellPeriodicHolonomyAvailable = false;\n""",
)

# Canonical relation identity and deterministic insertion live beside the existing branch normalization authority.
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """int normalized_branch(const int branch) {\n  return ((branch % 4) + 4) % 4;\n}\n\n} // namespace directional::geometry::surface_cell_tracing_detail\n""",
    r'''int normalized_branch(const int branch) {
  return ((branch % 4) + 4) % 4;
}

namespace {

std::vector<std::uint64_t> canonical_cycle_topology(
    const std::vector<std::uint64_t> &values) {
  if (values.empty()) return {};
  std::vector<std::uint64_t> best;
  const auto consider = [&](const std::vector<std::uint64_t> &candidate,
                            std::vector<std::uint64_t> &currentBest) {
    for (std::size_t offset = 0; offset < candidate.size(); ++offset) {
      std::vector<std::uint64_t> rotated;
      rotated.reserve(candidate.size());
      for (std::size_t i = 0; i < candidate.size(); ++i) {
        rotated.push_back(candidate[(offset + i) % candidate.size()]);
      }
      if (currentBest.empty() || rotated < currentBest) {
        currentBest = std::move(rotated);
      }
    }
  };
  consider(values, best);
  std::vector<std::uint64_t> reversed(values.rbegin(), values.rend());
  consider(reversed, best);
  return best;
}

std::vector<std::uint64_t> canonical_path_topology(
    const std::vector<std::uint64_t> &values) {
  std::vector<std::uint64_t> reversed(values.rbegin(), values.rend());
  return reversed < values ? reversed : values;
}

Eigen::Vector2i rotate_lattice_quarter_turn(const Eigen::Vector2i &value,
                                             const int quarterTurns) {
  switch (normalized_branch(quarterTurns)) {
  case 0: return value;
  case 1: return Eigen::Vector2i(-value.y(), value.x());
  case 2: return Eigen::Vector2i(-value.x(), -value.y());
  case 3: return Eigen::Vector2i(value.y(), -value.x());
  }
  return value;
}

int translation_orientation_rank(const Eigen::Vector2i &translation) {
  if (translation.x() != 0) return translation.x() > 0 ? 0 : 1;
  if (translation.y() != 0) return translation.y() > 0 ? 0 : 1;
  return 2;
}

auto periodic_relation_key(const SurfacePeriodicHolonomy &relation) {
  return std::tuple{
      relation.sourceComponent,
      relation.sourceSheet,
      relation.quarterTurnRotation,
      relation.latticeTranslation.x(),
      relation.latticeTranslation.y(),
      relation.sourceRouteTopology,
      relation.cutSourceTopology};
}

bool periodic_relation_shape_valid(const SurfacePeriodicHolonomy &relation) {
  return relation.sourceComponent >= 0 && relation.sourceSheet >= 0 &&
         relation.latticeTranslation != Eigen::Vector2i::Zero() &&
         !relation.sourceRouteEdges.empty() &&
         relation.sourceRouteEdges.size() == relation.sourceRouteTopology.size() &&
         !relation.cutSourceEdges.empty() &&
         relation.cutSourceEdges.size() == relation.cutSourceTopology.size();
}

} // namespace

SurfacePeriodicHolonomy canonicalize_periodic_holonomy(
    SurfacePeriodicHolonomy relation) {
  relation.quarterTurnRotation = normalized_branch(relation.quarterTurnRotation);
  relation.sourceRouteTopology =
      canonical_cycle_topology(relation.sourceRouteTopology);
  relation.cutSourceTopology = canonical_path_topology(relation.cutSourceTopology);

  SurfacePeriodicHolonomy inverse = relation;
  inverse.quarterTurnRotation = normalized_branch(-relation.quarterTurnRotation);
  inverse.latticeTranslation = -rotate_lattice_quarter_turn(
      relation.latticeTranslation, inverse.quarterTurnRotation);

  const auto action_key = [](const SurfacePeriodicHolonomy &candidate) {
    return std::tuple{translation_orientation_rank(candidate.latticeTranslation),
                      candidate.quarterTurnRotation,
                      std::abs(candidate.latticeTranslation.x()),
                      std::abs(candidate.latticeTranslation.y()),
                      candidate.latticeTranslation.x(),
                      candidate.latticeTranslation.y()};
  };
  if (action_key(inverse) < action_key(relation)) {
    relation.quarterTurnRotation = inverse.quarterTurnRotation;
    relation.latticeTranslation = inverse.latticeTranslation;
  }
  return relation;
}

SurfacePeriodicHolonomyInsertStatus insert_periodic_holonomy(
    std::vector<SurfacePeriodicHolonomy> &relations,
    SurfacePeriodicHolonomy relation) {
  relation = canonicalize_periodic_holonomy(std::move(relation));
  if (!periodic_relation_shape_valid(relation)) {
    return SurfacePeriodicHolonomyInsertStatus::Incompatible;
  }

  for (const SurfacePeriodicHolonomy &existing : relations) {
    if (periodic_relation_key(existing) == periodic_relation_key(relation)) {
      return SurfacePeriodicHolonomyInsertStatus::Equivalent;
    }
    if (existing.sourceComponent != relation.sourceComponent ||
        existing.sourceSheet != relation.sourceSheet) {
      continue;
    }
    if (existing.sourceRouteTopology == relation.sourceRouteTopology ||
        existing.cutSourceTopology == relation.cutSourceTopology) {
      return SurfacePeriodicHolonomyInsertStatus::Incompatible;
    }

    // This G4 slice intentionally does not guess a basis inside one source
    // sheet. Distinct same-sheet cycles require a later topology-basis solver;
    // retaining one by discovery order would be unsound. Multiple relations
    // on distinct authoritative sheets/components remain valid and are kept.
    return SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis;
  }

  relations.push_back(std::move(relation));
  std::sort(relations.begin(), relations.end(),
            [](const SurfacePeriodicHolonomy &a,
               const SurfacePeriodicHolonomy &b) {
              return periodic_relation_key(a) < periodic_relation_key(b);
            });
  return SurfacePeriodicHolonomyInsertStatus::Inserted;
}

} // namespace directional::geometry::surface_cell_tracing_detail
''',
)

# Add stable topology keys while deriving the exact reciprocal source route.
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """  int totalMatching = 0;\n  std::vector<int> holonomyRoute;\n  for (std::size_t index = 0; index < faceCycle.size(); ++index) {\n""",
    """  int totalMatching = 0;\n  std::vector<int> holonomyRoute;\n  std::vector<std::uint64_t> holonomyRouteTopology;\n  for (std::size_t index = 0; index < faceCycle.size(); ++index) {\n""",
)
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """    holonomyRoute.push_back(sourceEdge);\n    if (hasTransitions) {\n""",
    """    holonomyRoute.push_back(sourceEdge);\n    holonomyRouteTopology.push_back(sharedKey);\n    if (hasTransitions) {\n""",
)
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """  result.disposition = SurfaceCellProducerDisposition::Rejected;\n  result.periodicHolonomy.enabled = true;\n  result.periodicHolonomy.quarterTurnRotation = 0;\n  result.periodicHolonomy.latticeTranslation = {result.gridU, 0};\n  result.periodicHolonomy.sourceRouteEdges = std::move(holonomyRoute);\n  const int component = face_label_or_default(options.sourceFaceComponents,\n                                               activeFaces.front(), 0);\n  const int sheet = face_label_or_default(options.sourceFaceSheets,\n                                           activeFaces.front(), component);\n  result.periodicHolonomy.sourceComponent = component;\n  result.periodicHolonomy.sourceSheet = sheet;\n""",
    """  result.disposition = SurfaceCellProducerDisposition::Rejected;\n  result.periodicHolonomies.emplace_back();\n  SurfacePeriodicHolonomy &periodicHolonomy = result.periodicHolonomies.back();\n  periodicHolonomy.quarterTurnRotation = 0;\n  periodicHolonomy.latticeTranslation = {result.gridU, 0};\n  periodicHolonomy.sourceRouteEdges = std::move(holonomyRoute);\n  periodicHolonomy.sourceRouteTopology = std::move(holonomyRouteTopology);\n  const int component = face_label_or_default(options.sourceFaceComponents,\n                                               activeFaces.front(), 0);\n  const int sheet = face_label_or_default(options.sourceFaceSheets,\n                                           activeFaces.front(), component);\n  periodicHolonomy.sourceComponent = component;\n  periodicHolonomy.sourceSheet = sheet;\n""",
)
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """    result.periodicHolonomy.cutSourceEdges.push_back(sourceEdge);\n  }\n\n  const double stepV = height / static_cast<double>(result.gridV);\n""",
    """    periodicHolonomy.cutSourceEdges.push_back(sourceEdge);\n    periodicHolonomy.cutSourceTopology.push_back(key);\n  }\n  periodicHolonomy =\n      surface_cell_tracing_detail::canonicalize_periodic_holonomy(\n          std::move(periodicHolonomy));\n\n  const double stepV = height / static_cast<double>(result.gridV);\n""",
)

# Aggregation: retain multiple compatible sheet relations, dedupe equivalents,
# and fail closed rather than choosing an ambiguous/conflicting same-sheet basis.
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """    if (local.periodicHolonomy.enabled) {\n      if (result.periodicHolonomy.enabled) {\n        result.disposition = SurfaceCellProducerDisposition::Rejected;\n        set_phase_front_failure(result.failure,\n                                SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);\n        return result;\n      }\n      result.periodicHolonomy = local.periodicHolonomy;\n    }\n""",
    """    for (SurfacePeriodicHolonomy relation : local.periodicHolonomies) {\n      const auto insertion =\n          surface_cell_tracing_detail::insert_periodic_holonomy(\n              result.periodicHolonomies, std::move(relation));\n      if (insertion == SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis) {\n        result.disposition = SurfaceCellProducerDisposition::Rejected;\n        set_phase_front_failure(\n            result.failure,\n            SurfacePhaseFrontFailureReason::AmbiguousPeriodicRelationBasis);\n        return result;\n      }\n      if (insertion == SurfacePeriodicHolonomyInsertStatus::Incompatible) {\n        result.disposition = SurfaceCellProducerDisposition::Rejected;\n        set_phase_front_failure(\n            result.failure,\n            SurfacePhaseFrontFailureReason::IncompatiblePeriodicRelation);\n        return result;\n      }\n    }\n""",
)
replace_once(
    "src/geometry/SurfaceCellTracing.cpp",
    """  case SurfacePhaseFrontFailureReason::AmbiguousPeriodicRingCorrespondence: return \"AmbiguousPeriodicRingCorrespondence\";\n  }\n""",
    """  case SurfacePhaseFrontFailureReason::AmbiguousPeriodicRingCorrespondence: return \"AmbiguousPeriodicRingCorrespondence\";\n  case SurfacePhaseFrontFailureReason::AmbiguousPeriodicRelationBasis: return \"AmbiguousPeriodicRelationBasis\";\n  case SurfacePhaseFrontFailureReason::IncompatiblePeriodicRelation: return \"IncompatiblePeriodicRelation\";\n  }\n""",
)

# Structural hashing includes the whole canonical collection and uses stable
# source-topology keys rather than transient source-edge numbering.
regex_once(
    "src/pipeline/RemeshPipeline.cpp",
    r"  hash_combine_i64\(seed, network\.phaseFront\.periodicHolonomy\.enabled \? 1 : 0\);\n"
    r"  hash_combine_i64\(seed, network\.phaseFront\.periodicHolonomy\.sourceComponent\);\n"
    r"  hash_combine_i64\(seed, network\.phaseFront\.periodicHolonomy\.sourceSheet\);\n"
    r"  hash_combine_i64\(seed, network\.phaseFront\.periodicHolonomy\.quarterTurnRotation\);\n"
    r"  hash_combine_i64\(seed, network\.phaseFront\.periodicHolonomy\.latticeTranslation\.x\(\)\);\n"
    r"  hash_combine_i64\(seed, network\.phaseFront\.periodicHolonomy\.latticeTranslation\.y\(\)\);\n"
    r"  hash_vector\(seed, network\.phaseFront\.periodicHolonomy\.sourceRouteEdges\);\n"
    r"  hash_vector\(seed, network\.phaseFront\.periodicHolonomy\.cutSourceEdges\);\n",
    """  hash_combine_u64(seed, network.phaseFront.periodicHolonomies.size());\n  for (const auto &relation : network.phaseFront.periodicHolonomies) {\n    hash_combine_i64(seed, relation.sourceComponent);\n    hash_combine_i64(seed, relation.sourceSheet);\n    hash_combine_i64(seed, relation.quarterTurnRotation);\n    hash_combine_i64(seed, relation.latticeTranslation.x());\n    hash_combine_i64(seed, relation.latticeTranslation.y());\n    hash_vector(seed, relation.sourceRouteTopology);\n    hash_vector(seed, relation.cutSourceTopology);\n  }\n""",
)

# Exact materialization looks up the relation belonging to the current source
# sheet. Multiple authoritative sheets therefore no longer alias through one
# scalar relation; unsupported same-sheet actions still fail closed.
regex_once(
    "src/pipeline/RemeshPipeline.cpp",
    r"  const auto canonical_lattice = \[&\]\(const int component, const int sheet,\n"
    r"                                     Eigen::Vector2i lattice\) \{.*?"
    r"    return lattice;\n  \};",
    """  const auto canonical_lattice = [&](const int component, const int sheet,\n                                     Eigen::Vector2i lattice) {\n    for (const auto &relation : phaseFront.periodicHolonomies) {\n      if (relation.sourceComponent != component ||\n          relation.sourceSheet != sheet) {\n        continue;\n      }\n      const Eigen::Vector2i translation = relation.latticeTranslation;\n      if (relation.quarterTurnRotation != 0 || translation.x() <= 0 ||\n          translation.y() != 0) {\n        return Eigen::Vector2i{-1, -1};\n      }\n      if (lattice.x() == translation.x()) lattice.x() = 0;\n    }\n    return lattice;\n  };""",
)
replace_once(
    "src/pipeline/RemeshPipeline.cpp",
    """      grid.periodicU =\n          phaseFront.periodicHolonomy.enabled &&\n          phaseFront.periodicHolonomy.sourceComponent == cell.sourceComponent &&\n          phaseFront.periodicHolonomy.sourceSheet == cell.sourceSheet;\n""",
    """      grid.periodicU = std::any_of(\n          phaseFront.periodicHolonomies.begin(),\n          phaseFront.periodicHolonomies.end(), [&](const auto &relation) {\n            return relation.sourceComponent == cell.sourceComponent &&\n                   relation.sourceSheet == cell.sourceSheet &&\n                   relation.quarterTurnRotation == 0 &&\n                   relation.latticeTranslation.x() > 0 &&\n                   relation.latticeTranslation.y() == 0;\n          });\n""",
)

# Copy and merge collection diagnostics anywhere scalar compatibility fields are copied.
replace_once(
    "src/pipeline/RemeshPipeline.cpp",
    """  target.surfaceCellAuthoritativeProducerDisposition =\n      source.surfaceCellAuthoritativeProducerDisposition;\n  target.surfaceCellPeriodicHolonomyAvailable =\n      source.surfaceCellPeriodicHolonomyAvailable;\n""",
    """  target.surfaceCellAuthoritativeProducerDisposition =\n      source.surfaceCellAuthoritativeProducerDisposition;\n  target.surfaceCellPeriodicHolonomies = source.surfaceCellPeriodicHolonomies;\n  target.surfaceCellPeriodicHolonomyAvailable =\n      source.surfaceCellPeriodicHolonomyAvailable;\n""",
)
replace_once(
    "src/pipeline/RemeshPipeline.cpp",
    """  if (source.surfaceCellPeriodicHolonomyAvailable) {\n    target.surfaceCellPeriodicHolonomyAvailable = true;\n""",
    """  if (source.surfaceCellPeriodicHolonomyAvailable) {\n    target.surfaceCellPeriodicHolonomies.insert(\n        target.surfaceCellPeriodicHolonomies.end(),\n        source.surfaceCellPeriodicHolonomies.begin(),\n        source.surfaceCellPeriodicHolonomies.end());\n    target.surfaceCellPeriodicHolonomyAvailable = true;\n""",
)

# Producer diagnostics expose every canonical relation and retain legacy scalar
# fields only as a derived view of the first canonical entry.
regex_once(
    "src/pipeline/RemeshPipeline.cpp",
    r"    result\.diagnostics\.surfaceCellPeriodicHolonomyAvailable =\n"
    r"        traceNetwork\.phaseFront\.periodicHolonomy\.enabled;\n"
    r"    result\.diagnostics\.surfaceCellPeriodicHolonomyQuarterTurnRotation =\n"
    r"        traceNetwork\.phaseFront\.periodicHolonomy\.quarterTurnRotation;\n"
    r"    result\.diagnostics\.surfaceCellPeriodicHolonomyTranslationU =\n"
    r"        traceNetwork\.phaseFront\.periodicHolonomy\.latticeTranslation\.x\(\);\n"
    r"    result\.diagnostics\.surfaceCellPeriodicHolonomyTranslationV =\n"
    r"        traceNetwork\.phaseFront\.periodicHolonomy\.latticeTranslation\.y\(\);\n"
    r"    result\.diagnostics\.surfaceCellPeriodicHolonomyRouteEdgeCount =\n"
    r"        traceNetwork\.phaseFront\.periodicHolonomy\.sourceRouteEdges\.size\(\);\n"
    r"    result\.diagnostics\.surfaceCellPeriodicCutEdgeCount =\n"
    r"        traceNetwork\.phaseFront\.periodicHolonomy\.cutSourceEdges\.size\(\);",
    """    result.diagnostics.surfaceCellPeriodicHolonomies.clear();\n    for (const auto &relation : traceNetwork.phaseFront.periodicHolonomies) {\n      SurfaceCellPeriodicHolonomyDiagnostics diagnostic;\n      diagnostic.sourceComponent = relation.sourceComponent;\n      diagnostic.sourceSheet = relation.sourceSheet;\n      diagnostic.quarterTurnRotation = relation.quarterTurnRotation;\n      diagnostic.translationU = relation.latticeTranslation.x();\n      diagnostic.translationV = relation.latticeTranslation.y();\n      diagnostic.sourceRouteEdges = relation.sourceRouteEdges;\n      diagnostic.sourceRouteTopology = relation.sourceRouteTopology;\n      diagnostic.cutSourceEdges = relation.cutSourceEdges;\n      diagnostic.cutSourceTopology = relation.cutSourceTopology;\n      result.diagnostics.surfaceCellPeriodicHolonomies.push_back(\n          std::move(diagnostic));\n    }\n    result.diagnostics.surfaceCellPeriodicHolonomyAvailable =\n        !traceNetwork.phaseFront.periodicHolonomies.empty();\n    if (!traceNetwork.phaseFront.periodicHolonomies.empty()) {\n      const auto &primary = traceNetwork.phaseFront.periodicHolonomies.front();\n      result.diagnostics.surfaceCellPeriodicHolonomyQuarterTurnRotation =\n          primary.quarterTurnRotation;\n      result.diagnostics.surfaceCellPeriodicHolonomyTranslationU =\n          primary.latticeTranslation.x();\n      result.diagnostics.surfaceCellPeriodicHolonomyTranslationV =\n          primary.latticeTranslation.y();\n      result.diagnostics.surfaceCellPeriodicHolonomyRouteEdgeCount =\n          primary.sourceRouteEdges.size();\n      result.diagnostics.surfaceCellPeriodicCutEdgeCount =\n          primary.cutSourceEdges.size();\n    }""",
)

# Benchmark JSON surfaces collection cardinality for the following artifact-only turn.
replace_once(
    "src/bench/DirectionalBenchmark.cpp",
    """      << \"\\\"surfaceCellPeriodicHolonomyAvailable\\\":\"\n      << (diagnostics.surfaceCellPeriodicHolonomyAvailable ? \"true\" : \"false\") << \",\"\n""",
    """      << \"\\\"surfaceCellPeriodicHolonomyRelationCount\\\":\"\n      << diagnostics.surfaceCellPeriodicHolonomies.size() << \",\"\n      << \"\\\"surfaceCellPeriodicHolonomyAvailable\\\":\"\n      << (diagnostics.surfaceCellPeriodicHolonomyAvailable ? \"true\" : \"false\") << \",\"\n""",
)

# Update G3 annulus assertions to the collection authority.
for old, new in [
    ("network.phaseFront.periodicHolonomy.enabled", "!network.phaseFront.periodicHolonomies.empty()"),
    ("network.phaseFront.periodicHolonomy.quarterTurnRotation", "network.phaseFront.periodicHolonomies.front().quarterTurnRotation"),
    ("network.phaseFront.periodicHolonomy.latticeTranslation", "network.phaseFront.periodicHolonomies.front().latticeTranslation"),
    ("network.phaseFront.periodicHolonomy.sourceRouteEdges", "network.phaseFront.periodicHolonomies.front().sourceRouteEdges"),
    ("network.phaseFront.periodicHolonomy.cutSourceEdges", "network.phaseFront.periodicHolonomies.front().cutSourceEdges"),
    ("forward.phaseFront.periodicHolonomy.sourceRouteEdges", "forward.phaseFront.periodicHolonomies.front().sourceRouteEdges"),
    ("reverse.phaseFront.periodicHolonomy.sourceRouteEdges", "reverse.phaseFront.periodicHolonomies.front().sourceRouteEdges"),
    ("forward.phaseFront.periodicHolonomy.cutSourceEdges", "forward.phaseFront.periodicHolonomies.front().cutSourceEdges"),
    ("reverse.phaseFront.periodicHolonomy.cutSourceEdges", "reverse.phaseFront.periodicHolonomies.front().cutSourceEdges"),
    ("valid.phaseFront.periodicHolonomy.sourceRouteEdges", "valid.phaseFront.periodicHolonomies.front().sourceRouteEdges"),
]:
    p = Path("tests/SurfaceCellsPhase10Tests.cpp")
    text = p.read_text()
    if old in text:
        p.write_text(text.replace(old, new))

# Tighten annulus tests so scalar-to-vector migration cannot silently create extras.
p = Path("tests/SurfaceCellsPhase10Tests.cpp")
text = p.read_text()
anchor = """  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,\n            network.phaseFront.disposition);\n  EXPECT_TRUE(!network.phaseFront.periodicHolonomies.empty());\n"""
if anchor in text:
    text = text.replace(anchor, anchor + "  ASSERT_EQ(1U, network.phaseFront.periodicHolonomies.size());\n", 1)
p.write_text(text)

# Add focused semantic tests for canonical equivalence, ambiguity, conflict,
# and the real committed torus producer boundary. They are compiled only now.
insert_anchor = """TEST(SurfaceCellsPhase10,\n     PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason) {\n"""
new_tests = r'''TEST(SurfaceCellsPhase10,
     PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  SurfacePeriodicHolonomy forward;
  forward.sourceComponent = 2;
  forward.sourceSheet = 7;
  forward.quarterTurnRotation = 0;
  forward.latticeTranslation = Eigen::Vector2i(8, 0);
  forward.sourceRouteEdges = {4, 6, 8, 10};
  forward.sourceRouteTopology = {40, 60, 80, 100};
  forward.cutSourceEdges = {12, 14};
  forward.cutSourceTopology = {120, 140};

  SurfacePeriodicHolonomy reverse = forward;
  reverse.latticeTranslation = Eigen::Vector2i(-8, 0);
  std::reverse(reverse.sourceRouteEdges.begin(), reverse.sourceRouteEdges.end());
  std::reverse(reverse.sourceRouteTopology.begin(), reverse.sourceRouteTopology.end());
  std::reverse(reverse.cutSourceEdges.begin(), reverse.cutSourceEdges.end());
  std::reverse(reverse.cutSourceTopology.begin(), reverse.cutSourceTopology.end());

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, forward));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Equivalent,
            insert_periodic_holonomy(relations, reverse));
  ASSERT_EQ(1U, relations.size());
  EXPECT_EQ(Eigen::Vector2i(8, 0), relations.front().latticeTranslation);
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyDistinctAuthoritativeSheetsRetainEveryRelation) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  const auto makeRelation = [](const int sheet, const std::uint64_t routeKey,
                               const std::uint64_t cutKey) {
    SurfacePeriodicHolonomy relation;
    relation.sourceComponent = 0;
    relation.sourceSheet = sheet;
    relation.latticeTranslation = Eigen::Vector2i(6, 0);
    relation.sourceRouteEdges = {sheet * 10 + 1};
    relation.sourceRouteTopology = {routeKey};
    relation.cutSourceEdges = {sheet * 10 + 2};
    relation.cutSourceTopology = {cutKey};
    return relation;
  };

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, makeRelation(3, 300, 301)));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, makeRelation(1, 100, 101)));
  ASSERT_EQ(2U, relations.size());
  EXPECT_EQ(1, relations[0].sourceSheet);
  EXPECT_EQ(3, relations[1].sourceSheet);
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomySameSheetDependentBasisFailsClosedWithoutOrderChoice) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  const auto makeRelation = [](const int edge, const std::uint64_t topology) {
    SurfacePeriodicHolonomy relation;
    relation.sourceComponent = 0;
    relation.sourceSheet = 0;
    relation.latticeTranslation = Eigen::Vector2i(4, 0);
    relation.sourceRouteEdges = {edge};
    relation.sourceRouteTopology = {topology};
    relation.cutSourceEdges = {edge + 1};
    relation.cutSourceTopology = {topology + 1};
    return relation;
  };

  for (const bool reversed : {false, true}) {
    std::vector<SurfacePeriodicHolonomy> relations;
    auto first = makeRelation(1, 10);
    auto second = makeRelation(3, 30);
    if (reversed) std::swap(first, second);
    EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
              insert_periodic_holonomy(relations, first));
    EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis,
              insert_periodic_holonomy(relations, second));
    ASSERT_EQ(1U, relations.size());
  }
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyConflictingTransportFailsClosed) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  SurfacePeriodicHolonomy first;
  first.sourceComponent = 0;
  first.sourceSheet = 0;
  first.latticeTranslation = Eigen::Vector2i(4, 0);
  first.sourceRouteEdges = {1, 2};
  first.sourceRouteTopology = {10, 20};
  first.cutSourceEdges = {3};
  first.cutSourceTopology = {30};
  SurfacePeriodicHolonomy conflicting = first;
  conflicting.quarterTurnRotation = 1;
  conflicting.latticeTranslation = Eigen::Vector2i(0, 4);

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, first));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Incompatible,
            insert_periodic_holonomy(relations, conflicting));
}

TEST(SurfaceCellsPhase10,
     ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());

  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.preserveDebugArtifacts = true;
  options.surfaceCells.retainIntermediateGeometry = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.V, mesh.F, rawField, options);
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &phaseFront = result.surfaceCellContext.traceNetwork.phaseFront;
  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::InvalidPeriodicTopology,
            phaseFront.failure.reason);
  if (phaseFront.disposition ==
      directional::geometry::SurfaceCellProducerDisposition::Produced) {
    EXPECT_GT(phaseFront.periodicHolonomies.size(), 1U);
    EXPECT_EQ(phaseFront.periodicHolonomies.size(),
              result.diagnostics.surfaceCellPeriodicHolonomies.size());
  }
}

'''
text = Path("tests/SurfaceCellsPhase10Tests.cpp").read_text()
if text.count(insert_anchor) != 1:
    raise RuntimeError("failed to locate periodic malformed-holonomy insertion anchor")
Path("tests/SurfaceCellsPhase10Tests.cpp").write_text(
    text.replace(insert_anchor, new_tests + insert_anchor, 1))

# The exact cylinder producer-boundary compatibility test now reads from the collection.
p = Path("tests/SurfaceCellsPhase10Tests.cpp")
text = p.read_text().replace(
    "EXPECT_TRUE(network.phaseFront.periodicHolonomy.enabled);",
    "EXPECT_FALSE(network.phaseFront.periodicHolonomies.empty());")
p.write_text(text)

# Compile guard: no consumer may still treat the result as one scalar relation.
for path in [
    "include/directional/geometry/SurfaceCellTracing.h",
    "src/geometry/SurfaceCellTracing.cpp",
    "src/pipeline/RemeshPipeline.cpp",
    "tests/SurfaceCellsPhase10Tests.cpp",
]:
    text = Path(path).read_text()
    if ".periodicHolonomy" in text:
        raise RuntimeError(f"{path}: stale scalar periodicHolonomy consumer remains")

print("G4 holonomy-basis transform applied")
