#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${RUNNER_TEMP:?}"
: "${TB2_LOG:?}"

TURN_ID='M4-CP4-TB2-R1-EXEC'
CB4_ARTIFACT_ID='10578784752'
CB5_ARTIFACT_ID='10582435470'
CB4_ZIP_SHA256='d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a'
CB5_ZIP_SHA256='3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3'
CB4_SOURCE_SHA='c2224f6af6a4fab47b928c1a0cd2fad677b87b9a'
CB5_SOURCE_SHA='4e9ff5003c8dd165dd614c25dd95f0308403719b'
CB4_SOURCE_TAR_SHA256='dd7dd3351ad3ea10f56ef9ce2021fc8ea84e10d682560b93f70ca1d79b089175'
CB5_SOURCE_TAR_SHA256='b904ba5fec938d74d432501396f94de0c015072de6d9009c6213e6d547c19c81'
CB4_MANIFEST_SHA256='8d3c8902504ed6ef4f09f26329fcf7bddeeaa3fff9c023772c5f7e81abcb33b2'
CB5_MANIFEST_SHA256='f5239fa4cb8fb31551599d6f836ca16e44ab203056dc262eb5c26141ed62d270'
SELECTOR_REL='.agents/Directional/Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt'
SELECTOR_SHA256='f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f'
SELECTOR_ROWS=427
SELECTOR_BYTES=34783

ROOT="${RUNNER_TEMP}/${TURN_ID}"
CB4_ZIP="${ROOT}/artifact-${CB4_ARTIFACT_ID}.zip"
CB5_ZIP="${ROOT}/artifact-${CB5_ARTIFACT_ID}.zip"
CB4_PKG="${ROOT}/cb4-package"
CB5_PKG="${ROOT}/cb5-package"
CB4_SRC="${ROOT}/cb4-source"
CB5_SRC="${ROOT}/cb5-source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${RUNNER_TEMP}/${TURN_ID}-result"
mkdir -p "$ROOT" "$CB4_PKG" "$CB5_PKG" "$CB4_SRC" "$CB5_SRC" \
  "$EXEC_VIEW/bin" "$RESULT/raw/focus" "$RESULT/raw/selector" \
  "$RUNTIME/focus" "$RUNTIME/selector"
