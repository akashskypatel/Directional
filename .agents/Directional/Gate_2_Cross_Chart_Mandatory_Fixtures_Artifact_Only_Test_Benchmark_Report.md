# Gate 2 Cross-Chart Transport and Mandatory Production Fixtures — Artifact-Only Test + Benchmark Report

**Turn:** Test + Benchmark  
**Local date:** 2026-08-06  
**Evidence UTC:** 2026-08-07  
**Source commit:** `21f081b330418a0f34709f61d857f54a03d2fd48`

## Artifact authority

- input archive: `directional-g2-cross-chart-mandatory-fixtures-local-build-artifact.zip`;
- SHA-256: `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`;
- internal checksums: **45/45**;
- five executables, two project static libraries, 27 fixture/input files;
- no configure, compile, relink, regeneration, source/test/fixture/manifest/validator edit, or discovery regeneration occurred.

The artifact stores `test-data` beside `bin`, while compiled tests resolve `bin/test-data`. The test workspace therefore created only the runtime symlink `bin/test-data -> ../test-data`. No packaged byte changed.

Raw evidence archive:

- `directional-g2-mandatory-fixtures-artifact-only-test-evidence.zip`;
- SHA-256 `8762750ffc13c339e44ce0a2ffac8639f456d16cacc480b7da44b2fedc0ed251`;
- evidence checksums: **84/84**.

## Fixture integrity

The mandatory topology guard passed.

| Fixture | SHA-256 | Vertices | Triangles | Boundary | Components | Invalid topology |
|---|---|---:|---:|---:|---:|---:|
| randomized bunny | `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05` | 502 | 1,000 | 0 edges | 1 | 0 |
| vase | `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868` | 1,274 | 2,404 | 1 loop / 142 edges | 1 | 0 |

Both direct cases use generated `smooth` fields through ordinary field extraction. Their direct and legacy manifest entries remain separate; only `SurfaceCells` counts toward direct acceptance.

## Mandatory direct result

| Fixture | Result | Traces | Arrangement / simplified | Completed / output quads | Earliest invalid producer | Output hash |
|---|---:|---:|---:|---:|---|---|
| Plane | **fail — Gate 1 regression** | 106 | 9 / 9 | 12 / 0 | `completion/output-validation:AggregateCompletionValidationFailure`; 15 validation failures | none |
| Multi-face seam | **pass** | 256 | 65 / 65 | 64 / 64 | none | `a8972efd7c4900a4` |
| Close sheets | fail | 158 | 0 / 0 | 0 / 0 | `completion` | none |
| Cylinder | fail | 732 | 0 / 0 | 0 / 0 | `completion` | none |
| Randomized bunny | fail | 80,862 | 0 / 0 | 0 / 0 | `completion` | none |
| Vase | fail | 116,922 | 0 / 0 | 0 / 0 | `completion` | none |

All six requested and executed `SurfaceCells`, used fallback policy `Fail`, did not attempt fallback, did not use source-grid recovery, and were run in fresh processes. Failed cases reported output origin `None`; the seam reported `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero non-quads, zero degenerates, and zero validation failures.

The seam is real material progress: exact chart/transition transport now reaches deterministic direct one-cell-to-one-quad materialization. It is not sufficient to advance because the already-passed plane contract regressed.

Close sheets produced no arrangement or output cells, so no cross-sheet capture was observed. However, zero-cell failure does not prove successful close-sheet isolation.

Bunny and vase reached ordinary smooth-field extraction and the real tracing/embedding path. Their large trace counts prove they were not skipped or replaced, but neither reached arrangement.

## Determinism

- Plane, seam, close sheets, and cylinder were executed in three independent benchmark processes.
- Bunny and vase were executed in two independent benchmark processes.
- For every fixture, terminal state, stage counts, first invalid producer, stage structural hashes, fallback/recovery state, and output hash were identical across processes.
- Seam output hash was `a8972efd7c4900a4` in all three processes.

Representative seam lineage:

```text
tracing      4b0c672ea08103d2 / 256
arrangement  08e490c95b70fc70 / 65
completion   5b926355cfde2db9 / 64
validation   1510f433da23a020 / 64
```

Representative plane regression lineage:

```text
tracing      9a3bc6f1202818b1 / 106
arrangement  6e42bc969e9d7fba / 9
completion   c538eeec73e84d2d / 12
```

## Default suites

| Inventory | Passed | Total | Result |
|---|---:|---:|---|
| mandatory direct | 1 | 6 | five failures |
| remaining producer | 78 | 79 | timing-ratio failure only |
| completion | 154 | 164 | ten historical failures |
| validation | 60 | 60 | pass |
| compiled API | 8 | 8 | pass |
| non-overlapping total | **301** | **317** | 16 failures |

The remaining producer failure is `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`, a scheduler-sensitive wall-clock ratio. It remains benchmark/closeout evidence, not the constructive blocker.

The ten completion failures are unchanged historical/downstream tests and do not displace the earliest direct regression.

## Gate decision

- G0 remains passed.
- G1 is **red again** because plane direct acceptance regressed.
- The G2 seam sub-contract is proven by deterministic direct success.
- G2 cannot be declared passed while G1 is red and close sheets fails.
- G3 and later gates remain blocked.

The next turn must restore the general prescribed-field plane phase-front path while preserving seam success. It must not special-case either fixture or revert exact chart transition transport.
