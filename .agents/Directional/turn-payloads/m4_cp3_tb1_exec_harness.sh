#!/usr/bin/env bash
set -euo pipefail

ARTIFACT_ID=10182447649
EXPECTED_ARTIFACT_NAME='m4-cp3-cb2-package118-result-34555543569'
EXPECTED_ZIP_SHA='1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5'
EXPECTED_PROVIDER_DIGEST="sha256:${EXPECTED_ZIP_SHA}"
EXPECTED_SOURCE_SHA='c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc'
EXPECTED_SELECTOR_SHA='6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68'
EXPECTED_PREFIX_SHA='1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f'
ROOT="${RUNNER_TEMP}/m4-cp3-tb1-exec"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${ROOT}/result"
ZIP="${ROOT}/package118.zip"
ACTIVITY="${RUNNER_TEMP}/m4-cp3-tb1-exec.log"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW" "$RUNTIME" "$RESULT/raw" "$RESULT/resources"
: > "$ACTIVITY"
exec > >(tee -a "$ACTIVITY") 2>&1

classification='MEASURED_GREEN'
first_failure=''
runtime_started=false
preflight_complete=false
postflight_complete=false

sha_file() { sha256sum "$1" | awk '{print $1}'; }
record_failure() {
  local kind="$1" msg="$2"
  if [[ -z "$first_failure" ]]; then first_failure="$kind: $msg"; fi
  if [[ "$kind" == ORCHESTRATION_FAILURE ]]; then
    classification='ORCHESTRATION_FAILURE'
  elif [[ "$classification" == MEASURED_GREEN ]]; then
    classification='SEMANTIC_RED'
  fi
  printf '%s\t%s\n' "$kind" "$msg" >> "$RESULT/failures.tsv"
}
fail_orchestration() { record_failure ORCHESTRATION_FAILURE "$1"; exit 2; }

census_tree() {
  local root="$1" out="$2"
  printf 'path\tmode\tbytes\tsha256\n' > "$out"
  while IFS= read -r -d '' f; do
    local rel="${f#${root}/}"
    printf '%s\t%s\t%s\t%s\n' "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha_file "$f")" >> "$out"
  done < <(find "$root" -type f -print0 | LC_ALL=C sort -z)
}

best_effort_postflight() {
  set +e
  if [[ -f "$RESULT/package-census-before.tsv" ]]; then census_tree "$PKG" "$RESULT/package-census-after.tsv"; fi
  if [[ -f "$RESULT/source-census-before.tsv" ]]; then census_tree "$SOURCE" "$RESULT/source-census-after.tsv"; fi
  if [[ -f "$RESULT/execution-view-census-before.tsv" ]]; then census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-after.tsv"; fi
  set -e
}
on_exit() {
  local rc=$?
  if [[ "$postflight_complete" != true ]]; then best_effort_postflight; fi
  printf '%s\n' "$rc" > "$RESULT/harness-exit-code.txt"
  {
    echo "classification=$classification"
    echo "first_failure=${first_failure:-none}"
    echo "runtime_started=$runtime_started"
    echo "preflight_complete=$preflight_complete"
    echo "postflight_complete=$postflight_complete"
    echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  } > "$RESULT/final-status.txt"
}
trap on_exit EXIT

{
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=${GITHUB_RUN_ID:-unknown}"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=${GITHUB_REPOSITORY}"
  echo "artifact_id=$ARTIFACT_ID"
  echo "expected_source_sha=$EXPECTED_SOURCE_SHA"
  echo 'turnBoundary=TB-EXEC'
  echo 'artifactOnly=true'
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  uname -a
  unzip -v | head -n 2
  tar --version | head -n 1
  python3 --version
  timeout --version | head -n 1
} | tee "$RESULT/environment.txt"

artifact_json="$(curl --fail --silent --show-error -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}")"
provider_digest="$(jq -r '.digest // ""' <<<"$artifact_json")"
artifact_name="$(jq -r '.name // ""' <<<"$artifact_json")"
[[ "$provider_digest" == "$EXPECTED_PROVIDER_DIGEST" ]] || fail_orchestration "provider digest mismatch: $provider_digest"
[[ "$artifact_name" == "$EXPECTED_ARTIFACT_NAME" ]] || fail_orchestration "artifact name mismatch: $artifact_name"
curl -L --fail --silent --show-error -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" -o "$ZIP"
zip_sha="$(sha_file "$ZIP")"
[[ "$zip_sha" == "$EXPECTED_ZIP_SHA" ]] || fail_orchestration "downloaded ZIP digest mismatch: $zip_sha"
printf 'artifact_id=%s\nartifact_name=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\nbyte_size=%s\n' "$ARTIFACT_ID" "$artifact_name" "$provider_digest" "$zip_sha" "$(stat -c '%s' "$ZIP")" | tee "$RESULT/artifact-authority.txt"

