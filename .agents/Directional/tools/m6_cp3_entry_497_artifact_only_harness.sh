#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"

: "${CANDIDATE_ARTIFACT_ID:?}"
: "${EXPECTED_SOURCE_SHA:?}"
: "${EXPECTED_CANDIDATE_ZIP_SHA256:?}"
: "${EXPECTED_ROOT_MANIFEST_SHA256:?}"
: "${EXPECTED_SOURCE_ARCHIVE_SHA256:?}"
FOCUSED30_RELATIVE_PATH='.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_30.txt'
FOCUSED12_RELATIVE_PATH='.agents/Directional/Architecture_M6_CP2_Required_Green_Focused_12.txt'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt'
ROUTING_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv'
EXPECTED_FOCUSED30_COUNT=30
EXPECTED_FOCUSED12_COUNT=12
EXPECTED_SELECTOR_COUNT=449
EXPECTED_TOTAL_PROCESS_COUNT=497
EXPECTED_FOCUSED30_SHA256='1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6'
EXPECTED_FOCUSED12_SHA256='2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed'
EXPECTED_SELECTOR_SHA256='d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414'
EXPECTED_ROUTING_SHA256='9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707'
EXPECTED_BENCHMARK_COUNT=0
EXPECTED_CP3ENTRY_COUNT=6
CP3ENTRY_IDENTITIES=(
  'M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority'
  'M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge'
  'M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition'
  'M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds'
  'M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition'
  'M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels'
)

MODE="${1:-}"
case "$MODE" in
  --preflight-only|--execute) ;;
  *) echo "usage: $0 --preflight-only|--execute" >&2; exit 64 ;;
esac

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
CANDIDATE_ZIP="${ROOT}/candidate-${CANDIDATE_ARTIFACT_ID}.zip"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RUNTIME" \
  "$RESULT/raw/focused30" "$RESULT/raw/focused12" "$RESULT/raw/selector" "$RESULT/raw/cp3entry" \
  "$RESULT/resources/focused30" "$RESULT/resources/focused12" "$RESULT/resources/selector" "$RESULT/resources/cp3entry"
: > "$LOG"
exec > >(tee -a "$LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
orchestration_failure=false
selection_integrity=true
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
retry_after_runtime_start=false
focused30_executed=0
focused12_executed=0
selector_executed=0
cp3entry_executed=0
boundary_written=false

write_boundary() {
  cat > "${RESULT}/execution-boundary.txt" <<BOUNDARY
turn_id=${TURN_ID}
mode=${MODE}
runtime_started=${runtime_started}
runtime_completed=${runtime_completed}
preflight_completed=${preflight_completed}
orchestration_failure=${orchestration_failure}
selection_integrity=${selection_integrity}
focused30_executed=${focused30_executed}
focused12_executed=${focused12_executed}
selector_executed=${selector_executed}
cp3entry_executed=${cp3entry_executed}
total_executed=$((focused30_executed + focused12_executed + selector_executed + cp3entry_executed))
benchmark_execution=${benchmark_execution}
configure_execution=${configure_execution}
compile_execution=${compile_execution}
relink_execution=${relink_execution}
generated_discovery=${generated_discovery}
package_repair=${package_repair}
mode_repair=${mode_repair}
source_test_fixture_selector_mutation=${source_test_fixture_selector_mutation}
retry_after_runtime_start=${retry_after_runtime_start}
BOUNDARY
  boundary_written=true
}

finish() {
  status=$?
  set +e
  if [[ "${boundary_written:-false}" != true ]]; then
    write_boundary
    echo "script_exit=${status}" >> "${RESULT}/execution-boundary.txt"
  fi
  echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" >> "$LOG"
}
trap finish EXIT

fail_orchestration() {
  orchestration_failure=true
  echo "ORCHESTRATION_FAILURE: $*" >&2
  exit 90
}

sha_file() { sha256sum "$1" | awk '{print $1}'; }

census_tree() {
  local root="$1" out="$2"
  python3 - "$root" "$out" <<'PY'
import hashlib, os, pathlib, stat, sys
root = pathlib.Path(sys.argv[1]).resolve()
out = pathlib.Path(sys.argv[2])
rows = []
for path in [root, *sorted(root.rglob('*'), key=lambda p: p.relative_to(root).as_posix())]:
    rel = '.' if path == root else path.relative_to(root).as_posix()
    st = path.lstat()
    mode = format(stat.S_IMODE(st.st_mode), 'o')
    if stat.S_ISREG(st.st_mode):
        h = hashlib.sha256()
        with path.open('rb') as f:
            for chunk in iter(lambda: f.read(1024 * 1024), b''):
                h.update(chunk)
        kind, digest, target = 'file', h.hexdigest(), '-'
    elif stat.S_ISDIR(st.st_mode):
        kind, digest, target = 'directory', '-', '-'
    elif stat.S_ISLNK(st.st_mode):
        kind, digest, target = 'symlink', '-', os.readlink(path)
    else:
        kind, digest, target = 'other', '-', '-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{st.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows))
PY
}

download_artifact() {
  local artifact_id="$1" expected_zip_sha="$2" zip_path="$3" authority_path="$4"
  local artifact_json provider_digest downloaded_sha
  artifact_json="$(curl --fail --silent --show-error \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${artifact_id}")"
  provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
  [[ "$provider_digest" == "sha256:${expected_zip_sha}" ]] || fail_orchestration "provider digest mismatch for artifact ${artifact_id}: ${provider_digest}"
  curl -L --fail --silent --show-error \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${artifact_id}/zip" \
    -o "$zip_path"
  downloaded_sha="$(sha_file "$zip_path")"
  [[ "$downloaded_sha" == "$expected_zip_sha" ]] || fail_orchestration "downloaded ZIP digest mismatch for artifact ${artifact_id}: ${downloaded_sha}"
  printf 'artifact_id=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' \
    "$artifact_id" "$provider_digest" "$downloaded_sha" > "$authority_path"
}

