#!/usr/bin/env bash
set -euo pipefail
if [[ "${1:-}" == "--self-check" && ( "$#" -eq 3 || "$#" -eq 4 ) ]]; then
  mode=self-check
  manifest_arg=$2
  count_arg=$3
  ledger_arg=${4:-}
elif [[ "${1:-}" == "--self-test" && "$#" -eq 1 ]]; then
  mode=self-test
  manifest_arg=''
  count_arg=''
  ledger_arg=''
elif [[ "${1:-}" == "--execute" && "$#" -eq 1 ]]; then
  mode=execute
  manifest_arg=''
  count_arg=''
  ledger_arg=''
  : "${RUNNER_TEMP:?}"
  : "${TURN_ID:?}"
  exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
else
  echo 'usage: harness --self-check <case-manifest.tsv> <expected-count> [<deferred-ledger.tsv>] | --self-test | --execute' >&2
  exit 64
fi
python3 - "$mode" "$manifest_arg" "$count_arg" "$ledger_arg" <<'PY'
import csv
import hashlib
import json
import os
import signal
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tarfile
import tempfile

MODE, MANIFEST_ARG, COUNT_ARG, LEDGER_ARG = sys.argv[1:]
HEADER = ['row', 'kind', 'identity', 'test', 'binary', 'expect', 'asserted_site']
KINDS = {'NEGATIVE', 'POSITIVE', 'GUARD', 'RED', 'OBSERVE'}
LEDGER_HEADER = ['census_row', 'identity', 'test', 'binary', 'verdict', 'exit', 'group', 'class',
                 'first_failure']
CLASSES = {'FIXTURE', 'PRODUCT', 'OPEN', 'RETIRE'}
HEX64 = re.compile(r'[0-9a-f]{64}\Z')
HEX40 = re.compile(r'[0-9a-f]{40}\Z')
# Plain Suite.Test, or value-parameterized Prefix/Suite.Test/Param.
NAME = r'[A-Za-z_][A-Za-z0-9_]*'
TEST = re.compile(rf'(?:{NAME}\.{NAME}|{NAME}/{NAME}\.{NAME}/[A-Za-z0-9_]+)\Z')
BIN = re.compile(r'[A-Za-z0-9_-]+\Z')
PIN = re.compile(r'([A-Za-z_][A-Za-z0-9_]*\.cpp):([1-9][0-9]*)\|([^\r\n|]+)\Z')

def require(condition, message):
    if not condition:
        raise ValueError(message)

def digest(path):
    with Path(path).open('rb') as stream:
        sha = hashlib.sha256()
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            sha.update(chunk)
        return sha.hexdigest()

def expected_count(value):
    require(re.fullmatch(r'[1-9][0-9]*', value) is not None, 'invalid expected case count')
    return int(value)

def read_cases(path, count):
    with Path(path).open(newline='', encoding='utf-8') as stream:
        reader = csv.reader(stream, delimiter='\t', strict=True)
        require(next(reader, None) == HEADER, 'wrong case manifest header')
        cases = list(reader)
    require(len(cases) == count, f'case count mismatch: expected {count}, got {len(cases)}')
    identities, tests = set(), set()
    for index, case in enumerate(cases, 1):
        require(len(case) == len(HEADER), f'row {index}: wrong column count')
        row, kind, identity, test, binary, expect, site = case
        require(row == str(index), f'row {index}: nonsequential row')
        require(kind in KINDS, f'row {index}: unknown kind {kind!r}')
        require(bool(identity.strip()) and identity == identity.strip(), f'row {index}: invalid identity')
        require(bool(TEST.fullmatch(test)), f'row {index}: invalid gtest name')
        require(bool(BIN.fullmatch(binary)) and binary not in {'.', '..'}, f'row {index}: invalid binary')
        require(expect == (kind if kind in {'RED', 'OBSERVE'} else 'PASS'), f'row {index}: invalid expectation')
        require(bool(site) and ('\n' not in site and '\r' not in site), f'row {index}: invalid site')
        if kind == 'RED' or (kind == 'POSITIVE' and identity != 'selector:174' and site != '-'):
            require(PIN.fullmatch(site) is not None, f'row {index}: malformed or missing asserted-site pin')
        elif kind == 'POSITIVE' and identity == 'selector:174':
            # Frozen informational precondition, not a source-located failure.
            require(site == ('A4-rail-builder InvalidFeatureEdge on forged overfull incidence; '
                             'TriMesh set_mesh throws on nonmanifold (RA-164 H1)'),
                    f'row {index}: invalid informational note')
        else:
            require(site == '-', f'row {index}: unexpected asserted-site pin')
        require(identity not in identities, f'row {index}: duplicate identity {identity}')
        require(test not in tests, f'row {index}: duplicate test {test}')
        identities.add(identity)
        tests.add(test)
    # A census observes; it must never dilute a gate's PASS/RED controls.
    require(len({case[1] == 'OBSERVE' for case in cases}) == 1, 'OBSERVE rows mixed with gate rows')
    return cases

