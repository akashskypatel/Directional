#!/usr/bin/env bash
set -Eeuo pipefail
log="${RUNNER_TEMP}/m3-cp4c0-tb-r3.log"
exec > >(tee -a "$log") 2>&1
work="${RUNNER_TEMP}/m3-cp4c0-tb-r3"
pkg="$work/package"
evidence="$work/evidence-source"
results="$work/results"
raw="$results/raw"
mkdir -p "$pkg" "$evidence" "$raw"
selector="$GITHUB_WORKSPACE/$SELECTOR_PATH"
source "$(dirname "$0")/lib.sh"

echo 'phase=preflight'
zip="$work/package.zip"
curl --fail --location --retry 5 --retry-all-errors --retry-delay 2 \
  -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${PACKAGE_ARTIFACT_ID}/zip" -o "$zip"
test "$(sha256sum "$zip" | awk '{print $1}')" = "$PACKAGE_SHA256"
unzip -q "$zip" -d "$pkg"
manifest_lines="$(wc -l < "$pkg/SHA256SUMS" | tr -d ' ')"
test "$manifest_lines" -eq 27
(cd "$pkg" && sha256sum -c SHA256SUMS)
test "$(cat "$pkg/metadata/source-commit.txt")" = "$EVIDENCE_SOURCE_SHA"
grep -Fqx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt"
grep -Fqx 'turnBoundary=Code+Build-only' "$pkg/metadata/command-boundary.txt"
for f in "$pkg"/metadata/source-status*.txt; do test ! -s "$f"; done
test -s "$pkg/source/source-${EVIDENCE_SOURCE_SHA}.tar.gz"
tar -xzf "$pkg/source/source-${EVIDENCE_SOURCE_SHA}.tar.gz" -C "$evidence"

test "$(sha256sum "$selector" | awk '{print $1}')" = "$SELECTOR_SHA256"
test "$(grep -cve '^$' "$selector")" -eq 338
test "$(sort -u "$selector" | wc -l)" -eq 338
head -n 316 "$selector" > "$work/prefix316.txt"
head -n 328 "$selector" > "$work/prefix328.txt"
test "$(sha256sum "$work/prefix316.txt" | awk '{print $1}')" = "$PREFIX316_SHA256"
test "$(sha256sum "$work/prefix328.txt" | awk '{print $1}')" = "$PREFIX328_SHA256"
test "$(sed -n '329,338p' "$selector" | grep -c '^ResolvedBranchCorrection\.')" -eq 10
grep -Fq "TEST(ResolvedBranchCorrection," "$evidence/tests/FieldAlignedCurveNetworkTests.cpp"
grep -Fq 'NetworkDiagnosticsContainNoControlCharactersForAnyCode)' "$evidence/tests/FieldAlignedCurveNetworkTests.cpp"
grep -Fq 'TracingPathNeverPublishesSeedIdentityAsFailureLocus)' "$evidence/tests/FieldAlignedCurveNetworkTests.cpp"
for identity in "$SUPPLEMENTAL_1" "$SUPPLEMENTAL_2"; do
  test "$(owner_binary "${identity%%.*}")" = directional_surface_cell_producer_tests
done
for path in include src tests benchmarks benchmark-results cmake CMakeLists.txt; do
  diff -qr "$evidence/$path" "$GITHUB_WORKSPACE/$path"
done
test -z "$(git status --porcelain=v1)"
inventory "$pkg" "$results/package-pre.tsv" .
inventory "$GITHUB_WORKSPACE" "$results/runtime-inputs-pre.tsv" include src tests benchmarks benchmark-results cmake CMakeLists.txt
sha256sum "$selector" > "$results/selector-pre.sha256"
git status --porcelain=v1 > "$results/source-status-pre.txt"
printf '%s\n' 'preflight=PASS' "packageSha256=$PACKAGE_SHA256" "manifestChecks=27/27" \
  "sourceSha=$EVIDENCE_SOURCE_SHA" "controlSha=$GITHUB_SHA" "selectorSha256=$SELECTOR_SHA256" \
  "prefix316Sha256=$PREFIX316_SHA256" "prefix328Sha256=$PREFIX328_SHA256" \
  'runtimeExecutionInCB3=false' 'q8E6Present=true' | tee "$results/preflight.txt"

echo 'phase=required-gate'
outcomes="$results/identity-results.tsv"
printf 'ordinal\tidentity\tbinary\texit_code\tselected\tpassed\tfailed\tdisabled\terrors\telapsed_ms\tcredit\n' > "$outcomes"
executed=0; passed=0; prefix316_passed=0; prefix328_passed=0; correction10_passed=0
semantic_red_seen=0; gate=PASS; failure_kind=none; failure_identity=none; failure_ordinal=0
ordinal=0
while IFS= read -r identity; do
  [[ -n "$identity" ]] || continue
  ordinal=$((ordinal+1))
  if ! run_identity "$ordinal" "$identity"; then break; fi
done < "$selector"
if [[ "$gate" != ORCHESTRATION_FAIL ]]; then
  if [[ "$executed" -ne 338 ]]; then
    gate=ORCHESTRATION_FAIL; failure_kind=incomplete-gate
  elif [[ "$semantic_red_seen" -eq 0 && "$passed" -eq 338 ]]; then
    gate=PASS
  else
    gate=SEMANTIC_RED
  fi
fi

