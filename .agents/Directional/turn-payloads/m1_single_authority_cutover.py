#!/usr/bin/env python3
from __future__ import annotations
import base64
import hashlib
import pathlib
import subprocess
import zlib

PATCH_B64 = "eNqtUT1PwzAQ3f0rji1R4rRFaSnpUgmpEhOofKyRE1+CpcSJzk4FQvx37LRQtSwduOW+3zs/S1VVwHmtLIiJoXJSY9eipY/J00CVKPEOm+aZRKl0nZR9D8UlU0xpie9wfbtcpjOZJDNRFOl8AbPpdJGmjHN+GRuLouhCxvUa+NzxxTcQjX4JrnQYfnwTBjfUabtFMzQWikE1Mh+0qjpq896388r3c1fI/YoJGPzYFzsPVAXBVUcK3YbQMt+JRklh8QSqdCcGjMOJ7ZCscvAxjCzOkWgxBmNllrVKB8Zi/+Jz7F/DGLreqk67OY8WhvDJon8CJKxdEJ/j/fL8VgzaU4mEagbCgEYtk0Ma/xV7s+9sUZhOZ9m9HmXyP/cwSif8JfuXJUqGqyMloR1Iw55hdZT/GyVT3EE="
patch = zlib.decompress(base64.b64decode(PATCH_B64))
assert hashlib.sha256(patch).hexdigest() == "e3c92511719820b3a9b8b8ed759c465f462fa6345b0a9fddddf0b55c0a5612be"
root = pathlib.Path(__file__).resolve().parents[3]
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 region-validation compile fix")
