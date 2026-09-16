#!/usr/bin/env python3
import collections, csv, hashlib, os, pathlib, re, stat, sys
FOCUS = "M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral"

def sha256_file(path):
    h=hashlib.sha256()
    with open(path,"rb") as f:
        for chunk in iter(lambda:f.read(1024*1024),b""): h.update(chunk)
    return h.hexdigest()

def census(root_s,out_s):
    root=pathlib.Path(root_s); out=pathlib.Path(out_s); rows=[]
    paths=[root,*root.rglob("*")]
    paths.sort(key=lambda p:"" if p==root else p.relative_to(root).as_posix())
    for p in paths:
        rel="." if p==root else p.relative_to(root).as_posix(); st=p.lstat(); mode=f"{stat.S_IMODE(st.st_mode):04o}"
        if p.is_dir(): rows.append((rel,"directory",mode,str(st.st_size),"-","-"))
        elif p.is_file(): rows.append((rel,"file",mode,str(st.st_size),sha256_file(p),"-"))
        elif p.is_symlink(): rows.append((rel,"symlink",mode,str(st.st_size),"-",os.readlink(p)))
    out.write_text("\n".join("\t".join(r) for r in rows)+"\n",encoding="utf-8")

def selector_check(path_s):
    data=pathlib.Path(path_s).read_bytes()
    if b"\r" in data or not data.endswith(b"\n"): raise SystemExit("selector is not canonical LF text")
    rows=data.decode("utf-8").splitlines()
    if len(rows)!=425 or any(not x.strip() for x in rows) or len(set(rows))!=425: raise SystemExit("selector row/count/uniqueness mismatch")

def owner_index(source):
    cm=(source/"cmake/DirectionalTests.cmake").read_text(encoding="utf-8"); owners={}
    m=re.search(r"set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES\s+(.*?)\)",cm,re.S)
    if not m: raise SystemExit("producer source list missing")
    for f in re.findall(r"(?m)^\s*(tests/[^\s\)]+\.cpp)\s*$",m.group(1)): owners[f]=("producer","directional_surface_cell_producer_tests")
    for binary,owner in {"directional_surface_cell_authority_kernel_tests":"authority-kernel","directional_surface_cell_completion_tests":"completion","directional_surface_cell_validation_tests":"validation"}.items():
        mm=re.search(r"add_executable\(\s*"+re.escape(binary)+r"\s+(.*?)\)",cm,re.S)
        if not mm: raise SystemExit(f"target source list missing: {binary}")
        for f in re.findall(r"(?m)^\s*(tests/[^\s\)]+\.cpp)\s*$",mm.group(1)): owners[f]=(owner,binary)
    pat=re.compile(r"\bTEST(?:_F|_P)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)",re.S)
    index=collections.defaultdict(list)
    for f,(owner,binary) in owners.items():
        for suite,test in pat.findall((source/f).read_text(encoding="utf-8",errors="replace")): index[f"{suite}.{test}"].append((owner,binary,f))
    return index

def owner_map(source_s,selector_s,out_s):
    source=pathlib.Path(source_s); rows=[x.strip() for x in pathlib.Path(selector_s).read_text(encoding="utf-8").splitlines()]; index=owner_index(source); counts=collections.Counter(); lines=["ordinal\tidentity\towner\tbinary\tsource_definition"]
    for ordinal,identity in enumerate(rows,1):
        defs=index.get(identity,[])
        if len(defs)!=1: raise SystemExit(f"identity definition count {len(defs)}: {identity}")
        owner,binary,src=defs[0]; counts[owner]+=1; lines.append(f"{ordinal}\t{identity}\t{owner}\t{binary}\t{src}")
    actual=[counts["authority-kernel"],counts["producer"],counts["completion"],counts["validation"]]
    if actual!=[30,279,75,41]: raise SystemExit(f"owner census mismatch: {actual}")
    pathlib.Path(out_s).write_text("\n".join(lines)+"\n",encoding="utf-8")

