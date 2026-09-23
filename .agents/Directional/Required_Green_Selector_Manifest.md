# Required Green Selector Manifest

**Purpose — DURABLE, DO NOT DELETE.** One auditable index of every byte-frozen `Required_Green_Selector` file:
its identity count, its LF-normalized SHA-256, its prefix parent, what it appended, and its role.

This file is **derived and additive**. It changes no selector byte and grants no authority. Where it disagrees with
a selector file, **the selector file wins** — recompute with
`.agents/Directional/tools/selector_probe.py hash <n>`.

## Why every one of these files is retained

The prefix chain is the project's core safety invariant: every turn re-proves that accepted selector **365** is an
exact prefix of the current gate. **That check has force only because 365's bytes are stored independently of the
current gate file.** Collapsing the chain into one file plus line counts would make the check compare a file
against itself, so it could never fail — deleting the witness while keeping the assertion.

Each file is also hash-pinned in an immutable Test + Benchmark report and a GitHub Actions artifact, and
`tools/review_check.py boundary` re-verifies every hash against HEAD each turn. Consolidation, renaming, or
deletion of any selector file requires explicit user authorization; `M3_CP4c_Frozen_Definitions.md` Parts IV and V
additionally prohibit changing the bytes of 357, 358, 361, 365 and 367.

## Naming — read this before deriving a count from a filename

Selector files **357 through 384** are each named by their identity count. **This no longer holds.**
`Architecture_M3_CP4c3_Required_Green_Selector_385.txt` is named 385 and contains **388** identities, because
`M3-CP4c-3-CB22` appended four witnesses under a plan whose wording predicted one file number. Its bytes are
frozen, hash-verified and correct and it must **not** be renamed.

**Never derive an identity count from a selector filename. Use the `identities` column below.**
Future selector files are named by their resulting identity count.

## The chain

| Selector | Identities | LF SHA-256 | Prefix parent | Appended | Role |
|---|---:|---|---|---:|---|
| **357** | 357 | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` | - | - | superseded |
| **358** | 358 | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` | **none** | - | withdrawn |
| **361** | 361 | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` | **none** | - | superseded |
| **365** | 365 | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` | 361 | 4 | **ACCEPTED AUTHORITY** |
| **367** | 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` | 365 | 2 | superseded |
| **370** | 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` | 367 | 3 | superseded |
| **373** | 373 | `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` | 370 | 3 | superseded |
| **373** | 373 | `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b` | **none** | - | superseded |
| **374** | 374 | `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` | **none** | - | superseded |
| **375** | 375 | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` | 374 | 1 | superseded |
| **376** | 376 | `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8` | 375 | 1 | superseded |
| **377** | 377 | `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1` | 376 | 1 | superseded |
| **378** | 378 | `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8` | 377 | 1 | superseded |
| **379** | 379 | `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7` | 378 | 1 | superseded |
| **380** | 380 | `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4` | **none** | - | superseded |
| **380** | 380 | `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e` | **none** | - | superseded |
| **381** | 381 | `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90` | 380 | 1 | superseded |
| **382** | 382 | `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a` | 381 | 1 | superseded |
| **382** | 382 | `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f` | **none** | - | superseded |
| **383** | 383 | `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c` | **none** | - | superseded |
| **384** | 384 | `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564` | 383 | 1 | superseded |
| **385** | 388 | `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca` | 384 | 4 | superseded |
| **391** | 391 | `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0` | 385 | 3 | superseded |
| **393** | 393 | `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d` | 391 | 2 | superseded |
| **394** | 394 | `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68` | **none** | - | superseded |
| **397** | 397 | `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` | **none** | - | superseded |
| **401** | 401 | `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869` | 397 | 4 | superseded |
| **403** | 403 | `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007` | 401 | 2 | superseded |
| **403** | 403 | `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802` | **none** | - | superseded |
| **403** | 403 | `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` | **none** | - | superseded |
| **405** | 405 | `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7` | **none** | - | superseded |
| **406** | 406 | `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0` | 405 | 1 | superseded |
| **407** | 407 | `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae` | 406 | 1 | superseded |
| **408** | 408 | `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` | **none** | - | superseded |
| **408** | 408 | `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` | **none** | - | superseded |
| **409** | 409 | `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` | 408 | 1 | superseded |
| **422** | 422 | `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc` | **none** | - | superseded |
| **423** | 423 | `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343` | 422 | 1 | superseded |
| **424** | 424 | `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` | 423 | 1 | superseded accepted prefix |
| **425** | 425 | `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` | 424 | 1 | superseded accepted prefix |
| **426** | 426 | `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` | 425 | 1 | superseded accepted prefix |
| **427** | 427 | `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` | 426 | 1 | **ACCEPTED HISTORICAL PREFIX OF SELECTOR430** |
| **430** | 430 | `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` | 427 | 3 | **ACCEPTED HISTORICAL PREFIX OF SELECTOR448** |
| **448** | 448 | `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` | 430 | 18 | **ACCEPTED CURRENT AUTHORITY** |

`Prefix parent` **none** marks a file that is *not* an extension of the previous one — a superseded or withdrawn
branch carrying unique bytes. Those are not redundant with anything and cannot be reconstructed from the chain.

## Per-file notes and appended identities

### 357 — superseded

`Architecture_M3_CP4c2_Required_Green_Selector_357.txt` — 357 identities, first committed 8cf1ab312 2026-08-28.

CP4c-2 gate before the 358 branch. **Off-chain** - not a prefix of 358.

Chain root in this family.

### 358 — withdrawn

`Architecture_M3_CP4c2_Required_Green_Selector_358.txt` — 358 identities, first committed 8cf1ab312 2026-08-28.

**Off-chain** - not a prefix of 361. Retained as historical authority by DEFN-R2 AG0.

**Off-chain:** not an extension of selector 357. Holds unique bytes.

### 361 — superseded

`Architecture_M3_CP4c2_Required_Green_Selector_361.txt` — 361 identities, first committed 900da3938 2026-08-29.

First file of the current prefix chain.

**Off-chain:** not an extension of selector 358. Holds unique bytes.

### 365 — ACCEPTED AUTHORITY

`Architecture_M3_CP4c2_Required_Green_Selector_365.txt` — 365 identities, first committed 4f0f3ca74 2026-08-30.

The load-bearing boundary. Every acceptance claim cites this hash.

Appended 4 identities to selector 361:

- `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness`
- `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs`
- `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour`
- `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted`

### 367 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_367.txt` — 367 identities, first committed 4a4d5f8d0 2026-08-30.

Appended 2 identities to selector 365:

