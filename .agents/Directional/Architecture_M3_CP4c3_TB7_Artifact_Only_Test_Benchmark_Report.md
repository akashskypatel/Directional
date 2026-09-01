# M3-CP4c-3-TB7 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-3-TB7`
**Date:** 2026-09-01 UTC
**Verdict:** **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366**
**Next turn:** independent `M3-CP4c-3-TB7-REV` REVIEW + PLAN under
`Architecture_M3_CP4c3_TB7_Independent_Review_Plan.md`. No unchanged TB retry, product/test/fixture/selector
correction, rebuild, repackage, or acceptance attempt is authorized before review.

## 1. Immutable authority

TB7 consumed only immutable package **76** built from semantic source
`e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`.

- package artifact: `9811964367`
- Actions package ZIP SHA-256:
  `5c7d27996aa43ef798aa8110df756fc34bbcb6d490356bdfaea249c3953cc949`
- inner deterministic `package76.tar.gz` SHA-256:
  `a940ee61c29a1c4e25040dad6353ad54152a0d6181da3450a8fe771dfc170f8e`
- packaged source archive SHA-256:
  `71b86aafae465b5dcb1763cc3e0250b4310b188d8f2d6e34ac8d7b8c6c74f6ea`
- selector 373 SHA-256:
  `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- selector 374 SHA-256:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`
- authoritative TB7 run/job: `33541437165 / 99968443127`
- result artifact: `9813862211`, Actions SHA-256
  `814157162acfb95e785d4f5af3c886696534a0972942ac1f685d64b1c04086f0`
- log artifact: `9813862640`, Actions SHA-256
  `188d02d98928ccaf29d2e899918e487c35c186b96550044ac0138d48defea1a4`

The workflow caller schema check passed before the runtime job. Immutable preflight then re-proved the package/source
digests, recursive manifest, clean source records, exact GMP/GMPXX authority, build/preflight exit codes, 27
package-relative fixtures, six executable packaged binaries, selector 373/374 hashes/cardinality/uniqueness and
lineage, and a one-owner static executable mapping for all 374 identities.

No configure, compile, relink, generated discovery, package repair, source/product/test/fixture/selector mutation, or
benchmark was performed in TB7.

## 2. Ordered semantic gate

TB7 ran selector **374 from ordinal 1**, one exact identity per fresh process. Every filter selected exactly one test.

- ordinals **1–365: 365/365 PASS**
- ordinal **366: RED**
- identity:
  `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- target: `directional_surface_cell_producer_tests`
- exit code: `1`
- observed production failure:
  `NotProductionReady/field-aligned-network;detailCode=VertexTransitSeedUnavailable`
- typed locus:
  - `sourceVertex=11`
  - `sourceFace=(8,10,11)`
  - `branch=1`
  - `topologyRegion=0`
  - `arrivalMode=FaceInterior`
  - `publishedFaceCount=0`
  - `barrierAbsorbed=false`
  - `barrierIncident=false`

The first red occurs **before** the mechanical witness reaches CB9's developed vertex-star owner certificate. TB7
therefore does not prove the intended row-209/row-208 continuation, does not prove the AX8 projection at the
mechanical locus, and does not provide runtime acceptance of Amendments 22/23. It also does not prove that the old
vertex-30 defect remains: the earlier source-vertex-11 stop masks all later mechanical transit behavior.

The locus is closely related to TB5's source-vertex-11 first-failure surface, but the typed failure is now
`VertexTransitSeedUnavailable` rather than TB5's zero-candidate `VertexTransitSectorUnresolved`. Equivalence,
recurrence, or a new mechanism must be decided by independent review; TB7 does not infer one from the shared vertex.

Accepted semantic authority therefore remains **365/365**.

## 3. Full report-only remainder — zero gate credit

After the gate verdict was fixed, TB7 executed every remaining ordinal **367–374** exactly once, one identity per
fresh process, with zero gate credit.

Authoritative remainder result: **1 PASS / 7 RED**.

| Ordinal | Identity/result | Runtime disposition |
|---|---|---|
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` — RED | blocked by the same source-vertex-11 `VertexTransitSeedUnavailable`; no independent region/face-walk conclusion is creditable |
| 368 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` — RED | reproduces `surface-cut-graph/CellularityNotEstablished`, originating `RotationSystemInconsistent → TraceEventPositionInvalid`; trace 2/event 30 again reports `claimedSourceEdge=none` and `NoCarrierMatch / SourceEdgeUnavailable` |
| 369 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` — RED | reaches the intended assertion and again reports `certificate.saturationUsed=true`; existing quality/coverage candidate remains active |
| 370 | `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` — RED | reproduces the genuine product-contract red: actual error code `CellularityNotEstablished` (4), expected `EmptyNetworkOnClosedSurface` (6), and required `sourceFace` locus absent |
| 371 | `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` — RED | blocked upstream by the same source-vertex-11 transit failure; barrier-cycle contract remains unmeasured |
| 372 | `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` — RED | blocked upstream by the same source-vertex-11 transit failure; Euler-cut contract remains unmeasured |
| 373 | `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle` — PASS | synthetic-only pass with zero gate credit; mechanical zero-unbound evidence remains owed |
| 374 | `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` — RED | fails at `ASSERT_TRUE(atlasBuild)` before the folded-cone vertex-star authority executes; the test does not print the typed atlas error, so witness-precondition versus product rejection is not classified in TB7 |