# O14: every test a packaged *_tests binary lists is gated or deferred, never both.
def read_ledger(path, cases):
    require(cases[0][1] != 'OBSERVE', 'a census takes no deferred ledger')
    with Path(path).open(newline='', encoding='utf-8') as stream:
        reader = csv.reader(stream, delimiter='\t', strict=True)
        require(next(reader, None) == LEDGER_HEADER, 'wrong deferred ledger header')
        rows = list(reader)
    gated = {case[3] for case in cases}
    tests, entries = set(), []
    for index, row in enumerate(rows, 1):
        require(len(row) == len(LEDGER_HEADER), f'ledger row {index}: wrong column count')
        test, binary, disposition = row[2], row[3], row[7]
        require(bool(TEST.fullmatch(test)), f'ledger row {index}: invalid gtest name')
        require(bool(BIN.fullmatch(binary)) and binary not in {'.', '..'}, f'ledger row {index}: invalid binary')
        require(disposition in CLASSES, f'ledger row {index}: unknown class {disposition!r}')
        require(test not in tests, f'ledger row {index}: duplicate test {test}')
        require(test not in gated, f'ledger row {index}: also gated: {test}')
        tests.add(test)
        entries.append((test, binary))
    return entries

def list_tests(text):
    names, suite = [], None
    for line in text.splitlines():
        if not line.strip() or (suite is None and line.startswith('Running main() from ')):
            continue
        head = line.split('  # ', 1)[0].rstrip()  # drop GetParam()/TypeParam notes
        if not line.startswith(' '):
            require(head.endswith('.') and len(head) > 1, f'unparsable listing line: {line!r}')
            suite = head[:-1]
            continue
        require(suite is not None, 'listed test before its suite')
        name = f'{suite}.{head.strip()}'
        require(TEST.fullmatch(name) is not None, f'unsupported listed test: {name}')
        names.append(name)
    require(len(names) == len(set(names)), 'duplicate listed test')
    return set(names)

def membership(cases, ledger, listings):
    governed = {}
    for test, binary in [(case[3], case[4]) for case in cases] + ledger:
        governed.setdefault(binary, set()).add(test)
    require(set(listings) == set(governed),
            f'ungoverned or unpackaged test binaries: {sorted(set(listings) ^ set(governed))}')
    gated = {case[3] for case in cases}
    members = []
    for binary in sorted(listings):
        listed = list_tests(listings[binary])
        ungoverned = sorted(listed - governed[binary])
        stale = sorted(governed[binary] - listed)
        require(not ungoverned and not stale, f'{binary}: {len(ungoverned)} ungoverned '
                f'{ungoverned[:3]}, {len(stale)} stale {stale[:3]}')
        members += [[binary, test, 'GATED' if test in gated else 'DEFERRED'] for test in sorted(listed)]
    return members

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

def failure_block(text):
    lines = text.splitlines()
    start = next((i for i, line in enumerate(lines)
                  if ': Failure' in line), None)
    if start is None:
        return ''
    end = next((i for i in range(start + 1, len(lines))
                if lines[i].startswith('[  FAILED  ] ')), len(lines) - 1)
    return '\n'.join(lines[start:end + 1])

def typed_reason(text):
    block = failure_block(text)
    expressions = [
        r'code=[0-9]+;sourceAuthoritySite=[^\s"\r\n]+',
        r'code=[A-Za-z][A-Za-z0-9_]*(?:;sourceEdge=\([^\r\n)]*\)[^\s"\r\n]*)?',
        r'A5:[A-Za-z][A-Za-z0-9_-]*(?:;site=[^\s;"\r\n]+)?',
        r'firstStage=[^\s;"\r\n]+;firstReason=[^\s"\r\n]+',
        r'firstReason=[^\s"\r\n]+',
        r'site=[^\s;"\r\n]+',
    ]
    for expression in expressions:
        match = re.search(expression, block)
        if match:
            return match.group(0)
    return 'reason-not-observed'

def first_failure(text):
    return next((line.strip() for line in failure_block(text).splitlines() if
                 ': Failure' in line or 'producer failed:' in line or
                 'firstReason=' in line or 'firstStage=' in line or
                 line.startswith('[  FAILED  ] ')), 'failure-line-not-observed')

# Failure locations and decisive witnesses are supplied by the frozen manifest.
# selector:174 contains an informational precondition, never a failure-site pin.
def matches_registered_first_failure(text, registered):
    source_file, line, witness = registered
    location = first_failure(text)
    return (re.fullmatch(r'(?:[^\r\n:]*/)*' + re.escape(source_file) +
                         ':' + str(line) + r': Failure', location) is not None
            and witness in failure_block(text))

