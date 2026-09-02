#!/usr/bin/env bash
set -euo pipefail
log="${RUNNER_TEMP}/tb12.log"
exec > >(tee -a "$log") 2>&1
trap 's=$?; echo "tb12_exit=$s"' EXIT
out="${RUNNER_TEMP}/tb12-result"; envd="${RUNNER_TEMP}/envelope"
pkg="${RUNNER_TEMP}/package82/package82"; src="${RUNNER_TEMP}/source"
mkdir -p "$out" "$envd" "$(dirname "$pkg")" "$src"
archive="${RUNNER_TEMP}/package82.zip"
curl --fail --silent --show-error --location -H "Authorization: Bearer ${TOKEN}" \
  -H 'Accept: application/vnd.github+json' \
  "https://api.github.com/repos/${GITHUB_REPOSITORY}/actions/artifacts/9855841174/zip" -o "$archive"
test "$(sha256sum "$archive"|cut -d' ' -f1)" = 4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed
unzip -q "$archive" -d "$envd"
test "$(sha256sum "$envd/package82.tar.gz"|cut -d' ' -f1)" = 58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1
grep -qx 'runtimeExecution=false' "$envd/package82-boundary.txt"
grep -qx 'packageRepair=false' "$envd/package82-boundary.txt"
tar -xzf "$envd/package82.tar.gz" -C "$(dirname "$pkg")"
(cd "$pkg" && sha256sum -c SHA256SUMS) > "$out/pre-manifest.txt"
sarc="$pkg/source/source-71ece3ca184e90858d9222fb014b37c16d292294.tar.gz"
test "$(sha256sum "$sarc"|cut -d' ' -f1)" = 3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e
tar -xzf "$sarc" -C "$src"
test "$(cat "$pkg/metadata/source-commit.txt")" = 71ece3ca184e90858d9222fb014b37c16d292294
test "$(cat "$pkg/metadata/build-exit-code.txt")" = 0
test "$(cat "$pkg/metadata/preflight-exit-code.txt")" = 0
grep -q '^runtimeExecution=false$' "$pkg/metadata/package-envelope.txt"
grep -q '^packageRepair=false$' "$pkg/metadata/fixture-package-contract.txt"
grep -q '^exactArithmeticBackend=GMP$' "$pkg/metadata/package-envelope.txt"
grep -q '^modePreservingEnvelope=true$' "$pkg/metadata/package-envelope.txt"
grep -q '^DIRECTIONAL_ENABLE_GMP:BOOL=ON$' "$pkg/metadata/CMakeCache.txt"
grep -q 'libgmpxx' "$pkg/metadata/gmp-evidence.txt"
grep -q 'libgmp\.so' "$pkg/metadata/gmp-evidence.txt"
for f in "$pkg"/metadata/source-status-*.txt; do test ! -s "$f"; done
test "$(find "$pkg/test-data" -type f|wc -l)" -eq 27

python3 - "$pkg" "$src" "$out" <<'PY'
import hashlib,re,stat,sys
from pathlib import Path
p,s,o=map(Path,sys.argv[1:])
bins=sorted(x for x in (p/'bin').glob('directional_*') if x.is_file())
assert len(bins)==6 and all(stat.S_IMODE(x.stat().st_mode)==0o755 for x in bins)
exp={373:'b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834',374:'d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f',375:'aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0',376:'6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8',377:'7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1',378:'86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8'}
sd=s/'.agents/Directional'; sel={}
for n,h in exp.items():
    f=sd/f'Architecture_M3_CP4c3_Required_Green_Selector_{n}.txt'
    b=f.read_bytes(); a=f.read_text().splitlines()
    assert len(a)==n and len(set(a))==n and hashlib.sha256(b).hexdigest()==h
    sel[n]=a
for n in range(373,378): assert sel[378][:n]==sel[n]
assert sel[378][:377]==sel[377]
assert hashlib.sha256(('\n'.join(sel[378][:365])+'\n').encode()).hexdigest()=='6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1'
diag='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'
assert diag not in sel[378]
cm=(s/'cmake/DirectionalTests.cmake').read_text(); own={}
m=re.search(r'set\(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES(.*?)\)',cm,re.S); assert m
for f in re.findall(r'tests/([^\s)]+\.cpp)',m[1]): own[f]='directional_surface_cell_producer_tests'
for t in ('directional_surface_cell_authority_kernel_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests'):
    m=re.search(r'add_executable\(\s*'+re.escape(t)+r'\s+(.*?)\)',cm,re.S); assert m
    for f in re.findall(r'tests/([^\s)]+\.cpp)',m[1]): own[f]=t
defs={}
for f in (s/'tests').glob('*.cpp'):
    for m in re.finditer(r'\b(?:TEST|TEST_F|TEST_P)\s*\(\s*([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)',f.read_text(errors='replace')):
        defs.setdefault(m[1]+'.'+m[2],[]).append(f.name)
rows=[]
for i,x in enumerate(sel[378],1):
    hits=[(f,own[f]) for f in defs.get(x,[]) if f in own]
    assert len(hits)==1,(i,x,hits)
    rows.append((i,x,hits[0][1]))
