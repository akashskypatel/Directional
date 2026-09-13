#!/usr/bin/env bash
set -euo pipefail

: "${GITHUB_REPOSITORY:?}"
: "${GITHUB_RUN_ID:?}"
: "${GH_TOKEN:?}"
: "${TURN_ID:?}"
: "${ARTIFACT_ID:?}"
: "${EXPECTED_ARTIFACT_NAME:?}"
: "${EXPECTED_PROVIDER_DIGEST:?}"
: "${EXPECTED_ZIP_SHA256:?}"

EXPECTED_SOURCE_SHA='b576d061e23873b7b4193b158138d2097c75a728'
EXPECTED_SOURCE_ARCHIVE_SHA256='31e667a6891f9f9d2c938da98c7d23d048c3d60f6960e139e379631e7aa70c10'
EXPECTED_MANIFEST_SHA256='fdaf919a29eb77a99fea6f672f158010f664ec2580f4f62f04729c0217648f89'
EXPECTED_MANIFEST_ENTRIES=24
SELECTOR408_REL='.agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt'
EXPECTED_SELECTOR408_COUNT=408
EXPECTED_SELECTOR408_SHA256='c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484'
EXPECTED_FOCUSED_GATES=14
EXPECTED_REPORT_ONLY=1
EXPECTED_SELECTOR_GATES=408

FOCUSED_IDENTITIES=(
  'InputConditionerCPCondCB1.IdentityProducedSeparatesRawAndSemanticDigests'
  'InputConditionerCPCondCB1.ExactDyadicQuantizationRecordsNonEmptyOperation'
  'InputConditionerCPCondCB1.ExactEqualityMergeUsesMinimumRawOwner'
  'InputConditionerCPCondCB1.UnsafeDisconnectedExactMergeIsTypedRefusal'
  'InputConditionerCPCondCB1.ExactRationalSliverPredicateRefusesWithoutRepair'
  'InputConditionerCPCondCB1.HighValenceRawPreconditionIsIndependentAndProduced'
  'InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved'
  'InputConditionerCPCondCB1.ContradictoryExactZ4PairingIsTypedRefusal'
  'InputConditionerCPCondCB1.CertificateTamperMatrixRejectsEveryAuthorityClass'
  'InputConditionerCPCondCB1.IdempotenceHoldsForCleanAndNonEmptyOperationProducts'
  'InputConditionerCPCondCB1.ExactSameLatticeCellPerturbationsShareSemanticDigest'
  'InputConditionerCPCondCB1.LegacyPreconditionerCannotSubstituteForCertificate'
  'InputConditionerCPCondCB1.TolerantRawFieldFinalizationCannotReplaceExactCertificate'
  'InputConditionerCPCondCB1.SurfaceCellsRawEntryRejectsAtConditionerBeforeA0'
)
REPORT_ONLY_IDENTITY='InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker'

SAFE_TURN_ID="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="${RUNNER_TEMP}/${SAFE_TURN_ID}"
PKG="${ROOT}/package"
SOURCE="${ROOT}/source"
EXEC_VIEW="${ROOT}/execution-view"
RESULT="${RUNNER_TEMP}/${SAFE_TURN_ID}-result"
LOG="${RUNNER_TEMP}/${SAFE_TURN_ID}.log"
ZIP="${ROOT}/artifact-${ARTIFACT_ID}.zip"
mkdir -p "$PKG" "$SOURCE" "$EXEC_VIEW" "$RESULT"
: > "$LOG"
exec > >(tee -a "$LOG") 2>&1

runtime_started=false
runtime_completed=false
preflight_completed=false
postflight_completed=false
package_preflight_red=false
orchestration_failure=false
selection_integrity=true
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
source_test_fixture_selector_mutation=false
processes_executed=0
pass_count=0
red_count=0
skip_count=0
crash_count=0
selection_mismatch_count=0
stop_kind='NONE'
stop_detail='NONE'
package_census_equal='not-run'
source_census_equal='not-run'
execution_view_census_equal='not-run'

sha_file() { sha256sum "$1" | awk '{print $1}'; }

