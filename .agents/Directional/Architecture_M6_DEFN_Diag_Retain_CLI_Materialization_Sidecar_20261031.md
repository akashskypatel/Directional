# RA-186 — DIAG-RETAIN: CLI materialization sidecar (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING` (DEFN, Review track), run locally. It wires the CB59 dump ([RA-185](Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md)) into the CLI and splits the GUI layers into their own DEFN.
- **Method:** probes are diagnostic only. Source is CB59 `39a77d2e…`, unchanged in `src/`, `include/`, `tests/`, `CMakeLists.txt` and `cmake/` at HEAD. The probe is a CLI-ON reconfigure of the probe build tree (CB59 source plus the CB60 patch). The Review agent designed, probed and ruled.

## RA-186.1 Findings

- **The CLI throws before writing any diagnostics when the result is not produced** (`src/cli/RemeshCommand.cpp`, the `!result.is_produced()` check before `write_remeshed_mesh`). A rejected SurfaceCells run is exactly where the retained A5–A7 products matter.
- **DR4 (pre-existing, new).** `--diagnostics-prefix` fails on every SurfaceCells product: `write_remesh_diagnostics` writes `.degrees.dmat`, then calls `write_triangle_obj`/`write_triangle_off` on the product's cut mesh (`src/cli/RemeshOutput.cpp:388–392`), and a SurfaceCells product has none, so it throws `Triangle OBJ output faces must have shape (#F, 3).` The output mesh is already written. Probe run B below shows it without the CB60 dump.
- **GUI.** A GUI-ON build compiles polyscope, ImGui and GLFW, which no local tree has yet. The GUI layers get their own DEFN with that build as its first probe.

## RA-186.2 Rulings

- **CB60: the CLI sidecar.** After the remesh call and **before** the produced-result check, when `--diagnostics-prefix <p>` is given and any of the three snapshots is present, the CLI writes `<p>.materialization.txt` with `write_materialization_diagnostics`. The snapshots are present only under `--surface-cell-preserve-debug-artifacts`, which already sets retention. The usage text gains two lines. Nothing else changes; the pipeline and its result are untouched.
- **GUI layers → `M6-DEFN-DIAG-RETAIN-GUI-LAYERS`** (DEFN, R): optional layers over `materialization_diagnostics_display` (occurrence points coloured by class, cell sides, relations, A7 quads), probed in a GUI-ON build.
- **DR4: carried, owner M8-CP2** (CLI hardening): skip or adapt the cut-mesh sidecars for SurfaceCells products. It is independent of DIAG-RETAIN; the materialization sidecar is written before it fails.

## RA-186.3 Probe evidence

CLI-ON probe binary from CB59 source plus the CB60 patch, default arithmetic. Fixture `benchmarks/fixtures/milestone-g/plane.{obj,rawfield}`; common options `--raw-field <plane.rawfield> --remesh-backend SurfaceCells --surface-cell-fallback Fail --length-ratio 0.2`.

| Run | Extra options | Exit | Files after the run |
|---|---|---|---|
| A | `--surface-cell-preserve-debug-artifacts --diagnostics-prefix <d>/plane` | 1 (DR4 message) | `out.obj`, `plane.degrees.dmat`, **`plane.materialization.txt`** |
| B | `--diagnostics-prefix <d>/plane` | 1 (DR4 message) | `out.obj`, `plane.degrees.dmat`; no materialization file |
| C | `--surface-cell-preserve-debug-artifacts` | 0 | `out.obj` only |

- **Run A's dump** has 645 lines, with headers `A5 occurrence-complex cells=64 occurrences=256 relations=224`, `A6 quotient-product classes=81 classed-cells=64` and `A7 source-attached-geometry vertices=81 cells=64`, followed by 256 `occurrence`, 224 `relation`, 81 `class` and 81 `vertex` lines (a 9×9 vertex grid of 64 quads).
- Run B shows that DR4 predates CB60 and that no dump is written without retention. Run C shows the sidecar needs the prefix.
- The new lines stay within the file's existing line-length profile, and the CB59 gate binaries are untouched (CB60 changes only `src/cli/`, which none of the eight gate targets compile).

## RA-186.4 CB60 — exact patch

