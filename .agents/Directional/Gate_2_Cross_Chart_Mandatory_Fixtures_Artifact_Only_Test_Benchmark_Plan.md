# Gate 2 Cross-Chart Transport and Mandatory Production Fixtures — Artifact-Only Test + Benchmark Plan

## Turn boundary

Use only `directional-g2-cross-chart-mandatory-fixtures-local-build-artifact.zip`.

Do not configure, compile, relink, regenerate, or edit source, tests, fixtures, manifests, build logic, or validators.

## Artifact authority

- SHA-256: `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`
- Internal checksums: **45/45**
- Source commit: `21f081b330418a0f34709f61d857f54a03d2fd48`
- Payload cleanup commit: `98fe525bb46f348cddcad91b0525353796b9e061`
- Five executables, two project libraries, 27 fixture/input files

## Mandatory direct order

Run every case in a fresh process and record its result before aggregate suites:

1. plane — Gate 1 regression
2. multi-face seam — earliest active Gate 2 fixture
3. close sheets — Gate 2 isolation fixture
4. cylinder — Gate 3 observation only while G2 is red
5. `bunny_1k_random` — mandatory closed production fixture
6. vase — mandatory open-boundary production fixture

All six must be executed even when an earlier case fails, but later cases cannot be used to declare an earlier gate passed.

## Acceptance contract

Each mandatory case requires:

- requested and executed backend `SurfaceCells`;
- fallback policy `Fail`;
- no fallback attempt;
- source-grid recovery disabled and unused;
- non-empty pure-quad output;
- output origin `CompletedSurfaceCells`;
- complete source provenance;
- strict source-authoritative validation;
- deterministic structural output.

Timeout, fallback, recovery, input return, partial output, legacy output, fixture-specific bypass, or validator relaxation is failure.

## Fixture-integrity checks

Before execution verify:

- bunny SHA-256 and exact topology: 502 vertices, 1,000 triangles, closed, one component, no non-manifold or degenerate elements;
- vase SHA-256 and exact topology: 1,274 vertices, 2,404 triangles, one boundary loop with 142 boundary edges, one component, no non-manifold or degenerate elements;
- both request generated smooth cross fields;
- manifests contain direct and legacy entries but direct acceptance counts only `SurfaceCells`.

## Required observations

For every direct case report:

- terminal stage/reason;
- requested/executed backend;
- trace count and accepted phase-front cell count;
- chart and transition provenance counts when available;
- arrangement/simplified/direct/output cell counts;
- output vertices, quads, and non-quads;
- validation failure count and first invalid record;
- fallback, recovery, and output origin;
- structural hashes and output hash;
- wall time and exit code.

For the seam specifically determine whether exact chart transport produces nonzero authoritative cross-chart cells or direct success. Unchanged zero-cell completion failure is not material progress.

For close sheets verify no cross-sheet capture or positional merge.

For bunny and vase verify the real production meshes reach the ordinary field-extraction and `SurfaceCells` pipeline; no fixture-specific path is permitted.

## Default suites

After direct evidence run:

- producer suite excluding the six direct cases already counted;
- completion suite;
- validation suite;
- compiled API suite.

Report direct acceptance separately from aggregate totals.

The scheduler-sensitive validator wall-clock ratio remains benchmark/closeout evidence and cannot outweigh functional results.

## Determinism benchmarks

Run three independent bounded processes for plane, seam, close sheets, and cylinder.

Run at least two independent bounded processes for bunny and vase; use three when each run remains within the established test-turn resource budget. A timeout is a recorded failure, never correctness evidence.

## Exit products

- authoritative raw logs and command inventory;
- machine-readable runtime summary;
- Test + Benchmark report;
- next Code + Build plan if G2 remains red;
- updated TODO, milestone, handoff, design/testing authority, and PR metadata;
- final top-level PR #8 comment as the last repository write.