echo 'phase=supplemental-f3'
supplemental_outcomes="$results/supplemental-results.tsv"
printf 'ordinal\tidentity\tbinary\texit_code\tselected\tpassed\tfailed\tdisabled\terrors\telapsed_ms\tstatus\n' > "$supplemental_outcomes"
supplemental_executed=0; supplemental_passed=0; supplemental_semantic_red=0; supplemental_orchestration_fail=0
run_supplemental 1 "$SUPPLEMENTAL_1"
run_supplemental 2 "$SUPPLEMENTAL_2"
if [[ "$supplemental_orchestration_fail" -ne 0 || "$supplemental_executed" -ne 2 ]]; then
  supplemental_gate=ORCHESTRATION_FAIL
elif [[ "$supplemental_semantic_red" -eq 0 && "$supplemental_passed" -eq 2 ]]; then
  supplemental_gate=PASS
else
  supplemental_gate=SEMANTIC_RED
fi

q8=NOT_RUN; q8_creditable=false; q8_trace_count=none; q8_intersections=none
q8_face_crossover=NOT_RUN; q8_torus_trace_count=none; q8_mechanical_a1=NOT_RUN
q8_crossover_contract_identity=NOT_RUN
: > "$results/q8-observation-processes.tsv"
if [[ "$gate" == PASS && "$supplemental_gate" == PASS ]]; then
  q8_creditable=true
  echo 'phase=q8-authorized-observation'
  run_observation 'GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable' 'q8-sphere-reachability'
  run_observation 'GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable' 'q8-torus-reachability'
  run_observation 'GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable' 'q8-mechanical-reachability'
  sphere_log="$raw/q8-sphere-reachability.log"; torus_log="$raw/q8-torus-reachability.log"; mechanical_log="$raw/q8-mechanical-reachability.log"
  q8_trace_count="$(grep -o 'networkTraceCount=[0-9]*' "$sphere_log" | tail -1 | cut -d= -f2 || true)"
  q8_intersections="$(grep -o 'terminalTraceIntersectionCount=[0-9]*' "$sphere_log" | tail -1 | cut -d= -f2 || true)"
  q8_torus_trace_count="$(grep -o 'networkTraceCount=[0-9]*' "$torus_log" | tail -1 | cut -d= -f2 || true)"
  [[ -n "$q8_trace_count" ]] || q8_trace_count=none; [[ -n "$q8_intersections" ]] || q8_intersections=none; [[ -n "$q8_torus_trace_count" ]] || q8_torus_trace_count=none
  if grep -Fq 'failedStage=field-transport-atlas' "$mechanical_log" && grep -Fq 'IncompleteCycleBasis' "$mechanical_log"; then q8_mechanical_a1=PASS; else q8_mechanical_a1=RED; fi
  if awk -F '\t' '$1==317 && $4==0 && $5==1 {found=1} END {exit found?0:1}' "$outcomes"; then q8_crossover_contract_identity=PASS; else q8_crossover_contract_identity=RED; fi
  # The immutable package exposes the generic ordinal-317 crossover contract, but no
  # direct runtime observer for frozen Q8 item 4's exact sphere face 1-2-5/incoming 1-2.
  # Do not substitute the generic contract for that prediction.
  q8_face_crossover=NOT_OBSERVED
  q8=RED
  if [[ "$q8_trace_count" == 24 && "$q8_intersections" != none && "$q8_intersections" -ge 1 && \
        "$q8_face_crossover" == PASS && "$q8_torus_trace_count" == 0 && "$q8_mechanical_a1" == PASS ]]; then q8=PASS; fi
fi

cat > "$results/summary.env" <<EOF2
gate=$gate
executed=$executed
passed=$passed
prefix316_passed=$prefix316_passed
prefix328_passed=$prefix328_passed
correction10_passed=$correction10_passed
failure_kind=$failure_kind
failure_ordinal=$failure_ordinal
failure_identity=$failure_identity
supplemental_gate=$supplemental_gate
supplemental_executed=$supplemental_executed
supplemental_passed=$supplemental_passed
q8_creditable=$q8_creditable
q8=$q8
q8_trace_count=$q8_trace_count
q8_terminal_trace_intersections=$q8_intersections
q8_face_1_2_5_incoming_1_2_crossover=$q8_face_crossover
q8_crossover_contract_identity=$q8_crossover_contract_identity
q8_torus_trace_count=$q8_torus_trace_count
q8_mechanical_a1=$q8_mechanical_a1
EOF2
cat "$results/summary.env"

echo 'phase=post-integrity'
inventory "$pkg" "$results/package-post.tsv" .
inventory "$GITHUB_WORKSPACE" "$results/runtime-inputs-post.tsv" include src tests benchmarks benchmark-results cmake CMakeLists.txt
sha256sum "$selector" > "$results/selector-post.sha256"
git status --porcelain=v1 > "$results/source-status-post.txt"
cmp "$results/package-pre.tsv" "$results/package-post.tsv"
cmp "$results/runtime-inputs-pre.tsv" "$results/runtime-inputs-post.tsv"
cmp "$results/selector-pre.sha256" "$results/selector-post.sha256"
cmp "$results/source-status-pre.txt" "$results/source-status-post.txt"
test ! -s "$results/source-status-post.txt"
printf '%s\n' 'packageMutation=false' 'sourceMutation=false' 'testMutation=false' 'fixtureMutation=false' \
  'selectorMutation=false' 'configure=false' 'compile=false' 'relink=false' 'repair=false' \
  'generatedDiscovery=false' 'performanceBenchmark=false' > "$results/mutation-flags.txt"
cat "$results/mutation-flags.txt"
