import subprocess

BASE_PAYLOAD_COMMIT = "65a426f3d6c6984fed20245cecc32e0818474654"
PAYLOAD_PATH = ".agents/Directional/turn-payloads/m1j-edge-source-scope.py"

source = subprocess.check_output(
    ["git", "show", f"{BASE_PAYLOAD_COMMIT}:{PAYLOAD_PATH}"], text=True
)
start = source.index('header_path = Path("include/directional/geometry/SurfaceCellTracing.h")')
end = source.index("header_path.write_text(header)", start)
replacement = r'''header_path = Path("include/directional/geometry/SurfaceCellTracing.h")
header = header_path.read_text()
edge_begin = header.index("struct SurfaceFrontEdge")
edge_end = header.index("struct SurfaceFrontEvent", edge_begin)
edge = header[edge_begin:edge_end]
edge = replace_exact(
    edge,
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
header = header[:edge_begin] + edge + header[edge_end:]
'''
source = source[:start] + replacement + source[end:]
exec(compile(source, PAYLOAD_PATH, "exec"))
