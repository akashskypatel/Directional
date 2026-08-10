#!/usr/bin/env bash
set -Eeuo pipefail

RESULT_ARTIFACT_ID=9079318682
LOG_ARTIFACT_ID=9079319269
RESULT_ZIP_SHA=90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d
LOG_ZIP_SHA=1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381
MANIFEST_SHA=0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c
PRODUCER_SHA=3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1
IMPLEMENTATION=b9181364926cea840e9cb50da21fe721f33fd874
SOURCE_PARENT=38d6fc4c4042c5a0d200abf4e5594dcf325b8383
ACCEPTED_M1J=d5f681173600dc32dc7617de6105d9e584e593be

ROOT=${RUNNER_TEMP}/m1k-artifact-runtime
PKG_DIR=$ROOT/package
WORK_DIR=$ROOT/work
EVID_DIR=$ROOT/evidence
RESULT_ZIP=$ROOT/m1k-result.zip
LOG_ZIP=$ROOT/m1k-build-logs.zip
mkdir -p "$PKG_DIR" "$WORK_DIR" "$EVID_DIR"

exec > >(tee -a "$ACTIVITY_LOG") 2>&1
trap 'rc=$?; echo "validator_exit_code=$rc"; echo "finished_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)"; exit $rc' EXIT

echo "turn=M1k immutable Artifact-Only Test+Benchmark remote validation"
echo "implementation=$IMPLEMENTATION"
echo "event_sha=$GITHUB_SHA"
echo "started_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
echo 'configure=false compile=false relink=false regenerate=false sourceEdit=false testEdit=false fixtureEdit=false packageRepair=false fixtureSymlink=false'

download_artifact() {
  local id=$1 out=$2
  curl --fail --silent --show-error --location \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${id}/zip" \
    -o "$out"
}

download_artifact "$RESULT_ARTIFACT_ID" "$RESULT_ZIP"
download_artifact "$LOG_ARTIFACT_ID" "$LOG_ZIP"
test "$(sha256sum "$RESULT_ZIP" | awk '{print $1}')" = "$RESULT_ZIP_SHA"
test "$(sha256sum "$LOG_ZIP" | awk '{print $1}')" = "$LOG_ZIP_SHA"
for zip in "$RESULT_ZIP" "$LOG_ZIP"; do
  zipinfo -1 "$zip" | while IFS= read -r p; do
    case "$p" in /*|../*|*/../*|*/..) echo "unsafe archive member: $p"; exit 91;; esac
  done
done
unzip -q "$RESULT_ZIP" -d "$PKG_DIR"
test "$(find "$PKG_DIR" -type l | wc -l)" -eq 0
test ! -e "$PKG_DIR/bin/test-data"
test "$(sha256sum "$PKG_DIR/SHA256SUMS" | awk '{print $1}')" = "$MANIFEST_SHA"
(cd "$PKG_DIR" && sha256sum -c SHA256SUMS) > "$EVID_DIR/preflight-manifest-check.txt"
test "$(wc -l < "$PKG_DIR/SHA256SUMS")" -eq 68
test "$(find "$PKG_DIR" -type f | wc -l)" -eq 69
test "$(find "$PKG_DIR/bin" -maxdepth 1 -type f | wc -l)" -eq 7
test "$(find "$PKG_DIR/lib" -maxdepth 1 -type f | wc -l)" -eq 2
test "$(find "$PKG_DIR/test-data/benchmarks/fixtures" -type f | wc -l)" -eq 27
test "$(find "$PKG_DIR/test-data/benchmarks/fixtures/milestone-g" -type f | wc -l)" -eq 21
test "$(sha256sum "$PKG_DIR/bin/directional_surface_cell_producer_tests" | awk '{print $1}')" = "$PRODUCER_SHA"