**Turn:** `M6-CB60-DIAG-RETAIN-CLI-SIDECAR` (CB), run locally; Code + Build.
- **Scope:** `src/cli/RemeshCommand.cpp` `12 0`; `src/cli/Usage.cpp` `2 0`.
- **Checks:**
  - The RA-186.7 block, extracted verbatim with a trailing newline, has SHA-256 `d14aaeff98b662c70e49f0a64f3dfad4df355e97320301a6341d4d7ad2e2a784`.
  - `git apply --check`, then apply; the numstat must be exactly as above.
  - The resulting SHA-256 must be `418fbf8b055c1b88c3c6898b4e1921a0628e7f1e3d6a7208e0a44bb2d63a0e47` (`RemeshCommand.cpp`) and `91817875227bfa81f05a1b9bf1549a97ad6ec0f15550f60e4851f8a7df3cd86b` (`Usage.cpp`).
- **Build:** a fresh configure of a clean worktree with the CI flags **plus `-DDIRECTIONAL_BUILD_CLI=ON`**, building only `directional_cli` (executable `directional`). Stage `build/local-evidence/CB60/` with `bin/directional`, the standard metadata (`compiled-targets.txt` = `directional_cli`), `SHA256SUMS` and `pkg.zip`. No native runs.

| CB60 result | Successor |
|---|---|
| All exact, CLI built | `M6-TB59-DIAG-RETAIN-CLI-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-CLI-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB60A-DIAG-RETAIN-CLI-ORCH`, then one retry |

## RA-186.5 TB59 frozen check run

`M6-TB59-DIAG-RETAIN-CLI-EXEC` (TB-EXEC, local) runs the staged `bin/directional` three times, each in its own new output directory, with the RA-186.3 options.

| TB59 result | Successor |
|---|---|
| A, B and C exactly as in the RA-186.3 table, and run A's dump has exactly those three header lines and 256/224/81/81 element lines | `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` (no separate REV) |
| Anything else | `M6-TB59-DIAG-RETAIN-CLI-REV` (R) |

The five-binary gate is not re-run: no gate binary changes (TB58 862/863 stands).

## RA-186.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CB60-DIAG-RETAIN-CLI-SIDECAR` → `M6-TB59-DIAG-RETAIN-CLI-EXEC` | CB, TB-EXEC / local | runs A–C as registered |
| then | `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` (GUI-ON build probe first) | DEFN / R | frozen GUI CB |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | DR1, DR3 (RA-184.4); DR2, DR4 → M8-CP2; O2b, O15b, O15c, O16; Linux CI confirmation of rows 854–859 | — | — |

## RA-186.7 Exact CB60 patch

~~~diff
diff --git a/src/cli/RemeshCommand.cpp b/src/cli/RemeshCommand.cpp
index e87e6760c..b94e17bc6 100644
--- a/src/cli/RemeshCommand.cpp
+++ b/src/cli/RemeshCommand.cpp
@@ -9,6 +9,7 @@
 
 #include <cmath>
 #include <filesystem>
+#include <fstream>
 #include <iostream>
 #include <optional>
 #include <stdexcept>
@@ -16,6 +17,7 @@
 
 #include <directional/fields/RegularizedCurvatureCrossField.h>
 #include <directional/pipeline/RemeshPipeline.h>
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
 
 namespace directional::cli {
 namespace {
@@ -404,6 +406,16 @@ int run_remesh(const int argc, char **argv) {
     result = pipeline::remesh_from_mesh(mesh.vertices, mesh.faces, options);
   }
 
+  // A rejected SurfaceCells run is where the retained A5-A7 products matter
+  // most, so their dump is written before the produced-result check.
+  const auto &snapshots = result.surfaceCellContext.productSnapshots;
+  if (diagnosticsPrefix.has_value() &&
+      (snapshots.occurrenceComplex || snapshots.quotientProduct ||
+       snapshots.sourceAttachedGeometry)) {
+    std::ofstream dump(diagnosticsPrefix->string() + ".materialization.txt");
+    visualization::write_materialization_diagnostics(dump, snapshots);
+  }
+
   if (!result.is_produced()) {
     throw std::runtime_error(
         "Remeshing failed while simplifying or assembling the output mesh"
diff --git a/src/cli/Usage.cpp b/src/cli/Usage.cpp
index 873e80c4b..b3c7e3706 100644
--- a/src/cli/Usage.cpp
+++ b/src/cli/Usage.cpp
@@ -120,6 +120,8 @@ void print_usage(std::ostream &stream) {
       << "  --curvature-sharp-angle <degrees>\n"
       << "  --smooth-curvature-across-features\n"
       << "  --diagnostics-prefix <p>        Write pipeline result arrays as sidecars.\n"
+      << "                                  With --surface-cell-preserve-debug-artifacts, also\n"
+      << "                                  writes retained A5-A7 products to <p>.materialization.txt.\n"
       << "  --verbose                       Print pipeline timing details.\n";
 }
 
~~~
