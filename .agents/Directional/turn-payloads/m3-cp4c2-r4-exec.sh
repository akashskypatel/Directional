#!/usr/bin/env bash
set -euo pipefail
log="${RUNNER_TEMP}/m3-cp4c2-r4-exec.log"
out="${RUNNER_TEMP}/m3-cp4c2-r4-exec-result"
pkg="${RUNNER_TEMP}/pkg"
zip="${RUNNER_TEMP}/package.zip"
rm -rf "$out" "$pkg"; mkdir -p "$out" "$pkg"; : > "$log"
exec > >(tee -a "$log") 2>&1
status=orchestration-failure
echo "$status" > "$out/status.txt"
echo "run_id=${GITHUB_RUN_ID} event=${GITHUB_EVENT_NAME} event_sha=${GITHUB_SHA} ref=${GITHUB_REF}"
echo "runner_os=${RUNNER_OS} workspace=${GITHUB_WORKSPACE}"
uname -a; unzip -v | head -n 2; tar --version | head -n 1; sha256sum --version | head -n 1

curl -fsSL -H "Authorization: Bearer ${GH_TOKEN}" \
  -H "Accept: application/vnd.github+json" -H "X-GitHub-Api-Version: 2022-11-28" \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/9707091209/zip" -o "$zip"
echo "e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63  $zip" | sha256sum -c -
unzip -q "$zip" -d "$pkg"
test "$(stat -c '%a' "$pkg/bin/directional_surface_cell_producer_tests")" = 755
(cd "$pkg" && sha256sum -c SHA256SUMS)
test "$(cat "$pkg/source-commit.txt")" = "5ad711e5d4ced95f38e103b993139a6307ba2cee"
test "$(cat "$pkg/preflight-exit-code.txt")" = 0
test "$(cat "$pkg/build-exit-code.txt")" = 0
test ! -s "$pkg/source-status-pre.txt"; test ! -s "$pkg/source-status-post.txt"
grep -Fx 'runtimeExecution=false' "$pkg/command-boundary.txt"
grep -Fx 'turnBoundary=Code+Build-only' "$pkg/command-boundary.txt"
grep -Fx 'exactArithmeticBackend=GMP' "$pkg/command-boundary.txt"
grep -q 'libgmpxx\.so' "$pkg/gmp-evidence.txt"; grep -q 'libgmp\.so' "$pkg/gmp-evidence.txt"
cat > "$out/expected-targets.txt" <<'EOF'
directional_benchmarks
directional_compiled_api_tests
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_completion_tests
directional_surface_cell_producer_tests
directional_surface_cell_validation_tests
EOF
LC_ALL=C sort "$pkg/compiled-targets.txt" > "$out/actual-targets.txt"
diff -u "$out/expected-targets.txt" "$out/actual-targets.txt"
src="$pkg/source/source-5ad711e5d4ced95f38e103b993139a6307ba2cee.tar.gz"
echo "9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11  $src" | sha256sum -c -
test "$GITHUB_WORKSPACE" = "/home/runner/work/Directional/Directional"
strings "$pkg/bin/directional_surface_cell_producer_tests" | grep -Fx "$GITHUB_WORKSPACE"
test -z "$(find "$GITHUB_WORKSPACE" -mindepth 1 -maxdepth 1 -print -quit)"
tar -xzf "$src" -C "$GITHUB_WORKSPACE"
chmod -R a-w "$GITHUB_WORKSPACE"

inv() {
  root="$1"; dest="$2"
  (cd "$root" && find . -type f -print0 | LC_ALL=C sort -z | while IFS= read -r -d '' f; do
    printf '%s\t%s\t%s\t%s\n' "$f" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f" | cut -d' ' -f1)"
  done) > "$dest"
}
inv "$pkg" "$out/package-pre.tsv"; inv "$GITHUB_WORKSPACE" "$out/source-pre.tsv"

sel="$GITHUB_WORKSPACE/.agents/Directional"
test "$(head -n 316 "$sel/Architecture_M3_CP4c0_Required_Green_Selector.txt" | sha256sum | cut -d' ' -f1)" = 601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c
test "$(sha256sum "$sel/Architecture_M3_CP4c0_Required_Green_Selector.txt" | cut -d' ' -f1)" = 20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a
test "$(sha256sum "$sel/Architecture_M3_CP4c0b_Required_Green_Selector.txt" | cut -d' ' -f1)" = 51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5
test "$(sha256sum "$sel/Architecture_M3_CP4c1_Required_Green_Selector.txt" | cut -d' ' -f1)" = e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa
test "$(sha256sum "$sel/Architecture_M3_CP4c2_Required_Green_Selector_357.txt" | cut -d' ' -f1)" = b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70
test "$(sha256sum "$sel/Architecture_M3_CP4c2_Required_Green_Selector_358.txt" | cut -d' ' -f1)" = 6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62

cd "$pkg"
set +e
./bin/directional_surface_cell_producer_tests --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable 2>&1 | tee "$out/d1.log"
d1=${PIPESTATUS[0]}
set -e
echo "$d1" > "$out/d1-exit.txt"
python3 - "$out" "$d1" <<'PY'
import json,sys
from pathlib import Path
out=Path(sys.argv[1]); rc=int(sys.argv[2])
lines=[x for x in (out/'d1.log').read_text(errors='replace').splitlines() if 'm3Cp4c2Y1;' in x]
rec={}
for line in lines:
    s=line[line.index('m3Cp4c2Y1;'):]; d={}
    for p in s.split(';')[1:]:
        if '=' in p:
            k,v=p.split('=',1); d[k]=v
    rec[d.get('witness')]=d
