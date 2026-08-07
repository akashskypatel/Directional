# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure, but later fixtures cannot pass an earlier gate.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Current runtime authority

- plane: failure, 106 traces, 9 arrangement cells, 12 completion candidates, 15 validation failures, no output;
- seam: success, 256 traces, 65 arrangement cells, 64 pure output quads, hash `a8972efd7c4900a4`;
- close sheets/cylinder/bunny/vase: deterministic direct failures before output;
- narrow source-vertex/topology contracts: 4/4;
- non-overlapping total: 305/321.

Plane remains the earliest active regression.

## Contract tests versus production authority

Narrow synthetic/reconstructed fixtures remain useful for isolating one invariant, but they are not acceptance authority for the real pipeline.

The passing source-vertex tests reconstruct a geometrically equivalent plane, use different indexing, inject a constant target size, and omit substantial production preprocessing state. They must remain as contract tests, but Gate 1 additionally requires producer-level regression coverage using the exact committed `plane.obj` and `plane.rawfield`.

That production-level test must use the same general input construction as the real pipeline, including field finalization, adaptive target size, source component/sheet labels, feature/relief state, and tracing options. It must assert the authoritative producer disposition before downstream generic stages.

It may not inject fixture-specific target size, labels, transition IDs, expected cell count, or other convenient state merely to recreate 64 quads.

## Producer-authority contracts

The next implementation must distinguish:

```text
NotApplicable
Produced
Rejected
```

Mandatory tests:

- applicable valid plane/seam can reach `Produced`;
- applicable invalid metadata reaches `Rejected`, not `NotApplicable`;
- `Rejected` cannot generate generic seeds/traces/proposals or completion substitution;
- typed rejection remains first-invalid authority;
- non-embedded relief guidance does not veto transport;
- embedded relief barriers block according to the existing relief contract;
- ordinary shared-edge and ordered source-vertex fan transport remain covered;
- reversed face ordering preserves structural results;
- malformed/duplicate/nonreciprocal transition data fails closed;
- source component/sheet identity prevents unrelated capture;
- one accepted authoritative cell maps to exactly one quad.

A typed rejection without direct plane success is material architecture evidence, not Gate 1 acceptance.

## Default suites

Report direct acceptance separately. Explicitly executed contract/direct tests must be excluded from the remaining producer aggregate so totals are non-overlapping. Then run completion, validation, and compiled API suites. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence only.

## Turn boundaries

Code + Build may edit active-gate implementation and valid producer-level regression tests and compile approved targets, but executes no generated project binary. GitHub workflow compilation is permitted under the workflow policy. Test + Benchmark uses one exact immutable artifact and performs no rebuild or source/test/fixture/validator edit. Review turns do not edit production source/tests.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, post-hoc cell merging, or timeout-as-correctness.
