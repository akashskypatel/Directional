#!/usr/bin/env bash
set -euo pipefail
TURN=M4-CP-SCALE-TB3-EXEC
ARTIFACT_ID=10375799491
ARTIFACT_NAME=m4-cp-scale-cb3-package-result-34915185539
EXPECTED_ZIP_SHA=60e84d9b630a8a59574b330e83f80120000973f91a011272a743ce6bdbac5379
EXPECTED_MANIFEST_SHA=2f52b377f0a26bd1d474ed64e41a2fd5096b5ad102c4ff802691dd1969246cfb
EXPECTED_SOURCE_ARCHIVE_SHA=4ec9c7888621fbb0b51cff7173a8ef678c6351a5f3a88988fc0d1b590aee1e2d
EXPECTED_SELECTOR_SHA=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343
EXPECTED_FIRST422_SHA=bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc
EXPECTED_SOURCE=ba6e204d9daef39bfc6c168b659fc1b94f2b5b9b
FOCUS=M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle
WORK="${RUNNER_TEMP}/m4-cp-scale-tb3-exec"; ZIP="$WORK/candidate.zip"; PKG="$WORK/package"; SOURCE="$WORK/source"; VIEW="$WORK/execution-view"
RUNTIME="$WORK/runtime"; RESULT="$WORK/evidence"; PUBLISH="$RUNNER_TEMP/tb3-publish"
SELECTOR="$SOURCE/.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt"; OWNER_MAP="$RESULT/selector423-owner-map.tsv"
runtime_started=false; runtime_completed=false; focused_pass=false; selector_completed=false; selection_integrity=true; timeout_count=0; crash_count=0
configure_execution=false; compile_execution=false; relink_execution=false; repair_execution=false; generated_discovery=false; mutation_execution=false; benchmark_execution=false
mkdir -p "$PKG" "$SOURCE" "$VIEW/bin" "$VIEW/lib" "$VIEW/test-data/benchmarks" "$RUNTIME/s2" "$RUNTIME/selector" "$RESULT/raw/s2" "$RESULT/raw/selector" "$RESULT/resources/s2" "$RESULT/resources/selector" "$PUBLISH"
sha_file(){ sha256sum "$1" | awk '{print $1}'; }
census_tree(){ python3 - "$1" "$2" <<'PY'
import hashlib,os,pathlib,stat,sys
root=pathlib.Path(sys.argv[1]).resolve(); out=pathlib.Path(sys.argv[2]); rows=[]
for p in [root,*sorted(root.rglob('*'),key=lambda q:q.relative_to(root).as_posix())]:
 r='.' if p==root else p.relative_to(root).as_posix(); s=p.lstat(); m=f'{stat.S_IMODE(s.st_mode):04o}'
 if stat.S_ISREG(s.st_mode):
  h=hashlib.sha256()
  with p.open('rb') as f:
   for c in iter(lambda:f.read(1048576),b''): h.update(c)
  k,d,t='file',h.hexdigest(),'-'
 elif stat.S_ISDIR(s.st_mode): k,d,t='directory','-','-'
 elif stat.S_ISLNK(s.st_mode): k,d,t='symlink','-',os.readlink(p)
 else: k,d,t='other','-','-'
 rows.append(f'{r}\t{k}\t{m}\t{s.st_size}\t{d}\t{t}\n')
out.write_text(''.join(rows))
PY
}
finalize(){
 rc=$?; set +e
 printf 'mechanical_exit=%s\nruntimeStarted=%s\nruntimeCompleted=%s\nfocusedPass=%s\nselectorCompleted=%s\nselectionIntegrity=%s\ntimeoutCount=%s\ncrashCount=%s\n' "$rc" "$runtime_started" "$runtime_completed" "$focused_pass" "$selector_completed" "$selection_integrity" "$timeout_count" "$crash_count" > "$RESULT/final-status.txt"
 printf 'configureExecution=%s\ncompileExecution=%s\nrelinkExecution=%s\nrepairExecution=%s\ngeneratedDiscovery=%s\nmutationExecution=%s\nbenchmarkExecution=%s\n' "$configure_execution" "$compile_execution" "$relink_execution" "$repair_execution" "$generated_discovery" "$mutation_execution" "$benchmark_execution" > "$RESULT/execution-prohibitions.txt"
 ledger="$RESULT/selector423-process-ledger.tsv"
 if [[ -f "$ledger" ]]; then
  python3 - "$ledger" "$RESULT/selector423-summary.txt" <<'PY'
import csv,collections,pathlib,sys
r=list(csv.DictReader(open(sys.argv[1]),delimiter='\t')); assert len(r)==423 and [int(x['ordinal']) for x in r]==list(range(1,424)); c=collections.Counter(x['result'] for x in r); b=collections.Counter(x['binary'] for x in r)
t=''.join([f'total={len(r)}\n',f'pass={c["PASS"]}\n',f'red={c["RED"]}\n',f'skip={c["SKIP"]}\n',f'timeout={c["TIMEOUT"]}\n',f'selectionMismatch={c["SELECTION_MISMATCH"]}\n',f'unexecuted={c["UNEXECUTED"]}\n',f'authorityKernel={b["directional_surface_cell_authority_kernel_tests"]}\n',f'producer={b["directional_surface_cell_producer_tests"]}\n',f'completion={b["directional_surface_cell_completion_tests"]}\n',f'validation={b["directional_surface_cell_validation_tests"]}\n']); pathlib.Path(sys.argv[2]).write_text(t)
PY
 fi
 immutable_postflight=unavailable
 if [[ -f "$RESULT/package-census-before.tsv" && -d "$PKG" && -d "$SOURCE" && -d "$VIEW" ]]; then
  census_tree "$PKG" "$RESULT/package-census-after.tsv"
  census_tree "$SOURCE" "$RESULT/source-census-after.tsv"
  census_tree "$VIEW" "$RESULT/execution-view-after.tsv"
  p=false; ss=false; v=false; m=false
  cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" && p=true
  cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" && ss=true
  cmp -s "$RESULT/execution-view-before.tsv" "$RESULT/execution-view-after.tsv" && v=true
  if (cd "$PKG" && sha256sum -c SHA256SUMS) > "$RESULT/postflight-package-sha256-check.txt" 2>&1; then m=true; fi
  printf 'package_census_equal=%s\nsource_census_equal=%s\nexecution_view_census_equal=%s\npackage_manifest_verified=%s\nselector_rows=423\nselector_sha256=%s\nfirst422_sha256=%s\n' "$p" "$ss" "$v" "$m" "$EXPECTED_SELECTOR_SHA" "$EXPECTED_FIRST422_SHA" > "$RESULT/postflight-immutability.txt"
  if [[ "$p" == true && "$ss" == true && "$v" == true && "$m" == true ]]; then immutable_postflight=verified; else immutable_postflight=failed; fi
 fi
 if [[ -f "$ledger" ]]; then rem=true; else rem=false; fi
 printf 'failure_path_remainder_preserved=%s\nimmutable_postflight=%s\n' "$rem" "$immutable_postflight" > "$RESULT/failure-path-control.txt"
 (cd "$RESULT" && find . -type f ! -name SHA256SUMS ! -name '*.zip' -print0 | LC_ALL=C sort -z | xargs -0 sha256sum > SHA256SUMS)
 (cd "$RESULT" && sha256sum -c SHA256SUMS) > "$PUBLISH/evidence-manifest-check.txt" 2>&1
 (cd "$WORK" && zip -qr "$PUBLISH/Directional__M4-CP-SCALE-TB3-EXEC__evidence.zip" evidence)
 evsha=$(sha_file "$PUBLISH/Directional__M4-CP-SCALE-TB3-EXEC__evidence.zip")
 printf 'turn=%s\nartifact_id=%s\nartifact_name=%s\nevidence_zip_sha256=%s\nmechanical_exit=%s\nruntimeExecution=true\n' "$TURN" "$ARTIFACT_ID" "$ARTIFACT_NAME" "$evsha" "$rc" > "$PUBLISH/publication.env"
 exit "$rc"
}
trap finalize EXIT

gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" > "$ZIP"
[[ "$(sha_file "$ZIP")" == "$EXPECTED_ZIP_SHA" ]]
unzip -q "$ZIP" -d "$PKG"
[[ "$(grep -cve '^[[:space:]]*$' "$PKG/SHA256SUMS")" -eq 28 ]]; ! grep -Eq '(^|[ /])SHA256SUMS$' "$PKG/SHA256SUMS"
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA" ]]; (cd "$PKG" && sha256sum -c SHA256SUMS) > "$RESULT/preflight-package-sha256-check.txt"
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE" && "$(cat "$PKG/metadata/build-exit-code.txt")" == 0 && "$(cat "$PKG/metadata/preflight-exit-code.txt")" == 0 ]]
for f in "$PKG"/metadata/source-status-*.txt; do [[ ! -s "$f" ]]; done
for token in runtimeExecution=false turnBoundary=Code+Build-only exactArithmeticBackend=GMP manifestExcludesSelf=true; do grep -Fxq "$token" "$PKG/metadata/command-boundary.txt"; done
{
 printf 'kind\tname\tmode\tbytes\tsha256\n'
 for n in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests directional_compiled_api_tests directional_benchmarks; do p="$PKG/bin/$n"; [[ -x "$p" ]]; printf 'executable\t%s\t%s\t%s\t%s\n' "$n" "$(stat -c '%a' "$p")" "$(stat -c '%s' "$p")" "$(sha_file "$p")"; done
 for n in libdirectional_core.a libdirectional_pipeline.a; do p="$PKG/lib/$n"; [[ -f "$p" ]]; printf 'static-library\t%s\t%s\t%s\t%s\n' "$n" "$(stat -c '%a' "$p")" "$(stat -c '%s' "$p")" "$(sha_file "$p")"; done
} > "$RESULT/package-runtime-census.tsv"
mapfile -t src_archives < <(find "$PKG/source" -maxdepth 1 -type f -name 'source-*.tar.gz' -print); [[ ${#src_archives[@]} -eq 1 ]]; [[ "$(sha_file "${src_archives[0]}")" == "$EXPECTED_SOURCE_ARCHIVE_SHA" ]]
tar -xzf "${src_archives[0]}" -C "$SOURCE"
[[ "$(grep -cve '^[[:space:]]*$' "$SELECTOR")" -eq 423 && "$(sha_file "$SELECTOR")" == "$EXPECTED_SELECTOR_SHA" ]]
first422=$(python3 - "$SELECTOR" <<'PY'
import hashlib,sys
b=open(sys.argv[1],'rb').read().splitlines(keepends=True); assert len(b)==423; print(hashlib.sha256(b''.join(b[:422])).hexdigest())
PY
); [[ "$first422" == "$EXPECTED_FIRST422_SHA" ]]
grep -Fq 'TEST(M4CPScaleS2, VertexStarCertifiedFilterMatchesIndependentExactOracle)' "$SOURCE/tests/FieldAlignedCurveNetworkTests.cpp"; ! grep -Fxq "$FOCUS" "$SELECTOR"
owner_for_suite(){ case "$1" in
 FieldTransportAtlas|SurfaceCellAuthorityKernel) echo authority-kernel;;
 FlowRepStrandsPhase15|PatchDescriptorMilestoneE|PureQuadCompletionPhase18|SurfaceArrangementPhase16|SurfaceCellSourceSupportAndChartAuthority|SurfaceComplexSimplificationPhase17) echo completion;;
 SourceAuthoritativeMeshValidatorPhase22|SurfaceMeshOptimizerPhase19|SurfaceMeshOptimizerPhase22|SurfaceOptimizationRailAuthorityMigration) echo validation;;
 EmbeddedGraphTopology|FieldAlignedCurveNetwork|GlobalConformityBaseline|GlobalConformityCertificate|GlobalConformityExactSolver|GlobalConformityOutcome|GlobalConformityPlan|GlobalTopologyPlan|InputConditionerCPCondCB1|InputConditionerCPCondCB5|MilestoneGP26|RemeshPipeline|ResolvedBranchContinuation|ResolvedBranchCorrection|SurfaceCellAuthorityContractCutover|SurfaceCellClosedProductContracts|SurfaceCellFieldAlignedNetworkAuthority|SurfaceCellFieldTransitionAuthorityMigration|SurfaceCellIsolationSeamCertificateAuthority|SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration|SurfaceCellPhaseFrontFieldChartAuthorityMigration|SurfaceCellPipelinePhase20|SurfaceCellSegmentRouteTransportAuthorityMigration|SurfaceCellTracingPhase14|SurfaceCellTransitionQuotient|SurfaceCellTypedTransportAuthority|SurfaceCellVertexContinuationRouteTransportAuthorityMigration|SurfaceCellsPhase10|SurfaceCutGraph|SurfacePhaseFrontProductFactoryAuthority|TraceTerminationCorrection) echo producer;;
 *) return 1;; esac; }
