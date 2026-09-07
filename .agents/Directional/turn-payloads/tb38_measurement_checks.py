#!/usr/bin/env python3
import csv
import pathlib
import re
import sys

result = pathlib.Path(sys.argv[1])
out_summary = result / "tb38-measurement-checks.txt"
out_table = result / "accepted-region-euler-certificates.tsv"
lines = []

ledger = result / "ledger.tsv"
if not ledger.exists():
    out_summary.write_text("tb38_exec_checks_ok=false\nledger_missing=true\n")
    raise SystemExit(0)
rows = list(csv.DictReader(ledger.open(), delimiter="\t"))
by_ord = {int(row["ordinal"]): row for row in rows}
red = [n for n in sorted(by_ord) if by_ord[n]["result"] == "RED"]
accepted_ok = len(rows) == 409 and all(by_ord[n]["result"] == "PASS" for n in range(1, 366))
protected = (312, 390, 393, 404, 406, 407, 408, 409)
protected_ok = len(rows) == 409 and all(by_ord.get(n, {}).get("result") == "PASS" for n in protected)
selection_ok = len(rows) == 409 and all(row.get("selected") == "1" for row in rows)

field_names = (
    "X", "E_one", "B_int", "fullMinusReduced", "V_int", "E_int",
    "V_total", "E_total", "F", "chiReduced", "chiFull",
)
pattern = re.compile(r"(?:^|[;\s])([^=;\s]+)=([^;\s\"']+)")
cert_rows = []
arithmetic_ok = True
accepted_cert_count = 0
accepted_nonzero_count = 0
for ordinal in range(1, 410):
    raw = result / "raw" / f"ordinal-{ordinal:03d}.log"
    if not raw.exists():
        continue
    identity = by_ord.get(ordinal, {}).get("identity", "")
    verdict = by_ord.get(ordinal, {}).get("result", "MISSING")
    for line in raw.read_text(errors="replace").splitlines():
        if "M3_CP4AB_FRAGMENT_DIAG record=euler_certificate" not in line:
            continue
        values = dict(pattern.findall(line))
        missing = [name for name in ("region", *field_names) if name not in values]
        if missing:
            checks = (False, False, False, False)
            classification = "MISSING_FIELDS:" + ",".join(missing)
        else:
            n = {name: int(values[name]) for name in field_names}
            checks = (
                n["chiReduced"] == n["V_int"] - n["E_int"] + n["F"],
                n["chiFull"] == n["V_total"] - n["E_total"] + n["F"],
                n["fullMinusReduced"] == n["chiFull"] - n["chiReduced"],
                n["fullMinusReduced"] == n["X"] - n["E_one"] - n["B_int"],
            )
            if not all(checks):
                classification = "ARITHMETIC_MISMATCH"
            elif n["fullMinusReduced"] == 0:
                classification = "REDUCED_FULL_EQUIVALENT"
            elif ordinal <= 365 and verdict == "PASS":
                classification = "NONZERO_DIFFERENCE_UNCHANGED_ACCEPTED_VERDICT"
            else:
                classification = "NONZERO_DIFFERENCE"
        if ordinal <= 365:
            accepted_cert_count += 1
            arithmetic_ok &= all(checks)
            if not missing and int(values["fullMinusReduced"]) != 0:
                accepted_nonzero_count += 1
        cert_rows.append((ordinal, identity, verdict, values, checks, classification, raw.name))

header = ["ordinal", "identity", "verdict", "region", *field_names,
          "chiReduced_ok", "chiFull_ok", "difference_ok", "authority_difference_ok",
          "classification", "raw_log"]
with out_table.open("w", newline="") as stream:
    writer = csv.writer(stream, delimiter="\t", lineterminator="\n")
    writer.writerow(header)
    for ordinal, identity, verdict, values, checks, classification, raw_name in cert_rows:
        writer.writerow([
            ordinal, identity, verdict, values.get("region", "MISSING"),
            *(values.get(name, "MISSING") for name in field_names),
            *(str(check).lower() for check in checks), classification,
            f"raw/{raw_name}",
        ])

def detail_code(ordinal):
    if by_ord.get(ordinal, {}).get("result") == "PASS":
        return "PASS"
    detail = result / "failure-details" / f"ordinal-{ordinal:03d}.txt"
    text = detail.read_text(errors="replace") if detail.exists() else ""
    match = re.search(r"(?:^|[;\s])detailCode=([^;\s\"']+)", text)
    return match.group(1) if match else "UNPARSED_RED"

def certs_for(ordinal):
    return [entry for entry in cert_rows if entry[0] == ordinal]

def exact_tb37_row(entry):
    values = entry[3]
    expected = {
        "X": "36", "E_one": "20", "B_int": "12", "V_total": "136",
        "E_total": "385", "F": "250", "chiReduced": "-3",
        "chiFull": "1", "fullMinusReduced": "4",
    }
    return all(values.get(key) == value for key, value in expected.items())

retired = ("TraceArcDoesNotSeparateItsSides", "UncutFaceComponentOrbitSeedNotUnique")
retired_counts = {name: 0 for name in retired}
for raw in sorted((result / "raw").glob("ordinal-*.log")):
    text = raw.read_text(errors="replace")
    for name in retired:
        retired_counts[name] += text.count(name)

tb38_ok = accepted_ok and protected_ok and selection_ok and arithmetic_ok
lines += [
    f"tb38_exec_checks_ok={str(tb38_ok).lower()}",
    f"ledger_rows={len(rows)}",
    f"accepted_prefix_ok={str(accepted_ok).lower()}",
    f"protected_identities_ok={str(protected_ok).lower()}",
    f"selection_integrity_ok={str(selection_ok).lower()}",
    f"red_ordinals={red}",
    f"accepted_euler_certificate_rows={accepted_cert_count}",
    f"accepted_nonzero_full_minus_reduced_rows={accepted_nonzero_count}",
    f"accepted_euler_arithmetic_ok={str(arithmetic_ok).lower()}",
]
for name in retired:
    lines.append(f"retired_{name}_occurrences={retired_counts[name]}")
for ordinal in (366, 367):
    current = certs_for(ordinal)
    lines += [
        f"ordinal_{ordinal}_result={by_ord.get(ordinal, {}).get('result', 'MISSING')}",
        f"ordinal_{ordinal}_detailCode={detail_code(ordinal)}",
        f"ordinal_{ordinal}_euler_certificate_rows={len(current)}",
        f"ordinal_{ordinal}_tb37_exact_row_present={str(any(exact_tb37_row(row) for row in current)).lower()}",
    ]
    for index, entry in enumerate(current, 1):
        values = entry[3]
        lines.append(
            f"ordinal_{ordinal}_row_{index}=" + ",".join(
                f"{name}={values.get(name, 'MISSING')}" for name in ("region", *field_names)
            )
        )
for ordinal in (368, 369, 370, 374, 398):
    lines.append(f"ordinal_{ordinal}_result={by_ord.get(ordinal, {}).get('result', 'MISSING')}")
    lines.append(f"ordinal_{ordinal}_detailCode={detail_code(ordinal)}")
for ordinal in protected:
    lines.append(f"protected_ordinal_{ordinal}={by_ord.get(ordinal, {}).get('result', 'MISSING')}")

out_summary.write_text("\n".join(lines) + "\n")
print(out_summary.read_text(), end="")
