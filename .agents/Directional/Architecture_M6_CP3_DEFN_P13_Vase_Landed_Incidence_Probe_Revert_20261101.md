# RA-194 — P13-d Vase: review of the landed diagnostics CB67; exact revert, then RA-193's patches (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (Review/Definition), reopened a second time at `46b3e240e`. [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md) withdrew the static decision's diagnostics CB67 and froze exact patches. The withdrawn CB67 nevertheless landed on top of RA-193:

- `c9c3578af` and `a6bf2c7b5` dispatched it.
- `829a47b2d` applied it (dispatcher `drive_apply`, base `6bc6efcb7`, patch `25588e54…`).
- `46b3e240e` removed its trigger.

There was no compile run and no report. The compiled source now differs from `911840c1…` in six paths (213 + / 46 −). RA-194 reviews what landed, rules that it be reverted, and renumbers RA-193's exact patches after the revert. RA-193's diagnosis, Amendment 26, patches and TB pre-registrations are unchanged.

## RA-194.1 What landed

| Part | Change |
|---|---|
| a | `validate_incidence_allowing_nondisk` rewritten as a typed `audit_incidence_allowing_nondisk` (clause, node, halfedge, twin, next, cell, source face), exported as `audit_surface_cell_incidence` |
| b | Side repair stores `canonicalInputIncidence` in its product and failure, and uses it as its input check |
| c | `complete_surface_cell_complex_pass` records four boundary audits per pass (parity input, parity output, side-repair input, side-repair canonicalized input) |
| d | The pipeline audits the arrangement and the simplified complex and records the first invalid clause in `surfaceCellFirstInvalidProducer*`. On `SideSubdivisionRepair:InvalidInputIncidence` it fails at stage `completion` with that evidence appended to the detail string |
| e | New public `same_surface_cell_incidence_structure` |
| f | One test, `MilestoneDClosure.IncidenceOracleReportsExactIndependentFailureSites`, in `tests/MilestoneDClosureTests.cpp` |

## RA-194.2 Findings

| # | Finding |
|---|---|
| L1 | **Compiles and preserves verdicts.** A syntax-only compile of the three changed production TUs at HEAD (scratch `bld61` flags) is clean. The rewritten validator keeps every check in the same order, and adds one successor range guard that only prevents an out-of-bounds read. The one gated test that asserts `surfaceCellFirstInvalidProducerStage` stops at tracing, before the new audits. This is a scope problem, not a regression. |
| L2 | **Does not discharge O18 under Amendment 26.** The run still forwards Vase's cell-less arrangement through simplification, parity and side repair, and ends with `terminal=NotProductionReady:completion`. The first invalid producer appears only inside the detail string. Amendments 19 and 26 require the typed exit at the producer that failed. |
| L3 | **Records the symptom as the first clause.** It re-audits the arrangement with the downstream oracle instead of reading the arrangement's own audit. Its check order matches the RA-193 probe, whose first failing check was halfedge 0 with `cell = −1`, so for Vase it reports `HalfedgeCellOutOfRange` at halfedge 0. That is the consequence of the arrangement dropping every cell. The cause is the arrangement's `RepeatedNodeCycle` at node 33, which it never reads. |
| L4 | **No executable test.** `MilestoneDClosureTests.cpp` is built only in `directional_surface_cell_historical_tests`, which CI configures OFF (`agent-compile-reusable.yml:216`). The file does not compile at HEAD either: its fixtures use `sourceComponent`/`sourceSheet`, removed in the M1 cutover. The decision's own F3 (valid control, injected faults) therefore has no evidence. |
| L5 | **Dead and redundant surface.** `same_surface_cell_incidence_structure` has no production caller; its only use is the dead test. `parity/output` and `side-repair/input` audit the same object. Every completion pass, one per structural candidate, now runs three extra full-complex audits unconditionally, plus two more per run at the arrangement and simplification. That cost is small, but it adds work on the very stage P13-f must make cheaper. |
| L6 | **Unreachable once RA-193's patches land.** Before the rotation fix, the run ends typed at the arrangement; after it, Vase's arrangement is valid. Downstream incidence is already validated by parity (when cells are odd), by subdivision on its output and by side repair. No probe in this patch would then fire on any known fixture. |

