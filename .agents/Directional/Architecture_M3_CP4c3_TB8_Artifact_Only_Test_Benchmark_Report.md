# M3-CP4c-3-TB8 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-3-TB8`
**Date:** 2026-09-01 UTC
**Verdict:** **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366**
**Next turn:** independent `M3-CP4c-3-TB8-REV` REVIEW + PLAN under
`Architecture_M3_CP4c3_TB8_Independent_Review_Plan.md`. No unchanged TB retry, semantic correction, rebuild,
repackage, or acceptance attempt is authorized before review.

## 1. Immutable authority

TB8 consumed only immutable package **78** built from semantic source
`e2b59295c9920db5685239c2da188858839fa94f`.

- final compile run/job: `33556556002 / 100018687726`
- package run/job: `33557613904 / 100022216004`
- package artifact: `9819958467`
- Actions package SHA-256:
  `81414f18af71d5aacf50231a720b2774df71d88b223283c81ce747d13a977a51`
- inner `package78.tar.gz` SHA-256:
  `2cc3541cab1208781e234948228baa2d2b8d7bfdb12d855e6fd912cb30006591`
- packaged source archive SHA-256:
  `c1eadfdc4c1f118b34f9996aec00c2b51537e45e201ff52225b1d06b0d253d11`
- gating selector 374 SHA-256:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`
- diagnostic selector 375 SHA-256:
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`
- authoritative TB8 run/job: `33561723204 / 100035596811`
- result artifact: `9821602279`, Actions SHA-256
  `e9858ac5194646f888a193937e52cc504aa36a6940d79904b36f70c059026a62`
- log artifact: `9821602943`, Actions SHA-256
  `1f41626b53642bb30a00bcaafbbc3993d09870c20c2ffc15f2224670ecc65239`

Caller-schema validation passed before the runtime job. Immutable preflight then re-proved package/source/selector
identity, manifests, clean source records, GMP/GMPXX authority, executable modes, fixture/binary counts, and the
one-owner executable mapping. No configure, compile, relink, package repair, generated discovery, product/test/
fixture/selector mutation, or benchmark occurred in TB8.

## 2. Ordered semantic gate

TB8 ran gating selector **374 from ordinal 1**, one exact identity per fresh process. Every exact filter selected one
test.

- ordinals **1–365: 365/365 PASS**
- ordinal **366: RED**
- identity:
  `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- target: `directional_surface_cell_producer_tests`
- exit code: `1`
- observed production failure:
  `NotProductionReady/field-aligned-network;detailCode=InvalidNetworkTerminalOwnership`
- typed locus:
  - `sourceEdge=36-38`
  - `sourceFace=(36,38,39)`
  - `branch=2`
  - `publishedFaceCount=0`

This is a **new valid semantic masking locus**. In particular, ordinal 366 no longer reports the TB7
`VertexTransitSeedUnavailable` failure at source vertex 11. CB10 therefore moved the mechanical production path past
that former stop. The new failure does not serialize the old inappropriate `sourceVertex` locus, which is consistent
with CB10's diagnostic-locus correction.

The mechanical path still does not reach vertex 30. TB8 therefore provides no runtime acceptance of the frozen
row-209/row-208 owner election there, and row 41 remains a prohibited result rather than an observed one.

Accepted semantic authority remains **365/365**.

## 3. Full report-only remainder — zero gate credit

After gate credit fixed at ordinal 366, TB8 executed every later ordinal **367–374** once in fresh processes with zero
gate credit. Result: **1 PASS / 7 RED**.

| Ordinal | Identity/result | Runtime disposition |
|---|---|---|
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` — RED | blocked by the same new `InvalidNetworkTerminalOwnership` locus; no independent region/face-walk conclusion |
| 368 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` — RED | preserves the established `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable` sphere finding |
| 369 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` — RED | again reports `certificate.saturationUsed=true`; existing quality/coverage candidate remains active |
| 370 | `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` — RED | preserves the existing genuine product-contract red: `CellularityNotEstablished` rather than required `EmptyNetworkOnClosedSurface`, with the required source-face locus still absent |
| 371 | `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` — RED | blocked by the same new terminal-ownership failure |
| 372 | `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` — RED | blocked by the same new terminal-ownership failure |
| 373 | `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle` — PASS | synthetic-only pass with zero gate credit; mechanical zero-unbound evidence remains owed |
| 374 | `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` — RED | still stops at `ASSERT_TRUE(atlasBuild)` on the already-reviewed invalid folded-cone witness; it does not reach the exact-fallback/owner discriminator and creates no new review obligation by itself |

