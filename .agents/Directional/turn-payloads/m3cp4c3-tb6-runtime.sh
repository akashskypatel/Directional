#!/usr/bin/env bash
set -euo pipefail
work="${RUNNER_TEMP}/m3-cp4c3-tb6"; result="$work/result"; log="$work/tb6.log"
exec > >(tee -a "$log") 2>&1
pkg="$work/extract/package75"; mapping="$result/mapping.tsv"; rows="$result/execution.tsv"
printf 'phase\tordinal\tidentity\ttarget\texit_code\trun_count\tstatus\n' > "$rows"
gate_verdict=GREEN; gate_passed=0; first_red_ordinal=''; first_red_identity=''; first_red_target=''; first_red_exit=''
echo '== ORDERED SEMANTIC GATE =='
while IFS=$'\t' read -r ordinal identity target; do
 out="$result/gate-$(printf '%03d' "$ordinal").log"; echo "gate ordinal=$ordinal identity=$identity target=$target"
 set +e; (cd "$work/runtime-work" && "$pkg/bin/$target" --gtest_filter="$identity" --gtest_color=no) >"$out" 2>&1; rc=$?; set -e
 cat "$out"; run_count="$(grep -c '\[ RUN      \]' "$out" || true)"
 if [[ "$run_count" != 1 ]]; then printf 'gate\t%s\t%s\t%s\t%s\t%s\tORCHESTRATION_FAILURE\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" >> "$rows"; echo "exact filter selected $run_count tests" >&2; exit 2; fi
 if [[ "$rc" -eq 0 ]]; then gate_passed="$ordinal"; status=PASS; else gate_verdict=RED; first_red_ordinal="$ordinal"; first_red_identity="$identity"; first_red_target="$target"; first_red_exit="$rc"; status=RED; fi
 printf 'gate\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" "$status" >> "$rows"
 [[ "$status" == RED ]] && break
done < "$mapping"
{
 echo "gate_verdict=$gate_verdict"; echo "gate_passed=$gate_passed"; echo "first_red_ordinal=$first_red_ordinal"; echo "first_red_identity=$first_red_identity"; echo "first_red_target=$first_red_target"; echo "first_red_exit=$first_red_exit"
} | tee "$result/gate-verdict.txt"
report_pass=0; report_red=0; report_count=0
if [[ "$gate_verdict" == RED ]]; then
 echo '== FULL REPORT-ONLY REMAINDER / ZERO GATE CREDIT =='
 start=$((first_red_ordinal + 1))
 for ((ordinal=start; ordinal<=373; ordinal++)); do
  line="$(sed -n "${ordinal}p" "$mapping")"; IFS=$'\t' read -r mapped identity target <<< "$line"; test "$mapped" = "$ordinal"
  out="$result/report-only-$(printf '%03d' "$ordinal").log"
  set +e; (cd "$work/runtime-work" && "$pkg/bin/$target" --gtest_filter="$identity" --gtest_color=no) >"$out" 2>&1; rc=$?; set -e
  cat "$out"; run_count="$(grep -c '\[ RUN      \]' "$out" || true)"
  if [[ "$run_count" != 1 ]]; then printf 'report-only\t%s\t%s\t%s\t%s\t%s\tORCHESTRATION_FAILURE\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" >> "$rows"; echo "report-only exact filter selected $run_count tests" >&2; exit 3; fi
  if [[ "$rc" -eq 0 ]]; then report_pass=$((report_pass+1)); status=PASS; else report_red=$((report_red+1)); status=RED; fi
  report_count=$((report_count+1)); printf 'report-only\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$target" "$rc" "$run_count" "$status" >> "$rows"
 done
fi
printf 'report_only_count=%s\nreport_only_pass=%s\nreport_only_red=%s\nreport_only_gate_credit=0\n' "$report_count" "$report_pass" "$report_red" | tee "$result/report-only-verdict.txt"
