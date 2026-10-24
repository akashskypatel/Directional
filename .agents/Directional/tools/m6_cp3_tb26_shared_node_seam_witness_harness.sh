#!/usr/bin/env bash
set -euo pipefail
[[ "$1" == "--execute" ]] || exit 64
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
python3 - <<'PY'
import os,hashlib,json,pathlib,subprocess,tarfile,zipfile,re,csv,sys,shutil
sha="c5e0b242f3c3015f1f4f5f886058f0086fe1f679"
id=12399179446
digest="a82c75e0f648fa8f1c8e34e07934d7a01321692e12e993638f02465766f236e9"
root=pathlib.Path(os.environ["RUNNER_TEMP"])/os.environ["TURN_ID"]
out=pathlib.Path(str(root)+"-result")
for p in [root,out,out/"raw",root/"pkg",root/"source",root/"view",root/"run"]:p.mkdir(parents=True,exist_ok=True)
def h(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def ck(ok,reason):
 if not ok:raise RuntimeError(reason)
def manifest(pkg):
 lines=(pkg/"SHA256SUMS").read_text().splitlines()
 for line in lines:
  digest2,path=line.split("  ",1)
  ck(h(pkg/path)==digest2,"manifest "+path)
 return len(lines)
cases=[x.split("|") for x in """
A5|focused30:6|M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection
A5|focused30:20|M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership
A5|focused30:24|M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts
A5|focused30:25|M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus
A5|focused30:26|M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels
A5|focused30:27|M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage
A5|focused30:28|M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle
A5|selector:444|M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate
A5|selector:446|M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes
A5|selector:448|M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate
D3|cp3entry:3|M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition
D3|cp3entry:5|M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition
GUARD|selector:447|M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped
CONTROL|cp3entry:6|M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels
CONTROL|selector:217|SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions
CONTROL|TB18 A#14|SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags
CONTROL|selector:443|M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges
CONTROL|focused30:7|M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority
""".strip().splitlines()]
rows=[]
state=dict(planned=18,executed=0,passed=0,red=0,missing=0,control_bad=0,site_bad=0,postflight=False)
rc=90
try:
 ck(len(cases)==18 and len({c[2] for c in cases})==18,"unique cases")
 url="https://api.github.com/repos/"+os.environ["GITHUB_REPOSITORY"]+"/actions/artifacts/"+str(id)
 curl=["curl","-fsSL","-H","Authorization: Bearer "+os.environ["GH_TOKEN"]]
 ck(json.loads(subprocess.check_output(curl+[url],text=True))["digest"]=="sha256:"+digest,"provider digest")
 z=root/"package.zip"
 subprocess.run(curl+[url+"/zip","-o",str(z)],check=True)
 ck(h(z)==digest,"ZIP SHA-256")
 with zipfile.ZipFile(z) as f:f.extractall(root/"pkg")
 pkg=root/"pkg"
 ck(manifest(pkg)==28,"manifest count")
 ck((pkg/"metadata/source-commit.txt").read_text().strip()==sha,"source mismatch")
 ck((pkg/"metadata/build-exit-code.txt").read_text().strip()=="0","build boundary")
 b=(pkg/"metadata/command-boundary.txt").read_text()
 ck("runtimeExecution=false" in b and "exactArithmeticBackend=GMP" in b,"GMP compile boundary")
 srczip=pkg/"source"/("source-"+sha+".tar.gz")
 ck(h(srczip)=="08fa3b76d1fa9c7348e66f10ec3bf77d0561c61d28df9c88f9aa579f8257c245","source hash")
 with tarfile.open(srczip) as f:f.extractall(root/"source",filter="data")
 src=root/"source"
 frozen={".agents/Directional/Architecture_M6_CP1_Required_Green_Focused_30.txt":"1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6",".agents/Directional/Architecture_M6_CP2_Required_Green_Focused_12.txt":"2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed",".agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt":"d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414",".agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv":"9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707"}
 for path,hash2 in frozen.items():ck(h(src/path)==hash2,"frozen selector: "+path)
 view=root/"view"
 (view/"bin").mkdir()
 for p in (pkg/"bin").iterdir():
  staged=view/"bin"/p.name
  shutil.copy2(p,staged)
  staged.chmod(0o755)
 shutil.copytree(src/"benchmarks/fixtures",view/"test-data/benchmarks/fixtures")
 before={str(p.relative_to(view)):h(p) for p in view.rglob("*") if p.is_file()}
 exe=view/"bin/directional_surface_cell_producer_tests"
 for i,(kind,identity,test) in enumerate(cases,1):
  cwd=root/"run"/str(i);cwd.mkdir()
  log=out/"raw"/(str(i)+".log")
  with log.open("w") as f:
   result=subprocess.run(["/usr/bin/time","-v","env","GTEST_FAIL_IF_NO_TEST_SELECTED=1","GTEST_COLOR=no",str(exe),"--gtest_filter="+test],cwd=cwd,stdout=f,stderr=subprocess.STDOUT,timeout=600)
  data=log.read_text(errors="replace")
  nr=len(re.findall(r"(?m)^\[ RUN      \] ",data))
  passed=len(re.findall(r"(?m)^\[       OK \] ",data))
  skipped=len(re.findall(r"(?m)^\[  SKIPPED \] ",data))
  verdict="PASS" if result.returncode==0 and nr==passed==1 else "RED" if nr==1 and skipped==0 else "NOT_SELECTED"
  state["executed"]+=nr==1 and skipped==0
  state["passed"]+=verdict=="PASS"
  state["red"]+=verdict=="RED"
  state["missing"]+=verdict=="NOT_SELECTED"
  first=next((s for s in data.splitlines() if ": Failure" in s or "producer failed:" in s),"")
  sites=re.findall(r"site=(.*?)(?=;terminalStage=|\s|\"|$)",data)
  if kind in ("CONTROL","GUARD") and verdict!="PASS":state["control_bad"]+=1
  if kind in ("A5","D3") and verdict=="RED" and any("first-face" in s or "second-face" in s for s in sites):state["site_bad"]+=1
  rows.append((i,kind,identity,test,verdict,result.returncode,nr,passed,skipped,first," | ".join(sites),h(log)))
  print("TB26",kind,identity,verdict,first[:160],flush=True)
 with (out/"ledger.tsv").open("w",newline="") as f:
  w=csv.writer(f,delimiter="\t");w.writerow(["row","kind","identity","test","verdict","exit","run","passed","skipped","first_failure","sites","log_sha256"]);w.writerows(rows)
 deps=subprocess.run(["ldd",str(exe)],capture_output=True,text=True,check=True)
 (out/"runtime-dependencies.txt").write_text(deps.stdout+deps.stderr)
 ck("not found" not in deps.stdout+deps.stderr and "libgmp" in deps.stdout,"GMP dependency")
 ck(manifest(pkg)==28,"postflight package")
 ck(all(h(p)==before[str(p.relative_to(view))] for p in view.rglob("*") if p.is_file()),"staged view changed")
 state["postflight"]=True
 ck(state["executed"]==18 and state["missing"]==0,"selection mismatch")
 ck(state["control_bad"]==0 and state["site_bad"]==0,"control or face falsifier")
 rc=0
except Exception as exc:print("TB26_HARNESS_FAILURE",repr(exc),file=sys.stderr)
finally:
 (out/"execution-boundary.json").write_text(json.dumps(dict(artifact=id,source=sha,state=state,compile=False,relink=False,benchmarks=False,selector497=False,exit=rc),indent=2))
 with (out/"SHA256SUMS").open("w") as f:
  for p in sorted(out.rglob("*")):
   if p.is_file() and p.name!="SHA256SUMS":f.write(h(p)+"  "+str(p.relative_to(out))+"\n")
 print("TB26_RESULT",state,"exit",rc,flush=True)
sys.exit(rc)
PY
