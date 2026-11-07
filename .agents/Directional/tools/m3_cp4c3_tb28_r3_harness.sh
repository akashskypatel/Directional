#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"

MODE="${1:-}"
case "$MODE" in
  --preflight-only|--execute) ;;
  *)
    echo "usage: $0 --preflight-only|--execute" >&2
    exit 64
    ;;
esac

ARTIFACT_ID=9975737868
EXPECTED_ARTIFACT_NAME='m3-cp4c3-cb32-compile-result-33987769718'
EXPECTED_PROVIDER_DIGEST='sha256:16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec'
EXPECTED_ZIP_SHA='16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec'
EXPECTED_SOURCE_SHA='098ac7d93ea203222dd0ac50cdb68667744f0fd4'
EXPECTED_365='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
EXPECTED_397='d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5'
EXPECTED_401='0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869'
EXPECTED_403='60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007'
EXPECTED_405='615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7'
EXPECTED_406='efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0'
EXPECTED_407='9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae'

ROOT="${RUNNER_TEMP}/m3-cp4c3-tb28-r3"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RESULT="${RUNNER_TEMP}/m3-cp4c3-tb28-r3-result"
LOG="${RUNNER_TEMP}/m3-cp4c3-tb28-r3.log"
ZIP="${ROOT}/artifact-${ARTIFACT_ID}.zip"
RUNTIME="${ROOT}/runtime"
mkdir -p "$ROOT" "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RESULT/raw" "$RESULT/resources" "$RUNTIME"
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
        digest = h.hexdigest()
        target = '-'
    elif stat.S_ISDIR(st.st_mode):
        kind = 'directory'
        digest = '-'
        target = '-'
    elif stat.S_ISLNK(st.st_mode):
        kind = 'symlink'
        digest = '-'
        target = os.readlink(path)
    else:
        kind = 'other'
        digest = '-'
        target = '-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{st.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows))
PY
}

sha_file() {
  sha256sum "$1" | awk '{print $1}'
}

{
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=${GITHUB_RUN_ID}"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=${GITHUB_REPOSITORY}"
  echo "runner_os=${RUNNER_OS:-unknown}"
  echo "artifact_id=${ARTIFACT_ID}"
  echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"
  echo "mode=${MODE}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  unzip -v | head -n 2
  tar --version | head -n 1
  python3 --version
  timeout --version | head -n 1
  /usr/bin/time --version | head -n 1
} | tee "${RESULT}/environment.txt"

