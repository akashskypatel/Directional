# Gate 4 Transition-Quotient Materialization and Retained Authority — Code + Build Report

Status: **compile-valid candidate; awaiting artifact-only runtime validation**
Turn type: **Code + Build only**
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Compile record

Implementation **`7f486632b154a303789df6c4dd44f602c8c71281`** (`feat(surface-cells): materialize explicit front quotient`) and payload cleanup/build authority **`718b978dcd0fab66da67810e00661468fc11038f`** were pushed from exact entering branch head `33a2d09f457e48471dcd3df81735a43d32d97d23`.

Exact compile artifact:

- ID **`9024549134`**;
- name `g4-transition-quotient-code-build`;
- workflow run/job **`31267020112 / 93126709005`**;
- workflow event commit `fbf95650919865832ca93c60caaee9d001c95ffd`;
- outer ZIP SHA-256 `4d58454694668aecd30c394168dcceee9f01d5cb2999f111eefd1a720d2d80dd`;
- internal `SHA256SUMS` SHA-256 `d882776c1f92543ff9d2ca8b6acd5d4662419e2f2f4316afc505579db6e29ef5`;
- recursive checksums **48/48**;
- package **49 files / 27 fixtures / five executables / two project static libraries**;
- packaged source archive SHA-256 `a1f0f3b9cb19e01742138a3ccc9b58f91e6e885e5bcaaf4c61856cce01bb54cb`;
- packaged implementation patch SHA-256 `7de1ad7c6599d858709cbaea8f21fc2f29674f5821c4d93dcbdcdae5a8c904e0`;
- dedicated log artifact **`9024549261`**, outer ZIP SHA-256 `7e17330cb10e2c0fff9e55a7511998f4ec1d6666c3dccbb981eb7b105776ebc1`;
- Release/static/Ninja approved build **111/111**;
- GoogleTest discovery `PRE_TEST`;
- toolchain CMake 3.31.6, GCC 13.3.0, Ninja 1.13.2;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, polyscope `59da72df6517cab8379865899bdffdbc96171301`;
- artifact metadata `runtimeExecution=false`, review policy `never`.

The downloaded outer digests match GitHub artifact authority, both ZIP archives pass integrity checks, all 48 recursive entries pass, the eleven source blobs match both the packaged tree and implementation authority, and the dedicated configure/build/toolchain/submodule logs match the packaged copies. The packaged source closure contains only the durable `agent-source-snapshot.yml` workflow and no temporary payload file.

No generated Directional binary, test, benchmark, `ctest`, discovery command, CLI/GUI command, help/list/version command, or custom-input command was executed during this Code + Build turn.

## Implemented contract

The candidate performs the review-approved producer/materializer migration:

- classifies every open phase-front side as ordinary interior, genuine source boundary, hard rail, embedded relief cut, or periodic cut and records its owning cell side, exact source route, relation ownership, and reciprocal pairing authority;
- keeps embedded relief beneath its parent source-topology region, audits traversal blocking against `reliefBarriersEmbedded`, and preserves terminal ownership when embedded authority cannot be covered;
- replaces `(component,sheet,lattice)` / position-tolerance vertex merging with a union-find quotient over explicit cell-corner occurrences induced only by reciprocal ordinary sides, exact hard-rail sides, or explicitly owned full `R^r p+t` periodic transforms;
- requires complete topology-region, source-support, internal-seam, and periodic-relation consumption and rejects contradictory or incomplete authority;
- retains scalar `SurfacePoint` while extending output lineage with the complete sorted topology-region, local-isolation-sheet, source-chart, source-support, and rail/periodic equivalence provenance;
- derives unique edges, connected components, boundary loops, Euler characteristic, edge manifoldness, and vertex-fan manifoldness from emitted quad incidence instead of direct-path constants;
- retains the trace/phase-front network before materialization failure when `retainIntermediateGeometry=true`;
- adds a component/row-order-invariant semantic output digest over geometry, connectivity, and lineage while retaining the raw structural hash as same-artifact serialization evidence.

Focused compile-time regressions cover relief ownership, explicit periodic ownership and cylinder topology, reciprocal hard-rail stitching, multi-isolation quotient materialization, retained failure authority, and semantic-digest permutation invariance and mutation sensitivity. They were compiled only; they were not executed in this turn.

## Source authority

Decoded implementation patch SHA-256: `bf297294431183f9eda53d80b8ce174c33471fd96f2a9ccb446beba407915172`.

Final implementation blobs:

| File | Git blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `aa4d4d6f88233179943110f444827802fbaa376d` |
| `include/directional/geometry/PureQuadCompletion.h` | `33544710da7855249ebad98451ec527273c63c72` |
| `include/directional/geometry/SurfaceCellTracing.h` | `9db8d397bc69bd19773be2e6a63265c5d7e85048` |
| `include/directional/pipeline/RemeshPipeline.h` | `7af540b2fc97e1ebcb504c0623b913b72466ddf4` |
| `src/bench/BenchmarkQuality.cpp` | `c26650ec81e764f24d30f3b1ac791c3a05c4fbf7` |
| `src/bench/BenchmarkQuality.h` | `39beaa8b0e3ee17a4696c12de5af0a4be0b85045` |
| `src/bench/DirectionalBenchmark.cpp` | `29ab26405c1a361e23a7ab5422b3b25820435f39` |
| `src/geometry/SurfaceCellTracing.cpp` | `1c1677cefe1fb6ee85f3edcd838175271ab6313c` |
| `src/pipeline/RemeshPipeline.cpp` | `682580d3655fa3777099fd9aff494fc74b605c0e` |
| `tests/MilestoneGP27Tests.cpp` | `82b53ddd06b68b4b12a622b513ac38470b4e1513` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `8d60fe2a3da619a5ea5dc7c36e17c9af3d53f543` |

## Runtime status and next authority

This turn makes no runtime or G4-acceptance claim. The exact torus remains unclassified under this candidate until the immutable compile artifact is exercised in the mandatory following artifact-only Test + Benchmark turn.

The following turn must first verify exact artifact/source/checksum authority, then execute the new transition-quotient, relief, retention, topology, and semantic-digest cases; retained topology-region/polygonal/curved/sheet/periodic/G0-G3/validation/API authority; deterministic direct plane/seam/close-sheets/cylinder observations; and exact torus in at least three independent processes. Direct strict-valid torus acceptance requires one component, no boundary loops, Euler zero, complete lineage, all four topology regions/eight internal isolation seams/four periodic relations consumed, and no fallback/recovery. No torus output count is predicted or golden-filed.

Prescribed sphere, G5/G6, historical completion/simplification failures, validator-threshold changes, fallback/recovery, and unrelated optimization remain deferred.

## Repository hygiene

The four verified raw patch payloads were removed by cleanup/build commit `718b978dcd0fab66da67810e00661468fc11038f`. After immutable artifact/source/checksum/log authority was verified, the bounded workflow was removed in `160771335e037f89f4aa5ca07c5da61af668741c`, then its trigger in `09b333123e75ea04c3b375c08c29c6495eff1188`. End-of-turn inspection confirms the bounded workflow, trigger, and all four payload parts are absent; `.github/workflows` retains only `agent-source-snapshot.yml`.
