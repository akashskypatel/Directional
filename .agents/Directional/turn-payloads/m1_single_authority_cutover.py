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
    for i in range(2)
)
patch = zlib.decompress(base64.b64decode(encoded))
assert hashlib.sha256(patch).hexdigest() == (
    "b09149ff38f986722d610c7aa6e7134ea90df74e7d799978d917e96748ebf869"
)
subprocess.run(
    ["git", "apply", "--check", "-"], cwd=root, input=patch, check=True
)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of typed CellId owner cutover")
