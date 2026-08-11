#!/usr/bin/env python3
from __future__ import annotations
import base64, hashlib, pathlib, subprocess, zlib
root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = "".join(p.read_text().strip() for p in sorted(payload_dir.glob("m1_fix4.part*")))
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == "80ec71fa14d4dc509705a9c59f2c82f1663f7a963d36e301bd78ee910ec296db"
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 semantic owner cutover")
