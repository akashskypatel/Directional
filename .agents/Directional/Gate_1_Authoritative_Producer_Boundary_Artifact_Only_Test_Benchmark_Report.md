# Gate 1 Authoritative Producer Boundary — Artifact-Only Test + Benchmark Report

## Result

**Gate 1 is closed.** The exact immutable artifact built from source commit `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3` now produces direct deterministic valid pure-quad output for the exact committed production plane while retaining the proven multi-face seam success.

This turn was artifact-only. No configure, compile, relink, source/test/fixture/manifest/validator/build-logic edit, or replacement build was performed.

## Exact artifact authority

- artifact ID: `8984760467`;
- artifact name: `g1-authoritative-producer-boundary-build`;
- archive: `directional-g1-authoritative-producer-boundary-build-artifact.zip`;
- outer SHA-256: `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031` — exact;
- recursive checksums: **44/44 passed**;
- source commit: `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- payload cleanup: `bcf934d34e9a15f5d0929628ffd26f6833643214`;
- packaged closure: five executables, two project static libraries, 27 fixture/input files;
- changed-file blob authority: all six hashes matched packaged metadata;
- bunny SHA-256: `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`;
- vase SHA-256: `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`.

Runtime-only symlinks were used solely to expose packaged fixture paths expected by the compiled tests. No packaged byte was modified.

## Explicit producer contracts

All six required prerequisite checks passed:

1. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
2. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`;
3. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`;
4. `SurfaceCellsPhase10.UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded`;
5. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`;
6. `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`.

The exact committed plane therefore exercises the real production preprocessing route and reaches the authoritative producer boundary successfully.

## Mandatory direct acceptance

| Fixture | Result | Producer disposition | Traces | Arrangement | Completed quads | Output origin |
|---|---:|---|---:|---:|---:|---|
| Plane | **pass** | `Produced` | 352 | 65 | 64 | `CompletedSurfaceCells` |
| Multi-face seam | **pass** | `Produced` | 256 | 65 | 64 | `CompletedSurfaceCells` |
| Close sheets | fail | `NotApplicable` | 158 | 0 | 0 | `None` |
| Cylinder | fail | `NotApplicable` | 732 | 0 | 0 | `None` |
| Bunny | fail | `NotApplicable` | 80,862 | 0 | 0 | `None` |
| Vase | **timeout/fail** | not fully observed | — | — | — | — |

### Plane — Gate 1 closure evidence

The production plane now has:

- `surfaceCellAuthoritativeProducerDisposition = Produced`;
- requested/executed backend `SurfaceCells`;
- fallback policy `Fail`, no fallback attempt;
- source-grid recovery disabled and unused;
- terminal failure `None`;
- `CompletedSurfaceCells` output;
- 81 provenance vertices;
- 64 completed quads;
- zero strict validation failures;
- output review hash/path suffix `730caeae49ec872c`.

The old failing 106 traces / 9 arrangement / 12 completion signature is gone.

Three independent benchmark processes were structurally identical:

- disposition `Produced` in 3/3;
- 352 traces in 3/3;
- 65 arrangement cells in 3/3;
- 64 completed quads in 3/3;
- output hash suffix `730caeae49ec872c` in 3/3.

### Multi-face seam — mandatory retained regression

The seam remains:

- `Produced`;
- direct `CompletedSurfaceCells`;
- 81 provenance/output vertices;
- 64 pure quads;
- zero validation failures;
- no fallback/recovery;
- output hash suffix `a8972efd7c4900a4`.

Three independent benchmark processes reproduced the same disposition, counts, and output hash.

### Close sheets — next active gate

Close sheets remains outside the current bounded producer domain:

- disposition `NotApplicable`;
- 158 generic traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

This is now the earliest failing direct fixture and makes **G2 close-sheet isolation** the active design gate.

### Cylinder

Cylinder remains:

- disposition `NotApplicable`;
- 732 traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

G3 remains blocked by G2.

### Bunny and vase observations

Bunny completed one direct benchmark process as a deterministic failure:

- wall time 53.493351 s;
- disposition `NotApplicable`;
- 80,862 traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