- `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`

### 370 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_370.txt` — 370 identities, first committed 4250f1bf8 2026-08-31.

Appended 3 identities to selector 367:

- `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`
- `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`
- `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError`

### 373 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_373.txt` — 373 identities, first committed 4250f1bf8 2026-08-31.

Appended 3 identities to selector 370:

- `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`
- `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity`
- `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle`

### 373 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_373.txt` — 373 identities, first committed 4250f1bf8 2026-08-31.

Appended 3 identities to selector 370:

- `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`
- `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity`
- `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle`

### 374 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_374.txt` — 374 identities, first committed e5d6ed76c 2026-09-01.

Appended 1 identity to selector 373:

- `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`

### 375 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_375.txt` — 375 identities, first committed 37e18cc58 2026-09-01.

Appended 1 identity to selector 374:

- `ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries`

### 376 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_376.txt` — 376 identities, first committed d8eb6332e 2026-09-01.

Appended 1 identity to selector 375:

- `ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection`

### 377 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_377.txt` — 377 identities, first committed a3b6f1a41 2026-09-02.

Appended 1 identity to selector 376:

- `ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort`

### 378 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_378.txt` — 378 identities, first committed 71ece3ca1 2026-09-02.

Appended 1 identity to selector 377:

- `GlobalTopologyPlan.RotationRayOrderCollisionDiagnosticsSurviveProductionFailureProjection`

### 379 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_379.txt` — 379 identities, first committed ab0501de3 2026-09-02.

Appended 1 identity to selector 378:

- `GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry`

### 380 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_380.txt` — 380 identities, first committed a2efc8d10 2026-09-02.

Appended 1 identity to selector 379:

- `GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure`

### 380 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_380.txt` — 380 identities, first committed a2efc8d10 2026-09-02.

Appended 1 identity to selector 379:

- `GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure`

### 381 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_381.txt` — 381 identities, first committed 5dcaa8be0 2026-09-02.

Appended 1 identity to selector 380:

- `GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible`

### 382 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_382.txt` — 382 identities, first committed a01016ca5 2026-09-03.

Appended 1 identity to selector 381:

- `GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`

### 382 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_382.txt` — 382 identities, first committed a01016ca5 2026-09-03.

Appended 1 identity to selector 381:

- `GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`

### 383 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_383.txt` — 383 identities, first committed 57635e873 2026-09-03.

Appended 1 identity to selector 382:

- `GlobalTopologyPlan.TraceCutFaceFragmentMismatchDiagnosticsSurviveProductionFailureProjection`

### 384 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_384.txt` — 384 identities, first committed b76d878f4 2026-09-03.

Appended 1 identity to selector 383:

- `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath`

### 385 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_385.txt` — 388 identities, first committed 9f6f3794a 2026-09-03.

Name is 385; identity count is **388**. See the naming section above.

Appended 4 identities to selector 384:

- `GlobalTopologyPlan.UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence`
- `GlobalTopologyPlan.UncutFaceComponentSeedFailureProjectsDecisionAndBoundaryEvidence`
- `GlobalTopologyPlan.FragmentOwnerEvidenceProjectsUncutComponentSeedCensus`
- `GlobalTopologyPlan.UnrelatedFailureProjectionIsByteIdenticalWithoutUncutSeedDiagnostics`

### 391 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_391.txt` — 391 identities, first committed by M3-CP4c-3-CB23.

Appended 3 identities to selector 385 (whose frozen file contains 388 identities):

- `GlobalTopologyPlan.EmbeddedGraphEulerCensusPublishesThroughMechanicalProductionFailure`
- `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure`
- `GlobalTopologyPlan.EmbeddedGraphEulerCensusCarriesAcrossTorusAndPrescribedSphereProductionPaths`

### 393 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_393.txt` — 393 identities, first committed by M3-CP4c-3-CB24.

CB24 appends two diagnostic-only projection witnesses to frozen selector 391; CB25 supersedes the vacuous diagnostic contract without changing these bytes.

Appended 2 identities to selector 391:

- `GlobalTopologyPlan.UncutFaceComponentBoundaryEvidenceRetainsDistinctSeedAndReasonRows`
- `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual`

### 394 — superseded

`Architecture_M4_CP3_Required_Green_Selector_394.txt` — 394 identities, first committed -.

**Off-chain:** not an extension of selector 393. Holds unique bytes.

### 397 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_397.txt` — 397 identities, first committed by M3-CP4c-3-CB25.

CB25 appends four diagnostic-only certificate-source and falsifiability witnesses to frozen selector 393. CB27 retains all 397 bytes unchanged.

Appended 4 identities to selector 393:

- `GlobalTopologyPlan.CertificateFaceProjectionDerivesOwnerFromCertifiedFaceWalkSide`
- `GlobalTopologyPlan.CertificateSideLookupDoesNotAliasOppositeSideOrSeed`
- `GlobalTopologyPlan.CertificatePairMeasurementCanReportNonZeroDifferingCount`
- `GlobalTopologyPlan.UnrelatedTopologyErrorLocusRemainsByteIdenticalAfterCertificateDiagnostics`

### 401 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_401.txt` — 401 identities, first committed by M3-CP4c-3-CB27.

CB27 appends four owner-map, consistency-falsifiability, and fail-closed fixture-path witnesses to frozen selector 397.

Appended 4 identities to selector 397:

- `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`
- `SurfaceCutGraph.CellularityCertificateRejectsOwnerOutsideItsCertifiedFaces`
- `GlobalTopologyPlan.CertifiedSourceFaceOwnerConsistencyCanRejectConflictingComponentOwners`
- `TestFixturePaths.MissingPackageFailsClosedInsteadOfReturningMissingPath`

**Executed at `M3-CP4c-3-TB24-EXEC`:** 389 PASS / 12 RED, accepted 1–365 = 365/365. Of the four appended
identities, 399/400/401 PASS and 398 REDs. `M3-CP4c-3-TB24-REV` classified 398 as **the honest gate** — it states
the open problem and stays gating. Ordinal **385**'s assertions will be replaced in place by CB28; its name and
ordinal do not change, so the first 401 lines stay byte-identical.

### 403 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_403.txt` — 403 identities, first authored by M3-CP4c-3-CB28.

CB28 appends two measurement/falsifiability witnesses to frozen selector 401. Selector 401 is its exact
401-line prefix and selector 397 remains the frozen prefix of that. Two gating identities are appended:

- `SurfaceCutGraph.CertifiedOwnerConflictCensusPublishesOnOwnershipFailure`
- `SurfaceCutGraph.CertifiedOwnerConflictCensusNamesANonBarrierEdgeSeparatingCertifiedFaces`

