# RA-169 — TB49-REV closed on authentic history; C1 rail-cover DEFN with exact CB50/CB50F patches; O4/O5 DEFN split (2026-10-28)

**Turns:** this record completes `M6-CP3-TB49-RP01-FULL-GATE-REV` (type **TB-REV**) and the Review-track DEFN `M6-CP3-DEFN-RP01-C1-ORPHAN-HARD-EDGE-COVER` (type **DEFN**). The latter was split out of the monolithic `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE`, which is superseded.

**Decision:**
- The TB49-REV blocker was procedural: authentic Git history was missing from the reviewer's snapshot. The full-history checks run here all pass, so **TB49-REV is COMPLETE**. The TB49 candidate is 504/0, and CP3 is not promoted.
- **RA-162 C1 is real and slightly wider than RA-162 stated.**
  - The checked factory accepts an orphan hard edge whenever open rails exist.
  - The network builder runs the A4 consumer on the raw, unchecked rail authority. A torn set therefore surfaces as a misleading A2b/A3 diagnostic, which is the history of 8219.
- Two exact patches are authorized, one per CB: **P3** (ingress) and **P4** (factory). They are followed by a full gate, **TB50** (508 rows).
- The rest of the O4/O5 bundle becomes three narrowly scoped Review DEFNs.

**Basis:** scratch probes on a local GMP build of HEAD `5940e02f6`. These are diagnostic only, not gate authority.

## RA-169.1 TB49-REV closeout (authentic history)

- `review_check.py boundary` on the synced branch printed **ALL CHECKS PASSED**:
  - every selector hash matches HEAD;
  - the rewrite baseline `8b7299b43` exists and is an ancestor;
  - durable sections are preserved 4/4 (handoff), 1/1 (ORIENTATION) and 0/0 (tracker).
- `review_check.py ledgers --base 1399da715`: the append-only scan of `8b7299b43..HEAD` printed **ALL CHECKS PASSED**.
- **CB bytes:** applying RA-168 P1 then P2 to `1399da715` reproduces the HEAD blobs exactly:
  - `RemeshPipeline.cpp` `1ec7a047…`;
  - TQ `12bcc36c…`.
- `git diff 1399da715..HEAD` touches only those two source/test files. There is no benchmark, workflow, script or fixture change.
- `document_drift_audit.py` reported 0 errors and 1 warning (ORIENTATION at 24,095 bytes). This turn trims ORIENTATION back under budget.
- **Adjudication of TB49-REV:** its evidence work (1014/1014, 28/28, 504 joins, 491-line prefix) and its G3/E2 non-vacuity reading are **accepted**.
- **One correction:** the successor it froze bundled four independent mechanisms (O4, O5 coverage, P1-a, P1-b, plus C1) into one DEFN and one CB50. That turn would be untestable as a unit, so RA-169.8 splits it.

## RA-169.2 C1 analysis (line evidence at HEAD)

- **Factory.** `SurfacePhaseFrontProduct::make` checks cover only when `hardRailTerminalContacts` is empty (`SurfaceCellTracing.cpp:8712`). `hard_rail_open_chains_valid` (`:8394`) checks only chain ⊆ hard.
- **Masking.** `gauge-pin-span` (`:8595`) rejects any hard edge that disconnects a source region. That is why every 3×3 rail fixture hid C1: each of its regions is a dual-graph tree. On the produced torus (one region, 6 open rails and 1 closed rail), an interior non-hard edge that touches no rail vertex is **accepted at HEAD**.
- **Ingress.** `build_surface_cell_network` copies the options and runs `build_uniform_phase_front_state` and the A4 consumers (`:19378` onwards) before the factory runs. A torn set reaches `endpoint_certificate` and is reported as `InvalidHardRailRouteCertificate` / EndpointAttachment, a wrong first site. 8219's TB44 RED is that symptom.
- **Production cannot trip either check.** `hard_feature_edge_keys_from_rails` and `hard_rail_source_provenance_from_rails` (`RemeshPipeline.cpp:10001`, `:10026`) derive both sets from the same rails.

## RA-169.3 Decisions

- **D1 — ingress.** Once any open or closed chain is published, every hard-feature edge must lie on a chain.
  - The check runs before `build_uniform_phase_front_state`.
  - It fails `InvalidFrontBoundaryAuthority` with the exact diagnostic `firstPredicate=orphan-hard-feature-edge;edge=a,b`.
  - Chain-free hard sets are deliberately left to their existing sites, so 7614's `missing-terminal-or-closed-rail-provenance` is unchanged.
