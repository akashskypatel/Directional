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

EXPECTED_SOURCE_SHA='1611e9ef57bd1437b4422ab2fca7acef20b19a3a'
EXPECTED_SOURCE_ARCHIVE_SHA256='1ff187c6c08d13f5be5e6481f5323541e48fc93e6ffc0ada78af73a7926c205d'
EXPECTED_MANIFEST_SHA256='35e405ba8d72e4a928f1518f74b2ea6b009aa89995bb268d23cb3cc8392b13d3'
SELECTOR403_REL='.agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt'
SELECTOR408_REL='.agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt'
EXPECTED_SELECTOR403_COUNT=403
EXPECTED_SELECTOR408_COUNT=408
EXPECTED_SELECTOR403_SHA256='c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7'
EXPECTED_SELECTOR408_SHA256='c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484'
ROW408_IDENTITY='RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity'
ORDINAL138_IDENTITY='SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped'
SHARED_FOCUSED_ORDINALS=(211 217 219 227 230 231)
SHARED_FOCUSED_IDENTITIES=(
  'SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected'
  'SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions'
  'SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected'
  'SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed'
  'SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed'
  'SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity'
)

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
ZIP="${ROOT}/artifact-${ARTIFACT_ID}.zip"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RUNTIME" "$RESULT/raw" "$RESULT/resources"
: > "$LOG"
exec > >(tee -a "$LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
postflight_completed=false
orchestration_failure=false
selection_integrity=true
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
source_test_fixture_selector_mutation=false
processes_executed=0
pass_count=0
red_count=0
skip_count=0
crash_count=0
selection_mismatch_count=0
stop_kind='NONE'
stop_phase='NONE'
stop_ordinal='0'
stop_identity='NONE'

finish() {
  status=$?
  set +e
  {
    echo "script_exit=${status}"
    echo "turn_id=${TURN_ID}"
    echo "runtime_started=${runtime_started}"
    echo "runtime_completed=${runtime_completed}"
    echo "preflight_completed=${preflight_completed}"
    echo "postflight_completed=${postflight_completed}"
    echo "orchestration_failure=${orchestration_failure}"
    echo "selection_integrity=${selection_integrity}"
    echo "processes_executed=${processes_executed}"
    echo "pass_count=${pass_count}"
    echo "red_count=${red_count}"
    echo "skip_count=${skip_count}"
    echo "crash_count=${crash_count}"
    echo "selection_mismatch_count=${selection_mismatch_count}"
    echo "stop_kind=${stop_kind}"
    echo "stop_phase=${stop_phase}"
    echo "stop_ordinal=${stop_ordinal}"
    echo "stop_identity=${stop_identity}"
    echo "benchmark_execution=${benchmark_execution}"
    echo "configure_execution=${configure_execution}"
    echo "compile_execution=${compile_execution}"
    echo "relink_execution=${relink_execution}"
    echo "generated_discovery=${generated_discovery}"
    echo "package_repair=${package_repair}"
    echo "source_test_fixture_selector_mutation=${source_test_fixture_selector_mutation}"
  } | tee "${RESULT}/execution-boundary.txt"
  echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" | tee -a "$LOG"
}
trap finish EXIT

sha_file() { sha256sum "$1" | awk '{print $1}'; }

fail_orchestration() {
  orchestration_failure=true
  stop_kind='ORCHESTRATION'
  echo "ORCHESTRATION_FAILURE: $*" >&2
  exit 90
}

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
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "suite_timeout_policy=none"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
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
[[ "$(wc -l < "$PKG/SHA256SUMS" | tr -d ' ')" -eq 28 ]] || fail_orchestration 'root SHA256SUMS entry count drift'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA256" ]] || fail_orchestration 'package manifest digest mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "${RESULT}/sha256sums-preflight.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'source commit mismatch'
[[ "$(cat "$PKG/metadata/preflight-target.txt")" == 'directional_core' ]] || fail_orchestration 'preflight target mismatch'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'compile preflight exit nonzero'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'build exit nonzero'
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing command boundary: $token"
done
for token in 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/gmp-evidence.txt" || fail_orchestration "missing GMP evidence: $token"
done
for status_file in "$PKG"/metadata/source-status-*.txt; do
  [[ -f "$status_file" ]] || fail_orchestration 'source-status snapshot set absent'
  [[ ! -s "$status_file" ]] || fail_orchestration "non-empty source-status snapshot: $(basename "$status_file")"
done
for exe in directional_benchmarks directional_compiled_api_tests; do
  [[ -f "$PKG/bin/$exe" && -x "$PKG/bin/$exe" ]] || fail_orchestration "required packaged executable absent or non-executable: $exe"
done
for archive in libdirectional_core.a libdirectional_pipeline.a; do
  [[ -f "$PKG/lib/$archive" ]] || fail_orchestration "required packaged archive absent: $archive"
done

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE"

selector403="$SOURCE/$SELECTOR403_REL"
selector408="$SOURCE/$SELECTOR408_REL"
[[ -f "$selector403" && -f "$selector408" ]] || fail_orchestration 'selector file absent'
[[ "$(grep -cve '^[[:space:]]*$' "$selector403")" -eq "$EXPECTED_SELECTOR403_COUNT" ]] || fail_orchestration 'selector403 count mismatch'
[[ "$(grep -cve '^[[:space:]]*$' "$selector408")" -eq "$EXPECTED_SELECTOR408_COUNT" ]] || fail_orchestration 'selector408 count mismatch'
[[ "$(sha_file "$selector403")" == "$EXPECTED_SELECTOR403_SHA256" ]] || fail_orchestration 'selector403 digest mismatch'
[[ "$(sha_file "$selector408")" == "$EXPECTED_SELECTOR408_SHA256" ]] || fail_orchestration 'selector408 digest mismatch'
head -n 403 "$selector408" > "${RESULT}/selector408-first403.txt"
cmp -s "${RESULT}/selector408-first403.txt" "$selector403" || fail_orchestration 'selector408 first403 not byte-identical to selector403'
printf 'selector403_rows=403\nselector403_sha256=%s\nselector408_rows=408\nselector408_sha256=%s\nfirst403_exact=true\n' \
  "$EXPECTED_SELECTOR403_SHA256" "$EXPECTED_SELECTOR408_SHA256" | tee "${RESULT}/selector-authority.txt"

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

python3 - "$SOURCE" "$selector408" "${RESULT}/identity-map.tsv" "${RESULT}/owner-distribution.tsv" <<'PY'
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
producer = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\s*\n\s*add_executable', cmake, re.S)
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
for target, files in targets.items():
    for relative in files:
        path = root / relative
        if not path.is_file():
            raise SystemExit(f'missing target source: {target}:{relative}')
        for suite, name in pattern.findall(path.read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}', []).append((target, relative))
rows = []
counts = {t: 0 for t in target_names}
first403 = {t: 0 for t in target_names}
for ordinal, identity in enumerate(selector, 1):
    found = owners.get(identity, [])
    if len(found) != 1:
        raise SystemExit(f'identity owner count {len(found)} for {ordinal}:{identity}')
    binary, source = found[0]
    rows.append((ordinal, identity, binary, source))
    counts[binary] += 1
    if ordinal <= 403:
        first403[binary] += 1
expected = {
    'directional_surface_cell_authority_kernel_tests': 30,
    'directional_surface_cell_producer_tests': 262,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
expected403 = {
    'directional_surface_cell_authority_kernel_tests': 30,
    'directional_surface_cell_producer_tests': 257,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
if counts != expected:
    raise SystemExit(f'owner distribution drift: {counts!r}')
if first403 != expected403:
    raise SystemExit(f'accepted-prefix owner distribution drift: {first403!r}')
for ordinal, identity, binary, _ in rows[403:408]:
    if binary != 'directional_surface_cell_producer_tests':
        raise SystemExit(f'CP3 row not producer-owned: {ordinal}:{identity}:{binary}')
if rows[407][1] != 'RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity':
    raise SystemExit(f'row408 identity drift: {rows[407][1]}')
out.write_text('ordinal\tidentity\tbinary\tsource\n' + ''.join(
    f'{ordinal}\t{identity}\t{binary}\t{source}\n' for ordinal, identity, binary, source in rows))
dist_out.write_text('binary\tfull408\tfirst403\n' + ''.join(
    f'{t}\t{counts[t]}\t{first403[t]}\n' for t in target_names))
PY

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"

cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "staged binary mode mismatch: $exe"
done
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"

preflight_completed=true

postflight() {
  (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "${RESULT}/sha256sums-postflight.txt"
  [[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA256" ]] || fail_orchestration 'postflight package manifest digest mismatch'
  [[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'postflight source archive digest mismatch'
  [[ "$(sha_file "$selector403")" == "$EXPECTED_SELECTOR403_SHA256" ]] || fail_orchestration 'postflight selector403 digest mismatch'
  [[ "$(sha_file "$selector408")" == "$EXPECTED_SELECTOR408_SHA256" ]] || fail_orchestration 'postflight selector408 digest mismatch'
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'immutable package byte/mode census changed'
  if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then
    source_test_fixture_selector_mutation=true
    fail_orchestration 'immutable packaged source byte/mode census changed'
  fi
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'immutable execution-view byte/mode census changed'
  printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\n' | tee "${RESULT}/immutability.txt"
  postflight_completed=true
}

ledger="${RESULT}/process-ledger.tsv"
printf 'sequence\tphase\tordinal\tidentity\tbinary\texit\tselected\tok_lines\tskipped_lines\tclassification\traw_log\tresource_log\n' > "$ledger"

run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4"
  local seq=$((processes_executed + 1))
  local safe_phase stem raw_dir resource_dir work raw resource code selected ok_lines skipped_lines classification
  safe_phase="$(printf '%s' "$phase" | tr -c 'A-Za-z0-9._-' '-')"
  stem="seq-$(printf '%03d' "$seq")-ordinal-$(printf '%03d' "$ordinal")"
  raw_dir="${RESULT}/raw/${safe_phase}"
  resource_dir="${RESULT}/resources/${safe_phase}"
  work="${RUNTIME}/${safe_phase}/${stem}"
  raw="${raw_dir}/${stem}.log"
  resource="${resource_dir}/${stem}.time.txt"
  mkdir -p "$raw_dir" "$resource_dir" "$work"
  echo "${TURN_ID} sequence=${seq} phase=${phase} ordinal=${ordinal} identity=${identity} owner=${binary}"
  set +e
  (
    cd "$work"
    /usr/bin/time -v -o "$resource" \
      env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
      "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity" --gtest_color=no
  ) > "$raw" 2>&1
  code=$?
  set -e
  cat "$raw"
  selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
  ok_lines="$(grep -Ec '^\[       OK \] ' "$raw" || true)"
  skipped_lines="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"
  classification='RED'
  if [[ "$selected" -ne 1 ]]; then
    classification='SELECTION_MISMATCH'
    selection_integrity=false
    selection_mismatch_count=$((selection_mismatch_count + 1))
  elif [[ "$skipped_lines" -gt 0 ]]; then
    classification='SKIP'
    skip_count=$((skip_count + 1))
  elif [[ "$code" -ge 128 ]]; then
    classification='CRASH'
    crash_count=$((crash_count + 1))
  elif [[ "$code" -eq 0 && "$ok_lines" -eq 1 ]]; then
    classification='PASS'
    pass_count=$((pass_count + 1))
  else
    red_count=$((red_count + 1))
  fi
  processes_executed=$seq
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$seq" "$phase" "$ordinal" "$identity" "$binary" "$code" "$selected" "$ok_lines" "$skipped_lines" "$classification" \
    "raw/${safe_phase}/$(basename "$raw")" "resources/${safe_phase}/$(basename "$resource")" >> "$ledger"
  [[ "$classification" == 'PASS' ]]
}

map_identity() {
  local ordinal="$1"
  awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "${RESULT}/identity-map.tsv"
}

run_ordinal_census() {
  local phase="$1" ordinal="$2" expected_identity="${3:-}"
  local line identity binary classification
  line="$(map_identity "$ordinal")"
  identity="$(printf '%s\n' "$line" | cut -f2)"
  binary="$(printf '%s\n' "$line" | cut -f3)"
  [[ -n "$identity" && -n "$binary" ]] || fail_orchestration "missing routing at ordinal $ordinal"
  if [[ -n "$expected_identity" && "$identity" != "$expected_identity" ]]; then
    fail_orchestration "identity mismatch at ordinal $ordinal: $identity"
  fi
  if run_identity "$phase" "$ordinal" "$identity" "$binary"; then
    return 0
  fi
  classification="$(tail -n 1 "$ledger" | cut -f10)"
  case "$classification" in
    RED|SKIP)
      printf '%s\t%s\t%s\t%s\n' "$phase" "$ordinal" "$identity" "$classification" >> "${RESULT}/semantic-red-census.tsv"
      return 0
      ;;
    *)
      stop_kind="$classification"
      stop_phase="$phase"
      stop_ordinal="$ordinal"
      stop_identity="$identity"
      return 2
      ;;
  esac
}

runtime_started=true
stopped=false
printf 'phase\tordinal\tidentity\tclassification\n' > "${RESULT}/semantic-red-census.tsv"

for rep in A B; do
  for i in "${!SHARED_FOCUSED_ORDINALS[@]}"; do
    ordinal="${SHARED_FOCUSED_ORDINALS[$i]}"
    identity="${SHARED_FOCUSED_IDENTITIES[$i]}"
    if ! run_ordinal_census "A-shared-${rep}" "$ordinal" "$identity"; then stopped=true; break 2; fi
  done
done
if [[ "$stopped" == false ]] && ! run_ordinal_census 'B-ordinal138-A' 138 "$ORDINAL138_IDENTITY"; then stopped=true; fi
if [[ "$stopped" == false ]] && ! run_ordinal_census 'B-ordinal138-B' 138 "$ORDINAL138_IDENTITY"; then stopped=true; fi
if [[ "$stopped" == false ]] && ! run_ordinal_census 'C-row408-A' 408 "$ROW408_IDENTITY"; then stopped=true; fi
if [[ "$stopped" == false ]] && ! run_ordinal_census 'C-row408-B' 408 "$ROW408_IDENTITY"; then stopped=true; fi
if [[ "$stopped" == false ]]; then
  for rep in A B; do
    for ordinal in 404 405 406 407; do
      if ! run_ordinal_census "D-controls-${rep}" "$ordinal"; then stopped=true; break 2; fi
    done
  done
fi
if [[ "$stopped" == false ]]; then
  ordinal=0
  while IFS= read -r identity || [[ -n "$identity" ]]; do
    [[ -n "$identity" ]] || continue
    ordinal=$((ordinal + 1))
    line="$(map_identity "$ordinal")"
    mapped_identity="$(printf '%s\n' "$line" | cut -f2)"
    [[ "$mapped_identity" == "$identity" ]] || fail_orchestration "selector403/map mismatch at ordinal $ordinal"
    if ! run_ordinal_census 'E-selector403' "$ordinal" "$identity"; then stopped=true; break; fi
  done < "$selector403"
  [[ "$stopped" == true || "$ordinal" -eq 403 ]] || fail_orchestration 'selector403 did not enumerate 403 identities'
fi
if [[ "$stopped" == false ]]; then
  ordinal=0
  while IFS= read -r identity || [[ -n "$identity" ]]; do
    [[ -n "$identity" ]] || continue
    ordinal=$((ordinal + 1))
    line="$(map_identity "$ordinal")"
    mapped_identity="$(printf '%s\n' "$line" | cut -f2)"
    [[ "$mapped_identity" == "$identity" ]] || fail_orchestration "selector408/map mismatch at ordinal $ordinal"
    if ! run_ordinal_census 'F-selector408' "$ordinal" "$identity"; then stopped=true; break; fi
  done < "$selector408"
  [[ "$stopped" == true || "$ordinal" -eq 408 ]] || fail_orchestration 'selector408 did not enumerate 408 identities'
fi

if [[ "$stopped" == false ]]; then
  runtime_completed=true
fi

postflight

python3 - "$ledger" "${RESULT}/semantic-summary.txt" "$stop_kind" "$stop_phase" "$stop_ordinal" "$stop_identity" <<'PY'
import csv, pathlib, sys
rows = list(csv.DictReader(open(sys.argv[1]), delimiter='\t'))
counts = {}
for row in rows:
    counts[row['classification']] = counts.get(row['classification'], 0) + 1
phase_counts = {}
for row in rows:
    phase_counts[row['phase']] = phase_counts.get(row['phase'], 0) + 1
text = [
    f'processes_executed={len(rows)}',
    f'classifications={counts}',
    f'phase_counts={phase_counts}',
    f'stop_kind={sys.argv[3]}',
    f'stop_phase={sys.argv[4]}',
    f'stop_ordinal={sys.argv[5]}',
    f'stop_identity={sys.argv[6]}',
]
if len(rows) == 835:
    expected = {
        'A-shared-A': 6,
        'A-shared-B': 6,
        'B-ordinal138-A': 1,
        'B-ordinal138-B': 1,
        'C-row408-A': 1,
        'C-row408-B': 1,
        'D-controls-A': 4,
        'D-controls-B': 4,
        'E-selector403': 403,
        'F-selector408': 408,
    }
    if phase_counts != expected:
        raise SystemExit(f'full-ledger phase coverage mismatch: {phase_counts!r}')
pathlib.Path(sys.argv[2]).write_text('\n'.join(text) + '\n')
print('\n'.join(text))
PY
sha256sum "$ledger" > "${RESULT}/process-ledger.sha256"

if [[ "$selection_integrity" != true ]]; then
  orchestration_failure=true
  stop_kind='ORCHESTRATION_SELECTION_MISMATCH'
  exit 90
fi
if [[ "$stopped" == true ]]; then
  echo "${TURN_ID}_INCOMPLETE: ${stop_kind} at phase=${stop_phase} ordinal=${stop_ordinal} identity=${stop_identity}; processes=${processes_executed}; postflight complete."
  exit 2
fi
[[ "$processes_executed" -eq 835 ]] || fail_orchestration "complete process count mismatch: $processes_executed"
if [[ "$red_count" -gt 0 || "$skip_count" -gt 0 ]]; then
  echo "${TURN_ID}_COMPLETE_WITH_REDS: processes=${processes_executed}; pass=${pass_count}; red=${red_count}; skip=${skip_count}; accepted prefix fully censused; semantic interpretation deferred to M4-CP3-TB8-REV."
  exit 2
fi
[[ "$pass_count" -eq 835 ]] || fail_orchestration "green completion pass count mismatch: $pass_count"
echo "${TURN_ID}_COMPLETE: all 835 fresh exact-filter processes PASS; semantic interpretation deferred to M4-CP3-TB8-REV."
