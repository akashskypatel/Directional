#!/usr/bin/env python3
import csv,hashlib,json,os,stat,subprocess,sys
from pathlib import Path
E=os.environ;R=Path(E['RUNNER_TEMP'])/'m4-cp2-tb2';P=R/'package';S=R/'source';V=R/'execution-view';O=Path(E['RUNNER_TEMP'])/'m4-cp2-tb2-result';W=R/'runtime';W.mkdir(parents=True,exist_ok=True)
B=('directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests');X=dict(zip(B,(30,236,75,41)));F=(374,381,382);RC='M4_CP2_ORACLE_RECEIPT coordinateCount=4; containsBidirectedCoefficientMagnitude2=true; magnitude2LoadBearing=true'
st={'runtime_started':'false','runtime_completed':'false','preflight_completed':'true','selection_integrity':'true','configure_execution':'false','compile_execution':'false','relink_execution':'false','generated_discovery':'false','package_repair':'false','mode_repair':'false','source_test_fixture_selector_mutation':'false','benchmark_execution':'false','timeout_count':'0','orchestration_failure':'false'}
def h(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def census(base,d):
 r=[]
 for p in sorted(base.rglob('*')):
  q=p.relative_to(base).as_posix();s=p.lstat();m=oct(stat.S_IMODE(s.st_mode));r.append((q,'L',m,0,'',os.readlink(p)) if p.is_symlink() else (q,'F',m,s.st_size,h(p),'') if p.is_file() else (q,'D',m,0,'',''))
 Path(d).write_text('path\ttype\tmode\tsize\tsha256\ttarget\n'+''.join('\t'.join(map(str,x))+'\n' for x in r))
def state(): (O/'execution-boundary.txt').write_text(''.join(f'{k}={v}\n' for k,v in st.items()))
def die(m):st['orchestration_failure']='true';state();raise RuntimeError(m)
M=[]
with (O/'identity-map.tsv').open() as f:
 for r in list(csv.DictReader(f,delimiter='\t')):M.append((int(r['ordinal']),r['identity'],r['binary']))
if len(M)!=382:die('identity map count')
def one(ph,n,i,b,L):
 d=O/'raw'/ph;d.mkdir(parents=True,exist_ok=True);w=W/ph/f'ordinal-{n:03d}';w.mkdir(parents=True,exist_ok=True);raw=d/f'ordinal-{n:03d}.log';env=os.environ.copy();env.update(GTEST_FAIL_IF_NO_TEST_SELECTED='1',GTEST_COLOR='no')
 print(f'RUN phase={ph} ordinal={n} owner={b} identity={i}',flush=True);r=subprocess.run([str(V/'bin'/b),f'--gtest_filter={i}'],cwd=w,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);t=r.stdout or '';raw.write_text(t);run=[x for x in t.splitlines() if x.startswith('[ RUN      ] ')];ok=[x for x in t.splitlines() if x.startswith('[       OK ] ')];sk=[x for x in t.splitlines() if x.startswith('[  SKIPPED ] ')];sel=len(run)==1 and run[0].strip()=='[ RUN      ] '+i;good=sel and r.returncode==0 and len(ok)==1 and ok[0].startswith('[       OK ] '+i) and not sk
 if not sel:st['selection_integrity']='false'
 L.append([n,i,b,r.returncode,len(run),len(sk),'PASS' if good else 'RED',raw.relative_to(O).as_posix()]);print(f'RESULT phase={ph} ordinal={n} verdict={L[-1][6]} exit={r.returncode} selected={len(run)} skipped={len(sk)}',flush=True);return t
def led(p,L):
 with Path(p).open('w',newline='') as f:w=csv.writer(f,delimiter='\t',lineterminator='\n');w.writerow(('ordinal','identity','binary','exit','selected','skipped','result','raw_log'));w.writerows(L)
def post():
 for x,b in(('package',P),('source',S),('execution-view',V)):
  census(b,O/f'{x}-census-after.tsv')
  if (O/f'{x}-census-before.tsv').read_bytes()!=(O/f'{x}-census-after.tsv').read_bytes():
   if x=='source':st['source_test_fixture_selector_mutation']='true'
   die(x+' census changed')
try:
 st['runtime_started']='true';FV=[];A=[]
 for ph in('focused-a','focused-b'):
  L=[]
  for n in F:
   _,i,b=M[n-1];t=one(ph,n,i,b,L)
   if n==374:
    c=t.splitlines().count(RC);A.append((ph,c,'PASS' if c==1 else 'RED'))
    if c!=1:L[-1][6]='RED'
  led(O/f'{ph}-ledger.tsv',L);FV.append([r[6] for r in L])
 if st['selection_integrity']!='true':die('focused selection mismatch')
 (O/'ordinal374-receipt-audit.tsv').write_text('phase\tcount\tresult\n'+''.join(f'{a}\t{b}\t{c}\n' for a,b,c in A))
 L=[]
 for n,i,b in M:one('full',n,i,b,L)
 st['runtime_completed']='true';led(O/'full-ledger.tsv',L)
 if st['selection_integrity']!='true':die('full selection mismatch')
 red=[r for r in L if r[6]!='PASS'];skip=sum(r[5] for r in L);own={b:[0,0] for b in B}
 for r in L:own[r[2]][1]+=1;own[r[2]][0]+=r[6]=='PASS'
 pc=lambda a,b:sum(r[6]=='PASS' for r in L[a-1:b]);sem={'selector_pass':382-len(red),'selector_total':382,'accepted373_pass':pc(1,373),'cp2_374_380_pass':pc(374,380),'correction381_382_pass':pc(381,382),'red':len(red),'skip':skip,'timeout':0,'selection_mismatch':sum(r[4]!=1 for r in L),'focused_a':FV[0],'focused_b':FV[1],'focused_vectors_equal':FV[0]==FV[1],'receipt_audit':A,'owners':own};(O/'semantic-summary.json').write_text(json.dumps(sem,indent=2,sort_keys=True)+'\n');post();state();gate=sem['selector_pass']==382 and sem['accepted373_pass']==373 and sem['cp2_374_380_pass']==7 and sem['correction381_382_pass']==2 and not sem['red'] and not sem['skip'] and not sem['selection_mismatch'] and all(x[2]=='PASS' for x in A) and all(own[b]==[X[b],X[b]] for b in B);sys.exit(0 if gate else 1)
except Exception as e:
 print('ORCHESTRATION_FAILURE:',e,file=sys.stderr);(O/'failure.txt').write_text(str(e)+'\n');state();sys.exit(90)
