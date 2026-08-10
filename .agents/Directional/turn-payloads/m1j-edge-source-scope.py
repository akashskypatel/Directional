from pathlib import Path
import re


def replace_exact(text: str, old: str, new: str, label: str, count: int = 1) -> str:
    actual = text.count(old)
    if actual != count:
        raise SystemExit(f"{label}: expected {count} exact matches, found {actual}")
    return text.replace(old, new)


def insert_after_regex(text: str, pattern: str, addition: str, label: str) -> str:
    matches = list(re.finditer(pattern, text, flags=re.S))
    if len(matches) != 1:
        raise SystemExit(f"{label}: expected one regex match, found {len(matches)}")
    match = matches[0]
    return text[:match.end()] + addition + text[match.end():]


# 1. Type the selected SurfaceFrontEdge source-scope domains only.
header_path = Path("include/directional/geometry/SurfaceCellTracing.h")
header = header_path.read_text()
header = replace_exact(
    header,
    "  int sourceComponent = -1;\n  int sourceTopologyRegion = -1;\n  int sourceSheet = -1;\n  std::vector<int> sourceIsolationSheets;",
    "  /// Authoritative connected source component owning this front side.\n"
    "  std::optional<authority::SourceComponentId> sourceComponent;\n"
    "  int sourceTopologyRegion = -1;\n"
    "  /// Single-sheet authority; empty for legitimate multi-sheet front sides.\n"
    "  std::optional<authority::IsolationSheetId> sourceSheet;\n"
    "  /// Complete sorted isolation-sheet authority inherited from the owning cell.\n"
    "  std::vector<authority::IsolationSheetId> sourceIsolationSheets;",
    "SurfaceFrontEdge typed fields",
)
header_path.write_text(header)


# 2. Preserve typed cell authority through edge publication and validate rather than rewrite it.
tracing_path = Path("src/geometry/SurfaceCellTracing.cpp")
tracing = tracing_path.read_text()
edge_compat_helpers = r'''

int legacy_phase_front_source_component(const SurfaceFrontEdge &edge) {
  return edge.sourceComponent.has_value()
             ? static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
                   edge.sourceComponent.value()))
             : -1;
}

int legacy_phase_front_source_sheet(const SurfaceFrontEdge &edge) {
  return edge.sourceSheet.has_value()
             ? static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
                   edge.sourceSheet.value()))
             : -1;
}

std::vector<int> legacy_phase_front_isolation_sheets(
    const SurfaceFrontEdge &edge) {
  std::vector<int> legacy;
  legacy.reserve(edge.sourceIsolationSheets.size());
  for (const authority::IsolationSheetId sheet : edge.sourceIsolationSheets) {
    legacy.push_back(static_cast<int>(
        authority::LegacyAuthorityAdapters::to_legacy_index(sheet)));
  }
  return legacy;
}
'''
tracing = insert_after_regex(
    tracing,
    r"std::vector<int> legacy_phase_front_isolation_sheets\(\s*const SurfacePhaseFrontCell &cell\) \{.*?\n\}",
    edge_compat_helpers,
    "tracing edge compatibility helpers",
)

old_publication = (
    "        edge.sourceComponent = legacy_phase_front_source_component(cell);\n"
    "        edge.sourceSheet = legacy_phase_front_source_sheet(cell);\n"
    "        edge.sourceIsolationSheets = legacy_phase_front_isolation_sheets(cell);"
)
new_publication = (
    "        edge.sourceComponent = cell.sourceComponent;\n"
    "        edge.sourceSheet = cell.sourceSheet;\n"
    "        edge.sourceIsolationSheets = cell.sourceIsolationSheets;"
)
tracing = replace_exact(
    tracing, old_publication, new_publication, "typed edge publication", count=3
)

