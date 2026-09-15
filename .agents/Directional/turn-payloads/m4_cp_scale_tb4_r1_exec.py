#!/usr/bin/env python3
from m4_cp_scale_tb4_r1_exec_lib import *
try:
 z=root/'candidate.zip';
 with z.open('wb') as f: sh(['gh','api',f'repos/{os.environ["GITHUB_REPOSITORY"]}/actions/artifacts/{AID}/zip'],stdout=f)
 if sha(z)!=ZIP_SHA: raise RuntimeError('provider zip digest mismatch')
 sh(['unzip','-q',str(z),'-d',str(pkg)]); man=pkg/'SHA256SUMS'; rows=[x for x in man.read_text().splitlines() if x.strip()]
 if len(rows)!=28 or any(x.rstrip().endswith(' SHA256SUMS') for x in rows) or sha(man)!=MAN_SHA: raise RuntimeError('manifest authority mismatch')
 sh(['sha256sum','-c','SHA256SUMS'],cwd=pkg,stdout=(ev/'preflight-package-sha256-check.txt').open('wb'))
 if (pkg/'metadata/source-commit.txt').read_text().strip()!=SOURCE or (pkg/'metadata/build-exit-code.txt').read_text().strip()!='0' or (pkg/'metadata/preflight-exit-code.txt').read_text().strip()!='0': raise RuntimeError('compile metadata mismatch')
 for p in (pkg/'metadata').glob('source-status-*.txt'):
  if p.stat().st_size: raise RuntimeError(f'nonempty source status {p.name}')
 boundary=(pkg/'metadata/command-boundary.txt').read_text();
 for token in ['runtimeExecution=false','turnBoundary=Code+Build-only','exactArithmeticBackend=GMP','semanticContracts=compiled-not-executed','manifestExcludesSelf=true']:
  if token not in boundary.splitlines(): raise RuntimeError(f'missing boundary {token}')
 gmp=(pkg/'metadata/gmp-evidence.txt').read_text();
 if 'libgmpxx' not in gmp or 'libgmp' not in gmp: raise RuntimeError('GMP/GMPXX evidence missing')
 archives=list((pkg/'source').glob('source-*.tar.gz'))
 if len(archives)!=1 or sha(archives[0])!=SRC_AR_SHA: raise RuntimeError('source archive mismatch')
 sh(['tar','-xzf',str(archives[0]),'-C',str(src)]); selector=src/'.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt'; lines=selector.read_bytes().splitlines(keepends=True)
 if len(lines)!=423 or sha(selector)!=SEL_SHA or hashlib.sha256(b''.join(lines[:422])).hexdigest()!=FIRST_SHA: raise RuntimeError('selector mismatch')
 firstfile=src/'.agents/Directional/Architecture_M4_CP_COND_CB4_Required_Green_Selector_422.txt'
 if sha(firstfile)!=FIRST_SHA: raise RuntimeError('selector422 file mismatch')
 ids=[x.decode().rstrip('\n\r') for x in lines]; bins=[owner(x) for x in ids]; from collections import Counter
 if Counter(bins)!=Counter({'directional_surface_cell_authority_kernel_tests':30,'directional_surface_cell_producer_tests':277,'directional_surface_cell_completion_tests':75,'directional_surface_cell_validation_tests':41}): raise RuntimeError('owner census mismatch')
 for b in set(bins):
  if not (pkg/'bin'/b).is_file() or not os.access(pkg/'bin'/b,os.X_OK): raise RuntimeError(f'missing owner {b}')
 shutil.copytree(pkg/'bin',view/'bin',dirs_exist_ok=True,copy_function=shutil.copy2); shutil.copytree(pkg/'lib',view/'lib',dirs_exist_ok=True,copy_function=shutil.copy2); fixture_src=src/'benchmarks/fixtures'; fixture_dst=view/'test-data/benchmarks/fixtures'; shutil.copytree(fixture_src,fixture_dst,dirs_exist_ok=True,copy_function=shutil.copy2)
 assert_fixture_materialization(fixture_src,fixture_dst); write_preflight_censuses(); assert_preflight_census_contract(); (ev/'immutable-input.txt').write_text(f'artifact_id={AID}\nartifact_name={ANAME}\nprovider_zip_sha256={ZIP_SHA}\nsemantic_source={SOURCE}\nsource_archive_sha256={SRC_AR_SHA}\npackage_manifest_sha256={MAN_SHA}\npackage_manifest_entries=28\nselector_rows=423\nselector_sha256={SEL_SHA}\nfirst422_sha256={FIRST_SHA}\nowner_census=30/277/75/41\nruntimeExecution=true\n')
 ledger=[[str(i+1),ids[i],bins[i],'UNEXECUTED','','0','0','0',''] for i in range(423)]; write_ledger(ledger); state['preflight']=True
 state['runtime']=True; raw=ev/'raw/s2/focused.log'; rc,sel,ok,sk=execute(view/'bin/directional_surface_cell_producer_tests',FOCUS,run/'s2',raw,ev/'resources/s2/focused.time.txt'); fres='PASS' if rc==0 and sel==1 and ok==1 and sk==0 else ('SELECTION_MISMATCH' if sel!=1 else 'TIMEOUT' if rc in (124,137) else 'SKIP' if sk else 'RED'); state['focus']=fres; (ev/'s2-process-ledger.tsv').write_text(f'identity\texit\tselected\tok\tskipped\tresult\traw_log\n{FOCUS}\t{rc}\t{sel}\t{ok}\t{sk}\t{fres}\traw/s2/focused.log\n'); receipts='\n'.join(x for x in raw.read_text(errors='replace').splitlines() if x.startswith('m4CpScaleS2;'))+'\n'; (ev/'s2-receipts.txt').write_text(receipts)
 if fres!='PASS': postflight(); state['exit']=32; raise SystemExit(32)
 for i,(identity,binary) in enumerate(zip(ids,bins)):
  stem=f'ordinal-{i+1:03d}'; raw=ev/f'raw/selector/{stem}.log'; rc,sel,ok,sk=execute(view/'bin'/binary,identity,run/'selector'/stem,raw,ev/f'resources/selector/{stem}.time.txt'); res='SELECTION_MISMATCH' if sel!=1 else 'TIMEOUT' if rc in (124,137) else 'SKIP' if sk else 'PASS' if rc==0 and ok==1 else 'RED'; ledger[i]=[str(i+1),identity,binary,res,str(rc),str(sel),str(ok),str(sk),f'raw/selector/{stem}.log']; write_ledger(ledger); print(f'{i+1:03d}/423 {res} {identity}',flush=True)
  if res=='SELECTION_MISMATCH': state['exit']=31; postflight(); raise SystemExit(31)
 state['selector']=True; counts=Counter(r[3] for r in ledger); (ev/'selector423-summary.txt').write_text('\n'.join([f'total=423',f'pass={counts["PASS"]}',f'red={counts["RED"]}',f'skip={counts["SKIP"]}',f'timeout={counts["TIMEOUT"]}',f'selectionMismatch={counts["SELECTION_MISMATCH"]}',f'unexecuted={counts["UNEXECUTED"]}'])+'\n'); postflight(); state['exit']=0 if counts==Counter({'PASS':423}) else 40
except SystemExit as e:
 if state['exit']==99: state['exit']=int(e.code or 0)
except Exception as e:
 print('TB4_ERROR',repr(e),file=sys.stderr); state['exit']=96
finally:
 finalize()
sys.exit(state['exit'])
