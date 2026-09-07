#!/usr/bin/env python3
"""Work-unit-2 Batch-C progressive numeric-projection census/classifier.

Source-only audit. It imports the accepted A/B progressive scanner, freezes the
remaining Batch-C site set at the accepted-B boundary, preserves that C0
allocation, and advances exact current expectations after each C partial. Every
current C occurrence is C1-C4 require-change work or an allowed direct
container / one-way diagnostic / one-way export projection.

This script never executes a Directional binary.
"""

from __future__ import annotations

import argparse
import importlib.util
import sys
from collections import Counter
from pathlib import Path

ACCEPTED_BATCH_B_SOURCE = "d284818872cb865b2369d01011c91e3abae6d60e"

# Immutable WU2C0 census authority. These constants never advance; they prove
# what C1-C4 were allocated before the first Batch-C semantic mutation.
C0_BATCH_C_COUNT = 185
C0_BATCH_C_SITE_SET_HASH = (
    "5774bbbb984baef189ee7fc5eae3c2a20d86e4f8a0acc7866d98a2ea87721c87"
)
C0_BATCH_C_REQUIRE = {"C1": 10, "C2": 7, "C3": 27, "C4": 79}
C0_BATCH_C_ALLOWED = {
    "allowed-direct-container-leaf": 17,
    "allowed-one-way-diagnostic": 23,
    "allowed-one-way-export": 22,
}
C0_BATCH_C_FILE_COUNTS = {
    ".agents/Directional/tools/audit_r_b_row_identity.py": 4,
    "include/directional/geometry/SourceTopologyRegions.h": 4,
    "include/directional/geometry/SurfaceMeshOptimizer.h": 6,
    "include/directional/geometry/SurfacePointSupport.h": 2,
    "include/directional/validation/SourceAuthoritativeMeshValidator.h": 5,
    "src/authority/AuthorityKernel.cpp": 2,
    "src/bench/BenchmarkQuality.cpp": 15,
    "src/bench/DirectionalBenchmark.cpp": 7,
    "src/geometry/SurfaceMeshOptimizer.cpp": 2,
    "src/geometry/SurfaceOptimizationRailConstraints.cpp": 6,
    "src/pipeline/RemeshPipeline.cpp": 44,
    "src/validation/SourceAuthoritativeMeshValidator.cpp": 3,
    "tests/PureQuadCompletionPhase18Tests.cpp": 14,
    "tests/SurfaceArrangementPhase16Tests.cpp": 3,
    "tests/SurfaceCellAuthorityKernelTests.cpp": 4,
    "tests/SurfaceCellPipelinePhase20Tests.cpp": 1,
    "tests/SurfaceCellTransitionQuotientTests.cpp": 21,
    "tests/SurfaceCellsPhase10Tests.cpp": 42,
}
C0_C1_FILES = {
    "include/directional/geometry/SourceTopologyRegions.h",
    "include/directional/geometry/SurfaceMeshOptimizer.h",
    "include/directional/geometry/SurfacePointSupport.h",
    "src/authority/AuthorityKernel.cpp",
    "src/geometry/SurfaceMeshOptimizer.cpp",
    "src/geometry/SurfaceOptimizationRailConstraints.cpp",
}
C0_C2_FILES = {
    "include/directional/validation/SourceAuthoritativeMeshValidator.h",
    "src/validation/SourceAuthoritativeMeshValidator.cpp",
}
C0_C3_FILES = {"src/pipeline/RemeshPipeline.cpp"}
C0_C4_FILES = set(C0_BATCH_C_FILE_COUNTS) - C0_C1_FILES - C0_C2_FILES - C0_C3_FILES

