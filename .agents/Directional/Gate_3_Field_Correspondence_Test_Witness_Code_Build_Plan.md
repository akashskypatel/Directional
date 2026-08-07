# Gate 3 Field-Correspondence Test Witness — Code + Build Plan

## Turn boundary

This is **Code + Build only**. The production implementation has already satisfied the direct G3 runtime closure contract in artifact `9010838200`. The sole active G3 blocker is an incorrect unit-test witness requirement.

Do not execute any generated Directional binary, test, benchmark, ctest discovery, CLI, GUI, help/list command, or custom input during this turn. Use `PRE_TEST` or equivalent compile-only discovery behavior.

## Required design declaration before editing

```text
Active design gate: G3 periodic closure / holonomy — production runtime contract satisfied; formal closure pending test correction
Earliest failing contract: SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence
Missing test contract: field-authoritative adjacent-ring correspondence must be observed through source-attached V-family path geometry independent of target subdivision; a test may not require one un-subdivided phase-front edge to span two exact source-ring vertices
Smallest general change: replace the exactInterRingEdges witness with a subdivision-invariant check over nonzero V-family boundary-path segments reconstructed from face+barycentric source provenance, asserting alignment with the local authoritative V cross-field family while retaining a nonempty observation requirement
Observable closure condition: corrected field-correspondence test passes without production changes, the endpoint/ambiguity/periodic/G1/G2 contracts remain compiled unchanged, and the next exact artifact keeps cylinder direct deterministic strict-valid periodic CompletedSurfaceCells output
Explicitly deferred work: G4 topology/singularities, G5 adaptivity/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, and unrelated optimization
```

## Exact evidence entering the turn

Artifact `9010838200`, source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`:

- focused/retained raw result **16/17**;
- both endpoint-canonicalization tests pass;
- typed ambiguous correspondence test passes;
- all other nominal G3 periodic contracts pass;
- all seven retained G1/G2 contracts pass;
- cylinder direct `Produced` / `CompletedSurfaceCells`, holonomy `r=0, t=(32,0)`, route 32, cut 4, 1,728 traces, 288 pure quads, 320 provenance/output vertices, validation failures 0, field P95 `8.537736463e-07°`, output hash `32135be51d7a0a26`, deterministic 3/3, no fallback/recovery;
- output has exactly two true 32-edge annulus boundary loops at z ±1 and no artificial-cut exterior seam.

This is material progress, so the two-consecutive-Code+Build no-progress review rule is reset/not triggered.

## Why the current test expectation is invalid

`PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` currently increments `exactInterRingEdges` only when a phase-front V edge has two distinct endpoints that are both exact source vertices.

For the test's exact fixture and parameters:

- five source rings at z `-1, -0.5, 0, 0.5, 1`;
- source inter-ring spacing `0.5`;
- constant target size `0.25`;
- intrinsic axial height `2.0`;
- production formula `gridV = round(height / target) = 8`;
- phase-front V step `0.25`.

Each source inter-ring edge is therefore represented by **two** authoritative phase-front V edges. No one V edge spans both source-ring vertices, so `exactInterRingEdges > 0` is structurally impossible even when the same-column axial correspondence is correct.

The fixture remains valid; only the witness expectation is invalid.

## Required test-only correction

Keep the test's purpose and cylinder ambiguity scenario. Replace the incidental un-subdivided-edge witness with source-attached path evidence:

1. require `network.phaseFront.disposition == Produced` as now;
2. iterate V-family phase-front cell sides / `boundaryPaths` (or equivalent first-class source-attached V segments), not only front edges whose two corners are exact source vertices;
3. for every nonzero source-attached V segment:
   - require a valid source face;
   - require finite normalized barycentrics inside the source simplex;
   - reconstruct start/end 3D source points from that face and barycentrics;
   - ignore only truly zero-length segments;
   - project/reconstruct the local authoritative V field axis in that same source face;
   - assert `abs(dot(segmentDirection, authoritativeV))` is approximately 1 using a numerically justified tolerance;
4. require at least one qualifying V segment so an empty observation set cannot pass;
5. preserve the synthetic `AmbiguousPeriodicRingCorrespondence` test unchanged;
6. preserve endpoint canonicalization, annulus, cut/holonomy, source-strip, artificial-cut, malformed-holonomy and G1/G2 tests unchanged;
7. do not assert historical `gridV`, output count, source vertex IDs, DCEL IDs, discovery order, or exact segment count.

A diagonal/sheared correspondence must still fail this test: its source-attached inter-ring segment direction is the previously measured ~`37.9670987281°` away from the axial field family.

This correction should strengthen the behavioral contract because it checks actual source-attached V path geometry across subdivision rather than relying on one incidental exact-edge cardinality.

## Production source policy

**Expected production-source change: none.**

Do not change `SurfaceCellTracing.cpp`, validators, thresholds, ring-candidate scoring, endpoint canonicalization, periodic quotient, fallback/recovery, or materialization merely to satisfy the test.

If code inspection unexpectedly demonstrates that source-attached V boundary segments are not field-authoritative despite the direct strict-valid result, stop and revise the plan before production editing. Do not silently broaden scope.

## Compile/package gate

Compile the established seven approved targets with Release static / Ninja / `PRE_TEST` or equivalent:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Execute no generated project binary.

Package immutable source/test authority, patch SHA, final blobs, five executables, two project libraries, 27 fixture/input files, logs, compile commands, `runtimeExecution=false`, recursive checksums and an always-uploaded separate log artifact.

Remove any bounded workflow, trigger and payload after verifying artifact/log/source authority; final branch workflow state must again contain only durable `agent-source-snapshot.yml`.

## Following artifact-only acceptance

Run the exact artifact without rebuilding.

First rerun the 17 focused/retained contracts. Required result: **17/17** with the corrected field-correspondence test observing nonempty source-attached V segments and rejecting diagonal field misalignment semantically.

Then revalidate plane, seam, close sheets and exact cylinder. G3 formally closes when cylinder retains:

- `Produced`;
- direct `CompletedSurfaceCells` pure-quad output;
- valid `r=0` periodic holonomy and supported integral translation;
- nonempty canonical route/cut and exact artificial-cut quotient;
- two true annulus boundary loops only;
- complete provenance;
- zero validation failures;
- field/normal/warpage gates within existing limits;
- deterministic structural/output hashes;
- no fallback/recovery;
- passed G0-G2 regressions.

On that result, mark G3 passed and make G4 the next active design gate.

## Closeout note

This plan is authoritative because optional Review is skipped. The preceding artifact-only turn made material progress and therefore does not trigger the mandatory design-review stop rule.
