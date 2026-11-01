# RA-193 — P13-d Vase: probe adjudication of the completion-incidence decision, and exact CB67/CB68 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (Review/Definition), reopened and closed at `8eccb79d9`, semantic source `911840c195b52ce1800b3ac7ff3ea7380137ad9c` (CB66). The [Vase decision](Architecture_M6_CP3_DEFN_P13_Vase_Completion_Incidence_Review_Decision_20261101.md) was right to refuse an incidence "repair", and its F1 rule (the earliest invalid boundary owns the defect) is the rule applied here. But it left the producer unidentified, ruled from source reading alone, and handed the implementation agent an open-ended diagnostics CB. A two-minute scratch probe identifies the producer. **The arrangement publishes zero cells.** The cause is two defects in its directed rotation system, plus a pipeline that ignores the arrangement's own typed failure. Both are fixed here by exact patches (RA-193.10, RA-193.11), probe-verified on the gate and the ledger.

## RA-193.1 Review of the Vase decision

**Upheld.** No downstream incidence sanitizer, no skipped validator, no selector or assertion change; F1 (assign the earliest producer that violates incidence).

**Defects.**

| # | Decision text | Finding |
|---|---|---|
| V1 | "`arrangementCells=0` is a reported diagnostic count, not proof that the arrangement was empty" | **Wrong.** `RemeshPipeline.cpp:13736` sets it to `arrangementComplex.cells.size()`. The probe confirms 0 cells over 57,677 nodes and 169,004 halfedges, every one with `cell = −1`. |
| V2 | The zero-odd parity fast path is "a contract-validation blind spot" | **Immaterial.** Side repair runs the same `validate_incidence_allowing_nondisk` on the same complex immediately afterwards, so nothing is hidden. Not carried. |
| V3 | "No evidence currently distinguishes arrangement-origin invalidity, a simplification-induced invalidity, or an invalid parity transform" | **The evidence was already published.** The arrangement records its own typed audit (`SurfaceArrangementDiagnostics::incidenceValid`, `incidenceFailure`, node, halfedge). It reports `RepeatedNodeCycle` at node 33. The pipeline discards it: `RemeshPipeline.cpp:13777` records the stage as succeeded unconditionally. That is the O18 defect, an Amendment 19 violation, not a missing probe point. |
| V4 | CB67 "change only the smallest existing producer/validation boundary needed …", F3 "inject a known invalid twin … into a synthetic source-complex unit fixture" | **Open-ended.** It gives the implementation agent design latitude and fixture design, contrary to the standing rule (exact patches and frozen manifests only). Withdrawn. |
| V5 | "Invoke one consistent named validation oracle at these boundaries" | Three already exist: the arrangement's own audit, `validate_incidence_allowing_nondisk` and the typed `surface_simplification_detail::audit_complex_incidence`. No new oracle is needed. |
| V6 | No probe | A one-line `fprintf` at four boundaries settled F1 in one run (RA-193.3). This is the fourth consecutive P13 DEFN decided statically (RA-188, RA-190, RA-192). |

## RA-193.2 Root cause

The generic arrangement (`build_surface_cell_complex`, non-proposal branch) orders the rays at each node into directed wedges and takes each halfedge's successor from its wedge. Two defects break that rotation system wherever a trace crosses a source edge or vertex:

- **R1, split wedges.** The wedge map is keyed by `ResolvedSourceEntity`. Its `operator<` (`SourceChartTransitions.h:143`) compares `chart`, a `SourceProjectionChart` whose `operator<=>` includes the source **face** (`SurfaceCellOwnership.h:134`). An edge point seen from its two faces, or a vertex seen from the faces of its fan, therefore yields one wedge per face. Each wedge holds a single ray, whose successor is the incoming halfedge's own twin, so the face walk turns back along the trace. On Vase, 23,332 of 57,677 nodes are split, giving 46,585 single-ray wedges (46,338 edge, 247 vertex). The code's own intent is a shared wedge:
  - the two-face side mapping at `SurfaceArrangement.cpp:2926`;
  - the boundary-rail comment "One common SourceVertex/SourceEdge identity" (`:3603`);
  - the historical test `AdjacentLocalSheetChartsShareDirectedIntrinsicWedges` (`SurfaceArrangementPhase16Tests.cpp:1547`).

  The canonical `SourceEntityIdentity` (component, edge or vertex fan, field chart) exists for exactly this purpose.
