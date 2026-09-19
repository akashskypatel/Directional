#!/usr/bin/env bash
set -euo pipefail

REPOSITORY="akashskypatel/Directional"
ARTIFACT_ID="10575545321"
EXPECTED_PACKAGE_SHA256="602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00"
EXPECTED_SOURCE_SHA="ad54c12774e10480fd3cef8138cacb8d5dec1529"
EXPECTED_SOURCE_ARCHIVE_SHA256="781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed"
EXPECTED_SELECTOR_SHA256="f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f"
EXPECTED_SELECTOR_ROWS=427
SELECTOR_REL=".agents/Directional/Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt"

: "${RUNNER_TEMP:?RUNNER_TEMP required}"
: "${GITHUB_REPOSITORY:?GITHUB_REPOSITORY required}"
: "${GITHUB_RUN_ID:?GITHUB_RUN_ID required}"
: "${GH_TOKEN:?GH_TOKEN required}"

ROOT="${RUNNER_TEMP}/m4-cp4-tb1-r2"
PKG_ZIP="${ROOT}/candidate.zip"
PKG="${ROOT}/package"
SRCVIEW="${ROOT}/packaged-source"
EXECVIEW="${ROOT}/execution-view"
RESULT="${RUNNER_TEMP}/m4-cp4-tb1-r2-result"
RAW="${RESULT}/raw"
LOG="${RUNNER_TEMP}/m4-cp4-tb1-r2.log"
mkdir -p "$ROOT" "$PKG" "$SRCVIEW" "$EXECVIEW" "$RESULT" "$RAW"
: > "$LOG"
exec > >(tee -a "$LOG") 2>&1

runtime_started=false
postflight_complete=false
orchestration_failure=false
semantic_non_green=false
stop_reason="preflight_in_progress"
benchmark_execution_count=0
generated_discovery_count=0
configure_execution_count=0
compile_execution_count=0
relink_execution_count=0
package_repair_count=0
mode_repair_count=0
source_mutation_count=0
test_mutation_count=0
fixture_mutation_count=0
selector_mutation_count=0
focus_executed=0
selector_executed=0

write_boundary() {
  cat > "${RESULT}/boundary.env" <<BOUNDARY
repository=${GITHUB_REPOSITORY}
run_id=${GITHUB_RUN_ID}
artifact_id=${ARTIFACT_ID}
expected_source_sha=${EXPECTED_SOURCE_SHA}
runtime_started=${runtime_started}
postflight_complete=${postflight_complete}
orchestration_failure=${orchestration_failure}
semantic_non_green=${semantic_non_green}
stop_reason=${stop_reason}
focus_executed=${focus_executed}
selector_executed=${selector_executed}
benchmark_execution_count=${benchmark_execution_count}
generated_discovery_count=${generated_discovery_count}
configure_execution_count=${configure_execution_count}
compile_execution_count=${compile_execution_count}
relink_execution_count=${relink_execution_count}
package_repair_count=${package_repair_count}
mode_repair_count=${mode_repair_count}
source_mutation_count=${source_mutation_count}
test_mutation_count=${test_mutation_count}
fixture_mutation_count=${fixture_mutation_count}
selector_mutation_count=${selector_mutation_count}
BOUNDARY
}
trap 'rc=$?; trap - EXIT; write_boundary; echo "harness_exit=${rc}" > "${RESULT}/harness-exit-code.txt"; ( cd "$RESULT" && find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS ); exit $rc' EXIT

fail_orchestration() {
  local reason="$1"
  orchestration_failure=true
  stop_reason="$reason"
  echo "ORCHESTRATION_FAILURE: $reason" >&2
  return 90
}

sha_file() { sha256sum "$1" | awk '{print $1}'; }

