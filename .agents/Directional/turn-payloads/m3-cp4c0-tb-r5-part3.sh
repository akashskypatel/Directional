postflight() {
  set -euo pipefail
  source "$result_dir/runtime-summary.env"
  (
    cd "$package_dir"
    sha256sum -c SHA256SUMS | tee "$result_dir/manifest-post.txt"
    find . -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > "$result_dir/package-files-post.sha256"
  )
  (
    cd "$GITHUB_WORKSPACE"
    find . -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > "$result_dir/source-files-post.sha256"
    find benchmarks/fixtures -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > "$result_dir/fixtures-post.sha256"
  )
  sha256sum "$selector" > "$result_dir/selector-post.sha256"
  sha256sum "$package_dir/bin/directional_surface_cell_producer_tests" > "$result_dir/producer-executable-post.sha256"
  cmp "$result_dir/package-files-pre.sha256" "$result_dir/package-files-post.sha256"
  cmp "$result_dir/source-files-pre.sha256" "$result_dir/source-files-post.sha256"
  cmp "$result_dir/fixtures-pre.sha256" "$result_dir/fixtures-post.sha256"
  cmp "$result_dir/selector-pre.sha256" "$result_dir/selector-post.sha256"
  cmp "$result_dir/producer-executable-pre.sha256" "$result_dir/producer-executable-post.sha256"
  test "$(sha256sum "$package_zip" | awk '{print $1}')" = "$PACKAGE_SHA256"
  test "$(grep -c ': OK$' "$result_dir/manifest-post.txt")" -eq 27

  first_red_identity=none
  if [ "$first_red_ordinal" -gt 0 ]; then first_red_identity="$(awk -F '\t' -v n="$first_red_ordinal" 'NR>1 && $1==n {print $2}' "$result_dir/gate-ledger.tsv")"; fi
  g5_output="$(cat "$result_dir/g5-outcome.txt")"
  h1_json="$(cat "$result_dir/h1-classification.json")"
  jq -n \
    --arg turn M3-CP4c-0-TB-R5 --arg semanticSource "$SEMANTIC_SOURCE_SHA" --arg workflowControlSha "$GITHUB_SHA" \
    --arg runId "$GITHUB_RUN_ID" --arg packageArtifactId "$PACKAGE_ARTIFACT_ID" --arg packageSha256 "$PACKAGE_SHA256" \
    --arg sourceArchiveSha256 "$SOURCE_ARCHIVE_SHA256" --arg selectorSha256 "$SELECTOR_SHA256" \
    --arg selector316Sha256 "$SELECTOR_316_SHA256" --arg selector328Sha256 "$SELECTOR_328_SHA256" \
    --arg gate "$gate_status" --arg firstRedIdentity "$first_red_identity" --arg g5Outcome "$g5_output" \
    --arg h1Status "$h1_status" --arg h1Classification "$h1_classification" --argjson h1 "$h1_json" \
    --arg q8Status "$q8_status" --arg q8Reason "$q8_reason" --argjson required 338 --argjson executed 338 \
    --argjson passed "$passed" --argjson firstRedOrdinal "$first_red_ordinal" --argjson prefix316Passed "$prefix316_passed" \
    --argjson prefix328Passed "$prefix328_passed" --argjson f3Executed 2 --argjson f3Passed "$f3_passed" \
    --argjson orchestrationErrors "$orchestration_errors" --argjson q8Creditable "$q8_creditable" \
    '{turn:$turn,semanticSource:$semanticSource,workflowControlSha:$workflowControlSha,runId:($runId|tonumber),packageArtifactId:($packageArtifactId|tonumber),packageSha256:$packageSha256,sourceArchiveSha256:$sourceArchiveSha256,selector:{required:$required,executed:$executed,passed:$passed,sha256:$selectorSha256,first316Sha256:$selector316Sha256,first328Sha256:$selector328Sha256,prefix316Passed:$prefix316Passed,prefix328Passed:$prefix328Passed,firstRedOrdinal:$firstRedOrdinal,firstRedIdentity:$firstRedIdentity,gate:$gate},supplementalF3:{executed:$f3Executed,passed:$f3Passed},g5:{credit:"none",owningMeasure:"G5",outcome:$g5Outcome},h1:{credit:"none",owningMeasure:"H1",status:$h1Status,classification:$h1Classification,census:$h1},q8:{creditable:$q8Creditable,status:$q8Status,reason:$q8Reason},orchestrationErrors:$orchestrationErrors,packageMutation:false,sourceMutation:false,testMutation:false,fixtureMutation:false,selectorMutation:false,configure:false,compile:false,relink:false,repair:false,generatedDiscovery:false,performanceBenchmark:false,postflight:"PASS"}' > "$result_dir/result.json"
  echo "postflight=PASS"
  cat "$result_dir/result.json"
}

main_rc=0
echo "runtime_control_sha=$GITHUB_SHA"
echo "semantic_source_sha=$SEMANTIC_SOURCE_SHA"
echo "package_artifact_id=$PACKAGE_ARTIFACT_ID"
echo "turnBoundary=Test+Benchmark-artifact-only"
echo "configure=false"; echo "compile=false"; echo "relink=false"; echo "repair=false"; echo "generatedDiscovery=false"; echo "performanceBenchmark=false"
if ! preflight; then fail_control preflight_failed || true; exit 2; fi
runtime || main_rc=$?
if [ ! -f "$result_dir/runtime-summary.env" ]; then fail_control runtime_summary_missing || true; exit 3; fi
if ! postflight; then fail_control postflight_failed || true; exit 4; fi
source "$result_dir/runtime-summary.env"
if [ "$orchestration_errors" -ne 0 ] || [ "$main_rc" -ne 0 ]; then exit 5; fi
exit 0
