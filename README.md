# Directional

Directional is a directional-field processing library used here as a standalone C++ package and as a Python extension module.

This fork now supports two build workflows:

- pure CMake for native C++ consumers
- Python packaging builds via `setup.py` and `pip`

## Build outputs

The top-level project can build:

1. `directional` — compiled C++ library (shared by default, static when requested)
2. `_directional` — Python extension module
3. `directional_cli` — optional native executable installed as `directional`
4. `directional_cli_backend` — shared C++ command implementation used by both CLIs

The Python console script and native executable intentionally expose the same commands and option parsing through the C++ CLI backend.

## Requirements

### Native build

- CMake 3.21 or newer
- C++20-capable compiler
- Git submodules initialized, including Eigen
- Python only when building Python bindings or invoking `setup.py`

### Python build

Python 3.13 is verified in this repository. Install the build dependencies with:

```powershell
python -m pip install setuptools wheel pybind11
```

For PEP 517 builds, install any additional requirements declared by the project build configuration or disable build isolation when the active environment already contains them.

## Dependencies

### Eigen

Eigen is required and included as a repository submodule.

```powershell
git submodule update --init --recursive
```

Native installs include the vendored Eigen headers required by Directional's
public API, so installed-package consumers do not need a separate Eigen setup.

### GMP

GMP is optional and enables the preferred exact-arithmetic implementation.

- CMake option: `DIRECTIONAL_ENABLE_GMP`
- Default: `ON`
- MSVC builds can auto-install it when it is not already available
- Other platforms should provide GMP and GMPXX through the system or toolchain

When GMP cannot be found, CMake emits a warning and continues without GMP.

### Integration solver backends

DirectionalReMesher supports three optional integration solver backends:

- Intel oneMKL PARDISO
- NVIDIA cuDSS
- SuiteSparse / UMFPACK

Only one backend is enabled in a build. If more than one is requested, both CMake and `setup.py` emit a warning and select the first available request in this fixed order:

```text
PARDISO > CUDSS > SUITESPARSE
```

Relevant CMake options:

```text
DIRECTIONAL_ENABLE_PARDISO=ON|OFF
DIRECTIONAL_ENABLE_CUDSS=ON|OFF
DIRECTIONAL_ENABLE_SUITESPARSE=ON|OFF
CUDSS_ROOT=<path>
```

CMake defaults are:

```text
PARDISO=OFF
CUDSS=OFF
SUITESPARSE=ON
```

The current `setup.py` defaults request all three backends and therefore resolve to PARDISO unless overridden.

#### PARDISO

PARDISO uses Intel oneMKL and is the highest-priority backend. On supported MSVC builds, the dependency logic can install oneMKL automatically. Required runtime modules are copied beside the native library, native CLI, and Python extension during build and install.

#### cuDSS

cuDSS requires an NVIDIA cuDSS installation and the imported CMake target `CUDSS::cudss`. Set `CUDSS_ROOT` when automatic discovery is insufficient.

Example:

```powershell
cmake -S . -B build\cudss `
  -DDIRECTIONAL_ENABLE_PARDISO=OFF `
  -DDIRECTIONAL_ENABLE_CUDSS=ON `
  -DDIRECTIONAL_ENABLE_SUITESPARSE=OFF `
  -DCUDSS_ROOT="C:\Program Files\NVIDIA cuDSS\v0.8"
```

#### SuiteSparse

SuiteSparse is the default CMake backend. Supported MSVC builds can auto-install it when necessary. Other platforms should provide a usable SuiteSparse package or CMake configuration.

## CMake options

| Option | Default | Purpose |
|---|---:|---|
| `BUILD_SHARED_LIBS` | `ON` | Build the Directional Core and Pipeline modules as shared libraries; set `OFF` for static archives |
| `BUILD_PYTHON` | `OFF` | Build the Python extension |
| `DIRECTIONAL_BUILD_CLI` | `OFF` | Build the native CLI executable |
| `DIRECTIONAL_ENABLE_GMP` | `ON` | Enable GMP exact arithmetic |
| `DIRECTIONAL_ENABLE_SUITESPARSE` | `ON` | Request SuiteSparse |
| `DIRECTIONAL_ENABLE_PARDISO` | `OFF` | Request Intel oneMKL PARDISO |
| `DIRECTIONAL_ENABLE_CUDSS` | `OFF` | Request NVIDIA cuDSS |
| `CUDSS_ROOT` | empty | cuDSS installation root |
| `CMAKE_INSTALL_PREFIX` | platform default | Installation destination |

