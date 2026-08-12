from pathlib import Path


remesh = Path("src/pipeline/RemeshPipeline.cpp")
pure = Path("src/geometry/PureQuadCompletion.cpp")

remesh_text = remesh.read_text(encoding="utf-8")
old = "sheetsByTopologyRegion[occurrence.topologyRegion].insert(sheet);"
new = "sheetsByTopologyRegion[occurrence.topologyRegion].insert(\n          occurrence.isolationSheet);"
if remesh_text.count(old) != 1:
    raise SystemExit(
        f"{remesh}: expected one stale local sheet alias read, found {remesh_text.count(old)}"
    )
remesh.write_text(remesh_text.replace(old, new, 1), encoding="utf-8")

remesh_text = remesh.read_text(encoding="utf-8")
if ".point.sheet" in remesh_text:
    raise SystemExit("RemeshPipeline.cpp still semantically reads occurrence SurfacePoint::sheet")
if "authority::IsolationSheetId isolationSheet;" not in remesh_text:
    raise SystemExit("OccurrenceData is missing required typed IsolationSheetId")
if "insert(sheet);" in remesh_text:
    raise SystemExit("RemeshPipeline.cpp still reads the removed local sheet alias")

pure_text = pure.read_text(encoding="utf-8")
start = pure_text.index(
    "PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow,\n"
)
end = pure_text.index(
    "PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow) {",
    start,
)
resolved_block = pure_text[start:end]
for banned in (
    "provenance.component",
    "provenance.sheet",
    ".sourcePoint.component",
    ".sourcePoint.sheet",
):
    if banned in resolved_block:
        raise SystemExit(f"resolved_stitch_identity still reads raw authority: {banned}")
if "typed_lineage_stitch_identity" not in pure_text:
    raise SystemExit("typed lineage stitch identity helper missing")
if 'result.failure = "MissingTypedStitchIdentity";' not in pure_text:
    raise SystemExit("assembly does not fail closed on missing typed stitch identity")

print("R-A-REV-01 source audit: closed, including typed sheet aggregation")
print("R-A-REV-02 source audit: closed")
