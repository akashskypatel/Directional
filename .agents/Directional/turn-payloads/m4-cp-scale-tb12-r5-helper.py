#!/usr/bin/env python3
import collections,csv,hashlib,os,pathlib,re,stat,sys
SELECTOR_TOTAL=426
TOTAL=436
EXPECTED_CENSUS=[30,280,75,41]
ROW426='M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate'
FOCUSED=[
 ('A0',1,'FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle'),
 ('A0',2,'FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts'),
 ('A0',3,'FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle'),
 ('A0',4,'FieldTransportAtlas.PublishesCheckedSingularityPortAttachments'),
 ('A0',5,'FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings'),
 ('A',1,'FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents'),
 ('A',2,'FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence'),
 ('A',3,'FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper'),
 ('A',4,'FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow'),
 ('S5',1,'M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology'),
]

def sha(p):
 h=hashlib.sha256()
 with open(p,'rb') as f:
  for c in iter(lambda:f.read(1<<20),b''): h.update(c)
 return h.hexdigest()

def census(root_s,out_s):
 root=pathlib.Path(root_s); rows=[]
 ps=[root,*root.rglob('*')]; ps.sort(key=lambda p:'' if p==root else p.relative_to(root).as_posix())
 for p in ps:
  rel='.' if p==root else p.relative_to(root).as_posix(); st=p.lstat(); mode=f'{stat.S_IMODE(st.st_mode):04o}'
  if p.is_dir(): rows.append((rel,'directory',mode,str(st.st_size),'-','-'))
  elif p.is_file(): rows.append((rel,'file',mode,str(st.st_size),sha(p),'-'))
  elif p.is_symlink(): rows.append((rel,'symlink',mode,str(st.st_size),'-',os.readlink(p)))
 pathlib.Path(out_s).write_text('\n'.join('\t'.join(r) for r in rows)+'\n')

def selector_check(path_s,prefix_sha):
 p=pathlib.Path(path_s); b=p.read_bytes()
 if b'\r' in b or not b.endswith(b'\n'): raise SystemExit('selector not canonical LF text')
 rows=b.decode().splitlines()
 if len(rows)!=SELECTOR_TOTAL or any(not x.strip() for x in rows) or len(set(rows))!=SELECTOR_TOTAL: raise SystemExit('selector row/count/uniqueness mismatch')
 if rows[-1]!=ROW426: raise SystemExit('selector row426 identity mismatch')
 if hashlib.sha256(('\n'.join(rows[:425])+'\n').encode()).hexdigest()!=prefix_sha: raise SystemExit('selector first425 hash mismatch')

def ownership(source):
 cm=(source/'cmake/DirectionalTests.cmake').read_text(); owners={}
 m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s+(.*?)\)',cm,re.S)
 if not m: raise SystemExit('producer source list missing')
 for f in re.findall(r'(?m)^\s*(tests/[^\s\)]+\.cpp)\s*$',m.group(1)): owners[f]=('producer','directional_surface_cell_producer_tests')
 for binary,owner in {'directional_surface_cell_authority_kernel_tests':'authority-kernel','directional_surface_cell_completion_tests':'completion','directional_surface_cell_validation_tests':'validation'}.items():
  mm=re.search(r'add_executable\(\s*'+re.escape(binary)+r'\s+(.*?)\)',cm,re.S)
  if not mm: raise SystemExit('target source list missing: '+binary)
  for f in re.findall(r'(?m)^\s*(tests/[^\s\)]+\.cpp)\s*$',mm.group(1)): owners[f]=(owner,binary)
 pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)',re.S)
 idx=collections.defaultdict(list)
 for f,(owner,binary) in owners.items():
  for s,t in pat.findall((source/f).read_text(errors='replace')): idx[f'{s}.{t}'].append((owner,binary,f))
 return idx

def resolve(idx,identity):
 d=idx.get(identity,[])
 if len(d)!=1: raise SystemExit(f'owner definition count {len(d)}: {identity}')
 return d[0]

