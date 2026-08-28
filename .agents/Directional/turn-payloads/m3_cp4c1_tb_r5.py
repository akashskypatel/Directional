from m3_cp4c1_tb_r5_lib import *
res={'turn':'M3-CP4c-1-TB-R5','runId':RID,'packageArtifactId':int(AID),'semanticSource':SSHA,'exactArithmeticBackend':'GMP','configureOccurred':False,'compileOccurred':False,'relinkOccurred':False,'repairOccurred':False,'generatedDiscoveryOccurred':False,'mutationOccurred':False,'performanceAcceptanceBenchmarkApplicable':False,'overall':'PENDING'}
try:
 with Z.open('wb') as f: run(['gh','api',f'/repos/{R}/actions/artifacts/{AID}/zip'],stdout=f)
 if sha(Z)!=ASHA: raise RuntimeError('package digest mismatch')
 run(['unzip','-q',str(Z),'-d',str(P)]); sums=(P/'SHA256SUMS').read_text().splitlines(); checked=0
 for line in sums:
  h,rel=line.split(None,1); rel=rel.lstrip('* '); q=P/rel
  if sha(q)!=h: raise RuntimeError('manifest mismatch '+rel)
  checked+=1
 if checked!=28: raise RuntimeError(f'manifest count {checked}')
 if (P/'metadata/source-commit.txt').read_text().strip()!=SSHA: raise RuntimeError('source mismatch')
 for n in ['preflight-exit-code.txt','build-exit-code.txt']:
  if (P/'metadata'/n).read_text().strip()!='0': raise RuntimeError(n)
 for n in ['source-status-preconfigure.txt','source-status-before-configure.txt','source-status-after-configure.txt','source-status-after-build.txt','source-status-final.txt']:
  if (P/'metadata'/n).read_text().strip(): raise RuntimeError('dirty '+n)
 if 'runtimeExecution=false' not in (P/'metadata/command-boundary.txt').read_text(): raise RuntimeError('boundary')
 if 'libgmp' not in (P/'metadata/gmp-evidence.txt').read_text(): raise RuntimeError('gmp evidence')
 arch=next((P/'source').glob('*.tar.gz'))
 if sha(arch)!=SARCH: raise RuntimeError('source archive digest')
 run(['tar','-xzf',str(arch),'-C',str(S)])
 reqp=S/'.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt'; ngp=S/'.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt'; req=reqp.read_text().splitlines(); ng=ngp.read_text().splitlines()
 if len(req)!=355 or sha(reqp)!=REQSHA or len(ng)!=3 or sha(ngp)!=NGSH: raise RuntimeError('selector authority')
 for n,h in PREF.items():
  if psha(req,n)!=h: raise RuntimeError(f'prefix {n}')
 if req[353]!=C4 or req[354]!=C5 or ng!=NG: raise RuntimeError('selector order')
 for x in RET:
  if x in req or x in ng: raise RuntimeError('retired identity survives selector')
 text=(S/'tests/FieldAlignedCurveNetworkTests.cpp').read_text(); c5=text[text.index('EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced'):text.index('TEST(TraceTerminationCorrection',text.index('EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced'))]
 static={'nonEmpty': 'ASSERT_FALSE(producedTerminalKinds.empty())' in c5,'traceIntersectionCheck': 'FieldAlignedNetworkEventKind::TraceIntersection' in c5 and 'EXPECT_EQ(1U, producedTerminalKinds.count' in c5,'mandatoryBarrierCheck':'FieldAlignedNetworkEventKind::MandatoryBarrierTermination' in c5 and c5.count('EXPECT_EQ(1U, producedTerminalKinds.count')>=2}
 if not all(static.values()): raise RuntimeError('W3 source form')
 preP=inv(P); preS=inv(S); (O/'pre-package-inventory.json').write_text(json.dumps(preP,sort_keys=True)); (O/'pre-source-inventory.json').write_text(json.dumps(preS,sort_keys=True))
 routes=route(S,req+NG+[EXTRA]); rm={x:t for _,x,t in routes}; rows=[]; zeros=0; firstRed=None; exc=0
 for i,x,t in routes[:355]:
  r=one(x,t,O/'required'/f'{i:03d}'); rows.append(r); zeros+=r['selected']!=1; exc+=r['cppException']; firstRed=firstRed or (i if r['status']!='PASS' else None)
 res['required']={'passCount':sum(x['status']=='PASS' for x in rows),'count':355,'zeroSelected':zeros,'cppExceptions':exc,'firstRedOrdinal':firstRed,'prefix316Pass':all(x['status']=='PASS' for x in rows[:316]),'prefix346Pass':all(x['status']=='PASS' for x in rows[:346]),'prefix353Pass':all(x['status']=='PASS' for x in rows[:353]),'c4':rows[353]['status'],'c5':rows[354]['status']}
 diag={}
 for x in NG+[EXTRA]: diag[x]=one(x,rm[x],O/'diagnostics'/re.sub(r'[^A-Za-z0-9]+','_',x))
 (O/'diagnostics.json').write_text(json.dumps(diag,indent=2))
 sphere=diag[NG[2]]['log']; torus=diag[NG[0]]['log']; mech=diag[NG[1]]['log']; two=diag[EXTRA]['log']
 def field(log,key):
  m=re.search(r'(?:^|;)'+re.escape(key)+r'=([^;\n\r}]*)',log); return m.group(1).strip() if m else None
 sp=field(sphere,'producedTerminalEventKinds'); tp=field(torus,'producedTerminalEventKinds'); mechA1=('IncompleteCycleBasis' in mech); twoBarrier=(field(two,'barrierTerminatingTraceCount')=='3' and 'MandatoryBarrierTermination=3' in two)
 union=[]; contributors={}
 if sp and sp!='none':
  for k in sp.split(','): union.append(int(k)); contributors.setdefault(int(k),[]).append('prescribed sphere')
 if tp and tp!='none':
  for k in tp.split(','): union.append(int(k)); contributors.setdefault(int(k),[]).append('torus')
 if twoBarrier: union.append(3); contributors.setdefault(3,[]).append('two-ring')
 union=sorted(set(union)); contributors={str(k):v for k,v in sorted(contributors.items())}
 w3={'traceIntersectionCheckExecutedAndPassed':rows[354]['status']=='PASS' and static['traceIntersectionCheck'],'mandatoryBarrierCheckExecutedAndPassed':rows[354]['status']=='PASS' and static['mandatoryBarrierCheck'],'proofBasis':'C5 PASS plus frozen source control-flow/static named-check presence','observedTerminalKindUnion':union,'contributors':contributors,'torusKinds':tp,'mechanicalIncompleteCycleBasis':mechA1,'twoRingBarrierEvidence':twoBarrier,'extraTwoRingStatus':diag[EXTRA]['status']}
 res['w3']=w3; res['nonGating']={x:{k:v for k,v in diag[x].items() if k!='log'} for x in NG}; res['retiredIdentitiesAbsent']=all(x not in req and x not in ng and x not in text for x in RET)
 postP=inv(P); postS=inv(S); res['immutablePostflight']={'packageMatch':preP==postP,'sourceMatch':preS==postS}; (O/'post-package-inventory.json').write_text(json.dumps(postP,sort_keys=True)); (O/'post-source-inventory.json').write_text(json.dumps(postS,sort_keys=True))
 pred=(res['required']['passCount']==355 and zeros==0 and exc==0 and union==[2,3,4] and contributors=={'2':['prescribed sphere'],'3':['two-ring'],'4':['prescribed sphere']} and tp=='none' and mechA1 and twoBarrier and diag[EXTRA]['status']=='PASS' and all(diag[x]['selected']==1 and diag[x]['status']=='RED' and diag[x]['failures']==1 for x in NG) and res['retiredIdentitiesAbsent'] and preP==postP and preS==postS and all(static.values()))
 res['predictionMet']=pred; res['overall']='PASS' if pred else 'SEMANTIC_RED'; code=0 if pred else 1
except Exception as e:
 res['overall']='ORCHESTRATION_RED'; res['error']=repr(e); code=2
(O/'summary.json').write_text(json.dumps(res,indent=2,sort_keys=True)); (O/'gate-exit-code.txt').write_text(str(code)+'\n'); print(json.dumps(res,indent=2,sort_keys=True)); raise SystemExit(code)
