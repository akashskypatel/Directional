#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"

ARTIFACT_ID=10771899191
EXPECTED_ARTIFACT_SHA256='d0f26b1615cbc69d3dd977f726296ad8e76728b682ad3428dc10c07ddb1d2cbe'
EXPECTED_SOURCE_SHA='cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1'
EXPECTED_ROOT_MANIFEST_SHA256='b3afa49083701f466d7a1d6b98aea83d6d5a58078f0336727d29c4184a7dc3f3'
EXPECTED_SOURCE_ARCHIVE_SHA256='dabed7ea7f37565aec320bc7cfd34a51a840f519c2115015994f459880e580b7'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP3_CB20_Required_Green_Selector_448.txt'
ROUTING_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP3_CB20_Selector_448_Static_Routing_Receipt.tsv'
EXPECTED_SELECTOR_SHA256='70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789'
EXPECTED_ROUTING_SHA256='c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c'
EXPECTED_SELECTOR_COUNT=448
EXPECTED_BENCHMARK_COUNT=0

MODE="${1:-}"
case "$MODE" in
  --preflight-only|--execute) ;;
  *) echo "usage: $0 --preflight-only|--execute" >&2; exit 64 ;;
esac

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
ZIP="${ROOT}/candidate-${ARTIFACT_ID}.zip"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RUNTIME" "$RESULT/raw/selector" "$RESULT/resources/selector"
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
selector_executed=0
boundary_written=false

sha_file() { sha256sum "$1" | awk '{print $1}'; }

