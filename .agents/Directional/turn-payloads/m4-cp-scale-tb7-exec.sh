#!/usr/bin/env bash
set -euo pipefail
: "${CANDIDATE_ARTIFACT_ID:?}"
: "${CANDIDATE_PROVIDER_SHA256:?}"
: "${SEMANTIC_SOURCE_SHA:?}"
: "${SOURCE_ARCHIVE_SHA256:?}"
: "${PACKAGE_MANIFEST_SHA256:?}"
: "${SELECTOR_SHA256:?}"
: "${PREFIX424_SHA256:?}"
: "${ROW425_IDENTITY:?}"
log="${RUNNER_TEMP}/m4-cp-scale-tb7-exec.log"
result="${RUNNER_TEMP}/tb7-result"
evidence="${RUNNER_TEMP}/tb7-evidence"
package="${RUNNER_TEMP}/immutable-package"
source_root="${RUNNER_TEMP}/semantic-source"
execution="${RUNNER_TEMP}/execution-view"
raw="$evidence/raw/selector"
resources="$evidence/resources/selector"
runtime_started=false
rm -rf "$result" "$evidence" "$package" "$source_root" "$execution"
mkdir -p "$result" "$evidence/preflight" "$evidence/postflight" "$raw" "$resources"
printf '%s\n' 'status=BLOCKED_PRE_RUNTIME' 'runtimeStarted=false' 'runtimeCompleted=false' > "$result/final-status.txt"
finish_on_error() {
  rc=$?
  if [[ "$rc" -ne 0 ]]; then
    if [[ "$runtime_started" == true ]]; then
      printf '%s\n' 'status=BLOCKED_INFRASTRUCTURE' 'runtimeStarted=true' 'runtimeCompleted=false' > "$result/final-status.txt"
    else
      printf '%s\n' 'status=BLOCKED_PRE_RUNTIME' 'runtimeStarted=false' 'runtimeCompleted=false' > "$result/final-status.txt"
    fi
    echo "harness_exit=${rc}" | tee -a "$log"
  fi
}
trap finish_on_error EXIT
helper="${GITHUB_WORKSPACE}/.agents/Directional/turn-payloads/m4-cp-scale-tb7-helper.py"
census_tree() { python3 "$helper" census "$1" "$2"; }
parse_gtest() { python3 "$helper" parse-gtest "$1"; }
{
  echo "workflow=${GITHUB_WORKFLOW}"
  echo "run_id=${GITHUB_RUN_ID}"
  echo "event=${GITHUB_EVENT_NAME}"
  echo "event_sha=${GITHUB_SHA}"
  echo "candidate_artifact_id=${CANDIDATE_ARTIFACT_ID}"
  echo "candidate_provider_sha256=${CANDIDATE_PROVIDER_SHA256}"
  echo "semantic_source_sha=${SEMANTIC_SOURCE_SHA}"
  echo "selector_sha256=${SELECTOR_SHA256}"
  echo 'runtime_boundary=Test+Benchmark artifact-only'
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
} | tee -a "$log"
meta="$evidence/artifact-metadata.json"
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/${CANDIDATE_ARTIFACT_ID}" > "$meta"
jq -e --argjson id "$CANDIDATE_ARTIFACT_ID" '.id==$id and .expired==false' "$meta" >/dev/null
jq -e --arg digest "sha256:${CANDIDATE_PROVIDER_SHA256}" '.digest==$digest' "$meta" >/dev/null
candidate_zip="${RUNNER_TEMP}/candidate-artifact.zip"
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/${CANDIDATE_ARTIFACT_ID}/zip" > "$candidate_zip"
test "$(sha256sum "$candidate_zip" | awk '{print $1}')" = "$CANDIDATE_PROVIDER_SHA256"
mkdir -p "$package"
unzip -q "$candidate_zip" -d "$package"
test -f "$package/SHA256SUMS"
test "$(sha256sum "$package/SHA256SUMS" | awk '{print $1}')" = "$PACKAGE_MANIFEST_SHA256"
test "$(wc -l < "$package/SHA256SUMS" | tr -d ' ')" = 28
(cd "$package" && sha256sum -c SHA256SUMS) > "$evidence/preflight/package-sha256-check.txt"
census_tree "$package" "$evidence/package-census-before.tsv"
test "$(cat "$package/metadata/source-commit.txt")" = "$SEMANTIC_SOURCE_SHA"
test "$(cat "$package/metadata/build-exit-code.txt")" = 0
test "$(cat "$package/metadata/preflight-exit-code.txt")" = 0
for f in "$package"/metadata/source-status-*.txt; do test ! -s "$f"; done
grep -Fx 'runtimeExecution=false' "$package/metadata/command-boundary.txt" >/dev/null
grep -Fx 'turnBoundary=Code+Build-only' "$package/metadata/command-boundary.txt" >/dev/null
grep -Fx 'exactArithmeticBackend=GMP' "$package/metadata/command-boundary.txt" >/dev/null
grep -Fx 'manifestExcludesSelf=true' "$package/metadata/command-boundary.txt" >/dev/null
grep -F 'libgmpxx' "$package/metadata/gmp-evidence.txt" >/dev/null
grep -F 'libgmp.so' "$package/metadata/gmp-evidence.txt" >/dev/null
source_archive="$package/source/source-${SEMANTIC_SOURCE_SHA}.tar.gz"
test -f "$source_archive"
test "$(sha256sum "$source_archive" | awk '{print $1}')" = "$SOURCE_ARCHIVE_SHA256"
mkdir -p "$source_root"
tar -xzf "$source_archive" -C "$source_root"
census_tree "$source_root" "$evidence/source-census-before.tsv"
selector="$source_root/.agents/Directional/Architecture_M4_CP_SCALE_CB8_Required_Green_Selector_425.txt"
test -f "$selector"
test "$(sha256sum "$selector" | awk '{print $1}')" = "$SELECTOR_SHA256"
test "$(head -n 424 "$selector" | sha256sum | awk '{print $1}')" = "$PREFIX424_SHA256"
test "$(tail -n 1 "$selector")" = "$ROW425_IDENTITY"
python3 "$helper" selector-check "$selector" "$ROW425_IDENTITY"
owner_map="$evidence/selector425-owner-map.tsv"
python3 "$helper" owner-map "$source_root" "$selector" "$owner_map" "$ROW425_IDENTITY"
awk -F '\t' 'NR>1 {c[$3]++} END {printf "authority-kernel=%d\nproducer=%d\ncompletion=%d\nvalidation=%d\n",c["authority-kernel"],c["producer"],c["completion"],c["validation"]}' "$owner_map" > "$evidence/owner-census.txt"
for b in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do
  p="$package/bin/$b"; test -f "$p"; test -x "$p"; test "$(stat -c '%a' "$p")" = 755
  ldd "$p" > "$evidence/preflight/ldd-${b}.txt"; ! grep -Fq 'not found' "$evidence/preflight/ldd-${b}.txt"
