#!/usr/bin/env bash
set -euo pipefail

work="${RUNNER_TEMP}/m3-cp4c3-tb9"
result="$work/result"
log="$work/tb9.log"
mkdir -p "$result" "$work/raw" "$work/extract" "$work/source" "$work/runtime-work"
exec > >(tee -a "$log") 2>&1

pkgzip="$work/raw/package79.zip"
outer="$work/raw/outer"
mkdir -p "$outer"

echo '== IMMUTABLE PACKAGE 79 PRE-RUNTIME PREFLIGHT =='
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/9826005253/zip" > "$pkgzip"
echo '1f9c6e1d098a08eb375d415f2724185043de1c1d5d08cdce46cc716d57e3fa8a  '"$pkgzip" | sha256sum -c -
unzip -q "$pkgzip" -d "$outer"

test "$(awk '{print $1}' "$outer/package79.sha256")" = dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99
test "$(awk '{print $1}' "$outer/source-archive.sha256")" = 61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6
echo 'dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99  '"$outer/package79.tar.gz" | sha256sum -c -

tar -xzf "$outer/package79.tar.gz" -C "$work/extract"
pkg="$work/extract/package79"
manifest_lines="$(awk 'END{print NR}' "$pkg/SHA256SUMS")"
file_count="$(find "$pkg" -type f | wc -l | tr -d ' ')"
test "$manifest_lines" -gt 0
test "$file_count" -eq $((manifest_lines + 1))
grep -qx 'manifestExcludesSelf=true' "$pkg/metadata/command-boundary.txt"
(cd "$pkg" && sha256sum -c SHA256SUMS)

test "$(cat "$pkg/metadata/source-commit.txt")" = 803300698289e0d0f629eaa878add1aebc7193c1
source_archive="$pkg/source/source-803300698289e0d0f629eaa878add1aebc7193c1.tar.gz"
echo '61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6  '"$source_archive" | sha256sum -c -
for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
grep -qx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt"
grep -qx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt"
grep -qx 'packageRepair=false' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'selector=376' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'selector_sha256=6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'frozen_selector_374_sha256=d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'frozen_selector_375_sha256=aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'diagnostic_identity_376=ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'modePreservingEnvelope=true' "$pkg/metadata/package-envelope.txt"
grep -q 'libgmpxx.so' "$pkg/metadata/gmp-evidence.txt"
grep -q 'libgmp.so' "$pkg/metadata/gmp-evidence.txt"
test "$(cat "$pkg/metadata/preflight-exit-code.txt")" = 0
test "$(cat "$pkg/metadata/build-exit-code.txt")" = 0
test "$(find "$pkg/test-data/benchmarks/fixtures" -type f | wc -l | tr -d ' ')" = 27
test "$(find "$pkg/bin" -maxdepth 1 -type f -name 'directional_*' | wc -l | tr -d ' ')" = 6
for exe in "$pkg"/bin/directional_*; do test "$(stat -c '%a' "$exe")" = 755; done

tar -xzf "$source_archive" -C "$work/source"
sel_dir="$work/source/.agents/Directional"
selector374="$sel_dir/Architecture_M3_CP4c3_Required_Green_Selector_374.txt"
selector375="$sel_dir/Architecture_M3_CP4c3_Required_Green_Selector_375.txt"
selector376="$sel_dir/Architecture_M3_CP4c3_Required_Green_Selector_376.txt"

test "$(sha256sum "$selector374" | awk '{print $1}')" = d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f
test "$(sha256sum "$selector375" | awk '{print $1}')" = aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0
test "$(sha256sum "$selector376" | awk '{print $1}')" = 6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8
test "$(awk 'END{print NR}' "$selector374")" = 374
test "$(awk 'END{print NR}' "$selector375")" = 375
test "$(awk 'END{print NR}' "$selector376")" = 376
test "$(sort "$selector374" | uniq | wc -l | tr -d ' ')" = 374
test "$(sort "$selector375" | uniq | wc -l | tr -d ' ')" = 375
test "$(sort "$selector376" | uniq | wc -l | tr -d ' ')" = 376
cmp -s "$selector374" <(head -n 374 "$selector375")
cmp -s "$selector375" <(head -n 375 "$selector376")

