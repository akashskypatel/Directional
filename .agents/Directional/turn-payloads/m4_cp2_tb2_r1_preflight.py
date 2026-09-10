#!/usr/bin/env python3
import csv,hashlib,json,os,re,shutil,stat,subprocess,sys
from pathlib import Path
E=os.environ; R=Path(E['RUNNER_TEMP'])/'m4-cp2-tb2'; P=R/'package'; S=R/'source'; V=R/'execution-view'; O=Path(E['RUNNER_TEMP'])/'m4-cp2-tb2-result'
for p in(P,S,V/'bin',O):p.mkdir(parents=True,exist_ok=True)
SRC='534c0d41ae05b31e66711f21f4b4280b59f6483f'; AN='directional-m4-cp2-cb2-package117-result-34529050994'; SP='.agents/Directional/Architecture_M4_CP2_Required_Green_Selector_382.txt'
Z='e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725'; SA='a366908f0f52cc7bcdff4123893acbc553201880aa86a07f9418aac2734082f4'; SE='1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f'; P373='6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b'; P380='512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4'
B={'directional_surface_cell_authority_kernel_tests':'5efacc3ad52085a8ab76bad451bfc70c337e44a73a8f81a165f06ab1cd3041b3','directional_surface_cell_producer_tests':'2363de846e7f59a34be2d1e60bce524f3d4567c459c37a75f6b69ed6933c3968','directional_surface_cell_completion_tests':'1701820d85d91fe674cb3dd3496669f0a49ca43e6068a170fb0277227aba094a','directional_surface_cell_validation_tests':'303af6ab231bf88b6b618df03315c9999a27595b8b55871922935f5098a4ca5f'}; X=dict(zip(B,(30,236,75,41)))
def h(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def run(a,cwd=None,cap=False):return subprocess.run(a,cwd=cwd,text=True,stdout=subprocess.PIPE if cap else None,stderr=subprocess.STDOUT if cap else None)
def die(m):(O/'preflight-failure.txt').write_text(m+'\n');print('ORCHESTRATION_FAILURE:',m,file=sys.stderr);raise SystemExit(90)
def census(base,d):
 r=[]
 for p in sorted(base.rglob('*')):
  q=p.relative_to(base).as_posix();s=p.lstat();m=oct(stat.S_IMODE(s.st_mode))
  if p.is_symlink():r.append((q,'L',m,0,'',os.readlink(p)))
  elif p.is_file():r.append((q,'F',m,s.st_size,h(p),''))
  elif p.is_dir():r.append((q,'D',m,0,'',''))
 Path(d).write_text('path\ttype\tmode\tsize\tsha256\ttarget\n'+''.join('\t'.join(map(str,x))+'\n' for x in r))
def curl(u,d):
 a=['curl','-fsSL','-H',f"Authorization: Bearer {E['GH_TOKEN']}",'-H','Accept: application/vnd.github+json','-H','X-GitHub-Api-Version: 2022-11-28',u,'-o',str(d)]
 if run(a).returncode:die('curl failed')
meta=R/'artifact.json'; z=R/'artifact.zip'; aid=E['ARTIFACT_ID']; repo=E['GITHUB_REPOSITORY'];curl(f'https://api.github.com/repos/{repo}/actions/artifacts/{aid}',meta);j=json.loads(meta.read_text())
if j.get('name')!=AN or j.get('digest')!='sha256:'+Z:die('artifact metadata mismatch')
curl(f'https://api.github.com/repos/{repo}/actions/artifacts/{aid}/zip',z)
if h(z)!=Z:die('artifact zip digest mismatch')
if run(['unzip','-q',str(z),'-d',str(P)]).returncode:die('unzip failed')
mf=P/'SHA256SUMS';ml=mf.read_text().splitlines()
if len(ml)!=28 or any(x.strip().endswith(' SHA256SUMS') for x in ml):die('manifest shape mismatch')
r=run(['sha256sum','-c','SHA256SUMS'],P,True);(O/'package-sha256-check.txt').write_text(r.stdout or '')
if r.returncode or (r.stdout or '').count(': OK')!=28:die('package checksum failure')
if (P/'metadata/source-commit.txt').read_text().strip()!=SRC:die('source mismatch')
for p in (P/'metadata').glob('source-status-*.txt'):
 if p.read_bytes():die('nonempty source status '+p.name)
if (P/'metadata/build-exit-code.txt').read_text().strip()!='0' or (P/'metadata/preflight-exit-code.txt').read_text().strip()!='0':die('compile receipt mismatch')
cb=(P/'metadata/command-boundary.txt').read_text();ge=(P/'metadata/gmp-evidence.txt').read_text()
if any(x not in cb for x in('runtimeExecution=false','turnBoundary=Code+Build-only','exactArithmeticBackend=GMP')) or 'gmpxx' not in ge or 'libgmp' not in ge:die('boundary/GMP receipt mismatch')
sa=next((P/'source').glob('source-*.tar.gz'))
if h(sa)!=SA or run(['tar','-xzf',str(sa),'-C',str(S)]).returncode:die('source archive mismatch/extract failure')
sb=(S/SP).read_bytes();ls=sb.splitlines(keepends=True)
if len(ls)!=382 or b'\r' in sb or h(S/SP)!=SE:die('selector382 mismatch')
if hashlib.sha256(b''.join(ls[:373])).hexdigest()!=P373 or hashlib.sha256(b''.join(ls[:380])).hexdigest()!=P380:die('selector prefix mismatch')
ids=[x.decode().strip() for x in ls];cm=(S/'cmake/DirectionalTests.cmake').read_text();T={}
def cpp(t):return[x.strip() for x in t.splitlines() if x.strip().endswith('.cpp')]
p=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cm,re.S)
if not p:die('producer source set missing')
T['directional_surface_cell_producer_tests']=cpp(p.group(1))
for t in B:
 if t in T:continue
 q=re.search(r'add_executable\(\s*'+re.escape(t)+r'(.*?)\)\s*\n',cm,re.S)
 if not q:die('target block missing '+t)
 T[t]=cpp(q.group(1))
pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)');own={}
for t,fs in T.items():
 for f in fs:
  for a,b in pat.findall((S/f).read_text(errors='replace')):own.setdefault(a+'.'+b,[]).append((t,f))
rows=[];cnt={t:0 for t in B}
for n,i in enumerate(ids,1):
 g=own.get(i,[])
 if len(g)!=1:die(f'owner count {len(g)} at {n}:{i}')
 t,f=g[0];rows.append((n,i,t,f));cnt[t]+=1
if cnt!=X:die('owner distribution mismatch '+repr(cnt))
if any(rows[n-1][2]!='directional_surface_cell_producer_tests' for n in range(374,383)):die('CP2 owner mismatch')
with (O/'identity-map.tsv').open('w',newline='') as f:
 w=csv.writer(f,delimiter='\t',lineterminator='\n');w.writerow(('ordinal','identity','binary','source'));w.writerows(rows)
(O/'owner-distribution.txt').write_text(''.join(f'{k}={v}\n' for k,v in cnt.items()))
for b,d in B.items():
 p=P/'bin'/b
 if not p.is_file() or not os.access(p,os.X_OK) or h(p)!=d:die('owner executable mismatch '+b)
census(P,O/'package-census-before.tsv');census(S,O/'source-census-before.tsv')
if run(['cp','-a',str(P/'bin')+'/.',str(V/'bin')]).returncode:die('binary staging failed')
(V/'test-data/benchmarks').mkdir(parents=True,exist_ok=True)
if run(['cp','-a',str(S/'benchmarks/fixtures'),str(V/'test-data/benchmarks/')]).returncode:die('fixture staging failed')
for b in B:
 if h(P/'bin'/b)!=h(V/'bin'/b) or stat.S_IMODE((P/'bin'/b).stat().st_mode)!=stat.S_IMODE((V/'bin'/b).stat().st_mode):die('execution-view drift '+b)
tf=(S/'tests/TestFixturePaths.h').read_text()
if 'executableDirectory.parent_path() / "test-data"' not in tf or not (V/'test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj').is_file():die('fixture root invalid')
census(V,O/'execution-view-census-before.tsv');(O/'preflight.txt').write_text('preflight_completed=true\npackage_checksums=28/28\nselector382=382\nowners=30/236/75/41\n')
print('M4_CP2_TB2_PREFLIGHT_COMPLETE runtimeExecution=false package_repair=false mode_repair=false')
