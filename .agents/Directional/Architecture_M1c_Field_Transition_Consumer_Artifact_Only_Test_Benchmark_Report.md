# M1c Field-Transition Consumer — Artifact-Only Test + Benchmark Report

**Status:** ACCEPTED  
**Turn type:** Test + Benchmark only  
**Implementation under test:** `e139fca885538e310dc47ed7ba531517603d92cf`  
**Product behavior delta:** none observed or accepted  
**Review policy:** `never`  
**Date:** 2026-08-09 UTC

## 1. Immutable authority

| Evidence | Value |
|---|---|
| Migration base | `512d9523f13158a9f71b406b6db7137a1db3c504` |
| M1c implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Build/event commit | `ebda31859a18005844f81274393211991361cbbb` |
| Build run/job | `31334345368 / 93297618568` |
| Result artifact | `9043971772` |
| Result ZIP SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log ZIP SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Recursive manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| Producer executable SHA-256 | `9608ec2a0fc8eec52e4ceb61df53c0aae5670f9834b358a08e390ac9bb93fbdd` |
| Oracle executable SHA-256 | `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90` |
| Authority executable SHA-256 | `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71` |
| Validation executable SHA-256 | `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6` |

Preflight matched both outer GitHub artifact digests, rejected unsafe archive paths, verified the manifest itself and every **54/54** package checksum, confirmed 55 regular package files, seven ELF executables, two static libraries, and 27 fixtures, and verified the exact build-authority metadata and source blobs. The build package records `runtimeExecution=false`.

The packaged M1c source diff remains exactly:

- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

No configure, compile, relink, source/test/fixture edit, artifact substitution, or regeneration occurred during this turn.

## 2. Discovery authority

Native GoogleTest discovery was performed once for each required executable.

| Target | Discovery result | Output SHA-256 |
|---|---:|---|
| producer | exactly **172** unique tests | `aa2d595a995b8fec18fe6f7683238945f99ff70fc9dd3335b68a7c142dc90a15` |
| validation | exactly **77** tests | `ecea7f49605b6df5db31dc2ef407c5dbf455efd9456d301aabfdebae4b9eea35` |
| M1a authority kernel | exact immutable **14** names | `ca359bf4a81d2816daa16cc5c5334f02bc9c7fc33b0a34858714e9bfcdf30991` |
| T1 product oracle | exact immutable **29** names | `d43cd15871859b7bd26577f0b251508ec736f93a9bd6c8c3f089a2b9cbec02df` |

The M1c suite contains exactly the six packaged names and no extra member. Its static manifest remains SHA-256 `4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`.

The preserved static manifests remain:

- M1b focused six: `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`;
- M1a 14: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- T1 29: `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

Zero-selection success was rejected throughout.

## 3. M1c focused semantic acceptance

Each M1c contract ran individually in a fresh process, selected exactly one real test, and passed. Result: **6/6**.

1. `ForwardQuarterTurnUsesTypedModuloTransport` — pass.
2. `ReverseTraversalUsesExactQuarterTurnInverse` — pass.
3. `EquivalentQuarterTurnsNormalizeSemantically` — pass.
4. `ReversedSourceEdgeEndpointsPreserveSemanticIdentity` — pass.
5. `MalformedAuthoritativeFaceOrEdgeFailsClosed` — pass.
6. `LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent` — pass.

This accepts the intended relations at the migrated consumer: checked source face/vertex domains, endpoint-order-independent source-edge identity, exact modulo-four quarter-turn transport and inverse, fail-closed malformed authoritative metadata, preserved raw signed compatibility matching, and unchanged explicit legacy fallback.

## 4. Existing transition counterexamples

All three required pre-M1c counterexamples ran individually, selected exactly one test, and remained green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

The packaged source still requires the periodic tamper to reject with `SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch`.

## 5. Complete producer preservation and known-red accounting

Producer discovery contains exactly **172** tests. The aggregate is intentionally segmented because the target includes two long-running known-red direct cases and nine already-known/deferred red tests.

Exact accounting is:

| Class | Count | Result |
|---|---:|---|
| required-green producer segment | **157** | **157/157** pass, rc=0, 21.99 s |
| direct required-green product cases | **4** | **4/4** pass |
| historical/deferred known-red producer tests | **9** | each selected exactly one and remains red |
| BunnyRandom | **1** | known-red, exact prior signature preserved |
| Vase | **1** | bounded 60 s nonreturn, safety-only |
| **Total** | **172** | exact discovery accounting |

The nine individually retained known-red tests are:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`;
- `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize`;
- `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected`;
- `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner`;
- `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected`;
- `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected`;
- `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority`;
- `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`.

These map to already-recorded deferred transition-quotient/completion failures, strict-validator timing, and the historical exact-torus `InvalidHardRailPairing` blocker. They are not new M1c regressions. The exact torus still reports `NotProductionReady:tracing ... InvalidHardRailPairing`; periodic/quotient failures continue to expose the already-known periodic-holonomy/torus producer limitations.

