#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"

TURN_ID='M4-CP-SCALE-TB12-R8-EXEC'
ARTIFACT_ID=10542249210
EXPECTED_ARTIFACT_NAME='m4-cp-scale-cb21-result-35334247422'
EXPECTED_ZIP_SHA='a64352a9524c4f114865948bb84226a317eaa1affa2e7a7fcfeea62352c7ef6c'
EXPECTED_SOURCE='ea7b15f53e5e92cb034c855d52c17eaa2d8928d1'
EXPECTED_SOURCE_ARCHIVE_SHA='7a8c8f9c866dfc51580975d64e6dda5001291780e666d1491a6aee2a39a858e7'
EXPECTED_MANIFEST_SHA='88e3f454c963af481df96b5fea4b5450b904c707a6dc5ad1f9299d87ae55611c'
SELECTOR_REL='.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt'
EXPECTED_SELECTOR_SHA='41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114'
EXPECTED_FIRST425_SHA='e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b'
EXPECTED_OBJ_SHA='c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3'
EXPECTED_RAWFIELD_SHA='7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e'
EXPECTED_META_SHA='22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76'

ROOT="${RUNNER_TEMP}/${TURN_ID}"
PKG="$ROOT/package"
SRC="$ROOT/source"
VIEW="$ROOT/execution-view"
RESULT="${RUNNER_TEMP}/${TURN_ID}-result"
LOG="${RUNNER_TEMP}/${TURN_ID}.log"
ZIP="$ROOT/artifact.zip"
RUNTIME="$ROOT/runtime"
rm -rf "$ROOT" "$RESULT"; mkdir -p "$PKG" "$SRC" "$VIEW/bin" "$RESULT/raw" "$RUNTIME"
: > "$LOG"; exec > >(tee -a "$LOG") 2>&1

orchestration_failure=false
semantic_red=false
runtime_started=false
postflight_complete=false
benchmarkExecuted=0
configureExecuted=0
compileExecuted=0
relinkExecuted=0
generatedDiscovery=0
packageRepair=0
modeRepair=0
mutationPerformed=0
stop_reason='not_started'

sha() { sha256sum "$1" | awk '{print $1}'; }
fail_orch() { orchestration_failure=true; stop_reason="orchestration:$*"; echo "ORCHESTRATION_FAILURE: $*" >&2; return 90; }

census_tree() {
  python3 - "$1" "$2" <<'PY'
import hashlib, os, pathlib, stat, sys
root=pathlib.Path(sys.argv[1]).resolve(); out=pathlib.Path(sys.argv[2]); rows=[]
for p in [root,*sorted(root.rglob('*'), key=lambda q:q.relative_to(root).as_posix())]:
    rel='.' if p==root else p.relative_to(root).as_posix(); st=p.lstat(); mode=format(stat.S_IMODE(st.st_mode),'o')
    if stat.S_ISREG(st.st_mode):
        h=hashlib.sha256();
        with p.open('rb') as f:
            for b in iter(lambda:f.read(1048576),b''): h.update(b)
        kind,digest,target='file',h.hexdigest(),'-'
    elif stat.S_ISDIR(st.st_mode): kind,digest,target='directory','-','-'
    elif stat.S_ISLNK(st.st_mode): kind,digest,target='symlink','-',os.readlink(p)
    else: kind,digest,target='other','-','-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{st.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows))
PY
}

