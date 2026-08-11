#!/usr/bin/env python3
from __future__ import annotations
import base64
import hashlib
import pathlib
import subprocess
import zlib

PATCH_B64 = "eNqlVU1vGjEQvfMrnJwWwRo2SqEiJUo/hNpDo4jkVlUrx54Fq4u9sr1JaZP/Xtv7ndJCiw/s2ryZefNmxst4kqAwXHGDyEgrOsp4BikXMFrCBvT6ptximmXofh+ixwWD74hNp2NCpxiPi4Wi8Xhyft4Lw3B/lN5gMDgg0tUVCs+iyXQYnaGBf3mN7Nnb3Kyl4oYY/gA3a6JhoaQwn635EnSeGnSf85TFpI2LMweME4eMXaSgh9x6Lh48QUHClTZ3MpOpXG3xA0lzCProZI4oKMMTTokB7EELQgE9PRWmbmmgUrB9tgWqMg4r4xNT2i1hxaV4t3WIL9rxpjEl2rzRhs1mmv+A2FwGNYP+V2xziqtgR7hsiP3F5/+zbORovLnV1kZ5r0cE7OTwbxEHR6f4stJH+25n82fnTf/JXFFw8Pdyk0kBwuhDiffaAqG2ERcWXEQLLwtG9ulD1WGwvw6Cfv8IPi+S9XM/iV6Nh9EYDSbR+WQYRW7wiyuinHHlN26gN7EijzFVUus44WAnn2+yNOjmpcDkSiBKBOPMqcgZms/tcWpJSYELxnedIl20XTz36627LMoiWBdGWeLXYB6l+oaz+jra6VGXxdMYBHOi/Wz6U/m8sFMp12heZnvrt7PZtTQ3SrKcOrZLIGx78Zsp42QlpLYiayyk8ShrvwLr7dTR5GJ1epiZ/dEuvaZ/d4B1rhJXYkjThWupT8LOHWcFT1Bl6MaFWxWPkVcq9Pex5XREmJpqp96nJar7sQDFJeO0W5SuJL5NChYdWv48ITyNSz4xtYR0cNtiZ//NlW15BrsKNuwqsXvVdWra7bl6aYWqMvlo8xBys/3Q6IUa7WoXzRF+Mb9Wt1/jLK5m"
patch = zlib.decompress(base64.b64decode(PATCH_B64))
assert hashlib.sha256(patch).hexdigest() == "ac1820102d56e12a21cbf0821a7a96d4bc3afb72333a31e0f1c0b143b70d05ff"
root = pathlib.Path(__file__).resolve().parents[3]
subprocess.run(["git", "apply", "--check", "-"], cwd=root, input=patch, check=True)
subprocess.run(["git", "apply", "-"], cwd=root, input=patch, check=True)
print(f"applied {len(patch)} bytes of M1 pipeline compile fixes")