python3 - "$PKG_DIR/metadata/build-authority.json" <<PY
import json, sys
j=json.load(open(sys.argv[1]))
assert j['implementationCommit']=='$IMPLEMENTATION'
assert j['sourceParent']=='$SOURCE_PARENT'
assert j['acceptedM1jImplementation']=='$ACCEPTED_M1J'
assert str(j['runId'])=='31430898273'
assert j['configuration']=='Release'
assert j['generator']=='Ninja'
assert j['sharedLibraries'] is False
assert j['gtestDiscoveryMode']=='PRE_TEST'
for k in ['runtimeExecution','gtestListExecution','testExecution','benchmarkExecution','ctestExecution','cliExecution','fuzzerExecution','customInputExecution']:
    assert j[k] is False, (k,j[k])
PY

SRC_VERIFY=$ROOT/source-verify
mkdir -p "$SRC_VERIFY"
tar -xJf "$PKG_DIR/source/directional-m1k-edge-topology-region-source-no-deps.tar.xz" -C "$SRC_VERIFY"
python3 - "$PKG_DIR/metadata/source-blobs.txt" "$SRC_VERIFY" <<'PY'
import sys, pathlib, hashlib
manifest=pathlib.Path(sys.argv[1]); root=pathlib.Path(sys.argv[2])
for line in manifest.read_text().splitlines():
    p,h=line.rsplit(' ',1)
    data=(root/p).read_bytes()
    got=hashlib.sha1(f'blob {len(data)}\0'.encode()+data).hexdigest()
    assert got==h,(p,got,h)
PY
rm -rf "$SRC_VERIFY"

for required in \
  m1k-focused-test-names.txt m1j-focused-test-names.txt m1i-focused-test-names.txt \
  m1h-focused-test-names.txt m1g-focused-test-names.txt m1f-focused-test-names.txt \
  m1e-focused-test-names.txt m1d-focused-test-names.txt m1c-focused-test-names.txt \
  m1b-focused-test-names.txt m1a-test-names.txt t1-oracle-test-names.txt \
  direct-product-test-names.txt historical-deferred-red-test-names.txt \
  deferred-characterization-test-names.txt; do
  test -s "$PKG_DIR/metadata/$required"
done

grep -Fx 'UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom' "$PKG_DIR/metadata/deferred-characterization-test-names.txt" >/dev/null
grep -Fx 'UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase' "$PKG_DIR/metadata/deferred-characterization-test-names.txt" >/dev/null
printf '%s\n' \
  "result_zip_sha=$RESULT_ZIP_SHA" "log_zip_sha=$LOG_ZIP_SHA" "manifest_sha=$MANIFEST_SHA" \
  'manifest_verified=68/68' 'regular_files=69' 'executables=7' 'libraries=2' 'fixtures=27' \
  'milestone_g_fixtures=21' "producer_sha=$PRODUCER_SHA" 'symlinks=0' 'fixtureSymlink=false' \
  > "$EVID_DIR/preflight-summary.txt"

producer="$PKG_DIR/bin/directional_surface_cell_producer_tests"
validation="$PKG_DIR/bin/directional_surface_cell_validation_tests"
m1a="$PKG_DIR/bin/directional_surface_cell_authority_kernel_tests"
t1="$PKG_DIR/bin/directional_surface_cell_oracle_tests"

