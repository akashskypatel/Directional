#!/usr/bin/env bash
set -Eeuo pipefail

ROOT="$RUNNER_TEMP/m1l-artifact-runtime"
PKG="$ROOT/package"
BUILD_LOGS="$ROOT/build-log-artifact"
EVIDENCE="$RUNNER_TEMP/m1l-artifact-evidence"
RAW="$EVIDENCE/raw"
DIAG="$RUNNER_TEMP/m1l-artifact-logs"
ACTIVITY="$DIAG/activity.log"
mkdir -p "$ROOT" "$EVIDENCE" "$RAW" "$DIAG"
exec > >(tee -a "$ACTIVITY") 2>&1
trap 'rc=$?; echo "[m1l-runtime] exit_code=$rc"; printf "exit_code=%s\n" "$rc" > "$DIAG/exit-code.txt"; exit $rc' EXIT

RESULT_ID=9083262395
LOG_ID=9083262833
RESULT_SHA=3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c
LOG_SHA=a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8
MANIFEST_SHA=be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454
PRODUCER_SHA=fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856
IMPLEMENTATION=bd140cff4572412e6f4ecd70a6ce0fe85310932c
SEMANTIC_BASE=d5a97953416196a8fc74c8d9790a1ae7b646ca2d
BUILD_RUN=31441661026

RESULT_ZIP="$ROOT/result.zip"
LOG_ZIP="$ROOT/build-logs.zip"

echo "[m1l-runtime] event_sha=$GITHUB_SHA ref=$GITHUB_REF repository=$GITHUB_REPOSITORY"
echo "[m1l-runtime] implementation=$IMPLEMENTATION result_artifact=$RESULT_ID log_artifact=$LOG_ID"
echo "[m1l-runtime] tool versions"
uname -a
sha256sum --version | head -1
unzip -v | head -2 || true
python3 --version

# Download the exact existing Code+Build artifacts. Never rebuild or repair them.
curl -fsSL -H "Authorization: Bearer $GITHUB_TOKEN" -H "Accept: application/vnd.github+json" \
  "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$RESULT_ID/zip" -o "$RESULT_ZIP"
curl -fsSL -H "Authorization: Bearer $GITHUB_TOKEN" -H "Accept: application/vnd.github+json" \
  "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$LOG_ID/zip" -o "$LOG_ZIP"

actual_result_sha=$(sha256sum "$RESULT_ZIP" | awk '{print $1}')
actual_log_sha=$(sha256sum "$LOG_ZIP" | awk '{print $1}')
[[ "$actual_result_sha" == "$RESULT_SHA" ]]
[[ "$actual_log_sha" == "$LOG_SHA" ]]
printf 'result_artifact_id=%s\nresult_zip_sha256=%s\nlog_artifact_id=%s\nlog_zip_sha256=%s\n' \
  "$RESULT_ID" "$actual_result_sha" "$LOG_ID" "$actual_log_sha" > "$EVIDENCE/artifact-identity.txt"

python3 - "$RESULT_ZIP" "$LOG_ZIP" <<'PY'
import pathlib, stat, sys, zipfile
for raw in sys.argv[1:]:
    p = pathlib.Path(raw)
    with zipfile.ZipFile(p) as z:
        for info in z.infolist():
            name = info.filename
            parts = pathlib.PurePosixPath(name).parts
            if name.startswith('/') or '..' in parts:
                raise SystemExit(f'unsafe archive member: {name}')
            mode = (info.external_attr >> 16) & 0xFFFF
            kind = stat.S_IFMT(mode)
            if kind not in (0, stat.S_IFREG, stat.S_IFDIR):
                raise SystemExit(f'unexpected archive link/special member: {name} mode={oct(mode)}')
print('archive-member-safety=pass')
PY

mkdir -p "$PKG" "$BUILD_LOGS"
unzip -q "$RESULT_ZIP" -d "$PKG"
unzip -q "$LOG_ZIP" -d "$BUILD_LOGS"

