import collections,hashlib,json,os,re,shutil,stat,subprocess,time
from pathlib import Path
T=Path(os.environ['RUNNER_TEMP']); R=os.environ['GITHUB_REPOSITORY']; RID=int(os.environ['GITHUB_RUN_ID'])
O=T/'m3-cp4c1-tb-r5-result'; P=T/'m3-cp4c1-tb-r5-package'; S=T/'m3-cp4c1-tb-r5-source'; Z=T/'pkg.zip'
for p in (O,P,S): shutil.rmtree(p,ignore_errors=True); p.mkdir(parents=True)
(O/'required').mkdir(); (O/'diagnostics').mkdir()
AID='9675666067'; ASHA='63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17'; SSHA='b1ce8ad65952bd2bd76238f6dfc55523f6a24747'; SARCH='baead768e6f05acc7b09177a1571139262a514056cfc4fa281b8933135b6fc84'
REQSHA='e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa'; NGSH='537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a'; PREF={316:'601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c',346:'20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a',353:'51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5'}
C4='FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing'; C5='FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced'; EXTRA='ResolvedBranchCorrection.TwoRingContactPairingCensusIsPublishedNonGating'; RET=['FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique','FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable']
NG=['GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable','GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable','GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable']
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def inv(root):
 root=Path(root); return {str(p.relative_to(root)):[sha(p),stat.S_IMODE(p.stat().st_mode),p.stat().st_size] for p in sorted(root.rglob('*')) if p.is_file()}
def psha(lines,n): return hashlib.sha256(('\n'.join(lines[:n])+'\n').encode()).hexdigest()
def run(cmd,**kw): return subprocess.run(cmd,check=True,**kw)
def route(root,ids):
 cm=(root/'cmake/DirectionalTests.cmake').read_text(); m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)',cm,re.S); assert m
 tg={'directional_surface_cell_producer_tests':re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp',m.group(1)),'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
 pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',re.S); own=collections.defaultdict(set)
 for t,paths in tg.items():
  for rel in paths:
   for a,b in pat.findall((root/rel).read_text(errors='replace')): own[f'{a}.{b}'].add(t)
 out=[]
 for i,x in enumerate(ids,1):
  if len(own[x])!=1: raise RuntimeError(f'owner cardinality {x} {sorted(own[x])}')
  out.append((i,x,next(iter(own[x]))))
 return out
def one(identity,target,stem):
 j=Path(str(stem)+'.json'); l=Path(str(stem)+'.log'); t=time.monotonic_ns(); q=subprocess.run([str(P/'bin'/target),'--gtest_color=no',f'--gtest_filter={identity}',f'--gtest_output=json:{j}'],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True); ms=(time.monotonic_ns()-t)//1000000; out=q.stdout or ''; l.write_text(out); d=json.loads(j.read_text()) if j.exists() else {}; sel=int(d.get('tests',0)); fail=int(d.get('failures',0))+int(d.get('errors',0)); return {'identity':identity,'target':target,'exit':q.returncode,'selected':sel,'failures':fail,'ms':ms,'status':'ORCHESTRATION_RED' if sel!=1 else ('PASS' if q.returncode==0 and fail==0 else 'RED'),'cppException':'C++ exception with description' in out,'log':out}
