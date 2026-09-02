#!/usr/bin/env bash
set -euo pipefail
work="${RUNNER_TEMP}/m3-cp4c3-tb9"; result="$work/result"; log="$work/tb9.log"; pkg="$work/extract/package79"; src="$work/source"
exec > >(tee -a "$log") 2>&1
echo '== IMMUTABLE POSTFLIGHT =='
(cd "$pkg" && sha256sum -c SHA256SUMS)
source_archive="$pkg/source/source-803300698289e0d0f629eaa878add1aebc7193c1.tar.gz"
echo '61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6  '"$source_archive" | sha256sum -c -
test "$(cat "$pkg/metadata/source-commit.txt")" = 803300698289e0d0f629eaa878add1aebc7193c1
grep -qx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt"; grep -qx 'packageRepair=false' "$pkg/metadata/fixture-package-contract.txt"; grep -qx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt"; grep -q 'libgmpxx.so' "$pkg/metadata/gmp-evidence.txt"; grep -q 'libgmp.so' "$pkg/metadata/gmp-evidence.txt"
for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
for exe in "$pkg"/bin/directional_*; do test "$(stat -c '%a' "$exe")" = 755; done
selector374="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_374.txt"; selector375="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_375.txt"; selector376="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_376.txt"
test "$(sha256sum "$selector374" | awk '{print $1}')" = d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f; test "$(sha256sum "$selector375" | awk '{print $1}')" = aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0; test "$(sha256sum "$selector376" | awk '{print $1}')" = 6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8
test "$(awk 'END{print NR}' "$selector374")" = 374; test "$(awk 'END{print NR}' "$selector375")" = 375; test "$(awk 'END{print NR}' "$selector376")" = 376
cmp -s "$selector374" <(head -n 374 "$selector375"); cmp -s "$selector375" <(head -n 375 "$selector376")
census="$result/postflight-census.tsv"; : > "$census"
while IFS= read -r -d '' f; do rel="${f#$pkg/}"; printf '%s\t%s\t%s\t%s\n' "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f" | awk '{print $1}')" >> "$census"; done < <(find "$pkg" -type f -print0 | sort -z)
cmp -s "$work/preflight-census.reference.tsv" "$census"
printf '%s\n' 'postflight=PASS' 'runtimeExecution=true' 'configureExecution=false' 'compileExecution=false' 'relinkExecution=false' 'packageRepair=false' 'generatedDiscovery=false' 'productMutation=false' 'testMutation=false' 'fixtureMutation=false' 'selectorMutation=false' 'benchmarkExecution=false' "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" | tee "$result/postflight.txt"
