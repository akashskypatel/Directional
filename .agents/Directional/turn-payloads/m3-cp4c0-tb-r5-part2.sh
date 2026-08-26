runtime() {
  set +e
  set -uo pipefail
  local ledger="$result_dir/gate-ledger.tsv" f3ledger="$result_dir/f3-ledger.tsv"
  : > "$ledger"; : > "$f3ledger"
  printf 'ordinal\tidentity\ttarget\texit_code\tselected\tfailures\terrors\telapsed_ms\tcrediting\tstatus\n' >> "$ledger"
  printf 'identity\texit_code\tselected\tfailures\terrors\telapsed_ms\tstatus\n' >> "$f3ledger"

  first_red_ordinal=0; passed=0; orchestration_errors=0; prefix316_passed=0; prefix328_passed=0
  while IFS=$'\t' read -r ordinal identity target; do
    case_log="$result_dir/identity-results/$(printf '%03d' "$ordinal").log"
    case_json="$result_dir/identity-results/$(printf '%03d' "$ordinal").json"
    IFS=$'\t' read -r rc selected failures errors elapsed_ms status _identity < <(run_one "$identity" "$target" "$case_log" "$case_json")
    if [ "$status" = PASS ]; then
      passed=$((passed+1)); [ "$ordinal" -le 316 ] && prefix316_passed=$((prefix316_passed+1)); [ "$ordinal" -le 328 ] && prefix328_passed=$((prefix328_passed+1))
    elif [ "$status" = ORCHESTRATION_RED ]; then orchestration_errors=$((orchestration_errors+1)); fi
    if [ "$status" != PASS ] && [ "$first_red_ordinal" -eq 0 ]; then first_red_ordinal="$ordinal"; fi
    crediting=true; if [ "$first_red_ordinal" -ne 0 ] && [ "$ordinal" -gt "$first_red_ordinal" ]; then crediting=false; fi
    printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$target" "$rc" "$selected" "$failures" "$errors" "$elapsed_ms" "$crediting" "$status" >> "$ledger"
    echo "gate_identity ordinal=$ordinal status=$status crediting=$crediting identity=$identity"
  done < "$result_dir/route.tsv"

  gate_status=RED
  if [ "$orchestration_errors" -gt 0 ]; then gate_status=ORCHESTRATION_RED
  elif [ "$passed" -eq 338 ]; then gate_status=PASS; fi

  f3_passed=0
  for identity in "$F3_A" "$F3_B"; do
    safe="$(echo "$identity" | tr '.:' '__')"
    IFS=$'\t' read -r rc selected failures errors elapsed_ms status _identity < <(run_one "$identity" directional_surface_cell_producer_tests "$result_dir/supplementals/${safe}.log" "$result_dir/supplementals/${safe}.json")
    [ "$status" = PASS ] && f3_passed=$((f3_passed+1))
    [ "$status" = ORCHESTRATION_RED ] && orchestration_errors=$((orchestration_errors+1))
    printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$identity" "$rc" "$selected" "$failures" "$errors" "$elapsed_ms" "$status" >> "$f3ledger"
    echo "f3_identity status=$status identity=$identity"
  done
  q8_precondition_errors="$orchestration_errors"

  IFS=$'\t' read -r g5_rc g5_selected g5_failures g5_errors g5_elapsed_ms g5_status _identity < <(run_one "$G5_IDENTITY" directional_surface_cell_producer_tests "$result_dir/g5.log" "$result_dir/g5.json")
  [ "$g5_status" = ORCHESTRATION_RED ] && orchestration_errors=$((orchestration_errors+1))
  g5_output="$(grep '^m3Cp4c0G5' "$result_dir/g5.log" | tail -n 1 || true)"
  if [ -z "$g5_output" ]; then g5_status=ORCHESTRATION_RED; orchestration_errors=$((orchestration_errors+1)); fi
  printf '%s\n' "$g5_output" > "$result_dir/g5-outcome.txt"
  printf 'identity=%s\ncredit=none\nowningMeasure=G5\nexit_code=%s\nselected=%s\nfailures=%s\nerrors=%s\nelapsed_ms=%s\nstatus=%s\n' "$G5_IDENTITY" "$g5_rc" "$g5_selected" "$g5_failures" "$g5_errors" "$g5_elapsed_ms" "$g5_status" > "$result_dir/g5-summary.txt"

  IFS=$'\t' read -r h1_rc h1_selected h1_failures h1_errors h1_elapsed_ms h1_status _identity < <(run_one "$H1_IDENTITY" directional_surface_cell_producer_tests "$result_dir/h1.log" "$result_dir/h1.json")
  [ "$h1_status" = ORCHESTRATION_RED ] && orchestration_errors=$((orchestration_errors+1))
  grep '^m3Cp4c0H1' "$result_dir/h1.log" > "$result_dir/h1-census.txt" || true
  h1_lines="$(wc -l < "$result_dir/h1-census.txt" | tr -d ' ')"
  if [ "$h1_lines" -ne 4 ]; then h1_status=ORCHESTRATION_RED; orchestration_errors=$((orchestration_errors+1)); fi
  python3 - "$result_dir/h1-census.txt" "$result_dir/h1-classification.json" <<'PY'
import json, re, sys
from pathlib import Path
p = Path(sys.argv[1]); lines = [x for x in p.read_text().splitlines() if x]
expected = {"two-ring", "four-triangle-fan", "sphere_prescribed", "torus"}
records=[]; witnesses=set(); lifts=[]
for line in lines:
    def field(name, default=None):
        m=re.search(rf"(?:^|;){re.escape(name)}=([^;]+)", line); return m.group(1) if m else default
    witness=field("witness"); witnesses.add(witness)
    pairs=int(field("pairsChecked","0")); violations=int(field("violations","0"))
    local_lifts=[int(x) for x in re.findall(r"signedLift=([-+]?\d+)", line)]
    lifts += local_lifts
    records.append({"witness":witness,"pairsChecked":pairs,"violations":violations,"rate":(violations/pairs if pairs else None),"signedLifts":local_lifts})
total_pairs=sum(x["pairsChecked"] for x in records); total_violations=sum(x["violations"] for x in records)
classification="UNRESOLVED"
if len(lines)!=4 or witnesses!=expected:
    classification="ORCHESTRATION_RED"
elif total_violations==0:
    classification="H-C_A1_CENSUS_ZERO"
elif lifts and len(lifts)==total_violations and all(abs(x)%2==1 for x in lifts):
    classification="H-A_ODD_LIFT_ONLY"
elif total_pairs and 0.40 <= total_violations/total_pairs <= 0.60:
    classification="SYSTEMATIC_APPROX_HALF"
else:
    classification="H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED"
json.dump({"classification":classification,"witnesses":records,"totalPairs":total_pairs,"totalViolations":total_violations,"overallRate":(total_violations/total_pairs if total_pairs else None)}, open(sys.argv[2],"w"), indent=2, sort_keys=True)
print(Path(sys.argv[2]).read_text())
PY
  h1_classification="$(jq -r .classification "$result_dir/h1-classification.json")"
  if [ "$h1_classification" = ORCHESTRATION_RED ]; then h1_status=ORCHESTRATION_RED; orchestration_errors=$((orchestration_errors+1)); fi
  printf 'identity=%s\ncredit=none\nowningMeasure=H1\nexit_code=%s\nselected=%s\nfailures=%s\nerrors=%s\nelapsed_ms=%s\nstatus=%s\nclassification=%s\n' "$H1_IDENTITY" "$h1_rc" "$h1_selected" "$h1_failures" "$h1_errors" "$h1_elapsed_ms" "$h1_status" "$h1_classification" > "$result_dir/h1-summary.txt"

  q8_creditable=false; q8_status=NOT_CREDITABLE; q8_reason=precondition_not_green
  criterion1=RED; criterion2=NOT_EVALUABLE; criterion3=NOT_EVALUABLE; criterion4=NOT_EVALUABLE; criterion5=CARRIED_UNCHANGED_NOT_RERUN
  [ "$prefix316_passed" -eq 316 ] && criterion1=PASS
  t1_status="$(awk -F '\t' -v id="$T1_IDENTITY" '$2==id {print $10}' "$ledger")"
  [ "$t1_status" = PASS ] && criterion4=PASS || criterion4=RED
  if [ "$gate_status" = PASS ] && [ "$f3_passed" -eq 2 ] && [ "$q8_precondition_errors" -eq 0 ]; then
    q8_creditable=true; q8_status=RED; q8_reason=criterion2_sphere_network_not_published; criterion2=RED
    if [ "$g5_status" = ORCHESTRATION_RED ] || [ -z "$g5_output" ]; then
      q8_status=ORCHESTRATION_RED; q8_reason=g5_outcome_unavailable
    elif [[ "$g5_output" == *';fieldAlignedCurveNetwork=true;'* ]]; then
      trace_count="$(printf '%s\n' "$g5_output" | sed -n 's/.*;traceCount=\([0-9][0-9]*\).*/\1/p')"
      intersection_count="$(printf '%s\n' "$g5_output" | sed -n 's/.*TraceIntersection=\([0-9][0-9]*\).*/\1/p')"
      if [ "$trace_count" = 24 ]; then criterion2=PASS; else q8_reason="criterion2_sphere_trace_count_${trace_count:-missing}_expected_24"; fi
      if [ "$criterion2" = PASS ]; then
        if [ -n "$intersection_count" ] && [ "$intersection_count" -gt 0 ]; then criterion3=PASS; else criterion3=RED; q8_reason=criterion3_sphere_terminal_trace_intersection_missing; fi
      fi
      if [ "$criterion2" = PASS ] && [ "$criterion3" = PASS ] && [ "$criterion4" = PASS ]; then
        q8_status=PASS; q8_reason=criteria1_to5_satisfied_with_criterion5_carried_unchanged
      elif [ "$criterion2" = PASS ] && [ "$criterion4" != PASS ]; then q8_reason=criterion4_frozen_crossover_identity_not_green; fi
    fi
  fi
  cat > "$result_dir/q8.txt" <<EOF
creditable=$q8_creditable
status=$q8_status
reason=$q8_reason
criterion1_accepted_prefix=$criterion1
criterion2_sphere_network_24_traces=$criterion2
criterion3_terminal_trace_intersection=$criterion3
criterion4_frozen_face_1-2-5_crossover=$criterion4
criterion5_torus_mechanical=$criterion5
EOF

  cat > "$result_dir/runtime-summary.env" <<EOF
gate_status=$gate_status
required=338
executed=338
passed=$passed
first_red_ordinal=$first_red_ordinal
prefix316_passed=$prefix316_passed
prefix328_passed=$prefix328_passed
f3_executed=2
f3_passed=$f3_passed
g5_status=$g5_status
h1_status=$h1_status
h1_classification=$h1_classification
q8_creditable=$q8_creditable
q8_status=$q8_status
q8_reason=$q8_reason
orchestration_errors=$orchestration_errors
fresh_processes=342
EOF
}

