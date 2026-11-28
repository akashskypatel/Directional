#!/usr/bin/env python3
"""Source-only R-C checked Product witness reachability-shape audit.

This audit never executes generated Directional binaries and never claims a
runtime pass. It pins every publicly constructible SurfacePhaseFrontProduct
error to exact default-built GTest identities, parses those TEST bodies, and
requires each witness to reach the checked Product construction seam by source
shape. InvalidSourceAuthority remains schema-only because checked
SourceTopologyRegions construction rejects an empty authority before a Product
can be formed.
"""

from __future__ import annotations

import argparse
import dataclasses
import pathlib
import re
import sys

EXPECTED = [
    'InvalidSourceAuthority',
    'EmptyCells',
    'EmptyEdges',
    'DuplicateCellId',
    'InvalidCellRegion',
    'InvalidEdgeCell',
    'InvalidEdgeRegion',
    'InvalidOppositeEdge',
    'InvalidEventEdge',
    'DuplicatePeriodicRelationId',
    'InvalidPeriodicRelationRegion',
    'MissingPeriodicRelationOwner',
    'InvalidPeriodicRelationOwner',
    'DuplicateIsolationCertificate',
    'IsolationCertificateBijectionMismatch',
    'InvalidBoundedDiskRegion',
    'DuplicateBoundedDiskRegion',
]
STATIC_ONLY = {'InvalidSourceAuthority'}
RUNTIME_REQUIRED = [name for name in EXPECTED if name not in STATIC_ONLY]


@dataclasses.dataclass(frozen=True)
class Witness:
    file: str
    suite: str
    name: str
    required: tuple[str, ...] = ()
    forbidden: tuple[str, ...] = ()


WITNESSES: dict[str, tuple[Witness, ...]] = {
    'EmptyCells': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'EmptyCellsRejectAtCheckedFactory'),),
    'EmptyEdges': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'EmptyEdgesRejectAtCheckedFactory'),),
    'DuplicateCellId': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'DuplicateCellIdentityRejectsAtCheckedFactory'),),
    'InvalidCellRegion': (
        Witness(
            'tests/SurfaceCellsPhase10Tests.cpp',
            'SurfaceCellAuthorityContractCutover',
            'ConflictingCellRegionFailsBeforeMaterialization',
            required=(
                'TopologyRegionId::from_index', 'missingRegion', 'std::none_of',
                'region.id() == missingRegion.value()',
                'cells.front().sourceTopologyRegion = missingRegion.value()',
                'SurfacePhaseFrontProduct::make'),
            forbidden=('replacement->id()', 'region.id() != current')),),
    'InvalidEdgeCell': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'ForeignEdgeCellRejectsAtCheckedFactory'),),
    'InvalidEdgeRegion': (
        Witness('tests/SurfaceCellsPhase10Tests.cpp',
                'SurfaceCellAuthorityContractCutover',
                'ConflictingEdgeRegionFailsBeforeMaterialization'),),
    'InvalidOppositeEdge': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfaceCellTransitionQuotient',
                'MissingHardRailCounterpartIsRejected'),
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfaceCellTransitionQuotient',
                'AmbiguousHardRailCounterpartIsRejected')),
    'InvalidEventEdge': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'ForeignEventEdgeRejectsAtCheckedFactory'),),
    'DuplicatePeriodicRelationId': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory'),),
    'InvalidPeriodicRelationRegion': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'ForeignPeriodicRelationRegionRejectsAtCheckedFactory'),),
    'MissingPeriodicRelationOwner': (
        Witness(
            'tests/SurfaceCellTransitionQuotientTests.cpp',
            'SurfaceCellTransitionQuotient',
            'MissingPeriodicRelationOwnerIsRejected',
            required=(
                'direct_periodic_owner_product()', 'periodicRelation.has_value()',
                'periodicHolonomies.begin()', 'relation.id() == owner',
                'periodicRelation = std::nullopt', 'construct_phase_front_product'),
            forbidden=('torus_fixture()',)),),
    'InvalidPeriodicRelationOwner': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfacePhaseFrontProductFactoryAuthority',
                'UnknownPeriodicRelationOwnerRejectsAtCheckedFactory'),),
    'DuplicateIsolationCertificate': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfaceCellIsolationSeamCertificateAuthority',
                'DuplicateIsolationSeamCertificateIsRejected'),),
    'IsolationCertificateBijectionMismatch': (
        Witness('tests/SurfaceCellTransitionQuotientTests.cpp',
                'SurfaceCellIsolationSeamCertificateAuthority',
                'MissingIsolationSeamCertificateIsRejected'),),
    'InvalidBoundedDiskRegion': (
        Witness(
            'tests/SurfaceCellsPhase10Tests.cpp',
            'SurfacePhaseFrontProductFactoryAuthority',
            'ForeignBoundedDiskRegionRejectsAtCheckedFactory',
            required=(
                'make_curved_disk_fixture()', 'SurfaceCellProducerDisposition::Produced',
                'ASSERT_EQ(1U, product.boundedDiskBoundaryPhases().size())',
                'SurfacePhaseFrontProduct::make')),),
    'DuplicateBoundedDiskRegion': (
        Witness(
            'tests/SurfaceCellsPhase10Tests.cpp',
            'SurfacePhaseFrontProductFactoryAuthority',
            'DuplicateBoundedDiskRegionRejectsAtCheckedFactory',
            required=(
                'make_curved_disk_fixture()', 'SurfaceCellProducerDisposition::Produced',
                'ASSERT_EQ(1U, product.boundedDiskBoundaryPhases().size())',
                'phases.push_back(phases.front())',
                'SurfacePhaseFrontProduct::make')),),
}


