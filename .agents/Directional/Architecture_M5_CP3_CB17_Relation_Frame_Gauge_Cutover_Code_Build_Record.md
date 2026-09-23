# M5-CP3-CB17 Relation-Frame Gauge Cutover Code + Build Record

**Turn:** `M5-CP3-CB17`
**Boundary:** product + directly coupled focused contracts; runtime-free Code + Build
**Frozen authority:** `Architecture_M5_Frozen_Definitions.md` §16.3 and `Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Definition_Record.md`
**Disposition:** **COMPLETE / COMPILE GREEN / RUNTIME UNPROVED**

## 1. Implemented cutover

CB17 implements the frozen same-region relation-frame map directly:

```text
Q = G_R^-1 o A o G_F

Forward relation endpoint:
  branch = G_F^-1 o sourceBranch
  coord  = rawCutCoord

Reverse relation endpoint:
  branch = Q o (G_R^-1 o sourceBranch)
  coord  = rotate(Q, rawCutCoord)
```

`Q` is now the relation rotation authority throughout relation-endpoint construction and checked-product validation. The endpoint state field is renamed from the materially false `generatorRotation` to `relationRotation`; translation remains anchored from semantic Forward only by the existing pair-action builder; semantic storage resolution remains exactly `T` or `T.inverse()` according to A3 role, with no best-of-two retry or re-anchoring.

The cutover changes exactly four authorized paths:

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

No fixture, raw torus field, A3 route/occurrence authority, `PeriodicRelationId`, selector430 bytes, benchmark source, recovery behavior or M6 state changed.

## 2. Focused source/test contracts

CB17 preserves the existing relation-endpoint exactness test and changes it to the frozen Forward/Reverse coordinate normalization. It replaces the old occurrence-branch-only focus with `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges`.

The synthetic discriminator is intentionally nonzero-gauge and independent of the produced torus witness:

```text
A   = 1
G_F = 2
G_R = 1
Q   = 2
```

Therefore `Q != A`. The contract also proves that deleting either the `G_F` or `G_R^-1` term changes the result, and verifies Forward keeps raw cut coordinates while Reverse rotates by `Q`. This closes the compile-time/focused coverage gap recorded by `M5-CP3-TB1-R14-REV-OBS-01`; runtime credit remains owned by R15 Review.

Final CB17 static test inventory is cardinality-preserving relative to R14: one focused identity was replaced rather than appended. The fresh R15 vector is therefore exactly **448 processes**: mechanism/semantic **11**, focused atlas **1**, produced **6**, selector430 **430**, benchmark **0**.

## 3. Source preservation and application

The coherent implementation was preserved before repository mutation as a verified full-index patch against source `bc6d10e52b25bb99b653be8a2512ba9ed3963a0d`:

- patch SHA-256: `13cbee5aef8de0eb2d16520c7d2186a469779bdd10d4236f20a8578a5c17cb82`;
- diff-body SHA-256: `f34b3b43ab5a7cb4dc453c6f2a25ec889d8ce3af4f639fdfdf2b93d00ff0ef06`;
- Drive apply run/job: `35844224046 / 107126399443`;
- applied semantic source: `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- apply result/log artifacts: `10742846251 / 10742583073`;
- apply workflow recorded `runtimeExecution=false`.

The staging file required owner-side retirement because the workflow service identity could not trash it; the user-authorized Drive connector then deleted that exact file successfully.

## 4. Compile/package evidence

Final compile/package source is `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`.

- compile run/job: `35845003340 / 107128980299`;
- candidate/log artifacts: `10742798135 / 10743207155`;
- candidate/log ZIP SHA-256: `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866 / cc58680de72ec58dc3cc74d3a1971d881f6232be923f0eb8672dad711e69354c`;
- root package manifest: **28/28**, SHA-256 `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`;
- packaged source archive SHA-256: `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- preflight/build exit: `0 / 0`;
- required targets: all eight mandatory targets compile and link;
- exact arithmetic evidence: GMP enabled and generated link command contains both GMPXX and GMP;
- source receipts: clean;
- `runtimeExecution=false`.

No Directional executable, test, benchmark, help/version mode, custom mesh command or generated runtime was executed in CB17. Candidate remains unpromoted until artifact-only runtime and mandatory Review.

## 5. Orchestration note

The first temporary compile caller failed at workflow startup before any job because its caller permission ceiling used `contents: read`; current observer policy requires `contents: write` even with `commit_run_file: false`. The caller was corrected once, then retriggered once. The failed startup run executed no workload and does not alter candidate evidence.

A temporary recent-runs recovery caller created while the observer comment was absent failed at startup for the same permission-ceiling cause and executed no workload. It is orchestration-only provenance, not product evidence.

## 6. Exact successor

CB17 is runtime-free and grants no semantic recovery, debt discharge, observation closure, selector publication or candidate promotion. Stable accounting therefore remains **51 events / 14 categories / 37 recurrences** and produced-witness debt remains **3**.

The only authorized successor is **`M5-CP3-TB1-R15-EXEC`** under `Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Plan.md`, followed by mandatory **`M5-CP3-TB1-R15-REV`**.
