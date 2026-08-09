#!/usr/bin/env bash
set -Eeuo pipefail

LOG_DIR=/tmp/m1c-field-transition-consumer-code-build-v3-logs
ACTIVITY_LOG="$LOG_DIR/activity.log"
M1C_BASE=512d9523f13158a9f71b406b6db7137a1db3c504
ACCEPTED_M1B_IMPLEMENTATION=0340addf21473854856266ff00cb68915ce24ef0
ACCEPTED_M1B_ARTIFACT=9042940168
ACCEPTED_M1A_ARTIFACT=9041930767
ACCEPTED_T1_ARTIFACT=9041289209
EXPECTED_TRACING_BLOB=4809e66bb6e797001ffc22b3f2da6d3613cfdef0
EXPECTED_TEST_BLOB=552a3d98ec8f9280b960fb9bbff9a1c7596a0778
PACKAGE_DIR=/tmp/m1c-field-transition-consumer-code-build-v3

mkdir -p "$LOG_DIR"
exec > >(tee -a "$ACTIVITY_LOG") 2>&1
finish() {
  rc=$?
  trap - EXIT
  echo "script_exit_code=$rc finished_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  exit "$rc"
}
trap finish EXIT

echo "phase=authority-preflight"
echo "event_sha=$GITHUB_SHA"
echo "run_id=$GITHUB_RUN_ID"
test "$(git rev-parse HEAD)" = "$GITHUB_SHA"
git merge-base --is-ancestor "$M1C_BASE" "$GITHUB_SHA"
git merge-base --is-ancestor "$ACCEPTED_M1B_IMPLEMENTATION" "$GITHUB_SHA"
test -z "$(git status --porcelain=v1)"
test "$(git rev-parse HEAD:src/geometry/SurfaceCellTracing.cpp)" = "$EXPECTED_TRACING_BLOB"
test "$(git rev-parse HEAD:tests/SurfaceCellsPhase10Tests.cpp)" = "$EXPECTED_TEST_BLOB"

echo "phase=bounded-edit"
python3 -m py_compile .agents/connector-scripts/m1c-field-transition-consumer-apply.py
python3 .agents/connector-scripts/m1c-field-transition-consumer-apply.py
mapfile -t changed < <(git diff --name-only | LC_ALL=C sort)
test "${#changed[@]}" -eq 2
test "${changed[0]}" = "src/geometry/SurfaceCellTracing.cpp"
test "${changed[1]}" = "tests/SurfaceCellsPhase10Tests.cpp"
grep -q '#include <directional/authority/GridAutomorphism.h>' src/geometry/SurfaceCellTracing.cpp
grep -q '#include <directional/authority/LegacyAuthorityAdapters.h>' src/geometry/SurfaceCellTracing.cpp
test "$(grep -c 'LegacyAuthorityAdapters::source_face' src/geometry/SurfaceCellTracing.cpp)" -ge 4
test "$(grep -c 'LegacyAuthorityAdapters::source_vertex' src/geometry/SurfaceCellTracing.cpp)" -ge 2
grep -q 'SourceEdgeTopologyKey::make' src/geometry/SurfaceCellTracing.cpp
grep -q 'QuarterTurn::from_integer' src/geometry/SurfaceCellTracing.cpp
grep -q 'transport = transport.inverse()' src/geometry/SurfaceCellTracing.cpp
test "$(grep -c '^TEST(SurfaceCellFieldTransitionAuthorityMigration,' tests/SurfaceCellsPhase10Tests.cpp)" -eq 6
grep -q 'NonReciprocalSourceAdjacentIsolationSeamFailsClosed' tests/SurfaceCellsPhase10Tests.cpp
grep -q 'CurvedBoundedDiskInvalidReciprocalTransportFailsClosed' tests/SurfaceCellsPhase10Tests.cpp
git diff --check

git config user.name 'directional-m1c-agent'
git config user.email 'actions@users.noreply.github.com'
git add src/geometry/SurfaceCellTracing.cpp tests/SurfaceCellsPhase10Tests.cpp
git commit -m 'refactor: type field transition authority consumer'
implementation_commit="$(git rev-parse HEAD)"
echo "implementation_commit=$implementation_commit"
git push origin HEAD:agent/surface_cell_quad/p5-recover-bridge-healing
test -z "$(git status --porcelain=v1)"
mapfile -t product_changed < <(git diff --name-only "$M1C_BASE" "$implementation_commit" -- \
  src/geometry/SurfaceCellTracing.cpp tests/SurfaceCellsPhase10Tests.cpp \
  include/directional/geometry/SurfaceCellTracing.h CMakeLists.txt cmake/DirectionalTests.cmake | LC_ALL=C sort)
test "${#product_changed[@]}" -eq 2
test "${product_changed[0]}" = "src/geometry/SurfaceCellTracing.cpp"
test "${product_changed[1]}" = "tests/SurfaceCellsPhase10Tests.cpp"

