# RA-170 — TB49-REV re-audit; P1-a, P1-b, O4 DEFNs closed; E2 site pins; off-gate RED census (2026-10-28)

**Turns:** this record re-audits `M6-CP3-TB49-RP01-FULL-GATE-REV` and RA-169. It completes three Review-track DEFNs:
- `M6-CP3-DEFN-RP01-P1A-TERMINAL-A3-PATH-WITNESS`;
- `M6-CP3-DEFN-RP01-P1B-NETWORK-OWNERSHIP-DIFFERENTIAL`;
- `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-WITNESS`.

All three are type **DEFN**.

**Decision:**
- TB49 504/0 is **independently re-derived** here, no longer adopted second-hand.
- RA-169's C1 patches cause **no** gate or off-gate regression.
- Two small test-only patches are authorized: **P5** (P1-b witness) and **P6** (E2 site pins). They run as CB51 and CB52 before the unchanged TB50.
- P1-a and O4 are classified accepted-defensive, so no code turn is needed.
- **Trajectory correction:** 101 of the 408 tests in the four gate binaries that are outside the gate fail locally, at HEAD and with the patches alike. "504/0" therefore says nothing about the rest of the binaries. RP-01 cannot close until an off-gate census runs on CI (TB50C) and a disposition DEFN is completed.

**Basis:** local GMP build of HEAD `e58034171` with probes. Diagnostic only.

## RA-170.1 TB49 evidence, re-derived

- Downloaded artifact `12857282498`. ZIP SHA-256 is `3113383c…692db`, and `SHA256SUMS` passes 1014/1014.
- `execution-boundary.json`:
  - source `092b52eba881…`, package `12852132570`;
  - 504 planned, executed and passed; 0 red, missing, skipped, duplicate or control_bad;
  - `postflight=true`;
  - compile, relink, configure and benchmark all false.
- The manifest `a0e39fa2…`, `ledger.tsv` and the 504 raw logs join one-to-one by row, identity and log SHA-256. Each log has exactly one RUN and one OK for its test, with no FAILED or SKIPPED.
- Package `12852132570`: ZIP `24a0beb1…`, 28/28 checksums, `metadata/source-commit.txt` = `092b52eba881…`. There is no `src`/`tests` diff from it to HEAD.
- **Verified TB49-REV claims:**
  - the cp3entry:2 negatives (R-crossing tamper, null atlas, foreign atlas, carrier tamper);
  - the G3 gauge-free endpoint equations.
- **Gap in TB49-REV:** all five cp3entry:2 factory negatives assert only `InvalidSourceAuthority` (code 0). An unrelated earlier rejection would satisfy them. The probe shows they reach distinct, meaningful sites:
  - `endpoint-carrier;certificate=5;rail=2;endpoint=0;kind=R`;
  - `atlas-binding` (twice);
  - `rail-transition-a3` (twice).
  - P6 pins all five sites.

## RA-170.2 RA-169 C1 collateral (probe)

- **All 408 off-gate tests**, with P3+P4 and again at HEAD: the same 101 fail with the same first-failure lines. The only differences are line shifts from the P6 helper edit. C1 adds no regression.
- **Static check of every hand-built rail authority in `tests/`:**
  - Only Phase10's fixed-plan helper and TQ's drafts publish chains.
  - TQ's face-0 isolation test fails at `gauge-pin-span` before cover runs.

## RA-170.3 DEFN outcomes

- **P1-a (8219), accepted-defensive; owner O9.**
  - Under C1, hard edges are exactly rail edges. 8219's torn-input setup now duplicates `ra169:c1-ingress`.
  - **Probes on the produced 3×3 fixture:**
    - A real T-contact (extra rail `{3,4}`, which meets rail 1–4–7 at vertex 4) is **Produced**.
    - The diagonal variants `{4,8}` and `{0,4}` fail earlier with `InvalidBoundedDiskBoundaryPhase`.
  - No produced input reaches `missing-terminal-A3-path`. The 8219 test itself joins the O5 disposition (RA-170.5).
- **P1-b (7414): witness re-specified; this corrects TB44-REV remedy 2.**
  - With the network absent, A4 rejects even the **unmodified** rails (`InvalidFrontBoundaryAuthority`). The requested with/without-network differential is therefore unsatisfiable by construction.
  - The only network-specific predicate is A2a mandatory-edge ownership (`SurfaceCellTracing.cpp:6272`). It shares `TypedAuthorityMismatch` with the typed checks, so the differential has to be taken at `rail_interval_refs`.
  - **P5 replaces 7414's forged-key negative** with a swap of two same-component rail IDs:
    - `rail_interval_refs` returns `Valid` without the network and `TypedAuthorityMismatch` with it (interval 0, one of the swapped IDs);
    - the integrated A4 rejects at a real cell/side.
  - **Falsifier:** with the `rail`/`kind` ownership comparison removed from production, P5 fails at the network-bound status check.
