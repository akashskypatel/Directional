#!/usr/bin/env bash
set -euo pipefail
ARTIFACT_ID=9896472535
EXPECTED_OUTER_SHA='78d1ac33c9db7592a8a852fafe91d0cabd0548ca5cf6309ceb50f689da9d9770'
EXPECTED_INNER_SHA='015c1113e2237e779076e397f4907b8a44f101ce159e566ff482f9c598f51c48'
EXPECTED_SOURCE_SHA='f54461f5cba89fdd8d54ad2a43d8476a1785676419535eaa21e1556e3e9b538a'
EXPECTED_S380='1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e'
EXPECTED_S381='af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90'
EXPECTED_S382='f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a'
EXPECTED_PREFIX365='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
SOURCE_COMMIT='bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e'
DIAG='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'
root="$RUNNER_TEMP/m3-cp4c3-tb17"; envdir="$root/envelope"; tree="$root/tree"; out="$root/result"; src="$root/source"
rm -rf "$root"; mkdir -p "$envdir" "$tree" "$out/ordinals" "$out/diagnostic" "$src"
printf '%s\n' 'turn=M3-CP4c-3-TB17' 'artifactOnly=true' "artifact_id=$ARTIFACT_ID" "source_commit=$SOURCE_COMMIT" \
 'runtimeExecution=true' 'benchmarkExecution=false' 'configureExecution=false' 'compileExecution=false' 'relinkExecution=false' \
 'packageRepair=false' 'generatedDiscovery=false' 'sourceMutation=false' 'testMutation=false' 'fixtureMutation=false' 'selectorMutation=false' \
 "started_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$out/run.env"
meta="$root/artifact.json"
gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID" > "$meta"
test "$(jq -r .name "$meta")" = 'm3-cp4c3-cb19-package87'
test "$(jq -r .workflow_run.id "$meta")" = '33763450567'
test "$(jq -r .digest "$meta")" = "sha256:$EXPECTED_OUTER_SHA"
test "$(jq -r .expired "$meta")" = false
zip="$root/package87.zip"; gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID/zip" > "$zip"
test "$(sha256sum "$zip" | awk '{print $1}')" = "$EXPECTED_OUTER_SHA"
unzip -q "$zip" -d "$envdir"
inner="$envdir/package87.tar.gz"; test -f "$inner"; test "$(sha256sum "$inner" | awk '{print $1}')" = "$EXPECTED_INNER_SHA"
tar -xzf "$inner" -C "$tree"; pkg="$tree/package87"; test -d "$pkg"
(cd "$pkg" && sha256sum -c SHA256SUMS > "$out/internal-sha256-check.txt")
test "$(cat "$pkg/metadata/source-commit.txt")" = "$SOURCE_COMMIT"
grep -Fx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt" >/dev/null
grep -E 'gmpxx|gmp' "$pkg/metadata/gmp-evidence.txt" >/dev/null
contract="$pkg/metadata/fixture-package-contract.txt"
for line in 'package=87' 'fixture_count=27' 'fixture_authority=package-relative' 'selector=382' \
 "selector_sha256=$EXPECTED_S382" "accepted_selector_365_sha256=$EXPECTED_PREFIX365" "non_gating_diagnostic_identity=$DIAG" \
 'runtimeExecution=false' 'packageRepair=false'; do grep -Fx "$line" "$contract" >/dev/null; done
test "$(find "$pkg/test-data/benchmarks/fixtures" -type f | wc -l | tr -d ' ')" = 27
test -f "$pkg/test-data/benchmarks/fixtures/milestone_g_manifest.json"
for b in directional_benchmarks directional_compiled_api_tests directional_surface_cell_authority_kernel_tests directional_surface_cell_completion_tests directional_surface_cell_producer_tests directional_surface_cell_validation_tests; do
 test -x "$pkg/bin/$b"; test "$(stat -c '%a' "$pkg/bin/$b")" = 755
