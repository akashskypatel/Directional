#!/usr/bin/env bash
set -euo pipefail
log="${RUNNER_TEMP}/cp4c3-tb3-r1.log"
out="${RUNNER_TEMP}/cp4c3-tb3-r1-result"
w="${RUNNER_TEMP}/cp4c3-tb3-r1"
rm -rf "$out" "$w"; mkdir -p "$out/runtime" "$w/outer" "$w/pkg" "$w/src" "$w/cwd"
: > "$log"; exec > >(tee -a "$log") 2>&1
verdict=BLOCKED; reason=initializing; executed=0; passed=0; red=0; first_ordinal=; first_identity=; runtime=false
write_result(){ cat > "$out/result.env" <<EOF
turn=M3-CP4c-3-TB3-R1
semantic_verdict=$verdict
reason=$reason
executed=$executed
passed=$passed
red=$red
first_red_ordinal=$first_ordinal
first_red_identity=$first_identity
runtimeExecution=$runtime
benchmarkExecution=false
configure=false
compile=false
relink=false
packageRepair=false
generatedDiscovery=false
productMutation=false
testMutation=false
fixtureMutation=false
selectorMutation=false
package_artifact_id=$PACKAGE_ARTIFACT_ID
package_outer_sha256=$PACKAGE_OUTER_SHA256
package72_tar_sha256=$PACKAGE_TAR_SHA256
semantic_source=$SOURCE_SHA
source_archive_sha256=$SOURCE_ARCHIVE_SHA256
selector_sha256=$SELECTOR_SHA256
EOF
}
trap 's=$?; write_result; echo "script_exit=$s"; cat "$out/result.env"' EXIT
die(){ verdict=BLOCKED; reason="$1"; echo "BLOCKED: $reason" >&2; exit 2; }
sha(){ sha256sum "$1" | awk '{print $1}'; }
echo "turn=M3-CP4c-3-TB3-R1 run_id=$GITHUB_RUN_ID event_sha=$GITHUB_SHA started_at=$(date -u +%FT%TZ)"
echo 'runtime boundary: immutable package 72 only; no repair/build/generated discovery/benchmark'

curl --fail-with-body --silent --show-error --location \
  -H "Authorization: Bearer $GH_TOKEN" -H 'Accept: application/vnd.github+json' -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${PACKAGE_ARTIFACT_ID}/zip" -o "$w/package-actions.zip"
