# M3 CP4c-3 TB4 — Artifact-Only Test + Benchmark Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB4`
Status: **COMPLETE / VALID SEMANTIC RED — FIRST RED AT ORDINAL 366; AP6 DIAGNOSTIC PASS COMPLETE**

## Authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Immutable semantic/evidence source: `2d22ef293363058cfdca96d01158a93d2c0200f8`
- Immutable mode-preserving package **73**: artifact `9773591345`, Actions SHA-256 `8f3a8f0d6a3ad0931db89cb3e94c33d1d7e8a0d9e1aba27a6ad2690ec9c402a0`
- Inner `package73.tar.gz` SHA-256: `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`
- Packaged source archive SHA-256: `36451a2473a8858225cf9eabb181a58a5397f400f7f0a99995a1b8da37a2cb4f`
- Frozen selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Authoritative artifact-only run/job: `33436492493 / 99634138202`
- Result artifact: `9774693166`, SHA-256 `056f86df2e387391227bcf52f59ba932dd64a5d02923a8ff688cd8e315ff8a7e`
- Diagnostic log artifact: `9774693946`, SHA-256 `d2acc62037d0bce07ef98bb77a7cb42ee90758d8b72477d9d8516da2fa0afcb6`

No configure, compile, relink, package repair, generated discovery, benchmark, or package/source/product/test/fixture/selector mutation occurred.

## 1. Resolved orchestration-only attempt

Initial control run/job `33436283363 / 99633462747` stopped **before runtime** with
`package73-envelope-missing`. The runner expected sidecar `package73.tar.gz.sha256`, while the frozen package-73
Actions envelope contains `package73.sha256`. Control-only commit
`41a7a8b92a311c240cfbcf320a4003d1f17dde7b` changed exactly that sidecar lookup and digest read; package 73,
semantic source, selector, binaries, tests and fixtures were untouched. The corrected run below is the sole semantic
TB4 authority. This is `M3-CP4c3-TB4-ORCH-01`, resolved/non-stable with zero semantic execution in the failed attempt.

## 2. Immutable preflight

The corrected run passed immutable preflight before ordinal 1:

- package-73 outer and inner digests matched frozen CB5 authority;
- the complete **57-entry** internal `SHA256SUMS` passed;
- source SHA and source-archive digest matched exactly;
- source status records were clean;
- `runtimeExecution=false` and `exactArithmeticBackend=GMP` compile-boundary evidence were present before TB runtime;
- GMPXX and GMP linkage evidence remained present;
- all six packaged test/benchmark executables reproduced their frozen hashes and mode **`0755`** without repair;
- exactly **27** package-relative fixtures were present, including mechanical and prescribed-sphere witnesses;
- selector 373 had exactly 373 unique identities and reproduced the frozen 355/357/361/365/367/370 prefix hashes;
- static ownership resolved all 373 identities exactly once: producer **227**, authority-kernel **30**, completion **75**, validation **41**.

## 3. Ordered semantic gate

The semantic gate executed one exact identity per fresh process from ordinal 1 and stopped at its first red:

- ordinals **1–365**: **365/365 PASS**;
- ordinal **366**: `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` selected exactly once and failed;
- semantic gate total: **366 executed / 365 PASS / 1 RED**;
- ordinals 367–373 received **zero gate credit** and were not allowed to change that verdict.

The first-red failure remains `NotProductionReady/field-aligned-network` with detail code
`VertexTransitSectorUnresolved`.

## 4. AP2 finally publishes the exact ordinal-366 locus

CB5's typed locus channel closed the diagnostic-surface defect without changing transit semantics. The first-red now
publishes:

- `sourceVertex=30`;
- arrival/source face `(24,30,32)`;
- `branch=1`;
- `topologyRegion=0`;
- `arrivalMode=FaceInterior`;
- `publishedFaceCount=2`;
- candidate faces `(25,30,31)` and `(30,31,119)`;
- `barrierAbsorbed=false`;
- `barrierIncident=false`.

This is decisive for two of the three TB3-R1-REV mechanisms:

- **M1 barrier truncation → zero candidates is falsified at the failing locus.** The candidate set has cardinality 2.
- **M3 direct P2 consumer mismatch at one of the four `BarrierAbsorbed` census vertices is falsified at the failing locus.** Vertex 30 is neither barrier-absorbed nor barrier-incident.
- **M2 is not yet established.** The measured half of M2 — multiple candidates — is true, but M2 specifically attributed multiplicity to a singular vertex/holonomy mechanism. TB4 does not establish that vertex 30 is a prescribed singularity or prove why both candidate states satisfy the exact sector predicate. Independent review must reconstruct that fact before assigning cause.

The four mechanical atlas partition summaries still name the P2 port-emitting singularity vertices **10, 35, 47,
71**. The failing transit vertex is **30**, so the evidence no longer supports designing directly around the four
barrier-absorbed singularities. AP4 therefore did its job: the leading suspicion was measured before it became a
correction.

