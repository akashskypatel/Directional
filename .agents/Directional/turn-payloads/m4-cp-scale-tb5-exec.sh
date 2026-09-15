#!/usr/bin/env bash
set -euo pipefail

TURN=M4-CP-SCALE-TB5-EXEC
ARTIFACT_ID=10407605295
ARTIFACT_NAME=m4-cp-scale-cb6-result-34994665690
EXPECTED_ZIP_SHA=29f68b3880fb9d2d521aa74541112af9de5d35fdc982decfdbc8067305e747e5
EXPECTED_MANIFEST_SHA=802c57feb9cb01293ac61d1795d4ba9b1c848c8b78898ed54340bd55c256d3a7
EXPECTED_SOURCE_ARCHIVE_SHA=55bbe23520e7398fcf2e639623492007d445dd219ca1960cb5f63b301cd7b0c3
EXPECTED_SELECTOR_SHA=f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca
EXPECTED_PREFIX423_SHA=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343
EXPECTED_SOURCE=0d8e4aa3472fae26c22d49bc0d81acc5e98378d3
ROW424=M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle

WORK="${RUNNER_TEMP}/m4-cp-scale-tb5-exec"
ZIP="$WORK/candidate.zip"
PKG="$WORK/package"
SOURCE="$WORK/source"
VIEW="$WORK/execution-view"
RUNTIME="$WORK/runtime"
RESULT="$WORK/evidence"
PUBLISH="$RUNNER_TEMP/tb5-publish"
PUBLISH_RESULT="$PUBLISH/result"
PUBLISH_LOG="$PUBLISH/log"
SELECTOR="$SOURCE/.agents/Directional/Architecture_M4_CP_SCALE_CB6_Required_Green_Selector_424.txt"
OWNER_MAP="$RESULT/selector424-owner-map.tsv"
PROCESS_LEDGER="$RESULT/selector424-process-ledger.tsv"
RUNLOG="$PUBLISH_LOG/tb5-runtime.log"

runtime_started=false
runtime_completed=false
preflight_complete=false
postflight_complete=false
selection_integrity=true
mechanical_green=false
semantic_red_count=0
skip_count=0
crash_count=0
timeout_count=0
selection_mismatch_count=0
unexecuted_count=424
configure_execution=false
compile_execution=false
relink_execution=false
repair_execution=false
generated_discovery=false
mutation_execution=false
benchmark_execution=false

rm -rf "$WORK" "$PUBLISH"
mkdir -p "$PKG" "$SOURCE" "$VIEW/bin" "$VIEW/lib" "$VIEW/test-data/benchmarks" \
  "$RUNTIME/selector" "$RESULT/raw/selector" "$RESULT/resources/selector" \
  "$PUBLISH_RESULT" "$PUBLISH_LOG"
: > "$RUNLOG"
exec > >(tee -a "$RUNLOG") 2>&1

sha_file(){ sha256sum "$1" | awk '{print $1}'; }

census_tree(){
  python3 - "$1" "$2" <<'PY'
import hashlib, os, pathlib, stat, sys
root = pathlib.Path(sys.argv[1]).resolve()
out = pathlib.Path(sys.argv[2])
rows = []
for p in [root, *sorted(root.rglob('*'), key=lambda q: q.relative_to(root).as_posix())]:
    rel = '.' if p == root else p.relative_to(root).as_posix()
    s = p.lstat()
    mode = f'{stat.S_IMODE(s.st_mode):04o}'
    if stat.S_ISREG(s.st_mode):
        h = hashlib.sha256()
        with p.open('rb') as f:
            for chunk in iter(lambda: f.read(1048576), b''):
                h.update(chunk)
        kind, digest, target = 'file', h.hexdigest(), '-'
    elif stat.S_ISDIR(s.st_mode):
        kind, digest, target = 'directory', '-', '-'
    elif stat.S_ISLNK(s.st_mode):
        kind, digest, target = 'symlink', '-', os.readlink(p)
    else:
        kind, digest, target = 'other', '-', '-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{s.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows), encoding='utf-8')
PY
}