## Native CMake builds

Directional is split into `Directional::core` and `Directional::pipeline`.
Pipeline links Core and contains the meshing and high-level remeshing
implementation. `Directional::directional` remains available as a compatibility
target that links the complete Pipeline/Core stack.

### Shared library with SuiteSparse

```powershell
cmake -S . -B build\standalone `
  -DCMAKE_INSTALL_PREFIX="$PWD\build\standalone\install" `
  -DBUILD_SHARED_LIBS=ON `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_BUILD_CLI=OFF `
  -DDIRECTIONAL_ENABLE_GMP=ON `
  -DDIRECTIONAL_ENABLE_PARDISO=OFF `
  -DDIRECTIONAL_ENABLE_CUDSS=OFF `
  -DDIRECTIONAL_ENABLE_SUITESPARSE=ON

cmake --build build\standalone --config Release --target directional_pipeline
cmake --install build\standalone --config Release
```

### Static library

Use the same target and installed package with `BUILD_SHARED_LIBS=OFF`:

```powershell
cmake -S . -B build\static `
  -DCMAKE_INSTALL_PREFIX="$PWD\build\static\install" `
  -DBUILD_SHARED_LIBS=OFF `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_BUILD_CLI=OFF

cmake --build build\static --config Release --target directional_pipeline
cmake --install build\static --config Release
```

### Shared library with PARDISO

```powershell
cmake -S . -B build\pardiso `
  -DCMAKE_INSTALL_PREFIX="$PWD\build\pardiso\install" `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_ENABLE_PARDISO=ON `
  -DDIRECTIONAL_ENABLE_CUDSS=OFF `
  -DDIRECTIONAL_ENABLE_SUITESPARSE=OFF

cmake --build build\pardiso --config Release --target directional_pipeline
cmake --install build\pardiso --config Release
```

### Native CLI

```powershell
cmake -S . -B build\native-cli `
  -DCMAKE_INSTALL_PREFIX="$PWD\build\native-cli-release" `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_BUILD_CLI=ON `
  -DDIRECTIONAL_ENABLE_PARDISO=ON

cmake --build build\native-cli --config Release --target directional_cli
cmake --install build\native-cli --config Release
```

The installed executable is normally:

```text
<install-prefix>/bin/directional.exe
```

Run:

```powershell
directional --help
directional info
```

### Python extension through CMake

```powershell
python -m pip install pybind11
$pybind11Dir = python -m pybind11 --cmakedir

cmake -S . -B build\python `
  -DCMAKE_INSTALL_PREFIX="$PWD\build\python\install" `
  -DBUILD_PYTHON=ON `
  -DDIRECTIONAL_BUILD_CLI=OFF `
  -Dpybind11_DIR="$pybind11Dir" `
  -DDIRECTIONAL_ENABLE_PARDISO=ON

cmake --build build\python --config Release --target _directional
cmake --install build\python --config Release
```

The extension and Python package files are installed beneath:

```text
build/python/install/directional/
```

### Consume the installed C++ package

```cmake
find_package(Directional CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE Directional::directional)
```

For a nonstandard installation prefix:

```powershell
cmake -S . -B build `
  -DCMAKE_PREFIX_PATH="D:\path\to\DirectionalReMesher\build\standalone\install"
```

## `setup.py` builds

`setup.py` forwards build features to CMake and uses the same solver-selection priority.

### Feature flags

```text
--enable-gmp / --disable-gmp
--enable-suitesparse / --disable-suitesparse
--enable-pardiso / --disable-pardiso
--enable-cudss / --disable-cudss
--build-cli / --no-build-cli
```

### Standalone library

```powershell
python setup.py standalone
```

Default paths:

```text
build tree:   build/standalone/
install tree: build/standalone/install/
```

Build the library and native CLI together:

```powershell
python setup.py standalone --build-cli
```

Select a solver explicitly:

```powershell
python setup.py standalone `
  --enable-pardiso `
  --disable-cudss `
  --disable-suitesparse `
  --build-cli
