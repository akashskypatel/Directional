#!/usr/bin/env python3
import hashlib, json, os, pathlib, re, stat, subprocess, sys, tarfile
from datetime import datetime, timezone

AID=9736088354
PKG_SHA='78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf'
SRC_SHA='2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e'
TRANSPORT='57444781af7bdc460e38cc68930a9a8c8199eeea'
SEMANTIC='57444781af7bdc460e38cc68930a9a8c8199eeea'
EIGEN='769c72fd8019e389810d1de1e7c243521a43b594'
HASHES={355:'e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa',357:'b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70',361:'61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b',365:'6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'}
SEL='.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt'
NG=['GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable','GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable','ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating']
TARGETS={
'directional_surface_cell_producer_tests':['AdaptiveFeatureMapPhase11Tests.cpp','AdaptiveTargetSizePhase12Tests.cpp','BoundedMeshPreconditionerTests.cpp','CrossFieldTransferTests.cpp','FieldAlignedCurveNetworkTests.cpp','RegularizedCurvaturePhase1Tests.cpp','SourceGridRecoveryAuthorityTests.cpp','SurfaceCellDesignAcceptanceTests.cpp','SurfaceCellREPackageTests.cpp','SurfaceCellTransitionQuotientTests.cpp','SurfaceCellsPhase10Tests.cpp'],
'directional_surface_cell_authority_kernel_tests':['FieldTransportAtlasTests.cpp','SurfaceCellAuthorityKernelTests.cpp'],
'directional_surface_cell_completion_tests':['FlowRepStrandsPhase15Tests.cpp','PatchDescriptorMilestoneETests.cpp','PureQuadCompletionPhase18Tests.cpp','SurfaceArrangementRowIdentityTests.cpp','SurfaceComplexSimplificationPhase17Tests.cpp'],
'directional_surface_cell_validation_tests':['SourceAuthoritativeMeshValidatorPhase22Tests.cpp','SurfaceMeshOptimizerPhase19Tests.cpp','SurfaceMeshOptimizerPhase20Tests.cpp','SurfaceMeshOptimizerPhase21Tests.cpp','SurfaceMeshOptimizerPhase22Tests.cpp']}
EXPECTED_COUNTS={'directional_surface_cell_producer_tests':219,'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}
R=pathlib.Path(os.environ['RUNNER_TEMP'])/'m3-cp4c2-r10'; P=R/'package'; S=R/'source'; PROC=R/'processes'; OUT=pathlib.Path(os.environ['RUNNER_TEMP'])/'m3-cp4c2-r10-result'; LOG=pathlib.Path(os.environ['RUNNER_TEMP'])/'m3-cp4c2-r10.log'
for p in (R,P,S,PROC,OUT/'raw'): p.mkdir(parents=True,exist_ok=True)
class Tee:
 def __init__(self,*f): self.f=f
 def write(self,s):
  for x in self.f: x.write(s); x.flush()
 def flush(self):
  for x in self.f: x.flush()
lf=LOG.open('a',encoding='utf-8'); sys.stdout=Tee(sys.__stdout__,lf); sys.stderr=Tee(sys.__stderr__,lf)
started=datetime.now(timezone.utc).isoformat(); invalid=[]; ng_red=0; ng_done=0; done=0; passed=0; first_red=None; semantic='NOT_RUN'; ah6=False; post_ok=False

def sha(p):
 h=hashlib.sha256()
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(1<<20),b''): h.update(b)
 return h.hexdigest()
def bad(kind,msg): invalid.append((kind,msg)); print('INVALID',kind,msg); raise RuntimeError(msg)
def inv(root):
 rows=[]
 for p in sorted(root.rglob('*'),key=lambda x:x.as_posix()):
  st=p.lstat(); rel=p.relative_to(root).as_posix(); mode=oct(stat.S_IMODE(st.st_mode))
  if p.is_symlink(): data='link:'+os.readlink(p)
  elif p.is_file(): data=f'{st.st_size}:{sha(p)}'
  else: data='dir'
  rows.append((rel,mode,data))
 return rows