- **D2 — checked factory.** Exact cover: (closed ∪ open chain edges) == `hardFeatureEdges`.
  - The site is `closed-rail-cover` when there are no contacts (existing semantics) and `open-rail-cover` otherwise.
- **D3 — an orphan hard edge is never a legitimate barrier.** Non-rail barriers already have typed channels: relief barriers, isolation seams, and O10's non-hard isolation-barrier producer. C1 is therefore fail-closed, not a licence.

## RA-169.4 Probe evidence

- With P3+P4:
  - `OrphanHardFeatureEdgeRejectsBeforeA4Consumer` passes: the untorn full-provenance network is Produced, and the torn one fails with the exact ingress diagnostic `edge=1,5`.
  - `ProducedTorusOrphanHardFeatureEdgeRejectsAtCheckedFactoryCover` passes with `open-rail-cover`.
- **Falsifiers, against HEAD production:**
  - The factory test fails at `ASSERT_NE(error, nullptr)` because the factory accepts the orphan.
  - The ingress test gets `InvalidHardRailRouteCertificate` with an `a2bProbe…` consumer diagnostic.
- The 3×3 sweep confirmed the masking: all 12 candidate orphan edges fail at `gauge-pin-span`.
- 7614 and 7414 still pass. 8219 is unchanged (RED, with no contacts, so the ingress check stays off); P1-a owns it.
- **Local 508-row TB50 run with P3+P4: 506 PASS / 2 FAIL.**
  - Rows 492/493 and 505–508 pass.
  - The two failures are rows 283 and 445, the established macOS baselines: both fail with unpatched production too and pass on CI.
- Off-gate `SurfaceCellAuthorityContractCutover` tests (19 not in the manifest): 17 pass.
  - 8219 is RED, as expected.
  - **New O13:** `ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit` fails **identically at HEAD production**: 12× `Phase10:7631/7633`, with quarter-turn 3 vs 0 and lift mismatches on non-hard interior transports. C1 does not cause it. Owner: O5 coverage disposition in `M6-CP3-PLAN-RP01-CLOSURE`.

## RA-169.5 CB50 — `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` (type CB)

- Extract the RA-169.10 `~~~diff` block verbatim, with a trailing newline. SHA-256 must be `9874d1269b052aa975b4a42bf085ea48acfba1773246c973b05f76d492a1c1fb`. Then `git apply` with no hand edits.
- Numstat must be exactly `37 0 src/geometry/SurfaceCellTracing.cpp` and `47 0 tests/SurfaceCellsPhase10Tests.cpp`.
- **Evidence:** the established eight GMP/GMPXX targets, `runtimeExecution=false`, a record of at most 25 lines.

| Observed | Successor |
|---|---|
| Compile OK, numstat exact | `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` |
| The patch does not apply, or a compile error occurs | `M6-CP3-PLAN-RP01-C1-COVER-STOP` (Review) |
| Orchestration failure | `M6-CP3-CB50A-RP01-ORCH`, then retry CB50 |

## RA-169.6 CB50F — `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` (type CB)

- Requires CB50 committed. Extract the RA-169.11 block (SHA-256 `c8af43a28a7aa694d8cb2c43d461773061b34f2ba811649509d3def95127a426`) and `git apply` it on CB50.
- Numstat must be exactly `13 4 src/geometry/SurfaceCellTracing.cpp` and `52 0 tests/SurfaceCellTransitionQuotientTests.cpp`.
- **Evidence:** the same eight targets, runtime-free, ≤25 lines. Successors are as in RA-169.5, except that success leads to TB50.

## RA-169.7 TB50 — `M6-CP3-TB50-RP01-FULL-GATE-EXEC` (type TB-EXEC)

