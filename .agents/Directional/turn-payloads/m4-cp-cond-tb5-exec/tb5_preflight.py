#!/usr/bin/env python3
from pathlib import Path
import argparse, collections, hashlib, os, re, shutil, stat, subprocess, tarfile

ART_SHA='3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b'
SRC_SHA='07984711db59eaa228820e7d44e5552a652edadf'
SEL_SHA='4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343'
PFX_SHA='bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc'
ROW423='InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved'
SEL_REL='.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt'
BINS={
 'authority_kernel':'directional_surface_cell_authority_kernel_tests',
 'producer':'directional_surface_cell_producer_tests',
 'completion':'directional_surface_cell_completion_tests',
 'validation':'directional_surface_cell_validation_tests'}
SOURCES={
 'authority_kernel':['tests/FieldTransportAtlasTests.cpp','tests/SurfaceCellAuthorityKernelTests.cpp'],
 'producer':['tests/AdaptiveFeatureMapPhase11Tests.cpp','tests/AdaptiveTargetSizePhase12Tests.cpp','tests/BoundedMeshPreconditionerTests.cpp','tests/CrossFieldTransferTests.cpp','tests/FieldAlignedCurveNetworkTests.cpp','tests/GlobalConformityBaselineTests.cpp','tests/GlobalConformityPlanTests.cpp','tests/InputConditionerTests.cpp','tests/RegularizedCurvaturePhase1Tests.cpp','tests/SourceGridRecoveryAuthorityTests.cpp','tests/SurfaceCellDesignAcceptanceTests.cpp','tests/SurfaceCellREPackageTests.cpp','tests/SurfaceCellTransitionQuotientTests.cpp','tests/SurfaceCellsPhase10Tests.cpp'],
 'completion':['tests/FlowRepStrandsPhase15Tests.cpp','tests/PatchDescriptorMilestoneETests.cpp','tests/PureQuadCompletionPhase18Tests.cpp','tests/SurfaceArrangementRowIdentityTests.cpp','tests/SurfaceComplexSimplificationPhase17Tests.cpp'],
 'validation':['tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp','tests/SurfaceMeshOptimizerPhase19Tests.cpp','tests/SurfaceMeshOptimizerPhase20Tests.cpp','tests/SurfaceMeshOptimizerPhase21Tests.cpp','tests/SurfaceMeshOptimizerPhase22Tests.cpp']}
TEST_RE=re.compile(r'\bTEST(?:_F)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)',re.S)

def sha(p):
 h=hashlib.sha256()
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''): h.update(b)
 return h.hexdigest()

def census(root,out):
 root=Path(root); rows=[]
 for p in sorted(root.rglob('*'),key=lambda x:x.as_posix()):
  rel=p.relative_to(root).as_posix(); st=p.lstat(); mode=stat.S_IMODE(st.st_mode)
  if p.is_symlink(): rows.append(f'L\t{mode:04o}\t-\t{hashlib.sha256(os.readlink(p).encode()).hexdigest()}\t{rel}\n')
  elif p.is_file(): rows.append(f'F\t{mode:04o}\t{st.st_size}\t{sha(p)}\t{rel}\n')
 Path(out).write_text(''.join(rows))

def req(cond,msg):
 if not cond: raise SystemExit('PREFLIGHT: '+msg)

