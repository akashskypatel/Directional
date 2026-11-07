# RA-190 — O15c dyadic A2a exit: probe adjudication of RA-189 (2026-10-31)

**Turn:** `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` (Review/Definition), resumed and closed on an authentic Git checkout. RA-190 keeps RA-189's choice of a dyadic exit and its Cylinder promotion. It replaces RA-189 §2's safety obligations and §4's CB65 scope with one exact, probe-verified patch (RA-190.8). DESIGN.md Amendment 24 is rewritten to match.

## RA-190.1 The boundary block was procedural

RA-189 could not close because its agent ran `review_check.py boundary` on a source snapshot with no Git history, so the rewrite ancestor `8b7299b43` was missing. On this checkout at `aed15cd6c`, the unmodified checker reports **ALL CHECKS PASSED**: the rewrite baseline exists and is an ancestor, and the durable sections are preserved 4/4, 1/1 and 0/0. Nothing in the design depended on it.

## RA-190.2 Review of RA-189

**Upheld.**
- **A dyadic exit, not a higher cap or rounded directions.** Uncapped exact arithmetic on Vase needs 9,131 bits over 309 exits, and prescribed-sphere circulations reach 12,243 bits. Width grows linearly with trace length, so any fixed cap fails on production-size meshes. A rounded direction leaves the affine exit map composing rational coefficients.
- **The policy itself:** `B = 52`, ties to even, integer arithmetic only.
- **The Cylinder promotion,** re-verified:
  - The 864-row manifest `b50463ea…` has an 863-row prefix byte-identical to the TB58 manifest.
  - Ledger v5 `fd433f54…` is exactly v4 minus `offgate:362`.
  - The harness reports `SELF_CHECK_PASS cases=864 deferred=81`.

**Defects.**

| # | RA-189 text | Finding |
|---|---|---|
| R1 | §4: apply rounding "at every A4 trace-exit path" and at the `currentEntryPoint`/`proposal.nextEntryPoint = decision.exitPoint` assignments | **Would break consistency.** Four consumers re-derive a segment's exit by calling `resolve_field_branch_continuation` on the stored entry: the legacy tracer (`SurfaceCellTracing.cpp:2457`), the canonical traversal (`:3120`), the crossing predicate `field_aligned_segments_properly_cross` (`:2753`) and `field_aligned_segment_exit_point` (`:2893`). Rounding at the assignments would make each replayed exit differ from the next segment's entry. The only correct site is inside the resolver, where `EdgeExit` is built (`:680`). Vertex hits (`:675`, `:705`) and grazing transits (`:1996`) already publish exact endpoints. |
| R2 | New typed failure `ContinuationDyadicEndpointCollapse` for an interior exit that rounds to 0 or 1 | **Would add false failures.** HEAD's exact arithmetic already produces interior exits within 2⁻⁵³ of a vertex: 12 on the prescribed sphere (rows 688/699; t ≈ 5.6·10⁻¹⁸ to 1−1.1·10⁻¹⁶; widths 3,006–12,243 bits, several under the 4,096 cap). The dyadic run produces 1. Restricting `n` to `[1, 2⁵²−1]` keeps an interior exit interior, with no new failure. |
| R3 | "Same undirected canonical orientation in both faces" | **Vacuous.** `FieldBoundaryPoint` is already an undirected `SourceEdgeTopologyKey` plus the parameter of `edge.second()`, shared by both incident faces. |
| R4 | Pre-arithmetic direction-complexity certificate; certified field-deviation contract; exact separation/adjacency certificate; quantization-ambiguity error; policy-version receipts; oracle provenance check | **Undefined and unneeded; withdrawn.** A separation certificate needs the unrounded trajectory, which the construction discards. There is one representation, so there is no provenance to carry. `\|q − t\| ≤ 2⁻⁵³` follows from the construction and needs no runtime check. Measured rounding inputs reach at most 271 bits (gate) and 267 (Vase), so per-step arithmetic is already bounded. Existing exact predicates decide crossing, contact, barrier, vertex and recurrence on the published geometry. |
| R5 | "Vase is not pre-declared PASS"; no probe | **Probes give the exact outcome** (RA-190.3), so TB64 can pre-register it. |
| R6 | CB65 as open-ended design, implementation and test authoring | **Monolithic.** Replaced by the exact patch in RA-190.8. |
| R7 | TB64 on the 864-row manifest | **Would fail membership.** CB65 adds two tests (membership 945 → 947), so P8 needs the 866-row manifest in RA-190.6. |

