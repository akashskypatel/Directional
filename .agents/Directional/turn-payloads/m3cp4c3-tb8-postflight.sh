#!/usr/bin/env bash
set -euo pipefail

work="${RUNNER_TEMP}/m3-cp4c3-tb8"
result="$work/result"
log="$work/tb8.log"
pkg="$work/extract/package78"
src="$work/source"
exec > >(tee -a "$log") 2>&1

echo '== IMMUTABLE POSTFLIGHT =='
(cd "$pkg" && sha256sum -c SHA256SUMS)
source_archive="$pkg/source/source-e2b59295c9920db5685239c2da188858839fa94f.tar.gz"
echo 'c1eadfdc4c1f118b34f9996aec00c2b51537e45e201ff52225b1d06b0d253d11  '"$source_archive" | sha256sum -c -
test "$(cat "$pkg/metadata/source-commit.txt")" = e2b59295c9920db5685239c2da188858839fa94f
grep -qx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt"
grep -qx 'packageRepair=false' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt"
grep -q 'libgmpxx.so' "$pkg/metadata/gmp-evidence.txt"
grep -q 'libgmp.so' "$pkg/metadata/gmp-evidence.txt"
for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
for exe in "$pkg"/bin/directional_*; do test "$(stat -c '%a' "$exe")" = 755; done

selector374="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_374.txt"
selector375="$src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_375.txt"
test "$(sha256sum "$selector374" | awk '{print $1}')" = d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f
test "$(sha256sum "$selector375" | awk '{print $1}')" = aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0
test "$(awk 'END{print NR}' "$selector374")" = 374
test "$(awk 'END{print NR}' "$selector375")" = 375
cmp -s "$selector374" <(head -n 374 "$selector375")

census="$result/postflight-census.tsv"
: > "$census"
while IFS= read -r -d '' f; do
    rel="${f#$pkg/}"
    printf '%s\t%s\t%s\t%s\n' \
        "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f" | awk '{print $1}')" \
        >> "$census"
done < <(find "$pkg" -type f -print0 | sort -z)
cmp -s "$work/preflight-census.reference.tsv" "$census"

{
    echo 'postflight=PASS'
    echo 'runtimeExecution=true'
    echo 'configureExecution=false'
    echo 'compileExecution=false'
    echo 'relinkExecution=false'
    echo 'packageRepair=false'
    echo 'generatedDiscovery=false'
    echo 'productMutation=false'
    echo 'testMutation=false'
    echo 'fixtureMutation=false'
    echo 'selectorMutation=false'
    echo 'benchmarkExecution=false'
    echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
} | tee "$result/postflight.txt"
