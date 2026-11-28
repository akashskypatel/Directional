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
: "${EXPECTED_SOURCE_SHA:?}"
: "${SELECTOR_RELATIVE_PATH:?}"
: "${EXPECTED_SELECTOR_COUNT:?}"
: "${EXPECTED_SELECTOR_SHA256:?}"
: "${ACCEPTED_PREFIX_COUNT:?}"

MODE="${1:-}"
case "$MODE" in
  --preflight-only|--execute) ;;
  *)
    echo "usage: $0 --preflight-only|--execute" >&2
    exit 64
    ;;
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
mkdir -p "$ROOT" "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RESULT/raw" \
  "$RESULT/resources" "$RESULT/failure-details" "$RUNTIME"
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

sha_file() {
  sha256sum "$1" | awk '{print $1}'
}

census_tree() {
  local root="$1" out="$2"
  python3 - "$root" "$out" <<'PY'
import hashlib
import os
import pathlib
import stat
import sys
root = pathlib.Path(sys.argv[1]).resolve()
out = pathlib.Path(sys.argv[2])
rows = []
for path in [root, *sorted(root.rglob('*'), key=lambda p: p.relative_to(root).as_posix())]:
    rel = '.' if path == root else path.relative_to(root).as_posix()
    st = path.lstat()
    mode = format(stat.S_IMODE(st.st_mode), 'o')
    if stat.S_ISREG(st.st_mode):
        kind = 'file'
        h = hashlib.sha256()
        with path.open('rb') as stream:
            for chunk in iter(lambda: stream.read(1024 * 1024), b''):
                h.update(chunk)
        digest, target = h.hexdigest(), '-'
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
  echo "mode=${MODE}"
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
  "$ARTIFACT_ID" "$artifact_name" "$provider_digest" "$zip_sha" \
  | tee "${RESULT}/artifact-authority.txt"

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
  directional_benchmarks
  directional_compiled_api_tests
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_validation_tests
)
printf 'binary\tsha256\tmode\tsize\n' > "${RESULT}/runtime-executables.tsv"
for exe in "${required_executables[@]}"; do
  path="$PKG/bin/$exe"
  [[ -f "$path" && -x "$path" ]] || fail_orchestration "required executable absent or non-executable: $exe"
  printf '%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" \
    >> "${RESULT}/runtime-executables.tsv"
