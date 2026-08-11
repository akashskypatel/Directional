#!/usr/bin/env python3
from __future__ import annotations
import base64
import hashlib
import pathlib
import subprocess
import zlib

root = pathlib.Path(__file__).resolve().parents[3]
chunk_dir = pathlib.Path(__file__).resolve().parent / "m1-scope-chunks"
encoded = "".join(path.read_text().strip() for path in sorted(chunk_dir.glob("*.txt")))
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == "05a75540835544a0965c2f981b7a99b91d3a5efc8efd5eef71fdf591483534a6"
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 region-only phase-front scope and typed-test cutover")