def main():
 ap=argparse.ArgumentParser(); ap.add_argument('--artifact',required=True); ap.add_argument('--package',required=True); ap.add_argument('--work',required=True); ap.add_argument('--evidence',required=True); a=ap.parse_args()
 art,pkg,work,evid=map(Path,[a.artifact,a.package,a.work,a.evidence]); evid.mkdir(parents=True,exist_ok=True)
 req(sha(art)==ART_SHA,'artifact SHA mismatch')
 r=subprocess.run(['sha256sum','-c','SHA256SUMS'],cwd=pkg,text=True,capture_output=True)
 (evid/'package-sha256sum-check.txt').write_text(r.stdout+r.stderr); req(r.returncode==0,'package SHA256SUMS failed')
 lines=[x for x in (pkg/'SHA256SUMS').read_text().splitlines() if x.strip()]; req(len(lines)==27,'package manifest count != 27'); req(not any('SHA256SUMS' in x.split(maxsplit=1)[-1] for x in lines),'manifest self-entry')
 req((pkg/'metadata/source-commit.txt').read_text().strip()==SRC_SHA,'source commit mismatch')
 for n in ['preflight-exit-code.txt','build-exit-code.txt']: req((pkg/'metadata'/n).read_text().strip()=='0',n+' nonzero')
 for n in ['source-status-before-configure.txt','source-status-preconfigure.txt','source-status-after-configure.txt','source-status-after-build.txt','source-status-final.txt']: req((pkg/'metadata'/n).read_bytes()==b'',n+' nonempty')
 cb=(pkg/'metadata/command-boundary.txt').read_text(); req('runtimeExecution=false' in cb,'runtimeExecution'); req('turnBoundary=Code+Build-only' in cb,'turnBoundary'); req('exactArithmeticBackend=GMP' in cb,'GMP boundary')
 ge=(pkg/'metadata/gmp-evidence.txt').read_text(); req('libgmpxx.so' in ge and 'libgmp.so' in ge,'GMP/GMPXX link evidence')
 src=work/'source'; shutil.rmtree(src,ignore_errors=True); src.mkdir(parents=True)
 tarpath=pkg/'source'/f'source-{SRC_SHA}.tar.gz'
 with tarfile.open(tarpath,'r:gz') as t: t.extractall(src,filter='data')
 selector=src/SEL_REL; raw=selector.read_bytes(); req(hashlib.sha256(raw).hexdigest()==SEL_SHA,'selector423 hash'); req(raw.endswith(b'\n') and b'\r' not in raw,'selector not LF terminated')
 ids=raw.decode().splitlines(); req(len(ids)==423,'selector count'); req(hashlib.sha256(('\n'.join(ids[:422])+'\n').encode()).hexdigest()==PFX_SHA,'first422 hash'); req(ids[422]==ROW423,'row423')
 owners=collections.defaultdict(list)
 for owner,files in SOURCES.items():
  for f in files:
   txt=(src/f).read_text(errors='strict')
   for s,n in TEST_RE.findall(txt): owners[s+'.'+n].append(owner)
 missing=[i for i in ids if len(owners[i])==0]; amb=[i for i in ids if len(owners[i])!=1]; req(not missing,'missing static owners: '+','.join(missing[:3])); req(not amb,'ambiguous static owners: '+','.join(amb[:3]))
 counts=collections.Counter(owners[i][0] for i in ids); req(counts==collections.Counter({'authority_kernel':30,'producer':277,'completion':75,'validation':41}),'owner census '+repr(counts))
 execv=work/'execution-view'; shutil.rmtree(execv,ignore_errors=True); shutil.copytree(pkg,execv,copy_function=shutil.copy2,symlinks=True)
 fixture_src=src/'benchmarks/fixtures'; fixture_dst=execv/'bin/test-data/benchmarks/fixtures'; fixture_dst.parent.mkdir(parents=True,exist_ok=True); shutil.copytree(fixture_src,fixture_dst,copy_function=shutil.copy2,symlinks=True)
 for owner,bn in BINS.items():
  p=execv/'bin'/bn; req(p.is_file() and os.access(p,os.X_OK),f'owner binary not executable: {bn}')
  ld=subprocess.run(['ldd',str(p)],text=True,capture_output=True); (evid/f'ldd-{owner}.txt').write_text(ld.stdout+ld.stderr); req(ld.returncode==0 and 'not found' not in ld.stdout+ld.stderr,f'ldd failed: {bn}')
 census(pkg,evid/'package-pre.tsv'); census(src,evid/'source-pre.tsv'); census(execv,evid/'execution-pre.tsv')
 with open(evid/'owner-map.tsv','w') as f:
  f.write('ordinal\tidentity\towner\tbinary\n')
  for k,i in enumerate(ids,1): f.write(f'{k}\t{i}\t{owners[i][0]}\t{BINS[owners[i][0]]}\n')
 (evid/'preflight.txt').write_text('\n'.join([f'artifact_sha256={ART_SHA}',f'source_sha={SRC_SHA}',f'selector423_sha256={SEL_SHA}',f'first422_sha256={PFX_SHA}','selector_count=423','owner_census=30/277/75/41','package_manifest=27/27','gmp_runtime=resolved','fixture_view=byte-preserving-copy-from-packaged-source','preflight=PASS'])+'\n')
 print('PREFLIGHT PASS package=27/27 selector=423 owner=30/277/75/41')
if __name__=='__main__': main()