The first asserts **publication**, never a particular value; the second is the independent falsifiability witness
that splits *can* from *does*, as 399/400 did for their rules.

**Executed at `M3-CP4c-3-TB25-R1`:** 393 PASS / 10 RED, accepted 1–365 = 365/365. Both appended identities **PASS**,
and ordinals **384 and 385 recovered** from TB24's RED. `M3-CP4c-3-TB25-REV` recorded that ordinal 402's
`rowCount=0` is **structurally unable to be anything else** on the region under investigation — the census reads
only established owners, and every face of component 0 is `Unavailable`. Ordinals 402/403 stay gating and are not
withdrawn, but **neither may be cited as evidence about component 0**.

### 403 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_403.txt` — 403 identities, first authored by M3-CP4c-3-CB28.

CB28 appends two measurement/falsifiability witnesses to frozen selector 401. Selector 401 is its exact
401-line prefix and selector 397 remains the frozen prefix of that. Two gating identities are appended:

- `SurfaceCutGraph.CertifiedOwnerConflictCensusPublishesOnOwnershipFailure`
- `SurfaceCutGraph.CertifiedOwnerConflictCensusNamesANonBarrierEdgeSeparatingCertifiedFaces`

The first asserts **publication**, never a particular value; the second is the independent falsifiability witness
that splits *can* from *does*, as 399/400 did for their rules.

**Executed at `M3-CP4c-3-TB25-R1`:** 393 PASS / 10 RED, accepted 1–365 = 365/365. Both appended identities **PASS**,
and ordinals **384 and 385 recovered** from TB24's RED. `M3-CP4c-3-TB25-REV` recorded that ordinal 402's
`rowCount=0` is **structurally unable to be anything else** on the region under investigation — the census reads
only established owners, and every face of component 0 is `Unavailable`. Ordinals 402/403 stay gating and are not
withdrawn, but **neither may be cited as evidence about component 0**.

### 403 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_403.txt` — 403 identities, first authored by M3-CP4c-3-CB28.

CB28 appends two measurement/falsifiability witnesses to frozen selector 401. Selector 401 is its exact
401-line prefix and selector 397 remains the frozen prefix of that. Two gating identities are appended:

- `SurfaceCutGraph.CertifiedOwnerConflictCensusPublishesOnOwnershipFailure`
- `SurfaceCutGraph.CertifiedOwnerConflictCensusNamesANonBarrierEdgeSeparatingCertifiedFaces`

The first asserts **publication**, never a particular value; the second is the independent falsifiability witness
that splits *can* from *does*, as 399/400 did for their rules.

**Executed at `M3-CP4c-3-TB25-R1`:** 393 PASS / 10 RED, accepted 1–365 = 365/365. Both appended identities **PASS**,
and ordinals **384 and 385 recovered** from TB24's RED. `M3-CP4c-3-TB25-REV` recorded that ordinal 402's
`rowCount=0` is **structurally unable to be anything else** on the region under investigation — the census reads
only established owners, and every face of component 0 is `Unavailable`. Ordinals 402/403 stay gating and are not
withdrawn, but **neither may be cited as evidence about component 0**.

### 405 — SUPERSEDED BY 406

`Architecture_M3_CP4c3_Required_Green_Selector_405.txt` — **405 identities**, authored by M3-CP4c-3-CB30, LF SHA-256 `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`. Selector 403 is its exact 403-line prefix, selector 401 its exact 401-line prefix, and selector 397 remains byte-frozen. Two gating identities are appended:

- `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure`
- `SurfaceCutGraph.VertexTransitCensusNamesAFaceSeparationNoSourceEdgeBarrierCanCarry`

The first asserts **publication and completeness** of the three CJ6 censuses with **no established owner
required** — the defect that made ordinal 402 vacuous must not recur. The second is the independent falsifiability
witness on a constructed vertex-transit fixture. Ordinal **390**'s assertions were replaced in place by CJ8; its name and ordinal do not change, so the first 403 lines stay byte-identical. CB30 compile authority is source `e045bf7147afc02bd90eff4822e4b609edbaba66`, package `9957324848`.

**Executed at `M3-CP4c-3-TB26-R1`:** 397 PASS / 8 RED, accepted 1–365 = 365/365. Both appended identities **PASS**,
and ordinals **389 and 390 recovered** from TB25-R1's RED. `M3-CP4c-3-TB26-INDEPENDENT-REVIEW` recorded that
ordinal **404's PASS proves publication but not readability**: it asserts the in-memory census is complete while
the runtime serializes only aggregate counts, so the per-arc dart-orbit pair that decides the frozen discriminator
is not auditable from the immutable log. **Ordinal 404 must not be cited as evidence that the separating-arc horn
is selected.** CK8 strengthens it in place; the identity is not withdrawn.

### 406 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_406.txt` — **406 identities**, authored by
`M3-CP4c-3-CB31`, LF SHA-256
`efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`. Selector 405 is its exact
405-line prefix, with 403/401/397/365 the frozen prefixes of that. One gating identity is appended:

- `GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent`

It asserts that both partition identities and both face-set digests are published and that the failure locus states
**whether they match** — **publication of the correspondence, never equality**, because inequality is a live
possibility and a gate must not demand a hypothesis be true (`LESSONS.md` 123). Ordinals **404** and **393** have
their assertions replaced in place by CK8; their names and ordinals do not change, so the first 405 lines stay
byte-identical.