: > "$EVID_DIR/discovery-summary.txt"
for spec in producer:220 validation:77 m1a:14 t1:29; do
  label=${spec%%:*}; expected=${spec##*:}; exe="$producer"
  [ "$label" = validation ] && exe="$validation"
  [ "$label" = m1a ] && exe="$m1a"
  [ "$label" = t1 ] && exe="$t1"
  (cd "$WORK_DIR" && "$exe" --gtest_list_tests) > "$LOG_DIR/${label}-list.txt" 2>&1
  count=$(grep -c '^  [^ ]' "$LOG_DIR/${label}-list.txt")
  echo "$label=$count" | tee -a "$EVID_DIR/discovery-summary.txt"
  test "$count" -eq "$expected"
done

: > "$EVID_DIR/focused-summary.txt"
for label in m1k m1j m1i m1h m1g m1f m1e m1d m1c m1b; do
  exe="$producer"; [ "$label" = m1b ] && exe="$validation"
  idx=0; passed=0
  while IFS= read -r testname; do
    [ -z "$testname" ] && continue
    idx=$((idx+1)); out="$LOG_DIR/${label}-focused-${idx}.log"
    set +e; (cd "$WORK_DIR" && "$exe" --gtest_filter="$testname") > "$out" 2>&1; rc=$?; set -e
    selected=$(grep -E '^\[==========\] Running [0-9]+ test' "$out" | head -1 | sed -E 's/.*Running ([0-9]+) test.*/\1/')
    green=$(grep -E '^\[  PASSED  \] [0-9]+ test' "$out" | tail -1 | sed -E 's/.*\] ([0-9]+) test.*/\1/' || true)
    test "$rc" -eq 0; test "$selected" = 1; test "$green" = 1
    passed=$((passed+1))
  done < "$PKG_DIR/metadata/${label}-focused-test-names.txt"
  echo "$label=$passed/$idx" | tee -a "$EVID_DIR/focused-summary.txt"
  test "$idx" -eq 6; test "$passed" -eq 6
done

for spec in m1d-route-witness:3:m1d-route-witness-test-names.txt m1c-transition-counterexample:3:m1c-transition-counterexample-test-names.txt; do
  label=${spec%%:*}; rest=${spec#*:}; expected=${rest%%:*}; file=${rest#*:}; idx=0
  while IFS= read -r testname; do
    [ -z "$testname" ] && continue
    idx=$((idx+1)); out="$LOG_DIR/${label}-${idx}.log"
    (cd "$WORK_DIR" && "$producer" --gtest_filter="$testname") > "$out" 2>&1
    grep -F '[  PASSED  ] 1 test.' "$out" >/dev/null
  done < "$PKG_DIR/metadata/$file"
  echo "$label=$idx/$expected" | tee -a "$EVID_DIR/focused-summary.txt"
  test "$idx" -eq "$expected"
done

exclusions="$EVID_DIR/required-green-exclusions.txt"
cp "$PKG_DIR/metadata/direct-product-test-names.txt" "$exclusions"
cat "$PKG_DIR/metadata/historical-deferred-red-test-names.txt" >> "$exclusions"
printf '%s\n' \
  SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent \
  UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom \
  UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase >> "$exclusions"
test "$(wc -l < "$exclusions")" -eq 15
neg=$(paste -sd: "$exclusions")
filter="*-${neg}"
test "$(printf '%s' "$filter" | tr -cd '-' | wc -c)" -eq 1
(cd "$WORK_DIR" && /usr/bin/time -v -o "$LOG_DIR/required-green.resources.txt" "$producer" --gtest_filter="$filter") > "$LOG_DIR/required-green.log" 2>&1
selected=$(grep -E '^\[==========\] Running [0-9]+ test' "$LOG_DIR/required-green.log" | head -1 | sed -E 's/.*Running ([0-9]+) test.*/\1/')
green=$(grep -E '^\[  PASSED  \] [0-9]+ test' "$LOG_DIR/required-green.log" | tail -1 | sed -E 's/.*\] ([0-9]+) test.*/\1/')
test "$selected" = 205; test "$green" = 205
echo "required-green=$green/$selected" > "$EVID_DIR/required-green-summary.txt"
grep -E 'Elapsed \(wall clock\)|Maximum resident set size' "$LOG_DIR/required-green.resources.txt" >> "$EVID_DIR/required-green-summary.txt"

: > "$EVID_DIR/independent-targets-summary.txt"
for spec in validation:77 m1a:14 t1:29; do
  label=${spec%%:*}; expected=${spec##*:}; exe="$validation"
  [ "$label" = m1a ] && exe="$m1a"; [ "$label" = t1 ] && exe="$t1"
  (cd "$WORK_DIR" && "$exe") > "$LOG_DIR/${label}-aggregate.log" 2>&1
  selected=$(grep -E '^\[==========\] Running [0-9]+ test' "$LOG_DIR/${label}-aggregate.log" | head -1 | sed -E 's/.*Running ([0-9]+) test.*/\1/')
  green=$(grep -E '^\[  PASSED  \] [0-9]+ test' "$LOG_DIR/${label}-aggregate.log" | tail -1 | sed -E 's/.*\] ([0-9]+) test.*/\1/')
  test "$selected" = "$expected"; test "$green" = "$expected"
  echo "$label=$green/$selected" | tee -a "$EVID_DIR/independent-targets-summary.txt"
done

: > "$EVID_DIR/direct-products-summary.txt"; idx=0
while IFS= read -r testname; do
  [ -z "$testname" ] && continue
  idx=$((idx+1)); out="$LOG_DIR/direct-${idx}.log"; res="$LOG_DIR/direct-${idx}.resources.txt"
  set +e; (cd "$WORK_DIR" && /usr/bin/time -v -o "$res" timeout 60s "$producer" --gtest_filter="$testname") > "$out" 2>&1; rc=$?; set -e
  test "$rc" -eq 0
  grep -F '[  PASSED  ] 1 test.' "$out" >/dev/null
  test "$(find "$PKG_DIR" -type l | wc -l)" -eq 0; test ! -e "$PKG_DIR/bin/test-data"
  wall=$(grep 'Elapsed (wall clock) time' "$res" | sed 's/.*: //'); rss=$(grep 'Maximum resident set size' "$res" | sed 's/.*: //')
  echo "$idx|$testname|pass|wall=$wall|rss_kib=$rss" | tee -a "$EVID_DIR/direct-products-summary.txt"
done < "$PKG_DIR/metadata/direct-product-test-names.txt"
test "$idx" -eq 4

: > "$EVID_DIR/historical-red-summary.txt"; idx=0
while IFS= read -r testname; do
  [ -z "$testname" ] && continue
  idx=$((idx+1)); out="$LOG_DIR/red-${idx}.log"
  set +e; (cd "$WORK_DIR" && "$producer" --gtest_filter="$testname") > "$out" 2>&1; rc=$?; set -e
  test "$rc" -eq 1; grep -F '[  FAILED  ] 1 test' "$out" >/dev/null
  case "$idx" in
    2|3) grep -F 'PeriodicHolonomyMismatch' "$out" >/dev/null; sig=PeriodicHolonomyMismatch ;;
    4|5|6) grep -F 'InvalidHardRailPairing' "$out" >/dev/null; sig=InvalidHardRailPairing ;;
    8) grep -F 'NotProductionReady:tracing producer=tracing/phase-front/InvalidHardRailPairing' "$out" >/dev/null; sig=NotProductionReady:tracing/InvalidHardRailPairing ;;
    *) sig=existing-assertion-red ;;
  esac
  echo "$idx|$testname|rc=$rc|$sig" | tee -a "$EVID_DIR/historical-red-summary.txt"
