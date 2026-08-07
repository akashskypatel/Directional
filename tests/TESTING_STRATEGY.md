# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure, but later fixtures cannot pass an earlier gate.

Every direct case requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure-quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, or special-casing either fixture is prohibited.

## Current regression authority

The Gate 2 artifact produced:

- plane: failure, 106 traces, 9 arrangement cells, 12 invalid completion quads, 15 validation failures;
- seam: success, 256 traces, 65 arrangement cells, 64 pure output quads, hash `a8972efd7c4900a4`;
- close sheets/cylinder/bunny/vase: deterministic zero-arrangement failures.

Plane is now the earliest active regression. A Code + Build change must preserve the seam pass while restoring plane direct success.

## Default suites

Report direct separately. Then run remaining producer, completion, validation, and compiled API suites. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence, not functional correctness.

## Turn boundaries

Code + Build may edit active-gate implementation/tests/fixtures and compile approved targets, but executes no project binary. Test + Benchmark uses one exact artifact, performs no rebuild or source/test/fixture/validator edit, and preserves raw commands/logs/results.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, post-hoc cell merging, or timeout-as-correctness.