**Compiled at `M3-CP4c-3-CB31`:** semantic source
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`; run/job
`33940038189 / 101235542774`; result/log artifacts `9961564041 / 9961564295` with SHA-256
`ca1b69de319fba92e0c6accc580e698f2430505eb811e821c03d44e6629263cf` /
`f05d03dfe8457fe93c49a086915f1a69069ceb50726a02f0463887a734b4d73a`. Release/static `PRE_TEST`
compiled all eight approved targets with GMP/GMPXX linked; preflight and build exit codes are zero and
`runtimeExecution=false`. This is compile authority only, not semantic acceptance. Exact successor:
`M3-CP4c-3-TB27`, artifact-only execution of selector 406.

**Executed at `M3-CP4c-3-TB27-R1`:** formal run/job `33946094875 / 101252363079` on immutable package
`9961564041` produced **399 PASS / 7 RED**, accepted **1–365 = 365/365**. RED
`[366,367,368,369,370,374,398]`; ordinal393 recovered to PASS and ordinals404/406 PASS. Result/log artifacts
`9963419649 / 9963419830`; ledger SHA-256
`8da2002701437c5d0c4a57d613e24195f4f690d1ae4494da1234d58bb9a24da5`. Ordinal406 publishes
`matchesFailingComponent=false` between the plan `EmptyFragmentOrbits` failure partition and certifier
`NotTraceCut` census partition. Selector bytes are unchanged.

**Adjudicated at `M3-CP4c-3-TB27-INDEPENDENT-REVIEW`:** ordinals 404 and 406 are the first diagnostic gates in this
checkpoint whose PASS is **also readable** — 404 publishes all four interior-arc rows with both dart orbits (arc 14
`(0,1)` and arc 22 `(0,3)` separating), and 406 proves the census and the failure are different partition objects.
**Ordinal 404 still may not be cited as evidence about the failing plan component**, because it describes the
certifier's. Ordinal **393**'s repaired coverage contract is runtime-proved. CL6 strengthens 404 in place; no
identity is withdrawn.

### 407 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_407.txt` — **407 identities**, authored by
`M3-CP4c-3-CB32`, LF SHA-256
`9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`. Selector 406 is its exact 406-line
prefix in the CB32 packaged source (LF SHA-256
`efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`), with the earlier frozen prefix chain
retained. One gating identity is appended:

- `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions`

CB32 also strengthens ordinal **404** in place so the failing/certifier arc-locus publication is complete and bound
to crossed source faces, component ids in both partitions, and typed trace-cut miss reasons. Its name and ordinal do
not change, preserving the selector406 prefix. The appended identity remains a publication/completeness gate; it
does not require the eventual correction branch to take a hypothesized value.

**Compiled at `M3-CP4c-3-CB32`:** semantic evidence source
`098ac7d93ea203222dd0ac50cdb68667744f0fd4`; run/job `33987769718 / 101364411259`; result/log artifacts
`9975737868 / 9975738137` with SHA-256
`16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec` /
`ba2a7c97532f328bb50742c2de31dfd106d130b4ec4533e434250bceb9ec36ae`. Release/static Code + Build compiled all
eight approved targets with GMP/GMPXX linked; preflight/full build succeeded and `runtimeExecution=false`. This is
compile authority only, not semantic acceptance.

**Execution status.** `M3-CP4c-3-TB28-R1` failed before runtime on a `SHA256SUMS.txt` layout assumption.
`M3-CP4c-3-TB28-R2` reported `407 PASS / 0 RED` and was **REJECTED as orchestration-invalid** at
`M3-CP4c-3-TB28-INDEPENDENT-REVIEW`: selector 407 contains ordinals 366/367/398, all RED at TB27-R1, and CB32's
source diff is diagnostic-only, so **no behaviour change can account for the status change**. The report also
omitted the ledger, identity map, RED ordinals, accepted-prefix count, censuses and resource evidence this
selector's frozen plan requires, and recorded one runtime binary hash where the package holds five test
executables. **Selector 407 has therefore never been validly executed**, and its `407 PASS` figure may not be
quoted as a gate result or an accepted-prefix result. `LESSONS.md` 129, 130.

**Validly executed at `M3-CP4c-3-TB28-R3`** — run/job `33995961030 / 101386467115` on the same immutable package
`9975737868`, harness `b3191b314afa22f72e6f720519cfa2f8ad090dce3de5617612ad64c195489fbf`, ledger
`fa0626b8a28c0f2758e68e2be712fff024197e445be46e46c9491395cc0609ac`: **400 PASS / 7 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, **every row `selected=1`**. Ordinals 404, 406 and the
appended 407 PASS. Against TB27-R1's 399 PASS / 7 RED on selector 406, **the delta is exactly the appended
identity** — the control that settled the TB28-R2 false green. Promoted to runtime authority at
`M3-CP4c-3-TB28-R3-REV`.

**Exact successor:** `M3-CP4c-3-CB34`, which applies the frozen **separating-arc barrier rule** and may require an
appended witness at selector **408**, with 407 as an exact prefix, asserting the rule's **effect on the census** and
never a predicted owner value. Ordinals 397–407 keep their contracts and none may be weakened to obtain a green.

### 408 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_408.txt` — **408 identities**, authored by `M3-CP4c-3-CB34`, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`.

CB34 appends one separating-arc barrier-rule census-effect witness to frozen selector 407.

Appended 1 identity to selector 407:

- `SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus`

**Compiled at `M3-CP4c-3-CB34`:** semantic evidence source
`25ab3d55697598bde436d1ac811d71e6cf911f2e`; run/job `34001505322 / 101401105075`; result/log artifacts
`9979639398 / 9979639588` with SHA-256
`c7e35682b9d38b8e8b7916e6030cc2bd3fd4172d0dfc49be83d09a4b0a45ecf2` /
`de006914c3874c7d607d4deb34e39f17c08b847d708e96c99a9957d455d40f3c`. All eight approved targets compiled
with GMP/GMPXX linked and `runtimeExecution=false`; root package `SHA256SUMS` is 28/28 PASS. This is compile
authority only. Selector 408 is not semantically accepted until TB29.

**Executed at `M3-CP4c-3-TB29`** — run/job `34002726062 / 101404386206`, ledger
`3199d7117dbed28dd23dd22cefb543ff43f449a5a2aa859075f543a8f6195f51`: **399 PASS / 9 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,390,398,404]`, **every row `selected=1`**. Promoted to runtime
authority at `M3-CP4c-3-TB29-REV`.

Ordinal **408 PASSes on its first execution** and proves all three properties of the separating-arc barrier rule:
no separating arc remains interior to any uncut component; every separating-arc crossed face leaves the uncut
census; and **every equal-orbit terminal-slit face is preserved** — the rule does not over-cut. This is the first
identity in the checkpoint to assert the *effect* of a product correction and pass on it.

Ordinals **390** and **404** changed PASS → RED and are **test authority, not product**: 404 requires that no face
has established ownership — an out-of-contract assertion introduced at CB31 that passed vacuously while ownership
was failing — and 390 matches the plan and certifier partitions **by component index**. Both have their assertions
replaced in place at **CO6 / CB35**; names, ordinals and selector bytes do not change, so selector 408 stays
byte-identical and no new selector is authored.

**Re-executed at `M3-CP4c-3-TB30`** — run/job `34008104497 / 101418934144` on immutable CB35 package
`9980764888`, ledger `974fed9db1958ee7eb07df77097544199deeb61d663b1d366a37b54d64feeab0`: **401 PASS / 7 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, every row `selected=1`. **Ordinals 390 and 404
returned to PASS** with **no selector byte changed** — CB35 replaced their assertions in place — and the
credibility controls 366/367/398 stayed RED as required. Promoted to runtime authority at `M3-CP4c-3-TB30-REV`.

Two dispositions this selector must carry forward:

- **Ordinal 398 is not an ownership gate.** It fails on the **prescribed sphere**
  (`NotProductionReady/CellularityNotEstablished`), ordinal 368's surface. Certified source-face ownership is
  **total** — 300 established / 0 unavailable / 0 conflicting. **398 must not be re-scoped to exclude the sphere**,
  and its colour must not be read as an ownership signal.
- **Ordinals 366 and 367 are the whole remaining ownership frontier**, awaiting the same frozen guard at
  `GlobalTopologyPlan.cpp:830`.

**Re-executed at `M3-CP4c-3-TB31`** — run/job `34011402843 / 101427791582` on immutable CB36 package `9982174864`,
ledger `6632f428243788c98c816571f47ef0cf98df25a57274b2df75612674d563250b`: **397 PASS / 11 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`, every row `selected=1`. **CB36 authored no
selector change**, so selector 408 has now carried three runtimes unchanged.

