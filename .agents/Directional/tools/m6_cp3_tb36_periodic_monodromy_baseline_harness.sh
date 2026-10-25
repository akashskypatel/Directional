#!/usr/bin/env bash
set -euo pipefail
[[ "$1" == "--execute" ]] || exit 64
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
python3 - <<'PY'
import csv,hashlib,json,os,pathlib,re,shutil,subprocess,sys,tarfile,traceback
source="7de805c487fa66bcb96744f51b8bfbe7210ee8dc"
artifact=12580989509
ziphash="a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54"
manifesthash="ab2711b2efc64103a9106b9a63f03064c63dc6e93a16c0602f3c6b3f866c1d0c"
root=pathlib.Path(os.environ["RUNNER_TEMP"])/os.environ["TURN_ID"]
out=pathlib.Path(str(root)+"-result")
for p in [root,out,out/"raw",root/"pkg",root/"src",root/"view",root/"run"]:p.mkdir(parents=True,exist_ok=True)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def require(ok,msg):
 if not ok:raise RuntimeError(msg)
def checks(pkg):
 lines=(pkg/"SHA256SUMS").read_text().splitlines()
 for line in lines:
  h,rel=line.split("  ",1)
  require(sha(pkg/rel)==h,"package checksum mismatch: "+rel)
 return len(lines)
