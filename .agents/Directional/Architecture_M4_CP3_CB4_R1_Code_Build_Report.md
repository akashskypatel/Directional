# M4-CP3-CB4-R1 Code + Build Report — exact A2b source support and production A3 binder

**Status:** COMPLETE / IMPLEMENTATION + COMPILE GREEN / RUNTIME-FREE
**Turn:** `M4-CP3-CB4-R1`
**Execution mode:** canonical Code + Build
**Normative definition:** `Architecture_M4_DEFN_Frozen_Definitions.md` §§17 and 17.12
**Accepted runtime predecessor:** package119 / selector394 **394/394**
**Post-build candidate:** package120 / selector403, unpromoted
**Exact semantic source:** `3f909a5a2cfd305d423faf7a260bc465c7b06892`
**Exact next:** `M4-CP3-TB2-EXEC`

## 1. Implemented

CB4-R1 implements the reviewed §17.12 authority repair and stops before the deferred A3→A4 cutover.

1. Added one upstream-neutral exact source-path representation in `include/directional/authority/ExactSourcePath.h` for canonical source vertices, edge points, face-barycentric points and ordered support pieces.
2. Every accepted A2b `GlobalTopologyArc` now publishes a non-empty canonical `sourcePath` in `firstNode -> secondNode` orientation.
3. `Mandatory` and `Cut` arcs publish their actual exact source-edge subintervals; split arcs therefore no longer duplicate an overbroad parent-edge locus.
4. `Trace` arcs publish the exact ordered per-segment support chain derived from accepted A2a authority.
5. A2b validation reconstructs expected support independently, rejects non-canonical/disconnected/off-carrier/tampered paths, reconciles path support with existing source-face/edge authority, and binds the path into the semantic digest.
6. Production A3 uses `make_global_conformity_baseline_input()` to copy one A2b arc path into exactly one `ConformitySpanInput`, preserving `ConformitySpanId::from_network_arc(arc.id)` and introducing no caller-supplied family/sign authority.
7. `RemeshPipeline` constructs and independently validates exactly one `GlobalConformityBaselinePlan` immediately after `global-topology-plan`, publishes it as `global-conformity-baseline`, and retains it as an immutable component product.
8. A4/tracing continues to consume the same pre-R1 options and products. The new A3 product is published before tracing but is not read by A4 in this turn.

The change remains additive at the A2b→A3 boundary. It does not change selected cuts, A2b arc IDs/order/kinds, rotations, regions/disc certificates, `HardRailPairKey`, floating `support_key`, shared-boundary materialization, target-derived A4 subdivision logic, or the exact-torus A4 gate.

## 2. Regression-source coverage compiled in this turn

Selector403 appends nine identities after the accepted selector394 prefix:

```text
395 GlobalTopologyPlan.ExactSourcePathsAreCanonicalForEveryPublishedArcKind
396 GlobalTopologyPlan.SplitMandatoryAndCutArcsPublishExactStrictSubintervalSupport
397 GlobalTopologyPlan.MultiSegmentTracePublishesOrderedCanonicalFaceSupport
398 GlobalTopologyPlan.ReverseIncidenceReversesExactSourcePathWithoutMutatingCanonicalArc
399 GlobalTopologyPlan.IndependentValidationRejectsExactSourcePathTamperMatrix
400 ExactSourcePath.FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
401 GlobalConformityBaseline.ProductionBinderCopiesExactA2bSupportOneToOneWithoutFamilyOrSign
402 GlobalConformityBaseline.IndependentValidatorRejectsNonCanonicalRedundantExactPointEncoding
403 RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b
```

These cover all three A2b arc kinds, strict split-edge support, ordered multi-segment trace support, reverse incidence, independent tamper rejection, canonical face-point ordering, 1:1 A3 binding, non-canonical exact-point rejection and production-stage single-writer/reachability. They were compiled only; none executed during CB4-R1.

## 3. Semantic files changed

The exact semantic patch changes only:

- `.agents/Directional/Architecture_M4_CP3_CB4_R1_Required_Green_Selector_403.txt`
- `cmake/DirectionalTests.cmake`
- `include/directional/authority/ExactSourcePath.h`
- `include/directional/geometry/GlobalConformityPlan.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `src/geometry/EmbeddedGraphTopology.cpp`
- `src/geometry/GlobalConformityBaselineSupport.cpp`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`
- `tests/GlobalConformityBaselineTests.cpp`

Turn-closeout documentation is committed later and is not part of package120 semantic source.

## 4. Selector authority

Re-derived from the package120 source archive:

```text
selector382 prefix SHA-256 = 1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f
selector394 rows            = 394
selector394 SHA-256         = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector403 rows            = 403
selector403 SHA-256         = e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
```

Rows 1-394 of selector403 are byte-identical to selector394. The nine appended rows are all owned by the default producer test target. Expected selector403 owner totals are therefore **30 authority-kernel / 257 producer / 75 completion / 41 validation**; accepted selector394 remains **30 / 248 / 75 / 41**.

