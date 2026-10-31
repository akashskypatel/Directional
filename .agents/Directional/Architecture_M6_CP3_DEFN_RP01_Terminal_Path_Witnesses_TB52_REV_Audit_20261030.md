# RA-178 — TB52-REV audit and RP-01 terminal-path witness definition (2026-10-30)

**Turn:** `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` (DEFN, Review track). This record also audits [RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md). Native probes are diagnostic only (GMP_COMPILE_POLICY); they are not gate evidence. HEAD `690d6865d`; `src/`, `include/`, `tests/` and CMake are identical to CB52 source `7cf0857b…`.

## RA-178.1 RA-177 audit

- **Evidence re-verified.** Result `13004891149` ZIP SHA-256 `ba180165…` matches; 1,714/1,714 inner checksums verify; `execution-boundary.json` shows 853/853/853, postflight true, `membership=939`; `membership.tsv` has 853 GATED + 86 DEFERRED. RA-177's disposition (TB52 is the reviewed 853/0 candidate; no selector497 or CP3 promotion) is correct.
- **F1 — RA-177 carried a row that cannot be repaired (major, design).** Row 261 targets the A4 producer predicate `missing-terminal-A3-path`. RA-170.3 P1-a had already ruled that predicate accepted-defensive under C1 (no produced input reaches it), and O4 forbids production fault-injection seams. "Repair 261 without weakening" therefore had no valid exit. RA-174.3 introduced the conflict and RA-177 repeated it. Resolved in RA-178.3.
- **F2 — the recorded cause for 223 was imprecise (minor).** RA-172 called 223 a "cover-invalid negative". The checked factory actually rejects its stimulus at `gauge-pin-span` (`SurfaceCellTracing.cpp:8595`), which runs before `open-rail-cover`. Each region of the 3×3 rail source is a dual-graph tree, so any extra barrier disconnects it.
- **F3 — the CB successor was left open (sequencing).** RA-177 allowed `UNKNOWN` as the DEFN's exit, contrary to RA-164. CB54 is frozen here.

## RA-178.2 Probe evidence

The scratch build was arm64 Release at HEAD (GMP, tests ON). The patched rows were rerun with `FieldTransportAtlas.cpp` compiled with `-ffp-contract=off` to emulate Linux, with the same result.

- **All three rows reproduce the CI first failure:**
  - 225 fails at `:9932` (`terminalVertex` absent);
  - 223 fails at `:10350` (no detail);
  - 261 fails at `SurfaceCellsPhase10Tests.cpp:8325` (the diagnostic lacks `missing-terminal-A3-path`).
- **Endpoint inventory of `nonconstant_hard_rail_fixture()`.** It has one rail (id 2, chain 1-4-7) and 10 single-step routes. The endpoints are:
  - **T** at vertex 1, with a one-step contact path via (1,5);
  - **T** at vertex 7, with empty paths;
  - two **R** endpoints at vertex 4, each with a two-step path;
  - 16 **I** endpoints.

  225's premise that every endpoint is T predates RA-84.
- **223 stimulus.** Promoting a required spoke to a hard edge is rejected at `gauge-pin-span;region=1` with no detail. This holds for:
  - an orphan edge;
  - a C1-valid new rail `[v,w]` with its own contact and chain;
  - all three spokes on `hard_rail_fixture()`.

  `MissingTerminalA3Path` is unreachable on the 3×3 source by this route.