exec > >(tee -a "$TB2_LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
postflight_complete=false
orchestration_failure=false
semantic_non_green=false
selection_integrity=true
benchmark_execution_count=0
configure_execution_count=0
compile_execution_count=0
relink_execution_count=0
generated_discovery_count=0
repair_count=0
package_repair_count=0
mode_repair_count=0
source_mutation_count=0
test_mutation_count=0
fixture_mutation_count=0
selector_mutation_count=0
first_semantic_red=''
orchestration_reason=''
focus_executed=0
selector_executed=0

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

write_result_manifest() {
  (cd "$RESULT" && find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS)
}

finish() {
  status=$?
  set +e
  trap - EXIT
  if [[ "$status" -ne 0 && "$orchestration_failure" == false ]]; then
    orchestration_failure=true
    orchestration_reason="unexpected_harness_exit_${status}"
    status=90
  fi
  if [[ "$runtime_started" == true && "$postflight_complete" == false ]]; then
    orchestration_failure=true
    if [[ -z "$orchestration_reason" ]]; then orchestration_reason='runtime_postflight_incomplete'; fi
    status=90
  fi
  {
    echo "script_exit=${status}"
    echo "turn_id=${TURN_ID}"
    echo "runtime_started=${runtime_started}"
    echo "runtime_completed=${runtime_completed}"
    echo "preflight_completed=${preflight_completed}"
    echo "postflight_complete=${postflight_complete}"
    echo "orchestration_failure=${orchestration_failure}"
    echo "semantic_non_green=${semantic_non_green}"
    echo "selection_integrity=${selection_integrity}"
    echo "first_semantic_red=${first_semantic_red}"
    echo "orchestration_reason=${orchestration_reason}"
    echo "focus_executed=${focus_executed}"
    echo "selector_executed=${selector_executed}"
    echo "benchmark_execution_count=${benchmark_execution_count}"
    echo "configure_execution_count=${configure_execution_count}"
    echo "compile_execution_count=${compile_execution_count}"
    echo "relink_execution_count=${relink_execution_count}"
    echo "generated_discovery_count=${generated_discovery_count}"
    echo "repair_count=${repair_count}"
    echo "package_repair_count=${package_repair_count}"
    echo "mode_repair_count=${mode_repair_count}"
    echo "source_mutation_count=${source_mutation_count}"
    echo "test_mutation_count=${test_mutation_count}"
    echo "fixture_mutation_count=${fixture_mutation_count}"
    echo "selector_mutation_count=${selector_mutation_count}"
    echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  } > "$RESULT/execution-boundary.txt"
  if ! write_result_manifest; then
    orchestration_failure=true
    if [[ -z "$orchestration_reason" ]]; then orchestration_reason='result_manifest_write_failed'; fi
    status=90
    {
      echo "script_exit=${status}"
      echo "turn_id=${TURN_ID}"
      echo "runtime_started=${runtime_started}"
      echo "runtime_completed=${runtime_completed}"
      echo "preflight_completed=${preflight_completed}"
      echo "postflight_complete=${postflight_complete}"
      echo "orchestration_failure=${orchestration_failure}"
      echo "semantic_non_green=${semantic_non_green}"
      echo "selection_integrity=${selection_integrity}"
      echo "first_semantic_red=${first_semantic_red}"
      echo "orchestration_reason=${orchestration_reason}"
      echo "focus_executed=${focus_executed}"
      echo "selector_executed=${selector_executed}"
      echo "benchmark_execution_count=${benchmark_execution_count}"
      echo "configure_execution_count=${configure_execution_count}"
      echo "compile_execution_count=${compile_execution_count}"
      echo "relink_execution_count=${relink_execution_count}"
      echo "generated_discovery_count=${generated_discovery_count}"
      echo "repair_count=${repair_count}"
      echo "package_repair_count=${package_repair_count}"
      echo "mode_repair_count=${mode_repair_count}"
      echo "source_mutation_count=${source_mutation_count}"
      echo "test_mutation_count=${test_mutation_count}"
      echo "fixture_mutation_count=${fixture_mutation_count}"
      echo "selector_mutation_count=${selector_mutation_count}"
      echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
    } > "$RESULT/execution-boundary.txt"
    write_result_manifest || true
  fi
  echo "script_exit=${status} orchestration_failure=${orchestration_failure} semantic_non_green=${semantic_non_green} postflight_complete=${postflight_complete}"
  exit "$status"
}
trap finish EXIT

fail_orchestration() {
  orchestration_failure=true
  orchestration_reason="$*"
  echo "ORCHESTRATION_FAILURE: $*" >&2
  exit 90
}

mark_orchestration() {
  orchestration_failure=true
  if [[ -z "$orchestration_reason" ]]; then orchestration_reason="$*"; fi
  echo "ORCHESTRATION_FAILURE: $*" >&2
}

record_env() {
  {
    echo "turn_id=${TURN_ID}"
    echo "workflow=${GITHUB_WORKFLOW:-unknown}"
    echo "run_id=${GITHUB_RUN_ID}"
    echo "event=${GITHUB_EVENT_NAME:-unknown}"
    echo "event_sha=${GITHUB_SHA:-unknown}"
    echo "repository=${GITHUB_REPOSITORY}"
    echo "runner_os=${RUNNER_OS:-unknown}"
    echo "cb4_artifact_id=${CB4_ARTIFACT_ID}"
    echo "cb5_artifact_id=${CB5_ARTIFACT_ID}"
    echo "cb4_source_sha=${CB4_SOURCE_SHA}"
    echo "cb5_source_sha=${CB5_SOURCE_SHA}"
    echo "selector_relative_path=${SELECTOR_REL}"
    echo "selector_rows=${SELECTOR_ROWS}"
    echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
    echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
    uname -a
    python3 --version
    unzip -v | sed -n '1p'
  } > "$RESULT/environment.txt"
  cat "$RESULT/environment.txt"
}

fetch_artifact() {
  local id="$1" expected_zip="$2" zip="$3" authority_out="$4"
  local json provider_digest artifact_name
  json="$(curl --fail --silent --show-error \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${id}")"
  provider_digest="$(printf '%s' "$json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
  artifact_name="$(printf '%s' "$json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("name", ""))')"
  [[ "$provider_digest" == "sha256:${expected_zip}" ]] || fail_orchestration "artifact ${id} provider digest mismatch: ${provider_digest}"
  curl -L --fail --silent --show-error \
    -H "Authorization: Bearer ${GH_TOKEN}" \
    -H 'Accept: application/vnd.github+json' \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${id}/zip" \
    -o "$zip"
  local actual_zip
  actual_zip="$(sha_file "$zip")"
  [[ "$actual_zip" == "$expected_zip" ]] || fail_orchestration "artifact ${id} ZIP digest mismatch: ${actual_zip}"
  printf 'artifact_id=%s\nartifact_name=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' \
    "$id" "$artifact_name" "$provider_digest" "$actual_zip" > "$authority_out"
  cat "$authority_out"
}