census_tree() {
  local root="$1" out="$2"
  python3 - "$root" "$out" <<'PY'
from pathlib import Path
import hashlib, os, stat, sys
root=Path(sys.argv[1]); out=Path(sys.argv[2])
rows=[]
for p in sorted(root.rglob('*')):
    rel=p.relative_to(root).as_posix()
    st=p.lstat()
    mode=stat.S_IMODE(st.st_mode)
    if p.is_symlink():
        target=os.readlink(p)
        digest=hashlib.sha256(target.encode()).hexdigest()
        rows.append(f"L\t{mode:04o}\t{len(target)}\t{digest}\t{rel}\t{target}")
    elif p.is_file():
        h=hashlib.sha256()
        with p.open('rb') as f:
            for chunk in iter(lambda:f.read(1024*1024), b''): h.update(chunk)
        rows.append(f"F\t{mode:04o}\t{st.st_size}\t{h.hexdigest()}\t{rel}")
out.write_text('\n'.join(rows)+'\n', encoding='utf-8')
PY
}

record_manifest_verification() {
  local phase="$1"
  ( cd "$PKG" && sha256sum -c SHA256SUMS ) > "${RESULT}/package-manifest-${phase}.txt" 2>&1
  sha_file "${RESULT}/package-manifest-${phase}.txt" > "${RESULT}/package-manifest-${phase}.sha256"
}

require_line() {
  local file="$1" expected="$2"
  grep -Fqx -- "$expected" "$file" || { echo "missing exact line '$expected' in $file" >&2; return 1; }
}

