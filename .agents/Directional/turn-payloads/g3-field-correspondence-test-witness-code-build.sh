#!/usr/bin/env bash
set -Eeuo pipefail

LOG="/tmp/g3-field-correspondence-test-witness-code-build.log"
exec > >(tee -a "$LOG") 2>&1
trap 'rc=$?; echo "payload_exit=$rc"; echo "payload_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)"; exit $rc' EXIT

SOURCE_COMMIT="117620ec2da2083ce11b205835e58fa404f163ef"
EXPECTED_TEST_BLOB="80a0b58339102279ab863d9112e243a557cd270d"
EXPECTED_PROD_BLOB="63e5ee427f675077f710db51ffb56d91838d3519"
EXPECTED_HEADER_BLOB="c1b816a584d67a3f74c2d7389962bd92d52244c9"

echo "trigger_checkout_sha=$(git rev-parse HEAD)"
git fetch --no-tags --depth=1 origin "$SOURCE_COMMIT"
git checkout --detach "$SOURCE_COMMIT"
echo "source_commit=$(git rev-parse HEAD)"
test "$(git hash-object tests/SurfaceCellsPhase10Tests.cpp)" = "$EXPECTED_TEST_BLOB"
test "$(git hash-object src/geometry/SurfaceCellTracing.cpp)" = "$EXPECTED_PROD_BLOB"
test "$(git hash-object include/directional/geometry/SurfaceCellTracing.h)" = "$EXPECTED_HEADER_BLOB"

git diff --check HEAD^

sudo apt-get update
sudo apt-get install -y ninja-build libgmp-dev
git submodule update --init --depth 1 external/eigen external/googletest external/polyscope
git submodule status

cmake --version
c++ --version
ninja --version
cmake -S . -B agent-build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_SHARED_LIBS=OFF \
  -DDIRECTIONAL_BUILD_TESTS=ON \
  -DDIRECTIONAL_BUILD_BENCHMARKS=ON \
  -DGTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  2>&1 | tee agent-configure.log
cmake --build agent-build --target \
  directional_core \
  directional_pipeline \
  directional_compiled_api_tests \
  directional_surface_cell_producer_tests \
  directional_surface_cell_completion_tests \
  directional_surface_cell_validation_tests \
  directional_benchmarks \
  --parallel 2 2>&1 | tee agent-build.log

PARENT_COMMIT=$(git rev-parse HEAD^)
TEST_BLOB=$(git hash-object tests/SurfaceCellsPhase10Tests.cpp)
PROD_BLOB=$(git hash-object src/geometry/SurfaceCellTracing.cpp)
HEADER_BLOB=$(git hash-object include/directional/geometry/SurfaceCellTracing.h)
rm -rf agent-artifact
mkdir -p agent-artifact/{bin,lib,logs,metadata,source,test-data/benchmarks}
cp agent-build/directional_compiled_api_tests agent-artifact/bin/
cp agent-build/directional_surface_cell_producer_tests agent-artifact/bin/
cp agent-build/directional_surface_cell_completion_tests agent-artifact/bin/
cp agent-build/directional_surface_cell_validation_tests agent-artifact/bin/
cp agent-build/directional_benchmarks agent-artifact/bin/
cp agent-build/libdirectional_core.a agent-artifact/lib/
cp agent-build/libdirectional_pipeline.a agent-artifact/lib/
cp -a benchmarks/fixtures agent-artifact/test-data/benchmarks/
cp agent-configure.log agent-artifact/logs/configure.log
cp agent-build.log agent-artifact/logs/build.log
cp agent-build/compile_commands.json agent-artifact/source/compile_commands.json
git diff HEAD^ HEAD -- tests/SurfaceCellsPhase10Tests.cpp > agent-artifact/source/g3-field-correspondence-test-witness.patch
PATCH_SHA=$(sha256sum agent-artifact/source/g3-field-correspondence-test-witness.patch | awk '{print $1}')
git archive --format=tar HEAD | xz -T0 > agent-artifact/source/directional-g3-field-correspondence-test-witness-source-no-deps.tar.xz
{
  echo "source_commit=$SOURCE_COMMIT"
  cmake --version
  c++ --version
  ninja --version
  git submodule status
} > agent-artifact/logs/toolchain.txt
cat > agent-artifact/metadata/source-authority.json <<EOF
{
  "sourceCommit": "$SOURCE_COMMIT",
  "parentCommit": "$PARENT_COMMIT",
  "runtimeProvenProductionSourceCommit": "0279946920dfca6e9ac44b7ea31b38e929d1f5fc",
  "patchSha256": "$PATCH_SHA",
  "productionSourceChanged": false,
  "changedFileBlobs": {
    "include/directional/geometry/SurfaceCellTracing.h": "$HEADER_BLOB",
    "src/geometry/SurfaceCellTracing.cpp": "$PROD_BLOB",
    "tests/SurfaceCellsPhase10Tests.cpp": "$TEST_BLOB"
  }
}
EOF
cat > agent-artifact/metadata/build-authority.json <<'EOF'
{"configuration":"Release","generator":"Ninja","buildSharedLibs":false,"gtestDiscoveryMode":"PRE_TEST","approvedTargets":7,"runtimeExecution":false}
EOF
cat > agent-artifact/metadata/command-boundary.txt <<'EOF'
Code + Build turn only. No generated Directional binary/test/benchmark/CLI/GUI/help/list/discovery command was executed.
EOF
cat > agent-artifact/README.md <<EOF
# Gate 3 Field-Correspondence Test Witness Code + Build Artifact

Source commit: $SOURCE_COMMIT
Production source unchanged from runtime-proven commit 0279946920dfca6e9ac44b7ea31b38e929d1f5fc.
Compile-only artifact.
EOF

echo "source_commit=$SOURCE_COMMIT"
echo "patch_sha256=$PATCH_SHA"
echo "test_blob=$TEST_BLOB"
echo "production_blob=$PROD_BLOB"
echo "header_blob=$HEADER_BLOB"
echo "executables=$(find agent-artifact/bin -maxdepth 1 -type f | wc -l)"
echo "libraries=$(find agent-artifact/lib -maxdepth 1 -type f | wc -l)"
echo "fixture_files=$(find agent-artifact/test-data -type f | wc -l)"
(cd agent-artifact && find . -type f ! -name SHA256SUMS -print0 | sort -z | xargs -0 sha256sum > SHA256SUMS)
echo "checksum_entries=$(wc -l < agent-artifact/SHA256SUMS)"
(cd agent-artifact && sha256sum -c SHA256SUMS)
echo "final_head=$(git rev-parse HEAD)"
echo "final_status_begin"
git status --short
echo "final_status_end"
