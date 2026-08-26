#!/usr/bin/env bash
inventory() {
  local root="$1" out="$2"; shift 2
  : > "$out"
  (cd "$root" && find "$@" -type f -print0 | LC_ALL=C sort -z | while IFS= read -r -d '' f; do
    printf '%s\t%s\t%s\t%s\n' "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" \
      "$(sha256sum "$f" | awk '{print $1}')" "$f"
  done) >> "$out"
}

owner_binary() {
  case "$1" in
    FieldTransportAtlas|SurfaceCellAuthorityKernel)
      echo directional_surface_cell_authority_kernel_tests ;;
    FlowRepStrandsPhase15|PatchDescriptorMilestoneE|PureQuadCompletionPhase18|SurfaceArrangementPhase16|SurfaceCellSourceSupportAndChartAuthority|SurfaceComplexSimplificationPhase17)
      echo directional_surface_cell_completion_tests ;;
    SourceAuthoritativeMeshValidatorPhase22|SurfaceMeshOptimizerPhase19|SurfaceMeshOptimizerPhase22|SurfaceOptimizationRailAuthorityMigration)
      echo directional_surface_cell_validation_tests ;;
    FieldAlignedCurveNetwork|GlobalTopologyPlan|MilestoneGP26|ResolvedBranchContinuation|ResolvedBranchCorrection|SurfaceCellAuthorityContractCutover|SurfaceCellClosedProductContracts|SurfaceCellFieldAlignedNetworkAuthority|SurfaceCellFieldTransitionAuthorityMigration|SurfaceCellIsolationSeamCertificateAuthority|SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration|SurfaceCellPhaseFrontFieldChartAuthorityMigration|SurfaceCellPipelinePhase20|SurfaceCellSegmentRouteTransportAuthorityMigration|SurfaceCellTracingPhase14|SurfaceCellTransitionQuotient|SurfaceCellTypedTransportAuthority|SurfaceCellVertexContinuationRouteTransportAuthorityMigration|SurfaceCellsPhase10|SurfacePhaseFrontProductFactoryAuthority)
      echo directional_surface_cell_producer_tests ;;
    *) return 1 ;;
  esac
}

run_process() {
  local binary="$1" identity="$2" out="$3"
  local start end rc selected passed_count failed_count disabled_count error_count
  start="$(date +%s%3N)"
  set +e
  timeout --signal=TERM 300 "$pkg/bin/$binary" --gtest_filter="$identity" \
    --gtest_fail_if_no_test_selected --gtest_color=no 2>&1 | tee "$out"
  rc=${PIPESTATUS[0]}
  set -e
  end="$(date +%s%3N)"
  selected=0; passed_count=0; failed_count=0; disabled_count=0; error_count=0
  grep -Fq 'Running 1 test from 1 test suite' "$out" && selected=1
  if [[ "$selected" -eq 1 && "$rc" -eq 0 ]]; then
    passed_count=1
  elif [[ "$selected" -eq 1 && "$rc" -eq 1 ]]; then
    failed_count=1
  elif [[ "$rc" -ne 0 ]]; then
    error_count=1
  fi
  if grep -Eq 'YOU HAVE [0-9]+ DISABLED TEST' "$out"; then
    disabled_count="$(grep -Eo 'YOU HAVE [0-9]+ DISABLED TEST' "$out" | tail -1 | grep -Eo '[0-9]+' || echo 0)"
  fi
  PROCESS_RC="$rc" PROCESS_SELECTED="$selected" PROCESS_PASSED="$passed_count" \
    PROCESS_FAILED="$failed_count" PROCESS_DISABLED="$disabled_count" \
    PROCESS_ERRORS="$error_count" PROCESS_ELAPSED_MS="$((end-start))"
}

