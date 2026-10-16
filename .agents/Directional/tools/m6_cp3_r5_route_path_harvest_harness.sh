#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == --execute ]] || exit 64
: "${GITHUB_REPOSITORY:?}" "${GH_TOKEN:?}" "${RUNNER_TEMP:?}" "${TURN_ID:?}"
r="$RUNNER_TEMP/$TURN_ID"; o="$RUNNER_TEMP/$TURN_ID-result"
mkdir -p "$r/p" "$r/s" "$r/v/bin" "$r/run" "$o/raw"
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
executed=0; red=0; missing=0; postflight=false; planned=0
finish() {
  rc=$?; set +e
  printf 'artifact_id=12015849679\nsource_sha=a143af264bc8b33f0e1b2f8def16b2479b53d5fc\nplanned=44\nexecuted=%d\nred=%d\nmissing=%d\npostflight=%s\ncompile=false\nrelink=false\nbenchmarks=false\nselector497=false\nexit=%d\n' "$executed" "$red" "$missing" "$postflight" "$rc" > "$o/execution-boundary.txt"
  (cd "$o"; find . -type f ! -name SHA256SUMS -print0 | sort -z | xargs -0 sha256sum > SHA256SUMS)
}
trap finish EXIT
die() { echo "ORCHESTRATION_FAILURE $*" >&2; exit 90; }
sha() { sha256sum "$1" | cut -d' ' -f1; }
z="92a014a6d0bc4de3bef55b2ebcec2fd8c5095d3b65f90eb7bd79567dbcb10444"
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/12015849679" > "$r/provider.json"
grep -q "sha256:$z" "$r/provider.json" || die 'provider digest'
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/12015849679/zip" -o "$r/a.zip"
[[ "$(sha "$r/a.zip")" == "$z" ]] || die 'artifact digest'
unzip -q "$r/a.zip" -d "$r/p"
p="$r/p"; s="$r/s"
[[ "$(sha "$p/SHA256SUMS")" == eb8661cbea6538b2b2037df06ba66ff5663afaf825e958d12262c78750bdd801 ]] || die manifest
(cd "$p"; sha256sum -c SHA256SUMS) > "$o/manifest-before.txt" || die integrity
[[ "$(grep -c ': OK$' "$o/manifest-before.txt")" -eq 28 ]] || die manifest_count
[[ "$(cat "$p/metadata/source-commit.txt")" == a143af264bc8b33f0e1b2f8def16b2479b53d5fc ]] || die source_identity
grep -qx 'exactArithmeticBackend=GMP' "$p/metadata/command-boundary.txt" || die arithmetic
grep -qx 'runtimeExecution=false' "$p/metadata/command-boundary.txt" || die compile_only
a="$p/source/source-a143af264bc8b33f0e1b2f8def16b2479b53d5fc.tar.gz"
[[ "$(sha "$a")" == f554f5f19a6c264a99ddba7b1538485ae344b63b3509bdab26ab8a113218a3c3 ]] || die packaged_source_hash
tar -xzf "$a" -C "$s"
for pair in \
 '.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_30.txt:1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6' \
 '.agents/Directional/Architecture_M6_CP2_Required_Green_Focused_12.txt:2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed' \
 '.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt:d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414' \
 '.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv:9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707'; do
 [[ "$(sha "$s/${pair%%:*}")" == "${pair##*:}" ]] || die "frozen selector $pair"