printf '374\td496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f\tfrozen\n' > "$result/selector-hashes.tsv"
printf '375\taa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0\tfrozen\n' >> "$result/selector-hashes.tsv"
printf '376\t6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8\texecution\n' >> "$result/selector-hashes.tsv"

python3 - "$work/source" "$selector376" "$result/mapping.tsv" "$result/diagnostic-mapping.tsv" <<'PY'
from pathlib import Path
import re, sys
root = Path(sys.argv[1]); selector = Path(sys.argv[2]); gate_out = Path(sys.argv[3]); diag_out = Path(sys.argv[4])
targets = {
'directional_surface_cell_producer_tests': ['tests/AdaptiveFeatureMapPhase11Tests.cpp','tests/AdaptiveTargetSizePhase12Tests.cpp','tests/BoundedMeshPreconditionerTests.cpp','tests/CrossFieldTransferTests.cpp','tests/FieldAlignedCurveNetworkTests.cpp','tests/RegularizedCurvaturePhase1Tests.cpp','tests/SourceGridRecoveryAuthorityTests.cpp','tests/SurfaceCellDesignAcceptanceTests.cpp','tests/SurfaceCellREPackageTests.cpp','tests/SurfaceCellTransitionQuotientTests.cpp','tests/SurfaceCellsPhase10Tests.cpp'],
'directional_surface_cell_authority_kernel_tests': ['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],
'directional_surface_cell_completion_tests': ['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
'directional_surface_cell_validation_tests': ['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp'],
}
rx = re.compile(r'\b(?:TEST|TEST_F|TEST_P)\s*\(\s*([A-Za-z_][A-Za-z0-9_:]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)')
owners = {}
for target, files in targets.items():
    for rel in files:
        for suite, test in rx.findall((root / rel).read_text(encoding='utf-8')):
            owners.setdefault(f'{suite}.{test}', set()).add(target)
ids = selector.read_text(encoding='utf-8').splitlines()
if len(ids) != 376 or len(set(ids)) != 376: raise SystemExit('selector 376 cardinality/uniqueness invalid')
rows=[]
for ordinal, identity in enumerate(ids,1):
    found=sorted(owners.get(identity,()))
    if len(found)!=1: raise SystemExit(f'static mapping count {len(found)} for {ordinal}:{identity}:{found}')
    if ordinal < 376: rows.append(f'{ordinal}\t{identity}\t{found[0]}')
    else: diag_out.write_text(f'376\t{identity}\t{found[0]}\n',encoding='utf-8')
gate_out.write_text('\n'.join(rows)+'\n',encoding='utf-8')
PY

test "$(wc -l < "$result/mapping.tsv" | tr -d ' ')" = 375
test "$(wc -l < "$result/diagnostic-mapping.tsv" | tr -d ' ')" = 1
while IFS=$'\t' read -r _ _ target; do test -x "$pkg/bin/$target"; done < "$result/mapping.tsv"
while IFS=$'\t' read -r _ _ target; do test -x "$pkg/bin/$target"; done < "$result/diagnostic-mapping.tsv"

census="$result/preflight-census.tsv"; : > "$census"
while IFS= read -r -d '' f; do rel="${f#$pkg/}"; printf '%s\t%s\t%s\t%s\n' "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f" | awk '{print $1}')" >> "$census"; done < <(find "$pkg" -type f -print0 | sort -z)
test "$(wc -l < "$census" | tr -d ' ')" = "$file_count"
cp "$census" "$work/preflight-census.reference.tsv"

printf '%s\n' 'preflight=PASS' 'semantic_source=803300698289e0d0f629eaa878add1aebc7193c1' 'package=79' 'package_artifact_id=9826005253' 'execution_selector=376' 'runtimeExecution=false' | tee "$result/preflight.txt"
