#!/usr/bin/env python3
"""Source-only R-B row-independent face/support/chart identity closure audit.

This audit never executes Directional binaries.  It checks the semantic carrier
contracts directly and inventories every remaining SourceFaceId occurrence as a
representation-row site for human review in the generated report.
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

SOURCE_SUFFIXES = {".h", ".hpp", ".cpp"}
SCAN_ROOTS = ("include", "src", "tests")


@dataclass(frozen=True)
class Finding:
    rule: str
    path: str
    line: int
    text: str


def source_files(root: Path) -> Iterable[Path]:
    for top in SCAN_ROOTS:
        base = root / top
        if not base.exists():
            continue
        for path in sorted(base.rglob("*")):
            if path.is_file() and path.suffix in SOURCE_SUFFIXES and "external" not in path.parts:
                yield path


def line_findings(root: Path, rule: str, pattern: re.Pattern[str]) -> list[Finding]:
    findings: list[Finding] = []
    for path in source_files(root):
        relative = path.relative_to(root).as_posix()
        for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            if pattern.search(line):
                findings.append(Finding(rule, relative, number, line.strip()))
    return findings


def semantic_carrier_findings(root: Path) -> list[Finding]:
    findings: list[Finding] = []
    carriers = [
        (
            root / "include/directional/authority/SourceSupport.h",
            "SourceFaceInteriorSupport",
            "SourceFaceTopologyKey face;",
            "R-B-SUPPORT-CARRIER",
        ),
        (
            root / "include/directional/geometry/SurfaceCellOwnership.h",
            "SourceProjectionChart",
            "SourceFaceTopologyKey face;",
            "R-B-CHART-CARRIER",
        ),
    ]
    for path, struct_name, required, rule in carriers:
        text = path.read_text(encoding="utf-8")
        match = re.search(
            rf"struct\s+{re.escape(struct_name)}\s*\{{(?P<body>.*?)\n\}};",
            text,
            flags=re.DOTALL,
        )
        if match is None or required not in match.group("body"):
            findings.append(Finding(rule, path.relative_to(root).as_posix(), 1, f"missing `{required}`"))
        if match is not None and "SourceFaceId" in match.group("body"):
            line = text[: match.start()].count("\n") + 1
            findings.append(Finding(rule, path.relative_to(root).as_posix(), line, "semantic carrier contains SourceFaceId"))
    return findings


def audit_text(path: str, text: str) -> list[Finding]:
    findings: list[Finding] = []
    patterns = [
        ("R-B-ROW-FIELD-INDEX", re.compile(r"(?:\.|->)face\.index\s*\(\s*\)")),
        (
            "R-B-FIELD-CHART-FROM-ROW",
            re.compile(r"FieldChartId::from_index\s*\([^\n]*(?:sourceFace|faceRow|row)"),
        ),
        (
            "R-B-PROJECTION-CHART-ROW-CONSTRUCTOR",
            re.compile(r"SourceProjectionChart\s*\([^\n]*\b(?:faceId|faceRow|sourceFaceId|row)\.value\s*\(\s*\)"),
        ),
        (
            "R-B-FACE-SUPPORT-ROW-CONSTRUCTOR",
            re.compile(r"SourceFaceInteriorSupport\s*\{[^\n]*\b(?:faceId|faceRow|sourceFace|row)\.value\s*\(\s*\)"),
        ),
    ]
    for number, line in enumerate(text.splitlines(), 1):
        for rule, pattern in patterns:
            if pattern.search(line):
                findings.append(Finding(rule, path, number, line.strip()))
    return findings


def run_self_test() -> tuple[bool, list[str]]:
    cases = {
        "row-member-index": "value.face.index();",
        "pointer-row-member-index": "scope.chart->face.index();",
        "field-chart-row": "FieldChartId::from_index(sourceFace, extent);",
        "projection-row": "SourceProjectionChart(chart, faceId.value());",
        "support-row": "SourceFaceInteriorSupport{sourceFace.value()};",
    }
    failures: list[str] = []
    for name, snippet in cases.items():
        if not audit_text(f"self-test/{name}.cpp", snippet):
            failures.append(name)
    return not failures, failures


def classify_row_site(path: str, text: str) -> str:
    if "SourceTopologyRegions" in path:
        return "canonical row<->topology projection owner"
    if "SurfacePointSupport" in path:
        return "incident-face/container row projection"
    if "SourceChartTransitions" in path:
        return "chart-to-container row projection"
    if "SourceOptimizationRailConstraints" in path:
        return "source-container lookup"
    if "PureQuadCompletion" in path:
        return "support incidence/container lookup or diagnostic row"
    if "SurfaceCellTracing" in path:
        return "source-face traversal/container lookup"
    if "SurfaceArrangement" in path:
        return "source-face traversal/container lookup"
    if "RemeshPipeline" in path:
        return "component/source-container remap or diagnostic row"
    if "SourceAuthoritativeMeshValidator" in path:
        return "validator source-container lookup"
    if "SurfaceMeshOptimizer" in path:
        return "optimizer/validator source-container lookup"
    if "FlowRepStrands" in path:
        return "source-container lookup"
    if "DirectionalBenchmark" in path:
        return "benchmark representation lookup"
    if path.startswith("tests/"):
        return "test representation row"
    return "reviewed checked row locator"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path.cwd())
    parser.add_argument("--report", type=Path)
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    root = args.root.resolve()

    findings: list[Finding] = []
    for path in source_files(root):
        relative = path.relative_to(root).as_posix()
        findings.extend(audit_text(relative, path.read_text(encoding="utf-8")))
    findings.extend(semantic_carrier_findings(root))

    row_sites = line_findings(root, "R-B-ROW-INVENTORY", re.compile(r"\bSourceFaceId\b"))
    support_sites = line_findings(root, "R-B-SUPPORT-INVENTORY", re.compile(r"\bSourceSupport\b|SourceFaceInteriorSupport"))
    chart_sites = line_findings(root, "R-B-CHART-INVENTORY", re.compile(r"\bSourceProjectionChart\b|\bFieldChartId\b"))
    topology_sites = line_findings(root, "R-B-TOPOLOGY-INVENTORY", re.compile(r"\bSourceFaceTopologyKey\b"))

    self_test_ok = True
    self_test_failures: list[str] = []
    if args.self_test:
        self_test_ok, self_test_failures = run_self_test()
        if not self_test_ok:
            findings.append(Finding("R-B-AUDIT-SELF-TEST", "audit", 0, ", ".join(self_test_failures)))

    lines = [
        "# R-B row-independent identity source audit",
        "",
        f"- Result: **{'PASS' if not findings else 'FAIL'}**",
        f"- Audit self-test: **{'PASS' if self_test_ok else 'FAIL'}**",
        f"- Forbidden semantic row findings: **{len(findings)}**",
        f"- Remaining `SourceFaceId` row-locator sites inventoried: **{len(row_sites)}**",
        f"- `SourceSupport` sites inventoried: **{len(support_sites)}**",
        f"- `SourceProjectionChart` / `FieldChartId` sites inventoried: **{len(chart_sites)}**",
        f"- `SourceFaceTopologyKey` sites inventoried: **{len(topology_sites)}**",
        "",
        "The audit treats `SourceFaceId` as a checked representation-row locator only. Semantic face support and projection-chart equality/order/hash are required to carry `SourceFaceTopologyKey`. It also rejects direct `.face.index()` / `->face.index()` recovery from semantic carriers and direct chart/support construction from row IDs.",
        "",
        "## Forbidden findings",
        "",
    ]
    if findings:
        for finding in findings:
            lines.append(f"- `{finding.rule}` `{finding.path}:{finding.line}` — `{finding.text}`")
    else:
        lines.append("- None.")
    lines.extend(["", "## Remaining checked row-locator inventory", ""])
    for finding in row_sites:
        lines.append(
            f"- `{finding.path}:{finding.line}` — {classify_row_site(finding.path, finding.text)} — `{finding.text}`"
        )

    report = "\n".join(lines) + "\n"
    if args.report:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(report, encoding="utf-8")
    else:
        sys.stdout.write(report)
    return 0 if not findings else 1


if __name__ == "__main__":
    raise SystemExit(main())
