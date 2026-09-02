#!/usr/bin/env bash
set -euo pipefail

ARTIFACT_ID=9867334959
EXPECTED_OUTER_SHA='67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55'
EXPECTED_INNER_SHA='8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff'
EXPECTED_SOURCE_TAR_SHA='ca898abdf3e5a4d01429048f13a2a6f09dd6bc70dabd3b866209533f9e43db95'
EXPECTED_SELECTOR_365_PREFIX_SHA='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
EXPECTED_SELECTOR_373_SHA='b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834'
EXPECTED_SELECTOR_374_SHA='d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f'
EXPECTED_SELECTOR_375_SHA='aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0'
EXPECTED_SELECTOR_376_SHA='6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8'
EXPECTED_SELECTOR_377_SHA='7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1'
EXPECTED_SELECTOR_378_SHA='86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8'
EXPECTED_SELECTOR_379_SHA='ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7'
EXPECTED_SELECTOR_380_SHA='1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e'
EXPECTED_SOURCE_COMMIT='6808c090f2dd229a48550d758f459bfd156da4b6'
DIAGNOSTIC_IDENTITY='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'

root="${RUNNER_TEMP}/m3-cp4c3-tb14-retry"
envelope="${root}/envelope"
tree="${root}/tree"
out="${root}/result"
source_tree="${root}/source"
rm -rf "$root"
mkdir -p "$envelope" "$tree" "$out/ordinals" "$out/diagnostic" "$source_tree"

printf '%s\n' \
  'turn=M3-CP4c-3-TB14' \
  'execution=complete-user-authorized-retry' \
  'artifact_only=true' \
  "artifact_id=${ARTIFACT_ID}" \
  "expected_source=${EXPECTED_SOURCE_COMMIT}" \
  'benchmarkExecution=false' \
  'configureExecution=false' \
  'compileExecution=false' \
  'packageRepair=false' \
  'generatedDiscovery=false' \
  "started_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$out/run.env"

outer="${root}/package84-artifact.zip"
echo "downloading immutable package artifact ${ARTIFACT_ID}"
curl --fail-with-body --silent --show-error --location \
  -H "Authorization: Bearer ${GH_TOKEN}" \
  -H 'Accept: application/vnd.github+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" \
  -o "$outer"
actual_outer="$(sha256sum "$outer" | awk '{print $1}')"
echo "outer_artifact_sha256=${actual_outer}"
test "$actual_outer" = "$EXPECTED_OUTER_SHA"
unzip -q "$outer" -d "$envelope"
test -f "$envelope/package84.tar.gz"
actual_inner="$(sha256sum "$envelope/package84.tar.gz" | awk '{print $1}')"
echo "package84_tar_sha256=${actual_inner}"
test "$actual_inner" = "$EXPECTED_INNER_SHA"

tar -xzf "$envelope/package84.tar.gz" -C "$tree"
pkg="$tree/package84"
test -d "$pkg"

(
  cd "$pkg"
  sha256sum -c SHA256SUMS > "$out/internal-sha256-check.txt"
)
test "$(cat "$pkg/metadata/source-commit.txt")" = "$EXPECTED_SOURCE_COMMIT"
grep -Fx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt" >/dev/null
grep -E 'gmpxx|gmp' "$pkg/metadata/gmp-evidence.txt" >/dev/null
contract="$pkg/metadata/fixture-package-contract.txt"
grep -Fx 'package=84' "$contract" >/dev/null
grep -Fx 'fixture_count=27' "$contract" >/dev/null
grep -Fx 'selector=380' "$contract" >/dev/null
grep -Fx "selector_sha256=${EXPECTED_SELECTOR_380_SHA}" "$contract" >/dev/null
grep -Fx "frozen_selector_379_sha256=${EXPECTED_SELECTOR_379_SHA}" "$contract" >/dev/null
grep -Fx "non_gating_diagnostic_identity=${DIAGNOSTIC_IDENTITY}" "$contract" >/dev/null
grep -Fx 'runtimeExecution=false' "$contract" >/dev/null
grep -Fx 'packageRepair=false' "$contract" >/dev/null

binaries=(
  directional_benchmarks
  directional_compiled_api_tests
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_validation_tests
)
for binary in "${binaries[@]}"; do
  test -f "$pkg/bin/$binary"
  test -x "$pkg/bin/$binary"
  mode="$(stat -c '%a' "$pkg/bin/$binary")"
  echo "binary_mode ${binary}=${mode}"
  test "$mode" = 755
 done

