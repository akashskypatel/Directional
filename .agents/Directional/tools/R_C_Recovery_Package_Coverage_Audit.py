#!/usr/bin/env python3
"""Source-only guard for R-C focused recovery-witness package ownership."""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

TESTS = [
    'RecoveryTargetProjectionIsBoundedAndDeterministic',
    'RequiredProductionRecoveryTargetsAreFeasible',
    'UniqueFieldAlignedRecoveryAcceptsEveryPrescribedFieldFixture',
    'SourceCellRecoveryFailsClosedForIncompleteField',
    'RecoveryPreservesComponentAndSheetProvenance',
    'PrescribedSphereSingularitiesMatchRecoveredValence',
]

def check(name: str, ok: bool, failures: list[str]) -> None:
    print(f"{'PASS' if ok else 'FAIL'}: {name}")
    if not ok:
        failures.append(name)

def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument('--root', type=Path, default=Path.cwd())
    args = parser.parse_args()
    root = args.root.resolve()
    focused = (root / 'tests/SourceGridRecoveryAuthorityTests.cpp').read_text()
    historical = (root / 'tests/MilestoneGP26Tests.cpp').read_text()
    cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
    failures: list[str] = []

    producer = cmake.split('add_executable(\n  directional_surface_cell_producer_tests', 1)[1].split('directional_configure_test_target(directional_surface_cell_producer_tests)', 1)[0]
    historical_block = cmake.split('if(DIRECTIONAL_BUILD_HISTORICAL_TESTS)', 1)[1].split('include(GoogleTest)', 1)[0]

    check('historical source still records the seven rebound recovery calls',
          historical.count('recover_unique_field_aligned_source_quads(') == 7,
          failures)
    check('focused default witness contains six exact MilestoneGP26 contracts',
          all(re.search(r'TEST\(\s*MilestoneGP26\s*,\s*' + re.escape(name) + r'\s*\)', focused, re.S) for name in TESTS)
          and len(re.findall(r'TEST\(\s*MilestoneGP26\s*,', focused, re.S)) == 6,
          failures)
    check('focused witnesses exercise all seven recovery calls with explicit authority and excluded-edge inputs',
          focused.count('recover_unique_field_aligned_source_quads(') == 7
          and focused.count('&sourceAuthority') >= 7
          and focused.count('&no_recovery_excluded_edges()') >= 7,
          failures)
    check('focused authority builder has no defaulted component or sheet inputs',
          re.search(r'recovery_source_authority\(\s*const Eigen::MatrixXi &faces,\s*const std::vector<int> &components,\s*const std::vector<int> &sheets\s*\)', focused, re.S) is not None,
          failures)
    check('producer package owns only the focused recovery translation unit',
          'tests/SourceGridRecoveryAuthorityTests.cpp' in producer
          and 'tests/MilestoneGP26Tests.cpp' not in producer,
          failures)
    check('retired historical suite remains opt-in and owns the historical translation unit',
          re.search(r'option\(\s*DIRECTIONAL_BUILD_HISTORICAL_TESTS[^\n]*\n[^\n]*\n\s*OFF\)', cmake, re.S) is not None
          and 'tests/MilestoneGP26Tests.cpp' in historical_block,
          failures)

    print(f'summary: {6 - len(failures)}/6 checks passed')
    if failures:
        for failure in failures:
            print(f'- {failure}')
        return 1
    return 0

if __name__ == '__main__':
    sys.exit(main())
