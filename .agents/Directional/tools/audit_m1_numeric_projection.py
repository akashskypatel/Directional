#!/usr/bin/env python3
"""M1 work-unit-2 progressive numeric-projection census/classifier.

Source-only audit. It never executes a Directional binary.

WU2A0 froze the complete `.index()` site set and classified Batch A. WU2B0
freezes the accepted-post-A Batch-B subset before any B1-B3 production edit.
This progressive ledger preserves both immutable census authorities while
checking the exact current source after each partial. Migrated sites disappear
from the current require-change set; new representation leaves must be
explicitly classified.
"""

from __future__ import annotations

import argparse
import hashlib
import re
import subprocess
import sys
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

INDEX_PATTERN = re.compile(r"\.index\s*\(")
SOURCE_ROOTS = ("include/directional", "src", "tests", "benchmarks")
SOURCE_SUFFIXES = {".h", ".hpp", ".cpp", ".cc", ".cxx"}
EXTRA_SCAN_FILES = (".agents/Directional/tools/audit_r_b_row_identity.py",)

A0_MASTER_COUNT = 403
A0_BATCH_COUNTS = {"A": 97, "B": 123, "C": 183}
A0_BATCH_A_REQUIRE = {"A1": 9, "A2": 20, "A3": 22}
A0_SITE_SET_HASH = "192b388a0727c551d81421ffda419361c041684a7c53422a79cffef16fd0a2af"

B0_ACCEPTED_A_SOURCE = "5e1fed2545ac730c328f1ff475069874a84ec72a"
B0_BATCH_B_COUNT = 123
B0_BATCH_B_FILE_ORDER = (
    "src/geometry/SurfaceCellTracing.cpp",
    "src/geometry/SurfaceCellFeasibilityRepair.cpp",
    "src/geometry/SurfaceComplexSimplification.cpp",
    "src/geometry/FlowRepStrands.cpp",
)
B0_BATCH_B_FILE_COUNTS = {
    "src/geometry/SurfaceCellTracing.cpp": 112,
    "src/geometry/SurfaceCellFeasibilityRepair.cpp": 4,
    "src/geometry/SurfaceComplexSimplification.cpp": 6,
    "src/geometry/FlowRepStrands.cpp": 1,
}
B0_BATCH_B_REQUIRE = {"B1": 25, "B2": 17, "B3": 7}
B0_BATCH_B_SITE_SET_HASH = "1cbf56bfdc6fec76efaf36528a38c55205dceb5594259c47a101c09c4a20ca92"

# Exact progressive source ledger after WU2C4. Immutable A0/B0 constants
# above remain frozen; only these current-source expectations advance after a
# reconciled partial Code + Build checkpoint.
EXPECTED_MASTER_COUNT = 199
EXPECTED_OCCURRENCE_FILE_COUNT = 17
EXPECTED_BATCH_COUNTS = {"A": 51, "B": 84, "C": 64}
EXPECTED_SITE_SET_HASH = "60873d621fa1e5eb74978229e6c18328251264dbdcf6768d34d874fa02b2c503"
EXPECTED_BATCH_B_FILE_COUNTS = {
    "src/geometry/SurfaceCellTracing.cpp": 80,
    "src/geometry/SurfaceComplexSimplification.cpp": 4,
}
EXPECTED_BATCH_B_SITE_SET_HASH = "fbd9763324315f34c7651584a9f3cf5ef042963c635fa5c3f864a983276074fc"
EXPECTED_BATCH_B_REQUIRE = {"B1": 0, "B2": 0, "B3": 0}

