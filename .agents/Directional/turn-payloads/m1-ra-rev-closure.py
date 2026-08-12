from pathlib import Path


def replace_once(path: Path, old: str, new: str) -> None:
    text = path.read_text(encoding="utf-8")
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected exactly one match, found {count}")
    path.write_text(text.replace(old, new, 1), encoding="utf-8")


remesh = Path("src/pipeline/RemeshPipeline.cpp")
pure = Path("src/geometry/PureQuadCompletion.cpp")

replace_once(
    remesh,
    """    OccurrenceData(authority::OccurrenceId occurrenceId,\n                   geometry::SurfacePoint sourcePoint,\n                   authority::SourceSupport sourceSupport,\n                   geometry::SourceProjectionChart sourceChart,\n                   geometry::LocalLatticeState latticeState,\n                   authority::TopologyRegionId region, int cornerIndex)\n        : id(occurrenceId), point(std::move(sourcePoint)),\n          support(std::move(sourceSupport)), chart(std::move(sourceChart)),\n          lattice(std::move(latticeState)), topologyRegion(region),\n          corner(cornerIndex) {}\n""",
    """    OccurrenceData(authority::OccurrenceId occurrenceId,\n                   geometry::SurfacePoint sourcePoint,\n                   authority::SourceSupport sourceSupport,\n                   geometry::SourceProjectionChart sourceChart,\n                   geometry::LocalLatticeState latticeState,\n                   authority::TopologyRegionId region,\n                   authority::IsolationSheetId sheet, int cornerIndex)\n        : id(occurrenceId), point(std::move(sourcePoint)),\n          support(std::move(sourceSupport)), chart(std::move(sourceChart)),\n          lattice(std::move(latticeState)), topologyRegion(region),\n          isolationSheet(sheet), corner(cornerIndex) {}\n""",
)
replace_once(
    remesh,
    """    authority::TopologyRegionId topologyRegion;\n    int corner = -1;\n""",
    """    authority::TopologyRegionId topologyRegion;\n    authority::IsolationSheetId isolationSheet;\n    int corner = -1;\n""",
)
replace_once(
    remesh,
    """          geometry::SourceProjectionChart(lattice.sourceChart.value(), *faceId),\n          lattice, cell.sourceTopologyRegion, corner);\n""",
    """          geometry::SourceProjectionChart(lattice.sourceChart.value(), *faceId),\n          lattice, cell.sourceTopologyRegion, typedSheet, corner);\n""",
)
text = remesh.read_text(encoding="utf-8")
point_sheet_reads = text.count(".point.sheet")
if point_sheet_reads != 4:
    raise SystemExit(
        f"{remesh}: expected four reviewed occurrence point.sheet reads, found {point_sheet_reads}"
    )
text = text.replace(".point.sheet", ".isolationSheet")
remesh.write_text(text, encoding="utf-8")
replace_once(
    remesh,
    """      const auto occurrenceFaceId = source_face_id(occurrence.point.face);\n      if (!occurrenceFaceId.has_value()) {\n        result.failure = \"InvalidAuthoritativeIsolationSheet\";\n        return result;\n      }\n      const authority::IsolationSheetId sheet =\n          phaseFront.sourceTopologyRegions.sheet_for_row(*occurrenceFaceId);\n      domainStates.emplace_back(\n          occurrence.topologyRegion, sheet,\n""",
    """      domainStates.emplace_back(\n          occurrence.topologyRegion, occurrence.isolationSheet,\n""",
)
replace_once(
    remesh,
    """      const auto occurrenceFaceId = source_face_id(occurrence.point.face);\n      if (!occurrenceFaceId.has_value()) {\n        result.failure = \"InvalidAuthoritativeIsolationSheet\";\n        return result;\n      }\n      isolationSheets.insert(\n          phaseFront.sourceTopologyRegions.sheet_for_row(*occurrenceFaceId));\n""",
    """      isolationSheets.insert(occurrence.isolationSheet);\n""",
)