write_boundary() {
  cat > "${RESULT}/execution-boundary.txt" <<BOUNDARY
turn_id=${TURN_ID}
mode=${MODE}
runtime_started=${runtime_started}
runtime_completed=${runtime_completed}
preflight_completed=${preflight_completed}
orchestration_failure=${orchestration_failure}
selection_integrity=${selection_integrity}
selector_executed=${selector_executed}
total_executed=${selector_executed}
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

census_tree() {
  python3 - "$1" "$2" <<'PY'
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

{
  echo "turn_id=$TURN_ID"
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=$GITHUB_RUN_ID"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=$GITHUB_REPOSITORY"
  echo "runner_os=${RUNNER_OS:-unknown}"
  echo "artifact_id=$ARTIFACT_ID"
  echo "expected_source_sha=$EXPECTED_SOURCE_SHA"
  echo "selector_relative_path=$SELECTOR_RELATIVE_PATH"
  echo "routing_relative_path=$ROUTING_RELATIVE_PATH"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  python3 --version
} | tee "${RESULT}/environment.txt"

artifact_json="$(curl --fail --silent --show-error   -H "Authorization: Bearer $GH_TOKEN"   -H 'Accept: application/vnd.github+json'   -H 'X-GitHub-Api-Version: 2022-11-28'   "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID")"
provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
[[ "$provider_digest" == "sha256:$EXPECTED_ARTIFACT_SHA256" ]] || fail_orchestration "provider digest mismatch: $provider_digest"
curl -L --fail --silent --show-error   -H "Authorization: Bearer $GH_TOKEN"   -H 'Accept: application/vnd.github+json'   -H 'X-GitHub-Api-Version: 2022-11-28'   "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID/zip"   -o "$ZIP"
[[ "$(sha_file "$ZIP")" == "$EXPECTED_ARTIFACT_SHA256" ]] || fail_orchestration 'downloaded artifact digest mismatch'
printf 'artifact_id=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n'   "$ARTIFACT_ID" "$provider_digest" "$(sha_file "$ZIP")" > "${RESULT}/artifact-authority.txt"

# Use system unzip/tar so archived executable mode bits are preserved; do not repair modes.
unzip -q "$ZIP" -d "$PKG"
[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'root SHA256SUMS absent'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_ROOT_MANIFEST_SHA256" ]] || fail_orchestration 'root manifest digest mismatch'
manifest_log="${RESULT}/manifest-check-before.txt"
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$manifest_log"
[[ "$(grep -c ': OK$' "$manifest_log")" -eq 28 ]] || fail_orchestration 'root manifest did not verify 28/28'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'compile preflight exit nonzero'
for receipt in "$PKG"/metadata/source-status-*.txt; do
  [[ ! -s "$receipt" ]] || fail_orchestration "source-status receipt is not clean: $(basename "$receipt")"
done
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing command-boundary token: $token"
done
for token in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || fail_orchestration "missing GMP evidence: $token"
done

required_executables=(
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_validation_tests
)
printf 'binary\tsha256\tmode\tsize\n' > "${RESULT}/owner-executables.tsv"
for exe in "${required_executables[@]}"; do
  path="$PKG/bin/$exe"
  [[ -f "$path" && -x "$path" ]] || fail_orchestration "required owner executable absent or non-executable: $exe"
  printf '%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" >> "${RESULT}/owner-executables.tsv"
done
sha256sum "${RESULT}/owner-executables.tsv" > "${RESULT}/owner-executables.sha256"

source_archive="$PKG/source/source-$EXPECTED_SOURCE_SHA.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'packaged source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
routing="$SOURCE/$ROUTING_RELATIVE_PATH"
[[ -f "$selector" ]] || fail_orchestration "selector absent: $SELECTOR_RELATIVE_PATH"
[[ -f "$routing" ]] || fail_orchestration "routing receipt absent: $ROUTING_RELATIVE_PATH"
[[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector digest mismatch'
[[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'routing receipt digest mismatch'

python3 - "$selector" "$routing" "${RESULT}/selector-authority.txt" "${RESULT}/routing-authority.txt" <<'PY'
import collections, hashlib, pathlib, sys
selector = pathlib.Path(sys.argv[1])
routing = pathlib.Path(sys.argv[2])
sout = pathlib.Path(sys.argv[3])
rout = pathlib.Path(sys.argv[4])
data = selector.read_bytes()
lines = data.splitlines(keepends=True)
if b'\r' in data or len(lines) != 448 or any(not x.endswith(b'\n') for x in lines):
    raise SystemExit('selector byte/row contract mismatch')
ids = [x.decode().rstrip('\n') for x in lines]
rows = [line.rstrip('\n').split('\t') for line in routing.read_text().splitlines(keepends=True)]
if len(rows) != 448 or any(len(r) != 3 for r in rows):
    raise SystemExit('routing row/column contract mismatch')
if [int(r[0]) for r in rows] != list(range(1,449)):
    raise SystemExit('routing ordinal mismatch')
if [r[1] for r in rows] != ids:
    raise SystemExit('routing identity sequence differs from selector bytes')
counts = collections.Counter(r[2] for r in rows)
expected = {
    'directional_surface_cell_authority_kernel_tests': 32,
    'directional_surface_cell_producer_tests': 300,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
if counts != expected:
    raise SystemExit(f'owner census mismatch: {dict(counts)}')
sout.write_text(
    'selector_rows=448\n'
    f'selector_sha256={hashlib.sha256(data).hexdigest()}\n'
    'selector_terminal_lf=true\nselector_crlf=false\n'
)
rout.write_text(
    'routing_rows=448\nrouting_sequence_equals_selector=true\n'
    + ''.join(f'{k}={expected[k]}\n' for k in expected)
)
PY

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view mode mismatch: $exe"
done
[[ -f "$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'execution-view fixture tree incomplete'
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
preflight_completed=true

postflight() {
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'immutable package census changed'
  if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then
    source_test_fixture_selector_mutation=true
    fail_orchestration 'immutable packaged source census changed'
  fi
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view census changed'
  [[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector changed during execution'
  [[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'routing receipt changed during execution'
  post_manifest="${RESULT}/manifest-check-after.txt"
  (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$post_manifest"
  [[ "$(grep -c ': OK$' "$post_manifest")" -eq 28 ]] || fail_orchestration 'root manifest did not verify 28/28 after execution'
  printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\nselector_unchanged=true\nrouting_unchanged=true\nmanifest_after=28/28\n' > "${RESULT}/immutability.txt"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  write_boundary
  echo 'script_exit=0' >> "${RESULT}/execution-boundary.txt"
  echo "${TURN_ID}_PREFLIGHT_COMPLETE: immutable artifact, selector448, routing receipt, and execution view verified; no Directional runtime executed."
  exit 0
fi

run_identity() {
  local ordinal="$1" identity="$2" binary="$3" ledger="$4"
  local raw resource work code selected skipped passed result
  raw="${RESULT}/raw/selector/ordinal-$(printf '%03d' "$ordinal").log"
  resource="${RESULT}/resources/selector/ordinal-$(printf '%03d' "$ordinal").time.txt"
  work="${RUNTIME}/selector/ordinal-$(printf '%03d' "$ordinal")"
  mkdir -p "$work"
  echo "${TURN_ID} ordinal=${ordinal} identity=${identity} owner=${binary}"
  set +e
  (
    cd "$work"
    /usr/bin/time -v -o "$resource"       env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no       "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
  ) >"$raw" 2>&1
  code=$?
  set -e
  cat "$raw"
  selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
  skipped="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"
  passed="$(grep -Ec '^\[       OK \] ' "$raw" || true)"
  [[ "$selected" -eq 1 ]] || { selection_integrity=false; fail_orchestration "exact-one selection failed for $identity: selected=$selected"; }
  [[ "$skipped" -eq 0 ]] || { selection_integrity=false; fail_orchestration "skip observed for $identity: skipped=$skipped"; }
  result=RED
  if [[ "$code" -eq 0 && "$passed" -eq 1 ]]; then result=PASS; fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n'     "$ordinal" "$identity" "$binary" "$code" "$selected" "$skipped" "$passed" "$result" "$(sha_file "$raw")" >> "$ledger"
}

runtime_started=true
ledger="${RESULT}/selector-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$ledger"
while IFS=$'\t' read -r ordinal identity binary; do
  run_identity "$ordinal" "$identity" "$binary" "$ledger"
  selector_executed=$((selector_executed + 1))
done < "$routing"
[[ "$selector_executed" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration "selector execution count mismatch: $selector_executed"
sha256sum "$ledger" > "${RESULT}/selector-ledger.sha256"
runtime_completed=true

python3 - "$ledger" "${RESULT}/semantic-summary.txt" "${RESULT}/appended-selector.tsv" "${RESULT}/protected-selector.tsv" <<'PY'
import collections, csv, pathlib, sys
rows = list(csv.DictReader(open(sys.argv[1]), delimiter='\t'))
if len(rows) != 448 or [int(r['ordinal']) for r in rows] != list(range(1,449)):
    raise SystemExit('selector ledger coverage mismatch')
red = [int(r['ordinal']) for r in rows if r['result'] != 'PASS']
skips = [int(r['ordinal']) for r in rows if int(r['skipped']) != 0]
badsel = [int(r['ordinal']) for r in rows if int(r['selected']) != 1]
owners = collections.Counter(r['binary'] for r in rows)
pathlib.Path(sys.argv[2]).write_text(
    f'selector_total=448\nselector_pass={448-len(red)}\nselector_red={len(red)}\n'
    f'selector_red_ordinals={red}\nselection_mismatch={len(badsel)}\nselection_mismatch_ordinals={badsel}\n'
    f'skip_count={len(skips)}\nskip_ordinals={skips}\nbenchmark_execution=0\n'
    + ''.join(f'owner_{k}={owners[k]}\n' for k in sorted(owners))
)
header='ordinal\tidentity\tbinary\tresult\texit\traw_sha256\n'
pathlib.Path(sys.argv[3]).write_text(
    header + ''.join(f"{r['ordinal']}\t{r['identity']}\t{r['binary']}\t{r['result']}\t{r['exit']}\t{r['raw_sha256']}\n"
                     for r in rows if int(r['ordinal']) >= 431)
)
protected={191,192,247,408,446,447,448}
pathlib.Path(sys.argv[4]).write_text(
    header + ''.join(f"{r['ordinal']}\t{r['identity']}\t{r['binary']}\t{r['result']}\t{r['exit']}\t{r['raw_sha256']}\n"
                     for r in rows if int(r['ordinal']) in protected)
)
PY

postflight
[[ "$benchmark_execution" == false && "$EXPECTED_BENCHMARK_COUNT" -eq 0 ]] || fail_orchestration 'benchmark boundary violated'
write_boundary
echo 'script_exit=0' >> "${RESULT}/execution-boundary.txt"

manifest_tmp="${RUNNER_TEMP}/${SAFE_TURN_ID}-SHA256SUMS.tmp"
(
  cd "$RESULT"
  find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum
) > "$manifest_tmp"
manifest_rows="$(wc -l < "$manifest_tmp" | tr -d ' ')"
actual_nonmanifest="$(find "$RESULT" -type f ! -name SHA256SUMS | wc -l | tr -d ' ')"
[[ "$manifest_rows" -eq "$actual_nonmanifest" ]] || fail_orchestration "result manifest completeness mismatch rows=$manifest_rows files=$actual_nonmanifest"
mv "$manifest_tmp" "$RESULT/SHA256SUMS"
(cd "$RESULT" && sha256sum -c SHA256SUMS >/dev/null)

echo "${TURN_ID}_COMPLETE: 448 fresh exact-filter artifact-only selector processes complete; semantic interpretation deferred to Review."