def control_failure(kind, identity, verdict, data, site):
    if verdict == 'INVALID':
        return 'invalid-execution'
    if kind == 'OBSERVE':
        return None  # PASS, RED and ABNORMAL are all census evidence.
    if kind == 'RED':
        if verdict == 'PASS':
            return None  # Unexpected improvement is reported, not hidden.
        registered = PIN.fullmatch(site)
        if registered is None or not matches_registered_first_failure(data,
                (registered.group(1), int(registered.group(2)), registered.group(3))):
            return 'unregistered-red-first-site'
        return None
    if verdict == 'PASS':
        return None
    registered = PIN.fullmatch(site) if kind == 'POSITIVE' else None
    if (registered is not None and matches_registered_first_failure(data,
            (registered.group(1), int(registered.group(2)), registered.group(3)))):
        return None  # Keep verdict RED and raw evidence unchanged.
    return 'unexpected-control-failure'

def classify_case(text, test, code, observe=False):
    run_names = re.findall(r'(?m)^\[ RUN      \] ([^\r\n]+)', text)
    ok_names = re.findall(r'(?m)^\[       OK \] ([^\r\n]+)', text)
    skipped = len(re.findall(r'(?m)^\[  SKIPPED \] ', text))
    failed_lines = re.findall(r'(?m)^\[  FAILED  \] ([^\r\n]+)', text)
    # Only exact, unadorned per-test lines are terminal verdicts; ignore
    # GoogleTest's summary counts and decorated per-test timing lines.
    # Value-parameterized failures append ", where GetParam() = <value>".
    terminal_tests = [name for name in (value.split(', where GetParam() = ', 1)[0]
                                        for value in failed_lines
                                        if not re.search(r' \([0-9]+ ms\)\Z', value))
                      if TEST.fullmatch(name)]
    run = len(run_names)
    passed = len(ok_names)
    if (code == 0 and run_names == [test] and passed == 1 and
            ok_names[0].split(' (', 1)[0] == test and skipped == 0 and
            not failed_lines):
        verdict = 'PASS'
    elif (code == 1 and run_names == [test] and not ok_names and
          skipped == 0 and terminal_tests == [test]):
        verdict = 'RED'
    elif observe and run_names == [test] and skipped == 0:
        # A census keeps crashes, timeouts and verdict-less exits of the
        # selected test as evidence; selection failures stay INVALID.
        verdict = 'ABNORMAL'
    else:
        verdict = 'INVALID'
    return verdict, run, passed, skipped

