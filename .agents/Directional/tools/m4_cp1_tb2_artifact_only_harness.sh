#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"
: "${ARTIFACT_ID:?}"
: "${EXPECTED_ARTIFACT_NAME:?}"
: "${EXPECTED_PROVIDER_DIGEST:?}"
: "${EXPECTED_ZIP_SHA256:?}"

EXPECTED_SOURCE_SHA='680f9f1573d3c7e56a273366436463e40e196131'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP1_Required_Green_Selector_373.txt'
EXPECTED_SELECTOR_COUNT=373
EXPECTED_SELECTOR_SHA256='6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b'
ACCEPTED_PREFIX_COUNT=365
FOCUSED_FIRST=366
FOCUSED_LAST=373

MODE="${1:-}"
case "$MODE" in
  --preflight-only|--execute) ;;
  *) echo "usage: $0 --preflight-only|--execute" >&2; exit 64 ;;
esac

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
ZIP="${ROOT}/artifact-${ARTIFACT_ID}.zip"
RUNTIME="${ROOT}/runtime"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RESULT/raw/full" \
  "$RESULT/raw/focused-a" "$RESULT/raw/focused-b" "$RESULT/resources/full" \
  "$RESULT/resources/focused-a" "$RESULT/resources/focused-b" "$RUNTIME"