census_tree() {
  local root="$1" out="$2"
  python3 - "$root" "$out" <<'PY'
import hashlib, os, pathlib, stat, sys
root = pathlib.Path(sys.argv[1]).resolve()
out = pathlib.Path(sys.argv[2])
rows = []
for path in sorted(root.rglob('*'), key=lambda p: p.relative_to(root).as_posix()):
    rel = path.relative_to(root).as_posix()
    st = path.lstat()
    mode = format(stat.S_IMODE(st.st_mode), 'o')
    if stat.S_ISREG(st.st_mode):
        h = hashlib.sha256()
        with path.open('rb') as f:
            for chunk in iter(lambda: f.read(1024 * 1024), b''):
                h.update(chunk)
        kind, digest, target = 'file', h.hexdigest(), '-'
    elif stat.S_ISDIR(st.st_mode):
        kind, digest, target = 'directory', '-', '-'
    elif stat.S_ISLNK(st.st_mode):
        kind, digest, target = 'symlink', '-', os.readlink(path)
    else:
        kind, digest, target = 'other', '-', '-'
    rows.append(f'{rel}\t{kind}\t{mode}\t{st.st_size}\t{digest}\t{target}\n')
out.write_text(''.join(rows), encoding='utf-8')
PY
}

finish() {
  status=$?
  set +e
  if [[ -d "$PKG" && -f "${RESULT}/package-census-pre.tsv" ]]; then
    census_tree "$PKG" "${RESULT}/package-census-post.tsv" 2>/dev/null
    if cmp -s "${RESULT}/package-census-pre.tsv" "${RESULT}/package-census-post.tsv"; then package_census_equal=true; else package_census_equal=false; fi
  fi
  if [[ -d "$SOURCE" && -f "${RESULT}/source-census-pre.tsv" ]]; then
    census_tree "$SOURCE" "${RESULT}/source-census-post.tsv" 2>/dev/null
    if cmp -s "${RESULT}/source-census-pre.tsv" "${RESULT}/source-census-post.tsv"; then source_census_equal=true; else source_census_equal=false; fi
  fi
  if [[ -d "$EXEC_VIEW" && -f "${RESULT}/execution-view-census-pre.tsv" ]]; then
    census_tree "$EXEC_VIEW" "${RESULT}/execution-view-census-post.tsv" 2>/dev/null
    if cmp -s "${RESULT}/execution-view-census-pre.tsv" "${RESULT}/execution-view-census-post.tsv"; then execution_view_census_equal=true; else execution_view_census_equal=false; fi
  fi
  {
    echo "script_exit=${status}"
    echo "turn_id=${TURN_ID}"
    echo "runtime_started=${runtime_started}"
    echo "runtime_completed=${runtime_completed}"
    echo "preflight_completed=${preflight_completed}"
    echo "postflight_completed=${postflight_completed}"
    echo "package_preflight_red=${package_preflight_red}"
    echo "orchestration_failure=${orchestration_failure}"
    echo "selection_integrity=${selection_integrity}"
    echo "expected_focused_gates=${EXPECTED_FOCUSED_GATES}"
    echo "expected_report_only=${EXPECTED_REPORT_ONLY}"
    echo "expected_selector_gates=${EXPECTED_SELECTOR_GATES}"
    echo "processes_executed=${processes_executed}"
    echo "pass_count=${pass_count}"
    echo "red_count=${red_count}"
    echo "skip_count=${skip_count}"
    echo "crash_count=${crash_count}"
    echo "selection_mismatch_count=${selection_mismatch_count}"
    echo "stop_kind=${stop_kind}"
    echo "stop_detail=${stop_detail}"
    echo "package_census_equal=${package_census_equal}"
    echo "source_census_equal=${source_census_equal}"
    echo "execution_view_census_equal=${execution_view_census_equal}"
    echo "benchmark_execution=${benchmark_execution}"
    echo "configure_execution=${configure_execution}"
    echo "compile_execution=${compile_execution}"
    echo "relink_execution=${relink_execution}"
    echo "generated_discovery=${generated_discovery}"
    echo "package_repair=${package_repair}"
    echo "source_test_fixture_selector_mutation=${source_test_fixture_selector_mutation}"
  } | tee "${RESULT}/execution-boundary.txt"
  echo "finished_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)" | tee -a "$LOG"
}
trap finish EXIT

