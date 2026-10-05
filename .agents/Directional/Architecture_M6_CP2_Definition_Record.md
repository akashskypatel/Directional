# `M6-CP2-DEFN` — Independent Surface Product Verifier Definition Record

**Turn:** `M6-CP2-DEFN`
**Type:** bounded runtime-free Definition.
**Entering authority:** M6-CP1 CLOSED / ACCEPTED mechanism-only; reviewed runtime `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, focused30 + selector449 = **479/479**.
**Source inspection authority:** source-snapshot run `37318977093`, artifact `11348942941`, exact snapshot/event SHA `d06b615b496766687cd4bba0412fbee3f18e176d`, outer artifact SHA-256 `2e802a53dcc31d9112bab24a050176db9a0d26aa4300b23d774b04e2bea24aed`, source archive SHA-256 `8832b3944e46b133f5c4f5dc298dcfbff819c5cedf0d0d99df5f55f1c67ae452`, `runtimeExecution=false`.
**Accounting:** **60 / 16 / 44**, debt 1.
**Mandatory successor:** `M6-CP2-DEFN-REV`. No implementation is authorized by this Definition.

## 0. Definition checklist

- [x] D1 negative-witness seam and report/failure identity.
- [x] D2 C4 reachability disposition and independent manifoldness falsifier.
- [x] D3 three static wedge-rule tampers and mutant discrimination.
- [x] D4 production A8 integration point and stop rule.
- [x] D5 gate architecture, exact identities, count and compile targets.
- [x] D6 successor chain and first CP2 Code + Build name.
- [x] RA-26 §5(iii) ownership resolved.

## 1. D1 — negative-witness seam and verifier product surface

### 1.1 Why a separate record-view seam is required

The public products are intentionally validating/private-construction objects. A5's public validation publication still validates before returning a `SurfaceOccurrenceComplex` (`RemeshPipeline.h:973-1021`; `RemeshPipeline.cpp:3628-3765`). A6 already exposes plain `SurfaceQuotientValidationRecords` and `validation_records()`, while the `SurfaceQuotientProduct` constructor is private (`RemeshPipeline.h:1249-1315`); its focused publication seam still validates (`:1318-1331`). A7 likewise has a private constructor and no unchecked factory (`RemeshPipeline.h:1409-1462`). Therefore a verifier that accepted only product objects could never receive most malformed §6.3 witnesses.

**Decision:** CP2 introduces immutable-by-convention **verification record views**, not unchecked products:

```text
SurfaceOccurrenceVerificationRecords
  cells, occurrences, ownedRelations, certificate

SurfaceQuotientVerificationRecords
  SurfaceQuotientValidationRecords,
  QuotientCertificate,
  MaterializationCertificate,
  optional closedComplexView

SourceAttachedGeometryVerificationRecords
  vertices, topology, sourceSupportCertificates,
  boundaryLoops, GeometryEmbeddingCertificate
```

Each valid product exports a copy-by-value `verification_records()` view. Production uses `SurfaceProductVerifier::verify(A0, A5, A6, A7)`, which converts the immutable products to those views. Tests use `SurfaceProductVerifier::verify_records(...)` on copies and may tamper those copies. **There is no unchecked A5/A6/A7 factory and no API that converts a tampered record view back into a product.** The seam can therefore express malformed authority without weakening producer construction.

### 1.2 Verification report and semantic finding identity

Freeze:

```text
enum class VerificationStage : uint8_t { A0, A5, A6, A7, CrossStage };

enum class VerificationFailureCode : uint8_t {
  SourceIncidenceMismatch,
  OccurrenceOwnershipMismatch,
  DirectedSideCycleMismatch,
  SemanticIdentityMismatch,
  QuotientMembershipMismatch,
  QuadIncidenceMismatch,
  NonManifoldTopology,
  BoundaryOrEulerMismatch,
  NamedTransportMismatch,
  SourceSupportIncidenceMismatch,
  CertificatePayloadMismatch,
  MissingPublishedAuthority,
  UncertifiedAuthoritySubstitution,
  ForbiddenGeometricWeld,
  UpstreamFailureSubstitution
};

