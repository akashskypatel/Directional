import collections,hashlib,json,os,re,shutil,stat,subprocess,sys,time
from pathlib import Path

T=Path(os.environ['RUNNER_TEMP']); W=Path(os.environ['GITHUB_WORKSPACE']); R=os.environ['GITHUB_REPOSITORY']
O=T/'m3-cp4c0-tb-r9-result'; P=T/'package'; Z=T/'package.zip'
for x in (O,P): shutil.rmtree(x,ignore_errors=True); x.mkdir(parents=True)
(O/'identity').mkdir(); (O/'diagnostic').mkdir()

A='9634245265'; H='4ef834465ee8db3110f40f7882cde4a39f94821b6bc0daba3ae0b0e04d7e5629'
S='66325345567106fe7de8560ee2aee5f07ca665de'; AH='4c7a5585fd0627a7e1aa41cf84181d063bf102c3ab94895169ae54dff27f9110'
SH='20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a'
H316='601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c'; H328='cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600'
B='directional_surface_cell_producer_tests'; TIMEOUT_S=60; HISTORICAL_MAX_PASS_MS=16397
T1='ResolvedBranchContinuation.PositionChoosesSmallerExactExitAndFlipsAcrossCrossover'
N5='ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport'
K2='ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating'
TORUS='GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable'; MECH='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def inv(r,sub='.'):
 b=Path(r)/sub; return {str(p.relative_to(r)):sha(p) for p in sorted(b.rglob('*')) if p.is_file()}
def f(s,k):
 m=re.search(r'(?:^|;)'+re.escape(k)+r'=([^;]*)',s); return m.group(1) if m else None

