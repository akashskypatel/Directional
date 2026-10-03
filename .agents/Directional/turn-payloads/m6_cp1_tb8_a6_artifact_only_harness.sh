#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"

CANDIDATE_ARTIFACT_ID=11265967968
EXPECTED_SOURCE_SHA='8e0818b1e2f8d12b86c64d8774a3572c5ed5266c'
EXPECTED_CANDIDATE_ZIP_SHA256='022a35378a58463b892f1bf1d5113f726c2cc7cb8939892b24acd1da62259c4b'
EXPECTED_ROOT_MANIFEST_SHA256='8465269ab637b07a399b32e09fb812169a3c0564271c2e0998cab432fe010948'
EXPECTED_SOURCE_ARCHIVE_SHA256='7220c197eae6b69957b71d6136eb3fce2b6f875bdc3ed3a298537720fef00296'
SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt'
ROUTING_RELATIVE_PATH='.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv'
EXPECTED_SELECTOR_COUNT=449
EXPECTED_SELECTOR_SHA256='d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414'
EXPECTED_ROUTING_COUNT=449
EXPECTED_ROUTING_SHA256='9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707'
EXPECTED_FOCUSED_COUNT=12
EXPECTED_SELECTOR_PROCESS_COUNT=449
EXPECTED_TOTAL_PROCESS_COUNT=461
EXPECTED_BENCHMARK_COUNT=0

[[ "${1:-}" == '--execute' ]] || { echo "usage: $0 --execute" >&2; exit 64; }
SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
CANDIDATE_ZIP="${ROOT}/candidate-${CANDIDATE_ARTIFACT_ID}.zip"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RUNTIME="${ROOT}/runtime"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW/bin" "$RUNTIME" \
  "$RESULT/raw/focused" "$RESULT/raw/selector" \
  "$RESULT/resources/focused" "$RESULT/resources/selector"
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
focused_executed=0
selector_executed=0
boundary_written=false

write_boundary() {
  cat > "${RESULT}/execution-boundary.txt" <<BOUNDARY
turn_id=${TURN_ID}
runtime_started=${runtime_started}
runtime_completed=${runtime_completed}
preflight_completed=${preflight_completed}
orchestration_failure=${orchestration_failure}
selection_integrity=${selection_integrity}
focused_executed=${focused_executed}
selector_executed=${selector_executed}
total_executed=$((focused_executed + selector_executed))
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
  if [[ "${boundary_written:-false}" != true ]]; then
    write_boundary
    echo "script_exit=${status}" >> "${RESULT}/execution-boundary.txt"
  fi
  echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" >> "$LOG"
}
trap finish EXIT
fail_orchestration() { orchestration_failure=true; echo "ORCHESTRATION_FAILURE: $*" >&2; exit 90; }
sha_file() { sha256sum "$1" | awk '{print $1}'; }

census_tree() {
  local root="$1" out="$2"
  python3 - "$root" "$out" <<'PY'
import hashlib, os, pathlib, stat, sys
root=pathlib.Path(sys.argv[1]).resolve(); out=pathlib.Path(sys.argv[2]); rows=[]
for path in [root,*sorted(root.rglob('*'),key=lambda p:p.relative_to(root).as_posix())]:
    rel='.' if path==root else path.relative_to(root).as_posix(); st=path.lstat(); mode=format(stat.S_IMODE(st.st_mode),'o')
    if stat.S_ISREG(st.st_mode):
        h=hashlib.sha256();
        with path.open('rb') as f:
            for chunk in iter(lambda:f.read(1024*1024),b''): h.update(chunk)
        kind,digest,target='file',h.hexdigest(),'-'
    elif stat.S_ISDIR(st.st_mode): kind,digest,target='directory','-','-'
    elif stat.S_ISLNK(st.st_mode): kind,digest,target='symlink','-',os.readlink(path)
    else: kind,digest,target='other','-','-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{st.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows))
PY
}

download_artifact() {
  local artifact_json provider_digest downloaded_sha
  artifact_json="$(curl --fail --silent --show-error -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${CANDIDATE_ARTIFACT_ID}")"
  provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
  [[ "$provider_digest" == "sha256:${EXPECTED_CANDIDATE_ZIP_SHA256}" ]] || fail_orchestration "provider digest mismatch: ${provider_digest}"
  curl -L --fail --silent --show-error -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${CANDIDATE_ARTIFACT_ID}/zip" -o "$CANDIDATE_ZIP"
  downloaded_sha="$(sha_file "$CANDIDATE_ZIP")"
  [[ "$downloaded_sha" == "$EXPECTED_CANDIDATE_ZIP_SHA256" ]] || fail_orchestration "downloaded ZIP digest mismatch: ${downloaded_sha}"
  printf 'artifact_id=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' "$CANDIDATE_ARTIFACT_ID" "$provider_digest" "$downloaded_sha" > "${RESULT}/candidate-artifact-authority.txt"
}

