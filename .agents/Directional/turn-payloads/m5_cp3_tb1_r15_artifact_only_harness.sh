#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"

CANDIDATE_ARTIFACT_ID=10742798135
ROUTING_ARTIFACT_ID=10592987234
EXPECTED_SOURCE_SHA='1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3'
EXPECTED_CANDIDATE_ZIP_SHA256='eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866'
EXPECTED_ROOT_MANIFEST_SHA256='a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951'
EXPECTED_SOURCE_ARCHIVE_SHA256='e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt'
EXPECTED_SELECTOR_COUNT=430
EXPECTED_SELECTOR_SHA256='1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6'
EXPECTED_SELECTOR427_SHA256='f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f'
EXPECTED_ROUTING_ZIP_SHA256='352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce'
EXPECTED_IDENTITY_MAP_SHA256='7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c'
EXPECTED_NONSEL_COUNT=18
EXPECTED_SELECTOR_PROCESS_COUNT=430
EXPECTED_TOTAL_PROCESS_COUNT=448
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
mkdir -p "$PKG" "$ROUTING" "$SOURCE" "$EXEC_VIEW/bin" "$RUNTIME"   "$RESULT/raw/nonselector" "$RESULT/raw/selector"   "$RESULT/resources/nonselector" "$RESULT/resources/selector"
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
nonselector_executed=0
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
nonselector_executed=${nonselector_executed}
selector_executed=${selector_executed}
total_executed=$((nonselector_executed + selector_executed))
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
  if [[ "$boundary_written" != true ]]; then write_boundary; fi
  echo "script_exit=${status}" >> "${RESULT}/execution-boundary.txt"
  echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" >> "$LOG"
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
import hashlib, os, pathlib, stat, sys
root = pathlib.Path(sys.argv[1]).resolve(); out = pathlib.Path(sys.argv[2])
rows=[]
for path in [root, *sorted(root.rglob('*'), key=lambda p:p.relative_to(root).as_posix())]:
    rel='.' if path==root else path.relative_to(root).as_posix(); st=path.lstat(); mode=format(stat.S_IMODE(st.st_mode),'o')
    if stat.S_ISREG(st.st_mode):
        h=hashlib.sha256()
        with path.open('rb') as f:
            for chunk in iter(lambda:f.read(1024*1024), b''): h.update(chunk)
        kind,digest,target='file',h.hexdigest(),'-'
    elif stat.S_ISDIR(st.st_mode): kind,digest,target='directory','-','-'
    elif stat.S_ISLNK(st.st_mode): kind,digest,target='symlink','-',os.readlink(path)
    else: kind,digest,target='other','-','-'
    rows.append(f'{rel}	{kind}	{mode}	{st.st_size}	{digest}	{target}
')
out.write_text(''.join(rows))
PY
}

download_artifact() {
  local artifact_id="$1" expected_zip_sha="$2" zip_path="$3" authority_path="$4"
  local artifact_json provider_digest downloaded_sha
  artifact_json="$(curl --fail --silent --show-error     -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json'     -H 'X-GitHub-Api-Version: 2022-11-28'     "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${artifact_id}")"
  provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
  [[ "$provider_digest" == "sha256:${expected_zip_sha}" ]] || fail_orchestration "provider digest mismatch for artifact ${artifact_id}: ${provider_digest}"
  curl -L --fail --silent --show-error     -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json'     -H 'X-GitHub-Api-Version: 2022-11-28'     "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${artifact_id}/zip" -o "$zip_path"
  downloaded_sha="$(sha_file "$zip_path")"
  [[ "$downloaded_sha" == "$expected_zip_sha" ]] || fail_orchestration "downloaded ZIP digest mismatch for artifact ${artifact_id}: ${downloaded_sha}"
  printf 'artifact_id=%s
provider_digest=%s
downloaded_zip_sha256=%s
' "$artifact_id" "$provider_digest" "$downloaded_sha" > "$authority_path"
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
} > "${RESULT}/environment.txt"

download_artifact "$CANDIDATE_ARTIFACT_ID" "$EXPECTED_CANDIDATE_ZIP_SHA256" "$CANDIDATE_ZIP" "${RESULT}/candidate-artifact-authority.txt"
download_artifact "$ROUTING_ARTIFACT_ID" "$EXPECTED_ROUTING_ZIP_SHA256" "$ROUTING_ZIP" "${RESULT}/routing-artifact-authority.txt"

unzip -q "$CANDIDATE_ZIP" -d "$PKG"
unzip -q "$ROUTING_ZIP" -d "$ROUTING"

