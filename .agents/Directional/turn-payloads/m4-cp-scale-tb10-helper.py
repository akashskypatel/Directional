#!/usr/bin/env python3
import collections,csv,hashlib,os,pathlib,re,stat,sys
FOCUS="M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate"

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
 if len(rows)!=425 or any(not x.strip() for x in rows) or len(set(rows))!=425: raise SystemExit('selector row/count/uniqueness mismatch')
 if hashlib.sha256(('\n'.join(rows[:424])+'\n').encode()).hexdigest()!=prefix_sha: raise SystemExit('selector first424 hash mismatch')

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
 allidx=collections.defaultdict(list)
 for p in (source/'tests').rglob('*.cpp'):
  rel=p.relative_to(source).as_posix()
  for s,t in pat.findall(p.read_text(errors='replace')): allidx[f'{s}.{t}'].append(rel)
 idx=collections.defaultdict(list)
 for f,(owner,binary) in owners.items():
  for s,t in pat.findall((source/f).read_text(errors='replace')): idx[f'{s}.{t}'].append((owner,binary,f))
 return idx,allidx

def owner_map(source_s,selector_s,out_s,focus_out):
 source=pathlib.Path(source_s); rows=pathlib.Path(selector_s).read_text().splitlines(); idx,allidx=ownership(source); c=collections.Counter(); lines=['ordinal\tidentity\towner\tbinary\tsource_definition']
 for n,i in enumerate(rows,1):
  d=idx.get(i,[])
  if len(d)!=1: raise SystemExit(f'owner definition count {len(d)}: {i}')
  o,b,f=d[0]; c[o]+=1; lines.append(f'{n}\t{i}\t{o}\t{b}\t{f}')
 actual=[c['authority-kernel'],c['producer'],c['completion'],c['validation']]
 if actual!=[30,279,75,41]: raise SystemExit(f'owner census mismatch: {actual}')
 pathlib.Path(out_s).write_text('\n'.join(lines)+'\n')
 defs=allidx.get(FOCUS,[]); owned=idx.get(FOCUS,[])
 if len(defs)!=1 or len(owned)!=1 or owned[0][:2]!=('producer','directional_surface_cell_producer_tests'): raise SystemExit(f'focus definition/owner mismatch: all={defs} owned={owned}')
 o,b,f=owned[0]; pathlib.Path(focus_out).write_text(f'identity={FOCUS}\nsourceDefinitionCount=1\nowner={o}\nbinary={b}\nsource_definition={f}\n')

def parse_gtest(path_s):
 text=pathlib.Path(path_s).read_text(errors='replace')
 def n(p):
  m=re.search(p,text,re.M); return int(m.group(1)) if m else 0
 r=n(r'^\[=+\]\s+Running\s+(\d+)\s+test'); print(r); print(r); print(n(r'^\[\s*PASSED\s*\]\s+(\d+)\s+test')); print(n(r'^\[\s*SKIPPED\s*\]\s+(\d+)\s+test'))

def receipt(stdout_s,out_s):
 text=pathlib.Path(stdout_s).read_text(errors='replace'); lines=[x for x in text.splitlines() if x.startswith('m4CpScaleS4Product;')]
 ok=len(lines)==1; line=lines[0] if ok else ''
 def block(name):
  m=re.search(r'(?:^|;)'+re.escape(name)+r'=\{([^}]*)\}',line)
  if not m: return None
  d={}
  for item in m.group(1).split(','):
   if '=' in item:
    k,v=item.split('=',1); d[k]=v
  return d
 def field(name):
  m=re.search(r'(?:^|;)'+re.escape(name)+r'=([^;]+)',line); return m.group(1) if m else None
 neg=block('negative'); pos=block('positive')
 ok=ok and neg=={'V':'48','E':'48','Fobs':'4','c':'4','s':'1','chi':'0','b1':'4','Freq':'3','reject':'true'}
 ok=ok and pos=={'V':'72','E':'76','Fobs':'4','c':'1','s':'1','chi':'0','b1':'5','Freq':'4','reject':'false'}
 ok=ok and field('enumerationInvariant')=='true' and field('decisionNeutral')=='true'
 nums={k:int(field(k)) if field(k) and field(k).isdigit() else -1 for k in ['productCandidateEvaluations','productEarlyRejects','productFullCertificationAttempts','referenceFullCertificationAttempts','bypassedFinalCertificationAttempts']}
 ok=ok and nums['productCandidateEvaluations']>0 and nums['productEarlyRejects']>0
 ok=ok and nums['bypassedFinalCertificationAttempts']==nums['productEarlyRejects']
 ok=ok and nums['referenceFullCertificationAttempts']==nums['productFullCertificationAttempts']+nums['bypassedFinalCertificationAttempts']
 ok=ok and nums['referenceFullCertificationAttempts']>nums['productFullCertificationAttempts']
 ok=ok and field('adversarialReject') in ('true','false')
 pathlib.Path(out_s).write_text('\n'.join([f'receiptCount={len(lines)}',f'requiredFieldsValid={str(ok).lower()}',*(f'{k}={v}' for k,v in nums.items()),f'receipt={line}'])+'\n')
 if not ok: raise SystemExit('focused structured receipt invalid')

def summary(ledger_s,out_s):
 rows=list(csv.DictReader(open(ledger_s),delimiter='\t')); r=collections.Counter(x['result'] for x in rows); o=collections.Counter(x['owner'] for x in rows if x['result']=='PASS'); ords=[int(x['ordinal']) for x in rows]
 pathlib.Path(out_s).write_text('\n'.join([f'executed={len(rows)}',f'pass={r["PASS"]}',f'red={r["RED"]}',f'skip={r["SKIP"]}',f'crash={r["CRASH"]}','timeout=0',f'selectionMismatch={r["SELECTION_MISMATCH"]}',f'unexecuted={425-len(rows)}',f'ordinalContiguous={str(ords==list(range(1,len(rows)+1))).lower()}',f'authorityKernelPassed={o["authority-kernel"]}',f'producerPassed={o["producer"]}',f'completionPassed={o["completion"]}',f'validationPassed={o["validation"]}'])+'\n')

def remainder(owner_s,out_s):
 rows=list(csv.DictReader(open(owner_s),delimiter='\t')); pathlib.Path(out_s).write_text('ordinal\tidentity\tstatus\n'+'\n'.join(f'{r["ordinal"]}\t{r["identity"]}\tUNEXECUTED' for r in rows)+'\n')

cmd=sys.argv[1]
if cmd=='census': census(sys.argv[2],sys.argv[3])
elif cmd=='selector-check': selector_check(sys.argv[2],sys.argv[3])
elif cmd=='owner-map': owner_map(sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5])
elif cmd=='parse-gtest': parse_gtest(sys.argv[2])
elif cmd=='receipt': receipt(sys.argv[2],sys.argv[3])
elif cmd=='summary': summary(sys.argv[2],sys.argv[3])
elif cmd=='remainder': remainder(sys.argv[2],sys.argv[3])
else: raise SystemExit('unknown command: '+cmd)