## 5. Work preservation and source application

Before remote source application, the complete semantic diff was emitted and verified as:

```text
directional-m4-cp3-cb4-r1.patch
SHA-256 = 480214646c9cc7182440ad84ff49057e0955869ed47e96c3cc94c18de75b617f
diff-body SHA-256 = 1fc2b29c7a33c6f00954284a2a93be635f7debb0364e4e5aca8150abcd8554e1
base = c7ed09b42d4a7cd3a5a8b4ea5eacce6683eaa9c8
```

Drive apply run `34641983017` applied those exact bytes and produced semantic source `3f909a5a2cfd305d423faf7a260bc465c7b06892`. Result artifact `10280556700` recorded the same patch hash, `runtimeExecution=false`, and successful push. The Drive reusable lacked owner trash authority, so the exact staged Drive file was permanently deleted afterward through the owner-authorized control plane. The temporary apply caller/marker were removed in workflow-first order.

## 6. Compile evidence

### 6.1 First compile — semantic owner green, package scope incomplete

Run `34642178031`, job `103404391882`, compiled semantic source `3f909a5a2cfd305d423faf7a260bc465c7b06892` successfully with GMP/GMPXX and `runtimeExecution=false`.

Result artifact `10280154084` (`m4-cp3-cb4-r1-package-result-34642178031`, SHA-256 `e8b8a6f2775cfa35781f52184eb9c398b55fd2d7a4d7ae76e75e700e3b3cfe30`) verified the changed producer owner and supporting targets, but package inspection exposed an orchestration/package-scope defect: it omitted the authority-kernel, completion and validation selector-owner executables. No runtime was attempted. The artifact is compile evidence only and is superseded as TB authority by the corrected full package below.

### 6.2 Corrected full package compile — package120

The exact same semantic source was recompiled without source mutation, with the changed producer owner as the explicit preflight target followed by the complete approved package surface.

| Evidence | Authority |
|---|---|
| workflow run | `34643014511` |
| compile job | `103407112799` |
| semantic source | `3f909a5a2cfd305d423faf7a260bc465c7b06892` |
| package artifact | `10280703200` — `m4-cp3-cb4-r1-package-r2-result-34643014511` |
| package ZIP SHA-256 | `3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4` |
| compile-log artifact | `10280878009` |
| compile-log SHA-256 | `637255ac10f42363aed0a2af66b220ab436a0f4612b76ded61101f0cfbedb020` |

Preflight target `directional_surface_cell_producer_tests` linked with exit `0`. The complete package then linked:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Package verification established:

- provider artifact digest equals the recorded package ZIP SHA-256;
- recursive self-excluding `SHA256SUMS` verifies **28/28** entries;
- `metadata/source-commit.txt` is exactly `3f909a5a2cfd305d423faf7a260bc465c7b06892`;
- `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true` and `semanticContracts=compiled-not-executed`;
- GMP evidence includes both `gmpxx` and `gmp` on the authoritative generated link command;
- all source-status files are empty;
- all four selector-owner test executables are present with archived executable mode `0755`;
- selector382/394/403 row counts and hashes match §4 above.

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, fuzzer, `ctest`, or custom Directional input executed in CB4-R1.

## 7. Plan conformance and stop-condition review

No frozen stop condition fired:

- exact construction-time support existed for all required arc kinds;
- canonical face-point order derived from existing source topology;
- A2b arc IDs/order/topology, selected cuts, rotations and region certificates were not intentionally changed by the authority publication;
- A3 binding required no family/sign or floating reconstruction;
- A4 did not need semantic modification to compile;
- selector394 was not weakened, reordered or rewritten.

The first compile's incomplete packaging was an orchestration-scope defect discovered before runtime, not a semantic failure. It was corrected by rebuilding the same exact semantic source with the full frozen selector-owner target set.

## 8. Deferred runtime evidence

Compile success does not prove the new §17.12 contracts. Package120 remains **candidate / unpromoted** until artifact-only runtime evidence establishes:

- rows 395-403 pass and are deterministic;
- accepted selector394 remains 394/394 on the new semantic source;
- cumulative selector403 is 403/403;
- package/source/execution-view immutability holds before and after runtime;
- the nine new tests are non-vacuous under their exact packaged source definitions.

No performance benchmark is required because CB4-R1 changes authority publication/binding semantics and defines no performance acceptance metric.

## 9. Successor

The frozen successor plan is `Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md`.

Exact next state: **`M4-CP3-TB2-EXEC`**. It is artifact-only and must execute immutable package120 artifact `10280703200` without configure, compile, relink, source/test/fixture repair, permission repair or selector mutation. After execution it stops at **`M4-CP3-TB2-REV`** for independent diagnostics/adjudication. Only a later accepted TB2 review may authorize the final A3→A4 cutover in `M4-CP3-CB5`.