run_identity() {
  local ordinal="$1" identity="$2" suite binary out credit
  suite="${identity%%.*}"
  if ! binary="$(owner_binary "$suite")"; then
    gate=ORCHESTRATION_FAIL
    failure_kind=unknown-owner
    failure_identity="$identity"
    failure_ordinal="$ordinal"
    return 1
  fi
  out="$raw/$(printf '%03d' "$ordinal")-${identity//[^A-Za-z0-9_.-]/_}.log"
  run_process "$binary" "$identity" "$out"
  executed=$((executed+1))
  if [[ "$PROCESS_SELECTED" -ne 1 || "$PROCESS_ERRORS" -ne 0 ]]; then
    gate=ORCHESTRATION_FAIL
    failure_kind=$([[ "$PROCESS_SELECTED" -ne 1 ]] && echo selected-count || echo process-error)
    failure_identity="$identity"
    failure_ordinal="$ordinal"
    credit=ORCHESTRATION_FAIL
    printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
      "$ordinal" "$identity" "$binary" "$PROCESS_RC" "$PROCESS_SELECTED" "$PROCESS_PASSED" \
      "$PROCESS_FAILED" "$PROCESS_DISABLED" "$PROCESS_ERRORS" "$PROCESS_ELAPSED_MS" "$credit" >> "$outcomes"
    return 1
  fi
  if [[ "$PROCESS_RC" -eq 0 ]]; then
    passed=$((passed+1))
    [[ "$ordinal" -le 316 ]] && prefix316_passed=$((prefix316_passed+1))
    [[ "$ordinal" -le 328 ]] && prefix328_passed=$((prefix328_passed+1))
    [[ "$ordinal" -ge 329 ]] && correction10_passed=$((correction10_passed+1))
    if [[ "$semantic_red_seen" -eq 0 ]]; then credit=CREDIT_PASS; else credit=NON_CREDITING_PASS; fi
  else
    if [[ "$semantic_red_seen" -eq 0 ]]; then
      semantic_red_seen=1
      gate=SEMANTIC_RED
      failure_kind=test-failure
      failure_identity="$identity"
      failure_ordinal="$ordinal"
      credit=CREDIT_RED
      cp "$out" "$results/first-red.log"
    else
      credit=NON_CREDITING_RED
    fi
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$PROCESS_RC" "$PROCESS_SELECTED" "$PROCESS_PASSED" \
    "$PROCESS_FAILED" "$PROCESS_DISABLED" "$PROCESS_ERRORS" "$PROCESS_ELAPSED_MS" "$credit" >> "$outcomes"
  return 0
}

run_supplemental() {
  local ordinal="$1" identity="$2" binary out status
  binary=directional_surface_cell_producer_tests
  out="$raw/supplemental-$(printf '%02d' "$ordinal")-${identity//[^A-Za-z0-9_.-]/_}.log"
  run_process "$binary" "$identity" "$out"
  supplemental_executed=$((supplemental_executed+1))
  if [[ "$PROCESS_SELECTED" -ne 1 || "$PROCESS_ERRORS" -ne 0 ]]; then
    supplemental_orchestration_fail=1; status=ORCHESTRATION_FAIL
  elif [[ "$PROCESS_RC" -eq 0 ]]; then
    supplemental_passed=$((supplemental_passed+1)); status=PASS
  else
    supplemental_semantic_red=1; status=RED
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$PROCESS_RC" "$PROCESS_SELECTED" "$PROCESS_PASSED" \
    "$PROCESS_FAILED" "$PROCESS_DISABLED" "$PROCESS_ERRORS" "$PROCESS_ELAPSED_MS" "$status" >> "$supplemental_outcomes"
}

run_observation() {
  local identity="$1" name="$2" out="$raw/$name.log"
  run_process directional_surface_cell_producer_tests "$identity" "$out"
  test "$PROCESS_SELECTED" -eq 1
  test "$PROCESS_ERRORS" -eq 0
  test "$PROCESS_RC" -ne 0
  printf '%s\t%s\t%s\t%s\n' "$identity" "$PROCESS_RC" "$PROCESS_SELECTED" "$out" >> "$results/q8-observation-processes.tsv"
}
