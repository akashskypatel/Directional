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

ARTIFACT_ID=9921914679
EXPECTED_ARTIFACT_NAME='m3-cp4c3-cb25-package-result-33831662949'
EXPECTED_PROVIDER_DIGEST='sha256:db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7'
EXPECTED_ZIP_SHA='db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7'
EXPECTED_SOURCE_SHA='e12396d471c0754b112a40272a7992020ff49ced'
EXPECTED_365='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
EXPECTED_393='ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d'
EXPECTED_397='d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5'
EXPECTED_PACKAGE_CENSUS_SHA='9c7b12f4beba6f64e4ab1af3980554ba7b9f46af535ec2d2f2a9650f0359a927'
EXPECTED_SOURCE_CENSUS_SHA='e7bec1591154b4d9d79cd64ad27871305f54a51ba15946dc2042b55f6d2d8654'

ROOT="${RUNNER_TEMP}/m3-cp4c3-tb23-r1"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RESULT="${RUNNER_TEMP}/m3-cp4c3-tb23-r1-result"
LOG="${RUNNER_TEMP}/m3-cp4c3-tb23-r1.log"
ZIP="${ROOT}/artifact-9921914679.zip"
RUNTIME="${ROOT}/runtime"
mkdir -p "$ROOT" "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RESULT/raw" "$RUNTIME"
: > "$LOG"
exec > >(tee -a "$LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
execution_view_verified=false
orchestration_failure=false
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
  : > "$out"
  while IFS= read -r -d '' path; do
    rel="${path#"$root"/}"
    [[ "$path" == "$root" ]] && rel='.'
    mode="$(stat -c '%a' "$path")"
    type="$(stat -c '%F' "$path")"
    size="$(stat -c '%s' "$path")"
    digest='-'
    target='-'
    if [[ -f "$path" ]]; then digest="$(sha256sum "$path" | awk '{print $1}')"; fi
    if [[ -L "$path" ]]; then target="$(readlink "$path")"; fi
    printf '%s\t%s\t%s\t%s\t%s\t%s\n' "$rel" "$type" "$mode" "$size" "$digest" "$target" >> "$out"
  done < <(find "$root" -mindepth 0 -print0 | LC_ALL=C sort -z)
}