done
(cd "$p"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/p0"
(cd "$s"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/s0"
cp -a "$p/bin/." "$r/v/bin/"
mkdir -p "$r/v/test-data/benchmarks"; cp -a "$s/benchmarks/fixtures" "$r/v/test-data/benchmarks/"
(cd "$r/v"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/v0"
inventory="$GITHUB_WORKSPACE/.agents/Directional/Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv"
[[ -f "$inventory" ]] || die 'census inventory missing'
[[ "$(sha "$inventory")" == de05a7bd5ca27eb243156ecd38434fbc69d06f4b791bdd3dbcfc5982c273a865 ]] || die 'census inventory drift'
mapfile -t tests < <(tail -n +2 "$inventory" | cut -f2)
mapfile -t historical_ordinals < <(tail -n +2 "$inventory" | cut -f1)
[[ "${#tests[@]}" == 39 ]] || die "identity count ${#tests[@]}"
[[ "$(printf '%s\n' "${tests[@]}" | sort -u | wc -l)" == 39 ]] || die 'duplicate identities'

printf 'index\thistorical_ordinal\tidentity\towner\texit\tselected\tpassed\tverdict\n' > "$o/ledger.tsv"
for i in "${!tests[@]}"; do
 historical="${historical_ordinals[i]}"
 [[ "$historical" == 405 ]] && continue # separate non-interior mechanism, not part of 44
 planned=$((planned+1)); n=$planned; name="${tests[i]}"; exe=directional_surface_cell_producer_tests
 if [[ ! -x "$r/v/bin/$exe" ]]; then
  missing=$((missing+1)); echo "MISSING_IMMUTABLE_EXECUTABLE $exe ($name)";
  printf '%s\t%s\t%s\t%s\t-\t0\t0\tNOT_EXECUTED\n' "$n" "$historical" "$name" "$exe" >> "$o/ledger.tsv"
  continue
 fi
 mkdir -p "$r/run/$n"
 set +e
 (cd "$r/run/$n"; /usr/bin/time -v env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$r/v/bin/$exe" --gtest_filter="$name") > "$o/raw/$n.log" 2>&1
 code=$?
 set -e
 cat "$o/raw/$n.log"
 picked="$(grep -c '^\[ RUN      \] ' "$o/raw/$n.log" || true)"
 passed="$(grep -c '^\[       OK \] ' "$o/raw/$n.log" || true)"
 skipped="$(grep -c '^\[  SKIPPED \] ' "$o/raw/$n.log" || true)"
 if [[ "$picked" != 1 || "$skipped" != 0 ]]; then
  missing=$((missing+1))
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\tNOT_SELECTED\n' "$n" "$historical" "$name" "$exe" "$code" "$picked" "$passed" >> "$o/ledger.tsv"
  echo "NOT_SELECTED ordinal=$n identity=$name selected=$picked skipped=$skipped"
  continue
 fi
 verdict=RED; [[ "$code" == 0 && "$passed" == 1 ]] && verdict=PASS
 printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$n" "$historical" "$name" "$exe" "$code" "$picked" "$passed" "$verdict" >> "$o/ledger.tsv"
 executed=$((executed+1))
 if [[ "$verdict" == RED ]]; then red=$((red+1)); fi
done
# Additional named supplemental witnesses (two Phase14 identities require a
# separate historical test executable and are deliberately outside this rung).
# Every identity executes independently, including after an observed RED.
extra=(
  SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer
  SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard
  SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement
  SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate
  SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress
  M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm
)
for i in "${!extra[@]}"; do
 planned=$((planned+1)); n=$planned; name="${extra[i]}"; exe=directional_surface_cell_producer_tests
 if [[ ! -x "$r/v/bin/$exe" ]]; then
  missing=$((missing+1))
  printf '%s\tSUPPLEMENTAL\t%s\t%s\t-\t0\t0\tNOT_EXECUTED\n' "$n" "$name" "$exe" >> "$o/ledger.tsv"
  continue
 fi
 mkdir -p "$r/run/$n"
 set +e
 (cd "$r/run/$n"; /usr/bin/time -v env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$r/v/bin/$exe" --gtest_filter="$name") > "$o/raw/$n.log" 2>&1
 code=$?
 set -e
 cat "$o/raw/$n.log"
 picked="$(grep -c '^\[ RUN      \] ' "$o/raw/$n.log" || true)"
 passed="$(grep -c '^\[       OK \] ' "$o/raw/$n.log" || true)"
 skipped="$(grep -c '^\[  SKIPPED \] ' "$o/raw/$n.log" || true)"
 if [[ "$picked" != 1 || "$skipped" != 0 ]]; then
  missing=$((missing+1))
  printf '%s\tSUPPLEMENTAL\t%s\t%s\t%s\t%s\t%s\tNOT_SELECTED\n' "$n" "$name" "$exe" "$code" "$picked" "$passed" >> "$o/ledger.tsv"
  continue
 fi
 verdict=RED; [[ "$code" == 0 && "$passed" == 1 ]] && verdict=PASS
 printf '%s\tSUPPLEMENTAL\t%s\t%s\t%s\t%s\t%s\t%s\n' "$n" "$name" "$exe" "$code" "$picked" "$passed" "$verdict" >> "$o/ledger.tsv"
 executed=$((executed+1))
 if [[ "$verdict" == RED ]]; then red=$((red+1)); fi
done
[[ "$planned" == 44 ]] || die "planned count $planned"
# Parse each independent process's route and actual owning-cell path evidence.
python3 - "$o" <<'PY_HARVEST'
import collections, csv, pathlib, re, sys
out=pathlib.Path(sys.argv[1])
fields=['a2bProbeFailure','a2bProbeFirstFailedCondition','a2bProbeFromFace','a2bProbeToFace','a2bProbeFromAttachment','a2bProbeToAttachment','a2bProbeCarrierFirstFace','a2bProbeCarrierSecondFace','a2bProbeRouteStepCount','a2bProbeFirstPathFaces','a2bProbeSecondPathFaces']
def get(s,k):
 m=re.search(re.escape(k)+r'=([^;\r\n"]+)',s)
 return m.group(1) if m else ''
def face(s):
 if not re.fullmatch(r'[0-9]+(?:,[0-9]+){2}',s): return None
 x=frozenset(map(int,s.split(',')))
 return x if len(x)==3 else None
def rows(s):
 if not re.fullmatch(r'[0-9]+(?:,[0-9]+)*',s): return None
 return tuple(sorted(set(map(int,s.split(',')))))
ledger=list(csv.DictReader((out/'ledger.tsv').open(),delimiter='\t'))
counts=collections.Counter(); partitions=collections.Counter(); multiplicities=collections.Counter(); missing=[]
with (out/'route-path-reconciliation.tsv').open('w',newline='') as fp:
 writer=csv.writer(fp,delimiter='\t')
 writer.writerow(['index','historical_ordinal','identity','verdict','probe_emitted']+fields+['route_step_keys','carrier_edge','to_face_incident_route_steps','from_face_incident_route_steps','membership','first_path_includes_from_face','second_path_includes_to_face','probe_occurrences','evidence_status'])
 for row in ledger:
  raw=(out/'raw'/(row['index']+'.log')).read_text(errors='replace')
  v={k:get(raw,k) for k in fields}
  probe_lines=[line for line in raw.splitlines() if 'a2bProbeRouteStepCount=' in line]
  occurrences=[(get(line,'a2bProbeRouteStepCount'),re.findall(r'a2bProbeRouteStep\[([0-9]+)\]=([0-9]+,[0-9]+)',line)) for line in probe_lines]
  actual=occurrences[0][1] if occurrences else []
  occurrences_consistent=bool(occurrences) and all(count.isdigit() and int(count)==len(steps) and steps==actual for count,steps in occurrences)
  n=int(v['a2bProbeRouteStepCount']) if v['a2bProbeRouteStepCount'].isdigit() else -1
  indices=[int(i) for i,k in actual]
  edges=[frozenset(map(int,k.split(','))) for i,k in actual]
  f,t=face(v['a2bProbeFromAttachment']),face(v['a2bProbeToAttachment'])
  c,d=face(v['a2bProbeCarrierFirstFace']),face(v['a2bProbeCarrierSecondFace'])
  carrier=(c & d) if c and d else frozenset()
  pf,pt=rows(v['a2bProbeFirstPathFaces']),rows(v['a2bProbeSecondPathFaces'])
  rf=int(v['a2bProbeFromFace']) if v['a2bProbeFromFace'].isdigit() else None
  rt=int(v['a2bProbeToFace']) if v['a2bProbeToFace'].isdigit() else None
  hit_to=sum(bool(t and e <= t) for e in edges)
  hit_from=sum(bool(f and e <= f) for e in edges)
  matched=int(f in (c,d))+int(t in (c,d)) if all((f,t,c,d)) else -1
  membership={0:'neither',1:'one',2:'both'}.get(matched,'UNRESOLVED')
  complete=(row['verdict'] in ('RED','PASS') and bool(v['a2bProbeFailure']) and n>0 and len(actual)==n and occurrences_consistent and indices==list(range(n)) and all(len(e)==2 for e in edges) and all(x is not None for x in (f,t,c,d,pf,pt,rf,rt)) and len(carrier)==2)
  if not complete: missing.append(row['identity'])
  multiplicities[len(occurrences)]+=1
  counts[(v['a2bProbeFirstFailedCondition'],row['verdict'])]+=1
  partitions[(v['a2bProbeFirstFailedCondition'],membership,hit_to)]+=1
  writer.writerow([row['index'],row['historical_ordinal'],row['identity'],row['verdict'],int(any(v.values()))]+[v[k] for k in fields]+['|'.join(k for i,k in actual),','.join(map(str,sorted(carrier))),hit_to,hit_from,membership,rf in pf if pf is not None else '',rt in pt if pt is not None else '',len(occurrences),'COMPLETE' if complete else 'INCOMPLETE'])
with (out/'route-path-summary.txt').open('w') as fp:
 fp.write('route_key_semantics=source-edge SourceVertexId endpoint pair for each oriented route step\n')
 fp.write('to_incidence_test=route edge key is subset of canonical ToAttachment face vertex triple\n')
 fp.write('path_faces=distinct source-face row indices of each owning cell actual traced boundary path\n')
 fp.write('counts='+repr(sorted(counts.items()))+'\n')
 fp.write('first_rejection_membership_to_incidence='+repr(sorted(partitions.items()))+'\n')
 fp.write('probe_multiplicity='+repr(sorted(multiplicities.items()))+'\n')
 fp.write('missing_evidence='+repr(missing)+'\n')
 fp.write('historical_ordinal_405=EXCLUDED; separate non-interior mechanism\n')
 fp.write('producer_correction=NOT_AUTHORIZED\n')
if missing: raise SystemExit('Incomplete route/path evidence: '+repr(missing))
PY_HARVEST
(cd "$p"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/p1"
(cd "$s"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/s1"
(cd "$r/v"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/v1"
cmp -s "$r/p0" "$r/p1" || die package_mutation
cmp -s "$r/s0" "$r/s1" || die source_mutation
cmp -s "$r/v0" "$r/v1" || die execution_view_mutation
(cd "$p"; sha256sum -c SHA256SUMS) > "$o/manifest-after.txt" || die postflight_manifest
echo 'package=true source=true execution_view=true selector=true' > "$o/immutability.txt"
postflight=true
echo "ROUTE_PATH_MEASUREMENT_COMPLETE: $executed/44 executed; $red RED; $missing missing; all independent identities attempted."
[[ "$executed" == 44 && "$missing" == 0 && "$postflight" == true ]] || die 'incomplete endpoint-chart measurement'
exit 0
