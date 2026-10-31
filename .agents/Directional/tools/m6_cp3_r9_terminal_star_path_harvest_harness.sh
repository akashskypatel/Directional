#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == "--execute" ]] || exit 64
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
python3 - <<'PY'
import csv,hashlib,json,os,pathlib,re,shutil,subprocess,sys,tarfile,collections
sha="18cc4da5e2bc41138c5363a74de4e2db1e28ef23"
artifact=12052388003
digest="ed250e970a78dcdae621117cb2a7fd9333849d6083cc8e01775cb207823c07b9"
root=pathlib.Path(os.environ["RUNNER_TEMP"])/os.environ["TURN_ID"]
out=pathlib.Path(str(root)+"-result")
for p in [root,out,out/"raw",root/"package",root/"source",root/"view",root/"run"]:p.mkdir(parents=True,exist_ok=True)
state={"planned":0,"executed":0,"red":0,"missing":0,"postflight":False}
def sha256(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def check(ok,reason):
 if not ok:raise RuntimeError(reason)
def inventory(p):return {str(f.relative_to(p)):(sha256(f),f.stat().st_mode & 0o111) for f in p.rglob("*") if f.is_file()}
def write_tsv(path,header,rows):
 with path.open("w",newline="") as fp:
  writer=csv.writer(fp,delimiter="\t");writer.writerow(header);writer.writerows(rows)
def field(line,key):
 m=re.search(re.escape("a2bProbe"+key)+r'=([^;\r\n"]+)',line)
 return m.group(1) if m else ""
def manifest(pkg):
 entries=(pkg/"SHA256SUMS").read_text().splitlines()
 for entry in entries:
  h,rel=entry.split("  ",1)
  check(sha256(pkg/rel)==h,"manifest: "+rel)
 return len(entries)
rc=90
try:
 api="https://api.github.com/repos/"+os.environ["GITHUB_REPOSITORY"]+"/actions/artifacts/"+str(artifact)
 headers=["-H","Authorization: Bearer "+os.environ["GH_TOKEN"]]
 provider=json.loads(subprocess.check_output(["curl","-fsSL",*headers,api],text=True))
 check(provider["digest"]=="sha256:"+digest,"provider digest mismatch")
 pkgzip=root/"package.zip"
 subprocess.run(["curl","-fsSL",*headers,api+"/zip","-o",str(pkgzip)],check=True)
 check(sha256(pkgzip)==digest,"archive digest mismatch")
 subprocess.run(["unzip","-q",str(pkgzip),"-d",str(root/"package")],check=True)
 pkg=root/"package"
 check(manifest(pkg)==28,"packaged checksum count")
 check((pkg/"metadata/source-commit.txt").read_text().strip()==sha,"semantic source mismatch")
 boundary=(pkg/"metadata/command-boundary.txt").read_text()
 check("runtimeExecution=false" in boundary and "exactArithmeticBackend=GMP" in boundary,"compile/GMP authority")
 check((pkg/"metadata/build-exit-code.txt").read_text().strip()=="0","build failure")
 with tarfile.open(pkg/"source"/("source-"+sha+".tar.gz"),"r:gz") as tf:tf.extractall(root/"source",filter="data")
 src=root/"source"
 frozen={
 ".agents/Directional/Architecture_M6_CP1_Required_Green_Focused_30.txt":"1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6",
 ".agents/Directional/Architecture_M6_CP2_Required_Green_Focused_12.txt":"2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed",
 ".agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt":"d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414",
 ".agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv":"9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707"}
 for name,h in frozen.items():check(sha256(src/name)==h,"frozen selector drift: "+name)
 view=root/"view";(view/"bin").mkdir()
 for exe in (pkg/"bin").iterdir():shutil.copy2(exe,view/"bin"/exe.name)
 shutil.copytree(src/"benchmarks/fixtures",view/"test-data/benchmarks")
 initial=(inventory(pkg),inventory(src),inventory(view))
 test_inv=pathlib.Path(os.environ["GITHUB_WORKSPACE"])/".agents/Directional/Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv"
 check(sha256(test_inv)=="de05a7bd5ca27eb243156ecd38434fbc69d06f4b791bdd3dbcfc5982c273a865","test inventory drift")
 history=list(csv.reader(test_inv.open(),delimiter="\t"))[1:]
 check(len(history)==39,"historical inventory count")
 tests=[(r[0],r[1]) for r in history if r[0]!="405"]
 tests += [("SUPPLEMENTAL",n) for n in [
 "SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer",
 "SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard",
 "SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement",
 "SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate",
 "SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress",
 "M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm"]]
 check(len(tests)==44 and len({n for _,n in tests})==43,"identity coverage")
 exe=view/"bin/directional_surface_cell_producer_tests"
 check(exe.is_file(),"missing immutable test executable")
 ledger=[]
 for i,(ordinal,name) in enumerate(tests,1):
  state["planned"]+=1
  cwd=root/"run"/str(i);cwd.mkdir()
  with (out/"raw"/(str(i)+".log")).open("w") as fp:
   proc=subprocess.run(["/usr/bin/time","-v","env","GTEST_FAIL_IF_NO_TEST_SELECTED=1","GTEST_COLOR=no",str(exe),"--gtest_filter="+name],cwd=cwd,stdout=fp,stderr=subprocess.STDOUT)
  data=(out/"raw"/(str(i)+".log")).read_text(errors="replace")
  selected=len(re.findall(r"(?m)^\[ RUN      \] ",data))
  passed=len(re.findall(r"(?m)^\[       OK \] ",data))
  skipped=len(re.findall(r"(?m)^\[  SKIPPED \] ",data))
  verdict="PASS" if proc.returncode==0 and selected==passed==1 else "RED"
  if selected!=1 or skipped:state["missing"]+=1;verdict="NOT_SELECTED"
  else:state["executed"]+=1;state["red"]+=verdict=="RED"
  ledger.append((i,ordinal,name,proc.returncode,selected,passed,verdict))
 write_tsv(out/"ledger.tsv",["index","ordinal","identity","exit","selected","passed","verdict"],ledger)
 census=[];errors=[];counts=collections.Counter()
 grammar=re.compile(r"(\d+),(\d+),(\d+):override=([01]),sampled=face=(-?\d+),entity=(.*?),accepted=(none|face=(-?\d+),entity=(.+))$")
 for i,ordinal,name,exitcode,selected,passed,verdict in ledger:
  data=(out/"raw"/(str(i)+".log")).read_text(errors="replace")
  lines=[line for line in data.splitlines() if "a2bProbeBoundarySourceEntities=" in line]
  if not lines:errors.append((i,"missing rejected-certificate diagnostic"));continue
  for occurrence,line in enumerate(lines):
   condition=field(line,"FirstFailedCondition")
   payload=field(line,"BoundarySourceEntities")
   if not condition or not payload:errors.append((i,occurrence,"empty evidence"));continue
   if payload=="none":
    counts[(condition,"NOT_MEASURED")]+=1
    census.append((i,ordinal,name,occurrence,condition,"","","","","","","","","NOT_MEASURED","none"))
    continue
   seen=set()
   for raw in payload.split("|"):
    match=grammar.fullmatch(raw)
    if not match:errors.append((i,occurrence,"invalid node record",raw));continue
    region,u,v,override,face0,entity0,accepted,face1,entity1=match.groups()
    key=(region,u,v)
    if key in seen:errors.append((i,occurrence,"duplicate node",key))
    seen.add(key)
    if override=="1":
     if entity1 is None:errors.append((i,occurrence,"missing accepted point",raw))
     outcome="SAME_ENTITY" if entity0==entity1 else "DIFFERENT_ENTITY"
    else:
     if accepted!="none":errors.append((i,occurrence,"unexpected accepted point",raw))
     outcome="NOT_OVERRIDDEN"
    if entity0=="invalid-face" or entity1=="invalid-face":errors.append((i,occurrence,"invalid source face",raw))
    counts[(condition,outcome)]+=1
    census.append((i,ordinal,name,occurrence,condition,region,u,v,override,face0,entity0,face1 or "",entity1 or "",outcome,raw))
 write_tsv(out/"source-entity-census.tsv",["index","ordinal","identity","occurrence","condition","region","u","v","override","sampled_face","sampled_entity","accepted_face","accepted_entity","equivalence","original_record"],census)
 (out/"source-entity-summary.txt").write_text("outcomes="+repr(sorted(counts.items()))+"\nerrors="+repr(errors)+"\nrows="+str(len(census))+"\nexact entities only; source-sheet and directed-side carrier require separate proof\n")
 check(not errors and census,"missing/malformed diagnostic evidence")
 check(sum(n for (condition,kind),n in counts.items() if kind in ("SAME_ENTITY","DIFFERENT_ENTITY"))>0,"no measured overridden boundary points")
 check(state["planned"]==state["executed"]==44 and state["missing"]==0,"44 exact-filter selection incomplete")
 check((inventory(pkg),inventory(src),inventory(view))==initial,"postflight immutable package/source/view mismatch")
 check(manifest(pkg)==28,"postflight manifest mismatch")
 state["postflight"]=True
 (out/"immutability.txt").write_text("package=true source=true execution_view=true frozen_selectors=true\n")
 rc=0
except Exception as exc:
 print("TB9_HARNESS_FAILURE",repr(exc),file=sys.stderr)
finally:
 (out/"execution-boundary.txt").write_text("artifact_id="+str(artifact)+"\nsemantic_source="+sha+"\n"+ "".join(k+"="+str(v)+"\n" for k,v in state.items())+"compile=false\nrelink=false\nbenchmarks=false\nselector497=false\nexit="+str(rc)+"\n")
 with (out/"SHA256SUMS").open("w") as fp:
  for file in sorted(out.rglob("*")):
   if file.is_file() and file.name!="SHA256SUMS":fp.write(sha256(file)+"  "+str(file.relative_to(out))+"\n")
 print("TB9_RESULT",state,"exit",rc)
sys.exit(rc)
PY