done
grep -F 'libgmpxx.so' "$evidence/preflight/ldd-directional_surface_cell_producer_tests.txt" >/dev/null
grep -F 'libgmp.so' "$evidence/preflight/ldd-directional_surface_cell_producer_tests.txt" >/dev/null
mkdir -p "$execution/test-data/benchmarks"
cp -a "$package/bin" "$execution/bin"
cp -a "$package/lib" "$execution/lib"
cp -a "$source_root/benchmarks/fixtures" "$execution/test-data/benchmarks/fixtures"
census_tree "$source_root/benchmarks/fixtures" "$evidence/source-fixtures-census.tsv"
census_tree "$execution/test-data/benchmarks/fixtures" "$evidence/execution-fixtures-census.tsv"
cmp "$evidence/source-fixtures-census.tsv" "$evidence/execution-fixtures-census.tsv"
census_tree "$execution" "$evidence/execution-view-before.tsv"
printf '%s\n' 'configureExecution=false' 'compileExecution=false' 'relinkExecution=false' 'repairExecution=false' 'generatedDiscovery=false' 'mutationExecution=false' 'benchmarkExecution=false' > "$evidence/execution-prohibitions.txt"
python3 "$helper" immutable-input "$evidence/immutable-input.txt"
ledger="$evidence/selector425-process-ledger.tsv"
printf 'ordinal\tidentity\towner\tbinary\tsource_definition\tcommand\texit\tselected\texecuted\tpassed\tskipped\telapsed_ms\tresult\tstdout\tstderr\n' > "$ledger"
runtime_started=true
printf '%s\n' 'status=BLOCKED_INFRASTRUCTURE' 'runtimeStarted=true' 'runtimeCompleted=false' > "$result/final-status.txt"
while IFS=$'\t' read -r ordinal identity owner binary source_definition; do
  [[ "$ordinal" == ordinal ]] && continue
  stem="ordinal-$(printf '%03d' "$ordinal")"; stdout="$raw/${stem}.stdout.txt"; stderr="$raw/${stem}.stderr.txt"; timefile="$resources/${stem}.time.txt"
  command="$execution/bin/$binary --gtest_filter=$identity --gtest_color=no"
  started="$(date +%s%3N)"
  set +e
  /usr/bin/time -v -o "$timefile" "$execution/bin/$binary" --gtest_filter="$identity" --gtest_color=no >"$stdout" 2>"$stderr"
  exit_code=$?
  set -e
  ended="$(date +%s%3N)"; elapsed=$((ended-started))
  mapfile -t counts < <(parse_gtest "$stdout")
  selected="${counts[0]:-0}"; executed="${counts[1]:-0}"; passed="${counts[2]:-0}"; skipped="${counts[3]:-0}"
  row_result=RED
  if [[ "$selected" -ne 1 || "$executed" -ne 1 ]]; then row_result=SELECTION_MISMATCH
  elif [[ "$exit_code" -eq 0 && "$passed" -eq 1 && "$skipped" -eq 0 ]]; then row_result=PASS
  elif [[ "$skipped" -ne 0 ]]; then row_result=SKIP
  elif [[ "$exit_code" -ge 128 ]]; then row_result=CRASH
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$owner" "$binary" "$source_definition" "$command" "$exit_code" "$selected" "$executed" "$passed" "$skipped" "$elapsed" "$row_result" "${stdout#$evidence/}" "${stderr#$evidence/}" >> "$ledger"
  printf '[TB7 selector %s/425] %s %s\n' "$ordinal" "$row_result" "$identity"
done < "$owner_map"
python3 "$helper" summary "$ledger" "$evidence/selector425-summary.txt"
(cd "$package" && sha256sum -c SHA256SUMS) > "$evidence/postflight/package-sha256-check.txt"
test "$(sha256sum "$package/SHA256SUMS" | awk '{print $1}')" = "$PACKAGE_MANIFEST_SHA256"
test "$(sha256sum "$source_archive" | awk '{print $1}')" = "$SOURCE_ARCHIVE_SHA256"
test "$(sha256sum "$selector" | awk '{print $1}')" = "$SELECTOR_SHA256"
test "$(head -n 424 "$selector" | sha256sum | awk '{print $1}')" = "$PREFIX424_SHA256"
census_tree "$package" "$evidence/package-census-after.tsv"
census_tree "$source_root" "$evidence/source-census-after.tsv"
census_tree "$execution" "$evidence/execution-view-after.tsv"
cmp "$evidence/package-census-before.tsv" "$evidence/package-census-after.tsv"
cmp "$evidence/source-census-before.tsv" "$evidence/source-census-after.tsv"
cmp "$evidence/execution-view-before.tsv" "$evidence/execution-view-after.tsv"
printf '%s\n' 'package_census_equal=true' 'source_census_equal=true' 'execution_view_census_equal=true' 'package_manifest_verified=true' "selector_sha256=${SELECTOR_SHA256}" "prefix424_sha256=${PREFIX424_SHA256}" > "$evidence/postflight-immutability.txt"
passn="$(awk -F= '$1=="pass"{print $2}' "$evidence/selector425-summary.txt")"
executedn="$(awk -F= '$1=="executed"{print $2}' "$evidence/selector425-summary.txt")"
status=MECHANICALLY_RED
if [[ "$passn" == 425 && "$executedn" == 425 ]]; then status=MECHANICALLY_GREEN; fi
printf '%s\n' "status=${status}" "selector425=${passn}/425" 'runtime_processes_expected=425' "runtime_processes_actual=${executedn}" 'postflightComplete=true' 'runtimeStarted=true' 'runtimeCompleted=true' > "$evidence/final-status.txt"
cp "$evidence/final-status.txt" "$result/final-status.txt"
cp "$evidence/selector425-summary.txt" "$result/selector425-summary.txt"
(cd "$evidence" && find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS)
(cd "$evidence" && zip -q -r "$result/Directional__M4-CP-SCALE-TB7-EXEC__evidence.zip" .)
sha256sum "$result/Directional__M4-CP-SCALE-TB7-EXEC__evidence.zip" > "$result/evidence.zip.sha256"
cat "$result/final-status.txt"
