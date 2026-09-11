#!/usr/bin/env bash
set -euo pipefail

EVIDENCE="$RUNNER_TEMP/m4-cp3-tb1-r1-evidence"
PACKAGE_ZIP="$RUNNER_TEMP/package119.zip"
EXTRACT="$RUNNER_TEMP/package119"
SOURCE_ANALYSIS="$RUNNER_TEMP/package119-source-analysis"
mkdir -p "$EVIDENCE" "$EXTRACT" "$SOURCE_ANALYSIS"

printf '%s\n' \
  'turn=M4-CP3-TB1-R1-EXEC' \
  'executionBoundary=artifact-only Test+Benchmark runtime execution' \
  'packageDesignation=package119-unpromoted' \
  "artifactId=$ARTIFACT_ID" \
  "expectedZipSha256=$EXPECTED_ZIP_SHA256" \
  "expectedSourceSha=$EXPECTED_SOURCE_SHA" \
  'runtimeExecution=true' \
  'configure=false' \
  'compile=false' \
  'relink=false' \
  'generatedDiscovery=false' \
  'packageRepair=false' \
  'benchmarkExecution=false' \
  "perProcessTimeoutSeconds=$PER_PROCESS_TIMEOUT_SECONDS" \
  > "$EVIDENCE/command-boundary.txt"

gh api --method GET "repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID" > "$EVIDENCE/provider-artifact.json"
jq -e --argjson id "$ARTIFACT_ID" '.id == $id and (.expired | not)' "$EVIDENCE/provider-artifact.json" >/dev/null
jq -r '["artifactId=" + (.id|tostring), "artifactName=" + .name, "providerDigest=" + (.digest // ""), "providerSizeBytes=" + (.size_in_bytes|tostring), "expired=" + (.expired|tostring)][]' \
  "$EVIDENCE/provider-artifact.json" > "$EVIDENCE/artifact-provider-metadata.txt"

gh api --method GET "repos/$GITHUB_REPOSITORY/actions/artifacts/$ARTIFACT_ID/zip" > "$PACKAGE_ZIP"
DOWNLOAD_SHA="$(sha256sum "$PACKAGE_ZIP" | awk '{print $1}')"
DOWNLOAD_BYTES="$(stat -c '%s' "$PACKAGE_ZIP")"
printf 'downloadSha256=%s\ndownloadBytes=%s\n' "$DOWNLOAD_SHA" "$DOWNLOAD_BYTES" > "$EVIDENCE/artifact-download.txt"
test "$DOWNLOAD_SHA" = "$EXPECTED_ZIP_SHA256"

unzip -q "$PACKAGE_ZIP" -d "$EXTRACT"
mapfile -t MANIFESTS < <(find "$EXTRACT" -type f -name SHA256SUMS -print)
test "${#MANIFESTS[@]}" -eq 1
PACKAGE_ROOT="$(dirname "${MANIFESTS[0]}")"
printf 'packageRoot=%s\n' "$PACKAGE_ROOT" > "$EVIDENCE/package-root.txt"

python3 - "$PACKAGE_ROOT" "$EVIDENCE/package-census-pre.tsv" <<'PY'
import hashlib, stat, sys
from pathlib import Path
root = Path(sys.argv[1]); out = Path(sys.argv[2]); rows = []
for p in sorted(x for x in root.rglob('*') if x.is_file()):
    data = p.read_bytes(); st = p.stat()
    rows.append(f"{p.relative_to(root).as_posix()}\t{len(data)}\t{stat.S_IMODE(st.st_mode):04o}\t{hashlib.sha256(data).hexdigest()}\n")
out.write_text(''.join(rows), encoding='utf-8')
PY

(
  cd "$PACKAGE_ROOT"
  sha256sum -c SHA256SUMS | tee "$EVIDENCE/manifest-pre.txt"
)

python3 - "$PACKAGE_ROOT" "$EVIDENCE/manifest-pathset.txt" <<'PY'
import re, sys
from pathlib import Path
root = Path(sys.argv[1]); out = Path(sys.argv[2]); manifest = root / 'SHA256SUMS'
lines = manifest.read_text(encoding='utf-8').splitlines()
if len(lines) != 28:
    raise SystemExit(f"manifest entry count {len(lines)} != 28")
manifest_paths = []
for line in lines:
    m = re.fullmatch(r'([0-9a-f]{64})\s+\*?(.+)', line)
    if not m:
        raise SystemExit(f"invalid manifest line: {line!r}")
    path = m.group(2)
    while path.startswith('./'):
        path = path[2:]
    manifest_paths.append(path)
