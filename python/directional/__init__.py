from __future__ import annotations

import os
import sys
from pathlib import Path


def _configure_windows_dll_search() -> None:
    if sys.platform != "win32" or not hasattr(os, "add_dll_directory"):
        return

    package_dir = Path(__file__).resolve().parent
    repo_root = package_dir.parents[1]
    candidate_dirs = [
        package_dir,
        repo_root / "build" / "temp.win-amd64-cpython-313" / "Release" / "directional._directional" / "install" / "bin",
        repo_root / "build" / "standalone" / "Release",
        repo_root / "external" / "vcpkg" / "packages" / "gmp_x64-windows" / "bin",
        repo_root / "external" / "vcpkg" / "installed" / "x64-windows" / "bin",
    ]

    seen: set[str] = set()
    for directory in candidate_dirs:
        resolved = str(directory.resolve())
        if resolved in seen or not directory.exists():
            continue
        seen.add(resolved)
        os.add_dll_directory(resolved)


_configure_windows_dll_search()

from ._directional import RemeshOptions, RemeshResult, remesh_from_cross_field, remesh_from_raw_cross_field

__all__ = [
    "RemeshOptions",
    "RemeshResult",
    "remesh_from_cross_field",
    "remesh_from_raw_cross_field",
]
