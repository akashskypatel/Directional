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
| **374** | 374 | `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` | 373 | 1 | superseded |
| **375** | 375 | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` | 374 | 1 | superseded |
| **376** | 376 | `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8` | 375 | 1 | superseded |
| **377** | 377 | `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1` | 376 | 1 | superseded |
| **378** | 378 | `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8` | 377 | 1 | superseded |
| **379** | 379 | `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7` | 378 | 1 | superseded |
| **380** | 380 | `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e` | 379 | 1 | superseded |
| **381** | 381 | `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90` | 380 | 1 | superseded |
| **382** | 382 | `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a` | 381 | 1 | superseded |
| **383** | 383 | `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c` | 382 | 1 | superseded |
| **384** | 384 | `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564` | 383 | 1 | superseded |
| **385** | 388 | `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca` | 384 | 4 | superseded |
| **391** | 391 | `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0` | 385 | 3 | superseded |
| **393** | 393 | `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d` | 391 | 2 | superseded |
| **397** | 397 | `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` | 393 | 4 | superseded |
| **401** | 401 | `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869` | 397 | 4 | superseded |
| **403** | 403 | `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007` | 401 | 2 | superseded |
| **405** | 405 | `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7` | 403 | 2 | superseded |
| **406** | 406 | `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0` | 405 | 1 | superseded |
| **407** | 407 | `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae` | 406 | 1 | superseded |
| **408** | 408 | `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` | 407 | 1 | **CURRENT GATE** |

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

### 381 — superseded

`Architecture_M3_CP4c3_Required_Green_Selector_381.txt` — 381 identities, first committed 5dcaa8be0 2026-09-02.

Appended 1 identity to selector 380:

- `GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible`

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

### 408 — CURRENT GATE

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

**Exact successor:** `M3-CP4c-3-CB39` appends **409** with 408 as an exact 408-line prefix and one gating identity,
`GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` — a constructed negative proving that two
node-disjoint boundary loops are still rejected with reason `ArcChainBroken` after the `current == start` disjunct
is removed. It asserts a constructed rejection, never a value on the production fixture. Ordinals 397–408 keep
their contracts.

## Separate lineage — M1

`M1_Full_Required_Green_Selector.txt` — **234** identities, LF SHA-256 `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`. This is the M1 milestone's full
selector and is **not** part of the CP4c prefix chain above. It is retained under `M1_Closure_Record.md`.

## Regenerating this manifest

Every column is derived. `tools/selector_probe.py` computes counts, LF hashes, prefix relations and appended
identities; hashes here are over **LF-normalized** bytes, which is what the published hashes use — a Windows
checkout stores CRLF, so a raw file hash will not match.

Regenerate after any turn that appends a selector, and never edit a selector file to make it agree with this one.