fail_orchestration() {
  orchestration_failure=true
  stop_kind='ORCHESTRATION_FAILURE'
  stop_detail="$*"
  echo "ORCHESTRATION_FAILURE: $*" >&2
  exit 90
}

fail_package_preflight() {
  package_preflight_red=true
  stop_kind='PACKAGE_PREFLIGHT_RED'
  stop_detail="$*"
  echo "PACKAGE_PREFLIGHT_RED: $*" >&2
  exit 91
}

{
  echo "turn_id=${TURN_ID}"
  echo "workflow=${GITHUB_WORKFLOW:-unknown}"
  echo "run_id=${GITHUB_RUN_ID}"
  echo "event=${GITHUB_EVENT_NAME:-unknown}"
  echo "event_sha=${GITHUB_SHA:-unknown}"
  echo "repository=${GITHUB_REPOSITORY}"
  echo "runner_os=${RUNNER_OS:-unknown}"
  echo "artifact_id=${ARTIFACT_ID}"
  echo "expected_source_sha=${EXPECTED_SOURCE_SHA}"
  echo "harness_sha256=$(sha_file "${BASH_SOURCE[0]}")"
  echo "suite_timeout_policy=none"
  echo "started_at=$(date -u +%Y-%m-%dT%H:%M:%SZ)"
} | tee "${RESULT}/environment.txt"

artifact_json="$(curl --fail --silent --show-error \
  -H "Authorization: Bearer ${GH_TOKEN}" \
  -H 'Accept: application/vnd.github+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}")" || fail_orchestration 'artifact metadata request failed'
provider_digest="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("digest", ""))')"
artifact_name="$(printf '%s' "$artifact_json" | python3 -c 'import json,sys; print(json.load(sys.stdin).get("name", ""))')"
[[ "$provider_digest" == "$EXPECTED_PROVIDER_DIGEST" ]] || fail_package_preflight "provider digest mismatch: $provider_digest"
[[ "$artifact_name" == "$EXPECTED_ARTIFACT_NAME" ]] || fail_package_preflight "artifact name mismatch: $artifact_name"

curl -L --fail --silent --show-error \
  -H "Authorization: Bearer ${GH_TOKEN}" \
  -H 'Accept: application/vnd.github+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/${ARTIFACT_ID}/zip" \
  -o "$ZIP" || fail_orchestration 'artifact download failed'
zip_sha="$(sha_file "$ZIP")"
[[ "$zip_sha" == "$EXPECTED_ZIP_SHA256" ]] || fail_package_preflight "downloaded ZIP digest mismatch: $zip_sha"
printf 'artifact_id=%s\nartifact_name=%s\nprovider_digest=%s\ndownloaded_zip_sha256=%s\n' \
  "$ARTIFACT_ID" "$artifact_name" "$provider_digest" "$zip_sha" | tee "${RESULT}/artifact-authority.txt"

# `unzip` preserves archived executable mode bits; no chmod/repair is permitted.
unzip -q "$ZIP" -d "$PKG" || fail_orchestration 'artifact unzip failed'
[[ -f "$PKG/SHA256SUMS" ]] || fail_package_preflight 'root SHA256SUMS absent'
[[ "$(wc -l < "$PKG/SHA256SUMS" | tr -d ' ')" -eq "$EXPECTED_MANIFEST_ENTRIES" ]] || fail_package_preflight 'root SHA256SUMS entry count drift'
[[ "$(sha_file "$PKG/SHA256SUMS")" == "$EXPECTED_MANIFEST_SHA256" ]] || fail_package_preflight 'package manifest digest mismatch'
(cd "$PKG" && sha256sum -c SHA256SUMS) | tee "${RESULT}/sha256sums-preflight.txt" || fail_package_preflight 'root SHA256SUMS verification failed'
[[ "$(cat "$PKG/metadata/source-commit.txt")" == "$EXPECTED_SOURCE_SHA" ]] || fail_package_preflight 'source commit mismatch'
[[ "$(cat "$PKG/metadata/preflight-exit-code.txt")" == '0' ]] || fail_package_preflight 'compile preflight exit nonzero'
[[ "$(cat "$PKG/metadata/build-exit-code.txt")" == '0' ]] || fail_package_preflight 'build exit nonzero'
for token in 'runtimeExecution=false' 'turnBoundary=Code+Build-only' 'exactArithmeticBackend=GMP'; do
  grep -Fxq "$token" "$PKG/metadata/command-boundary.txt" || fail_package_preflight "missing command boundary: $token"
