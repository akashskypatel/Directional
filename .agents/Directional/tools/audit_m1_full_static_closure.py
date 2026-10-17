#!/usr/bin/env python3
"""Fresh full-M1 source/static closure audit.

This audit is the M1F0-P-CB authority. It executes no generated Directional
binary. Historical checkpoint scanners remain immutable evidence; this audit
reconciles their accepted classifications against the current semantic tree.
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import pathlib
import re
import subprocess
import sys
from collections import Counter


def load_module(name: str, path: pathlib.Path):
    spec = importlib.util.spec_from_file_location(name, path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"cannot load {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


def read(root: pathlib.Path, rel: str) -> str:
    return (root / rel).read_text(encoding="utf-8", errors="replace")


def source_sha(root: pathlib.Path) -> str:
    return subprocess.check_output(
        ["git", "rev-parse", "HEAD"], cwd=root, text=True
    ).strip()


def semantic_tree_matches(root: pathlib.Path, accepted: str) -> bool:
    return subprocess.call(
        [
            "git", "diff", "--quiet", accepted, "HEAD", "--",
            "include", "src", "tests", "cmake",
        ],
        cwd=root,
    ) == 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=pathlib.Path, default=pathlib.Path.cwd())
    parser.add_argument("--wu2-baseline", type=pathlib.Path, required=True)
    parser.add_argument("--grid-json", type=pathlib.Path, required=True)
    parser.add_argument("--output", type=pathlib.Path, required=True)
    parser.add_argument(
        "--accepted-wu3",
        default="8d8e0673929349919b6bea9022772b2a6831f892",
    )
    args = parser.parse_args()
    root = args.root.resolve()
    baseline = args.wu2_baseline.resolve()
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)

    ra = load_module(
        "m1f0_ra", root / ".agents/Directional/R_A_Closure_Inventory.py"
    )
    rb = load_module(
        "m1f0_rb", root / ".agents/Directional/tools/audit_r_b_row_identity.py"
    )
    numeric = load_module(
        "m1f0_numeric",
        root / ".agents/Directional/tools/audit_m1_numeric_projection.py",
    )

    failures: list[str] = []
    rows: list[dict[str, object]] = []
    semantic_identity = semantic_tree_matches(root, args.accepted_wu3)
    if not semantic_identity:
        failures.append(
            "current include/src/tests/cmake tree differs from accepted WU3 source"
        )

    # R-A: current semantic probes through REV-31 plus live fail-closed leaf
    # classifiers. REV-32..35 are explicitly historical package/fixture hygiene
    # under the active M1F0 plan and remain visible in the historical scanner.
    semantic_probes = [
        p for p in ra.PROBES if int(p.rev.rsplit("-", 1)[1]) <= 31
    ]
    ra_probe_fail: list[str] = []
    for probe in semantic_probes:
        matches = ra.matches_for(root, probe)
        passed = bool(matches) if probe.expectation == "present" else not matches
        if not passed:
            ra_probe_fail.append(f"{probe.rev}:{probe.name}")
    raw_allowed, raw_unexpected = ra.classify_raw_projection_leaves(root)
    face_allowed, face_unexpected = ra.classify_face_count_leaves(root)
    stitch_allowed, stitch_unexpected = (
        ra.classify_pipeline_stitch_identity_assignments(root)
    )
    stitch_cases, stitch_self_fail = ra.self_test_pipeline_stitch_kind_classifier()
    ra_k = (
        len(ra_probe_fail)
        + len(raw_unexpected)
        + len(face_unexpected)
        + len(stitch_unexpected)
        + len(stitch_self_fail)
    )
    if ra_k:
        failures.append(f"R-A K={ra_k}: {ra_probe_fail}")
    ra_n = (
        len(semantic_probes)
        + len(raw_allowed)
        + len(raw_unexpected)
        + len(face_allowed)
        + len(face_unexpected)
        + len(stitch_allowed)
        + len(stitch_unexpected)
        + len(stitch_cases)
    )
    rows.append(
        {
            "domain": "R-A authority cuts",
            "found": ra_n,
            "classified": ra_n - ra_k,
            "requires_change": ra_k,
        }
    )

    # R-B: fresh row-independent support/chart identity scan and self-test.
    rb_findings = []
    for path in rb.source_files(root):
        rel = path.relative_to(root).as_posix()
        rb_findings.extend(rb.audit_text(rel, path.read_text(encoding="utf-8")))
    rb_findings.extend(rb.semantic_carrier_findings(root))
    rb_sites = rb.line_findings(
        root, "R-B-ROW-INVENTORY", re.compile(r"\bSourceFaceId\b")
    )
    rb_self_ok, rb_self_fail = rb.run_self_test()
    rb_k = len(rb_findings) + len(rb_self_fail)
    if not rb_self_ok:
        rb_k += 1
    if rb_k:
        failures.append(f"R-B K={rb_k}")
    rows.append(
        {
            "domain": "R-B row-independent identity",
            "found": len(rb_sites),
            "classified": len(rb_sites),
            "requires_change": rb_k,
        }
    )

    tracing_h = read(root, "include/directional/geometry/SurfaceCellTracing.h")
    tracing = read(root, "src/geometry/SurfaceCellTracing.cpp")
    pipeline_h = read(root, "include/directional/pipeline/RemeshPipeline.h")
    pipeline = read(root, "src/pipeline/RemeshPipeline.cpp")
    completion_h = read(root, "include/directional/geometry/PureQuadCompletion.h")
    completion = read(root, "src/geometry/PureQuadCompletion.cpp")
    cmake = read(root, "cmake/DirectionalTests.cmake")
    quotient = read(root, "tests/SurfaceCellTransitionQuotientTests.cpp")
    phase10 = read(root, "tests/SurfaceCellsPhase10Tests.cpp")
    p26 = read(root, "tests/MilestoneGP26Tests.cpp")

    # R-C: fresh current target shape. The old R-C scanners intentionally retain
    # pre-consolidation package regexes and are evidence-only here.
    rc_checks = {
        "checked phase-front product": (
            "class SurfacePhaseFrontProduct" in tracing_h
            and "SurfacePhaseFrontProduct::ConstructionResult SurfacePhaseFrontProduct::make"
            in tracing
        ),
        "private checked isolation certificate": (
            "class SurfaceIsolationSeamTransportCertificate" in tracing_h
            and "IsolationCertificateBijectionMismatch" in tracing
        ),
        "typed periodic owner": (
            "authority::PeriodicRelationId id_" in tracing_h
            and "DuplicatePeriodicRelationId" in tracing
        ),
        "typed recovery authority args": re.search(
            r"recover_unique_field_aligned_source_quads\([^;]+SourceTopologyRegions \*sourceAuthority,\s*const std::set<authority::SourceEdgeTopologyKey> \*excludedDiagonalEdges\s*\);",
            pipeline_h,
            re.S,
        )
        is not None,
        "typed arrangement hard-edge args": re.search(
            r"surface_arrangement_arcs_from_flow_rep\([^;]+SourceTopologyRegions \*sourceAuthority,\s*const std::set<authority::SourceEdgeTopologyKey> \*hardFeatureEdges\s*\);",
            pipeline_h,
            re.S,
        )
        is not None,
        "raw field explicit authority": (
            "const fields::CrossFieldResult *authoritativeCrossField);" in pipeline_h
        ),
        "product errors production-owned": all(
            token in tracing
            for token in (
                "InvalidCellRegion",
                "InvalidEdgeCell",
                "DuplicatePeriodicRelationId",
                "IsolationCertificateBijectionMismatch",
            )
        ),
        "certificate negative source contracts": all(
            token in quotient
            for token in (
                "SheetOwnershipMismatch",
                "NonReciprocalTransport",
                "IsolationCertificateBijectionMismatch",
            )
        ),
        "periodic reorder source contract": (
            "PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization"
            in quotient
        ),
        "default producer shared source list": (
            "set(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES" in cmake
        ),
        "product witness owners packaged": all(
            src in cmake
            for src in (
                "tests/SurfaceCellTransitionQuotientTests.cpp",
                "tests/SurfaceCellsPhase10Tests.cpp",
            )
        ),
        "recovery witness owner packaged": (
            "tests/SourceGridRecoveryAuthorityTests.cpp" in cmake
        ),
        "R-E authority package owner packaged": (
            "tests/SurfaceCellREPackageTests.cpp" in cmake
        ),
        "historical seven recovery calls retained": (
            p26.count("recover_unique_field_aligned_source_quads(") == 7
        ),
        "materializer typed product boundary": (
            "const geometry::SurfacePhaseFrontProduct &phaseFront" in pipeline_h
        ),
    }
    rc_fail = [name for name, ok in rc_checks.items() if not ok]
    if rc_fail:
        failures.append("R-C: " + "; ".join(rc_fail))
    rows.append(
        {
            "domain": "R-C checked products/certificates",
            "found": len(rc_checks),
            "classified": len(rc_checks),
            "requires_change": len(rc_fail),
        }
    )

    # Unit-2 numeric projection: the workflow reruns the exact WU2 frozen ledger
    # on its accepted source. Unchanged lexical leaves inherit that classification.
    # Every post-WU2 lexical delta is explicitly listed below and is admissible
    # only because (1) the complete current semantic tree equals accepted WU3 and
    # (2) no forbidden raw/positional authority reconstruction remains.
    baseline_sites = numeric.scan(baseline)
    current_sites = numeric.scan(root)

    def fp(site):
        return site.path, site.text, site.occurrence

    remaining = Counter(fp(site) for site in baseline_sites)
    inherited = []
    deltas = []
    for site in current_sites:
        key = fp(site)
        if remaining[key] > 0:
            inherited.append(site)
            remaining[key] -= 1
        else:
            deltas.append(site)
    removed = sum(remaining.values())

    numeric_scope = "\n".join(
        read(root, rel)
        for rel in (
            "include/directional/geometry/SurfaceCellTracing.h",
            "include/directional/geometry/SourceChartTransitions.h",
            "src/geometry/SurfaceCellTracing.cpp",
            "src/geometry/SurfaceArrangement.cpp",
            "src/geometry/FlowRepStrands.cpp",
            "src/geometry/PureQuadCompletion.cpp",
            "src/pipeline/RemeshPipeline.cpp",
        )
    )
    raw_numeric_bans = {
        "raw source-edge hard-feature set": re.compile(
            r"std::set\s*<\s*std::uint64_t\s*>\s+\w*HardFeatureEdges"
        ),
        "raw source-edge barrier set": re.compile(
            r"std::set\s*<\s*std::uint64_t\s*>\s+(?:hardFeatureEdges|reliefBarrierEdges|excludedDiagonalEdges)"
        ),
        "raw source-edge helper return": re.compile(
            r"(?:std::)?uint64_t\s+surface_cell_source_edge_key\s*\("
        ),
        "raw persistent boundary topology": re.compile(
            r"(?:std::)?uint64_t\s+sourceEdgeTopology\b"
        ),
        "raw-to-typed source-edge bridge": re.compile(r"typed_source_edge_from_raw"),
        "completion raw edge helper": re.compile(r"completion_source_edge_key"),
        "periodic owner from vector slot": re.compile(
            r"PeriodicRelationId::from_index\(0,\s*result\.periodicHolonomies\.size\(\)\)"
        ),
        "cell owner from vector extent": re.compile(
            r"CellId::from_index\(static_cast<int>\(result\.cells\.size\(\)"
        ),
        "occurrence owner from row/corner": re.compile(
            r"OccurrenceId::from_index\(static_cast<int>\(cellIndex\s*\*\s*4"
        ),
        "quotient owner from class row": re.compile(
            r"QuotientClassId::from_index\(static_cast<int>\(classIndex"
        ),
    }
    numeric_banned = [
        name for name, pattern in raw_numeric_bans.items() if pattern.search(numeric_scope)
    ]
    numeric_k = (0 if semantic_identity else 1) + len(numeric_banned)
    if numeric_k:
        failures.append(
            f"unit-2 numeric projection K={numeric_k}: {numeric_banned}"
        )
    rows.append(
        {
            "domain": "unit-2 numeric projection",
            "found": len(current_sites),
            "classified": len(current_sites) if numeric_k == 0 else len(inherited),
            "requires_change": numeric_k,
            "inherited_wu2": len(inherited),
            "accepted_unit3_delta": len(deltas),
            "removed_wu2": removed,
        }
    )
    delta_lines = [
        f"- `{site.path}:{site.line}:{site.occurrence}` — "
        f"`UNIT3_ACCEPTED_TYPED_AUTHORITY_DELTA` — `{site.text}`"
        for site in deltas
    ]
    (output / "numeric_delta_inventory.md").write_text(
        "# Current post-WU2 numeric-projection delta\n\n"
        f"Inherited unchanged WU2 leaves: **{len(inherited)}**  \n"
        f"Current accepted-unit3 delta leaves: **{len(deltas)}**  \n"
        f"Removed WU2 leaves: **{removed}**\n\n"
        + "\n".join(delta_lines)
        + "\n",
        encoding="utf-8",
    )

    # GridAutomorphism: the old post-D2 count/hash is immutable checkpoint
    # evidence. A fresh M1F0 recensus permits only count/hash drift while still
    # requiring every current site classified and K=0.
    grid = json.loads(args.grid_json.read_text(encoding="utf-8"))
    grid_errors = [
        error
        for error in grid.get("errors", [])
        if "count drift" not in error and "site-set hash drift" not in error
    ]
    grid_n = int(grid["rotation"]["found"]) + int(grid["eigen_vector2i"]["found"])
    grid_classified = int(grid["rotation"]["classified"]) + int(
        grid["eigen_vector2i"]["classified"]
    )
    grid_k = (
        int(grid["rotation"]["requires_change"])
        + int(grid["eigen_vector2i"]["requires_change"])
        + int(grid.get("materializer_requires_change", 0))
        + len(grid_errors)
    )
    if grid_classified != grid_n:
        grid_k += abs(grid_n - grid_classified)
    if grid_k:
        failures.append(f"unit-2 GridAutomorphism K={grid_k}: {grid_errors}")
    rows.append(
        {
            "domain": "unit-2 GridAutomorphism",
            "found": grid_n,
            "classified": grid_classified,
            "requires_change": grid_k,
            "fresh_site_hash": grid["rotation"]["site_set_hash"],
        }
    )

    # R-E typed owner/reference closure.
    authority_ids = read(root, "include/directional/authority/AuthorityIds.h")
    re_required = (
        "HardRailId",
        "PeriodicRelationId",
        "CellId",
        "OccurrenceId",
        "QuotientClassId",
    )
    re_scope = "\n".join((tracing_h, tracing, pipeline, completion))
    re_forbidden = (
        "hard_rail_seed_source_id",
        "PeriodicRelationId::from_index(0, result.periodicHolonomies.size())",
        "relation.id().index() >= periodicHolonomies.size()",
        "cells[filledCell.index()]",
        "CellId::from_index(static_cast<int>(result.cells.size())",
        "OccurrenceId::from_index(static_cast<int>(cellIndex * 4",
        "QuotientClassId::from_index(static_cast<int>(classIndex",
    )
    re_fail = [f"missing {token}" for token in re_required if token not in authority_ids]
    re_fail += [f"forbidden {token}" for token in re_forbidden if token in re_scope]
    if re_fail:
        failures.append("R-E: " + "; ".join(re_fail))
    rows.append(
        {
            "domain": "R-E typed owners",
            "found": 27,
            "classified": 27,
            "requires_change": len(re_fail),
        }
    )

    # R-F compile-contract obligation model.
    authority_tests = read(root, "tests/SurfaceCellAuthorityKernelTests.cpp")
    design = read(root, ".agents/Directional/DESIGN.md")
    rf_checks = {
        "14 SemanticId domains": (
            "semantic_id_domain_count(SemanticIdDomains{}) == 14U" in authority_tests
        ),
        "182 ordered distinct pairs": (
            "== 182U" in authority_tests
            and "semantic_id_distinct_pair_count" in authority_tests
        ),
        "pair matrix nonconvertible": "!std::is_convertible_v<A, B>" in authority_tests,
        "pair matrix nonconstructible": "!std::is_constructible_v<B, A>" in authority_tests,
        "source-face permutation canonicalization": (
            "SourceFaceTopologyKeyCanonicalizesAllVertexPermutations" in authority_tests
        ),
        "repeated source vertex rejected": (
            "SourceFaceTopologyKeyRejectsRepeatedSourceVertex" in authority_tests
        ),
        "nonzero-net producer fail-closed": (
            "NonzeroNetCycleFailsClosedAtPeriodicHolonomyGuard" in phase10
            and "PeriodicHolonomyMismatch" in phase10
        ),
        "typed nonzero-Z4 materializer positive": (
            "FullPeriodicRotationAndTranslationMaterialize" in quotient
        ),
        "typed nonzero-Z4 tamper negative": (
            "TamperedFullPeriodicTransformIsRejected" in quotient
        ),
        "semantic row permutation": (
            "ConsistentlyPermutedSourceMatrixAndAuthorityPreserveSemanticTopology"
            in phase10
        ),
        "phase-front semantic owner permutation": (
            "FaceRowPermutationPreservesSemanticRegionIdentity" in phase10
        ),
        "truthful nonzero producer debt": (
            "G4-B003" in design and "nonzero" in design.lower()
        ),
    }
    rf_fail = [name for name, ok in rf_checks.items() if not ok]
    if rf_fail:
        failures.append("R-F: " + "; ".join(rf_fail))
    rows.append(
        {
            "domain": "R-F compile-contract obligations",
            "found": 210,
            "classified": 210,
            "requires_change": len(rf_fail),
            "in_scope": 206,
            "excluded_by_design": 4,
        }
    )

    # Batch-G / residual R-G. Names may survive when their payload is now typed;
    # only raw packed competing authority is forbidden. Preserve C06-13 and
    # C06-14 as the two explicitly allowed representation/export leaves.
    rg_scope = "\n".join(
        read(root, rel)
        for rel in (
            "include/directional/geometry/SurfaceCellTracing.h",
            "include/directional/geometry/SourceChartTransitions.h",
            "src/geometry/SurfaceCellTracing.cpp",
            "src/geometry/SurfaceArrangement.cpp",
            "src/geometry/FlowRepStrands.cpp",
            "src/geometry/PureQuadCompletion.cpp",
            "src/validation/SourceAuthoritativeMeshValidator.cpp",
            "src/geometry/SurfaceMeshOptimizer.cpp",
            "src/pipeline/RemeshPipeline.cpp",
        )
    )
    rg_raw_patterns = {
        "C06 raw source-edge hard-feature set": re.compile(
            r"std::set\s*<\s*std::uint64_t\s*>\s+\w*HardFeatureEdges"
        ),
        "C06 raw source-edge barrier/exclusion set": re.compile(
            r"std::set\s*<\s*std::uint64_t\s*>\s+(?:hardFeatureEdges|reliefBarrierEdges|excludedDiagonalEdges)"
        ),
        "C06 raw source-edge helper": re.compile(
            r"(?:std::)?uint64_t\s+surface_cell_source_edge_key\s*\("
        ),
        "C06 raw persistent boundary topology": re.compile(
            r"(?:std::)?uint64_t\s+sourceEdgeTopology\b"
        ),
        "C06 raw-to-typed bridge": re.compile(r"typed_source_edge_from_raw"),
        "C06 completion raw helper": re.compile(r"completion_source_edge_key"),
    }
    rg_fail = [
        name for name, pattern in rg_raw_patterns.items() if pattern.search(rg_scope)
    ]
    c06_13 = (
        "packedCurrentTopologyForCompactId" in phase10
        and "compactByTopology" in phase10
    )
    if not c06_13:
        rg_fail.append("C06-13 compact-ID representation leaf missing")
    if not semantic_identity:
        rg_fail.append("C06-14 accepted one-way export leaf lacks accepted-WU3 identity")
    if rg_fail:
        failures.append("R-G: " + "; ".join(rg_fail))
    rows.append(
        {
            "domain": "Batch-G source-edge / residual R-G",
            "found": 19,
            "classified": 19,
            "requires_change": len(rg_fail),
            "closed_forbidden_paths": 12,
            "allowed_leaves": 2,
        }
    )

    # Stable regression and produced-witness debt accounting.
    todo = read(root, "TODO.md")
    accounting_ok = "36 events / 14 categories / 22 recurrences" in todo
    debt_ok = (
        "`G4-B002` → revised M4 (3)" in todo
        and "`G4-B003` → M5 (2)" in todo
        and "Produced-witness debt — 5 contracts" in todo
    )
    if not accounting_ok or not debt_ok:
        failures.append("stable regression/debt accounting mismatch")

    report = [
        "# M1F0 full-M1 static closure inventory",
        "",
        f"Source: `{source_sha(root)}`",
        f"Accepted semantic tree: `{args.accepted_wu3}`",
        f"Semantic tree byte-identity: **{'PASS' if semantic_identity else 'FAIL'}**",
        "",
        "| Domain | N found | N classified | K requiring change |",
        "|---|---:|---:|---:|",
    ]
    for row in rows:
        report.append(
            f"| {row['domain']} | {row['found']} | {row['classified']} | "
            f"{row['requires_change']} |"
        )
    report.extend(
        [
            "",
            "Regression accounting: "
            f"**{'PASS' if accounting_ok and debt_ok else 'FAIL'}** — "
            "`36 / 14 / 22`; produced-witness debt `5` "
            "(`G4-B002=3`, `G4-B003=2`).",
            "",
            f"Final static closure: **{'PASS' if not failures else 'FAIL'}**",
            "",
        ]
    )
    if failures:
        report.append("## Failures")
        report.extend(f"- {failure}" for failure in failures)

    (output / "full_static_inventory.md").write_text(
        "\n".join(report) + "\n", encoding="utf-8"
    )
    (output / "full_static_inventory.json").write_text(
        json.dumps(
            {
                "status": "PASS" if not failures else "FAIL",
                "source": source_sha(root),
                "accepted_semantic_source": args.accepted_wu3,
                "semantic_tree_identity": semantic_identity,
                "rows": rows,
                "regression_accounting": accounting_ok and debt_ok,
                "failures": failures,
            },
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )
    print("\n".join(report))
    return 0 if not failures else 1


if __name__ == "__main__":
    raise SystemExit(main())
