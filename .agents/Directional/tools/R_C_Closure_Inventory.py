#!/usr/bin/env python3
"""Source-only R-C publication-contract audit.

This script checks the post-edit architecture only. It never executes a generated
Directional binary. Runtime semantic acceptance belongs to the following
artifact-only Test + Benchmark turn.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path


def read(root: Path, rel: str) -> str:
    return (root / rel).read_text(encoding="utf-8")


def check(name: str, condition: bool, failures: list[str]) -> None:
    print(f"{'PASS' if condition else 'FAIL'}: {name}")
    if not condition:
        failures.append(name)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path.cwd())
    args = parser.parse_args()
    root = args.root.resolve()
    header = read(root, "include/directional/geometry/SurfaceCellTracing.h")
    tracing = read(root, "src/geometry/SurfaceCellTracing.cpp")
    pipeline_h = read(root, "include/directional/pipeline/RemeshPipeline.h")
    pipeline = read(root, "src/pipeline/RemeshPipeline.cpp")
    completion_h = read(root, "include/directional/geometry/PureQuadCompletion.h")
    phase10 = read(root, "tests/SurfaceCellsPhase10Tests.cpp")
    quotient = read(root, "tests/SurfaceCellTransitionQuotientTests.cpp")
    p26 = read(root, "tests/MilestoneGP26Tests.cpp")

    failures: list[str] = []

    check("published phase-front product is a checked class",
          "class SurfacePhaseFrontProduct" in header and
          "static ConstructionResult" in header and
          "SurfacePhaseFrontProduct::ConstructionResult SurfacePhaseFrontProduct::make" in tracing,
          failures)
    check("published phase-front result exposes const payload only",
          "[[nodiscard]] Product *produced_product() noexcept" not in header and
          "[[nodiscard]] Product &product()" not in header and
          "const Product *produced_product() const noexcept" in header and
          "const Product &product() const" in header,
          failures)
    check("isolation certificate is private checked authority",
          "class SurfaceIsolationSeamTransportCertificate" in header and
          "make(const SourceTopologyRegions &sourceAuthority" in header and
          "SurfaceIsolationSeamTransportCertificateErrorCode" in header,
          failures)
    check("periodic relation owns explicit typed identity",
          "class SurfacePeriodicHolonomy" in header and
          "authority::PeriodicRelationId id_" in header and
          "SurfacePeriodicHolonomy::ConstructionResult SurfacePeriodicHolonomy::make" in tracing,
          failures)
    check("phase-front product validates periodic owner references",
          "DuplicatePeriodicRelationId" in tracing and
          "MissingPeriodicRelationOwner" in tracing and
          "InvalidPeriodicRelationOwner" in tracing,
          failures)
    check("materializer resolves periodic relations by typed ID",
          "periodicRelationById" in pipeline and
          not re.search(r"periodicHolonomies\(\)\s*\[\s*[^\]]*periodicRelation[^\]]*index", pipeline),
          failures)
    check("materializer accepts only typed published phase-front authority",
          re.search(r"build_authoritative_phase_front_mesh\s*\(\s*const Eigen::MatrixXd &sourceVertices,\s*const Eigen::MatrixXi &sourceFaces,\s*const geometry::SurfacePhaseFrontProduct &phaseFront\s*\)", pipeline_h, re.S) is not None,
          failures)
    check("published schema compile contracts are present",
          "decltype(std::declval<PhaseFrontResult &>().product())" in phase10 and
          "decltype(&directional::pipeline::build_authoritative_phase_front_mesh)" in phase10,
          failures)

    check("append_embedded_vertex source authority has no default",
          re.search(r"append_embedded_vertex\([^;]+const SourceTopologyRegions \*sourceAuthority\s*\);", completion_h, re.S) is not None and
          "const SourceTopologyRegions *sourceAuthority = nullptr" not in
              completion_h[completion_h.find("append_embedded_vertex"):completion_h.find("bool fill_positions")],
          failures)
    check("source-grid recovery mandatory authority arguments have no defaults",
          re.search(r"recover_unique_field_aligned_source_quads\([^;]+const geometry::SourceTopologyRegions \*sourceAuthority,\s*const std::set<std::uint64_t> \*excludedDiagonalEdges\s*\);", pipeline_h, re.S) is not None,
          failures)
    check("raw-cross-field implementation requires explicit authority choice",
          re.search(r"remesh_from_raw_cross_field_impl\([^;]+const fields::CrossFieldResult \*authoritativeCrossField\s*\);", pipeline_h, re.S) is not None,
          failures)
    check("arrangement conversion requires explicit source authority arguments",
          re.search(r"surface_arrangement_arcs_from_flow_rep\([^;]+const geometry::SourceTopologyRegions \*sourceAuthority,\s*const std::set<std::uint64_t> \*hardFeatureEdges\s*\);", pipeline_h, re.S) is not None,
          failures)
    check("historical recovery contracts pass production-shaped authority",
          p26.count("recover_unique_field_aligned_source_quads(") == 7 and
          p26.count("&sourceAuthority") >= 7 and
          p26.count("&no_recovery_excluded_edges()") >= 7,
          failures)

    check("certificate negative tests reject at factory boundary",
          "SheetOwnershipMismatch" in quotient and
          "NonReciprocalTransport" in quotient and
          "IsolationCertificateBijectionMismatch" in quotient,
          failures)
    check("periodic container reordering preserves typed owner IDs",
          "PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization" in quotient and
          "std::reverse(reordered.periodicHolonomies.begin()" in quotient,
          failures)

    print(f"summary: {15 - len(failures)}/15 checks passed")
    if failures:
        print("failures:")
        for failure in failures:
            print(f"- {failure}")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