actual = sorted(p.relative_to(root).as_posix() for p in root.rglob('*') if p.is_file() and p != manifest)
if sorted(manifest_paths) != actual:
    raise SystemExit('manifest self-excluding path set differs from package file set')
out.write_text('manifestEntries=28\nmanifestPathSetMatches=true\n' + '\n'.join(sorted(manifest_paths)) + '\n', encoding='utf-8')
PY

test "$(cat "$PACKAGE_ROOT/metadata/source-commit.txt")" = "$EXPECTED_SOURCE_SHA"
test "$(cat "$PACKAGE_ROOT/metadata/preflight-exit-code.txt")" = '0'
test "$(cat "$PACKAGE_ROOT/metadata/build-exit-code.txt")" = '0'
for required in \
  'runtimeExecution=false' \
  'turnBoundary=Code+Build-only' \
  'exactArithmeticBackend=GMP' \
  'preflightCompile=true' \
  'semanticContracts=compiled-not-executed' \
  'manifestExcludesSelf=true' \
  'buildLocation=runner-temp-out-of-tree'; do
  grep -Fxq "$required" "$PACKAGE_ROOT/metadata/command-boundary.txt"
done

mapfile -t GMP_EVIDENCE < <(find "$PACKAGE_ROOT" -type f -name 'gmp-evidence.txt' -print)
test "${#GMP_EVIDENCE[@]}" -eq 1
grep -q 'DIRECTIONAL_ENABLE_GMP.*ON' "${GMP_EVIDENCE[0]}"
grep -Eiq 'gmpxx.*gmp|gmp.*gmpxx' "${GMP_EVIDENCE[0]}"
cp "${GMP_EVIDENCE[0]}" "$EVIDENCE/gmp-evidence.txt"

mapfile -t SOURCE_STATUS < <(find "$PACKAGE_ROOT" -type f -name 'source-status-*.txt' -print | sort)
test "${#SOURCE_STATUS[@]}" -gt 0
: > "$EVIDENCE/source-status-report.txt"
for status_file in "${SOURCE_STATUS[@]}"; do
  test ! -s "$status_file"
  printf '%s empty=true\n' "${status_file#"$PACKAGE_ROOT"/}" >> "$EVIDENCE/source-status-report.txt"
done

mapfile -t SOURCE_ARCHIVES < <(find "$PACKAGE_ROOT" -type f -name 'source.tar.gz' -print)
test "${#SOURCE_ARCHIVES[@]}" -eq 1
tar -xzf "${SOURCE_ARCHIVES[0]}" -C "$SOURCE_ANALYSIS"
find "$SOURCE_ANALYSIS" -type f -exec chmod a-w {} +
find "$SOURCE_ANALYSIS" -type d -exec chmod a-w {} +

python3 - "$SOURCE_ANALYSIS" "$EVIDENCE/source-census-pre.tsv" <<'PY'
import hashlib, stat, sys
from pathlib import Path
root = Path(sys.argv[1]); out = Path(sys.argv[2]); rows=[]
for p in sorted(x for x in root.rglob('*') if x.is_file()):
    data=p.read_bytes(); rows.append(f"{p.relative_to(root).as_posix()}\t{len(data)}\t{stat.S_IMODE(p.stat().st_mode):04o}\t{hashlib.sha256(data).hexdigest()}\n")
out.write_text(''.join(rows), encoding='utf-8')
PY

cat > "$RUNNER_TEMP/tb_exec.py" <<'PY'
import hashlib
import json
import os
import re
import stat
import subprocess
import sys
import time
from collections import Counter, defaultdict
from pathlib import Path

source_extract = Path(sys.argv[1])
package_root = Path(sys.argv[2])
evidence = Path(sys.argv[3])
timeout_seconds = int(sys.argv[4])
expected_selector_sha = os.environ['EXPECTED_SELECTOR394_SHA256']
expected_prefix_sha = os.environ['EXPECTED_SELECTOR382_PREFIX_SHA256']
corrected = {386, 388, 389, 390, 391, 392, 394}
binary_names = {
    'authority': 'directional_surface_cell_authority_kernel_tests',
    'producer': 'directional_surface_cell_producer_tests',
    'completion': 'directional_surface_cell_completion_tests',
    'validation': 'directional_surface_cell_validation_tests',
}

