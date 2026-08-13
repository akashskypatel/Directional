# M1 Single-Authority Cutover — Active Code + Build Plan

## Status

R-A remains **open** after immutable artifact-only retry 3. This file contains only the next executable Code + Build scope; superseded R-A implementation history is retained in `CHANGELOG.md` and the current T+B report.

Entering runtime authority: M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

Rejected retry-3 candidate:
- implementation: `38d8d7d3e97f3b496e63979cb1348ed2cda304bc`
- exact compile source: `555109796188b318c788ef5777f622705ee0aa94`
- compile package: result `9167759672`, log `9167759825`
- runtime run/job: `31667380356 / 94344731465`
- result: **92 unique selected / 86 passed / 6 failed / 0 orchestration failures**

## Turn boundary

This is a **Code + Build** plan. Source, tests, diagnostics, audit code, build configuration, and durable documentation may change only as required by the tasks below. Configuration/compile/link/static analysis are allowed. Generated Directional tests, benchmarks, GTest discovery/listing, `ctest`, CLI, fuzzer, help/version commands, and custom inputs are prohibited during this turn.

Do not answer a runtime failure by weakening validation, removing an invariant, fabricating authority, bypassing a producer, or making a counterfactual vacuous. Compile success is not semantic acceptance.

## R-A-TB3-CB-01 — same-cardinality boundary-cache counterfactual

### Runtime evidence

`DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches` passed its strong canonical-publication checks but failed only this expectation: `surfaceCellAggregateIdentityBoundaryCacheRebuildCount == 0`, actual `2`.

The counterfactual mutator iterates existing `patch.boundaryNodeIdentities` and changes entries, but does not size the vector. Authoritative component materialization intentionally leaves this derived cache unpopulated. Production aggregate rebuild therefore sees two component patches whose cache extent differs from `boundaryVertices`, counts both, assigns the final extent, and rebuilds every identity from canonical lineage.

### Required correction

1. Make the test truly exercise **same-cardinality stale content**: before injecting stale tokens, explicitly size/populate each completed patch's boundary cache to `boundaryVertices.size()` using stale valid identities.
2. Retain assertions that every published boundary identity is valid, equals its matching lineage canonical identity, and contains no stale token.
3. Require rebuild count `0` only for this same-cardinality counterfactual.
4. Keep the existing missing-cardinality positive requiring exact rebuild count equal to completed-patch count.
5. Do not change `rebuild_aggregate_output_identity_caches` unless independent source analysis identifies a separate production defect.

### Compile gate

The amended authority-contract test must compile in the packaged producer-test target.

## R-A-TB3-CB-02 — feature-bearing completion before aggregate/final oracle

### Runtime evidence

Four failures share the same earliest seam:

- `ComponentFeatureRailTamperRejectsAtAggregationSeam` stops at `completion`, before its mutator can exercise aggregate authority.
- `FinalMergedOracleRejectsMissingRemappedFeatureAuthority` never reaches the final-oracle callback.
- `FinalMergedOracleRejectsChangedRemappedFeatureRailContent` never reaches the final-oracle callback.
- `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority` never observes non-empty feature authority at the final oracle.

The RA-CB-F5 transport/conservation contracts themselves are runtime-green. The remaining issue is earlier feature-bearing **component completion**, not global-to-local option remap.

### Required analysis before editing

1. Trace the exact component failure path from hard-feature option -> feature map -> authoritative rail -> completion options -> `complete_surface_cell_complex` -> fail-closed result.
2. Preserve the component's exact completion failure reason when the outer aggregate rejects. If current outer diagnostics discard it, add the minimum typed diagnostic propagation needed for a future immutable T+B run to identify the actual completion invariant without inspecting mutable state.
3. Determine from `DESIGN.md` and production source whether the current internal diagonal hard-edge fixture is within the supported R-A contract. Hard features are mandatory authority for Certified output; do not classify the entire feature path as optional.

### Required correction

Choose only the branch supported by the analysis:

**A. Supported input exposes a production defect:** repair completion so a valid internal hard feature survives naturally through completion and reaches aggregate/final validation. Preserve strict ownership, source support, canonical identity, rail authority, and no-substitution behavior.

**B. Exact fixture is outside the current supported input contract:** document the precise unsupported condition, replace the aggregate/final-oracle witness only with a demonstrably production-feasible **non-empty internal hard feature**, and add/retain a separate fail-closed contract for the unsupported case. Boundary-only or empty feature authority is not an acceptable substitute.

In either case the resulting compiled contracts must preserve these intended runtime outcomes:
- component feature-rail tamper reaches aggregation and rejects as changed component validation authority;
- missing remapped feature authority reaches the final oracle and rejects for missing feature rail authority;
- changed feature-rail content reaches the final oracle and rejects for changed/missing feature authority as specified by the validator;
- the positive reaches the final oracle with non-empty remapped feature authority and is accepted.

Do not synthesize feature rails solely inside test callbacks, disable feature checks, or relax completion/validator invariants to make these tests green.

## R-A-TB3-CB-03 — guaranteed semantic provenance tamper

### Runtime evidence

`FinalMergedOracleRejectsPostComponentProvenanceTamper` changed the first output provenance barycentric coordinate to `(1,0,0)`, yet the aggregate/final oracle accepted the mesh. The validator is source-authoritative: `(1,0,0)` is a valid certificate when the output point is exactly the corresponding source vertex, so the mutation is not guaranteed to change semantics.

### Required correction

1. Replace the counterfactual with a guaranteed semantic mutation while keeping otherwise valid authority intact. Preferred forms are:
   - preserve the source face but set a finite barycentric certificate that is provably different from the baseline and reconstructs a different position; or
   - mutate `SurfacePoint.position` while preserving the original valid barycentric certificate so the validator must report `SourcePositionMismatch`.
2. Add a precondition proving the mutation changes the semantic provenance certificate for the selected vertex; never assume the first vertex is not already a source corner.
3. Require final-oracle rejection and the intended typed validation issue, with zero semantic aggregate publication.
4. Do not weaken provenance tolerances or validator coverage.

## R-A-TB3-CB-04 — static closure and fresh immutable compile package

After CB-01 through CB-03 are complete:

1. update `R_A_Closure_Inventory.py` only if new/renamed semantic contracts require probe coverage;
2. regenerate `R_A_Closure_Inventory_Report.md` from the exact source and require zero unexpected raw-projection, face-count, or pipeline stitch-identity leaves and classifier self-test PASS;
3. compile/link the approved R-A targets through the durable reusable compile workflow;
4. package exact source, binaries, build logs, five clean source-status snapshots, command-boundary metadata, and a self-excluding recursive SHA-256 manifest;
5. record exact source SHA, run/job, artifact IDs and outer digests in `TODO.md` and the handoff;
6. execute **no generated runtime** in this Code + Build turn.

## Closure after this plan

The following turn is immutable artifact-only **R-A retry 4**. It must re-run the complete semantic gate, including the F2 per-contract reason evidence, with non-vacuous independent discovery and immutable pre/postflight. R-A closes only on an organic all-pass. Otherwise preserve evidence and return to another bounded Code + Build plan.

R-B through R-G remain blocked behind R-A. The full M1 artifact-only acceptance package remains dormant until R-A through R-G are complete.