census() {
  local dest="$1"
  (
    cd "$pkg"
    find . -type f -print0 | LC_ALL=C sort -z | while IFS= read -r -d '' f; do
      rel="${f#./}"
      printf '%s\t%s\t%s\t%s\n' "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f" | awk '{print $1}')"
    done
  ) > "$dest"
}
census "$out/preflight-census.tsv"
preflight_count="$(wc -l < "$out/preflight-census.tsv" | tr -d ' ')"
echo "preflight_file_count=${preflight_count}"
test "$preflight_count" -eq 58

source_tar="$pkg/source/source-${EXPECTED_SOURCE_COMMIT}.tar.gz"
test -f "$source_tar"
actual_source_tar="$(sha256sum "$source_tar" | awk '{print $1}')"
echo "source_tar_sha256=${actual_source_tar}"
test "$actual_source_tar" = "$EXPECTED_SOURCE_TAR_SHA"
tar -xzf "$source_tar" -C "$source_tree"

selector_dir="$source_tree/.agents/Directional"
declare -A selector_sha=(
  [373]="$EXPECTED_SELECTOR_373_SHA"
  [374]="$EXPECTED_SELECTOR_374_SHA"
  [375]="$EXPECTED_SELECTOR_375_SHA"
  [376]="$EXPECTED_SELECTOR_376_SHA"
  [377]="$EXPECTED_SELECTOR_377_SHA"
  [378]="$EXPECTED_SELECTOR_378_SHA"
  [379]="$EXPECTED_SELECTOR_379_SHA"
  [380]="$EXPECTED_SELECTOR_380_SHA"
)
for n in {373..380}; do
  f="$selector_dir/Architecture_M3_CP4c3_Required_Green_Selector_${n}.txt"
  test -f "$f"
  test "$(wc -l < "$f" | tr -d ' ')" -eq "$n"
  test "$(LC_ALL=C sort -u "$f" | wc -l | tr -d ' ')" -eq "$n"
  actual="$(sha256sum "$f" | awk '{print $1}')"
  echo "selector_${n}_sha256=${actual}"
  test "$actual" = "${selector_sha[$n]}"
  if [ "$n" -gt 373 ]; then
    prev=$((n - 1))
    prevf="$selector_dir/Architecture_M3_CP4c3_Required_Green_Selector_${prev}.txt"
    cmp -s "$prevf" <(head -n "$prev" "$f")
  fi
done
selector="$selector_dir/Architecture_M3_CP4c3_Required_Green_Selector_380.txt"
actual_prefix365="$(head -n 365 "$selector" | sha256sum | awk '{print $1}')"
echo "selector_380_prefix365_sha256=${actual_prefix365}"
test "$actual_prefix365" = "$EXPECTED_SELECTOR_365_PREFIX_SHA"

echo 'preflight=PASS' | tee "$out/preflight.env"

owner_for_ordinal() {
  local n="$1"
  if (( n >= 1 && n <= 17 )); then echo directional_surface_cell_producer_tests
  elif (( n >= 18 && n <= 28 )); then echo directional_surface_cell_authority_kernel_tests
  elif (( n >= 29 && n <= 40 )); then echo directional_surface_cell_completion_tests
  elif (( n >= 41 && n <= 46 )); then echo directional_surface_cell_producer_tests
  elif (( n >= 47 && n <= 104 )); then echo directional_surface_cell_completion_tests
  elif (( n >= 105 && n <= 112 )); then echo directional_surface_cell_validation_tests
  elif (( n == 113 )); then echo directional_surface_cell_completion_tests
  elif (( n >= 114 && n <= 154 )); then echo directional_surface_cell_producer_tests
  elif (( n >= 155 && n <= 173 )); then echo directional_surface_cell_authority_kernel_tests
  elif (( n >= 174 && n <= 207 )); then echo directional_surface_cell_producer_tests
  elif (( n == 208 )); then echo directional_surface_cell_completion_tests
  elif (( n >= 209 && n <= 257 )); then echo directional_surface_cell_producer_tests
  elif (( n >= 258 && n <= 260 )); then echo directional_surface_cell_completion_tests
  elif (( n >= 261 && n <= 293 )); then echo directional_surface_cell_validation_tests
  elif (( n >= 294 && n <= 380 )); then echo directional_surface_cell_producer_tests
  else return 1
  fi
}

