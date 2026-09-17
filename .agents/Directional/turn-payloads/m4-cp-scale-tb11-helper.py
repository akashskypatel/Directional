#!/usr/bin/env python3
import collections,csv,hashlib,os,pathlib,re,stat,sys
TOTAL=426
EXPECTED_CENSUS=[30,280,75,41]
ROW426='M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate'

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
 if len(rows)!=TOTAL or any(not x.strip() for x in rows) or len(set(rows))!=TOTAL: raise SystemExit('selector row/count/uniqueness mismatch')
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
 allidx=collections.defaultdict(list); idx=collections.defaultdict(list)
 for p in (source/'tests').rglob('*.cpp'):
  rel=p.relative_to(source).as_posix()
  for s,t in pat.findall(p.read_text(errors='replace')): allidx[f'{s}.{t}'].append(rel)
 for f,(owner,binary) in owners.items():
  for s,t in pat.findall((source/f).read_text(errors='replace')): idx[f'{s}.{t}'].append((owner,binary,f))
 return idx,allidx

def owner_map(source_s,selector_s,out_s):
 source=pathlib.Path(source_s); rows=pathlib.Path(selector_s).read_text().splitlines(); idx,allidx=ownership(source); c=collections.Counter(); lines=['ordinal\tidentity\towner\tbinary\tsource_definition']
 for n,i in enumerate(rows,1):
  d=idx.get(i,[])
  if len(d)!=1: raise SystemExit(f'owner definition count {len(d)}: {i}')
  o,b,f=d[0]; c[o]+=1; lines.append(f'{n}\t{i}\t{o}\t{b}\t{f}')
 actual=[c['authority-kernel'],c['producer'],c['completion'],c['validation']]
 if actual!=EXPECTED_CENSUS: raise SystemExit(f'owner census mismatch: {actual}')
 if lines[-1].split('\t')[1]!=ROW426 or lines[-1].split('\t')[2]!='producer': raise SystemExit('row426 owner mismatch')
 pathlib.Path(out_s).write_text('\n'.join(lines)+'\n')

def init_ledger(owner_s,out_s):
 rows=list(csv.DictReader(open(owner_s),delimiter='\t'))
 hdr=['ordinal','identity','owner','binary','source_definition','command','exit','selected','executed','passed','skipped','elapsed_ms','result','stdout','stderr']
 with open(out_s,'w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=hdr,delimiter='\t'); w.writeheader()
  for r in rows:
   w.writerow({**r,'command':'','exit':'','selected':'0','executed':'0','passed':'0','skipped':'0','elapsed_ms':'0','result':'UNEXECUTED','stdout':'','stderr':''})

def parse_gtest(path_s):
 text=pathlib.Path(path_s).read_text(errors='replace')
 m=re.search(r'^\[=+\]\s+Running\s+(\d+)\s+test',text,re.M); selected=int(m.group(1)) if m else 0
 executed=len(re.findall(r'^\[ RUN\s+\]',text,re.M)); passed=len(re.findall(r'^\[\s*OK\s+\]',text,re.M)); skipped=len(re.findall(r'^\[\s*SKIPPED\s*\]',text,re.M))
 print(selected); print(executed); print(passed); print(skipped)

def finalize(process_s,initial_s,out_s,summary_s):
 process=list(csv.DictReader(open(process_s),delimiter='\t')) if pathlib.Path(process_s).exists() else []
 initial=list(csv.DictReader(open(initial_s),delimiter='\t')); by={r['ordinal']:r for r in process}
 hdr=initial[0].keys() if initial else []
 with open(out_s,'w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=hdr,delimiter='\t'); w.writeheader()
  for row in initial: w.writerow(by.get(row['ordinal'],row))
 r=collections.Counter(x['result'] for x in by.values()); o=collections.Counter(x['owner'] for x in by.values() if x['result']=='PASS'); ords=[int(x['ordinal']) for x in process]
 row426=by.get(str(TOTAL),{}).get('result','UNEXECUTED')
 pathlib.Path(summary_s).write_text('\n'.join([f'executed={len(process)}',f'pass={r["PASS"]}',f'red={r["RED"]}',f'skip={r["SKIP"]}',f'crash={r["CRASH"]}','timeout=0',f'selectionMismatch={r["SELECTION_MISMATCH"]}',f'unexecuted={TOTAL-len(process)}',f'ordinalContiguous={str(ords==list(range(1,len(process)+1))).lower()}',f'authorityKernelPassed={o["authority-kernel"]}',f'producerPassed={o["producer"]}',f'completionPassed={o["completion"]}',f'validationPassed={o["validation"]}',f'row426={row426}'])+'\n')

cmd=sys.argv[1]
if cmd=='census': census(sys.argv[2],sys.argv[3])
elif cmd=='selector-check': selector_check(sys.argv[2],sys.argv[3])
elif cmd=='owner-map': owner_map(sys.argv[2],sys.argv[3],sys.argv[4])
elif cmd=='init-ledger': init_ledger(sys.argv[2],sys.argv[3])
elif cmd=='parse-gtest': parse_gtest(sys.argv[2])
elif cmd=='finalize': finalize(sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5])
else: raise SystemExit('unknown command: '+cmd)
