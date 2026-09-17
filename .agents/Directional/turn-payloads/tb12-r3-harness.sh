#!/usr/bin/env bash
set -euo pipefail
: "${GITHUB_REPOSITORY:?}" "${GITHUB_RUN_ID:?}" "${GH_TOKEN:?}" "${RUNNER_TEMP:?}"
python3 - <<'PY'
import csv,hashlib,json,os,pathlib,re,stat,subprocess,sys
ART=10523132151
NAME='m4-cp-scale-cb16-result-35283852353'
ZIP='2962e2c0e4ea6dc9294d159c19c78543ddf173b5ff342436c9e89e26b4410f73'
SRC_SHA='a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9'
MAN='61bf5fcabfb8a41f2de32b0ea7e1b3059579ecdd5ac07862cb657c46eedd3db5'
SRC_TAR='4be61bb45a1f925c4cff0cf5b6cc0b263948417b6271c43a919808f5c5133e99'
SEL_SHA='41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114'
PFX_SHA='e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b'
AK_SHA='78fd5072420e5fa2b92c9d86aacf989cb2718c48e2f66550e14602f083efdb27'
PR_SHA='18a24349093397ac8ea7bd3074e98defda55a26bf602c359fa2716421da9d6ee'
FIX={'genus_two.obj':'c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3','genus_two.rawfield':'7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e','genus_two.fixturemeta.json':'22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76'}
A=['FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents','FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence','FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper','FieldTransportAtlas.BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport']
B='M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology'
root=pathlib.Path(os.environ['RUNNER_TEMP'])/'m4-cp-scale-tb12-r3'; pkg=root/'package'; src=root/'source'; view=root/'execution-view'; res=pathlib.Path(os.environ['RUNNER_TEMP'])/'m4-cp-scale-tb12-r3-result'; raw=res/'raw'; log=pathlib.Path(os.environ['RUNNER_TEMP'])/'m4-cp-scale-tb12-r3.log'
for p in (pkg,src,view/'bin',res,raw): p.mkdir(parents=True,exist_ok=True)
lf=log.open('w',encoding='utf-8')
def emit(s): print(s,flush=True); print(s,file=lf,flush=True)
def sh(cmd,**kw): emit('$ '+' '.join(map(str,cmd))); return subprocess.run(cmd,check=True,**kw)
def fail(s):
 state['orchestrationFailure']=True; emit('ORCHESTRATION_FAILURE: '+s); raise RuntimeError(s)
sys.path.insert(0,str(pathlib.Path(os.environ['GITHUB_WORKSPACE'])/'.agents/Directional/turn-payloads'))
from tb12_r3_util import sha,census,TG as tg
def req(c,m):
 if not c: fail(m)
