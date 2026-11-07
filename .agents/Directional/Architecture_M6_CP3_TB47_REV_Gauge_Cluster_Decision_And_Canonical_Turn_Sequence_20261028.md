# RA-167 — TB47-REV: gauge cluster decided by probes; canonical turn sequence; stalled DEFN closed (2026-10-28)

**Turn:** `M6-CP3-TB47-RP01-FULL-GATE-REV` (canonical type **TB-REV**).

It closes and supersedes the stalled turn `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER`, which ran 62 same-turn revisions (R1–R62, about 327 commits) without a disposition. Its R1–R62 records stay as provenance.

**Decision:**
- **G1** (`selector:442`) and **G2** (`focused30:12`) are test-authority errors. Both are re-homed, and both pass.
- **G3** (cp3entry:1) is re-homed to a source-produced odd-gauge witness. That witness exposes a **real A4 production defect, P-G3**: periodic endpoint states are not gauge-covariant.
- One exact test-only patch (**CB48**) is authorized, then **TB48** (predict 502/2).

**Basis:** scratch probes against a local GMP build of HEAD `049a2ad8c` (test files unchanged since `08d41626e`). These are diagnostic only, not gate authority.

## RA-167.1 Why the Review stalled (process root cause)

- **Turn identity.** The user's canonical classifier `turn_type_from_turn` classifies `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` as **TB-EXEC**: the `-TB47-…` tail matches before the DEFN rule is tried. A Review that its own ID classifies as an execution turn has no consistent completion contract.
- **Capability mismatch.** RA-166 F6 requires probe-backed Reviews. The implementation agent cannot execute native code, so it kept accumulating static arguments (R28–R57), then drifted into auditing `review_check.py` (R60–R61).
- **Correction:** probe-requiring DEFN and TB-REV turns are owned by the probe-capable Review agent (RA-167.6). Implementation agents receive only CB turns with exact patches, and TB-EXEC turns with frozen manifests.

## RA-167.2 Probe evidence

- **G1, 442** (`FieldTransportAtlasTests:2856`, `ASSERT_TRUE(seamBuilt)`).
  - The seam section forges `sourceFaceComponents={0,1}` on a connected two-face square.
  - A3 correctly fails closed: a boundary cycle spans two components (`FieldTransportAtlas.cpp:2162–2194`, `SingularityMismatch`).
  - The producer derives components from edge connectivity, and regions split only at hard features. So a non-hard `NonTraversable` edge is unreachable, consistent with R59's static census.
  - The re-homed body asserts fail-closed for both row orders. **The FTA file passes 20/20.**
- **G2, `focused30:12`** (`TQ:5581`).
  - The test shifts branches and face gauges in one region while keeping A3 and the A4 rail certificates. That is an **unpaired** relabel, and A5 correctly rejects it (`HardRailTransportMismatch`; RA-36 endpoint equation; R-series 192/192 model).
  - The valid positive already exists as a source relabel: `nonconstant_hard_rail_fixture` is `hard_rail_fixture` with the right-half raw arms shifted a quarter turn. Probe results:
    - A3 rail crossing changes **0 → 3** on all 10 certificates;
    - HardRail canonical transports equal **20/20**;
    - occurrences 400/400 and relations 360/360;
    - A6 classes **121/121** with an identical member signature.
  - Re-homed: unpaired → typed A5 negative; source relabel → invariance positive. **The whole test passes**, including the 15 previously masked torus-periodic assertions.
- **G3, cp3entry:1** (`TQ:2916`).
  - The base torus has 5 candidates, all with delta 0.
  - Source relabel census (+1 arm shift on a half torus, by major angle) at 7 offsets: the **[0, π)** half gives **6/6 odd** deltas, reciprocal and holonomy-matched.
  - On that fixture the test's own Γ check fails, because the two endpoint pairs of one periodic relation give different gauge-stripped actions (translation (−30, 6) vs (−31, 5)).
  - **A5 rejects the produced torus** with `OccurrencePeriodicTransportMismatch`. The base torus is accepted.
  - The same physical field is rejected under a legal source relabel, so this is a **production defect (P-G3)**, not a test artifact.