## RA-190.3 Probe findings (macOS, scratch build, diagnostic only)

| Probe | Result |
|---|---|
| 864-row candidate gate, dyadic | **863/864.** Only row 283 (O16) fails, and it never reaches the rounding. 74 rows exercise inexact rounding; all pass, including the prescribed-sphere census (row 669, 67,299 exits). |
| 81 deferred rows, HEAD vs dyadic | **81/81 RED in both.** 7 rows exercise rounding. Vase changes as below. Rows 191, 344 and 350 give identical output. The prescribed-sphere rows 182, 192 and 196 fail at the same stage (`surface-cut-graph/CellularityNotEstablished`, origin `RotationSystemInconsistent`) with the same per-trace terminals (14 `TraceIntersection`, 10 `SingularityTermination`, the same trace IDs). Exactly coincident trace events separate (56 → 60 events, 10 → 12 terminal intersections), so the reported failure locus moves. |
| Vase, dyadic | Passes tracing (54 s), strands, embedding, arrangement (50 s) and simplification. Then RED at completion: `SideSubdivisionRepair:InvalidInputIncidence`, with 192,482 trace segments. The terminal reads `NotProductionReady:completion detail=None`. |
| Vase, exact, uncapped | **The same failure and the same 192,482 segments** (309 exits, up to 9,131 bits; tracing 69 s). The completion defect does not come from the rounding. |
| Cylinder | No interior exits; PASS in 8 s. Unaffected. |
| CB65 final patch | Both new tests pass. Mutant M1 (`EdgeExit` publishes the exact exit) fails the edge-exit test. Mutant M2 (floor, no clamp) fails both. The 74 rounding rows and 2 new rows pass 76/76. Census: Cylinder PASS; BunnyRandom `CutTransportDomainIdentityMismatch` `cutChi=-3`; Vase `completion=SideSubdivisionRepair:InvalidInputIncidence`. Listed membership is 947 = 866 + 81, with no overlap. |

## RA-190.4 Rulings

- **Amendment 24 (rewritten):**
  - There is a single site, the `EdgeExit` construction in `resolve_field_branch_continuation`, using the open grid `n/2⁵²` with `1 ≤ n ≤ 2⁵²−1`.
  - There is no new failure code and no receipt.
  - The trace is defined by its published geometry, not by the exact integral curve. Exactly coincident events that depend on an inexact exit may separate.
  - `B` is part of the definition; changing it is a DESIGN change.
- **O15c:** discharged for A2a once TB64 matches, because every A2a-continued entry is then at most 53 bits wide. The 4,096-bit guard stays as the fail-closed backstop for entries constructed outside A2a. Termination still comes from the exact-state cycle guard, the combinatorial-recurrence guard and the step budget.
- **P13-b (Vase):** the A4 frontier is passed. The new earliest failure is **P13-d**: A7 completion side-subdivision repair rejects its input as `InvalidInputIncidence` (`SurfaceCellFeasibilityRepair.cpp:2123`). It goes to a Review DEFN after TB64.
- **O18 (new):** the completion rejection at `RemeshPipeline.cpp:14352–14357` returns without a detail code or first-invalid stage, so the terminal reads `detail=None`. CB65's test hunk exposes `completionFailure` for TB64. The product diagnostic is owned by the P13-d DEFN.
- **Prescribed-sphere event separation:** a stated consequence of Amendment 24, not a regression; the deferred rows keep their stage and origin.
- **Carried unchanged:** O9 falsifier, O6, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b.

## RA-190.5 CB65 — exact patch

`M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` (CB; implementation agent; Linux workflow runner).

