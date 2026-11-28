#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == "--execute" ]] || exit 64
python3 - <<'PY'
import collections,csv,hashlib,json,os,pathlib,re,subprocess,sys
executor=pathlib.Path(os.environ["GITHUB_WORKSPACE"])
turn=os.environ["TURN_ID"]
out=pathlib.Path(os.environ["RUNNER_TEMP"])/(turn+"-result")
prior=executor/".agents/Directional/tools/m6_cp3_r9_terminal_star_path_harvest_harness.sh"
expected="baefec87673478a82cac49c6c2e3301bb103192195f90751253e794eb0a5f016"
source_sha="d938ecb57e1040c2a73d5d25c4a613414556cb18"
artifact_id="12062565622"
zip_sha="30111e7f26c8bbeb7ef9762e31fea5fb449b70c9cbdee64a27d4fc660834ef4f"
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def require(cond,what):
 if not cond:raise RuntimeError(what)
def attr(line,name):
 matches=re.findall(r"(?:^|;)a3Probe"+re.escape(name)+r"=([^;\r\n]+)",line)
 require(len(matches)<=1,"duplicate A3 attribute "+name)
 return matches[0] if matches else "NOT_MEASURED"
rc=90
try:
 require(sha(prior)==expected,"frozen prior harness mismatch")
 script=prior.read_text()
 replacements={
  'sha="18cc4da5e2bc41138c5363a74de4e2db1e28ef23"':'sha="'+source_sha+'"',
  'artifact=12052388003':'artifact='+artifact_id,
  'digest="ed250e970a78dcdae621117cb2a7fd9333849d6083cc8e01775cb207823c07b9"':'digest="'+zip_sha+'"',
 }
 for old,new in replacements.items():
  require(script.count(old)==1,"harness parameter substitution mismatch")
  script=script.replace(old,new)
 # Reuse the preflight, exact 44 identities, immutable execution, and postflight
 # of the frozen prior harness. Only its executor constants change in memory;
 # neither the Git source nor downloaded package/source/binaries are patched.
 run=subprocess.run(["bash","-s","--","--execute"],input=script,text=True)
 require(run.returncode==0,"immutable 44-selection harness failed: "+str(run.returncode))
 boundary=out/"execution-boundary.txt"
 require(boundary.exists() and "exit=0" in boundary.read_text(),"missing successful execution boundary")
 keys=("SameExactOneHotVertex","ContactPublished","ContactEndpointMember",
       "CarrierEndpointMember","DecodedVertex","ContactEndpointIds",
       "CertificateCarrierEdge","ResolvedCarrierEdge","CertificateRailId",
       "PublishedCarrierEndpoint","AdmissibleOrientationCount")
 observations=[]
 for log in sorted((out/"raw").glob("*.log"),key=lambda p:int(p.stem)):
  for line in log.read_text(errors="replace").splitlines():
   if "a3ProbeSameExactOneHotVertex=" not in line:continue
   row={key:attr(line,key) for key in keys}
   row["log_index"]=int(log.stem)
   observations.append(row)
 require(len(observations)==48,"unexpected A3 observation count")
 vertex=[v for v in observations if v["SameExactOneHotVertex"]=="1"]
 require(len(vertex)==21,"unexpected exact vertex observation count")
 for row in vertex:
  contact=row["ContactEndpointMember"]
  carrier=row["CarrierEndpointMember"]
  require(contact in ("0","1") and carrier in ("0","1"),"missing vertex memberships")
  require(row["PublishedCarrierEndpoint"]==str(int(contact=="1" and carrier=="1")),
          "composite predicate not equal to measured halves")
  v=row["DecodedVertex"]
  c=row["ContactEndpointIds"].split(",")
  e=row["CertificateCarrierEdge"].split(",")
  r=row["ResolvedCarrierEdge"].split(",")
  require(v.isdecimal() and len(c)==len(e)==len(r)==2,"invalid literal certificate identities")
  require(all(x.isdecimal() for x in c+e+r),"non-numeric endpoint identity")
  require(contact==str(int(v in c)) and carrier==str(int(v in e)),
          "recorded member flag contradicts literal source vertex IDs")
  require(row["CertificateRailId"].isdecimal(),"missing certificate rail ID")
 with (out/"carrier-endpoint-subcondition-census.tsv").open("w",newline="") as fp:
  writer=csv.writer(fp,delimiter="\t")
  writer.writerow(("log_index",*keys))
  writer.writerows((row["log_index"],*(row[k] for k in keys)) for row in observations)
 pairs=collections.Counter((v["ContactEndpointMember"],v["CarrierEndpointMember"]) for v in vertex)
 summary={
  "artifact_id":int(artifact_id),"source_sha":source_sha,
  "observations":len(observations),"exact_vertex_observations":len(vertex),
  "membership_pairs":{"/".join(k):n for k,n in sorted(pairs.items())},
  "composite_true":sum(v["PublishedCarrierEndpoint"]=="1" for v in vertex),
  "scope":"rejection-only; no regression promotion, selector 497 or repair",
 }
 (out/"carrier-endpoint-subcondition-summary.json").write_text(json.dumps(summary,indent=2,sort_keys=True)+"\n")
 with boundary.open("a") as fp:fp.write("a3_observations=48\na3_exact_vertex_observations=21\n")
 with (out/"SHA256SUMS").open("w") as fp:
  for p in sorted(out.rglob("*")):
   if p.is_file() and p.name!="SHA256SUMS":
    fp.write(sha(p)+"  "+str(p.relative_to(out))+"\n")
 print("TB10_RESULT",json.dumps(summary,sort_keys=True))
 rc=0
except Exception as e:
 print("TB10_HARNESS_FAILURE",repr(e),file=sys.stderr)
finally:
 if rc and out.exists():
  (out/"tb10-failure.txt").write_text("orchestration_failure=true\nexit="+str(rc)+"\n")
  with (out/"SHA256SUMS").open("w") as fp:
   for p in sorted(out.rglob("*")):
    if p.is_file() and p.name!="SHA256SUMS":
     fp.write(sha(p)+"  "+str(p.relative_to(out))+"\n")
sys.exit(rc)
PY