old_edge_normalization = r'''    for (auto &edge : local.edges) {
      edge.sourceTopologyRegion = region.id;
      edge.sourceComponent = region.sourceComponent;
      if (!normalize_sheets(edge.sourceIsolationSheets)) return false;
      edge.sourceSheet = edge.sourceIsolationSheets.size() == 1U
                             ? edge.sourceIsolationSheets.front()
                             : singleIsolationSheet;
    }
'''
new_edge_validation = r'''    const std::size_t componentExtent =
        source_label_authority_extent(options.sourceFaceComponents);
    const std::size_t sheetExtent =
        source_label_authority_extent(options.sourceFaceSheets);
    const auto typedRegionComponent =
        authority::LegacyAuthorityAdapters::source_component(
            region.sourceComponent, componentExtent);
    if (!typedRegionComponent) return false;
    std::vector<authority::IsolationSheetId> typedRegionSheets;
    typedRegionSheets.reserve(region.isolationSheets.size());
    for (const int rawSheet : region.isolationSheets) {
      const auto typedSheet = authority::LegacyAuthorityAdapters::isolation_sheet(
          rawSheet, sheetExtent);
      if (!typedSheet) return false;
      typedRegionSheets.push_back(typedSheet.value());
    }
    if (typedRegionSheets.empty() ||
        !std::is_sorted(typedRegionSheets.begin(), typedRegionSheets.end()) ||
        std::adjacent_find(typedRegionSheets.begin(), typedRegionSheets.end()) !=
            typedRegionSheets.end()) {
      return false;
    }
    for (auto &edge : local.edges) {
      edge.sourceTopologyRegion = region.id;
      const auto owner = std::find_if(
          local.cells.begin(), local.cells.end(),
          [&](const SurfacePhaseFrontCell &cell) {
            return cell.id == edge.filledCell;
          });
      if (owner == local.cells.end() || !edge.sourceComponent.has_value() ||
          edge.sourceComponent.value() != typedRegionComponent.value() ||
          edge.sourceComponent != owner->sourceComponent ||
          edge.sourceSheet != owner->sourceSheet ||
          edge.sourceIsolationSheets != owner->sourceIsolationSheets ||
          edge.sourceIsolationSheets.empty() ||
          !std::is_sorted(edge.sourceIsolationSheets.begin(),
                          edge.sourceIsolationSheets.end()) ||
          std::adjacent_find(edge.sourceIsolationSheets.begin(),
                             edge.sourceIsolationSheets.end()) !=
              edge.sourceIsolationSheets.end()) {
        return false;
      }
      for (const authority::IsolationSheetId typedSheet :
           edge.sourceIsolationSheets) {
        if (!std::binary_search(typedRegionSheets.begin(),
                                typedRegionSheets.end(), typedSheet)) {
          return false;
        }
      }
      if (edge.sourceIsolationSheets.size() == 1U) {
        if (!edge.sourceSheet.has_value() ||
            edge.sourceSheet.value() != edge.sourceIsolationSheets.front()) {
          return false;
        }
      } else if (edge.sourceSheet.has_value()) {
        return false;
      }
    }
'''
tracing = replace_exact(
    tracing,
    old_edge_normalization,
    new_edge_validation,
    "region edge scope validation",
)

tracing = replace_exact(
    tracing,
    "    for (SurfaceFrontEdge &edge : local.edges) {\n"
    "      if (edge.sourceComponent != region.sourceComponent ||\n"
    "          edge.sourceTopologyRegion != region.id) {",
    "    for (SurfaceFrontEdge &edge : local.edges) {\n"
    "      const auto typedRegionComponent =\n"
    "          authority::LegacyAuthorityAdapters::source_component(\n"
    "              region.sourceComponent,\n"
    "              source_label_authority_extent(options.sourceFaceComponents));\n"
    "      if (!typedRegionComponent || !edge.sourceComponent.has_value() ||\n"
    "          edge.sourceComponent.value() != typedRegionComponent.value() ||\n"
    "          edge.sourceTopologyRegion != region.id) {",
    "aggregate typed edge component guard",
)