[[ "$(sha "$w/package-actions.zip")" == "$PACKAGE_OUTER_SHA256" ]] || die outer-artifact-digest-mismatch
unzip -q "$w/package-actions.zip" -d "$w/outer"
[[ -f "$w/outer/package72.tar.gz" && -f "$w/outer/package72.tar.gz.sha256" && -f "$w/outer/result.env" ]] || die package72-envelope-missing
[[ "$(sha "$w/outer/package72.tar.gz")" == "$PACKAGE_TAR_SHA256" ]] || die inner-tar-digest-mismatch
grep -F "${PACKAGE_TAR_SHA256}  package72.tar.gz" "$w/outer/package72.tar.gz.sha256" >/dev/null || die inner-digest-sidecar-mismatch
tar -xzf "$w/outer/package72.tar.gz" -C "$w/pkg"
cd "$w/pkg"
[[ "$(grep -c . SHA256SUMS)" == 55 ]] || die manifest-cardinality-mismatch
sha256sum -c SHA256SUMS || die package-manifest-failed
[[ "$(cat metadata/source-commit.txt)" == "$SOURCE_SHA" ]] || die source-sha-mismatch
[[ "$(sha "source/source-${SOURCE_SHA}.tar.gz")" == "$SOURCE_ARCHIVE_SHA256" ]] || die source-archive-digest-mismatch
for f in metadata/source-status-before-configure.txt metadata/source-status-after-configure.txt metadata/source-status-after-build.txt metadata/source-status-final.txt metadata/source-status-preconfigure.txt; do [[ ! -s "$f" ]] || die source-status-not-clean; done
grep -Fx 'runtimeExecution=false' metadata/command-boundary.txt >/dev/null || die compile-runtime-boundary-missing
grep -Fx 'exactArithmeticBackend=GMP' metadata/command-boundary.txt >/dev/null || die gmp-boundary-missing
grep -F 'libgmpxx.so' metadata/gmp-evidence.txt >/dev/null || die gmpxx-evidence-missing
grep -F 'libgmp.so' metadata/gmp-evidence.txt >/dev/null || die gmp-evidence-missing
cat > "$w/binaries.tsv" <<EOF
$HASH_BENCHMARKS bin/directional_benchmarks
$HASH_COMPILED_API bin/directional_compiled_api_tests
$HASH_AUTHORITY bin/directional_surface_cell_authority_kernel_tests
$HASH_COMPLETION bin/directional_surface_cell_completion_tests
$HASH_PRODUCER bin/directional_surface_cell_producer_tests
$HASH_VALIDATION bin/directional_surface_cell_validation_tests
EOF
while read -r h p; do [[ "$(stat -c '%a' "$p")" == 755 ]] || die "binary-mode-${p##*/}"; [[ "$(sha "$p")" == "$h" ]] || die "binary-hash-${p##*/}"; done < "$w/binaries.tsv"
[[ "$(find test-data/benchmarks/fixtures -type f | wc -l | tr -d ' ')" == 27 ]] || die fixture-count-mismatch
for f in milestone-g/mechanical_feature.obj milestone-g/mechanical_feature.rawfield milestone-g/sphere_prescribed.obj milestone-g/sphere_prescribed.rawfield milestone-g/sphere_prescribed.fieldmeta.json; do [[ -f "test-data/benchmarks/fixtures/$f" ]] || die "fixture-missing-$f"; done
tar -xzf "source/source-${SOURCE_SHA}.tar.gz" -C "$w/src"
[[ ! $(grep -R -n 'DIRECTIONAL_TEST_SOURCE_DIR' "$w/src/tests/TestFixturePaths.h" "$w/src/cmake/DirectionalTests.cmake" || true) ]] || die absolute-source-fixture-fallback-present
sel="$w/src/.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_373.txt"
[[ "$(sha "$sel")" == "$SELECTOR_SHA256" ]] || die selector-digest-mismatch
[[ "$(grep -c . "$sel")" == 373 ]] || die selector-cardinality-mismatch
[[ "$(sort -u "$sel" | grep -c .)" == 373 ]] || die selector-uniqueness-mismatch
for spec in "355:$PREFIX355" "357:$PREFIX357" "361:$PREFIX361" "365:$PREFIX365" "367:$PREFIX367" "370:$PREFIX370"; do n=${spec%%:*}; h=${spec#*:}; head -n "$n" "$sel" > "$w/prefix"; [[ "$(sha "$w/prefix")" == "$h" ]] || die "selector-prefix-$n"; done
python3 - "$w/src" "$sel" "$out/identity-map.tsv" <<'PY'
import re,sys
from pathlib import Path
root=Path(sys.argv[1]); selector=[x.strip() for x in Path(sys.argv[2]).read_text().splitlines() if x.strip()]
targets={
'bin/directional_surface_cell_producer_tests':['AdaptiveFeatureMapPhase11Tests.cpp','AdaptiveTargetSizePhase12Tests.cpp','BoundedMeshPreconditionerTests.cpp','CrossFieldTransferTests.cpp','FieldAlignedCurveNetworkTests.cpp','RegularizedCurvaturePhase1Tests.cpp','SourceGridRecoveryAuthorityTests.cpp','SurfaceCellDesignAcceptanceTests.cpp','SurfaceCellREPackageTests.cpp','SurfaceCellTransitionQuotientTests.cpp','SurfaceCellsPhase10Tests.cpp'],
'bin/directional_surface_cell_authority_kernel_tests':['FieldTransportAtlasTests.cpp','SurfaceCellAuthorityKernelTests.cpp'],
'bin/directional_surface_cell_completion_tests':['FlowRepStrandsPhase15Tests.cpp','PatchDescriptorMilestoneETests.cpp','PureQuadCompletionPhase18Tests.cpp','SurfaceArrangementRowIdentityTests.cpp','SurfaceComplexSimplificationPhase17Tests.cpp'],
'bin/directional_surface_cell_validation_tests':['SourceAuthoritativeMeshValidatorPhase22Tests.cpp','SurfaceMeshOptimizerPhase19Tests.cpp','SurfaceMeshOptimizerPhase20Tests.cpp','SurfaceMeshOptimizerPhase21Tests.cpp','SurfaceMeshOptimizerPhase22Tests.cpp']}
own={}
for target,files in targets.items():
  for name in files:
    text=(root/'tests'/name).read_text(errors='replace')
    for m in re.finditer(r'\bTEST(?:_F)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',text,re.S): own.setdefault(f'{m.group(1)}.{m.group(2)}',[]).append(target)
rows=[]; counts={k:0 for k in targets}
for i,ident in enumerate(selector,1):
  hits=sorted(set(own.get(ident,[])))
  if len(hits)!=1: raise SystemExit(f'static owner count {len(hits)} at ordinal {i}: {ident}: {hits}')
  counts[hits[0]]+=1; rows.append(f'{i}\t{hits[0]}\t{ident}\n')
if sorted(counts.values())!=[30,41,75,227]: raise SystemExit(f'unexpected target counts: {counts}')
Path(sys.argv[3]).write_text(''.join(rows)); print('static_target_counts='+repr(counts)); print('static_selector_owners=373')
PY
python3 - "$w/pkg" > "$w/tree.before" <<'PY'
import hashlib,os,sys
from pathlib import Path
r=Path(sys.argv[1])
for p in sorted(x for x in r.rglob('*') if x.is_file()): print(f'{p.stat().st_mode&0o7777:04o} {hashlib.sha256(p.read_bytes()).hexdigest()} {p.relative_to(r)}')
PY
reason=executing
while IFS=$'\t' read -r ordinal binary identity; do
  runtime=true; executed=$((executed+1)); f="$out/runtime/$(printf '%03d' "$ordinal").log"
  set +e
  (cd "$w/cwd" && "$w/pkg/$binary" --gtest_color=no --gtest_filter="$identity") >"$f" 2>&1
  rc=$?
  set -e
  grep -Eq '\[==========\] Running 1 test from 1 test suite\.' "$f" || die "runtime-selection-not-one-ordinal-$ordinal"
  if (( rc != 0 )); then verdict=RED; reason=semantic-first-red; red=1; first_ordinal=$ordinal; first_identity=$identity; echo "FIRST_RED ordinal=$ordinal identity=$identity rc=$rc"; cat "$f"; break; fi
  passed=$((passed+1)); echo "PASS ordinal=$ordinal identity=$identity"
done < "$out/identity-map.tsv"
if (( red == 0 && executed == 373 && passed == 373 )); then verdict=GREEN; reason=all-373-pass; fi
cd "$w/pkg"; sha256sum -c SHA256SUMS >/dev/null || die postflight-manifest-failed
while read -r h p; do [[ "$(stat -c '%a' "$p")" == 755 && "$(sha "$p")" == "$h" ]] || die "postflight-binary-$p"; done < "$w/binaries.tsv"
python3 - "$w/pkg" > "$w/tree.after" <<'PY'
import hashlib,sys
from pathlib import Path
r=Path(sys.argv[1])
for p in sorted(x for x in r.rglob('*') if x.is_file()): print(f'{p.stat().st_mode&0o7777:04o} {hashlib.sha256(p.read_bytes()).hexdigest()} {p.relative_to(r)}')
PY
cmp -s "$w/tree.before" "$w/tree.after" || die package-tree-mutated
[[ "$(sha "$sel")" == "$SELECTOR_SHA256" ]] || die postflight-selector-mutated
echo "FINAL verdict=$verdict executed=$executed passed=$passed red=$red first_red_ordinal=${first_ordinal:-none}"
