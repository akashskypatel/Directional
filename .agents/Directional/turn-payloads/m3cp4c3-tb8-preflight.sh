#!/usr/bin/env bash
set -euo pipefail

work="${RUNNER_TEMP}/m3-cp4c3-tb8"
result="$work/result"
log="$work/tb8.log"
mkdir -p "$result" "$work/raw" "$work/extract" "$work/source" "$work/runtime-work"
exec > >(tee -a "$log") 2>&1

pkgzip="$work/raw/package78.zip"
outer="$work/raw/outer"
mkdir -p "$outer"

echo '== IMMUTABLE PACKAGE 78 PRE-RUNTIME PREFLIGHT =='
gh api "repos/${GITHUB_REPOSITORY}/actions/artifacts/9819958467/zip" > "$pkgzip"
echo '81414f18af71d5aacf50231a720b2774df71d88b223283c81ce747d13a977a51  '"$pkgzip" | sha256sum -c -
unzip -q "$pkgzip" -d "$outer"

test "$(awk '{print $1}' "$outer/package78.sha256")" = 2cc3541cab1208781e234948228baa2d2b8d7bfdb12d855e6fd912cb30006591
test "$(awk '{print $1}' "$outer/source-archive.sha256")" = c1eadfdc4c1f118b34f9996aec00c2b51537e45e201ff52225b1d06b0d253d11
echo '2cc3541cab1208781e234948228baa2d2b8d7bfdb12d855e6fd912cb30006591  '"$outer/package78.tar.gz" | sha256sum -c -

tar -xzf "$outer/package78.tar.gz" -C "$work/extract"
pkg="$work/extract/package78"

test "$(find "$pkg" -type f | wc -l | tr -d ' ')" = 58
test "$(awk 'END{print NR}' "$pkg/SHA256SUMS")" = 57
grep -qx 'manifestExcludesSelf=true' "$pkg/metadata/command-boundary.txt"
(cd "$pkg" && sha256sum -c SHA256SUMS)

test "$(cat "$pkg/metadata/source-commit.txt")" = e2b59295c9920db5685239c2da188858839fa94f
source_archive="$pkg/source/source-e2b59295c9920db5685239c2da188858839fa94f.tar.gz"
echo 'c1eadfdc4c1f118b34f9996aec00c2b51537e45e201ff52225b1d06b0d253d11  '"$source_archive" | sha256sum -c -

for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
grep -qx 'runtimeExecution=false' "$pkg/metadata/command-boundary.txt"
grep -qx 'exactArithmeticBackend=GMP' "$pkg/metadata/command-boundary.txt"
grep -qx 'packageRepair=false' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'selector=374' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'selector_sha256=d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'diagnostic_selector=375' "$pkg/metadata/fixture-package-contract.txt"
grep -qx 'diagnostic_selector_sha256=aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0' "$pkg/metadata/fixture-package-contract.txt"
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

test "$(sha256sum "$selector374" | awk '{print $1}')" = d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f
test "$(sha256sum "$selector375" | awk '{print $1}')" = aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0
test "$(awk 'END{print NR}' "$selector374")" = 374
test "$(awk 'END{print NR}' "$selector375")" = 375
test "$(sort "$selector374" | uniq | wc -l | tr -d ' ')" = 374
test "$(sort "$selector375" | uniq | wc -l | tr -d ' ')" = 375
cmp -s "$selector374" <(head -n 374 "$selector375")

printf '374\td496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f\tgate\n' > "$result/selector-hashes.tsv"
printf '375\taa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0\tdiagnostic-zero-credit\n' >> "$result/selector-hashes.tsv"

python3 - "$work/source" "$selector374" "$selector375" "$result/mapping.tsv" "$result/diagnostic-mapping.tsv" <<'PY'
from pathlib import Path
import re
import sys

root = Path(sys.argv[1])
selector374 = Path(sys.argv[2])
selector375 = Path(sys.argv[3])
gate_out = Path(sys.argv[4])
diag_out = Path(sys.argv[5])