- **O4, accepted-defensive; no CB.**
  - The four `MissingTransitionProvenance` returns (`:12656/12698/12707`, plus `from_index`/`interior`) guard maps built in one call from the same `faces`:
    - every `VertexPathStep` carries an edge key from `vertex_face_adjacency` or the shared key;
    - `resolve_branch_transition` already requires two-face incidence, which `edge_matching_indices` always indexes.
  - The only divergent path is the legacy `edgeTransitions` face match, which atlas-bound A4 nulls (RA-160). Its reachability belongs to O2, post-RP-01.
  - **Rule:** do not add fault-injection seams to production to manufacture witnesses for these guards.

## RA-170.4 Exact CB turns (each compile-only, the eight GMP targets, ≤25-line record)

| Turn | Patch | SHA-256 | Exact numstat |
|---|---|---|---|
| `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` | P3 (RA-169.10) | `9874d126…a1c1fb` | `37 0` SCT, `47 0` Phase10 |
| `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` | P4 (RA-169.11) | `c8af43a2…a127a426` | `13 4` SCT, `52 0` TQ |
| `M6-CP3-CB51-RP01-P1B-NETWORK-OWNER-WITNESS` | P5 (RA-170.7) | `a610f39b93970da7bd50a463427957d2b1e6eaa5455a4b0511d9770b55efd43c` | `40 19` Phase10 |
| `M6-CP3-CB52-RP01-E2-FACTORY-SITE-PINS` | P6 (RA-170.8) | `9f538bc2be2c6b42de796ed87a83f35e5e881fcbfd160796fcbd1a8b48976c91` | `16 6` TQ |

- Each patch applies on the previous one. P3→P6 applied to HEAD reproduce the probed bytes exactly.
- **Failure routes:**
  - a patch fails to apply, or a compile error → `M6-CP3-PLAN-RP01-C1-COVER-STOP` (Review);
  - orchestration failure → `M6-CP3-CB50A-RP01-ORCH`, then retry the same CB.

## RA-170.5 TB turns and the O5 disposition

- **`M6-CP3-TB50-RP01-FULL-GATE-EXEC`** on the CB52 package, manifest `6d5b7886…` (508 rows, unchanged).
  - P5 and P6 change only the bodies of rows 505 and 493. Predict **508/0**.
  - Local probe: 506/508, with the macOS baselines 283 and 445.
- **`M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC`** on the same package, using the unchanged harness.
  - Manifest [`Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv`](Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv), SHA-256 `800e7f26d7ef89357ae07002439f418f867e686c48471f9ef581fb676b88e005`.
  - It holds 408 GUARD rows: every test in the four gate binaries that is not in TB50.
  - There is **no pass prediction**: GUARD REDs are census data, not orchestration failure.
  - Local macOS result: 307 PASS / 101 RED. By source file:

| Source file | RED |
|---|---|
| FieldAlignedCurveNetworkTests | 27 |
| SurfaceComplexSimplificationPhase17 | 13 |
| PatchDescriptorMilestoneE | 11 |
| SurfaceCellsPhase10 | 8 |
| FlowRepStrandsPhase15 | 6 |
| TQ | 4 |
| SurfaceMeshOptimizer19–22 | 9 |
| REPackage | 1 |
| SurfaceCellDesignAcceptance (BunnyRandom, Vase) | 2 |
| uncaught C++ exception in the test body (e.g. "FlowRep test A3 atlas unavailable", "surviving twin has invalid next") | 20 |

  - Row 445's macOS cause (`FieldAlignedCurveNetworkTests.cpp:17125`) suggests many of these are platform-only. **CI decides.**
- **`M6-CP3-TB50-RP01-FULL-GATE-REV`** (Review) adjudicates both runs.
- **`M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`** (Review, RA-158.3 ID) classifies every CI RED into exactly one of:
  - stale oracle → exact re-home patch;
  - product regression → owner and RED;
  - legacy/no-atlas path → O2;
  - retired → exact deletion patch with rationale.
  - It then freezes the TB51 manifest, which absorbs the guards it re-homes.
  - This includes 8219, O11, O13 and `ProducedHardCarriersAreAtlasBarriers…`.