printf 'ordinal\tidentity\towner\n' > "$OWNER_MAP"; o=0
while IFS= read -r id || [[ -n "$id" ]]; do [[ -n "$id" ]] || continue; o=$((o+1)); owner=$(owner_for_suite "${id%%.*}"); printf '%s\t%s\t%s\n' "$o" "$id" "$owner" >> "$OWNER_MAP"; done < "$SELECTOR"; [[ $o -eq 423 ]]
for spec in 'authority-kernel 30' 'producer 277' 'completion 75' 'validation 41'; do set -- $spec; [[ "$(awk -F '\t' -v x="$1" 'NR>1&&$3==x{n++}END{print n+0}' "$OWNER_MAP")" -eq "$2" ]]; done
ledger="$RESULT/selector423-process-ledger.tsv"
printf 'ordinal\tidentity\tbinary\texit\tselected\tok\tskipped\tresult\traw_log\n' > "$ledger"
owner_bin(){ case "$1" in authority-kernel) echo directional_surface_cell_authority_kernel_tests;; producer) echo directional_surface_cell_producer_tests;; completion) echo directional_surface_cell_completion_tests;; validation) echo directional_surface_cell_validation_tests;; esac; }
while IFS=$'\t' read -r ordinal identity owner; do
 [[ "$ordinal" == ordinal ]] && continue
 printf '%s\t%s\t%s\t-\t0\t0\t0\tUNEXECUTED\t-\n' "$ordinal" "$identity" "$(owner_bin "$owner")" >> "$ledger"