def write_inv(path,rows): path.write_text(''.join('\t'.join(r)+'\n' for r in rows),encoding='utf-8')
def download():
 path=f"repos/{os.environ['GITHUB_REPOSITORY']}/actions/artifacts/{AID}/zip"
 with open(R/'package.zip','wb') as f:
  subprocess.run(['gh','api',path],stdout=f,check=True,env=os.environ.copy())
def manifest_ok():
 lines=(P/'SHA256SUMS').read_text().splitlines()
 if len(lines)!=28: return False
 for line in lines:
  want,name=line.split(None,1); name=name.lstrip('* ')
  if sha(P/name)!=want: return False
 return True
def resolve(selector):
 pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',re.S); found={}
 for binary,names in TARGETS.items():
  for name in names:
   text=(S/'tests'/name).read_text()
   for a,b in pat.findall(text): found.setdefault(f'{a}.{b}',[]).append((binary,'tests/'+name))
 m={}; counts={k:0 for k in TARGETS}
 for identity in selector+NG:
  hits=found.get(identity,[])
  if len(hits)!=1: bad('integrity',f'identity resolution {identity}: {hits}')
  m[identity]=hits[0]
  if identity in selector: counts[hits[0][0]]+=1
 if counts!=EXPECTED_COUNTS: bad('integrity',f'target counts {counts}')
 (OUT/'identity-map.tsv').write_text(''.join(f'{i}\t{m[i][0]}\t{m[i][1]}\n' for i in selector+NG))
 print('IDENTITY_COUNTS',counts); return m
def publish_ai2(raw,status):
 rows=[line for line in raw.read_text(encoding='utf-8',errors='replace').splitlines() if 'M3_CP4AB_FRAGMENT_DIAG record=' in line]
 terminal='SUCCESS' if status=='PASS' else 'RED_SEE_RAW_LOG'
 text=[f'gate_process_status={status}',f'typed_terminal_result={terminal}',f'diagnostic_row_count={len(rows)}']+rows
 (OUT/'ai2-fragment-orbit-evidence.txt').write_text('\n'.join(text)+'\n',encoding='utf-8')
 print('R10_AI2_ROWS',len(rows),'status',status)
def run_one(scope,ordinal,identity,m):
 binary=m[identity][0]; exe=P/'bin'/binary
 if not os.access(exe,os.X_OK): bad('orchestration',f'non-executable {binary}')
 wd=PROC/f'{scope}-{ordinal}'; wd.mkdir(); raw=OUT/'raw'/f'{scope}-{ordinal}.log'; env=os.environ.copy(); env['GTEST_COLOR']='no'
 if scope=='selector' and ordinal==363: env['DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS']='1'
 print('PROCESS_START',scope,ordinal,identity,binary,'fragmentDiagnostics='+str(scope=='selector' and ordinal==363).lower())
 cp=subprocess.run([str(exe),f'--gtest_filter={identity}'],cwd=wd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,env=env)
 raw.write_text(cp.stdout); print(cp.stdout,end='')
 selected=sum(1 for x in cp.stdout.splitlines() if x==f'[ RUN      ] {identity}')
 if selected!=1: bad('orchestration',f'{scope} {ordinal} selected={selected} rc={cp.returncode}')
 status='PASS' if cp.returncode==0 else 'RED'
 with (OUT/'process-results.tsv').open('a') as f: f.write(f'{scope}\t{ordinal}\t{identity}\t{binary}\t1\t{cp.returncode}\t{status}\t{raw.name}\n')
 if scope=='selector' and ordinal==363: publish_ai2(raw,status)
 print('PROCESS_END',scope,ordinal,status,cp.returncode); return status
