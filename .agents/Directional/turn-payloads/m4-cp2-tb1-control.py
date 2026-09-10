#!/usr/bin/env python3
import argparse, csv, pathlib, re, sys

def one(s, old, new):
    if s.count(old) != 1:
        raise SystemExit(f'replacement drift ({s.count(old)}): {old!r}')
    return s.replace(old, new)

def prepare(src, out):
    s=pathlib.Path(src).read_text()
    s=s.replace('first365','first373').replace('expected365','expected373')
    pairs=[
      ("EXPECTED_SOURCE_SHA='680f9f1573d3c7e56a273366436463e40e196131'","EXPECTED_SOURCE_SHA='eb23177e6ee9cbb27cf1ee30a299911abc0e1c60'"),
      ("SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP1_Required_Green_Selector_373.txt'","SELECTOR_RELATIVE_PATH='.agents/Directional/Architecture_M4_CP2_Required_Green_Selector_380.txt'"),
      ('EXPECTED_SELECTOR_COUNT=373','EXPECTED_SELECTOR_COUNT=380'),
      ('ACCEPTED_PREFIX_COUNT=365','ACCEPTED_PREFIX_COUNT=373'),('FOCUSED_FIRST=366','FOCUSED_FIRST=374'),('FOCUSED_LAST=373','FOCUSED_LAST=380'),
      ('if ordinal <= 365:','if ordinal <= 373:'),("'directional_surface_cell_producer_tests': 227,","'directional_surface_cell_producer_tests': 234,"),("'directional_surface_cell_producer_tests': 219,","'directional_surface_cell_producer_tests': 227,"),
      ('rows[365:373]','rows[373:380]'),('CP1 row not producer-owned','CP2 row not producer-owned'),("print('identity_count=373')","print('identity_count=380')"),('full373','full380'),
      ("-eq 373 ]] || fail_orchestration 'identity map count mismatch'","-eq 380 ]] || fail_orchestration 'identity map count mismatch'"),
      ('-eq 8 ]] || fail_orchestration "$phase did not execute 8 identities"','-eq 7 ]] || fail_orchestration "$phase did not execute 7 identities"'),
      ('-eq 8 ]] || fail_orchestration "$phase selection count mismatch"','-eq 7 ]] || fail_orchestration "$phase selection count mismatch"'),
      ("if len(full) != 373 or [int(r['ordinal']) for r in full] != list(range(1, 374)):","if len(full) != 380 or [int(r['ordinal']) for r in full] != list(range(1, 381)):") ,
      ("raise SystemExit('full ledger is not exactly ordinals 1..373')","raise SystemExit('full ledger is not exactly ordinals 1..380')"),('list(range(366, 374))','list(range(374, 381))'),('if n <= 365','if n <= 373'),
      ("cp1 = {int(r['ordinal']): r['result'] for r in full if int(r['ordinal']) >= 366}","cp2 = {int(r['ordinal']): r['result'] for r in full if int(r['ordinal']) >= 374}"),
      ("'total=373\\n'","'total=380\\n'"),("f'pass={373-len(red)}\\nred={len(red)}\\nred_ordinals={red}\\n'","f'pass={380-len(red)}\\nred={len(red)}\\nred_ordinals={red}\\n'"),
      ("f'accepted_prefix_pass={365-len(prefix_red)}/365\\naccepted_prefix_red_ordinals={prefix_red}\\n'","f'accepted_prefix_pass={373-len(prefix_red)}/373\\naccepted_prefix_red_ordinals={prefix_red}\\n'"),
      ("f'cp1_full_results={cp1}\\nfocused_a_results={a_results}\\nfocused_b_results={b_results}\\n'","f'cp2_full_results={cp2}\\nfocused_a_results={a_results}\\nfocused_b_results={b_results}\\n'"),
      ('focused CP1 twice plus full selector373','focused CP2 twice plus full selector380'),
      ('env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \\\n      "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"','"$EXEC_VIEW/bin/$binary" --gtest_filter="$identity" --gtest_color=no')]
    for a,b in pairs: s=one(s,a,b)
    s,n=re.subn(r"EXPECTED_SELECTOR_SHA256='[0-9a-f]{64}'", ': "${EXPECTED_SELECTOR_SHA256:?}"\n: "${EXPECTED_PREFIX_SHA256:?}"', s, count=1)
    if n != 1: raise SystemExit(f'selector hash replacement drift: {n}')
    n="[[ \"$(cat \"$PKG/metadata/preflight-exit-code.txt\")\" == '0' ]] || fail_orchestration 'compile preflight exit nonzero'\n"
    s=one(s,n,n+'for status_file in "$PKG"/metadata/source-status-*.txt; do\n  [[ -f "$status_file" && ! -s "$status_file" ]] || fail_orchestration "source status not clean: $(basename "$status_file")"\ndone\n')
    n="[[ \"$(sha_file \"$selector\")\" == \"$EXPECTED_SELECTOR_SHA256\" ]] || fail_orchestration 'selector digest mismatch'\n"
    s=one(s,n,n+'prefix_sha="$(head -n "$ACCEPTED_PREFIX_COUNT" "$selector" | sha256sum | awk \'{print $1}\')"\n[[ "$prefix_sha" == "$EXPECTED_PREFIX_SHA256" ]] || fail_orchestration "accepted-prefix digest mismatch: $prefix_sha"\n')
    n='census_tree "$SOURCE" "${RESULT}/source-census-before.tsv"\n'
    s=one(s,n,'find "$SOURCE" -type f -exec chmod a-w {} +\nfind "$SOURCE" -type d -exec chmod a-w {} +\n'+n)
    n='done\n\nfull_ledger="${RESULT}/ledger.tsv"'
    barrier="done\n\nif [[ \"$selection_integrity\" != true ]]; then postflight; fail_orchestration 'focused selection mismatch'; fi\nif [[ \"$timeout_count\" -ne 0 ]]; then postflight; fail_orchestration \"focused timeout count=$timeout_count\"; fi\n\nfull_ledger=\"${RESULT}/ledger.tsv\""
    s=one(s,n,barrier)
    pathlib.Path(out).write_text(s)