done
census(){ (cd "$pkg"; find . -type f -print0 | LC_ALL=C sort -z | while IFS= read -r -d '' f; do printf '%s\t%s\t%s\t%s\n' "${f#./}" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f"|awk '{print $1}')"; done) > "$1"; }
census "$out/preflight-census.tsv"; test "$(wc -l < "$out/preflight-census.tsv" | tr -d ' ')" = 58
source_tar="$pkg/source/source-$SOURCE_COMMIT.tar.gz"; test -f "$source_tar"; test "$(sha256sum "$source_tar"|awk '{print $1}')" = "$EXPECTED_SOURCE_SHA"
tar -xzf "$source_tar" -C "$src"
s365="$src/.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt"
s380="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_380.txt"
s381="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_381.txt"
s382="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_382.txt"
test "$(sha256sum "$s365"|awk '{print $1}')" = "$EXPECTED_PREFIX365"
test "$(sha256sum "$s380"|awk '{print $1}')" = "$EXPECTED_S380"
test "$(sha256sum "$s381"|awk '{print $1}')" = "$EXPECTED_S381"
test "$(sha256sum "$s382"|awk '{print $1}')" = "$EXPECTED_S382"
test "$(wc -l < "$s382"|tr -d ' ')" = 382; test "$(LC_ALL=C sort -u "$s382"|wc -l|tr -d ' ')" = 382
cmp -s "$s365" <(head -n365 "$s382"); cmp -s "$s380" <(head -n380 "$s382"); cmp -s "$s381" <(head -n381 "$s382")
# TestFixturePaths resolves bin/../test-data first; prove that exact runtime root before any Directional process.
test -d "$pkg/bin/../test-data/benchmarks/fixtures"; test -f "$pkg/bin/../test-data/benchmarks/fixtures/milestone_g_manifest.json"
echo preflight=PASS > "$out/preflight.env"
owner(){ local n=$1; if ((n<=17));then echo directional_surface_cell_producer_tests; elif ((n<=28));then echo directional_surface_cell_authority_kernel_tests; elif ((n<=40));then echo directional_surface_cell_completion_tests; elif ((n<=46));then echo directional_surface_cell_producer_tests; elif ((n<=104));then echo directional_surface_cell_completion_tests; elif ((n<=112));then echo directional_surface_cell_validation_tests; elif ((n==113));then echo directional_surface_cell_completion_tests; elif ((n<=154));then echo directional_surface_cell_producer_tests; elif ((n<=173));then echo directional_surface_cell_authority_kernel_tests; elif ((n<=207));then echo directional_surface_cell_producer_tests; elif ((n==208));then echo directional_surface_cell_completion_tests; elif ((n<=257));then echo directional_surface_cell_producer_tests; elif ((n<=260));then echo directional_surface_cell_completion_tests; elif ((n<=293));then echo directional_surface_cell_validation_tests; else echo directional_surface_cell_producer_tests; fi; }
printf 'ordinal\tdisposition\texit_code\tbinary\tidentity\n' > "$out/results.tsv"
pass=0; red=0; apass=0; ared=0; first=0; n=0
while IFS= read -r id; do
 n=$((n+1)); test -n "$id"; bin=$(owner "$n"); log="$out/ordinals/$(printf '%03d' "$n").log"
 echo "TB17 ordinal=$n owner=$bin identity=$id"
 set +e; (cd "$pkg"; "$pkg/bin/$bin" --gtest_filter="$id") >"$log" 2>&1; code=$?; set -e
 if ! grep -Fqx "Note: Google Test filter = $id" "$log" || ! grep -Eq '^\[==========\] Running 1 test from 1 test (suite|case)\.$' "$log" || ! grep -Fqx "[ RUN      ] $id" "$log"; then echo "invalid exact selection at ordinal $n" >&2; cat "$log" >&2; exit 90; fi
 if [ "$code" -eq 0 ]; then
   if ! grep -Fq "[       OK ] $id" "$log"; then echo "zero exit without matching OK line at ordinal $n" >&2; cat "$log" >&2; exit 91; fi
   d=PASS; pass=$((pass+1)); ((n<=365))&&apass=$((apass+1))
 else
   d=RED; red=$((red+1)); ((first==0))&&first=$n; ((n<=365))&&ared=$((ared+1))
 fi
 printf '%s\t%s\t%s\t%s\t%s\n' "$n" "$d" "$code" "$bin" "$id" >> "$out/results.tsv"
done < "$s382"; test "$n" = 382
awk -F'\t' 'NR==1 || $2=="RED"' "$out/results.tsv" > "$out/red-results.tsv"
sha256sum "$out/results.tsv" > "$out/results.tsv.sha256"
bin=directional_surface_cell_producer_tests; log="$out/diagnostic/MechanicalWitnessStageReachabilityIsObservable.log"
set +e; (cd "$pkg"; "$pkg/bin/$bin" --gtest_filter="$DIAG") >"$log" 2>&1; dcode=$?; set -e
if ! grep -Fqx "Note: Google Test filter = $DIAG" "$log" || ! grep -Eq '^\[==========\] Running 1 test from 1 test (suite|case)\.$' "$log" || ! grep -Fqx "[ RUN      ] $DIAG" "$log"; then echo 'invalid diagnostic selection' >&2; cat "$log" >&2; exit 92; fi
if [ "$dcode" -eq 0 ]; then grep -Fq "[       OK ] $DIAG" "$log" || { cat "$log" >&2; exit 91; }; dd=PASS; else dd=RED; fi
printf 'identity\tdisposition\texit_code\tbinary\n%s\t%s\t%s\t%s\n' "$DIAG" "$dd" "$dcode" "$bin" > "$out/diagnostic.tsv"
census "$out/postflight-census.tsv"; cmp -s "$out/preflight-census.tsv" "$out/postflight-census.tsv" || { diff -u "$out/preflight-census.tsv" "$out/postflight-census.tsv" > "$out/postflight-census.diff" || true; exit 93; }
sha256sum "$out/preflight-census.tsv" > "$out/census.sha256"
echo package_postflight=IDENTICAL > "$out/postflight.env"
printf '%s\n' "selector_attempted=$n" "selector_pass=$pass" "selector_red=$red" "accepted_prefix_pass=$apass" "accepted_prefix_red=$ared" "first_red_ordinal=$first" \
 "diagnostic_disposition=$dd" "diagnostic_exit_code=$dcode" 'package_postflight=IDENTICAL' 'runtimeExecution=true' 'benchmarkExecution=false' 'configureExecution=false' \
 'compileExecution=false' 'relinkExecution=false' 'packageRepair=false' 'generatedDiscovery=false' 'sourceMutation=false' 'testMutation=false' 'fixtureMutation=false' 'selectorMutation=false' \
 "finished_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$out/summary.env"
cat "$out/summary.env"
