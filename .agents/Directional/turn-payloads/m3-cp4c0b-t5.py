import collections
import hashlib
import json
import os
import re
import shutil
import stat
import subprocess
import sys
import time
from pathlib import Path

T = Path(os.environ['RUNNER_TEMP'])
R = os.environ['GITHUB_REPOSITORY']
RUN_ID = int(os.environ['GITHUB_RUN_ID'])
O = T / 'm3-cp4c0b-t5-result'
P = T / 'm3-cp4c0b-t5-package'
SROOT = T / 'm3-cp4c0b-t5-source'
Z = T / 'm3-cp4c0b-t5-package.zip'
for p in (O, P, SROOT):
    shutil.rmtree(p, ignore_errors=True)
    p.mkdir(parents=True)
(O / 'non-gating').mkdir()
(O / 'identity').mkdir()

PACKAGE_ID = '9671190795'
PACKAGE_SHA = '2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1'
SOURCE_SHA = '93059089881c8715a168a61968a8d6874ee1a670'
REQUIRED_SHA = '51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5'
PREFIX346_SHA = '20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a'
PREFIX316_SHA = '601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c'
NON_GATING_SHA = 'd42240028fb2586fa96a87cc7c058aeaa34279d5fc7b80508c4aa68472e2d9ad'
HISTORICAL_MAX_PASS_MS = 16397
SLOW_MULTIPLE = 4
SLOW_THRESHOLD_MS = HISTORICAL_MAX_PASS_MS * SLOW_MULTIPLE
WATCHED = {7, 9, 12, 13}
AUTHORIZED_REAUTHOR = {7, 9}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def inventory(root, sub='.'):
    base = Path(root) / sub
    return {
        str(p.relative_to(root)): sha(p)
        for p in sorted(base.rglob('*'))
        if p.is_file()
    }


def modes(root):
    root = Path(root)
    return {
        str(p.relative_to(root)): oct(stat.S_IMODE(p.stat().st_mode))
        for p in sorted(root.rglob('*'))
    }