# Exact current source ledger after WU2C4. C1-C4 are retired; every remaining
# Batch-C projection is one of the frozen representation boundaries from C0.
EXPECTED_BATCH_C_COUNT = 64
EXPECTED_BATCH_C_SITE_SET_HASH = (
    "0ca4956f3b384d3b4b1a6f07dd5a975d61aa8a0558d7367017afa725ab3c032a"
)
EXPECTED_BATCH_C_REQUIRE = {"C1": 0, "C2": 0, "C3": 0, "C4": 0}
EXPECTED_BATCH_C_ALLOWED = dict(C0_BATCH_C_ALLOWED)
EXPECTED_BATCH_C_ALLOWED["allowed-one-way-export"] += 2
EXPECTED_BATCH_C_FILE_COUNTS = {
    ".agents/Directional/tools/audit_r_b_row_identity.py": 4,
    "include/directional/geometry/SourceTopologyRegions.h": 4,
    "include/directional/geometry/SurfacePointSupport.h": 2,
    "include/directional/validation/SourceAuthoritativeMeshValidator.h": 1,
    "src/authority/AuthorityKernel.cpp": 2,
    "src/bench/BenchmarkQuality.cpp": 15,
    "src/bench/DirectionalBenchmark.cpp": 7,
    "src/geometry/SurfaceOptimizationRailConstraints.cpp": 4,
    "src/pipeline/RemeshPipeline.cpp": 19,
    "tests/SurfaceCellTransitionQuotientTests.cpp": 2,
    "tests/SurfaceCellsPhase10Tests.cpp": 4,
}

C1_LINES = {}

C2_LINES = {}

C3_LINES = {}

C4_LINES = {}

ALLOWED_DIRECT_CONTAINER_LEAF = {
    "include/directional/geometry/SourceTopologyRegions.h": {196, 200, 201, 205},
    "include/directional/geometry/SurfacePointSupport.h": {234, 293},
    "src/geometry/SurfaceOptimizationRailConstraints.cpp": {32, 39, 42, 98},
    "include/directional/validation/SourceAuthoritativeMeshValidator.h": {417},
    "tests/SurfaceCellTransitionQuotientTests.cpp": {870, 1197},
    "tests/SurfaceCellsPhase10Tests.cpp": {3075, 3289, 3292, 4404},
}

ALLOWED_ONE_WAY_DIAGNOSTIC = {
    "src/authority/AuthorityKernel.cpp": {23, 38},
    "src/pipeline/RemeshPipeline.cpp": {
        803, 1152, 2345, 6498, 6500, 6505, 6510, 6523,
        6524, 6533, 6534, 7541, 7547, 7548, 7559, 7996,
        7998
    },
    ".agents/Directional/tools/audit_r_b_row_identity.py": {107, 108, 187},
}

ALLOWED_ONE_WAY_EXPORT = {
    "src/pipeline/RemeshPipeline.cpp": {5410, 5411},
    "src/bench/BenchmarkQuality.cpp": {
        974, 1020, 1024, 1026, 1031, 1033, 1035,
        1053, 1054, 1055, 1056, 1067, 1068, 1078, 1079,
    },
    "src/bench/DirectionalBenchmark.cpp": {
        1238, 1244, 1251, 2201, 2206, 2207, 2246,
    },
}

CLASSIFIERS = (
    ("requires-C1", C1_LINES),
    ("requires-C2", C2_LINES),
    ("requires-C3", C3_LINES),
    ("requires-C4", C4_LINES),
    ("allowed-direct-container-leaf", ALLOWED_DIRECT_CONTAINER_LEAF),
    ("allowed-one-way-diagnostic", ALLOWED_ONE_WAY_DIAGNOSTIC),
    ("allowed-one-way-export", ALLOWED_ONE_WAY_EXPORT),
)