[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'candidate root SHA256SUMS absent'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_ROOT_MANIFEST_SHA256" ]] || fail_orchestration 'candidate root manifest digest mismatch'
manifest_log="${RESULT}/candidate-manifest-check-before.txt"
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$manifest_log"
[[ "$(grep -c ': OK$' "$manifest_log")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'candidate source commit mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_orchestration 'candidate build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_orchestration 'candidate compile preflight exit nonzero'
for receipt in "$PKG"/metadata/source-status-*.txt; do [[ ! -s "$receipt" ]] || fail_orchestration "source-status receipt not clean: $(basename "$receipt")"; done
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing command-boundary token: $token"
done
for token in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || fail_orchestration "missing GMP evidence: $token"
done

required_executables=(directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests)
printf 'binary	sha256	mode	size
' > "${RESULT}/owner-executables.tsv"
for exe in "${required_executables[@]}"; do
  path="$PKG/bin/$exe"
  [[ -f "$path" && -x "$path" ]] || fail_orchestration "required executable absent or non-executable: $exe"
  printf '%s	%s	%s	%s
' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" >> "${RESULT}/owner-executables.tsv"
done
sha256sum "${RESULT}/owner-executables.tsv" > "${RESULT}/owner-executables.sha256"

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'packaged source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"
[[ -f "$selector" ]] || fail_orchestration "selector absent: $SELECTOR_RELATIVE_PATH"
identity_map="$ROUTING/identity-map.tsv"
[[ -f "$identity_map" ]] || fail_orchestration 'routing identity-map.tsv absent'
[[ "$(sha_file "$identity_map")" == "$EXPECTED_IDENTITY_MAP_SHA256" ]] || fail_orchestration 'routing identity-map digest mismatch'

python3 - "$selector" "$identity_map" "${RESULT}/selector-authority.txt" "${RESULT}/routing-authority.txt" <<'PY'
import collections,csv,hashlib,pathlib,sys
selector=pathlib.Path(sys.argv[1]); imap=pathlib.Path(sys.argv[2]); sout=pathlib.Path(sys.argv[3]); rout=pathlib.Path(sys.argv[4])
data=selector.read_bytes(); lines=data.splitlines(keepends=True)
if b'' in data or len(lines)!=430 or any(not x.endswith(b'
') for x in lines): raise SystemExit('selector byte/row contract mismatch')
sha=hashlib.sha256(data).hexdigest(); prefix=hashlib.sha256(b''.join(lines[:427])).hexdigest()
if sha!='1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6': raise SystemExit('selector430 digest mismatch')
if prefix!='f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f': raise SystemExit('selector427 prefix mismatch')
ids=[x.decode().rstrip('
') for x in lines]
rows=list(csv.DictReader(imap.open(), delimiter='	'))
if len(rows)!=430 or [int(r['ordinal']) for r in rows]!=list(range(1,431)): raise SystemExit('routing ordinal/count mismatch')
if [r['identity'] for r in rows]!=ids: raise SystemExit('routing identity sequence differs from selector430 bytes')
counts=collections.Counter(r['binary'] for r in rows)
expected={'directional_surface_cell_authority_kernel_tests':31,'directional_surface_cell_producer_tests':283,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
if counts!=expected: raise SystemExit(f'owner census mismatch: {dict(counts)}')
sout.write_text(f'selector_rows=430
selector_sha256={sha}
selector427_sha256={prefix}
')
rout.write_text('routing_rows=430
routing_sequence_equals_selector=true
'+''.join(f'{k}={expected[k]}
' for k in expected))
PY

nonselector="${RESULT}/nonselector-routing.tsv"
cat > "$nonselector" <<'ROWS'
ordinal	phase	identity	binary
1	mechanism	M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges	directional_surface_cell_producer_tests
2	mechanism	M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse	directional_surface_cell_producer_tests
3	mechanism	SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator	directional_surface_cell_producer_tests
4	mechanism	SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained	directional_surface_cell_producer_tests
5	mechanism	M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap	directional_surface_cell_producer_tests
6	mechanism	M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation	directional_surface_cell_producer_tests
7	mechanism	M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate	directional_surface_cell_producer_tests
8	mechanism	M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation	directional_surface_cell_producer_tests
9	mechanism	SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory	directional_surface_cell_producer_tests
10	mechanism	SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory	directional_surface_cell_producer_tests
11	mechanism	SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory	directional_surface_cell_producer_tests
12	atlas	FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency	directional_surface_cell_authority_kernel_tests
13	produced	M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges	directional_surface_cell_producer_tests
14	produced	M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate	directional_surface_cell_producer_tests
15	produced	M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped	directional_surface_cell_producer_tests
16	produced	M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes	directional_surface_cell_producer_tests
17	produced	M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped	directional_surface_cell_producer_tests
18	produced	M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate	directional_surface_cell_producer_tests
ROWS
[[ "$(($(wc -l < "$nonselector") - 1))" -eq "$EXPECTED_NONSEL_COUNT" ]] || fail_orchestration 'nonselector vector count mismatch'

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"
mkdir -p "$EXEC_VIEW/test-data/benchmarks"
cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do
  [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary digest mismatch: $exe"
  [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "execution-view binary mode mismatch: $exe"
done
[[ -f "$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'execution-view fixture tree incomplete'
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-before.tsv"
preflight_completed=true

postflight() {
  census_tree "$PKG" "${RESULT}/package-census-after.tsv"
  census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"
  census_tree "$EXEC_VIEW" "${RESULT}/execution-view-after.tsv"
  cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'immutable candidate package census changed'
  if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then source_test_fixture_selector_mutation=true; fail_orchestration 'immutable packaged source census changed'; fi
  cmp -s "${RESULT}/execution-view-before.tsv" "${RESULT}/execution-view-after.tsv" || fail_orchestration 'execution view census changed'
  [[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector changed during execution'
  [[ "$(sha_file "$identity_map")" == "$EXPECTED_IDENTITY_MAP_SHA256" ]] || fail_orchestration 'routing identity map changed during execution'
  post_manifest="${RESULT}/candidate-manifest-check-after.txt"
  (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$post_manifest"
  [[ "$(grep -c ': OK$' "$post_manifest")" -eq 28 ]] || fail_orchestration 'candidate root manifest did not verify 28/28 after execution'
  printf 'package_census_equal=true
source_census_equal=true
execution_view_census_equal=true
selector_unchanged=true
routing_map_unchanged=true
manifest_after=28/28
' > "${RESULT}/immutability.txt"
}

if [[ "$MODE" == '--preflight-only' ]]; then
  postflight
  write_boundary
  echo "${TURN_ID}_PREFLIGHT_COMPLETE"
  exit 0
fi

run_identity() {
  local phase="$1" ordinal="$2" identity="$3" binary="$4" ledger="$5" raw resource work code selected skipped passed result
  raw="${RESULT}/raw/${phase}/ordinal-$(printf '%03d' "$ordinal").log"
  resource="${RESULT}/resources/${phase}/ordinal-$(printf '%03d' "$ordinal").time.txt"
  work="${RUNTIME}/${phase}/ordinal-$(printf '%03d' "$ordinal")"
  mkdir -p "$work"
  set +e
  (cd "$work" && /usr/bin/time -v -o "$resource" env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw" 2>&1
  code=$?
  set -e
  selected="$(grep -Ec '^[ RUN      ] ' "$raw" || true)"
  skipped="$(grep -Ec '^[  SKIPPED ] ' "$raw" || true)"
  passed="$(grep -Ec '^[       OK ] ' "$raw" || true)"
  [[ "$selected" -eq 1 ]] || { selection_integrity=false; fail_orchestration "exact-one selection failed for ${identity}: ${selected}"; }
  [[ "$skipped" -eq 0 ]] || { selection_integrity=false; fail_orchestration "skip observed for ${identity}: ${skipped}"; }
  result=RED; [[ "$code" -eq 0 && "$passed" -eq 1 ]] && result=PASS
  printf '%s	%s	%s	%s	%s	%s	%s	%s	%s
' "$ordinal" "$identity" "$binary" "$code" "$selected" "$skipped" "$passed" "$result" "$(sha_file "$raw")" >> "$ledger"
}

runtime_started=true
nonselector_ledger="${RESULT}/nonselector-ledger.tsv"
printf 'ordinal	phase	identity	binary	exit	selected	skipped	passed	result	raw_sha256
' > "$nonselector_ledger"
while IFS=$'	' read -r ordinal phase identity binary; do
  [[ "$ordinal" == ordinal ]] && continue
  tmp="${RESULT}/.row"
  printf 'ordinal	identity	binary	exit	selected	skipped	passed	result	raw_sha256
' > "$tmp"
  run_identity nonselector "$ordinal" "$identity" "$binary" "$tmp"
  tail -n 1 "$tmp" | awk -F'	' -v p="$phase" 'BEGIN{OFS="	"}{print $1,p,$2,$3,$4,$5,$6,$7,$8,$9}' >> "$nonselector_ledger"
  rm -f "$tmp"
  nonselector_executed=$((nonselector_executed + 1))
done < "$nonselector"
[[ "$nonselector_executed" -eq "$EXPECTED_NONSEL_COUNT" ]] || fail_orchestration "nonselector execution count mismatch: $nonselector_executed"
sha256sum "$nonselector_ledger" > "${RESULT}/nonselector-ledger.sha256"

selector_ledger="${RESULT}/selector-ledger.tsv"
printf 'ordinal	identity	binary	exit	selected	skipped	passed	result	raw_sha256
' > "$selector_ledger"
while IFS=$'	' read -r ordinal identity binary source; do
  [[ "$ordinal" == ordinal ]] && continue
  run_identity selector "$ordinal" "$identity" "$binary" "$selector_ledger"
  selector_executed=$((selector_executed + 1))
done < "$identity_map"
[[ "$selector_executed" -eq "$EXPECTED_SELECTOR_PROCESS_COUNT" ]] || fail_orchestration "selector execution count mismatch: $selector_executed"
sha256sum "$selector_ledger" > "${RESULT}/selector-ledger.sha256"
runtime_completed=true

python3 - "$nonselector_ledger" "$selector_ledger" "${RESULT}/semantic-summary.txt" "${RESULT}/protected-selector.tsv" <<'PY'
import csv,pathlib,sys
non=list(csv.DictReader(open(sys.argv[1]),delimiter='	')); sel=list(csv.DictReader(open(sys.argv[2]),delimiter='	'))
out=pathlib.Path(sys.argv[3]); prot=pathlib.Path(sys.argv[4])
if len(non)!=18 or [int(r['ordinal']) for r in non]!=list(range(1,19)): raise SystemExit('nonselector ledger coverage mismatch')
if len(sel)!=430 or [int(r['ordinal']) for r in sel]!=list(range(1,431)): raise SystemExit('selector ledger coverage mismatch')
def stats(rows):
    red=[int(r['ordinal']) for r in rows if r['result']!='PASS']; return len(rows)-len(red),red
mp=[r for r in non if r['phase']=='mechanism']; at=[r for r in non if r['phase']=='atlas']; pr=[r for r in non if r['phase']=='produced']
mpass,mred=stats(mp); apass,ared=stats(at); ppass,pred=stats(pr); spass,sred=stats(sel)
out.write_text(
 f'mechanism_total=11
mechanism_pass={mpass}
mechanism_red={len(mred)}
mechanism_red_ordinals={mred}
'
 f'atlas_total=1
atlas_pass={apass}
atlas_red={len(ared)}
atlas_red_ordinals={ared}
'
 f'produced_total=6
produced_pass={ppass}
produced_red={len(pred)}
produced_red_ordinals={pred}
'
 f'selector_total=430
selector_pass={spass}
selector_red={len(sred)}
selector_red_ordinals={sred}
'
 f'total_processes=448
total_pass={mpass+apass+ppass+spass}
total_red={len(mred)+len(ared)+len(pred)+len(sred)}
benchmark_execution=0
')
protected={191,192,247,408}
prot.write_text('ordinal	identity	result	exit	raw_sha256
'+''.join(f"{r['ordinal']}	{r['identity']}	{r['result']}	{r['exit']}	{r['raw_sha256']}
" for r in sel if int(r['ordinal']) in protected))
PY

{
  echo 'produced_row4_process_ordinal=16'
  echo 'produced_row5_process_ordinal=17'
  for n in 16 17; do
    f="${RESULT}/raw/nonselector/ordinal-$(printf '%03d' "$n").log"
    echo "--- ordinal ${n} ---"
    grep -E 'Periodic|NonReciprocal|relation|Relation|Forward|Reverse|rotation|translation|gauge|branch|material|FAILED|Failure|Expected|Actual' "$f" || true
  done
} > "${RESULT}/produced-observations.txt"

postflight
[[ "$benchmark_execution" == false && "$EXPECTED_BENCHMARK_COUNT" -eq 0 ]] || fail_orchestration 'benchmark boundary violated'
[[ $((nonselector_executed + selector_executed)) -eq "$EXPECTED_TOTAL_PROCESS_COUNT" ]] || fail_orchestration 'total execution count mismatch'
write_boundary

manifest_tmp="${RUNNER_TEMP}/${SAFE_TURN_ID}-SHA256SUMS.tmp"
(
  cd "$RESULT"
  find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum
) > "$manifest_tmp"
manifest_rows="$(wc -l < "$manifest_tmp" | tr -d ' ')"
actual_nonmanifest="$(find "$RESULT" -type f ! -name SHA256SUMS | wc -l | tr -d ' ')"
[[ "$manifest_rows" -eq "$actual_nonmanifest" ]] || fail_orchestration "result manifest completeness mismatch rows=${manifest_rows} files=${actual_nonmanifest}"
mv "$manifest_tmp" "$RESULT/SHA256SUMS"
(cd "$RESULT" && sha256sum -c SHA256SUMS >/dev/null)

echo "${TURN_ID}_COMPLETE: 448 fresh exact-filter artifact-only processes complete; semantic interpretation deferred to Review."