EXPECTED_FILE_COUNTS = {
    ".agents/Directional/tools/audit_r_b_row_identity.py": 4,
    "include/directional/geometry/SourceChartTransitions.h": 10,
    "include/directional/geometry/SourceTopologyRegions.h": 4,
    "include/directional/geometry/SurfaceCellOwnership.h": 1,
    "include/directional/geometry/SurfacePointSupport.h": 2,
    "include/directional/validation/SourceAuthoritativeMeshValidator.h": 1,
    "src/authority/AuthorityKernel.cpp": 2,
    "src/bench/BenchmarkQuality.cpp": 15,
    "src/bench/DirectionalBenchmark.cpp": 7,
    "src/geometry/PureQuadCompletion.cpp": 22,
    "src/geometry/SurfaceArrangement.cpp": 18,
    "src/geometry/SurfaceCellTracing.cpp": 80,
    "src/geometry/SurfaceComplexSimplification.cpp": 4,
    "src/geometry/SurfaceOptimizationRailConstraints.cpp": 4,
    "src/pipeline/RemeshPipeline.cpp": 19,
    "tests/SurfaceCellTransitionQuotientTests.cpp": 2,
    "tests/SurfaceCellsPhase10Tests.cpp": 4,
}

BATCH_A_FILES = {
    "include/directional/authority/AuthorityIds.h",  # zero `.index()` sites at A0
    "include/directional/geometry/SourceChartTransitions.h",
    "include/directional/geometry/SurfaceCellOwnership.h",
    "src/geometry/SurfaceArrangement.cpp",
    "src/geometry/PatchDescriptor.cpp",
    "src/geometry/PureQuadCompletion.cpp",
}
BATCH_B_FILES = {
    "src/geometry/SurfaceCellTracing.cpp",
    "src/geometry/SurfaceCellFeasibilityRepair.cpp",
    "src/geometry/SurfaceComplexSimplification.cpp",
    "src/geometry/FlowRepStrands.cpp",
}
BATCH_C_FILES = (
    set(EXPECTED_FILE_COUNTS)
    | {
        "include/directional/geometry/SurfaceMeshOptimizer.h",
        "src/geometry/SurfaceMeshOptimizer.cpp",
    }
) - (BATCH_A_FILES | BATCH_B_FILES)

# Progressive Batch-A classification. No site is allowed by default.
# A1's nine frozen require-change sites have been retired from current source.
A1_LINES = {}
A2_LINES = {}
A3_LINES = {}
ALLOWED_DIRECT_CONTAINER_LEAF = {
    "include/directional/geometry/SourceChartTransitions.h": {419, 431, 433, 489},
    "src/geometry/SurfaceArrangement.cpp": {1540, 1807, 2599, 2606, 2608, 4807, 4822, 4824},
    "src/geometry/PureQuadCompletion.cpp": {744, 745, 911, 1221, 1283, 1300, 1302, 2098, 2106, 2116, 2117, 3133},
}
ALLOWED_ONE_WAY_DIAGNOSTIC = {
    "include/directional/geometry/SurfaceCellOwnership.h": {175},
    "include/directional/geometry/SourceChartTransitions.h": {854, 856, 858, 860, 863, 864},
    "src/geometry/SurfaceArrangement.cpp": {33, 39, 40, 44, 7642, 7644, 7648, 7650},
    "src/geometry/PureQuadCompletion.cpp": {
        640, 684, 687, 688, 713, 721
    },
}
ALLOWED_ONE_WAY_EXPORT = {
    "src/geometry/SurfaceArrangement.cpp": {1764, 1770},
    "src/geometry/PureQuadCompletion.cpp": {315, 317, 1350, 1352},
}

A_CLASSIFIERS = (
    ("requires-A1", A1_LINES),
    ("requires-A2", A2_LINES),
    ("requires-A3", A3_LINES),
    ("allowed-direct-container-leaf", ALLOWED_DIRECT_CONTAINER_LEAF),
    ("allowed-one-way-diagnostic", ALLOWED_ONE_WAY_DIAGNOSTIC),
    ("allowed-one-way-export", ALLOWED_ONE_WAY_EXPORT),
)

