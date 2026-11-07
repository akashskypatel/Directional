# RA-182 — Row 935 display witness: a legitimate source-vertex stop (2026-10-31)

**Turn:** `M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS` (DEFN, Review track), run locally. **Authority:** [RA-180.4](Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md) and [RA-181](Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md). Probes are diagnostic only. Source is CB55 `04027167…`, unchanged in `src/`, `include/` and `tests/` at HEAD. A Sonnet subagent traced the locus paths (read-only); the Review agent ran the probes and verified them.

## RA-182.1 Which stages can report a source-vertex stop

- **Only these producers set `terminalFailureLocus`,** through `fail_surface_cells` (`src/pipeline/RemeshPipeline.cpp:12397–12420`):
  - the A3 atlas (`atlas_failure_locus`, `:12853–12874`);
  - the field-aligned network (`:149–197`);
  - the surface cut graph (`:390–457`);
  - the global topology plan (`:559–681`).
- **No locus is set** by input conditioning, cross-field validation or the A2 source-authority failure.
- **The cleanest vertex stop is A3 `InvalidSingularityMetadata`** (`src/authority/FieldTransportAtlas.cpp:573–579`). It fires when `4 − indexNumerator ∉ [3, 6]`; the accepted numerators are −2 to +1, i.e. singularity valences 3 to 6.
  - The numerator comes from the raw field's cycle indices (`RemeshPipeline.cpp:3051–3056`).
  - An open disk passes the earlier region checks, because the boundary absorbs the index correction (`FieldTransportAtlas.cpp:2726–2735`).
  - **A +½ singularity (numerator 2, valence 2) cannot be quad-meshed under the A3 port contract.** This is a legitimate design rejection at that vertex.

## RA-182.2 Probe evidence (bounded; one process per candidate, 120 s limit)

Each candidate is a flat fan of `ring` triangles around vertex 0, with the cross turned by m·φ around it. The pipeline is `remesh_from_raw_cross_field` with the display test's options.

| ring | m | Terminal stop | Locus vertex | Shown by display |
|---|---|---|---|---|
| 8 | ½ | `field-transport-atlas` / `InvalidFieldTransportAtlas` / `InvalidSingularityMetadata` | 0 | yes |
| 12 | ½ | same | 0 | yes |
| 8 | ¾ | same | 0 | yes |
| 8 | −½ | `SingularityPortClassCountMismatch` at vertex 0 | 0 | — |
| 8 | 1 | `completion`, no locus | — | — |
| 8 | 0 | timed out (>120 s) | — | — |

- **Choice: ring 8, m = ½.** The per-edge turn is 22.5°, far from the ±45° matching tie, so the stop does not depend on rounding or libm.
- **With the CB56 change:**
  - `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported` passes, together with the other two display tests.
  - The whole API binary passes 23/23 on both the default and the FMA-free CB55 builds.
  - The genus_two and sphere_prescribed sections are unchanged and still pass.

## RA-182.3 Disposition of row 935

Row 935 is **repaired (FIXTURE → gate).** The test's vertex section now uses a stage-reachable vertex stop on a constructed input. It asserts the locus vertex (0), the A3 detail `InvalidSingularityMetadata` and the display's vertex marker. The assertions are stronger than before (vertex and detail are pinned), and no diagnostics are fabricated.

## RA-182.4 CB56 — exact patch

**Turn:** `M6-CP3-CB56-API-DISPLAY-VERTEX-STOP-WITNESS` (CB), run locally; Code + Build, compile-only.
- **Scope:** `tests/SurfaceCellTracingDisplayTests.cpp` only: add the `run_half_index_singularity_fan()` helper (plus the `<cmath>` and `<numbers>` includes), replace the vertex section, and update the final loop variable.
- **Checks:**
  - The RA-182.7 block, extracted verbatim with a trailing newline, has SHA-256 `ffb723f4f664a6517d18620aa7de42a9ecda081e5941f00f04993fbbe0121224`.
  - `git apply --check`, then apply; the numstat must be exactly `46 8`.
  - The resulting file SHA-256 must be `f32540153871bd6d6c2f453f5e3784f9f392ab4fdafcb274f496f3a3ee199974`.
  - Build the eight targets with the CI flags at default arithmetic, and stage the package as for CB55. No native tests.

| CB56 result | Successor |
|---|---|
| All exact, package built | `M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC` |
| Mismatch | `M6-CP3-PLAN-API-DISPLAY-WITNESS-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CP3-CB56A-API-DISPLAY-ORCH`, then one retry |

## RA-182.5 TB55 frozen inputs

