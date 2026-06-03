# Directional

Directional is a directional-field processing library used here as a standalone C++ package and as a Python extension module.

This fork now supports two build workflows:

- pure CMake for native C++ consumers
- Python packaging builds via `setup.py` and `pip`

## What This Repository Builds

The top-level build supports three modes:

1. `directional` standalone shared library
2. tutorial executables
3. Python package / wheel exposing the headless remeshing API

Key build toggles:

- `BUILD_TUTORIALS=ON|OFF`
- `BUILD_PYTHON=ON|OFF`
- `BUILD_SHARED_LIBS=ON|OFF`
- `USE_GMP=ON|OFF`
- `DIRECTIONAL_AUTO_INSTALL_GMP=ON|OFF`

## Prerequisites

### Native build prerequisites

- CMake 3.15+
- A C++20-capable compiler
- Python is only required if you are building the Python bindings or using `setup.py`

### Python build prerequisites

- Python 3.13 was verified in this repo
- `setuptools`
- `wheel`
- `pybind11`

Install the Python-side build requirements with:

```powershell
python -m pip install setuptools wheel pybind11
```

If you want the docs/site Python dependencies instead:

```powershell
python -m pip install -r requirements.txt
```

## Pure CMake Build

Common GMP flags for all CMake examples:

```powershell
-DUSE_GMP=ON|OFF
-DDIRECTIONAL_AUTO_INSTALL_GMP=ON|OFF
```

Examples:

- GMP enabled: `-DUSE_GMP=ON -DDIRECTIONAL_AUTO_INSTALL_GMP=ON`
- non-GMP build: `-DUSE_GMP=OFF -DDIRECTIONAL_AUTO_INSTALL_GMP=OFF`

### 1. Build and install the standalone library

This is the native C++ path if you want a reusable installed package.

```powershell
cmake -S . -B build\standalone `
  -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_INSTALL_PREFIX=%CD%\build\standalone\install `
  -DBUILD_TUTORIALS=OFF `
  -DBUILD_PYTHON=OFF `
  -DUSE_GMP=ON `
  -DDIRECTIONAL_AUTO_INSTALL_GMP=ON

cmake --build build\standalone --config Release --target directional
cmake --install build\standalone --config Release
```

Artifacts:

- shared library under `build\standalone\Release\` during build
- installed library under `build\standalone\install\bin` and `build\standalone\install\lib`
- installed headers under `build\standalone\install\include`
- CMake package files under `build\standalone\install\lib\cmake\Directional`

### 2. Consume the installed library from another CMake project

```cmake
find_package(Directional CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE Directional::directional)
```

If Directional is installed in a nonstandard location, point CMake at it:

```powershell
cmake -S . -B build -DCMAKE_PREFIX_PATH=D:\path\to\Directional\build\standalone\install
```

### 3. Build the tutorials with pure CMake

```powershell
cmake -S . -B build\tutorials `
  -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_INSTALL_PREFIX=%CD%\build\tutorials\install `
  -DBUILD_SHARED_LIBS=OFF `
  -DBUILD_TUTORIALS=ON `
  -DBUILD_PYTHON=OFF `
  -DUSE_GMP=ON `
  -DDIRECTIONAL_AUTO_INSTALL_GMP=ON

cmake --build build\tutorials --config Release
```

Tutorial binaries are written under:

- `tutorial\bin\Release\`

`BUILD_SHARED_LIBS=OFF` is the recommended tutorial setting in this fork because it avoids Windows link issues in the bundled viewer stack.

To build only specific tutorials, pass `DIRECTIONAL_TUTORIALS` as a semicolon-separated or comma-separated list of tutorial prefixes or full directory names:

```powershell
cmake -S . -B build\tutorials-single `
  -DCMAKE_BUILD_TYPE=Release `
  -DBUILD_SHARED_LIBS=OFF `
  -DBUILD_TUTORIALS=ON `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_TUTORIALS=501 `
  -DUSE_GMP=ON `
  -DDIRECTIONAL_AUTO_INSTALL_GMP=ON

cmake --build build\tutorials-single --config Release
```

Example for multiple tutorials:

```powershell
cmake -S . -B build\tutorials-pair -DBUILD_SHARED_LIBS=OFF -DBUILD_TUTORIALS=ON -DBUILD_PYTHON=OFF -DDIRECTIONAL_TUTORIALS=501,505
```

### 4. Build the Python extension with pure CMake

This path is useful if you want CMake to produce the Python module directly instead of going through `setup.py`.

First, make sure `pybind11` is installed and discoverable:

```powershell
python -m pip install pybind11
python -m pybind11 --cmakedir
```

Then configure:

```powershell
cmake -S . -B build\python `
  -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_INSTALL_PREFIX=%CD%\build\python\install `
  -DBUILD_TUTORIALS=OFF `
  -DBUILD_PYTHON=ON `
  -Dpybind11_DIR="C:\path\reported\by\pybind11\cmakedir" `
  -DUSE_GMP=ON `
  -DDIRECTIONAL_AUTO_INSTALL_GMP=ON

