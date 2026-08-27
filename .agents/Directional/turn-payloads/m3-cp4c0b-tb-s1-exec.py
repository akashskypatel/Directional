import json,os,shutil,stat,subprocess,sys
from pathlib import Path
from tb_s1_common import sha,inv,run_one,route_map,census_summary
T=Path(os.environ['RUNNER_TEMP']); W=Path(os.environ['GITHUB_WORKSPACE']); R=os.environ['GITHUB_REPOSITORY']; O=T/'m3-cp4c0b-tb-s1-result'; P=T/'package'; Z=T/'package.zip'
for p in (O,P): shutil.rmtree(p,ignore_errors=True); p.mkdir(parents=True)
(O/'gate').mkdir(); (O/'diagnostic').mkdir()
A='9655632444'; H='c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f'; S='4bb467806df99c70889394a323c17c13bc185ca3'; GH='20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a'; DH='2550b9305284986c0af26677a881396bbeb61fd58304cdbbaac432c81da12806'; DID='ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating'
EX={'directional_benchmarks','directional_compiled_api_tests','directional_surface_cell_authority_kernel_tests','directional_surface_cell_completion_tests','directional_surface_cell_producer_tests','directional_surface_cell_validation_tests'}
try:
 with Z.open('wb') as z: subprocess.run(['gh','api','--method','GET',f'repos/{R}/actions/artifacts/{A}/zip'],stdout=z,check=True)
 if sha(Z)!=H: raise RuntimeError(f'package sha mismatch {sha(Z)}')
 subprocess.run(['unzip','-q',str(Z),'-d',str(P)],check=True)
 names={p.name for p in (P/'bin').iterdir()}; modes={p.name:oct(stat.S_IMODE(p.stat().st_mode)) for p in (P/'bin').iterdir()}
 if names!=EX: raise RuntimeError(f'executable inventory mismatch: {sorted(names)}')
 if not all(stat.S_IMODE((P/'bin'/n).stat().st_mode)&0o111 and os.access(P/'bin'/n,os.X_OK) for n in names): raise RuntimeError(f'archived executable mode missing: {modes}')
 for x in (P/'SHA256SUMS').read_text().splitlines():
  h,r=x.split('  ',1)
  if sha(P/r)!=h: raise RuntimeError(f'manifest mismatch: {r}')
 if (P/'metadata/source-commit.txt').read_text().strip()!=S: raise RuntimeError('source commit mismatch')
 boundary=(P/'metadata/command-boundary.txt').read_text()
 if not all(x in boundary for x in ('runtimeExecution=false','turnBoundary=Code+Build-only','exactArithmeticBackend=GMP')): raise RuntimeError('package boundary mismatch')
 ge=(P/'metadata/gmp-evidence.txt').read_text()
 if 'libgmpxx.so' not in ge or 'libgmp.so' not in ge: raise RuntimeError('GMP evidence missing')
 if any(x.read_bytes() for x in (P/'metadata').glob('source-status-*.txt')): raise RuntimeError('source status dirty')
 for x in list(W.iterdir()): shutil.rmtree(x) if x.is_dir() else x.unlink()
 subprocess.run(['tar','-xzf',str(P/'source'/f'source-{S}.tar.gz'),'-C',str(W)],check=True)
 gate_sel=W/'.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt'; diag_sel=W/'.agents/Directional/Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt'; gids=[x for x in gate_sel.read_text().splitlines() if x]; dids=[x for x in diag_sel.read_text().splitlines() if x]
 if sha(gate_sel)!=GH or len(gids)!=346 or len(set(gids))!=346: raise RuntimeError('346 selector mismatch')
 if sha(diag_sel)!=DH or dids!=[DID]: raise RuntimeError('S1 selector mismatch')
 routes=route_map(W,gids,DID); pre={'packageZip':sha(Z),'package':inv(P),'source':inv(W),'fixtures':inv(W,'benchmarks/fixtures'),'gateSelector':sha(gate_sel),'diagnosticSelector':sha(diag_sel),'executableModes':modes}; (O/'preflight-inventory.json').write_text(json.dumps(pre,sort_keys=True))
 rows=[]; passed=0; exceptions=False
 for n,identity in enumerate(gids,1):
  r=run_one(P,identity,routes[identity],O/'gate'/f'{n:03d}'); exceptions|=r['cppException']; passed+=r['status']=='PASS'; rows.append({k:v for k,v in r.items() if k!='stdout'}); print(f'gate_identity ordinal={n} status={r["status"]} identity={identity}')
 (O/'gate-ledger.json').write_text(json.dumps(rows,sort_keys=True)); gate='PASS' if passed==346 and len(rows)==346 and not exceptions else 'RED'
 dr=run_one(P,DID,routes[DID],O/'diagnostic'/'s1-contact-census'); lines=[x for x in dr['stdout'].splitlines() if x.startswith('m3Cp4c0bS1;')]; (O/'s1-census-lines.txt').write_text(''.join(x+'\n' for x in lines)); records,review,unexpected=census_summary(lines); diag_ok=dr['status']=='PASS' and not dr['cppException'] and len(lines)==4 and not unexpected; diagnostic='PASS' if diag_ok else 'RED'; review|=not diag_ok
 (O/'s1-census.json').write_text(json.dumps({'identity':DID,'gateCredit':0,'execution':{k:v for k,v in dr.items() if k!='stdout'},'records':records,'unexpected':unexpected,'requiresIndependentReview':review},sort_keys=True,indent=2))
 post={'packageZip':sha(Z),'package':inv(P),'source':inv(W),'fixtures':inv(W,'benchmarks/fixtures'),'gateSelector':sha(gate_sel),'diagnosticSelector':sha(diag_sel),'executableModes':{p.name:oct(stat.S_IMODE(p.stat().st_mode)) for p in (P/'bin').iterdir()}}; immutable=pre==post
 ok=gate=='PASS' and diagnostic=='PASS' and immutable and not exceptions and not dr['cppException']; nxt='M3-CP4c-0b-TB-S1-REV' if ok and not review else 'M3-CP4c-0b-S1-REVIEW-PLAN'
 result={'turn':'M3-CP4c-0b-TB-S1-EXEC','packageArtifactId':int(A),'packageSource':S,'packageSha256':H,'exactArithmeticBackend':'GMP','gate':{'required':346,'executed':len(rows),'passed':passed,'status':gate},'diagnostic':{'selectorSha256':DH,'identity':DID,'gateCredit':0,'status':diagnostic,'censusLineCount':len(lines),'requiresIndependentReview':review,'unexpected':unexpected},'cppExceptionSeen':exceptions or dr['cppException'],'repositoryTimeoutConfigured':False,'mutations':{'package':False,'source':False,'test':False,'fixture':False,'selector':False},'configure':False,'compile':False,'relink':False,'repair':False,'generatedDiscovery':False,'postflight':'PASS' if immutable else 'RED','requiredNext':nxt,'executionStatus':'PASS' if ok else 'RED'}
 (O/'result.json').write_text(json.dumps(result,sort_keys=True,indent=2)); print(json.dumps(result,sort_keys=True)); sys.exit(0 if ok else 4)
except Exception as e:
 (O/'orchestration-failure.txt').write_text(f'{type(e).__name__}: {e}\n'); raise