```

### Python extension and wheel

Build the extension:

```powershell
python setup.py build_ext
```

Build a wheel:

```powershell
python setup.py bdist_wheel
```

Pass feature flags through `build_ext` when creating a wheel:

```powershell
python setup.py build_ext `
  --enable-pardiso `
  --disable-cudss `
  --disable-suitesparse `
  bdist_wheel
```

Build and package the native executable with the wheel:

```powershell
python setup.py build_ext --build-cli bdist_wheel
```

When enabled, the installed native CLI and its runtime dependency closure are packaged beneath:

```text
directional/bin/
```

The Python console script remains available as `directional` and forwards commands to the same C++ backend through the extension module.

## PEP 517 and `pip`

The custom build backend accepts short and namespaced configuration keys.

| Short key | Namespaced key | Environment variable |
|---|---|---|
| `enable-gmp` | `directional.enable-gmp` | `DIRECTIONAL_ENABLE_GMP` |
| `enable-suitesparse` | `directional.enable-suitesparse` | `DIRECTIONAL_ENABLE_SUITESPARSE` |
| `enable-pardiso` | `directional.enable-pardiso` | `DIRECTIONAL_ENABLE_PARDISO` |
| `enable-cudss` | `directional.enable-cudss` | `DIRECTIONAL_ENABLE_CUDSS` |
| `build-cli` | `directional.build-cli` | `DIRECTIONAL_BUILD_CLI` |

Boolean values accept:

```text
1, 0, on, off, true, false, yes, no
```

### Basic install

```powershell
python -m pip install . --no-build-isolation
```

### Build a PARDISO wheel

```powershell
python -m pip wheel . `
  --no-deps `
  --no-build-isolation `
  -Cdirectional.enable-pardiso=true `
  -Cdirectional.enable-cudss=false `
  -Cdirectional.enable-suitesparse=false
```

### Build a wheel containing the native CLI

```powershell
python -m pip wheel . `
  --no-deps `
  --no-build-isolation `
  -Cdirectional.build-cli=true
```

### Environment-variable configuration

```powershell
$env:DIRECTIONAL_ENABLE_GMP = "1"
$env:DIRECTIONAL_ENABLE_PARDISO = "1"
$env:DIRECTIONAL_ENABLE_CUDSS = "0"
$env:DIRECTIONAL_ENABLE_SUITESPARSE = "0"
$env:DIRECTIONAL_BUILD_CLI = "1"

python -m pip wheel . --no-build-isolation
```

The legacy GMP environment variable `DIRECTIONAL_DIRECTIONAL_ENABLE_GMP` remains accepted as an alias.

## Command-line interface

Both the Python command and native executable support the same command set:

```text
directional info
directional cross-field <input.obj|input.off> <output-field> [options]
directional convert-field <input-field> <output-field> [options]
directional remesh <input.obj|input.off> <output.obj|output.off> [options]
directional --version
directional --help
```

The Python module form is also supported:

```powershell
python -m directional --help
```

### Field formats

| Format | Extensions | Description |
|---|---|---|
| `crossfield` | `.vec`, `.txt` | Alpha and beta vectors; six values per row |
| `rosy` | `.rosy` | Count/degree header followed by one alpha vector per face |
| `rawfield` | `.rawfield` | Degree/count header followed by `3 × degree` values per face |

### Extract a cross field

```powershell
directional cross-field input.obj output.rosy `
  --output-format rosy `
  --singularities output.sings
```

Options:

```text
--output-format <auto|crossfield|rosy|rawfield>
--no-normalize-directions
--no-normalize
--no-matching
--singularities <path>
--diagnostics-prefix <prefix>
--verbose
```

### Convert a field

```powershell
directional convert-field input.rosy output.txt `
  --input-format rosy `
  --output-format crossfield `
  --mesh input.obj
```

