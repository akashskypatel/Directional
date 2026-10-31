# RA-183 — O2: no-atlas A4 ingress (2026-10-31)

**Turn:** `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (DEFN, Review track), run locally. The ID frozen in RA-160.4 ended in `-RETIREMENT`; that suffix is dropped under the RA-167.6 naming rule.
- **Authority:** [RA-160.4](Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md) and RA-161 T2. O4 folds into O2. [RA-179 F3](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md) covers row 283.
- **Method:** probes are diagnostic only. Source is CB56 `567d1828…`, unchanged in `src/`, `include/` and `tests/` at HEAD. A Sonnet subagent produced the read-only consumer inventory; a Haiku subagent compared the runs; the Review agent probed and ruled.

## RA-183.1 Inventory (verified at HEAD)

- **Production always supplies an atlas.**
  - The only `build_surface_cell_network` call is `RemeshPipeline.cpp:13122`. The atlas is set at `:12985` after a successful build, and atlas failures return earlier (`:12977`, `:12993`).
  - The only other production tracing call is `trace_surface_field(crossField)` at `FlowRepStrands.cpp:3511`, reached with the same options. With an atlas, the legacy containers are ignored (`SurfaceCellTracing.cpp:5482`, `:6720`).
- **Without an atlas, the A4 builder takes three paths:**
  - a produced phase front: the checked factory rejects at `atlas-binding` (`:8462–8469`). Gated row 232 (`selector:190`) pins this.
  - a rejected phase front: an early return.
  - **NotApplicable** (every region declined; the no-feature fallback at `:18490`): `publish_phase_front_result` returns `not_applicable()` (`:13167`). The seed fallback (`:20707–20720`) and the singular separatrices (`:21182`) then publish seeds, traces and proposals **decided by legacy matching**. This is D2.
- **Probe (bounded) of the builder with no atlas and no features:**

  | Input | Result |
  |---|---|
  | unit square; 5-, 6- and 8-triangle fans | already reject at `atlas-binding`, with empty outputs |
  | **closed** tetrahedron, octahedron, cube | **NotApplicable**, publishing 4/6/8 seeds, 16/24/32 traces and 4/6/8 proposals |

- **D5 (periodic identity fall-through, `:14946–14989`)** is reachable only without an atlas. Every such path is rejected before anything is published (see RA-183.2), so the identity default never decides a published output (RA-161 T2).
- **Legacy branches in the detail functions** (`resolve_branch_transition` `:6798–6818`, plus the derived containers at `:12016`, `:12569`, `:16243` and `:18083`) are reached by:
  - 12 gated unit tests that call `detail::resolve_*` directly: rows 220–224, 275 and 777–781;
  - the public container overloads (D3);
  - historical tests that are not built (`DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF`).

  They are not reached from production or from the builder once the gate is in place.

## RA-183.2 Rulings

- **D2 and D5: fix with one entry gate.** In `publish_phase_front_result`, a NotApplicable phase front with no atlas is rejected with the checked factory's own failure:
  - `PublishedProductRejected` / `InvalidSourceAuthority` / `AtlasSourceMismatch` / `"atlas-binding"`.

  After the gate, every no-atlas builder path ends at the single locus that row 232 pins, with nothing published, and the separatrix code sits behind the same early return. With an atlas, behaviour is unchanged.
- **T2 is discharged.** No no-atlas path publishes anything, so a silent identity fallback is unobservable.
- **D3 and the detail legacy branches → O2b (carried; not CP3-blocking).** Retiring the public no-atlas container and `crossField` tracing APIs, the legacy branches, their 12 gated unit tests and the historical suite is a separate retirement slice. Production is unaffected today. Owner: a retirement DEFN after P13.
- **Row 283 → O16 (new; not O2; not CP3-blocking).** The test is in the default `LegacyInteger` NFunctionMesher backend (`GenerateMesh.cpp:1102`), not the SurfaceCells A4 ingress. It fails only on macOS arm64 and identically without FMA (RA-179); CP3 is evaluated on Linux CI, where it passes. The legacy backend is outside the SurfaceCells exactness amendments. Owner: a legacy-backend determinism probe DEFN, after M6 or when local mode needs it. Local outcome tables keep it pre-registered.
- **O4** (the `MissingTransitionProvenance` same-call guards) stays accepted-defensive (RA-170.3).

## RA-183.3 Probe evidence for CB57

Builds are local CB56 source plus the CB57 patch, default arithmetic.

| Check | Before the gate | With the gate |
|---|---|---|
| New `NoAtlasNotApplicableInputRejectsBeforeLegacySeedFallback` (closed cube, no atlas) | **FAIL** (disposition NotApplicable, 8 seeds) | PASS |
| Row 232 (`LegacyMatchingPathUsesSameTypedAlgebra`) | PASS | PASS |
| Full gate, 858 rows | 857/858 (TB55) | 857/858, verdicts identical by row (only 283) |
| 82 deferred rows | 81 RED / 1 PASS (362) | identical verdicts; the same first-failure assertions, with 11 lines shifted only by inserted tests (+14 from CB55's test, +63 from CB57's test) |

## RA-183.4 CB57 — exact patch

**Turn:** `M6-CP3-CB57-O2-NO-ATLAS-ENTRY-GATE` (CB), run locally; Code + Build.
- **Scope:**
  - `src/geometry/SurfaceCellTracing.cpp`: the NotApplicable no-atlas gate, `13 0`.
  - `tests/SurfaceCellsPhase10Tests.cpp`: the failing-first test, `63 0`.
- **Checks:**
  - The RA-183.7 block, extracted verbatim with a trailing newline, has SHA-256 `35eb2fbcb2196b8af934b9a57a7dd5d60d28e2a3d900a315626e9d52ab9644d6`.
  - `git apply --check`, then apply; the numstat must be exactly `13 0` and `63 0`.
  - The resulting SHA-256 must be `c0b753ae0b247063e5c6f426575cbd8a5a13aa804c9d93ab8965caa15457cdb3` (SurfaceCellTracing) and `12e42b5ab8399da4a3a4bf1a2edfb3b41ae0d2f7126648c256febfad31dc3478` (Phase10).
  - Build the eight targets at default arithmetic and stage the package. No native tests.

| CB57 result | Successor |
|---|---|
| All exact, package built | `M6-CP3-TB56-O2-FULL-GATE-EXEC` |
| Mismatch | `M6-CP3-PLAN-O2-ENTRY-GATE-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CP3-CB57A-O2-ORCH`, then one retry |

## RA-183.5 TB56 frozen inputs

- **Gate:** [`Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv), 859 rows, SHA-256 `c8437d61e5b9a12d37bcd9d026dc859ee7954e56eaf904f193d8b2a549a2097f`. The first 859 lines are TB55 (`eb508378…`); row 859 is `GUARD ra183:o2-no-atlas-not-applicable` (producer binary).
- **Ledger:** v4 is unchanged (82, `36241caa…`).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=859 deferred=82`. The real membership check of the patched binaries gives **941**.

| TB56 result (local) | Successor |
|---|---|
| 858/859 PASS, with row 283 (O16) the only RED, postflight true, membership 941 | next turn per RA-183.6; no separate REV |
| Any other non-PASS | `M6-CP3-TB56-O2-FULL-GATE-REV` (R) |
| Membership error | `M6-CP3-PLAN-O2-MEMBERSHIP-STOP` (PLAN, R) |

## RA-183.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CP3-CB57-O2-NO-ATLAS-ENTRY-GATE` → `M6-CP3-TB56-O2-FULL-GATE-EXEC` | CB, TB-EXEC / local | 858/859, with only 283 red |
| then | `M6-DEFN-DIAG-RETAIN-A5-A7` (user-directed diagnostics; RA-160.4 sequencing is satisfied now that RP-01 is closed) | DEFN / R | DIAG-RETAIN slices |
| then | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | O2b (no-atlas API and legacy-branch retirement), O15b, O15c, O16 (row 283); Linux CI confirmation of rows 854–859 | — | — |

