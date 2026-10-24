#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"

CANDIDATE_ARTIFACT_ID=10595705100
ROUTING_ARTIFACT_ID=10592987234
EXPECTED_SOURCE_SHA='b98f461b9a392cc182891a81c0a84b0b01dfbb45'
EXPECTED_CANDIDATE_ZIP_SHA256='fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea'
EXPECTED_ROOT_MANIFEST_SHA256='8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d'
EXPECTED_SOURCE_ARCHIVE_SHA256='4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt'
EXPECTED_SELECTOR_COUNT=430
EXPECTED_SELECTOR_SHA256='1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6'
EXPECTED_SELECTOR427_SHA256='f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f'
EXPECTED_ROUTING_ZIP_SHA256='352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce'
EXPECTED_IDENTITY_MAP_SHA256='7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c'
EXPECTED_FOCUSED_COUNT=9
EXPECTED_BENCHMARK_COUNT=0

MODE="${1:-}"
case "$MODE" in
  --preflight-only|--execute) ;;
  *) echo "usage: $0 --preflight-only|--execute" >&2; exit 64 ;;
esac

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
CANDIDATE_ZIP="${ROOT}/candidate-${CANDIDATE_ARTIFACT_ID}.zip"
ROUTING_ZIP="${ROOT}/routing-${ROUTING_ARTIFACT_ID}.zip"
PKG="${ROOT}/package"
ROUTING="${ROOT}/routing"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
mkdir -p "$PKG" "$ROUTING" "$SOURCE" "$EXEC_VIEW/bin" "$RUNTIME" "$RESULT/raw/focused" "$RESULT/raw/selector" "$RESULT/resources/focused" "$RESULT/resources/selector"
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
    echo "orchestration_failure=${orchestration_failure}"
    echo "selection_integrity=${selection_integrity}"
    echo "focused_executed=${focused_executed}"
    echo "selector_executed=${selector_executed}"
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
  echo "routing_artifact_id=${ROUTING_ARTIFACT_ID}"
  echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"
  echo "selector_relative_path=${SELECTOR_RELATIVE_PATH}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  python3 --version
} | tee "${RESULT}/environment.txt"

download_artifact "$CANDIDATE_ARTIFACT_ID" "$EXPECTED_CANDIDATE_ZIP_SHA256" "$CANDIDATE_ZIP" "${RESULT}/candidate-artifact-authority.txt"
download_artifact "$ROUTING_ARTIFACT_ID" "$EXPECTED_ROUTING_ZIP_SHA256" "$ROUTING_ZIP" "${RESULT}/routing-artifact-authority.txt"

unzip -q "$CANDIDATE_ZIP" -d "$PKG"
unzip -q "$ROUTING_ZIP" -d "$ROUTING"