## 5. AP6 report-only diagnostic pass

After the semantic first-red verdict was fixed, frozen ordinals **367–373** executed exactly once as a separate
non-gating diagnostic pass with **zero gate credit**. Result: **7 executed / 1 PASS / 6 RED**.

| Ordinal | Identity | Diagnostic result | Evidence/disposition |
|---:|---|---|---|
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | RED | blocked by the same mechanical `VertexTransitSectorUnresolved` locus at vertex 30 |
| 368 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | RED | reaches A2a′ and reports `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2 / event 30; **AL4 remains binding** |
| 369 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | RED | reaches the intended assertion and reports `certificate.saturationUsed == true`; the R10 quality/coverage candidate remains live |
| 370 | `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | RED | fails earlier at `ASSERT_TRUE(atlasBuild)`; the intended empty-network A2a′ contract is still unmeasured and a new diagnostic-witness precondition candidate is recorded |
| 371 | `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` | RED | blocked upstream by the same mechanical vertex-30 network failure |
| 372 | `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` | RED | blocked upstream by the same mechanical vertex-30 network failure |
| 373 | `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle` | **PASS** | its synthetic barrier-arc binding contract passes; full `M3-CP4c3-DEFN-R1-CAND-01` closure still also requires mechanical-witness zero-unbound evidence |

The AP6 pass is diagnostic evidence only. It neither extends the 365 accepted prefix nor changes the semantic first
red at 366.

## 6. Regression/candidate disposition

- `M3-CP4c3-TB3-R1-CAND-01`: remains **ACTIVE / GATING / NON-STABLE**, but is narrowed from unknown cardinality to a concrete **two-candidate FaceInterior locus** at vertex 30. M1 and direct-M3 are falsified; semantic cause remains unadjudicated until review reconstructs the two candidates and classifies vertex 30.
- `M3-CP4c3-TB3-R1-REV-CAND-01`: **RESOLVED / RUNTIME PROVED**. TB4 names the failing stage locus directly from `RemeshDiagnostics`; no independent review had to recover it by elimination.
- `M3-CP4c3-TB4-DIAG-CAND-01`: **ACTIVE / DIAGNOSTIC-WITNESS PRECONDITION / CAUSE UNADJUDICATED / NON-STABLE** for ordinal 370's `atlasBuild=false` stop before the intended empty-network contract.
- `M3-CP4c3-TB4-ORCH-01`: **RESOLVED / PRE-RUNTIME / NON-STABLE**; wrong package-73 sidecar filename in the TB runner, corrected without touching semantic bytes.
- `M3-CP4c2-TB-X2-CAND-04`: remains active/one-level-short; TB4 independently reproduces the sphere's `TraceEventPositionInvalid` subreason and trace/event locus, but does not authorize a sphere correction.
- `M3-CP4c2-TB-X2-R10-CAND-01`: remains active; ordinal 369 now directly confirms saturation is still used.
- `M3-CP4c2-TB-X2-R8-CAND-02`: remains active; ordinal 370 did not reach the intended cut-graph contract because its atlas precondition failed.
- `M3-CP4c3-DEFN-R1-CAND-01`: ordinal 373 is now runtime green, but its full closure condition is not yet satisfied because TB4 did not publish the mechanical witness's zero-unbound count.

No accepted behavior was lost: the frozen accepted prefix is still **365/365 green**, and CP4c-3 was already open.
All new/reproduced findings are on unaccepted or report-only surfaces. Stable accounting therefore remains **44 events /
14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3 packages **71**.

## 7. Immutable postflight

Postflight re-ran the package manifest, six exact binary hashes/modes, package-tree byte/mode census, and selector hash.
The package tree and selector were unchanged after all semantic and diagnostic runtime. Recorded boundary flags are:

- `runtimeExecution=true` — the 366 semantic-gate processes plus the seven report-only diagnostic processes;
- `benchmarkExecution=false`;
- `configure=false`, `compile=false`, `relink=false`;
- `packageRepair=false`, `generatedDiscovery=false`;
- `productMutation=false`, `testMutation=false`, `fixtureMutation=false`, `selectorMutation=false`.

The semantic red and AP6 observations are therefore valid immutable-package evidence.

## 8. Disposition

`M3-CP4c-3` remains **OPEN**. Do not retry TB4 unchanged and do not implement a semantic correction from the
multiple-candidate observation alone.

Exact successor: **independent `M3-CP4c-3-TB4-REV` — REVIEW + PLAN** under
`Architecture_M3_CP4c3_TB4_Independent_Review_Plan.md`. That review must explain why the exact
`FaceInterior` transit at vertex 30 produces the two published continuation candidates, classify causality relative
to P2, and adjudicate the 368–373 diagnostic findings before freezing one bounded successor. No Directional runtime,
compile, package, or product/test/fixture/selector mutation is authorized in the review.