cd "$PKG"
actual_manifest_sha=$(sha256sum SHA256SUMS | awk '{print $1}')
[[ "$actual_manifest_sha" == "$MANIFEST_SHA" ]]
[[ $(wc -l < SHA256SUMS | tr -d ' ') == 56 ]]
sha256sum -c SHA256SUMS > "$EVIDENCE/preflight-sha256-check.txt"
regular_files=$(find . -type f | wc -l | tr -d ' ')
executables=$(find bin -maxdepth 1 -type f -perm /111 | wc -l | tr -d ' ')
libraries=$(find lib -maxdepth 1 -type f -name '*.a' | wc -l | tr -d ' ')
fixtures=$(find test-data/benchmarks/fixtures -type f | wc -l | tr -d ' ')
milestone_fixtures=$(find test-data/benchmarks/fixtures/milestone-g -type f | wc -l | tr -d ' ')
symlinks=$(find . -type l | wc -l | tr -d ' ')
[[ "$regular_files" == 57 && "$executables" == 7 && "$libraries" == 2 && "$fixtures" == 27 && "$milestone_fixtures" == 21 && "$symlinks" == 0 ]]
actual_producer_sha=$(sha256sum bin/directional_surface_cell_producer_tests | awk '{print $1}')
[[ "$actual_producer_sha" == "$PRODUCER_SHA" ]]
printf 'manifest_sha256=%s\nmanifest_entries=56\nregular_files=%s\nexecutables=%s\nstatic_libraries=%s\nfixtures=%s\nmilestone_g_fixtures=%s\nsymlinks=%s\nproducer_sha256=%s\n' \
  "$actual_manifest_sha" "$regular_files" "$executables" "$libraries" "$fixtures" "$milestone_fixtures" "$symlinks" "$actual_producer_sha" > "$EVIDENCE/package-preflight.txt"

python3 - "$IMPLEMENTATION" "$SEMANTIC_BASE" "$BUILD_RUN" <<'PY'
import json, pathlib, sys
implementation, semantic_base, build_run = sys.argv[1:]
d = json.loads(pathlib.Path('metadata/build-authority.json').read_text())
expected = {
    'implementationCommit': implementation,
    'semanticSourceBase': semantic_base,
    'runId': build_run,
    'configuration': 'Release',
    'generator': 'Ninja',
    'sharedLibraries': False,
    'gtestDiscoveryMode': 'PRE_TEST',
    'runtimeExecution': False,
    'gtestListExecution': False,
    'testExecution': False,
    'benchmarkExecution': False,
    'ctestExecution': False,
    'cliExecution': False,
    'fuzzerExecution': False,
    'customInputExecution': False,
}
for key, value in expected.items():
    if d.get(key) != value:
        raise SystemExit(f'build-authority mismatch {key}: {d.get(key)!r} != {value!r}')
print('build-authority=pass')
PY

[[ $(wc -l < metadata/m1l-focused-test-names.txt | tr -d ' ') == 6 ]]
[[ $(wc -l < metadata/direct-product-test-names.txt | tr -d ' ') == 4 ]]
[[ $(wc -l < metadata/historical-deferred-red-test-names.txt | tr -d ' ') == 8 ]]
[[ $(wc -l < metadata/deferred-characterization-test-names.txt | tr -d ' ') == 3 ]]
find test-data/benchmarks/fixtures -type f | sed 's#^#./#' | sed 's#^\./test-data#test-data#' | sort > "$ROOT/actual-fixtures.txt"
sort metadata/fixture-files.txt > "$ROOT/expected-fixtures.txt"
diff -u "$ROOT/expected-fixtures.txt" "$ROOT/actual-fixtures.txt" > "$EVIDENCE/fixture-inventory-diff.txt"

mkdir -p "$ROOT/source-check"
tar -xJf source/directional-m1l-cell-topology-region-source-no-deps.tar.xz -C "$ROOT/source-check"
while read -r path blob; do
  [[ -f "$ROOT/source-check/$path" ]]
  actual_blob=$(git hash-object "$ROOT/source-check/$path")
  [[ "$actual_blob" == "$blob" ]]
done < metadata/source-blobs.txt
mapfile -t changed_paths < metadata/changed-paths.txt
mapfile -t patch_paths < <(grep '^diff --git a/' source/m1l-semantic-source.patch | sed -E 's#^diff --git a/([^ ]+) b/.*#\1#')
printf '%s\n' "${changed_paths[@]}" | sort > "$ROOT/changed.txt"
printf '%s\n' "${patch_paths[@]}" | sort > "$ROOT/patch.txt"
diff -u "$ROOT/changed.txt" "$ROOT/patch.txt" > "$EVIDENCE/semantic-patch-path-diff.txt"
printf 'source_blob_count=%s\nsemantic_patch_path_count=%s\n' "$(wc -l < metadata/source-blobs.txt | tr -d ' ')" "${#patch_paths[@]}" > "$EVIDENCE/source-provenance.txt"