def self_test():
    test = 'Suite.Case'
    run = '[ RUN      ] Suite.Case\n'
    ok = '[       OK ] Suite.Case (0 ms)\n'
    fail = '[  FAILED  ] Suite.Case\n'
    header = 'file.cpp:12: Failure\n'
    examples = [
        ('pass', run + ok, 0, 'PASS', 'reason-not-observed'),
        ('red', run + header + 'assertion failed\n' + fail, 1, 'RED', 'reason-not-observed'),
        ('crash', run + 'Segmentation fault\n', 139, 'INVALID', 'reason-not-observed'),
        ('timeout', run + 'HARNESS_TIMEOUT 600s\n', 124, 'INVALID', 'reason-not-observed'),
        ('skip', run + '[  SKIPPED ] Suite.Case\n', 0, 'INVALID', 'reason-not-observed'),
        ('zero-run', header + fail, 1, 'INVALID', 'reason-not-observed'),
        ('factory', run + header + 'code=23;sourceAuthoritySite=phase-front\n' + fail,
         1, 'RED', 'code=23;sourceAuthoritySite=phase-front'),
        ('atlas', run + header + 'code=SingularityMismatch;sourceEdge=(2,3)\n' + fail,
         1, 'RED', 'code=SingularityMismatch;sourceEdge=(2,3)'),
        ('a5-site', run + header + 'A5:InvalidX;site=corner\n' + fail,
         1, 'RED', 'A5:InvalidX;site=corner'),
        ('a5-hyphens', run + header + 'A5:no-produced-certified-ordinary-seam\n' + fail,
         1, 'RED', 'A5:no-produced-certified-ordinary-seam'),
        ('pre-failure', 'site=early\nfirstReason=wrong\n' + run + header +
         'code=17;sourceAuthoritySite=valid\n' + fail,
         1, 'RED', 'code=17;sourceAuthoritySite=valid'),
        ('no-typed', run + header + 'assertion failed without typed data\n' + fail,
         1, 'RED', 'reason-not-observed'),
        ('red-timed', run + header + '[  FAILED  ] Suite.Case (0 ms)\n'
         '[  FAILED  ] 1 test, listed below:\n' + fail, 1, 'RED', 'reason-not-observed'),
    ]
    for name, data, code, expected_verdict, expected_reason in examples:
        verdict, _, _, _ = classify_case(data, test, code)
        require(verdict == expected_verdict, f'{name}: verdict {verdict}, expected {expected_verdict}')
        reason = typed_reason(data)
        require(reason == expected_reason, f'{name}: reason {reason}, expected {expected_reason}')
    require('site=early' not in failure_block(examples[10][1]), 'failure block leaks preamble')
    require(first_failure(examples[10][1]) == 'file.cpp:12: Failure', 'first failure leaks preamble')

    param = 'P/Suite.Case/Param'
    where = ', where GetParam() = 16-byte object <BE-06 8A-02>'
    prun = f'[ RUN      ] {param}\n'
    ptimed = f'[  FAILED  ] {param}{where} (0 ms)\n'
    param_examples = [
        ('param-pass', prun + f'[       OK ] {param} (0 ms)\n', 0, 'PASS'),
        ('param-red', prun + header + ptimed + '[  FAILED  ] 1 test, listed below:\n' +
         f'[  FAILED  ] {param}{where}\n', 1, 'RED'),
        ('param-timed-only', prun + header + ptimed, 1, 'INVALID'),
    ]
    for name, data, code, expected_verdict in param_examples:
        verdict, _, _, _ = classify_case(data, param, code)
        require(verdict == expected_verdict, f'{name}: verdict {verdict}, expected {expected_verdict}')
    for name in ('Suite.Case', param):
        require(TEST.fullmatch(name) is not None, f'valid name rejected: {name}')
    for name in ('P/Suite.Case', 'Suite.Case/Param', 'A/P/Suite.Case/Param', 'Suite.*',
                 'Suite.Case:Other', 'P/Suite.Case/Pa-ram'):
        require(TEST.fullmatch(name) is None, f'invalid name accepted: {name}')

    observed = [('observe-red', examples[1], 'RED'), ('observe-crash', examples[2], 'ABNORMAL'),
                ('observe-timeout', examples[3], 'ABNORMAL'), ('observe-skip', examples[4], 'INVALID'),
                ('observe-zero-run', examples[5], 'INVALID')]
    for name, (_, data, code, _, _), expected_verdict in observed:
        verdict, _, _, _ = classify_case(data, test, code, observe=True)
        require(verdict == expected_verdict, f'{name}: verdict {verdict}, expected {expected_verdict}')
        expected_violation = 'invalid-execution' if verdict == 'INVALID' else None
        require(control_failure('OBSERVE', 'census', verdict, data, '-') == expected_violation,
                f'{name}: wrong census control result')
    require(control_failure('GUARD', 'gate', 'RED', examples[1][1], '-') ==
            'unexpected-control-failure', 'gate RED no longer fails its control')

    with tempfile.TemporaryDirectory() as scratch:
        path = Path(scratch) / 'cases.tsv'
        rows = [HEADER, ['1', 'OBSERVE', 'census:1', param, 'bin', 'OBSERVE', '-'],
                ['2', 'GUARD', 'gate:2', test, 'bin', 'PASS', '-']]
        path.write_text(''.join('\t'.join(row) + '\n' for row in rows))
        try:
            read_cases(path, 2)
        except ValueError as error:
            require('mixed' in str(error), f'mixed manifest: unexpected error {error}')
        else:
            raise ValueError('mixed OBSERVE/gate manifest accepted')
        path.write_text(''.join('\t'.join(row) + '\n' for row in rows[:2]))
        require(len(read_cases(path, 1)) == 1, 'OBSERVE-only manifest rejected')

    # Real --gtest_list_tests output (gtest_main, named TEST_P instances, DISABLED_).
    listing = ('Running main() from src/gtest_main.cc\nPlain.\n  First\n  DISABLED_Off\nFix.\n  Third\n'
               'U/Accept.\n  Out/Plane  # GetParam() = 16-byte object <D3-8D>\n'
               '  Out/Seam  # GetParam() = 16-byte object <D9-8D>\n')
    listed = {'Plain.First', 'Plain.DISABLED_Off', 'Fix.Third', 'U/Accept.Out/Plane', 'U/Accept.Out/Seam'}
    require(list_tests(listing) == listed, 'gtest listing misparsed')
    gate = [['1', 'GUARD', 'g:1', 'Plain.First', 'bin_tests', 'PASS', '-'],
            ['2', 'GUARD', 'g:2', 'U/Accept.Out/Plane', 'bin_tests', 'PASS', '-']]
    ledger = [('Plain.DISABLED_Off', 'bin_tests'), ('Fix.Third', 'bin_tests'), ('U/Accept.Out/Seam', 'bin_tests')]
    states = {row[1]: row[2] for row in membership(gate, ledger, {'bin_tests': listing})}
    require(states == {'Plain.First': 'GATED', 'U/Accept.Out/Plane': 'GATED', 'Plain.DISABLED_Off': 'DEFERRED',
                       'Fix.Third': 'DEFERRED', 'U/Accept.Out/Seam': 'DEFERRED'}, 'membership states wrong')
    rejected = [('ungoverned', gate, ledger[:2], {'bin_tests': listing}),
                ('stale', gate, ledger + [('Fix.Gone', 'bin_tests')], {'bin_tests': listing}),
                ('unpackaged', gate, ledger + [('Other.Case', 'other_tests')], {'bin_tests': listing}),
                ('ungoverned-binary', gate, ledger, {'bin_tests': listing, 'new_tests': 'New.\n  Case\n'}),
                ('typed-suite', gate, ledger, {'bin_tests': listing + 'T/0.  # TypeParam = int\n  Case\n'})]
    for name, gate_rows, ledger_rows, listings in rejected:
        try:
            membership(gate_rows, ledger_rows, listings)
        except ValueError:
            pass
        else:
            raise ValueError(f'membership {name} accepted')
    with tempfile.TemporaryDirectory() as scratch:
        path = Path(scratch) / 'ledger.tsv'
        entry = ['85', 'offgate:85', 'Fix.Third', 'bin_tests', 'RED', '1', 'P01', 'FIXTURE', '-']
        path.write_text('\t'.join(LEDGER_HEADER) + '\n' + '\t'.join(entry) + '\n')
        require(read_ledger(path, gate) == [('Fix.Third', 'bin_tests')], 'valid ledger rejected')
        for name, bad_cases in (('overlap', gate + [['3', 'GUARD', 'g:3', 'Fix.Third', 'bin_tests', 'PASS', '-']]),
                                ('census', [['1', 'OBSERVE', 'c:1', 'Plain.First', 'bin_tests', 'OBSERVE', '-']])):
            try:
                read_ledger(path, bad_cases)
            except ValueError:
                pass
            else:
                raise ValueError(f'ledger {name} accepted')
    print(f'SELF_TEST_PASS cases={len(examples) + len(param_examples) + len(observed) + 1 + len(rejected) + 3}')

