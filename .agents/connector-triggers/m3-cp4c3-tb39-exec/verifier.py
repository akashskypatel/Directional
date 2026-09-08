#!/usr/bin/env python3
import csv, hashlib, json, os, pathlib, re, sys

result = pathlib.Path(sys.argv[1])
harness_exit = sys.argv[2] or "unavailable"
ledger_path = result / "ledger.tsv"
rows = list(csv.DictReader(ledger_path.open(), delimiter="\t")) if ledger_path.exists() else []
by_ordinal = {int(r["ordinal"]): r for r in rows if r.get("ordinal", "").isdigit()}
required = ["region","X","E_one","B_int","B_int_one_side","B_int_both_sides","fullMinusReduced","V_int","E_int","V_total","E_total","F","chiReduced","chiFull","trace_cut_faces","split_fragments","fragment_corner_attributions"]
checks = ["reduced_eq","full_eq","difference_eq","boundary_eq","bint_eq"]
marker = "M3_CP4AB_FRAGMENT_DIAG record=euler_certificate"
tokens_re = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)=([^\s]+)")
cert_rows, missing_rows = [], []
for ordinal in sorted(by_ordinal):
    ledger = by_ordinal[ordinal]
    raw_rel = ledger.get("raw_log", "")
    raw = result / raw_rel
    if not raw.exists():
        continue
    for line_no, line in enumerate(raw.read_text(errors="replace").splitlines(), 1):
        if marker not in line:
            continue
        tokens = dict(tokens_re.findall(line))
        missing = [f for f in required if f not in tokens]
        if missing:
            missing_rows.append({"ordinal":ordinal,"identity":ledger["identity"],"line":line_no,"missing":missing,"raw":line})
            continue
        v = {f:int(tokens[f]) for f in required}
        c = {
            "reduced_eq": v["chiReduced"] == v["V_int"] - v["E_int"] + v["F"],
            "full_eq": v["chiFull"] == v["V_total"] - v["E_total"] + v["F"],
            "difference_eq": v["fullMinusReduced"] == v["chiFull"] - v["chiReduced"],
            "boundary_eq": v["fullMinusReduced"] == v["X"] - v["E_one"] - v["B_int"],
            "bint_eq": v["B_int"] == v["B_int_both_sides"],
        }
        cert_rows.append({"ordinal":ordinal,"identity":ledger["identity"],"result":ledger["result"],"raw_log":raw_rel,"raw_line":line_no,**v,**c})

cert_cols = ["ordinal","identity","result","raw_log","raw_line",*required,*checks]
def write_tsv(path, fieldnames, data):
    with path.open("w", newline="") as out:
        w = csv.DictWriter(out, fieldnames=fieldnames, delimiter="\t")
        w.writeheader(); w.writerows(data)

cert_path = result / "euler-certificate-rows.tsv"
write_tsv(cert_path, cert_cols, cert_rows)
(result / "euler-certificate-missing-fields.json").write_text(json.dumps(missing_rows, indent=2, sort_keys=True) + "\n")

digest_rows = {}
digest_path = result / "failure-detail-digests.tsv"
if digest_path.exists():
    digest_rows = {int(r["ordinal"]):r for r in csv.DictReader(digest_path.open(), delimiter="\t") if r.get("ordinal","").isdigit()}
direct_ordinals = [312,356,357,362,366,367,368,369,370,374,385,390,393,398,404,406,407,408,409]
direct = []
for o in direct_ordinals:
    r = by_ordinal.get(o)
    if not r: continue
    d = digest_rows.get(o,{})
    direct.append({"ordinal":o,"identity":r["identity"],"result":r["result"],"exit":r["exit"],"selected":r["selected"],"detail_sha256":d.get("detail_sha256",""),"detail_file":d.get("detail_file","")})
direct_path = result / "direct-identity-status.tsv"
write_tsv(direct_path,["ordinal","identity","result","exit","selected","detail_sha256","detail_file"],direct)

decisive = [r for r in cert_rows if r["ordinal"] in {356,357,362,366,367}]
decisive_path = result / "decisive-euler-rows.tsv"
write_tsv(decisive_path, cert_cols, decisive)

accepted_red = [o for o in range(1,366) if by_ordinal.get(o,{}).get("result") != "PASS"]
red = [o for o,r in sorted(by_ordinal.items()) if r.get("result") == "RED"]
selected_bad = [o for o,r in sorted(by_ordinal.items()) if r.get("selected") != "1"]
all_arithmetic = bool(cert_rows) and not missing_rows and all(all(r[c] for c in checks) for r in cert_rows)
retired = {code:0 for code in ["TraceArcDoesNotSeparateItsSides","UncutFaceComponentOrbitSeedNotUnique"]}
for ledger in by_ordinal.values():
    raw = result / ledger.get("raw_log","")
    if raw.exists():
        text = raw.read_text(errors="replace")
        for code in retired: retired[code] += text.count(code)