done
for token in 'libgmpxx.so' 'libgmp.so'; do
  grep -Fq "$token" "$PKG/metadata/gmp-evidence.txt" || fail_package_preflight "missing GMP evidence: $token"
done
for status_file in "$PKG"/metadata/source-status-*.txt; do
  [[ -f "$status_file" ]] || fail_package_preflight 'source-status snapshot set absent'
  [[ ! -s "$status_file" ]] || fail_package_preflight "non-empty source-status snapshot: $(basename "$status_file")"
done
printf 'compiled_targets:\n' > "${RESULT}/compile-package-metadata.txt"
cat "$PKG/metadata/compiled-targets.txt" >> "${RESULT}/compile-package-metadata.txt"

source_archive="$PKG/source/source-${EXPECTED_SOURCE_SHA}.tar.gz"
[[ -f "$source_archive" ]] || fail_package_preflight 'source archive absent'
[[ "$(sha_file "$source_archive")" == "$EXPECTED_SOURCE_ARCHIVE_SHA256" ]] || fail_package_preflight 'source archive digest mismatch'
tar -xzf "$source_archive" -C "$SOURCE" || fail_orchestration 'source archive extraction failed'

selector408="$SOURCE/$SELECTOR408_REL"
[[ -f "$selector408" ]] || fail_package_preflight 'selector408 absent'
python3 - "$selector408" "$EXPECTED_SELECTOR408_COUNT" <<'PY' || fail_package_preflight 'selector408 LF-row form mismatch'
import pathlib, sys
p = pathlib.Path(sys.argv[1])
expected = int(sys.argv[2])
b = p.read_bytes()
assert b.count(b'\n') == expected, (b.count(b'\n'), expected)
assert b'\r' not in b
assert b.endswith(b'\n')
assert all(line for line in b.splitlines())
PY
[[ "$(sha_file "$selector408")" == "$EXPECTED_SELECTOR408_SHA256" ]] || fail_package_preflight 'selector408 digest mismatch'
printf 'selector408_rows=%s\nselector408_sha256=%s\n' "$EXPECTED_SELECTOR408_COUNT" "$EXPECTED_SELECTOR408_SHA256" | tee "${RESULT}/selector-authority.txt"

# Create a separate immutable execution view before any Directional process.
cp -a "$PKG/." "$EXEC_VIEW/" || fail_orchestration 'execution-view copy failed'
census_tree "$PKG" "${RESULT}/package-census-pre.tsv"
census_tree "$SOURCE" "${RESULT}/source-census-pre.tsv"
census_tree "$EXEC_VIEW" "${RESULT}/execution-view-census-pre.tsv"
cmp -s "${RESULT}/package-census-pre.tsv" "${RESULT}/execution-view-census-pre.tsv" || fail_package_preflight 'execution view differs from immutable package before runtime'

# Resolve all accepted selector identities from static source ownership only. No binary discovery is executed.
python3 - "$SOURCE" "$selector408" "${RESULT}/identity-map.tsv" "${RESULT}/owner-distribution.tsv" "${RESULT}/focused-owner-map.tsv" "${FOCUSED_IDENTITIES[@]}" "$REPORT_ONLY_IDENTITY" <<'PY' || fail_package_preflight 'static selector/CP-COND ownership resolution failed'
import collections, pathlib, re, sys
root = pathlib.Path(sys.argv[1])
selector_path = pathlib.Path(sys.argv[2])
map_out = pathlib.Path(sys.argv[3])
dist_out = pathlib.Path(sys.argv[4])
focused_out = pathlib.Path(sys.argv[5])
requested = sys.argv[6:]
selector = [line.strip() for line in selector_path.read_text().splitlines() if line.strip()]
cmake = (root / 'cmake/DirectionalTests.cmake').read_text()
target_names = [
    'directional_surface_cell_authority_kernel_tests',
    'directional_surface_cell_producer_tests',
    'directional_surface_cell_completion_tests',
    'directional_surface_cell_validation_tests',
]
def cpp_lines(text):
    return [line.strip() for line in text.splitlines() if line.strip().endswith('.cpp')]
