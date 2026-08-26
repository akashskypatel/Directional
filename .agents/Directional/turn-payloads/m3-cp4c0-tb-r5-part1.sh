#!/usr/bin/env bash
set -uo pipefail

log="${RUNNER_TEMP}/m3-cp4c0-tb-r5-activity.log"
exec > >(tee -a "$log") 2>&1
result_dir="${RUNNER_TEMP}/m3-cp4c0-tb-r5-result"
package_zip="${RUNNER_TEMP}/m3-cp4c0-cb5-package.zip"
package_dir="${RUNNER_TEMP}/m3-cp4c0-cb5-package"
mkdir -p "$result_dir/identity-results" "$result_dir/supplementals"

PACKAGE_ARTIFACT_ID=9601160869
PACKAGE_SHA256=143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb
SEMANTIC_SOURCE_SHA=cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e
SOURCE_ARCHIVE_SHA256=f7f2e59cf9866beb8e784aeaefc2320cc2306a49ab1813133b7e343d5f3e35e3
SELECTOR_SHA256=d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116
SELECTOR_316_SHA256=601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c
SELECTOR_328_SHA256=cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600
F3_A=ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode
F3_B=ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus
G5_IDENTITY=ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating
H1_IDENTITY=ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating
T1_IDENTITY=ResolvedBranchContinuation.PositionChoosesSmallerExactExitAndFlipsAcrossCrossover

fail_control() {
  local reason="$1"
  echo "orchestration_failure=${reason}" | tee -a "$result_dir/orchestration-failure.txt"
  return 1
}