- **R2, mirrored edge rotations.** An edge ray's angle is measured from the canonical low→high direction into its face (`:2652`). That is counter-clockwise only on the face that traverses low→high. The side that gets `2π − θ` is chosen by sorted vertex signature, not orientation, and a single-face wedge is never corrected. An independent 3D rotation oracle (cyclic order about the face normal) over Vase's nodes with three or more rays gives: face interior 26,670 same / 0 mirrored; vertex 102 / 0; **edge 95 / 72**.
- **R3, O18.** When incidence is invalid the arrangement drops every cell (`:6351`). The pipeline still records the stage as succeeded and forwards the empty complex. Simplification, parity and side repair then pass it along until side repair's validator rejects it with a generic `InvalidInputIncidence`, `detail=None`.

**Why this was never seen.** The non-proposal path is reached only by fixtures that every authoritative phase-front producer declines. In the 869 gate rows and the 81 deferred rows, only Vase reaches an invalid arrangement. The arrangement's unit tests are in the historical target, which is not built, and they are stale: none passes `sourceAuthority`. Before CB65, Vase failed earlier at the A4 width bound. At HEAD, even an arc-free two-triangle square fails here with `BoundaryRotationalSystemConflict`.

## RA-193.3 Probe findings (macOS scratch build `bld61`, diagnostic only)

| Probe | Result |
|---|---|
| Incidence at each boundary (HEAD) | arrangement out, simplified out, parity in, side in (raw and canonical): all `cells=0`, first clause `halfedge.cell = −1`. **F1 fires at the arrangement.** Its own audit: `RepeatedNodeCycle`, node 33 (source face 0, interior X-crossing), first face walk of 68 halfedges, the outside of a figure-8 of arcs confined to triangle 0 because every arc reaching the triangle's interior edges U-turns |
| R1 only fixed | No single-ray wedges remain; walks from the first 112 halfedges pass; next `RepeatedEdgeCycle` (a 1,114-halfedge walk using both sides of a non-bridge edge, impossible on a disk) |
| R1 + R2 fixed | Rotation oracle edge 167 / 0. **Arrangement valid: 26,827 cells, `topologyValid`.** Simplification valid; parity 5,937 odd → 0; side-repair input valid. Completion then runs for more than 25 min (RA-193.4, P13-f) |
| Gate 869, R3 only (CB67 state) | **868/869**, only row 283 (O16); no row reaches an invalid arrangement |
| Gate 869, R1 + R2 + R3 (CB68 state) | **868/869**, only row 283 |
| Clean CB67 + CB68 build, TB67 manifest 871 | **870/871**, only row 283; membership listed from the five binaries **952** = 871 + 81 |
| 81 deferred rows, HEAD vs CB68 state | 0 PASS in both. One change: row 365 (Vase) RED → TIMEOUT at 300 s, because it now reaches completion. HEAD mode: exactly one row (Vase) with invalid arrangement incidence |
| New tests | `TraceCrossingInteriorSourceEdgeSharesOneDirectedEdgeWedge` and `TraceThroughInteriorSourceVertexSharesOneDirectedFanWedge` pass. R1 reverted: both fail (`BoundaryRotationalSystemConflict`). R2 reverted: both fail (`BoundaryFanSectorCoverConflict`). Both reverted: both fail |
| Vase census, CB67 state | `terminal=NotProductionReady:arrangement detail=RepeatedNodeCycle traceSegments=192482 arrangementCells=0 completedQuads=0 completion=` |
| Vase census, CB68 state | No verdict within 600 s (clean build); the stack is in `complete_pure_quad_patch` |
| Completion cost (stack samples) | 3,179 of 3,807 samples are in `close_completion_lineage_source_authority`, which builds a full `SourceChartTransitionGraph` and runs `matches_source_faces` (both O(F)) **per output vertex**. Reusing the caller's graph moves 2,755 of 3,840 samples to `validate_completion_domain_ownership`'s own per-patch graph build (`PureQuadCompletion.cpp:1322`), once per patch × 26,827 patches |

## RA-193.4 Rulings