def preflight():
 print('R10_PREFLIGHT_BEGIN'); download()
 if sha(R/'package.zip')!=PKG_SHA: bad('integrity','package sha')
 subprocess.run(['unzip','-q',str(R/'package.zip'),'-d',str(P)],check=True)
 if not manifest_ok(): bad('integrity','manifest 28/28')
 src=P/'source'/f'source-{TRANSPORT}.tar.gz'
 if not src.exists() or sha(src)!=SRC_SHA: bad('integrity','source archive')
 if (P/'metadata/source-commit.txt').read_text().strip()!=TRANSPORT: bad('integrity','transport source')
 dep=(P/'metadata/dependency-revisions.txt').read_text(); bound=(P/'metadata/command-boundary.txt').read_text(); gmp=(P/'metadata/gmp-evidence.txt').read_text()
 if f'{EIGEN} external/eigen' not in dep: bad('integrity','Eigen gitlink')
 for s in ('runtimeExecution=false','turnBoundary=Code+Build-only','exactArithmeticBackend=GMP'):
  if s not in bound: bad('integrity',s)
 if 'libgmpxx' not in gmp or 'libgmp.so' not in gmp: bad('integrity','GMP/GMPXX')
 for n in ('source-status-before-configure.txt','source-status-after-configure.txt','source-status-after-build.txt','source-status-final.txt'):
  if (P/'metadata'/n).read_text(): bad('integrity',f'dirty {n}')
 for b in TARGETS:
  if not os.access(P/'bin'/b,os.X_OK): bad('integrity',f'mode {b}')
 with tarfile.open(src,'r:gz') as t: t.extractall(S)
 selector=(S/SEL).read_text().splitlines()
 if len(selector)!=365 or len(set(selector))!=365: bad('integrity','selector cardinality/uniqueness')
 raw=(S/SEL).read_bytes().splitlines(keepends=True)
 for n,want in HASHES.items():
  if hashlib.sha256(b''.join(raw[:n])).hexdigest()!=want: bad('integrity',f'selector hash {n}')
 m=resolve(selector); write_inv(OUT/'package-inventory-pre.tsv',inv(P)); write_inv(OUT/'source-inventory-pre.tsv',inv(S))
 (OUT/'authority.json').write_text(json.dumps({'semanticSource':SEMANTIC,'transportSource':TRANSPORT,'artifactId':AID,'packageSha256':PKG_SHA,'sourceArchiveSha256':SRC_SHA,'selectorHashes':HASHES,'generatedDiscovery':False,'repair':False},indent=2))
 print('R10_PREFLIGHT_GREEN'); return selector,m
def publish_ah6():
 global ah6
 rows=(OUT/'process-results.tsv').read_text().splitlines() if (OUT/'process-results.tsv').exists() else []
 statby={int(x.split('\t')[1]):x.split('\t')[6] for x in rows if x.startswith('selector\t')}
 if done<365:
  (OUT/'ah6.txt').write_text('applicable=false\nreason=ordinals 363-365 not all reached\nordinal363='+statby.get(363,'NOT_RUN')+'\nordinal364='+statby.get(364,'NOT_RUN')+'\nordinal365='+statby.get(365,'NOT_RUN')+'\n'); return
 ah6=True
 src=(S/'src/geometry/SurfaceCutGraph.cpp').read_text().splitlines()
 needles=['barriers.insert(traceCrossed.begin(),traceCrossed.end())','proposal_tree_cotree_cut_edges','This includes exact trace-crossed edges under Amendment 14','saturationUsed=true']
 evidence=[]
 for q in needles:
  hits=[f'{i+1}:{x.strip()}' for i,x in enumerate(src) if q in x]
  if not hits: bad('integrity',f'AH6 source needle {q}')
  evidence+=hits
 (OUT/'ah6-source-evidence.txt').write_text('\n'.join(evidence)+'\n')
 allgreen=all(statby.get(n)=='PASS' for n in (363,364,365))
 if allgreen:
  body='''applicable=true\nordinal363=PASS\nordinal364=PASS\nordinal365=PASS\nordinary_proposal_selected_trace_crossed_edge=no\nsaturation_used=yes\nsaturation_locus_exists=yes\nsaturation_promoted_edge_count_positive=yes\nselected_trace_crossed_edge_exists=yes\nsubdivided_crossing_exists=yes\nexact_selected_trace_crossed_edge=NOT_OBSERVABLE_FROM_FROZEN_TEST_OUTPUT\nexact_saturation_locus=NOT_OBSERVABLE_FROM_FROZEN_TEST_OUTPUT\nexact_saturation_promoted_edge_count=NOT_OBSERVABLE_FROM_FROZEN_TEST_OUTPUT\nordinals_363_364_path_classification=saturation-reached state, not ordinary trace-crossed proposal coverage\ncoverage_disposition=RAW_SATURATION_ONLY_EVIDENCE_FOR_R10_REV\ncp4c2_auto_close_eligible=false\n'''
 else:
  body='applicable=true\nordinal363='+statby.get(363,'NOT_RUN')+'\nordinal364='+statby.get(364,'NOT_RUN')+'\nordinal365='+statby.get(365,'NOT_RUN')+'\ncoverage_disposition=R10_REV_OWNS_INTERPRETATION\n'
 (OUT/'ah6.txt').write_text(body)
 print('R10_AH6 applicable=true allgreen='+str(allgreen).lower())