replace_once(
    pure,
    """PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow,\n    const bool sharedBoundary, const std::int64_t patchOwner) {\n  const int localVertex =\n      patch.vertices[static_cast<std::size_t>(localRow)];\n  const SurfacePoint &provenance =\n      patch.vertexProvenance[static_cast<std::size_t>(localRow)];\n  PureQuadStitchIdentity key =\n      patch.vertexLineage[static_cast<std::size_t>(localRow)].stitchIdentity;\n  if (!key.valid()) {\n    key.kind = sharedBoundary\n                   ? PureQuadStitchIdentityKind::ArrangementBoundaryNode\n                   : PureQuadStitchIdentityKind::GeneratedPatchInterior;\n    key.canonical.valid = true;\n    if (sharedBoundary) {\n      key.canonical.values = {localVertex, provenance.component,\n                              provenance.sheet};\n    } else {\n      key.canonical.values = {patchOwner, localVertex, provenance.component,\n                              provenance.sheet};\n    }\n  }\n  if (!sharedBoundary &&\n      key.kind != PureQuadStitchIdentityKind::GeneratedPatchInterior) {\n    key.kind = PureQuadStitchIdentityKind::GeneratedPatchInterior;\n    key.canonical.valid = true;\n    key.canonical.values = {patchOwner, localVertex, provenance.component,\n                            provenance.sheet};\n  }\n  return key;\n}\n""",
    """PureQuadStitchIdentity typed_lineage_stitch_identity(\n    const PureQuadVertexLineage &lineage, const bool sharedBoundary,\n    const std::int64_t patchOwner, const int localVertex) {\n  std::vector<authority::TopologyRegionId> topologyRegions =\n      lineage.sourceTopologyRegions;\n  std::vector<authority::IsolationSheetId> isolationSheets =\n      lineage.sourceIsolationSheets;\n  std::sort(topologyRegions.begin(), topologyRegions.end());\n  topologyRegions.erase(\n      std::unique(topologyRegions.begin(), topologyRegions.end()),\n      topologyRegions.end());\n  std::sort(isolationSheets.begin(), isolationSheets.end());\n  isolationSheets.erase(\n      std::unique(isolationSheets.begin(), isolationSheets.end()),\n      isolationSheets.end());\n  if (topologyRegions.empty() || isolationSheets.empty()) {\n    return {};\n  }\n\n  PureQuadStitchIdentity key;\n  key.kind = sharedBoundary\n                 ? PureQuadStitchIdentityKind::ArrangementBoundaryNode\n                 : PureQuadStitchIdentityKind::GeneratedPatchInterior;\n  key.canonical.valid = true;\n  key.canonical.values = sharedBoundary\n                             ? std::vector<std::int64_t>{localVertex}\n                             : std::vector<std::int64_t>{patchOwner, localVertex};\n  key.canonical.values.push_back(\n      static_cast<std::int64_t>(topologyRegions.size()));\n  for (const authority::TopologyRegionId region : topologyRegions) {\n    key.canonical.values.push_back(static_cast<std::int64_t>(region.index()));\n  }\n  key.canonical.values.push_back(\n      static_cast<std::int64_t>(isolationSheets.size()));\n  for (const authority::IsolationSheetId sheet : isolationSheets) {\n    key.canonical.values.push_back(static_cast<std::int64_t>(sheet.index()));\n  }\n  return key;\n}\n\nPureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow,\n    const bool sharedBoundary, const std::int64_t patchOwner) {\n  const int localVertex =\n      patch.vertices[static_cast<std::size_t>(localRow)];\n  const PureQuadVertexLineage &lineage =\n      patch.vertexLineage[static_cast<std::size_t>(localRow)];\n  PureQuadStitchIdentity key = lineage.stitchIdentity;\n  if (!key.valid() ||\n      (!sharedBoundary &&\n       key.kind != PureQuadStitchIdentityKind::GeneratedPatchInterior)) {\n    key = typed_lineage_stitch_identity(lineage, sharedBoundary, patchOwner,\n                                        localVertex);\n  }\n  return key;\n}\n""",
)
replace_once(
    pure,
    """      const PureQuadStitchIdentity key = resolved_stitch_identity(\n          patch, localRow, sharedBoundary, patchOwner);\n      localRows.emplace(localVertex, localRow);\n\n      const Eigen::Vector3d position =\n""",
    """      const PureQuadStitchIdentity key = resolved_stitch_identity(\n          patch, localRow, sharedBoundary, patchOwner);\n      if (!key.valid()) {\n        result.failure = \"MissingTypedStitchIdentity\";\n        return result;\n      }\n      localRows.emplace(localVertex, localRow);\n\n      const Eigen::Vector3d position =\n""",
)

remesh_text = remesh.read_text(encoding="utf-8")
if ".point.sheet" in remesh_text:
    raise SystemExit("RemeshPipeline.cpp still semantically reads occurrence SurfacePoint::sheet")
if "authority::IsolationSheetId isolationSheet;" not in remesh_text:
    raise SystemExit("OccurrenceData is missing required typed IsolationSheetId")

pure_text = pure.read_text(encoding="utf-8")
start = pure_text.index(
    "PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow,\n"
)
end = pure_text.index(
    "PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow) {",
    start,
)
resolved_block = pure_text[start:end]
for banned in ("provenance.component", "provenance.sheet", ".sourcePoint.component", ".sourcePoint.sheet"):
    if banned in resolved_block:
        raise SystemExit(f"resolved_stitch_identity still reads raw authority: {banned}")
if "typed_lineage_stitch_identity" not in pure_text:
    raise SystemExit("typed lineage stitch identity helper missing")
if 'result.failure = "MissingTypedStitchIdentity";' not in pure_text:
    raise SystemExit("assembly does not fail closed on missing typed stitch identity")

print("R-A-REV-01 source audit: closed")
print("R-A-REV-02 source audit: closed")
