import csv,hashlib,json,os,pathlib,re,shutil,stat,subprocess,sys
from tb12_r4_spec import *
rt=pathlib.Path(os.environ['RUNNER_TEMP']); root=rt/'tb12-r4'; pkg=root/'package'; src=root/'source'; view=root/'execution-view'; res=rt/'M4-CP-SCALE-TB12-R4-EXEC-result'; raw=res/'raw'; log=rt/'M4-CP-SCALE-TB12-R4-EXEC.log'
for p in [pkg,src,view/'bin',res,raw]: p.mkdir(parents=True,exist_ok=True)
lf=log.open('w'); state={'o':False,'r':False,'p':False}
summary={'artifactId':ART,'compileSource':SRC,'gateA':'0/4','gateB':'0/1','selector':'0/426','firstFailure':None}
def emit(x): print(x,flush=True); print(x,file=lf,flush=True)
def sha(p):
 h=hashlib.sha256();
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(1<<20),b''): h.update(b)
 return h.hexdigest()
def req(x,m):
 if not x: state['o']=True; raise RuntimeError(m)
def census(r,o):
 rows=[]; r=pathlib.Path(r).resolve()
 for p in [r,*sorted(r.rglob('*'),key=lambda x:x.relative_to(r).as_posix())]:
  s=p.lstat(); rel='.' if p==r else p.relative_to(r).as_posix(); mode=format(stat.S_IMODE(s.st_mode),'o')
  if stat.S_ISREG(s.st_mode): kind='file'; d=sha(p); target='-'
  elif stat.S_ISDIR(s.st_mode): kind='directory'; d=target='-'
  elif stat.S_ISLNK(s.st_mode): kind='symlink'; d='-'; target=os.readlink(p)
  else: kind='other'; d=target='-'
  rows.append(f'{rel}\t{kind}\t{mode}\t{s.st_size}\t{d}\t{target}\n')
 pathlib.Path(o).write_text(''.join(rows))
