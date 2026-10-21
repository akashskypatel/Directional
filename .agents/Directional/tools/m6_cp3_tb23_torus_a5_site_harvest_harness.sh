#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == "--execute" ]] || exit 64
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
python3 - <<'PY'
import csv,hashlib,json,os,pathlib,re,shutil,subprocess,sys,tarfile
sha="c6e90916eb90bfd33bc8a38c5ece7def15dcc766"
artifact=12341307713
digest="b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5"
root=pathlib.Path(os.environ["RUNNER_TEMP"])/os.environ["TURN_ID"]
out=pathlib.Path(str(root)+"-result")
for p in [root,out,out/"raw",root/"package",root/"source",root/"view",root/"run"]:p.mkdir(parents=True,exist_ok=True)
st={"planned":0,"executed":0,"red":0,"missing":0,"site_bad":0,"ctrl_bad":0,"postflight":False}
def sha256(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def check(ok,reason):
 if not ok:raise RuntimeError(reason)
def inventory(p):return {str(f.relative_to(p)):(sha256(f),f.stat().st_mode & 0o111) for f in p.rglob("*") if f.is_file()}
def write_tsv(path,header,rows):
 with path.open("w",newline="") as fp:
  writer=csv.writer(fp,delimiter="\t");writer.writerow(header);writer.writerows(rows)
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
 check(sha256(pkg/"SHA256SUMS")=="7c396be65a3138eca15ad4c7a37db192d6828b80442a656d38f84d1887767f11","root manifest hash mismatch")
 check((pkg/"metadata/source-commit.txt").read_text().strip()==sha,"semantic source mismatch")
 boundary=(pkg/"metadata/command-boundary.txt").read_text()
 check("runtimeExecution=false" in boundary and "exactArithmeticBackend=GMP" in boundary,"compile/GMP authority")
 check((pkg/"metadata/build-exit-code.txt").read_text().strip()=="0","build failure")
 check(sha256(pkg/"source"/("source-"+sha+".tar.gz"))=="c3779cc949a97fd8b6ce73e62fc8cc62598c637e362bb57cc5f5ecb52cd0cd75","source archive hash mismatch")
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
 shutil.copytree(src/"benchmarks/fixtures",view/"test-data/benchmarks/fixtures")
 check(all((view/"test-data/benchmarks/fixtures/milestone-g"/name).is_file() for name in ("torus.obj", "torus.rawfield")), "missing staged torus fixture or rawfield")
 initial=(inventory(pkg),inventory(src),inventory(view))
 tests=[tuple(row.split("|")) for row in """
W|P|focused30:20|M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership
W|P|selector:446|M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes
W|D|focused30:24|M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts
T|P|focused30:25|M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus
T|D|focused30:26|M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels
T|D|focused30:27|M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage
T|D|focused30:28|M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle
T|P|selector:444|M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate
T|P|selector:448|M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate
W|P|focused30:6|M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection
W|P|selector:447|M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped
—|—|cp3entry:6|M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels
—|—|selector:217|SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions
—|—|TB18 A#14|SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags
—|—|selector:443|M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges
—|—|focused30:7|M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority
""".strip().splitlines()]
 check(len(tests)==16 and len({r[3] for r in tests})==16,"TB23 duplicate identities")
 exe=view/"bin/directional_surface_cell_producer_tests"
 check(exe.is_file(),"missing immutable test executable")
 ledger=[]
 for i,(fixture,path,identity,name) in enumerate(tests,1):
  st["planned"]+=1
  cwd=root/"run"/str(i);cwd.mkdir()
  log=out/"raw"/(str(i)+".log")
  with log.open("w") as fp:
   proc=subprocess.run(["/usr/bin/time","-v","env","GTEST_FAIL_IF_NO_TEST_SELECTED=1","GTEST_COLOR=no",str(exe),"--gtest_filter="+name],cwd=cwd,stdout=fp,stderr=subprocess.STDOUT,timeout=600)
  data=log.read_text(errors="replace")
  check("test-data package not found" not in data, "TB22 fixture not found in row "+str(i))
  selected=len(re.findall(r"(?m)^\[ RUN      \] ",data))
  passed=len(re.findall(r"(?m)^\[       OK \] ",data))
  skipped=len(re.findall(r"(?m)^\[  SKIPPED \] ",data))
  verdict="PASS" if proc.returncode==0 and selected==passed==1 else "RED"
  if selected!=1 or skipped:st["missing"]+=1;verdict="NOT_SELECTED"
  else:st["executed"]+=1;st["red"]+=verdict=="RED"
  lines=data.splitlines()
  fail=next((j for j,v in enumerate(lines) if re.search(r"(?:^unknown file|\.cpp:\d+): Failure",v)),None)
  first=(" | ".join(v.strip() for v in lines[fail:fail+9] if v.strip()) if fail is not None else next((v for v in lines if "firstPredicate=" in v or "producer failed:" in v),""))[:1800]
  rejection=next((line for line in lines if "producer failed: PublishedProductRejected" in line),"")
  def extract(key):
   match=re.search(r"(?:^|[ ;])"+re.escape(key)+r"=([^\s\"]+)",rejection)
   return match.group(1) if match else ""
  receipt=" | ".join(v.strip() for v in lines if any(x in v for x in ("selectionReceipt=","oddFaceGaugePairs=","selected=")))[:7000]
  a5code=r"(?:InvalidIsolationSeamEquivalenceAuthority:a5-(?:side|wedge)|A5:Occurrence(?:Mismatched|Missing)IsolationEvidence)"
  a5lines=[line for line in lines if re.search(a5code,line)]
  sites=re.findall(r'site=(.*?)(?=;terminalStage=|\s|"|$)',data)
  all_sites=" | ".join(sites)
  def fieldof(site,key):
   m=re.search(r"(?:^|;)"+key+r"=([^;]*)",site)
   return m.group(1) if m else ""
  labels=[site.split(";",1)[0] for site in sites]
  label=" | ".join(labels)
  region,seam,cert,certs=[" | ".join(fieldof(x,k) for x in sites) for k in ("region","seam","cert","certs")]
  clauses=" | ".join(",".join(re.findall(r'(?:^|;)(cert[0-9]+=[^;]*)',site)) for site in sites)
  suffixes=set(re.findall(r'a5-(side|wedge)'," ".join(a5lines)))
  allowed={"side-step","side-collinear","relation-collinear-seam"} if suffixes=={"side"} else {"wedge-edge","wedge-fan"} if suffixes=={"wedge"} else {"side-step","side-collinear","wedge-edge","wedge-fan","relation-collinear-seam"} if not suffixes else set()
  invalid=(a5lines and (not sites or not set(labels)<=allowed)) or any(re.search(r'cert[0-9]+=[^;]*:valid(?:;|$)',site) for site in sites)
  if invalid:st["site_bad"]+=1
  if fixture=="—" and (verdict!="PASS" or sites):st["ctrl_bad"]+=1
  ledger.append((i,fixture,path,identity,name,proc.returncode,selected,passed,verdict,len(a5lines),all_sites,label,region,seam,cert,certs,clauses,first,receipt,extract("product"),extract("detail"),sha256(log)))
 write_tsv(out/"ledger.tsv",["index","fixture","path","identity","gtest","exit","selected","passed","TB23","a5_failures","site_raw","label","region","seam","cert","certs","certN","first_failure","selection_receipt","product","detail","raw_sha256"],ledger)
 check(st["planned"]==st["executed"]==16 and st["missing"]==0,
       "TB23 selection mismatch")
 dependency=subprocess.run(["ldd",str(exe)],text=True,capture_output=True,check=True)
 (out/"runtime-dependencies.txt").write_text(dependency.stdout+dependency.stderr)
 check("not found" not in dependency.stdout+dependency.stderr and "libgmp" in dependency.stdout,
       "missing GMP runtime dependency")
 check((inventory(pkg),inventory(src),inventory(view))==initial,"postflight immutable package/source/view mismatch")
 check(manifest(pkg)==28,"postflight manifest mismatch")
 st["postflight"]=True
 check(st["site_bad"]==0 and st["ctrl_bad"]==0,"site/control falsifier")
 (out/"immutability.txt").write_text("package=true source=true execution_view=true frozen_selectors=true\n")
 rc=0
except Exception as exc:
 print("TB23_HARNESS_FAILURE",repr(exc),file=sys.stderr)
finally:
 (out/"execution-boundary.txt").write_text("artifact_id="+str(artifact)+"\nsemantic_source="+sha+"\n"+ "".join(k+"="+str(v)+"\n" for k,v in st.items())+"compile=false\nrelink=false\nbenchmarks=false\nselector497=false\nexit="+str(rc)+"\n")
 with (out/"SHA256SUMS").open("w") as fp:
  for file in sorted(out.rglob("*")):
   if file.is_file() and file.name!="SHA256SUMS":fp.write(sha256(file)+"  "+str(file.relative_to(out))+"\n")
 print("TB23_RESULT",st,"exit",rc)
sys.exit(rc)
PY