done
sha256sum "${RESULT}/runtime-executables.tsv" > "${RESULT}/runtime-executables.sha256"

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
[[ -f "$selector" ]] || fail_orchestration "selector absent: $SELECTOR_RELATIVE_PATH"
selector_count="$(grep -cve '^[[:space:]]*$' "$selector")"
selector_sha="$(sha_file "$selector")"
[[ "$selector_count" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration "selector count mismatch: $selector_count"
[[ "$selector_sha" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration "selector digest mismatch: $selector_sha"
printf 'selector_path=%s\nselector_rows=%s\nselector_lf_sha256=%s\naccepted_prefix_count=%s\n' \
  "$SELECTOR_RELATIVE_PATH" "$selector_count" "$selector_sha" "$ACCEPTED_PREFIX_COUNT" \
  | tee "${RESULT}/selector-authority.txt"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"

python3 - "$SOURCE" "$selector" "${RESULT}/identity-map.tsv" <<'PY'
import hashlib
import pathlib
import re
import sys
root = pathlib.Path(sys.argv[1])
selector_path = pathlib.Path(sys.argv[2])
out = pathlib.Path(sys.argv[3])
selector = [line.strip() for line in selector_path.read_text().splitlines() if line.strip()]
cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
targets = {
    'directional_compiled_api_tests': ['tests/CompiledLibraryTests.cpp'],
    'directional_surface_cell_authority_kernel_tests': [
        'tests/FieldTransportAtlasTests.cpp', 'tests/SurfaceCellAuthorityKernelTests.cpp'],
    'directional_surface_cell_completion_tests': [
        'tests/FlowRepStrandsPhase15Tests.cpp', 'tests/PatchDescriptorMilestoneETests.cpp',
        'tests/PureQuadCompletionPhase18Tests.cpp', 'tests/SurfaceArrangementRowIdentityTests.cpp',
        'tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
    'directional_surface_cell_validation_tests': [
        'tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase19Tests.cpp', 'tests/SurfaceMeshOptimizerPhase20Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase21Tests.cpp', 'tests/SurfaceMeshOptimizerPhase22Tests.cpp'],
}
match = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable', cmake, re.S)
if not match:
    raise SystemExit('producer source set not found')
targets['directional_surface_cell_producer_tests'] = [
    line.strip() for line in match.group(1).splitlines() if line.strip().endswith('.cpp')]
pattern = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners = {}
for target, files in targets.items():
    for relative in files:
        path = root / relative
        if not path.exists():
            continue
        for suite, name in pattern.findall(path.read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}', []).append((target, relative))
rows = []
for ordinal, identity in enumerate(selector, 1):
    found = owners.get(identity, [])
    if len(found) != 1:
        raise SystemExit(f'identity owner count {len(found)} for {ordinal}:{identity}')
    rows.append((ordinal, identity, *found[0]))
out.write_text('ordinal\tidentity\tbinary\tsource\n' + ''.join(
    f'{ordinal}\t{identity}\t{binary}\t{source}\n'
    for ordinal, identity, binary, source in rows))
print(f'identity_count={len(rows)}')
print('identity_map_sha256=' + hashlib.sha256(out.read_bytes()).hexdigest())
PY
[[ "$(($(wc -l < "${RESULT}/identity-map.tsv") - 1))" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration 'identity map count mismatch'
for binary in $(tail -n +2 "${RESULT}/identity-map.tsv" | cut -f3 | LC_ALL=C sort -u); do
  [[ -x "$PKG/bin/$binary" ]] || fail_orchestration "mapped binary absent from package: $binary"
done
sha256sum "${RESULT}/identity-map.tsv" > "${RESULT}/identity-map.sha256"

cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary mode mismatch: $exe"
done
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
  printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\n' \
    | tee "${RESULT}/immutability.txt"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  echo "${TURN_ID}_PREFLIGHT_COMPLETE: immutable package and selector authority verified; no Directional runtime executed."
  exit 0
fi

# This file names the run that is actually executing the artifact. Never copy a
# baseline run ID from a preceding turn into this authority record.
printf '%s run=%s artifact=%s source=%s selector=%s\n' \
  "$TURN_ID" "$GITHUB_RUN_ID" "$ARTIFACT_ID" "$EXPECTED_SOURCE_SHA" "$EXPECTED_SELECTOR_COUNT" \
  > "${RESULT}/baseline-authority.txt"

printf 'ordinal\tidentity\tbinary\texit\tselected\tresult\traw_log\n' > "${RESULT}/ledger.tsv"
printf 'ordinal\tidentity\tresult\tdetail_sha256\tdetail_file\n' > "${RESULT}/failure-detail-digests.tsv"
printf 'ordinal\tresource_log\tmax_rss_kb\telapsed\n' > "${RESULT}/resource-summary.tsv"
runtime_started=true
ordinal=0
while IFS= read -r identity || [[ -n "$identity" ]]; do
  [[ -n "$identity" ]] || continue
  ordinal=$((ordinal + 1))
  map_line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "${RESULT}/identity-map.tsv")"
  mapped_identity="$(printf '%s\n' "$map_line" | cut -f2)"
  binary="$(printf '%s\n' "$map_line" | cut -f3)"
  [[ "$mapped_identity" == "$identity" && -n "$binary" ]] || fail_orchestration "identity-map mismatch at ordinal $ordinal"
  stem="ordinal-$(printf '%03d' "$ordinal")"
  raw="${RESULT}/raw/${stem}.log"
  resource="${RESULT}/resources/${stem}.time.txt"
  detail="${RESULT}/failure-details/${stem}.txt"
  work="${RUNTIME}/${stem}"
  mkdir -p "$work"
  echo "${TURN_ID} ordinal=$ordinal identity=$identity owner=$binary"
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

  python3 - "$raw" "$detail" "$result" "$code" "$selected" <<'PY'
import pathlib
import re
import sys
raw = pathlib.Path(sys.argv[1])
out = pathlib.Path(sys.argv[2])
result, code, selected = sys.argv[3:]
if result == 'PASS':
    out.write_text('PASS\n')
    raise SystemExit(0)
lines = raw.read_text(errors='replace').splitlines()
blocks = []
i = 0
while i < len(lines):
    if lines[i].rstrip().endswith(': Failure'):
        block = [lines[i]]
        i += 1
        while i < len(lines):
            line = lines[i]
            if line.startswith('[  FAILED  ]') or line.startswith('[----------]') or line.startswith('[==========]'):
                break
            if line.rstrip().endswith(': Failure'):
                break
            block.append(line)
            i += 1
        while block and not block[-1].strip():
            block.pop()
        blocks.append('\n'.join(block))
        continue
    i += 1
if blocks:
    out.write_text('\n---\n'.join(blocks) + '\n')
else:
    tail = [line for line in lines if line.strip()][-8:]
    out.write_text(
        f'PROCESS_FAILURE exit={code} selected={selected}\n' +
        '\n'.join(tail) + ('\n' if tail else ''))
PY
  detail_sha="$(sha_file "$detail")"
  max_rss="$(awk -F ': ' '/Maximum resident set size \(kbytes\)/ {print $2; exit}' "$resource" || true)"
  elapsed="$(sed -n 's/^\t*Elapsed (wall clock) time (h:mm:ss or m:ss): //p' "$resource" | head -n 1)"
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$code" "$selected" "$result" "raw/$(basename "$raw")" \
    >> "${RESULT}/ledger.tsv"
  printf '%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$result" "$detail_sha" "failure-details/$(basename "$detail")" \
    >> "${RESULT}/failure-detail-digests.tsv"
  printf '%s\t%s\t%s\t%s\n' \
    "$ordinal" "resources/$(basename "$resource")" "${max_rss:-unknown}" "${elapsed:-unknown}" \
    >> "${RESULT}/resource-summary.tsv"
done < "$selector"
runtime_completed=true

python3 - "${RESULT}/ledger.tsv" "${RESULT}/semantic-summary.txt" "$EXPECTED_SELECTOR_COUNT" "$ACCEPTED_PREFIX_COUNT" <<'PY'
import csv
import hashlib
import pathlib
import sys
ledger = pathlib.Path(sys.argv[1])
summary = pathlib.Path(sys.argv[2])
expected = int(sys.argv[3])
accepted = int(sys.argv[4])
rows = list(csv.DictReader(ledger.open(), delimiter='\t'))
if len(rows) != expected:
    raise SystemExit(f'incomplete ledger: {len(rows)} != {expected}')
if [int(row['ordinal']) for row in rows] != list(range(1, expected + 1)):
    raise SystemExit('ledger ordinal sequence mismatch')
red = [int(row['ordinal']) for row in rows if row['result'] == 'RED']
selected_bad = [int(row['ordinal']) for row in rows if row['selected'] != '1']
accepted_red = [n for n in red if n <= accepted]
text = (
    f'total={expected}\npass={expected-len(red)}\nred={len(red)}\nred_ordinals={red}\n'
    f'selection_mismatch_ordinals={selected_bad}\n'
    f'accepted_prefix_pass={accepted-len(accepted_red)}/{accepted}\n'
    f'accepted_prefix_red_ordinals={accepted_red}\n'
    f'ledger_sha256={hashlib.sha256(ledger.read_bytes()).hexdigest()}\n')
summary.write_text(text)
print(text, end='')
PY
sha256sum "${RESULT}/ledger.tsv" > "${RESULT}/ledger.sha256"
sha256sum "${RESULT}/failure-detail-digests.tsv" > "${RESULT}/failure-detail-digests.sha256"
sha256sum "${RESULT}/resource-summary.tsv" > "${RESULT}/resource-summary.sha256"
postflight

if [[ "$selection_integrity" != true ]]; then fail_orchestration 'one or more selector rows did not select exactly one test'; fi
if [[ "$timeout_count" -ne 0 ]]; then fail_orchestration "one or more selector rows timed out: count=$timeout_count"; fi

echo "${TURN_ID}_COMPLETE: immutable artifact-only selector execution complete; semantic interpretation deferred to review."