- **Amendment 26 (new):** a directed wedge is one counter-clockwise rotation about its source entity, shared by every incident face chart. An arrangement whose incidence is invalid ends the run at the `arrangement` stage with its own typed failure.
- **O18:** discharged when TB66 matches.
- **P13-d (arrangement rotation system):** discharged when TB67 matches. Vase's frontier moves to completion.
- **P13-f (new):** completion ownership validation is O(output vertices × F) and then O(patches × F), from repeated `SourceChartTransitionGraph` construction in `PureQuadCompletion.cpp` (`:869`, `:1322`; callers `:1282`, `:1582`, `PatchDescriptor.cpp:2842`). The fix must build the graph once per completion and pass it down. That changes the `complete_pure_quad_patch` / `validate_completion_domain_ownership` signatures, so it is a design choice for a probe DEFN, not a CB.
  - Owner: `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (Review, probes), after TB67. It must name the next Vase failure, or a PASS, within the 600 s harness bound.
- **P13-e** (BunnyRandom vertex 49) is independent of this change and already confirmed on Linux by TB65. Its DEFN can run on the Review track now.
- **Superseded:** the decision's `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE`, its F1–F5 CB contract and its follow-on TB. CB67 now names the exact O18 patch.
- **Carried:** P13-e, O6, O9, O16, O17, O19, DR1/DR3, DR2/DR4, O2b, O15b. The stale historical arrangement suite belongs to O2b's retirement DEFN.

## RA-193.5 CB67 — exact patch (O18)

`M6-CP3-CB67-P13-ARRANGEMENT-INCIDENCE-TERMINAL` (Code + Build, implementation agent, Linux workflow runner; compile only).

| Item | Value |
|---|---|
| Precheck | `git diff --quiet 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Patch | RA-193.10 block, verbatim plus a trailing newline. SHA-256 `35727214ac067ac3337ce640ec78fd23a8e92f7f14c444d953053feef7209822`. Run `git apply --check`, then apply |
| Numstat | `29 1` `src/pipeline/RemeshPipeline.cpp` |
| Base / result SHA-256 | `47d77eb7ec4d7356f43890669b7b9158929b236695249956be2ddd8e264c410c` → `d478a64c57df71a0a50182ec80304b5176dfd87a0f5999de410a764c9e5f391a` |
| Build | `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256. No binary runs |
| Outcomes | Exact → TB66. Patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP` (Review). Infrastructure failure → `M6-CP3-CB67A-P13-ARRANGEMENT-TERMINAL-ORCH` (one retry) |

## RA-193.6 TB66 — frozen inputs and pre-registered outcomes

`M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` (artifact-only, CB67 package).

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv`, 869 rows, `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`, unchanged (CB67 adds no test) |
| Ledger | v5, 81 rows, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Census | `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

| Run | Pre-registered outcome |
|---|---|
| Gate | **869/869 PASS**, membership **950**, postflight true |
| Census 1, Cylinder | PASS |
| Census 2, BunnyRandom | RED `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` (unchanged) |
| Census 3, Vase | RED `terminal=NotProductionReady:arrangement detail=RepeatedNodeCycle`, `traceSegments=192482`, `arrangementCells=0`, `completedQuads=0`, empty `completion=` |

Mismatch → `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-REV` (Review). Infrastructure → `M6-CP3-TB66A-P13-ARRANGEMENT-TERMINAL-ORCH` (one retry).

## RA-193.7 CB68 — exact patch (arrangement rotation system)

`M6-CP3-CB68-P13-ARRANGEMENT-WEDGE-ROTATION` (Code + Build, implementation agent, Linux workflow runner; compile only; after TB66).