postflight(){
  set +e
  local ok=true
  census_tree "$PKG" "$RESULT/package-census-after.tsv" || ok=false
  census_tree "$SOURCE" "$RESULT/source-census-after.tsv" || ok=false
  census_tree "$VIEW" "$RESULT/execution-view-after.tsv" || ok=false
  cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" || ok=false
  cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" || ok=false
  cmp -s "$RESULT/execution-view-before.tsv" "$RESULT/execution-view-after.tsv" || ok=false
  (cd "$PKG" && sha256sum -c SHA256SUMS) > "$RESULT/postflight-package-sha256-check.txt" 2>&1 || ok=false
  python3 - "$SELECTOR" "$EXPECTED_SELECTOR_SHA" "$EXPECTED_PREFIX423_SHA" "$ROW424" > "$RESULT/postflight-selector-check.txt" <<'PY' || ok=false
from pathlib import Path
import hashlib, sys
p=Path(sys.argv[1]); expected=sys.argv[2]; prefix_expected=sys.argv[3]; row424=sys.argv[4]
b=p.read_bytes()
assert b.endswith(b'\n'), 'selector lacks final LF'
assert b'\r' not in b, 'selector contains CR'
rows=b.splitlines(keepends=True)
assert len(rows)==424
assert all(r.endswith(b'\n') and r.strip() for r in rows)
ids=[r[:-1].decode('utf-8') for r in rows]
assert len(set(ids))==424
full=hashlib.sha256(b).hexdigest(); prefix=hashlib.sha256(b''.join(rows[:423])).hexdigest()
assert full==expected, (full,expected)
assert prefix==prefix_expected, (prefix,prefix_expected)
assert ids[423]==row424
print(f'rows={len(rows)}')
print(f'selector_sha256={full}')
print(f'prefix423_sha256={prefix}')
print(f'row424={ids[423]}')
PY
  {
    echo "package_census_equal=$(cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" && echo true || echo false)"
    echo "source_census_equal=$(cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" && echo true || echo false)"
    echo "execution_view_census_equal=$(cmp -s "$RESULT/execution-view-before.tsv" "$RESULT/execution-view-after.tsv" && echo true || echo false)"
    echo "package_manifest_verified=$(grep -q ': OK$' "$RESULT/postflight-package-sha256-check.txt" && echo true || echo false)"
    echo "selector_sha256=$(sha_file "$SELECTOR" 2>/dev/null || echo unavailable)"
  } > "$RESULT/postflight-immutability.txt"
  [[ "$ok" == true ]] && postflight_complete=true || postflight_complete=false
  set -e
}

summarize_ledger(){
  python3 - "$PROCESS_LEDGER" "$OWNER_MAP" "$RESULT/selector424-summary.txt" <<'PY'
import csv, collections, pathlib, sys
ledger=pathlib.Path(sys.argv[1]); owners=pathlib.Path(sys.argv[2]); out=pathlib.Path(sys.argv[3])
rows=list(csv.DictReader(ledger.open(), delimiter='\t')) if ledger.exists() else []
own=list(csv.DictReader(owners.open(), delimiter='\t')) if owners.exists() else []
rc=collections.Counter(r['result'] for r in rows)
bc=collections.Counter(r['owner'] for r in rows)
text=''.join([
 f'executed={len(rows)}\n', f'pass={rc["PASS"]}\n', f'red={rc["RED"]}\n',
 f'skip={rc["SKIP"]}\n', f'crash={rc["CRASH"]}\n', f'timeout={rc["TIMEOUT"]}\n',
 f'selectionMismatch={rc["SELECTION_MISMATCH"]}\n', f'unexecuted={424-len(rows)}\n',
 f'authorityKernelExecuted={bc["authority-kernel"]}\n', f'producerExecuted={bc["producer"]}\n',
 f'completionExecuted={bc["completion"]}\n', f'validationExecuted={bc["validation"]}\n',
 f'ownerMapRows={len(own)}\n'])
out.write_text(text, encoding='utf-8'); print(text,end='')
PY
}

