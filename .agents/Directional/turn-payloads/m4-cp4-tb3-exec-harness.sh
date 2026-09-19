#!/usr/bin/env bash
set -Eeuo pipefail

TURN_ID='M4-CP4-TB3-EXEC'
ARTIFACT_ID='10591801825'
ARTIFACT_NAME='m4-cp4-cb8-result-result-35468097574'
PACKAGE_ZIP_SHA256='20d9b07bae631e68f3292ee37ccb80c4724bae6eec0c50cd2274c36443183da6'
SOURCE_SHA='aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431'
SOURCE_TAR_SHA256='4d057381ba3f1caed55579f7a9b662753632637eb0aff7b1432326d8e557021a'
MANIFEST_SHA256='30c3f51fa0e43882d1a3c1227f58c069023007e38dbdc9a96c832ce152157b5a'
SELECTOR_REL='.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt'
SELECTOR_SHA256='1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6'
PREFIX427_SHA256='f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f'
SELECTOR_ROWS=430
SELECTOR_BYTES=35001
RUNTIME="${RUNNER_TEMP}/m4-cp4-tb3-exec"
PKG="$RUNTIME/package"
SRC="$RUNTIME/source"
EXEC_VIEW="$RUNTIME/execution-view"
PROC="$RUNTIME/processes"
RESULT="${RUNNER_TEMP}/m4-cp4-tb3-exec-result"
TB_LOG="${RUNNER_TEMP}/m4-cp4-tb3-exec.log"
ZIP="$RUNTIME/package.zip"
mkdir -p "$PKG" "$SRC" "$EXEC_VIEW/bin" "$EXEC_VIEW/test-data/benchmarks" "$PROC" "$RESULT/raw"
: > "$TB_LOG"
exec > >(tee -a "$TB_LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
postflight_complete=false
orchestration_failure=false
orchestration_reason=''
semantic_non_green=false
configure_execution_count=0
compile_execution_count=0
relink_execution_count=0
generated_discovery_count=0
package_repair_count=0
mode_repair_count=0
source_mutation_count=0
test_mutation_count=0
fixture_mutation_count=0
selector_mutation_count=0
benchmark_execution_count=0

sha_file() { sha256sum "$1" | awk '{print $1}'; }
write_manifest() { (cd "$RESULT" && find . -type f ! -name SHA256SUMS -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS); }
census_tree() {
  python3 - "$1" "$2" <<'PY'
import hashlib, os, pathlib, stat, sys
root=pathlib.Path(sys.argv[1]).resolve(); out=pathlib.Path(sys.argv[2]); rows=[]
for p in [root,*sorted(root.rglob('*'),key=lambda q:q.relative_to(root).as_posix())]:
    rel='.' if p==root else p.relative_to(root).as_posix(); s=p.lstat(); mode=f'{stat.S_IMODE(s.st_mode):o}'
    if stat.S_ISREG(s.st_mode):
        h=hashlib.sha256()
        with p.open('rb') as f:
            for c in iter(lambda:f.read(1048576),b''): h.update(c)
        kind,digest,target='file',h.hexdigest(),'-'
    elif stat.S_ISDIR(s.st_mode): kind,digest,target='directory','-','-'
    elif stat.S_ISLNK(s.st_mode): kind,digest,target='symlink','-',os.readlink(p)
    else: kind,digest,target='other','-','-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{s.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows))
PY
}
finish() {
  local status=$?; set +e; trap - EXIT
  if [[ "$status" -ne 0 && "$orchestration_failure" == false ]]; then orchestration_failure=true; orchestration_reason="unexpected_harness_exit_${status}"; status=90; fi
  if [[ "$runtime_started" == true && "$postflight_complete" == false ]]; then orchestration_failure=true; [[ -n "$orchestration_reason" ]] || orchestration_reason='runtime_postflight_incomplete'; status=90; fi
  [[ "$orchestration_failure" == false ]] || status=90
  {
    echo "script_exit=$status"; echo "turn_id=$TURN_ID"; echo "runtime_started=$runtime_started"; echo "runtime_completed=$runtime_completed"
    echo "preflight_completed=$preflight_completed"; echo "postflight_complete=$postflight_complete"
    echo "orchestration_failure=$orchestration_failure"; echo "orchestration_reason=$orchestration_reason"; echo "semantic_non_green=$semantic_non_green"
    echo "configure_execution_count=$configure_execution_count"; echo "compile_execution_count=$compile_execution_count"; echo "relink_execution_count=$relink_execution_count"
    echo "generated_discovery_count=$generated_discovery_count"; echo "package_repair_count=$package_repair_count"; echo "mode_repair_count=$mode_repair_count"
    echo "source_mutation_count=$source_mutation_count"; echo "test_mutation_count=$test_mutation_count"; echo "fixture_mutation_count=$fixture_mutation_count"
    echo "selector_mutation_count=$selector_mutation_count"; echo "benchmark_execution_count=$benchmark_execution_count"; echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  } > "$RESULT/execution-boundary.txt"
  write_manifest || status=90
  echo "script_exit=$status orchestration_failure=$orchestration_failure semantic_non_green=$semantic_non_green postflight_complete=$postflight_complete"
  exit "$status"
}
trap finish EXIT
fail_orchestration() { orchestration_failure=true; orchestration_reason="$1"; echo "ORCHESTRATION FAILURE: $1" >&2; exit 90; }
mark_orchestration() { orchestration_failure=true; [[ -n "$orchestration_reason" ]] || orchestration_reason="$1"; echo "ORCHESTRATION FAILURE: $1" >&2; }

{
  echo "turn_id=$TURN_ID"; echo "artifact_id=$ARTIFACT_ID"; echo "expected_artifact_name=$ARTIFACT_NAME"; echo "source_sha=$SOURCE_SHA"
  echo "selector_relative_path=$SELECTOR_REL"; echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"; uname -a; python3 --version; unzip -v | sed -n '1p'; tar --version | sed -n '1p'
} > "$RESULT/environment.txt"

# Download the immutable CB8 package exactly once and verify provider/download digest.
meta="$(curl --fail --silent --show-error -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}")"
name="$(jq -r '.name' <<<"$meta")"; provider="$(jq -r '.digest // empty' <<<"$meta")"; expired="$(jq -r '.expired' <<<"$meta")"
[[ "$name" == "$ARTIFACT_NAME" && "$expired" == false ]] || fail_orchestration 'artifact identity/expiry mismatch'
[[ "$provider" == "sha256:${PACKAGE_ZIP_SHA256}" ]] || fail_orchestration 'provider artifact digest mismatch'
curl --fail --silent --show-error -L -H "Authorization: Bearer ${GH_TOKEN}" -H 'Accept: application/vnd.github+json' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" -o "$ZIP"
[[ "$(sha_file "$ZIP")" == "$PACKAGE_ZIP_SHA256" ]] || fail_orchestration 'downloaded artifact digest mismatch'
printf 'artifact_id=%s\nartifact_name=%s\nprovider_digest=%s\ndownload_sha256=%s\n' "$ARTIFACT_ID" "$name" "$provider" "$(sha_file "$ZIP")" > "$RESULT/artifact-authority.txt"
unzip -q "$ZIP" -d "$PKG"

