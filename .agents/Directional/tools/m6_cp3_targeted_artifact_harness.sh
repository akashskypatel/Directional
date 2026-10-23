#!/usr/bin/env bash
set -euo pipefail
if [[ "${1:-}" == "--self-check" && "$#" -eq 2 ]]; then
  mode=self-check
  manifest_arg=$2
elif [[ "${1:-}" == "--execute" && "$#" -eq 1 ]]; then
  mode=execute
  manifest_arg=''
  : "${RUNNER_TEMP:?}"
  : "${TURN_ID:?}"
  exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
else
  echo 'usage: harness --self-check <case-manifest.tsv> | --execute' >&2
  exit 64
fi
python3 - "$mode" "$manifest_arg" <<'PY'
import csv
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tarfile

MODE, MANIFEST_ARG = sys.argv[1:]
HEADER = ['row', 'kind', 'identity', 'test', 'binary', 'expect', 'asserted_site']
KINDS = {'NEGATIVE', 'POSITIVE', 'GUARD', 'RED'}
HEX64 = re.compile(r'[0-9a-f]{64}\Z')
HEX40 = re.compile(r'[0-9a-f]{40}\Z')
TEST = re.compile(r'[A-Za-z_][A-Za-z0-9_]*\.[A-Za-z_][A-Za-z0-9_]*\Z')
BIN = re.compile(r'[A-Za-z0-9_-]+\Z')

def require(condition, message):
    if not condition:
        raise ValueError(message)

def digest(path):
    with Path(path).open('rb') as stream:
        sha = hashlib.sha256()
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            sha.update(chunk)
        return sha.hexdigest()

def read_cases(path):
    with Path(path).open(newline='', encoding='utf-8') as stream:
        reader = csv.reader(stream, delimiter='\t', strict=True)
        require(next(reader, None) == HEADER, 'wrong case manifest header')
        cases = list(reader)
    require(bool(cases), 'empty case manifest')
    identities, tests = set(), set()
    for index, case in enumerate(cases, 1):
        require(len(case) == len(HEADER), f'row {index}: wrong column count')
        row, kind, identity, test, binary, expect, site = case
        require(row == str(index), f'row {index}: nonsequential row')
        require(kind in KINDS, f'row {index}: unknown kind {kind!r}')
        require(bool(identity.strip()) and identity == identity.strip(), f'row {index}: invalid identity')
        require(bool(TEST.fullmatch(test)), f'row {index}: invalid gtest name')
        require(bool(BIN.fullmatch(binary)) and binary not in {'.', '..'}, f'row {index}: invalid binary')
        require(expect == ('RED' if kind == 'RED' else 'PASS'), f'row {index}: invalid expectation')
        require(bool(site) and ('\n' not in site and '\r' not in site), f'row {index}: invalid site')
        require(identity not in identities, f'row {index}: duplicate identity {identity}')
        require(test not in tests, f'row {index}: duplicate test {test}')
        identities.add(identity)
        tests.add(test)
    return cases

if MODE == 'self-check':
    try:
        cases = read_cases(MANIFEST_ARG)
        print(f'SELF_CHECK_PASS cases={len(cases)}')
    except Exception as error:
        print(f'SELF_CHECK_FAIL {error}', file=sys.stderr)
        sys.exit(1)
    sys.exit(0)

ROOT = Path(os.environ['RUNNER_TEMP']) / os.environ['TURN_ID']
OUT = Path(str(ROOT) + '-result')
(OUT / 'raw').mkdir(parents=True, exist_ok=True)
ROOT.mkdir(parents=True, exist_ok=True)
state = dict(planned=0, executed=0, passed=0, red=0, missing=0,
             skipped=0, duplicate=0, control_bad=0, unexpected_pass=0,
             postflight=False)
rows = []
exit_code = 90
source_sha = ''
artifact_id = None
error_message = ''

# Preserve all completed execution evidence even when a later gate fails.
def sha_manifest(path):
    result = []
    for line in (path / 'SHA256SUMS').read_text().splitlines():
        expected, relative = line.split('  ', 1)
        require(HEX64.fullmatch(expected) is not None, 'malformed SHA256SUMS')
        target = (path / relative).resolve()
        require(path.resolve() in target.parents and target.is_file(), f'manifest path invalid: {relative}')
        require(digest(target) == expected, f'manifest mismatch: {relative}')
        result.append(relative)
    require(bool(result) and len(result) == len(set(result)), 'empty or duplicate package checksum entries')
    return len(result)