Options:

```text
--input-format <auto|crossfield|rosy|rawfield>
--output-format <auto|crossfield|rosy|rawfield>
--mesh <input.obj|input.off>
--degree <2|4>
```

The mesh is required when conversion must reconstruct beta directions from face normals.

### Remesh

Compute a cross field automatically and remesh:

```powershell
directional remesh input.obj output.obj --length-ratio 0.02
```

Use an existing field:

```powershell
directional remesh input.obj output.off `
  --field input.rosy `
  --field-format rosy `
  --length-ratio 0.02
```

Options:

```text
--field <path>
--field-format <auto|crossfield|rosy|rawfield>
--raw-field <path>
--primary-directions <path>
--secondary-directions <path>
--length-ratio <value>
--no-integral-seamless
--round-seams
--no-normalize-directions
--diagnostics-prefix <prefix>
--verbose
```

Without `--verbose`, long-running remeshing stages use in-place top-level progress reporting. With `--verbose`, detailed phase timing and solver diagnostics are printed as regular log lines.

## Polyscope desktop UI

The optional `directional-ui` executable provides a native C++ interface for the
field-extraction and quad-remeshing pipeline.

### Features

- Load an OBJ or OFF triangular mesh using the platform-native file dialog.
- Calculate a smooth power field or regularized-curvature field.
- Automatically calculate a field and quad-remesh the loaded mesh.
- Load a RawField, CrossField, or RoSy field and quad-remesh with it.
- Visualize the input triangle mesh, four cross-field branches, and output quads.
- Save fields through the existing field-conversion implementation.
- Save pure quad meshes as OBJ or OFF.
- Run field extraction and remeshing asynchronously so the viewer remains responsive.

### Build

```powershell
cmake -S . -B build\gui `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_BUILD_CLI=OFF `
  -DDIRECTIONAL_BUILD_GUI=ON `
  -DDIRECTIONAL_ENABLE_PARDISO=ON

cmake --build build\gui --config Release --target directional_gui
```

### Build with setup.py

Build and install only the desktop UI:

```powershell
python setup.py build_gui --enable-pardiso
```

The executable and runtime dependencies are installed beneath:

```text
build/gui/install/bin/
```

Build the standalone library, CLI, and UI together:

```powershell
python setup.py build_standalone `
  --build-cli `
  --build-gui `
  --enable-pardiso
```

Build a Python wheel which also packages the native UI under
`directional/bin/`:

```powershell
python setup.py build_ext --build-gui bdist_wheel
```

The equivalent PEP 517 setting is:

```powershell
python -m pip wheel . `
  --no-deps `
  --no-build-isolation `
  -Cdirectional.build-gui=true
```

Run:

```powershell
build\gui\Release\directional-ui.exe
build\gui\Release\directional-ui.exe path\to\mesh.obj
```

The **Browse...** buttons use the operating system's native file dialog:

- Windows: `IFileOpenDialog`
- macOS: `NSOpenPanel`
- Linux: XDG Desktop Portal through GIO/GDBus

On Linux, install the GIO development package when building the GUI (for
example, `libglib2.0-dev` on Debian/Ubuntu or `glib2-devel` on Fedora). The
runtime also needs `xdg-desktop-portal` and a portal backend provided by the
desktop environment. If GIO or the portal service is unavailable, the UI
automatically opens the dependency-free ImGui file picker instead.

Path entry fields remain editable and may contain absolute paths or paths
relative to the current working directory.

## Python API

The extension exposes the headless remeshing API, including:

```text
directional.RemeshOptions
directional.RemeshResult
directional.remesh_from_cross_field(...)
directional.remesh_from_raw_cross_field(...)
```

Minimal example:

```python
import numpy as np
import directional

vertices = np.array(
    [
        [0.0, 0.0, 0.0],
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
    ],
    dtype=np.float64,
)
faces = np.array([[0, 1, 2]], dtype=np.int32)
primary_directions = np.array([[1.0, 0.0, 0.0]], dtype=np.float64)

options = directional.RemeshOptions()
result = directional.remesh_from_cross_field(
    vertices,
    faces,
    primary_directions,
    options,
)

print(result.is_produced)
```

