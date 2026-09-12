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

EXPECTED_SOURCE_SHA='9d66fcebe4b91ab74a6d0234c46643a2723ab643'
EXPECTED_MANIFEST_SHA256='26529a4d12434bc737e4952f09f9790dd8f36d4151e1500154fa7a60497101af'
EXPECTED_SOURCE_ARCHIVE_SHA256='3c82e4778ec4ea4631e25d39ed18f7f7ed68a2a24a1ad08e3ebfe298dfe331a9'
SELECTOR403_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt'
SELECTOR408_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt'
EXPECTED_SELECTOR403_SHA256='c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7'
EXPECTED_SELECTOR408_SHA256='c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484'
ROW408='RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity'

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
HARNESS_LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}-harness.log"
ZIP="${ROOT}/artifact-${ARTIFACT_ID}.zip"
RUNTIME="${ROOT}/runtime"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RESULT/raw" "$RESULT/resources" "$RUNTIME"
: > "$HARNESS_LOG"
exec > >(tee -a "$HARNESS_LOG") 2>&1

preflight_completed=false
runtime_started=false
postflight_completed=false
orchestration_failure=false
semantic_red=false
red_phase=''
red_ordinal=''
red_identity=''
red_owner=''
red_exit=''
red_selected=''
red_skipped=''
process_total=0
phase_a=0
phase_b=0
phase_c=0
phase_d=0
phase_e=0

finish() {
  status=$?
  set +e
  {
    echo "script_exit=${status}"
    echo "turn_id=${TURN_ID}"
    echo "runtime_started=${runtime_started}"
    echo "preflight_completed=${preflight_completed}"
    echo "postflight_completed=${postflight_completed}"
    echo "orchestration_failure=${orchestration_failure}"
    echo "semantic_red=${semantic_red}"
    echo "process_total=${process_total}"
    echo "phase_a=${phase_a}"
    echo "phase_b=${phase_b}"
    echo "phase_c=${phase_c}"
    echo "phase_d=${phase_d}"
    echo "phase_e=${phase_e}"
    echo "red_phase=${red_phase}"
    echo "red_ordinal=${red_ordinal}"
    echo "red_identity=${red_identity}"
    echo "red_owner=${red_owner}"
    echo "red_exit=${red_exit}"
    echo "red_selected=${red_selected}"
    echo "red_skipped=${red_skipped}"
    echo 'benchmark_execution=false'
    echo 'configure_execution=false'
    echo 'compile_execution=false'
    echo 'relink_execution=false'
    echo 'generated_discovery=false'
    echo 'package_repair=false'
    echo 'mode_repair=false'
    echo 'source_test_fixture_selector_mutation=false'
    echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  } | tee "${RESULT}/execution-boundary.txt"
}
trap finish EXIT