Ordinal 374 is a new gating result and must not be read as a failure of the exact fallback or the one-ray election:
those paths were not reached. It is also not permission to weaken atlas validation. Independent review must recover
the exact atlas error and adjudicate the witness precondition first.

## 4. Regression and candidate disposition

TB7 loses no accepted-green behavior: ordinals 1–365 remain 365/365 green. CP4c-3 is still unaccepted. Stable
accounting therefore changes by **+0 events / +0 recurrences** and remains:

- **44 events / 14 categories / 30 recurrences**
- produced-witness debt **5**
- semantic M3 package count **74**; TB7 creates no package.

Candidate disposition:

- new `M3-CP4c3-TB7-CAND-01`: **ACTIVE / GATING / FIRST-FAILURE / NON-STABLE** for
  `VertexTransitSeedUnavailable` at source vertex 11. TB5's former source-vertex-11 record is not automatically
  reopened or counted as a recurrence; review must prove whether the mechanism is the same.
- new `M3-CP4c3-TB7-CAND-02`: **ACTIVE / GATING / UNCLASSIFIED WITNESS-PRECONDITION OR PRODUCT / NON-STABLE** for
  ordinal 374's `atlasBuild=false` stop with no typed error published.
- `M3-CP4c3-TB6-CAND-01`: CB9 compiled the frozen AX8 projection correction, but TB7 first-reds before the
  mechanical certificate is reached. Runtime closure is therefore **not measured**.
- `M3-CP4c3-DEFN-R2-CAND-01`: CB9 compiled the filter/fallback/budget implementation, but ordinal 374 stops before
  vertex-star evaluation and ordinal 366 stops at seed construction. The exact fallback's runtime closure condition
  remains unmeasured.
- `M3-CP4c2-TB-X2-R10-CAND-01`: remains ACTIVE; ordinal 369 again reports saturation.
- `M3-CP4c2-TB-X2-R8-CAND-02`: remains ACTIVE; ordinal 370 reproduces the same genuine product red.
- `M3-CP4c3-DEFN-R1-CAND-01`: ordinal 373 passes synthetically, but its mechanical zero-unbound condition remains
  unproved.
- the prescribed-sphere `NoCarrierMatch / SourceEdgeUnavailable` finding remains reproduced/deferred.
- CB9 static audit candidates `M3-CP4c3-CB9-AUDIT-01` and `M3-CP4c3-CB9-AUDIT-02` remain static follow-up debt and
  are not converted into runtime events by TB7.

## 5. Immutable postflight

Postflight is **PASS**.

TB7 reverified the recursive package manifest, source archive, selector 357/358/361/365/367/370/373/374 hashes,
binary executable modes, and the complete preflight package byte/mode census. The final control record proves:

- `configureExecution=false`
- `compileExecution=false`
- `relinkExecution=false`
- `packageRepair=false`
- `generatedDiscovery=false`
- `productMutation=false`
- `testMutation=false`
- `fixtureMutation=false`
- `selectorMutation=false`
- `benchmarkExecution=false`

The package remained immutable throughout the semantic run.

## 6. Process and evidence notes

The runtime workflow itself completed successfully because semantic red is an evidence result, not an orchestration
failure. The result artifact is authoritative for the 365-pass prefix, first-red ordinal 366, full zero-credit
remainder, and postflight.

A closeout source snapshot was already captured by run `33542254059` at control SHA
`5672defdd1f0b918d9c39fa9b510c2c30ae2e7ac`; source snapshot artifact `9814061554` has Actions SHA-256
`12797c1f2103f36e98ad906755d0f11a5e1c5d5e9612fd585b6690736cd38656` and inner archive SHA-256
`421890ddfc10fad40c85d38f9c971abd54f766de325e201441cac830e419481a`. It is document/control authority only and
does not replace package 76 as TB7 semantic authority.

During continuation after interruption, remote state was discovered to have already completed draft validation,
workflow publication, and TB7 runtime. One redundant Drive-apply trigger was created before that remote-ahead state
was discovered. It is control-plane-only, carries no semantic evidence, and must be removed during formal cleanup.

## 7. Stop decision

TB7 is a **valid semantic red** under the frozen stop rule. CP4c-3 remains **OPEN** and accepted authority remains
**365/365**. No unchanged retry is allowed.

Exact successor is independent `M3-CP4c-3-TB7-REV` REVIEW + PLAN. That review must:

1. establish why the mechanical arrival at source vertex 11 cannot produce the frozen `VertexStarRaySeed`, including
   whether this is the TB5 mechanism reintroduced or a distinct CB9 seed-authority defect;
2. determine whether the AX8 projection and exact-kernel implementation are correct but simply unreached, or share
   the seed failure;
3. recover ordinal 374's exact atlas-build error and decide whether the folded-cone witness violates an atlas
   precondition or exposes a product defect;
4. preserve the independent sphere, saturation, ordinal-370, and singularity-binding dispositions unless evidence
   proves a shared owner;
5. freeze exactly one bounded successor before any semantic patch or retry.