- **C1-valid witness.** Move one T-endpoint attachment to the carrier face across the rail, at the same exact vertex point. The front-edge trace point and the certificate attachment move together; hard edges, chains and contacts are unchanged. This gives `endpoint-a3-path;…;kind=T` with `MissingTerminalA3Path` for both sides.
- **223's later sections never ran in CI,** because the `:10350` ASSERT aborted first. Run here, they reject as written: the omitted path at `endpoint-contact-target`, the forged transport at `endpoint-contact-path`.
- **261 stimulus.** It passes no terminal contacts, so A4 rejects for missing provenance (`a2bProbeFailure=missing-terminal-or-closed-rail-provenance`). With contacts, the same stimulus is gated row 507 (`OrphanHardFeatureEdgeRejectsBeforeA4Consumer`), which rejects at `orphan-hard-feature-edge`.
- **Producer reachability.** The full pipeline was run with one extra genuine rail: {1,5}, {4,8}, {0,4}, {4,5}, {3,4}, and {3,4}+{4,5}.
  - A4 never reports `missing-terminal-A3-path`.
  - Three variants produce, with rails meeting at vertex 4.
  - The others reject earlier (`InvalidFrontBoundaryAuthority`, `InvalidBoundedDiskBoundaryPhase`).
- **O9.** Target ratios 0.2–2.5 on the rail fixture, plus the extra-rail variants above, all give single-step routes and zero junctions. The torus fixture publishes no hard-rail routes.

## RA-178.3 Dispositions and O9 ruling

| Row | Class | Disposition |
|---|---|---|
| 225 | FIXTURE | **Repair.** The oracle classifies T/R/I (RA-84) and checks each class's contract. It requires a nonempty germ at a T endpoint and at an R endpoint, and at least one I endpoint. |
| 223 | FIXTURE | **Repair.** The barrier stimulus becomes an explicit `gauge-pin-span` negative. `MissingTerminalA3Path` is now reached by the C1-valid wrong-sector stimulus, with the site pinned to `endpoint-a3-path;`. The test is strictly stronger. |
| 261 | OPEN | **Retire (delete).** Its target is accepted-defensive; its stimulus duplicates gated row 507; the guard's meaning is witnessed at the checked factory by 223. Membership goes from 939 to 938. |

- **The producer predicate `missing-terminal-A3-path` is accepted-defensive.** No produced input reaches it, and O4 forbids fault seams. The factory `MissingTerminalA3Path` guard is witnessed by 223.
- **O9 is removed from RP-01, with this reason.** The A4 junction-certificate path (producer `SurfaceCellTracing.cpp:20454–20648`, factory `:9088–9216`) has no produced input, because every produced open-rail route is single-carrier (D2). The code is kept: closed-rail routes are unprobed, so it is not deleted in CP3.
  - **Falsifier:** any produced route with `oriented_steps().size() > 1`. The slice that produces it must then witness the junction path.
  - **Owner:** the P13 probe DEFN checks the maximum route steps on each matrix fixture.
- **RP-01 closes at TB53-REV** if TB53 passes 855/855 with `membership=938`.
- **Observation, no new obligation.** A diagonal user rail {1,5} on the 3×3 rectangle rejects at `InvalidFrontBoundaryAuthority` with an empty diagnostic. This is input capability (O6-adjacent), not RP-01.

## RA-178.4 CB54 — exact patch

**Turn:** `M6-CP3-CB54-RP01-TERMINAL-PATH-WITNESSES` (CB, I). Code + Build only, compile-only.
- **Scope:** tests only.
  - `tests/SurfaceCellTransitionQuotientTests.cpp`: the 225 oracle and the 223 wrong-sector witness.
  - `tests/SurfaceCellsPhase10Tests.cpp`: delete 261.
  - No production, fixture, CMake, workflow, manifest or ledger change.
- **Checks:**
  - Extract the `~~~diff` block below verbatim, adding a trailing newline. Its SHA-256 must be `16a64128ff3ab2279620686af60d0278e4620e463dfebd132f4a4f535fb8a75d`.
  - `git apply --check`, then `git apply`. The numstat must be exactly `90 17` (TQ) and `0 46` (Phase10).
  - The resulting SHA-256 must be `895ef38db563168542666d369659fb53b0518c5cfcb90823497d39c4e9703768` for the TQ file and `de0dd49a4adafe4ff71303fd1cec190c1c2e0be48781cfda0b481cb8027b2645` for the Phase10 file.
  - The GMP compile of the eight approved targets succeeds, with the package published. Do not run native tests.

