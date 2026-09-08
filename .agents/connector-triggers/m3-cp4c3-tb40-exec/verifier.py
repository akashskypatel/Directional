#!/usr/bin/env python3
import csv, json, os, pathlib, re, sys, hashlib
r=pathlib.Path(sys.argv[1]); hx=sys.argv[2] or 'unavailable'
rows=list(csv.DictReader((r/'ledger.tsv').open(),delimiter='\t')) if (r/'ledger.tsv').exists() else []
by={int(x['ordinal']):x for x in rows if x.get('ordinal','').isdigit()}
raw={o:(r/x.get('raw_log','')).read_text(errors='replace') if (r/x.get('raw_log','')).exists() else '' for o,x in by.items()}
red=[o for o,x in sorted(by.items()) if x.get('result')=='RED']; acc=[o for o in range(1,366) if by.get(o,{}).get('result')!='PASS']; bad=[o for o,x in by.items() if x.get('selected')!='1']
# Preserve direct gate/carried statuses.
direct=[312,356,357,362,366,367,368,369,370,374,385,390,393,398,404,406,407,408,409]
with (r/'direct-identity-status.tsv').open('w',newline='') as f:
 w=csv.writer(f,delimiter='\t'); w.writerow(['ordinal','identity','result','exit','selected','raw_log'])
 for o in direct:
  x=by.get(o,{}); w.writerow([o,x.get('identity',''),x.get('result',''),x.get('exit',''),x.get('selected',''),x.get('raw_log','')])
# Parse actual-embedded face binding census.
tok=re.compile(r'([A-Za-z_][A-Za-z0-9_]*)=([^\s]+)'); groups={}; bind=[]; malformed=[]
creq=['graphComponents','sourceComponentCount','exteriorSize','boundaryLoops','graphEuler','sourceEuler']
rreq=['region','derivedOrbit','certificateOrbit','upstreamMatchCount','regionBoundaryArcCount','certificateBoundaryArcCount','discTopologyEstablished','fieldRegularity']
for o,text in raw.items():
 for n,line in enumerate(text.splitlines(),1):
  if 'M3_CP4C3_FACE_BINDING_CENSUS' not in line: continue
  t=dict(tok.findall(line)); kind=t.get('record',''); req=creq if kind=='complex' else rreq if kind=='region' else []
  miss=[k for k in req if k not in t]
  if not req or miss: malformed.append({'ordinal':o,'line':n,'record':kind,'missing':miss or ['record']}); continue
  g=groups.setdefault(o,{'complex':[],'region':[]}); g[kind].append(t); bind.append({'ordinal':o,'line':n,**t})
(r/'face-binding-rows.json').write_text(json.dumps(bind,indent=2,sort_keys=True)+'\n')
(r/'face-binding-malformed.json').write_text(json.dumps(malformed,indent=2,sort_keys=True)+'\n')
def valid(g):
 c=g['complex']; q=g['region']; d=[int(x['derivedOrbit']) for x in q]; ids=[int(x['region']) for x in q]
 return len(c)==1 and bool(q) and len(set(d))==len(d) and len(set(ids))==len(ids) and all(int(x['upstreamMatchCount'])==1 and int(x['derivedOrbit'])==int(x['certificateOrbit']) and int(x['regionBoundaryArcCount'])==int(x['certificateBoundaryArcCount']) and x['discTopologyEstablished']=='true' and x['fieldRegularity']=='true' for x in q)
nonuniform=any(len({int(x['derivedOrbit']) for x in g['region']})>1 for g in groups.values())
# Ownership control from ordinal 385.
own=None
m=re.search(r'm3Cp4c3CertifiedOwnerPublication;sourceFaceCount=(\d+);established=(\d+);unavailable=(\d+);conflicting=(\d+);conflictCensusPublished=(true|false);conflictRowCount=(\d+)',raw.get(385,''))
if m: own={'sourceFaceCount':int(m[1]),'established':int(m[2]),'unavailable':int(m[3]),'conflicting':int(m[4]),'conflictCensusPublished':m[5]=='true','conflictRowCount':int(m[6])}
legacy=['TraceArcDoesNotSeparateItsSides','UncutFaceComponentOrbitSeedNotUnique']; region_retired=['RegionEulerCharacteristicNotOne','RegionInteriorDisconnected']; carried=[368,369,370,374,398]; protected=[390,393,404,406,407,408]
legacy_counts={k:sum(text.count(k) for text in raw.values()) for k in legacy}
region_counts={o:{k:raw.get(o,'').count(k) for k in region_retired} for o in [366,367,*carried]}
checks={
 'ledger_complete':len(rows)==409 and sorted(by)==list(range(1,410)),
 'accepted_365_of_365':not acc,
 'ordinal_312_pass':by.get(312,{}).get('result')=='PASS',
 'ordinal_409_pass':by.get(409,{}).get('result')=='PASS',
 'protected_pass':all(by.get(o,{}).get('result')=='PASS' for o in protected),
 'selection_integrity':not bad,
 'carried_reds_preserved':all(by.get(o,{}).get('result')=='RED' for o in carried),
 'carried_reds_not_region_proxy':all(not any(region_counts[o].values()) for o in carried),
 '366_367_not_region_proxy':all(not any(region_counts[o].values()) for o in [366,367]),
 'ownership_300_0_0':bool(own) and own['sourceFaceCount']==300 and own['established']==300 and own['unavailable']==0 and own['conflicting']==0,
 'legacy_retired_silent':not any(legacy_counts.values()),
 'binding_nonempty':bool(bind),
 'binding_well_formed':not malformed,
 'binding_groups_valid':bool(groups) and all(valid(g) for g in groups.values()),
 'binding_356_357_present':{356,357}.issubset(groups),
 'binding_nonuniform':nonuniform,
}
out={'turn':os.getenv('TURN_ID'),'run_id':os.getenv('GITHUB_RUN_ID'),'event_sha':os.getenv('GITHUB_SHA'),'harness_exit':hx,'source_sha':os.getenv('EXPECTED_SOURCE_SHA'),'artifact_id':int(os.getenv('EXPECTED_ARTIFACT_ID','0')),'source_archive_sha256':os.getenv('EXPECTED_SOURCE_ARCHIVE_SHA256'),'selector409_sha256':os.getenv('EXPECTED_SELECTOR_SHA256'),'selector408_sha256':os.getenv('EXPECTED_SELECTOR408_SHA256'),'harness_sha256':os.getenv('EXPECTED_HARNESS_SHA256'),'test_source_sha256':os.getenv('EXPECTED_TEST_SOURCE_SHA256'),'total':len(rows),'pass':len(rows)-len(red),'red':len(red),'red_ordinals':red,'accepted_prefix_pass':365-len(acc),'accepted_prefix_red_ordinals':acc,'selection_mismatch_ordinals':bad,'ownership_ordinal_385':own,'legacy_retired_occurrences':legacy_counts,'region_retired_occurrences':region_counts,'face_binding_ordinals':sorted(groups),'face_binding_row_count':len(bind),'face_binding_nonuniform':nonuniform,'semantic_gate_checks':checks,'semantic_gate_pass':all(checks.values()),'no_build':True,'no_benchmark':True,'next_boundary':'M3-CP4c-3-TB40-REV'}
p=r/'tb40-verification.json'; p.write_text(json.dumps(out,indent=2,sort_keys=True)+'\n')
(r/'tb40-verification.json.sha256').write_text(hashlib.sha256(p.read_bytes()).hexdigest()+'  tb40-verification.json\n')
print(json.dumps(out,indent=2,sort_keys=True))