tracing = replace_exact(
    tracing,
    "    if (edge.oppositeEdge >= 0 || !edge.exterior || from.empty() || to.empty() ||\n"
    "        edge.sourceRouteTopology.empty()) {",
    "    if (edge.oppositeEdge >= 0 || !edge.exterior || from.empty() || to.empty() ||\n"
    "        !edge.sourceComponent.has_value() || edge.sourceRouteTopology.empty()) {",
    "hard-rail typed component presence",
)
tracing = replace_exact(
    tracing,
    "    hardRailGroups[{edge.sourceComponent, std::move(from), std::move(to),\n"
    "                    std::move(route)}]",
    "    hardRailGroups[{legacy_phase_front_source_component(edge), std::move(from),\n"
    "                    std::move(to), std::move(route)}]",
    "hard-rail legacy compatibility key",
)
tracing_path.write_text(tracing)


# 3. Convert typed edge scope only at the still-raw pipeline compatibility boundary.
pipeline_path = Path("src/pipeline/RemeshPipeline.cpp")
pipeline = pipeline_path.read_text()
pipeline_edge_helpers = r'''

int legacy_phase_front_source_component(
    const geometry::SurfaceFrontEdge &edge) {
  return edge.sourceComponent.has_value()
             ? static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
                   edge.sourceComponent.value()))
             : -1;
}

int legacy_phase_front_source_sheet(
    const geometry::SurfaceFrontEdge &edge) {
  return edge.sourceSheet.has_value()
             ? static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
                   edge.sourceSheet.value()))
             : -1;
}

std::vector<int> legacy_phase_front_isolation_sheets(
    const geometry::SurfaceFrontEdge &edge) {
  std::vector<int> legacy;
  legacy.reserve(edge.sourceIsolationSheets.size());
  for (const authority::IsolationSheetId sheet : edge.sourceIsolationSheets) {
    legacy.push_back(static_cast<int>(
        authority::LegacyAuthorityAdapters::to_legacy_index(sheet)));
  }
  return legacy;
}
'''
pipeline = insert_after_regex(
    pipeline,
    r"std::vector<int> legacy_phase_front_isolation_sheets\(\s*const geometry::SurfacePhaseFrontCell &cell\) \{.*?\n\}",
    pipeline_edge_helpers,
    "pipeline edge compatibility helpers",
)
pipeline = replace_exact(
    pipeline,
    "    hash_combine_i64(seed, edge.sourceComponent);\n"
    "    hash_combine_i64(seed, edge.sourceTopologyRegion);\n"
    "    hash_combine_i64(seed, edge.sourceSheet);\n"
    "    hash_vector(seed, edge.sourceIsolationSheets);",
    "    hash_combine_i64(seed, legacy_phase_front_source_component(edge));\n"
    "    hash_combine_i64(seed, edge.sourceTopologyRegion);\n"
    "    hash_combine_i64(seed, legacy_phase_front_source_sheet(edge));\n"
    "    hash_vector(seed, legacy_phase_front_isolation_sheets(edge));",
    "pipeline edge structural hash compatibility",
)
pipeline = replace_exact(
    pipeline,
    "        edge.sourceComponent != legacy_phase_front_source_component(owner) ||\n"
    "        edge.sourceTopologyRegion != owner.sourceTopologyRegion ||",
    "        edge.sourceComponent != owner.sourceComponent ||\n"
    "        edge.sourceTopologyRegion != owner.sourceTopologyRegion ||\n"
    "        edge.sourceSheet != owner.sourceSheet ||\n"
    "        edge.sourceIsolationSheets != owner.sourceIsolationSheets ||",
    "pipeline typed owner scope validation",
)
pipeline = replace_exact(
    pipeline,
    "        !isolation_sheets_connected(edge.sourceTopologyRegion,\n"
    "                                    edge.sourceIsolationSheets)) {",
    "        !isolation_sheets_connected(\n"
    "            edge.sourceTopologyRegion,\n"
    "            legacy_phase_front_isolation_sheets(edge))) {",
    "pipeline raw isolation connectivity boundary",
)
pipeline_path.write_text(pipeline)