def run(i,t,stem,timeout=TIMEOUT_S):
 j=Path(str(stem)+'.json'); l=Path(str(stem)+'.log'); st=time.monotonic_ns(); timed=False
 try:
  p=subprocess.run([str(P/'bin'/t),'--gtest_color=no',f'--gtest_filter={i}',f'--gtest_output=json:{j}'],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,timeout=timeout)
  out=p.stdout or ''; rc=p.returncode
 except subprocess.TimeoutExpired as e:
  timed=True; out=(e.stdout or '')+(e.stderr or '') if isinstance(e.stdout,str) else ''; rc=124
 l.write_text(out); print(out,end='')
 d=json.loads(j.read_text()) if j.exists() else {}; n=int(d.get('tests',0)); bad=int(d.get('failures',0))+int(d.get('errors',0))
 exc='C++ exception with description' in out
 if timed: z='TIMEOUT'
 elif n!=1: z='ORCHESTRATION_RED'
 else: z='PASS' if rc==0 and bad==0 else 'RED'
 return {'identity':i,'target':t,'exit':rc,'selected':n,'failures':bad,'ms':(time.monotonic_ns()-st)//1000000,'status':z,'timeout':timed,'cppException':exc,'log':out}

try:
 with Z.open('wb') as z: subprocess.run(['gh','api','--method','GET',f'repos/{R}/actions/artifacts/{A}/zip'],stdout=z,check=True)
 assert sha(Z)==H,(sha(Z),H); subprocess.run(['unzip','-q',str(Z),'-d',str(P)],check=True)
 EX=[x.name for x in sorted((P/'bin').iterdir())]; assert len(EX)==6,EX
 M=(P/'SHA256SUMS').read_text().splitlines(); assert len(M)==28,len(M)
 for x in M:
  h,r=x.split('  ',1); assert sha(P/r)==h,(r,sha(P/r),h)
 assert (P/'metadata/source-commit.txt').read_text().strip()==S
 assert (P/'metadata/build-exit-code.txt').read_text().strip()=='0' and (P/'metadata/preflight-exit-code.txt').read_text().strip()=='0'
 b=(P/'metadata/command-boundary.txt').read_text(); assert 'runtimeExecution=false' in b and 'turnBoundary=Code+Build-only' in b and 'exactArithmeticBackend=GMP' in b
 ge=(P/'metadata/gmp-evidence.txt').read_text(); assert 'libgmpxx.so' in ge and 'libgmp.so' in ge
 assert all(not x.read_bytes() for x in (P/'metadata').glob('source-status-*.txt'))
 arc=P/'source'/f'source-{S}.tar.gz'; assert sha(arc)==AH
 modes={x:oct(stat.S_IMODE((P/'bin'/x).stat().st_mode)) for x in EX}; assert all(stat.S_IMODE((P/'bin'/x).stat().st_mode)&0o111 and os.access(P/'bin'/x,os.X_OK) for x in EX)
 for x in list(W.iterdir()): shutil.rmtree(x) if x.is_dir() else x.unlink()
 subprocess.run(['tar','-xzf',str(arc),'-C',str(W)],check=True)
 sel=W/'.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt'; ids=[x for x in sel.read_text().splitlines() if x]
 assert len(ids)==len(set(ids))==346 and sha(sel)==SH
 assert hashlib.sha256(('\n'.join(ids[:316])+'\n').encode()).hexdigest()==H316
 assert hashlib.sha256(('\n'.join(ids[:328])+'\n').encode()).hexdigest()==H328
 cm=(W/'cmake/DirectionalTests.cmake').read_text(); m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)',cm,re.S); assert m
 ts={B:re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp',m.group(1)),'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
 pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',re.S); own=collections.defaultdict(set)
 for t,ps in ts.items():
  for p in ps:
   for a,n in pat.findall((W/p).read_text(errors='replace')): own[f'{a}.{n}'].add(t)
 route=[]
 for n,i in enumerate(ids,1): assert len(own[i])==1,(n,i,own[i]); route.append((n,i,next(iter(own[i]))))
 assert len(own[TORUS])==len(own[MECH])==len(own[N5])==len(own[K2])==1
 pre={'package':inv(P),'source':inv(W),'fixtures':inv(W,'benchmarks/fixtures'),'selector':sha(sel),'exe':{x:[sha(P/'bin'/x),modes[x]] for x in EX}}
 (O/'preflight-inventory.json').write_text(json.dumps(pre,sort_keys=True))
 rows=[]; passed=p316=p328=orch=0; first=0; stop=None; exception_seen=False; timeout_seen=False
 for n,i,t in route:
  r=run(i,t,O/'identity'/f'{n:03d}'); rows.append({k:v for k,v in r.items() if k!='log'}); print(f'gate_identity ordinal={n} status={r["status"]} ms={r["ms"]} identity={i}')
  exception_seen |= r['cppException']; timeout_seen |= r['timeout']
  if r['status']=='PASS': passed+=1; p316+=n<=316; p328+=n<=328
  elif r['status']=='ORCHESTRATION_RED': orch+=1
  if r['status']!='PASS' and not first: first=n
  if n<=316 and r['status']!='PASS': stop='accepted-prefix-red'; break
  if r['timeout']: stop='identity-timeout'; break
  if r['cppException']: stop='escaping-cpp-exception'; break
 gate='ORCHESTRATION_RED' if orch else ('PASS' if len(rows)==346 and passed==346 else 'RED')
 diag={}
 if stop is None:
  for key,i in [('torus',TORUS),('mechanical',MECH),('sphereTyped',N5),('legacyK2',K2)]:
   r=run(i,next(iter(own[i])),O/'diagnostic'/key); diag[key]={k:v for k,v in r.items() if k!='log'}; diag[key]['logText']=r['log']
   exception_seen |= r['cppException']; timeout_seen |= r['timeout']
   if r['timeout']: stop='diagnostic-timeout'; break
   if r['cppException']: stop='escaping-cpp-exception'; break
 t1=next((x['status'] for x in rows if x['identity']==T1),'MISSING')
 tor=diag.get('torus',{}).get('logText',''); mech=diag.get('mechanical',{}).get('logText',''); n5=diag.get('sphereTyped',{}).get('logText',''); k2=diag.get('legacyK2',{}).get('logText','')
 c1='PASS' if p316==316 else 'RED'; c4='PASS' if t1=='PASS' else 'RED'
 tor_ok='fieldAlignedCurveNetwork=true' in tor and 'networkTraceCount=0' in tor
 mech_ok='failedStage=field-transport-atlas' in mech and 'fieldAlignedCurveNetwork=true' not in mech
 c5='PASS' if tor_ok and mech_ok else 'RED'
 n5_ok='m3Cp4c0N5;credit=none;owningMeasure=C4/C5;spherePublishesNetwork=false;' in n5
 k2_line=next((x for x in k2.splitlines() if 'm3Cp4c0K2;' in x),'')
 (O/'legacy-k2-census.txt').write_text(k2_line+'\n' if k2_line else '')
 post={'package':inv(P),'source':inv(W),'fixtures':inv(W,'benchmarks/fixtures'),'selector':sha(sel),'exe':{x:[sha(P/'bin'/x),oct(stat.S_IMODE((P/'bin'/x).stat().st_mode))] for x in EX}}
 immutable=pre==post and sha(Z)==H
 q8='PASS' if c1==c4==c5=='PASS' else 'RED'
 overall='PASS' if gate=='PASS' and q8=='PASS' and not exception_seen and not timeout_seen and immutable and stop is None else 'RED'
 result={'turn':'M3-CP4c-0-TB-R9','packageSource':S,'runId':int(os.environ['GITHUB_RUN_ID']),'packageArtifactId':int(A),'packageSha256':H,'exactArithmeticBackend':'GMP','selector':{'required':346,'executed':len(rows),'passed':passed,'prefix316Passed':p316,'prefix328Passed':p328,'firstRedOrdinal':first,'firstRedIdentity':ids[first-1] if first else 'none','gate':gate},'q8':{'status':q8,'criterion1':c1,'criterion2':'MOVED_TO_CP4c-0b','criterion3':'MOVED_TO_CP4c-0b','criterion4':c4,'criterion5':c5,'torusZeroTraceObserved':tor_ok,'mechanicalFailsA1Observed':mech_ok},'stopReason':stop or 'none','cppExceptionSeen':exception_seen,'timeoutSeen':timeout_seen,'perIdentityTimeoutSeconds':TIMEOUT_S,'historicalMaxPassingIdentityMsTB_R8':HISTORICAL_MAX_PASS_MS,'sphereTypedOutcomeNonGatingObserved':n5_ok,'legacyK2SupportingCensusPublished':bool(k2_line),'legacyK2Authoritative':False,'freshRuntimePerTraceMaxExactWidthAvailable':False,'frozenReviewPrediction':{'candidatePorts':48,'singularityTerminations':42,'recurrenceStops':6,'recurrenceStopStep':65,'maxExactWidthBits':2684},'orchestrationErrors':orch,'archiveExtraction':'unzip+tar/no-repair','mutations':{'package':False,'source':False,'test':False,'fixture':False,'selector':False},'configure':False,'compile':False,'relink':False,'repair':False,'generatedDiscovery':False,'performanceBenchmark':False,'postflight':'PASS' if immutable else 'RED','overall':overall}
 (O/'gate-ledger.json').write_text(json.dumps(rows,sort_keys=True)); (O/'diagnostics.json').write_text(json.dumps({k:{kk:vv for kk,vv in v.items() if kk!='logText'} for k,v in diag.items()},sort_keys=True)); (O/'result.json').write_text(json.dumps(result,sort_keys=True,indent=2)); print(json.dumps(result,sort_keys=True)); sys.exit(0 if overall=='PASS' else 4)
except Exception as e:
 (O/'orchestration-failure.txt').write_text(f'{type(e).__name__}: {e}\n'); raise