# Progressive Batch-B classification after WU2B3. The immutable B0 census
# remains frozen above. B1 source-face scheduling/queue/map authority, B2
# tracing provenance/reconstruction, and B3 secondary-producer authority are
# migrated. One HardRailId projection remains as the explicit one-way public
# SurfaceTraceSeed::sourceId export boundary.
B1_LINES = {}
B2_LINES = {}
B3_LINES = {}
B_ALLOWED_DIRECT_CONTAINER_LEAF = {
    "src/geometry/SurfaceCellTracing.cpp": {
        119,
        2545, 2546, 2547, 2550,
        2581, 2582,
        2705, 2721,
        2737, 2738, 2744,
        6637, 6647, 6672,
        8333, 8343, 8362,
        9777, 9783, 9823,
        10436,
    },
}
B_ALLOWED_ONE_WAY_DIAGNOSTIC = {
    "src/geometry/SurfaceCellTracing.cpp": {
        187, 188, 189, 190, 193, 197, 199, 200,
        3237, 3238, 3243, 3245, 3249, 3250, 3254, 3255,
        6530, 6550, 6558, 6584, 6615,
        6642, 6652, 6666,
        8193, 8213, 8224, 8236, 8248, 8280, 8301, 8330, 8338, 8348,
        9167,
        9600, 9616, 9636, 9647, 9661, 9673, 9701, 9729,
        9780, 9801, 9809,
        10264, 10276, 10287, 10295, 10304, 10317, 10331, 10341,
        10456, 10474, 10495,
    },
    "src/geometry/SurfaceComplexSimplification.cpp": {75, 77, 81, 83},
}
B_ALLOWED_ONE_WAY_EXPORT = {
    "src/geometry/SurfaceCellTracing.cpp": {134},
}


B_CLASSIFIERS = (
    ("requires-B1", B1_LINES),
    ("requires-B2", B2_LINES),
    ("requires-B3", B3_LINES),
    ("allowed-direct-container-leaf", B_ALLOWED_DIRECT_CONTAINER_LEAF),
    ("allowed-one-way-diagnostic", B_ALLOWED_ONE_WAY_DIAGNOSTIC),
    ("allowed-one-way-export", B_ALLOWED_ONE_WAY_EXPORT),
)


@dataclass(frozen=True)
class Site:
    path: str
    line: int
    occurrence: int
    text: str

    @property
    def key(self) -> tuple[str, int]:
        return self.path, self.line


def source_files(root: Path) -> list[Path]:
    files: list[Path] = []
    for top in SOURCE_ROOTS:
        base = root / top
        if not base.exists():
            continue
        for path in sorted(base.rglob("*")):
            if (
                path.is_file()
                and path.suffix in SOURCE_SUFFIXES
                and "external" not in path.parts
            ):
                files.append(path)
    for relative in EXTRA_SCAN_FILES:
        path = root / relative
        if path.is_file():
            files.append(path)
    return files


def scan(root: Path) -> list[Site]:
    sites: list[Site] = []
    for path in source_files(root):
        relative = path.relative_to(root).as_posix()
        text = path.read_text(encoding="utf-8", errors="replace")
        for line_no, line in enumerate(text.splitlines(), 1):
            count = len(INDEX_PATTERN.findall(line))
            for occurrence in range(1, count + 1):
                sites.append(Site(relative, line_no, occurrence, line.strip()))
    return sites


def batch_for(path: str) -> str | None:
    if path in BATCH_A_FILES:
        return "A"
    if path in BATCH_B_FILES:
        return "B"
    if path in BATCH_C_FILES:
        return "C"
    return None


def classify_a(path: str, line: int) -> str | None:
    matches = [
        name
        for name, mapping in A_CLASSIFIERS
        if line in mapping.get(path, set())
    ]
    if len(matches) != 1:
        return None
    return matches[0]


def classify_b(path: str, line: int) -> str | None:
    matches = [
        name
        for name, mapping in B_CLASSIFIERS
        if line in mapping.get(path, set())
    ]
    if len(matches) != 1:
        return None
    return matches[0]