## RA-183.7 Exact CB57 patch

~~~diff
diff --git a/src/geometry/SurfaceCellTracing.cpp b/src/geometry/SurfaceCellTracing.cpp
index 86ac4f10c..c90a56ed0 100644
--- a/src/geometry/SurfaceCellTracing.cpp
+++ b/src/geometry/SurfaceCellTracing.cpp
@@ -13165,6 +13165,19 @@ SurfacePhaseFrontResult publish_phase_front_result(
     const SurfaceHardRailClosedChains &hardRailClosedChains,
     const SurfaceHardRailOpenChains &hardRailOpenChains) {
   if (state.disposition == SurfaceCellProducerDisposition::NotApplicable) {
+    // Without an A3 atlas the seed fallback would publish outputs decided by
+    // legacy matching (RA-160 D2). Reject at the checked factory's binding
+    // locus instead, as a produced phase front without an atlas is (RA-183).
+    if (fieldTransportAtlas == nullptr) {
+      state.failure.reason =
+          SurfacePhaseFrontFailureReason::PublishedProductRejected;
+      state.failure.publishedProductError =
+          SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority;
+      state.failure.publishedProductSourceAuthorityDetail =
+          SurfacePhaseFrontSourceAuthorityDetail::AtlasSourceMismatch;
+      state.failure.publishedProductSourceAuthoritySite = "atlas-binding";
+      return SurfacePhaseFrontResult::rejected(std::move(state.failure));
+    }
     return SurfacePhaseFrontResult::not_applicable();
   }
   if (state.disposition == SurfaceCellProducerDisposition::Rejected) {
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index 4dc7f07fb..e30db35fa 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -5351,6 +5351,69 @@ TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
   EXPECT_TRUE(rejected.proposals.empty()) << detail.str();
 }
 
+// O2 (RA-183): a closed feature-free input leaves every region NotApplicable.
+// Without an A3 atlas the seed fallback would publish seeds, traces and
+// proposals decided by legacy matching; A4 must reject at the same
+// atlas-binding locus as a produced phase front without an atlas.
+TEST(SurfaceCellAuthorityContractCutover,
+     NoAtlasNotApplicableInputRejectsBeforeLegacySeedFallback) {
+  Eigen::MatrixXd vertices(8, 3);
+  vertices << 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
+              0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1;
+  Eigen::MatrixXi faces(12, 3);
+  faces << 0, 2, 1, 0, 3, 2, 4, 5, 6, 4, 6, 7, 0, 1, 5, 0, 5, 4,
+           1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7;
+  directional::fields::CrossFieldResult field;
+  field.degree = directional::fields::kCrossFieldDegree;
+  field.primaryDirections.resize(faces.rows(), 3);
+  field.secondaryDirections.resize(faces.rows(), 3);
+  for (int face = 0; face < faces.rows(); ++face) {
+    field.primaryDirections.row(face) = Eigen::RowVector3d::UnitX();
+    field.secondaryDirections.row(face) = Eigen::RowVector3d::UnitY();
+  }
+  std::map<directional::authority::SourceEdgeTopologyKey, int> incidence;
+  for (int face = 0; face < faces.rows(); ++face)
+    for (int corner = 0; corner < 3; ++corner)
+      ++incidence[test_source_edge_topology(faces(face, corner),
+                                            faces(face, (corner + 1) % 3))];
+  const auto interior = static_cast<int>(std::count_if(
+      incidence.begin(), incidence.end(),
+      [](const auto &entry) { return entry.second == 2; }));
+  field.matching = Eigen::VectorXi::Zero(interior);
+  field.effort = Eigen::VectorXd::Zero(interior);
+  field.matchingComputed = true;
+  field.singularitiesComputed = true;
+  directional::geometry::SurfaceCellTracingOptions options;
+  options.sourceFaceComponents.assign(static_cast<std::size_t>(faces.rows()), 0);
+  options.sourceFaceSheets.assign(static_cast<std::size_t>(faces.rows()), 0);
+  options.fieldTransportAtlas = nullptr;
+  options.sourceAuthority = nullptr;
+  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(vertices.rows(), 0.25);
+
+  const auto rejected = directional::geometry::build_surface_cell_network(
+      vertices, faces, field, targetSize, options);
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
+            rejected.phaseFront.disposition());
+  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
+                PublishedProductRejected,
+            rejected.phaseFront.rejection_reason());
+  const auto *failure = rejected.phaseFront.rejection();
+  ASSERT_NE(nullptr, failure);
+  EXPECT_EQ(std::make_optional(
+                directional::geometry::SurfacePhaseFrontProductErrorCode::
+                    InvalidSourceAuthority),
+            failure->publishedProductError);
+  EXPECT_EQ(std::make_optional(
+                directional::geometry::SurfacePhaseFrontSourceAuthorityDetail::
+                    AtlasSourceMismatch),
+            failure->publishedProductSourceAuthorityDetail);
+  EXPECT_EQ("atlas-binding", failure->publishedProductSourceAuthoritySite);
+  EXPECT_EQ(nullptr, rejected.phaseFront.produced_product());
+  EXPECT_TRUE(rejected.seeds.empty());
+  EXPECT_TRUE(rejected.traces.empty());
+  EXPECT_TRUE(rejected.proposals.empty());
+}
+
 TEST(SurfaceCellsPhase10,
      ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary) {
   const auto meshPath = directional::tests::benchmark_fixture_path(
~~~