producer = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\s*\n\s*add_executable', cmake, re.S)
if not producer:
    raise SystemExit('producer source set not found')
targets = {'directional_surface_cell_producer_tests': cpp_lines(producer.group(1))}
for target in [t for t in target_names if t != 'directional_surface_cell_producer_tests']:
    m = re.search(r'add_executable\(\s*' + re.escape(target) + r'(.*?)\)\s*\n', cmake, re.S)
    if not m:
        raise SystemExit(f'target source block not found: {target}')
    targets[target] = cpp_lines(m.group(1))
pattern = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
owners = {}
for target, files in targets.items():
    for relative in files:
        path = root / relative
        if not path.is_file():
            raise SystemExit(f'missing target source: {target}:{relative}')
        for suite, name in pattern.findall(path.read_text(errors='replace')):
            owners.setdefault(f'{suite}.{name}', []).append((target, relative))
counts = collections.Counter()
rows = ['ordinal\tidentity\tbinary\tsource\n']
for ordinal, identity in enumerate(selector, start=1):
    hits = owners.get(identity, [])
    if len(hits) != 1:
        raise SystemExit(f'selector ownership cardinality {len(hits)} at {ordinal}:{identity}:{hits}')
    binary, source = hits[0]
    counts[binary] += 1
    rows.append(f'{ordinal}\t{identity}\t{binary}\t{source}\n')
map_out.write_text(''.join(rows), encoding='utf-8')
expected = {
    'directional_surface_cell_authority_kernel_tests': 30,
    'directional_surface_cell_producer_tests': 262,
    'directional_surface_cell_completion_tests': 75,
    'directional_surface_cell_validation_tests': 41,
}
if dict(counts) != expected:
    raise SystemExit(f'owner distribution drift: {dict(counts)}')
dist_out.write_text('binary\tcount\n' + ''.join(f'{k}\t{expected[k]}\n' for k in target_names), encoding='utf-8')
frows = ['identity\tbinary\tsource\n']
for identity in requested:
    hits = owners.get(identity, [])
    if len(hits) != 1:
        raise SystemExit(f'focused ownership cardinality {len(hits)}:{identity}:{hits}')
    binary, source = hits[0]
    if binary != 'directional_surface_cell_producer_tests':
        raise SystemExit(f'focused identity owner drift: {identity}:{binary}')
    frows.append(f'{identity}\t{binary}\t{source}\n')
focused_out.write_text(''.join(frows), encoding='utf-8')
PY

test "$(($(wc -l < "${RESULT}/focused-owner-map.tsv") - 1))" -eq 15 || fail_package_preflight 'focused owner-map count drift'

# Plan §2 requires every accepted selector owner binary to be packaged before any Directional process.
missing="${RESULT}/missing-owner-executables.txt"
: > "$missing"
while IFS=$'\t' read -r binary count; do
  [[ "$binary" == 'binary' ]] && continue
  path="$EXEC_VIEW/bin/$binary"
  if [[ ! -f "$path" || ! -x "$path" ]]; then
    printf '%s\t%s\n' "$binary" "$count" >> "$missing"
  fi
done < "${RESULT}/owner-distribution.tsv"

if [[ -s "$missing" ]]; then
  missing_count="$(wc -l < "$missing" | tr -d ' ')"
  stop_detail="immutable CB1 package omits ${missing_count} required selector408 owner executable(s)"
  fail_package_preflight "$stop_detail"
fi

# The immutable package digest fixes the preflight outcome above. Reaching runtime would indicate authority drift.
preflight_completed=true
fail_orchestration 'unexpectedly passed package owner-binary preflight; harness authority assumption invalid'