def init_all(source_s,selector_s,owner_out,ledger_out):
 source=pathlib.Path(source_s); rows=pathlib.Path(selector_s).read_text().splitlines(); idx=ownership(source); c=collections.Counter()
 oh=['phase\tphase_ordinal\tidentity\towner\tbinary\tsource_definition']
 entries=[]; g=0
 for phase,n,i in FOCUSED:
  o,b,f=resolve(idx,i); oh.append(f'{phase}\t{n}\t{i}\t{o}\t{b}\t{f}'); g+=1
  entries.append((g,phase,n,i,o,b,f))
 for n,i in enumerate(rows,1):
  o,b,f=resolve(idx,i); c[o]+=1; g+=1; entries.append((g,'SELECTOR426',n,i,o,b,f))
 actual=[c['authority-kernel'],c['producer'],c['completion'],c['validation']]
 if actual!=EXPECTED_CENSUS: raise SystemExit(f'owner census mismatch: {actual}')
 pathlib.Path(owner_out).write_text('\n'.join(oh)+'\n')
 hdr=['global_ordinal','phase','phase_ordinal','identity','owner','binary','source_definition','command','exit','selected','executed','passed','skipped','elapsed_ms','result','stdout','stderr','stdout_sha256','stderr_sha256']
 with open(ledger_out,'w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=hdr,delimiter='\t'); w.writeheader()
  for g,phase,n,i,o,b,s in entries:
   w.writerow({'global_ordinal':g,'phase':phase,'phase_ordinal':n,'identity':i,'owner':o,'binary':b,'source_definition':s,'command':'','exit':'','selected':'0','executed':'0','passed':'0','skipped':'0','elapsed_ms':'0','result':'UNEXECUTED','stdout':'','stderr':'','stdout_sha256':'','stderr_sha256':''})
 if g!=TOTAL: raise SystemExit(f'ledger total mismatch: {g}')

def parse_gtest(path_s):
 text=pathlib.Path(path_s).read_text(errors='replace')
 m=re.search(r'^\[=+\]\s+Running\s+(\d+)\s+test',text,re.M); selected=int(m.group(1)) if m else 0
 executed=len(re.findall(r'^\[ RUN\s+\]',text,re.M)); passed=len(re.findall(r'^\[\s*OK\s+\]',text,re.M)); skipped=len(re.findall(r'^\[\s*SKIPPED\s*\]',text,re.M))
 print(selected); print(executed); print(passed); print(skipped)

def finalize(process_s,initial_s,out_s,summary_s):
 process=list(csv.DictReader(open(process_s),delimiter='\t')) if pathlib.Path(process_s).exists() else []
 initial=list(csv.DictReader(open(initial_s),delimiter='\t')); by={r['global_ordinal']:r for r in process}
 hdr=list(initial[0].keys()) if initial else []
 with open(out_s,'w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=hdr,delimiter='\t'); w.writeheader()
  for row in initial: w.writerow(by.get(row['global_ordinal'],row))
 r=collections.Counter(x['result'] for x in process); phases=collections.Counter((x['phase'],x['result']) for x in process)
 sel=[x for x in process if x['phase']=='SELECTOR426']; owners=collections.Counter(x['owner'] for x in sel if x['result']=='PASS')
 summary=[
  f'executed={len(process)}',f'pass={r["PASS"]}',f'red={r["RED"]}',f'skip={r["SKIP"]}',f'crash={r["CRASH"]}',f'selectionMismatch={r["SELECTION_MISMATCH"]}',f'unexecuted={TOTAL-len(process)}',
  f'a0Pass={phases[("A0","PASS")]}',f'aPass={phases[("A","PASS")]}',f's5Pass={phases[("S5","PASS")]}',f'selectorPass={phases[("SELECTOR426","PASS")]}',f'selectorExecuted={len(sel)}',
  f'authorityKernelPassed={owners["authority-kernel"]}',f'producerPassed={owners["producer"]}',f'completionPassed={owners["completion"]}',f'validationPassed={owners["validation"]}',
  'benchmarkExecuted=0'
 ]
 pathlib.Path(summary_s).write_text('\n'.join(summary)+'\n')

cmd=sys.argv[1]
if cmd=='census': census(sys.argv[2],sys.argv[3])
elif cmd=='selector-check': selector_check(sys.argv[2],sys.argv[3])
elif cmd=='init-all': init_all(sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5])
elif cmd=='parse-gtest': parse_gtest(sys.argv[2])
elif cmd=='finalize': finalize(sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5])
else: raise SystemExit('unknown command: '+cmd)
