#!/usr/bin/env python3
import csv
import pathlib
import re
import sys

result = pathlib.Path(sys.argv[1])
out = result / "tb37-measurement-checks.txt"
lines = []
overall = True

ledger = result / "ledger.tsv"
if ledger.exists():
    rows = list(csv.DictReader(ledger.open(), delimiter="\t"))
    by_ord = {int(r["ordinal"]): r for r in rows}
    red = [n for n, r in by_ord.items() if r["result"] == "RED"]
    expected_red = [366, 367, 368, 369, 370, 374, 398]
    protected = (312, 390, 393, 404, 406, 407, 408, 409)
    behavior_ok = (
        len(rows) == 409
        and red == expected_red
        and all(by_ord[n]["result"] == "PASS" for n in protected)
        and all(by_ord[n]["result"] == "PASS" for n in range(1, 366))
    )
    overall &= behavior_ok
    lines += [
        f"behavioral_identity_ok={str(behavior_ok).lower()}",
        f"red_ordinals={red}",
    ]
else:
    overall = False
    lines += ["behavioral_identity_ok=false", "ledger_missing=true"]

required = (
    "regionInteriorBarrierEdgeCount",
    "regionExcludedVertexCount",
    "regionExcludedMeshBoundaryVertexCount",
    "regionExcludedBoundaryVertexCount",
    "regionExcludedAllOwnedVertexCount",
    "regionSubmeshBoundaryEdgeCount",
    "regionSubmeshBoundaryVertexCount",
    "regionVTotal",
    "regionETotal",
    "regionChiFull",
    "faceCount",
)

def value(text, key):
    m = re.search(r"(?:^|[;\s])" + re.escape(key) + r"=([^;\s\"']+)", text)
    return m.group(1) if m else None

for ordinal in (366, 367):
    detail = result / "failure-details" / f"ordinal-{ordinal:03d}.txt"
    text = detail.read_text(errors="replace") if detail.exists() else ""
    vals = {k: value(text, k) for k in required}
    identity_ok = (
        value(text, "detailCode") == "RegionEulerCharacteristicNotOne"
        and value(text, "regionBoundaryProvenance") == "FaceWalkOrbit"
        and value(text, "regionBoundaryCensusDomain") == "NetworkGraph"
        and value(text, "regionBoundaryNodeOccurrenceCountDerived") == "true"
        and all(v is not None for v in vals.values())
    )
    if not identity_ok:
        overall = False
        lines.append(f"ordinal_{ordinal}_contract_ok=false")
        for k, v in vals.items():
            lines.append(f"ordinal_{ordinal}_{k}={v or 'MISSING'}")
        continue

    n = {k: int(v) for k, v in vals.items()}
    x = n["regionExcludedVertexCount"]
    b = n["regionInteriorBarrierEdgeCount"]
    split_ok = x == (
        n["regionExcludedMeshBoundaryVertexCount"]
        + n["regionExcludedBoundaryVertexCount"]
        + n["regionExcludedAllOwnedVertexCount"]
    )
    chi_ok = n["regionChiFull"] == n["regionVTotal"] - n["regionETotal"] + n["faceCount"]
    witness_ok = n["faceCount"] != 250 or n["regionChiFull"] == x + b - 47
    d = x + b
    classification = (
        "REGION_CONSTRUCTION" if d == 44
        else "CERTIFICATE_ARITHMETIC" if d == 48
        else "MEASUREMENT_DISAGREEMENT"
    )
    row_ok = split_ok and chi_ok and witness_ok
    overall &= row_ok
    lines += [
        f"ordinal_{ordinal}_contract_ok={str(row_ok).lower()}",
        f"ordinal_{ordinal}_X={x}",
        f"ordinal_{ordinal}_B_int={b}",
        f"ordinal_{ordinal}_X_split_ok={str(split_ok).lower()}",
        f"ordinal_{ordinal}_chi_full_ok={str(chi_ok).lower()}",
        f"ordinal_{ordinal}_tb36_rev_identity_ok={str(witness_ok).lower()}",
        f"ordinal_{ordinal}_D={d}",
        f"ordinal_{ordinal}_classification={classification}",
    ]

lines.insert(0, f"measurement_checks_ok={str(overall).lower()}")
out.write_text("\n".join(lines) + "\n")
print(out.read_text(), end="")