done < "$OWNER_MAP"
[[ "$(awk 'END{print NR-1}' "$ledger")" -eq 423 ]]
cp -a "$PKG/bin/." "$VIEW/bin/"; cp -a "$PKG/lib/." "$VIEW/lib/"; cp -a "$SOURCE/benchmarks/fixtures" "$VIEW/test-data/benchmarks/"
for n in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests directional_compiled_api_tests directional_benchmarks; do [[ "$(sha_file "$PKG/bin/$n")" == "$(sha_file "$VIEW/bin/$n")" && "$(stat -c '%a' "$PKG/bin/$n")" == "$(stat -c '%a' "$VIEW/bin/$n")" ]]; done
census_tree "$PKG" "$RESULT/package-census-before.tsv"; census_tree "$SOURCE" "$RESULT/source-census-before.tsv"; census_tree "$VIEW" "$RESULT/execution-view-before.tsv"
printf 'artifact_id=%s\nartifact_name=%s\nprovider_zip_sha256=%s\nsemantic_source=%s\nsource_archive_sha256=%s\npackage_manifest_sha256=%s\npackage_manifest_entries=28\nselector_rows=423\nselector_sha256=%s\nfirst422_sha256=%s\nowner_census=30/277/75/41\nruntimeExecution_before_tb=false\n' "$ARTIFACT_ID" "$ARTIFACT_NAME" "$EXPECTED_ZIP_SHA" "$EXPECTED_SOURCE" "$EXPECTED_SOURCE_ARCHIVE_SHA" "$EXPECTED_MANIFEST_SHA" "$EXPECTED_SELECTOR_SHA" "$EXPECTED_FIRST422_SHA" > "$RESULT/immutable-input.txt"