classify_owner_map() {
  python3 - "$SRCVIEW" "$SRCVIEW/$SELECTOR_REL" "${RESULT}/identity-map.tsv" <<'PY'
from pathlib import Path
from collections import Counter
import re, sys
src=Path(sys.argv[1]); selector=Path(sys.argv[2]); out=Path(sys.argv[3])
source_sets={
'authority-kernel': ['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],
'producer': ['tests/AdaptiveFeatureMapPhase11Tests.cpp','tests/AdaptiveTargetSizePhase12Tests.cpp','tests/BoundedMeshPreconditionerTests.cpp','tests/CrossFieldTransferTests.cpp','tests/FieldAlignedCurveNetworkTests.cpp','tests/GlobalConformityBaselineTests.cpp','tests/GlobalConformityPlanTests.cpp','tests/InputConditionerTests.cpp','tests/RegularizedCurvaturePhase1Tests.cpp','tests/SourceGridRecoveryAuthorityTests.cpp','tests/SurfaceCellDesignAcceptanceTests.cpp','tests/SurfaceCellREPackageTests.cpp','tests/SurfaceCellTransitionQuotientTests.cpp','tests/SurfaceCellsPhase10Tests.cpp'],
'completion': ['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
'validation': ['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp'],
}
binaries={
'authority-kernel':'directional_surface_cell_authority_kernel_tests',
'producer':'directional_surface_cell_producer_tests',
'completion':'directional_surface_cell_completion_tests',
'validation':'directional_surface_cell_validation_tests',
}
texts={o:{p:(src/p).read_text(errors='replace') for p in ps} for o,ps in source_sets.items()}
rows=[]
for idx,ident in enumerate(selector.read_text(encoding='utf-8').splitlines(),1):
    if not ident or '.' not in ident: raise SystemExit(f'invalid selector row {idx}: {ident!r}')
    suite,name=ident.split('.',1)
    pat=re.compile(r'TEST(?:_F|_P)?\s*\(\s*'+re.escape(suite)+r'\s*,\s*'+re.escape(name)+r'\s*\)')
    hits=[]
    for owner,files in texts.items():
        for path,text in files.items():
            if pat.search(text): hits.append((owner,path))
    if len(hits)!=1: raise SystemExit(f'owner map row {idx} {ident}: hits={hits}')
    owner,path=hits[0]
    rows.append((idx,ident,owner,binaries[owner],path))
counts=Counter(r[2] for r in rows)
expected={'authority-kernel':30,'producer':281,'completion':75,'validation':41}
if dict(counts)!=expected: raise SystemExit(f'owner census mismatch: actual={dict(counts)} expected={expected}')
out.write_text('ordinal\tidentity\towner\tbinary\tsource\n'+''.join('\t'.join(map(str,r))+'\n' for r in rows), encoding='utf-8')
print('owner_census=' + '/'.join(str(counts[k]) for k in ('authority-kernel','producer','completion','validation')))
PY
}

initialize_ledger() {
  printf 'plan_row\tphase\tphase_ordinal\tidentity\towner\tbinary\tstatus\texit_code\tselected\tpassed\tskipped\traw_log_sha256\n' > "${RESULT}/ledger.tsv"
  python3 - "$RESULT/identity-map.tsv" "$RESULT/ledger.tsv" <<'PY'
from pathlib import Path
import csv, sys
imap=Path(sys.argv[1]); ledger=Path(sys.argv[2])
focus=[
('M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated','producer','directional_surface_cell_producer_tests'),
('M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle','completion','directional_surface_cell_completion_tests'),
('M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering','producer','directional_surface_cell_producer_tests'),
('M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected','producer','directional_surface_cell_producer_tests'),
('M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder','producer','directional_surface_cell_producer_tests'),
('M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection','authority-kernel','directional_surface_cell_authority_kernel_tests'),
]
with ledger.open('a',encoding='utf-8') as f:
    for i,(ident,owner,binary) in enumerate(focus,1):
        f.write(f'{i}\tfocus\t{i}\t{ident}\t{owner}\t{binary}\tUNEXECUTED\t\t0\t0\t0\t\n')
    with imap.open(encoding='utf-8') as m:
        r=csv.DictReader(m,delimiter='\t')
        for row in r:
            plan=6+int(row['ordinal'])
            f.write(f"{plan}\tselector\t{row['ordinal']}\t{row['identity']}\t{row['owner']}\t{row['binary']}\tUNEXECUTED\t\t0\t0\t0\t\n")
PY
  test "$(($(wc -l < "${RESULT}/ledger.tsv")-1))" -eq 433
}

update_ledger_row() {
  local plan_row="$1" status="$2" rc="$3" selected="$4" passed="$5" skipped="$6" rawsha="$7"
  python3 - "$RESULT/ledger.tsv" "$plan_row" "$status" "$rc" "$selected" "$passed" "$skipped" "$rawsha" <<'PY'
from pathlib import Path
import sys
p=Path(sys.argv[1]); target=int(sys.argv[2]); vals=sys.argv[3:]
lines=p.read_text().splitlines(); hdr=lines[0].split('\t'); out=[lines[0]]
for line in lines[1:]:
    row=line.split('\t')
    if int(row[0])==target:
        row[6]=vals[0]; row[7]=vals[1]; row[8]=vals[2]; row[9]=vals[3]; row[10]=vals[4]; row[11]=vals[5]
    out.append('\t'.join(row))
p.write_text('\n'.join(out)+'\n')
PY
}

run_one() {
  local plan_row="$1" phase="$2" phase_ord="$3" identity="$4" owner="$5" binary="$6"
  local raw="${RAW}/$(printf '%03d' "$plan_row")-${phase}-$(printf '%03d' "$phase_ord").log"
  local exe="${EXECVIEW}/bin/${binary}"
  local rc selected passed skipped status rawsha
  echo "RUN plan_row=${plan_row} phase=${phase} ordinal=${phase_ord} owner=${owner} identity=${identity}"
  if GTEST_FAIL_IF_NO_TEST_SELECTED=1 "$exe" "--gtest_filter=${identity}" > "$raw" 2>&1; then
    rc=0
  else
    rc=$?
  fi
  selected="$(grep -c '^\[ RUN      \]' "$raw" || true)"
  passed="$(grep -c '^\[       OK \]' "$raw" || true)"
  skipped="$(grep -c '^\[  SKIPPED \]' "$raw" || true)"
  rawsha="$(sha_file "$raw")"
  if [[ "$selected" -ne 1 ]]; then
    status=SELECTION_MISMATCH
    orchestration_failure=true
    stop_reason="selection_mismatch_${phase}_${phase_ord}"
  elif [[ "$skipped" -ne 0 ]]; then
    status=SKIP
    semantic_non_green=true
    stop_reason="semantic_skip_${phase}_${phase_ord}"
  elif [[ "$rc" -eq 0 && "$passed" -eq 1 ]]; then
    status=PASS
  elif [[ "$rc" -ge 128 ]]; then
    status=CRASH
    semantic_non_green=true
    stop_reason="semantic_crash_${phase}_${phase_ord}"
  else
    status=RED
    semantic_non_green=true
    stop_reason="semantic_red_${phase}_${phase_ord}"
  fi
  update_ledger_row "$plan_row" "$status" "$rc" "$selected" "$passed" "$skipped" "$rawsha"
  echo "RESULT plan_row=${plan_row} status=${status} exit=${rc} selected=${selected} passed=${passed} skipped=${skipped} raw_sha256=${rawsha}"
  [[ "$status" == PASS ]]
}

echo "M4-CP4-TB1-R2-EXEC immutable artifact-only harness"
echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
echo "repository=${GITHUB_REPOSITORY}; run_id=${GITHUB_RUN_ID}; artifact_id=${ARTIFACT_ID}"

if [[ "$GITHUB_REPOSITORY" != "$REPOSITORY" ]]; then fail_orchestration repository_mismatch; exit $?; fi

# Candidate artifact is downloaded exactly once as raw provider ZIP.
echo "downloading artifact_id=${ARTIFACT_ID} exactly once"
curl --fail --silent --show-error --location   -H "Authorization: Bearer ${GH_TOKEN}"   -H "Accept: application/vnd.github+json"   "https://api.github.com/repos/${REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip"   -o "$PKG_ZIP"
actual_package_sha="$(sha_file "$PKG_ZIP")"
echo "package_zip_sha256=${actual_package_sha}"
if [[ "$actual_package_sha" != "$EXPECTED_PACKAGE_SHA256" ]]; then fail_orchestration package_zip_sha_mismatch; exit $?; fi

unzip -q "$PKG_ZIP" -d "$PKG"
test -f "$PKG/SHA256SUMS" || { fail_orchestration package_manifest_missing; exit $?; }
if ! record_manifest_verification before; then fail_orchestration package_manifest_mismatch; exit $?; fi

source_commit="$(tr -d '\r\n' < "$PKG/metadata/source-commit.txt")"
echo "package_source_commit=${source_commit}"
if [[ "$source_commit" != "$EXPECTED_SOURCE_SHA" ]]; then fail_orchestration source_commit_mismatch; exit $?; fi
for receipt in source-status-before-configure.txt source-status-preconfigure.txt source-status-after-configure.txt source-status-after-build.txt source-status-final.txt; do
  test -f "$PKG/metadata/$receipt" || { fail_orchestration "missing_${receipt}"; exit $?; }
  if [[ -s "$PKG/metadata/$receipt" ]]; then fail_orchestration "dirty_${receipt}"; exit $?; fi
done
require_line "$PKG/metadata/command-boundary.txt" "runtimeExecution=false" || { fail_orchestration runtime_boundary_missing; exit $?; }
require_line "$PKG/metadata/command-boundary.txt" "exactArithmeticBackend=GMP" || { fail_orchestration gmp_boundary_missing; exit $?; }
require_line "$PKG/metadata/command-boundary.txt" "semanticContracts=compiled-not-executed" || { fail_orchestration semantic_boundary_missing; exit $?; }
grep -F 'libgmpxx.so' "$PKG/metadata/gmp-evidence.txt" >/dev/null || { fail_orchestration gmpxx_evidence_missing; exit $?; }
grep -F 'libgmp.so' "$PKG/metadata/gmp-evidence.txt" >/dev/null || { fail_orchestration gmp_evidence_missing; exit $?; }

mapfile -t source_archives < <(find "$PKG/source" -maxdepth 1 -type f -name 'source-*.tar.gz' -print)
if [[ "${#source_archives[@]}" -ne 1 ]]; then fail_orchestration source_archive_cardinality; exit $?; fi
source_archive="${source_archives[0]}"
actual_source_archive_sha="$(sha_file "$source_archive")"
echo "source_archive_sha256=${actual_source_archive_sha}"
if [[ "$actual_source_archive_sha" != "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]]; then fail_orchestration source_archive_sha_mismatch; exit $?; fi
tar -xzf "$source_archive" -C "$SRCVIEW"
selector="$SRCVIEW/$SELECTOR_REL"
test -f "$selector" || { fail_orchestration selector_missing; exit $?; }
selector_sha="$(sha_file "$selector")"
selector_rows="$(wc -l < "$selector" | tr -d ' ')"
cr_count="$(LC_ALL=C tr -cd '\r' < "$selector" | wc -c | tr -d ' ')"
echo "selector_rows=${selector_rows}; selector_sha256=${selector_sha}; selector_cr_count=${cr_count}"
if [[ "$selector_rows" -ne "$EXPECTED_SELECTOR_ROWS" || "$selector_sha" != "$EXPECTED_SELECTOR_SHA256" || "$cr_count" -ne 0 ]]; then fail_orchestration selector_integrity_mismatch; exit $?; fi
classify_owner_map
initialize_ledger

# Require package closure for all four existing selector owners before any runtime.
missing_owner_binaries=()
for binary in   directional_surface_cell_authority_kernel_tests   directional_surface_cell_producer_tests   directional_surface_cell_completion_tests   directional_surface_cell_validation_tests; do
  path="$PKG/bin/$binary"
  if [[ ! -f "$path" ]]; then
    missing_owner_binaries+=("$binary:absent")
    continue
  fi
  mode="$(stat -c '%a' "$path")"
  echo "owner_binary=${binary}; mode=${mode}; sha256=$(sha_file "$path")"
  if [[ ! -x "$path" ]]; then missing_owner_binaries+=("$binary:mode-${mode}"); fi
done
if (( ${#missing_owner_binaries[@]} != 0 )); then
  printf '%s\n' "${missing_owner_binaries[@]}" > "${RESULT}/missing-owner-binaries.txt"
  fail_orchestration missing_selector_owner_binary
  exit $?
fi

# Create a separate immutable execution view; package bytes/modes remain untouched.
mkdir -p "$EXECVIEW/bin" "$EXECVIEW/test-data/benchmarks"
for binary in   directional_surface_cell_authority_kernel_tests   directional_surface_cell_producer_tests   directional_surface_cell_completion_tests   directional_surface_cell_validation_tests; do
  cp -a "$PKG/bin/$binary" "$EXECVIEW/bin/$binary"
done
test -d "$SRCVIEW/benchmarks/fixtures" || { fail_orchestration packaged_fixture_tree_missing; exit $?; }
cp -a "$SRCVIEW/benchmarks/fixtures" "$EXECVIEW/test-data/benchmarks/fixtures"

census_tree "$PKG" "${RESULT}/package-census-before.tsv"
census_tree "$SRCVIEW" "${RESULT}/source-census-before.tsv"
census_tree "$EXECVIEW" "${RESULT}/execution-view-census-before.tsv"
sha_file "${RESULT}/package-census-before.tsv" > "${RESULT}/package-census-before.sha256"
sha_file "${RESULT}/source-census-before.tsv" > "${RESULT}/source-census-before.sha256"
sha_file "${RESULT}/execution-view-census-before.tsv" > "${RESULT}/execution-view-census-before.sha256"

runtime_started=true
stop_reason="runtime_in_progress"

# Focused phase: all six fresh processes execute even if one is semantic non-green.
while IFS=$'\t' read -r plan phase phase_ord identity owner binary status rc selected passed skipped rawsha; do
  [[ "$plan" == plan_row || "$phase" != focus ]] && continue
  set +e
  run_one "$plan" "$phase" "$phase_ord" "$identity" "$owner" "$binary"
  one_rc=$?
  set -e
  focus_executed=$((focus_executed+1))
  if [[ "$orchestration_failure" == true ]]; then break; fi
  : "$one_rc"
done < "${RESULT}/ledger.tsv"

# Exact selector prefix follows focused execution unless orchestration has invalidated runtime.
if [[ "$orchestration_failure" == false ]]; then
  while IFS=$'\t' read -r plan phase phase_ord identity owner binary status rc selected passed skipped rawsha; do
    [[ "$plan" == plan_row || "$phase" != selector ]] && continue
    set +e
    run_one "$plan" "$phase" "$phase_ord" "$identity" "$owner" "$binary"
    one_rc=$?
    set -e
    selector_executed=$((selector_executed+1))
    if [[ "$orchestration_failure" == true ]]; then break; fi
    if [[ "$one_rc" -ne 0 ]]; then
      # First selector semantic non-green is gating evidence; preserve and stop.
      break
    fi
  done < "${RESULT}/ledger.tsv"
fi

# Immutable postflight is mandatory whenever runtime started.
census_tree "$PKG" "${RESULT}/package-census-after.tsv"
census_tree "$SRCVIEW" "${RESULT}/source-census-after.tsv"
census_tree "$EXECVIEW" "${RESULT}/execution-view-census-after.tsv"
if ! cmp -s "${RESULT}/package-census-before.tsv" "${RESULT}/package-census-after.tsv"; then orchestration_failure=true; stop_reason=package_postflight_mismatch; fi
if ! cmp -s "${RESULT}/source-census-before.tsv" "${RESULT}/source-census-after.tsv"; then orchestration_failure=true; stop_reason=source_postflight_mismatch; fi
if ! cmp -s "${RESULT}/execution-view-census-before.tsv" "${RESULT}/execution-view-census-after.tsv"; then orchestration_failure=true; stop_reason=execution_view_postflight_mismatch; fi
if ! record_manifest_verification after; then orchestration_failure=true; stop_reason=package_manifest_postflight_mismatch; fi
postflight_complete=true

python3 - "$RESULT/ledger.tsv" "$RESULT/summary.json" <<'PY'
import csv,json,sys
from collections import Counter
rows=list(csv.DictReader(open(sys.argv[1],encoding='utf-8'),delimiter='\t'))
counts=Counter(r['status'] for r in rows)
focus=Counter(r['status'] for r in rows if r['phase']=='focus')
selector=Counter(r['status'] for r in rows if r['phase']=='selector')
json.dump({'planned_rows':len(rows),'status_counts':dict(counts),'focus_counts':dict(focus),'selector_counts':dict(selector)},open(sys.argv[2],'w'),indent=2,sort_keys=True)
PY

if [[ "$orchestration_failure" == false && "$semantic_non_green" == false && "$focus_executed" -eq 6 && "$selector_executed" -eq 427 ]]; then
  stop_reason=all_green
elif [[ "$orchestration_failure" == false && "$semantic_non_green" == true ]]; then
  : # keep first semantic stop reason recorded by run_one
fi

write_boundary

echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
echo "orchestration_failure=${orchestration_failure}; semantic_non_green=${semantic_non_green}; stop_reason=${stop_reason}; focus_executed=${focus_executed}; selector_executed=${selector_executed}"

if [[ "$orchestration_failure" == true ]]; then exit 90; fi
# Semantic non-green is valid evidence, not orchestration failure; preserve job evidence with exit 0.
exit 0
