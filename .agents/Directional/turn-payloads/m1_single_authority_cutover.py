#!/usr/bin/env python3
from __future__ import annotations
import base64, hashlib, pathlib, subprocess, zlib
root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = "".join(p.read_text().strip() for p in sorted(payload_dir.glob("m1_fix3.part*")))
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == "2b151c6a72f1e994660809b787ace31f3e1bc88c8e8e1e1ebcb6d9617b420624"
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 source-support authority cutover")
