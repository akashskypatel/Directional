import collections, hashlib, json, os, re, shutil, stat, subprocess, sys, time
from fractions import Fraction
from pathlib import Path

T = Path(os.environ['RUNNER_TEMP'])
W = Path(os.environ['GITHUB_WORKSPACE'])
repo = os.environ['GITHUB_REPOSITORY']
out = T / 'm3-cp4c0-tb-r7-result'
pkg = T / 'm3-cp4c0-cb7-package'
z = T / 'm3-cp4c0-cb7-package.zip'
shutil.rmtree(out, ignore_errors=True)
shutil.rmtree(pkg, ignore_errors=True)
out.mkdir()
(out / 'identity-results').mkdir()
(out / 'supplementals').mkdir()
pkg.mkdir()

AID = '9625495708'
ZSHA = 'dc07d4288b9a529ca71c06f96e0277b168d2e5a28c5a9eeba3fdf7341a33237a'
SRC = '077462da156c3e2dfbbc6867fc10d3e4442d853c'
ASHA = '6ecafbc5a5904568780e6518f39b9d4b1336c94e08a53f7fc0c31d8926e26344'
SSHA = 'd588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116'
S316 = '601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c'
S328 = 'cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600'
FIXTURE_HASHES = {
    'benchmarks/fixtures/milestone-g/sphere_prescribed.fieldmeta.json': '40c558cfe4203d3bfadea1876c65314ad8368fc4e53c08b70467156f59bfb024',
    'benchmarks/fixtures/milestone-g/sphere_prescribed.obj': '3973d82788756a514a5bcbe893e2a3e426857876468a204436b256f88f9b7253',
    'benchmarks/fixtures/milestone-g/sphere_prescribed.rawfield': '340f24b1360a520126962bf9013750d8d112a354dc4978a01a3e63a7c3efcd83',
}
EXECUTABLES = [
    'directional_benchmarks',
    'directional_compiled_api_tests',
    'directional_surface_cell_authority_kernel_tests',
    'directional_surface_cell_completion_tests',
    'directional_surface_cell_producer_tests',
    'directional_surface_cell_validation_tests',
]
F3 = [
    'ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode',
    'ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus',
]
G5 = 'ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating'
H1 = 'ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating'
K2 = 'ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating'
J3 = 'ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating'
K3 = 'ResolvedBranchCorrection.VertexFanHolonomyCensusIsPublishedNonGating'
T1 = 'ResolvedBranchContinuation.PositionChoosesSmallerExactExitAndFlipsAcrossCrossover'

sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()

def inventory(root, sub='.'):
    base = Path(root) / sub
    return {str(p.relative_to(root)): sha(p) for p in sorted(base.rglob('*')) if p.is_file()}

