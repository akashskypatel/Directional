#!/usr/bin/env bash
set -euo pipefail
: "${GITHUB_REPOSITORY:?}" "${GITHUB_RUN_ID:?}" "${GH_TOKEN:?}" "${TURN_ID:?}" "${RUNNER_TEMP:?}"
ART=10879581622
SRC=82b86a285292379cfd92cdc4e10d74181b38f1e8
ZIP_SHA=578845a2135ef2296e982e8bac9a378b7659d2968aa9ab5b2702f841288d57c6
MANIFEST_SHA=ca6af967b3abb6002ca0231a97873afef588348b9ed4a299e0eef59e28bf299e
SOURCE_SHA=0015832fb634b100419ac6c30352804152ea4fa2df665b1d059b3b06fab1425c
SEL_REL=.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt
ROUTE_REL=.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv
SEL_SHA=d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414
ROUTE_SHA=9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707
[[ "${1:-}" == --execute ]] || { echo "usage: $0 --execute" >&2; exit 64; }
SAFE=${TURN_ID//[^A-Za-z0-9._-]/-}; ROOT="$RUNNER_TEMP/$SAFE"; PKG="$ROOT/package"; SOURCE="$ROOT/source"; VIEW="$ROOT/view"; WORK="$ROOT/runtime"
RESULT="$RUNNER_TEMP/${SAFE}-result"; LOG="$RUNNER_TEMP/${SAFE}.log"; ZIP="$ROOT/candidate-$ART.zip"
mkdir -p "$PKG" "$SOURCE" "$VIEW/bin" "$WORK" "$RESULT/raw/focused" "$RESULT/raw/selector" "$RESULT/resources/focused" "$RESULT/resources/selector" "$RESULT/first-failures"
: > "$LOG"; exec > >(tee -a "$LOG") 2>&1
runtime_started=false; runtime_completed=false; preflight_completed=false; orchestration_failure=false; selection_integrity=true; focused_executed=0; selector_executed=0; finalized=false
sha(){ sha256sum "$1"|awk '{print $1}'; }
boundary(){ cat > "$RESULT/execution-boundary.txt" <<B
script_exit=$1
turn_id=$TURN_ID
runtime_started=$runtime_started
runtime_completed=$runtime_completed
preflight_completed=$preflight_completed
orchestration_failure=$orchestration_failure
selection_integrity=$selection_integrity
focused_executed=$focused_executed
selector_executed=$selector_executed
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
B
}
finish(){ s=$?; set +e; [[ $finalized == true ]] || boundary "$s"; echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" >> "$LOG"; }
trap finish EXIT
fail(){ orchestration_failure=true; echo "ORCHESTRATION_FAILURE: $*" >&2; exit 90; }
census(){ python3 - "$1" "$2" <<'PY'
import hashlib,os,pathlib,stat,sys
r=pathlib.Path(sys.argv[1]).resolve(); o=pathlib.Path(sys.argv[2]); rows=[]
for p in [r,*sorted(r.rglob('*'),key=lambda x:x.relative_to(r).as_posix())]:
 q='.' if p==r else p.relative_to(r).as_posix(); s=p.lstat(); m=format(stat.S_IMODE(s.st_mode),'o')
 if stat.S_ISREG(s.st_mode):
  h=hashlib.sha256(); f=p.open('rb')
  for c in iter(lambda:f.read(1048576),b''): h.update(c)
  f.close(); k,d,t='file',h.hexdigest(),'-'
 elif stat.S_ISDIR(s.st_mode): k,d,t='directory','-','-'
 elif stat.S_ISLNK(s.st_mode): k,d,t='symlink','-',os.readlink(p)
 else: k,d,t='other','-','-'
 rows.append(f'{q}\t{k}\t{m}\t{s.st_size}\t{d}\t{t}\n')
o.write_text(''.join(rows))
PY
}
{
 echo "turn_id=$TURN_ID"; echo "run_id=$GITHUB_RUN_ID"; echo "event=${GITHUB_EVENT_NAME:-unknown}"; echo "event_sha=${GITHUB_SHA:-unknown}"; echo "repository=$GITHUB_REPOSITORY"
 echo "candidate_artifact_id=$ART"; echo "expected_source_sha=$SRC"; echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"; uname -a; python3 --version; unzip -v|sed -n '1p'
} | tee "$RESULT/environment.txt"
meta=$(curl --fail --silent --show-error -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ART")
provider=$(python3 -c 'import json,sys;print(json.load(sys.stdin).get("digest",""))' <<<"$meta")
[[ $provider == sha256:$ZIP_SHA ]] || fail "provider digest mismatch: $provider"
curl -L --fail --silent --show-error -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ART/zip" -o "$ZIP"
[[ $(sha "$ZIP") == $ZIP_SHA ]] || fail 'downloaded ZIP digest mismatch'
printf 'artifact_id=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' "$ART" "$provider" "$(sha "$ZIP")" > "$RESULT/candidate-artifact-authority.txt"
unzip -q "$ZIP" -d "$PKG"
[[ -f $PKG/SHA256SUMS && $(sha "$PKG/SHA256SUMS") == $MANIFEST_SHA ]] || fail 'root manifest digest mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$RESULT/candidate-manifest-check-before.txt"
[[ $(grep -c ': OK$' "$RESULT/candidate-manifest-check-before.txt") -eq 28 ]] || fail 'root manifest not 28/28'
[[ $(cat "$PKG/metadata/source-commit.txt") == $SRC ]] || fail 'source commit mismatch'
[[ $(cat "$PKG/metadata/build-exit-code.txt") == 0 && $(cat "$PKG/metadata/preflight-exit-code.txt") == 0 ]] || fail 'compile evidence exit nonzero'
receipts=0; for f in "$PKG"/metadata/source-status-*.txt; do receipts=$((receipts+1)); [[ ! -s $f ]] || fail "dirty source receipt: $(basename "$f")"; done; [[ $receipts -eq 5 ]] || fail "expected five source status receipts; got $receipts"
for t in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP' 'preflightCompile=true'; do grep -Fxq "$t" "$PKG/metadata/command-boundary.txt" || fail "missing command-boundary token $t"; done
for t in 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' 'libgmpxx.so' 'libgmp.so'; do grep -Fq "$t" "$PKG/metadata/CMakeCache.txt" "$PKG/metadata/gmp-evidence.txt" || fail "missing GMP evidence $t"; done
EXES=(directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests)
printf 'kind\tname\tsha256\tmode\tsize\n' > "$RESULT/preflight-hashes.tsv"
for e in "${EXES[@]}"; do p="$PKG/bin/$e"; [[ -f $p && -x $p ]] || fail "missing/non-executable $e"; printf 'executable\t%s\t%s\t%s\t%s\n' "$e" "$(sha "$p")" "$(stat -c %a "$p")" "$(stat -c %s "$p")" >> "$RESULT/preflight-hashes.tsv"; done
ARCH="$PKG/source/source-$SRC.tar.gz"; [[ -f $ARCH && $(sha "$ARCH") == $SOURCE_SHA ]] || fail 'source archive mismatch'; tar -xzf "$ARCH" -C "$SOURCE"
SEL="$SOURCE/$SEL_REL"; ROUTE="$SOURCE/$ROUTE_REL"; [[ $(sha "$SEL") == $SEL_SHA ]] || fail 'selector digest mismatch'; [[ $(sha "$ROUTE") == $ROUTE_SHA ]] || fail 'routing digest mismatch'
printf 'source_archive\t%s\t%s\t%s\t%s\nselector\t%s\t%s\t%s\t%s\nrouting\t%s\t%s\t%s\t%s\n' "$(basename "$ARCH")" "$(sha "$ARCH")" "$(stat -c %a "$ARCH")" "$(stat -c %s "$ARCH")" "$SEL_REL" "$(sha "$SEL")" "$(stat -c %a "$SEL")" "$(stat -c %s "$SEL")" "$ROUTE_REL" "$(sha "$ROUTE")" "$(stat -c %a "$ROUTE")" "$(stat -c %s "$ROUTE")" >> "$RESULT/preflight-hashes.tsv"
python3 - "$SEL" "$ROUTE" "$PKG" "$RESULT/selector-routing.tsv" "$RESULT/selector-authority.txt" <<'PY'
import collections,hashlib,pathlib,sys
s=pathlib.Path(sys.argv[1]); r=pathlib.Path(sys.argv[2]); p=pathlib.Path(sys.argv[3]); out=pathlib.Path(sys.argv[4]); auth=pathlib.Path(sys.argv[5]); sb=s.read_bytes(); rb=r.read_bytes()
if b'\r' in sb+rb: raise SystemExit('CR bytes in selector/routing')
sl=sb.decode().splitlines(); rl=rb.decode().splitlines()
if len(sl)!=449 or len(rl)!=449 or len(set(sl))!=449: raise SystemExit('selector/routing count or uniqueness mismatch')
rows=[]; c=collections.Counter()
for n,line in enumerate(rl,1):
 x=line.split('\t')
 if len(x)!=3 or int(x[0])!=n or x[1]!=sl[n-1]: raise SystemExit(f'routing mismatch row {n}')
 rows.append((n,x[1],x[2])); c[x[2]]+=1
exp={'directional_surface_cell_authority_kernel_tests':32,'directional_surface_cell_producer_tests':301,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
if c!=exp: raise SystemExit(f'owner census mismatch {dict(c)}')
for e in exp:
 q=p/'bin'/e
 if not q.is_file() or not(q.stat().st_mode&0o111): raise SystemExit(f'owner executable invalid {e}')
out.write_text('ordinal\tidentity\tbinary\n'+''.join(f'{n}\t{i}\t{b}\n' for n,i,b in rows))
auth.write_text(f'selector_rows=449\nselector_sha256={hashlib.sha256(sb).hexdigest()}\nrouting_rows=449\nrouting_sha256={hashlib.sha256(rb).hexdigest()}\n'+''.join(f'{k}={v}\n' for k,v in exp.items()))
PY
cat > "$RESULT/focused-routing.tsv" <<'F'
ordinal	identity	binary
1	M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell	directional_surface_cell_producer_tests
2	M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity	directional_surface_cell_producer_tests
3	M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints	directional_surface_cell_producer_tests
4	M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct	directional_surface_cell_producer_tests
5	SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets	directional_surface_cell_producer_tests
6	M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection	directional_surface_cell_producer_tests
7	M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority	directional_surface_cell_producer_tests
F
census "$PKG" "$RESULT/package-census-before.tsv"; census "$SOURCE" "$RESULT/source-census-before.tsv"; cp -a "$PKG/bin/." "$VIEW/bin/"; mkdir -p "$VIEW/test-data/benchmarks"; cp -a "$SOURCE/benchmarks/fixtures" "$VIEW/test-data/benchmarks/"
for e in "${EXES[@]}"; do [[ $(sha "$PKG/bin/$e") == $(sha "$VIEW/bin/$e") && $(stat -c %a "$PKG/bin/$e") == $(stat -c %a "$VIEW/bin/$e") ]] || fail "execution-view mismatch $e"; done
census "$VIEW" "$RESULT/view-census-before.tsv"; preflight_completed=true
printf 'global_ordinal\tphase\tphase_ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tcrashed\tresult\telapsed_ms\traw_sha256\n' > "$RESULT/execution-ledger.tsv"
run_one(){ ph=$1; go=$2; po=$3; id=$4; bin=$5; d=${ph,,}; raw="$RESULT/raw/$d/ordinal-$(printf %03d "$po").log"; tim="$RESULT/resources/$d/ordinal-$(printf %03d "$po").time.txt"; wd="$WORK/$d/ordinal-$(printf %03d "$po")"; mkdir -p "$wd"; start=$(date +%s%3N); set +e; (cd "$wd"; /usr/bin/time -v -o "$tim" env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/$bin" --gtest_filter="$id") > "$raw" 2>&1; code=$?; set -e; end=$(date +%s%3N); cat "$raw"; sel=$(grep -Ec '^\[ RUN      \] ' "$raw"||true); skip=$(grep -Ec '^\[  SKIPPED \] ' "$raw"||true); pass=$(grep -Ec '^\[       OK \] ' "$raw"||true); [[ $sel -eq 1 && $skip -eq 0 ]] || { selection_integrity=false; fail "selection/skip mismatch $id selected=$sel skipped=$skip"; }; crash=0; [[ $code -lt 128 ]] || { crash=1; fail "crash $id exit=$code"; }; res=RED; [[ $code -eq 0 && $pass -eq 1 ]] && res=PASS; printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$go" "$ph" "$po" "$id" "$bin" "$code" "$sel" "$skip" "$pass" "$crash" "$res" "$((end-start))" "$(sha "$raw")" >> "$RESULT/execution-ledger.tsv"; if [[ $res == RED ]]; then { echo "identity=$id"; echo "phase=$ph ordinal=$po global=$go"; awk '/OccurrenceInvalidCornerAuthority|Failure|ERROR|Error|Invalid/{print; for(i=0;i<8&&getline;i++) print; found=1; exit} END{if(!found) print "see raw log"}' "$raw"; } > "$RESULT/first-failures/global-$(printf %03d "$go").txt"; fi; }
runtime_started=true
while IFS=$'\t' read -r n id bin; do [[ $n == ordinal ]] && continue; run_one focused "$n" "$n" "$id" "$bin"; focused_executed=$((focused_executed+1)); done < "$RESULT/focused-routing.tsv"
[[ $focused_executed -eq 7 ]] || fail 'focused execution count mismatch'
while IFS=$'\t' read -r n id bin; do [[ $n == ordinal ]] && continue; run_one selector "$((7+n))" "$n" "$id" "$bin"; selector_executed=$((selector_executed+1)); done < "$RESULT/selector-routing.tsv"
[[ $selector_executed -eq 449 ]] || fail 'selector execution count mismatch'; runtime_completed=true
python3 - "$RESULT/execution-ledger.tsv" "$RESULT/semantic-summary.txt" "$RESULT/red-ledger.tsv" <<'PY'
import csv,pathlib,sys
r=list(csv.DictReader(open(sys.argv[1]),delimiter='\t'))
if len(r)!=456 or [int(x['global_ordinal']) for x in r]!=list(range(1,457)): raise SystemExit('execution coverage mismatch')
f=[x for x in r if x['phase']=='focused']; s=[x for x in r if x['phase']=='selector']; fr=[x for x in f if x['result']!='PASS']; sr=[x for x in s if x['result']!='PASS']; red=fr+sr
pathlib.Path(sys.argv[2]).write_text(f'focused_total=7\nfocused_pass={7-len(fr)}\nfocused_red={len(fr)}\nselector_total=449\nselector_pass={449-len(sr)}\nselector_red={len(sr)}\ntotal_processes=456\ntotal_pass={456-len(red)}\ntotal_red={len(red)}\ncrashes=0\nselection_mismatches=0\nskips=0\nbenchmark_execution=0\nbuild_execution=0\nconfigure_execution=0\nlink_execution=0\n')
with open(sys.argv[3],'w',newline='') as o:
 w=csv.DictWriter(o,fieldnames=r[0].keys(),delimiter='\t',lineterminator='\n'); w.writeheader(); w.writerows(red)
PY
sha256sum "$RESULT/execution-ledger.tsv" > "$RESULT/execution-ledger.sha256"
printf 'kind\tname\tsha256\tmode\tsize\n' > "$RESULT/postflight-hashes.tsv"; for e in "${EXES[@]}"; do p="$PKG/bin/$e"; printf 'executable\t%s\t%s\t%s\t%s\n' "$e" "$(sha "$p")" "$(stat -c %a "$p")" "$(stat -c %s "$p")" >> "$RESULT/postflight-hashes.tsv"; done
printf 'source_archive\t%s\t%s\t%s\t%s\nselector\t%s\t%s\t%s\t%s\nrouting\t%s\t%s\t%s\t%s\n' "$(basename "$ARCH")" "$(sha "$ARCH")" "$(stat -c %a "$ARCH")" "$(stat -c %s "$ARCH")" "$SEL_REL" "$(sha "$SEL")" "$(stat -c %a "$SEL")" "$(stat -c %s "$SEL")" "$ROUTE_REL" "$(sha "$ROUTE")" "$(stat -c %a "$ROUTE")" "$(stat -c %s "$ROUTE")" >> "$RESULT/postflight-hashes.tsv"
cmp -s "$RESULT/preflight-hashes.tsv" "$RESULT/postflight-hashes.tsv" || fail 'pre/post hash inventory changed'; census "$PKG" "$RESULT/package-census-after.tsv"; census "$SOURCE" "$RESULT/source-census-after.tsv"; census "$VIEW" "$RESULT/view-census-after.tsv"; cmp -s "$RESULT/package-census-before.tsv" "$RESULT/package-census-after.tsv" || fail 'package census changed'; cmp -s "$RESULT/source-census-before.tsv" "$RESULT/source-census-after.tsv" || fail 'source census changed'; cmp -s "$RESULT/view-census-before.tsv" "$RESULT/view-census-after.tsv" || fail 'view census changed'
[[ $(sha "$SEL") == $SEL_SHA && $(sha "$ROUTE") == $ROUTE_SHA && $(sha "$ARCH") == $SOURCE_SHA ]] || fail 'immutable authority changed'; (cd "$PKG" && sha256sum -c SHA256SUMS) | tee "$RESULT/candidate-manifest-check-after.txt"; [[ $(grep -c ': OK$' "$RESULT/candidate-manifest-check-after.txt") -eq 28 ]] || fail 'post manifest not 28/28'
printf 'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\npre_post_hash_inventory_equal=true\nselector_unchanged=true\nrouting_unchanged=true\nsource_archive_unchanged=true\nmanifest_after=28/28\n' > "$RESULT/immutability.txt"
boundary 0; tmp="$RUNNER_TEMP/${SAFE}-SHA256SUMS.tmp"; (cd "$RESULT"; find . -type f ! -name SHA256SUMS -print0|LC_ALL=C sort -z|xargs -0 sha256sum) > "$tmp"; [[ $(wc -l < "$tmp") -eq $(find "$RESULT" -type f ! -name SHA256SUMS|wc -l) ]] || fail 'result manifest incomplete'; mv "$tmp" "$RESULT/SHA256SUMS"; (cd "$RESULT" && sha256sum -c SHA256SUMS >/dev/null); finalized=true
echo "${TURN_ID}_COMPLETE: 7 focused + selector449 artifact-only execution complete; interpretation deferred to Review."