if MODE == 'self-test':
    try:
        self_test()
    except Exception as error:
        print(f'SELF_TEST_FAIL {error}', file=sys.stderr)
        sys.exit(1)
    sys.exit(0)
if MODE == 'self-check':
    try:
        cases = read_cases(MANIFEST_ARG, expected_count(COUNT_ARG))
        deferred = f' deferred={len(read_ledger(LEDGER_ARG, cases))}' if LEDGER_ARG else ''
        print(f'SELF_CHECK_PASS cases={len(cases)}{deferred}')
    except Exception as error:
        print(f'SELF_CHECK_FAIL {error}', file=sys.stderr)
        sys.exit(1)
    sys.exit(0)

def observe_termination(executable, test, workdir, output):
    """One bounded debugger-owned inferior; never a gate or a retry."""
    import errno
    import pty
    import select
    import time
    import tty

    gdb = shutil.which('gdb')
    require(gdb is not None, 'GNU debugger unavailable')
    require(hasattr(os, 'pidfd_open') and hasattr(signal, 'pidfd_send_signal'),
            'Linux PID file descriptor support unavailable')
    env = {key: os.environ[key] for key in ('PATH', 'HOME', 'LANG', 'LC_ALL', 'TMPDIR')
           if key in os.environ}
    env.update(GTEST_COLOR='no', GTEST_FAIL_IF_NO_TEST_SELECTED='1', LC_ALL='C')
    log_path = output / 'raw/1006.log'
    start = time.monotonic()
    deadline = start + 600
    master, slave = pty.openpty()
    tty.setraw(slave)
    terminal = os.ttyname(slave)
    pid = None
    pidfd = None
    stopped = None
    responses = {}
    pending = b''
    sample_count = 0
    next_token = 0
    result = {'mode': 'non-gating-external-observation', 'test': test,
              'budget_seconds': 600, 'sample_interval_seconds': 30,
              'samples': [], 'outcome': 'observer-error', 'semanticAcceptance': False}
    process = None
    try:
        with log_path.open('wb') as raw, (output / 'gdb-mi.log').open('wb') as transcript:
            process = subprocess.Popen([gdb, '--nx', '--nh', '--quiet', '--interpreter=mi2',
                                        '-iex', 'set auto-load off', str(executable)],
                                       cwd=workdir, env=env, stdin=subprocess.PIPE,
                                       stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                       start_new_session=True)
            def pump(until):
                nonlocal pending, pid, pidfd, stopped
                require(process.poll() is None, 'debugger exited unexpectedly')
                ready, _, _ = select.select([process.stdout, master], [], [],
                                            max(0, min(0.2, until - time.monotonic())))
                for fd in ready:
                    try:
                        data = os.read(fd if isinstance(fd, int) else fd.fileno(), 65536)
                    except OSError as error:
                        if fd == master and error.errno == errno.EIO:
                            continue
                        raise
                    if fd == master:
                        raw.write(data)
                        raw.flush()
                        continue
                    require(bool(data), 'debugger output closed')
                    transcript.write(data)
                    transcript.flush()
                    pending += data
                    while b'\n' in pending:
                        line, pending = pending.split(b'\n', 1)
                        line = line.decode(errors='replace').rstrip('\r')
                        match = re.match(r'^(\d+)\^(.*)$', line)
                        if match:
                            responses[int(match[1])] = match[2]
                        if line.startswith('=thread-group-started,'):
                            match = re.search(r'pid="([0-9]+)"', line)
                            require(match is not None and pid is None, 'unexpected inferior identity')
                            pid = int(match[1])
                            try:
                                pidfd = os.pidfd_open(pid)
                            except ProcessLookupError:
                                pass  # An organic exit can precede receipt of this event.
                        if line.startswith('*stopped,'):
                            stopped = line

            def wait(predicate, until, label):
                while not predicate():
                    require(time.monotonic() < until, f'observer deadline: {label}')
                    pump(until)

            def command(text, expected='done', limit=15):
                nonlocal next_token
                next_token += 1
                token = next_token
                transcript.write(f'# command {token}{text}\n'.encode())
                transcript.flush()
                process.stdin.write(f'{token}{text}\n'.encode())
                process.stdin.flush()
                wait(lambda: token in responses, min(deadline, time.monotonic() + limit), text)
                response = responses.pop(token)
                require(response.split(',', 1)[0] == expected, f'debugger command failed: {text}: {response}')

            command('-gdb-version')
            for setting in ('pagination off', 'confirm off', 'disable-randomization off',
                            'mi-async on', 'startup-with-shell off', 'print frame-arguments none', 'debuginfod enabled off'):
                command('-gdb-set ' + setting)
            command('-inferior-tty-set ' + json.dumps(terminal))
            command('-exec-arguments --gtest_filter=' + test)
            command('-exec-run', 'running')
            wait(lambda: pid is not None, min(deadline, time.monotonic() + 15), 'inferior PID')
            next_sample = time.monotonic() + 30
            # Reserve time for the final sample and cleanup inside the diagnostic budget.
            while time.monotonic() < deadline - 25:
                if stopped is not None:
                    break
                pump(min(next_sample, deadline - 25))
                if time.monotonic() < next_sample or stopped is not None:
                    continue
                data = log_path.read_bytes()
                sample = {'elapsed_seconds': round(time.monotonic() - start, 3),
                          'pid': pid, 'log_bytes': len(data),
                          'log_sha256': hashlib.sha256(data).hexdigest(),
                          'receipts': [line.decode(errors='replace') for line in data.splitlines()
                                       if line.startswith(b'SlideEntryActivationReach recipe=')]}
                # Observe scheduler/resource counters before interruption, not debugger-stop state.
                for name in ('stat', 'status', 'wchan'):
                    try:
                        sample[name] = (Path('/proc') / str(pid) / name).read_text()
                    except OSError as error:
                        sample[name] = f'unavailable: {type(error).__name__}'
                tasks = Path('/proc') / str(pid) / 'task'
                sample['threads'] = {}
                for task in sorted(tasks.glob('[0-9]*')):
                    try:
                        sample['threads'][task.name] = {name: (task / name).read_text()
                                                        for name in ('stat', 'wchan')}
                    except OSError:
                        continue  # A thread may finish during observation.
                result['samples'].append(sample)
                sample_count += 1
                (output / 'observation.json').write_text(json.dumps(result, indent=2) + '\n')
                print(f'OBSERVE sample={sample_count} log_bytes={len(data)} receipts={len(sample["receipts"])}', flush=True)
                command('-exec-interrupt --all')
                wait(lambda: stopped is not None, min(deadline, time.monotonic() + 10), 'inferior stop')
                if 'reason="signal-received"' not in stopped or 'signal-name="SIGINT"' not in stopped:
                    break
                sample['pc_command_token'] = next_token + 1
                command('-interpreter-exec console "info registers pc"')
                sample['stack_command_token'] = next_token + 1
                command('-interpreter-exec console "thread apply all bt 40"')
                if sample_count == 1:
                    command('-interpreter-exec console "info proc mappings"')
                sample['stack_completed'] = True
                stopped = None
                command('-exec-continue', 'running')
                next_sample = time.monotonic() + 30
            # A late organic exit is distinguished from a deliberate observer cutoff.
            pump(min(deadline, time.monotonic() + 0.2))
            result['stop_record'] = stopped
            if stopped and 'reason="exited-normally"' in stopped:
                result['outcome'] = 'organic-exit-zero'
                code = 0
            elif stopped and 'reason="exited"' in stopped:
                result['outcome'] = 'organic-nonzero-exit'
                match = re.search(r'exit-code="([0-7]+)"', stopped)
                code = int(match[1], 8) if match else 90
            elif stopped:
                result['outcome'] = 'unexpected-inferior-stop'
                code = 90
            else:
                result['outcome'] = 'bounded-observation-ended'
                code = 124
            # Drain pending inferior output before closing the raw receipt.
            while time.monotonic() < deadline and select.select([master], [], [], 0)[0]:
                try:
                    data = os.read(master, 65536)
                except OSError as error:
                    if error.errno == errno.EIO:
                        break
                    raise
                if not data:
                    break
                raw.write(data)
            result['observer_exit_code'] = code
            if result['outcome'].startswith('organic-'):
                result['inferior_exit_code'] = code
            return code
    except Exception as error:
        result['error'] = f'{type(error).__name__}: {error}'
        print('OBSERVER_FAILURE', result['error'], flush=True)
        return 90
    finally:
        # A PID file descriptor identifies the exact inferior, even if GDB
        # gives it a separate session. Do not signal an unrelated process.
        if process is not None:
            if pidfd is not None:
                try:
                    signal.pidfd_send_signal(pidfd, signal.SIGKILL)
                except ProcessLookupError:
                    pass
                finally:
                    os.close(pidfd)
            if process.poll() is None:
                try:
                    process.stdin.write(b'-gdb-exit\n')
                    process.stdin.flush()
                    process.wait(timeout=3)
                except (BrokenPipeError, subprocess.TimeoutExpired):
                    try:
                        os.killpg(process.pid, signal.SIGKILL)
                    except ProcessLookupError:
                        pass
                    process.wait(timeout=10)
            result['debugger_exit_code'] = process.returncode
        os.close(master)
        os.close(slave)
        result['elapsed_seconds'] = round(time.monotonic() - start, 3)
        result['inferior_pid'] = pid
        (output / 'observation.json').write_text(json.dumps(result, indent=2) + '\n')

