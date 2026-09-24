#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"

CANDIDATE_ARTIFACT_ID=10826090221
EXPECTED_SOURCE_SHA='ee8b8ac20571df5773f5f94bf9b382161f37a893'
EXPECTED_CANDIDATE_ZIP_SHA256='6e3c3b09d272e200f3c213aa5198ed805bff2f293f35b37a55b948176c870a9c'
EXPECTED_ROOT_MANIFEST_SHA256='a7761a80b45ab5dd53fc43ed8e6f66cbdd0d5b51edde0cb7ebc4ffcbe0a68136'
EXPECTED_SOURCE_ARCHIVE_SHA256='0cdf160f9526096a250840513a447954130578a6f8270e708222e938fb31b6d6'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt'
ROUTING_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv'
EXPECTED_SELECTOR_COUNT=449
EXPECTED_SELECTOR_SHA256='d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414'
EXPECTED_ROUTING_SHA256='9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707'
EXPECTED_FOCUSED_COUNT=6
EXPECTED_TOTAL_PROCESS_COUNT=455
EXPECTED_BENCHMARK_COUNT=0

MODE="${1:-}"
case "$MODE" in
  --execute) ;;
  *) echo "usage: $0 --execute" >&2; exit 64 ;;
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
  "$RESULT/raw/focused" "$RESULT/raw/selector" \
  "$RESULT/resources/focused" "$RESULT/resources/selector"
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
focused_executed=0
selector_executed=0
finalized=false

write_boundary() {
  local status="$1"
  cat > "${RESULT}/execution-boundary.txt" <<BOUNDARY
script_exit=${status}
turn_id=${TURN_ID}
mode=${MODE}
runtime_started=${runtime_started}
runtime_completed=${runtime_completed}
preflight_completed=${preflight_completed}
orchestration_failure=${orchestration_failure}
selection_integrity=${selection_integrity}
focused_executed=${focused_executed}
selector_executed=${selector_executed}
benchmark_execution=${benchmark_execution}
configure_execution=${configure_execution}
compile_execution=${compile_execution}
relink_execution=${relink_execution}
generated_discovery=${generated_discovery}
package_repair=${package_repair}
mode_repair=${mode_repair}
source_test_fixture_selector_mutation=${source_test_fixture_selector_mutation}
BOUNDARY
}

finish() {
  status=$?
  set +e
  if [[ "$finalized" != true ]]; then
    write_boundary "$status"
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
out.write_text(''.join(rows), encoding='utf-8')
PY
}

download_artifact() {
  local artifact_json provider_digest downloaded_sha
  artifact_json="$(curl --fail --silent --show-error \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${CANDIDATE_ARTIFACT_ID}")"
  provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
  [[ "$provider_digest" == "sha256:${EXPECTED_CANDIDATE_ZIP_SHA256}" ]] || \
    fail_orchestration "provider digest mismatch: ${provider_digest}"
  curl -L --fail --silent --show-error \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${CANDIDATE_ARTIFACT_ID}/zip" \
    -o "$CANDIDATE_ZIP"
  downloaded_sha="$(sha_file "$CANDIDATE_ZIP")"
  [[ "$downloaded_sha" == "$EXPECTED_CANDIDATE_ZIP_SHA256" ]] || \
    fail_orchestration "downloaded ZIP digest mismatch: ${downloaded_sha}"
  printf 'artifact_id=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' \
    "$CANDIDATE_ARTIFACT_ID" "$provider_digest" "$downloaded_sha" \
    > "${RESULT}/candidate-artifact-authority.txt"
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
  echo "selector_relative_path=${SELECTOR_RELATIVE_PATH}"
  echo "routing_relative_path=${ROUTING_RELATIVE_PATH}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  python3 --version
  unzip -v | sed -n '1p'
} | tee "${RESULT}/environment.txt"

download_artifact

# Extraction must preserve archived executable mode bits. No chmod or permission repair is permitted.
unzip -q "$CANDIDATE_ZIP" -d "$PKG"

