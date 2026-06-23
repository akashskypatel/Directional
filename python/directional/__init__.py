"""Python interface for Directional cross-field extraction and remeshing."""

from __future__ import annotations

import os
import sys
from pathlib import Path
from typing import Any


# Keep the handles alive for the lifetime of the process. On Windows, releasing
# an add_dll_directory() handle removes that directory from the DLL search path.
_DLL_DIRECTORY_HANDLES: list[Any] = []


def _configure_windows_dll_search() -> None:
    if sys.platform != "win32" or not hasattr(os, "add_dll_directory"):
        return

    package_dir = Path(__file__).resolve().parent
    repo_root = package_dir.parents[1]
    cwd = Path.cwd()
    candidate_dirs = [
        package_dir,
        repo_root / "build" / "standalone" / "Release",
        repo_root / "vcpkg_installed" / "x64-windows" / "bin",
        repo_root / "external" / "vcpkg" / "packages" / "gmp_x64-windows" / "bin",
        repo_root / "external" / "vcpkg" / "installed" / "x64-windows" / "bin",
        cwd
        / "third_party"
        / "Directional"
        / "build"
        / "temp.win-amd64-cpython-313"
        / "Release"
        / "directional._directional"
        / "install"
        / "bin",
        cwd / "third_party" / "Directional" / "build" / "standalone" / "Release",
        cwd / "third_party" / "Directional" / "vcpkg_installed" / "x64-windows" / "bin",
        cwd
        / "third_party"
        / "Directional"
        / "external"
        / "vcpkg"
        / "packages"
        / "gmp_x64-windows"
        / "bin",
        cwd
        / "third_party"
        / "Directional"
        / "external"
        / "vcpkg"
        / "installed"
        / "x64-windows"
        / "bin",
    ]

    for temp_dir in (repo_root / "build").glob("temp.win-amd64-cpython-*"):
        candidate_dirs.append(
            temp_dir / "Release" / "directional._directional" / "install" / "bin"
        )

    seen: set[str] = set()
    for directory in candidate_dirs:
        if not directory.is_dir():
            continue

        resolved = str(directory.resolve())
        if resolved in seen:
            continue

        seen.add(resolved)
        _DLL_DIRECTORY_HANDLES.append(os.add_dll_directory(resolved))


_configure_windows_dll_search()

_NATIVE_IMPORT_ERROR: ImportError | None = None

try:
    from ._directional import (
        CrossFieldOptions,
        CrossFieldResult,
        RemeshOptions,
        RemeshResult,
        extract_cross_field,
        remesh_from_cross_field,
        remesh_from_mesh,
        remesh_from_raw_cross_field,
    )
except ImportError as exc:
    _NATIVE_IMPORT_ERROR = exc



def __getattr__(name: str) -> Any:
    if name in __all__ and _NATIVE_IMPORT_ERROR is not None:
        raise ImportError(
            "The directional native extension is not available. "
            "Build or install the package before using cross-field extraction "
            "or remeshing."
        ) from _NATIVE_IMPORT_ERROR
    raise AttributeError(f"module {__name__!r} has no attribute {name!r}")


__all__ = [
    "CrossFieldOptions",
    "CrossFieldResult",
    "RemeshOptions",
    "RemeshResult",
    "extract_cross_field",
    "remesh_from_cross_field",
    "remesh_from_mesh",
    "remesh_from_raw_cross_field",
]
