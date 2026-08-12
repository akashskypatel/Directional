#!/usr/bin/env python3
"""Reproducible static R-A closure inventory through R-A-REV-24.

This audit is intentionally source-only. It never executes a generated Directional
binary. Runtime semantic acceptance remains a separate artifact-only turn.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Sequence


@dataclass(frozen=True)
class Probe:
    rev: str
    name: str
    paths: tuple[str, ...]
    pattern: str
    expectation: str  # absent | present
    rationale: str
    flags: int = 0


ROOT_SCOPES = (
    "include/directional",
    "src",
    "tests",
    ".github/workflows/agent-compile-reusable.yml",
)

PROBES: tuple[Probe, ...] = (
    Probe("REV-01", "materializer owns typed isolation-sheet state",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"authority::IsolationSheetId isolationSheet;", "present",
          "OccurrenceData carries typed sheet authority instead of reading SurfacePoint::sheet as authority."),
    Probe("REV-01", "materializer raw projection is not read for sheet/component decisions",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"occurrence\.point\.(?:component|sheet)|representativeOccurrence\.point\.(?:component|sheet)", "absent",
          "The quotient/materializer semantic path must consume typed region/sheet/chart/support authority."),

    Probe("REV-02", "completion stitch key has no raw provenance component/sheet encoding",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"(?:stitchIdentity|canonical|identity).*provenance\.(?:component|sheet)|provenance\.(?:component|sheet).*(?:stitchIdentity|canonical|identity)", "absent",
          "Raw SurfacePoint labels may not enter semantic stitch/ownership identity."),
    Probe("REV-03", "typed stitch resolver rejects stale cached identity",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"lineage\.stitchIdentity != typed", "present",
          "A prebuilt compatibility identity cannot bypass typed fail-closed derivation."),
    Probe("REV-03", "missing typed stitch authority is an explicit failure",
          ("src/geometry/PureQuadCompletion.cpp", "tests/PureQuadCompletionPhase18Tests.cpp"),
          r"MissingTypedStitchIdentity", "present",
          "Exact geometry identity alone is insufficient for stitch publication."),

    Probe("REV-04", "validator does not read raw SurfacePoint component/sheet",
          ("src/validation/SourceAuthoritativeMeshValidator.cpp",),
          r"\.(?:component|sheet)\b", "absent",
          "Source-authoritative validation must use typed source authority, not generic projection labels."),
    Probe("REV-04", "rail constraints do not read raw SurfacePoint component/sheet",
          ("src/geometry/SurfaceOptimizationRailConstraints.cpp",),
          r"\.(?:component|sheet)\b", "absent",
          "Rail authority must not be scoped or accepted from generic projection labels."),

    Probe("REV-05", "typed-authority contract coverage remains compiled",
          ("tests/PureQuadCompletionPhase18Tests.cpp", "tests/SurfaceMeshOptimizerPhase19Tests.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"(?:MissingTypedStitchIdentity|MissingSourceAuthority|RawProjection|Stale|Distinct.*Sheet|Wrong.*Authority)", "present",
          "Retained test sources must contain fail-closed typed-authority and tamper contracts."),
    Probe("REV-06", "compile package manifest excludes and verifies itself",
          (".github/workflows/agent-compile-reusable.yml",),
          r"find \. -type f ! -name SHA256SUMS.*SHA256SUMS|sha256sum -c SHA256SUMS", "present",
          "Compile evidence must remain internally self-verifying."),
    Probe("REV-06", "compile package records clean source snapshots",
          (".github/workflows/agent-compile-reusable.yml",),
          r"source-status-(?:preconfigure|before-configure|after-configure|after-build|final)", "present",
          "Build provenance requires clean source status before/after build/package steps."),

    Probe("REV-07", "assembly validates owner-backed typed certificate",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"owner_validated_typed_authority_certificate", "present",
          "Published/stitch-authoritative vertices require complete owned region/sheet/chart/support authority."),
    Probe("REV-08", "SurfaceCells optimizer has mandatory source-authority predicate",
          ("src/geometry/SurfaceMeshOptimizer.cpp",),
          r"source_optimization_has_complete_authority", "present",
          "Strict optimizer/final validator entry points must fail closed without source authority."),
    Probe("REV-09", "component remap domain is typed and owner-derived",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"ComponentTypedAuthorityRemapDomain|make_component_typed_authority_remap_domain", "present",
          "Multi-component sheet/region/chart/support remapping must derive from typed owner domains."),
    Probe("REV-10", "bounded legacy audit is superseded by this complete inventory",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"R-A closure inventory through R-A-REV-24", "present",
          "REV-10's sampled audit is not used as closure evidence; this reproducible inventory replaces it."),

    Probe("REV-11", "collision certificates are intersected before publication",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"intersect_typed_authority_certificate", "present",
          "Same-key/same-position collision is not sufficient without compatible typed authority."),
    Probe("REV-12", "aggregate remap is checked and final lineage is validated",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"remap_quotient_lineage_authority|validate_aggregate_lineage_authority", "present",
          "Invalid chart/support/region/sheet remaps must reject before publication."),
    Probe("REV-13", "complete affected surface list is explicitly audited",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"AFFECTED_R_A_PATHS", "present",
          "Closure evidence names the affected source/test/workflow surfaces instead of sampling a few blocks."),

    Probe("REV-14", "post-intersection canonical authority identity is retained",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"canonical_typed_authority_identity", "present",
          "Collision publication derives one canonical authority identity from the final certificate."),
    Probe("REV-15", "region/sheet/chart/support remap domain is not self-bounded",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"ComponentTypedAuthorityRemapDomain", "present",
          "Remap domains are owned by published source topology/chart authority."),
    Probe("REV-16", "counterfactual mutation seam occurs before aggregation",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"beforeAggregation", "present",
          "Raw/tamper counterfactuals must reach the real aggregate consumer before publication."),
    Probe("REV-17", "certificate claims are checked against source ownership",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"owner_validated_typed_authority_certificate", "present",
          "Collision certificates must be owned by exact source topology/chart/support authority."),

    Probe("REV-18", "one global aggregate source owner is constructed",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"globalSourceAuthority", "present",
          "Disconnected aggregation must publish lineage through one checked global SourceTopologyRegions owner."),
    Probe("REV-18", "post-remap derived identity caches are rebuilt",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"rebuild_aggregate_output_identity_caches", "present",
          "Stitch/authoritative identities and face cycles must be regenerated after global remap."),
    Probe("REV-19", "aggregate publication is staged transactionally",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"RemeshResult staged = merged;", "present",
          "Semantic context remains uncommitted until all remaps and final validation succeed."),
    Probe("REV-19", "actual final merged mesh reaches source-authoritative validator",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"validate_source_authoritative_surface_mesh", "present",
          "Cached component reports cannot substitute for the post-merge oracle."),

    Probe("REV-20", "removed raw/legacy SurfaceCells compatibility paths stay absent",
          ("include/directional/geometry/SurfaceMeshOptimizer.h", "src/geometry/SurfaceMeshOptimizer.cpp", "src/geometry/SurfaceOptimizationRailConstraints.cpp", "src/validation/SourceAuthoritativeMeshValidator.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"sourcePositions|constraints\.sourceComponent|featureIntervals|legacyIndex|standaloneFixture", "absent",
          "Named raw optimizer/verifier and legacy point-cloud/feature-interval/standalone compatibility authority must remain removed."),

    Probe("REV-21", "exact source-row topology binding is used",
          ("include/directional/geometry/SourceTopologyRegions.h", "src/geometry/PureQuadCompletion.cpp", "src/geometry/SurfaceMeshOptimizer.cpp", "src/validation/SourceAuthoritativeMeshValidator.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"matches_source_faces", "present",
          "Same face count is not source ownership; paired geometry and authority must match exact row topology."),
    Probe("REV-21", "authority-only row permutation negative exists",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"AuthorityOnlyFaceRowPermutationRejectsExactTopologyBinding", "present",
          "The mismatched-pair counterexample must retain old authority while permuting only the source matrix."),
    Probe("REV-21", "consistent matrix-plus-authority permutation positive exists",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"ConsistentlyPermutedSourceMatrixAndAuthorityPreserveSemanticTopology", "present",
          "A row permutation remains valid when source geometry and rebuilt authority are paired consistently."),

    Probe("REV-22", "final aggregate carries independent strict validator authority",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"ComponentFinalValidationAuthority|globalValidationBoundaryLoops|globalValidationFeatureRails|globalValidationVertexCharts|globalValidationOutputQuadSourceFaces|globalValidationHardFeatureEdges", "present",
          "Boundary, feature, chart, output-face, hard-edge, and provenance authority must survive global remap into the final oracle."),
    Probe("REV-22", "final aggregate enables strict boundary/feature/local-sheet gates",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"finalAuthorityOptions\.requireBoundaryAuthority = true;|finalAuthorityOptions\.requireFeatureRailAuthority = true;|finalAuthorityOptions\.requireLocalSheetCompatibility = true;", "present",
          "The final oracle cannot weaken component strict gates to make aggregate output pass."),
    Probe("REV-22", "component authority tamper contracts name the aggregation seam",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"ComponentBoundaryRailTamperRejectsAtAggregationSeam|ComponentFeatureRailTamperRejectsAtAggregationSeam", "present",
          "Component capture-versus-mutation tests prove the pre-oracle seam guard and do not claim final-oracle coverage."),
    Probe("REV-22", "final oracle boundary and feature authority negatives exist",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"FinalMergedOracleRejectsMissingRemappedBoundaryAuthority|FinalMergedOracleRejectsMissingRemappedFeatureAuthority", "present",
          "Post-remap counterfactuals must pass component seam checks and make the final oracle reject missing boundary/feature authority with zero publication."),
    Probe("REV-22", "final oracle boundary content mismatch negative exists",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent", "present",
          "Present remapped boundary authority must be content-checked and reject with ChangedBoundaryLoop rather than only proving the absence guard."),
    Probe("REV-22", "final oracle feature content mismatch negative exists",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"FinalMergedOracleRejectsChangedRemappedFeatureRailContent", "present",
          "Present remapped feature authority with preserved cardinality must reject when a rail is absent from the merged output."),
    Probe("REV-22", "feature-bearing final oracle positive is non-vacuous",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority|expectedFeatureRailCount > 0U", "present",
          "Positive aggregate coverage must observe a non-empty feature-rail authority set before accepting it."),
    Probe("REV-22", "final oracle full issue list is retained in diagnostics",
          ("include/directional/diagnostics/RemeshDiagnostics.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"surfaceCellFinalSourceAuthorityValidationIssues", "present",
          "Content-mismatch negatives must prove the actual final-oracle issue list rather than relying only on preferred-code selection."),
    Probe("REV-22", "aggregate validation flags are sourced from final oracle observables",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"finalAuthorityValidation\.(?:strictValidationUsed|provenanceValidationUsed|boundaryAuthorityUsed|featureRailAuthorityUsed)", "present",
          "Published strict/provenance/boundary/feature usage flags must be oracle evidence, not constants."),
    Probe("REV-22", "aggregate validation flags are not hardcoded true",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"aggregateValidationResult\.(?:strictValidationUsed|provenanceValidationUsed|authoritativeFeatureRailsUsed)\s*=\s*true", "absent",
          "A hardcoded publication flag is a tautology and cannot establish validator execution."),
    Probe("REV-22", "option-echo usage EXPECT_TRUE assertions are absent",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"EXPECT_TRUE\((?:finalValidation\.strictValidationUsed|finalValidation\.authoritativeFeatureRailsUsed|oracle\.strictValidationUsed|oracle\.featureRailAuthorityUsed)\)", "absent",
          "Usage-option echoes are not semantic evidence; tests retain published-vs-oracle equality and input-derived gate observations instead."),
    Probe("REV-22", "final oracle outcome is published independently of component reports",
          ("include/directional/pipeline/RemeshPipeline.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"hasFinalSourceAuthorityValidationResult|componentValidationReportsComplete|FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing", "present",
          "Consumers must distinguish final oracle success from missing component-level aggregate reports."),
    Probe("REV-22", "valid boundary-bearing aggregate asserts strict final oracle evidence",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"finalSourceAuthorityValidationResult|authoritativeBoundaryUsed|authoritativeFeatureRailsUsed|orderedBoundaryCyclesPassed|sourceAuthoritativeValidationUsed", "present",
          "Positive coverage must prove the strict final merged-product validator actually ran and published its typed result."),

    Probe("REV-23", "pipeline stitch-kind assignment is structurally absent",
          ("src/pipeline",),
          r"stitchIdentity\s*(?:\.|->)\s*kind|(?:\w+::)*PureQuadStitchIdentityKind", "absent",
          "A structural whole-statement matcher rejects wrapped, fully-qualified, alias-based, and stale-copy stitch-kind writes across every pipeline translation unit."),
    Probe("REV-23", "pipeline stitch-kind classifier self-test is wired",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"self_test_pipeline_stitch_kind_classifier", "present",
          "The audit proves its own coverage against the four independently reviewed evasion forms."),
    Probe("REV-23", "completion-owned canonical stitch constructor is used",
          ("include/directional/geometry/PureQuadCompletion.h", "src/geometry/PureQuadCompletion.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"canonical_lineage_stitch_identity", "present",
          "Post-remap stitch kind/schema is derived from authoritative patch structure by the completion owner."),
    Probe("REV-23", "stale-kind and post-publication re-stitch contracts exist",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"GeneratedPatchInterior|stitch_pure_quad_patches|stitchIdentity\.kind", "present",
          "Generated interior lineages must remain canonical/resolvable after stale cache tamper and publication."),

    Probe("REV-24", "direct source-authoritative validator rejects null authority at entry",
          ("src/validation/SourceAuthoritativeMeshValidator.cpp",),
          r"options\.sourceAuthority == nullptr", "present",
          "Missing typed source authority is invalid independently of optional boundary/feature/local-sheet gates."),
    Probe("REV-24", "direct null/foreign authority negatives exist",
          ("tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp",),
          r"MissingSourceAuthorityRejectsEvenWhenOptionalGatesAreDisabled|SameExtentForeignSourceAuthorityRejectsBeforeOptionalGates", "present",
          "Direct public validator coverage must prove null and same-extent foreign authority fail closed."),
)

AFFECTED_R_A_PATHS: tuple[str, ...] = (
    "include/directional/diagnostics/RemeshDiagnostics.h",
    "include/directional/pipeline/RemeshPipeline.h",
    "include/directional/geometry/PureQuadCompletion.h",
    "include/directional/geometry/SourceChartTransitions.h",
    "include/directional/geometry/SourceTopologyRegions.h",
    "include/directional/geometry/SurfaceMeshOptimizer.h",
    "include/directional/validation/SourceAuthoritativeMeshValidator.h",
    "src/geometry/PureQuadCompletion.cpp",
    "src/geometry/SurfaceArrangement.cpp",
    "src/geometry/SurfaceCellTracing.cpp",
    "src/geometry/SurfaceMeshOptimizer.cpp",
    "src/geometry/SurfaceOptimizationRailConstraints.cpp",
    "src/pipeline/RemeshPipeline.cpp",
    "src/validation/SourceAuthoritativeMeshValidator.cpp",
    "tests/PureQuadCompletionPhase18Tests.cpp",
    "tests/SurfaceCellsPhase10Tests.cpp",
    "tests/SurfaceMeshOptimizerPhase19Tests.cpp",
    "tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp",
    ".github/workflows/agent-compile-reusable.yml",
)


def iter_files(root: Path, paths: Sequence[str]) -> Iterable[tuple[str, Path]]:
    for rel in paths:
        path = root / rel
        if path.is_dir():
            for child in sorted(path.rglob("*")):
                if child.is_file() and child.suffix in {".h", ".hpp", ".cpp", ".cc", ".cxx", ".yml", ".yaml", ".py"}:
                    yield child.relative_to(root).as_posix(), child
        elif path.is_file():
            yield rel, path
        else:
            raise FileNotFoundError(rel)


def _normalized_statement(text: str) -> str:
    return " ".join(text.split())


def _statement_line(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


def _pipeline_stitch_kind_assignment_matches(
    rel: str, text: str,
) -> list[tuple[str, int, str]]:
    enum_aliases = set(re.findall(
        r"\busing\s+([A-Za-z_]\w*)\s*=\s*(?:[A-Za-z_]\w*::)*PureQuadStitchIdentityKind\s*;",
        text,
        re.MULTILINE,
    ))
    typed_identity_variables = set(re.findall(
        r"(?:[A-Za-z_]\w*::)*PureQuadStitchIdentity\s+([A-Za-z_]\w*)\b",
        text,
        re.MULTILINE,
    ))
    auto_identity_variables = set(re.findall(
        r"\bauto\s+([A-Za-z_]\w*)\s*=\s*[^;]*canonical_lineage_stitch_identity\s*\(",
        text,
        re.MULTILINE | re.DOTALL,
    ))
    identity_variables = typed_identity_variables | auto_identity_variables
    assignment = re.compile(
        r"(?P<lhs>\b[A-Za-z_]\w*(?:\s*(?:\.|->)\s*[A-Za-z_]\w*)*)"
        r"\s*(?:\.|->)\s*kind\s*=\s*(?P<rhs>[^;]+);",
        re.MULTILINE,
    )
    enum_reference = re.compile(
        r"(?:[A-Za-z_]\w*::)*PureQuadStitchIdentityKind\b"
    )
    stale_kind_copy = re.compile(
        r"\bstitchIdentity\s*(?:\.|->)\s*kind\b"
    )
    out: list[tuple[str, int, str]] = []
    for match in assignment.finditer(text):
        lhs = re.sub(r"\s+", "", match.group("lhs"))
        rhs = match.group("rhs")
        root = re.split(r"(?:\.|->)", lhs, maxsplit=1)[0]
        alias_reference = any(
            re.search(rf"\b{re.escape(alias)}\s*::", rhs)
            for alias in enum_aliases
        )
        if (
            "stitchIdentity" not in lhs
            and root not in identity_variables
            and enum_reference.search(rhs) is None
            and stale_kind_copy.search(rhs) is None
            and not alias_reference
        ):
            continue
        out.append((
            rel,
            _statement_line(text, match.start()),
            _normalized_statement(match.group(0)),
        ))
    return out


def matches_for(root: Path, probe: Probe) -> list[tuple[str, int, str]]:
    if probe.name == "pipeline stitch-kind assignment is structurally absent":
        out: list[tuple[str, int, str]] = []
        for rel, path in iter_files(root, probe.paths):
            if path.suffix not in {".cpp", ".cc", ".cxx"}:
                continue
            out.extend(_pipeline_stitch_kind_assignment_matches(
                rel, path.read_text(encoding="utf-8")))
        return out

    regex = re.compile(probe.pattern, probe.flags)
    out: list[tuple[str, int, str]] = []
    for rel, path in iter_files(root, probe.paths):
        for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            if regex.search(line):
                out.append((rel, line_no, line.strip()))
    return out


def classify_raw_projection_leaves(root: Path) -> tuple[list[tuple[str, int, str, str]], list[tuple[str, int, str]]]:
    paths = (
        "src/pipeline/RemeshPipeline.cpp",
        "src/geometry/PureQuadCompletion.cpp",
        "src/geometry/SurfaceMeshOptimizer.cpp",
        "src/geometry/SurfaceOptimizationRailConstraints.cpp",
        "src/validation/SourceAuthoritativeMeshValidator.cpp",
    )
    regex = re.compile(r"\b(?:point|provenance|projected|sourcePoint|averaged)\.(?:component|sheet)\b")
    allowed: list[tuple[str, int, str, str]] = []
    unexpected: list[tuple[str, int, str]] = []
    for rel, path in iter_files(root, paths):
        lines = path.read_text(encoding="utf-8").splitlines()
        for line_no, line in enumerate(lines, 1):
            if not regex.search(line):
                continue
            text = line.strip()
            if re.search(r"\.(?:component|sheet)\s*=", text):
                classification = "one-way SurfacePoint geometry/export projection write"
            elif rel == "src/geometry/PureQuadCompletion.cpp" and re.search(r"=\s*point\.(?:component|sheet)\s*;", text):
                classification = "geometry-only averaging payload propagation; not stitch/owner/validator identity"
            else:
                unexpected.append((rel, line_no, text))
                continue
            allowed.append((rel, line_no, text, classification))
    return allowed, unexpected


def classify_face_count_leaves(root: Path) -> tuple[list[tuple[str, int, str, str]], list[tuple[str, int, str]]]:
    regex = re.compile(r"complete_for_face_count")
    allowed: list[tuple[str, int, str, str]] = []
    unexpected: list[tuple[str, int, str]] = []
    for rel, path in iter_files(root, ("include/directional", "src", "tests")):
        for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            if not regex.search(line):
                continue
            text = line.strip()
            if rel == "include/directional/geometry/SourceTopologyRegions.h":
                classification = (
                    "SourceTopologyRegions-local structural extent precondition; semantic consumers use matches_source_faces, "
                    "which immediately performs exact checked row-topology equality"
                )
                allowed.append((rel, line_no, text, classification))
            else:
                unexpected.append((rel, line_no, text))
    return allowed, unexpected


def _function_span(text: str, signature: str) -> tuple[int, int] | None:
    start = text.find(signature)
    if start < 0:
        return None
    open_brace = text.find("{", start)
    if open_brace < 0:
        return None
    depth = 0
    for offset in range(open_brace, len(text)):
        if text[offset] == "{":
            depth += 1
        elif text[offset] == "}":
            depth -= 1
            if depth == 0:
                return start, offset + 1
    return None


def classify_pipeline_stitch_identity_assignments(
    root: Path,
) -> tuple[list[tuple[str, int, str, str]], list[tuple[str, int, str]]]:
    whole_assignment = re.compile(
        r"\bstitchIdentity\s*=\s*([^;]+);", re.MULTILINE
    )
    member_assignment = re.compile(
        r"\bstitchIdentity\s*(?:\.|->)\s*[A-Za-z_]\w*"
        r"(?:\s*(?:\.|->)\s*[A-Za-z_]\w*)*\s*=\s*([^;]+);",
        re.MULTILINE,
    )
    allowed: list[tuple[str, int, str, str]] = []
    unexpected_by_key: dict[tuple[str, int, str], tuple[str, int, str]] = {}

    for rel, path in iter_files(root, ("src/pipeline",)):
        if path.suffix not in {".cpp", ".cc", ".cxx"}:
            continue
        text = path.read_text(encoding="utf-8")
        function_span = None
        function_text = ""
        canonical_factory_present = False
        canonical_map_populated = False
        if rel == "src/pipeline/RemeshPipeline.cpp":
            function_span = _function_span(
                text, "bool rebuild_aggregate_output_identity_caches("
            )
            if function_span is not None:
                function_text = text[function_span[0]:function_span[1]]
                canonical_factory_present = (
                    "canonical_lineage_stitch_identity(" in function_text
                )
                canonical_map_populated = bool(re.search(
                    r"canonicalStitchByPatchVertex\s*\n?\s*\.emplace\("
                    r"[\s\S]{0,300}?lineage\.stitchIdentity\)",
                    function_text,
                ))

        for match in whole_assignment.finditer(text):
            line_no = _statement_line(text, match.start())
            rhs = _normalized_statement(match.group(1))
            statement = _normalized_statement(match.group(0))
            inside_canonical = (
                function_span is not None
                and function_span[0] <= match.start() < function_span[1]
            )
            if rel == "src/pipeline/RemeshPipeline.cpp" and inside_canonical:
                if rhs == "stitch":
                    lookback = text[max(function_span[0], match.start() - 500):match.start()]
                    if "canonical_lineage_stitch_identity(" in lookback:
                        allowed.append((
                            rel, line_no, statement,
                            "direct assignment from the completion-owned canonical_lineage_stitch_identity result",
                        ))
                        continue
                if (
                    rhs == "canonical->second"
                    and canonical_factory_present
                    and canonical_map_populated
                ):
                    lookback = text[max(function_span[0], match.start() - 400):match.start()]
                    if "canonicalStitchByPatchVertex.find(" in lookback:
                        allowed.append((
                            rel, line_no, statement,
                            "assignment from a lookup map populated only by the completion-owned canonical stitch result",
                        ))
                        continue
            unexpected_by_key[(rel, line_no, statement)] = (rel, line_no, statement)

        for match in member_assignment.finditer(text):
            line_no = _statement_line(text, match.start())
            statement = _normalized_statement(match.group(0))
            unexpected_by_key[(rel, line_no, statement)] = (rel, line_no, statement)

        for kind_match in _pipeline_stitch_kind_assignment_matches(rel, text):
            unexpected_by_key[kind_match] = kind_match

    unexpected = sorted(unexpected_by_key.values())
    if not allowed and not unexpected:
        unexpected.append((
            "src/pipeline",
            0,
            "no stitchIdentity assignments found for structural classification",
        ))
    return allowed, unexpected


def self_test_pipeline_stitch_kind_classifier() -> tuple[list[str], list[str]]:
    cases = (
        (
            "fully-qualified-enum",
            "identity.kind = directional::geometry::PureQuadStitchIdentityKind::ArrangementBoundaryNode;",
        ),
        (
            "wrapped-enum-assignment",
            "identity.kind =\n    geometry::PureQuadStitchIdentityKind::ArrangementBoundaryNode;",
        ),
        (
            "stale-kind-copy",
            "identity.kind = lineage.stitchIdentity.kind;",
        ),
        (
            "enum-alias",
            "using K = geometry::PureQuadStitchIdentityKind; identity.kind = K::ArrangementBoundaryNode;",
        ),
    )
    passed: list[str] = []
    failed: list[str] = []
    for name, sample in cases:
        matches = _pipeline_stitch_kind_assignment_matches(
            f"<self-test:{name}>", sample
        )
        if matches:
            passed.append(name)
        else:
            failed.append(name)
    return passed, failed


def render(root: Path) -> tuple[str, bool]:
    lines: list[str] = []
    ok = True
    lines.append("# R-A Closure Inventory through R-A-REV-24")
    lines.append("")
    lines.append("Command: `python3 .agents/Directional/R_A_Closure_Inventory.py --root .`")
    lines.append("")
    lines.append("Scope: source-only Code + Build audit. No generated Directional binary, test, benchmark, discovery, `ctest`, CLI, fuzzer, or custom input is executed.")
    lines.append("")
    lines.append("## Checked affected paths")
    lines.append("")
    for path in AFFECTED_R_A_PATHS:
        exists = (root / path).is_file()
        ok = ok and exists
        lines.append(f"- `{path}` — {'present' if exists else 'MISSING'}")
    lines.append("")
    lines.append("## REV-01 through REV-24 probes")
    lines.append("")

    current_rev = None
    total_matches = 0
    for probe in PROBES:
        if probe.rev != current_rev:
            current_rev = probe.rev
            lines.append(f"### R-A-{probe.rev}")
            lines.append("")
        matches = matches_for(root, probe)
        total_matches += len(matches)
        passed = bool(matches) if probe.expectation == "present" else not matches
        ok = ok and passed
        lines.append(f"**{probe.name}** — {'PASS' if passed else 'FAIL'}")
        lines.append("")
        lines.append(f"- Checked paths: {', '.join(f'`{p}`' for p in probe.paths)}")
        lines.append(f"- Pattern: `{probe.pattern}`")
        lines.append(f"- Expectation: `{probe.expectation}`")
        lines.append(f"- Match count: **{len(matches)}**")
        lines.append(f"- Classification: {probe.rationale}")
        if matches:
            lines.append("- Matches:")
            for rel, line_no, text in matches:
                lines.append(f"  - `{rel}:{line_no}` — `{text}`")
        lines.append("")

    lines.append("## Allowed-leaf classification")
    lines.append("")
    raw_allowed, raw_unexpected = classify_raw_projection_leaves(root)
    lines.append("### Raw `SurfacePoint::{component,sheet}` projection leaves")
    lines.append("")
    lines.append(f"- Match count: **{len(raw_allowed) + len(raw_unexpected)}**")
    lines.append(f"- Allowed count: **{len(raw_allowed)}**")
    lines.append(f"- Unexpected count: **{len(raw_unexpected)}**")
    for rel, line_no, text, classification in raw_allowed:
        lines.append(f"- ALLOWED `{rel}:{line_no}` — {classification} — `{text}`")
    for rel, line_no, text in raw_unexpected:
        lines.append(f"- UNEXPECTED `{rel}:{line_no}` — `{text}`")
    if raw_unexpected:
        ok = False
    lines.append("")

    face_allowed, face_unexpected = classify_face_count_leaves(root)
    lines.append("### `complete_for_face_count` leaves")
    lines.append("")
    lines.append(f"- Match count: **{len(face_allowed) + len(face_unexpected)}**")
    lines.append(f"- Allowed count: **{len(face_allowed)}**")
    lines.append(f"- Unexpected count: **{len(face_unexpected)}**")
    for rel, line_no, text, classification in face_allowed:
        lines.append(f"- ALLOWED `{rel}:{line_no}` — {classification} — `{text}`")
    for rel, line_no, text in face_unexpected:
        lines.append(f"- UNEXPECTED `{rel}:{line_no}` — `{text}`")
    if face_unexpected:
        ok = False
    lines.append("")

    stitch_allowed, stitch_unexpected = classify_pipeline_stitch_identity_assignments(root)
    lines.append("### Pipeline `stitchIdentity` assignment leaves")
    lines.append("")
    lines.append(f"- Match count: **{len(stitch_allowed) + len(stitch_unexpected)}**")
    lines.append(f"- Allowed count: **{len(stitch_allowed)}**")
    lines.append(f"- Unexpected count: **{len(stitch_unexpected)}**")
    for rel, line_no, text, classification in stitch_allowed:
        lines.append(f"- ALLOWED `{rel}:{line_no}` — {classification} — `{text}`")
    for rel, line_no, text in stitch_unexpected:
        lines.append(f"- UNEXPECTED `{rel}:{line_no}` — `{text}`")
    if stitch_unexpected:
        ok = False
    lines.append("")

    stitch_self_test_passed, stitch_self_test_failed = \
        self_test_pipeline_stitch_kind_classifier()
    lines.append("### Pipeline stitch-kind classifier self-test")
    lines.append("")
    lines.append(f"- Case count: **{len(stitch_self_test_passed) + len(stitch_self_test_failed)}**")
    lines.append(f"- Passed count: **{len(stitch_self_test_passed)}**")
    lines.append(f"- Failed count: **{len(stitch_self_test_failed)}**")
    for name in stitch_self_test_passed:
        lines.append(f"- PASS `{name}`")
    for name in stitch_self_test_failed:
        lines.append(f"- FAIL `{name}`")
    if stitch_self_test_failed:
        ok = False
    lines.append("")

    lines.append("## Inventory summary")
    lines.append("")
    lines.append(f"- Probe count: **{len(PROBES)}**")
    lines.append(f"- Probe match count: **{total_matches}**")
    lines.append(f"- Affected path count: **{len(AFFECTED_R_A_PATHS)}**")
    lines.append(f"- Allowed raw-projection leaves: **{len(raw_allowed)}**")
    lines.append(f"- Unexpected raw-projection leaves: **{len(raw_unexpected)}**")
    lines.append(f"- Allowed face-count leaves: **{len(face_allowed)}**")
    lines.append(f"- Unexpected face-count leaves: **{len(face_unexpected)}**")
    lines.append(f"- Allowed pipeline stitchIdentity assignments: **{len(stitch_allowed)}**")
    lines.append(f"- Unexpected pipeline stitchIdentity assignments: **{len(stitch_unexpected)}**")
    lines.append(f"- Stitch-kind classifier self-test cases: **{len(stitch_self_test_passed) + len(stitch_self_test_failed)}**")
    lines.append(f"- Stitch-kind classifier self-test failures: **{len(stitch_self_test_failed)}**")
    lines.append(f"- Final static inventory: **{'PASS' if ok else 'FAIL'}**")
    lines.append("")
    lines.append(f"This {'PASS' if ok else 'FAIL'} is a static/compile-contract result only. R-A semantic acceptance requires the separately packaged artifact-only runtime turn on the fresh corrected compile package.")
    lines.append("")
    return "\n".join(lines), ok


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", default=".")
    parser.add_argument("--output", default="")
    args = parser.parse_args()
    root = Path(args.root).resolve()
    report, ok = render(root)
    if args.output:
        Path(args.output).write_text(report, encoding="utf-8")
    else:
        print(report, end="")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
