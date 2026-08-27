#!/usr/bin/env bash
set -uo pipefail

: "${GH_TOKEN:?GH_TOKEN required}"
: "${PACKAGE_ARTIFACT_ID:?PACKAGE_ARTIFACT_ID required}"
: "${PACKAGE_SHA256:?PACKAGE_SHA256 required}"
: "${SEMANTIC_SOURCE:?SEMANTIC_SOURCE required}"
: "${SELECTOR_SHA256:?SELECTOR_SHA256 required}"
: "${ACTIVITY_LOG:?ACTIVITY_LOG required}"

exec > >(tee -a "$ACTIVITY_LOG") 2>&1
out="${RUNNER_TEMP}/m3-cp4c0b-dg-result"
raw="$out/raw"
mkdir -p "$raw"
ledger="$out/case-ledger.tsv"
: > "$ledger"
status="PASS"
postflight="NOT_RUN"
executed=0
passed=0
failed=0
zero_selected=0
cpp_exception_seen=false

write_result() {
  local exit_code="$1"
  local cases_json='[]'
  if [[ -s "$ledger" ]]; then
    cases_json="$(jq -Rn '[inputs | split("\t") | {identity:.[0], exitCode:(.[1]|tonumber), selected:(.[2]|tonumber), status:.[3]}]' < "$ledger")"
  fi
  jq -n \
    --arg turn "M3-CP4c-0b-DG" \
    --arg status "$status" \
    --arg source "$SEMANTIC_SOURCE" \
    --arg artifact "$PACKAGE_ARTIFACT_ID" \
    --arg package_sha "$PACKAGE_SHA256" \
    --arg selector_sha "$SELECTOR_SHA256" \
    --arg postflight "$postflight" \
    --argjson executed "$executed" \
    --argjson passed "$passed" \
    --argjson failed "$failed" \
    --argjson zero_selected "$zero_selected" \
    --argjson cpp_exception_seen "$cpp_exception_seen" \
    --argjson cases "$cases_json" \
    --argjson exit_code "$exit_code" \
    '{turn:$turn,executionStatus:$status,exitCode:$exit_code,semanticSource:$source,packageArtifactId:($artifact|tonumber),packageSha256:$package_sha,selectorPath:".agents/Directional/Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt",selectorSha256:$selector_sha,required:7,executed:$executed,passed:$passed,failed:$failed,zeroSelected:$zero_selected,cppExceptionSeen:$cpp_exception_seen,repositoryTimeoutConfigured:false,configureOccurred:false,compileOccurred:false,relinkOccurred:false,repairOccurred:false,generatedDiscoveryOccurred:false,packageSourceTestFixtureSelectorMutation:false,postflight:$postflight,cases:$cases}' > "$out/result.json"
}

finalize() {
  local rc=$?
  if [[ ! -f "$out/result.json" ]]; then
    if [[ "$status" == "PASS" ]]; then status="ORCHESTRATION_FAILURE"; fi
    write_result "$rc" || true
  fi
  printf 'final_status=%s\nexit_code=%s\nfinished_at=%s\n' "$status" "$rc" "$(date -u +%Y-%m-%dT%H:%M:%SZ)"
}
trap finalize EXIT

fail_orchestration() {
  echo "ORCHESTRATION_FAILURE: $*" >&2
  status="ORCHESTRATION_FAILURE"
  postflight="FAIL"
  write_result 2
  exit 2
}

pkg_zip="${RUNNER_TEMP}/package.zip"
pkg="${RUNNER_TEMP}/package"
rm -rf "$pkg" "$pkg_zip"
mkdir -p "$pkg"

echo "turn=M3-CP4c-0b-DG"
echo "event_sha=${GITHUB_SHA}"
echo "package_artifact_id=${PACKAGE_ARTIFACT_ID}"
echo "semantic_source=${SEMANTIC_SOURCE}"
echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"

gh api -H 'Accept: application/vnd.github+json' \
  "repos/${GITHUB_REPOSITORY}/actions/artifacts/${PACKAGE_ARTIFACT_ID}/zip" > "$pkg_zip" || fail_orchestration "artifact download failed"
actual_zip_sha="$(sha256sum "$pkg_zip" | awk '{print $1}')"
[[ "$actual_zip_sha" == "$PACKAGE_SHA256" ]] || fail_orchestration "package ZIP SHA mismatch: $actual_zip_sha"

unzip -q "$pkg_zip" -d "$pkg" || fail_orchestration "package unzip failed"
[[ "$(stat -c '%a' "$pkg/bin/directional_surface_cell_producer_tests")" == "755" ]] || fail_orchestration "producer executable archived mode is not 755"
(
  cd "$pkg"
  sha256sum -c SHA256SUMS
) > "$out/package-manifest-check.txt" 2>&1 || fail_orchestration "package SHA256SUMS failed"
[[ "$(cat "$pkg/metadata/source-commit.txt")" == "$SEMANTIC_SOURCE" ]] || fail_orchestration "semantic source mismatch"
grep -Fxq 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt" || fail_orchestration "package is not Code+Build-only"
grep -Fxq 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt" || fail_orchestration "package is not GMP authority"
for f in "$pkg"/metadata/source-status-*.txt; do [[ ! -s "$f" ]] || fail_orchestration "non-clean packaged source status: $f"; done

