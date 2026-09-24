#!/usr/bin/env bash
set -euo pipefail
: "${GITHUB_REPOSITORY:?}" "${GITHUB_RUN_ID:?}" "${GH_TOKEN:?}" "${TURN_ID:?}"
ART=10782841045
SRC=535ec760b7c39dd437de69afebec568fafb44aab
ZIP_SHA='3772d2c323bb4995bcb4503960d1bef1251442a3a7a95d8c0660680008042da6'
MAN_SHA='ab5d9d7bdbc5583b3df69d781830dff91afe6b619386a6fde3c8e57447743985'
SRC_SHA='004be77dd02bd7f691cb3bf6a29aa551601b78a621e54dbdaa366f709e17112d'
SEL_SHA='70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789'
ROUTE_SHA='c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c'
SEL='.agents/Directional/Architecture_M5_CP3_CB20_Required_Gren_Selector_448.txt'
ROUTE=".agents/Directional/Architecture_M5_CP3_CB20_Selector_448_Static_Routing_Receipt.tsv"
ID449='M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion'
OWNER449='directional_surface_cell_producer_tests'
ROOT="$RUNNER_TEMP/$TURN_ID"; PKG="$ROOT/pkg"; SOURCE="$ROOT/source"; VIEW="$ROOT/view"; RUN="$ROOT/run"
OUT="$RUNNER_TEMP/$TURN_ID-result"; LOG="$RUNNER_TEMP/$TURN_ID.log"; ZIP="$ROOT/artifact.zip"
mkdir -p "$PKG" "$SOURCE" "$VIEW/bin" "$RUN" "$OUT/raw"; : >"$LOG"; exec > >(tee -a "$LOG") 2>&1
runtime=false; complete=false; orchestration=false; selected_ok=true; executed=0
boundary(){ cat >"$OUT/execution-boundary.txt" <<B
turn_id=$TURN_ID
runtime_started=$runtime
runtime_completed=$complete
orchestration_failure=$orchestration
selection_integrity=$selected_ok
executed=$executed
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
retry_after_runtime_start=false
B
}
fail(){ orchestration=true; boundary; echo "ORCHESTRATION_FAILURE: $*" >&2; exit 90; }
sha(){ sha256sum "$1"|awk '{print $1}'; }
treehash(){ tar -C "$1" --sort=name --mtime='UTC 1970-01-01' --owner=0 --group=0 --numeric-owner -cf - . | sha256sum | awk '{print $1}'; }
trap 's=$?; set +e; boundary; echo script_exit=$s >>"$OUT/execution-boundary.txt"; echo finished_at=$(date -u +%FT$TZ) >>"$LOG"' EXIT

echo "turn=$TURN_ID run=$GITHUB_RUN_ID event_sha=${GITHUB_SHA:-unknown} artifact=$ART expected_source=$SRC" | tee "$OUT/environment.txt"
meta="$(curl -fsS -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ART")"
provider="$(printf '%s' "$meta"|python3 -c 'import json,sys;print(json.load(sys.stdin).get("digest",""))')"
[[ "$provider" == "sha256:$ZIP_SHA" ]] || fail "provider digest $provider"
curl -LfsS -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/$ART/zip" -o "$ZIP"
[[ "$(sha "$ZIP")" == "$ZIP_SHA" ]] || fail 'artifact ZIP digest mismatch'
printf 'artifact_id=%s\nprovider_digest=%s\nzip_sha256=%s\n' "$ART" "$provider" "$(sha "$ZIP")" >"$OUT/artifact-authority.txt"
unzip -q "$ZIP" -d "$PKG"
[[ "$(sha "$PKG/SHA256SUMS")" == "$MAN_SHA" ]] || fail 'root manifest digest mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) >"$OUT/manifest-before.txt"
[[ "$(grep -c ': OK$' "$OUT/manifest-before.txt")" -eq 26 ]] || fail 'manifest before != 26/26'
[[ "$(tr -d '\r\n'<"$PKG/metadata/source-commit.txt")" == "$SRC" ]] || fail 'source commit mismatch'
grep -Fxq runtimeExecution=false "$PKG/metadata/command-boundary.txt" || fail 'package not runtime-free compile authority'
grep -Fxq exactArithmeticBackend=GMP "$PKG/metadata/command-boundary.txt" || fail 'package not GMP authority'
SA="$PKG/source/source-$SRC.tar.gz"; [[ "$(sha "$SA")" == "$SRC_SHA" ]] || fail 'source archive digest mismatch'
tar -xzf "$SA" -C "$SOURCE"
selector="$SOURCE/$SEL"; route="$SOURCE/$ROUTE"
[[ "$(wc -l<"$selector")" -eq 448 && "$(sha "$selector")" == "$SEL_SHA" ]] || fail 'selector448 authority mismatch'
[[ "$(wc -l<"$route")" -eq 448 && "$(sha "$route")" == "$ROUTE_SHA" ]] || fail 'routing448 authority mismatch'
R449="$OUT/routing449.tsv"; cp "$route" "$R449"; printf '449\t%s\t%s\n' "$ID449" "$OWNER449" >>"$R449"
python3 - "$selector" "$R449" <<'PY'
import pathlib,sys
s=pathlib.Path(sys.argv[1]).read_text().splitlines(); r=[x.split('\t') for x in pathlib.Path(sys.argv[2]).read_text().splitlines()]
assert len(s)==448 and len(r)==449
assert all(len(x)==3 and int(x[0])==i+1 for i,x in enumerate(r))
assert all(r[i][1]==s[i] for i in range(448))
assert r[-1]==['449','M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion','directional_surface_cell_producer_tests']
assert len({x[1] for x in r})==449
PY
for e in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests; do [[ -x "$PKG/bin/$e" ]]||fail "mode/executable missing $e"; done
cp -a "$PKG/bin/." "$VIEW/bin/"; mkdir -p "$VIEW/test-data/benchmarks"; cp -a "$SOURCE/benchmarks/fixtures" "$VIEW/test-data/benchmarks/"
PKG0="$(treehash "$PKG")"; SRC0="$(treehash "$SOURCE")"; VIEW0="$(treehash "$VIEW")"; printf 'package=%s\nsource=%s\nview=%s\n' "$PKG0" "$SRC0" "$VIEW0" >"$OUT/fingerprints-before.txt"