- **Gate:** [`Architecture_M6_CP3_TB55_API_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB55_API_Display_Full_Gate_Case_Manifest.tsv), 858 rows, SHA-256 `eb508378644093ac98cb8fcb3351af12e66b49ad284d68714c22710c0d4f892c`. The first 858 lines are TB54 (`53683907…`); row 858 is `GUARD apicensus:19` (API binary).
- **Ledger v4:** [`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv`](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv), 82 rows, SHA-256 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`. It is v3 minus census row 935. Classes: FIXTURE 47 / PRODUCT 7 / OPEN 23 / RETIRE 5.
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=858 deferred=82`. The real membership check of the patched binaries' listings gives **940**.

| TB55 result (local, default arithmetic) | Successor |
|---|---|
| 857/858 PASS, with row 283 (O2) the only RED, postflight true, membership 940 | Next definition turn (RA-182.6); no separate REV turn (RA-164 lean rule: a pre-registered green) |
| Any other non-PASS | `M6-CP3-TB55-API-DISPLAY-FULL-GATE-REV` (TB-REV, R) |
| Membership error | `M6-CP3-PLAN-API-DISPLAY-MEMBERSHIP-STOP` (PLAN, R) |

## RA-182.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| done | DEFN-API-DISPLAY-VERTEX-STOP-WITNESS (RA-182) | DEFN / R | CB56 frozen |
| NEXT | `M6-CP3-CB56-API-DISPLAY-VERTEX-STOP-WITNESS` → `M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC` | CB, TB-EXEC / local | 857/858, with only 283 red; ledger v4, 82 |
| then | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (legacy no-atlas ingress, O4, row 283) | DEFN / R | O2 ruling and slices |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | Linux CI confirmation (rows 854–858) | TB-EXEC / I | RP-01 and O15 falsifiers |

## RA-182.7 Exact CB56 patch

~~~diff
diff --git a/tests/SurfaceCellTracingDisplayTests.cpp b/tests/SurfaceCellTracingDisplayTests.cpp
index 8ae628003..9009edb71 100644
--- a/tests/SurfaceCellTracingDisplayTests.cpp
+++ b/tests/SurfaceCellTracingDisplayTests.cpp
@@ -9,7 +9,9 @@
 
 #include <algorithm>
 #include <array>
+#include <cmath>
 #include <fstream>
+#include <numbers>
 #include <stdexcept>
 #include <string>
 
@@ -54,6 +56,38 @@ FixtureRun run_fixture(const std::string &name) {
   return run;
 }
 
+// An eight-triangle fan whose cross turns by half a turn around vertex 0: a
+// +1/2 singularity, outside the index range that A3 singularity ports cover.
+FixtureRun run_half_index_singularity_fan() {
+  constexpr int ring = 8;
+  FixtureRun run;
+  Eigen::MatrixXd vertices(ring + 1, 3);
+  vertices.row(0) << 0.0, 0.0, 0.0;
+  for (int i = 0; i < ring; ++i) {
+    const double angle = 2.0 * std::numbers::pi * i / ring;
+    vertices.row(i + 1) << std::cos(angle), std::sin(angle), 0.0;
+  }
+  Eigen::MatrixXi faces(ring, 3);
+  for (int i = 0; i < ring; ++i) faces.row(i) << 0, 1 + i, 1 + (i + 1) % ring;
+  run.mesh.set_mesh(vertices, faces);
+  Eigen::MatrixXd raw(ring, 12);
+  for (int face = 0; face < ring; ++face) {
+    const Eigen::RowVector3d center =
+        (vertices.row(faces(face, 0)) + vertices.row(faces(face, 1)) +
+         vertices.row(faces(face, 2))) / 3.0;
+    const double turn = 0.5 * std::atan2(center[1], center[0]);
+    for (int branch = 0; branch < 4; ++branch) {
+      const double angle = turn + branch * std::numbers::pi / 2.0;
+      raw(face, 3 * branch) = std::cos(angle);
+      raw(face, 3 * branch + 1) = std::sin(angle);
+      raw(face, 3 * branch + 2) = 0.0;
+    }
+  }
+  run.result = directional::pipeline::remesh_from_raw_cross_field(
+      run.mesh.V, run.mesh.F, raw, surface_cell_options(-1));
+  return run;
+}
+
 directional::visualization::SurfaceCellTracingDisplay display_of(const FixtureRun &run) {
   const auto &context = run.result.surfaceCellContext;
   return directional::visualization::surface_cell_tracing_display(
@@ -101,14 +135,18 @@ TEST(SurfaceCellTracingDisplay, StopLocationShowsWhatEachStageReported) {
                             return note.find(reason) != std::string::npos;
                           }));
 
-  // The field-transport atlas rejects mechanical_feature at a vertex.
-  const FixtureRun mechanical = run_fixture("mechanical_feature");
-  const auto &vertexLocus = mechanical.result.diagnostics.terminalFailureLocus;
+  // The field-transport atlas rejects a +1/2 singularity at its source vertex.
+  // (mechanical_feature passes the atlas once A3 decides exact ties exactly.)
+  const FixtureRun singular = run_half_index_singularity_fan();
+  const auto &vertexLocus = singular.result.diagnostics.terminalFailureLocus;
   ASSERT_TRUE(vertexLocus.sourceVertex.has_value())
-      << mechanical.result.diagnostics.terminalFailureStage;
-  const auto mechanicalDisplay = display_of(mechanical);
-  EXPECT_TRUE(has_vertex(mechanicalDisplay,
-                         mechanical.mesh.V.row(static_cast<Eigen::Index>(
+      << singular.result.diagnostics.terminalFailureStage;
+  EXPECT_EQ(0U, *vertexLocus.sourceVertex);
+  EXPECT_EQ("InvalidSingularityMetadata",
+            singular.result.diagnostics.terminalFailureDetailCode);
+  const auto singularDisplay = display_of(singular);
+  EXPECT_TRUE(has_vertex(singularDisplay,
+                         singular.mesh.V.row(static_cast<Eigen::Index>(
                              *vertexLocus.sourceVertex))));
 
   // The cut graph rejects sphere_prescribed at a face given by its corners.
@@ -129,7 +167,7 @@ TEST(SurfaceCellTracingDisplay, StopLocationShowsWhatEachStageReported) {
   ASSERT_GE(row, 0);
   const auto sphereDisplay = display_of(sphere);
   EXPECT_TRUE(has_face(sphereDisplay, sphere.mesh.V, sphere.mesh.F, row));
-  for (const auto *display : {&genusDisplay, &mechanicalDisplay, &sphereDisplay}) {
+  for (const auto *display : {&genusDisplay, &singularDisplay, &sphereDisplay}) {
     EXPECT_TRUE(display->has_stop_location());
     EXPECT_EQ(0U, display->cellCount);
   }
~~~
