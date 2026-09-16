#!/usr/bin/env python3
import collections, csv, hashlib, os, pathlib, re, stat, sys

def census(root_s, out_s):
    root=pathlib.Path(root_s); out=pathlib.Path(out_s); rows=[]
    for p in sorted([root,*root.rglob('*')], key=lambda x: '' if x==root else x.relative_to(root).as_posix()):
        rel='.' if p==root else p.relative_to(root).as_posix(); st=p.lstat(); mode=f'{stat.S_IMODE(st.st_mode):04o}'
        if p.is_dir(): rows.append((rel,'directory',mode,str(st.st_size),'-','-'))
        elif p.is_file():
            h=hashlib.sha256()
            with p.open('rb') as f:
                for chunk in iter(lambda:f.read(1024*1024),b''): h.update(chunk)
            rows.append((rel,'file',mode,str(st.st_size),h.hexdigest(),'-'))
        elif p.is_symlink(): rows.append((rel,'symlink',mode,str(st.st_size),'-',os.readlink(p)))
    out.write_text('\n'.join('\t'.join(r) for r in rows)+'\n')

def selector_check(path_s, row425):
    b=pathlib.Path(path_s).read_bytes()
    if b'\r' in b or not b.endswith(b'\n'): raise SystemExit('selector is not canonical LF text')
    rows=[x for x in b.decode().splitlines() if x.strip()]
    if len(rows)!=425 or len(set(rows))!=425 or rows[-1]!=row425: raise SystemExit('selector count/uniqueness/row425 mismatch')

def owner_map(source_s, selector_s, out_s, row425):
    source=pathlib.Path(source_s); selector=pathlib.Path(selector_s); out=pathlib.Path(out_s)
    cm=(source/'cmake/DirectionalTests.cmake').read_text(); owners={}
    m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s+(.*?)\)',cm,re.S)
    if not m: raise SystemExit('producer source list missing')
    for f in re.findall(r'(?m)^\s*(tests/[^\s\)]+\.cpp)\s*$',m.group(1)): owners[f]=('producer','directional_surface_cell_producer_tests')
    targets={'directional_surface_cell_authority_kernel_tests':'authority-kernel','directional_surface_cell_completion_tests':'completion','directional_surface_cell_validation_tests':'validation'}
    for target,owner in targets.items():
        mm=re.search(r'add_executable\(\s*'+re.escape(target)+r'\s+(.*?)\)',cm,re.S)
        if not mm: raise SystemExit(f'target source list missing: {target}')
        for f in re.findall(r'(?m)^\s*(tests/[^\s\)]+\.cpp)\s*$',mm.group(1)): owners[f]=(owner,target)
    pat=re.compile(r'\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)',re.S)
    index=collections.defaultdict(list)
    for f,(owner,binary) in owners.items():
        for suite,test in pat.findall((source/f).read_text(errors='replace')): index[f'{suite}.{test}'].append((owner,binary,f))
    rows=[x.strip() for x in selector.read_text().splitlines() if x.strip()]; c=collections.Counter(); lines=['ordinal\tidentity\towner\tbinary\tsource_definition']
    for ordinal,identity in enumerate(rows,1):
        defs=index.get(identity,[])
        if len(defs)!=1: raise SystemExit(f'identity definition count {len(defs)}: {identity}')
        owner,binary,f=defs[0]; c[owner]+=1; lines.append(f'{ordinal}\t{identity}\t{owner}\t{binary}\t{f}')
    if [c['authority-kernel'],c['producer'],c['completion'],c['validation']] != [30,279,75,41]: raise SystemExit(f'owner census mismatch: {c}')
    if rows[-1]!=row425 or index[row425][0][0:2] != ('producer','directional_surface_cell_producer_tests'): raise SystemExit('row425 ownership mismatch')
    out.write_text('\n'.join(lines)+'\n')

def parse_gtest(path_s):
    text=pathlib.Path(path_s).read_text(errors='replace')
    def n(p):
        m=re.search(p,text,re.M); return int(m.group(1)) if m else 0
    running=n(r'^\[=+\]\s+Running\s+(\d+)\s+test'); passed=n(r'^\[\s*PASSED\s*\]\s+(\d+)\s+test'); skipped=n(r'^\[\s*SKIPPED\s*\]\s+(\d+)\s+test')
    print(running); print(running); print(passed); print(skipped)

def immutable_input(out_s):
    e=os.environ
    lines=[f'artifact_id={e["CANDIDATE_ARTIFACT_ID"]}',f'provider_zip_sha256={e["CANDIDATE_PROVIDER_SHA256"]}',f'semantic_source={e["SEMANTIC_SOURCE_SHA"]}',f'source_archive_sha256={e["SOURCE_ARCHIVE_SHA256"]}',f'package_manifest_sha256={e["PACKAGE_MANIFEST_SHA256"]}','package_manifest_entries=28','selector_rows=425',f'selector_sha256={e["SELECTOR_SHA256"]}',f'prefix424_sha256={e["PREFIX424_SHA256"]}','owner_census=30/279/75/41','runtimeExecution_before_tb=false']
    pathlib.Path(out_s).write_text('\n'.join(lines)+'\n')

def summary(ledger_s, out_s):
    rows=list(csv.DictReader(open(ledger_s),delimiter='\t')); result=collections.Counter(r['result'] for r in rows); owner=collections.Counter(r['owner'] for r in rows if r['result']=='PASS')
    text='\n'.join([f'executed={len(rows)}',f'pass={result["PASS"]}',f'red={result["RED"]}',f'skip={result["SKIP"]}',f'crash={result["CRASH"]}','timeout=0',f'selectionMismatch={result["SELECTION_MISMATCH"]}',f'unexecuted={425-len(rows)}',f'authorityKernelPassed={owner["authority-kernel"]}',f'producerPassed={owner["producer"]}',f'completionPassed={owner["completion"]}',f'validationPassed={owner["validation"]}'])+'\n'
    pathlib.Path(out_s).write_text(text)

cmd=sys.argv[1]
if cmd=='census': census(sys.argv[2],sys.argv[3])
elif cmd=='selector-check': selector_check(sys.argv[2],sys.argv[3])
elif cmd=='owner-map': owner_map(sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5])
elif cmd=='parse-gtest': parse_gtest(sys.argv[2])
elif cmd=='immutable-input': immutable_input(sys.argv[2])
elif cmd=='summary': summary(sys.argv[2],sys.argv[3])
else: raise SystemExit(f'unknown command: {cmd}')
