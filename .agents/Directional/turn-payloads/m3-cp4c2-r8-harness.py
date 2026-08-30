#!/usr/bin/env python3
import hashlib,json,os,selectors,subprocess,sys,time
binary,identity,prefix=sys.argv[1:4]
out=open(prefix+'.stdout','wb'); err=open(prefix+'.stderr','wb'); comb=open(prefix+'.combined','wb')
start=time.time_ns(); p=subprocess.Popen([binary,'--gtest_filter='+identity,'--gtest_color=no'],stdout=subprocess.PIPE,stderr=subprocess.PIPE,cwd=os.environ['GITHUB_WORKSPACE'])
sel=selectors.DefaultSelector()
for s,f in ((p.stdout,out),(p.stderr,err)): sel.register(s,selectors.EVENT_READ,f)
while sel.get_map():
  for key,_ in sel.select():
    b=os.read(key.fileobj.fileno(),65536)
    if b: key.data.write(b); key.data.flush(); comb.write(b); comb.flush()
    else: sel.unregister(key.fileobj)
rc=p.wait(); elapsed=(time.time_ns()-start)//1_000_000
out.close(); err.close(); comb.close()
def sha(path):
  h=hashlib.sha256()
  with open(path,'rb') as f:
    for b in iter(lambda:f.read(1<<20),b''): h.update(b)
  return h.hexdigest()
raw=open(prefix+'.combined','rb').read()
meta={'identity':identity,'binary':os.path.basename(binary),'returncode':rc,'elapsed_ms':elapsed,'run_count':raw.count(b'[ RUN      ]'),'stdout_sha256':sha(prefix+'.stdout'),'stderr_sha256':sha(prefix+'.stderr'),'combined_sha256':sha(prefix+'.combined')}
open(prefix+'.json','w').write(json.dumps(meta,sort_keys=True)+'\n'); print(json.dumps(meta,sort_keys=True))