| Item | Value |
|---|---|
| Precheck | `git diff --quiet d56d990580163f4fd0ceda4137f7ecd16ceb6027 HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Patch | RA-190.8 block, verbatim plus a trailing newline. SHA-256 `ed125319bb38f9ed5352c8b18b3513a53dc5e994d3e7f964d27f82341ac6f91b`. Run `git apply --check`, then apply. |
| Numstat | `26 1` `include/directional/geometry/SurfaceCellTracing.h`; `26 2` `src/geometry/SurfaceCellTracing.cpp`; `79 0` `tests/FieldAlignedCurveNetworkTests.cpp`; `2 1` `tests/SurfaceCellDesignAcceptanceTests.cpp` |
| Result SHA-256 | `.h` `6542668e53dcee5b5d13afe608dd7941026e270c0fdcbaee694a3635b47a677d`; `.cpp` `10b4532187d55c1f62dce50169d6e164f4a8141f9cd6c957093f5c2451ddd1fa`; network tests `7dff149cabc02c8862f804b532705ca5a81fbe0bc08e49e5aebaabf94fa24d18`; acceptance tests `f4105aa4772955b30574ff6200d9623a844ff70216aea1f8ef3dd9577a2e6ebf` |
| Build | `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets. Record the artifact ID, ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256. No native runs. |
| Outcomes | Exact → TB64. Patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-DYADIC-EXIT-STOP` (Review). Infrastructure → `M6-CP3-CB65A-P13-DYADIC-EXIT-ORCH` (one retry). |

## RA-190.6 TB64 — frozen inputs and pre-registered outcomes

`M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` (TB-EXEC; Linux), on the immutable CB65 package.

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB64_P13_Dyadic_Exit_Full_Gate_Case_Manifest.tsv`, **866 rows**, SHA-256 `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`. It is the 864-row candidate byte-for-byte, plus rows 865 `ra190:dyadic-exit-grid` and 866 `ra190:dyadic-edge-exit` (GUARD). `SELF_CHECK_PASS cases=866 deferred=81`. |
| Ledger | v5, 81 rows, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Census | `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` `3af1dc0d…`, no ledger, one fresh process per row |
| Harness | P8 `78b8002c…`, unchanged |

| Run | Pre-registered outcome |
|---|---|
| Gate | **866/866 PASS**, membership **947**, postflight true |
| Census row 1, Cylinder | PASS |
| Census row 2, BunnyRandom | RED `CutTransportDomainIdentityMismatch`, `cutChi=-3` |
| Census row 3, Vase | RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence` and no `BranchContinuationExactMagnitudeExceeded` |

Mismatch routes:
- Any gate RED, membership ≠ 947, or a census signature mismatch → `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-REV` (Review).
- Infrastructure → `M6-CP3-TB64A-P13-CANONICAL-DYADIC-ORCH` (one retry).

No TB64-REV is needed when everything matches.

## RA-190.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` | Implementation agent, Linux; exact patch |
| 2 | `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` | Implementation agent, Linux; gate 866 + census 3 |
| 3 (parallel with 1–2) | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (BunnyRandom, P13-c) → CB66 → TB65 | Review (probes) → implementation agent |
| 4 (after 2) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d, with O18) → CB → TB | Review (probes) → implementation agent |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | Per slice |

## RA-190.8 Exact CB65 patch

SHA-256 of the block content plus a trailing newline: `ed125319bb38f9ed5352c8b18b3513a53dc5e994d3e7f964d27f82341ac6f91b`.

Six lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the patched source itself is clean under `git diff --check`.

