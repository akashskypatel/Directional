#!/usr/bin/env python3
from __future__ import annotations
import base64
import hashlib
import pathlib
import subprocess
import zlib

PATCH_B64 = "eNqtVdtq20AQffdXLHkoErrEIm3cynVwapw0NA9J7EChFLGRRslSSSt2VyFp6b93Vqv1JVFuUIMloZ05Z+bMRUEQELqrQCq5u2hETlOYQVEsBa0kU4xX5w1XDCq11CZhWtcDz/PI1dtcplMSfBqN/I/E07don0ynA0KIVFkcC7gFIcERwEUGArKwBsF4xtKvvOAVLxnI8AquWeW4vvba+j3rBVXmuO5YO+VcEIc2ipN3kF0DiTc89Qvpkj+DQCOynDj6zQrwAgqq8yIHEzJcmRHSbzRBYPM4402lSEAi/Pfajgfes4ThDZXJLS0awCyQ1zO8Ka+kMtpJ9hsSRXiRnVQZ3CF5L1BwwPSx444txuFiMb9YJqdLx/r6iIjGaZJSqT5voB84Wwm5a5DHgQgoaV2DjcYakrbWr0HXcrl4sVE94GoLaEkw24wJSLUzLeIYD2+4YOo+js8eCHCCfLngZWJ0eDYuVqn99yawjWSw9d6cjPtI7+XF5XyFuz59upOMZdg1wdi0/9+BvWypIptCoVNJFSLRAiNycnanGgH+utkRQ09jNBx+8EfEi4bRHo6lGUeDhvkTGwuWsMs4Z0KqRAea8Dz5hTo6ipa1hvRJtwaOBK/UF8w8o+L+G5qsCzFrlIm+E+J47lgOH4dqrGfK4pl5/PGkxtbR/dmnWRC1sv4XMFuf1qNqioLXavwm3W0YJvn597P5bJkcHZ4udBtox1A2aQpSbhnMz52dkwqLzrINAQ9tf+/4HWuYU1Ygj9avf5HLM9whEA1fXN+PDds2GY322jbRd9smGxvraqPYZDJZb+etwbwGXoISOJevaxRcdR2M59mizJGuHaqxXb9rrXrHx7RVz/i9vGpXbi9QrNYqcl3a4Vx5HXdUvK45fhhBZ2CC2rYz3dCaCt4oCKGs1b39bulB/wdOrXnW"
patch = zlib.decompress(base64.b64decode(PATCH_B64))
assert hashlib.sha256(patch).hexdigest() == "d11eed671effc0641bae8c0b1337107d2effbb57088e5dc7dc07a33b56755da9"
root = pathlib.Path(__file__).resolve().parents[3]
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of typed periodic-relation test fixes")