ROOT = Path(os.environ['RUNNER_TEMP']) / os.environ['TURN_ID']
OUT = Path(str(ROOT) + '-result')
(OUT / 'raw').mkdir(parents=True, exist_ok=True)
(OUT / 'resources').mkdir(parents=True, exist_ok=True)
ROOT.mkdir(parents=True, exist_ok=True)
state = dict(planned=0, executed=0, passed=0, red=0, abnormal=0, missing=0,
             skipped=0, duplicate=0, control_bad=0, unexpected_pass=0,
             later_positive_red=0, red_site_bad=0, membership=0, postflight=False)
rows = []
exit_code = 90
source_sha = ''
artifact_id = None
error_message = ''
diagnostic = os.environ.get('REACH_TERMINATION_DIAGNOSTIC', '')

try:
    require(diagnostic in ('', '1'), 'invalid diagnostic mode')
    required = ['CANDIDATE_ARTIFACT_ID', 'EXPECTED_SOURCE_SHA',
                'EXPECTED_CANDIDATE_ZIP_SHA256', 'EXPECTED_ROOT_MANIFEST_SHA256',
                'EXPECTED_SOURCE_ARCHIVE_SHA256', 'CASE_MANIFEST', 'CASE_MANIFEST_SHA256',
                'EXPECTED_CASE_COUNT']
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

    def repo_file(relative, sha256, label):
        relative = Path(relative)
        require(not relative.is_absolute() and '..' not in relative.parts, f'{label} must be repo relative')
        path = (workspace / relative).resolve()
        require(workspace in path.parents and path.is_file() and not path.is_symlink(), f'{label} missing/unsafe')
        require(HEX64.fullmatch(sha256) is not None and digest(path) == sha256, f'{label} checksum mismatch')
        return path

    case_path = repo_file(values['CASE_MANIFEST'], values['CASE_MANIFEST_SHA256'], 'case manifest')
    cases = read_cases(case_path, expected_count(values['EXPECTED_CASE_COUNT']))
    # A gate run must account for every packaged test (O14); a census never takes a ledger.
    gate = cases[0][1] != 'OBSERVE'
    require(gate == ('MEMBERSHIP_LEDGER' in os.environ), 'gate runs require MEMBERSHIP_LEDGER; censuses forbid it')
    ledger = read_ledger(repo_file(os.environ['MEMBERSHIP_LEDGER'], os.environ.get('MEMBERSHIP_LEDGER_SHA256', ''),
                                   'deferred ledger'), cases) if gate else []
    state['planned'] = len(cases)
    if diagnostic:
        require(values == {
            'CANDIDATE_ARTIFACT_ID': '14995401750',
            'EXPECTED_SOURCE_SHA': '21087c8285a5dd367cc16f610386accc061bd194',
            'EXPECTED_CANDIDATE_ZIP_SHA256': '7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9',
            'EXPECTED_ROOT_MANIFEST_SHA256': '255e344116e2faa2d351b637cdfc6d11805b83352965f794b8bddaf56409f5d3',
            'EXPECTED_SOURCE_ARCHIVE_SHA256': 'bba6f2ce82c27a1481dad5fb16952b88476fca25411840a3e6d588ad67d2502e',
            'CASE_MANIFEST': '.agents/Directional/gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv',
            'CASE_MANIFEST_SHA256': 'a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587',
            'EXPECTED_CASE_COUNT': '1006'}, 'diagnostic package/gate authority mismatch')
        require(os.environ['MEMBERSHIP_LEDGER_SHA256'] == 'fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce'
                and len(ledger) == 81, 'diagnostic deferred authority mismatch')
        require(cases[-1] == ['1006', 'GUARD', 'tb-rev-184:slide-entry-activation-reach',
                'TraceTerminationCorrection.SlideEntryActivationReachByReaderRecipe',
                'directional_surface_cell_producer_tests', 'PASS', '-'], 'diagnostic row mismatch')
        state['planned'] = 0  # No gate cases are executed in this mode.
    print(f'PREFLIGHT cases={len(cases)} deferred={len(ledger)} source={source_sha} artifact={artifact_id}', flush=True)

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
    if gate and not diagnostic:
        listings = {}
        for entry in sorted(view_bin.iterdir()):
            if entry.is_file() and entry.name.endswith('_tests'):
                listing = subprocess.run(['env', 'GTEST_COLOR=no', str(entry), '--gtest_list_tests'],
                                         cwd=ROOT, capture_output=True, text=True, timeout=120)
                require(listing.returncode == 0, f'test listing failed: {entry.name}')
                listings[entry.name] = listing.stdout
        members = membership(cases, ledger, listings)
        with (OUT / 'membership.tsv').open('w', newline='', encoding='utf-8') as stream:
            csv.writer(stream, delimiter='\t').writerows([['binary', 'test', 'state']] + members)
        state['membership'] = len(members)
        print(f'MEMBERSHIP binaries={len(listings)} tests={len(members)}', flush=True)

    if diagnostic:
        row, _, _, test, binary, _, _ = cases[-1]
        workdir = ROOT / 'run' / row
        workdir.mkdir(parents=True, exist_ok=True)
        diagnostic_code = observe_termination(view_bin / binary, test, workdir, OUT)
        # Never convert diagnostic results into gate ledger rows or PASS counts.
    for case in ([] if diagnostic else cases):
        row, kind, identity, test, binary, expect, site = case
        executable = view_bin / binary
        workdir = ROOT / 'run' / row
        workdir.mkdir(parents=True, exist_ok=True)
        log = OUT / 'raw' / f'{row}.log'
        resource = OUT / 'resources' / f'{row}.time.txt'
        command = ['/usr/bin/time', '-v', '-o', str(resource), 'env',
                   'GTEST_FAIL_IF_NO_TEST_SELECTED=1', 'GTEST_COLOR=no',
                   str(executable), '--gtest_filter=' + test]
        with log.open('w') as stream:
            process = subprocess.Popen(command, cwd=workdir, stdout=stream,
                                       stderr=subprocess.STDOUT, start_new_session=True)
            try:
                code = process.wait() if gate else process.wait(timeout=600)
            except subprocess.TimeoutExpired:
                try:
                    os.killpg(process.pid, signal.SIGKILL)
                except ProcessLookupError:
                    pass
                process.wait()  # Reap before closing or reading the log.
                stream.write('\nHARNESS_TIMEOUT 600s\n')
                stream.flush()
                code = 124
        data = log.read_text(errors='replace')
        verdict, run, passed, skipped = classify_case(data, test, code, kind == 'OBSERVE')
        state['executed'] += int(run == 1 and skipped == 0)
        state['passed'] += int(verdict == 'PASS')
        state['red'] += int(verdict == 'RED')
        state['abnormal'] += int(verdict == 'ABNORMAL')
        state['skipped'] += skipped
        state['missing'] += int(verdict == 'INVALID')
        state['duplicate'] += int(run > 1)
        violation = control_failure(kind, identity, verdict, data, site)
        state['control_bad'] += int(violation is not None)
        state['red_site_bad'] += int(violation == 'unregistered-red-first-site')
        state['later_positive_red'] += int(kind == 'POSITIVE' and verdict == 'RED' and
                                           violation is None)
        state['unexpected_pass'] += int(kind == 'RED' and verdict == 'PASS')
        rows.append([row, kind, identity, test, binary, verdict, code, run, passed, skipped,
                     first_failure(data), '' if verdict == 'PASS' else typed_reason(data), digest(log)])
        print(f'CASE {row}/{len(cases)} {kind} {identity} {verdict}' +
              (f' control_violation={violation}' if violation else ''), flush=True)

    require(sha_manifest(package) == package_count, 'package postflight mismatch')
    after = {str(path.relative_to(view)): digest(path) for path in view.rglob('*') if path.is_file()}
    require(before == after, 'staged view mutated')
    state['postflight'] = True
    if diagnostic:
        data = (OUT / 'raw/1006.log').read_text(errors='replace')
        require(re.findall(r'(?m)^\[ RUN      \] ([^\r\n]+)', data) == [test],
                'diagnostic did not select exactly the frozen test')
        if diagnostic_code == 0:
            require(classify_case(data, test, 0)[0] == 'PASS',
                    'organic zero exit without exact terminal Google Test evidence')
    require(state['executed'] == state['planned'] and state['missing'] == 0 and
            state['duplicate'] == 0 and state['skipped'] == 0, 'selection failure')
    require(state['control_bad'] == 0, 'required controls failed')
    exit_code = diagnostic_code if diagnostic else 0
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
        'configure': False, 'benchmark': False, 'exit': exit_code,
        **({'nonGatingDiagnostic': True} if diagnostic else {})}, indent=2) + '\n')
    with (OUT / 'SHA256SUMS').open('w') as stream:
        for path in sorted(OUT.rglob('*')):
            if path.is_file() and path.name != 'SHA256SUMS':
                stream.write(digest(path) + '  ' + str(path.relative_to(OUT)) + '\n')
    print('TARGETED_HARNESS_RESULT', json.dumps(state), f'exit={exit_code}', flush=True)
sys.exit(exit_code)
PY