| Item | Value |
|---|---|
| Precheck | `git diff --name-only 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake` prints only `src/pipeline/RemeshPipeline.cpp`, at SHA-256 `d478a64c…` (CB67) |
| Patch | RA-193.11 block, verbatim plus a trailing newline (keep its five single-space context lines). SHA-256 `e93f5d8c5966f520e4650259a4d836bba1fbfa6ac025d08fe98e49a3065e0f82`. Run `git apply --check`, then apply |
| Numstat | `37 30` `src/geometry/SurfaceArrangement.cpp`; `95 0` `tests/SurfaceArrangementRowIdentityTests.cpp` |
| Base → result SHA-256 | arrangement `8dd2f3fd2cae0c253a050edaf38ce4b724ed379990d9ec800269077cee996d68` → `2c8f66296219f13b57895592851c1a3561e5f525dd98b1fc4b24049e2e4a183e`; tests `95ff8de9595844ff48b6f001360758dd67aca58a2a7812dd7a187ec4db255fea` → `862ab53de607ad094bc708bef86497e8ed81a4b6ee18ee5c1f638d689f646214` |
| Build | As CB67 |
| Outcomes | Exact → TB67. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP` (Review). Infrastructure → `M6-CP3-CB68A-P13-ARRANGEMENT-WEDGE-ORCH` (one retry) |

## RA-193.8 TB67 — frozen inputs and pre-registered outcomes

`M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` (artifact-only, CB68 package).

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv`, **871 rows**, SHA-256 `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b`: the TB65 869 rows byte-identical, plus GUARD rows 870 `ra193:edge-wedge` and 871 `ra193:fan-wedge` (`directional_surface_cell_completion_tests`). P8 `SELF_CHECK_PASS cases=871 deferred=81` |
| Ledger, census, harness | As TB66 |

| Run | Pre-registered outcome |
|---|---|
| Gate | **871/871 PASS**, membership **952**, postflight true |
| Census 1, Cylinder | PASS |
| Census 2, BunnyRandom | RED, unchanged signature (as TB66) |
| Census 3, Vase | **ABNORMAL**, harness timeout (600 s, exit 124) inside completion (P13-f). Any verdict before 600 s is a mismatch |

Mismatch → `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-REV` (Review). Infrastructure → `M6-CP3-TB67A-P13-ARRANGEMENT-WEDGE-ORCH` (one retry).

## RA-193.9 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB67-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; exact patch, compile only |
| 2 | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869, membership 950, census 3 |
| 3 | `M6-CP3-CB68-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; exact patch, compile only |
| 4 | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871, membership 952, census 3 |
| 5 (Review, parallel with 1–4) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) → CB → TB | Review (probes) → implementation agent |
| 6 (Review, after 4) | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) → CB → TB | Review (probes) → implementation agent |
| 7 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## RA-193.10 Exact CB67 patch

SHA-256 of the block content plus a trailing newline: `35727214ac067ac3337ce640ec78fd23a8e92f7f14c444d953053feef7209822`.

```diff
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index 5421e8e39..d44a21f83 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -13774,9 +13774,37 @@ remesh_from_raw_cross_field_impl_with_stage_products(
         result.diagnostics.surfaceCellArrangementCellCount);
     mark_stage_consumed("embedding", retainedNetworkIdentity,
                         SurfaceCellConsumptionKind::Full);
+    const geometry::SurfaceArrangementDiagnostics &arrangementIncidence =
+        arrangementComplex.diagnostics;
     record_surface_cell_stage("arrangement", retainedNetworkIdentity,
-                              arrangementIdentity, true,
+                              arrangementIdentity,
+                              arrangementIncidence.incidenceValid,
                               result.diagnostics.surfaceCellArrangementSeconds);