selectors = list(source_extract.rglob('Architecture_M4_CP3_Required_Green_Selector_394.txt'))
if len(selectors) != 1:
    raise SystemExit(f'expected one selector394, found {len(selectors)}')
selector = selectors[0]
project_root = selector.parents[2]
data = selector.read_bytes()
if b'\r' in data:
    raise SystemExit('selector394 contains CR bytes')
rows_bytes = data.splitlines(keepends=True)
if len(rows_bytes) != 394 or any(not row.endswith(b'\n') for row in rows_bytes):
    raise SystemExit('selector394 is not exactly 394 LF-terminated rows')
if hashlib.sha256(data).hexdigest() != expected_selector_sha:
    raise SystemExit('selector394 SHA mismatch')
prefix = b''.join(rows_bytes[:382])
if hashlib.sha256(prefix).hexdigest() != expected_prefix_sha:
    raise SystemExit('selector382 prefix SHA mismatch')
selector382 = list(source_extract.rglob('Architecture_M4_CP3_Required_Green_Selector_382.txt'))
if len(selector382) != 1 or selector382[0].read_bytes() != prefix:
    raise SystemExit('accepted selector382 is not byte-identical to selector394 prefix')
identities = [row[:-1].decode('utf-8') for row in rows_bytes]

cmake = project_root / 'cmake' / 'DirectionalTests.cmake'
cmake_text = cmake.read_text(encoding='utf-8')
owner_sources = {}
producer_set = re.search(r'set\s*\(\s*DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\n\)', cmake_text, re.S)
if not producer_set:
    raise SystemExit('producer source set not found statically')
owner_sources['producer'] = set(re.findall(r'(tests/[A-Za-z0-9_./+-]+\.cpp)', producer_set.group(1)))
for owner, target in [('authority', binary_names['authority']), ('completion', binary_names['completion']), ('validation', binary_names['validation'])]:
    m = re.search(r'add_executable\s*\(\s*' + re.escape(target) + r'\b(.*?)\)', cmake_text, re.S)
    if not m:
        raise SystemExit(f'{target} source block not found statically')
    owner_sources[owner] = set(re.findall(r'(tests/[A-Za-z0-9_./+-]+\.cpp)', m.group(1)))

definition_pattern = re.compile(r'\b(?:TEST|TEST_F|TEST_P|TYPED_TEST)\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', re.S)
definitions = defaultdict(list)
for src in sorted((project_root / 'tests').rglob('*.cpp')):
    text = src.read_text(encoding='utf-8', errors='replace')
    rel = src.relative_to(project_root).as_posix()
    for suite, name in definition_pattern.findall(text):
        definitions[f'{suite}.{name}'].append(rel)

owner_map = []
static_errors = []
for ordinal, identity in enumerate(identities, 1):
    defs = definitions.get(identity, [])
    if len(defs) != 1:
        static_errors.append(f'ordinal={ordinal} identity={identity} staticDefinitions={len(defs)} files={defs}')
        continue
    src = defs[0]
    owners = [owner for owner, sources in owner_sources.items() if src in sources]
    if len(owners) != 1:
        static_errors.append(f'ordinal={ordinal} identity={identity} source={src} owners={owners}')
        continue
    owner_map.append((ordinal, identity, owners[0], src))
if static_errors:
    (evidence / 'static-authority-errors.txt').write_text('\n'.join(static_errors) + '\n', encoding='utf-8')
    raise SystemExit(f'static selector authority failed with {len(static_errors)} errors')
if len(owner_map) != 394:
    raise SystemExit('owner map does not cover 394 identities')

expected_all = Counter({'authority': 30, 'producer': 248, 'completion': 75, 'validation': 41})
expected_prefix = Counter({'authority': 30, 'producer': 236, 'completion': 75, 'validation': 41})
all_counts = Counter(owner for _, _, owner, _ in owner_map)
prefix_counts = Counter(owner for ordinal, _, owner, _ in owner_map if ordinal <= 382)
if all_counts != expected_all:
    raise SystemExit(f'candidate owner totals mismatch: {all_counts}')
if prefix_counts != expected_prefix:
    raise SystemExit(f'prefix owner totals mismatch: {prefix_counts}')
with (evidence / 'selector-authority.tsv').open('w', encoding='utf-8') as f:
    f.write('ordinal\tidentity\towner\tsource\n')
    for row in owner_map:
        f.write('\t'.join(map(str, row)) + '\n')
