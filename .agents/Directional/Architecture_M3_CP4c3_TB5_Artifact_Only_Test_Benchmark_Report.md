# M3-CP4c-3-TB5 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-3-TB5`
**Date:** 2026-08-31 UTC
**Verdict:** **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366**
**Next turn:** independent `M3-CP4c-3-TB5-REV` REVIEW + PLAN. No unchanged TB retry and no semantic correction before review.

## 1. Immutable authority

TB5 executed only immutable package **74** built from semantic/evidence source
`49536cf7b4b261bd52f36a91c861b6459db356a4`.

- package artifact: `9778267541`
- Actions package ZIP SHA-256: `bad0ade74ff8e47c9937013c0fcc3f1084272c66eda35a2db60800ff7b6b767d`
- inner `package74.tar.gz` SHA-256: `c8d5167652ea95504252f5adb4d1dc5d9f463a4dfacfb7e5e11bd086fe935d8e`
- packaged source archive SHA-256: `5afa250d0dd8e003b91e7e5f887e3eed8658f16faa6754722bf8a2dd37a1c931`
- selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- authoritative TB5 run/job: `33448925069 / 99674216849`
- result artifact: `9779114492`, Actions SHA-256
  `a4d9239e7eee452b6b0e053577ad18126d37b5d5cc2a6a1225c1deefd660ca55`

Preflight and postflight both passed. The package remained byte/mode/source/fixture/selector immutable. Every build or
mutation flag was false: no configure, compile, relink, package repair, generated discovery, product/test/fixture/
selector mutation, or benchmark occurred.

## 2. Control-plane corrections before authoritative runtime

Two non-semantic attempts produced no gate evidence.

1. Run `33448461852` failed at workflow startup with zero jobs because the temporary caller granted `contents: read`
   while the reused observer's conditionally skipped branch-file job requests `contents: write`. The caller was
   corrected to the reusable job graph's permission union. No Directional process ran.
2. Run/job `33448694360 / 99673502678` passed schema validation and immutable package/hash checks, then stopped
   **before runtime** on an over-strong selector-lineage assertion: historical selector 358 is not a byte prefix of
   selector 373. Exact hashes/cardinalities remained correct. Static comparison showed selector 358 is a retained
   historical fork whose **identity set is a subset** of selector 373; selector 361 restores cumulative byte-prefix
   lineage. The authoritative retry therefore kept strict byte-prefix checks for 357/361/365/367/370, while 358
   was checked by exact hash/cardinality/uniqueness plus set-subset continuity. No selector byte changed.

This is control-plane evidence only. It does not alter semantic/package accounting.

**Process note.** The mandatory start-of-turn conservation gate should have selected `READ_MODE=snapshot` before repository document inspection because the checklist required multiple files. That choice was made late. Once recognized, semantic/static inspection was confined to the already-downloaded immutable package-74 source/local prepared documentation state rather than continuing broad repository pagination. This process miss does not alter the independently produced TB5 runtime artifact, but it is retained here so the review turn does not repeat it.

## 3. Ordered semantic gate

TB5 started from ordinal 1, ran exactly one frozen identity per fresh process, and stopped at the first semantic red.

- ordinals **1–365: 365/365 PASS**
- ordinal **366: RED**
- identity: `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- target: `directional_surface_cell_producer_tests`
- observed failure:
  `NotProductionReady/field-aligned-network;detailCode=VertexTransitSectorUnresolved`
- typed locus:
  - `sourceVertex=11`
  - `sourceFace=(8,10,11)`
  - `branch=1`
  - `topologyRegion=0`
  - `arrivalMode=FaceInterior`
  - `publishedFaceCount=0`
  - `barrierAbsorbed=false`
  - `barrierIncident=false`

This is **not** TB4's two-candidate vertex-30 locus. Amendment 17 changed the reached failure surface, but ordinal
366 remains red. The run therefore does **not** establish that the prior vertex-30 defect is accepted; it may be
cleared or merely masked by the earlier/new vertex-11 zero-candidate stop.

CB6's `vertexTransitStates` diagnostic serialization emitted **zero state records** at this failure. That is an
important discriminator: the independent review must trace the new transit pipeline's pre-diagnostic exits rather
than assuming ordinary zero-sector membership. Candidate `M3-CP4c3-TB5-CAND-01` owns the new locus.

## 4. AP6 report-only pass — zero gate credit

After the gate verdict was fixed, ordinals 367–373 ran once each as the frozen report-only pass. Result: **1 PASS /
6 RED**, with **zero gate credit**.

| Ordinal | Identity/result | Interpretation |
|---|---|---|
| 367 | `RotationSystemAndFaceWalkAgreeOnProducedWitnesses` — RED | blocked by the same mechanical vertex-11 `VertexTransitSectorUnresolved`; not independent rotation-system evidence |
| 368 | prescribed sphere production witness — RED | independently localizes trace 2/event 30 to `TraceEventPositionInvalid` with **`NoCarrierMatch / SourceEdgeUnavailable`**; AM7/AS6 diagnostic wiring is runtime-proved; AL4 still forbids a sphere semantic fix |
| 369 | ordinary trace-crossed proposal — RED | reaches its intended assertion and reports `certificate.saturationUsed=true`; reconfirms the deferred quality/coverage finding |
| 370 | empty-network closed-surface typed-error witness — RED | atlas build now publishes **`NonIntegralCycleLift;topologyRegion=0`** before A2a′; the constant ambient `make_zero_transport_field` torus witness violates the atlas precondition. Classify as **invalid diagnostic witness/precondition**, with the atlas's fail-closed rejection legitimate; the intended empty-network product contract remains unmeasured |
| 371 | non-separating barrier exclusion — RED | blocked upstream by the mechanical vertex-11 failure; contract remains unmeasured, not falsified |
| 372 | Euler cut identity — RED | blocked upstream by the mechanical vertex-11 failure; contract remains unmeasured, not falsified |
| 373 | prescribed singularity barrier-arc binding — PASS | synthetic-only proof with zero gate credit; mechanical `unboundSingularityCount=0` is still owed, so `M3-CP4c3-DEFN-R1-CAND-01` remains active/partial |

## 5. Regression and accounting disposition

Every observed red belongs to the still-unaccepted CP4c-3 surface or to explicitly report-only inherited debt. The
accepted 365-prefix remains fully green. No accepted-green behavior was lost, so this turn adds **+0 stable events /
+0 recurrences**.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**.
Semantic M3 package count remains **72**; TB5 created no package.

## 6. Stop decision

The red is valid semantic evidence. Per the binding turn workflow, TB5 stops here and routes to independent
`M3-CP4c-3-TB5-REV` REVIEW + PLAN. The review must independently reconstruct the source-vertex-11 zero-state/
zero-candidate path, determine why no `vertexTransitState` record is emitted, adjudicate whether Amendment 17's
vertex-30 correction is actually cleared or masked, and incorporate the now-resolved sphere/ordinal-370 diagnostic
classifications. No unchanged TB retry, code patch, fixture repair, selector edit, rebuild, repackage, or sphere fix
is authorized before that review.
