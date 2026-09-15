#!/usr/bin/env python3
import csv,hashlib,os,pathlib,shutil,stat,subprocess,sys,tarfile,time
TURN='M4-CP-SCALE-TB4-R1-EXEC'; AID='10378808176'; ANAME='m4-cp-scale-cb4-result-34923091581'
ZIP_SHA='a60fbbb7127b2fb36952cc9fef8d58cce366204ffbcbdcd7ace2de69ff7e488a'; MAN_SHA='b3364c9a0ce63f497a942b4ed8739403e4b4e9541ccf5b4faf13aab1a72f587f'; SRC_AR_SHA='e604279d0754e44d7aa02c7d1418e73cd23ec5fd5599b05b0bda929da248428d'
SEL_SHA='4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343'; FIRST_SHA='bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc'; SOURCE='905dabe390577d63ed6a9289e3f3d53aa4144936'
FOCUS='M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle'
root=pathlib.Path(os.environ['RUNNER_TEMP'])/'m4-cp-scale-tb4-r1-exec'; pkg=root/'package'; src=root/'source'; view=root/'view'; run=root/'runtime'; ev=root/'evidence'; pub=pathlib.Path(os.environ['RUNNER_TEMP'])/'tb4-r1-publish'
for p in [pkg,src,view/'bin',view/'lib',view/'test-data/benchmarks/fixtures',run/'s2',run/'selector',ev/'raw/s2',ev/'raw/selector',ev/'resources/s2',ev/'resources/selector',pub]: p.mkdir(parents=True,exist_ok=True)
state=dict(preflight=False,postflight=False,runtime=False,focus='UNEXECUTED',selector=False,exit=99)
def sha(p): return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()
def sh(args,**kw): print('+',' '.join(map(str,args)),flush=True); return subprocess.run(args,check=True,**kw)
def census(base,out):
 base=pathlib.Path(base); rows=[]
 for p in [base,*sorted(base.rglob('*'))]:
  s=p.lstat(); rel='.' if p==base else p.relative_to(base).as_posix(); kind='file' if p.is_file() else 'dir' if p.is_dir() else 'symlink' if p.is_symlink() else 'other'; digest=sha(p) if p.is_file() else '-'; target=os.readlink(p) if p.is_symlink() else '-'; rows.append(f'{rel}\t{kind}\t{stat.S_IMODE(s.st_mode):04o}\t{s.st_size}\t{digest}\t{target}\n')
 pathlib.Path(out).write_text(''.join(rows))
CENSUS_BASES=('package','source','execution-view')
def census_path(name,phase): return ev/f'{name}-census-{phase}.tsv'
def write_preflight_censuses():
 for name,base in [('package',pkg),('source',src),('execution-view',view)]: census(base,census_path(name,'before'))
def assert_preflight_census_contract():
 for name in CENSUS_BASES:
  p=census_path(name,'before')
  if not p.is_file(): raise RuntimeError(f'missing preflight census receipt {p.name}')
def tree_manifest(base,out):
 base=pathlib.Path(base); rows=[]
 for p in [base,*sorted(base.rglob('*'))]:
  s=p.lstat(); rel='.' if p==base else p.relative_to(base).as_posix(); mode=f'{stat.S_IMODE(s.st_mode):04o}'
  if p.is_file(): rows.append(f'{rel}\tfile\t{mode}\t{sha(p)}\n')
  elif p.is_dir(): rows.append(f'{rel}\tdir\t{mode}\t-\n')
  elif p.is_symlink(): rows.append(f'{rel}\tsymlink\t{mode}\t{os.readlink(p)}\n')
  else: rows.append(f'{rel}\tother\t{mode}\t-\n')
 pathlib.Path(out).write_text(''.join(rows))
def assert_fixture_materialization(source,destination):
 source=pathlib.Path(source); destination=pathlib.Path(destination)
 expected=view/'test-data/benchmarks/fixtures'
 if source != src/'benchmarks/fixtures' or destination != expected: raise RuntimeError('fixture layout contract mismatch')
 if not source.is_dir() or not destination.is_dir(): raise RuntimeError('fixture subtree missing')
 before=ev/'fixture-source-manifest.tsv'; after=ev/'fixture-execution-view-manifest.tsv'; tree_manifest(source,before); tree_manifest(destination,after)
 if before.read_bytes()!=after.read_bytes(): raise RuntimeError('fixture subtree materialization differs from packaged source')