def extract_braced_body(text: str, open_brace: int) -> str:
    depth = 0
    for index in range(open_brace, len(text)):
        char = text[index]
        if char == '{':
            depth += 1
        elif char == '}':
            depth -= 1
            if depth == 0:
                return text[open_brace:index + 1]
    raise RuntimeError('unterminated braced body')


def extract_test_body(text: str, suite: str, name: str) -> str:
    pattern = re.compile(
        r'TEST\(\s*' + re.escape(suite) + r'\s*,\s*' + re.escape(name) +
        r'\s*\)\s*\{', re.M | re.S)
    matches = list(pattern.finditer(text))
    if len(matches) != 1:
        raise RuntimeError(
            f'expected exactly one test {suite}.{name}, found {len(matches)}')
    return extract_braced_body(text, text.find('{', matches[0].start()))


def extract_function_body(text: str, signature_token: str) -> str:
    start = text.find(signature_token)
    if start < 0:
        raise RuntimeError(f'missing helper {signature_token}')
    open_brace = text.find('{', start)
    if open_brace < 0:
        raise RuntimeError(f'missing helper body {signature_token}')
    return extract_braced_body(text, open_brace)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument('--root', default='.')
    args = parser.parse_args()
    root = pathlib.Path(args.root).resolve()

    header = (root / 'include/directional/geometry/SurfaceCellTracing.h').read_text()
    source = (root / 'src/geometry/SurfaceCellTracing.cpp').read_text()
    authority_header = (
        root / 'include/directional/geometry/SourceTopologyRegions.h').read_text()
    cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
    phase10 = (root / 'tests/SurfaceCellsPhase10Tests.cpp').read_text()
    transition = (
        root / 'tests/SurfaceCellTransitionQuotientTests.cpp').read_text()

    enum_match = re.search(
        r'enum class SurfacePhaseFrontProductErrorCode\s*:\s*int\s*\{(.*?)\};',
        header, re.S)
    if not enum_match:
        raise RuntimeError('SurfacePhaseFrontProductErrorCode enum not found')
    actual = re.findall(
        r'^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*\d+\s*,?\s*$',
        enum_match.group(1), re.M)
    if actual != EXPECTED:
        raise RuntimeError(
            f'Product error classification stale; expected {EXPECTED}, found {actual}')
    if set(WITNESSES) != set(RUNTIME_REQUIRED):
        raise RuntimeError(
            'explicit runtime error-to-test map is incomplete or contains extras')

    producer_match = re.search(
        r'add_executable\(\s*directional_surface_cell_producer_tests(.*?)\)\s*'
        r'directional_configure_test_target\(directional_surface_cell_producer_tests\)',
        cmake, re.S)
    if not producer_match:
        raise RuntimeError('default producer target source block not found')
    producer_sources = set(re.findall(
        r'(?:src|tests)/[^\s\)]+\.cpp', producer_match.group(1)))

    texts: dict[str, str] = {}
    for code, specs in WITNESSES.items():
        for spec in specs:
            if spec.file not in producer_sources:
                raise RuntimeError(
                    f'{code} witness owner not in default producer target: {spec.file}')
            texts.setdefault(spec.file, (root / spec.file).read_text())

    helper_body = extract_function_body(
        transition, 'construct_phase_front_product(PhaseFrontDraft draft)')
    if 'SurfacePhaseFrontProduct::make' not in helper_body:
        raise RuntimeError(
            'accepted direct Product construction helper no longer ends at '
            'SurfacePhaseFrontProduct::make')

    witnessed_tests: set[str] = set()
    for code in RUNTIME_REQUIRED:
        for spec in WITNESSES[code]:
            body = extract_test_body(texts[spec.file], spec.suite, spec.name)
            identity = f'{spec.suite}.{spec.name}'
            witnessed_tests.add(identity)
            if re.search(
                    r'SurfacePhaseFrontProductErrorCode::\s*' +
                    re.escape(code) + r'\b', body) is None:
                raise RuntimeError(f'{identity} does not assert {code}')
            if ('SurfacePhaseFrontProduct::make' not in body and
                    'construct_phase_front_product' not in body):
                raise RuntimeError(
                    f'{identity} does not invoke checked Product construction')
            missing = [token for token in spec.required if token not in body]
            if missing:
                raise RuntimeError(
                    f'{identity} missing reachability-shape tokens: {missing}')
            forbidden = [token for token in spec.forbidden if token in body]
            if forbidden:
                raise RuntimeError(
                    f'{identity} contains forbidden precondition shape: {forbidden}')

    missing_production = [
        code for code in EXPECTED
        if re.search(
            r'SurfacePhaseFrontProductErrorCode::\s*' + re.escape(code) + r'\b',
            source) is None]
    if missing_production:
        raise RuntimeError(
            f'Product errors missing from production factory: {missing_production}')

    if ('class SourceTopologyRegions' not in authority_header or
            'SourceTopologyRegions(std::vector<SurfaceTopologyRegion> regions'
            not in authority_header):
        raise RuntimeError(
            'checked SourceTopologyRegions private construction shape changed')
    if 'if (faceCount == 0U || regions.empty()' not in source:
        raise RuntimeError(
            'SourceTopologyRegions empty-authority factory rejection changed')
    if ('static_assert(!std::is_default_constructible_v<\n'
            '                directional::geometry::SourceTopologyRegions>);'
            not in phase10):
        raise RuntimeError(
            'SourceTopologyRegions schema-only invalid-authority assertion missing')

    print('PASS: InvalidSourceAuthority: schema-only/unconstructible invalid source authority')
    for code in RUNTIME_REQUIRED:
        identities = ', '.join(
            f'{w.suite}.{w.name}' for w in WITNESSES[code])
        print(
            f'PASS: {code}: direct checked-factory witness-shaped: {identities}')
    print(
        'summary: 17/17 Product errors classified; '
        '16/16 direct checked-factory witness-shaped; '
        f'{len(witnessed_tests)} exact default-built test identities; '
        '1/1 schema-only')
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except Exception as exc:
        print(f'FAIL: {type(exc).__name__}: {exc}', file=sys.stderr)
        raise SystemExit(1)