{
 echo "turn_id=${TURN_ID}"; echo "workflow=${GITHUB_WORKFLOW:-unknown}"; echo "run_id=${GITHUB_RUN_ID}"; echo "event_sha=${GITHUB_SHA:-unknown}"; echo "candidate_artifact_id=${CANDIDATE_ARTIFACT_ID}"; echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"; echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"; echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"; uname -a; python3 --version; unzip -v | head -n1 || true; tar --version | head -n1 || true
} | tee "${RESULT}/environment.txt"

download_artifact
# Ordinary unzip preserves archived executable mode bits.
unzip -q "$CANDIDATE_ZIP" -d "$PKG"
[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'candidate root SHA256SUMS absent'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_ROOT_MANIFEST_SHA256" ]] || fail_orchestration 'root manifest digest mismatch'
manifest_log="${RESULT}/candidate-manifest-check-before.txt"
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$manifest_log"
[[ "$(grep -c ': OK$' "$manifest_log")" -eq 28 ]] || fail_orchestration 'candidate root manifest not 28/28'
[[ "$(wc -l < "$PKG/SHA256SUMS" | tr -d ' ')" -eq 28 ]] || fail_orchestration 'candidate root manifest row count mismatch'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_orchestration 'candidate source mismatch'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == 0 ]] || fail_orchestration 'candidate build exit nonzero'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == 0 ]] || fail_orchestration 'candidate preflight exit nonzero'
for receipt in "$PKG"/metadata/source-status-*.txt; do [[ ! -s "$receipt" ]] || fail_orchestration "dirty source receipt $(basename "$receipt")"; done
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_orchestration "missing boundary token $token"; done
for token in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do grep -Fq "$token" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || fail_orchestration "missing GMP evidence $token"; done

