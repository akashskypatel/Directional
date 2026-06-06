from __future__ import annotations

import os
import shutil
import subprocess
import sys
from pathlib import Path

from setuptools import Command, Extension, setup, find_packages
from setuptools.command.build_ext import build_ext


ROOT = Path(__file__).resolve().parent
WINDOWS_VS_CMAKE_CANDIDATES = (
    Path(r"C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"),
)
WINDOWS_VS_NINJA_CANDIDATES = (
    Path(r"C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe"),
)
WINDOWS_VCPKG_TRIPLETS = ("x64-windows", "xw")


def _first_existing_path(candidates: tuple[Path, ...]) -> Path | None:
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return None


def _windows_cmake_executable() -> Path | None:
    override = os.environ.get("DIRECTIONAL_CMAKE_EXECUTABLE") or os.environ.get("CMAKE_COMMAND")
    if override:
        candidate = Path(override)
        if candidate.exists():
            return candidate
    return _first_existing_path(WINDOWS_VS_CMAKE_CANDIDATES)


def _windows_ninja_executable() -> Path | None:
    override = os.environ.get("CMAKE_MAKE_PROGRAM")
    if override:
        candidate = Path(override)
        if candidate.exists():
            return candidate
    return _first_existing_path(WINDOWS_VS_NINJA_CANDIDATES)


def _cmake_executable() -> str:
    if sys.platform == "win32":
        candidate = _windows_cmake_executable()
        if candidate is not None:
            return str(candidate)
    return "cmake"


def _find_vcpkg_tool_dir(tool_name: str) -> Path | None:
    for candidate in ROOT.glob(f"build/**/downloads/tools/*/{tool_name}"):
        return candidate.parent
    return None


def _is_conflicting_cmake_path(entry: str, cmake_parent: str) -> bool:
    entry_lower = entry.lower()
    if entry_lower == cmake_parent:
        return False
    if "site-packages\\cmake\\data\\bin" in entry_lower:
        return True
    return ".venv" in entry_lower and entry_lower.endswith("\\scripts") and (Path(entry) / "cmake.exe").exists()


def _runtime_dll_dirs(build_temp: Path, install_dir: Path, installed_pkg_dir: Path) -> list[Path]:
    runtime_dirs = [installed_pkg_dir, install_dir / "bin"]
    for triplet in WINDOWS_VCPKG_TRIPLETS:
        runtime_dirs.extend(
            [
                build_temp / "_deps" / "vcpkg-src" / "installed" / triplet / "bin",
                build_temp / "_deps" / "vcpkg-src" / "installed" / triplet / "debug" / "bin",
                ROOT / "vcpkg_installed" / triplet / "bin",
                ROOT / "vcpkg_installed" / triplet / "debug" / "bin",
            ]
        )
    runtime_dirs.extend(
        [
            ROOT / "external" / "vcpkg" / "packages" / "gmp_x64-windows" / "bin",
            ROOT / "external" / "vcpkg" / "installed" / "x64-windows" / "bin",
        ]
    )
    return runtime_dirs


def _build_env(env: dict[str, str] | None = None) -> dict[str, str]:
    merged = os.environ.copy()
    if env:
        merged.update(env)
    if sys.platform == "win32":
        cmake_exe = _cmake_executable()
        cmake_parent = str(Path(cmake_exe).resolve().parent).lower() if Path(cmake_exe).exists() else ""
        path_entries = [
            entry
            for entry in merged.get("PATH", "").split(os.pathsep)
            if entry
            and not (
                "pip-build-env" in entry.lower()
                and entry.lower().endswith("\\overlay\\scripts")
            )
            and not _is_conflicting_cmake_path(entry, cmake_parent)
        ]
        prepend: list[str] = []
        windows_cmake = _windows_cmake_executable()
        if windows_cmake is not None:
            prepend.append(str(windows_cmake.parent))
        ninja_exe = _windows_ninja_executable()
        if ninja_exe is not None:
            prepend.append(str(ninja_exe.parent))
        seven_zip_dir = _find_vcpkg_tool_dir("7z.exe")
        if seven_zip_dir is not None:
            prepend.append(str(seven_zip_dir))
        merged["PATH"] = os.pathsep.join([*prepend, *path_entries])
        merged["CMAKE_COMMAND"] = cmake_exe
        if ninja_exe is not None:
            merged.setdefault("CMAKE_MAKE_PROGRAM", str(ninja_exe))
        if seven_zip_dir is not None:
            merged.setdefault("VCPKG_FORCE_SYSTEM_BINARIES", "1")
    return merged