def audit(result_dir):
    root=pathlib.Path(result_dir); summary=root/'semantic-audit-summary.txt'; out=root/'semantic-audit.tsv'
    specs=[('focused-a',root/'focused-a-ledger.tsv',range(374,381)),('focused-b',root/'focused-b-ledger.tsv',range(374,381)),('full',root/'ledger.tsv',range(1,381))]
    if not all(p.exists() for _,p,_ in specs):
        summary.write_text('audit_status=unavailable\nreason=incomplete-ledgers\n'); return
    rows=[]
    elapsed_re=re.compile(r'^\s*Elapsed \(wall clock\) time.*:\s*(.+)$')
    for phase,ledger,expected in specs:
        data=list(csv.DictReader(ledger.open(),delimiter='\t'))
        if [int(r['ordinal']) for r in data] != list(expected): raise SystemExit(f'{phase} ordinal coverage mismatch')
        for r in data:
            raw=root/r['raw_log']; text=raw.read_text(errors='replace')
            selected=len(re.findall(r'^\[ RUN      \] ',text,re.M)); skipped=len(re.findall(r'^\[  SKIPPED \] ',text,re.M)); code=int(r['exit']); timeout=code in (124,137)
            result='RED'
            if selected==1 and code==0 and skipped==0: result='PASS'
            elif selected==1 and code==0 and skipped>0: result='SKIP'
            tf=root/'resources'/phase/f"ordinal-{int(r['ordinal']):03d}.time.txt"; elapsed=''
            if tf.exists():
                for line in tf.read_text(errors='replace').splitlines():
                    m=elapsed_re.match(line)
                    if m: elapsed=m.group(1); break
            rows.append(dict(phase=phase,ordinal=r['ordinal'],identity=r['identity'],binary=r['binary'],exit=str(code),selected=str(selected),skipped=str(skipped),timeout=str(timeout).lower(),elapsed_wall=elapsed,result=result))
    fields=list(rows[0]); f=out.open('w',newline=''); w=csv.DictWriter(f,fieldnames=fields,delimiter='\t'); w.writeheader(); w.writerows(rows); f.close()
    def subset(phase,lo=None,hi=None): return [r for r in rows if r['phase']==phase and (lo is None or lo<=int(r['ordinal'])<=hi)]
    def tally(rs): return {k:sum(r['result']==k for r in rs) for k in ('PASS','RED','SKIP')} | {'timeout':sum(r['timeout']=='true' for r in rs),'selection_mismatch':sum(r['selected']!='1' for r in rs)}
    full=subset('full'); pref=[r for r in full if int(r['ordinal'])<=373]; cp2=[r for r in full if int(r['ordinal'])>=374]; a=subset('focused-a'); b=subset('focused-b')
    lines=['audit_status=complete']
    for name,rs,total in [('full',full,380),('accepted_prefix',pref,373),('cp2',cp2,7),('focused_a',a,7),('focused_b',b,7)]:
        t=tally(rs); lines += [f'{name}_total={len(rs)}/{total}']+[f'{name}_{k.lower()}={v}' for k,v in t.items()]
    va=[(r['ordinal'],r['result']) for r in a]; vb=[(r['ordinal'],r['result']) for r in b]; lines.append(f'focused_vectors_equal={str(va==vb).lower()}')
    for owner in sorted({r['binary'] for r in full}):
        rs=[r for r in full if r['binary']==owner]; t=tally(rs); lines.append('owner='+owner+' total='+str(len(rs))+' '+' '.join(f'{k.lower()}={v}' for k,v in t.items()))
    summary.write_text('\n'.join(lines)+'\n')

def main():
    ap=argparse.ArgumentParser(); sp=ap.add_subparsers(dest='cmd',required=True); p=sp.add_parser('prepare'); p.add_argument('src'); p.add_argument('out'); a=sp.add_parser('audit'); a.add_argument('result')
    x=ap.parse_args(); prepare(x.src,x.out) if x.cmd=='prepare' else audit(x.result)
if __name__=='__main__': main()