verify_package() {
  local label="$1" pkg="$2" source_sha="$3" source_tar_sha="$4" manifest_count="$5"
  [[ -f "$pkg/SHA256SUMS" ]] || fail_orchestration "$label SHA256SUMS absent"
  [[ "$(wc -l < "$pkg/SHA256SUMS")" -eq "$manifest_count" ]] || fail_orchestration "$label manifest count mismatch"
  (cd "$pkg" && sha256sum -c SHA256SUMS) > "$RESULT/${label}-manifest-check-before.txt"
  [[ "$(grep -c ': OK$' "$RESULT/${label}-manifest-check-before.txt")" -eq "$manifest_count" ]] || fail_orchestration "$label manifest verification incomplete"
  [[ "$(cat "$pkg/metadata/source-commit.txt")" == "$source_sha" ]] || fail_orchestration "$label source commit mismatch"
  [[ "$(cat "$pkg/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration "$label build exit nonzero"
  [[ "$(cat "$pkg/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration "$label compile preflight exit nonzero"
  for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
    grep -Fxq "$token" "$pkg/metadata/command-boundary.txt" || fail_orchestration "$label missing command boundary: $token"
  done
  grep -Fq 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' "$pkg/metadata/CMakeCache.txt" || fail_orchestration "$label GMP option disabled"
  grep -Fq 'libgmpxx.so' "$pkg/metadata/gmp-evidence.txt" || fail_orchestration "$label missing GMPXX evidence"
  grep -Fq 'libgmp.so' "$pkg/metadata/gmp-evidence.txt" || fail_orchestration "$label missing GMP evidence"
  for receipt in "$pkg"/metadata/source-status-*.txt; do
    [[ ! -s "$receipt" ]] || fail_orchestration "$label dirty source receipt: $(basename "$receipt")"
  done
  local source_tar="$pkg/source/source-${source_sha}.tar.gz"
  [[ -f "$source_tar" ]] || fail_orchestration "$label source archive absent"
  [[ "$(sha_file "$source_tar")" == "$source_tar_sha" ]] || fail_orchestration "$label source archive digest mismatch"
  printf 'label=%s\nmanifest_count=%s\nmanifest_sha256=%s\nsource_sha=%s\nsource_tar_sha256=%s\n' \
    "$label" "$manifest_count" "$(sha_file "$pkg/SHA256SUMS")" "$source_sha" "$(sha_file "$source_tar")" \
    > "$RESULT/${label}-package-authority.txt"
}

record_env
fetch_artifact "$CB4_ARTIFACT_ID" "$CB4_ZIP_SHA256" "$CB4_ZIP" "$RESULT/cb4-artifact-authority.txt"
fetch_artifact "$CB5_ARTIFACT_ID" "$CB5_ZIP_SHA256" "$CB5_ZIP" "$RESULT/cb5-artifact-authority.txt"
unzip -q "$CB4_ZIP" -d "$CB4_PKG"
unzip -q "$CB5_ZIP" -d "$CB5_PKG"
verify_package cb4 "$CB4_PKG" "$CB4_SOURCE_SHA" "$CB4_SOURCE_TAR_SHA256" 28
verify_package cb5 "$CB5_PKG" "$CB5_SOURCE_SHA" "$CB5_SOURCE_TAR_SHA256" 24
[[ "$(sha_file "$CB4_PKG/SHA256SUMS")" == "$CB4_MANIFEST_SHA256" ]] || fail_orchestration 'CB4 manifest SHA-256 mismatch'
[[ "$(sha_file "$CB5_PKG/SHA256SUMS")" == "$CB5_MANIFEST_SHA256" ]] || fail_orchestration 'CB5 manifest SHA-256 mismatch'

census_tree "$CB4_PKG" "$RESULT/cb4-package-census-before.tsv"
census_tree "$CB5_PKG" "$RESULT/cb5-package-census-before.tsv"
tar -xzf "$CB4_PKG/source/source-${CB4_SOURCE_SHA}.tar.gz" -C "$CB4_SRC"
tar -xzf "$CB5_PKG/source/source-${CB5_SOURCE_SHA}.tar.gz" -C "$CB5_SRC"
census_tree "$CB4_SRC" "$RESULT/cb4-source-census-before.tsv"
census_tree "$CB5_SRC" "$RESULT/cb5-source-census-before.tsv"

python3 - "$CB4_SRC" "$CB5_SRC" "$RESULT/semantic-source-delta.tsv" <<'PY'
import hashlib, pathlib, sys
A, B = pathlib.Path(sys.argv[1]), pathlib.Path(sys.argv[2])
out = pathlib.Path(sys.argv[3])
roots = ['src', 'include', 'cmake', 'tests', 'benchmarks/fixtures']
def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()
def inventory(root, rel):
    base = root / rel
    return {p.relative_to(root).as_posix(): digest(p) for p in base.rglob('*') if p.is_file()}
diffs=[]
for rel in roots:
    a,b=inventory(A,rel),inventory(B,rel)
    for name in sorted(set(a)|set(b)):
        if a.get(name) != b.get(name): diffs.append((name,a.get(name,'-'),b.get(name,'-')))
expected = {
    'tests/FieldTransportAtlasTests.cpp',
    'tests/SurfaceComplexSimplificationPhase17Tests.cpp',
}
actual={d[0] for d in diffs}
if actual != expected:
    raise SystemExit(f'semantic source delta drift: {sorted(actual)!r}')
out.write_text('path\tcb4_sha256\tcb5_sha256\n'+''.join(f'{p}\t{a}\t{b}\n' for p,a,b in diffs))
print('semantic_source_delta_exact=true')
print('changed_paths=' + ','.join(sorted(actual)))
PY

selector="$CB5_SRC/$SELECTOR_REL"
[[ -f "$selector" ]] || fail_orchestration 'selector absent from CB5 packaged source'
[[ "$(wc -l < "$selector")" -eq "$SELECTOR_ROWS" ]] || fail_orchestration 'selector line count mismatch'
[[ "$(wc -c < "$selector")" -eq "$SELECTOR_BYTES" ]] || fail_orchestration 'selector byte count mismatch'
[[ "$(sha_file "$selector")" == "$SELECTOR_SHA256" ]] || fail_orchestration 'selector SHA-256 mismatch'
selector_pre_sha="$(sha_file "$selector")"
printf 'path=%s\nrows=%s\nbytes=%s\nsha256=%s\n' "$SELECTOR_REL" "$SELECTOR_ROWS" "$SELECTOR_BYTES" "$selector_pre_sha" > "$RESULT/selector-authority.txt"

python3 - "$CB5_SRC" "$selector" "$RESULT/identity-map.tsv" "$RESULT/owner-distribution.tsv" "$RESULT/focus-map.tsv" <<'PY'
import pathlib,re,sys
root=pathlib.Path(sys.argv[1])
selector_path=pathlib.Path(sys.argv[2])
out=pathlib.Path(sys.argv[3]); dist_out=pathlib.Path(sys.argv[4]); focus_out=pathlib.Path(sys.argv[5])
selector=[line.strip() for line in selector_path.read_text().splitlines() if line.strip()]
cmake=(root/'cmake/DirectionalTests.cmake').read_text()
targets_order=[
'directional_surface_cell_authority_kernel_tests',
'directional_surface_cell_producer_tests',
'directional_surface_cell_completion_tests',
'directional_surface_cell_validation_tests']
def cpp_lines(text): return [line.strip() for line in text.splitlines() if line.strip().endswith('.cpp')]
producer=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cmake,re.S)
if not producer: raise SystemExit('producer source set not found')
targets={'directional_surface_cell_producer_tests':cpp_lines(producer.group(1))}
for target in [t for t in targets_order if t!='directional_surface_cell_producer_tests']:
    m=re.search(r'add_executable\(\s*'+re.escape(target)+r'(.*?)\)\s*\n',cmake,re.S)
    if not m: raise SystemExit(f'target source block not found: {target}')
    targets[target]=cpp_lines(m.group(1))
pattern=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners={}
for target in targets_order:
    for relative in targets[target]:
        path=root/relative
        if not path.is_file(): raise SystemExit(f'owner source missing: {target}:{relative}')
        for suite,name in pattern.findall(path.read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}',[]).append((target,relative))
rows=[]; counts={t:0 for t in targets_order}
for ordinal,identity in enumerate(selector,1):
    found=owners.get(identity,[])
    if len(found)!=1: raise SystemExit(f'identity owner count {len(found)} for {ordinal}:{identity}')
    binary,source=found[0]
    rows.append((ordinal,identity,binary,source)); counts[binary]+=1
expected={
'directional_surface_cell_authority_kernel_tests':30,
'directional_surface_cell_producer_tests':281,
'directional_surface_cell_completion_tests':75,
'directional_surface_cell_validation_tests':41}
if counts!=expected: raise SystemExit(f'owner distribution drift: {counts!r}')
out.write_text('ordinal\tidentity\tbinary\tsource\n'+''.join(f'{o}\t{i}\t{b}\t{s}\n' for o,i,b,s in rows))
dist_out.write_text('binary\tcount\n'+''.join(f'{t}\t{counts[t]}\n' for t in targets_order))
focus=[
('M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated','directional_surface_cell_producer_tests'),
('M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle','directional_surface_cell_completion_tests'),
('M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder','directional_surface_cell_producer_tests'),
('M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection','directional_surface_cell_authority_kernel_tests')]
frows=[]
for ordinal,(identity,expected_owner) in enumerate(focus,1):
    found=owners.get(identity,[])
    if len(found)!=1: raise SystemExit(f'focus owner count {len(found)} for {identity}')
    owner,source=found[0]
    if owner!=expected_owner: raise SystemExit(f'focus owner drift for {identity}: {owner}')
    frows.append((ordinal,identity,owner,source))
focus_out.write_text('focus_ordinal\tidentity\tbinary\tsource\n'+''.join(f'{o}\t{i}\t{b}\t{s}\n' for o,i,b,s in frows))
print('identity_count=427')
print('missing=0 duplicate=0')
for t in targets_order: print(f'{t}={counts[t]}')
PY
[[ "$(($(wc -l < "$RESULT/identity-map.tsv") - 1))" -eq 427 ]] || fail_orchestration 'identity map count mismatch'
[[ "$(($(wc -l < "$RESULT/focus-map.tsv") - 1))" -eq 4 ]] || fail_orchestration 'focus map count mismatch'
cat "$RESULT/owner-distribution.tsv"
cat "$RESULT/focus-map.tsv"

# Immutable owner-origin map and composite execution view.
printf 'binary\tpackage\n' > "$RESULT/owner-package-map.tsv"
printf '%s\t%s\n' 'directional_surface_cell_authority_kernel_tests' 'cb5' >> "$RESULT/owner-package-map.tsv"
printf '%s\t%s\n' 'directional_surface_cell_producer_tests' 'cb4' >> "$RESULT/owner-package-map.tsv"
printf '%s\t%s\n' 'directional_surface_cell_completion_tests' 'cb5' >> "$RESULT/owner-package-map.tsv"
printf '%s\t%s\n' 'directional_surface_cell_validation_tests' 'cb4' >> "$RESULT/owner-package-map.tsv"

cp -a "$CB5_PKG/bin/directional_surface_cell_authority_kernel_tests" "$EXEC_VIEW/bin/"
cp -a "$CB4_PKG/bin/directional_surface_cell_producer_tests" "$EXEC_VIEW/bin/"
cp -a "$CB5_PKG/bin/directional_surface_cell_completion_tests" "$EXEC_VIEW/bin/"
cp -a "$CB4_PKG/bin/directional_surface_cell_validation_tests" "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$CB4_SRC/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"

while IFS=$'\t' read -r binary package; do
  [[ "$binary" == 'binary' ]] && continue
  if [[ "$package" == cb4 ]]; then src="$CB4_PKG/bin/$binary"; else src="$CB5_PKG/bin/$binary"; fi
  dst="$EXEC_VIEW/bin/$binary"
  [[ -f "$src" && -x "$src" ]] || fail_orchestration "required source owner executable absent/non-executable: $binary"
  [[ -f "$dst" && -x "$dst" ]] || fail_orchestration "composite owner executable absent/non-executable: $binary"
  [[ "$(stat -c '%a' "$src")" == '755' ]] || fail_orchestration "unexpected archived mode for $binary"
  [[ "$(sha_file "$src")" == "$(sha_file "$dst")" ]] || fail_orchestration "composite binary digest mismatch for $binary"
  [[ "$(stat -c '%a' "$src")" == "$(stat -c '%a' "$dst")" ]] || fail_orchestration "composite binary mode mismatch for $binary"
done < "$RESULT/owner-package-map.tsv"

grep -Fq 'executableDirectory.parent_path() / "test-data"' "$CB5_SRC/tests/TestFixturePaths.h" || fail_orchestration 'sibling TestFixturePaths rule drifted'
known_fixture="$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj"
[[ -f "$known_fixture" ]] || fail_orchestration 'known fixture absent from composite execution view'
census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-before.tsv"
preflight_completed=true

run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4" phase_ledger="$5" global_ordinal="$6"
  local raw="$RESULT/raw/$phase/ordinal-$(printf '%03d' "$ordinal").log"
  local work="$RUNTIME/$phase/ordinal-$(printf '%03d' "$ordinal")"
  local package
  package="$(awk -F '\t' -v b="$binary" 'NR>1 && $1==b {print $2; exit}' "$RESULT/owner-package-map.tsv")"
  [[ "$package" == cb4 || "$package" == cb5 ]] || { mark_orchestration "owner package unresolved for $binary"; return 0; }
  mkdir -p "$work"
  echo "${TURN_ID} phase=${phase} ordinal=${ordinal} identity=${identity} owner=${binary} package=${package}"
  local code selected skipped passed result classification rawsha
  if (
    cd "$work"
    env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
      "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
  ) >"$raw" 2>&1; then
    code=0
  else
    code=$?
  fi
  cat "$raw"
  selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
  skipped="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"
  passed="$(grep -Ec '^\[       OK \] ' "$raw" || true)"
  rawsha="$(sha_file "$raw")"
  result=RED
  classification=TEST_FAILURE

  if [[ "$selected" -ne 1 ]]; then
    selection_integrity=false
    result=INVALID
    classification=SELECTION_MISMATCH
    mark_orchestration "selection mismatch phase=${phase} ordinal=${ordinal} identity=${identity} selected=${selected}"
  elif [[ "$skipped" -ne 0 ]]; then
    selection_integrity=false
    result=INVALID
    classification=SKIP
    mark_orchestration "skip phase=${phase} ordinal=${ordinal} identity=${identity} skipped=${skipped}"
  elif [[ "$code" -eq 0 && "$passed" -eq 1 ]]; then
    result=PASS
    classification=PASS
  elif [[ "$code" -ge 128 ]]; then
    classification=CRASH
    semantic_non_green=true
  else
    semantic_non_green=true
  fi

  if [[ "$result" == RED && -z "$first_semantic_red" ]]; then
    first_semantic_red="${phase}:${ordinal}:${identity}:${classification}:exit=${code}:skipped=${skipped}"
  fi

  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$binary" "$package" "$code" "$selected" "$passed" "$skipped" "$result" "$classification" "raw/${phase}/$(basename "$raw")" >> "$phase_ledger"
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$global_ordinal" "$phase" "$ordinal" "$identity" "$binary" "$package" "$code" "$selected" "$passed" "$skipped" "$result" "$classification" "$rawsha" >> "$RESULT/process-ledger.tsv"
}

runtime_started=true
focus_ledger="$RESULT/focus-ledger.tsv"
printf 'ordinal\tidentity\tbinary\tpackage\texit\tselected\tpassed\tskipped\tresult\tclassification\traw_log\n' > "$focus_ledger"
printf 'global_ordinal\tphase\tphase_ordinal\tidentity\tbinary\tpackage\texit\tselected\tpassed\tskipped\tresult\tclassification\traw_log_sha256\n' > "$RESULT/process-ledger.tsv"
while IFS=$'\t' read -r ordinal identity binary source; do
  [[ "$ordinal" == 'focus_ordinal' ]] && continue
  run_identity focus "$ordinal" "$identity" "$binary" "$focus_ledger" "$ordinal"
  focus_executed=$((focus_executed + 1))
  [[ "$orchestration_failure" == false ]] || break
done < "$RESULT/focus-map.tsv"

selector_ledger="$RESULT/selector-ledger.tsv"
printf 'ordinal\tidentity\tbinary\tpackage\texit\tselected\tpassed\tskipped\tresult\tclassification\traw_log\n' > "$selector_ledger"
if [[ "$orchestration_failure" == false ]]; then
  ordinal=0
  while IFS= read -r identity || [[ -n "$identity" ]]; do
    [[ -n "$identity" ]] || continue
    ordinal=$((ordinal + 1))
    map_line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "$RESULT/identity-map.tsv")"
    mapped_identity="$(printf '%s\n' "$map_line" | cut -f2)"
    binary="$(printf '%s\n' "$map_line" | cut -f3)"
    if [[ "$mapped_identity" != "$identity" || -z "$binary" ]]; then
      mark_orchestration "identity-map mismatch at selector ordinal $ordinal"
      break
    fi
    run_identity selector "$ordinal" "$identity" "$binary" "$selector_ledger" "$((4 + ordinal))"
    selector_executed=$((selector_executed + 1))
    [[ "$orchestration_failure" == false ]] || break
  done < "$selector"
fi

if [[ "$orchestration_failure" == false ]]; then
  [[ "$focus_executed" -eq 4 ]] || mark_orchestration "focused execution count mismatch: $focus_executed"
  [[ "$selector_executed" -eq 427 ]] || mark_orchestration "selector execution count mismatch: $selector_executed"
  [[ "$(($(wc -l < "$RESULT/process-ledger.tsv") - 1))" -eq 431 ]] || mark_orchestration 'combined process ledger count mismatch'
fi
if [[ "$orchestration_failure" == false ]]; then runtime_completed=true; fi

python3 - "$focus_ledger" "$selector_ledger" "$RESULT/process-ledger.tsv" "$RESULT/semantic-summary.txt" <<'PY'
import csv,pathlib,sys
focus=list(csv.DictReader(open(sys.argv[1]),delimiter='\t'))
selector=list(csv.DictReader(open(sys.argv[2]),delimiter='\t'))
all_rows=list(csv.DictReader(open(sys.argv[3]),delimiter='\t'))
out=pathlib.Path(sys.argv[4])
fp=[r for r in focus if r['result']=='PASS']; fr=[r for r in focus if r['result']=='RED']
sp=[r for r in selector if r['result']=='PASS']; sr=[r for r in selector if r['result']=='RED']
invalid=[r for r in all_rows if r['result']=='INVALID']
from collections import Counter
owners=Counter(r['binary'] for r in selector if r['result']=='PASS')
text=(
 f'focus_executed={len(focus)}\nfocus_pass={len(fp)}\nfocus_red={len(fr)}\n'
 f'focus_red_identities={[r["identity"] for r in fr]}\n'
 f'selector_executed={len(selector)}\nselector_pass={len(sp)}\nselector_red={len(sr)}\n'
 f'selector_red_ordinals={[int(r["ordinal"]) for r in sr]}\n'
 f'process_ledger_rows={len(all_rows)}\ninvalid_rows={len(invalid)}\nbenchmark_count=0\n'
 f'selector_pass_owners={dict(owners)}\n'
)
out.write_text(text); print(text,end='')
PY

# Immutable postflight whenever runtime started. Continue collecting all checks even after an orchestration fault.
census_tree "$CB4_PKG" "$RESULT/cb4-package-census-after.tsv"
census_tree "$CB5_PKG" "$RESULT/cb5-package-census-after.tsv"
census_tree "$CB4_SRC" "$RESULT/cb4-source-census-after.tsv"
census_tree "$CB5_SRC" "$RESULT/cb5-source-census-after.tsv"
census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-after.tsv"
cmp -s "$RESULT/cb4-package-census-before.tsv" "$RESULT/cb4-package-census-after.tsv" || mark_orchestration 'CB4 package census changed'
cmp -s "$RESULT/cb5-package-census-before.tsv" "$RESULT/cb5-package-census-after.tsv" || mark_orchestration 'CB5 package census changed'
cmp -s "$RESULT/cb4-source-census-before.tsv" "$RESULT/cb4-source-census-after.tsv" || mark_orchestration 'CB4 packaged source census changed'
cmp -s "$RESULT/cb5-source-census-before.tsv" "$RESULT/cb5-source-census-after.tsv" || mark_orchestration 'CB5 packaged source census changed'
cmp -s "$RESULT/execution-view-census-before.tsv" "$RESULT/execution-view-census-after.tsv" || mark_orchestration 'composite execution-view census changed'
[[ "$(sha_file "$selector")" == "$selector_pre_sha" ]] || mark_orchestration 'selector changed during execution'
if ! (cd "$CB4_PKG" && sha256sum -c SHA256SUMS) > "$RESULT/cb4-manifest-check-after.txt"; then mark_orchestration 'CB4 postflight manifest verification failed'; fi
if ! (cd "$CB5_PKG" && sha256sum -c SHA256SUMS) > "$RESULT/cb5-manifest-check-after.txt"; then mark_orchestration 'CB5 postflight manifest verification failed'; fi
[[ "$(grep -c ': OK$' "$RESULT/cb4-manifest-check-after.txt")" -eq 28 ]] || mark_orchestration 'CB4 postflight manifest verification incomplete'
[[ "$(grep -c ': OK$' "$RESULT/cb5-manifest-check-after.txt")" -eq 24 ]] || mark_orchestration 'CB5 postflight manifest verification incomplete'
printf 'cb4_package_census_equal=%s\ncb5_package_census_equal=%s\ncb4_source_census_equal=%s\ncb5_source_census_equal=%s\nexecution_view_census_equal=%s\nselector_equal=%s\ncb4_manifest_reverified=%s\ncb5_manifest_reverified=%s\n' \
  "$(cmp -s "$RESULT/cb4-package-census-before.tsv" "$RESULT/cb4-package-census-after.tsv" && echo true || echo false)" \
  "$(cmp -s "$RESULT/cb5-package-census-before.tsv" "$RESULT/cb5-package-census-after.tsv" && echo true || echo false)" \
  "$(cmp -s "$RESULT/cb4-source-census-before.tsv" "$RESULT/cb4-source-census-after.tsv" && echo true || echo false)" \
  "$(cmp -s "$RESULT/cb5-source-census-before.tsv" "$RESULT/cb5-source-census-after.tsv" && echo true || echo false)" \
  "$(cmp -s "$RESULT/execution-view-census-before.tsv" "$RESULT/execution-view-census-after.tsv" && echo true || echo false)" \
  "$( [[ "$(sha_file "$selector")" == "$selector_pre_sha" ]] && echo true || echo false)" \
  "$( [[ "$(grep -c ': OK$' "$RESULT/cb4-manifest-check-after.txt")" -eq 28 ]] && echo true || echo false)" \
  "$( [[ "$(grep -c ': OK$' "$RESULT/cb5-manifest-check-after.txt")" -eq 24 ]] && echo true || echo false)" \
  > "$RESULT/immutability.txt"
postflight_complete=true

if [[ "$orchestration_failure" == true ]]; then
  echo "${TURN_ID}_ORCHESTRATION_FAILURE: ${orchestration_reason}" >&2
  exit 90
fi

echo "${TURN_ID}_COMPLETE: four focused processes plus selector427 complete; semantic result preserved for mandatory Review."
exit 0
