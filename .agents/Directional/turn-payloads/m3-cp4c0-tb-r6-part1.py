import collections, hashlib, json, os, re, shutil, subprocess, sys, tarfile, time, zipfile
from pathlib import Path

T=Path(os.environ['RUNNER_TEMP']); W=Path(os.environ['GITHUB_WORKSPACE']); repo=os.environ['GITHUB_REPOSITORY']
out=T/'m3-cp4c0-tb-r6-result'; pkg=T/'m3-cp4c0-cb6-package'; z=T/'m3-cp4c0-cb6-package.zip'
shutil.rmtree(out,ignore_errors=True); shutil.rmtree(pkg,ignore_errors=True); out.mkdir(); (out/'identity-results').mkdir(); (out/'supplementals').mkdir(); pkg.mkdir()
AID='9619352525'; ZSHA='b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672'; SRC='8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6'; ASHA='308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093'
SSHA='d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116'; S316='601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c'; S328='cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600'
F3=['ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode','ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus']
G5='ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating'; H1='ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating'; J3='ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating'; T1='ResolvedBranchContinuation.PositionChoosesSmallerExactExitAndFlipsAcrossCrossover'
sha=lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
def inventory(root, sub='.'):
  base=Path(root)/sub; return {str(p.relative_to(root)):sha(p) for p in sorted(base.rglob('*')) if p.is_file()}
def run1(identity,target,stem):
  js=Path(str(stem)+'.json'); lg=Path(str(stem)+'.log'); t=time.monotonic_ns()
  p=subprocess.run([str(pkg/'bin'/target),'--gtest_color=no',f'--gtest_filter={identity}',f'--gtest_output=json:{js}'],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
  lg.write_text(p.stdout or ''); print(p.stdout or '',end=''); d=json.loads(js.read_text()) if js.exists() else {}; sel=int(d.get('tests',0)); fail=int(d.get('failures',0)); err=int(d.get('errors',0)); ms=(time.monotonic_ns()-t)//1_000_000
  status='ORCHESTRATION_RED' if sel!=1 else ('PASS' if p.returncode==0 and fail==0 and err==0 else 'RED')
  return dict(identity=identity,target=target,exit_code=p.returncode,selected=sel,failures=fail,errors=err,elapsed_ms=ms,status=status,log=p.stdout or '')
try:
  with z.open('wb') as f: subprocess.run(['gh','api','--method','GET',f'repos/{repo}/actions/artifacts/{AID}/zip'],stdout=f,check=True)
  assert sha(z)==ZSHA; zipfile.ZipFile(z).extractall(pkg)
  ok=0
  for line in (pkg/'SHA256SUMS').read_text().splitlines():
    h,rel=line.split('  ',1); assert sha(pkg/rel)==h; ok+=1
  assert ok==27 and (pkg/'metadata/source-commit.txt').read_text().strip()==SRC
  assert (pkg/'metadata/build-exit-code.txt').read_text().strip()=='0' and (pkg/'metadata/preflight-exit-code.txt').read_text().strip()=='0'
  b=(pkg/'metadata/command-boundary.txt').read_text(); assert 'runtimeExecution=false' in b and 'turnBoundary=Code+Build-only' in b
  assert all(not p.read_bytes() for p in (pkg/'metadata').glob('source-status-*.txt'))
  arc=pkg/'source'/f'source-{SRC}.tar.gz'; assert sha(arc)==ASHA
  for p in list(W.iterdir()): shutil.rmtree(p) if p.is_dir() else p.unlink()
  with tarfile.open(arc,'r:gz') as tf: tf.extractall(W,filter='data')
  selector=W/'.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt'; ids=[x for x in selector.read_text().splitlines() if x]
  assert len(ids)==338 and len(set(ids))==338 and sha(selector)==SSHA
  assert hashlib.sha256(('\n'.join(ids[:316])+'\n').encode()).hexdigest()==S316 and hashlib.sha256(('\n'.join(ids[:328])+'\n').encode()).hexdigest()==S328
  cm=(W/'cmake/DirectionalTests.cmake').read_text(); m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)',cm,re.S); assert m
  prod=re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp',m.group(1)); targets={'directional_surface_cell_producer_tests':prod,'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
  pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)',re.S); owners=collections.defaultdict(set)
  for target,paths in targets.items():
    for rel in paths:
      for s,n in pat.findall((W/rel).read_text(errors='replace')): owners[f'{s}.{n}'].add(target)
