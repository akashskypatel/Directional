#!/usr/bin/env bash
set -euo pipefail

ARTIFACT_ID=9912976409
COMPILE_RUN_ID=33805683152
COMPILE_JOB_ID=100815534364
EXPECTED_OUTER_SHA='b4cbcbf5304ff94bd815790264ac360fa1275f23b3af2080cffda381a698a851'
EXPECTED_SOURCE_TAR_SHA='cec7db850646ffc4c2de0ed1515afc42d544f989ec83ca20055c30accd9929d3'
EXPECTED_S385='164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca'
EXPECTED_S384='c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564'
EXPECTED_PREFIX365='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
SOURCE_COMMIT='c5d3c65936e14e1c3e2c8afcffbc4236f37aa131'
ARTIFACT_NAME='m3-cp4c3-cb22-r1-result-33805683152'

root="$RUNNER_TEMP/m3-cp4c3-tb20"
pkg="$root/package"
src="$root/source"
view="$root/execution-view"
out="$root/result"
rm -rf "$root"
mkdir -p "$pkg" "$src" "$view/bin" "$view/test-data" "$out/ordinals"

printf '%s\n' \
  'turn=M3-CP4c-3-TB20' \
  'artifactOnly=true' \
  "artifact_id=$ARTIFACT_ID" \
  "compile_run_id=$COMPILE_RUN_ID" \
  "compile_job_id=$COMPILE_JOB_ID" \
  "source_commit=$SOURCE_COMMIT" \
  'runtimeExecution=true' \
  'benchmarkExecution=false' \
  'configureExecution=false' \
  'compileExecution=false' \
  'relinkExecution=false' \
  'packageRepair=false' \
  'modeRepair=false' \
  'generatedDiscovery=false' \
  'sourceMutation=false' \
  'testMutation=false' \
  'fixtureMutation=false' \
  'selectorMutation=false' \
  'benchmarkMutation=false' \
  'executionView=true' \
  'executionViewBinaryMode=hardlink-same-inode' \
  'executionViewFixtureMode=extract-packaged-source-input' \
  "started_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$out/run.env"

meta="$out/artifact-metadata.json"
gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID" > "$meta"
test "$(jq -r .name "$meta")" = "$ARTIFACT_NAME"
test "$(jq -r .workflow_run.id "$meta")" = "$COMPILE_RUN_ID"
test "$(jq -r .digest "$meta")" = "sha256:$EXPECTED_OUTER_SHA"
test "$(jq -r .expired "$meta")" = false

gh api "repos/$GITHUB_REPOSITORY/actions/runs/$COMPILE_RUN_ID/jobs?per_page=100" > "$out/compile-run-jobs.json"
jq -e --argjson id "$COMPILE_JOB_ID" \
  '.jobs[] | select(.id == $id and .status == "completed" and .conclusion == "success")' \
  "$out/compile-run-jobs.json" >/dev/null

zip="$root/cb22-result.zip"
gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID/zip" > "$zip"
test "$(sha256sum "$zip" | awk '{print $1}')" = "$EXPECTED_OUTER_SHA"
unzip -q "$zip" -d "$pkg"
test -f "$pkg/SHA256SUMS"
test "$(wc -l < "$pkg/SHA256SUMS" | tr -d ' ')" = 28
(cd "$pkg" && sha256sum -c SHA256SUMS > "$out/internal-sha256-check.txt")

test "$(cat "$pkg/metadata/source-commit.txt")" = "$SOURCE_COMMIT"
test "$(tr -d '\r\n ' < "$pkg/metadata/build-exit-code.txt")" = 0
test "$(tr -d '\r\n ' < "$pkg/metadata/preflight-exit-code.txt")" = 0
for f in "$pkg"/metadata/source-status*.txt; do test ! -s "$f"; done
grep -Fx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt" >/dev/null
grep -Fx 'turnBoundary=Code+Build-only' "$pkg/metadata/command-boundary.txt" >/dev/null
grep -Fx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt" >/dev/null
grep -F '/libgmpxx.so' "$pkg/metadata/gmp-evidence.txt" >/dev/null
grep -F '/libgmp.so' "$pkg/metadata/gmp-evidence.txt" >/dev/null

for b in \
  directional_benchmarks \
  directional_compiled_api_tests \
  directional_surface_cell_authority_kernel_tests \
  directional_surface_cell_completion_tests \
  directional_surface_cell_producer_tests \
  directional_surface_cell_validation_tests; do
  test -x "$pkg/bin/$b"
  test "$(stat -c '%a' "$pkg/bin/$b")" = 755