def current_sha(root: Path) -> str:
    try:
        return subprocess.check_output(
            ["git", "rev-parse", "HEAD"],
            cwd=root,
            text=True,
            stderr=subprocess.DEVNULL,
        ).strip()
    except (OSError, subprocess.CalledProcessError):
        return "unknown"


def site_set_hash(sites: list[Site]) -> str:
    payload = "\n".join(
        f"{site.path}:{site.line}:{site.occurrence}:{site.text}" for site in sites
    )
    return hashlib.sha256(payload.encode("utf-8")).hexdigest()


def classifier_self_test() -> list[str]:
    failures: list[str] = []

    # Each batch classifier must be pairwise disjoint and fail closed.
    for batch_name, classifiers in (("A", A_CLASSIFIERS), ("B", B_CLASSIFIERS)):
        seen: dict[tuple[str, int], str] = {}
        for name, mapping in classifiers:
            for path, lines in mapping.items():
                for line in lines:
                    key = (path, line)
                    previous = seen.get(key)
                    if previous is not None:
                        failures.append(
                            f"Batch-{batch_name} classifier overlap "
                            f"{path}:{line}: {previous}/{name}"
                        )
                    seen[key] = name

    exemplars = {
        ("include/directional/geometry/SurfaceCellOwnership.h", 175):
            "allowed-one-way-diagnostic",
        ("include/directional/geometry/SourceChartTransitions.h", 419):
            "allowed-direct-container-leaf",
        ("src/geometry/PureQuadCompletion.cpp", 744):
            "allowed-direct-container-leaf",
        ("src/geometry/SurfaceArrangement.cpp", 1540):
            "allowed-direct-container-leaf",
        ("src/geometry/SurfaceArrangement.cpp", 33):
            "allowed-one-way-diagnostic",
        ("src/geometry/PureQuadCompletion.cpp", 315): "allowed-one-way-export",
    }
    for key, expected in exemplars.items():
        actual = classify_a(*key)
        if actual != expected:
            failures.append(
                f"exemplar {key[0]}:{key[1]} expected {expected}, got {actual}"
            )

    if classify_a("src/geometry/SurfaceArrangement.cpp", 999999) is not None:
        failures.append("unknown Batch-A site was implicitly allowed")

    b_exemplars = {
        ("src/geometry/SurfaceCellTracing.cpp", 119):
            "allowed-direct-container-leaf",
        ("src/geometry/SurfaceCellTracing.cpp", 3237):
            "allowed-one-way-diagnostic",
        ("src/geometry/SurfaceCellTracing.cpp", 134):
            "allowed-one-way-export",
        ("src/geometry/SurfaceComplexSimplification.cpp", 75):
            "allowed-one-way-diagnostic",
    }
    for key, expected in b_exemplars.items():
        actual = classify_b(*key)
        if actual != expected:
            failures.append(
                f"Batch-B exemplar {key[0]}:{key[1]} expected {expected}, got {actual}"
            )
    if classify_b("src/geometry/SurfaceCellTracing.cpp", 999999) is not None:
        failures.append("unknown Batch-B site was implicitly allowed")

    synthetic = "a.index(); b.index (); c.index(\n"
    if len(INDEX_PATTERN.findall(synthetic)) != 3:
        failures.append("index scanner failed multi-spelling synthetic case")

    expected_a_require = (
        sum(len(lines) for lines in A1_LINES.values())
        + sum(len(lines) for lines in A2_LINES.values())
        + sum(len(lines) for lines in A3_LINES.values())
    )
    expected_a_allow = sum(
        len(lines) for _, mapping in A_CLASSIFIERS[3:] for lines in mapping.values()
    )
    if expected_a_require != 0:
        failures.append(
            f"current require-change count is {expected_a_require}, expected 0"
        )
    if expected_a_allow != 51:
        failures.append(f"current allowed count is {expected_a_allow}, expected 51")

    expected_b_require = {
        "B1": sum(len(lines) for lines in B1_LINES.values()),
        "B2": sum(len(lines) for lines in B2_LINES.values()),
        "B3": sum(len(lines) for lines in B3_LINES.values()),
    }
    expected_b_allow = sum(
        len(lines) for _, mapping in B_CLASSIFIERS[3:] for lines in mapping.values()
    )
    if expected_b_require != EXPECTED_BATCH_B_REQUIRE:
        failures.append(
            f"current Batch-B require-change allocation {expected_b_require}, "
            f"expected {EXPECTED_BATCH_B_REQUIRE}"
        )
    if sum(expected_b_require.values()) + expected_b_allow != EXPECTED_BATCH_COUNTS["B"]:
        failures.append(
            "current Batch-B classifier allocation does not cover the progressive ledger"
        )
    if (
        A0_MASTER_COUNT != 403
        or A0_BATCH_COUNTS != {"A": 97, "B": 123, "C": 183}
        or A0_BATCH_A_REQUIRE != {"A1": 9, "A2": 20, "A3": 22}
    ):
        failures.append("immutable A0 baseline constants changed")
    if (
        B0_ACCEPTED_A_SOURCE != "5e1fed2545ac730c328f1ff475069874a84ec72a"
        or B0_BATCH_B_COUNT != 123
        or B0_BATCH_B_REQUIRE != {"B1": 25, "B2": 17, "B3": 7}
        or B0_BATCH_B_SITE_SET_HASH
        != "1cbf56bfdc6fec76efaf36528a38c55205dceb5594259c47a101c09c4a20ca92"
    ):
        failures.append("immutable WU2B0 baseline constants changed")

    if (
        BATCH_A_FILES & BATCH_B_FILES
        or BATCH_A_FILES & BATCH_C_FILES
        or BATCH_B_FILES & BATCH_C_FILES
    ):
        failures.append("batch ownership sets overlap")

    return failures