source_archive="$pkg/source/source-${SEMANTIC_SOURCE}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration "packaged source archive missing"
tar -tzf "$source_archive" > "$out/source-archive-list.txt" || fail_orchestration "packaged source archive listing failed"
grep -Fxq 'benchmarks/fixtures/milestone-g/sphere_prescribed.obj' "$out/source-archive-list.txt" || fail_orchestration "known packaged fixture path missing"

find "$pkg" -type f -print0 | sort -z | xargs -0 sha256sum > "$out/package-before.sha256"
find "$pkg" -printf '%m %P\n' | sort > "$out/package-before.modes"

find "$GITHUB_WORKSPACE" -mindepth 1 -maxdepth 1 -exec rm -rf {} +
tar -xzf "$source_archive" -C "$GITHUB_WORKSPACE" || fail_orchestration "packaged source materialization failed"
selector="$GITHUB_WORKSPACE/.agents/Directional/Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt"
[[ -f "$selector" ]] || fail_orchestration "DG selector missing from packaged source"
[[ "$(sha256sum "$selector" | awk '{print $1}')" == "$SELECTOR_SHA256" ]] || fail_orchestration "DG selector SHA mismatch"
[[ "$(wc -l < "$selector")" -eq 7 ]] || fail_orchestration "DG selector count is not seven"
[[ "$(sort "$selector" | uniq | wc -l)" -eq 7 ]] || fail_orchestration "DG selector contains duplicates"
cp "$selector" "$out/selector.txt"
find "$GITHUB_WORKSPACE" -type f -print0 | sort -z | xargs -0 sha256sum > "$out/source-before.sha256"
find "$GITHUB_WORKSPACE" -printf '%m %P\n' | sort > "$out/source-before.modes"

binary="$pkg/bin/directional_surface_cell_producer_tests"
while IFS= read -r identity; do
  [[ -n "$identity" ]] || continue
  executed=$((executed + 1))
  case_log="$raw/$(printf '%02d' "$executed")-$(echo "$identity" | tr '/:' '__').log"
  set +e
  "$binary" --gtest_color=no --gtest_filter="$identity" > "$case_log" 2>&1
  rc=$?
  set -e
  selected="$(grep -Fc "[ RUN      ] $identity" "$case_log" || true)"
  total_run="$(grep -c '^\[ RUN      \]' "$case_log" || true)"
  if grep -Eqi 'C\+\+ exception|unknown file: Failure.*exception' "$case_log"; then cpp_exception_seen=true; fi
  case_status="PASS"
  if [[ "$selected" -ne 1 || "$total_run" -ne 1 ]]; then
    case_status="ORCHESTRATION_FAILURE"
    zero_selected=$((zero_selected + (selected == 0 ? 1 : 0)))
    status="ORCHESTRATION_FAILURE"
    failed=$((failed + 1))
  elif [[ "$rc" -ne 0 ]]; then
    case_status="RED"
    [[ "$status" == "PASS" ]] && status="SEMANTIC_RED"
    failed=$((failed + 1))
  else
    passed=$((passed + 1))
  fi
  printf '%s\t%s\t%s\t%s\n' "$identity" "$rc" "$selected" "$case_status" >> "$ledger"
  echo "identity=$identity exit=$rc selected=$selected status=$case_status"
done < "$selector"

[[ "$executed" -eq 7 ]] || status="ORCHESTRATION_FAILURE"
find "$pkg" -type f -print0 | sort -z | xargs -0 sha256sum > "$out/package-after.sha256"
find "$pkg" -printf '%m %P\n' | sort > "$out/package-after.modes"
find "$GITHUB_WORKSPACE" -type f -print0 | sort -z | xargs -0 sha256sum > "$out/source-after.sha256"
find "$GITHUB_WORKSPACE" -printf '%m %P\n' | sort > "$out/source-after.modes"
if ! cmp -s "$out/package-before.sha256" "$out/package-after.sha256" || \
   ! cmp -s "$out/package-before.modes" "$out/package-after.modes" || \
   ! cmp -s "$out/source-before.sha256" "$out/source-after.sha256" || \
   ! cmp -s "$out/source-before.modes" "$out/source-after.modes"; then
  status="ORCHESTRATION_FAILURE"
  postflight="FAIL"
else
  postflight="PASS"
fi

final_rc=0
[[ "$status" == "SEMANTIC_RED" ]] && final_rc=1
[[ "$status" == "ORCHESTRATION_FAILURE" ]] && final_rc=2
write_result "$final_rc"
exit "$final_rc"
