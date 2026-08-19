#!/usr/bin/env python3
"""M1 Batch-D grid-automorphism transform census/classifier.

Source-only audit. It never executes a Directional binary.

D0 froze the exact accepted-post-C source census. D1 changes that source surface,
so the audit keeps the D0 baseline immutable while also recognizing the exact
post-D1 tracing cutover. Classification is semantic/pattern-based rather than
line-number based so source edits do not silently move debt between buckets.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
import sys
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

ACCEPTED_C_SOURCE = "d0f14508d59f4ea4d38b4db7b3904de239a6b555"

BATCH_D_FILES = (
    "include/directional/authority/GridAutomorphism.h",
    "include/directional/diagnostics/RemeshDiagnostics.h",
    "include/directional/geometry/SurfaceCellTracing.h",
    "src/bench/BenchmarkQuality.cpp",
    "src/bench/DirectionalBenchmark.cpp",
    "src/geometry/SurfaceCellTracing.cpp",
    "src/pipeline/RemeshPipeline.cpp",
    "tests/SurfaceCellAuthorityKernelTests.cpp",
    "tests/SurfaceCellTransitionQuotientTests.cpp",
    "tests/SurfaceCellsPhase10Tests.cpp",
)

TRANSFORM_TERM = re.compile(
    r"(QuarterTurn|quarterTurn|quarter_turn|quarter-turn|branchRotation|"
    r"signedQuarterTurn|normalized_rotation|rotate_lattice|inverseRotation|"
    r"rotation\.value\s*\(|action\s*\(\s*\)\.rotation|\.rotation\b|"
    r"quarterTurnRotation)",
    re.IGNORECASE,
)
MODULO_TERM = re.compile(r"(%\s*4\b|&\s*3\b)")
VECTOR2I_TERM = re.compile(r"\bEigen::Vector2i\b")

# Immutable D0 accepted-C census.
D0_ROTATION_SCREEN_COUNT = 216
D0_ROTATION_FILE_COUNT = 10
D0_ROTATION_SITE_SET_HASH = (
    "7c16533316cbd70675b8bbaa2b3e3ab4fe51ac9fd2fb9873ddc586213a8009b8"
)
D0_VECTOR2I_COUNT = 25
D0_VECTOR2I_FILE_COUNT = 3
D0_VECTOR2I_SITE_SET_HASH = (
    "2285b6d34b6edbafa0d818f6676e25b28d13b489f3c5432fb615bed5309742df"
)

# Exact source surface after WU2D1 tracing cutover plus its bounded compile
# boundary bridge into the still-raw D2 materializer. D2 is expected to change
# these values again and must deliberately advance this stage contract.
D1_ROTATION_SCREEN_COUNT = 220
D1_ROTATION_FILE_COUNT = 10
D1_ROTATION_SITE_SET_HASH = (
    "b1242bdeb58e1ebbe6e4cc5a557d112f8ba09e02d97e80953b4c8cba50aecdcb"
)
D1_VECTOR2I_COUNT = 8
D1_VECTOR2I_FILE_COUNT = 1
D1_VECTOR2I_SITE_SET_HASH = (
    "19d8327c42f07229d205a4a16cc3c9837942ab26c569d444dab0e828ffcc066f"
)

# Exact source surface after WU2D2 materializer cutover. D2 removes the raw
# modulo/Eigen materializer action and leaves only typed transform authority
# plus verified one-way diagnostic/export projections.
D2_ROTATION_SCREEN_COUNT = 213
D2_ROTATION_FILE_COUNT = 10
D2_ROTATION_SITE_SET_HASH = (
    "0f69009a0af17de7ec8fa872b036da4660e5f0dc0e51484782e6ec4551860e77"
)
D2_VECTOR2I_COUNT = 0
D2_VECTOR2I_FILE_COUNT = 0
D2_VECTOR2I_SITE_SET_HASH = (
    "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
)


@dataclass(frozen=True)
class Site:
    path: str
    line: int
    text: str

    @property
    def key(self) -> str:
        return f"{self.path}:{self.line}"


def _read_sites(root: Path) -> tuple[list[Site], list[Site]]:
    rotation_sites: list[Site] = []
    vector_sites: list[Site] = []
    for relative in BATCH_D_FILES:
        path = root / relative
        if not path.is_file():
            raise RuntimeError(f"missing Batch-D file: {relative}")
        for line_no, text in enumerate(
            path.read_text(encoding="utf-8", errors="replace").splitlines(), start=1
        ):
            if TRANSFORM_TERM.search(text) or MODULO_TERM.search(text):
                rotation_sites.append(Site(relative, line_no, text.rstrip()))
            if VECTOR2I_TERM.search(text):
                vector_sites.append(Site(relative, line_no, text.rstrip()))
    return rotation_sites, vector_sites


def _pipeline_rotation_class(site: Site) -> str:
    # One-way telemetry/export is not semantic transform authority.
    if (
        "surfaceCellPeriodicHolonomyQuarterTurnRotation" in site.text
        or "quarterTurnRotation" in site.text
        or "diagnosticQuarterTurn" in site.text
        or "action.rotation.value" in site.text
    ):
        return "allowed-one-way-diagnostic"

    # D2 owns the raw materializer action. These patterns describe its local
    # modulo/rotation helper and the typed-periodic-action -> raw helper seam.
    if (
        "normalized_rotation" in site.text
        or "rotate_lattice" in site.text
        or "inverseRotation" in site.text
        or "relation.action().rotation.value" in site.text
        or "inverseAction.rotation.value" in site.text
    ):
        return "requires-D2-materializer-transform"

    return "allowed-local-representation"


def _rotation_class(site: Site) -> str:
    if site.path == "include/directional/authority/GridAutomorphism.h":
        return "typed-authority"
    if site.path == "include/directional/diagnostics/RemeshDiagnostics.h":
        return "allowed-one-way-diagnostic"
    if site.path == "include/directional/geometry/SurfaceCellTracing.h":
        if "QuarterTurn" in site.text:
            return "typed-authority"
        return "allowed-local-representation"
    if site.path in {
        "src/bench/BenchmarkQuality.cpp",
        "src/bench/DirectionalBenchmark.cpp",
    }:
        return "allowed-one-way-diagnostic"
    if site.path == "src/geometry/SurfaceCellTracing.cpp":
        # Any surviving raw matching inverse is D1 debt. Other raw branch
        # arithmetic is local field/geometry representation, while QuarterTurn
        # use is typed authority at the tracing boundary.
        if "segment.matching" in site.text and "%" in site.text:
            return "requires-D1-tracing-transform"
        if "std::optional<int>" in site.text and "QuarterTurn" in site.text:
            return "requires-D1-tracing-transform"
        if "rotation.value" in site.text or "action.rotation" in site.text:
            return "allowed-typed-boundary-export"
        if "QuarterTurn" in site.text:
            return "typed-authority-boundary"
        return "allowed-local-representation"
    if site.path == "src/pipeline/RemeshPipeline.cpp":
        return _pipeline_rotation_class(site)
    if site.path.startswith("tests/"):
        return "allowed-test-contract-or-fixture"
    raise RuntimeError(f"unclassified rotation site: {site.key}: {site.text}")


def _vector_class(site: Site) -> str:
    if site.path in {
        "include/directional/geometry/SurfaceCellTracing.h",
        "src/geometry/SurfaceCellTracing.cpp",
    }:
        return "requires-D1-tracing-transform"
    if site.path == "src/pipeline/RemeshPipeline.cpp":
        return "requires-D2-materializer-transform"
    raise RuntimeError(f"unclassified Eigen::Vector2i site: {site.key}: {site.text}")


def _site_set_hash(sites: list[Site]) -> str:
    digest = hashlib.sha256()
    for site in sites:
        digest.update(site.key.encode("utf-8"))
        digest.update(b"\0")
        digest.update(site.text.encode("utf-8"))
        digest.update(b"\n")
    return digest.hexdigest()


def _git_head(root: Path) -> str:
    return subprocess.check_output(
        ["git", "-C", str(root), "rev-parse", "HEAD"], text=True
    ).strip()


def _tracing_cutover_errors(root: Path) -> list[str]:
    header = (root / "include/directional/geometry/SurfaceCellTracing.h").read_text(
        encoding="utf-8"
    )
    source = (root / "src/geometry/SurfaceCellTracing.cpp").read_text(
        encoding="utf-8"
    )

    required = {
        "typed lattice state": "authority::LatticeTranslation latticeCoordinate;" in header,
        "typed forward quarter turn":
            "std::optional<authority::QuarterTurn> forwardQuarterTurn;" in source,
        "typed reverse quarter turn":
            "std::optional<authority::QuarterTurn> reverseQuarterTurn;" in source,
        "typed forward candidate":
            "const authority::QuarterTurn candidateForward" in source,
        "typed reverse candidate":
            "const authority::QuarterTurn candidateReverse" in source,
        "exact inverse relation":
            "candidateReverse != candidateForward.inverse()" in source,
        "typed segment inverse":
            "authority::QuarterTurn::from_integer(segment.matching).inverse().value()"
            in source,
    }
    forbidden = {
        "tracing header Eigen::Vector2i": "Eigen::Vector2i" in header,
        "tracing source Eigen::Vector2i": "Eigen::Vector2i" in source,
        "raw forward quarter turn optional":
            "std::optional<int> forwardQuarterTurn" in source,
        "raw reverse quarter turn optional":
            "std::optional<int> reverseQuarterTurn" in source,
        "raw inverse-sum oracle":
            "normalized_branch(candidateForward + candidateReverse)" in source,
        "raw segment matching modulo inverse":
            "segment.matching = (4 - (segment.matching % 4) + 4) % 4" in source,
    }

    errors = [f"missing D1 tracing contract: {name}" for name, ok in required.items() if not ok]
    errors.extend(
        f"forbidden D1 tracing residual: {name}" for name, present in forbidden.items() if present
    )
    return errors


def _materializer_cutover_errors(root: Path) -> list[str]:
    pipeline = (root / "src/pipeline/RemeshPipeline.cpp").read_text(encoding="utf-8")

    required = {
        "typed materializer action parameter":
            "const authority::GridAutomorphism &action" in pipeline,
        "typed materializer lattice apply":
            "action.apply(first.latticeCoordinate)" in pipeline,
        "typed materializer branch composition":
            "compose(action.rotation," in pipeline,
        "typed forward materializer action":
            "action_matches(first.fromLattice, second.toLattice, action)" in pipeline,
        "typed inverse materializer action":
            "action_matches(first.fromLattice, second.toLattice, inverseAction)" in pipeline,
    }
    forbidden = {
        "raw normalized materializer rotation helper":
            "const auto normalized_rotation" in pipeline,
        "raw materializer lattice rotation helper":
            "const auto rotate_lattice" in pipeline,
        "raw materializer Eigen translation parameter":
            "const Eigen::Vector2i &translation" in pipeline,
        "raw materializer forward rotation extraction":
            "const int rotation =" in pipeline,
        "raw materializer inverse rotation extraction":
            "const int inverseRotation" in pipeline,
        "raw materializer forward Eigen translation":
            "const Eigen::Vector2i translation" in pipeline,
        "raw materializer inverse Eigen translation":
            "const Eigen::Vector2i inverseTranslation" in pipeline,
    }

    errors = [
        f"missing D2 materializer contract: {name}"
        for name, ok in required.items()
        if not ok
    ]
    errors.extend(
        f"forbidden D2 materializer residual: {name}"
        for name, present in forbidden.items()
        if present
    )
    return errors


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--json", action="store_true")
    parser.add_argument(
        "--allow-post-c-source",
        action="store_true",
        help="audit post-C source using the explicit current Batch-D stage contract",
    )
    args = parser.parse_args()

    root = args.root.resolve()
    rotation_sites, vector_sites = _read_sites(root)
    rotation_classifications = [(site, _rotation_class(site)) for site in rotation_sites]
    vector_classifications = [(site, _vector_class(site)) for site in vector_sites]

    rotation_counts = Counter(kind for _, kind in rotation_classifications)
    vector_counts = Counter(kind for _, kind in vector_classifications)
    rotation_files = {site.path for site in rotation_sites}
    vector_files = {site.path for site in vector_sites}
    rotation_hash = _site_set_hash(rotation_sites)
    vector_hash = _site_set_hash(vector_sites)

    rotation_k = sum(
        count for kind, count in rotation_counts.items() if kind.startswith("requires-")
    )
    vector_k = sum(
        count for kind, count in vector_counts.items() if kind.startswith("requires-")
    )
    tracing_k = (
        rotation_counts["requires-D1-tracing-transform"]
        + vector_counts["requires-D1-tracing-transform"]
    )
    materializer_k = (
        rotation_counts["requires-D2-materializer-transform"]
        + vector_counts["requires-D2-materializer-transform"]
    )

    head = _git_head(root)
    tracing_header = (
        root / "include/directional/geometry/SurfaceCellTracing.h"
    ).read_text(encoding="utf-8")
    pipeline_source = (root / "src/pipeline/RemeshPipeline.cpp").read_text(
        encoding="utf-8"
    )
    post_d1 = "authority::LatticeTranslation latticeCoordinate;" in tracing_header
    post_d2 = (
        post_d1
        and "const authority::GridAutomorphism &action" in pipeline_source
        and "action.apply(first.latticeCoordinate)" in pipeline_source
    )

    if post_d2:
        expected = {
            "stage": "post-D2",
            "rotation_count": D2_ROTATION_SCREEN_COUNT,
            "rotation_files": D2_ROTATION_FILE_COUNT,
            "rotation_hash": D2_ROTATION_SITE_SET_HASH,
            "vector_count": D2_VECTOR2I_COUNT,
            "vector_files": D2_VECTOR2I_FILE_COUNT,
            "vector_hash": D2_VECTOR2I_SITE_SET_HASH,
        }
    elif post_d1:
        expected = {
            "stage": "post-D1",
            "rotation_count": D1_ROTATION_SCREEN_COUNT,
            "rotation_files": D1_ROTATION_FILE_COUNT,
            "rotation_hash": D1_ROTATION_SITE_SET_HASH,
            "vector_count": D1_VECTOR2I_COUNT,
            "vector_files": D1_VECTOR2I_FILE_COUNT,
            "vector_hash": D1_VECTOR2I_SITE_SET_HASH,
        }
    else:
        expected = {
            "stage": "accepted-C-D0",
            "rotation_count": D0_ROTATION_SCREEN_COUNT,
            "rotation_files": D0_ROTATION_FILE_COUNT,
            "rotation_hash": D0_ROTATION_SITE_SET_HASH,
            "vector_count": D0_VECTOR2I_COUNT,
            "vector_files": D0_VECTOR2I_FILE_COUNT,
            "vector_hash": D0_VECTOR2I_SITE_SET_HASH,
        }

    errors: list[str] = []
    if len(rotation_sites) != expected["rotation_count"]:
        errors.append(
            f"rotation screen count drift for {expected['stage']}: "
            f"expected {expected['rotation_count']}, found {len(rotation_sites)}"
        )
    if len(rotation_files) != expected["rotation_files"]:
        errors.append(
            f"rotation file count drift for {expected['stage']}: "
            f"expected {expected['rotation_files']}, found {len(rotation_files)}"
        )
    if rotation_hash != expected["rotation_hash"]:
        errors.append(
            f"rotation site-set hash drift for {expected['stage']}: "
            f"expected {expected['rotation_hash']}, found {rotation_hash}"
        )
    if len(vector_sites) != expected["vector_count"]:
        errors.append(
            f"Eigen::Vector2i count drift for {expected['stage']}: "
            f"expected {expected['vector_count']}, found {len(vector_sites)}"
        )
    if len(vector_files) != expected["vector_files"]:
        errors.append(
            f"Eigen::Vector2i file count drift for {expected['stage']}: "
            f"expected {expected['vector_files']}, found {len(vector_files)}"
        )
    if vector_hash != expected["vector_hash"]:
        errors.append(
            f"Eigen::Vector2i site-set hash drift for {expected['stage']}: "
            f"expected {expected['vector_hash']}, found {vector_hash}"
        )

    if post_d1:
        errors.extend(_tracing_cutover_errors(root))
        if tracing_k != 0:
            errors.append(f"D1 tracing migration is incomplete: K={tracing_k}")
    if post_d2:
        errors.extend(_materializer_cutover_errors(root))
        if materializer_k != 0:
            errors.append(f"D2 materializer migration is incomplete: K={materializer_k}")
    elif post_d1 and materializer_k == 0:
        errors.append("D2 materializer debt disappeared before D2")

    if not args.allow_post_c_source and head != ACCEPTED_C_SOURCE:
        errors.append(
            f"source identity mismatch: expected accepted C {ACCEPTED_C_SOURCE}, found {head}"
        )

    result = {
        "status": "PASS" if not errors else "FAIL",
        "stage": expected["stage"],
        "source": head,
        "accepted_c_source": ACCEPTED_C_SOURCE,
        "rotation": {
            "found": len(rotation_sites),
            "classified": len(rotation_classifications),
            "files": len(rotation_files),
            "requires_change": rotation_k,
            "class_counts": dict(sorted(rotation_counts.items())),
            "site_set_hash": rotation_hash,
        },
        "eigen_vector2i": {
            "found": len(vector_sites),
            "classified": len(vector_classifications),
            "files": len(vector_files),
            "requires_change": vector_k,
            "class_counts": dict(sorted(vector_counts.items())),
            "site_set_hash": vector_hash,
        },
        "tracing_requires_change": tracing_k,
        "materializer_requires_change": materializer_k,
        "next_turn": (
            "WU2D1-P-CB"
            if tracing_k > 0
            else "WU2D2-P-CB"
            if materializer_k > 0
            else "WU2D-TB"
        ),
        "errors": errors,
    }

    if args.json:
        print(json.dumps(result, indent=2, sort_keys=True))
    else:
        print(f"stage={result['stage']}")
        print(
            "rotation="
            f"{result['rotation']['found']}/{result['rotation']['classified']}"
            f"/K{result['rotation']['requires_change']} "
            f"files={result['rotation']['files']} "
            f"hash={result['rotation']['site_set_hash']}"
        )
        for kind, count in result["rotation"]["class_counts"].items():
            print(f"  rotation {kind}={count}")
        print(
            "eigen_vector2i="
            f"{result['eigen_vector2i']['found']}/{result['eigen_vector2i']['classified']}"
            f"/K{result['eigen_vector2i']['requires_change']} "
            f"files={result['eigen_vector2i']['files']} "
            f"hash={result['eigen_vector2i']['site_set_hash']}"
        )
        for kind, count in result["eigen_vector2i"]["class_counts"].items():
            print(f"  eigen_vector2i {kind}={count}")
        print(f"tracing_K={tracing_k}")
        print(f"materializer_K={materializer_k}")
        print(f"next_turn={result['next_turn']}")
        print(f"status={result['status']}")
        for error in errors:
            print(f"ERROR: {error}")

    return 0 if not errors else 1


if __name__ == "__main__":
    sys.exit(main())