def sh(a,**kw): return subprocess.run(a,check=True,**kw)
try:
 token=os.environ['GH_TOKEN']; repo=os.environ['GITHUB_REPOSITORY']; hdr=['-H',f'Authorization: Bearer {token}','-H','Accept: application/vnd.github+json','-H','X-GitHub-Api-Version: 2022-11-28']
 j=json.loads(subprocess.check_output(['curl','--fail','--silent','--show-error',*hdr,f'https://api.github.com/repos/{repo}/actions/artifacts/{ART}'])); req(j['name']==NAME,'artifact name mismatch'); req(j.get('digest')=='sha256:'+ZIP,'provider digest mismatch')
 z=root/'candidate.zip'; sh(['curl','-L','--fail','--silent','--show-error',*hdr,f'https://api.github.com/repos/{repo}/actions/artifacts/{ART}/zip','-o',str(z)]); req(sha(z)==ZIP,'ZIP SHA mismatch'); sh(['unzip','-q',str(z),'-d',str(pkg)])
 req(sha(pkg/'SHA256SUMS')==MAN,'manifest SHA'); req(sum(1 for _ in open(pkg/'SHA256SUMS'))==28,'manifest count'); sh(['sha256sum','-c','SHA256SUMS'],cwd=pkg,stdout=lf,stderr=subprocess.STDOUT)
 req((pkg/'metadata/source-commit.txt').read_text().strip()==SRC,'source'); req((pkg/'metadata/preflight-exit-code.txt').read_text().strip()=='0' and (pkg/'metadata/build-exit-code.txt').read_text().strip()=='0','compile exits'); req(all((pkg/'metadata'/n).read_text()=='' for n in ['source-status-preconfigure.txt','source-status-before-configure.txt','source-status-after-configure.txt','source-status-after-build.txt','source-status-final.txt']),'source status')
 b=(pkg/'metadata/command-boundary.txt').read_text(); g=(pkg/'metadata/gmp-evidence.txt').read_text()+(pkg/'metadata/CMakeCache.txt').read_text(); req(all(x in b for x in ['runtimeExecution=false','turnBoundary=Code+Build-only','exactArithmeticBackend=GMP']),'boundary'); req('libgmpxx.so' in g and 'libgmp.so' in g and 'DIRECTIONAL_ENABLE_GMP:BOOL=ON' in g,'GMP')
 exes=[p.name for p in (pkg/'bin').iterdir() if p.is_file()]; req(len(exes)==6 and all(stat.S_IMODE((pkg/'bin'/x).stat().st_mode)==0o755 for x in exes),'executable modes'); census(pkg,res/'package-before.tsv')
 tar=pkg/f'source/source-{SRC}.tar.gz'; req(sha(tar)==ST,'source archive'); sh(['tar','-xzf',str(tar),'-C',str(src)]); census(src,res/'source-before.tsv')
 sel=src/'.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt'; data=sel.read_bytes(); req(sha(sel)==SEL and data.endswith(b'\n') and b'\r' not in data,'selector'); ids=[x.decode() for x in data[:-1].split(b'\n')]; req(len(ids)==426 and len(set(ids))==426 and all(ids),'selector rows'); req(hashlib.sha256(b'\n'.join(x.encode() for x in ids[:425])+b'\n').hexdigest()==PFX,'prefix'); req(not list(src.glob('.agents/Directional/*Selector_427*')),'selector427')
 fx=src/'benchmarks/fixtures/milestone-g'; [req(sha(fx/n)==h,'fixture '+n) for n,h in FIX.items()]
 cm=(src/'cmake/DirectionalTests.cmake').read_text(); targets={TG[0]:['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],TG[2]:['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],TG[3]:['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}; m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cm,re.S); req(m is not None,'producer set'); targets[TG[1]]=[x.strip() for x in m.group(1).splitlines() if x.strip().endswith('.cpp')]
 pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)'); owners={}
 for t,fs in targets.items():
  for f in fs:
   for a,n in pat.findall((src/f).read_text(errors='replace')): owners.setdefault(a+'.'+n,[]).append(t)
 om=[]; counts={t:0 for t in TG}
 for i,x in enumerate(ids,1): req(len(owners.get(x,[]))==1,f'owner {i}:{x}'); t=owners[x][0]; counts[t]+=1; om.append((i,x,t))
 req([counts[t] for t in TG]==[30,280,75,41],f'owner census {counts}'); (res/'owner-census.json').write_text(json.dumps(counts,sort_keys=True)+'\n')
 shutil.copytree(pkg/'bin',view/'bin',dirs_exist_ok=True,copy_function=shutil.copy2); os.symlink(src,view/'test-data',target_is_directory=True); census(view,res/'execution-view-before.tsv')
 ledger=[]
 for i,x in enumerate(A,1): ledger.append({'gate':'A','ordinal':i,'identity':x,'binary':TG[0],'status':'UNEXECUTED'})
 ledger.append({'gate':'B','ordinal':1,'identity':B,'binary':TG[1],'status':'UNEXECUTED'})
 for i,x,t in om: ledger.append({'gate':'C','ordinal':i,'identity':x,'binary':t,'status':'UNEXECUTED'})
 def writeledger():
  with open(res/'execution-ledger.tsv','w',newline='') as f:
   w=csv.DictWriter(f,fieldnames=['gate','ordinal','identity','binary','status','exit','selected','passed','skipped','stdout_sha256','stderr_sha256'],delimiter='\t',extrasaction='ignore'); w.writeheader(); w.writerows(ledger)
 writeledger()
 def run(gate,ordn,ident,bin):
  state['r']=True; stem=f'{gate.lower()}-{ordn:03d}'; wd=root/'runtime'/stem; wd.mkdir(parents=True,exist_ok=True); out=raw/(stem+'.stdout'); err=raw/(stem+'.stderr')
  cp=subprocess.run(['timeout','-k','5s','180s',str(view/'bin'/bin),f'--gtest_filter={ident}'],cwd=wd,stdout=subprocess.PIPE,stderr=subprocess.PIPE); out.write_bytes(cp.stdout); err.write_bytes(cp.stderr); txt=cp.stdout.decode(errors='replace'); runs=re.findall(r'^\[ RUN      \] (.+)$',txt,re.M); oks=re.findall(r'^\[       OK \] (.+?)(?: \(|$)',txt,re.M); skips=re.findall(r'^\[  SKIPPED \] (.+?)(?: \(|$)',txt,re.M); req(runs==[ident],f'selection mismatch {gate}:{ordn}:{runs}'); ok=cp.returncode==0 and ident in oks and not skips; rec=next(r for r in ledger if r['gate']==gate and r['ordinal']==ordn); rec.update(status='PASS' if ok else 'RED',exit=cp.returncode,selected=len(runs),passed=len(oks),skipped=len(skips),stdout_sha256=sha(out),stderr_sha256=sha(err)); writeledger(); return ok,rec
 ga=0; gb=0; sc=0
 for i,x in enumerate(A,1):
  ok,r=run('A',i,x,TG[0]); ga+=int(ok)
  if not ok: summary['firstFailure']=r; break
 if ga==4:
  ok,r=run('B',1,B,TG[1]); gb=int(ok)
  if not ok: summary['firstFailure']=r
 if ga==4 and gb==1:
  for i,x,t in om:
   ok,r=run('C',i,x,t); sc+=int(ok)
   if not ok: summary['firstFailure']=r; break
 summary['gateA']=f'{ga}/4'; summary['gateB']=f'{gb}/1'; summary['selector']=f'{sc}/426'; summary['semanticStatus']='GREEN' if ga==4 and gb==1 and sc==426 else 'RED'
 census(pkg,res/'package-after.tsv'); census(src,res/'source-after.tsv'); census(view,res/'execution-view-after.tsv'); req((res/'package-before.tsv').read_bytes()==(res/'package-after.tsv').read_bytes(),'package changed'); req((res/'source-before.tsv').read_bytes()==(res/'source-after.tsv').read_bytes(),'source changed'); req((res/'execution-view-before.tsv').read_bytes()==(res/'execution-view-after.tsv').read_bytes(),'view changed'); [req(sha(fx/n)==h,'post fixture '+n) for n,h in FIX.items()]; state['p']=True
except Exception as e:
 summary['semanticStatus']='ORCHESTRATION_FAILURE'; summary['exception']=repr(e)
finally:
 boundary={'orchestrationFailure':state['o'],'runtimeStarted':state['r'],'postflightComplete':state['p'],'benchmarkExecution':False,'configureExecution':False,'compileExecution':False,'relinkExecution':False,'packageRepair':False,'chmodExecution':False,'sourceTestFixtureSelectorMutation':False,'discoveryListHelpVersionActivity':False}; summary.update(boundary); summary.update({'artifactZipSha256':ZIP,'selectorSha256':SEL,'first425Sha256':PFX,'ownerCensus':[30,280,75,41]}); (res/'summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n'); (res/'execution-boundary.json').write_text(json.dumps(boundary,indent=2,sort_keys=True)+'\n')
 with open(res/'SHA256SUMS','w') as f:
  for p in sorted(x for x in res.rglob('*') if x.is_file() and x.name!='SHA256SUMS'): f.write(f'{sha(p)}  {p.relative_to(res).as_posix()}\n')
 lf.close()
if state['o']: sys.exit(90)