def run1(identity, target, stem):
    js = Path(str(stem) + '.json')
    lg = Path(str(stem) + '.log')
    started = time.monotonic_ns()
    p = subprocess.run(
        [str(pkg / 'bin' / target), '--gtest_color=no', f'--gtest_filter={identity}', f'--gtest_output=json:{js}'],
        text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    lg.write_text(p.stdout or '')
    print(p.stdout or '', end='')
    d = json.loads(js.read_text()) if js.exists() else {}
    selected = int(d.get('tests', 0))
    failures = int(d.get('failures', 0))
    errors = int(d.get('errors', 0))
    elapsed_ms = (time.monotonic_ns() - started) // 1_000_000
    status_name = 'ORCHESTRATION_RED' if selected != 1 else ('PASS' if p.returncode == 0 and failures == 0 and errors == 0 else 'RED')
    return dict(identity=identity, target=target, exit_code=p.returncode, selected=selected,
                failures=failures, errors=errors, elapsed_ms=elapsed_ms,
                status=status_name, log=p.stdout or '')

def field(line, name):
    m = re.search(r'(?:^|;)' + re.escape(name) + r'=([^;]*)', line)
    return m.group(1) if m else None

def fraction_values(distribution, field_name='minRatio'):
    return [Fraction(int(a), int(b)) for a, b in re.findall(re.escape(field_name) + r'=(-?\d+)/(\d+)', distribution)]

def fraction_summary(values):
    if not values:
        return {'count': 0}
    s = sorted(values)
    n = len(s)
    median = s[n // 2] if n % 2 else (s[n // 2 - 1] + s[n // 2]) / 2
    return {
        'count': n,
        'minExact': f'{s[0].numerator}/{s[0].denominator}',
        'medianExact': f'{median.numerator}/{median.denominator}',
        'maxExact': f'{s[-1].numerator}/{s[-1].denominator}',
        'minApprox': float(s[0]),
        'medianApprox': float(median),
        'maxApprox': float(s[-1]),
    }

def parse_h1(line):
    witness = field(line, 'witness') or 'unknown'
    dm = re.search(r';disagreeingTangencyDistribution=\[(.*?)\];agreeingTangencyDistribution=\[(.*?)\];status=', line)
    disagree = dm.group(1) if dm else ''
    agree = dm.group(2) if dm else ''
    return {
        'witness': witness,
        'population': field(line, 'population'),
        'classification': field(line, 'classification'),
        'discretizationAssumption': field(line, 'discretizationAssumption'),
        'flowAgreementInterpretation': field(line, 'flowAgreementInterpretation'),
        'disagreementClass': field(line, 'disagreementClass'),
        'pairsChecked': int(field(line, 'pairsChecked') or -1),
        'violations': int(field(line, 'violations') or -1),
        'distinctDisagreements': int(field(line, 'distinctDisagreements') or -1),
        'singularIncidentViolations': int(field(line, 'singularIncidentViolations') or -1),
        'disagreeingMinRatio': fraction_summary(fraction_values(disagree)),
        'agreeingMinRatio': fraction_summary(fraction_values(agree)),
    }

def parse_k2(line):
    first_steps = [int(x) for x in re.findall(r'firstGrazingStep=(\d+)', line)]
    max_consecutive = [int(x) for x in re.findall(r'maxConsecutiveGrazingCrossings=(\d+)', line)]
    grazing_counts = [int(x) for x in re.findall(r'grazingEdgeCount=(\d+)', line)]
    return {
        'traceCount': int(field(line, 'traceCount') or -1),
        'tracesReachingGrazing': int(field(line, 'tracesReachingGrazing') or -1),
        'firstGrazingSteps': first_steps,
        'earliestFirstGrazingStep': min(first_steps) if first_steps else None,
        'latestFirstGrazingStep': max(first_steps) if first_steps else None,
        'totalGrazingEdgeObservations': sum(grazing_counts),
        'maximumConsecutiveGrazingCrossings': max(max_consecutive) if max_consecutive else 0,
        'rawLine': line,
    }

def parse_k3(line):
    return {
        'witness': field(line, 'witness') or 'unknown',
        'population': field(line, 'population'),
        'oracleKind': field(line, 'oracleKind'),
        'usesPrincipalMatchingMinimizer': field(line, 'usesPrincipalMatchingMinimizer'),
        'interiorVertices': int(field(line, 'interiorVertices') or -1),
        'completeFans': int(field(line, 'completeFans') or -1),
        'mismatches': int(field(line, 'mismatches') or -1),
        'rawLine': line,
    }

try:
    with z.open('wb') as f:
        subprocess.run(['gh', 'api', '--method', 'GET', f'repos/{repo}/actions/artifacts/{AID}/zip'], stdout=f, check=True)
    assert sha(z) == ZSHA

    # K6: ordinary unzip is mandatory so executable modes are preserved. No chmod repair is permitted.
    subprocess.run(['unzip', '-q', str(z), '-d', str(pkg)], check=True)
    manifest_lines = (pkg / 'SHA256SUMS').read_text().splitlines()
    assert len(manifest_lines) == 27
    for line in manifest_lines:
        h, rel = line.split('  ', 1)
        assert sha(pkg / rel) == h
    assert (pkg / 'metadata/source-commit.txt').read_text().strip() == SRC
    assert (pkg / 'metadata/build-exit-code.txt').read_text().strip() == '0'
    assert (pkg / 'metadata/preflight-exit-code.txt').read_text().strip() == '0'
    boundary = (pkg / 'metadata/command-boundary.txt').read_text()
    assert 'runtimeExecution=false' in boundary and 'turnBoundary=Code+Build-only' in boundary
    assert all(not p.read_bytes() for p in (pkg / 'metadata').glob('source-status-*.txt'))
    arc = pkg / 'source' / f'source-{SRC}.tar.gz'
    assert sha(arc) == ASHA

    mode_inventory = {}
    for name in EXECUTABLES:
        p = pkg / 'bin' / name
        mode = stat.S_IMODE(p.stat().st_mode)
        mode_inventory[name] = oct(mode)
        assert mode & 0o111, f'executable mode lost for {name}: {oct(mode)}'
        assert os.access(p, os.X_OK), f'not executable after ordinary unzip: {name}'
    (out / 'executable-modes.json').write_text(json.dumps(mode_inventory, indent=2, sort_keys=True))

    for p in list(W.iterdir()):
        shutil.rmtree(p) if p.is_dir() else p.unlink()
    subprocess.run(['tar', '-xzf', str(arc), '-C', str(W)], check=True)

    selector = W / '.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt'
    ids = [x for x in selector.read_text().splitlines() if x]
    assert len(ids) == 338 and len(set(ids)) == 338 and sha(selector) == SSHA
    assert hashlib.sha256(('\n'.join(ids[:316]) + '\n').encode()).hexdigest() == S316
    assert hashlib.sha256(('\n'.join(ids[:328]) + '\n').encode()).hexdigest() == S328
    for rel, expected in FIXTURE_HASHES.items():
        assert sha(W / rel) == expected, rel
    (out / 'sphere-fixture-hashes.json').write_text(json.dumps(FIXTURE_HASHES, indent=2, sort_keys=True))

    cm = (W / 'cmake/DirectionalTests.cmake').read_text()
    m = re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)', cm, re.S)
    assert m
    prod = re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp', m.group(1))
    targets = {
        'directional_surface_cell_producer_tests': prod,
        'directional_surface_cell_authority_kernel_tests': ['tests/FieldTransportAtlasTests.cpp', 'tests/SurfaceCellAuthorityKernelTests.cpp'],
        'directional_surface_cell_completion_tests': ['tests/FlowRepStrandsPhase15Tests.cpp', 'tests/PatchDescriptorMilestoneETests.cpp', 'tests/PureQuadCompletionPhase18Tests.cpp', 'tests/SurfaceArrangementRowIdentityTests.cpp', 'tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
        'directional_surface_cell_validation_tests': ['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp', 'tests/SurfaceMeshOptimizerPhase19Tests.cpp', 'tests/SurfaceMeshOptimizerPhase20Tests.cpp', 'tests/SurfaceMeshOptimizerPhase21Tests.cpp', 'tests/SurfaceMeshOptimizerPhase22Tests.cpp'],
    }
    pat = re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', re.S)
    owners = collections.defaultdict(set)
    for target, paths in targets.items():
        for rel in paths:
            for suite, name in pat.findall((W / rel).read_text(errors='replace')):
                owners[f'{suite}.{name}'].add(target)
    route = []
    for i, identity in enumerate(ids, 1):
        assert len(owners[identity]) == 1, (i, identity, owners[identity])
        route.append((i, identity, next(iter(owners[identity]))))
    for identity in F3 + [G5, H1, K2, J3, K3]:
        assert owners[identity] == {'directional_surface_cell_producer_tests'}, (identity, owners[identity])
    (out / 'route.tsv').write_text(''.join(f'{i}\t{x}\t{t}\n' for i, x, t in route))

    pre_pkg = inventory(pkg)
    pre_src = inventory(W)
    pre_fix = inventory(W, 'benchmarks/fixtures')
    pre_sel = sha(selector)
    pre_exe = {name: sha(pkg / 'bin' / name) for name in EXECUTABLES}

    rows = []
    passed = pre316 = pre328 = 0
    first = 0
    orch = 0
    for i, identity, target in route:
        r = run1(identity, target, out / 'identity-results' / f'{i:03d}')
        rows.append(r)
        print(f'gate_identity ordinal={i} status={r["status"]} identity={identity}')
        if r['status'] == 'PASS':
            passed += 1
            pre316 += i <= 316
            pre328 += i <= 328
        elif r['status'] == 'ORCHESTRATION_RED':
            orch += 1
        if r['status'] != 'PASS' and not first:
            first = i
    gate = 'ORCHESTRATION_RED' if orch else ('PASS' if passed == 338 else 'RED')

    f3 = []
    for identity in F3:
        r = run1(identity, 'directional_surface_cell_producer_tests', out / 'supplementals' / identity.replace('.', '_'))
        f3.append(r)
        orch += r['status'] == 'ORCHESTRATION_RED'
    qpre = orch

    g = run1(G5, 'directional_surface_cell_producer_tests', out / 'g5')
    h = run1(H1, 'directional_surface_cell_producer_tests', out / 'h1')
    k2 = run1(K2, 'directional_surface_cell_producer_tests', out / 'k2')
    j = run1(J3, 'directional_surface_cell_producer_tests', out / 'j3')
    k3 = run1(K3, 'directional_surface_cell_producer_tests', out / 'k3')
    for r in (g, h, k2, j, k3):
        orch += r['status'] == 'ORCHESTRATION_RED'

    gl = [x for x in g['log'].splitlines() if x.startswith('m3Cp4c0G5')]
    hl = [x for x in h['log'].splitlines() if x.startswith('m3Cp4c0H1')]
    k2l = [x for x in k2['log'].splitlines() if x.startswith('m3Cp4c0K2')]
    jl = [x for x in j['log'].splitlines() if x.startswith('m3Cp4c0J3')]
    k3l = [x for x in k3['log'].splitlines() if x.startswith('m3Cp4c0K3Holonomy')]
    expected_lines = [(g, gl, 1), (h, hl, 4), (k2, k2l, 1), (j, jl, 4), (k3, k3l, 3)]
    for record, lines, expected in expected_lines:
        if len(lines) != expected:
            record['status'] = 'ORCHESTRATION_RED'
            orch += 1

    (out / 'g5-outcome.txt').write_text('\n'.join(gl) + '\n')
    (out / 'h1-census.txt').write_text('\n'.join(hl) + '\n')
    (out / 'k2-census.txt').write_text('\n'.join(k2l) + '\n')
    (out / 'j3-census.txt').write_text('\n'.join(jl) + '\n')
    (out / 'k3-holonomy.txt').write_text('\n'.join(k3l) + '\n')

    h1_summary = [parse_h1(x) for x in hl]
    k2_summary = parse_k2(k2l[0]) if len(k2l) == 1 else {'parseStatus': 'unavailable'}
    j3_summary = [{
        'witness': field(x, 'witness'),
        'population': field(x, 'population'),
        'oracleKind': field(x, 'oracleKind'),
        'canDetectMatchingAliasing': field(x, 'canDetectMatchingAliasing'),
        'edgesChecked': int(field(x, 'edgesChecked') or -1),
        'agreements': int(field(x, 'agreements') or -1),
        'disagreements': int(field(x, 'disagreements') or -1),
        'rawLine': x,
    } for x in jl]
    k3_summary = [parse_k3(x) for x in k3l]
    (out / 'h1-summary.json').write_text(json.dumps(h1_summary, indent=2, sort_keys=True))
    (out / 'k2-summary.json').write_text(json.dumps(k2_summary, indent=2, sort_keys=True))
    (out / 'j3-summary.json').write_text(json.dumps(j3_summary, indent=2, sort_keys=True))
    (out / 'k3-summary.json').write_text(json.dumps(k3_summary, indent=2, sort_keys=True))

    j3_contract_ok = len(jl) == 4 and all(field(x, 'oracleKind') == 'principal-matching-implementation-cross-check' and field(x, 'canDetectMatchingAliasing') == 'false' for x in jl)
    k3_contract_ok = len(k3l) == 3 and all(field(x, 'oracleKind') == 'vertex-fan-holonomy' and field(x, 'usesPrincipalMatchingMinimizer') == 'false' for x in k3l)
    k3_complete = k3_contract_ok and all(x['interiorVertices'] == x['completeFans'] for x in k3_summary)
    k3_mismatches = sum(max(0, x['mismatches']) for x in k3_summary) if k3_summary else -1

    t1_status = next((r['status'] for r in rows if r['identity'] == T1), 'MISSING')
    c1 = 'PASS' if pre316 == 316 else 'RED'
    c4 = 'PASS' if t1_status == 'PASS' else 'RED'
    c2 = c3 = 'NOT_EVALUABLE'
    qcred = False
    qs = 'NOT_CREDITABLE'
    qr = 'precondition_not_green'
    if gate == 'PASS' and sum(r['status'] == 'PASS' for r in f3) == 2 and qpre == 0:
        qcred = True
        qs = 'RED'
        c2 = 'RED'
        qr = 'criterion2_sphere_network_not_published'
        go = gl[0] if gl else ''
        if not go:
            qs = 'ORCHESTRATION_RED'
            qr = 'g5_outcome_unavailable'
        elif ';fieldAlignedCurveNetwork=true;' in go:
            mt = re.search(r';traceCount=(\d+)', go)
            mi = re.search(r'TraceIntersection=(\d+)', go)
            n = int(mt.group(1)) if mt else -1
            ni = int(mi.group(1)) if mi else -1
            c2 = 'PASS' if n == 24 else 'RED'
            qr = f'criterion2_sphere_trace_count_{n}_expected_24'
            if c2 == 'PASS':
                c3 = 'PASS' if ni > 0 else 'RED'
                qr = 'criterion3_sphere_terminal_trace_intersection_missing' if c3 == 'RED' else qr
            if c2 == 'PASS' and c3 == 'PASS' and c4 == 'PASS':
                qs = 'PASS'
                qr = 'criteria1_to5_satisfied_with_criterion5_carried_unchanged'
            elif c2 == 'PASS' and c4 != 'PASS':
                qr = 'criterion4_frozen_crossover_identity_not_green'

    post_pkg = inventory(pkg)
    post_src = inventory(W)
    post_fix = inventory(W, 'benchmarks/fixtures')
    post_exe = {name: sha(pkg / 'bin' / name) for name in EXECUTABLES}
    post_modes = {name: oct(stat.S_IMODE((pkg / 'bin' / name).stat().st_mode)) for name in EXECUTABLES}
    assert pre_pkg == post_pkg and pre_src == post_src and pre_fix == post_fix
    assert pre_sel == sha(selector) and pre_exe == post_exe and mode_inventory == post_modes and sha(z) == ZSHA
    for rel, expected in FIXTURE_HASHES.items():
        assert sha(W / rel) == expected

    result = {
        'turn': 'M3-CP4c-0-TB-R7',
        'semanticSource': SRC,
        'workflowControlSha': os.environ['GITHUB_SHA'],
        'runId': int(os.environ['GITHUB_RUN_ID']),
        'packageArtifactId': int(AID),
        'packageSha256': ZSHA,
        'sourceArchiveSha256': ASHA,
        'selector': {
            'required': 338, 'executed': 338, 'passed': passed, 'sha256': SSHA,
            'first316Sha256': S316, 'first328Sha256': S328,
            'prefix316Passed': pre316, 'prefix328Passed': pre328,
            'firstRedOrdinal': first, 'firstRedIdentity': ids[first - 1] if first else 'none',
            'gate': gate,
        },
        'supplementalF3': {'executed': 2, 'passed': sum(r['status'] == 'PASS' for r in f3), 'records': f3},
        'g5': {'credit': 'none', 'status': g['status'], 'outcome': gl},
        'k1_h1': {'credit': 'none', 'status': h['status'], 'witnesses': h1_summary},
        'k2': {'credit': 'none', 'status': k2['status'], 'summary': k2_summary},
        'j3': {'credit': 'none', 'status': j['status'], 'contractLabelsValid': j3_contract_ok, 'witnesses': j3_summary},
        'k3': {'credit': 'none', 'status': k3['status'], 'contractLabelsValid': k3_contract_ok, 'completeFanCoverage': k3_complete, 'mismatchCount': k3_mismatches, 'witnesses': k3_summary},
        'q8': {'creditable': qcred, 'status': qs, 'reason': qr, 'criterion1': c1, 'criterion2': c2, 'criterion3': c3, 'criterion4': c4, 'criterion5': 'CARRIED_UNCHANGED_NOT_RERUN'},
        'orchestrationErrors': orch,
        'freshProcesses': 345,
        'archiveExtraction': {'githubArtifact': 'unzip', 'sourceArchive': 'tar', 'permissionRepairAttempted': False, 'executableModes': mode_inventory},
        'packageMutation': False, 'sourceMutation': False, 'testMutation': False, 'fixtureMutation': False, 'selectorMutation': False,
        'configure': False, 'compile': False, 'relink': False, 'repair': False, 'generatedDiscovery': False, 'performanceBenchmark': False,
        'postflight': 'PASS',
    }
    (out / 'gate-ledger.json').write_text(json.dumps(rows, indent=2))
    (out / 'result.json').write_text(json.dumps(result, indent=2, sort_keys=True))
    print(json.dumps(result, indent=2, sort_keys=True))
    sys.exit(5 if orch else 0)
except Exception as e:
    (out / 'orchestration-failure.txt').write_text(f'{type(e).__name__}: {e}\n')
    raise
