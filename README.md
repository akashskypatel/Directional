# DirectionalReMesher

DirectionalReMesher is a spin-off ReMesher pipeline from [Directional](https://github.com/avaxman/Directional), which is a directional-field processing library that provides a standalone C++ drop-in interface library. 

DirectionalReMesher is a C++ implementation of the ReMesher algorithm from the paper ["Directional Field Synthesis, Design, and Processing" by A. Vaxman et al](https://cims.nyu.edu/gcl/papers/DirectionalFieldsSTAR-2016.pdf). It provides a practical implementation of the cross-field aligned quad remeshing with major improvements for robustness and performance compared to the original implementation. 

This fork supports two build workflows:

- pure CMake for native C++ consumers
- Python packaging builds via `setup.py` and `pip`

Optionally, you can include this library in your source by simply cloning this repository as a submodule or copying the source files directly into your project and including the headers in your source code.

## What This Repository Builds

The top-level build supports two modes:

1. `directional` standalone shared library
2. Python package / wheel exposing the headless remeshing API
3. Native CLI executable

Key build toggles:

- `BUILD_PYTHON=ON|OFF`
- `BUILD_SHARED_LIBS=ON|OFF`
- `DIRECTIONAL_ENABLE_GMP=ON|OFF`
- `DIRECTIONAL_ENABLE_SUITESPARSE=ON|OFF`

## Prerequisites

### Native build prerequisites

- CMake 3.15+
- A C++20-capable compiler
- Python is only required if you are building the Python bindings or using `setup.py`

### Dependencies

- **GMP**: optional, for exact arithmetic, otherwise uses built-in (less performant) exact arithmetic. If MSVC toolchain is detected, GMP will be automatically downloaded and built if enabled. MinGW, Linux and macOS users need to install GMP manually.
- **SuiteSparse**: optional, for sparse solvers, otherwise uses Eigen. If MSVC toolchain is detected, SuiteSparse will be automatically downloaded and built if enabled. MinGW, Linux and macOS users need to install SuiteSparse manually.
- **Eigen**: required, included as submodule

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

Common flags for all CMake examples:

```powershell
-DDIRECTIONAL_ENABLE_GMP=ON|OFF
-DDIRECTIONAL_BUILD_CLI=ON|OFF
-DDIRECTIONAL_ENABLE_SUITESPARSE=ON|OFF
```

Examples:

- GMP enabled: `-DDIRECTIONAL_ENABLE_GMP=ON`
- non-GMP build: `-DDIRECTIONAL_ENABLE_GMP=OFF`
- SuiteSparse enabled: `-DDIRECTIONAL_ENABLE_SUITESPARSE=ON`
- non-SuiteSparse build: `-DDIRECTIONAL_ENABLE_SUITESPARSE=OFF`

### 1. Build and install the standalone library

This is the native C++ path if you want a reusable installed package.

```powershell
cmake -S . -B build\standalone `
  -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_INSTALL_PREFIX=%CD%\build\standalone\install `
  -DBUILD_PYTHON=OFF `
  -DDIRECTIONAL_ENABLE_GMP=ON `
  -DDIRECTIONAL_ENABLE_SUITESPARSE=ON

cmake --build build\standalone --config Release --target directional
cmake --install build\standalone --config Release
```

Artifacts:

- shared library under `build\standalone\Release\` during build
- installed library under `build\standalone\install\bin` and `build\standalone\install\lib`
- installed headers under `build\standalone\install\include`
- CMake package files under `build\standalone\install\lib\cmake\Directional`

### Optional native CLI executable

The native executable is intentionally opt-in so it does not collide with the Python `directional` console script. Enable it with `DIRECTIONAL_BUILD_CLI=ON`:

```powershell
cmake -S . -B build/native-cli -DDIRECTIONAL_BUILD_CLI=ON -DBUILD_PYTHON=OFF -DCMAKE_INSTALL_PREFIX=build/native-cli-release

cmake --build build/native-cli --target directional_cli --config Release

cmake --install build/native-cli
```

The installed native command is:

```powershell
directional info
directional --help
```

`setup.py standalone` can also build it:

```powershell
python setup.py standalone --build-cli
```

### 2. Consume the installed library from another CMake project

```cmake
find_package(Directional CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE Directional::directional)
```

If Directional is installed in a nonstandard location, point CMake at it:

```powershell
cmake -S . -B build -DCMAKE_PREFIX_PATH=D:\path\to\Directional\build\standalone\install
```

### 3. Build the Python extension with pure CMake

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
  -DBUILD_PYTHON=ON `
  -Dpybind11_DIR="C:\path\reported\by\pybind11\cmakedir" `
  -DDIRECTIONAL_ENABLE_GMP=ON `
  -DDIRECTIONAL_ENABLE_SUITESPARSE=ON

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

- `--enable-gmp`
- `--disable-gmp`

Supported SuiteSparse flags:

- `--enable-suitesparse`
- `--disable-suitesparse`

### 1. Build the standalone shared library

```powershell
python setup.py standalone
```

Default output locations:

- build tree: `build\standalone\`
- install tree: `build\standalone\install\`

Examples:

```powershell
python setup.py standalone --enable-gmp
python setup.py standalone --disable-gmp
python setup.py standalone --enable-suitesparse
python setup.py standalone --disable-suitesparse
```

### 2. Build a Python wheel

```powershell
python setup.py bdist_wheel
```

`bdist_wheel` goes through `build_ext`, so GMP flags must be passed to `build_ext` in the same invocation:

```powershell
python setup.py build_ext --disable-gmp bdist_wheel
python setup.py build_ext --enable-gmp bdist_wheel
```

Wheel output:

- `dist\directional-<version>-<python>-<abi>-<platform>.whl`

Example verified in this repo:

- `dist\directional-0.1.0-cp313-cp313-win_amd64.whl`

### 3. Install the built wheel

```powershell
python -m pip install dist\directional-0.1.0-cp313-cp313-win_amd64.whl
```

Or reinstall during local iteration:

```powershell
python -m pip install --force-reinstall dist\directional-0.1.0-cp313-cp313-win_amd64.whl
```

## Python `pip` Build

`pip` and other PEP 517 frontends can control the same GMP and SuiteSparse toggles through `--config-settings`.

Supported keys:

- `-Cenable-gmp=1|0`
- `-Cenable-suitesparse=1|0`

### Basic pip install

```powershell
python -m pip install .
```

### Custom Installation Examples

```powershell
python -m pip install . --no-build-isolation -Cenable-gmp=1 -Cenable-suitesparse=1
python -m pip install . --no-build-isolation -Cenable-gmp=0 -Cenable-suitesparse=0
python -m pip wheel . --no-deps --no-build-isolation -Cenable-gmp=0 -Cenable-suitesparse=0
```

Namespaced aliases are also accepted if you prefer explicit keys:

```powershell
python -m pip install . --no-build-isolation -Cdirectional.enable-gmp=0 -Cdirectional.enable-suitesparse=0
```

Environment-variable fallback also works:

```powershell
$env:DIRECTIONAL_DIRECTIONAL_ENABLE_GMP = "0"
python -m pip install . --no-build-isolation
```

## Command Line Interface

Installing the Python package also installs a `directional` command. The same entry point is available with `python -m directional`.

Show package and native extension status:

```powershell
directional info
python -m directional info
```

Run the headless remeshing pipeline from a compressed NumPy input file:

```powershell
directional remesh input.npz output.npz --length-ratio 0.02 --verbose
```

The input `.npz` file must contain:

- `vertices`: `#V x 3` float array
- `faces`: `#F x 3` integer array
- either `raw_cross_field`: `#F x 12` float array, or `primary_directions`: `#F x 3` float array
- optional `secondary_directions`: `#F x 3` float array when using explicit primary and secondary directions

The output `.npz` file contains `success`, `vertices`, `faces`, `degrees`, and any cut-mesh arrays exposed by the native result object.

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
python setup.py build_ext --disable-gmp bdist_wheel
python -m pip wheel . --no-deps --no-build-isolation -Cenable-gmp=0 -Cauto-install-gmp=0
```

And for pure CMake:

```powershell
cmake -S . -B build\standalone -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=%CD%\build\standalone\install -DBUILD_PYTHON=OFF
cmake --build build\standalone --config Release --target directional
cmake --install build\standalone --config Release
```
## Tests

Install test dependencies and run the lightweight unit suite with:

```powershell
python -m pip install -e .[test] --no-build-isolation
python -m pytest
```

The included tests cover the Python CLI's error handling and `.npz` output behavior with a fake native backend, plus the optional native CLI CMake/source wiring. They do not require building the native extension.

## Tutorials

To build tutorials with pure cmake, run the following command:

To build only specific tutorials, pass DIRECTIONAL_TUTORIALS as a semicolon-separated or comma-separated list of tutorial prefixes or full directory names. Not providing this option will build all tutorials: `-DDDIRECTIONAL_TUTORIALS="501"|"501,502"|"203_Combing"`

```powershell
cmake -S . -B build\tutorials -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=%CD%\build\tutorials\install -DBUILD_PYTHON=OFF -DBUILD_TUTORIALS=ON
cmake --build build\tutorials --config Release --target directional_tutorials
cmake --install build\tutorials --config Release
```

To build tutorials with setup.py, run the following command:

To build only specific tutorials, pass DIRECTIONAL_TUTORIALS as a semicolon-separated or comma-separated list of tutorial prefixes or full directory names. Not providing this option will build all tutorials: `--tutorial="501"|"501,502"|"203_Combing"`

```powershell
python setup.py tutorials
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