- **Regression check.** The whole patched TQ file versus HEAD, single process: the only outcome change is `focused30:12` FAIL → PASS.
  - 5 further tests fail identically at HEAD and are **not in the 504 gate**: `HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`, `GenuineBoundaryWithInventedInteriorIndexIsRejected`, `QuotientLineageRetainsScalarPointAndCompleteSortedAuthority`, `TerminalRailContactPathsUseTypedSourceStarA3` and `CheckedFactoryRejectsForgedTerminalA2bSideGerm`. Registered as **O11**.

## RA-167.3 Decisions

- **G1:** the non-hard `NonTraversable` positive is unreachable by the producer. It is re-homed to a fail-closed A3 negative.
  - The HardFeature signed forward/inverse checks and the row-order checks are kept and now execute.
  - A future source-isolation-barrier producer owns the positive (**O10**, carried).
- **G2:** the RA-163 R2 relabel principle applies to **source-produced** relabels only. An unpaired A4 draft relabel is a negative.
- **G3:** the odd-gauge witness is `odd_gauge_torus_witness_fixture()`, the frozen torus field with a half-torus arm relabel. The frame oracle still runs on the unrelabelled field.
  - cp3entry:1 stays **RED**, now at a real production predicate: `TQ:3027`, "G3 periodic endpoint pairs disagree". The assertion is made single-line so the line pin does not depend on the compiler (CI uses GCC on ubuntu-24.04).
  - **P-G3 owner:** the A4 periodic endpoint-state publication.
    - `relationRotation` is derived only from the two **From** endpoints' carrier-face gauges (`SurfaceCellTracing.cpp:19088–19098`), then applied to the **To** endpoints (`:19109`, `:19123`) through `make_periodic_relation_endpoint_state` (`:8194–8218`).
    - The hypothesis to prove in the DEFN: per-endpoint gauge stripping is missing when the To faces' gauges differ.
- **E2:** unchanged (RA-166 D2). cp3entry:2 stays RED; its pin moves `:3154` → `:3183` because G3 adds lines above it.

## RA-167.4 CB48 — `M6-CP3-CB48-RP01-GAUGE-CLUSTER-TESTS` (type CB)

- Apply exactly the RA-167.8 embedded patch, SHA-256 `b32d6381d0a2412437fee13bdb651bdf6cb09bd7168c4cbc680a4af4851f651f`.
  - `git apply --check` passes at `049a2ad8c`.
  - Numstat must be `10 38 tests/FieldTransportAtlasTests.cpp` and `78 11 tests/SurfaceCellTransitionQuotientTests.cpp`.
- No other byte may change, and no hand edits are allowed.
- **Evidence:** the established eight GMP/GMPXX targets, `runtimeExecution=false`, a record of at most 25 lines.

| Observed | Successor |
|---|---|
| Compile OK, numstat exact | `M6-CP3-TB48-RP01-FULL-GATE-EXEC` |
| The patch does not apply, or a compile error occurs | `M6-CP3-PLAN-RP01-GAUGE-CLUSTER-STOP` (Review) |
| Orchestration failure | `M6-CP3-CB48A-RP01-ORCH`, then retry CB48 |

## RA-167.5 TB48 — `M6-CP3-TB48-RP01-FULL-GATE-EXEC` (type TB-EXEC)

- Artifact-only, on the CB48 package. The harness is unchanged (`142321061c57…`).
- **Manifest:** `Architecture_M6_CP3_TB48_Full_Gate_Case_Manifest.tsv`, SHA-256 `a3187d5557d792fe22bfd500e14fb0de8e6e14c06888aa17d18b7144ab5900bb`. It passes self-check (504 rows). Changes from TB47 v2:
  - rows 12 and 484: RED → POSITIVE, PASS, `-`;
  - row 492 cp3entry:1: pin `TQ:3027|G3 periodic endpoint pairs disagree`;
  - row 493 cp3entry:2: pin `TQ:3183`, same witness.
