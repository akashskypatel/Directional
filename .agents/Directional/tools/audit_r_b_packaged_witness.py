#!/usr/bin/env python3
"""Source-only guard for R-B mandatory packaged acceptance witnesses.

This guard never executes Directional binaries. It verifies that the direct
SurfaceArrangement R-B identity contract is source-present and compiled into an
approved default packaged test target while historical tests remain optional.
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path

WITNESS_SOURCE = "tests/SurfaceArrangementRowIdentityTests.cpp"
WITNESS_SUITE = "SurfaceArrangementPhase16"
WITNESS_NAME = "FaceInteriorSupportAndChartIdentityAreRowIndependentAndDiscriminating"
APPROVED_TARGETS = (
    "directional_surface_cell_authority_kernel_tests",
    "directional_surface_cell_producer_tests",
    "directional_surface_cell_completion_tests",
    "directional_surface_cell_validation_tests",
)
HISTORICAL_TARGET = "directional_surface_cell_historical_tests"


@dataclass(frozen=True)
class Finding:
    rule: str
    detail: str


def target_sources(cmake_text: str, target: str) -> set[str]:
    match = re.search(
        rf"add_executable\(\s*{re.escape(target)}\s+(?P<body>.*?)\)",
        cmake_text,
        flags=re.DOTALL,
    )
    if match is None:
        return set()
    return set(re.findall(r"(?:src|tests)/[^\s\)]+\.cpp", match.group("body")))


def historical_default_is_off(cmake_text: str) -> bool:
    return re.search(
        r"option\(\s*DIRECTIONAL_BUILD_HISTORICAL_TESTS\s+"
        r"\"[^\"]*\"\s+OFF\s*\)",
        cmake_text,
        flags=re.DOTALL,
    ) is not None


def witness_present(test_text: str) -> bool:
    return re.search(
        rf"TEST\s*\(\s*{re.escape(WITNESS_SUITE)}\s*,\s*"
        rf"{re.escape(WITNESS_NAME)}\s*\)",
        test_text,
        flags=re.DOTALL,
    ) is not None


def audit(cmake_text: str, test_text: str) -> tuple[list[Finding], dict[str, set[str]]]:
    findings: list[Finding] = []
    memberships = {
        target: target_sources(cmake_text, target)
        for target in (*APPROVED_TARGETS, HISTORICAL_TARGET)
    }

    if not witness_present(test_text):
        findings.append(
            Finding(
                "R-B-PACKAGED-WITNESS-SOURCE",
                f"missing exact TEST({WITNESS_SUITE}, {WITNESS_NAME}) contract",
            )
        )

    if not historical_default_is_off(cmake_text):
        findings.append(
            Finding(
                "R-B-HISTORICAL-DEFAULT",
                "DIRECTIONAL_BUILD_HISTORICAL_TESTS must remain default OFF",
            )
        )

    approved_owners = [
        target for target in APPROVED_TARGETS if WITNESS_SOURCE in memberships[target]
    ]
    if not approved_owners:
        historical_only = WITNESS_SOURCE in memberships[HISTORICAL_TARGET]
        detail = "mandatory source has no approved default packaged owner"
        if historical_only:
            detail += "; source is historical-only while historical tests default OFF"
        findings.append(Finding("R-B-PACKAGED-WITNESS-OWNER", detail))
    elif len(approved_owners) != 1:
        findings.append(
            Finding(
                "R-B-PACKAGED-WITNESS-DUPLICATE-OWNER",
                "mandatory source must have exactly one approved default owner: "
                + ", ".join(approved_owners),
            )
        )

    return findings, memberships


def run_self_test() -> tuple[bool, list[str]]:
    contract = f"TEST({WITNESS_SUITE}, {WITNESS_NAME}) {{}}\n"
    good = f'''option(\n  DIRECTIONAL_BUILD_HISTORICAL_TESTS\n  "historical"\n  OFF)\nadd_executable(\n  directional_surface_cell_completion_tests\n  {WITNESS_SOURCE})\nif(DIRECTIONAL_BUILD_HISTORICAL_TESTS)\n  add_executable(\n    {HISTORICAL_TARGET}\n    other.cpp)\nendif()\n'''
    historical_only = f'''option(\n  DIRECTIONAL_BUILD_HISTORICAL_TESTS\n  "historical"\n  OFF)\nadd_executable(\n  directional_surface_cell_completion_tests\n  other.cpp)\nif(DIRECTIONAL_BUILD_HISTORICAL_TESTS)\n  add_executable(\n    {HISTORICAL_TARGET}\n    {WITNESS_SOURCE})\nendif()\n'''
    duplicate = f'''option(\n  DIRECTIONAL_BUILD_HISTORICAL_TESTS\n  "historical"\n  OFF)\nadd_executable(\n  directional_surface_cell_completion_tests\n  {WITNESS_SOURCE})\nadd_executable(\n  directional_surface_cell_validation_tests\n  {WITNESS_SOURCE})\n'''
    failures: list[str] = []
    if audit(good, contract)[0]:
        failures.append("good-default-owner-rejected")
    if not any(
        finding.rule == "R-B-PACKAGED-WITNESS-OWNER"
        for finding in audit(historical_only, contract)[0]
    ):
        failures.append("historical-only-escape-not-detected")
    if not any(
        finding.rule == "R-B-PACKAGED-WITNESS-DUPLICATE-OWNER"
        for finding in audit(duplicate, contract)[0]
    ):
        failures.append("duplicate-approved-owner-not-detected")
    if not any(
        finding.rule == "R-B-PACKAGED-WITNESS-SOURCE"
        for finding in audit(good, "")[0]
    ):
        failures.append("missing-contract-not-detected")
    return not failures, failures


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path.cwd())
    parser.add_argument("--report", type=Path)
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    root = args.root.resolve()

    cmake_path = root / "cmake/DirectionalTests.cmake"
    test_path = root / WITNESS_SOURCE
    cmake_text = cmake_path.read_text(encoding="utf-8")
    test_text = test_path.read_text(encoding="utf-8")
    findings, memberships = audit(cmake_text, test_text)

    self_test_ok = True
    self_test_failures: list[str] = []
    if args.self_test:
        self_test_ok, self_test_failures = run_self_test()
        if not self_test_ok:
            findings.append(
                Finding("R-B-PACKAGED-WITNESS-SELF-TEST", ", ".join(self_test_failures))
            )

    approved_owners = [
        target for target in APPROVED_TARGETS if WITNESS_SOURCE in memberships[target]
    ]
    historical_owner = WITNESS_SOURCE in memberships[HISTORICAL_TARGET]
    lines = [
        "# R-B packaged witness source audit",
        "",
        f"- Result: **{'PASS' if not findings else 'FAIL'}**",
        f"- Audit self-test: **{'PASS' if self_test_ok else 'FAIL'}**",
        f"- Exact witness source present: **{'YES' if witness_present(test_text) else 'NO'}**",
        f"- Historical tests default OFF: **{'YES' if historical_default_is_off(cmake_text) else 'NO'}**",
        f"- Approved default owners: **{', '.join(approved_owners) if approved_owners else 'NONE'}**",
        f"- Historical target also owns source: **{'YES' if historical_owner else 'NO'}**",
        "",
        "This audit guards the TB2 escape in which the exact acceptance contract existed in source but was compiled only into an optional historical executable that was disabled in the immutable package.",
        "",
        "## Findings",
        "",
    ]
    if findings:
        lines.extend(f"- `{finding.rule}` — {finding.detail}" for finding in findings)
    else:
        lines.append("- None.")
    lines.extend(["", "## Target membership", ""])
    for target in (*APPROVED_TARGETS, HISTORICAL_TARGET):
        state = "owns witness source" if WITNESS_SOURCE in memberships[target] else "does not own witness source"
        lines.append(f"- `{target}` — {state}")
    report = "\n".join(lines) + "\n"

    if args.report:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(report, encoding="utf-8")
    else:
        sys.stdout.write(report)
    return 0 if not findings else 1


if __name__ == "__main__":
    raise SystemExit(main())