fail_orchestration() {
  orchestration_failure=true
  echo "ORCHESTRATION_RED: $*" >&2
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

write_machine_summary() {
  local state="$1"
  python3 - "$RESULT/machine-summary.json" "$state" "$process_total" "$phase_a" "$phase_b" "$phase_c" "$phase_d" "$phase_e" \
    "$red_phase" "$red_ordinal" "$red_identity" "$red_owner" "$red_exit" "$red_selected" "$red_skipped" <<'PY'
import json, pathlib, sys
(path, state, total, a, b, c, d, e, phase, ordinal, identity, owner, exit_code, selected, skipped) = sys.argv[1:]
def maybe_int(x):
    try: return int(x)
    except Exception: return None
obj = {
    'turn': 'M4-CP3-TB4-EXEC',
    'exitState': state,
    'artifactId': 10292005428,
    'packageSource': '9d66fcebe4b91ab74a6d0234c46643a2723ab643',
    'processCount': int(total),
    'phaseCounts': {'A': int(a), 'B': int(b), 'C': int(c), 'D': int(d), 'E': int(e)},
    'expectedGreenProcessCount': 821,
    'red': {
        'phase': phase or None,
        'ordinal': maybe_int(ordinal),
        'identity': identity or None,
        'owner': owner or None,
        'exit': maybe_int(exit_code),
        'selected': maybe_int(selected),
        'skipped': maybe_int(skipped),
    },
    'immutablePreflight': True,
    'immutablePostflight': bool(state != 'ORCHESTRATION_RED'),
    'configureExecution': False,
    'compileExecution': False,
    'relinkExecution': False,
    'generatedDiscovery': False,
    'benchmarkExecution': False,
    'packageRepair': False,
    'modeRepair': False,
}
pathlib.Path(path).write_text(json.dumps(obj, indent=2, sort_keys=True) + '\n')
PY
}

{
  echo "turn_id=${TURN_ID}"
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=${GITHUB_RUN_ID}"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=${GITHUB_REPOSITORY}"
  echo "artifact_id=${ARTIFACT_ID}"
  echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  python3 --version
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
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA256" ]] || fail_orchestration 'SHA256SUMS file digest mismatch'
[[ "$(wc -l < "$PKG/SHA256SUMS")" -eq 28 ]] || fail_orchestration 'SHA256SUMS entry count mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "${RESULT}/sha256sums-check-before.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'compile exit nonzero'
grep -Fxq 'runtimeExecution=false' "$PKG/metadata/command-boundary.txt" || fail_orchestration 'build runtimeExecution boundary missing/changed'

required_executables=(
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_validation_tests
)
printf 'binary\tsha256\tmode\tsize\n' > "${RESULT}/owner-executables-before.tsv"
for exe in "${required_executables[@]}"; do
  path="$PKG/bin/$exe"
  [[ -f "$path" && -x "$path" ]] || fail_orchestration "required owner executable absent or non-executable: $exe"
  printf '%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" \
    >> "${RESULT}/owner-executables-before.tsv"
done

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
selector403="$SOURCE/$SELECTOR403_RELATIVE_PATH"
selector408="$SOURCE/$SELECTOR408_RELATIVE_PATH"
[[ -f "$selector403" && -f "$selector408" ]] || fail_orchestration 'selector file absent'
[[ "$(sha_file "$selector403")" == "$EXPECTED_SELECTOR403_SHA256" ]] || fail_orchestration 'selector403 digest mismatch'
[[ "$(sha_file "$selector408")" == "$EXPECTED_SELECTOR408_SHA256" ]] || fail_orchestration 'selector408 digest mismatch'
[[ "$(grep -cve '^[[:space:]]*$' "$selector403")" -eq 403 ]] || fail_orchestration 'selector403 count mismatch'
[[ "$(grep -cve '^[[:space:]]*$' "$selector408")" -eq 408 ]] || fail_orchestration 'selector408 count mismatch'
head -n 403 "$selector408" | cmp - "$selector403" || fail_orchestration 'selector408 rows1-403 differ from selector403'
[[ "$(sed -n '408p' "$selector408")" == "$ROW408" ]] || fail_orchestration 'selector408 row408 identity drifted'
printf 'selector403_sha256=%s\nselector408_sha256=%s\nselector403_rows=403\nselector408_rows=408\nprefix_equal=true\nrow408=%s\n' \
  "$EXPECTED_SELECTOR403_SHA256" "$EXPECTED_SELECTOR408_SHA256" "$ROW408" | tee "${RESULT}/selector-authority.txt"

python3 - "$SOURCE" "$selector403" "$selector408" "${RESULT}/identity-map.tsv" "${RESULT}/owner-distribution.tsv" <<'PY'
import pathlib, re, sys
root = pathlib.Path(sys.argv[1])
selector403_path = pathlib.Path(sys.argv[2])
selector408_path = pathlib.Path(sys.argv[3])
out = pathlib.Path(sys.argv[4])
dist_out = pathlib.Path(sys.argv[5])
selector403 = [line.strip() for line in selector403_path.read_text().splitlines() if line.strip()]
selector408 = [line.strip() for line in selector408_path.read_text().splitlines() if line.strip()]
cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
target_names = ['directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests']
def cpp_lines(text): return [line.strip() for line in text.splitlines() if line.strip().endswith('.cpp')]
producer = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable', cmake, re.S)
if not producer: raise SystemExit('producer source set not found')
targets = {'directional_surface_cell_producer_tests': cpp_lines(producer.group(1))}
for target in [t for t in target_names if t != 'directional_surface_cell_producer_tests']:
    m = re.search(r'add_executable\(\s*' + re.escape(target) + r'(.*?)\)\s*\n', cmake, re.S)
    if not m: raise SystemExit(f'target source block not found: {target}')
    targets[target] = cpp_lines(m.group(1))
pattern = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners = {}
for target in target_names:
    for relative in targets[target]:
        path = root / relative
        if not path.is_file(): raise SystemExit(f'owner source missing: {target}:{relative}')
        for suite, name in pattern.findall(path.read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}', []).append((target, relative))
rows = []
counts408 = {t: 0 for t in target_names}; counts403 = {t: 0 for t in target_names}
for ordinal, identity in enumerate(selector408, 1):
    found = owners.get(identity, [])
    if len(found) != 1: raise SystemExit(f'identity owner count {len(found)} for {ordinal}:{identity}')
    binary, source = found[0]; rows.append((ordinal, identity, binary, source)); counts408[binary] += 1
    if ordinal <= 403: counts403[binary] += 1
expected408 = {'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_producer_tests':262,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
expected403 = {'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_producer_tests':257,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
if counts408 != expected408: raise SystemExit(f'owner408 distribution drift: {counts408!r}')
if counts403 != expected403: raise SystemExit(f'owner403 distribution drift: {counts403!r}')
if selector408[:403] != selector403: raise SystemExit('selector prefix mismatch after parse')
row408 = rows[407]
if row408[1] != 'RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity': raise SystemExit(f'row408 identity drift: {row408[1]}')
if row408[2] != 'directional_surface_cell_producer_tests': raise SystemExit(f'row408 owner drift: {row408[2]}')
out.write_text('ordinal\tidentity\tbinary\tsource\n' + ''.join(f'{ordinal}\t{identity}\t{binary}\t{source}\n' for ordinal, identity, binary, source in rows))
dist_out.write_text('binary\tselector408\tselector403\n' + ''.join(f'{t}\t{counts408[t]}\t{counts403[t]}\n' for t in target_names))
print('identity_count=408'); print('missing=0'); print('ambiguous=0')
for t in target_names: print(f'{t} selector408={counts408[t]} selector403={counts403[t]}')
PY
[[ "$(($(wc -l < "${RESULT}/identity-map.tsv") - 1))" -eq 408 ]] || fail_orchestration 'identity map count mismatch'
for binary in $(tail -n +2 "${RESULT}/identity-map.tsv" | cut -f3 | LC_ALL=C sort -u); do [[ -x "$PKG/bin/$binary" ]] || fail_orchestration "mapped binary absent from package: $binary"; done
cat "${RESULT}/owner-distribution.tsv"

row_source="$SOURCE/tests/FieldAlignedCurveNetworkTests.cpp"
for token in 'cp4c_torus_hard_rail_remesh_options' 'const std::array<int, 7> minorCycle{{0, 3, 25, 37, 49, 61, 0}}' '0, 1, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 0' 'options.surfaceCells.featureMap.userHardEdges.insert' 'ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity' 'ASSERT_GT(hardFeatureRailCount, 0U)' 'SurfaceCellProducerDisposition::Produced' 'EXPECT_NE("InvalidHardRailPairing", fixture.terminalFailureDetailCode)' 'EXPECT_GT(exactSharedIntervals, 0U)'; do
  grep -Fq "$token" "$row_source" || fail_orchestration "CB6 row408 witness token absent: $token"
done
printf 'cb6_row408_static_witness=true\n' | tee "${RESULT}/cb6-row408-static-witness.txt"

cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary mode mismatch: $exe"
done
grep -Fq 'executableDirectory.parent_path() / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'sibling TestFixturePaths rule drifted'
known_fixture="$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj"
[[ -f "$known_fixture" ]] || fail_orchestration 'known fixture absent from execution view'
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
preflight_completed=true

postflight() {
  local failed=0
  (cd "$PKG" && sha256sum -c SHA256SUMS) > "${RESULT}/sha256sums-check-after.txt" 2>&1 || failed=1
  [[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA256" ]] || failed=1
  [[ "$(sha_file "$selector403")" == "$EXPECTED_SELECTOR403_SHA256" ]] || failed=1
  [[ "$(sha_file "$selector408")" == "$EXPECTED_SELECTOR408_SHA256" ]] || failed=1
  [[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || failed=1
  printf 'binary\tsha256\tmode\tsize\n' > "${RESULT}/owner-executables-after.tsv"
  for exe in "${required_executables[@]}"; do path="$PKG/bin/$exe"; printf '%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" >> "${RESULT}/owner-executables-after.tsv"; done
  cmp -s "${RESULT}/owner-executables-before.tsv" "${RESULT}/owner-executables-after.tsv" || failed=1
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || failed=1
  cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv" || failed=1
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || failed=1
  if [[ "$failed" -ne 0 ]]; then orchestration_failure=true; echo 'ORCHESTRATION_RED: immutable postflight mismatch' >&2; write_machine_summary 'ORCHESTRATION_RED'; exit 91; fi
  postflight_completed=true
  printf 'sha256sums=true\nselector403=true\nselector408=true\nsource_archive=true\nexecutable_modes=true\npackage_census=true\nsource_census=true\nexecution_view_census=true\n' | tee "${RESULT}/postflight.txt"
}

printf 'process\tphase\tordinal\tidentity\tbinary\texit\tselected\tskipped\tresult\telapsed_ms\traw_log\tresource_log\n' > "${RESULT}/process-ledger.tsv"
run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4" phase_dir process_index stem raw resource work start_ns end_ns elapsed_ms code selected skipped result
  phase_dir="$(printf '%s' "$phase" | tr '[:upper:]' '[:lower:]' | tr -c 'a-z0-9._-' '-')"; process_index=$((process_total + 1)); stem="process-$(printf '%03d' "$process_index")-ordinal-$(printf '%03d' "$ordinal")"
  raw="${RESULT}/raw/${phase_dir}/${stem}.log"; resource="${RESULT}/resources/${phase_dir}/${stem}.time.txt"; work="${RUNTIME}/${phase_dir}/${stem}"
  mkdir -p "$(dirname "$raw")" "$(dirname "$resource")" "$work"
  echo "TB4 process=${process_index} phase=${phase} ordinal=${ordinal} identity=${identity} owner=${binary}"
  start_ns="$(date +%s%N)"; set +e
  (cd "$work"; /usr/bin/time -v -o "$resource" env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw" 2>&1
  code=$?; set -e; end_ns="$(date +%s%N)"; elapsed_ms=$(((end_ns - start_ns) / 1000000)); cat "$raw"
  selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"; skipped="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"; result='RED'
  if [[ "$code" -eq 0 && "$selected" -eq 1 && "$skipped" -eq 0 ]] && grep -Fq "[       OK ] ${identity}" "$raw"; then result='PASS'; fi
  process_total=$process_index
  case "$phase" in A-row408) phase_a=$((phase_a + 1));; B-row408) phase_b=$((phase_b + 1));; C-controls-*) phase_c=$((phase_c + 1));; D-selector403) phase_d=$((phase_d + 1));; E-selector408) phase_e=$((phase_e + 1));; esac
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$process_index" "$phase" "$ordinal" "$identity" "$binary" "$code" "$selected" "$skipped" "$result" "$elapsed_ms" "raw/${phase_dir}/$(basename "$raw")" "resources/${phase_dir}/$(basename "$resource")" >> "${RESULT}/process-ledger.tsv"
  if [[ "$result" != 'PASS' ]]; then semantic_red=true; red_phase="$phase"; red_ordinal="$ordinal"; red_identity="$identity"; red_owner="$binary"; red_exit="$code"; red_selected="$selected"; red_skipped="$skipped"; return 1; fi
}
route_identity() { awk -F '\t' -v o="$1" 'NR>1 && $1==o {print $2 "\t" $3; exit}' "${RESULT}/identity-map.tsv"; }
run_ordinal() { local phase="$1" ordinal="$2" route identity binary; route="$(route_identity "$ordinal")"; identity="${route%%$'\t'*}"; binary="${route#*$'\t'}"; [[ -n "$identity" && -n "$binary" && "$identity" != "$binary" ]] || fail_orchestration "identity map lookup failed: $ordinal"; run_identity "$phase" "$ordinal" "$identity" "$binary"; }

runtime_started=true
if ! run_ordinal 'A-row408' 408; then postflight; write_machine_summary 'SEMANTIC_RED'; exit 1; fi
if ! run_ordinal 'B-row408' 408; then postflight; write_machine_summary 'SEMANTIC_RED'; exit 1; fi
for phase in C-controls-A C-controls-B; do for ordinal in 404 405 406 407; do if ! run_ordinal "$phase" "$ordinal"; then postflight; write_machine_summary 'SEMANTIC_RED'; exit 1; fi; done; done
for ordinal in $(seq 1 403); do if ! run_ordinal 'D-selector403' "$ordinal"; then postflight; write_machine_summary 'SEMANTIC_RED'; exit 1; fi; done
for ordinal in $(seq 1 408); do if ! run_ordinal 'E-selector408' "$ordinal"; then postflight; write_machine_summary 'SEMANTIC_RED'; exit 1; fi; done
[[ "$process_total" -eq 821 && "$phase_a" -eq 1 && "$phase_b" -eq 1 && "$phase_c" -eq 8 && "$phase_d" -eq 403 && "$phase_e" -eq 408 ]] || fail_orchestration "green process cardinality mismatch: total=$process_total A=$phase_a B=$phase_b C=$phase_c D=$phase_d E=$phase_e"
postflight
write_machine_summary 'GREEN'
sha256sum "${RESULT}/process-ledger.tsv" > "${RESULT}/process-ledger.sha256"
echo 'M4-CP3-TB4-EXEC GREEN: all 821 exact fresh GTest processes passed and immutable postflight passed; interpretation deferred to TB4-REV.'