done

census() {
  (
    cd "$pkg"
    find . -type f -print0 | LC_ALL=C sort -z |
      while IFS= read -r -d '' f; do
        printf '%s\t%s\t%s\t%s\n' \
          "${f#./}" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" \
          "$(sha256sum "$f" | awk '{print $1}')"
      done
  ) > "$1"
}

census "$out/preflight-census.tsv"
test "$(wc -l < "$out/preflight-census.tsv" | tr -d ' ')" = 29
sha256sum "$out/preflight-census.tsv" > "$out/preflight-census.tsv.sha256"

source_tar="$pkg/source/source-$SOURCE_COMMIT.tar.gz"
test -f "$source_tar"
test "$(sha256sum "$source_tar" | awk '{print $1}')" = "$EXPECTED_SOURCE_TAR_SHA"
tar -xzf "$source_tar" -C "$src"
s365="$src/.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt"
s384="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_384.txt"
s385="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_385.txt"
test "$(sha256sum "$s365" | awk '{print $1}')" = "$EXPECTED_PREFIX365"
test "$(sha256sum "$s384" | awk '{print $1}')" = "$EXPECTED_S384"
test "$(sha256sum "$s385" | awk '{print $1}')" = "$EXPECTED_S385"
test "$(wc -l < "$s385" | tr -d ' ')" = 388
test "$(LC_ALL=C sort -u "$s385" | wc -l | tr -d ' ')" = 388
cmp -s "$s384" <(head -n 384 "$s385")
cmp -s "$s365" <(head -n 365 "$s385")
cp "$s385" "$out/selector-385.txt"

tar -xzf "$source_tar" -C "$view/test-data"
for b in \
  directional_compiled_api_tests \
  directional_surface_cell_authority_kernel_tests \
  directional_surface_cell_completion_tests \
  directional_surface_cell_producer_tests \
  directional_surface_cell_validation_tests; do
  ln "$pkg/bin/$b" "$view/bin/$b"
  test "$(stat -c '%d:%i' "$pkg/bin/$b")" = "$(stat -c '%d:%i' "$view/bin/$b")"
  test "$(sha256sum "$pkg/bin/$b" | awk '{print $1}')" = "$(sha256sum "$view/bin/$b" | awk '{print $1}')"
done
test -d "$view/test-data/benchmarks/fixtures"

printf '%s\n' \
  'preflight=PASS' \
  "artifact_outer_sha256=$EXPECTED_OUTER_SHA" \
  "source_tar_sha256=$EXPECTED_SOURCE_TAR_SHA" \
  "selector385_sha256=$EXPECTED_S385" \
  "selector384_prefix_sha256=$EXPECTED_S384" \
  "accepted365_sha256=$EXPECTED_PREFIX365" \
  'selector_identity_count=388' \
  'manifest_entry_count=28' \
  'package_file_count=29' \
  'packageRepair=false' \
  'modeRepair=false' > "$out/preflight.env"

owner() {
  case $1 in
    [1-9]|1[0-7]|4[1-6]|11[4-9]|1[2-4][0-9]|15[0-4]|17[4-9]|1[89][0-9]|20[0-7]|20[9]|21[0-9]|2[2-4][0-9]|25[0-7]|29[4-9]|3[0-8][0-9])
      echo directional_surface_cell_producer_tests;;
    1[89]|2[0-8]|15[5-9]|16[0-9]|17[0-3])
      echo directional_surface_cell_authority_kernel_tests;;
    29|3[0-9]|40|4[7-9]|[5-9][0-9]|10[0-4]|113|208|25[8-9]|260)
      echo directional_surface_cell_completion_tests;;
    10[5-9]|11[0-2]|26[1-9]|27[0-9]|28[0-9]|29[0-3])
      echo directional_surface_cell_validation_tests;;
    *) echo invalid-owner >&2; return 2;;
  esac
}

printf '%s\n' $'ordinal\tdisposition\texit_code\tbinary\tidentity\tlog_path\tlog_sha256\tterminal_status' > "$out/results.tsv"
pass=0
red=0
apass=0
ared=0
first=0
n=0
: > "$out/targeted-evidence.raw.txt"