echo "phase=compile-prerequisites"
sudo apt-get update
sudo apt-get install -y ninja-build libgmp-dev xz-utils time
git submodule sync --recursive
git -c protocol.version=2 submodule update --init --recursive --depth 1 --recommend-shallow
git submodule status --recursive | tee "$LOG_DIR/submodules.txt"

echo "phase=configure"
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_SHARED_LIBS=OFF \
  -DDIRECTIONAL_ENABLE_GMP=ON \
  -DDIRECTIONAL_ENABLE_PARDISO=OFF \
  -DDIRECTIONAL_ENABLE_CUDSS=OFF \
  -DDIRECTIONAL_ENABLE_SUITESPARSE=OFF \
  -DDIRECTIONAL_BUILD_TESTS=ON \
  -DDIRECTIONAL_BUILD_BENCHMARKS=ON \
  -DDIRECTIONAL_BUILD_CLI=OFF \
  -DDIRECTIONAL_BUILD_GUI=OFF \
  -DBUILD_PYTHON=OFF \
  -DBUILD_TUTORIALS=OFF \
  -DCMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST \
  2>&1 | tee "$LOG_DIR/configure.log"

echo "phase=compile-approved-targets"
/usr/bin/time -v -o "$LOG_DIR/build-resources.txt" \
  cmake --build build --parallel 2 --target \
    directional_core \
    directional_pipeline \
    directional_compiled_api_tests \
    directional_surface_cell_producer_tests \
    directional_surface_cell_oracle_tests \
    directional_surface_cell_authority_kernel_tests \
    directional_surface_cell_completion_tests \
    directional_surface_cell_validation_tests \
    directional_benchmarks \
  2>&1 | tee "$LOG_DIR/build.log"

echo "phase=package"
test "$(git rev-parse HEAD)" = "$implementation_commit"
test -z "$(git status --porcelain=v1)"
rm -rf "$PACKAGE_DIR"
mkdir -p "$PACKAGE_DIR/bin" "$PACKAGE_DIR/lib" "$PACKAGE_DIR/logs" \
  "$PACKAGE_DIR/metadata" "$PACKAGE_DIR/source" "$PACKAGE_DIR/test-data/benchmarks"
for exe in \
  directional_compiled_api_tests \
  directional_surface_cell_producer_tests \
  directional_surface_cell_oracle_tests \
  directional_surface_cell_authority_kernel_tests \
  directional_surface_cell_completion_tests \
  directional_surface_cell_validation_tests \
  directional_benchmarks; do
  test -x "build/$exe"
  cp "build/$exe" "$PACKAGE_DIR/bin/$exe"
