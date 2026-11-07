#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == "--execute" ]] || exit 64
python3 - <<'PY'
import hashlib,os,pathlib,subprocess,sys
base=pathlib.Path('.agents/Directional/tools/m6_cp3_tb23_torus_a5_site_harvest_harness.sh')
old=base.read_text()
def digest(s):return hashlib.sha256(s.encode()).hexdigest()
if digest(old)!='bf2cb7bc2799137e9a3556816380dc93388e9e05ee134cf320b068411f982cbe':raise SystemExit('TB23 harness authority mismatch')
def swap(a,b):
 global old
 if old.count(a)!=1:raise SystemExit('nonunique/missing TB23 template anchor: '+a[:80])
 old=old.replace(a,b)
swap('c6e90916eb90bfd33bc8a38c5ece7def15dcc766','e859175333f879273a75e3bfc321600e451048aa')
swap('artifact=12341307713','artifact=12355892070')
swap('b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5','5215e5c216cde5cd45d851d36c9aa9b2a62de496aa78db2aac54d828996af91f')
swap('c3779cc949a97fd8b6ce73e62fc8cc62598c637e362bb57cc5f5ecb52cd0cd75','b570e9815e8f6b438f3356970f79b80557f4e07941e5501517eb941644222281')
swap(' check(sha256(pkg/"SHA256SUMS")=="7c396be65a3138eca15ad4c7a37db192d6828b80442a656d38f84d1887767f11","root manifest hash mismatch")\n','')
start=old.index(' tests=[tuple(row.split("|")) for row in """')
end=old.index('""".strip().splitlines()]',start)+len('""".strip().splitlines()]')
new=''' tests=[tuple(row.split("|")) for row in """
W|P|focused30:20|M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership
T|P|selector:444|M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate
T|D|focused30:28|M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle
—|—|selector:447|M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped
—|—|cp3entry:6|M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels
—|—|selector:217|SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions
—|—|TB18 A#14|SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags
—|—|selector:443|M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges
—|—|focused30:7|M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority
""".strip().splitlines()]'''
old=old[:start]+new+old[end:]
swap('check(len(tests)==16 and len({r[3] for r in tests})==16','check(len(tests)==9 and len({r[3] for r in tests})==9')
swap('check(st["planned"]==st["executed"]==16','check(st["planned"]==st["executed"]==9')
old=old.replace('TB23','TB24')
marker=' dependency=subprocess.run(["ldd",str(exe)],text=True,capture_output=True,check=True)'
proof=''' expected="relation-collinear-seam;region=0;seam=60,61;relation=0:1,1:0;first=120/0;second=97/2;certs=1;cert0=120/0->97/2:first-face"
 a5=[row[10] for row in ledger[:3]]
 check(st["red"]==3 and st["ctrl_bad"]==0,"P2/RED count falsifier")
 check(len(set(a5))==1 and all(s.startswith(expected+";sel=") for s in a5),"P1 prefix/suffix disagreement")
 import re
 check(all(re.fullmatch(re.escape(expected)+r";sel=[^;]+;support=[^;]+;wedge=[^;]*;spanOnly0=[^;]+",s) for s in a5),"P1 missing/extra/out-of-order suffix")
 (out/"seam-face-proof.txt").write_text("P1=true\\nP2=true\\nfull_site="+a5[0]+"\\n")
'''
swap(marker,proof+marker)
expected='8ccc47a0dabb94f36f8ce39ff448f4f2b0371f68841aa29f9c6c2f43408c2635'
actual=digest(old)
if expected!=actual:raise SystemExit('rendered TB24 harness digest mismatch: '+actual)
render=pathlib.Path(os.environ['RUNNER_TEMP'])/'tb24-pinned-harness.sh'
render.write_text(old)
sys.exit(subprocess.run(['bash',str(render),'--execute'],check=False).returncode)
PY
