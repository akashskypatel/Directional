import collections,hashlib,json,os,re,shutil,stat,subprocess,sys,time
from pathlib import Path
T=Path(os.environ['RUNNER_TEMP']); W=Path(os.environ['GITHUB_WORKSPACE']); R=os.environ['GITHUB_REPOSITORY']; O=T/'m3-cp4c0-tb-r8-result'; P=T/'cb8'; Z=T/'cb8.zip'
for x in (O,P): shutil.rmtree(x,ignore_errors=True); x.mkdir()
(O/'identity').mkdir(); (O/'supp').mkdir()
A='9628445643'; H='869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6'; S='19ba8e9c5e58f9c33c14b309841165d3f0401db5'; AH='98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d'; SH='63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09'; H316='601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c'; H328='cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600'
B='directional_surface_cell_producer_tests'
F3=['ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode','ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus']
Q={'l2':'ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating','l5':'ResolvedBranchCorrection.GrazingEdgeTraceMultiplicityIsPublishedNonGating','k2':'ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating','g5':'ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating','j3':'ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating','k3':'ResolvedBranchCorrection.VertexFanHolonomyCensusIsPublishedNonGating'}; T1='ResolvedBranchContinuation.PositionChoosesSmallerExactExitAndFlipsAcrossCrossover'
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def inv(r,sub='.'):
 b=Path(r)/sub; return {str(p.relative_to(r)):sha(p) for p in sorted(b.rglob('*')) if p.is_file()}
def f(s,k):
 m=re.search(r'(?:^|;)'+re.escape(k)+r'=([^;]*)',s); return m.group(1) if m else None
