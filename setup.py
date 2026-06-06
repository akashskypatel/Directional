from __future__ import annotations

import os
import shutil
import subprocess
import sys
from pathlib import Path

from setuptools import Command, Extension, setup, find_packages
from setuptools.command.build_ext import build_ext


ROOT = Path(__file__).resolve().parent


def _run(cmd: list[str], cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    subprocess.run(cmd, cwd=str(cwd or ROOT), env=env, check=True)


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
    seen: set[Path] = set()
    for directory in directories:
        if not directory.exists():
            continue
        for dll_path in directory.glob("*.dll"):
            resolved = dll_path.resolve()
            if resolved in seen:
                continue
            seen.add(resolved)
            shutil.copy2(dll_path, target_dir / dll_path.name)


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
        ("enable-cuda", None, "Enable the optional CUDA-backed integration solver"),
        ("enable-cude", None, "Alias for --enable-cuda"),
        ("disable-cuda", None, "Disable the optional CUDA-backed integration solver"),
    ]
    boolean_options = ["use-gmp", "no-use-gmp", "auto-install-gmp", "no-auto-install-gmp", "enable-cuda", "enable-cude", "disable-cuda"]

    def initialize_options(self) -> None:
        self.build_dir = None
        self.install_dir = None
        self.use_gmp = _env_bool("DIRECTIONAL_USE_GMP", True)
        self.no_use_gmp = False
        self.auto_install_gmp = _env_bool("DIRECTIONAL_AUTO_INSTALL_GMP", True)
        self.no_auto_install_gmp = False
        self.enable_cuda = _env_bool("DIRECTIONAL_ENABLE_CUDA", True)
        self.enable_cude = False
        self.disable_cuda = False

    def finalize_options(self) -> None:
        if self.build_dir is None:
            self.build_dir = str(_build_dir("standalone"))
        if self.install_dir is None:
            self.install_dir = str(Path(self.build_dir) / "install")
        if self.no_use_gmp:
            self.use_gmp = False
        if self.no_auto_install_gmp:
            self.auto_install_gmp = False
        if self.enable_cude:
            self.enable_cuda = True
        if self.disable_cuda:
            self.enable_cuda = False

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
                f"-DDIRECTIONAL_ENABLE_CUDA={_as_cmake_bool(bool(self.enable_cuda))}",
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
        ("enable-cuda", None, "Enable the optional CUDA-backed integration solver"),
        ("enable-cude", None, "Alias for --enable-cuda"),
        ("disable-cuda", None, "Disable the optional CUDA-backed integration solver"),
    ]
    boolean_options = ["use-gmp", "no-use-gmp", "auto-install-gmp", "no-auto-install-gmp", "enable-cuda", "enable-cude", "disable-cuda"]

    def initialize_options(self) -> None:
        self.build_dir = None
        self.tutorial = None
        self.use_gmp = _env_bool("DIRECTIONAL_USE_GMP", True)
        self.no_use_gmp = False
        self.auto_install_gmp = _env_bool("DIRECTIONAL_AUTO_INSTALL_GMP", True)
        self.no_auto_install_gmp = False
        self.enable_cuda = _env_bool("DIRECTIONAL_ENABLE_CUDA", True)
        self.enable_cude = False
        self.disable_cuda = False

    def finalize_options(self) -> None:
        if self.tutorial is not None:
            self.tutorial = self.tutorial.strip()
            if not self.tutorial:
                self.tutorial = None
        if self.no_use_gmp:
            self.use_gmp = False
        if self.no_auto_install_gmp:
            self.auto_install_gmp = False
        if self.enable_cude:
            self.enable_cuda = True
        if self.disable_cuda:
            self.enable_cuda = False
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
                f"-DDIRECTIONAL_ENABLE_CUDA={_as_cmake_bool(bool(self.enable_cuda))}",
            ],
        )
        _configure_and_build(build_dir, configure_args)


class CMakeBuildExt(build_ext):
    user_options = build_ext.user_options + [
        ("use-gmp", None, "Enable GMP support if found"),
        ("no-use-gmp", None, "Disable GMP support"),
        ("auto-install-gmp", None, "Attempt to auto-install GMP on supported platforms"),
        ("no-auto-install-gmp", None, "Disable GMP auto-install attempts"),
        ("enable-cuda", None, "Enable the optional CUDA-backed integration solver"),
        ("enable-cude", None, "Alias for --enable-cuda"),
        ("disable-cuda", None, "Disable the optional CUDA-backed integration solver"),
    ]
    boolean_options = build_ext.boolean_options + ["use-gmp", "no-use-gmp", "auto-install-gmp", "no-auto-install-gmp", "enable-cuda", "enable-cude", "disable-cuda"]

    def initialize_options(self) -> None:
        super().initialize_options()
        self.use_gmp = _env_bool("DIRECTIONAL_USE_GMP", True)
        self.no_use_gmp = False
        self.auto_install_gmp = _env_bool("DIRECTIONAL_AUTO_INSTALL_GMP", True)
        self.no_auto_install_gmp = False
        self.enable_cuda = _env_bool("DIRECTIONAL_ENABLE_CUDA", True)
        self.enable_cude = False
        self.disable_cuda = False

    def finalize_options(self) -> None:
        super().finalize_options()
        if self.no_use_gmp:
            self.use_gmp = False
        if self.no_auto_install_gmp:
            self.auto_install_gmp = False
        if self.enable_cude:
            self.enable_cuda = True
        if self.disable_cuda:
            self.enable_cuda = False

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
                f"-DDIRECTIONAL_ENABLE_CUDA={_as_cmake_bool(bool(self.enable_cuda))}",
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
        runtime_bin_dir = install_dir / "bin"
        runtime_dirs = [
            runtime_bin_dir,
            ROOT / "vcpkg_installed" / "x64-windows" / "bin",
            ROOT / "vcpkg_installed" / "x64-windows" / "debug" / "bin",
            ROOT / "external" / "vcpkg" / "packages" / "gmp_x64-windows" / "bin",
            ROOT / "external" / "vcpkg" / "installed" / "x64-windows" / "bin",
        ]
        _copy_runtime_dlls(target_pkg_dir, runtime_dirs)


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