## Recommended Workflows

Use pure CMake when:

- you want to link Directional from another native C++ project
- you want a standard installed CMake package via `find_package`

Use `setup.py` when:

- you want the fastest local build entrypoint
- you want to produce a Python wheel
- you want one-command tutorial builds

Use `pip` when:

- you want a standard PEP 517 install path
- you want to drive GMP options through `--config-settings`

## Notes

- The installed C++ package exports `Directional::directional`.
- Non-template algorithms are compiled into `directional`; public headers retain
  declarations and genuinely type-dependent template definitions. Implementations
  live physically in `.cpp` files, so implementation-only edits rebuild their
  owning object and relink without recompiling consumers.
- Generic Eigen and DCEL templates remain available for arbitrary supported scalar,
  expression, and payload types. Directional avoids restrictive explicit
  instantiations; implementation-only template dependencies are included by their
  owning `.cpp` files instead of public declarations where possible.
- Shared and static installs expose the same `Directional::directional` target.
- The Python wheel is platform-specific because it contains a compiled extension module.
- Tutorial and Python builds depend on the same top-level CMake project; `setup.py` is only a wrapper over that build.

## Tutorials

Build all tutorials:

```powershell
python setup.py tutorials
```

Build a selected tutorial:

```powershell
python setup.py tutorials --tutorial=501
```

Build several selected tutorials:

```powershell
python setup.py tutorials --tutorial=501,502,601
```

Custom build directory:

```powershell
python setup.py tutorials `
  --tutorial=501 `
  --build-dir=build\tutorial-501
```

Solver options are also supported:

```powershell
python setup.py tutorials `
  --enable-pardiso `
  --disable-cudss `
  --disable-suitesparse
```

### Tutorial CMake parameters

The tutorial command configures:

```text
BUILD_SHARED_LIBS=OFF
BUILD_TUTORIALS=ON
BUILD_PYTHON=OFF
DIRECTIONAL_BUILD_CLI=OFF
DIRECTIONAL_TUTORIALS=<selection or ALL>
```

## Tests

Install test dependencies and run the Python tests:

```powershell
python -m pip install -e .[test] --no-build-isolation
python -m pytest
```

For native validation, configure and build the desired CMake targets, then run any CTest targets included by the current source tree:

```powershell
ctest --test-dir build\standalone -C Release --output-on-failure
```

## Installation layout

A native install typically contains:

```text
bin/                       directional executable and runtime DLLs
lib/                       directional import/static artifacts
include/                   Directional and Eigen headers
lib/cmake/Directional/     exported CMake package
```

A Python install contains:

```text
directional/
  __init__.py
  _directional*.pyd|so
  bin/                     optional native CLI and runtime files
```

## Recommended workflows

Use direct CMake when:

- embedding DirectionalReMesher into another C++ project
- producing an installed `find_package`-compatible package
- controlling dependency discovery and runtime deployment directly

Use `setup.py` when:

- iterating locally on the Python extension
- building the standalone library through a Python command
- building the optional native CLI alongside the extension

Use PEP 517 / `pip` when:

- producing standard wheels
- integrating with build automation
- controlling solver and CLI options through `--config-settings`

## Notes

- Only one integration solver backend is compiled into a build.
- The selection priority is always PARDISO, then cuDSS, then SuiteSparse.
- The C++ package exports `Directional::directional`.
- Python wheels are platform-specific because they contain a compiled extension.
- PARDISO builds deploy the oneMKL runtime modules needed by `mkl_rt` beside installed binaries.
- The native CLI and Python CLI share the same C++ implementation; command behavior should remain consistent between them.

## Citation

Original source: [avaxman/Directional](https://github.com/avaxman/Directional)

If you use this project in research, cite the original Directional work:

```bibtex
@misc{Directional,
  author = {Amir Vaxman and others},
  title = {Directional: A library for Directional Field Synthesis, Design, and Processing},
  doi = {10.5281/zenodo.3338174},
  url = {https://doi.org/10.5281/zenodo.3338174}
}
```