What this execution recorded:

- **The seed-uniqueness frontier is CLOSED.** Component 0 moved from 191 faces / seedCount 3 / `Multiple` /
  `[0,1,3]` to **189 / 1 / `Unique` / `[0]`**; certified ownership remains **300 / 0 / 0**.
- **Ordinals 404 and 408 stayed PASS** through both product corrections. They are the two identities written to
  assert **publication and completeness** rather than an outcome, and that is why they survived the frontier
  moving.
- **Ordinals 390, 393, 406 and 407 went PASS → RED as pinned witnesses** — each expected
  `UncutFaceComponentOrbitSeedNotUnique` and received `TraceArcDoesNotSeparateItsSides`. Their assertions are
  repaired **in place** by `M3-CP4c-3-DEFN-R4`; names, ordinals and selector bytes do not change.

**Selector 408 has now carried five runtimes unchanged** — TB29, TB30, TB31, TB32 and TB33 — across four product
corrections. At `M3-CP4c-3-TB33` it recorded **401 PASS / 7 RED**, accepted **1–365 = 365/365**, RED
`[366,367,368,369,370,374,398]`, every row `selected=1`, on immutable CB38 package `9994997588`.

Two facts this selector must carry forward:

- **Ordinals 404 and 408 have never gone RED across four consecutive forward steps.** They are the two identities
  written to assert **publication and completeness** rather than an outcome, and that is why they survived every
  frontier move. Treat them as the template.
- **Ordinals 390, 393, 406 and 407 returned to PASS** once each was given a **justified cleared-stage** outcome —
  the stage failed and published, or the stage was cleared and the later failure published its labelled evidence.
  Their assertions were replaced in place; no selector byte changed.

**CB39 result:** selector **409** appends 408 as an exact 408-line prefix and one gating identity,
`GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` — a constructed negative proving that two
node-disjoint boundary loops are still rejected with reason `ArcChainBroken` after the `current == start` disjunct
is removed. It asserts a constructed rejection, never a value on the production fixture. Ordinals 397–408 keep
their contracts.

### 408 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_408.txt` — **408 identities**, authored by `M3-CP4c-3-CB34`, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`.

CB34 appends one separating-arc barrier-rule census-effect witness to frozen selector 407.

Appended 1 identity to selector 407:

- `SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus`

**Compiled at `M3-CP4c-3-CB34`:** semantic evidence source
`25ab3d55697598bde436d1ac811d71e6cf911f2e`; run/job `34001505322 / 101401105075`; result/log artifacts
`9979639398 / 9979639588` with SHA-256
`c7e35682b9d38b8e8b7916e6030cc2bd3fd4172d0dfc49be83d09a4b0a45ecf2` /
`de006914c3874c7d607d4deb34e39f17c08b847d708e96c99a9957d455d40f3c`. All eight approved targets compiled
with GMP/GMPXX linked and `runtimeExecution=false`; root package `SHA256SUMS` is 28/28 PASS. This is compile
authority only. Selector 408 is not semantically accepted until TB29.

**Executed at `M3-CP4c-3-TB29`** — run/job `34002726062 / 101404386206`, ledger
`3199d7117dbed28dd23dd22cefb543ff43f449a5a2aa859075f543a8f6195f51`: **399 PASS / 9 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,390,398,404]`, **every row `selected=1`**. Promoted to runtime
authority at `M3-CP4c-3-TB29-REV`.

Ordinal **408 PASSes on its first execution** and proves all three properties of the separating-arc barrier rule:
no separating arc remains interior to any uncut component; every separating-arc crossed face leaves the uncut
census; and **every equal-orbit terminal-slit face is preserved** — the rule does not over-cut. This is the first
identity in the checkpoint to assert the *effect* of a product correction and pass on it.

Ordinals **390** and **404** changed PASS → RED and are **test authority, not product**: 404 requires that no face
has established ownership — an out-of-contract assertion introduced at CB31 that passed vacuously while ownership
was failing — and 390 matches the plan and certifier partitions **by component index**. Both have their assertions
replaced in place at **CO6 / CB35**; names, ordinals and selector bytes do not change, so selector 408 stays
byte-identical and no new selector is authored.

**Re-executed at `M3-CP4c-3-TB30`** — run/job `34008104497 / 101418934144` on immutable CB35 package
`9980764888`, ledger `974fed9db1958ee7eb07df77097544199deeb61d663b1d366a37b54d64feeab0`: **401 PASS / 7 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, every row `selected=1`. **Ordinals 390 and 404
returned to PASS** with **no selector byte changed** — CB35 replaced their assertions in place — and the
credibility controls 366/367/398 stayed RED as required. Promoted to runtime authority at `M3-CP4c-3-TB30-REV`.

Two dispositions this selector must carry forward:

- **Ordinal 398 is not an ownership gate.** It fails on the **prescribed sphere**
  (`NotProductionReady/CellularityNotEstablished`), ordinal 368's surface. Certified source-face ownership is
  **total** — 300 established / 0 unavailable / 0 conflicting. **398 must not be re-scoped to exclude the sphere**,
  and its colour must not be read as an ownership signal.
- **Ordinals 366 and 367 are the whole remaining ownership frontier**, awaiting the same frozen guard at
  `GlobalTopologyPlan.cpp:830`.

**Re-executed at `M3-CP4c-3-TB31`** — run/job `34011402843 / 101427791582` on immutable CB36 package `9982174864`,
ledger `6632f428243788c98c816571f47ef0cf98df25a57274b2df75612674d563250b`: **397 PASS / 11 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`, every row `selected=1`. **CB36 authored no
selector change**, so selector 408 has now carried three runtimes unchanged.