- **RP-01 closes only after:** one CB per disposition patch → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `…-REV` → `M6-CP3-PLAN-RP01-CLOSURE`.

## RA-170.6 Canonical sequence (IDs validated with `turn_type_from_turn`)

| Step | Turn | Type / track |
|---|---|---|
| done | TB49-REV (RA-169 + RA-170.1); DEFNs C1, P1-a, P1-b, O4 | TB-REV, DEFN / R |
| 1 — next | `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` (P3) | CB / I |
| 2 | `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` (P4) | CB / I |
| 3 | `M6-CP3-CB51-RP01-P1B-NETWORK-OWNER-WITNESS` (P5) | CB / I |
| 4 | `M6-CP3-CB52-RP01-E2-FACTORY-SITE-PINS` (P6) | CB / I |
| 5 | `M6-CP3-TB50-RP01-FULL-GATE-EXEC` (508, predict 508/0) | TB-EXEC / I |
| 6 | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC` (408, observe) | TB-EXEC / I |
| 7 | `M6-CP3-TB50-RP01-FULL-GATE-REV` (both runs) | TB-REV / R |
| 8 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` | DEFN / R |
| 9 | CB53… (one per disposition patch) → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `…-REV` | CB, TB / I, R |
| 10 | `M6-CP3-PLAN-RP01-CLOSURE` (O6 scope, O7–O12 owners) | PLAN / R |

- **Superseded:** the RA-169.8 "CB51/CB52 … one per DEFN patch" placeholder.
- **STOP routes:** as in RA-170.4; TB orchestration → `M6-CP3-CB50A-RP01-ORCH`, then `…-EXEC-R2`.

## RA-170.7 Exact CB51 patch P5 (authoritative bytes; applies on P4)

Extract the lines between the `~~~diff` line and the next `~~~` line, then add a trailing newline. SHA-256 `a610f39b93970da7bd50a463427957d2b1e6eaa5455a4b0511d9770b55efd43c`.

