#!/usr/bin/env python3
from __future__ import annotations

import base64
import hashlib
import pathlib
import subprocess
import zlib

root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = (payload_dir / "m1_closed_outcome.part00").read_text().strip()
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == (
    "800afc13e36075fdfdcfdff9b5e9723c4f898ba800a0c1dbab87daa36dd4f903"
)
subprocess.run(
    ["git", "apply", "--check", "-"], cwd=root, input=patch, check=True
)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of CellId compile fix")