```diff
diff --git a/include/directional/geometry/SurfaceCellTracing.h b/include/directional/geometry/SurfaceCellTracing.h
index 200da4bc2..8b0c96ea6 100644
--- a/include/directional/geometry/SurfaceCellTracing.h
+++ b/include/directional/geometry/SurfaceCellTracing.h
@@ -1126,10 +1126,35 @@ publish_field_aligned_trace_traversal_state(
  *
  * Exceeding it is a typed rejection, never a fallback to inexact arithmetic: the
  * producer declines to answer rather than answering approximately, so no
- * topological outcome is ever decided by a magnitude.
+ * topological outcome is ever decided by a magnitude. Since DESIGN.md
+ * Amendment 24 an entry published by A2a is at most 53 bits wide, so the policy
+ * binds only on an entry constructed outside A2a.
  */
 inline constexpr std::size_t kFieldExactContinuationMagnitudeBits = 4096U;
 
+/**
+ * @brief Fractional bits of the grid on which A2a publishes an interior exit.
+ *
+ * An exact exit composed face after face widens by the width of each face's
+ * direction (RA-188: about 200 bits per face on the vase), so a long trace
+ * outgrows any fixed magnitude policy. DESIGN.md Amendment 24 publishes each
+ * interior edge exit as n / 2^52 instead, which bounds the next entry at 53
+ * bits however many faces the trace has crossed.
+ */
+inline constexpr unsigned kFieldDyadicExitFractionBits = 52U;
+
+/**
+ * @brief The interior exit parameter A2a publishes for an exact interior exit.
+ *
+ * Returns n / 2^52 for the integer n nearest to 2^52 * parameter, ties to even,
+ * restricted to 0 < n < 2^52. The open grid keeps an interior exit interior:
+ * a vertex hit is decided exactly before this point and is never created or
+ * removed here. Integer arithmetic only. Requires 0 < parameter < 1.
+ */
+[[nodiscard]] authority::FieldExactRational
+field_dyadic_interior_exit_parameter(
+    const authority::FieldExactRational &parameter);
+
 [[nodiscard]] FieldBranchExitTimeOrdering compare_field_branch_exit_times(
     const authority::FieldExactRational &firstPosition,
     const authority::FieldExactRational &firstNegativeDirection,
diff --git a/src/geometry/SurfaceCellTracing.cpp b/src/geometry/SurfaceCellTracing.cpp
index c90a56ed0..1c9e19e8f 100644
--- a/src/geometry/SurfaceCellTracing.cpp
+++ b/src/geometry/SurfaceCellTracing.cpp
@@ -530,6 +530,24 @@ FieldBranchExitTimeOrdering compare_field_branch_exit_times(
   return FieldBranchExitTimeOrdering::Equal;
 }
 
+authority::FieldExactRational field_dyadic_interior_exit_parameter(
+    const authority::FieldExactRational &parameter) {
+  const EInt scale = authority::FieldExactRational::from_integer(
+                         std::int64_t{1} << kFieldDyadicExitFractionBits)
+                         .exact_numerator();
+  const EInt scaled = parameter.exact_numerator() * scale;
+  const EInt denominator = parameter.exact_denominator();
+  EInt nearest = scaled / denominator;
+  const EInt twiceRemainder = (scaled - nearest * denominator) * EInt(2);
+  const bool odd = nearest - (nearest / EInt(2)) * EInt(2) == EInt(1);
+  if (twiceRemainder > denominator || (twiceRemainder == denominator && odd)) {
+    nearest = nearest + EInt(1);
+  }
+  if (nearest < EInt(1)) nearest = EInt(1);
+  if (nearest > scale - EInt(1)) nearest = scale - EInt(1);
+  return *authority::FieldExactRational::from_exact_fraction(nearest, scale);
+}
+
 FieldBranchContinuationResult resolve_field_branch_continuation(
     const authority::SourceFaceTopologyKey &sourceFace,
     const authority::FieldBranchBoundaryPairing &pairing,
@@ -676,9 +694,15 @@ FieldBranchContinuationResult resolve_field_branch_continuation(
             vertexSupport->vertex};
       }
     }
+    // Amendment 24: publish the interior exit on the dyadic grid, so the next
+    // face's entry width does not grow with the length of the trace.
     return FieldBranchContinuationDecision{
-        FieldBranchContinuationKind::EdgeExit, *exitPoint, outgoing,
-        std::nullopt};
+        FieldBranchContinuationKind::EdgeExit,
+        authority::FieldBoundaryPoint{
+            outgoing, authority::ExactUnitParameter{
+                          field_dyadic_interior_exit_parameter(
+                              exitPoint->parameter.value)}},
+        outgoing, std::nullopt};
   }
 
   std::sort(minimizingEdges.begin(), minimizingEdges.end());
diff --git a/tests/FieldAlignedCurveNetworkTests.cpp b/tests/FieldAlignedCurveNetworkTests.cpp
index 2f68eb947..ad5883a38 100644
--- a/tests/FieldAlignedCurveNetworkTests.cpp
+++ b/tests/FieldAlignedCurveNetworkTests.cpp
@@ -16018,6 +16018,85 @@ TEST(ResolvedBranchCorrection,
   EXPECT_EQ(boundary_point(outgoing, 1, 4), decision->exitPoint);
 }
 
+TEST(ResolvedBranchCorrection,
+     DyadicInteriorExitIsNearestOpenGridPointTiesToEven) {
+  using namespace directional::geometry::surface_cell_tracing_detail;
+  constexpr std::int64_t kGrid = std::int64_t{1} << 52;
+  ASSERT_EQ(52U, kFieldDyadicExitFractionBits);
+
+  // A grid value is published unchanged; 1/3 goes to the nearest grid point.
+  EXPECT_EQ(exact_ratio(3, 8),
+            field_dyadic_interior_exit_parameter(exact_ratio(3, 8)));
+  EXPECT_EQ(exact_ratio(1501199875790165, kGrid),
+            field_dyadic_interior_exit_parameter(exact_ratio(1, 3)));
+  EXPECT_LE(field_dyadic_interior_exit_parameter(exact_ratio(1, 3))
+                .magnitude_bits(),
+            53U);
+
+  // Exact halfway points go to the even neighbour: 5.5 -> 6 and 6.5 -> 6.
+  EXPECT_EQ(exact_ratio(6, kGrid), field_dyadic_interior_exit_parameter(
+                                       exact_ratio(11, kGrid * 2)));
+  EXPECT_EQ(exact_ratio(6, kGrid), field_dyadic_interior_exit_parameter(
+                                       exact_ratio(13, kGrid * 2)));
+
+  // An interior value nearer an endpoint than half a grid step stays interior.
+  constexpr std::int64_t kFine = std::int64_t{1} << 60;
+  EXPECT_EQ(exact_ratio(1, kGrid),
+            field_dyadic_interior_exit_parameter(exact_ratio(1, kFine)));
+  EXPECT_EQ(exact_ratio(kGrid - 1, kGrid),
+            field_dyadic_interior_exit_parameter(exact_ratio(kFine - 1, kFine)));
+}
+
+TEST(ResolvedBranchCorrection, EdgeExitPublishesBoundedDyadicInteriorParameter) {
+  using namespace directional::geometry::surface_cell_tracing_detail;
+  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
+  const SourceEdgeTopologyKey incoming = topology_edge(0, 1);
+  const SourceEdgeTopologyKey outgoing = topology_edge(1, 2);
+  // Entry parameter p on (0,1) exits (1,2) exactly at (1 - p) / 2.
+  const auto pairing = continuation_pairing({-2, 1, 1}, {outgoing, incoming});
+  const auto exit_for = [&](const directional::authority::FieldExactRational &p)
+      -> std::optional<FieldBranchContinuationDecision> {
+    const auto resolved = resolve_field_branch_continuation(
+        face, pairing,
+        directional::authority::FieldBoundaryPoint{
+            incoming, directional::authority::ExactUnitParameter{p}});
+    const auto *decision =
+        std::get_if<FieldBranchContinuationDecision>(&resolved);
+    return decision == nullptr
+               ? std::nullopt
+               : std::optional<FieldBranchContinuationDecision>{*decision};
+  };
+
+  // The exact exit 1/3 is published as its grid point, not as 1/3.
+  const auto third = exit_for(exact_ratio(1, 3));
+  ASSERT_TRUE(third.has_value());
+  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, third->kind);
+  EXPECT_EQ(outgoing, third->exitPoint.edge);
+  EXPECT_EQ(field_dyadic_interior_exit_parameter(exact_ratio(1, 3)),
+            third->exitPoint.parameter.value);
+  EXPECT_NE(exact_ratio(1, 3), third->exitPoint.parameter.value);
+
+  // A wide entry under the magnitude policy (3^-2048, about 3,250 bits) has
+  // an exact exit just as wide; the published exit is the grid point 1/2.
+  auto wide = exact_ratio(1, 3);
+  for (int squaring = 0; squaring < 11; ++squaring) wide = wide * wide;
+  ASSERT_GT(wide.magnitude_bits(), 3000U);
+  ASSERT_LE(wide.magnitude_bits(), kFieldExactContinuationMagnitudeBits);
+  const auto narrowed = exit_for(wide);
+  ASSERT_TRUE(narrowed.has_value());
+  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, narrowed->kind);
+  EXPECT_EQ(exact_ratio(1, 2), narrowed->exitPoint.parameter.value);
+
+  // An exit 2^-61 from vertex 1 is still an edge exit, never a vertex hit.
+  constexpr std::int64_t kFine = std::int64_t{1} << 60;
+  const auto nearVertex = exit_for(exact_ratio(kFine - 1, kFine));
+  ASSERT_TRUE(nearVertex.has_value());
+  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, nearVertex->kind);
+  EXPECT_FALSE(nearVertex->sourceVertex.has_value());
+  EXPECT_EQ(exact_ratio(1, std::int64_t{1} << 52),
+            nearVertex->exitPoint.parameter.value);
+}
+
 TEST(M4CPScaleS1,
      ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral) {
   using namespace directional::geometry::surface_cell_tracing_detail;
diff --git a/tests/SurfaceCellDesignAcceptanceTests.cpp b/tests/SurfaceCellDesignAcceptanceTests.cpp
index 3ebd635ac..92efd233b 100644
--- a/tests/SurfaceCellDesignAcceptanceTests.cpp
+++ b/tests/SurfaceCellDesignAcceptanceTests.cpp
@@ -43,7 +43,8 @@ std::string failure_context(const directional::pipeline::RemeshResult &result) {
          " arrangementCells=" +
          std::to_string(result.diagnostics.surfaceCellArrangementCellCount) +
          " completedQuads=" +
-         std::to_string(result.diagnostics.surfaceCellCompletedQuadCount);
+         std::to_string(result.diagnostics.surfaceCellCompletedQuadCount) +
+         " completion=" + result.surfaceCellContext.completionFailure;
 }
 
 
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB58 `31c1360a…`, the 864 candidate `b50463ea…` (prefix byte-identical), ledger v5 `fd433f54…` (v4 minus 362) and the new 866 manifest `289d887c…` all self-check |
| Decisive claims independently re-derived | Probes, not static reading. Gate run under the change. Deferred rows compared between HEAD and dyadic mode. Vase run both exact-uncapped and dyadic. Membership listed from the built binaries |
| Non-vacuity checked | 74 gate rows plus 7 deferred rows exercise inexact rounding. Both new tests fail under mutants M1/M2 and pass on CB65 |
| Prior obligations discharged/carried | RA-189 R1–R7 ruled. O15c discharged once TB64 matches. P13-d and O18 new. O6, O9, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-d (Vase completion incidence), O18 (completion rejection publishes no detail) |
| ORIENTATION currency line | Updated to RA-190 / CB65 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 Next and §7 Immediate updated. §8 line on the dyadic exit corrected. §4: n/a, no witness change |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: a representation change belongs in the producer that every consumer replays |
| Consolidation under CLEAN_UP_POLICY | n/a: RA-189 stays as history; its 864 manifest is kept as the prefix of the 866 |
| Successor frozen | CB65 (RA-190.5); TB64 falsifiers (RA-190.6) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran only in scratch builds |
| `review_check.py boundary` | ALL CHECKS PASSED (see the commit) |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB65 |
| Pushed to origin, branch in sync | Confirmed after the push |