def owner(identity):
 suite=identity.split('.',1)[0]
 if suite in {'FieldTransportAtlas','SurfaceCellAuthorityKernel'}: return 'directional_surface_cell_authority_kernel_tests'
 if suite in {'FlowRepStrandsPhase15','PatchDescriptorMilestoneE','PureQuadCompletionPhase18','SurfaceArrangementPhase16','SurfaceCellSourceSupportAndChartAuthority','SurfaceComplexSimplificationPhase17'}: return 'directional_surface_cell_completion_tests'
 if suite in {'SourceAuthoritativeMeshValidatorPhase22','SurfaceMeshOptimizerPhase19','SurfaceMeshOptimizerPhase22','SurfaceOptimizationRailAuthorityMigration'}: return 'directional_surface_cell_validation_tests'
 return 'directional_surface_cell_producer_tests'
def write_ledger(rows):
 with (ev/'selector423-process-ledger.tsv').open('w',newline='') as f:
  w=csv.writer(f,delimiter='\t',lineterminator='\n'); w.writerow(['ordinal','identity','binary','state','exit','selected','ok','skipped','raw_log']); w.writerows(rows)
def execute(binary,identity,work,raw,timing):
 work.mkdir(parents=True,exist_ok=True); env=os.environ.copy(); env.update(GTEST_FAIL_IF_NO_TEST_SELECTED='1',GTEST_COLOR='no'); cmd=['/usr/bin/time','-v','-o',str(timing),'timeout','-k','5s','180s',str(binary),f'--gtest_filter={identity}']
 with raw.open('wb') as f: r=subprocess.run(cmd,cwd=work,env=env,stdout=f,stderr=subprocess.STDOUT)
 text=raw.read_text(errors='replace').splitlines(); selected=sum(x.startswith('[ RUN      ] ') for x in text); ok=sum(x.startswith('[       OK ] ') for x in text); skipped=sum(x.startswith('[  SKIPPED ] ') for x in text); return r.returncode,selected,ok,skipped
def postflight():
 if not state['preflight'] or state['postflight']: return
 sh(['sha256sum','-c','SHA256SUMS'],cwd=pkg,stdout=(ev/'postflight-package-sha256-check.txt').open('wb'))
 census(pkg,census_path('package','after')); census(src,census_path('source','after')); census(view,census_path('execution-view','after'))
 for n in CENSUS_BASES:
  if census_path(n,'before').read_bytes()!=census_path(n,'after').read_bytes(): raise RuntimeError(f'{n} census changed')
 selector=src/'.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt'; lines=selector.read_bytes().splitlines(keepends=True)
 if len(lines)!=423 or sha(selector)!=SEL_SHA or hashlib.sha256(b''.join(lines[:422])).hexdigest()!=FIRST_SHA: raise RuntimeError('selector drift')
 (ev/'postflight-immutability.txt').write_text(f'package_census_equal=true\nsource_census_equal=true\nexecution_view_census_equal=true\npackage_manifest_verified=true\nselector_rows=423\nselector_sha256={SEL_SHA}\nfirst422_sha256={FIRST_SHA}\n')
 state['postflight']=True
def finalize():
 try: postflight()
 except Exception as e: print('POSTFLIGHT_ERROR',repr(e)); state['exit']=97
 (ev/'final-status.txt').write_text('\n'.join([f'mechanical_exit={state["exit"]}',f'preflightPass={str(state["preflight"]).lower()}',f'postflightPass={str(state["postflight"]).lower()}',f'runtimeStarted={str(state["runtime"]).lower()}',f'focusedResult={state["focus"]}',f'selectorCompleted={str(state["selector"]).lower()}','runtimeExecution=true','configureExecution=false','compileExecution=false','relinkExecution=false','repairExecution=false','generatedDiscovery=false','mutationExecution=false','benchmarkExecution=false'])+'\n')
 files=sorted(p for p in ev.rglob('*') if p.is_file() and p.name!='SHA256SUMS'); (ev/'SHA256SUMS').write_text(''.join(f'{sha(p)}  {p.relative_to(ev).as_posix()}\n' for p in files)); sh(['sha256sum','-c','SHA256SUMS'],cwd=ev,stdout=(pub/'evidence-manifest-check.txt').open('wb'))
 z=pub/'Directional__M4-CP-SCALE-TB4-R1-EXEC__evidence.zip'; sh(['zip','-qr',str(z),'evidence'],cwd=root); (pub/'publication.env').write_text(f'turn={TURN}\nartifact_id={AID}\nartifact_name={ANAME}\nevidence_zip_sha256={sha(z)}\nmechanical_exit={state["exit"]}\nruntimeExecution=true\n')
