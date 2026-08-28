import collections
import hashlib
import json
import os
import re
import shutil
import stat
import subprocess
import sys
import time
from pathlib import Path

T = Path(os.environ["RUNNER_TEMP"])
R = os.environ["GITHUB_REPOSITORY"]
RUN_ID = int(os.environ["GITHUB_RUN_ID"])
O = T / "m3-cp4c1-tb-r4-result"
P = T / "m3-cp4c1-tb-r4-package"
SROOT = T / "m3-cp4c1-tb-r4-source"
Z = T / "m3-cp4c1-tb-r4-package.zip"
for p in (O, P, SROOT):
    shutil.rmtree(p, ignore_errors=True)
    p.mkdir(parents=True)
(O / "required").mkdir()
(O / "non-gating").mkdir()

PACKAGE_ID = "9673249952"
PACKAGE_NAME = "m3-cp4c1-cb3-compile-result-33139188595"
PACKAGE_SHA = "17a3f8da793fc20562e5ec2f0ab441d39f795dd146171e989fb952e6f942d2ea"
SOURCE_SHA = "66a065b5e07910568a317e24f0fc6b93d890d104"
SOURCE_ARCHIVE_SHA = "3ba7e745a25dddbacd0e18b79672ebac5a8e94a944ed45c60174216f2770c628"
REQUIRED_SHA = "e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa"
PREFIX353_SHA = "51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5"
PREFIX346_SHA = "20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a"
PREFIX316_SHA = "601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c"
NON_GATING_SHA = "9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130"
C4 = "FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing"
C5 = "FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced"


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def prefix_sha(lines, n):
    return hashlib.sha256(("\n".join(lines[:n]) + "\n").encode()).hexdigest()


def inventory(root, sub="."):
    root = Path(root)
    base = root / sub
    return {
        str(p.relative_to(root)): sha(p)
        for p in sorted(base.rglob("*"))
        if p.is_file()
    }


def modes(root):
    root = Path(root)
    return {
        str(p.relative_to(root)): oct(stat.S_IMODE(p.stat().st_mode))
        for p in sorted(root.rglob("*"))
    }


