#!/usr/bin/env python3
from __future__ import annotations
import base64, hashlib, pathlib, subprocess, zlib
root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = "".join(p.read_text().strip() for p in sorted(payload_dir.glob("m1_fix6.part*")))
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == "6cf05cd1a4c5b8a8b6b0f40d0425af09536f03b7cf683302d1be0d36d0ff029c"
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 compile remediation")