finalize(){
  local rc=$?
  set +e
  if [[ "$preflight_complete" == true && "$postflight_complete" != true ]]; then
    postflight
  fi
  summarize_ledger || true
  executed=$(sed -n 's/^executed=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  pass=$(sed -n 's/^pass=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  red=$(sed -n 's/^red=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  skip=$(sed -n 's/^skip=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  crash=$(sed -n 's/^crash=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  sm=$(sed -n 's/^selectionMismatch=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  unexecuted=$(sed -n 's/^unexecuted=//p' "$RESULT/selector424-summary.txt" 2>/dev/null)
  if [[ "$rc" -eq 0 && "$preflight_complete" == true && "$postflight_complete" == true && \
        "${executed:-0}" -eq 424 && "${pass:-0}" -eq 424 && "${red:-0}" -eq 0 && \
        "${skip:-0}" -eq 0 && "${crash:-0}" -eq 0 && "${sm:-0}" -eq 0 && "${unexecuted:-424}" -eq 0 ]]; then
    mechanical_green=true
  fi
  {
    echo "mechanical_exit=$rc"
    echo "mechanicalGreen=$mechanical_green"
    echo "preflightComplete=$preflight_complete"
    echo "runtimeStarted=$runtime_started"
    echo "runtimeCompleted=$runtime_completed"
    echo "postflightComplete=$postflight_complete"
    echo "selectionIntegrity=$selection_integrity"
    echo "timeoutCount=$timeout_count"
    echo "crashCount=$crash_count"
    echo "skipCount=$skip_count"
    echo "selectionMismatchCount=$selection_mismatch_count"
  } > "$RESULT/final-status.txt"
  {
    echo "configureExecution=$configure_execution"
    echo "compileExecution=$compile_execution"
    echo "relinkExecution=$relink_execution"
    echo "repairExecution=$repair_execution"
    echo "generatedDiscovery=$generated_discovery"
    echo "mutationExecution=$mutation_execution"
    echo "benchmarkExecution=$benchmark_execution"
  } > "$RESULT/execution-prohibitions.txt"
  (cd "$RESULT" && find . -type f ! -name SHA256SUMS ! -name '*.zip' -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS)
  (cd "$RESULT" && sha256sum -c SHA256SUMS) > "$PUBLISH_RESULT/evidence-manifest-check.txt" 2>&1
  (cd "$WORK" && zip -qr "$PUBLISH_RESULT/Directional__M4-CP-SCALE-TB5-EXEC__evidence.zip" evidence)
  evidence_sha=$(sha_file "$PUBLISH_RESULT/Directional__M4-CP-SCALE-TB5-EXEC__evidence.zip")
  manifest_sha=$(sha_file "$RESULT/SHA256SUMS")
  manifest_entries=$(grep -cve '^[[:space:]]*$' "$RESULT/SHA256SUMS")
  {
    echo "turn=$TURN"
    echo "artifact_id=$ARTIFACT_ID"
    echo "artifact_name=$ARTIFACT_NAME"
    echo "semantic_source=$EXPECTED_SOURCE"
    echo "selector_rows=424"
    echo "selector_sha256=$EXPECTED_SELECTOR_SHA"
    echo "selector423_prefix_sha256=$EXPECTED_PREFIX423_SHA"
    echo "evidence_zip_sha256=$evidence_sha"
    echo "evidence_manifest_sha256=$manifest_sha"
    echo "evidence_manifest_entries=$manifest_entries"
    echo "mechanical_exit=$rc"
    echo "mechanicalGreen=$mechanical_green"
    echo "runtimeExecution=$runtime_started"
  } > "$PUBLISH_RESULT/publication.env"
  cp "$RESULT/final-status.txt" "$PUBLISH_RESULT/final-status.txt"
  cp "$RESULT/selector424-summary.txt" "$PUBLISH_RESULT/selector424-summary.txt" 2>/dev/null || true
  echo "TB5_FINAL mechanical_exit=$rc mechanicalGreen=$mechanical_green runtimeStarted=$runtime_started runtimeCompleted=$runtime_completed postflightComplete=$postflight_complete evidence_zip_sha256=$evidence_sha"
  exit "$rc"
}
trap finalize EXIT

for tool in gh jq unzip zip tar sha256sum python3 /usr/bin/time; do
  command -v "$tool" >/dev/null || { echo "required runner tool missing: $tool" >&2; exit 10; }
done

# Exact artifact identity and immutable archive bytes.
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}" > "$RESULT/artifact-metadata.json"
jq -e --arg name "$ARTIFACT_NAME" --arg digest "sha256:$EXPECTED_ZIP_SHA" --argjson id "$ARTIFACT_ID" \
  '.id == $id and .name == $name and .expired == false and .digest == $digest' "$RESULT/artifact-metadata.json" >/dev/null
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" > "$ZIP"
[[ "$(sha_file "$ZIP")" == "$EXPECTED_ZIP_SHA" ]]
unzip -q "$ZIP" -d "$PKG"

# Package manifest, exact compile metadata, clean source authority, and GMP evidence.
[[ "$(grep -cve '^[[:space:]]*$' "$PKG/SHA256SUMS")" -eq 28 ]]
! grep -Eq '(^|[ /])SHA256SUMS$' "$PKG/SHA256SUMS"
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA" ]]
(cd "$PKG" && sha256sum -c SHA256SUMS) > "$RESULT/preflight-package-sha256-check.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE" ]]
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == 0 && "$(cat "$PKG/metadata/preflight-exit-code.txt")" == 0 ]]
for f in "$PKG"/metadata/source-status-*.txt; do [[ ! -s "$f" ]]; done
for token in runtimeExecution=false turnBoundary=Code+Build-only exactArithmeticBackend=GMP manifestExcludesSelf=true; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt"
done
grep -Fq 'GMPXX_LIBRARIES:FILEPATH=/usr/lib/x86_64-linux-gnu/libgmpxx.so' "$PKG/metadata/gmp-evidence.txt"
grep -Fq 'GMP_LIBRARIES:FILEPATH=/usr/lib/x86_64-linux-gnu/libgmp.so' "$PKG/metadata/gmp-evidence.txt"
grep -Eq 'libgmpxx\.so.*libgmp\.so|libgmp\.so.*libgmpxx\.so' "$PKG/metadata/gmp-evidence.txt"

