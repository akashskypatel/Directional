  route=[]
  for i,x in enumerate(ids,1): assert len(owners[x])==1,(i,x,owners[x]); route.append((i,x,next(iter(owners[x]))))
  for x in F3+[G5,H1,J3]: assert owners[x]=={'directional_surface_cell_producer_tests'},(x,owners[x])
  (out/'route.tsv').write_text(''.join(f'{i}\t{x}\t{t}\n' for i,x,t in route))
  pre_pkg=inventory(pkg); pre_src=inventory(W); pre_fix=inventory(W,'benchmarks/fixtures'); pre_sel=sha(selector); pre_exe=sha(pkg/'bin/directional_surface_cell_producer_tests')
  rows=[]; passed=pre316=pre328=0; first=0; orch=0
  for i,x,t in route:
    r=run1(x,t,out/'identity-results'/f'{i:03d}'); rows.append(r); print(f'gate_identity ordinal={i} status={r["status"]} identity={x}')
    if r['status']=='PASS': passed+=1; pre316+=i<=316; pre328+=i<=328
    elif r['status']=='ORCHESTRATION_RED': orch+=1
    if r['status']!='PASS' and not first: first=i
  gate='ORCHESTRATION_RED' if orch else ('PASS' if passed==338 else 'RED')
  f3=[]
  for x in F3:
    r=run1(x,'directional_surface_cell_producer_tests',out/'supplementals'/x.replace('.','_')); f3.append(r); orch+=r['status']=='ORCHESTRATION_RED'
  qpre=orch
  g=run1(G5,'directional_surface_cell_producer_tests',out/'g5'); h=run1(H1,'directional_surface_cell_producer_tests',out/'h1'); j=run1(J3,'directional_surface_cell_producer_tests',out/'j3')
  for r in (g,h,j): orch+=r['status']=='ORCHESTRATION_RED'
  gl=[x for x in g['log'].splitlines() if x.startswith('m3Cp4c0G5')]; hl=[x for x in h['log'].splitlines() if x.startswith('m3Cp4c0H1')]; jl=[x for x in j['log'].splitlines() if x.startswith('m3Cp4c0J3')]
  if len(gl)!=1: g['status']='ORCHESTRATION_RED'; orch+=1
  if len(hl)!=4: h['status']='ORCHESTRATION_RED'; orch+=1
  if len(jl)!=4: j['status']='ORCHESTRATION_RED'; orch+=1
  (out/'g5-outcome.txt').write_text('\n'.join(gl)+'\n'); (out/'h1-census.txt').write_text('\n'.join(hl)+'\n'); (out/'j3-census.txt').write_text('\n'.join(jl)+'\n')
  t1=next((r['status'] for r in rows if r['identity']==T1),'MISSING'); c1='PASS' if pre316==316 else 'RED'; c4='PASS' if t1=='PASS' else 'RED'; c2=c3='NOT_EVALUABLE'; qcred=False; qs='NOT_CREDITABLE'; qr='precondition_not_green'
  if gate=='PASS' and sum(r['status']=='PASS' for r in f3)==2 and qpre==0:
    qcred=True; qs='RED'; c2='RED'; qr='criterion2_sphere_network_not_published'; go=gl[0] if gl else ''
    if not go: qs='ORCHESTRATION_RED'; qr='g5_outcome_unavailable'
    elif ';fieldAlignedCurveNetwork=true;' in go:
      mt=re.search(r';traceCount=(\d+)',go); mi=re.search(r'TraceIntersection=(\d+)',go); n=int(mt.group(1)) if mt else -1; ni=int(mi.group(1)) if mi else -1
      c2='PASS' if n==24 else 'RED'; qr=f'criterion2_sphere_trace_count_{n}_expected_24'
      if c2=='PASS': c3='PASS' if ni>0 else 'RED'; qr='criterion3_sphere_terminal_trace_intersection_missing' if c3=='RED' else qr
      if c2=='PASS' and c3=='PASS' and c4=='PASS': qs='PASS'; qr='criteria1_to5_satisfied_with_criterion5_carried_unchanged'
      elif c2=='PASS' and c4!='PASS': qr='criterion4_frozen_crossover_identity_not_green'
  post_pkg=inventory(pkg); post_src=inventory(W); post_fix=inventory(W,'benchmarks/fixtures'); assert pre_pkg==post_pkg and pre_src==post_src and pre_fix==post_fix and pre_sel==sha(selector) and pre_exe==sha(pkg/'bin/directional_surface_cell_producer_tests') and sha(z)==ZSHA
  result={'turn':'M3-CP4c-0-TB-R6','semanticSource':SRC,'workflowControlSha':os.environ['GITHUB_SHA'],'runId':int(os.environ['GITHUB_RUN_ID']),'packageArtifactId':int(AID),'packageSha256':ZSHA,'sourceArchiveSha256':ASHA,'selector':{'required':338,'executed':338,'passed':passed,'sha256':SSHA,'first316Sha256':S316,'first328Sha256':S328,'prefix316Passed':pre316,'prefix328Passed':pre328,'firstRedOrdinal':first,'firstRedIdentity':ids[first-1] if first else 'none','gate':gate},'supplementalF3':{'executed':2,'passed':sum(r['status']=='PASS' for r in f3),'records':f3},'g5':{'credit':'none','status':g['status'],'outcome':gl},'h1':{'credit':'none','status':h['status'],'census':hl},'j3':{'credit':'none','status':j['status'],'census':jl},'q8':{'creditable':qcred,'status':qs,'reason':qr,'criterion1':c1,'criterion2':c2,'criterion3':c3,'criterion4':c4,'criterion5':'CARRIED_UNCHANGED_NOT_RERUN'},'orchestrationErrors':orch,'freshProcesses':343,'packageMutation':False,'sourceMutation':False,'testMutation':False,'fixtureMutation':False,'selectorMutation':False,'configure':False,'compile':False,'relink':False,'repair':False,'generatedDiscovery':False,'performanceBenchmark':False,'postflight':'PASS'}
  (out/'gate-ledger.json').write_text(json.dumps(rows,indent=2)); (out/'result.json').write_text(json.dumps(result,indent=2,sort_keys=True)); print(json.dumps(result,indent=2,sort_keys=True))
  sys.exit(5 if orch else 0)
except Exception as e:
  (out/'orchestration-failure.txt').write_text(f'{type(e).__name__}: {e}\n'); raise