state={'runtimeStarted':False,'postflightComplete':False,'orchestrationFailure':False,'configureExecution':False,'compileExecution':False,'relinkExecution':False,'codeGeneration':False,'chmodExecution':False,'packageRepair':False,'sourceTestFixtureMutation':False,'selectorMutation':False,'benchmarkExecution':False,'discoveryListHelpVersionActivity':False}
summary={'artifactId':ART,'compileSource':SRC_SHA,'gateA':[],'gateB':None,'selectorExecuted':0,'selectorPass':0,'firstFailure':None}
try:
 token=os.environ['GH_TOKEN']; repo=os.environ['GITHUB_REPOSITORY']; hdr=['-H',f'Authorization: Bearer {token}','-H','Accept: application/vnd.github+json','-H','X-GitHub-Api-Version: 2022-11-28']
 meta=subprocess.check_output(['curl','--fail','--silent','--show-error',*hdr,f'https://api.github.com/repos/{repo}/actions/artifacts/{ART}']); j=json.loads(meta); req(j['name']==NAME,'artifact name mismatch'); req(j.get('digest')=='sha256:'+ZIP,'provider digest mismatch')
 z=root/'candidate.zip'; sh(['curl','-L','--fail','--silent','--show-error',*hdr,f'https://api.github.com/repos/{repo}/actions/artifacts/{ART}/zip','-o',str(z)]); req(sha(z)==ZIP,'ZIP SHA mismatch')
 sh(['unzip','-q',str(z),'-d',str(pkg)]); req(sha(pkg/'SHA256SUMS')==MAN,'manifest SHA mismatch'); req(sum(1 for _ in open(pkg/'SHA256SUMS'))==28,'manifest count != 28'); sh(['sha256sum','-c','SHA256SUMS'],cwd=pkg,stdout=lf,stderr=subprocess.STDOUT)
 req((pkg/'metadata/source-commit.txt').read_text().strip()==SRC_SHA,'source commit mismatch'); req((pkg/'metadata/preflight-exit-code.txt').read_text().strip()=='0','preflight exit'); req((pkg/'metadata/build-exit-code.txt').read_text().strip()=='0','build exit')
 for n in ['source-status-preconfigure.txt','source-status-before-configure.txt','source-status-after-configure.txt','source-status-after-build.txt','source-status-final.txt']: req((pkg/'metadata'/n).read_text()=='' ,f'nonempty {n}')
 bnd=(pkg/'metadata/command-boundary.txt').read_text(); gmp=(pkg/'metadata/gmp-evidence.txt').read_text(); req(all(x in bnd for x in ['runtimeExecution=false','turnBoundary=Code+Build-only','exactArithmeticBackend=GMP']),'command boundary'); req('libgmpxx.so' in gmp and 'libgmp.so' in gmp,'GMP/GMPXX evidence')
 ak=pkg/'bin/directional_surface_cell_authority_kernel_tests'; pr=pkg/'bin/directional_surface_cell_producer_tests'; req(sha(ak)==AK_SHA and stat.S_IMODE(ak.stat().st_mode)==0o755,'authority kernel identity/mode'); req(sha(pr)==PR_SHA and stat.S_IMODE(pr.stat().st_mode)==0o755,'producer identity/mode')
 census(pkg,res/'package-before.tsv'); tar=pkg/f'source/source-{SRC_SHA}.tar.gz'; req(sha(tar)==SRC_TAR,'source archive SHA'); sh(['tar','-xzf',str(tar),'-C',str(src)]); census(src,res/'source-before.tsv')
 sel=src/'.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt'; data=sel.read_bytes(); req(sha(sel)==SEL_SHA and b'\r' not in data and data.endswith(b'\n'),'selector bytes'); lines=data[:-1].split(b'\n'); req(len(lines)==426 and len(set(lines))==426 and all(lines),'selector rows/unique'); req(hashlib.sha256(b'\n'.join(lines[:425])+b'\n').hexdigest()==PFX_SHA,'first425 SHA'); req(not list(src.glob('.agents/Directional/*Selector_427*')),'selector427 exists')
 fx=src/'benchmarks/fixtures/milestone-g'; [req(sha(fx/n)==h,f'fixture SHA {n}') for n,h in FIX.items()]; census(src/'benchmarks/fixtures',res/'fixtures-before.tsv')
 helper=pathlib.Path(os.environ['GITHUB_WORKSPACE'])/'.agents/Directional/turn-payloads/tb12-r3-owner-map.py'; sh(['python3',str(helper),str(src),str(sel),str(res/'owner-map.tsv')],stdout=lf,stderr=subprocess.STDOUT)
 om=[]; counts={t:0 for t in tg}
 with open(res/'owner-map.tsv') as f:
  for r in csv.DictReader(f,delimiter='\t'): om.append((int(r['ordinal']),r['identity'],r['binary'])); counts[r['binary']]+=1
 req([counts[x] for x in tg]==[30,280,75,41],f'owner census {counts}')
 for t in tg: req(os.access(pkg/'bin'/t,os.X_OK),f'owner executable {t}')
 for t in tg: os.link(pkg/'bin'/t,view/'bin'/t)
 os.symlink(src,view/'test-data',target_is_directory=True); req((view/'test-data/benchmarks/fixtures').is_dir(),'execution fixture root'); census(view,res/'execution-view-before.tsv')
 ledger={x:{'ordinal':i,'identity':x,'binary':t,'phase':'selector','status':'UNEXECUTED'} for i,x,t in om}
 def run(identity,binary,phase,ordinal):
  state['runtimeStarted']=True; d=raw/phase; d.mkdir(exist_ok=True); pth=d/f'{ordinal:03d}.log'; cp=subprocess.run([str(view/'bin'/binary),f'--gtest_filter={identity}'],cwd=root,stdout=subprocess.PIPE,stderr=subprocess.STDOUT); out=cp.stdout; pth.write_bytes(out); txt=out.decode(errors='replace'); runs=re.findall(r'^\[ RUN      \] (.+)$',txt,re.M); oks=re.findall(r'^\[       OK \] (.+?)(?: \(|$)',txt,re.M); skips=re.findall(r'^\[  SKIPPED \] (.+?)(?: \(|$)',txt,re.M); ok=cp.returncode==0 and runs==[identity] and identity in oks and not skips
  rec={'ordinal':ordinal,'identity':identity,'binary':binary,'phase':phase,'exit':cp.returncode,'selected':len(runs),'executed':len(runs),'status':'PASS' if ok else 'RED','raw':str(pth.relative_to(res)),'rawSha256':sha(pth)}; emit(json.dumps(rec,sort_keys=True)); return rec,ok
 gate_ok=True
 for k,x in enumerate(A,1):
  r,ok=run(x,tg[0],'gate-a',k); summary['gateA'].append(r); gate_ok &= ok
  if not ok: summary['firstFailure']=summary['firstFailure'] or r; break
 if gate_ok:
  r,ok=run(B,tg[1],'gate-b',1); summary['gateB']=r; gate_ok=ok
  if not ok: summary['firstFailure']=r
 if gate_ok:
  for i,x,t in om:
   r,ok=run(x,t,'selector',i); ledger[x]=r; summary['selectorExecuted']+=1; summary['selectorPass']+=int(ok)
   if not ok: summary['firstFailure']=summary['firstFailure'] or r
  gate_ok = summary['selectorPass']==426
 with open(res/'selector-ledger.tsv','w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=['ordinal','identity','binary','phase','status','exit','selected','executed','raw','rawSha256'],delimiter='\t',extrasaction='ignore'); w.writeheader(); [w.writerow(ledger[x]) for x in ids]
 sh(['sha256sum','-c','SHA256SUMS'],cwd=pkg,stdout=lf,stderr=subprocess.STDOUT); census(pkg,res/'package-after.tsv'); census(src,res/'source-after.tsv'); census(src/'benchmarks/fixtures',res/'fixtures-after.tsv'); census(view,res/'execution-view-after.tsv')
 for n in ['package','source','fixtures','execution-view']: req((res/f'{n}-before.tsv').read_bytes()==(res/f'{n}-after.tsv').read_bytes(),f'postflight census {n}')
 req(sha(tar)==SRC_TAR and sha(sel)==SEL_SHA and hashlib.sha256(b'\n'.join(lines[:425])+b'\n').hexdigest()==PFX_SHA,'postflight source/selector'); req(sha(ak)==AK_SHA and sha(pr)==PR_SHA and stat.S_IMODE(ak.stat().st_mode)==0o755 and stat.S_IMODE(pr.stat().st_mode)==0o755,'postflight executables'); [req(sha(fx/n)==h,f'postflight fixture {n}') for n,h in FIX.items()]
 state['postflightComplete']=True; summary['semanticStatus']='GREEN' if gate_ok else 'RED'; summary['gateAComplete']=len(summary['gateA'])==4; summary['gateBComplete']=summary['gateB'] is not None; summary['selectorComplete']=summary['selectorExecuted']==426
except Exception as e:
 summary['semanticStatus']='ORCHESTRATION_FAILURE'; summary['exception']=repr(e); emit(repr(e))
finally:
 summary.update(state); summary['artifactZipSha256']=ZIP; summary['selectorSha256']=SEL_SHA; summary['first425Sha256']=PFX_SHA; summary['ownerCensus']=[30,280,75,41]; (res/'summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n'); (res/'execution-boundary.json').write_text(json.dumps(state,indent=2,sort_keys=True)+'\n');
 for p in sorted([x for x in res.rglob('*') if x.is_file() and x.name!='SHA256SUMS']): pass
 with open(res/'SHA256SUMS','w') as f:
  for p in sorted([x for x in res.rglob('*') if x.is_file() and x.name!='SHA256SUMS']): f.write(f'{sha(p)}  {p.relative_to(res).as_posix()}\n')
 lf.close()
if state['orchestrationFailure'] or summary['semanticStatus']=='ORCHESTRATION_FAILURE': sys.exit(90)
PY