def run_identity(identity, target, stem):
    j = Path(str(stem) + '.json')
    l = Path(str(stem) + '.log')
    started = time.monotonic_ns()
    p = subprocess.run(
        [str(P / 'bin' / target), '--gtest_color=no', f'--gtest_filter={identity}', f'--gtest_output=json:{j}'],
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    out = p.stdout or ''
    elapsed_ms = (time.monotonic_ns() - started) // 1_000_000
    l.write_text(out)
    print(out, end='')
    data = json.loads(j.read_text()) if j.exists() else {}
    selected = int(data.get('tests', 0))
    failures = int(data.get('failures', 0)) + int(data.get('errors', 0))
    cpp_exception = 'C++ exception with description' in out
    if selected != 1:
        status = 'ORCHESTRATION_RED'
    elif p.returncode == 0 and failures == 0:
        status = 'PASS'
    else:
        status = 'RED'
    return {
        'identity': identity,
        'target': target,
        'exit': p.returncode,
        'selected': selected,
        'failures': failures,
        'ms': elapsed_ms,
        'status': status,
        'cppException': cpp_exception,
        'slow': elapsed_ms > SLOW_THRESHOLD_MS,
        'log': out,
    }


def tagged_line(log, tag):
    lines = [line.strip() for line in log.splitlines() if tag in line]
    if len(lines) != 1:
        raise RuntimeError(f'expected exactly one {tag} line, observed {len(lines)}')
    return lines[0]


def int_field(line, name):
    m = re.search(r'(?:^|;)' + re.escape(name) + r'=([0-9]+)', line)
    if not m:
        raise RuntimeError(f'missing {name} in census line')
    return int(m.group(1))


def ratio_field(line, name):
    m = re.search(r'(?:^|;)' + re.escape(name) + r'=([0-9]+)/([0-9]+)', line)
    if not m:
        raise RuntimeError(f'missing {name} ratio in census line')
    return int(m.group(1)), int(m.group(2))


def guard_zero(line):
    return ';guardFired={N1=0,N2=0,N4=0}' in line


def parse_u3u4(non_rows):
    logs = {row['identity']: row['log'] for row in non_rows}
    fan_id = 'ResolvedBranchCorrection.FourTriangleFanTerminationCensusIsPublishedNonGating'
    ring_id = 'ResolvedBranchCorrection.TwoRingContactPairingCensusIsPublishedNonGating'
    sphere_id = 'ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating'
    contact_id = 'ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating'
    fan = tagged_line(logs[fan_id], 'm3Cp4c0bV2;')
    ring = tagged_line(logs[ring_id], 'm3Cp4c0bV3;')
    sphere = tagged_line(logs[sphere_id], 'm3Cp4c0G5;')
    contact_lines = [line.strip() for line in logs[contact_id].splitlines() if 'm3Cp4c0bS1;' in line]

    fan_exact, fan_total = ratio_field(fan, 'terminalKindsExactlyOne')
    ring_exact, ring_total = ratio_field(ring, 'terminalKindsExactlyOne')
    pair_values = [int(x) for x in re.findall(r'pairedFirstContact=([01])', ring)]
    result = {
        'fan': {
            'line': fan,
            'statusReached': ';status=reached' in fan,
            'railAuthorityAtlasDerived': ';railAuthority=AtlasDerived' in fan,
            'guardSilence': guard_zero(fan),
            'traceCount': int_field(fan, 'traceCount'),
            'terminalKindsExactlyOne': [fan_exact, fan_total],
            'barrierTerminatingTraceCount': int_field(fan, 'barrierTerminatingTraceCount'),
            'contactTerminatingTraceCount': int_field(fan, 'contactTerminatingTraceCount'),
            'nodeCount': int_field(fan, 'nodeCount'),
            'mutualTerminationEventCount': int_field(fan, 'mutualTerminationEventCount'),
            'arrivalComparisonInconclusiveObserved': int_field(fan, 'arrivalComparisonInconclusiveObserved'),
            'eventHistogramPublished': ';eventKindHistogram={' in fan,
            'nodeProvenancePublished': ';node[0]={' in fan,
        },
        'twoRing': {
            'line': ring,
            'statusReached': ';status=reached' in ring,
            'railAuthorityAtlasDerived': ';railAuthority=AtlasDerived' in ring,
            'guardSilence': guard_zero(ring),
            'traceCount': int_field(ring, 'traceCount'),
            'terminalKindsExactlyOne': [ring_exact, ring_total],
            'barrierTerminatingTraceCount': int_field(ring, 'barrierTerminatingTraceCount'),
            'contactTerminatingTraceCount': int_field(ring, 'contactTerminatingTraceCount'),
            'nodeCount': int_field(ring, 'nodeCount'),
            'mutualTerminationEventCount': int_field(ring, 'mutualTerminationEventCount'),
            'arrivalComparisonInconclusiveObserved': int_field(ring, 'arrivalComparisonInconclusiveObserved'),
            'eventHistogramPublished': ';eventKindHistogram={' in ring,
            'nodeProvenancePublished': ';node[0]={' in ring,
            'barrierTerminationEventCount': int_field(ring, 'barrierTerminationEventCount'),
            'pairingValues': pair_values,
            'allBarrierTerminationsPaired': bool(pair_values) and all(pair_values),
            'eventLedgerPublished': ';event[0]={' in ring,
        },
        'sphere': {
            'line': sphere,
            'networkReached': ';fieldAlignedCurveNetwork=true' in sphere,
            'traceCount24': ';traceCount=24' in sphere,
            'terminalEventSummaryPublished': ';terminalEventSummary={' in sphere,
        },
        'contactPredicateCensus': {
            'publishedLineCount': len(contact_lines),
            'lines': contact_lines,
        },
    }

    fan_ok = all([
        result['fan']['statusReached'],
        result['fan']['railAuthorityAtlasDerived'],
        result['fan']['guardSilence'],
        fan_exact == fan_total,
        result['fan']['barrierTerminatingTraceCount'] == 3,
        result['fan']['contactTerminatingTraceCount'] == 0,
        result['fan']['nodeCount'] == 8,
        result['fan']['mutualTerminationEventCount'] == 0,
        result['fan']['arrivalComparisonInconclusiveObserved'] == 0,
        result['fan']['eventHistogramPublished'],
        result['fan']['nodeProvenancePublished'],
    ])
    ring_ok = all([
        result['twoRing']['statusReached'],
        result['twoRing']['railAuthorityAtlasDerived'],
        result['twoRing']['guardSilence'],
        ring_exact == ring_total,
        result['twoRing']['barrierTerminatingTraceCount'] == 3,
        result['twoRing']['contactTerminatingTraceCount'] == 0,
        result['twoRing']['nodeCount'] == 9,
        result['twoRing']['mutualTerminationEventCount'] == 0,
        result['twoRing']['arrivalComparisonInconclusiveObserved'] == 0,
        result['twoRing']['eventHistogramPublished'],
        result['twoRing']['nodeProvenancePublished'],
        result['twoRing']['barrierTerminationEventCount'] == 3,
        result['twoRing']['allBarrierTerminationsPaired'],
        result['twoRing']['eventLedgerPublished'],
    ])
    sphere_ok = all([
        result['sphere']['networkReached'],
        result['sphere']['traceCount24'],
        result['sphere']['terminalEventSummaryPublished'],
    ])
    result['predictionsMet'] = fan_ok and ring_ok and sphere_ok
    result['materialNewEvidence'] = not result['predictionsMet']
    return result


def static_routing(source_root, identities):
    producer = 'directional_surface_cell_producer_tests'
    cm = (source_root / 'cmake/DirectionalTests.cmake').read_text()
    m = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)', cm, re.S)
    if not m:
        raise RuntimeError('producer source set not found')
    targets = {
        producer: re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp', m.group(1)),
        'directional_surface_cell_authority_kernel_tests': [
            'tests/FieldTransportAtlasTests.cpp', 'tests/SurfaceCellAuthorityKernelTests.cpp'],
        'directional_surface_cell_completion_tests': [
            'tests/FlowRepStrandsPhase15Tests.cpp', 'tests/PatchDescriptorMilestoneETests.cpp',
            'tests/PureQuadCompletionPhase18Tests.cpp', 'tests/SurfaceArrangementRowIdentityTests.cpp',
            'tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
        'directional_surface_cell_validation_tests': [
            'tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp', 'tests/SurfaceMeshOptimizerPhase19Tests.cpp',
            'tests/SurfaceMeshOptimizerPhase20Tests.cpp', 'tests/SurfaceMeshOptimizerPhase21Tests.cpp',
            'tests/SurfaceMeshOptimizerPhase22Tests.cpp'],
    }
    pat = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)', re.S)
    own = collections.defaultdict(set)
    for target, paths in targets.items():
        for rel in paths:
            text = (source_root / rel).read_text(errors='replace')
            for suite, name in pat.findall(text):
                own[f'{suite}.{name}'].add(target)
    route = []
    for ordinal, identity in enumerate(identities, 1):
        if len(own[identity]) != 1:
            raise RuntimeError(f'identity owner cardinality ordinal={ordinal} identity={identity} owners={sorted(own[identity])}')
        route.append((ordinal, identity, next(iter(own[identity]))))
    return route