**Ruling:** revert `829a47b2d` exactly. Nothing in it is needed by the corrected trajectory. If a downstream `InvalidInputIncidence` ever recurs after the rotation fix, a DEFN can reintroduce a typed clause for that validator, with a test in a built target.

## RA-194.3 Renumbering

The landed patch consumed the number CB67. RA-193's turns keep their patches, SHAs, prechecks and pre-registered outcomes, under new numbers:

| RA-193 ID | New ID | Patch |
|---|---|---|
| — | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | RA-194.6 |
| `M6-CP3-CB67-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | RA-193.10, `35727214…` |
| `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | unchanged | — |
| `M6-CP3-CB68-P13-ARRANGEMENT-WEDGE-ROTATION` | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | RA-193.11, `e93f5d8c…` |
| `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | unchanged | — |

Routes follow the new numbers:
- CB69: `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP`, `M6-CP3-CB69A-P13-ARRANGEMENT-TERMINAL-ORCH`.
- CB70: `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP`, `M6-CP3-CB70A-P13-ARRANGEMENT-WEDGE-ORCH`.
- TB66 and TB67 routes are as in RA-193.6 and RA-193.8.

## RA-194.4 CB68 — exact revert

`M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` (Code, implementation agent, Linux workflow runner).

| Item | Value |
|---|---|
| Precheck | `git diff --quiet 829a47b2d96eb7313e64402c3de666266725ba7e HEAD -- src include tests benchmarks CMakeLists.txt cmake` (no source change since the landed patch) |
| Patch | RA-194.6 block, verbatim plus a trailing newline (keep its 13 single-space context lines). SHA-256 `a6b8cf62c8f9543bfa35766782906dc28c9d6cbe7263d5db0d1cabc1d4174c21`. Run `git apply --check`, then apply |
| Numstat | `0 8` `include/directional/geometry/PatchDescriptor.h`; `0 23` `include/directional/geometry/SurfaceCellFeasibilityRepair.h`; `0 14` `src/geometry/PatchDescriptor.cpp`; `46 85` `src/geometry/SurfaceCellFeasibilityRepair.cpp`; `0 49` `src/pipeline/RemeshPipeline.cpp`; `0 34` `tests/MilestoneDClosureTests.cpp` |
| Postcheck | `git diff --quiet 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Build | None. The postcheck proves every compiled path byte-identical to CB66's source, whose package `13067780359` TB65 ran 869/869. No binary runs |
| Outcomes | Exact → CB69. Mismatch → `M6-CP3-PLAN-P13-INCIDENCE-PROBE-REVERT-STOP` (Review). Infrastructure → `M6-CP3-CB68A-P13-INCIDENCE-PROBE-REVERT-ORCH` (one retry) |

## RA-194.5 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | Implementation agent, Linux; exact revert, source equality, no build |
| 2 | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; RA-193.10, compile only (spec RA-193.5) |
| 3 | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869, membership 950, census per RA-193.6 |
| 4 | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; RA-193.11, compile only (spec RA-193.7) |
| 5 | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871, membership 952, census per RA-193.8 |
| 6 (Review, parallel with 1–5) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) → CB → TB | Review (probes) → implementation agent |
| 7 (Review, after 5) | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) → CB → TB | Review (probes) → implementation agent |
| 8 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## RA-194.6 Exact CB68 revert patch

SHA-256 of the block content plus a trailing newline: `a6b8cf62c8f9543bfa35766782906dc28c9d6cbe7263d5db0d1cabc1d4174c21`. It is `git revert --no-commit 829a47b2d` at `46b3e240e`, as `git diff --cached`.

Thirteen lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the reverted source is clean under `git diff --check`.