cat > "${RESULT}/invalid-attempt-provenance.txt" <<'PROVENANCE'
TB28-R1 run=33990315861 classification=orchestration-invalid reason=incorrect-SHA256SUMS-layout semantic_credit=false
TB28-R2 run=33990951740 classification=orchestration-invalid reason=single-binary-routing-without-selection-proof semantic_credit=false
PROVENANCE

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
[[ "$zip_sha" == "$EXPECTED_ZIP_SHA" ]] || fail_orchestration "downloaded ZIP digest mismatch: $zip_sha"
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
cat "${RESULT}/runtime-executables.tsv"
sha256sum "${RESULT}/runtime-executables.tsv" | tee "${RESULT}/runtime-executables.sha256"

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
sha256sum "${RESULT}/package-census-before.tsv" | tee "${RESULT}/package-census-before.sha256"

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
tar -xzf "$source_archive" -C "$SOURCE"
[[ -f "$SOURCE/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'mechanical fixture missing from immutable packaged source'
[[ -f "$SOURCE/benchmarks/fixtures/milestone-g/sphere_prescribed.obj" ]] || fail_orchestration 'sphere fixture missing from immutable packaged source'
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
sha256sum "${RESULT}/source-census-before.tsv" | tee "${RESULT}/source-census-before.sha256"

python3 - "$SOURCE" "${RESULT}/selector-authority.txt" <<'PY'
import hashlib
import pathlib
import sys

root = pathlib.Path(sys.argv[1])
out = pathlib.Path(sys.argv[2])
expected = {
    365: '6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1',
    397: 'd67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5',
    401: '0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869',
    403: '60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007',
    405: '615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7',
    406: 'efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0',
    407: '9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae',
}
selectors = {}
for n in [397, 401, 403, 405, 406, 407]:
    path = root / f'.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_{n}.txt'
    rows = [line.strip() for line in path.read_text().splitlines() if line.strip()]
    digest = hashlib.sha256(('\n'.join(rows) + '\n').encode()).hexdigest()
    if len(rows) != n or digest != expected[n]:
        raise SystemExit(f'selector authority mismatch n={n} rows={len(rows)} digest={digest}')
    selectors[n] = rows
rows365 = selectors[397][:365]
digest365 = hashlib.sha256(('\n'.join(rows365) + '\n').encode()).hexdigest()
if digest365 != expected[365]:
    raise SystemExit(f'accepted-prefix digest mismatch: {digest365}')
for left, right in [(397,401),(401,403),(403,405),(405,406),(406,407)]:
    if selectors[right][:left] != selectors[left]:
        raise SystemExit(f'selector {left} is not exact prefix of {right}')
text = []
for n in [365,397,401,403,405,406,407]:
    text.append(f'selector_{n}_rows={n}')
    text.append(f'selector_{n}_lf_sha256={expected[n]}')
text.append('selector_prefix_chain=365<397<401<403<405<406<407')
out.write_text('\n'.join(text) + '\n')
PY
cat "${RESULT}/selector-authority.txt"

python3 - "$SOURCE" "${RESULT}/identity-map.tsv" <<'PY'
import hashlib
import pathlib
import re
import sys

root = pathlib.Path(sys.argv[1])
out = pathlib.Path(sys.argv[2])
selector = [line.strip() for line in (root / '.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_407.txt').read_text().splitlines() if line.strip()]
cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
targets = {
    'directional_compiled_api_tests': ['tests/CompiledLibraryTests.cpp'],
    'directional_surface_cell_authority_kernel_tests': [
        'tests/FieldTransportAtlasTests.cpp',
        'tests/SurfaceCellAuthorityKernelTests.cpp',
    ],
    'directional_surface_cell_completion_tests': [
        'tests/FlowRepStrandsPhase15Tests.cpp',
        'tests/PatchDescriptorMilestoneETests.cpp',
        'tests/PureQuadCompletionPhase18Tests.cpp',
        'tests/SurfaceArrangementRowIdentityTests.cpp',
        'tests/SurfaceComplexSimplificationPhase17Tests.cpp',
    ],
    'directional_surface_cell_validation_tests': [
        'tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase19Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase20Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase21Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase22Tests.cpp',
    ],
}
match = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable', cmake, re.S)
if not match:
    raise SystemExit('producer source set not found')
targets['directional_surface_cell_producer_tests'] = [
    line.strip() for line in match.group(1).splitlines() if line.strip().endswith('.cpp')
]
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
    binary, source = found[0]
    rows.append((ordinal, identity, binary, source))
out.write_text(
    'ordinal\tidentity\tbinary\tsource\n'
    + ''.join(f'{ordinal}\t{identity}\t{binary}\t{source}\n' for ordinal, identity, binary, source in rows)
)
print(f'identity_count={len(rows)}')
print('identity_map_sha256=' + hashlib.sha256(out.read_bytes()).hexdigest())
PY
[[ "$(($(wc -l < "${RESULT}/identity-map.tsv") - 1))" -eq 407 ]] || fail_orchestration 'identity map count mismatch'
awk -F '\t' 'NR>1 {count[$3]++} END {for (b in count) print b "\t" count[b]}' "${RESULT}/identity-map.tsv" \
  | LC_ALL=C sort | tee "${RESULT}/identity-owner-distribution.tsv"
for binary in $(tail -n +2 "${RESULT}/identity-map.tsv" | cut -f3 | LC_ALL=C sort -u); do
  [[ -x "$PKG/bin/$binary" ]] || fail_orchestration "mapped binary absent from package: $binary"
done
sha256sum "${RESULT}/identity-map.tsv" | tee "${RESULT}/identity-map.sha256"

# Materialize the executable-relative fixture layout without touching the immutable package/source trees.
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary mode mismatch: $exe"
done
probe="$EXEC_VIEW/bin/directional_surface_cell_producer_tests"
probe="$(realpath -e "$probe")"
exe_dir="$(dirname "$probe")"
sibling_candidate="$(dirname "$exe_dir")/test-data"
legacy_candidate="$exe_dir/test-data"
resolved_test_data=''
resolved_rule=''
if [[ -d "$sibling_candidate/benchmarks/fixtures" ]]; then
  resolved_test_data="$sibling_candidate"
  resolved_rule='sibling'
elif [[ -d "$legacy_candidate/benchmarks/fixtures" ]]; then
  resolved_test_data="$legacy_candidate"
  resolved_rule='legacy'
else
  fail_orchestration 'no consumer-resolvable fixture root in execution view'
fi
[[ -f "$resolved_test_data/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'consumer-resolved mechanical fixture missing'
{
  echo "resolved_rule=${resolved_rule}"
  echo "resolved_test_data=${resolved_test_data}"
  echo "known_fixture=${resolved_test_data}/benchmarks/fixtures/milestone-g/mechanical_feature.obj"
} | tee "${RESULT}/execution-view.txt"
grep -Fq 'executableDirectory.parent_path() / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'sibling candidate rule drifted'
grep -Fq 'executableDirectory / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'legacy candidate rule drifted'

census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
sha256sum "${RESULT}/execution-view-before.tsv" | tee "${RESULT}/execution-view-before.sha256"
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
  echo 'package_census_equal=true' | tee "${RESULT}/package-immutability.txt"
  echo 'source_census_equal=true' | tee "${RESULT}/source-immutability.txt"
  echo 'execution_view_census_equal=true' | tee "${RESULT}/execution-view-immutability.txt"
  sha256sum "${RESULT}/package-census-after.tsv" > "${RESULT}/package-census-after.sha256"
  sha256sum "${RESULT}/source-census-after.tsv" > "${RESULT}/source-census-after.sha256"
  sha256sum "${RESULT}/execution-view-after.tsv" > "${RESULT}/execution-view-after.sha256"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  echo 'CB33_PREFLIGHT_COMPLETE: package, executable routing, selection authority, and execution view verified; no Directional runtime executed.'
  exit 0
fi

selector="$SOURCE/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_407.txt"
echo -e 'ordinal\tidentity\tbinary\texit\tselected\tresult\traw_log' > "${RESULT}/ledger.tsv"
echo -e 'ordinal\tresource_log\tmax_rss_kb\telapsed' > "${RESULT}/resource-summary.tsv"
runtime_started=true
ordinal=0
while IFS= read -r identity || [[ -n "$identity" ]]; do
  [[ -n "$identity" ]] || continue
  ordinal=$((ordinal + 1))
  map_line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "${RESULT}/identity-map.tsv")"
  mapped_identity="$(printf '%s\n' "$map_line" | cut -f2)"
  binary="$(printf '%s\n' "$map_line" | cut -f3)"
  [[ "$mapped_identity" == "$identity" && -n "$binary" ]] || fail_orchestration "identity-map mismatch at ordinal $ordinal"
  raw="${RESULT}/raw/ordinal-$(printf '%03d' "$ordinal").log"
  resource="${RESULT}/resources/ordinal-$(printf '%03d' "$ordinal").time.txt"
  work="${RUNTIME}/ordinal-$(printf '%03d' "$ordinal")"
  mkdir -p "$work"
  echo "TB28_R3 ordinal=$ordinal identity=$identity owner=$binary"
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
  if [[ "$selected" -eq 1 && "$code" -eq 0 ]]; then
    result=PASS
  fi
  if [[ "$selected" -ne 1 ]]; then
    selection_integrity=false
  fi
  if [[ "$code" -eq 124 || "$code" -eq 137 ]]; then
    timeout_count=$((timeout_count + 1))
  fi
  max_rss="$(awk -F ': ' '/Maximum resident set size \(kbytes\)/ {print $2; exit}' "$resource" || true)"
  elapsed="$(sed -n 's/^\t*Elapsed (wall clock) time (h:mm:ss or m:ss): //p' "$resource" | head -n 1)"
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$code" "$selected" "$result" "raw/$(basename "$raw")" \
    >> "${RESULT}/ledger.tsv"
  printf '%s\t%s\t%s\t%s\n' \
    "$ordinal" "resources/$(basename "$resource")" "${max_rss:-unknown}" "${elapsed:-unknown}" \
    >> "${RESULT}/resource-summary.tsv"
done < "$selector"
runtime_completed=true

python3 - "${RESULT}/ledger.tsv" "${RESULT}/semantic-summary.txt" <<'PY'
import csv
import hashlib
import pathlib
import sys

ledger = pathlib.Path(sys.argv[1])
summary = pathlib.Path(sys.argv[2])
rows = list(csv.DictReader(ledger.open(), delimiter='\t'))
if len(rows) != 407:
    raise SystemExit(f'incomplete ledger: {len(rows)}')
ordinals = [int(row['ordinal']) for row in rows]
if ordinals != list(range(1, 408)):
    raise SystemExit('ledger ordinal sequence is not exactly 1..407')
red = [int(row['ordinal']) for row in rows if row['result'] == 'RED']
passed = sum(row['result'] == 'PASS' for row in rows)
selected_bad = [int(row['ordinal']) for row in rows if row['selected'] != '1']
accepted_red = [int(row['ordinal']) for row in rows if int(row['ordinal']) <= 365 and row['result'] == 'RED']
accepted_pass = 365 - len(accepted_red)
control = {ordinal: rows[ordinal - 1]['result'] for ordinal in (366, 367, 398)}
text = (
    'total=407\n'
    f'pass={passed}\n'
    f'red={len(red)}\n'
    f'red_ordinals={red}\n'
    f'selection_mismatch_ordinals={selected_bad}\n'
    f'accepted_prefix_pass={accepted_pass}/365\n'
    f'accepted_prefix_red_ordinals={accepted_red}\n'
    f'control_366_367_398={control}\n'
    f'control_known_red_reproduced={all(control[o] == "RED" for o in (366,367,398))}\n'
    f'ledger_sha256={hashlib.sha256(ledger.read_bytes()).hexdigest()}\n'
)
summary.write_text(text)
print(text, end='')
PY
sha256sum "${RESULT}/ledger.tsv" | tee "${RESULT}/ledger.sha256"
sha256sum "${RESULT}/resource-summary.tsv" | tee "${RESULT}/resource-summary.sha256"
{
  for n in 366 367 398 404 406 407; do
    f="${RESULT}/raw/ordinal-$(printf '%03d' "$n").log"
    printf '%s\t%s\t%s\n' "$n" "raw/$(basename "$f")" "$(sha_file "$f")"
  done
} | tee "${RESULT}/required-raw-log-index.tsv"

postflight

if [[ "$selection_integrity" != true ]]; then
  fail_orchestration 'one or more selector rows did not select exactly one test; see ledger.tsv'
fi
if [[ "$timeout_count" -ne 0 ]]; then
  fail_orchestration "one or more selector rows timed out: count=$timeout_count"
fi

echo 'TB28_R3_COMPLETE: immutable artifact-only selector407 execution complete; semantic interpretation deferred to TB28-R3 review.'
