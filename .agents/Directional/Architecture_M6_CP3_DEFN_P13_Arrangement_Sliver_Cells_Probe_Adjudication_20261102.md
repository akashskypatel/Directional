# RA-198 — P13-h2 needle grids and P13-i rail lenses: probe adjudication; exact CB77, TB71; selection DEFN (2026-11-02)

**Turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (Review/Definition). ChatGPT started it at 2026-11-02T05:14:30Z and set `STATUS` to BLOCKED at 15:07Z. Its [review WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Review_WIP_20261102.md"), about 100 commits long, says it lacks the original trace states, the FlowRep selection decisions and needle completion evidence, and that Review policy forbids runtime probes.

That block is procedural. RA-197.3 and handoff step 20 put this DEFN on the Review track as a **probe DEFN on the scratch build**: the evidence is a probe to run, not an artifact to find. `REVIEW_TURN_POLICY.md` §4.3 keeps a Review free of product, test, fixture and selector changes in the repository. Scratch diagnostic probes leave all of those untouched, and they have been the Review track's evidence since RA-188 (GMP_COMPILE_POLICY: diagnostic only, never gate authority). Resumed here at 15:54:02Z on the RA-197 scratch build.

Source at review: HEAD `1c7642c32`. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72` (TB70 package `13115678045`, 880/880). The scratch tree `wt61`/`bld61` equals that source (verified file by file) before the probes were added.

## RA-198.1 Findings

1. **F1 — the four needle grids complete under the existing boundary search (P13-h2 owner: completion).**
   - Cells 6095, 20533, 20968 and 22350 (2×2, 2×2, 3×2, 2×4) fail only because the closed-form grid places generated vertices from the four corners. A bent needle puts the bilinear point outside the cell, and its projection folds a quad (RA-197 F6).
   - The Amendment 28 pattern search over the **same boundary** finds an embedded quadrangulation for all four. Vase then stops at P13-i (probe B: `IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;…;failed=5;total=26826`), exactly RA-197's mode-4 data point.
   - The dispatch keeps a grid whenever `complete_rectangular_grid` returns true, so the pattern backend never sees these boundaries; only the final validator does.
   - DESIGN §4.11 treats thinness as a quality objective, not a validity criterion. A needle cell is a valid cell, so completion must complete it when its boundary has an embedded quadrangulation. Needle quality stays O23 (M7).
2. **F2 — the grid gives way only when the search succeeds, and only for grids with generated vertices.**
   - A first probe discarded every grid that failed the embedding predicate and let the dispatch fall through (probe H2). That turned three gate rows red:
     - 144 and 570: a `completed_cylinder_patches` 1×1 patch fails the check before ownership validation, although the final validator accepts it;
     - 875: its reversed plane grid would end in `NoEmbeddedQuadrangulation` instead of the registered `InvalidCompletionQuadEmbedding`.
   - The frozen rule (CB77) replaces the grid only when the pattern search succeeds; otherwise the grid stands and the validator reports its failure exactly as before. That alone keeps all three rows green (mutant M2).
   - CB77 also limits the rule to grids that generated vertices. 1×1 cells and strips have none, and RA-197 ruled that their failures must stay visible (no strip search: a failing ladder signals a registration or boundary defect). After CB76, no Vase strip fails. No current fixture distinguishes this scope (M2 survives); it narrows the change and adds no behaviour.
3. **F3 — the five lenses are optional rim-seed support traces.** `build_flow_rep_arcs_from_network` retains a boundary or feature seed's branch as optional layout support.
   - Traces 1037, 878, 20, 422 and 612 bound cells 26735, 26764, 26781, 26802 and 26812. Each comes from a vertex-backed seed on boundary rail 0, has 3 segments and 0.031–0.048 length, and terminates `Boundary` on the same rail.
   - They leave the rim at 0.6°, 0.2°, 3.3°, 11.1° and 1.7°, the smaller tip angle of each lens, and return at the larger one (RA-197 F7). Nothing crosses them, so each cell has two corners.
4. **F4 — no rail-tangent rule separates them.** The cross field is not aligned with Vase's rim.
   - The 115 retained rim support traces leave the rail at angles spread from 0.1° to 88° (72 below 45.6°, the tracer's hard-rail compatibility bound).
   - Dropping every branch within that bound (probe D/E) removes 72 connectors and changes the arrangement to 24,001 cells. It is not a rule: it discards traces with no defect.
   - The tracer's compatible-rail following applies only to `hardFeatureEdges`. Boundary edges are not in that set (`I_VSEED hard=0` for all 562 rim-seed branches), so the vertex-seed follow asymmetry found in source has no effect here (probe C = probe B).
5. **F5 — the FlowRep selector removes nothing on Vase (P13-i owner: A2a network selection).** DESIGN §7.2 step 7 and invariant 8 make global selection the stage that removes redundant traces. On Vase it accepts **0 of 4,057** attempted flowline removals:
   - 3,942 proposal flowlines fail their own cycle evidence. Every proposal is one required cycle, which is intended.
   - 104 support flowlines fail coverage. `build_coverage_index` only lets an arc cover a sample **in the same source face**, so removing the only arc in any face makes coverage infinite. Four of the five lens traces fail here, though each lies within about 10⁻³ of the rim that is kept.
   - 11 support flowlines pass coverage and fail the endpoint check. `protected_endpoint_degrees` freezes the exact degree at **every** endpoint with degree ≥ 3 and every rail endpoint, so no flowline that touches a junction can ever be removed. Lens trace 878 is one of them.
   - Relaxing only the degree check (protect rail and singularity incidence, forbid a new dangling end; probe G) removes 11 support flowlines including 878. Vase then stops at the other four lenses (`failed=4`).
6. **F6 — P13-i is a class, not five traces.** Dropping exactly the five lens traces (CB77 + `PROBE_P13I_DROP5`) leaves 26,822 cells and three *other* two-sided cells: `IncompleteSurfaceCellComplex;descriptor=25329;cell=26730;reason=side-count-unsupported;…;failed=3;total=26821`.
   - The two-sided cells are rim support traces that bound a cell with the rail. Deleting named traces only exposes the next ones.
   - A selection rule must therefore reach a fixed point over the whole network. What lies past P13-i is not yet observable; the selection DEFN must name it.
7. **F7 — the WIP's leads.**
   - Its source reading stands on several points: proposals are one cycle each, production substitutions are empty, and rail contacts are frozen by the degree rule.
   - It never measured whether selection removes anything, and it kept the needle question on the arrangement side. It also ruled runtime evidence out of the Review track, which RA-197 had placed there.
   - Its needle widths, wedge audit and cyclic side audit are consistent with F1–F5. They do not change the owners.

## RA-198.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB76 before the probes. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. Env switches in scratch copies of `SurfaceCellTracing.cpp`, `FlowRepStrands.cpp` and `PureQuadCompletion.cpp`; unset is HEAD behaviour:
- `PROBE_P13I_DUMP`: per rim-seed branch, its incident hard edges and alignment (`I_VSEED`); per retained support trace, its seed, termination, length and rail alignment (`I_SUP`, `I_ALIGN`); per selector transaction, its kind and both verdicts (`I_TX`).
- `PROBE_P13I_FOLLOW`: a vertex-backed rail seed's branch aligned with an incident hard edge follows that rail.
- `PROBE_P13I_SKIP`: drop rim support branches within 0.7 of the rail tangent.
- `PROBE_P13I_DEG`: protect only rail and singularity incidence and forbid new dangling ends.
- `PROBE_P13I_DROP5`: drop exactly the five lens traces.
- `PROBE_P13H2`: discard every grid that fails the embedding predicate.

| Probe | Result |
|---|---|
| A: dump, HEAD behaviour | Vase RED at patch 6095, `vertices=60917,19077,19081,-1`, 26,827 cells, 143 s: the TB70 locus. 115 retained support traces, all from vertex-backed seeds on rail 0, all `Boundary`; the 5 lens traces have 3 segments each |
| B: grid fall-through (H2) | The 4 needle grids fall through and complete by pattern. Vase RED `IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;…;failed=5;total=26826` |
| C: B + vertex-seed rail following | Identical to B: no rim edge is a hard edge |
| D, E: tangent-branch skip (± H2) | 72 of 115 support traces dropped, 24,001 cells. With H2: completion passes, Vase RED `AssemblyRejected`/`NonManifoldStitchedVertex`. Without: a different needle grid (17601) fails. Not a rule (F4) |
| F: selector census, current rule | 0 of 4,057 removals accepted: proposals 3,904 cycle-only + 38 cycle-and-degree; supports 102 coverage-and-degree + 13 degree-only |
| G: relaxed degree rule | 11 support removals accepted (878 among them); Vase RED `side-count-unsupported`, `failed=4`, 26,709 cells |
| Gate with H2 (unscoped) | 877/880: rows 144, 570, 875 RED besides 283 (F2) |
| CB77 exact source (clean, no probe effect) | Gate (TB71 manifest, 881 rows) **880/881**, only row 283 (O16, macOS LegacyInteger); no shared row changes against RA-197's CB76 gate; row 881 PASS. Vase RED `IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;…;failed=5;total=26826`, 26,827 cells, 0 quads (251 s with the gate running in parallel). Ledger v5 (81 rows) 0/81, as at CB76; no row changes its verdict or first-failure token |
| CB77 + DROP5 | 26,822 cells; Vase RED `side-count-unsupported` at descriptor 25329, cell 26730, `failed=3`: three other two-sided cells (F6) |
| Mutants (each rebuilt; `PatchDescriptorMilestoneE.*` and `PureQuadCompletionPhase18.*`) | Clean CB77: 100 passes plus exactly CB76's 11 off-gate `PatchDescriptorMilestoneE` failures (RA-170 baseline). M1, no replacement (HEAD behaviour): row 881 fails, nothing else changes. M2, scope removed: no change (F2). Restored clean: as above |

## RA-198.3 Rulings

- **DESIGN Amendment 30** (added): a closed-form grid gives way to the boundary search when its generated vertices fold a quad.
  - When a closed-form grid that generated interior vertices fails the Amendment 28 predicate, completion runs the pattern search over the same boundary. It keeps the search's result (backend `Pattern`) if there is one; otherwise the grid stands and the validator reports its failure.
  - 1×1 cells, strips and every typed failure of a boundary without an embedded quadrangulation are unchanged.
- **P13-h2 owner:** the closed-form dispatch in `complete_pure_quad_patch`. CB77 (exact, RA-198.8) fixes it. No interpolant change, no epsilon, no admissibility change.
- **P13-i owner:** A2a network selection (`run_flow_rep_sparse_selection`). It cannot remove an optional trace. Its two blocking predicates are the same-face coverage index and exact degree freezing at every junction (F5). The admissibility rejection of two-sided cells stands. Tracer, support admission, arrangement and completion are not the owner (F3, F4).
- **Next Review DEFN: `M6-CP3-DEFN-P13-FLOWREP-SELECTION`** (probe DEFN on this scratch build, Review track). It must decide:
  - what coverage means across source faces (the index today only sees same-face arcs);
  - which incidences selection must preserve: mandatory rail arcs, singularity ports, and no new dangling end (invariant 3), rather than every junction degree;
  - whether proposal cycles remain one required cycle each.

  It must also measure removals on every census fixture and on the gate and the ledger, name Vase's next failure, and then freeze exact patches.
- **O24** (new, quality, non-blocking): the cross field is not aligned with Vase's boundary rail (F4). Support traces leave the rim at any angle, so boundary cells have arbitrary corner angles. This is §2.1 item 10 quality, owned by M7, unless the selection DEFN finds it blocks a valid layout.
- **Vertex-seed rail following** (source finding, not a defect on any fixture): an edge-backed rail seed follows a compatible hard rail at its first step, while a vertex-backed one does not. No census fixture has hard-rail seeds that reach this path, so it goes to the selection DEFN's notes, not to a CB.
- A TB runs after CB77 alone (TB71). CB77 changes which backend completes some grids, so its gate, ledger and census evidence should not wait for the selection DEFN.

## RA-198.4 CB77 — `M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet f59f92f889fc6fe22d689fd7559c024cd09c6c72 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-198.8 verbatim plus a trailing newline. It has no single-space context lines. SHA-256 `673010d4a76f611bc3f7fbedd40306022ac3fa136ee1acea414a45cb415727db`; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PureQuadCompletion.cpp` | `23 0` | `9eb46a71b4f8af85b7b9ccda703606fe39dd4d7eb61a67d10e00ff5998f45476` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `27 0` | `e6f8b3cc6bcac81b91d7526d184b3e2664184b64fcb839032731c01ac2959cd2` |

- **Content:** in `complete_pure_quad_patch`, a closed-form grid with generated vertices whose quads do not all embed is replaced by `complete_pattern` over the same boundary, when that search finds an embedded quadrangulation.
- **Test (gate row 881):** `PatchDescriptorMilestoneE.BentNeedleGridCompletesByTheBoundarySearch`.
  - Fixture: a 2×2 strip 0.02 thick whose long sides dip by 0.03.
  - The bilinear vertex projects onto side 2, and the grid's last quad turns clockwise (signed area −1.8·10⁻³).
  - Expected: one `Pattern` patch with 3 quads and the 8 boundary vertices.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Precheck, apply, numstat or result-hash mismatch → `M6-CP3-PLAN-P13-NEEDLE-GRID-STOP`.
  - Infrastructure failure → `M6-CP3-CB77A-P13-NEEDLE-GRID-ORCH` (one retry).

## RA-198.5 TB71 — `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB77's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB71_P13_Needle_Grid_Full_Gate_Case_Manifest.tsv"), 881 rows, SHA-256 `f2503dcaf91b13c4a221d52fe7a18899327ab6f96862c3688a67f8f8d14c78a6`. That is TB70's 880 rows byte for byte plus GUARD row 881.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=881 deferred=81`.
  - Pre-registered **881/881**, membership **962**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, with `completion=IncompleteSurfaceCellComplex;…;reason=side-count-unsupported;…`.
  - The registered match is the stage, the detail, the code and the reason. The macOS locus (descriptor 23933, cell 26735, `failed=5`, `total=26826`) is recorded, not registered (RA-176).
  - Mismatches:
    - `InvalidCompletionQuadEmbedding` (a needle grid still fails);
    - any other completion code or reason;
    - `detail=None`, or a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB71A-P13-NEEDLE-GRID-ORCH` (one retry).

## RA-198.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH` | Implementation agent, Linux; RA-198.8, compile only |
| 2 | `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC` | Implementation agent, Linux; gate 881/881, membership 962; Vase RED `completion` / `PatchCompletionRejected` / `IncompleteSurfaceCellComplex` `side-count-unsupported`, within 600 s |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (P13-i; selection removes nothing) | Probe DEFN on the scratch build: coverage across faces, preserved incidences, removals on every fixture, gate and ledger; then exact patches |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–2 only. Steps 3–4 are probe DEFNs and stay on the Review track (Claude), on the scratch build; a Review turn that cannot run a scratch probe does not start them.

## RA-198.7 Probe scripts (scratch, not committed)

`scratchpad/p13i/`: `make_probe_i.py` (env-switched probes), `make_cb77.py` (CB77 state and mutants M1/M2), `make_patch77.py` (patch, apply check, result hashes), `needle_search.py` (the planar fixture search behind row 881), `gate.py` (env-driven per-row gate), `run_vase*.sh`.

## RA-198.8 Exact CB77 patch

```diff
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -2449,9 +2449,32 @@ PureQuadCompletionResult complete_pure_quad_patch(
     }
   }
   if (!completed && !boundedFallbackAdmissible) {
+    const PureQuadMesh boundaryOnly = mesh;
     completed = pure_quad_detail::complete_rectangular_grid(
         patch, mesh, projection.get(), allowedFacePtr,
         options.sourceAuthority);
+    // The grid places its generated vertices by the corners alone, which can
+    // fold a quad of a thin, bent patch whose boundary still has an embedded
+    // quadrangulation. Such a grid gives way to the pattern search over the
+    // same boundary when that search finds one; otherwise the grid stands and
+    // the validator reports its failure.
+    if (completed && patch.simple &&
+        mesh.vertices.size() > patch.boundaryVertices.size()) {
+      PureQuadMesh positioned = mesh;
+      PureQuadEmbeddingFailure gridFailure;
+      if (!pure_quad_detail::fill_positions(positioned) ||
+          !pure_quad_detail::completed_quads_have_simple_embedding(
+              positioned, options.completionVariant, gridFailure,
+              options.sourceVertices, options.sourceFaces)) {
+        PureQuadMesh search = boundaryOnly;
+        bool exhausted = false;
+        if (pure_quad_detail::complete_pattern(
+                patch, search, options.completionVariant,
+                options.sourceVertices, options.sourceFaces, exhausted)) {
+          mesh = std::move(search);
+        }
+      }
+    }
   }
   if (!completed && !boundedFallbackAdmissible && boundaryCount == 6) {
     completed = pure_quad_detail::complete_six_vertex_transition(
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -1991,3 +1991,30 @@ TEST(PatchDescriptorMilestoneE, ClosedFormStripRungsJoinOppositeSideVertices) {
   EXPECT_EQ(mesh.quads, (std::vector<std::vector<int>>{
                             {0, 1, 6, 7}, {1, 2, 5, 6}, {2, 3, 4, 5}}));
 }
+
+TEST(PatchDescriptorMilestoneE, BentNeedleGridCompletesByTheBoundarySearch) {
+  // A 2x2 strip 0.02 thick whose long sides dip by 0.03, more than its
+  // thickness. The bilinear vertex at (0.5, 0.01) lies outside the strip and
+  // projects onto side 2, where the grid's last quad turns clockwise; the
+  // boundary itself has an embedded quadrangulation.
+  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
+  fixture.V << 0.72, -0.0134, 0.0,
+               0.0, 0.0, 0.0,
+               0.5, -0.03, 0.0,
+               1.0, 0.0, 0.0,
+               1.0, 0.01, 0.0,
+               1.0, 0.02, 0.0,
+               0.7, -0.01, 0.0,
+               0.0, 0.02, 0.0,
+               0.0, 0.01, 0.0;
+  const auto completion = complete_fixture_with_source_authority(
+      fixture.complex, fixture.V, fixture.F);
+
+  ASSERT_TRUE(completion.is_produced());
+  ASSERT_EQ(1U, completion.product().completedPatches.size());
+  const auto &mesh = completion.product().completedPatches.front();
+  EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::Pattern,
+            mesh.backend);
+  EXPECT_EQ(3U, mesh.quads.size());
+  EXPECT_EQ(8U, mesh.vertices.size());
+}
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB71 manifest is TB70's 880 rows byte for byte plus row 881; `SELF_CHECK_PASS cases=881 deferred=81` with harness P8 |
| Decisive claims independently re-derived | Probe runs at HEAD behaviour reproduce TB70's Vase locus; every support trace and every selector transaction dumped; needle fall-through, rail-follow, tangent skip, relaxed degree and lens drop probes; clean build of the exact patch (gate, ledger, census); mutants; patch applied to HEAD with both result SHA-256 reproduced; embedded block re-hashed |
| Non-vacuity checked | Row 881 fails under M1 (HEAD behaviour); its grid quad has signed area −1.8·10⁻³, not a tolerance edge. The scope condition is not distinguished by any fixture (M2), and the record says so. The selector census counts every transaction, and the relaxed-degree and lens-drop probes show that each predicate binds |
| Prior obligations discharged/carried | P13-h2 attributed and routed (CB77/TB71). P13-i attributed to A2a selection → `M6-CP3-DEFN-P13-FLOWREP-SELECTION`. O24 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, O21, O22, O23, DR1/DR3, DR2/DR4, O2b, O15b, O7 |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | O24; the inert selector (F5) as a tracker candidate |
| ORIENTATION currency line | Updated to RA-198 / CB77 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: before routing a sliver to the arrangement or tracer, measure whether the selection stage removes anything |
| Consolidation under CLEAN_UP_POLICY | The review WIP stays as history with a superseded note pointing here |
| Successor frozen | CB77 (RA-198.4, exact RA-198.8) → TB71 (RA-198.5); Review DEFN `M6-CP3-DEFN-P13-FLOWREP-SELECTION` |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 1c7642c32` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB77 |
| Pushed to origin, branch in sync | Pushed to `origin/agent/surface_cell_quad/p5-recover-bridge-healing` as a fast-forward, no force; `git status -sb` confirms sync |
