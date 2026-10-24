# Interim tooling turn — A2a field-aligned network in the GUI (2026-10-21)

**Turn:** `M6-TOOL-VIS-FIELD-NETWORK-GUI-LAYER` (interim, user-directed; between CB24-REV and TB25). **Commit:** `bf518b003`.

**Scope:** display only. The adapter reads the retained A2a snapshot; no pipeline stage reads its output. All RP-01 sources are byte-identical to CB24's semantic source `dae267a82` (`src/pipeline`, `src/geometry`, `src/authority`, their headers and TQ). TB25 runs on the immutable CB24 package and is unaffected.

## What was added

- `include/directional/visualization/FieldAlignedNetworkPolylines.h` and `src/visualization/FieldAlignedNetworkPolylines.cpp` (in `directional_pipeline`). They build polylines from the published network:
  - each trace starts at its source vertex, then visits its segment entry points and edge-transit exits;
  - it ends at its published terminal: barrier point, singularity vertex, contact or limit-cycle entry;
  - mandatory edges and singularities (with index numerator) are separate layers.

  It fails closed on vertices missing from `V`, on edge parameters or barycentrics outside [0, 1], and on a terminal singularity with no port.
- **GUI (`directional-ui`):** a new section, **"6. Field-aligned curve network"**.
  - It uses the calculated or uploaded raw field, runs SurfaceCells (fallback `Fail`, intermediate geometry retained) and overlays three polyscope layers in the input mesh's transform: `A2a field-aligned traces` (colored per trace and by terminal kind), `A2a mandatory edges` and `A2a singularities`.
  - A later SurfaceCells rejection is shown as a status line, not an error.
- **Tests (`directional_compiled_api_tests`):** `FieldAlignedNetworkPolylines.ProducedTracesFollowTheInputField` and `.RejectsVerticesThatDoNotCoverTheNetwork`.

## Local evidence (macOS arm64, Release, GMP, out-of-tree build)

- `directional-ui` and `directional_compiled_api_tests` build with no warnings from new code. 2/2 tests pass. On `sphere_prescribed`: 24 traces, 184 segments, 160 segments parallel to an input direction (cos > 0.99), 8 singularities, adapter points equal the independent reconstruction.
- **Mutation:** flipping the edge parameter in the adapter fails the test.
- **Renders (polyscope screenshots):**
  - sphere: 24 traces and 8 singularity markers, aligned with the mesh;
  - `genus_two`: 72 mandatory edges, 0 traces (no singularities);
  - torus: 48 mandatory edges, 0 traces.
- **Not yet compiled in CI;** the next CB compile includes the new test file. CI builds with `DIRECTIONAL_BUILD_GUI=OFF`.
- **Local configure note:** CMake 4.3 needed `-DCMAKE_PROJECT_Directional_INCLUDE=<file containing enable_language(OBJCXX)>` for the macOS file dialog; the repository CMake is unchanged.

**Successor:** the canonical sequence resumes at `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST`.