def files(root):return {str(p.relative_to(root)):sha(p) for p in root.rglob("*") if p.is_file()}
state={"planned":5,"executed":0,"red":0,"pass":0,"missing":0,"postflight":False,"stopped_after":None,"stop_reason":None}
rows=[]; rc=90
try:
 manifest=pathlib.Path(os.environ["GITHUB_WORKSPACE"])/".agents/Directional/Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv"
 require(sha(manifest)==manifesthash,"TB36 manifest drift")
 with manifest.open(newline="") as f:cases=list(csv.DictReader(f,delimiter="\t"))
 require(len(cases)==5 and [int(c["row"]) for c in cases]==list(range(1,6)),"TB36 five rows")
 require(len({c["test"] for c in cases})==5 and len({c["identity"] for c in cases})==5,"duplicate case")
 require([c["pre_run"] for c in cases]==["UNMEASURED_PREDICTED_RED"]*3+["UNMEASURED_HISTORICAL_RED"]*2,"TB36 prediction drift")
 require([c["kind"] for c in cases]==["NEW_ORACLE"]*3+["FROZEN_SELECTOR"]*2,"TB36 kind drift")
 require({c["binary"] for c in cases}=={"directional_surface_cell_producer_tests"},"binary ownership drift")
 url="https://api.github.com/repos/"+os.environ["GITHUB_REPOSITORY"]+"/actions/artifacts/"+str(artifact)
 curl=["curl","-fsSL","-H","Authorization: Bearer "+os.environ["GH_TOKEN"]]
 require(json.loads(subprocess.check_output(curl+[url],text=True))["digest"]=="sha256:"+ziphash,"provider SHA mismatch")
 archive=root/"immutable.zip"
 subprocess.run(curl+[url+"/zip","-o",str(archive)],check=True)
 require(sha(archive)==ziphash,"ZIP digest mismatch")
 subprocess.run(["unzip","-q",str(archive),"-d",str(root/"pkg")],check=True)
 pkg=root/"pkg"
 require(checks(pkg)==28,"28 package checksums")
 require((pkg/"metadata/source-commit.txt").read_text().strip()==source,"semantic source SHA")
 require((pkg/"metadata/build-exit-code.txt").read_text().strip()=="0" and (pkg/"metadata/preflight-exit-code.txt").read_text().strip()=="0","compile evidence")
 boundary=(pkg/"metadata/command-boundary.txt").read_text()
 require("runtimeExecution=false" in boundary and "exactArithmeticBackend=GMP" in boundary,"compile/GMP boundary")
 with tarfile.open(pkg/"source"/("source-"+source+".tar.gz")) as t:t.extractall(root/"src",filter="data")
 src=root/"src"
 frozen={".agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt":"d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414",
 ".agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv":"9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707"}
 for path,value in frozen.items():require(sha(src/path)==value,"frozen selector drift "+path)
 view=root/"view";(view/"bin").mkdir()
 for name in {c["binary"] for c in cases}:
  original=pkg/"bin"/name;target=view/"bin"/name
  require(original.is_file() and os.access(original,os.X_OK),"archived binary/mode missing "+name)
  shutil.copy2(original,target)
  require(os.access(target,os.X_OK),"copied mode missing "+name)
  dep=subprocess.run(["ldd",str(target)],capture_output=True,text=True,check=True)
  (out/(name+"-dependencies.txt")).write_text(dep.stdout+dep.stderr)
  require("not found" not in dep.stdout+dep.stderr and "libgmp" in dep.stdout,"GMP runtime "+name)
 shutil.copytree(src/"benchmarks/fixtures",view/"test-data/benchmarks/fixtures")
 before=files(view)
 for c in cases:
  c["expected"]=c["pre_run"]
  i=int(c["row"]);wd=root/"run"/str(i);wd.mkdir()
  log=out/"raw"/(str(i)+".log")
  with log.open("w") as fp:
   try:
    run=subprocess.run(["/usr/bin/time","-v","env","GTEST_FAIL_IF_NO_TEST_SELECTED=1","GTEST_COLOR=no",str(view/"bin"/c["binary"]),"--gtest_filter="+c["test"]],cwd=wd,stdout=fp,stderr=subprocess.STDOUT,timeout=300)
    status=run.returncode;timeout=False
   except subprocess.TimeoutExpired:status=124;timeout=True
  data=log.read_text(errors="replace")
  n=len(re.findall(r"(?m)^\[ RUN      \] ",data))
  passed=len(re.findall(r"(?m)^\[       OK \] ",data))
  skipped=len(re.findall(r"(?m)^\[  SKIPPED \] ",data))
  failed=bool(re.search(r"(?m)^\[  FAILED  \] "+re.escape(c["test"])+r"(?:\s|$)",data))
  complete=not timeout and n==1 and skipped==0 and ((status==0 and passed==1) or (status!=0 and failed))
  verdict=("PASS" if status==0 and passed==1 else "RED") if complete else "INCOMPLETE"
  state["executed"]+=int(complete);state["missing"]+=int(not complete)
  state["red"]+=int(verdict=="RED");state["pass"]+=int(verdict=="PASS")
  failures=re.findall(r"SurfaceCellsPhase10Tests\.cpp:(\d+): Failure",data)
  first_line=int(failures[0]) if failures else None
  first_failure=next((line.strip() for line in data.splitlines() if re.search(r"SurfaceCellsPhase10Tests\.cpp:\d+: Failure",line)),"")
  reason=None
  if verdict=="INCOMPLETE":reason="NONTERMINAL_OR_MISSING_EXACT_TEST"
  elif c["kind"]=="NEW_ORACLE" and verdict=="PASS":reason="UNEXPECTED_GREEN_PREFIX"
  elif c["kind"]=="NEW_ORACLE" and first_line is None:reason="UNKNOWN_FIRST_FAILURE_STAGE"
  elif i in (1,2) and first_line is not None and first_line<4624:reason="PRE_A4_FACTORY_OR_SETUP_FAILURE"
  elif i==3 and first_line is not None and first_line<4661:reason="PUBLISHED_ROUTE_PREPRODUCER_FAILURE"
  rows.append([i,c["kind"],c["identity"],c["test"],c["binary"],c["expected"],verdict,status,n,passed,skipped,first_line or "",first_failure,reason or "",sha(log)])
  print("TB36",i,c["identity"],verdict,"first_line",first_line,"stop",reason,flush=True)
  if reason:
   state["stopped_after"]=i
   state["stop_reason"]=reason
   break
 with (out/"ledger.tsv").open("w",newline="") as fp:
  w=csv.writer(fp,delimiter="\t");w.writerow("row kind identity test binary predicted actual exit selected passed skipped first_failure_line first_failure stop_reason log_sha256".split());w.writerows(rows)
 require(checks(pkg)==28 and files(view)==before,"immutable postflight drift")
 state["postflight"]=True
 (out/"immutability.json").write_text(json.dumps({"artifact_id":artifact,"package_sha256":sha(archive),"source_sha":source,"manifest_sha256":manifesthash,"package_entries":28,"compile":False,"relink":False,"benchmarks":False,"selector_mutation":False},indent=2))
 if not state["stop_reason"]:require(state["executed"]==5 and state["missing"]==0,"missing process")
 else:print("TB36_STOP_CONDITION",state["stop_reason"],"after",state["stopped_after"])
 rc=0
except Exception as exc:
 print("TB36_HARNESS_FAILURE",repr(exc),file=sys.stderr);traceback.print_exc()
finally:
 (out/"execution-boundary.json").write_text(json.dumps({"artifact_id":artifact,"source_sha":source,"state":state,"compile":False,"relink":False,"benchmark":False,"exit":rc},indent=2))
 with (out/"SHA256SUMS").open("w") as fp:
  for p in sorted(out.rglob("*")):
   if p.is_file() and p.name!="SHA256SUMS":fp.write(sha(p)+"  "+str(p.relative_to(out))+"\n")
 print("TB36_RESULT",json.dumps(state),"exit",rc,flush=True)
sys.exit(rc)
PY