def run(i,t,stem):
 j=Path(str(stem)+'.json'); l=Path(str(stem)+'.log'); st=time.monotonic_ns(); p=subprocess.run([str(P/'bin'/t),'--gtest_color=no',f'--gtest_filter={i}',f'--gtest_output=json:{j}'],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT); l.write_text(p.stdout or ''); print(p.stdout or '',end=''); d=json.loads(j.read_text()) if j.exists() else {}; n=int(d.get('tests',0)); bad=int(d.get('failures',0))+int(d.get('errors',0)); z='ORCHESTRATION_RED' if n!=1 else ('PASS' if p.returncode==0 and bad==0 else 'RED'); return {'identity':i,'target':t,'exit':p.returncode,'selected':n,'failures':bad,'ms':(time.monotonic_ns()-st)//1000000,'status':z,'log':p.stdout or ''}
def ls(r,p): return [x for x in r['log'].splitlines() if x.startswith(p)]
def sm(a,k,p=None): return sum(int(f(x,k) or 0) for x in a if p is None or f(x,'population')==p)
try:
 with Z.open('wb') as z: subprocess.run(['gh','api','--method','GET',f'repos/{R}/actions/artifacts/{A}/zip'],stdout=z,check=True)
 assert sha(Z)==H; subprocess.run(['unzip','-q',str(Z),'-d',str(P)],check=True); EX=[x.name for x in sorted((P/'bin').iterdir())]; assert len(EX)==6; M=(P/'SHA256SUMS').read_text().splitlines(); assert len(M)==27
 for x in M: h,r=x.split('  ',1); assert sha(P/r)==h
 assert (P/'metadata/source-commit.txt').read_text().strip()==S and (P/'metadata/build-exit-code.txt').read_text().strip()=='0' and (P/'metadata/preflight-exit-code.txt').read_text().strip()=='0'; b=(P/'metadata/command-boundary.txt').read_text(); assert 'runtimeExecution=false' in b and 'turnBoundary=Code+Build-only' in b; assert all(not x.read_bytes() for x in (P/'metadata').glob('source-status-*.txt'))
 arc=P/'source'/f'source-{S}.tar.gz'; assert sha(arc)==AH; modes={x:oct(stat.S_IMODE((P/'bin'/x).stat().st_mode)) for x in EX}; assert all(stat.S_IMODE((P/'bin'/x).stat().st_mode)&0o111 and os.access(P/'bin'/x,os.X_OK) for x in EX)
 for x in list(W.iterdir()): shutil.rmtree(x) if x.is_dir() else x.unlink()
 subprocess.run(['tar','-xzf',str(arc),'-C',str(W)],check=True); sel=W/'.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt'; ids=[x for x in sel.read_text().splitlines() if x]; assert len(ids)==len(set(ids))==343 and sha(sel)==SH; assert hashlib.sha256(('\n'.join(ids[:316])+'\n').encode()).hexdigest()==H316 and hashlib.sha256(('\n'.join(ids[:328])+'\n').encode()).hexdigest()==H328
 cm=(W/'cmake/DirectionalTests.cmake').read_text(); m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)',cm,re.S); assert m
 ts={B:re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp',m.group(1)),'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}; pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',re.S); own=collections.defaultdict(set)
 for t,ps in ts.items():
  for p in ps:
   for a,n in pat.findall((W/p).read_text(errors='replace')): own[f'{a}.{n}'].add(t)
 route=[]
 for n,i in enumerate(ids,1): assert len(own[i])==1,(n,i,own[i]); route.append((n,i,next(iter(own[i]))))
 pre={'package':inv(P),'source':inv(W),'fixtures':inv(W,'benchmarks/fixtures'),'selector':sha(sel),'exe':{x:[sha(P/'bin'/x),modes[x]] for x in EX}}; (O/'preflight-inventory.json').write_text(json.dumps(pre,sort_keys=True))
 rows=[]; passed=p316=p328=orch=first=0
 for n,i,t in route:
  r=run(i,t,O/'identity'/f'{n:03d}'); rows.append({k:v for k,v in r.items() if k!='log'}); print(f'gate_identity ordinal={n} status={r["status"]} identity={i}')
  if r['status']=='PASS': passed+=1; p316+=n<=316; p328+=n<=328
  elif r['status']=='ORCHESTRATION_RED': orch+=1
  if r['status']!='PASS' and not first: first=n
 gate='ORCHESTRATION_RED' if orch else ('PASS' if passed==343 else 'RED'); f3=[]
 for i in F3:
  r=run(i,B,O/'supp'/i.replace('.','_')); f3.append({k:v for k,v in r.items() if k!='log'}); orch+=r['status']=='ORCHESTRATION_RED'
 rr={k:run(i,B,O/k) for k,i in Q.items()}; orch+=sum(r['status']=='ORCHESTRATION_RED' for r in rr.values()); pf={'l2':'m3Cp4c0L2','l5':'m3Cp4c0L5','k2':'m3Cp4c0K2','g5':'m3Cp4c0G5','j3':'m3Cp4c0J3','k3':'m3Cp4c0K3Holonomy'}; raw={k:ls(rr[k],p) for k,p in pf.items()}; exp={'l2':4,'l5':4,'k2':1,'g5':1,'j3':4,'k3':3}
 for k,n in exp.items():
  if len(raw[k])!=n: orch+=1; rr[k]['status']='ORCHESTRATION_RED'
  (O/f'{k}-census.txt').write_text('\n'.join(raw[k])+'\n')
 l2=[{'w':f(x,'witness'),'p':f(x,'population'),'cfg':int(f(x,'distinctGrazingConfigurations') or -1),'edges':int(f(x,'distinctGrazingEdges') or -1),'sign':int(f(x,'signDisagreements') or -1),'zero':int(f(x,'zeroRates') or -1)} for x in raw['l2']]; l5=[{'w':f(x,'witness'),'p':f(x,'population'),'traces':int(f(x,'candidateTraceCount') or -1),'edges':int(f(x,'grazingEdgesReached') or -1),'max':int(f(x,'maxTracesPerGrazingEdge') or -1)} for x in raw['l5']]; kl=raw['k2'][0] if len(raw['k2'])==1 else ''; tr=re.findall(r';trace\[\d+\]=\{([^}]*)\}',kl); g=raw['g5'][0] if len(raw['g5'])==1 else ''; j=[x for x in raw['j3'] if f(x,'population')=='included']; k=raw['k3']; ti=re.search(r'TraceIntersection=(\d+)',g)
 d={'l2':l2,'l5':l5,'k2':{'traceCount':int(f(kl,'traceCount') or -1),'max':int(f(kl,'maxTracesPerGrazingEdge') or -1),'allMulti':bool(tr) and all(len(re.search(r'traversedEdges=\[([^]]*)\]',x).group(1).split(','))>1 for x in tr),'v0Transit':any('sourceVertex=0' in x and 'firstTransitStep=7' in x and '6-8' in x and 'terminalKind=SingularityTermination' in x and 'terminalVertex=8' in x for x in tr)},'g5':{'network':';fieldAlignedCurveNetwork=true;' in g,'traces':int(f(g,'traceCount') or -1),'intersections':int(ti.group(1)) if ti else -1},'j3':[sm(j,'edgesChecked'),sm(j,'agreements'),sm(j,'disagreements')],'k3':[sm(k,'interiorVertices'),sm(k,'completeFans'),sm(k,'mismatches')]}; (O/'diagnostic-summary.json').write_text(json.dumps(d,sort_keys=True))
 t1=next((x['status'] for x in rows if x['identity']==T1),'MISSING'); fpass=sum(x['status']=='PASS' for x in f3); cred=gate=='PASS' and fpass==2 and orch==0; c=['PASS' if p316==316 else 'RED','PASS' if d['g5']['network'] and d['g5']['traces']==24 else 'RED','PASS' if d['g5']['intersections']>0 else 'RED','PASS' if t1=='PASS' else 'RED']; qs='NOT_CREDITABLE' if not cred else ('PASS' if all(x=='PASS' for x in c) else 'RED'); post={'package':inv(P),'source':inv(W),'fixtures':inv(W,'benchmarks/fixtures'),'selector':sha(sel),'exe':{x:[sha(P/'bin'/x),oct(stat.S_IMODE((P/'bin'/x).stat().st_mode))] for x in EX}}; assert pre==post and sha(Z)==H
 res={'turn':'M3-CP4c-0-TB-R8','semanticSource':S,'runId':int(os.environ['GITHUB_RUN_ID']),'packageArtifactId':int(A),'packageSha256':H,'selector':{'required':343,'passed':passed,'prefix316Passed':p316,'prefix328Passed':p328,'firstRedOrdinal':first,'firstRedIdentity':ids[first-1] if first else 'none','gate':gate},'F3Passed':fpass,'q8':{'creditable':cred,'status':qs,'criterion1':c[0],'criterion2':c[1],'criterion3':c[2],'criterion4':c[3],'criterion5':'CARRIED_ACCEPTED_GREEN'},'orchestrationErrors':orch,'archiveExtraction':'unzip+tar/no-repair','mutations':{'package':False,'source':False,'test':False,'fixture':False,'selector':False},'configure':False,'compile':False,'relink':False,'repair':False,'generatedDiscovery':False,'performanceBenchmark':False,'postflight':'PASS'}; (O/'gate-ledger.json').write_text(json.dumps(rows)); (O/'result.json').write_text(json.dumps(res,sort_keys=True)); print(json.dumps(res,sort_keys=True)); sys.exit(5 if orch else 0)
except Exception as e: (O/'orchestration-failure.txt').write_text(f'{type(e).__name__}: {e}\n'); raise
