# Source layout

The C++ code is grouped by responsibility. Public headers use canonical module
paths under `include/directional`; the former flat include paths remain as
forwarding headers for source compatibility.

| Module | Responsibility |
|---|---|
| `core/` | Mesh, tangent-bundle, Cartesian-field, and DCEL data structures |
| `fields/` | Field construction, conversion, matching, combing, and optimization |
| `geometry/` | Topology, curvature, subdivisions, isolines, and streamlines |
| `operators/` | Discrete differential, mass, curl, divergence, and cochain operators |
| `integration/` | Seamless integer-grid integration setup and solve |
| `meshing/` | N-function extraction and output mesh generation |
| `numerics/` | Exact arithmetic and exact geometric predicates |
| `pipeline/` | High-level remeshing entry point |
| `io/` | Mesh, field, matching, and singularity serialization |
| `util/` | Eigen, sparse-matrix, graph, and ordering helpers |
| `visualization/` | Optional Polyscope-based viewer support |

Implementation files are grouped under `src/core` and `src/cli`. Header-only
implementation details use `.inl` files below the owning module rather than
placing `.cpp` files in the public include root.

## Include migration

New code should include canonical paths:

```cpp
#include <directional/fields/PolyVectorField.h>
#include <directional/geometry/Streamlines.h>
#include <directional/io/ReadOBJ.h>
#include <directional/operators/GradientMatrices.h>
```

Existing includes such as `<directional/polyvector_field.h>` remain valid and
forward to the canonical header. They should be treated as compatibility paths,
not as locations for new implementation code.

## Dependency direction

The intended dependency direction is:

```text
util/numerics -> core -> geometry/operators/fields -> integration/meshing -> pipeline
```

`io` may depend on public data types. `visualization` is optional and may depend
on the other public modules, but production algorithms must not depend on it.