while IFS= read -r id; do
  n=$((n+1))
  test -n "$id"
  bin=$(owner "$n")
  rel="ordinals/$(printf '%03d' "$n").log"
  log="$out/$rel"
  echo "TB20 ordinal=$n owner=$bin identity=$id"
  set +e
  (cd "$view"; "$view/bin/$bin" --gtest_filter="$id") >"$log" 2>&1
  code=$?
  set -e

  if ! grep -Fqx "Note: Google Test filter = $id" "$log" || \
     ! grep -Eq '^\[==========\] Running 1 test from 1 test (suite|case)\.$' "$log" || \
     ! grep -Fqx "[ RUN      ] $id" "$log"; then
    echo "invalid exact selection at ordinal $n" >&2
    cat "$log" >&2
    exit 90
  fi

  if [ "$code" -eq 0 ]; then
    terminal=$(grep -F -m1 "[       OK ] $id" "$log" || true)
    test -n "$terminal" || { echo "zero exit without matching OK line at ordinal $n" >&2; exit 91; }
    disposition=PASS
    pass=$((pass+1))
    ((n<=365)) && apass=$((apass+1))
  else
    terminal=$(grep -F -m1 "[  FAILED  ] $id" "$log" || true)
    test -n "$terminal" || { echo "nonzero exit without terminal GoogleTest failure at ordinal $n" >&2; exit 94; }
    disposition=RED
    red=$((red+1))
    ((first==0)) && first=$n
    ((n<=365)) && ared=$((ared+1))
  fi

  logsha=$(sha256sum "$log" | awk '{print $1}')
  terminal=${terminal//$'\t'/ }
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$n" "$disposition" "$code" "$bin" "$id" "$rel" "$logsha" "$terminal" >> "$out/results.tsv"

  case "$n" in
    366|367|368|369|370|371|372|374|384|385|386|387|388)
      printf '===== ordinal=%s identity=%s =====\n' "$n" "$id" >> "$out/targeted-evidence.raw.txt"
      cat "$log" >> "$out/targeted-evidence.raw.txt"
      ;;
  esac
done < "$s385"

test "$n" -eq 388
test $((pass + red)) -eq 388
awk -F'\t' 'NR==1 || $2=="RED"' "$out/results.tsv" > "$out/red-results.tsv"
sha256sum "$out/results.tsv" > "$out/results.tsv.sha256"
find "$out/ordinals" -type f -name '*.log' -print0 | LC_ALL=C sort -z |
  xargs -0 sha256sum > "$out/ordinal-logs.sha256"
cp "$out/ordinals/366.log" "$out/ordinal366.raw.log"
grep -E 'UncutFaceComponentOrbitSeedNotUnique|detailCode=|sourceFace=|sourceFaceLocusKind=|uncutFaceComponent=|uncutFaceComponentSeedCount=|uncutFaceComponentSeedState=|uncutFaceComponentFaceCount=|uncutFaceComponentFacesTruncated=|uncutFaceComponentFace\[|uncutFaceComponentBoundaryEdgeCount=|uncutFaceComponentBoundaryEdgesTruncated=|uncutFaceComponentBoundaryEdge\[|fragmentOwnerComponentCount=|fragmentOwnerComponentsTruncated=|fragmentOwnerComponent\[' \
  "$out/ordinals/366.log" > "$out/ordinal366-decision-evidence.txt" || true

census "$out/postflight-census.tsv"
cmp -s "$out/preflight-census.tsv" "$out/postflight-census.tsv" || {
  diff -u "$out/preflight-census.tsv" "$out/postflight-census.tsv" > "$out/postflight-census.diff" || true
  exit 93
}
sha256sum "$out/postflight-census.tsv" > "$out/postflight-census.tsv.sha256"
echo package_postflight=IDENTICAL > "$out/postflight.env"
red_ordinals="$(awk -F'\t' 'NR>1 && $2=="RED" {printf "%s%s", sep, $1; sep=","}' "$out/results.tsv")"

printf '%s\n' \
  "selector_attempted=$n" \
  'selector_complete=true' \
  "selector_pass=$pass" \
  "selector_red=$red" \
  "accepted_prefix_pass=$apass" \
  "accepted_prefix_red=$ared" \
  "first_red_ordinal=$first" \
  "red_ordinals=${red_ordinals:-none}" \
  'package_postflight=IDENTICAL' \
  'runtimeExecution=true' \
  'benchmarkExecution=false' \
  'configureExecution=false' \
  'compileExecution=false' \
  'relinkExecution=false' \
  'packageRepair=false' \
  'modeRepair=false' \
  'generatedDiscovery=false' \
  'sourceMutation=false' \
  'testMutation=false' \
  'fixtureMutation=false' \
  'selectorMutation=false' \
  'benchmarkMutation=false' \
  "finished_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$out/summary.env"

cat "$out/summary.env"