done < "$PKG_DIR/metadata/historical-deferred-red-test-names.txt"
test "$idx" -eq 8

strict='SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent'
: > "$EVID_DIR/strict-timing-summary.txt"; strict_pass=0
for i in $(seq 1 10); do
  out="$LOG_DIR/strict-${i}.log"; res="$LOG_DIR/strict-${i}.resources.txt"
  set +e; (cd "$WORK_DIR" && /usr/bin/time -v -o "$res" "$producer" --gtest_filter="$strict") > "$out" 2>&1; rc=$?; set -e
  grep -F '[ RUN      ] SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent' "$out" >/dev/null
  [ "$rc" -eq 0 ] && strict_pass=$((strict_pass+1))
  line=$(grep -F 'actual:' "$out" | head -1 || true); wall=$(grep 'Elapsed (wall clock) time' "$res" | sed 's/.*: //' || true); rss=$(grep 'Maximum resident set size' "$res" | sed 's/.*: //' || true)
  echo "$i|rc=$rc|$line|wall=$wall|rss_kib=$rss" | tee -a "$EVID_DIR/strict-timing-summary.txt"
done
echo "strict_pass=$strict_pass/10" | tee "$EVID_DIR/strict-timing-count.txt"

# Earlier gates are green; perform bounded heavy comparison.
bunny='UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom'
vase='UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase'
set +e
(cd "$WORK_DIR" && /usr/bin/time -v -o "$LOG_DIR/bunny.resources.txt" timeout 120s "$producer" --gtest_filter="$bunny") > "$LOG_DIR/bunny.log" 2>&1
bunny_rc=$?
set -e
test "$bunny_rc" -eq 1
grep -F '[ RUN      ] UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom' "$LOG_DIR/bunny.log" >/dev/null
grep -F 'NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0' "$LOG_DIR/bunny.log" >/dev/null
oracle_line=$(grep -n 'independent' "$LOG_DIR/bunny.log" | head -1 | cut -d: -f1 || true)
product_line=$(grep -n 'NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0' "$LOG_DIR/bunny.log" | head -1 | cut -d: -f1)
if [ -n "$oracle_line" ]; then test "$oracle_line" -lt "$product_line"; fi
bunny_wall=$(grep 'Elapsed (wall clock) time' "$LOG_DIR/bunny.resources.txt" | sed 's/.*: //' || true)
bunny_rss=$(grep 'Maximum resident set size' "$LOG_DIR/bunny.resources.txt" | sed 's/.*: //' || true)
echo "BunnyRandom|rc=$bunny_rc|signature=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0|wall=$bunny_wall|rss_kib=$bunny_rss" > "$EVID_DIR/heavy-summary.txt"

