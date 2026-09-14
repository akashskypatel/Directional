#!/usr/bin/env python3
from pathlib import Path
import argparse,csv,datetime,hashlib,json,os,subprocess,time

def iso(): return datetime.datetime.now(datetime.timezone.utc).isoformat().replace('+00:00','Z')
def sha(p):
 h=hashlib.sha256();
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''): h.update(b)
 return h.hexdigest()
def main():
 ap=argparse.ArgumentParser(); ap.add_argument('--work',required=True); ap.add_argument('--evidence',required=True); a=ap.parse_args()
 work,evid=Path(a.work),Path(a.evidence); execv=work/'execution-view'; rawdir=evid/'raw'; rawdir.mkdir(exist_ok=True)
 rows=list(csv.DictReader(open(evid/'owner-map.tsv'),delimiter='\t')); ledger=[]
 for row in rows:
  n=int(row['ordinal']); ident=row['identity']; binary=execv/'bin'/row['binary']; log=rawdir/f'{n:03d}.log'; start=iso(); t0=time.monotonic()
  cmd=['timeout','-k','5s','180s',str(binary),f'--gtest_filter={ident}','--gtest_color=no']
  p=subprocess.run(cmd,cwd=execv/'bin',stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,errors='replace'); elapsed=time.monotonic()-t0; end=iso(); out=p.stdout; log.write_text(out)
  runids=[]
  for line in out.splitlines():
   if line.startswith('[ RUN      ] '): runids.append(line[len('[ RUN      ] '):].strip())
  selected=len(runids); mismatch=(selected!=1 or (selected==1 and runids[0]!=ident)); timeout=(p.returncode in (124,137))
  skipped=any(line.startswith('[  SKIPPED ] '+ident) for line in out.splitlines())
  failed=any(line.startswith('[  FAILED  ] '+ident) for line in out.splitlines())
  if timeout: result='TIMEOUT'
  elif mismatch: result='SELECTION_MISMATCH'
  elif skipped: result='SKIP'
  elif p.returncode==0 and not failed: result='PASS'
  else: result='RED'
  ledger.append({'ordinal':n,'identity':ident,'owner':row['owner'],'binary':row['binary'],'command':' '.join(cmd),'start_utc':start,'end_utc':end,'elapsed_seconds':f'{elapsed:.6f}','exit':p.returncode,'timeout':int(timeout),'selected':selected,'actual':','.join(runids),'result':result,'raw_log':log.name})
  print(f'{n:03d}/423 {result} exit={p.returncode} selected={selected} {ident}',flush=True)
 with open(evid/'ledger.tsv','w',newline='') as f:
  fields=list(ledger[0]); w=csv.DictWriter(f,fieldnames=fields,delimiter='\t',lineterminator='\n'); w.writeheader(); w.writerows(ledger)
 non=[r for r in ledger if r['result']!='PASS'];
 with open(evid/'non-pass.tsv','w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(ledger[0]),delimiter='\t',lineterminator='\n'); w.writeheader(); w.writerows(non)
 c={x:sum(r['result']==x for r in ledger) for x in ['PASS','RED','SKIP','TIMEOUT','SELECTION_MISMATCH']}; pfx=sum(r['result']=='PASS' for r in ledger[:422]); app=sum(r['result']=='PASS' for r in ledger[422:])
 summary={'selector_expected':423,'processes_executed':len(ledger),'pass':c['PASS'],'red':c['RED'],'skip':c['SKIP'],'timeout':c['TIMEOUT'],'selection_mismatch':c['SELECTION_MISMATCH'],'inherited422_pass':pfx,'appended_row423_pass':app,'mechanically_green':len(ledger)==423 and c=={'PASS':423,'RED':0,'SKIP':0,'TIMEOUT':0,'SELECTION_MISMATCH':0} and pfx==422 and app==1}
 (evid/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
 print('SUMMARY '+json.dumps(summary,sort_keys=True),flush=True)
if __name__=='__main__': main()
