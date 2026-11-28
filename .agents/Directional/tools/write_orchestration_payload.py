#!/usr/bin/env python3
"""Write an orchestration draft only after validating SHA-256 literals.

Templates use @@SHA256:<name>@@ placeholders. Every replacement is supplied as
--sha256 <name>=<64-lowercase-hex>. Invalid values are rejected before the
output file is created or replaced.
"""

from __future__ import annotations

import argparse
import os
from pathlib import Path
import re
import tempfile

SHA256 = re.compile(r"[0-9a-f]{64}\Z")
PLACEHOLDER = re.compile(r"@@SHA256:([A-Za-z0-9_.-]+)@@")


def parse_sha256(value: str) -> tuple[str, str]:
    name, separator, digest = value.partition("=")
    if not separator or not name or SHA256.fullmatch(digest) is None:
        raise argparse.ArgumentTypeError(
            "expected NAME=<exactly 64 lowercase hexadecimal SHA-256 characters>"
        )
    return name, digest


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--template", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--sha256", action="append", default=[], type=parse_sha256)
    args = parser.parse_args()

    replacements = dict(args.sha256)
    if len(replacements) != len(args.sha256):
        parser.error("duplicate --sha256 name")

    content = args.template.read_text(encoding="utf-8")
    required = set(PLACEHOLDER.findall(content))
    missing = sorted(required - replacements.keys())
    unused = sorted(replacements.keys() - required)
    if missing:
        parser.error("missing SHA-256 values for: " + ", ".join(missing))
    if unused:
        parser.error("unused SHA-256 values: " + ", ".join(unused))

    rendered = PLACEHOLDER.sub(lambda match: replacements[match.group(1)], content)
    if PLACEHOLDER.search(rendered):
        parser.error("unresolved SHA-256 placeholder remains")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(
        mode="w", encoding="utf-8", dir=args.output.parent, delete=False
    ) as handle:
        handle.write(rendered)
        temporary = Path(handle.name)
    os.replace(temporary, args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