: > "$LOG"
exec > >(tee -a "$LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
execution_view_verified=false
orchestration_failure=false
selection_integrity=true
timeout_count=0
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false

finish() {
  status=$?
  set +e
  {
    echo "script_exit=${status}"
    echo "turn_id=${TURN_ID}"
    echo "mode=${MODE}"
    echo "runtime_started=${runtime_started}"
    echo "runtime_completed=${runtime_completed}"
    echo "preflight_completed=${preflight_completed}"
    echo "execution_view_verified=${execution_view_verified}"
    echo "orchestration_failure=${orchestration_failure}"
    echo "selection_integrity=${selection_integrity}"
    echo "timeout_count=${timeout_count}"
    echo "benchmark_execution=${benchmark_execution}"
    echo "configure_execution=${configure_execution}"
    echo "compile_execution=${compile_execution}"
    echo "relink_execution=${relink_execution}"
    echo "generated_discovery=${generated_discovery}"
    echo "package_repair=${package_repair}"
    echo "mode_repair=${mode_repair}"
    echo "source_test_fixture_selector_mutation=${source_test_fixture_selector_mutation}"
  } | tee "${RESULT}/execution-boundary.txt"
  echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" | tee -a "$LOG"
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

{
  echo "turn_id=${TURN_ID}"
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=${GITHUB_RUN_ID}"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=${GITHUB_REPOSITORY}"
  echo "runner_os=${RUNNER_OS:-unknown}"
  echo "artifact_id=${ARTIFACT_ID}"
  echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"
  echo "selector_relative_path=${SELECTOR_RELATIVE_PATH}"
  echo "expected_selector_count=${EXPECTED_SELECTOR_COUNT}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  python3 --version
  timeout --version | head -n 1
} | tee "${RESULT}/environment.txt"

artifact_json="$(curl --fail --silent --show-error \
  -H "Authorization: Bearer ${GH_TOKEN}" \
  -H 'Accept: application/vnd.github+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}")"
provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
artifact_name="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("name", ""))')"
[[ "$provider_digest" == "$EXPECTED_PROVIDER_DIGEST" ]] || fail_orchestration "provider digest mismatch: $provider_digest"
[[ "$artifact_name" == "$EXPECTED_ARTIFACT_NAME" ]] || fail_orchestration "artifact name mismatch: $artifact_name"
curl -L --fail --silent --show-error \
  -H "Authorization: Bearer ${GH_TOKEN}" \
  -H 'Accept: application/vnd.github+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" \
  -o "$ZIP"
zip_sha="$(sha_file "$ZIP")"
[[ "$zip_sha" == "$EXPECTED_ZIP_SHA256" ]] || fail_orchestration "downloaded ZIP digest mismatch: $zip_sha"
printf 'artifact_id=%s\nartifact_name=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' \
  "$ARTIFACT_ID" "$artifact_name" "$provider_digest" "$zip_sha" | tee "${RESULT}/artifact-authority.txt"

unzip -q "$ZIP" -d "$PKG"
[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'root SHA256SUMS absent'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "${RESULT}/sha256sums-check.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'compile preflight exit nonzero'
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing command boundary: $token"
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
  printf '%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" \
    >> "${RESULT}/owner-executables.tsv"
done
sha256sum "${RESULT}/owner-executables.tsv" > "${RESULT}/owner-executables.sha256"

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
[[ -f "$selector" ]] || fail_orchestration "selector absent: $SELECTOR_RELATIVE_PATH"
[[ "$(grep -cve '^[[:space:]]*$' "$selector")" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration 'selector count mismatch'
[[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector digest mismatch'
printf 'selector_path=%s\nselector_rows=%s\nselector_sha256=%s\naccepted_prefix_count=%s\n' \
  "$SELECTOR_RELATIVE_PATH" "$EXPECTED_SELECTOR_COUNT" "$EXPECTED_SELECTOR_SHA256" "$ACCEPTED_PREFIX_COUNT" \
  | tee "${RESULT}/selector-authority.txt"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"

python3 - "$SOURCE" "$selector" "${RESULT}/identity-map.tsv" "${RESULT}/owner-distribution.tsv" <<'PY'
import pathlib, re, sys
root = pathlib.Path(sys.argv[1])
selector_path = pathlib.Path(sys.argv[2])
out = pathlib.Path(sys.argv[3])
dist_out = pathlib.Path(sys.argv[4])
selector = [line.strip() for line in selector_path.read_text().splitlines() if line.strip()]
cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
target_names = [
    'directional_surface_cell_authority_kernel_tests',
    'directional_surface_cell_producer_tests',
    'directional_surface_cell_completion_tests',
    'directional_surface_cell_validation_tests',
]
def cpp_lines(text):
    return [line.strip() for line in text.splitlines() if line.strip().endswith('.cpp')]
producer = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable', cmake, re.S)
if not producer:
    raise SystemExit('producer source set not found')
targets = {'directional_surface_cell_producer_tests': cpp_lines(producer.group(1))}
for target in [t for t in target_names if t != 'directional_surface_cell_producer_tests']:
    m = re.search(r'add_executable\(\s*' + re.escape(target) + r'(.*?)\)\s*\n', cmake, re.S)
    if not m:
        raise SystemExit(f'target source block not found: {target}')
    targets[target] = cpp_lines(m.group(1))
pattern = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners = {}
for target in target_names:
    for relative in targets[target]:
        path = root / relative
        if not path.is_file():
            raise SystemExit(f'owner source missing: {target}:{relative}')
        for suite, name in pattern.findall(path.read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}', []).append((target, relative))
rows = []
counts = {t: 0 for t in target_names}
first365 = {t: 0 for t in target_names}
for ordinal, identity in enumerate(selector, 1):
    found = owners.get(identity, [])
    if len(found) != 1:
        raise SystemExit(f'identity owner count {len(found)} for {ordinal}:{identity}')
    binary, source = found[0]
    rows.append((ordinal, identity, binary, source))
    counts[binary] += 1
    if ordinal <= 365:
        first365[binary] += 1
expected = {
    'directional_surface_cell_authority_kernel_tests': 30,
    'directional_surface_cell_producer_tests': 227,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
expected365 = {
    'directional_surface_cell_authority_kernel_tests': 30,
    'directional_surface_cell_producer_tests': 219,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
if counts != expected:
    raise SystemExit(f'owner distribution drift: {counts!r}')
if first365 != expected365:
    raise SystemExit(f'accepted-prefix owner distribution drift: {first365!r}')
for ordinal, identity, binary, _ in rows[365:373]:
    if binary != 'directional_surface_cell_producer_tests':
        raise SystemExit(f'CP1 row not producer-owned: {ordinal}:{identity}:{binary}')
out.write_text('ordinal\tidentity\tbinary\tsource\n' + ''.join(
    f'{ordinal}\t{identity}\t{binary}\t{source}\n' for ordinal, identity, binary, source in rows))
dist_out.write_text('binary\tfull373\tfirst365\n' + ''.join(
    f'{t}\t{counts[t]}\t{first365[t]}\n' for t in target_names))
print('identity_count=373')
print('missing=0')
print('duplicate=0')
for t in target_names:
    print(f'{t}={counts[t]} first365={first365[t]}')
PY
[[ "$(($(wc -l < "${RESULT}/identity-map.tsv") - 1))" -eq 373 ]] || fail_orchestration 'identity map count mismatch'
for binary in $(tail -n +2 "${RESULT}/identity-map.tsv" | cut -f3 | LC_ALL=C sort -u); do
  [[ -x "$PKG/bin/$binary" ]] || fail_orchestration "mapped binary absent from package: $binary"
done
sha256sum "${RESULT}/identity-map.tsv" > "${RESULT}/identity-map.sha256"
cat "${RESULT}/owner-distribution.tsv"

# Derived immutable execution view. Package and extracted source remain untouched.
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary mode mismatch: $exe"
done

grep -Fq 'executableDirectory.parent_path() / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'sibling TestFixturePaths rule drifted'
grep -Fq 'executableDirectory / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'legacy TestFixturePaths rule drifted'
probe="$(realpath -e "$EXEC_VIEW/bin/directional_surface_cell_producer_tests")"
exe_dir="$(dirname "$probe")"
sibling_candidate="$(dirname "$exe_dir")/test-data"
legacy_candidate="$exe_dir/test-data"
resolved_test_data=''
resolved_rule=''
if [[ -d "$sibling_candidate/benchmarks/fixtures" ]]; then
  resolved_test_data="$sibling_candidate"; resolved_rule='sibling'
elif [[ -d "$legacy_candidate/benchmarks/fixtures" ]]; then
  resolved_test_data="$legacy_candidate"; resolved_rule='legacy'
else
  fail_orchestration 'no consumer-resolvable fixture root in execution view'
fi
known_fixture="$resolved_test_data/benchmarks/fixtures/milestone-g/mechanical_feature.obj"
[[ -f "$known_fixture" ]] || fail_orchestration 'known fixture absent from consumer-resolved test-data root'
printf 'resolved_rule=%s\nresolved_test_data=%s\nknown_fixture=%s\n' "$resolved_rule" "$resolved_test_data" "$known_fixture" \
  | tee "${RESULT}/execution-view.txt"

census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
execution_view_verified=true
preflight_completed=true

postflight() {
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'immutable package byte/mode census changed'
  if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then
    source_test_fixture_selector_mutation=true
    fail_orchestration 'immutable packaged source byte/mode census changed'
  fi
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view byte/mode census changed'
  printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\n' | tee "${RESULT}/immutability.txt"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  echo "${TURN_ID}_PREFLIGHT_COMPLETE: package closure, owner map, fixture root, and immutable execution view verified; no Directional runtime executed."
  exit 0
fi

run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4" ledger="$5"
  local phase_dir="${phase,,}" stem="ordinal-$(printf '%03d' "$ordinal")"
  local raw="${RESULT}/raw/${phase_dir}/${stem}.log"
  local resource="${RESULT}/resources/${phase_dir}/${stem}.time.txt"
  local work="${RUNTIME}/${phase_dir}/${stem}"
  mkdir -p "$work"
  echo "${TURN_ID} phase=${phase} ordinal=${ordinal} identity=${identity} owner=${binary}"
  set +e
  (
    cd "$work"
    /usr/bin/time -v -o "$resource" \
      timeout -k 5s 180s \
      env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
      "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
  ) >"$raw" 2>&1
  code=$?
  set -e
  cat "$raw"
  selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
  result=RED
  if [[ "$selected" -eq 1 && "$code" -eq 0 ]]; then result=PASS; fi
  if [[ "$selected" -ne 1 ]]; then selection_integrity=false; fi
  if [[ "$code" -eq 124 || "$code" -eq 137 ]]; then timeout_count=$((timeout_count + 1)); fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$code" "$selected" "$result" "raw/${phase_dir}/$(basename "$raw")" >> "$ledger"
}

runtime_started=true
for phase in focused-a focused-b; do
  ledger="${RESULT}/${phase}-ledger.tsv"
  printf 'ordinal\tidentity\tbinary\texit\tselected\tresult\traw_log\n' > "$ledger"
  for ordinal in $(seq "$FOCUSED_FIRST" "$FOCUSED_LAST"); do
    map_line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "${RESULT}/identity-map.tsv")"
    identity="$(printf '%s\n' "$map_line" | cut -f2)"
    binary="$(printf '%s\n' "$map_line" | cut -f3)"
    [[ -n "$identity" && "$binary" == 'directional_surface_cell_producer_tests' ]] || fail_orchestration "focused routing mismatch at ordinal $ordinal"
    run_identity "$phase" "$ordinal" "$identity" "$binary" "$ledger"
  done
  [[ "$(($(wc -l < "$ledger") - 1))" -eq 8 ]] || fail_orchestration "$phase did not execute 8 identities"
  [[ "$(awk -F '\t' 'NR>1 && $5==1 {n++} END {print n+0}' "$ledger")" -eq 8 ]] || fail_orchestration "$phase selection count mismatch"
  sha256sum "$ledger" > "${ledger%.tsv}.sha256"
done

full_ledger="${RESULT}/ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tresult\traw_log\n' > "$full_ledger"
ordinal=0
while IFS= read -r identity || [[ -n "$identity" ]]; do
  [[ -n "$identity" ]] || continue
  ordinal=$((ordinal + 1))
  map_line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "${RESULT}/identity-map.tsv")"
  mapped_identity="$(printf '%s\n' "$map_line" | cut -f2)"
  binary="$(printf '%s\n' "$map_line" | cut -f3)"
  [[ "$mapped_identity" == "$identity" && -n "$binary" ]] || fail_orchestration "identity-map mismatch at ordinal $ordinal"
  run_identity full "$ordinal" "$identity" "$binary" "$full_ledger"
done < "$selector"
runtime_completed=true

python3 - "$full_ledger" "${RESULT}/focused-a-ledger.tsv" "${RESULT}/focused-b-ledger.tsv" "${RESULT}/semantic-summary.txt" <<'PY'
import csv, pathlib, sys
full = list(csv.DictReader(open(sys.argv[1]), delimiter='\t'))
a = list(csv.DictReader(open(sys.argv[2]), delimiter='\t'))
b = list(csv.DictReader(open(sys.argv[3]), delimiter='\t'))
out = pathlib.Path(sys.argv[4])
if len(full) != 373 or [int(r['ordinal']) for r in full] != list(range(1, 374)):
    raise SystemExit('full ledger is not exactly ordinals 1..373')
for name, rows in [('focused-a', a), ('focused-b', b)]:
    if [int(r['ordinal']) for r in rows] != list(range(366, 374)):
        raise SystemExit(f'{name} ordinal coverage mismatch')
red = [int(r['ordinal']) for r in full if r['result'] != 'PASS']
prefix_red = [n for n in red if n <= 365]
cp1 = {int(r['ordinal']): r['result'] for r in full if int(r['ordinal']) >= 366}
a_results = {int(r['ordinal']): r['result'] for r in a}
b_results = {int(r['ordinal']): r['result'] for r in b}
text = (
    'total=373\n'
    f'pass={373-len(red)}\nred={len(red)}\nred_ordinals={red}\n'
    f'accepted_prefix_pass={365-len(prefix_red)}/365\naccepted_prefix_red_ordinals={prefix_red}\n'
    f'cp1_full_results={cp1}\nfocused_a_results={a_results}\nfocused_b_results={b_results}\n'
    f'focused_vectors_equal={a_results == b_results}\n'
)
out.write_text(text)
print(text, end='')
PY
sha256sum "$full_ledger" > "${RESULT}/ledger.sha256"
postflight

if [[ "$selection_integrity" != true ]]; then fail_orchestration 'one or more processes did not select exactly one test'; fi
if [[ "$timeout_count" -ne 0 ]]; then fail_orchestration "one or more identities timed out: count=$timeout_count"; fi

echo "${TURN_ID}_COMPLETE: focused CP1 twice plus full selector373 artifact-only execution complete; semantic interpretation deferred to TB review."