echo "[m1l-runtime] preflight complete"

count_discovered() {
  local exe=$1 out=$2
  (cd "$PKG/bin" && "./$exe" --gtest_list_tests) > "$RAW/$out" 2>&1
  python3 - "$RAW/$out" <<'PY'
import sys
n=0
for line in open(sys.argv[1], errors='replace'):
    if line.startswith('  ') and line.strip() and not line.lstrip().startswith('#'):
        n += 1
print(n)
PY
}

producer_count=$(count_discovered directional_surface_cell_producer_tests discovery-producer.txt)
validation_count=$(count_discovered directional_surface_cell_validation_tests discovery-validation.txt)
m1a_count=$(count_discovered directional_surface_cell_authority_kernel_tests discovery-m1a.txt)
t1_count=$(count_discovered directional_surface_cell_oracle_tests discovery-t1.txt)
[[ "$producer_count" == 226 && "$validation_count" == 77 && "$m1a_count" == 14 && "$t1_count" == 29 ]]
printf 'producer=%s\nvalidation=%s\nm1a=%s\nt1=%s\n' "$producer_count" "$validation_count" "$m1a_count" "$t1_count" > "$EVIDENCE/discovery-counts.txt"

run_pass() {
  local exe=$1 filter=$2 label=$3 selected_expected=$4 passed_expected=$5 bound=${6:-180}
  local out="$RAW/$label.log"
  set +e
  (cd "$PKG/bin" && /usr/bin/time -f '\n__TIME__ elapsed=%e maxrss_kb=%M exit=%x' timeout "${bound}s" "./$exe" --gtest_filter="$filter") > "$out" 2>&1
  local rc=$?
  set -e
  local selected passed
  selected=$(grep -E '^\[==========\] Running [0-9]+ tests? from' "$out" | head -1 | sed -E 's/^\[==========\] Running ([0-9]+) tests?.*/\1/' || true)
  passed=$(grep -E '^\[  PASSED  \] [0-9]+ tests?\.' "$out" | tail -1 | sed -E 's/^\[  PASSED  \] ([0-9]+) tests?.*/\1/' || true)
  printf '%s rc=%s selected=%s passed=%s\n' "$label" "$rc" "${selected:-?}" "${passed:-0}" | tee -a "$EVIDENCE/pass-summary.txt"
  [[ "$rc" == 0 && "$selected" == "$selected_expected" && "$passed" == "$passed_expected" ]]
}

# M1l: six fresh single-test processes.
while IFS= read -r testname; do
  run_pass directional_surface_cell_producer_tests "$testname" "m1l-${testname#*.}" 1 1 120
done < metadata/m1l-focused-test-names.txt

suites=(
  'SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.*'
  'SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.*'
  'SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.*'
  'SurfaceCellPhaseFrontFieldChartAuthorityMigration.*'
  'SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.*'
  'SurfaceCellVertexContinuationRouteTransportAuthorityMigration.*'
  'SurfaceCellSegmentRouteTransportAuthorityMigration.*'
  'SurfaceCellPhaseFrontRouteAuthorityMigration.*'
  'SurfaceCellFieldTransitionAuthorityMigration.*'
)
labels=(m1k m1j m1i m1h m1g m1f m1e m1d m1c)
for i in "${!suites[@]}"; do
  run_pass directional_surface_cell_producer_tests "${suites[$i]}" "${labels[$i]}" 6 6 180
done
run_pass directional_surface_cell_validation_tests 'SurfaceOptimizationRailAuthorityMigration.*' m1b 6 6 180

route_filter='SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions:SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected:SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected'
transition_filter='SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition:SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideIndex:SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex'
# The exact current test is FullEfTransitionRowCannotReplaceSourceWideCompactIndex.
transition_filter='SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition:SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideCompactIndex:SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex'
run_pass directional_surface_cell_producer_tests "$route_filter" m1d-route-counterexamples 3 3 180
run_pass directional_surface_cell_producer_tests "$transition_filter" m1c-transition-counterexamples 3 3 180

