from __future__ import annotations

import os
import shutil
import subprocess
import sys
import warnings
from dataclasses import dataclass
from pathlib import Path

from setuptools import Command, Extension, find_packages, setup
from setuptools.command.build_ext import build_ext


ROOT = Path(__file__).resolve().parent
WINDOWS_VS_CMAKE_CANDIDATES = (
    Path(
        r"C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
    ),
)
WINDOWS_VS_NINJA_CANDIDATES = (
    Path(
        r"C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe"
    ),
)

COMMON_FEATURE_USER_OPTIONS = [
    ("enable-gmp", None, "Enable GMP support if found"),
    ("disable-gmp", None, "Disable GMP support"),
    ("enable-suitesparse", None, "Enable SuiteSparse integration solver"),
    ("disable-suitesparse", None, "Disable SuiteSparse integration solver"),
    ("enable-pardiso", None, "Enable Intel oneMKL PARDISO integration solver"),
    ("disable-pardiso", None, "Disable Intel oneMKL PARDISO integration solver"),
    ("enable-cudss", None, "Enable NVIDIA cuDSS integration solver"),
    ("disable-cudss", None, "Disable NVIDIA cuDSS integration solver"),
]
CLI_USER_OPTIONS = [
    ("build-cli", None, "Build the optional native directional CLI executable"),
    ("no-build-cli", None, "Do not build the optional native directional CLI executable"),
]
FEATURE_USER_OPTIONS = [*COMMON_FEATURE_USER_OPTIONS, *CLI_USER_OPTIONS]
COMMON_FEATURE_BOOLEAN_OPTIONS = [option[0] for option in COMMON_FEATURE_USER_OPTIONS]
FEATURE_BOOLEAN_OPTIONS = [option[0] for option in FEATURE_USER_OPTIONS]



@dataclass
class BuildFeatures:
    enable_gmp: bool
    enable_suitesparse: bool
    enable_pardiso: bool
    enable_cudss: bool
    build_cli: bool

    def resolve_solver_backend(self) -> None:
        requested = [
            name
            for name, enabled in (
                ("PARDISO", self.enable_pardiso),
                ("CUDSS", self.enable_cudss),
                ("SUITESPARSE", self.enable_suitesparse),
            )
            if enabled
        ]
        if len(requested) <= 1:
            return

        selected = requested[0]
        warnings.warn(
            "Multiple integration solver backends were requested: "
            f"{', '.join(requested)}. Only {selected} will be enabled. "
            "Selection priority is PARDISO, CUDSS, SUITESPARSE.",
            RuntimeWarning,
            stacklevel=3,
        )

        self.enable_pardiso = selected == "PARDISO"
        self.enable_cudss = selected == "CUDSS"
        self.enable_suitesparse = selected == "SUITESPARSE"

    def cmake_args(self, *, build_python: bool) -> list[str]:
        return [
            f"-DBUILD_PYTHON={_as_cmake_bool(build_python)}",
            f"-DDIRECTIONAL_BUILD_CLI={_as_cmake_bool(self.build_cli)}",
            f"-DDIRECTIONAL_ENABLE_GMP={_as_cmake_bool(self.enable_gmp)}",
            f"-DDIRECTIONAL_ENABLE_SUITESPARSE={_as_cmake_bool(self.enable_suitesparse)}",
            f"-DDIRECTIONAL_ENABLE_PARDISO={_as_cmake_bool(self.enable_pardiso)}",
            f"-DDIRECTIONAL_ENABLE_CUDSS={_as_cmake_bool(self.enable_cudss)}",
        ]


def _first_existing_path(candidates: tuple[Path, ...]) -> Path | None:
    return next((candidate for candidate in candidates if candidate.exists()), None)


def _windows_cmake_executable() -> Path | None:
    override = os.environ.get("DIRECTIONAL_CMAKE_EXECUTABLE") or os.environ.get(
        "CMAKE_COMMAND"
    )
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
    return (
        ".venv" in entry_lower
        and entry_lower.endswith("\\scripts")
        and (Path(entry) / "cmake.exe").exists()
    )


def _build_env(env: dict[str, str] | None = None) -> dict[str, str]:
    merged = os.environ.copy()
    if env:
        merged.update(env)
    if sys.platform != "win32":
        return merged

    cmake_exe = _cmake_executable()
    cmake_path = Path(cmake_exe)
    cmake_parent = (
        str(cmake_path.resolve().parent).lower() if cmake_path.exists() else ""
    )
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


