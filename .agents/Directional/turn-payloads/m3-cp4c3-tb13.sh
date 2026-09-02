#!/usr/bin/env bash
set -euo pipefail
log="${RUNNER_TEMP}/tb13.log"; exec > >(tee -a "$log") 2>&1; trap 's=$?; echo "tb13_exit=$s"' EXIT
out="${RUNNER_TEMP}/tb13-result"; envd="${RUNNER_TEMP}/envelope"; pkg="${RUNNER_TEMP}/package83/package83"; src="${RUNNER_TEMP}/source"
mkdir -p "$out" "$envd" "$(dirname "$pkg")" "$src"
archive="${RUNNER_TEMP}/package83.zip"
curl --fail --silent --show-error --location -H "Authorization: Bearer ${TOKEN}" -H 'Accept: application/vnd.github+json' "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/9861269273/zip" -o "$archive"
test "$(sha256sum "$archive"|cut -d' ' -f1)" = 1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4
unzip -q "$archive" -d "$envd"
test "$(sha256sum "$envd/package83.tar.gz"|cut -d' ' -f1)" = c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff
grep -qx 'runtimeExecution=false' "$envd/package83-boundary.txt"; grep -qx 'packageRepair=false' "$envd/package83-boundary.txt"
tar -xzf "$envd/package83.tar.gz" -C "$(dirname "$pkg")"
(cd "$pkg" && sha256sum -c SHA256SUMS) > "$out/pre-manifest.txt"
sarc="$pkg/source/source-a2fd98eaa015ff5872890bb1945cf4e9e9493615.tar.gz"
test "$(sha256sum "$sarc"|cut -d' ' -f1)" = 55305976488edc1edc13432e953787555c5ef5d4dcaff041617c0ae568d922c2
tar -xzf "$sarc" -C "$src"
test "$(cat "$pkg/metadata/source-commit.txt")" = a2fd98eaa015ff5872890bb1945cf4e9e9493615
test "$(cat "$pkg/metadata/build-exit-code.txt")" = 0; test "$(cat "$pkg/metadata/preflight-exit-code.txt")" = 0
grep -q '^runtimeExecution=false$' "$pkg/metadata/package-envelope.txt"; grep -q '^packageRepair=false$' "$pkg/metadata/fixture-package-contract.txt"
grep -q '^exactArithmeticBackend=GMP$' "$pkg/metadata/package-envelope.txt"; grep -q '^modePreservingEnvelope=true$' "$pkg/metadata/package-envelope.txt"
grep -q '^DIRECTIONAL_ENABLE_GMP:BOOL=ON$' "$pkg/metadata/CMakeCache.txt"; grep -q 'libgmpxx' "$pkg/metadata/gmp-evidence.txt"; grep -q 'libgmp\.so' "$pkg/metadata/gmp-evidence.txt"
for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
test "$(find "$pkg/test-data" -type f|wc -l)" -eq 27
helper=.agents/Directional/turn-payloads/m3-cp4c3-tb13.py
python3 "$helper" pre "$pkg" "$out" "$src"
printf 'ordinal\tidentity\ttarget\tresult\tcredit\texit\n' > "$out/results.tsv"
first_red=0; pass=0; red=0; proc=0
while IFS=$'\t' read -r ord ident target; do
  rlog="$out/ordinal-$(printf '%03d' "$ord").log"; set +e
  (cd "$pkg" && "$pkg/bin/$target" "--gtest_filter=$ident" --gtest_color=no) >"$rlog" 2>&1; rc=$?; set -e; proc=$((proc+1))
  test "$(grep -Fxc "[ RUN      ] $ident" "$rlog" || true)" -eq 1; test "$(grep -c '^\[ RUN      \]' "$rlog" || true)" -eq 1
  if [ "$rc" -eq 0 ]; then result=PASS; pass=$((pass+1)); else result=RED; red=$((red+1)); fi
  if [ "$first_red" -eq 0 ]; then credit=gate; [ "$rc" -eq 0 ] || first_red="$ord"; else credit=report-only; fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\n' "$ord" "$ident" "$target" "$result" "$credit" "$rc" >> "$out/results.tsv"
done < "$out/mapping.tsv"
test "$proc" -eq 379
diag='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'; dt="$(cut -f2 "$out/diagnostic-mapping.tsv")"; dlog="$out/non-gating-diagnostic.log"; set +e
(cd "$pkg" && "$pkg/bin/$dt" "--gtest_filter=$diag" --gtest_color=no) >"$dlog" 2>&1; drc=$?; set -e
test "$(grep -Fxc "[ RUN      ] $diag" "$dlog" || true)" -eq 1; test "$(grep -c '^\[ RUN      \]' "$dlog" || true)" -eq 1
[ "$drc" -eq 0 ] && dres=PASS || dres=RED
printf 'identity\ttarget\tresult\tcredit\texit\n%s\t%s\t%s\tnon-gating\t%s\n' "$diag" "$dt" "$dres" "$drc" > "$out/non-gating-diagnostic.tsv"
python3 "$helper" post "$pkg" "$out"
(cd "$pkg" && sha256sum -c SHA256SUMS) > "$out/post-manifest.txt"
printf '%s\n' "package=83" "selector=379" "processes=$proc" "passes=$pass" "reds=$red" "firstRedOrdinal=$first_red" "nonGatingDiagnosticResult=$dres" "nonGatingDiagnosticExit=$drc" "runtimeExecution=true" "configureExecution=false" "compileExecution=false" "relinkExecution=false" "packageRepair=false" "generatedDiscovery=false" "productMutation=false" "testMutation=false" "fixtureMutation=false" "selectorMutation=false" "benchmarkExecution=false" > "$out/summary.env"
cat "$out/summary.env"; cat "$out/bj9-analysis.json"
