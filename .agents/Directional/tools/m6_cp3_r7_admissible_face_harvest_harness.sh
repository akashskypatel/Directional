#!/usr/bin/env bash
set -euo pipefail
[[ "$1" == --execute ]] || exit 64
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
python3 - <<'PY'
import collections,csv,hashlib,os,pathlib,re,shutil,subprocess,sys,tarfile,zipfile
sha0="4d64b7684ac7ec2d0655f96c88ecf05f2906bca7"
artifact=12024554349
digest="c824a6aa43617309aaae6a54a3dd49a987c51390caa404600a88763d3b04fabf"
root=pathlib.Path(os.environ["RUNNER_TEMP"])/os.environ["TURN_ID"]
out=pathlib.Path(str(root)+"-result")
for p in (root,out,out/"raw",root/"package",root/"source",root/"view",root/"run"):p.mkdir(parents=True,exist_ok=True)
counts=dict(planned=0,executed=0,red=0,missing=0,postflight="false")
def hashfile(p):return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()
def check(ok,msg):
 if not ok:raise RuntimeError(msg)
def inventory(p):
 return {str(x.relative_to(p)):hashfile(x) for x in p.rglob("*") if x.is_file()}
def manifest(p):
 lines=(p/"SHA256SUMS").read_text().splitlines()
 for line in lines:
  h,rel=line.split("  ",1)
  check(hashfile(p/rel)==h,"manifest mismatch "+rel)
 return len(lines)
def field(line,key):
 m=re.search(re.escape("a2bProbe"+key)+r'=([^;\r\n"]+)',line)
 return m.group(1) if m else ""
def faces(s):return set(map(int,s.split(","))) if re.fullmatch(r"\d+(?:,\d+)*",s) else None
def serialize(rows,path,header):
 with path.open("w") as f:
  w=csv.writer(f,delimiter="\t");w.writerow(header);w.writerows(rows)