done
cp build/libdirectional_core.a "$PACKAGE_DIR/lib/"
cp build/libdirectional_pipeline.a "$PACKAGE_DIR/lib/"
cp -a benchmarks/fixtures "$PACKAGE_DIR/test-data/benchmarks/fixtures"
cp "$LOG_DIR"/* "$PACKAGE_DIR/logs/"
cp build/compile_commands.json "$PACKAGE_DIR/source/compile_commands.json"
git diff --binary "$M1C_BASE" "$implementation_commit" -- \
  src/geometry/SurfaceCellTracing.cpp tests/SurfaceCellsPhase10Tests.cpp \
  > "$PACKAGE_DIR/source/m1c-field-transition-consumer.patch"
git archive --format=tar "$implementation_commit" | xz -T0 -6 \
  > "$PACKAGE_DIR/source/directional-m1c-field-transition-source-no-deps.tar.xz"

python3 - <<'PY' > "$PACKAGE_DIR/metadata/m1c-focused-test-names.txt"
import pathlib, re
text = pathlib.Path('tests/SurfaceCellsPhase10Tests.cpp').read_text()
names = [f'{a.strip()}.{b.strip()}' for a,b in re.findall(r'TEST\(\s*(SurfaceCellFieldTransitionAuthorityMigration)\s*,\s*([^)]+)\)', text)]
if len(names) != 6 or len(set(names)) != 6:
    raise SystemExit(f'M1c focused manifest count mismatch: {len(names)}')
print('\n'.join(names))
PY
python3 - <<'PY' > "$PACKAGE_DIR/metadata/m1b-focused-test-names.txt"
import pathlib, re
text = pathlib.Path('tests/SurfaceMeshOptimizerPhase22Tests.cpp').read_text()
names = [f'{a.strip()}.{b.strip()}' for a,b in re.findall(r'TEST\(\s*(SurfaceOptimizationRailAuthorityMigration)\s*,\s*([^)]+)\)', text)]
if len(names) != 6 or len(set(names)) != 6:
    raise SystemExit(f'M1b focused manifest count mismatch: {len(names)}')
print('\n'.join(names))
PY
python3 - <<'PY' > "$PACKAGE_DIR/metadata/authority-kernel-test-names.txt"
import pathlib, re
text = pathlib.Path('tests/SurfaceCellAuthorityKernelTests.cpp').read_text()
names = [f'{a.strip()}.{b.strip()}' for a,b in re.findall(r'TEST\(\s*([^,]+),\s*([^)]+)\)', text)]
if len(names) != 14 or len(set(names)) != 14:
    raise SystemExit(f'authority manifest count mismatch: {len(names)}')
print('\n'.join(names))
PY
python3 - <<'PY' > "$PACKAGE_DIR/metadata/oracle-test-names.txt"
import pathlib, re
text = pathlib.Path('tests/SurfaceCellProductOracleTests.cpp').read_text()
names = [f'{a.strip()}.{b.strip()}' for a,b in re.findall(r'TEST\(\s*([^,]+),\s*([^)]+)\)', text)]
if len(names) != 29 or len(set(names)) != 29:
    raise SystemExit(f'oracle manifest count mismatch: {len(names)}')
print('\n'.join(names))
PY

cat > "$PACKAGE_DIR/metadata/build-authority.json" <<EOF
{
  "turn": "M1c Field-Transition Consumer Code+Build",
  "baseCommit": "$M1C_BASE",
  "implementationCommit": "$implementation_commit",
  "buildEventCommit": "$GITHUB_SHA",
  "workflowRun": "$GITHUB_RUN_ID",
  "workflowAttempt": "$GITHUB_RUN_ATTEMPT",
  "configuration": "Release/static/Ninja",
  "gtestDiscoveryMode": "PRE_TEST",
  "runtimeExecution": false,
  "m1cFocusedStaticTestCount": 6,
  "m1bFocusedStaticTestCount": 6,
  "authorityKernelStaticTestCount": 14,
  "oracleStaticTestCount": 29,
  "acceptedM1bArtifact": "$ACCEPTED_M1B_ARTIFACT",
  "acceptedM1aArtifact": "$ACCEPTED_M1A_ARTIFACT",
  "acceptedT1Artifact": "$ACCEPTED_T1_ARTIFACT"
}
EOF
cat > "$PACKAGE_DIR/metadata/command-boundary.txt" <<EOF
runtimeExecution=false
configured=true
compiled=true
generatedDirectionalBinaryExecuted=false
gtestDiscoveryExecuted=false
testExecuted=false
benchmarkExecuted=false
ctestExecuted=false
cliGuiHelpVersionExecuted=false
fuzzerExecuted=false
customInputExecuted=false
EOF
{
  echo "base_commit=$M1C_BASE"
  echo "implementation_commit=$implementation_commit"
  echo "build_event_commit=$GITHUB_SHA"
  echo "tracing_cpp_blob=$(git rev-parse "$implementation_commit:src/geometry/SurfaceCellTracing.cpp")"
  echo "phase10_tests_blob=$(git rev-parse "$implementation_commit:tests/SurfaceCellsPhase10Tests.cpp")"
  echo "tracing_header_blob=$(git rev-parse "$implementation_commit:include/directional/geometry/SurfaceCellTracing.h")"
  echo "authority_ids_blob=$(git rev-parse "$implementation_commit:include/directional/authority/AuthorityIds.h")"
  echo "authority_adapters_blob=$(git rev-parse "$implementation_commit:include/directional/authority/LegacyAuthorityAdapters.h")"
  echo "grid_automorphism_blob=$(git rev-parse "$implementation_commit:include/directional/authority/GridAutomorphism.h")"
  echo "m1b_tests_blob=$(git rev-parse "$implementation_commit:tests/SurfaceMeshOptimizerPhase22Tests.cpp")"
  echo "authority_tests_blob=$(git rev-parse "$implementation_commit:tests/SurfaceCellAuthorityKernelTests.cpp")"
  echo "oracle_tests_blob=$(git rev-parse "$implementation_commit:tests/SurfaceCellProductOracleTests.cpp")"
  echo "direct_acceptance_blob=$(git rev-parse "$implementation_commit:tests/SurfaceCellDesignAcceptanceTests.cpp")"
} > "$PACKAGE_DIR/metadata/source-blobs.txt"
git submodule status --recursive > "$PACKAGE_DIR/metadata/submodules.txt"
{
  cmake --version | head -1
  ninja --version
  c++ --version | head -1
  uname -a
} > "$PACKAGE_DIR/metadata/toolchain.txt"
find benchmarks/fixtures -type f -printf '%P\n' | LC_ALL=C sort \
  > "$PACKAGE_DIR/metadata/fixture-files.txt"

find "$PACKAGE_DIR" -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | \
  while IFS= read -r -d '' f; do
    rel="${f#"$PACKAGE_DIR"/}"
    sum=$(sha256sum "$f" | awk '{print $1}')
    printf '%s  %s\n' "$sum" "$rel"
  done > "$PACKAGE_DIR/SHA256SUMS"
echo "manifest_entries=$(wc -l < "$PACKAGE_DIR/SHA256SUMS")"
sha256sum "$PACKAGE_DIR/SHA256SUMS" | tee "$LOG_DIR/manifest.sha256"
find "$PACKAGE_DIR" -type f -printf '%P\n' | LC_ALL=C sort | tee "$LOG_DIR/package-files.txt"

echo "runtimeExecution=false"
echo "configured=true"
echo "compiled=true"