# Immutable package verification.
[[ -f "$PKG/SHA256SUMS" ]] || fail_orchestration 'SHA256SUMS absent'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$MANIFEST_SHA256" ]] || fail_orchestration 'manifest SHA-256 mismatch'
[[ "$(wc -l < "$PKG/SHA256SUMS")" -eq 26 ]] || fail_orchestration 'manifest cardinality mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) > "$RESULT/package-manifest-check-before.txt"
[[ "$(grep -c ': OK$' "$RESULT/package-manifest-check-before.txt")" -eq 26 ]] || fail_orchestration 'manifest verification incomplete'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$SOURCE_SHA" ]] || fail_orchestration 'compiled source mismatch'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == 0 && "$(cat "$PKG/metadata/build-exit-code.txt")" == 0 ]] || fail_orchestration 'compile receipt nonzero'
grep -Fq 'runtimeExecution=false' "$PKG/metadata/command-boundary.txt" || fail_orchestration 'CB8 runtime boundary missing'
grep -Fq 'turnBoundary=Code+Build-only' "$PKG/metadata/command-boundary.txt" || fail_orchestration 'CB8 turn boundary missing'
grep -Fq 'exactArithmeticBackend=GMP' "$PKG/metadata/command-boundary.txt" || fail_orchestration 'GMP boundary missing'
grep -Fq 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' "$PKG/metadata/CMakeCache.txt" || fail_orchestration 'GMP option disabled'
grep -Fq 'libgmpxx.so' "$PKG/metadata/gmp-evidence.txt" || fail_orchestration 'GMPXX evidence missing'
grep -Fq 'libgmp.so' "$PKG/metadata/gmp-evidence.txt" || fail_orchestration 'GMP evidence missing'
[[ "$(find "$PKG/metadata" -maxdepth 1 -type f -name 'source-status-*.txt' | wc -l)" -eq 5 ]] || fail_orchestration 'source-status receipt count mismatch'
for receipt in "$PKG"/metadata/source-status-*.txt; do [[ ! -s "$receipt" ]] || fail_orchestration "dirty source receipt $(basename "$receipt")"; done
expected_targets=$'directional_surface_cell_authority_kernel_tests\ndirectional_surface_cell_completion_tests\ndirectional_surface_cell_producer_tests\ndirectional_surface_cell_validation_tests'
[[ "$(LC_ALL=C sort "$PKG/metadata/compiled-targets.txt")" == "$expected_targets" ]] || fail_orchestration 'compiled target set mismatch'
SOURCE_TAR="$PKG/source/source-${SOURCE_SHA}.tar.gz"
[[ -f "$SOURCE_TAR" && "$(sha_file "$SOURCE_TAR")" == "$SOURCE_TAR_SHA256" ]] || fail_orchestration 'source archive mismatch'
for b in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do
  [[ -f "$PKG/bin/$b" ]] || fail_orchestration "missing owner binary $b"
  [[ "$(stat -c '%a' "$PKG/bin/$b")" == 755 && -x "$PKG/bin/$b" ]] || fail_orchestration "wrong owner executable mode $b"