status=90
try:
 url="https://api.github.com/repos/"+os.environ["GITHUB_REPOSITORY"]+"/actions/artifacts/"+str(artifact)
 auth=["-H","Authorization: Bearer "+os.environ["GH_TOKEN"]]
 provider=subprocess.check_output(["curl","-fsSL",*auth,url],text=True)
 check("sha256:"+digest in provider,"provider digest")
 pkgzip=root/"pkg.zip"
 subprocess.run(["curl","-fsSL",*auth,url+"/zip","-o",str(pkgzip)],check=True)
 check(hashfile(pkgzip)==digest,"package digest")
 subprocess.run(["unzip","-q",str(pkgzip),"-d",str(root/"package")],check=True)
 pkg=root/"package"
 check(manifest(pkg)==28,"manifest count")
 check((pkg/"metadata/source-commit.txt").read_text().strip()==sha0,"source SHA")
 cmd=(pkg/"metadata/command-boundary.txt").read_text()
 check("runtimeExecution=false" in cmd and "exactArithmeticBackend=GMP" in cmd,"GMP compile boundary")
 with tarfile.open(pkg/"source"/("source-"+sha0+".tar.gz"),"r:gz") as f:f.extractall(root/"source",filter="data")
 src=root/"source"
 frozen={
 ".agents/Directional/Architecture_M6_CP1_Required_Green_Focused_30.txt":"1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6",
 ".agents/Directional/Architecture_M6_CP2_Required_Green_Focused_12.txt":"2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed",
 ".agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt":"d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414",
 ".agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv":"9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707"}
 for p,h in frozen.items():check(hashfile(src/p)==h,"selector drift "+p)
 p0,s0=inventory(pkg),inventory(src)
 view=root/"view";(view/"bin").mkdir()
 for x in (pkg/"bin").iterdir():shutil.copy2(x,view/"bin"/x.name)
 shutil.copytree(src/"benchmarks/fixtures",view/"test-data/benchmarks")
 v0=inventory(view)
 exe=view/"bin/directional_surface_cell_producer_tests"
 check(exe.exists(),"producer executable absent")
 inv=pathlib.Path(os.environ["GITHUB_WORKSPACE"])/".agents/Directional/Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv"
 check(hashfile(inv)=="de05a7bd5ca27eb243156ecd38434fbc69d06f4b791bdd3dbcfc5982c273a865","inventory drift")
 rows=list(csv.reader(inv.open(),delimiter="\t"))[1:]
 check(len(rows)==39,"inventory count")
 tests=[(r[0],r[1]) for r in rows if r[0]!="405"]
 tests += [("SUPPLEMENTAL",n) for n in [
 "SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer",
 "SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard",
 "SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement",
 "SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate",
 "SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress",
 "M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm"]]
 check(len(tests)==44 and len({n for _,n in tests})==43,"44 unique identities")
 ledger=[]
 for i,(ordinal,name) in enumerate(tests,1):
  counts["planned"]+=1
  cwd=root/"run"/str(i);cwd.mkdir()
  with (out/"raw"/(str(i)+".log")).open("w") as log:
   r=subprocess.run(["/usr/bin/time","-v","env","GTEST_FAIL_IF_NO_TEST_SELECTED=1","GTEST_COLOR=no",str(exe),"--gtest_filter="+name],cwd=cwd,stdout=log,stderr=subprocess.STDOUT)
  raw=(out/"raw"/(str(i)+".log")).read_text(errors="replace")
  selected=len(re.findall(r"(?m)^\[ RUN      \] ",raw))
  passed=len(re.findall(r"(?m)^\[       OK \] ",raw))
  skipped=len(re.findall(r"(?m)^\[  SKIPPED \] ",raw))
  verdict="PASS" if r.returncode==0 and selected==passed==1 else "RED"
  if selected!=1 or skipped:counts["missing"]+=1;verdict="NOT_SELECTED"
  else:counts["executed"]+=1;counts["red"]+=int(verdict=="RED")
  ledger.append((i,ordinal,name,r.returncode,selected,passed,verdict))
 serialize(ledger,out/"ledger.tsv",["index","ordinal","identity","exit","selected","passed","verdict"])
 partitions=collections.Counter();multiplicity=collections.Counter();errors=[];census=[]
 for i,ordinal,name,rc,selected,passed,verdict in ledger:
  raw=(out/"raw"/(str(i)+".log")).read_text(errors="replace")
  lines=[line for line in raw.splitlines() if "a2bProbeRouteStepCount=" in line]
  multiplicity[len(lines)]+=1
  if not lines:errors.append((name,"missing"));continue
  signatures=[]
  for j,line in enumerate(lines):
   condition=field(line,"FirstFailedCondition")
   signature=[condition]
   for side in ("First","Second"):
    keys=("ActiveFaces","Frame","FromAdmissibleFaces","ToAdmissibleFaces","PathFaces")
    vals={k:field(line,side+k) for k in keys}
    signature+=list(vals.values())
    active,fs,ts,path=[faces(vals[k]) for k in ("ActiveFaces","FromAdmissibleFaces","ToAdmissibleFaces","PathFaces")]
    valid=bool(condition) and vals["Frame"]=="" and all(x is not None for x in (active,fs,ts,path))
    if valid:valid=fs<=active and ts<=active
    if not valid:errors.append((name,j,side,vals))
    all_to=path<=ts if path is not None and ts is not None else ""
    any_to=bool(path&ts) if path is not None and ts is not None else ""
    all_from=path<=fs if path is not None and fs is not None else ""
    partitions[(condition,side,str(all_to),str(any_to))]+=1
    census.append((i,name,ordinal,verdict,j,condition,side,vals["ActiveFaces"],vals["Frame"],vals["FromAdmissibleFaces"],vals["ToAdmissibleFaces"],vals["PathFaces"],all_to,any_to,all_from,"COMPLETE" if valid else "INCOMPLETE"))
   signatures.append(tuple(signature))
  if len(set(signatures))!=1:errors.append((name,"diagnostic mismatch"))
 serialize(census,out/"admissible-face-census.tsv",["index","identity","ordinal","verdict","occurrence","condition","side","active","frame","from_admissible","to_admissible","path","all_path_in_to","any_path_in_to","all_path_in_from","evidence"])
 (out/"admissible-face-summary.txt").write_text("comparison=actual traced side path face rows versus producer node admissible face rows\npartitions="+repr(sorted(partitions.items()))+"\nmultiplicity="+repr(sorted(multiplicity.items()))+"\nerrors="+repr(errors)+"\nstable_ledger=66/17/49 unchanged; candidate diagnostic vintage\n")
 check(not errors,"incomplete or inconsistent diagnostic evidence")
 check(counts["planned"]==counts["executed"]==44 and counts["missing"]==0,"coverage")
 check(inventory(pkg)==p0 and inventory(src)==s0 and inventory(view)==v0,"immutability")
 check(manifest(pkg)==28,"postflight SHA256SUMS")
 (out/"immutability.txt").write_text("package=true source=true execution_view=true selector=true\n")
 counts["postflight"]="true";status=0
except Exception as e:
 print("ORCHESTRATION_FAILURE",repr(e),file=sys.stderr)
finally:
 (out/"execution-boundary.txt").write_text("artifact_id="+str(artifact)+"\nsource_sha="+sha0+"\n"+"\n".join(k+"="+str(v) for k,v in counts.items())+"\ncompile=false\nrelink=false\nbenchmarks=false\nselector497=false\nexit="+str(status)+"\n")
 with (out/"SHA256SUMS").open("w") as f:
  for x in sorted(out.rglob("*")):
   if x.is_file() and x.name!="SHA256SUMS":f.write(hashfile(x)+"  "+str(x.relative_to(out))+"\n")
 print("TB6_RESULT",counts,"exit",status)
sys.exit(status)
PY