required_bins=(
  directional_surface_cell_authority_kernel_tests
  directional_surface_cell_producer_tests
  directional_surface_cell_completion_tests
  directional_surface_cell_validation_tests
)
printf 'binary\tmode\tbytes\tsha256\n' > "$RESULT/owner-binary-census.tsv"
for n in "${required_bins[@]}"; do
  p="$PKG/bin/$n"; [[ -x "$p" ]]
  printf '%s\t%s\t%s\t%s\n' "$n" "$(stat -c '%a' "$p")" "$(stat -c '%s' "$p")" "$(sha_file "$p")" >> "$RESULT/owner-binary-census.tsv"
  ldd "$p" > "$RESULT/ldd-$n.txt"
  ! grep -Fq 'not found' "$RESULT/ldd-$n.txt"
done
grep -Eq 'libgmpxx\.so' "$RESULT/ldd-directional_surface_cell_producer_tests.txt"
grep -Eq 'libgmp\.so' "$RESULT/ldd-directional_surface_cell_producer_tests.txt"

mapfile -t src_archives < <(find "$PKG/source" -maxdepth 1 -type f -name 'source-*.tar.gz' -print)
[[ ${#src_archives[@]} -eq 1 ]]
[[ "$(sha_file "${src_archives[0]}")" == "$EXPECTED_SOURCE_ARCHIVE_SHA" ]]
tar -xzf "${src_archives[0]}" -C "$SOURCE"

python3 - "$SELECTOR" "$EXPECTED_SELECTOR_SHA" "$EXPECTED_PREFIX423_SHA" "$ROW424" > "$RESULT/preflight-selector-check.txt" <<'PY'
from pathlib import Path
import hashlib, sys
p=Path(sys.argv[1]); expected=sys.argv[2]; prefix_expected=sys.argv[3]; row424=sys.argv[4]
b=p.read_bytes()
assert b.endswith(b'\n'), 'selector lacks final LF'
assert b'\r' not in b, 'selector contains CR'
rows=b.splitlines(keepends=True)
assert len(rows)==424
assert all(r.endswith(b'\n') and r.strip() for r in rows)
ids=[r[:-1].decode('utf-8') for r in rows]
assert len(set(ids))==424
full=hashlib.sha256(b).hexdigest(); prefix=hashlib.sha256(b''.join(rows[:423])).hexdigest()
assert full==expected, (full,expected)
assert prefix==prefix_expected, (prefix,prefix_expected)
assert ids[423]==row424
print(f'rows={len(rows)}')
print(f'unique={len(set(ids))}')
print(f'selector_sha256={full}')
print(f'prefix423_sha256={prefix}')
print(f'row424={ids[423]}')
PY

# Re-derive exact ownership from the packaged test target source lists and exact TEST/TEST_F declarations.
python3 - "$SOURCE" "$SELECTOR" "$OWNER_MAP" <<'PY'
from pathlib import Path
import collections, re, sys
root=Path(sys.argv[1]); selector=Path(sys.argv[2]); out=Path(sys.argv[3])
cm=(root/'cmake/DirectionalTests.cmake').read_text(encoding='utf-8')
def command(anchor):
    start=cm.index(anchor); op=cm.index('(',start); depth=0
    for i in range(op,len(cm)):
        c=cm[i]
        if c=='(': depth+=1
        elif c==')':
            depth-=1
            if depth==0: return cm[op+1:i]
    raise AssertionError(anchor)
def paths(body): return re.findall(r'(tests/[A-Za-z0-9_./-]+\.cpp)',body)
owner_files={
 'producer': paths(command('set(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES')),
 'authority-kernel': paths(command('add_executable(\n  directional_surface_cell_authority_kernel_tests')),
 'completion': paths(command('add_executable(\n  directional_surface_cell_completion_tests')),
 'validation': paths(command('add_executable(\n  directional_surface_cell_validation_tests')),
}
owner_bin={
 'authority-kernel':'directional_surface_cell_authority_kernel_tests',
 'producer':'directional_surface_cell_producer_tests',
 'completion':'directional_surface_cell_completion_tests',
 'validation':'directional_surface_cell_validation_tests',
}
texts={(owner,rel):(root/rel).read_text(errors='replace') for owner,rels in owner_files.items() for rel in rels}
ids=[x for x in selector.read_text(encoding='utf-8').splitlines() if x]
rows=[]
for ordinal,ident in enumerate(ids,1):
    suite,test=ident.split('.',1)
    pat=re.compile(r'\bTEST(?:_F)?\s*\(\s*'+re.escape(suite)+r'\s*,\s*'+re.escape(test)+r'\s*\)')
    matches=[]
    for owner,rels in owner_files.items():
        for rel in rels:
            n=len(pat.findall(texts[(owner,rel)]))
            matches.extend([(owner,rel)]*n)
    assert len(matches)==1, (ident,matches)
    owner,rel=matches[0]
    rows.append((ordinal,ident,owner,owner_bin[owner],rel))
c=collections.Counter(r[2] for r in rows)
assert c==collections.Counter({'producer':278,'completion':75,'validation':41,'authority-kernel':30}), c
assert rows[-1][1]=='M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle'
assert rows[-1][2]=='producer'
out.write_text('ordinal\tidentity\towner\tbinary\tsource_definition\n'+''.join('\t'.join(map(str,r))+'\n' for r in rows),encoding='utf-8')
print(dict(c))
print('row424='+ '\t'.join(map(str,rows[-1])))
PY

# Fresh execution view; only packaged bytes and packaged fixture bytes are materialized.
cp -a "$PKG/bin/." "$VIEW/bin/"
cp -a "$PKG/lib/." "$VIEW/lib/"
cp -a "$SOURCE/benchmarks/fixtures" "$VIEW/test-data/benchmarks/"
for n in "${required_bins[@]}"; do
  [[ "$(sha_file "$PKG/bin/$n")" == "$(sha_file "$VIEW/bin/$n")" ]]
  [[ "$(stat -c '%a' "$PKG/bin/$n")" == "$(stat -c '%a' "$VIEW/bin/$n")" ]]
done
census_tree "$SOURCE/benchmarks/fixtures" "$RESULT/source-fixtures-census.tsv"
census_tree "$VIEW/test-data/benchmarks/fixtures" "$RESULT/execution-fixtures-census.tsv"
sed 's#^\.\t#\.\t#' "$RESULT/source-fixtures-census.tsv" > /dev/null
cmp -s "$RESULT/source-fixtures-census.tsv" "$RESULT/execution-fixtures-census.tsv"

census_tree "$PKG" "$RESULT/package-census-before.tsv"
census_tree "$SOURCE" "$RESULT/source-census-before.tsv"
census_tree "$VIEW" "$RESULT/execution-view-before.tsv"
{
  echo "artifact_id=$ARTIFACT_ID"
  echo "artifact_name=$ARTIFACT_NAME"
  echo "provider_zip_sha256=$EXPECTED_ZIP_SHA"
  echo "semantic_source=$EXPECTED_SOURCE"
  echo "source_archive_sha256=$EXPECTED_SOURCE_ARCHIVE_SHA"
  echo "package_manifest_sha256=$EXPECTED_MANIFEST_SHA"
  echo "package_manifest_entries=28"
  echo "selector_rows=424"
  echo "selector_sha256=$EXPECTED_SELECTOR_SHA"
  echo "selector423_prefix_sha256=$EXPECTED_PREFIX423_SHA"
  echo "row424=$ROW424"
  echo "owner_census=30/278/75/41"
  echo "runtimeExecution_before_tb=false"
} > "$RESULT/immutable-input.txt"
preflight_complete=true

# Predeclare the full ordered surface before executing any row.
cp "$OWNER_MAP" "$RESULT/selector424-predeclared.tsv"
printf 'ordinal\tidentity\towner\tbinary\tsource_definition\texit\tselected\tok\tskipped\telapsed_ms\tresult\tstdout\tstderr\ttime_receipt\n' > "$PROCESS_LEDGER"

runtime_started=true
mechanical_rc=0
while IFS=$'\t' read -r ordinal identity owner binary source_definition; do
  [[ "$ordinal" == ordinal ]] && continue
  stem=$(printf 'ordinal-%03d' "$ordinal")
  procdir="$RUNTIME/selector/$stem"
  stdout="$RESULT/raw/selector/$stem.stdout.txt"
  stderr="$RESULT/raw/selector/$stem.stderr.txt"
  timerec="$RESULT/resources/selector/$stem.time.txt"
  mkdir -p "$procdir"
  start_ns=$(date +%s%N)
  set +e
  (cd "$procdir" && /usr/bin/time -v -o "$timerec" env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
    "$VIEW/bin/$binary" "--gtest_filter=$identity") >"$stdout" 2>"$stderr"
  code=$?
  set -e
  end_ns=$(date +%s%N)
  elapsed_ms=$(( (end_ns-start_ns)/1000000 ))
  selected=$({ grep -Ehc '^\[ RUN      \] ' "$stdout" "$stderr" || true; } | awk '{s+=$1} END{print s+0}')
  ok=$({ grep -Ehc '^\[       OK \] ' "$stdout" "$stderr" || true; } | awk '{s+=$1} END{print s+0}')
  skipped=$({ grep -Ehc '^\[  SKIPPED \] ' "$stdout" "$stderr" || true; } | awk '{s+=$1} END{print s+0}')
  result=RED
  if [[ "$selected" -ne 1 ]]; then
    result=SELECTION_MISMATCH; selection_integrity=false; selection_mismatch_count=$((selection_mismatch_count+1)); mechanical_rc=31
  elif [[ "$skipped" -ne 0 ]]; then
    result=SKIP; skip_count=$((skip_count+1)); mechanical_rc=32
  elif [[ "$code" -ge 128 ]]; then
    result=CRASH; crash_count=$((crash_count+1)); mechanical_rc=33
  elif [[ "$code" -eq 0 && "$ok" -eq 1 ]]; then
    result=PASS
  else
    result=RED; semantic_red_count=$((semantic_red_count+1)); [[ "$mechanical_rc" -eq 0 ]] && mechanical_rc=40
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
    "$ordinal" "$identity" "$owner" "$binary" "$source_definition" "$code" "$selected" "$ok" "$skipped" "$elapsed_ms" "$result" \
    "raw/selector/$stem.stdout.txt" "raw/selector/$stem.stderr.txt" "resources/selector/$stem.time.txt" >> "$PROCESS_LEDGER"
  printf '%03d/424 %-18s exit=%s selected=%s ok=%s skipped=%s elapsed_ms=%s %s\n' \
    "$ordinal" "$result" "$code" "$selected" "$ok" "$skipped" "$elapsed_ms" "$identity"
  # Selection mismatch/SKIP/crash is orchestration/validation failure. Semantic RED is allowed to finish the frozen surface.
  if [[ "$result" == SELECTION_MISMATCH || "$result" == SKIP || "$result" == CRASH ]]; then
    break
  fi
done < "$OWNER_MAP"

executed=$(( $(wc -l < "$PROCESS_LEDGER") - 1 ))
unexecuted_count=$((424-executed))
[[ "$executed" -eq 424 ]] && runtime_completed=true || runtime_completed=false
summarize_ledger
postflight

if [[ "$mechanical_rc" -eq 0 ]]; then
  pass=$(sed -n 's/^pass=//p' "$RESULT/selector424-summary.txt")
  red=$(sed -n 's/^red=//p' "$RESULT/selector424-summary.txt")
  skip=$(sed -n 's/^skip=//p' "$RESULT/selector424-summary.txt")
  crash=$(sed -n 's/^crash=//p' "$RESULT/selector424-summary.txt")
  sm=$(sed -n 's/^selectionMismatch=//p' "$RESULT/selector424-summary.txt")
  unexecuted=$(sed -n 's/^unexecuted=//p' "$RESULT/selector424-summary.txt")
  ak=$(sed -n 's/^authorityKernelExecuted=//p' "$RESULT/selector424-summary.txt")
  pr=$(sed -n 's/^producerExecuted=//p' "$RESULT/selector424-summary.txt")
  co=$(sed -n 's/^completionExecuted=//p' "$RESULT/selector424-summary.txt")
  va=$(sed -n 's/^validationExecuted=//p' "$RESULT/selector424-summary.txt")
  [[ "$pass" -eq 424 && "$red" -eq 0 && "$skip" -eq 0 && "$crash" -eq 0 && "$sm" -eq 0 && "$unexecuted" -eq 0 ]]
  [[ "$ak" -eq 30 && "$pr" -eq 278 && "$co" -eq 75 && "$va" -eq 41 ]]
  [[ "$postflight_complete" == true ]]
  last_identity=$(awk -F '\t' 'NR==425{print $2}' "$PROCESS_LEDGER")
  last_result=$(awk -F '\t' 'NR==425{print $11}' "$PROCESS_LEDGER")
  [[ "$last_identity" == "$ROW424" && "$last_result" == PASS ]]
else
  exit "$mechanical_rc"
fi

runtime_completed=true
exit 0