- Run on the CB50F package with the unchanged harness `142321061c57…`.
- Manifest: [`Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv), SHA-256 `6d5b788671487fa298ff3a3e9656dfda1729612f02c976206d3960a413121149`.
  - Rows 1–504 are byte-identical to TB49.
  - Rows 505–506 are GUARDs: `phase10:7414` and `phase10:7614`, previously off-gate and the nearest consumers of the fixed-plan provenance.
  - Rows 507–508 are POSITIVE: `ra169:c1-ingress` and `ra169:c1-factory`.
- **Predict 508/0.**
- Successor: `M6-CP3-TB50-RP01-FULL-GATE-REV`.
  - A RED on rows 1–504 or 505–506 means a C1 regression → `M6-CP3-PLAN-RP01-C1-COVER-STOP`.
  - Orchestration failure → `M6-CP3-CB50A-RP01-ORCH`, then `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2`.

## RA-169.8 Split of the O4/O5 DEFN (Review track; each is one mechanism with its own falsifier)

1. **`M6-CP3-DEFN-RP01-P1A-TERMINAL-A3-PATH-WITNESS`** (P1-a, 8219).
   - Under C1, hard edges are exactly rail edges, and the original torn-input purpose of 8219 is superseded by `ra169:c1-ingress`.
   - Decide by probe whether `missing-terminal-A3-path` (`:19868`) is reachable from a produced input. The candidate is a second rail ending inside the terminal star (a T-contact; this overlaps O9).
   - If it is reachable: exact CB51 rebuilds 8219 on that fixture, keeping its sites.
   - If it is not: retire 8219's predicate as accepted-defensive, with O9 as owner, by an exact test-only CB.
   - Falsifiers: the witness edits a caller set that production derives; the ingress orphan site or another earlier site fires first.
2. **`M6-CP3-DEFN-RP01-P1B-NETWORK-OWNERSHIP-DIFFERENTIAL`** (P1-b, 7414).
   - Pre-register a pair of first sites, one with the network bound and one without, for a typed-consistent rail mutation (RA-162 F3).
   - Falsifier: the same first site in both cases.
3. **`M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-WITNESS`** (O4). This replaces RA-158.3's `…-REACHABILITY`, which `turn_type_from_turn` rejects.
   - Classify each `MissingTransitionProvenance` site (`:12656/12698/12707`) as either production-reachable, with a witness, or accepted-defensive, with an owner.
4. **O5 off-selector coverage** (249 tests outside any frozen gate) is a scope decision, not a mechanism. It is folded into `M6-CP3-PLAN-RP01-CLOSURE`.

DEFNs 1–3 may run on the Review track while CB50/CB50F/TB50 run, because none of them edits the C1 code.

## RA-169.9 Canonical turn sequence (IDs validated with `turn_type_from_turn`)

| Step | Turn | Type / track |
|---|---|---|
| done | `M6-CP3-TB49-RP01-FULL-GATE-REV`; `M6-CP3-DEFN-RP01-C1-ORPHAN-HARD-EDGE-COVER` | TB-REV, DEFN / R |
| 1 | `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` (P3) | CB / I |
| 2 | `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` (P4) | CB / I |
| 3 | `M6-CP3-TB50-RP01-FULL-GATE-EXEC` (508, predict 508/0) | TB-EXEC / I |
| 4 | `M6-CP3-TB50-RP01-FULL-GATE-REV` | TB-REV / R |
| ∥ 1–4 | P1-a → P1-b → O4 DEFNs (RA-169.8) | DEFN / R |
| 5 | CB51 / CB52 / … one per DEFN patch, then `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `…-REV` | CB, TB / I, R |
| 6 | `M6-CP3-PLAN-RP01-CLOSURE` (O5 coverage, O6 scope, O7–O12 owners) | PLAN / R |

**STOP routes:**
- `M6-CP3-PLAN-RP01-C1-COVER-STOP` (S1–S3);
- `M6-CP3-CB50A-RP01-ORCH` (S5), then `…-EXEC-R2`.

## RA-169.10 Exact CB50 patch P3 (authoritative bytes)

Extract the lines between the `~~~diff` line and the next `~~~` line, then add a trailing newline. SHA-256 `9874d1269b052aa975b4a42bf085ea48acfba1773246c973b05f76d492a1c1fb`.

~~~diff
diff --git a/src/geometry/SurfaceCellTracing.cpp b/src/geometry/SurfaceCellTracing.cpp
index f671fc93f..859ddf8c3 100644
--- a/src/geometry/SurfaceCellTracing.cpp
+++ b/src/geometry/SurfaceCellTracing.cpp
@@ -19378,6 +19378,43 @@ SurfaceCellNetwork build_surface_cell_network(
   authoritativeOptions.sourceFaceComponents.clear();
   authoritativeOptions.sourceFaceSheets.clear();
   authoritativeOptions.sourceAuthority = &*network.sourceTopologyRegions;
+  // Once rail chains are published, every hard-feature edge must belong to
+  // one of them; reject a torn hard-edge set before any A4 consumer reads
+  // it (RA-162 C1).
+  if (!authoritativeOptions.hardRailOpenChains.empty() ||
+      !authoritativeOptions.hardRailClosedChains.empty()) {
+    std::set<authority::SourceEdgeTopologyKey> railEdges;
+    const auto addChain = [&](const auto &vertices, const bool closed) {
+      const std::size_t count = closed ? vertices.size() : vertices.size() - 1U;
+      for (std::size_t i = 0U; vertices.size() >= 2U && i < count; ++i) {
+        const auto edge = authority::SourceEdgeTopologyKey::make(
+            vertices[i], vertices[(i + 1U) % vertices.size()]);
+        if (edge) railEdges.insert(edge.value());
+      }
+    };
+    for (const auto &[rail, chain] : authoritativeOptions.hardRailOpenChains) {
+      (void)rail;
+      addChain(chain.vertices, false);
+    }
+    for (const auto &[rail, chain] : authoritativeOptions.hardRailClosedChains) {
+      (void)rail;
+      addChain(chain.vertices, true);
+    }
+    for (const authority::SourceEdgeTopologyKey &edge :
+         authoritativeOptions.hardFeatureEdges) {
+      if (railEdges.contains(edge)) continue;
+      SurfacePhaseFrontFailure failure;
+      failure.reason =
+          SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
+      std::ostringstream detail;
+      detail << "firstPredicate=orphan-hard-feature-edge"
+             << ";edge=" << edge.first().index() << ','
+             << edge.second().index();
+      failure.hardRailRouteDiagnostic = detail.str();
+      network.phaseFront = SurfacePhaseFrontResult::rejected(std::move(failure));
+      return network;
+    }
+  }
   auto phaseFrontState =
       surface_cell_tracing_detail::build_uniform_phase_front_state(
           vertices, faces, faceAxisX, faceAxisY, targetSize,
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index 3723a7552..0f7a3062c 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -8310,6 +8310,53 @@ TEST(SurfaceCellAuthorityContractCutover,
                 "a2bProbeFailure=no-exact-terminal-corner"));
 }
 
+// RA-169 C1: a hard-feature edge outside every published rail chain is a
+// torn A2b set. Network ingress rejects it before any A4 consumer reads it;
+// the same full provenance without the orphan still produces.
+TEST(SurfaceCellAuthorityContractCutover,
+     OrphanHardFeatureEdgeRejectsBeforeA4Consumer) {
+  const auto fixture = build_rectangular_hard_rail_phase_front();
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
+            fixture.network.phaseFront.disposition())
+      << hard_rail_first_failure_detail(fixture.network);
+  const auto &front = fixture.network.phaseFront.product();
+  ASSERT_FALSE(front.hardRailOpenChains().empty());
+  std::optional<directional::authority::SourceEdgeTopologyKey> orphan;
+  for (const auto &route : front.hardRailRouteCertificates()) {
+    for (const auto &endpoint : route.endpoints) {
+      for (const auto &path : endpoint.contactPaths) {
+        if (!path.empty() && !orphan.has_value()) orphan = path.front().edge;
+      }
+    }
+  }
+  ASSERT_TRUE(orphan.has_value())
+      << "the witness requires a produced non-hard terminal A3 step";
+  auto torn = fixture.hardFeatureEdges;
+  ASSERT_TRUE(torn.insert(*orphan).second)
+      << "the selected source-star step must originally be non-hard";
+  auto contacts = front.hardRailTerminalContacts();
+
+  const auto accepted =
+      build_fixed_plan_rectangular_hard_rail_network(fixture, 1.0, &contacts);
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
+            accepted.phaseFront.disposition())
+      << hard_rail_first_failure_detail(accepted);
+
+  const auto rejected = build_fixed_plan_rectangular_hard_rail_network(
+      fixture, 1.0, &contacts, &torn);
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
+            rejected.phaseFront.disposition());
+  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
+                InvalidFrontBoundaryAuthority,
+            rejected.phaseFront.rejection_reason());
+  const auto *failure = rejected.phaseFront.rejection();
+  ASSERT_NE(failure, nullptr);
+  std::ostringstream expected;
+  expected << "firstPredicate=orphan-hard-feature-edge;edge="
+           << orphan->first().index() << ',' << orphan->second().index();
+  EXPECT_EQ(expected.str(), failure->hardRailRouteDiagnostic);
+}
+
 TEST(SurfaceCellAuthorityContractCutover,
      ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback) {
   const auto fixture = build_rectangular_hard_rail_phase_front();
~~~

## RA-169.11 Exact CB50F patch P4 (authoritative bytes; applies on P3)

Extract the block the same way. SHA-256 `c8af43a28a7aa694d8cb2c43d461773061b34f2ba811649509d3def95127a426`.

~~~diff
diff --git a/src/geometry/SurfaceCellTracing.cpp b/src/geometry/SurfaceCellTracing.cpp
index 859ddf8c3..86ac4f10c 100644
--- a/src/geometry/SurfaceCellTracing.cpp
+++ b/src/geometry/SurfaceCellTracing.cpp
@@ -8707,11 +8707,20 @@ SurfacePhaseFrontProduct::ConstructionResult SurfacePhaseFrontProduct::make(
     error.sourceAuthoritySite = "open-rail-chain";
     return error;
   }
-  // A closed-only rail set must cover every hard-feature edge, not merely
-  // supply a convenient nonempty closed-chain token.
-  if (hardRailTerminalContacts.empty() && coveredClosedEdges != hardFeatureEdges) {
+  // Published rail chains must cover every hard-feature edge, not merely
+  // supply a convenient nonempty chain token. An orphan hard edge is not a
+  // source-owned rail barrier (RA-162 C1).
+  std::set<authority::SourceEdgeTopologyKey> coveredRailEdges = coveredClosedEdges;
+  for (const auto &[rail, chain] : hardRailOpenChains) {
+    (void)rail;
+    for (std::size_t i = 1U; i < chain.vertices.size(); ++i)
+      coveredRailEdges.insert(authority::SourceEdgeTopologyKey::make(
+          chain.vertices[i - 1U], chain.vertices[i]).value());
+  }
+  if (coveredRailEdges != hardFeatureEdges) {
     error.code = SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority;
-    error.sourceAuthoritySite = "closed-rail-cover";
+    error.sourceAuthoritySite = hardRailTerminalContacts.empty()
+        ? "closed-rail-cover" : "open-rail-cover";
     return error;
   }
   for (const auto &[rail, contact] : hardRailTerminalContacts) {
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index 12bcc36c6..e72c36d0c 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -6669,6 +6669,58 @@ TEST(M6CP1, ThinAdapterOutputIsPureProjectionOfStageProducts) {
 }
 
 
+// RA-169 C1: with open rails published, the checked factory requires the
+// rail chains to cover every hard-feature edge. An interior non-hard edge
+// away from every rail splits no gauge-pin region, so only cover can fire.
+TEST(M6CP3, ProducedTorusOrphanHardFeatureEdgeRejectsAtCheckedFactoryCover) {
+  const auto &torus = torus_fixture();
+  const auto &front = torus.network.phaseFront.product();
+  ASSERT_FALSE(front.hardRailTerminalContacts().empty());
+  ASSERT_FALSE(front.hardRailOpenChains().empty());
+  ASSERT_TRUE(std::holds_alternative<directional::geometry::SurfacePhaseFrontProduct>(
+      construct_phase_front_product(phase_front_draft(torus))));
+  std::set<directional::authority::SourceVertexId> railVertices;
+  for (const auto &[rail, chain] : front.hardRailOpenChains()) {
+    (void)rail;
+    railVertices.insert(chain.vertices.begin(), chain.vertices.end());
+  }
+  for (const auto &[rail, chain] : front.hardRailClosedChains()) {
+    (void)rail;
+    railVertices.insert(chain.vertices.begin(), chain.vertices.end());
+  }
+  const auto vertexCount = static_cast<std::size_t>(torus.mesh.V.rows());
+  std::map<directional::authority::SourceEdgeTopologyKey, int> incidence;
+  for (int row = 0; row < torus.mesh.F.rows(); ++row) {
+    for (int corner = 0; corner < 3; ++corner) {
+      ++incidence[test_source_edge_topology(
+          torus.mesh.F(row, corner), torus.mesh.F(row, (corner + 1) % 3),
+          vertexCount)];
+    }
+  }
+  std::optional<directional::authority::SourceEdgeTopologyKey> orphan;
+  for (const auto &[edge, count] : incidence) {
+    if (count == 2 && !front.hardFeatureEdges().contains(edge) &&
+        !railVertices.contains(edge.first()) &&
+        !railVertices.contains(edge.second())) {
+      orphan = edge;
+      break;
+    }
+  }
+  ASSERT_TRUE(orphan.has_value())
+      << "the witness requires an interior edge away from every rail";
+
+  PhaseFrontDraft torn = phase_front_draft(torus);
+  ASSERT_TRUE(torn.hardFeatureEdges.insert(*orphan).second);
+  auto result = construct_phase_front_product(std::move(torn));
+  const auto *error =
+      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(&result);
+  ASSERT_NE(error, nullptr) << "the checked factory must reject an orphan hard edge";
+  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
+                InvalidSourceAuthority,
+            error->code);
+  EXPECT_EQ("open-rail-cover", error->sourceAuthoritySite);
+}
+
 TEST(M6CP1, A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus) {
   const auto &fixture = torus_fixture();
   const auto hardEdges = torus_row408_hard_edges(fixture.mesh);
~~~
