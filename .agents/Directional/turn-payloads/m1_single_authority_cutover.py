#!/usr/bin/env python3
from __future__ import annotations

import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parents[3]
TEXT_ROOTS = [ROOT / "include", ROOT / "src", ROOT / "tests", ROOT / "cmake"]
EXTRA_FILES = [ROOT / "CMakeLists.txt"]

FACTORIES = {
    "source_vertex": "SourceVertexId",
    "source_face": "SourceFaceId",
    "interior_transition": "InteriorTransitionId",
    "source_component": "SourceComponentId",
    "isolation_sheet": "IsolationSheetId",
    "topology_region": "TopologyRegionId",
    "field_chart": "FieldChartId",
    "hard_rail": "HardRailId",
    "periodic_relation": "PeriodicRelationId",
    "cell": "CellId",
    "occurrence": "OccurrenceId",
    "quotient_class": "QuotientClassId",
}


def replace_balanced_call(text: str, prefix: str) -> str:
    pos = 0
    while True:
        start = text.find(prefix, pos)
        if start < 0:
            return text
        arg_start = start + len(prefix)
        depth = 1
        i = arg_start
        in_string = None
        escape = False
        while i < len(text) and depth:
            ch = text[i]
            if in_string:
                if escape:
                    escape = False
                elif ch == "\\":
                    escape = True
                elif ch == in_string:
                    in_string = None
            else:
                if ch in ('"', "'"):
                    in_string = ch
                elif ch == '(':
                    depth += 1
                elif ch == ')':
                    depth -= 1
            i += 1
        if depth != 0:
            raise RuntimeError(f"unbalanced call for {prefix} at {start}")
        expression = text[arg_start : i - 1]
        replacement = f"({expression}).index()"
        text = text[:start] + replacement + text[i:]
        pos = start + len(replacement)


def rewrite(text: str) -> str:
    text = re.sub(
        r'^\s*#include\s*<directional/authority/LegacyAuthorityAdapters\.h>\s*\n',
        '', text, flags=re.MULTILINE)
    text = re.sub(
        r'^\s*using\s+(?:directional::)?authority::LegacyAuthorityAdapters;\s*\n',
        '', text, flags=re.MULTILINE)

    # Formatting may split a class scope from the called method/template.
    text = re.sub(r'(LegacyAuthorityAdapters::)\s+', r'\1', text)

    # Checked construction belongs to the semantic ID type itself.
    for method, id_type in FACTORIES.items():
        for qualifier in (
            "directional::authority::LegacyAuthorityAdapters::",
            "authority::LegacyAuthorityAdapters::",
            "LegacyAuthorityAdapters::",
        ):
            text = text.replace(
                qualifier + method,
                f"directional::authority::{id_type}::from_index")

    checked_patterns = [
        r"directional::authority::LegacyAuthorityAdapters::checked<([^>]+)>",
        r"authority::LegacyAuthorityAdapters::checked<([^>]+)>",
        r"LegacyAuthorityAdapters::checked<([^>]+)>",
    ]
    for pattern in checked_patterns:
        text = re.sub(pattern, r"\1::from_domain_index", text)

    for prefix in (
        "directional::authority::LegacyAuthorityAdapters::to_legacy_index(",
        "authority::LegacyAuthorityAdapters::to_legacy_index(",
        "LegacyAuthorityAdapters::to_legacy_index(",
    ):
        text = replace_balanced_call(text, prefix)

    text = text.replace("NegativeLegacyValue", "NegativeIndex")
    text = text.replace("OutOfRangeLegacyValue", "IndexOutOfRange")
    text = text.replace("legacyValue", "inputValue")

    # Single names for the surviving chart/support contracts.
    text = text.replace("SourceChartId", "SourceProjectionChart")
    text = text.replace("SurfaceCellSourceChart", "SurfaceCellProjectionChart")

    # Remove explicitly obsolete raw-authority field spellings. These are
    # transitional representation names only; the next edits in this same
    # turn replace their storage with CanonicalRoute/typed products.
    text = text.replace("transitionSourceEdges", "entryRouteTransitionIndices")
    text = text.replace("transitionSourceTopology", "entryRouteTopologyKeys")
    text = text.replace("transitionSourceEdge", "entryTransitionIndex")
    text = text.replace("sourceRouteEdges", "routeTransitionIndices")
    text = text.replace("sourceRouteTopology", "routeTopologyKeys")

    # Consolidate topology-region ownership in producer/network products.
    text = text.replace("phaseFront.sourceTopologyRegionByFace",
                        "phaseFront.sourceTopologyRegions.regionByFace")
    text = text.replace("phaseFront.topologyRegions",
                        "phaseFront.sourceTopologyRegions.regions")
    text = text.replace("network.sourceFaceTopologyRegions",
                        "network.sourceTopologyRegions.regionByFace")
    text = text.replace("network.topologyRegions",
                        "network.sourceTopologyRegions.regions")
    return text


def source_files():
    for root in TEXT_ROOTS:
        if not root.exists():
            continue
        for path in root.rglob("*"):
            if path.suffix.lower() in {".h", ".hpp", ".cpp", ".cc", ".cxx", ".cmake", ".txt"}:
                yield path
    yield from EXTRA_FILES


changed = []
for path in source_files():
    if not path.exists():
        continue
    old = path.read_text(encoding="utf-8")
    new = rewrite(old)
    if old != new:
        path.write_text(new, encoding="utf-8")
        changed.append(path.relative_to(ROOT).as_posix())

# Structural declaration consolidation requires context-aware edits.
tracing = ROOT / "include/directional/geometry/SurfaceCellTracing.h"
text = tracing.read_text(encoding="utf-8")
old = """  std::vector<int> sourceTopologyRegionByFace;\n  std::vector<SurfaceTopologyRegion> topologyRegions;\n"""
if old in text:
    text = text.replace(old, "  SourceTopologyRegions sourceTopologyRegions;\n", 1)
old_network = """  std::vector<int> sourceFaceTopologyRegions;\n  std::vector<SurfaceTopologyRegion> topologyRegions;\n"""
if old_network in text:
    text = text.replace(old_network, "  SourceTopologyRegions sourceTopologyRegions;\n", 1)
tracing.write_text(text, encoding="utf-8")
if tracing.relative_to(ROOT).as_posix() not in changed:
    changed.append(tracing.relative_to(ROOT).as_posix())

print("M1 cutover codemod changed paths:")
for path in sorted(set(changed)):
    print(path)