What this execution recorded:

- **The seed-uniqueness frontier is CLOSED.** Component 0 moved from 191 faces / seedCount 3 / `Multiple` /
  `[0,1,3]` to **189 / 1 / `Unique` / `[0]`**; certified ownership remains **300 / 0 / 0**.
- **Ordinals 404 and 408 stayed PASS** through both product corrections. They are the two identities written to
  assert **publication and completeness** rather than an outcome, and that is why they survived the frontier
  moving.
- **Ordinals 390, 393, 406 and 407 went PASS → RED as pinned witnesses** — each expected
  `UncutFaceComponentOrbitSeedNotUnique` and received `TraceArcDoesNotSeparateItsSides`. Their assertions are
  repaired **in place** by `M3-CP4c-3-DEFN-R4`; names, ordinals and selector bytes do not change.

**Selector 408 has now carried five runtimes unchanged** — TB29, TB30, TB31, TB32 and TB33 — across four product
corrections. At `M3-CP4c-3-TB33` it recorded **401 PASS / 7 RED**, accepted **1–365 = 365/365**, RED
`[366,367,368,369,370,374,398]`, every row `selected=1`, on immutable CB38 package `9994997588`.

Two facts this selector must carry forward:

- **Ordinals 404 and 408 have never gone RED across four consecutive forward steps.** They are the two identities
  written to assert **publication and completeness** rather than an outcome, and that is why they survived every
  frontier move. Treat them as the template.
- **Ordinals 390, 393, 406 and 407 returned to PASS** once each was given a **justified cleared-stage** outcome —
  the stage failed and published, or the stage was cleared and the later failure published its labelled evidence.
  Their assertions were replaced in place; no selector byte changed.

**CB39 result:** selector **409** appends 408 as an exact 408-line prefix and one gating identity,
`GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` — a constructed negative proving that two
node-disjoint boundary loops are still rejected with reason `ArcChainBroken` after the `current == start` disjunct
is removed. It asserts a constructed rejection, never a value on the production fixture. Ordinals 397–408 keep
their contracts.

### 409 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_409.txt` — **409 identities**, authored by `M3-CP4c-3-CB39`, LF
SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`. Selector 408 is its exact 408-line
prefix, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`.

CB39 appends one constructed disjoint-loop boundary-walk falsifier to frozen selector 408:

- `GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected`

**Compiled at `M3-CP4c-3-CB39`:** semantic evidence source
`7711b9c2c20d284823911aa4ca067bd33244f4e6`; run/job `34061111130 / 101561719362`; result/log artifacts
`9997560649 / 9997560940` with SHA-256
`9a71fe17b789c94f70580116b822b3949dabecda7bf1d736afef10a1e6a9c3d2` /
`6f11586812cf77cd601f0a2339b573d915d57cb2b1bfbda0cfecfa87066ed645`. All eight approved targets compiled
with GMP/GMPXX linked; root package `SHA256SUMS` is 28/28 PASS; command boundary records `runtimeExecution=false`.
This is compile authority only. Selector 409 is not semantically accepted until TB34. Package count is **99**.

**Executed at `M3-CP4c-3-TB34`** — run `34066225065`, **400 PASS / 9 RED**, RED
`[312,366,367,368,369,370,374,398,409]`, **accepted 1–365 = 364/365**. Two results this selector must carry
forward:

- **Ordinal 312 — `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks` — regressed inside the accepted
  prefix.** It is the accepted witness for `RegionBoundaryNotSingleWalk`, and the code appears **exactly twice** in
  the test corpus: at 312 and at 409. **Before any future measure removes or weakens a rejection, grep for its
  error code and name every accepted identity that asserts it.** This selector's accepted prefix is restored by
  fixing the product at `M3-CP4c-3-CB40`, **never** by editing ordinal 312.
- **Ordinal 409 never reached its oracle** — `disjointRegions.has_value()` is false. Two **node-disjoint** boundary
  loops appear to be unconstructible through the production entry path, so the identity is **re-aimed in place** at
  the reachable negative — two loops meeting at a shared node, rejected with reason `ClosedBeforeEnd`. Its name,
  ordinal and the first 408 selector lines do not change.

**CB40 discharged that successor.** TB35 recorded ordinal **312 PASS** with the accepted prefix restored to
**365/365**, and ordinal **409 PASS** on its re-aimed shared-start oracle. Ordinals 390/393/404/406/407/408 stayed
green.

**CB41 discharged that successor and TB36 proved it at runtime.** CB41's static audit recorded ordinal 312's and
ordinal 409's test blocks as **byte-identical before and after** (`94724bef…`, `ea574dab…`) and selector409
unchanged at `eea6d8c2…`; TB36 then held both **PASS** while 366/367 advanced past `ClosedBeforeEnd`. The derived
provenance relation resolves their mutated copies (`tests/FieldAlignedCurveNetworkTests.cpp:3247–3253`,
`:3276–3279`) to `Unguaranteed`, so **Part IX-A §A.1 is confirmed**: a construction-time flag would have survived
the copy and re-broken accepted ordinal 312.

**CB42 discharged that successor and TB37 proved it.** CB42's grep found **no test-source assertion** of
`RegionEulerCharacteristicNotOne`, and ordinals 312/409 and selector409 stayed byte-identical
(`94724bef…`, `ea574dab…`, `eea6d8c2…`). TB37 then hashed `ledger.tsv` and `identity-map.tsv` **identical to
TB36's** while the failure-detail digest table changed — the artifact proof that a diagnostics-only turn changed
no behaviour.

**DEFN-R6 discharged that successor**, appending **Part X** without authoring a selector or touching source.

**CB43 discharged the Code + Build successor without authoring a selector.** Source `2fcde465b1de2e42a348d224f5165ce8b87e4fbe` compiles green as package103 artifact `10034608071`. Selector409 stays `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, selector408 prefix `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`, and `tests/FieldAlignedCurveNetworkTests.cpp` stays `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b`. CB43 adds full source-submesh Euler authority and proof diagnostics without editing 312, 409, any accepted identity, or region construction.

**TB38-EXEC discharged that successor, and its result refuted the definition CB43 implemented.** Selector409
stayed byte-frozen at `eea6d8c2…` and ordinals **312/409 stayed PASS**, but **accepted 356/357/362 and protected
390/393/406/407 regressed**, taking the accepted prefix to **362/365**. The cause is `DEFN-R6.4`, not the
implementation. **TB38 is not promoted; `M3-CP4c-3-TB37` remains this selector's accepted authority at 365/365.**
DEFN-R6.7's per-region proof also discharged over an **empty table**, because the certificate emission sits behind
`DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1`.

**CB44 discharged that Code + Build successor without authoring a selector.** Semantic source
`8756cfe983bf7e05209f560d59a522a6b5b0674a` compiles green as package104 artifact `10036808934`. Selector409
remains `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, selector408 prefix remains
`2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`, and test source remains
`913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b`. CB44 restores only the reduced criterion,
ungates the certificate rows, and adds publication-only traced/split measurements.