+    if (!arrangementIncidence.incidenceValid) {
+      // Without valid incidence the arrangement publishes no cells to simplify
+      // or complete; its own typed failure is the first invalid producer.
+      SurfaceCellFailureLocusDiagnostics locus;
+      if (arrangementIncidence.incidenceFailureNode >= 0 &&
+          arrangementIncidence.incidenceFailureNode <
+              static_cast<int>(arrangementComplex.nodes.size())) {
+        const int face =
+            arrangementComplex
+                .nodes[static_cast<std::size_t>(
+                    arrangementIncidence.incidenceFailureNode)]
+                .sourceFace;
+        if (face >= 0 && face < meshWhole.F.rows()) {
+          locus.sourceFace = std::array<std::size_t, 3>{
+              static_cast<std::size_t>(meshWhole.F(face, 0)),
+              static_cast<std::size_t>(meshWhole.F(face, 1)),
+              static_cast<std::size_t>(meshWhole.F(face, 2))};
+        }
+      }
+      return fail_surface_cells(
+          SurfaceCellFailureCode::NotProductionReady, "arrangement",
+          geometry::surface_arrangement_incidence_failure_name(
+              arrangementIncidence.incidenceFailure),
+          locus);
+    }
     completedSurfaceCellStages.push_back("arrangement");
     if (options.surfaceCells.injectFailureAfterStage == 6) {
       return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
```

## RA-193.11 Exact CB68 patch

SHA-256 of the block content plus a trailing newline: `e93f5d8c5966f520e4650259a4d836bba1fbfa6ac025d08fe98e49a3065e0f82`.

Five lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the patched source is clean under `git diff --check`.

```diff
diff --git a/src/geometry/SurfaceArrangement.cpp b/src/geometry/SurfaceArrangement.cpp
index 8dc2e40a4..3104eb4cc 100644
--- a/src/geometry/SurfaceArrangement.cpp
+++ b/src/geometry/SurfaceArrangement.cpp
@@ -2650,6 +2650,19 @@ SurfaceCellComplex build_surface_cell_complex(
           }
           y = std::max(0.0, y);
           parameter = std::atan2(y, direction.dot(edgeDirection));
+          // The angle runs from the canonical low->high direction into this
+          // face. It is counterclockwise only on the face that traverses
+          // low->high; the opposite face measures its clockwise complement.
+          const int chartFace = chart_source_face(chart);
+          bool lowToHigh = false;
+          for (int corner = 0; corner < 3; ++corner) {
+            lowToHigh = lowToHigh ||
+                        (faces(chartFace, corner) == lowVertex &&
+                         faces(chartFace, (corner + 1) % 3) == highVertex);
+          }
+          if (!lowToHigh && parameter > 0.0) {
+            parameter = 6.283185307179586476925286766559 - parameter;
+          }
           return std::isfinite(parameter);
         }
         if (entity.kind() == SourceEntityKind::FaceInterior) {
@@ -2812,9 +2825,19 @@ SurfaceCellComplex build_surface_cell_complex(
       }
     }
   } else {
+  // A directed wedge is one rotation about its source entity. Key it by the
+  // canonical identity so that the incident face charts of one source edge or
+  // vertex fan share it.
+  struct DirectedWedgeKeyLess {
+    bool operator()(const ResolvedSourceEntity &lhs,
+                    const ResolvedSourceEntity &rhs) const {
+      return lhs.identity < rhs.identity;
+    }
+  };
   using DirectedWedgeMap =
       std::map<ResolvedSourceEntity,
-               std::map<int, std::vector<DirectedWedgeWitness>>>;
+               std::map<int, std::vector<DirectedWedgeWitness>>,
+               DirectedWedgeKeyLess>;
   std::vector<DirectedWedgeMap> wedgeWitnesses(complex.nodes.size());
   std::vector<std::vector<int>> outgoing(complex.nodes.size());
   for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
@@ -2864,7 +2887,8 @@ SurfaceCellComplex build_surface_cell_complex(
     }
   }
 
-  std::vector<std::map<ResolvedSourceEntity, std::vector<DirectedWedgeRay>>>
+  std::vector<std::map<ResolvedSourceEntity, std::vector<DirectedWedgeRay>,
+                       DirectedWedgeKeyLess>>
       orderedWedges(complex.nodes.size());
   std::vector<std::vector<ResolvedSourceEntity>>
       halfedgeWedges(complex.halfedges.size());
@@ -2894,13 +2918,8 @@ SurfaceCellComplex build_surface_cell_complex(
           }
         }
       }