preflight() {
  set -euo pipefail
  rm -rf "$package_dir" "$result_dir"
  mkdir -p "$package_dir" "$result_dir/identity-results" "$result_dir/supplementals"
  echo "preflight_started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  gh api --method GET "repos/${GITHUB_REPOSITORY}/actions/artifacts/${PACKAGE_ARTIFACT_ID}/zip" > "$package_zip"
  package_sha="$(sha256sum "$package_zip" | awk '{print $1}')"
  echo "package_zip_sha256=${package_sha}"
  test "$package_sha" = "$PACKAGE_SHA256"

  unzip -q "$package_zip" -d "$package_dir"
  (
    cd "$package_dir"
    sha256sum -c SHA256SUMS | tee "$result_dir/manifest-pre.txt"
  )
  test "$(grep -c ': OK$' "$result_dir/manifest-pre.txt")" -eq 27
  test "$(cat "$package_dir/metadata/source-commit.txt")" = "$SEMANTIC_SOURCE_SHA"
  test "$(cat "$package_dir/metadata/build-exit-code.txt")" = "0"
  test "$(cat "$package_dir/metadata/preflight-exit-code.txt")" = "0"
  grep -Fx 'runtimeExecution=false' "$package_dir/metadata/command-boundary.txt"
  grep -Fx 'turnBoundary=Code+Build-only' "$package_dir/metadata/command-boundary.txt"
  for status_file in "$package_dir"/metadata/source-status-*.txt; do test ! -s "$status_file"; done

  source_archive="$package_dir/source/source-${SEMANTIC_SOURCE_SHA}.tar.gz"
  test "$(sha256sum "$source_archive" | awk '{print $1}')" = "$SOURCE_ARCHIVE_SHA256"

  # Materialize only the immutable packaged source because the packaged tests were
  # compiled with DIRECTIONAL_TEST_SOURCE_DIR pointing at the standard workspace.
  find "$GITHUB_WORKSPACE" -mindepth 1 -maxdepth 1 -exec rm -rf -- {} +
  tar -xzf "$source_archive" -C "$GITHUB_WORKSPACE"

  selector="$GITHUB_WORKSPACE/.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt"
  test -f "$selector"
  test "$(grep -cve '^$' "$selector")" -eq 338
  test "$(grep -ve '^$' "$selector" | sort -u | wc -l | tr -d ' ')" -eq 338
  test "$(sha256sum "$selector" | awk '{print $1}')" = "$SELECTOR_SHA256"
  test "$(head -n 316 "$selector" | sha256sum | awk '{print $1}')" = "$SELECTOR_316_SHA256"
  test "$(head -n 328 "$selector" | sha256sum | awk '{print $1}')" = "$SELECTOR_328_SHA256"

  python3 - "$GITHUB_WORKSPACE" "$selector" "$result_dir/route.tsv" <<'PY'
from pathlib import Path
import collections, re, sys
root = Path(sys.argv[1]); selector = Path(sys.argv[2]); output = Path(sys.argv[3])
cmake = (root / "cmake/DirectionalTests.cmake").read_text()
producer_match = re.search(r"set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)", cmake, re.S)
if producer_match is None:
    raise SystemExit("producer source set missing")
producer_sources = re.findall(r"(?:tests|src/bench)/[^\s\)]+\.cpp", producer_match.group(1))
target_sources = {
    "directional_surface_cell_producer_tests": producer_sources,
    "directional_surface_cell_authority_kernel_tests": ["tests/FieldTransportAtlasTests.cpp", "tests/SurfaceCellAuthorityKernelTests.cpp"],
    "directional_surface_cell_completion_tests": ["tests/FlowRepStrandsPhase15Tests.cpp", "tests/PatchDescriptorMilestoneETests.cpp", "tests/PureQuadCompletionPhase18Tests.cpp", "tests/SurfaceArrangementRowIdentityTests.cpp", "tests/SurfaceComplexSimplificationPhase17Tests.cpp"],
    "directional_surface_cell_validation_tests": ["tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp", "tests/SurfaceMeshOptimizerPhase19Tests.cpp", "tests/SurfaceMeshOptimizerPhase20Tests.cpp", "tests/SurfaceMeshOptimizerPhase21Tests.cpp", "tests/SurfaceMeshOptimizerPhase22Tests.cpp"],
    "directional_compiled_api_tests": ["tests/CompiledLibraryTests.cpp"],
}
pattern = re.compile(r"\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)", re.S)
owners = collections.defaultdict(set)
for target, paths in target_sources.items():
    for rel in paths:
        text = (root / rel).read_text(errors="replace")
        for suite, name in pattern.findall(text): owners[f"{suite}.{name}"].add(target)
identities = [line.strip() for line in selector.read_text().splitlines() if line.strip()]
rows = []
for ordinal, identity in enumerate(identities, 1):
    candidates = owners.get(identity, set())
    if len(candidates) != 1:
        raise SystemExit(f"static route failure ordinal={ordinal} identity={identity} owners={sorted(candidates)}")
    rows.append(f"{ordinal}\t{identity}\t{next(iter(candidates))}")
for identity in (
    "ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode",
    "ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus",
    "ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating",
    "ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating",
):
    if owners.get(identity) != {"directional_surface_cell_producer_tests"}:
        raise SystemExit(f"supplemental route failure identity={identity} owners={sorted(owners.get(identity, set()))}")
output.write_text("\n".join(rows) + "\n")
counts = collections.Counter(row.rsplit("\t", 1)[1] for row in rows)
print("static_route_count=338")
for target in sorted(counts): print(f"static_route_{target}={counts[target]}")
PY

  for target in directional_surface_cell_producer_tests directional_surface_cell_authority_kernel_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do
    test -x "$package_dir/bin/$target"
  done

  (
    cd "$package_dir"
    find . -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > "$result_dir/package-files-pre.sha256"
  )
  (
    cd "$GITHUB_WORKSPACE"
    find . -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > "$result_dir/source-files-pre.sha256"
    find benchmarks/fixtures -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > "$result_dir/fixtures-pre.sha256"
  )
  sha256sum "$selector" > "$result_dir/selector-pre.sha256"
  sha256sum "$package_dir/bin/directional_surface_cell_producer_tests" > "$result_dir/producer-executable-pre.sha256"
  echo "preflight=PASS"
}

run_one() {
  local identity="$1" target="$2" case_log="$3" case_json="$4"
  local start_ms end_ms rc selected failures errors status
  start_ms="$(date +%s%3N)"
  set +e
  "$package_dir/bin/$target" --gtest_color=no --gtest_filter="$identity" --gtest_output="json:$case_json" 2>&1 | tee "$case_log" | tee -a "$log" >&2
  rc=${PIPESTATUS[0]}
  set +e
  end_ms="$(date +%s%3N)"
  selected=0; failures=0; errors=0
  if [ -f "$case_json" ]; then
    selected="$(jq -r '.tests // 0' "$case_json" 2>/dev/null || echo 0)"
    failures="$(jq -r '.failures // 0' "$case_json" 2>/dev/null || echo 0)"
    errors="$(jq -r '.errors // 0' "$case_json" 2>/dev/null || echo 0)"
  fi
  status=RED
  if [ "$selected" -ne 1 ]; then status=ORCHESTRATION_RED
  elif [ "$rc" -eq 0 ] && [ "$failures" -eq 0 ] && [ "$errors" -eq 0 ]; then status=PASS
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$rc" "$selected" "$failures" "$errors" "$((end_ms-start_ms))" "$status" "$identity"
}

