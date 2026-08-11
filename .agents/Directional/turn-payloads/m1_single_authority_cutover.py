#!/usr/bin/env python3
from __future__ import annotations
import base64, hashlib, pathlib, subprocess, zlib
root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = "".join(p.read_text().strip() for p in sorted(payload_dir.glob("m1_fix2.part*")))
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == "8d26fa96ff74c8e6e34e731053b9ab34f0db9d657902c31b7124232ea4ca13e0"
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 pipeline compile fixes")