def _run(cmd: list[str], cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    resolved_cmd = list(cmd)
    if resolved_cmd and resolved_cmd[0] == "cmake":
        resolved_cmd[0] = _cmake_executable()
    subprocess.run(resolved_cmd, cwd=str(cwd or ROOT), env=_build_env(env), check=True)


def _cmake_args(prefix: Path, extra: list[str] | None = None) -> list[str]:
    args = [
        f"-DCMAKE_INSTALL_PREFIX={prefix}",
        f"-DPython_EXECUTABLE={sys.executable}",
    ]
    if extra:
        args.extend(extra)
    return args


def _build_dir(name: str) -> Path:
    return ROOT / "build" / name


def _safe_build_name(value: str) -> str:
    return "".join(ch if ch.isalnum() or ch in ("-", "_") else "-" for ch in value)


def _as_cmake_bool(value: bool) -> str:
    return "ON" if value else "OFF"


def _env_bool(name: str, default: bool) -> bool:
    raw = os.environ.get(name)
    if raw is None:
        return default
    value = raw.strip().lower()
    if value in {"1", "on", "true", "yes"}:
        return True
    if value in {"0", "off", "false", "no"}:
        return False
    raise RuntimeError(f"Invalid boolean value for {name}: {raw!r}")


def _configure_and_build(build_dir: Path, configure_args: list[str], build_target: str | None = None) -> Path:
    build_dir.mkdir(parents=True, exist_ok=True)
    _run(["cmake", "-S", str(ROOT), "-B", str(build_dir), *configure_args])
    build_cmd = ["cmake", "--build", str(build_dir), "--config", "Release"]
    if build_target:
        build_cmd.extend(["--target", build_target])
    _run(build_cmd)
    return build_dir


def _copy_runtime_dlls(target_dir: Path, directories: list[Path]) -> None:
    seen_names: set[str] = set()
    for directory in directories:
        if not directory.exists():
            continue
        for dll_path in directory.glob("*.dll"):
            dll_name = dll_path.name.lower()
            if dll_name in seen_names:
                continue
            seen_names.add(dll_name)
            shutil.copy2(dll_path, target_dir / dll_path.name)


def _copy_runtime_dlls_to_targets(target_dirs: list[Path], source_dirs: list[Path]) -> None:
    for target_dir in target_dirs:
        target_dir.mkdir(parents=True, exist_ok=True)
        _copy_runtime_dlls(target_dir, source_dirs)


def _tutorial_runtime_dll_dirs(build_dir: Path) -> list[Path]:
    runtime_dirs: list[Path] = [build_dir / "Release", build_dir / "Debug", build_dir / "RelWithDebInfo", build_dir / "MinSizeRel"]
    for triplet in WINDOWS_VCPKG_TRIPLETS:
        runtime_dirs.extend(
            [
                build_dir / "_deps" / "vcpkg-src" / "installed" / triplet / "bin",
                build_dir / "_deps" / "vcpkg-src" / "installed" / triplet / "debug" / "bin",
                ROOT / "vcpkg_installed" / triplet / "bin",
                ROOT / "vcpkg_installed" / triplet / "debug" / "bin",
            ]
        )
    runtime_dirs.extend(
        [
            ROOT / "external" / "vcpkg" / "packages" / "gmp_x64-windows" / "bin",
            ROOT / "external" / "vcpkg" / "installed" / "x64-windows" / "bin",
        ]
    )
    return runtime_dirs


class CMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = ".") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = str(Path(sourcedir).resolve())


