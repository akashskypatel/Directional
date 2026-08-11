#!/usr/bin/env python3
from __future__ import annotations

import base64
import hashlib
import pathlib
import subprocess
import zlib

root = pathlib.Path(__file__).resolve().parents[3]
payload_dir = pathlib.Path(__file__).resolve().parent
encoded = "".join(
    (payload_dir / f"m1_closed_outcome.part{i:02d}").read_text().strip()
    for i in range(6)
)
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == (
    "099a29f851199a04ccacc63c780c7bea353ae2c6f013b3c00052b242fd440286"
)
subprocess.run(
    ["git", "apply", "--check", "-"], cwd=root, input=patch, check=True
)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of closed producer-outcome cutover")
