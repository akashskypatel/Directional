# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure, but later fixtures cannot pass an earlier gate.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Latest executed runtime authority

The current Code + Build artifact has not yet been executed. Latest runtime remains:

- plane: failure, 106 traces, 9 arrangement cells, 12 completion candidates, 15 validation failures, no output;
- seam: success, 256 traces, 65 arrangement cells, 64 pure output quads, hash `a8972efd7c4900a4`;
- close sheets/cylinder/bunny/vase: deterministic direct failures before output;
- narrow source-vertex/topology contracts: 4/4;
- non-overlapping total: 305/321.

Plane remains the earliest active regression.

## Current producer-authority contracts

The source now distinguishes:

```text
NotApplicable
Produced
Rejected
```

Mandatory behavior:

- applicable valid plane/seam may reach `Produced`;
- applicable invalid metadata reaches `Rejected`, not `NotApplicable`;
- `Rejected` generates no generic seeds/traces/proposals;
- `Rejected` terminates at the tracing producer boundary before FlowRep/arrangement/completion substitution;
- typed rejection remains first-invalid authority;
- non-embedded relief guidance does not veto transport;
- embedded relief barriers block according to the existing relief contract;
- ordinary shared-edge and ordered source-vertex fan transport remain covered;
- reversed face ordering preserves structural results;
- malformed/duplicate/nonreciprocal transition data fails closed;
- source component/sheet identity prevents unrelated capture;
- one accepted authoritative cell maps to exactly one quad.

Producer disposition and typed rejection identity must be present in deterministic diagnostic/structural evidence.

## Contract tests versus production authority

Narrow synthetic/reconstructed fixtures remain useful for isolating one invariant, but they are not acceptance authority for the real pipeline.

The source now also contains `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`, which loads the exact committed `plane.obj` and `plane.rawfield` and enters the real `remesh_from_raw_cross_field` production path rather than injecting a convenient target, labels, or transitions.

The test compiled in the latest Code + Build turn but has **not** yet run. Its runtime result is part of the next artifact-only gate.

## Next artifact-only acceptance

Use artifact SHA-256 `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031` under `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Plan.md`.

Run explicit producer-contract tests first, then all six direct cases.

For every direct case additionally record `surfaceCellAuthoritativeProducerDisposition`, typed phase-front failure/context, generic trace count, arrangement/completion counts, terminal stage, stage/structural hashes, output hash, fallback/recovery state, and strict validation.

Gate 1 acceptance hierarchy:

1. `Produced` plane with direct deterministic valid pure-quads and retained seam direct success closes G1.
2. Immutable `Rejected` plane terminating at tracing with zero generic traces/arrangement/completion and disappearance of the old 106/9/12 signature is material architecture proof but not G1 closure.
3. `NotApplicable`/generic substitution, overwritten rejection, seam regression, or weakened acceptance is no progress.

## Default suites

Report direct acceptance separately. Explicitly executed contract/direct tests must be excluded from the remaining producer aggregate so totals are non-overlapping. Then run completion, validation, and compiled API suites. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence only.

## Turn boundaries

Code + Build may edit active-gate implementation and valid producer-level regression tests and compile approved targets, but executes no generated project binary. GitHub workflow compilation is permitted under the workflow policy. Test + Benchmark uses one exact immutable artifact and performs no rebuild or source/test/fixture/validator edit. Review turns do not edit production source/tests.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, post-hoc cell merging, or timeout-as-correctness.