- **Prediction: 502 PASS / 2 RED.** Harness exit 0.

| Observed | Successor |
|---|---|
| 502/2 at the pins | `M6-CP3-TB48-RP01-FULL-GATE-REV` (Review) |
| A pinned RED passes | Same REV; it records the pass |
| A GUARD or POSITIVE row fails, or an unregistered first site appears | Same REV, with S4 diagnosis |
| Infra, coverage or hash failure | `M6-CP3-CB48A-RP01-ORCH` → `M6-CP3-TB48-RP01-FULL-GATE-EXEC-R2` |

## RA-167.6 Canonical turn sequence (all IDs validated with `turn_type_from_turn`)

**Naming rules:**
- Allowed types: CB, TB-EXEC, TB-REV, DEFN, PLAN.
- DEFN and PLAN IDs must not contain `-CB<n>` or `-TB<n>` segments, and their final qualifier must not be R plus letters only (for example `-REHOME`, `-RETIREMENT`, `-RAIL`).
- A Review of a test run is `…-TB<n>-…-REV`. A Review of a CB stop is a PLAN.
- Same-turn continuations use `-R<n>` only on TB EXEC/REV roles. A DEFN or PLAN that cannot finish closes BLOCKED with a named successor instead of iterating.

**Tracks:**
- **I** = implementation agent.
- **R** = probe-capable Review agent.
- I and R may run in parallel where marked ∥.

