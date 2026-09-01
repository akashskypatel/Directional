# M3-CP4c-3-TB6 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-3-TB6`
**Date:** 2026-09-01 UTC
**Verdict:** **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366**
**Next turn:** independent `M3-CP4c-3-TB6-REV` REVIEW + PLAN under `Architecture_M3_CP4c3_TB6_Independent_Review_Plan.md`. No unchanged TB retry and no semantic correction before review.

## 1. Immutable authority

TB6 executed only immutable package **75** built from semantic/evidence source
`e926ada023bc51220628be550bbe9a87f98d7067`.

- package artifact: `9781487311`
- Actions package ZIP SHA-256: `547f2441b026b68d2bef10e7c7694faf994be473a1d2db68a6375d06b1e654b8`
- inner `package75.tar.gz` SHA-256: `8814b700a5c07290ce099ce1f719f01b2fbd5bcfd80f36037fe5bafc600f7896`
- packaged source archive SHA-256: `64e5189f3c9f22d648e496c50b4093e842a0fad25a885dca65778d7a110b629a`
- selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- authoritative TB6 run/job: `33458067065 / 99702200466`
- result artifact: `9782227361`, Actions SHA-256 `e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`
- supplemental immutable-source artifact: `5748464025`, Actions SHA-256 `5730c1681b51c63c20fe74453f37456dddb99b39b57d56f5d51d9d4a9c421a31`
- supplemental immutable-artifacts artifact: `5748463876`, Actions SHA-256 `3b25c796f9fb97e4642454e0ab46c6cf287190baf9fe0da7a970e347003af8c7`

Preflight and postflight both passed. The package remained byte/mode/source/fixture/selector immutable. Every build or
mutation flag was false: no configure, compile, relink, package repair, generated discovery, product/test/fixture/
selector mutation, or benchmark occurred.

## 2. Ordered semantic gate

TB6 started from ordinal 1, ran exactly one frozen identity per fresh process, and stopped gate credit at the first
semantic red.

- ordinals **1–365: 365/365 PASS**
- ordinal **366: RED**
- identity: `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- target: `directional_surface_cell_producer_tests`
- observed failure: `NotProductionReady/field-aligned-network;detailCode=VertexTransitSectorUnresolved`
- typed locus:
  - `sourceVertex=30`
  - `sourceFace=(24,30,32)`
  - `branch=1`
  - `topologyRegion=0`
  - `arrivalMode=FaceInterior`
  - `publishedFaceCount=2`
  - `publishedFaces=(25,30,31)|(30,31,119)`
  - `barrierAbsorbed=false`
  - `barrierIncident=false`

This proves CB7 clears TB5's earlier silent seed-drop at regular vertex 11 far enough for the mechanical witness to
return to the vertex-30 two-published-face failure surface. It does **not** prove Amendment 17 either correct or
incorrect: the production exception emitted by ordinal 366 contains no serialized `vertexTransitState[*]` rows and
no exact representative/incoming/elected-direction fields. The equal-direction falsifier frozen by TB5-REV is
therefore not observable in the authoritative TB6 gate artifact.

A second evidence-governance gap is now explicit. CB7 added and compiled
`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState`, but that identity is **not a
member of frozen selector 373**. TB6 therefore could not execute it without an unauthorized selector expansion.
The review must adjudicate that mismatch; TB6 correctly did not widen the selector.

## 3. Mandatory report-only remainder — zero gate credit

After the gate verdict was fixed, ordinals 367–373 ran once each. Authoritative result: **1 PASS / 6 RED**, with
**zero gate credit**.

| Ordinal | Identity/result | Runtime disposition |
|---|---|---|
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` — RED | blocked by the same mechanical vertex-30 `VertexTransitSectorUnresolved`; no independent region/face-walk conclusion is creditable |
| 368 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` — RED | remains `surface-cut-graph/CellularityNotEstablished`, originating `RotationSystemInconsistent → TraceEventPositionInvalid`; trace 2/event 30 publishes `claimedSourceEdge=none`, `NoCarrierMatch / SourceEdgeUnavailable`; localization is reproduced, not a fix |
| 369 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` — RED | reaches the intended assertion and reports `certificate.saturationUsed=true`; deferred quality/coverage finding persists |
| 370 | `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` — RED | repaired witness now gets past the prior `NonIntegralCycleLift`; actual error code is `CellularityNotEstablished` (enum value 4), not required `EmptyNetworkOnClosedSurface` (enum value 6), and no `sourceFace` locus is present. The intended A2a′ product contract is now measured and red |
| 371 | `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` — RED | blocked upstream by the mechanical vertex-30 failure; Amendment 15 barrier-exclusion contract remains unmeasured, not falsified |
| 372 | `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` — RED | blocked upstream by the same mechanical vertex-30 failure; Euler-cut contract remains unmeasured, not falsified |
| 373 | `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle` — PASS | synthetic-only evidence with zero gate credit; the mechanical zero-unbound proof remains owed |

## 4. Regression and candidate disposition

TB6 does not lose any accepted-green behavior: ordinals 1–365 remain 365/365 green. It therefore adds **+0 stable
events / +0 stable recurrences**.

- `M3-CP4c3-TB5-CAND-01` silent seed-drop: **runtime-cleared as the first failure surface**; vertex 11 is no longer
  the stopping locus.
- `M3-CP4c3-TB5-REV-CAND-01` exactness violation: CB7's exact path is the executed source authority; no float
  round-trip diagnosis reappears. The checkpoint remains red for a later transit/election question.
- `M3-CP4c3-TB3-R1-CAND-01`: **ACTIVE**. Runtime returns to vertex 30 with two published candidate faces, but the
  Amendment-17 falsifier cannot be adjudicated from the emitted artifact.
- New `M3-CP4c3-TB6-CAND-01`: **ACTIVE / DIAGNOSTIC-PROJECTION GAP / NON-STABLE** — the production failure surface
  does not publish the exact per-state/election fields CB7 compiled, so the gating red is not fine-grained enough
  to distinguish the frozen Amendment-17 hypotheses.
- `M3-CP4c3-TB4-DIAG-CAND-01`: **witness-precondition issue resolved**; ordinal 370 no longer fails in atlas
  construction. Its successor product contract is now genuinely measured and red under `M3-CP4c2-TB-X2-R8-CAND-02`.
- Sphere and saturation candidates remain active exactly as observed at 368/369; no semantic correction is
  authorized by this TB.
- `M3-CP4c3-DEFN-R1-CAND-01` remains partial because ordinal 373's synthetic pass does not establish the mechanical
  zero-unbound condition.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**.
Semantic M3 package count remains **73**; TB6 created no semantic package.

## 5. Stop decision

TB6 is a valid semantic red. Per the binding turn workflow, execution stops here and routes to independent
`M3-CP4c-3-TB6-REV` REVIEW + PLAN. That review must reconstruct the exact vertex-30 state/election path from CB7
source and the mechanical fixture, determine why the authoritative production diagnostic omits the compiled exact
state/election evidence, adjudicate Amendment 17 without guessing from `publishedFaceCount=2`, resolve the
selector-governance status of CB7's compiled-but-unselected minimal exact witness, and classify the newly genuine
ordinal-370 product red. No unchanged TB retry, code patch, fixture repair, selector edit, rebuild, repackage, or
sphere fix is authorized before that review.