result = {
    'turn': 'M3-CP4c-0b-TB-T5',
    'runId': RUN_ID,
    'packageArtifactId': int(PACKAGE_ID),
    'packageSha256': PACKAGE_SHA,
    'semanticSource': SOURCE_SHA,
    'requiredSelectorSha256': REQUIRED_SHA,
    'prefix346Sha256': PREFIX346_SHA,
    'nonGatingSelectorSha256': NON_GATING_SHA,
    'exactArithmeticBackend': 'GMP',
    'configureOccurred': False,
    'compileOccurred': False,
    'relinkOccurred': False,
    'repairOccurred': False,
    'generatedDiscoveryOccurred': False,
    'mutationOccurred': False,
    'perIdentityTimeoutConfigured': False,
    'slowThresholdMs': SLOW_THRESHOLD_MS,
    'historicalMaxPassingIdentityMs': HISTORICAL_MAX_PASS_MS,
    'u0': 'PENDING',
    'u3u4': 'PENDING',
    'gate': 'NOT_RUN',
    'stopReason': 'none',
    'overall': 'PENDING',
}
pre = post = None
exit_code = 2

try:
    gh_token = os.environ.get('GH_TOKEN', '')
    if not gh_token:
        raise RuntimeError('GH_TOKEN unavailable')
    with Z.open('wb') as z:
        subprocess.run(
            ['gh', 'api', '--method', 'GET', f'repos/{R}/actions/artifacts/{PACKAGE_ID}/zip'],
            stdout=z, check=True)
    if sha(Z) != PACKAGE_SHA:
        raise RuntimeError(f'package zip hash mismatch observed={sha(Z)} expected={PACKAGE_SHA}')
    subprocess.run(['unzip', '-q', str(Z), '-d', str(P)], check=True)

    manifest = (P / 'SHA256SUMS').read_text().splitlines()
    if len(manifest) != 28:
        raise RuntimeError(f'manifest cardinality={len(manifest)} expected=28')
    for line in manifest:
        expected, rel = line.split('  ', 1)
        observed = sha(P / rel)
        if observed != expected:
            raise RuntimeError(f'manifest mismatch {rel} observed={observed} expected={expected}')
    if (P / 'metadata/source-commit.txt').read_text().strip() != SOURCE_SHA:
        raise RuntimeError('source commit mismatch')
    if (P / 'metadata/build-exit-code.txt').read_text().strip() != '0':
        raise RuntimeError('build exit code not zero')
    if (P / 'metadata/preflight-exit-code.txt').read_text().strip() != '0':
        raise RuntimeError('preflight exit code not zero')
    boundary = (P / 'metadata/command-boundary.txt').read_text()
    if not all(token in boundary for token in ('runtimeExecution=false', 'turnBoundary=Code+Build-only', 'exactArithmeticBackend=GMP')):
        raise RuntimeError('command boundary metadata mismatch')
    gmp = (P / 'metadata/gmp-evidence.txt').read_text()
    if 'libgmpxx.so' not in gmp or 'libgmp.so' not in gmp:
        raise RuntimeError('GMP/GMPXX link evidence missing')
    if any(path.read_bytes() for path in (P / 'metadata').glob('source-status-*.txt')):
        raise RuntimeError('package source status not clean')
    compiled_targets = [x for x in (P / 'metadata/compiled-targets.txt').read_text().splitlines() if x]
    expected_targets = [
        'directional_core', 'directional_pipeline', 'directional_surface_cell_authority_kernel_tests',
        'directional_surface_cell_producer_tests', 'directional_surface_cell_completion_tests',
        'directional_surface_cell_validation_tests', 'directional_compiled_api_tests', 'directional_benchmarks']
    if compiled_targets != expected_targets:
        raise RuntimeError(f'compiled target inventory mismatch {compiled_targets}')
    executables = [p.name for p in sorted((P / 'bin').iterdir())]
    if len(executables) != 6:
        raise RuntimeError(f'executable inventory count={len(executables)} expected=6')
    if not all(os.access(P / 'bin' / x, os.X_OK) for x in executables):
        raise RuntimeError('non-executable packaged binary')

    archive = P / 'source' / f'source-{SOURCE_SHA}.tar.gz'
    subprocess.run(['tar', '-xzf', str(archive), '-C', str(SROOT)], check=True)
    required_path = SROOT / '.agents/Directional/Architecture_M3_CP4c0b_Required_Green_Selector.txt'
    cp4c0_path = SROOT / '.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt'
    non_path = SROOT / '.agents/Directional/Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt'
    required = [x for x in required_path.read_text().splitlines() if x]
    cp4c0 = [x for x in cp4c0_path.read_text().splitlines() if x]
    non = [x for x in non_path.read_text().splitlines() if x]
    if len(required) != len(set(required)) or len(required) != 353 or sha(required_path) != REQUIRED_SHA:
        raise RuntimeError('required selector integrity failure')
    if len(cp4c0) != 346 or cp4c0 != required[:346] or sha(cp4c0_path) != PREFIX346_SHA:
        raise RuntimeError('CP4c-0 prefix integrity failure')
    prefix316_hash = hashlib.sha256(('\n'.join(required[:316]) + '\n').encode()).hexdigest()
    if prefix316_hash != PREFIX316_SHA:
        raise RuntimeError('accepted-316 prefix integrity failure')
    if len(non) != len(set(non)) or len(non) != 4 or sha(non_path) != NON_GATING_SHA:
        raise RuntimeError('non-gating selector integrity failure')
    if set(non) & set(required):
        raise RuntimeError('non-gating selector collides with required gate')

    route = static_routing(SROOT, required)
    non_route = static_routing(SROOT, non)
    (O / 'required-selector.txt').write_text(required_path.read_text())
    (O / 'non-gating-selector.txt').write_text(non_path.read_text())
    (O / 'route.tsv').write_text(''.join(f'{n}\t{i}\t{t}\n' for n, i, t in route))
    (O / 'non-gating-route.tsv').write_text(''.join(f'{n}\t{i}\t{t}\n' for n, i, t in non_route))

    pre = {
        'package': inventory(P),
        'packageModes': modes(P),
        'source': inventory(SROOT),
        'sourceModes': modes(SROOT),
        'fixtures': inventory(SROOT, 'benchmarks/fixtures'),
        'requiredSelector': sha(required_path),
        'nonGatingSelector': sha(non_path),
        'executables': {x: [sha(P / 'bin' / x), oct(stat.S_IMODE((P / 'bin' / x).stat().st_mode))] for x in executables},
        'packageZip': sha(Z),
        'sourceArchive': sha(archive),
    }
    (O / 'preflight-inventory.json').write_text(json.dumps(pre, sort_keys=True, indent=2))
    result['u0'] = 'PASS'

    non_rows = []
    non_zero = 0
    non_red = 0
    non_cpp = False
    non_slow = False
    for n, identity, target in non_route:
        row = run_identity(identity, target, O / 'non-gating' / f'{n:02d}-{identity}')
        non_rows.append(row)
        print(f'non_gating ordinal={n} status={row["status"]} ms={row["ms"]} identity={identity}')
        non_zero += int(row['selected'] != 1)
        non_red += int(row['status'] != 'PASS')
        non_cpp |= row['cppException']
        non_slow |= row['slow']
    (O / 'non-gating-ledger.json').write_text(json.dumps([{k: v for k, v in r.items() if k != 'log'} for r in non_rows], sort_keys=True, indent=2))
    if non_zero:
        result['stopReason'] = 'non-gating-zero-selected'
        result['u3u4'] = 'ORCHESTRATION_RED'
        raise RuntimeError('one or more non-gating identities selected zero/multiple tests')
    if non_red or non_cpp:
        result['stopReason'] = 'non-gating-runtime-red'
        result['u3u4'] = 'RED'
        exit_code = 4
    elif non_slow:
        result['stopReason'] = 'non-gating-cost-anomaly'
        result['u3u4'] = 'RED'
        exit_code = 4
    else:
        u3u4 = parse_u3u4(non_rows)
        (O / 'u3u4-census.json').write_text(json.dumps(u3u4, sort_keys=True, indent=2))
        result['u3u4Evidence'] = u3u4
        if u3u4['materialNewEvidence']:
            result['stopReason'] = 'u3-u4-prediction-failed'
            result['u3u4'] = 'RED'
            exit_code = 4
        else:
            result['u3u4'] = 'PASS'

    rows = []
    watched = {}
    passed = 0
    prefix316_passed = 0
    prefix346_passed = 0
    first_red = 0
    zero_selected = 0
    cpp_exception_seen = False
    slow_seen = False
    authorized_watch_reds = []

    if result['u3u4'] == 'PASS':
        for ordinal, identity, target in route:
            row = run_identity(identity, target, O / 'identity' / f'{ordinal:03d}-{identity}')
            rows.append(row)
            print(f'gate_identity ordinal={ordinal} status={row["status"]} ms={row["ms"]} identity={identity}')
            if ordinal in WATCHED:
                watched[str(ordinal)] = {k: v for k, v in row.items() if k != 'log'}
                watched[str(ordinal)]['logText'] = row['log']
            zero_selected += int(row['selected'] != 1)
            cpp_exception_seen |= row['cppException']
            slow_seen |= row['slow']
            if row['status'] == 'PASS':
                passed += 1
                if ordinal <= 316:
                    prefix316_passed += 1
                if ordinal <= 346:
                    prefix346_passed += 1
            else:
                if not first_red:
                    first_red = ordinal
                if ordinal in AUTHORIZED_REAUTHOR and row['status'] == 'RED' and not row['cppException'] and row['selected'] == 1:
                    authorized_watch_reds.append(ordinal)
                else:
                    result['stopReason'] = f'unauthorized-gate-red-ordinal-{ordinal}'
            if row['selected'] != 1:
                result['stopReason'] = f'gate-selection-cardinality-ordinal-{ordinal}'
            if row['cppException']:
                result['stopReason'] = f'escaping-cpp-exception-ordinal-{ordinal}'
            if row['slow']:
                result['stopReason'] = f'cost-anomaly-ordinal-{ordinal}'
            if result['stopReason'] != 'none':
                break

        result['watchedOrdinals'] = watched
        result['authorizedWatchReds'] = authorized_watch_reds
        result['gateSummary'] = {
            'required': 353,
            'executed': len(rows),
            'passed': passed,
            'accepted316Passed': prefix316_passed,
            'cp4c0Prefix346Passed': prefix346_passed,
            'firstRedOrdinal': first_red,
            'firstRedIdentity': required[first_red - 1] if first_red else 'none',
            'zeroSelected': zero_selected,
            'cppExceptionSeen': cpp_exception_seen,
            'slowIdentitySeen': slow_seen,
        }
        (O / 'gate-ledger.json').write_text(json.dumps([{k: v for k, v in r.items() if k != 'log'} for r in rows], sort_keys=True, indent=2))

        if result['stopReason'] == 'none':
            if authorized_watch_reds:
                result['gate'] = 'VALID_RED_AUTHORIZED_WATCH'
                result['stopReason'] = 'authorized-ordinal-7-or-9-red-requires-reauthor-and-review'
                exit_code = 4
            elif len(rows) == 353 and passed == 353 and prefix316_passed == 316 and prefix346_passed == 346:
                result['gate'] = 'PASS_353_OF_353'
                exit_code = 0
            else:
                result['gate'] = 'RED'
                result['stopReason'] = 'incomplete-or-red-gate'
                exit_code = 4
        else:
            result['gate'] = 'STOPPED_RED'
            exit_code = 4