def _run(
    cmd: list[str],
    cwd: Path | None = None,
    env: dict[str, str] | None = None,
) -> None:
    resolved_cmd = list(cmd)
    if resolved_cmd and resolved_cmd[0] == "cmake":
        resolved_cmd[0] = _cmake_executable()

    print(f"Running: {' '.join(resolved_cmd)}")
    process = subprocess.Popen(
        resolved_cmd,
        cwd=str(cwd or ROOT),
        env=_build_env(env),
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        encoding="utf-8",
        errors="replace",
        bufsize=1,
    )
    assert process.stdout is not None

    if sys.platform == "win32":
        try:
            output = open("CONOUT$", "w", encoding="utf-8", errors="replace")
        except OSError:
            output = sys.stdout
    else:
        output = sys.stdout

    try:
        for line in process.stdout:
            output.write(line)
            output.flush()
    finally:
        if output is not sys.stdout:
            output.close()

    return_code = process.wait()
    if return_code != 0:
        raise subprocess.CalledProcessError(return_code, resolved_cmd)


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
    return "".join(
        character if character.isalnum() or character in {"-", "_"} else "-"
        for character in value
    )


def _as_cmake_bool(value: bool) -> str:
    return "ON" if value else "OFF"


def _env_bool(name: str, default: bool, *aliases: str) -> bool:
    raw = next(
        (os.environ[key] for key in (name, *aliases) if key in os.environ),
        None,
    )
    if raw is None:
        return default
    value = raw.strip().lower()
    if value in {"1", "on", "true", "yes"}:
        return True
    if value in {"0", "off", "false", "no"}:
        return False
    raise RuntimeError(f"Invalid boolean value for {name}: {raw!r}")


def _initialize_feature_options(command: object) -> None:
    command.enable_gmp = _env_bool(
        "DIRECTIONAL_ENABLE_GMP", True, "DIRECTIONAL_DIRECTIONAL_ENABLE_GMP"
    )
    command.disable_gmp = False
    command.enable_suitesparse = _env_bool("DIRECTIONAL_ENABLE_SUITESPARSE", True)
    command.disable_suitesparse = False
    command.enable_pardiso = _env_bool("DIRECTIONAL_ENABLE_PARDISO", True)
    command.disable_pardiso = False
    command.enable_cudss = _env_bool("DIRECTIONAL_ENABLE_CUDSS", True)
    command.disable_cudss = False
    command.build_cli = _env_bool("DIRECTIONAL_BUILD_CLI", False)
    command.no_build_cli = False


def _finalize_feature_options(command: object) -> BuildFeatures:
    features = BuildFeatures(
        enable_gmp=bool(command.enable_gmp and not command.disable_gmp),
        enable_suitesparse=bool(
            command.enable_suitesparse and not command.disable_suitesparse
        ),
        enable_pardiso=bool(command.enable_pardiso and not command.disable_pardiso),
        enable_cudss=bool(command.enable_cudss and not command.disable_cudss),
        build_cli=bool(command.build_cli and not command.no_build_cli),
    )
    features.resolve_solver_backend()

    command.enable_gmp = features.enable_gmp
    command.enable_suitesparse = features.enable_suitesparse
    command.enable_pardiso = features.enable_pardiso
    command.enable_cudss = features.enable_cudss
    command.build_cli = features.build_cli
    return features


def _features_from_command(command: object) -> BuildFeatures:
    return BuildFeatures(
        enable_gmp=bool(command.enable_gmp),
        enable_suitesparse=bool(command.enable_suitesparse),
        enable_pardiso=bool(command.enable_pardiso),
        enable_cudss=bool(command.enable_cudss),
        build_cli=bool(command.build_cli),
    )


def _configure(build_dir: Path, configure_args: list[str]) -> None:
    build_dir.mkdir(parents=True, exist_ok=True)
    _run(["cmake", "-S", str(ROOT), "-B", str(build_dir), *configure_args])


def _build(build_dir: Path, *targets: str) -> None:
    command = ["cmake", "--build", str(build_dir), "--config", "Release"]
    if targets:
        command.extend(["--target", *targets])
    _run(command)


def _install(build_dir: Path) -> None:
    _run(["cmake", "--install", str(build_dir), "--config", "Release"])


class CMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = ".") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = str(Path(sourcedir).resolve())


class BuildStandalone(Command):
    description = "Build and install the standalone Directional library and optional native CLI"
    user_options = [
        ("build-dir=", None, "Build directory"),
        ("install-dir=", None, "Install directory"),
        *FEATURE_USER_OPTIONS,
    ]
    boolean_options = FEATURE_BOOLEAN_OPTIONS

    def initialize_options(self) -> None:
        self.build_dir = None
        self.install_dir = None
        _initialize_feature_options(self)

    def finalize_options(self) -> None:
        if self.build_dir is None:
            self.build_dir = str(_build_dir("standalone"))
        if self.install_dir is None:
            self.install_dir = str(Path(self.build_dir) / "install")
        _finalize_feature_options(self)

    def run(self) -> None:
        build_dir = Path(self.build_dir)
        install_dir = Path(self.install_dir)
        features = _features_from_command(self)
        configure_args = _cmake_args(
            install_dir,
            [
                *features.cmake_args(build_python=False),
                "-DBUILD_TUTORIALS=OFF",
            ],
        )
        _configure(build_dir, configure_args)
        _build(build_dir, "directional_cli" if features.build_cli else "directional")
        _install(build_dir)