req={'torus','prescribed-sphere','two-ring'}; decision='STOP_EVIDENCE_CONFLICT'
if len(lines)==3 and set(rec)==req:
    t=rec['torus']; sp=rec['prescribed-sphere']; tr=rec['two-ring']
    shape=(t.get('witnessConstruction')=='pipelineProducts' and sp.get('witnessConstruction')=='pipelineProducts' and tr.get('witnessConstruction')=='constructed')
    pf=all(k in t for k in ('pipelineAtlasAvailable','pipelineNetworkAvailable','pipelineCutGraphAvailable','pipelinePlanAvailable','terminalFailureCode','terminalFailureStage'))
    if shape and pf and (t.get('pipelineAtlasAvailable')=='false' or t.get('pipelineNetworkAvailable')=='false' or t.get('constructionSucceeded')!='true'):
        decision='STOP_Z12'
    elif shape and t.get('constructionSucceeded')=='true':
        torus_ok=all(t.get(k)==v for k,v in {'complex':'sourceEdgeBarrier','railAuthority':'pipeline-authoritative','surfaceCutGraphCalls':'0','barrierV':'48','barrierE':'48','sourceChi':'0','networkOnlyCellular':'false','oracleSelfConsistent':'true'}.items())
        common=lambda d: d.get('oracleKind')=='independent-source-edge-barrier-complex' and d.get('complex')=='sourceEdgeBarrier' and d.get('oracleSelfConsistent')=='true' and d.get('constructionSucceeded')=='true'
        allok=torus_ok and common(t) and common(sp) and common(tr) and sp.get('railAuthority')=='pipeline-authoritative' and tr.get('railAuthority')=='atlas-derived'
        decision='RUN_D2' if allok and rc==0 else 'STOP_D1_CONSISTENCY'
(out/'d1-records.txt').write_text('\n'.join(lines)+('\n' if lines else ''))
(out/'d1-decision.txt').write_text(decision+'\n')
(out/'d1-records.json').write_text(json.dumps(rec,sort_keys=True,indent=2)+'\n')
print(f'd1_exit={rc} d1_records={len(lines)} d1_decision={decision}')
PY
decision="$(cat "$out/d1-decision.txt")"
if [[ "$decision" == RUN_D2 ]]; then
  set +e
  ./bin/directional_surface_cell_producer_tests --gtest_filter=GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable 2>&1 | tee "$out/d2.log"
  d2=${PIPESTATUS[0]}
  set -e
  echo "$d2" > "$out/d2-exit.txt"
  python3 - "$out" "$d2" <<'PY'
import sys
from pathlib import Path
out=Path(sys.argv[1]); rc=int(sys.argv[2])
lines=[x for x in (out/'d2.log').read_text(errors='replace').splitlines() if 'm3Cp4c2Y2;' in x]; ok=False
if len(lines)==1:
    s=lines[0][lines[0].index('m3Cp4c2Y2;'):]; d=dict(p.split('=',1) for p in s.split(';')[1:] if '=' in p)
    ok=rc==0 and d.get('witness')=='prescribed-sphere' and d.get('oracleComplex')=='sourceEdgeBarrier' and d.get('railAuthority')=='pipeline-authoritative' and d.get('oracleSelfConsistent')=='true' and d.get('localizationConsistent')=='true'
(out/'d2-records.txt').write_text('\n'.join(lines)+('\n' if lines else ''))
(out/'d2-decision.txt').write_text(('PASS' if ok else 'STOP_D2_EVIDENCE_CONFLICT')+'\n')
print(f'd2_exit={rc} d2_records={len(lines)} d2_decision={"PASS" if ok else "STOP_D2_EVIDENCE_CONFLICT"}')
PY
else
  echo "SKIPPED_DUE_TO_${decision}" > "$out/d2-decision.txt"
fi

inv "$pkg" "$out/package-post.tsv"; inv "$GITHUB_WORKSPACE" "$out/source-post.tsv"
cmp "$out/package-pre.tsv" "$out/package-post.tsv"
cmp "$out/source-pre.tsv" "$out/source-post.tsv"
(cd "$pkg" && sha256sum -c SHA256SUMS)
test "$(cat "$pkg/source-commit.txt")" = "5ad711e5d4ced95f38e103b993139a6307ba2cee"
grep -Fx 'runtimeExecution=false' "$pkg/command-boundary.txt"
grep -Fx 'turnBoundary=Code+Build-only' "$pkg/command-boundary.txt"
grep -Fx 'exactArithmeticBackend=GMP' "$pkg/command-boundary.txt"

final=semantic-red
[[ "$(cat "$out/d1-decision.txt")" == RUN_D2 && "$(cat "$out/d2-decision.txt")" == PASS ]] && final=semantic-pass
echo "$final" > "$out/status.txt"
jq -n --arg status "$final" --arg d1 "$(cat "$out/d1-decision.txt")" --arg d2 "$(cat "$out/d2-decision.txt")" \
  --arg event_sha "$GITHUB_SHA" --arg run_id "$GITHUB_RUN_ID" \
  '{turn:"M3-CP4c-2-TB-X2-R4-EXEC",status:$status,d1Decision:$d1,d2Decision:$d2,runId:$run_id,eventSha:$event_sha,packageArtifact:9707091209,packageSha256:"e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63",semanticSource:"5ad711e5d4ced95f38e103b993139a6307ba2cee",turnBoundary:"Test+Benchmark-artifact-only",configure:false,compile:false,relink:false,generatedDiscovery:false,benchmarkExecution:false,packageMutation:false,sourceMutation:false,selected_r2_branch:"NONE",selected_gate:"NONE"}' > "$out/summary.json"
cat "$out/summary.json"