The first red is ordinal 366, not the pre-classified ordinal-374 witness. The mandatory successor is therefore an
independent review of the new terminal-ownership locus.

## 4. Diagnostic identity 375 — zero gate credit

Diagnostic identity **375**,
`ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries`, executed exactly once in a fresh
process and **PASSed**, with zero gate credit.

Together with gating identities **328**
`ResolvedBranchContinuation.RejectsUnresolvedRegularVertexSector` and **329**
`ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`, which also pass in the 365-prefix,
TB8 gives runtime evidence that CB10's exact closed-wedge radial-arrival correction and the repaired audit/projection
consumer surface are reachable and functioning.

This closes the TB7 radial-arrival admissibility mechanism and the TB7-REV consumer/reachability defect. It does **not**
close the general `M3-CP4c3-DEFN-R2-CAND-01` exact-fallback/budget class: ordinal 374 still fails before that
non-flat folded-cone discriminator is reached, and vertex 30 is still runtime-unmeasured.

## 5. Regression and candidate disposition

TB8 loses no accepted-green behavior: ordinals 1–365 remain green. CP4c-3 is still unaccepted, so stable accounting
changes by **+0 events / +0 recurrences** and remains:

- **44 events / 14 categories / 30 recurrences**
- produced-witness debt **5**
- authoritative semantic M3 package count **75**

Candidate disposition:

- new `M3-CP4c3-TB8-CAND-01`: **ACTIVE / GATING / FIRST-FAILURE / NON-STABLE** for
  `InvalidNetworkTerminalOwnership` at source edge `36-38`, source face `(36,38,39)`, branch 2,
  `publishedFaceCount=0`; owner is independent `M3-CP4c-3-TB8-REV`.
- `M3-CP4c3-TB7-CAND-01`: **CLOSED / RUNTIME PROVED**. Ordinal 366 clears the source-vertex-11 seed stop and
  diagnostic 375 proves both exact radial `FaceInterior` arrival orientations.
- `M3-CP4c3-TB7-REV-CAND-01`: **CLOSED / RUNTIME PROVED** for its audit-object reachability and rendering/consumer
  defect. Gating identities 328/329 and diagnostic 375 exercise the repaired diagnostic surfaces.
- `M3-CP4c3-TB6-CAND-01`: remains **ACTIVE** for the mechanical vertex-30 owner/projection acceptance condition.
  CB10's generic projection surface now has runtime evidence, but TB8 does not reach vertex 30.
- `M3-CP4c3-DEFN-R2-CAND-01`: remains **ACTIVE**; the general non-flat exact-fallback/budget discriminator is still
  unreached.
- `M3-CP4c3-TB7-CAND-02`: remains **ACTIVE / DEFERRED / PRE-CLASSIFIED WITNESS PRECONDITION**; ordinal 374 repeats the
  known stop and adds no new product evidence.
- the prescribed-sphere, saturation, ordinal-370, and mechanical singularity-binding dispositions remain unchanged.

## 6. Immutable postflight

Postflight is **PASS**. TB8 reverified the package manifest, source archive, selector hashes, executable modes, and
the complete package-tree byte/mode census. Final control state records:

- `runtimeExecution=true`
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

Package 78 remained immutable throughout authorized runtime.

## 7. Stop decision

TB8 is a **valid semantic red** under the frozen stop rule. CP4c-3 remains **OPEN** and accepted authority remains
**365/365**. No unchanged retry is allowed.

Exact successor is independent `M3-CP4c-3-TB8-REV` REVIEW + PLAN. That review must reconstruct and classify the new
`InvalidNetworkTerminalOwnership` locus before authoring any correction, preserve the independently owned sphere,
saturation, ordinal-370, ordinal-374 and mechanical zero-unbound debts, reconcile the candidate/accounting state, and
freeze exactly one bounded successor for the earliest gating owner.
