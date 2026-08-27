import collections,hashlib,json,os,re,stat,subprocess
from pathlib import Path

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def inv(root,sub='.'):
 b=Path(root)/sub
 return {str(p.relative_to(root)):sha(p) for p in sorted(b.rglob('*')) if p.is_file()}
def parse_fields(line):
 d={}
 for x in line.strip().split(';')[1:]:
  if '=' in x:
   k,v=x.split('=',1); d[k]=v
 return d
def run_one(P,identity,target,stem):
 j=Path(str(stem)+'.json'); l=Path(str(stem)+'.log')
 p=subprocess.run([str(P/'bin'/target),'--gtest_color=no',f'--gtest_filter={identity}',f'--gtest_output=json:{j}'],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 out=p.stdout or ''; l.write_text(out); print(out,end='')
 d=json.loads(j.read_text()) if j.exists() else {}; n=int(d.get('tests',0)); bad=int(d.get('failures',0))+int(d.get('errors',0)); exc='C++ exception with description' in out
 status='ORCHESTRATION_RED' if n!=1 else ('PASS' if p.returncode==0 and bad==0 else 'RED')
 return {'identity':identity,'target':target,'exit':p.returncode,'selected':n,'failures':bad,'status':status,'cppException':exc,'stdout':out}
def route_map(W,ids,diag_id):
 cm=(W/'cmake/DirectionalTests.cmake').read_text(); m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s*(.*?)\)',cm,re.S)
 if not m: raise RuntimeError('producer source set not found')
 sets={'directional_surface_cell_producer_tests':re.findall(r'(?:tests|src/bench)/[^\s\)]+\.cpp',m.group(1)),'directional_surface_cell_authority_kernel_tests':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],'directional_surface_cell_completion_tests':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],'directional_surface_cell_validation_tests':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
 pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',re.S); own=collections.defaultdict(set)
 for target,paths in sets.items():
  for path in paths:
   for suite,name in pat.findall((W/path).read_text(errors='replace')): own[f'{suite}.{name}'].add(target)
 out={}
 for identity in list(ids)+[diag_id]:
  if len(own[identity])!=1: raise RuntimeError(f'identity ownership {identity}: {sorted(own[identity])}')
  out[identity]=next(iter(own[identity]))
 return out
def census_summary(lines):
 expected={'two-ring','four-triangle-fan','sphere_prescribed','torus'}; records=[]; seen=set(); review=False; unexpected=[]
 for line in lines:
  f=parse_fields(line); w=f.get('witness',''); seen.add(w); status=f.get('status','missing'); pop=f.get('population','')
  r={'raw':line,'witness':w,'population':pop,'classification':f.get('classification'),'status':status}
  if status=='reached':
   for k in ('sharedFaceContactCount','properCrossingCount','nonProperCrossingCount','unevaluatedCrossingCount','requiresReview','nodeCount'): r[k]=int(f.get(k,'-1'))
   sm=re.fullmatch(r'\{A=(\d+),B=(\d+),C=(\d+)\}',f.get('siteCounts','')); r['siteCounts']={'A':int(sm.group(1)),'B':int(sm.group(2)),'C':int(sm.group(3))} if sm else None
   r['priorTerminalKinds']=re.findall(r'priorTerminalKind=([^,}]+)',line); r['contactNodeSourceVertices']=[int(x) for x in re.findall(r'contactNode\[\d+\]=\{[^}]*sourceVertex=(\d+)\}',line)]
   hm=re.search(r';eventKindHistogram=\{([^}]*)\}',line); hist={}
   if hm and hm.group(1):
    for part in hm.group(1).split(','):
     k,v=part.split('=',1); hist[k]=int(v)
   r['eventKindHistogram']=hist
   if pop=='included' and (r['nonProperCrossingCount']>0 or r['unevaluatedCrossingCount']>0 or r['requiresReview']!=0): review=True
  elif status=='unreached':
   for k in ('networkError','sourceVertex','traceSteps','traceCombinatorialVisits','traceCombinatorialVisitAllowance'): r[k]=f.get(k)
   if w=='sphere_prescribed':
    if r['networkError']!='TraceCombinatorialRecurrenceExceeded': unexpected.append(f'sphere unexpected networkError={r["networkError"]}')
   elif pop=='included': unexpected.append(f'included witness unexpectedly unreached: {w}')
  else: unexpected.append(f'unexpected status {status}: {w}')
  if w=='four-triangle-fan' and pop!='excluded': unexpected.append('four-triangle-fan not excluded')
  if w in {'two-ring','sphere_prescribed','torus'} and pop!='included': unexpected.append(f'accepted witness not included: {w}')
  records.append(r)
 if seen!=expected: unexpected.append(f'witness set mismatch: {sorted(seen)}')
 return records,review,unexpected