| CB54 result | Successor |
|---|---|
| All exact, package published | `M6-CP3-TB53-RP01-FULL-GATE-EXEC` |
| Patch, SHA, numstat or compile mismatch | `M6-CP3-PLAN-RP01-TERMINAL-WITNESS-STOP` (PLAN, R) |
| Dispatcher or infrastructure failure | `M6-CP3-CB54A-RP01-ORCH`, then one retry |

## RA-178.5 TB53 frozen inputs

- **Package:** the CB54 package (artifact ID recorded by CB54). Harness `78b8002c…`, unchanged.
- **Gate:** [`Architecture_M6_CP3_TB53_RP01_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB53_RP01_Full_Gate_Case_Manifest.tsv), 855 rows, SHA-256 `5239f81ad7f046c1c318c9b503d710020cb72d73a4534cab9ac99e00439b17ab`.
  - The first 854 lines are byte-identical to TB52 (`95a7af66…`).
  - Row 854 is `GUARD offgate:223`; row 855 is `GUARD offgate:225`.
- **Ledger v3:** [`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv`](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv), 83 rows, SHA-256 `32b43fc5415c6811a8de1e8934b0e0361a84ab689ed76dc1cfa9b84d4663be78`.
  - It is ledger v2 minus census rows 223, 225 and 261, in order.
  - Classes: FIXTURE 48 / PRODUCT 7 / OPEN 23 / RETIRE 5.
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=855 deferred=83`; `--self-test` gives 30. A membership simulation (the TB52 listing minus 261) gives 938 = 855 + 83, with zero ungoverned and zero stale tests.

| TB53 result | Successor |
|---|---|
| 855/855 PASS, postflight true, `membership=938` | `M6-CP3-TB53-RP01-FULL-GATE-REV` (TB-REV, R); RP-01 closes if accepted |
| P8 membership error before any native row | `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP` (PLAN, R) |
| Any non-PASS | TB53-REV classifies it; no retry |
| Dispatcher failure | `M6-CP3-CB54A-RP01-ORCH`, then `M6-CP3-TB53-RP01-FULL-GATE-EXEC-R2` |

## RA-178.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CP3-CB54-RP01-TERMINAL-PATH-WITNESSES` | CB / I | Exact patch, package |
| then | `M6-CP3-TB53-RP01-FULL-GATE-EXEC` | TB-EXEC / I | 855, ledger v3 83, membership 938 |
| then | `M6-CP3-TB53-RP01-FULL-GATE-REV` | TB-REV / R | RP-01 closes |
| R∥ | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` → CB55 → CB56 → TB54 → TB54-REV | DEFN / R; CB, TB / I | O15 (RA-176.3); row 935 moves to the gate (ledger v4, 82) |
| then | P13 probe DEFN (Cylinder first; exact-atlas check and max-route-step check first) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs → CP3-REV | per slice | RA-174.3 + RA-176.3 + RA-178.3 |

## RA-178.7 Exact CB54 patch

~~~diff
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index 94dbe4f1d..219b20eb9 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -9922,21 +9922,46 @@ TEST(M6CP3, TerminalRailContactPathsUseTypedSourceStarA3) {
   ASSERT_TRUE(fixture.fieldTransportAtlas.has_value());
   const auto &atlas = *fixture.fieldTransportAtlas;
   const auto &topology = front.sourceTopologyRegions();
-  int attestedContacts = 0;
-  int nonemptySidePaths = 0;
+  // RA-84 endpoint classes: T is a chain terminal, R a strict interior chain
+  // vertex, I an interior carrier point. T and R own an A2b source-star germ
+  // around their vertex; I owns none.
+  int terminalPaths = 0;
+  int railVertexPaths = 0;
+  int interiorEndpoints = 0;
   for (const auto &route : front.hardRailRouteCertificates()) {
     const auto found = front.hardRailTerminalContacts().find(route.rail);
     if (found == front.hardRailTerminalContacts().end()) continue;
+    const auto chain = front.hardRailOpenChains().find(route.rail);
+    ASSERT_NE(chain, front.hardRailOpenChains().end());
     ASSERT_EQ(route.junctions.size() + 1U, route.route.oriented_steps().size());
     for (const auto &endpoint : route.endpoints) {
-      ASSERT_TRUE(endpoint.terminalVertex.has_value());
-      const auto vertex = *endpoint.terminalVertex;
-      EXPECT_TRUE(vertex == found->second.endpoints[0] ||
-                  vertex == found->second.endpoints[1]);
+      ASSERT_FALSE(endpoint.terminalVertex && endpoint.railVertex);
+      if (!endpoint.terminalVertex && !endpoint.railVertex) {
+        EXPECT_TRUE(endpoint.contactPaths[0].empty());
+        EXPECT_TRUE(endpoint.contactPaths[1].empty());
+        EXPECT_EQ(endpoint.terminalCarrier.firstFace, endpoint.firstAttachment);
+        EXPECT_EQ(endpoint.terminalCarrier.secondFace, endpoint.secondAttachment);
+        ++interiorEndpoints;
+        continue;
+      }
+      const auto vertex = endpoint.terminalVertex ? *endpoint.terminalVertex
+                                                  : *endpoint.railVertex;
+      EXPECT_EQ(endpoint.terminalVertex.has_value(),
+                vertex == found->second.endpoints[0] ||
+                    vertex == found->second.endpoints[1]);
+      if (endpoint.railVertex) {
+        const auto &vertices = chain->second.vertices;
+        const auto position = std::find(vertices.begin(), vertices.end(), vertex);
+        EXPECT_TRUE(position != vertices.end() && position != vertices.begin() &&
+                    position + 1 != vertices.end());
+      }
+      EXPECT_TRUE(endpoint.terminalCarrier.edge.first() == vertex ||
+                  endpoint.terminalCarrier.edge.second() == vertex);
       for (std::size_t side = 0U; side < 2U; ++side) {
         auto at = side == 0U ? endpoint.firstAttachment : endpoint.secondAttachment;
         const auto &steps = endpoint.contactPaths[side];
-        if (!steps.empty()) ++nonemptySidePaths;
+        if (!steps.empty())
+          ++(endpoint.terminalVertex ? terminalPaths : railVertexPaths);
         for (const auto &step : steps) {
           EXPECT_EQ(at, step.firstFace);
           EXPECT_TRUE(step.edge.first() == vertex || step.edge.second() == vertex);
@@ -9954,11 +9979,11 @@ TEST(M6CP3, TerminalRailContactPathsUseTypedSourceStarA3) {
         EXPECT_EQ(at, side == 0U ? endpoint.terminalCarrier.firstFace
                                   : endpoint.terminalCarrier.secondFace);
       }
-      ++attestedContacts;
     }
   }
-  EXPECT_GT(attestedContacts, 0) << "A2b terminal ownership must be produced";
-  EXPECT_GT(nonemptySidePaths, 0) << "A2b must actually transport a nonrail terminal germ";
+  EXPECT_GT(terminalPaths, 0) << "A2b must transport a nonrail germ at a T endpoint";
+  EXPECT_GT(railVertexPaths, 0) << "A2b must transport a nonrail germ at an R endpoint";
+  EXPECT_GT(interiorEndpoints, 0) << "the fixture must produce an I endpoint";
 }
 
 TEST(M6CP3, CheckedFactoryReconstructsProducedTerminalA2bStarUniqueness) {
@@ -10330,23 +10355,71 @@ TEST(M6CP3, CheckedFactoryRejectsForgedTerminalA2bSideGerm) {
   expect_phase_front_product_error(
       checked_with_routes_and_contacts(original, foreignContact, front.hardFeatureEdges()), expected);
 
-  // Remove exactly one independently produced non-hard A3 terminal spoke
-  // from admissible star transport by marking it as a barrier. Unlike
-  // modifying the certificate attachment, this preserves the source-owned
-  // front-face equality checks and reaches the actual missing-path guard.
-  // RA-46 establishes uniqueness, so severing a genuine required step
-  // leaves no alternate non-hard A3 route to the hard carrier.
+  // A required non-hard spoke promoted to a barrier is not a C1-valid
+  // stimulus. On this 3x3 source each region's non-hard dual graph is a tree,
+  // so the checked factory rejects the torn gauge span before any source-star
+  // path check (RA-178).
   const auto blockedSpoke =
       original[route].endpoints[endpoint].contactPaths[side].front().edge;
   auto blockedHardEdges = front.hardFeatureEdges();
   ASSERT_FALSE(blockedHardEdges.contains(blockedSpoke));
   blockedHardEdges.insert(blockedSpoke);
-  const auto unreachableResult = checked_with_routes_and_contacts(
+  const auto tornResult = checked_with_routes_and_contacts(
       original, front.hardRailTerminalContacts(), blockedHardEdges);
+  const auto *tornError = std::get_if<
+      directional::geometry::SurfacePhaseFrontProductError>(&tornResult);
+  ASSERT_NE(nullptr, tornError);
+  EXPECT_EQ(expected, tornError->code);
+  EXPECT_FALSE(tornError->sourceAuthorityDetail.has_value());
+  EXPECT_EQ(0U, tornError->sourceAuthoritySite.rfind("gauge-pin-span;", 0))
+      << describe_phase_front_product_error(*tornError);
+
+  // Keep every hard edge, chain and contact intact; move one T-endpoint trace
+  // attachment to the source face across the hard carrier at the same exact
+  // terminal vertex. Only the A2b sector is wrong, and the non-hard star has
+  // no path back to that side's carrier face.
+  const auto &terminal = original[route].endpoints[endpoint];
+  ASSERT_TRUE(terminal.terminalVertex.has_value())
+      << "the wrong-sector oracle requires a produced T endpoint";
+  const auto across = side == 0U ? terminal.terminalCarrier.secondFace
+                                 : terminal.terminalCarrier.firstFace;
+  const auto acrossRow = front.sourceTopologyRegions().row_for_topology(across);
+  ASSERT_TRUE(acrossRow.has_value());
+  const int acrossFace = static_cast<int>(acrossRow->index());
+  int corner = -1;
+  for (int i = 0; i < 3; ++i)
+    if (fixture.mesh.F(acrossFace, i) ==
+        static_cast<int>(terminal.terminalVertex->index()))
+      corner = i;
+  ASSERT_GE(corner, 0);
+  auto wrongSectorEdges = front.edges();
+  auto &traceEdge = wrongSectorEdges[static_cast<std::size_t>(
+      side == 0U ? original[route].firstFrontEdge
+                 : original[route].secondFrontEdge)];
+  auto &attachment = endpoint == side ? traceEdge.from : traceEdge.to;
+  attachment.face = acrossFace;
+  attachment.barycentric = Eigen::RowVector3d::Zero();
+  attachment.barycentric[corner] = 1.0;
+  auto wrongSector = original;
+  auto &moved = wrongSector[route].endpoints[endpoint];
+  (side == 0U ? moved.firstAttachment : moved.secondAttachment) = across;
+  const auto unreachableResult =
+      directional::geometry::SurfacePhaseFrontProduct::make(
+          front.gridU(), front.gridV(), front.sourceTopologyRegions(),
+          fixture.mesh.F, static_cast<std::size_t>(fixture.mesh.V.rows()),
+          &*fixture.fieldTransportAtlas,
+          front.isolationSeamTransportCertificates(), front.periodicHolonomies(),
+          front.boundedDiskBoundaryPhases(), wrongSectorEdges, front.events(),
+          front.cells(), front.conformityPlanReceipt(), front.hardFeatureEdges(),
+          front.sourceFaceBranchRotations(), front.hardRailFieldTransitions(),
+          wrongSector, front.hardRailTerminalContacts(),
+          front.hardRailClosedChains(), front.hardRailOpenChains());
   const auto *unreachableError = std::get_if<
       directional::geometry::SurfacePhaseFrontProductError>(&unreachableResult);
   ASSERT_NE(nullptr, unreachableError);
   EXPECT_EQ(expected, unreachableError->code);
+  EXPECT_EQ(0U, unreachableError->sourceAuthoritySite.rfind("endpoint-a3-path;", 0))
+      << describe_phase_front_product_error(*unreachableError);
   ASSERT_TRUE(unreachableError->sourceAuthorityDetail.has_value());
   EXPECT_EQ(directional::geometry::SurfacePhaseFrontSourceAuthorityDetail::
                 MissingTerminalA3Path,
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index 45034d120..4dc7f07fb 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -8285,52 +8285,6 @@ TEST(SurfaceCellAuthorityContractCutover,
                 "a2bProbeFailure=ambiguous-terminal-contact"));
 }
 
-// RA-46.5: sever one actual non-hard source-star step that a produced
-// terminal certificate needs. The A4 consumer must reject before the later
-// checked-factory MissingTerminalA3Path check can run. Execution is deferred.
-TEST(SurfaceCellAuthorityContractCutover,
-     MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate) {
-  const auto fixture = build_rectangular_hard_rail_phase_front();
-  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
-            fixture.network.phaseFront.disposition())
-      << hard_rail_first_failure_detail(fixture.network);
-  const auto &front = fixture.network.phaseFront.product();
-  std::optional<directional::authority::SourceEdgeTopologyKey> neededSpoke;
-  for (const auto &route : front.hardRailRouteCertificates()) {
-    for (const auto &endpoint : route.endpoints) {
-      for (const auto &path : endpoint.contactPaths) {
-        if (!path.empty() && !neededSpoke.has_value())
-          neededSpoke = path.front().edge;
-      }
-    }
-  }
-  ASSERT_TRUE(neededSpoke.has_value())
-      << "the consumer oracle requires a produced non-hard terminal A3 step";
-  auto blocked = fixture.hardFeatureEdges;
-  ASSERT_TRUE(blocked.insert(*neededSpoke).second)
-      << "the selected source-star step must originally be non-hard";
-
-  const auto rejected = build_fixed_plan_rectangular_hard_rail_network(
-      fixture, 1.0, nullptr, &blocked);
-  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
-            rejected.phaseFront.disposition());
-  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
-                InvalidHardRailRouteCertificate,
-            rejected.phaseFront.rejection_reason());
-  const auto *failure = rejected.phaseFront.rejection();
-  ASSERT_NE(failure, nullptr);
-  EXPECT_EQ(directional::geometry::SurfaceHardRailRouteFailureLocus::
-                EndpointAttachment,
-            failure->hardRailRouteLocus);
-  EXPECT_NE(std::string::npos,
-            failure->hardRailRouteDiagnostic.find(
-                "a2bProbeFailure=missing-terminal-A3-path"))
-      << failure->hardRailRouteDiagnostic;
-  EXPECT_EQ(std::string::npos,
-            failure->hardRailRouteDiagnostic.find(
-                "a2bProbeFailure=no-exact-terminal-corner"));
-}
-
 // RA-169 C1: a hard-feature edge outside every published rail chain is a
 // torn A2b set. Network ingress rejects it before any A4 consumer reads it;
 // the same full provenance without the orphan still produces.
~~~