# 4. Update the existing M1i compatibility assertion and add six M1j production-path contracts.
tests_path = Path("tests/SurfaceCellsPhase10Tests.cpp")
tests = tests_path.read_text()
test_edge_helpers = r'''

int legacy_phase_front_component(
    const directional::geometry::SurfaceFrontEdge &edge) {
  return edge.sourceComponent.has_value()
             ? static_cast<int>(directional::authority::LegacyAuthorityAdapters::
                                    to_legacy_index(edge.sourceComponent.value()))
             : -1;
}

int legacy_phase_front_sheet(
    const directional::geometry::SurfaceFrontEdge &edge) {
  return edge.sourceSheet.has_value()
             ? static_cast<int>(directional::authority::LegacyAuthorityAdapters::
                                    to_legacy_index(edge.sourceSheet.value()))
             : -1;
}

std::vector<int> legacy_phase_front_sheets(
    const directional::geometry::SurfaceFrontEdge &edge) {
  std::vector<int> legacy;
  legacy.reserve(edge.sourceIsolationSheets.size());
  for (const directional::authority::IsolationSheetId sheet :
       edge.sourceIsolationSheets) {
    legacy.push_back(static_cast<int>(
        directional::authority::LegacyAuthorityAdapters::to_legacy_index(sheet)));
  }
  return legacy;
}
'''
tests = insert_after_regex(
    tests,
    r"std::vector<int> legacy_phase_front_sheets\(\s*const directional::geometry::SurfacePhaseFrontCell &cell\) \{.*?\n\}",
    test_edge_helpers,
    "test edge compatibility helpers",
)
tests = replace_exact(
    tests,
    "    EXPECT_EQ(legacy_phase_front_component(*owner->second), edge.sourceComponent);\n"
    "    EXPECT_EQ(legacy_phase_front_sheet(*owner->second), edge.sourceSheet);\n"
    "    EXPECT_EQ(legacy_phase_front_sheets(*owner->second),\n"
    "              edge.sourceIsolationSheets);",
    "    EXPECT_EQ(owner->second->sourceComponent, edge.sourceComponent);\n"
    "    EXPECT_EQ(owner->second->sourceSheet, edge.sourceSheet);\n"
    "    EXPECT_EQ(owner->second->sourceIsolationSheets, edge.sourceIsolationSheets);\n"
    "    EXPECT_EQ(legacy_phase_front_component(*owner->second),\n"
    "              legacy_phase_front_component(edge));\n"
    "    EXPECT_EQ(legacy_phase_front_sheet(*owner->second),\n"
    "              legacy_phase_front_sheet(edge));\n"
    "    EXPECT_EQ(legacy_phase_front_sheets(*owner->second),\n"
    "              legacy_phase_front_sheets(edge));",
    "M1i typed-to-edge compatibility preservation",
)