cmake --build build\python --config Release --target _directional
cmake --install build\python --config Release
```

Artifacts are installed under:

- `build\python\install\directional\`

That folder will contain:

- `_directional*.pyd` or `_directional*.so`
- `__init__.py`

## Python `setup.py` Build

`setup.py` wraps the CMake build so you do not have to pass the common configuration manually.

Supported GMP flags:

- `--use-gmp`
- `--no-use-gmp`
- `--auto-install-gmp`
- `--no-auto-install-gmp`

### 1. Build the standalone shared library

```powershell
python setup.py standalone
```

Default output locations:

- build tree: `build\standalone\`
- install tree: `build\standalone\install\`

Examples:

```powershell
python setup.py standalone --use-gmp --auto-install-gmp
python setup.py standalone --no-use-gmp --no-auto-install-gmp
```

### 2. Build the tutorial suite

```powershell
python setup.py tutorials
```

Default output location:

- build tree: `build\tutorials\`

Tutorial executables are emitted into:

- `tutorial\bin\Release\`

To build only specific tutorials:

```powershell
python setup.py tutorials --tutorial=501
```

Or multiple tutorials:

```powershell
python setup.py tutorials --tutorial=501,505
```

With explicit GMP selection:

```powershell
python setup.py tutorials --tutorial=501 --no-use-gmp --no-auto-install-gmp
```

When `--tutorial` is provided, `setup.py` uses a tutorial-specific build directory by default so single-target builds do not reuse the full-suite build tree. Full names like `501_SeamlessIntegration` still work if you want exact naming.

### 3. Build a Python wheel

```powershell
python setup.py bdist_wheel
```

`bdist_wheel` goes through `build_ext`, so GMP flags must be passed to `build_ext` in the same invocation:

```powershell
python setup.py build_ext --no-use-gmp bdist_wheel
python setup.py build_ext --use-gmp --auto-install-gmp bdist_wheel
```

Wheel output:

- `dist\directional-<version>-<python>-<abi>-<platform>.whl`

Example verified in this repo:

- `dist\directional-0.1.0-cp313-cp313-win_amd64.whl`

### 4. Install the built wheel

```powershell
python -m pip install dist\directional-0.1.0-cp313-cp313-win_amd64.whl
```

Or reinstall during local iteration:

```powershell
python -m pip install --force-reinstall dist\directional-0.1.0-cp313-cp313-win_amd64.whl
```

## Python `pip` Build

`pip` and other PEP 517 frontends can now control the same GMP toggles through `--config-settings`.

Supported keys:

- `-Cuse-gmp=1|0`
- `-Cauto-install-gmp=1|0`

Examples:

```powershell
python -m pip install . --no-build-isolation -Cuse-gmp=1 -Cauto-install-gmp=1
python -m pip install . --no-build-isolation -Cuse-gmp=0 -Cauto-install-gmp=0
python -m pip wheel . --no-deps --no-build-isolation -Cuse-gmp=0 -Cauto-install-gmp=0
```

Namespaced aliases are also accepted if you prefer explicit keys:

```powershell
python -m pip install . --no-build-isolation -Cdirectional.use-gmp=0 -Cdirectional.auto-install-gmp=0
```

Environment-variable fallback also works:

```powershell
$env:DIRECTIONAL_USE_GMP = "0"
$env:DIRECTIONAL_AUTO_INSTALL_GMP = "0"
python -m pip install . --no-build-isolation
```

## Python API

The wheel exposes a small headless remeshing API:

- `directional.RemeshOptions`
- `directional.RemeshResult`
- `directional.remesh_from_cross_field(...)`
- `directional.remesh_from_raw_cross_field(...)`

Example:

```python
import numpy as np
import directional

V = np.array([
    [0.0, 0.0, 0.0],
    [1.0, 0.0, 0.0],
    [0.0, 1.0, 0.0],
], dtype=np.float64)

F = np.array([[0, 1, 2]], dtype=np.int32)
PD1 = np.array([[1.0, 0.0, 0.0]], dtype=np.float64)

opts = directional.RemeshOptions()
result = directional.remesh_from_cross_field(V, F, PD1, opts)
print(result.success)
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
- The current standalone library is intentionally minimal; most functionality remains header-driven.
- The Python wheel is platform-specific because it contains a compiled extension module.
- Tutorial and Python builds depend on the same top-level CMake project; `setup.py` is only a wrapper over that build.

## Verified Commands

The following commands were verified in this fork:

```powershell
python setup.py standalone
python setup.py tutorials
python setup.py build_ext --no-use-gmp bdist_wheel
python -m pip wheel . --no-deps --no-build-isolation -Cuse-gmp=0 -Cauto-install-gmp=0
```

And for pure CMake:

```powershell
cmake -S . -B build\standalone -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=%CD%\build\standalone\install -DBUILD_TUTORIALS=OFF -DBUILD_PYTHON=OFF
cmake --build build\standalone --config Release --target directional
cmake --install build\standalone --config Release
```

## Citation

Original source: https://github.com/avaxman/Directional

This project is based on the Directional library by Amir Vaxman and others. If you use this library in your research, please cite the original work:

```bibtex
@misc{Directional,
author       = {Amir Vaxman and others},
title        = {Directional: A library for Directional Field Synthesis, Design, and Processing},
doi          = {10.5281/zenodo.3338174},
url          = {https://doi.org/10.5281/zenodo.3338174}
}
```