targets = {
    'directional_surface_cell_producer_tests': [
        'tests/AdaptiveFeatureMapPhase11Tests.cpp',
        'tests/AdaptiveTargetSizePhase12Tests.cpp',
        'tests/BoundedMeshPreconditionerTests.cpp',
        'tests/CrossFieldTransferTests.cpp',
        'tests/FieldAlignedCurveNetworkTests.cpp',
        'tests/RegularizedCurvaturePhase1Tests.cpp',
        'tests/SourceGridRecoveryAuthorityTests.cpp',
        'tests/SurfaceCellDesignAcceptanceTests.cpp',
        'tests/SurfaceCellREPackageTests.cpp',
        'tests/SurfaceCellTransitionQuotientTests.cpp',
        'tests/SurfaceCellsPhase10Tests.cpp',
    ],
    'directional_surface_cell_authority_kernel_tests': [
        'tests/FieldTransportAtlasTests.cpp',
        'tests/SurfaceCellAuthorityKernelTests.cpp',
    ],
    'directional_surface_cell_completion_tests': [
        'tests/FlowRepStrandsPhase15Tests.cpp',
        'tests/PatchDescriptorMilestoneETests.cpp',
        'tests/PureQuadCompletionPhase18Tests.cpp',
        'tests/SurfaceArrangementRowIdentityTests.cpp',
        'tests/SurfaceComplexSimplificationPhase17Tests.cpp',
    ],
    'directional_surface_cell_validation_tests': [
        'tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase19Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase20Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase21Tests.cpp',
        'tests/SurfaceMeshOptimizerPhase22Tests.cpp',
    ],
}

rx = re.compile(
    r'\b(?:TEST|TEST_F|TEST_P)\s*\(\s*([A-Za-z_][A-Za-z0-9_:]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)'
)
owners = {}
for target, files in targets.items():
    for rel in files:
        text = (root / rel).read_text(encoding='utf-8')
        for suite, test in rx.findall(text):
            owners.setdefault(f'{suite}.{test}', set()).add(target)

gate_ids = selector374.read_text(encoding='utf-8').splitlines()
diag_ids = selector375.read_text(encoding='utf-8').splitlines()
if len(gate_ids) != 374 or len(set(gate_ids)) != 374:
    raise SystemExit('selector 374 cardinality/uniqueness invalid')
if len(diag_ids) != 375 or len(set(diag_ids)) != 375:
    raise SystemExit('selector 375 cardinality/uniqueness invalid')
if diag_ids[:374] != gate_ids:
    raise SystemExit('selector 374 is not the exact prefix of selector 375')

gate_rows = []
for ordinal, identity in enumerate(gate_ids, 1):
    found = sorted(owners.get(identity, ()))
    if len(found) != 1:
        raise SystemExit(f'static mapping count {len(found)} for gate {ordinal}:{identity}:{found}')
    gate_rows.append(f'{ordinal}\t{identity}\t{found[0]}')
gate_out.write_text('\n'.join(gate_rows) + '\n', encoding='utf-8')

identity = diag_ids[374]
found = sorted(owners.get(identity, ()))
if len(found) != 1:
    raise SystemExit(f'static mapping count {len(found)} for diagnostic 375:{identity}:{found}')
diag_out.write_text(f'375\t{identity}\t{found[0]}\n', encoding='utf-8')
PY

test "$(wc -l < "$result/mapping.tsv" | tr -d ' ')" = 374
test "$(wc -l < "$result/diagnostic-mapping.tsv" | tr -d ' ')" = 1
while IFS=$'\t' read -r _ _ target; do test -x "$pkg/bin/$target"; done < "$result/mapping.tsv"
while IFS=$'\t' read -r _ _ target; do test -x "$pkg/bin/$target"; done < "$result/diagnostic-mapping.tsv"

census="$result/preflight-census.tsv"
: > "$census"
while IFS= read -r -d '' f; do
    rel="${f#$pkg/}"
    printf '%s\t%s\t%s\t%s\n' \
        "$rel" "$(stat -c '%a' "$f")" "$(stat -c '%s' "$f")" "$(sha256sum "$f" | awk '{print $1}')" \
        >> "$census"
done < <(find "$pkg" -type f -print0 | sort -z)
test "$(wc -l < "$census" | tr -d ' ')" = 58
cp "$census" "$work/preflight-census.reference.tsv"

{
    echo 'preflight=PASS'
    echo 'semantic_source=e2b59295c9920db5685239c2da188858839fa94f'
    echo 'package=78'
    echo 'package_artifact_id=9819958467'
    echo 'gate_selector=374'
    echo 'diagnostic_selector=375'
    echo 'runtimeExecution=false'
} | tee "$result/preflight.txt"