runtime_started=true; raw="$RESULT/raw/s2/focused.log"; tm="$RESULT/resources/s2/focused.time.txt"
set +e; (cd "$RUNTIME/s2" && /usr/bin/time -v -o "$tm" timeout -k 5s 180s env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/directional_surface_cell_producer_tests" --gtest_filter="$FOCUS") > "$raw" 2>&1; frc=$?; set -e
sel=$(grep -Ec '^\[ RUN      \] ' "$raw" || true); ok=$(grep -Ec '^\[       OK \] ' "$raw" || true); sk=$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true); fres=RED
if [[ $frc -eq 0 && $sel -eq 1 && $ok -eq 1 && $sk -eq 0 ]]; then fres=PASS; focused_pass=true; fi
printf 'identity\texit\tselected\tok\tskipped\tresult\traw_log\n%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$FOCUS" "$frc" "$sel" "$ok" "$sk" "$fres" 'raw/s2/focused.log' > "$RESULT/s2-process-ledger.tsv"
[[ $sel -eq 1 ]] || { selection_integrity=false; exit 31; }; [[ "$fres" == PASS ]] || exit 32
python3 - "$raw" "$RESULT/s2-six-subject-receipt.tsv" <<'PY'
from pathlib import Path
import sys
E=[('positive-strict-interior','1','2','1','0-3-1','0','false'),('negative-opposite-order','2','1','-1','0-2-3','0','false'),('near-boundary-certified','1099511627776','1099511627775','-1','0-2-3','0','false'),('exact-boundary-fallback','1','1','0','0-3-1','1','true'),('tamper-base','5','4','-1','0-2-3','0','false'),('tamper-crossed','3','4','1','0-3-1','0','false')]; R=[]
for l in Path(sys.argv[1]).read_text(errors='replace').splitlines():
 if not l.startswith('m4CpScaleS2;'): continue
 d={k:v for k,v in (p.split('=',1) for p in l.split(';')[1:] if '=' in p)}; R.append(tuple(d[k] for k in ['subject','rayX','rayY','oracleBoundarySign','expectedOwner','route','onRadialRay']))
