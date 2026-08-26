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

run_observation() {
  local identity="$1" name="$2" out="$raw/$name.log" rc selected
  set +e
  "$pkg/bin/directional_surface_cell_producer_tests" \
    --gtest_filter="$identity" --gtest_fail_if_no_test_selected --gtest_color=no \
    2>&1 | tee "$out"
  rc=${PIPESTATUS[0]}
  set -e
  selected=0
  grep -Fq 'Running 1 test from 1 test suite' "$out" && selected=1
  test "$selected" -eq 1
  test "$rc" -ne 0
  printf '%s\t%s\t%s\n' "$identity" "$rc" "$out" >> "$results/q8-observation-processes.tsv"
}

run_identity() {
  local ordinal="$1" identity="$2" suite binary out start end rc selected
  suite="${identity%%.*}"
  if ! binary="$(owner_binary "$suite")"; then
    gate=ORCHESTRATION_FAIL
    failure_kind=unknown-owner
    failure_identity="$identity"
    failure_ordinal="$ordinal"
    return 1
  fi
  out="$raw/$(printf '%03d' "$ordinal")-${identity//[^A-Za-z0-9_.-]/_}.log"
  start="$(date +%s%3N)"
  set +e
  "$pkg/bin/$binary" --gtest_filter="$identity" --gtest_fail_if_no_test_selected \
    --gtest_color=no 2>&1 | tee "$out"
  rc=${PIPESTATUS[0]}
  set -e
  end="$(date +%s%3N)"
  selected=0
  grep -Fq 'Running 1 test from 1 test suite' "$out" && selected=1
  printf '%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$binary" \
    "$rc" "$selected" "$((end-start))" >> "$outcomes"
  executed=$((executed+1))
  if [[ "$selected" -ne 1 ]]; then
    gate=ORCHESTRATION_FAIL
    failure_kind=selected-count
    failure_identity="$identity"
    failure_ordinal="$ordinal"
    return 1
  fi
  if [[ "$rc" -ne 0 ]]; then
    gate=SEMANTIC_RED
    failure_kind=test-failure
    failure_identity="$identity"
    failure_ordinal="$ordinal"
    return 1
  fi
  passed=$((passed+1))
  [[ "$ordinal" -le 316 ]] && prefix316_passed=$((prefix316_passed+1))
  [[ "$ordinal" -le 328 ]] && prefix328_passed=$((prefix328_passed+1))
  [[ "$ordinal" -ge 329 ]] && correction10_passed=$((correction10_passed+1))
}
