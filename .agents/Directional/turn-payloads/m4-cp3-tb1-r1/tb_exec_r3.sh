#!/usr/bin/env bash
set -euo pipefail

BASE_REF='ec0912f759adbe6bf3c68a363e74e4ee40952962'
BASE_PATH='.agents/Directional/turn-payloads/m4_cp3_tb1_exec_harness.sh'
BASE_BLOB='0e6baf1d4090b022124b55891732617045126265'
base_json="$RUNNER_TEMP/tb-r1-base.json"
base="$RUNNER_TEMP/tb-r1-base.sh"
harness="$RUNNER_TEMP/tb-r1-harness.sh"

gh api --method GET "repos/$GITHUB_REPOSITORY/contents/$BASE_PATH?ref=$BASE_REF" > "$base_json"
test "$(jq -r .sha "$base_json")" = "$BASE_BLOB"
jq -r .content "$base_json" | tr -d '\n' | base64 --decode > "$base"
bash -n "$base"

python3 - "$base" "$harness" <<'PY'
from pathlib import Path
import sys
src = Path(sys.argv[1]).read_text(encoding='utf-8')
repls = {
    "ARTIFACT_ID=10182447649": "ARTIFACT_ID=10185370005",
    "EXPECTED_ARTIFACT_NAME='m4-cp3-cb2-package118-result-34555543569'": "EXPECTED_ARTIFACT_NAME='m4-cp3-cb3-package-result-34564069513'",
    "EXPECTED_ZIP_SHA='1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5'": "EXPECTED_ZIP_SHA='9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8'",
    "EXPECTED_SOURCE_SHA='c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc'": "EXPECTED_SOURCE_SHA='fd532c2f768d0ff6493260deb670cb34b6757712'",
    'ROOT="${RUNNER_TEMP}/m4-cp3-tb1-exec"': 'ROOT="${RUNNER_TEMP}/m4-cp3-tb1-r1-exec"',
    'ZIP="${ROOT}/package118.zip"': 'ZIP="${ROOT}/package119.zip"',
    'ACTIVITY="${RUNNER_TEMP}/m4-cp3-tb1-exec.log"': 'ACTIVITY="${RUNNER_TEMP}/m4-cp3-tb1-r1-exec.log"',
    'package118': 'package119',
    'M4-CP3-TB1-REV': 'M4-CP3-TB1-R1-REV',
}
for old, new in repls.items():
    if old not in src:
        raise SystemExit(f'missing expected adaptation token: {old}')
    src = src.replace(old, new)
anchor = 'run_range cumulative394 1 394\n\n'
if src.count(anchor) != 1:
    raise SystemExit(f'expected one receipt injection anchor, found {src.count(anchor)}')
receipt = r'''set +e
python3 - "$RESULT" <<'PY_RECEIPTS'
import hashlib, json, pathlib, re, sys
r = pathlib.Path(sys.argv[1])
corrected = [386,388,389,390,391,392,394]
phases = ['focused-a','focused-b']
receipts_dir = r/'receipts'; receipts_dir.mkdir(exist_ok=True)
errors=[]; parsed={}; raw_by={}
for phase in phases:
  parsed[phase]={}; raw_by[phase]={}
  for ordinal in corrected:
    log=(r/'raw'/f'{phase}-{ordinal:03d}.log').read_bytes()
    prefix=f'M4_CP3_BASELINE_RECEIPT ordinal={ordinal}'.encode()
    lines=[line for line in log.splitlines(keepends=True) if line.startswith(prefix)]
    if len(lines)!=1:
      errors.append(f'{phase} ordinal={ordinal} receipt_count={len(lines)}')
      continue
    raw=lines[0]; raw_by[phase][ordinal]=raw
    (receipts_dir/f'{phase}-{ordinal}.receipt').write_bytes(raw)
    text=raw.decode('utf-8').rstrip('\r\n')
    kv=dict(re.findall(r'([A-Za-z][A-Za-z0-9]*)=([^ ]+)',text)); parsed[phase][str(ordinal)]=kv
    try:
      if ordinal==386:
        assert int(kv['components'])==1 and kv['hasExterior'] in ('1','true') and kv['exteriorDemandOdd'] in ('1','true') and int(kv['terminalSpans'])==3
      elif ordinal==388:
        assert re.fullmatch(r'\[[0-9,-]+\]',kv['counts']); int(kv['minimumFlipCount']); int(kv['lexReceipts'])
      elif ordinal==389:
        assert [int(kv[k]) for k in ('onePreferred','oneFinal','largerPreferred','largerFinal')]==[1,2,2,1]
      elif ordinal==390:
        span=int(kv['spanCount']); examined=int(kv['assignmentsExamined']); feasible=int(kv['parityFeasibleAssignments'])
        assert span>0 and examined>0 and feasible>0 and examined==(1<<span) and kv['regionSpanMultiplicities'] not in ('','[]')
      elif ordinal==391:
        assert int(kv['tamperRows'])==9
      elif ordinal==392:
        preferred=int(kv['preferredCount']); count=int(kv['entryCount'])
        assert preferred==4 and count>1 and int(kv['forwardOrdinal'])==1 and int(kv['reverseOrdinal'])==count-1
        assert int(kv['forwardDenominator'])==count and int(kv['reverseDenominator'])==count
      elif ordinal==394:
        assert int(kv['topologyBoundaryIncidences'])==int(kv['baselineIncidences'])
    except Exception as exc:
      errors.append(f'{phase} ordinal={ordinal} invariant={type(exc).__name__}:{exc}')
for ordinal in corrected:
  if raw_by.get('focused-a',{}).get(ordinal) != raw_by.get('focused-b',{}).get(ordinal):
    errors.append(f'ordinal={ordinal} focused_receipt_bytes_differ')
summary={
  'correctedOrdinals':corrected,
  'focusedReceiptBytesEqual':not any('focused_receipt_bytes_differ' in x for x in errors),
  'receiptErrors':errors,
  'parsed':parsed,
}
(r/'receipt-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n',encoding='utf-8')
with (r/'receipt-ledger.tsv').open('w',encoding='utf-8') as f:
  f.write('phase\tordinal\tsha256\treceipt\n')
  for phase in phases:
    for ordinal in corrected:
      raw=raw_by.get(phase,{}).get(ordinal)
      if raw is not None:
        f.write(f"{phase}\t{ordinal}\t{hashlib.sha256(raw).hexdigest()}\t{raw.decode('utf-8').rstrip()}\n")
(r/'receipt-errors.txt').write_text(('\n'.join(errors)+'\n') if errors else '',encoding='utf-8')
raise SystemExit(1 if errors else 0)
PY_RECEIPTS
receipt_rc=$?
set -e
if [[ "$receipt_rc" -ne 0 ]]; then record_failure SEMANTIC_RED "focused receipt gate failed rc=$receipt_rc"; fi

'''
src = src.replace(anchor, anchor + receipt)
Path(sys.argv[2]).write_text(src, encoding='utf-8')
PY
bash -n "$harness"
printf 'orchestrationRetry=2\nbaseHarnessRef=%s\nbaseHarnessBlob=%s\nadaptation=package119-plus-focused-receipt-gate\n' "$BASE_REF" "$BASE_BLOB" > "$RUNNER_TEMP/tb-r1-orchestration-retry.txt"
exec bash "$harness"