class BuildStandalone(Command):
    description = "Build and install the standalone Directional shared library"
    user_options = [
        ("build-dir=", None, "Build directory"),
        ("install-dir=", None, "Install directory"),
        ("use-gmp", None, "Enable GMP support if found"),
        ("no-use-gmp", None, "Disable GMP support"),
        ("auto-install-gmp", None, "Attempt to auto-install GMP on supported platforms"),
        ("no-auto-install-gmp", None, "Disable GMP auto-install attempts"),
        ("enable-suitesparse", None, "Enable SuiteSparse support"),
        ("disable-suitesparse", None, "Disable SuiteSparse support"),
    ]
    boolean_options = ["use-gmp", "no-use-gmp", "auto-install-gmp", "no-auto-install-gmp", "enable-suitesparse", "disable-suitesparse"]

    def initialize_options(self) -> None:
        self.build_dir = None
        self.install_dir = None
        self.use_gmp = _env_bool("DIRECTIONAL_USE_GMP", True)
        self.no_use_gmp = False
        self.enable_suitesparse = _env_bool("DIRECTIONAL_ENABLE_SUITESPARSE", True)
        self.disable_suitesparse = False
        self.auto_install_gmp = _env_bool("DIRECTIONAL_AUTO_INSTALL_GMP", True)
        self.no_auto_install_gmp = False

    def finalize_options(self) -> None:
        if self.build_dir is None:
            self.build_dir = str(_build_dir("standalone"))
        if self.install_dir is None:
            self.install_dir = str(Path(self.build_dir) / "install")
        if self.no_use_gmp:
            self.use_gmp = False
        if self.disable_suitesparse:
            self.enable_suitesparse = False
        if self.no_auto_install_gmp:
            self.auto_install_gmp = False

    def run(self) -> None:
        build_dir = Path(self.build_dir)
        install_dir = Path(self.install_dir)
        configure_args = _cmake_args(
            install_dir,
            [
                "-DBUILD_TUTORIALS=OFF",
                "-DBUILD_PYTHON=OFF",
                f"-DUSE_GMP={_as_cmake_bool(bool(self.use_gmp))}",
                f"-DDIRECTIONAL_AUTO_INSTALL_GMP={_as_cmake_bool(bool(self.auto_install_gmp))}",
                f"-DDIRECTIONAL_ENABLE_SUITESPARSE={_as_cmake_bool(bool(self.enable_suitesparse))}",
            ],
        )
        _configure_and_build(build_dir, configure_args, build_target="directional")
        _run(["cmake", "--install", str(build_dir), "--config", "Release"])


class BuildTutorials(Command):
    description = "Build the Directional tutorial suite or a selected tutorial subset"
    user_options = [
        ("build-dir=", None, "Build directory"),
        ("tutorial=", None, "Tutorial prefix like 501 or full directory name; comma-separated lists are supported"),
        ("use-gmp", None, "Enable GMP support if found"),
        ("no-use-gmp", None, "Disable GMP support"),
        ("auto-install-gmp", None, "Attempt to auto-install GMP on supported platforms"),
        ("no-auto-install-gmp", None, "Disable GMP auto-install attempts"),
        ("enable-suitesparse", None, "Enable SuiteSparse support"),
        ("disable-suitesparse", None, "Disable SuiteSparse support"),
    ]
    boolean_options = ["use-gmp", "no-use-gmp", "auto-install-gmp", "no-auto-install-gmp", "enable-suitesparse", "disable-suitesparse"]

    def initialize_options(self) -> None:
        self.build_dir = None
        self.tutorial = None
        self.use_gmp = _env_bool("DIRECTIONAL_USE_GMP", True)
        self.no_use_gmp = False
        self.auto_install_gmp = _env_bool("DIRECTIONAL_AUTO_INSTALL_GMP", True)
        self.no_auto_install_gmp = False
        self.enable_suitesparse = _env_bool("DIRECTIONAL_ENABLE_SUITESPARSE", True)
        self.disable_suitesparse = False

    def finalize_options(self) -> None:
        if self.tutorial is not None:
            self.tutorial = self.tutorial.strip()
            if not self.tutorial:
                self.tutorial = None
        if self.no_use_gmp:
            self.use_gmp = False
        if self.no_auto_install_gmp:
            self.auto_install_gmp = False
        if self.disable_suitesparse:
            self.enable_suitesparse = False
        if self.build_dir is None:
            if self.tutorial is None:
                self.build_dir = str(_build_dir("tutorials"))
            else:
                self.build_dir = str(_build_dir(f"tutorials-{_safe_build_name(self.tutorial)}"))

    def run(self) -> None:
        build_dir = Path(self.build_dir)
        selected_tutorials = self.tutorial or "ALL"
        configure_args = _cmake_args(
            build_dir / "install",
            [
                "-DBUILD_SHARED_LIBS=OFF",
                "-DBUILD_TUTORIALS=ON",
                "-DBUILD_PYTHON=OFF",
                f"-DDIRECTIONAL_TUTORIALS={selected_tutorials}",
                f"-DUSE_GMP={_as_cmake_bool(bool(self.use_gmp))}",
                f"-DDIRECTIONAL_AUTO_INSTALL_GMP={_as_cmake_bool(bool(self.auto_install_gmp))}",
                f"-DDIRECTIONAL_ENABLE_SUITESPARSE={_as_cmake_bool(bool(self.enable_suitesparse))}",
            ],
        )
        _configure_and_build(build_dir, configure_args)
        tutorial_exe_dirs = sorted({path.parent for path in build_dir.glob("**/*.exe")})
        _copy_runtime_dlls_to_targets(tutorial_exe_dirs, _tutorial_runtime_dll_dirs(build_dir))


