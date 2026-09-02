#!/usr/bin/env python3
import hashlib,re,stat,sys,json
from pathlib import Path

def census(p):
    r=[]
    for x in sorted(p.rglob('*'),key=lambda z:z.relative_to(p).as_posix()):
        q=x.relative_to(p).as_posix(); st=x.lstat(); m=stat.S_IMODE(st.st_mode)
        if x.is_file(): r.append(f'F\t{m:04o}\t{st.st_size}\t{hashlib.sha256(x.read_bytes()).hexdigest()}\t{q}')
        elif x.is_dir(): r.append(f'D\t{m:04o}\t0\t-\t{q}')
    return '\n'.join(r)+'\n'

def preflight(p,s,o):
    bins=sorted(x for x in (p/'bin').glob('directional_*') if x.is_file())
    assert len(bins)==6 and all(stat.S_IMODE(x.stat().st_mode)==0o755 for x in bins)
    exp={373:'b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834',374:'d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f',375:'aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0',376:'6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8',377:'7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1',378:'86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8',379:'ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7'}
    sd=s/'.agents/Directional'; sel={}
    for n,h in exp.items():
        f=sd/f'Architecture_M3_CP4c3_Required_Green_Selector_{n}.txt'; b=f.read_bytes(); a=f.read_text().splitlines()
        assert len(a)==n and len(set(a))==n and hashlib.sha256(b).hexdigest()==h; sel[n]=a
    for n in range(373,379): assert sel[379][:n]==sel[n]
    assert hashlib.sha256(('\n'.join(sel[379][:365])+'\n').encode()).hexdigest()=='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
    diag='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'; assert diag not in sel[379]
    cm=(s/'cmake/DirectionalTests.cmake').read_text(); own={}
    m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)',cm,re.S); assert m
    for f in re.findall(r'tests/([^\s)]+\.cpp)',m[1]): own[f]='directional_surface_cell_producer_tests'
    for t in ('directional_surface_cell_authority_kernel_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests'):
        m=re.search(r'add_executable\(\s*'+re.escape(t)+r'\s+(.*?)\)',cm,re.S); assert m
        for f in re.findall(r'tests/([^\s)]+\.cpp)',m[1]): own[f]=t
    defs={}
    for f in (s/'tests').glob('*.cpp'):
        for m in re.finditer(r'\b(?:TEST|TEST_F|TEST_P)\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',f.read_text(errors='replace')):
            defs.setdefault(m[1]+'.'+m[2],[]).append(f.name)
    rows=[]
    for i,x in enumerate(sel[379],1):
        hits=[(f,own[f]) for f in defs.get(x,[]) if f in own]; assert len(hits)==1,(i,x,hits)
        rows.append((i,x,hits[0][1]))
    dh=[(f,own[f]) for f in defs.get(diag,[]) if f in own]; assert len(dh)==1,dh
    (o/'mapping.tsv').write_text(''.join(f'{i}\t{x}\t{t}\n' for i,x,t in rows))
    (o/'diagnostic-mapping.tsv').write_text(f'{diag}\t{dh[0][1]}\n')
    (o/'pre.census').write_text(census(p))

def analyze(p,o):
    post=census(p); (o/'post.census').write_text(post); assert post==(o/'pre.census').read_text()
    rows=[]
    for line in (o/'results.tsv').read_text().splitlines()[1:]:
        a=line.split('\t'); rows.append({'ordinal':int(a[0]),'identity':a[1],'target':a[2],'result':a[3],'credit':a[4],'exit':int(a[5])})
    assert len(rows)==379
    d1=all(x['result']=='PASS' for x in rows if x['ordinal']<=365)
    r366=rows[365]; text=(o/'ordinal-366.log').read_text(errors='replace')
    old=('rotationSystemReason=RotationRayOrderKeyCollision' in text and 'sourceVertex=47' in text)
    d2=not old
    ray_re=re.compile(r'rotationFanRay\[\d+\]=\{([^}]*)\}')
    rays=[]
    for body in ray_re.findall(text):
        kv={};
        for part in body.split(','):
            if '=' in part:
                k,v=part.split('=',1); kv[k]=v
        rays.append(kv)
    def ray(arc,trace,ori,origin):
        for x in rays:
            if x.get('arc')==str(arc) and x.get('trace')==str(trace) and x.get('orientation')==ori and x.get('originPortSourceVertex')==str(origin): return x
    a=ray(20,6,'Forward',47); b=ray(23,9,'Reverse',71)
    total5='rotationFanCensusTotal=5' in text; full='rotationFanCensusTruncated=false' in text
    sec_a=a.get('secondary') if a else None; sec_b=b.get('secondary') if b else None
    d3=bool(total5 and full and a and b and sec_a is not None and sec_b is not None and sec_a!=sec_b)
    residual=r366['result']=='RED'; moved=bool(residual and d2); d5=bool(d1 and d2 and d3)
    def last(key):
        vals=re.findall(r'(?:^|[;,])'+re.escape(key)+r'=([^;\n}]+)',text); return vals[-1] if vals else None
    keys=['sourceVertex','sourceEdge','sourceFace','rotationSystemReason','networkErrorCondition','traceEventPositionFailure','certificationAttempt','certificationCutEdges','nonDiscComponentCount','remainingAdmissibleEdgeCount','cutCandidateCount']
    details={k:last(k) for k in keys}
    relevant=[ln for ln in text.splitlines() if any(k in ln for k in ('NotProductionReady','Rotation','sourceVertex=','surface-cut-graph','TraceEvent','m3Cp4c'))]
    (o/'ordinal366-evidence.txt').write_text('\n'.join(relevant)+'\n')
    ord379=rows[378]
    data={'acceptedPrefix365':d1,'ordinal366Result':r366['result'],'ordinal366OldV47CollisionAbsent':d2,'ordinal366OldCollisionRepeat':old,'rotationFanCensusTotal5':total5,'rotationFanCensusFull':full,'formerRayASecondary':sec_a,'formerRayBSecondary':sec_b,'formerRaysDistinctSecondaryAndFiveRayRotation':d3,'ordinal366ResidualRedMoved':moved,'tb11CandidateClosureConjunction':d5,'ordinal366Details':details,'ordinal379Result':ord379['result'],'ordinal379Exit':ord379['exit'],'firstRedOrdinal':next((x['ordinal'] for x in rows if x['result']=='RED'),0),'passes':sum(x['result']=='PASS' for x in rows),'reds':sum(x['result']=='RED' for x in rows)}
    (o/'bj9-analysis.json').write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')
    print(json.dumps(data,sort_keys=True))

if __name__=='__main__':
    mode=sys.argv[1]; p=Path(sys.argv[2]); o=Path(sys.argv[3])
    if mode=='pre': preflight(p,Path(sys.argv[4]),o)
    elif mode=='post': analyze(p,o)
    else: raise SystemExit('bad mode')
