#!/usr/bin/env python3
"""Run a frozen gate manifest against a local package with the P8 harness's own logic.

The CI harness (`m6_cp3_targeted_artifact_harness.sh --execute`) downloads its
package through the GitHub API and uses Linux tools (`ldd`, GNU `time -v`).
This driver loads the harness's embedded Python definitions unchanged (case
and ledger parsing, P8 membership, `classify_case`, control checks) and
replaces only the I/O: a local package ZIP with pinned hashes, `otool -L`,
BSD `time -l`, and a bounded worker pool. Each case still runs alone in its
own process and working directory.
"""
import argparse
import concurrent.futures
import csv
import hashlib
import json
import os
import platform
import shutil
import signal
import subprocess
import sys
import tarfile
from pathlib import Path


def sha256(path):
    h = hashlib.sha256()
    with open(path, 'rb') as stream:
        for block in iter(lambda: stream.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()


def load_harness(path, expected_sha):
    if sha256(path) != expected_sha:
        sys.exit(f'harness checksum mismatch: {path}')
    text = Path(path).read_text()
    body = text.split("<<'PY'\n", 1)[1].rsplit('\nPY\n', 1)[0]
    definitions = body.split("ROOT = Path(os.environ['RUNNER_TEMP'])", 1)[0]
    namespace = {'__name__': 'harness'}
    saved = sys.argv
    sys.argv = ['harness', 'execute', '', '', '']
    try:
        exec(compile(definitions, str(path), 'exec'), namespace)
    finally:
        sys.argv = saved
    return namespace


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    for name in ('harness', 'harness-sha', 'package-zip', 'package-zip-sha', 'root-manifest-sha',
                 'source-sha', 'source-archive-sha', 'manifest', 'manifest-sha', 'count',
                 'ledger', 'ledger-sha', 'work'):
        parser.add_argument('--' + name, required=True)
    parser.add_argument('--jobs', type=int, default=3)
    args = parser.parse_args()

    h = load_harness(args.harness, args.harness_sha)
    require, digest = h['require'], h['digest']
    root = Path(args.work).resolve()
    out = Path(str(root) + '-result')
    require(not root.exists() and not out.exists(), 'work directory must be fresh')
    (out / 'raw').mkdir(parents=True)
    (out / 'resources').mkdir(parents=True)
    root.mkdir(parents=True)
    state = dict(planned=0, executed=0, passed=0, red=0, abnormal=0, missing=0,
                 skipped=0, duplicate=0, control_bad=0, unexpected_pass=0,
                 later_positive_red=0, red_site_bad=0, membership=0, postflight=False)
    rows, exit_code, error_message = [], 90, ''
    try:
        require(digest(args.manifest) == args.manifest_sha, 'case manifest checksum mismatch')
        cases = h['read_cases'](args.manifest, h['expected_count'](args.count))
        require(cases[0][1] != 'OBSERVE', 'the local driver runs gates only')
        require(digest(args.ledger) == args.ledger_sha, 'deferred ledger checksum mismatch')
        ledger = h['read_ledger'](args.ledger, cases)
        state['planned'] = len(cases)
        print(f'PREFLIGHT cases={len(cases)} deferred={len(ledger)} source={args.source_sha}', flush=True)

        zipped = root / 'package.zip'
        shutil.copy2(args.package_zip, zipped)
        require(digest(zipped) == args.package_zip_sha, 'candidate ZIP checksum mismatch')
        package = root / 'pkg'
        package.mkdir()
        subprocess.run(['unzip', '-q', str(zipped), '-d', str(package)], check=True)
        require(digest(package / 'SHA256SUMS') == args.root_manifest_sha, 'root checksum list mismatch')
        package_count = h['sha_manifest'](package)
        require((package / 'metadata/source-commit.txt').read_text().strip() == args.source_sha,
                'package source mismatch')
        require((package / 'metadata/build-exit-code.txt').read_text().strip() == '0',
                'package build exit not zero')
        boundary = (package / 'metadata/command-boundary.txt').read_text().splitlines()
        require('runtimeExecution=false' in boundary and 'exactArithmeticBackend=GMP' in boundary,
                'GMP/runtime-free compile evidence missing')
        archive_path = package / 'source' / f'source-{args.source_sha}.tar.gz'
        require(digest(archive_path) == args.source_archive_sha, 'source archive mismatch')
        source = root / 'source'
        source.mkdir()
        with tarfile.open(archive_path) as archive:
            archive.extractall(source, filter='data')
        fixtures = source / 'benchmarks/fixtures'
        require(fixtures.is_dir(), 'packaged source fixtures missing')
        view = root / 'view'
        view_bin = view / 'bin'
        view_bin.mkdir(parents=True)
        for entry in (package / 'bin').iterdir():
            if entry.is_file():
                shutil.copy2(entry, view_bin / entry.name)
                require(os.access(view_bin / entry.name, os.X_OK), f'missing executable mode {entry.name}')
        shutil.copytree(fixtures, view / 'test-data/benchmarks/fixtures')
        before = {str(p.relative_to(view)): digest(p) for p in view.rglob('*') if p.is_file()}
        for binary in sorted({case[4] for case in cases}):
            executable = view_bin / binary
            require(executable.is_file(), f'missing executable {binary}')
            deps = subprocess.run(['otool', '-L', str(executable)], capture_output=True, text=True, check=True)
            require('libgmp' in deps.stdout, f'GMP dependency missing for {binary}')
            (out / f'dependencies-{binary}.txt').write_text(deps.stdout + deps.stderr)

        listings = {}
        for entry in sorted(view_bin.iterdir()):
            if entry.is_file() and entry.name.endswith('_tests'):
                listing = subprocess.run(['env', 'GTEST_COLOR=no', str(entry), '--gtest_list_tests'],
                                         cwd=root, capture_output=True, text=True, timeout=120)
                require(listing.returncode == 0, f'test listing failed: {entry.name}')
                listings[entry.name] = listing.stdout
        members = h['membership'](cases, ledger, listings)
        with (out / 'membership.tsv').open('w', newline='', encoding='utf-8') as stream:
            csv.writer(stream, delimiter='\t').writerows([['binary', 'test', 'state']] + members)
        state['membership'] = len(members)
        print(f'MEMBERSHIP binaries={len(listings)} tests={len(members)}', flush=True)

        def run_case(case):
            row, kind, identity, test, binary, expect, site = case
            workdir = root / 'run' / row
            workdir.mkdir(parents=True)
            log = out / 'raw' / f'{row}.log'
            resource = out / 'resources' / f'{row}.time.txt'
            command = ['/usr/bin/time', '-l', '-o', str(resource), 'env',
                       'GTEST_FAIL_IF_NO_TEST_SELECTED=1', 'GTEST_COLOR=no',
                       str(view_bin / binary), '--gtest_filter=' + test]
            with log.open('w') as stream:
                process = subprocess.Popen(command, cwd=workdir, stdout=stream,
                                           stderr=subprocess.STDOUT, start_new_session=True)
                try:
                    code = process.wait(timeout=600)
                except subprocess.TimeoutExpired:
                    try:
                        os.killpg(process.pid, signal.SIGKILL)
                    except ProcessLookupError:
                        pass
                    process.wait()
                    stream.write('\nHARNESS_TIMEOUT 600s\n')
                    stream.flush()
                    code = 124
            return case, code, log.read_text(errors='replace'), digest(log)

        with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
            results = list(pool.map(run_case, cases))
        for case, code, data, log_sha in results:
            row, kind, identity, test, binary, expect, site = case
            verdict, run, passed, skipped = h['classify_case'](data, test, code, kind == 'OBSERVE')
            state['executed'] += int(run == 1 and skipped == 0)
            state['passed'] += int(verdict == 'PASS')
            state['red'] += int(verdict == 'RED')
            state['abnormal'] += int(verdict == 'ABNORMAL')
            state['skipped'] += skipped
            state['missing'] += int(verdict == 'INVALID')
            state['duplicate'] += int(run > 1)
            violation = h['control_failure'](kind, identity, verdict, data, site)
            state['control_bad'] += int(violation is not None)
            state['red_site_bad'] += int(violation == 'unregistered-red-first-site')
            state['later_positive_red'] += int(kind == 'POSITIVE' and verdict == 'RED' and violation is None)
            state['unexpected_pass'] += int(kind == 'RED' and verdict == 'PASS')
            rows.append([row, kind, identity, test, binary, verdict, code, run, passed, skipped,
                         h['first_failure'](data), '' if verdict == 'PASS' else h['typed_reason'](data),
                         log_sha])
            print(f'CASE {row}/{len(cases)} {kind} {identity} {verdict}' +
                  (f' control_violation={violation}' if violation else ''), flush=True)

        require(h['sha_manifest'](package) == package_count, 'package postflight mismatch')
        after = {str(p.relative_to(view)): digest(p) for p in view.rglob('*') if p.is_file()}
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
        with (out / 'ledger.tsv').open('w', newline='', encoding='utf-8') as stream:
            writer = csv.writer(stream, delimiter='\t')
            writer.writerow(['row', 'kind', 'identity', 'test', 'binary', 'verdict', 'exit',
                             'run', 'passed', 'skipped', 'first_failure', 'typed_reason', 'log_sha256'])
            writer.writerows(rows)
        (out / 'execution-boundary.json').write_text(json.dumps({
            'package_zip_sha256': args.package_zip_sha, 'source': args.source_sha, 'state': state,
            'error': error_message, 'compile': False, 'relink': False, 'configure': False,
            'benchmark': False, 'exit': exit_code, 'driver': 'local',
            'platform': f'{platform.system()} {platform.release()} {platform.machine()}',
            'harness_sha256': args.harness_sha, 'jobs': args.jobs}, indent=2) + '\n')
        with (out / 'SHA256SUMS').open('w') as stream:
            for path in sorted(out.rglob('*')):
                if path.is_file() and path.name != 'SHA256SUMS':
                    stream.write(digest(path) + '  ' + str(path.relative_to(out)) + '\n')
        print('TARGETED_HARNESS_RESULT', json.dumps(state), f'exit={exit_code}', flush=True)
    sys.exit(exit_code)


if __name__ == '__main__':
    main()