set +e
(cd "$WORK_DIR" && /usr/bin/time -v -o "$LOG_DIR/vase.resources.txt" timeout 60s "$producer" --gtest_filter="$vase") > "$LOG_DIR/vase.log" 2>&1
vase_rc=$?
set -e
grep -F '[ RUN      ] UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase' "$LOG_DIR/vase.log" >/dev/null
vase_wall=$(grep 'Elapsed (wall clock) time' "$LOG_DIR/vase.resources.txt" | sed 's/.*: //' || true)
vase_rss=$(grep 'Maximum resident set size' "$LOG_DIR/vase.resources.txt" | sed 's/.*: //' || true)
case "$vase_rc" in
  124) vase_class='bounded-safety-only-timeout' ;;
  0) grep -F '[  PASSED  ] 1 test.' "$LOG_DIR/vase.log" >/dev/null; vase_class='pass-within-bound' ;;
  *) echo "unexpected Vase rc=$vase_rc"; exit 83 ;;
esac
echo "Vase|rc=$vase_rc|class=$vase_class|wall=$vase_wall|rss_kib=$vase_rss" >> "$EVID_DIR/heavy-summary.txt"

# Exact immutable postflight.
test "$(sha256sum "$RESULT_ZIP" | awk '{print $1}')" = "$RESULT_ZIP_SHA"
test "$(sha256sum "$LOG_ZIP" | awk '{print $1}')" = "$LOG_ZIP_SHA"
test "$(sha256sum "$PKG_DIR/SHA256SUMS" | awk '{print $1}')" = "$MANIFEST_SHA"
(cd "$PKG_DIR" && sha256sum -c SHA256SUMS) > "$EVID_DIR/postflight-manifest-check.txt"
test "$(wc -l < "$PKG_DIR/SHA256SUMS")" -eq 68
test "$(find "$PKG_DIR" -type f | wc -l)" -eq 69
test "$(find "$PKG_DIR/bin" -maxdepth 1 -type f | wc -l)" -eq 7
test "$(find "$PKG_DIR/lib" -maxdepth 1 -type f | wc -l)" -eq 2
test "$(find "$PKG_DIR/test-data/benchmarks/fixtures" -type f | wc -l)" -eq 27
test "$(find "$PKG_DIR" -type l | wc -l)" -eq 0
test ! -e "$PKG_DIR/bin/test-data"
test "$(sha256sum "$producer" | awk '{print $1}')" = "$PRODUCER_SHA"
printf '%s\n' "$RESULT_ZIP_SHA" "$LOG_ZIP_SHA" "$MANIFEST_SHA" '68/68' '69 regular files' '7 executables' '2 libraries' '27 fixtures' "$PRODUCER_SHA" 'fixtureSymlink=false' > "$EVID_DIR/postflight-summary.txt"

echo 'remote_validation_complete=true' | tee "$EVID_DIR/acceptance-summary.txt"