unzip -q "$ZIP" -d "$PKG"
[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'root SHA256SUMS absent'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$RESULT/manifest-preflight.txt" || fail_orchestration 'package manifest verification failed'
manifest_count="$(wc -l < "$PKG/SHA256SUMS")"
[[ "$manifest_count" -eq 28 ]] || fail_orchestration "manifest count $manifest_count != 28"
(cd "$PKG" && awk '{print $2}' SHA256SUMS | LC_ALL=C sort) > "$RESULT/manifest-paths.txt"
(cd "$PKG" && find . -type f ! -name SHA256SUMS -print | LC_ALL=C sort) > "$RESULT/actual-package-paths.txt"
cmp -s "$RESULT/manifest-paths.txt" "$RESULT/actual-package-paths.txt" || fail_orchestration 'manifest path set differs from package file set'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'source commit mismatch'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == 0 ]] || fail_orchestration 'compile preflight exit nonzero'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == 0 ]] || fail_orchestration 'build exit nonzero'
for token in runtimeExecution=false turnBoundary=Code+Build-only exactArithmeticBackend=GMP preflightCompile=true semanticContracts=compiled-not-executed manifestExcludesSelf=true buildLocation=runner-temp-out-of-tree; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing command-boundary token: $token"
done
grep -Fxq 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' "$PKG/metadata/CMakeCache.txt" || fail_orchestration 'DIRECTIONAL_ENABLE_GMP is not ON'
grep -Fq 'gmpxx' "$PKG/metadata/gmp-evidence.txt" || fail_orchestration 'gmpxx link evidence absent'
grep -Fq 'gmp' "$PKG/metadata/gmp-evidence.txt" || fail_orchestration 'gmp link evidence absent'
status_files=("$PKG"/metadata/source-status-*.txt)
[[ ${#status_files[@]} -gt 0 ]] || fail_orchestration 'source-status files absent'
for f in "${status_files[@]}"; do [[ ! -s "$f" ]] || fail_orchestration "nonempty source status: $(basename "$f")"; done
for exe in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do
  [[ -f "$PKG/bin/$exe" && -x "$PKG/bin/$exe" ]] || fail_orchestration "required executable absent/non-executable: $exe"
done
census_tree "$PKG" "$RESULT/package-census-before.tsv"

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
tar -xzf "$source_archive" -C "$SOURCE" || fail_orchestration 'source archive extraction failed'
census_tree "$SOURCE" "$RESULT/source-census-before.tsv"

set +e
python3 - "$SOURCE" "$RESULT/identity-map.tsv" "$RESULT/selector-authority.txt" <<'PY'
import collections, hashlib, pathlib, re, sys
root=pathlib.Path(sys.argv[1]); mapout=pathlib.Path(sys.argv[2]); report=pathlib.Path(sys.argv[3])
selp=root/'.agents/Directional/Architecture_M4_CP3_Required_Green_Selector_394.txt'; b=selp.read_bytes()
if b'\r' in b or not b.endswith(b'\n') or b.count(b'\n') != 394: raise SystemExit('selector394 LF row contract failed')
if hashlib.sha256(b).hexdigest() != '6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68': raise SystemExit('selector394 hash mismatch')
rows=b.decode().splitlines(); prefix=('\n'.join(rows[:382])+'\n').encode()
if hashlib.sha256(prefix).hexdigest() != '1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f': raise SystemExit('selector382 prefix hash mismatch')
if (root/'.agents/Directional/Architecture_M4_CP2_Required_Green_Selector_382.txt').read_bytes() != prefix: raise SystemExit('selector382 bytes differ from candidate prefix')
cmake=(root/'cmake/DirectionalTests.cmake').read_text()
targets={
'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],
'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cmake,re.S)
if not m: raise SystemExit('producer source set absent')
targets['directional_surface_cell_producer_tests']=[x.strip() for x in m.group(1).splitlines() if x.strip().endswith('.cpp')]
pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)'); owners={}
for target,files in targets.items():
  for rel in files:
    p=root/rel
    if not p.exists(): continue
    for suite,name in pat.findall(p.read_text(errors='replace')): owners.setdefault(f'{suite}.{name}',[]).append((target,rel))
records=[]; cand=collections.Counter(); pred=collections.Counter()
for i,identity in enumerate(rows,1):
  found=owners.get(identity,[])
  if len(found)!=1: raise SystemExit(f'identity static definition count {len(found)} at {i}:{identity}')
  target,rel=found[0]; records.append((i,identity,target,rel)); cand[target]+=1
  if i<=382: pred[target]+=1
expected_c={'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_producer_tests':248,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
expected_p={'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_producer_tests':236,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
if cand!=expected_c or pred!=expected_p: raise SystemExit(f'owner partition mismatch candidate={cand} predecessor={pred}')
mapout.write_text('ordinal\tidentity\tbinary\tsource\n'+''.join(f'{i}\t{x}\t{t}\t{r}\n' for i,x,t,r in records))
report.write_text('\n'.join(['selector394_rows=394','selector394_lf_sha256='+hashlib.sha256(b).hexdigest(),'selector382_prefix_rows=382','selector382_prefix_lf_sha256='+hashlib.sha256(prefix).hexdigest(),'candidate_owner_partition=30/248/75/41','predecessor_owner_partition=30/236/75/41','static_definition_count=1_for_every_selector_identity'])+'\n')
PY
selector_map_rc=$?
set -e
[[ "$selector_map_rc" -eq 0 ]] || fail_orchestration "selector/static-owner preflight failed rc=$selector_map_rc"
cat "$RESULT/selector-authority.txt"

mkdir -p "$EXEC_VIEW/bin" "$EXEC_VIEW/test-data/benchmarks"
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary mode mismatch: $exe"
done
census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-before.tsv"
preflight_complete=true

printf 'phase\tordinal\tidentity\tbinary\texit\trun_count\texact_run\tok_count\tfailed_count\tskipped_count\ttimeout\tverdict\traw_log\n' > "$RESULT/all-processes.tsv"
run_one() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4"
  local tag="${phase}-$(printf '%03d' "$ordinal")" raw="$RESULT/raw/${tag}.log" res="$RESULT/resources/${tag}.time.txt" work="$RUNTIME/$tag"
  mkdir -p "$work"
  printf 'phase=%s ordinal=%s identity=%s owner=%s command=%s --gtest_filter=%s\n' "$phase" "$ordinal" "$identity" "$binary" "$EXEC_VIEW/bin/$binary" "$identity" >> "$RESULT/commands.log"
  set +e
  (cd "$work" && /usr/bin/time -v -o "$res" timeout -k 5s 180s env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw" 2>&1
  local code=$?
  set -e
  local total exact ok failed skipped timeout_state=false verdict=RED
  total="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
  exact="$(grep -Fxc "[ RUN      ] $identity" "$raw" || true)"
  ok="$(grep -Fc "[       OK ] $identity" "$raw" || true)"
  failed="$(grep -Ec '^\[  FAILED  \]' "$raw" || true)"
  skipped="$(grep -Ec '^\[  SKIPPED \]' "$raw" || true)"
  [[ "$code" -eq 124 || "$code" -eq 137 ]] && timeout_state=true
  if [[ "$code" -eq 0 && "$total" -eq 1 && "$exact" -eq 1 && "$ok" -eq 1 && "$failed" -eq 0 && "$skipped" -eq 0 ]]; then verdict=PASS; fi
  if [[ "$total" -ne 1 || "$exact" -ne 1 ]]; then record_failure ORCHESTRATION_FAILURE "selection mismatch phase=$phase ordinal=$ordinal identity=$identity total=$total exact=$exact"; fi
  if [[ "$timeout_state" == true ]]; then record_failure ORCHESTRATION_FAILURE "timeout phase=$phase ordinal=$ordinal identity=$identity exit=$code"; fi
  if [[ "$verdict" == RED && "$total" -eq 1 && "$exact" -eq 1 && "$timeout_state" == false ]]; then record_failure SEMANTIC_RED "phase=$phase ordinal=$ordinal identity=$identity exit=$code"; fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$phase" "$ordinal" "$identity" "$binary" "$code" "$total" "$exact" "$ok" "$failed" "$skipped" "$timeout_state" "$verdict" "raw/$(basename "$raw")" >> "$RESULT/all-processes.tsv"
}
run_range() {
  local phase="$1" start="$2" end="$3" ledger="$RESULT/${phase}.tsv"
  printf 'ordinal\tidentity\tbinary\tverdict\n' > "$ledger"
  local ordinal
  for ((ordinal=start; ordinal<=end; ordinal++)); do
    local line identity binary verdict
    line="$(awk -F '\t' -v o="$ordinal" 'NR>1 && $1==o {print; exit}' "$RESULT/identity-map.tsv")"
    identity="$(cut -f2 <<<"$line")"; binary="$(cut -f3 <<<"$line")"
    [[ -n "$identity" && -n "$binary" ]] || fail_orchestration "missing identity map at ordinal $ordinal"
    runtime_started=true
    run_one "$phase" "$ordinal" "$identity" "$binary"
    verdict="$(tail -n 1 "$RESULT/all-processes.tsv" | cut -f12)"
    printf '%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$binary" "$verdict" >> "$ledger"
  done
}

run_range focused-a 383 394
run_range focused-b 383 394
cut -f4 "$RESULT/focused-a.tsv" | tail -n +2 > "$RESULT/focused-a.vector"
cut -f4 "$RESULT/focused-b.tsv" | tail -n +2 > "$RESULT/focused-b.vector"
cmp -s "$RESULT/focused-a.vector" "$RESULT/focused-b.vector" || record_failure SEMANTIC_RED 'focused-a/focused-b verdict vectors differ'
run_range predecessor382 1 382
run_range cumulative394 1 394

python3 - "$RESULT" <<'PY'
import csv,json,pathlib,sys,collections
r=pathlib.Path(sys.argv[1])
def load(name): return list(csv.DictReader((r/name).open(),delimiter='\t'))
fa,fb,p,c=map(load,['focused-a.tsv','focused-b.tsv','predecessor382.tsv','cumulative394.tsv'])
def s(rows):
  cnt=collections.Counter(x['verdict'] for x in rows); owners=collections.Counter(x['binary'] for x in rows)
  return {'rows':len(rows),'pass':cnt['PASS'],'red':cnt['RED'],'owners':dict(sorted(owners.items()))}
summary={'focused_a':s(fa),'focused_b':s(fb),'focused_vectors_equal':(r/'focused-a.vector').read_bytes()==(r/'focused-b.vector').read_bytes(),'predecessor382':s(p),'cumulative394':s(c)}
(r/'semantic-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n')
print(json.dumps(summary,indent=2,sort_keys=True))
PY

census_tree "$PKG" "$RESULT/package-census-after.tsv"
census_tree "$SOURCE" "$RESULT/source-census-after.tsv"
census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-after.tsv"
cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" || fail_orchestration 'package census changed'
cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" || fail_orchestration 'source census changed'
cmp -s "$RESULT/execution-view-census-before.tsv" "$RESULT/execution-view-census-after.tsv" || fail_orchestration 'execution-view census changed'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$RESULT/manifest-postflight.txt" || fail_orchestration 'postflight package manifest verification failed'
[[ "$(wc -l < "$RESULT/manifest-postflight.txt")" -eq 28 ]] || fail_orchestration 'postflight manifest count not 28'
postflight_complete=true

{
  echo 'artifactOnly=true'
  echo 'configureExecuted=false'
  echo 'compileExecuted=false'
  echo 'relinkExecuted=false'
  echo 'generatedDiscoveryExecuted=false'
  echo 'packageRepairExecuted=false'
  echo 'permissionRepairExecuted=false'
  echo 'sourceTestFixtureSelectorMutation=false'
  echo 'productionA3A4Cutover=false'
  echo 'packagePromotion=false'
} > "$RESULT/tb-command-boundary.txt"

summary_red="$(python3 - "$RESULT/semantic-summary.json" <<'PY'
import json,sys
x=json.load(open(sys.argv[1])); print(sum(x[k]['red'] for k in ['focused_a','focused_b','predecessor382','cumulative394']))
PY
)"
if [[ "$summary_red" -gt 0 && "$classification" == MEASURED_GREEN ]]; then record_failure SEMANTIC_RED "planned gates contain $summary_red RED process outcomes"; fi
if [[ "$classification" == MEASURED_GREEN ]]; then
  echo 'TB1_EXEC_COMPLETE: measured green; raw evidence only; package118 remains unpromoted; stop at M4-CP3-TB1-REV.'
  exit 0
elif [[ "$classification" == SEMANTIC_RED ]]; then
  echo 'TB1_EXEC_COMPLETE: semantic RED preserved; stop at M4-CP3-TB1-REV.'
  exit 1
else
  echo 'TB1_EXEC_COMPLETE: orchestration failure preserved; stop at M4-CP3-TB1-REV.'
  exit 2
fi