| # | Turn | Type | Track | Gate |
|---|---|---|---|---|
| 1 | `M6-CP3-CB48-RP01-GAUGE-CLUSTER-TESTS` | CB | I | Exact patch; 8 targets |
| 2 | `M6-CP3-TB48-RP01-FULL-GATE-EXEC` | TB-EXEC | I | Predict 502/2 |
| 1∥ | `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` | DEFN | R | Root-cause P-G3 at the A4 endpoint state; exact production patch, probed so that cp3entry:1 passes and the 504 rows show no change |
| 2∥ | `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` | DEFN | R | Exact cp3entry:2 rewrite to RA-166 D2; junction tamper sections disposed per O9 |
| 3 | `M6-CP3-TB48-RP01-FULL-GATE-REV` | TB-REV | R | Confirms TB48; freezes the TB49 manifest; releases 4 and 5 |
| 4 | `M6-CP3-CB49-RP01-G3-PERIODIC-ENDPOINT-STATE` | CB | I | Exact production patch |
| 5 | `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` | CB | I | Exact test patch |
| 6 | `M6-CP3-TB49-RP01-FULL-GATE-EXEC` → `M6-CP3-TB49-RP01-FULL-GATE-REV` | TB-EXEC → TB-REV | I → R | Predict 504/0 (a green full gate) |
| 7 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-CB50-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-TB50-RP01-FULL-GATE-EXEC` → `-REV` | DEFN → CB → TB | R → I → I → R | O4, O5, P1-a/P1-b, RA-162 C1 |
| 8 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN | R | RP-01 Review: O6 scope; O7–O12 owners |
| 9 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN | R | After RP-01 |

**Old-to-canonical renames:**
- `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` → closed by this TB-REV.
- `…-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT` → `…-O2-NO-ATLAS-INGRESS`.
- `DIAG-RETAIN` → `M6-DEFN-DIAG-RETAIN-A5-A7`.
- RA-164.3 P4 STOP codes S1–S3 (formerly `<CB>-REV`, which classifies as CB) → the matching `M6-CP3-PLAN-RP01-<topic>-STOP`.
- S4 → the `-TB<n>-…-REV` of that test run.
- S5 → `-CB<n>A-RP01-ORCH`, then `-TB<n>-…-EXEC-R<k>`.

## RA-167.7 Carried items

- **P-G3**, candidate production defect. It is not a stable event until TB48 reproduces it on CI.
- **O10:** the non-hard isolation-barrier producer.
- **O11:** five off-gate TQ tests failing at HEAD.
- **O12:** R61 `review_check.py` selector-collision finding. Review-instrument work, off the CP3 critical path.
- Also carried: O1, O2, O6, O7, O8, O9, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting:**
- Stable 66/17/49, debt 1. CP2 491/491 accepted.
- TB47 500/4 is valid expected-RED.
- Selector497 frozen. RP-01 open.

## RA-167.8 Exact CB48 patch (authoritative bytes)

Extract the lines strictly between the `~~~diff` and `~~~` fences, write them with a trailing newline, check that the SHA-256 is `b32d6381d0a2412437fee13bdb651bdf6cb09bd7168c4cbc680a4af4851f651f`, then run `git apply`.

~~~diff
diff --git a/tests/FieldTransportAtlasTests.cpp b/tests/FieldTransportAtlasTests.cpp
index e406cdbba..d7e3b5277 100644
--- a/tests/FieldTransportAtlasTests.cpp
+++ b/tests/FieldTransportAtlasTests.cpp
@@ -2842,5 +2842,6 @@ TEST(FieldTransportAtlas,
 
-  // A component/region seam is not a rail. It must remain nontraversable
-  // for ordinary branch adjacency while still carrying the two directed A3
-  // values needed by the source-vertex terminal-star consumer and validator.
+  // A component/region seam on a connected manifold edge is not producible:
+  // source components are edge-connected and regions only split at hard
+  // features (RA-167 G1). A forged component split must fail closed at A3
+  // instead of publishing a non-hard NonTraversable barrier.
   SurfaceCellTracingOptions seamOptions;
@@ -2855,25 +2856,5 @@ TEST(FieldTransportAtlas,
       mesh, *seamAuthority, noHardEdges, relabeledField);
-  ASSERT_TRUE(seamBuilt)
-      << describe_field_atlas_build_error(seamBuilt.error());
-  const auto &seamAtlas = seamBuilt.value();
-  const auto seamBarrier = std::find_if(
-      seamAtlas.nontraversable_edges().begin(),
-      seamAtlas.nontraversable_edges().end(),
-      [&](const FieldNonTraversableEdge &candidate) {
-        return candidate.sourceEdge == sourceEdge;
-      });
-  ASSERT_NE(seamAtlas.nontraversable_edges().end(), seamBarrier);
-  EXPECT_EQ(FieldTransportBarrierKind::NonTraversable, seamBarrier->kind);
-  const auto seamForward = seamAtlas.transition_value(sourceEdge, first, second);
-  const auto seamReverse = seamAtlas.transition_value(sourceEdge, second, first);
-  ASSERT_TRUE(seamForward.has_value());
-  ASSERT_TRUE(seamReverse.has_value());
-  EXPECT_EQ(QuarterTurn::from_integer(relabeledLift), seamForward->transport);
-  EXPECT_EQ(relabeledLift, seamForward->signedLift);
-  EXPECT_EQ(seamForward->transport.inverse(), seamReverse->transport);
-  EXPECT_NE(seamForward->transport, seamReverse->transport);
-  EXPECT_EQ(-seamForward->signedLift, seamReverse->signedLift);
-  EXPECT_FALSE(seamAtlas.transport(sourceEdge, first, second));
-  EXPECT_FALSE(seamAtlas.transport(sourceEdge, second, first));
-  EXPECT_EQ(nullptr, seamAtlas.find_adjacency(sourceEdge));
+  ASSERT_FALSE(seamBuilt);
+  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
+            seamBuilt.error().code);
 
@@ -2917,14 +2898,5 @@ TEST(FieldTransportAtlas,
       reorderedMesh, *reorderedSeamAuthority, noHardEdges, reorderedField);
-  ASSERT_TRUE(reorderedSeam)
-      << describe_field_atlas_build_error(reorderedSeam.error());
-  const auto originalSeamValue = seamAtlas.transition_value(
-      sourceEdge, originalFrom, originalTo);
-  const auto reorderedSeamValue = reorderedSeam.value().transition_value(
-      sourceEdge, reorderedFrom, reorderedTo);
-  ASSERT_TRUE(originalSeamValue.has_value());
-  ASSERT_TRUE(reorderedSeamValue.has_value());
-  EXPECT_EQ(originalSeamValue->transport, reorderedSeamValue->transport);
-  EXPECT_EQ(originalSeamValue->signedLift, reorderedSeamValue->signedLift);
-  EXPECT_FALSE(reorderedSeam.value().transport(
-      sourceEdge, reorderedFrom, reorderedTo));
+  ASSERT_FALSE(reorderedSeam);
+  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
+            reorderedSeam.error().code);
 }
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index 379ba44c0..d51a59ed4 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -1689,3 +1689,4 @@ std::vector<ProducedTorusSourceWitness> enumerate_torus_source_witnesses(
 
-ProducedTorusWitnessFixture make_nonzero_z4_torus_witness_fixture() {
+ProducedTorusWitnessFixture make_nonzero_z4_torus_witness_fixture(
+    const bool oddFaceGaugeRelabel = false) {
   PhaseFrontFixture fixture;
@@ -1696,3 +1697,21 @@ ProducedTorusWitnessFixture make_nonzero_z4_torus_witness_fixture() {
   }
-  const Eigen::MatrixXd raw = torus_nonzero_z4_raw_field(fixture.mesh);
+  const Eigen::MatrixXd frameRaw = torus_nonzero_z4_raw_field(fixture.mesh);
+  // D1 odd face gauge (RA-167 G3): the same physical field with the arms of
+  // the half torus at major angle [0, pi) relabelled one quarter turn. A3 and
+  // A4 regenerate every transport and face gauge from this source input.
+  Eigen::MatrixXd raw = frameRaw;
+  if (oddFaceGaugeRelabel) {
+    for (int face = 0; face < fixture.mesh.F.rows(); ++face) {
+      Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
+      for (int corner = 0; corner < 3; ++corner) {
+        centroid += fixture.mesh.V.row(fixture.mesh.F(face, corner)).transpose();
+      }
+      double majorAngle = std::atan2(centroid.y(), centroid.x());
+      if (majorAngle < 0.0) majorAngle += 2.0 * std::numbers::pi;
+      if (majorAngle >= std::numbers::pi) continue;
+      const Eigen::RowVectorXd arms = frameRaw.row(face);
+      raw.row(face) << arms.segment(3, 3), arms.segment(6, 3),
+          arms.segment(9, 3), arms.segment(0, 3);
+    }
+  }
   const auto sourceCrossField =
@@ -1717,3 +1736,6 @@ ProducedTorusWitnessFixture make_nonzero_z4_torus_witness_fixture() {
       validate_nonzero_z4_torus_chart_subject(
-          fixture.mesh, raw, sourceCrossField, hardEdges);
+          fixture.mesh, frameRaw,
+          directional::pipeline::finalize_surface_cell_raw_cross_field(
+              fixture.mesh, frameRaw),
+          hardEdges);
   (void)chartOracle;
@@ -1882,2 +1904,8 @@ ProducedTorusWitnessFixture make_nonzero_z4_torus_witness_fixture() {
 
+const ProducedTorusWitnessFixture &odd_gauge_torus_witness_fixture() {
+  static const ProducedTorusWitnessFixture fixture =
+      make_nonzero_z4_torus_witness_fixture(true);
+  return fixture;
+}
+
 const ProducedTorusWitnessFixture &nonzero_z4_torus_witness_fixture() {
@@ -2902,3 +2930,3 @@ std::unique_ptr<PhaseFrontFixture> m6cp3_produced_seam_fixture(
 TEST(M6CP3, PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority) {
-  const auto &fixture = nonzero_z4_torus_witness_fixture();
+  const auto &fixture = odd_gauge_torus_witness_fixture();
   const auto semantic = produced_semantic_relation_for_witness(fixture);
@@ -2995,5 +3023,6 @@ TEST(M6CP3, PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority) {
       gammaTo->inverse(), compose(semantic->semanticAction, *gammaFrom));
-  EXPECT_EQ(expected, compose(gammaToOther->inverse(),
-                              compose(semantic->semanticAction,
-                                      *gammaFromOther)));
+  const auto otherPairAction = compose(
+      gammaToOther->inverse(),
+      compose(semantic->semanticAction, *gammaFromOther));
+  EXPECT_EQ(expected, otherPairAction) << "G3 periodic endpoint pairs disagree";
   const auto wrongDirection =
@@ -5580,6 +5609,44 @@ TEST(M6CP1, RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant) {
           &relabelledA5Construction);
-  ASSERT_NE(relabelledA5, nullptr)
-      << a5_rejection_message(relabelledA5Construction);
+  // An unpaired relabel (branches and face gauges shifted in one region while
+  // A3 and the A4 rail certificates keep their transport) is not a gauge
+  // change of the source field; A5 must reject it at the HardRail endpoint
+  // equation (RA-36).
+  ASSERT_EQ(relabelledA5, nullptr);
+  const auto *relabelledA5Error =
+      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
+          &relabelledA5Construction);
+  ASSERT_NE(relabelledA5Error, nullptr);
+  EXPECT_EQ(relabelledA5Error->code,
+            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
+                HardRailTransportMismatch);
+
+  // A source-produced relabel: the same mesh and rail with the right-half raw
+  // cross-field arms shifted one quarter turn, so A3 and A4 regenerate every
+  // transport. HardRail relation transports and A6 classes must not change.
+  const auto &sourceRelabelled = nonconstant_hard_rail_fixture();
+  bool railTransportChanged = false;
+  for (const auto &original :
+       hardRailFixture.network.phaseFront.product().hardRailRouteCertificates()) {
+    for (const auto &shifted : sourceRelabelled.network.phaseFront.product()
+                                   .hardRailRouteCertificates()) {
+      if (original.route == shifted.route &&
+          original.endpoints[0].terminalCarrier.firstFace ==
+              shifted.endpoints[0].terminalCarrier.firstFace &&
+          original.endpoints[0].terminalCarrier.firstToSecond !=
+              shifted.endpoints[0].terminalCarrier.firstToSecond) {
+        railTransportChanged = true;
+      }
+    }
+  }
+  EXPECT_TRUE(railTransportChanged)
+      << "the source relabel must change the A3 transport across the rail";
+  auto sourceRelabelledA5Construction = produceA5(
+      sourceRelabelled, sourceRelabelled.network.phaseFront.product());
+  const auto *relabelledSourceA5 =
+      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
+          &sourceRelabelledA5Construction);
+  ASSERT_NE(relabelledSourceA5, nullptr)
+      << a5_rejection_message(sourceRelabelledA5Construction);
   std::size_t relabelledHardRailCount = 0U;
-  for (const auto &relation : relabelledA5->owned_relations()) {
+  for (const auto &relation : relabelledSourceA5->owned_relations()) {
     if (relation.id.kind !=
@@ -5596,3 +5663,3 @@ TEST(M6CP1, RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant) {
   auto relabelledQuotientConstruction =
-      directional::pipeline::SurfaceQuotientProducer::produce(*relabelledA5);
+      directional::pipeline::SurfaceQuotientProducer::produce(*relabelledSourceA5);
   const auto *relabelledQuotient =
~~~