required_executables=(directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests)
printf 'binary\tsha256\tmode\tsize\n' > "${RESULT}/owner-executables.tsv"
for exe in "${required_executables[@]}"; do path="$PKG/bin/$exe"; [[ -f "$path" && -x "$path" ]] || fail_orchestration "owner binary absent/non-executable $exe"; printf '%s\t%s\t%s\t%s\n' "$exe" "$(sha_file "$path")" "$(stat -c '%a' "$path")" "$(stat -c '%s' "$path")" >> "${RESULT}/owner-executables.tsv"; done

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_orchestration 'source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_orchestration 'source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE"
selector="$SOURCE/$SELECTOR_RELATIVE_PATH"; routing="$SOURCE/$ROUTING_RELATIVE_PATH"
[[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" ]] || fail_orchestration 'selector digest mismatch'
[[ "$(wc -l < "$selector" | tr -d ' ')" -eq "$EXPECTED_SELECTOR_COUNT" ]] || fail_orchestration 'selector count mismatch'
[[ "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'routing digest mismatch'
[[ "$(wc -l < "$routing" | tr -d ' ')" -eq "$EXPECTED_ROUTING_COUNT" ]] || fail_orchestration 'routing count mismatch'
python3 - "$selector" "$routing" "${RESULT}/routing-validation.txt" <<'PY'
import collections,pathlib,sys
sel=pathlib.Path(sys.argv[1]).read_text().splitlines(); rows=[x.split('\t') for x in pathlib.Path(sys.argv[2]).read_text().splitlines()]; owners=collections.Counter()
for i,(identity,row) in enumerate(zip(sel,rows),1):
    if len(row)!=3 or int(row[0])!=i or row[1]!=identity: raise SystemExit(f'routing mismatch row {i}')
    owners[row[2]]+=1
expected={'directional_surface_cell_authority_kernel_tests':32,'directional_surface_cell_producer_tests':301,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
if dict(owners)!=expected: raise SystemExit(f'owner census mismatch {dict(owners)}')
pathlib.Path(sys.argv[3]).write_text('selector_rows=449\nrouting_rows=449\norder_exact=true\n'+''.join(f'{k}={expected[k]}\n' for k in sorted(expected)))
PY

focused="${RESULT}/focused-vector.tsv"
cat > "$focused" <<'ROWS'
ordinal	identity	binary
1	M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell	directional_surface_cell_producer_tests
2	M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity	directional_surface_cell_producer_tests
3	M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints	directional_surface_cell_producer_tests
4	M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct	directional_surface_cell_producer_tests
5	SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets	directional_surface_cell_producer_tests
6	M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection	directional_surface_cell_producer_tests
7	M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority	directional_surface_cell_producer_tests
8	M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant	directional_surface_cell_producer_tests
9	M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord	directional_surface_cell_producer_tests
10	M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption	directional_surface_cell_producer_tests
11	M6CP1.CycleClosingRelationTransportConflictRejected	directional_surface_cell_producer_tests
12	M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant	directional_surface_cell_producer_tests
ROWS
[[ "$(($(wc -l < "$focused") - 1))" -eq "$EXPECTED_FOCUSED_COUNT" ]] || fail_orchestration 'focused vector count mismatch'
sha256sum "$focused" > "${RESULT}/focused-vector.sha256"

# Static contract receipt from packaged source; no generated test discovery is executed.
python3 - "$SOURCE" "${RESULT}/critical-source-contracts.txt" <<'PY'
import pathlib,sys
root=pathlib.Path(sys.argv[1]); out=pathlib.Path(sys.argv[2]); needles=['RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant','ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection','QuotientRejectsMissingDuplicateOrConflictingConsumption','CycleClosingRelationTransportConflictRejected','canonicalRelationValue','InvalidHardRailTransport','QuotientHolonomyConflict']; rows=[]
for p in [root/'tests/SurfaceCellTransitionQuotientTests.cpp',root/'src/pipeline/RemeshPipeline.cpp']:
    lines=p.read_text(errors='replace').splitlines()
    for i,line in enumerate(lines,1):
        if any(n in line for n in needles):
            lo=max(1,i-2); hi=min(len(lines),i+3); rows.append(f'--- {p.relative_to(root)}:{lo}-{hi} ---\n'); rows.extend(f'{j}:{lines[j-1]}\n' for j in range(lo,hi+1))
out.write_text(''.join(rows))
PY

census_tree "$PKG" "${RESULT}/package-census-before.tsv"; census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"
cp -a "$PKG/bin/." "$EXEC_VIEW/bin/"; mkdir -p "$EXEC_VIEW/test-data/benchmarks"; cp -a "$SOURCE/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
for exe in "${required_executables[@]}"; do [[ "$(sha_file "$PKG/bin/$exe")" == "$(sha_file "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "binary copy digest mismatch $exe"; [[ "$(stat -c '%a' "$PKG/bin/$exe")" == "$(stat -c '%a' "$EXEC_VIEW/bin/$exe")" ]] || fail_orchestration "binary copy mode mismatch $exe"; done
[[ -f "$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'fixture execution view incomplete'
census_tree "$SOURCE/benchmarks/fixtures" "${RESULT}/fixture-source-before.tsv"; census_tree "$EXEC_VIEW/test-data/benchmarks/fixtures" "${RESULT}/fixture-execution-before.tsv"
cmp -s "${RESULT}/fixture-source-before.tsv" "${RESULT}/fixture-execution-before.tsv" || fail_orchestration 'fixture copy mismatch'
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-census-before.tsv"; preflight_completed=true

postflight() {
 census_tree "$PKG" "${RESULT}/package-census-after.tsv"; census_tree "$SOURCE" "${RESULT}/source-census-after.tsv"; census_tree "$EXEC_VIEW" "${RESULT}/execution-view-census-after.tsv"; census_tree "$SOURCE/benchmarks/fixtures" "${RESULT}/fixture-source-after.tsv"; census_tree "$EXEC_VIEW/test-data/benchmarks/fixtures" "${RESULT}/fixture-execution-after.tsv"
 cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv" || fail_orchestration 'candidate package changed'
 if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then source_test_fixture_selector_mutation=true; fail_orchestration 'packaged source changed'; fi
 cmp -s "${RESULT}/execution-view-census-before.tsv" "${RESULT}/execution-view-census-after.tsv" || fail_orchestration 'execution view changed'
 cmp -s "${RESULT}/fixture-source-before.tsv" "${RESULT}/fixture-source-after.tsv" || fail_orchestration 'source fixtures changed'
 cmp -s "${RESULT}/fixture-execution-before.tsv" "${RESULT}/fixture-execution-after.tsv" || fail_orchestration 'execution fixtures changed'
 [[ "$(sha_file "$selector")" == "$EXPECTED_SELECTOR_SHA256" && "$(sha_file "$routing")" == "$EXPECTED_ROUTING_SHA256" ]] || fail_orchestration 'selector/routing changed'
 post_manifest="${RESULT}/candidate-manifest-check-after.txt"; (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$post_manifest"; [[ "$(grep -c ': OK$' "$post_manifest")" -eq 28 ]] || fail_orchestration 'post manifest not 28/28'
 printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\nfixture_source_equal=true\nfixture_execution_equal=true\nselector_unchanged=true\nrouting_unchanged=true\nmanifest_after=28/28\n' > "${RESULT}/immutability.txt"
}

first_failure_text() { python3 - "$1" <<'PY'
import pathlib,sys
lines=pathlib.Path(sys.argv[1]).read_text(errors='replace').splitlines(); pats=('QuotientHolonomyConflict','OccurrenceInvalidCornerAuthority','InvalidHardRailTransport','RelationCertificateConflict','FAILED','Expected','Actual','what():')
for line in lines:
    if any(p in line for p in pats): print(line.replace('\t',' ').strip()[:800]); break
else: print('-')
PY
}
run_identity() {
 local phase="$1" ordinal="$2" identity="$3" binary="$4" ledger="$5" phase_dir raw resource work code selected skipped passed result first_failure
 phase_dir="${phase,,}"; raw="${RESULT}/raw/${phase_dir}/ordinal-$(printf '%03d' "$ordinal").log"; resource="${RESULT}/resources/${phase_dir}/ordinal-$(printf '%03d' "$ordinal").time.txt"; work="${RUNTIME}/${phase_dir}/ordinal-$(printf '%03d' "$ordinal")"; mkdir -p "$work"
 echo "${TURN_ID} phase=${phase} ordinal=${ordinal} identity=${identity} owner=${binary}"
 set +e; (cd "$work"; /usr/bin/time -v -o "$resource" env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw" 2>&1; code=$?; set -e; cat "$raw"
 selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"; skipped="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"; passed="$(grep -Ec '^\[       OK \] ' "$raw" || true)"
 [[ "$selected" -eq 1 ]] || { selection_integrity=false; fail_orchestration "exact-one failed ${identity} selected=${selected}"; }; [[ "$skipped" -eq 0 ]] || { selection_integrity=false; fail_orchestration "skip observed ${identity}"; }
 result=RED; [[ "$code" -eq 0 && "$passed" -eq 1 ]] && result=PASS; first_failure="$(first_failure_text "$raw")"
 printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$binary" "$code" "$selected" "$skipped" "$passed" "$result" "$(sha_file "$raw")" "$first_failure" >> "$ledger"
}

runtime_started=true
focused_ledger="${RESULT}/focused-ledger.tsv"; printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\tfirst_failure\n' > "$focused_ledger"
while IFS=$'\t' read -r ordinal identity binary; do [[ "$ordinal" == ordinal ]] && continue; run_identity focused "$ordinal" "$identity" "$binary" "$focused_ledger"; focused_executed=$((focused_executed+1)); done < "$focused"
[[ "$focused_executed" -eq 12 ]] || fail_orchestration 'focused execution count mismatch'; sha256sum "$focused_ledger" > "${RESULT}/focused-ledger.sha256"
selector_ledger="${RESULT}/selector-ledger.tsv"; printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\tfirst_failure\n' > "$selector_ledger"
while IFS=$'\t' read -r ordinal identity binary; do run_identity selector "$ordinal" "$identity" "$binary" "$selector_ledger"; selector_executed=$((selector_executed+1)); done < "$routing"
[[ "$selector_executed" -eq 449 ]] || fail_orchestration 'selector execution count mismatch'; sha256sum "$selector_ledger" > "${RESULT}/selector-ledger.sha256"; runtime_completed=true

python3 - "$focused_ledger" "$selector_ledger" "${RESULT}/semantic-summary.txt" "${RESULT}/red-ledger.tsv" "${RESULT}/critical-outcomes.tsv" "${RESULT}/execution-ledger.tsv" <<'PY'
import csv,pathlib,sys
focused=list(csv.DictReader(open(sys.argv[1]),delimiter='\t')); selector=list(csv.DictReader(open(sys.argv[2]),delimiter='\t'))
if len(focused)!=12 or [int(r['ordinal']) for r in focused]!=list(range(1,13)): raise SystemExit('focused ledger coverage mismatch')
if len(selector)!=449 or [int(r['ordinal']) for r in selector]!=list(range(1,450)): raise SystemExit('selector ledger coverage mismatch')
fp=sum(r['result']=='PASS' for r in focused); sp=sum(r['result']=='PASS' for r in selector); fred=[int(r['ordinal']) for r in focused if r['result']!='PASS']; sred=[int(r['ordinal']) for r in selector if r['result']!='PASS']
pathlib.Path(sys.argv[3]).write_text(f'focused_total=12\nfocused_pass={fp}\nfocused_red={len(fred)}\nfocused_red_ordinals={fred}\nselector_total=449\nselector_pass={sp}\nselector_red={len(sred)}\nselector_red_ordinals={sred}\ntotal_processes=461\ntotal_pass={fp+sp}\ntotal_red={len(fred)+len(sred)}\nbenchmark_execution=0\nexact_one_selection=true\nzero_skips=true\n')
fields=['phase','ordinal','identity','binary','exit','selected','skipped','passed','result','raw_sha256','first_failure']
with open(sys.argv[4],'w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=fields,delimiter='\t'); w.writeheader();
 for phase,rows in [('focused',focused),('selector',selector)]:
  for r in rows:
   if r['result']!='PASS': w.writerow({'phase':phase,**r})
crit_focus={6,10,11,12}; crit_sel={115,116,122,130,132,134,137,139,140,141,142,143,150,176,201,217,227,230,231,232,444,446,448,449}
with open(sys.argv[5],'w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=fields,delimiter='\t'); w.writeheader();
 for phase,rows,ords in [('focused',focused,crit_focus),('selector',selector,crit_sel)]:
  for r in rows:
   if int(r['ordinal']) in ords: w.writerow({'phase':phase,**r})
with open(sys.argv[6],'w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=fields,delimiter='\t'); w.writeheader();
 for phase,rows in [('focused',focused),('selector',selector)]:
  for r in rows: w.writerow({'phase':phase,**r})
PY
sha256sum "${RESULT}/execution-ledger.tsv" > "${RESULT}/execution-ledger.sha256"; sha256sum "${RESULT}/red-ledger.tsv" > "${RESULT}/red-ledger.sha256"
python3 - "$RESULT" "${RESULT}/diagnostic-census.txt" <<'PY'
import pathlib,sys
root=pathlib.Path(sys.argv[1])/'raw'; needles=['QuotientHolonomyConflict','OccurrenceInvalidCornerAuthority','InvalidHardRailTransport','RelationCertificateConflict']; lines=[]
for needle in needles:
 hits=[]
 for p in sorted(root.rglob('*.log')):
  n=p.read_text(errors='replace').count(needle)
  if n: hits.append((p.relative_to(root).as_posix(),n))
 lines += [f'{needle}_raw_file_count={len(hits)}',f'{needle}_occurrence_count={sum(n for _,n in hits)}']+[f'{needle}_hit={p}:{n}' for p,n in hits]
pathlib.Path(sys.argv[2]).write_text('\n'.join(lines)+'\n')
PY
postflight
[[ "$benchmark_execution" == false && "$EXPECTED_BENCHMARK_COUNT" -eq 0 ]] || fail_orchestration 'benchmark boundary violated'
[[ $((focused_executed+selector_executed)) -eq "$EXPECTED_TOTAL_PROCESS_COUNT" ]] || fail_orchestration 'total count mismatch'
write_boundary; echo 'script_exit=0' >> "${RESULT}/execution-boundary.txt"
manifest_tmp="${RUNNER_TEMP}/${SAFE_TURN_ID}-SHA256SUMS.tmp"; (cd "$RESULT"; find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum) > "$manifest_tmp"; rows="$(wc -l < "$manifest_tmp" | tr -d ' ')"; files="$(find "$RESULT" -type f ! -name SHA256SUMS | wc -l | tr -d ' ')"; [[ "$rows" -eq "$files" ]] || fail_orchestration 'result manifest completeness mismatch'; mv "$manifest_tmp" "$RESULT/SHA256SUMS"; (cd "$RESULT" && sha256sum -c SHA256SUMS >/dev/null)
cat "${RESULT}/semantic-summary.txt"; cat "${RESULT}/critical-outcomes.tsv"; cat "${RESULT}/diagnostic-census.txt"
echo "${TURN_ID}_COMPLETE: 461 fresh exact-filter artifact-only processes complete; semantic interpretation deferred to Review."