done
census_tree "$PKG" "$RESULT/package-census-before.tsv"
tar -xzf "$SOURCE_TAR" -C "$SRC"
census_tree "$SRC" "$RESULT/source-census-before.tsv"

# Selector430 and static owner authority derive only from immutable packaged source.
SELECTOR="$SRC/$SELECTOR_REL"
python3 - "$SELECTOR" "$SELECTOR_SHA256" "$PREFIX427_SHA256" "$SELECTOR_ROWS" "$SELECTOR_BYTES" "$RESULT/selector-authority.txt" <<'PY'
import hashlib,pathlib,sys
p=pathlib.Path(sys.argv[1]); expected=sys.argv[2]; prefix=sys.argv[3]; rows=int(sys.argv[4]); size=int(sys.argv[5]); out=pathlib.Path(sys.argv[6]); b=p.read_bytes()
if b'\r' in b or not b.endswith(b'\n') or b.count(b'\n')!=rows or len(b)!=size or hashlib.sha256(b).hexdigest()!=expected: raise SystemExit('selector430 bytes mismatch')
lines=b.splitlines(keepends=True)
if any(x in (b'',b'\n') for x in lines): raise SystemExit('blank selector row')
if hashlib.sha256(b''.join(lines[:427])).hexdigest()!=prefix: raise SystemExit('selector427 prefix mismatch')
final=[x.decode().rstrip('\n') for x in lines[-3:]]
want=['M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated','M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder','M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection']
if final!=want: raise SystemExit('selector430 final rows mismatch')
out.write_text(f'rows={rows}\nbytes={len(b)}\nsha256={expected}\nfirst427_sha256={prefix}\nfinal1={final[0]}\nfinal2={final[1]}\nfinal3={final[2]}\n')
PY
python3 - "$SRC" "$SELECTOR" "$RESULT/identity-map.tsv" "$RESULT/owner-distribution.tsv" <<'PY'
import pathlib,re,sys
root=pathlib.Path(sys.argv[1]); selector=pathlib.Path(sys.argv[2]).read_text().splitlines(); out=pathlib.Path(sys.argv[3]); dist=pathlib.Path(sys.argv[4])
cm=(root/'cmake/DirectionalTests.cmake').read_text(); order=['directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests']
def cpp(t): return [x.strip() for x in t.splitlines() if x.strip().endswith('.cpp')]
m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cm,re.S)
if not m: raise SystemExit('producer source set missing')
targets={order[1]:cpp(m.group(1))}
for t in (order[0],order[2],order[3]):
    m=re.search(r'add_executable\(\s*'+re.escape(t)+r'(.*?)\)\s*\n',cm,re.S)
    if not m: raise SystemExit('target block missing '+t)
    targets[t]=cpp(m.group(1))
pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)'); owners={}
for t in order:
    for rel in targets[t]:
        p=root/rel
        if not p.is_file(): raise SystemExit('owner source missing '+str(p))
        for s,n in pat.findall(p.read_text(errors='replace')): owners.setdefault(f'{s}.{n}',[]).append((t,rel))
counts={t:0 for t in order}; rows=[]
for o,i in enumerate(selector,1):
    f=owners.get(i,[])
    if len(f)!=1: raise SystemExit(f'owner count {len(f)} for {o}:{i}')
    t,src=f[0]; counts[t]+=1; rows.append((o,i,t,src))
expected={order[0]:31,order[1]:283,order[2]:75,order[3]:41}
if counts!=expected: raise SystemExit('owner census mismatch '+repr(counts))
out.write_text('ordinal\tidentity\tbinary\tsource\n'+''.join(f'{o}\t{i}\t{t}\t{s}\n' for o,i,t,s in rows))
dist.write_text('binary\tcount\n'+''.join(f'{t}\t{counts[t]}\n' for t in order))
PY
[[ "$(($(wc -l < "$RESULT/identity-map.tsv")-1))" -eq 430 ]] || fail_orchestration 'identity map cardinality mismatch'

# Construct immutable execution view by copying, never repairing, packaged bytes/modes and packaged fixtures.
for b in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do cp -a "$PKG/bin/$b" "$EXEC_VIEW/bin/"; done
cp -a "$SRC/benchmarks/fixtures" "$EXEC_VIEW/test-data/benchmarks/"
grep -Fq 'executableDirectory.parent_path() / "test-data"' "$SRC/tests/TestFixturePaths.h" || fail_orchestration 'fixture root rule drifted'
[[ -f "$EXEC_VIEW/test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj" ]] || fail_orchestration 'known fixture missing'
for b in "$EXEC_VIEW"/bin/*; do [[ "$(stat -c '%a' "$b")" == 755 && -x "$b" ]] || fail_orchestration "execution-view mode mismatch $(basename "$b")"; done
census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-before.tsv"
preflight_completed=true

printf 'ordinal\tidentity\tbinary\tselected\tskipped\tresult\texit\traw_log_sha256\n' > "$RESULT/process-ledger.tsv"
runtime_started=true
attempted=0
while IFS=$'\t' read -r ordinal identity binary source; do
  [[ "$ordinal" == ordinal ]] && continue
  attempted=$((attempted+1)); work="$PROC/$ordinal"; raw="$RESULT/raw/${ordinal}.log"; mkdir -p "$work"
  set +e
  (cd "$work" && GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw" 2>&1
  code=$?
  set -e
  selected="$(grep -c '^\[ RUN      \] ' "$raw" || true)"; skipped="$(grep -c '^\[  SKIPPED \] ' "$raw" || true)"; passed="$(grep -c '^\[       OK \] ' "$raw" || true)"
  if [[ "$selected" -ne 1 ]]; then result='INVALID_SELECTION'; mark_orchestration "selector ordinal $ordinal selected $selected tests"; else
    if [[ "$skipped" -gt 0 ]]; then result='SKIP'; semantic_non_green=true
    elif [[ "$code" -eq 0 && "$passed" -eq 1 ]]; then result='PASS'
    elif [[ "$code" -ge 128 ]]; then result='CRASH'; semantic_non_green=true
    else result='RED'; semantic_non_green=true; fi
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$ordinal" "$identity" "$binary" "$selected" "$skipped" "$result" "$code" "$(sha_file "$raw")" >> "$RESULT/process-ledger.tsv"
  [[ "$orchestration_failure" == false ]] || break
done < "$RESULT/identity-map.tsv"
[[ "$attempted" -eq 430 ]] && runtime_completed=true

python3 - "$RESULT/process-ledger.tsv" "$RESULT/summary.txt" <<'PY'
import collections,pathlib,sys
p=pathlib.Path(sys.argv[1]); out=pathlib.Path(sys.argv[2]); rows=[]
for line in p.read_text().splitlines()[1:]:
    a=line.split('\t'); rows.append(dict(ordinal=a[0],identity=a[1],binary=a[2],selected=int(a[3]),skipped=int(a[4]),result=a[5],exit=int(a[6]),raw=a[7]))
res=collections.Counter(r['result'] for r in rows); owners=collections.Counter(r['binary'] for r in rows if r['result']=='PASS')
lines=[f'attempted={len(rows)}',f'unexecuted={430-len(rows)}']+[f'{k.lower()}={res.get(k,0)}' for k in ['PASS','RED','SKIP','CRASH','INVALID_SELECTION']]
for b in ['directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests']: lines.append(f'pass_{b}={owners.get(b,0)}')
out.write_text('\n'.join(lines)+'\n'); print(out.read_text(),end='')
PY

# Mandatory immutable postflight, even after a runtime selection fault.
census_tree "$PKG" "$RESULT/package-census-after.tsv"; census_tree "$SRC" "$RESULT/source-census-after.tsv"; census_tree "$EXEC_VIEW" "$RESULT/execution-view-census-after.tsv"
cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" || mark_orchestration 'package postflight mutation'
cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" || mark_orchestration 'source postflight mutation'
cmp -s "$RESULT/execution-view-census-before.tsv" "$RESULT/execution-view-census-after.tsv" || mark_orchestration 'execution view postflight mutation'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$MANIFEST_SHA256" ]] || mark_orchestration 'postflight manifest digest mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) > "$RESULT/package-manifest-check-after.txt" || mark_orchestration 'postflight manifest verification failed'
[[ "$(sha_file "$SELECTOR")" == "$SELECTOR_SHA256" ]] || mark_orchestration 'postflight selector digest mismatch'
postflight_complete=true

# Mechanical-green computation is evidence only; semantic failures still exit 0 when orchestration is valid.
pass="$(awk -F= '$1=="pass"{print $2}' "$RESULT/summary.txt")"; red="$(awk -F= '$1=="red"{print $2}' "$RESULT/summary.txt")"; skip="$(awk -F= '$1=="skip"{print $2}' "$RESULT/summary.txt")"; crash="$(awk -F= '$1=="crash"{print $2}' "$RESULT/summary.txt")"; invalid="$(awk -F= '$1=="invalid_selection"{print $2}' "$RESULT/summary.txt")"
mechanically_green=false
if [[ "$runtime_completed" == true && "$pass" -eq 430 && "$red" -eq 0 && "$skip" -eq 0 && "$crash" -eq 0 && "$invalid" -eq 0 ]] && grep -Fqx 'pass_directional_surface_cell_authority_kernel_tests=31' "$RESULT/summary.txt" && grep -Fqx 'pass_directional_surface_cell_producer_tests=283' "$RESULT/summary.txt" && grep -Fqx 'pass_directional_surface_cell_completion_tests=75' "$RESULT/summary.txt" && grep -Fqx 'pass_directional_surface_cell_validation_tests=41' "$RESULT/summary.txt"; then mechanically_green=true; fi
printf 'mechanically_green=%s\n' "$mechanically_green" > "$RESULT/gate-result.txt"
[[ "$mechanically_green" == true ]] || semantic_non_green=true