except Exception as exc:
    if result['stopReason'] == 'none':
        result['stopReason'] = 'orchestration-exception'
    result['orchestrationError'] = f'{type(exc).__name__}: {exc}'
    (O / 'orchestration-failure.txt').write_text(result['orchestrationError'] + '\n')
    if result['u0'] != 'PASS':
        result['u0'] = 'FAIL'
    if exit_code == 2:
        result['overall'] = 'ORCHESTRATION_FAILURE'
    print(result['orchestrationError'])

try:
    if pre is not None and P.exists() and SROOT.exists():
        required_path = SROOT / '.agents/Directional/Architecture_M3_CP4c0b_Required_Green_Selector.txt'
        non_path = SROOT / '.agents/Directional/Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt'
        archive = P / 'source' / f'source-{SOURCE_SHA}.tar.gz'
        executables = [p.name for p in sorted((P / 'bin').iterdir())]
        post = {
            'package': inventory(P),
            'packageModes': modes(P),
            'source': inventory(SROOT),
            'sourceModes': modes(SROOT),
            'fixtures': inventory(SROOT, 'benchmarks/fixtures'),
            'requiredSelector': sha(required_path),
            'nonGatingSelector': sha(non_path),
            'executables': {x: [sha(P / 'bin' / x), oct(stat.S_IMODE((P / 'bin' / x).stat().st_mode))] for x in executables},
            'packageZip': sha(Z),
            'sourceArchive': sha(archive),
        }
        (O / 'postflight-inventory.json').write_text(json.dumps(post, sort_keys=True, indent=2))
        result['postflight'] = 'PASS' if post == pre else 'FAIL'
        if post != pre:
            result['mutationOccurred'] = True
            result['stopReason'] = 'immutable-postflight-failed'
            exit_code = 4
    else:
        result['postflight'] = 'NOT_AVAILABLE'
except Exception as exc:
    result['postflight'] = 'FAIL'
    result['postflightError'] = f'{type(exc).__name__}: {exc}'
    result['stopReason'] = 'postflight-exception'
    exit_code = 4

if result['overall'] == 'PENDING':
    if exit_code == 0 and result.get('gate') == 'PASS_353_OF_353' and result.get('u3u4') == 'PASS' and result.get('postflight') == 'PASS':
        result['overall'] = 'PASS'
    elif exit_code == 2:
        result['overall'] = 'ORCHESTRATION_FAILURE'
    else:
        result['overall'] = 'VALID_SEMANTIC_RED_OR_STOP'

(O / 'result.json').write_text(json.dumps(result, sort_keys=True, indent=2))
(O / 'gate-exit-code.txt').write_text(str(exit_code) + '\n')
print(json.dumps(result, sort_keys=True))
sys.exit(exit_code)