```diff
diff --git a/include/directional/geometry/PatchDescriptor.h b/include/directional/geometry/PatchDescriptor.h
index cf68a36cd..eaea5172e 100644
--- a/include/directional/geometry/PatchDescriptor.h
+++ b/include/directional/geometry/PatchDescriptor.h
@@ -298,15 +298,7 @@ enum class SurfaceCellComplexCompletionFailureKind : int {
   AssemblyRejected = 7,
 };
 
-struct SurfaceCellIncidenceBoundaryProbe {
-  std::string stage;
-  SurfaceCellIncidenceIssue issue;
-  int oddCellsBefore = -1;
-};
-
 struct SurfaceCellComplexCompletionEvidence {
-  // Ordered, read-only incidence oracles across the preparation boundary.
-  std::vector<SurfaceCellIncidenceBoundaryProbe> incidenceBoundaryProbes;
   int parityOddCellsBefore = 0;
   int parityOddCellsAfter = 0;
   int paritySplitEdges = 0;
diff --git a/include/directional/geometry/SurfaceCellFeasibilityRepair.h b/include/directional/geometry/SurfaceCellFeasibilityRepair.h
index 81cfe9573..4b89355e4 100644
--- a/include/directional/geometry/SurfaceCellFeasibilityRepair.h
+++ b/include/directional/geometry/SurfaceCellFeasibilityRepair.h
@@ -22,27 +22,6 @@
 
 namespace directional::geometry {
 
-// Exact clause and source-supported site of the first failed incidence check.
-// This is diagnostic evidence only; it never authorizes a topology mutation.
-struct SurfaceCellIncidenceIssue {
-  std::string clause;
-  int node = -1;
-  int halfedge = -1;
-  int twin = -1;
-  int next = -1;
-  int cell = -1;
-  int sourceFace = -1;
-
-  [[nodiscard]] bool valid() const noexcept { return clause.empty(); }
-};
-
-[[nodiscard]] SurfaceCellIncidenceIssue audit_surface_cell_incidence(
-    const SurfaceCellComplex &complex);
-
-// Equality is determined over exact structural identities, not a hash.
-[[nodiscard]] bool same_surface_cell_incidence_structure(
-    const SurfaceCellComplex &first, const SurfaceCellComplex &second);
-
 struct SurfaceCellReplacementScopeFailure {
   bool active = false;
   int originalCell = -1;
@@ -459,7 +438,6 @@ enum class SurfaceCellSideRepairPreparationReason : int {
 };
 
 struct SurfaceCellSideRepairProduct {
-  SurfaceCellIncidenceIssue canonicalInputIncidence;
   SurfaceCellSideRepairProductKind kind = SurfaceCellSideRepairProductKind::Repaired;
   SurfaceCellSideRepairPreparationReason preparationReason =
       SurfaceCellSideRepairPreparationReason::None;
@@ -482,7 +460,6 @@ struct SurfaceCellSideRepairProduct {
 };
 
 struct SurfaceCellSideRepairFailure {
-  SurfaceCellIncidenceIssue canonicalInputIncidence;
   SurfaceCellSideRepairFailureKind kind = SurfaceCellSideRepairFailureKind::None;
   std::string detail;
   bool rollbackEquivalent = false;
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
index ace51b779..b9da3c5f8 100644
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -2480,8 +2480,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     ReusableCompletionProducts *reusableProducts = nullptr) {
   SurfaceCellComplexCompletionDraft result;
   const SurfacePointSourceSupportResolver sourceSupportResolver(F);
-  result.incidenceBoundaryProbes.push_back(
-      {"parity/input", audit_surface_cell_incidence(complex), -1});
   SurfaceCellParityRepairResult parityRepair =
       repair_surface_cell_boundary_parity(std::move(complex));
   std::optional<SurfaceCellParityRepairProduct> parityProduct;
@@ -2540,12 +2538,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     return result;
   }
   recordParityDiagnostics(parityProduct.value());
-  result.incidenceBoundaryProbes.push_back(
-      {"parity/output", audit_surface_cell_incidence(parityProduct->complex),
-       parityProduct->oddCellsBefore});
-  result.incidenceBoundaryProbes.push_back(
-      {"side-repair/input", audit_surface_cell_incidence(parityProduct->complex),
-       parityProduct->oddCellsBefore});
 
   SurfaceCellSideRepairResult sideRepair =
       repair_surface_cell_side_subdivisions(
@@ -2592,9 +2584,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     return result;
   }
   if (sideFailure.has_value()) {
-    result.incidenceBoundaryProbes.push_back(
-        {"side-repair/canonicalized-input", sideFailure->canonicalInputIncidence,
-         result.parityOddCellsBefore});
     recordSideDiagnostics(sideFailure.value());
     result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
     result.failure = "SideSubdivisionRepair:" + sideFailure->detail;
@@ -2607,9 +2596,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     result.assembly.failure = result.failure;
     return result;
   }
-  result.incidenceBoundaryProbes.push_back(
-      {"side-repair/canonicalized-input", sideProduct->canonicalInputIncidence,
-       result.parityOddCellsBefore});
   recordSideDiagnostics(sideProduct.value());
   if (sideProduct->kind ==
       SurfaceCellSideRepairProductKind::GeneralFallbackPreparation) {
diff --git a/src/geometry/SurfaceCellFeasibilityRepair.cpp b/src/geometry/SurfaceCellFeasibilityRepair.cpp
index ad9f3aff4..59a8af636 100644
--- a/src/geometry/SurfaceCellFeasibilityRepair.cpp
+++ b/src/geometry/SurfaceCellFeasibilityRepair.cpp
@@ -423,92 +423,67 @@ int odd_bounded_cell_count(const SurfaceCellComplex &complex) {
       }));
 }
 
-SurfaceCellIncidenceIssue audit_incidence_allowing_nondisk(
-    const SurfaceCellComplex &complex) {
-  const auto fail = [&](const char *clause, const int node = -1,
-                        const int halfedge = -1, const int cell = -1) {
-    SurfaceCellIncidenceIssue issue;
-    issue.clause = clause;
-    issue.node = node;
-    issue.halfedge = halfedge;
-    issue.cell = cell;
-    if (halfedge >= 0 &&
-        halfedge < static_cast<int>(complex.halfedges.size())) {
-      const auto &edge = complex.halfedges[static_cast<std::size_t>(halfedge)];
-      issue.twin = edge.twin;
-      issue.next = edge.next;
-      issue.sourceFace = edge.sourceFace;
-      if (issue.node < 0) issue.node = edge.from;
-    } else if (node >= 0 && node < static_cast<int>(complex.nodes.size())) {
-      issue.sourceFace = complex.nodes[static_cast<std::size_t>(node)].sourceFace;
-    } else if (cell >= 0 && cell < static_cast<int>(complex.cells.size())) {
-      issue.sourceFace = complex.cells[static_cast<std::size_t>(cell)].sourceFace;
-    }
-    return issue;
-  };
+bool validate_incidence_allowing_nondisk(const SurfaceCellComplex &complex) {
   for (int node = 0; node < static_cast<int>(complex.nodes.size()); ++node) {
-    if (complex.nodes[static_cast<std::size_t>(node)].id != node)
-      return fail("NodeIdMismatch", node);
+    if (complex.nodes[static_cast<std::size_t>(node)].id != node) {
+      return false;
+    }
   }
   std::vector<int> useCount(complex.halfedges.size(), 0);
   for (int id = 0; id < static_cast<int>(complex.halfedges.size()); ++id) {
     const SurfaceArrangementHalfedge &edge =
         complex.halfedges[static_cast<std::size_t>(id)];
-    if (edge.id != id) return fail("HalfedgeIdMismatch", -1, id);
-    if (edge.twin < 0 || edge.twin >= static_cast<int>(complex.halfedges.size()))
-      return fail("TwinOutOfRange", -1, id);
-    if (edge.next < 0 || edge.next >= static_cast<int>(complex.halfedges.size()))
-      return fail("SuccessorOutOfRange", -1, id);
-    if (edge.from < 0 || edge.from >= static_cast<int>(complex.nodes.size()))
-      return fail("FromNodeOutOfRange", -1, id);
-    if (edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()))
-      return fail("ToNodeOutOfRange", -1, id);
-    if (edge.from == edge.to) return fail("DegenerateHalfedge", -1, id);
-    if (edge.cell < 0 || edge.cell >= static_cast<int>(complex.cells.size()))
-      return fail("HalfedgeCellOutOfRange", -1, id);
-    const auto &twin = complex.halfedges[static_cast<std::size_t>(edge.twin)];
-    if (twin.twin != id) return fail("NonReciprocalTwin", -1, id);
-    if (twin.from != edge.to || twin.to != edge.from)
-      return fail("TwinEndpointMismatch", -1, id);
+    if (edge.id != id || edge.twin < 0 ||
+        edge.twin >= static_cast<int>(complex.halfedges.size()) ||
+        edge.next < 0 ||
+        edge.next >= static_cast<int>(complex.halfedges.size()) ||
+        edge.from < 0 || edge.from >= static_cast<int>(complex.nodes.size()) ||
+        edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()) ||
+        edge.from == edge.to || edge.cell < 0 ||
+        edge.cell >= static_cast<int>(complex.cells.size())) {
+      return false;
+    }
+    const SurfaceArrangementHalfedge &twin =
+        complex.halfedges[static_cast<std::size_t>(edge.twin)];
+    if (twin.twin != id || twin.from != edge.to || twin.to != edge.from) {
+      return false;
+    }
   }
   for (int id = 0; id < static_cast<int>(complex.cells.size()); ++id) {
-    const auto &cell = complex.cells[static_cast<std::size_t>(id)];
-    if (cell.id != id) return fail("CellIdMismatch", -1, -1, id);
-    if (!cell.closed) return fail("OpenCell", -1, -1, id);
-    if (cell.halfedges.size() < 2U) return fail("ShortCellBoundary", -1, -1, id);
-    if (cell.sideFamilies.size() != cell.sideEdgeCounts.size())
-      return fail("SideMetadataSizeMismatch", -1, -1, id);
+    const SurfaceArrangementCell &cell =
+        complex.cells[static_cast<std::size_t>(id)];
+    if (cell.id != id || !cell.closed || cell.halfedges.size() < 2U ||
+        cell.sideFamilies.size() != cell.sideEdgeCounts.size()) {
+      return false;
+    }
     std::vector<std::pair<std::size_t, std::size_t>> boundaryRanges;
-    if (!surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges))
-      return fail("BoundaryCycleRangesInvalid", -1, -1, id);
+    if (!surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges)) {
+      return false;
+    }
     std::set<int> seenHalfedges;
     for (const auto &[begin, end] : boundaryRanges) {
       for (std::size_t index = begin; index < end; ++index) {
         const int edgeId = cell.halfedges[index];
-        if (edgeId < 0 || edgeId >= static_cast<int>(complex.halfedges.size()))
-          return fail("BoundaryHalfedgeOutOfRange", -1, edgeId, id);
-        if (!seenHalfedges.insert(edgeId).second)
-          return fail("RepeatedBoundaryHalfedge", -1, edgeId, id);
-        const auto &edge = complex.halfedges[static_cast<std::size_t>(edgeId)];
-        const int nextId = cell.halfedges[index + 1U < end ? index + 1U : begin];
-        if (nextId < 0 || nextId >= static_cast<int>(complex.halfedges.size()))
-          return fail("BoundarySuccessorOutOfRange", -1, edgeId, id);
-        if (edge.cell != id) return fail("BoundaryCellMismatch", -1, edgeId, id);
-        if (edge.next != nextId) return fail("BoundarySuccessorMismatch", -1, edgeId, id);
-        if (edge.to != complex.halfedges[static_cast<std::size_t>(nextId)].from)
-          return fail("BoundaryEndpointMismatch", -1, edgeId, id);
+        if (edgeId < 0 ||
+            edgeId >= static_cast<int>(complex.halfedges.size()) ||
+            !seenHalfedges.insert(edgeId).second) {
+          return false;
+        }
+        const SurfaceArrangementHalfedge &edge =
+            complex.halfedges[static_cast<std::size_t>(edgeId)];
+        const int nextId =
+            cell.halfedges[index + 1U < end ? index + 1U : begin];
+        if (edge.cell != id || edge.next != nextId ||
+            edge.to !=
+                complex.halfedges[static_cast<std::size_t>(nextId)].from) {
+          return false;
+        }
         ++useCount[static_cast<std::size_t>(edgeId)];
       }
     }
   }
-  for (std::size_t id = 0; id < useCount.size(); ++id)
-    if (useCount[id] != 1)
-      return fail("DirectedHalfedgeUseMultiplicity", -1, static_cast<int>(id));
-  return {};
-}
-
-bool validate_incidence_allowing_nondisk(const SurfaceCellComplex &complex) {
-  return audit_incidence_allowing_nondisk(complex).valid();
+  return std::all_of(useCount.begin(), useCount.end(),
+                     [](const int count) { return count == 1; });
 }
 
 SurfaceCellDomainIdentityAudit audit_simple_cell_boundary(
@@ -872,19 +847,6 @@ int total_side_equation_defect(const SurfaceCellComplex &complex,
 
 namespace directional::geometry {
 
-SurfaceCellIncidenceIssue audit_surface_cell_incidence(
-    const SurfaceCellComplex &complex) {
-  return surface_cell_feasibility_detail::audit_incidence_allowing_nondisk(complex);
-}
-
-bool same_surface_cell_incidence_structure(
-    const SurfaceCellComplex &first, const SurfaceCellComplex &second) {
-  // Exact rollback identities include source scopes, halfedge incidence,
-  // ordered cell boundaries, logical sides and provenance. No hash shortcut.
-  return surface_cell_feasibility_detail::exact_rollback_identity(first) ==
-         surface_cell_feasibility_detail::exact_rollback_identity(second);
-}
-
 namespace {
 
 SurfaceCellSubdivisionFailure subdivision_failure_from_product(
@@ -938,7 +900,6 @@ SurfaceCellSideRepairFailure side_failure_from_product(
         std::nullopt) {
   SurfaceCellSideRepairFailure failure;
   failure.kind = kind;
-  failure.canonicalInputIncidence = std::move(product.canonicalInputIncidence);
   failure.detail = std::move(detail);
   failure.rollbackEquivalent = product.rollbackEquivalent;
   failure.rollbackIdentityHashBefore = product.rollbackIdentityHashBefore;
@@ -2111,7 +2072,6 @@ SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
       surface_cell_feasibility_detail::exact_rollback_identity(canonicalInput);
   surface_cell_feasibility_detail::canonicalize_logical_sides(
       canonicalInput, sourceVertices, sourceFaces);
-  result.canonicalInputIncidence = audit_surface_cell_incidence(canonicalInput);
   result.rollbackIdentityHashBefore =
       surface_cell_feasibility_detail::rollback_identity_hash(
           rollbackIdentity);
@@ -2160,7 +2120,8 @@ SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
       options.maxPropagationPasses <= 0 || options.maxStagnantPasses <= 0) {
     return returnRollback(SurfaceCellSideRepairFailureKind::InvalidSideRepairOptions, "InvalidSideRepairOptions");
   }
-  if (!result.canonicalInputIncidence.valid()) {
+  if (!surface_cell_feasibility_detail::
+          validate_incidence_allowing_nondisk(canonicalInput)) {
     return returnRollback(SurfaceCellSideRepairFailureKind::InvalidInputIncidence, "InvalidInputIncidence");
   }
   std::map<int, int> insertions;
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index e61aa5664..5421e8e39 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -13763,23 +13763,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
         arrangementCurrentOwnedBytes;
     result.diagnostics.surfaceCellArrangementPeakOwnedBytes =
         result.surfaceCellContext.arrangementPeakOwnedBytes;
-    const auto arrangementIncidence =
-        geometry::audit_surface_cell_incidence(arrangementComplex);
-    const auto recordFirstIncidence =
-        [&](const std::string &stage,
-            const geometry::SurfaceCellIncidenceIssue &issue) {
-      if (issue.valid() ||
-          !result.diagnostics.surfaceCellFirstInvalidProducerStage.empty())
-        return;
-      result.diagnostics.surfaceCellFirstInvalidProducerStage = stage;
-      result.diagnostics.surfaceCellFirstInvalidProducerReason = issue.clause;
-      result.diagnostics.surfaceCellFirstInvalidProducerNode = issue.node;
-      result.diagnostics.surfaceCellFirstInvalidProducerHalfedge = issue.halfedge;
-      result.diagnostics.surfaceCellFirstInvalidProducerTwin = issue.twin;
-      result.diagnostics.surfaceCellFirstInvalidProducerCell = issue.cell;
-      result.diagnostics.surfaceCellFirstInvalidProducerFace = issue.sourceFace;
-    };
-    recordFirstIncidence("arrangement/output", arrangementIncidence);
     const std::uint64_t arrangementHash = hash_surface_complex(arrangementComplex);
     if (retainForExecution) {
       // Retain a debug copy; simplification consumes the local stage product.
@@ -13916,9 +13899,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
     result.diagnostics.surfaceCellSimplifiedCountAvailable = true;
     const geometry::SurfaceCellComplex &simplifiedComplexForHash =
         simplified.hasComplexOutput ? simplified.complex : arrangementComplex;
-    recordFirstIncidence("simplification/output-or-arrangement-fallback",
-                         geometry::audit_surface_cell_incidence(
-                             simplifiedComplexForHash));
     const std::uint64_t simplificationHash =
         hash_surface_complex(simplifiedComplexForHash);
     const SurfaceCellObjectIdentity simplificationIdentity = make_identity(
@@ -14164,11 +14144,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
         completionResult.firstCompletionOwnershipRejection;
     result.surfaceCellContext.firstCompletionEmbeddingFailure =
         completionResult.firstCompletionEmbeddingFailure;
-    // The exact same oracle is used at arrangement, simplification,
-    // parity and side-repair boundaries. An earlier invalid site takes
-    // precedence over a downstream rejection; no repair is performed here.
-    for (const auto &probe : completionResult.incidenceBoundaryProbes)
-      recordFirstIncidence(probe.stage, probe.issue);
     const auto *closedCompletionFailure = completionResult.rejection();
     result.surfaceCellContext.completionFailure =
         closedCompletionFailure == nullptr ? std::string{}
@@ -14373,30 +14348,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
       result.surfaceCellContext.hasSimplifiedComplex = true;
     }
     if (completionResult.is_rejected()) {
-      if (completionResult.rejection() != nullptr &&
-          completionResult.rejection()->detail ==
-              "SideSubdivisionRepair:InvalidInputIncidence" &&
-          !result.diagnostics.surfaceCellFirstInvalidProducerStage.empty()) {
-        const auto &d = result.diagnostics;
-        std::ostringstream locus;
-        locus << "SideSubdivisionRepair:InvalidInputIncidence"
-              << ";firstIncidenceStage=" << d.surfaceCellFirstInvalidProducerStage
-              << ";clause=" << d.surfaceCellFirstInvalidProducerReason
-              << ";cell=" << d.surfaceCellFirstInvalidProducerCell
-              << ";halfedge=" << d.surfaceCellFirstInvalidProducerHalfedge
-              << ";twin=" << d.surfaceCellFirstInvalidProducerTwin
-              << ";node=" << d.surfaceCellFirstInvalidProducerNode
-              << ";sourceFace=" << d.surfaceCellFirstInvalidProducerFace
-              << ";incidenceBoundaryProof=arrangement/output:"
-              << (arrangementIncidence.valid() ? "PASS" : arrangementIncidence.clause);
-        for (const auto &probe : completionResult.incidenceBoundaryProbes)
-          locus << ',' << probe.stage << ':'
-                << (probe.issue.valid() ? "PASS" : probe.issue.clause)
-                << "@" << probe.issue.halfedge << '/' << probe.issue.cell
-                << '/' << probe.issue.sourceFace;
-        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
-                                  "completion", locus.str());
-      }
       return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                 "completion");
     }
diff --git a/tests/MilestoneDClosureTests.cpp b/tests/MilestoneDClosureTests.cpp
index 31c1d4a37..6909c0e1f 100644
--- a/tests/MilestoneDClosureTests.cpp
+++ b/tests/MilestoneDClosureTests.cpp
@@ -439,40 +439,6 @@ std::vector<SurfaceArrangementArc> cylinder_grid_arcs(
 
 } // namespace
 
-TEST(MilestoneDClosure, IncidenceOracleReportsExactIndependentFailureSites) {
-  using directional::geometry::audit_surface_cell_incidence;
-  const SurfaceCellComplex control = two_interface_complex(unit_triangle());
-  const auto healthy = audit_surface_cell_incidence(control);
-  ASSERT_TRUE(healthy.valid()) << healthy.clause;
-
-  SurfaceCellComplex brokenTwin = control;
-  brokenTwin.halfedges[0].twin = -1;
-  const auto twin = audit_surface_cell_incidence(brokenTwin);
-  EXPECT_EQ(twin.clause, "TwinOutOfRange");
-  EXPECT_EQ(twin.halfedge, 0);
-  EXPECT_EQ(twin.sourceFace, 0);
-
-  SurfaceCellComplex missingSuccessor = control;
-  missingSuccessor.halfedges[0].next = -1;
-  const auto successor = audit_surface_cell_incidence(missingSuccessor);
-  EXPECT_EQ(successor.clause, "SuccessorOutOfRange");
-  EXPECT_EQ(successor.halfedge, 0);
-  EXPECT_EQ(successor.sourceFace, 0);
-
-  SurfaceCellComplex repeatedCycle = control;
-  const auto cycle = repeatedCycle.cells[0].halfedges;
-  repeatedCycle.cells[0].halfedges.insert(
-      repeatedCycle.cells[0].halfedges.end(), cycle.begin(), cycle.end());
-  const auto repeated = audit_surface_cell_incidence(repeatedCycle);
-  EXPECT_EQ(repeated.clause, "RepeatedBoundaryHalfedge");
-  EXPECT_EQ(repeated.cell, 0);
-  EXPECT_GE(repeated.halfedge, 0);
-  EXPECT_FALSE(directional::geometry::same_surface_cell_incidence_structure(
-      control, repeatedCycle));
-  EXPECT_TRUE(directional::geometry::same_surface_cell_incidence_structure(
-      control, control));
-}
-
 TEST(MilestoneDClosure, CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces) {
   const MeshFixture mesh = curved_square();
   const SurfaceCellComplex complex =
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector or manifest change; the TB66 869 and TB67 871 manifests are unchanged from RA-193 |
| Decisive claims independently re-derived | Syntax-only compile of the landed TUs; check-order comparison with the RA-193 probe; build-target and CI-flag check for its test; a compile of that test file; the inverse patch applied in scratch and compared to `911840c1…` |
| Non-vacuity checked | The landed test cannot compile or run (L4); the revert's postcheck is an exact equality |
| Prior obligations discharged/carried | L1–L6 ruled. RA-193's obligations carried unchanged: O18 (TB66), P13-d arrangement (TB67), P13-e, P13-f, O6, O9, O16, O17, O19, DR1/DR3, DR2/DR4, O2b, O15b |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | None; the stale historical suite (now including `MilestoneDClosureTests.cpp`) stays with O2b |
| ORIENTATION currency line | Updated to RA-194 / CB68 revert next |
| ORIENTATION §3 / §4 / §7 / §8 | §7 order updated. §3/§4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: a test counts only if its target is built and the file compiles |
| Consolidation under CLEAN_UP_POLICY | n/a: RA-193 keeps its patches; RA-194 renumbers them |
| Successor frozen | CB68 (RA-194.4); CB69–TB67 per RA-193.5–193.8 under RA-194.3's numbers |
| Turn boundary held | No product, test, fixture or selector change in the repository; the revert is the implementation agent's turn |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 8b7299b43` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB68 |
| Pushed to origin, branch in sync | Yes, fast-forward on `46b3e240e`, no force |