ledger="$OUT/selector449-ledger.tsv"; printf 'ordinal\tidentity\tbinary\texit\tselected\tskipped\tpassed\tresult\traw_sha256\n' >"$ledger"
runtime=true
while IFS=$'\t' read -r n id bin; do
  raw="$OUT/raw/ordinal-$(printf '%03d' "$n").log"; work="$RUN/ordinal-$(printf '%03d' "$n")"; mkdir -p "$work"
  echo "$TURN_ID ordinal=$n identity=$id owner=$bin"
  set +e; (cd "$work"; env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/$bin" --gtest_filter="$id") >"$raw" 2>&1; code=$?; set -e
  sel="$(grep -Ec '^\[ RUN      \] ' "$raw"||true)"; skip="$(grep -Ec '^\[  SKIPPED \] ' "$raw"||true)"; pass="$(grep -Ec '^\[       OK \] ' "$raw"||true)"
  [[ "$sel" -eq 1 ]]||{ selected_ok=false; fail "exact-one selection failed ordinal=$n selected=$sel"; }; [[ "$skip" -eq 0 ]]||{ selected_ok=false; fail "skip ordinal=$n"; }
  result=RED; [[ "$code" -eq 0 && "$pass" -eq 1 ]]&&result=PASS
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$n" "$id" "$bin" "$code" "$sel" "$skip" "$pass" "$result" "$(sha "$raw")" >>"$ledger"
  executed=$((executed+1))
done <"$R449"
[[ "$executed" -eq 449 ]]||fail "execution count $executed"
complete=true
python3 - "$ledger" "$OUT/semantic-summary.txt" "$OUT/row449-first-failed-fact.txt" "$OUT/raw/ordinal-449.log" <<'PY'
import csv,pathlib,re,sys
r=list(csv.DictReader(open(sys.argv[1]),delimiter='\t')); assert len(r)==449 and [int(x['ordinal']) for x in r]==list(range(1,450))
red=[int(x['ordinal']) for x in r if x['result']!='PASS']; pre=[x for x in red if x<=448]; last=r[-1]
own={}
for x in r: own[x['binary']]=own.get(x['binary'],0)+1
pathlib.Path(sys.argv[2]).write_text(f'total=449\npass={449-len(red)}\nred={len(red)}\nred_ordinals={red}\naccepted_prefix_pass={448-len(pre)}\naccepted_prefix_red={len(pre)}\naccepted_prefix_red_ordinals={pre}\nrow449_result={last["result"]}\nrow449_exit={last["exit"]}\nbenchmark_execution=0\n'+''.join(f'owner_{k}={v}\n' for k,v in sorted(own.items())))
raw=pathlib.Path(sys.argv[4]).read_text(errors='replace'); m=re.search(r'fact\s+([1-6]):([^\n]*)',raw)
pathlib.Path(sys.argv[3]).write_text(f'row449_result={last["result"]}\nfirst_failed_fact={(m.group(1)+":"+m.group(2).strip()) if m else ""}\n')
PY
PKG1="$(treehash "$PKG")"; SRC1="$(treehash "$SOURCE")"; VIEW1="$(treehash "$VIEW")"; [[ "$PKG0" == "$PKG1" && "$SRC0" == "$SRC1" && "$VIEW0" == "$VIEW1" ]]||fail 'immutable postflight fingerprint changed'
[[ "$(sha "$selector")" == "$SEL_SHA" && "$(sha "$route")" == "$ROUTE_SHA" ]]||fail 'selector/routing changed'
(cd "$PKG" && sha256sum -c SHA256SUMS) >"$OUT/manifest-after.txt"; [[ "$(grep -c ': OK$' "$OUT/manifest-after.txt")" -eq 26 ]]||fail 'manifest after != 26/26'
printf 'package=%s\nsource=%s\nview=%s\n' "$PKG1" "$SRC1" "$VIEW1" >"$OUT/fingerprints-after.txt"; echo immutable_postflight=true >"$OUT/immutability.txt"
boundary; echo script_exit=0 >>"$OUT/execution-boundary.txt"
(cd "$OUT"; find . -type f ! -name SHA256SUMS -print0|LC_ALL=C sort -z|xargs -0 sha256sum >SHA256SUMS; sha256sum -c SHA256SUMS >/dev/null)
echo "$TURN_ID COMPLETE: 449 fresh exact-filter processes; semantic interpretation deferred to Review."