~~~diff
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index 0f7a3062c..45034d120 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -7461,26 +7461,47 @@ TEST(SurfaceCellAuthorityContractCutover,
   ASSERT_NE(consumedRail, nullptr)
       << "the network-bound boundary consumer must publish an actual rail side";
 
-  // Keep the authentic A2a network, source charts, phase-front plan, samples,
-  // endpoint vertices and rail identity. Forge only one otherwise well-typed
-  // published edge key of a rail that the positive consumer actually used.
-  // This enters A4's open-front consumer, not FieldAlignedCurveNetwork::make.
-  auto forgedRails = fixture.rails;
-  auto forged = std::find_if(
-      forgedRails.begin(), forgedRails.end(), [&](const auto &rail) {
-        return rail.id == consumedRail->id;
-      });
-  ASSERT_NE(forged, forgedRails.end());
-  ASSERT_FALSE(forged->sourceEdges.empty());
-  const auto originalKey = forged->sourceEdges.front();
-  const auto foreignKey = std::find_if(
-      fixture.hardFeatureEdges.begin(), fixture.hardFeatureEdges.end(),
-      [&](const auto &key) { return key != originalKey; });
-  ASSERT_NE(foreignKey, fixture.hardFeatureEdges.end());
-  forged->sourceEdges.front() = *foreignKey;
-  ASSERT_EQ(forged->sourceVertices.size(), forged->sourceEdges.size() + 1U);
+  // RA-170 P1-b: swap the IDs of two produced rails of one component.
+  // Every typed interval predicate (vertices, edge keys, samples, component)
+  // still holds, so only A2a mandatory-edge ownership can tell them apart.
+  // A network-absent A4 is not a producing configuration, so the
+  // differential is taken at rail_interval_refs, and A4 must reject.
+  auto swappedRails = fixture.rails;
+  std::optional<std::pair<std::size_t, std::size_t>> sameComponent;
+  for (std::size_t i = 0U; i < swappedRails.size() && !sameComponent; ++i) {
+    if (swappedRails[i].id != consumedRail->id) continue;
+    for (std::size_t j = 0U; j < swappedRails.size(); ++j) {
+      if (j != i && swappedRails[j].component == swappedRails[i].component) {
+        sameComponent = std::make_pair(i, j);
+        break;
+      }
+    }
+  }
+  ASSERT_TRUE(sameComponent.has_value())
+      << "the witness requires a second rail in the consumed rail's component";
+  std::swap(swappedRails[sameComponent->first].id,
+            swappedRails[sameComponent->second].id);
+
+  using directional::geometry::surface_cell_tracing_detail::RailBuildStatus;
+  using directional::geometry::surface_cell_tracing_detail::rail_interval_refs;
+  const auto edgeFaces =
+      directional::geometry::surface_cell_tracing_detail::edge_faces(
+          fixture.mesh.F);
+  const auto typedOnly = rail_interval_refs(
+      swappedRails, fixture.mesh.V, fixture.mesh.F, edgeFaces);
+  EXPECT_EQ(RailBuildStatus::Valid, typedOnly.status)
+      << "an ID swap must satisfy every typed interval predicate";
+  const auto networkBound = rail_interval_refs(
+      swappedRails, fixture.mesh.V, fixture.mesh.F, edgeFaces,
+      &*fixture.fieldNetwork);
+  EXPECT_EQ(RailBuildStatus::TypedAuthorityMismatch, networkBound.status);
+  ASSERT_TRUE(networkBound.railId.has_value());
+  EXPECT_TRUE(*networkBound.railId == swappedRails[sameComponent->first].id ||
+              *networkBound.railId == swappedRails[sameComponent->second].id);
+  EXPECT_EQ(0, networkBound.intervalIndex);
+
   const auto rejected = build_fixed_plan_rectangular_hard_rail_network(
-      fixture, 1.0, nullptr, nullptr, nullptr, &forgedRails);
+      fixture, 1.0, nullptr, nullptr, nullptr, &swappedRails);
   ASSERT_EQ(SurfaceCellProducerDisposition::Rejected,
             rejected.phaseFront.disposition());
   EXPECT_EQ(SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority,
~~~

## RA-170.8 Exact CB52 patch P6 (authoritative bytes; applies on P5)

Extract the block the same way. SHA-256 `9f538bc2be2c6b42de796ed87a83f35e5e881fcbfd160796fcbd1a8b48976c91`.

~~~diff
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index e72c36d0c..94dbe4f1d 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -2016,7 +2016,8 @@ construct_phase_front_product(PhaseFrontDraft draft) {
 void expect_phase_front_product_error(
     const directional::geometry::SurfacePhaseFrontProduct::ConstructionResult
         &construction,
-    const directional::geometry::SurfacePhaseFrontProductErrorCode expected) {
+    const directional::geometry::SurfacePhaseFrontProductErrorCode expected,
+    const std::optional<std::string> &expectedSite = std::nullopt) {
   const auto *error =
       std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
           &construction);
@@ -2024,6 +2025,10 @@ void expect_phase_front_product_error(
   if (error != nullptr) {
     EXPECT_EQ(expected, error->code)
         << describe_phase_front_product_error(*error);
+    if (expectedSite.has_value()) {
+      EXPECT_EQ(*expectedSite, error->sourceAuthoritySite)
+          << describe_phase_front_product_error(*error);
+    }
   }
 }
 
@@ -3455,17 +3460,20 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
   expect_phase_front_product_error(
       checkedFactory(front.hardRailFieldTransitions(), tamperedCertificates,
                      &sourceAtlas),
-      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
+      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority,
+      "endpoint-carrier;certificate=5;rail=2;endpoint=0;kind=R");
   expect_phase_front_product_error(
       checkedFactory(front.hardRailFieldTransitions(),
                      front.hardRailRouteCertificates(), nullptr),
-      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
+      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority,
+      "atlas-binding");
   ASSERT_TRUE(permutedFixture.fieldTransportAtlas.has_value());
   expect_phase_front_product_error(
       checkedFactory(front.hardRailFieldTransitions(),
                      front.hardRailRouteCertificates(),
                      &*permutedFixture.fieldTransportAtlas),
-      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
+      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority,
+      "atlas-binding");
   auto tamperedCarriers = front.hardRailFieldTransitions();
   ASSERT_FALSE(tamperedCarriers.empty());
   tamperedCarriers.front().firstToSecond = compose(
@@ -3474,7 +3482,8 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
   expect_phase_front_product_error(
       checkedFactory(tamperedCarriers, front.hardRailRouteCertificates(),
                      &sourceAtlas),
-      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
+      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority,
+      "rail-transition-a3");
 
   // The same physical source topology must retain exact owner HardRail chi.
   // Canonicalize each directed transition by its typed source-face topology
@@ -3706,7 +3715,8 @@ TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
   // witness instead of bypassing this factory gate.
   expect_phase_front_product_error(
       construct_phase_front_product(std::move(tampered)),
-      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
+      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority,
+      "rail-transition-a3");
 
 }
 
~~~
