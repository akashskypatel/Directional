#!/usr/bin/env bash
set -euo pipefail
work="${RUNNER_TEMP}/m3-cp4c3-tb7"; result="$work/result"; log="$work/tb7.log"; pkg="$work/extract/package76"; src="$work/source"
exec > >(tee -a "$log") 2>&1
echo '== IMMUTABLE POSTFLIGHT =='
(cd "$pkg" && sha256sum -c SHA256SUMS)
echo '71b86aafae465b5dcb1763cc3e0250b4310b188d8f2d6e34ac8d7b8c6c74f6ea  '"$pkg/source/source-e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a.tar.gz" | sha256sum -c -
for exe in "$pkg"/bin/directional_*; do test "$(stat -c '%a' "$exe")" = 755; done
declare -A h=( [357]=b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70 [358]=6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62 [361]=61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b [365]=6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1 [367]=ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf [370]=9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525 [373]=b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834 [374]=d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f )
sel_dir="$src/.agents/Directional"; selector_path(){ case "$1" in 357|358|361|365) echo "$sel_dir/Architecture_M3_CP4c2_Required_Green_Selector_$1.txt";; *) echo "$sel_dir/Architecture_M3_CP4c3_Required_Green_Selector_$1.txt";; esac; }
for n in 357 358 361 365 367 370 373 374; do test "$(sha256sum "$(selector_path "$n")"|awk '{print $1}')" = "${h[$n]}"; done
census="$result/postflight-census.tsv"; : > "$census"
while IFS= read -r -d '' f; do rel="${f#$pkg/}"; printf '%s\t%s\t%s\t%s\n' "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f"|awk '{print $1}')" >> "$census"; done < <(find "$pkg" -type f -print0 | sort -z)
cmp -s "$work/preflight-census.reference.tsv" "$census"
{
 echo postflight=PASS; echo configureExecution=false; echo compileExecution=false; echo relinkExecution=false; echo packageRepair=false; echo generatedDiscovery=false; echo productMutation=false; echo testMutation=false; echo fixtureMutation=false; echo selectorMutation=false; echo benchmarkExecution=false; echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
} | tee "$result/postflight.txt"