census_sha() {
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
  echo "harness_sha256=$(sha256sum "${BASH_SOURCE[0]}" | awk '{print $1}')"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  unzip -v | head -n 2
  tar --version | head -n 1
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
zip_sha="$(sha256sum "$ZIP" | awk '{print $1}')"
[[ "$zip_sha" == "$EXPECTED_ZIP_SHA" ]] || fail_orchestration "downloaded ZIP digest mismatch: $zip_sha"
printf 'artifact_id=%s\nartifact_name=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' \
  "$ARTIFACT_ID" "$artifact_name" "$provider_digest" "$zip_sha" \
  | tee "${RESULT}/artifact-authority.txt"

unzip -q "$ZIP" -d "$PKG"
(cd "$PKG"; sha256sum -c SHA256SUMS) | tee "${RESULT}/sha256sums-check.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'compile preflight exit nonzero'
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing command boundary: $token"
done
for token in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || fail_orchestration "missing GMP evidence: $token"
done
cat > "${ROOT}/expected-targets.txt" <<'TARGETS'
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
TARGETS
cmp -s "${ROOT}/expected-targets.txt" "$PKG/metadata/compiled-targets.txt" || fail_orchestration 'compiled targets mismatch'

required_executables=(
  directional_benchmarks
  directional_compiled_api_tests
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_validation_tests
)
for exe in "${required_executables[@]}"; do
  [[ -f "$PKG/bin/$exe" && -x "$PKG/bin/$exe" ]] || fail_orchestration "required executable mode absent: $exe"
  stat -c '%n mode=%a size=%s' "$PKG/bin/$exe"
done | tee "${RESULT}/executable-modes.txt"

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
package_census_before_sha="$(census_sha "${RESULT}/package-census-before.tsv")"
printf '%s  %s\n' "$package_census_before_sha" "${RESULT}/package-census-before.tsv" | tee "${RESULT}/package-census-before.sha256"
[[ "$package_census_before_sha" == "$EXPECTED_PACKAGE_CENSUS_SHA" ]] || fail_orchestration "package census authority mismatch: $package_census_before_sha"

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
tar -xzf "$source_archive" -C "$SOURCE"
[[ -f "$SOURCE/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'mechanical fixture missing from immutable packaged source'
[[ -f "$SOURCE/benchmarks/fixtures/milestone-g/sphere_prescribed.obj" ]] || fail_orchestration 'sphere fixture missing from immutable packaged source'

census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
source_census_before_sha="$(census_sha "${RESULT}/source-census-before.tsv")"
printf '%s  %s\n' "$source_census_before_sha" "${RESULT}/source-census-before.tsv" | tee "${RESULT}/source-census-before.sha256"
[[ "$source_census_before_sha" == "$EXPECTED_SOURCE_CENSUS_SHA" ]] || fail_orchestration "source census authority mismatch: $source_census_before_sha"

# CD1: construct an execution view outside both immutable trees. The binary path is
# <view>/bin/<exe>, so TestFixturePaths.h's first candidate is <view>/test-data.
mkdir -p "$EXEC_VIEW/bin" "$EXEC_VIEW/test-data/benchmarks"
for exe in "${required_executables[@]}"; do
  ln "$PKG/bin/$exe" "$EXEC_VIEW/bin/$exe" || fail_orchestration "cannot hard-link packaged binary into execution view: $exe"
  [[ "$(sha256sum "$PKG/bin/$exe" | awk '{print $1}')" == "$(sha256sum "$EXEC_VIEW/bin/$exe" | awk '{print $1}')" ]] \
    || fail_orchestration "staged binary digest mismatch: $exe"
done
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"

# CD2/CD3: reproduce the consumer's exact two-candidate rule without executing
# Directional runtime. Fail closed before runtime if no candidate contains the fixture tree.
probe_executable="$EXEC_VIEW/bin/directional_surface_cell_producer_tests"
probe_executable="$(realpath -e "$probe_executable")"
executable_directory="$(dirname "$probe_executable")"
sibling_candidate="$(dirname "$executable_directory")/test-data"
legacy_candidate="$executable_directory/test-data"
resolved_test_data=''
resolved_rule=''
if [[ -d "$sibling_candidate/benchmarks/fixtures" ]]; then
  resolved_test_data="$sibling_candidate"
  resolved_rule='sibling'
elif [[ -d "$legacy_candidate/benchmarks/fixtures" ]]; then
  resolved_test_data="$legacy_candidate"
  resolved_rule='legacy'
else
  fail_orchestration "consumer-resolution preflight found no test-data fixture tree: sibling=$sibling_candidate legacy=$legacy_candidate"
fi
[[ -f "$resolved_test_data/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'consumer-resolved mechanical fixture absent'
[[ -f "$resolved_test_data/benchmarks/fixtures/milestone-g/sphere_prescribed.obj" ]] || fail_orchestration 'consumer-resolved sphere fixture absent'
[[ "$resolved_rule" == 'sibling' ]] || fail_orchestration "unexpected consumer resolution rule: $resolved_rule"
execution_view_verified=true
{
  echo "binary_stage=hardlink"
  echo "fixture_stage=copy-from-immutable-packaged-source"
  echo "probe_executable=$probe_executable"
  echo "executable_directory=$executable_directory"
  echo "candidate_1_sibling=$sibling_candidate"
  echo "candidate_2_legacy=$legacy_candidate"
  echo "resolved_rule=$resolved_rule"
  echo "resolved_test_data=$resolved_test_data"
  echo "known_fixture=$resolved_test_data/benchmarks/fixtures/milestone-g/mechanical_feature.obj"
} | tee "${RESULT}/execution-view.txt"

# The frozen consumer rule itself must still match the rule classified by TB23-REV.
grep -Fq 'executableDirectory.parent_path() / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'sibling candidate rule drifted'
grep -Fq 'executableDirectory / "test-data"' "$SOURCE/tests/TestFixturePaths.h" || fail_orchestration 'legacy candidate rule drifted'

(cd "$SOURCE"; \
  python3 .agents/Directional/tools/selector_probe.py hash 365; \
  python3 .agents/Directional/tools/selector_probe.py hash 393; \
  python3 .agents/Directional/tools/selector_probe.py hash 397; \
  python3 .agents/Directional/tools/selector_probe.py prefix 365 397; \
  python3 .agents/Directional/tools/selector_probe.py prefix 393 397) \
  | tee "${RESULT}/selector-probe.txt"
grep -Fq "$EXPECTED_365" "${RESULT}/selector-probe.txt" || fail_orchestration 'selector 365 hash mismatch'
grep -Fq "$EXPECTED_393" "${RESULT}/selector-probe.txt" || fail_orchestration 'selector 393 hash mismatch'
grep -Fq "$EXPECTED_397" "${RESULT}/selector-probe.txt" || fail_orchestration 'selector 397 hash mismatch'
[[ "$(grep -Fc 'exact prefix' "${RESULT}/selector-probe.txt")" -eq 2 ]] || fail_orchestration 'selector prefix proof missing'

python3 - "$SOURCE" "${RESULT}/identity-map.tsv" <<'PY'
import hashlib
import pathlib
import re
import sys

root = pathlib.Path(sys.argv[1])
out = pathlib.Path(sys.argv[2])
selector = (root / '.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_397.txt').read_text().splitlines()
cm = (root / 'cmake/DirectionalTests.cmake').read_text()
targets = {
    'directional_compiled_api_tests': ['tests/CompiledLibraryTests.cpp'],
    'directional_surface_cell_producer_tests': [],
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
m = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable', cm, re.S)
if not m:
    raise SystemExit('producer source set not found')
for line in m.group(1).splitlines():
    source = line.strip()
    if source.endswith('.cpp'):
        targets['directional_surface_cell_producer_tests'].append(source)
pattern = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners = {}
for target, files in targets.items():
    for relative in files:
        for suite, name in pattern.findall((root / relative).read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}', []).append((target, relative))
rows = []
for ordinal, identity in enumerate(selector, 1):
    found = owners.get(identity, [])
    if len(found) != 1:
        raise SystemExit(f'identity owner count {len(found)} for {ordinal}:{identity}')
    rows.append((ordinal, identity, *found[0]))
out.write_text(
    'ordinal\tidentity\tbinary\tsource\n'
    + ''.join(f'{ordinal}\t{identity}\t{binary}\t{source}\n' for ordinal, identity, binary, source in rows)
)
print(f'identity_count={len(rows)}')
print('identity_map_sha256=' + hashlib.sha256(out.read_bytes()).hexdigest())
PY
[[ "$(($(wc -l < "${RESULT}/identity-map.tsv") - 1))" -eq 397 ]] || fail_orchestration 'identity map count mismatch'
sha256sum "${RESULT}/identity-map.tsv" | tee "${RESULT}/identity-map.sha256"

census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
sha256sum "${RESULT}/execution-view-before.tsv" | tee "${RESULT}/execution-view-before.sha256"
preflight_completed=true

if [[ "$MODE" == '--preflight-only' ]]; then
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  [[ "$(census_sha "${RESULT}/package-census-after.tsv")" == "$EXPECTED_PACKAGE_CENSUS_SHA" ]] || fail_orchestration 'package changed during preflight'
  [[ "$(census_sha "${RESULT}/source-census-after.tsv")" == "$EXPECTED_SOURCE_CENSUS_SHA" ]] || fail_orchestration 'source changed during preflight'
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view changed during preflight'
  echo 'package_census_equal=true' | tee "${RESULT}/package-immutability.txt"
  echo 'source_census_equal=true' | tee "${RESULT}/source-immutability.txt"
  echo 'execution_view_census_equal=true' | tee "${RESULT}/execution-view-immutability.txt"
  echo 'CB26_PREFLIGHT_COMPLETE: execution view verified; no Directional runtime executed.'
  exit 0
fi

echo -e 'ordinal\tidentity\tbinary\texit\tselected\tresult\traw_log' > "${RESULT}/ledger.tsv"
runtime_started=true
selector="$SOURCE/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_397.txt"
while IFS= read -r identity || [[ -n "$identity" ]]; do
  ordinal="$(grep -F -n -x "$identity" "$selector" | cut -d: -f1)"
  [[ -n "$ordinal" ]] || fail_orchestration "ordinal not found for identity $identity"
  map_line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "${RESULT}/identity-map.tsv")"
  binary="$(printf '%s\n' "$map_line" | cut -f3)"
  [[ -n "$binary" ]] || fail_orchestration "owner missing for ordinal $ordinal"
  raw="${RESULT}/raw/ordinal-$(printf '%03d' "$ordinal").log"
  work="${RUNTIME}/ordinal-$(printf '%03d' "$ordinal")"
  mkdir -p "$work"
  echo "TB23_R1 ordinal=$ordinal identity=$identity owner=$binary"
  set +e
  (cd "$work" && "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw" 2>&1
  code=$?
  set -e
  cat "$raw"
  selected=1
  if ! grep -Eq '\[==========\] Running 1 test|\[ RUN      \] ' "$raw"; then selected=0; fi
  [[ "$selected" -eq 1 ]] || fail_orchestration "zero/non-single selection at ordinal $ordinal"
  result=RED
  [[ "$code" -eq 0 ]] && result=PASS
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$code" "$selected" "$result" "raw/$(basename "$raw")" \
    >> "${RESULT}/ledger.tsv"
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
if len(rows) != 397:
    raise SystemExit(f'incomplete ledger: {len(rows)}')
red = [int(row['ordinal']) for row in rows if row['result'] == 'RED']
passed = sum(row['result'] == 'PASS' for row in rows)
accepted = sum(row['result'] == 'PASS' for row in rows if int(row['ordinal']) <= 365)
new397 = {int(row['ordinal']): row['result'] for row in rows if 394 <= int(row['ordinal']) <= 397}
text = (
    'total=397\n'
    f'pass={passed}\n'
    f'red={len(red)}\n'
    f'red_ordinals={red}\n'
    f'accepted_prefix_pass={accepted}/365\n'
    f'new_394_397={new397}\n'
    f'expected_red_ordinals_match={red == [366, 367, 368, 369, 370, 374]}\n'
    f'ledger_sha256={hashlib.sha256(ledger.read_bytes()).hexdigest()}\n'
)
summary.write_text(text)
print(text, end='')
PY
sha256sum "${RESULT}/ledger.tsv" | tee "${RESULT}/ledger.sha256"
grep -F 'UncutFaceComponentOrbitSeedNotUnique' "${RESULT}/raw/ordinal-366.log" > "${RESULT}/d2-production-locus.txt" || true
grep -E '^m3Cp4c3CA[234];' "${RESULT}/raw/ordinal-393.log" > "${RESULT}/d3-d5-certificate-diagnostics.txt" || true
{
  echo "d2_has_detail=$(grep -Fc 'UncutFaceComponentOrbitSeedNotUnique' "${RESULT}/raw/ordinal-366.log")"
  echo "d2_component0=$(grep -Fc 'uncutFaceComponent=0' "${RESULT}/raw/ordinal-366.log")"
  echo "d2_seed_multiple=$(grep -Fc 'uncutFaceComponentSeedState=Multiple' "${RESULT}/raw/ordinal-366.log")"
  echo "d2_face_count_191=$(grep -Fc 'uncutFaceComponentFaceCount=191' "${RESULT}/raw/ordinal-366.log")"
  echo "d2_seed_orbits_013=$(grep -Fc 'seedOrbits=[0,1,3]' "${RESULT}/raw/ordinal-366.log")"
  echo "ca2_rows=$(grep -Ec '^m3Cp4c3CA2;' "${RESULT}/raw/ordinal-393.log" || true)"
  echo "ca3_rows=$(grep -Ec '^m3Cp4c3CA3;' "${RESULT}/raw/ordinal-393.log" || true)"
  echo "ca4_rows=$(grep -Ec '^m3Cp4c3CA4;' "${RESULT}/raw/ordinal-393.log" || true)"
} | tee "${RESULT}/discriminator-presence.txt"

census_tree "$PKG" "${RESULT}/package-census-after.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
[[ "$(census_sha "${RESULT}/package-census-after.tsv")" == "$EXPECTED_PACKAGE_CENSUS_SHA" ]] || fail_orchestration 'immutable package byte/mode census changed'
if [[ "$(census_sha "${RESULT}/source-census-after.tsv")" == "$EXPECTED_SOURCE_CENSUS_SHA" ]]; then
  echo 'source_census_equal=true' | tee "${RESULT}/source-immutability.txt"
else
  source_test_fixture_selector_mutation=true
  fail_orchestration 'immutable packaged source byte/mode census changed'
fi
cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view byte/mode census changed'
echo 'package_census_equal=true' | tee "${RESULT}/package-immutability.txt"
echo 'execution_view_census_equal=true' | tee "${RESULT}/execution-view-immutability.txt"
echo 'TB23_R1_COMPLETE: immutable execution and evidence preservation complete; review deferred to TB23-R1-REV.'
