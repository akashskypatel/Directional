#!/usr/bin/env python3
from __future__ import annotations
import base64, hashlib, pathlib, subprocess, zlib
root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = "".join(p.read_text().strip() for p in sorted(payload_dir.glob("m1_chart_cutover.part*")))
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == "205cd85d8c8303d7129602e8c1c1feb2cea7c8bca0e58165fa9b365f8053f0a7"
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 chart authority cutover")