exclude=$(cat metadata/direct-product-test-names.txt metadata/historical-deferred-red-test-names.txt metadata/deferred-characterization-test-names.txt | paste -sd: -)
run_pass directional_surface_cell_producer_tests "-$exclude" required-green 211 211 300
run_pass directional_surface_cell_validation_tests '*' validation-all 77 77 300
run_pass directional_surface_cell_authority_kernel_tests '*' m1a-all 14 14 180
run_pass directional_surface_cell_oracle_tests '*' t1-all 29 29 180

while IFS= read -r testname; do
  short=${testname##*/}
  bound=120
  run_pass directional_surface_cell_producer_tests "$testname" "direct-$short" 1 1 "$bound"
done < metadata/direct-product-test-names.txt

run_red() {
  local testname=$1 label=$2 token=${3:-}
  local out="$RAW/$label.log"
  set +e
  (cd "$PKG/bin" && /usr/bin/time -f '\n__TIME__ elapsed=%e maxrss_kb=%M exit=%x' timeout 120s ./directional_surface_cell_producer_tests --gtest_filter="$testname") > "$out" 2>&1
  local rc=$?
  set -e
  local selected failed
  selected=$(grep -E '^\[==========\] Running [0-9]+ tests? from' "$out" | head -1 | sed -E 's/^\[==========\] Running ([0-9]+) tests?.*/\1/' || true)
  failed=$(grep -E '^\[  FAILED  \] [0-9]+ tests?,' "$out" | tail -1 | sed -E 's/^\[  FAILED  \] ([0-9]+) tests?.*/\1/' || true)
  [[ "$rc" == 1 && "$selected" == 1 && "$failed" == 1 ]]
  if [[ -n "$token" ]]; then grep -q "$token" "$out"; fi
  printf '%s rc=%s selected=%s failure_token=%s\n' "$label" "$rc" "$selected" "${token:-assertion-red}" | tee -a "$EVIDENCE/historical-red-summary.txt"
}

mapfile -t reds < metadata/historical-deferred-red-test-names.txt
run_red "${reds[0]}" red-1
run_red "${reds[1]}" red-2 PeriodicHolonomyMismatch
run_red "${reds[2]}" red-3 PeriodicHolonomyMismatch
run_red "${reds[3]}" red-4 InvalidHardRailPairing
run_red "${reds[4]}" red-5 InvalidHardRailPairing
run_red "${reds[5]}" red-6 InvalidHardRailPairing
run_red "${reds[6]}" red-7
run_red "${reds[7]}" red-8 InvalidHardRailPairing
grep -q 'NotProductionReady:tracing' "$RAW/red-8.log"

strict_pass=0
strict_fail=0
for i in $(seq 1 10); do
  out="$RAW/strict-$i.log"
  set +e
  (cd "$PKG/bin" && /usr/bin/time -f '\n__TIME__ elapsed=%e maxrss_kb=%M exit=%x' timeout 30s ./directional_surface_cell_producer_tests --gtest_filter='SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent') > "$out" 2>&1
  rc=$?
  set -e
  selected=$(grep -E '^\[==========\] Running [0-9]+ tests? from' "$out" | head -1 | sed -E 's/^\[==========\] Running ([0-9]+) tests?.*/\1/' || true)
  [[ "$selected" == 1 ]]
  if [[ "$rc" == 0 ]] && grep -q '^\[  PASSED  \] 1 test\.' "$out"; then
    strict_pass=$((strict_pass+1))
    status=PASS
  elif [[ "$rc" == 1 ]]; then
    strict_fail=$((strict_fail+1))
    status=FAIL
  else
    echo "unexpected strict timing exit rc=$rc run=$i"
    exit 71
  fi
  printf 'run=%02d status=%s rc=%s\n' "$i" "$status" "$rc" >> "$EVIDENCE/strict-timing-summary.txt"
done
printf 'pass=%s\nfail=%s\n' "$strict_pass" "$strict_fail" >> "$EVIDENCE/strict-timing-summary.txt"

# Bunny: exact one-test known-red comparison; preserve independent-oracle-first ordering and signature.
bunny="$RAW/bunny.log"
set +e
(cd "$PKG/bin" && /usr/bin/time -f '\n__TIME__ elapsed=%e maxrss_kb=%M exit=%x' timeout 180s ./directional_surface_cell_producer_tests --gtest_filter='UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom') > "$bunny" 2>&1
bunny_rc=$?
set -e
bunny_selected=$(grep -E '^\[==========\] Running [0-9]+ tests? from' "$bunny" | head -1 | sed -E 's/^\[==========\] Running ([0-9]+) tests?.*/\1/' || true)
[[ "$bunny_rc" == 1 && "$bunny_selected" == 1 ]]
grep -q 'NotProductionReady:completion' "$bunny"
grep -q 'traceSegments=170831' "$bunny"
grep -q 'arrangementCells=0' "$bunny"
grep -q 'completedQuads=0' "$bunny"
independent_line=$(grep -n 'independentOracle.ok()' "$bunny" | head -1 | cut -d: -f1)
result_line=$(grep -n 'Value of: result.success' "$bunny" | head -1 | cut -d: -f1)
[[ -n "$independent_line" && -n "$result_line" && "$independent_line" -lt "$result_line" ]]
printf 'rc=%s\nselected=%s\nindependent_oracle_failure_line=%s\nresult_success_failure_line=%s\nsignature=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0\n' \
  "$bunny_rc" "$bunny_selected" "$independent_line" "$result_line" > "$EVIDENCE/bunny-summary.txt"

# Vase: exactly one test reaches RUN and is bounded at 60 seconds. Safety-only evidence.
vase="$RAW/vase.log"
set +e
(cd "$PKG/bin" && /usr/bin/time -f '\n__TIME__ elapsed=%e maxrss_kb=%M exit=%x' timeout 60s ./directional_surface_cell_producer_tests --gtest_filter='UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase') > "$vase" 2>&1
vase_rc=$?
set -e
vase_selected=$(grep -E '^\[==========\] Running [0-9]+ tests? from' "$vase" | head -1 | sed -E 's/^\[==========\] Running ([0-9]+) tests?.*/\1/' || true)
[[ "$vase_rc" == 124 && "$vase_selected" == 1 ]]
grep -q '^\[ RUN      \] UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase' "$vase"
printf 'rc=%s\nselected=%s\nbound_seconds=60\ndisposition=safety-only timeout after RUN\n' "$vase_rc" "$vase_selected" > "$EVIDENCE/vase-summary.txt"

# Exact postflight of the immutable input package and outer archives.
cd "$ROOT"
[[ $(sha256sum result.zip | awk '{print $1}') == "$RESULT_SHA" ]]
[[ $(sha256sum build-logs.zip | awk '{print $1}') == "$LOG_SHA" ]]
cd "$PKG"
[[ $(sha256sum SHA256SUMS | awk '{print $1}') == "$MANIFEST_SHA" ]]
sha256sum -c SHA256SUMS > "$EVIDENCE/postflight-sha256-check.txt"
[[ $(find . -type f | wc -l | tr -d ' ') == 57 ]]
[[ $(find bin -maxdepth 1 -type f -perm /111 | wc -l | tr -d ' ') == 7 ]]
[[ $(find lib -maxdepth 1 -type f -name '*.a' | wc -l | tr -d ' ') == 2 ]]
[[ $(find test-data/benchmarks/fixtures -type f | wc -l | tr -d ' ') == 27 ]]
[[ $(find test-data/benchmarks/fixtures/milestone-g -type f | wc -l | tr -d ' ') == 21 ]]
[[ $(find . -type l | wc -l | tr -d ' ') == 0 ]]
[[ $(sha256sum bin/directional_surface_cell_producer_tests | awk '{print $1}') == "$PRODUCER_SHA" ]]

cat > "$EVIDENCE/summary.txt" <<EOF
status=accepted
implementation=$IMPLEMENTATION
build_run=$BUILD_RUN
result_artifact=$RESULT_ID
log_artifact=$LOG_ID
producer_discovery=$producer_count
validation_discovery=$validation_count
m1a_discovery=$m1a_count
t1_discovery=$t1_count
m1l=6/6
m1k_through_m1b=all_green
m1d_route_counterexamples=3/3
m1c_transition_counterexamples=3/3
required_green=211/211
validation=77/77
m1a=14/14
t1=29/29
direct_products=4/4
historical_red_classes=preserved_8/8
strict_timing_pass=$strict_pass
strict_timing_fail=$strict_fail
bunny=NotProductionReady:completion_traceSegments_170831_arrangementCells_0_completedQuads_0
vase=bounded_60s_safety_only
postflight=56/56
symlinks=0
EOF

echo "[m1l-runtime] ACCEPTED"
cat "$EVIDENCE/summary.txt"