def postflight():
 global post_ok
 try:
  a=inv(P); b=inv(S); write_inv(OUT/'package-inventory-post.tsv',a); write_inv(OUT/'source-inventory-post.tsv',b)
  post_ok=(a==pre_pkg and b==pre_src and manifest_ok())
 except Exception as e: invalid.append(('postflight',str(e))); post_ok=False
 (OUT/'mutation-flags.txt').write_text(f'configure=false\ncompile=false\nrelink=false\nrepair=false\ngeneratedDiscovery=false\nsourceMutation=false\ntestMutation=false\nfixtureMutation=false\nselectorMutation=false\npackageMutation={str(not post_ok).lower()}\nbenchmarkExecution=false\npostflightPass={str(post_ok).lower()}\n')
 if not post_ok: invalid.append(('postflight','immutability comparison failed'))
 print('R10_POSTFLIGHT','GREEN' if post_ok else 'RED')

selector=[]; mapping={}; pre_pkg=[]; pre_src=[]
try:
 selector,mapping=preflight(); pre_pkg=inv(P); pre_src=inv(S)
 for i,x in enumerate(NG,1):
  st=run_one('nongating',i,x,mapping); ng_done+=1; ng_red+=st!='PASS'
 for i,x in enumerate(selector,1):
  st=run_one('selector',i,x,mapping); done=i
  if st=='PASS': passed+=1
  else: first_red=(i,x); semantic='RED'; print('R10_HARD_STOP',i,x); break
 if not first_red and done==365: semantic='GREEN'
 publish_ah6()
except RuntimeError:
 pass
except Exception as e:
 invalid.append(('orchestration',repr(e))); print('UNEXPECTED',repr(e))
finally:
 postflight()
valid=not invalid and post_ok
summary={'turn':'M3-CP4c-2-TB-X2-R10-EXEC','semanticSource':SEMANTIC,'transportSource':TRANSPORT,'artifactId':AID,'executionValid':valid,'invalid':invalid,'semanticOutcome':semantic,'nongatingExecuted':ng_done,'nongatingRed':ng_red,'selectorExecuted':done,'selectorPassed':passed,'firstRedOrdinal':first_red[0] if first_red else None,'firstRedIdentity':first_red[1] if first_red else None,'acceptedPrefix355Green':passed>=355,'r9Cand01RuntimeClosureCondition':passed>=365 and all((OUT/'process-results.tsv').read_text().find(f'selector\t{n}\t')>=0 for n in (363,364,365)) if (OUT/'process-results.tsv').exists() else False,'ah6Applicable':ah6,'ai2EvidencePublished':(OUT/'ai2-fragment-orbit-evidence.txt').exists(),'postflightPass':post_ok,'benchmarkExecution':False,'configure':False,'compile':False,'relink':False,'repair':False,'generatedDiscovery':False,'startedAt':started,'finishedAt':datetime.now(timezone.utc).isoformat()}
(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n'); print('R10_FINAL',json.dumps(summary,separators=(',',':')))
sys.exit(0 if valid else 2)
