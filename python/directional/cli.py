from __future__ import annotations

import sys
from collections.abc import Sequence


def _load_native_cli():
    try:
        from . import _directional
    except ImportError as exc:
        raise RuntimeError(
            "The directional native extension could not be imported. "
            "Build or install the package before running this command."
        ) from exc

    if not hasattr(_directional, "run_cli"):
        raise RuntimeError(
            "The directional native extension does not expose the shared CLI backend."
        )
    return _directional.run_cli


def main(argv: Sequence[str] | None = None) -> int:
    """Forward command-line arguments to the shared native C++ CLI backend."""
    arguments = list(sys.argv[1:] if argv is None else argv)
    try:
        return int(_load_native_cli()(arguments))
    except Exception as exc:
        print(f"directional: error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
