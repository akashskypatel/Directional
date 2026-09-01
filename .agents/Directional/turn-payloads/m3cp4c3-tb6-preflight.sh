#!/usr/bin/env bash
set -euo pipefail
work="${RUNNER_TEMP}/m3-cp4c3-tb6"
result="$work/result"
log="$work/tb6.log"
mkdir -p "$result" "$work/raw" "$work/extract" "$work/source" "$work/runtime-work"
exec > >(tee -a "$log") 2>&1
pkgzip="$work/raw/package75.zip"
outer="$work/raw/outer"
mkdir -p "$outer"
echo '== IMMUTABLE PACKAGE 75 PRE-RUNTIME PREFLIGHT =='
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/9781487311/zip" > "$pkgzip"
echo '547f2441b026b68d2bef10e7c7694faf994be473a1d2db68a6375d06b1e654b8  '"$pkgzip" | sha256sum -c -
unzip -q "$pkgzip" -d "$outer"
echo '8814b700a5c07290ce099ce1f719f01b2fbd5bcfd80f36037fe5bafc600f7896  '"$outer/package75.tar.gz" | sha256sum -c -
tar -xzf "$outer/package75.tar.gz" -C "$work/extract"
pkg="$work/extract/package75"
test "$(find "$pkg" -type f | wc -l | tr -d ' ')" = 58
test "$(awk 'END{print NR}' "$pkg/SHA256SUMS")" = 57
grep -qx 'manifestExcludesSelf=true' "$pkg/metadata/command-boundary.txt"
(cd "$pkg" && sha256sum -c SHA256SUMS)
test "$(cat "$pkg/metadata/source-commit.txt")" = e926ada023bc51220628be550bbe9a87f98d7067
echo '64e5189f3c9f22d648e496c50b4093e842a0fad25a885dca65778d7a110b629a  '"$pkg/source/source-e926ada023bc51220628be550bbe9a87f98d7067.tar.gz" | sha256sum -c -
for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
grep -qx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt"
grep -qx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt"
grep -qx 'packageRepair=false' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'modePreservingEnvelope=true' "$pkg/metadata/package-envelope.txt"
grep -q 'libgmpxx.so' "$pkg/metadata/gmp-evidence.txt"
grep -q 'libgmp.so' "$pkg/metadata/gmp-evidence.txt"
test "$(find "$pkg/test-data/benchmarks/fixtures" -type f | wc -l | tr -d ' ')" = 27
test "$(find "$pkg/bin" -maxdepth 1 -type f -name 'directional_*' | wc -l | tr -d ' ')" = 6
for exe in "$pkg"/bin/directional_*; do test "$(stat -c '%a' "$exe")" = 755; done

tar -xzf "$pkg/source/source-e926ada023bc51220628be550bbe9a87f98d7067.tar.gz" -C "$work/source"
sel_dir="$work/source/.agents/Directional"
declare -A h=(
 [357]=b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70
 [358]=6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62
 [361]=61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b
 [365]=6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1
 [367]=ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf
 [370]=9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525
 [373]=b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834 )
selector_path() { case "$1" in 357|358|361|365) echo "$sel_dir/Architecture_M3_CP4c2_Required_Green_Selector_$1.txt";; *) echo "$sel_dir/Architecture_M3_CP4c3_Required_Green_Selector_$1.txt";; esac; }
for n in 357 358 361 365 367 370 373; do
 p="$(selector_path "$n")"; actual="$(sha256sum "$p" | awk '{print $1}')"
 test "$actual" = "${h[$n]}"; test "$(awk 'END{print NR}' "$p")" = "$n"; test "$(sort "$p" | uniq | wc -l | tr -d ' ')" = "$n"
 printf '%s\t%s\n' "$n" "$actual" >> "$result/selector-hashes.tsv"
done
selector="$(selector_path 373)"
for n in 357 361 365 367 370; do p="$(selector_path "$n")"; head -n "$n" "$selector" > "$work/prefix-$n"; cmp -s "$p" "$work/prefix-$n"; done
p358="$(selector_path 358)"
test -z "$(comm -23 <(LC_ALL=C sort "$p358") <(LC_ALL=C sort "$selector"))"
echo '358 lineage=historical-set-subset-not-byte-prefix' >> "$result/selector-hashes.tsv"
python3 - "$work/source" "$selector" "$result/mapping.tsv" <<'PY'
from pathlib import Path
import re,sys
root=Path(sys.argv[1]); selector=Path(sys.argv[2]); out=Path(sys.argv[3])
targets={
'directional_surface_cell_producer_tests':['tests/AdaptiveFeatureMapPhase11Tests.cpp','tests/AdaptiveTargetSizePhase12Tests.cpp','tests/BoundedMeshPreconditionerTests.cpp','tests/CrossFieldTransferTests.cpp','tests/FieldAlignedCurveNetworkTests.cpp','tests/RegularizedCurvaturePhase1Tests.cpp','tests/SourceGridRecoveryAuthorityTests.cpp','tests/SurfaceCellDesignAcceptanceTests.cpp','tests/SurfaceCellREPackageTests.cpp','tests/SurfaceCellTransitionQuotientTests.cpp','tests/SurfaceCellsPhase10Tests.cpp'],
'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],
'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
rx=re.compile(r'\b(?:TEST|TEST_F|TEST_P)\s*\(\s*([A-Za-z_][A-Za-z0-9_:]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)')
own={}
for target,files in targets.items():
 for rel in files:
  for suite,test in rx.findall((root/rel).read_text(encoding='utf-8')): own.setdefault(f'{suite}.{test}',set()).add(target)
ids=selector.read_text(encoding='utf-8').splitlines()
if len(ids)!=373 or len(set(ids))!=373: raise SystemExit('selector cardinality/uniqueness invalid')
rows=[]
for i,ident in enumerate(ids,1):
 owners=sorted(own.get(ident,()))
 if len(owners)!=1: raise SystemExit(f'static mapping count {len(owners)} for {i}:{ident}:{owners}')
 rows.append(f'{i}\t{ident}\t{owners[0]}')
out.write_text('\n'.join(rows)+'\n',encoding='utf-8')
PY
test "$(wc -l < "$result/mapping.tsv" | tr -d ' ')" = 373
while IFS=$'\t' read -r _ _ target; do test -x "$pkg/bin/$target"; done < "$result/mapping.tsv"
census="$result/preflight-census.tsv"; : > "$census"
while IFS= read -r -d '' f; do rel="${f#$pkg/}"; printf '%s\t%s\t%s\t%s\n' "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f"|awk '{print $1}')" >> "$census"; done < <(find "$pkg" -type f -print0 | sort -z)
test "$(wc -l < "$census" | tr -d ' ')" = 58
cp "$census" "$work/preflight-census.reference.tsv"
echo 'preflight=PASS' | tee "$result/preflight.txt"