def typed_reason(text):
    # Prefer a checked-factory reason, then a named atlas reason, A5, or pipeline/A7.
    expressions = [
        r'code=[0-9]+;sourceAuthoritySite=[^\s"\r\n]+',
        r'code=[A-Za-z][A-Za-z0-9_]*(?:;sourceEdge=\([^\r\n)]*\)[^\s"\r\n]*)?',
        r'A5:[A-Za-z][A-Za-z0-9_]*(?:;site=[^\s;"\r\n]+)?',
        r'firstStage=[^\s;"\r\n]+;firstReason=[^\s"\r\n]+',
        r'firstReason=[^\s"\r\n]+',
        r'site=[^\s;"\r\n]+',
    ]
    for expression in expressions:
        match = re.search(expression, text)
        if match:
            return match.group(0)
    return 'reason-not-observed'

def first_failure(text):
    return next((line.strip() for line in text.splitlines() if
                ': Failure' in line or 'producer failed:' in line or
                'firstReason=' in line or 'firstStage=' in line or
                line.startswith('[  FAILED  ] ')), 'failure-line-not-observed')

try:
    required = ['CANDIDATE_ARTIFACT_ID', 'EXPECTED_SOURCE_SHA',
                'EXPECTED_CANDIDATE_ZIP_SHA256', 'EXPECTED_ROOT_MANIFEST_SHA256',
                'EXPECTED_SOURCE_ARCHIVE_SHA256', 'CASE_MANIFEST', 'CASE_MANIFEST_SHA256']
    values = {name: os.environ[name] for name in required}
    artifact_id = int(values['CANDIDATE_ARTIFACT_ID'])
    require(artifact_id > 0 and str(artifact_id) == values['CANDIDATE_ARTIFACT_ID'], 'invalid artifact ID')
    source_sha = values['EXPECTED_SOURCE_SHA']
    require(HEX40.fullmatch(source_sha) is not None, 'invalid source SHA')
    for key in (name for name in required if name.endswith('SHA256')):
        require(HEX64.fullmatch(values[key]) is not None, f'invalid hash: {key}')
    repo = os.environ['GITHUB_REPOSITORY']
    require(re.fullmatch(r'[A-Za-z0-9_.-]+/[A-Za-z0-9_.-]+', repo) is not None, 'invalid repository')
    token = os.environ['GH_TOKEN']
    workspace = Path(os.environ['GITHUB_WORKSPACE']).resolve()
    relative_manifest = Path(values['CASE_MANIFEST'])
    require(not relative_manifest.is_absolute() and '..' not in relative_manifest.parts, 'manifest must be repo relative')
    case_path = (workspace / relative_manifest).resolve()
    require(workspace in case_path.parents and case_path.is_file() and not case_path.is_symlink(), 'manifest missing/unsafe')
    require(digest(case_path) == values['CASE_MANIFEST_SHA256'], 'case manifest checksum mismatch')
    cases = read_cases(case_path)
    state['planned'] = len(cases)
    print(f'PREFLIGHT cases={len(cases)} source={source_sha} artifact={artifact_id}', flush=True)

    api = f'https://api.github.com/repos/{repo}/actions/artifacts/{artifact_id}'
    curl = ['curl', '-fsSL', '-H', 'Authorization: Bearer ' + token]
    details = json.loads(subprocess.check_output(curl + [api], text=True))
    require(details.get('digest') == 'sha256:' + values['EXPECTED_CANDIDATE_ZIP_SHA256'], 'provider digest mismatch')
    zipped = ROOT / 'package.zip'
    subprocess.run(curl + [api + '/zip', '-o', str(zipped)], check=True)
    require(digest(zipped) == values['EXPECTED_CANDIDATE_ZIP_SHA256'], 'candidate ZIP checksum mismatch')
    package = ROOT / 'pkg'
    package.mkdir(exist_ok=True)
    # unzip preserves executable mode bits; zipfile.extractall does not.
    subprocess.run(['unzip', '-q', str(zipped), '-d', str(package)], check=True)
    require(digest(package / 'SHA256SUMS') == values['EXPECTED_ROOT_MANIFEST_SHA256'], 'root checksum list mismatch')
    package_count = sha_manifest(package)
    require((package / 'metadata/source-commit.txt').read_text().strip() == source_sha, 'package source mismatch')
    require((package / 'metadata/build-exit-code.txt').read_text().strip() == '0', 'package build exit not zero')
    boundary = (package / 'metadata/command-boundary.txt').read_text().splitlines()
    require('runtimeExecution=false' in boundary and 'exactArithmeticBackend=GMP' in boundary,
            'GMP/runtime-free compile evidence missing')
    source_archive = package / 'source' / f'source-{source_sha}.tar.gz'
    require(digest(source_archive) == values['EXPECTED_SOURCE_ARCHIVE_SHA256'], 'source archive mismatch')
    source = ROOT / 'source'
    source.mkdir(exist_ok=True)
    with tarfile.open(source_archive) as archive:
        archive.extractall(source, filter='data')
    fixture_dir = source / 'benchmarks/fixtures'
    require(fixture_dir.is_dir(), 'packaged source fixtures missing')
    view = ROOT / 'view'
    view_bin = view / 'bin'
    view_bin.mkdir(parents=True, exist_ok=True)
    for entry in (package / 'bin').iterdir():
        if entry.is_file():
            staged = view_bin / entry.name
            shutil.copy2(entry, staged)
            require(os.access(entry, os.X_OK) and os.access(staged, os.X_OK),
                    f'missing archived executable mode {entry.name}')
    shutil.copytree(fixture_dir, view / 'test-data/benchmarks/fixtures')
    before = {str(path.relative_to(view)): digest(path) for path in view.rglob('*') if path.is_file()}
    for binary in sorted({case[4] for case in cases}):
        executable = view_bin / binary
        require(executable.is_file() and os.access(executable, os.X_OK), f'missing executable {binary}')
        deps = subprocess.run(['ldd', str(executable)], capture_output=True, text=True, check=True)
        deps_text = deps.stdout + deps.stderr
        require('not found' not in deps_text and 'libgmp' in deps_text, f'GMP dependency missing for {binary}')
        (OUT / f'dependencies-{binary}.txt').write_text(deps_text)

    for case in cases:
        row, kind, identity, test, binary, expect, site = case
        executable = view_bin / binary
        workdir = ROOT / 'run' / row
        workdir.mkdir(parents=True, exist_ok=True)
        log = OUT / 'raw' / f'{row}.log'
        command = ['/usr/bin/time', '-v', 'env', 'GTEST_FAIL_IF_NO_TEST_SELECTED=1',
                   'GTEST_COLOR=no', str(executable), '--gtest_filter=' + test]
        try:
            with log.open('w') as stream:
                result = subprocess.run(command, cwd=workdir, stdout=stream,
                                        stderr=subprocess.STDOUT, timeout=600)
            code = result.returncode
        except subprocess.TimeoutExpired:
            with log.open('a') as stream:
                stream.write('\nHARNESS_TIMEOUT 600s\n')
            code = 124
        data = log.read_text(errors='replace')
        run = len(re.findall(r'(?m)^\[ RUN      \] ', data))
        passed = len(re.findall(r'(?m)^\[       OK \] ', data))
        skipped = len(re.findall(r'(?m)^\[  SKIPPED \] ', data))
        verdict = ('PASS' if code == 0 and run == passed == 1 and skipped == 0 else
                   'RED' if code != 0 and run == 1 and passed == skipped == 0 else 'INVALID')
        state['executed'] += int(run == 1 and skipped == 0)
        state['passed'] += int(verdict == 'PASS')
        state['red'] += int(verdict == 'RED')
        state['skipped'] += skipped
        state['missing'] += int(verdict == 'INVALID')
        state['duplicate'] += int(run > 1)
        state['control_bad'] += int(kind != 'RED' and verdict != 'PASS')
        state['unexpected_pass'] += int(kind == 'RED' and verdict == 'PASS')
        rows.append([row, kind, identity, test, binary, verdict, code, run, passed, skipped,
                     first_failure(data), '' if verdict == 'PASS' else typed_reason(data), digest(log)])
        print(f'CASE {row}/{len(cases)} {kind} {identity} {verdict}', flush=True)

    require(sha_manifest(package) == package_count, 'package postflight mismatch')
    after = {str(path.relative_to(view)): digest(path) for path in view.rglob('*') if path.is_file()}
    require(before == after, 'staged view mutated')
    state['postflight'] = True
    require(state['executed'] == state['planned'] and state['missing'] == 0 and
            state['duplicate'] == 0 and state['skipped'] == 0, 'selection failure')
    require(state['control_bad'] == 0, 'required controls failed')
    exit_code = 0
except Exception as error:
    error_message = f'{type(error).__name__}: {error}'
    print('TARGETED_HARNESS_FAILURE', error_message, file=sys.stderr)
finally:
    with (OUT / 'ledger.tsv').open('w', newline='', encoding='utf-8') as stream:
        writer = csv.writer(stream, delimiter='\t')
        writer.writerow(['row', 'kind', 'identity', 'test', 'binary', 'verdict', 'exit',
                         'run', 'passed', 'skipped', 'first_failure', 'typed_reason', 'log_sha256'])
        writer.writerows(rows)
    (OUT / 'execution-boundary.json').write_text(json.dumps({
        'artifact': artifact_id, 'source': source_sha, 'state': state,
        'error': error_message, 'compile': False, 'relink': False,
        'configure': False, 'benchmark': False, 'exit': exit_code}, indent=2) + '\n')
    with (OUT / 'SHA256SUMS').open('w') as stream:
        for path in sorted(OUT.rglob('*')):
            if path.is_file() and path.name != 'SHA256SUMS':
                stream.write(digest(path) + '  ' + str(path.relative_to(OUT)) + '\n')
    print('TARGETED_HARNESS_RESULT', json.dumps(state), f'exit={exit_code}', flush=True)
sys.exit(exit_code)
PY
