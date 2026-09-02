#!/usr/bin/env bash
set -euo pipefail
work="${RUNNER_TEMP}/m3-cp4c3-tb9"; result="$work/result"; log="$work/tb9.log"; pkg="$work/extract/package79"; mapping="$result/mapping.tsv"; diag_mapping="$result/diagnostic-mapping.tsv"; rows="$result/execution.tsv"
exec > >(tee -a "$log") 2>&1
printf 'phase\tordinal\tidentity\ttarget\texit_code\trun_count\tstatus\tgate_credit\n' > "$rows"
gate_verdict=GREEN; gate_passed=0; first_red_ordinal=''; first_red_identity=''; first_red_target=''; first_red_exit=''
echo '== ORDERED SEMANTIC FRONTIER 1..375 =='
while IFS=$'\t' read -r ordinal identity target; do
  out="$result/gate-$(printf '%03d' "$ordinal").log"; echo "gate ordinal=$ordinal identity=$identity target=$target"
  set +e; (cd "$work/runtime-work" && "$pkg/bin/$target" --gtest_also_run_disabled_tests --gtest_filter="$identity" --gtest_color=no) >"$out" 2>&1; rc=$?; set -e
  cat "$out"; run_count="$(grep -c '\[ RUN      \]' "$out" || true)"
  if [[ "$run_count" != 1 ]]; then printf 'gate\t%s\t%s\t%s\t%s\t%s\tORCHESTRATION_FAILURE\t0\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" >> "$rows"; echo "exact gate filter selected $run_count tests" >&2; exit 2; fi
  if [[ "$rc" -eq 0 ]]; then gate_passed="$ordinal"; status=PASS; credit=1; else gate_verdict=RED; first_red_ordinal="$ordinal"; first_red_identity="$identity"; first_red_target="$target"; first_red_exit="$rc"; status=RED; credit=0; fi
  printf 'gate\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" "$status" "$credit" >> "$rows"
  [[ "$status" == RED ]] && break
done < "$mapping"
printf '%s\n' "gate_verdict=$gate_verdict" "gate_passed=$gate_passed" "first_red_ordinal=$first_red_ordinal" "first_red_identity=$first_red_identity" "first_red_target=$first_red_target" "first_red_exit=$first_red_exit" | tee "$result/gate-verdict.txt"

report_pass=0; report_red=0; report_count=0
if [[ "$gate_verdict" == RED ]]; then
  echo '== FULL REPORT-ONLY REMAINDER THROUGH 375 / ZERO GATE CREDIT =='; start=$((first_red_ordinal + 1))
  for ((ordinal=start; ordinal<=375; ordinal++)); do
    line="$(sed -n "${ordinal}p" "$mapping")"; IFS=$'\t' read -r mapped identity target <<< "$line"; test "$mapped" = "$ordinal"; out="$result/report-only-$(printf '%03d' "$ordinal").log"
    set +e; (cd "$work/runtime-work" && "$pkg/bin/$target" --gtest_also_run_disabled_tests --gtest_filter="$identity" --gtest_color=no) >"$out" 2>&1; rc=$?; set -e
    cat "$out"; run_count="$(grep -c '\[ RUN      \]' "$out" || true)"
    if [[ "$run_count" != 1 ]]; then printf 'report-only\t%s\t%s\t%s\t%s\t%s\tORCHESTRATION_FAILURE\t0\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" >> "$rows"; echo "report-only exact filter selected $run_count tests" >&2; exit 3; fi
    if [[ "$rc" -eq 0 ]]; then report_pass=$((report_pass+1)); status=PASS; else report_red=$((report_red+1)); status=RED; fi; report_count=$((report_count+1))
    printf 'report-only\t%s\t%s\t%s\t%s\t%s\t%s\t0\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" "$status" >> "$rows"
  done
fi
printf '%s\n' "report_only_count=$report_count" "report_only_pass=$report_pass" "report_only_red=$report_red" 'report_only_gate_credit=0' | tee "$result/report-only-verdict.txt"

echo '== DIAGNOSTIC ORDINAL 376 / FRESH PROCESS / ZERO GATE CREDIT =='
IFS=$'\t' read -r diag_ordinal diag_identity diag_target < "$diag_mapping"; test "$diag_ordinal" = 376; diag_out="$result/diagnostic-376.log"
set +e; (cd "$work/runtime-work" && "$pkg/bin/$diag_target" --gtest_also_run_disabled_tests --gtest_filter="$diag_identity" --gtest_color=no) >"$diag_out" 2>&1; diag_rc=$?; set -e
cat "$diag_out"; diag_run_count="$(grep -c '\[ RUN      \]' "$diag_out" || true)"
if [[ "$diag_run_count" != 1 ]]; then printf 'diagnostic\t376\t%s\t%s\t%s\t%s\tORCHESTRATION_FAILURE\t0\n' "$diag_identity" "$diag_target" "$diag_rc" "$diag_run_count" >> "$rows"; echo "diagnostic exact filter selected $diag_run_count tests" >&2; exit 4; fi
[[ "$diag_rc" -eq 0 ]] && diag_status=PASS || diag_status=RED
printf 'diagnostic\t376\t%s\t%s\t%s\t%s\t%s\t0\n' "$diag_identity" "$diag_target" "$diag_rc" "$diag_run_count" "$diag_status" >> "$rows"
printf '%s\n' 'diagnostic_ordinal=376' "diagnostic_identity=$diag_identity" "diagnostic_target=$diag_target" "diagnostic_exit=$diag_rc" "diagnostic_run_count=$diag_run_count" "diagnostic_status=$diag_status" 'diagnostic_gate_credit=0' | tee "$result/diagnostic-verdict.txt"