postflight() {
  census_tree "$PKG" "$RESULT/package-census-after.tsv"
  census_tree "$SRC" "$RESULT/source-census-after.tsv"
  census_tree "$VIEW" "$RESULT/execution-view-after.tsv"
  cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" || { fail_orch 'package census changed'; return 90; }
  cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" || { fail_orch 'source census changed'; return 90; }
  cmp -s "$RESULT/execution-view-before.tsv" "$RESULT/execution-view-after.tsv" || { fail_orch 'execution-view census changed'; return 90; }
  [[ "$(sha "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA" ]] || { fail_orch 'manifest hash changed'; return 90; }
  [[ "$(sha "$PKG/source/source-${EXPECTED_SOURCE}.tar.gz")" == "$EXPECTED_SOURCE_ARCHIVE_SHA" ]] || { fail_orch 'source archive hash changed'; return 90; }
  selector="$SRC/$SELECTOR_REL"
  [[ "$(wc -l < "$selector" | tr -d ' ')" == 426 && "$(sha "$selector")" == "$EXPECTED_SELECTOR_SHA" ]] || { fail_orch 'selector426 postflight drift'; return 90; }
  [[ "$(head -n 425 "$selector" | sha256sum | awk '{print $1}')" == "$EXPECTED_FIRST425_SHA" ]] || { fail_orch 'first425 postflight drift'; return 90; }
  for spec in \
    "benchmarks/fixtures/milestone-g/genus_two.obj:$EXPECTED_OBJ_SHA" \
    "benchmarks/fixtures/milestone-g/genus_two.rawfield:$EXPECTED_RAWFIELD_SHA" \
    "benchmarks/fixtures/milestone-g/genus_two.fixturemeta.json:$EXPECTED_META_SHA"; do
      p="${spec%%:*}"; h="${spec#*:}"; [[ "$(sha "$SRC/$p")" == "$h" ]] || { fail_orch "fixture drift $p"; return 90; }
  done
  postflight_complete=true
}

package_evidence() {
  status=$?
  if [[ "$status" -ne 0 && "$orchestration_failure" != true && "$semantic_red" != true ]]; then orchestration_failure=true; stop_reason="orchestration_unhandled_exit_${status}"; fi
  set +e
  if [[ -f "$RESULT/ledger.tsv" ]]; then sha256sum "$RESULT/ledger.tsv" > "$RESULT/ledger.sha256"; fi
  cat > "$RESULT/execution-boundary.env" <<META
turn=$TURN_ID
orchestration_failure=$orchestration_failure
semantic_red=$semantic_red
runtime_started=$runtime_started
postflight_complete=$postflight_complete
stop_reason=$stop_reason
benchmarkExecuted=$benchmarkExecuted
configureExecuted=$configureExecuted
compileExecuted=$compileExecuted
relinkExecuted=$relinkExecuted
generatedDiscovery=$generatedDiscovery
packageRepair=$packageRepair
modeRepair=$modeRepair
mutationPerformed=$mutationPerformed
META
  (cd "$RESULT" && find . -type f ! -name 'SHA256SUMS' ! -name 'evidence.tar.gz' ! -name 'evidence.tar.gz.sha256' -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS)
  (cd "$RESULT" && tar -czf evidence.tar.gz --exclude=evidence.tar.gz --exclude=evidence.tar.gz.sha256 . && sha256sum evidence.tar.gz > evidence.tar.gz.sha256)
  set -e
}
trap package_evidence EXIT

echo "turn=$TURN_ID run=$GITHUB_RUN_ID event_sha=${GITHUB_SHA:-unknown} started=$(date -u +%FT%TZ)"
uname -a; python3 --version; unzip -v | head -2; tar --version | head -1

meta="$(curl -fsSL -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID")"
name="$(python3 -c 'import json,sys; print(json.load(sys.stdin)["name"])' <<<"$meta")"
digest="$(python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))' <<<"$meta")"
[[ "$name" == "$EXPECTED_ARTIFACT_NAME" ]] || { fail_orch "artifact name $name"; exit 90; }
[[ "$digest" == "sha256:$EXPECTED_ZIP_SHA" ]] || { fail_orch "provider digest $digest"; exit 90; }
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID/zip" -o "$ZIP"
[[ "$(sha "$ZIP")" == "$EXPECTED_ZIP_SHA" ]] || { fail_orch 'artifact ZIP hash mismatch'; exit 90; }
(cd "$PKG" && unzip -q "$ZIP")
[[ "$(wc -l < "$PKG/SHA256SUMS" | tr -d ' ')" == 28 ]] || { fail_orch 'manifest count != 28'; exit 90; }
[[ "$(sha "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA" ]] || { fail_orch 'manifest hash mismatch'; exit 90; }
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$RESULT/package-manifest-check.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE" ]] || { fail_orch 'source commit mismatch'; exit 90; }
source_archive="$PKG/source/source-${EXPECTED_SOURCE}.tar.gz"
[[ "$(sha "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA" ]] || { fail_orch 'source archive mismatch'; exit 90; }
grep -Fxq 'runtimeExecution=false' "$PKG/metadata/command-boundary.txt" || { fail_orch 'runtime boundary mismatch'; exit 90; }
grep -Fxq 'turnBoundary=Code+Build-only' "$PKG/metadata/command-boundary.txt" || { fail_orch 'turn boundary mismatch'; exit 90; }
grep -Fxq 'exactArithmeticBackend=GMP' "$PKG/metadata/command-boundary.txt" || { fail_orch 'GMP boundary mismatch'; exit 90; }
grep -Fq 'libgmpxx.so' "$PKG/metadata/gmp-evidence.txt" && grep -Fq 'libgmp.so' "$PKG/metadata/gmp-evidence.txt" || { fail_orch 'GMP/GMPXX link evidence missing'; exit 90; }
for e in directional_benchmarks directional_compiled_api_tests directional_surface_cell_authority_kernel_tests directional_surface_cell_completion_tests directional_surface_cell_producer_tests directional_surface_cell_validation_tests; do [[ "$(stat -c '%a' "$PKG/bin/$e")" == 755 ]] || { fail_orch "mode mismatch $e"; exit 90; }; done
for l in libdirectional_core.a libdirectional_pipeline.a; do [[ "$(stat -c '%a' "$PKG/lib/$l")" == 644 ]] || { fail_orch "mode mismatch $l"; exit 90; }; done
for s in "$PKG"/metadata/source-status-*.txt; do [[ ! -s "$s" ]] || { fail_orch "dirty source receipt $(basename "$s")"; exit 90; }; done
tar -xzf "$source_archive" -C "$SRC"
selector="$SRC/$SELECTOR_REL"
[[ "$(wc -l < "$selector" | tr -d ' ')" == 426 && "$(sha "$selector")" == "$EXPECTED_SELECTOR_SHA" ]] || { fail_orch 'selector426 mismatch'; exit 90; }
[[ "$(head -n 425 "$selector" | sha256sum | awk '{print $1}')" == "$EXPECTED_FIRST425_SHA" ]] || { fail_orch 'first425 mismatch'; exit 90; }
[[ ! -e "$SRC/.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_427.txt" ]] || { fail_orch 'selector427 exists'; exit 90; }
for spec in \
  "benchmarks/fixtures/milestone-g/genus_two.obj:$EXPECTED_OBJ_SHA" \
  "benchmarks/fixtures/milestone-g/genus_two.rawfield:$EXPECTED_RAWFIELD_SHA" \
  "benchmarks/fixtures/milestone-g/genus_two.fixturemeta.json:$EXPECTED_META_SHA"; do p="${spec%%:*}"; h="${spec#*:}"; [[ "$(sha "$SRC/$p")" == "$h" ]] || { fail_orch "fixture hash $p"; exit 90; }; done
census_tree "$PKG" "$RESULT/package-census-before.tsv"; census_tree "$SRC" "$RESULT/source-census-before.tsv"

python3 - "$SRC" "$selector" "$RESULT/identity-map.tsv" "$RESULT/owner-map.tsv" <<'PY'
import pathlib,re,sys
root=pathlib.Path(sys.argv[1]); selector=[x for x in pathlib.Path(sys.argv[2]).read_text().splitlines() if x]; out=pathlib.Path(sys.argv[3]); owner_out=pathlib.Path(sys.argv[4])
cmake=(root/'cmake/DirectionalTests.cmake').read_text(); names=['directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests']
def cpp(s): return [x.strip() for x in s.splitlines() if x.strip().endswith('.cpp')]
p=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cmake,re.S); assert p
targets={'directional_surface_cell_producer_tests':cpp(p.group(1))}
for t in names:
    if t in targets: continue
    m=re.search(r'add_executable\(\s*'+re.escape(t)+r'(.*?)\)\s*\n',cmake,re.S); assert m, t
    targets[t]=cpp(m.group(1))
pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)'); owners={}
for t in names:
    for rel in targets[t]:
        for suite,test in pat.findall((root/rel).read_text(errors='replace')): owners.setdefault(f'{suite}.{test}',[]).append((t,rel))
owner_rows=[]
for ident,found in sorted(owners.items()):
    if len(found)!=1: raise SystemExit(f'global owner count {len(found)} for {ident}')
    t,rel=found[0]; owner_rows.append((ident,t,rel))
owner_out.write_text('identity\tbinary\tsource\n'+''.join(f'{i}\t{t}\t{r}\n' for i,t,r in owner_rows))
rows=[]; counts={t:0 for t in names}
for n,id in enumerate(selector,1):
    found=owners.get(id,[])
    if len(found)!=1: raise SystemExit(f'owner count {len(found)} at {n}:{id}')
    t,rel=found[0]; rows.append((n,id,t,rel)); counts[t]+=1
exp={'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_producer_tests':280,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
if counts!=exp: raise SystemExit(f'owner census drift {counts}')
out.write_text('selector_ordinal\tidentity\tbinary\tsource\n'+''.join(f'{n}\t{i}\t{t}\t{r}\n' for n,i,t,r in rows))
print(counts)
PY

cp -a "$PKG/bin/." "$VIEW/bin/"; mkdir -p "$VIEW/test-data/benchmarks"; cp -a "$SRC/benchmarks/fixtures" "$VIEW/test-data/benchmarks/"
for e in "$PKG"/bin/*; do b="$(basename "$e")"; [[ "$(sha "$e")" == "$(sha "$VIEW/bin/$b")" && "$(stat -c '%a' "$e")" == "$(stat -c '%a' "$VIEW/bin/$b")" ]] || { fail_orch "execution-view binary drift $b"; exit 90; }; done
census_tree "$VIEW" "$RESULT/execution-view-before.tsv"

python3 - "$RESULT/identity-map.tsv" "$RESULT/owner-map.tsv" "$RESULT/ledger.tsv" <<'PY'
import csv,sys
m={r['identity']:r['binary'] for r in csv.DictReader(open(sys.argv[2]),delimiter='\t')}
a0=['FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle','FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts','FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle','FieldTransportAtlas.PublishesCheckedSingularityPortAttachments','FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings']
a=['FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents','FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence','FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper','FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow']
s5=['M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology']
rows=[]
for phase,ids in [('A0',a0),('A',a),('S5',s5)]:
  for j,i in enumerate(ids,1):
    if i not in m: raise SystemExit(f'focused owner missing {i}')
    rows.append((len(rows)+1,phase,j,i,m[i],'UNEXECUTED','','','','','',''))
for r in csv.DictReader(open(sys.argv[1]),delimiter='\t'):
  rows.append((len(rows)+1,'SELECTOR',int(r['selector_ordinal']),r['identity'],r['binary'],'UNEXECUTED','','','','','',''))
if len(rows)!=436: raise SystemExit(len(rows))
with open(sys.argv[3],'w',newline='') as f:
  w=csv.writer(f,delimiter='\t',lineterminator='\n'); w.writerow(['ledger_ordinal','phase','phase_ordinal','identity','binary','status','exit','selected','skipped','stdout_sha256','stderr_sha256','raw_prefix']); w.writerows(rows)
PY
[[ "$(($(wc -l < "$RESULT/ledger.tsv")-1))" == 436 ]] || { fail_orch 'ledger init != 436'; exit 90; }
sha256sum "$RESULT/ledger.tsv" > "$RESULT/ledger.initial.sha256"
runtime_started=true

update_row() {
  python3 - "$RESULT/ledger.tsv" "$1" "$2" "$3" "$4" "$5" "$6" "$7" <<'PY'
import csv,sys,tempfile,os
p=sys.argv[1]; ordinal=int(sys.argv[2]); vals=sys.argv[3:]
rows=list(csv.reader(open(p),delimiter='\t')); hdr=rows[0]
for r in rows[1:]:
  if int(r[0])==ordinal:
    r[5:12]=vals; break
else: raise SystemExit('ledger ordinal missing')
q=p+'.tmp'
with open(q,'w',newline='') as f: csv.writer(f,delimiter='\t',lineterminator='\n').writerows(rows)
os.replace(q,p)
PY
}

run_row() {
  local ledger_ord="$1" phase="$2" phase_ord="$3" identity="$4" binary="$5"
  local stem dir work
  stem="$(printf '%03d' "$ledger_ord")-${phase}-$(printf '%03d' "$phase_ord")"
  dir="$RESULT/raw/$stem"
  work="$RUNTIME/$stem"
  mkdir -p "$dir" "$work"
  set +e
  (cd "$work" && env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/$binary" --gtest_filter="$identity") >"$dir/stdout.txt" 2>"$dir/stderr.txt"
  code=$?
  set -e
  cat "$dir/stdout.txt"; cat "$dir/stderr.txt" >&2
  selected="$(grep -hEc '^\[ RUN      \] ' "$dir/stdout.txt" "$dir/stderr.txt" 2>/dev/null | awk '{s+=$1} END{print s+0}')"
  skipped="$(grep -hEc '^\[  SKIPPED \] ' "$dir/stdout.txt" "$dir/stderr.txt" 2>/dev/null | awk '{s+=$1} END{print s+0}')"
  outsha="$(sha "$dir/stdout.txt")"; errsha="$(sha "$dir/stderr.txt")"; status='PASS'
  if [[ "$selected" -ne 1 || "$skipped" -ne 0 || "$code" -ge 128 ]]; then
    status='ORCHESTRATION'; orchestration_failure=true; stop_reason="orchestration_runtime:${phase}:${phase_ord}:${identity}:exit=${code}:selected=${selected}:skipped=${skipped}"
  elif [[ "$code" -ne 0 ]]; then
    status='RED'; semantic_red=true; stop_reason="semantic_red:${phase}:${phase_ord}:${identity}"
  fi
  update_row "$ledger_ord" "$status" "$code" "$selected" "$skipped" "$outsha" "$errsha" "raw/$stem"
  [[ "$status" == PASS ]]
}

ledger_ord=0
run_phase() {
  local phase="$1"; shift; local j=0 id binary
  for id in "$@"; do
    j=$((j+1)); ledger_ord=$((ledger_ord+1)); binary="$(awk -F '\t' -v id="$id" 'NR>1 && $1==id {print $2; exit}' "$RESULT/owner-map.tsv")"
    run_row "$ledger_ord" "$phase" "$j" "$id" "$binary" || return 1
  done
}
A0=( 'FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle' 'FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts' 'FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle' 'FieldTransportAtlas.PublishesCheckedSingularityPortAttachments' 'FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings' )
A=( 'FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents' 'FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence' 'FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper' 'FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow' )
S5=( 'M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology' )
if run_phase A0 "${A0[@]}" && run_phase A "${A[@]}" && run_phase S5 "${S5[@]}"; then
  while IFS=$'\t' read -r sel_ord id binary source; do
    [[ "$sel_ord" == selector_ordinal ]] && continue
    ledger_ord=$((ledger_ord+1))
    run_row "$ledger_ord" SELECTOR "$sel_ord" "$id" "$binary" || break
  done < "$RESULT/identity-map.tsv"
fi

postflight || true
python3 - "$RESULT/ledger.tsv" "$RESULT/summary.env" <<'PY'
import csv,collections,sys
rows=list(csv.DictReader(open(sys.argv[1]),delimiter='\t')); c=collections.Counter(r['status'] for r in rows)
ph={}
for r in rows: ph.setdefault(r['phase'],collections.Counter())[r['status']]+=1
sel=[r for r in rows if r['phase']=='SELECTOR']; own=collections.Counter(r['binary'] for r in sel if r['status']=='PASS')
with open(sys.argv[2],'w') as f:
  f.write(f"expected_rows=436\npass={c['PASS']}\nred={c['RED']}\norchestration={c['ORCHESTRATION']}\nunexecuted={c['UNEXECUTED']}\n")
  for p in ['A0','A','S5','SELECTOR']: f.write(f"{p}_pass={ph.get(p,{}) .get('PASS',0)}\n{p}_red={ph.get(p,{}) .get('RED',0)}\n{p}_unexecuted={ph.get(p,{}) .get('UNEXECUTED',0)}\n")
  for k,v in sorted(own.items()): f.write(f"selector_pass_owner_{k}={v}\n")
print(open(sys.argv[2]).read(),end='')
PY
if [[ "$orchestration_failure" == true ]]; then stop_reason="${stop_reason:-orchestration}"; exit 90; fi
if [[ "$semantic_red" == true ]]; then exit 0; fi
[[ "$ledger_ord" -eq 436 ]] || { fail_orch "green path ended at ledger ordinal $ledger_ord"; exit 90; }
stop_reason='all_gates_green'
echo "TB12_R8_EXEC_COMPLETE: 436/436 planned rows executed with no RED; semantic adjudication deferred to Review."