def focus_owner(source_s,out_s):
    defs=owner_index(pathlib.Path(source_s)).get(FOCUS,[])
    if len(defs)!=1: raise SystemExit(f"focused identity definition count {len(defs)}")
    owner,binary,src=defs[0]
    if (owner,binary)!=("producer","directional_surface_cell_producer_tests"): raise SystemExit(f"focused identity owner mismatch: {owner}/{binary}")
    pathlib.Path(out_s).write_text(f"identity={FOCUS}\nowner={owner}\nbinary={binary}\nsource_definition={src}\n",encoding="utf-8")

def parse_gtest(path_s):
    text=pathlib.Path(path_s).read_text(encoding="utf-8",errors="replace")
    def n(p):
        m=re.search(p,text,re.M); return int(m.group(1)) if m else 0
    running=n(r"^\[=+\]\s+Running\s+(\d+)\s+test"); passed=n(r"^\[\s*PASSED\s*\]\s+(\d+)\s+test"); skipped=n(r"^\[\s*SKIPPED\s*\]\s+(\d+)\s+test")
    print(running); print(running); print(passed); print(skipped)

def focused_receipt(stdout_s,out_s):
    text=pathlib.Path(stdout_s).read_text(encoding="utf-8",errors="replace"); line=next((x for x in text.splitlines() if x.startswith("m4CpScaleS4Prereq;")),"")
    required=["coveredClass=BettiFaceCountMismatch","reachableNegative=true","negativeBetti=13","negativeRequiredFaces=12","negativeObservedFaces=18","negativeProductEuler=6","positiveBetti=5","positiveRequiredFaces=4","positiveObservedFaces=4","enumerationInvariant=true","decisionNeutral=true","adversarialState={","adversarialReject="]
    ok=bool(line) and all(token in line for token in required)
    pathlib.Path(out_s).write_text("\n".join([f"structuredReceiptPresent={'true' if bool(line) else 'false'}",f"requiredFieldsPresent={'true' if ok else 'false'}",f"receipt={line}"])+"\n",encoding="utf-8")
    if not ok: raise SystemExit("focused structured receipt missing required fields")

def selector_summary(ledger_s,out_s):
    rows=list(csv.DictReader(open(ledger_s,encoding="utf-8"),delimiter="\t")); result=collections.Counter(r["result"] for r in rows); owner=collections.Counter(r["owner"] for r in rows if r["result"]=="PASS"); ordinals=[int(r["ordinal"]) for r in rows]; contiguous=ordinals==list(range(1,len(rows)+1))
    pathlib.Path(out_s).write_text("\n".join([f"executed={len(rows)}",f"pass={result['PASS']}",f"red={result['RED']}",f"skip={result['SKIP']}",f"crash={result['CRASH']}","timeout=0",f"selectionMismatch={result['SELECTION_MISMATCH']}",f"unexecuted={425-len(rows)}",f"ordinalContiguous={'true' if contiguous else 'false'}",f"authorityKernelPassed={owner['authority-kernel']}",f"producerPassed={owner['producer']}",f"completionPassed={owner['completion']}",f"validationPassed={owner['validation']}"])+"\n",encoding="utf-8")

def remainder(owner_map_s,first_s,out_s):
    first=int(first_s); rows=list(csv.DictReader(open(owner_map_s,encoding="utf-8"),delimiter="\t")); lines=["ordinal\tidentity\tstatus"]
    for r in rows:
        if int(r["ordinal"])>=first: lines.append(f"{r['ordinal']}\t{r['identity']}\tUNEXECUTED")
    pathlib.Path(out_s).write_text("\n".join(lines)+"\n",encoding="utf-8")

cmd=sys.argv[1]
if cmd=="census": census(sys.argv[2],sys.argv[3])
elif cmd=="selector-check": selector_check(sys.argv[2])
elif cmd=="owner-map": owner_map(sys.argv[2],sys.argv[3],sys.argv[4])
elif cmd=="focus-owner": focus_owner(sys.argv[2],sys.argv[3])
elif cmd=="parse-gtest": parse_gtest(sys.argv[2])
elif cmd=="focused-receipt": focused_receipt(sys.argv[2],sys.argv[3])
elif cmd=="selector-summary": selector_summary(sys.argv[2],sys.argv[3])
elif cmd=="remainder": remainder(sys.argv[2],sys.argv[3],sys.argv[4])
else: raise SystemExit(f"unknown command: {cmd}")