dh=[(f,own[f]) for f in defs.get(diag,[]) if f in own]; assert len(dh)==1,dh
(o/'mapping.tsv').write_text(''.join(f'{i}\t{x}\t{t}\n' for i,x,t in rows))
(o/'diagnostic-mapping.tsv').write_text(f'{diag}\t{dh[0][1]}\n')
def census(dst):
    r=[]
    for x in sorted(p.rglob('*'),key=lambda z:z.relative_to(p).as_posix()):
        q=x.relative_to(p).as_posix(); st=x.lstat(); m=stat.S_IMODE(st.st_mode)
        if x.is_file(): r.append(f'F\t{m:04o}\t{st.st_size}\t{hashlib.sha256(x.read_bytes()).hexdigest()}\t{q}')
        elif x.is_dir(): r.append(f'D\t{m:04o}\t0\t-\t{q}')
    dst.write_text('\n'.join(r)+'\n')
census(o/'pre.census')
PY

printf 'ordinal\tidentity\ttarget\tresult\tcredit\texit\n' > "$out/results.tsv"
first_red=0; pass=0; red=0; proc=0
while IFS=$'\t' read -r ord ident target; do
  rlog="$out/ordinal-$(printf '%03d' "$ord").log"; set +e
  (cd "$pkg" && "$pkg/bin/$target" "--gtest_filter=$ident" --gtest_color=no) >"$rlog" 2>&1
  rc=$?; set -e; proc=$((proc+1))
  test "$(grep -Fxc "[ RUN      ] $ident" "$rlog" || true)" -eq 1
  test "$(grep -c '^\[ RUN      \]' "$rlog" || true)" -eq 1
  if [ "$rc" -eq 0 ]; then result=PASS; pass=$((pass+1)); else result=RED; red=$((red+1)); fi
  if [ "$first_red" -eq 0 ]; then credit=gate; [ "$rc" -eq 0 ] || first_red="$ord"; else credit=report-only; fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\n' "$ord" "$ident" "$target" "$result" "$credit" "$rc" >> "$out/results.tsv"
done < "$out/mapping.tsv"
test "$proc" -eq 378

diag_ident='GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable'
diag_target="$(cut -f2 "$out/diagnostic-mapping.tsv")"
dlog="$out/non-gating-diagnostic.log"; set +e
(cd "$pkg" && "$pkg/bin/$diag_target" "--gtest_filter=$diag_ident" --gtest_color=no) >"$dlog" 2>&1
diag_rc=$?; set -e
test "$(grep -Fxc "[ RUN      ] $diag_ident" "$dlog" || true)" -eq 1
test "$(grep -c '^\[ RUN      \]' "$dlog" || true)" -eq 1
[ "$diag_rc" -eq 0 ] && diag_result=PASS || diag_result=RED
printf 'identity\ttarget\tresult\tcredit\texit\n%s\t%s\t%s\tnon-gating\t%s\n' \
  "$diag_ident" "$diag_target" "$diag_result" "$diag_rc" > "$out/non-gating-diagnostic.tsv"

prefix365=true
awk -F '\t' 'NR>1&&$1<=365&&$4!="PASS"{bad=1} END{exit bad}' "$out/results.tsv" || prefix365=false
ord366="$(grep -E 'NotProductionReady|RotationRayOrderKeyCollision' "$out/ordinal-366.log" | tail -n 1 || true)"
printf '%s\n' "$ord366" > "$out/ordinal366-evidence.txt"
frontier=false
[[ "$first_red" = 366 && "$ord366" == *'rotationSystemReason=RotationRayOrderKeyCollision'* \
  && "$ord366" == *'sourceVertex=47'* && "$ord366" == *'certificationAttempt=0'* \
  && "$ord366" == *'certificationCutEdges=0'* ]] && frontier=true

python3 - "$pkg" "$out" <<'PY'
import hashlib,stat,sys
from pathlib import Path
p,o=map(Path,sys.argv[1:]); r=[]
for x in sorted(p.rglob('*'),key=lambda z:z.relative_to(p).as_posix()):
    q=x.relative_to(p).as_posix(); st=x.lstat(); m=stat.S_IMODE(st.st_mode)
    if x.is_file(): r.append(f'F\t{m:04o}\t{st.st_size}\t{hashlib.sha256(x.read_bytes()).hexdigest()}\t{q}')
    elif x.is_dir(): r.append(f'D\t{m:04o}\t0\t-\t{q}')
(o/'post.census').write_text('\n'.join(r)+'\n')
PY
cmp "$out/pre.census" "$out/post.census"
(cd "$pkg" && sha256sum -c SHA256SUMS) > "$out/post-manifest.txt"
printf '%s\n' "package=82" "selector=378" "processes=$proc" "passes=$pass" "reds=$red" \
  "firstRedOrdinal=$first_red" "acceptedPrefix365=$prefix365" "ordinal366ExpectedFrontier=$frontier" \
  "nonGatingDiagnosticIdentity=$diag_ident" "nonGatingDiagnosticResult=$diag_result" "nonGatingDiagnosticExit=$diag_rc" \
  "runtimeExecution=true" "configureExecution=false" "compileExecution=false" "relinkExecution=false" \
  "packageRepair=false" "generatedDiscovery=false" "productMutation=false" "testMutation=false" \
  "fixtureMutation=false" "selectorMutation=false" "benchmarkExecution=false" > "$out/summary.env"
cat "$out/summary.env"