-      std::vector<int> wedgeFaces(sourceFaceSet.begin(), sourceFaceSet.end());
-      std::sort(wedgeFaces.begin(), wedgeFaces.end(), [&](const int lhs,
-                                                           const int rhs) {
-        return std::make_tuple(face_signature(lhs), lhs) <
-               std::make_tuple(face_signature(rhs), rhs);
-      });
-      if (wedgeKind == SourceEntityKind::SourceEdge && wedgeFaces.size() > 2U) {
+      if (wedgeKind == SourceEntityKind::SourceEdge &&
+          sourceFaceSet.size() > 2U) {
         ++complex.diagnostics.successorAmbiguityCount;
         record_incidence_failure(
             SurfaceArrangementIncidenceFailure::AmbiguousWedge, nodeId, -1,
@@ -2913,24 +2932,7 @@ SurfaceCellComplex build_surface_cell_complex(
         std::vector<double> parameters;
         parameters.reserve(witnesses.size());
         for (const DirectedWedgeWitness &witness : witnesses) {
-          double mapped = witness.localParameter;
-          if (wedgeKind == SourceEntityKind::SourceEdge &&
-              wedgeFaces.size() == 2U) {
-            const auto found = std::find(wedgeFaces.begin(), wedgeFaces.end(),
-                                         witness.chart.sourceFace);
-            if (found == wedgeFaces.end()) {
-              continue;
-            }
-            const int side =
-                static_cast<int>(std::distance(wedgeFaces.begin(), found));
-            if (side == 1) {
-              mapped = twoPi - mapped;
-            }
-            if (std::abs(mapped - twoPi) <= parameterTolerance) {
-              mapped = 0.0;
-            }
-          }
-          parameters.push_back(mapped);
+          parameters.push_back(witness.localParameter);
         }
         if (parameters.empty()) {
           ++complex.diagnostics.successorMissingCount;
@@ -2990,8 +2992,12 @@ SurfaceCellComplex build_surface_cell_complex(
     }
   }
   for (auto &memberships : halfedgeWedges) {
-    std::sort(memberships.begin(), memberships.end());
-    memberships.erase(std::unique(memberships.begin(), memberships.end()),
+    std::sort(memberships.begin(), memberships.end(), DirectedWedgeKeyLess{});
+    memberships.erase(std::unique(memberships.begin(), memberships.end(),
+                                  [](const ResolvedSourceEntity &lhs,
+                                     const ResolvedSourceEntity &rhs) {
+                                    return lhs.identity == rhs.identity;
+                                  }),
                       memberships.end());
   }
 
@@ -3612,7 +3618,8 @@ SurfaceCellComplex build_surface_cell_complex(
                 localOutgoing[index])];
             std::set_intersection(commonWedges.begin(), commonWedges.end(),
                                   memberships.begin(), memberships.end(),
-                                  std::back_inserter(intersection));
+                                  std::back_inserter(intersection),
+                                  DirectedWedgeKeyLess{});
             commonWedges = std::move(intersection);
           }
 
diff --git a/tests/SurfaceArrangementRowIdentityTests.cpp b/tests/SurfaceArrangementRowIdentityTests.cpp
index 1342f2da9..e4b6bbb5c 100644
--- a/tests/SurfaceArrangementRowIdentityTests.cpp
+++ b/tests/SurfaceArrangementRowIdentityTests.cpp
@@ -2,6 +2,7 @@
 #include <directional/geometry/SurfaceArrangement.h>
 #include <directional/geometry/SurfaceCellTracing.h>
 
+#include <algorithm>
 #include <memory>
 #include <stdexcept>
 #include <vector>
@@ -118,4 +119,98 @@ TEST(SurfaceArrangementPhase16,
   EXPECT_NE(firstIdentity, distinctIdentity);
 }
 
+// A directed wedge is one rotation about a source edge or vertex fan.
+// A trace crossing a shared source edge or vertex must continue into the next
+// face; keying the wedge by the witnessing face chart splits it and turns the
+// face walk back along the trace.
+directional::geometry::SurfaceArrangementArc wedge_test_arc(
+    const int id, const int face, const Eigen::RowVector3d &start,
+    const Eigen::RowVector3d &end) {
+  directional::geometry::SurfaceArrangementArc arc;
+  arc.id = id;
+  arc.sourceFace = face;
+  arc.startBarycentric = start;
+  arc.endBarycentric = end;
+  arc.family = 0;
+  arc.strand = 0;
+  arc.provenance = id;
+  return arc;
+}
+
+void expect_trace_continues_through_shared_node(
+    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
+    const std::vector<directional::geometry::SurfaceArrangementArc> &arcs,
+    const Eigen::RowVector3d &sharedPoint) {
+  const std::vector<int> components(static_cast<std::size_t>(faces.rows()), 0);
+  const std::vector<int> sheets(static_cast<std::size_t>(faces.rows()), 0);
+  directional::geometry::SurfaceArrangementOptions options;
+  options.sourceAuthority =
+      row_identity_source_authority(faces, components, sheets);
+  const auto complex = directional::geometry::build_surface_cell_complex(
+      vertices, faces, arcs, options);
+
+  ASSERT_TRUE(complex.diagnostics.incidenceValid)
+      << directional::geometry::surface_arrangement_incidence_failure_name(
+             complex.diagnostics.incidenceFailure);
+  EXPECT_EQ(2, std::count_if(complex.cells.begin(), complex.cells.end(),
+                             [](const auto &cell) { return !cell.boundaryCycle; }));
+  int sharedNode = -1;
+  for (const auto &node : complex.nodes) {
+    Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
+    for (int corner = 0; corner < 3; ++corner) {
+      position += node.barycentric(corner) *
+                  vertices.row(faces(node.sourceFace, corner));
+    }
+    if ((position - sharedPoint).norm() < 1.0e-12) {
+      ASSERT_EQ(-1, sharedNode);
+      sharedNode = node.id;
+    }
+  }
+  ASSERT_GE(sharedNode, 0);
+  int incoming = 0;
+  for (const auto &halfedge : complex.halfedges) {
+    if (halfedge.to != sharedNode) {
+      continue;
+    }
+    ++incoming;
+    EXPECT_NE(halfedge.twin, halfedge.next) << "halfedge " << halfedge.id;
+  }
+  EXPECT_EQ(2, incoming);
+}
+
+TEST(SurfaceArrangementPhase16,
+     TraceCrossingInteriorSourceEdgeSharesOneDirectedEdgeWedge) {
+  Eigen::MatrixXd vertices(4, 3);
+  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0;
+  Eigen::MatrixXi faces(2, 3);
+  faces << 0, 1, 2,
+           1, 3, 2;
+  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
+      wedge_test_arc(0, 0, Eigen::RowVector3d(0.5, 0.0, 0.5),
+                     Eigen::RowVector3d(0.0, 0.5, 0.5)),
+      wedge_test_arc(1, 1, Eigen::RowVector3d(0.5, 0.0, 0.5),
+                     Eigen::RowVector3d(0.5, 0.5, 0.0))};
+  expect_trace_continues_through_shared_node(
+      vertices, faces, arcs, Eigen::RowVector3d(0.5, 0.5, 0.0));
+}
+
+TEST(SurfaceArrangementPhase16,
+     TraceThroughInteriorSourceVertexSharesOneDirectedFanWedge) {
+  Eigen::MatrixXd vertices(5, 3);
+  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
+      0.5, 0.5, 0.0;
+  Eigen::MatrixXi faces(4, 3);
+  faces << 0, 1, 4,
+           1, 2, 4,
+           2, 3, 4,
+           3, 0, 4;
+  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
+      wedge_test_arc(0, 3, Eigen::RowVector3d(0.5, 0.5, 0.0),
+                     Eigen::RowVector3d(0.0, 0.0, 1.0)),
+      wedge_test_arc(1, 1, Eigen::RowVector3d(0.0, 0.0, 1.0),
+                     Eigen::RowVector3d(0.5, 0.5, 0.0))};
+  expect_trace_continues_through_shared_node(
+      vertices, faces, arcs, Eigen::RowVector3d(0.5, 0.5, 0.0));
+}
+
 } // namespace
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB65 869 `baaef9e7…` is the byte-identical prefix of TB67 871 `434e6d37…`; ledger v5 `fd433f54…` unchanged; both self-check |
| Decisive claims independently re-derived | Probes, not static reading: incidence at every boundary, the arrangement's own audit, a wedge census, an independent 3D rotation oracle, the gate in two states plus the clean build, the ledger in two modes, and stack samples of the completion cost |
| Non-vacuity checked | Each new test fails with either fix reverted; HEAD mode reaches an invalid arrangement on exactly one ledger row (Vase), which the CB67 census pre-registers |
| Prior obligations discharged/carried | V1–V6 ruled. O18 discharged once TB66 matches; P13-d's arrangement defect once TB67 matches. P13-f new. P13-e, O6, O9, O16, O17, O19, DR1/DR3, DR2/DR4, O2b, O15b carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-f (completion ownership cost) |
| ORIENTATION currency line | Updated to RA-193 / CB67 next |
| ORIENTATION §3 / §4 / §7 / §8 | §7 Immediate and priority 1 updated; §8 adds the arrangement-audit lesson. §3/§4: n/a, no executed gate or witness change |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: read the producer's own published audit before instrumenting its consumers |
| Consolidation under CLEAN_UP_POLICY | n/a: the Vase decision stays as history; RA-193.1 rules it |
| Successor frozen | CB67 (RA-193.5), TB66 (RA-193.6), CB68 (RA-193.7), TB67 (RA-193.8) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran only in scratch builds |
| `review_check.py boundary` | Recorded after the push |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB67 |
| Pushed to origin, branch in sync | Confirmed after the push |