class BuildTutorials(Command):
    description = "Build the Directional tutorial suite or a selected tutorial subset"
    user_options = [
        ("build-dir=", None, "Build directory"),
        (
            "tutorial=",
            None,
            "Tutorial prefix or full directory name; comma-separated selections are supported",
        ),
        *COMMON_FEATURE_USER_OPTIONS,
    ]
    boolean_options = COMMON_FEATURE_BOOLEAN_OPTIONS

    def initialize_options(self) -> None:
        self.build_dir = None
        self.tutorial = None
        _initialize_feature_options(self)

    def finalize_options(self) -> None:
        if self.tutorial is not None:
            self.tutorial = self.tutorial.strip() or None

        # Tutorials never package the native CLI, so keep this command focused
        # on tutorial executables while reusing the common backend resolver.
        self.build_cli = False
        self.no_build_cli = True
        _finalize_feature_options(self)

        if self.build_dir is None:
            suffix = (
                "tutorials"
                if self.tutorial is None
                else f"tutorials-{_safe_build_name(self.tutorial)}"
            )
            self.build_dir = str(_build_dir(suffix))

    def run(self) -> None:
        build_dir = Path(self.build_dir)
        features = _features_from_command(self)
        selected_tutorials = self.tutorial or "ALL"

        configure_args = _cmake_args(
            build_dir / "install",
            [
                *features.cmake_args(build_python=False),
                "-DBUILD_SHARED_LIBS=OFF",
                "-DBUILD_TUTORIALS=ON",
                "-DDIRECTIONAL_BUILD_CLI=OFF",
                f"-DDIRECTIONAL_TUTORIALS={selected_tutorials}",
            ],
        )

        _configure(build_dir, configure_args)
        _build(build_dir)


class CMakeBuildExt(build_ext):
    user_options = [*build_ext.user_options, *FEATURE_USER_OPTIONS]
    boolean_options = [*build_ext.boolean_options, *FEATURE_BOOLEAN_OPTIONS]

    def initialize_options(self) -> None:
        super().initialize_options()
        _initialize_feature_options(self)

    def finalize_options(self) -> None:
        super().finalize_options()
        _finalize_feature_options(self)

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
            raise RuntimeError(
                "pybind11 is required to build the Python extension"
            ) from exc

        features = _features_from_command(self)
        configure_args = _cmake_args(
            install_dir,
            [
                *features.cmake_args(build_python=True),
                "-DBUILD_TUTORIALS=OFF",
                f"-Dpybind11_DIR={pybind11_dir}",
            ],
        )

        _configure(build_temp, configure_args)
        targets = ["_directional"]
        if features.build_cli:
            targets.append("directional_cli")
        _build(build_temp, *targets)
        _install(build_temp)

        installed_pkg_dir = install_dir / "directional"
        built_module = next(installed_pkg_dir.glob("_directional*.pyd"), None)
        if built_module is None:
            built_module = next(installed_pkg_dir.glob("_directional*.so"), None)
        if built_module is None:
            raise RuntimeError("Built Python module not found after CMake install")

        shutil.copy2(built_module, ext_fullpath)
        shutil.copy2(
            ROOT / "python" / "directional" / "__init__.py",
            extdir / "__init__.py",
        )

        if features.build_cli:
            installed_bin_dir = install_dir / "bin"
            if not installed_bin_dir.is_dir():
                raise RuntimeError(
                    "Native CLI was requested, but CMake did not install a bin directory"
                )
            packaged_bin_dir = extdir / "bin"
            packaged_bin_dir.mkdir(parents=True, exist_ok=True)
            for runtime_file in installed_bin_dir.iterdir():
                if runtime_file.is_file():
                    shutil.copy2(runtime_file, packaged_bin_dir / runtime_file.name)


setup(
    name="directional",
    version="0.1.0",
    description="Directional field processing library with standalone, tutorial, native CLI, and Python wheel builds",
    packages=find_packages(where="python"),
    package_dir={"": "python"},
    package_data={"directional": ["*.dll", "*.dylib", "*.so", "bin/*"]},
    include_package_data=True,
    ext_modules=[CMakeExtension("directional._directional", sourcedir=".")],
    entry_points={"console_scripts": ["directional=directional.cli:main"]},
    cmdclass={
        "build_standalone": BuildStandalone,
        "standalone": BuildStandalone,
        "build_tutorials": BuildTutorials,
        "tutorials": BuildTutorials,
        "build_ext": CMakeBuildExt,
    },
    zip_safe=False,
)