class CMakeBuildExt(build_ext):
    user_options = build_ext.user_options + [
        ("use-gmp", None, "Enable GMP support if found"),
        ("no-use-gmp", None, "Disable GMP support"),
        ("auto-install-gmp", None, "Attempt to auto-install GMP on supported platforms"),
        ("no-auto-install-gmp", None, "Disable GMP auto-install attempts"),
        ("enable-suitesparse", None, "Enable SuiteSparse support"),
        ("disable-suitesparse", None, "Disable SuiteSparse support"),
    ]
    boolean_options = build_ext.boolean_options + ["use-gmp", "no-use-gmp", "auto-install-gmp", "no-auto-install-gmp", "enable-suitesparse", "disable-suitesparse"]

    def initialize_options(self) -> None:
        super().initialize_options()
        self.use_gmp = _env_bool("DIRECTIONAL_USE_GMP", True)
        self.no_use_gmp = False
        self.auto_install_gmp = _env_bool("DIRECTIONAL_AUTO_INSTALL_GMP", True)
        self.no_auto_install_gmp = False
        self.enable_suitesparse = _env_bool("DIRECTIONAL_ENABLE_SUITESPARSE", True)
        self.disable_suitesparse = False

    def finalize_options(self) -> None:
        super().finalize_options()
        if self.no_use_gmp:
            self.use_gmp = False
        if self.no_auto_install_gmp:
            self.auto_install_gmp = False
        if self.disable_suitesparse:
            self.enable_suitesparse = False

    def build_extension(self, ext: Extension) -> None:
        if not isinstance(ext, CMakeExtension):
            super().build_extension(ext)
            return

        build_temp = Path(self.build_temp) / ext.name
        install_dir = build_temp / "install"
        ext_fullpath = Path(self.get_ext_fullpath(ext.name)).resolve()
        extdir = ext_fullpath.parent
        extdir.mkdir(parents=True, exist_ok=True)

        try:
            pybind11_dir = subprocess.check_output(
                [sys.executable, "-m", "pybind11", "--cmakedir"],
                text=True,
            ).strip()
        except subprocess.CalledProcessError as exc:
            raise RuntimeError("pybind11 is required to build the Python extension") from exc

        configure_args = _cmake_args(
            install_dir,
            [
                "-DBUILD_TUTORIALS=OFF",
                "-DBUILD_PYTHON=ON",
                f"-Dpybind11_DIR={pybind11_dir}",
                f"-DUSE_GMP={_as_cmake_bool(bool(self.use_gmp))}",
                f"-DDIRECTIONAL_AUTO_INSTALL_GMP={_as_cmake_bool(bool(self.auto_install_gmp))}",
                f"-DDIRECTIONAL_ENABLE_SUITESPARSE={_as_cmake_bool(bool(self.enable_suitesparse))}",
            ],
        )

        _configure_and_build(build_temp, configure_args, build_target="_directional")
        _run(["cmake", "--install", str(build_temp), "--config", "Release"])

        installed_pkg_dir = install_dir / "directional"
        built_module = next(installed_pkg_dir.glob("_directional*.pyd"), None)
        if built_module is None:
            built_module = next(installed_pkg_dir.glob("_directional*.so"), None)
        if built_module is None:
            raise RuntimeError("Built Python module not found after CMake install")

        shutil.copy2(built_module, ext_fullpath)

        package_src = ROOT / "python" / "directional" / "__init__.py"
        target_pkg_dir = extdir
        shutil.copy2(package_src, target_pkg_dir / "__init__.py")

        # Copy runtime DLL dependencies beside the extension module so Python can load them.
        _copy_runtime_dlls(target_pkg_dir, _runtime_dll_dirs(build_temp, install_dir, installed_pkg_dir))


setup(
    name="directional",
    version="0.1.0",
    description="Directional field processing library with standalone, tutorial, and Python wheel builds",
    packages=find_packages(where="python"),
    package_dir={"": "python"},
    package_data={"directional": ["*.dll", "*.dylib", "*.so"]},
    include_package_data=True,
    ext_modules=[CMakeExtension("directional._directional", sourcedir=".")],
    cmdclass={
        "build_standalone": BuildStandalone,
        "standalone": BuildStandalone,
        "build_tutorials": BuildTutorials,
        "tutorials": BuildTutorials,
        "build_ext": CMakeBuildExt,
    },
    zip_safe=False,
)