(evidence / 'selector-report.txt').write_text(
    f'selector394Rows=394\nselector394Sha256={hashlib.sha256(data).hexdigest()}\n'
    f'selector382PrefixSha256={hashlib.sha256(prefix).hexdigest()}\n'
    'staticDefinitionsExactlyOne=true\n'
    'candidateOwnerTotals=30/248/75/41\n'
    'prefixOwnerTotals=30/236/75/41\n', encoding='utf-8')

binaries = {}
for owner, name in binary_names.items():
    matches = [p for p in package_root.rglob(name) if p.is_file()]
    if len(matches) != 1:
        raise SystemExit(f'expected one packaged binary {name}, found {len(matches)}')
    p = matches[0]
    if stat.S_IMODE(p.stat().st_mode) & 0o111 == 0:
        raise SystemExit(f'packaged binary lacks archived executable mode: {p}')
    binaries[owner] = p

with (evidence / 'binary-dependencies.txt').open('wb') as depout:
    for owner, binary in binaries.items():
        depout.write(f'## {owner} {binary}\n'.encode())
        proc = subprocess.run(['ldd', str(binary)], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        depout.write(proc.stdout)
        if proc.returncode != 0 or b'not found' in proc.stdout:
            raise SystemExit(f'unavailable runtime dependency for {binary}')

process_root = evidence / 'processes'
process_root.mkdir(parents=True, exist_ok=True)
ledger = (evidence / 'process-ledger.tsv').open('w', encoding='utf-8')
ledger.write('processIndex\tphase\tordinal\tidentity\towner\texitStatus\telapsedSeconds\ttimeout\trunCount\tokCount\tskipCount\tverdict\n')
process_index = 0
results = []
receipts = {'focusedA': {}, 'focusedB': {}}
run_line_re = re.compile(br'^\[ RUN      \] (.+)$', re.M)
ok_line_re = re.compile(br'^\[       OK \] ([^ ]+)(?: \(|$)', re.M)
skip_line_re = re.compile(br'^\[  SKIPPED \] ([^ ]+)(?: \(|$)', re.M)

def run_one(phase, ordinal, identity, owner):
    global process_index
    process_index += 1
    binary = binaries[owner]
    stem = f'{process_index:04d}_{phase}_{ordinal:03d}'
    stdout_path = process_root / f'{stem}.stdout.log'
    stderr_path = process_root / f'{stem}.stderr.log'
    meta_path = process_root / f'{stem}.meta.txt'
    cmd = [str(binary), f'--gtest_filter={identity}', '--gtest_color=no']
    env = os.environ.copy(); env['GTEST_FAIL_IF_NO_TEST_SELECTED'] = '1'
    started = time.monotonic(); timed_out = False
    try:
        proc = subprocess.run(cmd, cwd=binary.parent, env=env, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout_seconds)
        rc = proc.returncode; stdout = proc.stdout; stderr = proc.stderr
    except subprocess.TimeoutExpired as exc:
        timed_out = True; rc = 124; stdout = exc.stdout or b''; stderr = exc.stderr or b''
    elapsed = time.monotonic() - started
    stdout_path.write_bytes(stdout); stderr_path.write_bytes(stderr)
    runs = [x.decode('utf-8', errors='replace') for x in run_line_re.findall(stdout)]
    oks = [x.decode('utf-8', errors='replace') for x in ok_line_re.findall(stdout)]
    skips = [x.decode('utf-8', errors='replace') for x in skip_line_re.findall(stdout)]
    if timed_out:
        verdict = 'TIMEOUT'
    elif len(runs) != 1 or runs[0] != identity:
        verdict = 'SELECTION_MISMATCH'
    elif skips:
        verdict = 'SKIP'
    elif rc == 0 and len(oks) == 1 and oks[0] == identity:
        verdict = 'PASS'
    else:
        verdict = 'RED'
    meta_path.write_text(
        f'processIndex={process_index}\nphase={phase}\nordinal={ordinal}\nidentity={identity}\nowner={owner}\n'
        f'command={json.dumps(cmd)}\ncwd={binary.parent}\nexitStatus={rc}\nelapsedSeconds={elapsed:.6f}\n'
        f'timeout={str(timed_out).lower()}\nrunCount={len(runs)}\nokCount={len(oks)}\nskipCount={len(skips)}\nverdict={verdict}\n', encoding='utf-8')
    ledger.write(f'{process_index}\t{phase}\t{ordinal}\t{identity}\t{owner}\t{rc}\t{elapsed:.6f}\t{str(timed_out).lower()}\t{len(runs)}\t{len(oks)}\t{len(skips)}\t{verdict}\n'); ledger.flush()
    receipt_bytes = None
    if phase in receipts and ordinal in corrected:
        matching = [line for line in stdout.splitlines(keepends=True) if line.startswith(f'M4_CP3_BASELINE_RECEIPT ordinal={ordinal}'.encode())]
        if len(matching) == 1:
            receipt_bytes = matching[0]
            (evidence / f'receipt-{phase}-{ordinal}.bin').write_bytes(receipt_bytes)
        else:
            (evidence / f'receipt-{phase}-{ordinal}-count.txt').write_text(str(len(matching)) + '\n', encoding='utf-8')
        receipts[phase][ordinal] = receipt_bytes
    row = {'phase': phase, 'ordinal': ordinal, 'identity': identity, 'owner': owner, 'verdict': verdict, 'rc': rc, 'timeout': timed_out, 'receipt': receipt_bytes}
    results.append(row)
    return row

by_ordinal = {ordinal: (identity, owner) for ordinal, identity, owner, _ in owner_map}
for phase in ('focusedA', 'focusedB'):
    for ordinal in range(383, 395):
        identity, owner = by_ordinal[ordinal]; run_one(phase, ordinal, identity, owner)
for ordinal in range(1, 383):
    identity, owner = by_ordinal[ordinal]; run_one('predecessor382', ordinal, identity, owner)
for ordinal in range(1, 395):
    identity, owner = by_ordinal[ordinal]; run_one('cumulative394', ordinal, identity, owner)
ledger.close()

if process_index != 800:
    raise SystemExit(f'expected 800 semantic runtime processes, observed {process_index}')

def phase_rows(name): return [r for r in results if r['phase'] == name]
def verdict_vector_bytes(name): return ''.join(f"{r['ordinal']}\t{r['identity']}\t{r['verdict']}\n" for r in phase_rows(name)).encode()
va = verdict_vector_bytes('focusedA'); vb = verdict_vector_bytes('focusedB')
(evidence / 'focusedA-verdict-vector.tsv').write_bytes(va); (evidence / 'focusedB-verdict-vector.tsv').write_bytes(vb)
verdict_equal = va == vb

receipt_errors = []; parsed = {}
def parse_receipt(raw):
    if raw is None: return None
    text = raw.decode('utf-8').rstrip('\n')
    return dict(re.findall(r'([A-Za-z][A-Za-z0-9]*)=([^ ]+)', text))
for phase in ('focusedA', 'focusedB'):
    parsed[phase] = {}
    for ordinal in sorted(corrected):
        raw = receipts[phase].get(ordinal)
        if raw is None:
            receipt_errors.append(f'{phase} ordinal={ordinal} missing-or-duplicate-receipt'); continue
        kv = parse_receipt(raw); parsed[phase][ordinal] = kv
        try:
            if ordinal == 386:
                assert int(kv['components']) == 1; assert kv['hasExterior'] in ('1','true'); assert kv['exteriorDemandOdd'] in ('1','true'); assert int(kv['terminalSpans']) == 3
            elif ordinal == 388:
                assert re.fullmatch(r'\[[0-9,-]+\]', kv['counts']); int(kv['minimumFlipCount']); int(kv['lexReceipts'])
            elif ordinal == 389:
                assert [int(kv[k]) for k in ('onePreferred','oneFinal','largerPreferred','largerFinal')] == [1,2,2,1]
            elif ordinal == 390:
                span=int(kv['spanCount']); assignments=int(kv['assignmentsExamined']); feasible=int(kv['parityFeasibleAssignments'])
                assert span > 0 and assignments > 0 and feasible > 0 and assignments == (1 << span); assert kv['regionSpanMultiplicities'] not in ('','[]')
            elif ordinal == 391:
                assert int(kv['tamperRows']) == 9
            elif ordinal == 392:
                preferred=int(kv['preferredCount']); count=int(kv['entryCount']); assert preferred == 4 and count > 1
                assert int(kv['forwardOrdinal']) == 1 and int(kv['reverseOrdinal']) == count - 1
                assert int(kv['forwardDenominator']) == count and int(kv['reverseDenominator']) == count
            elif ordinal == 394:
                assert int(kv['topologyBoundaryIncidences']) == int(kv['baselineIncidences'])
        except Exception as exc:
            receipt_errors.append(f'{phase} ordinal={ordinal} invariant-failure {type(exc).__name__}: {exc}')
receipt_bytes_equal = True
for ordinal in sorted(corrected):
    if receipts['focusedA'].get(ordinal) != receipts['focusedB'].get(ordinal):
        receipt_bytes_equal = False; receipt_errors.append(f'ordinal={ordinal} focused-receipt-byte-drift')

(evidence / 'receipt-ledger.json').write_text(json.dumps(parsed, indent=2, sort_keys=True) + '\n', encoding='utf-8')
(evidence / 'receipt-errors.txt').write_text(('\n'.join(receipt_errors) + '\n') if receipt_errors else '', encoding='utf-8')
counts = {}
for phase in ('focusedA','focusedB','predecessor382','cumulative394'):
    counts[phase] = dict(Counter(r['verdict'] for r in phase_rows(phase)))
semantic_green = (
    counts['focusedA'].get('PASS',0) == 12 and len(counts['focusedA']) == 1 and
    counts['focusedB'].get('PASS',0) == 12 and len(counts['focusedB']) == 1 and verdict_equal and
    not receipt_errors and receipt_bytes_equal and
    counts['predecessor382'].get('PASS',0) == 382 and len(counts['predecessor382']) == 1 and
    counts['cumulative394'].get('PASS',0) == 394 and len(counts['cumulative394']) == 1)
summary = {
    'processCount': process_index,
    'phaseVerdicts': counts,
    'focusedVerdictVectorsEqual': verdict_equal,
    'focusedReceiptBytesEqual': receipt_bytes_equal,
    'receiptErrors': receipt_errors,
    'semanticGreen': semantic_green,
    'candidateOwnerTotals': dict(all_counts),
    'predecessorOwnerTotals': dict(prefix_counts),
}
(evidence / 'runtime-summary.json').write_text(json.dumps(summary, indent=2, sort_keys=True) + '\n', encoding='utf-8')
(evidence / 'runtime-result.txt').write_text(('MEASURED_GREEN\n' if semantic_green else 'MEASURED_RED\n'), encoding='utf-8')
PY

python3 "$RUNNER_TEMP/tb_exec.py" "$SOURCE_ANALYSIS" "$PACKAGE_ROOT" "$EVIDENCE" "$PER_PROCESS_TIMEOUT_SECONDS"

python3 - "$SOURCE_ANALYSIS" "$EVIDENCE/source-census-post.tsv" <<'PY'
import hashlib, stat, sys
from pathlib import Path
root=Path(sys.argv[1]); out=Path(sys.argv[2]); rows=[]
for p in sorted(x for x in root.rglob('*') if x.is_file()):
    data=p.read_bytes(); rows.append(f"{p.relative_to(root).as_posix()}\t{len(data)}\t{stat.S_IMODE(p.stat().st_mode):04o}\t{hashlib.sha256(data).hexdigest()}\n")
out.write_text(''.join(rows), encoding='utf-8')
PY
cmp "$EVIDENCE/source-census-pre.tsv" "$EVIDENCE/source-census-post.tsv"

python3 - "$PACKAGE_ROOT" "$EVIDENCE/package-census-post.tsv" <<'PY'
import hashlib, stat, sys
from pathlib import Path
root=Path(sys.argv[1]); out=Path(sys.argv[2]); rows=[]
for p in sorted(x for x in root.rglob('*') if x.is_file()):
    data=p.read_bytes(); rows.append(f"{p.relative_to(root).as_posix()}\t{len(data)}\t{stat.S_IMODE(p.stat().st_mode):04o}\t{hashlib.sha256(data).hexdigest()}\n")
out.write_text(''.join(rows), encoding='utf-8')
PY
cmp "$EVIDENCE/package-census-pre.tsv" "$EVIDENCE/package-census-post.tsv"

(
  cd "$PACKAGE_ROOT"
  sha256sum -c SHA256SUMS | tee "$EVIDENCE/manifest-post.txt"
)
cmp "$EVIDENCE/manifest-pre.txt" "$EVIDENCE/manifest-post.txt"
printf '%s\n' \
  'packageCensusPrePostIdentical=true' \
  'sourceCensusPrePostIdentical=true' \
  'manifestPost=28/28' \
  'packageBytesMutated=false' \
  'sourceBytesMutated=false' \
  'selectorBytesMutated=false' \
  'binariesMutated=false' \
  > "$EVIDENCE/immutable-postflight.txt"
