# Surface-Cell Testing Strategy

## Purpose

The default suite measures progress toward direct production-ready `SurfaceCells` paving. Historical diagnostics, repair bookkeeping, cache details, timing ratios, and aggregate pass counts cannot outweigh a failed direct design gate.

## Mandatory direct matrix

Run and report these cases in order:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder;
5. `bunny_1k_random`;
6. vase.

Every case requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure-quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

Run all six in each mandatory Test + Benchmark turn. A later case cannot be used to declare an earlier gate passed.

## Fixture integrity

Analytic fixtures isolate specific contracts. They are necessary but not sufficient.

The bunny and vase are mandatory production fixtures:

- bunny: SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`, 502 vertices, 1,000 triangles, closed, one component;
- vase: SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`, 1,274 vertices, 2,404 triangles, one open boundary loop and 142 boundary edges.

Tests assert these properties before remeshing. Replacing a fixture with a simplified mesh, shrinking it to match implemented capability, or special-casing its identity is prohibited.

Both request generated smooth cross fields through production field extraction rather than synthetic per-face edge directions.

## Gate coverage

### G1 regression

Plane protects first-class phase/front state, source-normal orientation, directed ownership, and one authoritative cell → one output quad.

### G2 active coverage

Seam and close sheets protect:

- exact source-chart identity;
- exact transition-edge provenance;
- reciprocal cross-field quarter-turn matching;
- transported phase/lattice/family/sign state;
- intrinsic multi-face source routes;
- no positional capture or unrelated-sheet merge;
- preservation of Gate 1 direct materialization.

### Later mandatory observations

Cylinder observes periodic closure while G3 is blocked. Bunny and vase observe real curved closed/open production behavior while success gates remain ordered. Their failures must identify real missing contracts rather than be removed from the suite.

## Default suites

- producer suite: source authority, field transport, phase/front construction, mandatory direct acceptance;
- completion suite: supported topology-distinct completion and transactional simplification;
- validation suite: source-constrained optimization and strict validation;
- compiled API suite: public compiled API.

Direct results are always reported separately from aggregate totals.

Scheduler-sensitive wall-clock ratios belong to benchmark/closeout coverage, not default functional correctness.

## Test validity rules

A test is valid when failure means a current or already-passed production contract is broken. Fixtures must create the geometry and preconditions they claim to test.

Demote, reconstruct, or remove tests that only enforce superseded milestones, exact diagnostics/counters/cache layouts, fallback as success, scheduler timing, or invalid synthetic scenarios. Never weaken assertions to fit current behavior.

## Turn boundaries

### Code + Build

May edit active-gate implementation, tests, fixtures, manifests, and build logic. Compile only approved targets. Execute no generated project binary, test, benchmark, discovery, CLI, GUI, help, or list command.

### Test + Benchmark

Use an exact packaged artifact. Perform no configure, compile, relink, regeneration, or source/test/fixture/validator edit. Preserve raw logs, commands, exit codes, and machine-readable results.

## Material-progress classification

Progress requires an active direct fixture pass, a first-class missing invariant becoming live and consumed, or a general ambiguity being removed. Different wording, a new hash, a higher aggregate count, faster failure, or fixture-specific behavior is insufficient.

## Preserved prohibitions

- no validator weakening;
- no fixture/ID special cases;
- no fallback/recovery substitution;
- no positional merging across unrelated sheets;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no synthetic counters or Euler correction;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