struct VerificationLocus {
  VerificationStage stage;
  optional<CellId> cell;
  optional<OccurrenceId> occurrence;
  optional<SurfaceOccurrenceRelationId> relation;
  optional<SurfaceQuotientClassId> quotientClass;
  string site;
};

struct VerificationFailure {
  VerificationFailureCode code;
  VerificationLocus locus;
};

struct VerificationReport {
  vector<VerificationFailure> findings;
  bool verified() const { return findings.empty(); }
};
```

`findings` is sorted and deduplicated by semantic `(stage, code, locus)`; vector indices, source-row indices, output-row indices and discovery order are diagnostics only and are not part of identity. The verifier may report multiple independent findings, but it never repairs one finding to discover another.

### 1.3 §6.2 recompute matrix

The first CP2 implementation recomputes only the frozen elementary facts (`Architecture_M6_Frozen_Definitions.md:233-246`):

| Input | Independent recompute | Failure class |
|---|---|---|
| A0 | source face/edge/vertex incidence and connected components | `SourceIncidenceMismatch` |
| A5 | exact occurrence ownership counts and every directed-side cycle | `OccurrenceOwnershipMismatch`, `DirectedSideCycleMismatch` |
| A6 | class/cell membership by published IDs; quad/edge incidence; connected components; boundary loops; Euler characteristic; vertex/edge manifoldness | `SemanticIdentityMismatch`, `QuotientMembershipMismatch`, `QuadIncidenceMismatch`, `NonManifoldTopology`, `BoundaryOrEulerMismatch` |
| named A5/A6 certificates | exact composition/inversion of only the explicitly named recorded transport | `NamedTransportMismatch` |
| A7 | published source-support incidence against A0; topology/class linkage by published IDs | `SourceSupportIncidenceMismatch`, `QuotientMembershipMismatch` |
| all stage certificates | deterministic payload equality under semantic ordering | `CertificatePayloadMismatch` |

No producer decision routine is called to perform these recomputations.

### 1.4 §6.3 malformed-authority matrix

Every frozen forbidden operation (`Architecture_M6_Frozen_Definitions.md:248-263`) has a reachable record-view witness or is classified defensive:

| Frozen forbidden class | Verifier disposition |
|---|---|
| create/renumber `OccurrenceId` / `QuotientClassId` | reject `SemanticIdentityMismatch` |
| union occurrences / choose a replacement representative | reject `QuotientMembershipMismatch` / `UncertifiedAuthoritySubstitution` |
| search for replacement route/path | no search API exists; named route tamper rejects `MissingPublishedAuthority` or `NamedTransportMismatch` |
| infer missing endpoint/owner/chart/sheet/support/relation | reject `MissingPublishedAuthority` |
| canonicalize malformed producer state | reject the first semantic mismatch; malformed ordering cannot be rewritten |
| substitute equivalent/reverse unreferenced relation | reject `UncertifiedAuthoritySubstitution` |
| weld by lattice/barycentric/3D/proximity | unrelated coincident records remain distinct; forced collapse rejects `ForbiddenGeometricWeld`/membership mismatch |
| repair directed-side/quad/source attachment/certificate | reject corresponding incidence/support/certificate code; input view remains byte-identical after verify |
| mutate A5/A6/A7 or emit corrected product | verifier API is `const`/record-copy input and emits report only; mutation attempt is structurally unavailable |
| convert upstream producer rejection through fallback/recovery | production overload requires successful immutable products; variant/error input has no accepting verifier overload; test seam records this as defensive `UpstreamFailureSubstitution` contract |

The last two are API-shape defensive classes; the first CP2 test pins the absence of repair/mutation/fallback APIs in addition to runtime record-view negatives.

## 2. Exact certificate-chain binding

**A6 → A5.** Every A6 `QuotientRelationCertificate` and `QuotientRelationConsumption` must cite one exact A5-owned `SurfaceOccurrenceRelationId`; endpoints, owner/kind and immutable evidence payload must equal that A5 relation. Selected path steps may compose/invert only those named certificates. An equivalent unused relation or an unreferenced reverse relation is not a substitute.

**A7 → A6/A5.** Every A7 vertex and `SourceSupportCertificate` binds to one exact published A6 class ID and its exact member set; every member is an A5 occurrence; the A7 support equals the A5-owned support used by the class; A7 topology equals the published A6 classed topology by IDs; A7 selected relation/path payloads must equal the exact A6/A5 named evidence they cite. Equivalent geometry or an alternate route is irrelevant.

This resolves `M6-CP1-TB12-REV-OBS-01` without letting the verifier reconstruct a replacement certificate chain.

## 3. D2 — C4 is accepted-defensive; verifier manifoldness is the executed falsifier

A6 validates that published classes are exactly the connected components of the already-owned A5 relation certificates (`RemeshPipeline.cpp:5810-5890`). A5's focused publication seam rejects missing endpoints, malformed owners and undeclared/duplicate relations rather than allowing a test to invent a weld relation (`RemeshPipeline.cpp:3716-3750`). The closed-complex view is constructed only after base A6 production succeeds (`RemeshPipeline.cpp:6368-6380`). C4 itself is the valence-four opposite-continuation fail-close in the closed view (`:6302-6333`).

**Decision:** no current production-derived A5 witness is known that reaches C4, and creating one by adding a relation would be exactly the forged-relation witness forbidden by D2. `QuotientClosedComplexStripContinuationMismatch` therefore remains an accepted-defensive A6 producer branch. CP2 does **not** weaken or delete it.

The executed falsifier is instead a D1 A6 record-view tamper: start from a valid produced A6 record view, create two otherwise valid quad fans sharing one quotient vertex in the view, and require the verifier's independently recomputed vertex-link/manifoldness test to emit `NonManifoldTopology`. It may not call `build_surface_quotient_closed_complex_view` or C4.

## 4. D3 — three appended wedge-rule tampers

Identity 29 already proves one consistent-chain negative by replacing every bridge transition endpoint with two unrelated sheets (`SurfaceCellTransitionQuotientTests.cpp:7346-7411`). The production wedge rule separately requires region equality, both transition endpoints inside the retained sheet set, and full graph connectivity (`RemeshPipeline.cpp:6884-6914`). Therefore the first CP2 Code + Build adds three distinct mutant-killing identities, leaving identity 29 unchanged:

1. **wrong-region:** keep the sheet endpoints correct but replace `transition.region`; defeats a mutant that omits `transition.region == occurrence.topologyRegion`. Identity29 cannot kill it because identity29 changes sheet endpoints instead.
2. **touches-not-connects:** keep exactly one transition endpoint in the retained sheet set and the other outside; defeats a mutant that checks `from ∈ S || to ∈ S` rather than both endpoints in-set. Identity29 puts both endpoints outside and cannot distinguish this mutant.
3. **three-sheet partial connectivity:** on the existing split-isolation bridge, add a third sheet to `cornerWedgeSheets` while retaining transitions that connect only the original two; republish A5, re-produce A6, then run A7. This defeats a mutant that accepts any valid transition instead of requiring the complete retained-sheet graph to be connected. No new fixture is required.

Each tamper must prove baseline acceptance first and must republish A5/re-produce A6 after the tamper; stale A6 reuse is forbidden.

## 5. D4 — A8 runs in the production pipeline immediately after A7

At the current integration seam, A5 and A6 have succeeded, A7 is produced at `RemeshPipeline.cpp:7451-7455`, and compatibility projection into output positions/lineage begins at `:7490-7523`.

**Decision:** CP2 production integration calls `SurfaceProductVerifier` **after successful A7 production and before the transitional adapter projects A7 into mesh/lineage**. A non-empty `VerificationReport.findings` fails closed with a typed verifier failure and no adapter projection. This keeps A8 after all products it verifies and before unverified authority is consumed downstream.

**Stop rule:** if this integration rejects any previously accepted focused-30 or selector449 identity, the first CP2 TB stops for Review. The verifier is not weakened, bypassed, or made test-only to regain green.

## 6. RA-26 §5(iii) — optimizer projection ownership

`project_vertices` currently derives `requiredScope` from the representative seed face and then compares the projected face's component/sheet back to that same anchor-derived scope (`SurfaceMeshOptimizer.cpp:781-829`, repeated at `:848-877`). The verifier cannot own this later continuous-projection safety check because A8 verifies immutable A7 before optimizer movement.

**Decision:** the optimizer keeps a **reference-safety** check, not semantic product authority. The first CP2 Code + Build replaces the vacuous component/sheet self-check with membership of the projected source chart in the class-wide `SurfaceOptimizationConstraints::vertexChartAuthority` for that output vertex. This check may only reject a projection candidate; it may not select quotient identity, relation authority, or a replacement chart. The verifier remains the semantic A0/A5/A6/A7 certifier.

## 7. D5 — gate architecture and exact first-CB identities

Keep CP1 focused-30, selector449 and routing449 byte-exact. Do **not** republish them into a new cumulative selector in CP2. The first CP2 CB creates a separate `Architecture_M6_CP2_Required_Green_Focused_12.txt` with exactly these identities, in this order:

1. `M6CP2.VerificationReportUsesSemanticFindingOrderAndIsPermutationInvariant`
2. `M6CP2.VerifierRecomputesA0AndA5ElementaryIncidenceIndependently`
3. `M6CP2.VerifierRecomputesA6TopologyAndMembershipIndependently`
4. `M6CP2.VerifierRecomputesA7SupportAndCertificatePayloadsIndependently`
5. `M6CP2.VerifierRejectsEveryForbiddenRepairClassWithoutMutation`
6. `M6CP2.CertificateChainRequiresExactA5A6A7PayloadBinding`
7. `M6CP2.WeldPinchedRecordViewFailsIndependentManifoldness`
8. `M6CP2.A7WedgeTransitionWrongRegionRejects`
9. `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`
10. `M6CP2.A7ThreeSheetPartialConnectivityRejects`
11. `M6CP2.PipelineRunsVerifierAfterA7BeforeAdapterProjection`
12. `M6CP2.OptimizerProjectionUsesClassWideChartAuthority`

TB1 is exactly **30 + 12 + 449 = 491** fresh exact-filter processes. Every list is executed separately and each process must select exactly one test. No guessed or deduplicated count is permitted.

Compile/package uses the durable reusable GMP/GMPXX workflow and the standard eight targets from `.github/workflows/agent-compile-reusable.yml`: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`. Code + Build remains runtime-free.

## 8. D6 — frozen successor chain

`M6-CP2-DEFN` → **`M6-CP2-DEFN-REV`** → **`M6-CP2-CB1-VERIFIER`** → `M6-CP2-TB1-VERIFIER-EXEC` → `M6-CP2-TB1-VERIFIER-REV`.

Only the Review may authorize `M6-CP2-CB1-VERIFIER`. `M6-DEFN-R5` follows CP2 and remains the CP3-entry Definition gate. `G4-B002` remains open; debt stays 1. No M7 disposition/degradation semantics are introduced.

## 9. Definition disposition

The Definition is internally complete and ready for mandatory independent Review. It changes no product source, tests, fixtures, selector bytes, benchmark source or build logic and executes no Directional runtime. Any Review finding that changes A5/A6/A7 semantics, permits verifier repair/substitution, or requires a production unchecked factory returns to Definition rather than being deferred into implementation.