## 6. M1b, M1a, and T1 preservation

M1b focused migration contracts ran individually in fresh processes: **6/6**.

The complete immutable validation executable passed **77/77** in 13 ms. Required pre-M1b rail/provenance witnesses remain present and green inside that aggregate.

M1a authority-kernel contracts ran individually in fresh processes: **14/14**.

T1 independent product-oracle contracts ran individually in fresh processes: **29/29**.

M1c focused tests therefore supplement rather than replace the accepted independent authority.

## 7. Direct required-green product comparison

The four required product cases ran individually from the exact M1c producer executable, each selected exactly one existing test and passed its encoded independent-oracle contract.

| Case | M1c result | Accepted M1b comparison |
|---|---|---|
| Plane | pass, **1.44 s** | pass, 1.000 s |
| MultiFaceSeam | pass, **2.19 s** | pass, 1.559 s |
| CloseSheets | pass, **17.24 s** | pass, 12.169 s |
| Cylinder | pass, **9.70 s** | pass, 6.525 s |

The runtime difference is recorded but is not classified as a performance regression: these process timings were collected in a different execution environment and this M1c acceptance plan defines no comparable performance threshold for these direct cases. Correctness and independent-oracle disposition are unchanged.

## 8. Bunny/Vase artifact-only GitHub Actions comparison

Long-running Bunny and Vase used a temporary artifact-only workflow. Authoritative runtime run: `31341209985`.

Each job independently downloaded exact result artifact `9043971772` from build run `31334345368`, verified the GitHub artifact digest, all **54/54** package checksums, implementation/build metadata, and producer executable content hash before runtime. `+x` was restored only after content verification, and a runtime-only fixture symlink was used. No configure/build/relink/content mutation occurred.

### BunnyRandom

Job `93315178447` selected exactly one real test and returned **rc=1** after GoogleTest **63.087 s** / wrapper **63.09 s**.

The accepted known-red ordering is preserved exactly:

1. the independent oracle rejects first with `EmptyOutput`, `NonQuadOutput`, connected-component mismatch, Euler-characteristic mismatch, output-origin mismatch, and `TerminalFailureObserved:NotProductionReady:completion`;
2. only afterward the unchanged fatal success assertion reports `terminal=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

Evidence:

- runtime artifact `9045884237`, SHA-256 `7b7ea790d386ed82667d4827bf8cb39910a08d9a8d9c075c24ac7ffa61dd7633`;
- log artifact `9045884506`, SHA-256 `7a757aa6230f4dfaaf3338c623ddb2488a616facec8950881238f4ad508c6a4f`.

### Vase

Job `93315178308` selected exactly one real test, reached `[ RUN ]`, and was bounded at **60.00 s** with rc=124. This remains safety evidence only, not correctness and not proof of nontermination.

Evidence:

- runtime artifact `9045884496`, SHA-256 `9f231de99277d19e1ab8a3c7ec7c937ba86df14d675bc77f384c7eb1c3c6c04c`;
- log artifact `9045884645`, SHA-256 `f34a034b716903105cd903053910bba8c5af2f7ddba7ebf0f29c281bcd80ee74`.

The temporary workflow and trigger were removed before turn closeout. Workflow-job success means orchestration success only; the dispositions above come from the retained GoogleTest logs.

## 9. Postflight immutability

Postflight reverified:

- result ZIP SHA-256 `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85`;
- log ZIP SHA-256 `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb`;
- `SHA256SUMS` digest `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d`;
- every **54/54** package checksum;
- all four selected executable content hashes;
- 55 regular package files unchanged.

The only runtime filesystem addition was a non-regular `bin/test-data -> ../test-data` locator; permission-only executable restoration changed no content.

## 10. Architecture and regression disposition

M1c is **immutable accepted** as the authoritative `CrossFieldEdgeTransition` consumer migration in `resolve_branch_transition`.

- `RP-01`: checked source-face/source-vertex authority at the M1c transition seam **accepted**.
- `RP-05`: canonical source-edge semantic identity versus legacy raw lookup representation **accepted**.
- `RP-07`: exact modulo-four `QuarterTurn` transport and algebraic reverse inverse **accepted**.
- `RP-02 / TA-05`: preserved by exact discovery, M1b 6/6 + validation 77/77, M1a 14/14, T1 29/29, and direct independent-oracle evidence.
- No new stable regression event or recurrence is created. Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains active and separate. M1c does not repair or reinterpret the representative direct-torus failure.

## 11. Following turn

Review policy is `never`; therefore the next turn is a bounded **Code + Build** slice under:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Plan.md`.

M1d will migrate only the authoritative interior phase-front route identity validation in `build_authoritative_phase_front_mesh` to checked `InteriorTransitionId`, checked `SourceVertexId`, and canonical `SourceEdgeTopologyKey` consumption while preserving the existing public `sourceRouteEdges/sourceRouteTopology` representation. It will not yet migrate route transport to `TransitionStep`/`CanonicalRoute` because this consumer does not own per-step transport semantics.