[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'candidate root SHA256SUMS absent'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_ROOT_MANIFEST_SHA256" ]] || fail_orchestration 'candidate root manifest digest mismatch'
manifest_log="${RESULT}/candidate-manifest-check.txt"
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$manifest_log"
[[ "$(grep -c ': OK$' "$manifest_log")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'candidate source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'candidate build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'candidate compile preflight exit nonzero'
for receipt in "$PKG"/metadata/source-status-*.txt; do
  [[ ! -s "$receipt" ]] || fail_orchestration "candidate source-status receipt is not clean: $(basename "$receipt")"
done
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing candidate command-boundary token: $token"
done
for token in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || fail_orchestration "missing candidate GMP evidence: $token"
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

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'candidate packaged source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'candidate packaged source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
[[ -f "$selector" ]] || fail_orchestration "selector absent: $SELECTOR_RELATIVE_PATH"

python3 - "$selector" "$EXPECTED_SELECTOR_COUNT" "$EXPECTED_SELECTOR_SHA256" "$EXPECTED_SELECTOR427_SHA256" "${RESULT}/selector-authority.txt" <<'PY'
import hashlib, pathlib, sys
path = pathlib.Path(sys.argv[1])
expected_count = int(sys.argv[2])
expected_sha = sys.argv[3]
expected_prefix_sha = sys.argv[4]
out = pathlib.Path(sys.argv[5])
data = path.read_bytes()
if b'\r' in data:
    raise SystemExit('selector contains CR bytes')
lines = data.splitlines(keepends=True)
if len(lines) != expected_count or any(not line.endswith(b'\n') for line in lines):
    raise SystemExit(f'selector is not exactly {expected_count} LF-terminated rows')
actual = hashlib.sha256(data).hexdigest()
prefix = hashlib.sha256(b''.join(lines[:427])).hexdigest()
if actual != expected_sha:
    raise SystemExit(f'selector digest mismatch: {actual}')
if prefix != expected_prefix_sha:
    raise SystemExit(f'selector427 prefix digest mismatch: {prefix}')
out.write_text(f'selector_rows={len(lines)}\nselector_sha256={actual}\nselector427_sha256={prefix}\n')
PY

identity_map="$ROUTING/identity-map.tsv"
[[ -f "$identity_map" ]] || fail_orchestration 'routing identity-map.tsv absent'
[[ "$(sha_file "$identity_map")" == "$EXPECTED_IDENTITY_MAP_SHA256" ]] || fail_orchestration 'routing identity-map digest mismatch'
python3 - "$identity_map" "$PKG" "${RESULT}/routing-authority.txt" <<'PY'
import collections, csv, pathlib, sys
path = pathlib.Path(sys.argv[1])
pkg = pathlib.Path(sys.argv[2])
out = pathlib.Path(sys.argv[3])
rows = list(csv.DictReader(path.open(), delimiter='\t'))
if path.read_text().splitlines()[0] != 'ordinal\tidentity\tbinary\tsource':
    raise SystemExit('routing header mismatch')
if len(rows) != 430:
    raise SystemExit(f'routing row count mismatch: {len(rows)}')
identities = [r['identity'] for r in rows]
if len(set(identities)) != 430:
    raise SystemExit('routing identities are not unique')
expected_ordinals = list(range(1, 431))
if [int(r['ordinal']) for r in rows] != expected_ordinals:
    raise SystemExit('routing ordinals are not exactly 1..430')
counts = collections.Counter(r['binary'] for r in rows)
expected = {
    'directional_surface_cell_authority_kernel_tests': 31,
    'directional_surface_cell_producer_tests': 283,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
if counts != expected:
    raise SystemExit(f'routing owner census mismatch: {dict(counts)!r}')
for binary in expected:
    p = pkg / 'bin' / binary
    if not p.is_file() or not (p.stat().st_mode & 0o111):
        raise SystemExit(f'routed executable absent or non-executable: {binary}')
out.write_text('routing_rows=430\nrouting_unique_identities=430\n' + ''.join(f'{k}={expected[k]}\n' for k in expected))
PY

focused_file="${RESULT}/focused-identities.txt"
cat > "$focused_file" <<'FOCUSED'
SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator
SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation
SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained
SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed
M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap
M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation
M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate
M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation
SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization
FOCUSED
[[ "$(wc -l < "$focused_file")" -eq "$EXPECTED_FOCUSED_COUNT" ]] || fail_orchestration 'focused identity count mismatch'

python3 - "$SOURCE" "$focused_file" "${RESULT}/focused-routing.tsv" "${RESULT}/cp1-source-audit.txt" <<'PY'
import pathlib, re, sys
root = pathlib.Path(sys.argv[1])
focused = [x.strip() for x in pathlib.Path(sys.argv[2]).read_text().splitlines() if x.strip()]
out = pathlib.Path(sys.argv[3])
audit_out = pathlib.Path(sys.argv[4])
cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
producer = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable', cmake, re.S)
if not producer:
    raise SystemExit('producer source set not found')
sources = [line.strip() for line in producer.group(1).splitlines() if line.strip().endswith('.cpp')]
pattern = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners = {}
for rel in sources:
    p = root / rel
    if not p.is_file():
        raise SystemExit(f'producer source absent: {rel}')
    for suite, name in pattern.findall(p.read_text(errors='replace')):
        owners.setdefault(f'{suite}.{name}', []).append(rel)
rows = []
for ordinal, identity in enumerate(focused, 1):
    found = owners.get(identity, [])
    if len(found) != 1:
        raise SystemExit(f'focused identity owner count {len(found)} for {identity}')
    rows.append((ordinal, identity, 'directional_surface_cell_producer_tests', found[0]))
bad = 'M4CP4.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization'
if owners.get(bad):
    raise SystemExit('superseded ninth focused identity still exists')
transition = (root / 'tests/SurfaceCellTransitionQuotientTests.cpp').read_text()
row9_anchor = 'TEST(SurfaceCellTransitionQuotient,\n     PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization)'
if row9_anchor not in transition:
    raise SystemExit('row9 exact test definition anchor absent')
row9_start = transition.index(row9_anchor)
row9_end = transition.find('\nTEST(', row9_start + len(row9_anchor))
row9_body = transition[row9_start:] if row9_end < 0 else transition[row9_start:row9_end]
for token in ('direct_periodic_owner_product()', 'ASSERT_EQ(2U, original.periodicHolonomies().size())', 'ASSERT_EQ(2U, original.edges().size())'):
    if token not in row9_body:
        raise SystemExit(f'row9 discriminator token absent: {token}')
production_text = ''
for base in ('src', 'include'):
    for p in sorted((root / base).rglob('*')):
        if p.is_file() and p.suffix in {'.cpp', '.h', '.hpp', '.cc'}:
            production_text += p.read_text(errors='replace') + '\n'
audit = {
    'production_PeriodicRelationId_from_index': len(re.findall(r'PeriodicRelationId\s*::\s*from_index\s*\(', production_text)),
    'production_periodicRelationOffset': len(re.findall(r'periodicRelationOffset', production_text)),
    'production_reachableHardRailComponents': len(re.findall(r'reachableHardRailComponents', production_text)),
    'production_hardRailAdjacency': len(re.findall(r'hardRailAdjacency', production_text)),
}
if audit['production_PeriodicRelationId_from_index'] != 0 or audit['production_periodicRelationOffset'] != 0 or audit['production_reachableHardRailComponents'] != 0 or audit['production_hardRailAdjacency'] != 0:
    raise SystemExit(f'CP1 source audit failed: {audit!r}')
if 'SelectedRelationPathCertificate' not in production_text:
    raise SystemExit('SelectedRelationPathCertificate absent from production source')
out.write_text('ordinal\tidentity\tbinary\tsource\n' + ''.join(f'{o}\t{i}\t{b}\t{s}\n' for o,i,b,s in rows))
audit_out.write_text(''.join(f'{k}={v}\n' for k,v in audit.items()) + 'SelectedRelationPathCertificate=present\nrow9_direct_helper_discriminator=present\n')
PY

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
  [[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector changed during execution'
  [[ "$(sha_file "$identity_map")" == "$EXPECTED_IDENTITY_MAP_SHA256" ]] || fail_orchestration 'routing identity map changed during execution'
  post_manifest="${RESULT}/candidate-manifest-check-after.txt"
  (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$post_manifest"
  [[ "$(grep -c ': OK$' "$post_manifest")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28 after execution'
  printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\nselector_unchanged=true\nrouting_map_unchanged=true\nmanifest_after=28/28\n' > "${RESULT}/immutability.txt"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  echo "${TURN_ID}_PREFLIGHT_COMPLETE: immutable artifacts, routing, focused identities, source audit, and execution view verified; no Directional runtime executed."
  exit 0
fi

run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4" ledger="$5"
  local phase_dir raw resource work code selected skipped passed result
  phase_dir="${phase,,}"
  raw="${RESULT}/raw/${phase_dir}/ordinal-$(printf '%03d' "$ordinal").log"
  resource="${RESULT}/resources/${phase_dir}/ordinal-$(printf '%03d' "$ordinal").time.txt"
  work="${RUNTIME}/${phase_dir}/ordinal-$(printf '%03d' "$ordinal")"
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
focused_ledger="${RESULT}/focused-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$focused_ledger"
while IFS=$'\t' read -r ordinal identity binary source; do
  [[ "$ordinal" == 'ordinal' ]] && continue
  run_identity focused "$ordinal" "$identity" "$binary" "$focused_ledger"
  focused_executed=$((focused_executed + 1))
done < "${RESULT}/focused-routing.tsv"
[[ "$focused_executed" -eq "$EXPECTED_FOCUSED_COUNT" ]] || fail_orchestration "focused execution count mismatch: ${focused_executed}"
sha256sum "$focused_ledger" > "${RESULT}/focused-ledger.sha256"

selector_ledger="${RESULT}/selector-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' > "$selector_ledger"
while IFS=$'\t' read -r ordinal identity binary source; do
  [[ "$ordinal" == 'ordinal' ]] && continue
  run_identity selector "$ordinal" "$identity" "$binary" "$selector_ledger"
  selector_executed=$((selector_executed + 1))
done < "$identity_map"
[[ "$selector_executed" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration "selector execution count mismatch: ${selector_executed}"
sha256sum "$selector_ledger" > "${RESULT}/selector-ledger.sha256"
runtime_completed=true

python3 - "$focused_ledger" "$selector_ledger" "${RESULT}/semantic-summary.txt" <<'PY'
import csv, pathlib, sys
focused = list(csv.DictReader(open(sys.argv[1]), delimiter='\t'))
selector = list(csv.DictReader(open(sys.argv[2]), delimiter='\t'))
out = pathlib.Path(sys.argv[3])
if len(focused) != 9 or [int(r['ordinal']) for r in focused] != list(range(1, 10)):
    raise SystemExit('focused ledger coverage mismatch')
if len(selector) != 430 or [int(r['ordinal']) for r in selector] != list(range(1, 431)):
    raise SystemExit('selector ledger coverage mismatch')
focused_red = [int(r['ordinal']) for r in focused if r['result'] != 'PASS']
selector_red = [int(r['ordinal']) for r in selector if r['result'] != 'PASS']
out.write_text(
    f'focused_total=9\nfocused_pass={9-len(focused_red)}\nfocused_red={len(focused_red)}\nfocused_red_ordinals={focused_red}\n'
    f'selector_total=430\nselector_pass={430-len(selector_red)}\nselector_red={len(selector_red)}\nselector_red_ordinals={selector_red}\n'
    'benchmark_execution=0\n'
)
PY
postflight

if [[ "$benchmark_execution" != false || "$EXPECTED_BENCHMARK_COUNT" -ne 0 ]]; then
  fail_orchestration 'benchmark execution boundary violated'
fi

echo "${TURN_ID}_COMPLETE: focused 9 plus selector430 artifact-only execution complete; semantic interpretation and promotion deferred to Review."