printf 'ordinal\tdisposition\texit_code\tbinary\tidentity\n' > "$out/results.tsv"
pass_count=0
red_count=0
accepted_pass=0
accepted_red=0
first_red=0
ordinal=0
while IFS= read -r identity; do
  ordinal=$((ordinal + 1))
  test -n "$identity"
  owner="$(owner_for_ordinal "$ordinal")"
  test -x "$pkg/bin/$owner"
  log="$out/ordinals/$(printf '%03d' "$ordinal").log"
  echo "TB14 ordinal=${ordinal} owner=${owner} identity=${identity}"
  set +e
  (
    cd "$pkg"
    "$pkg/bin/$owner" --gtest_filter="$identity"
  ) >"$log" 2>&1
  code=$?
  set -e

  if ! grep -Fqx "Note: Google Test filter = ${identity}" "$log" \
      || ! grep -Eq '^\[==========\] Running 1 test from 1 test (suite|case)\.$' "$log" \
      || ! grep -Fqx "[ RUN      ] ${identity}" "$log"; then
    printf '%s\t%s\t%s\t%s\t%s\n' "$ordinal" 'ORCHESTRATION_INVALID_SELECTION' "$code" "$owner" "$identity" >> "$out/results.tsv"
    echo "orchestration failure: exact identity did not select exactly one test at ordinal ${ordinal}" >&2
    cat "$log" >&2
    exit 90
  fi

  if [ "$code" -eq 0 ] && grep -Fqx "[       OK ] ${identity}" "$log"; then
    disposition=PASS
    pass_count=$((pass_count + 1))
    if (( ordinal <= 365 )); then accepted_pass=$((accepted_pass + 1)); fi
  else
    disposition=RED
    red_count=$((red_count + 1))
    if (( first_red == 0 )); then first_red=$ordinal; fi
    if (( ordinal <= 365 )); then accepted_red=$((accepted_red + 1)); fi
  fi
  printf '%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$disposition" "$code" "$owner" "$identity" >> "$out/results.tsv"
done < "$selector"
test "$ordinal" -eq 380

# Required retained non-gating diagnostic, exactly once in a fresh process.
diag_owner=directional_surface_cell_producer_tests
diag_log="$out/diagnostic/MechanicalWitnessStageReachabilityIsObservable.log"
set +e
(
  cd "$pkg"
  "$pkg/bin/$diag_owner" --gtest_filter="$DIAGNOSTIC_IDENTITY"
) >"$diag_log" 2>&1
diag_code=$?
set -e
if ! grep -Fqx "Note: Google Test filter = ${DIAGNOSTIC_IDENTITY}" "$diag_log" \
    || ! grep -Eq '^\[==========\] Running 1 test from 1 test (suite|case)\.$' "$diag_log" \
    || ! grep -Fqx "[ RUN      ] ${DIAGNOSTIC_IDENTITY}" "$diag_log"; then
  echo 'diagnostic selection was not exactly one test' >&2
  cat "$diag_log" >&2
  exit 92
fi
if [ "$diag_code" -eq 0 ] && grep -Fqx "[       OK ] ${DIAGNOSTIC_IDENTITY}" "$diag_log"; then
  diag_disposition=PASS
else
  diag_disposition=RED
fi
printf 'identity\tdisposition\texit_code\tbinary\n%s\t%s\t%s\t%s\n' \
  "$DIAGNOSTIC_IDENTITY" "$diag_disposition" "$diag_code" "$diag_owner" > "$out/diagnostic.tsv"

census "$out/postflight-census.tsv"
if ! cmp -s "$out/preflight-census.tsv" "$out/postflight-census.tsv"; then
  echo 'immutable package byte/mode census changed during TB14' >&2
  diff -u "$out/preflight-census.tsv" "$out/postflight-census.tsv" > "$out/postflight-census.diff" || true
  exit 93
fi

echo 'package_postflight=IDENTICAL' > "$out/postflight.env"
printf '%s\n' \
  "selector_attempted=${ordinal}" \
  "selector_pass=${pass_count}" \
  "selector_red=${red_count}" \
  "accepted_prefix_pass=${accepted_pass}" \
  "accepted_prefix_red=${accepted_red}" \
  "first_red_ordinal=${first_red}" \
  "diagnostic_disposition=${diag_disposition}" \
  "diagnostic_exit_code=${diag_code}" \
  'package_postflight=IDENTICAL' \
  'benchmarkExecution=false' \
  'configureExecution=false' \
  'compileExecution=false' \
  'packageRepair=false' \
  'generatedDiscovery=false' \
  "finished_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$out/summary.env"
cat "$out/summary.env"