ownership = None
owner_rel = by_ordinal.get(385,{}).get("raw_log","")
owner_raw = result / owner_rel if owner_rel else None
if owner_raw and owner_raw.exists():
    m = re.search(r"m3Cp4c3CertifiedOwnerPublication;sourceFaceCount=(\d+);established=(\d+);unavailable=(\d+);conflicting=(\d+);conflictCensusPublished=(true|false);conflictRowCount=(\d+)", owner_raw.read_text(errors="replace"))
    if m:
        ownership = {"sourceFaceCount":int(m[1]),"established":int(m[2]),"unavailable":int(m[3]),"conflicting":int(m[4]),"conflictCensusPublished":m[5]=="true","conflictRowCount":int(m[6])}

torus = [r for r in cert_rows if r["ordinal"] in {356,357,362}]
mechanical = [r for r in cert_rows if r["ordinal"] in {366,367}]
accepted_cert = [r for r in cert_rows if r["ordinal"] <= 365]
semantic_checks = {
    "ledger_complete": len(rows)==409 and sorted(by_ordinal)==list(range(1,410)),
    "accepted_365_of_365": not accepted_red,
    "ordinal_312_pass": by_ordinal.get(312,{}).get("result")=="PASS",
    "ordinal_409_pass": by_ordinal.get(409,{}).get("result")=="PASS",
    "protected_390_393_406_407_pass": all(by_ordinal.get(o,{}).get("result")=="PASS" for o in [390,393,406,407]),
    "preserved_404_408_pass": all(by_ordinal.get(o,{}).get("result")=="PASS" for o in [404,408]),
    "selection_integrity": not selected_bad,
    "euler_certificate_nonempty": bool(cert_rows),
    "euler_certificate_required_fields_complete": not missing_rows,
    "euler_certificate_arithmetic_all_rows": all_arithmetic,
    "retired_codes_absent": all(v==0 for v in retired.values()),
}
summary = {
    "turn":os.environ.get("TURN_ID"),"run_id":os.environ.get("GITHUB_RUN_ID"),"event_sha":os.environ.get("GITHUB_SHA"),"harness_exit":harness_exit,
    "source_sha":os.environ.get("EXPECTED_SOURCE_SHA"),"artifact_id":int(os.environ.get("EXPECTED_ARTIFACT_ID","0")),"source_archive_sha256":os.environ.get("EXPECTED_SOURCE_ARCHIVE_SHA256"),
    "selector409_sha256":os.environ.get("EXPECTED_SELECTOR_SHA256"),"selector408_sha256":os.environ.get("EXPECTED_SELECTOR408_SHA256"),"harness_sha256":os.environ.get("EXPECTED_HARNESS_SHA256"),"test_source_sha256":os.environ.get("EXPECTED_TEST_SOURCE_SHA256"),
    "total":len(rows),"pass":len(rows)-len(red),"red":len(red),"red_ordinals":red,"accepted_prefix_pass":365-len(accepted_red),"accepted_prefix_total":365,"accepted_prefix_red_ordinals":accepted_red,"selection_mismatch_ordinals":selected_bad,
    "euler_certificate_row_count":len(cert_rows),"euler_certificate_missing_field_row_count":len(missing_rows),"euler_certificate_arithmetic_all_rows":all_arithmetic,"retired_code_occurrences":retired,"ownership_ordinal_385":ownership,
    "torus_row_count":len(torus),"mechanical_row_count":len(mechanical),"torus_split_fragments_equals_F_all_rows":bool(torus) and all(r["split_fragments"]==r["F"] for r in torus),"accepted_fullMinusReduced_all_zero":bool(accepted_cert) and all(r["fullMinusReduced"]==0 for r in accepted_cert),
    "semantic_gate_checks":semantic_checks,"semantic_gate_pass":all(semantic_checks.values()),"no_build":True,"no_benchmark":True,"stable_repricing_permitted":False,"definition_decision_permitted":False,"next_boundary":"M3-CP4c-3-TB39-REV",
}
verification = result / "tb39-verification.json"
verification.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
(result / "tb39-verification.txt").write_text("".join(f"{k}={summary[k]}\n" for k in ["total","pass","red","red_ordinals","accepted_prefix_pass","accepted_prefix_total","accepted_prefix_red_ordinals","selection_mismatch_ordinals","euler_certificate_row_count","euler_certificate_missing_field_row_count","euler_certificate_arithmetic_all_rows","retired_code_occurrences","ownership_ordinal_385","torus_row_count","mechanical_row_count","torus_split_fragments_equals_F_all_rows","accepted_fullMinusReduced_all_zero","semantic_gate_pass","no_build","no_benchmark","next_boundary"]))
for p in [cert_path,direct_path,decisive_path,verification]:
    (result / f"{p.name}.sha256").write_text(hashlib.sha256(p.read_bytes()).hexdigest()+f"  {p.name}\n")
print(json.dumps(summary, indent=2, sort_keys=True))
