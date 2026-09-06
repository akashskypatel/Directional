#!/usr/bin/env python3
from pathlib import Path
import sys

src = Path(sys.argv[1])
out = Path(sys.argv[2])
text = src.read_text(encoding='utf-8')

replacements = [
    ("ARTIFACT_ID=9975737868", "ARTIFACT_ID=9980764888"),
    ("EXPECTED_ARTIFACT_NAME='m3-cp4c3-cb32-compile-result-33987769718'", "EXPECTED_ARTIFACT_NAME='m3-cp4c3-cb35-result-34005311571'"),
    ("EXPECTED_PROVIDER_DIGEST='sha256:16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec'", "EXPECTED_PROVIDER_DIGEST='sha256:ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0'"),
    ("EXPECTED_ZIP_SHA='16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec'", "EXPECTED_ZIP_SHA='ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0'"),
    ("EXPECTED_SOURCE_SHA='098ac7d93ea203222dd0ac50cdb68667744f0fd4'", "EXPECTED_SOURCE_SHA='ab86747bdfdb94c7c383bf5d2893ced4207eb555'\nEXPECTED_SOURCE_ARCHIVE_SHA='64801a38ccbe9de282dbec261cad6c2b6575403ed38e93b514c893c22f03684a'"),
    ("EXPECTED_407='9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae'", "EXPECTED_407='9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae'\nEXPECTED_408='2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6'"),
    ("(cd \"$PKG\" && sha256sum -c SHA256SUMS) | tee \"${RESULT}/sha256sums-check.txt\"", "[[ \"$(wc -l < \"$PKG/SHA256SUMS\")\" -eq 28 ]] || fail_orchestration 'root SHA256SUMS entry count mismatch'\n(cd \"$PKG\" && sha256sum -c SHA256SUMS) | tee \"${RESULT}/sha256sums-check.txt\""),
    ("[[ -f \"$source_archive\" ]] || fail_orchestration 'source archive absent'", "[[ -f \"$source_archive\" ]] || fail_orchestration 'source archive absent'\n[[ \"$(sha_file \"$source_archive\")\" == \"$EXPECTED_SOURCE_ARCHIVE_SHA\" ]] || fail_orchestration 'source archive digest mismatch'"),
    ("    407: '9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae',\n}", "    407: '9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae',\n    408: '2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6',\n}"),
    ("for n in [397, 401, 403, 405, 406, 407]:", "for n in [397, 401, 403, 405, 406, 407, 408]:"),
    ("[(397,401),(401,403),(403,405),(405,406),(406,407)]", "[(397,401),(401,403),(403,405),(405,406),(406,407),(407,408)]"),
    ("for n in [365,397,401,403,405,406,407]:", "for n in [365,397,401,403,405,406,407,408]:"),
    ("selector_prefix_chain=365<397<401<403<405<406<407", "selector_prefix_chain=365<397<401<403<405<406<407<408"),
    ("-eq 407 ]] || fail_orchestration 'identity map count mismatch'", "-eq 408 ]] || fail_orchestration 'identity map count mismatch'"),
    ("if len(rows) != 407:", "if len(rows) != 408:"),
    ("list(range(1, 408))", "list(range(1, 409))"),
    ("ledger ordinal sequence is not exactly 1..407", "ledger ordinal sequence is not exactly 1..408"),
    ("total=407", "total=408"),
    ("for n in 366 367 398 404 406 407; do", "for n in 366 367 368 369 370 374 390 398 404 406 407 408; do"),
    ("TB28_R3 ordinal=", "TB30 ordinal="),
    ("TB28_R3_COMPLETE: immutable artifact-only selector407 execution complete; semantic interpretation deferred to TB28-R3 review.", "TB30_EXEC_COMPLETE: immutable artifact-only selector408 execution complete; semantic interpretation deferred to TB30-REV."),
    ("CB33_PREFLIGHT_COMPLETE: package, executable routing, selection authority, and execution view verified; no Directional runtime executed.", "TB30_PREFLIGHT_COMPLETE: package, executable routing, selection authority, and execution view verified; no Directional runtime executed."),
]
for old, new in replacements:
    count = text.count(old)
    if count != 1:
        raise SystemExit(f'replacement anchor count {count}, expected 1: {old[:100]}')
    text = text.replace(old, new, 1)
for old, new, expected_count in [
    ('m3-cp4c3-tb28-r3', 'm3-cp4c3-tb30', 3),
    ('Architecture_M3_CP4c3_Required_Green_Selector_407.txt', 'Architecture_M3_CP4c3_Required_Green_Selector_408.txt', 2),
]:
    count = text.count(old)
    if count != expected_count:
        raise SystemExit(f'replacement anchor count {count}, expected {expected_count}: {old[:100]}')
    text = text.replace(old, new)
out.write_text(text, encoding='utf-8')