m1j_tests = r'''

TEST(SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration,
     PlanarEdgesPublishCheckedDefaultComponentAndSheet) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  std::map<int, const directional::geometry::SurfacePhaseFrontCell *> cellsById;
  for (const auto &cell : network.phaseFront.cells) {
    ASSERT_TRUE(cellsById.emplace(cell.id, &cell).second);
  }
  ASSERT_FALSE(network.phaseFront.edges.empty());
  for (const auto &edge : network.phaseFront.edges) {
    const auto owner = cellsById.find(edge.filledCell);
    ASSERT_NE(cellsById.end(), owner);
    ASSERT_TRUE(edge.sourceComponent.has_value());
    ASSERT_TRUE(edge.sourceSheet.has_value());
    ASSERT_EQ(1U, edge.sourceIsolationSheets.size());
    EXPECT_EQ(owner->second->sourceComponent, edge.sourceComponent);
    EXPECT_EQ(owner->second->sourceSheet, edge.sourceSheet);
    EXPECT_EQ(owner->second->sourceIsolationSheets, edge.sourceIsolationSheets);
    EXPECT_EQ(0, legacy_phase_front_component(edge));
    EXPECT_EQ(0, legacy_phase_front_sheet(edge));
    EXPECT_EQ((std::vector<int>{0}), legacy_phase_front_sheets(edge));
  }
}

TEST(SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration,
     ExplicitSourceLabelsRemainDistinctTypedEdgeDomains) {
  static_assert(!std::is_same_v<directional::authority::SourceComponentId,
                                directional::authority::IsolationSheetId>);
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 2);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 2);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  ASSERT_FALSE(network.phaseFront.edges.empty());
  for (const auto &edge : network.phaseFront.edges) {
    ASSERT_TRUE(edge.sourceComponent.has_value());
    ASSERT_TRUE(edge.sourceSheet.has_value());
    EXPECT_EQ(2, legacy_phase_front_component(edge));
    EXPECT_EQ(2, legacy_phase_front_sheet(edge));
  }
  const auto wrongDomain = directional::authority::LegacyAuthorityAdapters::
      checked<directional::authority::IsolationSheetId>(
          directional::authority::AuthorityDomain::SourceComponent, 2, 3);
  ASSERT_FALSE(wrongDomain);
  EXPECT_EQ(directional::authority::DomainErrorCode::DomainMismatch,
            wrongDomain.error().code);
}

TEST(SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration,
     MultipleObservedSheetsDoNotInventRepresentativeEdgeSheet) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(faces.rows()));
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(4, 0.5);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};

  const auto network = directional::geometry::build_surface_cell_network(
      vertices, faces, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  std::map<int, const directional::geometry::SurfacePhaseFrontCell *> cellsById;
  for (const auto &cell : network.phaseFront.cells) {
    ASSERT_TRUE(cellsById.emplace(cell.id, &cell).second);
  }
  bool sawMultipleSheets = false;
  for (const auto &edge : network.phaseFront.edges) {
    if (edge.sourceIsolationSheets.size() <= 1U) continue;
    sawMultipleSheets = true;
    const auto owner = cellsById.find(edge.filledCell);
    ASSERT_NE(cellsById.end(), owner);
    ASSERT_TRUE(edge.sourceComponent.has_value());
    EXPECT_FALSE(edge.sourceSheet.has_value());
    EXPECT_EQ((std::vector<int>{0, 1}), legacy_phase_front_sheets(edge));
    EXPECT_EQ(owner->second->sourceComponent, edge.sourceComponent);
    EXPECT_EQ(owner->second->sourceSheet, edge.sourceSheet);
    EXPECT_EQ(owner->second->sourceIsolationSheets, edge.sourceIsolationSheets);
  }
  EXPECT_TRUE(sawMultipleSheets)
      << "the production fixture must retain multi-sheet authority on front edges";
}

TEST(SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration,
     MalformedOrMismatchedEdgeScopeFailsClosed) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);

  directional::geometry::SurfaceCellTracingOptions negative;
  negative.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  negative.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  negative.sourceFaceSheets.front() = -1;
  const auto rejectedNegative = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, negative);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            rejectedNegative.phaseFront.disposition);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::InvalidInput,
            rejectedNegative.phaseFront.failure.reason);
  EXPECT_TRUE(rejectedNegative.phaseFront.cells.empty());
  EXPECT_TRUE(rejectedNegative.phaseFront.edges.empty());

  directional::geometry::SurfaceCellTracingOptions missing;
  missing.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  missing.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows() - 1), 0);
  const auto rejectedMissing = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, missing);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            rejectedMissing.phaseFront.disposition);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::InvalidInput,
            rejectedMissing.phaseFront.failure.reason);
  EXPECT_TRUE(rejectedMissing.phaseFront.cells.empty());
  EXPECT_TRUE(rejectedMissing.phaseFront.edges.empty());
}

TEST(SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration,
     FaceRowPermutationPreservesTypedEdgeSourceScope) {
  Eigen::MatrixXd vertices(8, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0,
              0.0, 0.0, 2.0,
              1.0, 0.0, 2.0,
              1.0, 1.0, 2.0,
              0.0, 1.0, 2.0;
  Eigen::MatrixXi forwardFaces(4, 3);
  forwardFaces << 0, 1, 2,
                  0, 2, 3,
                  4, 5, 6,
                  4, 6, 7;
  Eigen::MatrixXi reverseFaces = forwardFaces.colwise().reverse().eval();
  directional::TriMesh forwardMesh;
  directional::TriMesh reverseMesh;
  forwardMesh.set_mesh(vertices, forwardFaces);
  reverseMesh.set_mesh(vertices, reverseFaces);
  const auto forwardField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          forwardMesh, constant_xy_raw_field(forwardFaces.rows()));
  const auto reverseField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reverseMesh, constant_xy_raw_field(reverseFaces.rows()));
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(8, 0.5);

  directional::geometry::SurfaceCellTracingOptions forwardOptions;
  forwardOptions.sourceFaceComponents = {3, 3, 7, 7};
  forwardOptions.sourceFaceSheets = {5, 5, 11, 11};
  directional::geometry::SurfaceCellTracingOptions reverseOptions;
  reverseOptions.sourceFaceComponents = {7, 7, 3, 3};
  reverseOptions.sourceFaceSheets = {11, 11, 5, 5};

  const auto forward = directional::geometry::build_surface_cell_network(
      vertices, forwardFaces, forwardField, targetSize, forwardOptions);
  const auto reverse = directional::geometry::build_surface_cell_network(
      vertices, reverseFaces, reverseField, targetSize, reverseOptions);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition);

  const auto semanticCounts = [](const auto &network) {
    std::map<std::pair<int, int>, int> counts;
    for (const auto &edge : network.phaseFront.edges) {
      ++counts[{legacy_phase_front_component(edge),
                legacy_phase_front_sheet(edge)}];
    }
    return counts;
  };
  const auto forwardCounts = semanticCounts(forward);
  const auto reverseCounts = semanticCounts(reverse);
  EXPECT_EQ(forwardCounts, reverseCounts);
  const auto firstScope = forwardCounts.find({3, 5});
  const auto secondScope = forwardCounts.find({7, 11});
  ASSERT_NE(firstScope, forwardCounts.end());
  ASSERT_NE(secondScope, forwardCounts.end());
  EXPECT_GT(firstScope->second, 0);
  EXPECT_GT(secondScope->second, 0);
  EXPECT_EQ(forward.phaseFront.edges.size(), reverse.phaseFront.edges.size());
}

TEST(SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration,
     TypedEdgeToLegacyPipelineBoundaryPreservesCompatibility) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 2);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 5);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  ASSERT_FALSE(network.phaseFront.edges.empty());
  for (const auto &edge : network.phaseFront.edges) {
    ASSERT_TRUE(edge.sourceComponent.has_value());
    ASSERT_TRUE(edge.sourceSheet.has_value());
    EXPECT_EQ(2, legacy_phase_front_component(edge));
    EXPECT_EQ(5, legacy_phase_front_sheet(edge));
    EXPECT_EQ((std::vector<int>{5}), legacy_phase_front_sheets(edge));
  }

  const std::uint64_t baselineHash = directional::pipeline::hash_trace_network(network);
  auto changed = network;
  const auto otherComponent =
      directional::authority::LegacyAuthorityAdapters::source_component(1, 3);
  ASSERT_TRUE(otherComponent);
  changed.phaseFront.edges.front().sourceComponent = otherComponent.value();
  EXPECT_NE(baselineHash, directional::pipeline::hash_trace_network(changed));
}
'''
if not tests.endswith("} // namespace\n"):
    raise SystemExit("tests: expected final anonymous-namespace terminator")
tests = tests[:-len("} // namespace\n")] + m1j_tests + "\n} // namespace\n"
tests_path.write_text(tests)

print("M1j edge source-scope payload applied")