def load_progressive(root: Path):
    path = root / ".agents/Directional/tools/audit_m1_numeric_projection.py"
    spec = importlib.util.spec_from_file_location("audit_m1_progressive", path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"cannot load progressive audit module: {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def classify(path: str, line: int) -> str | None:
    matches = [
        name for name, mapping in CLASSIFIERS if line in mapping.get(path, set())
    ]
    return matches[0] if len(matches) == 1 else None


def allocation_count(mapping: dict[str, set[int]], sites) -> int:
    return sum(1 for site in sites if site.line in mapping.get(site.path, set()))


def self_test() -> list[str]:
    failures: list[str] = []
    seen: dict[tuple[str, int], str] = {}
    for name, mapping in CLASSIFIERS:
        for path, lines in mapping.items():
            for line in lines:
                key = (path, line)
                previous = seen.get(key)
                if previous is not None:
                    failures.append(
                        f"Batch-C classifier overlap {path}:{line}: {previous}/{name}"
                    )
                seen[key] = name

    exemplars = {
        ("src/geometry/SurfaceOptimizationRailConstraints.cpp", 98):
            "allowed-direct-container-leaf",
                ("src/pipeline/RemeshPipeline.cpp", 803):
            "allowed-one-way-diagnostic",
        ("src/pipeline/RemeshPipeline.cpp", 803): "allowed-one-way-diagnostic",
        ("include/directional/geometry/SourceTopologyRegions.h", 196):
            "allowed-direct-container-leaf",
        ("src/authority/AuthorityKernel.cpp", 23): "allowed-one-way-diagnostic",
        ("src/bench/DirectionalBenchmark.cpp", 1238): "allowed-one-way-export",
        ("src/pipeline/RemeshPipeline.cpp", 5410): "allowed-one-way-export",
    }
    for key, expected in exemplars.items():
        actual = classify(*key)
        if actual != expected:
            failures.append(
                f"exemplar {key[0]}:{key[1]} expected {expected}, got {actual}"
            )
    if classify("src/pipeline/RemeshPipeline.cpp", 999999) is not None:
        failures.append("unknown Batch-C site was implicitly allowed")
    if sum(C0_BATCH_C_REQUIRE.values()) + sum(C0_BATCH_C_ALLOWED.values()) != C0_BATCH_C_COUNT:
        failures.append("frozen C0 allocation does not sum to frozen C0 count")
    if sum(EXPECTED_BATCH_C_REQUIRE.values()) + sum(EXPECTED_BATCH_C_ALLOWED.values()) != EXPECTED_BATCH_C_COUNT:
        failures.append("current C allocation does not sum to current C count")
    if classify("include/directional/geometry/SurfaceMeshOptimizer.h", 372) is not None:
        failures.append("migrated C1 exemplar remains classified as current work")
    if C2_LINES:
        failures.append("migrated C2 allocation remains classified as current work")
    if C3_LINES:
        failures.append("migrated C3 allocation remains classified as current work")
    if C4_LINES:
        failures.append("migrated C4 allocation remains classified as current work")
    return failures


def audit(root: Path) -> tuple[list[str], str]:
    errors = self_test()
    progressive = load_progressive(root)
    progressive_errors, _ = progressive.audit(root)
    if progressive_errors:
        errors.append("accepted A/B progressive audit is not green at current source")

    sites = progressive.scan(root)
    c_sites = [site for site in sites if progressive.batch_for(site.path) == "C"]
    file_counts = Counter(site.path for site in c_sites)
    site_hash = progressive.site_set_hash(c_sites)

    if len(c_sites) != EXPECTED_BATCH_C_COUNT:
        errors.append(
            f"Batch-C census found {len(c_sites)}, expected {EXPECTED_BATCH_C_COUNT}"
        )
    if dict(sorted(file_counts.items())) != dict(sorted(EXPECTED_BATCH_C_FILE_COUNTS.items())):
        errors.append("Batch-C per-file counts differ from current post-C4 ledger")
    if site_hash != EXPECTED_BATCH_C_SITE_SET_HASH:
        errors.append(
            f"Batch-C site-set hash {site_hash}, expected {EXPECTED_BATCH_C_SITE_SET_HASH}"
        )

    classes = Counter()
    unclassified = []
    for site in c_sites:
        classification = classify(site.path, site.line)
        if classification is None:
            unclassified.append(site)
        else:
            classes[classification] += 1

    if unclassified:
        errors.append(
            "unclassified Batch-C sites: "
            + ", ".join(
                f"{site.path}:{site.line}:{site.occurrence}"
                for site in unclassified[:12]
            )
        )

    expected_classes = {
        "requires-C1": EXPECTED_BATCH_C_REQUIRE["C1"],
        "requires-C2": EXPECTED_BATCH_C_REQUIRE["C2"],
        "requires-C3": EXPECTED_BATCH_C_REQUIRE["C3"],
        "requires-C4": EXPECTED_BATCH_C_REQUIRE["C4"],
        **EXPECTED_BATCH_C_ALLOWED,
    }
    actual_classes = {name: classes[name] for name in expected_classes}
    if actual_classes != expected_classes:
        errors.append(f"Batch-C class counts {actual_classes}, expected {expected_classes}")

    lines = [
        "# M1 work-unit-2 Batch-C numeric-projection census",
        "",
        f"- Source SHA: `{progressive.current_sha(root)}`",
        f"- Accepted Batch-B semantic source: `{ACCEPTED_BATCH_B_SOURCE}`",
        f"- Frozen WU2C0 baseline: **{C0_BATCH_C_COUNT}** sites; "
        f"C1/C2/C3/C4 **{C0_BATCH_C_REQUIRE['C1']}/{C0_BATCH_C_REQUIRE['C2']}/{C0_BATCH_C_REQUIRE['C3']}/{C0_BATCH_C_REQUIRE['C4']}**; "
        f"hash `{C0_BATCH_C_SITE_SET_HASH}`",
        "- Progressive checkpoint: **C1-C3 typed consumer/validator/pipeline authority migrated; C4 remains allocated; Batch C semantically unaccepted**.",
        f"- Result: **{'PASS' if not errors else 'FAIL'}**",
        f"- Batch-C occurrences: **{len(c_sites)} / {EXPECTED_BATCH_C_COUNT}**",
        f"- Batch-C occurrence files: **{len(file_counts)} / {len(EXPECTED_BATCH_C_FILE_COUNTS)}**",
        f"- Batch-C site-set SHA-256: `{site_hash}`",
        f"- K requiring change: **{sum(classes[f'requires-{name}'] for name in ('C1','C2','C3','C4'))}**",
        f"- C1 allocation: **{classes['requires-C1']}**",
        f"- C2 allocation: **{classes['requires-C2']}**",
        f"- C3 allocation: **{classes['requires-C3']}**",
        f"- C4 allocation: **{classes['requires-C4']}**",
        f"- Allowed direct container leaves: **{classes['allowed-direct-container-leaf']}**",
        f"- Allowed one-way diagnostics: **{classes['allowed-one-way-diagnostic']}**",
        f"- Allowed one-way exports: **{classes['allowed-one-way-export']}**",
        f"- Unallocated Batch-C sites: **{len(unclassified)}**",
        "",
        "## Frozen C file/path ownership",
        "",
    ]
    for label, owned in (
        ("C1", sorted(C0_C1_FILES)),
        ("C2", sorted(C0_C2_FILES)),
        ("C3", sorted(C0_C3_FILES)),
        ("C4", sorted(C0_C4_FILES)),
    ):
        lines.append(f"- **{label}**: " + ", ".join(f"`{path}`" for path in owned))

    lines.extend([
        "",
        "## Deferred-blocker exposure",
        "",
        "- `G4-B001`: **NO** — C0 is source/static classification only.",
        "- `G4-B002`: **NO** — no produced hard-rail witness is required.",
        "- `G4-B003`: **NO** — no nonzero periodic runtime witness is required.",
        "- `G4-B004`: **NO** — no positive multi-isolation runtime witness is required.",
        "- New produced-witness debt: **0**; existing priced debt remains **3**.",
        "",
        "## Current Batch-C sites",
        "",
    ])
    for site in c_sites:
        lines.append(
            f"- `{site.path}:{site.line}:{site.occurrence}` — "
            f"**{classify(site.path, site.line) or 'UNCLASSIFIED'}** — `{site.text}`"
        )

    lines.extend(["", "## Batch-C per-file counts", ""])
    for path, count in sorted(file_counts.items()):
        lines.append(f"- `{path}` — {count}")

    if errors:
        lines.extend(["", "## Audit errors", ""])
        lines.extend(f"- {error}" for error in errors)
    return errors, "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path.cwd())
    parser.add_argument("--report", type=Path)
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    root = args.root.resolve()

    if args.self_test:
        failures = self_test()
        if failures:
            for failure in failures:
                print(f"FAIL: {failure}")
            return 1
        print("PASS: work-unit-2 Batch-C progressive classifier self-tests")
        return 0

    errors, report = audit(root)
    if args.report:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(report, encoding="utf-8")
    else:
        sys.stdout.write(report)
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