The direct GoogleTest process for bunny exceeded the bounded execution window before completion, so that timeout is a failure only and is not correctness evidence.

Vase exceeded the 180 s bounded process timeout. No correctness inference is made from the timeout. Vase remains a mandatory G6 observation, but it cannot block the newly earlier G2 gate.

## Default suites

After the explicit contracts and mandatory direct cases:

- remaining `SurfaceCellsPhase10.*`: **23/24 passed**;
  - only `StrictValidatorOverheadStaysBelowFivePercent` failed its scheduler-sensitive 5% timing ratio (`0.000189018` vs `0.00013954545` allowed);
- completion/simplification executable: **154/164 passed**;
  - the same ten downstream FlowRep/completion/simplification failures remain;
- validation executable: **60/60 passed**;
- compiled API executable: **8/8 passed**.

The timing-ratio failure is performance/measurement evidence, not an active correctness blocker. The ten completion/simplification failures remain downstream of the current G2 constructive gate and are not authorized as the next principal work.

## Gate decision

G1 satisfies the highest acceptance tier:

- exact production plane is `Produced`;
- direct deterministic 64-quad `CompletedSurfaceCells` output;
- zero strict validation failures;
- no fallback/recovery;
- complete source provenance;
- seam retains direct deterministic success.

Therefore:

```text
G0 truthful authority [passed]
→ G1 uniform phase-front plane [passed]
→ G2 cross-chart/close-sheet isolation [ACTIVE]
→ G3 periodic closure/holonomy [blocked]
→ G4 topology/singularities [blocked]
→ G5 adaptivity/features [blocked]
→ G6 bunny/vase production success [blocked]
→ G7 hardening [blocked]
```

## Proposed next Code + Build plan — authoritative because review policy is `never`

Before changing code, declare:

```text
Active design gate: G2 cross-chart/close-sheet isolation
Earliest failing fixture: close_sheets__surface_cells
Missing design contract: authoritative uniform phase/front applicability and construction across multiple disconnected but spatially close source sheets without positional cross-sheet coupling
Smallest general implementation change: extend the existing authoritative phase/front producer from the proven planar/seam domain to independent same-topology sheet components using source component/local-sheet authority and exact per-component transition/fan routing; do not alter cylinder/periodic logic
Observable material-progress condition: close_sheets disposition becomes Produced and yields direct deterministic valid pure quads with zero cross-sheet provenance/merge violations while plane and seam remain unchanged regressions
Explicitly deferred work: cylinder holonomy, singularities, topology-distinct completion, adaptive transitions/features, bunny/vase performance, scheduler timing, completion/simplification historical failures
```

Implementation constraints:

1. Preserve `NotApplicable / Produced / Rejected` semantics exactly.
2. Do not make `NotApplicable` into `Produced` by fixture identity, count, bounding-box separation, or positional clustering.
3. Partition producer state strictly by source component/local-sheet authority before phase/front construction.
4. A front on one sheet must never inspect, snap to, merge with, or inherit phase/ownership from another disconnected sheet solely because world-space positions are close.
5. Reuse the already proven ordinary-edge and ordered source-vertex-fan transport contract independently inside each authoritative sheet component.
6. Materialize accepted authoritative cells one cell → one quad; no generic substitution after `Rejected`.
7. Add/strengthen unit tests only as needed to prove generalized disconnected-close-sheet independence and permutation invariance; do not weaken existing direct acceptance tests.
8. Code + Build turn only: compile approved targets, execute no project binaries/tests/benchmarks.
9. Plane and seam are mandatory compile-time regressions for the next artifact test turn.
10. Keep cylinder explicitly `NotApplicable` until G3 periodic holonomy work; do not broaden G2 into periodic topology.

## Failure classification

- close sheets: **production implementation / missing authoritative producer coverage**;
- cylinder: **expected later-gate implementation gap**;
- bunny: **expected later-gate implementation gap; direct runtime failure observed**;
- vase: **bounded runtime timeout; later-gate observation only**;
- validator 5% test: **scheduler-sensitive performance/timing failure**;
- ten completion/simplification failures: **downstream existing implementation/test surface; deferred by gate ordering**.