{
  echo "turn_id=${TURN_ID}"
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=${GITHUB_RUN_ID}"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=${GITHUB_REPOSITORY}"
  echo "runner_os=${RUNNER_OS:-unknown}"
  echo "candidate_artifact_id=${CANDIDATE_ARTIFACT_ID}"
  echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  python3 --version
} | tee "${RESULT}/environment.txt"

download_artifact "$CANDIDATE_ARTIFACT_ID" "$EXPECTED_CANDIDATE_ZIP_SHA256" "$CANDIDATE_ZIP" "${RESULT}/candidate-artifact-authority.txt"
unzip -q "$CANDIDATE_ZIP" -d "$PKG"

[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'candidate root manifest missing'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_ROOT_MANIFEST_SHA256" ]] || fail_orchestration 'candidate root manifest hash mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "${RESULT}/candidate-manifest-check-before.txt"
[[ "$(grep -c ': OK$' "${RESULT}/candidate-manifest-check-before.txt")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28'

[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'candidate source commit mismatch'
grep -qx 'runtimeExecution=false' "$PKG/metadata/command-boundary.txt" || fail_orchestration 'candidate Code+Build runtime boundary missing'
grep -qx 'exactArithmeticBackend=GMP' "$PKG/metadata/command-boundary.txt" || fail_orchestration 'candidate GMP backend evidence missing'
source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'candidate source archive missing'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive hash mismatch'
tar -xzf "$source_archive" -C "$SOURCE"

focused30="$SOURCE/$FOCUSED30_RELATIVE_PATH"
focused12="$SOURCE/$FOCUSED12_RELATIVE_PATH"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
routing="$SOURCE/$ROUTING_RELATIVE_PATH"
[[ -f "$focused30" && -f "$focused12" && -f "$selector" && -f "$routing" ]] || fail_orchestration 'frozen gate authority missing from packaged source'
[[ "$(sha_file "$focused30")" == "$EXPECTED_FOCUSED30_SHA256" ]] || fail_orchestration 'focused30 hash mismatch'
[[ "$(sha_file "$focused12")" == "$EXPECTED_FOCUSED12_SHA256" ]] || fail_orchestration 'focused12 hash mismatch'
[[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector449 hash mismatch'
[[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'routing449 hash mismatch'
[[ "$(wc -l < "$focused30" | tr -d ' ')" -eq "$EXPECTED_FOCUSED30_COUNT" ]] || fail_orchestration 'focused30 count mismatch'
[[ "$(wc -l < "$focused12" | tr -d ' ')" -eq "$EXPECTED_FOCUSED12_COUNT" ]] || fail_orchestration 'focused12 count mismatch'
[[ "$(wc -l < "$selector" | tr -d ' ')" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration 'selector449 count mismatch'
[[ "$(wc -l < "$routing" | tr -d ' ')" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration 'routing449 count mismatch'

cut -f2 "$routing" > "${ROOT}/routing-identities.txt"
cmp -s "$selector" "${ROOT}/routing-identities.txt" || fail_orchestration 'selector449/routing449 identity order mismatch'
awk -F'\t' '$3=="directional_surface_cell_authority_kernel_tests"{a++}
             $3=="directional_surface_cell_producer_tests"{p++}
             $3=="directional_surface_cell_completion_tests"{c++}
             $3=="directional_surface_cell_validation_tests"{v++}
             END{if(a!=32||p!=301||c!=75||v!=41)exit 1}' "$routing" \
  || fail_orchestration 'routing449 owner census mismatch'

focus30_routing="${ROOT}/focused30-routing.tsv"
focus12_routing="${ROOT}/focused12-routing.tsv"
awk '{print NR "\t" $0 "\tdirectional_surface_cell_producer_tests"}' "$focused30" > "$focus30_routing"
awk '{print NR "\t" $0 "\tdirectional_surface_cell_producer_tests"}' "$focused12" > "$focus12_routing"

required_executables=(
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_validation_tests
  directional_compiled_api_tests
  directional_benchmarks
)
for exe in "${required_executables[@]}"; do
  [[ -x "$PKG/bin/$exe" ]] || fail_orchestration "packaged executable missing mode: $exe"
done

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary mode mismatch: $exe"
done
known_fixture="$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj"
[[ -f "$known_fixture" ]] || fail_orchestration 'execution-view fixture tree is incomplete'
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
preflight_completed=true

postflight() {
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'immutable candidate package byte/mode census changed'
  if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then
    source_test_fixture_selector_mutation=true
    fail_orchestration 'immutable packaged source byte/mode census changed'
  fi
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view byte/mode census changed'
  [[ "$(sha_file "$focused30")" == "$EXPECTED_FOCUSED30_SHA256" ]] || fail_orchestration 'focused30 changed during execution'
  [[ "$(sha_file "$focused12")" == "$EXPECTED_FOCUSED12_SHA256" ]] || fail_orchestration 'focused12 changed during execution'
  [[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector449 changed during execution'
  [[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'routing449 changed during execution'
  post_manifest="${RESULT}/candidate-manifest-check-after.txt"
  (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$post_manifest"
  [[ "$(grep -c ': OK$' "$post_manifest")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28 after execution'
  printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\nfocused30_unchanged=true\nfocused12_unchanged=true\nselector_unchanged=true\nrouting_unchanged=true\nmanifest_after=28/28\n' > "${RESULT}/immutability.txt"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  write_boundary
  echo 'script_exit=0' >> "${RESULT}/execution-boundary.txt"
  echo "${TURN_ID}_PREFLIGHT_COMPLETE: immutable package/source/gate authorities and execution view verified; no Directional runtime executed."
  exit 0
fi

run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4" ledger="$5"
  local raw resource work code selected skipped passed result
  raw="${RESULT}/raw/${phase}/ordinal-$(printf '%03d' "$ordinal").log"
  resource="${RESULT}/resources/${phase}/ordinal-$(printf '%03d' "$ordinal").time.txt"
  work="${RUNTIME}/${phase}/ordinal-$(printf '%03d' "$ordinal")"
  mkdir -p "$work"
  echo "${TURN_ID} phase=${phase} ordinal=${ordinal} identity=${identity} owner=${binary}"
  set +e
  (
    cd "$work"
    /usr/bin/time -v -o "$resource" \
      env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
      "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
  ) >"$raw" 2>&1
  code=$?
  set -e
  cat "$raw"
  selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
  skipped="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"
  passed="$(grep -Ec '^\[       OK \] ' "$raw" || true)"
  [[ "$selected" -eq 1 ]] || { selection_integrity=false; fail_orchestration "exact-one selection failed for ${identity}: selected=${selected}"; }
  [[ "$skipped" -eq 0 ]] || { selection_integrity=false; fail_orchestration "skip observed for ${identity}: skipped=${skipped}"; }
  result=RED
  if [[ "$code" -eq 0 && "$passed" -eq 1 ]]; then result=PASS; fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$code" "$selected" "$skipped" "$passed" "$result" "$(sha_file "$raw")" >> "$ledger"
}

runtime_started=true

focused30_ledger="${RESULT}/focused30-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$focused30_ledger"
while IFS=$'\t' read -r ordinal identity binary; do
  run_identity focused30 "$ordinal" "$identity" "$binary" "$focused30_ledger"
  focused30_executed=$((focused30_executed + 1))
done < "$focus30_routing"
[[ "$focused30_executed" -eq "$EXPECTED_FOCUSED30_COUNT" ]] || fail_orchestration "focused30 execution count mismatch: $focused30_executed"
sha256sum "$focused30_ledger" > "${RESULT}/focused30-ledger.sha256"

focused12_ledger="${RESULT}/focused12-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$focused12_ledger"
while IFS=$'\t' read -r ordinal identity binary; do
  run_identity focused12 "$ordinal" "$identity" "$binary" "$focused12_ledger"
  focused12_executed=$((focused12_executed + 1))
done < "$focus12_routing"
[[ "$focused12_executed" -eq "$EXPECTED_FOCUSED12_COUNT" ]] || fail_orchestration "focused12 execution count mismatch: $focused12_executed"
sha256sum "$focused12_ledger" > "${RESULT}/focused12-ledger.sha256"

selector_ledger="${RESULT}/selector-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$selector_ledger"
while IFS=$'\t' read -r ordinal identity binary; do
  run_identity selector "$ordinal" "$identity" "$binary" "$selector_ledger"
  selector_executed=$((selector_executed + 1))
done < "$routing"
[[ "$selector_executed" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration "selector449 execution count mismatch: $selector_executed"
sha256sum "$selector_ledger" > "${RESULT}/selector-ledger.sha256"

cp3entry_ledger="${RESULT}/cp3entry-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$cp3entry_ledger"
cp3entry_ordinal=0
for identity in "${CP3ENTRY_IDENTITIES[@]}"; do
  cp3entry_ordinal=$((cp3entry_ordinal + 1))
  run_identity cp3entry "$cp3entry_ordinal" "$identity" directional_surface_cell_producer_tests "$cp3entry_ledger"
  cp3entry_executed=$((cp3entry_executed + 1))
done
[[ "$cp3entry_executed" -eq "$EXPECTED_CP3ENTRY_COUNT" ]] || fail_orchestration "cp3entry execution count mismatch: $cp3entry_executed"
sha256sum "$cp3entry_ledger" > "${RESULT}/cp3entry-ledger.sha256"
runtime_completed=true

python3 - "$focused30_ledger" "$focused12_ledger" "$selector_ledger" "$cp3entry_ledger" "${RESULT}/semantic-summary.txt" <<'PY'
import csv, pathlib, sys
focus30=list(csv.DictReader(open(sys.argv[1]),delimiter='\t'))
focus12=list(csv.DictReader(open(sys.argv[2]),delimiter='\t'))
selector=list(csv.DictReader(open(sys.argv[3]),delimiter='\t'))
cp3entry=list(csv.DictReader(open(sys.argv[4]),delimiter='\t'))
out=pathlib.Path(sys.argv[5])
if len(focus30)!=30 or [int(r['ordinal']) for r in focus30]!=list(range(1,31)):
    raise SystemExit('focused30 ledger coverage mismatch')
if len(focus12)!=12 or [int(r['ordinal']) for r in focus12]!=list(range(1,13)):
    raise SystemExit('focused12 ledger coverage mismatch')
if len(selector)!=449 or [int(r['ordinal']) for r in selector]!=list(range(1,450)):
    raise SystemExit('selector449 ledger coverage mismatch')
if len(cp3entry)!=6 or [int(r['ordinal']) for r in cp3entry]!=list(range(1,7)):
    raise SystemExit('cp3entry ledger coverage mismatch')
def stats(rows):
    red=[int(r['ordinal']) for r in rows if r['result']!='PASS']
    return len(rows)-len(red), red
p30,r30=stats(focus30); p12,r12=stats(focus12); ps,rs=stats(selector); pc3,rc3=stats(cp3entry)
out.write_text(
    f'focused30_total=30\nfocused30_pass={p30}\nfocused30_red={len(r30)}\nfocused30_red_ordinals={r30}\n'
    f'focused12_total=12\nfocused12_pass={p12}\nfocused12_red={len(r12)}\nfocused12_red_ordinals={r12}\n'
    f'selector449_total=449\nselector449_pass={ps}\nselector449_red={len(rs)}\nselector449_red_ordinals={rs}\n'
    f'cp3entry_total=6\ncp3entry_pass={pc3}\ncp3entry_red={len(rc3)}\ncp3entry_red_ordinals={rc3}\n'
    f'total_processes=497\ntotal_pass={p30+p12+ps+pc3}\ntotal_red={len(r30)+len(r12)+len(rs)+len(rc3)}\n'
    'benchmark_execution=0\n'
)
PY

{
  echo -e 'phase\tordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256'
  awk 'NR>1{print "focused30\t"$0}' "$focused30_ledger"
  awk 'NR>1{print "focused12\t"$0}' "$focused12_ledger"
  awk 'NR>1{print "selector\t"$0}' "$selector_ledger"
  awk 'NR>1{print "cp3entry\t"$0}' "$cp3entry_ledger"
} > "${RESULT}/combined-ledger.tsv"
sha256sum "${RESULT}/combined-ledger.tsv" > "${RESULT}/combined-ledger.sha256"

{
  echo -e 'phase\tordinal\tidentity\tbinary\texit\traw_sha256'
  awk -F'\t' 'NR>1 && $8!="PASS"{print "focused30\t"$1"\t"$2"\t"$3"\t"$4"\t"$9}' "$focused30_ledger"
  awk -F'\t' 'NR>1 && $8!="PASS"{print "focused12\t"$1"\t"$2"\t"$3"\t"$4"\t"$9}' "$focused12_ledger"
  awk -F'\t' 'NR>1 && $8!="PASS"{print "selector\t"$1"\t"$2"\t"$3"\t"$4"\t"$9}' "$selector_ledger"
  awk -F'\t' 'NR>1 && $8!="PASS"{print "cp3entry\t"$1"\t"$2"\t"$3"\t"$4"\t"$9}' "$cp3entry_ledger"
} > "${RESULT}/red-ledger.tsv"
sha256sum "${RESULT}/red-ledger.tsv" > "${RESULT}/red-ledger.sha256"

postflight
[[ "$benchmark_execution" == false && "$EXPECTED_BENCHMARK_COUNT" -eq 0 ]] || fail_orchestration 'benchmark boundary violated'
[[ $((focused30_executed + focused12_executed + selector_executed + cp3entry_executed)) -eq "$EXPECTED_TOTAL_PROCESS_COUNT" ]] || fail_orchestration 'total execution count mismatch'
write_boundary
echo 'script_exit=0' >> "${RESULT}/execution-boundary.txt"

manifest_tmp="${RUNNER_TEMP}/${SAFE_TURN_ID}-SHA256SUMS.tmp"
(
  cd "$RESULT"
  find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum
) > "$manifest_tmp"
manifest_rows="$(wc -l < "$manifest_tmp" | tr -d ' ')"
actual_nonmanifest="$(find "$RESULT" -type f ! -name SHA256SUMS | wc -l | tr -d ' ')"
[[ "$manifest_rows" -eq "$actual_nonmanifest" ]] || fail_orchestration "result manifest completeness mismatch rows=${manifest_rows} files=${actual_nonmanifest}"
mv "$manifest_tmp" "$RESULT/SHA256SUMS"
(cd "$RESULT" && sha256sum -c SHA256SUMS >/dev/null)

echo "${TURN_ID}_COMPLETE: 497 fresh exact-filter artifact-only processes complete; semantic interpretation deferred to Review."