**TB39-EXEC discharged that successor without changing selector bytes.** Run `34177823202` on immutable package104
records **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`; 312/409 and
390/393/404/406/407/408 PASS, zero selection mismatch/timeout. Ledger SHA `058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`
is identical to TB37. The non-vacuous certificate table contains 513 complete rows and all frozen arithmetic
relations pass. Selector409 remains byte-frozen.

**TB39-REV promotion:** independent review promotes this TB39 execution to the **current valid semantic runtime
authority**. Selector409 bytes remain frozen; accepted authority is **365/365**, with current full selector colour
vector **402 PASS / 7 RED** and RED `[366,367,368,369,370,374,398]`. Stable accounting remains 46 / 14 / 32.
The review makes no selector membership change.

**DEFN-R7 / CB45 / TB40 / CB46 / TB41 have since run on this same byte-frozen selector409.** CB45 implemented the
Part XI actual-embedded face binding; TB40 confirmed the binding but lost accepted 311/314/356/357 because four
oracles compared the production orbit ordinal against an independent enumeration's index; CB46 replaced that with a
**content anchor** (`canonical_cycle_anchor`); and **TB41 recovered all four**, with `arc 0` appearing in both
orientations so the census is non-uniform. **`M3-CP4c-3-TB41` is the promoted authority at 398 PASS / 11 RED,
accepted 365/365, package106.** Ordinals 312/315/409 stayed PASS throughout.

**CB47 discharged that successor and TB42 answered it.** Selector409 stayed byte-frozen at `eea6d8c2…`; TB42's
ledger hash is **identical to TB41's** while the failure-detail digest changed, so CB47 was diagnostics-only as
required and the oracle was not re-hidden. **`M3-CP4c-3-TB42` is the promoted authority at 398 PASS / 11 RED,
accepted 365/365, package107.**

**The frontier census is measured and closed to further measurement.** The uncut-component partition holds **226
unlabelled faces in 9 components**; the failing region holds **10** source faces of which **0** are in the
partition. **A domain mismatch, not an empty set** — three of the four affected identities name that census
explicitly, and their `UncutComponent` early return was a **domain guard written as a stage check**.

**Exact successor:** `M3-CP4c-3-DEFN-R8` — a **static definition turn** appending **Part XII**, which authors no
selector and touches no source. It states the census's domain, decides what a `RegionCertification` failure must
publish instead, requires a **domain predicate rather than a stage string**, and restates ordinals
**390/393/406/407** so each still **fails** when its own census is broken within its own domain. **Widening the
early return to make them pass is prohibited**, and the implementing turn it freezes, `M3-CP4c-3-CB48`, must
publish per identity **which branch it took** so "passed" and "did not run" stay distinguishable. **Selector 409
stays byte-frozen and accepted prefix 365/365 is a stop condition.**

### 422 — superseded

`Architecture_M4_CP_COND_CB4_Required_Green_Selector_422.txt` — 422 identities, first committed -.

**Off-chain:** not an extension of selector 409. Holds unique bytes.

### 423 — superseded

`Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt` — 423 identities, first committed -.

Appended 1 identity to selector 422:

- `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`

### 424 — ACCEPTED HISTORICAL PREFIX OF CURRENT SELECTOR426

`Architecture_M4_CP_SCALE_CB6_Required_Green_Selector_424.txt` — **424 identities**, LF SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`. Its first423 LF rows are byte-identical to accepted selector423 SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.

Appended 1 identity to selector 423:

- `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

**Accepted at `M4-CP-SCALE-TB5-REV`; now the exact first424 prefix of current selector426 through selector425.** Package `10407605295` / source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` first established selector424 **424/424**. TB6 Review later promoted package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` under the same byte-identical selector424. `M4-CP-SCALE-TB4-REV-OBS-01` remains discharged; selector424 remains frozen historical accepted prefix authority.

**S3 publication and cumulative acceptance complete.** TB7 Review proves the exact selector424-prefix publication, fresh selector425 **425/425** cumulative runtime and independent Review, accepts S3 cumulative credit, and discharges `M4-CP-SCALE-TB6-REV-OBS-01`.

### 425 — ACCEPTED HISTORICAL PREFIX OF CURRENT SELECTOR426

`Architecture_M4_CP_SCALE_CB8_Required_Green_Selector_425.txt` — **425 identities**, LF SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`. Its first424 LF rows are byte-identical to accepted selector424 SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.

Appended 1 producer-owned identity to selector424:

- `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`

CB8 static ownership is **30 authority-kernel / 279 producer / 75 completion / 41 validation**. Compile/package run/job `35042417046 / 104624909472` first published the selector on source `01b1124af094044e32d6887ff0615881333d12ce`, artifact `10425344367`, and TB7 Review accepted it **425/425**. TB9 later executes the byte-identical selector from corrected-prerequisite package `10455353524` / source `bebb14e32a0ac53dd420acf46bfa34410cf759a1`: run/job `35121594986 / 104880514495` records a separate S4-prerequisite focus **1/1 PASS** followed by selector425 **425/425 PASS**, exact owner census **30/279/75/41** and immutable postflight. `M4-CP-SCALE-TB9-REV` independently re-derives the prerequisite, selector/prefix/owners/all 425 raw outcomes and **PROMOTES package `10455353524` as the then-current M4 runtime authority under unchanged selector425**. S3 cumulative credit remains accepted; `M4-CP-SCALE-DEFN-OBS-03` is discharged as prerequisite-only evidence. At that historical point selector426 was not yet authorized; the later S4 product/publication chain is recorded in the selector426 note below.

### 426 — ACCEPTED HISTORICAL PREFIX OF SELECTOR427

`Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt` — **426 identities**, LF SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`. Its first425 LF rows are byte-identical to accepted selector425 SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`.

Appended 1 producer-owned identity to selector425:

- `M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`