def run_identity(identity, target, stem):
    j = Path(str(stem) + ".json")
    l = Path(str(stem) + ".log")
    started = time.monotonic_ns()
    p = subprocess.run(
        [
            str(P / "bin" / target),
            "--gtest_color=no",
            f"--gtest_filter={identity}",
            f"--gtest_output=json:{j}",
        ],
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    out = p.stdout or ""
    elapsed_ms = (time.monotonic_ns() - started) // 1_000_000
    l.write_text(out)
    print(out, end="")
    data = json.loads(j.read_text()) if j.exists() else {}
    selected = int(data.get("tests", 0))
    failures = int(data.get("failures", 0)) + int(data.get("errors", 0))
    cpp_exception = "C++ exception with description" in out
    if selected != 1:
        status = "ORCHESTRATION_RED"
    elif p.returncode == 0 and failures == 0:
        status = "PASS"
    else:
        status = "RED"
    return {
        "identity": identity,
        "target": target,
        "exit": p.returncode,
        "selected": selected,
        "failures": failures,
        "ms": elapsed_ms,
        "status": status,
        "cppException": cpp_exception,
        "log": out,
    }


def static_routing(source_root, identities):
    producer = "directional_surface_cell_producer_tests"
    cm = (source_root / "cmake/DirectionalTests.cmake").read_text()
    m = re.search(r"set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)", cm, re.S)
    if not m:
        raise RuntimeError("producer source set not found")
    targets = {
        producer: re.findall(r"(?:tests|src/bench)/[^\s\)]+\.cpp", m.group(1)),
        "directional_surface_cell_authority_kernel_tests": [
            "tests/FieldTransportAtlasTests.cpp",
            "tests/SurfaceCellAuthorityKernelTests.cpp",
        ],
        "directional_surface_cell_completion_tests": [
            "tests/FlowRepStrandsPhase15Tests.cpp",
            "tests/PatchDescriptorMilestoneETests.cpp",
            "tests/PureQuadCompletionPhase18Tests.cpp",
            "tests/SurfaceArrangementRowIdentityTests.cpp",
            "tests/SurfaceComplexSimplificationPhase17Tests.cpp",
        ],
        "directional_surface_cell_validation_tests": [
            "tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp",
            "tests/SurfaceMeshOptimizerPhase19Tests.cpp",
            "tests/SurfaceMeshOptimizerPhase20Tests.cpp",
            "tests/SurfaceMeshOptimizerPhase21Tests.cpp",
            "tests/SurfaceMeshOptimizerPhase22Tests.cpp",
        ],
    }
    pat = re.compile(r"\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)", re.S)
    owners = collections.defaultdict(set)
    for target, paths in targets.items():
        for rel in paths:
            text = (source_root / rel).read_text(errors="replace")
            for suite, name in pat.findall(text):
                owners[f"{suite}.{name}"].add(target)
    route = []
    for ordinal, identity in enumerate(identities, 1):
        if len(owners[identity]) != 1:
            raise RuntimeError(
                f"identity owner cardinality ordinal={ordinal} identity={identity} "
                f"owners={sorted(owners[identity])}"
            )
        route.append((ordinal, identity, next(iter(owners[identity]))))
    return route


result = {
    "turn": "M3-CP4c-1-TB-R4",
    "runId": RUN_ID,
    "packageArtifactId": int(PACKAGE_ID),
    "packageName": PACKAGE_NAME,
    "packageSha256": PACKAGE_SHA,
    "semanticSource": SOURCE_SHA,
    "requiredSelectorSha256": REQUIRED_SHA,
    "prefix353Sha256": PREFIX353_SHA,
    "prefix346Sha256": PREFIX346_SHA,
    "prefix316Sha256": PREFIX316_SHA,
    "nonGatingSelectorSha256": NON_GATING_SHA,
    "exactArithmeticBackend": "GMP",
    "configureOccurred": False,
    "compileOccurred": False,
    "relinkOccurred": False,
    "repairOccurred": False,
    "generatedDiscoveryOccurred": False,
    "mutationOccurred": False,
    "performanceAcceptanceBenchmarkApplicable": False,
    "gate": "NOT_RUN",
    "nonGating": "NOT_RUN",
    "stopReason": "none",
    "overall": "PENDING",
}
pre = None
exit_code = 2

try:
    if not os.environ.get("GH_TOKEN"):
        raise RuntimeError("GH_TOKEN unavailable")

    meta = json.loads(
        subprocess.check_output(
            ["gh", "api", f"repos/{R}/actions/artifacts/{PACKAGE_ID}"],
            text=True,
        )
    )
    expected_digest = f"sha256:{PACKAGE_SHA}"
    if int(meta.get("id", 0)) != int(PACKAGE_ID):
        raise RuntimeError("artifact id mismatch")
    if meta.get("name") != PACKAGE_NAME:
        raise RuntimeError(f"artifact name mismatch observed={meta.get('name')}")
    if meta.get("digest") != expected_digest:
        raise RuntimeError(f"artifact digest mismatch observed={meta.get('digest')}")
    if bool(meta.get("expired")):
        raise RuntimeError("artifact is expired")
    (O / "artifact-metadata.json").write_text(json.dumps(meta, sort_keys=True, indent=2))

    with Z.open("wb") as z:
        subprocess.run(
            ["gh", "api", "--method", "GET", f"repos/{R}/actions/artifacts/{PACKAGE_ID}/zip"],
            stdout=z,
            check=True,
        )
    if sha(Z) != PACKAGE_SHA:
        raise RuntimeError(f"package zip hash mismatch observed={sha(Z)} expected={PACKAGE_SHA}")
    subprocess.run(["unzip", "-q", str(Z), "-d", str(P)], check=True)

    manifest = (P / "SHA256SUMS").read_text().splitlines()
    if len(manifest) != 28:
        raise RuntimeError(f"manifest cardinality={len(manifest)} expected=28")
    for line in manifest:
        expected, rel = line.split("  ", 1)
        observed = sha(P / rel)
        if observed != expected:
            raise RuntimeError(f"manifest mismatch {rel} observed={observed} expected={expected}")

    if (P / "metadata/source-commit.txt").read_text().strip() != SOURCE_SHA:
        raise RuntimeError("source commit mismatch")
    if (P / "metadata/build-exit-code.txt").read_text().strip() != "0":
        raise RuntimeError("build exit code not zero")
    if (P / "metadata/preflight-exit-code.txt").read_text().strip() != "0":
        raise RuntimeError("preflight exit code not zero")
    if any(path.read_bytes() for path in (P / "metadata").glob("source-status-*.txt")):
        raise RuntimeError("package source status not clean")

    boundary = (P / "metadata/command-boundary.txt").read_text()
    if not all(
        token in boundary
        for token in (
            "runtimeExecution=false",
            "turnBoundary=Code+Build-only",
            "exactArithmeticBackend=GMP",
        )
    ):
        raise RuntimeError("command boundary metadata mismatch")
    gmp = (P / "metadata/gmp-evidence.txt").read_text()
    if "libgmpxx.so" not in gmp or "libgmp.so" not in gmp:
        raise RuntimeError("GMP/GMPXX link evidence missing")

    compiled_targets = [
        x for x in (P / "metadata/compiled-targets.txt").read_text().splitlines() if x
    ]
    expected_targets = [
        "directional_core",
        "directional_pipeline",
        "directional_surface_cell_authority_kernel_tests",
        "directional_surface_cell_producer_tests",
        "directional_surface_cell_completion_tests",
        "directional_surface_cell_validation_tests",
        "directional_compiled_api_tests",
        "directional_benchmarks",
    ]
    if compiled_targets != expected_targets:
        raise RuntimeError(f"compiled target inventory mismatch {compiled_targets}")

    executables = [p.name for p in sorted((P / "bin").iterdir()) if p.is_file()]
    if len(executables) != 6:
        raise RuntimeError(f"executable inventory count={len(executables)} expected=6")
    if not all(os.access(P / "bin" / x, os.X_OK) for x in executables):
        raise RuntimeError("non-executable packaged binary")
    for exe in executables:
        ldd = subprocess.check_output(["ldd", str(P / "bin" / exe)], text=True)
        if "not found" in ldd:
            raise RuntimeError(f"missing runtime dependency for {exe}")
    (O / "runtime-dependency-check.txt").write_text(
        "\n".join(executables) + "\nGMP/GMPXX runtime dependencies present\n"
    )

    archive = P / "source" / f"source-{SOURCE_SHA}.tar.gz"
    if sha(archive) != SOURCE_ARCHIVE_SHA:
        raise RuntimeError(
            f"source archive mismatch observed={sha(archive)} expected={SOURCE_ARCHIVE_SHA}"
        )
    subprocess.run(["tar", "-xzf", str(archive), "-C", str(SROOT)], check=True)

    required_path = SROOT / ".agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt"
    non_path = SROOT / ".agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt"
    required = [x for x in required_path.read_text().splitlines() if x]
    non = [x for x in non_path.read_text().splitlines() if x]

    if len(required) != 355 or len(required) != len(set(required)) or sha(required_path) != REQUIRED_SHA:
        raise RuntimeError("required selector integrity failure")
    if prefix_sha(required, 353) != PREFIX353_SHA:
        raise RuntimeError("accepted-353 prefix integrity failure")
    if prefix_sha(required, 346) != PREFIX346_SHA:
        raise RuntimeError("accepted-346 prefix integrity failure")
    if prefix_sha(required, 316) != PREFIX316_SHA:
        raise RuntimeError("accepted-316 prefix integrity failure")
    if required[353] != C4 or required[354] != C5:
        raise RuntimeError("C4/C5 ordinal integrity failure")
    if len(non) != 5 or len(non) != len(set(non)) or sha(non_path) != NON_GATING_SHA:
        raise RuntimeError("non-gating selector integrity failure")
    if set(non) & set(required):
        raise RuntimeError("non-gating selector collides with required gate")

    route = static_routing(SROOT, required)
    non_route = static_routing(SROOT, non)
    (O / "required-selector.txt").write_text(required_path.read_text())
    (O / "non-gating-selector.txt").write_text(non_path.read_text())
    (O / "required-route.tsv").write_text(
        "".join(f"{n}\t{i}\t{t}\n" for n, i, t in route)
    )
    (O / "non-gating-route.tsv").write_text(
        "".join(f"{n}\t{i}\t{t}\n" for n, i, t in non_route)
    )

    pre = {
        "package": inventory(P),
        "packageModes": modes(P),
        "source": inventory(SROOT),
        "sourceModes": modes(SROOT),
        "fixtures": inventory(SROOT, "benchmarks/fixtures"),
        "requiredSelector": sha(required_path),
        "nonGatingSelector": sha(non_path),
        "executables": {
            x: [sha(P / "bin" / x), oct(stat.S_IMODE((P / "bin" / x).stat().st_mode))]
            for x in executables
        },
        "packageZip": sha(Z),
        "sourceArchive": sha(archive),
    }
    (O / "preflight-inventory.json").write_text(json.dumps(pre, sort_keys=True, indent=2))
    result["preflight"] = "PASS"

    rows = []
    selected_errors = 0
    cpp_exceptions = 0
    passed = 0
    for ordinal, identity, target in route:
        row = run_identity(identity, target, O / "required" / f"{ordinal:03d}-{identity}")
        rows.append(row)
        selected_errors += int(row["selected"] != 1)
        cpp_exceptions += int(row["cppException"])
        passed += int(row["status"] == "PASS")
        print(
            f"required ordinal={ordinal} status={row['status']} selected={row['selected']} "
            f"exit={row['exit']} ms={row['ms']} identity={identity}"
        )
        if row["selected"] != 1:
            result["stopReason"] = f"required-selection-cardinality-ordinal-{ordinal}"
            break

    required_ledger = [{k: v for k, v in r.items() if k != "log"} for r in rows]
    (O / "required-ledger.json").write_text(json.dumps(required_ledger, sort_keys=True, indent=2))
    first_red = next((n for n, r in enumerate(rows, 1) if r["status"] != "PASS"), 0)
    result["gateSummary"] = {
        "required": 355,
        "executed": len(rows),
        "passed": passed,
        "accepted316Passed": sum(r["status"] == "PASS" for r in rows[:316]),
        "accepted346Passed": sum(r["status"] == "PASS" for r in rows[:346]),
        "accepted353Passed": sum(r["status"] == "PASS" for r in rows[:353]),
        "c4": required_ledger[353] if len(required_ledger) >= 354 else None,
        "c5": required_ledger[354] if len(required_ledger) >= 355 else None,
        "firstRedOrdinal": first_red,
        "firstRedIdentity": required[first_red - 1] if first_red else "none",
        "zeroOrMultipleSelected": selected_errors,
        "cppExceptionCount": cpp_exceptions,
        "maxElapsedMs": max((r["ms"] for r in rows), default=0),
    }

    non_rows = []
    if selected_errors == 0:
        for ordinal, identity, target in non_route:
            row = run_identity(identity, target, O / "non-gating" / f"{ordinal:02d}-{identity}")
            non_rows.append(row)
            print(
                f"non_gating ordinal={ordinal} status={row['status']} selected={row['selected']} "
                f"exit={row['exit']} ms={row['ms']} identity={identity}"
            )
            if row["selected"] != 1:
                result["stopReason"] = f"non-gating-selection-cardinality-ordinal-{ordinal}"
                break
        (O / "non-gating-ledger.json").write_text(
            json.dumps(
                [{k: v for k, v in r.items() if k != "log"} for r in non_rows],
                sort_keys=True,
                indent=2,
            )
        )
        result["nonGatingSummary"] = {
            "requiredReports": 5,
            "executed": len(non_rows),
            "trustworthy": sum(r["selected"] == 1 for r in non_rows),
            "pass": sum(r["status"] == "PASS" for r in non_rows),
            "red": sum(r["status"] == "RED" for r in non_rows),
            "cppExceptionCount": sum(r["cppException"] for r in non_rows),
            "gateCredit": 0,
            "classification": "REVIEW_REQUIRED_FROM_PRESERVED_LOGS",
        }

    if selected_errors or len(non_rows) != 5 or any(r["selected"] != 1 for r in non_rows):
        result["gate"] = "ORCHESTRATION_INVALID"
        result["nonGating"] = "ORCHESTRATION_INVALID"
        exit_code = 2
    else:
        result["nonGating"] = "TRUSTWORTHY_REPORT_ONLY"
        if len(rows) == 355 and passed == 355 and cpp_exceptions == 0:
            result["gate"] = "PASS_355_OF_355"
            exit_code = 0
        else:
            result["gate"] = "VALID_SEMANTIC_RED"
            if result["stopReason"] == "none":
                result["stopReason"] = (
                    f"required-red-ordinal-{first_red}" if first_red else "required-gate-incomplete"
                )
            exit_code = 4

except Exception as exc:
    if result["stopReason"] == "none":
        result["stopReason"] = "orchestration-exception"
    result["orchestrationError"] = f"{type(exc).__name__}: {exc}"
    (O / "orchestration-failure.txt").write_text(result["orchestrationError"] + "\n")
    result["preflight"] = result.get("preflight", "FAIL")
    result["overall"] = "ORCHESTRATION_FAILURE"
    exit_code = 2
    print(result["orchestrationError"])

try:
    if pre is not None and P.exists() and SROOT.exists():
        required_path = SROOT / ".agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt"
        non_path = SROOT / ".agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt"
        archive = P / "source" / f"source-{SOURCE_SHA}.tar.gz"
        executables = [p.name for p in sorted((P / "bin").iterdir()) if p.is_file()]
        post = {
            "package": inventory(P),
            "packageModes": modes(P),
            "source": inventory(SROOT),
            "sourceModes": modes(SROOT),
            "fixtures": inventory(SROOT, "benchmarks/fixtures"),
            "requiredSelector": sha(required_path),
            "nonGatingSelector": sha(non_path),
            "executables": {
                x: [
                    sha(P / "bin" / x),
                    oct(stat.S_IMODE((P / "bin" / x).stat().st_mode)),
                ]
                for x in executables
            },
            "packageZip": sha(Z),
            "sourceArchive": sha(archive),
        }
        (O / "postflight-inventory.json").write_text(
            json.dumps(post, sort_keys=True, indent=2)
        )
        result["postflight"] = "PASS" if post == pre else "FAIL"
        if post != pre:
            result["mutationOccurred"] = True
            result["stopReason"] = "immutable-postflight-failed"
            exit_code = 4
        else:
            manifest = (P / "SHA256SUMS").read_text().splitlines()
            for line in manifest:
                expected, rel = line.split("  ", 1)
                if sha(P / rel) != expected:
                    raise RuntimeError(f"postflight manifest mismatch {rel}")
    else:
        result["postflight"] = "NOT_AVAILABLE"
except Exception as exc:
    result["postflight"] = "FAIL"
    result["postflightError"] = f"{type(exc).__name__}: {exc}"
    result["stopReason"] = "postflight-exception"
    exit_code = 4

if result["overall"] == "PENDING":
    if (
        exit_code == 0
        and result.get("gate") == "PASS_355_OF_355"
        and result.get("nonGating") == "TRUSTWORTHY_REPORT_ONLY"
        and result.get("postflight") == "PASS"
    ):
        result["overall"] = "PASS"
    elif exit_code == 2:
        result["overall"] = "ORCHESTRATION_FAILURE"
    else:
        result["overall"] = "VALID_SEMANTIC_RED_OR_STOP"

(O / "result.json").write_text(json.dumps(result, sort_keys=True, indent=2))
(O / "gate-exit-code.txt").write_text(str(exit_code) + "\n")
print(json.dumps(result, sort_keys=True))
sys.exit(exit_code)
