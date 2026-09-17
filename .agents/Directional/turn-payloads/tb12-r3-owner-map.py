#!/usr/bin/env python3
import csv,pathlib,re,sys
root=pathlib.Path(sys.argv[1]); selector=pathlib.Path(sys.argv[2]); out=pathlib.Path(sys.argv[3])
cm=(root/'cmake/DirectionalTests.cmake').read_text()
tg=['directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests']
def cpp(s): return [x.strip() for x in s.splitlines() if x.strip().endswith('.cpp')]
pm=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)\n\nadd_executable',cm,re.S)
if not pm: raise SystemExit('producer set missing')
targets={tg[1]:cpp(pm.group(1))}
for t in [tg[0],tg[2],tg[3]]:
 m=re.search(r'add_executable\(\s*'+re.escape(t)+r'(.*?)\)\s*\n',cm,re.S)
 if not m: raise SystemExit('target block missing '+t)
 targets[t]=cpp(m.group(1))
pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')
own={}
for t,fs in targets.items():
 for f in fs:
  p=root/f
  if not p.is_file(): raise SystemExit('owner source missing '+f)
  for a,b in pat.findall(p.read_text(errors='replace')): own.setdefault(a+'.'+b,[]).append(t)
ids=[x for x in selector.read_text().splitlines() if x]
rows=[]; counts={t:0 for t in tg}
for i,x in enumerate(ids,1):
 got=own.get(x,[])
 if len(got)!=1: raise SystemExit(f'owner count {len(got)} for {i}:{x}')
 rows.append((i,x,got[0])); counts[got[0]]+=1
if len(rows)!=426 or [counts[x] for x in tg]!=[30,280,75,41]: raise SystemExit(f'owner census drift {len(rows)} {counts}')
with out.open('w',newline='') as f:
 w=csv.writer(f,delimiter='\t'); w.writerow(['ordinal','identity','binary']); w.writerows(rows)
print('owner_count=426; authority=30; producer=280; completion=75; validation=41')
