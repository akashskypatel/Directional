# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure, but later fixtures cannot pass an earlier gate.

Every direct case requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure-quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, or special-casing either fixture is prohibited.

## Current runtime authority

The latest exact artifact produced:

- plane: failure, 106 traces, 9 arrangement cells, 12 completion candidates, 15 validation failures, no output;
- seam: success, 256 traces, 65 arrangement cells, 64 pure output quads, hash `a8972efd7c4900a4`;
- close sheets/cylinder/bunny/vase: deterministic zero-arrangement failures;
- explicit source-vertex/topology guards: 4/4;
- non-overlapping total: 305/321.

Plane remains the earliest active regression and is now under mandatory producer-architecture review.

## Contract tests versus production fixtures

Narrow synthetic/reconstructed fixtures are valid for isolating one invariant, but they are not acceptance authority for a production route.

The source-vertex fan tests reconstruct a 5x4 rectangular plane with different vertex/face indexing and inject a constant target size directly into `build_surface_cell_network`. Their pass proves the isolated fan algorithm but does **not** prove the exact committed `plane.obj` route after production cross-field finalization, target-size computation, source component/sheet classification, feature/barrier state, and tracing-option construction.

Future Gate 1 Code + Build work must therefore retain the narrow fan tests **and** add producer-level coverage that loads the exact committed `plane.obj` and `plane.rawfield`, derives the same production inputs as `RemeshPipeline`, and asserts the authoritative phase-front outcome before downstream generic stages can obscure it.

A test that recreates expected 64-quad behavior by injecting convenient target size, labels, metadata, or fixture-specific state is insufficient.

## Source-vertex transition contracts

Mandatory producer coverage includes:

- ordinary authoritative shared-edge transport;
- unique ordered multi-edge source-vertex fan transport;
- full ordered source-edge provenance;
- invariance under face-row reordering;
- typed fail-closed rejection for duplicate, malformed, disconnected, non-manifold, ambiguous, nonreciprocal, or branch-mismatched transition data;
- one accepted authoritative cell mapping to exactly one output quad.

A positional face jump, arbitrary fan subset, shortest-path selection, fixture-specific route, or typed diagnostic without constructive advancement does not satisfy the contract.

## Default suites

Report direct acceptance separately. Explicitly executed contract/direct tests must be excluded from the remaining producer aggregate so totals are non-overlapping. Then run completion, validation, and compiled API suites. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence, not functional correctness.

## Turn boundaries

Code + Build may edit active-gate implementation and valid contract/production regression tests and compile approved targets, but executes no project binary. Test + Benchmark uses one exact artifact, performs no rebuild or source/test/fixture/validator edit, and preserves raw commands/logs/results. Review turns do not edit production source/tests and must produce one evidence-backed next implementation plan.

The no-progress stop rule is active. The next turn is `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Plan.md`; a third local predicate-repair turn is prohibited.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, post-hoc cell merging, or timeout-as-correctness.