if R!=E: raise SystemExit(f'S2 receipt mismatch: {R!r}')
Path(sys.argv[2]).write_text('subject\trayX\trayY\toracleBoundarySign\texpectedOwner\troute\tonRadialRay\n'+''.join('\t'.join(r)+'\n' for r in R))
PY
o=0
while IFS= read -r id || [[ -n "$id" ]]; do [[ -n "$id" ]] || continue; o=$((o+1)); line=$(awk -F '\t' -v n="$o" 'NR>1&&$1==n{print;exit}' "$OWNER_MAP"); [[ "$(cut -f2 <<<"$line")" == "$id" ]]; owner=$(cut -f3 <<<"$line"); bin=$(owner_bin "$owner"); stem=$(printf 'ordinal-%03d' "$o"); r="$RESULT/raw/selector/$stem.log"; t="$RESULT/resources/selector/$stem.time.txt"; d="$RUNTIME/selector/$stem"; mkdir -p "$d"
 set +e; (cd "$d" && /usr/bin/time -v -o "$t" timeout -k 5s 180s env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/$bin" --gtest_filter="$id") > "$r" 2>&1; c=$?; set -e
 s=$(grep -Ec '^\[ RUN      \] ' "$r" || true); k=$(grep -Ec '^\[       OK \] ' "$r" || true); x=$(grep -Ec '^\[  SKIPPED \] ' "$r" || true); res=RED
 if [[ $s -ne 1 ]]; then selection_integrity=false; res=SELECTION_MISMATCH; elif [[ $c -eq 124 || $c -eq 137 ]]; then timeout_count=$((timeout_count+1)); res=TIMEOUT; elif [[ $x -gt 0 ]]; then res=SKIP; elif [[ $c -eq 0 && $k -eq 1 ]]; then res=PASS; else [[ $c -lt 128 ]] || crash_count=$((crash_count+1)); fi
 python3 - "$ledger" "$o" "$id" "$bin" "$c" "$s" "$k" "$x" "$res" "raw/selector/$stem.log" <<'PY'
import csv,pathlib,sys,os
path=pathlib.Path(sys.argv[1]); ordinal=int(sys.argv[2]); expected=sys.argv[3]
rows=list(csv.DictReader(path.open(),delimiter='\t')); assert len(rows)==423
row=rows[ordinal-1]; assert int(row['ordinal'])==ordinal and row['identity']==expected and row['result']=='UNEXECUTED'
for key,val in zip(['binary','exit','selected','ok','skipped','result','raw_log'],sys.argv[4:]): row[key]=val
tmp=path.with_suffix('.tmp')
with tmp.open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=['ordinal','identity','binary','exit','selected','ok','skipped','result','raw_log'],delimiter='\t',lineterminator='\n'); w.writeheader(); w.writerows(rows)
os.replace(tmp,path)
PY
 printf '%03d/423 %s %s\n' "$o" "$res" "$id"
done < "$SELECTOR"; selector_completed=true; runtime_completed=true
python3 - "$ledger" "$RESULT/selector423-summary-runtime.txt" <<'PY'
import csv,collections,pathlib,sys
r=list(csv.DictReader(open(sys.argv[1]),delimiter='\t')); assert len(r)==423; c=collections.Counter(x['result'] for x in r)
t=''.join(f'{k}={c[k]}\n' for k in ['PASS','RED','SKIP','TIMEOUT','SELECTION_MISMATCH','UNEXECUTED']); pathlib.Path(sys.argv[2]).write_text(t)
PY
pass=$(awk -F= '$1=="PASS"{print $2}' "$RESULT/selector423-summary-runtime.txt"); red=$(awk -F= '$1=="RED"{print $2}' "$RESULT/selector423-summary-runtime.txt"); skip=$(awk -F= '$1=="SKIP"{print $2}' "$RESULT/selector423-summary-runtime.txt"); tout=$(awk -F= '$1=="TIMEOUT"{print $2}' "$RESULT/selector423-summary-runtime.txt"); sm=$(awk -F= '$1=="SELECTION_MISMATCH"{print $2}' "$RESULT/selector423-summary-runtime.txt"); un=$(awk -F= '$1=="UNEXECUTED"{print $2}' "$RESULT/selector423-summary-runtime.txt")
printf 'TB3_RESULT focus=%s receipt=6/6 selector=%s/423 red=%s skip=%s timeout=%s selectionMismatch=%s unexecuted=%s\n' "$fres" "$pass" "$red" "$skip" "$tout" "$sm" "$un"; [[ "$fres" == PASS && "$pass" -eq 423 && "$red" -eq 0 && "$skip" -eq 0 && "$tout" -eq 0 && "$sm" -eq 0 && "$un" -eq 0 ]]
