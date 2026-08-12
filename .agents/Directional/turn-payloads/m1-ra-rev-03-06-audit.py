from pathlib import Path


def block(text: str, start: str, end: str) -> str:
    s = text.index(start)
    e = text.index(end, s)
    return text[s:e]

pure = Path('src/geometry/PureQuadCompletion.cpp').read_text()
pure_h = Path('include/directional/geometry/PureQuadCompletion.h').read_text()
validator = Path('src/validation/SourceAuthoritativeMeshValidator.cpp').read_text()
optimizer = Path('src/geometry/SurfaceMeshOptimizer.cpp').read_text()
rail = Path('src/geometry/SurfaceOptimizationRailConstraints.cpp').read_text()
remesh = Path('src/pipeline/RemeshPipeline.cpp').read_text()
pure_tests = Path('tests/PureQuadCompletionPhase18Tests.cpp').read_text()
optimizer_tests = Path('tests/SurfaceMeshOptimizerPhase22Tests.cpp').read_text()
quotient_tests = Path('tests/SurfaceCellTransitionQuotientTests.cpp').read_text()

# REV-03: no compatibility synthesis and no generated interior identity before typed proof.
assert 'Compatibility path for standalone completion fixtures' not in pure
append = block(pure, 'int append_embedded_vertex(', '\n}\n\n} // namespace directional::geometry::pure_quad_detail')
assert 'canonical.valid = true' not in append
assert 'canonical.values = {mesh.sourcePatch' not in append
assert 'boundaryNodeIdentities = patch.boundaryNodeIdentities' in pure
assert 'std::vector<SurfaceCellCanonicalIdentity> boundaryNodeIdentities;' in pure_h
resolved = block(pure, 'PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow,\n', 'PureQuadStitchIdentity resolved_stitch_identity(\n    const PureQuadMesh &patch, const int localRow) {')
assert 'patch.boundaryNodeIdentities' in resolved
assert 'typed_lineage_stitch_identity' in resolved
assert 'return {};' in resolved
resolved_authoritative = block(pure, 'PureQuadStitchIdentity resolved_authoritative_identity(', '\n}\n\nCompletedFaceOwnershipRecord')
assert 'typed_lineage_stitch_identity' in resolved_authoritative
assert 'authoritative.valid() ? authoritative' not in resolved_authoritative
assert 'MissingTypedStitchIdentity' in pure

# REV-04: raw SurfacePoint component/sheet are not validation/optimizer/rail authority.
assert '.component' not in validator and '.sheet' not in validator
for banned in (
    'point.component', 'point.sheet', 'source.component', 'source.sheet',
    'faceSource.component', 'faceSource.sheet', 'firstPoint.component',
    'firstPoint.sheet',
):
    assert banned not in optimizer, banned
rail_support = block(rail, 'bool provenance_supports_interval_sheet(', '\n}\n\n} // namespace directional::geometry::surface_optimization_rail_detail')
for banned in ('provenance.component', 'provenance.sheet', 'interval.component', 'interval.sheet'):
    assert banned not in rail_support, banned
assert 'legacy_source_vertex_extent' not in rail
assert 'constraints.sourceVertices.rows()' in rail_support

# Raw projection labels must not contribute to completion hashing.
hash_point = block(remesh, 'void hash_surface_point(', '\n}\n\n} // namespace directional::pipeline')
assert 'point.component' not in hash_point and 'point.sheet' not in hash_point

# Materializer occurrence authority remains typed and raw payload is not read back.
materializer = block(remesh, 'AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(', '\n}\n\n} // namespace directional::pipeline')
assert 'authority::IsolationSheetId isolationSheet;' in materializer
assert '.point.component' not in materializer and '.point.sheet' not in materializer

# REV-05 compiled contract inventory.
for required in (
    'PrebuiltBoundaryStitchIdentityMustMatchExactAuthority',
    'MissingTypedStitchIdentityFailsClosedForGeneratedInterior',
    'RawProjectionTamperDoesNotChangeTypedStitchAssembly',
    'CoincidentPositionsOnDistinctTypedSheetsDoNotMerge',
):
    assert required in pure_tests, required
for required in (
    'HardRailChartAuthorityIgnoresRawProjectionLabelsButNotGeometryFailures',
    'RawProjectionLabelsDoNotAffectTypedRailCompatibility',
):
    assert required in optimizer_tests, required
assert 'MaterializedCompletionHashIgnoresRawProjectionLabels' in quotient_tests

print('R-A-REV-03 source audit: closed')
print('R-A-REV-04 source audit: closed')
print('R-A-REV-05 compiled-contract inventory: present')