CB12 static ownership is **30 authority-kernel / 280 producer / 75 completion / 41 validation**. TB11 run/job `35173390136 / 105049726721` then executes selector426 **426/426 PASS** in 426 fresh exact-filter processes with the same owner census, fresh row426 **1/1 PASS**, zero anomalies and exact immutable postflight. `M4-CP-SCALE-TB11-REV` first accepted this selector and promoted package `10473134357`. R10 Review later independently re-hashes selector426/prefix425, re-counts the same **30/280/75/41** ownership and promotes package `10560828304` / source `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff` under the unchanged selector after **434/434** artifact-only GREEN evidence. Selector426 remains accepted cumulative M4 authority and the exact historical prefix of selector427; S4 cumulative credit remains accepted. `M4-CP-SCALE-TB12-R10-REV-OBS-01` authorized selector427 only as this exact 426-row prefix plus the reviewed S5 row.

### 427 — ACCEPTED HISTORICAL PREFIX OF SELECTOR430

`Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt` — **427 identities**, LF SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Its first426 LF rows are byte-identical to accepted selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`.

Appended 1 producer-owned identity to selector426:

- `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`

CB24 static ownership is **30 authority-kernel / 281 producer / 75 completion / 41 validation**. `M4-CP-SCALE-TB13-EXEC` run/job `35393657851 / 105757517161` executes selector427 **427/427 PASS** in exact file order with exact immutable postflight. `M4-CP-SCALE-TB13-REV` independently re-hashes the selector/prefix, re-parses every one-selected PASS row, verifies the package/result manifests and pre/post censuses, and promotes package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef`. S5 therefore has cumulative required-green credit and selector427 is accepted current M4 authority.

### 430 — ACCEPTED HISTORICAL PREFIX OF SELECTOR448

`Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` — **430 identities**, LF SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`. Its first427 LF rows are byte-identical to accepted selector427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Appended exactly the three `M4-CP4-TB2-R2-REV` reviewed-green identities, in frozen order:

- `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated`
- `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder`
- `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection`

CB8 static ownership is **31 authority-kernel / 283 producer / 75 completion / 41 validation**. Mandatory GMP compile/package run/job `35468097574 / 105964043163` succeeds from exact publication source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431`; artifact `10591801825` has provider ZIP SHA-256 `20d9b07bae631e68f3292ee37ccb80c4724bae6eec0c50cd2274c36443183da6`, package manifest **26/26**, source archive SHA-256 `4d057381ba3f1caed55579f7a9b662753632637eb0aff7b1432326d8e557021a`, all four owner executables mode `0755`, clean source receipts, GMPXX+GMP linkage and `runtimeExecution=false`.

TB3 run/job `35470130614 / 105969470184` then executes the exact selector430 as **430/430 PASS** fresh exact-filter processes with zero RED/SKIP/crash/selection mismatch/unexecuted and exact owner census **31/283/75/41**. Result/log artifacts are `10592987234 / 10592817804`; mandatory package/source/execution-view postflight is byte+mode exact and every forbidden build/repair/mutation/benchmark counter is zero. `M4-CP4-TB3-REV` independently re-hashes package/selector/prefix, re-parses all 430 process rows/raw hashes, checks the three appended rows for non-vacuity, and **promotes package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` under selector430 as accepted current M4 closure authority**. Selector427 remains its exact accepted historical prefix.

`M5-CP1-TB1-R3-REV` later promotes package `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7` as the **current accepted runtime package under the same byte-frozen selector430** after focused 9/9 + selector430 430/430 artifact-only runtime and independent Review. Selector membership, ordering, hash and owner census are unchanged; this is package/CP1 promotion, not a selector append.

`M5-CP2-TB1-REV` subsequently promotes package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` as the **current accepted runtime package under the same byte-frozen selector430** after focused 7/7 + selector430 430/430 artifact-only runtime and independent Review. Selector membership, ordering, LF hash `1c412850...9db6`, first427 prefix and owner census **31/283/75/41** are unchanged. M5 §13 now freezes the later CP3 publication sequence; no selector append occurs in CP2.

`M5-CP3-TB1-R16-REV` subsequently promotes package `10763242885` / source `a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1` as the **current accepted runtime package under the same byte-frozen selector430**. The basis is the complete fresh R16 pre-publication gate (run/job `35889831381 / 107279255523`): 18 nonselector identities 18/18 + selector430 430/430, 921/921 result evidence, and independent Review. Selector membership, ordering, LF hash `1c412850...9db6`, first427 prefix and owner census **31/283/75/41** are unchanged. The same Review **precommits** selector448 (SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`, selector430 as exact first430 prefix, owners **32/300/75/41**; `Architecture_M5_Frozen_Definitions.md` §17). At the R16 Review point it was **not yet a published selector file** and therefore had no table row; CB20 later published those exact bytes and `M5-CP3-TB2-REV` accepted them. *(Added by the R16-REV reviewing-agent addendum; the delegated closeout marked this manifest n/a and missed the package promotion.)*

### 448 — ACCEPTED CURRENT AUTHORITY

`Architecture_M5_CP3_CB20_Required_Green_Selector_448.txt` — **448 identities**, LF SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`. Its first430 LF rows are byte-identical to accepted selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`.

`M5-CP3-CB20` publishes exactly the 18 identities precommitted by `M5-CP3-TB1-R16-REV`, in frozen order. Static ownership across the four standard owner executables is **32 authority-kernel / 300 producer / 75 completion / 41 validation**. The exact 448-row routing receipt is `Architecture_M5_CP3_CB20_Selector_448_Static_Routing_Receipt.tsv`, SHA-256 `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`. `M5-CP3-TB2-EXEC` run/job `35913334490 / 107358491487` executes this exact published selector as **448/448 PASS** fresh exact-filter processes with zero skips, benchmark 0, exact owner census **32/300/75/41**, complete 917/917 result evidence and immutable postflight. `M5-CP3-TB2-REV` independently re-hashes selector448/prefix430/routing authority and all 448 ledger/raw-log receipts, then **accepts selector448 and promotes CB20 package/source `10771899191 / cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1` as the current accepted M5 runtime authority**. Selector430 remains the exact accepted historical first430 prefix.

## Separate lineage — M1

`M1_Full_Required_Green_Selector.txt` — **234** identities, LF SHA-256 `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`. This is the M1 milestone's full
selector and is **not** part of the CP4c prefix chain above. It is retained under `M1_Closure_Record.md`.

## Regenerating this manifest

Every column is derived. `tools/selector_probe.py` computes counts, LF hashes, prefix relations and appended
identities; hashes here are over **LF-normalized** bytes, which is what the published hashes use — a Windows
checkout stores CRLF, so a raw file hash will not match.

Regenerate after any turn that appends a selector, and never edit a selector file to make it agree with this one.
