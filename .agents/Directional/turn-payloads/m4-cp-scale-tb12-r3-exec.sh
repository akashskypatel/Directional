#!/usr/bin/env bash
set -euo pipefail
: "${RUNNER_TEMP:?}"; : "${GITHUB_RUN_ID:?}"; : "${TURN_ID:?}"
SAFE="$(printf '%s' "$TURN_ID" | tr -c 'A-Za-z0-9._-' '-')"
ROOT="$RUNNER_TEMP/$SAFE"; PKG="$ROOT/package"; SOURCE="$ROOT/source"; VIEW="$ROOT/execution-view"
RESULT="$RUNNER_TEMP/${SAFE}-result"; LOG="$RUNNER_TEMP/${SAFE}.log"; RUNTIME="$ROOT/runtime-r3"
mkdir -p "$RESULT/raw" "$RESULT/resources" "$RUNTIME"; exec > >(tee -a "$LOG") 2>&1
SEL="$SOURCE/.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt"
PREF="$SOURCE/.agents/Directional/Architecture_M4_CP_SCALE_CB8_Required_Green_Selector_425.txt"
EXPECT_SOURCE='a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9'
EXPECT_MANIFEST='61bf5fcabfb8a41f2de32b0ea7e1b3059579ecdd5ac07862cb657c46eedd3db5'
EXPECT_SOURCE_ARCH='4be61bb45a1f925c4cff0cf5b6cc0b263948417b6271c43a919808f5c5133e99'
EXPECT_SEL='41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114'
EXPECT_PREF='e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b'
EXPECT_AUTH='78fd5072420e5fa2b92c9d86aacf989cb2718c48e2f66550e14602f083efdb27'
EXPECT_PROD='18a24349093397ac8ea7bd3074e98defda55a26bf602c359fa2716421da9d6ee'
EXPECT_OBJ='c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3'
EXPECT_RAW='7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e'
EXPECT_META='22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76'
sha(){ sha256sum "$1" | awk '{print $1}'; }
fail(){ echo "ORCHESTRATION_FAILURE: $*" >&2; echo "orchestration_failure=true" >> "$RESULT/tb12-r3-summary.txt"; exit 90; }
census(){ python3 - "$1" "$2" <<'PY'
import hashlib,os,pathlib,stat,sys
r=pathlib.Path(sys.argv[1]).resolve(); o=pathlib.Path(sys.argv[2]); rows=[]
for p in [r,*sorted(r.rglob('*'),key=lambda x:x.relative_to(r).as_posix())]:
 rel='.' if p==r else p.relative_to(r).as_posix(); s=p.lstat(); m=format(stat.S_IMODE(s.st_mode),'o')
 if stat.S_ISREG(s.st_mode):
  h=hashlib.sha256(); f=p.open('rb')
  for b in iter(lambda:f.read(1048576),b''): h.update(b)
  f.close(); k,d,t='file',h.hexdigest(),'-'
 elif stat.S_ISDIR(s.st_mode): k,d,t='directory','-','-'
 elif stat.S_ISLNK(s.st_mode): k,d,t='symlink','-',os.readlink(p)
 else: k,d,t='other','-','-'
 rows.append(f'{rel}\t{k}\t{m}\t{s.st_size}\t{d}\t{t}\n')
o.write_text(''.join(rows))
PY
}
# Extend the reusable immutable preflight with TB12-R3-specific frozen facts.
[[ -f "$RESULT/package-census-before.tsv" && -f "$RESULT/source-census-before.tsv" && -f "$RESULT/execution-view-before.tsv" ]] || fail 'reusable preflight census absent'
[[ "$(sha "$PKG/SHA256SUMS")" == "$EXPECT_MANIFEST" ]] || fail 'manifest hash mismatch'
ARCH="$PKG/source/source-${EXPECT_SOURCE}.tar.gz"; [[ "$(sha "$ARCH")" == "$EXPECT_SOURCE_ARCH" ]] || fail 'source archive hash mismatch'
[[ "$(sha "$SEL")" == "$EXPECT_SEL" && "$(grep -cve '^[[:space:]]*$' "$SEL")" == 426 ]] || fail 'selector426 mismatch'
[[ "$(sha "$PREF")" == "$EXPECT_PREF" && "$(grep -cve '^[[:space:]]*$' "$PREF")" == 425 ]] || fail 'selector425 mismatch'
[[ "$(head -n 425 "$SEL" | sha256sum | awk '{print $1}')" == "$EXPECT_PREF" ]] || fail 'selector425 prefix mismatch'
[[ ! -e "$SOURCE/.agents/Directional/Architecture_M4_CP_SCALE_CB13_Required_Green_Selector_427.txt" ]] || fail 'selector427 unexpectedly present'
AUTH="$PKG/bin/directional_surface_cell_authority_kernel_tests"; PROD="$PKG/bin/directional_surface_cell_producer_tests"
[[ "$(sha "$AUTH")" == "$EXPECT_AUTH" && "$(stat -c '%a' "$AUTH")" == 755 ]] || fail 'authority executable mismatch'
[[ "$(sha "$PROD")" == "$EXPECT_PROD" && "$(stat -c '%a' "$PROD")" == 755 ]] || fail 'producer executable mismatch'
FIX="$SOURCE/benchmarks/fixtures/milestone-g"
[[ "$(sha "$FIX/genus_two.obj")" == "$EXPECT_OBJ" && "$(sha "$FIX/genus_two.rawfield")" == "$EXPECT_RAW" && "$(sha "$FIX/genus_two.fixturemeta.json")" == "$EXPECT_META" ]] || fail 'genus-two fixture mismatch'
MAP="$RESULT/identity-map.tsv"; [[ -f "$MAP" ]] || fail 'identity map absent'
a=$(awk -F'\t' 'NR>1&&$3=="directional_surface_cell_authority_kernel_tests"{n++}END{print n+0}' "$MAP")
p=$(awk -F'\t' 'NR>1&&$3=="directional_surface_cell_producer_tests"{n++}END{print n+0}' "$MAP")
c=$(awk -F'\t' 'NR>1&&$3=="directional_surface_cell_completion_tests"{n++}END{print n+0}' "$MAP")
v=$(awk -F'\t' 'NR>1&&$3=="directional_surface_cell_validation_tests"{n++}END{print n+0}' "$MAP")
[[ "$a/$p/$c/$v" == '30/280/75/41' ]] || fail "owner census $a/$p/$c/$v"
printf 'authority=%s\nproducer=%s\ncompletion=%s\nvalidation=%s\n' "$a" "$p" "$c" "$v" > "$RESULT/owner-census.txt"
printf 'gate\tordinal\tidentity\tbinary\texit\tselected\tok\tskipped\tresult\tstdout_sha256\tstderr_sha256\n' > "$RESULT/execution-ledger.tsv"
run_one(){
 local gate="$1" ord="$2" id="$3" bin="$4" bounded="$5"; local stem="${gate,,}-$(printf '%03d' "$ord")" w="$RUNTIME/$stem"
 local out="$RESULT/raw/$stem.stdout" err="$RESULT/raw/$stem.stderr" res="$RESULT/resources/$stem.time.txt" code
 mkdir -p "$w"; set +e
 if [[ "$bounded" == yes ]]; then (cd "$w" && /usr/bin/time -v -o "$res" timeout -k 5s 180s env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/$bin" --gtest_filter="$id") >"$out" 2>"$err"; code=$?
 else (cd "$w" && /usr/bin/time -v -o "$res" env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$VIEW/bin/$bin" --gtest_filter="$id") >"$out" 2>"$err"; code=$?; fi
 set -e; cat "$out"; cat "$err" >&2
 local selected ok skipped result=RED; selected=$(grep -Ec '^\[ RUN      \] ' "$out" || true); ok=$(grep -Ec '^\[       OK \] ' "$out" || true); skipped=$(grep -Ec '^\[  SKIPPED \] ' "$out" || true)
 [[ "$code" -eq 0 && "$selected" -eq 1 && "$ok" -eq 1 && "$skipped" -eq 0 ]] && result=PASS
 printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$gate" "$ord" "$id" "$bin" "$code" "$selected" "$ok" "$skipped" "$result" "$(sha "$out")" "$(sha "$err")" >> "$RESULT/execution-ledger.tsv"
 [[ "$result" == PASS ]]
}
outcome='GATE_A_PASS'; gate_a_pass=0; gate_b_pass=0; selector_executed=0; selector_pass=0; selector_red=0
A=(
'FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents'
'FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence'
'FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper'
'FieldTransportAtlas.BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport')
for i in 0 1 2 3; do if run_one A "$((i+1))" "${A[$i]}" directional_surface_cell_authority_kernel_tests yes; then gate_a_pass=$((gate_a_pass+1)); else outcome='GATE_A_RED'; break; fi; done
if [[ "$gate_a_pass" -eq 4 ]]; then
 B='M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology'
 if run_one B 1 "$B" directional_surface_cell_producer_tests yes; then gate_b_pass=1; outcome='GATE_B_PASS'; else outcomô'DtDUô%õ$TBs²f¦f¦bµ²"FvFUö÷72"ÖWBbb"FvFUö%÷72"ÖWÕÓ²FVà¢÷WF6öÖSÒu4TÄT5Dõ%õ52p¢vÆRe3ÒBuÇBr&VB×"÷&BB&â7&3²Fòµ²"F÷&B"ÓÒ÷&FæÂÕÒbb6öçFçVS²6VÆV7F÷%öWV7WFVCÒB6VÆV7F÷%öWV7WFVB³²b'VåööæR2"F÷&B""FB""F&â"æó²FVâ6VÆV7F÷%÷73ÒB6VÆV7F÷%÷72³²VÇ6R6VÆV7F÷%÷&VCÒB6VÆV7F÷%÷&VB³²÷WF6öÖSÒu4TÄT5Dõ%õ$TBs²f²FöæRÂ"DÔ ¢µ²"G6VÆV7F÷%öWV7WFVB"ÖWC#bÕÒÇÂfÂ'6VÆV7F÷"WV7WFöâ6÷VçBG6VÆV7F÷%öWV7WFVB ¦f¦6Vç7W2"E´r""E$U5TÅB÷6¶vRÖ6Vç7W2×&ÖgFW"çG7b#²6Vç7W2"E4õU$4R""E$U5TÅB÷6÷W&6RÖ6Vç7W2×"ÖÖgFW"çG7b#²6Vç7W2"EdUr""E$U5TÅBöWV7WFöâ×fWr×#2ÖgFW"çG7b ¦6××2"E$U5TÅB÷6¶vRÖ6Vç7W2Ö&Vf÷&RçG7b""E$U5TÅB÷6¶vRÖ6Vç7W2×#2ÖgFW"çG7b"ÇÂfÂw6¶vR6Vç7W26ævVBp¦6××2"E$U5TÅB÷6÷W&6RÖ6Vç7W2Ö&Vf÷&RçG7b""E$U5TÅB÷6÷W&6RÖ6Vç7W2×#2ÖgFW"çG7b"ÇÂfÂw6÷W&6R6Vç7W26ævVBp¦6××2"E$U5TÅBöWV7WFöâ×fWrÖ&Vf÷&RçG7b""E$U5TÅBöWV7WFöâ×fWr×#2ÖgFW"çG7b"ÇÂfÂvWV7WFöâfWr6Vç7W26ævVBp¥µ²"B6"DdövVçW5÷Gvòæö&¢""ÓÒ"DUT5Eôô$¢"bb"B6"DdövVçW5÷Gvòç&vfVÆB""ÓÒ"DUT5Eõ$r"bb"B6"DdövVçW5÷GvòæfGW&VÖWFæ§6öâ""ÓÒ"DUT5EôÔUD"ÕÒÇÂfÂvfGW&R÷7FfÆvBÖ6ÖF6p¦ÆVFvW%÷6ÒB6"E$U5TÅBöWV7WFöâÖÆVFvW"çG7b"¦6Bâ"E$U5TÅB÷F#"×#2×7VÖÖ'çGB"ÃÅ5TÔÔ%§GW&ãÒEEU$åô@§'VåöCÒDtDT%õ%Tåô@¦'Ff7EöCÓS#33#S§6÷W&6SÒDUT5Eõ4õU$4P¦÷WF6öÖSÒF÷WF6öÖP¦vFUö÷73ÒFvFUö÷72ó@¦vFUö%÷73ÒFvFUö%÷72ó§6VÆV7F÷%öWV7WFVCÒG6VÆV7F÷%öWV7WFVBóC#`§6VÆV7F÷%÷73ÒG6VÆV7F÷%÷70§6VÆV7F÷%÷&VCÒG6VÆV7F÷%÷&V@¦ÆVFvW%÷6#ScÒFÆVFvW%÷6§÷7FfÆvD6ö×ÆWFS×G'VP¦6öæfwW&TWV7WFöãÖfÇ6P¦6ö×ÆTWV7WFöãÖfÇ6P§&VÆæ´WV7WFöãÖfÇ6P¦6öFTvVæW&FöãÖfÇ6P¦6ÖöDWV7WFöãÖfÇ6P§6¶vU&W#ÖfÇ6P§6÷W&6T×WFFöãÖfÇ6P§FW7D×WFFöãÖfÇ6P¦fGW&T×WFFöãÖfÇ6P§6VÆV7F÷$×WFFöãÖfÇ6P¦&Væ6Ö&´WV7WFöãÖfÇ6P¦F66÷fW'Æ7DVÇfW'6öä7FfGÖfÇ6P¥5TÔÔ%¦6Bâ"E$U5TÅBöWV7WFöâÖ&÷VæF'çGB"ÃÄ$õTäD%§'VçFÖTWV7WFöã×G'VP§'VçFÖTvFTÒFvFUö÷72ó@§'VçFÖTvFT#ÒFvFUö%÷72ó§'VçFÖU6VÆV7F÷#ÒG6VÆV7F÷%öWV7WFVBóC#`¦&Væ6Ö&´WV7WFöãÖfÇ6P¦6öæfwW&TWV7WFöãÖfÇ6P¦6ö×ÆTWV7WFöãÖfÇ6P§&VÆæ´WV7WFöãÖfÇ6P§6¶vU&W#ÖfÇ6P¦6ÖöDWV7WFöãÖfÇ6P§6÷W&6UFW7DfGW&U6VÆV7F÷$×WFFöãÖfÇ6P§÷7FfÆvD6ö×ÆWFS×G'VP¤$õTäD%¦6B"E$U5TÅB÷F#"×#2×7VÖÖ'çGB  