def audit(root: Path) -> tuple[list[str], str]:
    errors = classifier_self_test()
    sites = scan(root)
    file_counts = Counter(site.path for site in sites)

    if len(sites) != EXPECTED_MASTER_COUNT:
        errors.append(
            f"master census found {len(sites)}, expected {EXPECTED_MASTER_COUNT}"
        )
    if len(file_counts) != EXPECTED_OCCURRENCE_FILE_COUNT:
        errors.append(
            f"master census found {len(file_counts)} occurrence files, expected {EXPECTED_OCCURRENCE_FILE_COUNT}"
        )
    if dict(sorted(file_counts.items())) != dict(sorted(EXPECTED_FILE_COUNTS.items())):
        errors.append("master per-file occurrence counts differ from progressive ledger")
    current_site_hash = site_set_hash(sites)
    if current_site_hash != EXPECTED_SITE_SET_HASH:
        errors.append(f"master site-set hash {current_site_hash}, expected {EXPECTED_SITE_SET_HASH}")

    routed = Counter()
    unowned: list[Site] = []
    for site in sites:
        batch = batch_for(site.path)
        if batch is None:
            unowned.append(site)
        else:
            routed[batch] += 1
    if unowned:
        errors.append(
            "unowned master sites: "
            + ", ".join(f"{s.path}:{s.line}" for s in unowned[:8])
        )
    if dict(routed) != EXPECTED_BATCH_COUNTS:
        errors.append(
            f"batch counts {dict(routed)}, expected {EXPECTED_BATCH_COUNTS}"
        )

    a_sites = [site for site in sites if batch_for(site.path) == "A"]
    a_classes = Counter()
    a_unclassified: list[Site] = []
    for site in a_sites:
        classification = classify_a(site.path, site.line)
        if classification is None:
            a_unclassified.append(site)
        else:
            a_classes[classification] += 1

    if a_unclassified:
        errors.append(
            "unclassified Batch-A sites: "
            + ", ".join(
                f"{s.path}:{s.line}:{s.occurrence}" for s in a_unclassified[:12]
            )
        )
    expected_classes = {
        "allowed-direct-container-leaf": 24,
        "allowed-one-way-diagnostic": 21,
        "allowed-one-way-export": 6,
    }
    if dict(a_classes) != expected_classes:
        errors.append(
            f"Batch-A class counts {dict(a_classes)}, expected {expected_classes}"
        )

    b_sites = [site for site in sites if batch_for(site.path) == "B"]
    b_file_counts = Counter(site.path for site in b_sites)
    b_file_rank = {path: rank for rank, path in enumerate(B0_BATCH_B_FILE_ORDER)}
    b_hash_sites = sorted(
        b_sites,
        key=lambda site: (
            b_file_rank.get(site.path, len(b_file_rank)),
            site.line,
            site.occurrence,
        ),
    )
    b_site_hash = site_set_hash(b_hash_sites)
    b_classes = Counter()
    b_unclassified: list[Site] = []
    for site in b_sites:
        classification = classify_b(site.path, site.line)
        if classification is None:
            b_unclassified.append(site)
        else:
            b_classes[classification] += 1

    if len(b_sites) != EXPECTED_BATCH_COUNTS["B"]:
        errors.append(
            f"Batch-B census found {len(b_sites)}, expected {EXPECTED_BATCH_COUNTS['B']}"
        )
    if dict(sorted(b_file_counts.items())) != dict(
        sorted(EXPECTED_BATCH_B_FILE_COUNTS.items())
    ):
        errors.append("Batch-B per-file counts differ from progressive ledger")
    if b_site_hash != EXPECTED_BATCH_B_SITE_SET_HASH:
        errors.append(
            f"Batch-B site-set hash {b_site_hash}, expected {EXPECTED_BATCH_B_SITE_SET_HASH}"
        )
    if b_unclassified:
        errors.append(
            "unclassified Batch-B sites: "
            + ", ".join(
                f"{site.path}:{site.line}:{site.occurrence}"
                for site in b_unclassified[:12]
            )
        )
    expected_b_classes = {
        "allowed-direct-container-leaf": 22,
        "allowed-one-way-diagnostic": 61,
        "allowed-one-way-export": 1,
    }
    if dict(b_classes) != expected_b_classes:
        errors.append(
            f"Batch-B class counts {dict(b_classes)}, expected {expected_b_classes}"
        )

    lines = [
        "# M1 work-unit-2 progressive numeric-projection census",
        "",
        f"- Source SHA: `{current_sha(root)}`",
        f"- Frozen A0 baseline: **{A0_MASTER_COUNT}** sites; batches **A {A0_BATCH_COUNTS['A']} / B {A0_BATCH_COUNTS['B']} / C {A0_BATCH_COUNTS['C']}**; A1/A2/A3 **9/20/22**; hash `{A0_SITE_SET_HASH}`.",
        "- Progressive checkpoint: **Batch A/B accepted; Batch-C C1 consumer authority migrated; C2-C4 remain allocated and Batch C is semantically unaccepted**.",
        f"- Frozen WU2B0 Batch-B baseline: accepted-A source `{B0_ACCEPTED_A_SOURCE}`; **{B0_BATCH_B_COUNT}** sites; B1/B2/B3 **{B0_BATCH_B_REQUIRE['B1']}/{B0_BATCH_B_REQUIRE['B2']}/{B0_BATCH_B_REQUIRE['B3']}**; hash `{B0_BATCH_B_SITE_SET_HASH}`.",
        f"- Result: **{'PASS' if not errors else 'FAIL'}**",
        f"- Master `.index()` occurrences: **{len(sites)} / {EXPECTED_MASTER_COUNT}**",
        f"- Master occurrence files: **{len(file_counts)} / {EXPECTED_OCCURRENCE_FILE_COUNT}**",
        f"- Master site-set SHA-256: `{current_site_hash}`",
        f"- Batch A: **{routed['A']} / {EXPECTED_BATCH_COUNTS['A']}**",
        f"- Batch B: **{routed['B']} / {EXPECTED_BATCH_COUNTS['B']}**",
        f"- Batch C: **{routed['C']} / {EXPECTED_BATCH_COUNTS['C']}**",
        "",
        "## Batch A classification",
        "",
        f"- N found: **{len(a_sites)}**",
        f"- N classified: **{len(a_sites) - len(a_unclassified)}**",
        f"- K requiring change: **{a_classes['requires-A1'] + a_classes['requires-A2'] + a_classes['requires-A3']}**",
        f"- A1 remaining allocation: **{a_classes['requires-A1']}** (expected 0; frozen 9 migrated)",
        f"- A2 allocation: **{a_classes['requires-A2']}**",
        f"- A3 allocation: **{a_classes['requires-A3']}**",
        f"- Allowed direct container leaves: **{a_classes['allowed-direct-container-leaf']}**",
        f"- Allowed one-way diagnostics: **{a_classes['allowed-one-way-diagnostic']}**",
        f"- Allowed one-way exports: **{a_classes['allowed-one-way-export']}**",
        (
            "- Unallocated Batch-A sites: **0**"
            if not a_unclassified
            else f"- Unallocated Batch-A sites: **{len(a_unclassified)}**"
        ),
        "",
        "## Batch B classification",
        "",
        f"- N found: **{len(b_sites)}**",
        f"- N classified: **{len(b_sites) - len(b_unclassified)}**",
        f"- K requiring change: **{b_classes['requires-B1'] + b_classes['requires-B2'] + b_classes['requires-B3']}**",
        f"- B1 allocation: **{b_classes['requires-B1']}**",
        f"- B2 allocation: **{b_classes['requires-B2']}**",
        f"- B3 allocation: **{b_classes['requires-B3']}**",
        f"- Allowed direct container leaves: **{b_classes['allowed-direct-container-leaf']}**",
        f"- Allowed one-way diagnostics: **{b_classes['allowed-one-way-diagnostic']}**",
        f"- Allowed one-way exports: **{b_classes['allowed-one-way-export']}**",
        f"- Batch-B site-set SHA-256: `{b_site_hash}`",
        (
            "- Unallocated Batch-B sites: **0**"
            if not b_unclassified
            else f"- Unallocated Batch-B sites: **{len(b_unclassified)}**"
        ),
        "",
        "## Deferred-blocker exposure",
        "",
        "- `G4-B001`: **NO** — source/static census and typed authority contracts do not require produced torus/periodic execution.",
        "- `G4-B002`: **NO** — no produced hard-rail pairing witness is required.",
        "- `G4-B003`: **NO** — no nonzero periodic runtime witness is required.",
        "- `G4-B004`: **NO** — no positive multi-isolation runtime witness is required.",
        "- New produced-witness debt: **0**; existing priced debt remains **3**.",
        "",
        "## Current Batch-A sites",
        "",
    ]
    for site in a_sites:
        classification = classify_a(site.path, site.line) or "UNCLASSIFIED"
        lines.append(
            f"- `{site.path}:{site.line}:{site.occurrence}` — "
            f"**{classification}** — `{site.text}`"
        )

    lines.extend(["", "## Current Batch-B sites", ""])
    for site in b_sites:
        classification = classify_b(site.path, site.line) or "UNCLASSIFIED"
        lines.append(
            f"- `{site.path}:{site.line}:{site.occurrence}` — "
            f"**{classification}** — `{site.text}`"
        )

    lines.extend(["", "## Master per-file counts", ""])
    for path, count in sorted(file_counts.items()):
        lines.append(
            f"- `{path}` — {count} — batch **{batch_for(path) or 'UNOWNED'}**"
        )

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
        failures = classifier_self_test()
        if failures:
            for failure in failures:
                print(f"FAIL: {failure}")
            return 1
        print("PASS: work-unit-2 progressive classifier self-tests")
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