[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'candidate root SHA256SUMS absent'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_ROOT_MANIFEST_SHA256" ]] || \
  fail_orchestration 'candidate root manifest digest mismatch'
manifest_log="${RESULT}/candidate-manifest-check-before.txt"
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$manifest_log"
[[ "$(grep -c ': OK$' "$manifest_log")" -eq 28 ]] || \
  fail_orchestration 'candidate root manifest did not verify 28/28'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || \
  fail_orchestration 'candidate source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'candidate build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'candidate compile preflight exit nonzero'
for receipt in "$PKG"/metadata/source-status-*.txt; do
  [[ ! -s "$receipt" ]] || fail_orchestration "candidate source-status receipt is not clean: $(basename "$receipt")"
done
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing candidate command-boundary token: $token"
done
for token in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || \
    fail_orchestration "missing candidate GMP evidence: $token"
done

required_executables=(
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_validation_tests
)
printf 'kind\tname\tsha256\tmode\tsize\n' > "${RESULT}/preflight-hashes.tsv"
for exe in "${required_executables[@]}"; do
  path="$PKG/bin/$exe"
  [[ -f "$path" && -x "$path" ]] || fail_orchestration "required owner executable absent or non-executable: $exe"
  printf 'executable\t%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" \
    >> "${RESULT}/preflight-hashes.tsv"
done

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'candidate packaged source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || \
  fail_orchestration 'candidate packaged source archive digest mismatch'
printf 'source_archive\t%s\t%s\t%s\t%s\n' "$(basename "$source_archive")" "$(sha_file "$source_archive")" \
  "$(stat -c '%a' "$source_archive")" "$(stat -c '%s' "$source_archive")" >> "${RESULT}/preflight-hashes.tsv"

tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
routing="$SOURCE/$ROUTING_RELATIVE_PATH"
[[ -f "$selector" ]] || fail_orchestration "selector absent: $SELECTOR_RELATIVE_PATH"
[[ -f "$routing" ]] || fail_orchestration "routing receipt absent: $ROUTING_RELATIVE_PATH"
[[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector449 digest mismatch'
[[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'selector449 routing digest mismatch'
printf 'selector\t%s\t%s\t%s\t%s\n' "$SELECTOR_RELATIVE_PATH" "$(sha_file "$selector")" \
  "$(stat -c '%a' "$selector")" "$(stat -c '%s' "$selector")" >> "${RESULT}/preflight-hashes.tsv"
printf 'routing\t%s\t%s\t%s\t%s\n' "$ROUTING_RELATIVE_PATH" "$(sha_file "$routing")" \
  "$(stat -c '%a' "$routing")" "$(stat -c '%s' "$routing")" >> "${RESULT}/preflight-hashes.tsv"
sha256sum "${RESULT}/preflight-hashes.tsv" > "${RESULT}/preflight-hashes.sha256"

python3 - "$selector" "$routing" "$PKG" "${RESULT}/selector-routing.tsv" "${RESULT}/selector-authority.txt" <<'PY'
import collections, hashlib, pathlib, sys
selector = pathlib.Path(sys.argv[1])
routing = pathlib.Path(sys.argv[2])
pkg = pathlib.Path(sys.argv[3])
out = pathlib.Path(sys.argv[4])
auth = pathlib.Path(sys.argv[5])
sel_data = selector.read_bytes()
route_data = routing.read_bytes()
for label, data in [('selector', sel_data), ('routing', route_data)]:
    if b'\r' in data:
        raise SystemExit(f'{label} contains CR bytes')
sel_lines = sel_data.decode().splitlines()
route_lines = route_data.decode().splitlines()
if len(sel_lines) != 449 or len(route_lines) != 449:
    raise SystemExit(f'row count mismatch selector={len(sel_lines)} routing={len(route_lines)}')
if len(set(sel_lines)) != 449:
    raise SystemExit('selector identities are not unique')
rows = []
counts = collections.Counter()
for index, line in enumerate(route_lines, 1):
    parts = line.split('\t')
    if len(parts) != 3:
        raise SystemExit(f'routing column count mismatch at row {index}')
    ordinal, identity, binary = parts
    if int(ordinal) != index:
        raise SystemExit(f'routing ordinal mismatch at row {index}: {ordinal}')
    if identity != sel_lines[index - 1]:
        raise SystemExit(f'routing identity mismatch at row {index}')
    rows.append((index, identity, binary))
    counts[binary] += 1
expected = {
    'directional_surface_cell_authority_kernel_tests': 32,
    'directional_surface_cell_producer_tests': 301,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
if counts != expected:
    raise SystemExit(f'owner census mismatch: {dict(counts)!r}')
for binary in expected:
    p = pkg / 'bin' / binary
    if not p.is_file() or not (p.stat().st_mode & 0o111):
        raise SystemExit(f'routed executable absent or non-executable: {binary}')
out.write_text('ordinal\tidentity\tbinary\n' + ''.join(f'{o}\t{i}\t{b}\n' for o,i,b in rows), encoding='utf-8')
auth.write_text(
    f'selector_rows={len(sel_lines)}\nselector_sha256={hashlib.sha256(sel_data).hexdigest()}\n'
    f'routing_rows={len(route_lines)}\nrouting_sha256={hashlib.sha256(route_data).hexdigest()}\n'
    + ''.join(f'{k}={expected[k]}\n' for k in expected), encoding='utf-8')
PY

focused="${RESULT}/focused-routing.tsv"
cat > "$focused" <<'FOCUSED'
ordinal	identity	binary
1	M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell	directional_surface_cell_producer_tests
2	M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct	directional_surface_cell_producer_tests
3	M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity	directional_surface_cell_producer_tests
4	M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints	directional_surface_cell_producer_tests
5	SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets	directional_surface_cell_producer_tests
6	M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection	directional_surface_cell_producer_tests
FOCUSED
[[ "$(( $(wc -l < "$focused") - 1 ))" -eq "$EXPECTED_FOCUSED_COUNT" ]] || fail_orchestration 'focused identity count mismatch'

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary mode mismatch: $exe"
done
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
preflight_completed=true

run_identity() {
  local phase="$1" global_ordinal="$2" phase_ordinal="$3" identity="$4" binary="$5"
  local phase_dir raw resource work code selected skipped passed crashed result
  phase_dir="${phase,,}"
  raw="${RESULT}/raw/${phase_dir}/ordinal-$(printf '%03d' "$phase_ordinal").log"
  resource="${RESULT}/resources/${phase_dir}/ordinal-$(printf '%03d' "$phase_ordinal").time.txt"
  work="${RUNTIME}/${phase_dir}/ordinal-$(printf '%03d' "$phase_ordinal")"
  mkdir -p "$work"
  echo "${TURN_ID} phase=${phase} global=${global_ordinal} ordinal=${phase_ordinal} identity=${identity} owner=${binary}"
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
  crashed=0
  if [[ "$code" -ge 128 ]]; then crashed=1; fi
  result=RED
  if [[ "$code" -eq 0 && "$passed" -eq 1 ]]; then result=PASS; fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$global_ordinal" "$phase" "$phase_ordinal" "$identity" "$binary" "$code" "$selected" "$skipped" "$passed" "$crashed" "$result" "$(sha_file "$raw")" \
    >> "${RESULT}/execution-ledger.tsv"
}

printf 'global_ordinal\tphase\tphase_ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tcrashed\tresult\traw_sha256\n' \
  > "${RESULT}/execution-ledger.tsv"
runtime_started=true

while IFS=$'\t' read -r ordinal identity binary; do
  [[ "$ordinal" == 'ordinal' ]] && continue
  run_identity focused "$ordinal" "$ordinal" "$identity" "$binary"
  focused_executed=$((focused_executed + 1))
done < "$focused"
[[ "$focused_executed" -eq "$EXPECTED_FOCUSED_COUNT" ]] || fail_orchestration "focused execution count mismatch: ${focused_executed}"

while IFS=$'\t' read -r ordinal identity binary; do
  [[ "$ordinal" == 'ordinal' ]] && continue
  global_ordinal=$((EXPECTED_FOCUSED_COUNT + ordinal))
  run_identity selector "$global_ordinal" "$ordinal" "$identity" "$binary"
  selector_executed=$((selector_executed + 1))
done < "${RESULT}/selector-routing.tsv"
[[ "$selector_executed" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration "selector execution count mismatch: ${selector_executed}"
runtime_completed=true

python3 - "${RESULT}/execution-ledger.tsv" "${RESULT}/semantic-summary.txt" "${RESULT}/red-ledger.tsv" <<'PY'
import csv, pathlib, sys
ledger = pathlib.Path(sys.argv[1])
summary = pathlib.Path(sys.argv[2])
red_out = pathlib.Path(sys.argv[3])
rows = list(csv.DictReader(ledger.open(), delimiter='\t'))
if len(rows) != 455 or [int(r['global_ordinal']) for r in rows] != list(range(1, 456)):
    raise SystemExit('execution ledger coverage mismatch')
focused = [r for r in rows if r['phase'] == 'focused']
selector = [r for r in rows if r['phase'] == 'selector']
if len(focused) != 6 or len(selector) != 449:
    raise SystemExit('phase coverage mismatch')
reds = [r for r in rows if r['result'] != 'PASS']
selector_reds = [r for r in selector if r['result'] != 'PASS']
focused_reds = [r for r in focused if r['result'] != 'PASS']
crashes = [r for r in rows if r['crashed'] == '1']
summary.write_text(
    f'focused_total=6\nfocused_pass={6-len(focused_reds)}\nfocused_red={len(focused_reds)}\n'
    f'selector_total=449\nselector_pass={449-len(selector_reds)}\nselector_red={len(selector_reds)}\n'
    f'total_processes=455\ntotal_pass={455-len(reds)}\ntotal_red={len(reds)}\ncrashes={len(crashes)}\n'
    'selection_mismatches=0\nskips=0\nbenchmark_execution=0\nbuild_execution=0\nconfigure_execution=0\nlink_execution=0\n',
    encoding='utf-8')
with red_out.open('w', encoding='utf-8', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=rows[0].keys(), delimiter='\t', lineterminator='\n')
    writer.writeheader()
    writer.writerows(reds)
PY
sha256sum "${RESULT}/execution-ledger.tsv" > "${RESULT}/execution-ledger.sha256"

postflight_hashes="${RESULT}/postflight-hashes.tsv"
printf 'kind\tname\tsha256\tmode\tsize\n' > "$postflight_hashes"
for exe in "${required_executables[@]}"; do
  path="$PKG/bin/$exe"
  printf 'executable\t%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" >> "$postflight_hashes"
done
printf 'source_archive\t%s\t%s\t%s\t%s\n' "$(basename "$source_archive")" "$(sha_file "$source_archive")" \
  "$(stat -c '%a' "$source_archive")" "$(stat -c '%s' "$source_archive")" >> "$postflight_hashes"
printf 'selector\t%s\t%s\t%s\t%s\n' "$SELECTOR_RELATIVE_PATH" "$(sha_file "$selector")" \
  "$(stat -c '%a' "$selector")" "$(stat -c '%s' "$selector")" >> "$postflight_hashes"
printf 'routing\t%s\t%s\t%s\t%s\n' "$ROUTING_RELATIVE_PATH" "$(sha_file "$routing")" \
  "$(stat -c '%a' "$routing")" "$(stat -c '%s' "$routing")" >> "$postflight_hashes"
cmp -s "${RESULT}/preflight-hashes.tsv" "$postflight_hashes" || fail_orchestration 'pre/post hash inventory changed'
sha256sum "$postflight_hashes" > "${RESULT}/postflight-hashes.sha256"

census_tree "$PKG" "${RESULT}/package-census-after.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'immutable candidate package byte/mode census changed'
if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then
  source_test_fixture_selector_mutation=true
  fail_orchestration 'immutable packaged source byte/mode census changed'
fi
cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view byte/mode census changed'
[[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector changed during execution'
[[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'routing receipt changed during execution'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive changed during execution'
post_manifest="${RESULT}/candidate-manifest-check-after.txt"
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$post_manifest"
[[ "$(grep -c ': OK$' "$post_manifest")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28 after execution'
printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\npre_post_hash_inventory_equal=true\nselector_unchanged=true\nrouting_unchanged=true\nsource_archive_unchanged=true\nmanifest_after=28/28\n' \
  > "${RESULT}/immutability.txt"

[[ "$benchmark_execution" == false && "$EXPECTED_BENCHMARK_COUNT" -eq 0 ]] || fail_orchestration 'benchmark boundary violated'
[[ "$configure_execution" == false && "$compile_execution" == false && "$relink_execution" == false ]] || fail_orchestration 'build/configure/link boundary violated'
[[ $((focused_executed + selector_executed)) -eq "$EXPECTED_TOTAL_PROCESS_COUNT" ]] || fail_orchestration 'total execution count mismatch'

write_boundary 0
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
finalized=true

echo "${TURN_ID}_COMPLETE: six focused plus selector449 artifact-only execution complete; semantic interpretation and promotion deferred to Review."
